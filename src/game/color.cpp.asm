#include "common.h"
#include "color.h"

RGE_Color_Table::RGE_Color_Table(int param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0042435b(R)  
    //              char[300]         Stack[-0x130   tempname                  XREF[0,4]:   004243e0(*), 004243f0(R), 004243b3(*), 004243c6(*)  
    //              short             Stack[-0x132   temp_color
    //                               ??0RGE_Color_Table@@QAE@H@Z                                  XREF[1]:     color_table_init:005419a6(c)  
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:162 (11)
    //         00424350     SUB        ESP,0x130
    //         00424356     PUSH       EBX
    //         00424357     PUSH       ESI
    //         00424358     MOV        ESI,this
    //         0042435a     PUSH       EDI
    //                              color.cpp:168 (28)
    //         0042435b     MOV        EDI,dword ptr [ESP + param_1]
    //         00424362     PUSH       0x1e
    //         00424364     LEA        EBX,[ESI + 0x4]
    //         00424367     MOV        dword ptr [ESI],RGE_Color_Table::`vftable'       = 00424420
    //         0042436d     PUSH       EBX
    //         0042436e     PUSH       EDI
    //         0042436f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424374     ADD        ESP,0xc
    //                              color.cpp:169 (15)
    //         00424377     LEA        EAX,[ESI + 0x26]
    //         0042437a     PUSH       0x2
    //         0042437c     PUSH       EAX
    //         0042437d     PUSH       EDI
    //         0042437e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424383     ADD        ESP,0xc
    //                              color.cpp:170 (15)
    //         00424386     LEA        this,[ESI + 0x22]
    //         00424389     PUSH       0x2
    //         0042438b     PUSH       this
    //         0042438c     PUSH       EDI
    //         0042438d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424392     ADD        ESP,0xc
    //                              color.cpp:171 (15)
    //         00424395     LEA        EDX,[ESI + 0x25]
    //         00424398     PUSH       0x1
    //         0042439a     PUSH       EDX
    //         0042439b     PUSH       EDI
    //         0042439c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004243a1     ADD        ESP,0xc
    //                              color.cpp:172 (15)
    //         004243a4     LEA        EAX,[ESI + 0x24]
    //         004243a7     PUSH       0x1
    //         004243a9     PUSH       EAX
    //         004243aa     PUSH       EDI
    //         004243ab     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004243b0     ADD        ESP,0xc
    //                              color.cpp:174 (19)
    //         004243b3     LEA        this=>tempname[4],[ESP + 0x10]
    //         004243b7     PUSH       EBX
    //         004243b8     PUSH       s_data\%s                                        = "data\\%s"
    //         004243bd     PUSH       this
    //         004243be     CALL       sprintf                                          undefined sprintf()
    //         004243c3     ADD        ESP,0xc
    //                              color.cpp:175 (20)
    //         004243c6     LEA        EDX=>tempname[4],[ESP + 0x10]
    //         004243ca     PUSH       s_r                                              = "r"
    //         004243cf     PUSH       EDX
    //         004243d0     CALL       fopen                                            undefined fopen()
    //         004243d5     MOV        EBX,EAX
    //         004243d7     ADD        ESP,0x8
    //                              color.cpp:176 (4)
    //         004243da     TEST       EBX,EBX
    //         004243dc     JZ         LAB_0042440d
    //                              color.cpp:178 (2)
    //         004243de     XOR        EDI,EDI
    //                               LAB_004243e0                                                 XREF[1]:     00424402(j)  
    //                              color.cpp:180 (16)
    //         004243e0     LEA        EAX=>tempname[2],[ESP + 0xe]
    //         004243e4     PUSH       EAX
    //         004243e5     PUSH       s_%hd                                            = "%hd"
    //         004243ea     PUSH       EBX
    //         004243eb     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:181 (20)
    //         004243f0     MOV        this,byte ptr [ESP + tempname[2]]
    //         004243f4     ADD        ESP,0xc
    //         004243f7     MOV        byte ptr [EDI + ESI*0x1 + 0x28],this
    //         004243fb     INC        EDI
    //         004243fc     CMP        EDI,0x100
    //         00424402     JL         LAB_004243e0
    //                              color.cpp:183 (9)
    //         00424404     PUSH       EBX
    //         00424405     CALL       fclose                                           undefined fclose()
    //         0042440a     ADD        ESP,0x4
    //                               LAB_0042440d                                                 XREF[1]:     004243dc(j)  
    //                              color.cpp:186 (14)
    //         0042440d     MOV        EAX,ESI
    //         0042440f     POP        EDI
    //         00424410     POP        ESI
    //         00424411     POP        EBX
    //         00424412     ADD        ESP,0x130
    //         00424418     RET        0x4
    //         0042441b     ??         90h
    //         0042441c     NOP
    //         0042441d     NOP
    //         0042441e     NOP
    //         0042441f     NOP
}

RGE_Color_Table::RGE_Color_Table(TDrawArea* param_1, long param_2, tagPALETTEENTRY* param_3, tagPALETTEENTRY* param_4) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0042435b(R)  
    //              char[300]         Stack[-0x130   tempname                  XREF[0,4]:   004243e0(*), 004243f0(R), 004243b3(*), 004243c6(*)  
    //              short             Stack[-0x132   temp_color
    //                               ??0RGE_Color_Table@@QAE@H@Z                                  XREF[1]:     color_table_init:005419a6(c)  
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:162 (11)
    //         00424350     SUB        ESP,0x130
    //         00424356     PUSH       EBX
    //         00424357     PUSH       ESI
    //         00424358     MOV        ESI,this
    //         0042435a     PUSH       EDI
    //                              color.cpp:168 (28)
    //         0042435b     MOV        EDI,dword ptr [ESP + param_1]
    //         00424362     PUSH       0x1e
    //         00424364     LEA        EBX,[ESI + 0x4]
    //         00424367     MOV        dword ptr [ESI],RGE_Color_Table::`vftable'       = 00424420
    //         0042436d     PUSH       EBX
    //         0042436e     PUSH       EDI
    //         0042436f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424374     ADD        ESP,0xc
    //                              color.cpp:169 (15)
    //         00424377     LEA        EAX,[ESI + 0x26]
    //         0042437a     PUSH       0x2
    //         0042437c     PUSH       EAX
    //         0042437d     PUSH       EDI
    //         0042437e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424383     ADD        ESP,0xc
    //                              color.cpp:170 (15)
    //         00424386     LEA        this,[ESI + 0x22]
    //         00424389     PUSH       0x2
    //         0042438b     PUSH       this
    //         0042438c     PUSH       EDI
    //         0042438d     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         00424392     ADD        ESP,0xc
    //                              color.cpp:171 (15)
    //         00424395     LEA        EDX,[ESI + 0x25]
    //         00424398     PUSH       0x1
    //         0042439a     PUSH       EDX
    //         0042439b     PUSH       EDI
    //         0042439c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004243a1     ADD        ESP,0xc
    //                              color.cpp:172 (15)
    //         004243a4     LEA        EAX,[ESI + 0x24]
    //         004243a7     PUSH       0x1
    //         004243a9     PUSH       EAX
    //         004243aa     PUSH       EDI
    //         004243ab     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004243b0     ADD        ESP,0xc
    //                              color.cpp:174 (19)
    //         004243b3     LEA        this=>tempname[4],[ESP + 0x10]
    //         004243b7     PUSH       EBX
    //         004243b8     PUSH       s_data\%s                                        = "data\\%s"
    //         004243bd     PUSH       this
    //         004243be     CALL       sprintf                                          undefined sprintf()
    //         004243c3     ADD        ESP,0xc
    //                              color.cpp:175 (20)
    //         004243c6     LEA        EDX=>tempname[4],[ESP + 0x10]
    //         004243ca     PUSH       s_r                                              = "r"
    //         004243cf     PUSH       EDX
    //         004243d0     CALL       fopen                                            undefined fopen()
    //         004243d5     MOV        EBX,EAX
    //         004243d7     ADD        ESP,0x8
    //                              color.cpp:176 (4)
    //         004243da     TEST       EBX,EBX
    //         004243dc     JZ         LAB_0042440d
    //                              color.cpp:178 (2)
    //         004243de     XOR        EDI,EDI
    //                               LAB_004243e0                                                 XREF[1]:     00424402(j)  
    //                              color.cpp:180 (16)
    //         004243e0     LEA        EAX=>tempname[2],[ESP + 0xe]
    //         004243e4     PUSH       EAX
    //         004243e5     PUSH       s_%hd                                            = "%hd"
    //         004243ea     PUSH       EBX
    //         004243eb     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:181 (20)
    //         004243f0     MOV        this,byte ptr [ESP + tempname[2]]
    //         004243f4     ADD        ESP,0xc
    //         004243f7     MOV        byte ptr [EDI + ESI*0x1 + 0x28],this
    //         004243fb     INC        EDI
    //         004243fc     CMP        EDI,0x100
    //         00424402     JL         LAB_004243e0
    //                              color.cpp:183 (9)
    //         00424404     PUSH       EBX
    //         00424405     CALL       fclose                                           undefined fclose()
    //         0042440a     ADD        ESP,0x4
    //                               LAB_0042440d                                                 XREF[1]:     004243dc(j)  
    //                              color.cpp:186 (14)
    //         0042440d     MOV        EAX,ESI
    //         0042440f     POP        EDI
    //         00424410     POP        ESI
    //         00424411     POP        EBX
    //         00424412     ADD        ESP,0x130
    //         00424418     RET        0x4
    //         0042441b     ??         90h
    //         0042441c     NOP
    //         0042441d     NOP
    //         0042441e     NOP
    //         0042441f     NOP
}

RGE_Color_Table::RGE_Color_Table(_iobuf* param_1, short param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, _iobuf 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              _iobuf *          Stack[0x4]:4   param_1                   XREF[3]:     00424466(*), 0042446e(*), 0042448f(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[3]:     00424441(R), 00424460(*), 0042448b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0042447e(W), 00424496(*), 004244ac(R)  
    //              char *            Stack[-0x8]:4  file_name
    //                               ??0RGE_Color_Table@@QAE@PAU_iobuf@@F@Z                       XREF[1]:     data_load_color_tables:00541082(c)
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:191 (1)
    //         00424440     PUSH       this
    //                              color.cpp:196 (15)
    //         00424441     MOV        AX,word ptr [ESP + param_2]
    //         00424446     PUSH       EBX
    //         00424447     MOV        EBX,this
    //         00424449     PUSH       EBP
    //         0042444a     PUSH       ESI
    //         0042444b     PUSH       EDI
    //         0042444c     MOV        word ptr [EBX + 0x26],AX
    //                              color.cpp:197 (16)
    //         00424450     MOV        this,0x40
    //         00424455     XOR        EAX,EAX
    //         00424457     LEA        EDI,[EBX + 0x28]
    //         0042445a     MOV        dword ptr [EBX],RGE_Color_Table::`vftable'       = 00424420
    //                              color.cpp:199 (43)
    //         00424460     LEA        EDX=>param_2,[ESP + 0x1c]
    //         00424464     STOSD.REP  ES:EDI
    //         00424466     LEA        this=>param_1,[ESP + 0x18]
    //         0042446a     LEA        EBP,[EBX + 0x4]
    //         0042446d     PUSH       this
    //         0042446e     MOV        this=>param_1,dword ptr [ESP + 0x1c]
    //         00424472     PUSH       EDX
    //         00424473     LEA        EAX,[EBX + 0x22]
    //         00424476     PUSH       EBP
    //         00424477     PUSH       EAX
    //         00424478     PUSH       s_%hd_%s_%hd_%hd                                 = "%hd %s %hd %hd"
    //         0042447d     PUSH       this
    //         0042447e     MOV        dword ptr [ESP + local_4],0x0
    //         00424486     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:201 (4)
    //         0042448b     MOV        DL,byte ptr [ESP + param_2]
    //                              color.cpp:202 (7)
    //         0042448f     MOV        AL,byte ptr [ESP + param_1]
    //         00424493     ADD        ESP,0x18
    //                              color.cpp:204 (22)
    //         00424496     LEA        this=>local_4,[ESP + 0x10]
    //         0042449a     MOV        byte ptr [EBX + 0x25],DL
    //         0042449d     MOV        byte ptr [EBX + 0x24],AL
    //         004244a0     PUSH       s_.col                                           = 2Eh
    //         004244a5     PUSH       EBP
    //         004244a6     PUSH       this
    //         004244a7     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              color.cpp:205 (36)
    //         004244ac     MOV        EDX,dword ptr [ESP + local_4]
    //         004244b0     OR         this,0xffffffff
    //         004244b3     MOV        EDI,EDX
    //         004244b5     XOR        EAX,EAX
    //         004244b7     ADD        ESP,0xc
    //         004244ba     SCASB.RE   ES:EDI
    //         004244bc     NOT        this
    //         004244be     SUB        EDI,this
    //         004244c0     MOV        EAX,this
    //         004244c2     MOV        ESI,EDI
    //         004244c4     MOV        EDI,EBP
    //         004244c6     SHR        this,0x2
    //         004244c9     MOVSD.REP  ES:EDI,ESI
    //         004244cb     MOV        this,EAX
    //         004244cd     AND        this,0x3
    //                              color.cpp:207 (6)
    //         004244d0     TEST       EDX,EDX
    //         004244d2     MOVSB.REP  ES:EDI,ESI
    //         004244d4     JZ         LAB_004244df
    //                              color.cpp:208 (9)
    //         004244d6     PUSH       EDX
    //         004244d7     CALL       free                                             undefined free()
    //         004244dc     ADD        ESP,0x4
    //                               LAB_004244df                                                 XREF[1]:     004244d4(j)  
    //                              color.cpp:209 (10)
    //         004244df     POP        EDI
    //         004244e0     POP        ESI
    //         004244e1     MOV        EAX,EBX
    //         004244e3     POP        EBP
    //         004244e4     POP        EBX
    //         004244e5     POP        this
    //         004244e6     RET        0x8
    //         004244e9     ??         90h
    //         004244ea     NOP
    //         004244eb     NOP
    //         004244ec     NOP
    //         004244ed     NOP
    //         004244ee     NOP
    //         004244ef     NOP
}

RGE_Color_Table::RGE_Color_Table(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, char * 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00424522(R)  
    //              char[300]         Stack[-0x130   tempname                  XREF[4,2]:   00424558(W), 0042455e(R), 004245a8(*), 004245b8(R), 
    //                                                                                     0042457a(*), 0042458e(*)  
    //              short             Stack[-0x134   temp_color
    //                               ??0RGE_Color_Table@@QAE@PAD@Z
    //                               RGE_Color_Table::RGE_Color_Table
    //                              color.cpp:214 (12)
    //         004244f0     SUB        ESP,0x130
    //         004244f6     PUSH       EBX
    //         004244f7     PUSH       EBP
    //         004244f8     MOV        EBP,this
    //         004244fa     PUSH       ESI
    //         004244fb     PUSH       EDI
    //                              color.cpp:223 (33)
    //         004244fc     MOV        this,0x40
    //         00424501     LEA        EBX,[EBP + 0x28]
    //         00424504     XOR        EAX,EAX
    //         00424506     MOV        EDI,EBX
    //         00424508     MOV        dword ptr [EBP],RGE_Color_Table::`vftable'       = 00424420
    //         0042450f     MOV        word ptr [EBP + 0x22],0x0
    //         00424515     MOV        byte ptr [EBP + 0x25],0x0
    //         00424519     MOV        byte ptr [EBP + 0x24],0x0
    //                              color.cpp:225 (34)
    //         0042451d     LEA        EDX,[EBP + 0x4]
    //         00424520     STOSD.REP  ES:EDI
    //         00424522     MOV        EDI,dword ptr [ESP + param_1]
    //         00424529     OR         this,0xffffffff
    //         0042452c     SCASB.RE   ES:EDI
    //         0042452e     NOT        this
    //         00424530     SUB        EDI,this
    //         00424532     MOV        EAX,this
    //         00424534     MOV        ESI,EDI
    //         00424536     MOV        EDI,EDX
    //         00424538     SHR        this,0x2
    //         0042453b     MOVSD.REP  ES:EDI,ESI
    //         0042453d     MOV        this,EAX
    //                              color.cpp:226 (50)
    //         0042453f     XOR        EAX,EAX
    //         00424541     AND        this,0x3
    //         00424544     MOVSB.REP  ES:EDI,ESI
    //         00424546     MOV        EDI,s_.col                                       = 2Eh
    //         0042454b     OR         this,0xffffffff
    //         0042454e     SCASB.RE   ES:EDI=>s_.col                                   = 2Eh
    //                                                                                  = 006c6f63
    //         00424550     NOT        this
    //         00424552     SUB        EDI,this
    //         00424554     MOV        EAX,this
    //         00424556     MOV        ESI,EDI
    //         00424558     MOV        dword ptr [ESP + tempname[0]],EAX
    //         0042455c     MOV        EDI,EDX
    //         0042455e     MOV        EDX,dword ptr [ESP + tempname[0]]
    //         00424562     OR         this,0xffffffff
    //         00424565     XOR        EAX,EAX
    //         00424567     SCASB.RE   ES:EDI
    //         00424569     MOV        this,EDX
    //         0042456b     DEC        EDI
    //         0042456c     SHR        this,0x2
    //         0042456f     MOVSD.REP  ES:EDI,ESI=>s_.col                               = 2Eh
    //                              color.cpp:228 (29)
    //         00424571     LEA        EAX,[EBP + 0x4]
    //         00424574     MOV        this,EDX
    //         00424576     PUSH       EAX
    //         00424577     AND        this,0x3
    //         0042457a     LEA        EAX=>tempname[4],[ESP + 0x18]
    //         0042457e     PUSH       s_data\%s                                        = "data\\%s"
    //         00424583     MOVSB.REP  ES:EDI,ESI=>s_.col                               = 2Eh
    //         00424585     PUSH       EAX
    //         00424586     CALL       sprintf                                          undefined sprintf()
    //         0042458b     ADD        ESP,0xc
    //                              color.cpp:229 (20)
    //         0042458e     LEA        this=>tempname[4],[ESP + 0x14]
    //         00424592     PUSH       s_r                                              = "r"
    //         00424597     PUSH       this
    //         00424598     CALL       fopen                                            undefined fopen()
    //         0042459d     MOV        EDI,EAX
    //         0042459f     ADD        ESP,0x8
    //                              color.cpp:230 (4)
    //         004245a2     TEST       EDI,EDI
    //         004245a4     JZ         LAB_004245d4
    //                              color.cpp:232 (2)
    //         004245a6     XOR        ESI,ESI
    //                               LAB_004245a8                                                 XREF[1]:     004245c9(j)  
    //                              color.cpp:234 (16)
    //         004245a8     LEA        EDX=>tempname,[ESP + 0x10]
    //         004245ac     PUSH       EDX
    //         004245ad     PUSH       s_%hd                                            = "%hd"
    //         004245b2     PUSH       EDI
    //         004245b3     CALL       fscanf                                           undefined fscanf()
    //                              color.cpp:235 (19)
    //         004245b8     MOV        AL,byte ptr [ESP + tempname[0]]
    //         004245bc     ADD        ESP,0xc
    //         004245bf     MOV        byte ptr [ESI + EBX*0x1],AL
    //         004245c2     INC        ESI
    //         004245c3     CMP        ESI,0x100
    //         004245c9     JL         LAB_004245a8
    //                              color.cpp:237 (9)
    //         004245cb     PUSH       EDI
    //         004245cc     CALL       fclose                                           undefined fclose()
    //         004245d1     ADD        ESP,0x4
    //                               LAB_004245d4                                                 XREF[1]:     004245a4(j)  
    //                              color.cpp:239 (15)
    //         004245d4     POP        EDI
    //         004245d5     MOV        EAX,EBP
    //         004245d7     POP        ESI
    //         004245d8     POP        EBP
    //         004245d9     POP        EBX
    //         004245da     ADD        ESP,0x130
    //         004245e0     RET        0x4
    //         004245e3     ??         90h
    //         004245e4     NOP
    //         004245e5     NOP
    //         004245e6     NOP
    //         004245e7     NOP
    //         004245e8     NOP
    //         004245e9     NOP
    //         004245ea     NOP
    //         004245eb     NOP
    //         004245ec     NOP
    //         004245ed     NOP
    //         004245ee     NOP
    //         004245ef     NOP
    //                              * public: __thiscall RGE_Color_Table::RGE_Color_Table(class TDrawArea *,long,struct tagPALETTEENTRY ... *
    //                              undefined __thiscall RGE_Color_Table(RGE_Color_Table * this, TDrawAr
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00424613(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004246b2(R)  
    //              tagPALETTEENTR    Stack[0xc]:4   param_3                   XREF[1]:     00424664(R)  
    //              tagPALETTEENTR    Stack[0x10]:4  param_4                   XREF[1]:     004245f6(R)  
    //              tagPALETTEENTR    Stack[-0x404   temp_palette              XREF[0,5]:   004246c2(*), 004246ef(R), 004246d5(*), 004246f4(*), 
    //                                                                                     00424700(R)  
    //              tagPALETTEENTR    Stack[-0x804   palette                   XREF[2,11]:  00424708(W), 00424725(R), 0042461a(*), 00424626(*), 
    //                                                                                     00424644(W), 004246ca(*), 00424718(R), 0042462a(*), 
    //                                                                                     00424630(*), 0042464a(*), 00424710(*), 0042471b(*), 
    //                                                                                     0042472d(R)  
    //              undefined4        Stack[-0x808   local_808                 XREF[2]:     0042470c(W), 00424735(R)  
    //              undefined4        Stack[-0x80c   local_80c                 XREF[2]:     004246f6(W), 0042471f(R)  
    //              undefined4        Stack[-0x810   local_810                 XREF[3]:     004246e3(W), 0042476f(R), 00424781(W)  
    //              undefined4        Stack[-0x814   local_814                 XREF[3]:     004246df(W), 00424763(R), 0042477d(W)  
    //              long              Stack[-0x818   index1                    XREF[3]:     00424607(W), 00424660(R), 0042475f(R)  
    //              undefined4        Stack[-0x81c   local_81c                 XREF[6,6]:   0042466f(W), 00424686(W), 004246b9(R), 004246fc(W), 
    //                                                                                     0042474f(W), 00424767(R), 00424677(W), 00424694(W), 
    //                                                                                     00424673(W), 0042468d(W), 0042467b(W), 00424698(W)  
    //              long              Stack[-0x820   temp_color
    //                               ??0RGE_Color_Table@@QAE@PAVTDrawArea@@JPAUtagPALETTEENTRY@@  XREF[2]:     set_palette:00467ea4(c), 
    //                               RGE_Color_Table::RGE_Color_Table                                          set_shadow_amount:00468282(c)  
    //                              color.cpp:245 (6)
    //         004245f0     SUB        ESP,0x81c
    //                              color.cpp:259 (29)
    //         004245f6     MOV        EDX,dword ptr [ESP + param_4]
    //         004245fd     PUSH       EBX
    //         004245fe     PUSH       EBP
    //         004245ff     PUSH       ESI
    //         00424600     MOV        ESI,this
    //         00424602     XOR        EBX,EBX
    //         00424604     CMP        EDX,EBX
    //         00424606     PUSH       EDI
    //         00424607     MOV        dword ptr [ESP + index1],ESI
    //         0042460b     MOV        dword ptr [ESI],RGE_Color_Table::`vftable'       = 00424420
    //         00424611     JNZ        LAB_00424626
    //                              color.cpp:260 (17)
    //         00424613     MOV        this,dword ptr [ESP + param_1]
    //         0042461a     LEA        EAX=>palette[1],[ESP + 0x2c]
    //         0042461e     PUSH       EAX
    //         0042461f     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              color.cpp:261 (2)
    //         00424624     JMP        LAB_00424664
    //                               LAB_00424626                                                 XREF[1]:     00424611(j)  
    //                              color.cpp:264 (10)
    //         00424626     LEA        ESI=>palette[1],[ESP + 0x2c]
    //         0042462a     LEA        EDI=>palette[1].peGreen,[ESP + 0x2d]
    //         0042462e     SUB        ESI,EDX
    //                              color.cpp:319 (48)
    //         00424630     LEA        this=>palette[1].peGreen,[ESP + 0x2d]
    //         00424634     LEA        EAX,[EDX + 0x2]
    //         00424637     SUB        EDI,EDX
    //         00424639     MOV        EBP,0x100
    //                               LAB_0042463e                                                 XREF[1]:     0042465e(j)  
    //         0042463e     MOV        DL,byte ptr [EAX + -0x2]
    //         00424641     ADD        EAX,0x4
    //         00424644     MOV        byte ptr [ECX + palette[1].peRed],DL
    //         00424647     MOV        DL,byte ptr [EAX + -0x5]
    //         0042464a     MOV        byte ptr [this->_padding_]=>palette[1].peGreen
    //         0042464c     MOV        DL,byte ptr [EAX + -0x4]
    //         0042464f     MOV        byte ptr [ESI + EAX*0x1 + -0x4],DL
    //         00424653     MOV        DL,byte ptr [EAX + -0x3]
    //         00424656     MOV        byte ptr [EDI + EAX*0x1 + -0x4],DL
    //         0042465a     ADD        this,0x4
    //         0042465d     DEC        EBP
    //         0042465e     JNZ        LAB_0042463e
    //                              color.cpp:262 (4)
    //         00424660     MOV        ESI,dword ptr [ESP + index1]
    //                               LAB_00424664                                                 XREF[1]:     00424624(j)  
    //                              color.cpp:271 (11)
    //         00424664     MOV        EAX,dword ptr [ESP + param_3]
    //         0042466b     CMP        EAX,EBX
    //         0042466d     JNZ        LAB_00424681
    //                              color.cpp:273 (4)
    //         0042466f     MOV        byte ptr [ESP + local_81c],BL
    //                              color.cpp:274 (4)
    //         00424673     MOV        byte ptr [ESP + local_81c+0x2],BL
    //                              color.cpp:275 (4)
    //         00424677     MOV        byte ptr [ESP + local_81c+0x1],BL
    //                              color.cpp:276 (4)
    //         0042467b     MOV        byte ptr [ESP + local_81c+0x3],BL
    //                              color.cpp:278 (2)
    //         0042467f     JMP        LAB_0042469c
    //                               LAB_00424681                                                 XREF[1]:     0042466d(j)  
    //                              color.cpp:280 (2)
    //         00424681     MOV        this,byte ptr [EAX]
    //                              color.cpp:281 (7)
    //         00424683     MOV        DL,byte ptr [EAX + 0x2]
    //         00424686     MOV        byte ptr [ESP + local_81c],this
    //                              color.cpp:282 (7)
    //         0042468a     MOV        this,byte ptr [EAX + 0x1]
    //         0042468d     MOV        byte ptr [ESP + local_81c+0x2],DL
    //                              color.cpp:283 (11)
    //         00424691     MOV        DL,byte ptr [EAX + 0x3]
    //         00424694     MOV        byte ptr [ESP + local_81c+0x1],this
    //         00424698     MOV        byte ptr [ESP + local_81c+0x3],DL
    //                               LAB_0042469c                                                 XREF[1]:     0042467f(j)  
    //                              color.cpp:289 (22)
    //         0042469c     LEA        EDI,[ESI + 0x28]
    //         0042469f     MOV        this,0x40
    //         004246a4     XOR        EAX,EAX
    //         004246a6     MOV        word ptr [ESI + 0x22],BX
    //         004246aa     MOV        byte ptr [ESI + 0x25],BL
    //         004246ad     MOV        byte ptr [ESI + 0x24],BL
    //         004246b0     STOSD.REP  ES:EDI
    //                              color.cpp:292 (45)
    //         004246b2     MOV        EAX,dword ptr [ESP + param_2]
    //         004246b9     MOV        this,dword ptr [ESP + local_81c]
    //         004246bd     PUSH       -0x1
    //         004246bf     PUSH       -0x1
    //         004246c1     PUSH       EAX
    //         004246c2     LEA        EDX=>temp_palette[1],[ESP + 0x438]
    //         004246c9     PUSH       this
    //         004246ca     LEA        EAX=>palette[1],[ESP + 0x3c]
    //         004246ce     PUSH       EDX
    //         004246cf     PUSH       EAX
    //         004246d0     CALL       RGE_translate_palette                            void RGE_translate_palette(tagPALETTEENTRY * 
    //         004246d5     LEA        this=>temp_palette[1].peGreen,[ESP + 0x445]
    //         004246dc     ADD        ESP,0x18
    //                              color.cpp:295 (10)
    //         004246df     MOV        dword ptr [ESP + local_814],EBX
    //         004246e3     MOV        dword ptr [ESP + local_810],this
    //         004246e7     JMP        LAB_004246eb
    //                               LAB_004246e9                                                 XREF[1]:     00424785(j)  
    //                              color.cpp:286 (2)
    //         004246e9     XOR        EBX,EBX
    //                               LAB_004246eb                                                 XREF[1]:     004246e7(j)  
    //                              color.cpp:301 (7)
    //         004246eb     XOR        EDX,EDX
    //         004246ed     XOR        EBP,EBP
    //         004246ef     MOV        DL,byte ptr [ECX + temp_palette[1].peRed]
    //                              color.cpp:302 (8)
    //         004246f2     XOR        EAX,EAX
    //         004246f4     MOV        AL,byte ptr [this->_padding_]=>temp_palette[1]
    //         004246f6     MOV        dword ptr [ESP + local_80c],EDX
    //                              color.cpp:303 (54)
    //         004246fa     XOR        EDX,EDX
    //         004246fc     MOV        dword ptr [ESP + local_81c],EBX
    //         00424700     MOV        DL,byte ptr [ECX + temp_palette[1].peBlue]
    //         00424703     MOV        EDI,0x4e20
    //         00424708     MOV        dword ptr [ESP + palette[0].peRed],EAX
    //         0042470c     MOV        dword ptr [ESP + local_808],EDX
    //         00424710     LEA        ESI=>palette[1].peGreen,[ESP + 0x2d]
    //                               LAB_00424714                                                 XREF[1]:     0042475d(j)  
    //         00424714     XOR        EAX,EAX
    //         00424716     XOR        EDX,EDX
    //         00424718     MOV        AL,byte ptr [ESI + palette[1].peRed]
    //         0042471b     MOV        DL,byte ptr [ESI]=>palette[1].peGreen
    //         0042471d     MOV        this,EAX
    //         0042471f     MOV        EAX,dword ptr [ESP + local_80c]
    //         00424723     SUB        EAX,this
    //         00424725     MOV        this,dword ptr [ESP + palette[0].peRed]
    //         00424729     SUB        this,EDX
    //         0042472b     XOR        EDX,EDX
    //         0042472d     MOV        DL,byte ptr [ESI + palette[1].peBlue]
    //                              color.cpp:310 (25)
    //         00424730     IMUL       EAX,EAX
    //         00424733     MOV        EBX,EDX
    //         00424735     MOV        EDX,dword ptr [ESP + local_808]
    //         00424739     SUB        EDX,EBX
    //         0042473b     MOV        EBX,this
    //         0042473d     IMUL       EBX,this
    //         00424740     MOV        this,EDX
    //         00424742     ADD        EAX,EBX
    //         00424744     IMUL       this,EDX
    //         00424747     ADD        EAX,this
    //                              color.cpp:311 (4)
    //         00424749     CMP        EAX,EDI
    //         0042474b     JGE        LAB_00424753
    //                              color.cpp:313 (2)
    //         0042474d     MOV        EDI,EAX
    //                              color.cpp:314 (16)
    //         0042474f     MOV        dword ptr [ESP + local_81c],EBP
    //                               LAB_00424753                                                 XREF[1]:     0042474b(j)  
    //         00424753     INC        EBP
    //         00424754     ADD        ESI,0x4
    //         00424757     CMP        EBP,0xff
    //         0042475d     JLE        LAB_00424714
    //                              color.cpp:317 (44)
    //         0042475f     MOV        EAX,dword ptr [ESP + index1]
    //         00424763     MOV        EDX,dword ptr [ESP + local_814]
    //         00424767     MOV        this,byte ptr [ESP + local_81c]
    //         0042476b     MOV        byte ptr [EDX + EAX*0x1 + 0x28],this
    //         0042476f     MOV        this,dword ptr [ESP + local_810]
    //         00424773     INC        EDX
    //         00424774     ADD        this,0x4
    //         00424777     CMP        EDX,0xff
    //         0042477d     MOV        dword ptr [ESP + local_814],EDX
    //         00424781     MOV        dword ptr [ESP + local_810],this
    //         00424785     JLE        LAB_004246e9
    //                              color.cpp:319 (13)
    //         0042478b     POP        EDI
    //         0042478c     POP        ESI
    //         0042478d     POP        EBP
    //         0042478e     POP        EBX
    //         0042478f     ADD        ESP,0x81c
    //         00424795     RET        0x10
    //         00424798     ??         90h
    //         00424799     NOP
    //         0042479a     NOP
    //         0042479b     NOP
    //         0042479c     NOP
    //         0042479d     NOP
    //         0042479e     NOP
    //         0042479f     NOP
}

RGE_Color_Table::~RGE_Color_Table() {
    /* TODO: Stub */
    //                              void __thiscall ~RGE_Color_Table(RGE_Color_Table * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //                               ??1RGE_Color_Table@@UAE@XZ                                   XREF[1]:     `scalar_deleting_destructor':00424
    //                               RGE_Color_Table::~RGE_Color_Table
    //                              color.cpp:323 (6)
    //         004247a0     MOV        dword ptr [this->_padding_],RGE_Color_Table::`   = 00424420
    //                              color.cpp:324 (1)
    //         004247a6     RET
    //         004247a7     ??         90h
    //         004247a8     NOP
    //         004247a9     NOP
    //         004247aa     NOP
    //         004247ab     NOP
    //         004247ac     NOP
    //         004247ad     NOP
    //         004247ae     NOP
    //         004247af     NOP
}

void RGE_Color_Table::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(RGE_Color_Table * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Color_Tabl    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004247b4(R)  
    //                               ?save@RGE_Color_Table@@QAEXH@Z                               XREF[1]:     base_save:005438f6(c)  
    //                               RGE_Color_Table::save
    //                              color.cpp:329 (4)
    //         004247b0     PUSH       ESI
    //         004247b1     MOV        ESI,this
    //         004247b3     PUSH       EDI
    //                              color.cpp:330 (19)
    //         004247b4     MOV        EDI,dword ptr [ESP + param_1]
    //         004247b8     LEA        EAX,[ESI + 0x4]
    //         004247bb     PUSH       0x1e
    //         004247bd     PUSH       EAX
    //         004247be     PUSH       EDI
    //         004247bf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247c4     ADD        ESP,0xc
    //                              color.cpp:331 (15)
    //         004247c7     LEA        this,[ESI + 0x26]
    //         004247ca     PUSH       0x2
    //         004247cc     PUSH       this
    //         004247cd     PUSH       EDI
    //         004247ce     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247d3     ADD        ESP,0xc
    //                              color.cpp:332 (15)
    //         004247d6     LEA        EDX,[ESI + 0x22]
    //         004247d9     PUSH       0x2
    //         004247db     PUSH       EDX
    //         004247dc     PUSH       EDI
    //         004247dd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247e2     ADD        ESP,0xc
    //                              color.cpp:333 (15)
    //         004247e5     LEA        EAX,[ESI + 0x25]
    //         004247e8     PUSH       0x1
    //         004247ea     PUSH       EAX
    //         004247eb     PUSH       EDI
    //         004247ec     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004247f1     ADD        ESP,0xc
    //                              color.cpp:334 (15)
    //         004247f4     ADD        ESI,0x24
    //         004247f7     PUSH       0x1
    //         004247f9     PUSH       ESI
    //         004247fa     PUSH       EDI
    //         004247fb     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         00424800     ADD        ESP,0xc
    //                              color.cpp:335 (5)
    //         00424803     POP        EDI
    //         00424804     POP        ESI
    //         00424805     RET        0x4
    //         00424808     ??         90h
    //         00424809     NOP
    //         0042480a     NOP
    //         0042480b     NOP
    //         0042480c     NOP
    //         0042480d     NOP
    //         0042480e     NOP
    //         0042480f     NOP
    //                              * void __cdecl color_log(unsigned char,unsigned char,int)                                               *
    //                              void __cdecl color_log(uchar param_1, uchar param_2, int param_3)
    //              void              <VOID>         <RETURN>
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004248c0(R)  
    //              uchar             Stack[0x8]:1   param_2
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0042485b(R)  
    //              _DDBLTFX          Stack[-0x68]   ddbltfx                   XREF[1,3]:   0042489b(W), 004248e0(*), 004248ec(W), 004248f0(W)  
    //              tagPOINT          Stack[-0x70]:8 point                     XREF[1,2]:   00424883(W), 0042488e(W), 004248ac(*)  
    //              tagRECT           Stack[-0x80]   back_dest                 XREF[1,3]:   004248e8(W), 0042488a(W), 00424879(W), 00424895(W)  
    //              tagRECT           Stack[-0x90]   scr_dest                  XREF[0,3]:   004248c7(W), 004248cb(W), 004248e4(W)  
    //                               ?color_log@@YAXEEH@Z                                         XREF[133]:   handle_idle:00420f80(c), 
    //                               color_log                                                                 handle_idle:00421004(c), 
    //                                                                                                         handle_idle:0042101c(c), 
    //                                                                                                         handle_idle:0042104d(c), 
    //                                                                                                         handle_idle:00421081(c), 
    //                                                                                                         handle_idle:0042109a(c), 
    //                                                                                                         handle_idle:004210b2(c), 
    //                                                                                                         handle_idle:004210d4(c), 
    //                                                                                                         handle_idle:004210ec(c), 
    //                                                                                                         handle_idle:004210fa(c), 
    //                                                                                                         TShape:004b8b90(c), 
    //                                                                                                         TShape:004b8d28(c), 
    //                                                                                                         load:004bcd97(c), 
    //                                                                                                         load:004bd296(c), 
    //                                                                                                         load:004bd2dc(c), 
    //                                                                                                         handle_idle:0052967a(c), 
    //                                                                                                         handle_idle:00529688(c), 
    //                                                                                                         handle_idle:005297c7(c), 
    //                                                                                                         handle_idle:005297df(c), 
    //                                                                                                         handle_idle:0052992c(c), [more]
    //                              Colorlog.cpp:13 (21)
    //         00424810     MOV        AL,[do_color_log]                                = 00h
    //         00424815     SUB        ESP,0x8c
    //         0042481b     TEST       AL,AL
    //         0042481d     PUSH       EBX
    //         0042481e     PUSH       ESI
    //         0042481f     JZ         LAB_004249c1
    //                              Colorlog.cpp:19 (32)
    //         00424825     MOV        EAX,[rge_base_game]                              = 00000000
    //         0042482a     TEST       EAX,EAX
    //         0042482c     JZ         LAB_004249c1
    //         00424832     MOV        ECX,dword ptr [EAX + 0x1b0]
    //         00424838     MOV        EBX,0x2
    //         0042483d     CMP        ECX,EBX
    //         0042483f     JL         LAB_004249c1
    //                              Colorlog.cpp:21 (3)
    //         00424845     MOV        ESI,dword ptr [EAX + 0x48]
    //                              Colorlog.cpp:22 (19)
    //         00424848     TEST       ESI,ESI
    //         0042484a     JZ         LAB_004249c1
    //         00424850     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00424853     TEST       EAX,EAX
    //         00424855     JZ         LAB_004249c1
    //                              Colorlog.cpp:30 (16)
    //         0042485b     MOV        ECX,dword ptr [ESP + param_3]
    //         00424862     MOV        EDX,dword ptr [ESI + 0xc]
    //         00424865     MOV        EAX,EBX
    //         00424867     PUSH       EDI
    //         00424868     SUB        EAX,ECX
    //         0042486a     PUSH       EBP
    //                              Colorlog.cpp:33 (35)
    //         0042486b     MOV        EBP,0xa
    //         00424870     LEA        ECX,[EAX + EAX*0x4]
    //         00424873     MOV        EAX,dword ptr [EDX + 0x18]
    //         00424876     CDQ
    //         00424877     SUB        EAX,EDX
    //         00424879     MOV        dword ptr [ESP + back_dest.right],0x0
    //         00424881     SAR        EAX,0x1
    //         00424883     MOV        dword ptr [ESP + point.x],EBP
    //         00424887     LEA        ECX,[EAX + ECX*0x4]
    //         0042488a     MOV        dword ptr [ESP + back_dest.top],ECX
    //                              Colorlog.cpp:36 (11)
    //         0042488e     MOV        dword ptr [ESP + point.y],ECX
    //         00424892     LEA        EAX,[ECX + 0xa]
    //         00424895     MOV        dword ptr [ESP + back_dest.bottom],EAX
    //                              Colorlog.cpp:37 (6)
    //         00424899     XOR        EAX,EAX
    //         0042489b     MOV        dword ptr [ESP + ddbltfx.dwSize],EAX
    //                              Colorlog.cpp:38 (10)
    //         0042489f     MOV        DL,byte ptr [ESI + 0x479]
    //         004248a5     CMP        DL,BL
    //         004248a7     JNZ        LAB_004248c0
    //                              Colorlog.cpp:39 (23)
    //         004248a9     MOV        EDX,dword ptr [ESI + 0x4]
    //         004248ac     LEA        ECX=>point.y,[ESP + 0x30]
    //         004248b0     PUSH       ECX
    //         004248b1     PUSH       EDX
    //         004248b2     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
    //         004248b8     MOV        EAX,dword ptr [ESP + 0x34]
    //         004248bc     MOV        ECX,dword ptr [ESP + 0x30]
    //                               LAB_004248c0                                                 XREF[1]:     004248a7(j)  
    //                              Colorlog.cpp:47 (32)
    //         004248c0     MOV        EDI,dword ptr [ESP + param_1]
    //         004248c7     MOV        dword ptr [ESP + scr_dest.top],ECX
    //         004248cb     MOV        dword ptr [ESP + scr_dest.right],EAX
    //         004248cf     ADD        ECX,0xa
    //         004248d2     ADD        EAX,0xa
    //         004248d5     MOV        EBX,0x64
    //         004248da     AND        EDI,0xff
    //                              Colorlog.cpp:48 (47)
    //         004248e0     LEA        EDX=>ddbltfx.dwDDFX,[ESP + 0x38]
    //         004248e4     MOV        dword ptr [ESP + scr_dest.bottom],ECX
    //         004248e8     MOV        dword ptr [ESP + back_dest.left],EAX
    //         004248ec     MOV        dword ptr [ESP + ddbltfx.dwDDFX],EBX
    //         004248f0     MOV        dword ptr [ESP + ddbltfx.ddckDestColorkey.dwCo
    //         004248f7     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004248fa     PUSH       EDX
    //         004248fb     PUSH       0x1000400
    //         00424900     PUSH       0x0
    //         00424902     MOV        ECX,dword ptr [EAX]
    //         00424904     LEA        EDX,[ESP + 0x1c]
    //         00424908     PUSH       0x0
    //         0042490a     PUSH       EDX
    //         0042490b     PUSH       EAX
    //         0042490c     CALL       dword ptr [ECX + 0x14]
    //                              Colorlog.cpp:50 (4)
    //         0042490f     MOV        dword ptr [ESP + 0x38],EBX
    //                              Colorlog.cpp:51 (7)
    //         00424913     MOV        dword ptr [ESP + 0x88],EDI
    //                              Colorlog.cpp:52 (31)
    //         0042491a     MOV        EAX,dword ptr [ESI + 0xc]
    //         0042491d     LEA        EDX,[ESP + 0x38]
    //         00424921     PUSH       EDX
    //         00424922     PUSH       offset DAT_fffffff8
    //         00424927     MOV        EAX,dword ptr [EAX + 0x3c]
    //         0042492a     PUSH       0x0=>DAT_fffffff4
    //         0042492c     LEA        EDX,[ESP + 0x2c]
    //         00424930     PUSH       0x0=>DAT_fffffff0
    //         00424932     MOV        ECX,dword ptr [EAX]
    //         00424934     PUSH       EDX
    //         00424935     PUSH       EAX
    //         00424936     CALL       dword ptr [ECX + 0x14]
    //                              Colorlog.cpp:56 (4)
    //         00424939     MOV        EDI,dword ptr [ESP + 0x2c]
    //                              Colorlog.cpp:58 (8)
    //         0042493d     MOV        EDX,dword ptr [ESP + 0x14]
    //         00424941     MOV        EAX,dword ptr [ESP + 0x24]
    //                              Colorlog.cpp:59 (12)
    //         00424945     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00424949     ADD        EDI,EBP
    //         0042494b     ADD        EDX,EBP
    //         0042494d     MOV        dword ptr [ESP + 0x2c],EDI
    //                              Colorlog.cpp:62 (21)
    //         00424951     MOV        EDI,dword ptr [ESP + 0xa4]
    //         00424958     MOV        dword ptr [ESP + 0x14],EDX
    //         0042495c     ADD        EAX,EBP
    //         0042495e     ADD        ECX,EBP
    //         00424960     AND        EDI,0xff
    //                              Colorlog.cpp:63 (47)
    //         00424966     LEA        EDX,[ESP + 0x38]
    //         0042496a     MOV        dword ptr [ESP + 0x24],EAX
    //         0042496e     MOV        dword ptr [ESP + 0x1c],ECX
    //         00424972     MOV        dword ptr [ESP + 0x38],EBX
    //         00424976     MOV        dword ptr [ESP + 0x88],EDI
    //         0042497d     MOV        EAX,dword ptr [ESI + 0x1c]
    //         00424980     PUSH       EDX
    //         00424981     PUSH       offset DAT_fffffff8
    //         00424986     MOV        ECX,dword ptr [EAX]
    //         00424988     PUSH       0x0=>DAT_fffffff4
    //         0042498a     LEA        EDX,[ESP + 0x1c]
    //         0042498e     PUSH       0x0=>DAT_fffffff0
    //         00424990     PUSH       EDX
    //         00424991     PUSH       EAX
    //         00424992     CALL       dword ptr [ECX + 0x14]
    //                              Colorlog.cpp:65 (4)
    //         00424995     MOV        dword ptr [ESP + 0x38],EBX
    //                              Colorlog.cpp:66 (7)
    //         00424999     MOV        dword ptr [ESP + 0x88],EDI
    //                              Colorlog.cpp:67 (33)
    //         004249a0     MOV        EAX,dword ptr [ESI + 0xc]
    //         004249a3     LEA        EDX,[ESP + 0x38]
    //         004249a7     PUSH       EDX
    //         004249a8     PUSH       offset DAT_fffffff8
    //         004249ad     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004249b0     PUSH       0x0=>DAT_fffffff4
    //         004249b2     LEA        EDX,[ESP + 0x2c]
    //         004249b6     PUSH       0x0=>DAT_fffffff0
    //         004249b8     MOV        ECX,dword ptr [EAX]
    //         004249ba     PUSH       EDX
    //         004249bb     PUSH       EAX
    //         004249bc     CALL       dword ptr [ECX + 0x14]
    //         004249bf     POP        EBP
    //         004249c0     POP        EDI
    //                               LAB_004249c1                                                 XREF[5]:     0042481f(j), 0042482c(j), 
    //                                                                                                         0042483f(j), 0042484a(j), 
    //                                                                                                         00424855(j)  
    //                              Colorlog.cpp:68 (9)
    //         004249c1     POP        ESI
    //         004249c2     POP        EBX
    //         004249c3     ADD        ESP,0x8c
    //         004249c9     RET
    //         004249ca     ??         90h
    //         004249cb     NOP
    //         004249cc     NOP
    //         004249cd     NOP
    //         004249ce     NOP
    //         004249cf     NOP
    //                              * public: __thiscall RGE_Communications_Addresses::RGE_Communications_Addresses(class TCommunication... *
    //                              undefined __thiscall RGE_Communications_Addresses(RGE_Communications
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Communicat    ECX:4 (auto)   this
    //              TCommunication    Stack[0x4]:4   param_1                   XREF[1]:     004249de(R)  
    //                               ??0RGE_Communications_Addresses@@QAE@PAVTCommunications_Han  XREF[1]:     showNetInfo:004a295e(c)  
    //                               RGE_Communications_Addresses::RGE_Communications_Addresses
    //                              com_addr.cpp:8 (14)
    //         004249d0     MOV        EAX,FS:[0x0]
    //         004249d6     PUSH       -0x1
    //         004249d8     PUSH       FUN_0055cc5b
    //         004249dd     PUSH       EAX
    //                              com_addr.cpp:14 (18)
    //         004249de     MOV        EAX,dword ptr [ESP + param_1]
    //         004249e2     MOV        dword ptr FS:[0x0],ESP
    //         004249e9     PUSH       EBX
    //         004249ea     PUSH       ESI
    //         004249eb     MOV        ESI,this
    //         004249ed     PUSH       EDI
    //         004249ee     MOV        dword ptr [ESI],EAX
    //                              com_addr.cpp:15 (5)
    //         004249f0     CALL       RGE_Communications_Addresses::EraseInformation   void EraseInformation(RGE_Communications_Addr
    //                              com_addr.cpp:16 (14)
    //         004249f5     LEA        this,[ESI + 0x4]
    //         004249f8     PUSH       this
    //         004249f9     PUSH       0x101
    //         004249fe     CALL       _WSAStartup@8                                    undefined _WSAStartup@8()
    //                              com_addr.cpp:18 (67)
    //         00424a03     PUSH       0x504
    //         00424a08     MOV        EBX,EAX
    //         00424a0a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00424a0f     ADD        ESP,0x4
    //         00424a12     MOV        dword ptr [ESP + 0x1c],EAX
    //         00424a16     TEST       EAX,EAX
    //         00424a18     MOV        dword ptr [ESP + 0x14],0x0
    //         00424a20     JZ         LAB_00424a44
    //         00424a22     PUSH       IPAD::~IPAD
    //         00424a27     PUSH       IPAD::IPAD
    //         00424a2c     LEA        EDI,[EAX + 0x4]
    //         00424a2f     PUSH       offset DAT_fffffff4
    //         00424a31     PUSH       offset DAT_fffffff0
    //         00424a36     PUSH       EDI
    //         00424a37     MOV        dword ptr [EAX],0x8
    //         00424a3d     CALL       `eh_vector_constructor_iterator'                 void `eh_vector_constructor_iterator'(void * 
    //         00424a42     JMP        LAB_00424a46
    //                               LAB_00424a44                                                 XREF[1]:     00424a20(j)  
    //         00424a44     XOR        EDI,EDI
    //                               LAB_00424a46                                                 XREF[1]:     00424a42(j)  
    //                              com_addr.cpp:20 (18)
    //         00424a46     TEST       EBX,EBX
    //         00424a48     MOV        dword ptr [ESP + 0x14],0xffffffff
    //         00424a50     MOV        dword ptr [ESI + 0x220],EDI
    //         00424a56     JZ         LAB_00424a64
    //                              com_addr.cpp:46 (10)
    //         00424a58     MOV        dword ptr [ESI + 0x214],0x0
    //                              com_addr.cpp:51 (2)
    //         00424a62     JMP        LAB_00424a9d
    //                               LAB_00424a64                                                 XREF[1]:     00424a56(j)  
    //                              com_addr.cpp:60 (17)
    //         00424a64     MOV        this,ESI
    //         00424a66     MOV        dword ptr [ESI + 0x214],0x1
    //         00424a70     CALL       RGE_Communications_Addresses::GetHostName        char * GetHostName(RGE_Communications_Address
    //                              com_addr.cpp:65 (15)
    //         00424a75     PUSH       0xff
    //         00424a7a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00424a7f     ADD        ESP,0x4
    //         00424a82     MOV        EDI,EAX
    //                              com_addr.cpp:68 (8)
    //         00424a84     MOV        this,ESI
    //         00424a86     PUSH       EDI
    //         00424a87     CALL       RGE_Communications_Addresses::SetIPAddresses     int SetIPAddresses(RGE_Communications_Address
    //                              com_addr.cpp:73 (8)
    //         00424a8c     PUSH       EDI
    //         00424a8d     MOV        this,ESI
    //         00424a8f     CALL       RGE_Communications_Addresses::SetIPAliases       int SetIPAliases(RGE_Communications_Addresses
    //                              com_addr.cpp:77 (9)
    //         00424a94     PUSH       EDI
    //         00424a95     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00424a9a     ADD        ESP,0x4
    //                               LAB_00424a9d                                                 XREF[1]:     00424a62(j)  
    //                              com_addr.cpp:79 (22)
    //         00424a9d     MOV        this,dword ptr [ESP + 0xc]
    //         00424aa1     MOV        EAX,ESI
    //         00424aa3     POP        EDI
    //         00424aa4     POP        ESI
    //         00424aa5     MOV        dword ptr FS:[0x0],this
    //         00424aac     POP        EBX
    //         00424aad     ADD        ESP,0xc
    //         00424ab0     RET        0x4
    //         00424ab3     ??         90h
    //         00424ab4     NOP
    //         00424ab5     NOP
    //         00424ab6     NOP
    //         00424ab7     NOP
    //         00424ab8     NOP
    //         00424ab9     NOP
    //         00424aba     NOP
    //         00424abb     NOP
    //         00424abc     NOP
    //         00424abd     NOP
    //         00424abe     NOP
    //         00424abf     NOP
    return;
}

