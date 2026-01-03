#include "../common.h"
#include "tact_rep.h"

TRIBE_Action_Repair::TRIBE_Action_Repair(int param_1, RGE_Action_Object* param_2, int param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Repair(TRIBE_Action_Repair * this,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d1697(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004d169d(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004d16b0(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d16b4(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d16d5(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d16a7(W)
//                               ??0TRIBE_Action_Repair@@QAE@HPAVRGE_Action_Object@@H@Z       XREF[1]:     create_action:004d0415(c)
//                               TRIBE_Action_Repair::TRIBE_Action_Repair
//                              tact_rep.cpp:41 (48)
//         004d1680     PUSH       -0x1
//         004d1682     PUSH       FUN_005600e8
//         004d1687     MOV        EAX,FS:[0x0]
//         004d168d     PUSH       EAX
//         004d168e     MOV        dword ptr FS:[0x0],ESP
//         004d1695     PUSH       this
//         004d1696     PUSH       EBX
//         004d1697     MOV        EBX,dword ptr [ESP + param_1]
//         004d169b     PUSH       ESI
//         004d169c     PUSH       EDI
//         004d169d     MOV        EDI,dword ptr [ESP + param_2]
//         004d16a1     PUSH       0x0
//         004d16a3     MOV        ESI,this
//         004d16a5     PUSH       EDI
//         004d16a6     PUSH       EBX
//         004d16a7     MOV        dword ptr [ESP + local_10],ESI
//         004d16ab     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, int p
//                              tact_rep.cpp:44 (28)
//         004d16b0     MOV        EAX,dword ptr [ESP + param_3]
//         004d16b4     MOV        dword ptr [ESP + local_4],0x0
//         004d16bc     TEST       EAX,EAX
//         004d16be     MOV        dword ptr [ESI],TRIBE_Action_Repair::`vftable'   = 004d16f0
//         004d16c4     MOV        word ptr [ESI + 0x4],0x6a
//         004d16ca     JZ         LAB_004d16d5
//                              tact_rep.cpp:45 (9)
//         004d16cc     PUSH       EDI
//         004d16cd     PUSH       EBX
//         004d16ce     MOV        this,ESI
//         004d16d0     CALL       TRIBE_Action_Repair::setup                       int setup(TRIBE_Action_Repair * this, int par
//                               LAB_004d16d5                                                 XREF[1]:     004d16ca(j)
//                              tact_rep.cpp:46 (22)
//         004d16d5     MOV        this,dword ptr [ESP + local_c]
//         004d16d9     MOV        EAX,ESI
//         004d16db     POP        EDI
//         004d16dc     POP        ESI
//         004d16dd     MOV        dword ptr FS:[0x0],this
//         004d16e4     POP        EBX
//         004d16e5     ADD        ESP,0x10
//         004d16e8     RET        0xc
//         004d16eb     ??         90h
//         004d16ec     NOP
//         004d16ed     NOP
//         004d16ee     NOP
//         004d16ef     NOP
}

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Repair(TRIBE_Action_Repair * this,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d1736(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004d174a(R)
//              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     004d174e(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004d1758(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004d1792(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004d1741(W)
//                               ??0TRIBE_Action_Repair@@QAE@PAVRGE_Action_Object@@PAVRGE_Ta  XREF[2]:     repair:004cb56d(c),
//                               TRIBE_Action_Repair::TRIBE_Action_Repair                                  create_task_action:004d09e4(c)
//                              tact_rep.cpp:54 (42)
//         004d1720     PUSH       -0x1
//         004d1722     PUSH       FUN_00560108
//         004d1727     MOV        EAX,FS:[0x0]
//         004d172d     PUSH       EAX
//         004d172e     MOV        dword ptr FS:[0x0],ESP
//         004d1735     PUSH       this
//         004d1736     MOV        EAX,dword ptr [ESP + param_1]
//         004d173a     PUSH       ESI
//         004d173b     PUSH       EDI
//         004d173c     MOV        ESI,this
//         004d173e     PUSH       0x1
//         004d1740     PUSH       EAX
//         004d1741     MOV        dword ptr [ESP + local_10],ESI
//         004d1745     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_rep.cpp:56 (4)
//         004d174a     MOV        this,dword ptr [ESP + param_2]
//                              tact_rep.cpp:58 (39)
//         004d174e     MOV        EDI,dword ptr [ESP + param_3]
//         004d1752     MOV        dword ptr [ESI + 0x30],this
//         004d1755     PUSH       EDI
//         004d1756     MOV        this,ESI
//         004d1758     MOV        dword ptr [ESP + local_4],0x0
//         004d1760     MOV        dword ptr [ESI],TRIBE_Action_Repair::`vftable'   = 004d16f0
//         004d1766     MOV        word ptr [ESI + 0x4],0x6a
//         004d176c     MOV        byte ptr [ESI + 0x40],0x0
//         004d1770     CALL       RGE_Action::set_target_obj                       void set_target_obj(RGE_Action * this, RGE_St
//                              tact_rep.cpp:59 (4)
//         004d1775     TEST       EDI,EDI
//         004d1777     JZ         LAB_004d1792
//                              tact_rep.cpp:61 (6)
//         004d1779     MOV        EDX,dword ptr [EDI + 0x38]
//         004d177c     MOV        dword ptr [ESI + 0x20],EDX
//                              tact_rep.cpp:62 (6)
//         004d177f     MOV        EAX,dword ptr [EDI + 0x3c]
//         004d1782     MOV        dword ptr [ESI + 0x24],EAX
//                              tact_rep.cpp:63 (6)
//         004d1785     MOV        this,dword ptr [EDI + 0x40]
//         004d1788     MOV        dword ptr [ESI + 0x28],this
//                              tact_rep.cpp:64 (7)
//         004d178b     MOV        this,ESI
//         004d178d     CALL       TRIBE_Action_Repair::meet_target                 void meet_target(TRIBE_Action_Repair * this)
//                               LAB_004d1792                                                 XREF[1]:     004d1777(j)
//                              tact_rep.cpp:66 (21)
//         004d1792     MOV        this,dword ptr [ESP + local_c]
//         004d1796     MOV        EAX,ESI
//         004d1798     POP        EDI
//         004d1799     MOV        dword ptr FS:[0x0],this
//         004d17a0     POP        ESI
//         004d17a1     ADD        ESP,0x10
//         004d17a4     RET        0xc
//         004d17a7     ??         90h
//         004d17a8     NOP
//         004d17a9     NOP
//         004d17aa     NOP
//         004d17ab     NOP
//         004d17ac     NOP
//         004d17ad     NOP
//         004d17ae     NOP
//         004d17af     NOP
}

TRIBE_Action_Repair::TRIBE_Action_Repair(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Action_Repair(TRIBE_Action_Repair * this,
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              RGE_Action_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d17b0(R)
//              RGE_Task *        Stack[0x8]:4   param_2                   XREF[1]:     004d17bf(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d17c7(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d17c3(R)
//              float             Stack[0x14]:4  param_5                   XREF[1]:     004d17ce(R)
//                               ??0TRIBE_Action_Repair@@QAE@PAVRGE_Action_Object@@PAVRGE_Ta  XREF[1]:     create_task_action:004d0a2f(c)
//                               TRIBE_Action_Repair::TRIBE_Action_Repair
//                              tact_rep.cpp:74 (15)
//         004d17b0     MOV        EAX,dword ptr [ESP + param_1]
//         004d17b4     PUSH       ESI
//         004d17b5     PUSH       0x1
//         004d17b7     MOV        ESI,this
//         004d17b9     PUSH       EAX
//         004d17ba     CALL       RGE_Action::RGE_Action                           undefined RGE_Action(RGE_Action * this, RGE_A
//                              tact_rep.cpp:76 (4)
//         004d17bf     MOV        this,dword ptr [ESP + param_2]
//                              tact_rep.cpp:78 (11)
//         004d17c3     MOV        EAX,dword ptr [ESP + param_4]
//         004d17c7     MOV        EDX,dword ptr [ESP + param_3]
//         004d17cb     MOV        dword ptr [ESI + 0x30],this
//                              tact_rep.cpp:79 (25)
//         004d17ce     MOV        this,dword ptr [ESP + param_5]
//         004d17d2     MOV        dword ptr [ESI + 0x24],EAX
//         004d17d5     MOV        dword ptr [ESI],TRIBE_Action_Repair::`vftable'   = 004d16f0
//         004d17db     MOV        word ptr [ESI + 0x4],0x6a
//         004d17e1     MOV        dword ptr [ESI + 0x20],EDX
//         004d17e4     MOV        dword ptr [ESI + 0x28],this
//                              tact_rep.cpp:80 (4)
//         004d17e7     MOV        byte ptr [ESI + 0x40],0x0
//                              tact_rep.cpp:81 (6)
//         004d17eb     MOV        EAX,ESI
//         004d17ed     POP        ESI
//         004d17ee     RET        0x14
//         004d17f1     ??         90h
//         004d17f2     NOP
//         004d17f3     NOP
//         004d17f4     NOP
//         004d17f5     NOP
//         004d17f6     NOP
//         004d17f7     NOP
//         004d17f8     NOP
//         004d17f9     NOP
//         004d17fa     NOP
//         004d17fb     NOP
//         004d17fc     NOP
//         004d17fd     NOP
//         004d17fe     NOP
//         004d17ff     NOP
}

int TRIBE_Action_Repair::setup(int param_1, RGE_Action_Object* param_2) {
    /* TODO: Stub */
//                              int __thiscall setup(TRIBE_Action_Repair * this, int param_1, RGE_Ac
//              int               EAX:4          <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d1807(R)
//              RGE_Action_Obj    Stack[0x8]:4   param_2                   XREF[1]:     004d1800(R)
//                               ?setup@TRIBE_Action_Repair@@UAEHHPAVRGE_Action_Object@@@Z    XREF[2]:     TRIBE_Action_Repair:004d16d0(c),
//                               TRIBE_Action_Repair::setup                                                00575210(*)
//                              tact_rep.cpp:85 (20)
//         004d1800     MOV        EAX,dword ptr [ESP + param_2]
//         004d1804     PUSH       EBX
//         004d1805     PUSH       ESI
//         004d1806     PUSH       EDI
//         004d1807     MOV        EDI,dword ptr [ESP + param_1]
//         004d180b     PUSH       EAX
//         004d180c     MOV        ESI,this
//         004d180e     PUSH       EDI
//         004d180f     CALL       RGE_Action::setup                                int setup(RGE_Action * this, int param_1, RGE
//                              tact_rep.cpp:90 (21)
//         004d1814     FLD        float ptr [save_game_version]                    = 7.23
//         004d181a     FCOMP      float ptr [DAT_00575268]                         = align(2)
//         004d1820     MOV        EBX,EAX
//         004d1822     FNSTSW     AX
//         004d1824     TEST       AH,0x1
//         004d1827     JNZ        LAB_004d1840
//                              tact_rep.cpp:91 (15)
//         004d1829     ADD        ESI,0x40
//         004d182c     PUSH       0x1
//         004d182e     PUSH       ESI
//         004d182f     PUSH       EDI
//         004d1830     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
//         004d1835     ADD        ESP,0xc
//                              tact_rep.cpp:95 (2)
//         004d1838     MOV        EAX,EBX
//                              tact_rep.cpp:96 (6)
//         004d183a     POP        EDI
//         004d183b     POP        ESI
//         004d183c     POP        EBX
//         004d183d     RET        0x8
//                               LAB_004d1840                                                 XREF[1]:     004d1827(j)
//                              tact_rep.cpp:93 (4)
//         004d1840     MOV        byte ptr [ESI + 0x40],0x0
//                              tact_rep.cpp:96 (8)
//         004d1844     POP        EDI
//         004d1845     MOV        EAX,EBX
//         004d1847     POP        ESI
//         004d1848     POP        EBX
//         004d1849     RET        0x8
//         004d184c     ??         90h
//         004d184d     NOP
//         004d184e     NOP
//         004d184f     NOP
    return 0;
}

void TRIBE_Action_Repair::save(int param_1) {
    /* TODO: Stub */
//                              void __thiscall save(TRIBE_Action_Repair * this, int param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004d1852(R)
//                               ?save@TRIBE_Action_Repair@@UAEXH@Z                           XREF[1]:     0057521c(*)
//                               TRIBE_Action_Repair::save
//                              tact_rep.cpp:100 (2)
//         004d1850     PUSH       ESI
//         004d1851     PUSH       EDI
//                              tact_rep.cpp:101 (12)
//         004d1852     MOV        EDI,dword ptr [ESP + param_1]
//         004d1856     MOV        ESI,this
//         004d1858     PUSH       EDI
//         004d1859     CALL       RGE_Action::save                                 void save(RGE_Action * this, int param_1)
//                              tact_rep.cpp:103 (15)
//         004d185e     ADD        ESI,0x40
//         004d1861     PUSH       0x1
//         004d1863     PUSH       ESI
//         004d1864     PUSH       EDI
//         004d1865     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
//         004d186a     ADD        ESP,0xc
//                              tact_rep.cpp:104 (5)
//         004d186d     POP        EDI
//         004d186e     POP        ESI
//         004d186f     RET        0x4
//         004d1872     ??         90h
//         004d1873     NOP
//         004d1874     NOP
//         004d1875     NOP
//         004d1876     NOP
//         004d1877     NOP
//         004d1878     NOP
//         004d1879     NOP
//         004d187a     NOP
//         004d187b     NOP
//         004d187c     NOP
//         004d187d     NOP
//         004d187e     NOP
//         004d187f     NOP
    return;
}

void TRIBE_Action_Repair::first_in_stack(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall first_in_stack(TRIBE_Action_Repair * this, uchar par
//              void              <VOID>         <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004d1880(R)
//                               ?first_in_stack@TRIBE_Action_Repair@@UAEXE@Z                 XREF[1]:     00575224(*)
//                               TRIBE_Action_Repair::first_in_stack
//                              tact_rep.cpp:110 (15)
//         004d1880     MOV        AL,byte ptr [ESP + param_1]
//         004d1884     TEST       AL,AL
//         004d1886     JZ         LAB_004d1899
//         004d1888     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d188b     TEST       EAX,EAX
//         004d188d     JZ         LAB_004d1899
//                              tact_rep.cpp:112 (7)
//         004d188f     MOV        EAX,dword ptr [this->_padding_]
//         004d1891     PUSH       0x4
//         004d1893     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:115 (3)
//         004d1896     RET        0x4
//                               LAB_004d1899                                                 XREF[2]:     004d1886(j), 004d188d(j)
//                              tact_rep.cpp:114 (7)
//         004d1899     MOV        EDX,dword ptr [this->_padding_]
//         004d189b     PUSH       0x3
//         004d189d     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:115 (3)
//         004d18a0     RET        0x4
//         004d18a3     ??         90h
//         004d18a4     NOP
//         004d18a5     NOP
//         004d18a6     NOP
//         004d18a7     NOP
//         004d18a8     NOP
//         004d18a9     NOP
//         004d18aa     NOP
//         004d18ab     NOP
//         004d18ac     NOP
//         004d18ad     NOP
//         004d18ae     NOP
//         004d18af     NOP
    return;
}

void TRIBE_Action_Repair::set_state(uchar param_1) {
    /* TODO: Stub */
//                              void __thiscall set_state(TRIBE_Action_Repair * this, uchar param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     004d18d1(R), 004d1913(W), 004d19b9(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004d1919(W), 004d194b(W), 004d19bf(W), 004d19f1(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     004d1983(R), 004d1a29(R), 004d1b66(R)
//                               ?set_state@TRIBE_Action_Repair@@MAEXE@Z                      XREF[1]:     00575264(*)
//                               TRIBE_Action_Repair::set_state
//                              tact_rep.cpp:121 (25)
//         004d18b0     MOV        EAX,FS:[0x0]
//         004d18b6     PUSH       -0x1
//         004d18b8     PUSH       FUN_00560136
//         004d18bd     PUSH       EAX
//         004d18be     MOV        dword ptr FS:[0x0],ESP
//         004d18c5     PUSH       ESI
//         004d18c6     MOV        ESI,this
//         004d18c8     PUSH       EDI
//                              tact_rep.cpp:129 (8)
//         004d18c9     MOV        this,dword ptr [ESI + 0x34]
//         004d18cc     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
//                              tact_rep.cpp:132 (7)
//         004d18d1     MOV        EAX,dword ptr [ESP + param_1]
//         004d18d5     MOV        byte ptr [ESI + 0xc],AL
//                              tact_rep.cpp:134 (22)
//         004d18d8     AND        EAX,0xff
//         004d18dd     DEC        EAX
//         004d18de     CMP        EAX,0xa
//         004d18e1     JA         switchD_004d18e7::caseD_5
//                               switchD_004d18e7::switchD
//         004d18e7     JMP        dword ptr [EAX*0x4 + switchD_004d18e7::switchd   = 004d1b29
//                               switchD_004d18e7::caseD_3                                    XREF[2]:     004d18e7(j), 004d1b84(*)
//                              tact_rep.cpp:137 (22)
//         004d18ee     MOV        this,dword ptr [ESI + 0x8]
//         004d18f1     PUSH       0x0
//         004d18f3     PUSH       0x0
//         004d18f5     PUSH       0x26a
//         004d18fa     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d18fd     MOV        EDX,dword ptr [this->_padding_]
//         004d18ff     PUSH       0x202
//                              tact_rep.cpp:139 (5)
//         004d1904     JMP        LAB_004d1b4f
//                               switchD_004d18e7::caseD_b                                    XREF[2]:     004d18e7(j), 004d1ba4(*)
//                              tact_rep.cpp:148 (64)
//         004d1909     PUSH       0x44
//         004d190b     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d1910     ADD        ESP,0x4
//         004d1913     MOV        dword ptr [ESP + param_1],EAX
//         004d1917     TEST       EAX,EAX
//         004d1919     MOV        dword ptr [ESP + local_4],0x0
//         004d1921     JZ         LAB_004d1947
//         004d1923     MOV        this,dword ptr [ESI + 0x30]
//         004d1926     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d1929     MOV        this,dword ptr [ESI + 0x28]
//         004d192c     PUSH       EDX
//         004d192d     MOV        EDX,dword ptr [ESI + 0x24]
//         004d1930     PUSH       0x0
//         004d1932     PUSH       this
//         004d1933     MOV        this,dword ptr [ESI + 0x20]
//         004d1936     PUSH       EDX
//         004d1937     MOV        EDX,dword ptr [ESI + 0x8]
//         004d193a     PUSH       this
//         004d193b     PUSH       EDX
//         004d193c     MOV        this,EAX
//         004d193e     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004d1943     MOV        EDI,EAX
//         004d1945     JMP        LAB_004d1949
//                               LAB_004d1947                                                 XREF[1]:     004d1921(j)
//         004d1947     XOR        EDI,EDI
//                               LAB_004d1949                                                 XREF[1]:     004d1945(j)
//                              tact_rep.cpp:149 (12)
//         004d1949     TEST       EDI,EDI
//         004d194b     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d1953     JNZ        LAB_004d1971
//                              tact_rep.cpp:151 (9)
//         004d1955     MOV        EAX,dword ptr [ESI]
//         004d1957     PUSH       0xd
//         004d1959     MOV        this,ESI
//         004d195b     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:221 (19)
//         004d195e     MOV        this,dword ptr [ESP + 0x8]
//         004d1962     MOV        dword ptr FS:[0x0],this
//         004d1969     POP        EDI
//         004d196a     POP        ESI
//         004d196b     ADD        ESP,0xc
//         004d196e     RET        0x4
//                               LAB_004d1971                                                 XREF[1]:     004d1953(j)
//                              tact_rep.cpp:154 (9)
//         004d1971     PUSH       0x1
//         004d1973     MOV        this,EDI
//         004d1975     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_rep.cpp:155 (9)
//         004d197a     MOV        this,dword ptr [ESI + 0x34]
//         004d197d     PUSH       EDI
//         004d197e     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_rep.cpp:221 (19)
//         004d1983     MOV        this,dword ptr [ESP + local_c]
//         004d1987     MOV        dword ptr FS:[0x0],this
//         004d198e     POP        EDI
//         004d198f     POP        ESI
//         004d1990     ADD        ESP,0xc
//         004d1993     RET        0x4
//                               switchD_004d18e7::caseD_4                                    XREF[2]:     004d18e7(j), 004d1b88(*)
//                              tact_rep.cpp:160 (7)
//         004d1996     MOV        EAX,dword ptr [ESI + 0x10]
//         004d1999     TEST       EAX,EAX
//         004d199b     JZ         LAB_004d19af
//                              tact_rep.cpp:162 (6)
//         004d199d     MOV        this,dword ptr [EAX + 0x38]
//         004d19a0     MOV        dword ptr [ESI + 0x20],this
//                              tact_rep.cpp:163 (6)
//         004d19a3     MOV        EDX,dword ptr [EAX + 0x3c]
//         004d19a6     MOV        dword ptr [ESI + 0x24],EDX
//                              tact_rep.cpp:164 (6)
//         004d19a9     MOV        EAX,dword ptr [EAX + 0x40]
//         004d19ac     MOV        dword ptr [ESI + 0x28],EAX
//                               LAB_004d19af                                                 XREF[1]:     004d199b(j)
//                              tact_rep.cpp:167 (64)
//         004d19af     PUSH       0x44
//         004d19b1     CALL       operator_new                                     void * operator_new(uint param_1)
//         004d19b6     ADD        ESP,0x4
//         004d19b9     MOV        dword ptr [ESP + param_1],EAX
//         004d19bd     TEST       EAX,EAX
//         004d19bf     MOV        dword ptr [ESP + local_4],0x1
//         004d19c7     JZ         LAB_004d19ed
//         004d19c9     MOV        this,dword ptr [ESI + 0x30]
//         004d19cc     MOV        EDX,dword ptr [ESI + 0x8]
//         004d19cf     MOV        this,dword ptr [ECX + this->_padding_]
//         004d19d2     PUSH       this
//         004d19d3     MOV        this,dword ptr [EDX + 0x8]
//         004d19d6     MOV        this,dword ptr [this->_padding_ + 0x114]
//         004d19dc     PUSH       this
//         004d19dd     MOV        this,dword ptr [ESI + 0x10]
//         004d19e0     PUSH       this
//         004d19e1     PUSH       EDX
//         004d19e2     MOV        this,EAX
//         004d19e4     CALL       RGE_Action_Move_To::RGE_Action_Move_To           undefined RGE_Action_Move_To(RGE_Action_Move_
//         004d19e9     MOV        EDI,EAX
//         004d19eb     JMP        LAB_004d19ef
//                               LAB_004d19ed                                                 XREF[1]:     004d19c7(j)
//         004d19ed     XOR        EDI,EDI
//                               LAB_004d19ef                                                 XREF[1]:     004d19eb(j)
//                              tact_rep.cpp:168 (12)
//         004d19ef     TEST       EDI,EDI
//         004d19f1     MOV        dword ptr [ESP + local_4],0xffffffff
//         004d19f9     JNZ        LAB_004d1a17
//                              tact_rep.cpp:170 (9)
//         004d19fb     MOV        EDX,dword ptr [ESI]
//         004d19fd     PUSH       0xd
//         004d19ff     MOV        this,ESI
//         004d1a01     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:221 (19)
//         004d1a04     MOV        this,dword ptr [ESP + 0x8]
//         004d1a08     MOV        dword ptr FS:[0x0],this
//         004d1a0f     POP        EDI
//         004d1a10     POP        ESI
//         004d1a11     ADD        ESP,0xc
//         004d1a14     RET        0x4
//                               LAB_004d1a17                                                 XREF[1]:     004d19f9(j)
//                              tact_rep.cpp:173 (9)
//         004d1a17     MOV        this,dword ptr [ESI + 0x34]
//         004d1a1a     PUSH       EDI
//         004d1a1b     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
//                              tact_rep.cpp:174 (9)
//         004d1a20     PUSH       0x1
//         004d1a22     MOV        this,EDI
//         004d1a24     CALL       RGE_Action::setSubAction                         void setSubAction(RGE_Action * this, uchar pa
//                              tact_rep.cpp:221 (19)
//         004d1a29     MOV        this,dword ptr [ESP + local_c]
//         004d1a2d     MOV        dword ptr FS:[0x0],this
//         004d1a34     POP        EDI
//         004d1a35     POP        ESI
//         004d1a36     ADD        ESP,0xc
//         004d1a39     RET        0x4
//                               switchD_004d18e7::caseD_a                                    XREF[2]:     004d18e7(j), 004d1ba0(*)
//                              tact_rep.cpp:178 (15)
//         004d1a3c     MOV        this,dword ptr [ESI + 0x8]
//         004d1a3f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d1a42     MOV        EAX,dword ptr [this->_padding_]
//         004d1a44     MOV        EDX,dword ptr [EDX + 0x18]
//         004d1a47     PUSH       EDX
//         004d1a48     CALL       dword ptr [EAX + 0x38]
//                              tact_rep.cpp:186 (53)
//         004d1a4b     MOV        this,dword ptr [ESI + 0x10]
//         004d1a4e     MOV        dword ptr [ESI + 0x2c],0x3f800000
//         004d1a55     TEST       this,this
//         004d1a57     JZ         switchD_004d18e7::caseD_5
//         004d1a5d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1a60     MOV        AX,word ptr [EAX + 0x14]
//         004d1a64     CMP        AX,0x2
//         004d1a68     JZ         LAB_004d1a80
//         004d1a6a     CMP        AX,0x14
//         004d1a6e     JZ         LAB_004d1a80
//         004d1a70     CMP        AX,0x15
//         004d1a74     JZ         LAB_004d1a80
//         004d1a76     CMP        AX,0x16
//         004d1a7a     JNZ        switchD_004d18e7::caseD_5
//                               LAB_004d1a80                                                 XREF[3]:     004d1a68(j), 004d1a6e(j),
//                                                                                                         004d1a74(j)
//                              tact_rep.cpp:189 (17)
//         004d1a80     MOV        DL,byte ptr [this->_padding_ + 0x188]
//         004d1a86     MOV        AL,byte ptr [ESI + 0x40]
//         004d1a89     CMP        DL,AL
//         004d1a8b     JNZ        switchD_004d18e7::caseD_5
//                              tact_rep.cpp:192 (27)
//         004d1a91     MOV        ESI,dword ptr [ESI + 0x8]
//         004d1a94     MOV        EAX,dword ptr [this->_padding_]
//         004d1a96     PUSH       0x1
//         004d1a98     PUSH       0x0=>DAT_fffffff8
//         004d1a9a     MOV        EDX,dword ptr [ESI + 0x40]
//         004d1a9d     PUSH       EDX=>DAT_fffffff4
//         004d1a9e     MOV        EDX,dword ptr [ESI + 0x3c]
//         004d1aa1     PUSH       EDX=>DAT_fffffff0
//         004d1aa2     MOV        EDX,dword ptr [ESI + 0x38]
//         004d1aa5     PUSH       EDX
//         004d1aa6     CALL       dword ptr [EAX + 0x154]
//                              tact_rep.cpp:221 (19)
//         004d1aac     MOV        this,dword ptr [ESP + 0x8]
//         004d1ab0     MOV        dword ptr FS:[0x0],this
//         004d1ab7     POP        EDI
//         004d1ab8     POP        ESI
//         004d1ab9     ADD        ESP,0xc
//         004d1abc     RET        0x4
//                               switchD_004d18e7::caseD_6                                    XREF[2]:     004d18e7(j), 004d1b90(*)
//                              tact_rep.cpp:198 (9)
//         004d1abf     MOV        EAX,dword ptr [ESI + 0x10]
//         004d1ac2     MOV        this,dword ptr [EAX + 0x38]
//         004d1ac5     MOV        dword ptr [ESI + 0x20],this
//                              tact_rep.cpp:199 (3)
//         004d1ac8     MOV        EDX,dword ptr [EAX + 0x3c]
//                              tact_rep.cpp:201 (24)
//         004d1acb     MOV        this,dword ptr [ESI + 0x8]
//         004d1ace     MOV        dword ptr [ESI + 0x24],EDX
//         004d1ad1     MOV        EAX,dword ptr [EAX + 0x40]
//         004d1ad4     MOV        EDX,dword ptr [this->_padding_]
//         004d1ad6     MOV        dword ptr [ESI + 0x28],EAX
//         004d1ad9     MOV        EAX,dword ptr [ESI + 0x30]
//         004d1adc     MOV        EAX,dword ptr [EAX + 0x34]
//         004d1adf     PUSH       EAX
//         004d1ae0     CALL       dword ptr [EDX + 0x38]
//                              tact_rep.cpp:221 (19)
//         004d1ae3     MOV        this,dword ptr [ESP + 0x8]
//         004d1ae7     MOV        dword ptr FS:[0x0],this
//         004d1aee     POP        EDI
//         004d1aef     POP        ESI
//         004d1af0     ADD        ESP,0xc
//         004d1af3     RET        0x4
//                               switchD_004d18e7::caseD_7                                    XREF[2]:     004d18e7(j), 004d1b94(*)
//                              tact_rep.cpp:206 (15)
//         004d1af6     MOV        EAX,dword ptr [ESI + 0x30]
//         004d1af9     MOV        this,dword ptr [ESI + 0x8]
//         004d1afc     MOV        EAX,dword ptr [EAX + 0x38]
//         004d1aff     MOV        EDX,dword ptr [this->_padding_]
//         004d1b01     PUSH       EAX
//         004d1b02     CALL       dword ptr [EDX + 0x38]
//                              tact_rep.cpp:209 (10)
//         004d1b05     MOV        this,dword ptr [ESI + 0x30]
//         004d1b08     MOV        this,dword ptr [ECX + this+0x44]
//         004d1b0b     TEST       this,this
//         004d1b0d     JZ         switchD_004d18e7::caseD_5
//                              tact_rep.cpp:210 (7)
//         004d1b0f     PUSH       0x1
//         004d1b11     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
//                              tact_rep.cpp:221 (19)
//         004d1b16     MOV        this,dword ptr [ESP + 0x8]
//         004d1b1a     MOV        dword ptr FS:[0x0],this
//         004d1b21     POP        EDI
//         004d1b22     POP        ESI
//         004d1b23     ADD        ESP,0xc
//         004d1b26     RET        0x4
//                               switchD_004d18e7::caseD_1                                    XREF[2]:     004d18e7(j), 004d1b7c(*)
//                              tact_rep.cpp:214 (9)
//         004d1b29     MOV        EDX,dword ptr [ESI]
//         004d1b2b     PUSH       0x0
//         004d1b2d     MOV        this,ESI
//         004d1b2f     CALL       dword ptr [EDX + 0x54]
//                              tact_rep.cpp:215 (7)
//         004d1b32     MOV        AL,byte ptr [ESI + 0x3c]
//         004d1b35     TEST       AL,AL
//         004d1b37     JNZ        switchD_004d18e7::caseD_2
//                              tact_rep.cpp:217 (30)
//         004d1b39     MOV        this,dword ptr [ESI + 0x8]
//         004d1b3c     PUSH       0x0
//         004d1b3e     PUSH       0x0=>DAT_fffffff8
//         004d1b40     PUSH       offset DAT_fffffff4
//         004d1b45     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1b48     MOV        EDX,dword ptr [this->_padding_]
//         004d1b4a     PUSH       offset DAT_fffffff0
//                               LAB_004d1b4f                                                 XREF[1]:     004d1904(j)
//         004d1b4f     PUSH       EAX
//         004d1b50     PUSH       EAX
//         004d1b51     CALL       dword ptr [EDX + 0x148]
//                               switchD_004d18e7::caseD_2                                    XREF[3]:     004d18e7(j), 004d1b37(j),
//                                                                                                         004d1b80(*)
//                              tact_rep.cpp:218 (15)
//         004d1b57     MOV        this,dword ptr [ESI + 0x8]
//         004d1b5a     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004d1b5d     MOV        EAX,dword ptr [this->_padding_]
//         004d1b5f     MOV        EDX,dword ptr [EDX + 0x18]
//         004d1b62     PUSH       EDX
//         004d1b63     CALL       dword ptr [EAX + 0x38]
//                               switchD_004d18e7::caseD_8                                    XREF[9]:     004d18e1(j), 004d18e7(j),
//                               switchD_004d18e7::caseD_9                                                 004d1a57(j), 004d1a7a(j),
//                               switchD_004d18e7::caseD_5                                                 004d1a8b(j), 004d1b0d(j),
//                                                                                                         004d1b8c(*), 004d1b98(*),
//                                                                                                         004d1b9c(*)
//                              tact_rep.cpp:221 (66)
//         004d1b66     MOV        this,dword ptr [ESP + local_c]
//         004d1b6a     POP        EDI
//         004d1b6b     MOV        dword ptr FS:[0x0],this
//         004d1b72     POP        ESI
//         004d1b73     ADD        ESP,0xc
//         004d1b76     RET        0x4
    return;
}

uchar TRIBE_Action_Repair::update() {
    /* TODO: Stub */
//                              uchar __thiscall update(TRIBE_Action_Repair * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//                               ?update@TRIBE_Action_Repair@@UAEEXZ                          XREF[1]:     00575230(*)
//                               TRIBE_Action_Repair::update
//                              tact_rep.cpp:229 (5)
//         004d1bb0     PUSH       EBX
//         004d1bb1     PUSH       ESI
//         004d1bb2     MOV        ESI,this
//         004d1bb4     PUSH       EDI
//                              tact_rep.cpp:249 (25)
//         004d1bb5     MOV        EAX,dword ptr [ESI + 0x18]
//         004d1bb8     CMP        EAX,-0x1
//         004d1bbb     JZ         LAB_004d1bd4
//         004d1bbd     PUSH       EAX
//         004d1bbe     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1bc1     MOV        this,dword ptr [EAX + 0xc]
//         004d1bc4     MOV        this,dword ptr [ECX + this->_padding_]
//         004d1bc7     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004d1bcc     TEST       EAX,EAX
//                              tact_rep.cpp:253 (6)
//         004d1bce     JZ         switchD_004d1c93::caseD_3
//                               LAB_004d1bd4                                                 XREF[1]:     004d1bbb(j)
//                              tact_rep.cpp:255 (27)
//         004d1bd4     MOV        EAX,dword ptr [ESI + 0x1c]
//         004d1bd7     CMP        EAX,-0x1
//         004d1bda     JZ         LAB_004d1bf7
//         004d1bdc     MOV        EDX,dword ptr [ESI + 0x8]
//         004d1bdf     PUSH       EAX
//         004d1be0     MOV        EAX,dword ptr [EDX + 0xc]
//         004d1be3     MOV        this,dword ptr [EAX + 0x3c]
//         004d1be6     CALL       RGE_Game_World::object                           RGE_Static_Object * object(RGE_Game_World * t
//         004d1beb     TEST       EAX,EAX
//         004d1bed     JNZ        LAB_004d1bf7
//                              tact_rep.cpp:256 (8)
//         004d1bef     MOV        EDX,dword ptr [ESI]
//         004d1bf1     PUSH       EAX
//         004d1bf2     MOV        this,ESI
//         004d1bf4     CALL       dword ptr [EDX + 0x58]
//                               LAB_004d1bf7                                                 XREF[2]:     004d1bda(j), 004d1bed(j)
//                              tact_rep.cpp:259 (11)
//         004d1bf7     MOV        EAX,dword ptr [ESI + 0x10]
//         004d1bfa     TEST       EAX,EAX
//         004d1bfc     JZ         LAB_004d1c23
//         004d1bfe     CMP        byte ptr [EAX + 0x48],0x2
//                              tact_rep.cpp:263 (6)
//         004d1c02     JNZ        switchD_004d1c93::caseD_3
//                              tact_rep.cpp:266 (25)
//         004d1c08     TEST       EAX,EAX
//         004d1c0a     JZ         LAB_004d1c23
//         004d1c0c     MOV        this,dword ptr [ESI + 0x8]
//         004d1c0f     MOV        EAX,dword ptr [EAX + 0xc]
//         004d1c12     MOV        this,dword ptr [ECX + this->_padding_]
//         004d1c15     MOVSX      EAX,word ptr [EAX + 0x4a]
//         004d1c19     MOV        EDX,dword ptr [this->_padding_]
//         004d1c1b     PUSH       EAX
//         004d1c1c     CALL       dword ptr [EDX + 0x1c]
//         004d1c1f     TEST       EAX,EAX
//                              tact_rep.cpp:270 (2)
//         004d1c21     JZ         switchD_004d1c93::caseD_3
//                               LAB_004d1c23                                                 XREF[2]:     004d1bfc(j), 004d1c0a(j)
//                              tact_rep.cpp:273 (22)
//         004d1c23     XOR        EAX,EAX
//         004d1c25     MOV        AL,byte ptr [ESI + 0xc]
//         004d1c28     DEC        EAX
//         004d1c29     CMP        EAX,0xc
//         004d1c2c     JA         switchD_004d1c32::caseD_1
//                               switchD_004d1c32::switchD
//         004d1c32     JMP        dword ptr [EAX*0x4 + switchD_004d1c32::switchd   = 004d1eb3
//                               switchD_004d1c32::caseD_a                                    XREF[2]:     004d1c32(j), 004d1f14(*)
//                              tact_rep.cpp:277 (30)
//         004d1c39     MOV        this,dword ptr [ESI + 0x34]
//         004d1c3c     MOV        EDX,dword ptr [this->_padding_]
//         004d1c3e     CALL       dword ptr [EDX + 0xc]
//         004d1c41     AND        EAX,0xff
//         004d1c46     DEC        EAX
//         004d1c47     CMP        EAX,0x4
//         004d1c4a     JA         switchD_004d1c32::caseD_1
//                               switchD_004d1c50::switchD
//         004d1c50     JMP        dword ptr [EAX*0x4 + switchD_004d1c50::switchd   = 004d1c6d
//                               switchD_004d1c50::caseD_3                                    XREF[2]:     004d1c50(j), 004d1f2c(*)
//                              tact_rep.cpp:285 (9)
//         004d1c57     MOV        EDI,dword ptr [ESI]
//         004d1c59     PUSH       0x0
//         004d1c5b     MOV        this,ESI
//         004d1c5d     CALL       dword ptr [EDI + 0x54]
//                              tact_rep.cpp:286 (7)
//         004d1c60     PUSH       0xb
//         004d1c62     MOV        this,ESI
//         004d1c64     CALL       dword ptr [EDI + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1c67     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1c69     POP        EDI
//         004d1c6a     POP        ESI
//         004d1c6b     POP        EBX
//         004d1c6c     RET
//                               switchD_004d1c50::caseD_1                                    XREF[5]:     004d1c50(j), 004d1f20(*),
//                               switchD_004d1c50::caseD_2                                                 004d1f24(*), 004d1f28(*),
//                               switchD_004d1c50::caseD_4                                                 004d1f30(*)
//                               switchD_004d1c50::caseD_0
//                              tact_rep.cpp:296 (9)
//         004d1c6d     MOV        EAX,dword ptr [ESI]
//         004d1c6f     PUSH       0x1
//         004d1c71     MOV        this,ESI
//         004d1c73     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1c76     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1c78     POP        EDI
//         004d1c79     POP        ESI
//         004d1c7a     POP        EBX
//         004d1c7b     RET
//                               switchD_004d1c32::caseD_3                                    XREF[2]:     004d1c32(j), 004d1ef8(*)
//                              tact_rep.cpp:303 (30)
//         004d1c7c     MOV        this,dword ptr [ESI + 0x34]
//         004d1c7f     MOV        EDX,dword ptr [this->_padding_]
//         004d1c81     CALL       dword ptr [EDX + 0xc]
//         004d1c84     AND        EAX,0xff
//         004d1c89     DEC        EAX
//         004d1c8a     CMP        EAX,0x4
//         004d1c8d     JA         switchD_004d1c32::caseD_1
//                               switchD_004d1c93::switchD
//         004d1c93     JMP        dword ptr [EAX*0x4 + switchD_004d1c93::switchd   = 004d1cb0
//                               switchD_004d1c93::caseD_4                                    XREF[6]:     004d1bce(j), 004d1c02(j),
//                               switchD_004d1c93::caseD_3                                                 004d1c21(j), 004d1c93(j),
//                                                                                                         004d1f40(*), 004d1f44(*)
//                              tact_rep.cpp:312 (9)
//         004d1c9a     MOV        EDI,dword ptr [ESI]
//         004d1c9c     PUSH       0x0
//         004d1c9e     MOV        this,ESI
//         004d1ca0     CALL       dword ptr [EDI + 0x54]
//                              tact_rep.cpp:314 (7)
//         004d1ca3     PUSH       0x1
//         004d1ca5     MOV        this,ESI
//         004d1ca7     CALL       dword ptr [EDI + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1caa     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1cac     POP        EDI
//         004d1cad     POP        ESI
//         004d1cae     POP        EBX
//         004d1caf     RET
//                               switchD_004d1c93::caseD_1                                    XREF[4]:     004d1c93(j), 004d1f34(*),
//                               switchD_004d1c93::caseD_2                                                 004d1f38(*), 004d1f3c(*)
//                               switchD_004d1c93::caseD_0
//                              tact_rep.cpp:326 (24)
//         004d1cb0     MOV        EAX,dword ptr [ESI + 0x10]
//         004d1cb3     MOV        this,dword ptr [ESI + 0x8]
//         004d1cb6     PUSH       EAX
//         004d1cb7     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//         004d1cbc     FSUB       float ptr [DAT_0057526c]
//         004d1cc2     FST        float ptr [DAT_0086bc08]                         = align(8)
//                              tact_rep.cpp:327 (13)
//         004d1cc8     FCOMP      double ptr [DAT_00575270]                        = 9Ah
//         004d1cce     FNSTSW     AX
//         004d1cd0     TEST       AH,0x41
//         004d1cd3     JZ         LAB_004d1ce4
//                              tact_rep.cpp:328 (9)
//         004d1cd5     MOV        EDX,dword ptr [ESI]
//         004d1cd7     PUSH       0x6
//         004d1cd9     MOV        this,ESI
//         004d1cdb     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1cde     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1ce0     POP        EDI
//         004d1ce1     POP        ESI
//         004d1ce2     POP        EBX
//         004d1ce3     RET
//                               LAB_004d1ce4                                                 XREF[1]:     004d1cd3(j)
//                              tact_rep.cpp:330 (9)
//         004d1ce4     MOV        EAX,dword ptr [ESI]
//         004d1ce6     PUSH       0xa
//         004d1ce8     MOV        this,ESI
//         004d1cea     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1ced     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1cef     POP        EDI
//         004d1cf0     POP        ESI
//         004d1cf1     POP        EBX
//         004d1cf2     RET
//                               switchD_004d1c32::caseD_5                                    XREF[2]:     004d1c32(j), 004d1f00(*)
//                              tact_rep.cpp:338 (7)
//         004d1cf3     MOV        EAX,dword ptr [ESI + 0x10]
//         004d1cf6     TEST       EAX,EAX
//         004d1cf8     JNZ        LAB_004d1d09
//                              tact_rep.cpp:341 (9)
//         004d1cfa     MOV        EDX,dword ptr [ESI]
//         004d1cfc     PUSH       0x1
//         004d1cfe     MOV        this,ESI
//         004d1d00     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1d03     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1d05     POP        EDI
//         004d1d06     POP        ESI
//         004d1d07     POP        EBX
//         004d1d08     RET
//                               LAB_004d1d09                                                 XREF[1]:     004d1cf8(j)
//                              tact_rep.cpp:346 (24)
//         004d1d09     MOV        this,dword ptr [ESI + 0x8]
//         004d1d0c     PUSH       0x0
//         004d1d0e     PUSH       0x0
//         004d1d10     PUSH       EAX
//         004d1d11     MOV        EDX,dword ptr [this->_padding_]
//         004d1d13     CALL       dword ptr [EDX + 0x1f0]
//         004d1d19     TEST       AL,AL
//         004d1d1b     JZ         switchD_004d1c32::caseD_1
//                              tact_rep.cpp:348 (9)
//         004d1d21     MOV        EAX,dword ptr [ESI]
//         004d1d23     PUSH       0x7
//         004d1d25     MOV        this,ESI
//         004d1d27     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1d2a     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1d2c     POP        EDI
//         004d1d2d     POP        ESI
//         004d1d2e     POP        EBX
//         004d1d2f     RET
//                               switchD_004d1c32::caseD_6                                    XREF[2]:     004d1c32(j), 004d1f04(*)
//                              tact_rep.cpp:357 (7)
//         004d1d30     MOV        EDX,dword ptr [ESI + 0x10]
//         004d1d33     TEST       EDX,EDX
//         004d1d35     JNZ        LAB_004d1d46
//                              tact_rep.cpp:360 (9)
//         004d1d37     MOV        EDX,dword ptr [ESI]
//         004d1d39     PUSH       0x1
//         004d1d3b     MOV        this,ESI
//         004d1d3d     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1d40     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1d42     POP        EDI
//         004d1d43     POP        ESI
//         004d1d44     POP        EBX
//         004d1d45     RET
//                               LAB_004d1d46                                                 XREF[1]:     004d1d35(j)
//                              tact_rep.cpp:366 (34)
//         004d1d46     FLD        float ptr [EDX + 0x38]
//         004d1d49     FCOMP      float ptr [ESI + 0x20]
//         004d1d4c     FNSTSW     AX
//         004d1d4e     TEST       AH,0x40
//         004d1d51     JZ         LAB_004d1dff
//         004d1d57     FLD        float ptr [ESI + 0x24]
//         004d1d5a     FCOMP      float ptr [EDX + 0x3c]
//         004d1d5d     FNSTSW     AX
//         004d1d5f     TEST       AH,0x40
//         004d1d62     JZ         LAB_004d1dff
//                              tact_rep.cpp:385 (44)
//         004d1d68     MOV        EAX,dword ptr [ESI + 0x8]
//         004d1d6b     MOV        this,dword ptr [ESI + 0x30]
//         004d1d6e     MOV        EDI,dword ptr [EDX]
//         004d1d70     PUSH       this
//         004d1d71     MOV        EBX,dword ptr [EAX + 0xc]
//         004d1d74     MOV        EAX,dword ptr [EAX + 0x8]
//         004d1d77     FLD        float ptr [ECX + this->_padding_]
//         004d1d7a     MOV        EBX,dword ptr [EBX + 0x3c]
//         004d1d7d     MOV        this,EDX
//         004d1d7f     FMUL       float ptr [EBX + 0x84]
//         004d1d85     FMUL       float ptr [EAX + 0xe4]
//         004d1d8b     FSTP       float ptr [ESP]
//         004d1d8e     CALL       dword ptr [EDI + 0x8c]
//                              tact_rep.cpp:386 (4)
//         004d1d94     CMP        AL,0x1
//         004d1d96     JNZ        LAB_004d1da7
//                              tact_rep.cpp:392 (9)
//         004d1d98     MOV        EDX,dword ptr [ESI]
//         004d1d9a     PUSH       0x1
//         004d1d9c     MOV        this,ESI
//         004d1d9e     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1da1     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1da3     POP        EDI
//         004d1da4     POP        ESI
//         004d1da5     POP        EBX
//         004d1da6     RET
//                               LAB_004d1da7                                                 XREF[1]:     004d1d96(j)
//                              tact_rep.cpp:394 (8)
//         004d1da7     CMP        AL,0x2
//         004d1da9     JNZ        switchD_004d1c32::caseD_1
//                              tact_rep.cpp:396 (30)
//         004d1daf     MOV        this,dword ptr [ESI + 0x8]
//         004d1db2     PUSH       0x0
//         004d1db4     PUSH       0x0
//         004d1db6     PUSH       0x26a
//         004d1dbb     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1dbe     MOV        EDX,dword ptr [this->_padding_]
//         004d1dc0     PUSH       0x1fb
//         004d1dc5     PUSH       EAX
//         004d1dc6     PUSH       EAX
//         004d1dc7     CALL       dword ptr [EDX + 0x148]
//                              tact_rep.cpp:397 (35)
//         004d1dcd     MOV        EDX,dword ptr [ESI + 0x10]
//         004d1dd0     PUSH       0x0
//         004d1dd2     PUSH       0x0
//         004d1dd4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004d1dda     MOV        EDX,dword ptr [EDX + 0x4]
//         004d1ddd     PUSH       EDX
//         004d1dde     MOV        EDX,dword ptr [ESI + 0x8]
//         004d1de1     MOV        EAX,dword ptr [this->_padding_]
//         004d1de3     MOV        EDX,dword ptr [EDX + 0xc]
//         004d1de6     MOVSX      EDX,word ptr [EDX + 0x4a]
//         004d1dea     PUSH       EDX
//         004d1deb     PUSH       0x6b
//         004d1ded     CALL       dword ptr [EAX + 0x40]
//                              tact_rep.cpp:398 (9)
//         004d1df0     MOV        EAX,dword ptr [ESI]
//         004d1df2     PUSH       0x2
//         004d1df4     MOV        this,ESI
//         004d1df6     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1df9     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1dfb     POP        EDI
//         004d1dfc     POP        ESI
//         004d1dfd     POP        EBX
//         004d1dfe     RET
//                               LAB_004d1dff                                                 XREF[2]:     004d1d51(j), 004d1d62(j)
//                              tact_rep.cpp:370 (21)
//         004d1dff     MOV        this,dword ptr [ESI + 0x8]
//         004d1e02     PUSH       EDX
//         004d1e03     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//         004d1e08     FSUB       float ptr [DAT_0057526c]
//         004d1e0e     FST        float ptr [DAT_0086bc08]                         = align(8)
//                              tact_rep.cpp:371 (13)
//         004d1e14     FCOMP      double ptr [DAT_00575270]                        = 9Ah
//         004d1e1a     FNSTSW     AX
//         004d1e1c     TEST       AH,0x41
//         004d1e1f     JNZ        LAB_004d1e30
//                              tact_rep.cpp:372 (9)
//         004d1e21     MOV        EDX,dword ptr [ESI]
//         004d1e23     PUSH       0x3
//         004d1e25     MOV        this,ESI
//         004d1e27     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1e2a     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1e2c     POP        EDI
//         004d1e2d     POP        ESI
//         004d1e2e     POP        EBX
//         004d1e2f     RET
//                               LAB_004d1e30                                                 XREF[1]:     004d1e1f(j)
//                              tact_rep.cpp:375 (9)
//         004d1e30     MOV        EAX,dword ptr [ESI + 0x10]
//         004d1e33     MOV        this,dword ptr [EAX + 0x38]
//         004d1e36     MOV        dword ptr [ESI + 0x20],this
//                              tact_rep.cpp:376 (6)
//         004d1e39     MOV        EDX,dword ptr [EAX + 0x3c]
//         004d1e3c     MOV        dword ptr [ESI + 0x24],EDX
//                              tact_rep.cpp:377 (6)
//         004d1e3f     MOV        EAX,dword ptr [EAX + 0x40]
//         004d1e42     MOV        dword ptr [ESI + 0x28],EAX
//                              tact_rep.cpp:440 (2)
//         004d1e45     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1e47     POP        EDI
//         004d1e48     POP        ESI
//         004d1e49     POP        EBX
//         004d1e4a     RET
//                               switchD_004d1c32::caseD_9                                    XREF[2]:     004d1c32(j), 004d1f10(*)
//                              tact_rep.cpp:404 (11)
//         004d1e4b     MOV        EDX,dword ptr [ESI + 0x10]
//         004d1e4e     TEST       EDX,EDX
//         004d1e50     JZ         switchD_004d1c32::caseD_1
//                              tact_rep.cpp:406 (18)
//         004d1e56     MOV        this,dword ptr [ESI + 0x8]
//         004d1e59     FLD        float ptr [ESI + 0x2c]
//         004d1e5c     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1e5f     MOV        EAX,dword ptr [EAX + 0x3c]
//         004d1e62     FSUB       float ptr [EAX + 0x84]
//                              tact_rep.cpp:407 (16)
//         004d1e68     FCOM       float ptr [DAT_00575278]
//         004d1e6e     FSTP       float ptr [ESI + 0x2c]
//         004d1e71     FNSTSW     AX
//         004d1e73     TEST       AH,0x41
//         004d1e76     JZ         switchD_004d1c32::caseD_1
//                              tact_rep.cpp:409 (18)
//         004d1e78     PUSH       EDX
//         004d1e79     CALL       RGE_Static_Object::distance_to_object            float distance_to_object(RGE_Static_Object *
//         004d1e7e     FSUB       float ptr [DAT_0057526c]
//         004d1e84     FST        float ptr [DAT_0086bc08]                         = align(8)
//                              tact_rep.cpp:410 (13)
//         004d1e8a     FCOMP      double ptr [DAT_00575270]                        = 9Ah
//         004d1e90     FNSTSW     AX
//         004d1e92     TEST       AH,0x41
//         004d1e95     JZ         LAB_004d1ea6
//                              tact_rep.cpp:411 (9)
//         004d1e97     MOV        EDX,dword ptr [ESI]
//         004d1e99     PUSH       0x6
//         004d1e9b     MOV        this,ESI
//         004d1e9d     CALL       dword ptr [EDX + 0x5c]
//                              tact_rep.cpp:440 (2)
//         004d1ea0     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1ea2     POP        EDI
//         004d1ea3     POP        ESI
//         004d1ea4     POP        EBX
//         004d1ea5     RET
//                               LAB_004d1ea6                                                 XREF[1]:     004d1e95(j)
//                              tact_rep.cpp:414 (7)
//         004d1ea6     MOV        dword ptr [ESI + 0x2c],0x3f800000
//                              tact_rep.cpp:440 (2)
//         004d1ead     XOR        AL,AL
//                              tact_rep.cpp:441 (4)
//         004d1eaf     POP        EDI
//         004d1eb0     POP        ESI
//         004d1eb1     POP        EBX
//         004d1eb2     RET
//                               switchD_004d1c32::caseD_0                                    XREF[2]:     004d1c32(j), 004d1eec(*)
//                              tact_rep.cpp:431 (2)
//         004d1eb3     MOV        AL,0x1
//                              tact_rep.cpp:441 (4)
//         004d1eb5     POP        EDI
//         004d1eb6     POP        ESI
//         004d1eb7     POP        EBX
//         004d1eb8     RET
//                               switchD_004d1c32::caseD_c                                    XREF[2]:     004d1c32(j), 004d1f1c(*)
//                              tact_rep.cpp:435 (30)
//         004d1eb9     MOV        this,dword ptr [ESI + 0x8]
//         004d1ebc     PUSH       0x0
//         004d1ebe     PUSH       0x0
//         004d1ec0     PUSH       0x26a
//         004d1ec5     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004d1ec8     MOV        EDX,dword ptr [this->_padding_]
//         004d1eca     PUSH       0x1f9
//         004d1ecf     PUSH       EAX
//         004d1ed0     PUSH       EAX
//         004d1ed1     CALL       dword ptr [EDX + 0x148]
//                              tact_rep.cpp:436 (9)
//         004d1ed7     MOV        EAX,dword ptr [ESI]
//         004d1ed9     PUSH       0x2
//         004d1edb     MOV        this,ESI
//         004d1edd     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:437 (2)
//         004d1ee0     MOV        AL,0x3
//                              tact_rep.cpp:441 (102)
//         004d1ee2     POP        EDI
//         004d1ee3     POP        ESI
//         004d1ee4     POP        EBX
//         004d1ee5     RET
//                               switchD_004d1c32::caseD_2                                    XREF[14]:    004d1c2c(j), 004d1c32(j),
//                               switchD_004d1c32::caseD_4                                                 004d1c4a(j), 004d1c8d(j),
//                               switchD_004d1c32::caseD_7                                                 004d1d1b(j), 004d1da9(j),
//                               switchD_004d1c32::caseD_8                                                 004d1e50(j), 004d1e76(j),
//                               switchD_004d1c32::caseD_b                                                 004d1ef0(*), 004d1ef4(*),
//                               switchD_004d1c50::default                                                 004d1efc(*), 004d1f08(*),
//                               switchD_004d1c93::default                                                 004d1f0c(*), 004d1f18(*)
//                               switchD_004d1c32::caseD_1
//         004d1ee6     POP        EDI
//         004d1ee7     POP        ESI
//         004d1ee8     XOR        AL,AL
//         004d1eea     POP        EBX
//         004d1eeb     RET
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d1c32::switchdataD_004d1eec                       XREF[1]:     update:004d1c32(*)
//         004d1eec     addr       switchD_004d1c32::caseD_0
//         004d1ef0     addr       switchD_004d1c32::caseD_1
//         004d1ef4     addr       switchD_004d1c32::caseD_1
//         004d1ef8     addr       switchD_004d1c32::caseD_3
//         004d1efc     addr       switchD_004d1c32::caseD_1
//         004d1f00     addr       switchD_004d1c32::caseD_5
//         004d1f04     addr       switchD_004d1c32::caseD_6
//         004d1f08     addr       switchD_004d1c32::caseD_1
//         004d1f0c     addr       switchD_004d1c32::caseD_1
//         004d1f10     addr       switchD_004d1c32::caseD_9
//         004d1f14     addr       switchD_004d1c32::caseD_a
//         004d1f18     addr       switchD_004d1c32::caseD_1
//         004d1f1c     addr       switchD_004d1c32::caseD_c
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d1c50::switchdataD_004d1f20                       XREF[1]:     update:004d1c50(*)
//         004d1f20     addr       switchD_004d1c50::caseD_0
//         004d1f24     addr       switchD_004d1c50::caseD_0
//         004d1f28     addr       switchD_004d1c50::caseD_0
//         004d1f2c     addr       switchD_004d1c50::caseD_3
//         004d1f30     addr       switchD_004d1c50::caseD_0
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004d1c93::switchdataD_004d1f34                       XREF[1]:     update:004d1c93(*)
//         004d1f34     addr       switchD_004d1c93::caseD_0
//         004d1f38     addr       switchD_004d1c93::caseD_0
//         004d1f3c     addr       switchD_004d1c93::caseD_0
//         004d1f40     addr       switchD_004d1c93::caseD_3
//         004d1f44     addr       switchD_004d1c93::caseD_3
//         004d1f48     ??         90h
//         004d1f49     ??         90h
//         004d1f4a     ??         90h
//         004d1f4b     ??         90h
//         004d1f4c     ??         90h
//         004d1f4d     ??         90h
//         004d1f4e     ??         90h
//         004d1f4f     ??         90h
    return 0;
}

int TRIBE_Action_Repair::stop() {
    /* TODO: Stub */
//                              int __thiscall stop(TRIBE_Action_Repair * this)
//              int               EAX:4          <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//                               ?stop@TRIBE_Action_Repair@@UAEHXZ                            XREF[1]:     00575234(*)
//                               TRIBE_Action_Repair::stop
//                              tact_rep.cpp:447 (7)
//         004d1f50     MOV        EAX,dword ptr [this->_padding_]
//         004d1f52     PUSH       0x2
//         004d1f54     CALL       dword ptr [EAX + 0x5c]
//                              tact_rep.cpp:449 (5)
//         004d1f57     MOV        EAX,0x1
//                              tact_rep.cpp:450 (1)
//         004d1f5c     RET
//         004d1f5d     ??         90h
//         004d1f5e     NOP
//         004d1f5f     NOP
    return 0;
}

int TRIBE_Action_Repair::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall move_to(TRIBE_Action_Repair * this, RGE_Static_Object
//              int               EAX:4          <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004d1f60(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d1f6b(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d1f64(R)
//                               ?move_to@TRIBE_Action_Repair@@UAEHPAVRGE_Static_Object@@MMM@Z XREF[1]:     00575238(*)
//                               TRIBE_Action_Repair::move_to
//                              tact_rep.cpp:457 (4)
//         004d1f60     MOV        EAX,dword ptr [ESP + param_2]
//                              tact_rep.cpp:460 (12)
//         004d1f64     MOV        EDX,dword ptr [ESP + param_4]
//         004d1f68     PUSH       ESI
//         004d1f69     MOV        ESI,this
//         004d1f6b     MOV        this,dword ptr [ESP + param_3]
//         004d1f6f     PUSH       EDI
//                              tact_rep.cpp:461 (18)
//         004d1f70     MOV        EDI,dword ptr [ESI]
//         004d1f72     MOV        dword ptr [ESI + 0x24],this
//         004d1f75     PUSH       0x0
//         004d1f77     MOV        this,ESI
//         004d1f79     MOV        dword ptr [ESI + 0x20],EAX
//         004d1f7c     MOV        dword ptr [ESI + 0x28],EDX
//         004d1f7f     CALL       dword ptr [EDI + 0x54]
//                              tact_rep.cpp:462 (7)
//         004d1f82     PUSH       0xb
//         004d1f84     MOV        this,ESI
//         004d1f86     CALL       dword ptr [EDI + 0x5c]
//                              tact_rep.cpp:464 (10)
//         004d1f89     POP        EDI
//         004d1f8a     MOV        EAX,0x1
//         004d1f8f     POP        ESI
//         004d1f90     RET        0x10
//         004d1f93     ??         90h
//         004d1f94     NOP
//         004d1f95     NOP
//         004d1f96     NOP
//         004d1f97     NOP
//         004d1f98     NOP
//         004d1f99     NOP
//         004d1f9a     NOP
//         004d1f9b     NOP
//         004d1f9c     NOP
//         004d1f9d     NOP
//         004d1f9e     NOP
//         004d1f9f     NOP
    return 0;
}

int TRIBE_Action_Repair::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    /* TODO: Stub */
//                              int __thiscall work(TRIBE_Action_Repair * this, RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     004d1fa3(R)
//              float             Stack[0x8]:4   param_2                   XREF[1]:     004d1ff4(R)
//              float             Stack[0xc]:4   param_3                   XREF[1]:     004d1ff0(R)
//              float             Stack[0x10]:4  param_4                   XREF[1]:     004d1ff8(R)
//                               ?work@TRIBE_Action_Repair@@UAEHPAVRGE_Static_Object@@MMM@Z   XREF[1]:     0057523c(*)
//                               TRIBE_Action_Repair::work
//                              tact_rep.cpp:471 (3)
//         004d1fa0     PUSH       EBX
//         004d1fa1     PUSH       ESI
//         004d1fa2     PUSH       EDI
//                              tact_rep.cpp:472 (10)
//         004d1fa3     MOV        EDI,dword ptr [ESP + param_1]
//         004d1fa7     TEST       EDI,EDI
//         004d1fa9     MOV        ESI,this
//         004d1fab     JZ         LAB_004d1ff0
//                              tact_rep.cpp:476 (14)
//         004d1fad     CMP        EDI,dword ptr [ESI + 0x10]
//         004d1fb0     JNZ        LAB_004d1fbd
//         004d1fb2     MOV        AL,byte ptr [ESI + 0xc]
//         004d1fb5     CMP        AL,0x4
//         004d1fb7     JZ         LAB_004d2015
//         004d1fb9     CMP        AL,0x6
//                              tact_rep.cpp:477 (2)
//         004d1fbb     JZ         LAB_004d2015
//                               LAB_004d1fbd                                                 XREF[1]:     004d1fb0(j)
//                              tact_rep.cpp:479 (8)
//         004d1fbd     MOV        EBX,dword ptr [ESI]
//         004d1fbf     PUSH       EDI
//         004d1fc0     MOV        this,ESI
//         004d1fc2     CALL       dword ptr [EBX + 0x54]
//                              tact_rep.cpp:480 (6)
//         004d1fc5     MOV        EAX,dword ptr [EDI + 0x38]
//         004d1fc8     MOV        dword ptr [ESI + 0x20],EAX
//                              tact_rep.cpp:481 (6)
//         004d1fcb     MOV        this,dword ptr [EDI + 0x3c]
//         004d1fce     MOV        dword ptr [ESI + 0x24],this
//                              tact_rep.cpp:482 (3)
//         004d1fd1     MOV        EDX,dword ptr [EDI + 0x40]
//                              tact_rep.cpp:483 (10)
//         004d1fd4     MOV        this,ESI
//         004d1fd6     MOV        dword ptr [ESI + 0x28],EDX
//         004d1fd9     CALL       TRIBE_Action_Repair::meet_target                 void meet_target(TRIBE_Action_Repair * this)
//                              tact_rep.cpp:484 (7)
//         004d1fde     PUSH       0x4
//         004d1fe0     MOV        this,ESI
//         004d1fe2     CALL       dword ptr [EBX + 0x5c]
//                              tact_rep.cpp:494 (5)
//         004d1fe5     MOV        EAX,0x1
//                              tact_rep.cpp:495 (6)
//         004d1fea     POP        EDI
//         004d1feb     POP        ESI
//         004d1fec     POP        EBX
//         004d1fed     RET        0x10
//                               LAB_004d1ff0                                                 XREF[1]:     004d1fab(j)
//                              tact_rep.cpp:489 (8)
//         004d1ff0     MOV        this,dword ptr [ESP + param_3]
//         004d1ff4     MOV        EAX,dword ptr [ESP + param_2]
//                              tact_rep.cpp:490 (4)
//         004d1ff8     MOV        EDX,dword ptr [ESP + param_4]
//                              tact_rep.cpp:491 (18)
//         004d1ffc     MOV        EDI,dword ptr [ESI]
//         004d1ffe     MOV        dword ptr [ESI + 0x24],this
//         004d2001     PUSH       0x0
//         004d2003     MOV        this,ESI
//         004d2005     MOV        dword ptr [ESI + 0x20],EAX
//         004d2008     MOV        dword ptr [ESI + 0x28],EDX
//         004d200b     CALL       dword ptr [EDI + 0x54]
//                              tact_rep.cpp:492 (7)
//         004d200e     PUSH       0xb
//         004d2010     MOV        this,ESI
//         004d2012     CALL       dword ptr [EDI + 0x5c]
//                               LAB_004d2015                                                 XREF[2]:     004d1fb7(j), 004d1fbb(j)
//                              tact_rep.cpp:495 (11)
//         004d2015     POP        EDI
//         004d2016     POP        ESI
//         004d2017     MOV        EAX,0x1
//         004d201c     POP        EBX
//         004d201d     RET        0x10
    return 0;
}

void TRIBE_Action_Repair::meet_target() {
    /* TODO: Stub */
//                              void __thiscall meet_target(TRIBE_Action_Repair * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//              XYPoint           Stack[-0xc]:8  rVal
//              XYPoint           Stack[-0x14]:8 start
//              XYPoint           Stack[-0x1c]:8 dest
//                               ?meet_target@TRIBE_Action_Repair@@IAEXXZ                     XREF[2]:     TRIBE_Action_Repair:004d178d(c),
//                               TRIBE_Action_Repair::meet_target                                          work:004d1fd9(c)
//                              tact_rep.cpp:501 (9)
//         004d2020     SUB        ESP,0x20
//         004d2023     PUSH       EBX
//         004d2024     PUSH       EBP
//         004d2025     PUSH       ESI
//         004d2026     PUSH       EDI
//         004d2027     MOV        EDI,this
//                              tact_rep.cpp:508 (38)
//         004d2029     MOV        EAX,dword ptr [EDI + 0x10]
//         004d202c     MOV        this,dword ptr [EAX + 0x8]
//         004d202f     MOV        AX,word ptr [ECX + this->_padding_]
//         004d2033     CMP        AX,0x2
//         004d2037     JZ         LAB_004d204f
//         004d2039     CMP        AX,0x14
//         004d203d     JZ         LAB_004d204f
//         004d203f     CMP        AX,0x15
//         004d2043     JZ         LAB_004d204f
//         004d2045     CMP        AX,0x16
//         004d2049     JNZ        LAB_004d213e
//                               LAB_004d204f                                                 XREF[3]:     004d2037(j), 004d203d(j),
//                                                                                                         004d2043(j)
//                              tact_rep.cpp:515 (16)
//         004d204f     MOV        EDX,dword ptr [EDI + 0x8]
//         004d2052     MOV        EAX,dword ptr [EDX + 0xc]
//         004d2055     MOV        this,dword ptr [EAX + 0x28]
//         004d2058     MOV        EBP,dword ptr [ECX + this->_padding_]
//         004d205b     TEST       EBP,EBP
//         004d205d     JZ         LAB_004d209a
//                               LAB_004d205f                                                 XREF[1]:     004d2098(j)
//                              tact_rep.cpp:517 (21)
//         004d205f     MOV        ESI,dword ptr [EBP]
//         004d2062     MOV        EAX,dword ptr [EDI + 0x8]
//         004d2065     CMP        ESI,EAX
//         004d2067     JZ         LAB_004d2093
//         004d2069     MOV        EDX,dword ptr [ESI + 0x8]
//         004d206c     CMP        word ptr [EDX + 0x10],0x9c
//         004d2072     JNZ        LAB_004d2093
//                              tact_rep.cpp:520 (31)
//         004d2074     MOV        EBX,dword ptr [ESI]
//         004d2076     MOV        this,ESI
//         004d2078     CALL       dword ptr [EBX + 0xcc]
//         004d207e     CMP        EAX,dword ptr [EDI + 0x10]
//         004d2081     JNZ        LAB_004d2093
//         004d2083     MOV        this,ESI
//         004d2085     CALL       dword ptr [EBX + 0x134]
//         004d208b     CMP        AL,0x2
//         004d208d     JNZ        LAB_004d2146
//                               LAB_004d2093                                                 XREF[3]:     004d2067(j), 004d2072(j),
//                                                                                                         004d2081(j)
//                              tact_rep.cpp:515 (7)
//         004d2093     MOV        EBP,dword ptr [EBP + 0x4]
//         004d2096     TEST       EBP,EBP
//         004d2098     JNZ        LAB_004d205f
//                               LAB_004d209a                                                 XREF[1]:     004d205d(j)
//                              tact_rep.cpp:540 (15)
//         004d209a     MOV        ESI,dword ptr [EDI + 0x8]
//         004d209d     FLD        float ptr [ESI + 0x38]
//         004d20a0     CALL       __ftol                                           undefined __ftol()
//         004d20a5     MOV        dword ptr [ESP + 0x20],EAX
//                              tact_rep.cpp:541 (8)
//         004d20a9     FLD        float ptr [ESI + 0x3c]
//         004d20ac     CALL       __ftol                                           undefined __ftol()
//                              tact_rep.cpp:543 (19)
//         004d20b1     MOV        EBX,dword ptr [EDI + 0x10]
//         004d20b4     MOV        dword ptr [ESP + 0x24],EAX
//         004d20b8     FLD        float ptr [EBX + 0x38]
//         004d20bb     CALL       __ftol                                           undefined __ftol()
//         004d20c0     MOV        dword ptr [ESP + 0x18],EAX
//                              tact_rep.cpp:544 (8)
//         004d20c4     FLD        float ptr [EBX + 0x3c]
//         004d20c7     CALL       __ftol                                           undefined __ftol()
//                              tact_rep.cpp:546 (40)
//         004d20cc     PUSH       0x1
//         004d20ce     PUSH       0x2
//         004d20d0     LEA        this,[ESP + 0x30]
//         004d20d4     PUSH       0x2
//         004d20d6     PUSH       this
//         004d20d7     LEA        EDX,[ESP + 0x28]
//         004d20db     LEA        this,[ESP + 0x30]
//         004d20df     MOV        dword ptr [ESP + 0x2c],EAX
//         004d20e3     MOV        EAX,dword ptr [ESI]
//         004d20e5     PUSH       EDX
//         004d20e6     PUSH       this
//         004d20e7     MOV        this,ESI
//         004d20e9     CALL       dword ptr [EAX + 0x1b4]
//         004d20ef     CMP        EAX,0x1
//         004d20f2     JNZ        LAB_004d213e
//                              tact_rep.cpp:549 (4)
//         004d20f4     FILD       dword ptr [ESP + 0x28]
//                              tact_rep.cpp:553 (58)
//         004d20f8     MOV        this,dword ptr [EDI + 0x10]
//         004d20fb     PUSH       EAX
//         004d20fc     PUSH       0x0
//         004d20fe     FSUB       float ptr [DAT_0057527c]
//         004d2104     MOV        EDX,dword ptr [this->_padding_]
//         004d2106     FST        float ptr [ESP + 0x1c]
//         004d210a     FSTP       float ptr [EDI + 0x20]
//         004d210d     FILD       dword ptr [ESP + 0x34]
//         004d2111     FSUB       float ptr [DAT_0057527c]
//         004d2117     FST        float ptr [ESP + 0x18]
//         004d211b     FSTP       float ptr [EDI + 0x24]
//         004d211e     MOV        EAX,dword ptr [ECX + this->save_target_command
//         004d2121     PUSH       EAX
//         004d2122     MOV        EAX,dword ptr [ESP + 0x1c]
//         004d2126     PUSH       EAX
//         004d2127     MOV        EAX,dword ptr [ESP + 0x24]
//         004d212b     PUSH       EAX
//         004d212c     CALL       dword ptr [EDX + 0x154]
//                              tact_rep.cpp:554 (12)
//         004d2132     MOV        this,dword ptr [EDI + 0x10]
//         004d2135     MOV        DL,byte ptr [this->_padding_ + 0x188]
//         004d213b     MOV        byte ptr [EDI + 0x40],DL
//                               LAB_004d213e                                                 XREF[2]:     004d2049(j), 004d20f2(j)
//                              tact_rep.cpp:557 (8)
//         004d213e     POP        EDI
//         004d213f     POP        ESI
//         004d2140     POP        EBP
//         004d2141     POP        EBX
//         004d2142     ADD        ESP,0x20
//         004d2145     RET
//                               LAB_004d2146                                                 XREF[1]:     004d208d(j)
//                              tact_rep.cpp:522 (15)
//         004d2146     MOV        this,dword ptr [EDI + 0x10]
//         004d2149     MOV        EAX,dword ptr [this->_padding_]
//         004d214b     CALL       dword ptr [EAX + 0x134]
//         004d2151     CMP        AL,0xb
//         004d2153     JNZ        LAB_004d218d
//                              tact_rep.cpp:524 (21)
//         004d2155     MOV        this,dword ptr [EDI + 0x10]
//         004d2158     MOV        this,dword ptr [this->_padding_ + 0x184]
//         004d215e     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004d2163     MOV        this,EAX
//         004d2165     CALL       RGE_Action::targetX                              float targetX(RGE_Action * this)
//                              tact_rep.cpp:525 (27)
//         004d216a     MOV        EDX,dword ptr [EDI + 0x10]
//         004d216d     FSTP       float ptr [EDI + 0x20]
//         004d2170     MOV        this,dword ptr [EDX + 0x184]
//         004d2176     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
//         004d217b     MOV        this,EAX
//         004d217d     CALL       RGE_Action::targetY                              float targetY(RGE_Action * this)
//         004d2182     FSTP       float ptr [EDI + 0x24]
//                              tact_rep.cpp:557 (8)
//         004d2185     POP        EDI
//         004d2186     POP        ESI
//         004d2187     POP        EBP
//         004d2188     POP        EBX
//         004d2189     ADD        ESP,0x20
//         004d218c     RET
//                               LAB_004d218d                                                 XREF[1]:     004d2153(j)
//                              tact_rep.cpp:529 (9)
//         004d218d     MOV        EAX,dword ptr [EDI + 0x10]
//         004d2190     MOV        this,dword ptr [EAX + 0x38]
//         004d2193     MOV        dword ptr [EDI + 0x20],this
//                              tact_rep.cpp:530 (6)
//         004d2196     MOV        EDX,dword ptr [EAX + 0x3c]
//         004d2199     MOV        dword ptr [EDI + 0x24],EDX
//                              tact_rep.cpp:557 (8)
//         004d219c     POP        EDI
//         004d219d     POP        ESI
//         004d219e     POP        EBP
//         004d219f     POP        EBX
//         004d21a0     ADD        ESP,0x20
//         004d21a3     RET
//         004d21a4     ??         90h
//         004d21a5     NOP
//         004d21a6     NOP
//         004d21a7     NOP
//         004d21a8     NOP
//         004d21a9     NOP
//         004d21aa     NOP
//         004d21ab     NOP
//         004d21ac     NOP
//         004d21ad     NOP
//         004d21ae     NOP
//         004d21af     NOP
    return;
}

TRIBE_Action_Repair::~TRIBE_Action_Repair() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Action_Repair(TRIBE_Action_Repair * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Action_R    ECX:4 (auto)   this
//                               ??1TRIBE_Action_Repair@@UAE@XZ                               XREF[1]:     `vector_deleting_destructor':004d1
//                               TRIBE_Action_Repair::~TRIBE_Action_Repair
//         004d1710     JMP        RGE_Action::~RGE_Action
//         004d1715     ??         90h
//         004d1716     NOP
//         004d1717     NOP
//         004d1718     NOP
//         004d1719     NOP
//         004d171a     NOP
//         004d171b     NOP
//         004d171c     NOP
//         004d171d     NOP
//         004d171e     NOP
//         004d171f     NOP
}

