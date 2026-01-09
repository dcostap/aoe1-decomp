#include "common.h"
#include "victory.h"

RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Victory_Conditions(RGE_Victory_Conditions *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     00531af2(R)  
    //                               ??0RGE_Victory_Conditions@@QAE@PAVRGE_Player@@@Z             XREF[2]:     new_victory:00471d36(c), 
    //                               RGE_Victory_Conditions::RGE_Victory_Conditions                            TRIBE_Victory_Conditions:0052c928(
    //                              victory.cpp:150 (2)
    //         00531af0     MOV        EAX,this
    //                              victory.cpp:151 (7)
    //         00531af2     MOV        this,dword ptr [ESP + param_1]
    //         00531af6     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:152 (11)
    //         00531af9     XOR        this,this
    //         00531afb     MOV        dword ptr [EAX],RGE_Victory_Conditions::`vftab   = 00531f30
    //         00531b01     MOV        dword ptr [EAX + 0x8],this
    //                              victory.cpp:153 (3)
    //         00531b04     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:154 (3)
    //         00531b07     MOV        dword ptr [EAX + 0x14],this
    //                              victory.cpp:155 (3)
    //         00531b0a     MOV        byte ptr [EAX + 0x10],this
    //                              victory.cpp:156 (3)
    //         00531b0d     MOV        dword ptr [EAX + 0x18],this
    //                              victory.cpp:157 (3)
    //         00531b10     MOV        dword ptr [EAX + 0x1c],this
    //                              victory.cpp:158 (3)
    //         00531b13     RET        0x4
    //         00531b16     ??         90h
    //         00531b17     NOP
    //         00531b18     NOP
    //         00531b19     NOP
    //         00531b1a     NOP
    //         00531b1b     NOP
    //         00531b1c     NOP
    //         00531b1d     NOP
    //         00531b1e     NOP
    //         00531b1f     NOP
}

RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Victory_Conditions(RGE_Victory_Conditions *
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     00531af2(R)  
    //                               ??0RGE_Victory_Conditions@@QAE@PAVRGE_Player@@@Z             XREF[2]:     new_victory:00471d36(c), 
    //                               RGE_Victory_Conditions::RGE_Victory_Conditions                            TRIBE_Victory_Conditions:0052c928(
    //                              victory.cpp:150 (2)
    //         00531af0     MOV        EAX,this
    //                              victory.cpp:151 (7)
    //         00531af2     MOV        this,dword ptr [ESP + param_1]
    //         00531af6     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:152 (11)
    //         00531af9     XOR        this,this
    //         00531afb     MOV        dword ptr [EAX],RGE_Victory_Conditions::`vftab   = 00531f30
    //         00531b01     MOV        dword ptr [EAX + 0x8],this
    //                              victory.cpp:153 (3)
    //         00531b04     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:154 (3)
    //         00531b07     MOV        dword ptr [EAX + 0x14],this
    //                              victory.cpp:155 (3)
    //         00531b0a     MOV        byte ptr [EAX + 0x10],this
    //                              victory.cpp:156 (3)
    //         00531b0d     MOV        dword ptr [EAX + 0x18],this
    //                              victory.cpp:157 (3)
    //         00531b10     MOV        dword ptr [EAX + 0x1c],this
    //                              victory.cpp:158 (3)
    //         00531b13     RET        0x4
    //         00531b16     ??         90h
    //         00531b17     NOP
    //         00531b18     NOP
    //         00531b19     NOP
    //         00531b1a     NOP
    //         00531b1b     NOP
    //         00531b1c     NOP
    //         00531b1d     NOP
    //         00531b1e     NOP
    //         00531b1f     NOP
}

RGE_Victory_Conditions::~RGE_Victory_Conditions() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Victory_Conditions(RGE_Victory_Conditions * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //                               ??1RGE_Victory_Conditions@@QAE@XZ                            XREF[4]:     ~RGE_Player:0046eb7d(c), 
    //                               RGE_Victory_Conditions::~RGE_Victory_Conditions                           scenario_load:0046f683(c), 
    //                                                                                                         scenario_postload:0046fa10(c), 
    //                                                                                                         ~TRIBE_Victory_Conditions:0052c946
    //                              victory.cpp:163 (4)
    //         00531b20     PUSH       EBX
    //         00531b21     PUSH       ESI
    //         00531b22     MOV        ESI,this
    //                              victory.cpp:164 (15)
    //         00531b24     XOR        EBX,EBX
    //         00531b26     MOV        EAX,dword ptr [ESI + 0x4]
    //         00531b29     MOV        dword ptr [ESI],RGE_Victory_Conditions::`vftab   = 00531f30
    //         00531b2f     CMP        EAX,EBX
    //         00531b31     JZ         LAB_00531b42
    //                               LAB_00531b33                                                 XREF[1]:     00531b40(j)  
    //                              victory.cpp:165 (15)
    //         00531b33     PUSH       EAX
    //         00531b34     MOV        this,ESI
    //         00531b36     CALL       RGE_Victory_Conditions::sub                      void sub(RGE_Victory_Conditions * this, RGE_V
    //         00531b3b     MOV        EAX,dword ptr [ESI + 0x4]
    //         00531b3e     CMP        EAX,EBX
    //         00531b40     JNZ        LAB_00531b33
    //                               LAB_00531b42                                                 XREF[1]:     00531b31(j)  
    //                              victory.cpp:166 (7)
    //         00531b42     MOV        EAX,dword ptr [ESI + 0x14]
    //         00531b45     CMP        EAX,EBX
    //         00531b47     JZ         LAB_00531b58
    //                               LAB_00531b49                                                 XREF[1]:     00531b56(j)  
    //                              victory.cpp:167 (15)
    //         00531b49     PUSH       EAX
    //         00531b4a     MOV        this,ESI
    //         00531b4c     CALL       RGE_Victory_Conditions::sub_point                void sub_point(RGE_Victory_Conditions * this,
    //         00531b51     MOV        EAX,dword ptr [ESI + 0x14]
    //         00531b54     CMP        EAX,EBX
    //         00531b56     JNZ        LAB_00531b49
    //                               LAB_00531b58                                                 XREF[1]:     00531b47(j)  
    //                              victory.cpp:168 (3)
    //         00531b58     MOV        dword ptr [ESI + 0x8],EBX
    //                              victory.cpp:169 (3)
    //         00531b5b     MOV        dword ptr [ESI + 0x18],EBX
    //                              victory.cpp:170 (3)
    //         00531b5e     MOV        byte ptr [ESI + 0x10],BL
    //                              victory.cpp:171 (3)
    //         00531b61     MOV        dword ptr [ESI + 0xc],EBX
    //                              victory.cpp:172 (3)
    //         00531b64     POP        ESI
    //         00531b65     POP        EBX
    //         00531b66     RET
    //         00531b67     ??         90h
    //         00531b68     NOP
    //         00531b69     NOP
    //         00531b6a     NOP
    //         00531b6b     NOP
    //         00531b6c     NOP
    //         00531b6d     NOP
    //         00531b6e     NOP
    //         00531b6f     NOP
}

void RGE_Victory_Conditions::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Victory_Conditions * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[5]:     00531b76(R), 00531bcc(W), 00531bd2(W), 00531c02(W), 
    //                                                                                     00531c27(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00531b7b(*), 00531b85(W)  
    //              float             Stack[-0x8]:4  version                   XREF[3]:     00531bf4(W), 00531c08(W), 00531ca1(*)  
    //              long              Stack[-0xc]:4  target_obj                XREF[3]:     00531be0(W), 00531be6(W), 00531c91(*)  
    //              long              Stack[-0x10]:4 this_obj
    //                               ?save@RGE_Victory_Conditions@@UAEXH@Z                        XREF[2]:     0057734c(*), 005775b4(*)  
    //                               RGE_Victory_Conditions::save
    //                              victory.cpp:177 (6)
    //         00531b70     SUB        ESP,0xc
    //         00531b73     PUSH       EBX
    //         00531b74     PUSH       EBP
    //         00531b75     PUSH       ESI
    //                              victory.cpp:185 (31)
    //         00531b76     MOV        ESI,dword ptr [ESP + param_1]
    //         00531b7a     PUSH       EDI
    //         00531b7b     LEA        EAX=>local_4,[ESP + 0x18]
    //         00531b7f     PUSH       0x4
    //         00531b81     PUSH       EAX
    //         00531b82     MOV        EBX,this
    //         00531b84     PUSH       ESI
    //         00531b85     MOV        dword ptr [ESP + local_4],0x3f800000
    //         00531b8d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531b92     ADD        ESP,0xc
    //                              victory.cpp:188 (15)
    //         00531b95     LEA        this,[EBX + 0x8]
    //         00531b98     PUSH       0x4
    //         00531b9a     PUSH       this
    //         00531b9b     PUSH       ESI
    //         00531b9c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531ba1     ADD        ESP,0xc
    //                              victory.cpp:189 (12)
    //         00531ba4     LEA        EDX,[EBX + 0x10]
    //         00531ba7     PUSH       0x1
    //         00531ba9     PUSH       EDX
    //         00531baa     PUSH       ESI
    //         00531bab     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              victory.cpp:192 (17)
    //         00531bb0     MOV        EDI,dword ptr [EBX + 0x4]
    //         00531bb3     ADD        ESP,0xc
    //         00531bb6     TEST       EDI,EDI
    //         00531bb8     JZ         LAB_00531ce9
    //         00531bbe     OR         EBP,0xffffffff
    //                               LAB_00531bc1                                                 XREF[1]:     00531ce3(j)  
    //                              victory.cpp:194 (7)
    //         00531bc1     MOV        EAX,dword ptr [EDI + 0x8]
    //         00531bc4     TEST       EAX,EAX
    //         00531bc6     JZ         LAB_00531bd2
    //                              victory.cpp:195 (8)
    //         00531bc8     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         00531bcc     MOV        dword ptr [ESP + param_1],EAX
    //                              victory.cpp:196 (2)
    //         00531bd0     JMP        LAB_00531bd6
    //                               LAB_00531bd2                                                 XREF[1]:     00531bc6(j)  
    //                              victory.cpp:197 (4)
    //         00531bd2     MOV        dword ptr [ESP + param_1],EBP
    //                               LAB_00531bd6                                                 XREF[1]:     00531bd0(j)  
    //                              victory.cpp:199 (7)
    //         00531bd6     MOV        EAX,dword ptr [EDI + 0x24]
    //         00531bd9     TEST       EAX,EAX
    //         00531bdb     JZ         LAB_00531be6
    //                              victory.cpp:200 (7)
    //         00531bdd     MOV        this,dword ptr [EAX + 0x4]
    //         00531be0     MOV        dword ptr [ESP + target_obj],this
    //                              victory.cpp:201 (2)
    //         00531be4     JMP        LAB_00531bea
    //                               LAB_00531be6                                                 XREF[1]:     00531bdb(j)  
    //                              victory.cpp:202 (4)
    //         00531be6     MOV        dword ptr [ESP + target_obj],EBP
    //                               LAB_00531bea                                                 XREF[1]:     00531be4(j)  
    //                              victory.cpp:204 (7)
    //         00531bea     MOV        EAX,dword ptr [EDI + 0x28]
    //         00531bed     TEST       EAX,EAX
    //         00531bef     JZ         LAB_00531c08
    //                              victory.cpp:206 (7)
    //         00531bf1     MOV        EDX,dword ptr [EAX + 0x4]
    //         00531bf4     MOV        dword ptr [ESP + version],EDX
    //                              victory.cpp:207 (14)
    //         00531bf8     MOV        EAX,dword ptr [EDI + 0x28]
    //         00531bfb     MOV        this,dword ptr [EAX + 0xc]
    //         00531bfe     MOVSX      EDX,word ptr [this->_padding_ + 0x4a]
    //         00531c02     MOV        dword ptr [ESP + param_1],EDX
    //                              victory.cpp:209 (2)
    //         00531c06     JMP        LAB_00531c0c
    //                               LAB_00531c08                                                 XREF[1]:     00531bef(j)  
    //                              victory.cpp:210 (4)
    //         00531c08     MOV        dword ptr [ESP + version],EBP
    //                               LAB_00531c0c                                                 XREF[1]:     00531c06(j)  
    //                              victory.cpp:212 (12)
    //         00531c0c     PUSH       0x1
    //         00531c0e     PUSH       EDI
    //         00531c0f     PUSH       ESI
    //         00531c10     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c15     ADD        ESP,0xc
    //                              victory.cpp:213 (15)
    //         00531c18     LEA        EAX,[EDI + 0x4]
    //         00531c1b     PUSH       0x4
    //         00531c1d     PUSH       EAX
    //         00531c1e     PUSH       ESI
    //         00531c1f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c24     ADD        ESP,0xc
    //                              victory.cpp:214 (16)
    //         00531c27     LEA        this=>param_1,[ESP + 0x20]
    //         00531c2b     PUSH       0x4
    //         00531c2d     PUSH       this
    //         00531c2e     PUSH       ESI
    //         00531c2f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c34     ADD        ESP,0xc
    //                              victory.cpp:215 (15)
    //         00531c37     LEA        EDX,[EDI + 0xc]
    //         00531c3a     PUSH       0x4
    //         00531c3c     PUSH       EDX
    //         00531c3d     PUSH       ESI
    //         00531c3e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c43     ADD        ESP,0xc
    //                              victory.cpp:216 (15)
    //         00531c46     LEA        EAX,[EDI + 0x10]
    //         00531c49     PUSH       0x4
    //         00531c4b     PUSH       EAX
    //         00531c4c     PUSH       ESI
    //         00531c4d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c52     ADD        ESP,0xc
    //                              victory.cpp:217 (15)
    //         00531c55     LEA        this,[EDI + 0x14]
    //         00531c58     PUSH       0x4
    //         00531c5a     PUSH       this
    //         00531c5b     PUSH       ESI
    //         00531c5c     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c61     ADD        ESP,0xc
    //                              victory.cpp:218 (15)
    //         00531c64     LEA        EDX,[EDI + 0x18]
    //         00531c67     PUSH       0x4
    //         00531c69     PUSH       EDX
    //         00531c6a     PUSH       ESI
    //         00531c6b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c70     ADD        ESP,0xc
    //                              victory.cpp:219 (15)
    //         00531c73     LEA        EAX,[EDI + 0x1c]
    //         00531c76     PUSH       0x4
    //         00531c78     PUSH       EAX
    //         00531c79     PUSH       ESI
    //         00531c7a     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c7f     ADD        ESP,0xc
    //                              victory.cpp:220 (15)
    //         00531c82     LEA        this,[EDI + 0x20]
    //         00531c85     PUSH       0x4
    //         00531c87     PUSH       this
    //         00531c88     PUSH       ESI
    //         00531c89     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c8e     ADD        ESP,0xc
    //                              victory.cpp:221 (16)
    //         00531c91     LEA        EDX=>target_obj,[ESP + 0x10]
    //         00531c95     PUSH       0x4
    //         00531c97     PUSH       EDX
    //         00531c98     PUSH       ESI
    //         00531c99     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531c9e     ADD        ESP,0xc
    //                              victory.cpp:222 (16)
    //         00531ca1     LEA        EAX=>version,[ESP + 0x14]
    //         00531ca5     PUSH       0x4
    //         00531ca7     PUSH       EAX
    //         00531ca8     PUSH       ESI
    //         00531ca9     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531cae     ADD        ESP,0xc
    //                              victory.cpp:223 (15)
    //         00531cb1     LEA        this,[EDI + 0x2c]
    //         00531cb4     PUSH       0x1
    //         00531cb6     PUSH       this
    //         00531cb7     PUSH       ESI
    //         00531cb8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531cbd     ADD        ESP,0xc
    //                              victory.cpp:224 (15)
    //         00531cc0     LEA        EDX,[EDI + 0x2d]
    //         00531cc3     PUSH       0x1
    //         00531cc5     PUSH       EDX
    //         00531cc6     PUSH       ESI
    //         00531cc7     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531ccc     ADD        ESP,0xc
    //                              victory.cpp:225 (26)
    //         00531ccf     LEA        EAX,[EDI + 0x2e]
    //         00531cd2     PUSH       0x1
    //         00531cd4     PUSH       EAX
    //         00531cd5     PUSH       ESI
    //         00531cd6     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531cdb     MOV        EDI,dword ptr [EDI + 0x30]
    //         00531cde     ADD        ESP,0xc
    //         00531ce1     TEST       EDI,EDI
    //         00531ce3     JNZ        LAB_00531bc1
    //                               LAB_00531ce9                                                 XREF[1]:     00531bb8(j)  
    //                              victory.cpp:229 (15)
    //         00531ce9     LEA        this,[EBX + 0x1c]
    //         00531cec     PUSH       0x4
    //         00531cee     PUSH       this
    //         00531cef     PUSH       ESI
    //         00531cf0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531cf5     ADD        ESP,0xc
    //                              victory.cpp:230 (12)
    //         00531cf8     LEA        EDX,[EBX + 0x18]
    //         00531cfb     PUSH       0x4
    //         00531cfd     PUSH       EDX
    //         00531cfe     PUSH       ESI
    //         00531cff     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              victory.cpp:232 (14)
    //         00531d04     MOV        EDI,dword ptr [EBX + 0x14]
    //         00531d07     ADD        ESP,0xc
    //         00531d0a     TEST       EDI,EDI
    //         00531d0c     JZ         LAB_00531da1
    //                               LAB_00531d12                                                 XREF[1]:     00531d9b(j)  
    //                              victory.cpp:234 (12)
    //         00531d12     PUSH       0x1
    //         00531d14     PUSH       EDI
    //         00531d15     PUSH       ESI
    //         00531d16     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d1b     ADD        ESP,0xc
    //                              victory.cpp:235 (15)
    //         00531d1e     LEA        EAX,[EDI + 0x1]
    //         00531d21     PUSH       0x1
    //         00531d23     PUSH       EAX
    //         00531d24     PUSH       ESI
    //         00531d25     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d2a     ADD        ESP,0xc
    //                              victory.cpp:236 (15)
    //         00531d2d     LEA        this,[EDI + 0x4]
    //         00531d30     PUSH       0x4
    //         00531d32     PUSH       this
    //         00531d33     PUSH       ESI
    //         00531d34     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d39     ADD        ESP,0xc
    //                              victory.cpp:237 (15)
    //         00531d3c     LEA        EDX,[EDI + 0x8]
    //         00531d3f     PUSH       0x4
    //         00531d41     PUSH       EDX
    //         00531d42     PUSH       ESI
    //         00531d43     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d48     ADD        ESP,0xc
    //                              victory.cpp:238 (15)
    //         00531d4b     LEA        EAX,[EDI + 0xc]
    //         00531d4e     PUSH       0x4
    //         00531d50     PUSH       EAX
    //         00531d51     PUSH       ESI
    //         00531d52     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d57     ADD        ESP,0xc
    //                              victory.cpp:239 (15)
    //         00531d5a     LEA        this,[EDI + 0x10]
    //         00531d5d     PUSH       0x4
    //         00531d5f     PUSH       this
    //         00531d60     PUSH       ESI
    //         00531d61     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d66     ADD        ESP,0xc
    //                              victory.cpp:240 (15)
    //         00531d69     LEA        EDX,[EDI + 0x2]
    //         00531d6c     PUSH       0x1
    //         00531d6e     PUSH       EDX
    //         00531d6f     PUSH       ESI
    //         00531d70     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d75     ADD        ESP,0xc
    //                              victory.cpp:241 (15)
    //         00531d78     LEA        EAX,[EDI + 0x3]
    //         00531d7b     PUSH       0x1
    //         00531d7d     PUSH       EAX
    //         00531d7e     PUSH       ESI
    //         00531d7f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d84     ADD        ESP,0xc
    //                              victory.cpp:242 (26)
    //         00531d87     LEA        this,[EDI + 0x14]
    //         00531d8a     PUSH       0x4
    //         00531d8c     PUSH       this
    //         00531d8d     PUSH       ESI
    //         00531d8e     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00531d93     MOV        EDI,dword ptr [EDI + 0x18]
    //         00531d96     ADD        ESP,0xc
    //         00531d99     TEST       EDI,EDI
    //         00531d9b     JNZ        LAB_00531d12
    //                               LAB_00531da1                                                 XREF[1]:     00531d0c(j)  
    //                              victory.cpp:244 (10)
    //         00531da1     POP        EDI
    //         00531da2     POP        ESI
    //         00531da3     POP        EBP
    //         00531da4     POP        EBX
    //         00531da5     ADD        ESP,0xc
    //         00531da8     RET        0x4
    //         00531dab     ??         90h
    //         00531dac     NOP
    //         00531dad     NOP
    //         00531dae     NOP
    //         00531daf     NOP
    return;
}

void RGE_Victory_Conditions::check_for_victory() {
    /* TODO: Stub */
    //                              void __thiscall check_for_victory(RGE_Victory_Conditions * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00531dc0(W), 00531de7(R), 00531deb(R), 00531e68(R)  
    //              long              Stack[-0x8]:4  curr_victory_group        XREF[4]:     00531dc8(W), 00531e0b(R), 00531e10(W), 00531e74(R)  
    //              long              Stack[-0xc]:4  group_num                 XREF[3]:     00531dcc(W), 00531e54(RW), 00531e70(R)  
    //              long              Stack[-0x10]:4 failed_group_num          XREF[3]:     00531dc4(W), 00531e3a(RW), 00531e5e(R)  
    //              long              Stack[-0x14]:4 victory_void_num
    //                               ?check_for_victory@RGE_Victory_Conditions@@IAEXXZ            XREF[1]:     update:00531ed7(c)  
    //                               RGE_Victory_Conditions::check_for_victory
    //                              victory.cpp:250 (6)
    //         00531db0     SUB        ESP,0x10
    //         00531db3     MOV        EDX,this
    //         00531db5     PUSH       EBX
    //                              victory.cpp:255 (3)
    //         00531db6     XOR        this,this
    //         00531db8     PUSH       EBP
    //                              victory.cpp:260 (29)
    //         00531db9     MOV        EAX,dword ptr [EDX + 0x4]
    //         00531dbc     PUSH       ESI
    //         00531dbd     CMP        EAX,this
    //         00531dbf     PUSH       EDI
    //         00531dc0     MOV        dword ptr [ESP + local_4],EDX
    //         00531dc4     MOV        dword ptr [ESP + failed_group_num],this
    //         00531dc8     MOV        dword ptr [ESP + curr_victory_group],this
    //         00531dcc     MOV        dword ptr [ESP + group_num],this
    //         00531dd0     JZ         LAB_00531e80
    //                              victory.cpp:266 (7)
    //         00531dd6     CMP        EAX,this
    //         00531dd8     MOV        byte ptr [EDX + 0x10],this
    //         00531ddb     JZ         LAB_00531de7
    //                               LAB_00531ddd                                                 XREF[1]:     00531de5(j)  
    //                              victory.cpp:267 (10)
    //         00531ddd     MOV        byte ptr [EAX + 0x2f],this
    //         00531de0     MOV        EAX,dword ptr [EAX + 0x30]
    //         00531de3     CMP        EAX,this
    //         00531de5     JNZ        LAB_00531ddd
    //                               LAB_00531de7                                                 XREF[1]:     00531ddb(j)  
    //                              victory.cpp:266 (4)
    //         00531de7     MOV        EBP,dword ptr [ESP + local_4]
    //                               LAB_00531deb                                                 XREF[3]:     00531e58(j), 00531e5c(j), 
    //                                                                                                         00531e66(j)  
    //                              victory.cpp:273 (11)
    //         00531deb     MOV        ESI,dword ptr [ESP + local_4]
    //         00531def     MOV        EAX,dword ptr [ESI + 0x4]
    //         00531df2     CMP        EAX,this
    //         00531df4     JZ         LAB_00531e70
    //                               LAB_00531df6                                                 XREF[1]:     00531e00(j)  
    //                              victory.cpp:274 (14)
    //         00531df6     CMP        byte ptr [EAX + 0x2f],this
    //         00531df9     JZ         LAB_00531e04
    //         00531dfb     MOV        EAX,dword ptr [EAX + 0x30]
    //         00531dfe     CMP        EAX,this
    //         00531e00     JNZ        LAB_00531df6
    //         00531e02     JMP        LAB_00531e14
    //                               LAB_00531e04                                                 XREF[1]:     00531df9(j)  
    //                              victory.cpp:276 (7)
    //         00531e04     XOR        EDX,EDX
    //         00531e06     MOV        DL,byte ptr [EAX + 0x2c]
    //         00531e09     MOV        EBP,EDX
    //                              victory.cpp:277 (9)
    //         00531e0b     MOV        EDX,dword ptr [ESP + curr_victory_group]
    //         00531e0f     INC        EDX
    //         00531e10     MOV        dword ptr [ESP + curr_victory_group],EDX
    //                               LAB_00531e14                                                 XREF[1]:     00531e02(j)  
    //                              victory.cpp:282 (4)
    //         00531e14     CMP        EAX,this
    //         00531e16     JZ         LAB_00531e70
    //                              victory.cpp:285 (2)
    //         00531e18     XOR        ESI,ESI
    //                              victory.cpp:286 (2)
    //         00531e1a     XOR        EBX,EBX
    //                              victory.cpp:287 (2)
    //         00531e1c     XOR        EDI,EDI
    //                               LAB_00531e1e                                                 XREF[1]:     00531e4d(j)  
    //                              victory.cpp:290 (9)
    //         00531e1e     XOR        EDX,EDX
    //         00531e20     MOV        DL,byte ptr [EAX + 0x2c]
    //         00531e23     CMP        EDX,EBP
    //         00531e25     JNZ        LAB_00531e48
    //                              victory.cpp:294 (19)
    //         00531e27     XOR        EDX,EDX
    //         00531e29     INC        ESI
    //         00531e2a     MOV        DL,byte ptr [EAX + 0x2e]
    //         00531e2d     MOV        byte ptr [EAX + 0x2f],0x1
    //         00531e31     DEC        EDX
    //         00531e32     JZ         LAB_00531e43
    //         00531e34     DEC        EDX
    //         00531e35     JZ         LAB_00531e40
    //         00531e37     DEC        EDX
    //         00531e38     JNZ        LAB_00531e48
    //                              victory.cpp:300 (4)
    //         00531e3a     INC        dword ptr [ESP + failed_group_num]
    //                              victory.cpp:301 (2)
    //         00531e3e     JMP        LAB_00531e48
    //                               LAB_00531e40                                                 XREF[1]:     00531e35(j)  
    //                              victory.cpp:297 (1)
    //         00531e40     INC        EBX
    //                              victory.cpp:298 (2)
    //         00531e41     JMP        LAB_00531e48
    //                               LAB_00531e43                                                 XREF[1]:     00531e32(j)  
    //                              victory.cpp:303 (5)
    //         00531e43     MOV        EDI,0x1
    //                               LAB_00531e48                                                 XREF[4]:     00531e25(j), 00531e38(j), 
    //                                                                                                         00531e3e(j), 00531e41(j)  
    //                              victory.cpp:289 (7)
    //         00531e48     MOV        EAX,dword ptr [EAX + 0x30]
    //         00531e4b     CMP        EAX,this
    //         00531e4d     JNZ        LAB_00531e1e
    //                              victory.cpp:311 (5)
    //         00531e4f     CMP        EDI,0x1
    //         00531e52     JNZ        LAB_00531e5a
    //                              victory.cpp:312 (4)
    //         00531e54     INC        dword ptr [ESP + group_num]
    //                              victory.cpp:314 (2)
    //         00531e58     JMP        LAB_00531deb
    //                               LAB_00531e5a                                                 XREF[1]:     00531e52(j)  
    //                              victory.cpp:315 (14)
    //         00531e5a     CMP        EBX,this
    //         00531e5c     JLE        LAB_00531deb
    //         00531e5e     MOV        EAX,dword ptr [ESP + failed_group_num]
    //         00531e62     ADD        EAX,EBX
    //         00531e64     CMP        ESI,EAX
    //         00531e66     JNZ        LAB_00531deb
    //                              victory.cpp:317 (8)
    //         00531e68     MOV        ESI,dword ptr [ESP + local_4]
    //         00531e6c     MOV        byte ptr [ESI + 0x10],0x2
    //                               LAB_00531e70                                                 XREF[2]:     00531df4(j), 00531e16(j)  
    //                              victory.cpp:324 (12)
    //         00531e70     MOV        this,dword ptr [ESP + group_num]
    //         00531e74     MOV        EAX,dword ptr [ESP + curr_victory_group]
    //         00531e78     CMP        EAX,this
    //         00531e7a     JNZ        LAB_00531e80
    //                              victory.cpp:325 (4)
    //         00531e7c     MOV        byte ptr [ESI + 0x10],0x1
    //                               LAB_00531e80                                                 XREF[2]:     00531dd0(j), 00531e7a(j)  
    //                              victory.cpp:326 (8)
    //         00531e80     POP        EDI
    //         00531e81     POP        ESI
    //         00531e82     POP        EBP
    //         00531e83     POP        EBX
    //         00531e84     ADD        ESP,0x10
    //         00531e87     RET
    //         00531e88     ??         90h
    //         00531e89     NOP
    //         00531e8a     NOP
    //         00531e8b     NOP
    //         00531e8c     NOP
    //         00531e8d     NOP
    //         00531e8e     NOP
    //         00531e8f     NOP
    return;
}

uchar RGE_Victory_Conditions::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(RGE_Victory_Conditions * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //                               ?update@RGE_Victory_Conditions@@QAEEXZ                       XREF[1]:     update:0047014b(c)  
    //                               RGE_Victory_Conditions::update
    //                              victory.cpp:332 (4)
    //         00531e90     PUSH       ESI
    //         00531e91     PUSH       EDI
    //         00531e92     MOV        EDI,this
    //                              victory.cpp:336 (7)
    //         00531e94     MOV        ESI,dword ptr [EDI + 0x14]
    //         00531e97     TEST       ESI,ESI
    //         00531e99     JZ         LAB_00531eb4
    //                               LAB_00531e9b                                                 XREF[1]:     00531eb2(j)  
    //                              victory.cpp:338 (11)
    //         00531e9b     MOV        AL,byte ptr [ESI + 0x1]
    //         00531e9e     CMP        AL,0x3
    //         00531ea0     JZ         LAB_00531ead
    //         00531ea2     CMP        AL,0x1
    //         00531ea4     JZ         LAB_00531ead
    //                              victory.cpp:339 (14)
    //         00531ea6     MOV        EAX,dword ptr [EDI]
    //         00531ea8     PUSH       ESI
    //         00531ea9     MOV        this,EDI
    //         00531eab     CALL       dword ptr [EAX]
    //                               LAB_00531ead                                                 XREF[2]:     00531ea0(j), 00531ea4(j)  
    //         00531ead     MOV        ESI,dword ptr [ESI + 0x18]
    //         00531eb0     TEST       ESI,ESI
    //         00531eb2     JNZ        LAB_00531e9b
    //                               LAB_00531eb4                                                 XREF[1]:     00531e99(j)  
    //                              victory.cpp:341 (7)
    //         00531eb4     MOV        ESI,dword ptr [EDI + 0x4]
    //         00531eb7     TEST       ESI,ESI
    //         00531eb9     JZ         LAB_00531ed5
    //                               LAB_00531ebb                                                 XREF[1]:     00531ed3(j)  
    //                              victory.cpp:342 (11)
    //         00531ebb     MOV        AL,byte ptr [ESI + 0x2e]
    //         00531ebe     CMP        AL,0x3
    //         00531ec0     JZ         LAB_00531ece
    //         00531ec2     CMP        AL,0x1
    //         00531ec4     JZ         LAB_00531ece
    //                              victory.cpp:343 (15)
    //         00531ec6     MOV        EDX,dword ptr [EDI]
    //         00531ec8     PUSH       ESI
    //         00531ec9     MOV        this,EDI
    //         00531ecb     CALL       dword ptr [EDX + 0x4]
    //                               LAB_00531ece                                                 XREF[2]:     00531ec0(j), 00531ec4(j)  
    //         00531ece     MOV        ESI,dword ptr [ESI + 0x30]
    //         00531ed1     TEST       ESI,ESI
    //         00531ed3     JNZ        LAB_00531ebb
    //                               LAB_00531ed5                                                 XREF[1]:     00531eb9(j)  
    //                              victory.cpp:345 (7)
    //         00531ed5     MOV        this,EDI
    //         00531ed7     CALL       RGE_Victory_Conditions::check_for_victory        void check_for_victory(RGE_Victory_Conditions
    //                              victory.cpp:347 (3)
    //         00531edc     MOV        AL,byte ptr [EDI + 0x10]
    //                              victory.cpp:348 (3)
    //         00531edf     POP        EDI
    //         00531ee0     POP        ESI
    //         00531ee1     RET
    //         00531ee2     ??         90h
    //         00531ee3     NOP
    //         00531ee4     NOP
    //         00531ee5     NOP
    //         00531ee6     NOP
    //         00531ee7     NOP
    //         00531ee8     NOP
    //         00531ee9     NOP
    //         00531eea     NOP
    //         00531eeb     NOP
    //         00531eec     NOP
    //         00531eed     NOP
    //         00531eee     NOP
    //         00531eef     NOP
    return 0;
}

void RGE_Victory_Conditions::update_for_object(RGE_Static_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall update_for_object(RGE_Victory_Conditions * this, RGE
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     00531efb(R)  
    //                               ?update_for_object@RGE_Victory_Conditions@@QAEXPAVRGE_Stati  XREF[2]:     ~RGE_Static_Object:004c12e5(c), 
    //                               RGE_Victory_Conditions::update_for_object                                 recycle_out_of_game:004c15d8(c)  
    //                              victory.cpp:353 (3)
    //         00531ef0     PUSH       EBX
    //         00531ef1     MOV        EBX,this
    //                              victory.cpp:357 (13)
    //         00531ef3     MOV        EAX,dword ptr [EBX + 0x4]
    //         00531ef6     TEST       EAX,EAX
    //         00531ef8     JZ         LAB_00531f1f
    //         00531efa     PUSH       EDI
    //         00531efb     MOV        EDI,dword ptr [ESP + param_1]
    //         00531eff     PUSH       ESI
    //                               LAB_00531f00                                                 XREF[1]:     00531f1b(j)  
    //                              victory.cpp:360 (15)
    //         00531f00     MOV        this,dword ptr [EAX + 0x24]
    //         00531f03     MOV        ESI,dword ptr [EAX + 0x30]
    //         00531f06     CMP        this,EDI
    //         00531f08     JZ         LAB_00531f0f
    //         00531f0a     CMP        dword ptr [EAX + 0x28],EDI
    //         00531f0d     JNZ        LAB_00531f17
    //                               LAB_00531f0f                                                 XREF[1]:     00531f08(j)  
    //                              victory.cpp:361 (16)
    //         00531f0f     PUSH       EAX
    //         00531f10     MOV        this,EBX
    //         00531f12     CALL       RGE_Victory_Conditions::sub                      void sub(RGE_Victory_Conditions * this, RGE_V
    //                               LAB_00531f17                                                 XREF[1]:     00531f0d(j)  
    //         00531f17     TEST       ESI,ESI
    //         00531f19     MOV        EAX,ESI
    //         00531f1b     JNZ        LAB_00531f00
    //         00531f1d     POP        ESI
    //         00531f1e     POP        EDI
    //                               LAB_00531f1f                                                 XREF[1]:     00531ef8(j)  
    //                              victory.cpp:364 (4)
    //         00531f1f     POP        EBX
    //         00531f20     RET        0x4
    //         00531f23     ??         90h
    //         00531f24     NOP
    //         00531f25     NOP
    //         00531f26     NOP
    //         00531f27     NOP
    //         00531f28     NOP
    //         00531f29     NOP
    //         00531f2a     NOP
    //         00531f2b     NOP
    //         00531f2c     NOP
    //         00531f2d     NOP
    //         00531f2e     NOP
    //         00531f2f     NOP
    //                              * protected: virtual void __thiscall RGE_Victory_Conditions::handle_point_condition(struct RGE_Victo... *
    //                              void __thiscall handle_point_condition(RGE_Victory_Conditions * this
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[1]:     00531f30(R)  
    //                               ?handle_point_condition@RGE_Victory_Conditions@@MAEXPAURGE_  XREF[2]:     00577340(*), 005775a8(*)  
    //                               RGE_Victory_Conditions::handle_point_condition
    //                              victory.cpp:369 (20)
    //         00531f30     MOV        EAX,dword ptr [ESP + param_1]
    //         00531f34     XOR        EDX,EDX
    //         00531f36     MOV        DL,byte ptr [EAX]
    //         00531f38     CMP        EDX,0x4
    //         00531f3b     JA         switchD_00531f3d::default
    //                               switchD_00531f3d::switchD
    //         00531f3d     JMP        dword ptr [EDX*0x4 + switchD_00531f3d::switchd   = 00531f44
    //                               switchD_00531f3d::caseD_0                                    XREF[2]:     00531f3d(j), 00531f74(*)  
    //                              victory.cpp:373 (6)
    //         00531f44     PUSH       EAX
    //         00531f45     CALL       RGE_Victory_Conditions::handle_points_attribut   void handle_points_attribute_amount(RGE_Victo
    //                              victory.cpp:395 (3)
    //         00531f4a     RET        0x4
    //                               switchD_00531f3d::caseD_1                                    XREF[2]:     00531f3d(j), 00531f78(*)  
    //                              victory.cpp:377 (6)
    //         00531f4d     PUSH       EAX
    //         00531f4e     CALL       RGE_Victory_Conditions::handle_points_attribut   void handle_points_attribute_first(RGE_Victor
    //                              victory.cpp:395 (3)
    //         00531f53     RET        0x4
    //                               switchD_00531f3d::caseD_2                                    XREF[2]:     00531f3d(j), 00531f7c(*)  
    //                              victory.cpp:381 (6)
    //         00531f56     PUSH       EAX
    //         00531f57     CALL       RGE_Victory_Conditions::handle_points_highest_   void handle_points_highest_attribute(RGE_Vict
    //                              victory.cpp:395 (3)
    //         00531f5c     RET        0x4
    //                               switchD_00531f3d::caseD_3                                    XREF[2]:     00531f3d(j), 00531f80(*)  
    //                              victory.cpp:385 (6)
    //         00531f5f     PUSH       EAX
    //         00531f60     CALL       RGE_Victory_Conditions::handle_points_high_att   void handle_points_high_attribute_once(RGE_Vi
    //                              victory.cpp:395 (3)
    //         00531f65     RET        0x4
    //                               switchD_00531f3d::caseD_4                                    XREF[2]:     00531f3d(j), 00531f84(*)  
    //                              victory.cpp:389 (6)
    //         00531f68     PUSH       EAX
    //         00531f69     CALL       RGE_Victory_Conditions::handle_points_high_att   void handle_points_high_attribute_amount(RGE_
    //                               switchD_00531f3d::default                                    XREF[1]:     00531f3b(j)  
    //                              victory.cpp:395 (26)
    //         00531f6e     RET        0x4
    //                              *                                               FUNCTION                                                *
    //                              undefined FUN_00531f71()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_00531f71
    //         00531f71     NOP
    //         00531f72     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00531f3d::switchdataD_00531f74                       XREF[1]:     handle_point_condition:00531f3d(*)
    //         00531f74     addr       switchD_00531f3d::caseD_0
    //         00531f78     addr       switchD_00531f3d::caseD_1
    //         00531f7c     addr       switchD_00531f3d::caseD_2
    //         00531f80     addr       switchD_00531f3d::caseD_3
    //         00531f84     addr       switchD_00531f3d::caseD_4
    //         00531f88     ??         90h
    //         00531f89     ??         90h
    //         00531f8a     ??         90h
    //         00531f8b     ??         90h
    //         00531f8c     ??         90h
    //         00531f8d     ??         90h
    //         00531f8e     ??         90h
    //         00531f8f     ??         90h
    //                              * protected: virtual void __thiscall RGE_Victory_Conditions::handle_condition(struct RGE_Victory_Ent... *
    //                              void __thiscall handle_condition(RGE_Victory_Conditions * this, RGE_
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     00531f90(R)  
    //                               ?handle_condition@RGE_Victory_Conditions@@MAEXPAURGE_Victor  XREF[2]:     handle_condition:0052c95a(c), 
    //                               RGE_Victory_Conditions::handle_condition                                  005775ac(*)  
    //                              victory.cpp:400 (20)
    //         00531f90     MOV        EAX,dword ptr [ESP + param_1]
    //         00531f94     XOR        EDX,EDX
    //         00531f96     MOV        DL,byte ptr [EAX]
    //         00531f98     CMP        EDX,0xc
    //         00531f9b     JA         switchD_00531f9d::caseD_b
    //                               switchD_00531f9d::switchD
    //         00531f9d     JMP        dword ptr [EDX*0x4 + switchD_00531f9d::switchd   = 00531fa4
    //                               switchD_00531f9d::caseD_0                                    XREF[2]:     00531f9d(j), 00532010(*)  
    //                              victory.cpp:404 (6)
    //         00531fa4     PUSH       EAX
    //         00531fa5     CALL       RGE_Victory_Conditions::handle_capture           void handle_capture(RGE_Victory_Conditions * 
    //                              victory.cpp:455 (3)
    //         00531faa     RET        0x4
    //                               switchD_00531f9d::caseD_1                                    XREF[2]:     00531f9d(j), 00532014(*)  
    //                              victory.cpp:408 (6)
    //         00531fad     PUSH       EAX
    //         00531fae     CALL       RGE_Victory_Conditions::handle_create            void handle_create(RGE_Victory_Conditions * t
    //                              victory.cpp:455 (3)
    //         00531fb3     RET        0x4
    //                               switchD_00531f9d::caseD_8                                    XREF[2]:     00531f9d(j), 00532030(*)  
    //                              victory.cpp:412 (6)
    //         00531fb6     PUSH       EAX
    //         00531fb7     CALL       RGE_Victory_Conditions::handle_create_in_area    void handle_create_in_area(RGE_Victory_Condit
    //                              victory.cpp:455 (3)
    //         00531fbc     RET        0x4
    //                               switchD_00531f9d::caseD_2                                    XREF[2]:     00531f9d(j), 00532018(*)  
    //                              victory.cpp:416 (6)
    //         00531fbf     PUSH       EAX
    //         00531fc0     CALL       RGE_Victory_Conditions::handle_destroy           void handle_destroy(RGE_Victory_Conditions * 
    //                              victory.cpp:455 (3)
    //         00531fc5     RET        0x4
    //                               switchD_00531f9d::caseD_3                                    XREF[2]:     00531f9d(j), 0053201c(*)  
    //                              victory.cpp:420 (6)
    //         00531fc8     PUSH       EAX
    //         00531fc9     CALL       RGE_Victory_Conditions::handle_destroy_multiple  void handle_destroy_multiple(RGE_Victory_Cond
    //                              victory.cpp:455 (3)
    //         00531fce     RET        0x4
    //                               switchD_00531f9d::caseD_9                                    XREF[2]:     00531f9d(j), 00532034(*)  
    //                              victory.cpp:424 (6)
    //         00531fd1     PUSH       EAX
    //         00531fd2     CALL       RGE_Victory_Conditions::handle_destroy_all       void handle_destroy_all(RGE_Victory_Condition
    //                              victory.cpp:455 (3)
    //         00531fd7     RET        0x4
    //                               switchD_00531f9d::caseD_a                                    XREF[2]:     00531f9d(j), 00532038(*)  
    //                              victory.cpp:428 (6)
    //         00531fda     PUSH       EAX
    //         00531fdb     CALL       RGE_Victory_Conditions::handle_destroy_player    void handle_destroy_player(RGE_Victory_Condit
    //                              victory.cpp:455 (3)
    //         00531fe0     RET        0x4
    //                               switchD_00531f9d::caseD_4                                    XREF[2]:     00531f9d(j), 00532020(*)  
    //                              victory.cpp:432 (6)
    //         00531fe3     PUSH       EAX
    //         00531fe4     CALL       RGE_Victory_Conditions::handle_bring_area        void handle_bring_area(RGE_Victory_Conditions
    //                              victory.cpp:455 (3)
    //         00531fe9     RET        0x4
    //                               switchD_00531f9d::caseD_5                                    XREF[2]:     00531f9d(j), 00532024(*)  
    //                              victory.cpp:436 (6)
    //         00531fec     PUSH       EAX
    //         00531fed     CALL       RGE_Victory_Conditions::handle_bring_object      void handle_bring_object(RGE_Victory_Conditio
    //                              victory.cpp:455 (3)
    //         00531ff2     RET        0x4
    //                               switchD_00531f9d::caseD_6                                    XREF[2]:     00531f9d(j), 00532028(*)  
    //                              victory.cpp:440 (6)
    //         00531ff5     PUSH       EAX
    //         00531ff6     CALL       RGE_Victory_Conditions::handle_attribute         void handle_attribute(RGE_Victory_Conditions 
    //                              victory.cpp:455 (3)
    //         00531ffb     RET        0x4
    //                               switchD_00531f9d::caseD_7                                    XREF[2]:     00531f9d(j), 0053202c(*)  
    //                              victory.cpp:444 (6)
    //         00531ffe     PUSH       EAX
    //         00531fff     CALL       RGE_Victory_Conditions::handle_explore           void handle_explore(RGE_Victory_Conditions * 
    //                              victory.cpp:455 (3)
    //         00532004     RET        0x4
    //                               switchD_00531f9d::caseD_c                                    XREF[2]:     00531f9d(j), 00532040(*)  
    //                              victory.cpp:448 (6)
    //         00532007     PUSH       EAX
    //         00532008     CALL       RGE_Victory_Conditions::handle_victory_points    void handle_victory_points(RGE_Victory_Condit
    //                               switchD_00531f9d::caseD_b                                    XREF[3]:     00531f9b(j), 00531f9d(j), 
    //                                                                                                         0053203c(*)  
    //                              victory.cpp:455 (55)
    //         0053200d     RET        0x4
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00531f9d::switchdataD_00532010                       XREF[1]:     handle_condition:00531f9d(*)  
    //         00532010     addr       switchD_00531f9d::caseD_0
    //         00532014     addr       switchD_00531f9d::caseD_1
    //         00532018     addr       switchD_00531f9d::caseD_2
    //         0053201c     addr       switchD_00531f9d::caseD_3
    //         00532020     addr       switchD_00531f9d::caseD_4
    //         00532024     addr       switchD_00531f9d::caseD_5
    //         00532028     addr       switchD_00531f9d::caseD_6
    //         0053202c     addr       switchD_00531f9d::caseD_7
    //         00532030     addr       switchD_00531f9d::caseD_8
    //         00532034     addr       switchD_00531f9d::caseD_9
    //         00532038     addr       switchD_00531f9d::caseD_a
    //         0053203c     addr       switchD_00531f9d::caseD_b
    //         00532040     addr       switchD_00531f9d::caseD_c
    //         00532044     ??         90h
    //         00532045     ??         90h
    //         00532046     ??         90h
    //         00532047     ??         90h
    //         00532048     ??         90h
    //         00532049     ??         90h
    //         0053204a     ??         90h
    //         0053204b     ??         90h
    //         0053204c     ??         90h
    //         0053204d     ??         90h
    //         0053204e     ??         90h
    //         0053204f     ??         90h
    return;
}

void RGE_Victory_Conditions::handle_capture(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_capture(RGE_Victory_Conditions * this, RGE_Vi
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     00532051(R)  
    //                               ?handle_capture@RGE_Victory_Conditions@@IAEXPAURGE_Victory_  XREF[1]:     handle_condition:00531fa5(c)  
    //                               RGE_Victory_Conditions::handle_capture
    //                              victory.cpp:461 (1)
    //         00532050     PUSH       ESI
    //                              victory.cpp:462 (16)
    //         00532051     MOV        ESI,dword ptr [ESP + param_1]
    //         00532055     PUSH       EDI
    //         00532056     MOV        EAX,dword ptr [ESI + 0x28]
    //         00532059     TEST       EAX,EAX
    //         0053205b     JZ         LAB_00532101
    //                              victory.cpp:464 (6)
    //         00532061     CMP        byte ptr [EAX + 0x48],0x2
    //         00532065     JBE        LAB_00532082
    //                              victory.cpp:467 (18)
    //         00532067     MOV        AL,byte ptr [ESI + 0x2e]
    //         0053206a     MOV        dword ptr [ESI + 0x28],0x0
    //         00532071     TEST       AL,AL
    //         00532073     JNZ        LAB_00532101
    //                              victory.cpp:468 (4)
    //         00532079     MOV        byte ptr [ESI + 0x2e],0x1
    //                              victory.cpp:484 (5)
    //         0053207d     POP        EDI
    //         0053207e     POP        ESI
    //         0053207f     RET        0x4
    //                               LAB_00532082                                                 XREF[1]:     00532065(j)  
    //                              victory.cpp:470 (7)
    //         00532082     MOV        DL,byte ptr [ESI + 0x2e]
    //         00532085     TEST       DL,DL
    //         00532087     JNZ        LAB_005320d7
    //                              victory.cpp:474 (69)
    //         00532089     MOV        EAX,dword ptr [EAX + 0xc]
    //         0053208c     MOV        this,dword ptr [ECX + this->player]
    //         0053208f     CMP        EAX,this
    //         00532091     JZ         LAB_005320ce
    //         00532093     MOV        DL,byte ptr [ESI + 0x2d]
    //         00532096     TEST       DL,DL
    //         00532098     JZ         LAB_00532101
    //         0053209a     MOV        DL,byte ptr [this->_padding_ + 0x104]
    //         005320a0     TEST       DL,DL
    //         005320a2     JZ         LAB_00532101
    //         005320a4     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         005320a8     MOV        EDI,dword ptr [this->_padding_ + 0x84]
    //         005320ae     CMP        byte ptr [EDI + EDX*0x1],0x0
    //         005320b2     JNZ        LAB_00532101
    //         005320b4     MOVSX      this,word ptr [this->_padding_ + 0x4a]
    //         005320b8     MOV        EDX,dword ptr [EAX + 0x84]
    //         005320be     CMP        byte ptr [EDX + this->_padding_*0x1],0x0
    //         005320c2     JNZ        LAB_00532101
    //         005320c4     MOV        this,byte ptr [EAX + 0x104]
    //         005320ca     TEST       this,this
    //         005320cc     JZ         LAB_00532101
    //                               LAB_005320ce                                                 XREF[1]:     00532091(j)  
    //                              victory.cpp:475 (4)
    //         005320ce     MOV        byte ptr [ESI + 0x2e],0x2
    //                              victory.cpp:484 (5)
    //         005320d2     POP        EDI
    //         005320d3     POP        ESI
    //         005320d4     RET        0x4
    //                               LAB_005320d7                                                 XREF[1]:     00532087(j)  
    //                              victory.cpp:477 (5)
    //         005320d7     CMP        DL,0x2
    //         005320da     JNZ        LAB_00532101
    //                              victory.cpp:480 (33)
    //         005320dc     MOV        EAX,dword ptr [EAX + 0xc]
    //         005320df     MOV        this,dword ptr [ECX + this->player]
    //         005320e2     CMP        EAX,this
    //         005320e4     JZ         LAB_00532101
    //         005320e6     MOV        DL,byte ptr [ESI + 0x2d]
    //         005320e9     TEST       DL,DL
    //         005320eb     JZ         LAB_005320fd
    //         005320ed     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         005320f1     MOV        this,dword ptr [this->_padding_ + 0x84]
    //         005320f7     CMP        byte ptr [this->_padding_ + EAX*0x1],0x0
    //         005320fb     JZ         LAB_00532101
    //                               LAB_005320fd                                                 XREF[1]:     005320eb(j)  
    //                              victory.cpp:481 (4)
    //         005320fd     MOV        byte ptr [ESI + 0x2e],0x0
    //                               LAB_00532101                                                 XREF[10]:    0053205b(j), 00532073(j), 
    //                                                                                                         00532098(j), 005320a2(j), 
    //                                                                                                         005320b2(j), 005320c2(j), 
    //                                                                                                         005320cc(j), 005320da(j), 
    //                                                                                                         005320e4(j), 005320fb(j)  
    //                              victory.cpp:484 (5)
    //         00532101     POP        EDI
    //         00532102     POP        ESI
    //         00532103     RET        0x4
    //         00532106     ??         90h
    //         00532107     NOP
    //         00532108     NOP
    //         00532109     NOP
    //         0053210a     NOP
    //         0053210b     NOP
    //         0053210c     NOP
    //         0053210d     NOP
    //         0053210e     NOP
    //         0053210f     NOP
    return;
}

void RGE_Victory_Conditions::handle_create(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_create(RGE_Victory_Conditions * this, RGE_Vic
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[3]:     00532118(R), 005321b9(R), 005321ea(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053217a(W), 005321de(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     00532123(W), 0053214c(W), 005321d3(RW), 005321ee(R)  
    //              long              Stack[-0xc]:4  num
    //                               ?handle_create@RGE_Victory_Conditions@@IAEXPAURGE_Victory_E  XREF[1]:     handle_condition:00531fae(c)  
    //                               RGE_Victory_Conditions::handle_create
    //                              victory.cpp:491 (5)
    //         00532110     SUB        ESP,0x8
    //         00532113     PUSH       EBX
    //         00532114     PUSH       EBP
    //                              victory.cpp:497 (25)
    //         00532115     MOV        EBP,dword ptr [ECX + this->player]
    //         00532118     MOV        EBX,dword ptr [ESP + param_1]
    //         0053211c     PUSH       ESI
    //         0053211d     PUSH       EDI
    //         0053211e     MOV        EAX,dword ptr [EBP + 0x28]
    //         00532121     XOR        EDI,EDI
    //         00532123     MOV        dword ptr [ESP + local_8],EDI
    //         00532127     MOV        EAX,dword ptr [EAX + 0x4]
    //         0053212a     TEST       EAX,EAX
    //         0053212c     JZ         LAB_00532150
    //                              victory.cpp:498 (22)
    //         0053212e     MOV        EDX,dword ptr [EBX + 0x4]
    //                               LAB_00532131                                                 XREF[1]:     0053214a(j)  
    //         00532131     MOV        this,dword ptr [EAX]
    //         00532133     MOV        ESI,dword ptr [ECX + this->list_num]
    //         00532136     MOVSX      ESI,word ptr [ESI + 0x12]
    //         0053213a     CMP        ESI,EDX
    //         0053213c     JNZ        LAB_00532145
    //         0053213e     CMP        byte ptr [this->_padding_ + 0x48],0x2
    //         00532142     JNZ        LAB_00532145
    //                              victory.cpp:499 (1)
    //         00532144     INC        EDI
    //                               LAB_00532145                                                 XREF[2]:     0053213c(j), 00532142(j)  
    //                              victory.cpp:497 (7)
    //         00532145     MOV        EAX,dword ptr [EAX + 0x4]
    //         00532148     TEST       EAX,EAX
    //         0053214a     JNZ        LAB_00532131
    //                              victory.cpp:499 (4)
    //         0053214c     MOV        dword ptr [ESP + local_8],EDI
    //                               LAB_00532150                                                 XREF[1]:     0053212c(j)  
    //                              victory.cpp:502 (25)
    //         00532150     MOV        AL,byte ptr [EBX + 0x2d]
    //         00532153     TEST       AL,AL
    //         00532155     JZ         LAB_005321f2
    //         0053215b     MOV        AL,byte ptr [EBP + 0x104]
    //         00532161     TEST       AL,AL
    //         00532163     JZ         LAB_005321f2
    //                              victory.cpp:504 (3)
    //         00532169     MOV        EAX,dword ptr [EBP + 0x3c]
    //                              victory.cpp:505 (20)
    //         0053216c     MOV        ESI,0x1
    //         00532171     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         00532175     MOV        this,dword ptr [EAX + 0x40]
    //         00532178     CMP        EDX,ESI
    //         0053217a     MOV        dword ptr [ESP + local_4],EDX
    //         0053217e     JLE        LAB_005321f2
    //                              victory.cpp:517 (3)
    //         00532180     LEA        EDI,[ECX + this->victory_list]
    //                               LAB_00532183                                                 XREF[1]:     005321e8(j)  
    //                              victory.cpp:506 (44)
    //         00532183     MOV        EAX,dword ptr [EBP + 0x84]
    //         00532189     CMP        byte ptr [ESI + EAX*0x1],0x0
    //         0053218d     JNZ        LAB_005321e2
    //         0053218f     MOV        EAX,dword ptr [EDI]
    //         00532191     MOVSX      this,word ptr [EBP + 0x4a]
    //         00532195     MOV        EBX,dword ptr [EAX + 0x84]
    //         0053219b     CMP        byte ptr [EBX + this->_padding_*0x1],0x0
    //         0053219f     JNZ        LAB_005321e2
    //         005321a1     CMP        ESI,this
    //         005321a3     JZ         LAB_005321e2
    //         005321a5     MOV        this,byte ptr [EAX + 0x104]
    //         005321ab     TEST       this,this
    //         005321ad     JZ         LAB_005321e2
    //                              victory.cpp:507 (10)
    //         005321af     MOV        this,dword ptr [EAX + 0x28]
    //         005321b2     MOV        EAX,dword ptr [ECX + this->victory_list]
    //         005321b5     TEST       EAX,EAX
    //         005321b7     JZ         LAB_005321e2
    //                              victory.cpp:508 (26)
    //         005321b9     MOV        EDX,dword ptr [ESP + param_1]
    //         005321bd     MOV        EDX,dword ptr [EDX + 0x4]
    //                               LAB_005321c0                                                 XREF[1]:     005321dc(j)  
    //         005321c0     MOV        this,dword ptr [EAX]
    //         005321c2     MOV        EBX,dword ptr [ECX + this->list_num]
    //         005321c5     MOVSX      EBX,word ptr [EBX + 0x12]
    //         005321c9     CMP        EBX,EDX
    //         005321cb     JNZ        LAB_005321d7
    //         005321cd     CMP        byte ptr [this->_padding_ + 0x48],0x2
    //         005321d1     JNZ        LAB_005321d7
    //                              victory.cpp:509 (11)
    //         005321d3     INC        dword ptr [ESP + local_8]
    //                               LAB_005321d7                                                 XREF[2]:     005321cb(j), 005321d1(j)  
    //         005321d7     MOV        EAX,dword ptr [EAX + 0x4]
    //         005321da     TEST       EAX,EAX
    //         005321dc     JNZ        LAB_005321c0
    //                              victory.cpp:507 (4)
    //         005321de     MOV        EDX,dword ptr [ESP + local_4]
    //                               LAB_005321e2                                                 XREF[5]:     0053218d(j), 0053219f(j), 
    //                                                                                                         005321a3(j), 005321ad(j), 
    //                                                                                                         005321b7(j)  
    //                              victory.cpp:505 (16)
    //         005321e2     INC        ESI
    //         005321e3     ADD        EDI,0x4
    //         005321e6     CMP        ESI,EDX
    //         005321e8     JL         LAB_00532183
    //         005321ea     MOV        EBX,dword ptr [ESP + param_1]
    //         005321ee     MOV        EDI,dword ptr [ESP + local_8]
    //                               LAB_005321f2                                                 XREF[3]:     00532155(j), 00532163(j), 
    //                                                                                                         0053217e(j)  
    //                              victory.cpp:513 (5)
    //         005321f2     CMP        EDI,dword ptr [EBX + 0x1c]
    //         005321f5     JL         LAB_00532205
    //                              victory.cpp:514 (4)
    //         005321f7     MOV        byte ptr [EBX + 0x2e],0x2
    //                              victory.cpp:517 (24)
    //         005321fb     POP        EDI
    //         005321fc     POP        ESI
    //         005321fd     POP        EBP
    //         005321fe     POP        EBX
    //         005321ff     ADD        ESP,0x8
    //         00532202     RET        0x4
    //                               LAB_00532205                                                 XREF[1]:     005321f5(j)  
    //         00532205     POP        EDI
    //         00532206     POP        ESI
    //         00532207     MOV        byte ptr [EBX + 0x2e],0x0
    //         0053220b     POP        EBP
    //         0053220c     POP        EBX
    //         0053220d     ADD        ESP,0x8
    //         00532210     RET        0x4
    //         00532213     ??         90h
    //         00532214     NOP
    //         00532215     NOP
    //         00532216     NOP
    //         00532217     NOP
    //         00532218     NOP
    //         00532219     NOP
    //         0053221a     NOP
    //         0053221b     NOP
    //         0053221c     NOP
    //         0053221d     NOP
    //         0053221e     NOP
    //         0053221f     NOP
    return;
}

void RGE_Victory_Conditions::handle_create_in_area(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_create_in_area(RGE_Victory_Conditions * this,
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[3]:     0053222b(R), 005322d9(W), 005322dd(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005322c2(W), 0053236f(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00532237(W), 005322cf(R), 005322ec(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     00532233(W), 00532294(W), 00532364(RW), 0053237f(R)  
    //              long              Stack[-0x10]:4 num
    //                               ?handle_create_in_area@RGE_Victory_Conditions@@IAEXPAURGE_V  XREF[1]:     handle_condition:00531fb7(c)  
    //                               RGE_Victory_Conditions::handle_create_in_area
    //                              victory.cpp:524 (5)
    //         00532220     SUB        ESP,0xc
    //         00532223     PUSH       EBX
    //         00532224     PUSH       EBP
    //                              victory.cpp:531 (29)
    //         00532225     MOV        EBP,dword ptr [ECX + this->player]
    //         00532228     XOR        EBX,EBX
    //         0053222a     PUSH       ESI
    //         0053222b     MOV        ESI,dword ptr [ESP + param_1]
    //         0053222f     MOV        EAX,dword ptr [EBP + 0x28]
    //         00532232     PUSH       EDI
    //         00532233     MOV        dword ptr [ESP + local_c],EBX
    //         00532237     MOV        dword ptr [ESP + local_8],EBP
    //         0053223b     MOV        EDX,dword ptr [EAX + 0x4]
    //         0053223e     TEST       EDX,EDX
    //         00532240     JZ         LAB_00532298
    //                              victory.cpp:532 (16)
    //         00532242     MOV        EDI,dword ptr [ESI + 0x4]
    //                               LAB_00532245                                                 XREF[1]:     00532292(j)  
    //         00532245     MOV        this,dword ptr [EDX]
    //         00532247     MOV        EAX,dword ptr [ECX + this->list_num]
    //         0053224a     MOVSX      EAX,word ptr [EAX + 0x12]
    //         0053224e     CMP        EAX,EDI
    //         00532250     JNZ        LAB_0053228d
    //                              victory.cpp:537 (58)
    //         00532252     CMP        byte ptr [this->_padding_ + 0x48],0x2
    //         00532256     JNZ        LAB_0053228d
    //         00532258     FLD        float ptr [this->_padding_ + 0x38]
    //         0053225b     FCOMP      float ptr [ESI + 0xc]
    //         0053225e     FNSTSW     AX
    //         00532260     TEST       AH,0x1
    //         00532263     JNZ        LAB_0053228d
    //         00532265     FLD        float ptr [this->_padding_ + 0x38]
    //         00532268     FCOMP      float ptr [ESI + 0x14]
    //         0053226b     FNSTSW     AX
    //         0053226d     TEST       AH,0x41
    //         00532270     JZ         LAB_0053228d
    //         00532272     FLD        float ptr [this->_padding_ + 0x3c]
    //         00532275     FCOMP      float ptr [ESI + 0x10]
    //         00532278     FNSTSW     AX
    //         0053227a     TEST       AH,0x1
    //         0053227d     JNZ        LAB_0053228d
    //         0053227f     FLD        float ptr [this->_padding_ + 0x3c]
    //         00532282     FCOMP      float ptr [ESI + 0x18]
    //         00532285     FNSTSW     AX
    //         00532287     TEST       AH,0x41
    //         0053228a     JZ         LAB_0053228d
    //                              victory.cpp:538 (1)
    //         0053228c     INC        EBX
    //                               LAB_0053228d                                                 XREF[6]:     00532250(j), 00532256(j), 
    //                                                                                                         00532263(j), 00532270(j), 
    //                                                                                                         0053227d(j), 0053228a(j)  
    //                              victory.cpp:531 (7)
    //         0053228d     MOV        EDX,dword ptr [EDX + 0x4]
    //         00532290     TEST       EDX,EDX
    //         00532292     JNZ        LAB_00532245
    //                              victory.cpp:538 (4)
    //         00532294     MOV        dword ptr [ESP + local_c],EBX
    //                               LAB_00532298                                                 XREF[1]:     00532240(j)  
    //                              victory.cpp:542 (25)
    //         00532298     MOV        AL,byte ptr [ESI + 0x2d]
    //         0053229b     TEST       AL,AL
    //         0053229d     JZ         LAB_00532383
    //         005322a3     MOV        AL,byte ptr [EBP + 0x104]
    //         005322a9     TEST       AL,AL
    //         005322ab     JZ         LAB_00532383
    //                              victory.cpp:544 (3)
    //         005322b1     MOV        EAX,dword ptr [EBP + 0x3c]
    //                              victory.cpp:545 (24)
    //         005322b4     MOV        EBP,0x1
    //         005322b9     MOVSX      EDI,word ptr [EAX + 0x3c]
    //         005322bd     MOV        this,dword ptr [EAX + 0x40]
    //         005322c0     CMP        EDI,EBP
    //         005322c2     MOV        dword ptr [ESP + local_4],EDI
    //         005322c6     JLE        LAB_00532383
    //                              victory.cpp:563 (54)
    //         005322cc     LEA        EBX,[ECX + this->victory_list]
    //         005322cf     MOV        this,dword ptr [ESP + local_8]
    //         005322d3     MOV        EDX,dword ptr [this->_padding_ + 0x84]
    //         005322d9     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_005322dd                                                 XREF[1]:     00532379(j)  
    //         005322dd     MOV        EAX,dword ptr [ESP + param_1]
    //         005322e1     CMP        byte ptr [EBP + EAX*0x1],0x0
    //         005322e6     JNZ        LAB_00532373
    //         005322ec     MOV        this,dword ptr [ESP + local_8]
    //         005322f0     MOV        EAX,dword ptr [EBX]
    //         005322f2     MOVSX      this,word ptr [this->_padding_ + 0x4a]
    //         005322f6     MOV        EDX,dword ptr [EAX + 0x84]
    //         005322fc     CMP        byte ptr [EDX + this->_padding_*0x1],0x0
    //         00532300     JNZ        LAB_00532373
    //                              victory.cpp:546 (14)
    //         00532302     CMP        EBP,this
    //         00532304     JZ         LAB_00532373
    //         00532306     MOV        this,byte ptr [EAX + 0x104]
    //         0053230c     TEST       this,this
    //         0053230e     JZ         LAB_00532373
    //                              victory.cpp:547 (10)
    //         00532310     MOV        EAX,dword ptr [EAX + 0x28]
    //         00532313     MOV        EDX,dword ptr [EAX + 0x4]
    //         00532316     TEST       EDX,EDX
    //         00532318     JZ         LAB_00532373
    //                              victory.cpp:550 (3)
    //         0053231a     MOV        EDI,dword ptr [ESI + 0x4]
    //                               LAB_0053231d                                                 XREF[1]:     0053236d(j)  
    //                              victory.cpp:549 (2)
    //         0053231d     MOV        this,dword ptr [EDX]
    //                              victory.cpp:550 (11)
    //         0053231f     MOV        EAX,dword ptr [ECX + this->list_num]
    //         00532322     MOVSX      EAX,word ptr [EAX + 0x12]
    //         00532326     CMP        EAX,EDI
    //         00532328     JNZ        LAB_00532368
    //                              victory.cpp:553 (58)
    //         0053232a     CMP        byte ptr [this->_padding_ + 0x48],0x2
    //         0053232e     JNZ        LAB_00532368
    //         00532330     FLD        float ptr [this->_padding_ + 0x38]
    //         00532333     FCOMP      float ptr [ESI + 0xc]
    //         00532336     FNSTSW     AX
    //         00532338     TEST       AH,0x1
    //         0053233b     JNZ        LAB_00532368
    //         0053233d     FLD        float ptr [this->_padding_ + 0x38]
    //         00532340     FCOMP      float ptr [ESI + 0x14]
    //         00532343     FNSTSW     AX
    //         00532345     TEST       AH,0x41
    //         00532348     JZ         LAB_00532368
    //         0053234a     FLD        float ptr [this->_padding_ + 0x3c]
    //         0053234d     FCOMP      float ptr [ESI + 0x10]
    //         00532350     FNSTSW     AX
    //         00532352     TEST       AH,0x1
    //         00532355     JNZ        LAB_00532368
    //         00532357     FLD        float ptr [this->_padding_ + 0x3c]
    //         0053235a     FCOMP      float ptr [ESI + 0x18]
    //         0053235d     FNSTSW     AX
    //         0053235f     TEST       AH,0x41
    //         00532362     JZ         LAB_00532368
    //                              victory.cpp:554 (11)
    //         00532364     INC        dword ptr [ESP + local_c]
    //                               LAB_00532368                                                 XREF[6]:     00532328(j), 0053232e(j), 
    //                                                                                                         0053233b(j), 00532348(j), 
    //                                                                                                         00532355(j), 00532362(j)  
    //         00532368     MOV        EDX,dword ptr [EDX + 0x4]
    //         0053236b     TEST       EDX,EDX
    //         0053236d     JNZ        LAB_0053231d
    //                              victory.cpp:547 (4)
    //         0053236f     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_00532373                                                 XREF[5]:     005322e6(j), 00532300(j), 
    //                                                                                                         00532304(j), 0053230e(j), 
    //                                                                                                         00532318(j)  
    //                              victory.cpp:545 (16)
    //         00532373     INC        EBP
    //         00532374     ADD        EBX,0x4
    //         00532377     CMP        EBP,EDI
    //         00532379     JL         LAB_005322dd
    //         0053237f     MOV        EBX,dword ptr [ESP + local_c]
    //                               LAB_00532383                                                 XREF[3]:     0053229d(j), 005322ab(j), 
    //                                                                                                         005322c6(j)  
    //                              victory.cpp:559 (5)
    //         00532383     CMP        EBX,dword ptr [ESI + 0x1c]
    //         00532386     JL         LAB_00532396
    //                              victory.cpp:560 (4)
    //         00532388     MOV        byte ptr [ESI + 0x2e],0x2
    //                              victory.cpp:563 (10)
    //         0053238c     POP        EDI
    //         0053238d     POP        ESI
    //         0053238e     POP        EBP
    //         0053238f     POP        EBX
    //         00532390     ADD        ESP,0xc
    //         00532393     RET        0x4
    //                               LAB_00532396                                                 XREF[1]:     00532386(j)  
    //                              victory.cpp:562 (4)
    //         00532396     MOV        byte ptr [ESI + 0x2e],0x0
    //                              victory.cpp:563 (10)
    //         0053239a     POP        EDI
    //         0053239b     POP        ESI
    //         0053239c     POP        EBP
    //         0053239d     POP        EBX
    //         0053239e     ADD        ESP,0xc
    //         005323a1     RET        0x4
    //         005323a4     ??         90h
    //         005323a5     NOP
    //         005323a6     NOP
    //         005323a7     NOP
    //         005323a8     NOP
    //         005323a9     NOP
    //         005323aa     NOP
    //         005323ab     NOP
    //         005323ac     NOP
    //         005323ad     NOP
    //         005323ae     NOP
    //         005323af     NOP
    return;
}

void RGE_Victory_Conditions::handle_destroy(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_destroy(RGE_Victory_Conditions * this, RGE_Vi
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     005323b0(R)  
    //                               ?handle_destroy@RGE_Victory_Conditions@@IAEXPAURGE_Victory_  XREF[1]:     handle_condition:00531fc0(c)  
    //                               RGE_Victory_Conditions::handle_destroy
    //                              victory.cpp:569 (11)
    //         005323b0     MOV        this,dword ptr [ESP + param_1]
    //         005323b4     MOV        EAX,dword ptr [this->_padding_ + 0x28]
    //         005323b7     TEST       EAX,EAX
    //         005323b9     JZ         LAB_005323cc
    //                              victory.cpp:571 (6)
    //         005323bb     CMP        byte ptr [EAX + 0x48],0x7
    //         005323bf     JNZ        LAB_005323cc
    //                              victory.cpp:573 (4)
    //         005323c1     MOV        byte ptr [this->_padding_ + 0x2e],0x2
    //                              victory.cpp:574 (7)
    //         005323c5     MOV        dword ptr [this->_padding_ + 0x28],0x0
    //                               LAB_005323cc                                                 XREF[2]:     005323b9(j), 005323bf(j)  
    //                              victory.cpp:576 (3)
    //         005323cc     RET        0x4
    //         005323cf     ??         90h
    //                              * protected: void __thiscall RGE_Victory_Conditions::handle_destroy_multiple(struct RGE_Victory_Entr... *
    //                              void __thiscall handle_destroy_multiple(RGE_Victory_Conditions * thi
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[3]:     005323d1(R), 0053245c(R), 00532465(R)  
    //                               ?handle_destroy_multiple@RGE_Victory_Conditions@@IAEXPAURGE  XREF[1]:     handle_condition:00531fc9(c)  
    //                               RGE_Victory_Conditions::handle_destroy_multiple
    //                              victory.cpp:582 (1)
    //         005323d0     PUSH       EBX
    //                              victory.cpp:587 (18)
    //         005323d1     MOV        EBX,dword ptr [ESP + param_1]
    //         005323d5     PUSH       EBP
    //         005323d6     PUSH       ESI
    //         005323d7     MOV        AL,byte ptr [EBX + 0x2e]
    //         005323da     PUSH       EDI
    //         005323db     TEST       AL,AL
    //         005323dd     JNZ        LAB_00532490
    //                              victory.cpp:589 (7)
    //         005323e3     MOV        EAX,dword ptr [EBX + 0x8]
    //         005323e6     TEST       EAX,EAX
    //         005323e8     JZ         LAB_0053241a
    //                              victory.cpp:591 (14)
    //         005323ea     MOV        EAX,dword ptr [EAX + 0x28]
    //         005323ed     MOV        EAX,dword ptr [EAX + 0x4]
    //         005323f0     TEST       EAX,EAX
    //         005323f2     JZ         LAB_00532482
    //                              victory.cpp:592 (16)
    //         005323f8     MOV        EDX,dword ptr [EBX + 0x4]
    //                               LAB_005323fb                                                 XREF[1]:     00532416(j)  
    //         005323fb     MOV        this,dword ptr [EAX]
    //         005323fd     MOV        ESI,dword ptr [ECX + this->list_num]
    //         00532400     MOVSX      ESI,word ptr [ESI + 0x12]
    //         00532404     CMP        ESI,EDX
    //         00532406     JNZ        LAB_00532411
    //                              victory.cpp:593 (6)
    //         00532408     CMP        byte ptr [this->_padding_ + 0x48],0x7
    //         0053240c     JNZ        LAB_00532411
    //                              victory.cpp:594 (10)
    //         0053240e     INC        dword ptr [EBX + 0x20]
    //                               LAB_00532411                                                 XREF[2]:     00532406(j), 0053240c(j)  
    //         00532411     MOV        EAX,dword ptr [EAX + 0x4]
    //         00532414     TEST       EAX,EAX
    //         00532416     JNZ        LAB_005323fb
    //                              victory.cpp:596 (2)
    //         00532418     JMP        LAB_00532482
    //                               LAB_0053241a                                                 XREF[1]:     005323e8(j)  
    //                              victory.cpp:598 (3)
    //         0053241a     MOV        EAX,dword ptr [ECX + this->player]
    //                              victory.cpp:599 (14)
    //         0053241d     XOR        ESI,ESI
    //         0053241f     MOV        EDX,dword ptr [EAX + 0x3c]
    //         00532422     CMP        word ptr [EDX + 0x3c],SI
    //         00532426     MOV        EDI,dword ptr [EDX + 0x40]
    //         00532429     JLE        LAB_00532482
    //                              victory.cpp:610 (2)
    //         0053242b     MOV        EBP,EDI
    //                               LAB_0053242d                                                 XREF[1]:     00532480(j)  
    //                              victory.cpp:600 (12)
    //         0053242d     MOV        EDX,dword ptr [EAX + 0x84]
    //         00532433     CMP        byte ptr [EDX + ESI*0x1],0x0
    //         00532437     JZ         LAB_00532470
    //                              victory.cpp:601 (13)
    //         00532439     MOV        EAX,dword ptr [EBP]
    //         0053243c     MOV        EDX,dword ptr [EAX + 0x28]
    //         0053243f     MOV        EAX,dword ptr [EDX + 0x4]
    //         00532442     TEST       EAX,EAX
    //         00532444     JZ         LAB_00532470
    //                              victory.cpp:602 (16)
    //         00532446     MOV        EDI,dword ptr [EBX + 0x4]
    //                               LAB_00532449                                                 XREF[1]:     0053246e(j)  
    //         00532449     MOV        EDX,dword ptr [EAX]
    //         0053244b     MOV        EBX,dword ptr [EDX + 0x8]
    //         0053244e     MOVSX      EBX,word ptr [EBX + 0x12]
    //         00532452     CMP        EBX,EDI
    //         00532454     JNZ        LAB_00532465
    //                              victory.cpp:603 (6)
    //         00532456     CMP        byte ptr [EDX + 0x48],0x7
    //         0053245a     JNZ        LAB_00532465
    //                              victory.cpp:604 (13)
    //         0053245c     MOV        EBX,dword ptr [ESP + param_1]
    //         00532460     INC        dword ptr [EBX + 0x20]
    //         00532463     JMP        LAB_00532469
    //                               LAB_00532465                                                 XREF[2]:     00532454(j), 0053245a(j)  
    //         00532465     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_00532469                                                 XREF[1]:     00532463(j)  
    //                              victory.cpp:601 (7)
    //         00532469     MOV        EAX,dword ptr [EAX + 0x4]
    //         0053246c     TEST       EAX,EAX
    //         0053246e     JNZ        LAB_00532449
    //                               LAB_00532470                                                 XREF[2]:     00532437(j), 00532444(j)  
    //                              victory.cpp:599 (18)
    //         00532470     MOV        EAX,dword ptr [ECX + this->player]
    //         00532473     INC        ESI
    //         00532474     ADD        EBP,0x4
    //         00532477     MOV        EDX,dword ptr [EAX + 0x3c]
    //         0053247a     MOVSX      EDX,word ptr [EDX + 0x3c]
    //         0053247e     CMP        ESI,EDX
    //         00532480     JL         LAB_0053242d
    //                               LAB_00532482                                                 XREF[3]:     005323f2(j), 00532418(j), 
    //                                                                                                         00532429(j)  
    //                              victory.cpp:607 (10)
    //         00532482     MOV        EAX,dword ptr [EBX + 0x20]
    //         00532485     MOV        this,dword ptr [EBX + 0x1c]
    //         00532488     CMP        EAX,this
    //         0053248a     JL         LAB_00532490
    //                              victory.cpp:608 (4)
    //         0053248c     MOV        byte ptr [EBX + 0x2e],0x2
    //                               LAB_00532490                                                 XREF[2]:     005323dd(j), 0053248a(j)  
    //                              victory.cpp:610 (7)
    //         00532490     POP        EDI
    //         00532491     POP        ESI
    //         00532492     POP        EBP
    //         00532493     POP        EBX
    //         00532494     RET        0x4
    //         00532497     ??         90h
    //         00532498     NOP
    //         00532499     NOP
    //         0053249a     NOP
    //         0053249b     NOP
    //         0053249c     NOP
    //         0053249d     NOP
    //         0053249e     NOP
    //         0053249f     NOP
    return;
}

void RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_destroy_all(RGE_Victory_Conditions * this, RG
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[3]:     005324a1(R), 00532536(R), 0053254d(R)  
    //                               ?handle_destroy_all@RGE_Victory_Conditions@@IAEXPAURGE_Vict  XREF[1]:     handle_condition:00531fd2(c)  
    //                               RGE_Victory_Conditions::handle_destroy_all
    //                              victory.cpp:616 (1)
    //         005324a0     PUSH       EBX
    //                              victory.cpp:621 (14)
    //         005324a1     MOV        EBX,dword ptr [ESP + param_1]
    //         005324a5     PUSH       EBP
    //         005324a6     PUSH       ESI
    //         005324a7     MOV        EAX,dword ptr [EBX + 0x8]
    //         005324aa     PUSH       EDI
    //         005324ab     TEST       EAX,EAX
    //         005324ad     JZ         LAB_005324ea
    //                              victory.cpp:623 (14)
    //         005324af     MOV        EAX,dword ptr [EAX + 0x28]
    //         005324b2     MOV        EAX,dword ptr [EAX + 0x4]
    //         005324b5     TEST       EAX,EAX
    //         005324b7     JZ         LAB_0053255c
    //                              victory.cpp:624 (23)
    //         005324bd     MOV        this,dword ptr [EBX + 0x4]
    //                               LAB_005324c0                                                 XREF[1]:     005324d2(j)  
    //         005324c0     MOV        EDX,dword ptr [EAX]
    //         005324c2     MOV        EDX,dword ptr [EDX + 0x8]
    //         005324c5     MOVSX      EDX,word ptr [EDX + 0x12]
    //         005324c9     CMP        EDX,this
    //         005324cb     JZ         LAB_005324df
    //         005324cd     MOV        EAX,dword ptr [EAX + 0x4]
    //         005324d0     TEST       EAX,EAX
    //         005324d2     JNZ        LAB_005324c0
    //                              victory.cpp:642 (4)
    //         005324d4     MOV        byte ptr [EBX + 0x2e],0x2
    //                              victory.cpp:643 (7)
    //         005324d8     POP        EDI
    //         005324d9     POP        ESI
    //         005324da     POP        EBP
    //         005324db     POP        EBX
    //         005324dc     RET        0x4
    //                               LAB_005324df                                                 XREF[1]:     005324cb(j)  
    //                              victory.cpp:626 (4)
    //         005324df     MOV        byte ptr [EBX + 0x2e],0x0
    //                              victory.cpp:643 (7)
    //         005324e3     POP        EDI
    //         005324e4     POP        ESI
    //         005324e5     POP        EBP
    //         005324e6     POP        EBX
    //         005324e7     RET        0x4
    //                               LAB_005324ea                                                 XREF[1]:     005324ad(j)  
    //                              victory.cpp:632 (3)
    //         005324ea     MOV        EBP,dword ptr [ECX + this->player]
    //                              victory.cpp:633 (16)
    //         005324ed     XOR        this,this
    //         005324ef     MOV        EAX,dword ptr [EBP + 0x3c]
    //         005324f2     MOVSX      EDI,word ptr [EAX + 0x3c]
    //         005324f6     MOV        EDX,dword ptr [EAX + 0x40]
    //         005324f9     TEST       EDI,EDI
    //         005324fb     JLE        LAB_0053255c
    //                              victory.cpp:643 (2)
    //         005324fd     MOV        ESI,EDX
    //                               LAB_005324ff                                                 XREF[1]:     00532540(j)  
    //                              victory.cpp:634 (20)
    //         005324ff     MOV        EAX,dword ptr [EBP + 0x84]
    //         00532505     CMP        byte ptr [this->_padding_ + EAX*0x1],0x0
    //         00532509     JZ         LAB_0053253a
    //         0053250b     MOVSX      EAX,word ptr [EBP + 0x4a]
    //         0053250f     CMP        this,EAX
    //         00532511     JZ         LAB_0053253a
    //                              victory.cpp:635 (12)
    //         00532513     MOV        EDX,dword ptr [ESI]
    //         00532515     MOV        EAX,dword ptr [EDX + 0x28]
    //         00532518     MOV        EAX,dword ptr [EAX + 0x4]
    //         0053251b     TEST       EAX,EAX
    //         0053251d     JZ         LAB_0053253a
    //                              victory.cpp:636 (23)
    //         0053251f     MOV        EDX,dword ptr [EBX + 0x4]
    //                               LAB_00532522                                                 XREF[1]:     00532534(j)  
    //         00532522     MOV        EBX,dword ptr [EAX]
    //         00532524     MOV        EBX,dword ptr [EBX + 0x8]
    //         00532527     MOVSX      EBX,word ptr [EBX + 0x12]
    //         0053252b     CMP        EBX,EDX
    //         0053252d     JZ         LAB_0053254d
    //         0053252f     MOV        EAX,dword ptr [EAX + 0x4]
    //         00532532     TEST       EAX,EAX
    //         00532534     JNZ        LAB_00532522
    //                              victory.cpp:635 (4)
    //         00532536     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_0053253a                                                 XREF[3]:     00532509(j), 00532511(j), 
    //                                                                                                         0053251d(j)  
    //                              victory.cpp:633 (8)
    //         0053253a     INC        this
    //         0053253b     ADD        ESI,0x4
    //         0053253e     CMP        this,EDI
    //         00532540     JL         LAB_005324ff
    //                              victory.cpp:642 (4)
    //         00532542     MOV        byte ptr [EBX + 0x2e],0x2
    //                              victory.cpp:643 (7)
    //         00532546     POP        EDI
    //         00532547     POP        ESI
    //         00532548     POP        EBP
    //         00532549     POP        EBX
    //         0053254a     RET        0x4
    //                               LAB_0053254d                                                 XREF[1]:     0053252d(j)  
    //                              victory.cpp:638 (8)
    //         0053254d     MOV        this,dword ptr [ESP + param_1]
    //         00532551     MOV        byte ptr [this->_padding_ + 0x2e],0x0
    //                              victory.cpp:643 (18)
    //         00532555     POP        EDI
    //         00532556     POP        ESI
    //         00532557     POP        EBP
    //         00532558     POP        EBX
    //         00532559     RET        0x4
    //                               LAB_0053255c                                                 XREF[2]:     005324b7(j), 005324fb(j)  
    //         0053255c     POP        EDI
    //         0053255d     POP        ESI
    //         0053255e     MOV        byte ptr [EBX + 0x2e],0x2
    //         00532562     POP        EBP
    //         00532563     POP        EBX
    //         00532564     RET        0x4
    //         00532567     ??         90h
    //         00532568     NOP
    //         00532569     NOP
    //         0053256a     NOP
    //         0053256b     NOP
    //         0053256c     NOP
    //         0053256d     NOP
    //         0053256e     NOP
    //         0053256f     NOP
    return;
}

void RGE_Victory_Conditions::handle_destroy_player(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_destroy_player(RGE_Victory_Conditions * this,
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     00532570(R)  
    //                               ?handle_destroy_player@RGE_Victory_Conditions@@IAEXPAURGE_V  XREF[1]:     handle_condition:00531fdb(c)  
    //                               RGE_Victory_Conditions::handle_destroy_player
    //                              victory.cpp:649 (12)
    //         00532570     MOV        this,dword ptr [ESP + param_1]
    //         00532574     PUSH       EBX
    //         00532575     MOV        EAX,dword ptr [ECX + this->list_num]
    //         00532578     TEST       EAX,EAX
    //         0053257a     JZ         LAB_00532593
    //                              victory.cpp:652 (12)
    //         0053257c     MOV        BL,byte ptr [EAX + 0x80]
    //         00532582     MOV        DL,0x2
    //         00532584     CMP        BL,DL
    //         00532586     JZ         LAB_00532590
    //                              victory.cpp:653 (4)
    //         00532588     MOV        byte ptr [this->_padding_ + 0x2e],0x0
    //                              victory.cpp:657 (4)
    //         0053258c     POP        EBX
    //         0053258d     RET        0x4
    //                               LAB_00532590                                                 XREF[1]:     00532586(j)  
    //                              victory.cpp:655 (3)
    //         00532590     MOV        byte ptr [this->_padding_ + 0x2e],DL
    //                               LAB_00532593                                                 XREF[1]:     0053257a(j)  
    //                              victory.cpp:657 (4)
    //         00532593     POP        EBX
    //         00532594     RET        0x4
    //         00532597     ??         90h
    //         00532598     NOP
    //         00532599     NOP
    //         0053259a     NOP
    //         0053259b     NOP
    //         0053259c     NOP
    //         0053259d     NOP
    //         0053259e     NOP
    //         0053259f     NOP
    return;
}

void RGE_Victory_Conditions::handle_bring_area(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_bring_area(RGE_Victory_Conditions * this, RGE
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     005325a0(R)  
    //                               ?handle_bring_area@RGE_Victory_Conditions@@IAEXPAURGE_Victo  XREF[1]:     handle_condition:00531fe4(c)  
    //                               RGE_Victory_Conditions::handle_bring_area
    //                              victory.cpp:663 (11)
    //         005325a0     MOV        this,dword ptr [ESP + param_1]
    //         005325a4     MOV        EDX,dword ptr [this->_padding_ + 0x24]
    //         005325a7     TEST       EDX,EDX
    //         005325a9     JZ         LAB_00532608
    //                              victory.cpp:668 (6)
    //         005325ab     CMP        byte ptr [EDX + 0x48],0x3
    //         005325af     JC         LAB_005325c6
    //                              victory.cpp:670 (7)
    //         005325b1     MOV        AL,byte ptr [this->_padding_ + 0x2e]
    //         005325b4     TEST       AL,AL
    //         005325b6     JNZ        LAB_005325bc
    //                              victory.cpp:671 (4)
    //         005325b8     MOV        byte ptr [this->_padding_ + 0x2e],0x1
    //                               LAB_005325bc                                                 XREF[1]:     005325b6(j)  
    //                              victory.cpp:672 (7)
    //         005325bc     MOV        dword ptr [this->_padding_ + 0x24],0x0
    //                              victory.cpp:686 (3)
    //         005325c3     RET        0x4
    //                               LAB_005325c6                                                 XREF[1]:     005325af(j)  
    //                              victory.cpp:678 (52)
    //         005325c6     FLD        float ptr [EDX + 0x38]
    //         005325c9     FCOMP      float ptr [ECX + this->player]
    //         005325cc     FNSTSW     AX
    //         005325ce     TEST       AH,0x1
    //         005325d1     JNZ        LAB_00532601
    //         005325d3     FLD        float ptr [EDX + 0x38]
    //         005325d6     FCOMP      float ptr [ECX + this->victory_point_list]
    //         005325d9     FNSTSW     AX
    //         005325db     TEST       AH,0x41
    //         005325de     JZ         LAB_00532601
    //         005325e0     FLD        float ptr [EDX + 0x3c]
    //         005325e3     FCOMP      float ptr [ECX + this->victory]
    //         005325e6     FNSTSW     AX
    //         005325e8     TEST       AH,0x1
    //         005325eb     JNZ        LAB_00532601
    //         005325ed     FLD        float ptr [EDX + 0x3c]
    //         005325f0     FCOMP      float ptr [ECX + this->point_list_num]
    //         005325f3     FNSTSW     AX
    //         005325f5     TEST       AH,0x41
    //         005325f8     JZ         LAB_00532601
    //                              victory.cpp:679 (4)
    //         005325fa     MOV        byte ptr [this->_padding_ + 0x2e],0x2
    //                              victory.cpp:686 (3)
    //         005325fe     RET        0x4
    //                               LAB_00532601                                                 XREF[4]:     005325d1(j), 005325de(j), 
    //                                                                                                         005325eb(j), 005325f8(j)  
    //                              victory.cpp:681 (4)
    //         00532601     MOV        byte ptr [this->_padding_ + 0x2e],0x0
    //                              victory.cpp:686 (3)
    //         00532605     RET        0x4
    //                               LAB_00532608                                                 XREF[1]:     005325a9(j)  
    //                              victory.cpp:685 (4)
    //         00532608     MOV        byte ptr [this->_padding_ + 0x2e],0x3
    //                              victory.cpp:686 (3)
    //         0053260c     RET        0x4
    //         0053260f     ??         90h
    return;
}

void RGE_Victory_Conditions::handle_bring_object(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_bring_object(RGE_Victory_Conditions * this, R
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[3]:     00532611(R), 0053264d(W), 0053265b(R)  
    //                               ?handle_bring_object@RGE_Victory_Conditions@@IAEXPAURGE_Vic  XREF[1]:     handle_condition:00531fed(c)  
    //                               RGE_Victory_Conditions::handle_bring_object
    //                              victory.cpp:692 (1)
    //         00532610     PUSH       ESI
    //                              victory.cpp:698 (26)
    //         00532611     MOV        ESI,dword ptr [ESP + param_1]
    //         00532615     MOV        EDX,dword ptr [ESI + 0x24]
    //         00532618     TEST       EDX,EDX
    //         0053261a     JZ         LAB_005326e8
    //         00532620     MOV        this,dword ptr [ESI + 0x28]
    //         00532623     TEST       this,this
    //         00532625     JZ         LAB_005326e8
    //                              victory.cpp:700 (20)
    //         0053262b     MOV        AL,0x3
    //         0053262d     CMP        byte ptr [EDX + 0x48],AL
    //         00532630     JNC        LAB_005326cb
    //         00532636     CMP        byte ptr [this->_padding_ + 0x48],AL
    //         00532639     JNC        LAB_005326cb
    //                              victory.cpp:709 (6)
    //         0053263f     FLD        float ptr [EDX + 0x38]
    //         00532642     FSUB       float ptr [this->_padding_ + 0x38]
    //                              victory.cpp:710 (14)
    //         00532645     FLD        float ptr [EDX + 0x3c]
    //         00532648     FSUB       float ptr [this->_padding_ + 0x3c]
    //         0053264b     FXCH
    //         0053264d     FST        float ptr [ESP + param_1]
    //         00532651     FXCH
    //                              victory.cpp:711 (21)
    //         00532653     FXCH
    //         00532655     FCOMP      float ptr [DAT_00577588]
    //         0053265b     FLD        float ptr [ESP + param_1]
    //         0053265f     FNSTSW     AX
    //         00532661     TEST       AH,0x1
    //         00532664     JZ         LAB_00532668
    //         00532666     FCHS
    //                               LAB_00532668                                                 XREF[1]:     00532664(j)  
    //                              victory.cpp:712 (21)
    //         00532668     FLD        ST1
    //         0053266a     FCOMP      float ptr [DAT_00577588]
    //         00532670     FNSTSW     AX
    //         00532672     TEST       AH,0x1
    //         00532675     JZ         LAB_0053267d
    //         00532677     FXCH
    //         00532679     FCHS
    //         0053267b     FXCH
    //                               LAB_0053267d                                                 XREF[1]:     00532675(j)  
    //                              victory.cpp:714 (6)
    //         0053267d     MOV        this,dword ptr [ECX + this->list_num]
    //         00532680     MOV        EDX,dword ptr [EDX + 0x8]
    //                              victory.cpp:715 (52)
    //         00532683     FLD        float ptr [this->_padding_ + 0x30]
    //         00532686     FADD       float ptr [EDX + 0x30]
    //         00532689     FLD        float ptr [this->_padding_ + 0x34]
    //         0053268c     FXCH
    //         0053268e     FSUB       float ptr [DAT_0057759c]
    //         00532694     FXCH
    //         00532696     FADD       float ptr [EDX + 0x34]
    //         00532699     FSUB       float ptr [DAT_0057759c]
    //         0053269f     FXCH       ST2
    //         005326a1     FCOMPP
    //         005326a3     FNSTSW     AX
    //         005326a5     TEST       AH,0x41
    //         005326a8     JZ         LAB_005326bf
    //         005326aa     FXCH
    //         005326ac     FCOMP
    //         005326ae     FNSTSW     AX
    //         005326b0     TEST       AH,0x41
    //         005326b3     FSTP       ST0
    //         005326b5     JZ         LAB_005326c3
    //                              victory.cpp:716 (4)
    //         005326b7     MOV        byte ptr [ESI + 0x2e],0x2
    //                              victory.cpp:723 (4)
    //         005326bb     POP        ESI
    //         005326bc     RET        0x4
    //                               LAB_005326bf                                                 XREF[1]:     005326a8(j)  
    //                              victory.cpp:715 (4)
    //         005326bf     FSTP       ST0
    //         005326c1     FSTP       ST0
    //                               LAB_005326c3                                                 XREF[1]:     005326b5(j)  
    //                              victory.cpp:718 (4)
    //         005326c3     MOV        byte ptr [ESI + 0x2e],0x0
    //                              victory.cpp:723 (4)
    //         005326c7     POP        ESI
    //         005326c8     RET        0x4
    //                               LAB_005326cb                                                 XREF[2]:     00532630(j), 00532639(j)  
    //                              victory.cpp:704 (21)
    //         005326cb     MOV        AL,byte ptr [ESI + 0x2e]
    //         005326ce     MOV        dword ptr [ESI + 0x24],0x0
    //         005326d5     TEST       AL,AL
    //         005326d7     MOV        dword ptr [ESI + 0x28],0x0
    //         005326de     JNZ        LAB_005326ec
    //                              victory.cpp:705 (4)
    //         005326e0     MOV        byte ptr [ESI + 0x2e],0x1
    //                              victory.cpp:723 (4)
    //         005326e4     POP        ESI
    //         005326e5     RET        0x4
    //                               LAB_005326e8                                                 XREF[2]:     0053261a(j), 00532625(j)  
    //                              victory.cpp:722 (4)
    //         005326e8     MOV        byte ptr [ESI + 0x2e],0x3
    //                               LAB_005326ec                                                 XREF[1]:     005326de(j)  
    //                              victory.cpp:723 (4)
    //         005326ec     POP        ESI
    //         005326ed     RET        0x4
    return;
}

void RGE_Victory_Conditions::handle_attribute(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_attribute(RGE_Victory_Conditions * this, RGE_
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[2]:     00532700(R), 00532774(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053270d(W), 00532765(R)  
    //                               ?handle_attribute@RGE_Victory_Conditions@@IAEXPAURGE_Victor  XREF[1]:     handle_condition:00531ff6(c)  
    //                               RGE_Victory_Conditions::handle_attribute
    //                              victory.cpp:730 (5)
    //         005326f0     PUSH       this
    //         005326f1     PUSH       EBX
    //         005326f2     PUSH       EBP
    //         005326f3     PUSH       ESI
    //         005326f4     PUSH       EDI
    //                              victory.cpp:735 (11)
    //         005326f5     MOV        EDI,dword ptr [ECX + this->player]
    //         005326f8     TEST       EDI,EDI
    //         005326fa     JZ         LAB_00532796
    //                              victory.cpp:737 (20)
    //         00532700     MOV        ESI,dword ptr [ESP + param_1]
    //         00532704     MOV        this,dword ptr [EDI + 0x50]
    //         00532707     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0053270a     SHL        EAX,0x2
    //         0053270d     MOV        dword ptr [ESP + local_4],EAX
    //         00532711     FLD        float ptr [this->_padding_ + EAX*0x1]
    //                              victory.cpp:739 (17)
    //         00532714     MOV        AL,byte ptr [ESI + 0x2d]
    //         00532717     TEST       AL,AL
    //         00532719     JZ         LAB_00532778
    //         0053271b     MOV        AL,byte ptr [EDI + 0x104]
    //         00532721     TEST       AL,AL
    //         00532723     JZ         LAB_00532778
    //                              victory.cpp:741 (3)
    //         00532725     MOV        EAX,dword ptr [EDI + 0x3c]
    //                              victory.cpp:742 (16)
    //         00532728     MOVSX      this,word ptr [EAX + 0x3c]
    //         0053272c     MOV        EDX,dword ptr [EAX + 0x40]
    //         0053272f     DEC        this
    //         00532730     JS         LAB_00532778
    //         00532732     MOV        EBX,dword ptr [EDI + 0x84]
    //                              victory.cpp:752 (28)
    //         00532738     LEA        ESI,[EDX + this->_padding_*0x4]
    //                               LAB_0053273b                                                 XREF[1]:     00532772(j)  
    //         0053273b     CMP        byte ptr [this->_padding_ + EBX*0x1],0x0
    //         0053273f     JNZ        LAB_0053276c
    //         00532741     MOV        EAX,dword ptr [ESI]
    //         00532743     MOVSX      EDX,word ptr [EDI + 0x4a]
    //         00532747     MOV        EBP,dword ptr [EAX + 0x84]
    //         0053274d     CMP        byte ptr [EBP + EDX*0x1],0x0
    //         00532752     JNZ        LAB_0053276c
    //                              victory.cpp:743 (14)
    //         00532754     CMP        this,EDX
    //         00532756     JZ         LAB_0053276c
    //         00532758     MOV        DL,byte ptr [EAX + 0x104]
    //         0053275e     TEST       DL,DL
    //         00532760     JZ         LAB_0053276c
    //                              victory.cpp:744 (18)
    //         00532762     MOV        EDX,dword ptr [EAX + 0x50]
    //         00532765     MOV        EAX,dword ptr [ESP + local_4]
    //         00532769     FADD       float ptr [EDX + EAX*0x1]
    //                               LAB_0053276c                                                 XREF[4]:     0053273f(j), 00532752(j), 
    //                                                                                                         00532756(j), 00532760(j)  
    //         0053276c     DEC        this
    //         0053276d     SUB        ESI,0x4
    //         00532770     TEST       this,this
    //         00532772     JGE        LAB_0053273b
    //                              victory.cpp:742 (4)
    //         00532774     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_00532778                                                 XREF[3]:     00532719(j), 00532723(j), 
    //                                                                                                         00532730(j)  
    //                              victory.cpp:747 (14)
    //         00532778     FILD       dword ptr [ESI + 0x20]
    //         0053277b     FXCH
    //         0053277d     FCOMPP
    //         0053277f     FNSTSW     AX
    //         00532781     TEST       AH,0x1
    //         00532784     JNZ        LAB_00532792
    //                              victory.cpp:748 (4)
    //         00532786     MOV        byte ptr [ESI + 0x2e],0x2
    //                              victory.cpp:752 (8)
    //         0053278a     POP        EDI
    //         0053278b     POP        ESI
    //         0053278c     POP        EBP
    //         0053278d     POP        EBX
    //         0053278e     POP        this
    //         0053278f     RET        0x4
    //                               LAB_00532792                                                 XREF[1]:     00532784(j)  
    //                              victory.cpp:750 (4)
    //         00532792     MOV        byte ptr [ESI + 0x2e],0x0
    //                               LAB_00532796                                                 XREF[1]:     005326fa(j)  
    //                              victory.cpp:752 (8)
    //         00532796     POP        EDI
    //         00532797     POP        ESI
    //         00532798     POP        EBP
    //         00532799     POP        EBX
    //         0053279a     POP        this
    //         0053279b     RET        0x4
    //         0053279e     ??         90h
    //         0053279f     NOP
    return;
}

void RGE_Victory_Conditions::handle_explore(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_explore(RGE_Victory_Conditions * this, RGE_Vi
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[2]:     005327a3(R), 0053282b(R)  
    //                               ?handle_explore@RGE_Victory_Conditions@@IAEXPAURGE_Victory_  XREF[1]:     handle_condition:00531fff(c)  
    //                               RGE_Victory_Conditions::handle_explore
    //                              victory.cpp:756 (3)
    //         005327a0     PUSH       EBX
    //         005327a1     PUSH       EBP
    //         005327a2     PUSH       ESI
    //                              victory.cpp:760 (29)
    //         005327a3     MOV        ESI,dword ptr [ESP + param_1]
    //         005327a7     PUSH       EDI
    //         005327a8     MOV        EBX,this
    //         005327aa     MOV        AL,byte ptr [ESI + 0x2e]
    //         005327ad     TEST       AL,AL
    //         005327af     JNZ        LAB_00532879
    //         005327b5     MOV        EAX,dword ptr [EBX + 0xc]
    //         005327b8     TEST       EAX,EAX
    //         005327ba     JZ         LAB_00532879
    //                              victory.cpp:762 (25)
    //         005327c0     MOV        this,byte ptr [ESI + 0x2d]
    //         005327c3     TEST       this,this
    //         005327c5     JZ         LAB_0053285b
    //         005327cb     MOV        this,byte ptr [EAX + 0x104]
    //         005327d1     TEST       this,this
    //         005327d3     JZ         LAB_0053285b
    //                              victory.cpp:764 (3)
    //         005327d9     MOV        EAX,dword ptr [EAX + 0x3c]
    //                              victory.cpp:765 (14)
    //         005327dc     MOVSX      ESI,word ptr [EAX + 0x3c]
    //         005327e0     MOV        this,dword ptr [EAX + 0x40]
    //         005327e3     DEC        ESI
    //         005327e4     JS         LAB_00532879
    //                              victory.cpp:777 (3)
    //         005327ea     LEA        EDI,[this->_padding_ + ESI*0x4]
    //                               LAB_005327ed                                                 XREF[1]:     00532847(j)  
    //                              victory.cpp:766 (52)
    //         005327ed     MOV        EAX,dword ptr [EBX + 0xc]
    //         005327f0     MOV        this,dword ptr [EAX + 0x84]
    //         005327f6     CMP        byte ptr [this->_padding_ + ESI*0x1],0x0
    //         005327fa     JNZ        LAB_00532819
    //         005327fc     MOV        this,dword ptr [EDI]
    //         005327fe     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         00532802     MOV        EBP,dword ptr [this->_padding_ + 0x84]
    //         00532808     CMP        byte ptr [EBP + EDX*0x1],0x0
    //         0053280d     JNZ        LAB_00532819
    //         0053280f     MOV        DL,byte ptr [this->_padding_ + 0x104]
    //         00532815     TEST       DL,DL
    //         00532817     JNZ        LAB_00532821
    //                               LAB_00532819                                                 XREF[2]:     005327fa(j), 0053280d(j)  
    //         00532819     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         0053281d     CMP        ESI,EAX
    //         0053281f     JNZ        LAB_00532841
    //                               LAB_00532821                                                 XREF[1]:     00532817(j)  
    //                              victory.cpp:767 (32)
    //         00532821     MOV        this,dword ptr [EDI]
    //         00532823     MOV        this,dword ptr [this->_padding_ + 0x38]
    //         00532826     CALL       RGE_Visible_Map::percentExplored                 float percentExplored(RGE_Visible_Map * this)
    //         0053282b     MOV        this,dword ptr [ESP + param_1]
    //         0053282f     FMUL       float ptr [DAT_005775a0]
    //         00532835     FILD       dword ptr [ECX + this+0x20]
    //         00532838     FCOMPP
    //         0053283a     FNSTSW     AX
    //         0053283c     TEST       AH,0x41
    //         0053283f     JNZ        LAB_00532850
    //                               LAB_00532841                                                 XREF[1]:     0053281f(j)  
    //                              victory.cpp:765 (8)
    //         00532841     DEC        ESI
    //         00532842     SUB        EDI,0x4
    //         00532845     TEST       ESI,ESI
    //         00532847     JGE        LAB_005327ed
    //                              victory.cpp:777 (7)
    //         00532849     POP        EDI
    //         0053284a     POP        ESI
    //         0053284b     POP        EBP
    //         0053284c     POP        EBX
    //         0053284d     RET        0x4
    //                               LAB_00532850                                                 XREF[1]:     0053283f(j)  
    //                              victory.cpp:769 (4)
    //         00532850     MOV        byte ptr [this->_padding_ + 0x2e],0x2
    //                              victory.cpp:777 (7)
    //         00532854     POP        EDI
    //         00532855     POP        ESI
    //         00532856     POP        EBP
    //         00532857     POP        EBX
    //         00532858     RET        0x4
    //                               LAB_0053285b                                                 XREF[2]:     005327c5(j), 005327d3(j)  
    //                              victory.cpp:774 (26)
    //         0053285b     MOV        this,dword ptr [EAX + 0x38]
    //         0053285e     CALL       RGE_Visible_Map::percentExplored                 float percentExplored(RGE_Visible_Map * this)
    //         00532863     FMUL       float ptr [DAT_005775a0]
    //         00532869     FILD       dword ptr [ESI + 0x20]
    //         0053286c     FCOMPP
    //         0053286e     FNSTSW     AX
    //         00532870     TEST       AH,0x41
    //         00532873     JZ         LAB_00532879
    //                              victory.cpp:775 (4)
    //         00532875     MOV        byte ptr [ESI + 0x2e],0x2
    //                               LAB_00532879                                                 XREF[4]:     005327af(j), 005327ba(j), 
    //                                                                                                         005327e4(j), 00532873(j)  
    //                              victory.cpp:777 (7)
    //         00532879     POP        EDI
    //         0053287a     POP        ESI
    //         0053287b     POP        EBP
    //         0053287c     POP        EBX
    //         0053287d     RET        0x4
    return;
}

void RGE_Victory_Conditions::handle_victory_points(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall handle_victory_points(RGE_Victory_Conditions * this,
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[2]:     00532892(R), 0053290c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00532899(W), 005328fb(R), 00532900(W), 00532916(R)  
    //              long              Stack[-0x8]:4  player_count
    //                               ?handle_victory_points@RGE_Victory_Conditions@@IAEXPAURGE_V  XREF[1]:     handle_condition:00532008(c)  
    //                               RGE_Victory_Conditions::handle_victory_points
    //                              victory.cpp:781 (6)
    //         00532880     PUSH       this
    //         00532881     PUSH       EBX
    //         00532882     MOV        EBX,this
    //         00532884     PUSH       EBP
    //         00532885     PUSH       ESI
    //                              victory.cpp:787 (12)
    //         00532886     MOV        EAX,dword ptr [EBX + 0xc]
    //         00532889     PUSH       EDI
    //         0053288a     TEST       EAX,EAX
    //         0053288c     JZ         LAB_00532922
    //                              victory.cpp:792 (32)
    //         00532892     MOV        EDI,dword ptr [ESP + param_1]
    //         00532896     MOV        EBP,dword ptr [EBX + 0x1c]
    //         00532899     MOV        dword ptr [ESP + local_4],0x1
    //         005328a1     MOV        this,byte ptr [EDI + 0x2d]
    //         005328a4     TEST       this,this
    //         005328a6     JZ         LAB_00532910
    //         005328a8     MOV        this,byte ptr [EAX + 0x104]
    //         005328ae     TEST       this,this
    //         005328b0     JZ         LAB_00532910
    //                              victory.cpp:794 (3)
    //         005328b2     MOV        EAX,dword ptr [EAX + 0x3c]
    //                              victory.cpp:795 (10)
    //         005328b5     MOVSX      ESI,word ptr [EAX + 0x3c]
    //         005328b9     MOV        this,dword ptr [EAX + 0x40]
    //         005328bc     DEC        ESI
    //         005328bd     JS         LAB_00532910
    //                              victory.cpp:810 (3)
    //         005328bf     LEA        EDI,[this->_padding_ + ESI*0x4]
    //                               LAB_005328c2                                                 XREF[1]:     0053290a(j)  
    //                              victory.cpp:796 (47)
    //         005328c2     MOV        this,dword ptr [EBX + 0xc]
    //         005328c5     MOV        EAX,dword ptr [this->_padding_ + 0x84]
    //         005328cb     CMP        byte ptr [EAX + ESI*0x1],0x0
    //         005328cf     JNZ        LAB_00532904
    //         005328d1     MOV        EAX,dword ptr [EDI]
    //         005328d3     MOVSX      this,word ptr [this->_padding_ + 0x4a]
    //         005328d7     MOV        EDX,dword ptr [EAX + 0x84]
    //         005328dd     CMP        byte ptr [EDX + this->_padding_*0x1],0x0
    //         005328e1     JNZ        LAB_00532904
    //         005328e3     CMP        ESI,this
    //         005328e5     JZ         LAB_00532904
    //         005328e7     MOV        this,byte ptr [EAX + 0x104]
    //         005328ed     TEST       this,this
    //         005328ef     JZ         LAB_00532904
    //                              victory.cpp:798 (10)
    //         005328f1     MOV        this,dword ptr [EAX + 0x34]
    //         005328f4     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //         005328f9     ADD        EBP,EAX
    //                              victory.cpp:799 (17)
    //         005328fb     MOV        EAX,dword ptr [ESP + local_4]
    //         005328ff     INC        EAX
    //         00532900     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_00532904                                                 XREF[4]:     005328cf(j), 005328e1(j), 
    //                                                                                                         005328e5(j), 005328ef(j)  
    //         00532904     DEC        ESI
    //         00532905     SUB        EDI,0x4
    //         00532908     TEST       ESI,ESI
    //         0053290a     JGE        LAB_005328c2
    //                              victory.cpp:795 (4)
    //         0053290c     MOV        EDI,dword ptr [ESP + param_1]
    //                               LAB_00532910                                                 XREF[3]:     005328a6(j), 005328b0(j), 
    //                                                                                                         005328bd(j)  
    //                              victory.cpp:805 (14)
    //         00532910     MOV        EAX,EBP
    //         00532912     MOV        this,dword ptr [EDI + 0x20]
    //         00532915     CDQ
    //         00532916     IDIV       dword ptr [ESP + local_4]
    //         0053291a     CMP        EAX,this
    //         0053291c     JL         LAB_00532922
    //                              victory.cpp:806 (4)
    //         0053291e     MOV        byte ptr [EDI + 0x2e],0x2
    //                               LAB_00532922                                                 XREF[2]:     0053288c(j), 0053291c(j)  
    //                              victory.cpp:810 (8)
    //         00532922     POP        EDI
    //         00532923     POP        ESI
    //         00532924     POP        EBP
    //         00532925     POP        EBX
    //         00532926     POP        this
    //         00532927     RET        0x4
    //         0053292a     ??         90h
    //         0053292b     NOP
    //         0053292c     NOP
    //         0053292d     NOP
    //         0053292e     NOP
    //         0053292f     NOP
    //                              * protected: struct RGE_Victory_Entry * __thiscall RGE_Victory_Conditions::add(unsigned char,unsigne... *
    //                              RGE_Victory_Entry * __thiscall add(RGE_Victory_Conditions * this, uc
    //              RGE_Victory_En    EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532945(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     0053294f(R)  
    //                               ?add@RGE_Victory_Conditions@@IAEPAURGE_Victory_Entry@@EE@Z   XREF[13]:    add_tech:0052c9b7(c), 
    //                               RGE_Victory_Conditions::add                                               add_capture:0053297a(c), 
    //                                                                                                         add_create:005329aa(c), 
    //                                                                                                         add_create:005329da(c), 
    //                                                                                                         add_destroy:00532a27(c), 
    //                                                                                                         add_destroy:00532a57(c), 
    //                                                                                                         add_destroy:00532a97(c), 
    //                                                                                                         add_destroy:00532ac7(c), 
    //                                                                                                         add_bring:00532af7(c), 
    //                                                                                                         add_bring:00532b37(c), 
    //                                                                                                         add_attributes:00532b7a(c), 
    //                                                                                                         add_explore:00532baa(c), 
    //                                                                                                         add_victory_points:00532bea(c)  
    //                              victory.cpp:815 (1)
    //         00532930     PUSH       ESI
    //                              victory.cpp:818 (11)
    //         00532931     PUSH       0x34
    //         00532933     MOV        ESI,this
    //         00532935     PUSH       0x1
    //         00532937     CALL       calloc                                           undefined calloc()
    //                              victory.cpp:819 (9)
    //         0053293c     XOR        this,this
    //         0053293e     ADD        ESP,0x8
    //         00532941     CMP        EAX,this
    //         00532943     JZ         LAB_00532969
    //                              victory.cpp:821 (4)
    //         00532945     MOV        DL,byte ptr [ESP + param_1]
    //                              victory.cpp:823 (13)
    //         00532949     MOV        byte ptr [EAX + 0x2e],this
    //         0053294c     MOV        byte ptr [EAX + 0x2c],DL
    //         0053294f     MOV        DL,byte ptr [ESP + param_2]
    //         00532953     MOV        byte ptr [EAX + 0x2d],DL
    //                              victory.cpp:824 (3)
    //         00532956     MOV        dword ptr [EAX + 0x20],this
    //                              victory.cpp:825 (6)
    //         00532959     MOV        this,dword ptr [ESI + 0x4]
    //         0053295c     MOV        dword ptr [EAX + 0x30],this
    //                              victory.cpp:827 (10)
    //         0053295f     MOV        this,dword ptr [ESI + 0x8]
    //         00532962     INC        this
    //         00532963     MOV        dword ptr [ESI + 0x4],EAX
    //         00532966     MOV        dword ptr [ESI + 0x8],this
    //                               LAB_00532969                                                 XREF[1]:     00532943(j)  
    //                              victory.cpp:831 (4)
    //         00532969     POP        ESI
    //         0053296a     RET        0x8
    //         0053296d     ??         90h
    //         0053296e     NOP
    //         0053296f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_capture(unsigned char,class RGE_Stati... *
    //                              uchar __thiscall add_capture(RGE_Victory_Conditions * this, uchar pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532974(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00532983(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00532970(R)  
    //                               ?add_capture@RGE_Victory_Conditions@@QAEEEPAVRGE_Static_Obj  XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_capture
    //                              victory.cpp:836 (15)
    //         00532970     MOV        EAX,dword ptr [ESP + param_3]
    //         00532974     MOV        EDX,dword ptr [ESP + param_1]
    //         00532978     PUSH       EAX
    //         00532979     PUSH       EDX
    //         0053297a     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:840 (4)
    //         0053297f     TEST       EAX,EAX
    //         00532981     JZ         LAB_00532998
    //                              victory.cpp:843 (10)
    //         00532983     MOV        this,dword ptr [ESP + param_2]
    //         00532987     MOV        byte ptr [EAX],0x0
    //         0053298a     MOV        dword ptr [EAX + 0x28],this
    //                              victory.cpp:844 (6)
    //         0053298d     MOV        this,dword ptr [ECX + this->player]
    //         00532990     MOV        dword ptr [EAX + 0x8],this
    //                              victory.cpp:845 (2)
    //         00532993     MOV        AL,0x1
    //                              victory.cpp:849 (3)
    //         00532995     RET        0xc
    //                               LAB_00532998                                                 XREF[1]:     00532981(j)  
    //                              victory.cpp:848 (2)
    //         00532998     XOR        AL,AL
    //                              victory.cpp:849 (3)
    //         0053299a     RET        0xc
    //         0053299d     ??         90h
    //         0053299e     NOP
    //         0053299f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_create(unsigned char,long,long,unsign... *
    //                              uchar __thiscall add_create(RGE_Victory_Conditions * this, uchar par
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     005329a4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     005329b3(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     005329b7(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     005329a0(R)  
    //                               ?add_create@RGE_Victory_Conditions@@QAEEEJJE@Z               XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_create
    //                              victory.cpp:854 (15)
    //         005329a0     MOV        EAX,dword ptr [ESP + param_4]
    //         005329a4     MOV        EDX,dword ptr [ESP + param_1]
    //         005329a8     PUSH       EAX
    //         005329a9     PUSH       EDX
    //         005329aa     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:858 (4)
    //         005329af     TEST       EAX,EAX
    //         005329b1     JZ         LAB_005329c9
    //                              victory.cpp:861 (4)
    //         005329b3     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:862 (13)
    //         005329b7     MOV        EDX,dword ptr [ESP + param_3]
    //         005329bb     MOV        byte ptr [EAX],0x1
    //         005329be     MOV        dword ptr [EAX + 0x4],this
    //         005329c1     MOV        dword ptr [EAX + 0x1c],EDX
    //                              victory.cpp:863 (2)
    //         005329c4     MOV        AL,0x1
    //                              victory.cpp:867 (3)
    //         005329c6     RET        0x10
    //                               LAB_005329c9                                                 XREF[1]:     005329b1(j)  
    //                              victory.cpp:866 (2)
    //         005329c9     XOR        AL,AL
    //                              victory.cpp:867 (3)
    //         005329cb     RET        0x10
    //         005329ce     ??         90h
    //         005329cf     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_create(unsigned char,long,long,float,... *
    //                              uchar __thiscall add_create(RGE_Victory_Conditions * this, uchar par
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     005329d4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     005329e3(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     005329e7(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     005329ee(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     005329f5(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     005329fc(R)  
    //              float             Stack[0x1c]:4  param_7                   XREF[1]:     00532a03(R)  
    //              uchar             Stack[0x20]:1  param_8                   XREF[1]:     005329d0(R)  
    //                               ?add_create@RGE_Victory_Conditions@@QAEEEJJMMMME@Z           XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_create
    //                              victory.cpp:872 (15)
    //         005329d0     MOV        EAX,dword ptr [ESP + param_8]
    //         005329d4     MOV        EDX,dword ptr [ESP + param_1]
    //         005329d8     PUSH       EAX
    //         005329d9     PUSH       EDX
    //         005329da     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:876 (4)
    //         005329df     TEST       EAX,EAX
    //         005329e1     JZ         LAB_00532a15
    //                              victory.cpp:879 (4)
    //         005329e3     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:880 (7)
    //         005329e7     MOV        EDX,dword ptr [ESP + param_3]
    //         005329eb     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:881 (7)
    //         005329ee     MOV        this,dword ptr [ESP + param_4]
    //         005329f2     MOV        dword ptr [EAX + 0x1c],EDX
    //                              victory.cpp:882 (7)
    //         005329f5     MOV        EDX,dword ptr [ESP + param_5]
    //         005329f9     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:883 (7)
    //         005329fc     MOV        this,dword ptr [ESP + param_6]
    //         00532a00     MOV        dword ptr [EAX + 0x10],EDX
    //                              victory.cpp:884 (13)
    //         00532a03     MOV        EDX,dword ptr [ESP + param_7]
    //         00532a07     MOV        byte ptr [EAX],0x8
    //         00532a0a     MOV        dword ptr [EAX + 0x14],this
    //         00532a0d     MOV        dword ptr [EAX + 0x18],EDX
    //                              victory.cpp:885 (2)
    //         00532a10     MOV        AL,0x1
    //                              victory.cpp:889 (3)
    //         00532a12     RET        0x20
    //                               LAB_00532a15                                                 XREF[1]:     005329e1(j)  
    //                              victory.cpp:888 (2)
    //         00532a15     XOR        AL,AL
    //                              victory.cpp:889 (3)
    //         00532a17     RET        0x20
    //         00532a1a     ??         90h
    //         00532a1b     NOP
    //         00532a1c     NOP
    //         00532a1d     NOP
    //         00532a1e     NOP
    //         00532a1f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,class RGE_Stati... *
    //                              uchar __thiscall add_destroy(RGE_Victory_Conditions * this, uchar pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532a20(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00532a30(R)  
    //                               ?add_destroy@RGE_Victory_Conditions@@QAEEEPAVRGE_Static_Obj  XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_destroy
    //                              victory.cpp:894 (12)
    //         00532a20     MOV        EAX,dword ptr [ESP + param_1]
    //         00532a24     PUSH       0x0
    //         00532a26     PUSH       EAX
    //         00532a27     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:898 (4)
    //         00532a2c     TEST       EAX,EAX
    //         00532a2e     JZ         LAB_00532a45
    //                              victory.cpp:901 (10)
    //         00532a30     MOV        this,dword ptr [ESP + param_2]
    //         00532a34     MOV        byte ptr [EAX],0x2
    //         00532a37     MOV        dword ptr [EAX + 0x28],this
    //                              victory.cpp:902 (6)
    //         00532a3a     MOV        this,dword ptr [ECX + this->player]
    //         00532a3d     MOV        dword ptr [EAX + 0x8],this
    //                              victory.cpp:903 (2)
    //         00532a40     MOV        AL,0x1
    //                              victory.cpp:907 (3)
    //         00532a42     RET        0x8
    //                               LAB_00532a45                                                 XREF[1]:     00532a2e(j)  
    //                              victory.cpp:906 (2)
    //         00532a45     XOR        AL,AL
    //                              victory.cpp:907 (3)
    //         00532a47     RET        0x8
    //         00532a4a     ??         90h
    //         00532a4b     NOP
    //         00532a4c     NOP
    //         00532a4d     NOP
    //         00532a4e     NOP
    //         00532a4f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,long,long,class... *
    //                              uchar __thiscall add_destroy(RGE_Victory_Conditions * this, uchar pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532a50(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00532a60(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00532a64(R)  
    //              RGE_Player *      Stack[0x10]:4  param_4                   XREF[1]:     00532a6b(R)  
    //                               ?add_destroy@RGE_Victory_Conditions@@QAEEEJJPAVRGE_Player@@@Z XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_destroy
    //                              victory.cpp:912 (12)
    //         00532a50     MOV        EAX,dword ptr [ESP + param_1]
    //         00532a54     PUSH       0x0
    //         00532a56     PUSH       EAX
    //         00532a57     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:916 (4)
    //         00532a5c     TEST       EAX,EAX
    //         00532a5e     JZ         LAB_00532a7d
    //                              victory.cpp:919 (4)
    //         00532a60     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:920 (7)
    //         00532a64     MOV        EDX,dword ptr [ESP + param_3]
    //         00532a68     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:921 (13)
    //         00532a6b     MOV        this,dword ptr [ESP + param_4]
    //         00532a6f     MOV        byte ptr [EAX],0x3
    //         00532a72     MOV        dword ptr [EAX + 0x1c],EDX
    //         00532a75     MOV        dword ptr [EAX + 0x8],this
    //                              victory.cpp:922 (2)
    //         00532a78     MOV        AL,0x1
    //                              victory.cpp:926 (3)
    //         00532a7a     RET        0x10
    //                               LAB_00532a7d                                                 XREF[1]:     00532a5e(j)  
    //                              victory.cpp:925 (2)
    //         00532a7d     XOR        AL,AL
    //                              victory.cpp:926 (3)
    //         00532a7f     RET        0x10
    //         00532a82     ??         90h
    //         00532a83     NOP
    //         00532a84     NOP
    //         00532a85     NOP
    //         00532a86     NOP
    //         00532a87     NOP
    //         00532a88     NOP
    //         00532a89     NOP
    //         00532a8a     NOP
    //         00532a8b     NOP
    //         00532a8c     NOP
    //         00532a8d     NOP
    //         00532a8e     NOP
    //         00532a8f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,long,class RGE_... *
    //                              uchar __thiscall add_destroy(RGE_Victory_Conditions * this, uchar pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532a90(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00532aa0(R)  
    //              RGE_Player *      Stack[0xc]:4   param_3                   XREF[1]:     00532aa4(R)  
    //                               ?add_destroy@RGE_Victory_Conditions@@QAEEEJPAVRGE_Player@@@Z XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_destroy
    //                              victory.cpp:931 (12)
    //         00532a90     MOV        EAX,dword ptr [ESP + param_1]
    //         00532a94     PUSH       0x0
    //         00532a96     PUSH       EAX
    //         00532a97     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:935 (4)
    //         00532a9c     TEST       EAX,EAX
    //         00532a9e     JZ         LAB_00532ab6
    //                              victory.cpp:938 (4)
    //         00532aa0     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:939 (13)
    //         00532aa4     MOV        EDX,dword ptr [ESP + param_3]
    //         00532aa8     MOV        byte ptr [EAX],0x9
    //         00532aab     MOV        dword ptr [EAX + 0x4],this
    //         00532aae     MOV        dword ptr [EAX + 0x8],EDX
    //                              victory.cpp:940 (2)
    //         00532ab1     MOV        AL,0x1
    //                              victory.cpp:944 (3)
    //         00532ab3     RET        0xc
    //                               LAB_00532ab6                                                 XREF[1]:     00532a9e(j)  
    //                              victory.cpp:943 (2)
    //         00532ab6     XOR        AL,AL
    //                              victory.cpp:944 (3)
    //         00532ab8     RET        0xc
    //         00532abb     ??         90h
    //         00532abc     NOP
    //         00532abd     NOP
    //         00532abe     NOP
    //         00532abf     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_destroy(unsigned char,class RGE_Playe... *
    //                              uchar __thiscall add_destroy(RGE_Victory_Conditions * this, uchar pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532ac0(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     00532ad0(R)  
    //                               ?add_destroy@RGE_Victory_Conditions@@QAEEEPAVRGE_Player@@@Z  XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_destroy
    //                              victory.cpp:949 (12)
    //         00532ac0     MOV        EAX,dword ptr [ESP + param_1]
    //         00532ac4     PUSH       0x0
    //         00532ac6     PUSH       EAX
    //         00532ac7     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:953 (4)
    //         00532acc     TEST       EAX,EAX
    //         00532ace     JZ         LAB_00532adf
    //                              victory.cpp:956 (10)
    //         00532ad0     MOV        this,dword ptr [ESP + param_2]
    //         00532ad4     MOV        byte ptr [EAX],0xa
    //         00532ad7     MOV        dword ptr [EAX + 0x8],this
    //                              victory.cpp:957 (2)
    //         00532ada     MOV        AL,0x1
    //                              victory.cpp:961 (3)
    //         00532adc     RET        0x8
    //                               LAB_00532adf                                                 XREF[1]:     00532ace(j)  
    //                              victory.cpp:960 (2)
    //         00532adf     XOR        AL,AL
    //                              victory.cpp:961 (3)
    //         00532ae1     RET        0x8
    //         00532ae4     ??         90h
    //         00532ae5     NOP
    //         00532ae6     NOP
    //         00532ae7     NOP
    //         00532ae8     NOP
    //         00532ae9     NOP
    //         00532aea     NOP
    //         00532aeb     NOP
    //         00532aec     NOP
    //         00532aed     NOP
    //         00532aee     NOP
    //         00532aef     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_bring(unsigned char,class RGE_Static_... *
    //                              uchar __thiscall add_bring(RGE_Victory_Conditions * this, uchar para
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532af0(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00532b00(R)  
    //              RGE_Static_Obj    Stack[0xc]:4   param_3                   XREF[1]:     00532b0a(R)  
    //                               ?add_bring@RGE_Victory_Conditions@@QAEEEPAVRGE_Static_Objec  XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_bring
    //                              victory.cpp:966 (12)
    //         00532af0     MOV        EAX,dword ptr [ESP + param_1]
    //         00532af4     PUSH       0x0
    //         00532af6     PUSH       EAX
    //         00532af7     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:970 (4)
    //         00532afc     TEST       EAX,EAX
    //         00532afe     JZ         LAB_00532b1c
    //                              victory.cpp:973 (10)
    //         00532b00     MOV        this,dword ptr [ESP + param_2]
    //         00532b04     MOV        byte ptr [EAX],0x5
    //         00532b07     MOV        dword ptr [EAX + 0x24],this
    //                              victory.cpp:974 (7)
    //         00532b0a     MOV        this,dword ptr [ESP + param_3]
    //         00532b0e     MOV        dword ptr [EAX + 0x28],this
    //                              victory.cpp:975 (6)
    //         00532b11     MOV        EDX,dword ptr [ECX + this->player]
    //         00532b14     MOV        dword ptr [EAX + 0x8],EDX
    //                              victory.cpp:976 (2)
    //         00532b17     MOV        AL,0x1
    //                              victory.cpp:980 (3)
    //         00532b19     RET        0xc
    //                               LAB_00532b1c                                                 XREF[1]:     00532afe(j)  
    //                              victory.cpp:979 (2)
    //         00532b1c     XOR        AL,AL
    //                              victory.cpp:980 (3)
    //         00532b1e     RET        0xc
    //         00532b21     ??         90h
    //         00532b22     NOP
    //         00532b23     NOP
    //         00532b24     NOP
    //         00532b25     NOP
    //         00532b26     NOP
    //         00532b27     NOP
    //         00532b28     NOP
    //         00532b29     NOP
    //         00532b2a     NOP
    //         00532b2b     NOP
    //         00532b2c     NOP
    //         00532b2d     NOP
    //         00532b2e     NOP
    //         00532b2f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_bring(unsigned char,class RGE_Static_... *
    //                              uchar __thiscall add_bring(RGE_Victory_Conditions * this, uchar para
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532b30(R)  
    //              RGE_Static_Obj    Stack[0x8]:4   param_2                   XREF[1]:     00532b40(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     00532b44(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     00532b4b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     00532b52(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     00532b59(R)  
    //                               ?add_bring@RGE_Victory_Conditions@@QAEEEPAVRGE_Static_Objec  XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_bring
    //                              victory.cpp:985 (12)
    //         00532b30     MOV        EAX,dword ptr [ESP + param_1]
    //         00532b34     PUSH       0x0
    //         00532b36     PUSH       EAX
    //         00532b37     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:989 (4)
    //         00532b3c     TEST       EAX,EAX
    //         00532b3e     JZ         LAB_00532b6b
    //                              victory.cpp:992 (4)
    //         00532b40     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:993 (7)
    //         00532b44     MOV        EDX,dword ptr [ESP + param_3]
    //         00532b48     MOV        dword ptr [EAX + 0x24],this
    //                              victory.cpp:994 (7)
    //         00532b4b     MOV        this,dword ptr [ESP + param_4]
    //         00532b4f     MOV        dword ptr [EAX + 0xc],EDX
    //                              victory.cpp:995 (7)
    //         00532b52     MOV        EDX,dword ptr [ESP + param_5]
    //         00532b56     MOV        dword ptr [EAX + 0x10],this
    //                              victory.cpp:996 (13)
    //         00532b59     MOV        this,dword ptr [ESP + param_6]
    //         00532b5d     MOV        byte ptr [EAX],0x4
    //         00532b60     MOV        dword ptr [EAX + 0x14],EDX
    //         00532b63     MOV        dword ptr [EAX + 0x18],this
    //                              victory.cpp:997 (2)
    //         00532b66     MOV        AL,0x1
    //                              victory.cpp:1001 (3)
    //         00532b68     RET        0x18
    //                               LAB_00532b6b                                                 XREF[1]:     00532b3e(j)  
    //                              victory.cpp:1000 (2)
    //         00532b6b     XOR        AL,AL
    //                              victory.cpp:1001 (3)
    //         00532b6d     RET        0x18
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_attributes(unsigned char,long,long,un... *
    //                              uchar __thiscall add_attributes(RGE_Victory_Conditions * this, uchar
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532b74(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00532b83(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00532b87(R)  
    //              uchar             Stack[0x10]:1  param_4                   XREF[1]:     00532b70(R)  
    //                               ?add_attributes@RGE_Victory_Conditions@@QAEEEJJE@Z           XREF[15]:    Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_attributes                                    Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                              victory.cpp:1006 (15)
    //         00532b70     MOV        EAX,dword ptr [ESP + param_4]
    //         00532b74     MOV        EDX,dword ptr [ESP + param_1]
    //         00532b78     PUSH       EAX
    //         00532b79     PUSH       EDX
    //         00532b7a     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:1010 (4)
    //         00532b7f     TEST       EAX,EAX
    //         00532b81     JZ         LAB_00532b99
    //                              victory.cpp:1013 (4)
    //         00532b83     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:1014 (13)
    //         00532b87     MOV        EDX,dword ptr [ESP + param_3]
    //         00532b8b     MOV        byte ptr [EAX],0x6
    //         00532b8e     MOV        dword ptr [EAX + 0x1c],this
    //         00532b91     MOV        dword ptr [EAX + 0x20],EDX
    //                              victory.cpp:1015 (2)
    //         00532b94     MOV        AL,0x1
    //                              victory.cpp:1019 (3)
    //         00532b96     RET        0x10
    //                               LAB_00532b99                                                 XREF[1]:     00532b81(j)  
    //                              victory.cpp:1018 (2)
    //         00532b99     XOR        AL,AL
    //                              victory.cpp:1019 (3)
    //         00532b9b     RET        0x10
    //         00532b9e     ??         90h
    //         00532b9f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_explore(unsigned char,long,unsigned c... *
    //                              uchar __thiscall add_explore(RGE_Victory_Conditions * this, uchar pa
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532ba4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00532bb3(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00532ba0(R)  
    //                               ?add_explore@RGE_Victory_Conditions@@QAEEEJE@Z               XREF[3]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::add_explore                                       Save_victory_conditions_into_playe
    //                                                                                                         Save_victory_conditions_into_playe
    //                              victory.cpp:1024 (15)
    //         00532ba0     MOV        EAX,dword ptr [ESP + param_3]
    //         00532ba4     MOV        EDX,dword ptr [ESP + param_1]
    //         00532ba8     PUSH       EAX
    //         00532ba9     PUSH       EDX
    //         00532baa     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:1028 (4)
    //         00532baf     TEST       EAX,EAX
    //         00532bb1     JZ         LAB_00532bd6
    //                              victory.cpp:1031 (12)
    //         00532bb3     MOV        this,dword ptr [ESP + param_2]
    //         00532bb7     MOV        byte ptr [EAX],0x7
    //         00532bba     CMP        this,0x1
    //         00532bbd     JGE        LAB_00532bc4
    //                              victory.cpp:1032 (5)
    //         00532bbf     MOV        this,0x1
    //                               LAB_00532bc4                                                 XREF[1]:     00532bbd(j)  
    //                              victory.cpp:1033 (5)
    //         00532bc4     CMP        this,0x64
    //         00532bc7     JLE        LAB_00532bce
    //                              victory.cpp:1034 (5)
    //         00532bc9     MOV        this,0x64
    //                               LAB_00532bce                                                 XREF[1]:     00532bc7(j)  
    //                              victory.cpp:1035 (3)
    //         00532bce     MOV        dword ptr [EAX + 0x20],this
    //                              victory.cpp:1036 (2)
    //         00532bd1     MOV        AL,0x1
    //                              victory.cpp:1040 (3)
    //         00532bd3     RET        0xc
    //                               LAB_00532bd6                                                 XREF[1]:     00532bb1(j)  
    //                              victory.cpp:1039 (2)
    //         00532bd6     XOR        AL,AL
    //                              victory.cpp:1040 (3)
    //         00532bd8     RET        0xc
    //         00532bdb     ??         90h
    //         00532bdc     NOP
    //         00532bdd     NOP
    //         00532bde     NOP
    //         00532bdf     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_victory_points(unsigned char,long,uns... *
    //                              uchar __thiscall add_victory_points(RGE_Victory_Conditions * this, u
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532be4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00532bf3(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00532be0(R)  
    //                               ?add_victory_points@RGE_Victory_Conditions@@QAEEEJE@Z        XREF[2]:     new_game:0052f8e7(c), 
    //                               RGE_Victory_Conditions::add_victory_points                                new_game:0052f9af(c)  
    //                              victory.cpp:1045 (15)
    //         00532be0     MOV        EAX,dword ptr [ESP + param_3]
    //         00532be4     MOV        EDX,dword ptr [ESP + param_1]
    //         00532be8     PUSH       EAX
    //         00532be9     PUSH       EDX
    //         00532bea     CALL       RGE_Victory_Conditions::add                      RGE_Victory_Entry * add(RGE_Victory_Condition
    //                              victory.cpp:1049 (4)
    //         00532bef     TEST       EAX,EAX
    //         00532bf1     JZ         LAB_00532c02
    //                              victory.cpp:1052 (10)
    //         00532bf3     MOV        this,dword ptr [ESP + param_2]
    //         00532bf7     MOV        byte ptr [EAX],0xc
    //         00532bfa     MOV        dword ptr [EAX + 0x20],this
    //                              victory.cpp:1053 (2)
    //         00532bfd     MOV        AL,0x1
    //                              victory.cpp:1057 (3)
    //         00532bff     RET        0xc
    //                               LAB_00532c02                                                 XREF[1]:     00532bf1(j)  
    //                              victory.cpp:1056 (2)
    //         00532c02     XOR        AL,AL
    //                              victory.cpp:1057 (3)
    //         00532c04     RET        0xc
    //         00532c07     ??         90h
    //         00532c08     NOP
    //         00532c09     NOP
    //         00532c0a     NOP
    //         00532c0b     NOP
    //         00532c0c     NOP
    //         00532c0d     NOP
    //         00532c0e     NOP
    //         00532c0f     NOP
    return;
}

void RGE_Victory_Conditions::sub(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall sub(RGE_Victory_Conditions * this, RGE_Victory_Entry
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     00532c1d(R)  
    //                               ?sub@RGE_Victory_Conditions@@IAEXPAURGE_Victory_Entry@@@Z    XREF[4]:     ~RGE_Victory_Conditions:00531b36(c
    //                               RGE_Victory_Conditions::sub                                               update_for_object:00531f12(c), 
    //                                                                                                         destroy_all:00532c5d(c), 
    //                                                                                                         remove_condition:00532f31(c)  
    //                              victory.cpp:1062 (3)
    //         00532c10     PUSH       ESI
    //         00532c11     MOV        ESI,this
    //                              victory.cpp:1066 (14)
    //         00532c13     MOV        EAX,dword ptr [ESI + 0x4]
    //         00532c16     LEA        this,[ESI + 0x4]
    //         00532c19     TEST       EAX,EAX
    //         00532c1b     JZ         LAB_00532c48
    //         00532c1d     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_00532c21                                                 XREF[1]:     00532c2d(j)  
    //                              victory.cpp:1068 (4)
    //         00532c21     CMP        EAX,EDX
    //         00532c23     JZ         LAB_00532c33
    //                              victory.cpp:1076 (10)
    //         00532c25     LEA        this,[EAX + 0x30]
    //         00532c28     MOV        EAX,dword ptr [EAX + 0x30]
    //         00532c2b     TEST       EAX,EAX
    //         00532c2d     JNZ        LAB_00532c21
    //                              victory.cpp:1078 (4)
    //         00532c2f     POP        ESI
    //         00532c30     RET        0x4
    //                               LAB_00532c33                                                 XREF[1]:     00532c23(j)  
    //                              victory.cpp:1070 (3)
    //         00532c33     MOV        EDX,dword ptr [EAX + 0x30]
    //                              victory.cpp:1071 (8)
    //         00532c36     PUSH       EAX
    //         00532c37     MOV        dword ptr [this->_padding_],EDX
    //         00532c39     CALL       free                                             undefined free()
    //                              victory.cpp:1072 (10)
    //         00532c3e     MOV        EAX,dword ptr [ESI + 0x8]
    //         00532c41     ADD        ESP,0x4
    //         00532c44     DEC        EAX
    //         00532c45     MOV        dword ptr [ESI + 0x8],EAX
    //                               LAB_00532c48                                                 XREF[1]:     00532c1b(j)  
    //                              victory.cpp:1078 (4)
    //         00532c48     POP        ESI
    //         00532c49     RET        0x4
    //         00532c4c     ??         90h
    //         00532c4d     NOP
    //         00532c4e     NOP
    //         00532c4f     NOP
    return;
}

void RGE_Victory_Conditions::destroy_all() {
    /* TODO: Stub */
    //                              void __thiscall destroy_all(RGE_Victory_Conditions * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //                               ?destroy_all@RGE_Victory_Conditions@@QAEXXZ                  XREF[1]:     Save_victory_conditions_into_playe
    //                               RGE_Victory_Conditions::destroy_all
    //                              victory.cpp:1083 (3)
    //         00532c50     PUSH       ESI
    //         00532c51     MOV        ESI,this
    //                              victory.cpp:1084 (7)
    //         00532c53     MOV        EAX,dword ptr [ESI + 0x4]
    //         00532c56     TEST       EAX,EAX
    //         00532c58     JZ         LAB_00532c69
    //                               LAB_00532c5a                                                 XREF[1]:     00532c67(j)  
    //                              victory.cpp:1085 (15)
    //         00532c5a     PUSH       EAX
    //         00532c5b     MOV        this,ESI
    //         00532c5d     CALL       RGE_Victory_Conditions::sub                      void sub(RGE_Victory_Conditions * this, RGE_V
    //         00532c62     MOV        EAX,dword ptr [ESI + 0x4]
    //         00532c65     TEST       EAX,EAX
    //         00532c67     JNZ        LAB_00532c5a
    //                               LAB_00532c69                                                 XREF[1]:     00532c58(j)  
    //                              victory.cpp:1086 (2)
    //         00532c69     POP        ESI
    //         00532c6a     RET
    //         00532c6b     ??         90h
    //         00532c6c     NOP
    //         00532c6d     NOP
    //         00532c6e     NOP
    //         00532c6f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::condition_info(long,char * *,unsigned cha... *
    //                              uchar __thiscall condition_info(RGE_Victory_Conditions * this, long 
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00532c7a(R)  
    //              char * *          Stack[0x8]:4   param_2                   XREF[2]:     00532c8a(R), 00532cb0(R)  
    //              uchar *           Stack[0xc]:4   param_3
    //                               ?condition_info@RGE_Victory_Conditions@@QAEEJPAPADAAE@Z
    //                               RGE_Victory_Conditions::condition_info
    //                              victory.cpp:1092 (1)
    //         00532c70     PUSH       ESI
    //                              victory.cpp:1096 (13)
    //         00532c71     MOV        ESI,dword ptr [ECX + this->victory_list]
    //         00532c74     XOR        EAX,EAX
    //         00532c76     TEST       ESI,ESI
    //         00532c78     JZ         LAB_00532cb0
    //         00532c7a     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_00532c7e                                                 XREF[1]:     00532c88(j)  
    //                              victory.cpp:1098 (7)
    //         00532c7e     CMP        EAX,EDX
    //         00532c80     JZ         LAB_00532c96
    //         00532c82     MOV        ESI,dword ptr [ESI + 0x30]
    //                              victory.cpp:1104 (5)
    //         00532c85     INC        EAX
    //         00532c86     TEST       ESI,ESI
    //         00532c88     JNZ        LAB_00532c7e
    //                              victory.cpp:1107 (4)
    //         00532c8a     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:1108 (4)
    //         00532c8e     XOR        AL,AL
    //         00532c90     MOV        dword ptr [this->_padding_],ESI
    //                              victory.cpp:1109 (4)
    //         00532c92     POP        ESI
    //         00532c93     RET        0xc
    //                               LAB_00532c96                                                 XREF[1]:     00532c80(j)  
    //                              victory.cpp:1100 (12)
    //         00532c96     MOV        EAX,dword ptr [this->_padding_]
    //         00532c98     PUSH       ESI
    //         00532c99     CALL       dword ptr [EAX + 0x8]
    //         00532c9c     MOV        this,dword ptr [ESP + 0xc]
    //         00532ca0     MOV        dword ptr [this->_padding_],EAX
    //                              victory.cpp:1101 (8)
    //         00532ca2     MOV        EAX,dword ptr [ESP + 0x10]
    //         00532ca6     MOV        DL,byte ptr [ESI]
    //         00532ca8     MOV        byte ptr [EAX],DL
    //                              victory.cpp:1102 (2)
    //         00532caa     MOV        AL,0x1
    //                              victory.cpp:1109 (4)
    //         00532cac     POP        ESI
    //         00532cad     RET        0xc
    //                               LAB_00532cb0                                                 XREF[1]:     00532c78(j)  
    //                              victory.cpp:1107 (4)
    //         00532cb0     MOV        this,dword ptr [ESP + param_2]
    //                              victory.cpp:1108 (2)
    //         00532cb4     XOR        AL,AL
    //                              victory.cpp:1109 (10)
    //         00532cb6     POP        ESI
    //         00532cb7     MOV        dword ptr [this->_padding_],0x0
    //         00532cbd     RET        0xc
    //                              * protected: virtual char * __thiscall RGE_Victory_Conditions::condition_description(struct RGE_Vict... *
    //                              char * __thiscall condition_description(RGE_Victory_Conditions * thi
    //              char *            EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_En    Stack[0x4]:4   param_1                   XREF[1]:     00532cc6(R)  
    //              char[200]         Stack[-0xcc]   temp                      XREF[3,10]:  00532ccf(*), 00532e84(*), 00532e8f(R), 00532cef(*), 
    //                                                                                     00532d53(*), 00532d75(*), 00532da1(*), 00532dd2(*), 
    //                                                                                     00532e0b(*), 00532e36(*), 00532e56(*), 00532e6d(*), 
    //                                                                                     00532e80(*)  
    //              char *            Stack[-0xd0]:4 description
    //              undefined8        Stack[-0xdc]:8 local_dc                  XREF[2]:     00532d38(*), 00532df6(*)  
    //              undefined8        Stack[-0xe4]:8 local_e4                  XREF[2]:     00532d44(*), 00532dff(*)  
    //              undefined8        Stack[-0xec]:8 local_ec                  XREF[2]:     00532d57(*), 00532e12(*)  
    //                               ?condition_description@RGE_Victory_Conditions@@MAEPADPAURGE  XREF[2]:     00577348(*), 005775b0(*)  
    //                               RGE_Victory_Conditions::condition_description
    //                              victory.cpp:1113 (6)
    //         00532cc0     SUB        ESP,0xcc
    //                              victory.cpp:1117 (35)
    //         00532cc6     MOV        EAX,dword ptr [ESP + param_1]
    //         00532ccd     XOR        this,this
    //         00532ccf     MOV        dword ptr [ESP]=>temp,0x0
    //         00532cd7     MOV        this,byte ptr [EAX]
    //         00532cd9     CMP        this,0x9
    //         00532cdc     JA         switchD_00532ce2::default
    //                               switchD_00532ce2::switchD
    //         00532ce2     JMP        dword ptr [this->_padding_*0x4 + switchD_00532   = 00532ce9
    //                               switchD_00532ce2::caseD_0                                    XREF[2]:     00532ce2(j), 00532ea0(*)  
    //                              victory.cpp:1120 (20)
    //         00532ce9     MOV        EAX,dword ptr [EAX + 0x24]
    //         00532cec     MOV        this,dword ptr [EAX + 0x8]
    //         00532cef     LEA        EAX=>temp[4],[ESP + 0x4]
    //         00532cf3     MOV        EDX,dword ptr [ECX + this->list_num]
    //         00532cf6     PUSH       EDX
    //         00532cf7     PUSH       s_Capture_%s                                     = "Capture %s"
    //         00532cfc     PUSH       EAX
    //                              victory.cpp:1121 (5)
    //         00532cfd     JMP        LAB_00532e78
    //                               switchD_00532ce2::caseD_1                                    XREF[2]:     00532ce2(j), 00532ea4(*)  
    //                              victory.cpp:1124 (25)
    //         00532d02     MOV        EDX,dword ptr [EAX + 0x8]
    //         00532d05     MOV        this,dword ptr [EAX + 0x4]
    //         00532d08     MOV        EAX,dword ptr [EAX + 0x1c]
    //         00532d0b     MOV        EDX,dword ptr [EDX + 0x24]
    //         00532d0e     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         00532d11     MOV        EDX,dword ptr [ECX + this->list_num]
    //         00532d14     PUSH       EDX
    //         00532d15     PUSH       EAX
    //         00532d16     PUSH       s_Create_%d_%s                                   = "Create %d %s"
    //                              victory.cpp:1125 (5)
    //         00532d1b     JMP        LAB_00532dd2
    //                               switchD_00532ce2::caseD_8                                    XREF[2]:     00532ce2(j), 00532ec0(*)  
    //                              victory.cpp:1128 (74)
    //         00532d20     FLD        float ptr [EAX + 0x18]
    //         00532d23     SUB        ESP,0x8
    //         00532d26     MOV        this,dword ptr [EAX + 0x8]
    //         00532d29     MOV        EDX,dword ptr [EAX + 0x4]
    //         00532d2c     FSTP       double ptr [ESP]=>Stack[-0xd4]
    //         00532d2f     FLD        float ptr [EAX + 0x14]
    //         00532d32     MOV        this,dword ptr [this->_padding_ + 0x24]
    //         00532d35     SUB        ESP,0x8
    //         00532d38     FSTP       double ptr [ESP]=>local_dc
    //         00532d3b     FLD        float ptr [EAX + 0x10]
    //         00532d3e     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         00532d41     SUB        ESP,0x8
    //         00532d44     FSTP       double ptr [ESP]=>local_e4
    //         00532d47     FLD        float ptr [EAX + 0xc]
    //         00532d4a     MOV        this,dword ptr [EDX + 0x8]
    //         00532d4d     MOV        EDX,dword ptr [EAX + 0x1c]
    //         00532d50     SUB        ESP,0x8
    //         00532d53     LEA        EAX=>temp[4],[ESP + 0x24]
    //         00532d57     FSTP       double ptr [ESP]=>local_ec
    //         00532d5a     PUSH       this
    //         00532d5b     PUSH       EDX
    //         00532d5c     PUSH       s_Create_%d_%s_in_area_(%f,_%f)_-_               = "Create %d %s in area (%f, %f) - (%f, %f)"
    //         00532d61     PUSH       EAX
    //         00532d62     CALL       sprintf                                          undefined sprintf()
    //         00532d67     ADD        ESP,0x30
    //                              victory.cpp:1129 (5)
    //         00532d6a     JMP        switchD_00532ce2::default
    //                               switchD_00532ce2::caseD_2                                    XREF[2]:     00532ce2(j), 00532ea8(*)  
    //                              victory.cpp:1132 (20)
    //         00532d6f     MOV        this,dword ptr [EAX + 0x24]
    //         00532d72     MOV        EDX,dword ptr [ECX + this->list_num]
    //         00532d75     LEA        this=>temp[4],[ESP + 0x4]
    //         00532d79     MOV        EAX,dword ptr [EDX + 0x8]
    //         00532d7c     PUSH       EAX
    //         00532d7d     PUSH       s_Destroy_%s                                     = "Destroy %s"
    //         00532d82     PUSH       this
    //                              victory.cpp:1133 (5)
    //         00532d83     JMP        LAB_00532e78
    //                               switchD_00532ce2::caseD_3                                    XREF[2]:     00532ce2(j), 00532eac(*)  
    //                              victory.cpp:1136 (43)
    //         00532d88     MOV        this,dword ptr [EAX + 0x8]
    //         00532d8b     MOVSX      EDX,word ptr [this->_padding_ + 0x4a]
    //         00532d8f     MOV        this,dword ptr [this->_padding_ + 0x24]
    //         00532d92     PUSH       EDX
    //         00532d93     MOV        EDX,dword ptr [EAX + 0x4]
    //         00532d96     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
    //         00532d99     MOV        this,dword ptr [EDX + 0x8]
    //         00532d9c     MOV        EDX,dword ptr [EAX + 0x1c]
    //         00532d9f     PUSH       this
    //         00532da0     PUSH       EDX
    //         00532da1     LEA        EAX=>temp[4],[ESP + 0x10]
    //         00532da5     PUSH       s_Destroy_%d_%s_of_player_%d                     = "Destroy %d %s of player %d"
    //         00532daa     PUSH       EAX
    //         00532dab     CALL       sprintf                                          undefined sprintf()
    //         00532db0     ADD        ESP,0x14
    //                              victory.cpp:1137 (5)
    //         00532db3     JMP        switchD_00532ce2::default
    //                               switchD_00532ce2::caseD_9                                    XREF[2]:     00532ce2(j), 00532ec4(*)  
    //                              victory.cpp:1140 (39)
    //         00532db8     MOV        this,dword ptr [EAX + 0x8]
    //         00532dbb     MOV        EAX,dword ptr [EAX + 0x4]
    //         00532dbe     MOVSX      EDX,word ptr [this->_padding_ + 0x4a]
    //         00532dc2     MOV        this,dword ptr [this->_padding_ + 0x24]
    //         00532dc5     PUSH       EDX
    //         00532dc6     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         00532dc9     MOV        EAX,dword ptr [EDX + 0x8]
    //         00532dcc     PUSH       EAX
    //         00532dcd     PUSH       s_Destroy_all_%s_of_player_%d                    = "Destroy all %s of player %d"
    //                               LAB_00532dd2                                                 XREF[1]:     00532d1b(j)  
    //         00532dd2     LEA        this=>temp[4],[ESP + 0x10]
    //         00532dd6     PUSH       this
    //         00532dd7     CALL       sprintf                                          undefined sprintf()
    //         00532ddc     ADD        ESP,0x10
    //                              victory.cpp:1141 (5)
    //         00532ddf     JMP        switchD_00532ce2::default
    //                               switchD_00532ce2::caseD_4                                    XREF[2]:     00532ce2(j), 00532eb0(*)  
    //                              victory.cpp:1144 (64)
    //         00532de4     FLD        float ptr [EAX + 0x18]
    //         00532de7     SUB        ESP,0x8
    //         00532dea     MOV        EDX,dword ptr [EAX + 0x24]
    //         00532ded     FSTP       double ptr [ESP]=>Stack[-0xd4]
    //         00532df0     FLD        float ptr [EAX + 0x14]
    //         00532df3     SUB        ESP,0x8
    //         00532df6     FSTP       double ptr [ESP]=>local_dc
    //         00532df9     FLD        float ptr [EAX + 0x10]
    //         00532dfc     SUB        ESP,0x8
    //         00532dff     FSTP       double ptr [ESP]=>local_e4
    //         00532e02     FLD        float ptr [EAX + 0xc]
    //         00532e05     MOV        EAX,dword ptr [EDX + 0x8]
    //         00532e08     SUB        ESP,0x8
    //         00532e0b     LEA        EDX=>temp[4],[ESP + 0x24]
    //         00532e0f     MOV        this,dword ptr [EAX + 0x8]
    //         00532e12     FSTP       double ptr [ESP]=>local_ec
    //         00532e15     PUSH       this
    //         00532e16     PUSH       s_Bring_%s_to_area_(%f,_%f)_-_(%f,               = "Bring %s to area (%f, %f) - (%f, %f)"
    //         00532e1b     PUSH       EDX
    //         00532e1c     CALL       sprintf                                          undefined sprintf()
    //         00532e21     ADD        ESP,0x2c
    //                              victory.cpp:1145 (2)
    //         00532e24     JMP        switchD_00532ce2::default
    //                               switchD_00532ce2::caseD_5                                    XREF[2]:     00532ce2(j), 00532eb4(*)  
    //                              victory.cpp:1148 (38)
    //         00532e26     MOV        this,dword ptr [EAX + 0x28]
    //         00532e29     MOV        EDX,dword ptr [ECX + this->list_num]
    //         00532e2c     MOV        this,dword ptr [EDX + 0x8]
    //         00532e2f     MOV        EDX,dword ptr [EAX + 0x24]
    //         00532e32     PUSH       this
    //         00532e33     MOV        EAX,dword ptr [EDX + 0x8]
    //         00532e36     LEA        EDX=>temp[4],[ESP + 0x8]
    //         00532e3a     MOV        this,dword ptr [EAX + 0x8]
    //         00532e3d     PUSH       this
    //         00532e3e     PUSH       s_Bring_%s_to_%s                                 = "Bring %s to %s"
    //         00532e43     PUSH       EDX
    //         00532e44     CALL       sprintf                                          undefined sprintf()
    //         00532e49     ADD        ESP,0x10
    //                              victory.cpp:1149 (2)
    //         00532e4c     JMP        switchD_00532ce2::default
    //                               switchD_00532ce2::caseD_6                                    XREF[2]:     00532ce2(j), 00532eb8(*)  
    //                              victory.cpp:1152 (26)
    //         00532e4e     MOV        this,dword ptr [EAX + 0x1c]
    //         00532e51     MOV        EDX,dword ptr [EAX + 0x20]
    //         00532e54     PUSH       this
    //         00532e55     PUSH       EDX
    //         00532e56     LEA        EAX=>temp[4],[ESP + 0xc]
    //         00532e5a     PUSH       s_aqquire_%d_of_attribute_%d                     = "aqquire %d of attribute %d"
    //         00532e5f     PUSH       EAX
    //         00532e60     CALL       sprintf                                          undefined sprintf()
    //         00532e65     ADD        ESP,0x10
    //                              victory.cpp:1153 (2)
    //         00532e68     JMP        switchD_00532ce2::default
    //                               switchD_00532ce2::caseD_7                                    XREF[2]:     00532ce2(j), 00532ebc(*)  
    //                              victory.cpp:1156 (22)
    //         00532e6a     MOV        this,dword ptr [EAX + 0x20]
    //         00532e6d     LEA        EDX=>temp[4],[ESP + 0x4]
    //         00532e71     PUSH       this
    //         00532e72     PUSH       s_explore_%d_percent_of_the_map                  = "explore %d percent of the map"
    //         00532e77     PUSH       EDX
    //                               LAB_00532e78                                                 XREF[2]:     00532cfd(j), 00532d83(j)  
    //         00532e78     CALL       sprintf                                          undefined sprintf()
    //         00532e7d     ADD        ESP,0xc
    //                               switchD_00532ce2::default                                    XREF[7]:     00532cdc(j), 00532d6a(j), 
    //                                                                                                         00532db3(j), 00532ddf(j), 
    //                                                                                                         00532e24(j), 00532e4c(j), 
    //                                                                                                         00532e68(j)  
    //                              victory.cpp:1164 (15)
    //         00532e80     LEA        EAX=>temp[4],[ESP + 0x4]
    //         00532e84     LEA        this=>temp,[ESP]
    //         00532e88     PUSH       EAX
    //         00532e89     PUSH       this
    //         00532e8a     CALL       getstring                                        void getstring(char * * param_1, char * param
    //                              victory.cpp:1166 (7)
    //         00532e8f     MOV        EAX,dword ptr [ESP + temp[0]]
    //         00532e93     ADD        ESP,0x8
    //                              victory.cpp:1167 (50)
    //         00532e96     ADD        ESP,0xcc
    //         00532e9c     RET        0x4
    //         00532e9f     ??         90h
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00532ce2::switchdataD_00532ea0                       XREF[1]:     condition_description:00532ce2(*)  
    //         00532ea0     addr       switchD_00532ce2::caseD_0
    //         00532ea4     addr       switchD_00532ce2::caseD_1
    //         00532ea8     addr       switchD_00532ce2::caseD_2
    //         00532eac     addr       switchD_00532ce2::caseD_3
    //         00532eb0     addr       switchD_00532ce2::caseD_4
    //         00532eb4     addr       switchD_00532ce2::caseD_5
    //         00532eb8     addr       switchD_00532ce2::caseD_6
    //         00532ebc     addr       switchD_00532ce2::caseD_7
    //         00532ec0     addr       switchD_00532ce2::caseD_8
    //         00532ec4     addr       switchD_00532ce2::caseD_9
    //         00532ec8     ??         90h
    //         00532ec9     ??         90h
    //         00532eca     ??         90h
    //         00532ecb     ??         90h
    //         00532ecc     ??         90h
    //         00532ecd     ??         90h
    //         00532ece     ??         90h
    //         00532ecf     ??         90h
    return;
}

RGE_Victory_Entry* RGE_Victory_Conditions::condition_raw_info(long param_1) {
    /* TODO: Stub */
    //                              RGE_Victory_Entry * __thiscall condition_raw_info(RGE_Victory_Condit
    //              RGE_Victory_En    EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00532ed9(R)  
    //                               ?condition_raw_info@RGE_Victory_Conditions@@QAEPAURGE_Victo  XREF[1]:     update:004e985c(c)  
    //                               RGE_Victory_Conditions::condition_raw_info
    //                              victory.cpp:1172 (13)
    //         00532ed0     MOV        EAX,dword ptr [ECX + this->victory_list]
    //         00532ed3     XOR        EDX,EDX
    //         00532ed5     TEST       EAX,EAX
    //         00532ed7     JZ         LAB_00532ee9
    //         00532ed9     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_00532edd                                                 XREF[1]:     00532ee7(j)  
    //                              victory.cpp:1178 (7)
    //         00532edd     CMP        EDX,this
    //         00532edf     JZ         LAB_00532eeb
    //         00532ee1     MOV        EAX,dword ptr [EAX + 0x30]
    //                              victory.cpp:1182 (5)
    //         00532ee4     INC        EDX
    //         00532ee5     TEST       EAX,EAX
    //         00532ee7     JNZ        LAB_00532edd
    //                               LAB_00532ee9                                                 XREF[1]:     00532ed7(j)  
    //                              victory.cpp:1184 (2)
    //         00532ee9     XOR        EAX,EAX
    //                               LAB_00532eeb                                                 XREF[1]:     00532edf(j)  
    //                              victory.cpp:1185 (3)
    //         00532eeb     RET        0x4
    //         00532eee     ??         90h
    //         00532eef     NOP
    return 0;
}

long RGE_Victory_Conditions::condition_number(long param_1) {
    /* TODO: Stub */
    //                              long __thiscall condition_number(RGE_Victory_Conditions * this, long
    //              long              EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //                               ?condition_number@RGE_Victory_Conditions@@QAEJJ@Z
    //                               RGE_Victory_Conditions::condition_number
    //                              victory.cpp:1190 (3)
    //         00532ef0     MOV        EAX,dword ptr [ECX + this->list_num]
    //                              victory.cpp:1192 (3)
    //         00532ef3     RET        0x4
    //         00532ef6     ??         90h
    //         00532ef7     NOP
    //         00532ef8     NOP
    //         00532ef9     NOP
    //         00532efa     NOP
    //         00532efb     NOP
    //         00532efc     NOP
    //         00532efd     NOP
    //         00532efe     NOP
    //         00532eff     NOP
    return 0;
}

uchar RGE_Victory_Conditions::victory_achieved() {
    /* TODO: Stub */
    //                              uchar __thiscall victory_achieved(RGE_Victory_Conditions * this)
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //                               ?victory_achieved@RGE_Victory_Conditions@@QAEEXZ             XREF[2]:     check_victory_conditions:0047069c(
    //                               RGE_Victory_Conditions::victory_achieved                                  check_victory:0047076e(c)  
    //                              victory.cpp:1196 (7)
    //         00532f00     CMP        byte ptr [ECX + this->victory],0x2
    //         00532f04     SETZ       AL
    //                              victory.cpp:1201 (1)
    //         00532f07     RET
    //         00532f08     ??         90h
    //         00532f09     NOP
    //         00532f0a     NOP
    //         00532f0b     NOP
    //         00532f0c     NOP
    //         00532f0d     NOP
    //         00532f0e     NOP
    //         00532f0f     NOP
    return 0;
}

uchar RGE_Victory_Conditions::remove_condition(long param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall remove_condition(RGE_Victory_Conditions * this, lon
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     00532f1a(R)  
    //                               ?remove_condition@RGE_Victory_Conditions@@QAEEJ@Z
    //                               RGE_Victory_Conditions::remove_condition
    //                              victory.cpp:1206 (14)
    //         00532f10     MOV        EAX,dword ptr [ECX + this->victory_list]
    //         00532f13     XOR        EDX,EDX
    //         00532f15     TEST       EAX,EAX
    //         00532f17     PUSH       ESI
    //         00532f18     JZ         LAB_00532f3c
    //         00532f1a     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_00532f1e                                                 XREF[1]:     00532f28(j)  
    //                              victory.cpp:1212 (7)
    //         00532f1e     CMP        EDX,ESI
    //         00532f20     JZ         LAB_00532f30
    //         00532f22     MOV        EAX,dword ptr [EAX + 0x30]
    //                              victory.cpp:1217 (5)
    //         00532f25     INC        EDX
    //         00532f26     TEST       EAX,EAX
    //         00532f28     JNZ        LAB_00532f1e
    //                              victory.cpp:1220 (2)
    //         00532f2a     XOR        AL,AL
    //                              victory.cpp:1221 (4)
    //         00532f2c     POP        ESI
    //         00532f2d     RET        0x4
    //                               LAB_00532f30                                                 XREF[1]:     00532f20(j)  
    //                              victory.cpp:1214 (6)
    //         00532f30     PUSH       EAX
    //         00532f31     CALL       RGE_Victory_Conditions::sub                      void sub(RGE_Victory_Conditions * this, RGE_V
    //                              victory.cpp:1215 (2)
    //         00532f36     MOV        AL,0x1
    //                              victory.cpp:1221 (4)
    //         00532f38     POP        ESI
    //         00532f39     RET        0x4
    //                               LAB_00532f3c                                                 XREF[1]:     00532f18(j)  
    //                              victory.cpp:1220 (2)
    //         00532f3c     XOR        AL,AL
    //                              victory.cpp:1221 (4)
    //         00532f3e     POP        ESI
    //         00532f3f     RET        0x4
    //         00532f42     ??         90h
    //         00532f43     NOP
    //         00532f44     NOP
    //         00532f45     NOP
    //         00532f46     NOP
    //         00532f47     NOP
    //         00532f48     NOP
    //         00532f49     NOP
    //         00532f4a     NOP
    //         00532f4b     NOP
    //         00532f4c     NOP
    //         00532f4d     NOP
    //         00532f4e     NOP
    //         00532f4f     NOP
    //                              * protected: struct RGE_Victory_Point_Entry * __thiscall RGE_Victory_Conditions::add_point(unsigned ... *
    //                              RGE_Victory_Point_Entry * __thiscall add_point(RGE_Victory_Condition
    //              RGE_Victory_Po    EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532f65(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00532f85(R)  
    //                               ?add_point@RGE_Victory_Conditions@@IAEPAURGE_Victory_Point_  XREF[6]:     RGE_Victory_Conditions:00531a0f(c)
    //                               RGE_Victory_Conditions::add_point                                         add_points_attribute_amount:00532f
    //                                                                                                         add_points_attribute_first:0053302
    //                                                                                                         add_points_highest_attribute:00533
    //                                                                                                         add_points_high_attribute_once:005
    //                                                                                                         add_points_high_attribute_amount:0
    //                              victory.cpp:1226 (1)
    //         00532f50     PUSH       ESI
    //                              victory.cpp:1229 (11)
    //         00532f51     PUSH       0x1c
    //         00532f53     MOV        ESI,this
    //         00532f55     PUSH       0x1
    //         00532f57     CALL       calloc                                           undefined calloc()
    //                              victory.cpp:1230 (9)
    //         00532f5c     XOR        this,this
    //         00532f5e     ADD        ESP,0x8
    //         00532f61     CMP        EAX,this
    //         00532f63     JZ         LAB_00532f99
    //                              victory.cpp:1239 (32)
    //         00532f65     MOV        DL,byte ptr [ESP + param_1]
    //         00532f69     MOV        byte ptr [EAX + 0x1],this
    //         00532f6c     MOV        dword ptr [EAX + 0x4],0xffffffff
    //         00532f73     MOV        dword ptr [EAX + 0x8],this
    //         00532f76     MOV        byte ptr [EAX],0xff
    //         00532f79     MOV        dword ptr [EAX + 0xc],this
    //         00532f7c     MOV        dword ptr [EAX + 0x10],this
    //         00532f7f     MOV        this,dword ptr [ESI + 0x14]
    //         00532f82     MOV        dword ptr [EAX + 0x18],this
    //                              victory.cpp:1240 (10)
    //         00532f85     MOV        this,byte ptr [ESP + param_2]
    //         00532f89     MOV        byte ptr [EAX + 0x2],DL
    //         00532f8c     MOV        byte ptr [EAX + 0x3],this
    //                              victory.cpp:1242 (10)
    //         00532f8f     MOV        this,dword ptr [ESI + 0x18]
    //         00532f92     MOV        dword ptr [ESI + 0x14],EAX
    //         00532f95     INC        this
    //         00532f96     MOV        dword ptr [ESI + 0x18],this
    //                               LAB_00532f99                                                 XREF[1]:     00532f63(j)  
    //                              victory.cpp:1246 (4)
    //         00532f99     POP        ESI
    //         00532f9a     RET        0x8
    //         00532f9d     ??         90h
    //         00532f9e     NOP
    //         00532f9f     NOP
    return 0;
}

void RGE_Victory_Conditions::sub_point(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    //                              void __thiscall sub_point(RGE_Victory_Conditions * this, RGE_Victory
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[1]:     00532fad(R)  
    //                               ?sub_point@RGE_Victory_Conditions@@IAEXPAURGE_Victory_Point  XREF[1]:     ~RGE_Victory_Conditions:00531b4c(c
    //                               RGE_Victory_Conditions::sub_point
    //                              victory.cpp:1251 (3)
    //         00532fa0     PUSH       ESI
    //         00532fa1     MOV        ESI,this
    //                              victory.cpp:1255 (14)
    //         00532fa3     MOV        EAX,dword ptr [ESI + 0x14]
    //         00532fa6     LEA        this,[ESI + 0x14]
    //         00532fa9     TEST       EAX,EAX
    //         00532fab     JZ         LAB_00532fd8
    //         00532fad     MOV        EDX,dword ptr [ESP + param_1]
    //                               LAB_00532fb1                                                 XREF[1]:     00532fbd(j)  
    //                              victory.cpp:1257 (4)
    //         00532fb1     CMP        EAX,EDX
    //         00532fb3     JZ         LAB_00532fc3
    //                              victory.cpp:1265 (10)
    //         00532fb5     LEA        this,[EAX + 0x18]
    //         00532fb8     MOV        EAX,dword ptr [EAX + 0x18]
    //         00532fbb     TEST       EAX,EAX
    //         00532fbd     JNZ        LAB_00532fb1
    //                              victory.cpp:1267 (4)
    //         00532fbf     POP        ESI
    //         00532fc0     RET        0x4
    //                               LAB_00532fc3                                                 XREF[1]:     00532fb3(j)  
    //                              victory.cpp:1259 (3)
    //         00532fc3     MOV        EDX,dword ptr [EAX + 0x18]
    //                              victory.cpp:1260 (8)
    //         00532fc6     PUSH       EAX
    //         00532fc7     MOV        dword ptr [this->_padding_],EDX
    //         00532fc9     CALL       free                                             undefined free()
    //                              victory.cpp:1261 (10)
    //         00532fce     MOV        EAX,dword ptr [ESI + 0x18]
    //         00532fd1     ADD        ESP,0x4
    //         00532fd4     DEC        EAX
    //         00532fd5     MOV        dword ptr [ESI + 0x18],EAX
    //                               LAB_00532fd8                                                 XREF[1]:     00532fab(j)  
    //                              victory.cpp:1267 (4)
    //         00532fd8     POP        ESI
    //         00532fd9     RET        0x4
    //         00532fdc     ??         90h
    //         00532fdd     NOP
    //         00532fde     NOP
    //         00532fdf     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_points_attribute_amount(unsigned char... *
    //                              uchar __thiscall add_points_attribute_amount(RGE_Victory_Conditions 
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00532fe0(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00532fe4(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00532ff3(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00532ff7(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     00532ffe(R)  
    //                               ?add_points_attribute_amount@RGE_Victory_Conditions@@QAEEEE  XREF[15]:    new_game:00530097(c), 
    //                               RGE_Victory_Conditions::add_points_attribute_amount                       new_game:005300ac(c), 
    //                                                                                                         new_game:005300c2(c), 
    //                                                                                                         new_game:005300ef(c), 
    //                                                                                                         new_game:00530105(c), 
    //                                                                                                         new_game:00530146(c), 
    //                                                                                                         new_game:00530182(c), 
    //                                                                                                         new_game:005301b0(c), 
    //                                                                                                         new_game:005301c7(c), 
    //                                                                                                         new_game:005301de(c), 
    //                                                                                                         new_game:005301f5(c), 
    //                                                                                                         new_game:0053020c(c), 
    //                                                                                                         new_game:00530223(c), 
    //                                                                                                         new_game:00530281(c), 
    //                                                                                                         new_game:00530298(c)  
    //                              victory.cpp:1271 (15)
    //         00532fe0     MOV        EAX,dword ptr [ESP + param_1]
    //         00532fe4     MOV        EDX,dword ptr [ESP + param_2]
    //         00532fe8     PUSH       EAX
    //         00532fe9     PUSH       EDX
    //         00532fea     CALL       RGE_Victory_Conditions::add_point                RGE_Victory_Point_Entry * add_point(RGE_Victo
    //                              victory.cpp:1275 (4)
    //         00532fef     TEST       EAX,EAX
    //         00532ff1     JZ         LAB_00533010
    //                              victory.cpp:1278 (4)
    //         00532ff3     MOV        this,dword ptr [ESP + param_3]
    //                              victory.cpp:1279 (7)
    //         00532ff7     MOV        EDX,dword ptr [ESP + param_4]
    //         00532ffb     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:1280 (13)
    //         00532ffe     MOV        this,dword ptr [ESP + param_5]
    //         00533002     MOV        byte ptr [EAX],0x0
    //         00533005     MOV        dword ptr [EAX + 0x8],EDX
    //         00533008     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:1281 (2)
    //         0053300b     MOV        AL,0x1
    //                              victory.cpp:1285 (3)
    //         0053300d     RET        0x14
    //                               LAB_00533010                                                 XREF[1]:     00532ff1(j)  
    //                              victory.cpp:1284 (2)
    //         00533010     XOR        AL,AL
    //                              victory.cpp:1285 (3)
    //         00533012     RET        0x14
    //         00533015     ??         90h
    //         00533016     NOP
    //         00533017     NOP
    //         00533018     NOP
    //         00533019     NOP
    //         0053301a     NOP
    //         0053301b     NOP
    //         0053301c     NOP
    //         0053301d     NOP
    //         0053301e     NOP
    //         0053301f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_points_attribute_first(unsigned char,... *
    //                              uchar __thiscall add_points_attribute_first(RGE_Victory_Conditions *
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00533020(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00533024(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00533033(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00533037(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0053303e(R)  
    //                               ?add_points_attribute_first@RGE_Victory_Conditions@@QAEEEEJ  XREF[2]:     new_game:00530252(c), 
    //                               RGE_Victory_Conditions::add_points_attribute_first                        new_game:0053026a(c)  
    //                              victory.cpp:1289 (15)
    //         00533020     MOV        EAX,dword ptr [ESP + param_1]
    //         00533024     MOV        EDX,dword ptr [ESP + param_2]
    //         00533028     PUSH       EAX
    //         00533029     PUSH       EDX
    //         0053302a     CALL       RGE_Victory_Conditions::add_point                RGE_Victory_Point_Entry * add_point(RGE_Victo
    //                              victory.cpp:1293 (4)
    //         0053302f     TEST       EAX,EAX
    //         00533031     JZ         LAB_00533050
    //                              victory.cpp:1296 (4)
    //         00533033     MOV        this,dword ptr [ESP + param_3]
    //                              victory.cpp:1297 (7)
    //         00533037     MOV        EDX,dword ptr [ESP + param_4]
    //         0053303b     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:1298 (13)
    //         0053303e     MOV        this,dword ptr [ESP + param_5]
    //         00533042     MOV        byte ptr [EAX],0x1
    //         00533045     MOV        dword ptr [EAX + 0x8],EDX
    //         00533048     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:1299 (2)
    //         0053304b     MOV        AL,0x1
    //                              victory.cpp:1303 (3)
    //         0053304d     RET        0x14
    //                               LAB_00533050                                                 XREF[1]:     00533031(j)  
    //                              victory.cpp:1302 (2)
    //         00533050     XOR        AL,AL
    //                              victory.cpp:1303 (3)
    //         00533052     RET        0x14
    //         00533055     ??         90h
    //         00533056     NOP
    //         00533057     NOP
    //         00533058     NOP
    //         00533059     NOP
    //         0053305a     NOP
    //         0053305b     NOP
    //         0053305c     NOP
    //         0053305d     NOP
    //         0053305e     NOP
    //         0053305f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_points_highest_attribute(unsigned cha... *
    //                              uchar __thiscall add_points_highest_attribute(RGE_Victory_Conditions
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00533060(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00533064(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00533073(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     00533077(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0053307e(R)  
    //                               ?add_points_highest_attribute@RGE_Victory_Conditions@@QAEEE  XREF[3]:     new_game:0053016b(c), 
    //                               RGE_Victory_Conditions::add_points_highest_attribute                      new_game:00530199(c), 
    //                                                                                                         new_game:0053023a(c)  
    //                              victory.cpp:1307 (15)
    //         00533060     MOV        EAX,dword ptr [ESP + param_1]
    //         00533064     MOV        EDX,dword ptr [ESP + param_2]
    //         00533068     PUSH       EAX
    //         00533069     PUSH       EDX
    //         0053306a     CALL       RGE_Victory_Conditions::add_point                RGE_Victory_Point_Entry * add_point(RGE_Victo
    //                              victory.cpp:1311 (4)
    //         0053306f     TEST       EAX,EAX
    //         00533071     JZ         LAB_00533090
    //                              victory.cpp:1314 (4)
    //         00533073     MOV        this,dword ptr [ESP + param_3]
    //                              victory.cpp:1315 (7)
    //         00533077     MOV        EDX,dword ptr [ESP + param_4]
    //         0053307b     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:1316 (13)
    //         0053307e     MOV        this,dword ptr [ESP + param_5]
    //         00533082     MOV        byte ptr [EAX],0x2
    //         00533085     MOV        dword ptr [EAX + 0x8],EDX
    //         00533088     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:1317 (2)
    //         0053308b     MOV        AL,0x1
    //                              victory.cpp:1321 (3)
    //         0053308d     RET        0x14
    //                               LAB_00533090                                                 XREF[1]:     00533071(j)  
    //                              victory.cpp:1320 (2)
    //         00533090     XOR        AL,AL
    //                              victory.cpp:1321 (3)
    //         00533092     RET        0x14
    //         00533095     ??         90h
    //         00533096     NOP
    //         00533097     NOP
    //         00533098     NOP
    //         00533099     NOP
    //         0053309a     NOP
    //         0053309b     NOP
    //         0053309c     NOP
    //         0053309d     NOP
    //         0053309e     NOP
    //         0053309f     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_points_high_attribute_once(unsigned c... *
    //                              uchar __thiscall add_points_high_attribute_once(RGE_Victory_Conditio
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     005330a0(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     005330a4(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     005330b3(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     005330b7(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     005330be(R)  
    //                               ?add_points_high_attribute_once@RGE_Victory_Conditions@@QAE  XREF[2]:     new_game:005300d9(c), 
    //                               RGE_Victory_Conditions::add_points_high_attribute_once                    new_game:00530130(c)  
    //                              victory.cpp:1325 (15)
    //         005330a0     MOV        EAX,dword ptr [ESP + param_1]
    //         005330a4     MOV        EDX,dword ptr [ESP + param_2]
    //         005330a8     PUSH       EAX
    //         005330a9     PUSH       EDX
    //         005330aa     CALL       RGE_Victory_Conditions::add_point                RGE_Victory_Point_Entry * add_point(RGE_Victo
    //                              victory.cpp:1329 (4)
    //         005330af     TEST       EAX,EAX
    //         005330b1     JZ         LAB_005330d0
    //                              victory.cpp:1332 (4)
    //         005330b3     MOV        this,dword ptr [ESP + param_3]
    //                              victory.cpp:1333 (7)
    //         005330b7     MOV        EDX,dword ptr [ESP + param_4]
    //         005330bb     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:1334 (13)
    //         005330be     MOV        this,dword ptr [ESP + param_5]
    //         005330c2     MOV        byte ptr [EAX],0x3
    //         005330c5     MOV        dword ptr [EAX + 0x8],EDX
    //         005330c8     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:1335 (2)
    //         005330cb     MOV        AL,0x1
    //                              victory.cpp:1339 (3)
    //         005330cd     RET        0x14
    //                               LAB_005330d0                                                 XREF[1]:     005330b1(j)  
    //                              victory.cpp:1338 (2)
    //         005330d0     XOR        AL,AL
    //                              victory.cpp:1339 (3)
    //         005330d2     RET        0x14
    //         005330d5     ??         90h
    //         005330d6     NOP
    //         005330d7     NOP
    //         005330d8     NOP
    //         005330d9     NOP
    //         005330da     NOP
    //         005330db     NOP
    //         005330dc     NOP
    //         005330dd     NOP
    //         005330de     NOP
    //         005330df     NOP
    //                              * public: unsigned char __thiscall RGE_Victory_Conditions::add_points_high_attribute_amount(unsigned... *
    //                              uchar __thiscall add_points_high_attribute_amount(RGE_Victory_Condit
    //              uchar             AL:1           <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     005330e0(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     005330e4(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     005330f3(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     005330f7(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     005330fe(R)  
    //                               ?add_points_high_attribute_amount@RGE_Victory_Conditions@@Q  XREF[1]:     new_game:0053011a(c)  
    //                               RGE_Victory_Conditions::add_points_high_attribute_amount
    //                              victory.cpp:1343 (15)
    //         005330e0     MOV        EAX,dword ptr [ESP + param_1]
    //         005330e4     MOV        EDX,dword ptr [ESP + param_2]
    //         005330e8     PUSH       EAX
    //         005330e9     PUSH       EDX
    //         005330ea     CALL       RGE_Victory_Conditions::add_point                RGE_Victory_Point_Entry * add_point(RGE_Victo
    //                              victory.cpp:1347 (4)
    //         005330ef     TEST       EAX,EAX
    //         005330f1     JZ         LAB_00533110
    //                              victory.cpp:1350 (4)
    //         005330f3     MOV        this,dword ptr [ESP + param_3]
    //                              victory.cpp:1351 (7)
    //         005330f7     MOV        EDX,dword ptr [ESP + param_4]
    //         005330fb     MOV        dword ptr [EAX + 0x4],this
    //                              victory.cpp:1352 (13)
    //         005330fe     MOV        this,dword ptr [ESP + param_5]
    //         00533102     MOV        byte ptr [EAX],0x4
    //         00533105     MOV        dword ptr [EAX + 0x8],EDX
    //         00533108     MOV        dword ptr [EAX + 0xc],this
    //                              victory.cpp:1353 (2)
    //         0053310b     MOV        AL,0x1
    //                              victory.cpp:1357 (3)
    //         0053310d     RET        0x14
    //                               LAB_00533110                                                 XREF[1]:     005330f1(j)  
    //                              victory.cpp:1356 (2)
    //         00533110     XOR        AL,AL
    //                              victory.cpp:1357 (3)
    //         00533112     RET        0x14
    //         00533115     ??         90h
    //         00533116     NOP
    //         00533117     NOP
    //         00533118     NOP
    //         00533119     NOP
    //         0053311a     NOP
    //         0053311b     NOP
    //         0053311c     NOP
    //         0053311d     NOP
    //         0053311e     NOP
    //         0053311f     NOP
    //                              * protected: void __thiscall RGE_Victory_Conditions::handle_points_attribute_amount(struct RGE_Victo... *
    //                              void __thiscall handle_points_attribute_amount(RGE_Victory_Condition
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[3]:     00533121(R), 00533140(W), 00533145(R)  
    //                               ?handle_points_attribute_amount@RGE_Victory_Conditions@@IAE  XREF[1]:     handle_point_condition:00531f45(c)
    //                               RGE_Victory_Conditions::handle_points_attribute_amount
    //                              victory.cpp:1361 (1)
    //         00533120     PUSH       ESI
    //                              victory.cpp:1365 (14)
    //         00533121     MOV        ESI,dword ptr [ESP + param_1]
    //         00533125     PUSH       EDI
    //         00533126     MOV        EDI,this
    //         00533128     MOV        AL,byte ptr [ESI + 0x1]
    //         0053312b     TEST       AL,AL
    //         0053312d     JNZ        LAB_00533171
    //                              victory.cpp:1367 (21)
    //         0053312f     MOV        EAX,dword ptr [EDI + 0xc]
    //         00533132     MOV        this,dword ptr [ESI + 0x4]
    //         00533135     MOV        EDX,dword ptr [EAX + 0x50]
    //         00533138     FLD        float ptr [EDX + this->_padding_*0x4]
    //         0053313b     CALL       __ftol                                           undefined __ftol()
    //         00533140     MOV        dword ptr [ESP + param_1],EAX
    //                              victory.cpp:1369 (11)
    //         00533144     CDQ
    //         00533145     FILD       dword ptr [ESP + param_1]
    //         00533149     IDIV       dword ptr [ESI + 0x8]
    //         0053314c     FSTP       float ptr [ESI + 0x14]
    //                              victory.cpp:1370 (4)
    //         0053314f     TEST       EAX,EAX
    //         00533151     JGE        LAB_00533155
    //                              victory.cpp:1371 (2)
    //         00533153     XOR        EAX,EAX
    //                               LAB_00533155                                                 XREF[1]:     00533151(j)  
    //                              victory.cpp:1372 (6)
    //         00533155     MOV        this,dword ptr [ESI + 0xc]
    //         00533158     IMUL       this,EAX
    //                              victory.cpp:1373 (7)
    //         0053315b     MOV        EAX,dword ptr [ESI + 0x10]
    //         0053315e     CMP        this,EAX
    //         00533160     JZ         LAB_00533171
    //                              victory.cpp:1375 (12)
    //         00533162     MOV        EDX,this
    //         00533164     SUB        EDX,EAX
    //         00533166     MOV        EAX,dword ptr [EDI + 0x1c]
    //         00533169     ADD        EAX,EDX
    //         0053316b     MOV        dword ptr [EDI + 0x1c],EAX
    //                              victory.cpp:1376 (3)
    //         0053316e     MOV        dword ptr [ESI + 0x10],this
    //                               LAB_00533171                                                 XREF[2]:     0053312d(j), 00533160(j)  
    //                              victory.cpp:1379 (5)
    //         00533171     POP        EDI
    //         00533172     POP        ESI
    //         00533173     RET        0x4
    //         00533176     ??         90h
    //         00533177     NOP
    //         00533178     NOP
    //         00533179     NOP
    //         0053317a     NOP
    //         0053317b     NOP
    //         0053317c     NOP
    //         0053317d     NOP
    //         0053317e     NOP
    //         0053317f     NOP
    //                              * protected: void __thiscall RGE_Victory_Conditions::handle_points_attribute_first(struct RGE_Victor... *
    //                              void __thiscall handle_points_attribute_first(RGE_Victory_Conditions
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[5]:     00533187(R), 005331b2(W), 005331ba(R), 005331e3(W), 
    //                                                                                     005331e7(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     005331b6(W), 00533208(R)  
    //              long              Stack[-0x8]:4  points                    XREF[2]:     005331c6(W), 005331ef(R)  
    //                               ?handle_points_attribute_first@RGE_Victory_Conditions@@IAEX  XREF[1]:     handle_point_condition:00531f4e(c)
    //                               RGE_Victory_Conditions::handle_points_attribute_first
    //                              victory.cpp:1383 (7)
    //         00533180     SUB        ESP,0x8
    //         00533183     PUSH       EBX
    //         00533184     PUSH       EBP
    //         00533185     PUSH       ESI
    //         00533186     PUSH       EDI
    //                              victory.cpp:1389 (17)
    //         00533187     MOV        EDI,dword ptr [ESP + param_1]
    //         0053318b     MOV        EBP,this
    //         0053318d     MOV        AL,byte ptr [EDI + 0x1]
    //         00533190     TEST       AL,AL
    //         00533192     JNZ        LAB_00533222
    //                              victory.cpp:1391 (20)
    //         00533198     MOV        ESI,dword ptr [EBP + 0xc]
    //         0053319b     MOV        EBX,dword ptr [EDI + 0x4]
    //         0053319e     SHL        EBX,0x2
    //         005331a1     MOV        EAX,dword ptr [ESI + 0x50]
    //         005331a4     FLD        float ptr [EAX + EBX*0x1]
    //         005331a7     CALL       __ftol                                           undefined __ftol()
    //                              victory.cpp:1392 (3)
    //         005331ac     MOV        this,dword ptr [EDI + 0xc]
    //                              victory.cpp:1393 (11)
    //         005331af     MOV        EDX,dword ptr [ESI + 0x3c]
    //         005331b2     MOV        dword ptr [ESP + param_1],EAX
    //         005331b6     MOV        dword ptr [ESP + local_4],this
    //                              victory.cpp:1394 (4)
    //         005331ba     FILD       dword ptr [ESP + param_1]
    //                              victory.cpp:1396 (17)
    //         005331be     MOV        this,dword ptr [EDI + 0x8]
    //         005331c1     MOV        EDX,dword ptr [EDX + 0x40]
    //         005331c4     CMP        EAX,this
    //         005331c6     MOV        dword ptr [ESP + points],this
    //         005331ca     FSTP       float ptr [EDI + 0x14]
    //         005331cd     JL         LAB_00533222
    //                              victory.cpp:1398 (16)
    //         005331cf     MOV        EAX,dword ptr [EBP + 0xc]
    //         005331d2     XOR        this,this
    //         005331d4     MOV        ESI,dword ptr [EAX + 0x3c]
    //         005331d7     MOVSX      ESI,word ptr [ESI + 0x3c]
    //         005331db     TEST       ESI,ESI
    //         005331dd     JLE        LAB_00533208
    //                              victory.cpp:1399 (14)
    //         005331df     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         005331e3     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_005331e7                                                 XREF[1]:     00533206(j)  
    //         005331e7     CMP        this,dword ptr [ESP + param_1]
    //         005331eb     JZ         LAB_00533200
    //                              victory.cpp:1400 (19)
    //         005331ed     MOV        EAX,dword ptr [EDX]
    //         005331ef     FILD       dword ptr [ESP + points]
    //         005331f3     MOV        EAX,dword ptr [EAX + 0x50]
    //         005331f6     FCOMP      float ptr [EAX + EBX*0x1]
    //         005331f9     FNSTSW     AX
    //         005331fb     TEST       AH,0x41
    //         005331fe     JNZ        LAB_0053322c
    //                               LAB_00533200                                                 XREF[1]:     005331eb(j)  
    //                              victory.cpp:1398 (8)
    //         00533200     INC        this
    //         00533201     ADD        EDX,0x4
    //         00533204     CMP        this,ESI
    //         00533206     JL         LAB_005331e7
    //                               LAB_00533208                                                 XREF[1]:     005331dd(j)  
    //                              victory.cpp:1406 (19)
    //         00533208     MOV        EAX,dword ptr [ESP + local_4]
    //         0053320c     MOV        ESI,dword ptr [EDI + 0x10]
    //         0053320f     MOV        EDX,dword ptr [EBP + 0x1c]
    //         00533212     MOV        this,EAX
    //         00533214     SUB        this,ESI
    //         00533216     ADD        EDX,this
    //         00533218     MOV        dword ptr [EBP + 0x1c],EDX
    //                              victory.cpp:1407 (3)
    //         0053321b     MOV        dword ptr [EDI + 0x10],EAX
    //                              victory.cpp:1408 (4)
    //         0053321e     MOV        byte ptr [EDI + 0x1],0x2
    //                               LAB_00533222                                                 XREF[2]:     00533192(j), 005331cd(j)  
    //                              victory.cpp:1411 (10)
    //         00533222     POP        EDI
    //         00533223     POP        ESI
    //         00533224     POP        EBP
    //         00533225     POP        EBX
    //         00533226     ADD        ESP,0x8
    //         00533229     RET        0x4
    //                               LAB_0053322c                                                 XREF[1]:     005331fe(j)  
    //                              victory.cpp:1402 (4)
    //         0053322c     MOV        byte ptr [EDI + 0x1],0x1
    //                              victory.cpp:1411 (10)
    //         00533230     POP        EDI
    //         00533231     POP        ESI
    //         00533232     POP        EBP
    //         00533233     POP        EBX
    //         00533234     ADD        ESP,0x8
    //         00533237     RET        0x4
    //         0053323a     ??         90h
    //         0053323b     NOP
    //         0053323c     NOP
    //         0053323d     NOP
    //         0053323e     NOP
    //         0053323f     NOP
    //                              * protected: void __thiscall RGE_Victory_Conditions::handle_points_highest_attribute(struct RGE_Vict... *
    //                              void __thiscall handle_points_highest_attribute(RGE_Victory_Conditio
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[7]:     00533246(R), 00533270(W), 00533277(R), 0053327b(W), 
    //                                                                                     005332e4(W), 005332f6(W), 005332fe(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00533250(W), 0053330d(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     005332a7(W), 005332e8(R)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     005332b3(W), 005332ba(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     00533284(W), 00533288(R), 005332c9(R), 005332d6(R)  
    //                               ?handle_points_highest_attribute@RGE_Victory_Conditions@@IA  XREF[1]:     handle_point_condition:00531f57(c)
    //                               RGE_Victory_Conditions::handle_points_highest_attribute
    //                              victory.cpp:1415 (6)
    //         00533240     SUB        ESP,0x10
    //         00533243     PUSH       EBX
    //         00533244     PUSH       EBP
    //         00533245     PUSH       ESI
    //                              victory.cpp:1421 (22)
    //         00533246     MOV        ESI,dword ptr [ESP + param_1]
    //         0053324a     PUSH       EDI
    //         0053324b     MOV        EDI,this
    //         0053324d     MOV        AL,byte ptr [ESI + 0x1]
    //         00533250     MOV        dword ptr [ESP + local_4],EDI
    //         00533254     TEST       AL,AL
    //         00533256     JNZ        LAB_0053331c
    //                              victory.cpp:1423 (24)
    //         0053325c     MOV        EAX,dword ptr [EDI + 0xc]
    //         0053325f     MOV        EBX,dword ptr [ESI + 0x4]
    //         00533262     SHL        EBX,0x2
    //         00533265     MOV        this,dword ptr [EAX + 0x50]
    //         00533268     FLD        float ptr [this->_padding_ + EBX*0x1]
    //         0053326b     CALL       __ftol                                           undefined __ftol()
    //         00533270     MOV        dword ptr [ESP + param_1],EAX
    //                              victory.cpp:1425 (11)
    //         00533274     MOV        this,dword ptr [ESI + 0xc]
    //         00533277     FILD       dword ptr [ESP + param_1]
    //         0053327b     MOV        dword ptr [ESP + param_1],this
    //                              victory.cpp:1428 (27)
    //         0053327f     MOV        this,dword ptr [ESI + 0x8]
    //         00533282     CMP        EAX,this
    //         00533284     FSTP       float ptr [ESP + local_10]
    //         00533288     MOV        EDX,dword ptr [ESP + local_10]
    //         0053328c     MOV        dword ptr [ESI + 0x14],EDX
    //         0053328f     MOV        EDI,dword ptr [EDI + 0xc]
    //         00533292     MOV        EDX,dword ptr [EDI + 0x3c]
    //         00533295     MOV        EBP,dword ptr [EDX + 0x40]
    //         00533298     JGE        LAB_0053329e
    //                              victory.cpp:1429 (2)
    //         0053329a     XOR        this,this
    //                              victory.cpp:1430 (2)
    //         0053329c     JMP        LAB_00533302
    //                               LAB_0053329e                                                 XREF[1]:     00533298(j)  
    //                              victory.cpp:1431 (17)
    //         0053329e     MOVSX      EAX,word ptr [EDX + 0x3c]
    //         005332a2     MOV        this,0x1
    //         005332a7     MOV        dword ptr [ESP + local_8],EAX
    //         005332ab     CMP        EAX,this
    //         005332ad     JLE        LAB_005332fe
    //                              victory.cpp:1432 (8)
    //         005332af     MOVSX      EDX,word ptr [EDI + 0x4a]
    //         005332b3     MOV        dword ptr [ESP + local_c],EDX
    //                              victory.cpp:1449 (63)
    //         005332b7     LEA        EDI,[EBP + 0x4]
    //                               LAB_005332ba                                                 XREF[1]:     005332f2(j)  
    //         005332ba     CMP        this,dword ptr [ESP + local_c]
    //         005332be     JZ         LAB_005332e8
    //         005332c0     MOV        EAX,dword ptr [EDI]
    //         005332c2     MOV        EDX,dword ptr [EAX + 0x50]
    //         005332c5     ADD        EDX,EBX
    //         005332c7     FLD        float ptr [EDX]
    //         005332c9     FCOMP      float ptr [ESP + local_10]
    //         005332cd     FNSTSW     AX
    //         005332cf     TEST       AH,0x41
    //         005332d2     JZ         LAB_005332f6
    //         005332d4     FLD        float ptr [EDX]
    //         005332d6     FCOMP      float ptr [ESP + local_10]
    //         005332da     FNSTSW     AX
    //         005332dc     TEST       AH,0x40
    //         005332df     JZ         LAB_005332e8
    //         005332e1     MOV        EAX,dword ptr [ESI + 0x10]
    //         005332e4     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_005332e8                                                 XREF[2]:     005332be(j), 005332df(j)  
    //         005332e8     MOV        EAX,dword ptr [ESP + local_8]
    //         005332ec     INC        this
    //         005332ed     ADD        EDI,0x4
    //         005332f0     CMP        this,EAX
    //         005332f2     JL         LAB_005332ba
    //         005332f4     JMP        LAB_005332fe
    //                               LAB_005332f6                                                 XREF[1]:     005332d2(j)  
    //                              victory.cpp:1436 (12)
    //         005332f6     MOV        dword ptr [ESP + param_1],0x0
    //                               LAB_005332fe                                                 XREF[2]:     005332ad(j), 005332f4(j)  
    //         005332fe     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_00533302                                                 XREF[1]:     0053329c(j)  
    //                              victory.cpp:1443 (7)
    //         00533302     MOV        EAX,dword ptr [ESI + 0x10]
    //         00533305     CMP        this,EAX
    //         00533307     JZ         LAB_0053331c
    //                              victory.cpp:1445 (16)
    //         00533309     MOV        EDX,this
    //         0053330b     SUB        EDX,EAX
    //         0053330d     MOV        EAX,dword ptr [ESP + local_4]
    //         00533311     MOV        EDI,dword ptr [EAX + 0x1c]
    //         00533314     ADD        EDI,EDX
    //         00533316     MOV        dword ptr [EAX + 0x1c],EDI
    //                              victory.cpp:1446 (3)
    //         00533319     MOV        dword ptr [ESI + 0x10],this
    //                               LAB_0053331c                                                 XREF[2]:     00533256(j), 00533307(j)  
    //                              victory.cpp:1449 (10)
    //         0053331c     POP        EDI
    //         0053331d     POP        ESI
    //         0053331e     POP        EBP
    //         0053331f     POP        EBX
    //         00533320     ADD        ESP,0x10
    //         00533323     RET        0x4
    //         00533326     ??         90h
    //         00533327     NOP
    //         00533328     NOP
    //         00533329     NOP
    //         0053332a     NOP
    //         0053332b     NOP
    //         0053332c     NOP
    //         0053332d     NOP
    //         0053332e     NOP
    //         0053332f     NOP
    //                              * protected: void __thiscall RGE_Victory_Conditions::handle_points_high_attribute_once(struct RGE_Vi... *
    //                              void __thiscall handle_points_high_attribute_once(RGE_Victory_Condit
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[4]:     00533335(R), 0053335e(W), 00533362(R), 005333e5(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00533352(W), 00533398(R), 005333ce(W), 005333d2(R)  
    //                               ?handle_points_high_attribute_once@RGE_Victory_Conditions@@  XREF[1]:     handle_point_condition:00531f60(c)
    //                               RGE_Victory_Conditions::handle_points_high_attribute_once
    //                              victory.cpp:1453 (5)
    //         00533330     PUSH       this
    //         00533331     PUSH       EBX
    //         00533332     PUSH       EBP
    //         00533333     PUSH       ESI
    //         00533334     PUSH       EDI
    //                              victory.cpp:1459 (17)
    //         00533335     MOV        EDI,dword ptr [ESP + param_1]
    //         00533339     MOV        EBP,this
    //         0053333b     MOV        AL,byte ptr [EDI + 0x1]
    //         0053333e     TEST       AL,AL
    //         00533340     JNZ        LAB_00533408
    //                              victory.cpp:1461 (28)
    //         00533346     MOV        this,dword ptr [EBP + 0xc]
    //         00533349     MOV        EAX,dword ptr [EDI + 0x4]
    //         0053334c     SHL        EAX,0x2
    //         0053334f     MOV        EDX,dword ptr [this->_padding_ + 0x50]
    //         00533352     MOV        dword ptr [ESP + local_4],EAX
    //         00533356     FLD        float ptr [EDX + EAX*0x1]
    //         00533359     CALL       __ftol                                           undefined __ftol()
    //         0053335e     MOV        dword ptr [ESP + param_1],EAX
    //                              victory.cpp:1462 (14)
    //         00533362     FILD       dword ptr [ESP + param_1]
    //         00533366     FCOM       float ptr [EDI + 0x14]
    //         00533369     FNSTSW     AX
    //         0053336b     TEST       AH,0x41
    //         0053336e     JNZ        LAB_00533375
    //                              victory.cpp:1463 (3)
    //         00533370     FSTP       float ptr [EDI + 0x14]
    //                              victory.cpp:1462 (4)
    //         00533373     JMP        LAB_00533377
    //                               LAB_00533375                                                 XREF[1]:     0053336e(j)  
    //         00533375     FSTP       ST0
    //                               LAB_00533377                                                 XREF[1]:     00533373(j)  
    //                              victory.cpp:1465 (3)
    //         00533377     MOV        EAX,dword ptr [EBP + 0xc]
    //                              victory.cpp:1467 (17)
    //         0053337a     MOV        ESI,0x1
    //         0053337f     MOV        this,dword ptr [EAX + 0x3c]
    //         00533382     CMP        word ptr [this->_padding_ + 0x3c],SI
    //         00533386     MOV        EBX,dword ptr [this->_padding_ + 0x40]
    //         00533389     JLE        LAB_005333cb
    //                              victory.cpp:1465 (3)
    //         0053338b     ADD        EBX,0x4
    //                               LAB_0053338e                                                 XREF[1]:     005333c9(j)  
    //                              victory.cpp:1468 (8)
    //         0053338e     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         00533392     CMP        ESI,EAX
    //         00533394     JZ         LAB_005333b9
    //                              victory.cpp:1469 (25)
    //         00533396     MOV        this,dword ptr [EBX]
    //         00533398     MOV        EAX,dword ptr [ESP + local_4]
    //         0053339c     FILD       dword ptr [EDI + 0x8]
    //         0053339f     MOV        EDX,dword ptr [this->_padding_ + 0x50]
    //         005333a2     FCOMP      float ptr [EDX + EAX*0x1]
    //         005333a5     LEA        this,[EDX + EAX*0x1]
    //         005333a8     FNSTSW     AX
    //         005333aa     TEST       AH,0x41
    //         005333ad     JZ         LAB_005333b9
    //                              victory.cpp:1470 (28)
    //         005333af     FLD        float ptr [this->_padding_]
    //         005333b1     CALL       __ftol                                           undefined __ftol()
    //         005333b6     MOV        dword ptr [EDI + 0x8],EAX
    //                               LAB_005333b9                                                 XREF[2]:     00533394(j), 005333ad(j)  
    //         005333b9     MOV        EAX,dword ptr [EBP + 0xc]
    //         005333bc     INC        ESI
    //         005333bd     ADD        EBX,0x4
    //         005333c0     MOV        this,dword ptr [EAX + 0x3c]
    //         005333c3     MOVSX      EDX,word ptr [this->_padding_ + 0x3c]
    //         005333c7     CMP        ESI,EDX
    //         005333c9     JL         LAB_0053338e
    //                               LAB_005333cb                                                 XREF[1]:     00533389(j)  
    //                              victory.cpp:1472 (21)
    //         005333cb     MOV        this,dword ptr [EDI + 0x8]
    //         005333ce     MOV        dword ptr [ESP + local_4],this
    //         005333d2     FILD       dword ptr [ESP + local_4]
    //         005333d6     FCOMP      float ptr [EDI + 0x14]
    //         005333d9     FNSTSW     AX
    //         005333db     TEST       AH,0x41
    //         005333de     JZ         LAB_005333e5
    //                              victory.cpp:1473 (3)
    //         005333e0     MOV        EAX,dword ptr [EDI + 0xc]
    //                              victory.cpp:1474 (8)
    //         005333e3     JMP        LAB_005333f2
    //                               LAB_005333e5                                                 XREF[1]:     005333de(j)  
    //         005333e5     CMP        dword ptr [ESP + param_1],this
    //         005333e9     JNZ        LAB_005333f0
    //                              victory.cpp:1475 (3)
    //         005333eb     MOV        EAX,dword ptr [EDI + 0x10]
    //                              victory.cpp:1476 (2)
    //         005333ee     JMP        LAB_005333f2
    //                               LAB_005333f0                                                 XREF[1]:     005333e9(j)  
    //                              victory.cpp:1477 (2)
    //         005333f0     XOR        EAX,EAX
    //                               LAB_005333f2                                                 XREF[2]:     005333e3(j), 005333ee(j)  
    //                              victory.cpp:1479 (7)
    //         005333f2     MOV        this,dword ptr [EDI + 0x10]
    //         005333f5     CMP        EAX,this
    //         005333f7     JZ         LAB_00533408
    //                              victory.cpp:1481 (12)
    //         005333f9     MOV        EDX,EAX
    //         005333fb     SUB        EDX,this
    //         005333fd     MOV        this,dword ptr [EBP + 0x1c]
    //         00533400     ADD        this,EDX
    //         00533402     MOV        dword ptr [EBP + 0x1c],this
    //                              victory.cpp:1482 (3)
    //         00533405     MOV        dword ptr [EDI + 0x10],EAX
    //                               LAB_00533408                                                 XREF[2]:     00533340(j), 005333f7(j)  
    //                              victory.cpp:1485 (8)
    //         00533408     POP        EDI
    //         00533409     POP        ESI
    //         0053340a     POP        EBP
    //         0053340b     POP        EBX
    //         0053340c     POP        this
    //         0053340d     RET        0x4
    //                              * protected: void __thiscall RGE_Victory_Conditions::handle_points_high_attribute_amount(struct RGE_... *
    //                              void __thiscall handle_points_high_attribute_amount(RGE_Victory_Cond
    //              void              <VOID>         <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              RGE_Victory_Po    Stack[0x4]:4   param_1                   XREF[3]:     00533411(R), 00533430(W), 00533434(R)  
    //                               ?handle_points_high_attribute_amount@RGE_Victory_Conditions  XREF[1]:     handle_point_condition:00531f69(c)
    //                               RGE_Victory_Conditions::handle_points_high_attribute_amount
    //                              victory.cpp:1489 (1)
    //         00533410     PUSH       ESI
    //                              victory.cpp:1493 (14)
    //         00533411     MOV        ESI,dword ptr [ESP + param_1]
    //         00533415     PUSH       EDI
    //         00533416     MOV        EDI,this
    //         00533418     MOV        AL,byte ptr [ESI + 0x1]
    //         0053341b     TEST       AL,AL
    //         0053341d     JNZ        LAB_0053346e
    //                              victory.cpp:1495 (21)
    //         0053341f     MOV        this,dword ptr [EDI + 0xc]
    //         00533422     MOV        EAX,dword ptr [ESI + 0x4]
    //         00533425     MOV        EDX,dword ptr [this->_padding_ + 0x50]
    //         00533428     FLD        float ptr [EDX + EAX*0x4]
    //         0053342b     CALL       __ftol                                           undefined __ftol()
    //         00533430     MOV        dword ptr [ESP + param_1],EAX
    //                              victory.cpp:1496 (14)
    //         00533434     FILD       dword ptr [ESP + param_1]
    //         00533438     FCOM       float ptr [ESI + 0x14]
    //         0053343b     FNSTSW     AX
    //         0053343d     TEST       AH,0x41
    //         00533440     JNZ        LAB_00533447
    //                              victory.cpp:1497 (3)
    //         00533442     FSTP       float ptr [ESI + 0x14]
    //                              victory.cpp:1496 (4)
    //         00533445     JMP        LAB_00533449
    //                               LAB_00533447                                                 XREF[1]:     00533440(j)  
    //         00533447     FSTP       ST0
    //                               LAB_00533449                                                 XREF[1]:     00533445(j)  
    //                              victory.cpp:1500 (15)
    //         00533449     FILD       dword ptr [ESI + 0x8]
    //         0053344c     FDIVR      float ptr [ESI + 0x14]
    //         0053344f     CALL       __ftol                                           undefined __ftol()
    //         00533454     IMUL       EAX,dword ptr [ESI + 0xc]
    //                              victory.cpp:1501 (7)
    //         00533458     MOV        this,dword ptr [ESI + 0x10]
    //         0053345b     CMP        EAX,this
    //         0053345d     JZ         LAB_0053346e
    //                              victory.cpp:1503 (12)
    //         0053345f     MOV        EDX,EAX
    //         00533461     SUB        EDX,this
    //         00533463     MOV        this,dword ptr [EDI + 0x1c]
    //         00533466     ADD        this,EDX
    //         00533468     MOV        dword ptr [EDI + 0x1c],this
    //                              victory.cpp:1504 (3)
    //         0053346b     MOV        dword ptr [ESI + 0x10],EAX
    //                               LAB_0053346e                                                 XREF[2]:     0053341d(j), 0053345d(j)  
    //                              victory.cpp:1507 (5)
    //         0053346e     POP        EDI
    //         0053346f     POP        ESI
    //         00533470     RET        0x4
    //         00533473     ??         90h
    //         00533474     NOP
    //         00533475     NOP
    //         00533476     NOP
    //         00533477     NOP
    //         00533478     NOP
    //         00533479     NOP
    //         0053347a     NOP
    //         0053347b     NOP
    //         0053347c     NOP
    //         0053347d     NOP
    //         0053347e     NOP
    //         0053347f     NOP
    return;
}

long RGE_Victory_Conditions::get_victory_points() {
    /* TODO: Stub */
    //                              long __thiscall get_victory_points(RGE_Victory_Conditions * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //                               ?get_victory_points@RGE_Victory_Conditions@@QAEJXZ           XREF[14]:    mostHated:0040c555(c), 
    //                               RGE_Victory_Conditions::get_victory_points                                set_mode:0048e744(c), 
    //                                                                                                         reset_score_display:0049b122(c), 
    //                                                                                                         reset_score_display:0049b207(c), 
    //                                                                                                         currentScore:004e6893(c), 
    //                                                                                                         logStatus:0051908f(c), 
    //                                                                                                         draw_score:0051c147(c), 
    //                                                                                                         handle_idle:0051c481(c), 
    //                                                                                                         save_object_info:0051ca55(c), 
    //                                                                                                         load_game:0052653a(c), 
    //                                                                                                         check_game_state:0053048c(c), 
    //                                                                                                         check_game_state:005304ed(c), 
    //                                                                                                         send_zone_score_info:005314a7(c), 
    //                                                                                                         handle_victory_points:005328f4(c)  
    //                              victory.cpp:1511 (3)
    //         00533480     MOV        EAX,dword ptr [ECX + this->tot_victory_points]
    //                              victory.cpp:1513 (1)
    //         00533483     RET
    //         00533484     ??         90h
    //         00533485     NOP
    //         00533486     NOP
    //         00533487     NOP
    //         00533488     NOP
    //         00533489     NOP
    //         0053348a     NOP
    //         0053348b     NOP
    //         0053348c     NOP
    //         0053348d     NOP
    //         0053348e     NOP
    //         0053348f     NOP
    return 0;
}

long RGE_Victory_Conditions::get_victory_points_group(uchar param_1) {
    /* TODO: Stub */
    //                              long __thiscall get_victory_points_group(RGE_Victory_Conditions * th
    //              long              EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00533499(R)  
    //                               ?get_victory_points_group@RGE_Victory_Conditions@@QAEJE@Z    XREF[14]:    set_mode:0048e645(c), 
    //                               RGE_Victory_Conditions::get_victory_points_group                          set_mode:0048e66f(c), 
    //                                                                                                         set_mode:0048e698(c), 
    //                                                                                                         set_mode:0048e6c2(c), 
    //                                                                                                         set_mode:0048e91c(c), 
    //                                                                                                         set_mode:0048eb2f(c), 
    //                                                                                                         set_mode:0048ed5a(c), 
    //                                                                                                         set_mode:0048eeff(c), 
    //                                                                                                         logStatus:00518ffb(c), 
    //                                                                                                         logStatus:00519014(c), 
    //                                                                                                         logStatus:0051902d(c), 
    //                                                                                                         logStatus:00519046(c), 
    //                                                                                                         fill_in_score:00531275(c), 
    //                                                                                                         fill_in_score:00531288(c)  
    //                              victory.cpp:1517 (13)
    //         00533490     MOV        this,dword ptr [ECX + this->victory_point_list]
    //         00533493     XOR        EAX,EAX
    //         00533495     TEST       this,this
    //         00533497     JZ         LAB_005334b1
    //         00533499     MOV        DL,byte ptr [ESP + param_1]
    //                               LAB_0053349d                                                 XREF[1]:     005334af(j)  
    //                              victory.cpp:1522 (10)
    //         0053349d     CMP        byte ptr [ECX + this+0x3],DL
    //         005334a0     JZ         LAB_005334a7
    //         005334a2     CMP        DL,0xff
    //         005334a5     JNZ        LAB_005334aa
    //                               LAB_005334a7                                                 XREF[1]:     005334a0(j)  
    //                              victory.cpp:1523 (10)
    //         005334a7     ADD        EAX,dword ptr [ECX + this->victory]
    //                               LAB_005334aa                                                 XREF[1]:     005334a5(j)  
    //         005334aa     MOV        this,dword ptr [ECX + this->point_list_num]
    //         005334ad     TEST       this,this
    //         005334af     JNZ        LAB_0053349d
    //                               LAB_005334b1                                                 XREF[1]:     00533497(j)  
    //                              victory.cpp:1526 (3)
    //         005334b1     RET        0x4
    //         005334b4     ??         90h
    //         005334b5     NOP
    //         005334b6     NOP
    //         005334b7     NOP
    //         005334b8     NOP
    //         005334b9     NOP
    //         005334ba     NOP
    //         005334bb     NOP
    //         005334bc     NOP
    //         005334bd     NOP
    //         005334be     NOP
    //         005334bf     NOP
    return 0;
}

long RGE_Victory_Conditions::get_victory_points_id(uchar param_1) {
    /* TODO: Stub */
    //                              long __thiscall get_victory_points_id(RGE_Victory_Conditions * this,
    //              long              EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     005334c9(R)  
    //                               ?get_victory_points_id@RGE_Victory_Conditions@@QAEJE@Z       XREF[13]:    set_mode:0048e6e5(c), 
    //                               RGE_Victory_Conditions::get_victory_points_id                             set_mode:0048e712(c), 
    //                                                                                                         set_mode:0048e8e8(c), 
    //                                                                                                         set_mode:0048ea78(c), 
    //                                                                                                         set_mode:0048ead1(c), 
    //                                                                                                         set_mode:0048ec71(c), 
    //                                                                                                         set_mode:0048ed22(c), 
    //                                                                                                         set_mode:0048ed2e(c), 
    //                                                                                                         set_mode:0048ee72(c), 
    //                                                                                                         set_mode:0048ee9e(c), 
    //                                                                                                         set_mode:0048eecb(c), 
    //                                                                                                         logStatus:0051905f(c), 
    //                                                                                                         logStatus:00519078(c)  
    //                              victory.cpp:1530 (13)
    //         005334c0     MOV        this,dword ptr [ECX + this->victory_point_list]
    //         005334c3     XOR        EAX,EAX
    //         005334c5     TEST       this,this
    //         005334c7     JZ         LAB_005334dc
    //         005334c9     MOV        DL,byte ptr [ESP + param_1]
    //                               LAB_005334cd                                                 XREF[1]:     005334da(j)  
    //                              victory.cpp:1535 (5)
    //         005334cd     CMP        byte ptr [ECX + this+0x2],DL
    //         005334d0     JNZ        LAB_005334d5
    //                              victory.cpp:1536 (3)
    //         005334d2     MOV        EAX,dword ptr [ECX + this->victory]
    //                               LAB_005334d5                                                 XREF[1]:     005334d0(j)  
    //                              victory.cpp:1534 (7)
    //         005334d5     MOV        this,dword ptr [ECX + this->point_list_num]
    //         005334d8     TEST       this,this
    //         005334da     JNZ        LAB_005334cd
    //                               LAB_005334dc                                                 XREF[1]:     005334c7(j)  
    //                              victory.cpp:1539 (3)
    //         005334dc     RET        0x4
    //         005334df     ??         90h
    return 0;
}

long RGE_Victory_Conditions::get_attribute_id(uchar param_1) {
    /* TODO: Stub */
    //                              long __thiscall get_attribute_id(RGE_Victory_Conditions * this, ucha
    //              long              EAX:4          <RETURN>
    //              RGE_Victory_Co    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     005334eb(R)  
    //                               ?get_attribute_id@RGE_Victory_Conditions@@QAEJE@Z            XREF[17]:    set_mode:0048e844(c), 
    //                               RGE_Victory_Conditions::get_attribute_id                                  set_mode:0048e86e(c), 
    //                                                                                                         set_mode:0048e8c5(c), 
    //                                                                                                         set_mode:0048ea2b(c), 
    //                                                                                                         set_mode:0048ea55(c), 
    //                                                                                                         set_mode:0048eaa4(c), 
    //                                                                                                         set_mode:0048eb05(c), 
    //                                                                                                         set_mode:0048ec4e(c), 
    //                                                                                                         set_mode:0048eca4(c), 
    //                                                                                                         set_mode:0048ecce(c), 
    //                                                                                                         set_mode:0048ecf8(c), 
    //                                                                                                         set_mode:0048ee4f(c), 
    //                                                                                                         logStatus:005190c2(c), 
    //                                                                                                         logStatus:005190db(c), 
    //                                                                                                         logStatus:005190f4(c), 
    //                                                                                                         logStatus:00519174(c), 
    //                                                                                                         logStatus:0051918d(c)  
    //                              victory.cpp:1543 (1)
    //         005334e0     PUSH       ESI
    //                              victory.cpp:1547 (14)
    //         005334e1     MOV        ESI,dword ptr [ECX + this->victory_point_list]
    //         005334e4     XOR        EAX,EAX
    //         005334e6     TEST       ESI,ESI
    //         005334e8     JZ         LAB_00533504
    //         005334ea     PUSH       EBX
    //         005334eb     MOV        BL,byte ptr [ESP + param_1]
    //                               LAB_005334ef                                                 XREF[1]:     00533501(j)  
    //                              victory.cpp:1548 (5)
    //         005334ef     CMP        byte ptr [ESI + 0x2],BL
    //         005334f2     JNZ        LAB_005334fc
    //                              victory.cpp:1549 (15)
    //         005334f4     FLD        float ptr [ESI + 0x14]
    //         005334f7     CALL       __ftol                                           undefined __ftol()
    //                               LAB_005334fc                                                 XREF[1]:     005334f2(j)  
    //         005334fc     MOV        ESI,dword ptr [ESI + 0x18]
    //         005334ff     TEST       ESI,ESI
    //         00533501     JNZ        LAB_005334ef
    //                              victory.cpp:1543 (1)
    //         00533503     POP        EBX
    //                               LAB_00533504                                                 XREF[1]:     005334e8(j)  
    //                              victory.cpp:1552 (4)
    //         00533504     POP        ESI
    //         00533505     RET        0x4
    //         00533508     ??         90h
    //         00533509     NOP
    //         0053350a     NOP
    //         0053350b     NOP
    //         0053350c     NOP
    //         0053350d     NOP
    //         0053350e     NOP
    //         0053350f     NOP
    return 0;
}

void RGE_Victory_Conditions::handle_point_condition(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Victory_Conditions::handle_condition(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

RGE_Victory_Entry* RGE_Victory_Conditions::add(uchar param_1, uchar param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_capture(uchar param_1, RGE_Static_Object* param_2, uchar param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_create(uchar param_1, long param_2, long param_3, uchar param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_create(uchar param_1, long param_2, long param_3, float param_4, float param_5, float param_6, float param_7, uchar param_8) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_destroy(uchar param_1, RGE_Static_Object* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_destroy(uchar param_1, long param_2, long param_3, RGE_Player* param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_destroy(uchar param_1, long param_2, RGE_Player* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_destroy(uchar param_1, RGE_Player* param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_bring(uchar param_1, RGE_Static_Object* param_2, RGE_Static_Object* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_bring(uchar param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_attributes(uchar param_1, long param_2, long param_3, uchar param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_explore(uchar param_1, long param_2, uchar param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_victory_points(uchar param_1, long param_2, uchar param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::condition_info(long param_1, char** param_2, uchar* param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

char* RGE_Victory_Conditions::condition_description(RGE_Victory_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

RGE_Victory_Point_Entry* RGE_Victory_Conditions::add_point(uchar param_1, uchar param_2) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_points_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_points_attribute_first(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_points_highest_attribute(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_points_high_attribute_once(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

uchar RGE_Victory_Conditions::add_points_high_attribute_amount(uchar param_1, uchar param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void RGE_Victory_Conditions::handle_points_attribute_amount(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Victory_Conditions::handle_points_highest_attribute(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Victory_Conditions::handle_points_high_attribute_once(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

void RGE_Victory_Conditions::handle_points_high_attribute_amount(RGE_Victory_Point_Entry* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

