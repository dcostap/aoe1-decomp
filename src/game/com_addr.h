#pragma once
#include "../common.h"
#include "Com_hand.h"

class RGE_Communications_Addresses {
public:
    WSAData wsaData;                         // 0x4
    char hostname[128];                      // 0x194
    int Status;                              // 0x214
    uint AddressesAvailable;                 // 0x218
    uint AliasesAvailable;                   // 0x21C
    IPAD* pIPAD;                             // 0x220

    RGE_Communications_Addresses(TCommunications_Handler* param_1);
    virtual ~RGE_Communications_Addresses();
    virtual char* GetHostName();
    virtual int SetIPAliases(char* param_1);
    virtual char* GetAddress(uint param_1);
    virtual char* GetAlias(uint param_1);
    virtual int SetIPAddresses(char* param_1);
    virtual void EraseInformation();
};

static_assert(sizeof(RGE_Communications_Addresses) == 0x224, "RGE_Communications_Addresses Size Mismatch");
static_assert(offsetof(RGE_Communications_Addresses, pIPAD) == 0x220, "RGE_Communications_Addresses Offset Mismatch");

class IPAD {
public:
    char DottedIPAddress[32];
    char Alias[128];                         // 0x20
    IPAD();
    ~IPAD();
};

static_assert(sizeof(IPAD) == 0xA0, "IPAD Size Mismatch");
static_assert(offsetof(IPAD, Alias) == 0x20, "IPAD Offset Mismatch");

IPAD::IPAD() {
    /* TODO: Stub */
//                              undefined __thiscall IPAD(IPAD * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              IPAD *            ECX:4 (auto)   this
//                               ??0IPAD@@QAE@XZ                                              XREF[1]:     RGE_Communications_Addresses:00424
//                               IPAD::IPAD
//                              com_addr.h:46 (5)
//         00424dd0     PUSH       EBX
//         00424dd1     PUSH       ESI
//         00424dd2     MOV        EDX,this
//         00424dd4     PUSH       EDI
//                              com_addr.h:48 (10)
//         00424dd5     MOV        EDI,s_                                           = ""
//         00424dda     OR         this,0xffffffff
//         00424ddd     XOR        EAX,EAX
//                              com_addr.h:49 (56)
//         00424ddf     LEA        EBX,[EDX + 0x20]
//         00424de2     SCASB.RE   ES:EDI=>s_                                       = ""
//         00424de4     NOT        this
//         00424de6     SUB        EDI,this
//         00424de8     MOV        EAX,this
//         00424dea     MOV        ESI,EDI
//         00424dec     MOV        EDI,EDX
//         00424dee     SHR        this,0x2
//         00424df1     MOVSD.REP  ES:EDI,ESI
//         00424df3     MOV        this,EAX
//         00424df5     XOR        EAX,EAX
//         00424df7     AND        this,0x3
//         00424dfa     MOVSB.REP  ES:EDI,ESI
//         00424dfc     MOV        EDI,s_                                           = ""
//         00424e01     OR         this,0xffffffff
//         00424e04     SCASB.RE   ES:EDI=>s_                                       = ""
//         00424e06     NOT        this
//         00424e08     SUB        EDI,this
//         00424e0a     MOV        EAX,this
//         00424e0c     MOV        ESI,EDI
//         00424e0e     MOV        EDI,EBX
//         00424e10     SHR        this,0x2
//         00424e13     MOVSD.REP  ES:EDI,ESI
//         00424e15     MOV        this,EAX
//                              com_addr.h:50 (11)
//         00424e17     MOV        EAX,EDX
//         00424e19     AND        this,0x3
//         00424e1c     MOVSB.REP  ES:EDI,ESI
//         00424e1e     POP        EDI
//         00424e1f     POP        ESI
//         00424e20     POP        EBX
//         00424e21     RET
//         00424e22     ??         90h
//         00424e23     NOP
//         00424e24     NOP
//         00424e25     NOP
//         00424e26     NOP
//         00424e27     NOP
//         00424e28     NOP
//         00424e29     NOP
//         00424e2a     NOP
//         00424e2b     NOP
//         00424e2c     NOP
//         00424e2d     NOP
//         00424e2e     NOP
//         00424e2f     NOP
}

IPAD::~IPAD() {
    /* TODO: Stub */
//                              void __thiscall ~IPAD(IPAD * this)
//              void              <VOID>         <RETURN>
//              IPAD *            ECX:4 (auto)   this
//                               ??1IPAD@@QAE@XZ                                              XREF[3]:     RGE_Communications_Addresses:00424
//                               IPAD::~IPAD                                                               `vector_deleting_destructor':00424
//                                                                                                         ~RGE_Communications_Addresses:0042
//                              com_addr.h:53 (1)
//         00424e30     RET
//         00424e31     ??         90h
//         00424e32     NOP
//         00424e33     NOP
//         00424e34     NOP
//         00424e35     NOP
//         00424e36     NOP
//         00424e37     NOP
//         00424e38     NOP
//         00424e39     NOP
//         00424e3a     NOP
//         00424e3b     NOP
//         00424e3c     NOP
//         00424e3d     NOP
//         00424e3e     NOP
//         00424e3f     NOP
}

