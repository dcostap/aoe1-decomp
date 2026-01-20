// Auto-generated scaffold unit: bucket_055B.cpp.asm
#include "../include/common.h"

// Offset: 0x0055B110
undefined ios(ios* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: __thiscall ios::ios(void)                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ios(ios * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ios *             ECX:4 (auto)   this
    //                               ??0ios@@IAE@XZ                                               XREF[12]:    ostream:0055a8ad(c), 
    //                               ios::ios                                                                  ostream:0055a938(c), 
    //                                                                                                         ostream:0055a9c8(c), 
    //                                                                                                         operator=:0055aa79(c), 
    //                                                                                                         ostream_withassign:0055ab18(c), 
    //                                                                                                         ostream_withassign:0055abc8(c), 
    //                                                                                                         istream:0055b46d(c), 
    //                                                                                                         istream:0055b517(c), 
    //                                                                                                         istream:0055b5b7(c), 
    //                                                                                                         operator=:0055b678(c), 
    //                                                                                                         istream_withassign:0055b9c8(c), 
    //                                                                                                         istream_withassign:0055ba78(c)  
    //         0055b110     MOV        EAX,this
    //         0055b112     XOR        this,this
    //         0055b114     MOV        dword ptr [EAX],ios::`vftable'                   = 0055b150
    //         0055b11a     MOV        dword ptr [EAX + 0x4],this
    //         0055b11d     MOV        dword ptr [EAX + 0x8],0x4
    //         0055b124     MOV        dword ptr [EAX + 0xc],this
    //         0055b127     MOV        dword ptr [EAX + 0x10],this
    //         0055b12a     MOV        dword ptr [EAX + 0x20],this
    //         0055b12d     MOV        dword ptr [EAX + 0x24],this
    //         0055b130     MOV        dword ptr [EAX + 0x28],0x6
    //         0055b137     MOV        byte ptr [EAX + 0x2c],0x20
    //         0055b13b     MOV        dword ptr [EAX + 0x30],this
    //         0055b13e     MOV        dword ptr [EAX + 0x1c],this
    //         0055b141     RET
}

// Offset: 0x0055B170
undefined ios(ios* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall ios::ios(class streambuf *)                                                        *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ios(ios * this, streambuf * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ios *             ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1                   XREF[1]:     0055b172(R)  
    //                               ??0ios@@QAE@PAVstreambuf@@@Z
    //                               ios::ios
    //         0055b170     MOV        EAX,this
    //         0055b172     MOV        this,dword ptr [ESP + param_1]
    //         0055b176     MOV        dword ptr [EAX + 0x4],this
    //         0055b179     MOV        dword ptr [EAX],ios::`vftable'                   = 0055b150
    //         0055b17f     NEG        this
    //         0055b181     SBB        this,this
    //         0055b183     MOV        dword ptr [EAX + 0x28],0x6
    //         0055b18a     AND        this,0xfffffffc
    //         0055b18d     MOV        byte ptr [EAX + 0x2c],0x20
    //         0055b191     ADD        this,0x4
    //         0055b194     MOV        dword ptr [EAX + 0x8],this
    //         0055b197     XOR        this,this
    //         0055b199     MOV        dword ptr [EAX + 0xc],this
    //         0055b19c     MOV        dword ptr [EAX + 0x10],this
    //         0055b19f     MOV        dword ptr [EAX + 0x20],this
    //         0055b1a2     MOV        dword ptr [EAX + 0x24],this
    //         0055b1a5     MOV        dword ptr [EAX + 0x30],this
    //         0055b1a8     MOV        dword ptr [EAX + 0x1c],this
    //         0055b1ab     RET        0x4
}

// Offset: 0x0055B1B0
undefined ios(ios* this_, ios* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: __thiscall ios::ios(class ios const &)                                                     *
    //                              *********************************************************************************************************
    //                              undefined __thiscall ios(ios * this, ios * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              ios *             ECX:4 (auto)   this
    //              ios *             Stack[0x4]:4   param_1                   XREF[1]:     0055b1bb(R)  
    //                               ??0ios@@IAE@ABV0@@Z
    //                               ios::ios
    //         0055b1b0     PUSH       ESI
    //         0055b1b1     MOV        ESI,this
    //         0055b1b3     XOR        EAX,EAX
    //         0055b1b5     MOV        dword ptr [ESI + 0x4],EAX
    //         0055b1b8     MOV        dword ptr [ESI + 0x1c],EAX
    //         0055b1bb     MOV        EAX,dword ptr [ESP + param_1]
    //         0055b1bf     MOV        dword ptr [ESI],ios::`vftable'                   = 0055b150
    //         0055b1c5     PUSH       EAX
    //         0055b1c6     CALL       ios::operator=                                   ios * operator=(ios * this, ios * param_1)
    //         0055b1cb     MOV        EAX,ESI
    //         0055b1cd     POP        ESI
    //         0055b1ce     RET        0x4
}

// Offset: 0x0055B1E0
void ios(ios* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall ios::~ios(void)                                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~ios(ios * this)
    //              void              <VOID>         <RETURN>
    //              ios *             ECX:4 (auto)   this
    //                               ??1ios@@UAE@XZ                                               XREF[11]:    `scalar_deleting_destructor':0055a
    //                               ios::~ios                                                                 operator=:0055aa9f(c), 
    //                                                                                                         `vector_deleting_destructor':0055a
    //                                                                                                         `vector_deleting_destructor':0055b
    //                                                                                                         `scalar_deleting_destructor':0055b
    //                                                                                                         operator=:0055b69a(c), 
    //                                                                                                         `vector_deleting_destructor':0055b
    //                                                                                                         FUN_00561f00:00561f14(c), 
    //                                                                                                         FUN_00561f70:00561f80(c), 
    //                                                                                                         FUN_00561f90:00561fa4(c), 
    //                                                                                                         FUN_00562030:00562040(c)  
    //         0055b1e0     PUSH       ESI
    //         0055b1e1     MOV        ESI,this
    //         0055b1e3     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0055b1e6     MOV        dword ptr [ESI],ios::`vftable'                   = 0055b150
    //         0055b1ec     TEST       EAX,EAX
    //         0055b1ee     JZ         LAB_0055b1fd
    //         0055b1f0     MOV        this,dword ptr [ESI + 0x4]
    //         0055b1f3     TEST       this,this
    //         0055b1f5     JZ         LAB_0055b1fd
    //         0055b1f7     MOV        EAX,dword ptr [this->_padding_]
    //         0055b1f9     PUSH       0x1
    //         0055b1fb     CALL       dword ptr [EAX]
    //                               LAB_0055b1fd                                                 XREF[2]:     0055b1ee(j), 0055b1f5(j)  
    //         0055b1fd     MOV        dword ptr [ESI + 0x4],0x0
    //         0055b204     MOV        dword ptr [ESI + 0x8],0x4
    //         0055b20b     POP        ESI
    //         0055b20c     RET
}

// Offset: 0x0055B210
void init(ios* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall ios::init(class streambuf *)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall init(ios * this, streambuf * param_1)
    //              void              <VOID>         <RETURN>
    //              ios *             ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1                   XREF[1]:     0055b227(R)  
    //                               ?init@ios@@IAEXPAVstreambuf@@@Z                              XREF[6]:     ostream:0055a965(c), 
    //                               ios::init                                                                 ostream:0055a9fe(c), 
    //                                                                                                         operator=:0055aabd(c), 
    //                                                                                                         istream:0055b540(c), 
    //                                                                                                         istream:0055b5e9(c), 
    //                                                                                                         operator=:0055b6b4(c)  
    //         0055b210     PUSH       ESI
    //         0055b211     MOV        ESI,this
    //         0055b213     MOV        EAX,dword ptr [ESI + 0x1c]
    //         0055b216     TEST       EAX,EAX
    //         0055b218     JZ         LAB_0055b227
    //         0055b21a     MOV        this,dword ptr [ESI + 0x4]
    //         0055b21d     TEST       this,this
    //         0055b21f     JZ         LAB_0055b227
    //         0055b221     MOV        EAX,dword ptr [this->_padding_]
    //         0055b223     PUSH       0x1
    //         0055b225     CALL       dword ptr [EAX]
    //                               LAB_0055b227                                                 XREF[2]:     0055b218(j), 0055b21f(j)  
    //         0055b227     MOV        EAX,dword ptr [ESP + param_1]
    //         0055b22b     MOV        dword ptr [ESI + 0x4],EAX
    //         0055b22e     TEST       EAX,EAX
    //         0055b230     MOV        EAX,dword ptr [ESI + 0x8]
    //         0055b233     JZ         LAB_0055b23e
    //         0055b235     AND        AL,0xfb
    //         0055b237     MOV        dword ptr [ESI + 0x8],EAX
    //         0055b23a     POP        ESI
    //         0055b23b     RET        0x4
    //                               LAB_0055b23e                                                 XREF[1]:     0055b233(j)  
    //         0055b23e     OR         AL,0x4
    //         0055b240     MOV        dword ptr [ESI + 0x8],EAX
    //         0055b243     POP        ESI
    //         0055b244     RET        0x4
}

// Offset: 0x0055B250
ios* operator(ios* this_, ios* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class ios & __thiscall ios::operator=(class ios const &)                                   *
    //                              *********************************************************************************************************
    //                              ios * __thiscall operator=(ios * this, ios * param_1)
    //              ios *             EAX:4          <RETURN>
    //              ios *             ECX:4 (auto)   this
    //              ios *             Stack[0x4]:4   param_1                   XREF[1]:     0055b252(R)  
    //                               ??4ios@@IAEAAV0@ABV0@@Z                                      XREF[3]:     operator=:0055aa8e(c), 
    //                               ios::operator=                                                            ios:0055b1c6(c), 
    //                                                                                                         operator=:0055b689(c)  
    //         0055b250     MOV        EAX,this
    //         0055b252     MOV        this,dword ptr [ESP + param_1]
    //         0055b256     MOV        EDX,dword ptr [ECX + this->x_tie]
    //         0055b259     MOV        dword ptr [EAX + 0x20],EDX
    //         0055b25c     MOV        EDX,dword ptr [ECX + this->x_flags]
    //         0055b25f     MOV        dword ptr [EAX + 0x24],EDX
    //         0055b262     MOVSX      EDX,byte ptr [ECX + this->x_precision]
    //         0055b266     MOV        dword ptr [EAX + 0x28],EDX
    //         0055b269     MOV        DL,byte ptr [ECX + this->x_fill]
    //         0055b26c     MOV        byte ptr [EAX + 0x2c],DL
    //         0055b26f     MOVSX      EDX,byte ptr [ECX + this->x_width]
    //         0055b273     MOV        dword ptr [EAX + 0x30],EDX
    //         0055b276     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055b279     MOV        this,dword ptr [ECX + this->state]
    //         0055b27c     TEST       EDX,EDX
    //         0055b27e     MOV        dword ptr [EAX + 0x8],this
    //         0055b281     JNZ        LAB_0055b289
    //         0055b283     OR         this,0x4
    //         0055b286     MOV        dword ptr [EAX + 0x8],this
    //                               LAB_0055b289                                                 XREF[1]:     0055b281(j)  
    //         0055b289     RET        0x4
}

// Offset: 0x0055B290
int xalloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: static int __cdecl ios::xalloc(void)                                                          *
    //                              *********************************************************************************************************
    //                              int __cdecl xalloc(void)
    //              int               EAX:4          <RETURN>
    //                               ?xalloc@ios@@SAHXZ
    //                               ios::xalloc
    //         0055b290     MOV        EAX,[ios::x_curindex]                            = FFFFFFFFh
    //         0055b295     PUSH       ESI
    //         0055b296     LEA        ECX,[EAX*0x4 + 0x8]
    //         0055b29d     PUSH       ECX
    //         0055b29e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0055b2a3     MOV        ESI,EAX
    //         0055b2a5     ADD        ESP,0x4
    //         0055b2a8     TEST       ESI,ESI
    //         0055b2aa     JNZ        LAB_0055b2b1
    //         0055b2ac     OR         EAX,0xffffffff
    //         0055b2af     POP        ESI
    //         0055b2b0     RET
    //                               LAB_0055b2b1                                                 XREF[1]:     0055b2aa(j)  
    //         0055b2b1     MOV        ECX,dword ptr [ios::x_curindex]                  = FFFFFFFFh
    //         0055b2b7     XOR        EAX,EAX
    //         0055b2b9     TEST       ECX,ECX
    //         0055b2bb     JL         LAB_0055b2d6
    //                               LAB_0055b2bd                                                 XREF[1]:     0055b2d4(j)  
    //         0055b2bd     MOV        EDX,dword ptr [ios::x_statebuf]                  = 00000000
    //         0055b2c3     INC        EAX
    //         0055b2c4     MOV        ECX,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0055b2c8     MOV        dword ptr [ESI + EAX*0x4 + -0x4],ECX
    //         0055b2cc     MOV        ECX,dword ptr [ios::x_curindex]                  = FFFFFFFFh
    //         0055b2d2     CMP        EAX,ECX
    //         0055b2d4     JLE        LAB_0055b2bd
    //                               LAB_0055b2d6                                                 XREF[1]:     0055b2bb(j)  
    //         0055b2d6     INC        ECX
    //         0055b2d7     MOV        dword ptr [ios::x_curindex],ECX                  = FFFFFFFFh
    //         0055b2dd     MOV        dword ptr [ESI + ECX*0x4],0x0
    //         0055b2e4     MOV        EAX,[ios::x_statebuf]                            = 00000000
    //         0055b2e9     TEST       EAX,EAX
    //         0055b2eb     JZ         LAB_0055b2f6
    //         0055b2ed     PUSH       EAX
    //         0055b2ee     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0055b2f3     ADD        ESP,0x4
    //                               LAB_0055b2f6                                                 XREF[1]:     0055b2eb(j)  
    //         0055b2f6     MOV        EAX,[ios::x_curindex]                            = FFFFFFFFh
    //         0055b2fb     MOV        dword ptr [ios::x_statebuf],ESI                  = 00000000
    //         0055b301     POP        ESI
    //         0055b302     RET
}

// Offset: 0x0055B310
long bitalloc() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: static long __cdecl ios::bitalloc(void)                                                       *
    //                              *********************************************************************************************************
    //                              long __cdecl bitalloc(void)
    //              long              EAX:4          <RETURN>
    //                               ?bitalloc@ios@@SAJXZ
    //                               ios::bitalloc
    //         0055b310     MOV        EAX,[ios::x_maxbit]                              = 8000h
    //         0055b315     SHL        EAX,0x1
    //         0055b317     MOV        [ios::x_maxbit],EAX                              = 8000h
    //         0055b31c     RET
}

// Offset: 0x0055B320
int snextc(streambuf* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall streambuf::snextc(void)                                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall snextc(streambuf * this)
    //              int               EAX:4          <RETURN>
    //              streambuf *       ECX:4 (auto)   this
    //                               ?snextc@streambuf@@QAEHXZ                                    XREF[1]:     eatwhite:0055b96c(c)  
    //                               streambuf::snextc
    //         0055b320     PUSH       ESI
    //         0055b321     MOV        ESI,this
    //         0055b323     MOV        EAX,dword ptr [ESI + 0x8]
    //         0055b326     TEST       EAX,EAX
    //         0055b328     JZ         LAB_0055b341
    //         0055b32a     CMP        dword ptr [ESI + 0xc],-0x1
    //         0055b32e     JNZ        LAB_0055b335
    //         0055b330     MOV        EAX,dword ptr [ESI]
    //         0055b332     CALL       dword ptr [EAX + 0x20]
    //                               LAB_0055b335                                                 XREF[1]:     0055b32e(j)  
    //         0055b335     MOV        EDX,dword ptr [ESI]
    //         0055b337     MOV        this,ESI
    //         0055b339     CALL       dword ptr [EDX + 0x20]
    //         0055b33c     MOV        dword ptr [ESI + 0xc],EAX
    //         0055b33f     POP        ESI
    //         0055b340     RET
    //                               LAB_0055b341                                                 XREF[1]:     0055b328(j)  
    //         0055b341     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0055b344     TEST       EAX,EAX
    //         0055b346     JZ         LAB_0055b34d
    //         0055b348     CMP        dword ptr [ESI + 0x28],EAX
    //         0055b34b     JC         LAB_0055b354
    //                               LAB_0055b34d                                                 XREF[1]:     0055b346(j)  
    //         0055b34d     MOV        EAX,dword ptr [ESI]
    //         0055b34f     MOV        this,ESI
    //         0055b351     CALL       dword ptr [EAX + 0x20]
    //                               LAB_0055b354                                                 XREF[1]:     0055b34b(j)  
    //         0055b354     MOV        EDX,dword ptr [ESI + 0x28]
    //         0055b357     MOV        this,dword ptr [ESI + 0x2c]
    //         0055b35a     INC        EDX
    //         0055b35b     MOV        EAX,EDX
    //         0055b35d     MOV        dword ptr [ESI + 0x28],EDX
    //         0055b360     CMP        EAX,this
    //         0055b362     JNC        LAB_0055b36c
    //         0055b364     XOR        this,this
    //         0055b366     MOV        this,byte ptr [EAX]
    //         0055b368     MOV        EAX,this
    //         0055b36a     POP        ESI
    //         0055b36b     RET
    //                               LAB_0055b36c                                                 XREF[1]:     0055b362(j)  
    //         0055b36c     MOV        EDX,dword ptr [ESI]
    //         0055b36e     MOV        this,ESI
    //         0055b370     CALL       dword ptr [EDX + 0x20]
    //         0055b373     POP        ESI
    //         0055b374     RET
}

// Offset: 0x0055B380
int sbumpc(streambuf* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall streambuf::sbumpc(void)                                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall sbumpc(streambuf * this)
    //              int               EAX:4          <RETURN>
    //              streambuf *       ECX:4 (auto)   this
    //                               ?sbumpc@streambuf@@QAEHXZ
    //                               streambuf::sbumpc
    //         0055b380     PUSH       ESI
    //         0055b381     MOV        ESI,this
    //         0055b383     MOV        EAX,dword ptr [ESI + 0x8]
    //         0055b386     TEST       EAX,EAX
    //         0055b388     JZ         LAB_0055b3a2
    //         0055b38a     MOV        EAX,dword ptr [ESI + 0xc]
    //         0055b38d     CMP        EAX,-0x1
    //         0055b390     JNZ        LAB_0055b399
    //         0055b392     MOV        EAX,dword ptr [ESI]
    //         0055b394     CALL       dword ptr [EAX + 0x20]
    //         0055b397     POP        ESI
    //         0055b398     RET
    //                               LAB_0055b399                                                 XREF[1]:     0055b390(j)  
    //         0055b399     MOV        dword ptr [ESI + 0xc],0xffffffff
    //         0055b3a0     POP        ESI
    //         0055b3a1     RET
    //                               LAB_0055b3a2                                                 XREF[1]:     0055b388(j)  
    //         0055b3a2     MOV        EAX,dword ptr [ESI + 0x28]
    //         0055b3a5     MOV        this,dword ptr [ESI + 0x2c]
    //         0055b3a8     CMP        EAX,this
    //         0055b3aa     JNC        LAB_0055b3bb
    //         0055b3ac     XOR        this,this
    //         0055b3ae     MOV        this,byte ptr [EAX]
    //         0055b3b0     MOV        EAX,this
    //         0055b3b2     MOV        this,dword ptr [ESI + 0x28]
    //         0055b3b5     INC        this
    //         0055b3b6     MOV        dword ptr [ESI + 0x28],this
    //         0055b3b9     POP        ESI
    //         0055b3ba     RET
    //                               LAB_0055b3bb                                                 XREF[1]:     0055b3aa(j)  
    //         0055b3bb     MOV        EDX,dword ptr [ESI]
    //         0055b3bd     MOV        this,ESI
    //         0055b3bf     CALL       dword ptr [EDX + 0x20]
    //         0055b3c2     MOV        this,dword ptr [ESI + 0x28]
    //         0055b3c5     INC        this
    //         0055b3c6     MOV        dword ptr [ESI + 0x28],this
    //         0055b3c9     POP        ESI
    //         0055b3ca     RET
}

// Offset: 0x0055B3D0
void stossc(streambuf* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall streambuf::stossc(void)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall stossc(streambuf * this)
    //              void              <VOID>         <RETURN>
    //              streambuf *       ECX:4 (auto)   this
    //                               ?stossc@streambuf@@QAEXXZ                                    XREF[3]:     get:0055ae87(c), get:0055aed4(c), 
    //                               streambuf::stossc                                                         operator>>:0055b814(c)  
    //         0055b3d0     PUSH       ESI
    //         0055b3d1     MOV        ESI,this
    //         0055b3d3     MOV        EAX,dword ptr [ESI + 0x8]
    //         0055b3d6     TEST       EAX,EAX
    //         0055b3d8     JZ         LAB_0055b3f2
    //         0055b3da     MOV        this,dword ptr [ESI + 0xc]
    //         0055b3dd     OR         EAX,0xffffffff
    //         0055b3e0     CMP        this,EAX
    //         0055b3e2     JNZ        LAB_0055b3ed
    //         0055b3e4     MOV        EAX,dword ptr [ESI]
    //         0055b3e6     MOV        this,ESI
    //         0055b3e8     CALL       dword ptr [EAX + 0x20]
    //         0055b3eb     POP        ESI
    //         0055b3ec     RET
    //                               LAB_0055b3ed                                                 XREF[1]:     0055b3e2(j)  
    //         0055b3ed     MOV        dword ptr [ESI + 0xc],EAX
    //         0055b3f0     POP        ESI
    //         0055b3f1     RET
    //                               LAB_0055b3f2                                                 XREF[1]:     0055b3d8(j)  
    //         0055b3f2     MOV        this,dword ptr [ESI + 0x28]
    //         0055b3f5     MOV        EAX,dword ptr [ESI + 0x2c]
    //         0055b3f8     CMP        this,EAX
    //         0055b3fa     JC         LAB_0055b403
    //         0055b3fc     MOV        EDX,dword ptr [ESI]
    //         0055b3fe     MOV        this,ESI
    //         0055b400     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0055b403                                                 XREF[1]:     0055b3fa(j)  
    //         0055b403     MOV        EAX,dword ptr [ESI + 0x28]
    //         0055b406     MOV        this,dword ptr [ESI + 0x2c]
    //         0055b409     CMP        EAX,this
    //         0055b40b     JNC        LAB_0055b411
    //         0055b40d     INC        EAX
    //         0055b40e     MOV        dword ptr [ESI + 0x28],EAX
    //                               LAB_0055b411                                                 XREF[1]:     0055b40b(j)  
    //         0055b411     POP        ESI
    //         0055b412     RET
}

// Offset: 0x0055B420
int sgetc(streambuf* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall streambuf::sgetc(void)                                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall sgetc(streambuf * this)
    //              int               EAX:4          <RETURN>
    //              streambuf *       ECX:4 (auto)   this
    //                               ?sgetc@streambuf@@QAEHXZ                                     XREF[4]:     get:0055ae67(c), 
    //                               streambuf::sgetc                                                          operator>>:0055b7eb(c), 
    //                                                                                                         peek:0055b897(c), 
    //                                                                                                         eatwhite:0055b94c(c)  
    //         0055b420     PUSH       ESI
    //         0055b421     MOV        ESI,this
    //         0055b423     MOV        EAX,dword ptr [ESI + 0x8]
    //         0055b426     TEST       EAX,EAX
    //         0055b428     JZ         LAB_0055b43d
    //         0055b42a     CMP        dword ptr [ESI + 0xc],-0x1
    //         0055b42e     JNZ        LAB_0055b438
    //         0055b430     MOV        EAX,dword ptr [ESI]
    //         0055b432     CALL       dword ptr [EAX + 0x20]
    //         0055b435     MOV        dword ptr [ESI + 0xc],EAX
    //                               LAB_0055b438                                                 XREF[1]:     0055b42e(j)  
    //         0055b438     MOV        EAX,dword ptr [ESI + 0xc]
    //         0055b43b     POP        ESI
    //         0055b43c     RET
    //                               LAB_0055b43d                                                 XREF[1]:     0055b428(j)  
    //         0055b43d     MOV        EDX,dword ptr [ESI]
    //         0055b43f     MOV        this,ESI
    //         0055b441     CALL       dword ptr [EDX + 0x20]
    //         0055b444     POP        ESI
    //         0055b445     RET
}

// Offset: 0x0055B450
undefined istream(istream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: __thiscall istream::istream(void)                                                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall istream(istream * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055b45a(W)  
    //                               ??0istream@@IAE@XZ                                           XREF[1]:     istream_withassign:0055b9e1(c)  
    //                               istream::istream
    //         0055b450     PUSH       this
    //         0055b451     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055b455     PUSH       ESI
    //         0055b456     TEST       EAX,EAX
    //         0055b458     MOV        ESI,this
    //         0055b45a     MOV        dword ptr [ESP + local_4],0x0
    //         0055b462     JZ         LAB_0055b472
    //         0055b464     LEA        this,[ESI + 0xc]
    //         0055b467     MOV        dword ptr [ESI],istream::`vbtable'
    //         0055b46d     CALL       ios::ios                                         undefined ios(ios * this)
    //                               LAB_0055b472                                                 XREF[1]:     0055b462(j)  
    //         0055b472     MOV        EAX,dword ptr [ESI]
    //         0055b474     MOV        this,dword ptr [EAX + 0x4]=>DAT_00578084         = 0000000Ch
    //         0055b477     MOV        dword ptr [this->field0_0x0 + ESI*0x1],istream   = 0055b4b0
    //         0055b47e     MOV        EDX,dword ptr [ESI]
    //         0055b480     MOV        EAX,dword ptr [EDX + 0x4]=>DAT_00578084          = 0000000Ch
    //         0055b483     MOV        this,dword ptr [EAX + ESI*0x1 + 0x24]
    //         0055b487     LEA        EAX,[EAX + ESI*0x1 + 0x24]
    //         0055b48b     OR         this,0x1
    //         0055b48e     MOV        dword ptr [EAX],this
    //         0055b490     MOV        dword ptr [ESI + 0x8],0x0
    //         0055b497     MOV        dword ptr [ESI + 0x4],0x0
    //         0055b49e     MOV        EAX,ESI
    //         0055b4a0     POP        ESI
    //         0055b4a1     POP        this
    //         0055b4a2     RET        0x4
}

// Offset: 0x0055B4E0
undefined istream(istream* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall istream::istream(class streambuf *)                                                *
    //                              *********************************************************************************************************
    //                              undefined __thiscall istream(istream * this, streambuf * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1                   XREF[1]:     0055b52a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055b524(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0055b557(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0055b504(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055b508(W), 0055b51c(W)  
    //                               ??0istream@@QAE@PAVstreambuf@@@Z                             XREF[1]:     istream_withassign:0055ba96(c)  
    //                               istream::istream
    //         0055b4e0     PUSH       -0x1
    //         0055b4e2     PUSH       FUN_00561faa
    //         0055b4e7     MOV        EAX,FS:[0x0]
    //         0055b4ed     PUSH       EAX
    //         0055b4ee     MOV        dword ptr FS:[0x0],ESP
    //         0055b4f5     SUB        ESP,0x8
    //         0055b4f8     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055b4fc     PUSH       ESI
    //         0055b4fd     PUSH       EDI
    //         0055b4fe     XOR        EDI,EDI
    //         0055b500     MOV        ESI,this
    //         0055b502     CMP        EAX,EDI
    //         0055b504     MOV        dword ptr [ESP + local_10],ESI
    //         0055b508     MOV        dword ptr [ESP + local_14],EDI
    //         0055b50c     JZ         LAB_0055b528
    //         0055b50e     LEA        this,[ESI + 0xc]
    //         0055b511     MOV        dword ptr [ESI],istream::`vbtable'
    //         0055b517     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055b51c     MOV        dword ptr [ESP + local_14],0x1
    //         0055b524     MOV        dword ptr [ESP + local_4],EDI
    //                               LAB_0055b528                                                 XREF[1]:     0055b50c(j)  
    //         0055b528     MOV        EAX,dword ptr [ESI]
    //         0055b52a     MOV        EDX,dword ptr [ESP + param_1]
    //         0055b52e     PUSH       EDX
    //         0055b52f     MOV        this,dword ptr [EAX + 0x4]=>DAT_00578084         = 0000000Ch
    //         0055b532     MOV        dword ptr [this->field0_0x0 + ESI*0x1],istream   = 0055b4b0
    //         0055b539     MOV        EAX,dword ptr [ESI]
    //         0055b53b     MOV        this,dword ptr [EAX + 0x4]=>DAT_00578084         = 0000000Ch
    //         0055b53e     ADD        this,ESI
    //         0055b540     CALL       ios::init                                        void init(ios * this, streambuf * param_1)
    //         0055b545     MOV        this,dword ptr [ESI]
    //         0055b547     MOV        EDX,dword ptr [ECX + this->_fGline]=>DAT_00578   = 0000000Ch
    //         0055b54a     MOV        this,dword ptr [EDX + ESI*0x1 + 0x24]
    //         0055b54e     OR         this,0x1
    //         0055b551     LEA        EAX,[EDX + ESI*0x1 + 0x24]
    //         0055b555     MOV        dword ptr [EAX],this
    //         0055b557     MOV        this,dword ptr [ESP + local_c]
    //         0055b55b     MOV        dword ptr [ESI + 0x8],EDI
    //         0055b55e     MOV        dword ptr [ESI + 0x4],EDI
    //         0055b561     MOV        EAX,ESI
    //         0055b563     POP        EDI
    //         0055b564     MOV        dword ptr FS:[0x0],this
    //         0055b56b     POP        ESI
    //         0055b56c     ADD        ESP,0x14
    //         0055b56f     RET        0x8
}

// Offset: 0x0055B580
undefined istream(istream* this_, istream* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: __thiscall istream::istream(class istream const &)                                         *
    //                              *********************************************************************************************************
    //                              undefined __thiscall istream(istream * this, istream * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              istream *         Stack[0x4]:4   param_1                   XREF[1]:     0055b5cd(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055b5c4(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0055b600(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0055b5a4(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055b5a8(W), 0055b5bc(W)  
    //                               ??0istream@@IAE@ABV0@@Z
    //                               istream::istream
    //         0055b580     PUSH       -0x1
    //         0055b582     PUSH       FUN_00561fda
    //         0055b587     MOV        EAX,FS:[0x0]
    //         0055b58d     PUSH       EAX
    //         0055b58e     MOV        dword ptr FS:[0x0],ESP
    //         0055b595     SUB        ESP,0x8
    //         0055b598     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055b59c     PUSH       ESI
    //         0055b59d     PUSH       EDI
    //         0055b59e     XOR        EDI,EDI
    //         0055b5a0     MOV        ESI,this
    //         0055b5a2     CMP        EAX,EDI
    //         0055b5a4     MOV        dword ptr [ESP + local_10],ESI
    //         0055b5a8     MOV        dword ptr [ESP + local_14],EDI
    //         0055b5ac     JZ         LAB_0055b5c8
    //         0055b5ae     LEA        this,[ESI + 0xc]
    //         0055b5b1     MOV        dword ptr [ESI],istream::`vbtable'
    //         0055b5b7     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055b5bc     MOV        dword ptr [ESP + local_14],0x1
    //         0055b5c4     MOV        dword ptr [ESP + local_4],EDI
    //                               LAB_0055b5c8                                                 XREF[1]:     0055b5ac(j)  
    //         0055b5c8     MOV        EAX,dword ptr [ESI]
    //         0055b5ca     MOV        this,dword ptr [EAX + 0x4]=>DAT_00578084         = 0000000Ch
    //         0055b5cd     MOV        EAX,dword ptr [ESP + param_1]
    //         0055b5d1     MOV        dword ptr [this->field0_0x0 + ESI*0x1],istream   = 0055b4b0
    //         0055b5d8     MOV        EDX,dword ptr [EAX]
    //         0055b5da     MOV        this,dword ptr [EDX + 0x4]
    //         0055b5dd     MOV        EDX,dword ptr [ECX + EAX*0x1 + this->_fGline]
    //         0055b5e1     MOV        EAX,dword ptr [ESI]
    //         0055b5e3     PUSH       EDX
    //         0055b5e4     MOV        this,dword ptr [EAX + 0x4]=>DAT_00578084         = 0000000Ch
    //         0055b5e7     ADD        this,ESI
    //         0055b5e9     CALL       ios::init                                        void init(ios * this, streambuf * param_1)
    //         0055b5ee     MOV        this,dword ptr [ESI]
    //         0055b5f0     MOV        EDX,dword ptr [ECX + this->_fGline]=>DAT_00578   = 0000000Ch
    //         0055b5f3     MOV        this,dword ptr [EDX + ESI*0x1 + 0x24]
    //         0055b5f7     OR         this,0x1
    //         0055b5fa     LEA        EAX,[EDX + ESI*0x1 + 0x24]
    //         0055b5fe     MOV        dword ptr [EAX],this
    //         0055b600     MOV        this,dword ptr [ESP + local_c]
    //         0055b604     MOV        dword ptr [ESI + 0x8],EDI
    //         0055b607     MOV        dword ptr [ESI + 0x4],EDI
    //         0055b60a     MOV        EAX,ESI
    //         0055b60c     POP        EDI
    //         0055b60d     MOV        dword ptr FS:[0x0],this
    //         0055b614     POP        ESI
    //         0055b615     ADD        ESP,0x14
    //         0055b618     RET        0x8
}

// Offset: 0x0055B620
void istream(istream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall istream::~istream(void)                                                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~istream(istream * this)
    //              void              <VOID>         <RETURN>
    //              istream *         ECX:4 (auto)   this
    //                               ??1istream@@UAE@XZ                                           XREF[2]:     `scalar_deleting_destructor':0055b
    //                               istream::~istream                                                         ~istream_withassign:0055bace(c)  
    //         0055b620     MOV        EAX,dword ptr [this->field0_0x0 + DAT_fffffff4]
    //         0055b623     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055b626     MOV        dword ptr [EDX + this->field0_0x0*0x1 + -0xc],   = 0055b4b0
    //         0055b62e     RET
}

// Offset: 0x0055B630
istream* operator(istream* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: class istream & __thiscall istream::operator=(class streambuf *)                           *
    //                              *********************************************************************************************************
    //                              istream * __thiscall operator=(istream * this, streambuf * param_1)
    //              istream *         EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1
    //              undefined         Stack[-0x40]:1 local_40                  XREF[1]:     0055b674(*)  
    //                               ??4istream@@IAEAAV0@PAVstreambuf@@@Z
    //                               istream::operator=
    //         0055b630     MOV        EAX,FS:[0x0]
    //         0055b636     PUSH       -0x1
    //         0055b638     PUSH       FUN_00561ff8
    //         0055b63d     PUSH       EAX
    //         0055b63e     MOV        dword ptr FS:[0x0],ESP
    //         0055b645     SUB        ESP,0x34
    //         0055b648     PUSH       ESI
    //         0055b649     MOV        ESI,this
    //         0055b64b     PUSH       EDI
    //         0055b64c     XOR        EDI,EDI
    //         0055b64e     MOV        EAX,dword ptr [ESI]
    //         0055b650     MOV        this,dword ptr [EAX + 0x4]
    //         0055b653     LEA        EAX,[this->field0_0x0 + ESI*0x1]
    //         0055b656     MOV        this,dword ptr [ECX + ESI*0x1 + this->field22_
    //         0055b65a     CMP        this,EDI
    //         0055b65c     JZ         LAB_0055b66b
    //         0055b65e     MOV        this,dword ptr [EAX + 0x4]
    //         0055b661     CMP        this,EDI
    //         0055b663     JZ         LAB_0055b66b
    //         0055b665     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055b667     PUSH       0x1
    //         0055b669     CALL       dword ptr [EDX]
    //                               LAB_0055b66b                                                 XREF[2]:     0055b65c(j), 0055b663(j)  
    //         0055b66b     MOV        EAX,dword ptr [ESI]
    //         0055b66d     MOV        this,dword ptr [EAX + 0x4]
    //         0055b670     MOV        dword ptr [ECX + ESI*0x1 + this->_fGline],EDI
    //         0055b674     LEA        this=>local_40,[ESP + 0x8]
    //         0055b678     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055b67d     MOV        EDX,dword ptr [ESI]
    //         0055b67f     PUSH       EAX
    //         0055b680     MOV        dword ptr [ESP + 0x48],EDI
    //         0055b684     MOV        this,dword ptr [EDX + 0x4]
    //         0055b687     ADD        this,ESI
    //         0055b689     CALL       ios::operator=                                   ios * operator=(ios * this, ios * param_1)
    //         0055b68e     LEA        this,[ESP + 0x8]
    //         0055b692     MOV        dword ptr [ESP + 0x44],0xffffffff
    //         0055b69a     CALL       ios::~ios                                        void ~ios(ios * this)
    //         0055b69f     MOV        EAX,dword ptr [ESI]
    //         0055b6a1     MOV        EDX,dword ptr [ESP + 0x4c]
    //         0055b6a5     PUSH       EDX
    //         0055b6a6     MOV        this,dword ptr [EAX + 0x4]
    //         0055b6a9     MOV        dword ptr [ECX + ESI*0x1 + this->field22_0x1c]
    //         0055b6ad     MOV        EAX,dword ptr [ESI]
    //         0055b6af     MOV        this,dword ptr [EAX + 0x4]
    //         0055b6b2     ADD        this,ESI
    //         0055b6b4     CALL       ios::init                                        void init(ios * this, streambuf * param_1)
    //         0055b6b9     MOV        this,dword ptr [ESI]
    //         0055b6bb     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b6be     MOV        this,dword ptr [EDX + ESI*0x1 + 0x24]
    //         0055b6c2     OR         this,0x1
    //         0055b6c5     LEA        EAX,[EDX + ESI*0x1 + 0x24]
    //         0055b6c9     MOV        dword ptr [EAX],this
    //         0055b6cb     MOV        this,dword ptr [ESP + 0x3c]
    //         0055b6cf     MOV        dword ptr [ESI + 0x8],EDI
    //         0055b6d2     MOV        EAX,ESI
    //         0055b6d4     POP        EDI
    //         0055b6d5     MOV        dword ptr FS:[0x0],this
    //         0055b6dc     POP        ESI
    //         0055b6dd     ADD        ESP,0x40
    //         0055b6e0     RET        0x4
}

// Offset: 0x0055B6F0
int ipfx(istream* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall istream::ipfx(int)                                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall ipfx(istream * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0055b6f2(R)  
    //                               ?ipfx@istream@@QAEHH@Z                                       XREF[3]:     get:0055ae3a(c), 
    //                               istream::ipfx                                                             operator>>:0055b798(c), 
    //                                                                                                         peek:0055b885(c)  
    //         0055b6f0     PUSH       ESI
    //         0055b6f1     PUSH       EDI
    //         0055b6f2     MOV        EDI,dword ptr [ESP + param_1]
    //         0055b6f6     MOV        ESI,this
    //         0055b6f8     TEST       EDI,EDI
    //         0055b6fa     JZ         LAB_0055b703
    //         0055b6fc     MOV        dword ptr [ESI + 0x8],0x0
    //                               LAB_0055b703                                                 XREF[1]:     0055b6fa(j)  
    //         0055b703     MOV        EAX,dword ptr [ESI]
    //         0055b705     MOV        this,dword ptr [EAX + 0x4]
    //         0055b708     LEA        EAX,[this->field0_0x0 + ESI*0x1]
    //         0055b70b     MOV        this,dword ptr [ECX + ESI*0x1 + this->x_gcount]
    //         0055b70f     TEST       this,this
    //         0055b711     JZ         LAB_0055b720
    //         0055b713     OR         this,0x2
    //         0055b716     MOV        dword ptr [EAX + 0x8],this
    //         0055b719     XOR        EAX,EAX
    //         0055b71b     POP        EDI
    //         0055b71c     POP        ESI
    //         0055b71d     RET        0x4
    //                               LAB_0055b720                                                 XREF[1]:     0055b711(j)  
    //         0055b720     MOV        this,dword ptr [EAX + 0x20]
    //         0055b723     TEST       this,this
    //         0055b725     JZ         LAB_0055b747
    //         0055b727     TEST       EDI,EDI
    //         0055b729     JZ         LAB_0055b742
    //         0055b72b     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055b72e     MOV        EAX,dword ptr [EDX + 0x2c]
    //         0055b731     MOV        EDX,dword ptr [EDX + 0x28]
    //         0055b734     CMP        EDX,EAX
    //         0055b736     JNC        LAB_0055b73c
    //         0055b738     SUB        EAX,EDX
    //         0055b73a     JMP        LAB_0055b73e
    //                               LAB_0055b73c                                                 XREF[1]:     0055b736(j)  
    //         0055b73c     XOR        EAX,EAX
    //                               LAB_0055b73e                                                 XREF[1]:     0055b73a(j)  
    //         0055b73e     CMP        EDI,EAX
    //         0055b740     JLE        LAB_0055b747
    //                               LAB_0055b742                                                 XREF[1]:     0055b729(j)  
    //         0055b742     CALL       ostream::flush                                   ostream * flush(ostream * this)
    //                               LAB_0055b747                                                 XREF[2]:     0055b725(j), 0055b740(j)  
    //         0055b747     TEST       EDI,EDI
    //         0055b749     JNZ        LAB_0055b77a
    //         0055b74b     MOV        EDX,dword ptr [ESI]
    //         0055b74d     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055b750     TEST       byte ptr [EAX + ESI*0x1 + 0x24],0x1
    //         0055b755     JZ         LAB_0055b77a
    //         0055b757     MOV        this,ESI
    //         0055b759     CALL       istream::eatwhite                                void eatwhite(istream * this)
    //         0055b75e     MOV        this,dword ptr [ESI]
    //         0055b760     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b763     MOV        EAX,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055b767     LEA        this,[EDX + ESI*0x1 + 0x8]
    //         0055b76b     TEST       EAX,EAX
    //         0055b76d     JZ         LAB_0055b77a
    //         0055b76f     OR         AL,0x2
    //         0055b771     MOV        dword ptr [this->field0_0x0],EAX
    //         0055b773     XOR        EAX,EAX
    //         0055b775     POP        EDI
    //         0055b776     POP        ESI
    //         0055b777     RET        0x4
    //                               LAB_0055b77a                                                 XREF[3]:     0055b749(j), 0055b755(j), 
    //                                                                                                         0055b76d(j)  
    //         0055b77a     POP        EDI
    //         0055b77b     MOV        EAX,0x1
    //         0055b780     POP        ESI
    //         0055b781     RET        0x4
}

// Offset: 0x0055B790
istream* operator(istream* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class istream & __thiscall istream::operator>>(char *)                                        *
    //                              *********************************************************************************************************
    //                              istream * __thiscall operator>>(istream * this, char * param_1)
    //              istream *         EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[3]:     0055b7b9(R), 0055b804(R), 0055b867(R)  
    //                               ??5istream@@QAEAAV0@PAD@Z
    //                               istream::operator>>
    //         0055b790     PUSH       EBX
    //         0055b791     PUSH       EBP
    //         0055b792     PUSH       ESI
    //         0055b793     PUSH       EDI
    //         0055b794     MOV        ESI,this
    //         0055b796     PUSH       0x0
    //         0055b798     CALL       istream::ipfx                                    int ipfx(istream * this, int param_1)
    //         0055b79d     TEST       EAX,EAX
    //         0055b79f     JZ         LAB_0055b86f
    //         0055b7a5     MOV        EAX,dword ptr [ESI]
    //         0055b7a7     MOV        this,dword ptr [EAX + 0x4]
    //         0055b7aa     MOV        EBP,dword ptr [ECX + ESI*0x1 + this->field42_0
    //         0055b7ae     LEA        EAX,[ECX + ESI*0x1 + this->field42_0x30]
    //         0055b7b2     DEC        EBP
    //         0055b7b3     MOV        dword ptr [EAX],0x0
    //         0055b7b9     MOV        EAX,dword ptr [ESP + param_1]
    //         0055b7bd     TEST       EAX,EAX
    //         0055b7bf     JNZ        LAB_0055b7dc
    //         0055b7c1     MOV        EDX,dword ptr [ESI]
    //         0055b7c3     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055b7c6     MOV        this,dword ptr [EAX + ESI*0x1 + 0x8]
    //         0055b7ca     LEA        EAX,[EAX + ESI*0x1 + 0x8]
    //         0055b7ce     OR         this,0x2
    //         0055b7d1     MOV        dword ptr [EAX],this
    //         0055b7d3     MOV        EAX,ESI
    //         0055b7d5     POP        EDI
    //         0055b7d6     POP        ESI
    //         0055b7d7     POP        EBP
    //         0055b7d8     POP        EBX
    //         0055b7d9     RET        0x4
    //                               LAB_0055b7dc                                                 XREF[1]:     0055b7bf(j)  
    //         0055b7dc     XOR        EDI,EDI
    //         0055b7de     TEST       EBP,EBP
    //         0055b7e0     JBE        LAB_0055b848
    //                               LAB_0055b7e2                                                 XREF[1]:     0055b81c(j)  
    //         0055b7e2     MOV        this,dword ptr [ESI]
    //         0055b7e4     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b7e7     MOV        this,dword ptr [EDX + ESI*0x1 + 0x4]
    //         0055b7eb     CALL       streambuf::sgetc                                 int sgetc(streambuf * this)
    //         0055b7f0     MOV        EBX,EAX
    //         0055b7f2     CMP        EBX,-0x1
    //         0055b7f5     JZ         LAB_0055b820
    //         0055b7f7     PUSH       EBX
    //         0055b7f8     CALL       isspace                                          undefined isspace()
    //         0055b7fd     ADD        ESP,0x4
    //         0055b800     TEST       EAX,EAX
    //         0055b802     JNZ        LAB_0055b848
    //         0055b804     MOV        EAX,dword ptr [ESP + param_1]
    //         0055b808     MOV        byte ptr [EDI + EAX*0x1],BL
    //         0055b80b     MOV        this,dword ptr [ESI]
    //         0055b80d     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b810     MOV        this,dword ptr [EDX + ESI*0x1 + 0x4]
    //         0055b814     CALL       streambuf::stossc                                void stossc(streambuf * this)
    //         0055b819     INC        EDI
    //         0055b81a     CMP        EDI,EBP
    //         0055b81c     JC         LAB_0055b7e2
    //         0055b81e     JMP        LAB_0055b848
    //                               LAB_0055b820                                                 XREF[1]:     0055b7f5(j)  
    //         0055b820     MOV        EAX,dword ptr [ESI]
    //         0055b822     MOV        this,dword ptr [EAX + 0x4]
    //         0055b825     LEA        EAX,[ECX + ESI*0x1 + this->x_gcount]
    //         0055b829     MOV        this,dword ptr [ECX + ESI*0x1 + this->x_gcount]
    //         0055b82d     OR         this,0x1
    //         0055b830     TEST       EDI,EDI
    //         0055b832     MOV        dword ptr [EAX],this
    //         0055b834     JNZ        LAB_0055b867
    //         0055b836     MOV        EDX,dword ptr [ESI]
    //         0055b838     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055b83b     MOV        this,dword ptr [EAX + ESI*0x1 + 0x8]
    //         0055b83f     LEA        EAX,[EAX + ESI*0x1 + 0x8]
    //         0055b843     OR         this,0x6
    //         0055b846     MOV        dword ptr [EAX],this
    //                               LAB_0055b848                                                 XREF[3]:     0055b7e0(j), 0055b802(j), 
    //                                                                                                         0055b81e(j)  
    //         0055b848     TEST       EDI,EDI
    //         0055b84a     JNZ        LAB_0055b867
    //         0055b84c     MOV        this,dword ptr [ESI]
    //         0055b84e     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b851     MOV        this,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055b855     OR         this,0x2
    //         0055b858     LEA        EAX,[EDX + ESI*0x1 + 0x8]
    //         0055b85c     MOV        dword ptr [EAX],this
    //         0055b85e     MOV        EAX,ESI
    //         0055b860     POP        EDI
    //         0055b861     POP        ESI
    //         0055b862     POP        EBP
    //         0055b863     POP        EBX
    //         0055b864     RET        0x4
    //                               LAB_0055b867                                                 XREF[2]:     0055b834(j), 0055b84a(j)  
    //         0055b867     MOV        EAX,dword ptr [ESP + param_1]
    //         0055b86b     MOV        byte ptr [EDI + EAX*0x1],0x0
    //                               LAB_0055b86f                                                 XREF[1]:     0055b79f(j)  
    //         0055b86f     MOV        EAX,ESI
    //         0055b871     POP        EDI
    //         0055b872     POP        ESI
    //         0055b873     POP        EBP
    //         0055b874     POP        EBX
    //         0055b875     RET        0x4
}

// Offset: 0x0055B880
int peek(istream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall istream::peek(void)                                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall peek(istream * this)
    //              int               EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //                               ?peek@istream@@QAEHXZ
    //                               istream::peek
    //         0055b880     PUSH       ESI
    //         0055b881     MOV        ESI,this
    //         0055b883     PUSH       0x1
    //         0055b885     CALL       istream::ipfx                                    int ipfx(istream * this, int param_1)
    //         0055b88a     TEST       EAX,EAX
    //         0055b88c     JZ         LAB_0055b89e
    //         0055b88e     MOV        EAX,dword ptr [ESI]
    //         0055b890     MOV        this,dword ptr [EAX + 0x4]
    //         0055b893     MOV        this,dword ptr [ECX + ESI*0x1 + this->_fGline]
    //         0055b897     CALL       streambuf::sgetc                                 int sgetc(streambuf * this)
    //         0055b89c     POP        ESI
    //         0055b89d     RET
    //                               LAB_0055b89e                                                 XREF[1]:     0055b88c(j)  
    //         0055b89e     OR         EAX,0xffffffff
    //         0055b8a1     POP        ESI
    //         0055b8a2     RET
}

// Offset: 0x0055B8B0
istream* putback(istream* this_, char param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: class istream & __thiscall istream::putback(char)                                             *
    //                              *********************************************************************************************************
    //                              istream * __thiscall putback(istream * this, char param_1)
    //              istream *         EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //              char              Stack[0x4]:1   param_1                   XREF[2]:     0055b8d4(R), 0055b8df(R)  
    //                               ?putback@istream@@QAEAAV1@D@Z
    //                               istream::putback
    //         0055b8b0     PUSH       ESI
    //         0055b8b1     MOV        ESI,this
    //         0055b8b3     MOV        EAX,dword ptr [ESI]
    //         0055b8b5     MOV        this,dword ptr [EAX + 0x4]
    //         0055b8b8     LEA        EAX,[this->field0_0x0 + ESI*0x1]
    //         0055b8bb     MOV        this,dword ptr [ECX + ESI*0x1 + this->x_gcount]
    //         0055b8bf     TEST       this,this
    //         0055b8c1     JNZ        LAB_0055b900
    //         0055b8c3     MOV        this,dword ptr [EAX + 0x4]
    //         0055b8c6     MOV        EAX,dword ptr [ECX + this->field34_0x28]
    //         0055b8c9     MOV        EDX,dword ptr [ECX + this->field30_0x24]
    //         0055b8cc     CMP        EDX,EAX
    //         0055b8ce     JNC        LAB_0055b8df
    //         0055b8d0     DEC        EAX
    //         0055b8d1     MOV        dword ptr [ECX + this->field34_0x28],EAX
    //         0055b8d4     MOV        this,byte ptr [ESP + param_1]
    //         0055b8d8     MOV        byte ptr [EAX],this
    //         0055b8da     MOVSX      EAX,this
    //         0055b8dd     JMP        LAB_0055b8ea
    //                               LAB_0055b8df                                                 XREF[1]:     0055b8ce(j)  
    //         0055b8df     MOVSX      EAX,byte ptr [ESP + param_1]
    //         0055b8e4     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055b8e6     PUSH       EAX
    //         0055b8e7     CALL       dword ptr [EDX + 0x24]
    //                               LAB_0055b8ea                                                 XREF[1]:     0055b8dd(j)  
    //         0055b8ea     CMP        EAX,-0x1
    //         0055b8ed     JNZ        LAB_0055b900
    //         0055b8ef     MOV        this,dword ptr [ESI]
    //         0055b8f1     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b8f4     MOV        EAX,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055b8f8     LEA        this,[EDX + ESI*0x1 + 0x8]
    //         0055b8fc     OR         AL,0x2
    //         0055b8fe     MOV        dword ptr [this->field0_0x0],EAX
    //                               LAB_0055b900                                                 XREF[2]:     0055b8c1(j), 0055b8ed(j)  
    //         0055b900     MOV        EAX,ESI
    //         0055b902     POP        ESI
    //         0055b903     RET        0x4
}

// Offset: 0x0055B910
int sync(istream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall istream::sync(void)                                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall sync(istream * this)
    //              int               EAX:4          <RETURN>
    //              istream *         ECX:4 (auto)   this
    //                               ?sync@istream@@QAEHXZ
    //                               istream::sync
    //         0055b910     PUSH       ESI
    //         0055b911     MOV        ESI,this
    //         0055b913     MOV        EAX,dword ptr [ESI]
    //         0055b915     MOV        this,dword ptr [EAX + 0x4]
    //         0055b918     MOV        this,dword ptr [ECX + ESI*0x1 + this->_fGline]
    //         0055b91c     MOV        EDX,dword ptr [this->field0_0x0]
    //         0055b91e     CALL       dword ptr [EDX + 0x4]
    //         0055b921     CMP        EAX,-0x1
    //         0055b924     JNZ        LAB_0055b938
    //         0055b926     MOV        this,dword ptr [ESI]
    //         0055b928     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b92b     LEA        this,[EDX + ESI*0x1 + 0x8]
    //         0055b92f     MOV        EDX,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055b933     OR         EDX,0x6
    //         0055b936     MOV        dword ptr [this->field0_0x0],EDX
    //                               LAB_0055b938                                                 XREF[1]:     0055b924(j)  
    //         0055b938     POP        ESI
    //         0055b939     RET
}

// Offset: 0x0055B940
void eatwhite(istream* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall istream::eatwhite(void)                                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall eatwhite(istream * this)
    //              void              <VOID>         <RETURN>
    //              istream *         ECX:4 (auto)   this
    //                               ?eatwhite@istream@@QAEXXZ                                    XREF[1]:     ipfx:0055b759(c)  
    //                               istream::eatwhite
    //         0055b940     PUSH       ESI
    //         0055b941     MOV        ESI,this
    //         0055b943     MOV        EAX,dword ptr [ESI]
    //         0055b945     MOV        this,dword ptr [EAX + 0x4]
    //         0055b948     MOV        this,dword ptr [ECX + ESI*0x1 + this->_fGline]
    //         0055b94c     CALL       streambuf::sgetc                                 int sgetc(streambuf * this)
    //         0055b951     CMP        EAX,-0x1
    //         0055b954     JZ         LAB_0055b976
    //                               LAB_0055b956                                                 XREF[1]:     0055b974(j)  
    //         0055b956     PUSH       EAX
    //         0055b957     CALL       isspace                                          undefined isspace()
    //         0055b95c     ADD        ESP,0x4
    //         0055b95f     TEST       EAX,EAX
    //         0055b961     JZ         LAB_0055b988
    //         0055b963     MOV        EDX,dword ptr [ESI]
    //         0055b965     MOV        EAX,dword ptr [EDX + 0x4]
    //         0055b968     MOV        this,dword ptr [EAX + ESI*0x1 + 0x4]
    //         0055b96c     CALL       streambuf::snextc                                int snextc(streambuf * this)
    //         0055b971     CMP        EAX,-0x1
    //         0055b974     JNZ        LAB_0055b956
    //                               LAB_0055b976                                                 XREF[1]:     0055b954(j)  
    //         0055b976     MOV        this,dword ptr [ESI]
    //         0055b978     MOV        EDX,dword ptr [ECX + this->_fGline]
    //         0055b97b     MOV        this,dword ptr [EDX + ESI*0x1 + 0x8]
    //         0055b97f     OR         this,0x1
    //         0055b982     LEA        EAX,[EDX + ESI*0x1 + 0x8]
    //         0055b986     MOV        dword ptr [EAX],this
    //                               LAB_0055b988                                                 XREF[1]:     0055b961(j)  
    //         0055b988     POP        ESI
    //         0055b989     RET
}

// Offset: 0x0055B990
undefined istream_withassign(istream_withassign* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall istream_withassign::istream_withassign(void)                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall istream_withassign(istream_withassign * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              istream_withas    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055b9d5(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0055b9b9(W), 0055b9f4(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055b9af(W), 0055b9cd(W)  
    //                               ??0istream_withassign@@QAE@XZ
    //                               istream_withassign::istream_withassign
    //         0055b990     PUSH       -0x1
    //         0055b992     PUSH       FUN_00562026
    //         0055b997     MOV        EAX,FS:[0x0]
    //         0055b99d     PUSH       EAX
    //         0055b99e     MOV        dword ptr FS:[0x0],ESP
    //         0055b9a5     SUB        ESP,0x8
    //         0055b9a8     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055b9ac     PUSH       ESI
    //         0055b9ad     MOV        ESI,this
    //         0055b9af     MOV        dword ptr [ESP + local_14],0x0
    //         0055b9b7     TEST       EAX,EAX
    //         0055b9b9     MOV        dword ptr [ESP + local_10],ESI
    //         0055b9bd     JZ         LAB_0055b9dd
    //         0055b9bf     LEA        this,[ESI + 0xc]
    //         0055b9c2     MOV        dword ptr [ESI],istream_withassign::`vbtable'
    //         0055b9c8     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055b9cd     MOV        dword ptr [ESP + local_14],0x1
    //         0055b9d5     MOV        dword ptr [ESP + local_4],0x0
    //                               LAB_0055b9dd                                                 XREF[1]:     0055b9bd(j)  
    //         0055b9dd     PUSH       0x0
    //         0055b9df     MOV        this,ESI
    //         0055b9e1     CALL       istream::istream                                 undefined istream(istream * this)
    //         0055b9e6     MOV        EAX,dword ptr [ESI]
    //         0055b9e8     MOV        this,dword ptr [EAX + 0x4]=>DAT_00578094         = 0000000Ch
    //         0055b9eb     MOV        EAX,ESI
    //         0055b9ed     MOV        dword ptr [this + ESI*0x1],istream_withassign:   = 0055ba10
    //         0055b9f4     MOV        this,dword ptr [ESP + local_10]
    //         0055b9f8     MOV        dword ptr FS:[0x0],this
    //         0055b9ff     POP        ESI
    //         0055ba00     ADD        ESP,0x14
    //         0055ba03     RET        0x4
}

// Offset: 0x0055BA40
undefined istream_withassign(istream_withassign* this_, streambuf* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall istream_withassign::istream_withassign(class streambuf *)                          *
    //                              *********************************************************************************************************
    //                              undefined __thiscall istream_withassign(istream_withassign * this, s
    //              undefined         <UNASSIGNED>   <RETURN>
    //              istream_withas    ECX:4 (auto)   this
    //              streambuf *       Stack[0x4]:4   param_1                   XREF[1]:     0055ba8d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0055ba85(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[2]:     0055ba69(W), 0055baa2(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[2]:     0055ba5f(W), 0055ba7d(W)  
    //                               ??0istream_withassign@@QAE@PAVstreambuf@@@Z
    //                               istream_withassign::istream_withassign
    //         0055ba40     PUSH       -0x1
    //         0055ba42     PUSH       FUN_00562046
    //         0055ba47     MOV        EAX,FS:[0x0]
    //         0055ba4d     PUSH       EAX
    //         0055ba4e     MOV        dword ptr FS:[0x0],ESP
    //         0055ba55     SUB        ESP,0x8
    //         0055ba58     MOV        EAX,dword ptr [ESP + Stack[0x8]]
    //         0055ba5c     PUSH       ESI
    //         0055ba5d     MOV        ESI,this
    //         0055ba5f     MOV        dword ptr [ESP + local_14],0x0
    //         0055ba67     TEST       EAX,EAX
    //         0055ba69     MOV        dword ptr [ESP + local_10],ESI
    //         0055ba6d     JZ         LAB_0055ba8d
    //         0055ba6f     LEA        this,[ESI + 0xc]
    //         0055ba72     MOV        dword ptr [ESI],istream_withassign::`vbtable'
    //         0055ba78     CALL       ios::ios                                         undefined ios(ios * this)
    //         0055ba7d     MOV        dword ptr [ESP + local_14],0x1
    //         0055ba85     MOV        dword ptr [ESP + local_4],0x0
    //                               LAB_0055ba8d                                                 XREF[1]:     0055ba6d(j)  
    //         0055ba8d     MOV        EAX,dword ptr [ESP + param_1]
    //         0055ba91     PUSH       0x0
    //         0055ba93     PUSH       EAX
    //         0055ba94     MOV        this,ESI
    //         0055ba96     CALL       istream::istream                                 undefined istream(istream * this, streambuf *
    //         0055ba9b     MOV        this,dword ptr [ESI]
    //         0055ba9d     MOV        EAX,ESI
    //         0055ba9f     MOV        EDX,dword ptr [this + 0x4]=>DAT_00578094         = 0000000Ch
    //         0055baa2     MOV        this,dword ptr [ESP + local_10]
    //         0055baa6     MOV        dword ptr [EDX + ESI*0x1],istream_withassign::   = 0055ba10
    //         0055baad     MOV        dword ptr FS:[0x0],this
    //         0055bab4     POP        ESI
    //         0055bab5     ADD        ESP,0x14
    //         0055bab8     RET        0x8
}

// Offset: 0x0055BAC0
void istream_withassign(istream_withassign* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall istream_withassign::~istream_withassign(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~istream_withassign(istream_withassign * this)
    //              void              <VOID>         <RETURN>
    //              istream_withas    ECX:4 (auto)   this
    //                               ??1istream_withassign@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':0055b
    //                               istream_withassign::~istream_withassign
    //         0055bac0     MOV        EAX,dword ptr [this + DAT_fffffff4]
    //         0055bac3     MOV        EDX,dword ptr [EAX + 0x4]
    //         0055bac6     MOV        dword ptr [EDX + this*0x1 + -0xc],istream_with   = 0055ba10
    //         0055bace     JMP        istream::~istream                                void ~istream(istream * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x0055BAEC
undefined gethostname() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * __stdcall gethostname,8                                                                               *
    //                              *********************************************************************************************************
    //                              undefined __stdcall gethostname()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _gethostname@8                                               XREF[1]:     GetHostName:00424b6d(c)  
    //                               gethostname
    //         0055baec     JMP        dword ptr [->WSOCK32.DLL::gethostname]
}

// Offset: 0x0055BAF2
undefined gethostbyname() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * __stdcall gethostbyname,4                                                                             *
    //                              *********************************************************************************************************
    //                              undefined __stdcall gethostbyname()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _gethostbyname@4                                             XREF[2]:     SetIPAliases:00424b98(c), 
    //                               gethostbyname                                                             SetIPAddresses:00424c9e(c)  
    //         0055baf2     JMP        dword ptr [->WSOCK32.DLL::gethostbyname]
}

// Offset: 0x0055BC40
undefined strupr() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * strupr                                                                                                *
    //                              *********************************************************************************************************
    //                              undefined __cdecl strupr()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _strupr                                                      XREF[1]:     get_palette:00464325(c)  
    //                               __strupr
    //                               strupr
    //         0055bc40     MOV        EAX,[DAT_008882c0]
    //         0055bc45     PUSH       EBX
    //         0055bc46     XOR        EBX,EBX
    //         0055bc48     TEST       EAX,EAX
    //         0055bc4a     JNZ        LAB_0055bc76
    //         0055bc4c     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055bc50     MOV        EDX,EAX
    //         0055bc52     CMP        byte ptr [EAX],0x0
    //         0055bc55     JZ         LAB_0055bcf4
    //                               LAB_0055bc5b                                                 XREF[1]:     0055bc72(j)  
    //         0055bc5b     MOV        CL,byte ptr [EDX]
    //         0055bc5d     CMP        CL,0x61
    //         0055bc60     JL         LAB_0055bc6c
    //         0055bc62     CMP        CL,0x7a
    //         0055bc65     JG         LAB_0055bc6c
    //         0055bc67     SUB        CL,0x20
    //         0055bc6a     MOV        byte ptr [EDX],CL
    //                               LAB_0055bc6c                                                 XREF[2]:     0055bc60(j), 0055bc65(j)  
    //         0055bc6c     MOV        CL,byte ptr [EDX + 0x1]
    //         0055bc6f     INC        EDX
    //         0055bc70     TEST       CL,CL
    //         0055bc72     JNZ        LAB_0055bc5b
    //         0055bc74     POP        EBX
    //         0055bc75     RET
    //                               LAB_0055bc76                                                 XREF[1]:     0055bc4a(j)  
    //         0055bc76     PUSH       ESI
    //         0055bc77     PUSH       EBP
    //         0055bc78     MOV        EBP,dword ptr [ESP + Stack[0x4]]
    //         0055bc7c     PUSH       0x0
    //         0055bc7e     PUSH       0x0
    //         0055bc80     PUSH       0x0
    //         0055bc82     PUSH       -0x1
    //         0055bc84     PUSH       EBP
    //         0055bc85     PUSH       0x200
    //         0055bc8a     PUSH       EAX
    //         0055bc8b     CALL       ___crtLCMapStringA                               undefined ___crtLCMapStringA()
    //         0055bc90     MOV        ESI,EAX
    //         0055bc92     ADD        ESP,0x1c
    //         0055bc95     TEST       ESI,ESI
    //         0055bc97     JZ         LAB_0055bce7
    //         0055bc99     PUSH       ESI
    //         0055bc9a     CALL       malloc                                           undefined malloc()
    //         0055bc9f     MOV        EBX,EAX
    //         0055bca1     ADD        ESP,0x4
    //         0055bca4     TEST       EBX,EBX
    //         0055bca6     JZ         LAB_0055bce7
    //         0055bca8     MOV        EAX,[DAT_008882c0]
    //         0055bcad     PUSH       0x0
    //         0055bcaf     PUSH       ESI
    //         0055bcb0     PUSH       EBX
    //         0055bcb1     PUSH       -0x1
    //         0055bcb3     PUSH       EBP
    //         0055bcb4     PUSH       0x200
    //         0055bcb9     PUSH       EAX
    //         0055bcba     CALL       ___crtLCMapStringA                               undefined ___crtLCMapStringA()
    //         0055bcbf     ADD        ESP,0x1c
    //         0055bcc2     TEST       EAX,EAX
    //         0055bcc4     JZ         LAB_0055bce7
    //         0055bcc6     PUSH       EDI
    //         0055bcc7     MOV        EDI,EBX
    //         0055bcc9     OR         ECX,0xffffffff
    //         0055bccc     XOR        EAX,EAX
    //         0055bcce     SCASB.RE   ES:EDI
    //         0055bcd0     NOT        ECX
    //         0055bcd2     SUB        EDI,ECX
    //         0055bcd4     MOV        EDX,ECX
    //         0055bcd6     MOV        ESI,EDI
    //         0055bcd8     MOV        EDI,EBP
    //         0055bcda     SHR        ECX,0x2
    //         0055bcdd     MOVSD.REP  ES:EDI,ESI
    //         0055bcdf     MOV        ECX,EDX
    //         0055bce1     AND        ECX,0x3
    //         0055bce4     MOVSB.REP  ES:EDI,ESI
    //         0055bce6     POP        EDI
    //                               LAB_0055bce7                                                 XREF[3]:     0055bc97(j), 0055bca6(j), 
    //                                                                                                         0055bcc4(j)  
    //         0055bce7     PUSH       EBX
    //         0055bce8     CALL       free                                             undefined free()
    //         0055bced     ADD        ESP,0x4
    //         0055bcf0     MOV        EAX,EBP
    //         0055bcf2     POP        EBP
    //         0055bcf3     POP        ESI
    //                               LAB_0055bcf4                                                 XREF[1]:     0055bc55(j)  
    //         0055bcf4     POP        EBX
    //         0055bcf5     RET
}

// Offset: 0x0055BD00
undefined itoa() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * itoa                                                                                                  *
    //                              *********************************************************************************************************
    //                              undefined __cdecl itoa()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               _itoa                                                        XREF[29]:    set_mode:0048e64b(c), 
    //                               __itoa                                                                    set_mode:0048e675(c), 
    //                               itoa                                                                      set_mode:0048e69e(c), 
    //                                                                                                         set_mode:0048e6c8(c), 
    //                                                                                                         set_mode:0048e74a(c), 
    //                                                                                                         set_mode:0048e84a(c), 
    //                                                                                                         set_mode:0048e874(c), 
    //                                                                                                         set_mode:0048e8a1(c), 
    //                                                                                                         set_mode:0048e8cb(c), 
    //                                                                                                         set_mode:0048e922(c), 
    //                                                                                                         set_mode:0048ea31(c), 
    //                                                                                                         set_mode:0048ea5b(c), 
    //                                                                                                         set_mode:0048eb0b(c), 
    //                                                                                                         set_mode:0048eb35(c), 
    //                                                                                                         set_mode:0048ec54(c), 
    //                                                                                                         load_victory_cond_from_scenario:00
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         load_multi_victory_cond_from_scena
    //                                                                                                         [more]
    //         0055bd00     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0055bd04     MOV        EAX,dword ptr [ESP + Stack[0x4]]
    //         0055bd08     CMP        ECX,0xa
    //         0055bd0b     PUSH       ESI
    //         0055bd0c     JNZ        LAB_0055bd28
    //         0055bd0e     TEST       EAX,EAX
    //         0055bd10     JGE        LAB_0055bd28
    //         0055bd12     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055bd16     PUSH       0x1
    //         0055bd18     PUSH       0xa
    //         0055bd1a     PUSH       ESI
    //         0055bd1b     PUSH       EAX
    //         0055bd1c     CALL       FUN_0055bd40                                     undefined FUN_0055bd40()
    //         0055bd21     ADD        ESP,0x10
    //         0055bd24     MOV        EAX,ESI
    //         0055bd26     POP        ESI
    //         0055bd27     RET
    //                               LAB_0055bd28                                                 XREF[2]:     0055bd0c(j), 0055bd10(j)  
    //         0055bd28     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055bd2c     PUSH       0x0
    //         0055bd2e     PUSH       ECX
    //         0055bd2f     PUSH       ESI
    //         0055bd30     PUSH       EAX
    //         0055bd31     CALL       FUN_0055bd40                                     undefined FUN_0055bd40()
    //         0055bd36     ADD        ESP,0x10
    //         0055bd39     MOV        EAX,ESI
    //         0055bd3b     POP        ESI
    //         0055bd3c     RET
}

// Offset: 0x0055BD40
undefined FUN_0055bd40() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055bd40()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055bd40                                                 XREF[5]:     itoa:0055bd1c(c), 
    //                                                                                                         itoa:0055bd31(c), 
    //                                                                                                         FUN_0055bda1:0055bdcf(c), 
    //                                                                                                         FUN_0055bda1:0055bde5(c), 
    //                                                                                                         FUN_0055bdf1:0055be12(c)  
    //         0055bd40     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0055bd44     PUSH       EBX
    //         0055bd45     PUSH       EBP
    //         0055bd46     PUSH       ESI
    //         0055bd47     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055bd4b     PUSH       EDI
    //         0055bd4c     TEST       EAX,EAX
    //         0055bd4e     JZ         LAB_0055bd5c
    //         0055bd50     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055bd54     MOV        byte ptr [ESI],0x2d
    //         0055bd57     INC        ESI
    //         0055bd58     NEG        EDI
    //         0055bd5a     JMP        LAB_0055bd60
    //                               LAB_0055bd5c                                                 XREF[1]:     0055bd4e(j)  
    //         0055bd5c     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //                               LAB_0055bd60                                                 XREF[1]:     0055bd5a(j)  
    //         0055bd60     MOV        EBP,dword ptr [ESP + Stack[0xc]]
    //         0055bd64     MOV        EBX,ESI
    //                               LAB_0055bd66                                                 XREF[1]:     0055bd88(j)  
    //         0055bd66     MOV        EAX,EDI
    //         0055bd68     XOR        EDX,EDX
    //         0055bd6a     DIV        EBP
    //         0055bd6c     MOV        EAX,EDI
    //         0055bd6e     MOV        ECX,EDX
    //         0055bd70     XOR        EDX,EDX
    //         0055bd72     DIV        EBP
    //         0055bd74     CMP        ECX,0x9
    //         0055bd77     MOV        EDI,EAX
    //         0055bd79     JBE        LAB_0055bd80
    //         0055bd7b     ADD        CL,0x57
    //         0055bd7e     JMP        LAB_0055bd83
    //                               LAB_0055bd80                                                 XREF[1]:     0055bd79(j)  
    //         0055bd80     ADD        CL,0x30
    //                               LAB_0055bd83                                                 XREF[1]:     0055bd7e(j)  
    //         0055bd83     MOV        byte ptr [ESI],CL
    //         0055bd85     INC        ESI
    //         0055bd86     TEST       EDI,EDI
    //         0055bd88     JA         LAB_0055bd66
    //         0055bd8a     MOV        byte ptr [ESI],0x0
    //         0055bd8d     DEC        ESI
    //                               LAB_0055bd8e                                                 XREF[1]:     0055bd9a(j)  
    //         0055bd8e     MOV        CL,byte ptr [EBX]
    //         0055bd90     MOV        AL,byte ptr [ESI]
    //         0055bd92     MOV        byte ptr [ESI],CL
    //         0055bd94     MOV        byte ptr [EBX],AL
    //         0055bd96     DEC        ESI
    //         0055bd97     INC        EBX
    //         0055bd98     CMP        EBX,ESI
    //         0055bd9a     JC         LAB_0055bd8e
    //         0055bd9c     POP        EDI
    //         0055bd9d     POP        ESI
    //         0055bd9e     POP        EBP
    //         0055bd9f     POP        EBX
    //         0055bda0     RET
}

// Offset: 0x0055BDA1
undefined FUN_0055bda1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055bda1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055bda1
    //         0055bda1     NOP
    //         0055bda2     NOP
    //         0055bda3     NOP
    //         0055bda4     NOP
    //         0055bda5     NOP
    //         0055bda6     NOP
    //         0055bda7     NOP
    //         0055bda8     NOP
    //         0055bda9     NOP
    //         0055bdaa     NOP
    //         0055bdab     NOP
    //         0055bdac     NOP
    //         0055bdad     NOP
    //         0055bdae     NOP
    //         0055bdaf     NOP
    //                               __ltoa
    //         0055bdb0     MOV        ECX,dword ptr [ESP + Stack[0xc]]
    //         0055bdb4     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0055bdb8     CMP        ECX,0xa
    //         0055bdbb     PUSH       ESI
    //         0055bdbc     JNZ        LAB_0055bddb
    //         0055bdbe     TEST       EDX,EDX
    //         0055bdc0     JGE        LAB_0055bddb
    //         0055bdc2     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055bdc6     MOV        EAX,0x1
    //         0055bdcb     PUSH       EAX
    //         0055bdcc     PUSH       ECX
    //         0055bdcd     PUSH       ESI
    //         0055bdce     PUSH       EDX
    //         0055bdcf     CALL       FUN_0055bd40                                     undefined FUN_0055bd40()
    //         0055bdd4     ADD        ESP,0x10
    //         0055bdd7     MOV        EAX,ESI
    //         0055bdd9     POP        ESI
    //         0055bdda     RET
    //                               LAB_0055bddb                                                 XREF[2]:     0055bdbc(j), 0055bdc0(j)  
    //         0055bddb     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055bddf     XOR        EAX,EAX
    //         0055bde1     PUSH       EAX
    //         0055bde2     PUSH       ECX
    //         0055bde3     PUSH       ESI
    //         0055bde4     PUSH       EDX
    //         0055bde5     CALL       FUN_0055bd40                                     undefined FUN_0055bd40()
    //         0055bdea     ADD        ESP,0x10
    //         0055bded     MOV        EAX,ESI
    //         0055bdef     POP        ESI
    //         0055bdf0     RET
}

// Offset: 0x0055BDF1
undefined FUN_0055bdf1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055bdf1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055bdf1
    //         0055bdf1     NOP
    //         0055bdf2     NOP
    //         0055bdf3     NOP
    //         0055bdf4     NOP
    //         0055bdf5     NOP
    //         0055bdf6     NOP
    //         0055bdf7     NOP
    //         0055bdf8     NOP
    //         0055bdf9     NOP
    //         0055bdfa     NOP
    //         0055bdfb     NOP
    //         0055bdfc     NOP
    //         0055bdfd     NOP
    //         0055bdfe     NOP
    //         0055bdff     NOP
    //                               __ultoa
    //         0055be00     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0055be04     MOV        ECX,dword ptr [ESP + Stack[0x4]]
    //         0055be08     PUSH       ESI
    //         0055be09     MOV        ESI,dword ptr [ESP + Stack[0x8]]
    //         0055be0d     PUSH       0x0
    //         0055be0f     PUSH       EAX
    //         0055be10     PUSH       ESI
    //         0055be11     PUSH       ECX
    //         0055be12     CALL       FUN_0055bd40                                     undefined FUN_0055bd40()
    //         0055be17     ADD        ESP,0x10
    //         0055be1a     MOV        EAX,ESI
    //         0055be1c     POP        ESI
    //         0055be1d     RET
}

// Offset: 0x0055BE1E
undefined FUN_0055be1e() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055be1e()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055be1e
    //         0055be1e     NOP
    //         0055be1f     NOP
    //                               __i64toa
    //         0055be20     MOV        ECX,dword ptr [ESP + Stack[0x10]]
    //         0055be24     MOV        EDX,dword ptr [ESP + Stack[0x8]]
    //         0055be28     PUSH       ESI
    //         0055be29     PUSH       EDI
    //         0055be2a     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055be2e     CMP        ECX,0xa
    //         0055be31     JNZ        LAB_0055be55
    //         0055be33     TEST       EDX,EDX
    //         0055be35     JG         LAB_0055be55
    //         0055be37     JL         LAB_0055be3d
    //         0055be39     TEST       EDI,EDI
    //         0055be3b     JNC        LAB_0055be55
    //                               LAB_0055be3d                                                 XREF[1]:     0055be37(j)  
    //         0055be3d     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0055be41     MOV        EAX,0x1
    //         0055be46     PUSH       EAX
    //         0055be47     PUSH       ECX
    //         0055be48     PUSH       ESI
    //         0055be49     PUSH       EDX
    //         0055be4a     PUSH       EDI
    //         0055be4b     CALL       FUN_0055be70                                     undefined FUN_0055be70()
    //         0055be50     MOV        EAX,ESI
    //         0055be52     POP        EDI
    //         0055be53     POP        ESI
    //         0055be54     RET
    //                               LAB_0055be55                                                 XREF[3]:     0055be31(j), 0055be35(j), 
    //                                                                                                         0055be3b(j)  
    //         0055be55     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0055be59     XOR        EAX,EAX
    //         0055be5b     PUSH       EAX
    //         0055be5c     PUSH       ECX
    //         0055be5d     PUSH       ESI
    //         0055be5e     PUSH       EDX
    //         0055be5f     PUSH       EDI
    //         0055be60     CALL       FUN_0055be70                                     undefined FUN_0055be70()
    //         0055be65     MOV        EAX,ESI
    //         0055be67     POP        EDI
    //         0055be68     POP        ESI
    //         0055be69     RET
}

// Offset: 0x0055BE70
undefined FUN_0055be70() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055be70()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055be70                                                 XREF[3]:     FUN_0055be1e:0055be4b(c), 
    //                                                                                                         FUN_0055be1e:0055be60(c), 
    //                                                                                                         FUN_0055bef1:0055bf17(c)  
    //         0055be70     MOV        EAX,dword ptr [ESP + Stack[0x14]]
    //         0055be74     PUSH       EBX
    //         0055be75     PUSH       EBP
    //         0055be76     PUSH       ESI
    //         0055be77     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0055be7b     PUSH       EDI
    //         0055be7c     TEST       EAX,EAX
    //         0055be7e     JZ         LAB_0055be84
    //         0055be80     MOV        byte ptr [ESI],0x2d
    //         0055be83     INC        ESI
    //                               LAB_0055be84                                                 XREF[1]:     0055be7e(j)  
    //         0055be84     MOV        EBP,dword ptr [ESP + Stack[0x8]]
    //         0055be88     MOV        EDI,dword ptr [ESP + Stack[0x4]]
    //         0055be8c     MOV        dword ptr [ESP + Stack[0xc]],ESI
    //                               LAB_0055be90                                                 XREF[2]:     0055bec6(j), 0055becc(j)  
    //         0055be90     XOR        EAX,EAX
    //         0055be92     PUSH       EAX
    //         0055be93     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0055be97     PUSH       EAX
    //         0055be98     PUSH       EBP
    //         0055be99     PUSH       EDI
    //         0055be9a     CALL       __aullrem                                        undefined __aullrem()
    //         0055be9f     MOV        EBX,EAX
    //         0055bea1     XOR        EAX,EAX
    //         0055bea3     PUSH       EAX
    //         0055bea4     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0055bea8     PUSH       EAX
    //         0055bea9     PUSH       EBP
    //         0055beaa     PUSH       EDI
    //         0055beab     CALL       __aulldiv                                        undefined __aulldiv()
    //         0055beb0     CMP        EBX,0x9
    //         0055beb3     MOV        EDI,EAX
    //         0055beb5     MOV        EBP,EDX
    //         0055beb7     JBE        LAB_0055bebe
    //         0055beb9     ADD        BL,0x57
    //         0055bebc     JMP        LAB_0055bec1
    //                               LAB_0055bebe                                                 XREF[1]:     0055beb7(j)  
    //         0055bebe     ADD        BL,0x30
    //                               LAB_0055bec1                                                 XREF[1]:     0055bebc(j)  
    //         0055bec1     MOV        byte ptr [ESI],BL
    //         0055bec3     INC        ESI
    //         0055bec4     TEST       EBP,EBP
    //         0055bec6     JA         LAB_0055be90
    //         0055bec8     JC         LAB_0055bece
    //         0055beca     TEST       EDI,EDI
    //         0055becc     JA         LAB_0055be90
    //                               LAB_0055bece                                                 XREF[1]:     0055bec8(j)  
    //         0055bece     MOV        byte ptr [ESI],0x0
    //         0055bed1     DEC        ESI
    //                               LAB_0055bed2                                                 XREF[1]:     0055bee8(j)  
    //         0055bed2     MOV        EAX,dword ptr [ESP + Stack[0xc]]
    //         0055bed6     MOV        CL,byte ptr [ESI]
    //         0055bed8     DEC        ESI
    //         0055bed9     MOV        DL,byte ptr [EAX]
    //         0055bedb     INC        EAX
    //         0055bedc     MOV        byte ptr [ESI + 0x1],DL
    //         0055bedf     MOV        byte ptr [EAX + -0x1],CL
    //         0055bee2     CMP        EAX,ESI
    //         0055bee4     MOV        dword ptr [ESP + Stack[0xc]],EAX
    //         0055bee8     JC         LAB_0055bed2
    //         0055beea     POP        EDI
    //         0055beeb     POP        ESI
    //         0055beec     POP        EBP
    //         0055beed     POP        EBX
    //         0055beee     RET        0x14
}

// Offset: 0x0055BEF1
undefined FUN_0055bef1() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0055bef1()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0055bef1
    //         0055bef1     NOP
    //         0055bef2     NOP
    //         0055bef3     NOP
    //         0055bef4     NOP
    //         0055bef5     NOP
    //         0055bef6     NOP
    //         0055bef7     NOP
    //         0055bef8     NOP
    //         0055bef9     NOP
    //         0055befa     NOP
    //         0055befb     NOP
    //         0055befc     NOP
    //         0055befd     NOP
    //         0055befe     NOP
    //         0055beff     NOP
    //                               __ui64toa
    //         0055bf00     MOV        EAX,dword ptr [ESP + Stack[0x10]]
    //         0055bf04     MOV        ECX,dword ptr [ESP + Stack[0x8]]
    //         0055bf08     MOV        EDX,dword ptr [ESP + Stack[0x4]]
    //         0055bf0c     PUSH       ESI
    //         0055bf0d     MOV        ESI,dword ptr [ESP + Stack[0xc]]
    //         0055bf11     PUSH       0x0
    //         0055bf13     PUSH       EAX
    //         0055bf14     PUSH       ESI
    //         0055bf15     PUSH       ECX
    //         0055bf16     PUSH       EDX
    //         0055bf17     CALL       FUN_0055be70                                     undefined FUN_0055be70()
    //         0055bf1c     MOV        EAX,ESI
    //         0055bf1e     POP        ESI
    //         0055bf1f     RET
}

// Offset: 0x0055BF20
void type_info(type_info* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall type_info::~type_info(void)                                                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~type_info(type_info * this)
    //              void              <VOID>         <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //                               ??1type_info@@UAE@XZ                                         XREF[1]:     `vector_deleting_destructor':0055b
    //                               type_info::~type_info
    //         0055bf20     MOV        dword ptr [this],type_info::`vftable'            = 0055bf40
    //         0055bf26     MOV        this,dword ptr [this + 0x4]
    //         0055bf29     TEST       this,this
    //         0055bf2b     JZ         LAB_0055bf36
    //         0055bf2d     PUSH       this
    //         0055bf2e     CALL       free                                             undefined free()
    //         0055bf33     ADD        ESP,0x4
    //                               LAB_0055bf36                                                 XREF[1]:     0055bf2b(j)  
    //         0055bf36     RET
}

// Offset: 0x0055BF60
int operator(type_info* this_, type_info* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall type_info::operator==(class type_info const &)const                            *
    //                              *********************************************************************************************************
    //                              int __thiscall operator==(type_info * this, type_info * param_1)
    //              int               EAX:4          <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //              type_info *       Stack[0x4]:4   param_1                   XREF[1]:     0055bf60(R)  
    //                               ??8type_info@@QBEHABV0@@Z
    //                               type_info::operator==
    //         0055bf60     MOV        EAX,dword ptr [ESP + param_1]
    //         0055bf64     PUSH       EBX
    //         0055bf65     PUSH       ESI
    //         0055bf66     LEA        ESI,[this + 0x9]
    //         0055bf69     ADD        EAX,0x9
    //                               LAB_0055bf6c                                                 XREF[1]:     0055bf8e(j)  
    //         0055bf6c     MOV        DL,byte ptr [EAX]
    //         0055bf6e     MOV        BL,byte ptr [ESI]
    //         0055bf70     MOV        this,DL
    //         0055bf72     CMP        DL,BL
    //         0055bf74     JNZ        LAB_0055bfa0
    //         0055bf76     TEST       this,this
    //         0055bf78     JZ         LAB_0055bf90
    //         0055bf7a     MOV        DL,byte ptr [EAX + 0x1]
    //         0055bf7d     MOV        BL,byte ptr [ESI + 0x1]
    //         0055bf80     MOV        this,DL
    //         0055bf82     CMP        DL,BL
    //         0055bf84     JNZ        LAB_0055bfa0
    //         0055bf86     ADD        EAX,0x2
    //         0055bf89     ADD        ESI,0x2
    //         0055bf8c     TEST       this,this
    //         0055bf8e     JNZ        LAB_0055bf6c
    //                               LAB_0055bf90                                                 XREF[1]:     0055bf78(j)  
    //         0055bf90     XOR        EAX,EAX
    //         0055bf92     XOR        this,this
    //         0055bf94     TEST       EAX,EAX
    //         0055bf96     SETZ       this
    //         0055bf99     MOV        EAX,this
    //         0055bf9b     POP        ESI
    //         0055bf9c     POP        EBX
    //         0055bf9d     RET        0x4
    //                               LAB_0055bfa0                                                 XREF[2]:     0055bf74(j), 0055bf84(j)  
    //         0055bfa0     SBB        EAX,EAX
    //         0055bfa2     POP        ESI
    //         0055bfa3     SBB        EAX,-0x1
    //         0055bfa6     XOR        this,this
    //         0055bfa8     TEST       EAX,EAX
    //         0055bfaa     SETZ       this
    //         0055bfad     MOV        EAX,this
    //         0055bfaf     POP        EBX
    //         0055bfb0     RET        0x4
}

// Offset: 0x0055BFC0
int operator(type_info* this_, type_info* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall type_info::operator!=(class type_info const &)const                            *
    //                              *********************************************************************************************************
    //                              int __thiscall operator!=(type_info * this, type_info * param_1)
    //              int               EAX:4          <RETURN>
    //              type_info *       ECX:4 (auto)   this
    //              type_info *       Stack[0x4]:4   param_1                   XREF[1]:     0055bfc0(R)  
    //                               ??9type_info@@QBEHABV0@@Z
    //                               type_info::operator!=
    //         0055bfc0     MOV        EAX,dword ptr [ESP + param_1]
    //         0055bfc4     PUSH       EBX
    //         0055bfc5     PUSH       ESI
    //         0055bfc6     LEA        ESI,[this + 0x9]
    //         0055bfc9     ADD        EAX,0x9
    //                               LAB_0055bfcc                                                 XREF[1]:     0055bfee(j)  
    //         0055bfcc     MOV        DL,byte ptr [EAX]
    //         0055bfce     MOV        BL,byte ptr [ESI]
    //         0055bfd0     MOV        this,DL
    //         0055bfd2     CMP        DL,BL
    //         0055bfd4     JNZ        LAB_0055c000
    //         0055bfd6     TEST       this,this
    //         0055bfd8     JZ         LAB_0055bff0
    //         0055bfda     MOV        DL,byte ptr [EAX + 0x1]
    //         0055bfdd     MOV        BL,byte ptr [ESI + 0x1]
    //         0055bfe0     MOV        this,DL
    //         0055bfe2     CMP        DL,BL
    //         0055bfe4     JNZ        LAB_0055c000
    //         0055bfe6     ADD        EAX,0x2
    //         0055bfe9     ADD        ESI,0x2
    //         0055bfec     TEST       this,this
    //         0055bfee     JNZ        LAB_0055bfcc
    //                               LAB_0055bff0                                                 XREF[1]:     0055bfd8(j)  
    //         0055bff0     XOR        EAX,EAX
    //         0055bff2     XOR        this,this
    //         0055bff4     TEST       EAX,EAX
    //         0055bff6     SETNZ      this
    //         0055bff9     MOV        EAX,this
    //         0055bffb     POP        ESI
    //         0055bffc     POP        EBX
    //         0055bffd     RET        0x4
    //                               LAB_0055c000                                                 XREF[2]:     0055bfd4(j), 0055bfe4(j)  
    //         0055c000     SBB        EAX,EAX
    //         0055c002     POP        ESI
    //         0055c003     SBB        EAX,-0x1
    //         0055c006     XOR        this,this
    //         0055c008     TEST       EAX,EAX
    //         0055c00a     SETNZ      this
    //         0055c00d     MOV        EAX,this
    //         0055c00f     POP        EBX
    //         0055c010     RET        0x4
}

