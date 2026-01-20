// Auto-generated scaffold unit: dstring.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/dstring.cpp
#include "../include/common.h"

// Offset: 0x004465D0
undefined DString(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DString::DString(void)                                                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446620
undefined DString(DString* this_, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DString::DString(class DString const &)                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446690
undefined DString(DString* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DString::DString(char const *)                                                     *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446700
void DString(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DString::~DString(void)                                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446710
ostream* operator(ostream* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * class ostream & __cdecl operator<<(class ostream &,class DString const &)                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446730
istream* operator(istream* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * class istream & __cdecl operator>>(class istream &,class DString &)                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446780
DString* operator(DString* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString & __thiscall DString::operator=(char const *)                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446800
DString* operator(DString* this_, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString & __thiscall DString::operator=(class DString const &)                          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446880
int operator(DString* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(class DString const &,class DString const &)                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004468E0
int operator(DString* param_1, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(class DString const &,char const *)                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446930
int operator(char* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(char const *,class DString const &)                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446980
int operator(DString* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(class DString const &,class DString const &)                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004469E0
int operator(DString* param_1, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(class DString const &,char const *)                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446A30
int operator(char* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(char const *,class DString const &)                                            *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446A80
int operator(DString* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator<(class DString const &,class DString const &)                                    *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446AE0
int operator(DString* param_1, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator<(class DString const &,char const *)                                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446B30
int operator(char* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator<(char const *,class DString const &)                                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446B80
int operator(DString* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator>(class DString const &,class DString const &)                                    *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446BE0
int operator(DString* param_1, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator>(class DString const &,char const *)                                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446C30
int operator(char* param_1, DString* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator>(char const *,class DString const &)                                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446C80
DString operator(DString* this_, DString* return_storage_ptr, DString* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::operator+(class DString const &)const                       *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446D10
char* operator(DString* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char & __thiscall DString::operator[](int)                                                    *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446D30
char* operator_char(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DString::operator char *(void)const                                                *
    //                              *********************************************************************************************************
    //                              char * __thiscall operator_char*(DString * this)
    //              char *            EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ??BDString@@QBEPADXZ                                         XREF[1]:     contains:00446d84(c)  
    //                               DString::operator_char*
    //                              dstring.cpp:204 (2)
    //         00446d30     MOV        EAX,dword ptr [this->stringValue]
    //                              dstring.cpp:206 (1)
    //         00446d32     RET
}

// Offset: 0x00446D40
int length(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DString::length(void)const                                                     *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446D50
int index(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DString::index(void)const                                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall index(DString * this)
    //              int               EAX:4          <RETURN>
    //              DString *         ECX:4 (auto)   this
    //                               ?index@DString@@QBEHXZ
    //                               DString::index
    //                              dstring.cpp:212 (3)
    //         00446d50     MOV        EAX,dword ptr [ECX + this->indexValue]
    //                              dstring.cpp:214 (1)
    //         00446d53     RET
}

// Offset: 0x00446D60
int contains(DString* this_, DString param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DString::contains(class DString)const                                          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446DE0
int contains(DString* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DString::contains(char const *)const                                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446E00
int numWords(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DString::numWords(void)                                                        *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446E90
DString word(DString* this_, DString* return_storage_ptr, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::word(int)                                                   *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00446FD0
DString nextWord(DString* this_, DString* return_storage_ptr, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::nextWord(int)                                               *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004470B0
void moveToFirstWord(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DString::moveToFirstWord(void)                                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004470C0
void moveToNextWord(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DString::moveToNextWord(void)                                                 *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447140
DString subString(DString* this_, DString* return_storage_ptr, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::subString(int,int)                                          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004471F0
void append(DString* this_, DString param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DString::append(class DString)                                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004472D0
DString stripTrailing(DString* this_, DString* return_storage_ptr, char param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::stripTrailing(char)                                         *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447370
DString stripLeading(DString* this_, DString* return_storage_ptr, char param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::stripLeading(char)                                          *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447400
int asInt(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall DString::asInt(void)const                                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447410
double asDouble(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: double __thiscall DString::asDouble(void)const                                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447420
void uppercase(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DString::uppercase(void)                                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447460
DString asUppercase(DString* this_, DString* return_storage_ptr) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::asUppercase(void)                                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004474E0
void lowercase(DString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DString::lowercase(void)                                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447520
DString asLowercase(DString* this_, DString* return_storage_ptr) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DString::asLowercase(void)                                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004475A0
void change(DString* this_, char param_2, char param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DString::change(char,char)                                                    *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004475D0
undefined DKeyString(DKeyString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DKeyString::DKeyString(void)                                                       *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447620
undefined DKeyString(DKeyString* this_, DString param_2, DString param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DKeyString::DKeyString(class DString,class DString)                                *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004476A0
void DKeyString(DKeyString* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall DKeyString::~DKeyString(void)                                                      *
    //                              *********************************************************************************************************
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
}

// Offset: 0x004476F0
DString key(DKeyString* this_, DString* return_storage_ptr) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DKeyString::key(void)const                                           *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447710
void setKey(DKeyString* this_, DString param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DKeyString::setKey(class DString)                                             *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447760
DString value(DKeyString* this_, DString* return_storage_ptr) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class DString __thiscall DKeyString::value(void)const                                         *
    //                              *********************************************************************************************************
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
}

// Offset: 0x00447780
void setValue(DKeyString* this_, DString param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall DKeyString::setValue(class DString)                                           *
    //                              *********************************************************************************************************
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
}

