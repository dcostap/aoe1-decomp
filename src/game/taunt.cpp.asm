#include "common.h"
#include "taunt.h"

TTaunt::TTaunt(TSound_Driver* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TTaunt(TTaunt * this, TSound_Driver * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //              TSound_Driver *   Stack[0x4]:4   param_1                   XREF[1]:     00509450(R)  
    //                               ??0TTaunt@@QAE@PAVTSound_Driver@@@Z                          XREF[2]:     TChat:00423c74(c), 
    //                               TTaunt::TTaunt                                                            TEST:004289dd(c)  
    //                              taunt.cpp:16 (20)
    //         00509450     MOV        EAX,dword ptr [ESP + param_1]
    //         00509454     PUSH       ESI
    //         00509455     MOV        ESI,this
    //         00509457     PUSH       EAX
    //         00509458     MOV        byte ptr [ESI + 0x113],0x0
    //         0050945f     CALL       TTaunt::RestartSoundSystem                       int RestartSoundSystem(TTaunt * this, TSound_
    //                              taunt.cpp:21 (10)
    //         00509464     MOV        dword ptr [ESI + 0x194],0x0
    //                              taunt.cpp:22 (6)
    //         0050946e     MOV        EAX,ESI
    //         00509470     POP        ESI
    //         00509471     RET        0x4
    //         00509474     ??         90h
    //         00509475     NOP
    //         00509476     NOP
    //         00509477     NOP
    //         00509478     NOP
    //         00509479     NOP
    //         0050947a     NOP
    //         0050947b     NOP
    //         0050947c     NOP
    //         0050947d     NOP
    //         0050947e     NOP
    //         0050947f     NOP
}

TTaunt::~TTaunt() {
    /* TODO: Stub */
    //                              void __thiscall ~TTaunt(TTaunt * this)
    //              void              <VOID>         <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //                               ??1TTaunt@@QAE@XZ                                            XREF[2]:     ~TChat:00423ce4(c), 
    //                               TTaunt::~TTaunt                                                           TEST:00428a3f(c)  
    //                              taunt.cpp:25 (5)
    //         00509480     JMP        TTaunt::StopSoundSystem
    //         00509485     ??         90h
    //         00509486     NOP
    //         00509487     NOP
    //         00509488     NOP
    //         00509489     NOP
    //         0050948a     NOP
    //         0050948b     NOP
    //         0050948c     NOP
    //         0050948d     NOP
    //         0050948e     NOP
    //         0050948f     NOP
}

int TTaunt::PlayTauntStr(char* param_1, uchar param_2) {
    /* TODO: Stub */
    //                              int __thiscall PlayTauntStr(TTaunt * this, char * param_1, uchar par
    //              int               EAX:4          <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     005094a2(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     005094b5(R)  
    //                               ?PlayTauntStr@TTaunt@@QAEHPADE@Z                             XREF[1]:     AddChatMsg:00423ddd(c)  
    //                               TTaunt::PlayTauntStr
    //                              taunt.cpp:30 (6)
    //         00509490     PUSH       EBX
    //         00509491     PUSH       EBP
    //         00509492     PUSH       ESI
    //         00509493     MOV        ESI,this
    //         00509495     PUSH       EDI
    //                              taunt.cpp:35 (46)
    //         00509496     MOV        EDI,DAT_00576548                                 = 21h
    //         0050949b     OR         this,0xffffffff
    //         0050949e     XOR        EAX,EAX
    //         005094a0     SCASB.RE   ES:EDI=>DAT_00576548                             = 21h
    //                                                                                  = 4Dh
    //         005094a2     MOV        EBP,dword ptr [ESP + param_1]
    //         005094a6     NOT        this
    //         005094a8     DEC        this
    //         005094a9     PUSH       this
    //         005094aa     PUSH       DAT_00576548                                     = 21h
    //         005094af     PUSH       EBP
    //         005094b0     CALL       __strnicmp                                       undefined __strnicmp()
    //         005094b5     MOV        BL,byte ptr [ESP + param_2]
    //         005094b9     ADD        ESP,0xc
    //         005094bc     TEST       EAX,EAX
    //         005094be     JNZ        LAB_005094ce
    //         005094c0     TEST       BL,BL
    //         005094c2     JZ         LAB_005094ce
    //                              taunt.cpp:36 (10)
    //         005094c4     MOV        dword ptr [ESI + 0x194],0x1
    //                               LAB_005094ce                                                 XREF[2]:     005094be(j), 005094c2(j)  
    //                              taunt.cpp:39 (38)
    //         005094ce     MOV        EDI,DAT_00576550                                 = 21h
    //         005094d3     OR         this,0xffffffff
    //         005094d6     XOR        EAX,EAX
    //         005094d8     SCASB.RE   ES:EDI=>DAT_00576550                             = 21h
    //                                                                                  = "NOMUTE"
    //         005094da     NOT        this
    //         005094dc     DEC        this
    //         005094dd     PUSH       this
    //         005094de     PUSH       DAT_00576550                                     = 21h
    //         005094e3     PUSH       EBP
    //         005094e4     CALL       __strnicmp                                       undefined __strnicmp()
    //         005094e9     ADD        ESP,0xc
    //         005094ec     TEST       EAX,EAX
    //         005094ee     JNZ        LAB_005094fa
    //         005094f0     TEST       BL,BL
    //         005094f2     JZ         LAB_005094fa
    //                              taunt.cpp:40 (6)
    //         005094f4     MOV        dword ptr [ESI + 0x194],EAX
    //                               LAB_005094fa                                                 XREF[2]:     005094ee(j), 005094f2(j)  
    //                              taunt.cpp:43 (10)
    //         005094fa     MOV        EAX,dword ptr [ESI + 0x194]
    //         00509500     TEST       EAX,EAX
    //         00509502     JZ         LAB_0050950d
    //                              taunt.cpp:44 (2)
    //         00509504     XOR        EAX,EAX
    //                              taunt.cpp:56 (7)
    //         00509506     POP        EDI
    //         00509507     POP        ESI
    //         00509508     POP        EBP
    //         00509509     POP        EBX
    //         0050950a     RET        0x8
    //                               LAB_0050950d                                                 XREF[1]:     00509502(j)  
    //                              taunt.cpp:47 (10)
    //         0050950d     PUSH       EBP
    //         0050950e     MOV        this,ESI
    //         00509510     CALL       TTaunt::GetTauntNo                               int GetTauntNo(TTaunt * this, char * param_1)
    //         00509515     MOV        EDI,EAX
    //                              taunt.cpp:50 (4)
    //         00509517     TEST       EDI,EDI
    //         00509519     JZ         LAB_00509523
    //                              taunt.cpp:52 (8)
    //         0050951b     PUSH       EDI
    //         0050951c     MOV        this,ESI
    //         0050951e     CALL       TTaunt::PlayTauntNo                              int PlayTauntNo(TTaunt * this, int param_1)
    //                               LAB_00509523                                                 XREF[1]:     00509519(j)  
    //                              taunt.cpp:55 (2)
    //         00509523     MOV        EAX,EDI
    //                              taunt.cpp:56 (7)
    //         00509525     POP        EDI
    //         00509526     POP        ESI
    //         00509527     POP        EBP
    //         00509528     POP        EBX
    //         00509529     RET        0x8
    //         0050952c     ??         90h
    //         0050952d     NOP
    //         0050952e     NOP
    //         0050952f     NOP
    return 0;
}

int TTaunt::PlayTauntNo(int param_1) {
    /* TODO: Stub */
    //                              int __thiscall PlayTauntNo(TTaunt * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00509557(R)  
    //              char[128]         Stack[-0x84]   FName                     XREF[0,2]:   00509568(*), 005095c7(*)  
    //                               ?PlayTauntNo@TTaunt@@QAEHH@Z                                 XREF[2]:     TEST:00428a34(c), 
    //                               TTaunt::PlayTauntNo                                                       PlayTauntStr:0050951e(c)  
    //                              taunt.cpp:59 (11)
    //         00509530     SUB        ESP,0x80
    //         00509536     PUSH       EBX
    //         00509537     MOV        EBX,this
    //         00509539     PUSH       ESI
    //         0050953a     PUSH       EDI
    //                              taunt.cpp:62 (8)
    //         0050953b     MOV        EAX,dword ptr [EBX + 0x194]
    //         00509541     TEST       EAX,EAX
    //                              taunt.cpp:63 (6)
    //         00509543     JNZ        LAB_005095f3
    //                              taunt.cpp:65 (8)
    //         00509549     LEA        EAX,[EBX + 0x113]
    //         0050954f     TEST       EAX,EAX
    //                              taunt.cpp:66 (6)
    //         00509551     JZ         LAB_005095f3
    //                              taunt.cpp:68 (9)
    //         00509557     MOV        this,dword ptr [ESP + param_1]
    //         0050955e     TEST       this,this
    //                              taunt.cpp:69 (6)
    //         00509560     JZ         LAB_005095f3
    //                              taunt.cpp:71 (20)
    //         00509566     PUSH       this
    //         00509567     PUSH       EAX
    //         00509568     LEA        EAX=>FName[4],[ESP + 0x14]
    //         0050956c     PUSH       s_%sTaunt%.3d.wav                                = "%sTaunt%.3d.wav"
    //         00509571     PUSH       EAX
    //         00509572     CALL       sprintf                                          undefined sprintf()
    //         00509577     ADD        ESP,0x10
    //                              taunt.cpp:116 (54)
    //         0050957a     MOV        ESI,EBX
    //         0050957c     MOV        EDI,0x4
    //                               LAB_00509581                                                 XREF[1]:     0050959b(j)  
    //         00509581     MOV        this,dword ptr [ESI]
    //         00509583     TEST       this,this
    //         00509585     JZ         LAB_00509597
    //         00509587     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
    //         0050958c     TEST       EAX,EAX
    //         0050958e     JNZ        LAB_00509597
    //         00509590     MOV        this,dword ptr [ESI]
    //         00509592     CALL       TDigital::unload                                 void unload(TDigital * this)
    //                               LAB_00509597                                                 XREF[2]:     00509585(j), 0050958e(j)  
    //         00509597     ADD        ESI,0x4
    //         0050959a     DEC        EDI
    //         0050959b     JNZ        LAB_00509581
    //         0050959d     XOR        ESI,ESI
    //         0050959f     MOV        EDI,EBX
    //                               LAB_005095a1                                                 XREF[1]:     005095b7(j)  
    //         005095a1     MOV        this,dword ptr [EDI]
    //         005095a3     TEST       this,this
    //         005095a5     JZ         LAB_005095b0
    //         005095a7     CALL       TDigital::is_playing                             int is_playing(TDigital * this)
    //         005095ac     TEST       EAX,EAX
    //         005095ae     JZ         LAB_005095c7
    //                               LAB_005095b0                                                 XREF[1]:     005095a5(j)  
    //                              taunt.cpp:81 (9)
    //         005095b0     INC        ESI
    //         005095b1     ADD        EDI,0x4
    //         005095b4     CMP        ESI,0x4
    //         005095b7     JL         LAB_005095a1
    //                              taunt.cpp:96 (2)
    //         005095b9     XOR        EAX,EAX
    //                              taunt.cpp:116 (12)
    //         005095bb     POP        EDI
    //         005095bc     POP        ESI
    //         005095bd     POP        EBX
    //         005095be     ADD        ESP,0x80
    //         005095c4     RET        0x4
    //                               LAB_005095c7                                                 XREF[1]:     005095ae(j)  
    //                              taunt.cpp:85 (15)
    //         005095c7     LEA        this=>FName[4],[ESP + 0xc]
    //         005095cb     PUSH       -0x1
    //         005095cd     PUSH       this
    //         005095ce     MOV        this,dword ptr [EBX + ESI*0x4]
    //         005095d1     CALL       TDigital::load                                   int load(TDigital * this, char * param_1, lon
    //                              taunt.cpp:86 (12)
    //         005095d6     MOV        this,dword ptr [EBX + ESI*0x4]
    //         005095d9     TEST       EAX,EAX
    //         005095db     JZ         LAB_005095ee
    //         005095dd     CALL       TDigital::play                                   int play(TDigital * this)
    //                              taunt.cpp:116 (12)
    //         005095e2     POP        EDI
    //         005095e3     POP        ESI
    //         005095e4     POP        EBX
    //         005095e5     ADD        ESP,0x80
    //         005095eb     RET        0x4
    //                               LAB_005095ee                                                 XREF[1]:     005095db(j)  
    //                              taunt.cpp:89 (5)
    //         005095ee     CALL       TDigital::unload                                 void unload(TDigital * this)
    //                               LAB_005095f3                                                 XREF[3]:     00509543(j), 00509551(j), 
    //                                                                                                         00509560(j)  
    //                              taunt.cpp:116 (14)
    //         005095f3     POP        EDI
    //         005095f4     POP        ESI
    //         005095f5     XOR        EAX,EAX
    //         005095f7     POP        EBX
    //         005095f8     ADD        ESP,0x80
    //         005095fe     RET        0x4
    //         00509601     ??         90h
    //         00509602     NOP
    //         00509603     NOP
    //         00509604     NOP
    //         00509605     NOP
    //         00509606     NOP
    //         00509607     NOP
    //         00509608     NOP
    //         00509609     NOP
    //         0050960a     NOP
    //         0050960b     NOP
    //         0050960c     NOP
    //         0050960d     NOP
    //         0050960e     NOP
    //         0050960f     NOP
    return 0;
}

int TTaunt::GetTauntNo(char* param_1) {
    /* TODO: Stub */
    //                              int __thiscall GetTauntNo(TTaunt * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00509610(R)  
    //                               ?GetTauntNo@TTaunt@@QAEHPAD@Z                                XREF[1]:     PlayTauntStr:00509510(c)  
    //                               TTaunt::GetTauntNo
    //                              taunt.cpp:119 (9)
    //         00509610     MOV        EAX,dword ptr [ESP + param_1]
    //         00509614     CMP        byte ptr [EAX],0x21
    //         00509617     JNZ        LAB_0050961a
    //                              taunt.cpp:127 (1)
    //         00509619     INC        EAX
    //                               LAB_0050961a                                                 XREF[1]:     00509617(j)  
    //                              taunt.cpp:133 (9)
    //         0050961a     PUSH       EAX
    //         0050961b     CALL       atoi                                             undefined atoi()
    //         00509620     ADD        ESP,0x4
    //                              taunt.cpp:136 (4)
    //         00509623     TEST       EAX,EAX
    //         00509625     JNZ        LAB_0050962a
    //                              taunt.cpp:143 (3)
    //         00509627     RET        0x4
    //                               LAB_0050962a                                                 XREF[1]:     00509625(j)  
    //                              taunt.cpp:139 (13)
    //         0050962a     XOR        this,this
    //         0050962c     CMP        EAX,0x3e7
    //         00509631     SETG       this
    //         00509634     DEC        this
    //         00509635     AND        EAX,this
    //                              taunt.cpp:143 (3)
    //         00509637     RET        0x4
    //         0050963a     ??         90h
    //         0050963b     NOP
    //         0050963c     NOP
    //         0050963d     NOP
    //         0050963e     NOP
    //         0050963f     NOP
    return 0;
}

char* TTaunt::GetTauntText(int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall GetTauntText(TTaunt * this, int param_1)
    //              char *            EAX:4          <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //                               ?GetTauntText@TTaunt@@QAEPADH@Z
    //                               TTaunt::GetTauntText
    //                              taunt.cpp:146 (2)
    //         00509640     PUSH       ESI
    //         00509641     PUSH       EDI
    //                              taunt.cpp:154 (32)
    //         00509642     LEA        EDX,[ECX + this->TBuff[0]]
    //         00509645     MOV        EDI,s_Taunts_you!                                = 54h
    //         0050964a     OR         this,0xffffffff
    //         0050964d     XOR        EAX,EAX
    //         0050964f     SCASB.RE   ES:EDI=>s_Taunts_you!                            = 54h
    //                                                                                  = "aunts you!"
    //         00509651     NOT        this
    //         00509653     SUB        EDI,this
    //         00509655     MOV        EAX,this
    //         00509657     MOV        ESI,EDI
    //         00509659     MOV        EDI,EDX
    //         0050965b     SHR        this,0x2
    //         0050965e     MOVSD.REP  ES:EDI,ESI
    //         00509660     MOV        this,EAX
    //                              taunt.cpp:156 (7)
    //         00509662     MOV        EAX,EDX
    //         00509664     AND        this,0x3
    //         00509667     MOVSB.REP  ES:EDI,ESI
    //                              taunt.cpp:157 (5)
    //         00509669     POP        EDI
    //         0050966a     POP        ESI
    //         0050966b     RET        0x4
    //         0050966e     ??         90h
    //         0050966f     NOP
    return 0;
}

void TTaunt::StopSoundSystem() {
    /* TODO: Stub */
    //                              void __thiscall StopSoundSystem(TTaunt * this)
    //              void              <VOID>         <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //                               ?StopSoundSystem@TTaunt@@QAEXXZ                              XREF[2]:     StopSoundSystem:00423eba(c), 
    //                               TTaunt::StopSoundSystem                                                   ~TTaunt:00509480(j)  
    //                              taunt.cpp:160 (5)
    //         00509670     PUSH       EBX
    //         00509671     PUSH       ESI
    //         00509672     PUSH       EDI
    //         00509673     MOV        EDI,this
    //                              taunt.cpp:161 (5)
    //         00509675     MOV        EBX,0x4
    //                               LAB_0050967a                                                 XREF[1]:     0050969a(j)  
    //                              taunt.cpp:163 (6)
    //         0050967a     MOV        ESI,dword ptr [EDI]
    //         0050967c     TEST       ESI,ESI
    //         0050967e     JZ         LAB_00509696
    //                              taunt.cpp:165 (16)
    //         00509680     MOV        this,ESI
    //         00509682     CALL       TDigital::~TDigital                              void ~TDigital(TDigital * this)
    //         00509687     PUSH       ESI
    //         00509688     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0050968d     ADD        ESP,0x4
    //                              taunt.cpp:166 (12)
    //         00509690     MOV        dword ptr [EDI],0x0
    //                               LAB_00509696                                                 XREF[1]:     0050967e(j)  
    //         00509696     ADD        EDI,0x4
    //         00509699     DEC        EBX
    //         0050969a     JNZ        LAB_0050967a
    //                              taunt.cpp:170 (4)
    //         0050969c     POP        EDI
    //         0050969d     POP        ESI
    //         0050969e     POP        EBX
    //         0050969f     RET
    return;
}

int TTaunt::RestartSoundSystem(TSound_Driver* param_1) {
    /* TODO: Stub */
    //                              int __thiscall RestartSoundSystem(TTaunt * this, TSound_Driver * par
    //              int               EAX:4          <RETURN>
    //              TTaunt *          ECX:4 (auto)   this
    //              TSound_Driver *   Stack[0x4]:4   param_1                   XREF[2]:     005096b6(R), 005096d1(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005096d7(W), 005096f9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     005096ff(R)  
    //                               ?RestartSoundSystem@TTaunt@@QAEHPAVTSound_Driver@@@Z         XREF[2]:     RestartSoundSystem:00423ecf(c), 
    //                               TTaunt::RestartSoundSystem                                                TTaunt:0050945f(c)  
    //                              taunt.cpp:173 (22)
    //         005096a0     MOV        EAX,FS:[0x0]
    //         005096a6     PUSH       -0x1
    //         005096a8     PUSH       FUN_00560dab
    //         005096ad     PUSH       EAX
    //         005096ae     MOV        dword ptr FS:[0x0],ESP
    //         005096b5     PUSH       EBX
    //                              taunt.cpp:175 (17)
    //         005096b6     MOV        EBX,dword ptr [ESP + param_1]
    //         005096ba     PUSH       EBP
    //         005096bb     PUSH       ESI
    //         005096bc     PUSH       EDI
    //         005096bd     MOV        ESI,this
    //         005096bf     MOV        EDI,0x4
    //         005096c4     OR         EBP,0xffffffff
    //                               LAB_005096c7                                                 XREF[1]:     005096fd(j)  
    //                              taunt.cpp:176 (56)
    //         005096c7     PUSH       0x3c
    //         005096c9     CALL       operator_new                                     void * operator_new(uint param_1)
    //         005096ce     ADD        ESP,0x4
    //         005096d1     MOV        dword ptr [ESP + param_1],EAX
    //         005096d5     TEST       EAX,EAX
    //         005096d7     MOV        dword ptr [ESP + local_4],0x0
    //         005096df     JZ         LAB_005096f1
    //         005096e1     PUSH       EBP
    //         005096e2     PUSH       s_Silence                                        = "Silence"
    //         005096e7     PUSH       EBX
    //         005096e8     MOV        this,EAX
    //         005096ea     CALL       TDigital::TDigital                               undefined TDigital(TDigital * this, TSound_Dr
    //         005096ef     JMP        LAB_005096f3
    //                               LAB_005096f1                                                 XREF[1]:     005096df(j)  
    //         005096f1     XOR        EAX,EAX
    //                               LAB_005096f3                                                 XREF[1]:     005096ef(j)  
    //         005096f3     MOV        dword ptr [ESI],EAX
    //         005096f5     ADD        ESI,0x4
    //         005096f8     DEC        EDI
    //         005096f9     MOV        dword ptr [ESP + local_4],EBP
    //         005096fd     JNZ        LAB_005096c7
    //                              taunt.cpp:179 (26)
    //         005096ff     MOV        this,dword ptr [ESP + local_c]
    //         00509703     POP        EDI
    //         00509704     POP        ESI
    //         00509705     POP        EBP
    //         00509706     MOV        EAX,0x1
    //         0050970b     MOV        dword ptr FS:[0x0],this
    //         00509712     POP        EBX
    //         00509713     ADD        ESP,0xc
    //         00509716     RET        0x4
    //         00509719     ??         90h
    //         0050971a     NOP
    //         0050971b     NOP
    //         0050971c     NOP
    //         0050971d     NOP
    //         0050971e     NOP
    //         0050971f     NOP
    return 0;
}

