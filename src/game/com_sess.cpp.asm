#include "common.h"
#include "com_sess.h"

TCommunications_Sessions::~TCommunications_Sessions() {
    /* TODO: Stub */
    //                              void __thiscall ~TCommunications_Sessions(TCommunications_Sessions *
    //              void              <VOID>         <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //                               ??1TCommunications_Sessions@@QAE@XZ                          XREF[1]:     ~TribeJoinScreen:004919c8(c)  
    //                               TCommunications_Sessions::~TCommunications_Sessions
    //                              com_sess.cpp:38 (1)
    //         00432290     RET
    //         00432291     ??         90h
    //         00432292     NOP
    //         00432293     NOP
    //         00432294     NOP
    //         00432295     NOP
    //         00432296     NOP
    //         00432297     NOP
    //         00432298     NOP
    //         00432299     NOP
    //         0043229a     NOP
    //         0043229b     NOP
    //         0043229c     NOP
    //         0043229d     NOP
    //         0043229e     NOP
    //         0043229f     NOP
}

void TCommunications_Sessions::EraseInformation() {
    /* TODO: Stub */
    //                              void __thiscall EraseInformation(TCommunications_Sessions * this)
    //              void              <VOID>         <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //                               ?EraseInformation@TCommunications_Sessions@@AAEXXZ           XREF[2]:     TCommunications_Sessions:00432274(
    //                               TCommunications_Sessions::EraseInformation                                Refresh:004324f7(c)  
    //                              com_sess.cpp:45 (3)
    //         004322a0     MOV        EDX,this
    //         004322a2     PUSH       EDI
    //                              com_sess.cpp:50 (18)
    //         004322a3     MOV        this,0x115e6
    //         004322a8     XOR        EAX,EAX
    //         004322aa     LEA        EDI,[EDX + 0x4]
    //         004322ad     MOV        dword ptr [EDX],0x0
    //         004322b3     STOSD.REP  ES:EDI
    //                              com_sess.cpp:51 (2)
    //         004322b5     POP        EDI
    //         004322b6     RET
    //         004322b7     ??         90h
    //         004322b8     NOP
    //         004322b9     NOP
    //         004322ba     NOP
    //         004322bb     NOP
    //         004322bc     NOP
    //         004322bd     NOP
    //         004322be     NOP
    //         004322bf     NOP
    return;
}

int TCommunications_Sessions::GetSessionCount() {
    /* TODO: Stub */
    //                              int __thiscall GetSessionCount(TCommunications_Sessions * this)
    //              int               EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //                               ?GetSessionCount@TCommunications_Sessions@@QAEHXZ            XREF[1]:     fillList:00491d63(c)  
    //                               TCommunications_Sessions::GetSessionCount
    //                              com_sess.cpp:54 (2)
    //         004322c0     MOV        EAX,dword ptr [this->SessionCount]
    //                              com_sess.cpp:60 (1)
    //         004322c2     RET
    //         004322c3     ??         90h
    //         004322c4     NOP
    //         004322c5     NOP
    //         004322c6     NOP
    //         004322c7     NOP
    //         004322c8     NOP
    //         004322c9     NOP
    //         004322ca     NOP
    //         004322cb     NOP
    //         004322cc     NOP
    //         004322cd     NOP
    //         004322ce     NOP
    //         004322cf     NOP
    return 0;
}

char* TCommunications_Sessions::GetSessionName(int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall GetSessionName(TCommunications_Sessions * this, in
    //              char *            EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004322d0(R)  
    //                               ?GetSessionName@TCommunications_Sessions@@QAEPADH@Z          XREF[1]:     fillList:00491daa(c)  
    //                               TCommunications_Sessions::GetSessionName
    //                              com_sess.cpp:63 (12)
    //         004322d0     MOV        EAX,dword ptr [ESP + param_1]
    //         004322d4     TEST       EAX,EAX
    //         004322d6     JL         LAB_004322eb
    //         004322d8     CMP        EAX,dword ptr [this->SessionCount]
    //         004322da     JG         LAB_004322eb
    //                              com_sess.cpp:72 (12)
    //         004322dc     LEA        EDX,[EAX + EAX*0x8]
    //         004322df     SHL        EDX,0x3
    //         004322e2     SUB        EDX,EAX
    //         004322e4     LEA        EAX,[ECX + EDX*0x8 + this->Session[0].Name[0]]
    //                              com_sess.cpp:73 (3)
    //         004322e8     RET        0x4
    //                               LAB_004322eb                                                 XREF[2]:     004322d6(j), 004322da(j)  
    //                              com_sess.cpp:66 (2)
    //         004322eb     XOR        EAX,EAX
    //                              com_sess.cpp:73 (3)
    //         004322ed     RET        0x4
    return 0;
}

ulong TCommunications_Sessions::GetSessionMaxPlayers(int param_1) {
    /* TODO: Stub */
    //                              ulong __thiscall GetSessionMaxPlayers(TCommunications_Sessions * thi
    //              ulong             EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004322f0(R)  
    //                               ?GetSessionMaxPlayers@TCommunications_Sessions@@QAEKH@Z      XREF[1]:     fillList:00491d90(c)  
    //                               TCommunications_Sessions::GetSessionMaxPlayers
    //                              com_sess.cpp:76 (12)
    //         004322f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004322f4     TEST       EAX,EAX
    //         004322f6     JL         LAB_0043230e
    //         004322f8     CMP        EAX,dword ptr [this->SessionCount]
    //         004322fa     JG         LAB_0043230e
    //                              com_sess.cpp:80 (15)
    //         004322fc     LEA        EDX,[EAX + EAX*0x8]
    //         004322ff     SHL        EDX,0x3
    //         00432302     SUB        EDX,EAX
    //         00432304     MOV        EAX,dword ptr [ECX + EDX*0x8 + this+0x228]
    //                              com_sess.cpp:81 (3)
    //         0043230b     RET        0x4
    //                               LAB_0043230e                                                 XREF[2]:     004322f6(j), 004322fa(j)  
    //                              com_sess.cpp:78 (2)
    //         0043230e     XOR        EAX,EAX
    //                              com_sess.cpp:81 (3)
    //         00432310     RET        0x4
    //         00432313     ??         90h
    //         00432314     NOP
    //         00432315     NOP
    //         00432316     NOP
    //         00432317     NOP
    //         00432318     NOP
    //         00432319     NOP
    //         0043231a     NOP
    //         0043231b     NOP
    //         0043231c     NOP
    //         0043231d     NOP
    //         0043231e     NOP
    //         0043231f     NOP
    return 0;
}

ulong TCommunications_Sessions::GetSessionCurrentPlayers(int param_1) {
    /* TODO: Stub */
    //                              ulong __thiscall GetSessionCurrentPlayers(TCommunications_Sessions *
    //              ulong             EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00432320(R)  
    //                               ?GetSessionCurrentPlayers@TCommunications_Sessions@@QAEKH@Z  XREF[1]:     fillList:00491d9d(c)  
    //                               TCommunications_Sessions::GetSessionCurrentPlayers
    //                              com_sess.cpp:84 (12)
    //         00432320     MOV        EAX,dword ptr [ESP + param_1]
    //         00432324     TEST       EAX,EAX
    //         00432326     JL         LAB_0043233e
    //         00432328     CMP        EAX,dword ptr [this->SessionCount]
    //         0043232a     JG         LAB_0043233e
    //                              com_sess.cpp:88 (15)
    //         0043232c     LEA        EDX,[EAX + EAX*0x8]
    //         0043232f     SHL        EDX,0x3
    //         00432332     SUB        EDX,EAX
    //         00432334     MOV        EAX,dword ptr [ECX + EDX*0x8 + this+0x224]
    //                              com_sess.cpp:89 (3)
    //         0043233b     RET        0x4
    //                               LAB_0043233e                                                 XREF[2]:     00432326(j), 0043232a(j)  
    //                              com_sess.cpp:86 (2)
    //         0043233e     XOR        EAX,EAX
    //                              com_sess.cpp:89 (3)
    //         00432340     RET        0x4
    //         00432343     ??         90h
    //         00432344     NOP
    //         00432345     NOP
    //         00432346     NOP
    //         00432347     NOP
    //         00432348     NOP
    //         00432349     NOP
    //         0043234a     NOP
    //         0043234b     NOP
    //         0043234c     NOP
    //         0043234d     NOP
    //         0043234e     NOP
    //         0043234f     NOP
    return 0;
}

_GUID* TCommunications_Sessions::GetSessionGUID(int param_1) {
    /* TODO: Stub */
    //                              _GUID * __thiscall GetSessionGUID(TCommunications_Sessions * this, i
    //              _GUID *           EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00432350(R)  
    //                               ?GetSessionGUID@TCommunications_Sessions@@QAEPAU_GUID@@H@Z   XREF[1]:     action:00491ec6(c)  
    //                               TCommunications_Sessions::GetSessionGUID
    //                              com_sess.cpp:92 (12)
    //         00432350     MOV        EAX,dword ptr [ESP + param_1]
    //         00432354     TEST       EAX,EAX
    //         00432356     JL         LAB_0043236e
    //         00432358     CMP        EAX,dword ptr [this->SessionCount]
    //         0043235a     JG         LAB_0043236e
    //                              com_sess.cpp:100 (15)
    //         0043235c     LEA        EDX,[EAX + EAX*0x8]
    //         0043235f     SHL        EDX,0x3
    //         00432362     SUB        EDX,EAX
    //         00432364     LEA        EAX,[ECX + EDX*0x8 + this+0x214]
    //                              com_sess.cpp:101 (3)
    //         0043236b     RET        0x4
    //                               LAB_0043236e                                                 XREF[2]:     00432356(j), 0043235a(j)  
    //                              com_sess.cpp:94 (2)
    //         0043236e     XOR        EAX,EAX
    //                              com_sess.cpp:101 (3)
    //         00432370     RET        0x4
    //         00432373     ??         90h
    //         00432374     NOP
    //         00432375     NOP
    //         00432376     NOP
    //         00432377     NOP
    //         00432378     NOP
    //         00432379     NOP
    //         0043237a     NOP
    //         0043237b     NOP
    //         0043237c     NOP
    //         0043237d     NOP
    //         0043237e     NOP
    //         0043237f     NOP
    return 0;
}

int TCommunications_Sessions::IncSessionCount() {
    /* TODO: Stub */
    //                              int __thiscall IncSessionCount(TCommunications_Sessions * this)
    //              int               EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //                               ?IncSessionCount@TCommunications_Sessions@@QAEHXZ            XREF[1]:     AddSession:004324d6(c)  
    //                               TCommunications_Sessions::IncSessionCount
    //                              com_sess.cpp:105 (5)
    //         00432380     MOV        EAX,dword ptr [this->SessionCount]
    //         00432382     INC        EAX
    //         00432383     MOV        dword ptr [this->SessionCount],EAX
    //                              com_sess.cpp:111 (1)
    //         00432385     RET
    //         00432386     ??         90h
    //         00432387     NOP
    //         00432388     NOP
    //         00432389     NOP
    //         0043238a     NOP
    //         0043238b     NOP
    //         0043238c     NOP
    //         0043238d     NOP
    //         0043238e     NOP
    //         0043238f     NOP
    //                              * public: int __thiscall TCommunications_Sessions::AddSession(struct _GUID,struct _GUID,unsigned lon... *
    //                              int __thiscall AddSession(TCommunications_Sessions * this, _GUID par
    //              int               EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              _GUID             Stack[0x4]:16  param_1                   XREF[1,3]:   004323d6(R), 004323dc(R), 004323e3(R), 004323ea(R)  
    //              _GUID             Stack[0x14]:16 param_2                   XREF[1,3]:   004323aa(R), 004323b0(R), 004323b7(R), 004323be(R)  
    //              ulong             Stack[0x24]:4  param_3                   XREF[1]:     004323fb(R)  
    //              ulong             Stack[0x28]:4  param_4                   XREF[1]:     00432410(R)  
    //              char *            Stack[0x2c]:4  param_5                   XREF[1]:     00432397(R)  
    //              char *            Stack[0x30]:4  param_6                   XREF[1]:     0043249e(R)  
    //              ulong             Stack[0x34]:4  param_7                   XREF[1]:     00432425(R)  
    //              ulong             Stack[0x38]:4  param_8                   XREF[1]:     0043243a(R)  
    //              ulong             Stack[0x3c]:4  param_9                   XREF[1]:     0043244f(R)  
    //              ulong             Stack[0x40]:4  param_10                  XREF[1]:     00432464(R)  
    //                               ?AddSession@TCommunications_Sessions@@QAEHU_GUID@@0KKPAD1KK  XREF[1]:     EnumSessionCallback:004325d1(c)  
    //                               TCommunications_Sessions::AddSession
    //                              com_sess.cpp:126 (5)
    //         00432390     MOV        EDX,this
    //         00432392     PUSH       EBX
    //         00432393     PUSH       ESI
    //         00432394     PUSH       EDI
    //                              com_sess.cpp:137 (2)
    //         00432395     MOV        EAX,dword ptr [EDX]
    //                              com_sess.cpp:149 (220)
    //         00432397     MOV        EDI,dword ptr [ESP + param_5]
    //         0043239b     LEA        this,[EAX + EAX*0x8]
    //         0043239e     SHL        this,0x3
    //         004323a1     SUB        this,EAX
    //         004323a3     LEA        EAX,[EDX + this->SessionCount*0x8 + 0x204]
    //         004323aa     MOV        this,dword ptr [ESP + param_2.Data1]
    //         004323ae     MOV        dword ptr [EAX],this
    //         004323b0     MOV        this,dword ptr [ESP + param_2.Data2]
    //         004323b4     MOV        dword ptr [EAX + 0x4],this
    //         004323b7     MOV        this,dword ptr [ESP + param_2.Data4[0]]
    //         004323bb     MOV        dword ptr [EAX + 0x8],this
    //         004323be     MOV        this,dword ptr [ESP + param_2+0xc]
    //         004323c2     MOV        dword ptr [EAX + 0xc],this
    //         004323c5     MOV        EAX,dword ptr [EDX]
    //         004323c7     LEA        this,[EAX + EAX*0x8]
    //         004323ca     SHL        this,0x3
    //         004323cd     SUB        this,EAX
    //         004323cf     LEA        EAX,[EDX + this->SessionCount*0x8 + 0x214]
    //         004323d6     MOV        this,dword ptr [ESP + param_1.Data1]
    //         004323da     MOV        dword ptr [EAX],this
    //         004323dc     MOV        this,dword ptr [ESP + param_1.Data2]
    //         004323e0     MOV        dword ptr [EAX + 0x4],this
    //         004323e3     MOV        this,dword ptr [ESP + param_1.Data4[0]]
    //         004323e7     MOV        dword ptr [EAX + 0x8],this
    //         004323ea     MOV        this,dword ptr [ESP + param_1+0xc]
    //         004323ee     MOV        dword ptr [EAX + 0xc],this
    //         004323f1     MOV        EAX,dword ptr [EDX]
    //         004323f3     LEA        this,[EAX + EAX*0x8]
    //         004323f6     SHL        this,0x3
    //         004323f9     SUB        this,EAX
    //         004323fb     MOV        EAX,dword ptr [ESP + param_3]
    //         004323ff     MOV        dword ptr [EDX + this->SessionCount*0x8 + 0x22
    //         00432406     MOV        EAX,dword ptr [EDX]
    //         00432408     LEA        this,[EAX + EAX*0x8]
    //         0043240b     SHL        this,0x3
    //         0043240e     SUB        this,EAX
    //         00432410     MOV        EAX,dword ptr [ESP + param_4]
    //         00432414     MOV        dword ptr [EDX + this->SessionCount*0x8 + 0x22
    //         0043241b     MOV        EAX,dword ptr [EDX]
    //         0043241d     LEA        this,[EAX + EAX*0x8]
    //         00432420     SHL        this,0x3
    //         00432423     SUB        this,EAX
    //         00432425     MOV        EAX,dword ptr [ESP + param_7]
    //         00432429     MOV        dword ptr [EDX + this->SessionCount*0x8 + 0x22
    //         00432430     MOV        EAX,dword ptr [EDX]
    //         00432432     LEA        this,[EAX + EAX*0x8]
    //         00432435     SHL        this,0x3
    //         00432438     SUB        this,EAX
    //         0043243a     MOV        EAX,dword ptr [ESP + param_8]
    //         0043243e     MOV        dword ptr [EDX + this->SessionCount*0x8 + 0x22
    //         00432445     MOV        EAX,dword ptr [EDX]
    //         00432447     LEA        this,[EAX + EAX*0x8]
    //         0043244a     SHL        this,0x3
    //         0043244d     SUB        this,EAX
    //         0043244f     MOV        EAX,dword ptr [ESP + param_9]
    //         00432453     MOV        dword ptr [EDX + this->SessionCount*0x8 + 0x22
    //         0043245a     MOV        EAX,dword ptr [EDX]
    //         0043245c     LEA        this,[EAX + EAX*0x8]
    //         0043245f     SHL        this,0x3
    //         00432462     SUB        this,EAX
    //         00432464     MOV        EAX,dword ptr [ESP + param_10]
    //         00432468     TEST       EDI,EDI
    //         0043246a     MOV        dword ptr [EDX + this->SessionCount*0x8 + 0x22
    //         00432471     JZ         LAB_0043249e
    //                              com_sess.cpp:150 (43)
    //         00432473     MOV        EAX,dword ptr [EDX]
    //         00432475     LEA        this,[EAX + EAX*0x8]
    //         00432478     SHL        this,0x3
    //         0043247b     SUB        this,EAX
    //         0043247d     XOR        EAX,EAX
    //         0043247f     LEA        EBX,[EDX + this->SessionCount*0x8 + 0x4]
    //         00432483     OR         this,0xffffffff
    //         00432486     SCASB.RE   ES:EDI
    //         00432488     NOT        this
    //         0043248a     SUB        EDI,this
    //         0043248c     MOV        EAX,this
    //         0043248e     MOV        ESI,EDI
    //         00432490     MOV        EDI,EBX
    //         00432492     SHR        this,0x2
    //         00432495     MOVSD.REP  ES:EDI,ESI
    //         00432497     MOV        this,EAX
    //         00432499     AND        this,0x3
    //         0043249c     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0043249e                                                 XREF[1]:     00432471(j)  
    //                              com_sess.cpp:151 (8)
    //         0043249e     MOV        EDI,dword ptr [ESP + param_6]
    //         004324a2     TEST       EDI,EDI
    //         004324a4     JZ         LAB_004324d4
    //                              com_sess.cpp:152 (46)
    //         004324a6     MOV        EAX,dword ptr [EDX]
    //         004324a8     LEA        this,[EAX + EAX*0x8]
    //         004324ab     SHL        this,0x3
    //         004324ae     SUB        this,EAX
    //         004324b0     XOR        EAX,EAX
    //         004324b2     LEA        EBX,[EDX + this->SessionCount*0x8 + 0x103]
    //         004324b9     OR         this,0xffffffff
    //         004324bc     SCASB.RE   ES:EDI
    //         004324be     NOT        this
    //         004324c0     SUB        EDI,this
    //         004324c2     MOV        EAX,this
    //         004324c4     MOV        ESI,EDI
    //         004324c6     MOV        EDI,EBX
    //         004324c8     SHR        this,0x2
    //         004324cb     MOVSD.REP  ES:EDI,ESI
    //         004324cd     MOV        this,EAX
    //         004324cf     AND        this,0x3
    //         004324d2     MOVSB.REP  ES:EDI,ESI
    //                               LAB_004324d4                                                 XREF[1]:     004324a4(j)  
    //                              com_sess.cpp:154 (7)
    //         004324d4     MOV        this,EDX
    //         004324d6     CALL       TCommunications_Sessions::IncSessionCount        int IncSessionCount(TCommunications_Sessions 
    //                              com_sess.cpp:157 (11)
    //         004324db     POP        EDI
    //         004324dc     POP        ESI
    //         004324dd     MOV        EAX,0x1
    //         004324e2     POP        EBX
    //         004324e3     RET        0x40
    //         004324e6     ??         90h
    //         004324e7     NOP
    //         004324e8     NOP
    //         004324e9     NOP
    //         004324ea     NOP
    //         004324eb     NOP
    //         004324ec     NOP
    //         004324ed     NOP
    //         004324ee     NOP
    //         004324ef     NOP
    return 0;
}

int TCommunications_Sessions::Refresh() {
    /* TODO: Stub */
    //                              int __thiscall Refresh(TCommunications_Sessions * this)
    //              int               EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              DPSESSIONDESC2    Stack[-0x54]   dpDesc                    XREF[0,7]:   00432509(*), 00432538(*), 00432546(W), 0043251a(W), 
    //                                                                                     0043253c(W), 0043252e(W), 00432523(W)  
    //                               ?Refresh@TCommunications_Sessions@@QAEHXZ                    XREF[2]:     TCommunications_Sessions:0043227b(
    //                               TCommunications_Sessions::Refresh                                         fillList:00491d58(c)  
    //                              com_sess.cpp:161 (7)
    //         004324f0     SUB        ESP,0x50
    //         004324f3     PUSH       ESI
    //         004324f4     PUSH       EDI
    //         004324f5     MOV        ESI,this
    //                              com_sess.cpp:167 (5)
    //         004324f7     CALL       TCommunications_Sessions::EraseInformation       void EraseInformation(TCommunications_Session
    //                              com_sess.cpp:171 (43)
    //         004324fc     MOV        EDX,dword ptr [ApplicationGUID.Data4[0]]
    //         00432502     MOV        this,0x14
    //         00432507     XOR        EAX,EAX
    //         00432509     LEA        EDI=>dpDesc.dwFlags,[ESP + 0x8]
    //         0043250d     STOSD.REP  ES:EDI
    //         0043250f     MOV        EAX,[ApplicationGUID]
    //         00432514     MOV        this,dword ptr [ApplicationGUID.Data2]
    //         0043251a     MOV        dword ptr [ESP + dpDesc+0x1c],EAX
    //         0043251e     MOV        EAX,[ApplicationGUID.Data4[4]]
    //         00432523     MOV        dword ptr [ESP + dpDesc.dwMaxPlayers],EAX
    //                              com_sess.cpp:182 (42)
    //         00432527     MOV        EAX,[glpSERV]                                    = 00000000
    //         0043252c     PUSH       0x1
    //         0043252e     MOV        dword ptr [ESP + dpDesc+0x24],EDX
    //         00432532     PUSH       ESI
    //         00432533     PUSH       EnumSessionCallback
    //         00432538     LEA        EDX=>dpDesc.dwFlags,[ESP + 0x14]
    //         0043253c     MOV        dword ptr [ESP + dpDesc+0x20],this
    //         00432540     MOV        this,dword ptr [EAX]
    //         00432542     PUSH       0x0
    //         00432544     PUSH       EDX
    //         00432545     PUSH       EAX
    //         00432546     MOV        dword ptr [ESP + dpDesc.dwFlags],0x50
    //         0043254e     CALL       dword ptr [ECX + this+0x34]
    //                              com_sess.cpp:186 (6)
    //         00432551     POP        EDI
    //         00432552     POP        ESI
    //         00432553     ADD        ESP,0x50
    //         00432556     RET
    //         00432557     ??         90h
    //         00432558     NOP
    //         00432559     NOP
    //         0043255a     NOP
    //         0043255b     NOP
    //         0043255c     NOP
    //         0043255d     NOP
    //         0043255e     NOP
    //         0043255f     NOP
    //                              * int __stdcall EnumSessionCallback(struct DPSESSIONDESC2 *,unsigned long *,unsigned long,void *)       *
    //                              int __stdcall EnumSessionCallback(DPSESSIONDESC2 * param_1, ulong * 
    //              int               EAX:4          <RETURN>
    //              DPSESSIONDESC2    Stack[0x4]:4   param_1                   XREF[1]:     0043256c(R)  
    //              ulong *           Stack[0x8]:4   param_2
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00432560(R)  
    //              void *            Stack[0x10]:4  param_4                   XREF[1]:     004325ca(R)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[1]:     004325b2(W)  
    //              undefined4        Stack[-0x2c]:4 local_2c                  XREF[1]:     004325ac(W)  
    //              undefined4        Stack[-0x30]:4 local_30                  XREF[1]:     004325a6(W)  
    //              undefined4        Stack[-0x34]:4 local_34                  XREF[1]:     004325a1(*)  
    //              undefined4        Stack[-0x38]:4 local_38                  XREF[1]:     004325ce(W)  
    //              undefined4        Stack[-0x3c]:4 local_3c                  XREF[1]:     004325c7(W)  
    //              undefined4        Stack[-0x40]:4 local_40                  XREF[1]:     004325be(W)  
    //              undefined4        Stack[-0x44]:4 local_44                  XREF[1]:     004325b9(*)  
    //                               ?EnumSessionCallback@@YGHPAUDPSESSIONDESC2@@PAKKPAX@Z        XREF[1]:     Refresh:00432533(*)  
    //                               EnumSessionCallback
    //                              com_sess.cpp:199 (9)
    //         00432560     TEST       byte ptr [ESP + param_3],0x1
    //         00432565     JZ         LAB_0043256c
    //         00432567     XOR        EAX,EAX
    //                              com_sess.cpp:224 (3)
    //         00432569     RET        0x10
    //                               LAB_0043256c                                                 XREF[1]:     00432565(j)  
    //                              com_sess.cpp:221 (106)
    //         0043256c     MOV        EAX,dword ptr [ESP + param_1]
    //         00432570     PUSH       ESI
    //         00432571     MOV        ECX,dword ptr [EAX + 0x4c]
    //         00432574     MOV        EDX,dword ptr [EAX + 0x48]
    //         00432577     PUSH       ECX
    //         00432578     MOV        ECX,dword ptr [EAX + 0x44]
    //         0043257b     PUSH       EDX
    //         0043257c     MOV        EDX,dword ptr [EAX + 0x40]
    //         0043257f     PUSH       ECX
    //         00432580     MOV        ECX,dword ptr [EAX + 0x34]
    //         00432583     PUSH       EDX
    //         00432584     MOV        EDX,dword ptr [EAX + 0x30]
    //         00432587     PUSH       ECX
    //         00432588     MOV        ECX,dword ptr [EAX + 0x2c]
    //         0043258b     PUSH       EDX
    //         0043258c     MOV        EDX,dword ptr [EAX + 0x28]
    //         0043258f     PUSH       ECX
    //         00432590     PUSH       EDX
    //         00432591     LEA        ECX,[EAX + 0x18]
    //         00432594     SUB        ESP,0x10
    //         00432597     MOV        EDX,ESP
    //         00432599     ADD        EAX,0x8
    //         0043259c     MOV        ESI,dword ptr [ECX]
    //         0043259e     SUB        ESP,0x10
    //         004325a1     MOV        dword ptr [EDX]=>local_34,ESI
    //         004325a3     MOV        ESI,dword ptr [ECX + 0x4]
    //         004325a6     MOV        dword ptr [EDX + local_30],ESI
    //         004325a9     MOV        ESI,dword ptr [ECX + 0x8]
    //         004325ac     MOV        dword ptr [EDX + local_2c],ESI
    //         004325af     MOV        ECX,dword ptr [ECX + 0xc]
    //         004325b2     MOV        dword ptr [EDX + local_28],ECX
    //         004325b5     MOV        ECX,dword ptr [EAX]
    //         004325b7     MOV        EDX,ESP
    //         004325b9     MOV        dword ptr [EDX]=>local_44,ECX
    //         004325bb     MOV        ECX,dword ptr [EAX + 0x4]
    //         004325be     MOV        dword ptr [EDX + local_40],ECX
    //         004325c1     MOV        ECX,dword ptr [EAX + 0x8]
    //         004325c4     MOV        EAX,dword ptr [EAX + 0xc]
    //         004325c7     MOV        dword ptr [EDX + local_3c],ECX
    //         004325ca     MOV        ECX,dword ptr [ESP + param_4]
    //         004325ce     MOV        dword ptr [EDX + local_38],EAX
    //         004325d1     CALL       TCommunications_Sessions::AddSession             int AddSession(TCommunications_Sessions * thi
    //                              com_sess.cpp:223 (6)
    //         004325d6     MOV        EAX,0x1
    //         004325db     POP        ESI
    //                              com_sess.cpp:224 (3)
    //         004325dc     RET        0x10
    //         004325df     ??         90h
    return 0;
}

int TCommunications_Sessions::IsEqualGuid(_GUID* param_1, _GUID* param_2) {
    /* TODO: Stub */
    //                              int __thiscall IsEqualGuid(TCommunications_Sessions * this, _GUID * 
    //              int               EAX:4          <RETURN>
    //              TCommunication    ECX:4 (auto)   this
    //              _GUID *           Stack[0x4]:4   param_1                   XREF[1]:     004325e0(R)  
    //              _GUID *           Stack[0x8]:4   param_2                   XREF[1]:     004325e4(R)  
    //                               ?IsEqualGuid@TCommunications_Sessions@@QAEHPAU_GUID@@0@Z
    //                               TCommunications_Sessions::IsEqualGuid
    //                              com_sess.cpp:233 (52)
    //         004325e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004325e4     MOV        this,dword ptr [ESP + param_2]
    //         004325e8     PUSH       ESI
    //         004325e9     MOV        EDX,dword ptr [EAX]
    //         004325eb     MOV        ESI,dword ptr [this->SessionCount]
    //         004325ed     CMP        EDX,ESI
    //         004325ef     JNZ        LAB_00432618
    //         004325f1     MOV        EDX,dword ptr [EAX + 0x4]
    //         004325f4     MOV        ESI,dword ptr [ECX + this->Session[0].Name[0]]
    //         004325f7     CMP        EDX,ESI
    //         004325f9     JNZ        LAB_00432618
    //         004325fb     MOV        EDX,dword ptr [EAX + 0x8]
    //         004325fe     MOV        ESI,dword ptr [ECX + this+0x8]
    //         00432601     CMP        EDX,ESI
    //         00432603     JNZ        LAB_00432618
    //         00432605     MOV        EAX,dword ptr [EAX + 0xc]
    //         00432608     MOV        EDX,dword ptr [ECX + this+0xc]
    //         0043260b     CMP        EAX,EDX
    //         0043260d     JNZ        LAB_00432618
    //         0043260f     MOV        EAX,0x1
    //                              com_sess.cpp:239 (4)
    //         00432614     POP        ESI
    //         00432615     RET        0x8
    //                               LAB_00432618                                                 XREF[4]:     004325ef(j), 004325f9(j), 
    //                                                                                                         00432603(j), 0043260d(j)  
    //                              com_sess.cpp:238 (2)
    //         00432618     XOR        EAX,EAX
    //                              com_sess.cpp:239 (4)
    //         0043261a     POP        ESI
    //         0043261b     RET        0x8
    //         0043261e     ??         90h
    //         0043261f     NOP
    //                              * public: __thiscall RGE_Communications_Speed::RGE_Communications_Speed(class TCommunications_Handle... *
    //                              undefined __thiscall RGE_Communications_Speed(RGE_Communications_Spe
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              TCommunication    Stack[0x4]:4   param_1                   XREF[3]:     0043262e(R), 00432709(W), 0043273b(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0043270f(W), 00432725(W), 00432741(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00432756(R)  
    //                               ??0RGE_Communications_Speed@@QAE@PAVTCommunications_Handler  XREF[3]:     TCommunications_Handler:00425e26(c
    //                               RGE_Communications_Speed::RGE_Communications_Speed                        UnlinkCurrentLevel:0042c216(c), 
    //                                                                                                         UnlinkCurrentLevel:0042c3b3(c)  
    //                              com_spd.cpp:11 (14)
    //         00432620     MOV        EAX,FS:[0x0]
    //         00432626     PUSH       -0x1
    //         00432628     PUSH       FUN_0055cf06
    //         0043262d     PUSH       EAX
    //                              com_spd.cpp:20 (29)
    //         0043262e     MOV        EAX,dword ptr [ESP + param_1]
    //         00432632     MOV        dword ptr FS:[0x0],ESP
    //         00432639     PUSH       EBX
    //         0043263a     PUSH       ESI
    //         0043263b     MOV        ESI,this
    //         0043263d     PUSH       EDI
    //         0043263e     MOV        EDX,0xa
    //         00432643     XOR        EDI,EDI
    //         00432645     MOV        dword ptr [ESI + 0x108],EAX
    //                              com_spd.cpp:25 (11)
    //         0043264b     MOV        EAX,0x5a
    //         00432650     MOV        dword ptr [ESI + 0x12c],EAX
    //                              com_spd.cpp:26 (58)
    //         00432656     MOV        dword ptr [ESI + 0x218],EAX
    //         0043265c     MOV        dword ptr [ESI + 0x11c],EDX
    //         00432662     MOV        dword ptr [ESI + 0x214],EDX
    //         00432668     MOV        dword ptr [ESI + 0x118],0x1
    //         00432672     MOV        dword ptr [ESI + 0x134],EDI
    //         00432678     MOV        dword ptr [ESI + 0x224],EDI
    //         0043267e     MOV        dword ptr [ESI + 0x238],EDI
    //         00432684     MOV        dword ptr [ESI + 0x23c],EDI
    //         0043268a     MOV        dword ptr [ESI + 0x124],EDI
    //                              com_spd.cpp:27 (6)
    //         00432690     MOV        dword ptr [ESI + 0x138],EDI
    //                              com_spd.cpp:28 (10)
    //         00432696     MOV        dword ptr [ESI + 0x128],0x1f4
    //                              com_spd.cpp:30 (6)
    //         004326a0     MOV        dword ptr [ESI + 0x228],EDI
    //                              com_spd.cpp:31 (6)
    //         004326a6     MOV        dword ptr [ESI + 0x22c],EDI
    //                              com_spd.cpp:32 (6)
    //         004326ac     MOV        dword ptr [ESI + 0x230],EDI
    //                              com_spd.cpp:33 (6)
    //         004326b2     MOV        dword ptr [ESI + 0x234],EDI
    //                              com_spd.cpp:36 (6)
    //         004326b8     MOV        dword ptr [ESI + 0x140],EDI
    //                              com_spd.cpp:39 (6)
    //         004326be     MOV        dword ptr [ESI + 0x120],EDI
    //                              com_spd.cpp:40 (23)
    //         004326c4     MOV        dword ptr [ESI + 0x130],EDI
    //         004326ca     LEA        this,[ESI + 0x1a8]
    //         004326d0     LEA        EAX,[ESI + 0x16c]
    //         004326d6     MOV        EBX,0x1e
    //                               LAB_004326db                                                 XREF[1]:     004326f0(j)  
    //                              com_spd.cpp:47 (3)
    //         004326db     MOV        dword ptr [EAX + -0x28],EBX
    //                              com_spd.cpp:48 (2)
    //         004326de     MOV        dword ptr [EAX],EDI
    //                              com_spd.cpp:49 (3)
    //         004326e0     MOV        word ptr [this->TBuff[0]],DI
    //                              com_spd.cpp:52 (3)
    //         004326e3     MOV        dword ptr [EAX + 0x50],EDI
    //                              com_spd.cpp:53 (12)
    //         004326e6     MOV        dword ptr [EAX + 0x78],EDI
    //         004326e9     ADD        this,0x2
    //         004326ec     ADD        EAX,0x4
    //         004326ef     DEC        EDX
    //         004326f0     JNZ        LAB_004326db
    //                              com_spd.cpp:58 (46)
    //         004326f2     PUSH       0x2b4
    //         004326f7     MOV        dword ptr [ESI + 0x20c],0x1f4
    //         00432701     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00432706     ADD        ESP,0x4
    //         00432709     MOV        dword ptr [ESP + param_1],EAX
    //         0043270d     CMP        EAX,EDI
    //         0043270f     MOV        dword ptr [ESP + local_4],EDI
    //         00432713     JZ         LAB_0043271e
    //         00432715     MOV        this,EAX
    //         00432717     CALL       RGE_TimeSinceLastCall::RGE_TimeSinceLastCall     undefined RGE_TimeSinceLastCall(RGE_TimeSince
    //         0043271c     JMP        LAB_00432720
    //                               LAB_0043271e                                                 XREF[1]:     00432713(j)  
    //         0043271e     XOR        EAX,EAX
    //                               LAB_00432720                                                 XREF[1]:     0043271c(j)  
    //                              com_spd.cpp:59 (54)
    //         00432720     PUSH       0x2b4
    //         00432725     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0043272d     MOV        dword ptr [ESI + 0x104],EAX
    //         00432733     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00432738     ADD        ESP,0x4
    //         0043273b     MOV        dword ptr [ESP + param_1],EAX
    //         0043273f     CMP        EAX,EDI
    //         00432741     MOV        dword ptr [ESP + local_4],0x1
    //         00432749     JZ         LAB_00432754
    //         0043274b     MOV        this,EAX
    //         0043274d     CALL       RGE_TimeSinceLastCall::RGE_TimeSinceLastCall     undefined RGE_TimeSinceLastCall(RGE_TimeSince
    //         00432752     JMP        LAB_00432756
    //                               LAB_00432754                                                 XREF[1]:     00432749(j)  
    //         00432754     XOR        EAX,EAX
    //                               LAB_00432756                                                 XREF[1]:     00432752(j)  
    //                              com_spd.cpp:60 (28)
    //         00432756     MOV        this,dword ptr [ESP + local_c]
    //         0043275a     MOV        dword ptr [ESI + 0x100],EAX
    //         00432760     MOV        EAX,ESI
    //         00432762     POP        EDI
    //         00432763     POP        ESI
    //         00432764     MOV        dword ptr FS:[0x0],this
    //         0043276b     POP        EBX
    //         0043276c     ADD        ESP,0xc
    //         0043276f     RET        0x4
    //         00432772     ??         90h
    //         00432773     NOP
    //         00432774     NOP
    //         00432775     NOP
    //         00432776     NOP
    //         00432777     NOP
    //         00432778     NOP
    //         00432779     NOP
    //         0043277a     NOP
    //         0043277b     NOP
    //         0043277c     NOP
    //         0043277d     NOP
    //         0043277e     NOP
    //         0043277f     NOP
    return 0;
}

TCommunications_Sessions::TCommunications_Sessions(TCommunications_Handler* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

int TCommunications_Sessions::AddSession(_GUID param_1, _GUID param_2, ulong param_3, ulong param_4, char* param_5, char* param_6, ulong param_7, ulong param_8, ulong param_9, ulong param_10) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

