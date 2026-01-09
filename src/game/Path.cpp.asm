#include "common.h"
#include "Path.h"

Path::Path(int param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall Path(Path * this, int param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046a740(R)  
    //                               ??0Path@@QAE@H@Z                                             XREF[6]:     RGE_Moving_Object:0045c49f(c), 
    //                               Path::Path                                                                RGE_Moving_Object:0045c4b1(c), 
    //                                                                                                         RGE_Moving_Object:0045c5fd(c), 
    //                                                                                                         RGE_Moving_Object:0045c60f(c), 
    //                                                                                                         recycle_in_to_game:0045c7b3(c), 
    //                                                                                                         operator+:0046a915(c)  
    //                              Path.cpp:36 (153)
    //         0046a740     MOV        EAX,dword ptr [ESP + param_1]
    //         0046a744     PUSH       EBX
    //         0046a745     PUSH       EBP
    //         0046a746     PUSH       ESI
    //         0046a747     MOV        ESI,this
    //         0046a749     XOR        EBP,EBP
    //         0046a74b     CMP        EAX,EBP
    //         0046a74d     PUSH       EDI
    //         0046a74e     MOV        dword ptr [ESI],EBP
    //         0046a750     MOV        dword ptr [ESI + 0x24],EBP
    //         0046a753     MOV        dword ptr [ESI + 0x28],EBP
    //         0046a756     MOV        dword ptr [ESI + 0x2c],EBP
    //         0046a759     MOV        dword ptr [ESI + 0x30],EBP
    //         0046a75c     MOV        dword ptr [ESI + 0x4],EBP
    //         0046a75f     MOV        dword ptr [ESI + 0x8],EBP
    //         0046a762     MOV        dword ptr [ESI + 0xc],EBP
    //         0046a765     MOV        dword ptr [ESI + 0x14],EBP
    //         0046a768     MOV        dword ptr [ESI + 0x18],EBP
    //         0046a76b     MOV        dword ptr [ESI + 0x1c],EBP
    //         0046a76e     JZ         LAB_0046a772
    //         0046a770     JL         LAB_0046a7d9
    //                               LAB_0046a772                                                 XREF[1]:     0046a76e(j)  
    //         0046a772     MOV        dword ptr [ESI + 0x28],EAX
    //         0046a775     SHL        EAX,0x4
    //         0046a778     PUSH       EAX
    //         0046a779     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046a77e     MOV        EBX,EAX
    //         0046a780     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046a783     ADD        ESP,0x4
    //         0046a786     XOR        EDI,EDI
    //         0046a788     CMP        EAX,EBP
    //         0046a78a     JLE        LAB_0046a7c6
    //         0046a78c     XOR        EAX,EAX
    //         0046a78e     LEA        this,[EBX + 0x8]
    //                               LAB_0046a791                                                 XREF[1]:     0046a7c4(j)  
    //         0046a791     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046a794     INC        EDI
    //         0046a795     ADD        this,0x10
    //         0046a798     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0046a79b     ADD        EAX,0x10
    //         0046a79e     MOV        dword ptr [this->timeStampValue + -0x18],EDX
    //         0046a7a1     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046a7a4     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0xc]
    //         0046a7a8     MOV        dword ptr [this->timeStampValue + -0x14],EDX
    //         0046a7ab     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046a7ae     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0x8]
    //         0046a7b2     MOV        dword ptr [this->timeStampValue + -0x10],EDX
    //         0046a7b5     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046a7b8     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x4]
    //         0046a7bc     MOV        byte ptr [this->timeStampValue + -0xc],DL
    //         0046a7bf     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0046a7c2     CMP        EDI,EDX
    //         0046a7c4     JL         LAB_0046a791
    //                               LAB_0046a7c6                                                 XREF[1]:     0046a78a(j)  
    //         0046a7c6     MOV        EAX,dword ptr [ESI + 0x24]
    //         0046a7c9     CMP        EAX,EBP
    //         0046a7cb     JZ         LAB_0046a7d6
    //         0046a7cd     PUSH       EAX
    //         0046a7ce     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046a7d3     ADD        ESP,0x4
    //                               LAB_0046a7d6                                                 XREF[1]:     0046a7cb(j)  
    //         0046a7d6     MOV        dword ptr [ESI + 0x24],EBX
    //                               LAB_0046a7d9                                                 XREF[1]:     0046a770(j)  
    //                              Path.cpp:44 (9)
    //         0046a7d9     MOV        EAX,ESI
    //         0046a7db     POP        EDI
    //         0046a7dc     POP        ESI
    //         0046a7dd     POP        EBP
    //         0046a7de     POP        EBX
    //         0046a7df     RET        0x4
    //         0046a7e2     ??         90h
    //         0046a7e3     NOP
    //         0046a7e4     NOP
    //         0046a7e5     NOP
    //         0046a7e6     NOP
    //         0046a7e7     NOP
    //         0046a7e8     NOP
    //         0046a7e9     NOP
    //         0046a7ea     NOP
    //         0046a7eb     NOP
    //         0046a7ec     NOP
    //         0046a7ed     NOP
    //         0046a7ee     NOP
    //         0046a7ef     NOP
}

Path::~Path() {
    /* TODO: Stub */
    //                              void __thiscall ~Path(Path * this)
    //              void              <VOID>         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ??1Path@@QAE@XZ                                              XREF[6]:     ~RGE_Moving_Object:0045c753(c), 
    //                               Path::~Path                                                               ~RGE_Moving_Object:0045c763(c), 
    //                                                                                                         recycle_in_to_game:0045c7d9(c), 
    //                                                                                                         operator+:0046a9c1(c), 
    //                                                                                                         FUN_0055dc68:0055dc71(c), 
    //                                                                                                         FUN_0055dc76:0055dc7f(c)  
    //                              Path.cpp:49 (7)
    //         0046a7f0     MOV        EAX,dword ptr [ECX + this->pathValue]
    //         0046a7f3     TEST       EAX,EAX
    //         0046a7f5     JZ         LAB_0046a800
    //                              Path.cpp:51 (9)
    //         0046a7f7     PUSH       EAX
    //         0046a7f8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046a7fd     ADD        ESP,0x4
    //                               LAB_0046a800                                                 XREF[1]:     0046a7f5(j)  
    //                              Path.cpp:52 (1)
    //         0046a800     RET
    //         0046a801     ??         90h
    //         0046a802     NOP
    //         0046a803     NOP
    //         0046a804     NOP
    //         0046a805     NOP
    //         0046a806     NOP
    //         0046a807     NOP
    //         0046a808     NOP
    //         0046a809     NOP
    //         0046a80a     NOP
    //         0046a80b     NOP
    //         0046a80c     NOP
    //         0046a80d     NOP
    //         0046a80e     NOP
    //         0046a80f     NOP
    //                              * class ostream & __cdecl operator<<(class ostream &,class Path const &)                                *
    //                              ostream * __cdecl operator<<(ostream * param_1, Path * param_2)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         Stack[0x4]:4   param_1                   XREF[3]:     0046a826(R), 0046a8ab(R), 0046a8d7(R)  
    //              Path *            Stack[0x8]:4   param_2                   XREF[1]:     0046a812(R)  
    //              undefined8        Stack[-0x14]:8 local_14                  XREF[2]:     0046a846(*), 0046a86d(*)  
    //                               ??6@YAAAVostream@@AAV0@ABVPath@@@Z
    //                               operator<<
    //                              Path.cpp:57 (2)
    //         0046a810     PUSH       EBX
    //         0046a811     PUSH       ESI
    //                              Path.cpp:58 (20)
    //         0046a812     MOV        ESI,dword ptr [ESP + param_2]
    //         0046a816     XOR        EBX,EBX
    //         0046a818     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046a81b     TEST       EAX,EAX
    //         0046a81d     JLE        LAB_0046a8d7
    //         0046a823     PUSH       EDI
    //         0046a824     XOR        EDI,EDI
    //                               LAB_0046a826                                                 XREF[1]:     0046a8d0(j)  
    //                              Path.cpp:60 (130)
    //         0046a826     MOV        ECX,dword ptr [ESP + param_1]
    //         0046a82a     PUSH       s_(                                              = "("
    //         0046a82f     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, char * p
    //         0046a834     MOV        ECX,dword ptr [ESI + 0x24]
    //         0046a837     SUB        ESP,0x8
    //         0046a83a     FLD        float ptr [ECX + EDI*0x1]
    //         0046a83d     MOV        ECX,EAX
    //         0046a83f     MOV        dword ptr [EAX + 0x4],0x1
    //         0046a846     FSTP       double ptr [ESP]=>local_14
    //         0046a849     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, double p
    //         0046a84e     PUSH       s_,_                                             = ", "
    //         0046a853     MOV        ECX,EAX
    //         0046a855     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, char * p
    //         0046a85a     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046a85d     SUB        ESP,0x8
    //         0046a860     MOV        ECX,EAX
    //         0046a862     FLD        float ptr [EDX + EDI*0x1 + 0x4]
    //         0046a866     MOV        dword ptr [EAX + 0x4],0x1
    //         0046a86d     FSTP       double ptr [ESP]=>local_14
    //         0046a870     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, double p
    //         0046a875     PUSH       s_,_                                             = ", "
    //         0046a87a     MOV        ECX,EAX
    //         0046a87c     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, char * p
    //         0046a881     MOV        ECX,dword ptr [ESI + 0x24]
    //         0046a884     PUSH       s_,_                                             = ", "
    //         0046a889     SUB        ESP,0x8
    //         0046a88c     FLD        float ptr [ECX + EDI*0x1 + 0x8]
    //         0046a890     MOV        ECX,EAX
    //         0046a892     MOV        dword ptr [EAX + 0x4],0x1
    //         0046a899     FSTP       double ptr [ESP]=>Stack[-0x18]
    //         0046a89c     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, double p
    //         0046a8a1     MOV        ECX,EAX
    //         0046a8a3     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, char * p
    //                              Path.cpp:62 (46)
    //         0046a8a8     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046a8ab     MOV        ECX,dword ptr [ESP + param_1]
    //         0046a8af     XOR        EAX,EAX
    //         0046a8b1     PUSH       s_)_                                             = ") "
    //         0046a8b6     MOV        AL,byte ptr [EDX + EDI*0x1 + 0xc]
    //         0046a8ba     PUSH       EAX
    //         0046a8bb     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, int para
    //         0046a8c0     MOV        ECX,EAX
    //         0046a8c2     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, char * p
    //         0046a8c7     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046a8ca     INC        EBX
    //         0046a8cb     ADD        EDI,0x10
    //         0046a8ce     CMP        EBX,EAX
    //         0046a8d0     JL         LAB_0046a826
    //                              Path.cpp:57 (1)
    //         0046a8d6     POP        EDI
    //                               LAB_0046a8d7                                                 XREF[1]:     0046a81d(j)  
    //                              Path.cpp:64 (4)
    //         0046a8d7     MOV        EAX,dword ptr [ESP + param_1]
    //                              Path.cpp:65 (3)
    //         0046a8db     POP        ESI
    //         0046a8dc     POP        EBX
    //         0046a8dd     RET
    //         0046a8de     ??         90h
    //         0046a8df     NOP
    //                              * public: class Path __thiscall Path::operator+(class Path const &)const                                *
    //                              Path __thiscall operator+(Path * this, Path * __return_storage_ptr__
    //              Path              EAX:4 (ptr)    <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              Path *            Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0046a99f(R)  
    //              Path *            Stack[0x8]:4   param_1                   XREF[1]:     0046a8f9(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046a921(W), 0046a9bc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0046a9c6(R)  
    //              Path              Stack[-0x44]   newPath                   XREF[2,5]:   0046a910(W), 0046a9b0(W), 0046a90a(*), 0046a94b(*), 
    //                                                                                     0046a985(*), 0046a9a8(*), 0046a9b8(*)  
    //              undefined4        Stack[-0x58]:4 local_58                  XREF[2]:     0046a948(W), 0046a98c(W)  
    //              undefined4        Stack[-0x5c]:4 local_5c                  XREF[2]:     0046a942(W), 0046a982(W)  
    //              undefined4        Stack[-0x60]:4 local_60                  XREF[2]:     0046a93c(W), 0046a97c(W)  
    //              undefined4        Stack[-0x64]:4 local_64                  XREF[2]:     0046a937(*), 0046a977(*)  
    //                               ??HPath@@QBE?AV0@ABV0@@Z
    //                               Path::operator+
    //                              Path.cpp:70 (25)
    //         0046a8e0     PUSH       -0x1
    //         0046a8e2     PUSH       FUN_0055e1bf
    //         0046a8e7     MOV        EAX,FS:[0x0]
    //         0046a8ed     PUSH       EAX
    //         0046a8ee     MOV        dword ptr FS:[0x0],ESP
    //         0046a8f5     SUB        ESP,0x38
    //         0046a8f8     PUSH       EBX
    //                              Path.cpp:71 (33)
    //         0046a8f9     MOV        EBX,dword ptr [ESP + param_1]
    //         0046a8fd     PUSH       EBP
    //         0046a8fe     PUSH       ESI
    //         0046a8ff     MOV        EDX,dword ptr [EBX + 0x28]
    //         0046a902     MOV        ESI,this
    //         0046a904     PUSH       EDI
    //         0046a905     XOR        EBP,EBP
    //         0046a907     MOV        EAX,dword ptr [ESI + 0x28]
    //         0046a90a     LEA        this=>newPath.startValue,[ESP + 0x14]
    //         0046a90e     ADD        EAX,EDX
    //         0046a910     MOV        dword ptr [ESP + newPath.timeStampValue],EBP
    //         0046a914     PUSH       EAX
    //         0046a915     CALL       Path::Path                                       undefined Path(Path * this, int param_1)
    //                              Path.cpp:72 (20)
    //         0046a91a     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046a91d     XOR        EDI,EDI
    //         0046a91f     CMP        EAX,EBP
    //         0046a921     MOV        dword ptr [ESP + local_4],0x1
    //         0046a929     JLE        LAB_0046a95f
    //                               LAB_0046a92b                                                 XREF[1]:     0046a95d(j)  
    //         0046a92b     MOV        this,dword ptr [ESI + 0x24]
    //                              Path.cpp:73 (49)
    //         0046a92e     SUB        ESP,0x10
    //         0046a931     ADD        this,EBP
    //         0046a933     MOV        EDX,ESP
    //         0046a935     MOV        EAX,dword ptr [this->timeStampValue]
    //         0046a937     MOV        dword ptr [EDX]=>local_64,EAX
    //         0046a939     MOV        EAX,dword ptr [ECX + this->startValue.x]
    //         0046a93c     MOV        dword ptr [EDX + local_60],EAX
    //         0046a93f     MOV        EAX,dword ptr [ECX + this+0x8]
    //         0046a942     MOV        dword ptr [EDX + local_5c],EAX
    //         0046a945     MOV        this,dword ptr [ECX + this+0xc]
    //         0046a948     MOV        dword ptr [EDX + local_58],this
    //         0046a94b     LEA        this=>newPath.startValue,[ESP + 0x24]
    //         0046a94f     CALL       Path::insertAtEnd                                int insertAtEnd(Path * this, Waypoint param_1)
    //         0046a954     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046a957     INC        EDI
    //         0046a958     ADD        EBP,0x10
    //         0046a95b     CMP        EDI,EAX
    //         0046a95d     JL         LAB_0046a92b
    //                               LAB_0046a95f                                                 XREF[1]:     0046a929(j)  
    //                              Path.cpp:74 (12)
    //         0046a95f     MOV        EAX,dword ptr [EBX + 0x2c]
    //         0046a962     XOR        ESI,ESI
    //         0046a964     TEST       EAX,EAX
    //         0046a966     JLE        LAB_0046a99f
    //         0046a968     SHL        EDI,0x4
    //                               LAB_0046a96b                                                 XREF[1]:     0046a99d(j)  
    //                              Path.cpp:75 (52)
    //         0046a96b     MOV        EDX,dword ptr [EBX + 0x24]
    //         0046a96e     SUB        ESP,0x10
    //         0046a971     ADD        EDX,EDI
    //         0046a973     MOV        EAX,ESP
    //         0046a975     MOV        this,dword ptr [EDX]
    //         0046a977     MOV        dword ptr [EAX]=>local_64,this
    //         0046a979     MOV        this,dword ptr [EDX + 0x4]
    //         0046a97c     MOV        dword ptr [EAX + local_60],this
    //         0046a97f     MOV        this,dword ptr [EDX + 0x8]
    //         0046a982     MOV        dword ptr [EAX + local_5c],this
    //         0046a985     LEA        this=>newPath.startValue,[ESP + 0x24]
    //         0046a989     MOV        EDX,dword ptr [EDX + 0xc]
    //         0046a98c     MOV        dword ptr [EAX + local_58],EDX
    //         0046a98f     CALL       Path::insertAtEnd                                int insertAtEnd(Path * this, Waypoint param_1)
    //         0046a994     MOV        EAX,dword ptr [EBX + 0x2c]
    //         0046a997     ADD        EDI,0x10
    //         0046a99a     INC        ESI
    //         0046a99b     CMP        ESI,EAX
    //         0046a99d     JL         LAB_0046a96b
    //                               LAB_0046a99f                                                 XREF[1]:     0046a966(j)  
    //                              Path.cpp:76 (39)
    //         0046a99f     MOV        EBX,dword ptr [ESP + __return_storage_ptr__]
    //         0046a9a3     MOV        this,0xd
    //         0046a9a8     LEA        ESI=>newPath.startValue,[ESP + 0x14]
    //         0046a9ac     MOV        EDI,EBX
    //         0046a9ae     MOVSD.REP  ES:EDI,ESI
    //         0046a9b0     MOV        dword ptr [ESP + newPath.timeStampValue],0x1
    //         0046a9b8     LEA        this=>newPath.startValue,[ESP + 0x14]
    //         0046a9bc     MOV        byte ptr [ESP + local_4],0x0
    //         0046a9c1     CALL       Path::~Path                                      void ~Path(Path * this)
    //                              Path.cpp:77 (23)
    //         0046a9c6     MOV        this,dword ptr [ESP + local_c]
    //         0046a9ca     POP        EDI
    //         0046a9cb     POP        ESI
    //         0046a9cc     MOV        EAX,EBX
    //         0046a9ce     POP        EBP
    //         0046a9cf     MOV        dword ptr FS:[0x0],this
    //         0046a9d6     POP        EBX
    //         0046a9d7     ADD        ESP,0x44
    //         0046a9da     RET        0x8
    //         0046a9dd     ??         90h
    //         0046a9de     NOP
    //         0046a9df     NOP
}

Path* Path::operator=(Path* param_1) {
    /* TODO: Stub */
    //                              Path * __thiscall operator=(Path * this, Path * param_1)
    //              Path *            EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              Path *            Stack[0x4]:4   param_1                   XREF[1]:     0046a9e4(R)  
    //                               ??4Path@@QAEAAV0@ABV0@@Z                                     XREF[1]:     recycle_in_to_game:0045c7c9(c)  
    //                               Path::operator=
    //                              Path.cpp:82 (4)
    //         0046a9e0     PUSH       EBX
    //         0046a9e1     PUSH       EBP
    //         0046a9e2     PUSH       ESI
    //         0046a9e3     PUSH       EDI
    //                              Path.cpp:83 (16)
    //         0046a9e4     MOV        EDI,dword ptr [ESP + param_1]
    //         0046a9e8     MOV        ESI,this
    //         0046a9ea     MOV        this,dword ptr [ESI + 0x28]
    //         0046a9ed     MOV        EAX,dword ptr [EDI + 0x28]
    //         0046a9f0     CMP        this,EAX
    //         0046a9f2     JGE        LAB_0046aa70
    //                              Path.cpp:84 (124)
    //         0046a9f4     TEST       EAX,EAX
    //         0046a9f6     JZ         LAB_0046aa00
    //         0046a9f8     CMP        this,EAX
    //         0046a9fa     JG         LAB_0046aa70
    //         0046a9fc     TEST       EAX,EAX
    //         0046a9fe     JNZ        LAB_0046aa05
    //                               LAB_0046aa00                                                 XREF[1]:     0046a9f6(j)  
    //         0046aa00     LEA        EAX,[ECX + ECX*0x1]
    //         0046aa03     JMP        LAB_0046aa07
    //                               LAB_0046aa05                                                 XREF[1]:     0046a9fe(j)  
    //         0046aa05     ADD        EAX,this
    //                               LAB_0046aa07                                                 XREF[1]:     0046aa03(j)  
    //         0046aa07     MOV        this,EAX
    //         0046aa09     MOV        dword ptr [ESI + 0x28],EAX
    //         0046aa0c     SHL        this,0x4
    //         0046aa0f     PUSH       this
    //         0046aa10     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046aa15     MOV        EBX,EAX
    //         0046aa17     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046aa1a     ADD        ESP,0x4
    //         0046aa1d     XOR        EBP,EBP
    //         0046aa1f     TEST       EAX,EAX
    //         0046aa21     JLE        LAB_0046aa5d
    //         0046aa23     XOR        EAX,EAX
    //         0046aa25     LEA        this,[EBX + 0x8]
    //                               LAB_0046aa28                                                 XREF[1]:     0046aa5b(j)  
    //         0046aa28     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046aa2b     INC        EBP
    //         0046aa2c     ADD        this,0x10
    //         0046aa2f     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0046aa32     ADD        EAX,0x10
    //         0046aa35     MOV        dword ptr [this->timeStampValue + -0x18],EDX
    //         0046aa38     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046aa3b     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0xc]
    //         0046aa3f     MOV        dword ptr [this->timeStampValue + -0x14],EDX
    //         0046aa42     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046aa45     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0x8]
    //         0046aa49     MOV        dword ptr [this->timeStampValue + -0x10],EDX
    //         0046aa4c     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046aa4f     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x4]
    //         0046aa53     MOV        byte ptr [this->timeStampValue + -0xc],DL
    //         0046aa56     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0046aa59     CMP        EBP,EDX
    //         0046aa5b     JL         LAB_0046aa28
    //                               LAB_0046aa5d                                                 XREF[1]:     0046aa21(j)  
    //         0046aa5d     MOV        EAX,dword ptr [ESI + 0x24]
    //         0046aa60     TEST       EAX,EAX
    //         0046aa62     JZ         LAB_0046aa6d
    //         0046aa64     PUSH       EAX
    //         0046aa65     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046aa6a     ADD        ESP,0x4
    //                               LAB_0046aa6d                                                 XREF[1]:     0046aa62(j)  
    //         0046aa6d     MOV        dword ptr [ESI + 0x24],EBX
    //                               LAB_0046aa70                                                 XREF[2]:     0046a9f2(j), 0046a9fa(j)  
    //                              Path.cpp:85 (11)
    //         0046aa70     MOV        EAX,dword ptr [EDI + 0x2c]
    //         0046aa73     XOR        this,this
    //         0046aa75     TEST       EAX,EAX
    //         0046aa77     JLE        LAB_0046aabc
    //         0046aa79     XOR        EAX,EAX
    //                               LAB_0046aa7b                                                 XREF[1]:     0046aaba(j)  
    //                              Path.cpp:86 (13)
    //         0046aa7b     MOV        EDX,dword ptr [EDI + 0x24]
    //         0046aa7e     MOV        EBX,dword ptr [ESI + 0x24]
    //         0046aa81     INC        this
    //         0046aa82     MOV        EDX,dword ptr [EAX + EDX*0x1]
    //         0046aa85     MOV        dword ptr [EBX + EAX*0x1],EDX
    //                              Path.cpp:87 (14)
    //         0046aa88     MOV        EDX,dword ptr [EDI + 0x24]
    //         0046aa8b     MOV        EBX,dword ptr [ESI + 0x24]
    //         0046aa8e     MOV        EDX,dword ptr [EAX + EDX*0x1 + 0x4]
    //         0046aa92     MOV        dword ptr [EBX + EAX*0x1 + 0x4],EDX
    //                              Path.cpp:88 (14)
    //         0046aa96     MOV        EDX,dword ptr [EDI + 0x24]
    //         0046aa99     MOV        EBX,dword ptr [ESI + 0x24]
    //         0046aa9c     MOV        EDX,dword ptr [EAX + EDX*0x1 + 0x8]
    //         0046aaa0     MOV        dword ptr [EBX + EAX*0x1 + 0x8],EDX
    //                              Path.cpp:89 (24)
    //         0046aaa4     MOV        EDX,dword ptr [EDI + 0x24]
    //         0046aaa7     MOV        EBX,dword ptr [ESI + 0x24]
    //         0046aaaa     MOV        DL,byte ptr [EAX + EDX*0x1 + 0xc]
    //         0046aaae     MOV        byte ptr [EBX + EAX*0x1 + 0xc],DL
    //         0046aab2     MOV        EDX,dword ptr [EDI + 0x2c]
    //         0046aab5     ADD        EAX,0x10
    //         0046aab8     CMP        this,EDX
    //         0046aaba     JL         LAB_0046aa7b
    //                               LAB_0046aabc                                                 XREF[1]:     0046aa77(j)  
    //                              Path.cpp:91 (6)
    //         0046aabc     MOV        EAX,dword ptr [EDI + 0x30]
    //         0046aabf     MOV        dword ptr [ESI + 0x30],EAX
    //                              Path.cpp:92 (6)
    //         0046aac2     MOV        this,dword ptr [EDI + 0x2c]
    //         0046aac5     MOV        dword ptr [ESI + 0x2c],this
    //                              Path.cpp:93 (2)
    //         0046aac8     MOV        EAX,ESI
    //                              Path.cpp:94 (7)
    //         0046aaca     POP        EDI
    //         0046aacb     POP        ESI
    //         0046aacc     POP        EBP
    //         0046aacd     POP        EBX
    //         0046aace     RET        0x4
    //         0046aad1     ??         90h
    //         0046aad2     NOP
    //         0046aad3     NOP
    //         0046aad4     NOP
    //         0046aad5     NOP
    //         0046aad6     NOP
    //         0046aad7     NOP
    //         0046aad8     NOP
    //         0046aad9     NOP
    //         0046aada     NOP
    //         0046aadb     NOP
    //         0046aadc     NOP
    //         0046aadd     NOP
    //         0046aade     NOP
    //         0046aadf     NOP
    //                              * public: int __thiscall Path::operator==(class Path const &)const                                      *
    //                              int __thiscall operator==(Path * this, Path * param_1)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              Path *            Stack[0x4]:4   param_1                   XREF[1]:     0046aaf0(R)  
    //                               ??8Path@@QBEHABV0@@Z
    //                               Path::operator==
    //                              Path.cpp:99 (4)
    //         0046aae0     PUSH       EBX
    //         0046aae1     PUSH       EBP
    //         0046aae2     PUSH       ESI
    //         0046aae3     PUSH       EDI
    //                              Path.cpp:100 (9)
    //         0046aae4     MOV        EDI,dword ptr [ECX + this->currentSizeValue]
    //         0046aae7     XOR        ESI,ESI
    //         0046aae9     TEST       EDI,EDI
    //         0046aaeb     JLE        LAB_0046ab4e
    //                              Path.cpp:105 (76)
    //         0046aaed     MOV        EAX,dword ptr [ECX + this->pathValue]
    //         0046aaf0     MOV        this,dword ptr [ESP + param_1]
    //         0046aaf4     MOV        EBP,EAX
    //         0046aaf6     MOV        this,dword ptr [ECX + this->pathValue]
    //         0046aaf9     LEA        EDX,[EAX + 0x8]
    //         0046aafc     SUB        EBP,this
    //                               LAB_0046aafe                                                 XREF[1]:     0046ab37(j)  
    //         0046aafe     FLD        float ptr [EBP + this->timeStampValue*0x1]
    //         0046ab02     FCOMP      float ptr [this->timeStampValue]
    //         0046ab04     FNSTSW     AX
    //         0046ab06     TEST       AH,0x40
    //         0046ab09     JZ         LAB_0046ab45
    //         0046ab0b     FLD        float ptr [EDX + -0x4]
    //         0046ab0e     FCOMP      float ptr [ECX + this->startValue.x]
    //         0046ab11     FNSTSW     AX
    //         0046ab13     TEST       AH,0x40
    //         0046ab16     JZ         LAB_0046ab45
    //         0046ab18     FLD        float ptr [EDX]
    //         0046ab1a     FCOMP      float ptr [ECX + this+0x8]
    //         0046ab1d     FNSTSW     AX
    //         0046ab1f     TEST       AH,0x40
    //         0046ab22     JZ         LAB_0046ab45
    //         0046ab24     MOV        AL,byte ptr [EDX + 0x4]
    //         0046ab27     MOV        BL,byte ptr [ECX + this+0xc]
    //         0046ab2a     CMP        AL,BL
    //         0046ab2c     JNZ        LAB_0046ab45
    //         0046ab2e     INC        ESI
    //         0046ab2f     ADD        EDX,0x10
    //         0046ab32     ADD        this,0x10
    //         0046ab35     CMP        ESI,EDI
    //         0046ab37     JL         LAB_0046aafe
    //                              Path.cpp:107 (5)
    //         0046ab39     MOV        EAX,0x1
    //                              Path.cpp:108 (7)
    //         0046ab3e     POP        EDI
    //         0046ab3f     POP        ESI
    //         0046ab40     POP        EBP
    //         0046ab41     POP        EBX
    //         0046ab42     RET        0x4
    //                               LAB_0046ab45                                                 XREF[4]:     0046ab09(j), 0046ab16(j), 
    //                                                                                                         0046ab22(j), 0046ab2c(j)  
    //                              Path.cpp:106 (2)
    //         0046ab45     XOR        EAX,EAX
    //                              Path.cpp:108 (19)
    //         0046ab47     POP        EDI
    //         0046ab48     POP        ESI
    //         0046ab49     POP        EBP
    //         0046ab4a     POP        EBX
    //         0046ab4b     RET        0x4
    //                               LAB_0046ab4e                                                 XREF[1]:     0046aaeb(j)  
    //         0046ab4e     POP        EDI
    //         0046ab4f     POP        ESI
    //         0046ab50     POP        EBP
    //         0046ab51     MOV        EAX,0x1
    //         0046ab56     POP        EBX
    //         0046ab57     RET        0x4
    //         0046ab5a     ??         90h
    //         0046ab5b     NOP
    //         0046ab5c     NOP
    //         0046ab5d     NOP
    //         0046ab5e     NOP
    //         0046ab5f     NOP
    return 0;
}

int Path::insertAtCurrent(Waypoint* param_1) {
    /* TODO: Stub */
    //                              int __thiscall insertAtCurrent(Path * this, Waypoint * param_1)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              Waypoint *        Stack[0x4]:4   param_1                   XREF[1]:     0046ab81(R)  
    //                               ?insertAtCurrent@Path@@QAEHABUWaypoint@@@Z                   XREF[6]:     findPath:0045d73c(c), 
    //                               Path::insertAtCurrent                                                     findPath:0045d744(c), 
    //                                                                                                         copyPath:0046d93b(c), 
    //                                                                                                         copyPath:0046d955(c), 
    //                                                                                                         copyPath:0046dc48(c), 
    //                                                                                                         copyPath:0046dc66(c)  
    //                              Path.cpp:113 (3)
    //         0046ab60     PUSH       ESI
    //         0046ab61     MOV        ESI,this
    //                              Path.cpp:115 (10)
    //         0046ab63     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046ab66     CMP        EAX,0x3e8
    //         0046ab6b     JLE        LAB_0046ab73
    //                              Path.cpp:117 (2)
    //         0046ab6d     XOR        EAX,EAX
    //                              Path.cpp:139 (4)
    //         0046ab6f     POP        ESI
    //         0046ab70     RET        0x4
    //                               LAB_0046ab73                                                 XREF[1]:     0046ab6b(j)  
    //                              Path.cpp:121 (14)
    //         0046ab73     INC        EAX
    //         0046ab74     PUSH       EDI
    //         0046ab75     SHL        EAX,0x4
    //         0046ab78     PUSH       EBP
    //         0046ab79     PUSH       EAX
    //         0046ab7a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046ab7f     MOV        EBP,EAX
    //                              Path.cpp:123 (7)
    //         0046ab81     MOV        EAX,dword ptr [ESP + param_1]
    //         0046ab85     ADD        ESP,0x4
    //                              Path.cpp:127 (32)
    //         0046ab88     XOR        EDI,EDI
    //         0046ab8a     MOV        this,dword ptr [EAX]
    //         0046ab8c     MOV        dword ptr [EBP],this
    //         0046ab8f     MOV        EDX,dword ptr [EAX + 0x4]
    //         0046ab92     MOV        dword ptr [EBP + 0x4],EDX
    //         0046ab95     MOV        this,dword ptr [EAX + 0x8]
    //         0046ab98     MOV        dword ptr [EBP + 0x8],this
    //         0046ab9b     MOV        DL,byte ptr [EAX + 0xc]
    //         0046ab9e     MOV        byte ptr [EBP + 0xc],DL
    //         0046aba1     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046aba4     TEST       EAX,EAX
    //         0046aba6     JLE        LAB_0046abe2
    //                              Path.cpp:139 (58)
    //         0046aba8     XOR        EAX,EAX
    //         0046abaa     LEA        this,[EBP + 0x14]
    //                               LAB_0046abad                                                 XREF[1]:     0046abe0(j)  
    //         0046abad     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046abb0     INC        EDI
    //         0046abb1     ADD        this,0x10
    //         0046abb4     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0046abb7     ADD        EAX,0x10
    //         0046abba     MOV        dword ptr [this->timeStampValue + -0x14],EDX
    //         0046abbd     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046abc0     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0xc]
    //         0046abc4     MOV        dword ptr [this->timeStampValue + -0x10],EDX
    //         0046abc7     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046abca     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0x8]
    //         0046abce     MOV        dword ptr [this->timeStampValue + -0xc],EDX
    //         0046abd1     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046abd4     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x4]
    //         0046abd8     MOV        byte ptr [this->timeStampValue + -0x8],DL
    //         0046abdb     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0046abde     CMP        EDI,EDX
    //         0046abe0     JL         LAB_0046abad
    //                               LAB_0046abe2                                                 XREF[1]:     0046aba6(j)  
    //                              Path.cpp:134 (7)
    //         0046abe2     MOV        EAX,dword ptr [ESI + 0x24]
    //         0046abe5     TEST       EAX,EAX
    //         0046abe7     JZ         LAB_0046abf2
    //                              Path.cpp:135 (9)
    //         0046abe9     PUSH       EAX
    //         0046abea     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046abef     ADD        ESP,0x4
    //                               LAB_0046abf2                                                 XREF[1]:     0046abe7(j)  
    //                              Path.cpp:137 (12)
    //         0046abf2     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046abf5     MOV        dword ptr [ESI + 0x24],EBP
    //         0046abf8     INC        EAX
    //         0046abf9     POP        EBP
    //         0046abfa     MOV        dword ptr [ESI + 0x2c],EAX
    //         0046abfd     POP        EDI
    //                              Path.cpp:138 (5)
    //         0046abfe     MOV        EAX,0x1
    //                              Path.cpp:139 (4)
    //         0046ac03     POP        ESI
    //         0046ac04     RET        0x4
    //         0046ac07     ??         90h
    //         0046ac08     NOP
    //         0046ac09     NOP
    //         0046ac0a     NOP
    //         0046ac0b     NOP
    //         0046ac0c     NOP
    //         0046ac0d     NOP
    //         0046ac0e     NOP
    //         0046ac0f     NOP
    return 0;
}

int Path::insertAtEnd(Waypoint param_1) {
    /* TODO: Stub */
    //                              int __thiscall insertAtEnd(Path * this, Waypoint param_1)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              Waypoint          Stack[0x4]:16  param_1                   XREF[1,3]:   0046ac90(R), 0046aca0(R), 0046acb1(R), 0046acc2(R)  
    //                               ?insertAtEnd@Path@@QAEHUWaypoint@@@Z                         XREF[3]:     setup:0045cb77(c), 
    //                               Path::insertAtEnd                                                         operator+:0046a94f(c), 
    //                                                                                                         operator+:0046a98f(c)  
    //                              Path.cpp:144 (3)
    //         0046ac10     PUSH       ESI
    //         0046ac11     MOV        ESI,this
    //                              Path.cpp:145 (10)
    //         0046ac13     MOV        EAX,dword ptr [ESI + 0x28]
    //         0046ac16     MOV        this,dword ptr [ESI + 0x2c]
    //         0046ac19     CMP        this,EAX
    //         0046ac1b     JNZ        LAB_0046ac8a
    //                              Path.cpp:146 (30)
    //         0046ac1d     ADD        EAX,EAX
    //         0046ac1f     PUSH       EDI
    //         0046ac20     MOV        dword ptr [ESI + 0x28],EAX
    //         0046ac23     PUSH       EBP
    //         0046ac24     SHL        EAX,0x4
    //         0046ac27     PUSH       EAX
    //         0046ac28     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0046ac2d     MOV        EBP,EAX
    //         0046ac2f     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046ac32     ADD        ESP,0x4
    //         0046ac35     XOR        EDI,EDI
    //         0046ac37     TEST       EAX,EAX
    //         0046ac39     JLE        LAB_0046ac75
    //                              Path.cpp:153 (58)
    //         0046ac3b     XOR        EAX,EAX
    //         0046ac3d     LEA        this,[EBP + 0x8]
    //                               LAB_0046ac40                                                 XREF[1]:     0046ac73(j)  
    //         0046ac40     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046ac43     INC        EDI
    //         0046ac44     ADD        this,0x10
    //         0046ac47     MOV        EDX,dword ptr [EDX + EAX*0x1]
    //         0046ac4a     ADD        EAX,0x10
    //         0046ac4d     MOV        dword ptr [this->timeStampValue + -0x18],EDX
    //         0046ac50     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046ac53     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0xc]
    //         0046ac57     MOV        dword ptr [this->timeStampValue + -0x14],EDX
    //         0046ac5a     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046ac5d     MOV        EDX,dword ptr [EDX + EAX*0x1 + -0x8]
    //         0046ac61     MOV        dword ptr [this->timeStampValue + -0x10],EDX
    //         0046ac64     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046ac67     MOV        DL,byte ptr [EDX + EAX*0x1 + -0x4]
    //         0046ac6b     MOV        byte ptr [this->timeStampValue + -0xc],DL
    //         0046ac6e     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0046ac71     CMP        EDI,EDX
    //         0046ac73     JL         LAB_0046ac40
    //                               LAB_0046ac75                                                 XREF[1]:     0046ac39(j)  
    //                              Path.cpp:146 (21)
    //         0046ac75     MOV        EAX,dword ptr [ESI + 0x24]
    //         0046ac78     TEST       EAX,EAX
    //         0046ac7a     JZ         LAB_0046ac85
    //         0046ac7c     PUSH       EAX
    //         0046ac7d     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0046ac82     ADD        ESP,0x4
    //                               LAB_0046ac85                                                 XREF[1]:     0046ac7a(j)  
    //         0046ac85     MOV        dword ptr [ESI + 0x24],EBP
    //         0046ac88     POP        EBP
    //         0046ac89     POP        EDI
    //                               LAB_0046ac8a                                                 XREF[1]:     0046ac1b(j)  
    //                              Path.cpp:147 (16)
    //         0046ac8a     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046ac8d     MOV        this,dword ptr [ESI + 0x24]
    //         0046ac90     FLD        float ptr [ESP + param_1.x]
    //         0046ac94     SHL        EAX,0x4
    //         0046ac97     FSTP       float ptr [EAX + this->timeStampValue*0x1]
    //                              Path.cpp:148 (17)
    //         0046ac9a     MOV        EDX,dword ptr [ESI + 0x2c]
    //         0046ac9d     MOV        EAX,dword ptr [ESI + 0x24]
    //         0046aca0     FLD        float ptr [ESP + param_1.y]
    //         0046aca4     SHL        EDX,0x4
    //         0046aca7     FSTP       float ptr [EDX + EAX*0x1 + 0x4]
    //                              Path.cpp:149 (17)
    //         0046acab     MOV        this,dword ptr [ESI + 0x2c]
    //         0046acae     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046acb1     FLD        float ptr [ESP + param_1.z]
    //         0046acb5     SHL        this,0x4
    //         0046acb8     FSTP       float ptr [ECX + EDX*0x1 + this+0x8]
    //                              Path.cpp:150 (17)
    //         0046acbc     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046acbf     MOV        this,dword ptr [ESI + 0x24]
    //         0046acc2     MOV        DL,byte ptr [ESP + param_1.facetToNextWaypoint]
    //         0046acc6     SHL        EAX,0x4
    //         0046acc9     MOV        byte ptr [EAX + this->timeStampValue*0x1 + 0xc
    //                              Path.cpp:151 (7)
    //         0046accd     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046acd0     INC        EAX
    //         0046acd1     MOV        dword ptr [ESI + 0x2c],EAX
    //                              Path.cpp:152 (5)
    //         0046acd4     MOV        EAX,0x1
    //                              Path.cpp:153 (4)
    //         0046acd9     POP        ESI
    //         0046acda     RET        0x10
    //         0046acdd     ??         90h
    //         0046acde     NOP
    //         0046acdf     NOP
    //                              * public: int __thiscall Path::contains(struct Waypoint const &)const                                   *
    //                              int __thiscall contains(Path * this, Waypoint * param_1)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              Waypoint *        Stack[0x4]:4   param_1                   XREF[2]:     0046ad0e(R), 0046ad43(R)  
    //              undefined8        Stack[-0x10]:8 local_10                  XREF[4]:     0046ad15(W), 0046ad21(R), 0046ad4b(W), 0046ad57(R)  
    //              undefined8        Stack[-0x28]:8 local_28                  XREF[4]:     0046ad06(*), 0046ad19(*), 0046ad3b(*), 0046ad4f(*)  
    //                               ?contains@Path@@QBEHABUWaypoint@@@Z
    //                               Path::contains
    //                              Path.cpp:158 (13)
    //         0046ace0     PUSH       EBP
    //         0046ace1     MOV        EBP,ESP
    //         0046ace3     AND        ESP,0xfffffff8
    //         0046ace6     SUB        ESP,0xc
    //         0046ace9     PUSH       EBX
    //         0046acea     PUSH       ESI
    //         0046aceb     MOV        ESI,this
    //                              Path.cpp:159 (16)
    //         0046aced     XOR        EBX,EBX
    //         0046acef     PUSH       EDI
    //         0046acf0     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046acf3     TEST       EAX,EAX
    //         0046acf5     JLE        LAB_0046ad8b
    //         0046acfb     XOR        EDI,EDI
    //                               LAB_0046acfd                                                 XREF[1]:     0046ad70(j)  
    //                              Path.cpp:161 (106)
    //         0046acfd     MOV        EAX,dword ptr [ESI + 0x24]
    //         0046ad00     SUB        ESP,0x8
    //         0046ad03     FLD        float ptr [EAX + EDI*0x1]
    //         0046ad06     FSTP       double ptr [ESP]=>local_28
    //         0046ad09     CALL       floor                                            undefined floor()
    //         0046ad0e     MOV        this,dword ptr [EBP + param_1]
    //         0046ad11     FLD        float ptr [this->timeStampValue]
    //         0046ad13     FXCH
    //         0046ad15     FSTP       double ptr [ESP + local_10]
    //         0046ad19     FSTP       double ptr [ESP]=>local_28
    //         0046ad1c     CALL       floor                                            undefined floor()
    //         0046ad21     FLD        double ptr [ESP + local_10]
    //         0046ad25     FCOMPP
    //         0046ad27     ADD        ESP,0x8
    //         0046ad2a     FNSTSW     AX
    //         0046ad2c     TEST       AH,0x40
    //         0046ad2f     JZ         LAB_0046ad67
    //         0046ad31     MOV        EDX,dword ptr [ESI + 0x24]
    //         0046ad34     SUB        ESP,0x8
    //         0046ad37     FLD        float ptr [EDX + EDI*0x1 + 0x4]
    //         0046ad3b     FSTP       double ptr [ESP]=>local_28
    //         0046ad3e     CALL       floor                                            undefined floor()
    //         0046ad43     MOV        EAX,dword ptr [EBP + param_1]
    //         0046ad46     FLD        float ptr [EAX + 0x4]
    //         0046ad49     FXCH
    //         0046ad4b     FSTP       double ptr [ESP + local_10]
    //         0046ad4f     FSTP       double ptr [ESP]=>local_28
    //         0046ad52     CALL       floor                                            undefined floor()
    //         0046ad57     FLD        double ptr [ESP + local_10]
    //         0046ad5b     FCOMPP
    //         0046ad5d     ADD        ESP,0x8
    //         0046ad60     FNSTSW     AX
    //         0046ad62     TEST       AH,0x40
    //         0046ad65     JNZ        LAB_0046ad7d
    //                               LAB_0046ad67                                                 XREF[1]:     0046ad2f(j)  
    //                              Path.cpp:159 (11)
    //         0046ad67     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0046ad6a     INC        EBX
    //         0046ad6b     ADD        EDI,0x10
    //         0046ad6e     CMP        EBX,EAX
    //         0046ad70     JL         LAB_0046acfd
    //                              Path.cpp:165 (2)
    //         0046ad72     XOR        EAX,EAX
    //                              Path.cpp:166 (9)
    //         0046ad74     POP        EDI
    //         0046ad75     POP        ESI
    //         0046ad76     POP        EBX
    //         0046ad77     MOV        ESP,EBP
    //         0046ad79     POP        EBP
    //         0046ad7a     RET        0x4
    //                               LAB_0046ad7d                                                 XREF[1]:     0046ad65(j)  
    //                              Path.cpp:164 (5)
    //         0046ad7d     MOV        EAX,0x1
    //                              Path.cpp:166 (20)
    //         0046ad82     POP        EDI
    //         0046ad83     POP        ESI
    //         0046ad84     POP        EBX
    //         0046ad85     MOV        ESP,EBP
    //         0046ad87     POP        EBP
    //         0046ad88     RET        0x4
    //                               LAB_0046ad8b                                                 XREF[1]:     0046acf5(j)  
    //         0046ad8b     POP        EDI
    //         0046ad8c     POP        ESI
    //         0046ad8d     XOR        EAX,EAX
    //         0046ad8f     POP        EBX
    //         0046ad90     MOV        ESP,EBP
    //         0046ad92     POP        EBP
    //         0046ad93     RET        0x4
    //         0046ad96     ??         90h
    //         0046ad97     NOP
    //         0046ad98     NOP
    //         0046ad99     NOP
    //         0046ad9a     NOP
    //         0046ad9b     NOP
    //         0046ad9c     NOP
    //         0046ad9d     NOP
    //         0046ad9e     NOP
    //         0046ad9f     NOP
    return 0;
}

void Path::killPath() {
    /* TODO: Stub */
    //                              void __thiscall killPath(Path * this)
    //              void              <VOID>         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?killPath@Path@@QAEXXZ                                       XREF[8]:     findPath:0045d72e(c), 
    //                               Path::killPath                                                            findTilePath:0046b7d0(c), 
    //                                                                                                         findTilePath:0046b82b(c), 
    //                                                                                                         findTilePath:0046cb03(c), 
    //                                                                                                         findTilePath:0046ccf6(c), 
    //                                                                                                         findTilePath:0046cff4(c), 
    //                                                                                                         findTilePath:0046d1eb(c), 
    //                                                                                                         copyPath:0046d855(c)  
    //                              Path.cpp:183 (5)
    //         0046ada0     XOR        EAX,EAX
    //         0046ada2     MOV        dword ptr [ECX + this->currentSizeValue],EAX
    //                              Path.cpp:185 (3)
    //         0046ada5     MOV        dword ptr [ECX + this->currentWaypointValue],EAX
    //                              Path.cpp:186 (1)
    //         0046ada8     RET
    //         0046ada9     ??         90h
    //         0046adaa     NOP
    //         0046adab     NOP
    //         0046adac     NOP
    //         0046adad     NOP
    //         0046adae     NOP
    //         0046adaf     NOP
    //                              * public: int const __thiscall Path::maxNumberOfWaypoints(void)const                                    *
    //                              int __thiscall maxNumberOfWaypoints(Path * this)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?maxNumberOfWaypoints@Path@@QBE?BHXZ
    //                               Path::maxNumberOfWaypoints
    //                              Path.cpp:191 (3)
    //         0046adb0     MOV        EAX,dword ptr [ECX + this->maxSizeValue]
    //                              Path.cpp:193 (1)
    //         0046adb3     RET
    //         0046adb4     ??         90h
    //         0046adb5     NOP
    //         0046adb6     NOP
    //         0046adb7     NOP
    //         0046adb8     NOP
    //         0046adb9     NOP
    //         0046adba     NOP
    //         0046adbb     NOP
    //         0046adbc     NOP
    //         0046adbd     NOP
    //         0046adbe     NOP
    //         0046adbf     NOP
    //                              * public: int const __thiscall Path::numberOfWaypoints(void)const                                       *
    //                              int __thiscall numberOfWaypoints(Path * this)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?numberOfWaypoints@Path@@QBE?BHXZ                            XREF[35]:    save:0045ce85(c), 
    //                               Path::numberOfWaypoints                                                   doMove:0045e145(c), 
    //                                                                                                         doMove:0045e18c(c), 
    //                                                                                                         doMove:0045e1c2(c), 
    //                                                                                                         doMove:0045e2e7(c), 
    //                                                                                                         doMove:0045e346(c), 
    //                                                                                                         doMove:0045e65a(c), 
    //                                                                                                         doMove:0045e6a1(c), 
    //                                                                                                         doMove:0045e6d7(c), 
    //                                                                                                         doMove:0045e82f(c), 
    //                                                                                                         doMove:0045e88e(c), 
    //                                                                                                         doTrivialMove:0045f05e(c), 
    //                                                                                                         stuffAvoidancePath:0050227c(c), 
    //                                                                                                         stuffAvoidancePath:00502292(c), 
    //                                                                                                         stuffAvoidancePath:005022fe(c), 
    //                                                                                                         load_game:0052674e(c), 
    //                                                                                                         load_game:005267cc(c), 
    //                                                                                                         load_game:0052681a(c), 
    //                                                                                                         load_game:00526a7f(c), 
    //                                                                                                         load_game:00526afd(c), [more]
    //                              Path.cpp:198 (3)
    //         0046adc0     MOV        EAX,dword ptr [ECX + this->currentSizeValue]
    //                              Path.cpp:200 (1)
    //         0046adc3     RET
    //         0046adc4     ??         90h
    //         0046adc5     NOP
    //         0046adc6     NOP
    //         0046adc7     NOP
    //         0046adc8     NOP
    //         0046adc9     NOP
    //         0046adca     NOP
    //         0046adcb     NOP
    //         0046adcc     NOP
    //         0046adcd     NOP
    //         0046adce     NOP
    //         0046adcf     NOP
    //                              * public: unsigned long __thiscall Path::timeStamp(void)const                                           *
    //                              ulong __thiscall timeStamp(Path * this)
    //              ulong             EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?timeStamp@Path@@QBEKXZ
    //                               Path::timeStamp
    //                              Path.cpp:205 (2)
    //         0046add0     MOV        EAX,dword ptr [this->timeStampValue]
    //                              Path.cpp:207 (1)
    //         0046add2     RET
    //         0046add3     ??         90h
    //         0046add4     NOP
    //         0046add5     NOP
    //         0046add6     NOP
    //         0046add7     NOP
    //         0046add8     NOP
    //         0046add9     NOP
    //         0046adda     NOP
    //         0046addb     NOP
    //         0046addc     NOP
    //         0046addd     NOP
    //         0046adde     NOP
    //         0046addf     NOP
    return;
}

void Path::setTimeStamp(ulong param_1) {
    /* TODO: Stub */
    //                              void __thiscall setTimeStamp(Path * this, ulong param_1)
    //              void              <VOID>         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              ulong             Stack[0x4]:4   param_1                   XREF[1]:     0046ade0(R)  
    //                               ?setTimeStamp@Path@@QAEXK@Z                                  XREF[2]:     findPath:0045d727(c), 
    //                               Path::setTimeStamp                                                        findPath:0045dacb(c)  
    //                              Path.cpp:212 (6)
    //         0046ade0     MOV        EAX,dword ptr [ESP + param_1]
    //         0046ade4     MOV        dword ptr [this->timeStampValue],EAX
    //                              Path.cpp:214 (3)
    //         0046ade6     RET        0x4
    //         0046ade9     ??         90h
    //         0046adea     NOP
    //         0046adeb     NOP
    //         0046adec     NOP
    //         0046aded     NOP
    //         0046adee     NOP
    //         0046adef     NOP
    //                              * public: float __thiscall Path::length(void)const                                                      *
    //                              float __thiscall length(Path * this)
    //              float             ST0:10         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0046ae2b(*), 0046ae37(*)  
    //                               ?length@Path@@QBEMXZ                                         XREF[1]:     stuffAvoidancePath:0050223b(c)  
    //                               Path::length
    //                              Path.cpp:219 (1)
    //         0046adf0     PUSH       this
    //                              Path.cpp:221 (23)
    //         0046adf1     MOV        EDX,dword ptr [ECX + this->currentSizeValue]
    //         0046adf4     FLD        float ptr [DAT_00570e40]                         = align(8)
    //         0046adfa     CMP        EDX,0x1
    //         0046adfd     JLE        LAB_0046ae49
    //         0046adff     MOV        EAX,dword ptr [ECX + this->pathValue]
    //         0046ae02     LEA        this,[EDX + -0x1]
    //         0046ae05     ADD        EAX,0x10
    //                               LAB_0046ae08                                                 XREF[1]:     0046ae47(j)  
    //                              Path.cpp:226 (65)
    //         0046ae08     FLD        float ptr [EAX]
    //         0046ae0a     FSUB       float ptr [EAX + -0x10]
    //         0046ae0d     FLD        float ptr [EAX + 0x4]
    //         0046ae10     FLD        float ptr [EAX + 0x8]
    //         0046ae13     FLD        float ptr [EAX + 0x8]
    //         0046ae16     FXCH       ST2
    //         0046ae18     FSUB       float ptr [EAX + -0xc]
    //         0046ae1b     FXCH
    //         0046ae1d     FSUB       float ptr [EAX + -0x8]
    //         0046ae20     FXCH       ST2
    //         0046ae22     FSUB       float ptr [EAX + -0x10]
    //         0046ae25     FLD        ST3
    //         0046ae27     FMUL       ST4
    //         0046ae29     FXCH       ST2
    //         0046ae2b     FST        float ptr [ESP]=>local_4
    //         0046ae2f     FXCH
    //         0046ae31     FMULP      ST3
    //         0046ae33     ADD        EAX,0x10
    //         0046ae36     DEC        this
    //         0046ae37     FMUL       float ptr [ESP]=>local_4
    //         0046ae3b     FXCH
    //         0046ae3d     FADDP      ST2,ST0
    //         0046ae3f     FADDP
    //         0046ae41     FSQRT
    //         0046ae43     FSTP       ST1
    //         0046ae45     FADDP
    //         0046ae47     JNZ        LAB_0046ae08
    //                               LAB_0046ae49                                                 XREF[1]:     0046adfd(j)  
    //                              Path.cpp:229 (2)
    //         0046ae49     POP        this
    //         0046ae4a     RET
    //         0046ae4b     ??         90h
    //         0046ae4c     NOP
    //         0046ae4d     NOP
    //         0046ae4e     NOP
    //         0046ae4f     NOP
    //                              * public: struct Waypoint const & __thiscall Path::start(void)const                                     *
    //                              Waypoint * __thiscall start(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?start@Path@@QBEABUWaypoint@@XZ
    //                               Path::start
    //                              Path.cpp:234 (3)
    //         0046ae50     LEA        EAX,[ECX + this->startValue.x]
    //                              Path.cpp:236 (1)
    //         0046ae53     RET
    //         0046ae54     ??         90h
    //         0046ae55     NOP
    //         0046ae56     NOP
    //         0046ae57     NOP
    //         0046ae58     NOP
    //         0046ae59     NOP
    //         0046ae5a     NOP
    //         0046ae5b     NOP
    //         0046ae5c     NOP
    //         0046ae5d     NOP
    //         0046ae5e     NOP
    //         0046ae5f     NOP
    //                              * public: struct Waypoint const & __thiscall Path::goal(void)const                                      *
    //                              Waypoint * __thiscall goal(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?goal@Path@@QBEABUWaypoint@@XZ
    //                               Path::goal
    //                              Path.cpp:241 (3)
    //         0046ae60     LEA        EAX,[ECX + this->goalValue.x]
    //                              Path.cpp:243 (1)
    //         0046ae63     RET
    //         0046ae64     ??         90h
    //         0046ae65     NOP
    //         0046ae66     NOP
    //         0046ae67     NOP
    //         0046ae68     NOP
    //         0046ae69     NOP
    //         0046ae6a     NOP
    //         0046ae6b     NOP
    //         0046ae6c     NOP
    //         0046ae6d     NOP
    //         0046ae6e     NOP
    //         0046ae6f     NOP
    //                              * public: struct Waypoint const * __thiscall Path::waypoint(int)const                                   *
    //                              Waypoint * __thiscall waypoint(Path * this, int param_1)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046ae77(R)  
    //                               ?waypoint@Path@@QBEPBUWaypoint@@H@Z                          XREF[1]:     save:0045cead(c)  
    //                               Path::waypoint
    //                              Path.cpp:248 (21)
    //         0046ae70     MOV        EDX,dword ptr [ECX + this->pathValue]
    //         0046ae73     TEST       EDX,EDX
    //         0046ae75     JZ         LAB_0046ae8d
    //         0046ae77     MOV        EAX,dword ptr [ESP + param_1]
    //         0046ae7b     CMP        EAX,-0x1
    //         0046ae7e     JLE        LAB_0046ae8d
    //         0046ae80     CMP        EAX,dword ptr [ECX + this->currentSizeValue]
    //         0046ae83     JGE        LAB_0046ae8d
    //                              Path.cpp:250 (5)
    //         0046ae85     SHL        EAX,0x4
    //         0046ae88     ADD        EAX,EDX
    //                              Path.cpp:252 (3)
    //         0046ae8a     RET        0x4
    //                               LAB_0046ae8d                                                 XREF[3]:     0046ae75(j), 0046ae7e(j), 
    //                                                                                                         0046ae83(j)  
    //                              Path.cpp:251 (2)
    //         0046ae8d     XOR        EAX,EAX
    //                              Path.cpp:252 (3)
    //         0046ae8f     RET        0x4
    //         0046ae92     ??         90h
    //         0046ae93     NOP
    //         0046ae94     NOP
    //         0046ae95     NOP
    //         0046ae96     NOP
    //         0046ae97     NOP
    //         0046ae98     NOP
    //         0046ae99     NOP
    //         0046ae9a     NOP
    //         0046ae9b     NOP
    //         0046ae9c     NOP
    //         0046ae9d     NOP
    //         0046ae9e     NOP
    //         0046ae9f     NOP
    //                              * public: struct Waypoint * __thiscall Path::currentWaypoint(void)const                                 *
    //                              Waypoint * __thiscall currentWaypoint(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?currentWaypoint@Path@@QBEPAUWaypoint@@XZ                    XREF[67]:    facetToNextWaypoint:0045d629(c), 
    //                               Path::currentWaypoint                                                     facetToNextWaypoint:0045d634(c), 
    //                                                                                                         doMove:0045dc9b(c), 
    //                                                                                                         doMove:0045dca6(c), 
    //                                                                                                         doMove:0045dcb6(c), 
    //                                                                                                         doMove:0045dd91(c), 
    //                                                                                                         doMove:0045dda0(c), 
    //                                                                                                         doMove:0045ddb0(c), 
    //                                                                                                         doMove:0045dddf(c), 
    //                                                                                                         doMove:0045ddea(c), 
    //                                                                                                         doMove:0045de03(c), 
    //                                                                                                         doMove:0045de0e(c), 
    //                                                                                                         doMove:0045de19(c), 
    //                                                                                                         stuffAvoidancePath:005022cb(c), 
    //                                                                                                         stuffAvoidancePath:005022d6(c), 
    //                                                                                                         load_game:005267d7(c), 
    //                                                                                                         load_game:005267e4(c), 
    //                                                                                                         load_game:005267f4(c), 
    //                                                                                                         load_game:00526b08(c), 
    //                                                                                                         load_game:00526b15(c), [more]
    //                              Path.cpp:257 (20)
    //         0046aea0     MOV        EDX,dword ptr [ECX + this->pathValue]
    //         0046aea3     TEST       EDX,EDX
    //         0046aea5     JZ         LAB_0046aeba
    //         0046aea7     MOV        EAX,dword ptr [ECX + this->currentWaypointValue]
    //         0046aeaa     CMP        EAX,-0x1
    //         0046aead     JLE        LAB_0046aeba
    //         0046aeaf     CMP        EAX,dword ptr [ECX + this->currentSizeValue]
    //         0046aeb2     JGE        LAB_0046aeba
    //                              Path.cpp:260 (5)
    //         0046aeb4     SHL        EAX,0x4
    //         0046aeb7     ADD        EAX,EDX
    //                              Path.cpp:262 (1)
    //         0046aeb9     RET
    //                               LAB_0046aeba                                                 XREF[3]:     0046aea5(j), 0046aead(j), 
    //                                                                                                         0046aeb2(j)  
    //                              Path.cpp:261 (2)
    //         0046aeba     XOR        EAX,EAX
    //                              Path.cpp:262 (1)
    //         0046aebc     RET
    //         0046aebd     ??         90h
    //         0046aebe     NOP
    //         0046aebf     NOP
    //                              * public: int const __thiscall Path::currentWaypointNumber(void)const                                   *
    //                              int __thiscall currentWaypointNumber(Path * this)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?currentWaypointNumber@Path@@QBE?BHXZ                        XREF[2]:     save:0045cec7(c), 
    //                               Path::currentWaypointNumber                                               get_waypoint_checksum:00460f54(c)  
    //                              Path.cpp:267 (3)
    //         0046aec0     MOV        EAX,dword ptr [ECX + this->currentWaypointValue]
    //                              Path.cpp:269 (1)
    //         0046aec3     RET
    //         0046aec4     ??         90h
    //         0046aec5     NOP
    //         0046aec6     NOP
    //         0046aec7     NOP
    //         0046aec8     NOP
    //         0046aec9     NOP
    //         0046aeca     NOP
    //         0046aecb     NOP
    //         0046aecc     NOP
    //         0046aecd     NOP
    //         0046aece     NOP
    //         0046aecf     NOP
    return;
}

void Path::setCurrentWaypointNumber(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall setCurrentWaypointNumber(Path * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0046aed0(R)  
    //                               ?setCurrentWaypointNumber@Path@@QAEXH@Z                      XREF[1]:     get_waypoint_checksum:00460fa4(c)  
    //                               Path::setCurrentWaypointNumber
    //                              Path.cpp:274 (7)
    //         0046aed0     MOV        EAX,dword ptr [ESP + param_1]
    //         0046aed4     MOV        dword ptr [ECX + this->currentWaypointValue],EAX
    //                              Path.cpp:276 (3)
    //         0046aed7     RET        0x4
    //         0046aeda     ??         90h
    //         0046aedb     NOP
    //         0046aedc     NOP
    //         0046aedd     NOP
    //         0046aede     NOP
    //         0046aedf     NOP
    //                              * public: struct Waypoint const * __thiscall Path::nextWaypoint(void)const                              *
    //                              Waypoint * __thiscall nextWaypoint(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?nextWaypoint@Path@@QBEPBUWaypoint@@XZ
    //                               Path::nextWaypoint
    //                              Path.cpp:281 (24)
    //         0046aee0     MOV        EDX,dword ptr [ECX + this->pathValue]
    //         0046aee3     PUSH       ESI
    //         0046aee4     TEST       EDX,EDX
    //         0046aee6     JZ         LAB_0046aeff
    //         0046aee8     MOV        EAX,dword ptr [ECX + this->currentWaypointValue]
    //         0046aeeb     CMP        EAX,-0x1
    //         0046aeee     JLE        LAB_0046aeff
    //         0046aef0     MOV        ESI,dword ptr [ECX + this->currentSizeValue]
    //         0046aef3     INC        EAX
    //         0046aef4     CMP        EAX,ESI
    //         0046aef6     JGE        LAB_0046aeff
    //                              Path.cpp:284 (5)
    //         0046aef8     SHL        EAX,0x4
    //         0046aefb     ADD        EAX,EDX
    //                              Path.cpp:286 (2)
    //         0046aefd     POP        ESI
    //         0046aefe     RET
    //                               LAB_0046aeff                                                 XREF[3]:     0046aee6(j), 0046aeee(j), 
    //                                                                                                         0046aef6(j)  
    //                              Path.cpp:285 (2)
    //         0046aeff     XOR        EAX,EAX
    //                              Path.cpp:286 (2)
    //         0046af01     POP        ESI
    //         0046af02     RET
    //         0046af03     ??         90h
    //         0046af04     NOP
    //         0046af05     NOP
    //         0046af06     NOP
    //         0046af07     NOP
    //         0046af08     NOP
    //         0046af09     NOP
    //         0046af0a     NOP
    //         0046af0b     NOP
    //         0046af0c     NOP
    //         0046af0d     NOP
    //         0046af0e     NOP
    //         0046af0f     NOP
    //                              * public: struct Waypoint const * __thiscall Path::previousWaypoint(void)const                          *
    //                              Waypoint * __thiscall previousWaypoint(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?previousWaypoint@Path@@QBEPBUWaypoint@@XZ
    //                               Path::previousWaypoint
    //                              Path.cpp:291 (23)
    //         0046af10     MOV        EDX,dword ptr [ECX + this->pathValue]
    //         0046af13     PUSH       ESI
    //         0046af14     TEST       EDX,EDX
    //         0046af16     JZ         LAB_0046af30
    //         0046af18     MOV        EAX,dword ptr [ECX + this->currentWaypointValue]
    //         0046af1b     LEA        ESI,[EAX + 0x1]
    //         0046af1e     TEST       ESI,ESI
    //         0046af20     JLE        LAB_0046af30
    //         0046af22     CMP        EAX,dword ptr [ECX + this->currentSizeValue]
    //         0046af25     JGE        LAB_0046af30
    //                              Path.cpp:294 (7)
    //         0046af27     SHL        EAX,0x4
    //         0046af2a     LEA        EAX,[EAX + EDX*0x1 + -0x10]
    //                              Path.cpp:296 (2)
    //         0046af2e     POP        ESI
    //         0046af2f     RET
    //                               LAB_0046af30                                                 XREF[3]:     0046af16(j), 0046af20(j), 
    //                                                                                                         0046af25(j)  
    //                              Path.cpp:295 (2)
    //         0046af30     XOR        EAX,EAX
    //                              Path.cpp:296 (2)
    //         0046af32     POP        ESI
    //         0046af33     RET
    //         0046af34     ??         90h
    //         0046af35     NOP
    //         0046af36     NOP
    //         0046af37     NOP
    //         0046af38     NOP
    //         0046af39     NOP
    //         0046af3a     NOP
    //         0046af3b     NOP
    //         0046af3c     NOP
    //         0046af3d     NOP
    //         0046af3e     NOP
    //         0046af3f     NOP
    //                              * public: struct Waypoint const * __thiscall Path::firstWaypoint(void)const                             *
    //                              Waypoint * __thiscall firstWaypoint(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?firstWaypoint@Path@@QBEPBUWaypoint@@XZ
    //                               Path::firstWaypoint
    //                              Path.cpp:301 (12)
    //         0046af40     MOV        EAX,dword ptr [ECX + this->pathValue]
    //         0046af43     TEST       EAX,EAX
    //         0046af45     JZ         LAB_0046af4e
    //         0046af47     MOV        EDX,dword ptr [ECX + this->currentSizeValue]
    //         0046af4a     TEST       EDX,EDX
    //                              Path.cpp:303 (2)
    //         0046af4c     JG         LAB_0046af50
    //                               LAB_0046af4e                                                 XREF[1]:     0046af45(j)  
    //                              Path.cpp:304 (2)
    //         0046af4e     XOR        EAX,EAX
    //                               LAB_0046af50                                                 XREF[1]:     0046af4c(j)  
    //                              Path.cpp:305 (1)
    //         0046af50     RET
    //         0046af51     ??         90h
    //         0046af52     NOP
    //         0046af53     NOP
    //         0046af54     NOP
    //         0046af55     NOP
    //         0046af56     NOP
    //         0046af57     NOP
    //         0046af58     NOP
    //         0046af59     NOP
    //         0046af5a     NOP
    //         0046af5b     NOP
    //         0046af5c     NOP
    //         0046af5d     NOP
    //         0046af5e     NOP
    //         0046af5f     NOP
    //                              * public: struct Waypoint const * __thiscall Path::lastWaypoint(void)const                              *
    //                              Waypoint * __thiscall lastWaypoint(Path * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?lastWaypoint@Path@@QBEPBUWaypoint@@XZ                       XREF[4]:     canBidirectionPath:0045fda9(c), 
    //                               Path::lastWaypoint                                                        canBidirectionPath:0045fdb9(c), 
    //                                                                                                         canBidirectionPath:0045fe87(c), 
    //                                                                                                         canBidirectionPath:0045fe97(c)  
    //                              Path.cpp:310 (14)
    //         0046af60     MOV        EDX,dword ptr [ECX + this->pathValue]
    //         0046af63     TEST       EDX,EDX
    //         0046af65     JZ         LAB_0046af76
    //         0046af67     MOV        EAX,dword ptr [ECX + this->currentSizeValue]
    //         0046af6a     TEST       EAX,EAX
    //         0046af6c     JLE        LAB_0046af76
    //                              Path.cpp:312 (7)
    //         0046af6e     SHL        EAX,0x4
    //         0046af71     LEA        EAX,[EAX + EDX*0x1 + -0x10]
    //                              Path.cpp:314 (1)
    //         0046af75     RET
    //                               LAB_0046af76                                                 XREF[2]:     0046af65(j), 0046af6c(j)  
    //                              Path.cpp:313 (2)
    //         0046af76     XOR        EAX,EAX
    //                              Path.cpp:314 (1)
    //         0046af78     RET
    //         0046af79     ??         90h
    //         0046af7a     NOP
    //         0046af7b     NOP
    //         0046af7c     NOP
    //         0046af7d     NOP
    //         0046af7e     NOP
    //         0046af7f     NOP
    return;
}

void Path::initToStart() {
    /* TODO: Stub */
    //                              void __thiscall initToStart(Path * this)
    //              void              <VOID>         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?initToStart@Path@@QAEXXZ                                    XREF[30]:    setup:0045cb9f(c), 
    //                               Path::initToStart                                                         doMove:0045e13c(c), 
    //                                                                                                         doMove:0045e1aa(c), 
    //                                                                                                         doMove:0045e2dc(c), 
    //                                                                                                         doMove:0045e351(c), 
    //                                                                                                         doMove:0045e361(c), 
    //                                                                                                         doMove:0045e651(c), 
    //                                                                                                         doMove:0045e6bf(c), 
    //                                                                                                         doMove:0045e824(c), 
    //                                                                                                         doMove:0045e899(c), 
    //                                                                                                         doMove:0045e8a7(c), 
    //                                                                                                         doTrivialMove:0045f055(c), 
    //                                                                                                         doTrivialMove:0045f0c3(c), 
    //                                                                                                         doTrivialMove:0045f205(c), 
    //                                                                                                         doTrivialMove:0045f288(c), 
    //                                                                                                         copyPath:0046d901(c), 
    //                                                                                                         stuffAvoidancePath:00502261(c), 
    //                                                                                                         load_game:0052675d(c), 
    //                                                                                                         load_game:00526825(c), 
    //                                                                                                         load_game:00526a8e(c), [more]
    //                              Path.cpp:319 (7)
    //         0046af80     MOV        dword ptr [ECX + this->currentWaypointValue],0x0
    //                              Path.cpp:321 (1)
    //         0046af87     RET
    //         0046af88     ??         90h
    //         0046af89     NOP
    //         0046af8a     NOP
    //         0046af8b     NOP
    //         0046af8c     NOP
    //         0046af8d     NOP
    //         0046af8e     NOP
    //         0046af8f     NOP
    return;
}

void Path::initToEnd() {
    /* TODO: Stub */
    //                              void __thiscall initToEnd(Path * this)
    //              void              <VOID>         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?initToEnd@Path@@QAEXXZ
    //                               Path::initToEnd
    //                              Path.cpp:326 (7)
    //         0046af90     MOV        EAX,dword ptr [ECX + this->currentSizeValue]
    //         0046af93     DEC        EAX
    //         0046af94     MOV        dword ptr [ECX + this->currentWaypointValue],EAX
    //                              Path.cpp:328 (1)
    //         0046af97     RET
    //         0046af98     ??         90h
    //         0046af99     NOP
    //         0046af9a     NOP
    //         0046af9b     NOP
    //         0046af9c     NOP
    //         0046af9d     NOP
    //         0046af9e     NOP
    //         0046af9f     NOP
    return;
}

int Path::moveToNextWaypoint() {
    /* TODO: Stub */
    //                              int __thiscall moveToNextWaypoint(Path * this)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?moveToNextWaypoint@Path@@QAEHXZ                             XREF[33]:    setup:0045cbae(c), 
    //                               Path::moveToNextWaypoint                                                  doMove:0045de2a(c), 
    //                                                                                                         doMove:0045e185(c), 
    //                                                                                                         doMove:0045e1b1(c), 
    //                                                                                                         doMove:0045e33f(c), 
    //                                                                                                         doMove:0045e358(c), 
    //                                                                                                         doMove:0045e368(c), 
    //                                                                                                         doMove:0045e44e(c), 
    //                                                                                                         doMove:0045e69a(c), 
    //                                                                                                         doMove:0045e6c6(c), 
    //                                                                                                         doMove:0045e887(c), 
    //                                                                                                         doMove:0045e8a0(c), 
    //                                                                                                         doMove:0045e8ae(c), 
    //                                                                                                         doTrivialMove:0045f09e(c), 
    //                                                                                                         doTrivialMove:0045f0ca(c), 
    //                                                                                                         stuffAvoidancePath:00502273(c), 
    //                                                                                                         stuffAvoidancePath:005022f7(c), 
    //                                                                                                         load_game:00526813(c), 
    //                                                                                                         load_game:0052682c(c), 
    //                                                                                                         load_game:00526b44(c), [more]
    //                              Path.cpp:333 (11)
    //         0046afa0     MOV        EAX,dword ptr [ECX + this->currentSizeValue]
    //         0046afa3     MOV        EDX,dword ptr [ECX + this->currentWaypointValue]
    //         0046afa6     DEC        EAX
    //         0046afa7     CMP        EDX,EAX
    //         0046afa9     JGE        LAB_0046afb5
    //                              Path.cpp:337 (1)
    //         0046afab     INC        EDX
    //                              Path.cpp:338 (8)
    //         0046afac     MOV        EAX,0x1
    //         0046afb1     MOV        dword ptr [ECX + this->currentWaypointValue],EDX
    //                              Path.cpp:342 (1)
    //         0046afb4     RET
    //                               LAB_0046afb5                                                 XREF[1]:     0046afa9(j)  
    //                              Path.cpp:340 (3)
    //         0046afb5     MOV        dword ptr [ECX + this->currentWaypointValue],EAX
    //                              Path.cpp:341 (2)
    //         0046afb8     XOR        EAX,EAX
    //                              Path.cpp:342 (1)
    //         0046afba     RET
    //         0046afbb     ??         90h
    //         0046afbc     NOP
    //         0046afbd     NOP
    //         0046afbe     NOP
    //         0046afbf     NOP
    return 0;
}

int Path::moveToLastWaypoint() {
    /* TODO: Stub */
    //                              int __thiscall moveToLastWaypoint(Path * this)
    //              int               EAX:4          <RETURN>
    //              Path *            ECX:4 (auto)   this
    //                               ?moveToLastWaypoint@Path@@QAEHXZ
    //                               Path::moveToLastWaypoint
    //                              Path.cpp:347 (7)
    //         0046afc0     MOV        EAX,dword ptr [ECX + this->currentWaypointValue]
    //         0046afc3     TEST       EAX,EAX
    //         0046afc5     JLE        LAB_0046afd1
    //                              Path.cpp:349 (4)
    //         0046afc7     DEC        EAX
    //         0046afc8     MOV        dword ptr [ECX + this->currentWaypointValue],EAX
    //                              Path.cpp:350 (5)
    //         0046afcb     MOV        EAX,0x1
    //                              Path.cpp:353 (1)
    //         0046afd0     RET
    //                               LAB_0046afd1                                                 XREF[1]:     0046afc5(j)  
    //                              Path.cpp:352 (2)
    //         0046afd1     XOR        EAX,EAX
    //                              Path.cpp:353 (1)
    //         0046afd3     RET
    //         0046afd4     ??         90h
    //         0046afd5     NOP
    //         0046afd6     NOP
    //         0046afd7     NOP
    //         0046afd8     NOP
    //         0046afd9     NOP
    //         0046afda     NOP
    //         0046afdb     NOP
    //         0046afdc     NOP
    //         0046afdd     NOP
    //         0046afde     NOP
    //         0046afdf     NOP
    //                              * public: float __thiscall Path::distanceToNextWaypoint(void)const                                      *
    //                              float __thiscall distanceToNextWaypoint(Path * this)
    //              float             ST0:10         <RETURN>
    //              Path *            ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0046b023(W), 0046b02b(R), 0046b035(W), 0046b039(R)  
    //                               ?distanceToNextWaypoint@Path@@QBEMXZ                         XREF[2]:     stuffAvoidancePath:00502268(c), 
    //                               Path::distanceToNextWaypoint                                              stuffAvoidancePath:005022e7(c)  
    //                              Path.cpp:358 (1)
    //         0046afe0     PUSH       this
    //                              Path.cpp:361 (28)
    //         0046afe1     MOV        EDX,dword ptr [ECX + this->pathValue]
    //         0046afe4     FLD        float ptr [DAT_00570e40]                         = align(8)
    //         0046afea     TEST       EDX,EDX
    //         0046afec     JZ         LAB_0046b04c
    //         0046afee     MOV        EAX,dword ptr [ECX + this->currentWaypointValue]
    //         0046aff1     TEST       EAX,EAX
    //         0046aff3     JL         LAB_0046b04c
    //         0046aff5     MOV        this,dword ptr [ECX + this->currentSizeValue]
    //         0046aff8     DEC        this
    //         0046aff9     CMP        EAX,this
    //         0046affb     JGE        LAB_0046b04c
    //                              Path.cpp:365 (79)
    //         0046affd     MOV        this,EAX
    //         0046afff     PUSH       ESI
    //         0046b000     SHL        this,0x4
    //         0046b003     LEA        ESI,[EAX + 0x1]
    //         0046b006     LEA        EAX,[this->timeStampValue + EDX*0x1]
    //         0046b009     FSTP       ST0
    //         0046b00b     FLD        float ptr [EAX + 0x14]
    //         0046b00e     SHL        ESI,0x4
    //         0046b011     FLD        float ptr [ESI + EDX*0x1]
    //         0046b014     FSUB       float ptr [EAX]
    //         0046b016     FXCH
    //         0046b018     FSUB       float ptr [EAX + 0x4]
    //         0046b01b     FLD        float ptr [EAX + 0x18]
    //         0046b01e     FSUB       float ptr [EAX + 0x8]
    //         0046b021     FXCH       ST2
    //         0046b023     FST        float ptr [ESP + local_4]
    //         0046b027     FLD        ST1
    //         0046b029     FXCH
    //         0046b02b     FMUL       float ptr [ESP + local_4]
    //         0046b02f     FXCH
    //         0046b031     FMUL       ST2
    //         0046b033     FXCH       ST3
    //         0046b035     FST        float ptr [ESP + local_4]
    //         0046b039     FMUL       float ptr [ESP + local_4]
    //         0046b03d     FXCH       ST3
    //         0046b03f     FADDP
    //         0046b041     FXCH       ST2
    //         0046b043     FADDP      ST2,ST0
    //         0046b045     FXCH
    //         0046b047     POP        ESI
    //         0046b048     FSQRT
    //         0046b04a     FSTP       ST1
    //                               LAB_0046b04c                                                 XREF[3]:     0046afec(j), 0046aff3(j), 
    //                                                                                                         0046affb(j)  
    //                              Path.cpp:367 (2)
    //         0046b04c     POP        this
    //         0046b04d     RET
    //         0046b04e     ??         90h
    //         0046b04f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E12()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E12
    //         0046b050     CALL       $E9                                              undefined $E9()
    //         0046b055     JMP        $E11                                             undefined $E11()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0046b05a     ??         90h
    //         0046b05b     NOP
    //         0046b05c     NOP
    //         0046b05d     NOP
    //         0046b05e     NOP
    //         0046b05f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E9                                                          XREF[1]:     $E12:0046b050(c)  
    //                              pathsys.cpp:58 (27)
    //         0046b060     PUSH       0x0
    //         0046b062     PUSH       0x0
    //         0046b064     PUSH       0x0
    //         0046b066     PUSH       0xff
    //         0046b06b     PUSH       0xff
    //         0046b070     MOV        ECX,pathSystem
    //         0046b075     CALL       PathingSystem::PathingSystem                     undefined PathingSystem(PathingSystem * this,
    //         0046b07a     RET
    //         0046b07b     ??         90h
    //         0046b07c     NOP
    //         0046b07d     NOP
    //         0046b07e     NOP
    //         0046b07f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E11()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E11                                                         XREF[1]:     $E12:0046b055(c)  
    //         0046b080     PUSH       $E10
    //         0046b085     CALL       atexit                                           undefined atexit()
    //         0046b08a     ADD        ESP,0x4
    //         0046b08d     RET
    //         0046b08e     ??         90h
    //         0046b08f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E10()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E10                                                         XREF[1]:     $E11:0046b080(*)  
    //         0046b090     MOV        ECX,pathSystem
    //         0046b095     JMP        PathingSystem::~PathingSystem                    void ~PathingSystem(PathingSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0046b09a     ??         90h
    //         0046b09b     NOP
    //         0046b09c     NOP
    //         0046b09d     NOP
    //         0046b09e     NOP
    //         0046b09f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E17()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E17
    //         0046b0a0     CALL       $E14                                             undefined $E14()
    //         0046b0a5     JMP        $E16                                             undefined $E16()
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0046b0aa     ??         90h
    //         0046b0ab     NOP
    //         0046b0ac     NOP
    //         0046b0ad     NOP
    //         0046b0ae     NOP
    //         0046b0af     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E14()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E14                                                         XREF[1]:     $E17:0046b0a0(c)  
    //                              pathsys.cpp:60 (27)
    //         0046b0b0     PUSH       0x0
    //         0046b0b2     PUSH       0x0
    //         0046b0b4     PUSH       0x1
    //         0046b0b6     PUSH       0xff
    //         0046b0bb     PUSH       0xff
    //         0046b0c0     MOV        ECX,aiPathSystem
    //         0046b0c5     CALL       PathingSystem::PathingSystem                     undefined PathingSystem(PathingSystem * this,
    //         0046b0ca     RET
    //         0046b0cb     ??         90h
    //         0046b0cc     NOP
    //         0046b0cd     NOP
    //         0046b0ce     NOP
    //         0046b0cf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E16()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E16                                                         XREF[1]:     $E17:0046b0a5(c)  
    //         0046b0d0     PUSH       $E15
    //         0046b0d5     CALL       atexit                                           undefined atexit()
    //         0046b0da     ADD        ESP,0x4
    //         0046b0dd     RET
    //         0046b0de     ??         90h
    //         0046b0df     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined $E15()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               $E15                                                         XREF[1]:     $E16:0046b0d0(*)  
    //         0046b0e0     MOV        ECX,aiPathSystem
    //         0046b0e5     JMP        PathingSystem::~PathingSystem                    void ~PathingSystem(PathingSystem * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0046b0ea     ??         90h
    //         0046b0eb     NOP
    //         0046b0ec     NOP
    //         0046b0ed     NOP
    //         0046b0ee     NOP
    //         0046b0ef     NOP
    return 0;
}

Path* Path::operator+(Path* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int Path::operator==(Path* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int Path::contains(Waypoint* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int Path::maxNumberOfWaypoints() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int Path::numberOfWaypoints() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

ulong Path::timeStamp() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

float Path::length() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::start() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::goal() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::waypoint(int param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::currentWaypoint() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int Path::currentWaypointNumber() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::nextWaypoint() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::previousWaypoint() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::firstWaypoint() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

Waypoint* Path::lastWaypoint() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

float Path::distanceToNextWaypoint() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

