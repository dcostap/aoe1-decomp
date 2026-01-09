#include "common.h"
#include "dstring.h"

DString::DString() {
    /* TODO: Stub */
    //                              undefined __thiscall DString(DString * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ??0DString@@QAE@XZ
    //                               DString::DString
    //                              dstring.cpp:31 (7)
    //         004465d0     PUSH       EBX
    //         004465d1     PUSH       ESI
    //         004465d2     MOV        EBX,this
    //         004465d4     PUSH       EDI
    //         004465d5     XOR        EAX,EAX
    //                              dstring.cpp:32 (27)
    //         004465d7     PUSH       0x1
    //         004465d9     MOV        dword ptr [EBX],EAX
    //         004465db     MOV        dword ptr [EBX + 0x4],EAX
    //         004465de     MOV        dword ptr [EBX + 0x8],0xffffffff
    //         004465e5     MOV        dword ptr [EBX + 0xc],EAX
    //         004465e8     MOV        dword ptr [EBX + 0x10],EAX
    //         004465eb     CALL       malloc                                           undefined malloc()
    //         004465f0     MOV        EDX,EAX
    //                              dstring.cpp:33 (34)
    //         004465f2     MOV        EDI,s_                                           = ""
    //         004465f7     OR         this,0xffffffff
    //         004465fa     XOR        EAX,EAX
    //         004465fc     ADD        ESP,0x4
    //         004465ff     MOV        dword ptr [EBX],EDX
    //         00446601     SCASB.RE   ES:EDI=>s_                                       = ""
    //         00446603     NOT        this
    //         00446605     SUB        EDI,this
    //         00446607     MOV        EAX,this
    //         00446609     MOV        ESI,EDI
    //         0044660b     MOV        EDI,EDX
    //         0044660d     SHR        this,0x2
    //         00446610     MOVSD.REP  ES:EDI,ESI
    //         00446612     MOV        this,EAX
    //                              dstring.cpp:35 (11)
    //         00446614     MOV        EAX,EBX
    //         00446616     AND        this,0x3
    //         00446619     MOVSB.REP  ES:EDI,ESI
    //         0044661b     POP        EDI
    //         0044661c     POP        ESI
    //         0044661d     POP        EBX
    //         0044661e     RET
    //         0044661f     ??         90h
}

DString::DString(DString* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall DString(DString * this, DString * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446622(R)  
    //                               ??0DString@@QAE@ABV0@@Z                                      XREF[14]:    operator+:00446ca6(c), 
    //                               DString::DString                                                          operator+:00446cc1(c), 
    //                                                                                                         operator+:00446cda(c), 
    //                                                                                                         word:00446f8e(c), 
    //                                                                                                         nextWord:00447081(c), 
    //                                                                                                         subString:004471bc(c), 
    //                                                                                                         stripTrailing:00447348(c), 
    //                                                                                                         stripLeading:004473e6(c), 
    //                                                                                                         asUppercase:004474a9(c), 
    //                                                                                                         asLowercase:00447569(c), 
    //                                                                                                         DKeyString:0044764a(c), 
    //                                                                                                         DKeyString:0044765c(c), 
    //                                                                                                         key:00447701(c), 
    //                                                                                                         value:00447774(c)  
    //                              dstring.cpp:41 (32)
    //         00446620     PUSH       EBX
    //         00446621     PUSH       ESI
    //         00446622     MOV        ESI,dword ptr [ESP + param_1]
    //         00446626     MOV        EBX,this
    //         00446628     MOV        EAX,dword ptr [ESI + 0x4]
    //         0044662b     MOV        dword ptr [EBX + 0x4],EAX
    //         0044662e     MOV        this,dword ptr [ESI + 0x8]
    //         00446631     MOV        dword ptr [EBX + 0x8],this
    //         00446634     MOV        EDX,dword ptr [ESI + 0xc]
    //         00446637     MOV        dword ptr [EBX + 0xc],EDX
    //         0044663a     MOV        EAX,dword ptr [ESI + 0x10]
    //         0044663d     MOV        dword ptr [EBX + 0x10],EAX
    //                              dstring.cpp:42 (7)
    //         00446640     MOV        EAX,dword ptr [EBX + 0x4]
    //         00446643     TEST       EAX,EAX
    //         00446645     JLE        LAB_0044667d
    //                              dstring.cpp:43 (10)
    //         00446647     INC        EAX
    //         00446648     PUSH       EDI
    //         00446649     PUSH       EAX
    //         0044664a     CALL       malloc                                           undefined malloc()
    //         0044664f     MOV        EDX,EAX
    //                              dstring.cpp:44 (31)
    //         00446651     OR         this,0xffffffff
    //         00446654     MOV        dword ptr [EBX],EDX
    //         00446656     MOV        EDI,dword ptr [ESI]
    //         00446658     XOR        EAX,EAX
    //         0044665a     ADD        ESP,0x4
    //         0044665d     SCASB.RE   ES:EDI
    //         0044665f     NOT        this
    //         00446661     SUB        EDI,this
    //         00446663     MOV        EAX,this
    //         00446665     MOV        ESI,EDI
    //         00446667     MOV        EDI,EDX
    //         00446669     SHR        this,0x2
    //         0044666c     MOVSD.REP  ES:EDI,ESI
    //         0044666e     MOV        this,EAX
    //                              dstring.cpp:48 (13)
    //         00446670     MOV        EAX,EBX
    //         00446672     AND        this,0x3
    //         00446675     MOVSB.REP  ES:EDI,ESI
    //         00446677     POP        EDI
    //         00446678     POP        ESI
    //         00446679     POP        EBX
    //         0044667a     RET        0x4
    //                               LAB_0044667d                                                 XREF[1]:     00446645(j)  
    //                              dstring.cpp:47 (6)
    //         0044667d     MOV        dword ptr [EBX],0x0
    //                              dstring.cpp:48 (7)
    //         00446683     MOV        EAX,EBX
    //         00446685     POP        ESI
    //         00446686     POP        EBX
    //         00446687     RET        0x4
    //         0044668a     ??         90h
    //         0044668b     NOP
    //         0044668c     NOP
    //         0044668d     NOP
    //         0044668e     NOP
    //         0044668f     NOP
}

DString::DString(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall DString(DString * this, char * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446692(R)  
    //                               ??0DString@@QAE@PBD@Z                                        XREF[6]:     word:00446fb1(c), 
    //                               DString::DString                                                          subString:004471a3(c), 
    //                                                                                                         asUppercase:00447488(c), 
    //                                                                                                         asLowercase:00447548(c), 
    //                                                                                                         DKeyString:004475f2(c), 
    //                                                                                                         DKeyString:00447607(c)  
    //                              dstring.cpp:54 (28)
    //         00446690     PUSH       EBX
    //         00446691     PUSH       ESI
    //         00446692     MOV        ESI,dword ptr [ESP + param_1]
    //         00446696     MOV        EBX,this
    //         00446698     PUSH       EDI
    //         00446699     MOV        EDI,ESI
    //         0044669b     OR         this,0xffffffff
    //         0044669e     XOR        EAX,EAX
    //         004466a0     SCASB.RE   ES:EDI
    //         004466a2     NOT        this
    //         004466a4     DEC        this
    //         004466a5     MOV        dword ptr [EBX + 0x8],0xffffffff
    //                              dstring.cpp:55 (13)
    //         004466ac     CMP        this,EAX
    //         004466ae     MOV        dword ptr [EBX + 0x4],this
    //         004466b1     MOV        dword ptr [EBX + 0xc],EAX
    //         004466b4     MOV        dword ptr [EBX + 0x10],EAX
    //         004466b7     JLE        LAB_004466ee
    //                              dstring.cpp:56 (9)
    //         004466b9     INC        this
    //         004466ba     PUSH       this
    //         004466bb     CALL       malloc                                           undefined malloc()
    //         004466c0     MOV        EDX,EAX
    //                              dstring.cpp:57 (31)
    //         004466c2     MOV        EDI,ESI
    //         004466c4     OR         this,0xffffffff
    //         004466c7     XOR        EAX,EAX
    //         004466c9     ADD        ESP,0x4
    //         004466cc     MOV        dword ptr [EBX],EDX
    //         004466ce     SCASB.RE   ES:EDI
    //         004466d0     NOT        this
    //         004466d2     SUB        EDI,this
    //         004466d4     MOV        EAX,this
    //         004466d6     MOV        ESI,EDI
    //         004466d8     MOV        EDI,EDX
    //         004466da     SHR        this,0x2
    //         004466dd     MOVSD.REP  ES:EDI,ESI
    //         004466df     MOV        this,EAX
    //                              dstring.cpp:61 (13)
    //         004466e1     MOV        EAX,EBX
    //         004466e3     AND        this,0x3
    //         004466e6     MOVSB.REP  ES:EDI,ESI
    //         004466e8     POP        EDI
    //         004466e9     POP        ESI
    //         004466ea     POP        EBX
    //         004466eb     RET        0x4
    //                               LAB_004466ee                                                 XREF[1]:     004466b7(j)  
    //                              dstring.cpp:60 (2)
    //         004466ee     MOV        dword ptr [EBX],EAX
    //                              dstring.cpp:61 (8)
    //         004466f0     POP        EDI
    //         004466f1     MOV        EAX,EBX
    //         004466f3     POP        ESI
    //         004466f4     POP        EBX
    //         004466f5     RET        0x4
    //         004466f8     ??         90h
    //         004466f9     NOP
    //         004466fa     NOP
    //         004466fb     NOP
    //         004466fc     NOP
    //         004466fd     NOP
    //         004466fe     NOP
    //         004466ff     NOP
}

DString::~DString() {
    /* TODO: Stub */
    //                              void __thiscall ~DString(DString * this)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ??1DString@@QAE@XZ                                           XREF[17]:    operator+:00446cf0(c), 
    //                               DString::~DString                                                         contains:00446da5(c), 
    //                                                                                                         contains:00446dc1(c), 
    //                                                                                                         word:00446f9f(c), 
    //                                                                                                         nextWord:00447093(c), 
    //                                                                                                         subString:004471ce(c), 
    //                                                                                                         append:004472b5(c), 
    //                                                                                                         stripTrailing:0044733c(c), 
    //                                                                                                         stripLeading:004473da(c), 
    //                                                                                                         asUppercase:004474bf(c), 
    //                                                                                                         asLowercase:0044757f(c), 
    //                                                                                                         DKeyString:0044766a(c), 
    //                                                                                                         DKeyString:0044767b(c), 
    //                                                                                                         ~DKeyString:004476c3(c), 
    //                                                                                                         ~DKeyString:004476d2(c), 
    //                                                                                                         setKey:00447743(c), 
    //                                                                                                         setValue:004477b6(c)  
    //                              dstring.cpp:63 (6)
    //         00446700     MOV        EAX,dword ptr [this->stringValue]
    //         00446702     TEST       EAX,EAX
    //         00446704     JZ         LAB_0044670f
    //                              dstring.cpp:65 (9)
    //         00446706     PUSH       EAX
    //         00446707     CALL       free                                             undefined free()
    //         0044670c     ADD        ESP,0x4
    //                               LAB_0044670f                                                 XREF[1]:     00446704(j)  
    //                              dstring.cpp:66 (1)
    //         0044670f     RET
    //                              * class ostream & __cdecl operator<<(class ostream &,class DString const &)                             *
    //                              ostream * __cdecl operator<<(ostream * param_1, DString * param_2)
    //              ostream *         EAX:4          <RETURN>
    //              ostream *         Stack[0x4]:4   param_1                   XREF[1]:     00446715(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446710(R)  
    //                               ??6@YAAAVostream@@AAV0@ABVDString@@@Z
    //                               operator<<
    //                              dstring.cpp:68 (15)
    //         00446710     MOV        EAX,dword ptr [ESP + param_2]
    //         00446714     PUSH       ESI
    //         00446715     MOV        ESI,dword ptr [ESP + param_1]
    //         00446719     MOV        EAX,dword ptr [EAX]
    //         0044671b     TEST       EAX,EAX
    //         0044671d     JZ         LAB_00446727
    //                              dstring.cpp:70 (8)
    //         0044671f     PUSH       EAX
    //         00446720     MOV        ECX,ESI
    //         00446722     CALL       ostream::operator<<                              ostream * operator<<(ostream * this, char * p
    //                               LAB_00446727                                                 XREF[1]:     0044671d(j)  
    //                              dstring.cpp:71 (2)
    //         00446727     MOV        EAX,ESI
    //                              dstring.cpp:72 (2)
    //         00446729     POP        ESI
    //         0044672a     RET
    //         0044672b     ??         90h
    //         0044672c     NOP
    //         0044672d     NOP
    //         0044672e     NOP
    //         0044672f     NOP
    //                              * class istream & __cdecl operator>>(class istream &,class DString &)                                   *
    //                              istream * __cdecl operator>>(istream * param_1, DString * param_2)
    //              istream *         EAX:4          <RETURN>
    //              istream *         Stack[0x4]:4   param_1                   XREF[1]:     0044673b(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     0044675d(R)  
    //              char[256]         Stack[-0x104   buffer                    XREF[0,2]:   00446736(*), 00446758(*)  
    //                               ??5@YAAAVistream@@AAV0@AAVDString@@@Z
    //                               operator>>
    //                              dstring.cpp:74 (6)
    //         00446730     SUB        ESP,0x100
    //                              dstring.cpp:76 (34)
    //         00446736     LEA        EAX=>buffer[4],[ESP]
    //         0044673a     PUSH       ESI
    //         0044673b     MOV        ESI,dword ptr [ESP + param_1]
    //         00446742     PUSH       0xa
    //         00446744     PUSH       0x100
    //         00446749     MOV        ECX,dword ptr [ESI + 0x4]
    //         0044674c     PUSH       EAX
    //         0044674d     INC        ECX
    //         0044674e     MOV        dword ptr [ESI + 0x4],ECX
    //         00446751     MOV        ECX,ESI
    //         00446753     CALL       istream::get                                     istream * get(istream * this, char * param_1,
    //                              dstring.cpp:77 (17)
    //         00446758     LEA        ECX=>buffer[4],[ESP + 0x4]
    //         0044675c     PUSH       ECX
    //         0044675d     MOV        ECX,dword ptr [ESP + param_2]
    //         00446764     CALL       DString::operator=                               DString * operator=(DString * this, char * pa
    //                              dstring.cpp:78 (2)
    //         00446769     MOV        EAX,ESI
    //                              dstring.cpp:79 (8)
    //         0044676b     POP        ESI
    //         0044676c     ADD        ESP,0x100
    //         00446772     RET
    //         00446773     ??         90h
    //         00446774     NOP
    //         00446775     NOP
    //         00446776     NOP
    //         00446777     NOP
    //         00446778     NOP
    //         00446779     NOP
    //         0044677a     NOP
    //         0044677b     NOP
    //         0044677c     NOP
    //         0044677d     NOP
    //         0044677e     NOP
    //         0044677f     NOP
}

DString* DString::operator=(char* param_1) {
    /* TODO: Stub */
    //                              DString * __thiscall operator=(DString * this, char * param_1)
    //              DString *         EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446794(R)  
    //                               ??4DString@@QAEAAV0@PBD@Z                                    XREF[1]:     operator>>:00446764(c)  
    //                               DString::operator=
    //                              dstring.cpp:81 (5)
    //         00446780     PUSH       EBX
    //         00446781     MOV        EBX,this
    //         00446783     PUSH       ESI
    //         00446784     PUSH       EDI
    //                              dstring.cpp:82 (6)
    //         00446785     MOV        EAX,dword ptr [EBX]
    //         00446787     TEST       EAX,EAX
    //         00446789     JZ         LAB_00446794
    //                              dstring.cpp:83 (9)
    //         0044678b     PUSH       EAX
    //         0044678c     CALL       free                                             undefined free()
    //         00446791     ADD        ESP,0x4
    //                               LAB_00446794                                                 XREF[1]:     00446789(j)  
    //                              dstring.cpp:88 (33)
    //         00446794     MOV        ESI,dword ptr [ESP + param_1]
    //         00446798     OR         this,0xffffffff
    //         0044679b     MOV        EDI,ESI
    //         0044679d     XOR        EAX,EAX
    //         0044679f     MOV        dword ptr [EBX + 0x8],this
    //         004467a2     MOV        dword ptr [EBX + 0xc],0x0
    //         004467a9     MOV        dword ptr [EBX + 0x10],0x0
    //         004467b0     SCASB.RE   ES:EDI
    //         004467b2     NOT        this
    //         004467b4     DEC        this
    //                              dstring.cpp:90 (7)
    //         004467b5     TEST       this,this
    //         004467b7     MOV        dword ptr [EBX + 0x4],this
    //         004467ba     JLE        LAB_004467f1
    //                              dstring.cpp:91 (9)
    //         004467bc     INC        this
    //         004467bd     PUSH       this
    //         004467be     CALL       malloc                                           undefined malloc()
    //         004467c3     MOV        EDX,EAX
    //                              dstring.cpp:92 (31)
    //         004467c5     MOV        EDI,ESI
    //         004467c7     OR         this,0xffffffff
    //         004467ca     XOR        EAX,EAX
    //         004467cc     ADD        ESP,0x4
    //         004467cf     MOV        dword ptr [EBX],EDX
    //         004467d1     SCASB.RE   ES:EDI
    //         004467d3     NOT        this
    //         004467d5     SUB        EDI,this
    //         004467d7     MOV        EAX,this
    //         004467d9     MOV        ESI,EDI
    //         004467db     MOV        EDI,EDX
    //         004467dd     SHR        this,0x2
    //         004467e0     MOVSD.REP  ES:EDI,ESI
    //         004467e2     MOV        this,EAX
    //                              dstring.cpp:97 (7)
    //         004467e4     MOV        EAX,EBX
    //         004467e6     AND        this,0x3
    //         004467e9     MOVSB.REP  ES:EDI,ESI
    //                              dstring.cpp:98 (20)
    //         004467eb     POP        EDI
    //         004467ec     POP        ESI
    //         004467ed     POP        EBX
    //         004467ee     RET        0x4
    //                               LAB_004467f1                                                 XREF[1]:     004467ba(j)  
    //         004467f1     POP        EDI
    //         004467f2     MOV        dword ptr [EBX],0x0
    //         004467f8     MOV        EAX,EBX
    //         004467fa     POP        ESI
    //         004467fb     POP        EBX
    //         004467fc     RET        0x4
    //         004467ff     ??         90h
    return 0;
}

DString* DString::operator=(DString* param_1) {
    /* TODO: Stub */
    //                              DString * __thiscall operator=(DString * this, DString * param_1)
    //              DString *         EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446814(R)  
    //                               ??4DString@@QAEAAV0@ABV0@@Z                                  XREF[4]:     stripTrailing:0044732b(c), 
    //                               DString::operator=                                                        stripLeading:004473c9(c), 
    //                                                                                                         setKey:00447732(c), 
    //                                                                                                         setValue:004477a5(c)  
    //                              dstring.cpp:100 (5)
    //         00446800     PUSH       EBX
    //         00446801     MOV        EBX,this
    //         00446803     PUSH       ESI
    //         00446804     PUSH       EDI
    //                              dstring.cpp:101 (6)
    //         00446805     MOV        EAX,dword ptr [EBX]
    //         00446807     TEST       EAX,EAX
    //         00446809     JZ         LAB_00446814
    //                              dstring.cpp:102 (9)
    //         0044680b     PUSH       EAX
    //         0044680c     CALL       free                                             undefined free()
    //         00446811     ADD        ESP,0x4
    //                               LAB_00446814                                                 XREF[1]:     00446809(j)  
    //                              dstring.cpp:104 (10)
    //         00446814     MOV        ESI,dword ptr [ESP + param_1]
    //         00446818     MOV        EAX,dword ptr [ESI + 0x8]
    //         0044681b     MOV        dword ptr [EBX + 0x8],EAX
    //                              dstring.cpp:105 (6)
    //         0044681e     MOV        this,dword ptr [ESI + 0xc]
    //         00446821     MOV        dword ptr [EBX + 0xc],this
    //                              dstring.cpp:106 (6)
    //         00446824     MOV        EDX,dword ptr [ESI + 0x10]
    //         00446827     MOV        dword ptr [EBX + 0x10],EDX
    //                              dstring.cpp:107 (3)
    //         0044682a     MOV        EAX,dword ptr [ESI + 0x4]
    //                              dstring.cpp:109 (7)
    //         0044682d     TEST       EAX,EAX
    //         0044682f     MOV        dword ptr [EBX + 0x4],EAX
    //         00446832     JLE        LAB_00446869
    //                              dstring.cpp:110 (9)
    //         00446834     INC        EAX
    //         00446835     PUSH       EAX
    //         00446836     CALL       malloc                                           undefined malloc()
    //         0044683b     MOV        EDX,EAX
    //                              dstring.cpp:111 (31)
    //         0044683d     OR         this,0xffffffff
    //         00446840     MOV        dword ptr [EBX],EDX
    //         00446842     MOV        EDI,dword ptr [ESI]
    //         00446844     XOR        EAX,EAX
    //         00446846     ADD        ESP,0x4
    //         00446849     SCASB.RE   ES:EDI
    //         0044684b     NOT        this
    //         0044684d     SUB        EDI,this
    //         0044684f     MOV        EAX,this
    //         00446851     MOV        ESI,EDI
    //         00446853     MOV        EDI,EDX
    //         00446855     SHR        this,0x2
    //         00446858     MOVSD.REP  ES:EDI,ESI
    //         0044685a     MOV        this,EAX
    //                              dstring.cpp:116 (7)
    //         0044685c     MOV        EAX,EBX
    //         0044685e     AND        this,0x3
    //         00446861     MOVSB.REP  ES:EDI,ESI
    //                              dstring.cpp:117 (20)
    //         00446863     POP        EDI
    //         00446864     POP        ESI
    //         00446865     POP        EBX
    //         00446866     RET        0x4
    //                               LAB_00446869                                                 XREF[1]:     00446832(j)  
    //         00446869     POP        EDI
    //         0044686a     MOV        dword ptr [EBX],0x0
    //         00446870     MOV        EAX,EBX
    //         00446872     POP        ESI
    //         00446873     POP        EBX
    //         00446874     RET        0x4
    //         00446877     ??         90h
    //         00446878     NOP
    //         00446879     NOP
    //         0044687a     NOP
    //         0044687b     NOP
    //         0044687c     NOP
    //         0044687d     NOP
    //         0044687e     NOP
    //         0044687f     NOP
    //                              * int __cdecl operator==(class DString const &,class DString const &)                                   *
    //                              int __cdecl operator==(DString * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446884(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446880(R)  
    //                               ??8@YAHABVDString@@0@Z
    //                               operator==
    //                              dstring.cpp:119 (61)
    //         00446880     MOV        EAX,dword ptr [ESP + param_2]
    //         00446884     MOV        ECX,dword ptr [ESP + param_1]
    //         00446888     PUSH       EBX
    //         00446889     PUSH       ESI
    //         0044688a     MOV        ESI,dword ptr [EAX]
    //         0044688c     MOV        EAX,dword ptr [ECX]
    //                               LAB_0044688e                                                 XREF[1]:     004468b0(j)  
    //         0044688e     MOV        DL,byte ptr [EAX]
    //         00446890     MOV        BL,byte ptr [ESI]
    //         00446892     MOV        CL,DL
    //         00446894     CMP        DL,BL
    //         00446896     JNZ        LAB_004468c0
    //         00446898     TEST       CL,CL
    //         0044689a     JZ         LAB_004468b2
    //         0044689c     MOV        DL,byte ptr [EAX + 0x1]
    //         0044689f     MOV        BL,byte ptr [ESI + 0x1]
    //         004468a2     MOV        CL,DL
    //         004468a4     CMP        DL,BL
    //         004468a6     JNZ        LAB_004468c0
    //         004468a8     ADD        EAX,0x2
    //         004468ab     ADD        ESI,0x2
    //         004468ae     TEST       CL,CL
    //         004468b0     JNZ        LAB_0044688e
    //                               LAB_004468b2                                                 XREF[1]:     0044689a(j)  
    //         004468b2     XOR        EAX,EAX
    //         004468b4     XOR        ECX,ECX
    //         004468b6     TEST       EAX,EAX
    //         004468b8     SETZ       CL
    //         004468bb     MOV        EAX,ECX
    //                              dstring.cpp:123 (3)
    //         004468bd     POP        ESI
    //         004468be     POP        EBX
    //         004468bf     RET
    //                               LAB_004468c0                                                 XREF[2]:     00446896(j), 004468a6(j)  
    //                              dstring.cpp:120 (2)
    //         004468c0     SBB        EAX,EAX
    //                              dstring.cpp:123 (15)
    //         004468c2     POP        ESI
    //         004468c3     SBB        EAX,-0x1
    //         004468c6     XOR        ECX,ECX
    //         004468c8     TEST       EAX,EAX
    //         004468ca     SETZ       CL
    //         004468cd     MOV        EAX,ECX
    //         004468cf     POP        EBX
    //         004468d0     RET
    //         004468d1     ??         90h
    //         004468d2     NOP
    //         004468d3     NOP
    //         004468d4     NOP
    //         004468d5     NOP
    //         004468d6     NOP
    //         004468d7     NOP
    //         004468d8     NOP
    //         004468d9     NOP
    //         004468da     NOP
    //         004468db     NOP
    //         004468dc     NOP
    //         004468dd     NOP
    //         004468de     NOP
    //         004468df     NOP
    //                              * int __cdecl operator==(class DString const &,char const *)                                            *
    //                              int __cdecl operator==(DString * param_1, char * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     004468e0(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     004468e6(R)  
    //                               ??8@YAHABVDString@@PBD@Z
    //                               operator==
    //                              dstring.cpp:125 (59)
    //         004468e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004468e4     PUSH       EBX
    //         004468e5     PUSH       ESI
    //         004468e6     MOV        ESI,dword ptr [ESP + param_2]
    //         004468ea     MOV        EAX,dword ptr [EAX]
    //                               LAB_004468ec                                                 XREF[1]:     0044690e(j)  
    //         004468ec     MOV        DL,byte ptr [EAX]
    //         004468ee     MOV        BL,byte ptr [ESI]
    //         004468f0     MOV        CL,DL
    //         004468f2     CMP        DL,BL
    //         004468f4     JNZ        LAB_0044691e
    //         004468f6     TEST       CL,CL
    //         004468f8     JZ         LAB_00446910
    //         004468fa     MOV        DL,byte ptr [EAX + 0x1]
    //         004468fd     MOV        BL,byte ptr [ESI + 0x1]
    //         00446900     MOV        CL,DL
    //         00446902     CMP        DL,BL
    //         00446904     JNZ        LAB_0044691e
    //         00446906     ADD        EAX,0x2
    //         00446909     ADD        ESI,0x2
    //         0044690c     TEST       CL,CL
    //         0044690e     JNZ        LAB_004468ec
    //                               LAB_00446910                                                 XREF[1]:     004468f8(j)  
    //         00446910     XOR        EAX,EAX
    //         00446912     XOR        ECX,ECX
    //         00446914     TEST       EAX,EAX
    //         00446916     SETZ       CL
    //         00446919     MOV        EAX,ECX
    //                              dstring.cpp:129 (3)
    //         0044691b     POP        ESI
    //         0044691c     POP        EBX
    //         0044691d     RET
    //                               LAB_0044691e                                                 XREF[2]:     004468f4(j), 00446904(j)  
    //                              dstring.cpp:126 (2)
    //         0044691e     SBB        EAX,EAX
    //                              dstring.cpp:129 (15)
    //         00446920     POP        ESI
    //         00446921     SBB        EAX,-0x1
    //         00446924     XOR        ECX,ECX
    //         00446926     TEST       EAX,EAX
    //         00446928     SETZ       CL
    //         0044692b     MOV        EAX,ECX
    //         0044692d     POP        EBX
    //         0044692e     RET
    //         0044692f     ??         90h
    //                              * int __cdecl operator==(char const *,class DString const &)                                            *
    //                              int __cdecl operator==(char * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446938(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446930(R)  
    //                               ??8@YAHPBDABVDString@@@Z
    //                               operator==
    //                              dstring.cpp:131 (59)
    //         00446930     MOV        EAX,dword ptr [ESP + param_2]
    //         00446934     PUSH       EBX
    //         00446935     PUSH       ESI
    //         00446936     MOV        ESI,dword ptr [EAX]
    //         00446938     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_0044693c                                                 XREF[1]:     0044695e(j)  
    //         0044693c     MOV        DL,byte ptr [EAX]
    //         0044693e     MOV        BL,byte ptr [ESI]
    //         00446940     MOV        CL,DL
    //         00446942     CMP        DL,BL
    //         00446944     JNZ        LAB_0044696e
    //         00446946     TEST       CL,CL
    //         00446948     JZ         LAB_00446960
    //         0044694a     MOV        DL,byte ptr [EAX + 0x1]
    //         0044694d     MOV        BL,byte ptr [ESI + 0x1]
    //         00446950     MOV        CL,DL
    //         00446952     CMP        DL,BL
    //         00446954     JNZ        LAB_0044696e
    //         00446956     ADD        EAX,0x2
    //         00446959     ADD        ESI,0x2
    //         0044695c     TEST       CL,CL
    //         0044695e     JNZ        LAB_0044693c
    //                               LAB_00446960                                                 XREF[1]:     00446948(j)  
    //         00446960     XOR        EAX,EAX
    //         00446962     XOR        ECX,ECX
    //         00446964     TEST       EAX,EAX
    //         00446966     SETZ       CL
    //         00446969     MOV        EAX,ECX
    //                              dstring.cpp:135 (3)
    //         0044696b     POP        ESI
    //         0044696c     POP        EBX
    //         0044696d     RET
    //                               LAB_0044696e                                                 XREF[2]:     00446944(j), 00446954(j)  
    //                              dstring.cpp:132 (2)
    //         0044696e     SBB        EAX,EAX
    //                              dstring.cpp:135 (15)
    //         00446970     POP        ESI
    //         00446971     SBB        EAX,-0x1
    //         00446974     XOR        ECX,ECX
    //         00446976     TEST       EAX,EAX
    //         00446978     SETZ       CL
    //         0044697b     MOV        EAX,ECX
    //         0044697d     POP        EBX
    //         0044697e     RET
    //         0044697f     ??         90h
    //                              * int __cdecl operator!=(class DString const &,class DString const &)                                   *
    //                              int __cdecl operator!=(DString * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446984(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446980(R)  
    //                               ??9@YAHABVDString@@0@Z
    //                               operator!=
    //                              dstring.cpp:137 (61)
    //         00446980     MOV        EAX,dword ptr [ESP + param_2]
    //         00446984     MOV        ECX,dword ptr [ESP + param_1]
    //         00446988     PUSH       EBX
    //         00446989     PUSH       ESI
    //         0044698a     MOV        ESI,dword ptr [EAX]
    //         0044698c     MOV        EAX,dword ptr [ECX]
    //                               LAB_0044698e                                                 XREF[1]:     004469b0(j)  
    //         0044698e     MOV        DL,byte ptr [EAX]
    //         00446990     MOV        BL,byte ptr [ESI]
    //         00446992     MOV        CL,DL
    //         00446994     CMP        DL,BL
    //         00446996     JNZ        LAB_004469c0
    //         00446998     TEST       CL,CL
    //         0044699a     JZ         LAB_004469b2
    //         0044699c     MOV        DL,byte ptr [EAX + 0x1]
    //         0044699f     MOV        BL,byte ptr [ESI + 0x1]
    //         004469a2     MOV        CL,DL
    //         004469a4     CMP        DL,BL
    //         004469a6     JNZ        LAB_004469c0
    //         004469a8     ADD        EAX,0x2
    //         004469ab     ADD        ESI,0x2
    //         004469ae     TEST       CL,CL
    //         004469b0     JNZ        LAB_0044698e
    //                               LAB_004469b2                                                 XREF[1]:     0044699a(j)  
    //         004469b2     XOR        EAX,EAX
    //         004469b4     XOR        ECX,ECX
    //         004469b6     TEST       EAX,EAX
    //         004469b8     SETNZ      CL
    //         004469bb     MOV        EAX,ECX
    //                              dstring.cpp:141 (3)
    //         004469bd     POP        ESI
    //         004469be     POP        EBX
    //         004469bf     RET
    //                               LAB_004469c0                                                 XREF[2]:     00446996(j), 004469a6(j)  
    //                              dstring.cpp:138 (2)
    //         004469c0     SBB        EAX,EAX
    //                              dstring.cpp:141 (15)
    //         004469c2     POP        ESI
    //         004469c3     SBB        EAX,-0x1
    //         004469c6     XOR        ECX,ECX
    //         004469c8     TEST       EAX,EAX
    //         004469ca     SETNZ      CL
    //         004469cd     MOV        EAX,ECX
    //         004469cf     POP        EBX
    //         004469d0     RET
    //         004469d1     ??         90h
    //         004469d2     NOP
    //         004469d3     NOP
    //         004469d4     NOP
    //         004469d5     NOP
    //         004469d6     NOP
    //         004469d7     NOP
    //         004469d8     NOP
    //         004469d9     NOP
    //         004469da     NOP
    //         004469db     NOP
    //         004469dc     NOP
    //         004469dd     NOP
    //         004469de     NOP
    //         004469df     NOP
    //                              * int __cdecl operator!=(class DString const &,char const *)                                            *
    //                              int __cdecl operator!=(DString * param_1, char * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     004469e0(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     004469e6(R)  
    //                               ??9@YAHABVDString@@PBD@Z
    //                               operator!=
    //                              dstring.cpp:143 (59)
    //         004469e0     MOV        EAX,dword ptr [ESP + param_1]
    //         004469e4     PUSH       EBX
    //         004469e5     PUSH       ESI
    //         004469e6     MOV        ESI,dword ptr [ESP + param_2]
    //         004469ea     MOV        EAX,dword ptr [EAX]
    //                               LAB_004469ec                                                 XREF[1]:     00446a0e(j)  
    //         004469ec     MOV        DL,byte ptr [EAX]
    //         004469ee     MOV        BL,byte ptr [ESI]
    //         004469f0     MOV        CL,DL
    //         004469f2     CMP        DL,BL
    //         004469f4     JNZ        LAB_00446a1e
    //         004469f6     TEST       CL,CL
    //         004469f8     JZ         LAB_00446a10
    //         004469fa     MOV        DL,byte ptr [EAX + 0x1]
    //         004469fd     MOV        BL,byte ptr [ESI + 0x1]
    //         00446a00     MOV        CL,DL
    //         00446a02     CMP        DL,BL
    //         00446a04     JNZ        LAB_00446a1e
    //         00446a06     ADD        EAX,0x2
    //         00446a09     ADD        ESI,0x2
    //         00446a0c     TEST       CL,CL
    //         00446a0e     JNZ        LAB_004469ec
    //                               LAB_00446a10                                                 XREF[1]:     004469f8(j)  
    //         00446a10     XOR        EAX,EAX
    //         00446a12     XOR        ECX,ECX
    //         00446a14     TEST       EAX,EAX
    //         00446a16     SETNZ      CL
    //         00446a19     MOV        EAX,ECX
    //                              dstring.cpp:147 (3)
    //         00446a1b     POP        ESI
    //         00446a1c     POP        EBX
    //         00446a1d     RET
    //                               LAB_00446a1e                                                 XREF[2]:     004469f4(j), 00446a04(j)  
    //                              dstring.cpp:144 (2)
    //         00446a1e     SBB        EAX,EAX
    //                              dstring.cpp:147 (15)
    //         00446a20     POP        ESI
    //         00446a21     SBB        EAX,-0x1
    //         00446a24     XOR        ECX,ECX
    //         00446a26     TEST       EAX,EAX
    //         00446a28     SETNZ      CL
    //         00446a2b     MOV        EAX,ECX
    //         00446a2d     POP        EBX
    //         00446a2e     RET
    //         00446a2f     ??         90h
    //                              * int __cdecl operator!=(char const *,class DString const &)                                            *
    //                              int __cdecl operator!=(char * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446a38(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446a30(R)  
    //                               ??9@YAHPBDABVDString@@@Z
    //                               operator!=
    //                              dstring.cpp:149 (59)
    //         00446a30     MOV        EAX,dword ptr [ESP + param_2]
    //         00446a34     PUSH       EBX
    //         00446a35     PUSH       ESI
    //         00446a36     MOV        ESI,dword ptr [EAX]
    //         00446a38     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_00446a3c                                                 XREF[1]:     00446a5e(j)  
    //         00446a3c     MOV        DL,byte ptr [EAX]
    //         00446a3e     MOV        BL,byte ptr [ESI]
    //         00446a40     MOV        CL,DL
    //         00446a42     CMP        DL,BL
    //         00446a44     JNZ        LAB_00446a6e
    //         00446a46     TEST       CL,CL
    //         00446a48     JZ         LAB_00446a60
    //         00446a4a     MOV        DL,byte ptr [EAX + 0x1]
    //         00446a4d     MOV        BL,byte ptr [ESI + 0x1]
    //         00446a50     MOV        CL,DL
    //         00446a52     CMP        DL,BL
    //         00446a54     JNZ        LAB_00446a6e
    //         00446a56     ADD        EAX,0x2
    //         00446a59     ADD        ESI,0x2
    //         00446a5c     TEST       CL,CL
    //         00446a5e     JNZ        LAB_00446a3c
    //                               LAB_00446a60                                                 XREF[1]:     00446a48(j)  
    //         00446a60     XOR        EAX,EAX
    //         00446a62     XOR        ECX,ECX
    //         00446a64     TEST       EAX,EAX
    //         00446a66     SETNZ      CL
    //         00446a69     MOV        EAX,ECX
    //                              dstring.cpp:153 (3)
    //         00446a6b     POP        ESI
    //         00446a6c     POP        EBX
    //         00446a6d     RET
    //                               LAB_00446a6e                                                 XREF[2]:     00446a44(j), 00446a54(j)  
    //                              dstring.cpp:150 (2)
    //         00446a6e     SBB        EAX,EAX
    //                              dstring.cpp:153 (15)
    //         00446a70     POP        ESI
    //         00446a71     SBB        EAX,-0x1
    //         00446a74     XOR        ECX,ECX
    //         00446a76     TEST       EAX,EAX
    //         00446a78     SETNZ      CL
    //         00446a7b     MOV        EAX,ECX
    //         00446a7d     POP        EBX
    //         00446a7e     RET
    //         00446a7f     ??         90h
    //                              * int __cdecl operator<(class DString const &,class DString const &)                                    *
    //                              int __cdecl operator<(DString * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446a84(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446a80(R)  
    //                               ??M@YAHABVDString@@0@Z
    //                               operator<
    //                              dstring.cpp:155 (61)
    //         00446a80     MOV        EAX,dword ptr [ESP + param_2]
    //         00446a84     MOV        ECX,dword ptr [ESP + param_1]
    //         00446a88     PUSH       EBX
    //         00446a89     PUSH       ESI
    //         00446a8a     MOV        ESI,dword ptr [EAX]
    //         00446a8c     MOV        EAX,dword ptr [ECX]
    //                               LAB_00446a8e                                                 XREF[1]:     00446ab0(j)  
    //         00446a8e     MOV        DL,byte ptr [EAX]
    //         00446a90     MOV        BL,byte ptr [ESI]
    //         00446a92     MOV        CL,DL
    //         00446a94     CMP        DL,BL
    //         00446a96     JNZ        LAB_00446ac0
    //         00446a98     TEST       CL,CL
    //         00446a9a     JZ         LAB_00446ab2
    //         00446a9c     MOV        DL,byte ptr [EAX + 0x1]
    //         00446a9f     MOV        BL,byte ptr [ESI + 0x1]
    //         00446aa2     MOV        CL,DL
    //         00446aa4     CMP        DL,BL
    //         00446aa6     JNZ        LAB_00446ac0
    //         00446aa8     ADD        EAX,0x2
    //         00446aab     ADD        ESI,0x2
    //         00446aae     TEST       CL,CL
    //         00446ab0     JNZ        LAB_00446a8e
    //                               LAB_00446ab2                                                 XREF[1]:     00446a9a(j)  
    //         00446ab2     XOR        EAX,EAX
    //         00446ab4     XOR        ECX,ECX
    //         00446ab6     TEST       EAX,EAX
    //         00446ab8     SETL       CL
    //         00446abb     MOV        EAX,ECX
    //                              dstring.cpp:159 (3)
    //         00446abd     POP        ESI
    //         00446abe     POP        EBX
    //         00446abf     RET
    //                               LAB_00446ac0                                                 XREF[2]:     00446a96(j), 00446aa6(j)  
    //                              dstring.cpp:156 (2)
    //         00446ac0     SBB        EAX,EAX
    //                              dstring.cpp:159 (15)
    //         00446ac2     POP        ESI
    //         00446ac3     SBB        EAX,-0x1
    //         00446ac6     XOR        ECX,ECX
    //         00446ac8     TEST       EAX,EAX
    //         00446aca     SETL       CL
    //         00446acd     MOV        EAX,ECX
    //         00446acf     POP        EBX
    //         00446ad0     RET
    //         00446ad1     ??         90h
    //         00446ad2     NOP
    //         00446ad3     NOP
    //         00446ad4     NOP
    //         00446ad5     NOP
    //         00446ad6     NOP
    //         00446ad7     NOP
    //         00446ad8     NOP
    //         00446ad9     NOP
    //         00446ada     NOP
    //         00446adb     NOP
    //         00446adc     NOP
    //         00446add     NOP
    //         00446ade     NOP
    //         00446adf     NOP
    //                              * int __cdecl operator<(class DString const &,char const *)                                             *
    //                              int __cdecl operator<(DString * param_1, char * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446ae0(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00446ae6(R)  
    //                               ??M@YAHABVDString@@PBD@Z
    //                               operator<
    //                              dstring.cpp:161 (59)
    //         00446ae0     MOV        EAX,dword ptr [ESP + param_1]
    //         00446ae4     PUSH       EBX
    //         00446ae5     PUSH       ESI
    //         00446ae6     MOV        ESI,dword ptr [ESP + param_2]
    //         00446aea     MOV        EAX,dword ptr [EAX]
    //                               LAB_00446aec                                                 XREF[1]:     00446b0e(j)  
    //         00446aec     MOV        DL,byte ptr [EAX]
    //         00446aee     MOV        BL,byte ptr [ESI]
    //         00446af0     MOV        CL,DL
    //         00446af2     CMP        DL,BL
    //         00446af4     JNZ        LAB_00446b1e
    //         00446af6     TEST       CL,CL
    //         00446af8     JZ         LAB_00446b10
    //         00446afa     MOV        DL,byte ptr [EAX + 0x1]
    //         00446afd     MOV        BL,byte ptr [ESI + 0x1]
    //         00446b00     MOV        CL,DL
    //         00446b02     CMP        DL,BL
    //         00446b04     JNZ        LAB_00446b1e
    //         00446b06     ADD        EAX,0x2
    //         00446b09     ADD        ESI,0x2
    //         00446b0c     TEST       CL,CL
    //         00446b0e     JNZ        LAB_00446aec
    //                               LAB_00446b10                                                 XREF[1]:     00446af8(j)  
    //         00446b10     XOR        EAX,EAX
    //         00446b12     XOR        ECX,ECX
    //         00446b14     TEST       EAX,EAX
    //         00446b16     SETL       CL
    //         00446b19     MOV        EAX,ECX
    //                              dstring.cpp:165 (3)
    //         00446b1b     POP        ESI
    //         00446b1c     POP        EBX
    //         00446b1d     RET
    //                               LAB_00446b1e                                                 XREF[2]:     00446af4(j), 00446b04(j)  
    //                              dstring.cpp:162 (2)
    //         00446b1e     SBB        EAX,EAX
    //                              dstring.cpp:165 (15)
    //         00446b20     POP        ESI
    //         00446b21     SBB        EAX,-0x1
    //         00446b24     XOR        ECX,ECX
    //         00446b26     TEST       EAX,EAX
    //         00446b28     SETL       CL
    //         00446b2b     MOV        EAX,ECX
    //         00446b2d     POP        EBX
    //         00446b2e     RET
    //         00446b2f     ??         90h
    //                              * int __cdecl operator<(char const *,class DString const &)                                             *
    //                              int __cdecl operator<(char * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446b38(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446b30(R)  
    //                               ??M@YAHPBDABVDString@@@Z
    //                               operator<
    //                              dstring.cpp:167 (59)
    //         00446b30     MOV        EAX,dword ptr [ESP + param_2]
    //         00446b34     PUSH       EBX
    //         00446b35     PUSH       ESI
    //         00446b36     MOV        ESI,dword ptr [EAX]
    //         00446b38     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_00446b3c                                                 XREF[1]:     00446b5e(j)  
    //         00446b3c     MOV        DL,byte ptr [EAX]
    //         00446b3e     MOV        BL,byte ptr [ESI]
    //         00446b40     MOV        CL,DL
    //         00446b42     CMP        DL,BL
    //         00446b44     JNZ        LAB_00446b6e
    //         00446b46     TEST       CL,CL
    //         00446b48     JZ         LAB_00446b60
    //         00446b4a     MOV        DL,byte ptr [EAX + 0x1]
    //         00446b4d     MOV        BL,byte ptr [ESI + 0x1]
    //         00446b50     MOV        CL,DL
    //         00446b52     CMP        DL,BL
    //         00446b54     JNZ        LAB_00446b6e
    //         00446b56     ADD        EAX,0x2
    //         00446b59     ADD        ESI,0x2
    //         00446b5c     TEST       CL,CL
    //         00446b5e     JNZ        LAB_00446b3c
    //                               LAB_00446b60                                                 XREF[1]:     00446b48(j)  
    //         00446b60     XOR        EAX,EAX
    //         00446b62     XOR        ECX,ECX
    //         00446b64     TEST       EAX,EAX
    //         00446b66     SETL       CL
    //         00446b69     MOV        EAX,ECX
    //                              dstring.cpp:171 (3)
    //         00446b6b     POP        ESI
    //         00446b6c     POP        EBX
    //         00446b6d     RET
    //                               LAB_00446b6e                                                 XREF[2]:     00446b44(j), 00446b54(j)  
    //                              dstring.cpp:168 (2)
    //         00446b6e     SBB        EAX,EAX
    //                              dstring.cpp:171 (15)
    //         00446b70     POP        ESI
    //         00446b71     SBB        EAX,-0x1
    //         00446b74     XOR        ECX,ECX
    //         00446b76     TEST       EAX,EAX
    //         00446b78     SETL       CL
    //         00446b7b     MOV        EAX,ECX
    //         00446b7d     POP        EBX
    //         00446b7e     RET
    //         00446b7f     ??         90h
    //                              * int __cdecl operator>(class DString const &,class DString const &)                                    *
    //                              int __cdecl operator>(DString * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446b84(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446b80(R)  
    //                               ??O@YAHABVDString@@0@Z
    //                               operator>
    //                              dstring.cpp:173 (61)
    //         00446b80     MOV        EAX,dword ptr [ESP + param_2]
    //         00446b84     MOV        ECX,dword ptr [ESP + param_1]
    //         00446b88     PUSH       EBX
    //         00446b89     PUSH       ESI
    //         00446b8a     MOV        ESI,dword ptr [EAX]
    //         00446b8c     MOV        EAX,dword ptr [ECX]
    //                               LAB_00446b8e                                                 XREF[1]:     00446bb0(j)  
    //         00446b8e     MOV        DL,byte ptr [EAX]
    //         00446b90     MOV        BL,byte ptr [ESI]
    //         00446b92     MOV        CL,DL
    //         00446b94     CMP        DL,BL
    //         00446b96     JNZ        LAB_00446bc0
    //         00446b98     TEST       CL,CL
    //         00446b9a     JZ         LAB_00446bb2
    //         00446b9c     MOV        DL,byte ptr [EAX + 0x1]
    //         00446b9f     MOV        BL,byte ptr [ESI + 0x1]
    //         00446ba2     MOV        CL,DL
    //         00446ba4     CMP        DL,BL
    //         00446ba6     JNZ        LAB_00446bc0
    //         00446ba8     ADD        EAX,0x2
    //         00446bab     ADD        ESI,0x2
    //         00446bae     TEST       CL,CL
    //         00446bb0     JNZ        LAB_00446b8e
    //                               LAB_00446bb2                                                 XREF[1]:     00446b9a(j)  
    //         00446bb2     XOR        EAX,EAX
    //         00446bb4     XOR        ECX,ECX
    //         00446bb6     TEST       EAX,EAX
    //         00446bb8     SETG       CL
    //         00446bbb     MOV        EAX,ECX
    //                              dstring.cpp:177 (3)
    //         00446bbd     POP        ESI
    //         00446bbe     POP        EBX
    //         00446bbf     RET
    //                               LAB_00446bc0                                                 XREF[2]:     00446b96(j), 00446ba6(j)  
    //                              dstring.cpp:174 (2)
    //         00446bc0     SBB        EAX,EAX
    //                              dstring.cpp:177 (15)
    //         00446bc2     POP        ESI
    //         00446bc3     SBB        EAX,-0x1
    //         00446bc6     XOR        ECX,ECX
    //         00446bc8     TEST       EAX,EAX
    //         00446bca     SETG       CL
    //         00446bcd     MOV        EAX,ECX
    //         00446bcf     POP        EBX
    //         00446bd0     RET
    //         00446bd1     ??         90h
    //         00446bd2     NOP
    //         00446bd3     NOP
    //         00446bd4     NOP
    //         00446bd5     NOP
    //         00446bd6     NOP
    //         00446bd7     NOP
    //         00446bd8     NOP
    //         00446bd9     NOP
    //         00446bda     NOP
    //         00446bdb     NOP
    //         00446bdc     NOP
    //         00446bdd     NOP
    //         00446bde     NOP
    //         00446bdf     NOP
    //                              * int __cdecl operator>(class DString const &,char const *)                                             *
    //                              int __cdecl operator>(DString * param_1, char * param_2)
    //              int               EAX:4          <RETURN>
    //              DString *         Stack[0x4]:4   param_1                   XREF[1]:     00446be0(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     00446be6(R)  
    //                               ??O@YAHABVDString@@PBD@Z
    //                               operator>
    //                              dstring.cpp:179 (59)
    //         00446be0     MOV        EAX,dword ptr [ESP + param_1]
    //         00446be4     PUSH       EBX
    //         00446be5     PUSH       ESI
    //         00446be6     MOV        ESI,dword ptr [ESP + param_2]
    //         00446bea     MOV        EAX,dword ptr [EAX]
    //                               LAB_00446bec                                                 XREF[1]:     00446c0e(j)  
    //         00446bec     MOV        DL,byte ptr [EAX]
    //         00446bee     MOV        BL,byte ptr [ESI]
    //         00446bf0     MOV        CL,DL
    //         00446bf2     CMP        DL,BL
    //         00446bf4     JNZ        LAB_00446c1e
    //         00446bf6     TEST       CL,CL
    //         00446bf8     JZ         LAB_00446c10
    //         00446bfa     MOV        DL,byte ptr [EAX + 0x1]
    //         00446bfd     MOV        BL,byte ptr [ESI + 0x1]
    //         00446c00     MOV        CL,DL
    //         00446c02     CMP        DL,BL
    //         00446c04     JNZ        LAB_00446c1e
    //         00446c06     ADD        EAX,0x2
    //         00446c09     ADD        ESI,0x2
    //         00446c0c     TEST       CL,CL
    //         00446c0e     JNZ        LAB_00446bec
    //                               LAB_00446c10                                                 XREF[1]:     00446bf8(j)  
    //         00446c10     XOR        EAX,EAX
    //         00446c12     XOR        ECX,ECX
    //         00446c14     TEST       EAX,EAX
    //         00446c16     SETG       CL
    //         00446c19     MOV        EAX,ECX
    //                              dstring.cpp:183 (3)
    //         00446c1b     POP        ESI
    //         00446c1c     POP        EBX
    //         00446c1d     RET
    //                               LAB_00446c1e                                                 XREF[2]:     00446bf4(j), 00446c04(j)  
    //                              dstring.cpp:180 (2)
    //         00446c1e     SBB        EAX,EAX
    //                              dstring.cpp:183 (15)
    //         00446c20     POP        ESI
    //         00446c21     SBB        EAX,-0x1
    //         00446c24     XOR        ECX,ECX
    //         00446c26     TEST       EAX,EAX
    //         00446c28     SETG       CL
    //         00446c2b     MOV        EAX,ECX
    //         00446c2d     POP        EBX
    //         00446c2e     RET
    //         00446c2f     ??         90h
    //                              * int __cdecl operator>(char const *,class DString const &)                                             *
    //                              int __cdecl operator>(char * param_1, DString * param_2)
    //              int               EAX:4          <RETURN>
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446c38(R)  
    //              DString *         Stack[0x8]:4   param_2                   XREF[1]:     00446c30(R)  
    //                               ??O@YAHPBDABVDString@@@Z
    //                               operator>
    //                              dstring.cpp:185 (59)
    //         00446c30     MOV        EAX,dword ptr [ESP + param_2]
    //         00446c34     PUSH       EBX
    //         00446c35     PUSH       ESI
    //         00446c36     MOV        ESI,dword ptr [EAX]
    //         00446c38     MOV        EAX,dword ptr [ESP + param_1]
    //                               LAB_00446c3c                                                 XREF[1]:     00446c5e(j)  
    //         00446c3c     MOV        DL,byte ptr [EAX]
    //         00446c3e     MOV        BL,byte ptr [ESI]
    //         00446c40     MOV        CL,DL
    //         00446c42     CMP        DL,BL
    //         00446c44     JNZ        LAB_00446c6e
    //         00446c46     TEST       CL,CL
    //         00446c48     JZ         LAB_00446c60
    //         00446c4a     MOV        DL,byte ptr [EAX + 0x1]
    //         00446c4d     MOV        BL,byte ptr [ESI + 0x1]
    //         00446c50     MOV        CL,DL
    //         00446c52     CMP        DL,BL
    //         00446c54     JNZ        LAB_00446c6e
    //         00446c56     ADD        EAX,0x2
    //         00446c59     ADD        ESI,0x2
    //         00446c5c     TEST       CL,CL
    //         00446c5e     JNZ        LAB_00446c3c
    //                               LAB_00446c60                                                 XREF[1]:     00446c48(j)  
    //         00446c60     XOR        EAX,EAX
    //         00446c62     XOR        ECX,ECX
    //         00446c64     TEST       EAX,EAX
    //         00446c66     SETG       CL
    //         00446c69     MOV        EAX,ECX
    //                              dstring.cpp:189 (3)
    //         00446c6b     POP        ESI
    //         00446c6c     POP        EBX
    //         00446c6d     RET
    //                               LAB_00446c6e                                                 XREF[2]:     00446c44(j), 00446c54(j)  
    //                              dstring.cpp:186 (2)
    //         00446c6e     SBB        EAX,EAX
    //                              dstring.cpp:189 (15)
    //         00446c70     POP        ESI
    //         00446c71     SBB        EAX,-0x1
    //         00446c74     XOR        ECX,ECX
    //         00446c76     TEST       EAX,EAX
    //         00446c78     SETG       CL
    //         00446c7b     MOV        EAX,ECX
    //         00446c7d     POP        EBX
    //         00446c7e     RET
    //         00446c7f     ??         90h
    //                              * public: class DString __thiscall DString::operator+(class DString const &)const                       *
    //                              DString __thiscall operator+(DString * this, DString * __return_stor
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     00446ccf(R)  
    //              DString *         Stack[0x8]:4   param_1                   XREF[1]:     00446cab(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00446cb9(W), 00446ceb(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00446cf5(R)  
    //              DString           Stack[-0x24]   newStr                    XREF[1,4]:   00446cb4(W), 00446c9a(*), 00446cc6(*), 00446cd3(*), 
    //                                                                                     00446ce7(*)  
    //              undefined4        Stack[-0x28]:4 local_28                  XREF[2]:     00446c9e(W), 00446cdf(W)  
    //                               ??HDString@@QBE?AV0@ABV0@@Z
    //                               DString::operator+
    //                              dstring.cpp:191 (25)
    //         00446c80     PUSH       -0x1
    //         00446c82     PUSH       FUN_0055d35f
    //         00446c87     MOV        EAX,FS:[0x0]
    //         00446c8d     PUSH       EAX
    //         00446c8e     MOV        dword ptr FS:[0x0],ESP
    //         00446c95     SUB        ESP,0x1c
    //         00446c98     PUSH       ESI
    //                              dstring.cpp:192 (18)
    //         00446c99     PUSH       this
    //         00446c9a     LEA        this=>newStr.lengthValue,[ESP + 0x10]
    //         00446c9e     MOV        dword ptr [ESP + local_28],0x0
    //         00446ca6     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //                              dstring.cpp:193 (36)
    //         00446cab     MOV        EAX,dword ptr [ESP + param_1]
    //         00446caf     SUB        ESP,0x14
    //         00446cb2     MOV        this,ESP
    //         00446cb4     MOV        dword ptr [ESP + newStr.stringValue],ESP
    //         00446cb8     PUSH       EAX
    //         00446cb9     MOV        dword ptr [ESP + local_4],0x1
    //         00446cc1     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00446cc6     LEA        this=>newStr.lengthValue,[ESP + 0x20]
    //         00446cca     CALL       DString::append                                  void append(DString * this, DString param_1)
    //                              dstring.cpp:194 (38)
    //         00446ccf     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00446cd3     LEA        this=>newStr.lengthValue,[ESP + 0xc]
    //         00446cd7     PUSH       this
    //         00446cd8     MOV        this,ESI
    //         00446cda     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00446cdf     MOV        dword ptr [ESP + local_28],0x1
    //         00446ce7     LEA        this=>newStr.lengthValue,[ESP + 0xc]
    //         00446ceb     MOV        byte ptr [ESP + local_4],0x0
    //         00446cf0     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:195 (20)
    //         00446cf5     MOV        this,dword ptr [ESP + local_c]
    //         00446cf9     MOV        EAX,ESI
    //         00446cfb     MOV        dword ptr FS:[0x0],this
    //         00446d02     POP        ESI
    //         00446d03     ADD        ESP,0x28
    //         00446d06     RET        0x8
    //         00446d09     ??         90h
    //         00446d0a     NOP
    //         00446d0b     NOP
    //         00446d0c     NOP
    //         00446d0d     NOP
    //         00446d0e     NOP
    //         00446d0f     NOP
    return 0;
}

char* DString::operator[](int param_1) {
    /* TODO: Stub */
    //                              char * __thiscall operator[](DString * this, int param_1)
    //              char *            EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00446d10(R)  
    //                               ??ADString@@QAEAADH@Z                                        XREF[1]:     append:00447260(c)  
    //                               DString::operator[]
    //                              dstring.cpp:197 (19)
    //         00446d10     MOV        EAX,dword ptr [ESP + param_1]
    //         00446d14     PUSH       ESI
    //         00446d15     TEST       EAX,EAX
    //         00446d17     JL         LAB_00446d29
    //         00446d19     MOV        ESI,dword ptr [ECX + this->lengthValue]
    //         00446d1c     LEA        EDX,[EAX + 0x1]
    //         00446d1f     CMP        ESI,EDX
    //         00446d21     JL         LAB_00446d29
    //                              dstring.cpp:201 (2)
    //         00446d23     ADD        EAX,dword ptr [this->stringValue]
    //                              dstring.cpp:202 (4)
    //         00446d25     POP        ESI
    //         00446d26     RET        0x4
    //                               LAB_00446d29                                                 XREF[2]:     00446d17(j), 00446d21(j)  
    //                              dstring.cpp:200 (2)
    //         00446d29     MOV        EAX,dword ptr [this->stringValue]
    //                              dstring.cpp:202 (4)
    //         00446d2b     POP        ESI
    //         00446d2c     RET        0x4
    //         00446d2f     ??         90h
    //                              * public: __thiscall DString::operator char *(void)const                                                *
    //                              char * __thiscall operator_char*(DString * this)
    //              char *            EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ??BDString@@QBEPADXZ                                         XREF[1]:     contains:00446d84(c)  
    //                               DString::operator_char*
    //                              dstring.cpp:204 (2)
    //         00446d30     MOV        EAX,dword ptr [this->stringValue]
    //                              dstring.cpp:206 (1)
    //         00446d32     RET
    //         00446d33     ??         90h
    //         00446d34     NOP
    //         00446d35     NOP
    //         00446d36     NOP
    //         00446d37     NOP
    //         00446d38     NOP
    //         00446d39     NOP
    //         00446d3a     NOP
    //         00446d3b     NOP
    //         00446d3c     NOP
    //         00446d3d     NOP
    //         00446d3e     NOP
    //         00446d3f     NOP
    //                              * public: int __thiscall DString::length(void)const                                                     *
    //                              int __thiscall length(DString * this)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?length@DString@@QBEHXZ                                      XREF[8]:     append:00447215(c), 
    //                               DString::length                                                           append:0044724c(c), 
    //                                                                                                         append:00447272(c), 
    //                                                                                                         append:00447292(c), 
    //                                                                                                         uppercase:00447426(c), 
    //                                                                                                         uppercase:00447446(c), 
    //                                                                                                         lowercase:004474e6(c), 
    //                                                                                                         lowercase:00447506(c)  
    //                              dstring.cpp:208 (3)
    //         00446d40     MOV        EAX,dword ptr [ECX + this->lengthValue]
    //                              dstring.cpp:210 (1)
    //         00446d43     RET
    //         00446d44     ??         90h
    //         00446d45     NOP
    //         00446d46     NOP
    //         00446d47     NOP
    //         00446d48     NOP
    //         00446d49     NOP
    //         00446d4a     NOP
    //         00446d4b     NOP
    //         00446d4c     NOP
    //         00446d4d     NOP
    //         00446d4e     NOP
    //         00446d4f     NOP
    //                              * public: int __thiscall DString::index(void)const                                                      *
    //                              int __thiscall index(DString * this)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?index@DString@@QBEHXZ
    //                               DString::index
    //                              dstring.cpp:212 (3)
    //         00446d50     MOV        EAX,dword ptr [ECX + this->indexValue]
    //                              dstring.cpp:214 (1)
    //         00446d53     RET
    //         00446d54     ??         90h
    //         00446d55     NOP
    //         00446d56     NOP
    //         00446d57     NOP
    //         00446d58     NOP
    //         00446d59     NOP
    //         00446d5a     NOP
    //         00446d5b     NOP
    //         00446d5c     NOP
    //         00446d5d     NOP
    //         00446d5e     NOP
    //         00446d5f     NOP
    //                              * public: int __thiscall DString::contains(class DString)const                                          *
    //                              int __thiscall contains(DString * this, DString param_1)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString           Stack[0x4]:20  param_1                   XREF[2]:     00446d78(*), 00446d9f(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00446d7c(W), 00446d95(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00446daf(R), 00446dc6(R)  
    //                               ?contains@DString@@QBEHV1@@Z
    //                               DString::contains
    //                              dstring.cpp:216 (24)
    //         00446d60     MOV        EAX,FS:[0x0]
    //         00446d66     PUSH       -0x1
    //         00446d68     PUSH       FUN_0055d378
    //         00446d6d     PUSH       EAX
    //         00446d6e     MOV        dword ptr FS:[0x0],ESP
    //         00446d75     PUSH       ESI
    //         00446d76     MOV        ESI,this
    //                              dstring.cpp:217 (29)
    //         00446d78     LEA        this=>param_1,[ESP + 0x14]
    //         00446d7c     MOV        dword ptr [ESP + local_4],0x0
    //         00446d84     CALL       DString::operator_char*                          char * operator_char*(DString * this)
    //         00446d89     PUSH       EAX
    //         00446d8a     MOV        EAX,dword ptr [ESI]
    //         00446d8c     PUSH       EAX
    //         00446d8d     CALL       strstr                                           undefined strstr()
    //         00446d92     ADD        ESP,0x8
    //                              dstring.cpp:218 (26)
    //         00446d95     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00446d9d     TEST       EAX,EAX
    //         00446d9f     LEA        this=>param_1,[ESP + 0x14]
    //         00446da3     JZ         LAB_00446dc1
    //         00446da5     CALL       DString::~DString                                void ~DString(DString * this)
    //         00446daa     MOV        EAX,0x1
    //                              dstring.cpp:220 (43)
    //         00446daf     MOV        this,dword ptr [ESP + local_c]
    //         00446db3     MOV        dword ptr FS:[0x0],this
    //         00446dba     POP        ESI
    //         00446dbb     ADD        ESP,0xc
    //         00446dbe     RET        0x14
    //                               LAB_00446dc1                                                 XREF[1]:     00446da3(j)  
    //         00446dc1     CALL       DString::~DString                                void ~DString(DString * this)
    //         00446dc6     MOV        this,dword ptr [ESP + local_c]
    //         00446dca     XOR        EAX,EAX
    //         00446dcc     MOV        dword ptr FS:[0x0],this
    //         00446dd3     POP        ESI
    //         00446dd4     ADD        ESP,0xc
    //         00446dd7     RET        0x14
    //         00446dda     ??         90h
    //         00446ddb     NOP
    //         00446ddc     NOP
    //         00446ddd     NOP
    //         00446dde     NOP
    //         00446ddf     NOP
    //                              * public: int __thiscall DString::contains(char const *)const                                           *
    //                              int __thiscall contains(DString * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00446de0(R)  
    //                               ?contains@DString@@QBEHPBD@Z
    //                               DString::contains
    //                              dstring.cpp:222 (22)
    //         00446de0     MOV        EAX,dword ptr [ESP + param_1]
    //         00446de4     MOV        this,dword ptr [this->stringValue]
    //         00446de6     PUSH       EAX
    //         00446de7     PUSH       this
    //         00446de8     CALL       strstr                                           undefined strstr()
    //         00446ded     ADD        ESP,0x8
    //         00446df0     NEG        EAX
    //         00446df2     SBB        EAX,EAX
    //         00446df4     NEG        EAX
    //                              dstring.cpp:226 (3)
    //         00446df6     RET        0x4
    //         00446df9     ??         90h
    //         00446dfa     NOP
    //         00446dfb     NOP
    //         00446dfc     NOP
    //         00446dfd     NOP
    //         00446dfe     NOP
    //         00446dff     NOP
    return 0;
}

int DString::numWords() {
    /* TODO: Stub */
    //                              int __thiscall numWords(DString * this)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?numWords@DString@@QAEHXZ                                    XREF[1]:     word:00446eb4(c)  
    //                               DString::numWords
    //                              dstring.cpp:228 (5)
    //         00446e00     PUSH       EBX
    //         00446e01     PUSH       ESI
    //         00446e02     MOV        ESI,this
    //         00446e04     PUSH       EDI
    //                              dstring.cpp:229 (6)
    //         00446e05     MOV        EAX,dword ptr [ESI + 0x8]
    //         00446e08     CMP        EAX,-0x1
    //                              dstring.cpp:230 (2)
    //         00446e0b     JNZ        LAB_00446e81
    //                              dstring.cpp:232 (7)
    //         00446e0d     MOV        EAX,dword ptr [ESI + 0x4]
    //         00446e10     TEST       EAX,EAX
    //         00446e12     JNZ        LAB_00446e18
    //                              dstring.cpp:254 (4)
    //         00446e14     POP        EDI
    //         00446e15     POP        ESI
    //         00446e16     POP        EBX
    //         00446e17     RET
    //                               LAB_00446e18                                                 XREF[1]:     00446e12(j)  
    //                              dstring.cpp:236 (7)
    //         00446e18     MOV        this,dword ptr [ESI]
    //         00446e1a     CMP        byte ptr [this->stringValue],0x20
    //         00446e1d     JNZ        LAB_00446e2a
    //                              dstring.cpp:237 (7)
    //         00446e1f     MOV        dword ptr [ESI + 0x8],0x0
    //                              dstring.cpp:238 (2)
    //         00446e26     XOR        EBX,EBX
    //                              dstring.cpp:240 (2)
    //         00446e28     JMP        LAB_00446e36
    //                               LAB_00446e2a                                                 XREF[1]:     00446e1d(j)  
    //                              dstring.cpp:241 (7)
    //         00446e2a     MOV        dword ptr [ESI + 0x8],0x1
    //                              dstring.cpp:242 (5)
    //         00446e31     MOV        EBX,0x1
    //                               LAB_00446e36                                                 XREF[1]:     00446e28(j)  
    //                              dstring.cpp:245 (6)
    //         00446e36     XOR        EDI,EDI
    //         00446e38     TEST       EAX,EAX
    //         00446e3a     JLE        LAB_00446e7e
    //                               LAB_00446e3c                                                 XREF[1]:     00446e7c(j)  
    //                              dstring.cpp:246 (23)
    //         00446e3c     TEST       EBX,EBX
    //         00446e3e     JNZ        LAB_00446e61
    //         00446e40     MOV        EDX,dword ptr [ESI]
    //         00446e42     MOVSX      EAX,byte ptr [EDI + EDX*0x1]
    //         00446e46     PUSH       EAX
    //         00446e47     CALL       isspace                                          undefined isspace()
    //         00446e4c     ADD        ESP,0x4
    //         00446e4f     TEST       EAX,EAX
    //         00446e51     JNZ        LAB_00446e61
    //                              dstring.cpp:247 (3)
    //         00446e53     MOV        EAX,dword ptr [ESI + 0x8]
    //                              dstring.cpp:248 (9)
    //         00446e56     MOV        EBX,0x1
    //         00446e5b     INC        EAX
    //         00446e5c     MOV        dword ptr [ESI + 0x8],EAX
    //                              dstring.cpp:250 (21)
    //         00446e5f     JMP        LAB_00446e76
    //                               LAB_00446e61                                                 XREF[2]:     00446e3e(j), 00446e51(j)  
    //         00446e61     MOV        this,dword ptr [ESI]
    //         00446e63     MOVSX      EDX,byte ptr [EDI + this->stringValue*0x1]
    //         00446e67     PUSH       EDX
    //         00446e68     CALL       isspace                                          undefined isspace()
    //         00446e6d     ADD        ESP,0x4
    //         00446e70     TEST       EAX,EAX
    //         00446e72     JZ         LAB_00446e76
    //                              dstring.cpp:251 (2)
    //         00446e74     XOR        EBX,EBX
    //                               LAB_00446e76                                                 XREF[2]:     00446e5f(j), 00446e72(j)  
    //                              dstring.cpp:245 (8)
    //         00446e76     MOV        EAX,dword ptr [ESI + 0x4]
    //         00446e79     INC        EDI
    //         00446e7a     CMP        EDI,EAX
    //         00446e7c     JL         LAB_00446e3c
    //                               LAB_00446e7e                                                 XREF[1]:     00446e3a(j)  
    //                              dstring.cpp:253 (3)
    //         00446e7e     MOV        EAX,dword ptr [ESI + 0x8]
    //                               LAB_00446e81                                                 XREF[1]:     00446e0b(j)  
    //                              dstring.cpp:254 (4)
    //         00446e81     POP        EDI
    //         00446e82     POP        ESI
    //         00446e83     POP        EBX
    //         00446e84     RET
    //         00446e85     ??         90h
    //         00446e86     NOP
    //         00446e87     NOP
    //         00446e88     NOP
    //         00446e89     NOP
    //         00446e8a     NOP
    //         00446e8b     NOP
    //         00446e8c     NOP
    //         00446e8d     NOP
    //         00446e8e     NOP
    //         00446e8f     NOP
    return 0;
}

DString* DString::word(int param_1) {
    /* TODO: Stub */
    //                              DString __thiscall word(DString * this, DString * __return_storage_p
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[3]:     00446ed6(R), 00446f7b(R), 00446fa6(R)  
    //              int               Stack[0x8]:4   param_1                   XREF[3]:     00446eb9(R), 00446f2d(R), 00446f36(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00446f86(W), 00446f97(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00446fb6(R)  
    //              DString           Stack[-0x24]   rStr                      XREF[1,3]:   00446eb0(W), 00446f6d(*), 00446f7f(*), 00446f93(*)  
    //                               ?word@DString@@QAE?AV1@H@Z
    //                               DString::word
    //                              dstring.cpp:256 (36)
    //         00446e90     PUSH       -0x1
    //         00446e92     PUSH       FUN_0055d398
    //         00446e97     MOV        EAX,FS:[0x0]
    //         00446e9d     PUSH       EAX
    //         00446e9e     MOV        dword ptr FS:[0x0],ESP
    //         00446ea5     SUB        ESP,0x18
    //         00446ea8     PUSH       EBX
    //         00446ea9     PUSH       EBP
    //         00446eaa     PUSH       ESI
    //         00446eab     PUSH       EDI
    //         00446eac     XOR        EBP,EBP
    //         00446eae     MOV        EDI,this
    //         00446eb0     MOV        dword ptr [ESP + rStr.stringValue],EBP
    //                              dstring.cpp:257 (26)
    //         00446eb4     CALL       DString::numWords                                int numWords(DString * this)
    //         00446eb9     MOV        this,dword ptr [ESP + param_1]
    //         00446ebd     CMP        this,EAX
    //         00446ebf     JG         LAB_00446fa6
    //         00446ec5     CMP        this,0x1
    //         00446ec8     JL         LAB_00446fa6
    //                              dstring.cpp:260 (8)
    //         00446ece     MOV        EAX,dword ptr [EDI + 0x10]
    //         00446ed1     INC        EAX
    //         00446ed2     CMP        this,EAX
    //         00446ed4     JNZ        LAB_00446eec
    //                              dstring.cpp:262 (22)
    //         00446ed6     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00446eda     PUSH       0x1
    //         00446edc     PUSH       ESI
    //         00446edd     MOV        this,EDI
    //         00446edf     MOV        dword ptr [EDI + 0x10],EAX
    //         00446ee2     CALL       DString::nextWord                                DString * nextWord(DString * this, DString * 
    //         00446ee7     JMP        LAB_00446fb6
    //                               LAB_00446eec                                                 XREF[1]:     00446ed4(j)  
    //                              dstring.cpp:269 (13)
    //         00446eec     XOR        ESI,ESI
    //         00446eee     XOR        EBX,EBX
    //         00446ef0     TEST       this,this
    //         00446ef2     JZ         LAB_00446f36
    //                               LAB_00446ef4                                                 XREF[1]:     00446f34(j)  
    //         00446ef4     CMP        ESI,dword ptr [EDI + 0x4]
    //         00446ef7     JGE        LAB_00446f36
    //                              dstring.cpp:270 (23)
    //         00446ef9     TEST       EBX,EBX
    //         00446efb     JNZ        LAB_00446f18
    //         00446efd     MOV        EAX,dword ptr [EDI]
    //         00446eff     MOVSX      this,byte ptr [ESI + EAX*0x1]
    //         00446f03     PUSH       this
    //         00446f04     CALL       isspace                                          undefined isspace()
    //         00446f09     ADD        ESP,0x4
    //         00446f0c     TEST       EAX,EAX
    //         00446f0e     JNZ        LAB_00446f18
    //                              dstring.cpp:271 (1)
    //         00446f10     INC        EBP
    //                              dstring.cpp:272 (5)
    //         00446f11     MOV        EBX,0x1
    //                              dstring.cpp:274 (21)
    //         00446f16     JMP        LAB_00446f2d
    //                               LAB_00446f18                                                 XREF[2]:     00446efb(j), 00446f0e(j)  
    //         00446f18     MOV        EDX,dword ptr [EDI]
    //         00446f1a     MOVSX      EAX,byte ptr [ESI + EDX*0x1]
    //         00446f1e     PUSH       EAX
    //         00446f1f     CALL       isspace                                          undefined isspace()
    //         00446f24     ADD        ESP,0x4
    //         00446f27     TEST       EAX,EAX
    //         00446f29     JZ         LAB_00446f2d
    //                              dstring.cpp:275 (2)
    //         00446f2b     XOR        EBX,EBX
    //                               LAB_00446f2d                                                 XREF[2]:     00446f16(j), 00446f29(j)  
    //                              dstring.cpp:269 (4)
    //         00446f2d     MOV        EAX,dword ptr [ESP + param_1]
    //                              dstring.cpp:277 (5)
    //         00446f31     INC        ESI
    //         00446f32     CMP        EBP,EAX
    //         00446f34     JNZ        LAB_00446ef4
    //                               LAB_00446f36                                                 XREF[2]:     00446ef2(j), 00446ef7(j)  
    //                              dstring.cpp:281 (6)
    //         00446f36     CMP        EBP,dword ptr [ESP + param_1]
    //         00446f3a     JNZ        LAB_00446fa6
    //                              dstring.cpp:283 (29)
    //         00446f3c     MOV        this,dword ptr [EDI]
    //         00446f3e     LEA        EBX,[ESI + -0x1]
    //         00446f41     MOVSX      EDX,byte ptr [ESI + this->stringValue*0x1]
    //         00446f45     PUSH       EDX
    //         00446f46     CALL       isspace                                          undefined isspace()
    //         00446f4b     ADD        ESP,0x4
    //         00446f4e     TEST       EAX,EAX
    //         00446f50     JNZ        LAB_00446f6b
    //                               LAB_00446f52                                                 XREF[1]:     00446f69(j)  
    //         00446f52     CMP        ESI,dword ptr [EDI + 0x4]
    //         00446f55     JGE        LAB_00446f6b
    //         00446f57     MOV        EAX,dword ptr [EDI]
    //                              dstring.cpp:284 (18)
    //         00446f59     INC        ESI
    //         00446f5a     MOVSX      this,byte ptr [ESI + EAX*0x1]
    //         00446f5e     PUSH       this
    //         00446f5f     CALL       isspace                                          undefined isspace()
    //         00446f64     ADD        ESP,0x4
    //         00446f67     TEST       EAX,EAX
    //         00446f69     JZ         LAB_00446f52
    //                               LAB_00446f6b                                                 XREF[2]:     00446f50(j), 00446f55(j)  
    //                              dstring.cpp:286 (16)
    //         00446f6b     SUB        ESI,EBX
    //         00446f6d     LEA        EDX=>rStr.lengthValue,[ESP + 0x14]
    //         00446f71     PUSH       ESI
    //         00446f72     PUSH       EBX
    //         00446f73     PUSH       EDX
    //         00446f74     MOV        this,EDI
    //         00446f76     CALL       DString::subString                               DString * subString(DString * this, DString *
    //                              dstring.cpp:287 (43)
    //         00446f7b     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00446f7f     LEA        EAX=>rStr.lengthValue,[ESP + 0x14]
    //         00446f83     PUSH       EAX
    //         00446f84     MOV        this,ESI
    //         00446f86     MOV        dword ptr [ESP + local_4],0x0
    //         00446f8e     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00446f93     LEA        this=>rStr.lengthValue,[ESP + 0x14]
    //         00446f97     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00446f9f     CALL       DString::~DString                                void ~DString(DString * this)
    //         00446fa4     JMP        LAB_00446fb6
    //                               LAB_00446fa6                                                 XREF[3]:     00446ebf(j), 00446ec8(j), 
    //                                                                                                         00446f3a(j)  
    //                              dstring.cpp:258 (16)
    //         00446fa6     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00446faa     PUSH       s_                                               = ""
    //         00446faf     MOV        this,ESI
    //         00446fb1     CALL       DString::DString                                 undefined DString(DString * this, char * para
    //                               LAB_00446fb6                                                 XREF[2]:     00446ee7(j), 00446fa4(j)  
    //                              dstring.cpp:291 (23)
    //         00446fb6     MOV        this,dword ptr [ESP + local_c]
    //         00446fba     MOV        EAX,ESI
    //         00446fbc     POP        EDI
    //         00446fbd     POP        ESI
    //         00446fbe     POP        EBP
    //         00446fbf     MOV        dword ptr FS:[0x0],this
    //         00446fc6     POP        EBX
    //         00446fc7     ADD        ESP,0x24
    //         00446fca     RET        0x8
    //         00446fcd     ??         90h
    //         00446fce     NOP
    //         00446fcf     NOP
    return 0;
}

DString* DString::nextWord(int param_1) {
    /* TODO: Stub */
    //                              DString __thiscall nextWord(DString * this, DString * __return_stora
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0044706d(R)  
    //              int               Stack[0x8]:4   param_1                   XREF[1]:     00447052(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044707d(W), 0044708e(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00447098(R)  
    //              DString           Stack[-0x24]   rStr                      XREF[2,3]:   00446fed(W), 00447086(W), 0044705f(*), 00447071(*), 
    //                                                                                     0044708a(*)  
    //                               ?nextWord@DString@@QAE?AV1@H@Z                               XREF[1]:     word:00446ee2(c)  
    //                               DString::nextWord
    //                              dstring.cpp:293 (37)
    //         00446fd0     PUSH       -0x1
    //         00446fd2     PUSH       FUN_0055d3cf
    //         00446fd7     MOV        EAX,FS:[0x0]
    //         00446fdd     PUSH       EAX
    //         00446fde     MOV        dword ptr FS:[0x0],ESP
    //         00446fe5     SUB        ESP,0x18
    //         00446fe8     PUSH       EBP
    //         00446fe9     PUSH       ESI
    //         00446fea     PUSH       EDI
    //         00446feb     MOV        EDI,this
    //         00446fed     MOV        dword ptr [ESP + rStr.stringValue],0x0
    //                              dstring.cpp:294 (3)
    //         00446ff5     MOV        ESI,dword ptr [EDI + 0xc]
    //                              dstring.cpp:297 (26)
    //         00446ff8     MOV        EAX,dword ptr [EDI]
    //         00446ffa     MOVSX      this,byte ptr [ESI + EAX*0x1]
    //         00446ffe     PUSH       this
    //         00446fff     CALL       isspace                                          undefined isspace()
    //         00447004     ADD        ESP,0x4
    //         00447007     TEST       EAX,EAX
    //         00447009     JZ         LAB_00447024
    //                               LAB_0044700b                                                 XREF[1]:     00447022(j)  
    //         0044700b     CMP        ESI,dword ptr [EDI + 0x4]
    //         0044700e     JGE        LAB_00447024
    //         00447010     MOV        EDX,dword ptr [EDI]
    //                              dstring.cpp:298 (18)
    //         00447012     INC        ESI
    //         00447013     MOVSX      EAX,byte ptr [ESI + EDX*0x1]
    //         00447017     PUSH       EAX
    //         00447018     CALL       isspace                                          undefined isspace()
    //         0044701d     ADD        ESP,0x4
    //         00447020     TEST       EAX,EAX
    //         00447022     JNZ        LAB_0044700b
    //                               LAB_00447024                                                 XREF[2]:     00447009(j), 0044700e(j)  
    //                              dstring.cpp:303 (28)
    //         00447024     MOV        this,dword ptr [EDI]
    //         00447026     MOV        EBP,ESI
    //         00447028     MOVSX      EDX,byte ptr [ESI + this->stringValue*0x1]
    //         0044702c     PUSH       EDX
    //         0044702d     CALL       isspace                                          undefined isspace()
    //         00447032     ADD        ESP,0x4
    //         00447035     TEST       EAX,EAX
    //         00447037     JNZ        LAB_00447052
    //                               LAB_00447039                                                 XREF[1]:     00447050(j)  
    //         00447039     CMP        ESI,dword ptr [EDI + 0x4]
    //         0044703c     JGE        LAB_00447052
    //         0044703e     MOV        EAX,dword ptr [EDI]
    //                              dstring.cpp:304 (18)
    //         00447040     INC        ESI
    //         00447041     MOVSX      this,byte ptr [ESI + EAX*0x1]
    //         00447045     PUSH       this
    //         00447046     CALL       isspace                                          undefined isspace()
    //         0044704b     ADD        ESP,0x4
    //         0044704e     TEST       EAX,EAX
    //         00447050     JZ         LAB_00447039
    //                               LAB_00447052                                                 XREF[2]:     00447037(j), 0044703c(j)  
    //                              dstring.cpp:306 (8)
    //         00447052     MOV        EAX,dword ptr [ESP + param_1]
    //         00447056     TEST       EAX,EAX
    //         00447058     JZ         LAB_0044705d
    //                              dstring.cpp:307 (3)
    //         0044705a     MOV        dword ptr [EDI + 0xc],ESI
    //                               LAB_0044705d                                                 XREF[1]:     00447058(j)  
    //                              dstring.cpp:309 (16)
    //         0044705d     SUB        ESI,EBP
    //         0044705f     LEA        EDX=>rStr.lengthValue,[ESP + 0x10]
    //         00447063     PUSH       ESI
    //         00447064     PUSH       EBP
    //         00447065     PUSH       EDX
    //         00447066     MOV        this,EDI
    //         00447068     CALL       DString::subString                               DString * subString(DString * this, DString *
    //                              dstring.cpp:310 (43)
    //         0044706d     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00447071     LEA        EAX=>rStr.lengthValue,[ESP + 0x10]
    //         00447075     MOV        EDI,0x1
    //         0044707a     PUSH       EAX
    //         0044707b     MOV        this,ESI
    //         0044707d     MOV        dword ptr [ESP + local_4],EDI
    //         00447081     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00447086     MOV        dword ptr [ESP + rStr.stringValue],EDI
    //         0044708a     LEA        this=>rStr.lengthValue,[ESP + 0x10]
    //         0044708e     MOV        byte ptr [ESP + local_4],0x0
    //         00447093     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:311 (22)
    //         00447098     MOV        this,dword ptr [ESP + local_c]
    //         0044709c     MOV        EAX,ESI
    //         0044709e     POP        EDI
    //         0044709f     POP        ESI
    //         004470a0     MOV        dword ptr FS:[0x0],this
    //         004470a7     POP        EBP
    //         004470a8     ADD        ESP,0x24
    //         004470ab     RET        0x8
    //         004470ae     ??         90h
    //         004470af     NOP
    return 0;
}

void DString::moveToFirstWord() {
    /* TODO: Stub */
    //                              void __thiscall moveToFirstWord(DString * this)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?moveToFirstWord@DString@@QAEXXZ
    //                               DString::moveToFirstWord
    //                              dstring.cpp:313 (5)
    //         004470b0     XOR        EAX,EAX
    //         004470b2     MOV        dword ptr [ECX + this->indexValue],EAX
    //                              dstring.cpp:315 (3)
    //         004470b5     MOV        dword ptr [ECX + this->currentWordValue],EAX
    //                              dstring.cpp:316 (1)
    //         004470b8     RET
    //         004470b9     ??         90h
    //         004470ba     NOP
    //         004470bb     NOP
    //         004470bc     NOP
    //         004470bd     NOP
    //         004470be     NOP
    //         004470bf     NOP
    return;
}

void DString::moveToNextWord() {
    /* TODO: Stub */
    //                              void __thiscall moveToNextWord(DString * this)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?moveToNextWord@DString@@QAEXXZ
    //                               DString::moveToNextWord
    //                              dstring.cpp:318 (3)
    //         004470c0     PUSH       ESI
    //         004470c1     MOV        ESI,this
    //                              dstring.cpp:320 (34)
    //         004470c3     MOV        EAX,dword ptr [ESI]
    //         004470c5     MOV        this,dword ptr [ESI + 0xc]
    //         004470c8     MOVSX      EDX,byte ptr [EAX + this->stringValue*0x1]
    //         004470cc     PUSH       EDX
    //         004470cd     CALL       isspace                                          undefined isspace()
    //         004470d2     ADD        ESP,0x4
    //         004470d5     TEST       EAX,EAX
    //         004470d7     JZ         LAB_004470fa
    //                               LAB_004470d9                                                 XREF[1]:     004470f8(j)  
    //         004470d9     MOV        EAX,dword ptr [ESI + 0xc]
    //         004470dc     MOV        this,dword ptr [ESI + 0x4]
    //         004470df     CMP        EAX,this
    //         004470e1     JGE        LAB_004470fa
    //         004470e3     MOV        this,dword ptr [ESI]
    //                              dstring.cpp:321 (21)
    //         004470e5     INC        EAX
    //         004470e6     MOV        dword ptr [ESI + 0xc],EAX
    //         004470e9     MOVSX      EDX,byte ptr [this->stringValue + EAX*0x1]
    //         004470ed     PUSH       EDX
    //         004470ee     CALL       isspace                                          undefined isspace()
    //         004470f3     ADD        ESP,0x4
    //         004470f6     TEST       EAX,EAX
    //         004470f8     JNZ        LAB_004470d9
    //                               LAB_004470fa                                                 XREF[2]:     004470d7(j), 004470e1(j)  
    //                              dstring.cpp:324 (34)
    //         004470fa     MOV        EAX,dword ptr [ESI]
    //         004470fc     MOV        this,dword ptr [ESI + 0xc]
    //         004470ff     MOVSX      EDX,byte ptr [EAX + this->stringValue*0x1]
    //         00447103     PUSH       EDX
    //         00447104     CALL       isspace                                          undefined isspace()
    //         00447109     ADD        ESP,0x4
    //         0044710c     TEST       EAX,EAX
    //         0044710e     JNZ        LAB_00447131
    //                               LAB_00447110                                                 XREF[1]:     0044712f(j)  
    //         00447110     MOV        EAX,dword ptr [ESI + 0xc]
    //         00447113     MOV        this,dword ptr [ESI + 0x4]
    //         00447116     CMP        EAX,this
    //         00447118     JGE        LAB_00447131
    //         0044711a     MOV        this,dword ptr [ESI]
    //                              dstring.cpp:325 (21)
    //         0044711c     INC        EAX
    //         0044711d     MOV        dword ptr [ESI + 0xc],EAX
    //         00447120     MOVSX      EDX,byte ptr [this->stringValue + EAX*0x1]
    //         00447124     PUSH       EDX
    //         00447125     CALL       isspace                                          undefined isspace()
    //         0044712a     ADD        ESP,0x4
    //         0044712d     TEST       EAX,EAX
    //         0044712f     JZ         LAB_00447110
    //                               LAB_00447131                                                 XREF[2]:     0044710e(j), 00447118(j)  
    //                              dstring.cpp:326 (2)
    //         00447131     POP        ESI
    //         00447132     RET
    //         00447133     ??         90h
    //         00447134     NOP
    //         00447135     NOP
    //         00447136     NOP
    //         00447137     NOP
    //         00447138     NOP
    //         00447139     NOP
    //         0044713a     NOP
    //         0044713b     NOP
    //         0044713c     NOP
    //         0044713d     NOP
    //         0044713e     NOP
    //         0044713f     NOP
    return;
}

DString* DString::subString(int param_1, int param_2) {
    /* TODO: Stub */
    //                              DString __thiscall subString(DString * this, DString * __return_stor
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     004471a8(R)  
    //              int               Stack[0x8]:4   param_1                   XREF[1]:     00447172(R)  
    //              int               Stack[0xc]:4   param_2                   XREF[1]:     00447159(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004471b8(W), 004471c9(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004471d3(R)  
    //              DString           Stack[-0x24]   rStr                      XREF[2,3]:   00447165(W), 004471c1(W), 0044719f(*), 004471ac(*), 
    //                                                                                     004471c5(*)  
    //                               ?subString@DString@@QAE?AV1@HH@Z                             XREF[4]:     word:00446f76(c), 
    //                               DString::subString                                                        nextWord:00447068(c), 
    //                                                                                                         stripTrailing:0044731b(c), 
    //                                                                                                         stripLeading:004473b9(c)  
    //                              dstring.cpp:328 (25)
    //         00447140     PUSH       -0x1
    //         00447142     PUSH       FUN_0055d3ff
    //         00447147     MOV        EAX,FS:[0x0]
    //         0044714d     PUSH       EAX
    //         0044714e     MOV        dword ptr FS:[0x0],ESP
    //         00447155     SUB        ESP,0x18
    //         00447158     PUSH       EBP
    //                              dstring.cpp:329 (25)
    //         00447159     MOV        EBP,dword ptr [ESP + param_2]
    //         0044715d     PUSH       ESI
    //         0044715e     PUSH       EDI
    //         0044715f     LEA        EAX,[EBP + 0x1]
    //         00447162     MOV        ESI,this
    //         00447164     PUSH       EAX
    //         00447165     MOV        dword ptr [ESP + rStr.stringValue],0x0
    //         0044716d     CALL       malloc                                           undefined malloc()
    //                              dstring.cpp:332 (22)
    //         00447172     MOV        EDX,dword ptr [ESP + param_1]
    //         00447176     MOV        EDI,EAX
    //         00447178     MOV        EAX,dword ptr [ESI + 0x4]
    //         0044717b     ADD        ESP,0x4
    //         0044717e     XOR        this,this
    //         00447180     CMP        EDX,EAX
    //         00447182     JGE        LAB_0044719a
    //                               LAB_00447184                                                 XREF[1]:     00447198(j)  
    //         00447184     CMP        this,EBP
    //         00447186     JGE        LAB_0044719a
    //                              dstring.cpp:333 (18)
    //         00447188     MOV        EAX,dword ptr [ESI]
    //         0044718a     INC        this
    //         0044718b     MOV        AL,byte ptr [EDX + EAX*0x1]
    //         0044718e     INC        EDX
    //         0044718f     MOV        byte ptr [this->stringValue + EDI*0x1 + -0x1],AL
    //         00447193     MOV        EAX,dword ptr [ESI + 0x4]
    //         00447196     CMP        EDX,EAX
    //         00447198     JL         LAB_00447184
    //                               LAB_0044719a                                                 XREF[2]:     00447182(j), 00447186(j)  
    //                              dstring.cpp:334 (4)
    //         0044719a     MOV        byte ptr [this->stringValue + EDI*0x1],0x0
    //                              dstring.cpp:336 (10)
    //         0044719e     PUSH       EDI
    //         0044719f     LEA        this=>rStr.lengthValue,[ESP + 0x14]
    //         004471a3     CALL       DString::DString                                 undefined DString(DString * this, char * para
    //                              dstring.cpp:337 (43)
    //         004471a8     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         004471ac     LEA        this=>rStr.lengthValue,[ESP + 0x10]
    //         004471b0     MOV        EDI,0x1
    //         004471b5     PUSH       this
    //         004471b6     MOV        this,ESI
    //         004471b8     MOV        dword ptr [ESP + local_4],EDI
    //         004471bc     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         004471c1     MOV        dword ptr [ESP + rStr.stringValue],EDI
    //         004471c5     LEA        this=>rStr.lengthValue,[ESP + 0x10]
    //         004471c9     MOV        byte ptr [ESP + local_4],0x0
    //         004471ce     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:338 (22)
    //         004471d3     MOV        this,dword ptr [ESP + local_c]
    //         004471d7     MOV        EAX,ESI
    //         004471d9     POP        EDI
    //         004471da     POP        ESI
    //         004471db     MOV        dword ptr FS:[0x0],this
    //         004471e2     POP        EBP
    //         004471e3     ADD        ESP,0x24
    //         004471e6     RET        0xc
    //         004471e9     ??         90h
    //         004471ea     NOP
    //         004471eb     NOP
    //         004471ec     NOP
    //         004471ed     NOP
    //         004471ee     NOP
    //         004471ef     NOP
    return 0;
}

void DString::append(DString param_1) {
    /* TODO: Stub */
    //                              void __thiscall append(DString * this, DString param_1)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString           Stack[0x4]:20  param_1                   XREF[6]:     0044720d(*), 00447248(*), 00447259(*), 00447267(*), 
    //                                                                                     0044728c(*), 004472ab(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00447211(W), 004472a7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004472ba(R)  
    //                               ?append@DString@@QAEXV1@@Z                                   XREF[1]:     operator+:00446cca(c)  
    //                               DString::append
    //                              dstring.cpp:340 (29)
    //         004471f0     MOV        EAX,FS:[0x0]
    //         004471f6     PUSH       -0x1
    //         004471f8     PUSH       FUN_0055d418
    //         004471fd     PUSH       EAX
    //         004471fe     MOV        dword ptr FS:[0x0],ESP
    //         00447205     PUSH       EBX
    //         00447206     PUSH       EBP
    //         00447207     PUSH       ESI
    //         00447208     PUSH       EDI
    //         00447209     MOV        EDI,this
    //         0044720b     XOR        ESI,ESI
    //                              dstring.cpp:341 (28)
    //         0044720d     LEA        this=>param_1,[ESP + 0x20]
    //         00447211     MOV        dword ptr [ESP + local_4],ESI
    //         00447215     CALL       DString::length                                  int length(DString * this)
    //         0044721a     MOV        this,dword ptr [EDI + 0x4]
    //         0044721d     LEA        EDX,[EAX + this->stringValue*0x1 + 0x1]
    //         00447221     PUSH       EDX
    //         00447222     CALL       malloc                                           undefined malloc()
    //         00447227     MOV        EBX,EAX
    //                              dstring.cpp:344 (10)
    //         00447229     MOV        EAX,dword ptr [EDI + 0x4]
    //         0044722c     ADD        ESP,0x4
    //         0044722f     CMP        EAX,ESI
    //         00447231     JLE        LAB_00447245
    //                               LAB_00447233                                                 XREF[1]:     00447243(j)  
    //                              dstring.cpp:345 (18)
    //         00447233     MOV        EAX,dword ptr [EDI]
    //         00447235     INC        ESI
    //         00447236     MOV        this,byte ptr [ESI + EAX*0x1 + -0x1]
    //         0044723a     MOV        byte ptr [ESI + EBX*0x1 + -0x1],this
    //         0044723e     MOV        EAX,dword ptr [EDI + 0x4]
    //         00447241     CMP        ESI,EAX
    //         00447243     JL         LAB_00447233
    //                               LAB_00447245                                                 XREF[1]:     00447231(j)  
    //                              dstring.cpp:347 (18)
    //         00447245     MOV        EBP,dword ptr [EDI + 0x4]
    //         00447248     LEA        this=>param_1,[ESP + 0x20]
    //         0044724c     CALL       DString::length                                  int length(DString * this)
    //         00447251     ADD        EAX,EBP
    //         00447253     CMP        ESI,EAX
    //         00447255     JGE        LAB_0044727d
    //                               LAB_00447257                                                 XREF[1]:     0044727b(j)  
    //                              dstring.cpp:348 (38)
    //         00447257     MOV        EDX,ESI
    //         00447259     LEA        this=>param_1,[ESP + 0x20]
    //         0044725d     SUB        EDX,EBP
    //         0044725f     PUSH       EDX
    //         00447260     CALL       DString::operator[]                              char * operator[](DString * this, int param_1)
    //         00447265     MOV        AL,byte ptr [EAX]
    //         00447267     LEA        this=>param_1,[ESP + 0x20]
    //         0044726b     MOV        byte ptr [ESI + EBX*0x1],AL
    //         0044726e     MOV        EBP,dword ptr [EDI + 0x4]
    //         00447271     INC        ESI
    //         00447272     CALL       DString::length                                  int length(DString * this)
    //         00447277     ADD        EAX,EBP
    //         00447279     CMP        ESI,EAX
    //         0044727b     JL         LAB_00447257
    //                               LAB_0044727d                                                 XREF[1]:     00447255(j)  
    //                              dstring.cpp:350 (4)
    //         0044727d     MOV        byte ptr [ESI + EBX*0x1],0x0
    //                              dstring.cpp:351 (11)
    //         00447281     MOV        this,dword ptr [EDI]
    //         00447283     PUSH       this
    //         00447284     CALL       free                                             undefined free()
    //         00447289     ADD        ESP,0x4
    //                              dstring.cpp:355 (16)
    //         0044728c     LEA        this=>param_1,[ESP + 0x20]
    //         00447290     MOV        dword ptr [EDI],EBX
    //         00447292     CALL       DString::length                                  int length(DString * this)
    //         00447297     MOV        this,dword ptr [EDI + 0x4]
    //         0044729a     ADD        this,EAX
    //                              dstring.cpp:356 (5)
    //         0044729c     XOR        EAX,EAX
    //         0044729e     MOV        dword ptr [EDI + 0x4],this
    //                              dstring.cpp:357 (6)
    //         004472a1     OR         this,0xffffffff
    //         004472a4     MOV        dword ptr [EDI + 0x8],this
    //                              dstring.cpp:359 (40)
    //         004472a7     MOV        dword ptr [ESP + local_4],this
    //         004472ab     LEA        this=>param_1,[ESP + 0x20]
    //         004472af     MOV        dword ptr [EDI + 0xc],EAX
    //         004472b2     MOV        dword ptr [EDI + 0x10],EAX
    //         004472b5     CALL       DString::~DString                                void ~DString(DString * this)
    //         004472ba     MOV        this,dword ptr [ESP + local_c]
    //         004472be     POP        EDI
    //         004472bf     POP        ESI
    //         004472c0     POP        EBP
    //         004472c1     MOV        dword ptr FS:[0x0],this
    //         004472c8     POP        EBX
    //         004472c9     ADD        ESP,0xc
    //         004472cc     RET        0x14
    //         004472cf     ??         90h
    return;
}

DString* DString::stripTrailing(char param_1) {
    /* TODO: Stub */
    //                              DString __thiscall stripTrailing(DString * this, DString * __return_
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     00447342(R)  
    //              char              Stack[0x8]:1   param_1                   XREF[1]:     004472ec(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00447323(W), 00447334(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044734d(R)  
    //              undefined         Stack[-0x20]:1 local_20                  XREF[2]:     00447312(*), 00447330(*)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     004472f0(W)  
    //                               ?stripTrailing@DString@@QAE?AV1@D@Z
    //                               DString::stripTrailing
    //                              dstring.cpp:361 (28)
    //         004472d0     PUSH       -0x1
    //         004472d2     PUSH       FUN_0055d438
    //         004472d7     MOV        EAX,FS:[0x0]
    //         004472dd     PUSH       EAX
    //         004472de     MOV        dword ptr FS:[0x0],ESP
    //         004472e5     SUB        ESP,0x18
    //         004472e8     PUSH       EBX
    //         004472e9     PUSH       ESI
    //         004472ea     MOV        ESI,this
    //                              dstring.cpp:363 (31)
    //         004472ec     MOV        DL,byte ptr [ESP + param_1]
    //         004472f0     MOV        dword ptr [ESP + local_24],0x0
    //         004472f8     MOV        EAX,dword ptr [ESI + 0x4]
    //         004472fb     MOV        this,dword ptr [ESI]
    //         004472fd     ADD        this,EAX
    //         004472ff     CMP        byte ptr [this->stringValue + -0x1],DL
    //         00447302     JNZ        LAB_00447311
    //                               LAB_00447304                                                 XREF[1]:     0044730f(j)  
    //         00447304     TEST       EAX,EAX
    //         00447306     JLE        LAB_00447311
    //         00447308     MOV        BL,byte ptr [this->stringValue + -0x2]
    //                              dstring.cpp:364 (6)
    //         0044730b     DEC        EAX
    //         0044730c     DEC        this
    //         0044730d     CMP        BL,DL
    //         0044730f     JZ         LAB_00447304
    //                               LAB_00447311                                                 XREF[2]:     00447302(j), 00447306(j)  
    //                              dstring.cpp:372 (48)
    //         00447311     PUSH       EAX
    //         00447312     LEA        EDX=>local_20,[ESP + 0x10]
    //         00447316     PUSH       0x0
    //         00447318     PUSH       EDX
    //         00447319     MOV        this,ESI
    //         0044731b     CALL       DString::subString                               DString * subString(DString * this, DString *
    //         00447320     PUSH       EAX
    //         00447321     MOV        this,ESI
    //         00447323     MOV        dword ptr [ESP + local_4],0x0
    //         0044732b     CALL       DString::operator=                               DString * operator=(DString * this, DString *
    //         00447330     LEA        this=>local_20,[ESP + 0xc]
    //         00447334     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0044733c     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:373 (12)
    //         00447341     PUSH       ESI
    //         00447342     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00447346     MOV        this,ESI
    //         00447348     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //                              dstring.cpp:374 (21)
    //         0044734d     MOV        this,dword ptr [ESP + local_c]
    //         00447351     MOV        EAX,ESI
    //         00447353     POP        ESI
    //         00447354     MOV        dword ptr FS:[0x0],this
    //         0044735b     POP        EBX
    //         0044735c     ADD        ESP,0x24
    //         0044735f     RET        0x8
    //         00447362     ??         90h
    //         00447363     NOP
    //         00447364     NOP
    //         00447365     NOP
    //         00447366     NOP
    //         00447367     NOP
    //         00447368     NOP
    //         00447369     NOP
    //         0044736a     NOP
    //         0044736b     NOP
    //         0044736c     NOP
    //         0044736d     NOP
    //         0044736e     NOP
    //         0044736f     NOP
    return 0;
}

DString* DString::stripLeading(char param_1) {
    /* TODO: Stub */
    //                              DString __thiscall stripLeading(DString * this, DString * __return_s
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     004473e0(R)  
    //              char              Stack[0x8]:1   param_1                   XREF[1]:     00447388(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004473c1(W), 004473d2(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004473eb(R)  
    //              undefined         Stack[-0x20]:1 local_20                  XREF[2]:     004473b0(*), 004473ce(*)  
    //              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00447392(W)  
    //                               ?stripLeading@DString@@QAE?AV1@D@Z
    //                               DString::stripLeading
    //                              dstring.cpp:376 (24)
    //         00447370     PUSH       -0x1
    //         00447372     PUSH       FUN_0055d458
    //         00447377     MOV        EAX,FS:[0x0]
    //         0044737d     PUSH       EAX
    //         0044737e     MOV        dword ptr FS:[0x0],ESP
    //         00447385     SUB        ESP,0x18
    //                              dstring.cpp:378 (31)
    //         00447388     MOV        DL,byte ptr [ESP + param_1]
    //         0044738c     PUSH       ESI
    //         0044738d     MOV        ESI,this
    //         0044738f     XOR        EAX,EAX
    //         00447391     PUSH       EDI
    //         00447392     MOV        dword ptr [ESP + local_24],0x0
    //         0044739a     MOV        this,dword ptr [ESI]
    //         0044739c     CMP        byte ptr [this->stringValue],DL
    //         0044739e     JNZ        LAB_004473ad
    //         004473a0     MOV        EDI,dword ptr [ESI + 0x4]
    //                               LAB_004473a3                                                 XREF[1]:     004473ab(j)  
    //         004473a3     CMP        EAX,EDI
    //         004473a5     JGE        LAB_004473ad
    //                              dstring.cpp:379 (6)
    //         004473a7     INC        EAX
    //         004473a8     CMP        byte ptr [EAX + this->stringValue*0x1],DL
    //         004473ab     JZ         LAB_004473a3
    //                               LAB_004473ad                                                 XREF[2]:     0044739e(j), 004473a5(j)  
    //                              dstring.cpp:380 (50)
    //         004473ad     MOV        this,dword ptr [ESI + 0x4]
    //         004473b0     LEA        EDX=>local_20,[ESP + 0xc]
    //         004473b4     PUSH       this
    //         004473b5     PUSH       EAX
    //         004473b6     PUSH       EDX
    //         004473b7     MOV        this,ESI
    //         004473b9     CALL       DString::subString                               DString * subString(DString * this, DString *
    //         004473be     PUSH       EAX
    //         004473bf     MOV        this,ESI
    //         004473c1     MOV        dword ptr [ESP + local_4],0x0
    //         004473c9     CALL       DString::operator=                               DString * operator=(DString * this, DString *
    //         004473ce     LEA        this=>local_20,[ESP + 0xc]
    //         004473d2     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004473da     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:381 (12)
    //         004473df     PUSH       ESI
    //         004473e0     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         004473e4     MOV        this,ESI
    //         004473e6     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //                              dstring.cpp:382 (21)
    //         004473eb     MOV        this,dword ptr [ESP + local_c]
    //         004473ef     MOV        EAX,ESI
    //         004473f1     POP        EDI
    //         004473f2     MOV        dword ptr FS:[0x0],this
    //         004473f9     POP        ESI
    //         004473fa     ADD        ESP,0x24
    //         004473fd     RET        0x8
    //                              * public: int __thiscall DString::asInt(void)const                                                      *
    //                              int __thiscall asInt(DString * this)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?asInt@DString@@QBEHXZ
    //                               DString::asInt
    //                              dstring.cpp:384 (11)
    //         00447400     MOV        EAX,dword ptr [this->stringValue]
    //         00447402     PUSH       EAX
    //         00447403     CALL       atoi                                             undefined atoi()
    //         00447408     ADD        ESP,0x4
    //                              dstring.cpp:386 (1)
    //         0044740b     RET
    //         0044740c     ??         90h
    //         0044740d     NOP
    //         0044740e     NOP
    //         0044740f     NOP
    //                              * public: double __thiscall DString::asDouble(void)const                                                *
    //                              double __thiscall asDouble(DString * this)
    //              double            ST0:10         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?asDouble@DString@@QBENXZ
    //                               DString::asDouble
    //                              dstring.cpp:388 (11)
    //         00447410     MOV        EAX,dword ptr [this->stringValue]
    //         00447412     PUSH       EAX
    //         00447413     CALL       atof                                             undefined atof()
    //         00447418     ADD        ESP,0x4
    //                              dstring.cpp:390 (1)
    //         0044741b     RET
    //         0044741c     ??         90h
    //         0044741d     NOP
    //         0044741e     NOP
    //         0044741f     NOP
    return 0;
}

void DString::uppercase() {
    /* TODO: Stub */
    //                              void __thiscall uppercase(DString * this)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?uppercase@DString@@QAEXXZ                                   XREF[1]:     asUppercase:00447499(c)  
    //                               DString::uppercase
    //                              dstring.cpp:392 (4)
    //         00447420     PUSH       ESI
    //         00447421     PUSH       EDI
    //         00447422     MOV        EDI,this
    //                              dstring.cpp:393 (11)
    //         00447424     XOR        ESI,ESI
    //         00447426     CALL       DString::length                                  int length(DString * this)
    //         0044742b     TEST       EAX,EAX
    //         0044742d     JLE        LAB_0044744f
    //                               LAB_0044742f                                                 XREF[1]:     0044744d(j)  
    //                              dstring.cpp:394 (32)
    //         0044742f     MOV        EAX,dword ptr [EDI]
    //         00447431     MOVSX      this,byte ptr [EAX + ESI*0x1]
    //         00447435     PUSH       this
    //         00447436     CALL       toupper                                          undefined toupper()
    //         0044743b     MOV        EDX,dword ptr [EDI]
    //         0044743d     ADD        ESP,0x4
    //         00447440     MOV        this,EDI
    //         00447442     MOV        byte ptr [EDX + ESI*0x1],AL
    //         00447445     INC        ESI
    //         00447446     CALL       DString::length                                  int length(DString * this)
    //         0044744b     CMP        ESI,EAX
    //         0044744d     JL         LAB_0044742f
    //                               LAB_0044744f                                                 XREF[1]:     0044742d(j)  
    //                              dstring.cpp:395 (3)
    //         0044744f     POP        EDI
    //         00447450     POP        ESI
    //         00447451     RET
    //         00447452     ??         90h
    //         00447453     NOP
    //         00447454     NOP
    //         00447455     NOP
    //         00447456     NOP
    //         00447457     NOP
    //         00447458     NOP
    //         00447459     NOP
    //         0044745a     NOP
    //         0044745b     NOP
    //         0044745c     NOP
    //         0044745d     NOP
    //         0044745e     NOP
    //         0044745f     NOP
    return;
}

DString* DString::asUppercase() {
    /* TODO: Stub */
    //                              DString __thiscall asUppercase(DString * this, DString * __return_st
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0044749e(R)  
    //              <NoType>          Stack[0x0]:1   __$ReturnUdt
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00447491(W), 004474ba(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004474c4(R)  
    //              DString           Stack[-0x24]   rStr                      XREF[2,4]:   00447480(W), 004474ae(W), 0044747c(*), 0044748d(*), 
    //                                                                                     004474a2(*), 004474b6(*)  
    //                               ?asUppercase@DString@@QAE?AV1@XZ
    //                               DString::asUppercase
    //                              dstring.cpp:397 (24)
    //         00447460     PUSH       -0x1
    //         00447462     PUSH       FUN_0055d48b
    //         00447467     MOV        EAX,FS:[0x0]
    //         0044746d     PUSH       EAX
    //         0044746e     MOV        dword ptr FS:[0x0],ESP
    //         00447475     SUB        ESP,0x18
    //                              dstring.cpp:398 (21)
    //         00447478     MOV        EAX,dword ptr [this->stringValue]
    //         0044747a     PUSH       ESI
    //         0044747b     PUSH       EAX
    //         0044747c     LEA        this=>rStr.lengthValue,[ESP + 0xc]
    //         00447480     MOV        dword ptr [ESP + rStr.stringValue],0x0
    //         00447488     CALL       DString::DString                                 undefined DString(DString * this, char * para
    //                              dstring.cpp:399 (17)
    //         0044748d     LEA        this=>rStr.lengthValue,[ESP + 0x8]
    //         00447491     MOV        dword ptr [ESP + local_4],0x1
    //         00447499     CALL       DString::uppercase                               void uppercase(DString * this)
    //                              dstring.cpp:400 (38)
    //         0044749e     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         004474a2     LEA        this=>rStr.lengthValue,[ESP + 0x8]
    //         004474a6     PUSH       this
    //         004474a7     MOV        this,ESI
    //         004474a9     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         004474ae     MOV        dword ptr [ESP + rStr.stringValue],0x1
    //         004474b6     LEA        this=>rStr.lengthValue,[ESP + 0x8]
    //         004474ba     MOV        byte ptr [ESP + local_4],0x0
    //         004474bf     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:401 (20)
    //         004474c4     MOV        this,dword ptr [ESP + local_c]
    //         004474c8     MOV        EAX,ESI
    //         004474ca     MOV        dword ptr FS:[0x0],this
    //         004474d1     POP        ESI
    //         004474d2     ADD        ESP,0x24
    //         004474d5     RET        0x4
    //         004474d8     ??         90h
    //         004474d9     NOP
    //         004474da     NOP
    //         004474db     NOP
    //         004474dc     NOP
    //         004474dd     NOP
    //         004474de     NOP
    //         004474df     NOP
    return 0;
}

void DString::lowercase() {
    /* TODO: Stub */
    //                              void __thiscall lowercase(DString * this)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?lowercase@DString@@QAEXXZ                                   XREF[1]:     asLowercase:00447559(c)  
    //                               DString::lowercase
    //                              dstring.cpp:403 (4)
    //         004474e0     PUSH       ESI
    //         004474e1     PUSH       EDI
    //         004474e2     MOV        EDI,this
    //                              dstring.cpp:404 (11)
    //         004474e4     XOR        ESI,ESI
    //         004474e6     CALL       DString::length                                  int length(DString * this)
    //         004474eb     TEST       EAX,EAX
    //         004474ed     JLE        LAB_0044750f
    //                               LAB_004474ef                                                 XREF[1]:     0044750d(j)  
    //                              dstring.cpp:405 (32)
    //         004474ef     MOV        EAX,dword ptr [EDI]
    //         004474f1     MOVSX      this,byte ptr [EAX + ESI*0x1]
    //         004474f5     PUSH       this
    //         004474f6     CALL       tolower                                          undefined tolower()
    //         004474fb     MOV        EDX,dword ptr [EDI]
    //         004474fd     ADD        ESP,0x4
    //         00447500     MOV        this,EDI
    //         00447502     MOV        byte ptr [EDX + ESI*0x1],AL
    //         00447505     INC        ESI
    //         00447506     CALL       DString::length                                  int length(DString * this)
    //         0044750b     CMP        ESI,EAX
    //         0044750d     JL         LAB_004474ef
    //                               LAB_0044750f                                                 XREF[1]:     004474ed(j)  
    //                              dstring.cpp:406 (3)
    //         0044750f     POP        EDI
    //         00447510     POP        ESI
    //         00447511     RET
    //         00447512     ??         90h
    //         00447513     NOP
    //         00447514     NOP
    //         00447515     NOP
    //         00447516     NOP
    //         00447517     NOP
    //         00447518     NOP
    //         00447519     NOP
    //         0044751a     NOP
    //         0044751b     NOP
    //         0044751c     NOP
    //         0044751d     NOP
    //         0044751e     NOP
    //         0044751f     NOP
    return;
}

DString* DString::asLowercase() {
    /* TODO: Stub */
    //                              DString __thiscall asLowercase(DString * this, DString * __return_st
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0044755e(R)  
    //              <NoType>          Stack[0x0]:1   __$ReturnUdt
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00447551(W), 0044757a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00447584(R)  
    //              DString           Stack[-0x24]   rStr                      XREF[2,4]:   00447540(W), 0044756e(W), 0044753c(*), 0044754d(*), 
    //                                                                                     00447562(*), 00447576(*)  
    //                               ?asLowercase@DString@@QAE?AV1@XZ
    //                               DString::asLowercase
    //                              dstring.cpp:408 (24)
    //         00447520     PUSH       -0x1
    //         00447522     PUSH       FUN_0055d4bb
    //         00447527     MOV        EAX,FS:[0x0]
    //         0044752d     PUSH       EAX
    //         0044752e     MOV        dword ptr FS:[0x0],ESP
    //         00447535     SUB        ESP,0x18
    //                              dstring.cpp:409 (21)
    //         00447538     MOV        EAX,dword ptr [this->stringValue]
    //         0044753a     PUSH       ESI
    //         0044753b     PUSH       EAX
    //         0044753c     LEA        this=>rStr.lengthValue,[ESP + 0xc]
    //         00447540     MOV        dword ptr [ESP + rStr.stringValue],0x0
    //         00447548     CALL       DString::DString                                 undefined DString(DString * this, char * para
    //                              dstring.cpp:410 (17)
    //         0044754d     LEA        this=>rStr.lengthValue,[ESP + 0x8]
    //         00447551     MOV        dword ptr [ESP + local_4],0x1
    //         00447559     CALL       DString::lowercase                               void lowercase(DString * this)
    //                              dstring.cpp:411 (38)
    //         0044755e     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00447562     LEA        this=>rStr.lengthValue,[ESP + 0x8]
    //         00447566     PUSH       this
    //         00447567     MOV        this,ESI
    //         00447569     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         0044756e     MOV        dword ptr [ESP + rStr.stringValue],0x1
    //         00447576     LEA        this=>rStr.lengthValue,[ESP + 0x8]
    //         0044757a     MOV        byte ptr [ESP + local_4],0x0
    //         0044757f     CALL       DString::~DString                                void ~DString(DString * this)
    //                              dstring.cpp:412 (20)
    //         00447584     MOV        this,dword ptr [ESP + local_c]
    //         00447588     MOV        EAX,ESI
    //         0044758a     MOV        dword ptr FS:[0x0],this
    //         00447591     POP        ESI
    //         00447592     ADD        ESP,0x24
    //         00447595     RET        0x4
    //         00447598     ??         90h
    //         00447599     NOP
    //         0044759a     NOP
    //         0044759b     NOP
    //         0044759c     NOP
    //         0044759d     NOP
    //         0044759e     NOP
    //         0044759f     NOP
    return 0;
}

void DString::change(char param_1, char param_2) {
    /* TODO: Stub */
    //                              void __thiscall change(DString * this, char param_1, char param_2)
    //              void              <VOID>         <RETURN>
    //              DString *         ECX:4 (auto)   this
    //              char              Stack[0x4]:1   param_1                   XREF[1]:     004475ac(R)  
    //              char              Stack[0x8]:1   param_2                   XREF[1]:     004475b1(R)  
    //                               ?change@DString@@QAEXDD@Z
    //                               DString::change
    //                              dstring.cpp:414 (3)
    //         004475a0     PUSH       ESI
    //         004475a1     MOV        ESI,this
    //                              dstring.cpp:415 (18)
    //         004475a3     XOR        EDX,EDX
    //         004475a5     MOV        EAX,dword ptr [ESI + 0x4]
    //         004475a8     TEST       EAX,EAX
    //         004475aa     JLE        LAB_004475c8
    //         004475ac     MOV        this,byte ptr [ESP + param_1]
    //         004475b0     PUSH       EBX
    //         004475b1     MOV        BL,byte ptr [ESP + param_2]
    //                               LAB_004475b5                                                 XREF[1]:     004475c5(j)  
    //                              dstring.cpp:416 (8)
    //         004475b5     MOV        EAX,dword ptr [ESI]
    //         004475b7     ADD        EAX,EDX
    //         004475b9     CMP        byte ptr [EAX],this
    //         004475bb     JNZ        LAB_004475bf
    //                              dstring.cpp:417 (2)
    //         004475bd     MOV        byte ptr [EAX],BL
    //                               LAB_004475bf                                                 XREF[1]:     004475bb(j)  
    //                              dstring.cpp:415 (8)
    //         004475bf     MOV        EAX,dword ptr [ESI + 0x4]
    //         004475c2     INC        EDX
    //         004475c3     CMP        EDX,EAX
    //         004475c5     JL         LAB_004475b5
    //                              dstring.cpp:414 (1)
    //         004475c7     POP        EBX
    //                               LAB_004475c8                                                 XREF[1]:     004475aa(j)  
    //                              dstring.cpp:418 (4)
    //         004475c8     POP        ESI
    //         004475c9     RET        0x8
    //         004475cc     ??         90h
    //         004475cd     NOP
    //         004475ce     NOP
    //         004475cf     NOP
    return;
}

DKeyString::DKeyString() {
    /* TODO: Stub */
    //                              undefined __thiscall DKeyString(DKeyString * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004475ff(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0044760c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004475ee(W)  
    //                               ??0DKeyString@@QAE@XZ
    //                               DKeyString::DKeyString
    //                              dstring.cpp:426 (60)
    //         004475d0     PUSH       -0x1
    //         004475d2     PUSH       FUN_0055d4d8
    //         004475d7     MOV        EAX,FS:[0x0]
    //         004475dd     PUSH       EAX
    //         004475de     MOV        dword ptr FS:[0x0],ESP
    //         004475e5     PUSH       this
    //         004475e6     PUSH       ESI
    //         004475e7     MOV        ESI,this
    //         004475e9     PUSH       s_                                               = ""
    //         004475ee     MOV        dword ptr [ESP + local_10],ESI
    //         004475f2     CALL       DString::DString                                 undefined DString(DString * this, char * para
    //         004475f7     PUSH       s_                                               = ""
    //         004475fc     LEA        this,[ESI + 0x14]
    //         004475ff     MOV        dword ptr [ESP + local_4],0x0
    //         00447607     CALL       DString::DString                                 undefined DString(DString * this, char * para
    //                              dstring.cpp:427 (18)
    //         0044760c     MOV        this,dword ptr [ESP + local_c]
    //         00447610     MOV        EAX,ESI
    //         00447612     MOV        dword ptr FS:[0x0],this
    //         00447619     POP        ESI
    //         0044761a     ADD        ESP,0x10
    //         0044761d     RET
    //         0044761e     ??         90h
    //         0044761f     NOP
}

DKeyString::DKeyString(DString param_1, DString param_2) {
    /* TODO: Stub */
    //                              undefined __thiscall DKeyString(DKeyString * this, DString param_1, 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              DString           Stack[0x4]:20  param_1                   XREF[2]:     0044763d(*), 00447661(*)  
    //              DString           Stack[0x18]:20 param_2                   XREF[2]:     0044764f(*), 0044766f(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     00447641(W), 00447653(W), 00447665(W), 00447673(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00447680(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00447639(W)  
    //                               ??0DKeyString@@QAE@VDString@@0@Z
    //                               DKeyString::DKeyString
    //                              dstring.cpp:431 (69)
    //         00447620     PUSH       -0x1
    //         00447622     PUSH       FUN_0055d508
    //         00447627     MOV        EAX,FS:[0x0]
    //         0044762d     PUSH       EAX
    //         0044762e     MOV        dword ptr FS:[0x0],ESP
    //         00447635     PUSH       this
    //         00447636     PUSH       ESI
    //         00447637     MOV        ESI,this
    //         00447639     MOV        dword ptr [ESP + local_10],ESI
    //         0044763d     LEA        EAX=>param_1,[ESP + 0x18]
    //         00447641     MOV        dword ptr [ESP + local_4],0x1
    //         00447649     PUSH       EAX
    //         0044764a     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         0044764f     LEA        this=>param_2,[ESP + 0x2c]
    //         00447653     MOV        byte ptr [ESP + local_4],0x2
    //         00447658     PUSH       this
    //         00447659     LEA        this,[ESI + 0x14]
    //         0044765c     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00447661     LEA        this=>param_1,[ESP + 0x18]
    //                              dstring.cpp:432 (47)
    //         00447665     MOV        byte ptr [ESP + local_4],0x0
    //         0044766a     CALL       DString::~DString                                void ~DString(DString * this)
    //         0044766f     LEA        this=>param_2,[ESP + 0x2c]
    //         00447673     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0044767b     CALL       DString::~DString                                void ~DString(DString * this)
    //         00447680     MOV        this,dword ptr [ESP + local_c]
    //         00447684     MOV        EAX,ESI
    //         00447686     MOV        dword ptr FS:[0x0],this
    //         0044768d     POP        ESI
    //         0044768e     ADD        ESP,0x10
    //         00447691     RET        0x28
    //         00447694     ??         90h
    //         00447695     NOP
    //         00447696     NOP
    //         00447697     NOP
    //         00447698     NOP
    //         00447699     NOP
    //         0044769a     NOP
    //         0044769b     NOP
    //         0044769c     NOP
    //         0044769d     NOP
    //         0044769e     NOP
    //         0044769f     NOP
}

DKeyString::~DKeyString() {
    /* TODO: Stub */
    //                              void __thiscall ~DKeyString(DKeyString * this)
    //              void              <VOID>         <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004476bb(W), 004476ca(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004476d7(R)  
    //                               ??1DKeyString@@QAE@XZ
    //                               DKeyString::~DKeyString
    //                              dstring.cpp:434 (42)
    //         004476a0     MOV        EAX,FS:[0x0]
    //         004476a6     PUSH       -0x1
    //         004476a8     PUSH       FUN_0055d528
    //         004476ad     PUSH       EAX
    //         004476ae     MOV        dword ptr FS:[0x0],ESP
    //         004476b5     PUSH       ESI
    //         004476b6     MOV        ESI,this
    //         004476b8     LEA        this,[ESI + 0x14]
    //         004476bb     MOV        dword ptr [ESP + local_4],0x0
    //         004476c3     CALL       DString::~DString                                void ~DString(DString * this)
    //         004476c8     MOV        this,ESI
    //                              dstring.cpp:435 (29)
    //         004476ca     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004476d2     CALL       DString::~DString                                void ~DString(DString * this)
    //         004476d7     MOV        this,dword ptr [ESP + local_c]
    //         004476db     POP        ESI
    //         004476dc     MOV        dword ptr FS:[0x0],this
    //         004476e3     ADD        ESP,0xc
    //         004476e6     RET
    //         004476e7     ??         90h
    //         004476e8     NOP
    //         004476e9     NOP
    //         004476ea     NOP
    //         004476eb     NOP
    //         004476ec     NOP
    //         004476ed     NOP
    //         004476ee     NOP
    //         004476ef     NOP
    //                              * public: class DString __thiscall DKeyString::key(void)const                                           *
    //                              DString __thiscall key(DKeyString * this, DString * __return_storage
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     004476f2(R)  
    //              <NoType>          Stack[0x0]:1   __$ReturnUdt
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004476f9(W)  
    //                               ?key@DKeyString@@QBE?AVDString@@XZ
    //                               DKeyString::key
    //                              dstring.cpp:437 (2)
    //         004476f0     PUSH       this
    //         004476f1     PUSH       ESI
    //                              dstring.cpp:438 (22)
    //         004476f2     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         004476f6     PUSH       this
    //         004476f7     MOV        this,ESI
    //         004476f9     MOV        dword ptr [ESP + local_4],0x0
    //         00447701     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00447706     MOV        EAX,ESI
    //                              dstring.cpp:439 (5)
    //         00447708     POP        ESI
    //         00447709     POP        this
    //         0044770a     RET        0x4
    //         0044770d     ??         90h
    //         0044770e     NOP
    //         0044770f     NOP
}

void DKeyString::setKey(DString param_1) {
    /* TODO: Stub */
    //                              void __thiscall setKey(DKeyString * this, DString param_1)
    //              void              <VOID>         <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              DString           Stack[0x4]:20  param_1                   XREF[2]:     00447725(*), 00447737(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00447729(W), 0044773b(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00447748(*)  
    //                               ?setKey@DKeyString@@QAEXVDString@@@Z
    //                               DKeyString::setKey
    //                              dstring.cpp:441 (21)
    //         00447710     MOV        EAX,FS:[0x0]
    //         00447716     PUSH       -0x1
    //         00447718     PUSH       FUN_0055d548
    //         0044771d     PUSH       EAX
    //         0044771e     MOV        dword ptr FS:[0x0],ESP
    //                              dstring.cpp:442 (22)
    //         00447725     LEA        EAX=>param_1,[ESP + 0x10]
    //         00447729     MOV        dword ptr [ESP + local_4],0x0
    //         00447731     PUSH       EAX
    //         00447732     CALL       DString::operator=                               DString * operator=(DString * this, DString *
    //         00447737     LEA        this=>param_1,[ESP + 0x10]
    //                              dstring.cpp:443 (30)
    //         0044773b     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00447743     CALL       DString::~DString                                void ~DString(DString * this)
    //         00447748     MOV        this,dword ptr [ESP]=>local_c
    //         0044774c     MOV        dword ptr FS:[0x0],this
    //         00447753     ADD        ESP,0xc
    //         00447756     RET        0x14
    //         00447759     ??         90h
    //         0044775a     NOP
    //         0044775b     NOP
    //         0044775c     NOP
    //         0044775d     NOP
    //         0044775e     NOP
    //         0044775f     NOP
    //                              * public: class DString __thiscall DKeyString::value(void)const                                         *
    //                              DString __thiscall value(DKeyString * this, DString * __return_stora
    //              DString           EAX:4 (ptr)    <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              DString *         Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     00447762(R)  
    //              <NoType>          Stack[0x0]:1   __$ReturnUdt
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00447769(W)  
    //                               ?value@DKeyString@@QBE?AVDString@@XZ
    //                               DKeyString::value
    //                              dstring.cpp:445 (2)
    //         00447760     PUSH       this
    //         00447761     PUSH       ESI
    //                              dstring.cpp:446 (25)
    //         00447762     MOV        ESI,dword ptr [ESP + __return_storage_ptr__]
    //         00447766     ADD        this,0x14
    //         00447769     MOV        dword ptr [ESP + local_4],0x0
    //         00447771     PUSH       this
    //         00447772     MOV        this,ESI
    //         00447774     CALL       DString::DString                                 undefined DString(DString * this, DString * p
    //         00447779     MOV        EAX,ESI
    //                              dstring.cpp:447 (5)
    //         0044777b     POP        ESI
    //         0044777c     POP        this
    //         0044777d     RET        0x4
    return;
}

void DKeyString::setValue(DString param_1) {
    /* TODO: Stub */
    //                              void __thiscall setValue(DKeyString * this, DString param_1)
    //              void              <VOID>         <RETURN>
    //              DKeyString *      ECX:4 (auto)   this
    //              DString           Stack[0x4]:20  param_1                   XREF[2]:     00447795(*), 004477aa(*)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044779d(W), 004477ae(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004477bb(*)  
    //                               ?setValue@DKeyString@@QAEXVDString@@@Z
    //                               DKeyString::setValue
    //                              dstring.cpp:449 (21)
    //         00447780     MOV        EAX,FS:[0x0]
    //         00447786     PUSH       -0x1
    //         00447788     PUSH       FUN_0055d568
    //         0044778d     PUSH       EAX
    //         0044778e     MOV        dword ptr FS:[0x0],ESP
    //                              dstring.cpp:450 (25)
    //         00447795     LEA        EAX=>param_1,[ESP + 0x10]
    //         00447799     ADD        this,0x14
    //         0044779c     PUSH       EAX
    //         0044779d     MOV        dword ptr [ESP + local_4],0x0
    //         004477a5     CALL       DString::operator=                               DString * operator=(DString * this, DString *
    //         004477aa     LEA        this=>param_1,[ESP + 0x10]
    //                              dstring.cpp:451 (30)
    //         004477ae     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004477b6     CALL       DString::~DString                                void ~DString(DString * this)
    //         004477bb     MOV        this,dword ptr [ESP]=>local_c
    //         004477bf     MOV        dword ptr FS:[0x0],this
    //         004477c6     ADD        ESP,0xc
    //         004477c9     RET        0x14
    //         004477cc     ??         90h
    //         004477cd     NOP
    //         004477ce     NOP
    //         004477cf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _ShowErrMsg()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ShowErrMsg
    //                              Dsutil.c:38 (1)
    //         004477d0     RET
    //         004477d1     ??         90h
    //         004477d2     NOP
    //         004477d3     NOP
    //         004477d4     NOP
    //         004477d5     NOP
    //         004477d6     NOP
    //         004477d7     NOP
    //         004477d8     NOP
    //         004477d9     NOP
    //         004477da     NOP
    //         004477db     NOP
    //         004477dc     NOP
    //         004477dd     NOP
    //         004477de     NOP
    //         004477df     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _DSLoadSoundBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004477fe(W), 00447802(*)  
    //              _DSBUFFERDESC     Stack[-0x18]   dsBD                      XREF[3,8]:   0044780b(W), 0044782b(*), 00447882(*), 00447813(W), 
    //                                                                                     00447834(*), 0044783a(W), 004477e9(W), 00447842(W), 
    //                                                                                     004477e5(*), 004477f1(W), 004477fa(W)  
    //              IDirectSoundBu    Stack[-0x1c]:4 pDSB
    //                               _DSLoadSoundBuffer                                           XREF[2]:     _SndObjCreate:004479b9(c), 
    //                                                                                                         _SndObjCreate:004479e3(c)  
    //                              Dsutil.c:72 (3)
    //         004477e0     SUB        ESP,0x18
    //                              Dsutil.c:74 (2)
    //         004477e3     XOR        EAX,EAX
    //                              Dsutil.c:77 (66)
    //         004477e5     LEA        ECX=>dsBD.dwReserved,[ESP + 0xc]
    //         004477e9     MOV        dword ptr [ESP + dsBD.dwBufferBytes],EAX
    //         004477ed     LEA        EDX=>Stack[0x8],[ESP + 0x20]
    //         004477f1     MOV        dword ptr [ESP + dsBD.dwReserved],EAX
    //         004477f5     PUSH       ECX
    //         004477f6     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         004477fa     MOV        dword ptr [ESP + dsBD.lpwfxFormat],EAX
    //         004477fe     MOV        dword ptr [ESP + local_4],EAX
    //         00447802     LEA        EAX=>local_4,[ESP + 0x18]
    //         00447806     PUSH       EDX
    //         00447807     PUSH       EAX
    //         00447808     PUSH       ECX
    //         00447809     PUSH       0x0
    //         0044780b     MOV        dword ptr [ESP + dsBD.dwSize],0x0
    //         00447813     MOV        dword ptr [ESP + dsBD.dwFlags],0x0
    //         0044781b     CALL       _DSGetWaveResource                               undefined _DSGetWaveResource()
    //         00447820     ADD        ESP,0x14
    //         00447823     TEST       EAX,EAX
    //         00447825     JZ         LAB_00447882
    //                              Dsutil.c:82 (42)
    //         00447827     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0044782b     LEA        ECX=>dsBD,[ESP]
    //         0044782f     PUSH       0x0
    //         00447831     PUSH       ECX
    //         00447832     MOV        EDX,dword ptr [EAX]
    //         00447834     LEA        ECX=>dsBD.dwFlags,[ESP + 0xc]
    //         00447838     PUSH       ECX
    //         00447839     PUSH       EAX
    //         0044783a     MOV        dword ptr [ESP + dsBD.dwFlags],0x14
    //         00447842     MOV        dword ptr [ESP + dsBD.dwBufferBytes],0xe2
    //         0044784a     CALL       dword ptr [EDX + 0xc]
    //         0044784d     TEST       EAX,EAX
    //         0044784f     JL         LAB_0044787c
    //                              Dsutil.c:84 (27)
    //         00447851     MOV        EDX,dword ptr [ESP + 0xc]
    //         00447855     MOV        EAX,dword ptr [ESP + 0x20]
    //         00447859     MOV        ECX,dword ptr [ESP]
    //         0044785d     PUSH       EDX
    //         0044785e     PUSH       EAX=>DAT_fffffff8
    //         0044785f     PUSH       ECX=>DAT_fffffff4
    //         00447860     CALL       _DSFillSoundBuffer                               undefined _DSFillSoundBuffer()
    //         00447865     ADD        ESP,0xc
    //         00447868     TEST       EAX,EAX
    //         0044786a     JNZ        LAB_00447882
    //                              Dsutil.c:86 (10)
    //         0044786c     MOV        EAX,dword ptr [ESP]
    //         00447870     PUSH       EAX
    //         00447871     MOV        EDX,dword ptr [EAX]
    //         00447873     CALL       dword ptr [EDX + 0x8]
    //                              Dsutil.c:87 (2)
    //         00447876     XOR        EAX,EAX
    //                              Dsutil.c:97 (4)
    //         00447878     ADD        ESP,0x18
    //         0044787b     RET
    //                               LAB_0044787c                                                 XREF[1]:     0044784f(j)  
    //                              Dsutil.c:92 (2)
    //         0044787c     XOR        EAX,EAX
    //                              Dsutil.c:97 (4)
    //         0044787e     ADD        ESP,0x18
    //         00447881     RET
    //                               LAB_00447882                                                 XREF[2]:     00447825(j), 0044786a(j)  
    //                              Dsutil.c:92 (4)
    //         00447882     MOV        EAX,dword ptr [ESP]=>dsBD
    //                              Dsutil.c:97 (4)
    //         00447886     ADD        ESP,0x18
    //         00447889     RET
    //         0044788a     ??         90h
    //         0044788b     NOP
    //         0044788c     NOP
    //         0044788d     NOP
    //         0044788e     NOP
    //         0044788f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _DSReloadSoundBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0044789b(*)  
    //              uchar *           Stack[-0x8]:4  pbWaveData
    //                               _DSReloadSoundBuffer
    //                              Dsutil.c:106 (1)
    //         00447890     PUSH       ECX
    //                              Dsutil.c:111 (33)
    //         00447891     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00447895     PUSH       ESI
    //         00447896     LEA        EAX=>Stack[0x8],[ESP + 0x10]
    //         0044789a     PUSH       EDI
    //         0044789b     LEA        ECX=>local_4,[ESP + 0x8]
    //         0044789f     XOR        ESI,ESI
    //         004478a1     PUSH       EAX
    //         004478a2     PUSH       ECX
    //         004478a3     PUSH       ESI
    //         004478a4     PUSH       EDX
    //         004478a5     PUSH       ESI
    //         004478a6     CALL       _DSGetWaveResource                               undefined _DSGetWaveResource()
    //         004478ab     ADD        ESP,0x14
    //         004478ae     TEST       EAX,EAX
    //         004478b0     JZ         LAB_004478dc
    //                              Dsutil.c:114 (37)
    //         004478b2     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         004478b6     PUSH       EDI
    //         004478b7     MOV        EAX,dword ptr [EDI]
    //         004478b9     CALL       dword ptr [EAX + 0x50]
    //         004478bc     TEST       EAX,EAX
    //         004478be     JL         LAB_004478dc
    //         004478c0     MOV        ECX,dword ptr [ESP + 0x14]
    //         004478c4     MOV        EDX,dword ptr [ESP + 0x8]
    //         004478c8     PUSH       ECX
    //         004478c9     PUSH       EDX=>DAT_fffffff8
    //         004478ca     PUSH       EDI=>DAT_fffffff4
    //         004478cb     CALL       _DSFillSoundBuffer                               undefined _DSFillSoundBuffer()
    //         004478d0     ADD        ESP,0xc
    //         004478d3     TEST       EAX,EAX
    //         004478d5     JZ         LAB_004478dc
    //                              Dsutil.c:116 (5)
    //         004478d7     MOV        ESI,0x1
    //                               LAB_004478dc                                                 XREF[3]:     004478b0(j), 004478be(j), 
    //                                                                                                         004478d5(j)  
    //                              Dsutil.c:120 (2)
    //         004478dc     MOV        EAX,ESI
    //                              Dsutil.c:121 (4)
    //         004478de     POP        EDI
    //         004478df     POP        ESI
    //         004478e0     POP        ECX
    //         004478e1     RET
    //         004478e2     ??         90h
    //         004478e3     NOP
    //         004478e4     NOP
    //         004478e5     NOP
    //         004478e6     NOP
    //         004478e7     NOP
    //         004478e8     NOP
    //         004478e9     NOP
    //         004478ea     NOP
    //         004478eb     NOP
    //         004478ec     NOP
    //         004478ed     NOP
    //         004478ee     NOP
    //         004478ef     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _DSGetWaveResource()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _DSGetWaveResource                                           XREF[3]:     _DSLoadSoundBuffer:0044781b(c), 
    //                                                                                                         _DSReloadSoundBuffer:004478a6(c), 
    //                                                                                                         _SndObjCreate:0044796e(c)  
    //                              Dsutil.c:131 (77)
    //         004478f0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         004478f4     PUSH       ESI
    //         004478f5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         004478f9     PUSH       PTR_FUN_00570428                                 = 00564157
    //         004478fe     PUSH       EAX
    //         004478ff     PUSH       ESI
    //         00447900     CALL       dword ptr [->KERNEL32.DLL::FindResourceA]        = 0048ab3c
    //         00447906     TEST       EAX,EAX
    //         00447908     JZ         LAB_00447944
    //         0044790a     PUSH       EAX
    //         0044790b     PUSH       ESI
    //         0044790c     CALL       dword ptr [->KERNEL32.DLL::LoadResource]         = 0048ab2c
    //         00447912     TEST       EAX,EAX
    //         00447914     JZ         LAB_00447944
    //         00447916     PUSH       EAX
    //         00447917     CALL       dword ptr [->KERNEL32.DLL::LockResource]         = 0048ab1c
    //         0044791d     TEST       EAX,EAX
    //         0044791f     JZ         LAB_00447944
    //         00447921     MOV        ECX,dword ptr [ESP + 0x18]
    //         00447925     MOV        EDX,dword ptr [ESP + 0x14]
    //         00447929     PUSH       ECX
    //         0044792a     MOV        ECX,dword ptr [ESP + 0x14]
    //         0044792e     PUSH       EDX=>DAT_fffffff8
    //         0044792f     PUSH       ECX=>DAT_fffffff4
    //         00447930     PUSH       EAX=>DAT_fffffff0
    //         00447931     CALL       _DSParseWaveResource                             undefined _DSParseWaveResource()
    //         00447936     ADD        ESP,0x10
    //         00447939     TEST       EAX,EAX
    //         0044793b     JZ         LAB_00447944
    //                              Dsutil.c:141 (5)
    //         0044793d     MOV        EAX,0x1
    //                              Dsutil.c:145 (2)
    //         00447942     POP        ESI
    //         00447943     RET
    //                               LAB_00447944                                                 XREF[4]:     00447908(j), 00447914(j), 
    //                                                                                                         0044791f(j), 0044793b(j)  
    //                              Dsutil.c:144 (2)
    //         00447944     XOR        EAX,EAX
    //                              Dsutil.c:145 (2)
    //         00447946     POP        ESI
    //         00447947     RET
    //         00447948     ??         90h
    //         00447949     NOP
    //         0044794a     NOP
    //         0044794b     NOP
    //         0044794c     NOP
    //         0044794d     NOP
    //         0044794e     NOP
    //         0044794f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _SndObjCreate()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0044795b(*)  
    //              tWAVEFORMATEX *   Stack[-0x8]:4  pWaveHeader               XREF[1]:     00447953(*)  
    //              uint              Stack[-0xc]:4  cbData                    XREF[1]:     00447957(*)  
    //              uchar *           Stack[-0x10]:4 pbData
    //                               _SndObjCreate
    //                              Dsutil.c:152 (3)
    //         00447950     SUB        ESP,0xc
    //                              Dsutil.c:158 (43)
    //         00447953     LEA        EAX=>pWaveHeader,[ESP + 0x4]
    //         00447957     LEA        ECX=>cbData,[ESP]
    //         0044795b     LEA        EDX=>local_4,[ESP + 0x8]
    //         0044795f     PUSH       EBX
    //         00447960     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00447964     PUSH       EBP
    //         00447965     PUSH       ESI
    //         00447966     PUSH       EDI
    //         00447967     PUSH       EAX
    //         00447968     PUSH       ECX
    //         00447969     XOR        ESI,ESI
    //         0044796b     PUSH       EDX
    //         0044796c     PUSH       EBX
    //         0044796d     PUSH       ESI
    //         0044796e     CALL       _DSGetWaveResource                               undefined _DSGetWaveResource()
    //         00447973     ADD        ESP,0x14
    //         00447976     TEST       EAX,EAX
    //         00447978     JZ         LAB_00447a11
    //                              Dsutil.c:160 (13)
    //         0044797e     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00447982     MOV        EBP,0x1
    //         00447987     CMP        EDI,EBP
    //         00447989     JGE        LAB_0044798d
    //                              Dsutil.c:161 (2)
    //         0044798b     MOV        EDI,EBP
    //                               LAB_0044798d                                                 XREF[1]:     00447989(j)  
    //                              Dsutil.c:164 (22)
    //         0044798d     LEA        EAX,[EDI*0x4 + 0x10]
    //         00447994     PUSH       EAX
    //         00447995     PUSH       0x40
    //         00447997     CALL       dword ptr [->KERNEL32.DLL::LocalAlloc]           = 0048ab80
    //         0044799d     MOV        ESI,EAX
    //         0044799f     TEST       ESI,ESI
    //         004479a1     JZ         LAB_00447a11
    //                              Dsutil.c:168 (3)
    //         004479a3     MOV        dword ptr [ESI + 0x8],EDI
    //                              Dsutil.c:169 (4)
    //         004479a6     MOV        ECX,dword ptr [ESP + 0x10]
    //                              Dsutil.c:171 (23)
    //         004479aa     PUSH       EBX
    //         004479ab     MOV        EBX,dword ptr [ESP + 0x24]
    //         004479af     MOV        dword ptr [ESI],ECX
    //         004479b1     MOV        EDX,dword ptr [ESP + 0x18]
    //         004479b5     PUSH       EBX=>DAT_fffffff8
    //         004479b6     MOV        dword ptr [ESI + 0x4],EDX
    //         004479b9     CALL       _DSLoadSoundBuffer                               undefined _DSLoadSoundBuffer()
    //         004479be     MOV        dword ptr [ESI + 0x10],EAX
    //                              Dsutil.c:173 (10)
    //         004479c1     MOV        EAX,dword ptr [ESI + 0x8]
    //         004479c4     ADD        ESP,0x8
    //         004479c7     CMP        EAX,EBP
    //         004479c9     JLE        LAB_00447a11
    //                              Dsutil.c:190 (3)
    //         004479cb     LEA        EDI,[ESI + 0x14]
    //                               LAB_004479ce                                                 XREF[1]:     004479fa(j)  
    //                              Dsutil.c:176 (15)
    //         004479ce     MOV        ECX,dword ptr [ESI + 0x10]
    //         004479d1     MOV        EAX,dword ptr [EBX]
    //         004479d3     PUSH       EDI
    //         004479d4     PUSH       ECX=>DAT_fffffff8
    //         004479d5     PUSH       EBX=>DAT_fffffff4
    //         004479d6     CALL       dword ptr [EAX + 0x14]
    //         004479d9     TEST       EAX,EAX
    //         004479db     JGE        LAB_004479f1
    //                              Dsutil.c:178 (16)
    //         004479dd     MOV        EDX,dword ptr [ESP + 0x24]
    //         004479e1     PUSH       EDX
    //         004479e2     PUSH       EBX=>DAT_fffffff8
    //         004479e3     CALL       _DSLoadSoundBuffer                               undefined _DSLoadSoundBuffer()
    //         004479e8     ADD        ESP,0x8
    //         004479eb     MOV        dword ptr [EDI],EAX
    //                              Dsutil.c:179 (4)
    //         004479ed     TEST       EAX,EAX
    //         004479ef     JZ         LAB_00447a06
    //                               LAB_004479f1                                                 XREF[1]:     004479db(j)  
    //                              Dsutil.c:173 (11)
    //         004479f1     MOV        EAX,dword ptr [ESI + 0x8]
    //         004479f4     INC        EBP
    //         004479f5     ADD        EDI,0x4
    //         004479f8     CMP        EBP,EAX
    //         004479fa     JL         LAB_004479ce
    //                              Dsutil.c:189 (2)
    //         004479fc     MOV        EAX,ESI
    //                              Dsutil.c:190 (8)
    //         004479fe     POP        EDI
    //         004479ff     POP        ESI
    //         00447a00     POP        EBP
    //         00447a01     POP        EBX
    //         00447a02     ADD        ESP,0xc
    //         00447a05     RET
    //                               LAB_00447a06                                                 XREF[1]:     004479ef(j)  
    //                              Dsutil.c:180 (9)
    //         00447a06     PUSH       ESI
    //         00447a07     CALL       _SndObjDestroy                                   undefined _SndObjDestroy()
    //         00447a0c     ADD        ESP,0x4
    //                              Dsutil.c:181 (2)
    //         00447a0f     XOR        ESI,ESI
    //                               LAB_00447a11                                                 XREF[3]:     00447978(j), 004479a1(j), 
    //                                                                                                         004479c9(j)  
    //                              Dsutil.c:189 (2)
    //         00447a11     MOV        EAX,ESI
    //                              Dsutil.c:190 (8)
    //         00447a13     POP        EDI
    //         00447a14     POP        ESI
    //         00447a15     POP        EBP
    //         00447a16     POP        EBX
    //         00447a17     ADD        ESP,0xc
    //         00447a1a     RET
    //         00447a1b     ??         90h
    //         00447a1c     NOP
    //         00447a1d     NOP
    //         00447a1e     NOP
    //         00447a1f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _SndObjDestroy()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjDestroy                                               XREF[1]:     _SndObjCreate:00447a07(c)  
    //                              Dsutil.c:196 (1)
    //         00447a20     PUSH       EBX
    //                              Dsutil.c:197 (8)
    //         00447a21     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00447a25     TEST       EBX,EBX
    //         00447a27     JZ         LAB_00447a5d
    //                              Dsutil.c:201 (11)
    //         00447a29     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447a2c     PUSH       EDI
    //         00447a2d     XOR        EDI,EDI
    //         00447a2f     TEST       EAX,EAX
    //         00447a31     JLE        LAB_00447a55
    //         00447a33     PUSH       ESI
    //                              Dsutil.c:211 (32)
    //         00447a34     LEA        ESI,[EBX + 0x10]
    //                               LAB_00447a37                                                 XREF[1]:     00447a52(j)  
    //         00447a37     MOV        EAX,dword ptr [ESI]
    //         00447a39     TEST       EAX,EAX
    //         00447a3b     JZ         LAB_00447a49
    //         00447a3d     MOV        ECX,dword ptr [EAX]
    //         00447a3f     PUSH       EAX
    //         00447a40     CALL       dword ptr [ECX + 0x8]
    //         00447a43     MOV        dword ptr [ESI],0x0
    //                               LAB_00447a49                                                 XREF[1]:     00447a3b(j)  
    //         00447a49     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447a4c     INC        EDI
    //         00447a4d     ADD        ESI,0x4
    //         00447a50     CMP        EDI,EAX
    //         00447a52     JL         LAB_00447a37
    //                              Dsutil.c:196 (1)
    //         00447a54     POP        ESI
    //                               LAB_00447a55                                                 XREF[1]:     00447a31(j)  
    //                              Dsutil.c:209 (8)
    //         00447a55     PUSH       EBX
    //         00447a56     CALL       dword ptr [->KERNEL32.DLL::LocalFree]            = 0048ab74
    //         00447a5c     POP        EDI
    //                               LAB_00447a5d                                                 XREF[1]:     00447a27(j)  
    //                              Dsutil.c:211 (2)
    //         00447a5d     POP        EBX
    //         00447a5e     RET
    //         00447a5f     ??         90h
    //                              *                                               FUNCTION                                                *
    //                              undefined _SndObjGetFreeBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjGetFreeBuffer                                         XREF[1]:     _SndObjPlay:00447b3e(c)  
    //                              Dsutil.c:217 (1)
    //         00447a60     PUSH       EDI
    //                              Dsutil.c:220 (8)
    //         00447a61     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00447a65     TEST       EDI,EDI
    //         00447a67     JNZ        LAB_00447a6d
    //                              Dsutil.c:221 (2)
    //         00447a69     XOR        EAX,EAX
    //                              Dsutil.c:266 (2)
    //         00447a6b     POP        EDI
    //         00447a6c     RET
    //                               LAB_00447a6d                                                 XREF[1]:     00447a67(j)  
    //                              Dsutil.c:223 (16)
    //         00447a6d     MOV        EAX,dword ptr [EDI + 0xc]
    //         00447a70     PUSH       ESI
    //         00447a71     MOV        ESI,dword ptr [EDI + EAX*0x4 + 0x10]
    //         00447a75     TEST       ESI,ESI
    //         00447a77     JZ         LAB_00447b1a
    //                              Dsutil.c:228 (11)
    //         00447a7d     MOV        ECX,dword ptr [ESI]
    //         00447a7f     LEA        EDX=>Stack[0x4],[ESP + 0xc]
    //         00447a83     PUSH       EDX
    //         00447a84     PUSH       ESI
    //         00447a85     CALL       dword ptr [ECX + 0x24]
    //                              Dsutil.c:230 (4)
    //         00447a88     TEST       EAX,EAX
    //         00447a8a     JGE        LAB_00447a94
    //                              Dsutil.c:231 (8)
    //         00447a8c     MOV        dword ptr [ESP + 0xc],0x0
    //                               LAB_00447a94                                                 XREF[1]:     00447a8a(j)  
    //                              Dsutil.c:233 (11)
    //         00447a94     MOV        EAX,dword ptr [ESP + 0xc]
    //         00447a98     AND        EAX,0x1
    //         00447a9b     CMP        AL,0x1
    //         00447a9d     JNZ        LAB_00447aef
    //                              Dsutil.c:235 (8)
    //         00447a9f     MOV        EAX,dword ptr [EDI + 0x8]
    //         00447aa2     CMP        EAX,0x1
    //         00447aa5     JLE        LAB_00447aed
    //                              Dsutil.c:237 (13)
    //         00447aa7     MOV        EDX,dword ptr [EDI + 0xc]
    //         00447aaa     INC        EDX
    //         00447aab     MOV        ECX,EDX
    //         00447aad     MOV        dword ptr [EDI + 0xc],EDX
    //         00447ab0     CMP        ECX,EAX
    //         00447ab2     JL         LAB_00447abb
    //                              Dsutil.c:238 (7)
    //         00447ab4     MOV        dword ptr [EDI + 0xc],0x0
    //                               LAB_00447abb                                                 XREF[1]:     00447ab2(j)  
    //                              Dsutil.c:240 (3)
    //         00447abb     MOV        ECX,dword ptr [EDI + 0xc]
    //                              Dsutil.c:241 (15)
    //         00447abe     LEA        EAX,[ESP + 0xc]
    //         00447ac2     PUSH       EAX
    //         00447ac3     MOV        ESI,dword ptr [EDI + ECX*0x4 + 0x10]
    //         00447ac7     PUSH       ESI=>DAT_fffffff8
    //         00447ac8     MOV        EDX,dword ptr [ESI]
    //         00447aca     CALL       dword ptr [EDX + 0x24]
    //                              Dsutil.c:243 (16)
    //         00447acd     TEST       EAX,EAX
    //         00447acf     JL         LAB_00447aef
    //         00447ad1     MOV        ECX,dword ptr [ESP + 0xc]
    //         00447ad5     AND        ECX,0x1
    //         00447ad8     CMP        CL,0x1
    //         00447adb     JNZ        LAB_00447aef
    //                              Dsutil.c:245 (6)
    //         00447add     MOV        EDX,dword ptr [ESI]
    //         00447adf     PUSH       ESI
    //         00447ae0     CALL       dword ptr [EDX + 0x48]
    //                              Dsutil.c:246 (8)
    //         00447ae3     MOV        EAX,dword ptr [ESI]
    //         00447ae5     PUSH       0x0
    //         00447ae7     PUSH       ESI=>DAT_fffffff8
    //         00447ae8     CALL       dword ptr [EAX + 0x34]
    //                              Dsutil.c:249 (2)
    //         00447aeb     JMP        LAB_00447aef
    //                               LAB_00447aed                                                 XREF[1]:     00447aa5(j)  
    //                              Dsutil.c:251 (2)
    //         00447aed     XOR        ESI,ESI
    //                               LAB_00447aef                                                 XREF[4]:     00447a9d(j), 00447acf(j), 
    //                                                                                                         00447adb(j), 00447aeb(j)  
    //                              Dsutil.c:255 (11)
    //         00447aef     TEST       ESI,ESI
    //         00447af1     JZ         LAB_00447b1a
    //         00447af3     TEST       byte ptr [ESP + 0xc],0x2
    //         00447af8     JZ         LAB_00447b1a
    //                              Dsutil.c:258 (30)
    //         00447afa     MOV        ECX,dword ptr [ESI]
    //         00447afc     PUSH       ESI
    //         00447afd     CALL       dword ptr [ECX + 0x50]
    //         00447b00     TEST       EAX,EAX
    //         00447b02     JL         LAB_00447b18
    //         00447b04     MOV        EDX,dword ptr [EDI + 0x4]
    //         00447b07     MOV        EAX,dword ptr [EDI]
    //         00447b09     PUSH       EDX
    //         00447b0a     PUSH       EAX=>DAT_fffffff8
    //         00447b0b     PUSH       ESI=>DAT_fffffff4
    //         00447b0c     CALL       _DSFillSoundBuffer                               undefined _DSFillSoundBuffer()
    //         00447b11     ADD        ESP,0xc
    //         00447b14     TEST       EAX,EAX
    //         00447b16     JNZ        LAB_00447b1a
    //                               LAB_00447b18                                                 XREF[1]:     00447b02(j)  
    //                              Dsutil.c:260 (2)
    //         00447b18     XOR        ESI,ESI
    //                               LAB_00447b1a                                                 XREF[4]:     00447a77(j), 00447af1(j), 
    //                                                                                                         00447af8(j), 00447b16(j)  
    //                              Dsutil.c:265 (3)
    //         00447b1a     MOV        EAX,ESI
    //         00447b1c     POP        ESI
    //                              Dsutil.c:266 (2)
    //         00447b1d     POP        EDI
    //         00447b1e     RET
    //         00447b1f     ??         90h
    //                              *                                               FUNCTION                                                *
    //                              undefined _SndObjPlay()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjPlay
    //                              Dsutil.c:272 (11)
    //         00447b20     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00447b24     PUSH       ESI
    //         00447b25     XOR        ESI,ESI
    //         00447b27     TEST       EAX,EAX
    //         00447b29     JNZ        LAB_00447b2d
    //                              Dsutil.c:287 (2)
    //         00447b2b     POP        ESI
    //         00447b2c     RET
    //                               LAB_00447b2d                                                 XREF[1]:     00447b29(j)  
    //                              Dsutil.c:272 (1)
    //         00447b2d     PUSH       EBX
    //                              Dsutil.c:278 (15)
    //         00447b2e     MOV        EBX,dword ptr [ESP + Stack[0x8]]
    //         00447b32     TEST       BL,0x1
    //         00447b35     JZ         LAB_00447b3d
    //         00447b37     CMP        dword ptr [EAX + 0x8],0x1
    //         00447b3b     JNZ        LAB_00447b5e
    //                               LAB_00447b3d                                                 XREF[1]:     00447b35(j)  
    //                              Dsutil.c:280 (9)
    //         00447b3d     PUSH       EAX
    //         00447b3e     CALL       _SndObjGetFreeBuffer                             undefined _SndObjGetFreeBuffer()
    //         00447b43     ADD        ESP,0x4
    //                              Dsutil.c:281 (4)
    //         00447b46     TEST       EAX,EAX
    //         00447b48     JZ         LAB_00447b5e
    //                              Dsutil.c:282 (20)
    //         00447b4a     MOV        ECX,dword ptr [EAX]
    //         00447b4c     PUSH       EBX
    //         00447b4d     PUSH       0x0
    //         00447b4f     PUSH       0x0
    //         00447b51     PUSH       EAX
    //         00447b52     CALL       dword ptr [ECX + 0x30]
    //         00447b55     XOR        EDX,EDX
    //         00447b57     TEST       EAX,EAX
    //         00447b59     SETGE      DL
    //         00447b5c     MOV        ESI,EDX
    //                               LAB_00447b5e                                                 XREF[2]:     00447b3b(j), 00447b48(j)  
    //                              Dsutil.c:286 (3)
    //         00447b5e     MOV        EAX,ESI
    //         00447b60     POP        EBX
    //                              Dsutil.c:287 (2)
    //         00447b61     POP        ESI
    //         00447b62     RET
    //         00447b63     ??         90h
    //         00447b64     NOP
    //         00447b65     NOP
    //         00447b66     NOP
    //         00447b67     NOP
    //         00447b68     NOP
    //         00447b69     NOP
    //         00447b6a     NOP
    //         00447b6b     NOP
    //         00447b6c     NOP
    //         00447b6d     NOP
    //         00447b6e     NOP
    //         00447b6f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _SndObjStop()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _SndObjStop
    //                              Dsutil.c:293 (1)
    //         00447b70     PUSH       EBX
    //                              Dsutil.c:296 (8)
    //         00447b71     MOV        EBX,dword ptr [ESP + Stack[0x4]]
    //         00447b75     TEST       EBX,EBX
    //         00447b77     JNZ        LAB_00447b7d
    //                              Dsutil.c:297 (2)
    //         00447b79     XOR        EAX,EAX
    //                              Dsutil.c:306 (2)
    //         00447b7b     POP        EBX
    //         00447b7c     RET
    //                               LAB_00447b7d                                                 XREF[1]:     00447b77(j)  
    //                              Dsutil.c:299 (11)
    //         00447b7d     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447b80     PUSH       EDI
    //         00447b81     XOR        EDI,EDI
    //         00447b83     TEST       EAX,EAX
    //         00447b85     JLE        LAB_00447ba9
    //         00447b87     PUSH       ESI
    //                              Dsutil.c:306 (32)
    //         00447b88     LEA        ESI,[EBX + 0x10]
    //                               LAB_00447b8b                                                 XREF[1]:     00447ba6(j)  
    //         00447b8b     MOV        EAX,dword ptr [ESI]
    //         00447b8d     PUSH       EAX
    //         00447b8e     MOV        ECX,dword ptr [EAX]
    //         00447b90     CALL       dword ptr [ECX + 0x48]
    //         00447b93     MOV        EAX,dword ptr [ESI]
    //         00447b95     PUSH       0x0
    //         00447b97     PUSH       EAX=>DAT_fffffff8
    //         00447b98     MOV        EDX,dword ptr [EAX]
    //         00447b9a     CALL       dword ptr [EDX + 0x34]
    //         00447b9d     MOV        EAX,dword ptr [EBX + 0x8]
    //         00447ba0     INC        EDI
    //         00447ba1     ADD        ESI,0x4
    //         00447ba4     CMP        EDI,EAX
    //         00447ba6     JL         LAB_00447b8b
    //                              Dsutil.c:293 (2)
    //         00447ba8     POP        ESI
    //                               LAB_00447ba9                                                 XREF[1]:     00447b85(j)  
    //         00447ba9     POP        EDI
    //                              Dsutil.c:305 (5)
    //         00447baa     MOV        EAX,0x1
    //                              Dsutil.c:306 (2)
    //         00447baf     POP        EBX
    //         00447bb0     RET
    //         00447bb1     ??         90h
    //         00447bb2     NOP
    //         00447bb3     NOP
    //         00447bb4     NOP
    //         00447bb5     NOP
    //         00447bb6     NOP
    //         00447bb7     NOP
    //         00447bb8     NOP
    //         00447bb9     NOP
    //         00447bba     NOP
    //         00447bbb     NOP
    //         00447bbc     NOP
    //         00447bbd     NOP
    //         00447bbe     NOP
    //         00447bbf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _DSFillSoundBuffer()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00447bf2(*)  
    //              void *            Stack[-0x8]:4  pMem1
    //                               _DSFillSoundBuffer                                           XREF[3]:     _DSLoadSoundBuffer:00447860(c), 
    //                                                                                                         _DSReloadSoundBuffer:004478cb(c), 
    //                                                                                                         _SndObjGetFreeBuffer:00447b0c(c)  
    //                              Dsutil.c:312 (2)
    //         00447bc0     PUSH       ECX
    //         00447bc1     PUSH       ESI
    //                              Dsutil.c:313 (29)
    //         00447bc2     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00447bc6     TEST       ESI,ESI
    //         00447bc8     PUSH       EDI
    //         00447bc9     JZ         LAB_00447c55
    //         00447bcf     MOV        EDI,dword ptr [ESP + Stack[0x8]]
    //         00447bd3     TEST       EDI,EDI
    //         00447bd5     JZ         LAB_00447c55
    //         00447bd7     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         00447bdb     TEST       EAX,EAX
    //         00447bdd     JZ         LAB_00447c55
    //                              Dsutil.c:319 (35)
    //         00447bdf     LEA        EDX=>Stack[0x8],[ESP + 0x14]
    //         00447be3     PUSH       0x0
    //         00447be5     PUSH       EDX
    //         00447be6     LEA        EDX=>Stack[0xc],[ESP + 0x20]
    //         00447bea     MOV        ECX,dword ptr [ESI]
    //         00447bec     PUSH       EDX
    //         00447bed     LEA        EDX=>Stack[0x4],[ESP + 0x1c]
    //         00447bf1     PUSH       EDX
    //         00447bf2     LEA        EDX=>local_4,[ESP + 0x18]
    //         00447bf6     PUSH       EDX
    //         00447bf7     PUSH       EAX
    //         00447bf8     PUSH       0x0
    //         00447bfa     PUSH       ESI
    //         00447bfb     CALL       dword ptr [ECX + 0x2c]
    //         00447bfe     TEST       EAX,EAX
    //         00447c00     JL         LAB_00447c55
    //                              Dsutil.c:321 (16)
    //         00447c02     MOV        EAX,dword ptr [ESP + 0x10]
    //         00447c06     MOV        ECX,dword ptr [ESP + 0x8]
    //         00447c0a     PUSH       EAX
    //         00447c0b     PUSH       EDI=>DAT_fffffff8
    //         00447c0c     PUSH       ECX=>DAT_fffffff4
    //         00447c0d     CALL       memcpy                                           undefined memcpy()
    //                              Dsutil.c:323 (11)
    //         00447c12     MOV        EAX,dword ptr [ESP + 0x20]
    //         00447c16     ADD        ESP,0xc
    //         00447c19     TEST       EAX,EAX
    //         00447c1b     JZ         LAB_00447c36
    //                              Dsutil.c:324 (25)
    //         00447c1d     MOV        EDX,dword ptr [ESP + 0x10]
    //         00447c21     PUSH       EAX
    //         00447c22     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00447c26     ADD        EDX,EDI
    //         00447c28     PUSH       EDX=>DAT_fffffff8
    //         00447c29     PUSH       EAX=>DAT_fffffff4
    //         00447c2a     CALL       memcpy                                           undefined memcpy()
    //         00447c2f     MOV        EAX,dword ptr [ESP + 0x20]
    //         00447c33     ADD        ESP,0xc
    //                               LAB_00447c36                                                 XREF[1]:     00447c1b(j)  
    //                              Dsutil.c:326 (22)
    //         00447c36     MOV        EDX,dword ptr [ESP + 0x18]
    //         00447c3a     MOV        ECX,dword ptr [ESI]
    //         00447c3c     PUSH       EAX
    //         00447c3d     MOV        EAX,dword ptr [ESP + 0x14]
    //         00447c41     PUSH       EDX=>DAT_fffffff8
    //         00447c42     MOV        EDX,dword ptr [ESP + 0x10]
    //         00447c46     PUSH       EAX=>DAT_fffffff4
    //         00447c47     PUSH       EDX=>DAT_fffffff0
    //         00447c48     PUSH       ESI
    //         00447c49     CALL       dword ptr [ECX + 0x4c]
    //                              Dsutil.c:327 (5)
    //         00447c4c     MOV        EAX,0x1
    //                              Dsutil.c:332 (10)
    //         00447c51     POP        EDI
    //         00447c52     POP        ESI
    //         00447c53     POP        ECX
    //         00447c54     RET
    //                               LAB_00447c55                                                 XREF[4]:     00447bc9(j), 00447bd5(j), 
    //                                                                                                         00447bdd(j), 00447c00(j)  
    //         00447c55     POP        EDI
    //         00447c56     XOR        EAX,EAX
    //         00447c58     POP        ESI
    //         00447c59     POP        ECX
    //         00447c5a     RET
    //         00447c5b     ??         90h
    //         00447c5c     NOP
    //         00447c5d     NOP
    //         00447c5e     NOP
    //         00447c5f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _DSParseWaveResource()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _DSParseWaveResource                                         XREF[1]:     _DSGetWaveResource:00447931(c)  
    //                              Dsutil.c:338 (2)
    //         00447c60     PUSH       EBX
    //         00447c61     PUSH       EBP
    //                              Dsutil.c:345 (10)
    //         00447c62     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         00447c66     PUSH       ESI
    //         00447c67     TEST       EBP,EBP
    //         00447c69     PUSH       EDI
    //         00447c6a     JZ         LAB_00447c73
    //                              Dsutil.c:346 (7)
    //         00447c6c     MOV        dword ptr [EBP],0x0
    //                               LAB_00447c73                                                 XREF[1]:     00447c6a(j)  
    //                              Dsutil.c:348 (8)
    //         00447c73     MOV        EDI,dword ptr [ESP + Stack[0xc]]
    //         00447c77     TEST       EDI,EDI
    //         00447c79     JZ         LAB_00447c81
    //                              Dsutil.c:349 (6)
    //         00447c7b     MOV        dword ptr [EDI],0x0
    //                               LAB_00447c81                                                 XREF[1]:     00447c79(j)  
    //                              Dsutil.c:351 (8)
    //         00447c81     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         00447c85     TEST       EBX,EBX
    //         00447c87     JZ         LAB_00447c8f
    //                              Dsutil.c:352 (6)
    //         00447c89     MOV        dword ptr [EBX],0x0
    //                               LAB_00447c8f                                                 XREF[1]:     00447c87(j)  
    //                              Dsutil.c:355 (4)
    //         00447c8f     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //                              Dsutil.c:356 (9)
    //         00447c93     MOV        EDX,dword ptr [ECX + 0x4]
    //         00447c96     LEA        EAX,[ECX + 0x4]
    //         00447c99     ADD        EAX,0x4
    //                              Dsutil.c:357 (5)
    //         00447c9c     MOV        ESI,dword ptr [EAX]
    //         00447c9e     ADD        EAX,0x4
    //                              Dsutil.c:359 (12)
    //         00447ca1     CMP        dword ptr [ECX],0x46464952
    //         00447ca7     JNZ        LAB_00447d49
    //                              Dsutil.c:362 (12)
    //         00447cad     CMP        ESI,0x45564157
    //         00447cb3     JNZ        LAB_00447d49
    //                              Dsutil.c:365 (4)
    //         00447cb9     LEA        ESI,[EDX + EAX*0x1 + -0x4]
    //                              Dsutil.c:367 (8)
    //         00447cbd     CMP        EAX,ESI
    //         00447cbf     JNC        LAB_00447d49
    //                               LAB_00447cc5                                                 XREF[1]:     00447d36(j)  
    //                              Dsutil.c:369 (2)
    //         00447cc5     MOV        ECX,dword ptr [EAX]
    //                              Dsutil.c:370 (9)
    //         00447cc7     MOV        EDX,dword ptr [EAX + 0x4]
    //         00447cca     ADD        EAX,0x4
    //         00447ccd     ADD        EAX,0x4
    //                              Dsutil.c:372 (16)
    //         00447cd0     CMP        ECX,0x20746d66
    //         00447cd6     JZ         LAB_00447d0a
    //         00447cd8     CMP        ECX,0x61746164
    //         00447cde     JNZ        LAB_00447d2e
    //                              Dsutil.c:392 (18)
    //         00447ce0     TEST       EDI,EDI
    //         00447ce2     JZ         LAB_00447ce9
    //         00447ce4     CMP        dword ptr [EDI],0x0
    //         00447ce7     JZ         LAB_00447cf2
    //                               LAB_00447ce9                                                 XREF[1]:     00447ce2(j)  
    //         00447ce9     TEST       EBX,EBX
    //         00447ceb     JZ         LAB_00447d2e
    //         00447ced     CMP        dword ptr [EBX],0x0
    //         00447cf0     JNZ        LAB_00447d2e
    //                               LAB_00447cf2                                                 XREF[1]:     00447ce7(j)  
    //                              Dsutil.c:394 (4)
    //         00447cf2     TEST       EDI,EDI
    //         00447cf4     JZ         LAB_00447cf8
    //                              Dsutil.c:395 (2)
    //         00447cf6     MOV        dword ptr [EDI],EAX
    //                               LAB_00447cf8                                                 XREF[1]:     00447cf4(j)  
    //                              Dsutil.c:397 (4)
    //         00447cf8     TEST       EBX,EBX
    //         00447cfa     JZ         LAB_00447cfe
    //                              Dsutil.c:398 (2)
    //         00447cfc     MOV        dword ptr [EBX],EDX
    //                               LAB_00447cfe                                                 XREF[1]:     00447cfa(j)  
    //                              Dsutil.c:400 (10)
    //         00447cfe     TEST       EBP,EBP
    //         00447d00     JZ         LAB_00447d3f
    //         00447d02     CMP        dword ptr [EBP],0x0
    //         00447d06     JNZ        LAB_00447d3f
    //                              Dsutil.c:403 (2)
    //         00447d08     JMP        LAB_00447d2e
    //                               LAB_00447d0a                                                 XREF[1]:     00447cd6(j)  
    //                              Dsutil.c:375 (10)
    //         00447d0a     TEST       EBP,EBP
    //         00447d0c     JZ         LAB_00447d2e
    //         00447d0e     CMP        dword ptr [EBP],0x0
    //         00447d12     JNZ        LAB_00447d2e
    //                              Dsutil.c:377 (5)
    //         00447d14     CMP        EDX,0xe
    //         00447d17     JC         LAB_00447d49
    //                              Dsutil.c:383 (21)
    //         00447d19     TEST       EDI,EDI
    //         00447d1b     MOV        dword ptr [EBP],EAX
    //         00447d1e     JZ         LAB_00447d25
    //         00447d20     CMP        dword ptr [EDI],0x0
    //         00447d23     JZ         LAB_00447d2e
    //                               LAB_00447d25                                                 XREF[1]:     00447d1e(j)  
    //         00447d25     TEST       EBX,EBX
    //         00447d27     JZ         LAB_00447d3f
    //         00447d29     CMP        dword ptr [EBX],0x0
    //         00447d2c     JNZ        LAB_00447d3f
    //                               LAB_00447d2e                                                 XREF[7]:     00447cde(j), 00447ceb(j), 
    //                                                                                                         00447cf0(j), 00447d08(j), 
    //                                                                                                         00447d0c(j), 00447d12(j), 
    //                                                                                                         00447d23(j)  
    //                              Dsutil.c:406 (10)
    //         00447d2e     INC        EDX
    //         00447d2f     AND        EDX,0xfffffffe
    //         00447d32     ADD        EAX,EDX
    //         00447d34     CMP        EAX,ESI
    //         00447d36     JC         LAB_00447cc5
    //                              Dsutil.c:410 (2)
    //         00447d38     XOR        EAX,EAX
    //                              Dsutil.c:411 (5)
    //         00447d3a     POP        EDI
    //         00447d3b     POP        ESI
    //         00447d3c     POP        EBP
    //         00447d3d     POP        EBX
    //         00447d3e     RET
    //                               LAB_00447d3f                                                 XREF[4]:     00447d00(j), 00447d06(j), 
    //                                                                                                         00447d27(j), 00447d2c(j)  
    //                              Dsutil.c:385 (5)
    //         00447d3f     MOV        EAX,0x1
    //                              Dsutil.c:411 (12)
    //         00447d44     POP        EDI
    //         00447d45     POP        ESI
    //         00447d46     POP        EBP
    //         00447d47     POP        EBX
    //         00447d48     RET
    //                              Symbol Ref: No symbol: exit
    //                               LAB_00447d49                                                 XREF[4]:     00447ca7(j), 00447cb3(j), 
    //                                                                                                         00447cbf(j), 00447d17(j)  
    //         00447d49     POP        EDI
    //         00447d4a     POP        ESI
    //         00447d4b     POP        EBP
    //         00447d4c     XOR        EAX,EAX
    //         00447d4e     POP        EBX
    //         00447d4f     RET
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveOpenFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ckIn
    //              pcmwaveformat_    Stack[-0x28]   pcmWaveFormat
    //                               _WaveOpenFile                                                XREF[2]:     _WaveLoadFile:00448506(c), 
    //                                                                                                         ds_stream_file:00448731(c)  
    //                              Dsutil.c:496 (4)
    //         00447d50     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //                              Dsutil.c:509 (37)
    //         00447d54     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00447d58     SUB        ESP,0x24
    //         00447d5b     MOV        dword ptr [EAX],0x0
    //         00447d61     PUSH       EBX
    //         00447d62     PUSH       EBP
    //         00447d63     PUSH       ESI
    //         00447d64     PUSH       EDI
    //         00447d65     PUSH       0x10000
    //         00447d6a     PUSH       0x0
    //         00447d6c     PUSH       ECX
    //         00447d6d     CALL       dword ptr [->WINMM.DLL::mmioOpenA]               = 0048b48e
    //         00447d73     MOV        EDI,EAX
    //         00447d75     TEST       EDI,EDI
    //         00447d77     JNZ        LAB_00447d83
    //                              Dsutil.c:511 (5)
    //         00447d79     MOV        ESI,0xe100
    //                              Dsutil.c:512 (5)
    //         00447d7e     JMP        LAB_00447eb8
    //                               LAB_00447d83                                                 XREF[1]:     00447d77(j)  
    //                              Dsutil.c:515 (28)
    //         00447d83     MOV        EBX,dword ptr [ESP + 0x44]
    //         00447d87     MOV        EBP,dword ptr [->WINMM.DLL::mmioDescend]         = 0048b480
    //         00447d8d     PUSH       0x0
    //         00447d8f     PUSH       0x0
    //         00447d91     PUSH       EBX
    //         00447d92     PUSH       EDI
    //         00447d93     CALL       EBP=>WINMM.DLL::mmioDescend
    //         00447d95     MOV        ESI,EAX
    //         00447d97     TEST       ESI,ESI
    //         00447d99     JNZ        LAB_00447eb8
    //                              Dsutil.c:521 (25)
    //         00447d9f     CMP        dword ptr [EBX],0x46464952
    //         00447da5     JNZ        LAB_00447eb3
    //         00447dab     CMP        dword ptr [EBX + 0x8],0x45564157
    //         00447db2     JNZ        LAB_00447eb3
    //                              Dsutil.c:529 (29)
    //         00447db8     PUSH       0x10
    //         00447dba     LEA        EDX,[ESP + 0x24]
    //         00447dbe     PUSH       EBX
    //         00447dbf     PUSH       EDX
    //         00447dc0     PUSH       EDI
    //         00447dc1     MOV        dword ptr [ESP + 0x30],0x20746d66
    //         00447dc9     CALL       EBP=>WINMM.DLL::mmioDescend
    //         00447dcb     MOV        ESI,EAX
    //         00447dcd     TEST       ESI,ESI
    //         00447dcf     JNZ        LAB_00447eb8
    //                              Dsutil.c:537 (5)
    //         00447dd5     CMP        dword ptr [ESP + 0x24],0x10
    //                              Dsutil.c:540 (6)
    //         00447dda     JC         LAB_00447eb3
    //                              Dsutil.c:544 (21)
    //         00447de0     MOV        EBX,dword ptr [->WINMM.DLL::mmioRead]            = 0048b474
    //         00447de6     LEA        EAX,[ESP + 0x10]
    //         00447dea     PUSH       0x10
    //         00447dec     PUSH       EAX
    //         00447ded     PUSH       EDI
    //         00447dee     CALL       EBX=>WINMM.DLL::mmioRead
    //         00447df0     CMP        EAX,0x10
    //         00447df3     JZ         LAB_00447dff
    //                              Dsutil.c:546 (5)
    //         00447df5     MOV        ESI,0xe102
    //                              Dsutil.c:547 (5)
    //         00447dfa     JMP        LAB_00447eb8
    //                               LAB_00447dff                                                 XREF[1]:     00447df3(j)  
    //                              Dsutil.c:554 (8)
    //         00447dff     CMP        word ptr [ESP + 0x10],0x1
    //         00447e05     JNZ        LAB_00447e0f
    //                              Dsutil.c:555 (6)
    //         00447e07     XOR        EAX,EAX
    //         00447e09     MOV        dword ptr [ESP + 0x38],EAX
    //                              Dsutil.c:557 (2)
    //         00447e0d     JMP        LAB_00447e2c
    //                               LAB_00447e0f                                                 XREF[1]:     00447e05(j)  
    //                              Dsutil.c:561 (15)
    //         00447e0f     LEA        ECX,[ESP + 0x38]
    //         00447e13     PUSH       0x2
    //         00447e15     PUSH       ECX
    //         00447e16     PUSH       EDI
    //         00447e17     CALL       EBX=>WINMM.DLL::mmioRead
    //         00447e19     CMP        EAX,0x2
    //         00447e1c     JZ         LAB_00447e28
    //                              Dsutil.c:563 (5)
    //         00447e1e     MOV        ESI,0xe102
    //                              Dsutil.c:564 (9)
    //         00447e23     JMP        LAB_00447eb8
    //                               LAB_00447e28                                                 XREF[1]:     00447e1c(j)  
    //         00447e28     MOV        EAX,dword ptr [ESP + 0x38]
    //                               LAB_00447e2c                                                 XREF[1]:     00447e0d(j)  
    //                              Dsutil.c:570 (27)
    //         00447e2c     AND        EAX,0xffff
    //         00447e31     ADD        EAX,0x12
    //         00447e34     PUSH       EAX
    //         00447e35     PUSH       0x0
    //         00447e37     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         00447e3d     MOV        ESI,dword ptr [ESP + 0x40]
    //         00447e41     TEST       EAX,EAX
    //         00447e43     MOV        dword ptr [ESI],EAX
    //         00447e45     JNZ        LAB_00447e4e
    //                              Dsutil.c:572 (5)
    //         00447e47     MOV        ESI,0xe000
    //                              Dsutil.c:573 (2)
    //         00447e4c     JMP        LAB_00447eb8
    //                               LAB_00447e4e                                                 XREF[1]:     00447e45(j)  
    //                              Dsutil.c:577 (13)
    //         00447e4e     LEA        EDX,[ESP + 0x10]
    //         00447e52     PUSH       0x10
    //         00447e54     PUSH       EDX
    //         00447e55     PUSH       EAX
    //         00447e56     CALL       memcpy                                           undefined memcpy()
    //                              Dsutil.c:578 (14)
    //         00447e5b     MOV        EAX,dword ptr [ESI]
    //         00447e5d     MOV        CX,word ptr [ESP + 0x44]
    //         00447e62     ADD        ESP,0xc
    //         00447e65     MOV        word ptr [EAX + 0x10],CX
    //                              Dsutil.c:581 (9)
    //         00447e69     MOV        EAX,dword ptr [ESP + 0x38]
    //         00447e6d     TEST       AX,AX
    //         00447e70     JZ         LAB_00447e8f
    //                              Dsutil.c:584 (27)
    //         00447e72     MOV        EDX,dword ptr [ESI]
    //         00447e74     AND        EAX,0xffff
    //         00447e79     ADD        EDX,0x12
    //         00447e7c     PUSH       EAX
    //         00447e7d     PUSH       EDX
    //         00447e7e     PUSH       EDI
    //         00447e7f     CALL       EBX=>WINMM.DLL::mmioRead
    //         00447e81     MOV        ECX,dword ptr [ESP + 0x38]
    //         00447e85     AND        ECX,0xffff
    //         00447e8b     CMP        EAX,ECX
    //                              Dsutil.c:587 (2)
    //         00447e8d     JNZ        LAB_00447eb3
    //                               LAB_00447e8f                                                 XREF[1]:     00447e70(j)  
    //                              Dsutil.c:592 (20)
    //         00447e8f     LEA        EDX,[ESP + 0x20]
    //         00447e93     PUSH       0x0
    //         00447e95     PUSH       EDX
    //         00447e96     PUSH       EDI
    //         00447e97     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         00447e9d     MOV        ESI,EAX
    //         00447e9f     TEST       ESI,ESI
    //         00447ea1     JNZ        LAB_00447eb8
    //                              Dsutil.c:615 (6)
    //         00447ea3     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00447ea7     MOV        dword ptr [EAX],EDI
    //                              Dsutil.c:617 (2)
    //         00447ea9     MOV        EAX,ESI
    //                              Dsutil.c:619 (8)
    //         00447eab     POP        EDI
    //         00447eac     POP        ESI
    //         00447ead     POP        EBP
    //         00447eae     POP        EBX
    //         00447eaf     ADD        ESP,0x24
    //         00447eb2     RET
    //                               LAB_00447eb3                                                 XREF[4]:     00447da5(j), 00447db2(j), 
    //                                                                                                         00447dda(j), 00447e8d(j)  
    //                              Dsutil.c:523 (5)
    //         00447eb3     MOV        ESI,0xe101
    //                              Symbol Ref: No symbol: ERROR_READING_WAVE
    //                               LAB_00447eb8                                                 XREF[7]:     00447d7e(j), 00447d99(j), 
    //                                                                                                         00447dcf(j), 00447dfa(j), 
    //                                                                                                         00447e23(j), 00447e4c(j), 
    //                                                                                                         00447ea1(j)  
    //                              Dsutil.c:602 (10)
    //         00447eb8     MOV        EBX,dword ptr [ESP + 0x40]
    //         00447ebc     MOV        EAX,dword ptr [EBX]
    //         00447ebe     TEST       EAX,EAX
    //         00447ec0     JZ         LAB_00447ecf
    //                              Dsutil.c:604 (7)
    //         00447ec2     PUSH       EAX
    //         00447ec3     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:605 (6)
    //         00447ec9     MOV        dword ptr [EBX],0x0
    //                               LAB_00447ecf                                                 XREF[1]:     00447ec0(j)  
    //                              Dsutil.c:608 (4)
    //         00447ecf     TEST       EDI,EDI
    //         00447ed1     JZ         LAB_00447ede
    //                              Dsutil.c:610 (9)
    //         00447ed3     PUSH       0x0
    //         00447ed5     PUSH       EDI
    //         00447ed6     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                              Dsutil.c:611 (2)
    //         00447edc     XOR        EDI,EDI
    //                              Symbol Ref: No symbol: TEMPCLEANUP
    //                               LAB_00447ede                                                 XREF[1]:     00447ed1(j)  
    //                              Dsutil.c:615 (6)
    //         00447ede     MOV        EAX,dword ptr [ESP + 0x3c]
    //         00447ee2     MOV        dword ptr [EAX],EDI
    //                              Dsutil.c:617 (2)
    //         00447ee4     MOV        EAX,ESI
    //                              Dsutil.c:619 (8)
    //         00447ee6     POP        EDI
    //         00447ee7     POP        ESI
    //         00447ee8     POP        EBP
    //         00447ee9     POP        EBX
    //         00447eea     ADD        ESP,0x24
    //         00447eed     RET
    //         00447eee     ??         90h
    //         00447eef     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveStartDataRead()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveStartDataRead                                           XREF[5]:     _WaveLoadFile:00448523(c), 
    //                                                                                                         ds_stream_file:00448782(c), 
    //                                                                                                         ds_stream_file:004488de(c), 
    //                                                                                                         ds_stream_time_func:00448eae(c), 
    //                                                                                                         ds_stream_time_func:00449010(c)  
    //                              Dsutil.c:631 (1)
    //         00447ef0     PUSH       ESI
    //                              Dsutil.c:637 (32)
    //         00447ef1     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         00447ef5     PUSH       EDI
    //         00447ef6     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         00447efa     MOV        EAX,dword ptr [ESI + 0xc]
    //         00447efd     PUSH       0x0
    //         00447eff     MOV        ECX,dword ptr [EDI]
    //         00447f01     ADD        EAX,0x4
    //         00447f04     PUSH       EAX
    //         00447f05     PUSH       ECX
    //         00447f06     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //         00447f0c     CMP        EAX,-0x1
    //         00447f0f     JNZ        LAB_00447f19
    //                              Dsutil.c:640 (5)
    //         00447f11     MOV        EAX,0x1
    //                              Dsutil.c:657 (3)
    //         00447f16     POP        EDI
    //         00447f17     POP        ESI
    //         00447f18     RET
    //                               LAB_00447f19                                                 XREF[1]:     00447f0f(j)  
    //                              Dsutil.c:645 (4)
    //         00447f19     MOV        EAX,dword ptr [ESP + 0x10]
    //                              Dsutil.c:646 (19)
    //         00447f1d     PUSH       0x10
    //         00447f1f     PUSH       ESI=>DAT_fffffff8
    //         00447f20     PUSH       EAX=>DAT_fffffff4
    //         00447f21     MOV        dword ptr [EAX],0x61746164
    //         00447f27     MOV        EDX,dword ptr [EDI]
    //         00447f29     PUSH       EDX=>DAT_fffffff0
    //         00447f2a     CALL       dword ptr [->WINMM.DLL::mmioDescend]             = 0048b480
    //                              Dsutil.c:657 (3)
    //         00447f30     POP        EDI
    //         00447f31     POP        ESI
    //         00447f32     RET
    //         00447f33     ??         90h
    //         00447f34     NOP
    //         00447f35     NOP
    //         00447f36     NOP
    //         00447f37     NOP
    //         00447f38     NOP
    //         00447f39     NOP
    //         00447f3a     NOP
    //         00447f3b     NOP
    //         00447f3c     NOP
    //         00447f3d     NOP
    //         00447f3e     NOP
    //         00447f3f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveReadFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMIOINFO         Stack[-0x4c]   mmioinfoIn                XREF[0,1]:   00447f47(*)  
    //                               _WaveReadFile                                                XREF[7]:     _WaveLoadFile:0044855f(c), 
    //                                                                                                         ds_stream_file:004488a3(c), 
    //                                                                                                         ds_stream_file:004488fd(c), 
    //                                                                                                         ds_stream_time_func:00448de9(c), 
    //                                                                                                         ds_stream_time_func:00448ecd(c), 
    //                                                                                                         ds_stream_time_func:00448f47(c), 
    //                                                                                                         ds_stream_time_func:0044902f(c)  
    //                              Dsutil.c:680 (37)
    //         00447f40     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         00447f44     SUB        ESP,0x48
    //         00447f47     LEA        EAX=>mmioinfoIn.fccIOProc,[ESP]
    //         00447f4b     PUSH       EBX
    //         00447f4c     PUSH       EBP
    //         00447f4d     PUSH       ESI
    //         00447f4e     PUSH       EDI
    //         00447f4f     PUSH       0x0
    //         00447f51     PUSH       EAX
    //         00447f52     PUSH       ECX
    //         00447f53     CALL       dword ptr [->WINMM.DLL::mmioGetInfo]             = 0048b4c2
    //         00447f59     NEG        EAX
    //         00447f5b     SBB        EAX,EAX
    //         00447f5d     NEG        EAX
    //         00447f5f     JNZ        LAB_00447ffb
    //                              Dsutil.c:694 (15)
    //         00447f65     MOV        ECX,dword ptr [ESP + 0x68]
    //         00447f69     MOV        EBX,dword ptr [ESP + 0x60]
    //         00447f6d     MOV        EAX,dword ptr [ECX + 0x4]
    //         00447f70     CMP        EBX,EAX
    //         00447f72     JBE        LAB_00447f76
    //                              Dsutil.c:695 (2)
    //         00447f74     MOV        EBX,EAX
    //                               LAB_00447f76                                                 XREF[1]:     00447f72(j)  
    //                              Dsutil.c:697 (2)
    //         00447f76     SUB        EAX,EBX
    //                              Dsutil.c:699 (17)
    //         00447f78     XOR        EDI,EDI
    //         00447f7a     TEST       EBX,EBX
    //         00447f7c     MOV        dword ptr [ECX + 0x4],EAX
    //         00447f7f     JBE        LAB_00447fe5
    //         00447f81     MOV        EBP,dword ptr [ESP + 0x64]
    //         00447f85     MOV        ECX,dword ptr [ESP + 0x2c]
    //                               LAB_00447f89                                                 XREF[1]:     00447fe3(j)  
    //                              Dsutil.c:702 (8)
    //         00447f89     MOV        ESI,dword ptr [ESP + 0x30]
    //         00447f8d     CMP        ECX,ESI
    //         00447f8f     JNZ        LAB_00447fb3
    //                              Dsutil.c:704 (22)
    //         00447f91     MOV        EAX,dword ptr [ESP + 0x5c]
    //         00447f95     LEA        EDX,[ESP + 0x10]
    //         00447f99     PUSH       0x0
    //         00447f9b     PUSH       EDX=>DAT_fffffff8
    //         00447f9c     PUSH       EAX=>DAT_fffffff4
    //         00447f9d     CALL       dword ptr [->WINMM.DLL::mmioAdvance]             = 0048b4b4
    //         00447fa3     TEST       EAX,EAX
    //         00447fa5     JNZ        LAB_00447ffb
    //                              Dsutil.c:708 (12)
    //         00447fa7     MOV        ECX,dword ptr [ESP + 0x2c]
    //         00447fab     MOV        ESI,dword ptr [ESP + 0x30]
    //         00447faf     CMP        ECX,ESI
    //         00447fb1     JZ         LAB_0044801b
    //                               LAB_00447fb3                                                 XREF[1]:     00447f8f(j)  
    //                              Dsutil.c:717 (6)
    //         00447fb3     MOV        EAX,EBX
    //         00447fb5     SUB        ESI,ECX
    //         00447fb7     SUB        EAX,EDI
    //                              Dsutil.c:718 (4)
    //         00447fb9     CMP        EAX,ESI
    //         00447fbb     JNC        LAB_00447fc7
    //                              Dsutil.c:721 (8)
    //         00447fbd     PUSH       EAX
    //         00447fbe     PUSH       ECX=>DAT_fffffff8
    //         00447fbf     LEA        ECX,[EDI + EBP*0x1]
    //         00447fc2     MOV        ESI,EAX
    //         00447fc4     PUSH       ECX=>DAT_fffffff4
    //                              Dsutil.c:723 (2)
    //         00447fc5     JMP        LAB_00447fcd
    //                               LAB_00447fc7                                                 XREF[1]:     00447fbb(j)  
    //                              Dsutil.c:725 (11)
    //         00447fc7     PUSH       ESI
    //         00447fc8     LEA        EDX,[EDI + EBP*0x1]
    //         00447fcb     PUSH       ECX=>DAT_fffffff8
    //         00447fcc     PUSH       EDX=>DAT_fffffff4
    //                               LAB_00447fcd                                                 XREF[1]:     00447fc5(j)  
    //         00447fcd     CALL       memcpy                                           undefined memcpy()
    //                              Dsutil.c:728 (19)
    //         00447fd2     MOV        ECX,dword ptr [ESP + 0x38]
    //         00447fd6     ADD        EDI,ESI
    //         00447fd8     ADD        ESP,0xc
    //         00447fdb     ADD        ECX,ESI
    //         00447fdd     CMP        EDI,EBX
    //         00447fdf     MOV        dword ptr [ESP + 0x2c],ECX
    //         00447fe3     JC         LAB_00447f89
    //                               LAB_00447fe5                                                 XREF[1]:     00447f7f(j)  
    //                              Dsutil.c:731 (22)
    //         00447fe5     MOV        ECX,dword ptr [ESP + 0x5c]
    //         00447fe9     LEA        EAX,[ESP + 0x10]
    //         00447fed     PUSH       0x0
    //         00447fef     PUSH       EAX=>DAT_fffffff8
    //         00447ff0     PUSH       ECX=>DAT_fffffff4
    //         00447ff1     CALL       dword ptr [->WINMM.DLL::mmioSetInfo]             = 0048b4a6
    //         00447ff7     TEST       EAX,EAX
    //         00447ff9     JZ         LAB_0044800d
    //                              Symbol Ref: No symbol: ERROR_CANNOT_READ
    //                               LAB_00447ffb                                                 XREF[2]:     00447f5f(j), 00447fa5(j)  
    //                              Dsutil.c:740 (10)
    //         00447ffb     MOV        EDX,dword ptr [ESP + 0x6c]
    //         00447fff     MOV        dword ptr [EDX],0x0
    //                              Dsutil.c:745 (8)
    //         00448005     POP        EDI
    //         00448006     POP        ESI
    //         00448007     POP        EBP
    //         00448008     POP        EBX
    //         00448009     ADD        ESP,0x48
    //         0044800c     RET
    //                               LAB_0044800d                                                 XREF[1]:     00447ff9(j)  
    //                              Dsutil.c:736 (6)
    //         0044800d     MOV        ECX,dword ptr [ESP + 0x6c]
    //         00448011     MOV        dword ptr [ECX],EBX
    //                              Dsutil.c:745 (8)
    //         00448013     POP        EDI
    //         00448014     POP        ESI
    //         00448015     POP        EBP
    //         00448016     POP        EBX
    //         00448017     ADD        ESP,0x48
    //         0044801a     RET
    //                               LAB_0044801b                                                 XREF[1]:     00447fb1(j)  
    //                              Dsutil.c:740 (4)
    //         0044801b     MOV        EDX,dword ptr [ESP + 0x6c]
    //                              Dsutil.c:745 (19)
    //         0044801f     POP        EDI
    //         00448020     POP        ESI
    //         00448021     POP        EBP
    //         00448022     MOV        EAX,0xe103
    //         00448027     MOV        dword ptr [EDX],0x0
    //         0044802d     POP        EBX
    //         0044802e     ADD        ESP,0x48
    //         00448031     RET
    //         00448032     ??         90h
    //         00448033     NOP
    //         00448034     NOP
    //         00448035     NOP
    //         00448036     NOP
    //         00448037     NOP
    //         00448038     NOP
    //         00448039     NOP
    //         0044803a     NOP
    //         0044803b     NOP
    //         0044803c     NOP
    //         0044803d     NOP
    //         0044803e     NOP
    //         0044803f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveCloseReadFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveCloseReadFile                                           XREF[3]:     ds_stream_file:00448761(c), 
    //                                                                                                         ds_stream_file:00448798(c), 
    //                                                                                                         ds_stream_stop:00448aec(c)  
    //                              Dsutil.c:758 (1)
    //         00448040     PUSH       ESI
    //                              Dsutil.c:760 (10)
    //         00448041     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         00448045     MOV        EAX,dword ptr [ESI]
    //         00448047     TEST       EAX,EAX
    //         00448049     JZ         LAB_00448058
    //                              Dsutil.c:762 (7)
    //         0044804b     PUSH       EAX
    //         0044804c     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:763 (6)
    //         00448052     MOV        dword ptr [ESI],0x0
    //                               LAB_00448058                                                 XREF[1]:     00448049(j)  
    //                              Dsutil.c:766 (10)
    //         00448058     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         0044805c     MOV        EAX,dword ptr [ESI]
    //         0044805e     TEST       EAX,EAX
    //         00448060     JZ         LAB_00448071
    //                              Dsutil.c:768 (9)
    //         00448062     PUSH       0x0
    //         00448064     PUSH       EAX
    //         00448065     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                              Dsutil.c:769 (6)
    //         0044806b     MOV        dword ptr [ESI],0x0
    //                               LAB_00448071                                                 XREF[1]:     00448060(j)  
    //                              Dsutil.c:772 (2)
    //         00448071     XOR        EAX,EAX
    //                              Dsutil.c:774 (2)
    //         00448073     POP        ESI
    //         00448074     RET
    //         00448075     ??         90h
    //         00448076     NOP
    //         00448077     NOP
    //         00448078     NOP
    //         00448079     NOP
    //         0044807a     NOP
    //         0044807b     NOP
    //         0044807c     NOP
    //         0044807d     NOP
    //         0044807e     NOP
    //         0044807f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveCreateFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ckOut1                    XREF[1]:     00448093(W)  
    //              ulong             Stack[-0x1c]:4 dwFactChunk
    //                               _WaveCreateFile                                              XREF[1]:     _WaveSaveFile:004485df(c)  
    //                              Dsutil.c:793 (3)
    //         00448080     SUB        ESP,0x18
    //                              Dsutil.c:803 (34)
    //         00448083     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00448087     PUSH       EBX
    //         00448088     PUSH       EBP
    //         00448089     PUSH       ESI
    //         0044808a     PUSH       EDI
    //         0044808b     PUSH       0x11002
    //         00448090     PUSH       0x0
    //         00448092     PUSH       EAX
    //         00448093     MOV        dword ptr [ESP + ckOut1.ckid],0xffffffff
    //         0044809b     CALL       dword ptr [->WINMM.DLL::mmioOpenA]               = 0048b48e
    //         004480a1     MOV        ESI,dword ptr [ESP + 0x30]
    //                              Dsutil.c:805 (4)
    //         004480a5     TEST       EAX,EAX
    //         004480a7     MOV        dword ptr [ESI],EAX
    //                              Dsutil.c:808 (6)
    //         004480a9     JZ         LAB_00448192
    //                              Dsutil.c:813 (4)
    //         004480af     MOV        EAX,dword ptr [ESP + 0x3c]
    //                              Dsutil.c:815 (36)
    //         004480b3     MOV        EBP,dword ptr [->WINMM.DLL::mmioCreateChunk]     = 0048b4dc
    //         004480b9     PUSH       0x20
    //         004480bb     PUSH       EAX=>DAT_fffffff8
    //         004480bc     MOV        dword ptr [EAX + 0x8],0x45564157
    //         004480c3     MOV        dword ptr [EAX + 0x4],0x0
    //         004480ca     MOV        ECX,dword ptr [ESI]
    //         004480cc     PUSH       ECX=>DAT_fffffff4
    //         004480cd     CALL       EBP=>WINMM.DLL::mmioCreateChunk
    //         004480cf     TEST       EAX,EAX
    //         004480d1     JNZ        LAB_00448197
    //                              Dsutil.c:825 (4)
    //         004480d7     MOV        EDI,dword ptr [ESP + 0x38]
    //                              Dsutil.c:827 (28)
    //         004480db     PUSH       EAX
    //         004480dc     PUSH       EDI=>DAT_fffffff8
    //         004480dd     MOV        dword ptr [EDI],0x20746d66
    //         004480e3     MOV        dword ptr [EDI + 0x4],0x10
    //         004480ea     MOV        EDX,dword ptr [ESI]
    //         004480ec     PUSH       EDX=>DAT_fffffff4
    //         004480ed     CALL       EBP=>WINMM.DLL::mmioCreateChunk
    //         004480ef     TEST       EAX,EAX
    //         004480f1     JNZ        LAB_00448197
    //                              Dsutil.c:833 (10)
    //         004480f7     MOV        EBX,dword ptr [ESP + 0x34]
    //         004480fb     CMP        word ptr [EBX],0x1
    //         004480ff     JNZ        LAB_0044811f
    //                              Dsutil.c:836 (17)
    //         00448101     MOV        EAX,dword ptr [ESI]
    //         00448103     PUSH       0x10
    //         00448105     PUSH       EBX=>DAT_fffffff8
    //         00448106     PUSH       EAX=>DAT_fffffff4
    //         00448107     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         0044810d     CMP        EAX,0x10
    //         00448110     JZ         LAB_00448140
    //                              Dsutil.c:880 (5)
    //         00448112     MOV        EAX,0xe104
    //                              Dsutil.c:895 (8)
    //         00448117     POP        EDI
    //         00448118     POP        ESI
    //         00448119     POP        EBP
    //         0044811a     POP        EBX
    //         0044811b     ADD        ESP,0x18
    //         0044811e     RET
    //                               LAB_0044811f                                                 XREF[1]:     004480ff(j)  
    //                              Dsutil.c:847 (31)
    //         0044811f     MOV        EDX,dword ptr [ESI]
    //         00448121     XOR        ECX,ECX
    //         00448123     MOV        CX,word ptr [EBX + 0x10]
    //         00448127     ADD        ECX,0x12
    //         0044812a     PUSH       ECX
    //         0044812b     PUSH       EBX=>DAT_fffffff8
    //         0044812c     PUSH       EDX=>DAT_fffffff4
    //         0044812d     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         00448133     XOR        ECX,ECX
    //         00448135     MOV        CX,word ptr [EBX + 0x10]
    //         00448139     ADD        ECX,0x12
    //         0044813c     CMP        EAX,ECX
    //                              Dsutil.c:850 (2)
    //         0044813e     JNZ        LAB_00448192
    //                               LAB_00448140                                                 XREF[1]:     00448110(j)  
    //                              Dsutil.c:857 (18)
    //         00448140     MOV        EDX,dword ptr [ESI]
    //         00448142     PUSH       0x0
    //         00448144     PUSH       EDI=>DAT_fffffff8
    //         00448145     MOV        EDI,dword ptr [->WINMM.DLL::mmioAscend]          = 0048b466
    //         0044814b     PUSH       EDX=>DAT_fffffff4
    //         0044814c     CALL       EDI=>WINMM.DLL::mmioAscend
    //         0044814e     TEST       EAX,EAX
    //         00448150     JNZ        LAB_00448197
    //                              Dsutil.c:866 (27)
    //         00448152     MOV        ECX,dword ptr [ESI]
    //         00448154     MOV        dword ptr [ESP + 0x18],EAX
    //         00448158     PUSH       EAX
    //         00448159     LEA        EAX,[ESP + 0x18]
    //         0044815d     PUSH       EAX=>DAT_fffffff8
    //         0044815e     PUSH       ECX=>DAT_fffffff4
    //         0044815f     MOV        dword ptr [ESP + 0x20],0x74636166
    //         00448167     CALL       EBP=>WINMM.DLL::mmioCreateChunk
    //         00448169     TEST       EAX,EAX
    //         0044816b     JNZ        LAB_00448197
    //                              Dsutil.c:871 (19)
    //         0044816d     MOV        EAX,dword ptr [ESI]
    //         0044816f     LEA        EDX,[ESP + 0x10]
    //         00448173     PUSH       0x4
    //         00448175     PUSH       EDX=>DAT_fffffff8
    //         00448176     PUSH       EAX=>DAT_fffffff4
    //         00448177     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         0044817d     CMP        EAX,0x4
    //                              Dsutil.c:874 (2)
    //         00448180     JNZ        LAB_00448192
    //                              Dsutil.c:878 (16)
    //         00448182     MOV        EDX,dword ptr [ESI]
    //         00448184     LEA        ECX,[ESP + 0x14]
    //         00448188     PUSH       0x0
    //         0044818a     PUSH       ECX=>DAT_fffffff8
    //         0044818b     PUSH       EDX=>DAT_fffffff4
    //         0044818c     CALL       EDI=>WINMM.DLL::mmioAscend
    //         0044818e     TEST       EAX,EAX
    //         00448190     JZ         LAB_00448197
    //                               LAB_00448192                                                 XREF[3]:     004480a9(j), 0044813e(j), 
    //                                                                                                         00448180(j)  
    //                              Dsutil.c:880 (5)
    //         00448192     MOV        EAX,0xe104
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                              Symbol Ref: No symbol: DONE_CREATE
    //                               LAB_00448197                                                 XREF[5]:     004480d1(j), 004480f1(j), 
    //                                                                                                         00448150(j), 0044816b(j), 
    //                                                                                                         00448190(j)  
    //                              Dsutil.c:895 (8)
    //         00448197     POP        EDI
    //         00448198     POP        ESI
    //         00448199     POP        EBP
    //         0044819a     POP        EBX
    //         0044819b     ADD        ESP,0x18
    //         0044819e     RET
    //         0044819f     ??         90h
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveStartDataWrite()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveStartDataWrite                                          XREF[1]:     _WaveSaveFile:004485fa(c)  
    //                              Dsutil.c:906 (5)
    //         004481a0     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         004481a4     PUSH       ESI
    //                              Dsutil.c:914 (33)
    //         004481a5     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         004481a9     PUSH       0x0
    //         004481ab     MOV        dword ptr [EAX],0x61746164
    //         004481b1     MOV        dword ptr [EAX + 0x4],0x0
    //         004481b8     PUSH       EAX
    //         004481b9     MOV        EAX,dword ptr [ESI]
    //         004481bb     PUSH       EAX
    //         004481bc     CALL       dword ptr [->WINMM.DLL::mmioCreateChunk]         = 0048b4dc
    //         004481c2     TEST       EAX,EAX
    //         004481c4     JNZ        LAB_004481d5
    //                              Dsutil.c:919 (15)
    //         004481c6     MOV        ECX,dword ptr [ESP + 0x10]
    //         004481ca     MOV        EDX,dword ptr [ESI]
    //         004481cc     PUSH       EAX
    //         004481cd     PUSH       ECX=>DAT_fffffff8
    //         004481ce     PUSH       EDX=>DAT_fffffff4
    //         004481cf     CALL       dword ptr [->WINMM.DLL::mmioGetInfo]             = 0048b4c2
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                               LAB_004481d5                                                 XREF[1]:     004481c4(j)  
    //                              Dsutil.c:929 (2)
    //         004481d5     POP        ESI
    //         004481d6     RET
    //         004481d7     ??         90h
    //         004481d8     NOP
    //         004481d9     NOP
    //         004481da     NOP
    //         004481db     NOP
    //         004481dc     NOP
    //         004481dd     NOP
    //         004481de     NOP
    //         004481df     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveWriteFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveWriteFile                                               XREF[1]:     _WaveSaveFile:0044862a(c)  
    //                              Dsutil.c:952 (22)
    //         004481e0     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         004481e4     PUSH       EBX
    //         004481e5     MOV        EBX,dword ptr [ESP + Stack[0x14]]
    //         004481e9     PUSH       EBP
    //         004481ea     PUSH       ESI
    //         004481eb     PUSH       EDI
    //         004481ec     XOR        EAX,EAX
    //         004481ee     XOR        EDI,EDI
    //         004481f0     TEST       ECX,ECX
    //         004481f2     MOV        dword ptr [EBX],EAX
    //         004481f4     JBE        LAB_00448241
    //                              Dsutil.c:964 (18)
    //         004481f6     MOV        ESI,dword ptr [ESP + Stack[0x18]]
    //         004481fa     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //                               LAB_004481fe                                                 XREF[1]:     0044823f(j)  
    //         004481fe     MOV        ECX,dword ptr [ESI + 0x1c]
    //         00448201     MOV        EDX,dword ptr [ESI + 0x24]
    //         00448204     CMP        ECX,EDX
    //         00448206     JNZ        LAB_00448220
    //                              Dsutil.c:966 (2)
    //         00448208     MOV        EDX,dword ptr [ESI]
    //                              Dsutil.c:967 (22)
    //         0044820a     PUSH       0x1
    //         0044820c     OR         EDX,0x10000000
    //         00448212     PUSH       ESI=>DAT_fffffff8
    //         00448213     PUSH       EBP=>DAT_fffffff4
    //         00448214     MOV        dword ptr [ESI],EDX
    //         00448216     CALL       dword ptr [->WINMM.DLL::mmioAdvance]             = 0048b4b4
    //         0044821c     TEST       EAX,EAX
    //         0044821e     JNZ        LAB_00448241
    //                               LAB_00448220                                                 XREF[1]:     00448206(j)  
    //                              Dsutil.c:972 (19)
    //         00448220     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00448224     MOV        EDX,dword ptr [ESI + 0x1c]
    //         00448227     MOV        CL,byte ptr [EDI + ECX*0x1]
    //         0044822a     MOV        byte ptr [EDX],CL
    //         0044822c     MOV        EDX,dword ptr [ESI + 0x1c]
    //         0044822f     INC        EDX
    //         00448230     MOV        dword ptr [ESI + 0x1c],EDX
    //                              Dsutil.c:973 (14)
    //         00448233     MOV        ECX,dword ptr [EBX]
    //         00448235     INC        ECX
    //         00448236     INC        EDI
    //         00448237     MOV        dword ptr [EBX],ECX
    //         00448239     MOV        ECX,dword ptr [ESP + 0x18]
    //         0044823d     CMP        EDI,ECX
    //         0044823f     JC         LAB_004481fe
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                               LAB_00448241                                                 XREF[2]:     004481f4(j), 0044821e(j)  
    //                              Dsutil.c:983 (5)
    //         00448241     POP        EDI
    //         00448242     POP        ESI
    //         00448243     POP        EBP
    //         00448244     POP        EBX
    //         00448245     RET
    //         00448246     ??         90h
    //         00448247     NOP
    //         00448248     NOP
    //         00448249     NOP
    //         0044824a     NOP
    //         0044824b     NOP
    //         0044824c     NOP
    //         0044824d     NOP
    //         0044824e     NOP
    //         0044824f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveCloseWriteFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveCloseWriteFile                                          XREF[1]:     _WaveSaveFile:00448652(c)  
    //                              Dsutil.c:1007 (3)
    //         00448250     PUSH       EBX
    //         00448251     PUSH       EBP
    //         00448252     PUSH       ESI
    //                              Dsutil.c:1013 (10)
    //         00448253     MOV        ESI,dword ptr [ESP + Stack[0x4]]
    //         00448257     PUSH       EDI
    //         00448258     CMP        dword ptr [ESI],0x0
    //         0044825b     JNZ        LAB_00448264
    //                              Dsutil.c:1014 (2)
    //         0044825d     XOR        EAX,EAX
    //                              Dsutil.c:1076 (5)
    //         0044825f     POP        EDI
    //         00448260     POP        ESI
    //         00448261     POP        EBP
    //         00448262     POP        EBX
    //         00448263     RET
    //                               LAB_00448264                                                 XREF[1]:     0044825b(j)  
    //                              Dsutil.c:1016 (4)
    //         00448264     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //                              Dsutil.c:1017 (32)
    //         00448268     PUSH       0x0
    //         0044826a     PUSH       EAX
    //         0044826b     MOV        EBX,dword ptr [EAX]
    //         0044826d     OR         EBX,0x10000000
    //         00448273     MOV        dword ptr [EAX],EBX
    //         00448275     MOV        EAX,dword ptr [ESI]
    //         00448277     PUSH       EAX
    //         00448278     CALL       dword ptr [->WINMM.DLL::mmioSetInfo]             = 0048b4a6
    //         0044827e     MOV        EDI,EAX
    //         00448280     TEST       EDI,EDI
    //         00448282     JNZ        LAB_0044830e
    //                              Dsutil.c:1026 (21)
    //         00448288     MOV        EBP,dword ptr [ESP + 0x18]
    //         0044828c     MOV        ECX,dword ptr [ESI]
    //         0044828e     PUSH       EAX
    //         0044828f     PUSH       EBP=>DAT_fffffff8
    //         00448290     PUSH       ECX=>DAT_fffffff4
    //         00448291     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         00448297     MOV        EDI,EAX
    //         00448299     TEST       EDI,EDI
    //         0044829b     JNZ        LAB_0044830e
    //                              Dsutil.c:1031 (21)
    //         0044829d     MOV        EBX,dword ptr [ESP + 0x1c]
    //         004482a1     MOV        EDX,dword ptr [ESI]
    //         004482a3     PUSH       EAX
    //         004482a4     PUSH       EBX=>DAT_fffffff8
    //         004482a5     PUSH       EDX=>DAT_fffffff4
    //         004482a6     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         004482ac     MOV        EDI,EAX
    //         004482ae     TEST       EDI,EDI
    //         004482b0     JNZ        LAB_0044830e
    //                              Dsutil.c:1035 (11)
    //         004482b2     PUSH       EAX
    //         004482b3     PUSH       EAX=>DAT_fffffff8
    //         004482b4     MOV        EAX,dword ptr [ESI]
    //         004482b6     PUSH       EAX=>DAT_fffffff4
    //         004482b7     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //                              Dsutil.c:1036 (18)
    //         004482bd     MOV        ECX,dword ptr [ESI]
    //         004482bf     PUSH       EDI
    //         004482c0     PUSH       EDI=>DAT_fffffff8
    //         004482c1     PUSH       EBX=>DAT_fffffff4
    //         004482c2     PUSH       ECX=>DAT_fffffff0
    //         004482c3     CALL       dword ptr [->WINMM.DLL::mmioDescend]             = 0048b480
    //         004482c9     MOV        EDI,EAX
    //         004482cb     TEST       EDI,EDI
    //         004482cd     JNZ        LAB_0044830e
    //                              Dsutil.c:1042 (7)
    //         004482cf     MOV        dword ptr [EBP],0x74636166
    //                              Dsutil.c:1043 (17)
    //         004482d6     MOV        EDX,dword ptr [ESI]
    //         004482d8     PUSH       0x10
    //         004482da     PUSH       EBX=>DAT_fffffff8
    //         004482db     PUSH       EBP=>DAT_fffffff4
    //         004482dc     PUSH       EDX=>DAT_fffffff0
    //         004482dd     CALL       dword ptr [->WINMM.DLL::mmioDescend]             = 0048b480
    //         004482e3     TEST       EAX,EAX
    //         004482e5     JNZ        LAB_0044832a
    //                              Dsutil.c:1047 (16)
    //         004482e7     MOV        ECX,dword ptr [ESI]
    //         004482e9     LEA        EAX,[ESP + 0x24]
    //         004482ed     PUSH       0x4
    //         004482ef     PUSH       EAX=>DAT_fffffff8
    //         004482f0     PUSH       ECX=>DAT_fffffff4
    //         004482f1     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //                              Dsutil.c:1048 (13)
    //         004482f7     MOV        EDX,dword ptr [ESI]
    //         004482f9     PUSH       EDI
    //         004482fa     MOV        EDI,dword ptr [->WINMM.DLL::mmioAscend]          = 0048b466
    //         00448300     PUSH       EBP=>DAT_fffffff8
    //         00448301     PUSH       EDX=>DAT_fffffff4
    //         00448302     CALL       EDI=>WINMM.DLL::mmioAscend
    //                              Dsutil.c:1062 (10)
    //         00448304     MOV        EAX,dword ptr [ESI]
    //         00448306     PUSH       0x0
    //         00448308     PUSH       EBX=>DAT_fffffff8
    //         00448309     PUSH       EAX=>DAT_fffffff4
    //         0044830a     CALL       EDI=>WINMM.DLL::mmioAscend
    //         0044830c     MOV        EDI,EAX
    //                              Symbol Ref: No symbol: ERROR_CANNOT_WRITE
    //                               LAB_0044830e                                                 XREF[4]:     00448282(j), 0044829b(j), 
    //                                                                                                         004482b0(j), 004482cd(j)  
    //                              Dsutil.c:1068 (6)
    //         0044830e     MOV        EAX,dword ptr [ESI]
    //         00448310     TEST       EAX,EAX
    //         00448312     JZ         LAB_00448323
    //                              Dsutil.c:1070 (9)
    //         00448314     PUSH       0x0
    //         00448316     PUSH       EAX=>DAT_fffffff8
    //         00448317     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                              Dsutil.c:1071 (6)
    //         0044831d     MOV        dword ptr [ESI],0x0
    //                               LAB_00448323                                                 XREF[1]:     00448312(j)  
    //                              Dsutil.c:1074 (2)
    //         00448323     MOV        EAX,EDI
    //                              Dsutil.c:1076 (15)
    //         00448325     POP        EDI
    //         00448326     POP        ESI
    //         00448327     POP        EBP
    //         00448328     POP        EBX
    //         00448329     RET
    //                               LAB_0044832a                                                 XREF[1]:     004482e5(j)  
    //         0044832a     POP        EDI
    //         0044832b     POP        ESI
    //         0044832c     POP        EBP
    //         0044832d     MOV        EAX,0x1
    //         00448332     POP        EBX
    //         00448333     RET
    //         00448334     ??         90h
    //         00448335     NOP
    //         00448336     NOP
    //         00448337     NOP
    //         00448338     NOP
    //         00448339     NOP
    //         0044833a     NOP
    //         0044833b     NOP
    //         0044833c     NOP
    //         0044833d     NOP
    //         0044833e     NOP
    //         0044833f     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveCopyUselessChunks()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _WaveCopyUselessChunks
    //                              Dsutil.c:1102 (1)
    //         00448340     PUSH       EBX
    //                              Dsutil.c:1108 (33)
    //         00448341     MOV        EBX,dword ptr [ESP + Stack[0xc]]
    //         00448345     PUSH       ESI
    //         00448346     PUSH       EDI
    //         00448347     MOV        EAX,dword ptr [EBX + 0xc]
    //         0044834a     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0044834e     ADD        EAX,0x4
    //         00448351     PUSH       0x0
    //         00448353     MOV        ECX,dword ptr [EDI]
    //         00448355     PUSH       EAX
    //         00448356     PUSH       ECX
    //         00448357     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //         0044835d     CMP        EAX,-0x1
    //         00448360     JNZ        LAB_00448369
    //                              Dsutil.c:1110 (5)
    //         00448362     MOV        ESI,0xe102
    //                              Dsutil.c:1111 (2)
    //         00448367     JMP        LAB_004483e5
    //                               LAB_00448369                                                 XREF[1]:     00448360(j)  
    //                              Dsutil.c:1116 (32)
    //         00448369     MOV        ESI,dword ptr [ESP + 0x14]
    //         0044836d     MOV        EDX,dword ptr [EDI]
    //         0044836f     PUSH       EBP
    //         00448370     MOV        EBP,dword ptr [->WINMM.DLL::mmioDescend]         = 0048b480
    //         00448376     PUSH       0x0=>DAT_fffffff8
    //         00448378     PUSH       EBX=>DAT_fffffff4
    //         00448379     PUSH       ESI=>DAT_fffffff0
    //         0044837a     PUSH       EDX
    //         0044837b     MOV        dword ptr [ESP + 0x2c],0x0
    //         00448383     CALL       EBP=>WINMM.DLL::mmioDescend
    //         00448385     TEST       EAX,EAX
    //         00448387     JNZ        LAB_004483e0
    //                               LAB_00448389                                                 XREF[1]:     004483de(j)  
    //                              Dsutil.c:1120 (20)
    //         00448389     MOV        EAX,dword ptr [EBX + 0x4]
    //         0044838c     MOV        ECX,dword ptr [EBX + 0xc]
    //         0044838f     MOV        EDX,dword ptr [ESI + 0x4]
    //         00448392     ADD        EAX,ECX
    //         00448394     MOV        ECX,dword ptr [ESI + 0xc]
    //         00448397     ADD        ECX,EDX
    //         00448399     CMP        ECX,EAX
    //         0044839b     JA         LAB_004483e0
    //                              Dsutil.c:1123 (23)
    //         0044839d     MOV        EAX,dword ptr [ESI]
    //         0044839f     CMP        EAX,0x20444150
    //         004483a4     JZ         LAB_004483c7
    //         004483a6     CMP        EAX,0x50534944
    //         004483ab     JZ         LAB_004483b4
    //         004483ad     CMP        EAX,0x74736c70
    //         004483b2     JNZ        LAB_004483c7
    //                               LAB_004483b4                                                 XREF[1]:     004483ab(j)  
    //                              Dsutil.c:1151 (19)
    //         004483b4     MOV        EDX,dword ptr [ESP + 0x20]
    //         004483b8     MOV        ECX,dword ptr [EDI]
    //         004483ba     PUSH       ESI
    //         004483bb     MOV        EAX,dword ptr [EDX]
    //         004483bd     PUSH       EAX=>DAT_fffffff8
    //         004483be     PUSH       ECX=>DAT_fffffff4
    //         004483bf     CALL       riffCopyChunk                                    undefined riffCopyChunk()
    //         004483c4     ADD        ESP,0xc
    //                               LAB_004483c7                                                 XREF[2]:     004483a4(j), 004483b2(j)  
    //                              Dsutil.c:1162 (25)
    //         004483c7     MOV        EDX,dword ptr [EDI]
    //         004483c9     PUSH       0x0
    //         004483cb     PUSH       ESI=>DAT_fffffff8
    //         004483cc     PUSH       EDX=>DAT_fffffff4
    //         004483cd     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         004483d3     MOV        EAX,dword ptr [EDI]
    //         004483d5     PUSH       0x0
    //         004483d7     PUSH       EBX=>DAT_fffffff8
    //         004483d8     PUSH       ESI=>DAT_fffffff4
    //         004483d9     PUSH       EAX=>DAT_fffffff0
    //         004483da     CALL       EBP=>WINMM.DLL::mmioDescend
    //         004483dc     TEST       EAX,EAX
    //         004483de     JZ         LAB_00448389
    //                               LAB_004483e0                                                 XREF[2]:     00448387(j), 0044839b(j)  
    //                              Dsutil.c:1116 (5)
    //         004483e0     MOV        ESI,dword ptr [ESP + 0x1c]
    //         004483e4     POP        EBP
    //                              Symbol Ref: No symbol: ERROR_IN_PROC
    //                               LAB_004483e5                                                 XREF[1]:     00448367(j)  
    //                              Dsutil.c:1169 (18)
    //         004483e5     MOV        ECX,dword ptr [EBX + 0xc]
    //         004483e8     MOV        EDX,dword ptr [EDI]
    //         004483ea     ADD        ECX,0x4
    //         004483ed     PUSH       0x0
    //         004483ef     PUSH       ECX=>DAT_fffffff8
    //         004483f0     PUSH       EDX=>DAT_fffffff4
    //         004483f1     CALL       dword ptr [->WINMM.DLL::mmioSeek]                = 0048b49a
    //                              Dsutil.c:1172 (2)
    //         004483f7     MOV        EAX,ESI
    //                              Dsutil.c:1173 (4)
    //         004483f9     POP        EDI
    //         004483fa     POP        ESI
    //         004483fb     POP        EBX
    //         004483fc     RET
    //         004483fd     ??         90h
    //         004483fe     NOP
    //         004483ff     NOP
    //                              * riffCopyChunk                                                                                         *
    //                              undefined __cdecl riffCopyChunk()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ck
    //                               _riffCopyChunk                                               XREF[1]:     _WaveCopyUselessChunks:004483bf(c)
    //                               riffCopyChunk
    //                              Dsutil.c:1191 (6)
    //         00448400     SUB        ESP,0x14
    //         00448403     PUSH       EBX
    //         00448404     PUSH       EBP
    //         00448405     PUSH       ESI
    //                              Dsutil.c:1198 (26)
    //         00448406     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0044840a     PUSH       EDI
    //         0044840b     MOV        EAX,dword ptr [ESI + 0x4]
    //         0044840e     PUSH       EAX
    //         0044840f     PUSH       0x42
    //         00448411     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         00448417     PUSH       EAX
    //         00448418     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
    //         0044841e     MOV        EDI,EAX
    //                              Dsutil.c:1199 (4)
    //         00448420     TEST       EDI,EDI
    //         00448422     JNZ        LAB_0044842c
    //                              Dsutil.c:1227 (8)
    //         00448424     POP        EDI
    //         00448425     POP        ESI
    //         00448426     POP        EBP
    //         00448427     POP        EBX
    //         00448428     ADD        ESP,0x14
    //         0044842b     RET
    //                               LAB_0044842c                                                 XREF[1]:     00448422(j)  
    //                              Dsutil.c:1204 (35)
    //         0044842c     MOV        EBP,dword ptr [ESP + 0x2c]
    //         00448430     MOV        ECX,dword ptr [ESI]
    //         00448432     MOV        EDX,dword ptr [ESI + 0x4]
    //         00448435     LEA        EAX,[ESP + 0x10]
    //         00448439     PUSH       0x0
    //         0044843b     PUSH       EAX=>DAT_fffffff8
    //         0044843c     PUSH       EBP=>DAT_fffffff4
    //         0044843d     MOV        dword ptr [ESP + 0x1c],ECX
    //         00448441     MOV        dword ptr [ESP + 0x20],EDX
    //         00448445     CALL       dword ptr [->WINMM.DLL::mmioCreateChunk]         = 0048b4dc
    //         0044844b     TEST       EAX,EAX
    //         0044844d     JNZ        LAB_00448485
    //                              Dsutil.c:1207 (22)
    //         0044844f     MOV        EBX,dword ptr [ESI + 0x4]
    //         00448452     MOV        EDX,dword ptr [ESP + 0x28]
    //         00448456     MOV        ECX,EBX
    //         00448458     PUSH       ECX
    //         00448459     PUSH       EDI=>DAT_fffffff8
    //         0044845a     PUSH       EDX=>DAT_fffffff4
    //         0044845b     CALL       dword ptr [->WINMM.DLL::mmioRead]                = 0048b474
    //         00448461     CMP        EAX,EBX
    //         00448463     JNZ        LAB_00448485
    //                              Dsutil.c:1210 (14)
    //         00448465     PUSH       EBX
    //         00448466     PUSH       EDI=>DAT_fffffff8
    //         00448467     PUSH       EBP=>DAT_fffffff4
    //         00448468     CALL       dword ptr [->WINMM.DLL::mmioWrite]               = 0048b4d0
    //         0044846e     CMP        EAX,dword ptr [ESI + 0x4]
    //         00448471     JNZ        LAB_00448485
    //                              Dsutil.c:1213 (18)
    //         00448473     LEA        EAX,[ESP + 0x10]
    //         00448477     PUSH       0x0
    //         00448479     PUSH       EAX=>DAT_fffffff8
    //         0044847a     PUSH       EBP=>DAT_fffffff4
    //         0044847b     CALL       dword ptr [->WINMM.DLL::mmioAscend]              = 0048b466
    //         00448481     TEST       EAX,EAX
    //         00448483     JZ         LAB_004484a9
    //                              Symbol Ref: No symbol: rscc_Error
    //                               LAB_00448485                                                 XREF[3]:     0044844d(j), 00448463(j), 
    //                                                                                                         00448471(j)  
    //                              Dsutil.c:1224 (26)
    //         00448485     MOV        ESI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         0044848b     PUSH       EDI
    //         0044848c     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         0044848e     PUSH       EAX
    //         0044848f     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         00448495     PUSH       EDI
    //         00448496     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         00448498     PUSH       EAX
    //         00448499     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:1226 (2)
    //         0044849f     XOR        EAX,EAX
    //                              Dsutil.c:1227 (8)
    //         004484a1     POP        EDI
    //         004484a2     POP        ESI
    //         004484a3     POP        EBP
    //         004484a4     POP        EBX
    //         004484a5     ADD        ESP,0x14
    //         004484a8     RET
    //                               LAB_004484a9                                                 XREF[1]:     00448483(j)  
    //                              Dsutil.c:1217 (26)
    //         004484a9     MOV        ESI,dword ptr [->KERNEL32.DLL::GlobalHandle]     = 0048ab0c
    //         004484af     PUSH       EDI
    //         004484b0     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         004484b2     PUSH       EAX
    //         004484b3     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
    //         004484b9     PUSH       EDI
    //         004484ba     CALL       ESI=>KERNEL32.DLL::GlobalHandle
    //         004484bc     PUSH       EAX
    //         004484bd     CALL       dword ptr [->KERNEL32.DLL::GlobalFree]           = 0048aad0
    //                              Dsutil.c:1227 (13)
    //         004484c3     POP        EDI
    //         004484c4     POP        ESI
    //         004484c5     POP        EBP
    //         004484c6     MOV        EAX,0x1
    //         004484cb     POP        EBX
    //         004484cc     ADD        ESP,0x14
    //         004484cf     RET
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveLoadFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMCKINFO         Stack[-0x18]   ckInRiff                  XREF[0,2]:   004484d7(*), 00448514(*)  
    //              _MMCKINFO         Stack[-0x2c]   ckIn                      XREF[0,2]:   00448518(*), 00448531(R)  
    //                               _WaveLoadFile
    //                              Dsutil.c:1251 (3)
    //         004484d0     SUB        ESP,0x28
    //                              Dsutil.c:1263 (65)
    //         004484d3     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         004484d7     LEA        EAX=>ckInRiff.cksize,[ESP + 0x14]
    //         004484db     LEA        ECX=>Stack[0x14],[ESP + 0x3c]
    //         004484df     PUSH       EBX
    //         004484e0     MOV        EBX,dword ptr [ESP + Stack[0x10]]
    //         004484e4     PUSH       EBP
    //         004484e5     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         004484e9     PUSH       ESI
    //         004484ea     MOV        ESI,dword ptr [ESP + Stack[0x14]]
    //         004484ee     PUSH       EDI
    //         004484ef     PUSH       EAX
    //         004484f0     PUSH       EBX
    //         004484f1     MOV        dword ptr [ESI],0x0
    //         004484f7     PUSH       ECX
    //         004484f8     MOV        dword ptr [EBX],0x0
    //         004484fe     PUSH       EDX
    //         004484ff     MOV        dword ptr [EBP],0x0
    //         00448506     CALL       _WaveOpenFile                                    undefined _WaveOpenFile()
    //         0044850b     MOV        EDI,EAX
    //         0044850d     ADD        ESP,0x10
    //         00448510     TEST       EDI,EDI
    //         00448512     JNZ        LAB_0044856d
    //                              Dsutil.c:1268 (29)
    //         00448514     LEA        EAX=>ckInRiff.cksize,[ESP + 0x24]
    //         00448518     LEA        ECX=>ckIn.cksize,[ESP + 0x10]
    //         0044851c     PUSH       EAX
    //         0044851d     LEA        EDX=>Stack[0x14],[ESP + 0x50]
    //         00448521     PUSH       ECX
    //         00448522     PUSH       EDX
    //         00448523     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //         00448528     MOV        EDI,EAX
    //         0044852a     ADD        ESP,0xc
    //         0044852d     TEST       EDI,EDI
    //         0044852f     JNZ        LAB_0044856d
    //                              Dsutil.c:1274 (18)
    //         00448531     MOV        EAX,dword ptr [ESP + ckIn.fccType]
    //         00448535     PUSH       EAX
    //         00448536     PUSH       EDI
    //         00448537     CALL       dword ptr [->KERNEL32.DLL::GlobalAlloc]          = 0048ab8e
    //         0044853d     TEST       EAX,EAX
    //         0044853f     MOV        dword ptr [ESI],EAX
    //         00448541     JNZ        LAB_0044854a
    //                              Dsutil.c:1276 (5)
    //         00448543     MOV        EDI,0xe000
    //                              Dsutil.c:1277 (2)
    //         00448548     JMP        LAB_0044856d
    //                               LAB_0044854a                                                 XREF[1]:     00448541(j)  
    //                              Dsutil.c:1280 (35)
    //         0044854a     LEA        ECX,[ESP + 0x48]
    //         0044854e     LEA        EDX,[ESP + 0x10]
    //         00448552     PUSH       ECX
    //         00448553     MOV        ECX,dword ptr [ESP + 0x50]
    //         00448557     PUSH       EDX
    //         00448558     PUSH       EAX
    //         00448559     MOV        EAX,dword ptr [ESP + 0x20]
    //         0044855d     PUSH       EAX
    //         0044855e     PUSH       ECX
    //         0044855f     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //         00448564     MOV        EDI,EAX
    //         00448566     ADD        ESP,0x14
    //         00448569     TEST       EDI,EDI
    //         0044856b     JZ         LAB_00448593
    //                              Symbol Ref: No symbol: ERROR_LOADING
    //                               LAB_0044856d                                                 XREF[3]:     00448512(j), 0044852f(j), 
    //                                                                                                         00448548(j)  
    //                              Dsutil.c:1289 (12)
    //         0044856d     MOV        EAX,dword ptr [ESI]
    //         0044856f     MOV        EBP,dword ptr [->KERNEL32.DLL::GlobalFree]       = 0048aad0
    //         00448575     TEST       EAX,EAX
    //         00448577     JZ         LAB_00448582
    //                              Dsutil.c:1291 (3)
    //         00448579     PUSH       EAX
    //         0044857a     CALL       EBP=>KERNEL32.DLL::GlobalFree
    //                              Dsutil.c:1292 (6)
    //         0044857c     MOV        dword ptr [ESI],0x0
    //                               LAB_00448582                                                 XREF[1]:     00448577(j)  
    //                              Dsutil.c:1294 (6)
    //         00448582     MOV        EAX,dword ptr [EBX]
    //         00448584     TEST       EAX,EAX
    //         00448586     JZ         LAB_0044859a
    //                              Dsutil.c:1296 (3)
    //         00448588     PUSH       EAX
    //         00448589     CALL       EBP=>KERNEL32.DLL::GlobalFree
    //                              Dsutil.c:1297 (8)
    //         0044858b     MOV        dword ptr [EBX],0x0
    //         00448591     JMP        LAB_0044859a
    //                               LAB_00448593                                                 XREF[1]:     0044856b(j)  
    //                              Dsutil.c:1285 (7)
    //         00448593     MOV        EDX,dword ptr [ESP + 0x48]
    //         00448597     MOV        dword ptr [EBP],EDX
    //                              Symbol Ref: No symbol: DONE_LOADING
    //                               LAB_0044859a                                                 XREF[2]:     00448586(j), 00448591(j)  
    //                              Dsutil.c:1302 (8)
    //         0044859a     MOV        EAX,dword ptr [ESP + 0x4c]
    //         0044859e     TEST       EAX,EAX
    //         004485a0     JZ         LAB_004485ab
    //                              Dsutil.c:1304 (9)
    //         004485a2     PUSH       0x0
    //         004485a4     PUSH       EAX
    //         004485a5     CALL       dword ptr [->WINMM.DLL::mmioClose]               = 0048b45a
    //                               LAB_004485ab                                                 XREF[1]:     004485a0(j)  
    //                              Dsutil.c:1308 (2)
    //         004485ab     MOV        EAX,EDI
    //                              Dsutil.c:1310 (8)
    //         004485ad     POP        EDI
    //         004485ae     POP        ESI
    //         004485af     POP        EBP
    //         004485b0     POP        EBX
    //         004485b1     ADD        ESP,0x28
    //         004485b4     RET
    //         004485b5     ??         90h
    //         004485b6     NOP
    //         004485b7     NOP
    //         004485b8     NOP
    //         004485b9     NOP
    //         004485ba     NOP
    //         004485bb     NOP
    //         004485bc     NOP
    //         004485bd     NOP
    //         004485be     NOP
    //         004485bf     NOP
    //                              *                                               FUNCTION                                                *
    //                              undefined _WaveSaveFile()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              _MMIOINFO         Stack[-0x4c]   mmioinfoOut               XREF[0,3]:   004485eb(*), 00448606(*), 0044863d(*)  
    //              _MMCKINFO         Stack[-0x60]   ckOutRIFF                 XREF[0,2]:   004485c7(*), 00448642(*)  
    //              _MMCKINFO         Stack[-0x74]   ckOut                     XREF[1,4]:   0044860a(*), 004485cb(*), 004485ef(*), 00448616(*), 
    //                                                                                     00448647(*)  
    //              uint              Stack[-0x78]:4 cbActualWrite             XREF[4]:     004485d8(*), 004485f4(*), 00448623(R), 0044864c(*)  
    //              void *            Stack[-0x7c]:4 hmmioOut
    //                               _WaveSaveFile
    //                              Dsutil.c:1327 (43)
    //         004485c0     MOV        EDX,dword ptr [ESP + Stack[0x10]]
    //         004485c4     SUB        ESP,0x78
    //         004485c7     LEA        EAX=>ckOutRIFF.cksize,[ESP + 0x1c]
    //         004485cb     LEA        ECX=>ckOut.cksize,[ESP + 0x8]
    //         004485cf     PUSH       EAX
    //         004485d0     PUSH       ECX
    //         004485d1     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         004485d8     LEA        EAX=>cbActualWrite,[ESP + 0x8]
    //         004485dc     PUSH       EDX
    //         004485dd     PUSH       EAX
    //         004485de     PUSH       ECX
    //         004485df     CALL       _WaveCreateFile                                  undefined _WaveCreateFile()
    //         004485e4     ADD        ESP,0x14
    //         004485e7     TEST       EAX,EAX
    //         004485e9     JNZ        LAB_0044865a
    //                              Dsutil.c:1341 (27)
    //         004485eb     LEA        EDX=>mmioinfoOut.fccIOProc,[ESP + 0x30]
    //         004485ef     LEA        EAX=>ckOut.cksize,[ESP + 0x8]
    //         004485f3     PUSH       EDX
    //         004485f4     LEA        ECX=>cbActualWrite,[ESP + 0x4]
    //         004485f8     PUSH       EAX
    //         004485f9     PUSH       ECX
    //         004485fa     CALL       _WaveStartDataWrite                              undefined _WaveStartDataWrite()
    //         004485ff     ADD        ESP,0xc
    //         00448602     TEST       EAX,EAX
    //         00448604     JNZ        LAB_0044865a
    //                              Dsutil.c:1346 (48)
    //         00448606     LEA        EDX=>mmioinfoOut.fccIOProc,[ESP + 0x30]
    //         0044860a     LEA        EAX=>ckOut,[ESP + 0x4]
    //         0044860e     PUSH       EDX
    //         0044860f     MOV        EDX,dword ptr [ESP + Stack[0x14]]
    //         00448616     LEA        ECX=>ckOut.cksize,[ESP + 0xc]
    //         0044861a     PUSH       EAX
    //         0044861b     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00448622     PUSH       ECX
    //         00448623     MOV        ECX,dword ptr [ESP + cbActualWrite]
    //         00448627     PUSH       EDX
    //         00448628     PUSH       EAX
    //         00448629     PUSH       ECX
    //         0044862a     CALL       _WaveWriteFile                                   undefined _WaveWriteFile()
    //         0044862f     ADD        ESP,0x18
    //         00448632     TEST       EAX,EAX
    //         00448634     JNZ        LAB_0044865a
    //                              Dsutil.c:1351 (36)
    //         00448636     MOV        EDX,dword ptr [ESP + Stack[0xc]]
    //         0044863d     LEA        EAX=>mmioinfoOut.fccIOProc,[ESP + 0x30]
    //         00448641     PUSH       EDX
    //         00448642     LEA        ECX=>ckOutRIFF.cksize,[ESP + 0x20]
    //         00448646     PUSH       EAX
    //         00448647     LEA        EDX=>ckOut.cksize,[ESP + 0x10]
    //         0044864b     PUSH       ECX
    //         0044864c     LEA        EAX=>cbActualWrite,[ESP + 0xc]
    //         00448650     PUSH       EDX
    //         00448651     PUSH       EAX
    //         00448652     CALL       _WaveCloseWriteFile                              undefined _WaveCloseWriteFile()
    //         00448657     ADD        ESP,0x14
    //                              Symbol Ref: No symbol: ERROR_SAVING
    //                               LAB_0044865a                                                 XREF[3]:     004485e9(j), 00448604(j), 
    //                                                                                                         00448634(j)  
    //                              Dsutil.c:1360 (4)
    //         0044865a     ADD        ESP,0x78
    //         0044865d     RET
    //         0044865e     ??         90h
    //         0044865f     NOP
    //                              * ds_stream_init                                                                                        *
    //                              undefined __cdecl ds_stream_init()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_init                                              XREF[1]:     init:004bc78a(c)  
    //                               ds_stream_init
    //                              Dsutil.c:1392 (4)
    //         00448660     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //                              Dsutil.c:1403 (50)
    //         00448664     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         00448668     XOR        EAX,EAX
    //         0044866a     MOV        dword ptr [_uLastPercent],0x64
    //         00448674     MOV        [_lpDSBStreamBuffer],EAX
    //         00448679     MOV        [_bFileOpen],EAX
    //         0044867e     MOV        [_bPlaying],EAX
    //         00448683     MOV        [_bTimerInstalled],EAX
    //         00448688     MOV        [_uTimerID],EAX
    //         0044868d     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         00448691     MOV        [_main_wnd],EAX
    //                              Dsutil.c:1405 (22)
    //         00448696     MOV        EAX,0x1
    //         0044869b     MOV        dword ptr [_lpBuffer],ECX                        = align(8)
    //         004486a1     MOV        dword ptr [_lpDS],EDX
    //         004486a7     MOV        [_ds_ready],EAX
    //                              Dsutil.c:1408 (1)
    //         004486ac     RET
    //         004486ad     ??         90h
    //         004486ae     NOP
    //         004486af     NOP
    //                              * ds_stream_exit                                                                                        *
    //                              undefined __cdecl ds_stream_exit()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_exit                                              XREF[1]:     exit:004bc7cd(c)  
    //                               ds_stream_exit
    //                              Dsutil.c:1415 (9)
    //         004486b0     MOV        EAX,[_ds_ready]
    //         004486b5     TEST       EAX,EAX
    //         004486b7     JZ         LAB_004486e3
    //                              Dsutil.c:1418 (27)
    //         004486b9     MOV        EAX,[_bFileOpen]
    //         004486be     TEST       EAX,EAX
    //         004486c0     JNZ        LAB_004486d4
    //         004486c2     MOV        EAX,[_bPlaying]
    //         004486c7     TEST       EAX,EAX
    //         004486c9     JNZ        LAB_004486d4
    //         004486cb     MOV        EAX,[_bTimerInstalled]
    //         004486d0     TEST       EAX,EAX
    //         004486d2     JZ         LAB_004486d9
    //                               LAB_004486d4                                                 XREF[2]:     004486c0(j), 004486c9(j)  
    //                              Dsutil.c:1419 (5)
    //         004486d4     CALL       ds_stream_stop                                   undefined ds_stream_stop()
    //                               LAB_004486d9                                                 XREF[1]:     004486d2(j)  
    //                              Dsutil.c:1421 (10)
    //         004486d9     MOV        dword ptr [_ds_ready],0x0
    //                               LAB_004486e3                                                 XREF[1]:     004486b7(j)  
    //                              Dsutil.c:1423 (1)
    //         004486e3     RET
    //         004486e4     ??         90h
    //         004486e5     NOP
    //         004486e6     NOP
    //         004486e7     NOP
    //         004486e8     NOP
    //         004486e9     NOP
    //         004486ea     NOP
    //         004486eb     NOP
    //         004486ec     NOP
    //         004486ed     NOP
    //         004486ee     NOP
    //         004486ef     NOP
    //                              * ds_stream_file                                                                                        *
    //                              undefined __cdecl ds_stream_file()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00448802(W)  
    //              _DSBUFFERDESC     Stack[-0x18]   dsbd                      XREF[0,5]:   004487d9(*), 00448806(*), 0044880b(W), 00448813(W), 
    //                                                                                     0044881b(W)  
    //              ulong             Stack[-0x1c]:4 dwLen2
    //              uchar *           Stack[-0x20]:4 lpWrite2
    //              uint              Stack[-0x24]:4 uChkErr
    //              uchar *           Stack[-0x28]:4 lpWrite1
    //              ulong             Stack[-0x2c]:4 dwLen1
    //                               _ds_stream_file                                              XREF[1]:     stream_file:004bc91a(c)  
    //                               ds_stream_file
    //                              Dsutil.c:1429 (34)
    //         004486f0     MOV        EAX,[_bFileOpen]
    //         004486f5     SUB        ESP,0x28
    //         004486f8     PUSH       EBX
    //         004486f9     XOR        EBX,EBX
    //         004486fb     PUSH       EBP
    //         004486fc     PUSH       ESI
    //         004486fd     CMP        EAX,EBX
    //         004486ff     PUSH       EDI
    //         00448700     JNZ        LAB_00448712
    //         00448702     CMP        dword ptr [_bPlaying],EBX
    //         00448708     JNZ        LAB_00448712
    //         0044870a     CMP        dword ptr [_bTimerInstalled],EBX
    //         00448710     JZ         LAB_00448717
    //                               LAB_00448712                                                 XREF[2]:     00448700(j), 00448708(j)  
    //                              Dsutil.c:1439 (5)
    //         00448712     CALL       ds_stream_stop                                   undefined ds_stream_stop()
    //                               LAB_00448717                                                 XREF[1]:     00448710(j)  
    //                              Dsutil.c:1447 (38)
    //         00448717     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0044871b     PUSH       null_0088847c                                    = align(4)
    //         00448720     PUSH       _wiWave
    //         00448725     PUSH       DAT_00888464
    //         0044872a     PUSH       EAX
    //         0044872b     MOV        dword ptr [_stream_paused],EBX
    //         00448731     CALL       _WaveOpenFile                                    undefined _WaveOpenFile()
    //         00448736     ADD        ESP,0x10
    //         00448739     CMP        EAX,EBX
    //         0044873b     JZ         LAB_00448747
    //                              Dsutil.c:1451 (2)
    //         0044873d     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         0044873f     POP        EDI
    //         00448740     POP        ESI
    //         00448741     POP        EBP
    //         00448742     POP        EBX
    //         00448743     ADD        ESP,0x28
    //         00448746     RET
    //                               LAB_00448747                                                 XREF[1]:     0044873b(j)  
    //                              Dsutil.c:1454 (16)
    //         00448747     MOV        ECX,dword ptr [_wiWave]
    //         0044874d     MOV        EBP,0x1
    //         00448752     CMP        word ptr [ECX],BP
    //         00448755     JZ         LAB_00448773
    //                              Dsutil.c:1457 (18)
    //         00448757     PUSH       _wiWave
    //         0044875c     PUSH       DAT_00888464
    //         00448761     CALL       _WaveCloseReadFile                               undefined _WaveCloseReadFile()
    //         00448766     ADD        ESP,0x8
    //                              Dsutil.c:1459 (2)
    //         00448769     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         0044876b     POP        EDI
    //         0044876c     POP        ESI
    //         0044876d     POP        EBP
    //         0044876e     POP        EBX
    //         0044876f     ADD        ESP,0x28
    //         00448772     RET
    //                               LAB_00448773                                                 XREF[1]:     00448755(j)  
    //                              Dsutil.c:1463 (27)
    //         00448773     PUSH       null_0088847c                                    = align(4)
    //         00448778     PUSH       DAT_00888468                                     = align(24)
    //         0044877d     PUSH       DAT_00888464
    //         00448782     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //         00448787     ADD        ESP,0xc
    //         0044878a     CMP        EAX,EBX
    //         0044878c     JZ         LAB_004487aa
    //                              Dsutil.c:1466 (18)
    //         0044878e     PUSH       _wiWave
    //         00448793     PUSH       DAT_00888464
    //         00448798     CALL       _WaveCloseReadFile                               undefined _WaveCloseReadFile()
    //         0044879d     ADD        ESP,0x8
    //                              Dsutil.c:1468 (2)
    //         004487a0     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         004487a2     POP        EDI
    //         004487a3     POP        ESI
    //         004487a4     POP        EBP
    //         004487a5     POP        EBX
    //         004487a6     ADD        ESP,0x28
    //         004487a9     RET
    //                               LAB_004487aa                                                 XREF[1]:     0044878c(j)  
    //                              Dsutil.c:1479 (6)
    //         004487aa     MOV        EDX,dword ptr [_wiWave]
    //                              Dsutil.c:1490 (62)
    //         004487b0     PUSH       0x14
    //         004487b2     PUSH       EBX
    //         004487b3     MOV        EAX,dword ptr [EDX + 0x8]
    //         004487b6     LEA        EAX,[EAX + EAX*0x2]
    //         004487b9     LEA        ECX,[EAX + EAX*0x4]
    //         004487bc     MOV        EAX,0x51eb851f
    //         004487c1     SHL        ECX,0x3
    //         004487c4     MUL        ECX
    //         004487c6     SHR        EDX,0x5
    //         004487c9     MOV        EAX,0xaaaaaaab
    //         004487ce     MUL        EDX
    //         004487d0     SHR        EDX,0x2
    //         004487d3     MOV        dword ptr [DAT_00888498],EDX
    //         004487d9     LEA        EAX=>dsbd.dwFlags,[ESP + 0x2c]
    //         004487dd     LEA        EDX,[EDX + EDX*0x2]
    //         004487e0     PUSH       EAX
    //         004487e1     SHL        EDX,0x1
    //         004487e3     MOV        dword ptr [DAT_00888494],EDX
    //         004487e9     CALL       memset                                           undefined memset()
    //                              Dsutil.c:1496 (12)
    //         004487ee     MOV        EDX,dword ptr [_wiWave]
    //         004487f4     MOV        ECX,dword ptr [DAT_00888494]
    //                              Dsutil.c:1497 (49)
    //         004487fa     MOV        EAX,[_lpDS]
    //         004487ff     ADD        ESP,0xc
    //         00448802     MOV        dword ptr [ESP + local_4],EDX
    //         00448806     LEA        EDX=>dsbd.dwFlags,[ESP + 0x24]
    //         0044880a     PUSH       EBX
    //         0044880b     MOV        dword ptr [ESP + dsbd.dwFlags],0x14
    //         00448813     MOV        dword ptr [ESP + dsbd.dwBufferBytes],0xe0
    //         0044881b     MOV        dword ptr [ESP + dsbd.dwReserved],ECX
    //         0044881f     MOV        ECX,dword ptr [EAX]
    //         00448821     PUSH       _lpDSBStreamBuffer
    //         00448826     PUSH       EDX
    //         00448827     PUSH       EAX
    //         00448828     CALL       dword ptr [ECX + 0xc]
    //                              Dsutil.c:1498 (4)
    //         0044882b     CMP        EAX,EBX
    //         0044882d     JZ         LAB_00448839
    //                              Dsutil.c:1502 (2)
    //         0044882f     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         00448831     POP        EDI
    //         00448832     POP        ESI
    //         00448833     POP        EBP
    //         00448834     POP        EBX
    //         00448835     ADD        ESP,0x28
    //         00448838     RET
    //                               LAB_00448839                                                 XREF[1]:     0044882d(j)  
    //                              Dsutil.c:1512 (57)
    //         00448839     LEA        EDX,[ESP + 0x20]
    //         0044883d     PUSH       EBX
    //         0044883e     PUSH       EDX=>DAT_fffffff8
    //         0044883f     LEA        EDX,[ESP + 0x24]
    //         00448843     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448848     PUSH       EDX=>DAT_fffffff4
    //         00448849     LEA        EDX,[ESP + 0x1c]
    //         0044884d     MOV        [DAT_00888490],EAX
    //         00448852     PUSH       EDX=>DAT_fffffff0
    //         00448853     LEA        EDX,[ESP + 0x24]
    //         00448857     PUSH       EDX
    //         00448858     MOV        EDX,dword ptr [DAT_00888494]
    //         0044885e     MOV        dword ptr [DAT_008884b0],EBX
    //         00448864     MOV        dword ptr [DAT_008884b4],EBX
    //         0044886a     MOV        ECX,dword ptr [EAX]
    //         0044886c     PUSH       EDX
    //         0044886d     PUSH       EBX
    //         0044886e     PUSH       EAX
    //         0044886f     CALL       dword ptr [ECX + 0x2c]
    //                              Dsutil.c:1513 (4)
    //         00448872     CMP        EAX,EBX
    //         00448874     JZ         LAB_00448880
    //                              Dsutil.c:1516 (2)
    //         00448876     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         00448878     POP        EDI
    //         00448879     POP        ESI
    //         0044887a     POP        EBP
    //         0044887b     POP        EBX
    //         0044887c     ADD        ESP,0x28
    //         0044887f     RET
    //                               LAB_00448880                                                 XREF[1]:     00448874(j)  
    //                              Dsutil.c:1519 (12)
    //         00448880     MOV        ESI,dword ptr [ESP + 0x10]
    //         00448884     CMP        ESI,EBX
    //         00448886     JZ         LAB_00448955
    //                              Dsutil.c:1522 (28)
    //         0044888c     MOV        ECX,dword ptr [ESP + 0x14]
    //         00448890     MOV        EDX,dword ptr [DAT_00888464]
    //         00448896     LEA        EAX,[ESP + 0x18]
    //         0044889a     PUSH       EAX
    //         0044889b     PUSH       DAT_00888468                                     = align(24)
    //         004488a0     PUSH       ECX=>DAT_fffffff4
    //         004488a1     PUSH       ESI=>DAT_fffffff0
    //         004488a2     PUSH       EDX
    //         004488a3     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1523 (19)
    //         004488a8     MOV        ECX,dword ptr [ESP + 0x2c]
    //         004488ac     MOV        ESI,dword ptr [ESP + 0x24]
    //         004488b0     ADD        ESP,0x14
    //         004488b3     CMP        ECX,ESI
    //         004488b5     JNC        LAB_00448955
    //                              Dsutil.c:1525 (8)
    //         004488bb     CMP        dword ptr [DAT_008884ac],EBX
    //         004488c1     JZ         LAB_00448913
    //                              Dsutil.c:1531 (4)
    //         004488c3     MOV        EDI,dword ptr [ESP + 0x14]
    //                               LAB_004488c7                                                 XREF[1]:     0044890f(j)  
    //                              Dsutil.c:1544 (28)
    //         004488c7     PUSH       null_0088847c                                    = align(4)
    //         004488cc     SUB        ESI,ECX
    //         004488ce     PUSH       DAT_00888468                                     = align(24)
    //         004488d3     PUSH       DAT_00888464
    //         004488d8     ADD        EDI,ECX
    //         004488da     MOV        dword ptr [ESP + 0x1c],ESI
    //         004488de     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //                              Dsutil.c:1547 (31)
    //         004488e3     MOV        ECX,dword ptr [ESP + 0x1c]
    //         004488e7     MOV        EDX,dword ptr [DAT_00888464]
    //         004488ed     ADD        ESP,0xc
    //         004488f0     LEA        EAX,[ESP + 0x18]
    //         004488f4     PUSH       EAX
    //         004488f5     PUSH       DAT_00888468                                     = align(24)
    //         004488fa     PUSH       EDI=>DAT_fffffff4
    //         004488fb     PUSH       ECX=>DAT_fffffff0
    //         004488fc     PUSH       EDX
    //         004488fd     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1548 (15)
    //         00448902     MOV        ECX,dword ptr [ESP + 0x2c]
    //         00448906     MOV        ESI,dword ptr [ESP + 0x24]
    //         0044890a     ADD        ESP,0x14
    //         0044890d     CMP        ECX,ESI
    //         0044890f     JC         LAB_004488c7
    //                              Dsutil.c:1550 (2)
    //         00448911     JMP        LAB_00448955
    //                               LAB_00448913                                                 XREF[1]:     004488c1(j)  
    //                              Dsutil.c:1554 (10)
    //         00448913     MOV        EAX,ECX
    //         00448915     XOR        EDX,EDX
    //         00448917     DIV        dword ptr [DAT_00888498]
    //                              Dsutil.c:1559 (56)
    //         0044891d     MOV        EDX,dword ptr [_wiWave]
    //         00448923     MOV        dword ptr [DAT_008884b0],EBP
    //         00448929     SUB        ESI,ECX
    //         0044892b     PUSH       ESI
    //         0044892c     MOV        [DAT_008884b4],EAX
    //         00448931     XOR        EAX,EAX
    //         00448933     CMP        word ptr [EDX + 0xe],0x8
    //         00448938     SETNZ      AL
    //         0044893b     DEC        EAX
    //         0044893c     AND        EAX,0x80
    //         00448941     PUSH       EAX=>DAT_fffffff8
    //         00448942     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00448946     ADD        ECX,EAX
    //         00448948     PUSH       ECX=>DAT_fffffff4
    //         00448949     CALL       memset                                           undefined memset()
    //         0044894e     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00448952     ADD        ESP,0xc
    //                               LAB_00448955                                                 XREF[3]:     00448886(j), 004488b5(j), 
    //                                                                                                         00448911(j)  
    //                              Dsutil.c:1564 (23)
    //         00448955     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00448959     MOV        EAX,[_lpDSBStreamBuffer]
    //         0044895e     PUSH       EBX
    //         0044895f     PUSH       EDX=>DAT_fffffff8
    //         00448960     MOV        EDX,dword ptr [ESP + 0x1c]
    //         00448964     MOV        ECX,dword ptr [EAX]
    //         00448966     PUSH       ESI=>DAT_fffffff4
    //         00448967     PUSH       EDX=>DAT_fffffff0
    //         00448968     PUSH       EAX
    //         00448969     CALL       dword ptr [ECX + 0x4c]
    //                              Dsutil.c:1567 (4)
    //         0044896c     MOV        EAX,dword ptr [ESP + 0x40]
    //                              Dsutil.c:1571 (60)
    //         00448970     MOV        ECX,dword ptr [_main_wnd]
    //         00448976     PUSH       EBX
    //         00448977     PUSH       EBX=>DAT_fffffff8
    //         00448978     AND        EAX,0xff
    //         0044897d     PUSH       offset DAT_fffffff4
    //         00448982     PUSH       ECX=>DAT_fffffff0
    //         00448983     MOV        dword ptr [DAT_008884a4],EBX
    //         00448989     MOV        dword ptr [DAT_008884a0],EBX
    //         0044898f     MOV        dword ptr [DAT_0088849c],EBX
    //         00448995     MOV        dword ptr [DAT_008884a8],EBX
    //         0044899b     MOV        [DAT_008884ac],EAX
    //         004489a0     MOV        dword ptr [_bFileOpen],EBP
    //         004489a6     CALL       dword ptr [->USER32.DLL::SendMessageA]           = 0048ad08
    //                              Dsutil.c:1574 (12)
    //         004489ac     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489b1     PUSH       EBX
    //         004489b2     PUSH       EAX=>DAT_fffffff8
    //         004489b3     MOV        EDX,dword ptr [EAX]
    //         004489b5     CALL       dword ptr [EDX + 0x34]
    //                              Dsutil.c:1575 (16)
    //         004489b8     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489bd     MOV        EDX,dword ptr [ESP + 0x44]
    //         004489c1     PUSH       EDX
    //         004489c2     PUSH       EAX=>DAT_fffffff8
    //         004489c3     MOV        ECX,dword ptr [EAX]
    //         004489c5     CALL       dword ptr [ECX + 0x3c]
    //                              Dsutil.c:1576 (14)
    //         004489c8     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489cd     PUSH       EBP
    //         004489ce     PUSH       EBX=>DAT_fffffff8
    //         004489cf     PUSH       EBX=>DAT_fffffff4
    //         004489d0     MOV        ECX,dword ptr [EAX]
    //         004489d2     PUSH       EAX=>DAT_fffffff0
    //         004489d3     CALL       dword ptr [ECX + 0x30]
    //                              Dsutil.c:1578 (12)
    //         004489d6     PUSH       0x32
    //         004489d8     CALL       dword ptr [->WINMM.DLL::timeBeginPeriod]         = 0048b4fe
    //         004489de     TEST       EAX,EAX
    //         004489e0     JZ         LAB_00448a03
    //                              Dsutil.c:1581 (11)
    //         004489e2     MOV        EAX,[_lpDSBStreamBuffer]
    //         004489e7     PUSH       EAX
    //         004489e8     MOV        EDX,dword ptr [EAX]
    //         004489ea     CALL       dword ptr [EDX + 0x48]
    //                              Dsutil.c:1582 (12)
    //         004489ed     MOV        dword ptr [_bTimerInstalled],EBX
    //         004489f3     MOV        dword ptr [_bPlaying],EBX
    //                              Dsutil.c:1584 (2)
    //         004489f9     XOR        EAX,EAX
    //                              Dsutil.c:1595 (8)
    //         004489fb     POP        EDI
    //         004489fc     POP        ESI
    //         004489fd     POP        EBP
    //         004489fe     POP        EBX
    //         004489ff     ADD        ESP,0x28
    //         00448a02     RET
    //                               LAB_00448a03                                                 XREF[1]:     004489e0(j)  
    //                              Dsutil.c:1588 (26)
    //         00448a03     PUSH       EBP
    //         00448a04     PUSH       EBX=>DAT_fffffff8
    //         00448a05     PUSH       ds_stream_time_func
    //         00448a0a     PUSH       offset DAT_fffffff0
    //         00448a0c     PUSH       0x32
    //         00448a0e     CALL       dword ptr [->WINMM.DLL::timeSetEvent]            = 0048b4ee
    //         00448a14     CMP        EAX,EBX
    //         00448a16     MOV        [_uTimerID],EAX
    //         00448a1b     JZ         LAB_00448a23
    //                              Dsutil.c:1589 (6)
    //         00448a1d     MOV        dword ptr [_bTimerInstalled],EBP
    //                               LAB_00448a23                                                 XREF[1]:     00448a1b(j)  
    //                              Dsutil.c:1595 (16)
    //         00448a23     POP        EDI
    //         00448a24     MOV        dword ptr [_bPlaying],EBP
    //         00448a2a     MOV        EAX,EBP
    //         00448a2c     POP        ESI
    //         00448a2d     POP        EBP
    //         00448a2e     POP        EBX
    //         00448a2f     ADD        ESP,0x28
    //         00448a32     RET
    //         00448a33     ??         90h
    //         00448a34     NOP
    //         00448a35     NOP
    //         00448a36     NOP
    //         00448a37     NOP
    //         00448a38     NOP
    //         00448a39     NOP
    //         00448a3a     NOP
    //         00448a3b     NOP
    //         00448a3c     NOP
    //         00448a3d     NOP
    //         00448a3e     NOP
    //         00448a3f     NOP
    //                              * ds_stream_volume                                                                                      *
    //                              undefined __cdecl ds_stream_volume()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_volume                                            XREF[1]:     set_stream_volume:004bc93f(c)  
    //                               ds_stream_volume
    //                              Dsutil.c:1602 (9)
    //         00448a40     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448a45     TEST       EAX,EAX
    //         00448a47     JNZ        LAB_00448a4a
    //                              Dsutil.c:1614 (1)
    //         00448a49     RET
    //                               LAB_00448a4a                                                 XREF[1]:     00448a47(j)  
    //                              Dsutil.c:1608 (11)
    //         00448a4a     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         00448a4e     MOV        ECX,dword ptr [EAX]
    //         00448a50     PUSH       EDX
    //         00448a51     PUSH       EAX
    //         00448a52     CALL       dword ptr [ECX + 0x3c]
    //                              Dsutil.c:1610 (9)
    //         00448a55     XOR        ECX,ECX
    //         00448a57     TEST       EAX,EAX
    //         00448a59     SETZ       CL
    //         00448a5c     MOV        EAX,ECX
    //                              Dsutil.c:1614 (1)
    //         00448a5e     RET
    //         00448a5f     ??         90h
    //                              * ds_stream_pause                                                                                       *
    //                              undefined __cdecl ds_stream_pause()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_pause                                             XREF[1]:     pause_stream:004bc958(c)  
    //                               ds_stream_pause
    //                              Dsutil.c:1620 (10)
    //         00448a60     MOV        EAX,0x1
    //         00448a65     MOV        [_stream_paused],EAX
    //                              Dsutil.c:1623 (1)
    //         00448a6a     RET
    //         00448a6b     ??         90h
    //         00448a6c     NOP
    //         00448a6d     NOP
    //         00448a6e     NOP
    //         00448a6f     NOP
    //                              * ds_stream_resume                                                                                      *
    //                              undefined __cdecl ds_stream_resume()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_resume                                            XREF[1]:     resume_stream:004bc968(c)  
    //                               ds_stream_resume
    //                              Dsutil.c:1629 (10)
    //         00448a70     MOV        dword ptr [_stream_paused],0x0
    //                              Dsutil.c:1631 (5)
    //         00448a7a     MOV        EAX,0x1
    //                              Dsutil.c:1632 (1)
    //         00448a7f     RET
    //                              * ds_stream_stop                                                                                        *
    //                              undefined __cdecl ds_stream_stop()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _ds_stream_stop                                              XREF[4]:     ds_stream_exit:004486d4(c), 
    //                               ds_stream_stop                                                            ds_stream_file:00448712(c), 
    //                                                                                                         ds_stream_messages:00448b8e(c), 
    //                                                                                                         stop_stream:004bc978(c)  
    //                              Dsutil.c:1638 (22)
    //         00448a80     MOV        EAX,[_bTimerInstalled]
    //         00448a85     PUSH       ESI
    //         00448a86     XOR        ESI,ESI
    //         00448a88     MOV        dword ptr [DAT_008884a8],0x1
    //         00448a92     CMP        EAX,ESI
    //         00448a94     JZ         LAB_00448ab0
    //                              Dsutil.c:1646 (18)
    //         00448a96     MOV        EAX,[_uTimerID]
    //         00448a9b     MOV        dword ptr [_bTimerInstalled],ESI
    //         00448aa1     PUSH       EAX
    //         00448aa2     CALL       dword ptr [->WINMM.DLL::timeKillEvent]           = 0048b520
    //                              Dsutil.c:1647 (8)
    //         00448aa8     PUSH       0x32
    //         00448aaa     CALL       dword ptr [->WINMM.DLL::timeEndPeriod]           = 0048b510
    //                               LAB_00448ab0                                                 XREF[1]:     00448a94(j)  
    //                              Dsutil.c:1650 (8)
    //         00448ab0     CMP        dword ptr [_bPlaying],ESI
    //         00448ab6     JZ         LAB_00448acd
    //                              Dsutil.c:1653 (15)
    //         00448ab8     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448abd     MOV        dword ptr [_bPlaying],ESI
    //         00448ac3     CMP        EAX,ESI
    //         00448ac5     JZ         LAB_00448ad2
    //                              Dsutil.c:1654 (11)
    //         00448ac7     MOV        ECX,dword ptr [EAX]
    //         00448ac9     PUSH       EAX
    //         00448aca     CALL       dword ptr [ECX + 0x48]
    //                               LAB_00448acd                                                 XREF[1]:     00448ab6(j)  
    //         00448acd     MOV        EAX,[_lpDSBStreamBuffer]
    //                               LAB_00448ad2                                                 XREF[1]:     00448ac5(j)  
    //                              Dsutil.c:1661 (8)
    //         00448ad2     CMP        dword ptr [_bFileOpen],ESI
    //         00448ad8     JZ         LAB_00448b1b
    //                              Dsutil.c:1663 (8)
    //         00448ada     CMP        dword ptr [_wiWave],ESI
    //         00448ae0     JZ         LAB_00448aff
    //                              Dsutil.c:1665 (15)
    //         00448ae2     PUSH       _wiWave
    //         00448ae7     PUSH       DAT_00888464
    //         00448aec     CALL       _WaveCloseReadFile                               undefined _WaveCloseReadFile()
    //                              Dsutil.c:1666 (14)
    //         00448af1     MOV        EAX,[_lpDSBStreamBuffer]
    //         00448af6     ADD        ESP,0x8
    //         00448af9     MOV        dword ptr [_wiWave],ESI
    //                               LAB_00448aff                                                 XREF[1]:     00448ae0(j)  
    //                              Dsutil.c:1668 (4)
    //         00448aff     CMP        EAX,ESI
    //         00448b01     JZ         LAB_00448b15
    //                              Dsutil.c:1670 (6)
    //         00448b03     MOV        EDX,dword ptr [EAX]
    //         00448b05     PUSH       EAX
    //         00448b06     CALL       dword ptr [EDX + 0x8]
    //                              Dsutil.c:1671 (6)
    //         00448b09     MOV        dword ptr [_lpDSBStreamBuffer],ESI
    //                              Dsutil.c:1672 (6)
    //         00448b0f     MOV        dword ptr [DAT_00888490],ESI
    //                               LAB_00448b15                                                 XREF[1]:     00448b01(j)  
    //                              Dsutil.c:1674 (6)
    //         00448b15     MOV        dword ptr [_bFileOpen],ESI
    //                               LAB_00448b1b                                                 XREF[1]:     00448ad8(j)  
    //                              Dsutil.c:1677 (5)
    //         00448b1b     MOV        EAX,0x1
    //                              Dsutil.c:1678 (2)
    //         00448b20     POP        ESI
    //         00448b21     RET
    //         00448b22     ??         90h
    //         00448b23     NOP
    //         00448b24     NOP
    //         00448b25     NOP
    //         00448b26     NOP
    //         00448b27     NOP
    //         00448b28     NOP
    //         00448b29     NOP
    //         00448b2a     NOP
    //         00448b2b     NOP
    //         00448b2c     NOP
    //         00448b2d     NOP
    //         00448b2e     NOP
    //         00448b2f     NOP
    //                              * ds_stream_messages                                                                                    *
    //                              undefined __cdecl ds_stream_messages()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined8        Stack[-0x8]:8  local_8                   XREF[2,1]:   00448b6e(*), 00448b72(*), 00448b5e(W)  
    //                               _ds_stream_messages                                          XREF[1]:     handle_messages:004bc99e(c)  
    //                               ds_stream_messages
    //                              Dsutil.c:1684 (19)
    //         00448b30     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         00448b34     SUB        ESP,0x8
    //         00448b37     SUB        EAX,0x500
    //         00448b3c     JZ         LAB_00448b8e
    //         00448b3e     SUB        EAX,0x2
    //         00448b41     JNZ        LAB_00448b93
    //                              Dsutil.c:1693 (15)
    //         00448b43     MOV        EAX,[DAT_008884a4]
    //         00448b48     MOV        ECX,dword ptr [DAT_00888480]
    //         00448b4e     CMP        EAX,ECX
    //         00448b50     JBE        LAB_00448b59
    //                              Dsutil.c:1694 (7)
    //         00448b52     SUB        EAX,ECX
    //         00448b54     MOV        [DAT_008884a4],EAX
    //                               LAB_00448b59                                                 XREF[1]:     00448b50(j)  
    //                              Dsutil.c:1699 (34)
    //         00448b59     LEA        EAX,[EAX + EAX*0x4]
    //         00448b5c     XOR        EDX,EDX
    //         00448b5e     MOV        dword ptr [ESP + local_8+0x4],0x0
    //         00448b66     LEA        EAX,[EAX + EAX*0x4]
    //         00448b69     SHL        EAX,0x2
    //         00448b6c     DIV        ECX
    //         00448b6e     MOV        dword ptr [ESP]=>local_8,EAX
    //         00448b72     FILD       qword ptr [ESP]=>local_8
    //         00448b76     CALL       __ftol                                           undefined __ftol()
    //                              Dsutil.c:1700 (8)
    //         00448b7b     CMP        EAX,dword ptr [_uLastPercent]
    //         00448b81     JZ         LAB_00448b93
    //                              Dsutil.c:1702 (5)
    //         00448b83     MOV        [_uLastPercent],EAX
    //                              Dsutil.c:1717 (2)
    //         00448b88     XOR        EAX,EAX
    //                              Dsutil.c:1718 (4)
    //         00448b8a     ADD        ESP,0x8
    //         00448b8d     RET
    //                               LAB_00448b8e                                                 XREF[1]:     00448b3c(j)  
    //                              Dsutil.c:1714 (5)
    //         00448b8e     CALL       ds_stream_stop                                   undefined ds_stream_stop()
    //                               LAB_00448b93                                                 XREF[2]:     00448b41(j), 00448b81(j)  
    //                              Dsutil.c:1717 (2)
    //         00448b93     XOR        EAX,EAX
    //                              Dsutil.c:1718 (4)
    //         00448b95     ADD        ESP,0x8
    //         00448b98     RET
    //         00448b99     ??         90h
    //         00448b9a     NOP
    //         00448b9b     NOP
    //         00448b9c     NOP
    //         00448b9d     NOP
    //         00448b9e     NOP
    //         00448b9f     NOP
    //                              * __stdcall ds_stream_time_func,20                                                                      *
    //                              undefined __stdcall ds_stream_time_func()
    //              undefined         <UNASSIGNED>   <RETURN>
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     00448be8(*)  
    //              ulong             Stack[-0x8]:4  dwWrite                   XREF[1]:     00448bed(*)  
    //              ulong             Stack[-0xc]:4  dwPlay
    //              uchar *           Stack[-0x10]:4 lpWrite2
    //              uint              Stack[-0x14]:4 uChkErr
    //              uchar *           Stack[-0x18]:4 lpWrite1
    //              ulong             Stack[-0x1c]:4 dwLen2
    //              ulong             Stack[-0x20]:4 dwLen1
    //                               _ds_stream_time_func@20                                      XREF[1]:     ds_stream_file:00448a05(*)  
    //                               ds_stream_time_func
    //                              Dsutil.c:1726 (33)
    //         00448ba0     MOV        EAX,[DAT_0062e658]
    //         00448ba5     SUB        ESP,0x1c
    //         00448ba8     PUSH       EBX
    //         00448ba9     PUSH       EBP
    //         00448baa     XOR        EBP,EBP
    //         00448bac     PUSH       ESI
    //         00448bad     CMP        EAX,EBP
    //         00448baf     JNZ        LAB_004490cb
    //         00448bb5     CMP        dword ptr [_stream_paused],EBP
    //         00448bbb     JNZ        LAB_004490cb
    //                              Dsutil.c:1738 (37)
    //         00448bc1     MOV        EAX,[DAT_008884a8]
    //         00448bc6     MOV        EBX,0x1
    //         00448bcb     CMP        EAX,EBP
    //         00448bcd     MOV        dword ptr [DAT_0062e658],EBX
    //         00448bd3     JNZ        LAB_004490c5
    //         00448bd9     MOV        EAX,[DAT_00888490]
    //         00448bde     CMP        EAX,EBP
    //         00448be0     JZ         LAB_004490c5
    //                              Dsutil.c:1746 (16)
    //         00448be6     MOV        ECX,dword ptr [EAX]
    //         00448be8     LEA        EDX=>local_4,[ESP + 0x24]
    //         00448bec     PUSH       EDX
    //         00448bed     LEA        EDX=>dwWrite,[ESP + 0x24]
    //         00448bf1     PUSH       EDX
    //         00448bf2     PUSH       EAX
    //         00448bf3     CALL       dword ptr [ECX + 0x10]
    //                              Dsutil.c:1754 (24)
    //         00448bf6     MOV        ECX,dword ptr [DAT_0088849c]
    //         00448bfc     MOV        EAX,dword ptr [ESP + 0x20]
    //         00448c00     CMP        ECX,EAX
    //         00448c02     JNC        LAB_00448c14
    //         00448c04     MOV        EDX,dword ptr [DAT_00888498]
    //         00448c0a     ADD        ECX,EDX
    //         00448c0c     CMP        ECX,EAX
    //                              Dsutil.c:1757 (6)
    //         00448c0e     JA         LAB_004490c5
    //                               LAB_00448c14                                                 XREF[1]:     00448c02(j)  
    //                              Dsutil.c:1761 (16)
    //         00448c14     CMP        dword ptr [DAT_008884b0],EBP
    //         00448c1a     JZ         LAB_00448c58
    //         00448c1c     CMP        dword ptr [DAT_008884b4],EBP
    //         00448c22     JNZ        LAB_00448c58
    //                              Dsutil.c:1763 (12)
    //         00448c24     CMP        dword ptr [DAT_008884a8],EBP
    //         00448c2a     JNZ        LAB_004490c5
    //                              Dsutil.c:1766 (31)
    //         00448c30     MOV        EAX,[_main_wnd]
    //         00448c35     PUSH       EBP
    //         00448c36     PUSH       EBP=>DAT_fffffff8
    //         00448c37     PUSH       offset DAT_fffffff4
    //         00448c3c     PUSH       EAX=>DAT_fffffff0
    //         00448c3d     MOV        dword ptr [DAT_008884a8],EBX
    //         00448c43     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //         00448c49     MOV        dword ptr [DAT_0062e658],EBP
    //                              Dsutil.c:1983 (9)
    //         00448c4f     POP        ESI
    //         00448c50     POP        EBP
    //         00448c51     POP        EBX
    //         00448c52     ADD        ESP,0x1c
    //         00448c55     RET        0x14
    //                               LAB_00448c58                                                 XREF[2]:     00448c1a(j), 00448c22(j)  
    //                              Dsutil.c:1772 (10)
    //         00448c58     MOV        ECX,dword ptr [DAT_008884a0]
    //         00448c5e     CMP        EAX,ECX
    //         00448c60     JNC        LAB_00448c6c
    //                              Dsutil.c:1773 (8)
    //         00448c62     MOV        EDX,dword ptr [DAT_00888494]
    //         00448c68     ADD        EDX,EAX
    //                              Dsutil.c:1774 (2)
    //         00448c6a     JMP        LAB_00448c6e
    //                               LAB_00448c6c                                                 XREF[1]:     00448c60(j)  
    //                              Dsutil.c:1775 (10)
    //         00448c6c     MOV        EDX,EAX
    //                               LAB_00448c6e                                                 XREF[1]:     00448c6a(j)  
    //         00448c6e     SUB        EDX,ECX
    //         00448c70     MOV        ECX,dword ptr [DAT_008884a4]
    //                              Dsutil.c:1776 (5)
    //         00448c76     MOV        [DAT_008884a0],EAX
    //                              Dsutil.c:1777 (27)
    //         00448c7b     MOV        EAX,[_main_wnd]
    //         00448c80     PUSH       EBP
    //         00448c81     PUSH       EBP=>DAT_fffffff8
    //         00448c82     ADD        ECX,EDX
    //         00448c84     PUSH       offset DAT_fffffff4
    //         00448c89     PUSH       EAX=>DAT_fffffff0
    //         00448c8a     MOV        dword ptr [DAT_008884a4],ECX
    //         00448c90     CALL       dword ptr [->USER32.DLL::PostMessageA]           = 0048afc2
    //                              Dsutil.c:1784 (25)
    //         00448c96     CMP        dword ptr [DAT_008884b0],EBP
    //         00448c9c     JZ         LAB_00448d7b
    //         00448ca2     MOV        EAX,[DAT_008884b4]
    //         00448ca7     CMP        EAX,EBP
    //         00448ca9     JZ         LAB_00448d7b
    //                              Dsutil.c:1786 (1)
    //         00448caf     DEC        EAX
    //                              Dsutil.c:1788 (26)
    //         00448cb0     CMP        EAX,EBX
    //         00448cb2     MOV        [DAT_008884b4],EAX
    //         00448cb7     JLE        LAB_004490c5
    //         00448cbd     MOV        EAX,[DAT_00888490]
    //         00448cc2     CMP        EAX,EBP
    //         00448cc4     JZ         LAB_004490c5
    //                              Dsutil.c:1795 (43)
    //         00448cca     LEA        EDX,[ESP + 0x10]
    //         00448cce     PUSH       EBP
    //         00448ccf     PUSH       EDX=>DAT_fffffff8
    //         00448cd0     LEA        EDX,[ESP + 0x24]
    //         00448cd4     PUSH       EDX=>DAT_fffffff4
    //         00448cd5     LEA        EDX,[ESP + 0x18]
    //         00448cd9     PUSH       EDX=>DAT_fffffff0
    //         00448cda     MOV        ECX,dword ptr [EAX]
    //         00448cdc     LEA        EDX,[ESP + 0x24]
    //         00448ce0     PUSH       EDX
    //         00448ce1     MOV        EDX,dword ptr [DAT_00888498]
    //         00448ce7     PUSH       EDX
    //         00448ce8     MOV        EDX,dword ptr [DAT_0088849c]
    //         00448cee     PUSH       EDX
    //         00448cef     PUSH       EAX
    //         00448cf0     CALL       dword ptr [ECX + 0x2c]
    //         00448cf3     TEST       EAX,EAX
    //                              Dsutil.c:1799 (6)
    //         00448cf5     JNZ        LAB_004490c5
    //                              Dsutil.c:1803 (17)
    //         00448cfb     MOV        EAX,[_wiWave]
    //         00448d00     CMP        EAX,EBP
    //         00448d02     JZ         LAB_00448d37
    //         00448d04     MOV        ECX,dword ptr [ESP + 0x14]
    //         00448d08     CMP        ECX,EBP
    //         00448d0a     JZ         LAB_00448d37
    //                              Dsutil.c:1805 (10)
    //         00448d0c     MOV        AX,word ptr [EAX + 0xe]
    //         00448d10     CMP        AX,0x8
    //         00448d14     JNZ        LAB_00448d22
    //                              Dsutil.c:1806 (10)
    //         00448d16     MOV        EAX,dword ptr [ESP + 0xc]
    //         00448d1a     PUSH       EAX
    //                              language.dll match for 0x80: "Arial"
    //         00448d1b     PUSH       offset DAT_fffffff8
    //                              Dsutil.c:1807 (8)
    //         00448d20     JMP        LAB_00448d2e
    //                               LAB_00448d22                                                 XREF[1]:     00448d14(j)  
    //         00448d22     CMP        AX,0x10
    //         00448d26     JNZ        LAB_00448d37
    //                              Dsutil.c:1808 (15)
    //         00448d28     MOV        EDX,dword ptr [ESP + 0xc]
    //         00448d2c     PUSH       EDX
    //         00448d2d     PUSH       EBP=>DAT_fffffff8
    //                               LAB_00448d2e                                                 XREF[1]:     00448d20(j)  
    //         00448d2e     PUSH       ECX=>DAT_fffffff4
    //         00448d2f     CALL       memset                                           undefined memset()
    //         00448d34     ADD        ESP,0xc
    //                               LAB_00448d37                                                 XREF[3]:     00448d02(j), 00448d0a(j), 
    //                                                                                                         00448d26(j)  
    //                              Dsutil.c:1813 (31)
    //         00448d37     MOV        EDX,dword ptr [ESP + 0x10]
    //         00448d3b     MOV        EAX,[DAT_00888490]
    //         00448d40     PUSH       EDX
    //         00448d41     MOV        EDX,dword ptr [ESP + 0x20]
    //         00448d45     MOV        ECX,dword ptr [EAX]
    //         00448d47     PUSH       EDX=>DAT_fffffff8
    //         00448d48     MOV        EDX,dword ptr [ESP + 0x14]
    //         00448d4c     PUSH       EDX=>DAT_fffffff4
    //         00448d4d     MOV        EDX,dword ptr [ESP + 0x20]
    //         00448d51     PUSH       EDX=>DAT_fffffff0
    //         00448d52     PUSH       EAX
    //         00448d53     CALL       dword ptr [ECX + 0x4c]
    //                              Dsutil.c:1820 (11)
    //         00448d56     MOV        EAX,[DAT_0088849c]
    //         00448d5b     MOV        ESI,dword ptr [DAT_00888498]
    //                              Dsutil.c:1821 (21)
    //         00448d61     MOV        ECX,dword ptr [DAT_00888494]
    //         00448d67     ADD        EAX,ESI
    //         00448d69     CMP        EAX,ECX
    //         00448d6b     MOV        [DAT_0088849c],EAX
    //         00448d70     JC         LAB_004490c5
    //                              Dsutil.c:1826 (5)
    //         00448d76     JMP        LAB_004490be
    //                               LAB_00448d7b                                                 XREF[2]:     00448c9c(j), 00448ca9(j)  
    //                              Dsutil.c:1830 (7)
    //         00448d7b     MOV        EAX,[DAT_00888490]
    //         00448d80     CMP        EAX,EBP
    //                              Dsutil.c:1833 (6)
    //         00448d82     JZ         LAB_004490c5
    //                              Dsutil.c:1841 (43)
    //         00448d88     LEA        EDX,[ESP + 0x10]
    //         00448d8c     PUSH       EBP
    //         00448d8d     PUSH       EDX=>DAT_fffffff8
    //         00448d8e     LEA        EDX,[ESP + 0x24]
    //         00448d92     PUSH       EDX=>DAT_fffffff4
    //         00448d93     LEA        EDX,[ESP + 0x18]
    //         00448d97     PUSH       EDX=>DAT_fffffff0
    //         00448d98     MOV        ECX,dword ptr [EAX]
    //         00448d9a     LEA        EDX,[ESP + 0x24]
    //         00448d9e     PUSH       EDX
    //         00448d9f     MOV        EDX,dword ptr [DAT_00888498]
    //         00448da5     PUSH       EDX
    //         00448da6     MOV        EDX,dword ptr [DAT_0088849c]
    //         00448dac     PUSH       EDX
    //         00448dad     PUSH       EAX
    //         00448dae     CALL       dword ptr [ECX + 0x2c]
    //         00448db1     TEST       EAX,EAX
    //                              Dsutil.c:1845 (6)
    //         00448db3     JNZ        LAB_004490c5
    //                              Dsutil.c:1849 (26)
    //         00448db9     MOV        EAX,dword ptr [ESP + 0xc]
    //         00448dbd     MOV        ECX,dword ptr [DAT_008884a8]
    //         00448dc3     CMP        EAX,EBP
    //         00448dc5     JZ         LAB_00448ee3
    //         00448dcb     CMP        ECX,EBP
    //         00448dcd     JNZ        LAB_00448ee3
    //                              Dsutil.c:1852 (27)
    //         00448dd3     MOV        EDX,dword ptr [ESP + 0x14]
    //         00448dd7     LEA        ECX,[ESP + 0x18]
    //         00448ddb     PUSH       ECX
    //         00448ddc     PUSH       DAT_00888468                                     = align(24)
    //         00448de1     PUSH       EDX=>DAT_fffffff4
    //         00448de2     PUSH       EAX=>DAT_fffffff0
    //         00448de3     MOV        EAX,[DAT_00888464]
    //         00448de8     PUSH       EAX
    //         00448de9     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1853 (19)
    //         00448dee     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00448df2     MOV        ESI,dword ptr [ESP + 0x20]
    //         00448df6     ADD        ESP,0x14
    //         00448df9     CMP        EAX,ESI
    //         00448dfb     JNC        LAB_00448f18
    //                              Dsutil.c:1855 (8)
    //         00448e01     CMP        dword ptr [DAT_008884ac],EBP
    //         00448e07     JNZ        LAB_00448e87
    //                              Dsutil.c:1858 (18)
    //         00448e09     MOV        ECX,dword ptr [_wiWave]
    //         00448e0f     CMP        ECX,EBP
    //         00448e11     JZ         LAB_00448e44
    //         00448e13     MOV        EDX,dword ptr [ESP + 0x14]
    //         00448e17     CMP        EDX,EBP
    //         00448e19     JZ         LAB_00448e44
    //                              Dsutil.c:1860 (10)
    //         00448e1b     MOV        CX,word ptr [ECX + 0xe]
    //         00448e1f     CMP        CX,0x8
    //         00448e23     JNZ        LAB_00448e2f
    //                              Dsutil.c:1861 (8)
    //         00448e25     SUB        ESI,EAX
    //         00448e27     PUSH       ESI
    //                              language.dll match for 0x80: "Arial"
    //         00448e28     PUSH       offset DAT_fffffff8
    //                              Dsutil.c:1862 (8)
    //         00448e2d     JMP        LAB_00448e39
    //                               LAB_00448e2f                                                 XREF[1]:     00448e23(j)  
    //         00448e2f     CMP        CX,0x10
    //         00448e33     JNZ        LAB_00448e44
    //                              Dsutil.c:1863 (15)
    //         00448e35     SUB        ESI,EAX
    //         00448e37     PUSH       ESI
    //         00448e38     PUSH       EBP=>DAT_fffffff8
    //                               LAB_00448e39                                                 XREF[1]:     00448e2d(j)  
    //         00448e39     ADD        EAX,EDX
    //         00448e3b     PUSH       EAX=>DAT_fffffff4
    //         00448e3c     CALL       memset                                           undefined memset()
    //         00448e41     ADD        ESP,0xc
    //                               LAB_00448e44                                                 XREF[3]:     00448e11(j), 00448e19(j), 
    //                                                                                                         00448e33(j)  
    //                              Dsutil.c:1867 (19)
    //         00448e44     MOV        ECX,dword ptr [ESP + 0x20]
    //         00448e48     MOV        EAX,[DAT_0088849c]
    //         00448e4d     CMP        ECX,EAX
    //         00448e4f     MOV        dword ptr [DAT_008884b0],EBX
    //         00448e55     JBE        LAB_00448e73
    //                              Dsutil.c:1870 (23)
    //         00448e57     MOV        EDX,dword ptr [DAT_00888494]
    //         00448e5d     ADD        EAX,EDX
    //         00448e5f     XOR        EDX,EDX
    //         00448e61     SUB        EAX,ECX
    //         00448e63     DIV        dword ptr [DAT_00888498]
    //         00448e69     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1871 (5)
    //         00448e6e     JMP        LAB_00448f18
    //                               LAB_00448e73                                                 XREF[1]:     00448e55(j)  
    //                              Dsutil.c:1874 (15)
    //         00448e73     SUB        EAX,ECX
    //         00448e75     XOR        EDX,EDX
    //         00448e77     DIV        dword ptr [DAT_00888498]
    //         00448e7d     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1876 (17)
    //         00448e82     JMP        LAB_00448f18
    //                               LAB_00448e87                                                 XREF[1]:     00448e07(j)  
    //         00448e87     MOV        ESI,dword ptr [ESP + 0x14]
    //         00448e8b     CMP        ESI,EBP
    //         00448e8d     JZ         LAB_00448f18
    //                               LAB_00448e93                                                 XREF[1]:     00448edf(j)  
    //                              Dsutil.c:1887 (4)
    //         00448e93     MOV        ECX,dword ptr [ESP + 0xc]
    //                              Dsutil.c:1890 (28)
    //         00448e97     PUSH       null_0088847c                                    = align(4)
    //         00448e9c     SUB        ECX,EAX
    //         00448e9e     PUSH       DAT_00888468                                     = align(24)
    //         00448ea3     PUSH       DAT_00888464
    //         00448ea8     ADD        ESI,EAX
    //         00448eaa     MOV        dword ptr [ESP + 0x18],ECX
    //         00448eae     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //                              Dsutil.c:1893 (31)
    //         00448eb3     MOV        ECX,dword ptr [ESP + 0x18]
    //         00448eb7     MOV        EDX,dword ptr [DAT_00888464]
    //         00448ebd     ADD        ESP,0xc
    //         00448ec0     LEA        EAX,[ESP + 0x18]
    //         00448ec4     PUSH       EAX
    //         00448ec5     PUSH       DAT_00888468                                     = align(24)
    //         00448eca     PUSH       ESI=>DAT_fffffff4
    //         00448ecb     PUSH       ECX=>DAT_fffffff0
    //         00448ecc     PUSH       EDX
    //         00448ecd     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1894 (15)
    //         00448ed2     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00448ed6     MOV        ECX,dword ptr [ESP + 0x20]
    //         00448eda     ADD        ESP,0x14
    //         00448edd     CMP        EAX,ECX
    //         00448edf     JC         LAB_00448e93
    //                              Dsutil.c:1904 (10)
    //         00448ee1     JMP        LAB_00448f18
    //                               LAB_00448ee3                                                 XREF[2]:     00448dc5(j), 00448dcd(j)  
    //         00448ee3     CMP        EAX,EBP
    //         00448ee5     JZ         LAB_00448f18
    //         00448ee7     CMP        ECX,EBP
    //         00448ee9     JZ         LAB_00448f18
    //                              Dsutil.c:1907 (18)
    //         00448eeb     MOV        ESI,dword ptr [_wiWave]
    //         00448ef1     CMP        ESI,EBP
    //         00448ef3     JZ         LAB_00448f18
    //         00448ef5     MOV        ECX,dword ptr [ESP + 0x14]
    //         00448ef9     CMP        ECX,EBP
    //         00448efb     JZ         LAB_00448f18
    //                              Dsutil.c:1910 (27)
    //         00448efd     PUSH       EAX
    //         00448efe     XOR        EAX,EAX
    //         00448f00     CMP        word ptr [ESI + 0xe],0x8
    //         00448f05     SETNZ      AL
    //         00448f08     DEC        EAX
    //         00448f09     AND        EAX,0x80
    //         00448f0e     PUSH       EAX=>DAT_fffffff8
    //         00448f0f     PUSH       ECX=>DAT_fffffff4
    //         00448f10     CALL       memset                                           undefined memset()
    //         00448f15     ADD        ESP,0xc
    //                               LAB_00448f18                                                 XREF[9]:     00448dfb(j), 00448e6e(j), 
    //                                                                                                         00448e82(j), 00448e8d(j), 
    //                                                                                                         00448ee1(j), 00448ee5(j), 
    //                                                                                                         00448ee9(j), 00448ef3(j), 
    //                                                                                                         00448efb(j)  
    //                              Dsutil.c:1913 (24)
    //         00448f18     MOV        ECX,dword ptr [ESP + 0x10]
    //         00448f1c     CMP        ECX,EBP
    //         00448f1e     JZ         LAB_00449083
    //         00448f24     CMP        dword ptr [DAT_008884a8],EBP
    //         00448f2a     JNZ        LAB_00449045
    //                              Dsutil.c:1916 (28)
    //         00448f30     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00448f34     LEA        EDX,[ESP + 0x18]
    //         00448f38     PUSH       EDX
    //         00448f39     PUSH       DAT_00888468                                     = align(24)
    //         00448f3e     PUSH       EAX=>DAT_fffffff4
    //         00448f3f     PUSH       ECX=>DAT_fffffff0
    //         00448f40     MOV        ECX,dword ptr [DAT_00888464]
    //         00448f46     PUSH       ECX
    //         00448f47     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1917 (19)
    //         00448f4c     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00448f50     MOV        ECX,dword ptr [ESP + 0x24]
    //         00448f54     ADD        ESP,0x14
    //         00448f57     CMP        EAX,ECX
    //         00448f59     JNC        LAB_00449083
    //                              Dsutil.c:1919 (12)
    //         00448f5f     CMP        dword ptr [DAT_008884ac],EBP
    //         00448f65     JNZ        LAB_00448fed
    //                              Dsutil.c:1922 (18)
    //         00448f6b     MOV        EDX,dword ptr [_wiWave]
    //         00448f71     CMP        EDX,EBP
    //         00448f73     JZ         LAB_00448faa
    //         00448f75     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00448f79     CMP        ESI,EBP
    //         00448f7b     JZ         LAB_00448faa
    //                              Dsutil.c:1924 (10)
    //         00448f7d     MOV        DX,word ptr [EDX + 0xe]
    //         00448f81     CMP        DX,0x8
    //         00448f85     JNZ        LAB_00448f91
    //                              Dsutil.c:1925 (8)
    //         00448f87     SUB        ECX,EAX
    //         00448f89     PUSH       ECX
    //                              language.dll match for 0x80: "Arial"
    //         00448f8a     PUSH       offset DAT_fffffff8
    //                              Dsutil.c:1926 (8)
    //         00448f8f     JMP        LAB_00448f9b
    //                               LAB_00448f91                                                 XREF[1]:     00448f85(j)  
    //         00448f91     CMP        DX,0x10
    //         00448f95     JNZ        LAB_00448faa
    //                              Dsutil.c:1927 (19)
    //         00448f97     SUB        ECX,EAX
    //         00448f99     PUSH       ECX
    //         00448f9a     PUSH       EBP=>DAT_fffffff8
    //                               LAB_00448f9b                                                 XREF[1]:     00448f8f(j)  
    //         00448f9b     ADD        EAX,ESI
    //         00448f9d     PUSH       EAX=>DAT_fffffff4
    //         00448f9e     CALL       memset                                           undefined memset()
    //         00448fa3     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00448fa7     ADD        ESP,0xc
    //                               LAB_00448faa                                                 XREF[3]:     00448f73(j), 00448f7b(j), 
    //                                                                                                         00448f95(j)  
    //                              Dsutil.c:1933 (19)
    //         00448faa     MOV        EDX,dword ptr [ESP + 0x20]
    //         00448fae     MOV        EAX,[DAT_0088849c]
    //         00448fb3     CMP        EDX,EAX
    //         00448fb5     MOV        dword ptr [DAT_008884b0],EBX
    //         00448fbb     JBE        LAB_00448fd9
    //                              Dsutil.c:1936 (23)
    //         00448fbd     MOV        ESI,dword ptr [DAT_00888494]
    //         00448fc3     ADD        EAX,ESI
    //         00448fc5     SUB        EAX,EDX
    //         00448fc7     XOR        EDX,EDX
    //         00448fc9     DIV        dword ptr [DAT_00888498]
    //         00448fcf     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1937 (5)
    //         00448fd4     JMP        LAB_00449083
    //                               LAB_00448fd9                                                 XREF[1]:     00448fbb(j)  
    //                              Dsutil.c:1940 (15)
    //         00448fd9     SUB        EAX,EDX
    //         00448fdb     XOR        EDX,EDX
    //         00448fdd     DIV        dword ptr [DAT_00888498]
    //         00448fe3     MOV        [DAT_008884b4],EAX
    //                              Dsutil.c:1942 (17)
    //         00448fe8     JMP        LAB_00449083
    //                               LAB_00448fed                                                 XREF[1]:     00448f65(j)  
    //         00448fed     MOV        ESI,dword ptr [ESP + 0x1c]
    //         00448ff1     CMP        ESI,EBP
    //         00448ff3     JZ         LAB_00449083
    //                               LAB_00448ff9                                                 XREF[1]:     00449041(j)  
    //                              Dsutil.c:1956 (28)
    //         00448ff9     PUSH       null_0088847c                                    = align(4)
    //         00448ffe     SUB        ECX,EAX
    //         00449000     PUSH       DAT_00888468                                     = align(24)
    //         00449005     PUSH       DAT_00888464
    //         0044900a     ADD        ESI,EAX
    //         0044900c     MOV        dword ptr [ESP + 0x1c],ECX
    //         00449010     CALL       _WaveStartDataRead                               undefined _WaveStartDataRead()
    //                              Dsutil.c:1959 (31)
    //         00449015     MOV        EAX,dword ptr [ESP + 0x1c]
    //         00449019     MOV        ECX,dword ptr [DAT_00888464]
    //         0044901f     ADD        ESP,0xc
    //         00449022     LEA        EDX,[ESP + 0x18]
    //         00449026     PUSH       EDX
    //         00449027     PUSH       DAT_00888468                                     = align(24)
    //         0044902c     PUSH       ESI=>DAT_fffffff4
    //         0044902d     PUSH       EAX=>DAT_fffffff0
    //         0044902e     PUSH       ECX
    //         0044902f     CALL       _WaveReadFile                                    undefined _WaveReadFile()
    //                              Dsutil.c:1960 (15)
    //         00449034     MOV        EAX,dword ptr [ESP + 0x2c]
    //         00449038     MOV        ECX,dword ptr [ESP + 0x24]
    //         0044903c     ADD        ESP,0x14
    //         0044903f     CMP        EAX,ECX
    //         00449041     JC         LAB_00448ff9
    //                              Dsutil.c:1964 (32)
    //         00449043     JMP        LAB_00449083
    //                               LAB_00449045                                                 XREF[1]:     00448f2a(j)  
    //         00449045     CMP        ECX,EBP
    //         00449047     JZ         LAB_00449083
    //         00449049     CMP        dword ptr [DAT_008884a8],EBP
    //         0044904f     JZ         LAB_00449083
    //         00449051     MOV        EDX,dword ptr [_wiWave]
    //         00449057     CMP        EDX,EBP
    //         00449059     JZ         LAB_00449083
    //         0044905b     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0044905f     CMP        EAX,EBP
    //         00449061     JZ         LAB_00449083
    //                              Dsutil.c:1969 (32)
    //         00449063     PUSH       ECX
    //         00449064     XOR        ECX,ECX
    //         00449066     CMP        word ptr [EDX + 0xe],0x8
    //         0044906b     SETNZ      CL
    //         0044906e     DEC        ECX
    //         0044906f     AND        ECX,0x80
    //         00449075     PUSH       ECX=>DAT_fffffff8
    //         00449076     PUSH       EAX=>DAT_fffffff4
    //         00449077     CALL       memset                                           undefined memset()
    //         0044907c     MOV        ECX,dword ptr [ESP + 0x1c]
    //         00449080     ADD        ESP,0xc
    //                               LAB_00449083                                                 XREF[10]:    00448f1e(j), 00448f59(j), 
    //                                                                                                         00448fd4(j), 00448fe8(j), 
    //                                                                                                         00448ff3(j), 00449043(j), 
    //                                                                                                         00449047(j), 0044904f(j), 
    //                                                                                                         00449059(j), 00449061(j)  
    //                              Dsutil.c:1972 (9)
    //         00449083     MOV        EAX,[DAT_00888490]
    //         00449088     CMP        EAX,EBP
    //         0044908a     JZ         LAB_004490a2
    //                              Dsutil.c:1975 (22)
    //         0044908c     PUSH       ECX
    //         0044908d     MOV        ECX,dword ptr [ESP + 0x20]
    //         00449091     MOV        EDX,dword ptr [EAX]
    //         00449093     PUSH       ECX=>DAT_fffffff8
    //         00449094     MOV        ECX,dword ptr [ESP + 0x14]
    //         00449098     PUSH       ECX=>DAT_fffffff4
    //         00449099     MOV        ECX,dword ptr [ESP + 0x20]
    //         0044909d     PUSH       ECX=>DAT_fffffff0
    //         0044909e     PUSH       EAX
    //         0044909f     CALL       dword ptr [EDX + 0x4c]
    //                               LAB_004490a2                                                 XREF[1]:     0044908a(j)  
    //                              Dsutil.c:1977 (11)
    //         004490a2     MOV        EAX,[DAT_0088849c]
    //         004490a7     MOV        ESI,dword ptr [DAT_00888498]
    //                              Dsutil.c:1978 (17)
    //         004490ad     MOV        ECX,dword ptr [DAT_00888494]
    //         004490b3     ADD        EAX,ESI
    //         004490b5     CMP        EAX,ECX
    //         004490b7     MOV        [DAT_0088849c],EAX
    //         004490bc     JC         LAB_004490c5
    //                               LAB_004490be                                                 XREF[1]:     00448d76(j)  
    //                              Dsutil.c:1979 (7)
    //         004490be     SUB        EAX,ECX
    //         004490c0     MOV        [DAT_0088849c],EAX
    //                               LAB_004490c5                                                 XREF[11]:    00448bd3(j), 00448be0(j), 
    //                                                                                                         00448c0e(j), 00448c2a(j), 
    //                                                                                                         00448cb7(j), 00448cc4(j), 
    //                                                                                                         00448cf5(j), 00448d70(j), 
    //                                                                                                         00448d82(j), 00448db3(j), 
    //                                                                                                         004490bc(j)  
    //                              Dsutil.c:1740 (6)
    //         004490c5     MOV        dword ptr [DAT_0062e658],EBP
    //                               LAB_004490cb                                                 XREF[2]:     00448baf(j), 00448bbb(j)  
    //                              Dsutil.c:1983 (9)
    //         004490cb     POP        ESI
    //         004490cc     POP        EBP
    //         004490cd     POP        EBX
    //         004490ce     ADD        ESP,0x1c
    //         004490d1     RET        0x14
    //         004490d4     ??         90h
    //         004490d5     NOP
    //         004490d6     NOP
    //         004490d7     NOP
    //         004490d8     NOP
    //         004490d9     NOP
    //         004490da     NOP
    //         004490db     NOP
    //         004490dc     NOP
    //         004490dd     NOP
    //         004490de     NOP
    //         004490df     NOP
    return;
}

DString* DString::operator+(DString* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

char* DString::operator_char*() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DString::length() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DString::index() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DString::contains(DString param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DString::contains(char* param_1) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

int DString::asInt() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

double DString::asDouble() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

DString* DKeyString::key() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

DString* DKeyString::value() {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

