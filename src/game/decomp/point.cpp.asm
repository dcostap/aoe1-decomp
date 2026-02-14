// Auto-generated scaffold unit: point.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/point.cpp
#include "../include/common.h"

// Offset: 0x0047E480
undefined XYZ(XYZ* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall XYZ::XYZ(void)                                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall XYZ(XYZ * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              XYZ *             ECX:4 (auto)   this
    //                               ??0XYZ@@QAE@XZ                                               XREF[1]:     loadPlays:0041120a(c)  
    //                               XYZ::XYZ
    //                              point.cpp:22 (12)
    //         0047e480     MOV        EAX,this
    //         0047e482     XOR        this,this
    //         0047e484     MOV        dword ptr [EAX],this
    //         0047e486     MOV        dword ptr [EAX + 0x4],this
    //         0047e489     MOV        dword ptr [EAX + 0x8],this
    //                              point.cpp:23 (1)
    //         0047e48c     RET
}

// Offset: 0x0047E490
undefined XYZ(XYZ* this_, int param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall XYZ::XYZ(int,int,int)                                                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall XYZ(XYZ * this, int param_1, int param_2, int p
    //              undefined         <UNASSIGNED>   <RETURN>
    //              XYZ *             ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047e496(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0047e490(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0047e49c(R)  
    //                               ??0XYZ@@QAE@HHH@Z                                            XREF[5]:     AIPlayStatus:0040fc4f(c), 
    //                               XYZ::XYZ                                                                  loadPlays:00411201(c), 
    //                                                                                                         loadPlays:0041121f(c), 
    //                                                                                                         operator+:0047e555(c), 
    //                                                                                                         operator-:0047e5a5(c)  
    //                              point.cpp:32 (22)
    //         0047e490     MOV        EDX,dword ptr [ESP + param_2]
    //         0047e494     MOV        EAX,this
    //         0047e496     MOV        this,dword ptr [ESP + param_1]
    //         0047e49a     MOV        dword ptr [EAX],this
    //         0047e49c     MOV        this,dword ptr [ESP + param_3]
    //         0047e4a0     MOV        dword ptr [EAX + 0x4],EDX
    //         0047e4a3     MOV        dword ptr [EAX + 0x8],this
    //                              point.cpp:33 (3)
    //         0047e4a6     RET        0xc
}

// Offset: 0x0047E4B0
int operator(XYZ* param_1, XYZ* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(class XYZ const &,class XYZ const &)                                           *
    //                              *********************************************************************************************************
    //                              int __cdecl operator==(XYZ * param_1, XYZ * param_2)
    //              int               EAX:4          <RETURN>
    //              XYZ *             Stack[0x4]:4   param_1                   XREF[1]:     0047e4b0(R)  
    //              XYZ *             Stack[0x8]:4   param_2                   XREF[1]:     0047e4b4(R)  
    //                               ??8@YAHABVXYZ@@0@Z
    //                               operator==
    //                              point.cpp:38 (37)
    //         0047e4b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0047e4b4     MOV        ECX,dword ptr [ESP + param_2]
    //         0047e4b8     PUSH       ESI
    //         0047e4b9     MOV        EDX,dword ptr [EAX]
    //         0047e4bb     MOV        ESI,dword ptr [ECX]
    //         0047e4bd     CMP        EDX,ESI
    //         0047e4bf     JNZ        LAB_0047e4dc
    //         0047e4c1     MOV        EDX,dword ptr [EAX + 0x4]
    //         0047e4c4     MOV        ESI,dword ptr [ECX + 0x4]
    //         0047e4c7     CMP        EDX,ESI
    //         0047e4c9     JNZ        LAB_0047e4dc
    //         0047e4cb     MOV        EAX,dword ptr [EAX + 0x8]
    //         0047e4ce     MOV        EDX,dword ptr [ECX + 0x8]
    //         0047e4d1     CMP        EAX,EDX
    //         0047e4d3     JNZ        LAB_0047e4dc
    //                              point.cpp:42 (5)
    //         0047e4d5     MOV        EAX,0x1
    //                              point.cpp:44 (2)
    //         0047e4da     POP        ESI
    //         0047e4db     RET
    //                               LAB_0047e4dc                                                 XREF[3]:     0047e4bf(j), 0047e4c9(j), 
    //                                                                                                         0047e4d3(j)  
    //                              point.cpp:43 (2)
    //         0047e4dc     XOR        EAX,EAX
    //                              point.cpp:44 (2)
    //         0047e4de     POP        ESI
    //         0047e4df     RET
}

// Offset: 0x0047E4E0
int operator(XYZ* param_1, XYZ* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(class XYZ const &,class XYZ const &)                                           *
    //                              *********************************************************************************************************
    //                              int __cdecl operator!=(XYZ * param_1, XYZ * param_2)
    //              int               EAX:4          <RETURN>
    //              XYZ *             Stack[0x4]:4   param_1                   XREF[1]:     0047e4e0(R)  
    //              XYZ *             Stack[0x8]:4   param_2                   XREF[1]:     0047e4e4(R)  
    //                               ??9@YAHABVXYZ@@0@Z
    //                               operator!=
    //                              point.cpp:49 (37)
    //         0047e4e0     MOV        EAX,dword ptr [ESP + param_1]
    //         0047e4e4     MOV        ECX,dword ptr [ESP + param_2]
    //         0047e4e8     PUSH       ESI
    //         0047e4e9     MOV        EDX,dword ptr [EAX]
    //         0047e4eb     MOV        ESI,dword ptr [ECX]
    //         0047e4ed     CMP        EDX,ESI
    //         0047e4ef     JNZ        LAB_0047e509
    //         0047e4f1     MOV        EDX,dword ptr [EAX + 0x4]
    //         0047e4f4     MOV        ESI,dword ptr [ECX + 0x4]
    //         0047e4f7     CMP        EDX,ESI
    //         0047e4f9     JNZ        LAB_0047e509
    //         0047e4fb     MOV        EAX,dword ptr [EAX + 0x8]
    //         0047e4fe     MOV        EDX,dword ptr [ECX + 0x8]
    //         0047e501     CMP        EAX,EDX
    //         0047e503     JNZ        LAB_0047e509
    //                              point.cpp:54 (2)
    //         0047e505     XOR        EAX,EAX
    //                              point.cpp:55 (2)
    //         0047e507     POP        ESI
    //         0047e508     RET
    //                               LAB_0047e509                                                 XREF[3]:     0047e4ef(j), 0047e4f9(j), 
    //                                                                                                         0047e503(j)  
    //                              point.cpp:53 (5)
    //         0047e509     MOV        EAX,0x1
    //                              point.cpp:55 (2)
    //         0047e50e     POP        ESI
    //         0047e50f     RET
}

// Offset: 0x0047E510
XYZ* operator(XYZ* this_, XYZ* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class XYZ & __thiscall XYZ::operator=(class XYZ const &)                                      *
    //                              *********************************************************************************************************
    //                              XYZ * __thiscall operator=(XYZ * this, XYZ * param_1)
    //              XYZ *             EAX:4          <RETURN>
    //              XYZ *             ECX:4 (auto)   this
    //              XYZ *             Stack[0x4]:4   param_1                   XREF[1]:     0047e512(R)  
    //                               ??4XYZ@@QAEAAV0@ABV0@@Z
    //                               XYZ::operator=
    //                              point.cpp:60 (2)
    //         0047e510     MOV        EAX,this
    //                              point.cpp:61 (8)
    //         0047e512     MOV        this,dword ptr [ESP + param_1]
    //         0047e516     MOV        EDX,dword ptr [this->xValue]
    //         0047e518     MOV        dword ptr [EAX],EDX
    //                              point.cpp:62 (6)
    //         0047e51a     MOV        EDX,dword ptr [ECX + this->yValue]
    //         0047e51d     MOV        dword ptr [EAX + 0x4],EDX
    //                              point.cpp:63 (6)
    //         0047e520     MOV        this,dword ptr [ECX + this->zValue]
    //         0047e523     MOV        dword ptr [EAX + 0x8],this
    //                              point.cpp:65 (3)
    //         0047e526     RET        0x4
}

// Offset: 0x0047E530
XYZ operator(XYZ* this_, XYZ* return_storage_ptr, XYZ* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class XYZ __thiscall XYZ::operator+(class XYZ const &)const                                   *
    //                              *********************************************************************************************************
    //                              XYZ __thiscall operator+(XYZ * this, XYZ * __return_storage_ptr__, X
    //              XYZ               EAX:4 (ptr)    <RETURN>
    //              XYZ *             ECX:4 (auto)   this
    //              XYZ *             Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0047e55a(R)  
    //              XYZ *             Stack[0x8]:4   param_1                   XREF[1]:     0047e530(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0047e56e(R)  
    //              XYZ               Stack[-0x10]   newP                      XREF[0,3]:   0047e551(*), 0047e55e(R), 0047e567(R)  
    //                               ??HXYZ@@QBE?AV0@ABV0@@Z
    //                               XYZ::operator+
    //                              point.cpp:70 (42)
    //         0047e530     MOV        EAX,dword ptr [ESP + param_1]
    //         0047e534     SUB        ESP,0xc
    //         0047e537     MOV        EDX,dword ptr [EAX + 0x8]
    //         0047e53a     PUSH       ESI
    //         0047e53b     MOV        ESI,dword ptr [ECX + this->zValue]
    //         0047e53e     ADD        EDX,ESI
    //         0047e540     MOV        ESI,dword ptr [EAX + 0x4]
    //         0047e543     PUSH       EDX
    //         0047e544     MOV        EDX,dword ptr [ECX + this->yValue]
    //         0047e547     MOV        this,dword ptr [this->xValue]
    //         0047e549     ADD        EDX,ESI
    //         0047e54b     PUSH       EDX
    //         0047e54c     MOV        EDX,dword ptr [EAX]
    //         0047e54e     ADD        this,EDX
    //         0047e550     PUSH       this
    //         0047e551     LEA        this=>newP.yValue,[ESP + 0x10]
    //         0047e555     CALL       XYZ::XYZ                                         undefined XYZ(XYZ * this, int param_1, int pa
    //                              point.cpp:72 (10)
    //         0047e55a     MOV        EAX,dword ptr [ESP + __return_storage_ptr__]
    //         0047e55e     MOV        this,dword ptr [ESP + newP.yValue]
    //         0047e562     MOV        EDX,EAX
    //                              point.cpp:73 (23)
    //         0047e564     POP        ESI
    //         0047e565     MOV        dword ptr [EDX],this
    //         0047e567     MOV        this,dword ptr [ESP + newP.zValue]
    //         0047e56b     MOV        dword ptr [EDX + 0x4],this
    //         0047e56e     MOV        this,dword ptr [ESP + local_4]
    //         0047e572     MOV        dword ptr [EDX + 0x8],this
    //         0047e575     ADD        ESP,0xc
    //         0047e578     RET        0x8
}

// Offset: 0x0047E580
XYZ operator(XYZ* this_, XYZ* return_storage_ptr, XYZ* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class XYZ __thiscall XYZ::operator-(class XYZ const &)const                                   *
    //                              *********************************************************************************************************
    //                              XYZ __thiscall operator-(XYZ * this, XYZ * __return_storage_ptr__, X
    //              XYZ               EAX:4 (ptr)    <RETURN>
    //              XYZ *             ECX:4 (auto)   this
    //              XYZ *             Stack[0x4]:4   __return_storage_ptr__    XREF[1]:     0047e5aa(R)  
    //              XYZ *             Stack[0x8]:4   param_1                   XREF[1]:     0047e580(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0047e5be(R)  
    //              XYZ               Stack[-0x10]   newP                      XREF[0,3]:   0047e5a1(*), 0047e5ae(R), 0047e5b7(R)  
    //                               ??GXYZ@@QBE?AV0@ABV0@@Z
    //                               XYZ::operator-
    //                              point.cpp:78 (42)
    //         0047e580     MOV        EAX,dword ptr [ESP + param_1]
    //         0047e584     MOV        EDX,dword ptr [ECX + this->zValue]
    //         0047e587     SUB        ESP,0xc
    //         0047e58a     PUSH       ESI
    //         0047e58b     MOV        ESI,dword ptr [EAX + 0x8]
    //         0047e58e     SUB        EDX,ESI
    //         0047e590     MOV        ESI,dword ptr [EAX + 0x4]
    //         0047e593     PUSH       EDX
    //         0047e594     MOV        EDX,dword ptr [ECX + this->yValue]
    //         0047e597     MOV        this,dword ptr [this->xValue]
    //         0047e599     SUB        EDX,ESI
    //         0047e59b     PUSH       EDX
    //         0047e59c     MOV        EDX,dword ptr [EAX]
    //         0047e59e     SUB        this,EDX
    //         0047e5a0     PUSH       this
    //         0047e5a1     LEA        this=>newP.yValue,[ESP + 0x10]
    //         0047e5a5     CALL       XYZ::XYZ                                         undefined XYZ(XYZ * this, int param_1, int pa
    //                              point.cpp:80 (10)
    //         0047e5aa     MOV        EAX,dword ptr [ESP + __return_storage_ptr__]
    //         0047e5ae     MOV        this,dword ptr [ESP + newP.yValue]
    //         0047e5b2     MOV        EDX,EAX
    //                              point.cpp:81 (23)
    //         0047e5b4     POP        ESI
    //         0047e5b5     MOV        dword ptr [EDX],this
    //         0047e5b7     MOV        this,dword ptr [ESP + newP.zValue]
    //         0047e5bb     MOV        dword ptr [EDX + 0x4],this
    //         0047e5be     MOV        this,dword ptr [ESP + local_4]
    //         0047e5c2     MOV        dword ptr [EDX + 0x8],this
    //         0047e5c5     ADD        ESP,0xc
    //         0047e5c8     RET        0x8
}

// Offset: 0x0047E5D0
void rotateXYByFacet(XYZ* this_, XYZ* param_2, XYZ* param_3, uchar param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall XYZ::rotateXYByFacet(class XYZ const &,class XYZ &,unsigned char)             *
    //                              *********************************************************************************************************
    //                              void __thiscall rotateXYByFacet(XYZ * this, XYZ * param_1, XYZ * par
    //              void              <VOID>         <RETURN>
    //              XYZ *             ECX:4 (auto)   this
    //              XYZ *             Stack[0x4]:4   param_1                   XREF[1]:     0047e5f8(R)  
    //              XYZ *             Stack[0x8]:4   param_2                   XREF[9]:     0047e5d3(R), 0047e5f4(W), 0047e5fc(R), 0047e60b(W), 
    //                                                                                     0047e611(R), 0047e61d(W), 0047e621(R), 0047e627(W), 
    //                                                                                     0047e62b(R)  
    //              uchar             Stack[0xc]:1   param_3                   XREF[1]:     0047e5e5(R)  
    //                               ?rotateXYByFacet@XYZ@@QAEXABV1@AAV1@E@Z                      XREF[1]:     loadPlays:00411237(c)  
    //                               XYZ::rotateXYByFacet
    //                              point.cpp:86 (9)
    //         0047e5d0     MOV        EAX,dword ptr [this->xValue]
    //         0047e5d2     PUSH       ESI
    //         0047e5d3     MOV        ESI,dword ptr [ESP + param_2]
    //         0047e5d7     MOV        dword ptr [ESI],EAX
    //                              point.cpp:90 (6)
    //         0047e5d9     MOV        EDX,dword ptr [ECX + this->yValue]
    //         0047e5dc     MOV        dword ptr [ESI + 0x4],EDX
    //                              point.cpp:91 (6)
    //         0047e5df     MOV        EAX,dword ptr [ECX + this->zValue]
    //         0047e5e2     MOV        dword ptr [ESI + 0x8],EAX
    //                              point.cpp:93 (8)
    //         0047e5e5     MOV        EAX,dword ptr [ESP + param_3]
    //         0047e5e9     TEST       AL,AL
    //         0047e5eb     JZ         LAB_0047e65f
    //                              point.cpp:101 (7)
    //         0047e5ed     MOV        EDX,dword ptr [this->xValue]
    //         0047e5ef     AND        EAX,0xff
    //                              point.cpp:102 (29)
    //         0047e5f4     MOV        dword ptr [ESP + param_2],EAX
    //         0047e5f8     MOV        EAX,dword ptr [ESP + param_1]
    //         0047e5fc     FILD       dword ptr [ESP + param_2]
    //         0047e600     MOV        this,dword ptr [ECX + this->yValue]
    //         0047e603     PUSH       EDI
    //         0047e604     MOV        EDI,dword ptr [EAX]
    //         0047e606     SUB        EDX,EDI
    //         0047e608     MOV        EDI,dword ptr [EAX + 0x4]
    //         0047e60b     MOV        dword ptr [ESP + param_2],EDX
    //         0047e60f     SUB        this,EDI
    //                              point.cpp:107 (55)
    //         0047e611     FILD       dword ptr [ESP + param_2]
    //         0047e615     FXCH
    //         0047e617     FMUL       float ptr [DAT_00571ce8]                         = DBh
    //         0047e61d     MOV        dword ptr [ESP + param_2],this
    //         0047e621     FILD       dword ptr [ESP + param_2]
    //         0047e625     FXCH
    //         0047e627     FST        float ptr [ESP + param_2]
    //         0047e62b     FLD        float ptr [ESP + param_2]
    //         0047e62f     FXCH
    //         0047e631     FSIN
    //         0047e633     FXCH
    //         0047e635     FCOS
    //         0047e637     FLD        ST1
    //         0047e639     FLD        ST1
    //         0047e63b     FMUL       ST5
    //         0047e63d     FXCH
    //         0047e63f     FMUL       ST4
    //         0047e641     FSUBP
    //         0047e643     CALL       __ftol                                           undefined __ftol()
    //                              point.cpp:108 (23)
    //         0047e648     FMUL       ST2
    //         0047e64a     FXCH
    //         0047e64c     FMUL       ST3
    //         0047e64e     MOV        dword ptr [ESI],EAX
    //         0047e650     FADDP
    //         0047e652     CALL       __ftol                                           undefined __ftol()
    //         0047e657     FSTP       ST0
    //         0047e659     FSTP       ST0
    //         0047e65b     MOV        dword ptr [ESI + 0x4],EAX
    //         0047e65e     POP        EDI
    //                               LAB_0047e65f                                                 XREF[1]:     0047e5eb(j)  
    //                              point.cpp:109 (4)
    //         0047e65f     POP        ESI
    //         0047e660     RET        0xc
}

