#include "../common.h"
#include "taicrule.h"

CombatRuleSystem::CombatRuleSystem() {
    /* TODO: Stub */
//                              undefined __thiscall CombatRuleSystem(CombatRuleSystem * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              CombatRuleSyst    ECX:4 (auto)   this
//                               ??0CombatRuleSystem@@QAE@XZ
//                               CombatRuleSystem::CombatRuleSystem
//                              taicrule.cpp:23 (8)
//         004d68d0     MOV        EAX,this
//         004d68d2     MOV        dword ptr [EAX],CombatRuleSystem::`vftable'      = 004d68e0
//                              taicrule.cpp:24 (1)
//         004d68d8     RET
//         004d68d9     ??         90h
//         004d68da     NOP
//         004d68db     NOP
//         004d68dc     NOP
//         004d68dd     NOP
//         004d68de     NOP
//         004d68df     NOP
}

CombatRuleSystem::~CombatRuleSystem() {
    /* TODO: Stub */
//                              void __thiscall ~CombatRuleSystem(CombatRuleSystem * this)
//              void              <VOID>         <RETURN>
//              CombatRuleSyst    ECX:4 (auto)   this
//                               ??1CombatRuleSystem@@UAE@XZ                                  XREF[1]:     `scalar_deleting_destructor':004d6
//                               CombatRuleSystem::~CombatRuleSystem
//                              taicrule.cpp:29 (6)
//         004d6900     MOV        dword ptr [this->_padding_],CombatRuleSystem::   = 004d68e0
//                              taicrule.cpp:30 (1)
//         004d6906     RET
//         004d6907     ??         90h
//         004d6908     NOP
//         004d6909     NOP
//         004d690a     NOP
//         004d690b     NOP
//         004d690c     NOP
//         004d690d     NOP
//         004d690e     NOP
//         004d690f     NOP
}

int CombatRuleSystem::loadRules(char* param_1) {
    /* TODO: Stub */
//                              int __thiscall loadRules(CombatRuleSystem * this, char * param_1)
//              int               EAX:4          <RETURN>
//              CombatRuleSyst    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[2]:     004d6917(R), 004d6a46(R)
//              char[256]         Stack[-0x104   temp                      XREF[2,6]:   004d69ec(*), 004d6a16(R), 004d6964(*), 004d6976(*),
//                                                                                     004d69a0(*), 004d69c8(*), 004d69f7(*), 004d6a2c(*)
//              int               Stack[-0x108   targetUnitType            XREF[2]:     004d69e8(*), 004d6a23(R)
//              int               Stack[-0x10c   rating                    XREF[2]:     004d69f1(*), 004d6a06(R)
//              int               Stack[-0x110   unitIndex                 XREF[0,4]:   004d69c2(*), 004d69d7(R), 004d69be(*), 004d69e2(R)
//              char              Stack[-0x111   commentTemp2
//              char              Stack[-0x112   commentTemp1
//                               ?loadRules@CombatRuleSystem@@QAEHPAD@Z
//                               CombatRuleSystem::loadRules
//                              taicrule.cpp:35 (7)
//         004d6910     SUB        ESP,0x110
//         004d6916     PUSH       EBX
//                              taicrule.cpp:38 (76)
//         004d6917     MOV        EBX,dword ptr [ESP + param_1]
//         004d691e     PUSH       EBP
//         004d691f     PUSH       ESI
//         004d6920     PUSH       EDI
//         004d6921     MOV        EBP,this
//         004d6923     MOV        ESI,s_NONE                                       = 4Eh
//         004d6928     MOV        EAX,EBX
//                               LAB_004d692a                                                 XREF[1]:     004d6948(j)
//         004d692a     MOV        DL,byte ptr [EAX]
//         004d692c     MOV        this,DL
//         004d692e     CMP        DL,byte ptr [ESI]=>s_NONE                        = 4Eh
//         004d6930     JNZ        LAB_004d694e
//         004d6932     TEST       this,this
//         004d6934     JZ         LAB_004d694a
//         004d6936     MOV        DL,byte ptr [EAX + 0x1]
//         004d6939     MOV        this,DL
//         004d693b     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0057f351            = 4Fh
//                                                                                  = 45h
//         004d693e     JNZ        LAB_004d694e
//         004d6940     ADD        EAX,0x2
//         004d6943     ADD        ESI,0x2
//         004d6946     TEST       this,this
//         004d6948     JNZ        LAB_004d692a
//                               LAB_004d694a                                                 XREF[1]:     004d6934(j)
//         004d694a     XOR        EAX,EAX
//         004d694c     JMP        LAB_004d6953
//                               LAB_004d694e                                                 XREF[2]:     004d6930(j), 004d693e(j)
//         004d694e     SBB        EAX,EAX
//         004d6950     SBB        EAX,-0x1
//                               LAB_004d6953                                                 XREF[1]:     004d694c(j)
//         004d6953     TEST       EAX,EAX
//         004d6955     JZ         LAB_004d6a83
//         004d695b     TEST       EBX,EBX
//         004d695d     JZ         LAB_004d6a83
//                              taicrule.cpp:42 (19)
//         004d6963     PUSH       EBX
//         004d6964     LEA        EAX=>temp[4],[ESP + 0x24]
//         004d6968     PUSH       s_%s                                             = "%s"
//         004d696d     PUSH       EAX
//         004d696e     CALL       sprintf                                          undefined sprintf()
//         004d6973     ADD        ESP,0xc
//                              taicrule.cpp:43 (20)
//         004d6976     LEA        this=>temp[4],[ESP + 0x20]
//         004d697a     PUSH       s_r                                              = "r"
//         004d697f     PUSH       this
//         004d6980     CALL       fopen                                            undefined fopen()
//         004d6985     MOV        ESI,EAX
//         004d6987     ADD        ESP,0x8
//                              taicrule.cpp:44 (2)
//         004d698a     TEST       ESI,ESI
//                              taicrule.cpp:45 (6)
//         004d698c     JZ         LAB_004d6a83
//                              taicrule.cpp:74 (42)
//         004d6992     LEA        EDI,[EBP + 0x4]
//         004d6995     MOV        this,0x271
//         004d699a     MOV        EAX,0x32323232
//         004d699f     PUSH       ESI
//         004d69a0     LEA        EDX=>temp[4],[ESP + 0x24]
//         004d69a4     PUSH       0x100
//         004d69a9     STOSD.REP  ES:EDI
//         004d69ab     PUSH       EDX
//         004d69ac     CALL       fgets                                            undefined fgets()
//         004d69b1     ADD        ESP,0xc
//         004d69b4     TEST       EAX,EAX
//         004d69b6     JZ         LAB_004d6a4d
//                              taicrule.cpp:52 (2)
//         004d69bc     MOV        BL,0x2f
//                               LAB_004d69be                                                 XREF[1]:     004d6a40(j)
//                              taicrule.cpp:55 (25)
//         004d69be     LEA        EAX=>unitIndex+0x3,[ESP + 0x13]
//         004d69c2     LEA        this=>unitIndex+0x2,[ESP + 0x12]
//         004d69c6     PUSH       EAX
//         004d69c7     PUSH       this
//         004d69c8     LEA        EDX=>temp[4],[ESP + 0x28]
//         004d69cc     PUSH       s_%c%c                                           = "%c%c"
//         004d69d1     PUSH       EDX
//         004d69d2     CALL       sscanf                                           undefined sscanf()
//                              taicrule.cpp:57 (17)
//         004d69d7     MOV        AL,byte ptr [ESP + unitIndex+0x2]
//         004d69db     ADD        ESP,0x10
//         004d69de     CMP        AL,BL
//         004d69e0     JNZ        LAB_004d69e8
//         004d69e2     CMP        byte ptr [ESP + unitIndex+0x3],BL
//         004d69e6     JZ         LAB_004d6a2b
//                               LAB_004d69e8                                                 XREF[1]:     004d69e0(j)
//                              taicrule.cpp:64 (30)
//         004d69e8     LEA        EAX=>targetUnitType,[ESP + 0x18]
//         004d69ec     LEA        this=>temp,[ESP + 0x1c]
//         004d69f0     PUSH       EAX
//         004d69f1     LEA        EDX=>rating,[ESP + 0x18]
//         004d69f5     PUSH       this
//         004d69f6     PUSH       EDX
//         004d69f7     LEA        EAX=>temp[4],[ESP + 0x2c]
//         004d69fb     PUSH       s_%d_%d_%d_                                      = "%d %d %d "
//         004d6a00     PUSH       EAX
//         004d6a01     CALL       sscanf                                           undefined sscanf()
//                              taicrule.cpp:65 (16)
//         004d6a06     MOV        EAX,dword ptr [ESP + rating]
//         004d6a0a     ADD        ESP,0x14
//         004d6a0d     TEST       EAX,EAX
//         004d6a0f     JL         LAB_004d6a2b
//         004d6a11     CMP        EAX,0x32
//         004d6a14     JGE        LAB_004d6a2b
//                              taicrule.cpp:66 (48)
//         004d6a16     MOV        EDX,dword ptr [ESP + temp[0]]
//         004d6a1a     LEA        EAX,[EAX + EAX*0x4]
//         004d6a1d     LEA        this,[EAX + EAX*0x4]
//         004d6a20     LEA        EAX,[EDX + this->_padding_*0x2]
//         004d6a23     MOV        this,byte ptr [ESP + targetUnitType]
//         004d6a27     MOV        byte ptr [EAX + EBP*0x1 + 0x4],this
//                               LAB_004d6a2b                                                 XREF[3]:     004d69e6(j), 004d6a0f(j),
//                                                                                                         004d6a14(j)
//         004d6a2b     PUSH       ESI
//         004d6a2c     LEA        EDX=>temp[4],[ESP + 0x24]
//         004d6a30     PUSH       0x100
//         004d6a35     PUSH       EDX
//         004d6a36     CALL       fgets                                            undefined fgets()
//         004d6a3b     ADD        ESP,0xc
//         004d6a3e     TEST       EAX,EAX
//         004d6a40     JNZ        LAB_004d69be
//                              taicrule.cpp:52 (7)
//         004d6a46     MOV        EBX,dword ptr [ESP + param_1]
//                               LAB_004d6a4d                                                 XREF[1]:     004d69b6(j)
//                              taicrule.cpp:69 (9)
//         004d6a4d     PUSH       ESI
//         004d6a4e     CALL       fclose                                           undefined fclose()
//         004d6a53     ADD        ESP,0x4
//                              taicrule.cpp:71 (18)
//         004d6a56     PUSH       s_.tmp                                           = ".tmp"
//         004d6a5b     PUSH       EBX
//         004d6a5c     CALL       strstr                                           undefined strstr()
//         004d6a61     ADD        ESP,0x8
//         004d6a64     TEST       EAX,EAX
//         004d6a66     JZ         LAB_004d6a71
//                              taicrule.cpp:72 (9)
//         004d6a68     PUSH       EBX
//         004d6a69     CALL       __unlink                                         undefined __unlink()
//         004d6a6e     ADD        ESP,0x4
//                               LAB_004d6a71                                                 XREF[1]:     004d6a66(j)
//                              taicrule.cpp:73 (5)
//         004d6a71     MOV        EAX,0x1
//                              taicrule.cpp:74 (28)
//         004d6a76     POP        EDI
//         004d6a77     POP        ESI
//         004d6a78     POP        EBP
//         004d6a79     POP        EBX
//         004d6a7a     ADD        ESP,0x110
//         004d6a80     RET        0x4
//                               LAB_004d6a83                                                 XREF[3]:     004d6955(j), 004d695d(j),
//                                                                                                         004d698c(j)
//         004d6a83     POP        EDI
//         004d6a84     POP        ESI
//         004d6a85     POP        EBP
//         004d6a86     XOR        EAX,EAX
//         004d6a88     POP        EBX
//         004d6a89     ADD        ESP,0x110
//         004d6a8f     RET        0x4
//         004d6a92     ??         90h
//         004d6a93     NOP
//         004d6a94     NOP
//         004d6a95     NOP
//         004d6a96     NOP
//         004d6a97     NOP
//         004d6a98     NOP
//         004d6a99     NOP
//         004d6a9a     NOP
//         004d6a9b     NOP
//         004d6a9c     NOP
//         004d6a9d     NOP
//         004d6a9e     NOP
//         004d6a9f     NOP
    return 0;
}

int CombatRuleSystem::bestUnitTypeToAttack(int param_1) {
    /* TODO: Stub */
//                              int __thiscall bestUnitTypeToAttack(CombatRuleSystem * this, int par
//              int               EAX:4          <RETURN>
//              CombatRuleSyst    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?bestUnitTypeToAttack@CombatRuleSystem@@QAEHH@Z
//                               CombatRuleSystem::bestUnitTypeToAttack
//                              taicrule.cpp:79 (3)
//         004d6aa0     OR         EAX,0xffffffff
//                              taicrule.cpp:81 (3)
//         004d6aa3     RET        0x4
//         004d6aa6     ??         90h
//         004d6aa7     NOP
//         004d6aa8     NOP
//         004d6aa9     NOP
//         004d6aaa     NOP
//         004d6aab     NOP
//         004d6aac     NOP
//         004d6aad     NOP
//         004d6aae     NOP
//         004d6aaf     NOP
    return 0;
}

int CombatRuleSystem::bestUnitTypeToDefendAgainst(int param_1) {
    /* TODO: Stub */
//                              int __thiscall bestUnitTypeToDefendAgainst(CombatRuleSystem * this,
//              int               EAX:4          <RETURN>
//              CombatRuleSyst    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?bestUnitTypeToDefendAgainst@CombatRuleSystem@@QAEHH@Z
//                               CombatRuleSystem::bestUnitTypeToDefendAgainst
//                              taicrule.cpp:86 (3)
//         004d6ab0     OR         EAX,0xffffffff
//                              taicrule.cpp:88 (3)
//         004d6ab3     RET        0x4
//         004d6ab6     ??         90h
//         004d6ab7     NOP
//         004d6ab8     NOP
//         004d6ab9     NOP
//         004d6aba     NOP
//         004d6abb     NOP
//         004d6abc     NOP
//         004d6abd     NOP
//         004d6abe     NOP
//         004d6abf     NOP
    return 0;
}

