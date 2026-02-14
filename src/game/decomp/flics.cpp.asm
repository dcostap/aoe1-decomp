// Auto-generated scaffold unit: flics.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/flics.cpp
#include "../include/common.h"

// Offset: 0x00449B30
undefined RGE_Flic_Player(RGE_Flic_Player* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Flic_Player::RGE_Flic_Player(char *)                                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Flic_Player(RGE_Flic_Player * this, char * 
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     00449b30(R)  
    //                               ??0RGE_Flic_Player@@QAE@PAD@Z
    //                               RGE_Flic_Player::RGE_Flic_Player
    //                              flics.cpp:21 (24)
    //         00449b30     MOV        EAX,dword ptr [ESP + param_1]
    //         00449b34     PUSH       EBX
    //         00449b35     PUSH       EBP
    //         00449b36     PUSH       0x8000
    //         00449b3b     MOV        EBX,this
    //         00449b3d     PUSH       EAX
    //         00449b3e     CALL       __open                                           undefined __open()
    //         00449b43     MOV        EBP,EAX
    //         00449b45     ADD        ESP,0x8
    //                              flics.cpp:27 (7)
    //         00449b48     CMP        EBP,-0x1
    //         00449b4b     JLE        LAB_00449bbd
    //         00449b4d     PUSH       EDI
    //         00449b4e     PUSH       ESI
    //                              flics.cpp:30 (13)
    //         00449b4f     PUSH       0x2
    //         00449b51     PUSH       0x0
    //         00449b53     PUSH       EBP
    //         00449b54     CALL       lseek                                            undefined lseek()
    //         00449b59     ADD        ESP,0xc
    //                              flics.cpp:31 (11)
    //         00449b5c     PUSH       EBP
    //         00449b5d     CALL       __tell                                           undefined __tell()
    //         00449b62     ADD        ESP,0x4
    //         00449b65     MOV        ESI,EAX
    //                              flics.cpp:34 (13)
    //         00449b67     PUSH       0x1
    //         00449b69     PUSH       ESI
    //         00449b6a     CALL       calloc                                           undefined calloc()
    //         00449b6f     ADD        ESP,0x8
    //         00449b72     MOV        dword ptr [EBX],EAX
    //                              flics.cpp:37 (10)
    //         00449b74     PUSH       0x0
    //         00449b76     PUSH       0x0
    //         00449b78     PUSH       EBP
    //         00449b79     CALL       lseek                                            undefined lseek()
    //                              flics.cpp:38 (13)
    //         00449b7e     MOV        this,dword ptr [EBX]
    //         00449b80     ADD        ESP,0xc
    //         00449b83     PUSH       ESI
    //         00449b84     PUSH       this
    //         00449b85     PUSH       EBP
    //         00449b86     CALL       read                                             undefined read()
    //                              flics.cpp:40 (15)
    //         00449b8b     MOV        ESI,dword ptr [EBX]
    //         00449b8d     LEA        EDI,[EBX + 0x8]
    //         00449b90     MOV        this,0x21
    //         00449b95     ADD        ESP,0xc
    //         00449b98     MOVSD.REP  ES:EDI,ESI
    //                              flics.cpp:41 (4)
    //         00449b9a     MOVSX      EDX,word ptr [EBX + 0x10]
    //                              flics.cpp:42 (13)
    //         00449b9e     MOV        this,EBX
    //         00449ba0     MOV        dword ptr [EBX + 0x94],EDX
    //         00449ba6     CALL       RGE_Flic_Player::start                           void start(RGE_Flic_Player * this)
    //                              flics.cpp:43 (9)
    //         00449bab     PUSH       EBP
    //         00449bac     CALL       close                                            undefined close()
    //         00449bb1     ADD        ESP,0x4
    //                              flics.cpp:50 (9)
    //         00449bb4     MOV        EAX,EBX
    //         00449bb6     POP        ESI
    //         00449bb7     POP        EDI
    //         00449bb8     POP        EBP
    //         00449bb9     POP        EBX
    //         00449bba     RET        0x4
    //                               LAB_00449bbd                                                 XREF[1]:     00449b4b(j)  
    //                              flics.cpp:47 (6)
    //         00449bbd     MOV        dword ptr [EBX],0x0
    //                              flics.cpp:48 (7)
    //         00449bc3     MOV        dword ptr [EBX + 0x4],0xffffffff
    //                              flics.cpp:50 (7)
    //         00449bca     MOV        EAX,EBX
    //         00449bcc     POP        EBP
    //         00449bcd     POP        EBX
    //         00449bce     RET        0x4
}

// Offset: 0x00449BE0
undefined RGE_Flic_Player(RGE_Flic_Player* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Flic_Player::RGE_Flic_Player(int)                                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Flic_Player(RGE_Flic_Player * this, int par
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     00449be2(R)  
    //                               ??0RGE_Flic_Player@@QAE@H@Z
    //                               RGE_Flic_Player::RGE_Flic_Player
    //                              flics.cpp:54 (2)
    //         00449be0     PUSH       ESI
    //         00449be1     PUSH       EDI
    //                              flics.cpp:57 (11)
    //         00449be2     MOV        EDI,dword ptr [ESP + param_1]
    //         00449be6     MOV        ESI,this
    //         00449be8     CMP        EDI,-0x1
    //         00449beb     JLE        LAB_00449c20
    //                              flics.cpp:59 (15)
    //         00449bed     LEA        EAX,[ESI + 0x8]
    //                              language.dll match for 0x84: "8"
    //         00449bf0     PUSH       0x84
    //         00449bf5     PUSH       EAX
    //         00449bf6     PUSH       EDI
    //         00449bf7     CALL       read                                             undefined read()
    //                              flics.cpp:62 (13)
    //         00449bfc     MOVSX      this,word ptr [ESI + 0x10]
    //         00449c00     MOV        dword ptr [ESI + 0x94],this
    //         00449c06     ADD        ESP,0xc
    //                              flics.cpp:63 (16)
    //         00449c09     MOV        this,ESI
    //         00449c0b     MOV        dword ptr [ESI + 0x4],EDI
    //         00449c0e     MOV        dword ptr [ESI],0x0
    //         00449c14     CALL       RGE_Flic_Player::start                           void start(RGE_Flic_Player * this)
    //                              flics.cpp:70 (7)
    //         00449c19     MOV        EAX,ESI
    //         00449c1b     POP        EDI
    //         00449c1c     POP        ESI
    //         00449c1d     RET        0x4
    //                               LAB_00449c20                                                 XREF[1]:     00449beb(j)  
    //                              flics.cpp:67 (6)
    //         00449c20     MOV        dword ptr [ESI],0x0
    //                              flics.cpp:68 (7)
    //         00449c26     MOV        dword ptr [ESI + 0x4],0xffffffff
    //                              flics.cpp:70 (7)
    //         00449c2d     MOV        EAX,ESI
    //         00449c2f     POP        EDI
    //         00449c30     POP        ESI
    //         00449c31     RET        0x4
}

// Offset: 0x00449C40
void RGE_Flic_Player(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Flic_Player::~RGE_Flic_Player(void)                                            *
    //                              *********************************************************************************************************
    //                              void __thiscall ~RGE_Flic_Player(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ??1RGE_Flic_Player@@QAE@XZ
    //                               RGE_Flic_Player::~RGE_Flic_Player
    //                              flics.cpp:74 (6)
    //         00449c40     MOV        EAX,dword ptr [this->flic_buffer]
    //         00449c42     TEST       EAX,EAX
    //         00449c44     JZ         LAB_00449c4f
    //                              flics.cpp:76 (9)
    //         00449c46     PUSH       EAX
    //         00449c47     CALL       free                                             undefined free()
    //         00449c4c     ADD        ESP,0x4
    //                               LAB_00449c4f                                                 XREF[1]:     00449c44(j)  
    //                              flics.cpp:77 (1)
    //         00449c4f     RET
}

// Offset: 0x00449C50
void palette(RGE_Flic_Player* this_, tagRGBQUAD* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Flic_Player::palette(struct tagRGBQUAD *)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall palette(RGE_Flic_Player * this, tagRGBQUAD * param_1)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              tagRGBQUAD *      Stack[0x4]:4   param_1                   XREF[2]:     00449d0d(R), 00449d66(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00449c5b(W), 00449db5(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00449c5f(W), 00449caf(W), 00449dcc(R)  
    //              char *            Stack[-0xc]:4  temp_buffer               XREF[3]:     00449cce(W), 00449d9e(R), 00449dab(W)  
    //              long              Stack[-0x10]:4 index1                    XREF[4]:     00449c80(W), 00449cc3(W), 00449cca(R), 00449d98(R)  
    //              FrameHead *       Stack[-0x14]:4 framehead
    //                               ?palette@RGE_Flic_Player@@QAEXPAUtagRGBQUAD@@@Z
    //                               RGE_Flic_Player::palette
    //                              flics.cpp:81 (9)
    //         00449c50     SUB        ESP,0x10
    //         00449c53     PUSH       EBX
    //         00449c54     PUSH       EBP
    //         00449c55     PUSH       ESI
    //         00449c56     PUSH       EDI
    //         00449c57     MOV        EDI,this
    //                              flics.cpp:88 (10)
    //         00449c59     XOR        EBP,EBP
    //         00449c5b     MOV        dword ptr [ESP + local_4],EDI
    //         00449c5f     MOV        dword ptr [ESP + local_8],EBP
    //                              flics.cpp:92 (6)
    //         00449c63     CMP        dword ptr [EDI + 0x4],-0x1
    //         00449c67     JLE        LAB_00449cc0
    //                              flics.cpp:94 (9)
    //         00449c69     PUSH       0x10
    //         00449c6b     PUSH       0x1
    //         00449c6d     CALL       calloc                                           undefined calloc()
    //                              flics.cpp:95 (23)
    //         00449c72     MOV        this,dword ptr [EDI + 0x4]
    //         00449c75     ADD        ESP,0x8
    //         00449c78     MOV        ESI,EAX
    //         00449c7a     MOV        EAX,dword ptr [EDI + 0x60]
    //         00449c7d     PUSH       EBP
    //         00449c7e     PUSH       EAX
    //         00449c7f     PUSH       this
    //         00449c80     MOV        dword ptr [ESP + index1],ESI
    //         00449c84     CALL       lseek                                            undefined lseek()
    //                              flics.cpp:96 (15)
    //         00449c89     MOV        EDX,dword ptr [EDI + 0x4]
    //         00449c8c     ADD        ESP,0xc
    //         00449c8f     PUSH       0x10
    //         00449c91     PUSH       ESI
    //         00449c92     PUSH       EDX
    //         00449c93     CALL       read                                             undefined read()
    //                              flics.cpp:98 (13)
    //         00449c98     MOV        EAX,dword ptr [ESI]
    //         00449c9a     ADD        ESP,0xc
    //         00449c9d     PUSH       0x1
    //         00449c9f     PUSH       EAX
    //         00449ca0     CALL       calloc                                           undefined calloc()
    //                              flics.cpp:99 (25)
    //         00449ca5     MOV        this,dword ptr [ESI]
    //         00449ca7     MOV        EDX,dword ptr [EDI + 0x4]
    //         00449caa     ADD        ESP,0x8
    //         00449cad     MOV        EBX,EAX
    //         00449caf     MOV        dword ptr [ESP + local_8],EBX
    //         00449cb3     PUSH       this
    //         00449cb4     PUSH       EBX
    //         00449cb5     PUSH       EDX
    //         00449cb6     CALL       read                                             undefined read()
    //         00449cbb     ADD        ESP,0xc
    //                              flics.cpp:103 (2)
    //         00449cbe     JMP        LAB_00449cca
    //                               LAB_00449cc0                                                 XREF[1]:     00449c67(j)  
    //                              flics.cpp:105 (7)
    //         00449cc0     MOV        EBX,dword ptr [EDI + 0x60]
    //         00449cc3     MOV        dword ptr [ESP + index1],EBX
    //                              flics.cpp:106 (3)
    //         00449cc7     ADD        EBX,0x10
    //                               LAB_00449cca                                                 XREF[1]:     00449cbe(j)  
    //                              flics.cpp:109 (18)
    //         00449cca     MOV        this,dword ptr [ESP + index1]
    //         00449cce     MOV        dword ptr [ESP + temp_buffer],EBP
    //         00449cd2     CMP        word ptr [ECX + this+0x6],BP
    //         00449cd6     JLE        LAB_00449db9
    //                               LAB_00449cdc                                                 XREF[1]:     00449daf(j)  
    //                              flics.cpp:111 (7)
    //         00449cdc     CMP        word ptr [EBX + 0x4],0x4
    //         00449ce1     JNZ        LAB_00449d35
    //                              flics.cpp:115 (9)
    //         00449ce3     MOVSX      this,word ptr [EBX + 0x6]
    //         00449ce7     LEA        EAX,[EBX + 0x6]
    //         00449cea     XOR        EDI,EDI
    //                              flics.cpp:116 (3)
    //         00449cec     ADD        EAX,0x2
    //                              flics.cpp:117 (4)
    //         00449cef     TEST       this,this
    //         00449cf1     JLE        LAB_00449d35
    //                              flics.cpp:171 (2)
    //         00449cf3     MOV        EBP,this
    //                               LAB_00449cf5                                                 XREF[1]:     00449d33(j)  
    //                              flics.cpp:119 (3)
    //         00449cf5     MOVSX      this,byte ptr [EAX]
    //                              flics.cpp:122 (11)
    //         00449cf8     MOVSX      EDX,byte ptr [EAX + 0x1]
    //         00449cfc     ADD        EDI,this
    //         00449cfe     INC        EAX
    //         00449cff     TEST       EDX,EDX
    //         00449d01     JNZ        LAB_00449d08
    //                              flics.cpp:123 (5)
    //         00449d03     MOV        EDX,0x100
    //                               LAB_00449d08                                                 XREF[1]:     00449d01(j)  
    //                              flics.cpp:124 (1)
    //         00449d08     INC        EAX
    //                              flics.cpp:125 (16)
    //         00449d09     TEST       EDX,EDX
    //         00449d0b     JLE        LAB_00449d32
    //         00449d0d     MOV        this,dword ptr [ESP + param_1]
    //         00449d11     MOV        ESI,EDX
    //         00449d13     LEA        this,[ECX + EDI*0x4 + this+0x1]
    //         00449d17     ADD        EDI,EDX
    //                               LAB_00449d19                                                 XREF[1]:     00449d30(j)  
    //                              flics.cpp:127 (2)
    //         00449d19     MOV        DL,byte ptr [EAX]
    //                              flics.cpp:131 (23)
    //         00449d1b     ADD        EAX,0x3
    //         00449d1e     MOV        byte ptr [ECX + this+0x1],DL
    //         00449d21     MOV        DL,byte ptr [EAX + -0x2]
    //         00449d24     MOV        byte ptr [this->flic_buffer],DL
    //         00449d26     MOV        DL,byte ptr [EAX + -0x1]
    //         00449d29     MOV        byte ptr [this->flic_buffer + -0x1],DL
    //         00449d2c     ADD        this,0x4
    //         00449d2f     DEC        ESI
    //         00449d30     JNZ        LAB_00449d19
    //                               LAB_00449d32                                                 XREF[1]:     00449d0b(j)  
    //                              flics.cpp:117 (3)
    //         00449d32     DEC        EBP
    //         00449d33     JNZ        LAB_00449cf5
    //                               LAB_00449d35                                                 XREF[2]:     00449ce1(j), 00449cf1(j)  
    //                              flics.cpp:135 (7)
    //         00449d35     CMP        word ptr [EBX + 0x4],0xb
    //         00449d3a     JNZ        LAB_00449d98
    //                              flics.cpp:139 (9)
    //         00449d3c     MOVSX      this,word ptr [EBX + 0x6]
    //         00449d40     LEA        EAX,[EBX + 0x6]
    //         00449d43     XOR        EDI,EDI
    //                              flics.cpp:140 (3)
    //         00449d45     ADD        EAX,0x2
    //                              flics.cpp:141 (4)
    //         00449d48     TEST       this,this
    //         00449d4a     JLE        LAB_00449d98
    //                              flics.cpp:171 (2)
    //         00449d4c     MOV        EBP,this
    //                               LAB_00449d4e                                                 XREF[1]:     00449d96(j)  
    //                              flics.cpp:143 (3)
    //         00449d4e     MOVSX      this,byte ptr [EAX]
    //                              flics.cpp:146 (11)
    //         00449d51     MOVSX      EDX,byte ptr [EAX + 0x1]
    //         00449d55     ADD        EDI,this
    //         00449d57     INC        EAX
    //         00449d58     TEST       EDX,EDX
    //         00449d5a     JNZ        LAB_00449d61
    //                              flics.cpp:147 (5)
    //         00449d5c     MOV        EDX,0x100
    //                               LAB_00449d61                                                 XREF[1]:     00449d5a(j)  
    //                              flics.cpp:148 (1)
    //         00449d61     INC        EAX
    //                              flics.cpp:149 (16)
    //         00449d62     TEST       EDX,EDX
    //         00449d64     JLE        LAB_00449d95
    //         00449d66     MOV        this,dword ptr [ESP + param_1]
    //         00449d6a     MOV        ESI,EDX
    //         00449d6c     LEA        this,[ECX + EDI*0x4 + this+0x1]
    //         00449d70     ADD        EDI,EDX
    //                               LAB_00449d72                                                 XREF[1]:     00449d93(j)  
    //                              flics.cpp:151 (2)
    //         00449d72     MOV        DL,byte ptr [EAX]
    //                              flics.cpp:154 (27)
    //         00449d74     ADD        this,0x4
    //         00449d77     SHL        DL,0x2
    //         00449d7a     MOV        byte ptr [this->flic_buffer + -0x3],DL
    //         00449d7d     MOV        DL,byte ptr [EAX + 0x1]
    //         00449d80     SHL        DL,0x2
    //         00449d83     MOV        byte ptr [this->flic_buffer + -0x4],DL
    //         00449d86     MOV        DL,byte ptr [EAX + 0x2]
    //         00449d89     SHL        DL,0x2
    //         00449d8c     MOV        byte ptr [this->flic_buffer + -0x5],DL
    //                              flics.cpp:155 (6)
    //         00449d8f     ADD        EAX,0x3
    //         00449d92     DEC        ESI
    //         00449d93     JNZ        LAB_00449d72
    //                               LAB_00449d95                                                 XREF[1]:     00449d64(j)  
    //                              flics.cpp:141 (3)
    //         00449d95     DEC        EBP
    //         00449d96     JNZ        LAB_00449d4e
    //                               LAB_00449d98                                                 XREF[2]:     00449d3a(j), 00449d4a(j)  
    //                              flics.cpp:109 (4)
    //         00449d98     MOV        this,dword ptr [ESP + index1]
    //                              flics.cpp:159 (25)
    //         00449d9c     MOV        EBP,dword ptr [EBX]
    //         00449d9e     MOV        EAX,dword ptr [ESP + temp_buffer]
    //         00449da2     ADD        EBX,EBP
    //         00449da4     MOVSX      EDX,word ptr [ECX + this+0x6]
    //         00449da8     INC        EAX
    //         00449da9     CMP        EAX,EDX
    //         00449dab     MOV        dword ptr [ESP + temp_buffer],EAX
    //         00449daf     JL         LAB_00449cdc
    //                              flics.cpp:109 (4)
    //         00449db5     MOV        EDI,dword ptr [ESP + local_4]
    //                               LAB_00449db9                                                 XREF[1]:     00449cd6(j)  
    //                              flics.cpp:163 (6)
    //         00449db9     CMP        dword ptr [EDI + 0x4],-0x1
    //         00449dbd     JLE        LAB_00449ddd
    //                              flics.cpp:165 (4)
    //         00449dbf     TEST       this,this
    //         00449dc1     JZ         LAB_00449dcc
    //                              flics.cpp:166 (9)
    //         00449dc3     PUSH       this
    //         00449dc4     CALL       free                                             undefined free()
    //         00449dc9     ADD        ESP,0x4
    //                               LAB_00449dcc                                                 XREF[1]:     00449dc1(j)  
    //                              flics.cpp:168 (8)
    //         00449dcc     MOV        EAX,dword ptr [ESP + local_8]
    //         00449dd0     TEST       EAX,EAX
    //         00449dd2     JZ         LAB_00449ddd
    //                              flics.cpp:169 (9)
    //         00449dd4     PUSH       EAX
    //         00449dd5     CALL       free                                             undefined free()
    //         00449dda     ADD        ESP,0x4
    //                               LAB_00449ddd                                                 XREF[2]:     00449dbd(j), 00449dd2(j)  
    //                              flics.cpp:171 (10)
    //         00449ddd     POP        EDI
    //         00449dde     POP        ESI
    //         00449ddf     POP        EBP
    //         00449de0     POP        EBX
    //         00449de1     ADD        ESP,0x10
    //         00449de4     RET        0x4
}

// Offset: 0x00449DF0
long resolution(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Flic_Player::resolution(void)                                             *
    //                              *********************************************************************************************************
    //                              long __thiscall resolution(RGE_Flic_Player * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?resolution@RGE_Flic_Player@@QAEJXZ
    //                               RGE_Flic_Player::resolution
    //                              flics.cpp:175 (13)
    //         00449df0     MOVSX      EAX,word ptr [ECX + this+0x10]
    //         00449df4     MOVSX      this,word ptr [ECX + this+0x12]
    //         00449df8     SHL        EAX,0x10
    //         00449dfb     OR         EAX,this
    //                              flics.cpp:180 (1)
    //         00449dfd     RET
}

// Offset: 0x00449E00
long time_delay(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall RGE_Flic_Player::time_delay(void)                                             *
    //                              *********************************************************************************************************
    //                              long __thiscall time_delay(RGE_Flic_Player * this)
    //              long              EAX:4          <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?time_delay@RGE_Flic_Player@@QAEJXZ
    //                               RGE_Flic_Player::time_delay
    //                              flics.cpp:184 (3)
    //         00449e00     MOV        EAX,dword ptr [ECX + this+0x18]
    //                              flics.cpp:186 (1)
    //         00449e03     RET
}

// Offset: 0x00449E10
short frames(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: short __thiscall RGE_Flic_Player::frames(void)                                                *
    //                              *********************************************************************************************************
    //                              short __thiscall frames(RGE_Flic_Player * this)
    //              short             AX:2           <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?frames@RGE_Flic_Player@@QAEFXZ
    //                               RGE_Flic_Player::frames
    //                              flics.cpp:190 (4)
    //         00449e10     MOV        AX,word ptr [ECX + this+0xe]
    //                              flics.cpp:192 (1)
    //         00449e14     RET
}

// Offset: 0x00449E20
void start(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Flic_Player::start(void)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall start(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?start@RGE_Flic_Player@@QAEXXZ                               XREF[2]:     RGE_Flic_Player:00449ba6(c), 
    //                               RGE_Flic_Player::start                                                    RGE_Flic_Player:00449c14(c)  
    //                              flics.cpp:196 (17)
    //         00449e20     XOR        EAX,EAX
    //         00449e22     PUSH       ESI
    //         00449e23     MOV        AX,word ptr [ECX + this+0xc]
    //         00449e27     SUB        EAX,0xaf11
    //         00449e2c     JZ         LAB_00449e40
    //         00449e2e     DEC        EAX
    //         00449e2f     JNZ        LAB_00449e70
    //                              flics.cpp:204 (10)
    //         00449e31     MOV        EAX,dword ptr [this->flic_buffer]
    //         00449e33     MOV        EDX,dword ptr [ECX + this+0x5c]
    //         00449e36     ADD        EDX,EAX
    //         00449e38     MOV        dword ptr [ECX + this+0x5c],EDX
    //                              flics.cpp:211 (3)
    //         00449e3b     MOV        dword ptr [ECX + this+0x60],EDX
    //                              flics.cpp:212 (2)
    //         00449e3e     POP        ESI
    //         00449e3f     RET
    //                               LAB_00449e40                                                 XREF[1]:     00449e2c(j)  
    //                              flics.cpp:201 (48)
    //         00449e40     MOV        EAX,dword ptr [ECX + this+0x18]
    //         00449e43     MOV        EDX,dword ptr [this->flic_buffer]
    //         00449e45     ADD        EDX,0x84
    //         00449e4b     LEA        EAX,[EAX + EAX*0x4]
    //         00449e4e     MOV        dword ptr [ECX + this+0x5c],EDX
    //         00449e51     LEA        EAX,[EAX + EAX*0x4]
    //         00449e54     LEA        ESI,[EAX + EAX*0x4]
    //         00449e57     MOV        EAX,0xea0ea0eb
    //         00449e5c     SHL        ESI,0x3
    //         00449e5f     IMUL       ESI
    //         00449e61     ADD        EDX,ESI
    //         00449e63     SAR        EDX,0x6
    //         00449e66     MOV        EAX,EDX
    //         00449e68     SHR        EAX,0x1f
    //         00449e6b     ADD        EDX,EAX
    //         00449e6d     MOV        dword ptr [ECX + this+0x18],EDX
    //                               LAB_00449e70                                                 XREF[1]:     00449e2f(j)  
    //                              flics.cpp:211 (3)
    //         00449e70     MOV        EDX,dword ptr [ECX + this+0x5c]
    //                              flics.cpp:212 (5)
    //         00449e73     POP        ESI
    //         00449e74     MOV        dword ptr [ECX + this+0x60],EDX
    //         00449e77     RET
}

// Offset: 0x00449E80
void reset(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall RGE_Flic_Player::reset(void)                                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall reset(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?reset@RGE_Flic_Player@@QAEXXZ
    //                               RGE_Flic_Player::reset
    //                              flics.cpp:216 (6)
    //         00449e80     MOV        EAX,dword ptr [ECX + this+0x5c]
    //         00449e83     MOV        dword ptr [ECX + this+0x60],EAX
    //                              flics.cpp:218 (1)
    //         00449e86     RET
}

// Offset: 0x00449E90
uchar draw(RGE_Flic_Player* this_, TDrawArea* param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall RGE_Flic_Player::draw(class TDrawArea *,long,long)                   *
    //                              *********************************************************************************************************
    //                              uchar __thiscall draw(RGE_Flic_Player * this, TDrawArea * param_1, l
    //              uchar             AL:1           <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00449f0d(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00449f05(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     00449f09(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00449e97(W), 00449eea(W), 0044a042(R)  
    //              char *            Stack[-0x8]:4  temp_buffer
    //                               ?draw@RGE_Flic_Player@@QAEEPAVTDrawArea@@JJ@Z
    //                               RGE_Flic_Player::draw
    //                              flics.cpp:222 (7)
    //         00449e90     PUSH       this
    //         00449e91     PUSH       EBX
    //         00449e92     PUSH       EBP
    //         00449e93     PUSH       ESI
    //         00449e94     MOV        ESI,this
    //         00449e96     PUSH       EDI
    //                              flics.cpp:225 (8)
    //         00449e97     MOV        dword ptr [ESP + local_4],0x0
    //                              flics.cpp:232 (6)
    //         00449e9f     CMP        dword ptr [ESI + 0x4],-0x1
    //         00449ea3     JLE        LAB_00449efb
    //                              flics.cpp:234 (9)
    //         00449ea5     PUSH       0x10
    //         00449ea7     PUSH       0x1
    //         00449ea9     CALL       calloc                                           undefined calloc()
    //                              flics.cpp:235 (20)
    //         00449eae     MOV        this,dword ptr [ESI + 0x4]
    //         00449eb1     ADD        ESP,0x8
    //         00449eb4     MOV        EBP,EAX
    //         00449eb6     MOV        EAX,dword ptr [ESI + 0x60]
    //         00449eb9     PUSH       0x0
    //         00449ebb     PUSH       EAX
    //         00449ebc     PUSH       this
    //         00449ebd     CALL       lseek                                            undefined lseek()
    //                              flics.cpp:236 (15)
    //         00449ec2     MOV        EDX,dword ptr [ESI + 0x4]
    //         00449ec5     ADD        ESP,0xc
    //         00449ec8     PUSH       0x10
    //         00449eca     PUSH       EBP
    //         00449ecb     PUSH       EDX
    //         00449ecc     CALL       read                                             undefined read()
    //                              flics.cpp:238 (14)
    //         00449ed1     MOV        EAX,dword ptr [EBP]
    //         00449ed4     ADD        ESP,0xc
    //         00449ed7     PUSH       0x1
    //         00449ed9     PUSH       EAX
    //         00449eda     CALL       calloc                                           undefined calloc()
    //                              flics.cpp:239 (26)
    //         00449edf     MOV        this,dword ptr [EBP]
    //         00449ee2     MOV        EDX,dword ptr [ESI + 0x4]
    //         00449ee5     ADD        ESP,0x8
    //         00449ee8     MOV        EDI,EAX
    //         00449eea     MOV        dword ptr [ESP + local_4],EDI
    //         00449eee     PUSH       this
    //         00449eef     PUSH       EDI
    //         00449ef0     PUSH       EDX
    //         00449ef1     CALL       read                                             undefined read()
    //         00449ef6     ADD        ESP,0xc
    //                              flics.cpp:243 (2)
    //         00449ef9     JMP        LAB_00449f01
    //                               LAB_00449efb                                                 XREF[1]:     00449ea3(j)  
    //                              flics.cpp:245 (3)
    //         00449efb     MOV        EBP,dword ptr [ESI + 0x60]
    //                              flics.cpp:246 (3)
    //         00449efe     LEA        EDI,[EBP + 0x10]
    //                               LAB_00449f01                                                 XREF[1]:     00449ef9(j)  
    //                              flics.cpp:257 (54)
    //         00449f01     MOVSX      EBX,word ptr [ESI + 0x10]
    //         00449f05     MOV        EAX,dword ptr [ESP + param_2]
    //         00449f09     MOV        EDX,dword ptr [ESP + param_3]
    //         00449f0d     MOV        this,dword ptr [ESP + param_1]
    //         00449f11     MOV        dword ptr [ESI + 0xa4],EAX
    //         00449f17     ADD        EBX,EAX
    //         00449f19     MOV        dword ptr [ESI + 0x8c],this
    //         00449f1f     MOVSX      EAX,word ptr [ESI + 0x12]
    //         00449f23     ADD        EAX,EDX
    //         00449f25     MOV        dword ptr [ESI + 0xac],EBX
    //         00449f2b     MOV        dword ptr [ESI + 0xa8],EDX
    //         00449f31     MOV        dword ptr [ESI + 0xb0],EAX
    //                              flics.cpp:260 (17)
    //         00449f37     MOV        EBX,this
    //         00449f39     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         00449f3e     IMUL       EAX,dword ptr [EBX + 0x24]
    //         00449f42     MOV        dword ptr [ESI + 0x90],EAX
    //                              flics.cpp:261 (8)
    //         00449f48     MOV        this,dword ptr [EBX + 0x24]
    //         00449f4b     CMP        this,0x1
    //         00449f4e     JGE        LAB_00449f74
    //                              flics.cpp:262 (34)
    //         00449f50     MOV        this,dword ptr [ESI + 0xa8]
    //         00449f56     MOV        EDX,dword ptr [EBX + 0x1c]
    //         00449f59     SUB        this,EDX
    //         00449f5b     MOV        EDX,dword ptr [EBX + 0x8]
    //         00449f5e     INC        this
    //         00449f5f     IMUL       this,EAX
    //         00449f62     MOV        EAX,dword ptr [ESI + 0xa4]
    //         00449f68     ADD        this,EDX
    //         00449f6a     ADD        this,EAX
    //         00449f6c     MOV        dword ptr [ESI + 0x98],this
    //                              flics.cpp:263 (2)
    //         00449f72     JMP        LAB_00449f8e
    //                               LAB_00449f74                                                 XREF[1]:     00449f4e(j)  
    //                              flics.cpp:264 (26)
    //         00449f74     IMUL       EAX,dword ptr [ESI + 0xa8]
    //         00449f7b     MOV        EDX,dword ptr [EBX + 0x8]
    //         00449f7e     MOV        this,dword ptr [ESI + 0xa4]
    //         00449f84     ADD        EAX,EDX
    //         00449f86     ADD        EAX,this
    //         00449f88     MOV        dword ptr [ESI + 0x98],EAX
    //                               LAB_00449f8e                                                 XREF[1]:     00449f72(j)  
    //                              flics.cpp:265 (6)
    //         00449f8e     MOV        EDX,dword ptr [ESI + 0x98]
    //                              flics.cpp:294 (14)
    //         00449f94     XOR        EBX,EBX
    //         00449f96     MOV        dword ptr [ESI + 0x9c],EDX
    //         00449f9c     CMP        word ptr [EBP + 0x6],BX
    //         00449fa0     JLE        LAB_00449ffe
    //                               LAB_00449fa2                                                 XREF[1]:     00449ffc(j)  
    //                              flics.cpp:296 (9)
    //         00449fa2     LEA        EAX,[EDI + 0x6]
    //         00449fa5     MOV        dword ptr [ESI + 0xa0],EAX
    //                              flics.cpp:297 (27)
    //         00449fab     MOVSX      EAX,word ptr [EDI + 0x4]
    //         00449faf     ADD        EAX,-0x4
    //         00449fb2     CMP        EAX,0xc
    //         00449fb5     JA         switchD_00449fbf::caseD_4
    //         00449fb7     XOR        this,this
    //         00449fb9     MOV        this,byte ptr [EAX + 0x44a07c]=>PTR_caseD_4_00   = 00449ff1
    //                               switchD_00449fbf::switchD
    //         00449fbf     JMP        dword ptr [this->flic_buffer*0x4 + switchD_004   = 00449ff1
    //                               switchD_00449fbf::caseD_10                                   XREF[2]:     00449fbf(j), 0044a074(*)  
    //                              flics.cpp:300 (7)
    //         00449fc6     MOV        this,ESI
    //         00449fc8     CALL       RGE_Flic_Player::literal                         void literal(RGE_Flic_Player * this)
    //                              flics.cpp:301 (2)
    //         00449fcd     JMP        switchD_00449fbf::caseD_4
    //                               switchD_00449fbf::caseD_7                                    XREF[2]:     00449fbf(j), 0044a064(*)  
    //                              flics.cpp:303 (7)
    //         00449fcf     MOV        this,ESI
    //         00449fd1     CALL       RGE_Flic_Player::delta_flc                       void delta_flc(RGE_Flic_Player * this)
    //                              flics.cpp:304 (2)
    //         00449fd6     JMP        switchD_00449fbf::caseD_4
    //                               switchD_00449fbf::caseD_c                                    XREF[2]:     00449fbf(j), 0044a068(*)  
    //                              flics.cpp:306 (7)
    //         00449fd8     MOV        this,ESI
    //         00449fda     CALL       RGE_Flic_Player::delta_fli                       void delta_fli(RGE_Flic_Player * this)
    //                              flics.cpp:307 (2)
    //         00449fdf     JMP        switchD_00449fbf::caseD_4
    //                               switchD_00449fbf::caseD_d                                    XREF[2]:     00449fbf(j), 0044a06c(*)  
    //                              flics.cpp:309 (7)
    //         00449fe1     MOV        this,ESI
    //         00449fe3     CALL       RGE_Flic_Player::black                           void black(RGE_Flic_Player * this)
    //                              flics.cpp:310 (2)
    //         00449fe8     JMP        switchD_00449fbf::caseD_4
    //                               switchD_00449fbf::caseD_f                                    XREF[2]:     00449fbf(j), 0044a070(*)  
    //                              flics.cpp:312 (7)
    //         00449fea     MOV        this,ESI
    //         00449fec     CALL       RGE_Flic_Player::byte_run                        void byte_run(RGE_Flic_Player * this)
    //                               switchD_00449fbf::caseD_5                                    XREF[8]:     00449fb5(j), 00449fbf(j), 
    //                               switchD_00449fbf::caseD_6                                                 00449fcd(j), 00449fd6(j), 
    //                               switchD_00449fbf::caseD_8                                                 00449fdf(j), 00449fe8(j), 
    //                               switchD_00449fbf::caseD_9                                                 0044a060(*), 0044a078(*)  
    //                               switchD_00449fbf::caseD_a
    //                               switchD_00449fbf::caseD_b
    //                               switchD_00449fbf::caseD_e
    //                               switchD_00449fbf::caseD_4
    //                              flics.cpp:317 (13)
    //         00449ff1     MOV        EDX,dword ptr [EDI]
    //         00449ff3     ADD        EDI,EDX
    //         00449ff5     INC        EBX
    //         00449ff6     MOVSX      EDX,word ptr [EBP + 0x6]
    //         00449ffa     CMP        EBX,EDX
    //         00449ffc     JL         LAB_00449fa2
    //                               LAB_00449ffe                                                 XREF[1]:     00449fa0(j)  
    //                              flics.cpp:321 (6)
    //         00449ffe     MOV        EAX,dword ptr [EBP]
    //         0044a001     MOV        EBX,dword ptr [ESI + 0x60]
    //                              flics.cpp:322 (18)
    //         0044a004     MOV        this,dword ptr [ESI]
    //         0044a006     MOV        EDX,dword ptr [ESI + 0x8]
    //         0044a009     ADD        EBX,EAX
    //         0044a00b     MOV        EAX,EBX
    //         0044a00d     MOV        dword ptr [ESI + 0x60],EBX
    //         0044a010     SUB        EAX,this
    //         0044a012     CMP        EAX,EDX
    //         0044a014     JL         LAB_0044a02d
    //                              flics.cpp:325 (3)
    //         0044a016     MOV        EAX,dword ptr [ESI + 0x5c]
    //                              flics.cpp:327 (7)
    //         0044a019     TEST       this,this
    //         0044a01b     MOV        dword ptr [ESI + 0x60],EAX
    //         0044a01e     JZ         LAB_0044a029
    //                              flics.cpp:328 (9)
    //         0044a020     MOV        EDX,dword ptr [EAX]
    //         0044a022     MOV        this,EAX
    //         0044a024     ADD        this,EDX
    //         0044a026     MOV        dword ptr [ESI + 0x60],this
    //                               LAB_0044a029                                                 XREF[1]:     0044a01e(j)  
    //                              flics.cpp:330 (2)
    //         0044a029     MOV        BL,0x2
    //                              flics.cpp:332 (2)
    //         0044a02b     JMP        LAB_0044a02f
    //                               LAB_0044a02d                                                 XREF[1]:     0044a014(j)  
    //                              flics.cpp:333 (2)
    //         0044a02d     XOR        BL,BL
    //                               LAB_0044a02f                                                 XREF[1]:     0044a02b(j)  
    //                              flics.cpp:336 (6)
    //         0044a02f     CMP        dword ptr [ESI + 0x4],-0x1
    //         0044a033     JLE        LAB_0044a053
    //                              flics.cpp:338 (4)
    //         0044a035     TEST       EBP,EBP
    //         0044a037     JZ         LAB_0044a042
    //                              flics.cpp:339 (9)
    //         0044a039     PUSH       EBP
    //         0044a03a     CALL       free                                             undefined free()
    //         0044a03f     ADD        ESP,0x4
    //                               LAB_0044a042                                                 XREF[1]:     0044a037(j)  
    //                              flics.cpp:340 (8)
    //         0044a042     MOV        EAX,dword ptr [ESP + local_4]
    //         0044a046     TEST       EAX,EAX
    //         0044a048     JZ         LAB_0044a053
    //                              flics.cpp:341 (9)
    //         0044a04a     PUSH       EAX
    //         0044a04b     CALL       free                                             undefined free()
    //         0044a050     ADD        ESP,0x4
    //                               LAB_0044a053                                                 XREF[2]:     0044a033(j), 0044a048(j)  
    //                              flics.cpp:345 (54)
    //         0044a053     POP        EDI
    //         0044a054     POP        ESI
    //         0044a055     MOV        AL,BL
    //         0044a057     POP        EBP
    //         0044a058     POP        EBX
    //         0044a059     POP        this
    //         0044a05a     RET        0xc
}

// Offset: 0x0044A05D
undefined FUN_0044a05d() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0044a05d()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0044a05d
    //         0044a05d     NOP
    //         0044a05e     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_00449fbf::switchdataD_0044a060                       XREF[1]:     draw:00449fbf(*)  
}

// Offset: 0x0044A090
void literal(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall RGE_Flic_Player::literal(void)                                               *
    //                              *********************************************************************************************************
    //                              void __thiscall literal(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?literal@RGE_Flic_Player@@AAEXXZ                             XREF[1]:     draw:00449fc8(c)  
    //                               RGE_Flic_Player::literal
    //                              flics.cpp:349 (2)
    //         0044a090     MOV        EAX,this
    //                              flics.cpp:355 (15)
    //         0044a092     XOR        EDX,EDX
    //         0044a094     MOV        this,dword ptr [EAX + 0xb8]
    //         0044a09a     TEST       this,this
    //         0044a09c     JLE        LAB_0044a0f7
    //         0044a09e     PUSH       EDI
    //         0044a09f     PUSH       ESI
    //         0044a0a0     PUSH       EBX
    //                               LAB_0044a0a1                                                 XREF[1]:     0044a0f2(j)  
    //                              flics.cpp:357 (32)
    //         0044a0a1     MOV        this,dword ptr [EAX + 0xb4]
    //         0044a0a7     MOV        ESI,dword ptr [EAX + 0xa0]
    //         0044a0ad     MOV        EDI,dword ptr [EAX + 0x98]
    //         0044a0b3     MOV        EBX,this
    //         0044a0b5     SHR        this,0x2
    //         0044a0b8     MOVSD.REP  ES:EDI,ESI
    //         0044a0ba     MOV        this,EBX
    //         0044a0bc     AND        this,0x3
    //         0044a0bf     MOVSB.REP  ES:EDI,ESI
    //                              flics.cpp:358 (12)
    //         0044a0c1     MOV        this,dword ptr [EAX + 0x90]
    //         0044a0c7     MOV        EBX,dword ptr [EAX + 0x98]
    //                              flics.cpp:359 (42)
    //         0044a0cd     MOV        EDI,dword ptr [EAX + 0xa0]
    //         0044a0d3     ADD        EBX,this
    //         0044a0d5     MOV        this,dword ptr [EAX + 0x94]
    //         0044a0db     MOV        dword ptr [EAX + 0x98],EBX
    //         0044a0e1     ADD        EDI,this
    //         0044a0e3     MOV        this,dword ptr [EAX + 0xb8]
    //         0044a0e9     INC        EDX
    //         0044a0ea     MOV        dword ptr [EAX + 0xa0],EDI
    //         0044a0f0     CMP        EDX,this
    //         0044a0f2     JL         LAB_0044a0a1
    //         0044a0f4     POP        EBX
    //         0044a0f5     POP        ESI
    //         0044a0f6     POP        EDI
    //                               LAB_0044a0f7                                                 XREF[1]:     0044a09c(j)  
    //                              flics.cpp:361 (1)
    //         0044a0f7     RET
}

// Offset: 0x0044A100
void delta_flc(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall RGE_Flic_Player::delta_flc(void)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall delta_flc(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0044a126(W), 0044a27b(R), 0044a28a(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0044a1b5(W), 0044a251(R), 0044a256(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0044a106(W), 0044a14e(R), 0044a159(W), 0044a26c(R), 
    //                                                                                     0044a280(W)  
    //              long              Stack[-0x10]:4 cur_y
    //                               ?delta_flc@RGE_Flic_Player@@AAEXXZ                           XREF[1]:     draw:00449fd1(c)  
    //                               RGE_Flic_Player::delta_flc
    //                              flics.cpp:365 (6)
    //         0044a100     SUB        ESP,0xc
    //         0044a103     MOV        EAX,this
    //         0044a105     PUSH       EBP
    //                              flics.cpp:367 (8)
    //         0044a106     MOV        dword ptr [ESP + local_c],0x0
    //                              flics.cpp:372 (6)
    //         0044a10e     MOV        EBP,dword ptr [EAX + 0xa0]
    //                              flics.cpp:375 (4)
    //         0044a114     MOVSX      this,word ptr [EBP]
    //                              flics.cpp:376 (3)
    //         0044a118     ADD        EBP,0x2
    //                              flics.cpp:377 (15)
    //         0044a11b     TEST       this,this
    //         0044a11d     JLE        LAB_0044a297
    //         0044a123     PUSH       EDI
    //         0044a124     PUSH       ESI
    //         0044a125     PUSH       EBX
    //         0044a126     MOV        dword ptr [ESP + local_4],this
    //                               LAB_0044a12a                                                 XREF[1]:     0044a28e(j)  
    //                              flics.cpp:379 (2)
    //         0044a12a     XOR        BL,BL
    //                               LAB_0044a12c                                                 XREF[1]:     0044a1a7(j)  
    //                              flics.cpp:382 (4)
    //         0044a12c     MOV        this,word ptr [EBP]
    //                              flics.cpp:383 (2)
    //         0044a130     XOR        EDI,EDI
    //                              flics.cpp:384 (2)
    //         0044a132     MOV        ESI,this
    //                              flics.cpp:385 (14)
    //         0044a134     ADD        EBP,0x2
    //         0044a137     AND        ESI,0xffff
    //         0044a13d     MOV        EDX,ESI
    //         0044a13f     SHR        EDX,0xe
    //                              flics.cpp:386 (12)
    //         0044a142     SUB        EDX,EDI
    //         0044a144     JZ         LAB_0044a1a1
    //         0044a146     SUB        EDX,0x2
    //         0044a149     JZ         LAB_0044a17c
    //         0044a14b     DEC        EDX
    //         0044a14c     JNZ        LAB_0044a1a5
    //                              flics.cpp:398 (15)
    //         0044a14e     MOV        EDX,dword ptr [ESP + local_c]
    //         0044a152     NEG        this
    //         0044a154     MOVSX      this,this
    //         0044a157     ADD        EDX,this
    //         0044a159     MOV        dword ptr [ESP + local_c],EDX
    //                              flics.cpp:399 (23)
    //         0044a15d     MOV        EDX,dword ptr [EAX + 0x90]
    //         0044a163     IMUL       EDX,this
    //         0044a166     MOV        this,dword ptr [EAX + 0x9c]
    //         0044a16c     ADD        this,EDX
    //         0044a16e     MOV        dword ptr [EAX + 0x9c],this
    //                              flics.cpp:400 (6)
    //         0044a174     MOV        dword ptr [EAX + 0x98],this
    //                              flics.cpp:401 (2)
    //         0044a17a     JMP        LAB_0044a1a5
    //                               LAB_0044a17c                                                 XREF[1]:     0044a149(j)  
    //                              flics.cpp:389 (26)
    //         0044a17c     MOV        EDX,dword ptr [EAX + 0x98]
    //         0044a182     MOV        this,ESI
    //         0044a184     MOV        ESI,dword ptr [EAX + 0x94]
    //         0044a18a     AND        this,0xff
    //         0044a190     MOV        this,this
    //         0044a192     MOV        byte ptr [EDX + ESI*0x1 + -0x1],this
    //                              flics.cpp:390 (8)
    //         0044a196     MOV        this,word ptr [EBP]
    //         0044a19a     LEA        EDX,[EDX + ESI*0x1 + -0x1]
    //                              flics.cpp:391 (3)
    //         0044a19e     ADD        EBP,0x2
    //                               LAB_0044a1a1                                                 XREF[1]:     0044a144(j)  
    //                              flics.cpp:393 (2)
    //         0044a1a1     MOV        EDI,this
    //                              flics.cpp:394 (2)
    //         0044a1a3     MOV        BL,0x1
    //                               LAB_0044a1a5                                                 XREF[2]:     0044a14c(j), 0044a17a(j)  
    //                              flics.cpp:404 (4)
    //         0044a1a5     TEST       BL,BL
    //         0044a1a7     JZ         LAB_0044a12c
    //                              flics.cpp:406 (9)
    //         0044a1a9     TEST       DI,DI
    //         0044a1ac     JLE        LAB_0044a260
    //                              flics.cpp:441 (77)
    //         0044a1b2     MOVSX      this,DI
    //         0044a1b5     MOV        dword ptr [ESP + local_8],this
    //                               LAB_0044a1b9                                                 XREF[1]:     0044a25a(j)  
    //         0044a1b9     MOVSX      EDX,byte ptr [EBP]
    //         0044a1bd     MOV        EBX,dword ptr [EAX + 0x98]
    //         0044a1c3     ADD        EBX,EDX
    //         0044a1c5     INC        EBP
    //         0044a1c6     MOV        dword ptr [EAX + 0x98],EBX
    //         0044a1cc     MOV        this,byte ptr [EBP]
    //         0044a1cf     INC        EBP
    //         0044a1d0     TEST       this,this
    //         0044a1d2     JLE        LAB_0044a1ff
    //         0044a1d4     MOVSX      EDX,this
    //         0044a1d7     SHL        EDX,0x1
    //         0044a1d9     MOV        this,EDX
    //         0044a1db     MOV        EDI,EBX
    //         0044a1dd     MOV        EBX,this
    //         0044a1df     MOV        ESI,EBP
    //         0044a1e1     SHR        this,0x2
    //         0044a1e4     MOVSD.REP  ES:EDI,ESI
    //         0044a1e6     MOV        this,EBX
    //         0044a1e8     AND        this,0x3
    //         0044a1eb     MOVSB.REP  ES:EDI,ESI
    //         0044a1ed     MOV        ESI,dword ptr [EAX + 0x98]
    //         0044a1f3     ADD        ESI,EDX
    //         0044a1f5     ADD        EBP,EDX
    //         0044a1f7     MOV        dword ptr [EAX + 0x98],ESI
    //         0044a1fd     JMP        LAB_0044a251
    //                               LAB_0044a1ff                                                 XREF[1]:     0044a1d2(j)  
    //                              flics.cpp:422 (7)
    //         0044a1ff     MOVSX      this,this
    //         0044a202     NEG        this
    //         0044a204     SHL        this,0x1
    //                              flics.cpp:423 (5)
    //         0044a206     CMP        this,0x1
    //         0044a209     JLE        LAB_0044a234
    //                              flics.cpp:441 (38)
    //         0044a20b     MOV        EDX,this
    //         0044a20d     SHR        EDX,0x1
    //                               LAB_0044a20f                                                 XREF[1]:     0044a22f(j)  
    //         0044a20f     MOV        ESI,dword ptr [EAX + 0x98]
    //         0044a215     MOV        DI,word ptr [EBP]
    //         0044a219     SUB        this,0x2
    //         0044a21c     MOV        word ptr [ESI],DI
    //         0044a21f     MOV        EBX,dword ptr [EAX + 0x98]
    //         0044a225     ADD        EBX,0x2
    //         0044a228     DEC        EDX
    //         0044a229     MOV        dword ptr [EAX + 0x98],EBX
    //         0044a22f     JNZ        LAB_0044a20f
    //                              flics.cpp:428 (5)
    //         0044a231     CMP        this,0x1
    //                               LAB_0044a234                                                 XREF[1]:     0044a209(j)  
    //         0044a234     JNZ        LAB_0044a24e
    //                              flics.cpp:430 (11)
    //         0044a236     MOV        this,dword ptr [EAX + 0x98]
    //         0044a23c     MOV        DL,byte ptr [EBP]
    //         0044a23f     MOV        byte ptr [this->flic_buffer],DL
    //                              flics.cpp:431 (13)
    //         0044a241     MOV        this,dword ptr [EAX + 0x98]
    //         0044a247     INC        this
    //         0044a248     MOV        dword ptr [EAX + 0x98],this
    //                               LAB_0044a24e                                                 XREF[1]:     0044a234(j)  
    //                              flics.cpp:433 (3)
    //         0044a24e     ADD        EBP,0x2
    //                               LAB_0044a251                                                 XREF[1]:     0044a1fd(j)  
    //                              flics.cpp:406 (15)
    //         0044a251     MOV        this,dword ptr [ESP + local_8]
    //         0044a255     DEC        this
    //         0044a256     MOV        dword ptr [ESP + local_8],this
    //         0044a25a     JNZ        LAB_0044a1b9
    //                               LAB_0044a260                                                 XREF[1]:     0044a1ac(j)  
    //                              flics.cpp:438 (21)
    //         0044a260     MOV        this,dword ptr [EAX + 0x90]
    //         0044a266     MOV        EDX,dword ptr [EAX + 0x9c]
    //         0044a26c     MOV        ESI,dword ptr [ESP + local_c]
    //         0044a270     ADD        EDX,this
    //         0044a272     MOV        this,EDX
    //         0044a274     INC        ESI
    //                              flics.cpp:439 (34)
    //         0044a275     MOV        dword ptr [EAX + 0x98],this
    //         0044a27b     MOV        this,dword ptr [ESP + local_4]
    //         0044a27f     DEC        this
    //         0044a280     MOV        dword ptr [ESP + local_c],ESI
    //         0044a284     MOV        dword ptr [EAX + 0x9c],EDX
    //         0044a28a     MOV        dword ptr [ESP + local_4],this
    //         0044a28e     JNZ        LAB_0044a12a
    //         0044a294     POP        EBX
    //         0044a295     POP        ESI
    //         0044a296     POP        EDI
    //                               LAB_0044a297                                                 XREF[1]:     0044a11d(j)  
    //                              flics.cpp:441 (5)
    //         0044a297     POP        EBP
    //         0044a298     ADD        ESP,0xc
    //         0044a29b     RET
}

// Offset: 0x0044A2A0
void delta_fli(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall RGE_Flic_Player::delta_fli(void)                                             *
    //                              *********************************************************************************************************
    //                              void __thiscall delta_fli(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044a2e2(W), 0044a30e(R)  
    //              long              Stack[-0x8]:4  cur_x                     XREF[3]:     0044a2c1(W), 0044a369(R), 0044a376(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0044a2d4(W), 0044a34c(R), 0044a353(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[4]:     0044a2a7(W), 0044a319(R), 0044a328(R), 0044a348(R)  
    //                               ?delta_fli@RGE_Flic_Player@@AAEXXZ                           XREF[1]:     draw:00449fda(c)  
    //                               RGE_Flic_Player::delta_fli
    //                              flics.cpp:445 (11)
    //         0044a2a0     SUB        ESP,0x10
    //         0044a2a3     PUSH       EBP
    //         0044a2a4     PUSH       ESI
    //         0044a2a5     MOV        ESI,this
    //         0044a2a7     MOV        dword ptr [ESP + local_10],ESI
    //                              flics.cpp:451 (6)
    //         0044a2ab     MOV        EBP,dword ptr [ESI + 0xa0]
    //                              flics.cpp:454 (3)
    //         0044a2b1     MOV        EAX,dword ptr [EBP]
    //                              flics.cpp:457 (3)
    //         0044a2b4     ADD        EBP,0x8
    //                              flics.cpp:459 (14)
    //         0044a2b7     TEST       EAX,EAX
    //         0044a2b9     JLE        LAB_0044a382
    //         0044a2bf     PUSH       EDI
    //         0044a2c0     PUSH       EBX
    //         0044a2c1     MOV        dword ptr [ESP + cur_x],EAX
    //                               LAB_0044a2c5                                                 XREF[1]:     0044a37a(j)  
    //                              flics.cpp:462 (6)
    //         0044a2c5     MOVSX      EAX,byte ptr [EBP]
    //         0044a2c9     XOR        EBX,EBX
    //                              flics.cpp:463 (1)
    //         0044a2cb     INC        EBP
    //                              flics.cpp:464 (8)
    //         0044a2cc     TEST       EAX,EAX
    //         0044a2ce     JLE        LAB_0044a35d
    //                              flics.cpp:461 (4)
    //         0044a2d4     MOV        dword ptr [ESP + local_c],EAX
    //                               LAB_0044a2d8                                                 XREF[1]:     0044a357(j)  
    //                              flics.cpp:466 (6)
    //         0044a2d8     MOVSX      EAX,byte ptr [EBP]
    //         0044a2dc     ADD        EBX,EAX
    //                              flics.cpp:468 (8)
    //         0044a2de     MOV        AL,byte ptr [EBP + 0x1]
    //         0044a2e1     INC        EBP
    //         0044a2e2     MOV        dword ptr [ESP + local_4],EBX
    //                              flics.cpp:469 (1)
    //         0044a2e6     INC        EBP
    //                              flics.cpp:470 (4)
    //         0044a2e7     TEST       AL,AL
    //         0044a2e9     JGE        LAB_0044a325
    //                              flics.cpp:472 (2)
    //         0044a2eb     NEG        AL
    //                              flics.cpp:473 (33)
    //         0044a2ed     MOVSX      EDX,AL
    //         0044a2f0     MOVSX      EAX,byte ptr [EBP]
    //         0044a2f4     MOV        EDI,EBX
    //         0044a2f6     MOV        EBX,dword ptr [ESI + 0x98]
    //         0044a2fc     ADD        EDI,EBX
    //         0044a2fe     MOV        BL,AL
    //         0044a300     MOV        BH,BL
    //         0044a302     MOV        this,EDX
    //         0044a304     MOV        EAX,EBX
    //         0044a306     MOV        ESI,this
    //         0044a308     SHL        EAX,0x10
    //         0044a30b     MOV        AX,BX
    //                              flics.cpp:476 (23)
    //         0044a30e     MOV        EBX,dword ptr [ESP + local_4]
    //         0044a312     SHR        this,0x2
    //         0044a315     STOSD.REP  ES:EDI
    //         0044a317     MOV        this,ESI
    //         0044a319     MOV        ESI,dword ptr [ESP + local_10]
    //         0044a31d     AND        this,0x3
    //         0044a320     INC        EBP
    //         0044a321     STOSB.REP  ES:EDI
    //         0044a323     JMP        LAB_0044a34c
    //                               LAB_0044a325                                                 XREF[1]:     0044a2e9(j)  
    //                              flics.cpp:478 (31)
    //         0044a325     MOVSX      EDX,AL
    //         0044a328     MOV        EAX,dword ptr [ESP + local_10]
    //         0044a32c     MOV        EDI,EBX
    //         0044a32e     MOV        this,EDX
    //         0044a330     MOV        ESI,EBP
    //         0044a332     ADD        EDI,dword ptr [EAX + 0x98]
    //         0044a338     MOV        EAX,this
    //         0044a33a     SHR        this,0x2
    //         0044a33d     MOVSD.REP  ES:EDI,ESI
    //         0044a33f     MOV        this,EAX
    //         0044a341     AND        this,0x3
    //                              flics.cpp:479 (12)
    //         0044a344     ADD        EBP,EDX
    //         0044a346     MOVSB.REP  ES:EDI,ESI
    //         0044a348     MOV        ESI,dword ptr [ESP + local_10]
    //                               LAB_0044a34c                                                 XREF[1]:     0044a323(j)  
    //         0044a34c     MOV        EAX,dword ptr [ESP + local_c]
    //                              flics.cpp:482 (13)
    //         0044a350     ADD        EBX,EDX
    //         0044a352     DEC        EAX
    //         0044a353     MOV        dword ptr [ESP + local_c],EAX
    //         0044a357     JNZ        LAB_0044a2d8
    //                               LAB_0044a35d                                                 XREF[1]:     0044a2ce(j)  
    //                              flics.cpp:486 (37)
    //         0044a35d     MOV        this,dword ptr [ESI + 0x90]
    //         0044a363     MOV        EDX,dword ptr [ESI + 0x98]
    //         0044a369     MOV        EAX,dword ptr [ESP + cur_x]
    //         0044a36d     ADD        EDX,this
    //         0044a36f     DEC        EAX
    //         0044a370     MOV        dword ptr [ESI + 0x98],EDX
    //         0044a376     MOV        dword ptr [ESP + cur_x],EAX
    //         0044a37a     JNZ        LAB_0044a2c5
    //         0044a380     POP        EBX
    //         0044a381     POP        EDI
    //                               LAB_0044a382                                                 XREF[1]:     0044a2b9(j)  
    //                              flics.cpp:488 (6)
    //         0044a382     POP        ESI
    //         0044a383     POP        EBP
    //         0044a384     ADD        ESP,0x10
    //         0044a387     RET
}

// Offset: 0x0044A390
void black(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall RGE_Flic_Player::black(void)                                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall black(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //                               ?black@RGE_Flic_Player@@AAEXXZ                               XREF[1]:     draw:00449fe3(c)  
    //                               RGE_Flic_Player::black
    //                              flics.cpp:492 (3)
    //         0044a390     MOV        EDX,this
    //         0044a392     PUSH       ESI
    //                              flics.cpp:495 (14)
    //         0044a393     XOR        ESI,ESI
    //         0044a395     MOV        EAX,dword ptr [EDX + 0xb8]
    //         0044a39b     TEST       EAX,EAX
    //         0044a39d     JLE        LAB_0044a3de
    //         0044a39f     PUSH       EDI
    //         0044a3a0     PUSH       EBX
    //                               LAB_0044a3a1                                                 XREF[1]:     0044a3da(j)  
    //                              flics.cpp:497 (28)
    //         0044a3a1     MOV        this,dword ptr [EDX + 0xb4]
    //         0044a3a7     MOV        EDI,dword ptr [EDX + 0x98]
    //         0044a3ad     MOV        EBX,this
    //         0044a3af     XOR        EAX,EAX
    //         0044a3b1     SHR        this,0x2
    //         0044a3b4     STOSD.REP  ES:EDI
    //         0044a3b6     MOV        this,EBX
    //         0044a3b8     AND        this,0x3
    //         0044a3bb     STOSB.REP  ES:EDI
    //                              flics.cpp:498 (33)
    //         0044a3bd     MOV        EAX,dword ptr [EDX + 0x90]
    //         0044a3c3     MOV        EDI,dword ptr [EDX + 0x98]
    //         0044a3c9     ADD        EDI,EAX
    //         0044a3cb     MOV        EAX,dword ptr [EDX + 0xb8]
    //         0044a3d1     INC        ESI
    //         0044a3d2     MOV        dword ptr [EDX + 0x98],EDI
    //         0044a3d8     CMP        ESI,EAX
    //         0044a3da     JL         LAB_0044a3a1
    //         0044a3dc     POP        EBX
    //         0044a3dd     POP        EDI
    //                               LAB_0044a3de                                                 XREF[1]:     0044a39d(j)  
    //                              flics.cpp:500 (2)
    //         0044a3de     POP        ESI
    //         0044a3df     RET
}

// Offset: 0x0044A3E0
void byte_run(RGE_Flic_Player* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: void __thiscall RGE_Flic_Player::byte_run(void)                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall byte_run(RGE_Flic_Player * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Flic_Playe    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0044a40c(W), 0044a49a(R), 0044a4a7(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     0044a413(W), 0044a43e(R), 0044a488(W)  
    //              long              Stack[-0xc]:4  cur_x                     XREF[4]:     0044a3e6(W), 0044a449(R), 0044a45a(R), 0044a47a(R)  
    //                               ?byte_run@RGE_Flic_Player@@AAEXXZ                            XREF[1]:     draw:00449fec(c)  
    //                               RGE_Flic_Player::byte_run
    //                              flics.cpp:504 (10)
    //         0044a3e0     SUB        ESP,0xc
    //         0044a3e3     PUSH       ESI
    //         0044a3e4     MOV        ESI,this
    //         0044a3e6     MOV        dword ptr [ESP + cur_x],ESI
    //                              flics.cpp:507 (12)
    //         0044a3ea     MOV        EAX,dword ptr [ESI + 0xa8]
    //         0044a3f0     MOV        this,dword ptr [ESI + 0xb8]
    //                              flics.cpp:508 (10)
    //         0044a3f6     MOV        EDX,dword ptr [ESI + 0xa0]
    //         0044a3fc     LEA        EAX,[EAX + this->flic_buffer*0x1 + -0x1]
    //                              flics.cpp:512 (16)
    //         0044a400     TEST       EAX,EAX
    //         0044a402     JL         LAB_0044a4b4
    //         0044a408     PUSH       EDI
    //         0044a409     INC        EAX
    //         0044a40a     PUSH       EBP
    //         0044a40b     PUSH       EBX
    //         0044a40c     MOV        dword ptr [ESP + local_4],EAX
    //                               LAB_0044a410                                                 XREF[1]:     0044a4ab(j)  
    //                              flics.cpp:514 (2)
    //         0044a410     XOR        EBX,EBX
    //                              flics.cpp:515 (5)
    //         0044a412     INC        EDX
    //         0044a413     MOV        dword ptr [ESP + local_8],EBX
    //                               LAB_0044a417                                                 XREF[1]:     0044a48c(j)  
    //                              flics.cpp:519 (2)
    //         0044a417     MOV        AL,byte ptr [EDX]
    //                              flics.cpp:520 (1)
    //         0044a419     INC        EDX
    //                              flics.cpp:522 (4)
    //         0044a41a     TEST       AL,AL
    //         0044a41c     JL         LAB_0044a455
    //                              flics.cpp:524 (32)
    //         0044a41e     MOVSX      EBP,AL
    //         0044a421     MOVSX      EAX,byte ptr [EDX]
    //         0044a424     MOV        EDI,EBX
    //         0044a426     MOV        EBX,dword ptr [ESI + 0x98]
    //         0044a42c     ADD        EDI,EBX
    //         0044a42e     MOV        BL,AL
    //         0044a430     MOV        BH,BL
    //         0044a432     MOV        this,EBP
    //         0044a434     MOV        EAX,EBX
    //         0044a436     MOV        ESI,this
    //         0044a438     SHL        EAX,0x10
    //         0044a43b     MOV        AX,BX
    //                              flics.cpp:527 (23)
    //         0044a43e     MOV        EBX,dword ptr [ESP + local_8]
    //         0044a442     SHR        this,0x2
    //         0044a445     STOSD.REP  ES:EDI
    //         0044a447     MOV        this,ESI
    //         0044a449     MOV        ESI,dword ptr [ESP + cur_x]
    //         0044a44d     AND        this,0x3
    //         0044a450     INC        EDX
    //         0044a451     STOSB.REP  ES:EDI
    //         0044a453     JMP        LAB_0044a47e
    //                               LAB_0044a455                                                 XREF[1]:     0044a41c(j)  
    //                              flics.cpp:529 (2)
    //         0044a455     NEG        AL
    //                              flics.cpp:531 (31)
    //         0044a457     MOVSX      EBP,AL
    //         0044a45a     MOV        EAX,dword ptr [ESP + cur_x]
    //         0044a45e     MOV        EDI,EBX
    //         0044a460     MOV        this,EBP
    //         0044a462     MOV        ESI,EDX
    //         0044a464     ADD        EDI,dword ptr [EAX + 0x98]
    //         0044a46a     MOV        EAX,this
    //         0044a46c     SHR        this,0x2
    //         0044a46f     MOVSD.REP  ES:EDI,ESI
    //         0044a471     MOV        this,EAX
    //         0044a473     AND        this,0x3
    //                              flics.cpp:532 (8)
    //         0044a476     ADD        EDX,EBP
    //         0044a478     MOVSB.REP  ES:EDI,ESI
    //         0044a47a     MOV        ESI,dword ptr [ESP + cur_x]
    //                               LAB_0044a47e                                                 XREF[1]:     0044a453(j)  
    //                              flics.cpp:536 (16)
    //         0044a47e     MOV        EAX,dword ptr [ESI + 0x94]
    //         0044a484     ADD        EBX,EBP
    //         0044a486     CMP        EBX,EAX
    //         0044a488     MOV        dword ptr [ESP + local_8],EBX
    //         0044a48c     JL         LAB_0044a417
    //                              flics.cpp:539 (38)
    //         0044a48e     MOV        this,dword ptr [ESI + 0x90]
    //         0044a494     MOV        EDI,dword ptr [ESI + 0x98]
    //         0044a49a     MOV        EAX,dword ptr [ESP + local_4]
    //         0044a49e     ADD        EDI,this
    //         0044a4a0     DEC        EAX
    //         0044a4a1     MOV        dword ptr [ESI + 0x98],EDI
    //         0044a4a7     MOV        dword ptr [ESP + local_4],EAX
    //         0044a4ab     JNZ        LAB_0044a410
    //         0044a4b1     POP        EBX
    //         0044a4b2     POP        EBP
    //         0044a4b3     POP        EDI
    //                               LAB_0044a4b4                                                 XREF[1]:     0044a402(j)  
    //                              flics.cpp:541 (5)
    //         0044a4b4     POP        ESI
    //         0044a4b5     ADD        ESP,0xc
    //         0044a4b8     RET
}

