// Auto-generated scaffold unit: aibobj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/aibobj.cpp
#include "../include/common.h"

// Offset: 0x00409FA0
undefined BaseObject(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BaseObject::BaseObject(void)                                                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BaseObject(BaseObject * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ??0BaseObject@@QAE@XZ
    //                               BaseObject::BaseObject
    //                              aibobj.cpp:43 (15)
    //         00409fa0     MOV        EDX,this
    //         00409fa2     PUSH       EBX
    //         00409fa3     PUSH       ESI
    //         00409fa4     PUSH       EDI
    //         00409fa5     XOR        EAX,EAX
    //         00409fa7     OR         this,0xffffffff
    //         00409faa     MOV        ESI,0xbf800000
    //                              aibobj.cpp:44 (126)
    //         00409faf     MOV        EDI,s_                                           = ""
    //         00409fb4     MOV        dword ptr [EDX + 0x4],EAX
    //         00409fb7     MOV        dword ptr [EDX + 0x8],EAX
    //         00409fba     MOV        dword ptr [EDX + 0xc],EAX
    //         00409fbd     MOV        dword ptr [EDX + 0x10],EAX
    //         00409fc0     MOV        dword ptr [EDX + 0x14],this
    //         00409fc3     MOV        dword ptr [EDX + 0x18],this
    //         00409fc6     MOV        dword ptr [EDX + 0x1c],this
    //         00409fc9     MOV        dword ptr [EDX + 0x60],ESI
    //         00409fcc     MOV        dword ptr [EDX + 0x64],ESI
    //         00409fcf     MOV        dword ptr [EDX + 0x68],ESI
    //         00409fd2     MOV        dword ptr [EDX + 0x6c],ESI
    //         00409fd5     MOV        dword ptr [EDX + 0x70],ESI
    //         00409fd8     MOV        dword ptr [EDX + 0x74],ESI
    //         00409fdb     MOV        dword ptr [EDX + 0x78],EAX
    //         00409fde     MOV        dword ptr [EDX + 0x7c],EAX
    //         00409fe1     MOV        dword ptr [EDX + 0x80],EAX
    //         00409fe7     MOV        dword ptr [EDX + 0x84],EAX
    //         00409fed     MOV        dword ptr [EDX + 0x88],this
    //         00409ff3     MOV        dword ptr [EDX + 0x8c],this
    //         00409ff9     MOV        dword ptr [EDX + 0x90],this
    //         00409fff     MOV        dword ptr [EDX + 0x94],EAX
    //         0040a005     MOV        dword ptr [EDX + 0x98],EAX
    //         0040a00b     MOV        dword ptr [EDX + 0x9c],EAX
    //         0040a011     MOV        dword ptr [EDX],BaseObject::`vftable'            = 0040a040
    //         0040a017     SCASB.RE   ES:EDI=>s_                                       = ""
    //         0040a019     NOT        this
    //         0040a01b     SUB        EDI,this
    //         0040a01d     LEA        EBX,[EDX + 0x20]
    //         0040a020     MOV        EAX,this
    //         0040a022     MOV        ESI,EDI
    //         0040a024     MOV        EDI,EBX
    //         0040a026     SHR        this,0x2
    //         0040a029     MOVSD.REP  ES:EDI,ESI
    //         0040a02b     MOV        this,EAX
    //                              aibobj.cpp:45 (11)
    //         0040a02d     MOV        EAX,EDX
    //         0040a02f     AND        this,0x3
    //         0040a032     MOVSB.REP  ES:EDI,ESI
    //         0040a034     POP        EDI
    //         0040a035     POP        ESI
    //         0040a036     POP        EBX
    //         0040a037     RET
}

// Offset: 0x0040A060
undefined BaseObject(BaseObject* this_, int param_2, int param_3, int param_4, int param_5, char* param_6, float param_7, float param_8, float param_9, float param_10, float param_11, float param_12, int param_13, int param_14, int param_15) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BaseObject::BaseObject(int,int,int,int,char *,float,float,float,float,float,flo... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BaseObject(BaseObject * this, int param_1, int 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a103(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0040a069(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     0040a060(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0040a072(R)  
    //              char *            Stack[0x14]:4  param_5                   XREF[1]:     0040a107(R)  
    //              float             Stack[0x18]:4  param_6                   XREF[1]:     0040a08e(R)  
    //              float             Stack[0x1c]:4  param_7                   XREF[1]:     0040a095(R)  
    //              float             Stack[0x20]:4  param_8                   XREF[1]:     0040a09c(R)  
    //              float             Stack[0x24]:4  param_9                   XREF[1]:     0040a079(R)  
    //              float             Stack[0x28]:4  param_10                  XREF[1]:     0040a080(R)  
    //              float             Stack[0x2c]:4  param_11                  XREF[1]:     0040a087(R)  
    //              int               Stack[0x30]:4  param_12                  XREF[1]:     0040a0a3(R)  
    //              int               Stack[0x34]:4  param_13                  XREF[1]:     0040a0aa(R)  
    //              int               Stack[0x38]:4  param_14                  XREF[1]:     0040a0b1(R)  
    //                               ??0BaseObject@@QAE@HHHHPADMMMMMMHHH@Z
    //                               BaseObject::BaseObject
    //                              aibobj.cpp:74 (13)
    //         0040a060     MOV        EDX,dword ptr [ESP + param_3]
    //         0040a064     PUSH       ESI
    //         0040a065     MOV        ESI,this
    //         0040a067     XOR        EAX,EAX
    //         0040a069     MOV        this,dword ptr [ESP + param_2]
    //                              aibobj.cpp:76 (150)
    //         0040a06d     PUSH       0x4
    //         0040a06f     MOV        dword ptr [ESI + 0x14],this
    //         0040a072     MOV        this,dword ptr [ESP + param_4]
    //         0040a076     MOV        dword ptr [ESI + 0x18],EDX
    //         0040a079     MOV        EDX,dword ptr [ESP + param_9]
    //         0040a07d     MOV        dword ptr [ESI + 0x1c],this
    //         0040a080     MOV        this,dword ptr [ESP + param_10]
    //         0040a084     MOV        dword ptr [ESI + 0x60],EDX
    //         0040a087     MOV        EDX,dword ptr [ESP + param_11]
    //         0040a08b     MOV        dword ptr [ESI + 0x64],this
    //         0040a08e     MOV        this,dword ptr [ESP + param_6]
    //         0040a092     MOV        dword ptr [ESI + 0x68],EDX
    //         0040a095     MOV        EDX,dword ptr [ESP + param_7]
    //         0040a099     MOV        dword ptr [ESI + 0x6c],this
    //         0040a09c     MOV        this,dword ptr [ESP + param_8]
    //         0040a0a0     MOV        dword ptr [ESI + 0x70],EDX
    //         0040a0a3     MOV        EDX,dword ptr [ESP + param_12]
    //         0040a0a7     MOV        dword ptr [ESI + 0x74],this
    //         0040a0aa     MOV        this,dword ptr [ESP + param_13]
    //         0040a0ae     MOV        dword ptr [ESI + 0x78],EDX
    //         0040a0b1     MOV        EDX,dword ptr [ESP + param_14]
    //         0040a0b5     MOV        dword ptr [ESI + 0x7c],this
    //         0040a0b8     OR         this,0xffffffff
    //         0040a0bb     MOV        dword ptr [ESI + 0x4],EAX
    //         0040a0be     MOV        dword ptr [ESI + 0x8],EAX
    //         0040a0c1     MOV        dword ptr [ESI + 0xc],0x1
    //         0040a0c8     MOV        dword ptr [ESI + 0x80],EDX
    //         0040a0ce     MOV        dword ptr [ESI + 0x84],EAX
    //         0040a0d4     MOV        dword ptr [ESI + 0x88],this
    //         0040a0da     MOV        dword ptr [ESI + 0x8c],this
    //         0040a0e0     MOV        dword ptr [ESI + 0x90],this
    //         0040a0e6     MOV        dword ptr [ESI + 0x94],EAX
    //         0040a0ec     MOV        dword ptr [ESI + 0x98],EAX
    //         0040a0f2     MOV        dword ptr [ESI + 0x9c],EAX
    //         0040a0f8     MOV        dword ptr [ESI],BaseObject::`vftable'            = 0040a040
    //         0040a0fe     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              aibobj.cpp:77 (4)
    //         0040a103     MOV        this,dword ptr [ESP + param_1]
    //                              aibobj.cpp:79 (27)
    //         0040a107     MOV        EDX,dword ptr [ESP + param_5]
    //         0040a10b     ADD        ESP,0x4
    //         0040a10e     MOV        dword ptr [ESI + 0x10],EAX
    //         0040a111     MOV        dword ptr [EAX],this
    //         0040a113     LEA        EAX,[ESI + 0x20]
    //         0040a116     PUSH       0x3f
    //         0040a118     PUSH       EDX
    //         0040a119     PUSH       EAX
    //         0040a11a     CALL       strncpy                                          undefined strncpy()
    //         0040a11f     ADD        ESP,0xc
    //                              aibobj.cpp:80 (6)
    //         0040a122     MOV        EAX,ESI
    //         0040a124     POP        ESI
    //         0040a125     RET        0x38
}

// Offset: 0x0040A130
undefined BaseObject(BaseObject* this_, BaseObject* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BaseObject::BaseObject(class BaseObject *)                                         *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BaseObject(BaseObject * this, BaseObject * para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              BaseObject *      Stack[0x4]:4   param_1                   XREF[1]:     0040a134(R)  
    //                               ??0BaseObject@@QAE@PAV0@@Z
    //                               BaseObject::BaseObject
    //                              aibobj.cpp:107 (172)
    //         0040a130     PUSH       ESI
    //         0040a131     MOV        ESI,this
    //         0040a133     PUSH       EDI
    //         0040a134     MOV        EDI,dword ptr [ESP + param_1]
    //         0040a138     MOV        dword ptr [ESI + 0x4],0x0
    //         0040a13f     MOV        dword ptr [ESI + 0x8],0x0
    //         0040a146     MOV        EAX,dword ptr [EDI + 0xc]
    //         0040a149     MOV        dword ptr [ESI + 0xc],EAX
    //         0040a14c     MOV        this,dword ptr [EDI + 0x14]
    //         0040a14f     MOV        dword ptr [ESI + 0x14],this
    //         0040a152     MOV        EDX,dword ptr [EDI + 0x18]
    //         0040a155     MOV        dword ptr [ESI + 0x18],EDX
    //         0040a158     MOV        EAX,dword ptr [EDI + 0x1c]
    //         0040a15b     MOV        dword ptr [ESI + 0x1c],EAX
    //         0040a15e     MOV        this,dword ptr [EDI + 0x60]
    //         0040a161     MOV        dword ptr [ESI + 0x60],this
    //         0040a164     MOV        EDX,dword ptr [EDI + 0x64]
    //         0040a167     MOV        dword ptr [ESI + 0x64],EDX
    //         0040a16a     MOV        EAX,dword ptr [EDI + 0x68]
    //         0040a16d     MOV        dword ptr [ESI + 0x68],EAX
    //         0040a170     MOV        this,dword ptr [EDI + 0x6c]
    //         0040a173     MOV        dword ptr [ESI + 0x6c],this
    //         0040a176     MOV        EDX,dword ptr [EDI + 0x70]
    //         0040a179     MOV        dword ptr [ESI + 0x70],EDX
    //         0040a17c     MOV        EAX,dword ptr [EDI + 0x74]
    //         0040a17f     MOV        dword ptr [ESI + 0x74],EAX
    //         0040a182     MOV        this,dword ptr [EDI + 0x78]
    //         0040a185     MOV        dword ptr [ESI + 0x78],this
    //         0040a188     MOV        EDX,dword ptr [EDI + 0x7c]
    //         0040a18b     MOV        dword ptr [ESI + 0x7c],EDX
    //         0040a18e     MOV        EAX,dword ptr [EDI + 0x80]
    //         0040a194     MOV        dword ptr [ESI + 0x80],EAX
    //         0040a19a     MOV        this,dword ptr [EDI + 0x84]
    //         0040a1a0     MOV        dword ptr [ESI + 0x84],this
    //         0040a1a6     MOV        EDX,dword ptr [EDI + 0x88]
    //         0040a1ac     MOV        dword ptr [ESI + 0x88],EDX
    //         0040a1b2     MOV        EAX,dword ptr [EDI + 0x8c]
    //         0040a1b8     MOV        dword ptr [ESI + 0x8c],EAX
    //         0040a1be     MOV        this,dword ptr [EDI + 0x90]
    //         0040a1c4     MOV        dword ptr [ESI + 0x90],this
    //         0040a1ca     MOV        EDX,dword ptr [EDI + 0x94]
    //         0040a1d0     MOV        dword ptr [ESI + 0x94],EDX
    //         0040a1d6     MOV        EAX,dword ptr [EDI + 0x98]
    //                              aibobj.cpp:109 (36)
    //         0040a1dc     MOV        EDX,dword ptr [ESI + 0xc]
    //         0040a1df     MOV        dword ptr [ESI + 0x98],EAX
    //         0040a1e5     MOV        this,dword ptr [EDI + 0x9c]
    //         0040a1eb     MOV        dword ptr [ESI],BaseObject::`vftable'            = 0040a040
    //         0040a1f1     SHL        EDX,0x2
    //         0040a1f4     PUSH       EDX
    //         0040a1f5     MOV        dword ptr [ESI + 0x9c],this
    //         0040a1fb     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              aibobj.cpp:110 (15)
    //         0040a200     MOV        this,dword ptr [ESI + 0xc]
    //         0040a203     MOV        dword ptr [ESI + 0x10],EAX
    //         0040a206     ADD        ESP,0x4
    //         0040a209     XOR        EAX,EAX
    //         0040a20b     TEST       this,this
    //         0040a20d     JLE        LAB_0040a223
    //                               LAB_0040a20f                                                 XREF[1]:     0040a221(j)  
    //                              aibobj.cpp:111 (20)
    //         0040a20f     MOV        this,dword ptr [EDI + 0x10]
    //         0040a212     MOV        EDX,dword ptr [ESI + 0x10]
    //         0040a215     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0040a218     MOV        dword ptr [EDX + EAX*0x4],this
    //         0040a21b     MOV        this,dword ptr [ESI + 0xc]
    //         0040a21e     INC        EAX
    //         0040a21f     CMP        EAX,this
    //         0040a221     JL         LAB_0040a20f
    //                               LAB_0040a223                                                 XREF[1]:     0040a20d(j)  
    //                              aibobj.cpp:113 (18)
    //         0040a223     ADD        EDI,0x20
    //         0040a226     PUSH       0x3f
    //         0040a228     LEA        EDX,[ESI + 0x20]
    //         0040a22b     PUSH       EDI
    //         0040a22c     PUSH       EDX
    //         0040a22d     CALL       strncpy                                          undefined strncpy()
    //         0040a232     ADD        ESP,0xc
    //                              aibobj.cpp:114 (7)
    //         0040a235     MOV        EAX,ESI
    //         0040a237     POP        EDI
    //         0040a238     POP        ESI
    //         0040a239     RET        0x4
}

// Offset: 0x0040A240
undefined BaseObject(BaseObject* this_, BaseObject* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall BaseObject::BaseObject(class BaseObject const &)                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall BaseObject(BaseObject * this, BaseObject * para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              BaseObject *      Stack[0x4]:4   param_1                   XREF[1]:     0040a244(R)  
    //                               ??0BaseObject@@QAE@ABV0@@Z
    //                               BaseObject::BaseObject
    //                              aibobj.cpp:141 (172)
    //         0040a240     PUSH       ESI
    //         0040a241     MOV        ESI,this
    //         0040a243     PUSH       EDI
    //         0040a244     MOV        EDI,dword ptr [ESP + param_1]
    //         0040a248     MOV        dword ptr [ESI + 0x4],0x0
    //         0040a24f     MOV        dword ptr [ESI + 0x8],0x0
    //         0040a256     MOV        EAX,dword ptr [EDI + 0xc]
    //         0040a259     MOV        dword ptr [ESI + 0xc],EAX
    //         0040a25c     MOV        this,dword ptr [EDI + 0x14]
    //         0040a25f     MOV        dword ptr [ESI + 0x14],this
    //         0040a262     MOV        EDX,dword ptr [EDI + 0x18]
    //         0040a265     MOV        dword ptr [ESI + 0x18],EDX
    //         0040a268     MOV        EAX,dword ptr [EDI + 0x1c]
    //         0040a26b     MOV        dword ptr [ESI + 0x1c],EAX
    //         0040a26e     MOV        this,dword ptr [EDI + 0x60]
    //         0040a271     MOV        dword ptr [ESI + 0x60],this
    //         0040a274     MOV        EDX,dword ptr [EDI + 0x64]
    //         0040a277     MOV        dword ptr [ESI + 0x64],EDX
    //         0040a27a     MOV        EAX,dword ptr [EDI + 0x68]
    //         0040a27d     MOV        dword ptr [ESI + 0x68],EAX
    //         0040a280     MOV        this,dword ptr [EDI + 0x6c]
    //         0040a283     MOV        dword ptr [ESI + 0x6c],this
    //         0040a286     MOV        EDX,dword ptr [EDI + 0x70]
    //         0040a289     MOV        dword ptr [ESI + 0x70],EDX
    //         0040a28c     MOV        EAX,dword ptr [EDI + 0x74]
    //         0040a28f     MOV        dword ptr [ESI + 0x74],EAX
    //         0040a292     MOV        this,dword ptr [EDI + 0x78]
    //         0040a295     MOV        dword ptr [ESI + 0x78],this
    //         0040a298     MOV        EDX,dword ptr [EDI + 0x7c]
    //         0040a29b     MOV        dword ptr [ESI + 0x7c],EDX
    //         0040a29e     MOV        EAX,dword ptr [EDI + 0x80]
    //         0040a2a4     MOV        dword ptr [ESI + 0x80],EAX
    //         0040a2aa     MOV        this,dword ptr [EDI + 0x84]
    //         0040a2b0     MOV        dword ptr [ESI + 0x84],this
    //         0040a2b6     MOV        EDX,dword ptr [EDI + 0x88]
    //         0040a2bc     MOV        dword ptr [ESI + 0x88],EDX
    //         0040a2c2     MOV        EAX,dword ptr [EDI + 0x8c]
    //         0040a2c8     MOV        dword ptr [ESI + 0x8c],EAX
    //         0040a2ce     MOV        this,dword ptr [EDI + 0x90]
    //         0040a2d4     MOV        dword ptr [ESI + 0x90],this
    //         0040a2da     MOV        EDX,dword ptr [EDI + 0x94]
    //         0040a2e0     MOV        dword ptr [ESI + 0x94],EDX
    //         0040a2e6     MOV        EAX,dword ptr [EDI + 0x98]
    //                              aibobj.cpp:143 (36)
    //         0040a2ec     MOV        EDX,dword ptr [ESI + 0xc]
    //         0040a2ef     MOV        dword ptr [ESI + 0x98],EAX
    //         0040a2f5     MOV        this,dword ptr [EDI + 0x9c]
    //         0040a2fb     MOV        dword ptr [ESI],BaseObject::`vftable'            = 0040a040
    //         0040a301     SHL        EDX,0x2
    //         0040a304     PUSH       EDX
    //         0040a305     MOV        dword ptr [ESI + 0x9c],this
    //         0040a30b     CALL       operator_new                                     void * operator_new(uint param_1)
    //                              aibobj.cpp:144 (15)
    //         0040a310     MOV        this,dword ptr [ESI + 0xc]
    //         0040a313     MOV        dword ptr [ESI + 0x10],EAX
    //         0040a316     ADD        ESP,0x4
    //         0040a319     XOR        EAX,EAX
    //         0040a31b     TEST       this,this
    //         0040a31d     JLE        LAB_0040a333
    //                               LAB_0040a31f                                                 XREF[1]:     0040a331(j)  
    //                              aibobj.cpp:145 (20)
    //         0040a31f     MOV        this,dword ptr [EDI + 0x10]
    //         0040a322     MOV        EDX,dword ptr [ESI + 0x10]
    //         0040a325     MOV        this,dword ptr [this->_padding_ + EAX*0x4]
    //         0040a328     MOV        dword ptr [EDX + EAX*0x4],this
    //         0040a32b     MOV        this,dword ptr [ESI + 0xc]
    //         0040a32e     INC        EAX
    //         0040a32f     CMP        EAX,this
    //         0040a331     JL         LAB_0040a31f
    //                               LAB_0040a333                                                 XREF[1]:     0040a31d(j)  
    //                              aibobj.cpp:147 (18)
    //         0040a333     ADD        EDI,0x20
    //         0040a336     PUSH       0x3f
    //         0040a338     LEA        EDX,[ESI + 0x20]
    //         0040a33b     PUSH       EDI
    //         0040a33c     PUSH       EDX
    //         0040a33d     CALL       strncpy                                          undefined strncpy()
    //         0040a342     ADD        ESP,0xc
    //                              aibobj.cpp:148 (7)
    //         0040a345     MOV        EAX,ESI
    //         0040a347     POP        EDI
    //         0040a348     POP        ESI
    //         0040a349     RET        0x4
}

// Offset: 0x0040A350
void BaseObject(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall BaseObject::~BaseObject(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~BaseObject(BaseObject * this)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ??1BaseObject@@UAE@XZ                                        XREF[1]:     `vector_deleting_destructor':0040a
    //                               BaseObject::~BaseObject
    //                              aibobj.cpp:153 (18)
    //         0040a350     MOV        EAX,dword ptr [ECX + this->groupIDValue]
    //         0040a353     MOV        dword ptr [this->_padding_],BaseObject::`vftab   = 0040a040
    //         0040a359     PUSH       EAX
    //         0040a35a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040a35f     ADD        ESP,0x4
    //                              aibobj.cpp:155 (1)
    //         0040a362     RET
}

// Offset: 0x0040A370
int operator(BaseObject* param_1, BaseObject* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator==(class BaseObject const &,class BaseObject const &)                             *
    //                              *********************************************************************************************************
    //                              int __cdecl operator==(BaseObject * param_1, BaseObject * param_2)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      Stack[0x4]:4   param_1                   XREF[1]:     0040a370(R)  
    //              BaseObject *      Stack[0x8]:4   param_2                   XREF[1]:     0040a374(R)  
    //                               ??8@YAHABVBaseObject@@0@Z
    //                               operator==
    //                              aibobj.cpp:160 (22)
    //         0040a370     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a374     MOV        EDX,dword ptr [ESP + param_2]
    //         0040a378     PUSH       ESI
    //         0040a379     MOV        ECX,dword ptr [EAX + 0x1c]
    //         0040a37c     MOV        ESI,dword ptr [EDX + 0x1c]
    //         0040a37f     XOR        EAX,EAX
    //         0040a381     CMP        ECX,ESI
    //         0040a383     SETZ       AL
    //                              aibobj.cpp:164 (2)
    //         0040a386     POP        ESI
    //         0040a387     RET
}

// Offset: 0x0040A390
int operator(BaseObject* param_1, BaseObject* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator!=(class BaseObject const &,class BaseObject const &)                             *
    //                              *********************************************************************************************************
    //                              int __cdecl operator!=(BaseObject * param_1, BaseObject * param_2)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      Stack[0x4]:4   param_1                   XREF[1]:     0040a390(R)  
    //              BaseObject *      Stack[0x8]:4   param_2                   XREF[1]:     0040a394(R)  
    //                               ??9@YAHABVBaseObject@@0@Z
    //                               operator!=
    //                              aibobj.cpp:169 (22)
    //         0040a390     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a394     MOV        EDX,dword ptr [ESP + param_2]
    //         0040a398     PUSH       ESI
    //         0040a399     MOV        ECX,dword ptr [EAX + 0x1c]
    //         0040a39c     MOV        ESI,dword ptr [EDX + 0x1c]
    //         0040a39f     XOR        EAX,EAX
    //         0040a3a1     CMP        ECX,ESI
    //         0040a3a3     SETNZ      AL
    //                              aibobj.cpp:173 (2)
    //         0040a3a6     POP        ESI
    //         0040a3a7     RET
}

// Offset: 0x0040A3B0
int operator(BaseObject* param_1, BaseObject* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator<(class BaseObject const &,class BaseObject const &)                              *
    //                              *********************************************************************************************************
    //                              int __cdecl operator<(BaseObject * param_1, BaseObject * param_2)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      Stack[0x4]:4   param_1                   XREF[1]:     0040a3b0(R)  
    //              BaseObject *      Stack[0x8]:4   param_2                   XREF[1]:     0040a3b4(R)  
    //                               ??M@YAHABVBaseObject@@0@Z
    //                               operator<
    //                              aibobj.cpp:178 (22)
    //         0040a3b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a3b4     MOV        EDX,dword ptr [ESP + param_2]
    //         0040a3b8     PUSH       ESI
    //         0040a3b9     MOV        ECX,dword ptr [EAX + 0x1c]
    //         0040a3bc     MOV        ESI,dword ptr [EDX + 0x1c]
    //         0040a3bf     XOR        EAX,EAX
    //         0040a3c1     CMP        ECX,ESI
    //         0040a3c3     SETL       AL
    //                              aibobj.cpp:182 (2)
    //         0040a3c6     POP        ESI
    //         0040a3c7     RET
}

// Offset: 0x0040A3D0
int operator(BaseObject* param_1, BaseObject* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * int __cdecl operator>(class BaseObject const &,class BaseObject const &)                              *
    //                              *********************************************************************************************************
    //                              int __cdecl operator>(BaseObject * param_1, BaseObject * param_2)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      Stack[0x4]:4   param_1                   XREF[1]:     0040a3d0(R)  
    //              BaseObject *      Stack[0x8]:4   param_2                   XREF[1]:     0040a3d4(R)  
    //                               ??O@YAHABVBaseObject@@0@Z
    //                               operator>
    //                              aibobj.cpp:187 (22)
    //         0040a3d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a3d4     MOV        EDX,dword ptr [ESP + param_2]
    //         0040a3d8     PUSH       ESI
    //         0040a3d9     MOV        ECX,dword ptr [EAX + 0x1c]
    //         0040a3dc     MOV        ESI,dword ptr [EDX + 0x1c]
    //         0040a3df     XOR        EAX,EAX
    //         0040a3e1     CMP        ECX,ESI
    //         0040a3e3     SETG       AL
    //                              aibobj.cpp:191 (2)
    //         0040a3e6     POP        ESI
    //         0040a3e7     RET
}

// Offset: 0x0040A3F0
int numberGroups(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::numberGroups(void)const                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall numberGroups(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?numberGroups@BaseObject@@QBEHXZ
    //                               BaseObject::numberGroups
    //                              aibobj.cpp:196 (3)
    //         0040a3f0     MOV        EAX,dword ptr [ECX + this->numberGroupsValue]
    //                              aibobj.cpp:198 (1)
    //         0040a3f3     RET
}

// Offset: 0x0040A400
int groupID(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::groupID(int)const                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall groupID(BaseObject * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a407(R)  
    //                               ?groupID@BaseObject@@QBEHH@Z
    //                               BaseObject::groupID
    //                              aibobj.cpp:203 (20)
    //         0040a400     MOV        EDX,dword ptr [ECX + this->groupIDValue]
    //         0040a403     TEST       EDX,EDX
    //         0040a405     JZ         LAB_0040a41a
    //         0040a407     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a40b     TEST       EAX,EAX
    //         0040a40d     JL         LAB_0040a41a
    //         0040a40f     CMP        EAX,dword ptr [ECX + this->numberGroupsValue]
    //         0040a412     JGE        LAB_0040a41a
    //                              aibobj.cpp:205 (3)
    //         0040a414     MOV        EAX,dword ptr [EDX + EAX*0x4]
    //                              aibobj.cpp:207 (3)
    //         0040a417     RET        0x4
    //                               LAB_0040a41a                                                 XREF[3]:     0040a405(j), 0040a40d(j), 
    //                                                                                                         0040a412(j)  
    //                              aibobj.cpp:206 (3)
    //         0040a41a     OR         EAX,0xffffffff
    //                              aibobj.cpp:207 (3)
    //         0040a41d     RET        0x4
}

// Offset: 0x0040A420
int inGroup(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::inGroup(int)const                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall inGroup(BaseObject * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a42d(R)  
    //                               ?inGroup@BaseObject@@QBEHH@Z                                 XREF[2]:     addGroup:0040a46a(c), 
    //                               BaseObject::inGroup                                                       removeGroup:0040a4ea(c)  
    //                              aibobj.cpp:212 (17)
    //         0040a420     MOV        EDX,dword ptr [ECX + this->numberGroupsValue]
    //         0040a423     XOR        EAX,EAX
    //         0040a425     PUSH       ESI
    //         0040a426     TEST       EDX,EDX
    //         0040a428     JLE        LAB_0040a44c
    //         0040a42a     MOV        this,dword ptr [ECX + this->groupIDValue]
    //         0040a42d     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_0040a431                                                 XREF[1]:     0040a43b(j)  
    //                              aibobj.cpp:214 (12)
    //         0040a431     CMP        dword ptr [this->_padding_],ESI
    //         0040a433     JZ         LAB_0040a443
    //         0040a435     INC        EAX
    //         0040a436     ADD        this,0x4
    //         0040a439     CMP        EAX,EDX
    //         0040a43b     JL         LAB_0040a431
    //                              aibobj.cpp:216 (2)
    //         0040a43d     XOR        EAX,EAX
    //                              aibobj.cpp:217 (4)
    //         0040a43f     POP        ESI
    //         0040a440     RET        0x4
    //                               LAB_0040a443                                                 XREF[1]:     0040a433(j)  
    //                              aibobj.cpp:215 (5)
    //         0040a443     MOV        EAX,0x1
    //                              aibobj.cpp:217 (10)
    //         0040a448     POP        ESI
    //         0040a449     RET        0x4
    //                               LAB_0040a44c                                                 XREF[1]:     0040a428(j)  
    //         0040a44c     XOR        EAX,EAX
    //         0040a44e     POP        ESI
    //         0040a44f     RET        0x4
}

// Offset: 0x0040A460
int addGroup(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::addGroup(int)                                                      *
    //                              *********************************************************************************************************
    //                              int __thiscall addGroup(BaseObject * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a461(R)  
    //                               ?addGroup@BaseObject@@QAEHH@Z
    //                               BaseObject::addGroup
    //                              aibobj.cpp:222 (1)
    //         0040a460     PUSH       EBX
    //                              aibobj.cpp:225 (18)
    //         0040a461     MOV        EBX,dword ptr [ESP + param_1]
    //         0040a465     PUSH       ESI
    //         0040a466     PUSH       EDI
    //         0040a467     MOV        ESI,this
    //         0040a469     PUSH       EBX
    //         0040a46a     CALL       BaseObject::inGroup                              int inGroup(BaseObject * this, int param_1)
    //         0040a46f     TEST       EAX,EAX
    //         0040a471     JZ         LAB_0040a47b
    //                              aibobj.cpp:226 (2)
    //         0040a473     XOR        EAX,EAX
    //                              aibobj.cpp:239 (6)
    //         0040a475     POP        EDI
    //         0040a476     POP        ESI
    //         0040a477     POP        EBX
    //         0040a478     RET        0x4
    //                               LAB_0040a47b                                                 XREF[1]:     0040a471(j)  
    //                              aibobj.cpp:228 (21)
    //         0040a47b     MOV        EAX,dword ptr [ESI + 0xc]
    //         0040a47e     LEA        this,[EAX*0x4 + 0x4]
    //         0040a485     PUSH       this
    //         0040a486     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040a48b     MOV        EDI,EAX
    //         0040a48d     ADD        ESP,0x4
    //                              aibobj.cpp:229 (4)
    //         0040a490     TEST       EDI,EDI
    //         0040a492     JNZ        LAB_0040a49a
    //                              aibobj.cpp:239 (6)
    //         0040a494     POP        EDI
    //         0040a495     POP        ESI
    //         0040a496     POP        EBX
    //         0040a497     RET        0x4
    //                               LAB_0040a49a                                                 XREF[1]:     0040a492(j)  
    //                              aibobj.cpp:231 (9)
    //         0040a49a     MOV        this,dword ptr [ESI + 0xc]
    //         0040a49d     XOR        EAX,EAX
    //         0040a49f     TEST       this,this
    //         0040a4a1     JLE        LAB_0040a4b6
    //                               LAB_0040a4a3                                                 XREF[1]:     0040a4b4(j)  
    //                              aibobj.cpp:232 (19)
    //         0040a4a3     MOV        EDX,dword ptr [ESI + 0x10]
    //         0040a4a6     INC        EAX
    //         0040a4a7     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         0040a4ab     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         0040a4af     MOV        this,dword ptr [ESI + 0xc]
    //         0040a4b2     CMP        EAX,this
    //         0040a4b4     JL         LAB_0040a4a3
    //                               LAB_0040a4b6                                                 XREF[1]:     0040a4a1(j)  
    //                              aibobj.cpp:233 (6)
    //         0040a4b6     MOV        EDX,dword ptr [ESI + 0xc]
    //         0040a4b9     MOV        dword ptr [EDI + EDX*0x4],EBX
    //                              aibobj.cpp:234 (3)
    //         0040a4bc     MOV        EDX,dword ptr [ESI + 0xc]
    //                              aibobj.cpp:236 (16)
    //         0040a4bf     MOV        EAX,dword ptr [ESI + 0x10]
    //         0040a4c2     INC        EDX
    //         0040a4c3     PUSH       EAX
    //         0040a4c4     MOV        dword ptr [ESI + 0xc],EDX
    //         0040a4c7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040a4cc     ADD        ESP,0x4
    //                              aibobj.cpp:237 (3)
    //         0040a4cf     MOV        dword ptr [ESI + 0x10],EDI
    //                              aibobj.cpp:238 (5)
    //         0040a4d2     MOV        EAX,0x1
    //                              aibobj.cpp:239 (6)
    //         0040a4d7     POP        EDI
    //         0040a4d8     POP        ESI
    //         0040a4d9     POP        EBX
    //         0040a4da     RET        0x4
}

// Offset: 0x0040A4E0
int removeGroup(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::removeGroup(int)                                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall removeGroup(BaseObject * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a4e3(R)  
    //                               ?removeGroup@BaseObject@@QAEHH@Z
    //                               BaseObject::removeGroup
    //                              aibobj.cpp:244 (3)
    //         0040a4e0     PUSH       EBX
    //         0040a4e1     PUSH       ESI
    //         0040a4e2     PUSH       EDI
    //                              aibobj.cpp:247 (16)
    //         0040a4e3     MOV        EDI,dword ptr [ESP + param_1]
    //         0040a4e7     MOV        ESI,this
    //         0040a4e9     PUSH       EDI
    //         0040a4ea     CALL       BaseObject::inGroup                              int inGroup(BaseObject * this, int param_1)
    //         0040a4ef     TEST       EAX,EAX
    //         0040a4f1     JNZ        LAB_0040a4f9
    //                              aibobj.cpp:262 (6)
    //         0040a4f3     POP        EDI
    //         0040a4f4     POP        ESI
    //         0040a4f5     POP        EBX
    //         0040a4f6     RET        0x4
    //                               LAB_0040a4f9                                                 XREF[1]:     0040a4f1(j)  
    //                              aibobj.cpp:251 (21)
    //         0040a4f9     MOV        EAX,dword ptr [ESI + 0xc]
    //         0040a4fc     LEA        this,[EAX*0x4 + 0xfffffffc]
    //         0040a503     PUSH       this
    //         0040a504     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0040a509     MOV        EBX,EAX
    //         0040a50b     ADD        ESP,0x4
    //                              aibobj.cpp:252 (4)
    //         0040a50e     TEST       EBX,EBX
    //         0040a510     JNZ        LAB_0040a518
    //                              aibobj.cpp:262 (6)
    //         0040a512     POP        EDI
    //         0040a513     POP        ESI
    //         0040a514     POP        EBX
    //         0040a515     RET        0x4
    //                               LAB_0040a518                                                 XREF[1]:     0040a510(j)  
    //                              aibobj.cpp:254 (9)
    //         0040a518     MOV        EAX,dword ptr [ESI + 0xc]
    //         0040a51b     XOR        this,this
    //         0040a51d     TEST       EAX,EAX
    //         0040a51f     JLE        LAB_0040a53a
    //                              aibobj.cpp:262 (2)
    //         0040a521     MOV        EDX,EBX
    //                               LAB_0040a523                                                 XREF[1]:     0040a538(j)  
    //                              aibobj.cpp:255 (10)
    //         0040a523     MOV        EAX,dword ptr [ESI + 0x10]
    //         0040a526     MOV        EAX,dword ptr [EAX + this->_padding_*0x4]
    //         0040a529     CMP        EAX,EDI
    //         0040a52b     JZ         LAB_0040a532
    //                              aibobj.cpp:256 (13)
    //         0040a52d     MOV        dword ptr [EDX],EAX
    //         0040a52f     ADD        EDX,0x4
    //                               LAB_0040a532                                                 XREF[1]:     0040a52b(j)  
    //         0040a532     MOV        EAX,dword ptr [ESI + 0xc]
    //         0040a535     INC        this
    //         0040a536     CMP        this,EAX
    //         0040a538     JL         LAB_0040a523
    //                               LAB_0040a53a                                                 XREF[1]:     0040a51f(j)  
    //                              aibobj.cpp:257 (3)
    //         0040a53a     MOV        EDI,dword ptr [ESI + 0xc]
    //                              aibobj.cpp:259 (16)
    //         0040a53d     MOV        this,dword ptr [ESI + 0x10]
    //         0040a540     DEC        EDI
    //         0040a541     PUSH       this
    //         0040a542     MOV        dword ptr [ESI + 0xc],EDI
    //         0040a545     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0040a54a     ADD        ESP,0x4
    //                              aibobj.cpp:260 (3)
    //         0040a54d     MOV        dword ptr [ESI + 0x10],EBX
    //                              aibobj.cpp:261 (5)
    //         0040a550     MOV        EAX,0x1
    //                              aibobj.cpp:262 (6)
    //         0040a555     POP        EDI
    //         0040a556     POP        ESI
    //         0040a557     POP        EBX
    //         0040a558     RET        0x4
}

// Offset: 0x0040A560
int categoryID(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::categoryID(void)const                                              *
    //                              *********************************************************************************************************
    //                              int __thiscall categoryID(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?categoryID@BaseObject@@QBEHXZ
    //                               BaseObject::categoryID
    //                              aibobj.cpp:267 (3)
    //         0040a560     MOV        EAX,dword ptr [ECX + this->categoryIDValue]
    //                              aibobj.cpp:269 (1)
    //         0040a563     RET
}

// Offset: 0x0040A570
int typeID(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::typeID(void)const                                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall typeID(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?typeID@BaseObject@@QBEHXZ
    //                               BaseObject::typeID
    //                              aibobj.cpp:274 (3)
    //         0040a570     MOV        EAX,dword ptr [ECX + this->typeIDValue]
    //                              aibobj.cpp:276 (1)
    //         0040a573     RET
}

// Offset: 0x0040A580
int* gameID(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int const & __thiscall BaseObject::gameID(void)const                                          *
    //                              *********************************************************************************************************
    //                              int * __thiscall gameID(BaseObject * this)
    //              int *             EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?gameID@BaseObject@@QBEABHXZ
    //                               BaseObject::gameID
    //                              aibobj.cpp:281 (3)
    //         0040a580     LEA        EAX,[ECX + this->gameIDValue]
    //                              aibobj.cpp:283 (1)
    //         0040a583     RET
}

// Offset: 0x0040A590
char* name(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall BaseObject::name(void)                                                      *
    //                              *********************************************************************************************************
    //                              char * __thiscall name(BaseObject * this)
    //              char *            EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?name@BaseObject@@QAEPADXZ
    //                               BaseObject::name
    //                              aibobj.cpp:288 (3)
    //         0040a590     LEA        EAX,[ECX + this->nameValue[0]]
    //                              aibobj.cpp:290 (1)
    //         0040a593     RET
}

// Offset: 0x0040A5A0
float xPosition(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::xPosition(void)const                                             *
    //                              *********************************************************************************************************
    //                              float __thiscall xPosition(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?xPosition@BaseObject@@QBEMXZ
    //                               BaseObject::xPosition
    //                              aibobj.cpp:295 (3)
    //         0040a5a0     FLD        float ptr [ECX + this->xPositionValue]
    //                              aibobj.cpp:297 (1)
    //         0040a5a3     RET
}

// Offset: 0x0040A5B0
float yPosition(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::yPosition(void)const                                             *
    //                              *********************************************************************************************************
    //                              float __thiscall yPosition(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?yPosition@BaseObject@@QBEMXZ
    //                               BaseObject::yPosition
    //                              aibobj.cpp:302 (3)
    //         0040a5b0     FLD        float ptr [ECX + this->yPositionValue]
    //                              aibobj.cpp:304 (1)
    //         0040a5b3     RET
}

// Offset: 0x0040A5C0
float zPosition(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::zPosition(void)const                                             *
    //                              *********************************************************************************************************
    //                              float __thiscall zPosition(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?zPosition@BaseObject@@QBEMXZ
    //                               BaseObject::zPosition
    //                              aibobj.cpp:309 (3)
    //         0040a5c0     FLD        float ptr [ECX + this->zPositionValue]
    //                              aibobj.cpp:311 (1)
    //         0040a5c3     RET
}

// Offset: 0x0040A5D0
float xSize(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::xSize(void)const                                                 *
    //                              *********************************************************************************************************
    //                              float __thiscall xSize(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?xSize@BaseObject@@QBEMXZ
    //                               BaseObject::xSize
    //                              aibobj.cpp:316 (3)
    //         0040a5d0     FLD        float ptr [ECX + this->xSizeValue]
    //                              aibobj.cpp:318 (1)
    //         0040a5d3     RET
}

// Offset: 0x0040A5E0
float ySize(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::ySize(void)const                                                 *
    //                              *********************************************************************************************************
    //                              float __thiscall ySize(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?ySize@BaseObject@@QBEMXZ
    //                               BaseObject::ySize
    //                              aibobj.cpp:323 (3)
    //         0040a5e0     FLD        float ptr [ECX + this->ySizeValue]
    //                              aibobj.cpp:325 (1)
    //         0040a5e3     RET
}

// Offset: 0x0040A5F0
float zSize(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::zSize(void)const                                                 *
    //                              *********************************************************************************************************
    //                              float __thiscall zSize(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?zSize@BaseObject@@QBEMXZ
    //                               BaseObject::zSize
    //                              aibobj.cpp:330 (3)
    //         0040a5f0     FLD        float ptr [ECX + this->zSizeValue]
    //                              aibobj.cpp:332 (1)
    //         0040a5f3     RET
}

// Offset: 0x0040A600
int hitPoints(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::hitPoints(void)const                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall hitPoints(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?hitPoints@BaseObject@@QBEHXZ
    //                               BaseObject::hitPoints
    //                              aibobj.cpp:337 (3)
    //         0040a600     MOV        EAX,dword ptr [ECX + this->hitPointValue]
    //                              aibobj.cpp:339 (1)
    //         0040a603     RET
}

// Offset: 0x0040A610
int minHitPoints(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::minHitPoints(void)const                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall minHitPoints(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?minHitPoints@BaseObject@@QBEHXZ
    //                               BaseObject::minHitPoints
    //                              aibobj.cpp:344 (3)
    //         0040a610     MOV        EAX,dword ptr [ECX + this->minHitPointValue]
    //                              aibobj.cpp:346 (1)
    //         0040a613     RET
}

// Offset: 0x0040A620
int maxHitPoints(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::maxHitPoints(void)const                                            *
    //                              *********************************************************************************************************
    //                              int __thiscall maxHitPoints(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?maxHitPoints@BaseObject@@QBEHXZ
    //                               BaseObject::maxHitPoints
    //                              aibobj.cpp:351 (6)
    //         0040a620     MOV        EAX,dword ptr [ECX + this->maxHitPointValue]
    //                              aibobj.cpp:353 (1)
    //         0040a626     RET
}

// Offset: 0x0040A630
int busy(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::busy(void)const                                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall busy(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?busy@BaseObject@@QBEHXZ
    //                               BaseObject::busy
    //                              aibobj.cpp:358 (6)
    //         0040a630     MOV        EAX,dword ptr [ECX + this->busyValue]
    //                              aibobj.cpp:360 (1)
    //         0040a636     RET
}

// Offset: 0x0040A640
int currentTask(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::currentTask(void)const                                             *
    //                              *********************************************************************************************************
    //                              int __thiscall currentTask(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?currentTask@BaseObject@@QBEHXZ
    //                               BaseObject::currentTask
    //                              aibobj.cpp:365 (6)
    //         0040a640     MOV        EAX,dword ptr [ECX + this->currentTaskValue]
    //                              aibobj.cpp:367 (1)
    //         0040a646     RET
}

// Offset: 0x0040A650
int currentTarget(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::currentTarget(void)const                                           *
    //                              *********************************************************************************************************
    //                              int __thiscall currentTarget(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?currentTarget@BaseObject@@QBEHXZ
    //                               BaseObject::currentTarget
    //                              aibobj.cpp:372 (6)
    //         0040a650     MOV        EAX,dword ptr [ECX + this->currentTargetValue]
    //                              aibobj.cpp:374 (1)
    //         0040a656     RET
}

// Offset: 0x0040A660
int currentTargetType(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall BaseObject::currentTargetType(void)const                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall currentTargetType(BaseObject * this)
    //              int               EAX:4          <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?currentTargetType@BaseObject@@QBEHXZ
    //                               BaseObject::currentTargetType
    //                              aibobj.cpp:379 (6)
    //         0040a660     MOV        EAX,dword ptr [ECX + this->currentTargetTypeVa
    //                              aibobj.cpp:381 (1)
    //         0040a666     RET
}

// Offset: 0x0040A670
float currentTargetXPosition(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::currentTargetXPosition(void)const                                *
    //                              *********************************************************************************************************
    //                              float __thiscall currentTargetXPosition(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?currentTargetXPosition@BaseObject@@QBEMXZ
    //                               BaseObject::currentTargetXPosition
    //                              aibobj.cpp:386 (6)
    //         0040a670     FLD        float ptr [ECX + this->currentTargetXPositionV
    //                              aibobj.cpp:388 (1)
    //         0040a676     RET
}

// Offset: 0x0040A680
float currentTargetYPosition(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::currentTargetYPosition(void)const                                *
    //                              *********************************************************************************************************
    //                              float __thiscall currentTargetYPosition(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?currentTargetYPosition@BaseObject@@QBEMXZ
    //                               BaseObject::currentTargetYPosition
    //                              aibobj.cpp:393 (6)
    //         0040a680     FLD        float ptr [ECX + this->currentTargetYPositionV
    //                              aibobj.cpp:395 (1)
    //         0040a686     RET
}

// Offset: 0x0040A690
float currentTargetZPosition(BaseObject* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: float __thiscall BaseObject::currentTargetZPosition(void)const                                *
    //                              *********************************************************************************************************
    //                              float __thiscall currentTargetZPosition(BaseObject * this)
    //              float             ST0:10         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //                               ?currentTargetZPosition@BaseObject@@QBEMXZ
    //                               BaseObject::currentTargetZPosition
    //                              aibobj.cpp:400 (6)
    //         0040a690     FLD        float ptr [ECX + this->currentTargetZPositionV
    //                              aibobj.cpp:402 (1)
    //         0040a696     RET
}

// Offset: 0x0040A6A0
void setXPosition(BaseObject* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setXPosition(float)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setXPosition(BaseObject * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a6a0(R)  
    //                               ?setXPosition@BaseObject@@QAEXM@Z
    //                               BaseObject::setXPosition
    //                              aibobj.cpp:407 (7)
    //         0040a6a0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a6a4     MOV        dword ptr [ECX + this->xPositionValue],EAX
    //                              aibobj.cpp:409 (3)
    //         0040a6a7     RET        0x4
}

// Offset: 0x0040A6B0
void setYPosition(BaseObject* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setYPosition(float)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setYPosition(BaseObject * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a6b0(R)  
    //                               ?setYPosition@BaseObject@@QAEXM@Z
    //                               BaseObject::setYPosition
    //                              aibobj.cpp:414 (7)
    //         0040a6b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a6b4     MOV        dword ptr [ECX + this->yPositionValue],EAX
    //                              aibobj.cpp:416 (3)
    //         0040a6b7     RET        0x4
}

// Offset: 0x0040A6C0
void setZPosition(BaseObject* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setZPosition(float)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setZPosition(BaseObject * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a6c0(R)  
    //                               ?setZPosition@BaseObject@@QAEXM@Z
    //                               BaseObject::setZPosition
    //                              aibobj.cpp:421 (7)
    //         0040a6c0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a6c4     MOV        dword ptr [ECX + this->zPositionValue],EAX
    //                              aibobj.cpp:423 (3)
    //         0040a6c7     RET        0x4
}

// Offset: 0x0040A6D0
void setXSize(BaseObject* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setXSize(float)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall setXSize(BaseObject * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a6d0(R)  
    //                               ?setXSize@BaseObject@@QAEXM@Z
    //                               BaseObject::setXSize
    //                              aibobj.cpp:428 (7)
    //         0040a6d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a6d4     MOV        dword ptr [ECX + this->xSizeValue],EAX
    //                              aibobj.cpp:430 (3)
    //         0040a6d7     RET        0x4
}

// Offset: 0x0040A6E0
void setYSize(BaseObject* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setYSize(float)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall setYSize(BaseObject * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a6e0(R)  
    //                               ?setYSize@BaseObject@@QAEXM@Z
    //                               BaseObject::setYSize
    //                              aibobj.cpp:435 (7)
    //         0040a6e0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a6e4     MOV        dword ptr [ECX + this->ySizeValue],EAX
    //                              aibobj.cpp:437 (3)
    //         0040a6e7     RET        0x4
}

// Offset: 0x0040A6F0
void setZSize(BaseObject* this_, float param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setZSize(float)                                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall setZSize(BaseObject * this, float param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a6f0(R)  
    //                               ?setZSize@BaseObject@@QAEXM@Z
    //                               BaseObject::setZSize
    //                              aibobj.cpp:442 (7)
    //         0040a6f0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a6f4     MOV        dword ptr [ECX + this->zSizeValue],EAX
    //                              aibobj.cpp:444 (3)
    //         0040a6f7     RET        0x4
}

// Offset: 0x0040A700
void setHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setHitPoints(int)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall setHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a700(R)  
    //                               ?setHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::setHitPoints
    //                              aibobj.cpp:449 (7)
    //         0040a700     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a704     MOV        dword ptr [ECX + this->hitPointValue],EAX
    //                              aibobj.cpp:451 (3)
    //         0040a707     RET        0x4
}

// Offset: 0x0040A710
void incrementHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::incrementHitPoints(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a710(R)  
    //                               ?incrementHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::incrementHitPoints
    //                              aibobj.cpp:456 (12)
    //         0040a710     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a714     MOV        EDX,dword ptr [ECX + this->hitPointValue]
    //         0040a717     ADD        EDX,EAX
    //         0040a719     MOV        dword ptr [ECX + this->hitPointValue],EDX
    //                              aibobj.cpp:458 (3)
    //         0040a71c     RET        0x4
}

// Offset: 0x0040A720
void decrementHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::decrementHitPoints(int)                                           *
    //                              *********************************************************************************************************
    //                              void __thiscall decrementHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a720(R)  
    //                               ?decrementHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::decrementHitPoints
    //                              aibobj.cpp:463 (12)
    //         0040a720     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a724     MOV        EDX,dword ptr [ECX + this->hitPointValue]
    //         0040a727     SUB        EDX,EAX
    //         0040a729     MOV        dword ptr [ECX + this->hitPointValue],EDX
    //                              aibobj.cpp:465 (3)
    //         0040a72c     RET        0x4
}

// Offset: 0x0040A730
void setMinHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setMinHitPoints(int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall setMinHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a730(R)  
    //                               ?setMinHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::setMinHitPoints
    //                              aibobj.cpp:470 (7)
    //         0040a730     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a734     MOV        dword ptr [ECX + this->minHitPointValue],EAX
    //                              aibobj.cpp:472 (3)
    //         0040a737     RET        0x4
}

// Offset: 0x0040A740
void incrementMinHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::incrementMinHitPoints(int)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementMinHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a740(R)  
    //                               ?incrementMinHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::incrementMinHitPoints
    //                              aibobj.cpp:477 (12)
    //         0040a740     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a744     MOV        EDX,dword ptr [ECX + this->minHitPointValue]
    //         0040a747     ADD        EDX,EAX
    //         0040a749     MOV        dword ptr [ECX + this->minHitPointValue],EDX
    //                              aibobj.cpp:479 (3)
    //         0040a74c     RET        0x4
}

// Offset: 0x0040A750
void decrementMinHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::decrementMinHitPoints(int)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall decrementMinHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a750(R)  
    //                               ?decrementMinHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::decrementMinHitPoints
    //                              aibobj.cpp:484 (12)
    //         0040a750     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a754     MOV        EDX,dword ptr [ECX + this->minHitPointValue]
    //         0040a757     SUB        EDX,EAX
    //         0040a759     MOV        dword ptr [ECX + this->minHitPointValue],EDX
    //                              aibobj.cpp:486 (3)
    //         0040a75c     RET        0x4
}

// Offset: 0x0040A760
void setMaxHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setMaxHitPoints(int)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall setMaxHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a760(R)  
    //                               ?setMaxHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::setMaxHitPoints
    //                              aibobj.cpp:491 (10)
    //         0040a760     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a764     MOV        dword ptr [ECX + this->maxHitPointValue],EAX
    //                              aibobj.cpp:493 (3)
    //         0040a76a     RET        0x4
}

// Offset: 0x0040A770
void incrementMaxHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::incrementMaxHitPoints(int)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall incrementMaxHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a770(R)  
    //                               ?incrementMaxHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::incrementMaxHitPoints
    //                              aibobj.cpp:498 (18)
    //         0040a770     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a774     MOV        EDX,dword ptr [ECX + this->maxHitPointValue]
    //         0040a77a     ADD        EDX,EAX
    //         0040a77c     MOV        dword ptr [ECX + this->maxHitPointValue],EDX
    //                              aibobj.cpp:500 (3)
    //         0040a782     RET        0x4
}

// Offset: 0x0040A790
void decrementMaxHitPoints(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::decrementMaxHitPoints(int)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall decrementMaxHitPoints(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a790(R)  
    //                               ?decrementMaxHitPoints@BaseObject@@QAEXH@Z
    //                               BaseObject::decrementMaxHitPoints
    //                              aibobj.cpp:505 (18)
    //         0040a790     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a794     MOV        EDX,dword ptr [ECX + this->maxHitPointValue]
    //         0040a79a     SUB        EDX,EAX
    //         0040a79c     MOV        dword ptr [ECX + this->maxHitPointValue],EDX
    //                              aibobj.cpp:507 (3)
    //         0040a7a2     RET        0x4
}

// Offset: 0x0040A7B0
void setBusy(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setBusy(int)                                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall setBusy(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a7b0(R)  
    //                               ?setBusy@BaseObject@@QAEXH@Z
    //                               BaseObject::setBusy
    //                              aibobj.cpp:512 (10)
    //         0040a7b0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a7b4     MOV        dword ptr [ECX + this->busyValue],EAX
    //                              aibobj.cpp:514 (3)
    //         0040a7ba     RET        0x4
}

// Offset: 0x0040A7C0
void setCurrentTask(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setCurrentTask(int)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setCurrentTask(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a7c0(R)  
    //                               ?setCurrentTask@BaseObject@@QAEXH@Z
    //                               BaseObject::setCurrentTask
    //                              aibobj.cpp:519 (10)
    //         0040a7c0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a7c4     MOV        dword ptr [ECX + this->currentTaskValue],EAX
    //                              aibobj.cpp:521 (3)
    //         0040a7ca     RET        0x4
}

// Offset: 0x0040A7D0
void setCurrentTarget(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setCurrentTarget(int)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall setCurrentTarget(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a7d0(R)  
    //                               ?setCurrentTarget@BaseObject@@QAEXH@Z
    //                               BaseObject::setCurrentTarget
    //                              aibobj.cpp:526 (10)
    //         0040a7d0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a7d4     MOV        dword ptr [ECX + this->currentTargetValue],EAX
    //                              aibobj.cpp:528 (3)
    //         0040a7da     RET        0x4
}

// Offset: 0x0040A7E0
void setCurrentTargetType(BaseObject* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setCurrentTargetType(int)                                         *
    //                              *********************************************************************************************************
    //                              void __thiscall setCurrentTargetType(BaseObject * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0040a7e0(R)  
    //                               ?setCurrentTargetType@BaseObject@@QAEXH@Z
    //                               BaseObject::setCurrentTargetType
    //                              aibobj.cpp:533 (10)
    //         0040a7e0     MOV        EAX,dword ptr [ESP + param_1]
    //         0040a7e4     MOV        dword ptr [ECX + this->currentTargetTypeValue]
    //                              aibobj.cpp:535 (3)
    //         0040a7ea     RET        0x4
}

// Offset: 0x0040A7F0
void setCurrentTargetPosition(BaseObject* this_, float param_2, float param_3, float param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall BaseObject::setCurrentTargetPosition(float,float,float)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall setCurrentTargetPosition(BaseObject * this, float pa
    //              void              <VOID>         <RETURN>
    //              BaseObject *      ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[1]:     0040a7f0(R)  
    //              float             Stack[0x8]:4   param_2                   XREF[1]:     0040a7f4(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     0040a7fe(R)  
    //                               ?setCurrentTargetPosition@BaseObject@@QAEXMMM@Z
    //                               BaseObject::setCurrentTargetPosition
    //                              aibobj.cpp:540 (4)
    //         0040a7f0     MOV        EAX,dword ptr [ESP + param_1]
    //                              aibobj.cpp:542 (10)
    //         0040a7f4     MOV        EDX,dword ptr [ESP + param_2]
    //         0040a7f8     MOV        dword ptr [ECX + this->currentTargetXPositionV
    //                              aibobj.cpp:543 (16)
    //         0040a7fe     MOV        EAX,dword ptr [ESP + param_3]
    //         0040a802     MOV        dword ptr [ECX + this->currentTargetYPositionV
    //         0040a808     MOV        dword ptr [ECX + this->currentTargetZPositionV
    //                              aibobj.cpp:544 (3)
    //         0040a80e     RET        0xc
}

