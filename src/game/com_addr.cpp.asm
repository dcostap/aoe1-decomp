#include "common.h"
#include "com_addr.h"

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

RGE_Communications_Addresses::~RGE_Communications_Addresses() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Communications_Addresses(RGE_Communications_Add
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ??1RGE_Communications_Addresses@@QAE@XZ                      XREF[1]:     showNetInfo:004a2b6e(c)  
    //                               RGE_Communications_Addresses::~RGE_Communications_Addresses
    //                              com_addr.cpp:82 (3)
    //         00424b10     PUSH       ESI
    //         00424b11     MOV        ESI,this
    //                              com_addr.cpp:83 (5)
    //         00424b13     CALL       RGE_Communications_Addresses::EraseInformation   void EraseInformation(RGE_Communications_Addr
    //                              com_addr.cpp:87 (10)
    //         00424b18     MOV        EAX,dword ptr [ESI + 0x214]
    //         00424b1e     TEST       EAX,EAX
    //         00424b20     JZ         LAB_00424b27
    //                              com_addr.cpp:88 (5)
    //         00424b22     CALL       _WSACleanup@0                                    undefined _WSACleanup@0()
    //                               LAB_00424b27                                                 XREF[1]:     00424b20(j)  
    //                              com_addr.cpp:89 (42)
    //         00424b27     MOV        EAX,dword ptr [ESI + 0x220]
    //         00424b2d     TEST       EAX,EAX
    //         00424b2f     JZ         LAB_00424b51
    //         00424b31     MOV        this,dword ptr [EAX + -0x4]
    //         00424b34     LEA        ESI,[EAX + -0x4]
    //         00424b37     PUSH       IPAD::~IPAD
    //         00424b3c     PUSH       this=>DAT_fffffff8
    //         00424b3d     PUSH       offset DAT_fffffff4
    //         00424b42     PUSH       EAX=>DAT_fffffff0
    //         00424b43     CALL       `eh_vector_destructor_iterator'                  void `eh_vector_destructor_iterator'(void * p
    //         00424b48     PUSH       ESI
    //         00424b49     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00424b4e     ADD        ESP,0x4
    //                               LAB_00424b51                                                 XREF[1]:     00424b2f(j)  
    //                              com_addr.cpp:90 (2)
    //         00424b51     POP        ESI
    //         00424b52     RET
    //         00424b53     ??         90h
    //         00424b54     NOP
    //         00424b55     NOP
    //         00424b56     NOP
    //         00424b57     NOP
    //         00424b58     NOP
    //         00424b59     NOP
    //         00424b5a     NOP
    //         00424b5b     NOP
    //         00424b5c     NOP
    //         00424b5d     NOP
    //         00424b5e     NOP
    //         00424b5f     NOP
}

char* RGE_Communications_Addresses::GetHostName() {
    /* TODO: Stub */
    //                              char * __thiscall GetHostName(RGE_Communications_Addresses * this)
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?GetHostName@RGE_Communications_Addresses@@QAEPADXZ          XREF[2]:     RGE_Communications_Addresses:00424
    //                               RGE_Communications_Addresses::GetHostName                                 showNetInfo:004a29c3(c)  
    //                              com_addr.cpp:93 (1)
    //         00424b60     PUSH       ESI
    //                              com_addr.cpp:95 (17)
    //         00424b61     LEA        ESI,[ECX + this->hostname[0]]
    //                              language.dll match for 0x80: "Arial"
    //         00424b67     PUSH       0x80
    //         00424b6c     PUSH       ESI
    //         00424b6d     CALL       gethostname                                      undefined gethostname()
    //                              com_addr.cpp:96 (2)
    //         00424b72     MOV        EAX,ESI
    //                              com_addr.cpp:97 (2)
    //         00424b74     POP        ESI
    //         00424b75     RET
    //         00424b76     ??         90h
    //         00424b77     NOP
    //         00424b78     NOP
    //         00424b79     NOP
    //         00424b7a     NOP
    //         00424b7b     NOP
    //         00424b7c     NOP
    //         00424b7d     NOP
    //         00424b7e     NOP
    //         00424b7f     NOP
    return 0;
}

int RGE_Communications_Addresses::SetIPAliases(char* param_1) {
    /* TODO: Stub */
    //                              int __thiscall SetIPAliases(RGE_Communications_Addresses * this, cha
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //                               ?SetIPAliases@RGE_Communications_Addresses@@IAEHPAD@Z        XREF[1]:     RGE_Communications_Addresses:00424
    //                               RGE_Communications_Addresses::SetIPAliases
    //                              com_addr.cpp:100 (5)
    //         00424b80     PUSH       EBX
    //         00424b81     MOV        EBX,this
    //         00424b83     PUSH       EBP
    //         00424b84     PUSH       ESI
    //                              com_addr.cpp:104 (11)
    //         00424b85     LEA        EAX,[EBX + 0x194]
    //         00424b8b     PUSH       EDI
    //         00424b8c     TEST       EAX,EAX
    //         00424b8e     JNZ        LAB_00424b97
    //                              com_addr.cpp:135 (7)
    //         00424b90     POP        EDI
    //         00424b91     POP        ESI
    //         00424b92     POP        EBP
    //         00424b93     POP        EBX
    //         00424b94     RET        0x4
    //                               LAB_00424b97                                                 XREF[1]:     00424b8e(j)  
    //                              com_addr.cpp:112 (6)
    //         00424b97     PUSH       EAX
    //         00424b98     CALL       gethostbyname                                    undefined gethostbyname()
    //                              com_addr.cpp:114 (4)
    //         00424b9d     TEST       EAX,EAX
    //         00424b9f     JNZ        LAB_00424ba8
    //                              com_addr.cpp:135 (7)
    //         00424ba1     POP        EDI
    //         00424ba2     POP        ESI
    //         00424ba3     POP        EBP
    //         00424ba4     POP        EBX
    //         00424ba5     RET        0x4
    //                               LAB_00424ba8                                                 XREF[1]:     00424b9f(j)  
    //                              com_addr.cpp:117 (7)
    //         00424ba8     MOV        this,dword ptr [ESP + 0x14]
    //         00424bac     MOV        byte ptr [this->comm],0x0
    //                              com_addr.cpp:120 (3)
    //         00424baf     MOV        EDX,dword ptr [EAX + 0x4]
    //                              com_addr.cpp:122 (10)
    //         00424bb2     MOV        dword ptr [EBX + 0x21c],0x0
    //                              com_addr.cpp:124 (6)
    //         00424bbc     MOV        EDI,dword ptr [EDX]
    //         00424bbe     TEST       EDI,EDI
    //         00424bc0     JZ         LAB_00424c0b
    //                               LAB_00424bc2                                                 XREF[1]:     00424c09(j)  
    //                              com_addr.cpp:130 (12)
    //         00424bc2     MOV        EAX,dword ptr [EBX + 0x21c]
    //         00424bc8     MOV        this,dword ptr [EBX + 0x220]
    //                              com_addr.cpp:132 (61)
    //         00424bce     ADD        EDX,0x4
    //         00424bd1     LEA        EAX,[EAX + EAX*0x4]
    //         00424bd4     SHL        EAX,0x5
    //         00424bd7     LEA        EBP,[EAX + this->comm*0x1 + 0x20]
    //         00424bdb     OR         this,0xffffffff
    //         00424bde     XOR        EAX,EAX
    //         00424be0     SCASB.RE   ES:EDI
    //         00424be2     NOT        this
    //         00424be4     SUB        EDI,this
    //         00424be6     MOV        EAX,this
    //         00424be8     MOV        ESI,EDI
    //         00424bea     MOV        EDI,EBP
    //         00424bec     SHR        this,0x2
    //         00424bef     MOVSD.REP  ES:EDI,ESI
    //         00424bf1     MOV        this,EAX
    //         00424bf3     AND        this,0x3
    //         00424bf6     MOVSB.REP  ES:EDI,ESI
    //         00424bf8     MOV        ESI,dword ptr [EBX + 0x21c]
    //         00424bfe     INC        ESI
    //         00424bff     MOV        dword ptr [EBX + 0x21c],ESI
    //         00424c05     MOV        EDI,dword ptr [EDX]
    //         00424c07     TEST       EDI,EDI
    //         00424c09     JNZ        LAB_00424bc2
    //                               LAB_00424c0b                                                 XREF[1]:     00424bc0(j)  
    //                              com_addr.cpp:134 (6)
    //         00424c0b     MOV        EAX,dword ptr [EBX + 0x21c]
    //                              com_addr.cpp:135 (7)
    //         00424c11     POP        EDI
    //         00424c12     POP        ESI
    //         00424c13     POP        EBP
    //         00424c14     POP        EBX
    //         00424c15     RET        0x4
    //         00424c18     ??         90h
    //         00424c19     NOP
    //         00424c1a     NOP
    //         00424c1b     NOP
    //         00424c1c     NOP
    //         00424c1d     NOP
    //         00424c1e     NOP
    //         00424c1f     NOP
    return 0;
}

char* RGE_Communications_Addresses::GetAddress(uint param_1) {
    /* TODO: Stub */
    //                              char * __thiscall GetAddress(RGE_Communications_Addresses * this, ui
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00424c20(R)  
    //                               ?GetAddress@RGE_Communications_Addresses@@QAEPADI@Z          XREF[2]:     showNetInfo:004a2a53(c), 
    //                               RGE_Communications_Addresses::GetAddress                                  showNetInfo:004a2a5f(c)  
    //                              com_addr.cpp:138 (29)
    //         00424c20     MOV        EDX,dword ptr [ESP + param_1]
    //         00424c24     PUSH       ESI
    //         00424c25     MOV        ESI,dword ptr [ECX + this->pIPAD]
    //         00424c2b     LEA        EAX,[EDX + EDX*0x4]
    //         00424c2e     SHL        EAX,0x5
    //         00424c31     ADD        EAX,ESI
    //         00424c33     TEST       EAX,EAX
    //         00424c35     JZ         LAB_00424c3f
    //         00424c37     CMP        EDX,dword ptr [ECX + this->AddressesAvailable]
    //                              com_addr.cpp:142 (2)
    //         00424c3d     JBE        LAB_00424c44
    //                               LAB_00424c3f                                                 XREF[1]:     00424c35(j)  
    //                              com_addr.cpp:140 (5)
    //         00424c3f     MOV        EAX,s__                                          = 20h
    //                               LAB_00424c44                                                 XREF[1]:     00424c3d(j)  
    //                              com_addr.cpp:143 (4)
    //         00424c44     POP        ESI
    //         00424c45     RET        0x4
    //         00424c48     ??         90h
    //         00424c49     NOP
    //         00424c4a     NOP
    //         00424c4b     NOP
    //         00424c4c     NOP
    //         00424c4d     NOP
    //         00424c4e     NOP
    //         00424c4f     NOP
    return 0;
}

char* RGE_Communications_Addresses::GetAlias(uint param_1) {
    /* TODO: Stub */
    //                              char * __thiscall GetAlias(RGE_Communications_Addresses * this, uint
    //              char *            EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00424c50(R)  
    //                               ?GetAlias@RGE_Communications_Addresses@@QAEPADI@Z            XREF[2]:     showNetInfo:004a2abe(c), 
    //                               RGE_Communications_Addresses::GetAlias                                    showNetInfo:004a2aca(c)  
    //                              com_addr.cpp:146 (12)
    //         00424c50     MOV        EAX,dword ptr [ESP + param_1]
    //         00424c54     MOV        EDX,dword ptr [ECX + this->AliasesAvailable]
    //         00424c5a     CMP        EAX,EDX
    //                              com_addr.cpp:148 (2)
    //         00424c5c     JA         LAB_00424c72
    //                              com_addr.cpp:150 (20)
    //         00424c5e     MOV        this,dword ptr [ECX + this->pIPAD]
    //         00424c64     LEA        EAX,[EAX + EAX*0x4]
    //         00424c67     SHL        EAX,0x5
    //         00424c6a     LEA        EAX,[EAX + this->comm*0x1 + 0x20]
    //         00424c6e     TEST       EAX,EAX
    //         00424c70     JNZ        LAB_00424c77
    //                               LAB_00424c72                                                 XREF[1]:     00424c5c(j)  
    //                              com_addr.cpp:151 (5)
    //         00424c72     MOV        EAX,s__                                          = 20h
    //                               LAB_00424c77                                                 XREF[1]:     00424c70(j)  
    //                              com_addr.cpp:154 (3)
    //         00424c77     RET        0x4
    //         00424c7a     ??         90h
    //         00424c7b     NOP
    //         00424c7c     NOP
    //         00424c7d     NOP
    //         00424c7e     NOP
    //         00424c7f     NOP
    return 0;
}

int RGE_Communications_Addresses::SetIPAddresses(char* param_1) {
    /* TODO: Stub */
    //                              int __thiscall SetIPAddresses(RGE_Communications_Addresses * this, c
    //              int               EAX:4          <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1
    //              char[25]          Stack[-0x20]   temp
    //                               ?SetIPAddresses@RGE_Communications_Addresses@@IAEHPAD@Z      XREF[1]:     RGE_Communications_Addresses:00424
    //                               RGE_Communications_Addresses::SetIPAddresses
    //                              com_addr.cpp:157 (8)
    //         00424c80     SUB        ESP,0x1c
    //         00424c83     PUSH       EBX
    //         00424c84     MOV        EBX,this
    //         00424c86     PUSH       EBP
    //         00424c87     PUSH       ESI
    //                              com_addr.cpp:161 (11)
    //         00424c88     LEA        EAX,[EBX + 0x194]
    //         00424c8e     PUSH       EDI
    //         00424c8f     TEST       EAX,EAX
    //         00424c91     JNZ        LAB_00424c9d
    //                              com_addr.cpp:198 (10)
    //         00424c93     POP        EDI
    //         00424c94     POP        ESI
    //         00424c95     POP        EBP
    //         00424c96     POP        EBX
    //         00424c97     ADD        ESP,0x1c
    //         00424c9a     RET        0x4
    //                               LAB_00424c9d                                                 XREF[1]:     00424c91(j)  
    //                              com_addr.cpp:169 (6)
    //         00424c9d     PUSH       EAX
    //         00424c9e     CALL       gethostbyname                                    undefined gethostbyname()
    //                              com_addr.cpp:171 (4)
    //         00424ca3     TEST       EAX,EAX
    //         00424ca5     JNZ        LAB_00424cb1
    //                              com_addr.cpp:198 (10)
    //         00424ca7     POP        EDI
    //         00424ca8     POP        ESI
    //         00424ca9     POP        EBP
    //         00424caa     POP        EBX
    //         00424cab     ADD        ESP,0x1c
    //         00424cae     RET        0x4
    //                               LAB_00424cb1                                                 XREF[1]:     00424ca5(j)  
    //                              com_addr.cpp:174 (7)
    //         00424cb1     MOV        this,dword ptr [ESP + 0x30]
    //         00424cb5     MOV        byte ptr [this->comm],0x0
    //                              com_addr.cpp:179 (3)
    //         00424cb8     MOV        EBP,dword ptr [EAX + 0xc]
    //                              com_addr.cpp:181 (10)
    //         00424cbb     MOV        dword ptr [EBX + 0x218],0x0
    //                              com_addr.cpp:183 (11)
    //         00424cc5     MOV        EAX,dword ptr [EBP]
    //         00424cc8     TEST       EAX,EAX
    //         00424cca     JZ         LAB_00424d74
    //                               LAB_00424cd0                                                 XREF[1]:     00424d6e(j)  
    //                              com_addr.cpp:189 (38)
    //         00424cd0     XOR        EDX,EDX
    //         00424cd2     XOR        this,this
    //         00424cd4     MOV        DL,byte ptr [EAX + 0x3]
    //         00424cd7     MOV        this,byte ptr [EAX + 0x2]
    //         00424cda     PUSH       EDX
    //         00424cdb     PUSH       this=>DAT_fffffff8
    //         00424cdc     XOR        EDX,EDX
    //         00424cde     XOR        this,this
    //         00424ce0     MOV        DL,byte ptr [EAX + 0x1]
    //         00424ce3     MOV        this,byte ptr [EAX]
    //         00424ce5     PUSH       EDX=>DAT_fffffff4
    //         00424ce6     PUSH       this=>DAT_fffffff0
    //         00424ce7     LEA        EDX,[ESP + 0x20]
    //         00424ceb     PUSH       s_%d.%d.%d.%d_                                   = "%d.%d.%d.%d\n"
    //         00424cf0     PUSH       EDX
    //         00424cf1     CALL       sprintf                                          undefined sprintf()
    //                              com_addr.cpp:190 (18)
    //         00424cf6     LEA        EDI,[ESP + 0x28]
    //         00424cfa     OR         this,0xffffffff
    //         00424cfd     XOR        EAX,EAX
    //         00424cff     ADD        ESP,0x18
    //         00424d02     SCASB.RE   ES:EDI
    //         00424d04     NOT        this
    //         00424d06     SUB        EDI,this
    //                              com_addr.cpp:194 (108)
    //         00424d08     ADD        EBP,0x4
    //         00424d0b     MOV        ESI,EDI
    //         00424d0d     MOV        EDI,dword ptr [ESP + 0x30]
    //         00424d11     MOV        EDX,this
    //         00424d13     OR         this,0xffffffff
    //         00424d16     SCASB.RE   ES:EDI
    //         00424d18     MOV        this,EDX
    //         00424d1a     DEC        EDI
    //         00424d1b     SHR        this,0x2
    //         00424d1e     MOVSD.REP  ES:EDI,ESI
    //         00424d20     MOV        this,EDX
    //         00424d22     AND        this,0x3
    //         00424d25     MOVSB.REP  ES:EDI,ESI
    //         00424d27     MOV        EAX,dword ptr [EBX + 0x218]
    //         00424d2d     MOV        this,dword ptr [EBX + 0x220]
    //         00424d33     LEA        EDI,[ESP + 0x10]
    //         00424d37     LEA        EDX,[EAX + EAX*0x4]
    //         00424d3a     XOR        EAX,EAX
    //         00424d3c     SHL        EDX,0x5
    //         00424d3f     ADD        EDX,this
    //         00424d41     OR         this,0xffffffff
    //         00424d44     SCASB.RE   ES:EDI
    //         00424d46     NOT        this
    //         00424d48     SUB        EDI,this
    //         00424d4a     MOV        EAX,this
    //         00424d4c     MOV        ESI,EDI
    //         00424d4e     MOV        EDI,EDX
    //         00424d50     SHR        this,0x2
    //         00424d53     MOVSD.REP  ES:EDI,ESI
    //         00424d55     MOV        this,EAX
    //         00424d57     AND        this,0x3
    //         00424d5a     MOVSB.REP  ES:EDI,ESI
    //         00424d5c     MOV        ESI,dword ptr [EBX + 0x218]
    //         00424d62     INC        ESI
    //         00424d63     MOV        dword ptr [EBX + 0x218],ESI
    //         00424d69     MOV        EAX,dword ptr [EBP]
    //         00424d6c     TEST       EAX,EAX
    //         00424d6e     JNZ        LAB_00424cd0
    //                               LAB_00424d74                                                 XREF[1]:     00424cca(j)  
    //                              com_addr.cpp:197 (6)
    //         00424d74     MOV        EAX,dword ptr [EBX + 0x218]
    //                              com_addr.cpp:198 (10)
    //         00424d7a     POP        EDI
    //         00424d7b     POP        ESI
    //         00424d7c     POP        EBP
    //         00424d7d     POP        EBX
    //         00424d7e     ADD        ESP,0x1c
    //         00424d81     RET        0x4
    //         00424d84     ??         90h
    //         00424d85     NOP
    //         00424d86     NOP
    //         00424d87     NOP
    //         00424d88     NOP
    //         00424d89     NOP
    //         00424d8a     NOP
    //         00424d8b     NOP
    //         00424d8c     NOP
    //         00424d8d     NOP
    //         00424d8e     NOP
    //         00424d8f     NOP
    return 0;
}

void RGE_Communications_Addresses::EraseInformation() {
    /* TODO: Stub */
    //                              void __thiscall EraseInformation(RGE_Communications_Addresses * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //                               ?EraseInformation@RGE_Communications_Addresses@@IAEXXZ       XREF[2]:     RGE_Communications_Addresses:00424
    //                               RGE_Communications_Addresses::EraseInformation                            ~RGE_Communications_Addresses:0042
    //                              com_addr.cpp:202 (5)
    //         00424d90     PUSH       EBX
    //         00424d91     PUSH       ESI
    //         00424d92     MOV        EDX,this
    //         00424d94     PUSH       EDI
    //                              com_addr.cpp:203 (35)
    //         00424d95     MOV        EDI,s_                                           = ""
    //         00424d9a     OR         this,0xffffffff
    //         00424d9d     XOR        EAX,EAX
    //         00424d9f     LEA        EBX,[EDX + 0x194]
    //         00424da5     SCASB.RE   ES:EDI=>s_                                       = ""
    //         00424da7     NOT        this
    //         00424da9     SUB        EDI,this
    //         00424dab     MOV        EAX,this
    //         00424dad     MOV        ESI,EDI
    //         00424daf     MOV        EDI,EBX
    //         00424db1     SHR        this,0x2
    //         00424db4     MOVSD.REP  ES:EDI,ESI
    //         00424db6     MOV        this,EAX
    //                              com_addr.cpp:204 (7)
    //         00424db8     XOR        EAX,EAX
    //         00424dba     AND        this,0x3
    //         00424dbd     MOVSB.REP  ES:EDI,ESI
    //                              com_addr.cpp:206 (16)
    //         00424dbf     POP        EDI
    //         00424dc0     POP        ESI
    //         00424dc1     MOV        dword ptr [EDX + 0x21c],EAX
    //         00424dc7     MOV        dword ptr [EDX + 0x218],EAX
    //         00424dcd     POP        EBX
    //         00424dce     RET
    //         00424dcf     ??         90h
    return;
}

RGE_Communications_Addresses::RGE_Communications_Addresses(TCommunications_Handler* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
}

