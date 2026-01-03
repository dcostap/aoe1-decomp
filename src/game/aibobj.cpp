#include "../common.h"
#include "aibobj.h"

BaseObject::BaseObject() {
    /* TODO: Stub */
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
//         0040a038     ??         90h
//         0040a039     NOP
//         0040a03a     NOP
//         0040a03b     NOP
//         0040a03c     NOP
//         0040a03d     NOP
//         0040a03e     NOP
//         0040a03f     NOP
}

BaseObject::BaseObject(int param_1, int param_2, int param_3, int param_4, char* param_5, float param_6, float param_7, float param_8, float param_9, float param_10, float param_11, int param_12, int param_13, int param_14) {
    /* TODO: Stub */
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
//         0040a128     ??         90h
//         0040a129     NOP
//         0040a12a     NOP
//         0040a12b     NOP
//         0040a12c     NOP
//         0040a12d     NOP
//         0040a12e     NOP
//         0040a12f     NOP
}

BaseObject::BaseObject(BaseObject* param_1) {
    /* TODO: Stub */
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
//         0040a23c     ??         90h
//         0040a23d     NOP
//         0040a23e     NOP
//         0040a23f     NOP
}

BaseObject::BaseObject(BaseObject* param_1) {
    /* TODO: Stub */
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
//         0040a34c     ??         90h
//         0040a34d     NOP
//         0040a34e     NOP
//         0040a34f     NOP
}

BaseObject::~BaseObject() {
    /* TODO: Stub */
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
//         0040a363     ??         90h
//         0040a364     NOP
//         0040a365     NOP
//         0040a366     NOP
//         0040a367     NOP
//         0040a368     NOP
//         0040a369     NOP
//         0040a36a     NOP
//         0040a36b     NOP
//         0040a36c     NOP
//         0040a36d     NOP
//         0040a36e     NOP
//         0040a36f     NOP
}

int BaseObject::numberGroups() {
    /* TODO: Stub */
//                              int __thiscall numberGroups(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?numberGroups@BaseObject@@QBEHXZ
//                               BaseObject::numberGroups
//                              aibobj.cpp:196 (3)
//         0040a3f0     MOV        EAX,dword ptr [ECX + this->numberGroupsValue]
//                              aibobj.cpp:198 (1)
//         0040a3f3     RET
//         0040a3f4     ??         90h
//         0040a3f5     NOP
//         0040a3f6     NOP
//         0040a3f7     NOP
//         0040a3f8     NOP
//         0040a3f9     NOP
//         0040a3fa     NOP
//         0040a3fb     NOP
//         0040a3fc     NOP
//         0040a3fd     NOP
//         0040a3fe     NOP
//         0040a3ff     NOP
    return 0;
}

int BaseObject::groupID(int param_1) {
    /* TODO: Stub */
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
    return 0;
}

int BaseObject::inGroup(int param_1) {
    /* TODO: Stub */
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
//         0040a452     ??         90h
//         0040a453     NOP
//         0040a454     NOP
//         0040a455     NOP
//         0040a456     NOP
//         0040a457     NOP
//         0040a458     NOP
//         0040a459     NOP
//         0040a45a     NOP
//         0040a45b     NOP
//         0040a45c     NOP
//         0040a45d     NOP
//         0040a45e     NOP
//         0040a45f     NOP
    return 0;
}

int BaseObject::addGroup(int param_1) {
    /* TODO: Stub */
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
//         0040a4dd     ??         90h
//         0040a4de     NOP
//         0040a4df     NOP
    return 0;
}

int BaseObject::removeGroup(int param_1) {
    /* TODO: Stub */
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
//         0040a55b     ??         90h
//         0040a55c     NOP
//         0040a55d     NOP
//         0040a55e     NOP
//         0040a55f     NOP
    return 0;
}

int BaseObject::categoryID() {
    /* TODO: Stub */
//                              int __thiscall categoryID(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?categoryID@BaseObject@@QBEHXZ
//                               BaseObject::categoryID
//                              aibobj.cpp:267 (3)
//         0040a560     MOV        EAX,dword ptr [ECX + this->categoryIDValue]
//                              aibobj.cpp:269 (1)
//         0040a563     RET
//         0040a564     ??         90h
//         0040a565     NOP
//         0040a566     NOP
//         0040a567     NOP
//         0040a568     NOP
//         0040a569     NOP
//         0040a56a     NOP
//         0040a56b     NOP
//         0040a56c     NOP
//         0040a56d     NOP
//         0040a56e     NOP
//         0040a56f     NOP
    return 0;
}

int BaseObject::typeID() {
    /* TODO: Stub */
//                              int __thiscall typeID(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?typeID@BaseObject@@QBEHXZ
//                               BaseObject::typeID
//                              aibobj.cpp:274 (3)
//         0040a570     MOV        EAX,dword ptr [ECX + this->typeIDValue]
//                              aibobj.cpp:276 (1)
//         0040a573     RET
//         0040a574     ??         90h
//         0040a575     NOP
//         0040a576     NOP
//         0040a577     NOP
//         0040a578     NOP
//         0040a579     NOP
//         0040a57a     NOP
//         0040a57b     NOP
//         0040a57c     NOP
//         0040a57d     NOP
//         0040a57e     NOP
//         0040a57f     NOP
    return 0;
}

int* BaseObject::gameID() {
    /* TODO: Stub */
//                              int * __thiscall gameID(BaseObject * this)
//              int *             EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?gameID@BaseObject@@QBEABHXZ
//                               BaseObject::gameID
//                              aibobj.cpp:281 (3)
//         0040a580     LEA        EAX,[ECX + this->gameIDValue]
//                              aibobj.cpp:283 (1)
//         0040a583     RET
//         0040a584     ??         90h
//         0040a585     NOP
//         0040a586     NOP
//         0040a587     NOP
//         0040a588     NOP
//         0040a589     NOP
//         0040a58a     NOP
//         0040a58b     NOP
//         0040a58c     NOP
//         0040a58d     NOP
//         0040a58e     NOP
//         0040a58f     NOP
    return 0;
}

char* BaseObject::name() {
    /* TODO: Stub */
//                              char * __thiscall name(BaseObject * this)
//              char *            EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?name@BaseObject@@QAEPADXZ
//                               BaseObject::name
//                              aibobj.cpp:288 (3)
//         0040a590     LEA        EAX,[ECX + this->nameValue[0]]
//                              aibobj.cpp:290 (1)
//         0040a593     RET
//         0040a594     ??         90h
//         0040a595     NOP
//         0040a596     NOP
//         0040a597     NOP
//         0040a598     NOP
//         0040a599     NOP
//         0040a59a     NOP
//         0040a59b     NOP
//         0040a59c     NOP
//         0040a59d     NOP
//         0040a59e     NOP
//         0040a59f     NOP
    return 0;
}

float BaseObject::xPosition() {
    /* TODO: Stub */
//                              float __thiscall xPosition(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?xPosition@BaseObject@@QBEMXZ
//                               BaseObject::xPosition
//                              aibobj.cpp:295 (3)
//         0040a5a0     FLD        float ptr [ECX + this->xPositionValue]
//                              aibobj.cpp:297 (1)
//         0040a5a3     RET
//         0040a5a4     ??         90h
//         0040a5a5     NOP
//         0040a5a6     NOP
//         0040a5a7     NOP
//         0040a5a8     NOP
//         0040a5a9     NOP
//         0040a5aa     NOP
//         0040a5ab     NOP
//         0040a5ac     NOP
//         0040a5ad     NOP
//         0040a5ae     NOP
//         0040a5af     NOP
    return 0;
}

float BaseObject::yPosition() {
    /* TODO: Stub */
//                              float __thiscall yPosition(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?yPosition@BaseObject@@QBEMXZ
//                               BaseObject::yPosition
//                              aibobj.cpp:302 (3)
//         0040a5b0     FLD        float ptr [ECX + this->yPositionValue]
//                              aibobj.cpp:304 (1)
//         0040a5b3     RET
//         0040a5b4     ??         90h
//         0040a5b5     NOP
//         0040a5b6     NOP
//         0040a5b7     NOP
//         0040a5b8     NOP
//         0040a5b9     NOP
//         0040a5ba     NOP
//         0040a5bb     NOP
//         0040a5bc     NOP
//         0040a5bd     NOP
//         0040a5be     NOP
//         0040a5bf     NOP
    return 0;
}

float BaseObject::zPosition() {
    /* TODO: Stub */
//                              float __thiscall zPosition(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?zPosition@BaseObject@@QBEMXZ
//                               BaseObject::zPosition
//                              aibobj.cpp:309 (3)
//         0040a5c0     FLD        float ptr [ECX + this->zPositionValue]
//                              aibobj.cpp:311 (1)
//         0040a5c3     RET
//         0040a5c4     ??         90h
//         0040a5c5     NOP
//         0040a5c6     NOP
//         0040a5c7     NOP
//         0040a5c8     NOP
//         0040a5c9     NOP
//         0040a5ca     NOP
//         0040a5cb     NOP
//         0040a5cc     NOP
//         0040a5cd     NOP
//         0040a5ce     NOP
//         0040a5cf     NOP
    return 0;
}

float BaseObject::xSize() {
    /* TODO: Stub */
//                              float __thiscall xSize(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?xSize@BaseObject@@QBEMXZ
//                               BaseObject::xSize
//                              aibobj.cpp:316 (3)
//         0040a5d0     FLD        float ptr [ECX + this->xSizeValue]
//                              aibobj.cpp:318 (1)
//         0040a5d3     RET
//         0040a5d4     ??         90h
//         0040a5d5     NOP
//         0040a5d6     NOP
//         0040a5d7     NOP
//         0040a5d8     NOP
//         0040a5d9     NOP
//         0040a5da     NOP
//         0040a5db     NOP
//         0040a5dc     NOP
//         0040a5dd     NOP
//         0040a5de     NOP
//         0040a5df     NOP
    return 0;
}

float BaseObject::ySize() {
    /* TODO: Stub */
//                              float __thiscall ySize(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?ySize@BaseObject@@QBEMXZ
//                               BaseObject::ySize
//                              aibobj.cpp:323 (3)
//         0040a5e0     FLD        float ptr [ECX + this->ySizeValue]
//                              aibobj.cpp:325 (1)
//         0040a5e3     RET
//         0040a5e4     ??         90h
//         0040a5e5     NOP
//         0040a5e6     NOP
//         0040a5e7     NOP
//         0040a5e8     NOP
//         0040a5e9     NOP
//         0040a5ea     NOP
//         0040a5eb     NOP
//         0040a5ec     NOP
//         0040a5ed     NOP
//         0040a5ee     NOP
//         0040a5ef     NOP
    return 0;
}

float BaseObject::zSize() {
    /* TODO: Stub */
//                              float __thiscall zSize(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?zSize@BaseObject@@QBEMXZ
//                               BaseObject::zSize
//                              aibobj.cpp:330 (3)
//         0040a5f0     FLD        float ptr [ECX + this->zSizeValue]
//                              aibobj.cpp:332 (1)
//         0040a5f3     RET
//         0040a5f4     ??         90h
//         0040a5f5     NOP
//         0040a5f6     NOP
//         0040a5f7     NOP
//         0040a5f8     NOP
//         0040a5f9     NOP
//         0040a5fa     NOP
//         0040a5fb     NOP
//         0040a5fc     NOP
//         0040a5fd     NOP
//         0040a5fe     NOP
//         0040a5ff     NOP
    return 0;
}

int BaseObject::hitPoints() {
    /* TODO: Stub */
//                              int __thiscall hitPoints(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?hitPoints@BaseObject@@QBEHXZ
//                               BaseObject::hitPoints
//                              aibobj.cpp:337 (3)
//         0040a600     MOV        EAX,dword ptr [ECX + this->hitPointValue]
//                              aibobj.cpp:339 (1)
//         0040a603     RET
//         0040a604     ??         90h
//         0040a605     NOP
//         0040a606     NOP
//         0040a607     NOP
//         0040a608     NOP
//         0040a609     NOP
//         0040a60a     NOP
//         0040a60b     NOP
//         0040a60c     NOP
//         0040a60d     NOP
//         0040a60e     NOP
//         0040a60f     NOP
    return 0;
}

int BaseObject::minHitPoints() {
    /* TODO: Stub */
//                              int __thiscall minHitPoints(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?minHitPoints@BaseObject@@QBEHXZ
//                               BaseObject::minHitPoints
//                              aibobj.cpp:344 (3)
//         0040a610     MOV        EAX,dword ptr [ECX + this->minHitPointValue]
//                              aibobj.cpp:346 (1)
//         0040a613     RET
//         0040a614     ??         90h
//         0040a615     NOP
//         0040a616     NOP
//         0040a617     NOP
//         0040a618     NOP
//         0040a619     NOP
//         0040a61a     NOP
//         0040a61b     NOP
//         0040a61c     NOP
//         0040a61d     NOP
//         0040a61e     NOP
//         0040a61f     NOP
    return 0;
}

int BaseObject::maxHitPoints() {
    /* TODO: Stub */
//                              int __thiscall maxHitPoints(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?maxHitPoints@BaseObject@@QBEHXZ
//                               BaseObject::maxHitPoints
//                              aibobj.cpp:351 (6)
//         0040a620     MOV        EAX,dword ptr [ECX + this->maxHitPointValue]
//                              aibobj.cpp:353 (1)
//         0040a626     RET
//         0040a627     ??         90h
//         0040a628     NOP
//         0040a629     NOP
//         0040a62a     NOP
//         0040a62b     NOP
//         0040a62c     NOP
//         0040a62d     NOP
//         0040a62e     NOP
//         0040a62f     NOP
    return 0;
}

int BaseObject::busy() {
    /* TODO: Stub */
//                              int __thiscall busy(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?busy@BaseObject@@QBEHXZ
//                               BaseObject::busy
//                              aibobj.cpp:358 (6)
//         0040a630     MOV        EAX,dword ptr [ECX + this->busyValue]
//                              aibobj.cpp:360 (1)
//         0040a636     RET
//         0040a637     ??         90h
//         0040a638     NOP
//         0040a639     NOP
//         0040a63a     NOP
//         0040a63b     NOP
//         0040a63c     NOP
//         0040a63d     NOP
//         0040a63e     NOP
//         0040a63f     NOP
    return 0;
}

int BaseObject::currentTask() {
    /* TODO: Stub */
//                              int __thiscall currentTask(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?currentTask@BaseObject@@QBEHXZ
//                               BaseObject::currentTask
//                              aibobj.cpp:365 (6)
//         0040a640     MOV        EAX,dword ptr [ECX + this->currentTaskValue]
//                              aibobj.cpp:367 (1)
//         0040a646     RET
//         0040a647     ??         90h
//         0040a648     NOP
//         0040a649     NOP
//         0040a64a     NOP
//         0040a64b     NOP
//         0040a64c     NOP
//         0040a64d     NOP
//         0040a64e     NOP
//         0040a64f     NOP
    return 0;
}

int BaseObject::currentTarget() {
    /* TODO: Stub */
//                              int __thiscall currentTarget(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?currentTarget@BaseObject@@QBEHXZ
//                               BaseObject::currentTarget
//                              aibobj.cpp:372 (6)
//         0040a650     MOV        EAX,dword ptr [ECX + this->currentTargetValue]
//                              aibobj.cpp:374 (1)
//         0040a656     RET
//         0040a657     ??         90h
//         0040a658     NOP
//         0040a659     NOP
//         0040a65a     NOP
//         0040a65b     NOP
//         0040a65c     NOP
//         0040a65d     NOP
//         0040a65e     NOP
//         0040a65f     NOP
    return 0;
}

int BaseObject::currentTargetType() {
    /* TODO: Stub */
//                              int __thiscall currentTargetType(BaseObject * this)
//              int               EAX:4          <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?currentTargetType@BaseObject@@QBEHXZ
//                               BaseObject::currentTargetType
//                              aibobj.cpp:379 (6)
//         0040a660     MOV        EAX,dword ptr [ECX + this->currentTargetTypeVa
//                              aibobj.cpp:381 (1)
//         0040a666     RET
//         0040a667     ??         90h
//         0040a668     NOP
//         0040a669     NOP
//         0040a66a     NOP
//         0040a66b     NOP
//         0040a66c     NOP
//         0040a66d     NOP
//         0040a66e     NOP
//         0040a66f     NOP
    return 0;
}

float BaseObject::currentTargetXPosition() {
    /* TODO: Stub */
//                              float __thiscall currentTargetXPosition(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?currentTargetXPosition@BaseObject@@QBEMXZ
//                               BaseObject::currentTargetXPosition
//                              aibobj.cpp:386 (6)
//         0040a670     FLD        float ptr [ECX + this->currentTargetXPositionV
//                              aibobj.cpp:388 (1)
//         0040a676     RET
//         0040a677     ??         90h
//         0040a678     NOP
//         0040a679     NOP
//         0040a67a     NOP
//         0040a67b     NOP
//         0040a67c     NOP
//         0040a67d     NOP
//         0040a67e     NOP
//         0040a67f     NOP
    return 0;
}

float BaseObject::currentTargetYPosition() {
    /* TODO: Stub */
//                              float __thiscall currentTargetYPosition(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?currentTargetYPosition@BaseObject@@QBEMXZ
//                               BaseObject::currentTargetYPosition
//                              aibobj.cpp:393 (6)
//         0040a680     FLD        float ptr [ECX + this->currentTargetYPositionV
//                              aibobj.cpp:395 (1)
//         0040a686     RET
//         0040a687     ??         90h
//         0040a688     NOP
//         0040a689     NOP
//         0040a68a     NOP
//         0040a68b     NOP
//         0040a68c     NOP
//         0040a68d     NOP
//         0040a68e     NOP
//         0040a68f     NOP
    return 0;
}

float BaseObject::currentTargetZPosition() {
    /* TODO: Stub */
//                              float __thiscall currentTargetZPosition(BaseObject * this)
//              float             ST0:10         <RETURN>
//              BaseObject *      ECX:4 (auto)   this
//                               ?currentTargetZPosition@BaseObject@@QBEMXZ
//                               BaseObject::currentTargetZPosition
//                              aibobj.cpp:400 (6)
//         0040a690     FLD        float ptr [ECX + this->currentTargetZPositionV
//                              aibobj.cpp:402 (1)
//         0040a696     RET
//         0040a697     ??         90h
//         0040a698     NOP
//         0040a699     NOP
//         0040a69a     NOP
//         0040a69b     NOP
//         0040a69c     NOP
//         0040a69d     NOP
//         0040a69e     NOP
//         0040a69f     NOP
    return 0;
}

void BaseObject::setXPosition(float param_1) {
    /* TODO: Stub */
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
//         0040a6aa     ??         90h
//         0040a6ab     NOP
//         0040a6ac     NOP
//         0040a6ad     NOP
//         0040a6ae     NOP
//         0040a6af     NOP
    return;
}

void BaseObject::setYPosition(float param_1) {
    /* TODO: Stub */
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
//         0040a6ba     ??         90h
//         0040a6bb     NOP
//         0040a6bc     NOP
//         0040a6bd     NOP
//         0040a6be     NOP
//         0040a6bf     NOP
    return;
}

void BaseObject::setZPosition(float param_1) {
    /* TODO: Stub */
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
//         0040a6ca     ??         90h
//         0040a6cb     NOP
//         0040a6cc     NOP
//         0040a6cd     NOP
//         0040a6ce     NOP
//         0040a6cf     NOP
    return;
}

void BaseObject::setXSize(float param_1) {
    /* TODO: Stub */
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
//         0040a6da     ??         90h
//         0040a6db     NOP
//         0040a6dc     NOP
//         0040a6dd     NOP
//         0040a6de     NOP
//         0040a6df     NOP
    return;
}

void BaseObject::setYSize(float param_1) {
    /* TODO: Stub */
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
//         0040a6ea     ??         90h
//         0040a6eb     NOP
//         0040a6ec     NOP
//         0040a6ed     NOP
//         0040a6ee     NOP
//         0040a6ef     NOP
    return;
}

void BaseObject::setZSize(float param_1) {
    /* TODO: Stub */
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
//         0040a6fa     ??         90h
//         0040a6fb     NOP
//         0040a6fc     NOP
//         0040a6fd     NOP
//         0040a6fe     NOP
//         0040a6ff     NOP
    return;
}

void BaseObject::setHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a70a     ??         90h
//         0040a70b     NOP
//         0040a70c     NOP
//         0040a70d     NOP
//         0040a70e     NOP
//         0040a70f     NOP
    return;
}

void BaseObject::incrementHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a71f     ??         90h
    return;
}

void BaseObject::decrementHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a72f     ??         90h
    return;
}

void BaseObject::setMinHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a73a     ??         90h
//         0040a73b     NOP
//         0040a73c     NOP
//         0040a73d     NOP
//         0040a73e     NOP
//         0040a73f     NOP
    return;
}

void BaseObject::incrementMinHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a74f     ??         90h
    return;
}

void BaseObject::decrementMinHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a75f     ??         90h
    return;
}

void BaseObject::setMaxHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a76d     ??         90h
//         0040a76e     NOP
//         0040a76f     NOP
    return;
}

void BaseObject::incrementMaxHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a785     ??         90h
//         0040a786     NOP
//         0040a787     NOP
//         0040a788     NOP
//         0040a789     NOP
//         0040a78a     NOP
//         0040a78b     NOP
//         0040a78c     NOP
//         0040a78d     NOP
//         0040a78e     NOP
//         0040a78f     NOP
    return;
}

void BaseObject::decrementMaxHitPoints(int param_1) {
    /* TODO: Stub */
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
//         0040a7a5     ??         90h
//         0040a7a6     NOP
//         0040a7a7     NOP
//         0040a7a8     NOP
//         0040a7a9     NOP
//         0040a7aa     NOP
//         0040a7ab     NOP
//         0040a7ac     NOP
//         0040a7ad     NOP
//         0040a7ae     NOP
//         0040a7af     NOP
    return;
}

void BaseObject::setBusy(int param_1) {
    /* TODO: Stub */
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
//         0040a7bd     ??         90h
//         0040a7be     NOP
//         0040a7bf     NOP
    return;
}

void BaseObject::setCurrentTask(int param_1) {
    /* TODO: Stub */
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
//         0040a7cd     ??         90h
//         0040a7ce     NOP
//         0040a7cf     NOP
    return;
}

void BaseObject::setCurrentTarget(int param_1) {
    /* TODO: Stub */
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
//         0040a7dd     ??         90h
//         0040a7de     NOP
//         0040a7df     NOP
    return;
}

void BaseObject::setCurrentTargetType(int param_1) {
    /* TODO: Stub */
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
//         0040a7ed     ??         90h
//         0040a7ee     NOP
//         0040a7ef     NOP
    return;
}

void BaseObject::setCurrentTargetPosition(float param_1, float param_2, float param_3) {
    /* TODO: Stub */
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
//         0040a811     ??         90h
//         0040a812     NOP
//         0040a813     NOP
//         0040a814     NOP
//         0040a815     NOP
//         0040a816     NOP
//         0040a817     NOP
//         0040a818     NOP
//         0040a819     NOP
//         0040a81a     NOP
//         0040a81b     NOP
//         0040a81c     NOP
//         0040a81d     NOP
//         0040a81e     NOP
//         0040a81f     NOP
    return;
}

