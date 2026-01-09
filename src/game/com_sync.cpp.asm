#include "common.h"
#include "com_sync.h"

RGE_Communications_Synchronize::~RGE_Communications_Synchronize() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Communications_Synchronize(RGE_Communications_S
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ??1RGE_Communications_Synchronize@@QAE@XZ                    XREF[3]:     ~TCommunications_Handler:00426320(
    //                               RGE_Communications_Synchronize::~RGE_Communications_Synchro               UnlinkCurrentLevel:0042c1ec(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c385(c)  
    //                              com_sync.cpp:30 (42)
    //         00433070     LEA        EAX,[ECX + this+0x38]
    //         00433073     MOV        EDX,0x37
    //         00433078     XOR        this,this
    //                               LAB_0043307a                                                 XREF[1]:     00433098(j)  
    //         0043307a     MOV        dword ptr [EAX + -0x4],this
    //         0043307d     MOV        dword ptr [EAX],this
    //         0043307f     MOV        dword ptr [EAX + 0x4],this
    //         00433082     MOV        dword ptr [EAX + 0x8],this
    //         00433085     MOV        dword ptr [EAX + 0xc],this
    //         00433088     MOV        dword ptr [EAX + 0x10],this
    //         0043308b     MOV        dword ptr [EAX + 0x14],this
    //         0043308e     MOV        dword ptr [EAX + 0x18],this
    //         00433091     MOV        dword ptr [EAX + -0x8],this
    //         00433094     ADD        EAX,0x24
    //         00433097     DEC        EDX
    //         00433098     JNZ        LAB_0043307a
    //                              com_sync.cpp:32 (1)
    //         0043309a     RET
    //         0043309b     ??         90h
    //         0043309c     NOP
    //         0043309d     NOP
    //         0043309e     NOP
    //         0043309f     NOP
    //                              * public: int __thiscall RGE_Communications_Synchronize::Add(unsigned int,unsigned long,unsigned lon... *
    //                              int __thiscall Add(RGE_Communications_Synchronize * this, uint param
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     0043313d(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     004330c8(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004330cc(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[2]:     0043312c(R), 00433156(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004330d0(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[1]:     004330d7(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     004330db(R), 0043314f(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[2]:     0043310e(R), 0043314a(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[2]:     0043311e(R), 00433145(R)  
    //                               ?Add@RGE_Communications_Synchronize@@QAEHIKKKJJJJJ@Z         XREF[2]:     EvaluatePlayerMessage:004283cc(c), 
    //                               RGE_Communications_Synchronize::Add                                       DoChecksum:004333ed(c)  
    //                              com_sync.cpp:44 (7)
    //         004330a0     MOV        EAX,dword ptr [ECX + this->DoChecksums]
    //         004330a3     TEST       EAX,EAX
    //         004330a5     JNZ        LAB_004330ac
    //                              com_sync.cpp:46 (2)
    //         004330a7     XOR        EAX,EAX
    //                              com_sync.cpp:62 (3)
    //         004330a9     RET        0x24
    //                               LAB_004330ac                                                 XREF[1]:     004330a5(j)  
    //                              com_sync.cpp:48 (6)
    //         004330ac     MOV        EDX,dword ptr [ECX + this->Offset]
    //         004330af     PUSH       EDI
    //         004330b0     INC        EDX
    //         004330b1     PUSH       ESI
    //                              com_sync.cpp:49 (12)
    //         004330b2     MOV        EAX,EDX
    //         004330b4     PUSH       EBP
    //         004330b5     CMP        EAX,0x36
    //         004330b8     PUSH       EBX
    //         004330b9     MOV        dword ptr [ECX + this->Offset],EDX
    //         004330bc     JC         LAB_004330c5
    //                              com_sync.cpp:50 (7)
    //         004330be     MOV        dword ptr [ECX + this->Offset],0x0
    //                               LAB_004330c5                                                 XREF[1]:     004330bc(j)  
    //                              com_sync.cpp:51 (7)
    //         004330c5     MOV        EAX,dword ptr [ECX + this->Offset]
    //         004330c8     MOV        EDX,dword ptr [ESP + param_2]
    //                              com_sync.cpp:52 (4)
    //         004330cc     MOV        ESI,dword ptr [ESP + param_3]
    //                              com_sync.cpp:53 (7)
    //         004330d0     MOV        EDI,dword ptr [ESP + param_5]
    //         004330d4     LEA        EAX,[EAX + EAX*0x8]
    //                              com_sync.cpp:54 (4)
    //         004330d7     MOV        EBX,dword ptr [ESP + param_6]
    //                              com_sync.cpp:55 (48)
    //         004330db     MOV        EBP,dword ptr [ESP + param_7]
    //         004330df     MOV        dword ptr [ECX + EAX*0x4 + this+0x34],EDX
    //         004330e3     MOV        EAX,dword ptr [ECX + this->Offset]
    //         004330e6     LEA        EAX,[EAX + EAX*0x8]
    //         004330e9     MOV        dword ptr [ECX + EAX*0x4 + this+0x38],ESI
    //         004330ed     MOV        EAX,dword ptr [ECX + this->Offset]
    //         004330f0     LEA        EAX,[EAX + EAX*0x8]
    //         004330f3     MOV        dword ptr [ECX + EAX*0x4 + this+0x3c],EDI
    //         004330f7     MOV        EAX,dword ptr [ECX + this->Offset]
    //         004330fa     LEA        EAX,[EAX + EAX*0x8]
    //         004330fd     MOV        dword ptr [ECX + EAX*0x4 + this+0x40],EBX
    //         00433101     MOV        EAX,dword ptr [ECX + this->Offset]
    //         00433104     LEA        EAX,[EAX + EAX*0x8]
    //         00433107     MOV        dword ptr [ECX + EAX*0x4 + this+0x44],EBP
    //                              com_sync.cpp:56 (16)
    //         0043310b     MOV        EAX,dword ptr [ECX + this->Offset]
    //         0043310e     MOV        EBP,dword ptr [ESP + param_8]
    //         00433112     ADD        EAX,0x2
    //         00433115     LEA        EAX,[EAX + EAX*0x8]
    //         00433118     MOV        dword ptr [this->Comm + EAX*0x4],EBP
    //                              com_sync.cpp:57 (14)
    //         0043311b     MOV        EAX,dword ptr [ECX + this->Offset]
    //         0043311e     MOV        EBP,dword ptr [ESP + param_9]
    //         00433122     LEA        EAX,[EAX + EAX*0x8]
    //         00433125     MOV        dword ptr [ECX + EAX*0x4 + this+0x4c],EBP
    //                              com_sync.cpp:58 (14)
    //         00433129     MOV        EAX,dword ptr [ECX + this->Offset]
    //         0043312c     MOV        EBP,dword ptr [ESP + param_4]
    //         00433130     LEA        EAX,[EAX + EAX*0x8]
    //         00433133     MOV        dword ptr [ECX + EAX*0x4 + this+0x50],EBP
    //                              com_sync.cpp:59 (14)
    //         00433137     MOV        EAX,dword ptr [ECX + this->Offset]
    //         0043313a     LEA        EBP,[EAX + EAX*0x8]
    //         0043313d     MOV        EAX,dword ptr [ESP + param_1]
    //         00433141     MOV        dword ptr [ECX + EBP*0x4 + this->Check[0].Play
    //                              com_sync.cpp:61 (41)
    //         00433145     MOV        EBP,dword ptr [ESP + param_9]
    //         00433149     PUSH       EBP
    //         0043314a     MOV        EBP,dword ptr [ESP + param_8]
    //         0043314e     PUSH       EBP
    //         0043314f     MOV        EBP,dword ptr [ESP + param_7]
    //         00433153     PUSH       EBP
    //         00433154     PUSH       EBX
    //         00433155     PUSH       EDI
    //         00433156     MOV        EDI,dword ptr [ESP + param_4]
    //         0043315a     PUSH       EDI
    //         0043315b     PUSH       ESI
    //         0043315c     PUSH       EDX
    //         0043315d     PUSH       EAX
    //         0043315e     MOV        dword ptr [ECX + this->NewData],0x1
    //         00433165     CALL       RGE_Communications_Synchronize::ValidateChecks   int ValidateChecksums(RGE_Communications_Sync
    //         0043316a     POP        EBX
    //         0043316b     POP        EBP
    //         0043316c     POP        ESI
    //         0043316d     POP        EDI
    //                              com_sync.cpp:62 (3)
    //         0043316e     RET        0x24
    //         00433171     ??         90h
    //         00433172     NOP
    //         00433173     NOP
    //         00433174     NOP
    //         00433175     NOP
    //         00433176     NOP
    //         00433177     NOP
    //         00433178     NOP
    //         00433179     NOP
    //         0043317a     NOP
    //         0043317b     NOP
    //         0043317c     NOP
    //         0043317d     NOP
    //         0043317e     NOP
    //         0043317f     NOP
    //                              * protected: int __thiscall RGE_Communications_Synchronize::ValidateChecksums(unsigned int,unsigned ... *
    //                              int __thiscall ValidateChecksums(RGE_Communications_Synchronize * th
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[2]:     00433218(R), 0043325a(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     0043319b(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00433197(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[3]:     004331ef(R), 0043320b(R), 0043323a(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[3]:     004331c2(R), 00433207(R), 00433252(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     004331cb(R), 0043324d(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     004331d4(R), 00433248(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[2]:     004331dd(R), 00433243(R)  
    //              long              Stack[0x24]:4  param_9                   XREF[2]:     004331e6(R), 0043323e(R)  
    //                               ?ValidateChecksums@RGE_Communications_Synchronize@@IAEHIKKK  XREF[1]:     Add:00433165(c)  
    //                               RGE_Communications_Synchronize::ValidateChecksums
    //                              com_sync.cpp:74 (5)
    //         00433180     PUSH       EBX
    //         00433181     PUSH       EBP
    //         00433182     PUSH       ESI
    //         00433183     MOV        ESI,this
    //                              com_sync.cpp:76 (8)
    //         00433185     XOR        EBX,EBX
    //         00433187     PUSH       EDI
    //         00433188     CMP        dword ptr [ESI + 0x18],EBX
    //         0043318b     JNZ        LAB_00433197
    //                              com_sync.cpp:77 (3)
    //         0043318d     MOV        EAX,dword ptr [ESI + 0x1c]
    //                              com_sync.cpp:125 (38)
    //         00433190     POP        EDI
    //         00433191     POP        ESI
    //         00433192     POP        EBP
    //         00433193     POP        EBX
    //         00433194     RET        0x24
    //                               LAB_00433197                                                 XREF[1]:     0043318b(j)  
    //         00433197     MOV        EDI,dword ptr [ESP + param_3]
    //         0043319b     MOV        EDX,dword ptr [ESP + param_2]
    //         0043319f     MOV        dword ptr [ESI + 0x18],EBX
    //         004331a2     MOV        dword ptr [ESI + 0x1c],EBX
    //         004331a5     MOV        this,0x1
    //         004331aa     LEA        EAX,[ESI + 0x58]
    //                               LAB_004331ad                                                 XREF[1]:     00433205(j)  
    //         004331ad     CMP        dword ptr [EAX + 0x4],EDI
    //         004331b0     JNZ        LAB_004331bb
    //         004331b2     CMP        dword ptr [EAX],EDX
    //         004331b4     JZ         LAB_004331bf
    //                              com_sync.cpp:91 (5)
    //         004331b6     MOV        EBX,0x1
    //                               LAB_004331bb                                                 XREF[1]:     004331b0(j)  
    //                              com_sync.cpp:94 (4)
    //         004331bb     CMP        dword ptr [EAX],EDX
    //         004331bd     JNZ        LAB_004331fa
    //                               LAB_004331bf                                                 XREF[1]:     004331b4(j)  
    //                              com_sync.cpp:100 (54)
    //         004331bf     MOV        EBP,dword ptr [EAX + 0x8]
    //         004331c2     CMP        EBP,dword ptr [ESP + param_5]
    //         004331c6     JNZ        LAB_004331f5
    //         004331c8     MOV        EBP,dword ptr [EAX + 0xc]
    //         004331cb     CMP        EBP,dword ptr [ESP + param_6]
    //         004331cf     JNZ        LAB_004331f5
    //         004331d1     MOV        EBP,dword ptr [EAX + 0x10]
    //         004331d4     CMP        EBP,dword ptr [ESP + param_7]
    //         004331d8     JNZ        LAB_004331f5
    //         004331da     MOV        EBP,dword ptr [EAX + 0x14]
    //         004331dd     CMP        EBP,dword ptr [ESP + param_8]
    //         004331e1     JNZ        LAB_004331f5
    //         004331e3     MOV        EBP,dword ptr [EAX + 0x18]
    //         004331e6     CMP        EBP,dword ptr [ESP + param_9]
    //         004331ea     JNZ        LAB_004331f5
    //         004331ec     MOV        EBP,dword ptr [EAX + 0x1c]
    //         004331ef     CMP        EBP,dword ptr [ESP + param_4]
    //         004331f3     JZ         LAB_004331fa
    //                               LAB_004331f5                                                 XREF[5]:     004331c6(j), 004331cf(j), 
    //                                                                                                         004331d8(j), 004331e1(j), 
    //                                                                                                         004331ea(j)  
    //                              com_sync.cpp:101 (5)
    //         004331f5     MOV        EBX,0x1
    //                               LAB_004331fa                                                 XREF[2]:     004331bd(j), 004331f3(j)  
    //                              com_sync.cpp:103 (13)
    //         004331fa     TEST       EBX,EBX
    //         004331fc     JNZ        LAB_0043323a
    //         004331fe     INC        this
    //         004331ff     ADD        EAX,0x24
    //         00433202     CMP        this,0x36
    //         00433205     JBE        LAB_004331ad
    //                              com_sync.cpp:120 (33)
    //         00433207     MOV        EAX,dword ptr [ESP + param_5]
    //         0043320b     MOV        this,dword ptr [ESP + param_4]
    //         0043320f     PUSH       EAX
    //         00433210     MOV        EAX,[L]                                          = 00000000
    //         00433215     PUSH       this
    //         00433216     PUSH       EDI
    //         00433217     PUSH       EDX
    //         00433218     MOV        EDX,dword ptr [ESP + param_1]
    //         0043321c     PUSH       EDX
    //         0043321d     PUSH       s_P#%d_In_Sync_@_Wtime=%d_WTurn=%d               = "P#%d In Sync @ Wtime=%d WTurn=%d Wrand=%d 
    //         00433222     PUSH       EAX
    //         00433223     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_sync.cpp:123 (11)
    //         00433228     MOV        EAX,0x1
    //         0043322d     ADD        ESP,0x1c
    //         00433230     MOV        dword ptr [ESI + 0x1c],EAX
    //                              com_sync.cpp:125 (7)
    //         00433233     POP        EDI
    //         00433234     POP        ESI
    //         00433235     POP        EBP
    //         00433236     POP        EBX
    //         00433237     RET        0x24
    //                               LAB_0043323a                                                 XREF[1]:     004331fc(j)  
    //                              com_sync.cpp:105 (44)
    //         0043323a     MOV        EAX,dword ptr [ESP + param_4]
    //         0043323e     MOV        this,dword ptr [ESP + param_9]
    //         00433242     PUSH       EAX
    //         00433243     MOV        EAX,dword ptr [ESP + param_8]
    //         00433247     PUSH       this
    //         00433248     MOV        this,dword ptr [ESP + param_7]
    //         0043324c     PUSH       EAX
    //         0043324d     MOV        EAX,dword ptr [ESP + param_6]
    //         00433251     PUSH       this
    //         00433252     MOV        this,dword ptr [ESP + param_5]
    //         00433256     PUSH       EAX
    //         00433257     PUSH       this
    //         00433258     PUSH       EDI
    //         00433259     PUSH       EDX
    //         0043325a     MOV        EDX,dword ptr [ESP + param_1]
    //         0043325e     MOV        this,ESI
    //         00433260     PUSH       EDX
    //         00433261     CALL       RGE_Communications_Synchronize::LogChecksums     void LogChecksums(RGE_Communications_Synchron
    //                              com_sync.cpp:106 (13)
    //         00433266     MOV        this,dword ptr [ESI]
    //         00433268     PUSH       EDI
    //         00433269     PUSH       0x17b0
    //         0043326e     CALL       TCommunications_Handler::NotifyWindowParam       void NotifyWindowParam(TCommunications_Handle
    //                              com_sync.cpp:107 (7)
    //         00433273     MOV        dword ptr [ESI + 0x1c],0x0
    //                              com_sync.cpp:125 (9)
    //         0043327a     POP        EDI
    //         0043327b     POP        ESI
    //         0043327c     POP        EBP
    //         0043327d     XOR        EAX,EAX
    //         0043327f     POP        EBX
    //         00433280     RET        0x24
    //         00433283     ??         90h
    //         00433284     NOP
    //         00433285     NOP
    //         00433286     NOP
    //         00433287     NOP
    //         00433288     NOP
    //         00433289     NOP
    //         0043328a     NOP
    //         0043328b     NOP
    //         0043328c     NOP
    //         0043328d     NOP
    //         0043328e     NOP
    //         0043328f     NOP
}

ulong RGE_Communications_Synchronize::DoChecksum(ulong param_1) {
    /* TODO: Stub */
    //                              ulong __thiscall DoChecksum(RGE_Communications_Synchronize * this, u
    //              ulong             EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[3]:     004332cb(R), 004333d7(R), 00433415(R)  
    //              char[255]         Stack[-0x104   tmp                       XREF[4,2]:   00433300(*), 00433320(W), 004333cd(R), 004333f2(R), 
    //                                                                                     00433337(*), 0043334b(*)  
    //              long              Stack[-0x108   cs4                       XREF[4]:     0043330c(*), 00433318(W), 004333c7(R), 004333fa(R)  
    //              long              Stack[-0x10c   cs2                       XREF[4]:     00433307(*), 0043331c(W), 004333c3(R), 004333f6(R)  
    //              long              Stack[-0x110   cs3
    //                               ?DoChecksum@RGE_Communications_Synchronize@@QAEKK@Z          XREF[1]:     DoCycle:00426886(c)  
    //                               RGE_Communications_Synchronize::DoChecksum
    //                              com_sync.cpp:129 (12)
    //         00433290     SUB        ESP,0x10c
    //         00433296     PUSH       EBX
    //         00433297     PUSH       EBP
    //         00433298     PUSH       ESI
    //         00433299     MOV        ESI,this
    //         0043329b     PUSH       EDI
    //                              com_sync.cpp:131 (2)
    //         0043329c     XOR        EDI,EDI
    //                              com_sync.cpp:137 (9)
    //         0043329e     MOV        EAX,dword ptr [ESI + 0x24]
    //         004332a1     XOR        EBP,EBP
    //         004332a3     CMP        EAX,EDI
    //         004332a5     JNZ        LAB_004332b6
    //                              com_sync.cpp:138 (2)
    //         004332a7     XOR        EAX,EAX
    //                              com_sync.cpp:195 (13)
    //         004332a9     POP        EDI
    //         004332aa     POP        ESI
    //         004332ab     POP        EBP
    //         004332ac     POP        EBX
    //         004332ad     ADD        ESP,0x10c
    //         004332b3     RET        0x4
    //                               LAB_004332b6                                                 XREF[1]:     004332a5(j)  
    //                              com_sync.cpp:141 (15)
    //         004332b6     MOV        EAX,[rge_base_game]                              = 00000000
    //         004332bb     MOV        EAX,dword ptr [EAX + 0x3f4]
    //         004332c1     CMP        EAX,EDI
    //         004332c3     JZ         LAB_004332c8
    //                              com_sync.cpp:142 (3)
    //         004332c5     MOV        EBP,dword ptr [EAX + 0x4]
    //                               LAB_004332c8                                                 XREF[1]:     004332c3(j)  
    //                              com_sync.cpp:151 (14)
    //         004332c8     MOV        EAX,dword ptr [ESI + 0x8]
    //         004332cb     MOV        this,dword ptr [ESP + param_1]
    //         004332d2     CMP        this,EAX
    //         004332d4     JNC        LAB_004332e5
    //                              com_sync.cpp:152 (2)
    //         004332d6     XOR        EAX,EAX
    //                              com_sync.cpp:195 (13)
    //         004332d8     POP        EDI
    //         004332d9     POP        ESI
    //         004332da     POP        EBP
    //         004332db     POP        EBX
    //         004332dc     ADD        ESP,0x10c
    //         004332e2     RET        0x4
    //                               LAB_004332e5                                                 XREF[1]:     004332d4(j)  
    //                              com_sync.cpp:155 (18)
    //         004332e5     MOV        this,dword ptr [L]                               = 00000000
    //         004332eb     PUSH       EAX
    //         004332ec     PUSH       s_Sync_check_at_turn_#%d                         = "Sync check at turn #%d"
    //         004332f1     PUSH       this
    //         004332f2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_sync.cpp:158 (9)
    //         004332f7     MOV        this,dword ptr [ESI + 0x8]
    //         004332fa     ADD        ESP,0xc
    //         004332fd     ADD        this,0x4
    //                              com_sync.cpp:163 (41)
    //         00433300     LEA        EDX=>tmp,[ESP + 0x18]
    //         00433304     MOV        dword ptr [ESI + 0x8],this
    //         00433307     LEA        EAX=>cs2,[ESP + 0x10]
    //         0043330b     PUSH       EDX
    //         0043330c     LEA        this=>cs4,[ESP + 0x18]
    //         00433310     PUSH       EAX
    //         00433311     PUSH       this
    //         00433312     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00433318     MOV        dword ptr [ESP + cs4],EDI
    //         0043331c     MOV        dword ptr [ESP + cs2],EDI
    //         00433320     MOV        dword ptr [ESP + tmp[0]],EDI
    //         00433324     CALL       RGE_Base_Game::GetWorldChecksums                 uchar GetWorldChecksums(RGE_Base_Game * this,
    //                              com_sync.cpp:166 (5)
    //         00433329     CMP        dword ptr [ESI + 0x14],EDI
    //         0043332c     JZ         LAB_00433355
    //                              com_sync.cpp:170 (24)
    //         0043332e     MOV        EDX,dword ptr [ESI + 0x2c]
    //         00433331     MOV        EAX,dword ptr [ESI + 0x28]
    //         00433334     PUSH       EDX
    //         00433335     PUSH       EAX
    //         00433336     PUSH       EBP
    //         00433337     LEA        this=>tmp[4],[ESP + 0x28]
    //         0043333b     PUSH       s_Worldtime=%ld_Random=%d_Checksum               = "Worldtime=%ld Random=%d Checksum=%d"
    //         00433340     PUSH       this
    //         00433341     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:171 (15)
    //         00433346     MOV        this,dword ptr [ESI]
    //         00433348     ADD        ESP,0x14
    //         0043334b     LEA        EDX=>tmp[4],[ESP + 0x1c]
    //         0043334f     PUSH       EDX
    //         00433350     CALL       TCommunications_Handler::SendChatMsgAll          void SendChatMsgAll(TCommunications_Handler *
    //                               LAB_00433355                                                 XREF[1]:     0043332c(j)  
    //                              com_sync.cpp:178 (24)
    //         00433355     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043335a     MOV        this,dword ptr [EAX + 0x3f4]
    //         00433360     MOV        EDX,dword ptr [ECX + this+0x40]
    //         00433363     MOV        EAX,dword ptr [EDX]
    //         00433365     MOV        this,dword ptr [EAX + 0x38]
    //         00433368     CALL       RGE_Visible_Map::checksumUnifiedVisible          ulong checksumUnifiedVisible(RGE_Visible_Map 
    //                              com_sync.cpp:179 (28)
    //         0043336d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00433373     MOV        [DAT_0062d230],EAX
    //         00433378     MOV        EDI,0x1
    //         0043337d     MOV        EAX,dword ptr [ECX + this+0x3f4]
    //         00433383     CMP        word ptr [EAX + 0x3c],DI
    //         00433387     JLE        LAB_004333b3
    //                               LAB_00433389                                                 XREF[1]:     004333b1(j)  
    //                              com_sync.cpp:180 (42)
    //         00433389     MOV        EDX,dword ptr [EAX + 0x40]
    //         0043338c     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         0043338f     MOV        this,dword ptr [EAX + 0x38]
    //         00433392     CALL       RGE_Visible_Map::checksumVisible                 long checksumVisible(RGE_Visible_Map * this)
    //         00433397     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043339d     MOV        dword ptr [EDI*0x4 + 0x62d208]=>DAT_0062d20c,EAX
    //         004333a4     INC        EDI
    //         004333a5     MOV        EAX,dword ptr [ECX + this+0x3f4]
    //         004333ab     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         004333af     CMP        EDI,EDX
    //         004333b1     JL         LAB_00433389
    //                               LAB_004333b3                                                 XREF[1]:     00433387(j)  
    //                              com_sync.cpp:182 (6)
    //         004333b3     MOV        EDI,dword ptr [DAT_0062d230]
    //                              com_sync.cpp:183 (10)
    //         004333b9     MOV        this,pathSystem
    //         004333be     CALL       PathingSystem::checksum                          long checksum(PathingSystem * this)
    //                              com_sync.cpp:186 (47)
    //         004333c3     MOV        this,dword ptr [ESP + cs2]
    //         004333c7     MOV        EDX,dword ptr [ESP + cs4]
    //         004333cb     MOV        EBX,EAX
    //         004333cd     MOV        EAX,dword ptr [ESP + tmp[0]]
    //         004333d1     PUSH       EBX
    //         004333d2     PUSH       EAX
    //         004333d3     MOV        EAX,dword ptr [ESI + 0x28]
    //         004333d6     PUSH       this
    //         004333d7     MOV        this,dword ptr [ESP + param_1]
    //         004333de     PUSH       EDX
    //         004333df     PUSH       EDI
    //         004333e0     PUSH       EAX
    //         004333e1     PUSH       this
    //         004333e2     MOV        this,dword ptr [ESI]
    //         004333e4     PUSH       EBP
    //         004333e5     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
    //         004333ea     PUSH       EAX
    //         004333eb     MOV        this,ESI
    //         004333ed     CALL       RGE_Communications_Synchronize::Add              int Add(RGE_Communications_Synchronize * this
    //                              com_sync.cpp:188 (29)
    //         004333f2     MOV        EDX,dword ptr [ESP + tmp[0]]
    //         004333f6     MOV        EAX,dword ptr [ESP + cs2]
    //         004333fa     MOV        this,dword ptr [ESP + cs4]
    //         004333fe     PUSH       EBX
    //         004333ff     PUSH       EDX
    //         00433400     MOV        EDX,dword ptr [ESI + 0x28]
    //         00433403     PUSH       EAX
    //         00433404     PUSH       this
    //         00433405     MOV        this,dword ptr [ESI]
    //         00433407     PUSH       EDI
    //         00433408     PUSH       EDX
    //         00433409     PUSH       EBP
    //         0043340a     CALL       TCommunications_Handler::SendChecksumMessage     long SendChecksumMessage(TCommunications_Hand
    //                              com_sync.cpp:191 (33)
    //         0043340f     MOV        EAX,dword ptr [ESI + 0x2c]
    //         00433412     MOV        this,dword ptr [ESI + 0x28]
    //         00433415     MOV        EDX,dword ptr [ESP + param_1]
    //         0043341c     PUSH       EAX
    //         0043341d     MOV        EAX,[L]                                          = 00000000
    //         00433422     PUSH       this
    //         00433423     PUSH       EBP
    //         00433424     PUSH       EDX
    //         00433425     PUSH       s_Checksum:_T#%d_wt=%d___rand=%d__               = "Checksum: T#%d wt=%d   rand=%d  csum=%d"
    //         0043342a     PUSH       EAX
    //         0043342b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //                              com_sync.cpp:192 (14)
    //         00433430     MOV        this,dword ptr [L]                               = 00000000
    //         00433436     ADD        ESP,0x18
    //         00433439     CALL       TDebuggingLog::FlushLog                          void FlushLog(TDebuggingLog * this)
    //                              com_sync.cpp:195 (18)
    //         0043343e     POP        EDI
    //         0043343f     POP        ESI
    //         00433440     POP        EBP
    //         00433441     MOV        EAX,0x1
    //         00433446     POP        EBX
    //         00433447     ADD        ESP,0x10c
    //         0043344d     RET        0x4
    return 0;
}

void RGE_Communications_Synchronize::SetLastWorldRandom(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetLastWorldRandom(RGE_Communications_Synchronize * 
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     00433450(R)  
    //                               ?SetLastWorldRandom@RGE_Communications_Synchronize@@QAEXK@Z  XREF[1]:     LastWorldRandom:0042663b(c)  
    //                               RGE_Communications_Synchronize::SetLastWorldRandom
    //                              com_sync.cpp:200 (7)
    //         00433450     MOV        EAX,dword ptr [ESP + param_1]
    //         00433454     MOV        dword ptr [ECX + this->LastWorldRandom],EAX
    //                              com_sync.cpp:202 (3)
    //         00433457     RET        0x4
    //         0043345a     ??         90h
    //         0043345b     NOP
    //         0043345c     NOP
    //         0043345d     NOP
    //         0043345e     NOP
    //         0043345f     NOP
    //                              * public: void __thiscall RGE_Communications_Synchronize::LogChecksums(unsigned int,unsigned long,un... *
    //                              void __thiscall LogChecksums(RGE_Communications_Synchronize * this, 
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004334c1(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00433497(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[2]:     004334b9(R), 004335cb(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[2]:     004334b1(R), 0043367e(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[2]:     004334a9(R), 004336d1(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     0043348d(R), 00433725(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     00433486(R), 00433779(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[2]:     004334a0(R), 004337cc(R)  
    //              ulong             Stack[0x24]:4  param_9                   XREF[1]:     0043347f(R)  
    //              char[513]         Stack[-0x208   TBuff                     XREF[3,48]:  00433476(W), 00433896(R), 00433910(R), 004334cc(*), 
    //                                                                                     004334e3(*), 004334f5(*), 00433511(*), 00433529(*), 
    //                                                                                     0043353b(*), 00433585(*), 0043359d(*), 004335af(*), 
    //                                                                                     004335e2(*), 004335f9(*), 0043360b(*), 00433638(*), 
    //                                                                                     00433650(*), 00433662(*), 0043368c(*), 004336a3(*)  
    //              undefined4        Stack[-0x20c   local_20c                 XREF[7]:     0043355a(W), 00433820(R), 00433828(W), 0043388e(W), 
    //                                                                                     004339b7(R), 00433a04(R), 00433a11(W)  
    //                               ?LogChecksums@RGE_Communications_Synchronize@@QAEXIKKJJJJJK@Z XREF[2]:     EvaluatePlayerMessage:004284e6(c), 
    //                               RGE_Communications_Synchronize::LogChecksums                              ValidateChecksums:00433261(c)  
    //                              com_sync.cpp:207 (12)
    //         00433460     SUB        ESP,0x20c
    //         00433466     PUSH       EBX
    //         00433467     PUSH       EBP
    //         00433468     PUSH       ESI
    //         00433469     PUSH       EDI
    //         0043346a     MOV        ESI,this
    //                              com_sync.cpp:213 (19)
    //         0043346c     PUSH       s_wt                                             = "wt"
    //         00433471     PUSH       s_C:\aoesync.txt                                 = "C:\\aoesync.txt"
    //         00433476     MOV        dword ptr [ESP + TBuff[0]],ESI
    //         0043347a     CALL       fopen                                            undefined fopen()
    //                              com_sync.cpp:216 (92)
    //         0043347f     MOV        EBP,dword ptr [ESP + param_9]
    //         00433486     MOV        this,dword ptr [ESP + param_7]
    //         0043348d     MOV        EDX,dword ptr [ESP + param_6]
    //         00433494     ADD        ESP,0x8
    //         00433497     MOV        EDI,dword ptr [ESP + param_2]
    //         0043349e     MOV        EBX,EAX
    //         004334a0     MOV        EAX,dword ptr [ESP + param_8]
    //         004334a7     PUSH       EBP
    //         004334a8     PUSH       EAX
    //         004334a9     MOV        EAX,dword ptr [ESP + param_5]
    //         004334b0     PUSH       this
    //         004334b1     MOV        this,dword ptr [ESP + param_4]
    //         004334b8     PUSH       EDX
    //         004334b9     MOV        EDX,dword ptr [ESP + param_3]
    //         004334c0     PUSH       EAX
    //         004334c1     MOV        EAX,dword ptr [ESP + param_1]
    //         004334c8     PUSH       this
    //         004334c9     PUSH       EDX
    //         004334ca     PUSH       EDI
    //         004334cb     PUSH       EAX
    //         004334cc     LEA        this=>TBuff[4],[ESP + 0x3c]
    //         004334d0     PUSH       s_Adding:__P#%d__WTime=%d__Turn=%d               = "Adding:  P#%d  WTime=%d  Turn=%d Cs1=%d  C
    //         004334d5     PUSH       this
    //         004334d6     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:217 (54)
    //         004334db     MOV        EAX,[L]                                          = 00000000
    //         004334e0     ADD        ESP,0x2c
    //         004334e3     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         004334e7     PUSH       EDX
    //         004334e8     PUSH       EAX
    //         004334e9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004334ee     ADD        ESP,0x8
    //         004334f1     TEST       EBX,EBX
    //         004334f3     JZ         LAB_00433511
    //         004334f5     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004334f9     PUSH       EBX
    //         004334fa     PUSH       this
    //         004334fb     CALL       fputs                                            undefined fputs()
    //         00433500     ADD        ESP,0x8
    //         00433503     PUSH       EBX
    //         00433504     PUSH       s__                                              = 0Ah
    //         00433509     CALL       fputs                                            undefined fputs()
    //         0043350e     ADD        ESP,0x8
    //                               LAB_00433511                                                 XREF[1]:     004334f3(j)  
    //                              com_sync.cpp:219 (15)
    //         00433511     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         00433515     PUSH       s_Plr:_Wrldtime_CommTurn_Random_WC               = "Plr: Wrldtime CommTurn Random WChecksum Ck
    //         0043351a     PUSH       EDX
    //         0043351b     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:220 (55)
    //         00433520     MOV        this,dword ptr [L]                               = 00000000
    //         00433526     ADD        ESP,0x8
    //         00433529     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         0043352d     PUSH       EAX
    //         0043352e     PUSH       this
    //         0043352f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433534     ADD        ESP,0x8
    //         00433537     TEST       EBX,EBX
    //         00433539     JZ         LAB_00433557
    //         0043353b     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         0043353f     PUSH       EBX
    //         00433540     PUSH       EDX
    //         00433541     CALL       fputs                                            undefined fputs()
    //         00433546     ADD        ESP,0x8
    //         00433549     PUSH       EBX
    //         0043354a     PUSH       s__                                              = 0Ah
    //         0043354f     CALL       fputs                                            undefined fputs()
    //         00433554     ADD        ESP,0x8
    //                               LAB_00433557                                                 XREF[1]:     00433539(j)  
    //                              com_sync.cpp:222 (11)
    //         00433557     ADD        ESI,0x58
    //         0043355a     MOV        dword ptr [ESP + local_20c],0x35
    //                               LAB_00433562                                                 XREF[1]:     0043382c(j)  
    //                              com_sync.cpp:233 (50)
    //         00433562     MOV        EAX,dword ptr [ESI + 0x18]
    //         00433565     MOV        this,dword ptr [ESI + 0x14]
    //         00433568     MOV        EDX,dword ptr [ESI + 0x10]
    //         0043356b     PUSH       EAX
    //         0043356c     MOV        EAX,dword ptr [ESI + 0xc]
    //         0043356f     PUSH       this
    //         00433570     MOV        this,dword ptr [ESI + 0x8]
    //         00433573     PUSH       EDX
    //         00433574     MOV        EDX,dword ptr [ESI + 0x1c]
    //         00433577     PUSH       EAX
    //         00433578     MOV        EAX,dword ptr [ESI + 0x4]
    //         0043357b     PUSH       this
    //         0043357c     MOV        this,dword ptr [ESI]
    //         0043357e     PUSH       EDX
    //         0043357f     MOV        EDX,dword ptr [ESI + -0x4]
    //         00433582     PUSH       EAX
    //         00433583     PUSH       this
    //         00433584     PUSH       EDX
    //         00433585     LEA        EAX=>TBuff[4],[ESP + 0x3c]
    //         00433589     PUSH       s__%.2d:_%.8d_%.8d_%.6d_%.8d_%.8d_               = " %.2d: %.8d %.8d %.6d %.8d %.8d %.8d %.8d 
    //         0043358e     PUSH       EAX
    //         0043358f     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:235 (55)
    //         00433594     MOV        EDX,dword ptr [L]                                = 00000000
    //         0043359a     ADD        ESP,0x2c
    //         0043359d     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004335a1     PUSH       this
    //         004335a2     PUSH       EDX
    //         004335a3     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004335a8     ADD        ESP,0x8
    //         004335ab     TEST       EBX,EBX
    //         004335ad     JZ         LAB_004335cb
    //         004335af     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         004335b3     PUSH       EBX
    //         004335b4     PUSH       EAX
    //         004335b5     CALL       fputs                                            undefined fputs()
    //         004335ba     ADD        ESP,0x8
    //         004335bd     PUSH       EBX
    //         004335be     PUSH       s__                                              = 0Ah
    //         004335c3     CALL       fputs                                            undefined fputs()
    //         004335c8     ADD        ESP,0x8
    //                               LAB_004335cb                                                 XREF[1]:     004335ad(j)  
    //                              com_sync.cpp:238 (20)
    //         004335cb     MOV        this,dword ptr [ESP + param_3]
    //         004335d2     MOV        EAX,dword ptr [ESI + 0x4]
    //         004335d5     CMP        EAX,this
    //         004335d7     JNZ        LAB_00433627
    //         004335d9     MOV        EAX,dword ptr [ESI]
    //         004335db     CMP        EAX,EDI
    //         004335dd     JZ         LAB_00433627
    //                              com_sync.cpp:243 (18)
    //         004335df     PUSH       this
    //         004335e0     PUSH       EAX
    //         004335e1     PUSH       EDI
    //         004335e2     LEA        this=>TBuff[4],[ESP + 0x24]
    //         004335e6     PUSH       s_=====>__WORLD_TIME_IS_OUT_OF_SYN               = "=====>  WORLD TIME IS OUT OF SYNC  (%d sho
    //         004335eb     PUSH       this
    //         004335ec     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:244 (54)
    //         004335f1     MOV        EAX,[L]                                          = 00000000
    //         004335f6     ADD        ESP,0x14
    //         004335f9     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         004335fd     PUSH       EDX
    //         004335fe     PUSH       EAX
    //         004335ff     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433604     ADD        ESP,0x8
    //         00433607     TEST       EBX,EBX
    //         00433609     JZ         LAB_00433627
    //         0043360b     LEA        this=>TBuff[4],[ESP + 0x18]
    //         0043360f     PUSH       EBX
    //         00433610     PUSH       this
    //         00433611     CALL       fputs                                            undefined fputs()
    //         00433616     ADD        ESP,0x8
    //         00433619     PUSH       EBX
    //         0043361a     PUSH       s__                                              = 0Ah
    //         0043361f     CALL       fputs                                            undefined fputs()
    //         00433624     ADD        ESP,0x8
    //                               LAB_00433627                                                 XREF[3]:     004335d7(j), 004335dd(j), 
    //                                                                                                         00433609(j)  
    //                              com_sync.cpp:247 (8)
    //         00433627     CMP        dword ptr [ESI],EDI
    //         00433629     JNZ        LAB_00433820
    //                              com_sync.cpp:249 (7)
    //         0043362f     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00433632     CMP        EAX,EBP
    //         00433634     JZ         LAB_0043367e
    //                              com_sync.cpp:253 (17)
    //         00433636     PUSH       EAX
    //         00433637     PUSH       EBP
    //         00433638     LEA        EDX=>TBuff[4],[ESP + 0x20]
    //         0043363c     PUSH       s_=====>__MISMATCHED_RANDOM_(_%d_s               = "=====>  MISMATCHED RANDOM ( %d should be %
    //         00433641     PUSH       EDX
    //         00433642     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:254 (55)
    //         00433647     MOV        this,dword ptr [L]                               = 00000000
    //         0043364d     ADD        ESP,0x10
    //         00433650     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         00433654     PUSH       EAX
    //         00433655     PUSH       this
    //         00433656     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         0043365b     ADD        ESP,0x8
    //         0043365e     TEST       EBX,EBX
    //         00433660     JZ         LAB_0043367e
    //         00433662     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         00433666     PUSH       EBX
    //         00433667     PUSH       EDX
    //         00433668     CALL       fputs                                            undefined fputs()
    //         0043366d     ADD        ESP,0x8
    //         00433670     PUSH       EBX
    //         00433671     PUSH       s__                                              = 0Ah
    //         00433676     CALL       fputs                                            undefined fputs()
    //         0043367b     ADD        ESP,0x8
    //                               LAB_0043367e                                                 XREF[2]:     00433634(j), 00433660(j)  
    //                              com_sync.cpp:257 (14)
    //         0043367e     MOV        EAX,dword ptr [ESP + param_4]
    //         00433685     MOV        this,dword ptr [ESI + 0x8]
    //         00433688     CMP        this,EAX
    //         0043368a     JZ         LAB_004336d1
    //                              com_sync.cpp:259 (15)
    //         0043368c     LEA        this=>TBuff[4],[ESP + 0x18]
    //         00433690     PUSH       s_=====>__MISMATCHED_Unified_Visib               = "=====>  MISMATCHED Unified Visible Map"
    //         00433695     PUSH       this
    //         00433696     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:260 (54)
    //         0043369b     MOV        EAX,[L]                                          = 00000000
    //         004336a0     ADD        ESP,0x8
    //         004336a3     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         004336a7     PUSH       EDX
    //         004336a8     PUSH       EAX
    //         004336a9     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004336ae     ADD        ESP,0x8
    //         004336b1     TEST       EBX,EBX
    //         004336b3     JZ         LAB_004336d1
    //         004336b5     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004336b9     PUSH       EBX
    //         004336ba     PUSH       this
    //         004336bb     CALL       fputs                                            undefined fputs()
    //         004336c0     ADD        ESP,0x8
    //         004336c3     PUSH       EBX
    //         004336c4     PUSH       s__                                              = 0Ah
    //         004336c9     CALL       fputs                                            undefined fputs()
    //         004336ce     ADD        ESP,0x8
    //                               LAB_004336d1                                                 XREF[2]:     0043368a(j), 004336b3(j)  
    //                              com_sync.cpp:263 (14)
    //         004336d1     MOV        EDX,dword ptr [ESP + param_5]
    //         004336d8     MOV        EAX,dword ptr [ESI + 0xc]
    //         004336db     CMP        EAX,EDX
    //         004336dd     JZ         LAB_00433725
    //                              com_sync.cpp:265 (15)
    //         004336df     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         004336e3     PUSH       s_=====>__MISMATCHED_CHECKSUM...Ne               = "=====>  MISMATCHED CHECKSUM...New"
    //         004336e8     PUSH       EAX
    //         004336e9     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:266 (55)
    //         004336ee     MOV        EDX,dword ptr [L]                                = 00000000
    //         004336f4     ADD        ESP,0x8
    //         004336f7     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004336fb     PUSH       this
    //         004336fc     PUSH       EDX
    //         004336fd     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433702     ADD        ESP,0x8
    //         00433705     TEST       EBX,EBX
    //         00433707     JZ         LAB_00433725
    //         00433709     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         0043370d     PUSH       EBX
    //         0043370e     PUSH       EAX
    //         0043370f     CALL       fputs                                            undefined fputs()
    //         00433714     ADD        ESP,0x8
    //         00433717     PUSH       EBX
    //         00433718     PUSH       s__                                              = 0Ah
    //         0043371d     CALL       fputs                                            undefined fputs()
    //         00433722     ADD        ESP,0x8
    //                               LAB_00433725                                                 XREF[2]:     004336dd(j), 00433707(j)  
    //                              com_sync.cpp:269 (14)
    //         00433725     MOV        this,dword ptr [ESP + param_6]
    //         0043372c     MOV        EAX,dword ptr [ESI + 0x10]
    //         0043372f     CMP        EAX,this
    //         00433731     JZ         LAB_00433779
    //                              com_sync.cpp:271 (15)
    //         00433733     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         00433737     PUSH       s_=====>__MISMATCHED..Position                   = "=====>  MISMATCHED..Position"
    //         0043373c     PUSH       EDX
    //         0043373d     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:272 (55)
    //         00433742     MOV        this,dword ptr [L]                               = 00000000
    //         00433748     ADD        ESP,0x8
    //         0043374b     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         0043374f     PUSH       EAX
    //         00433750     PUSH       this
    //         00433751     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433756     ADD        ESP,0x8
    //         00433759     TEST       EBX,EBX
    //         0043375b     JZ         LAB_00433779
    //         0043375d     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         00433761     PUSH       EBX
    //         00433762     PUSH       EDX
    //         00433763     CALL       fputs                                            undefined fputs()
    //         00433768     ADD        ESP,0x8
    //         0043376b     PUSH       EBX
    //         0043376c     PUSH       s__                                              = 0Ah
    //         00433771     CALL       fputs                                            undefined fputs()
    //         00433776     ADD        ESP,0x8
    //                               LAB_00433779                                                 XREF[2]:     00433731(j), 0043375b(j)  
    //                              com_sync.cpp:275 (14)
    //         00433779     MOV        EAX,dword ptr [ESP + param_7]
    //         00433780     MOV        this,dword ptr [ESI + 0x14]
    //         00433783     CMP        this,EAX
    //         00433785     JZ         LAB_004337cc
    //                              com_sync.cpp:277 (15)
    //         00433787     LEA        this=>TBuff[4],[ESP + 0x18]
    //         0043378b     PUSH       s_=====>__MISMATCHED...Action                    = "=====>  MISMATCHED...Action"
    //         00433790     PUSH       this
    //         00433791     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:278 (54)
    //         00433796     MOV        EAX,[L]                                          = 00000000
    //         0043379b     ADD        ESP,0x8
    //         0043379e     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         004337a2     PUSH       EDX
    //         004337a3     PUSH       EAX
    //         004337a4     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004337a9     ADD        ESP,0x8
    //         004337ac     TEST       EBX,EBX
    //         004337ae     JZ         LAB_004337cc
    //         004337b0     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004337b4     PUSH       EBX
    //         004337b5     PUSH       this
    //         004337b6     CALL       fputs                                            undefined fputs()
    //         004337bb     ADD        ESP,0x8
    //         004337be     PUSH       EBX
    //         004337bf     PUSH       s__                                              = 0Ah
    //         004337c4     CALL       fputs                                            undefined fputs()
    //         004337c9     ADD        ESP,0x8
    //                               LAB_004337cc                                                 XREF[2]:     00433785(j), 004337ae(j)  
    //                              com_sync.cpp:281 (14)
    //         004337cc     MOV        EDX,dword ptr [ESP + param_8]
    //         004337d3     MOV        EAX,dword ptr [ESI + 0x18]
    //         004337d6     CMP        EAX,EDX
    //         004337d8     JZ         LAB_00433820
    //                              com_sync.cpp:283 (15)
    //         004337da     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         004337de     PUSH       s_=====>__MISMATCHED...Obstruction               = "=====>  MISMATCHED...ObstructionMap Checks
    //         004337e3     PUSH       EAX
    //         004337e4     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:284 (73)
    //         004337e9     MOV        EDX,dword ptr [L]                                = 00000000
    //         004337ef     ADD        ESP,0x8
    //         004337f2     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004337f6     PUSH       this
    //         004337f7     PUSH       EDX
    //         004337f8     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004337fd     ADD        ESP,0x8
    //         00433800     TEST       EBX,EBX
    //         00433802     JZ         LAB_00433820
    //         00433804     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         00433808     PUSH       EBX
    //         00433809     PUSH       EAX
    //         0043380a     CALL       fputs                                            undefined fputs()
    //         0043380f     ADD        ESP,0x8
    //         00433812     PUSH       EBX
    //         00433813     PUSH       s__                                              = 0Ah
    //         00433818     CALL       fputs                                            undefined fputs()
    //         0043381d     ADD        ESP,0x8
    //                               LAB_00433820                                                 XREF[3]:     00433629(j), 004337d8(j), 
    //                                                                                                         00433802(j)  
    //         00433820     MOV        EAX,dword ptr [ESP + local_20c]
    //         00433824     ADD        ESI,0x24
    //         00433827     DEC        EAX
    //         00433828     MOV        dword ptr [ESP + local_20c],EAX
    //         0043382c     JNZ        LAB_00433562
    //                              com_sync.cpp:293 (26)
    //         00433832     MOV        EDI,s_Player_Checksum_information:               = 50h
    //         00433837     OR         this,0xffffffff
    //         0043383a     XOR        EAX,EAX
    //         0043383c     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         00433840     SCASB.RE   ES:EDI=>s_Player_Checksum_information:           = 50h
    //                                                                                  = "layer Checksum information:"
    //         00433842     NOT        this
    //         00433844     SUB        EDI,this
    //         00433846     MOV        EAX,this
    //         00433848     MOV        ESI,EDI
    //         0043384a     MOV        EDI,EDX
    //                              com_sync.cpp:294 (64)
    //         0043384c     MOV        EDX,dword ptr [L]                                = 00000000
    //         00433852     SHR        this,0x2
    //         00433855     MOVSD.REP  ES:EDI,ESI
    //         00433857     MOV        this,EAX
    //         00433859     AND        this,0x3
    //         0043385c     MOVSB.REP  ES:EDI,ESI
    //         0043385e     LEA        this=>TBuff[4],[ESP + 0x18]
    //         00433862     PUSH       this
    //         00433863     PUSH       EDX
    //         00433864     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433869     ADD        ESP,0x8
    //         0043386c     TEST       EBX,EBX
    //         0043386e     JZ         LAB_0043388c
    //         00433870     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         00433874     PUSH       EBX
    //         00433875     PUSH       EAX
    //         00433876     CALL       fputs                                            undefined fputs()
    //         0043387b     ADD        ESP,0x8
    //         0043387e     PUSH       EBX
    //         0043387f     PUSH       s__                                              = 0Ah
    //         00433884     CALL       fputs                                            undefined fputs()
    //         00433889     ADD        ESP,0x8
    //                               LAB_0043388c                                                 XREF[1]:     0043386e(j)  
    //                              com_sync.cpp:296 (10)
    //         0043388c     XOR        EBP,EBP
    //         0043388e     MOV        dword ptr [ESP + local_20c],DAT_0062d208
    //                               LAB_00433896                                                 XREF[1]:     00433a15(j)  
    //                              com_sync.cpp:298 (32)
    //         00433896     MOV        ESI,dword ptr [ESP + TBuff[0]]
    //         0043389a     PUSH       EBP
    //         0043389b     MOV        this,dword ptr [ESI]
    //         0043389d     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
    //         004338a2     TEST       EAX,EAX
    //         004338a4     JNZ        LAB_004338b6
    //         004338a6     MOV        this,dword ptr [ESI]
    //         004338a8     PUSH       EBP
    //         004338a9     CALL       TCommunications_Handler::IsPlayerComputer        int IsPlayerComputer(TCommunications_Handler 
    //         004338ae     TEST       EAX,EAX
    //         004338b0     JZ         LAB_00433a04
    //                               LAB_004338b6                                                 XREF[1]:     004338a4(j)  
    //                              com_sync.cpp:300 (26)
    //         004338b6     MOV        EDI,s___                                         = 0A20h
    //         004338bb     OR         this,0xffffffff
    //         004338be     XOR        EAX,EAX
    //         004338c0     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         004338c4     SCASB.RE   ES:EDI=>s___                                     = 0A20h
    //         004338c6     NOT        this
    //         004338c8     SUB        EDI,this
    //         004338ca     MOV        EAX,this
    //         004338cc     MOV        ESI,EDI
    //         004338ce     MOV        EDI,EDX
    //                              com_sync.cpp:301 (64)
    //         004338d0     MOV        EDX,dword ptr [L]                                = 00000000
    //         004338d6     SHR        this,0x2
    //         004338d9     MOVSD.REP  ES:EDI,ESI
    //         004338db     MOV        this,EAX
    //         004338dd     AND        this,0x3
    //         004338e0     MOVSB.REP  ES:EDI,ESI
    //         004338e2     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004338e6     PUSH       this
    //         004338e7     PUSH       EDX
    //         004338e8     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004338ed     ADD        ESP,0x8
    //         004338f0     TEST       EBX,EBX
    //         004338f2     JZ         LAB_00433910
    //         004338f4     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         004338f8     PUSH       EBX
    //         004338f9     PUSH       EAX
    //         004338fa     CALL       fputs                                            undefined fputs()
    //         004338ff     ADD        ESP,0x8
    //         00433902     PUSH       EBX
    //         00433903     PUSH       s__                                              = 0Ah
    //         00433908     CALL       fputs                                            undefined fputs()
    //         0043390d     ADD        ESP,0x8
    //                               LAB_00433910                                                 XREF[1]:     004338f2(j)  
    //                              com_sync.cpp:303 (28)
    //         00433910     MOV        this,dword ptr [ESP + TBuff[0]]
    //         00433914     PUSH       EBP
    //         00433915     MOV        this,dword ptr [this->Comm]
    //         00433917     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler 
    //         0043391c     PUSH       EAX
    //         0043391d     LEA        EDX=>TBuff[4],[ESP + 0x1c]
    //         00433921     PUSH       s_PLAYER:_%s                                     = "PLAYER: %s"
    //         00433926     PUSH       EDX
    //         00433927     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:304 (55)
    //         0043392c     MOV        this,dword ptr [L]                               = 00000000
    //         00433932     ADD        ESP,0xc
    //         00433935     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         00433939     PUSH       EAX
    //         0043393a     PUSH       this
    //         0043393b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433940     ADD        ESP,0x8
    //         00433943     TEST       EBX,EBX
    //         00433945     JZ         LAB_00433963
    //         00433947     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         0043394b     PUSH       EBX
    //         0043394c     PUSH       EDX
    //         0043394d     CALL       fputs                                            undefined fputs()
    //         00433952     ADD        ESP,0x8
    //         00433955     PUSH       EBX
    //         00433956     PUSH       s__                                              = 0Ah
    //         0043395b     CALL       fputs                                            undefined fputs()
    //         00433960     ADD        ESP,0x8
    //                               LAB_00433963                                                 XREF[1]:     00433945(j)  
    //                              com_sync.cpp:306 (29)
    //         00433963     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00433969     PUSH       EBP
    //         0043396a     CALL       RGE_Base_Game::GetChecksum                       long GetChecksum(RGE_Base_Game * this, long p
    //         0043396f     PUSH       EAX
    //         00433970     PUSH       EBP
    //         00433971     LEA        EAX=>TBuff[4],[ESP + 0x20]
    //         00433975     PUSH       s_P#%d_CSum=%d_                                  = "P#%d CSum=%d "
    //         0043397a     PUSH       EAX
    //         0043397b     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:307 (55)
    //         00433980     MOV        EDX,dword ptr [L]                                = 00000000
    //         00433986     ADD        ESP,0x10
    //         00433989     LEA        this=>TBuff[4],[ESP + 0x18]
    //         0043398d     PUSH       this
    //         0043398e     PUSH       EDX
    //         0043398f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433994     ADD        ESP,0x8
    //         00433997     TEST       EBX,EBX
    //         00433999     JZ         LAB_004339b7
    //         0043399b     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         0043399f     PUSH       EBX
    //         004339a0     PUSH       EAX
    //         004339a1     CALL       fputs                                            undefined fputs()
    //         004339a6     ADD        ESP,0x8
    //         004339a9     PUSH       EBX
    //         004339aa     PUSH       s__                                              = 0Ah
    //         004339af     CALL       fputs                                            undefined fputs()
    //         004339b4     ADD        ESP,0x8
    //                               LAB_004339b7                                                 XREF[1]:     00433999(j)  
    //                              com_sync.cpp:310 (22)
    //         004339b7     MOV        this,dword ptr [ESP + local_20c]
    //         004339bb     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         004339bf     MOV        EDX,dword ptr [this->Comm]=>DAT_0062d208
    //         004339c1     PUSH       EDX
    //         004339c2     PUSH       s_VISIBLE_Checksum_=_%d                          = "VISIBLE Checksum = %d"
    //         004339c7     PUSH       EAX
    //         004339c8     CALL       sprintf                                          undefined sprintf()
    //                              com_sync.cpp:311 (78)
    //         004339cd     MOV        EDX,dword ptr [L]                                = 00000000
    //         004339d3     ADD        ESP,0xc
    //         004339d6     LEA        this=>TBuff[4],[ESP + 0x18]
    //         004339da     PUSH       this
    //         004339db     PUSH       EDX
    //         004339dc     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         004339e1     ADD        ESP,0x8
    //         004339e4     TEST       EBX,EBX
    //         004339e6     JZ         LAB_00433a04
    //         004339e8     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         004339ec     PUSH       EBX
    //         004339ed     PUSH       EAX
    //         004339ee     CALL       fputs                                            undefined fputs()
    //         004339f3     ADD        ESP,0x8
    //         004339f6     PUSH       EBX
    //         004339f7     PUSH       s__                                              = 0Ah
    //         004339fc     CALL       fputs                                            undefined fputs()
    //         00433a01     ADD        ESP,0x8
    //                               LAB_00433a04                                                 XREF[2]:     004338b0(j), 004339e6(j)  
    //         00433a04     MOV        EAX,dword ptr [ESP + local_20c]
    //         00433a08     INC        EBP
    //         00433a09     ADD        EAX,0x4
    //         00433a0c     CMP        EAX,null_0062d22c                                = align(4)
    //         00433a11     MOV        dword ptr [ESP + local_20c],EAX=>DAT_0062d20c
    //         00433a15     JC         LAB_00433896
    //                              com_sync.cpp:318 (26)
    //         00433a1b     MOV        EDI,s_...end_of_log                              = 2Eh
    //         00433a20     OR         this,0xffffffff
    //         00433a23     XOR        EAX,EAX
    //         00433a25     LEA        EDX=>TBuff[4],[ESP + 0x18]
    //         00433a29     SCASB.RE   ES:EDI=>s_...end_of_log                          = 2Eh
    //                                                                                  = "..end of log"
    //         00433a2b     NOT        this
    //         00433a2d     SUB        EDI,this
    //         00433a2f     MOV        EAX,this
    //         00433a31     MOV        ESI,EDI
    //         00433a33     MOV        EDI,EDX
    //                              com_sync.cpp:319 (64)
    //         00433a35     MOV        EDX,dword ptr [L]                                = 00000000
    //         00433a3b     SHR        this,0x2
    //         00433a3e     MOVSD.REP  ES:EDI,ESI
    //         00433a40     MOV        this,EAX
    //         00433a42     AND        this,0x3
    //         00433a45     MOVSB.REP  ES:EDI,ESI
    //         00433a47     LEA        this=>TBuff[4],[ESP + 0x18]
    //         00433a4b     PUSH       this
    //         00433a4c     PUSH       EDX
    //         00433a4d     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433a52     ADD        ESP,0x8
    //         00433a55     TEST       EBX,EBX
    //         00433a57     JZ         LAB_00433a75
    //         00433a59     LEA        EAX=>TBuff[4],[ESP + 0x18]
    //         00433a5d     PUSH       EBX
    //         00433a5e     PUSH       EAX
    //         00433a5f     CALL       fputs                                            undefined fputs()
    //         00433a64     ADD        ESP,0x8
    //         00433a67     PUSH       EBX
    //         00433a68     PUSH       s__                                              = 0Ah
    //         00433a6d     CALL       fputs                                            undefined fputs()
    //         00433a72     ADD        ESP,0x8
    //                               LAB_00433a75                                                 XREF[1]:     00433a57(j)  
    //                              com_sync.cpp:321 (9)
    //         00433a75     PUSH       EBX
    //         00433a76     CALL       fclose                                           undefined fclose()
    //         00433a7b     ADD        ESP,0x4
    //                              com_sync.cpp:322 (13)
    //         00433a7e     POP        EDI
    //         00433a7f     POP        ESI
    //         00433a80     POP        EBP
    //         00433a81     POP        EBX
    //         00433a82     ADD        ESP,0x20c
    //         00433a88     RET        0x24
    //         00433a8b     ??         90h
    //         00433a8c     NOP
    //         00433a8d     NOP
    //         00433a8e     NOP
    //         00433a8f     NOP
    return;
}

void RGE_Communications_Synchronize::EnableSyncChecking(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall EnableSyncChecking(RGE_Communications_Synchronize * 
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00433a90(R)  
    //                               ?EnableSyncChecking@RGE_Communications_Synchronize@@QAEXH@Z
    //                               RGE_Communications_Synchronize::EnableSyncChecking
    //                              com_sync.cpp:325 (7)
    //         00433a90     MOV        EAX,dword ptr [ESP + param_1]
    //         00433a94     MOV        dword ptr [ECX + this->DoChecksums],EAX
    //                              com_sync.cpp:327 (3)
    //         00433a97     RET        0x4
    //         00433a9a     ??         90h
    //         00433a9b     NOP
    //         00433a9c     NOP
    //         00433a9d     NOP
    //         00433a9e     NOP
    //         00433a9f     NOP
    return;
}

void RGE_Communications_Synchronize::SetStopOnFail(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetStopOnFail(RGE_Communications_Synchronize * this,
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00433aa0(R)  
    //                               ?SetStopOnFail@RGE_Communications_Synchronize@@QAEXH@Z       XREF[1]:     StopIfSyncFail:004258fb(c)  
    //                               RGE_Communications_Synchronize::SetStopOnFail
    //                              com_sync.cpp:330 (7)
    //         00433aa0     MOV        EAX,dword ptr [ESP + param_1]
    //         00433aa4     MOV        dword ptr [ECX + this->StopOnSyncFail],EAX
    //                              com_sync.cpp:332 (3)
    //         00433aa7     RET        0x4
    //         00433aaa     ??         90h
    //         00433aab     NOP
    //         00433aac     NOP
    //         00433aad     NOP
    //         00433aae     NOP
    //         00433aaf     NOP
    return;
}

void RGE_Communications_Synchronize::SetDialogOnFail(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SetDialogOnFail(RGE_Communications_Synchronize * thi
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00433ab0(R)  
    //                               ?SetDialogOnFail@RGE_Communications_Synchronize@@QAEXH@Z     XREF[1]:     StopIfSyncFail:004258ef(c)  
    //                               RGE_Communications_Synchronize::SetDialogOnFail
    //                              com_sync.cpp:335 (7)
    //         00433ab0     MOV        EAX,dword ptr [ESP + param_1]
    //         00433ab4     MOV        dword ptr [ECX + this->DialogOnSyncFail],EAX
    //                              com_sync.cpp:337 (3)
    //         00433ab7     RET        0x4
    //         00433aba     ??         90h
    //         00433abb     NOP
    //         00433abc     NOP
    //         00433abd     NOP
    //         00433abe     NOP
    //         00433abf     NOP
    return;
}

void RGE_Communications_Synchronize::SendChatMsgsAtChecksum(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall SendChatMsgsAtChecksum(RGE_Communications_Synchroniz
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00433ac0(R)  
    //                               ?SendChatMsgsAtChecksum@RGE_Communications_Synchronize@@QAE  XREF[1]:     ShowSyncChatMsgs:0042591b(c)  
    //                               RGE_Communications_Synchronize::SendChatMsgsAtChecksum
    //                              com_sync.cpp:340 (7)
    //         00433ac0     MOV        EAX,dword ptr [ESP + param_1]
    //         00433ac4     MOV        dword ptr [ECX + this->SendChatMsgs],EAX
    //                              com_sync.cpp:342 (3)
    //         00433ac7     RET        0x4
    //         00433aca     ??         90h
    //         00433acb     NOP
    //         00433acc     NOP
    //         00433acd     NOP
    //         00433ace     NOP
    //         00433acf     NOP
    return;
}

int RGE_Communications_Synchronize::IsPlayerOutOfSync(uint param_1, ulong param_2) {
    /* TODO: Stub */
    //                              int __thiscall IsPlayerOutOfSync(RGE_Communications_Synchronize * th
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[2]:     00433b0f(R), 00433bbf(R)  
    //              ulong             Stack[0x8]:4   param_2                   XREF[2]:     00433b18(R), 00433bce(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00433ade(W), 00433c86(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00433b00(W), 00433b65(W), 00433c12(R)  
    //              uint              Stack[-0xc]:4  myRandom                  XREF[3]:     00433aea(W), 00433b31(W), 00433b69(R)  
    //              int               Stack[-0x10]:4 foundMine                 XREF[3]:     00433b04(W), 00433c97(RW), 00433ca9(R)  
    //              int               Stack[-0x14]:4 NumPlayers                XREF[4]:     00433ae2(W), 00433c44(R), 00433c4d(W), 00433ca5(R)  
    //              int               Stack[-0x18]:4 NumDiff                   XREF[4]:     00433ae6(W), 00433c1b(R), 00433c25(W), 00433ca1(R)  
    //              int               Stack[-0x1c]:4 NumSame                   XREF[5]:     00433afc(W), 00433b61(W), 00433b90(R), 00433c07(R), 
    //                                                                                     00433c51(R)  
    //              long              Stack[-0x20]:4 mycs5                     XREF[5]:     00433af0(W), 00433b43(W), 00433b9d(R), 00433be6(R), 
    //                                                                                     00433c40(R)  
    //              long              Stack[-0x24]:4 mycs2                     XREF[6]:     00433af4(W), 00433b5d(W), 00433b98(R), 00433bf1(R), 
    //                                                                                     00433c29(R), 00433c56(R)  
    //              long              Stack[-0x28]:4 mycs3                     XREF[6]:     00433af8(W), 00433b56(W), 00433b94(R), 00433bfc(R), 
    //                                                                                     00433c20(R), 00433c48(R)  
    //              long              Stack[-0x2c]:4 mycs4
    //                               ?IsPlayerOutOfSync@RGE_Communications_Synchronize@@QAEHIK@Z  XREF[1]:     IsPlayerOutOfSync:0042f280(c)  
    //                               RGE_Communications_Synchronize::IsPlayerOutOfSync
    //                              com_sync.cpp:345 (9)
    //         00433ad0     SUB        ESP,0x28
    //         00433ad3     PUSH       EBX
    //         00433ad4     PUSH       EBP
    //         00433ad5     MOV        EDX,this
    //         00433ad7     PUSH       ESI
    //         00433ad8     PUSH       EDI
    //                              com_sync.cpp:346 (13)
    //         00433ad9     XOR        EBX,EBX
    //         00433adb     LEA        EDI,[EDX + 0x5c]
    //         00433ade     MOV        dword ptr [ESP + local_4],EDX
    //         00433ae2     MOV        dword ptr [ESP + NumPlayers],EBX
    //                              com_sync.cpp:347 (4)
    //         00433ae6     MOV        dword ptr [ESP + NumDiff],EBX
    //                              com_sync.cpp:348 (4)
    //         00433aea     MOV        dword ptr [ESP + myRandom],EBX
    //                              com_sync.cpp:350 (2)
    //         00433aee     XOR        EBP,EBP
    //                              com_sync.cpp:351 (4)
    //         00433af0     MOV        dword ptr [ESP + mycs5],EBX
    //                              com_sync.cpp:352 (4)
    //         00433af4     MOV        dword ptr [ESP + mycs2],EBX
    //                              com_sync.cpp:353 (4)
    //         00433af8     MOV        dword ptr [ESP + mycs3],EBX
    //                              com_sync.cpp:354 (4)
    //         00433afc     MOV        dword ptr [ESP + NumSame],EBX
    //                              com_sync.cpp:355 (4)
    //         00433b00     MOV        dword ptr [ESP + local_8],EBX
    //                              com_sync.cpp:356 (4)
    //         00433b04     MOV        dword ptr [ESP + foundMine],EBX
    //                              com_sync.cpp:360 (7)
    //         00433b08     MOV        this,0x1
    //         00433b0d     MOV        EAX,EDI
    //                               LAB_00433b0f                                                 XREF[1]:     00433b27(j)  
    //                              com_sync.cpp:362 (17)
    //         00433b0f     MOV        ESI,dword ptr [ESP + param_1]
    //         00433b13     CMP        dword ptr [EAX + -0x8],ESI
    //         00433b16     JNZ        LAB_00433b20
    //         00433b18     MOV        ESI,dword ptr [ESP + param_2]
    //         00433b1c     CMP        dword ptr [EAX],ESI
    //         00433b1e     JZ         LAB_00433b2b
    //                               LAB_00433b20                                                 XREF[1]:     00433b16(j)  
    //                              com_sync.cpp:360 (11)
    //         00433b20     INC        this
    //         00433b21     ADD        EAX,0x24
    //         00433b24     CMP        this,0x36
    //         00433b27     JBE        LAB_00433b0f
    //         00433b29     JMP        LAB_00433b69
    //                               LAB_00433b2b                                                 XREF[1]:     00433b1e(j)  
    //                              com_sync.cpp:365 (3)
    //         00433b2b     LEA        EAX,[ECX + ECX*0x8]
    //                              com_sync.cpp:369 (34)
    //         00433b2e     ADD        this,0x2
    //         00433b31     MOV        dword ptr [ESP + myRandom],0x1
    //         00433b39     MOV        ESI,dword ptr [EDX + EAX*0x4 + 0x40]
    //         00433b3d     LEA        EAX,[EDX + EAX*0x4]
    //         00433b40     LEA        this,[ECX + ECX*0x8]
    //         00433b43     MOV        dword ptr [ESP + mycs5],ESI
    //         00433b47     MOV        ESI,dword ptr [EAX + 0x44]
    //         00433b4a     MOV        EBX,dword ptr [EAX + 0x34]
    //         00433b4d     MOV        EDX,dword ptr [EDX + this->Comm*0x4]
    //                              com_sync.cpp:370 (10)
    //         00433b50     MOV        this,dword ptr [EAX + 0x4c]
    //         00433b53     MOV        EBP,dword ptr [EAX + 0x3c]
    //         00433b56     MOV        dword ptr [ESP + mycs3],EDX
    //                              com_sync.cpp:371 (15)
    //         00433b5a     MOV        EDX,dword ptr [EAX + 0x50]
    //         00433b5d     MOV        dword ptr [ESP + mycs2],ESI
    //         00433b61     MOV        dword ptr [ESP + NumSame],this
    //         00433b65     MOV        dword ptr [ESP + local_8],EDX
    //                               LAB_00433b69                                                 XREF[1]:     00433b29(j)  
    //                              com_sync.cpp:376 (8)
    //         00433b69     MOV        EAX,dword ptr [ESP + myRandom]
    //         00433b6d     TEST       EAX,EAX
    //         00433b6f     JNZ        LAB_00433b90
    //                              com_sync.cpp:378 (11)
    //         00433b71     MOV        EAX,[L]                                          = 00000000
    //         00433b76     PUSH       s_OUTOFSYNC:_DIDN'T_FIND_MY_VALUES               = "OUTOFSYNC: DIDN'T FIND MY VALUES"
    //         00433b7b     PUSH       EAX
    //                              com_sync.cpp:433 (8)
    //         00433b7c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433b81     ADD        ESP,0x8
    //                              com_sync.cpp:434 (2)
    //         00433b84     XOR        EAX,EAX
    //                              com_sync.cpp:435 (10)
    //         00433b86     POP        EDI
    //         00433b87     POP        ESI
    //         00433b88     POP        EBP
    //         00433b89     POP        EBX
    //         00433b8a     ADD        ESP,0x28
    //         00433b8d     RET        0x8
    //                               LAB_00433b90                                                 XREF[1]:     00433b6f(j)  
    //                              com_sync.cpp:382 (42)
    //         00433b90     MOV        this,dword ptr [ESP + NumSame]
    //         00433b94     MOV        EDX,dword ptr [ESP + mycs3]
    //         00433b98     MOV        EAX,dword ptr [ESP + mycs2]
    //         00433b9c     PUSH       this
    //         00433b9d     MOV        this,dword ptr [ESP + mycs5]
    //         00433ba1     PUSH       EDX
    //         00433ba2     MOV        EDX,dword ptr [L]                                = 00000000
    //         00433ba8     PUSH       EAX
    //         00433ba9     PUSH       this
    //         00433baa     PUSH       EBP
    //         00433bab     PUSH       EBX
    //         00433bac     PUSH       s_OUTOFSYNC:_my_values:_%d_%d_%d_%               = "OUTOFSYNC: my values: %d %d %d %d %d %d"
    //         00433bb1     PUSH       EDX
    //         00433bb2     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433bb7     ADD        ESP,0x20
    //                              com_sync.cpp:385 (5)
    //         00433bba     MOV        ESI,0x1
    //                               LAB_00433bbf                                                 XREF[1]:     00433c7b(j)  
    //                              com_sync.cpp:387 (29)
    //         00433bbf     MOV        EAX,dword ptr [ESP + param_1]
    //         00433bc3     MOV        this,dword ptr [EDI + -0x8]
    //         00433bc6     CMP        this,EAX
    //         00433bc8     JZ         LAB_00433c74
    //         00433bce     MOV        this,dword ptr [ESP + param_2]
    //         00433bd2     MOV        EAX,dword ptr [EDI]
    //         00433bd4     CMP        EAX,this
    //         00433bd6     JNZ        LAB_00433c74
    //                              com_sync.cpp:395 (63)
    //         00433bdc     CMP        EBX,dword ptr [EDI + -0x4]
    //         00433bdf     JNZ        LAB_00433c40
    //         00433be1     CMP        EBP,dword ptr [EDI + 0x4]
    //         00433be4     JNZ        LAB_00433c40
    //         00433be6     MOV        EAX,dword ptr [ESP + mycs5]
    //         00433bea     MOV        this,dword ptr [EDI + 0x8]
    //         00433bed     CMP        EAX,this
    //         00433bef     JNZ        LAB_00433c44
    //         00433bf1     MOV        EDX,dword ptr [ESP + mycs2]
    //         00433bf5     MOV        this,dword ptr [EDI + 0xc]
    //         00433bf8     CMP        EDX,this
    //         00433bfa     JNZ        LAB_00433c44
    //         00433bfc     MOV        this,dword ptr [ESP + mycs3]
    //         00433c00     MOV        EDX,dword ptr [EDI + 0x10]
    //         00433c03     CMP        this,EDX
    //         00433c05     JNZ        LAB_00433c44
    //         00433c07     MOV        this,dword ptr [ESP + NumSame]
    //         00433c0b     MOV        EDX,dword ptr [EDI + 0x14]
    //         00433c0e     CMP        this,EDX
    //         00433c10     JNZ        LAB_00433c44
    //         00433c12     MOV        EDX,dword ptr [ESP + local_8]
    //         00433c16     CMP        EDX,dword ptr [EDI + 0x18]
    //         00433c19     JNZ        LAB_00433c44
    //                              com_sync.cpp:402 (4)
    //         00433c1b     MOV        EDX,dword ptr [ESP + NumDiff]
    //                              com_sync.cpp:403 (37)
    //         00433c1f     PUSH       this
    //         00433c20     MOV        this,dword ptr [ESP + mycs3]
    //         00433c24     INC        EDX
    //         00433c25     MOV        dword ptr [ESP + NumDiff],EDX
    //         00433c29     MOV        EDX,dword ptr [ESP + mycs2]
    //         00433c2d     PUSH       this
    //         00433c2e     PUSH       EDX
    //         00433c2f     PUSH       EAX
    //         00433c30     MOV        EAX,[L]                                          = 00000000
    //         00433c35     PUSH       EBP
    //         00433c36     PUSH       EBX
    //         00433c37     PUSH       ESI
    //         00433c38     PUSH       s_OUTOFSYNC:_%d_same:_%d_%d_%d_%d_               = "OUTOFSYNC: %d same: %d %d %d %d %d %d"
    //         00433c3d     PUSH       EAX
    //         00433c3e     JMP        LAB_00433c6c
    //                               LAB_00433c40                                                 XREF[2]:     00433bdf(j), 00433be4(j)  
    //         00433c40     MOV        EAX,dword ptr [ESP + mycs5]
    //                               LAB_00433c44                                                 XREF[5]:     00433bef(j), 00433bfa(j), 
    //                                                                                                         00433c05(j), 00433c10(j), 
    //                                                                                                         00433c19(j)  
    //                              com_sync.cpp:397 (4)
    //         00433c44     MOV        this,dword ptr [ESP + NumPlayers]
    //                              com_sync.cpp:398 (57)
    //         00433c48     MOV        EDX,dword ptr [ESP + mycs3]
    //         00433c4c     INC        this
    //         00433c4d     MOV        dword ptr [ESP + NumPlayers],this
    //         00433c51     MOV        this,dword ptr [ESP + NumSame]
    //         00433c55     PUSH       this
    //         00433c56     MOV        this,dword ptr [ESP + mycs2]
    //         00433c5a     PUSH       EDX
    //         00433c5b     MOV        EDX,dword ptr [L]                                = 00000000
    //         00433c61     PUSH       this
    //         00433c62     PUSH       EAX
    //         00433c63     PUSH       EBP
    //         00433c64     PUSH       EBX
    //         00433c65     PUSH       ESI
    //         00433c66     PUSH       s_OUTOFSYNC:_%d_diff:_%d_%d_%d_%d_               = "OUTOFSYNC: %d diff: %d %d %d %d %d %d"
    //         00433c6b     PUSH       EDX
    //                               LAB_00433c6c                                                 XREF[1]:     00433c3e(j)  
    //         00433c6c     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433c71     ADD        ESP,0x24
    //                               LAB_00433c74                                                 XREF[2]:     00433bc8(j), 00433bd6(j)  
    //         00433c74     INC        ESI
    //         00433c75     ADD        EDI,0x24
    //         00433c78     CMP        ESI,0x36
    //         00433c7b     JBE        LAB_00433bbf
    //                              com_sync.cpp:409 (5)
    //         00433c81     MOV        ESI,0x1
    //                               LAB_00433c86                                                 XREF[1]:     00433c9f(j)  
    //                              com_sync.cpp:411 (17)
    //         00433c86     MOV        EAX,dword ptr [ESP + local_4]
    //         00433c8a     PUSH       ESI
    //         00433c8b     MOV        this,dword ptr [EAX]
    //         00433c8d     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //         00433c92     CMP        EAX,0x2
    //         00433c95     JNZ        LAB_00433c9b
    //                              com_sync.cpp:412 (10)
    //         00433c97     INC        dword ptr [ESP + foundMine]
    //                               LAB_00433c9b                                                 XREF[1]:     00433c95(j)  
    //         00433c9b     INC        ESI
    //         00433c9c     CMP        ESI,0x9
    //         00433c9f     JLE        LAB_00433c86
    //                              com_sync.cpp:415 (35)
    //         00433ca1     MOV        EDI,dword ptr [ESP + NumDiff]
    //         00433ca5     MOV        ESI,dword ptr [ESP + NumPlayers]
    //         00433ca9     MOV        EBX,dword ptr [ESP + foundMine]
    //         00433cad     MOV        this,dword ptr [L]                               = 00000000
    //         00433cb3     PUSH       EDI
    //         00433cb4     PUSH       ESI
    //         00433cb5     PUSH       EBX
    //         00433cb6     PUSH       s_OUTOFSYNC:_numplayers=%d,_diff=%               = "OUTOFSYNC: numplayers=%d, diff=%d, same=%d"
    //         00433cbb     PUSH       this
    //         00433cbc     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433cc1     ADD        ESP,0x14
    //                              com_sync.cpp:419 (8)
    //         00433cc4     LEA        EDX,[EDI + ESI*0x1]
    //         00433cc7     DEC        EBX
    //         00433cc8     CMP        EDX,EBX
    //         00433cca     JGE        LAB_00433ceb
    //                              com_sync.cpp:421 (11)
    //         00433ccc     MOV        EAX,[L]                                          = 00000000
    //         00433cd1     PUSH       s_OUTOFSYNC:_return_not_out                      = "OUTOFSYNC: return not out"
    //         00433cd6     PUSH       EAX
    //                              com_sync.cpp:433 (8)
    //         00433cd7     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433cdc     ADD        ESP,0x8
    //                              com_sync.cpp:434 (2)
    //         00433cdf     XOR        EAX,EAX
    //                              com_sync.cpp:435 (10)
    //         00433ce1     POP        EDI
    //         00433ce2     POP        ESI
    //         00433ce3     POP        EBP
    //         00433ce4     POP        EBX
    //         00433ce5     ADD        ESP,0x28
    //         00433ce8     RET        0x8
    //                               LAB_00433ceb                                                 XREF[1]:     00433cca(j)  
    //                              com_sync.cpp:427 (4)
    //         00433ceb     CMP        ESI,EDI
    //         00433ced     JLE        LAB_00433d12
    //                              com_sync.cpp:429 (20)
    //         00433cef     MOV        this,dword ptr [L]                               = 00000000
    //         00433cf5     PUSH       s_OUTOFSYNC:_return_out                          = "OUTOFSYNC: return out"
    //         00433cfa     PUSH       this
    //         00433cfb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433d00     ADD        ESP,0x8
    //                              com_sync.cpp:430 (5)
    //         00433d03     MOV        EAX,0x1
    //                              com_sync.cpp:435 (10)
    //         00433d08     POP        EDI
    //         00433d09     POP        ESI
    //         00433d0a     POP        EBP
    //         00433d0b     POP        EBX
    //         00433d0c     ADD        ESP,0x28
    //         00433d0f     RET        0x8
    //                               LAB_00433d12                                                 XREF[1]:     00433ced(j)  
    //                              com_sync.cpp:433 (20)
    //         00433d12     MOV        EDX,dword ptr [L]                                = 00000000
    //         00433d18     PUSH       s_OUTOFSYNC:_return_not_out_2                    = "OUTOFSYNC: return not out 2"
    //         00433d1d     PUSH       EDX
    //         00433d1e     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
    //         00433d23     ADD        ESP,0x8
    //                              com_sync.cpp:434 (2)
    //         00433d26     XOR        EAX,EAX
    //                              com_sync.cpp:435 (10)
    //         00433d28     POP        EDI
    //         00433d29     POP        ESI
    //         00433d2a     POP        EBP
    //         00433d2b     POP        EBX
    //         00433d2c     ADD        ESP,0x28
    //         00433d2f     RET        0x8
    //         00433d32     ??         90h
    //         00433d33     NOP
    //         00433d34     NOP
    //         00433d35     NOP
    //         00433d36     NOP
    //         00433d37     NOP
    //         00433d38     NOP
    //         00433d39     NOP
    //         00433d3a     NOP
    //         00433d3b     NOP
    //         00433d3c     NOP
    //         00433d3d     NOP
    //         00433d3e     NOP
    //         00433d3f     NOP
    return 0;
}

RGE_Communications_Synchronize::RGE_Communications_Synchronize(TCommunications_Handler* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int RGE_Communications_Synchronize::Add(uint param_1, ulong param_2, ulong param_3, ulong param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int RGE_Communications_Synchronize::ValidateChecksums(uint param_1, ulong param_2, ulong param_3, ulong param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void RGE_Communications_Synchronize::LogChecksums(uint param_1, ulong param_2, ulong param_3, long param_4, long param_5, long param_6, long param_7, long param_8, ulong param_9) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

