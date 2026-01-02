#include "../common.h"
#include "com_serv.h"

TCommunications_Services::TCommunications_Services() {
    /* TODO: Stub */
//                              undefined __thiscall TCommunications_Services(TCommunications_Servic
//              undefined         <UNASSIGNED>   <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00431fb9(W), 00432008(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     00431fde(W), 00431fe6(R)
//                               ??0TCommunications_Services@@QAE@XZ                          XREF[2]:     action:0049fb99(c),
//                               TCommunications_Services::TCommunications_Services                        fillList:0049ff07(c)
//                              com_serv.cpp:20 (5)
//         00431fb0     SUB        ESP,0x8
//         00431fb3     PUSH       EBX
//         00431fb4     PUSH       EBP
//                              com_serv.cpp:21 (22)
//         00431fb5     XOR        EBX,EBX
//         00431fb7     PUSH       ESI
//         00431fb8     PUSH       EDI
//         00431fb9     MOV        dword ptr [ESP + local_4],this
//         00431fbd     MOV        dword ptr [ECX + this->ServiceCount],EBX
//         00431fc3     LEA        EDX,[ECX + this+0x5c]
//         00431fc6     MOV        EBP,0x64
//                               LAB_00431fcb                                                 XREF[1]:     00432006(j)
//                              com_serv.cpp:26 (10)
//         00431fcb     MOV        EDI,s_                                           = ""
//         00431fd0     OR         this,0xffffffff
//         00431fd3     XOR        EAX,EAX
//                              com_serv.cpp:27 (40)
//         00431fd5     LEA        ESI,[EDX + -0x5c]
//         00431fd8     SCASB.RE   ES:EDI=>s_                                       = ""
//         00431fda     NOT        this
//         00431fdc     SUB        EDI,this
//         00431fde     MOV        dword ptr [ESP + local_8],ESI
//         00431fe2     MOV        EAX,this
//         00431fe4     MOV        ESI,EDI
//         00431fe6     MOV        EDI,dword ptr [ESP + local_8]
//         00431fea     ADD        EDX,0x60
//         00431fed     SHR        this,0x2
//         00431ff0     MOVSD.REP  ES:EDI,ESI
//         00431ff2     MOV        this,EAX
//         00431ff4     AND        this,0x3
//         00431ff7     DEC        EBP
//         00431ff8     MOVSB.REP  ES:EDI,ESI
//         00431ffa     MOV        dword ptr [EDX + -0x6c],EBX
//                              com_serv.cpp:28 (3)
//         00431ffd     MOV        dword ptr [EDX + -0x60],EBX
//                              com_serv.cpp:29 (3)
//         00432000     MOV        dword ptr [EDX + -0x64],EBX
//                              com_serv.cpp:30 (5)
//         00432003     MOV        dword ptr [EDX + -0x68],EBX
//         00432006     JNZ        LAB_00431fcb
//                              com_serv.cpp:36 (15)
//         00432008     MOV        ESI,dword ptr [ESP + local_4]
//         0043200c     PUSH       ESI
//         0043200d     PUSH       DPEnumCallback
//         00432012     CALL       _DirectPlayEnumerateA@8                          undefined _DirectPlayEnumerateA@8()
//                              com_serv.cpp:37 (10)
//         00432017     MOV        EAX,ESI
//         00432019     POP        EDI
//         0043201a     POP        ESI
//         0043201b     POP        EBP
//         0043201c     POP        EBX
//         0043201d     ADD        ESP,0x8
//         00432020     RET
//         00432021     ??         90h
//         00432022     NOP
//         00432023     NOP
//         00432024     NOP
//         00432025     NOP
//         00432026     NOP
//         00432027     NOP
//         00432028     NOP
//         00432029     NOP
//         0043202a     NOP
//         0043202b     NOP
//         0043202c     NOP
//         0043202d     NOP
//         0043202e     NOP
//         0043202f     NOP
}

TCommunications_Services::~TCommunications_Services() {
    /* TODO: Stub */
//                              void __thiscall ~TCommunications_Services(TCommunications_Services *
//              void              <VOID>         <RETURN>
//              TCommunication    ECX:4 (auto)   this
//                               ??1TCommunications_Services@@QAE@XZ                          XREF[2]:     action:0049fc4f(c),
//                               TCommunications_Services::~TCommunications_Services                       fillList:004a007f(c)
//                              com_serv.cpp:42 (1)
//         00432030     RET
//         00432031     ??         90h
//         00432032     NOP
//         00432033     NOP
//         00432034     NOP
//         00432035     NOP
//         00432036     NOP
//         00432037     NOP
//         00432038     NOP
//         00432039     NOP
//         0043203a     NOP
//         0043203b     NOP
//         0043203c     NOP
//         0043203d     NOP
//         0043203e     NOP
//         0043203f     NOP
}

int TCommunications_Services::GetServiceCount() {
    /* TODO: Stub */
//                              int __thiscall GetServiceCount(TCommunications_Services * this)
//              int               EAX:4          <RETURN>
//              TCommunication    ECX:4 (auto)   this
//                               ?GetServiceCount@TCommunications_Services@@QAEHXZ            XREF[2]:     DPEnumCallback:00432189(c),
//                               TCommunications_Services::GetServiceCount                                 fillList:0049ff1e(c)
//                              com_serv.cpp:49 (6)
//         00432040     MOV        EAX,dword ptr [ECX + this->ServiceCount]
//                              com_serv.cpp:51 (1)
//         00432046     RET
//         00432047     ??         90h
//         00432048     NOP
//         00432049     NOP
//         0043204a     NOP
//         0043204b     NOP
//         0043204c     NOP
//         0043204d     NOP
//         0043204e     NOP
//         0043204f     NOP
    return 0;
}

int TCommunications_Services::IncServiceCount() {
    /* TODO: Stub */
//                              int __thiscall IncServiceCount(TCommunications_Services * this)
//              int               EAX:4          <RETURN>
//              TCommunication    ECX:4 (auto)   this
//                               ?IncServiceCount@TCommunications_Services@@QAEHXZ            XREF[2]:     DPEnumCallback:004321d1(c),
//                               TCommunications_Services::IncServiceCount                                 DPEnumCallback:004321ed(c)
//                              com_serv.cpp:54 (13)
//         00432050     MOV        EAX,dword ptr [ECX + this->ServiceCount]
//         00432056     INC        EAX
//         00432057     MOV        dword ptr [ECX + this->ServiceCount],EAX
//                              com_serv.cpp:57 (1)
//         0043205d     RET
//         0043205e     ??         90h
//         0043205f     NOP
    return 0;
}

char* TCommunications_Services::GetServiceName(int param_1) {
    /* TODO: Stub */
//                              char * __thiscall GetServiceName(TCommunications_Services * this, in
//              char *            EAX:4          <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00432060(R)
//                               ?GetServiceName@TCommunications_Services@@QAEPADH@Z          XREF[3]:     fillList:0049ffa6(c),
//                               TCommunications_Services::GetServiceName                                  fillList:0049ffb8(c),
//                                                                                                         fillList:0049ffd5(c)
//                              com_serv.cpp:61 (16)
//         00432060     MOV        EAX,dword ptr [ESP + param_1]
//         00432064     TEST       EAX,EAX
//         00432066     JL         LAB_0043207b
//         00432068     CMP        EAX,dword ptr [ECX + this->ServiceCount]
//         0043206e     JG         LAB_0043207b
//                              com_serv.cpp:65 (8)
//         00432070     LEA        EAX,[EAX + EAX*0x2]
//         00432073     SHL        EAX,0x5
//         00432076     ADD        EAX,this
//                              com_serv.cpp:66 (3)
//         00432078     RET        0x4
//                               LAB_0043207b                                                 XREF[2]:     00432066(j), 0043206e(j)
//                              com_serv.cpp:63 (2)
//         0043207b     XOR        EAX,EAX
//                              com_serv.cpp:66 (3)
//         0043207d     RET        0x4
    return 0;
}

int TCommunications_Services::SetServiceName(int param_1, char* param_2) {
    /* TODO: Stub */
//                              int __thiscall SetServiceName(TCommunications_Services * this, int p
//              int               EAX:4          <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00432080(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     00432086(R)
//                               ?SetServiceName@TCommunications_Services@@QAEHHPAD@Z         XREF[1]:     DPEnumCallback:00432198(c)
//                               TCommunications_Services::SetServiceName
//                              com_serv.cpp:69 (42)
//         00432080     MOV        EAX,dword ptr [ESP + param_1]
//         00432084     PUSH       ESI
//         00432085     PUSH       EDI
//         00432086     MOV        EDI,dword ptr [ESP + param_2]
//         0043208a     LEA        EDX,[EAX + EAX*0x2]
//         0043208d     XOR        EAX,EAX
//         0043208f     SHL        EDX,0x5
//         00432092     ADD        EDX,this
//         00432094     OR         this,0xffffffff
//         00432097     SCASB.RE   ES:EDI
//         00432099     NOT        this
//         0043209b     SUB        EDI,this
//         0043209d     MOV        EAX,this
//         0043209f     MOV        ESI,EDI
//         004320a1     MOV        EDI,EDX
//         004320a3     SHR        this,0x2
//         004320a6     MOVSD.REP  ES:EDI,ESI
//         004320a8     MOV        this,EAX
//                              com_serv.cpp:74 (10)
//         004320aa     MOV        EAX,0x1
//         004320af     AND        this,0x3
//         004320b2     MOVSB.REP  ES:EDI,ESI
//                              com_serv.cpp:75 (5)
//         004320b4     POP        EDI
//         004320b5     POP        ESI
//         004320b6     RET        0x8
//         004320b9     ??         90h
//         004320ba     NOP
//         004320bb     NOP
//         004320bc     NOP
//         004320bd     NOP
//         004320be     NOP
//         004320bf     NOP
    return 0;
}

_GUID* TCommunications_Services::GetServiceGUID(_GUID* __return_storage_ptr__, int param_1) {
    /* TODO: Stub */
//                              _GUID __thiscall GetServiceGUID(TCommunications_Services * this, _GU
//              _GUID             EAX:4 (ptr)    <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              _GUID *           Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     004320cf(R)
//              int               Stack[0x8]:4   param_1                   XREF[1]:     004320c0(R)
//                               ?GetServiceGUID@TCommunications_Services@@QAE?AU_GUID@@H@Z   XREF[1]:     action:0049fbbe(c)
//                               TCommunications_Services::GetServiceGUID
//                              com_serv.cpp:80 (37)
//         004320c0     MOV        EAX,dword ptr [ESP + param_1]
//         004320c4     PUSH       ESI
//         004320c5     LEA        EAX,[EAX + EAX*0x2]
//         004320c8     SHL        EAX,0x5
//         004320cb     MOV        this,dword ptr [EAX + this->Service[0].Name[0]
//         004320cf     MOV        EAX,dword ptr [ESP + __return_storage_ptr__]
//         004320d3     MOV        EDX,EAX
//         004320d5     MOV        ESI,dword ptr [this->Service[0].Name[0]]
//         004320d7     MOV        dword ptr [EDX],ESI
//         004320d9     MOV        ESI,dword ptr [ECX + this+0x4]
//         004320dc     MOV        dword ptr [EDX + 0x4],ESI
//         004320df     MOV        ESI,dword ptr [ECX + this+0x8]
//         004320e2     MOV        dword ptr [EDX + 0x8],ESI
//                              com_serv.cpp:82 (10)
//         004320e5     POP        ESI
//         004320e6     MOV        this,dword ptr [ECX + this+0xc]
//         004320e9     MOV        dword ptr [EDX + 0xc],this
//         004320ec     RET        0x8
//         004320ef     ??         90h
    return 0;
}

void TCommunications_Services::EnumServiceGUID(int param_1, _GUID* param_2) {
    /* TODO: Stub */
//                              void __thiscall EnumServiceGUID(TCommunications_Services * this, int
//              void              <VOID>         <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004320f0(R)
//              _GUID *           Stack[0x8]:4   param_2                   XREF[1]:     00432100(R)
//                               ?EnumServiceGUID@TCommunications_Services@@QAEXHPAU_GUID@@@Z XREF[1]:     DPEnumCallback:004321a5(c)
//                               TCommunications_Services::EnumServiceGUID
//                              com_serv.cpp:86 (16)
//         004320f0     MOV        EAX,dword ptr [ESP + param_1]
//         004320f4     TEST       EAX,EAX
//         004320f6     JL         LAB_0043210e
//         004320f8     CMP        EAX,dword ptr [ECX + this->ServiceCount]
//         004320fe     JG         LAB_0043210e
//                              com_serv.cpp:90 (14)
//         00432100     MOV        EDX,dword ptr [ESP + param_2]
//         00432104     LEA        EAX,[EAX + EAX*0x2]
//         00432107     SHL        EAX,0x5
//         0043210a     MOV        dword ptr [EAX + this->Service[0].Name[0]*0x1
//                               LAB_0043210e                                                 XREF[2]:     004320f6(j), 004320fe(j)
//                              com_serv.cpp:91 (3)
//         0043210e     RET        0x8
//         00432111     ??         90h
//         00432112     NOP
//         00432113     NOP
//         00432114     NOP
//         00432115     NOP
//         00432116     NOP
//         00432117     NOP
//         00432118     NOP
//         00432119     NOP
//         0043211a     NOP
//         0043211b     NOP
//         0043211c     NOP
//         0043211d     NOP
//         0043211e     NOP
//         0043211f     NOP
    return;
}

int TCommunications_Services::GetServiceActive(int param_1) {
    /* TODO: Stub */
//                              int __thiscall GetServiceActive(TCommunications_Services * this, int
//              int               EAX:4          <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00432120(R)
//                               ?GetServiceActive@TCommunications_Services@@QAEHH@Z          XREF[1]:     fillList:0049ff95(c)
//                               TCommunications_Services::GetServiceActive
//                              com_serv.cpp:97 (16)
//         00432120     MOV        EAX,dword ptr [ESP + param_1]
//         00432124     TEST       EAX,EAX
//         00432126     JL         LAB_0043213d
//         00432128     CMP        EAX,dword ptr [ECX + this->ServiceCount]
//         0043212e     JG         LAB_0043213d
//                              com_serv.cpp:104 (10)
//         00432130     LEA        EAX,[EAX + EAX*0x2]
//         00432133     SHL        EAX,0x5
//         00432136     MOV        EAX,dword ptr [ECX + EAX*0x1 + this+0x5c]
//                              com_serv.cpp:105 (3)
//         0043213a     RET        0x4
//                               LAB_0043213d                                                 XREF[2]:     00432126(j), 0043212e(j)
//                              com_serv.cpp:99 (2)
//         0043213d     XOR        EAX,EAX
//                              com_serv.cpp:105 (3)
//         0043213f     RET        0x4
//         00432142     ??         90h
//         00432143     NOP
//         00432144     NOP
//         00432145     NOP
//         00432146     NOP
//         00432147     NOP
//         00432148     NOP
//         00432149     NOP
//         0043214a     NOP
//         0043214b     NOP
//         0043214c     NOP
//         0043214d     NOP
//         0043214e     NOP
//         0043214f     NOP
    return 0;
}

void TCommunications_Services::SetServiceActive(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetServiceActive(TCommunications_Services * this, in
//              void              <VOID>         <RETURN>
//              TCommunication    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00432150(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00432160(R)
//                               ?SetServiceActive@TCommunications_Services@@QAEXHH@Z         XREF[2]:     DPEnumCallback:004321c0(c),
//                               TCommunications_Services::SetServiceActive                                DPEnumCallback:004321e6(c)
//                              com_serv.cpp:108 (16)
//         00432150     MOV        EAX,dword ptr [ESP + param_1]
//         00432154     TEST       EAX,EAX
//         00432156     JL         LAB_0043216e
//         00432158     CMP        EAX,dword ptr [ECX + this->ServiceCount]
//         0043215e     JG         LAB_0043216e
//                              com_serv.cpp:112 (14)
//         00432160     MOV        EDX,dword ptr [ESP + param_2]
//         00432164     LEA        EAX,[EAX + EAX*0x2]
//         00432167     SHL        EAX,0x5
//         0043216a     MOV        dword ptr [EAX + this->Service[0].Name[0]*0x1
//                               LAB_0043216e                                                 XREF[2]:     00432156(j), 0043215e(j)
//                              com_serv.cpp:118 (3)
//         0043216e     RET        0x8
//         00432171     ??         90h
//         00432172     NOP
//         00432173     NOP
//         00432174     NOP
//         00432175     NOP
//         00432176     NOP
//         00432177     NOP
//         00432178     NOP
//         00432179     NOP
//         0043217a     NOP
//         0043217b     NOP
//         0043217c     NOP
//         0043217d     NOP
//         0043217e     NOP
//         0043217f     NOP
    return;
}

int DPEnumCallback(_GUID* param_1, char* param_2, ulong param_3, ulong param_4, void* param_5) {
    /* TODO: Stub */
//                              int __stdcall DPEnumCallback(_GUID * param_1, char * param_2, ulong
//              int               EAX:4          <RETURN>
//              _GUID *           Stack[0x4]:4   param_1                   XREF[1]:     0043219f(R)
//              char *            Stack[0x8]:4   param_2                   XREF[1]:     00432190(R)
//              ulong             Stack[0xc]:4   param_3
//              ulong             Stack[0x10]:4  param_4
//              void *            Stack[0x14]:4  param_5                   XREF[3]:     00432182(R), 004321aa(*), 004321c5(R)
//                               ?DPEnumCallback@@YGHPAU_GUID@@PADKKPAX@Z                     XREF[1]:     TCommunications_Services:0043200d(
//                               DPEnumCallback
//                              com_serv.cpp:123 (2)
//         00432180     PUSH       EBX
//         00432181     PUSH       ESI
//                              com_serv.cpp:133 (14)
//         00432182     MOV        ESI,dword ptr [ESP + param_5]
//         00432186     PUSH       EDI
//         00432187     MOV        ECX,ESI
//         00432189     CALL       TCommunications_Services::GetServiceCount        int GetServiceCount(TCommunications_Services
//         0043218e     MOV        EDI,EAX
//                              com_serv.cpp:136 (13)
//         00432190     MOV        EAX,dword ptr [ESP + param_2]
//         00432194     PUSH       EAX
//         00432195     PUSH       EDI
//         00432196     MOV        ECX,ESI
//         00432198     CALL       TCommunications_Services::SetServiceName         int SetServiceName(TCommunications_Services *
//                              com_serv.cpp:140 (13)
//         0043219d     MOV        ECX,ESI
//         0043219f     MOV        EBX,dword ptr [ESP + param_1]
//         004321a3     PUSH       EBX
//         004321a4     PUSH       EDI
//         004321a5     CALL       TCommunications_Services::EnumServiceGUID        void EnumServiceGUID(TCommunications_Services
//                              com_serv.cpp:144 (13)
//         004321aa     LEA        ECX=>param_5,[ESP + 0x20]
//         004321ae     PUSH       0x0
//         004321b0     PUSH       ECX
//         004321b1     PUSH       EBX
//         004321b2     CALL       _DirectPlayCreate@12                             undefined _DirectPlayCreate@12()
//                              com_serv.cpp:146 (4)
//         004321b7     TEST       EAX,EAX
//         004321b9     JNZ        LAB_004321e1
//                              com_serv.cpp:148 (10)
//         004321bb     PUSH       0x1
//         004321bd     PUSH       EDI
//         004321be     MOV        ECX,ESI
//         004321c0     CALL       TCommunications_Services::SetServiceActive       void SetServiceActive(TCommunications_Service
//                              com_serv.cpp:150 (10)
//         004321c5     MOV        EAX,dword ptr [ESP + param_5]
//         004321c9     PUSH       EAX
//         004321ca     MOV        EDX,dword ptr [EAX]
//         004321cc     CALL       dword ptr [EDX + 0x8]
//                              com_serv.cpp:159 (7)
//         004321cf     MOV        ECX,ESI
//         004321d1     CALL       TCommunications_Services::IncServiceCount        int IncServiceCount(TCommunications_Services
//                              com_serv.cpp:161 (5)
//         004321d6     MOV        EAX,0x1
//                              com_serv.cpp:162 (6)
//         004321db     POP        EDI
//         004321dc     POP        ESI
//         004321dd     POP        EBX
//         004321de     RET        0x14
//                               LAB_004321e1                                                 XREF[1]:     004321b9(j)
//                              com_serv.cpp:154 (10)
//         004321e1     PUSH       0x0
//         004321e3     PUSH       EDI
//         004321e4     MOV        ECX,ESI
//         004321e6     CALL       TCommunications_Services::SetServiceActive       void SetServiceActive(TCommunications_Service
//                              com_serv.cpp:159 (7)
//         004321eb     MOV        ECX,ESI
//         004321ed     CALL       TCommunications_Services::IncServiceCount        int IncServiceCount(TCommunications_Services
//                              com_serv.cpp:162 (11)
//         004321f2     POP        EDI
//         004321f3     POP        ESI
//         004321f4     MOV        EAX,0x1
//         004321f9     POP        EBX
//         004321fa     RET        0x14
//         004321fd     ??         90h
//         004321fe     NOP
//         004321ff     NOP
    return 0;
}

