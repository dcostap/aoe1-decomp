// Auto-generated scaffold unit: Shape.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Shape.cpp
#include "../include/common.h"

// Offset: 0x004B8B30
undefined TShape(TShape* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TShape::TShape(void)                                                               *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TShape(TShape * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //                               ??0TShape@@QAE@XZ
    //                               TShape::TShape
    //                              Shape.cpp:53 (2)
    //         004b8b30     MOV        EAX,this
    //                              Shape.cpp:54 (4)
    //         004b8b32     XOR        this,this
    //         004b8b34     MOV        dword ptr [EAX],this
    //                              Shape.cpp:55 (3)
    //         004b8b36     MOV        dword ptr [EAX + 0xc],this
    //                              Shape.cpp:56 (3)
    //         004b8b39     MOV        dword ptr [EAX + 0x10],this
    //                              Shape.cpp:57 (3)
    //         004b8b3c     MOV        dword ptr [EAX + 0x14],this
    //                              Shape.cpp:58 (3)
    //         004b8b3f     MOV        dword ptr [EAX + 0x18],this
    //                              Shape.cpp:59 (3)
    //         004b8b42     MOV        dword ptr [EAX + 0x1c],this
    //                              Shape.cpp:61 (7)
    //         004b8b45     MOV        dword ptr [EAX + 0x4],0xffffffff
    //                              Shape.cpp:62 (3)
    //         004b8b4c     MOV        dword ptr [EAX + 0x8],this
    //                              Shape.cpp:63 (1)
    //         004b8b4f     RET
}

// Offset: 0x004B8B50
undefined TShape(TShape* this_, char* param_2, long param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TShape::TShape(char *,long)                                                        *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TShape(TShape * this, char * param_1, long para
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004b8b95(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004b8b77(R), 004b8d2d(R)  
    //              char[260]         Stack[-0x108   NextFile                  XREF[0,5]:   004b8baa(*), 004b8bc7(*), 004b8bff(*), 004b8c7c(*), 
    //                                                                                     004b8cb5(*)  
    //                               ??0TShape@@QAE@PADJ@Z                                        XREF[51]:    LoadCursors:0045b39c(c), 
    //                               TShape::TShape                                                            set_background:00467b2f(c), 
    //                                                                                                         set_background:00467b67(c), 
    //                                                                                                         set_background2:00467c9f(c), 
    //                                                                                                         set_background2:00467cd7(c), 
    //                                                                                                         set_button_pics:0046811f(c), 
    //                                                                                                         set_button_pics:00468157(c), 
    //                                                                                                         load_pic:0047a44c(c), 
    //                                                                                                         set_back_pic:0047cc84(c), 
    //                                                                                                         player_changed:00498dbb(c), 
    //                                                                                                         player_changed:00498deb(c), 
    //                                                                                                         player_changed:00498e5f(c), 
    //                                                                                                         player_changed:00498e8f(c), 
    //                                                                                                         player_changed:00498f00(c), 
    //                                                                                                         player_changed:00498f30(c), 
    //                                                                                                         player_changed:00498fa1(c), 
    //                                                                                                         player_changed:00498fd1(c), 
    //                                                                                                         player_changed:004990bb(c), 
    //                                                                                                         get_size:004c08c6(c), 
    //                                                                                                         get_frame:004c09e0(c), [more]
    //                              Shape.cpp:67 (6)
    //         004b8b50     SUB        ESP,0x104
    //                              Shape.cpp:73 (11)
    //         004b8b56     XOR        EAX,EAX
    //         004b8b58     PUSH       EBX
    //         004b8b59     PUSH       EBP
    //         004b8b5a     MOV        EBP,this
    //         004b8b5c     PUSH       ESI
    //         004b8b5d     PUSH       EDI
    //         004b8b5e     MOV        dword ptr [EBP],EAX
    //                              Shape.cpp:74 (3)
    //         004b8b61     MOV        dword ptr [EBP + 0xc],EAX
    //                              Shape.cpp:75 (3)
    //         004b8b64     MOV        dword ptr [EBP + 0x10],EAX
    //                              Shape.cpp:76 (3)
    //         004b8b67     MOV        dword ptr [EBP + 0x14],EAX
    //                              Shape.cpp:77 (3)
    //         004b8b6a     MOV        dword ptr [EBP + 0x18],EAX
    //                              Shape.cpp:79 (25)
    //         004b8b6d     MOV        this,byte ptr [shape_file_first]                 = 00h
    //         004b8b73     TEST       this,this
    //         004b8b75     JNZ        LAB_004b8b86
    //         004b8b77     MOV        EBX,dword ptr [ESP + param_2]
    //         004b8b7e     CMP        EBX,EAX
    //         004b8b80     JGE        LAB_004b8d39
    //                               LAB_004b8b86                                                 XREF[1]:     004b8b75(j)  
    //                              Shape.cpp:84 (15)
    //         004b8b86     MOV        EBX,0x1
    //         004b8b8b     PUSH       EBX
    //         004b8b8c     PUSH       0x54
    //         004b8b8e     PUSH       0x54
    //         004b8b90     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //                              Shape.cpp:86 (31)
    //         004b8b95     MOV        EDI,dword ptr [ESP + param_1]
    //         004b8b9c     OR         this,0xffffffff
    //         004b8b9f     XOR        EAX,EAX
    //         004b8ba1     ADD        ESP,0xc
    //         004b8ba4     SCASB.RE   ES:EDI
    //         004b8ba6     NOT        this
    //         004b8ba8     SUB        EDI,this
    //         004b8baa     LEA        EDX=>NextFile[4],[ESP + 0x10]
    //         004b8bae     MOV        EAX,this
    //         004b8bb0     MOV        ESI,EDI
    //         004b8bb2     MOV        EDI,EDX
    //                              Shape.cpp:92 (102)
    //         004b8bb4     PUSH       0x8000
    //         004b8bb9     SHR        this,0x2
    //         004b8bbc     MOVSD.REP  ES:EDI,ESI
    //         004b8bbe     MOV        this,EAX
    //         004b8bc0     XOR        EAX,EAX
    //         004b8bc2     AND        this,0x3
    //         004b8bc5     MOVSB.REP  ES:EDI,ESI
    //         004b8bc7     LEA        EDI=>NextFile[4],[ESP + 0x14]
    //         004b8bcb     OR         this,0xffffffff
    //         004b8bce     SCASB.RE   ES:EDI
    //         004b8bd0     NOT        this
    //         004b8bd2     ADD        this,-0x4
    //         004b8bd5     MOV        EDI,s_SLP                                        = 53h    S
    //         004b8bda     LEA        EDX,[ESP + this->shape*0x1 + 0x14]
    //         004b8bde     OR         this,0xffffffff
    //         004b8be1     SCASB.RE   ES:EDI=>s_SLP                                    = 53h    S
    //                                                                                  = 4Ch
    //         004b8be3     NOT        this
    //         004b8be5     SUB        EDI,this
    //         004b8be7     MOV        EAX,this
    //         004b8be9     MOV        ESI,EDI
    //         004b8beb     MOV        EDI,EDX
    //         004b8bed     SHR        this,0x2
    //         004b8bf0     MOVSD.REP  ES:EDI,ESI
    //         004b8bf2     MOV        this,EAX
    //         004b8bf4     AND        this,0x3
    //         004b8bf7     MOVSB.REP  ES:EDI,ESI
    //         004b8bf9     MOV        EDI,dword ptr [Shape_Loads]
    //         004b8bff     LEA        this=>NextFile[4],[ESP + 0x14]
    //         004b8c03     INC        EDI
    //         004b8c04     PUSH       this
    //         004b8c05     MOV        dword ptr [Shape_Loads],EDI
    //         004b8c0b     CALL       __open                                           undefined __open()
    //         004b8c10     MOV        ESI,EAX
    //         004b8c12     ADD        ESP,0x8
    //         004b8c15     CMP        ESI,-0x1
    //         004b8c18     JZ         LAB_004b8c71
    //                              Shape.cpp:94 (13)
    //         004b8c1a     PUSH       0x2
    //         004b8c1c     PUSH       0x0
    //         004b8c1e     PUSH       ESI
    //         004b8c1f     CALL       lseek                                            undefined lseek()
    //         004b8c24     ADD        ESP,0xc
    //                              Shape.cpp:95 (11)
    //         004b8c27     PUSH       ESI
    //         004b8c28     CALL       __tell                                           undefined __tell()
    //         004b8c2d     ADD        ESP,0x4
    //         004b8c30     MOV        EDI,EAX
    //                              Shape.cpp:97 (12)
    //         004b8c32     PUSH       EDI
    //         004b8c33     CALL       malloc                                           undefined malloc()
    //         004b8c38     ADD        ESP,0x4
    //         004b8c3b     MOV        dword ptr [EBP + 0x18],EAX
    //                              Shape.cpp:99 (10)
    //         004b8c3e     PUSH       0x0
    //         004b8c40     PUSH       0x0
    //         004b8c42     PUSH       ESI
    //         004b8c43     CALL       lseek                                            undefined lseek()
    //                              Shape.cpp:100 (17)
    //         004b8c48     MOV        EDX,dword ptr [EBP + 0x18]
    //         004b8c4b     ADD        ESP,0xc
    //         004b8c4e     PUSH       EDI
    //         004b8c4f     PUSH       EDX
    //         004b8c50     PUSH       ESI
    //         004b8c51     CALL       read                                             undefined read()
    //         004b8c56     ADD        ESP,0xc
    //                              Shape.cpp:101 (6)
    //         004b8c59     PUSH       ESI
    //         004b8c5a     CALL       close                                            undefined close()
    //                              Shape.cpp:103 (9)
    //         004b8c5f     MOV        EAX,dword ptr [EBP + 0x18]
    //         004b8c62     ADD        ESP,0x4
    //         004b8c65     ADD        EAX,0x20
    //                              Shape.cpp:104 (6)
    //         004b8c68     MOV        dword ptr [EBP + 0x4],EBX
    //         004b8c6b     MOV        dword ptr [EBP + 0x1c],EAX
    //                              Shape.cpp:105 (3)
    //         004b8c6e     MOV        dword ptr [EBP + 0x8],EDI
    //                               LAB_004b8c71                                                 XREF[1]:     004b8c18(j)  
    //                              Shape.cpp:110 (11)
    //         004b8c71     MOV        EAX,dword ptr [EBP + 0x18]
    //         004b8c74     TEST       EAX,EAX
    //         004b8c76     JNZ        LAB_004b8d23
    //                              Shape.cpp:112 (9)
    //         004b8c7c     LEA        EDI=>NextFile[4],[ESP + 0x10]
    //         004b8c80     OR         this,0xffffffff
    //         004b8c83     XOR        EAX,EAX
    //                              Shape.cpp:114 (68)
    //         004b8c85     PUSH       0x8000
    //         004b8c8a     SCASB.RE   ES:EDI
    //         004b8c8c     NOT        this
    //         004b8c8e     ADD        this,-0x4
    //         004b8c91     MOV        EDI,s_SHP                                        = 53h    S
    //         004b8c96     LEA        EDX,[ESP + this->shape*0x1 + 0x14]
    //         004b8c9a     OR         this,0xffffffff
    //         004b8c9d     SCASB.RE   ES:EDI=>s_SHP                                    = 53h    S
    //                                                                                  = 48h
    //         004b8c9f     NOT        this
    //         004b8ca1     SUB        EDI,this
    //         004b8ca3     MOV        EAX,this
    //         004b8ca5     MOV        ESI,EDI
    //         004b8ca7     MOV        EDI,EDX
    //         004b8ca9     SHR        this,0x2
    //         004b8cac     MOVSD.REP  ES:EDI,ESI
    //         004b8cae     MOV        this,EAX
    //         004b8cb0     AND        this,0x3
    //         004b8cb3     MOVSB.REP  ES:EDI,ESI
    //         004b8cb5     LEA        this=>NextFile[4],[ESP + 0x14]
    //         004b8cb9     PUSH       this
    //         004b8cba     CALL       __open                                           undefined __open()
    //         004b8cbf     MOV        ESI,EAX
    //         004b8cc1     ADD        ESP,0x8
    //         004b8cc4     CMP        ESI,-0x1
    //         004b8cc7     JZ         LAB_004b8d23
    //                              Shape.cpp:116 (13)
    //         004b8cc9     PUSH       0x2
    //         004b8ccb     PUSH       0x0
    //         004b8ccd     PUSH       ESI
    //         004b8cce     CALL       lseek                                            undefined lseek()
    //         004b8cd3     ADD        ESP,0xc
    //                              Shape.cpp:117 (11)
    //         004b8cd6     PUSH       ESI
    //         004b8cd7     CALL       __tell                                           undefined __tell()
    //         004b8cdc     ADD        ESP,0x4
    //         004b8cdf     MOV        EDI,EAX
    //                              Shape.cpp:119 (12)
    //         004b8ce1     PUSH       EDI
    //         004b8ce2     CALL       malloc                                           undefined malloc()
    //         004b8ce7     ADD        ESP,0x4
    //         004b8cea     MOV        dword ptr [EBP],EAX
    //                              Shape.cpp:121 (10)
    //         004b8ced     PUSH       0x0
    //         004b8cef     PUSH       0x0
    //         004b8cf1     PUSH       ESI
    //         004b8cf2     CALL       lseek                                            undefined lseek()
    //                              Shape.cpp:122 (17)
    //         004b8cf7     MOV        EDX,dword ptr [EBP]
    //         004b8cfa     ADD        ESP,0xc
    //         004b8cfd     PUSH       EDI
    //         004b8cfe     PUSH       EDX
    //         004b8cff     PUSH       ESI
    //         004b8d00     CALL       read                                             undefined read()
    //         004b8d05     ADD        ESP,0xc
    //                              Shape.cpp:123 (6)
    //         004b8d08     PUSH       ESI
    //         004b8d09     CALL       close                                            undefined close()
    //                              Shape.cpp:125 (9)
    //         004b8d0e     MOV        EAX,dword ptr [EBP]
    //         004b8d11     ADD        ESP,0x4
    //         004b8d14     MOV        dword ptr [EBP + 0x10],EAX
    //                              Shape.cpp:126 (6)
    //         004b8d17     ADD        EAX,0x8
    //         004b8d1a     MOV        dword ptr [EBP + 0x14],EAX
    //                              Shape.cpp:128 (3)
    //         004b8d1d     MOV        dword ptr [EBP + 0x4],EBX
    //                              Shape.cpp:129 (3)
    //         004b8d20     MOV        dword ptr [EBP + 0x8],EDI
    //                               LAB_004b8d23                                                 XREF[2]:     004b8c76(j), 004b8cc7(j)  
    //                              Shape.cpp:133 (22)
    //         004b8d23     PUSH       EBX
    //         004b8d24     PUSH       0x5f
    //         004b8d26     PUSH       0x54
    //         004b8d28     CALL       color_log                                        void color_log(uchar param_1, uchar param_2, 
    //         004b8d2d     MOV        EBX,dword ptr [ESP + param_2]
    //         004b8d34     ADD        ESP,0xc
    //         004b8d37     XOR        EAX,EAX
    //                               LAB_004b8d39                                                 XREF[1]:     004b8b80(j)  
    //                              Shape.cpp:137 (14)
    //         004b8d39     CMP        dword ptr [EBP + 0x18],EAX
    //         004b8d3c     JNZ        LAB_004b8dbc
    //         004b8d3e     CMP        dword ptr [EBP],EAX
    //         004b8d41     JNZ        LAB_004b8dbc
    //         004b8d43     CMP        EBX,EAX
    //         004b8d45     JL         LAB_004b8dbc
    //                              Shape.cpp:141 (6)
    //         004b8d47     MOV        this,dword ptr [Shape_Loads]
    //                              Shape.cpp:143 (32)
    //         004b8d4d     LEA        ESI,[EBP + 0x8]
    //         004b8d50     LEA        EDI,[EBP + 0x4]
    //         004b8d53     PUSH       ESI
    //         004b8d54     PUSH       EDI
    //         004b8d55     INC        this
    //         004b8d56     PUSH       EBX
    //         004b8d57     PUSH       0x73687020
    //         004b8d5c     MOV        dword ptr [Shape_Loads],this
    //         004b8d62     CALL       RESFILE_load                                     uchar * RESFILE_load(ulong param_1, ulong par
    //         004b8d67     ADD        ESP,0x10
    //         004b8d6a     MOV        dword ptr [EBP],EAX
    //                              Shape.cpp:145 (4)
    //         004b8d6d     TEST       EAX,EAX
    //         004b8d6f     JZ         LAB_004b8d95
    //                              Shape.cpp:147 (12)
    //         004b8d71     MOV        this,dword ptr [EAX]
    //         004b8d73     MOV        EDX,dword ptr [s_1.10]                           = "1.10"
    //         004b8d79     CMP        this,EDX
    //         004b8d7b     JNZ        LAB_004b8dbc
    //                              Shape.cpp:149 (3)
    //         004b8d7d     MOV        dword ptr [EBP + 0x10],EAX
    //                              Shape.cpp:150 (6)
    //         004b8d80     ADD        EAX,0x8
    //         004b8d83     MOV        dword ptr [EBP + 0x14],EAX
    //                              Shape.cpp:176 (15)
    //         004b8d86     MOV        EAX,EBP
    //         004b8d88     POP        EDI
    //         004b8d89     POP        ESI
    //         004b8d8a     POP        EBP
    //         004b8d8b     POP        EBX
    //         004b8d8c     ADD        ESP,0x104
    //         004b8d92     RET        0x8
    //                               LAB_004b8d95                                                 XREF[1]:     004b8d6f(j)  
    //                              Shape.cpp:157 (19)
    //         004b8d95     PUSH       ESI
    //         004b8d96     PUSH       EDI
    //         004b8d97     PUSH       EBX
    //         004b8d98     PUSH       0x736c7020
    //         004b8d9d     CALL       RESFILE_load                                     uchar * RESFILE_load(ulong param_1, ulong par
    //         004b8da2     ADD        ESP,0x10
    //         004b8da5     MOV        dword ptr [EBP],EAX
    //                              Shape.cpp:159 (4)
    //         004b8da8     TEST       EAX,EAX
    //         004b8daa     JZ         LAB_004b8dbc
    //                              Shape.cpp:161 (3)
    //         004b8dac     MOV        dword ptr [EBP + 0x18],EAX
    //                              Shape.cpp:164 (13)
    //         004b8daf     ADD        EAX,0x20
    //         004b8db2     MOV        dword ptr [EBP],0x0
    //         004b8db9     MOV        dword ptr [EBP + 0x1c],EAX
    //                               LAB_004b8dbc                                                 XREF[5]:     004b8d3c(j), 004b8d41(j), 
    //                                                                                                         004b8d45(j), 004b8d7b(j), 
    //                                                                                                         004b8daa(j)  
    //                              Shape.cpp:176 (15)
    //         004b8dbc     POP        EDI
    //         004b8dbd     MOV        EAX,EBP
    //         004b8dbf     POP        ESI
    //         004b8dc0     POP        EBP
    //         004b8dc1     POP        EBX
    //         004b8dc2     ADD        ESP,0x104
    //         004b8dc8     RET        0x8
}

// Offset: 0x004B8DD0
void TShape(TShape* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TShape::~TShape(void)                                                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TShape(TShape * this)
    //              void              <VOID>         <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //                               ??1TShape@@QAE@XZ                                            XREF[55]:    ~RGE_Map:004554db(c), 
    //                               TShape::~TShape                                                           ~RGE_Map:0045550b(c), 
    //                                                                                                         LoadCursors:0045b33f(c), 
    //                                                                                                         prepare_for_close:004672f2(c), 
    //                                                                                                         prepare_for_close:00467312(c), 
    //                                                                                                         prepare_for_close:00467363(c), 
    //                                                                                                         set_background:00467a9b(c), 
    //                                                                                                         set_background:00467ba0(c), 
    //                                                                                                         set_background2:00467c0b(c), 
    //                                                                                                         set_background2:00467d10(c), 
    //                                                                                                         set_button_pics:0046808b(c), 
    //                                                                                                         set_button_pics:00468190(c), 
    //                                                                                                         load_pic:0047a4f2(c), 
    //                                                                                                         free_pic:0047a600(c), 
    //                                                                                                         set_back_pic:0047cc3b(c), 
    //                                                                                                         player_changed:00498d6c(c), 
    //                                                                                                         player_changed:00498e10(c), 
    //                                                                                                         player_changed:00498eb1(c), 
    //                                                                                                         player_changed:00498f52(c), 
    //                                                                                                         player_changed:00498ff3(c), [more]
    //                              Shape.cpp:180 (4)
    //         004b8dd0     PUSH       ESI
    //         004b8dd1     MOV        ESI,this
    //         004b8dd3     PUSH       EDI
    //                              Shape.cpp:182 (9)
    //         004b8dd4     XOR        EDI,EDI
    //         004b8dd6     MOV        EAX,dword ptr [ESI + 0x18]
    //         004b8dd9     CMP        EAX,EDI
    //         004b8ddb     JZ         LAB_004b8e01
    //                              Shape.cpp:184 (6)
    //         004b8ddd     CMP        dword ptr [ESI + 0x4],0x1
    //         004b8de1     JNZ        LAB_004b8dec
    //                              Shape.cpp:185 (9)
    //         004b8de3     PUSH       EAX
    //         004b8de4     CALL       free                                             undefined free()
    //         004b8de9     ADD        ESP,0x4
    //                               LAB_004b8dec                                                 XREF[1]:     004b8de1(j)  
    //                              Shape.cpp:186 (5)
    //         004b8dec     CMP        dword ptr [ESI + 0x4],EDI
    //         004b8def     JNZ        LAB_004b8e01
    //                              Shape.cpp:187 (16)
    //         004b8df1     MOV        EAX,dword ptr [ESI + 0x8]
    //         004b8df4     MOV        this,dword ptr [ESI + 0x18]
    //         004b8df7     PUSH       EAX
    //         004b8df8     PUSH       this
    //         004b8df9     CALL       RESFILE_Decommit_Mapped_Memory                   int RESFILE_Decommit_Mapped_Memory(uchar * pa
    //         004b8dfe     ADD        ESP,0x8
    //                               LAB_004b8e01                                                 XREF[2]:     004b8ddb(j), 004b8def(j)  
    //                              Shape.cpp:190 (6)
    //         004b8e01     MOV        EAX,dword ptr [ESI]
    //         004b8e03     CMP        EAX,EDI
    //         004b8e05     JZ         LAB_004b8e2a
    //                              Shape.cpp:192 (6)
    //         004b8e07     CMP        dword ptr [ESI + 0x4],0x1
    //         004b8e0b     JNZ        LAB_004b8e16
    //                              Shape.cpp:193 (9)
    //         004b8e0d     PUSH       EAX
    //         004b8e0e     CALL       free                                             undefined free()
    //         004b8e13     ADD        ESP,0x4
    //                               LAB_004b8e16                                                 XREF[1]:     004b8e0b(j)  
    //                              Shape.cpp:194 (5)
    //         004b8e16     CMP        dword ptr [ESI + 0x4],EDI
    //         004b8e19     JNZ        LAB_004b8e2a
    //                              Shape.cpp:195 (15)
    //         004b8e1b     MOV        EDX,dword ptr [ESI + 0x8]
    //         004b8e1e     MOV        EAX,dword ptr [ESI]
    //         004b8e20     PUSH       EDX
    //         004b8e21     PUSH       EAX
    //         004b8e22     CALL       RESFILE_Decommit_Mapped_Memory                   int RESFILE_Decommit_Mapped_Memory(uchar * pa
    //         004b8e27     ADD        ESP,0x8
    //                               LAB_004b8e2a                                                 XREF[2]:     004b8e05(j), 004b8e19(j)  
    //                              Shape.cpp:198 (2)
    //         004b8e2a     MOV        dword ptr [ESI],EDI
    //                              Shape.cpp:199 (3)
    //         004b8e2c     MOV        dword ptr [ESI + 0xc],EDI
    //                              Shape.cpp:200 (3)
    //         004b8e2f     MOV        dword ptr [ESI + 0x10],EDI
    //                              Shape.cpp:201 (3)
    //         004b8e32     MOV        dword ptr [ESI + 0x14],EDI
    //                              Shape.cpp:202 (3)
    //         004b8e35     MOV        dword ptr [ESI + 0x18],EDI
    //                              Shape.cpp:203 (3)
    //         004b8e38     POP        EDI
    //         004b8e39     POP        ESI
    //         004b8e3a     RET
}

// Offset: 0x004B8E40
uchar Check_shape(TShape* this_, long param_2, char* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::Check_shape(long,char *)                                    *
    //                              *********************************************************************************************************
    //                              uchar __thiscall Check_shape(TShape * this, long param_1, char * par
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     004b8e60(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[4]:     004b8e71(R), 004b8e9b(R), 004b8ee9(R), 004b8f3b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[14]:    004b8e46(W), 004b8e75(*), 004b8e9f(*), 004b8eaf(R), 
    //                                                                                     004b8eb6(*), 004b8ec6(R), 004b8eed(*), 004b8efd(R), 
    //                                                                                     004b8f04(*), 004b8f14(R), 004b8f3f(*), 004b8f57(R), 
    //                                                                                     004b8f5b(*), 004b8f66(R)  
    //              char *            Stack[-0x8]:4  msg
    //                               ?Check_shape@TShape@@AAEEJPAD@Z                              XREF[7]:     shape_bounds:004b8ff7(c), 
    //                               TShape::Check_shape                                                       shape_count:004b904a(c), 
    //                                                                                                         shape_minmax:004b9086(c), 
    //                                                                                                         shape_check:004b9158(c), 
    //                                                                                                         shape_draw:004b9460(c), 
    //                                                                                                         shape_mirror:004ba570(c), 
    //                                                                                                         shape_dither:004bb617(c)  
    //                              Shape.cpp:207 (1)
    //         004b8e40     PUSH       this
    //                              Shape.cpp:211 (24)
    //         004b8e41     MOV        EAX,dword ptr [this->shape]
    //         004b8e43     PUSH       ESI
    //         004b8e44     TEST       EAX,EAX
    //         004b8e46     MOV        dword ptr [ESP + local_4],0x0
    //         004b8e4e     JNZ        LAB_004b8e60
    //         004b8e50     MOV        EDX,dword ptr [ECX + this->FShape]
    //         004b8e53     TEST       EDX,EDX
    //         004b8e55     JNZ        LAB_004b8e5e
    //         004b8e57     MOV        AL,0x1
    //                              Shape.cpp:263 (5)
    //         004b8e59     POP        ESI
    //         004b8e5a     POP        this
    //         004b8e5b     RET        0x8
    //                               LAB_004b8e5e                                                 XREF[1]:     004b8e55(j)  
    //                              Shape.cpp:213 (12)
    //         004b8e5e     TEST       EAX,EAX
    //                               LAB_004b8e60                                                 XREF[1]:     004b8e4e(j)  
    //         004b8e60     MOV        EDX,dword ptr [ESP + param_1]
    //         004b8e64     JZ         LAB_004b8f2b
    //                              Shape.cpp:215 (7)
    //         004b8e6a     MOV        EAX,dword ptr [ECX + this->head]
    //         004b8e6d     TEST       EAX,EAX
    //         004b8e6f     JNZ        LAB_004b8e92
    //                              Shape.cpp:217 (23)
    //         004b8e71     MOV        EAX,dword ptr [ESP + param_2]
    //         004b8e75     LEA        this=>local_4,[ESP + 0x4]
    //         004b8e79     PUSH       EAX
    //         004b8e7a     PUSH       s_ERROR:_(                                       = "ERROR: ("
    //         004b8e7f     PUSH       this
    //         004b8e80     CALL       addstring                                        void addstring(char * * param_1, char * param
    //         004b8e85     ADD        ESP,0xc
    //                              Shape.cpp:218 (5)
    //         004b8e88     PUSH       s_)_Bad_shape                                    = ") Bad shape"
    //                              Shape.cpp:222 (5)
    //         004b8e8d     JMP        LAB_004b8f57
    //                               LAB_004b8e92                                                 XREF[1]:     004b8e6f(j)  
    //                              Shape.cpp:225 (9)
    //         004b8e92     TEST       EDX,EDX
    //         004b8e94     JL         LAB_004b8edd
    //         004b8e96     CMP        EDX,dword ptr [EAX + 0x4]
    //         004b8e99     JL         LAB_004b8edd
    //                              Shape.cpp:227 (20)
    //         004b8e9b     MOV        EDX,dword ptr [ESP + param_2]
    //         004b8e9f     LEA        EAX=>local_4,[ESP + 0x4]
    //         004b8ea3     PUSH       EDX
    //         004b8ea4     PUSH       s_ERROR:_(                                       = "ERROR: ("
    //         004b8ea9     PUSH       EAX
    //         004b8eaa     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              Shape.cpp:228 (23)
    //         004b8eaf     MOV        this,dword ptr [ESP + local_4]
    //         004b8eb3     ADD        ESP,0xc
    //         004b8eb6     LEA        EDX=>local_4,[ESP + 0x4]
    //         004b8eba     PUSH       s_)_shape_number_out_of_bounds                   = ") shape number out of bounds"
    //         004b8ebf     PUSH       this
    //         004b8ec0     PUSH       EDX
    //         004b8ec1     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              Shape.cpp:230 (16)
    //         004b8ec6     MOV        EAX,dword ptr [ESP + local_4]
    //         004b8eca     ADD        ESP,0xc
    //         004b8ecd     PUSH       EAX
    //         004b8ece     CALL       free                                             undefined free()
    //         004b8ed3     ADD        ESP,0x4
    //                              Shape.cpp:232 (2)
    //         004b8ed6     MOV        AL,0x1
    //                              Shape.cpp:263 (5)
    //         004b8ed8     POP        ESI
    //         004b8ed9     POP        this
    //         004b8eda     RET        0x8
    //                               LAB_004b8edd                                                 XREF[2]:     004b8e94(j), 004b8e99(j)  
    //                              Shape.cpp:235 (12)
    //         004b8edd     MOV        EAX,dword ptr [EAX]
    //         004b8edf     MOV        ESI,dword ptr [s_1.10]                           = "1.10"
    //         004b8ee5     CMP        EAX,ESI
    //         004b8ee7     JZ         LAB_004b8f2b
    //                              Shape.cpp:237 (20)
    //         004b8ee9     MOV        this,dword ptr [ESP + param_2]
    //         004b8eed     LEA        EDX=>local_4,[ESP + 0x4]
    //         004b8ef1     PUSH       this
    //         004b8ef2     PUSH       s_ERROR:_(                                       = "ERROR: ("
    //         004b8ef7     PUSH       EDX
    //         004b8ef8     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              Shape.cpp:238 (23)
    //         004b8efd     MOV        EAX,dword ptr [ESP + local_4]
    //         004b8f01     ADD        ESP,0xc
    //         004b8f04     LEA        this=>local_4,[ESP + 0x4]
    //         004b8f08     PUSH       s_)_shape_version_wrong                          = ") shape version wrong"
    //         004b8f0d     PUSH       EAX
    //         004b8f0e     PUSH       this
    //         004b8f0f     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              Shape.cpp:240 (16)
    //         004b8f14     MOV        EDX,dword ptr [ESP + local_4]
    //         004b8f18     ADD        ESP,0xc
    //         004b8f1b     PUSH       EDX
    //         004b8f1c     CALL       free                                             undefined free()
    //         004b8f21     ADD        ESP,0x4
    //                              Shape.cpp:242 (2)
    //         004b8f24     MOV        AL,0x1
    //                              Shape.cpp:263 (5)
    //         004b8f26     POP        ESI
    //         004b8f27     POP        this
    //         004b8f28     RET        0x8
    //                               LAB_004b8f2b                                                 XREF[2]:     004b8e64(j), 004b8ee7(j)  
    //                              Shape.cpp:247 (7)
    //         004b8f2b     MOV        this,dword ptr [ECX + this->FShape]
    //         004b8f2e     TEST       this,this
    //         004b8f30     JZ         LAB_004b8f7d
    //                              Shape.cpp:249 (9)
    //         004b8f32     TEST       EDX,EDX
    //         004b8f34     JL         LAB_004b8f7d
    //         004b8f36     CMP        EDX,dword ptr [ECX + this->load_type]
    //         004b8f39     JL         LAB_004b8f7d
    //                              Shape.cpp:251 (23)
    //         004b8f3b     MOV        EAX,dword ptr [ESP + param_2]
    //         004b8f3f     LEA        this=>local_4,[ESP + 0x4]
    //         004b8f43     PUSH       EAX
    //         004b8f44     PUSH       s_ERROR:_(                                       = "ERROR: ("
    //         004b8f49     PUSH       this
    //         004b8f4a     CALL       addstring                                        void addstring(char * * param_1, char * param
    //         004b8f4f     ADD        ESP,0xc
    //                              Shape.cpp:252 (20)
    //         004b8f52     PUSH       s_)_Fshape_number_out_of_bounds                  = ") Fshape number out of bounds"
    //                               LAB_004b8f57                                                 XREF[1]:     004b8e8d(j)  
    //         004b8f57     MOV        EDX,dword ptr [ESP + local_4]
    //         004b8f5b     LEA        EAX=>local_4,[ESP + 0x8]
    //         004b8f5f     PUSH       EDX
    //         004b8f60     PUSH       EAX
    //         004b8f61     CALL       addstring                                        void addstring(char * * param_1, char * param
    //                              Shape.cpp:254 (16)
    //         004b8f66     MOV        this,dword ptr [ESP + local_4]
    //         004b8f6a     ADD        ESP,0xc
    //         004b8f6d     PUSH       this
    //         004b8f6e     CALL       free                                             undefined free()
    //         004b8f73     ADD        ESP,0x4
    //                              Shape.cpp:256 (2)
    //         004b8f76     MOV        AL,0x1
    //                              Shape.cpp:263 (5)
    //         004b8f78     POP        ESI
    //         004b8f79     POP        this
    //         004b8f7a     RET        0x8
    //                               LAB_004b8f7d                                                 XREF[3]:     004b8f30(j), 004b8f34(j), 
    //                                                                                                         004b8f39(j)  
    //                              Shape.cpp:262 (2)
    //         004b8f7d     XOR        AL,AL
    //                              Shape.cpp:263 (5)
    //         004b8f7f     POP        ESI
    //         004b8f80     POP        this
    //         004b8f81     RET        0x8
}

// Offset: 0x004B8F90
int is_loaded(TShape* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TShape::is_loaded(void)                                                        *
    //                              *********************************************************************************************************
    //                              int __thiscall is_loaded(TShape * this)
    //              int               EAX:4          <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //                               ?is_loaded@TShape@@QAEHXZ                                    XREF[18]:    load_terrain_types:00457f30(c), 
    //                               TShape::is_loaded                                                         load_border_types:00458300(c), 
    //                                                                                                         setup:0045b1fd(c), 
    //                                                                                                         LoadCursors:0045b3ba(c), 
    //                                                                                                         set_background:00467b8b(c), 
    //                                                                                                         set_background2:00467cfb(c), 
    //                                                                                                         set_button_pics:0046817b(c), 
    //                                                                                                         load_pic:0047a4b9(c), 
    //                                                                                                         TRIBE_Screen_Game:00494128(c), 
    //                                                                                                         TRIBE_Screen_Game:0049417b(c), 
    //                                                                                                         TRIBE_Screen_Game:004941ce(c), 
    //                                                                                                         TRIBE_Screen_Game:0049426b(c), 
    //                                                                                                         create_all_buttons_etc:004b0177(c)
    //                                                                                                         create_all_buttons_etc:004b01f7(c)
    //                                                                                                         TRIBE_Panel_Object:0051afa0(c), 
    //                                                                                                         TRIBE_Panel_Object:0051b005(c), 
    //                                                                                                         set_background:0051ed33(c), 
    //                                                                                                         set_special_events:0051f003(c)  
    //                              Shape.cpp:267 (14)
    //         004b8f90     CMP        dword ptr [this->shape],0x0
    //         004b8f93     JNZ        LAB_004b8f9f
    //         004b8f95     MOV        EAX,dword ptr [ECX + this->FShape]
    //         004b8f98     TEST       EAX,EAX
    //         004b8f9a     JNZ        LAB_004b8f9f
    //         004b8f9c     XOR        EAX,EAX
    //                              Shape.cpp:270 (1)
    //         004b8f9e     RET
    //                               LAB_004b8f9f                                                 XREF[2]:     004b8f93(j), 004b8f9a(j)  
    //                              Shape.cpp:269 (5)
    //         004b8f9f     MOV        EAX,0x1
    //                              Shape.cpp:270 (1)
    //         004b8fa4     RET
}

// Offset: 0x004B8FB0
uchar shape_bounds(TShape* this_, long param_2, short* param_3, short* param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TShape::shape_bounds(long,short &,short &)                           *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_bounds(TShape * this, long param_1, short * p
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[2]:     004b8fbb(R), 004b8fe7(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[2]:     004b8fca(R), 004b900f(R)  
    //              short *           Stack[0xc]:4   param_3                   XREF[2]:     004b8fd4(R), 004b901c(R)  
    //                               ?shape_bounds@TShape@@QAEEJAAF0@Z                            XREF[2]:     setup:0047a33e(c), 
    //                               TShape::shape_bounds                                                      calculate_icon_location:0051f67d(c
    //                              Shape.cpp:285 (4)
    //         004b8fb0     PUSH       ESI
    //         004b8fb1     MOV        ESI,this
    //         004b8fb3     PUSH       EDI
    //                              Shape.cpp:287 (7)
    //         004b8fb4     MOV        EAX,dword ptr [ESI + 0x18]
    //         004b8fb7     TEST       EAX,EAX
    //         004b8fb9     JZ         LAB_004b8fe7
    //                              Shape.cpp:289 (22)
    //         004b8fbb     MOV        EAX,dword ptr [ESP + param_1]
    //         004b8fbf     MOV        this,dword ptr [ESI + 0x1c]
    //         004b8fc2     SHL        EAX,0x5
    //         004b8fc5     MOV        DX,word ptr [ECX + EAX*0x1 + this->head]
    //         004b8fca     MOV        this,dword ptr [ESP + param_2]
    //         004b8fce     MOV        word ptr [this->shape],DX
    //                              Shape.cpp:290 (15)
    //         004b8fd1     MOV        EDX,dword ptr [ESI + 0x1c]
    //         004b8fd4     MOV        this,dword ptr [ESP + param_3]
    //         004b8fd8     MOV        AX,word ptr [EDX + EAX*0x1 + 0x14]
    //         004b8fdd     MOV        word ptr [this->shape],AX
    //                              Shape.cpp:303 (2)
    //         004b8fe0     MOV        AL,0x1
    //                              Shape.cpp:304 (5)
    //         004b8fe2     POP        EDI
    //         004b8fe3     POP        ESI
    //         004b8fe4     RET        0xc
    //                               LAB_004b8fe7                                                 XREF[1]:     004b8fb9(j)  
    //                              Shape.cpp:294 (25)
    //         004b8fe7     MOV        EDI,dword ptr [ESP + param_1]
    //         004b8feb     TEST       EDI,EDI
    //         004b8fed     JL         LAB_004b902d
    //         004b8fef     PUSH       s_RGL_shape_resolution                           = "RGL_shape_resolution"
    //         004b8ff4     PUSH       EDI
    //         004b8ff5     MOV        this,ESI
    //         004b8ff7     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004b8ffc     TEST       AL,AL
    //         004b8ffe     JNZ        LAB_004b902d
    //                              Shape.cpp:297 (13)
    //         004b9000     MOV        EDX,dword ptr [ESI + 0x14]
    //         004b9003     MOV        this,dword ptr [ESI]
    //         004b9005     MOV        EAX,dword ptr [EDX + EDI*0x8]
    //         004b9008     ADD        EAX,this
    //         004b900a     MOV        dword ptr [ESI + 0xc],EAX
    //                              Shape.cpp:299 (12)
    //         004b900d     MOV        EDX,dword ptr [EAX]
    //         004b900f     MOV        EAX,dword ptr [ESP + param_2]
    //         004b9013     SAR        EDX,0x10
    //         004b9016     MOV        word ptr [EAX],DX
    //                              Shape.cpp:300 (13)
    //         004b9019     MOV        this,dword ptr [ESI + 0xc]
    //         004b901c     MOV        EAX,dword ptr [ESP + param_3]
    //         004b9020     MOV        DX,word ptr [this->shape]
    //         004b9023     MOV        word ptr [EAX],DX
    //                              Shape.cpp:303 (2)
    //         004b9026     MOV        AL,0x1
    //                              Shape.cpp:304 (12)
    //         004b9028     POP        EDI
    //         004b9029     POP        ESI
    //         004b902a     RET        0xc
    //                               LAB_004b902d                                                 XREF[2]:     004b8fed(j), 004b8ffe(j)  
    //         004b902d     POP        EDI
    //         004b902e     XOR        AL,AL
    //         004b9030     POP        ESI
    //         004b9031     RET        0xc
}

// Offset: 0x004B9040
long shape_count(TShape* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TShape::shape_count(void)                                                     *
    //                              *********************************************************************************************************
    //                              long __thiscall shape_count(TShape * this)
    //              long              EAX:4          <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //                               ?shape_count@TShape@@QAEJXZ                                  XREF[10]:    setup:0045b224(c), 
    //                               TShape::shape_count                                                       LoadCursors:0045b3d3(c), 
    //                                                                                                         draw:0051b311(c), 
    //                                                                                                         draw:0051b328(c), 
    //                                                                                                         draw:0051b361(c), 
    //                                                                                                         draw:0051b374(c), 
    //                                                                                                         calculate_icon_location:0051f637(c
    //                                                                                                         calculate_icon_location:0051f64f(c
    //                                                                                                         draw_legend:00520d5d(c), 
    //                                                                                                         view_function_terrain:00537672(c)  
    //                              Shape.cpp:308 (1)
    //         004b9040     PUSH       ESI
    //                              Shape.cpp:309 (18)
    //         004b9041     PUSH       s_RGL_shape_count                                = "RGL_shape_count"
    //         004b9046     MOV        ESI,this
    //         004b9048     PUSH       -0x1
    //         004b904a     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004b904f     TEST       AL,AL
    //         004b9051     JZ         LAB_004b9057
    //                              Shape.cpp:310 (2)
    //         004b9053     XOR        EAX,EAX
    //                              Shape.cpp:315 (2)
    //         004b9055     POP        ESI
    //         004b9056     RET
    //                               LAB_004b9057                                                 XREF[1]:     004b9051(j)  
    //                              Shape.cpp:312 (7)
    //         004b9057     MOV        EAX,dword ptr [ESI + 0x18]
    //         004b905a     TEST       EAX,EAX
    //         004b905c     JNZ        LAB_004b9061
    //                              Shape.cpp:314 (6)
    //         004b905e     MOV        EAX,dword ptr [ESI + 0x10]
    //                               LAB_004b9061                                                 XREF[1]:     004b905c(j)  
    //         004b9061     MOV        EAX,dword ptr [EAX + 0x4]
    //                              Shape.cpp:315 (2)
    //         004b9064     POP        ESI
    //         004b9065     RET
}

// Offset: 0x004B9070
uchar shape_minmax(TShape* this_, long* param_2, long* param_3, long* param_4, long* param_5, long param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TShape::shape_minmax(long &,long &,long &,long &,long)               *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_minmax(TShape * this, long * param_1, long * 
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              long *            Stack[0x4]:4   param_1                   XREF[2]:     004b90a6(R), 004b90f7(R)  
    //              long *            Stack[0x8]:4   param_2                   XREF[2]:     004b90b5(R), 004b9106(R)  
    //              long *            Stack[0xc]:4   param_3                   XREF[2]:     004b90c8(R), 004b9112(R)  
    //              long *            Stack[0x10]:4  param_4                   XREF[2]:     004b90de(R), 004b911e(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004b9072(R)  
    //                               ?shape_minmax@TShape@@QAEEAAJ000J@Z                          XREF[12]:    setup_shadow_area:00467470(c), 
    //                               TShape::shape_minmax                                                      draw_background:00467773(c), 
    //                                                                                                         draw:004729ba(c), 
    //                                                                                                         draw_back_pic:0047b8eb(c), 
    //                                                                                                         draw_button_pic:0047b9bc(c), 
    //                                                                                                         set_back_pic:0047ccb2(c), 
    //                                                                                                         get_size:004c0925(c), 
    //                                                                                                         shape_hit_test:004c0eac(c), 
    //                                                                                                         set_background:0051ebaa(c), 
    //                                                                                                         set_background:0051ed7b(c), 
    //                                                                                                         set_special_events:0051ee7a(c), 
    //                                                                                                         set_special_events:0051f04b(c)  
    //                              Shape.cpp:319 (2)
    //         004b9070     PUSH       ESI
    //         004b9071     PUSH       EDI
    //                              Shape.cpp:320 (33)
    //         004b9072     MOV        EDI,dword ptr [ESP + param_5]
    //         004b9076     MOV        ESI,this
    //         004b9078     TEST       EDI,EDI
    //         004b907a     JL         LAB_004b912e
    //         004b9080     PUSH       s_RGL_shape_minxy                                = "RGL_shape_minxy"
    //         004b9085     PUSH       EDI
    //         004b9086     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004b908b     TEST       AL,AL
    //         004b908d     JNZ        LAB_004b912e
    //                              Shape.cpp:324 (7)
    //         004b9093     MOV        EAX,dword ptr [ESI + 0x18]
    //         004b9096     TEST       EAX,EAX
    //         004b9098     JZ         LAB_004b90ec
    //                              Shape.cpp:326 (20)
    //         004b909a     MOV        this,dword ptr [ESI + 0x1c]
    //         004b909d     SHL        EDI,0x5
    //         004b90a0     MOV        EAX,EDI
    //         004b90a2     MOV        EDX,dword ptr [ECX + EAX*0x1 + this->FShape]
    //         004b90a6     MOV        this,dword ptr [ESP + param_1]
    //         004b90aa     NEG        EDX
    //         004b90ac     MOV        dword ptr [this->shape],EDX
    //                              Shape.cpp:327 (15)
    //         004b90ae     MOV        EDX,dword ptr [ESI + 0x1c]
    //         004b90b1     MOV        this,dword ptr [EDX + EAX*0x1 + 0x1c]
    //         004b90b5     MOV        EDX,dword ptr [ESP + param_2]
    //         004b90b9     NEG        this
    //         004b90bb     MOV        dword ptr [EDX],this
    //                              Shape.cpp:328 (20)
    //         004b90bd     MOV        this,dword ptr [ESI + 0x1c]
    //         004b90c0     ADD        this,EAX
    //         004b90c2     MOV        EDX,dword ptr [ECX + this->head]
    //         004b90c5     MOV        EDI,dword ptr [ECX + this->FShape]
    //         004b90c8     MOV        this,dword ptr [ESP + param_3]
    //         004b90cc     SUB        EDX,EDI
    //         004b90ce     DEC        EDX
    //         004b90cf     MOV        dword ptr [this->shape],EDX
    //                              Shape.cpp:329 (18)
    //         004b90d1     MOV        EDX,dword ptr [ESI + 0x1c]
    //         004b90d4     ADD        EAX,EDX
    //         004b90d6     MOV        this,dword ptr [EAX + 0x14]
    //         004b90d9     MOV        EDX,dword ptr [EAX + 0x1c]
    //         004b90dc     SUB        this,EDX
    //         004b90de     MOV        EDX,dword ptr [ESP + param_4]
    //         004b90e2     DEC        this
    //                              Shape.cpp:331 (4)
    //         004b90e3     MOV        AL,0x1
    //         004b90e5     MOV        dword ptr [EDX],this
    //                              Shape.cpp:342 (5)
    //         004b90e7     POP        EDI
    //         004b90e8     POP        ESI
    //         004b90e9     RET        0x14
    //                               LAB_004b90ec                                                 XREF[1]:     004b9098(j)  
    //                              Shape.cpp:334 (11)
    //         004b90ec     MOV        EAX,dword ptr [ESI + 0x14]
    //         004b90ef     MOV        EDX,dword ptr [ESI]
    //         004b90f1     MOV        this,dword ptr [EAX + EDI*0x8]
    //         004b90f4     LEA        EAX,[this->shape + EDX*0x1]
    //                              Shape.cpp:336 (12)
    //         004b90f7     MOV        this,dword ptr [ESP + param_1]
    //         004b90fb     MOV        dword ptr [ESI + 0xc],EAX
    //         004b90fe     MOV        EAX,dword ptr [EAX + 0x8]
    //         004b9101     MOV        dword ptr [this->shape],EAX
    //                              Shape.cpp:337 (12)
    //         004b9103     MOV        EDX,dword ptr [ESI + 0xc]
    //         004b9106     MOV        this,dword ptr [ESP + param_2]
    //         004b910a     MOV        EAX,dword ptr [EDX + 0xc]
    //         004b910d     MOV        dword ptr [this->shape],EAX
    //                              Shape.cpp:338 (12)
    //         004b910f     MOV        EDX,dword ptr [ESI + 0xc]
    //         004b9112     MOV        this,dword ptr [ESP + param_3]
    //         004b9116     MOV        EAX,dword ptr [EDX + 0x10]
    //         004b9119     MOV        dword ptr [this->shape],EAX
    //                              Shape.cpp:339 (12)
    //         004b911b     MOV        EDX,dword ptr [ESI + 0xc]
    //         004b911e     MOV        this,dword ptr [ESP + param_4]
    //         004b9122     MOV        EAX,dword ptr [EDX + 0x14]
    //         004b9125     MOV        dword ptr [this->shape],EAX
    //                              Shape.cpp:341 (2)
    //         004b9127     MOV        AL,0x1
    //                              Shape.cpp:342 (12)
    //         004b9129     POP        EDI
    //         004b912a     POP        ESI
    //         004b912b     RET        0x14
    //                               LAB_004b912e                                                 XREF[2]:     004b907a(j), 004b908d(j)  
    //         004b912e     POP        EDI
    //         004b912f     XOR        AL,AL
    //         004b9131     POP        ESI
    //         004b9132     RET        0x14
}

// Offset: 0x004B9140
uchar shape_check(TShape* this_, long param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TShape::shape_check(long,long,long)                                  *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_check(TShape * this, long param_1, long param
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[16]:    004b9173(R), 004b9201(W), 004b9218(R), 004b9236(R), 
    //                                                                                     004b925b(R), 004b926c(R), 004b9284(R), 004b92a6(R), 
    //                                                                                     004b92c7(R), 004b932a(R), 004b9355(W), 004b935b(R), 
    //                                                                                     004b9394(W), 004b93a6(R), 004b93bc(W), 004b93c9(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[7]:     004b9177(R), 004b91c5(W), 004b91d9(R), 004b9303(R), 
    //                                                                                     004b9380(W), 004b93c2(W), 004b93da(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[3]:     004b9144(R), 004b9318(W), 004b937a(R)  
    //                               ?shape_check@TShape@@QAEEJJJ@Z                               XREF[4]:     hit_button:00473990(c), 
    //                               TShape::shape_check                                                       shape_hit_test:004c0f2b(c), 
    //                                                                                                         shape_hit_test:004c0f55(c), 
    //                                                                                                         hit_tile:00539e8f(c)  
    //                              Shape.cpp:399 (4)
    //         004b9140     PUSH       EBX
    //         004b9141     PUSH       EBP
    //         004b9142     PUSH       ESI
    //         004b9143     PUSH       EDI
    //                              Shape.cpp:416 (33)
    //         004b9144     MOV        EDI,dword ptr [ESP + param_3]
    //         004b9148     MOV        ESI,this
    //         004b914a     TEST       EDI,EDI
    //         004b914c     JL         switchD_004b9211::caseD_e
    //         004b9152     PUSH       s_RGL_shape_draw                                 = "RGL_shape_draw"
    //         004b9157     PUSH       EDI
    //         004b9158     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004b915d     TEST       AL,AL
    //         004b915f     JNZ        switchD_004b9211::caseD_e
    //                              Shape.cpp:419 (11)
    //         004b9165     MOV        EBX,dword ptr [ESI + 0x18]
    //         004b9168     TEST       EBX,EBX
    //         004b916a     JZ         LAB_004b92f6
    //                              Shape.cpp:421 (7)
    //         004b9170     MOV        EAX,dword ptr [ESI + 0x1c]
    //         004b9173     MOV        EBP,dword ptr [ESP + param_1]
    //                              Shape.cpp:422 (17)
    //         004b9177     MOV        ESI,dword ptr [ESP + param_2]
    //         004b917b     SHL        EDI,0x5
    //         004b917e     ADD        EAX,EDI
    //         004b9180     MOV        EDI,dword ptr [EAX + 0x18]
    //         004b9183     MOV        this,dword ptr [EAX + 0x1c]
    //         004b9186     ADD        EDI,EBP
    //                              Shape.cpp:423 (5)
    //         004b9188     MOV        EBP,dword ptr [EAX + 0x10]
    //         004b918b     ADD        this,ESI
    //                              Shape.cpp:427 (33)
    //         004b918d     TEST       EDI,EDI
    //         004b918f     JL         switchD_004b9211::caseD_e
    //         004b9195     TEST       this,this
    //         004b9197     JL         switchD_004b9211::caseD_e
    //         004b919d     CMP        EDI,EBP
    //         004b919f     JGE        switchD_004b9211::caseD_e
    //         004b91a5     CMP        this,dword ptr [EAX + 0x14]
    //         004b91a8     JGE        switchD_004b9211::caseD_e
    //                              Shape.cpp:429 (3)
    //         004b91ae     MOV        EDX,dword ptr [EAX + 0x4]
    //                              Shape.cpp:431 (13)
    //         004b91b1     LEA        ESI,[this->shape*0x4 + 0x0]
    //         004b91b8     ADD        EDX,EBX
    //         004b91ba     MOVSX      this,word ptr [EDX + ESI*0x1]
    //                              Shape.cpp:432 (5)
    //         004b91be     MOVSX      EDX,word ptr [EDX + ESI*0x1 + 0x2]
    //                              Shape.cpp:434 (12)
    //         004b91c3     TEST       this,this
    //         004b91c5     MOV        dword ptr [ESP + param_2],EDX
    //         004b91c9     JL         switchD_004b9211::caseD_e
    //                              Shape.cpp:435 (8)
    //         004b91cf     CMP        EDI,this
    //         004b91d1     JL         switchD_004b9211::caseD_e
    //                              Shape.cpp:436 (14)
    //         004b91d7     MOV        EDX,EBP
    //         004b91d9     SUB        EDX,dword ptr [ESP + param_2]
    //         004b91dd     CMP        EDI,EDX
    //         004b91df     JG         switchD_004b9211::caseD_e
    //                              Shape.cpp:440 (4)
    //         004b91e5     MOV        EDX,EBX
    //         004b91e7     ADD        EDX,dword ptr [EAX]
    //                              Shape.cpp:441 (5)
    //         004b91e9     MOV        EAX,dword ptr [EDX + ESI*0x1]
    //         004b91ec     ADD        EAX,EBX
    //                              Shape.cpp:444 (8)
    //         004b91ee     CMP        this,EBP
    //         004b91f0     JGE        switchD_004b9211::caseD_e
    //                               LAB_004b91f6                                                 XREF[1]:     004b92e7(j)  
    //                              Shape.cpp:448 (8)
    //         004b91f6     CMP        EDI,this
    //         004b91f8     JL         switchD_004b9211::caseD_e
    //                              Shape.cpp:450 (2)
    //         004b91fe     MOV        DL,byte ptr [EAX]
    //                              Shape.cpp:451 (5)
    //         004b9200     INC        EAX
    //         004b9201     MOV        byte ptr [ESP + param_1],DL
    //                              Shape.cpp:454 (19)
    //         004b9205     AND        EDX,0xf
    //         004b9208     CMP        EDX,0xf
    //         004b920b     JA         switchD_004b9211::caseD_e
    //                               switchD_004b9211::switchD
    //         004b9211     JMP        dword ptr [EDX*0x4 + switchD_004b9211::switchd   = 004b9218
    //                               switchD_004b9211::caseD_4                                    XREF[5]:     004b9211(j), 004b9400(*), 
    //                               switchD_004b9211::caseD_8                                                 004b9410(*), 004b9420(*), 
    //                               switchD_004b9211::caseD_c                                                 004b9430(*)  
    //                               switchD_004b9211::caseD_0
    //                              Shape.cpp:460 (13)
    //         004b9218     MOV        EDX,dword ptr [ESP + param_1]
    //         004b921c     AND        EDX,0xff
    //         004b9222     SHR        EDX,0x2
    //                              Shape.cpp:461 (10)
    //         004b9225     ADD        this,EDX
    //         004b9227     CMP        EDI,this
    //         004b9229     JL         LAB_004b93eb
    //                              Shape.cpp:462 (2)
    //         004b922f     ADD        EAX,EDX
    //                              Shape.cpp:464 (5)
    //         004b9231     JMP        LAB_004b92e5
    //                               switchD_004b9211::caseD_2                                    XREF[2]:     004b9211(j), 004b9408(*)  
    //                              Shape.cpp:467 (19)
    //         004b9236     MOV        ESI,dword ptr [ESP + param_1]
    //         004b923a     XOR        EDX,EDX
    //         004b923c     MOV        DL,byte ptr [EAX]
    //         004b923e     AND        ESI,0xff
    //         004b9244     SHL        ESI,0x4
    //         004b9247     OR         ESI,EDX
    //                              Shape.cpp:468 (1)
    //         004b9249     INC        EAX
    //                              Shape.cpp:469 (10)
    //         004b924a     ADD        this,ESI
    //         004b924c     CMP        EDI,this
    //         004b924e     JL         LAB_004b93eb
    //                              Shape.cpp:471 (2)
    //         004b9254     ADD        EAX,ESI
    //                              Shape.cpp:473 (5)
    //         004b9256     JMP        LAB_004b92e5
    //                               switchD_004b9211::caseD_5                                    XREF[5]:     004b9211(j), 004b9404(*), 
    //                               switchD_004b9211::caseD_9                                                 004b9414(*), 004b9424(*), 
    //                               switchD_004b9211::caseD_d                                                 004b9434(*)  
    //                               switchD_004b9211::caseD_1
    //                              Shape.cpp:480 (15)
    //         004b925b     MOV        EDX,dword ptr [ESP + param_1]
    //         004b925f     AND        EDX,0xff
    //         004b9265     SHR        EDX,0x2
    //         004b9268     ADD        this,EDX
    //                              Shape.cpp:481 (2)
    //         004b926a     JMP        LAB_004b92e5
    //                               switchD_004b9211::caseD_3                                    XREF[2]:     004b9211(j), 004b940c(*)  
    //                              Shape.cpp:484 (19)
    //         004b926c     MOV        ESI,dword ptr [ESP + param_1]
    //         004b9270     XOR        EDX,EDX
    //         004b9272     MOV        DL,byte ptr [EAX]
    //         004b9274     AND        ESI,0xff
    //         004b927a     SHL        ESI,0x4
    //         004b927d     OR         ESI,EDX
    //                              Shape.cpp:485 (1)
    //         004b927f     INC        EAX
    //                              Shape.cpp:486 (2)
    //         004b9280     ADD        this,ESI
    //                              Shape.cpp:487 (2)
    //         004b9282     JMP        LAB_004b92e5
    //                               switchD_004b9211::caseD_6                                    XREF[2]:     004b9211(j), 004b9418(*)  
    //                              Shape.cpp:490 (13)
    //         004b9284     MOV        EDX,dword ptr [ESP + param_1]
    //         004b9288     AND        EDX,0xff
    //         004b928e     SHR        EDX,0x4
    //                              Shape.cpp:491 (7)
    //         004b9291     JNZ        LAB_004b9298
    //         004b9293     XOR        EDX,EDX
    //         004b9295     MOV        DL,byte ptr [EAX]
    //         004b9297     INC        EAX
    //                               LAB_004b9298                                                 XREF[1]:     004b9291(j)  
    //                              Shape.cpp:492 (10)
    //         004b9298     ADD        this,EDX
    //         004b929a     CMP        EDI,this
    //         004b929c     JL         LAB_004b93eb
    //                              Shape.cpp:493 (2)
    //         004b92a2     ADD        EAX,EDX
    //                              Shape.cpp:495 (2)
    //         004b92a4     JMP        LAB_004b92e5
    //                               switchD_004b9211::caseD_a                                    XREF[3]:     004b9211(j), 004b941c(*), 
    //                               switchD_004b9211::caseD_7                                                 004b9428(*)  
    //                              Shape.cpp:499 (13)
    //         004b92a6     MOV        EDX,dword ptr [ESP + param_1]
    //         004b92aa     AND        EDX,0xff
    //         004b92b0     SHR        EDX,0x4
    //                              Shape.cpp:500 (7)
    //         004b92b3     JNZ        LAB_004b92ba
    //         004b92b5     XOR        EDX,EDX
    //         004b92b7     MOV        DL,byte ptr [EAX]
    //         004b92b9     INC        EAX
    //                               LAB_004b92ba                                                 XREF[1]:     004b92b3(j)  
    //                              Shape.cpp:501 (10)
    //         004b92ba     ADD        this,EDX
    //         004b92bc     CMP        EDI,this
    //         004b92be     JL         LAB_004b93eb
    //                              Shape.cpp:502 (1)
    //         004b92c4     INC        EAX
    //                              Shape.cpp:504 (2)
    //         004b92c5     JMP        LAB_004b92e5
    //                               switchD_004b9211::caseD_b                                    XREF[2]:     004b9211(j), 004b942c(*)  
    //                              Shape.cpp:507 (13)
    //         004b92c7     MOV        EDX,dword ptr [ESP + param_1]
    //         004b92cb     AND        EDX,0xff
    //         004b92d1     SHR        EDX,0x4
    //                              Shape.cpp:508 (7)
    //         004b92d4     JNZ        LAB_004b92db
    //         004b92d6     XOR        EDX,EDX
    //         004b92d8     MOV        DL,byte ptr [EAX]
    //         004b92da     INC        EAX
    //                               LAB_004b92db                                                 XREF[1]:     004b92d4(j)  
    //                              Shape.cpp:509 (10)
    //         004b92db     ADD        this,EDX
    //         004b92dd     CMP        EDI,this
    //         004b92df     JL         LAB_004b93eb
    //                               LAB_004b92e5                                                 XREF[6]:     004b9231(j), 004b9256(j), 
    //                                                                                                         004b926a(j), 004b9282(j), 
    //                                                                                                         004b92a4(j), 004b92c5(j)  
    //                              Shape.cpp:444 (8)
    //         004b92e5     CMP        this,EBP
    //         004b92e7     JL         LAB_004b91f6
    //                              Shape.cpp:417 (2)
    //         004b92ed     XOR        AL,AL
    //                              Shape.cpp:607 (7)
    //         004b92ef     POP        EDI
    //         004b92f0     POP        ESI
    //         004b92f1     POP        EBP
    //         004b92f2     POP        EBX
    //         004b92f3     RET        0xc
    //                               LAB_004b92f6                                                 XREF[1]:     004b916a(j)  
    //                              Shape.cpp:527 (13)
    //         004b92f6     MOV        EAX,dword ptr [ESI + 0x14]
    //         004b92f9     MOV        EDX,dword ptr [ESI]
    //         004b92fb     MOV        this,dword ptr [EAX + EDI*0x8]
    //         004b92fe     ADD        this,EDX
    //         004b9300     MOV        dword ptr [ESI + 0xc],this
    //                              Shape.cpp:535 (59)
    //         004b9303     MOV        ESI,dword ptr [ESP + param_2]
    //         004b9307     MOV        EDX,dword ptr [ECX + this->shape_header]
    //         004b930a     MOV        EBX,dword ptr [ECX + this->load_size]
    //         004b930d     MOV        EDI,dword ptr [ECX + this->head]
    //         004b9310     LEA        EAX,[ECX + this->FShape]
    //         004b9313     MOV        this,dword ptr [ECX + this->offsets]
    //         004b9316     CMP        ESI,EDX
    //         004b9318     MOV        dword ptr [ESP + param_3],EBX
    //         004b931c     JL         switchD_004b9211::caseD_e
    //         004b9322     CMP        ESI,this
    //         004b9324     JG         switchD_004b9211::caseD_e
    //         004b932a     MOV        EBP,dword ptr [ESP + param_1]
    //         004b932e     CMP        EBP,EBX
    //         004b9330     JL         switchD_004b9211::caseD_e
    //         004b9336     CMP        EBP,EDI
    //         004b9338     JG         switchD_004b9211::caseD_e
    //                              Shape.cpp:539 (4)
    //         004b933e     CMP        EDX,ESI
    //         004b9340     JGE        LAB_004b937e
    //                              Shape.cpp:607 (2)
    //         004b9342     SUB        ESI,EDX
    //                               LAB_004b9344                                                 XREF[1]:     004b9378(j)  
    //                              Shape.cpp:541 (2)
    //         004b9344     XOR        DL,DL
    //                               LAB_004b9346                                                 XREF[1]:     004b9375(j)  
    //                              Shape.cpp:544 (2)
    //         004b9346     MOV        this,byte ptr [EAX]
    //                              Shape.cpp:545 (1)
    //         004b9348     INC        EAX
    //                              Shape.cpp:546 (10)
    //         004b9349     MOV        BL,this
    //         004b934b     AND        BL,0x1
    //         004b934e     CMP        BL,0x1
    //         004b9351     JNZ        LAB_004b9369
    //                              Shape.cpp:548 (6)
    //         004b9353     SHR        this,0x1
    //         004b9355     MOV        byte ptr [ESP + param_1],this
    //                              Shape.cpp:551 (2)
    //         004b9359     JZ         LAB_004b9372
    //                              Shape.cpp:552 (12)
    //         004b935b     MOV        this,dword ptr [ESP + param_1]
    //         004b935f     AND        this,0xff
    //         004b9365     ADD        EAX,this
    //                              Shape.cpp:554 (2)
    //         004b9367     JMP        LAB_004b9373
    //                               LAB_004b9369                                                 XREF[1]:     004b9351(j)  
    //                              Shape.cpp:557 (5)
    //         004b9369     TEST       this,0xfe
    //         004b936c     JNZ        LAB_004b9372
    //                              Shape.cpp:558 (2)
    //         004b936e     MOV        DL,0x1
    //                              Shape.cpp:559 (2)
    //         004b9370     JMP        LAB_004b9373
    //                               LAB_004b9372                                                 XREF[2]:     004b9359(j), 004b936c(j)  
    //                              Shape.cpp:560 (1)
    //         004b9372     INC        EAX
    //                               LAB_004b9373                                                 XREF[2]:     004b9367(j), 004b9370(j)  
    //                              Shape.cpp:542 (4)
    //         004b9373     TEST       DL,DL
    //         004b9375     JZ         LAB_004b9346
    //                              Shape.cpp:539 (7)
    //         004b9377     DEC        ESI
    //         004b9378     JNZ        LAB_004b9344
    //         004b937a     MOV        EBX,dword ptr [ESP + param_3]
    //                               LAB_004b937e                                                 XREF[1]:     004b9340(j)  
    //                              Shape.cpp:566 (2)
    //         004b937e     MOV        this,EBX
    //                              Shape.cpp:568 (5)
    //         004b9380     MOV        byte ptr [ESP + param_2],0x0
    //                               LAB_004b9385                                                 XREF[1]:     004b93e0(j)  
    //                              Shape.cpp:571 (2)
    //         004b9385     MOV        DL,byte ptr [EAX]
    //                              Shape.cpp:572 (1)
    //         004b9387     INC        EAX
    //                              Shape.cpp:573 (10)
    //         004b9388     MOV        BL,DL
    //         004b938a     AND        BL,0x1
    //         004b938d     CMP        BL,0x1
    //         004b9390     JNZ        LAB_004b93ba
    //                              Shape.cpp:575 (6)
    //         004b9392     SHR        DL,0x1
    //         004b9394     MOV        byte ptr [ESP + param_1],DL
    //                              Shape.cpp:576 (2)
    //         004b9398     JNZ        LAB_004b93a6
    //                              Shape.cpp:578 (6)
    //         004b939a     XOR        EDX,EDX
    //         004b939c     MOV        DL,byte ptr [EAX]
    //         004b939e     ADD        this,EDX
    //                              Shape.cpp:579 (4)
    //         004b93a0     CMP        this,EBP
    //         004b93a2     JG         switchD_004b9211::caseD_e
    //                              Shape.cpp:583 (2)
    //         004b93a4     JMP        LAB_004b93d9
    //                               LAB_004b93a6                                                 XREF[1]:     004b9398(j)  
    //                              Shape.cpp:585 (12)
    //         004b93a6     MOV        EDX,dword ptr [ESP + param_1]
    //         004b93aa     AND        EDX,0xff
    //         004b93b0     ADD        this,EDX
    //                              Shape.cpp:586 (4)
    //         004b93b2     CMP        this,EBP
    //         004b93b4     JG         LAB_004b93eb
    //                              Shape.cpp:588 (2)
    //         004b93b6     ADD        EAX,EDX
    //                              Shape.cpp:591 (2)
    //         004b93b8     JMP        LAB_004b93da
    //                               LAB_004b93ba                                                 XREF[1]:     004b9390(j)  
    //                              Shape.cpp:593 (6)
    //         004b93ba     SHR        DL,0x1
    //         004b93bc     MOV        byte ptr [ESP + param_1],DL
    //                              Shape.cpp:594 (2)
    //         004b93c0     JNZ        LAB_004b93c9
    //                              Shape.cpp:595 (5)
    //         004b93c2     MOV        byte ptr [ESP + param_2],0x1
    //                              Shape.cpp:596 (2)
    //         004b93c7     JMP        LAB_004b93da
    //                               LAB_004b93c9                                                 XREF[1]:     004b93c0(j)  
    //                              Shape.cpp:598 (12)
    //         004b93c9     MOV        EDX,dword ptr [ESP + param_1]
    //         004b93cd     AND        EDX,0xff
    //         004b93d3     ADD        this,EDX
    //                              Shape.cpp:599 (4)
    //         004b93d5     CMP        this,EBP
    //         004b93d7     JG         LAB_004b93eb
    //                               LAB_004b93d9                                                 XREF[1]:     004b93a4(j)  
    //                              Shape.cpp:601 (1)
    //         004b93d9     INC        EAX
    //                               LAB_004b93da                                                 XREF[2]:     004b93b8(j), 004b93c7(j)  
    //                              Shape.cpp:569 (8)
    //         004b93da     MOV        DL,byte ptr [ESP + param_2]
    //         004b93de     TEST       DL,DL
    //         004b93e0     JZ         LAB_004b9385
    //                              Shape.cpp:417 (2)
    //         004b93e2     XOR        AL,AL
    //                              Shape.cpp:607 (7)
    //         004b93e4     POP        EDI
    //         004b93e5     POP        ESI
    //         004b93e6     POP        EBP
    //         004b93e7     POP        EBX
    //         004b93e8     RET        0xc
    //                               LAB_004b93eb                                                 XREF[7]:     004b9229(j), 004b924e(j), 
    //                                                                                                         004b929c(j), 004b92be(j), 
    //                                                                                                         004b92df(j), 004b93b4(j), 
    //                                                                                                         004b93d7(j)  
    //                              Shape.cpp:600 (2)
    //         004b93eb     MOV        AL,0x1
    //                              Shape.cpp:607 (83)
    //         004b93ed     POP        EDI
    //         004b93ee     POP        ESI
    //         004b93ef     POP        EBP
    //         004b93f0     POP        EBX
    //         004b93f1     RET        0xc
    //                               switchD_004b9211::caseD_f                                    XREF[20]:    004b914c(j), 004b915f(j), 
    //                               switchD_004b9211::caseD_e                                                 004b918f(j), 004b9197(j), 
    //                                                                                                         004b919f(j), 004b91a8(j), 
    //                                                                                                         004b91c9(j), 004b91d1(j), 
    //                                                                                                         004b91df(j), 004b91f0(j), 
    //                                                                                                         004b91f8(j), 004b920b(j), 
    //                                                                                                         004b9211(j), 004b931c(j), 
    //                                                                                                         004b9324(j), 004b9330(j), 
    //                                                                                                         004b9338(j), 004b93a2(j), 
    //                                                                                                         004b9438(*), 004b943c(*)  
    //         004b93f4     POP        EDI
    //         004b93f5     POP        ESI
    //         004b93f6     POP        EBP
    //         004b93f7     XOR        AL,AL
    //         004b93f9     POP        EBX
    //         004b93fa     RET        0xc
}

// Offset: 0x004B93FD
undefined FUN_004b93fd() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004b93fd()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004b93fd
    //         004b93fd     NOP
    //         004b93fe     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004b9211::switchdataD_004b9400                       XREF[1]:     shape_check:004b9211(*)  
}

// Offset: 0x004B9440
uchar shape_draw(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, uchar param_6, uchar* param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TShape::shape_draw(class TDrawArea *,long,long,long,unsigned char... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_draw(TShape * this, TDrawArea * param_1, long
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[11]:    004b94de(R), 004b9584(R), 004b95d6(W), 004b95f8(W), 
    //                                                                                     004b9622(R), 004b962c(W), 004b9656(R), 004b966c(R), 
    //                                                                                     004b9764(R), 004b978d(R), 004b97b2(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[12]:    004b94b9(R), 004b955c(R), 004b95b4(R), 004b95cc(R), 
    //                                                                                     004b95f2(W), 004b9610(W), 004b963d(R), 004b9648(W), 
    //                                                                                     004b967e(R), 004b975d(R), 004b9786(R), 004b97ab(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[9]:     004b94a0(R), 004b9552(R), 004b95d2(R), 004b95e8(W), 
    //                                                                                     004b9604(W), 004b9630(R), 004b9636(W), 004b9660(R), 
    //                                                                                     004b973b(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[6]:     004b9444(R), 004b96b9(R), 004b96ef(R), 004b9709(R), 
    //                                                                                     004b9722(R), 004b9792(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     004b9698(R), 004b973f(R)  
    //              uchar *           Stack[0x18]:4  param_6                   XREF[6]:     004b949c(R), 004b951b(R), 004b96b1(R), 004b96e7(R), 
    //                                                                                     004b9754(R), 004b977d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b95a7(W), 004b9614(R)  
    //              tagRECT           Stack[-0x14]   rect                      XREF[2,6]:   004b95ee(W), 004b9682(R), 004b958e(W), 004b95e4(R), 
    //                                                                                     004b9595(W), 004b95fc(R), 004b959c(W), 004b9608(R)  
    //              long              Stack[-0x18]:4 shape_x1                  XREF[3]:     004b95de(W), 004b9618(R), 004b968e(R)  
    //              long              Stack[-0x1c]:4 shape_y1                  XREF[0,2]:   004b944f(W), 004b97cb(R)  
    //              uchar             Stack[-0x1d]:1 ret_num
    //                               ?shape_draw@TShape@@QAEEPAVTDrawArea@@JJJEPAE@Z              XREF[42]:    LoadCursors:0045b511(c), 
    //                               TShape::shape_draw                                                        Poll:0045c296(c), 
    //                                                                                                         setup_shadow_area:004674fb(c), 
    //                                                                                                         draw:00472a62(c), 
    //                                                                                                         render_to_image_buffer:0047a050(c)
    //                                                                                                         render_to_image_buffer:0047a0b1(c)
    //                                                                                                         draw:0047a6c7(c), 
    //                                                                                                         draw_button_pic:0047ba3f(c), 
    //                                                                                                         draw_background:0047d4a0(c), 
    //                                                                                                         draw:0049b64c(c), 
    //                                                                                                         draw:0049b688(c), 
    //                                                                                                         do_draw:004c049f(c), 
    //                                                                                                         draw:0051b2e2(c), 
    //                                                                                                         draw:0051b39c(c), 
    //                                                                                                         draw_item:0051c274(c), 
    //                                                                                                         view_function_terrain:005376e4(c), 
    //                                                                                                         draw_terrain_shape:00538bf1(c), 
    //                                                                                                         draw_terrain_shape:00538cd7(c), 
    //                                                                                                         draw_terrain_shape:00538d20(c), 
    //                                                                                                         draw_terrain_obstruction_map:00538
    //                                                                                                         [more]
    //                              Shape.cpp:611 (4)
    //         004b9440     SUB        ESP,0x1c
    //         004b9443     PUSH       EBX
    //                              Shape.cpp:627 (41)
    //         004b9444     MOV        EBX,dword ptr [ESP + param_4]
    //         004b9448     PUSH       EBP
    //         004b9449     PUSH       ESI
    //         004b944a     TEST       EBX,EBX
    //         004b944c     PUSH       EDI
    //         004b944d     MOV        ESI,this
    //         004b944f     MOV        byte ptr [ESP + shape_y1+0x3],0x0
    //         004b9454     JL         LAB_004b97d9
    //         004b945a     PUSH       s_RGL_shape_draw                                 = "RGL_shape_draw"
    //         004b945f     PUSH       EBX
    //         004b9460     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004b9465     TEST       AL,AL
    //         004b9467     JNZ        LAB_004b97d9
    //                              Shape.cpp:629 (11)
    //         004b946d     MOV        EAX,dword ptr [ESI + 0x18]
    //         004b9470     TEST       EAX,EAX
    //         004b9472     JZ         LAB_004b9584
    //                              Shape.cpp:631 (10)
    //         004b9478     MOV        this,dword ptr [SDI_Capture_Info]
    //         004b947e     TEST       this,this
    //         004b9480     JZ         LAB_004b94de
    //                              Shape.cpp:635 (80)
    //         004b9482     MOV        this,dword ptr [SDI_Draw_Level]
    //         004b9488     LEA        EDI,[EBX + 0x1]
    //         004b948b     SHL        EDI,0x5
    //         004b948e     ADD        EDI,EAX
    //         004b9490     MOV        EAX,[SDI_Object_ID]
    //         004b9495     PUSH       EAX
    //         004b9496     PUSH       this
    //         004b9497     CALL       _ASMGet_Color_Xform                              undefined _ASMGet_Color_Xform()
    //         004b949c     MOV        EDX,dword ptr [ESP + param_6]
    //         004b94a0     MOV        this,dword ptr [ESP + param_3]
    //         004b94a4     MOV        EBP,dword ptr [EDI + 0x18]
    //         004b94a7     PUSH       EAX
    //         004b94a8     MOV        EAX,[fog_next_shape]
    //         004b94ad     PUSH       EDX
    //         004b94ae     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004b94b1     PUSH       EAX
    //         004b94b2     MOV        EAX,[SDI_Draw_Line]
    //         004b94b7     SUB        this,EDX
    //         004b94b9     MOV        EDX,dword ptr [ESP + param_2]
    //         004b94bd     PUSH       this
    //         004b94be     MOV        this,dword ptr [ESI + 0x18]
    //         004b94c1     SUB        EDX,EBP
    //         004b94c3     PUSH       EDX
    //         004b94c4     PUSH       EAX
    //         004b94c5     PUSH       EDI
    //         004b94c6     PUSH       this
    //         004b94c7     MOV        this,dword ptr [SDI_List]                        = 00000000
    //         004b94cd     CALL       DClipInfo_List::AddDrawNode                      void AddDrawNode(DClipInfo_List * this, void 
    //                              Shape.cpp:637 (2)
    //         004b94d2     MOV        AL,0x1
    //                              Shape.cpp:772 (10)
    //         004b94d4     POP        EDI
    //         004b94d5     POP        ESI
    //         004b94d6     POP        EBP
    //         004b94d7     POP        EBX
    //         004b94d8     ADD        ESP,0x1c
    //         004b94db     RET        0x18
    //                               LAB_004b94de                                                 XREF[1]:     004b9480(j)  
    //                              Shape.cpp:641 (26)
    //         004b94de     MOV        this,dword ptr [ESP + param_1]
    //         004b94e2     MOV        EDX,dword ptr [this->shape + 0xcc]
    //         004b94e8     MOV        EAX,dword ptr [this->shape + 0xd0]
    //         004b94ee     MOV        EDX,dword ptr [EDX + 0x50]
    //         004b94f1     MOV        EDI,dword ptr [EAX + 0x50]
    //         004b94f4     CMP        EDX,EDI
    //         004b94f6     JGE        LAB_004b94fb
    //                              Shape.cpp:642 (1)
    //         004b94f8     DEC        EDX
    //                              Shape.cpp:643 (2)
    //         004b94f9     JMP        LAB_004b94fe
    //                               LAB_004b94fb                                                 XREF[1]:     004b94f6(j)  
    //                              Shape.cpp:644 (3)
    //         004b94fb     LEA        EDX,[EDI + -0x1]
    //                               LAB_004b94fe                                                 XREF[1]:     004b94f9(j)  
    //                              Shape.cpp:654 (29)
    //         004b94fe     MOV        this,dword ptr [this->shape + 0xc0]
    //         004b9504     PUSH       EDX
    //         004b9505     MOV        EDX,dword ptr [EAX + 0x5c]
    //         004b9508     PUSH       EDX
    //         004b9509     MOV        EDX,dword ptr [EAX + 0x40]
    //         004b950c     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004b950f     PUSH       0x0
    //         004b9511     PUSH       0x0
    //         004b9513     PUSH       EDX
    //         004b9514     PUSH       EAX
    //         004b9515     PUSH       this
    //         004b9516     CALL       _ASMSet_Surface_Info                             undefined _ASMSet_Surface_Info()
    //                              Shape.cpp:658 (20)
    //         004b951b     MOV        EAX,dword ptr [ESP + param_6]
    //         004b951f     ADD        ESP,0x1c
    //         004b9522     TEST       EAX,EAX
    //         004b9524     JZ         LAB_004b952f
    //         004b9526     PUSH       EAX
    //         004b9527     CALL       _ASMSet_Xlate_Table                              undefined _ASMSet_Xlate_Table()
    //         004b952c     ADD        ESP,0x4
    //                               LAB_004b952f                                                 XREF[1]:     004b9524(j)  
    //                              Shape.cpp:660 (3)
    //         004b952f     MOV        ESI,dword ptr [ESI + 0x18]
    //                              Shape.cpp:675 (56)
    //         004b9532     MOV        EDX,dword ptr [fog_next_shape]
    //         004b9538     LEA        EAX,[EBX + 0x1]
    //         004b953b     PUSH       EDX
    //         004b953c     SHL        EAX,0x5
    //         004b953f     ADD        EAX,ESI
    //         004b9541     MOV        this,dword ptr [EAX + 0x4]
    //         004b9544     MOV        EDX,dword ptr [EAX]
    //         004b9546     PUSH       this
    //         004b9547     MOV        this,dword ptr [EAX + 0x14]
    //         004b954a     MOV        EBX,dword ptr [EAX + 0x18]
    //         004b954d     PUSH       EDX
    //         004b954e     MOV        EDX,dword ptr [EAX + 0x10]
    //         004b9551     PUSH       this
    //         004b9552     MOV        this,dword ptr [ESP + param_3]
    //         004b9556     PUSH       EDX
    //         004b9557     MOV        EDX,dword ptr [EAX + 0x1c]
    //         004b955a     SUB        this,EDX
    //         004b955c     MOV        EDX,dword ptr [ESP + param_2]
    //         004b9560     SUB        EDX,EBX
    //         004b9562     PUSH       this
    //         004b9563     PUSH       EDX
    //         004b9564     PUSH       ESI
    //         004b9565     CALL       _ASMDraw_Sprite                                  undefined _ASMDraw_Sprite()
    //                              Shape.cpp:677 (14)
    //         004b956a     MOV        EAX,[ASM_Fast_Count]
    //         004b956f     ADD        ESP,0x20
    //         004b9572     INC        EAX
    //         004b9573     MOV        [ASM_Fast_Count],EAX
    //                              Shape.cpp:679 (2)
    //         004b9578     MOV        AL,0x1
    //                              Shape.cpp:772 (10)
    //         004b957a     POP        EDI
    //         004b957b     POP        ESI
    //         004b957c     POP        EBP
    //         004b957d     POP        EBX
    //         004b957e     ADD        ESP,0x1c
    //         004b9581     RET        0x18
    //                               LAB_004b9584                                                 XREF[1]:     004b9472(j)  
    //                              Shape.cpp:689 (31)
    //         004b9584     MOV        EDI,dword ptr [ESP + param_1]
    //         004b9588     LEA        EAX,[EDI + 0x28]
    //         004b958b     MOV        this,dword ptr [EDI + 0x28]
    //         004b958e     MOV        dword ptr [ESP + rect.top],this
    //         004b9592     MOV        EDX,dword ptr [EAX + 0x4]
    //         004b9595     MOV        dword ptr [ESP + rect.right],EDX
    //         004b9599     MOV        this,dword ptr [EAX + 0x8]
    //         004b959c     MOV        dword ptr [ESP + rect.bottom],this
    //         004b95a0     MOV        EDX,dword ptr [EAX + 0xc]
    //                              Shape.cpp:691 (14)
    //         004b95a3     MOV        EAX,dword ptr [ESI]
    //         004b95a5     TEST       EAX,EAX
    //         004b95a7     MOV        dword ptr [ESP + local_4],EDX
    //         004b95ab     JZ         LAB_004b97d9
    //                              Shape.cpp:693 (3)
    //         004b95b1     MOV        this,dword ptr [ESI + 0x14]
    //                              Shape.cpp:695 (15)
    //         004b95b4     MOV        EBP,dword ptr [ESP + param_2]
    //         004b95b8     MOV        EDX,dword ptr [this->shape + EBX*0x8]
    //         004b95bb     ADD        EDX,EAX
    //         004b95bd     MOV        dword ptr [ESI + 0xc],EDX
    //         004b95c0     MOV        EAX,dword ptr [EDX + 0x8]
    //                              Shape.cpp:696 (3)
    //         004b95c3     MOV        this,dword ptr [EDX + 0xc]
    //                              Shape.cpp:699 (3)
    //         004b95c6     MOV        EBX,dword ptr [EDX + 0x10]
    //                              Shape.cpp:700 (27)
    //         004b95c9     MOV        EDX,dword ptr [EDX + 0x14]
    //         004b95cc     ADD        EBX,dword ptr [ESP + param_2]
    //         004b95d0     ADD        EAX,EBP
    //         004b95d2     MOV        EBP,dword ptr [ESP + param_3]
    //         004b95d6     MOV        dword ptr [ESP + param_1],EAX
    //         004b95da     ADD        EDX,EBP
    //         004b95dc     ADD        this,EBP
    //         004b95de     MOV        dword ptr [ESP + shape_x1],EDX
    //         004b95e2     MOV        EBP,EDX
    //                              Shape.cpp:702 (24)
    //         004b95e4     MOV        EDX,dword ptr [ESP + rect.top]
    //         004b95e8     MOV        dword ptr [ESP + param_3],this
    //         004b95ec     CMP        EAX,EDX
    //         004b95ee     MOV        dword ptr [ESP + rect.left],EBX
    //         004b95f2     MOV        dword ptr [ESP + param_2],EBX
    //         004b95f6     JGE        LAB_004b95fc
    //         004b95f8     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_004b95fc                                                 XREF[1]:     004b95f6(j)  
    //                              Shape.cpp:703 (12)
    //         004b95fc     MOV        EDX,dword ptr [ESP + rect.right]
    //         004b9600     CMP        this,EDX
    //         004b9602     JGE        LAB_004b9608
    //         004b9604     MOV        dword ptr [ESP + param_3],EDX
    //                               LAB_004b9608                                                 XREF[1]:     004b9602(j)  
    //                              Shape.cpp:704 (12)
    //         004b9608     MOV        EDX,dword ptr [ESP + rect.bottom]
    //         004b960c     CMP        EBX,EDX
    //         004b960e     JLE        LAB_004b9614
    //         004b9610     MOV        dword ptr [ESP + param_2],EDX
    //                               LAB_004b9614                                                 XREF[1]:     004b960e(j)  
    //                              Shape.cpp:705 (14)
    //         004b9614     MOV        EDX,dword ptr [ESP + local_4]
    //         004b9618     MOV        EBX,dword ptr [ESP + shape_x1]
    //         004b961c     CMP        EBX,EDX
    //         004b961e     JLE        LAB_004b9622
    //         004b9620     MOV        EBP,EDX
    //                               LAB_004b9622                                                 XREF[1]:     004b961e(j)  
    //                              Shape.cpp:707 (14)
    //         004b9622     MOV        EBX,dword ptr [ESP + param_1]
    //         004b9626     XOR        EDX,EDX
    //         004b9628     CMP        EBX,EDX
    //         004b962a     JGE        LAB_004b9630
    //         004b962c     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_004b9630                                                 XREF[1]:     004b962a(j)  
    //                              Shape.cpp:708 (10)
    //         004b9630     CMP        dword ptr [ESP + param_3],EDX
    //         004b9634     JGE        LAB_004b963a
    //         004b9636     MOV        dword ptr [ESP + param_3],EDX
    //                               LAB_004b963a                                                 XREF[1]:     004b9634(j)  
    //                              Shape.cpp:709 (18)
    //         004b963a     MOV        EDX,dword ptr [EDI + 0x18]
    //         004b963d     MOV        EBX,dword ptr [ESP + param_2]
    //         004b9641     CMP        EBX,EDX
    //         004b9643     JL         LAB_004b964c
    //         004b9645     LEA        EBX,[EDX + -0x1]
    //         004b9648     MOV        dword ptr [ESP + param_2],EBX
    //                               LAB_004b964c                                                 XREF[1]:     004b9643(j)  
    //                              Shape.cpp:710 (10)
    //         004b964c     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004b964f     CMP        EBP,EDX
    //         004b9651     JL         LAB_004b9656
    //         004b9653     LEA        EBP,[EDX + -0x1]
    //                               LAB_004b9656                                                 XREF[1]:     004b9651(j)  
    //                              Shape.cpp:712 (22)
    //         004b9656     CMP        EBX,dword ptr [ESP + param_1]
    //         004b965a     JL         LAB_004b97d9
    //         004b9660     MOV        EDX,dword ptr [ESP + param_3]
    //         004b9664     CMP        EBP,EDX
    //         004b9666     JL         LAB_004b97d9
    //                              Shape.cpp:715 (44)
    //         004b966c     CMP        dword ptr [ESP + param_1],EAX
    //         004b9670     JNZ        LAB_004b973f
    //         004b9676     CMP        EDX,this
    //         004b9678     JNZ        LAB_004b973f
    //         004b967e     MOV        EDX,dword ptr [ESP + param_2]
    //         004b9682     MOV        EBX,dword ptr [ESP + rect.left]
    //         004b9686     CMP        EDX,EBX
    //         004b9688     JNZ        LAB_004b973b
    //         004b968e     CMP        EBP,dword ptr [ESP + shape_x1]
    //         004b9692     JNZ        LAB_004b973b
    //                              Shape.cpp:719 (25)
    //         004b9698     MOV        EDX,dword ptr [ESP + param_5]
    //         004b969c     AND        EDX,0xff
    //         004b96a2     SUB        EDX,0x0
    //         004b96a5     JZ         LAB_004b9722
    //         004b96a7     DEC        EDX
    //         004b96a8     JZ         LAB_004b96e7
    //         004b96aa     DEC        EDX
    //         004b96ab     JNZ        LAB_004b97cb
    //                              Shape.cpp:731 (8)
    //         004b96b1     MOV        EDX,dword ptr [ESP + param_6]
    //         004b96b5     TEST       EDX,EDX
    //         004b96b7     JNZ        LAB_004b96d2
    //                              Shape.cpp:732 (15)
    //         004b96b9     MOV        EDX,dword ptr [ESP + param_4]
    //         004b96bd     PUSH       EDX
    //         004b96be     PUSH       this
    //         004b96bf     PUSH       EAX
    //         004b96c0     PUSH       EDI
    //         004b96c1     MOV        this,ESI
    //         004b96c3     CALL       TShape::shape_draw_unclipped                     uchar shape_draw_unclipped(TShape * this, TDr
    //                              Shape.cpp:772 (10)
    //         004b96c8     POP        EDI
    //         004b96c9     POP        ESI
    //         004b96ca     POP        EBP
    //         004b96cb     POP        EBX
    //         004b96cc     ADD        ESP,0x1c
    //         004b96cf     RET        0x18
    //                               LAB_004b96d2                                                 XREF[1]:     004b96b7(j)  
    //                              Shape.cpp:734 (11)
    //         004b96d2     PUSH       EDX
    //         004b96d3     PUSH       this
    //         004b96d4     PUSH       EAX
    //         004b96d5     PUSH       EDI
    //         004b96d6     MOV        this,ESI
    //         004b96d8     CALL       TShape::shape_shadow_unclipped                   uchar shape_shadow_unclipped(TShape * this, T
    //                              Shape.cpp:772 (10)
    //         004b96dd     POP        EDI
    //         004b96de     POP        ESI
    //         004b96df     POP        EBP
    //         004b96e0     POP        EBX
    //         004b96e1     ADD        ESP,0x1c
    //         004b96e4     RET        0x18
    //                               LAB_004b96e7                                                 XREF[1]:     004b96a8(j)  
    //                              Shape.cpp:725 (8)
    //         004b96e7     MOV        EDX,dword ptr [ESP + param_6]
    //         004b96eb     TEST       EDX,EDX
    //         004b96ed     JNZ        LAB_004b9708
    //                              Shape.cpp:726 (15)
    //         004b96ef     MOV        EDX,dword ptr [ESP + param_4]
    //         004b96f3     PUSH       EDX
    //         004b96f4     PUSH       this
    //         004b96f5     PUSH       EAX
    //         004b96f6     PUSH       EDI
    //         004b96f7     MOV        this,ESI
    //         004b96f9     CALL       TShape::shape_draw_unclipped                     uchar shape_draw_unclipped(TShape * this, TDr
    //                              Shape.cpp:772 (10)
    //         004b96fe     POP        EDI
    //         004b96ff     POP        ESI
    //         004b9700     POP        EBP
    //         004b9701     POP        EBX
    //         004b9702     ADD        ESP,0x1c
    //         004b9705     RET        0x18
    //                               LAB_004b9708                                                 XREF[1]:     004b96ed(j)  
    //                              Shape.cpp:728 (16)
    //         004b9708     PUSH       EDX
    //         004b9709     MOV        EDX,dword ptr [ESP + param_4]
    //         004b970d     PUSH       EDX
    //         004b970e     PUSH       this
    //         004b970f     PUSH       EAX
    //         004b9710     PUSH       EDI
    //         004b9711     MOV        this,ESI
    //         004b9713     CALL       TShape::shape_color_trans_unclipped              uchar shape_color_trans_unclipped(TShape * th
    //                              Shape.cpp:772 (10)
    //         004b9718     POP        EDI
    //         004b9719     POP        ESI
    //         004b971a     POP        EBP
    //         004b971b     POP        EBX
    //         004b971c     ADD        ESP,0x1c
    //         004b971f     RET        0x18
    //                               LAB_004b9722                                                 XREF[1]:     004b96a5(j)  
    //                              Shape.cpp:722 (15)
    //         004b9722     MOV        EDX,dword ptr [ESP + param_4]
    //         004b9726     PUSH       EDX
    //         004b9727     PUSH       this
    //         004b9728     PUSH       EAX
    //         004b9729     PUSH       EDI
    //         004b972a     MOV        this,ESI
    //         004b972c     CALL       TShape::shape_draw_unclipped                     uchar shape_draw_unclipped(TShape * this, TDr
    //                              Shape.cpp:772 (10)
    //         004b9731     POP        EDI
    //         004b9732     POP        ESI
    //         004b9733     POP        EBP
    //         004b9734     POP        EBX
    //         004b9735     ADD        ESP,0x1c
    //         004b9738     RET        0x18
    //                               LAB_004b973b                                                 XREF[2]:     004b9688(j), 004b9692(j)  
    //                              Shape.cpp:738 (4)
    //         004b973b     MOV        EDX,dword ptr [ESP + param_3]
    //                               LAB_004b973f                                                 XREF[2]:     004b9670(j), 004b9678(j)  
    //                              Shape.cpp:742 (21)
    //         004b973f     MOV        EBX,dword ptr [ESP + param_5]
    //         004b9743     AND        EBX,0xff
    //         004b9749     SUB        EBX,0x0
    //         004b974c     JZ         LAB_004b97ab
    //         004b974e     DEC        EBX
    //         004b974f     JZ         LAB_004b977d
    //         004b9751     DEC        EBX
    //         004b9752     JNZ        LAB_004b97cb
    //                              Shape.cpp:754 (6)
    //         004b9754     MOV        EBX,dword ptr [ESP + param_6]
    //         004b9758     TEST       EBX,EBX
    //                              Shape.cpp:756 (2)
    //         004b975a     JZ         LAB_004b97ab
    //                              Shape.cpp:757 (23)
    //         004b975c     PUSH       EBX
    //         004b975d     MOV        EBX,dword ptr [ESP + param_2]
    //         004b9761     PUSH       EBP
    //         004b9762     PUSH       EBX
    //         004b9763     PUSH       EDX
    //         004b9764     MOV        EDX,dword ptr [ESP + param_1]
    //         004b9768     PUSH       EDX
    //         004b9769     PUSH       this
    //         004b976a     PUSH       EAX
    //         004b976b     PUSH       EDI
    //         004b976c     MOV        this,ESI
    //         004b976e     CALL       TShape::shape_shadow_clipped                     uchar shape_shadow_clipped(TShape * this, TDr
    //                              Shape.cpp:772 (10)
    //         004b9773     POP        EDI
    //         004b9774     POP        ESI
    //         004b9775     POP        EBP
    //         004b9776     POP        EBX
    //         004b9777     ADD        ESP,0x1c
    //         004b977a     RET        0x18
    //                               LAB_004b977d                                                 XREF[1]:     004b974f(j)  
    //                              Shape.cpp:748 (6)
    //         004b977d     MOV        EBX,dword ptr [ESP + param_6]
    //         004b9781     TEST       EBX,EBX
    //                              Shape.cpp:750 (2)
    //         004b9783     JZ         LAB_004b97ab
    //                              Shape.cpp:751 (28)
    //         004b9785     PUSH       EBX
    //         004b9786     MOV        EBX,dword ptr [ESP + param_2]
    //         004b978a     PUSH       EBP
    //         004b978b     PUSH       EBX
    //         004b978c     PUSH       EDX
    //         004b978d     MOV        EDX,dword ptr [ESP + param_1]
    //         004b9791     PUSH       EDX
    //         004b9792     MOV        EDX,dword ptr [ESP + param_4]
    //         004b9796     PUSH       EDX
    //         004b9797     PUSH       this
    //         004b9798     PUSH       EAX
    //         004b9799     PUSH       EDI
    //         004b979a     MOV        this,ESI
    //         004b979c     CALL       TShape::shape_color_trans_clipped                uchar shape_color_trans_clipped(TShape * this
    //                              Shape.cpp:772 (10)
    //         004b97a1     POP        EDI
    //         004b97a2     POP        ESI
    //         004b97a3     POP        EBP
    //         004b97a4     POP        EBX
    //         004b97a5     ADD        ESP,0x1c
    //         004b97a8     RET        0x18
    //                               LAB_004b97ab                                                 XREF[3]:     004b974c(j), 004b975a(j), 
    //                                                                                                         004b9783(j)  
    //                              Shape.cpp:745 (22)
    //         004b97ab     MOV        EBX,dword ptr [ESP + param_2]
    //         004b97af     PUSH       EBP
    //         004b97b0     PUSH       EBX
    //         004b97b1     PUSH       EDX
    //         004b97b2     MOV        EDX,dword ptr [ESP + param_1]
    //         004b97b6     PUSH       EDX
    //         004b97b7     PUSH       this
    //         004b97b8     PUSH       EAX
    //         004b97b9     PUSH       EDI
    //         004b97ba     MOV        this,ESI
    //         004b97bc     CALL       TShape::shape_draw_clipped                       uchar shape_draw_clipped(TShape * this, TDraw
    //                              Shape.cpp:772 (10)
    //         004b97c1     POP        EDI
    //         004b97c2     POP        ESI
    //         004b97c3     POP        EBP
    //         004b97c4     POP        EBX
    //         004b97c5     ADD        ESP,0x1c
    //         004b97c8     RET        0x18
    //                               LAB_004b97cb                                                 XREF[2]:     004b96ab(j), 004b9752(j)  
    //                              Shape.cpp:745 (4)
    //         004b97cb     MOV        AL,byte ptr [ESP + shape_y1+0x3]
    //                              Shape.cpp:772 (22)
    //         004b97cf     POP        EDI
    //         004b97d0     POP        ESI
    //         004b97d1     POP        EBP
    //         004b97d2     POP        EBX
    //         004b97d3     ADD        ESP,0x1c
    //         004b97d6     RET        0x18
    //                               LAB_004b97d9                                                 XREF[5]:     004b9454(j), 004b9467(j), 
    //                                                                                                         004b95ab(j), 004b965a(j), 
    //                                                                                                         004b9666(j)  
    //         004b97d9     POP        EDI
    //         004b97da     POP        ESI
    //         004b97db     POP        EBP
    //         004b97dc     XOR        AL,AL
    //         004b97de     POP        EBX
    //         004b97df     ADD        ESP,0x1c
    //         004b97e2     RET        0x18
}

// Offset: 0x004B97F0
uchar shape_draw_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_draw_unclipped(class TDrawArea *,long,long,long)      *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_draw_unclipped(TShape * this, TDrawArea * par
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004b97f5(R), 004b984b(W), 004b98bd(R), 004b98c8(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004b9837(R), 004b9841(W), 004b98b5(R), 004b98c4(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     004b981e(R), 004b982f(R), 004b9860(W), 004b986e(R), 
    //                                                                                     004b988b(W), 004b9895(R)  
    //              long              Stack[0x10]:4  param_4
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b9818(W), 004b98b9(R)  
    //              long              Stack[-0x8]:4  width
    //                               ?shape_draw_unclipped@TShape@@AAEEPAVTDrawArea@@JJJ@Z        XREF[3]:     shape_draw:004b96c3(c), 
    //                               TShape::shape_draw_unclipped                                              shape_draw:004b96f9(c), 
    //                                                                                                         shape_draw:004b972c(c)  
    //                              Shape.cpp:777 (1)
    //         004b97f0     PUSH       this
    //                              Shape.cpp:779 (4)
    //         004b97f1     MOV        EAX,dword ptr [ECX + this->shape_header]
    //         004b97f4     PUSH       EBX
    //                              Shape.cpp:789 (32)
    //         004b97f5     MOV        EBX,dword ptr [ESP + param_1]
    //         004b97f9     PUSH       EBP
    //         004b97fa     MOV        EBP,dword ptr [EAX + 0x14]
    //         004b97fd     PUSH       ESI
    //         004b97fe     MOV        ESI,dword ptr [EAX + 0xc]
    //         004b9801     PUSH       EDI
    //         004b9802     SUB        EBP,ESI
    //         004b9804     MOV        ESI,dword ptr [EBX + 0x24]
    //         004b9807     MOV        this,EBX
    //         004b9809     INC        EBP
    //         004b980a     LEA        EDI,[EAX + 0x18]
    //         004b980d     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004b9812     IMUL       EAX,ESI
    //                              Shape.cpp:790 (9)
    //         004b9815     CMP        ESI,0x1
    //         004b9818     MOV        dword ptr [ESP + local_4],EAX
    //         004b981c     JGE        LAB_004b982d
    //                              Shape.cpp:791 (13)
    //         004b981e     MOV        ESI,dword ptr [ESP + param_3]
    //         004b9822     MOV        this,dword ptr [EBX + 0x1c]
    //         004b9825     SUB        ESI,this
    //         004b9827     INC        ESI
    //         004b9828     IMUL       ESI,EAX
    //                              Shape.cpp:792 (2)
    //         004b982b     JMP        LAB_004b9834
    //                               LAB_004b982d                                                 XREF[1]:     004b981c(j)  
    //                              Shape.cpp:793 (18)
    //         004b982d     MOV        ESI,EAX
    //         004b982f     IMUL       ESI,dword ptr [ESP + param_3]
    //                               LAB_004b9834                                                 XREF[1]:     004b982b(j)  
    //         004b9834     MOV        this,dword ptr [EBX + 0x8]
    //         004b9837     MOV        EAX,dword ptr [ESP + param_2]
    //         004b983b     ADD        ESI,this
    //         004b983d     ADD        ESI,EAX
    //                              Shape.cpp:796 (12)
    //         004b983f     TEST       EBP,EBP
    //         004b9841     MOV        dword ptr [ESP + param_2],ESI
    //         004b9845     JLE        LAB_004b98ce
    //                              Shape.cpp:794 (4)
    //         004b984b     MOV        dword ptr [ESP + param_1],EBP
    //                               LAB_004b984f                                                 XREF[1]:     004b98cc(j)  
    //                              Shape.cpp:798 (2)
    //         004b984f     XOR        BL,BL
    //                               LAB_004b9851                                                 XREF[1]:     004b98b3(j)  
    //                              Shape.cpp:801 (2)
    //         004b9851     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:802 (1)
    //         004b9853     INC        EDI
    //                              Shape.cpp:803 (10)
    //         004b9854     MOV        this,AL
    //         004b9856     AND        this,0x1
    //         004b9859     CMP        this,0x1
    //         004b985c     JNZ        LAB_004b9889
    //                              Shape.cpp:805 (6)
    //         004b985e     SHR        AL,0x1
    //         004b9860     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:806 (2)
    //         004b9864     JNZ        LAB_004b986e
    //                              Shape.cpp:808 (6)
    //         004b9866     XOR        EDX,EDX
    //         004b9868     MOV        DL,byte ptr [EDI]
    //         004b986a     ADD        ESI,EDX
    //                              Shape.cpp:811 (2)
    //         004b986c     JMP        LAB_004b98b0
    //                               LAB_004b986e                                                 XREF[1]:     004b9864(j)  
    //                              Shape.cpp:813 (21)
    //         004b986e     MOV        EBP,dword ptr [ESP + param_3]
    //         004b9872     AND        EBP,0xff
    //         004b9878     PUSH       EBP
    //         004b9879     PUSH       EDI
    //         004b987a     PUSH       ESI
    //         004b987b     CALL       memcpy                                           undefined memcpy()
    //         004b9880     ADD        ESP,0xc
    //                              Shape.cpp:814 (2)
    //         004b9883     ADD        ESI,EBP
    //                              Shape.cpp:815 (2)
    //         004b9885     ADD        EDI,EBP
    //                              Shape.cpp:818 (2)
    //         004b9887     JMP        LAB_004b98b1
    //                               LAB_004b9889                                                 XREF[1]:     004b985c(j)  
    //                              Shape.cpp:820 (6)
    //         004b9889     SHR        AL,0x1
    //         004b988b     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:821 (2)
    //         004b988f     JNZ        LAB_004b9895
    //                              Shape.cpp:822 (2)
    //         004b9891     MOV        BL,0x1
    //                              Shape.cpp:823 (2)
    //         004b9893     JMP        LAB_004b98b1
    //                               LAB_004b9895                                                 XREF[1]:     004b988f(j)  
    //                              Shape.cpp:825 (25)
    //         004b9895     MOV        EBP,dword ptr [ESP + param_3]
    //         004b9899     XOR        EAX,EAX
    //         004b989b     MOV        AL,byte ptr [EDI]
    //         004b989d     AND        EBP,0xff
    //         004b98a3     PUSH       EBP
    //         004b98a4     PUSH       EAX
    //         004b98a5     PUSH       ESI
    //         004b98a6     CALL       memset                                           undefined memset()
    //         004b98ab     ADD        ESP,0xc
    //                              Shape.cpp:826 (2)
    //         004b98ae     ADD        ESI,EBP
    //                               LAB_004b98b0                                                 XREF[1]:     004b986c(j)  
    //                              Shape.cpp:827 (1)
    //         004b98b0     INC        EDI
    //                               LAB_004b98b1                                                 XREF[2]:     004b9887(j), 004b9893(j)  
    //                              Shape.cpp:799 (4)
    //         004b98b1     TEST       BL,BL
    //         004b98b3     JZ         LAB_004b9851
    //                              Shape.cpp:831 (25)
    //         004b98b5     MOV        ESI,dword ptr [ESP + param_2]
    //         004b98b9     MOV        this,dword ptr [ESP + local_4]
    //         004b98bd     MOV        EAX,dword ptr [ESP + param_1]
    //         004b98c1     ADD        ESI,this
    //         004b98c3     DEC        EAX
    //         004b98c4     MOV        dword ptr [ESP + param_2],ESI
    //         004b98c8     MOV        dword ptr [ESP + param_1],EAX
    //         004b98cc     JNZ        LAB_004b984f
    //                               LAB_004b98ce                                                 XREF[1]:     004b9845(j)  
    //                              Shape.cpp:836 (10)
    //         004b98ce     POP        EDI
    //         004b98cf     POP        ESI
    //         004b98d0     POP        EBP
    //         004b98d1     MOV        AL,0x1
    //         004b98d3     POP        EBX
    //         004b98d4     POP        this
    //         004b98d5     RET        0x10
}

// Offset: 0x004B98E0
uchar shape_color_trans_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, uchar* param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_color_trans_unclipped(class TDrawArea *,long,long,... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_color_trans_unclipped(TShape * this, TDrawAre
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004b98e4(R), 004b9933(W), 004b99c3(R), 004b99d2(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     004b9929(R), 004b9959(W), 004b9967(R), 004b998d(W), 
    //                                                                                     004b999a(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004b9910(R), 004b9921(R), 004b9945(W), 004b9993(W), 
    //                                                                                     004b99bb(R)  
    //              long              Stack[0x10]:4  param_4
    //              uchar *           Stack[0x14]:4  param_5                   XREF[1]:     004b993d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b990a(W), 004b99c7(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004b9941(W), 004b99cb(R), 004b99d6(W)  
    //                               ?shape_color_trans_unclipped@TShape@@AAEEPAVTDrawArea@@JJJP  XREF[1]:     shape_draw:004b9713(c)  
    //                               TShape::shape_color_trans_unclipped
    //                              Shape.cpp:841 (4)
    //         004b98e0     SUB        ESP,0x8
    //         004b98e3     PUSH       EBX
    //                              Shape.cpp:854 (35)
    //         004b98e4     MOV        EBX,dword ptr [ESP + param_1]
    //         004b98e8     PUSH       EBP
    //         004b98e9     PUSH       ESI
    //         004b98ea     PUSH       EDI
    //         004b98eb     MOV        EDI,dword ptr [ECX + this->shape_header]
    //         004b98ee     MOV        this,EBX
    //         004b98f0     MOV        EBP,dword ptr [EDI + 0x14]
    //         004b98f3     MOV        ESI,dword ptr [EDI + 0xc]
    //         004b98f6     SUB        EBP,ESI
    //         004b98f8     MOV        ESI,dword ptr [EBX + 0x24]
    //         004b98fb     INC        EBP
    //         004b98fc     ADD        EDI,0x18
    //         004b98ff     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004b9904     IMUL       EAX,ESI
    //                              Shape.cpp:856 (9)
    //         004b9907     CMP        ESI,0x1
    //         004b990a     MOV        dword ptr [ESP + local_4],EAX
    //         004b990e     JGE        LAB_004b991f
    //                              Shape.cpp:857 (13)
    //         004b9910     MOV        ESI,dword ptr [ESP + param_3]
    //         004b9914     MOV        this,dword ptr [EBX + 0x1c]
    //         004b9917     SUB        ESI,this
    //         004b9919     INC        ESI
    //         004b991a     IMUL       ESI,EAX
    //                              Shape.cpp:858 (2)
    //         004b991d     JMP        LAB_004b9926
    //                               LAB_004b991f                                                 XREF[1]:     004b990e(j)  
    //                              Shape.cpp:859 (18)
    //         004b991f     MOV        ESI,EAX
    //         004b9921     IMUL       ESI,dword ptr [ESP + param_3]
    //                               LAB_004b9926                                                 XREF[1]:     004b991d(j)  
    //         004b9926     MOV        this,dword ptr [EBX + 0x8]
    //         004b9929     MOV        EAX,dword ptr [ESP + param_2]
    //         004b992d     ADD        ESI,this
    //         004b992f     ADD        ESI,EAX
    //                              Shape.cpp:862 (20)
    //         004b9931     TEST       EBP,EBP
    //         004b9933     MOV        dword ptr [ESP + param_1],ESI
    //         004b9937     JLE        LAB_004b99e0
    //         004b993d     MOV        EBX,dword ptr [ESP + param_5]
    //         004b9941     MOV        dword ptr [ESP + width],EBP
    //                               LAB_004b9945                                                 XREF[1]:     004b99da(j)  
    //                              Shape.cpp:864 (5)
    //         004b9945     MOV        byte ptr [ESP + param_3],0x0
    //                               LAB_004b994a                                                 XREF[1]:     004b99c1(j)  
    //                              Shape.cpp:867 (2)
    //         004b994a     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:868 (1)
    //         004b994c     INC        EDI
    //                              Shape.cpp:869 (10)
    //         004b994d     MOV        this,AL
    //         004b994f     AND        this,0x1
    //         004b9952     CMP        this,0x1
    //         004b9955     JNZ        LAB_004b998b
    //                              Shape.cpp:871 (6)
    //         004b9957     SHR        AL,0x1
    //         004b9959     MOV        byte ptr [ESP + param_2],AL
    //                              Shape.cpp:872 (2)
    //         004b995d     JNZ        LAB_004b9967
    //                              Shape.cpp:874 (6)
    //         004b995f     XOR        EDX,EDX
    //         004b9961     MOV        DL,byte ptr [EDI]
    //         004b9963     ADD        ESI,EDX
    //                              Shape.cpp:877 (2)
    //         004b9965     JMP        LAB_004b99ba
    //                               LAB_004b9967                                                 XREF[1]:     004b995d(j)  
    //                              Shape.cpp:879 (14)
    //         004b9967     MOV        this,dword ptr [ESP + param_2]
    //         004b996b     MOV        EAX,ESI
    //         004b996d     AND        this,0xff
    //         004b9973     ADD        EAX,this
    //                              Shape.cpp:880 (4)
    //         004b9975     CMP        ESI,EAX
    //         004b9977     JNC        LAB_004b99bb
    //                               LAB_004b9979                                                 XREF[1]:     004b9987(j)  
    //                              Shape.cpp:882 (4)
    //         004b9979     XOR        EDX,EDX
    //         004b997b     MOV        DL,byte ptr [EDI]
    //                              Shape.cpp:883 (12)
    //         004b997d     INC        EDI
    //         004b997e     INC        ESI
    //         004b997f     MOV        this,byte ptr [EDX + EBX*0x1]
    //         004b9982     CMP        ESI,EAX
    //         004b9984     MOV        byte ptr [ESI + -0x1],this
    //         004b9987     JC         LAB_004b9979
    //                              Shape.cpp:887 (2)
    //         004b9989     JMP        LAB_004b99bb
    //                               LAB_004b998b                                                 XREF[1]:     004b9955(j)  
    //                              Shape.cpp:889 (6)
    //         004b998b     SHR        AL,0x1
    //         004b998d     MOV        byte ptr [ESP + param_2],AL
    //                              Shape.cpp:890 (2)
    //         004b9991     JNZ        LAB_004b999a
    //                              Shape.cpp:891 (5)
    //         004b9993     MOV        byte ptr [ESP + param_3],0x1
    //                              Shape.cpp:892 (2)
    //         004b9998     JMP        LAB_004b99bb
    //                               LAB_004b999a                                                 XREF[1]:     004b9991(j)  
    //                              Shape.cpp:894 (30)
    //         004b999a     MOV        EBP,dword ptr [ESP + param_2]
    //         004b999e     XOR        EDX,EDX
    //         004b99a0     MOV        DL,byte ptr [EDI]
    //         004b99a2     XOR        EAX,EAX
    //         004b99a4     AND        EBP,0xff
    //         004b99aa     MOV        AL,byte ptr [EDX + EBX*0x1]
    //         004b99ad     PUSH       EBP
    //         004b99ae     PUSH       EAX
    //         004b99af     PUSH       ESI
    //         004b99b0     CALL       memset                                           undefined memset()
    //         004b99b5     ADD        ESP,0xc
    //                              Shape.cpp:895 (2)
    //         004b99b8     ADD        ESI,EBP
    //                               LAB_004b99ba                                                 XREF[1]:     004b9965(j)  
    //                              Shape.cpp:896 (1)
    //         004b99ba     INC        EDI
    //                               LAB_004b99bb                                                 XREF[3]:     004b9977(j), 004b9989(j), 
    //                                                                                                         004b9998(j)  
    //                              Shape.cpp:865 (8)
    //         004b99bb     MOV        AL,byte ptr [ESP + param_3]
    //         004b99bf     TEST       AL,AL
    //         004b99c1     JZ         LAB_004b994a
    //                              Shape.cpp:900 (29)
    //         004b99c3     MOV        ESI,dword ptr [ESP + param_1]
    //         004b99c7     MOV        this,dword ptr [ESP + local_4]
    //         004b99cb     MOV        EAX,dword ptr [ESP + width]
    //         004b99cf     ADD        ESI,this
    //         004b99d1     DEC        EAX
    //         004b99d2     MOV        dword ptr [ESP + param_1],ESI
    //         004b99d6     MOV        dword ptr [ESP + width],EAX
    //         004b99da     JNZ        LAB_004b9945
    //                               LAB_004b99e0                                                 XREF[1]:     004b9937(j)  
    //                              Shape.cpp:905 (12)
    //         004b99e0     POP        EDI
    //         004b99e1     POP        ESI
    //         004b99e2     POP        EBP
    //         004b99e3     MOV        AL,0x1
    //         004b99e5     POP        EBX
    //         004b99e6     ADD        ESP,0x8
    //         004b99e9     RET        0x14
}

// Offset: 0x004B99F0
uchar shape_shadow_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, uchar* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_shadow_unclipped(class TDrawArea *,long,long,unsig... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_shadow_unclipped(TShape * this, TDrawArea * p
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004b9a03(R), 004b9a4f(W), 004b9acf(R), 004b9ada(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004b9a37(R), 004b9a41(W), 004b9ac7(R), 004b9ad6(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     004b9a1e(R), 004b9a2f(R), 004b9a63(W), 004b9a72(R), 
    //                                                                                     004b9a98(W), 004b9aa2(R)  
    //              uchar *           Stack[0x10]:4  param_4                   XREF[1]:     004b9a4b(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b9a18(W), 004b9acb(R)  
    //              long              Stack[-0x8]:4  width
    //                               ?shape_shadow_unclipped@TShape@@AAEEPAVTDrawArea@@JJPAE@Z    XREF[1]:     shape_draw:004b96d8(c)  
    //                               TShape::shape_shadow_unclipped
    //                              Shape.cpp:909 (1)
    //         004b99f0     PUSH       this
    //                              Shape.cpp:911 (13)
    //         004b99f1     MOV        EAX,dword ptr [ECX + this->shape_header]
    //         004b99f4     PUSH       EBX
    //         004b99f5     PUSH       EBP
    //         004b99f6     PUSH       ESI
    //         004b99f7     MOV        ESI,dword ptr [EAX + 0x14]
    //         004b99fa     PUSH       EDI
    //         004b99fb     MOV        EDI,dword ptr [EAX + 0xc]
    //                              Shape.cpp:913 (5)
    //         004b99fe     LEA        EBP,[EAX + 0x18]
    //         004b9a01     SUB        ESI,EDI
    //                              Shape.cpp:922 (18)
    //         004b9a03     MOV        EDI,dword ptr [ESP + param_1]
    //         004b9a07     MOV        this,EDI
    //         004b9a09     INC        ESI
    //         004b9a0a     MOV        EBX,dword ptr [EDI + 0x24]
    //         004b9a0d     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004b9a12     IMUL       EAX,EBX
    //                              Shape.cpp:924 (9)
    //         004b9a15     CMP        EBX,0x1
    //         004b9a18     MOV        dword ptr [ESP + local_4],EAX
    //         004b9a1c     JGE        LAB_004b9a2d
    //                              Shape.cpp:925 (13)
    //         004b9a1e     MOV        this,dword ptr [ESP + param_3]
    //         004b9a22     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004b9a25     SUB        this,EDX
    //         004b9a27     INC        this
    //         004b9a28     IMUL       this,EAX
    //                              Shape.cpp:926 (2)
    //         004b9a2b     JMP        LAB_004b9a34
    //                               LAB_004b9a2d                                                 XREF[1]:     004b9a1c(j)  
    //                              Shape.cpp:927 (18)
    //         004b9a2d     MOV        this,EAX
    //         004b9a2f     IMUL       this,dword ptr [ESP + param_3]
    //                               LAB_004b9a34                                                 XREF[1]:     004b9a2b(j)  
    //         004b9a34     MOV        EDX,dword ptr [EDI + 0x8]
    //         004b9a37     MOV        EAX,dword ptr [ESP + param_2]
    //         004b9a3b     ADD        this,EDX
    //         004b9a3d     ADD        this,EAX
    //                              Shape.cpp:930 (20)
    //         004b9a3f     TEST       ESI,ESI
    //         004b9a41     MOV        dword ptr [ESP + param_2],this
    //         004b9a45     JLE        LAB_004b9ae4
    //         004b9a4b     MOV        EDI,dword ptr [ESP + param_4]
    //         004b9a4f     MOV        dword ptr [ESP + param_1],ESI
    //                               LAB_004b9a53                                                 XREF[1]:     004b9ade(j)  
    //                              Shape.cpp:932 (2)
    //         004b9a53     XOR        BL,BL
    //                               LAB_004b9a55                                                 XREF[1]:     004b9ac5(j)  
    //                              Shape.cpp:935 (3)
    //         004b9a55     MOV        DL,byte ptr [EBP]
    //                              Shape.cpp:936 (1)
    //         004b9a58     INC        EBP
    //                              Shape.cpp:937 (8)
    //         004b9a59     MOV        AL,DL
    //         004b9a5b     AND        AL,0x1
    //         004b9a5d     CMP        AL,0x1
    //         004b9a5f     JNZ        LAB_004b9a96
    //                              Shape.cpp:939 (6)
    //         004b9a61     SHR        DL,0x1
    //         004b9a63     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:940 (2)
    //         004b9a67     JNZ        LAB_004b9a72
    //                              Shape.cpp:942 (7)
    //         004b9a69     XOR        EDX,EDX
    //         004b9a6b     MOV        DL,byte ptr [EBP]
    //         004b9a6e     ADD        this,EDX
    //                              Shape.cpp:945 (2)
    //         004b9a70     JMP        LAB_004b9ac2
    //                               LAB_004b9a72                                                 XREF[1]:     004b9a67(j)  
    //                              Shape.cpp:947 (13)
    //         004b9a72     MOV        ESI,dword ptr [ESP + param_3]
    //         004b9a76     AND        ESI,0xff
    //         004b9a7c     LEA        EDX,[this->shape + ESI*0x1]
    //                              Shape.cpp:948 (4)
    //         004b9a7f     CMP        this,EDX
    //         004b9a81     JNC        LAB_004b9a92
    //                               LAB_004b9a83                                                 XREF[1]:     004b9a90(j)  
    //                              Shape.cpp:949 (15)
    //         004b9a83     XOR        EAX,EAX
    //         004b9a85     MOV        AL,byte ptr [this->shape]
    //         004b9a87     INC        this
    //         004b9a88     CMP        this,EDX
    //         004b9a8a     MOV        AL,byte ptr [EAX + EDI*0x1]
    //         004b9a8d     MOV        byte ptr [this->shape + -0x1],AL
    //         004b9a90     JC         LAB_004b9a83
    //                               LAB_004b9a92                                                 XREF[1]:     004b9a81(j)  
    //                              Shape.cpp:950 (2)
    //         004b9a92     ADD        EBP,ESI
    //                              Shape.cpp:953 (2)
    //         004b9a94     JMP        LAB_004b9ac3
    //                               LAB_004b9a96                                                 XREF[1]:     004b9a5f(j)  
    //                              Shape.cpp:955 (6)
    //         004b9a96     SHR        DL,0x1
    //         004b9a98     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:956 (2)
    //         004b9a9c     JNZ        LAB_004b9aa2
    //                              Shape.cpp:957 (2)
    //         004b9a9e     MOV        BL,0x1
    //                              Shape.cpp:958 (2)
    //         004b9aa0     JMP        LAB_004b9ac3
    //                               LAB_004b9aa2                                                 XREF[1]:     004b9a9c(j)  
    //                              Shape.cpp:960 (13)
    //         004b9aa2     MOV        EAX,dword ptr [ESP + param_3]
    //         004b9aa6     MOV        EDX,this
    //         004b9aa8     AND        EAX,0xff
    //         004b9aad     ADD        EDX,EAX
    //                              Shape.cpp:961 (4)
    //         004b9aaf     CMP        this,EDX
    //         004b9ab1     JNC        LAB_004b9ac2
    //                               LAB_004b9ab3                                                 XREF[1]:     004b9ac0(j)  
    //                              Shape.cpp:962 (15)
    //         004b9ab3     XOR        EAX,EAX
    //         004b9ab5     MOV        AL,byte ptr [this->shape]
    //         004b9ab7     INC        this
    //         004b9ab8     CMP        this,EDX
    //         004b9aba     MOV        AL,byte ptr [EAX + EDI*0x1]
    //         004b9abd     MOV        byte ptr [this->shape + -0x1],AL
    //         004b9ac0     JC         LAB_004b9ab3
    //                               LAB_004b9ac2                                                 XREF[2]:     004b9a70(j), 004b9ab1(j)  
    //                              Shape.cpp:963 (1)
    //         004b9ac2     INC        EBP
    //                               LAB_004b9ac3                                                 XREF[2]:     004b9a94(j), 004b9aa0(j)  
    //                              Shape.cpp:933 (4)
    //         004b9ac3     TEST       BL,BL
    //         004b9ac5     JZ         LAB_004b9a55
    //                              Shape.cpp:967 (29)
    //         004b9ac7     MOV        this,dword ptr [ESP + param_2]
    //         004b9acb     MOV        EDX,dword ptr [ESP + local_4]
    //         004b9acf     MOV        EAX,dword ptr [ESP + param_1]
    //         004b9ad3     ADD        this,EDX
    //         004b9ad5     DEC        EAX
    //         004b9ad6     MOV        dword ptr [ESP + param_2],this
    //         004b9ada     MOV        dword ptr [ESP + param_1],EAX
    //         004b9ade     JNZ        LAB_004b9a53
    //                               LAB_004b9ae4                                                 XREF[1]:     004b9a45(j)  
    //                              Shape.cpp:972 (10)
    //         004b9ae4     POP        EDI
    //         004b9ae5     POP        ESI
    //         004b9ae6     POP        EBP
    //         004b9ae7     MOV        AL,0x1
    //         004b9ae9     POP        EBX
    //         004b9aea     POP        this
    //         004b9aeb     RET        0x10
}

// Offset: 0x004B9AF0
uchar shape_draw_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_draw_clipped(class TDrawArea *,long,long,long,long... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_draw_clipped(TShape * this, TDrawArea * param
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[13]:    004b9af4(R), 004b9b75(W), 004b9b7b(R), 004b9bd7(W), 
    //                                                                                     004b9c0c(R), 004b9c6f(W), 004b9c7c(R), 004b9cf5(W), 
    //                                                                                     004b9d19(R), 004b9d5c(W), 004b9d69(R), 004b9dcd(W), 
    //                                                                                     004b9dd3(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004b9bb3(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     004b9b4d(R), 004b9c18(W), 004b9c43(R), 004b9c5c(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[7]:     004b9b2f(R), 004b9b43(R), 004b9c28(R), 004b9c3f(R), 
    //                                                                                     004b9c60(R), 004b9cb9(R), 004b9da2(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[26]:    004b9b1b(R), 004b9b37(R), 004b9b5d(W), 004b9b95(R), 
    //                                                                                     004b9b9a(W), 004b9bbf(W), 004b9bf2(W), 004b9bfe(W), 
    //                                                                                     004b9c2c(W), 004b9c49(W), 004b9c75(W), 004b9c96(W), 
    //                                                                                     004b9ca6(W), 004b9cc3(R), 004b9cd1(W), 004b9cd6(R), 
    //                                                                                     004b9cdc(W), 004b9d10(W), 004b9d2f(W), 004b9d62(W)  
    //              long              Stack[0x18]:4  param_6                   XREF[6]:     004b9bec(R), 004b9c20(R), 004b9c8c(R), 004b9d03(R), 
    //                                                                                     004b9d1d(R), 004b9d6d(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[4]:     004b9ba0(R), 004b9baf(W), 004b9dfc(R), 004b9e07(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b9b15(W), 004b9df8(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004b9b51(W), 004b9df4(R), 004b9e03(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer
    //                               ?shape_draw_clipped@TShape@@AAEEPAVTDrawArea@@JJJJJJ@Z       XREF[1]:     shape_draw:004b97bc(c)  
    //                               TShape::shape_draw_clipped
    //                              Shape.cpp:976 (4)
    //         004b9af0     SUB        ESP,0x8
    //         004b9af3     PUSH       EBX
    //                              Shape.cpp:977 (21)
    //         004b9af4     MOV        EBX,dword ptr [ESP + param_1]
    //         004b9af8     PUSH       EBP
    //         004b9af9     PUSH       ESI
    //         004b9afa     MOV        ESI,dword ptr [EBX + 0x24]
    //         004b9afd     PUSH       EDI
    //         004b9afe     MOV        EDI,this
    //         004b9b00     MOV        this,EBX
    //         004b9b02     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004b9b07     MOV        this,EAX
    //                              Shape.cpp:984 (9)
    //         004b9b09     MOV        EDI,dword ptr [EDI + 0xc]
    //         004b9b0c     IMUL       this,ESI
    //         004b9b0f     ADD        EDI,0x18
    //                              Shape.cpp:990 (9)
    //         004b9b12     CMP        ESI,0x1
    //         004b9b15     MOV        dword ptr [ESP + local_4],this
    //         004b9b19     JGE        LAB_004b9b37
    //                              Shape.cpp:991 (26)
    //         004b9b1b     MOV        EAX,dword ptr [ESP + param_5]
    //         004b9b1f     MOV        EDX,dword ptr [EBX + 0x1c]
    //         004b9b22     MOV        ESI,EAX
    //         004b9b24     SUB        ESI,EDX
    //         004b9b26     MOV        EDX,dword ptr [EBX + 0x8]
    //         004b9b29     INC        ESI
    //         004b9b2a     IMUL       ESI,this
    //         004b9b2d     ADD        ESI,EDX
    //         004b9b2f     MOV        EDX,dword ptr [ESP + param_4]
    //         004b9b33     ADD        ESI,EDX
    //                              Shape.cpp:992 (2)
    //         004b9b35     JMP        LAB_004b9b4d
    //                               LAB_004b9b37                                                 XREF[1]:     004b9b19(j)  
    //                              Shape.cpp:993 (22)
    //         004b9b37     MOV        EAX,dword ptr [ESP + param_5]
    //         004b9b3b     MOV        ESI,this
    //         004b9b3d     IMUL       ESI,EAX
    //         004b9b40     MOV        EDX,dword ptr [EBX + 0x8]
    //         004b9b43     MOV        this,dword ptr [ESP + param_4]
    //         004b9b47     ADD        ESI,EDX
    //         004b9b49     MOV        EDX,this
    //         004b9b4b     ADD        ESI,this
    //                               LAB_004b9b4d                                                 XREF[1]:     004b9b35(j)  
    //                              Shape.cpp:997 (23)
    //         004b9b4d     MOV        this,dword ptr [ESP + param_3]
    //         004b9b51     MOV        dword ptr [ESP + width],ESI
    //         004b9b55     CMP        this,EAX
    //         004b9b57     MOV        EBP,this
    //         004b9b59     JGE        LAB_004b9ba0
    //         004b9b5b     SUB        EAX,this
    //         004b9b5d     MOV        dword ptr [ESP + param_5],EAX
    //         004b9b61     LEA        EBP,[this->shape + EAX*0x1]
    //                               LAB_004b9b64                                                 XREF[1]:     004b9b9e(j)  
    //                              Shape.cpp:999 (2)
    //         004b9b64     XOR        this,this
    //                               LAB_004b9b66                                                 XREF[1]:     004b9b93(j)  
    //                              Shape.cpp:1002 (2)
    //         004b9b66     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1003 (1)
    //         004b9b68     INC        EDI
    //                              Shape.cpp:1004 (10)
    //         004b9b69     MOV        BL,AL
    //         004b9b6b     AND        BL,0x1
    //         004b9b6e     CMP        BL,0x1
    //         004b9b71     JNZ        LAB_004b9b88
    //                              Shape.cpp:1006 (6)
    //         004b9b73     SHR        AL,0x1
    //         004b9b75     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1009 (2)
    //         004b9b79     JZ         LAB_004b9b90
    //                              Shape.cpp:1010 (11)
    //         004b9b7b     MOV        EAX,dword ptr [ESP + param_1]
    //         004b9b7f     AND        EAX,0xff
    //         004b9b84     ADD        EDI,EAX
    //                              Shape.cpp:1012 (2)
    //         004b9b86     JMP        LAB_004b9b91
    //                               LAB_004b9b88                                                 XREF[1]:     004b9b71(j)  
    //                              Shape.cpp:1015 (4)
    //         004b9b88     TEST       AL,0xfe
    //         004b9b8a     JNZ        LAB_004b9b90
    //                              Shape.cpp:1016 (2)
    //         004b9b8c     MOV        this,0x1
    //                              Shape.cpp:1017 (2)
    //         004b9b8e     JMP        LAB_004b9b91
    //                               LAB_004b9b90                                                 XREF[2]:     004b9b79(j), 004b9b8a(j)  
    //                              Shape.cpp:1018 (1)
    //         004b9b90     INC        EDI
    //                               LAB_004b9b91                                                 XREF[2]:     004b9b86(j), 004b9b8e(j)  
    //                              Shape.cpp:1000 (15)
    //         004b9b91     TEST       this,this
    //         004b9b93     JZ         LAB_004b9b66
    //         004b9b95     MOV        EAX,dword ptr [ESP + param_5]
    //         004b9b99     DEC        EAX
    //         004b9b9a     MOV        dword ptr [ESP + param_5],EAX
    //         004b9b9e     JNZ        LAB_004b9b64
    //                               LAB_004b9ba0                                                 XREF[1]:     004b9b59(j)  
    //                              Shape.cpp:1024 (19)
    //         004b9ba0     MOV        EAX,dword ptr [ESP + param_7]
    //         004b9ba4     CMP        EBP,EAX
    //         004b9ba6     JG         LAB_004b9e11
    //         004b9bac     SUB        EAX,EBP
    //         004b9bae     INC        EAX
    //         004b9baf     MOV        dword ptr [ESP + param_7],EAX
    //                               LAB_004b9bb3                                                 XREF[1]:     004b9e0b(j)  
    //                              Shape.cpp:1026 (4)
    //         004b9bb3     MOV        EBP,dword ptr [ESP + param_2]
    //                              Shape.cpp:1029 (8)
    //         004b9bb7     CMP        EBP,EDX
    //         004b9bb9     JGE        LAB_004b9cd1
    //                              Shape.cpp:1031 (5)
    //         004b9bbf     MOV        byte ptr [ESP + param_5],0x0
    //                               LAB_004b9bc4                                                 XREF[1]:     004b9cc9(j)  
    //                              Shape.cpp:1034 (2)
    //         004b9bc4     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1035 (1)
    //         004b9bc6     INC        EDI
    //                              Shape.cpp:1036 (14)
    //         004b9bc7     MOV        this,AL
    //         004b9bc9     AND        this,0x1
    //         004b9bcc     CMP        this,0x1
    //         004b9bcf     JNZ        LAB_004b9c6d
    //                              Shape.cpp:1038 (6)
    //         004b9bd5     SHR        AL,0x1
    //         004b9bd7     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1039 (2)
    //         004b9bdb     JNZ        LAB_004b9c0c
    //                              Shape.cpp:1041 (6)
    //         004b9bdd     XOR        EAX,EAX
    //         004b9bdf     MOV        AL,byte ptr [EDI]
    //         004b9be1     ADD        EBP,EAX
    //                              Shape.cpp:1042 (1)
    //         004b9be3     INC        EDI
    //                              Shape.cpp:1043 (8)
    //         004b9be4     CMP        EBP,EDX
    //         004b9be6     JL         LAB_004b9cc3
    //                              Shape.cpp:1045 (6)
    //         004b9bec     CMP        EBP,dword ptr [ESP + param_6]
    //         004b9bf0     JLE        LAB_004b9bfc
    //                              Shape.cpp:1046 (5)
    //         004b9bf2     MOV        byte ptr [ESP + param_5],0x2
    //                              Shape.cpp:1047 (5)
    //         004b9bf7     JMP        LAB_004b9cc3
    //                               LAB_004b9bfc                                                 XREF[1]:     004b9bf0(j)  
    //                              Shape.cpp:1050 (11)
    //         004b9bfc     MOV        this,EBP
    //         004b9bfe     MOV        byte ptr [ESP + param_5],0x1
    //         004b9c03     SUB        this,EDX
    //         004b9c05     ADD        ESI,this
    //                              Shape.cpp:1054 (5)
    //         004b9c07     JMP        LAB_004b9cc3
    //                               LAB_004b9c0c                                                 XREF[1]:     004b9bdb(j)  
    //                              Shape.cpp:1056 (16)
    //         004b9c0c     MOV        this,dword ptr [ESP + param_1]
    //         004b9c10     AND        this,0xff
    //         004b9c16     ADD        EBP,this
    //         004b9c18     MOV        dword ptr [ESP + param_3],this
    //                              Shape.cpp:1057 (4)
    //         004b9c1c     CMP        EBP,EDX
    //         004b9c1e     JL         LAB_004b9c69
    //                              Shape.cpp:1059 (8)
    //         004b9c20     MOV        EBX,dword ptr [ESP + param_6]
    //         004b9c24     CMP        EBP,EBX
    //         004b9c26     JLE        LAB_004b9c3f
    //                              Shape.cpp:1064 (11)
    //         004b9c28     MOV        EAX,dword ptr [ESP + param_4]
    //         004b9c2c     MOV        byte ptr [ESP + param_5],0x2
    //         004b9c31     SUB        EBX,EAX
    //                              Shape.cpp:1065 (10)
    //         004b9c33     LEA        EDX,[EDI + EAX*0x1]
    //         004b9c36     INC        EBX
    //         004b9c37     SUB        EDX,EBP
    //         004b9c39     PUSH       EBX
    //         004b9c3a     ADD        EDX,this
    //         004b9c3c     PUSH       EDX
    //                              Shape.cpp:1068 (2)
    //         004b9c3d     JMP        LAB_004b9c56
    //                               LAB_004b9c3f                                                 XREF[1]:     004b9c26(j)  
    //                              Shape.cpp:1071 (4)
    //         004b9c3f     MOV        EDX,dword ptr [ESP + param_4]
    //                              Shape.cpp:1072 (15)
    //         004b9c43     MOV        EAX,dword ptr [ESP + param_3]
    //         004b9c47     MOV        EBX,EBP
    //         004b9c49     MOV        byte ptr [ESP + param_5],0x1
    //         004b9c4e     SUB        EBX,EDX
    //         004b9c50     SUB        EAX,EBX
    //                              Shape.cpp:1073 (10)
    //         004b9c52     PUSH       EBX
    //         004b9c53     ADD        EAX,EDI
    //         004b9c55     PUSH       EAX
    //                               LAB_004b9c56                                                 XREF[1]:     004b9c3d(j)  
    //         004b9c56     PUSH       ESI
    //         004b9c57     CALL       memcpy                                           undefined memcpy()
    //                              Shape.cpp:1074 (13)
    //         004b9c5c     MOV        this,dword ptr [ESP + param_3]
    //         004b9c60     MOV        EDX,dword ptr [ESP + param_4]
    //         004b9c64     ADD        ESP,0xc
    //         004b9c67     ADD        ESI,EBX
    //                               LAB_004b9c69                                                 XREF[1]:     004b9c1e(j)  
    //                              Shape.cpp:1077 (2)
    //         004b9c69     ADD        EDI,this
    //                              Shape.cpp:1080 (2)
    //         004b9c6b     JMP        LAB_004b9cc3
    //                               LAB_004b9c6d                                                 XREF[1]:     004b9bcf(j)  
    //                              Shape.cpp:1082 (6)
    //         004b9c6d     SHR        AL,0x1
    //         004b9c6f     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1083 (2)
    //         004b9c73     JNZ        LAB_004b9c7c
    //                              Shape.cpp:1084 (5)
    //         004b9c75     MOV        byte ptr [ESP + param_5],0x3
    //                              Shape.cpp:1085 (2)
    //         004b9c7a     JMP        LAB_004b9cc3
    //                               LAB_004b9c7c                                                 XREF[1]:     004b9c73(j)  
    //                              Shape.cpp:1087 (12)
    //         004b9c7c     MOV        this,dword ptr [ESP + param_1]
    //         004b9c80     AND        this,0xff
    //         004b9c86     ADD        EBP,this
    //                              Shape.cpp:1088 (4)
    //         004b9c88     CMP        EBP,EDX
    //         004b9c8a     JL         LAB_004b9cc2
    //                              Shape.cpp:1090 (8)
    //         004b9c8c     MOV        EBX,dword ptr [ESP + param_6]
    //         004b9c90     CMP        EBP,EBX
    //         004b9c92     JLE        LAB_004b9ca4
    //                              Shape.cpp:1093 (8)
    //         004b9c94     SUB        EBX,EDX
    //         004b9c96     MOV        byte ptr [ESP + param_5],0x2
    //         004b9c9b     INC        EBX
    //                              Shape.cpp:1094 (6)
    //         004b9c9c     XOR        EDX,EDX
    //         004b9c9e     MOV        DL,byte ptr [EDI]
    //         004b9ca0     PUSH       EBX
    //         004b9ca1     PUSH       EDX
    //                              Shape.cpp:1097 (2)
    //         004b9ca2     JMP        LAB_004b9cb3
    //                               LAB_004b9ca4                                                 XREF[1]:     004b9c92(j)  
    //                              Shape.cpp:1100 (9)
    //         004b9ca4     MOV        EBX,EBP
    //         004b9ca6     MOV        byte ptr [ESP + param_5],0x1
    //         004b9cab     SUB        EBX,EDX
    //                              Shape.cpp:1101 (12)
    //         004b9cad     XOR        EAX,EAX
    //         004b9caf     MOV        AL,byte ptr [EDI]
    //         004b9cb1     PUSH       EBX
    //         004b9cb2     PUSH       EAX
    //                               LAB_004b9cb3                                                 XREF[1]:     004b9ca2(j)  
    //         004b9cb3     PUSH       ESI
    //         004b9cb4     CALL       memset                                           undefined memset()
    //                              Shape.cpp:1102 (9)
    //         004b9cb9     MOV        EDX,dword ptr [ESP + param_4]
    //         004b9cbd     ADD        ESP,0xc
    //         004b9cc0     ADD        ESI,EBX
    //                               LAB_004b9cc2                                                 XREF[1]:     004b9c8a(j)  
    //                              Shape.cpp:1105 (1)
    //         004b9cc2     INC        EDI
    //                               LAB_004b9cc3                                                 XREF[5]:     004b9be6(j), 004b9bf7(j), 
    //                                                                                                         004b9c07(j), 004b9c6b(j), 
    //                                                                                                         004b9c7a(j)  
    //                              Shape.cpp:1032 (12)
    //         004b9cc3     MOV        AL,byte ptr [ESP + param_5]
    //         004b9cc7     TEST       AL,AL
    //         004b9cc9     JZ         LAB_004b9bc4
    //                              Shape.cpp:1110 (2)
    //         004b9ccf     JMP        LAB_004b9cd6
    //                               LAB_004b9cd1                                                 XREF[1]:     004b9bb9(j)  
    //                              Shape.cpp:1111 (5)
    //         004b9cd1     MOV        byte ptr [ESP + param_5],0x1
    //                               LAB_004b9cd6                                                 XREF[1]:     004b9ccf(j)  
    //                              Shape.cpp:1114 (10)
    //         004b9cd6     MOV        AL,byte ptr [ESP + param_5]
    //         004b9cda     DEC        AL
    //         004b9cdc     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:1115 (6)
    //         004b9ce0     JNZ        LAB_004b9db2
    //                               LAB_004b9ce6                                                 XREF[1]:     004b9dac(j)  
    //                              Shape.cpp:1117 (2)
    //         004b9ce6     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1118 (1)
    //         004b9ce8     INC        EDI
    //                              Shape.cpp:1119 (10)
    //         004b9ce9     MOV        this,AL
    //         004b9ceb     AND        this,0x1
    //         004b9cee     CMP        this,0x1
    //         004b9cf1     JNZ        LAB_004b9d5a
    //                              Shape.cpp:1121 (6)
    //         004b9cf3     SHR        AL,0x1
    //         004b9cf5     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1122 (2)
    //         004b9cf9     JNZ        LAB_004b9d19
    //                              Shape.cpp:1124 (6)
    //         004b9cfb     XOR        EAX,EAX
    //         004b9cfd     MOV        AL,byte ptr [EDI]
    //         004b9cff     ADD        EBP,EAX
    //                              Shape.cpp:1125 (2)
    //         004b9d01     ADD        ESI,EAX
    //                              Shape.cpp:1127 (13)
    //         004b9d03     MOV        EAX,dword ptr [ESP + param_6]
    //         004b9d07     INC        EDI
    //         004b9d08     CMP        EBP,EAX
    //         004b9d0a     JLE        LAB_004b9da6
    //                              Shape.cpp:1128 (4)
    //         004b9d10     MOV        byte ptr [ESP + param_5],this
    //                              Shape.cpp:1130 (5)
    //         004b9d14     JMP        LAB_004b9da6
    //                               LAB_004b9d19                                                 XREF[1]:     004b9cf9(j)  
    //                              Shape.cpp:1132 (4)
    //         004b9d19     MOV        EBX,dword ptr [ESP + param_1]
    //                              Shape.cpp:1133 (16)
    //         004b9d1d     MOV        EAX,dword ptr [ESP + param_6]
    //         004b9d21     AND        EBX,0xff
    //         004b9d27     ADD        EBP,EBX
    //         004b9d29     CMP        EBP,EAX
    //         004b9d2b     JLE        LAB_004b9d49
    //                              Shape.cpp:1137 (12)
    //         004b9d2d     SUB        EAX,EBP
    //         004b9d2f     MOV        byte ptr [ESP + param_5],0x1
    //         004b9d34     LEA        EDX,[EAX + EBX*0x1 + 0x1]
    //         004b9d38     PUSH       EDX
    //                              Shape.cpp:1140 (10)
    //         004b9d39     PUSH       EDI
    //         004b9d3a     PUSH       ESI
    //         004b9d3b     CALL       memcpy                                           undefined memcpy()
    //         004b9d40     ADD        ESP,0xc
    //                              Shape.cpp:1141 (2)
    //         004b9d43     ADD        ESI,EBX
    //                              Shape.cpp:1142 (2)
    //         004b9d45     ADD        EDI,EBX
    //                              Shape.cpp:1145 (2)
    //         004b9d47     JMP        LAB_004b9da2
    //                               LAB_004b9d49                                                 XREF[1]:     004b9d2b(j)  
    //                              Shape.cpp:1140 (11)
    //         004b9d49     PUSH       EBX
    //         004b9d4a     PUSH       EDI
    //         004b9d4b     PUSH       ESI
    //         004b9d4c     CALL       memcpy                                           undefined memcpy()
    //         004b9d51     ADD        ESP,0xc
    //                              Shape.cpp:1141 (2)
    //         004b9d54     ADD        ESI,EBX
    //                              Shape.cpp:1142 (2)
    //         004b9d56     ADD        EDI,EBX
    //                              Shape.cpp:1145 (2)
    //         004b9d58     JMP        LAB_004b9da2
    //                               LAB_004b9d5a                                                 XREF[1]:     004b9cf1(j)  
    //                              Shape.cpp:1147 (6)
    //         004b9d5a     SHR        AL,0x1
    //         004b9d5c     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1148 (2)
    //         004b9d60     JNZ        LAB_004b9d69
    //                              Shape.cpp:1149 (5)
    //         004b9d62     MOV        byte ptr [ESP + param_5],0x3
    //                              Shape.cpp:1150 (2)
    //         004b9d67     JMP        LAB_004b9da6
    //                               LAB_004b9d69                                                 XREF[1]:     004b9d60(j)  
    //                              Shape.cpp:1152 (4)
    //         004b9d69     MOV        EBX,dword ptr [ESP + param_1]
    //                              Shape.cpp:1153 (16)
    //         004b9d6d     MOV        EAX,dword ptr [ESP + param_6]
    //         004b9d71     AND        EBX,0xff
    //         004b9d77     ADD        EBP,EBX
    //         004b9d79     CMP        EBP,EAX
    //         004b9d7b     JLE        LAB_004b9d90
    //                              Shape.cpp:1157 (17)
    //         004b9d7d     SUB        EAX,EBP
    //         004b9d7f     XOR        this,this
    //         004b9d81     MOV        this,byte ptr [EDI]
    //         004b9d83     MOV        byte ptr [ESP + param_5],0x1
    //         004b9d88     LEA        EAX,[EAX + EBX*0x1 + 0x1]
    //         004b9d8c     PUSH       EAX
    //         004b9d8d     PUSH       this
    //                              Shape.cpp:1159 (2)
    //         004b9d8e     JMP        LAB_004b9d96
    //                               LAB_004b9d90                                                 XREF[1]:     004b9d7b(j)  
    //                              Shape.cpp:1160 (15)
    //         004b9d90     XOR        EDX,EDX
    //         004b9d92     PUSH       EBX
    //         004b9d93     MOV        DL,byte ptr [EDI]
    //         004b9d95     PUSH       EDX
    //                               LAB_004b9d96                                                 XREF[1]:     004b9d8e(j)  
    //         004b9d96     PUSH       ESI
    //         004b9d97     CALL       memset                                           undefined memset()
    //         004b9d9c     ADD        ESP,0xc
    //                              Shape.cpp:1161 (2)
    //         004b9d9f     ADD        ESI,EBX
    //                              Shape.cpp:1162 (5)
    //         004b9da1     INC        EDI
    //                               LAB_004b9da2                                                 XREF[2]:     004b9d47(j), 004b9d58(j)  
    //         004b9da2     MOV        EDX,dword ptr [ESP + param_4]
    //                               LAB_004b9da6                                                 XREF[3]:     004b9d0a(j), 004b9d14(j), 
    //                                                                                                         004b9d67(j)  
    //                              Shape.cpp:1115 (12)
    //         004b9da6     MOV        AL,byte ptr [ESP + param_5]
    //         004b9daa     TEST       AL,AL
    //         004b9dac     JZ         LAB_004b9ce6
    //                               LAB_004b9db2                                                 XREF[1]:     004b9ce0(j)  
    //                              Shape.cpp:1168 (10)
    //         004b9db2     MOV        AL,byte ptr [ESP + param_5]
    //         004b9db6     DEC        AL
    //         004b9db8     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:1169 (2)
    //         004b9dbc     JNZ        LAB_004b9df4
    //                               LAB_004b9dbe                                                 XREF[1]:     004b9df2(j)  
    //                              Shape.cpp:1171 (2)
    //         004b9dbe     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1172 (1)
    //         004b9dc0     INC        EDI
    //                              Shape.cpp:1173 (10)
    //         004b9dc1     MOV        this,AL
    //         004b9dc3     AND        this,0x1
    //         004b9dc6     CMP        this,0x1
    //         004b9dc9     JNZ        LAB_004b9de0
    //                              Shape.cpp:1175 (6)
    //         004b9dcb     SHR        AL,0x1
    //         004b9dcd     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1178 (2)
    //         004b9dd1     JZ         LAB_004b9deb
    //                              Shape.cpp:1179 (11)
    //         004b9dd3     MOV        EAX,dword ptr [ESP + param_1]
    //         004b9dd7     AND        EAX,0xff
    //         004b9ddc     ADD        EDI,EAX
    //                              Shape.cpp:1181 (2)
    //         004b9dde     JMP        LAB_004b9dec
    //                               LAB_004b9de0                                                 XREF[1]:     004b9dc9(j)  
    //                              Shape.cpp:1184 (4)
    //         004b9de0     TEST       AL,0xfe
    //         004b9de2     JNZ        LAB_004b9deb
    //                              Shape.cpp:1185 (5)
    //         004b9de4     MOV        byte ptr [ESP + param_5],0x2
    //                              Shape.cpp:1186 (2)
    //         004b9de9     JMP        LAB_004b9dec
    //                               LAB_004b9deb                                                 XREF[2]:     004b9dd1(j), 004b9de2(j)  
    //                              Shape.cpp:1187 (1)
    //         004b9deb     INC        EDI
    //                               LAB_004b9dec                                                 XREF[2]:     004b9dde(j), 004b9de9(j)  
    //                              Shape.cpp:1169 (8)
    //         004b9dec     MOV        AL,byte ptr [ESP + param_5]
    //         004b9df0     TEST       AL,AL
    //         004b9df2     JZ         LAB_004b9dbe
    //                               LAB_004b9df4                                                 XREF[1]:     004b9dbc(j)  
    //                              Shape.cpp:1192 (29)
    //         004b9df4     MOV        ESI,dword ptr [ESP + width]
    //         004b9df8     MOV        this,dword ptr [ESP + local_4]
    //         004b9dfc     MOV        EAX,dword ptr [ESP + param_7]
    //         004b9e00     ADD        ESI,this
    //         004b9e02     DEC        EAX
    //         004b9e03     MOV        dword ptr [ESP + width],ESI
    //         004b9e07     MOV        dword ptr [ESP + param_7],EAX
    //         004b9e0b     JNZ        LAB_004b9bb3
    //                               LAB_004b9e11                                                 XREF[1]:     004b9ba6(j)  
    //                              Shape.cpp:1197 (12)
    //         004b9e11     POP        EDI
    //         004b9e12     POP        ESI
    //         004b9e13     POP        EBP
    //         004b9e14     MOV        AL,0x1
    //         004b9e16     POP        EBX
    //         004b9e17     ADD        ESP,0x8
    //         004b9e1a     RET        0x1c
}

// Offset: 0x004B9E20
uchar shape_color_trans_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, uchar* param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_color_trans_clipped(class TDrawArea *,long,long,lo... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_color_trans_clipped(TShape * this, TDrawArea 
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[13]:    004b9e24(R), 004b9ea5(W), 004b9eab(R), 004b9f07(W), 
    //                                                                                     004b9f3c(R), 004b9fd6(W), 004b9fe3(R), 004ba063(W), 
    //                                                                                     004ba087(R), 004ba0f0(W), 004ba0fd(R), 004ba165(W), 
    //                                                                                     004ba16b(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004b9ee3(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004b9e7d(R), 004b9f6d(W), 004b9f94(R), 004ba0a5(W), 
    //                                                                                     004ba0c8(R)  
    //              long              Stack[0x10]:4  param_4
    //              long              Stack[0x14]:4  param_5                   XREF[7]:     004b9e5f(R), 004b9e73(R), 004b9f5b(R), 004b9f9a(R), 
    //                                                                                     004ba023(R), 004ba0c4(R), 004ba134(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[26]:    004b9e4b(R), 004b9e67(R), 004b9e8d(W), 004b9ec5(R), 
    //                                                                                     004b9eca(W), 004b9eef(W), 004b9f22(W), 004b9f2e(W), 
    //                                                                                     004b9f68(W), 004b9fa9(W), 004b9fdc(W), 004b9ffd(W), 
    //                                                                                     004ba007(W), 004ba02d(R), 004ba03b(W), 004ba040(R), 
    //                                                                                     004ba046(W), 004ba07e(W), 004ba09c(W), 004ba0f6(W)  
    //              long              Stack[0x1c]:4  param_7                   XREF[6]:     004b9f1c(R), 004b9f4f(R), 004b9ff3(R), 004ba071(R), 
    //                                                                                     004ba08b(R), 004ba101(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[4]:     004b9ed0(R), 004b9edf(W), 004ba194(R), 004ba19f(W)  
    //              uchar *           Stack[0x24]:4  param_9                   XREF[6]:     004b9f7c(R), 004b9fba(R), 004ba00e(R), 004ba0b0(R), 
    //                                                                                     004ba0d8(R), 004ba120(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b9e45(W), 004ba190(R)  
    //              long              Stack[-0x8]:4  width                     XREF[2]:     004b9f76(W), 004b9f8c(R)  
    //              uchar *           Stack[-0xc]:4  temp_buffer               XREF[3]:     004b9e81(W), 004ba18c(R), 004ba19b(W)  
    //              uchar *           Stack[-0x10]:4 save_buffer
    //                               ?shape_color_trans_clipped@TShape@@AAEEPAVTDrawArea@@JJJJJJ  XREF[1]:     shape_draw:004b979c(c)  
    //                               TShape::shape_color_trans_clipped
    //                              Shape.cpp:1201 (4)
    //         004b9e20     SUB        ESP,0xc
    //         004b9e23     PUSH       EBX
    //                              Shape.cpp:1202 (21)
    //         004b9e24     MOV        EBX,dword ptr [ESP + param_1]
    //         004b9e28     PUSH       EBP
    //         004b9e29     PUSH       ESI
    //         004b9e2a     MOV        ESI,dword ptr [EBX + 0x24]
    //         004b9e2d     PUSH       EDI
    //         004b9e2e     MOV        EDI,this
    //         004b9e30     MOV        this,EBX
    //         004b9e32     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004b9e37     MOV        this,EAX
    //                              Shape.cpp:1207 (9)
    //         004b9e39     MOV        EDI,dword ptr [EDI + 0xc]
    //         004b9e3c     IMUL       this,ESI
    //         004b9e3f     ADD        EDI,0x18
    //                              Shape.cpp:1214 (9)
    //         004b9e42     CMP        ESI,0x1
    //         004b9e45     MOV        dword ptr [ESP + local_4],this
    //         004b9e49     JGE        LAB_004b9e67
    //                              Shape.cpp:1215 (26)
    //         004b9e4b     MOV        EAX,dword ptr [ESP + param_6]
    //         004b9e4f     MOV        EDX,dword ptr [EBX + 0x1c]
    //         004b9e52     MOV        ESI,EAX
    //         004b9e54     SUB        ESI,EDX
    //         004b9e56     MOV        EDX,dword ptr [EBX + 0x8]
    //         004b9e59     INC        ESI
    //         004b9e5a     IMUL       ESI,this
    //         004b9e5d     ADD        ESI,EDX
    //         004b9e5f     MOV        EDX,dword ptr [ESP + param_5]
    //         004b9e63     ADD        ESI,EDX
    //                              Shape.cpp:1216 (2)
    //         004b9e65     JMP        LAB_004b9e7d
    //                               LAB_004b9e67                                                 XREF[1]:     004b9e49(j)  
    //                              Shape.cpp:1217 (22)
    //         004b9e67     MOV        EAX,dword ptr [ESP + param_6]
    //         004b9e6b     MOV        ESI,this
    //         004b9e6d     IMUL       ESI,EAX
    //         004b9e70     MOV        EDX,dword ptr [EBX + 0x8]
    //         004b9e73     MOV        this,dword ptr [ESP + param_5]
    //         004b9e77     ADD        ESI,EDX
    //         004b9e79     MOV        EDX,this
    //         004b9e7b     ADD        ESI,this
    //                               LAB_004b9e7d                                                 XREF[1]:     004b9e65(j)  
    //                              Shape.cpp:1221 (23)
    //         004b9e7d     MOV        this,dword ptr [ESP + param_3]
    //         004b9e81     MOV        dword ptr [ESP + temp_buffer],ESI
    //         004b9e85     CMP        this,EAX
    //         004b9e87     MOV        EBP,this
    //         004b9e89     JGE        LAB_004b9ed0
    //         004b9e8b     SUB        EAX,this
    //         004b9e8d     MOV        dword ptr [ESP + param_6],EAX
    //         004b9e91     LEA        EBP,[this->shape + EAX*0x1]
    //                               LAB_004b9e94                                                 XREF[1]:     004b9ece(j)  
    //                              Shape.cpp:1223 (2)
    //         004b9e94     XOR        this,this
    //                               LAB_004b9e96                                                 XREF[1]:     004b9ec3(j)  
    //                              Shape.cpp:1226 (2)
    //         004b9e96     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1227 (1)
    //         004b9e98     INC        EDI
    //                              Shape.cpp:1228 (10)
    //         004b9e99     MOV        BL,AL
    //         004b9e9b     AND        BL,0x1
    //         004b9e9e     CMP        BL,0x1
    //         004b9ea1     JNZ        LAB_004b9eb8
    //                              Shape.cpp:1230 (6)
    //         004b9ea3     SHR        AL,0x1
    //         004b9ea5     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1233 (2)
    //         004b9ea9     JZ         LAB_004b9ec0
    //                              Shape.cpp:1234 (11)
    //         004b9eab     MOV        EAX,dword ptr [ESP + param_1]
    //         004b9eaf     AND        EAX,0xff
    //         004b9eb4     ADD        EDI,EAX
    //                              Shape.cpp:1236 (2)
    //         004b9eb6     JMP        LAB_004b9ec1
    //                               LAB_004b9eb8                                                 XREF[1]:     004b9ea1(j)  
    //                              Shape.cpp:1239 (4)
    //         004b9eb8     TEST       AL,0xfe
    //         004b9eba     JNZ        LAB_004b9ec0
    //                              Shape.cpp:1240 (2)
    //         004b9ebc     MOV        this,0x1
    //                              Shape.cpp:1241 (2)
    //         004b9ebe     JMP        LAB_004b9ec1
    //                               LAB_004b9ec0                                                 XREF[2]:     004b9ea9(j), 004b9eba(j)  
    //                              Shape.cpp:1242 (1)
    //         004b9ec0     INC        EDI
    //                               LAB_004b9ec1                                                 XREF[2]:     004b9eb6(j), 004b9ebe(j)  
    //                              Shape.cpp:1224 (15)
    //         004b9ec1     TEST       this,this
    //         004b9ec3     JZ         LAB_004b9e96
    //         004b9ec5     MOV        EAX,dword ptr [ESP + param_6]
    //         004b9ec9     DEC        EAX
    //         004b9eca     MOV        dword ptr [ESP + param_6],EAX
    //         004b9ece     JNZ        LAB_004b9e94
    //                               LAB_004b9ed0                                                 XREF[1]:     004b9e89(j)  
    //                              Shape.cpp:1248 (19)
    //         004b9ed0     MOV        EAX,dword ptr [ESP + param_8]
    //         004b9ed4     CMP        EBP,EAX
    //         004b9ed6     JG         LAB_004ba1a9
    //         004b9edc     SUB        EAX,EBP
    //         004b9ede     INC        EAX
    //         004b9edf     MOV        dword ptr [ESP + param_8],EAX
    //                               LAB_004b9ee3                                                 XREF[1]:     004ba1a3(j)  
    //                              Shape.cpp:1250 (4)
    //         004b9ee3     MOV        EBP,dword ptr [ESP + param_2]
    //                              Shape.cpp:1253 (8)
    //         004b9ee7     CMP        EBP,EDX
    //         004b9ee9     JGE        LAB_004ba03b
    //                              Shape.cpp:1255 (5)
    //         004b9eef     MOV        byte ptr [ESP + param_6],0x0
    //                               LAB_004b9ef4                                                 XREF[1]:     004ba033(j)  
    //                              Shape.cpp:1258 (2)
    //         004b9ef4     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1259 (1)
    //         004b9ef6     INC        EDI
    //                              Shape.cpp:1260 (14)
    //         004b9ef7     MOV        this,AL
    //         004b9ef9     AND        this,0x1
    //         004b9efc     CMP        this,0x1
    //         004b9eff     JNZ        LAB_004b9fd4
    //                              Shape.cpp:1262 (6)
    //         004b9f05     SHR        AL,0x1
    //         004b9f07     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1263 (2)
    //         004b9f0b     JNZ        LAB_004b9f3c
    //                              Shape.cpp:1265 (6)
    //         004b9f0d     XOR        EAX,EAX
    //         004b9f0f     MOV        AL,byte ptr [EDI]
    //         004b9f11     ADD        EBP,EAX
    //                              Shape.cpp:1266 (1)
    //         004b9f13     INC        EDI
    //                              Shape.cpp:1267 (8)
    //         004b9f14     CMP        EBP,EDX
    //         004b9f16     JL         LAB_004ba02d
    //                              Shape.cpp:1269 (6)
    //         004b9f1c     CMP        EBP,dword ptr [ESP + param_7]
    //         004b9f20     JLE        LAB_004b9f2c
    //                              Shape.cpp:1270 (5)
    //         004b9f22     MOV        byte ptr [ESP + param_6],0x2
    //                              Shape.cpp:1271 (5)
    //         004b9f27     JMP        LAB_004ba02d
    //                               LAB_004b9f2c                                                 XREF[1]:     004b9f20(j)  
    //                              Shape.cpp:1274 (11)
    //         004b9f2c     MOV        this,EBP
    //         004b9f2e     MOV        byte ptr [ESP + param_6],0x1
    //         004b9f33     SUB        this,EDX
    //         004b9f35     ADD        ESI,this
    //                              Shape.cpp:1278 (5)
    //         004b9f37     JMP        LAB_004ba02d
    //                               LAB_004b9f3c                                                 XREF[1]:     004b9f0b(j)  
    //                              Shape.cpp:1280 (11)
    //         004b9f3c     MOV        EAX,dword ptr [ESP + param_1]
    //         004b9f40     AND        EAX,0xff
    //         004b9f45     ADD        EBP,EAX
    //                              Shape.cpp:1281 (8)
    //         004b9f47     CMP        EBP,EDX
    //         004b9f49     JL         LAB_004b9fd0
    //                              Shape.cpp:1283 (8)
    //         004b9f4f     MOV        EBX,dword ptr [ESP + param_7]
    //         004b9f53     CMP        EBP,EBX
    //         004b9f55     JLE        LAB_004b9fa7
    //                              Shape.cpp:1287 (2)
    //         004b9f57     MOV        this,EDX
    //                              Shape.cpp:1288 (13)
    //         004b9f59     MOV        EDX,EBX
    //         004b9f5b     MOV        EBX,dword ptr [ESP + param_5]
    //         004b9f5f     SUB        this,EBP
    //         004b9f61     SUB        EDX,EBX
    //         004b9f63     ADD        this,EAX
    //         004b9f65     INC        EDX
    //                              Shape.cpp:1291 (11)
    //         004b9f66     ADD        EDI,this
    //         004b9f68     MOV        byte ptr [ESP + param_6],0x2
    //         004b9f6d     MOV        dword ptr [ESP + param_3],EDX
    //                              Shape.cpp:1292 (11)
    //         004b9f71     LEA        EBX,[ESI + EDX*0x1]
    //         004b9f74     CMP        ESI,EBX
    //         004b9f76     MOV        dword ptr [ESP + width],EBX
    //         004b9f7a     JNC        LAB_004b9f98
    //                               LAB_004b9f7c                                                 XREF[1]:     004b9f92(j)  
    //                              Shape.cpp:1294 (8)
    //         004b9f7c     MOV        EBX,dword ptr [ESP + param_9]
    //         004b9f80     XOR        EDX,EDX
    //         004b9f82     MOV        DL,byte ptr [EDI]
    //                              Shape.cpp:1295 (16)
    //         004b9f84     INC        EDI
    //         004b9f85     INC        ESI
    //         004b9f86     MOV        DL,byte ptr [EDX + EBX*0x1]
    //         004b9f89     MOV        byte ptr [ESI + -0x1],DL
    //         004b9f8c     MOV        EDX,dword ptr [ESP + width]
    //         004b9f90     CMP        ESI,EDX
    //         004b9f92     JC         LAB_004b9f7c
    //                              Shape.cpp:1292 (4)
    //         004b9f94     MOV        EDX,dword ptr [ESP + param_3]
    //                               LAB_004b9f98                                                 XREF[1]:     004b9f7a(j)  
    //                              Shape.cpp:1297 (2)
    //         004b9f98     SUB        EAX,EDX
    //                              Shape.cpp:1299 (13)
    //         004b9f9a     MOV        EDX,dword ptr [ESP + param_5]
    //         004b9f9e     SUB        EAX,this
    //         004b9fa0     ADD        EDI,EAX
    //         004b9fa2     JMP        LAB_004ba02d
    //                               LAB_004b9fa7                                                 XREF[1]:     004b9f55(j)  
    //                              Shape.cpp:1302 (9)
    //         004b9fa7     MOV        this,EBP
    //         004b9fa9     MOV        byte ptr [ESP + param_6],0x1
    //         004b9fae     SUB        this,EDX
    //                              Shape.cpp:1303 (2)
    //         004b9fb0     SUB        EAX,this
    //                              Shape.cpp:1307 (8)
    //         004b9fb2     ADD        this,ESI
    //         004b9fb4     ADD        EDI,EAX
    //         004b9fb6     CMP        ESI,this
    //         004b9fb8     JNC        LAB_004ba02d
    //                               LAB_004b9fba                                                 XREF[1]:     004b9fcc(j)  
    //                              Shape.cpp:1309 (8)
    //         004b9fba     MOV        EBX,dword ptr [ESP + param_9]
    //         004b9fbe     XOR        EAX,EAX
    //         004b9fc0     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1310 (12)
    //         004b9fc2     INC        EDI
    //         004b9fc3     INC        ESI
    //         004b9fc4     MOV        AL,byte ptr [EAX + EBX*0x1]
    //         004b9fc7     CMP        ESI,this
    //         004b9fc9     MOV        byte ptr [ESI + -0x1],AL
    //         004b9fcc     JC         LAB_004b9fba
    //                              Shape.cpp:1314 (2)
    //         004b9fce     JMP        LAB_004ba02d
    //                               LAB_004b9fd0                                                 XREF[1]:     004b9f49(j)  
    //                              Shape.cpp:1315 (2)
    //         004b9fd0     ADD        EDI,EAX
    //                              Shape.cpp:1318 (2)
    //         004b9fd2     JMP        LAB_004ba02d
    //                               LAB_004b9fd4                                                 XREF[1]:     004b9eff(j)  
    //                              Shape.cpp:1320 (6)
    //         004b9fd4     SHR        AL,0x1
    //         004b9fd6     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1321 (2)
    //         004b9fda     JNZ        LAB_004b9fe3
    //                              Shape.cpp:1322 (5)
    //         004b9fdc     MOV        byte ptr [ESP + param_6],0x3
    //                              Shape.cpp:1323 (2)
    //         004b9fe1     JMP        LAB_004ba02d
    //                               LAB_004b9fe3                                                 XREF[1]:     004b9fda(j)  
    //                              Shape.cpp:1325 (12)
    //         004b9fe3     MOV        this,dword ptr [ESP + param_1]
    //         004b9fe7     AND        this,0xff
    //         004b9fed     ADD        EBP,this
    //                              Shape.cpp:1326 (4)
    //         004b9fef     CMP        EBP,EDX
    //         004b9ff1     JL         LAB_004ba02c
    //                              Shape.cpp:1328 (8)
    //         004b9ff3     MOV        EBX,dword ptr [ESP + param_7]
    //         004b9ff7     CMP        EBP,EBX
    //         004b9ff9     JLE        LAB_004ba005
    //                              Shape.cpp:1331 (8)
    //         004b9ffb     SUB        EBX,EDX
    //         004b9ffd     MOV        byte ptr [ESP + param_6],0x2
    //         004ba002     INC        EBX
    //                              Shape.cpp:1335 (2)
    //         004ba003     JMP        LAB_004ba00e
    //                               LAB_004ba005                                                 XREF[1]:     004b9ff9(j)  
    //                              Shape.cpp:1338 (9)
    //         004ba005     MOV        EBX,EBP
    //         004ba007     MOV        byte ptr [ESP + param_6],0x1
    //         004ba00c     SUB        EBX,EDX
    //                               LAB_004ba00e                                                 XREF[1]:     004ba003(j)  
    //                              Shape.cpp:1339 (21)
    //         004ba00e     MOV        this,dword ptr [ESP + param_9]
    //         004ba012     XOR        EDX,EDX
    //         004ba014     MOV        DL,byte ptr [EDI]
    //         004ba016     XOR        EAX,EAX
    //         004ba018     PUSH       EBX
    //         004ba019     MOV        AL,byte ptr [EDX + this->shape*0x1]
    //         004ba01c     PUSH       EAX
    //         004ba01d     PUSH       ESI
    //         004ba01e     CALL       memset                                           undefined memset()
    //                              Shape.cpp:1340 (9)
    //         004ba023     MOV        EDX,dword ptr [ESP + param_5]
    //         004ba027     ADD        ESP,0xc
    //         004ba02a     ADD        ESI,EBX
    //                               LAB_004ba02c                                                 XREF[1]:     004b9ff1(j)  
    //                              Shape.cpp:1343 (1)
    //         004ba02c     INC        EDI
    //                               LAB_004ba02d                                                 XREF[8]:     004b9f16(j), 004b9f27(j), 
    //                                                                                                         004b9f37(j), 004b9fa2(j), 
    //                                                                                                         004b9fb8(j), 004b9fce(j), 
    //                                                                                                         004b9fd2(j), 004b9fe1(j)  
    //                              Shape.cpp:1256 (12)
    //         004ba02d     MOV        AL,byte ptr [ESP + param_6]
    //         004ba031     TEST       AL,AL
    //         004ba033     JZ         LAB_004b9ef4
    //                              Shape.cpp:1348 (2)
    //         004ba039     JMP        LAB_004ba040
    //                               LAB_004ba03b                                                 XREF[1]:     004b9ee9(j)  
    //                              Shape.cpp:1349 (5)
    //         004ba03b     MOV        byte ptr [ESP + param_6],0x1
    //                               LAB_004ba040                                                 XREF[1]:     004ba039(j)  
    //                              Shape.cpp:1352 (10)
    //         004ba040     MOV        AL,byte ptr [ESP + param_6]
    //         004ba044     DEC        AL
    //         004ba046     MOV        byte ptr [ESP + param_6],AL
    //                              Shape.cpp:1353 (6)
    //         004ba04a     JNZ        LAB_004ba14a
    //                               LAB_004ba050                                                 XREF[1]:     004ba144(j)  
    //                              Shape.cpp:1355 (2)
    //         004ba050     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1356 (1)
    //         004ba052     INC        EDI
    //                              Shape.cpp:1357 (14)
    //         004ba053     MOV        this,AL
    //         004ba055     AND        this,0x1
    //         004ba058     CMP        this,0x1
    //         004ba05b     JNZ        LAB_004ba0ee
    //                              Shape.cpp:1359 (6)
    //         004ba061     SHR        AL,0x1
    //         004ba063     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1360 (2)
    //         004ba067     JNZ        LAB_004ba087
    //                              Shape.cpp:1362 (6)
    //         004ba069     XOR        EAX,EAX
    //         004ba06b     MOV        AL,byte ptr [EDI]
    //         004ba06d     ADD        EBP,EAX
    //                              Shape.cpp:1363 (2)
    //         004ba06f     ADD        ESI,EAX
    //                              Shape.cpp:1365 (13)
    //         004ba071     MOV        EAX,dword ptr [ESP + param_7]
    //         004ba075     INC        EDI
    //         004ba076     CMP        EBP,EAX
    //         004ba078     JLE        LAB_004ba13e
    //                              Shape.cpp:1366 (4)
    //         004ba07e     MOV        byte ptr [ESP + param_6],this
    //                              Shape.cpp:1368 (5)
    //         004ba082     JMP        LAB_004ba13e
    //                               LAB_004ba087                                                 XREF[1]:     004ba067(j)  
    //                              Shape.cpp:1370 (4)
    //         004ba087     MOV        EAX,dword ptr [ESP + param_1]
    //                              Shape.cpp:1371 (15)
    //         004ba08b     MOV        this,dword ptr [ESP + param_7]
    //         004ba08f     AND        EAX,0xff
    //         004ba094     ADD        EBP,EAX
    //         004ba096     CMP        EBP,this
    //         004ba098     JLE        LAB_004ba0d2
    //                              Shape.cpp:1374 (15)
    //         004ba09a     SUB        this,EBP
    //         004ba09c     MOV        byte ptr [ESP + param_6],0x1
    //         004ba0a1     LEA        EBX,[ECX + EAX*this+0x1 + 0x1]
    //         004ba0a5     MOV        dword ptr [ESP + param_3],EBX
    //                              Shape.cpp:1375 (7)
    //         004ba0a9     LEA        this,[ESI + EBX*0x1]
    //         004ba0ac     CMP        ESI,this
    //         004ba0ae     JNC        LAB_004ba0cc
    //                               LAB_004ba0b0                                                 XREF[1]:     004ba0c2(j)  
    //                              Shape.cpp:1377 (8)
    //         004ba0b0     MOV        EBX,dword ptr [ESP + param_9]
    //         004ba0b4     XOR        EDX,EDX
    //         004ba0b6     MOV        DL,byte ptr [EDI]
    //                              Shape.cpp:1378 (20)
    //         004ba0b8     INC        EDI
    //         004ba0b9     INC        ESI
    //         004ba0ba     MOV        DL,byte ptr [EDX + EBX*0x1]
    //         004ba0bd     CMP        ESI,this
    //         004ba0bf     MOV        byte ptr [ESI + -0x1],DL
    //         004ba0c2     JC         LAB_004ba0b0
    //         004ba0c4     MOV        EDX,dword ptr [ESP + param_5]
    //         004ba0c8     MOV        EBX,dword ptr [ESP + param_3]
    //                               LAB_004ba0cc                                                 XREF[1]:     004ba0ae(j)  
    //                              Shape.cpp:1380 (4)
    //         004ba0cc     SUB        EAX,EBX
    //         004ba0ce     ADD        EDI,EAX
    //                              Shape.cpp:1382 (2)
    //         004ba0d0     JMP        LAB_004ba13e
    //                               LAB_004ba0d2                                                 XREF[1]:     004ba098(j)  
    //                              Shape.cpp:1384 (6)
    //         004ba0d2     ADD        EAX,ESI
    //         004ba0d4     CMP        ESI,EAX
    //         004ba0d6     JNC        LAB_004ba13e
    //                               LAB_004ba0d8                                                 XREF[1]:     004ba0ea(j)  
    //                              Shape.cpp:1386 (8)
    //         004ba0d8     MOV        EBX,dword ptr [ESP + param_9]
    //         004ba0dc     XOR        this,this
    //         004ba0de     MOV        this,byte ptr [EDI]
    //                              Shape.cpp:1387 (12)
    //         004ba0e0     INC        EDI
    //         004ba0e1     INC        ESI
    //         004ba0e2     MOV        this,byte ptr [this->shape + EBX*0x1]
    //         004ba0e5     CMP        ESI,EAX
    //         004ba0e7     MOV        byte ptr [ESI + -0x1],this
    //         004ba0ea     JC         LAB_004ba0d8
    //                              Shape.cpp:1392 (2)
    //         004ba0ec     JMP        LAB_004ba13e
    //                               LAB_004ba0ee                                                 XREF[1]:     004ba05b(j)  
    //                              Shape.cpp:1394 (6)
    //         004ba0ee     SHR        AL,0x1
    //         004ba0f0     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1395 (2)
    //         004ba0f4     JNZ        LAB_004ba0fd
    //                              Shape.cpp:1396 (5)
    //         004ba0f6     MOV        byte ptr [ESP + param_6],0x3
    //                              Shape.cpp:1397 (2)
    //         004ba0fb     JMP        LAB_004ba13e
    //                               LAB_004ba0fd                                                 XREF[1]:     004ba0f4(j)  
    //                              Shape.cpp:1399 (4)
    //         004ba0fd     MOV        EBX,dword ptr [ESP + param_1]
    //                              Shape.cpp:1400 (16)
    //         004ba101     MOV        EAX,dword ptr [ESP + param_7]
    //         004ba105     AND        EBX,0xff
    //         004ba10b     ADD        EBP,EBX
    //         004ba10d     CMP        EBP,EAX
    //         004ba10f     JLE        LAB_004ba11f
    //                              Shape.cpp:1404 (12)
    //         004ba111     SUB        EAX,EBP
    //         004ba113     MOV        byte ptr [ESP + param_6],0x1
    //         004ba118     LEA        EDX,[EAX + EBX*0x1 + 0x1]
    //         004ba11c     PUSH       EDX
    //                              Shape.cpp:1406 (2)
    //         004ba11d     JMP        LAB_004ba120
    //                               LAB_004ba11f                                                 XREF[1]:     004ba10f(j)  
    //                              Shape.cpp:1407 (21)
    //         004ba11f     PUSH       EBX
    //                               LAB_004ba120                                                 XREF[1]:     004ba11d(j)  
    //         004ba120     MOV        EDX,dword ptr [ESP + param_9]
    //         004ba124     XOR        EAX,EAX
    //         004ba126     MOV        AL,byte ptr [EDI]
    //         004ba128     XOR        this,this
    //         004ba12a     MOV        this,byte ptr [EAX + EDX*0x1]
    //         004ba12d     PUSH       this
    //         004ba12e     PUSH       ESI
    //         004ba12f     CALL       memset                                           undefined memset()
    //                              Shape.cpp:1409 (22)
    //         004ba134     MOV        EDX,dword ptr [ESP + param_5]
    //         004ba138     ADD        ESP,0xc
    //         004ba13b     ADD        ESI,EBX
    //         004ba13d     INC        EDI
    //                               LAB_004ba13e                                                 XREF[6]:     004ba078(j), 004ba082(j), 
    //                                                                                                         004ba0d0(j), 004ba0d6(j), 
    //                                                                                                         004ba0ec(j), 004ba0fb(j)  
    //         004ba13e     MOV        AL,byte ptr [ESP + param_6]
    //         004ba142     TEST       AL,AL
    //         004ba144     JZ         LAB_004ba050
    //                               LAB_004ba14a                                                 XREF[1]:     004ba04a(j)  
    //                              Shape.cpp:1415 (10)
    //         004ba14a     MOV        AL,byte ptr [ESP + param_6]
    //         004ba14e     DEC        AL
    //         004ba150     MOV        byte ptr [ESP + param_6],AL
    //                              Shape.cpp:1416 (2)
    //         004ba154     JNZ        LAB_004ba18c
    //                               LAB_004ba156                                                 XREF[1]:     004ba18a(j)  
    //                              Shape.cpp:1418 (2)
    //         004ba156     MOV        AL,byte ptr [EDI]
    //                              Shape.cpp:1419 (1)
    //         004ba158     INC        EDI
    //                              Shape.cpp:1420 (10)
    //         004ba159     MOV        this,AL
    //         004ba15b     AND        this,0x1
    //         004ba15e     CMP        this,0x1
    //         004ba161     JNZ        LAB_004ba178
    //                              Shape.cpp:1422 (6)
    //         004ba163     SHR        AL,0x1
    //         004ba165     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:1425 (2)
    //         004ba169     JZ         LAB_004ba183
    //                              Shape.cpp:1426 (11)
    //         004ba16b     MOV        EAX,dword ptr [ESP + param_1]
    //         004ba16f     AND        EAX,0xff
    //         004ba174     ADD        EDI,EAX
    //                              Shape.cpp:1428 (2)
    //         004ba176     JMP        LAB_004ba184
    //                               LAB_004ba178                                                 XREF[1]:     004ba161(j)  
    //                              Shape.cpp:1431 (4)
    //         004ba178     TEST       AL,0xfe
    //         004ba17a     JNZ        LAB_004ba183
    //                              Shape.cpp:1432 (5)
    //         004ba17c     MOV        byte ptr [ESP + param_6],0x2
    //                              Shape.cpp:1433 (2)
    //         004ba181     JMP        LAB_004ba184
    //                               LAB_004ba183                                                 XREF[2]:     004ba169(j), 004ba17a(j)  
    //                              Shape.cpp:1434 (1)
    //         004ba183     INC        EDI
    //                               LAB_004ba184                                                 XREF[2]:     004ba176(j), 004ba181(j)  
    //                              Shape.cpp:1416 (8)
    //         004ba184     MOV        AL,byte ptr [ESP + param_6]
    //         004ba188     TEST       AL,AL
    //         004ba18a     JZ         LAB_004ba156
    //                               LAB_004ba18c                                                 XREF[1]:     004ba154(j)  
    //                              Shape.cpp:1439 (29)
    //         004ba18c     MOV        ESI,dword ptr [ESP + temp_buffer]
    //         004ba190     MOV        this,dword ptr [ESP + local_4]
    //         004ba194     MOV        EAX,dword ptr [ESP + param_8]
    //         004ba198     ADD        ESI,this
    //         004ba19a     DEC        EAX
    //         004ba19b     MOV        dword ptr [ESP + temp_buffer],ESI
    //         004ba19f     MOV        dword ptr [ESP + param_8],EAX
    //         004ba1a3     JNZ        LAB_004b9ee3
    //                               LAB_004ba1a9                                                 XREF[1]:     004b9ed6(j)  
    //                              Shape.cpp:1444 (12)
    //         004ba1a9     POP        EDI
    //         004ba1aa     POP        ESI
    //         004ba1ab     POP        EBP
    //         004ba1ac     MOV        AL,0x1
    //         004ba1ae     POP        EBX
    //         004ba1af     ADD        ESP,0xc
    //         004ba1b2     RET        0x24
}

// Offset: 0x004BA1C0
uchar shape_shadow_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_shadow_clipped(class TDrawArea *,long,long,long,lo... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_shadow_clipped(TShape * this, TDrawArea * par
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[25]:    004ba1c6(R), 004ba1e9(W), 004ba22d(R), 004ba234(W), 
    //                                                                                     004ba24e(R), 004ba259(W), 004ba267(RW), 004ba26f(R), 
    //                                                                                     004ba2a1(R), 004ba2b4(W), 004ba2cd(W), 004ba32d(R), 
    //                                                                                     004ba352(R), 004ba3b8(R), 004ba3bd(W), 004ba3c1(R), 
    //                                                                                     004ba3db(R), 004ba3ee(W), 004ba413(W), 004ba457(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004ba28d(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     004ba214(R), 004ba289(W), 004ba529(R), 004ba534(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[5]:     004ba20c(R), 004ba291(R), 004ba2d1(R), 004ba2fb(R), 
    //                                                                                     004ba36a(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[18]:    004ba1ef(R), 004ba200(R), 004ba244(W), 004ba24a(R), 
    //                                                                                     004ba2a5(W), 004ba2b0(R), 004ba2c0(W), 004ba2f7(R), 
    //                                                                                     004ba35c(W), 004ba366(R), 004ba3df(W), 004ba3ea(R), 
    //                                                                                     004ba3fa(W), 004ba424(R), 004ba47f(W), 004ba489(R), 
    //                                                                                     004ba4fb(W), 004ba501(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[6]:     004ba2dd(R), 004ba30b(R), 004ba37a(R), 004ba40c(R), 
    //                                                                                     004ba428(R), 004ba48d(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     004ba276(R)  
    //              uchar *           Stack[0x20]:4  param_8                   XREF[1]:     004ba282(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ba1e5(W), 004ba525(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004ba21a(W), 004ba521(R), 004ba530(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer
    //                               ?shape_shadow_clipped@TShape@@AAEEPAVTDrawArea@@JJJJJJPAE@Z  XREF[1]:     shape_draw:004b976e(c)  
    //                               TShape::shape_shadow_clipped
    //                              Shape.cpp:1448 (6)
    //         004ba1c0     SUB        ESP,0x8
    //         004ba1c3     PUSH       EBX
    //         004ba1c4     PUSH       EBP
    //         004ba1c5     PUSH       ESI
    //                              Shape.cpp:1449 (19)
    //         004ba1c6     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba1ca     MOV        EBX,this
    //         004ba1cc     PUSH       EDI
    //         004ba1cd     MOV        EDI,dword ptr [ESI + 0x24]
    //         004ba1d0     MOV        this,ESI
    //         004ba1d2     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004ba1d7     MOV        EDX,EAX
    //                              Shape.cpp:1453 (9)
    //         004ba1d9     MOV        EBX,dword ptr [EBX + 0xc]
    //         004ba1dc     IMUL       EDX,EDI
    //         004ba1df     ADD        EBX,0x18
    //                              Shape.cpp:1460 (13)
    //         004ba1e2     CMP        EDI,0x1
    //         004ba1e5     MOV        dword ptr [ESP + local_4],EDX
    //         004ba1e9     MOV        dword ptr [ESP + param_1],EBX
    //         004ba1ed     JGE        LAB_004ba200
    //                              Shape.cpp:1461 (15)
    //         004ba1ef     MOV        EAX,dword ptr [ESP + param_5]
    //         004ba1f3     MOV        EDI,dword ptr [ESI + 0x1c]
    //         004ba1f6     MOV        this,EAX
    //         004ba1f8     SUB        this,EDI
    //         004ba1fa     INC        this
    //         004ba1fb     IMUL       this,EDX
    //                              Shape.cpp:1462 (2)
    //         004ba1fe     JMP        LAB_004ba209
    //                               LAB_004ba200                                                 XREF[1]:     004ba1ed(j)  
    //                              Shape.cpp:1463 (20)
    //         004ba200     MOV        EAX,dword ptr [ESP + param_5]
    //         004ba204     MOV        this,EDX
    //         004ba206     IMUL       this,EAX
    //                               LAB_004ba209                                                 XREF[1]:     004ba1fe(j)  
    //         004ba209     MOV        EDI,dword ptr [ESI + 0x8]
    //         004ba20c     MOV        EDX,dword ptr [ESP + param_4]
    //         004ba210     ADD        this,EDI
    //         004ba212     ADD        this,EDX
    //                              Shape.cpp:1467 (21)
    //         004ba214     MOV        EDX,dword ptr [ESP + param_3]
    //         004ba218     CMP        EDX,EAX
    //         004ba21a     MOV        dword ptr [ESP + width],this
    //         004ba21e     MOV        ESI,EDX
    //         004ba220     JGE        LAB_004ba276
    //         004ba222     SUB        EAX,EDX
    //         004ba224     MOV        EDI,EAX
    //         004ba226     LEA        ESI,[EDX + EDI*0x1]
    //                               LAB_004ba229                                                 XREF[1]:     004ba274(j)  
    //                              Shape.cpp:1469 (8)
    //         004ba229     XOR        DL,DL
    //         004ba22b     JMP        LAB_004ba231
    //                               LAB_004ba22d                                                 XREF[1]:     004ba26d(j)  
    //         004ba22d     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_004ba231                                                 XREF[1]:     004ba22b(j)  
    //                              Shape.cpp:1472 (2)
    //         004ba231     MOV        AL,byte ptr [EBX]
    //                              Shape.cpp:1473 (5)
    //         004ba233     INC        EBX
    //         004ba234     MOV        dword ptr [ESP + param_1],EBX
    //                              Shape.cpp:1474 (10)
    //         004ba238     MOV        BL,AL
    //         004ba23a     AND        BL,0x1
    //         004ba23d     CMP        BL,0x1
    //         004ba240     JNZ        LAB_004ba25f
    //                              Shape.cpp:1476 (6)
    //         004ba242     SHR        AL,0x1
    //         004ba244     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:1479 (2)
    //         004ba248     JZ         LAB_004ba267
    //                              Shape.cpp:1480 (19)
    //         004ba24a     MOV        EAX,dword ptr [ESP + param_5]
    //         004ba24e     MOV        EBX,dword ptr [ESP + param_1]
    //         004ba252     AND        EAX,0xff
    //         004ba257     ADD        EBX,EAX
    //         004ba259     MOV        dword ptr [ESP + param_1],EBX
    //                              Shape.cpp:1482 (2)
    //         004ba25d     JMP        LAB_004ba26b
    //                               LAB_004ba25f                                                 XREF[1]:     004ba240(j)  
    //                              Shape.cpp:1485 (4)
    //         004ba25f     TEST       AL,0xfe
    //         004ba261     JNZ        LAB_004ba267
    //                              Shape.cpp:1486 (2)
    //         004ba263     MOV        DL,0x1
    //                              Shape.cpp:1487 (2)
    //         004ba265     JMP        LAB_004ba26b
    //                               LAB_004ba267                                                 XREF[2]:     004ba248(j), 004ba261(j)  
    //                              Shape.cpp:1488 (4)
    //         004ba267     INC        dword ptr [ESP + param_1]
    //                               LAB_004ba26b                                                 XREF[2]:     004ba25d(j), 004ba265(j)  
    //                              Shape.cpp:1470 (11)
    //         004ba26b     TEST       DL,DL
    //         004ba26d     JZ         LAB_004ba22d
    //         004ba26f     MOV        EBX,dword ptr [ESP + param_1]
    //         004ba273     DEC        EDI
    //         004ba274     JNZ        LAB_004ba229
    //                               LAB_004ba276                                                 XREF[1]:     004ba220(j)  
    //                              Shape.cpp:1494 (23)
    //         004ba276     MOV        EAX,dword ptr [ESP + param_7]
    //         004ba27a     CMP        ESI,EAX
    //         004ba27c     JG         LAB_004ba53e
    //         004ba282     MOV        EBP,dword ptr [ESP + param_8]
    //         004ba286     SUB        EAX,ESI
    //         004ba288     INC        EAX
    //         004ba289     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_004ba28d                                                 XREF[1]:     004ba538(j)  
    //                              Shape.cpp:1496 (4)
    //         004ba28d     MOV        EDX,dword ptr [ESP + param_2]
    //                              Shape.cpp:1499 (12)
    //         004ba291     MOV        EAX,dword ptr [ESP + param_4]
    //         004ba295     CMP        EDX,EAX
    //         004ba297     JGE        LAB_004ba3cf
    //                              Shape.cpp:1501 (2)
    //         004ba29d     XOR        AL,AL
    //                               LAB_004ba29f                                                 XREF[1]:     004ba3c7(j)  
    //                              Shape.cpp:1504 (2)
    //         004ba29f     MOV        BL,byte ptr [EBX]
    //                              Shape.cpp:1505 (8)
    //         004ba2a1     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba2a5     MOV        byte ptr [ESP + param_5],BL
    //                              Shape.cpp:1506 (7)
    //         004ba2a9     AND        BL,0x1
    //         004ba2ac     INC        ESI
    //         004ba2ad     CMP        BL,0x1
    //                              Shape.cpp:1508 (20)
    //         004ba2b0     MOV        BL,byte ptr [ESP + param_5]
    //         004ba2b4     MOV        dword ptr [ESP + param_1],ESI
    //         004ba2b8     JNZ        LAB_004ba35a
    //         004ba2be     SHR        BL,0x1
    //         004ba2c0     MOV        byte ptr [ESP + param_5],BL
    //                              Shape.cpp:1509 (2)
    //         004ba2c4     JNZ        LAB_004ba2f7
    //                              Shape.cpp:1511 (6)
    //         004ba2c6     XOR        EBX,EBX
    //         004ba2c8     MOV        BL,byte ptr [ESI]
    //         004ba2ca     ADD        EDX,EBX
    //                              Shape.cpp:1512 (5)
    //         004ba2cc     INC        ESI
    //         004ba2cd     MOV        dword ptr [ESP + param_1],ESI
    //                              Shape.cpp:1513 (12)
    //         004ba2d1     MOV        ESI,dword ptr [ESP + param_4]
    //         004ba2d5     CMP        EDX,ESI
    //         004ba2d7     JL         LAB_004ba3c1
    //                              Shape.cpp:1515 (6)
    //         004ba2dd     CMP        EDX,dword ptr [ESP + param_6]
    //         004ba2e1     JLE        LAB_004ba2ea
    //                              Shape.cpp:1516 (2)
    //         004ba2e3     MOV        AL,0x2
    //                              Shape.cpp:1517 (5)
    //         004ba2e5     JMP        LAB_004ba3c1
    //                               LAB_004ba2ea                                                 XREF[1]:     004ba2e1(j)  
    //                              Shape.cpp:1520 (8)
    //         004ba2ea     MOV        EDI,EDX
    //         004ba2ec     MOV        AL,0x1
    //         004ba2ee     SUB        EDI,ESI
    //         004ba2f0     ADD        this,EDI
    //                              Shape.cpp:1524 (5)
    //         004ba2f2     JMP        LAB_004ba3c1
    //                               LAB_004ba2f7                                                 XREF[1]:     004ba2c4(j)  
    //                              Shape.cpp:1526 (4)
    //         004ba2f7     MOV        EDI,dword ptr [ESP + param_5]
    //                              Shape.cpp:1527 (16)
    //         004ba2fb     MOV        EBX,dword ptr [ESP + param_4]
    //         004ba2ff     AND        EDI,0xff
    //         004ba305     ADD        EDX,EDI
    //         004ba307     CMP        EDX,EBX
    //         004ba309     JL         LAB_004ba352
    //                              Shape.cpp:1529 (8)
    //         004ba30b     MOV        ESI,dword ptr [ESP + param_6]
    //         004ba30f     CMP        EDX,ESI
    //         004ba311     JLE        LAB_004ba338
    //                              Shape.cpp:1533 (11)
    //         004ba313     ADD        ESI,this
    //         004ba315     MOV        AL,0x2
    //         004ba317     SUB        ESI,EBX
    //         004ba319     INC        ESI
    //         004ba31a     CMP        this,ESI
    //         004ba31c     JNC        LAB_004ba352
    //                               LAB_004ba31e                                                 XREF[1]:     004ba32b(j)  
    //                              Shape.cpp:1534 (15)
    //         004ba31e     XOR        EBX,EBX
    //         004ba320     MOV        BL,byte ptr [this->shape]
    //         004ba322     INC        this
    //         004ba323     CMP        this,ESI
    //         004ba325     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba328     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba32b     JC         LAB_004ba31e
    //                              Shape.cpp:1544 (6)
    //         004ba32d     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba331     ADD        ESI,EDI
    //                              Shape.cpp:1547 (5)
    //         004ba333     JMP        LAB_004ba3bd
    //                               LAB_004ba338                                                 XREF[1]:     004ba311(j)  
    //                              Shape.cpp:1540 (11)
    //         004ba338     LEA        ESI,[this->shape + EDX*0x1]
    //         004ba33b     MOV        AL,0x1
    //         004ba33d     SUB        ESI,EBX
    //         004ba33f     CMP        this,ESI
    //         004ba341     JNC        LAB_004ba352
    //                               LAB_004ba343                                                 XREF[1]:     004ba350(j)  
    //                              Shape.cpp:1541 (15)
    //         004ba343     XOR        EBX,EBX
    //         004ba345     MOV        BL,byte ptr [this->shape]
    //         004ba347     INC        this
    //         004ba348     CMP        this,ESI
    //         004ba34a     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba34d     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba350     JC         LAB_004ba343
    //                               LAB_004ba352                                                 XREF[3]:     004ba309(j), 004ba31c(j), 
    //                                                                                                         004ba341(j)  
    //                              Shape.cpp:1544 (6)
    //         004ba352     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba356     ADD        ESI,EDI
    //                              Shape.cpp:1547 (2)
    //         004ba358     JMP        LAB_004ba3bd
    //                               LAB_004ba35a                                                 XREF[1]:     004ba2b8(j)  
    //                              Shape.cpp:1549 (6)
    //         004ba35a     SHR        BL,0x1
    //         004ba35c     MOV        byte ptr [ESP + param_5],BL
    //                              Shape.cpp:1550 (2)
    //         004ba360     JNZ        LAB_004ba366
    //                              Shape.cpp:1551 (2)
    //         004ba362     MOV        AL,0x3
    //                              Shape.cpp:1552 (2)
    //         004ba364     JMP        LAB_004ba3c1
    //                               LAB_004ba366                                                 XREF[1]:     004ba360(j)  
    //                              Shape.cpp:1554 (4)
    //         004ba366     MOV        ESI,dword ptr [ESP + param_5]
    //                              Shape.cpp:1555 (16)
    //         004ba36a     MOV        EDI,dword ptr [ESP + param_4]
    //         004ba36e     AND        ESI,0xff
    //         004ba374     ADD        EDX,ESI
    //         004ba376     CMP        EDX,EDI
    //         004ba378     JL         LAB_004ba3b8
    //                              Shape.cpp:1557 (8)
    //         004ba37a     MOV        ESI,dword ptr [ESP + param_6]
    //         004ba37e     CMP        EDX,ESI
    //         004ba380     JLE        LAB_004ba39e
    //                              Shape.cpp:1561 (11)
    //         004ba382     ADD        ESI,this
    //         004ba384     MOV        AL,0x2
    //         004ba386     SUB        ESI,EDI
    //         004ba388     INC        ESI
    //         004ba389     CMP        this,ESI
    //         004ba38b     JNC        LAB_004ba3b8
    //                               LAB_004ba38d                                                 XREF[1]:     004ba39a(j)  
    //                              Shape.cpp:1562 (15)
    //         004ba38d     XOR        EBX,EBX
    //         004ba38f     MOV        BL,byte ptr [this->shape]
    //         004ba391     INC        this
    //         004ba392     CMP        this,ESI
    //         004ba394     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba397     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba39a     JC         LAB_004ba38d
    //                              Shape.cpp:1564 (2)
    //         004ba39c     JMP        LAB_004ba3b8
    //                               LAB_004ba39e                                                 XREF[1]:     004ba380(j)  
    //                              Shape.cpp:1568 (11)
    //         004ba39e     LEA        ESI,[this->shape + EDX*0x1]
    //         004ba3a1     MOV        AL,0x1
    //         004ba3a3     SUB        ESI,EDI
    //         004ba3a5     CMP        this,ESI
    //         004ba3a7     JNC        LAB_004ba3b8
    //                               LAB_004ba3a9                                                 XREF[1]:     004ba3b6(j)  
    //                              Shape.cpp:1569 (15)
    //         004ba3a9     XOR        EBX,EBX
    //         004ba3ab     MOV        BL,byte ptr [this->shape]
    //         004ba3ad     INC        this
    //         004ba3ae     CMP        this,ESI
    //         004ba3b0     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba3b3     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba3b6     JC         LAB_004ba3a9
    //                               LAB_004ba3b8                                                 XREF[4]:     004ba378(j), 004ba38b(j), 
    //                                                                                                         004ba39c(j), 004ba3a7(j)  
    //                              Shape.cpp:1572 (9)
    //         004ba3b8     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba3bc     INC        ESI
    //                               LAB_004ba3bd                                                 XREF[2]:     004ba333(j), 004ba358(j)  
    //         004ba3bd     MOV        dword ptr [ESP + param_1],ESI
    //                               LAB_004ba3c1                                                 XREF[4]:     004ba2d7(j), 004ba2e5(j), 
    //                                                                                                         004ba2f2(j), 004ba364(j)  
    //                              Shape.cpp:1577 (14)
    //         004ba3c1     MOV        EBX,dword ptr [ESP + param_1]
    //         004ba3c5     TEST       AL,AL
    //         004ba3c7     JZ         LAB_004ba29f
    //         004ba3cd     JMP        LAB_004ba3d1
    //                               LAB_004ba3cf                                                 XREF[1]:     004ba297(j)  
    //                              Shape.cpp:1578 (2)
    //         004ba3cf     MOV        AL,0x1
    //                               LAB_004ba3d1                                                 XREF[1]:     004ba3cd(j)  
    //                              Shape.cpp:1581 (2)
    //         004ba3d1     DEC        AL
    //                              Shape.cpp:1582 (6)
    //         004ba3d3     JNZ        LAB_004ba4e8
    //                               LAB_004ba3d9                                                 XREF[1]:     004ba4e2(j)  
    //                              Shape.cpp:1584 (2)
    //         004ba3d9     MOV        BL,byte ptr [EBX]
    //                              Shape.cpp:1585 (8)
    //         004ba3db     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba3df     MOV        byte ptr [ESP + param_5],BL
    //                              Shape.cpp:1586 (7)
    //         004ba3e3     AND        BL,0x1
    //         004ba3e6     INC        ESI
    //         004ba3e7     CMP        BL,0x1
    //                              Shape.cpp:1588 (20)
    //         004ba3ea     MOV        BL,byte ptr [ESP + param_5]
    //         004ba3ee     MOV        dword ptr [ESP + param_1],ESI
    //         004ba3f2     JNZ        LAB_004ba47d
    //         004ba3f8     SHR        BL,0x1
    //         004ba3fa     MOV        byte ptr [ESP + param_5],BL
    //                              Shape.cpp:1589 (2)
    //         004ba3fe     JNZ        LAB_004ba424
    //                              Shape.cpp:1591 (10)
    //         004ba400     MOV        EDI,ESI
    //         004ba402     XOR        EBX,EBX
    //         004ba404     MOV        BL,byte ptr [EDI]
    //         004ba406     MOV        ESI,EBX
    //         004ba408     ADD        EDX,ESI
    //                              Shape.cpp:1592 (2)
    //         004ba40a     ADD        this,ESI
    //                              Shape.cpp:1594 (17)
    //         004ba40c     MOV        ESI,dword ptr [ESP + param_6]
    //         004ba410     INC        EDI
    //         004ba411     CMP        EDX,ESI
    //         004ba413     MOV        dword ptr [ESP + param_1],EDI
    //         004ba417     JLE        LAB_004ba4dc
    //                              Shape.cpp:1595 (2)
    //         004ba41d     MOV        AL,0x1
    //                              Shape.cpp:1597 (5)
    //         004ba41f     JMP        LAB_004ba4dc
    //                               LAB_004ba424                                                 XREF[1]:     004ba3fe(j)  
    //                              Shape.cpp:1599 (4)
    //         004ba424     MOV        EDI,dword ptr [ESP + param_5]
    //                              Shape.cpp:1600 (16)
    //         004ba428     MOV        ESI,dword ptr [ESP + param_6]
    //         004ba42c     AND        EDI,0xff
    //         004ba432     ADD        EDX,EDI
    //         004ba434     CMP        EDX,ESI
    //         004ba436     JLE        LAB_004ba45f
    //                              Shape.cpp:1604 (16)
    //         004ba438     MOV        EBX,this
    //         004ba43a     MOV        AL,0x1
    //         004ba43c     SUB        EBX,EDX
    //         004ba43e     ADD        EBX,ESI
    //         004ba440     LEA        ESI,[EBX + EDI*0x1 + 0x1]
    //         004ba444     CMP        this,ESI
    //         004ba446     JNC        LAB_004ba475
    //                               LAB_004ba448                                                 XREF[1]:     004ba455(j)  
    //                              Shape.cpp:1605 (15)
    //         004ba448     XOR        EBX,EBX
    //         004ba44a     MOV        BL,byte ptr [this->shape]
    //         004ba44c     INC        this
    //         004ba44d     CMP        this,ESI
    //         004ba44f     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba452     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba455     JC         LAB_004ba448
    //                              Shape.cpp:1610 (6)
    //         004ba457     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba45b     ADD        ESI,EDI
    //                              Shape.cpp:1613 (2)
    //         004ba45d     JMP        LAB_004ba4d8
    //                               LAB_004ba45f                                                 XREF[1]:     004ba436(j)  
    //                              Shape.cpp:1608 (7)
    //         004ba45f     LEA        ESI,[this->shape + EDI*0x1]
    //         004ba462     CMP        this,ESI
    //         004ba464     JNC        LAB_004ba475
    //                               LAB_004ba466                                                 XREF[1]:     004ba473(j)  
    //                              Shape.cpp:1609 (15)
    //         004ba466     XOR        EBX,EBX
    //         004ba468     MOV        BL,byte ptr [this->shape]
    //         004ba46a     INC        this
    //         004ba46b     CMP        this,ESI
    //         004ba46d     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba470     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba473     JC         LAB_004ba466
    //                               LAB_004ba475                                                 XREF[2]:     004ba446(j), 004ba464(j)  
    //                              Shape.cpp:1610 (6)
    //         004ba475     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba479     ADD        ESI,EDI
    //                              Shape.cpp:1613 (2)
    //         004ba47b     JMP        LAB_004ba4d8
    //                               LAB_004ba47d                                                 XREF[1]:     004ba3f2(j)  
    //                              Shape.cpp:1615 (6)
    //         004ba47d     SHR        BL,0x1
    //         004ba47f     MOV        byte ptr [ESP + param_5],BL
    //                              Shape.cpp:1616 (2)
    //         004ba483     JNZ        LAB_004ba489
    //                              Shape.cpp:1617 (2)
    //         004ba485     MOV        AL,0x3
    //                              Shape.cpp:1618 (2)
    //         004ba487     JMP        LAB_004ba4dc
    //                               LAB_004ba489                                                 XREF[1]:     004ba483(j)  
    //                              Shape.cpp:1620 (4)
    //         004ba489     MOV        ESI,dword ptr [ESP + param_5]
    //                              Shape.cpp:1621 (16)
    //         004ba48d     MOV        EDI,dword ptr [ESP + param_6]
    //         004ba491     AND        ESI,0xff
    //         004ba497     ADD        EDX,ESI
    //         004ba499     CMP        EDX,EDI
    //         004ba49b     JLE        LAB_004ba4be
    //                              Shape.cpp:1625 (16)
    //         004ba49d     MOV        EBX,this
    //         004ba49f     MOV        AL,0x1
    //         004ba4a1     SUB        EBX,EDX
    //         004ba4a3     ADD        EBX,EDI
    //         004ba4a5     LEA        ESI,[EBX + ESI*0x1 + 0x1]
    //         004ba4a9     CMP        this,ESI
    //         004ba4ab     JNC        LAB_004ba4d3
    //                               LAB_004ba4ad                                                 XREF[1]:     004ba4ba(j)  
    //                              Shape.cpp:1626 (15)
    //         004ba4ad     XOR        EBX,EBX
    //         004ba4af     MOV        BL,byte ptr [this->shape]
    //         004ba4b1     INC        this
    //         004ba4b2     CMP        this,ESI
    //         004ba4b4     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba4b7     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba4ba     JC         LAB_004ba4ad
    //                              Shape.cpp:1628 (2)
    //         004ba4bc     JMP        LAB_004ba4d3
    //                               LAB_004ba4be                                                 XREF[1]:     004ba49b(j)  
    //                              Shape.cpp:1629 (6)
    //         004ba4be     ADD        ESI,this
    //         004ba4c0     CMP        this,ESI
    //         004ba4c2     JNC        LAB_004ba4d3
    //                               LAB_004ba4c4                                                 XREF[1]:     004ba4d1(j)  
    //                              Shape.cpp:1630 (15)
    //         004ba4c4     XOR        EBX,EBX
    //         004ba4c6     MOV        BL,byte ptr [this->shape]
    //         004ba4c8     INC        this
    //         004ba4c9     CMP        this,ESI
    //         004ba4cb     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004ba4ce     MOV        byte ptr [this->shape + -0x1],BL
    //         004ba4d1     JC         LAB_004ba4c4
    //                               LAB_004ba4d3                                                 XREF[3]:     004ba4ab(j), 004ba4bc(j), 
    //                                                                                                         004ba4c2(j)  
    //                              Shape.cpp:1631 (9)
    //         004ba4d3     MOV        ESI,dword ptr [ESP + param_1]
    //         004ba4d7     INC        ESI
    //                               LAB_004ba4d8                                                 XREF[2]:     004ba45d(j), 004ba47b(j)  
    //         004ba4d8     MOV        dword ptr [ESP + param_1],ESI
    //                               LAB_004ba4dc                                                 XREF[3]:     004ba417(j), 004ba41f(j), 
    //                                                                                                         004ba487(j)  
    //                              Shape.cpp:1582 (12)
    //         004ba4dc     MOV        EBX,dword ptr [ESP + param_1]
    //         004ba4e0     TEST       AL,AL
    //         004ba4e2     JZ         LAB_004ba3d9
    //                               LAB_004ba4e8                                                 XREF[1]:     004ba3d3(j)  
    //                              Shape.cpp:1637 (2)
    //         004ba4e8     DEC        AL
    //                              Shape.cpp:1638 (2)
    //         004ba4ea     JNZ        LAB_004ba521
    //                               LAB_004ba4ec                                                 XREF[1]:     004ba51b(j)  
    //                              Shape.cpp:1640 (2)
    //         004ba4ec     MOV        this,byte ptr [EBX]
    //                              Shape.cpp:1641 (1)
    //         004ba4ee     INC        EBX
    //                              Shape.cpp:1642 (10)
    //         004ba4ef     MOV        DL,this
    //         004ba4f1     AND        DL,0x1
    //         004ba4f4     CMP        DL,0x1
    //         004ba4f7     JNZ        LAB_004ba50f
    //                              Shape.cpp:1644 (6)
    //         004ba4f9     SHR        this,0x1
    //         004ba4fb     MOV        byte ptr [ESP + param_5],this
    //                              Shape.cpp:1647 (2)
    //         004ba4ff     JZ         LAB_004ba518
    //                              Shape.cpp:1648 (12)
    //         004ba501     MOV        this,dword ptr [ESP + param_5]
    //         004ba505     AND        this,0xff
    //         004ba50b     ADD        EBX,this
    //                              Shape.cpp:1650 (2)
    //         004ba50d     JMP        LAB_004ba519
    //                               LAB_004ba50f                                                 XREF[1]:     004ba4f7(j)  
    //                              Shape.cpp:1653 (5)
    //         004ba50f     TEST       this,0xfe
    //         004ba512     JNZ        LAB_004ba518
    //                              Shape.cpp:1654 (2)
    //         004ba514     MOV        AL,0x2
    //                              Shape.cpp:1655 (2)
    //         004ba516     JMP        LAB_004ba519
    //                               LAB_004ba518                                                 XREF[2]:     004ba4ff(j), 004ba512(j)  
    //                              Shape.cpp:1656 (1)
    //         004ba518     INC        EBX
    //                               LAB_004ba519                                                 XREF[2]:     004ba50d(j), 004ba516(j)  
    //                              Shape.cpp:1638 (4)
    //         004ba519     TEST       AL,AL
    //         004ba51b     JZ         LAB_004ba4ec
    //                              Shape.cpp:1641 (4)
    //         004ba51d     MOV        dword ptr [ESP + param_1],EBX
    //                               LAB_004ba521                                                 XREF[1]:     004ba4ea(j)  
    //                              Shape.cpp:1661 (29)
    //         004ba521     MOV        this,dword ptr [ESP + width]
    //         004ba525     MOV        EDX,dword ptr [ESP + local_4]
    //         004ba529     MOV        EAX,dword ptr [ESP + param_3]
    //         004ba52d     ADD        this,EDX
    //         004ba52f     DEC        EAX
    //         004ba530     MOV        dword ptr [ESP + width],this
    //         004ba534     MOV        dword ptr [ESP + param_3],EAX
    //         004ba538     JNZ        LAB_004ba28d
    //                               LAB_004ba53e                                                 XREF[1]:     004ba27c(j)  
    //                              Shape.cpp:1666 (12)
    //         004ba53e     POP        EDI
    //         004ba53f     POP        ESI
    //         004ba540     POP        EBP
    //         004ba541     MOV        AL,0x1
    //         004ba543     POP        EBX
    //         004ba544     ADD        ESP,0x8
    //         004ba547     RET        0x20
}

// Offset: 0x004BA550
uchar shape_mirror(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, uchar param_6, uchar* param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TShape::shape_mirror(class TDrawArea *,long,long,long,unsigned ch... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror(TShape * this, TDrawArea * param_1, lo
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[9]:     004ba5f4(R), 004ba69f(R), 004ba708(W), 004ba72e(W), 
    //                                                                                     004ba759(R), 004ba762(W), 004ba77a(R), 004ba7a8(R), 
    //                                                                                     004ba856(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[12]:    004ba5bb(R), 004ba65a(R), 004ba6d9(R), 004ba6f8(W), 
    //                                                                                     004ba716(W), 004ba73e(R), 004ba748(W), 004ba776(R), 
    //                                                                                     004ba796(R), 004ba87e(R), 004ba8a7(R), 004ba8cc(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[13]:    004ba5ae(R), 004ba672(R), 004ba6cf(R), 004ba6f4(R), 
    //                                                                                     004ba710(W), 004ba73a(W), 004ba769(R), 004ba772(W), 
    //                                                                                     004ba78a(R), 004ba7b4(R), 004ba878(R), 004ba8a1(R), 
    //                                                                                     004ba8c6(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     004ba557(R), 004ba829(R), 004ba8ad(R)  
    //              uchar             Stack[0x14]:1  param_5                   XREF[2]:     004ba7c2(R), 004ba85a(R)  
    //              uchar *           Stack[0x18]:4  param_6                   XREF[6]:     004ba5aa(R), 004ba631(R), 004ba7db(R), 004ba80c(R), 
    //                                                                                     004ba86f(R), 004ba898(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004ba6be(W), 004ba732(R)  
    //              tagRECT           Stack[-0x14]   rect                      XREF[2,6]:   004ba70c(W), 004ba7b8(R), 004ba6a9(W), 004ba6fe(R), 
    //                                                                                     004ba6b0(W), 004ba71a(R), 004ba6b7(W), 004ba726(R)  
    //              long              Stack[-0x18]:4 shape_y1                  XREF[5]:     004ba704(W), 004ba722(W), 004ba74c(R), 004ba752(W), 
    //                                                                                     004ba786(R)  
    //              long              Stack[-0x1c]:4 clip_y0                   XREF[0,2]:   004ba55f(W), 004ba8e6(R)  
    //              uchar             Stack[-0x1d]:1 ret_num
    //                               ?shape_mirror@TShape@@QAEEPAVTDrawArea@@JJJEPAE@Z            XREF[2]:     do_draw:004c0373(c), 
    //                               TShape::shape_mirror                                                      do_draw:004c03be(c)  
    //                              Shape.cpp:1670 (7)
    //         004ba550     SUB        ESP,0x1c
    //         004ba553     PUSH       EBX
    //         004ba554     PUSH       EBP
    //         004ba555     PUSH       ESI
    //         004ba556     PUSH       EDI
    //                              Shape.cpp:1684 (38)
    //         004ba557     MOV        EDI,dword ptr [ESP + param_4]
    //         004ba55b     MOV        ESI,this
    //         004ba55d     TEST       EDI,EDI
    //         004ba55f     MOV        byte ptr [ESP + clip_y0+0x3],0x0
    //         004ba564     JL         LAB_004ba8f4
    //         004ba56a     PUSH       s_RGL_shape_draw                                 = "RGL_shape_draw"
    //         004ba56f     PUSH       EDI
    //         004ba570     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004ba575     TEST       AL,AL
    //         004ba577     JNZ        LAB_004ba8f4
    //                              Shape.cpp:1686 (11)
    //         004ba57d     MOV        EAX,dword ptr [ESI + 0x18]
    //         004ba580     TEST       EAX,EAX
    //         004ba582     JZ         LAB_004ba69f
    //                              Shape.cpp:1688 (10)
    //         004ba588     MOV        this,dword ptr [SDI_Capture_Info]
    //         004ba58e     TEST       this,this
    //         004ba590     JZ         LAB_004ba5f4
    //                              Shape.cpp:1692 (86)
    //         004ba592     MOV        this,dword ptr [SDI_Draw_Level]
    //         004ba598     INC        EDI
    //         004ba599     SHL        EDI,0x5
    //         004ba59c     ADD        EDI,EAX
    //         004ba59e     MOV        EAX,[SDI_Object_ID]
    //         004ba5a3     PUSH       EAX
    //         004ba5a4     PUSH       this
    //         004ba5a5     CALL       _ASMGet_Color_Xform                              undefined _ASMGet_Color_Xform()
    //         004ba5aa     MOV        EDX,dword ptr [ESP + param_6]
    //         004ba5ae     MOV        this,dword ptr [ESP + param_3]
    //         004ba5b2     MOV        EBX,dword ptr [EDI + 0x1c]
    //         004ba5b5     PUSH       EAX
    //         004ba5b6     MOV        EAX,[fog_next_shape]
    //         004ba5bb     MOV        EBP,dword ptr [ESP + param_2]
    //         004ba5bf     ADD        EAX,0x2
    //         004ba5c2     PUSH       EDX
    //         004ba5c3     MOV        EDX,dword ptr [EDI + 0x18]
    //         004ba5c6     PUSH       EAX
    //         004ba5c7     MOV        EAX,dword ptr [EDI + 0x10]
    //         004ba5ca     SUB        this,EBX
    //         004ba5cc     SUB        EDX,EAX
    //         004ba5ce     MOV        EAX,[SDI_Draw_Line]
    //         004ba5d3     ADD        EDX,EBP
    //         004ba5d5     PUSH       this
    //         004ba5d6     MOV        this,dword ptr [ESI + 0x18]
    //         004ba5d9     PUSH       EDX
    //         004ba5da     PUSH       EAX
    //         004ba5db     PUSH       EDI
    //         004ba5dc     PUSH       this
    //         004ba5dd     MOV        this,dword ptr [SDI_List]                        = 00000000
    //         004ba5e3     CALL       DClipInfo_List::AddDrawNode                      void AddDrawNode(DClipInfo_List * this, void 
    //                              Shape.cpp:1694 (2)
    //         004ba5e8     MOV        AL,0x1
    //                              Shape.cpp:1805 (10)
    //         004ba5ea     POP        EDI
    //         004ba5eb     POP        ESI
    //         004ba5ec     POP        EBP
    //         004ba5ed     POP        EBX
    //         004ba5ee     ADD        ESP,0x1c
    //         004ba5f1     RET        0x18
    //                               LAB_004ba5f4                                                 XREF[1]:     004ba590(j)  
    //                              Shape.cpp:1698 (26)
    //         004ba5f4     MOV        this,dword ptr [ESP + param_1]
    //         004ba5f8     MOV        EDX,dword ptr [this->shape + 0xcc]
    //         004ba5fe     MOV        EAX,dword ptr [this->shape + 0xd0]
    //         004ba604     MOV        EDX,dword ptr [EDX + 0x50]
    //         004ba607     MOV        EBX,dword ptr [EAX + 0x50]
    //         004ba60a     CMP        EDX,EBX
    //         004ba60c     JGE        LAB_004ba611
    //                              Shape.cpp:1699 (1)
    //         004ba60e     DEC        EDX
    //                              Shape.cpp:1700 (2)
    //         004ba60f     JMP        LAB_004ba614
    //                               LAB_004ba611                                                 XREF[1]:     004ba60c(j)  
    //                              Shape.cpp:1701 (3)
    //         004ba611     LEA        EDX,[EBX + -0x1]
    //                               LAB_004ba614                                                 XREF[1]:     004ba60f(j)  
    //                              Shape.cpp:1711 (29)
    //         004ba614     MOV        this,dword ptr [this->shape + 0xc0]
    //         004ba61a     PUSH       EDX
    //         004ba61b     MOV        EDX,dword ptr [EAX + 0x5c]
    //         004ba61e     PUSH       EDX
    //         004ba61f     MOV        EDX,dword ptr [EAX + 0x40]
    //         004ba622     MOV        EAX,dword ptr [EAX + 0x3c]
    //         004ba625     PUSH       0x0
    //         004ba627     PUSH       0x0
    //         004ba629     PUSH       EDX
    //         004ba62a     PUSH       EAX
    //         004ba62b     PUSH       this
    //         004ba62c     CALL       _ASMSet_Surface_Info                             undefined _ASMSet_Surface_Info()
    //                              Shape.cpp:1714 (20)
    //         004ba631     MOV        EAX,dword ptr [ESP + param_6]
    //         004ba635     ADD        ESP,0x1c
    //         004ba638     TEST       EAX,EAX
    //         004ba63a     JZ         LAB_004ba645
    //         004ba63c     PUSH       EAX
    //         004ba63d     CALL       _ASMSet_Xlate_Table                              undefined _ASMSet_Xlate_Table()
    //         004ba642     ADD        ESP,0x4
    //                               LAB_004ba645                                                 XREF[1]:     004ba63a(j)  
    //                              Shape.cpp:1716 (3)
    //         004ba645     MOV        ESI,dword ptr [ESI + 0x18]
    //                              Shape.cpp:1730 (61)
    //         004ba648     MOV        EDX,dword ptr [fog_next_shape]
    //         004ba64e     LEA        EAX,[EDI + 0x1]
    //         004ba651     ADD        EDX,0x2
    //         004ba654     SHL        EAX,0x5
    //         004ba657     ADD        EAX,ESI
    //         004ba659     PUSH       EDX
    //         004ba65a     MOV        EBP,dword ptr [ESP + param_2]
    //         004ba65e     MOV        EDX,dword ptr [EAX + 0x4]
    //         004ba661     MOV        this,dword ptr [EAX + 0x10]
    //         004ba664     MOV        EBX,dword ptr [EAX + 0x1c]
    //         004ba667     PUSH       EDX
    //         004ba668     MOV        EDX,dword ptr [EAX]
    //         004ba66a     PUSH       EDX
    //         004ba66b     MOV        EDX,dword ptr [EAX + 0x14]
    //         004ba66e     MOV        EAX,dword ptr [EAX + 0x18]
    //         004ba671     PUSH       EDX
    //         004ba672     MOV        EDX,dword ptr [ESP + param_3]
    //         004ba676     ADD        EAX,EBP
    //         004ba678     SUB        EDX,EBX
    //         004ba67a     PUSH       this
    //         004ba67b     SUB        EAX,this
    //         004ba67d     PUSH       EDX
    //         004ba67e     PUSH       EAX
    //         004ba67f     PUSH       ESI
    //         004ba680     CALL       _ASMDraw_Sprite                                  undefined _ASMDraw_Sprite()
    //                              Shape.cpp:1732 (14)
    //         004ba685     MOV        EAX,[ASM_Fast_Count]
    //         004ba68a     ADD        ESP,0x20
    //         004ba68d     INC        EAX
    //         004ba68e     MOV        [ASM_Fast_Count],EAX
    //                              Shape.cpp:1734 (2)
    //         004ba693     MOV        AL,0x1
    //                              Shape.cpp:1805 (10)
    //         004ba695     POP        EDI
    //         004ba696     POP        ESI
    //         004ba697     POP        EBP
    //         004ba698     POP        EBX
    //         004ba699     ADD        ESP,0x1c
    //         004ba69c     RET        0x18
    //                               LAB_004ba69f                                                 XREF[1]:     004ba582(j)  
    //                              Shape.cpp:1741 (35)
    //         004ba69f     MOV        EBP,dword ptr [ESP + param_1]
    //         004ba6a3     LEA        this,[EBP + 0x28]
    //         004ba6a6     MOV        EDX,dword ptr [EBP + 0x28]
    //         004ba6a9     MOV        dword ptr [ESP + rect.top],EDX
    //         004ba6ad     MOV        EAX,dword ptr [ECX + this->load_type]
    //         004ba6b0     MOV        dword ptr [ESP + rect.right],EAX
    //         004ba6b4     MOV        EDX,dword ptr [ECX + this->load_size]
    //         004ba6b7     MOV        dword ptr [ESP + rect.bottom],EDX
    //         004ba6bb     MOV        EAX,dword ptr [ECX + this->shape_header]
    //         004ba6be     MOV        dword ptr [ESP + local_4],EAX
    //                              Shape.cpp:1743 (10)
    //         004ba6c2     MOV        EAX,dword ptr [ESI]
    //         004ba6c4     TEST       EAX,EAX
    //         004ba6c6     JZ         LAB_004ba8f4
    //                              Shape.cpp:1745 (3)
    //         004ba6cc     MOV        this,dword ptr [ESI + 0x14]
    //                              Shape.cpp:1748 (29)
    //         004ba6cf     MOV        EBX,dword ptr [ESP + param_3]
    //         004ba6d3     MOV        EDX,dword ptr [this->shape + EDI*0x8]
    //         004ba6d6     LEA        this,[EDX + EAX*0x1]
    //         004ba6d9     MOV        EDX,dword ptr [ESP + param_2]
    //         004ba6dd     MOV        dword ptr [ESI + 0xc],this
    //         004ba6e0     MOV        EDI,EDX
    //         004ba6e2     MOV        EAX,dword ptr [ECX + this->head]
    //         004ba6e5     SUB        EDI,EAX
    //         004ba6e7     MOV        EAX,dword ptr [ECX + this->shape_header]
    //         004ba6ea     ADD        EAX,EBX
    //                              Shape.cpp:1750 (3)
    //         004ba6ec     MOV        EBX,dword ptr [ECX + this->load_size]
    //                              Shape.cpp:1751 (15)
    //         004ba6ef     MOV        this,dword ptr [ECX + this->offsets]
    //         004ba6f2     SUB        EDX,EBX
    //         004ba6f4     MOV        EBX,dword ptr [ESP + param_3]
    //         004ba6f8     MOV        dword ptr [ESP + param_2],EDI
    //         004ba6fc     ADD        this,EBX
    //                              Shape.cpp:1753 (28)
    //         004ba6fe     MOV        EBX,dword ptr [ESP + rect.top]
    //         004ba702     CMP        EDI,EBX
    //         004ba704     MOV        dword ptr [ESP + shape_y1],EAX
    //         004ba708     MOV        dword ptr [ESP + param_1],EDX
    //         004ba70c     MOV        dword ptr [ESP + rect.left],this
    //         004ba710     MOV        dword ptr [ESP + param_3],this
    //         004ba714     JGE        LAB_004ba71a
    //         004ba716     MOV        dword ptr [ESP + param_2],EBX
    //                               LAB_004ba71a                                                 XREF[1]:     004ba714(j)  
    //                              Shape.cpp:1754 (12)
    //         004ba71a     MOV        EBX,dword ptr [ESP + rect.right]
    //         004ba71e     CMP        EAX,EBX
    //         004ba720     JGE        LAB_004ba726
    //         004ba722     MOV        dword ptr [ESP + shape_y1],EBX
    //                               LAB_004ba726                                                 XREF[1]:     004ba720(j)  
    //                              Shape.cpp:1755 (12)
    //         004ba726     MOV        EBX,dword ptr [ESP + rect.bottom]
    //         004ba72a     CMP        EDX,EBX
    //         004ba72c     JLE        LAB_004ba732
    //         004ba72e     MOV        dword ptr [ESP + param_1],EBX
    //                               LAB_004ba732                                                 XREF[1]:     004ba72c(j)  
    //                              Shape.cpp:1756 (12)
    //         004ba732     MOV        EBX,dword ptr [ESP + local_4]
    //         004ba736     CMP        this,EBX
    //         004ba738     JLE        LAB_004ba73e
    //         004ba73a     MOV        dword ptr [ESP + param_3],EBX
    //                               LAB_004ba73e                                                 XREF[1]:     004ba738(j)  
    //                              Shape.cpp:1758 (14)
    //         004ba73e     MOV        EBX,dword ptr [ESP + param_2]
    //         004ba742     XOR        this,this
    //         004ba744     CMP        EBX,this
    //         004ba746     JGE        LAB_004ba74c
    //         004ba748     MOV        dword ptr [ESP + param_2],this
    //                               LAB_004ba74c                                                 XREF[1]:     004ba746(j)  
    //                              Shape.cpp:1759 (10)
    //         004ba74c     CMP        dword ptr [ESP + shape_y1],this
    //         004ba750     JGE        LAB_004ba756
    //         004ba752     MOV        dword ptr [ESP + shape_y1],this
    //                               LAB_004ba756                                                 XREF[1]:     004ba750(j)  
    //                              Shape.cpp:1760 (16)
    //         004ba756     MOV        this,dword ptr [EBP + 0x18]
    //         004ba759     MOV        EBX,dword ptr [ESP + param_1]
    //         004ba75d     CMP        EBX,this
    //         004ba75f     JL         LAB_004ba766
    //         004ba761     DEC        this
    //         004ba762     MOV        dword ptr [ESP + param_1],this
    //                               LAB_004ba766                                                 XREF[1]:     004ba75f(j)  
    //                              Shape.cpp:1761 (16)
    //         004ba766     MOV        this,dword ptr [EBP + 0x1c]
    //         004ba769     MOV        EBX,dword ptr [ESP + param_3]
    //         004ba76d     CMP        EBX,this
    //         004ba76f     JL         LAB_004ba776
    //         004ba771     DEC        this
    //         004ba772     MOV        dword ptr [ESP + param_3],this
    //                               LAB_004ba776                                                 XREF[1]:     004ba76f(j)  
    //                              Shape.cpp:1763 (32)
    //         004ba776     MOV        this,dword ptr [ESP + param_2]
    //         004ba77a     MOV        EBX,dword ptr [ESP + param_1]
    //         004ba77e     CMP        EBX,this
    //         004ba780     JL         LAB_004ba8f4
    //         004ba786     MOV        EBX,dword ptr [ESP + shape_y1]
    //         004ba78a     MOV        this,dword ptr [ESP + param_3]
    //         004ba78e     CMP        this,EBX
    //         004ba790     JL         LAB_004ba8f4
    //                              Shape.cpp:1765 (44)
    //         004ba796     CMP        dword ptr [ESP + param_2],EDI
    //         004ba79a     JNZ        LAB_004ba856
    //         004ba7a0     CMP        EBX,EAX
    //         004ba7a2     JNZ        LAB_004ba856
    //         004ba7a8     MOV        this,dword ptr [ESP + param_1]
    //         004ba7ac     CMP        this,EDX
    //         004ba7ae     JNZ        LAB_004ba85a
    //         004ba7b4     MOV        EDI,dword ptr [ESP + param_3]
    //         004ba7b8     CMP        EDI,dword ptr [ESP + rect.left]
    //         004ba7bc     JNZ        LAB_004ba85a
    //                              Shape.cpp:1766 (25)
    //         004ba7c2     MOV        this,dword ptr [ESP + param_5]
    //         004ba7c6     AND        this,0xff
    //         004ba7cc     SUB        this,0x0
    //         004ba7cf     JZ         LAB_004ba842
    //         004ba7d1     DEC        this
    //         004ba7d2     JZ         LAB_004ba80c
    //         004ba7d4     DEC        this
    //         004ba7d5     JNZ        LAB_004ba8e6
    //                              Shape.cpp:1778 (8)
    //         004ba7db     MOV        this,dword ptr [ESP + param_6]
    //         004ba7df     TEST       this,this
    //         004ba7e1     JNZ        LAB_004ba7f7
    //                              Shape.cpp:1779 (10)
    //         004ba7e3     PUSH       EAX
    //         004ba7e4     PUSH       EDX
    //         004ba7e5     PUSH       EBP
    //         004ba7e6     MOV        this,ESI
    //         004ba7e8     CALL       TShape::shape_mirror_unclipped                   uchar shape_mirror_unclipped(TShape * this, T
    //                              Shape.cpp:1805 (10)
    //         004ba7ed     POP        EDI
    //         004ba7ee     POP        ESI
    //         004ba7ef     POP        EBP
    //         004ba7f0     POP        EBX
    //         004ba7f1     ADD        ESP,0x1c
    //         004ba7f4     RET        0x18
    //                               LAB_004ba7f7                                                 XREF[1]:     004ba7e1(j)  
    //                              Shape.cpp:1781 (11)
    //         004ba7f7     PUSH       this
    //         004ba7f8     PUSH       EAX
    //         004ba7f9     PUSH       EDX
    //         004ba7fa     PUSH       EBP
    //         004ba7fb     MOV        this,ESI
    //         004ba7fd     CALL       TShape::shape_mirror_shadow_unclipped            uchar shape_mirror_shadow_unclipped(TShape * 
    //                              Shape.cpp:1805 (10)
    //         004ba802     POP        EDI
    //         004ba803     POP        ESI
    //         004ba804     POP        EBP
    //         004ba805     POP        EBX
    //         004ba806     ADD        ESP,0x1c
    //         004ba809     RET        0x18
    //                               LAB_004ba80c                                                 XREF[1]:     004ba7d2(j)  
    //                              Shape.cpp:1772 (8)
    //         004ba80c     MOV        this,dword ptr [ESP + param_6]
    //         004ba810     TEST       this,this
    //         004ba812     JNZ        LAB_004ba828
    //                              Shape.cpp:1773 (10)
    //         004ba814     PUSH       EAX
    //         004ba815     PUSH       EDX
    //         004ba816     PUSH       EBP
    //         004ba817     MOV        this,ESI
    //         004ba819     CALL       TShape::shape_mirror_unclipped                   uchar shape_mirror_unclipped(TShape * this, T
    //                              Shape.cpp:1805 (10)
    //         004ba81e     POP        EDI
    //         004ba81f     POP        ESI
    //         004ba820     POP        EBP
    //         004ba821     POP        EBX
    //         004ba822     ADD        ESP,0x1c
    //         004ba825     RET        0x18
    //                               LAB_004ba828                                                 XREF[1]:     004ba812(j)  
    //                              Shape.cpp:1775 (16)
    //         004ba828     PUSH       this
    //         004ba829     MOV        this,dword ptr [ESP + param_4]
    //         004ba82d     PUSH       this
    //         004ba82e     PUSH       EAX
    //         004ba82f     PUSH       EDX
    //         004ba830     PUSH       EBP
    //         004ba831     MOV        this,ESI
    //         004ba833     CALL       TShape::shape_mirror_color_trans_unclipped       uchar shape_mirror_color_trans_unclipped(TSha
    //                              Shape.cpp:1805 (10)
    //         004ba838     POP        EDI
    //         004ba839     POP        ESI
    //         004ba83a     POP        EBP
    //         004ba83b     POP        EBX
    //         004ba83c     ADD        ESP,0x1c
    //         004ba83f     RET        0x18
    //                               LAB_004ba842                                                 XREF[1]:     004ba7cf(j)  
    //                              Shape.cpp:1769 (10)
    //         004ba842     PUSH       EAX
    //         004ba843     PUSH       EDX
    //         004ba844     PUSH       EBP
    //         004ba845     MOV        this,ESI
    //         004ba847     CALL       TShape::shape_mirror_unclipped                   uchar shape_mirror_unclipped(TShape * this, T
    //                              Shape.cpp:1805 (10)
    //         004ba84c     POP        EDI
    //         004ba84d     POP        ESI
    //         004ba84e     POP        EBP
    //         004ba84f     POP        EBX
    //         004ba850     ADD        ESP,0x1c
    //         004ba853     RET        0x18
    //                               LAB_004ba856                                                 XREF[2]:     004ba79a(j), 004ba7a2(j)  
    //                              Shape.cpp:1784 (4)
    //         004ba856     MOV        this,dword ptr [ESP + param_1]
    //                               LAB_004ba85a                                                 XREF[2]:     004ba7ae(j), 004ba7bc(j)  
    //                              Shape.cpp:1785 (21)
    //         004ba85a     MOV        EDI,dword ptr [ESP + param_5]
    //         004ba85e     AND        EDI,0xff
    //         004ba864     SUB        EDI,0x0
    //         004ba867     JZ         LAB_004ba8c6
    //         004ba869     DEC        EDI
    //         004ba86a     JZ         LAB_004ba898
    //         004ba86c     DEC        EDI
    //         004ba86d     JNZ        LAB_004ba8e6
    //                              Shape.cpp:1797 (6)
    //         004ba86f     MOV        EDI,dword ptr [ESP + param_6]
    //         004ba873     TEST       EDI,EDI
    //                              Shape.cpp:1799 (2)
    //         004ba875     JZ         LAB_004ba8c6
    //                              Shape.cpp:1800 (23)
    //         004ba877     PUSH       EDI
    //         004ba878     MOV        EDI,dword ptr [ESP + param_3]
    //         004ba87c     PUSH       EDI
    //         004ba87d     PUSH       this
    //         004ba87e     MOV        this,dword ptr [ESP + param_2]
    //         004ba882     PUSH       EBX
    //         004ba883     PUSH       this
    //         004ba884     PUSH       EAX
    //         004ba885     PUSH       EDX
    //         004ba886     PUSH       EBP
    //         004ba887     MOV        this,ESI
    //         004ba889     CALL       TShape::shape_mirror_shadow_clipped              uchar shape_mirror_shadow_clipped(TShape * th
    //                              Shape.cpp:1805 (10)
    //         004ba88e     POP        EDI
    //         004ba88f     POP        ESI
    //         004ba890     POP        EBP
    //         004ba891     POP        EBX
    //         004ba892     ADD        ESP,0x1c
    //         004ba895     RET        0x18
    //                               LAB_004ba898                                                 XREF[1]:     004ba86a(j)  
    //                              Shape.cpp:1791 (6)
    //         004ba898     MOV        EDI,dword ptr [ESP + param_6]
    //         004ba89c     TEST       EDI,EDI
    //                              Shape.cpp:1793 (2)
    //         004ba89e     JZ         LAB_004ba8c6
    //                              Shape.cpp:1794 (28)
    //         004ba8a0     PUSH       EDI
    //         004ba8a1     MOV        EDI,dword ptr [ESP + param_3]
    //         004ba8a5     PUSH       EDI
    //         004ba8a6     PUSH       this
    //         004ba8a7     MOV        this,dword ptr [ESP + param_2]
    //         004ba8ab     PUSH       EBX
    //         004ba8ac     PUSH       this
    //         004ba8ad     MOV        this,dword ptr [ESP + param_4]
    //         004ba8b1     PUSH       this
    //         004ba8b2     PUSH       EAX
    //         004ba8b3     PUSH       EDX
    //         004ba8b4     PUSH       EBP
    //         004ba8b5     MOV        this,ESI
    //         004ba8b7     CALL       TShape::shape_mirror_color_trans_clipped         uchar shape_mirror_color_trans_clipped(TShape
    //                              Shape.cpp:1805 (10)
    //         004ba8bc     POP        EDI
    //         004ba8bd     POP        ESI
    //         004ba8be     POP        EBP
    //         004ba8bf     POP        EBX
    //         004ba8c0     ADD        ESP,0x1c
    //         004ba8c3     RET        0x18
    //                               LAB_004ba8c6                                                 XREF[3]:     004ba867(j), 004ba875(j), 
    //                                                                                                         004ba89e(j)  
    //                              Shape.cpp:1788 (22)
    //         004ba8c6     MOV        EDI,dword ptr [ESP + param_3]
    //         004ba8ca     PUSH       EDI
    //         004ba8cb     PUSH       this
    //         004ba8cc     MOV        this,dword ptr [ESP + param_2]
    //         004ba8d0     PUSH       EBX
    //         004ba8d1     PUSH       this
    //         004ba8d2     PUSH       EAX
    //         004ba8d3     PUSH       EDX
    //         004ba8d4     PUSH       EBP
    //         004ba8d5     MOV        this,ESI
    //         004ba8d7     CALL       TShape::shape_mirror_clipped                     uchar shape_mirror_clipped(TShape * this, TDr
    //                              Shape.cpp:1805 (10)
    //         004ba8dc     POP        EDI
    //         004ba8dd     POP        ESI
    //         004ba8de     POP        EBP
    //         004ba8df     POP        EBX
    //         004ba8e0     ADD        ESP,0x1c
    //         004ba8e3     RET        0x18
    //                               LAB_004ba8e6                                                 XREF[2]:     004ba7d5(j), 004ba86d(j)  
    //                              Shape.cpp:1788 (4)
    //         004ba8e6     MOV        AL,byte ptr [ESP + clip_y0+0x3]
    //                              Shape.cpp:1805 (22)
    //         004ba8ea     POP        EDI
    //         004ba8eb     POP        ESI
    //         004ba8ec     POP        EBP
    //         004ba8ed     POP        EBX
    //         004ba8ee     ADD        ESP,0x1c
    //         004ba8f1     RET        0x18
    //                               LAB_004ba8f4                                                 XREF[5]:     004ba564(j), 004ba577(j), 
    //                                                                                                         004ba6c6(j), 004ba780(j), 
    //                                                                                                         004ba790(j)  
    //         004ba8f4     POP        EDI
    //         004ba8f5     POP        ESI
    //         004ba8f6     POP        EBP
    //         004ba8f7     XOR        AL,AL
    //         004ba8f9     POP        EBX
    //         004ba8fa     ADD        ESP,0x1c
    //         004ba8fd     RET        0x18
}

// Offset: 0x004BA900
uchar shape_mirror_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_mirror_unclipped(class TDrawArea *,long,long)         *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror_unclipped(TShape * this, TDrawArea * p
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004ba904(R), 004ba958(W), 004ba9c2(R), 004ba9cd(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     004ba948(R), 004ba952(W), 004ba9be(R), 004ba9c9(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     004ba92d(R), 004ba93e(R), 004ba96d(W), 004ba97f(R), 
    //                                                                                     004ba995(W), 004ba99f(R)  
    //                               ?shape_mirror_unclipped@TShape@@AAEEPAVTDrawArea@@JJ@Z       XREF[3]:     shape_mirror:004ba7e8(c), 
    //                               TShape::shape_mirror_unclipped                                            shape_mirror:004ba819(c), 
    //                                                                                                         shape_mirror:004ba847(c)  
    //                              Shape.cpp:1809 (4)
    //         004ba900     PUSH       EBX
    //         004ba901     PUSH       EBP
    //         004ba902     PUSH       ESI
    //         004ba903     PUSH       EDI
    //                              Shape.cpp:1810 (16)
    //         004ba904     MOV        EDI,dword ptr [ESP + param_1]
    //         004ba908     MOV        ESI,this
    //         004ba90a     MOV        this,EDI
    //         004ba90c     MOV        EBX,dword ptr [EDI + 0x24]
    //         004ba90f     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //                              Shape.cpp:1811 (16)
    //         004ba914     MOV        this,dword ptr [ESI + 0xc]
    //         004ba917     MOV        EBP,EAX
    //         004ba919     IMUL       EBP,EBX
    //         004ba91c     MOV        EAX,dword ptr [ECX + this->offsets]
    //         004ba91f     MOV        ESI,dword ptr [ECX + this->shape_header]
    //         004ba922     SUB        EAX,ESI
    //                              Shape.cpp:1813 (4)
    //         004ba924     LEA        ESI,[ECX + this->FShape]
    //         004ba927     INC        EAX
    //                              Shape.cpp:1822 (5)
    //         004ba928     CMP        EBX,0x1
    //         004ba92b     JGE        LAB_004ba93c
    //                              Shape.cpp:1823 (13)
    //         004ba92d     MOV        this,dword ptr [ESP + param_3]
    //         004ba931     MOV        EDX,dword ptr [EDI + 0x1c]
    //         004ba934     SUB        this,EDX
    //         004ba936     INC        this
    //         004ba937     IMUL       this,EBP
    //                              Shape.cpp:1824 (2)
    //         004ba93a     JMP        LAB_004ba943
    //                               LAB_004ba93c                                                 XREF[1]:     004ba92b(j)  
    //                              Shape.cpp:1825 (16)
    //         004ba93c     MOV        this,EBP
    //         004ba93e     IMUL       this,dword ptr [ESP + param_3]
    //                               LAB_004ba943                                                 XREF[1]:     004ba93a(j)  
    //         004ba943     MOV        EDX,dword ptr [EDI + 0x8]
    //         004ba946     ADD        this,EDX
    //         004ba948     MOV        EDX,dword ptr [ESP + param_2]
    //                              Shape.cpp:1828 (12)
    //         004ba94c     TEST       EAX,EAX
    //         004ba94e     LEA        EDI,[ECX + EDX*this+0x1 + 0x1]
    //         004ba952     MOV        dword ptr [ESP + param_2],EDI
    //         004ba956     JLE        LAB_004ba9d3
    //                              Shape.cpp:1826 (4)
    //         004ba958     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_004ba95c                                                 XREF[1]:     004ba9d1(j)  
    //                              Shape.cpp:1830 (2)
    //         004ba95c     XOR        BL,BL
    //                               LAB_004ba95e                                                 XREF[1]:     004ba9bc(j)  
    //                              Shape.cpp:1833 (2)
    //         004ba95e     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:1834 (1)
    //         004ba960     INC        ESI
    //                              Shape.cpp:1835 (10)
    //         004ba961     MOV        this,AL
    //         004ba963     AND        this,0x1
    //         004ba966     CMP        this,0x1
    //         004ba969     JNZ        LAB_004ba993
    //                              Shape.cpp:1837 (6)
    //         004ba96b     SHR        AL,0x1
    //         004ba96d     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:1838 (2)
    //         004ba971     JNZ        LAB_004ba97b
    //                              Shape.cpp:1840 (6)
    //         004ba973     XOR        EDX,EDX
    //         004ba975     MOV        DL,byte ptr [ESI]
    //         004ba977     SUB        EDI,EDX
    //                              Shape.cpp:1843 (2)
    //         004ba979     JMP        LAB_004ba9b9
    //                               LAB_004ba97b                                                 XREF[1]:     004ba971(j)  
    //                              Shape.cpp:1847 (4)
    //         004ba97b     TEST       AL,AL
    //         004ba97d     JBE        LAB_004ba9ba
    //                              Shape.cpp:1874 (18)
    //         004ba97f     MOV        EAX,dword ptr [ESP + param_3]
    //         004ba983     AND        EAX,0xff
    //                               LAB_004ba988                                                 XREF[1]:     004ba98f(j)  
    //         004ba988     MOV        this,byte ptr [ESI]
    //         004ba98a     DEC        EDI
    //         004ba98b     INC        ESI
    //         004ba98c     DEC        EAX
    //         004ba98d     MOV        byte ptr [EDI],this
    //         004ba98f     JNZ        LAB_004ba988
    //                              Shape.cpp:1856 (2)
    //         004ba991     JMP        LAB_004ba9ba
    //                               LAB_004ba993                                                 XREF[1]:     004ba969(j)  
    //                              Shape.cpp:1858 (6)
    //         004ba993     SHR        AL,0x1
    //         004ba995     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:1859 (2)
    //         004ba999     JNZ        LAB_004ba99f
    //                              Shape.cpp:1860 (2)
    //         004ba99b     MOV        BL,0x1
    //                              Shape.cpp:1861 (2)
    //         004ba99d     JMP        LAB_004ba9ba
    //                               LAB_004ba99f                                                 XREF[1]:     004ba999(j)  
    //                              Shape.cpp:1863 (4)
    //         004ba99f     MOV        EAX,dword ptr [ESP + param_3]
    //                              Shape.cpp:1864 (22)
    //         004ba9a3     XOR        EDX,EDX
    //         004ba9a5     MOV        DL,byte ptr [ESI]
    //         004ba9a7     AND        EAX,0xff
    //         004ba9ac     SUB        EDI,EAX
    //         004ba9ae     PUSH       EAX
    //         004ba9af     PUSH       EDX
    //         004ba9b0     PUSH       EDI
    //         004ba9b1     CALL       memset                                           undefined memset()
    //         004ba9b6     ADD        ESP,0xc
    //                               LAB_004ba9b9                                                 XREF[1]:     004ba979(j)  
    //                              Shape.cpp:1865 (1)
    //         004ba9b9     INC        ESI
    //                               LAB_004ba9ba                                                 XREF[3]:     004ba97d(j), 004ba991(j), 
    //                                                                                                         004ba99d(j)  
    //                              Shape.cpp:1831 (4)
    //         004ba9ba     TEST       BL,BL
    //         004ba9bc     JZ         LAB_004ba95e
    //                              Shape.cpp:1869 (21)
    //         004ba9be     MOV        EDI,dword ptr [ESP + param_2]
    //         004ba9c2     MOV        EAX,dword ptr [ESP + param_1]
    //         004ba9c6     ADD        EDI,EBP
    //         004ba9c8     DEC        EAX
    //         004ba9c9     MOV        dword ptr [ESP + param_2],EDI
    //         004ba9cd     MOV        dword ptr [ESP + param_1],EAX
    //         004ba9d1     JNZ        LAB_004ba95c
    //                               LAB_004ba9d3                                                 XREF[1]:     004ba956(j)  
    //                              Shape.cpp:1874 (9)
    //         004ba9d3     POP        EDI
    //         004ba9d4     POP        ESI
    //         004ba9d5     POP        EBP
    //         004ba9d6     MOV        AL,0x1
    //         004ba9d8     POP        EBX
    //         004ba9d9     RET        0xc
}

// Offset: 0x004BA9E0
uchar shape_mirror_color_trans_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, uchar* param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_mirror_color_trans_unclipped(class TDrawArea *,lon... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror_color_trans_unclipped(TShape * this, T
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004ba9e5(R), 004baa50(W), 004baaca(R), 004baad5(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     004baa24(R), 004baa38(R), 004baa42(W), 004baac2(R), 
    //                                                                                     004baad1(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     004baa12(R), 004baa2e(R), 004baa65(W), 004baa77(R), 
    //                                                                                     004baa93(W), 004baa9d(R)  
    //              long              Stack[0x10]:4  param_4
    //              uchar *           Stack[0x14]:4  param_5                   XREF[1]:     004baa4c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004baa05(W), 004baac6(R)  
    //              long              Stack[-0x8]:4  width
    //                               ?shape_mirror_color_trans_unclipped@TShape@@AAEEPAVTDrawAre  XREF[1]:     shape_mirror:004ba833(c)  
    //                               TShape::shape_mirror_color_trans_unclipped
    //                              Shape.cpp:1878 (5)
    //         004ba9e0     PUSH       this
    //         004ba9e1     PUSH       EBX
    //         004ba9e2     PUSH       EBP
    //         004ba9e3     PUSH       ESI
    //         004ba9e4     PUSH       EDI
    //                              Shape.cpp:1879 (16)
    //         004ba9e5     MOV        EDI,dword ptr [ESP + param_1]
    //         004ba9e9     MOV        ESI,this
    //         004ba9eb     MOV        this,EDI
    //         004ba9ed     MOV        EBP,dword ptr [EDI + 0x24]
    //         004ba9f0     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //                              Shape.cpp:1880 (21)
    //         004ba9f5     MOV        this,dword ptr [ESI + 0xc]
    //         004ba9f8     MOV        EDX,EAX
    //         004ba9fa     IMUL       EDX,EBP
    //         004ba9fd     MOV        EAX,dword ptr [ECX + this->offsets]
    //         004baa00     MOV        EBX,dword ptr [ECX + this->shape_header]
    //         004baa03     SUB        EAX,EBX
    //         004baa05     MOV        dword ptr [ESP + local_4],EDX
    //         004baa09     INC        EAX
    //                              Shape.cpp:1890 (8)
    //         004baa0a     CMP        EBP,0x1
    //         004baa0d     LEA        ESI,[ECX + this->FShape]
    //         004baa10     JGE        LAB_004baa2e
    //                              Shape.cpp:1891 (26)
    //         004baa12     MOV        this,dword ptr [ESP + param_3]
    //         004baa16     MOV        EBP,dword ptr [EDI + 0x1c]
    //         004baa19     SUB        this,EBP
    //         004baa1b     INC        this
    //         004baa1c     IMUL       this,EDX
    //         004baa1f     MOV        EDX,dword ptr [EDI + 0x8]
    //         004baa22     ADD        this,EDX
    //         004baa24     MOV        EDX,dword ptr [ESP + param_2]
    //         004baa28     LEA        EDI,[ECX + EDX*this+0x1 + 0x1]
    //                              Shape.cpp:1892 (2)
    //         004baa2c     JMP        LAB_004baa40
    //                               LAB_004baa2e                                                 XREF[1]:     004baa10(j)  
    //                              Shape.cpp:1893 (18)
    //         004baa2e     IMUL       EDX,dword ptr [ESP + param_3]
    //         004baa33     MOV        this,dword ptr [EDI + 0x8]
    //         004baa36     ADD        EDX,this
    //         004baa38     MOV        this,dword ptr [ESP + param_2]
    //         004baa3c     LEA        EDI,[EDX + this->shape*0x1 + 0x1]
    //                               LAB_004baa40                                                 XREF[1]:     004baa2c(j)  
    //                              Shape.cpp:1896 (20)
    //         004baa40     TEST       EAX,EAX
    //         004baa42     MOV        dword ptr [ESP + param_2],EDI
    //         004baa46     JLE        LAB_004baadf
    //         004baa4c     MOV        EBP,dword ptr [ESP + param_5]
    //         004baa50     MOV        dword ptr [ESP + param_1],EAX
    //                               LAB_004baa54                                                 XREF[1]:     004baad9(j)  
    //                              Shape.cpp:1898 (2)
    //         004baa54     XOR        BL,BL
    //                               LAB_004baa56                                                 XREF[1]:     004baac0(j)  
    //                              Shape.cpp:1901 (2)
    //         004baa56     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:1902 (1)
    //         004baa58     INC        ESI
    //                              Shape.cpp:1903 (10)
    //         004baa59     MOV        DL,AL
    //         004baa5b     AND        DL,0x1
    //         004baa5e     CMP        DL,0x1
    //         004baa61     JNZ        LAB_004baa91
    //                              Shape.cpp:1905 (6)
    //         004baa63     SHR        AL,0x1
    //         004baa65     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:1906 (2)
    //         004baa69     JNZ        LAB_004baa73
    //                              Shape.cpp:1908 (6)
    //         004baa6b     XOR        EAX,EAX
    //         004baa6d     MOV        AL,byte ptr [ESI]
    //         004baa6f     SUB        EDI,EAX
    //                              Shape.cpp:1911 (2)
    //         004baa71     JMP        LAB_004baabd
    //                               LAB_004baa73                                                 XREF[1]:     004baa69(j)  
    //                              Shape.cpp:1913 (4)
    //         004baa73     TEST       AL,AL
    //         004baa75     JBE        LAB_004baabe
    //                              Shape.cpp:1939 (24)
    //         004baa77     MOV        EAX,dword ptr [ESP + param_3]
    //         004baa7b     AND        EAX,0xff
    //                               LAB_004baa80                                                 XREF[1]:     004baa8d(j)  
    //         004baa80     XOR        this,this
    //         004baa82     DEC        EDI
    //         004baa83     MOV        this,byte ptr [ESI]
    //         004baa85     INC        ESI
    //         004baa86     DEC        EAX
    //         004baa87     MOV        DL,byte ptr [EBP + this->shape*0x1]
    //         004baa8b     MOV        byte ptr [EDI],DL
    //         004baa8d     JNZ        LAB_004baa80
    //                              Shape.cpp:1921 (2)
    //         004baa8f     JMP        LAB_004baabe
    //                               LAB_004baa91                                                 XREF[1]:     004baa61(j)  
    //                              Shape.cpp:1923 (6)
    //         004baa91     SHR        AL,0x1
    //         004baa93     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:1924 (2)
    //         004baa97     JNZ        LAB_004baa9d
    //                              Shape.cpp:1925 (2)
    //         004baa99     MOV        BL,0x1
    //                              Shape.cpp:1926 (2)
    //         004baa9b     JMP        LAB_004baabe
    //                               LAB_004baa9d                                                 XREF[1]:     004baa97(j)  
    //                              Shape.cpp:1928 (4)
    //         004baa9d     MOV        EAX,dword ptr [ESP + param_3]
    //                              Shape.cpp:1929 (28)
    //         004baaa1     XOR        this,this
    //         004baaa3     AND        EAX,0xff
    //         004baaa8     SUB        EDI,EAX
    //         004baaaa     PUSH       EAX
    //         004baaab     XOR        EAX,EAX
    //         004baaad     MOV        AL,byte ptr [ESI]
    //         004baaaf     MOV        this,byte ptr [EBP + EAX*0x1]
    //         004baab3     PUSH       this
    //         004baab4     PUSH       EDI
    //         004baab5     CALL       memset                                           undefined memset()
    //         004baaba     ADD        ESP,0xc
    //                               LAB_004baabd                                                 XREF[1]:     004baa71(j)  
    //                              Shape.cpp:1930 (1)
    //         004baabd     INC        ESI
    //                               LAB_004baabe                                                 XREF[3]:     004baa75(j), 004baa8f(j), 
    //                                                                                                         004baa9b(j)  
    //                              Shape.cpp:1899 (4)
    //         004baabe     TEST       BL,BL
    //         004baac0     JZ         LAB_004baa56
    //                              Shape.cpp:1934 (29)
    //         004baac2     MOV        EDI,dword ptr [ESP + param_2]
    //         004baac6     MOV        this,dword ptr [ESP + local_4]
    //         004baaca     MOV        EAX,dword ptr [ESP + param_1]
    //         004baace     ADD        EDI,this
    //         004baad0     DEC        EAX
    //         004baad1     MOV        dword ptr [ESP + param_2],EDI
    //         004baad5     MOV        dword ptr [ESP + param_1],EAX
    //         004baad9     JNZ        LAB_004baa54
    //                               LAB_004baadf                                                 XREF[1]:     004baa46(j)  
    //                              Shape.cpp:1939 (10)
    //         004baadf     POP        EDI
    //         004baae0     POP        ESI
    //         004baae1     POP        EBP
    //         004baae2     MOV        AL,0x1
    //         004baae4     POP        EBX
    //         004baae5     POP        this
    //         004baae6     RET        0x14
}

// Offset: 0x004BAAF0
uchar shape_mirror_shadow_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, uchar* param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_mirror_shadow_unclipped(class TDrawArea *,long,lon... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror_shadow_unclipped(TShape * this, TDrawA
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004baaf4(R), 004bab5e(W), 004babdc(R), 004babe7(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[5]:     004bab32(R), 004bab46(R), 004bab50(W), 004babd4(R), 
    //                                                                                     004babe3(W)  
    //              long              Stack[0xc]:4   param_3                   XREF[6]:     004bab20(R), 004bab3c(R), 004bab72(W), 004bab81(R), 
    //                                                                                     004babaa(W), 004babb8(R)  
    //              uchar *           Stack[0x10]:4  param_4                   XREF[1]:     004bab5a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004bab0b(W), 004babd8(R)  
    //              long              Stack[-0x8]:4  width
    //                               ?shape_mirror_shadow_unclipped@TShape@@AAEEPAVTDrawArea@@JJ  XREF[1]:     shape_mirror:004ba7fd(c)  
    //                               TShape::shape_mirror_shadow_unclipped
    //                              Shape.cpp:1943 (4)
    //         004baaf0     PUSH       this
    //         004baaf1     PUSH       EBX
    //         004baaf2     PUSH       EBP
    //         004baaf3     PUSH       ESI
    //                              Shape.cpp:1944 (20)
    //         004baaf4     MOV        ESI,dword ptr [ESP + param_1]
    //         004baaf8     MOV        EBX,this
    //         004baafa     PUSH       EDI
    //         004baafb     MOV        EDI,dword ptr [ESI + 0x24]
    //         004baafe     MOV        this,ESI
    //         004bab00     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004bab05     IMUL       EAX,EDI
    //                              Shape.cpp:1945 (15)
    //         004bab08     MOV        this,dword ptr [EBX + 0xc]
    //         004bab0b     MOV        dword ptr [ESP + local_4],EAX
    //         004bab0f     MOV        EDX,dword ptr [ECX + this->offsets]
    //         004bab12     MOV        EBP,dword ptr [ECX + this->shape_header]
    //         004bab15     SUB        EDX,EBP
    //                              Shape.cpp:1947 (4)
    //         004bab17     LEA        EBP,[ECX + this->FShape]
    //         004bab1a     INC        EDX
    //                              Shape.cpp:1954 (5)
    //         004bab1b     CMP        EDI,0x1
    //         004bab1e     JGE        LAB_004bab3c
    //                              Shape.cpp:1955 (26)
    //         004bab20     MOV        this,dword ptr [ESP + param_3]
    //         004bab24     MOV        EBX,dword ptr [ESI + 0x1c]
    //         004bab27     SUB        this,EBX
    //         004bab29     INC        this
    //         004bab2a     IMUL       this,EAX
    //         004bab2d     MOV        EAX,dword ptr [ESI + 0x8]
    //         004bab30     ADD        this,EAX
    //         004bab32     MOV        EAX,dword ptr [ESP + param_2]
    //         004bab36     LEA        this,[ECX + EAX*this+0x1 + 0x1]
    //                              Shape.cpp:1956 (2)
    //         004bab3a     JMP        LAB_004bab4e
    //                               LAB_004bab3c                                                 XREF[1]:     004bab1e(j)  
    //                              Shape.cpp:1957 (18)
    //         004bab3c     IMUL       EAX,dword ptr [ESP + param_3]
    //         004bab41     MOV        this,dword ptr [ESI + 0x8]
    //         004bab44     ADD        EAX,this
    //         004bab46     MOV        this,dword ptr [ESP + param_2]
    //         004bab4a     LEA        this,[EAX + this->shape*0x1 + 0x1]
    //                               LAB_004bab4e                                                 XREF[1]:     004bab3a(j)  
    //                              Shape.cpp:1960 (20)
    //         004bab4e     TEST       EDX,EDX
    //         004bab50     MOV        dword ptr [ESP + param_2],this
    //         004bab54     JLE        LAB_004babf1
    //         004bab5a     MOV        EDI,dword ptr [ESP + param_4]
    //         004bab5e     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_004bab62                                                 XREF[1]:     004babeb(j)  
    //                              Shape.cpp:1962 (2)
    //         004bab62     XOR        BL,BL
    //                               LAB_004bab64                                                 XREF[1]:     004babd2(j)  
    //                              Shape.cpp:1965 (3)
    //         004bab64     MOV        DL,byte ptr [EBP]
    //                              Shape.cpp:1966 (1)
    //         004bab67     INC        EBP
    //                              Shape.cpp:1967 (8)
    //         004bab68     MOV        AL,DL
    //         004bab6a     AND        AL,0x1
    //         004bab6c     CMP        AL,0x1
    //         004bab6e     JNZ        LAB_004baba8
    //                              Shape.cpp:1969 (6)
    //         004bab70     SHR        DL,0x1
    //         004bab72     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:1970 (2)
    //         004bab76     JNZ        LAB_004bab81
    //                              Shape.cpp:1972 (7)
    //         004bab78     XOR        EDX,EDX
    //         004bab7a     MOV        DL,byte ptr [EBP]
    //         004bab7d     SUB        this,EDX
    //                              Shape.cpp:1975 (2)
    //         004bab7f     JMP        LAB_004babcf
    //                               LAB_004bab81                                                 XREF[1]:     004bab76(j)  
    //                              Shape.cpp:1977 (8)
    //         004bab81     MOV        ESI,dword ptr [ESP + param_3]
    //         004bab85     TEST       DL,DL
    //         004bab87     JBE        LAB_004bab9e
    //                              Shape.cpp:2006 (21)
    //         004bab89     MOV        EDX,ESI
    //         004bab8b     AND        EDX,0xff
    //                               LAB_004bab91                                                 XREF[1]:     004bab9c(j)  
    //         004bab91     DEC        this
    //         004bab92     XOR        EAX,EAX
    //         004bab94     DEC        EDX
    //         004bab95     MOV        AL,byte ptr [this->shape]
    //         004bab97     MOV        AL,byte ptr [EDI + EAX*0x1]
    //         004bab9a     MOV        byte ptr [this->shape],AL
    //         004bab9c     JNZ        LAB_004bab91
    //                               LAB_004bab9e                                                 XREF[1]:     004bab87(j)  
    //                              Shape.cpp:1982 (8)
    //         004bab9e     AND        ESI,0xff
    //         004baba4     ADD        EBP,ESI
    //                              Shape.cpp:1985 (2)
    //         004baba6     JMP        LAB_004babd0
    //                               LAB_004baba8                                                 XREF[1]:     004bab6e(j)  
    //                              Shape.cpp:1987 (6)
    //         004baba8     SHR        DL,0x1
    //         004babaa     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:1988 (2)
    //         004babae     JNZ        LAB_004babb4
    //                              Shape.cpp:1989 (2)
    //         004babb0     MOV        BL,0x1
    //                              Shape.cpp:1990 (2)
    //         004babb2     JMP        LAB_004babd0
    //                               LAB_004babb4                                                 XREF[1]:     004babae(j)  
    //                              Shape.cpp:1992 (4)
    //         004babb4     TEST       DL,DL
    //         004babb6     JBE        LAB_004babcf
    //                              Shape.cpp:2006 (23)
    //         004babb8     MOV        EDX,dword ptr [ESP + param_3]
    //         004babbc     AND        EDX,0xff
    //                               LAB_004babc2                                                 XREF[1]:     004babcd(j)  
    //         004babc2     DEC        this
    //         004babc3     XOR        EAX,EAX
    //         004babc5     DEC        EDX
    //         004babc6     MOV        AL,byte ptr [this->shape]
    //         004babc8     MOV        AL,byte ptr [EDI + EAX*0x1]
    //         004babcb     MOV        byte ptr [this->shape],AL
    //         004babcd     JNZ        LAB_004babc2
    //                               LAB_004babcf                                                 XREF[2]:     004bab7f(j), 004babb6(j)  
    //                              Shape.cpp:1997 (1)
    //         004babcf     INC        EBP
    //                               LAB_004babd0                                                 XREF[2]:     004baba6(j), 004babb2(j)  
    //                              Shape.cpp:1963 (4)
    //         004babd0     TEST       BL,BL
    //         004babd2     JZ         LAB_004bab64
    //                              Shape.cpp:2001 (29)
    //         004babd4     MOV        this,dword ptr [ESP + param_2]
    //         004babd8     MOV        EDX,dword ptr [ESP + local_4]
    //         004babdc     MOV        EAX,dword ptr [ESP + param_1]
    //         004babe0     ADD        this,EDX
    //         004babe2     DEC        EAX
    //         004babe3     MOV        dword ptr [ESP + param_2],this
    //         004babe7     MOV        dword ptr [ESP + param_1],EAX
    //         004babeb     JNZ        LAB_004bab62
    //                               LAB_004babf1                                                 XREF[1]:     004bab54(j)  
    //                              Shape.cpp:2006 (10)
    //         004babf1     POP        EDI
    //         004babf2     POP        ESI
    //         004babf3     POP        EBP
    //         004babf4     MOV        AL,0x1
    //         004babf6     POP        EBX
    //         004babf7     POP        this
    //         004babf8     RET        0x10
}

// Offset: 0x004BAC00
uchar shape_mirror_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_mirror_clipped(class TDrawArea *,long,long,long,lo... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror_clipped(TShape * this, TDrawArea * par
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[7]:     004bac07(R), 004bac67(W), 004bac9f(R), 004baca4(W), 
    //                                                                                     004bae43(W), 004bae4e(R), 004bae53(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004bacbd(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     004bac57(R), 004bacb9(W), 004baefe(R), 004baf09(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[9]:     004bacf3(R), 004bad1d(R), 004bad25(R), 004bad4d(R), 
    //                                                                                     004bad99(R), 004bae03(R), 004bae1b(R), 004bae2b(R), 
    //                                                                                     004bae83(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[14]:    004bac1f(R), 004bac7f(W), 004bac85(R), 004bacde(W), 
    //                                                                                     004bad0d(R), 004bad80(W), 004bad8a(R), 004badf5(W), 
    //                                                                                     004bae17(R), 004bae5f(R), 004bae75(W), 004bae7f(R), 
    //                                                                                     004baed6(W), 004baedc(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[6]:     004bac36(R), 004bac4f(R), 004bad2d(R), 004bad55(R), 
    //                                                                                     004badc6(R), 004baeb7(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     004bacaa(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004bac29(W), 004baefa(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004bac5b(W), 004baef6(R), 004baf05(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer
    //                               ?shape_mirror_clipped@TShape@@AAEEPAVTDrawArea@@JJJJJJ@Z     XREF[1]:     shape_mirror:004ba8d7(c)  
    //                               TShape::shape_mirror_clipped
    //                              Shape.cpp:2010 (7)
    //         004bac00     SUB        ESP,0x8
    //         004bac03     PUSH       EBX
    //         004bac04     PUSH       EBP
    //         004bac05     PUSH       ESI
    //         004bac06     PUSH       EDI
    //                              Shape.cpp:2011 (18)
    //         004bac07     MOV        EDI,dword ptr [ESP + param_1]
    //         004bac0b     MOV        ESI,this
    //         004bac0d     MOV        this,EDI
    //         004bac0f     MOV        EBX,dword ptr [EDI + 0x24]
    //         004bac12     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004bac17     MOV        this,EAX
    //                              Shape.cpp:2016 (6)
    //         004bac19     MOV        ESI,dword ptr [ESI + 0xc]
    //         004bac1c     IMUL       this,EBX
    //                              Shape.cpp:2024 (38)
    //         004bac1f     MOV        EAX,dword ptr [ESP + param_5]
    //         004bac23     ADD        ESI,0x18
    //         004bac26     CMP        EBX,0x1
    //         004bac29     MOV        dword ptr [ESP + local_4],this
    //         004bac2d     JGE        LAB_004bac47
    //         004bac2f     MOV        EBP,dword ptr [EDI + 0x1c]
    //         004bac32     MOV        EBX,EAX
    //         004bac34     SUB        EBX,EBP
    //         004bac36     MOV        EDX,dword ptr [ESP + param_6]
    //         004bac3a     INC        EBX
    //         004bac3b     IMUL       EBX,this
    //         004bac3e     ADD        EBX,dword ptr [EDI + 0x8]
    //         004bac41     LEA        EBP,[EBX + EDX*0x1 + 0x1]
    //                              Shape.cpp:2025 (2)
    //         004bac45     JMP        LAB_004bac57
    //                               LAB_004bac47                                                 XREF[1]:     004bac2d(j)  
    //                              Shape.cpp:2026 (16)
    //         004bac47     IMUL       this,EAX
    //         004bac4a     MOV        EDX,dword ptr [EDI + 0x8]
    //         004bac4d     ADD        this,EDX
    //         004bac4f     MOV        EDX,dword ptr [ESP + param_6]
    //         004bac53     LEA        EBP,[ECX + EDX*this+0x1 + 0x1]
    //                               LAB_004bac57                                                 XREF[1]:     004bac45(j)  
    //                              Shape.cpp:2030 (23)
    //         004bac57     MOV        this,dword ptr [ESP + param_3]
    //         004bac5b     MOV        dword ptr [ESP + width],EBP
    //         004bac5f     CMP        this,EAX
    //         004bac61     MOV        EDI,this
    //         004bac63     JGE        LAB_004bacaa
    //         004bac65     SUB        EAX,this
    //         004bac67     MOV        dword ptr [ESP + param_1],EAX
    //         004bac6b     LEA        EDI,[this->shape + EAX*0x1]
    //                               LAB_004bac6e                                                 XREF[1]:     004baca8(j)  
    //                              Shape.cpp:2032 (2)
    //         004bac6e     XOR        this,this
    //                               LAB_004bac70                                                 XREF[1]:     004bac9d(j)  
    //                              Shape.cpp:2035 (2)
    //         004bac70     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2036 (1)
    //         004bac72     INC        ESI
    //                              Shape.cpp:2037 (10)
    //         004bac73     MOV        BL,AL
    //         004bac75     AND        BL,0x1
    //         004bac78     CMP        BL,0x1
    //         004bac7b     JNZ        LAB_004bac92
    //                              Shape.cpp:2039 (6)
    //         004bac7d     SHR        AL,0x1
    //         004bac7f     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:2042 (2)
    //         004bac83     JZ         LAB_004bac9a
    //                              Shape.cpp:2043 (11)
    //         004bac85     MOV        EAX,dword ptr [ESP + param_5]
    //         004bac89     AND        EAX,0xff
    //         004bac8e     ADD        ESI,EAX
    //                              Shape.cpp:2045 (2)
    //         004bac90     JMP        LAB_004bac9b
    //                               LAB_004bac92                                                 XREF[1]:     004bac7b(j)  
    //                              Shape.cpp:2048 (4)
    //         004bac92     TEST       AL,0xfe
    //         004bac94     JNZ        LAB_004bac9a
    //                              Shape.cpp:2049 (2)
    //         004bac96     MOV        this,0x1
    //                              Shape.cpp:2050 (2)
    //         004bac98     JMP        LAB_004bac9b
    //                               LAB_004bac9a                                                 XREF[2]:     004bac83(j), 004bac94(j)  
    //                              Shape.cpp:2051 (1)
    //         004bac9a     INC        ESI
    //                               LAB_004bac9b                                                 XREF[2]:     004bac90(j), 004bac98(j)  
    //                              Shape.cpp:2033 (15)
    //         004bac9b     TEST       this,this
    //         004bac9d     JZ         LAB_004bac70
    //         004bac9f     MOV        EAX,dword ptr [ESP + param_1]
    //         004baca3     DEC        EAX
    //         004baca4     MOV        dword ptr [ESP + param_1],EAX
    //         004baca8     JNZ        LAB_004bac6e
    //                               LAB_004bacaa                                                 XREF[1]:     004bac63(j)  
    //                              Shape.cpp:2057 (19)
    //         004bacaa     MOV        EAX,dword ptr [ESP + param_7]
    //         004bacae     CMP        EDI,EAX
    //         004bacb0     JG         LAB_004baf13
    //         004bacb6     SUB        EAX,EDI
    //         004bacb8     INC        EAX
    //         004bacb9     MOV        dword ptr [ESP + param_3],EAX
    //                               LAB_004bacbd                                                 XREF[1]:     004baf0d(j)  
    //                              Shape.cpp:2059 (4)
    //         004bacbd     MOV        EDI,dword ptr [ESP + param_2]
    //                              Shape.cpp:2062 (8)
    //         004bacc1     CMP        EDI,EDX
    //         004bacc3     JLE        LAB_004badd8
    //                              Shape.cpp:2064 (2)
    //         004bacc9     XOR        BL,BL
    //                               LAB_004baccb                                                 XREF[1]:     004badd0(j)  
    //                              Shape.cpp:2067 (2)
    //         004baccb     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2068 (1)
    //         004baccd     INC        ESI
    //                              Shape.cpp:2069 (14)
    //         004bacce     MOV        this,AL
    //         004bacd0     AND        this,0x1
    //         004bacd3     CMP        this,0x1
    //         004bacd6     JNZ        LAB_004bad7e
    //                              Shape.cpp:2071 (6)
    //         004bacdc     SHR        AL,0x1
    //         004bacde     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:2072 (2)
    //         004bace2     JNZ        LAB_004bad0d
    //                              Shape.cpp:2074 (6)
    //         004bace4     XOR        EAX,EAX
    //         004bace6     MOV        AL,byte ptr [ESI]
    //         004bace8     SUB        EDI,EAX
    //                              Shape.cpp:2075 (1)
    //         004bacea     INC        ESI
    //                              Shape.cpp:2076 (8)
    //         004baceb     CMP        EDI,EDX
    //         004baced     JG         LAB_004badce
    //                              Shape.cpp:2078 (6)
    //         004bacf3     CMP        EDI,dword ptr [ESP + param_4]
    //         004bacf7     JGE        LAB_004bad00
    //                              Shape.cpp:2079 (2)
    //         004bacf9     MOV        BL,0x2
    //                              Shape.cpp:2080 (5)
    //         004bacfb     JMP        LAB_004badce
    //                               LAB_004bad00                                                 XREF[1]:     004bacf7(j)  
    //                              Shape.cpp:2083 (8)
    //         004bad00     MOV        this,EDI
    //         004bad02     MOV        BL,0x1
    //         004bad04     SUB        this,EDX
    //         004bad06     ADD        EBP,this
    //                              Shape.cpp:2087 (5)
    //         004bad08     JMP        LAB_004badce
    //                               LAB_004bad0d                                                 XREF[1]:     004bace2(j)  
    //                              Shape.cpp:2089 (12)
    //         004bad0d     MOV        this,dword ptr [ESP + param_5]
    //         004bad11     AND        this,0xff
    //         004bad17     SUB        EDI,this
    //                              Shape.cpp:2090 (4)
    //         004bad19     CMP        EDI,EDX
    //         004bad1b     JG         LAB_004bad7a
    //                              Shape.cpp:2092 (6)
    //         004bad1d     CMP        EDI,dword ptr [ESP + param_4]
    //         004bad21     JGE        LAB_004bad5b
    //                              Shape.cpp:2097 (8)
    //         004bad23     MOV        EAX,EDX
    //         004bad25     MOV        EDX,dword ptr [ESP + param_4]
    //         004bad29     SUB        EAX,EDX
    //                              Shape.cpp:2098 (11)
    //         004bad2b     MOV        EDX,EDI
    //         004bad2d     SUB        EDX,dword ptr [ESP + param_6]
    //         004bad31     INC        EAX
    //         004bad32     MOV        BL,0x2
    //         004bad34     ADD        EDX,this
    //                              Shape.cpp:2099 (8)
    //         004bad36     TEST       AL,AL
    //         004bad38     LEA        ESI,[ESI + EDX*0x1 + -0x1]
    //         004bad3c     JBE        LAB_004bad4d
    //                              Shape.cpp:2255 (5)
    //         004bad3e     AND        EAX,0xff
    //                               LAB_004bad43                                                 XREF[1]:     004bad4b(j)  
    //                              Shape.cpp:2102 (3)
    //         004bad43     MOV        this,byte ptr [ESI]
    //         004bad45     DEC        EBP
    //                              Shape.cpp:2103 (7)
    //         004bad46     INC        ESI
    //         004bad47     DEC        EAX
    //         004bad48     MOV        byte ptr [EBP],this
    //         004bad4b     JNZ        LAB_004bad43
    //                               LAB_004bad4d                                                 XREF[1]:     004bad3c(j)  
    //                              Shape.cpp:2105 (8)
    //         004bad4d     MOV        EDX,dword ptr [ESP + param_4]
    //         004bad51     SUB        EDX,EDI
    //         004bad53     ADD        ESI,EDX
    //                              Shape.cpp:2107 (6)
    //         004bad55     MOV        EDX,dword ptr [ESP + param_6]
    //         004bad59     JMP        LAB_004badce
    //                               LAB_004bad5b                                                 XREF[1]:     004bad21(j)  
    //                              Shape.cpp:2065 (2)
    //         004bad5b     MOV        EAX,EDX
    //                              Shape.cpp:2109 (4)
    //         004bad5d     MOV        BL,0x1
    //         004bad5f     SUB        EAX,EDI
    //                              Shape.cpp:2111 (4)
    //         004bad61     SUB        this,EAX
    //         004bad63     ADD        ESI,this
    //                              Shape.cpp:2112 (4)
    //         004bad65     TEST       AL,AL
    //         004bad67     JBE        LAB_004badce
    //                              Shape.cpp:2255 (5)
    //         004bad69     AND        EAX,0xff
    //                               LAB_004bad6e                                                 XREF[1]:     004bad76(j)  
    //                              Shape.cpp:2115 (3)
    //         004bad6e     MOV        this,byte ptr [ESI]
    //         004bad70     DEC        EBP
    //                              Shape.cpp:2116 (7)
    //         004bad71     INC        ESI
    //         004bad72     DEC        EAX
    //         004bad73     MOV        byte ptr [EBP],this
    //         004bad76     JNZ        LAB_004bad6e
    //                              Shape.cpp:2120 (2)
    //         004bad78     JMP        LAB_004badce
    //                               LAB_004bad7a                                                 XREF[1]:     004bad1b(j)  
    //                              Shape.cpp:2121 (2)
    //         004bad7a     ADD        ESI,this
    //                              Shape.cpp:2124 (2)
    //         004bad7c     JMP        LAB_004badce
    //                               LAB_004bad7e                                                 XREF[1]:     004bacd6(j)  
    //                              Shape.cpp:2126 (6)
    //         004bad7e     SHR        AL,0x1
    //         004bad80     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:2127 (2)
    //         004bad84     JNZ        LAB_004bad8a
    //                              Shape.cpp:2128 (2)
    //         004bad86     MOV        BL,0x3
    //                              Shape.cpp:2129 (2)
    //         004bad88     JMP        LAB_004badce
    //                               LAB_004bad8a                                                 XREF[1]:     004bad84(j)  
    //                              Shape.cpp:2131 (11)
    //         004bad8a     MOV        EAX,dword ptr [ESP + param_5]
    //         004bad8e     AND        EAX,0xff
    //         004bad93     SUB        EDI,EAX
    //                              Shape.cpp:2132 (4)
    //         004bad95     CMP        EDI,EDX
    //         004bad97     JG         LAB_004badcd
    //                              Shape.cpp:2134 (8)
    //         004bad99     MOV        this,dword ptr [ESP + param_4]
    //         004bad9d     CMP        EDI,this
    //         004bad9f     JGE        LAB_004badb2
    //                              Shape.cpp:2137 (7)
    //         004bada1     MOV        EAX,EDX
    //         004bada3     MOV        BL,0x2
    //         004bada5     SUB        EAX,this
    //         004bada7     INC        EAX
    //                              Shape.cpp:2138 (2)
    //         004bada8     SUB        EBP,EAX
    //                              Shape.cpp:2139 (6)
    //         004badaa     XOR        this,this
    //         004badac     MOV        this,byte ptr [ESI]
    //         004badae     PUSH       EAX
    //         004badaf     PUSH       this
    //                              Shape.cpp:2141 (2)
    //         004badb0     JMP        LAB_004badc0
    //                               LAB_004badb2                                                 XREF[1]:     004bad9f(j)  
    //                              Shape.cpp:2065 (2)
    //         004badb2     MOV        EAX,EDX
    //                              Shape.cpp:2143 (4)
    //         004badb4     MOV        BL,0x1
    //         004badb6     SUB        EAX,EDI
    //                              Shape.cpp:2145 (2)
    //         004badb8     SUB        EBP,EAX
    //                              Shape.cpp:2146 (19)
    //         004badba     XOR        EDX,EDX
    //         004badbc     MOV        DL,byte ptr [ESI]
    //         004badbe     PUSH       EAX
    //         004badbf     PUSH       EDX
    //                               LAB_004badc0                                                 XREF[1]:     004badb0(j)  
    //         004badc0     PUSH       EBP
    //         004badc1     CALL       memset                                           undefined memset()
    //         004badc6     MOV        EDX,dword ptr [ESP + param_6]
    //         004badca     ADD        ESP,0xc
    //                               LAB_004badcd                                                 XREF[1]:     004bad97(j)  
    //                              Shape.cpp:2149 (1)
    //         004badcd     INC        ESI
    //                               LAB_004badce                                                 XREF[8]:     004baced(j), 004bacfb(j), 
    //                                                                                                         004bad08(j), 004bad59(j), 
    //                                                                                                         004bad67(j), 004bad78(j), 
    //                                                                                                         004bad7c(j), 004bad88(j)  
    //                              Shape.cpp:2065 (8)
    //         004badce     TEST       BL,BL
    //         004badd0     JZ         LAB_004baccb
    //                              Shape.cpp:2154 (2)
    //         004badd6     JMP        LAB_004badda
    //                               LAB_004badd8                                                 XREF[1]:     004bacc3(j)  
    //                              Shape.cpp:2155 (2)
    //         004badd8     MOV        BL,0x1
    //                               LAB_004badda                                                 XREF[1]:     004badd6(j)  
    //                              Shape.cpp:2158 (2)
    //         004badda     DEC        BL
    //                              Shape.cpp:2159 (6)
    //         004baddc     JNZ        LAB_004baec3
    //                               LAB_004bade2                                                 XREF[1]:     004baebd(j)  
    //                              Shape.cpp:2161 (2)
    //         004bade2     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2162 (1)
    //         004bade4     INC        ESI
    //                              Shape.cpp:2163 (14)
    //         004bade5     MOV        this,AL
    //         004bade7     AND        this,0x1
    //         004badea     CMP        this,0x1
    //         004baded     JNZ        LAB_004bae73
    //                              Shape.cpp:2165 (6)
    //         004badf3     SHR        AL,0x1
    //         004badf5     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:2166 (2)
    //         004badf9     JNZ        LAB_004bae17
    //                              Shape.cpp:2168 (6)
    //         004badfb     XOR        EAX,EAX
    //         004badfd     MOV        AL,byte ptr [ESI]
    //         004badff     SUB        EDI,EAX
    //                              Shape.cpp:2169 (2)
    //         004bae01     SUB        EBP,EAX
    //                              Shape.cpp:2171 (13)
    //         004bae03     MOV        EAX,dword ptr [ESP + param_4]
    //         004bae07     INC        ESI
    //         004bae08     CMP        EDI,EAX
    //         004bae0a     JGE        LAB_004baebb
    //                              Shape.cpp:2172 (2)
    //         004bae10     MOV        BL,this
    //                              Shape.cpp:2174 (5)
    //         004bae12     JMP        LAB_004baebb
    //                               LAB_004bae17                                                 XREF[1]:     004badf9(j)  
    //                              Shape.cpp:2176 (4)
    //         004bae17     MOV        this,dword ptr [ESP + param_5]
    //                              Shape.cpp:2177 (16)
    //         004bae1b     MOV        EAX,dword ptr [ESP + param_4]
    //         004bae1f     AND        this,0xff
    //         004bae25     SUB        EDI,this
    //         004bae27     CMP        EDI,EAX
    //         004bae29     JGE        LAB_004bae5f
    //                              Shape.cpp:2180 (12)
    //         004bae2b     MOV        EDX,dword ptr [ESP + param_4]
    //         004bae2f     MOV        EAX,EDI
    //         004bae31     SUB        EAX,EDX
    //         004bae33     MOV        BL,0x1
    //         004bae35     ADD        EAX,this
    //                              Shape.cpp:2181 (4)
    //         004bae37     TEST       AL,AL
    //         004bae39     JBE        LAB_004bae59
    //                              Shape.cpp:2255 (30)
    //         004bae3b     MOV        EDX,EAX
    //         004bae3d     AND        EDX,0xff
    //         004bae43     MOV        dword ptr [ESP + param_1],EDX
    //                               LAB_004bae47                                                 XREF[1]:     004bae57(j)  
    //         004bae47     MOV        DL,byte ptr [ESI]
    //         004bae49     DEC        EBP
    //         004bae4a     INC        ESI
    //         004bae4b     MOV        byte ptr [EBP],DL
    //         004bae4e     MOV        EDX,dword ptr [ESP + param_1]
    //         004bae52     DEC        EDX
    //         004bae53     MOV        dword ptr [ESP + param_1],EDX
    //         004bae57     JNZ        LAB_004bae47
    //                               LAB_004bae59                                                 XREF[1]:     004bae39(j)  
    //                              Shape.cpp:2187 (4)
    //         004bae59     SUB        this,EAX
    //         004bae5b     ADD        ESI,this
    //                              Shape.cpp:2189 (2)
    //         004bae5d     JMP        LAB_004baeb7
    //                               LAB_004bae5f                                                 XREF[1]:     004bae29(j)  
    //                              Shape.cpp:2191 (8)
    //         004bae5f     MOV        AL,byte ptr [ESP + param_5]
    //         004bae63     TEST       AL,AL
    //         004bae65     JBE        LAB_004baebb
    //                               LAB_004bae67                                                 XREF[1]:     004bae6f(j)  
    //                              Shape.cpp:2194 (3)
    //         004bae67     MOV        AL,byte ptr [ESI]
    //         004bae69     DEC        EBP
    //                              Shape.cpp:2195 (7)
    //         004bae6a     INC        ESI
    //         004bae6b     DEC        this
    //         004bae6c     MOV        byte ptr [EBP],AL
    //         004bae6f     JNZ        LAB_004bae67
    //                              Shape.cpp:2200 (2)
    //         004bae71     JMP        LAB_004baebb
    //                               LAB_004bae73                                                 XREF[1]:     004baded(j)  
    //                              Shape.cpp:2202 (6)
    //         004bae73     SHR        AL,0x1
    //         004bae75     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:2203 (2)
    //         004bae79     JNZ        LAB_004bae7f
    //                              Shape.cpp:2204 (2)
    //         004bae7b     MOV        BL,0x3
    //                              Shape.cpp:2205 (2)
    //         004bae7d     JMP        LAB_004baebb
    //                               LAB_004bae7f                                                 XREF[1]:     004bae79(j)  
    //                              Shape.cpp:2207 (4)
    //         004bae7f     MOV        this,dword ptr [ESP + param_5]
    //                              Shape.cpp:2208 (16)
    //         004bae83     MOV        EDX,dword ptr [ESP + param_4]
    //         004bae87     AND        this,0xff
    //         004bae8d     SUB        EDI,this
    //         004bae8f     CMP        EDI,EDX
    //         004bae91     JGE        LAB_004baea5
    //                              Shape.cpp:2211 (8)
    //         004bae93     MOV        EAX,EDI
    //         004bae95     MOV        BL,0x1
    //         004bae97     SUB        EAX,EDX
    //         004bae99     ADD        EAX,this
    //                              Shape.cpp:2212 (2)
    //         004bae9b     SUB        EBP,EAX
    //                              Shape.cpp:2213 (6)
    //         004bae9d     XOR        this,this
    //         004bae9f     MOV        this,byte ptr [ESI]
    //         004baea1     PUSH       EAX
    //         004baea2     PUSH       this
    //                              Shape.cpp:2215 (2)
    //         004baea3     JMP        LAB_004baead
    //                               LAB_004baea5                                                 XREF[1]:     004bae91(j)  
    //                              Shape.cpp:2217 (2)
    //         004baea5     SUB        EBP,this
    //                              Shape.cpp:2218 (15)
    //         004baea7     XOR        EDX,EDX
    //         004baea9     MOV        DL,byte ptr [ESI]
    //         004baeab     PUSH       this
    //         004baeac     PUSH       EDX
    //                               LAB_004baead                                                 XREF[1]:     004baea3(j)  
    //         004baead     PUSH       EBP
    //         004baeae     CALL       memset                                           undefined memset()
    //         004baeb3     ADD        ESP,0xc
    //                              Shape.cpp:2220 (5)
    //         004baeb6     INC        ESI
    //                               LAB_004baeb7                                                 XREF[1]:     004bae5d(j)  
    //         004baeb7     MOV        EDX,dword ptr [ESP + param_6]
    //                               LAB_004baebb                                                 XREF[5]:     004bae0a(j), 004bae12(j), 
    //                                                                                                         004bae65(j), 004bae71(j), 
    //                                                                                                         004bae7d(j)  
    //                              Shape.cpp:2159 (8)
    //         004baebb     TEST       BL,BL
    //         004baebd     JZ         LAB_004bade2
    //                               LAB_004baec3                                                 XREF[1]:     004baddc(j)  
    //                              Shape.cpp:2226 (2)
    //         004baec3     DEC        BL
    //                              Shape.cpp:2227 (2)
    //         004baec5     JNZ        LAB_004baef6
    //                               LAB_004baec7                                                 XREF[1]:     004baef4(j)  
    //                              Shape.cpp:2229 (2)
    //         004baec7     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2230 (1)
    //         004baec9     INC        ESI
    //                              Shape.cpp:2231 (10)
    //         004baeca     MOV        this,AL
    //         004baecc     AND        this,0x1
    //         004baecf     CMP        this,0x1
    //         004baed2     JNZ        LAB_004baee9
    //                              Shape.cpp:2233 (6)
    //         004baed4     SHR        AL,0x1
    //         004baed6     MOV        byte ptr [ESP + param_5],AL
    //                              Shape.cpp:2236 (2)
    //         004baeda     JZ         LAB_004baef1
    //                              Shape.cpp:2237 (11)
    //         004baedc     MOV        EAX,dword ptr [ESP + param_5]
    //         004baee0     AND        EAX,0xff
    //         004baee5     ADD        ESI,EAX
    //                              Shape.cpp:2239 (2)
    //         004baee7     JMP        LAB_004baef2
    //                               LAB_004baee9                                                 XREF[1]:     004baed2(j)  
    //                              Shape.cpp:2242 (4)
    //         004baee9     TEST       AL,0xfe
    //         004baeeb     JNZ        LAB_004baef1
    //                              Shape.cpp:2243 (2)
    //         004baeed     MOV        BL,0x2
    //                              Shape.cpp:2244 (2)
    //         004baeef     JMP        LAB_004baef2
    //                               LAB_004baef1                                                 XREF[2]:     004baeda(j), 004baeeb(j)  
    //                              Shape.cpp:2245 (1)
    //         004baef1     INC        ESI
    //                               LAB_004baef2                                                 XREF[2]:     004baee7(j), 004baeef(j)  
    //                              Shape.cpp:2227 (4)
    //         004baef2     TEST       BL,BL
    //         004baef4     JZ         LAB_004baec7
    //                               LAB_004baef6                                                 XREF[1]:     004baec5(j)  
    //                              Shape.cpp:2250 (29)
    //         004baef6     MOV        EBP,dword ptr [ESP + width]
    //         004baefa     MOV        this,dword ptr [ESP + local_4]
    //         004baefe     MOV        EAX,dword ptr [ESP + param_3]
    //         004baf02     ADD        EBP,this
    //         004baf04     DEC        EAX
    //         004baf05     MOV        dword ptr [ESP + width],EBP
    //         004baf09     MOV        dword ptr [ESP + param_3],EAX
    //         004baf0d     JNZ        LAB_004bacbd
    //                               LAB_004baf13                                                 XREF[1]:     004bacb0(j)  
    //                              Shape.cpp:2255 (12)
    //         004baf13     POP        EDI
    //         004baf14     POP        ESI
    //         004baf15     POP        EBP
    //         004baf16     MOV        AL,0x1
    //         004baf18     POP        EBX
    //         004baf19     ADD        ESP,0x8
    //         004baf1c     RET        0x1c
}

// Offset: 0x004BAF20
uchar shape_mirror_color_trans_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, uchar* param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_mirror_color_trans_clipped(class TDrawArea *,long,... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror_color_trans_clipped(TShape * this, TDr
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[14]:    004baf27(R), 004baf9f(W), 004bafa5(R), 004baffe(W), 
    //                                                                                     004bb02d(R), 004bb0b7(W), 004bb0c1(R), 004bb12d(W), 
    //                                                                                     004bb14f(R), 004bb1a7(R), 004bb1d1(W), 004bb1db(R), 
    //                                                                                     004bb236(W), 004bb23c(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004bafdd(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     004baf77(R), 004bb17f(W), 004bb192(R), 004bb197(W)  
    //              long              Stack[0x10]:4  param_4
    //              long              Stack[0x14]:4  param_5                   XREF[9]:     004bb013(R), 004bb03d(R), 004bb045(R), 004bb075(R), 
    //                                                                                     004bb0d0(R), 004bb13b(R), 004bb153(R), 004bb163(R), 
    //                                                                                     004bb1df(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[9]:     004baf3f(R), 004baf87(W), 004bafbf(R), 004bafc4(W), 
    //                                                                                     004bb16f(W), 004bb19d(R), 004bb1af(W), 004bb1c2(R), 
    //                                                                                     004bb1c7(W)  
    //              long              Stack[0x1c]:4  param_7                   XREF[7]:     004baf56(R), 004baf6f(R), 004bb04d(R), 004bb07d(R), 
    //                                                                                     004bb0ab(R), 004bb0fe(R), 004bb217(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[4]:     004bafca(R), 004bafd9(W), 004bb25e(R), 004bb269(W)  
    //              uchar *           Stack[0x24]:4  param_9                   XREF[6]:     004bb063(R), 004bb099(R), 004bb0ee(R), 004bb183(R), 
    //                                                                                     004bb1b3(R), 004bb1ff(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004baf49(W), 004bb25a(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004baf7b(W), 004bb256(R), 004bb265(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer
    //                               ?shape_mirror_color_trans_clipped@TShape@@AAEEPAVTDrawArea@  XREF[1]:     shape_mirror:004ba8b7(c)  
    //                               TShape::shape_mirror_color_trans_clipped
    //                              Shape.cpp:2259 (7)
    //         004baf20     SUB        ESP,0x8
    //         004baf23     PUSH       EBX
    //         004baf24     PUSH       EBP
    //         004baf25     PUSH       ESI
    //         004baf26     PUSH       EDI
    //                              Shape.cpp:2260 (18)
    //         004baf27     MOV        EDI,dword ptr [ESP + param_1]
    //         004baf2b     MOV        ESI,this
    //         004baf2d     MOV        this,EDI
    //         004baf2f     MOV        EBX,dword ptr [EDI + 0x24]
    //         004baf32     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004baf37     MOV        this,EAX
    //                              Shape.cpp:2265 (6)
    //         004baf39     MOV        ESI,dword ptr [ESI + 0xc]
    //         004baf3c     IMUL       this,EBX
    //                              Shape.cpp:2275 (38)
    //         004baf3f     MOV        EAX,dword ptr [ESP + param_6]
    //         004baf43     ADD        ESI,0x18
    //         004baf46     CMP        EBX,0x1
    //         004baf49     MOV        dword ptr [ESP + local_4],this
    //         004baf4d     JGE        LAB_004baf67
    //         004baf4f     MOV        EBP,dword ptr [EDI + 0x1c]
    //         004baf52     MOV        EBX,EAX
    //         004baf54     SUB        EBX,EBP
    //         004baf56     MOV        EDX,dword ptr [ESP + param_7]
    //         004baf5a     INC        EBX
    //         004baf5b     IMUL       EBX,this
    //         004baf5e     ADD        EBX,dword ptr [EDI + 0x8]
    //         004baf61     LEA        EDI,[EBX + EDX*0x1 + 0x1]
    //                              Shape.cpp:2276 (2)
    //         004baf65     JMP        LAB_004baf77
    //                               LAB_004baf67                                                 XREF[1]:     004baf4d(j)  
    //                              Shape.cpp:2277 (16)
    //         004baf67     IMUL       this,EAX
    //         004baf6a     MOV        EDX,dword ptr [EDI + 0x8]
    //         004baf6d     ADD        this,EDX
    //         004baf6f     MOV        EDX,dword ptr [ESP + param_7]
    //         004baf73     LEA        EDI,[ECX + EDX*this+0x1 + 0x1]
    //                               LAB_004baf77                                                 XREF[1]:     004baf65(j)  
    //                              Shape.cpp:2281 (23)
    //         004baf77     MOV        this,dword ptr [ESP + param_3]
    //         004baf7b     MOV        dword ptr [ESP + width],EDI
    //         004baf7f     CMP        this,EAX
    //         004baf81     MOV        EBP,this
    //         004baf83     JGE        LAB_004bafca
    //         004baf85     SUB        EAX,this
    //         004baf87     MOV        dword ptr [ESP + param_6],EAX
    //         004baf8b     LEA        EBP,[this->shape + EAX*0x1]
    //                               LAB_004baf8e                                                 XREF[1]:     004bafc8(j)  
    //                              Shape.cpp:2283 (2)
    //         004baf8e     XOR        this,this
    //                               LAB_004baf90                                                 XREF[1]:     004bafbd(j)  
    //                              Shape.cpp:2286 (2)
    //         004baf90     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2287 (1)
    //         004baf92     INC        ESI
    //                              Shape.cpp:2288 (10)
    //         004baf93     MOV        BL,AL
    //         004baf95     AND        BL,0x1
    //         004baf98     CMP        BL,0x1
    //         004baf9b     JNZ        LAB_004bafb2
    //                              Shape.cpp:2290 (6)
    //         004baf9d     SHR        AL,0x1
    //         004baf9f     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:2293 (2)
    //         004bafa3     JZ         LAB_004bafba
    //                              Shape.cpp:2294 (11)
    //         004bafa5     MOV        EAX,dword ptr [ESP + param_1]
    //         004bafa9     AND        EAX,0xff
    //         004bafae     ADD        ESI,EAX
    //                              Shape.cpp:2296 (2)
    //         004bafb0     JMP        LAB_004bafbb
    //                               LAB_004bafb2                                                 XREF[1]:     004baf9b(j)  
    //                              Shape.cpp:2299 (4)
    //         004bafb2     TEST       AL,0xfe
    //         004bafb4     JNZ        LAB_004bafba
    //                              Shape.cpp:2300 (2)
    //         004bafb6     MOV        this,0x1
    //                              Shape.cpp:2301 (2)
    //         004bafb8     JMP        LAB_004bafbb
    //                               LAB_004bafba                                                 XREF[2]:     004bafa3(j), 004bafb4(j)  
    //                              Shape.cpp:2302 (1)
    //         004bafba     INC        ESI
    //                               LAB_004bafbb                                                 XREF[2]:     004bafb0(j), 004bafb8(j)  
    //                              Shape.cpp:2284 (15)
    //         004bafbb     TEST       this,this
    //         004bafbd     JZ         LAB_004baf90
    //         004bafbf     MOV        EAX,dword ptr [ESP + param_6]
    //         004bafc3     DEC        EAX
    //         004bafc4     MOV        dword ptr [ESP + param_6],EAX
    //         004bafc8     JNZ        LAB_004baf8e
    //                               LAB_004bafca                                                 XREF[1]:     004baf83(j)  
    //                              Shape.cpp:2308 (19)
    //         004bafca     MOV        EAX,dword ptr [ESP + param_8]
    //         004bafce     CMP        EBP,EAX
    //         004bafd0     JG         LAB_004bb273
    //         004bafd6     SUB        EAX,EBP
    //         004bafd8     INC        EAX
    //         004bafd9     MOV        dword ptr [ESP + param_8],EAX
    //                               LAB_004bafdd                                                 XREF[1]:     004bb26d(j)  
    //                              Shape.cpp:2310 (4)
    //         004bafdd     MOV        EBP,dword ptr [ESP + param_2]
    //                              Shape.cpp:2313 (8)
    //         004bafe1     CMP        EBP,EDX
    //         004bafe3     JLE        LAB_004bb110
    //                              Shape.cpp:2315 (2)
    //         004bafe9     XOR        BL,BL
    //                               LAB_004bafeb                                                 XREF[1]:     004bb108(j)  
    //                              Shape.cpp:2318 (2)
    //         004bafeb     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2319 (1)
    //         004bafed     INC        ESI
    //                              Shape.cpp:2320 (14)
    //         004bafee     MOV        this,AL
    //         004baff0     AND        this,0x1
    //         004baff3     CMP        this,0x1
    //         004baff6     JNZ        LAB_004bb0b5
    //                              Shape.cpp:2322 (6)
    //         004baffc     SHR        AL,0x1
    //         004baffe     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:2323 (2)
    //         004bb002     JNZ        LAB_004bb02d
    //                              Shape.cpp:2325 (6)
    //         004bb004     XOR        EAX,EAX
    //         004bb006     MOV        AL,byte ptr [ESI]
    //         004bb008     SUB        EBP,EAX
    //                              Shape.cpp:2326 (1)
    //         004bb00a     INC        ESI
    //                              Shape.cpp:2327 (8)
    //         004bb00b     CMP        EBP,EDX
    //         004bb00d     JG         LAB_004bb106
    //                              Shape.cpp:2329 (6)
    //         004bb013     CMP        EBP,dword ptr [ESP + param_5]
    //         004bb017     JGE        LAB_004bb020
    //                              Shape.cpp:2330 (2)
    //         004bb019     MOV        BL,0x2
    //                              Shape.cpp:2331 (5)
    //         004bb01b     JMP        LAB_004bb106
    //                               LAB_004bb020                                                 XREF[1]:     004bb017(j)  
    //                              Shape.cpp:2334 (8)
    //         004bb020     MOV        this,EBP
    //         004bb022     MOV        BL,0x1
    //         004bb024     SUB        this,EDX
    //         004bb026     ADD        EDI,this
    //                              Shape.cpp:2338 (5)
    //         004bb028     JMP        LAB_004bb106
    //                               LAB_004bb02d                                                 XREF[1]:     004bb002(j)  
    //                              Shape.cpp:2340 (12)
    //         004bb02d     MOV        this,dword ptr [ESP + param_1]
    //         004bb031     AND        this,0xff
    //         004bb037     SUB        EBP,this
    //                              Shape.cpp:2341 (4)
    //         004bb039     CMP        EBP,EDX
    //         004bb03b     JG         LAB_004bb0b1
    //                              Shape.cpp:2343 (6)
    //         004bb03d     CMP        EBP,dword ptr [ESP + param_5]
    //         004bb041     JGE        LAB_004bb086
    //                              Shape.cpp:2348 (8)
    //         004bb043     MOV        EAX,EDX
    //         004bb045     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb049     SUB        EAX,EDX
    //                              Shape.cpp:2349 (11)
    //         004bb04b     MOV        EDX,EBP
    //         004bb04d     SUB        EDX,dword ptr [ESP + param_7]
    //         004bb051     INC        EAX
    //         004bb052     MOV        BL,0x2
    //         004bb054     ADD        EDX,this
    //                              Shape.cpp:2350 (8)
    //         004bb056     TEST       AL,AL
    //         004bb058     LEA        ESI,[ESI + EDX*0x1 + -0x1]
    //         004bb05c     JBE        LAB_004bb075
    //                              Shape.cpp:2506 (5)
    //         004bb05e     AND        EAX,0xff
    //                               LAB_004bb063                                                 XREF[1]:     004bb073(j)  
    //                              Shape.cpp:2353 (9)
    //         004bb063     MOV        EDX,dword ptr [ESP + param_9]
    //         004bb067     XOR        this,this
    //         004bb069     MOV        this,byte ptr [ESI]
    //         004bb06b     DEC        EDI
    //                              Shape.cpp:2354 (9)
    //         004bb06c     INC        ESI
    //         004bb06d     DEC        EAX
    //         004bb06e     MOV        this,byte ptr [EDX + this->shape*0x1]
    //         004bb071     MOV        byte ptr [EDI],this
    //         004bb073     JNZ        LAB_004bb063
    //                               LAB_004bb075                                                 XREF[1]:     004bb05c(j)  
    //                              Shape.cpp:2356 (8)
    //         004bb075     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb079     SUB        EDX,EBP
    //         004bb07b     ADD        ESI,EDX
    //                              Shape.cpp:2358 (9)
    //         004bb07d     MOV        EDX,dword ptr [ESP + param_7]
    //         004bb081     JMP        LAB_004bb106
    //                               LAB_004bb086                                                 XREF[1]:     004bb041(j)  
    //                              Shape.cpp:2316 (2)
    //         004bb086     MOV        EAX,EDX
    //                              Shape.cpp:2360 (4)
    //         004bb088     MOV        BL,0x1
    //         004bb08a     SUB        EAX,EBP
    //                              Shape.cpp:2362 (4)
    //         004bb08c     SUB        this,EAX
    //         004bb08e     ADD        ESI,this
    //                              Shape.cpp:2363 (4)
    //         004bb090     TEST       AL,AL
    //         004bb092     JBE        LAB_004bb106
    //                              Shape.cpp:2506 (5)
    //         004bb094     AND        EAX,0xff
    //                               LAB_004bb099                                                 XREF[1]:     004bb0a9(j)  
    //                              Shape.cpp:2366 (9)
    //         004bb099     MOV        EDX,dword ptr [ESP + param_9]
    //         004bb09d     XOR        this,this
    //         004bb09f     MOV        this,byte ptr [ESI]
    //         004bb0a1     DEC        EDI
    //                              Shape.cpp:2367 (9)
    //         004bb0a2     INC        ESI
    //         004bb0a3     DEC        EAX
    //         004bb0a4     MOV        this,byte ptr [EDX + this->shape*0x1]
    //         004bb0a7     MOV        byte ptr [EDI],this
    //         004bb0a9     JNZ        LAB_004bb099
    //                              Shape.cpp:2371 (6)
    //         004bb0ab     MOV        EDX,dword ptr [ESP + param_7]
    //         004bb0af     JMP        LAB_004bb106
    //                               LAB_004bb0b1                                                 XREF[1]:     004bb03b(j)  
    //                              Shape.cpp:2372 (2)
    //         004bb0b1     ADD        ESI,this
    //                              Shape.cpp:2375 (2)
    //         004bb0b3     JMP        LAB_004bb106
    //                               LAB_004bb0b5                                                 XREF[1]:     004baff6(j)  
    //                              Shape.cpp:2377 (6)
    //         004bb0b5     SHR        AL,0x1
    //         004bb0b7     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:2378 (2)
    //         004bb0bb     JNZ        LAB_004bb0c1
    //                              Shape.cpp:2379 (2)
    //         004bb0bd     MOV        BL,0x3
    //                              Shape.cpp:2380 (2)
    //         004bb0bf     JMP        LAB_004bb106
    //                               LAB_004bb0c1                                                 XREF[1]:     004bb0bb(j)  
    //                              Shape.cpp:2382 (11)
    //         004bb0c1     MOV        EAX,dword ptr [ESP + param_1]
    //         004bb0c5     AND        EAX,0xff
    //         004bb0ca     SUB        EBP,EAX
    //                              Shape.cpp:2383 (4)
    //         004bb0cc     CMP        EBP,EDX
    //         004bb0ce     JG         LAB_004bb105
    //                              Shape.cpp:2385 (8)
    //         004bb0d0     MOV        this,dword ptr [ESP + param_5]
    //         004bb0d4     CMP        EBP,this
    //         004bb0d6     JGE        LAB_004bb0e1
    //                              Shape.cpp:2388 (7)
    //         004bb0d8     MOV        EAX,EDX
    //         004bb0da     MOV        BL,0x2
    //         004bb0dc     SUB        EAX,this
    //         004bb0de     INC        EAX
    //                              Shape.cpp:2392 (2)
    //         004bb0df     JMP        LAB_004bb0e7
    //                               LAB_004bb0e1                                                 XREF[1]:     004bb0d6(j)  
    //                              Shape.cpp:2316 (2)
    //         004bb0e1     MOV        EAX,EDX
    //                              Shape.cpp:2394 (4)
    //         004bb0e3     MOV        BL,0x1
    //         004bb0e5     SUB        EAX,EBP
    //                               LAB_004bb0e7                                                 XREF[1]:     004bb0df(j)  
    //                              Shape.cpp:2397 (30)
    //         004bb0e7     XOR        this,this
    //         004bb0e9     SUB        EDI,EAX
    //         004bb0eb     MOV        this,byte ptr [ESI]
    //         004bb0ed     PUSH       EAX
    //         004bb0ee     MOV        EAX,dword ptr [ESP + param_9]
    //         004bb0f2     XOR        EDX,EDX
    //         004bb0f4     MOV        DL,byte ptr [EAX + this->shape*0x1]
    //         004bb0f7     PUSH       EDX
    //         004bb0f8     PUSH       EDI
    //         004bb0f9     CALL       memset                                           undefined memset()
    //         004bb0fe     MOV        EDX,dword ptr [ESP + param_7]
    //         004bb102     ADD        ESP,0xc
    //                               LAB_004bb105                                                 XREF[1]:     004bb0ce(j)  
    //                              Shape.cpp:2400 (1)
    //         004bb105     INC        ESI
    //                               LAB_004bb106                                                 XREF[8]:     004bb00d(j), 004bb01b(j), 
    //                                                                                                         004bb028(j), 004bb081(j), 
    //                                                                                                         004bb092(j), 004bb0af(j), 
    //                                                                                                         004bb0b3(j), 004bb0bf(j)  
    //                              Shape.cpp:2316 (8)
    //         004bb106     TEST       BL,BL
    //         004bb108     JZ         LAB_004bafeb
    //                              Shape.cpp:2405 (2)
    //         004bb10e     JMP        LAB_004bb112
    //                               LAB_004bb110                                                 XREF[1]:     004bafe3(j)  
    //                              Shape.cpp:2406 (2)
    //         004bb110     MOV        BL,0x1
    //                               LAB_004bb112                                                 XREF[1]:     004bb10e(j)  
    //                              Shape.cpp:2409 (2)
    //         004bb112     DEC        BL
    //                              Shape.cpp:2410 (6)
    //         004bb114     JNZ        LAB_004bb223
    //                               LAB_004bb11a                                                 XREF[1]:     004bb21d(j)  
    //                              Shape.cpp:2412 (2)
    //         004bb11a     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2413 (1)
    //         004bb11c     INC        ESI
    //                              Shape.cpp:2414 (14)
    //         004bb11d     MOV        this,AL
    //         004bb11f     AND        this,0x1
    //         004bb122     CMP        this,0x1
    //         004bb125     JNZ        LAB_004bb1cf
    //                              Shape.cpp:2416 (6)
    //         004bb12b     SHR        AL,0x1
    //         004bb12d     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:2417 (2)
    //         004bb131     JNZ        LAB_004bb14f
    //                              Shape.cpp:2419 (6)
    //         004bb133     XOR        EAX,EAX
    //         004bb135     MOV        AL,byte ptr [ESI]
    //         004bb137     SUB        EBP,EAX
    //                              Shape.cpp:2420 (2)
    //         004bb139     SUB        EDI,EAX
    //                              Shape.cpp:2422 (13)
    //         004bb13b     MOV        EAX,dword ptr [ESP + param_5]
    //         004bb13f     INC        ESI
    //         004bb140     CMP        EBP,EAX
    //         004bb142     JGE        LAB_004bb21b
    //                              Shape.cpp:2423 (2)
    //         004bb148     MOV        BL,this
    //                              Shape.cpp:2425 (5)
    //         004bb14a     JMP        LAB_004bb21b
    //                               LAB_004bb14f                                                 XREF[1]:     004bb131(j)  
    //                              Shape.cpp:2427 (4)
    //         004bb14f     MOV        this,dword ptr [ESP + param_1]
    //                              Shape.cpp:2428 (16)
    //         004bb153     MOV        EAX,dword ptr [ESP + param_5]
    //         004bb157     AND        this,0xff
    //         004bb15d     SUB        EBP,this
    //         004bb15f     CMP        EBP,EAX
    //         004bb161     JGE        LAB_004bb1a7
    //                              Shape.cpp:2431 (16)
    //         004bb163     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb167     MOV        EAX,EBP
    //         004bb169     SUB        EAX,EDX
    //         004bb16b     MOV        BL,0x1
    //         004bb16d     ADD        EAX,this
    //         004bb16f     MOV        byte ptr [ESP + param_6],BL
    //                              Shape.cpp:2432 (4)
    //         004bb173     TEST       AL,AL
    //         004bb175     JBE        LAB_004bb1a1
    //                              Shape.cpp:2506 (38)
    //         004bb177     MOV        EDX,EAX
    //         004bb179     AND        EDX,0xff
    //         004bb17f     MOV        dword ptr [ESP + param_3],EDX
    //                               LAB_004bb183                                                 XREF[1]:     004bb19b(j)  
    //         004bb183     MOV        EBX,dword ptr [ESP + param_9]
    //         004bb187     XOR        EDX,EDX
    //         004bb189     MOV        DL,byte ptr [ESI]
    //         004bb18b     DEC        EDI
    //         004bb18c     INC        ESI
    //         004bb18d     MOV        DL,byte ptr [EBX + EDX*0x1]
    //         004bb190     MOV        byte ptr [EDI],DL
    //         004bb192     MOV        EDX,dword ptr [ESP + param_3]
    //         004bb196     DEC        EDX
    //         004bb197     MOV        dword ptr [ESP + param_3],EDX
    //         004bb19b     JNZ        LAB_004bb183
    //                              Shape.cpp:2432 (4)
    //         004bb19d     MOV        BL,byte ptr [ESP + param_6]
    //                               LAB_004bb1a1                                                 XREF[1]:     004bb175(j)  
    //                              Shape.cpp:2438 (4)
    //         004bb1a1     SUB        this,EAX
    //         004bb1a3     ADD        ESI,this
    //                              Shape.cpp:2440 (2)
    //         004bb1a5     JMP        LAB_004bb217
    //                               LAB_004bb1a7                                                 XREF[1]:     004bb161(j)  
    //                              Shape.cpp:2442 (8)
    //         004bb1a7     MOV        AL,byte ptr [ESP + param_1]
    //         004bb1ab     TEST       AL,AL
    //         004bb1ad     JBE        LAB_004bb21b
    //                              Shape.cpp:2506 (4)
    //         004bb1af     MOV        dword ptr [ESP + param_6],this
    //                               LAB_004bb1b3                                                 XREF[1]:     004bb1cb(j)  
    //                              Shape.cpp:2445 (9)
    //         004bb1b3     MOV        this,dword ptr [ESP + param_9]
    //         004bb1b7     XOR        EAX,EAX
    //         004bb1b9     MOV        AL,byte ptr [ESI]
    //         004bb1bb     DEC        EDI
    //                              Shape.cpp:2446 (17)
    //         004bb1bc     INC        ESI
    //         004bb1bd     MOV        AL,byte ptr [this->shape + EAX*0x1]
    //         004bb1c0     MOV        byte ptr [EDI],AL
    //         004bb1c2     MOV        EAX,dword ptr [ESP + param_6]
    //         004bb1c6     DEC        EAX
    //         004bb1c7     MOV        dword ptr [ESP + param_6],EAX
    //         004bb1cb     JNZ        LAB_004bb1b3
    //                              Shape.cpp:2451 (2)
    //         004bb1cd     JMP        LAB_004bb21b
    //                               LAB_004bb1cf                                                 XREF[1]:     004bb125(j)  
    //                              Shape.cpp:2453 (6)
    //         004bb1cf     SHR        AL,0x1
    //         004bb1d1     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:2454 (2)
    //         004bb1d5     JNZ        LAB_004bb1db
    //                              Shape.cpp:2455 (2)
    //         004bb1d7     MOV        BL,0x3
    //                              Shape.cpp:2456 (2)
    //         004bb1d9     JMP        LAB_004bb21b
    //                               LAB_004bb1db                                                 XREF[1]:     004bb1d5(j)  
    //                              Shape.cpp:2458 (4)
    //         004bb1db     MOV        this,dword ptr [ESP + param_1]
    //                              Shape.cpp:2459 (16)
    //         004bb1df     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb1e3     AND        this,0xff
    //         004bb1e9     SUB        EBP,this
    //         004bb1eb     CMP        EBP,EDX
    //         004bb1ed     JGE        LAB_004bb1fc
    //                              Shape.cpp:2462 (8)
    //         004bb1ef     MOV        EAX,EBP
    //         004bb1f1     MOV        BL,0x1
    //         004bb1f3     SUB        EAX,EDX
    //         004bb1f5     ADD        EAX,this
    //                              Shape.cpp:2463 (2)
    //         004bb1f7     SUB        EDI,EAX
    //                              Shape.cpp:2464 (1)
    //         004bb1f9     PUSH       EAX
    //                              Shape.cpp:2466 (2)
    //         004bb1fa     JMP        LAB_004bb1ff
    //                               LAB_004bb1fc                                                 XREF[1]:     004bb1ed(j)  
    //                              Shape.cpp:2468 (2)
    //         004bb1fc     SUB        EDI,this
    //                              Shape.cpp:2469 (24)
    //         004bb1fe     PUSH       this
    //                               LAB_004bb1ff                                                 XREF[1]:     004bb1fa(j)  
    //         004bb1ff     MOV        EAX,dword ptr [ESP + param_9]
    //         004bb203     XOR        this,this
    //         004bb205     MOV        this,byte ptr [ESI]
    //         004bb207     XOR        EDX,EDX
    //         004bb209     MOV        DL,byte ptr [EAX + this->shape*0x1]
    //         004bb20c     PUSH       EDX
    //         004bb20d     PUSH       EDI
    //         004bb20e     CALL       memset                                           undefined memset()
    //         004bb213     ADD        ESP,0xc
    //                              Shape.cpp:2471 (5)
    //         004bb216     INC        ESI
    //                               LAB_004bb217                                                 XREF[1]:     004bb1a5(j)  
    //         004bb217     MOV        EDX,dword ptr [ESP + param_7]
    //                               LAB_004bb21b                                                 XREF[5]:     004bb142(j), 004bb14a(j), 
    //                                                                                                         004bb1ad(j), 004bb1cd(j), 
    //                                                                                                         004bb1d9(j)  
    //                              Shape.cpp:2410 (8)
    //         004bb21b     TEST       BL,BL
    //         004bb21d     JZ         LAB_004bb11a
    //                               LAB_004bb223                                                 XREF[1]:     004bb114(j)  
    //                              Shape.cpp:2477 (2)
    //         004bb223     DEC        BL
    //                              Shape.cpp:2478 (2)
    //         004bb225     JNZ        LAB_004bb256
    //                               LAB_004bb227                                                 XREF[1]:     004bb254(j)  
    //                              Shape.cpp:2480 (2)
    //         004bb227     MOV        AL,byte ptr [ESI]
    //                              Shape.cpp:2481 (1)
    //         004bb229     INC        ESI
    //                              Shape.cpp:2482 (10)
    //         004bb22a     MOV        this,AL
    //         004bb22c     AND        this,0x1
    //         004bb22f     CMP        this,0x1
    //         004bb232     JNZ        LAB_004bb249
    //                              Shape.cpp:2484 (6)
    //         004bb234     SHR        AL,0x1
    //         004bb236     MOV        byte ptr [ESP + param_1],AL
    //                              Shape.cpp:2487 (2)
    //         004bb23a     JZ         LAB_004bb251
    //                              Shape.cpp:2488 (11)
    //         004bb23c     MOV        EAX,dword ptr [ESP + param_1]
    //         004bb240     AND        EAX,0xff
    //         004bb245     ADD        ESI,EAX
    //                              Shape.cpp:2490 (2)
    //         004bb247     JMP        LAB_004bb252
    //                               LAB_004bb249                                                 XREF[1]:     004bb232(j)  
    //                              Shape.cpp:2493 (4)
    //         004bb249     TEST       AL,0xfe
    //         004bb24b     JNZ        LAB_004bb251
    //                              Shape.cpp:2494 (2)
    //         004bb24d     MOV        BL,0x2
    //                              Shape.cpp:2495 (2)
    //         004bb24f     JMP        LAB_004bb252
    //                               LAB_004bb251                                                 XREF[2]:     004bb23a(j), 004bb24b(j)  
    //                              Shape.cpp:2496 (1)
    //         004bb251     INC        ESI
    //                               LAB_004bb252                                                 XREF[2]:     004bb247(j), 004bb24f(j)  
    //                              Shape.cpp:2478 (4)
    //         004bb252     TEST       BL,BL
    //         004bb254     JZ         LAB_004bb227
    //                               LAB_004bb256                                                 XREF[1]:     004bb225(j)  
    //                              Shape.cpp:2501 (29)
    //         004bb256     MOV        EDI,dword ptr [ESP + width]
    //         004bb25a     MOV        this,dword ptr [ESP + local_4]
    //         004bb25e     MOV        EAX,dword ptr [ESP + param_8]
    //         004bb262     ADD        EDI,this
    //         004bb264     DEC        EAX
    //         004bb265     MOV        dword ptr [ESP + width],EDI
    //         004bb269     MOV        dword ptr [ESP + param_8],EAX
    //         004bb26d     JNZ        LAB_004bafdd
    //                               LAB_004bb273                                                 XREF[1]:     004bafd0(j)  
    //                              Shape.cpp:2506 (12)
    //         004bb273     POP        EDI
    //         004bb274     POP        ESI
    //         004bb275     POP        EBP
    //         004bb276     MOV        AL,0x1
    //         004bb278     POP        EBX
    //         004bb279     ADD        ESP,0x8
    //         004bb27c     RET        0x24
}

// Offset: 0x004BB280
uchar shape_mirror_shadow_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, uchar* param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_mirror_shadow_clipped(class TDrawArea *,long,long,... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_mirror_shadow_clipped(TShape * this, TDrawAre
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[14]:    004bb286(R), 004bb2ab(W), 004bb324(W), 004bb338(R), 
    //                                                                                     004bb35e(W), 004bb3db(R), 004bb3e1(W), 004bb407(R), 
    //                                                                                     004bb40d(W), 004bb490(W), 004bb4f3(R), 004bb50e(R), 
    //                                                                                     004bb568(R), 004bb56d(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     004bb33e(R), 004bb349(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[4]:     004bb2db(R), 004bb343(W), 004bb5b8(R), 004bb5c3(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[6]:     004bb389(R), 004bb3b7(R), 004bb435(R), 004bb4ac(R), 
    //                                                                                     004bb4c4(R), 004bb526(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[13]:    004bb29d(R), 004bb2ff(W), 004bb305(R), 004bb370(W), 
    //                                                                                     004bb3a3(R), 004bb417(W), 004bb421(R), 004bb49e(W), 
    //                                                                                     004bb4c0(R), 004bb518(W), 004bb522(R), 004bb58e(W), 
    //                                                                                     004bb594(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[6]:     004bb2c1(R), 004bb2d3(R), 004bb34d(R), 004bb37c(R), 
    //                                                                                     004bb3a7(R), 004bb42d(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[1]:     004bb328(R)  
    //              uchar *           Stack[0x20]:4  param_8                   XREF[1]:     004bb334(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004bb2a7(W), 004bb5b4(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004bb2df(W), 004bb5b0(R), 004bb5bf(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer
    //                               ?shape_mirror_shadow_clipped@TShape@@AAEEPAVTDrawArea@@JJJJ  XREF[1]:     shape_mirror:004ba889(c)  
    //                               TShape::shape_mirror_shadow_clipped
    //                              Shape.cpp:2510 (6)
    //         004bb280     SUB        ESP,0x8
    //         004bb283     PUSH       EBX
    //         004bb284     PUSH       EBP
    //         004bb285     PUSH       ESI
    //                              Shape.cpp:2511 (20)
    //         004bb286     MOV        ESI,dword ptr [ESP + param_1]
    //         004bb28a     MOV        EBX,this
    //         004bb28c     PUSH       EDI
    //         004bb28d     MOV        EDI,dword ptr [ESI + 0x24]
    //         004bb290     MOV        this,ESI
    //         004bb292     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004bb297     IMUL       EAX,EDI
    //                              Shape.cpp:2515 (3)
    //         004bb29a     MOV        EBP,dword ptr [EBX + 0xc]
    //                              Shape.cpp:2523 (44)
    //         004bb29d     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb2a1     ADD        EBP,0x18
    //         004bb2a4     CMP        EDI,0x1
    //         004bb2a7     MOV        dword ptr [ESP + local_4],EAX
    //         004bb2ab     MOV        dword ptr [ESP + param_1],EBP
    //         004bb2af     JGE        LAB_004bb2cb
    //         004bb2b1     MOV        EBX,dword ptr [ESI + 0x1c]
    //         004bb2b4     MOV        this,EDX
    //         004bb2b6     SUB        this,EBX
    //         004bb2b8     INC        this
    //         004bb2b9     IMUL       this,EAX
    //         004bb2bc     MOV        EAX,dword ptr [ESI + 0x8]
    //         004bb2bf     ADD        this,EAX
    //         004bb2c1     MOV        EAX,dword ptr [ESP + param_6]
    //         004bb2c5     LEA        this,[ECX + EAX*this+0x1 + 0x1]
    //                              Shape.cpp:2524 (2)
    //         004bb2c9     JMP        LAB_004bb2db
    //                               LAB_004bb2cb                                                 XREF[1]:     004bb2af(j)  
    //                              Shape.cpp:2525 (16)
    //         004bb2cb     IMUL       EAX,EDX
    //         004bb2ce     MOV        this,dword ptr [ESI + 0x8]
    //         004bb2d1     ADD        EAX,this
    //         004bb2d3     MOV        this,dword ptr [ESP + param_6]
    //         004bb2d7     LEA        this,[EAX + this->shape*0x1 + 0x1]
    //                               LAB_004bb2db                                                 XREF[1]:     004bb2c9(j)  
    //                              Shape.cpp:2529 (18)
    //         004bb2db     MOV        ESI,dword ptr [ESP + param_3]
    //         004bb2df     MOV        dword ptr [ESP + width],this
    //         004bb2e3     CMP        ESI,EDX
    //         004bb2e5     JGE        LAB_004bb328
    //         004bb2e7     SUB        EDX,ESI
    //         004bb2e9     MOV        EDI,EDX
    //         004bb2eb     ADD        ESI,EDI
    //                               LAB_004bb2ed                                                 XREF[1]:     004bb322(j)  
    //                              Shape.cpp:2531 (2)
    //         004bb2ed     XOR        AL,AL
    //                               LAB_004bb2ef                                                 XREF[1]:     004bb31f(j)  
    //                              Shape.cpp:2534 (3)
    //         004bb2ef     MOV        DL,byte ptr [EBP]
    //                              Shape.cpp:2535 (1)
    //         004bb2f2     INC        EBP
    //                              Shape.cpp:2536 (10)
    //         004bb2f3     MOV        BL,DL
    //         004bb2f5     AND        BL,0x1
    //         004bb2f8     CMP        BL,0x1
    //         004bb2fb     JNZ        LAB_004bb313
    //                              Shape.cpp:2538 (6)
    //         004bb2fd     SHR        DL,0x1
    //         004bb2ff     MOV        byte ptr [ESP + param_5],DL
    //                              Shape.cpp:2541 (2)
    //         004bb303     JZ         LAB_004bb31c
    //                              Shape.cpp:2542 (12)
    //         004bb305     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb309     AND        EDX,0xff
    //         004bb30f     ADD        EBP,EDX
    //                              Shape.cpp:2544 (2)
    //         004bb311     JMP        LAB_004bb31d
    //                               LAB_004bb313                                                 XREF[1]:     004bb2fb(j)  
    //                              Shape.cpp:2547 (5)
    //         004bb313     TEST       DL,0xfe
    //         004bb316     JNZ        LAB_004bb31c
    //                              Shape.cpp:2548 (2)
    //         004bb318     MOV        AL,0x1
    //                              Shape.cpp:2549 (2)
    //         004bb31a     JMP        LAB_004bb31d
    //                               LAB_004bb31c                                                 XREF[2]:     004bb303(j), 004bb316(j)  
    //                              Shape.cpp:2550 (1)
    //         004bb31c     INC        EBP
    //                               LAB_004bb31d                                                 XREF[2]:     004bb311(j), 004bb31a(j)  
    //                              Shape.cpp:2532 (4)
    //         004bb31d     TEST       AL,AL
    //         004bb31f     JZ         LAB_004bb2ef
    //                              Shape.cpp:2529 (3)
    //         004bb321     DEC        EDI
    //         004bb322     JNZ        LAB_004bb2ed
    //                              Shape.cpp:2535 (4)
    //         004bb324     MOV        dword ptr [ESP + param_1],EBP
    //                               LAB_004bb328                                                 XREF[1]:     004bb2e5(j)  
    //                              Shape.cpp:2556 (37)
    //         004bb328     MOV        EDX,dword ptr [ESP + param_7]
    //         004bb32c     CMP        ESI,EDX
    //         004bb32e     JG         LAB_004bb5cd
    //         004bb334     MOV        EBP,dword ptr [ESP + param_8]
    //         004bb338     MOV        EDI,dword ptr [ESP + param_1]
    //         004bb33c     SUB        EDX,ESI
    //         004bb33e     MOV        ESI,dword ptr [ESP + param_2]
    //         004bb342     INC        EDX
    //         004bb343     MOV        dword ptr [ESP + param_3],EDX
    //         004bb347     JMP        LAB_004bb34d
    //                               LAB_004bb349                                                 XREF[1]:     004bb5c7(j)  
    //         004bb349     MOV        ESI,dword ptr [ESP + param_2]
    //                               LAB_004bb34d                                                 XREF[1]:     004bb347(j)  
    //                              Shape.cpp:2561 (10)
    //         004bb34d     CMP        ESI,dword ptr [ESP + param_6]
    //         004bb351     JLE        LAB_004bb481
    //                              Shape.cpp:2563 (2)
    //         004bb357     XOR        AL,AL
    //                               LAB_004bb359                                                 XREF[1]:     004bb479(j)  
    //                              Shape.cpp:2566 (2)
    //         004bb359     MOV        DL,byte ptr [EDI]
    //                              Shape.cpp:2567 (1)
    //         004bb35b     INC        EDI
    //                              Shape.cpp:2568 (18)
    //         004bb35c     MOV        BL,DL
    //         004bb35e     MOV        dword ptr [ESP + param_1],EDI
    //         004bb362     AND        BL,0x1
    //         004bb365     CMP        BL,0x1
    //         004bb368     JNZ        LAB_004bb415
    //                              Shape.cpp:2570 (6)
    //         004bb36e     SHR        DL,0x1
    //         004bb370     MOV        byte ptr [ESP + param_5],DL
    //                              Shape.cpp:2571 (2)
    //         004bb374     JNZ        LAB_004bb3a3
    //                              Shape.cpp:2573 (6)
    //         004bb376     XOR        EDX,EDX
    //         004bb378     MOV        DL,byte ptr [EDI]
    //         004bb37a     SUB        ESI,EDX
    //                              Shape.cpp:2575 (13)
    //         004bb37c     MOV        EDX,dword ptr [ESP + param_6]
    //         004bb380     INC        EDI
    //         004bb381     CMP        ESI,EDX
    //         004bb383     JG         LAB_004bb477
    //                              Shape.cpp:2577 (6)
    //         004bb389     CMP        ESI,dword ptr [ESP + param_4]
    //         004bb38d     JGE        LAB_004bb396
    //                              Shape.cpp:2578 (2)
    //         004bb38f     MOV        AL,0x2
    //                              Shape.cpp:2579 (5)
    //         004bb391     JMP        LAB_004bb477
    //                               LAB_004bb396                                                 XREF[1]:     004bb38d(j)  
    //                              Shape.cpp:2582 (8)
    //         004bb396     MOV        EBX,ESI
    //         004bb398     MOV        AL,0x1
    //         004bb39a     SUB        EBX,EDX
    //         004bb39c     ADD        this,EBX
    //                              Shape.cpp:2586 (5)
    //         004bb39e     JMP        LAB_004bb477
    //                               LAB_004bb3a3                                                 XREF[1]:     004bb374(j)  
    //                              Shape.cpp:2588 (4)
    //         004bb3a3     MOV        EDI,dword ptr [ESP + param_5]
    //                              Shape.cpp:2589 (16)
    //         004bb3a7     MOV        EDX,dword ptr [ESP + param_6]
    //         004bb3ab     AND        EDI,0xff
    //         004bb3b1     SUB        ESI,EDI
    //         004bb3b3     CMP        ESI,EDX
    //         004bb3b5     JG         LAB_004bb407
    //                              Shape.cpp:2591 (8)
    //         004bb3b7     MOV        EBX,dword ptr [ESP + param_4]
    //         004bb3bb     CMP        ESI,EBX
    //         004bb3bd     JGE        LAB_004bb3ec
    //                              Shape.cpp:2594 (5)
    //         004bb3bf     SUB        EDX,EBX
    //         004bb3c1     MOV        AL,0x2
    //         004bb3c3     INC        EDX
    //                              Shape.cpp:2595 (4)
    //         004bb3c4     TEST       DL,DL
    //         004bb3c6     JBE        LAB_004bb407
    //                              Shape.cpp:2756 (6)
    //         004bb3c8     AND        EDX,0xff
    //                               LAB_004bb3ce                                                 XREF[1]:     004bb3d9(j)  
    //                              Shape.cpp:2597 (1)
    //         004bb3ce     DEC        this
    //                              Shape.cpp:2598 (12)
    //         004bb3cf     XOR        EBX,EBX
    //         004bb3d1     DEC        EDX
    //         004bb3d2     MOV        BL,byte ptr [this->shape]
    //         004bb3d4     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb3d7     MOV        byte ptr [this->shape],BL
    //         004bb3d9     JNZ        LAB_004bb3ce
    //                              Shape.cpp:2612 (10)
    //         004bb3db     MOV        EDX,dword ptr [ESP + param_1]
    //         004bb3df     ADD        EDX,EDI
    //         004bb3e1     MOV        dword ptr [ESP + param_1],EDX
    //                              Shape.cpp:2615 (7)
    //         004bb3e5     MOV        EDI,EDX
    //         004bb3e7     JMP        LAB_004bb477
    //                               LAB_004bb3ec                                                 XREF[1]:     004bb3bd(j)  
    //                              Shape.cpp:2564 (2)
    //         004bb3ec     SUB        EDX,ESI
    //                              Shape.cpp:2603 (2)
    //         004bb3ee     MOV        AL,0x1
    //                              Shape.cpp:2605 (4)
    //         004bb3f0     TEST       DL,DL
    //         004bb3f2     JBE        LAB_004bb407
    //                              Shape.cpp:2756 (6)
    //         004bb3f4     AND        EDX,0xff
    //                               LAB_004bb3fa                                                 XREF[1]:     004bb405(j)  
    //                              Shape.cpp:2607 (1)
    //         004bb3fa     DEC        this
    //                              Shape.cpp:2608 (12)
    //         004bb3fb     XOR        EBX,EBX
    //         004bb3fd     DEC        EDX
    //         004bb3fe     MOV        BL,byte ptr [this->shape]
    //         004bb400     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb403     MOV        byte ptr [this->shape],BL
    //         004bb405     JNZ        LAB_004bb3fa
    //                               LAB_004bb407                                                 XREF[3]:     004bb3b5(j), 004bb3c6(j), 
    //                                                                                                         004bb3f2(j)  
    //                              Shape.cpp:2612 (10)
    //         004bb407     MOV        EDX,dword ptr [ESP + param_1]
    //         004bb40b     ADD        EDX,EDI
    //         004bb40d     MOV        dword ptr [ESP + param_1],EDX
    //                              Shape.cpp:2615 (4)
    //         004bb411     MOV        EDI,EDX
    //         004bb413     JMP        LAB_004bb477
    //                               LAB_004bb415                                                 XREF[1]:     004bb368(j)  
    //                              Shape.cpp:2617 (6)
    //         004bb415     SHR        DL,0x1
    //         004bb417     MOV        byte ptr [ESP + param_5],DL
    //                              Shape.cpp:2618 (2)
    //         004bb41b     JNZ        LAB_004bb421
    //                              Shape.cpp:2619 (2)
    //         004bb41d     MOV        AL,0x3
    //                              Shape.cpp:2620 (2)
    //         004bb41f     JMP        LAB_004bb477
    //                               LAB_004bb421                                                 XREF[1]:     004bb41b(j)  
    //                              Shape.cpp:2622 (12)
    //         004bb421     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb425     AND        EDX,0xff
    //         004bb42b     SUB        ESI,EDX
    //                              Shape.cpp:2623 (8)
    //         004bb42d     MOV        EDX,dword ptr [ESP + param_6]
    //         004bb431     CMP        ESI,EDX
    //         004bb433     JG         LAB_004bb476
    //                              Shape.cpp:2625 (8)
    //         004bb435     MOV        EBX,dword ptr [ESP + param_4]
    //         004bb439     CMP        ESI,EBX
    //         004bb43b     JGE        LAB_004bb45b
    //                              Shape.cpp:2628 (5)
    //         004bb43d     SUB        EDX,EBX
    //         004bb43f     MOV        AL,0x2
    //         004bb441     INC        EDX
    //                              Shape.cpp:2629 (4)
    //         004bb442     TEST       DL,DL
    //         004bb444     JBE        LAB_004bb476
    //                              Shape.cpp:2756 (6)
    //         004bb446     AND        EDX,0xff
    //                               LAB_004bb44c                                                 XREF[1]:     004bb457(j)  
    //                              Shape.cpp:2631 (1)
    //         004bb44c     DEC        this
    //                              Shape.cpp:2632 (12)
    //         004bb44d     XOR        EBX,EBX
    //         004bb44f     DEC        EDX
    //         004bb450     MOV        BL,byte ptr [this->shape]
    //         004bb452     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb455     MOV        byte ptr [this->shape],BL
    //         004bb457     JNZ        LAB_004bb44c
    //                              Shape.cpp:2635 (2)
    //         004bb459     JMP        LAB_004bb476
    //                               LAB_004bb45b                                                 XREF[1]:     004bb43b(j)  
    //                              Shape.cpp:2564 (2)
    //         004bb45b     SUB        EDX,ESI
    //                              Shape.cpp:2637 (2)
    //         004bb45d     MOV        AL,0x1
    //                              Shape.cpp:2639 (4)
    //         004bb45f     TEST       DL,DL
    //         004bb461     JBE        LAB_004bb476
    //                              Shape.cpp:2756 (6)
    //         004bb463     AND        EDX,0xff
    //                               LAB_004bb469                                                 XREF[1]:     004bb474(j)  
    //                              Shape.cpp:2641 (1)
    //         004bb469     DEC        this
    //                              Shape.cpp:2642 (12)
    //         004bb46a     XOR        EBX,EBX
    //         004bb46c     DEC        EDX
    //         004bb46d     MOV        BL,byte ptr [this->shape]
    //         004bb46f     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb472     MOV        byte ptr [this->shape],BL
    //         004bb474     JNZ        LAB_004bb469
    //                               LAB_004bb476                                                 XREF[4]:     004bb433(j), 004bb444(j), 
    //                                                                                                         004bb459(j), 004bb461(j)  
    //                              Shape.cpp:2646 (1)
    //         004bb476     INC        EDI
    //                               LAB_004bb477                                                 XREF[6]:     004bb383(j), 004bb391(j), 
    //                                                                                                         004bb39e(j), 004bb3e7(j), 
    //                                                                                                         004bb413(j), 004bb41f(j)  
    //                              Shape.cpp:2564 (8)
    //         004bb477     TEST       AL,AL
    //         004bb479     JZ         LAB_004bb359
    //                              Shape.cpp:2651 (2)
    //         004bb47f     JMP        LAB_004bb483
    //                               LAB_004bb481                                                 XREF[1]:     004bb351(j)  
    //                              Shape.cpp:2652 (2)
    //         004bb481     MOV        AL,0x1
    //                               LAB_004bb483                                                 XREF[1]:     004bb47f(j)  
    //                              Shape.cpp:2655 (2)
    //         004bb483     DEC        AL
    //                              Shape.cpp:2656 (6)
    //         004bb485     JNZ        LAB_004bb57b
    //                               LAB_004bb48b                                                 XREF[1]:     004bb575(j)  
    //                              Shape.cpp:2658 (2)
    //         004bb48b     MOV        DL,byte ptr [EDI]
    //                              Shape.cpp:2659 (1)
    //         004bb48d     INC        EDI
    //                              Shape.cpp:2660 (14)
    //         004bb48e     MOV        BL,DL
    //         004bb490     MOV        dword ptr [ESP + param_1],EDI
    //         004bb494     AND        BL,0x1
    //         004bb497     CMP        BL,0x1
    //         004bb49a     JNZ        LAB_004bb516
    //                              Shape.cpp:2662 (6)
    //         004bb49c     SHR        DL,0x1
    //         004bb49e     MOV        byte ptr [ESP + param_5],DL
    //                              Shape.cpp:2663 (2)
    //         004bb4a2     JNZ        LAB_004bb4c0
    //                              Shape.cpp:2665 (6)
    //         004bb4a4     XOR        EDX,EDX
    //         004bb4a6     MOV        DL,byte ptr [EDI]
    //         004bb4a8     SUB        ESI,EDX
    //                              Shape.cpp:2666 (2)
    //         004bb4aa     SUB        this,EDX
    //                              Shape.cpp:2668 (13)
    //         004bb4ac     MOV        EDX,dword ptr [ESP + param_4]
    //         004bb4b0     INC        EDI
    //         004bb4b1     CMP        ESI,EDX
    //         004bb4b3     JGE        LAB_004bb573
    //                              Shape.cpp:2669 (2)
    //         004bb4b9     MOV        AL,BL
    //                              Shape.cpp:2671 (5)
    //         004bb4bb     JMP        LAB_004bb573
    //                               LAB_004bb4c0                                                 XREF[1]:     004bb4a2(j)  
    //                              Shape.cpp:2673 (4)
    //         004bb4c0     MOV        EDI,dword ptr [ESP + param_5]
    //                              Shape.cpp:2674 (16)
    //         004bb4c4     MOV        EBX,dword ptr [ESP + param_4]
    //         004bb4c8     AND        EDI,0xff
    //         004bb4ce     SUB        ESI,EDI
    //         004bb4d0     CMP        ESI,EBX
    //         004bb4d2     JGE        LAB_004bb4fb
    //                              Shape.cpp:2677 (8)
    //         004bb4d4     MOV        EDX,ESI
    //         004bb4d6     MOV        AL,0x1
    //         004bb4d8     SUB        EDX,EBX
    //         004bb4da     ADD        EDX,EDI
    //                              Shape.cpp:2678 (4)
    //         004bb4dc     TEST       DL,DL
    //         004bb4de     JBE        LAB_004bb50e
    //                              Shape.cpp:2756 (6)
    //         004bb4e0     AND        EDX,0xff
    //                               LAB_004bb4e6                                                 XREF[1]:     004bb4f1(j)  
    //                              Shape.cpp:2680 (1)
    //         004bb4e6     DEC        this
    //                              Shape.cpp:2681 (12)
    //         004bb4e7     XOR        EBX,EBX
    //         004bb4e9     DEC        EDX
    //         004bb4ea     MOV        BL,byte ptr [this->shape]
    //         004bb4ec     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb4ef     MOV        byte ptr [this->shape],BL
    //         004bb4f1     JNZ        LAB_004bb4e6
    //                              Shape.cpp:2692 (6)
    //         004bb4f3     MOV        EDX,dword ptr [ESP + param_1]
    //         004bb4f7     ADD        EDX,EDI
    //                              Shape.cpp:2695 (2)
    //         004bb4f9     JMP        LAB_004bb56d
    //                               LAB_004bb4fb                                                 XREF[1]:     004bb4d2(j)  
    //                              Shape.cpp:2686 (4)
    //         004bb4fb     TEST       DL,DL
    //         004bb4fd     JBE        LAB_004bb50e
    //                              Shape.cpp:2756 (2)
    //         004bb4ff     MOV        EDX,EDI
    //                               LAB_004bb501                                                 XREF[1]:     004bb50c(j)  
    //                              Shape.cpp:2688 (1)
    //         004bb501     DEC        this
    //                              Shape.cpp:2689 (12)
    //         004bb502     XOR        EBX,EBX
    //         004bb504     DEC        EDX
    //         004bb505     MOV        BL,byte ptr [this->shape]
    //         004bb507     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb50a     MOV        byte ptr [this->shape],BL
    //         004bb50c     JNZ        LAB_004bb501
    //                               LAB_004bb50e                                                 XREF[2]:     004bb4de(j), 004bb4fd(j)  
    //                              Shape.cpp:2692 (6)
    //         004bb50e     MOV        EDX,dword ptr [ESP + param_1]
    //         004bb512     ADD        EDX,EDI
    //                              Shape.cpp:2695 (2)
    //         004bb514     JMP        LAB_004bb56d
    //                               LAB_004bb516                                                 XREF[1]:     004bb49a(j)  
    //                              Shape.cpp:2697 (6)
    //         004bb516     SHR        DL,0x1
    //         004bb518     MOV        byte ptr [ESP + param_5],DL
    //                              Shape.cpp:2698 (2)
    //         004bb51c     JNZ        LAB_004bb522
    //                              Shape.cpp:2699 (2)
    //         004bb51e     MOV        AL,0x3
    //                              Shape.cpp:2700 (2)
    //         004bb520     JMP        LAB_004bb573
    //                               LAB_004bb522                                                 XREF[1]:     004bb51c(j)  
    //                              Shape.cpp:2702 (4)
    //         004bb522     MOV        EDI,dword ptr [ESP + param_5]
    //                              Shape.cpp:2703 (16)
    //         004bb526     MOV        EBX,dword ptr [ESP + param_4]
    //         004bb52a     AND        EDI,0xff
    //         004bb530     SUB        ESI,EDI
    //         004bb532     CMP        ESI,EBX
    //         004bb534     JGE        LAB_004bb557
    //                              Shape.cpp:2706 (8)
    //         004bb536     MOV        EDX,ESI
    //         004bb538     MOV        AL,0x1
    //         004bb53a     SUB        EDX,EBX
    //         004bb53c     ADD        EDX,EDI
    //                              Shape.cpp:2707 (4)
    //         004bb53e     TEST       DL,DL
    //         004bb540     JBE        LAB_004bb568
    //                              Shape.cpp:2756 (6)
    //         004bb542     AND        EDX,0xff
    //                               LAB_004bb548                                                 XREF[1]:     004bb553(j)  
    //                              Shape.cpp:2709 (1)
    //         004bb548     DEC        this
    //                              Shape.cpp:2710 (12)
    //         004bb549     XOR        EBX,EBX
    //         004bb54b     DEC        EDX
    //         004bb54c     MOV        BL,byte ptr [this->shape]
    //         004bb54e     MOV        BL,byte ptr [EBX + EBP*0x1]
    //         004bb551     MOV        byte ptr [this->shape],BL
    //         004bb553     JNZ        LAB_004bb548
    //                              Shape.cpp:2713 (2)
    //         004bb555     JMP        LAB_004bb568
    //                               LAB_004bb557                                                 XREF[1]:     004bb534(j)  
    //                              Shape.cpp:2715 (4)
    //         004bb557     TEST       DL,DL
    //         004bb559     JBE        LAB_004bb568
    //                               LAB_004bb55b                                                 XREF[1]:     004bb566(j)  
    //                              Shape.cpp:2717 (1)
    //         004bb55b     DEC        this
    //                              Shape.cpp:2718 (12)
    //         004bb55c     XOR        EDX,EDX
    //         004bb55e     DEC        EDI
    //         004bb55f     MOV        DL,byte ptr [this->shape]
    //         004bb561     MOV        DL,byte ptr [EDX + EBP*0x1]
    //         004bb564     MOV        byte ptr [this->shape],DL
    //         004bb566     JNZ        LAB_004bb55b
    //                               LAB_004bb568                                                 XREF[3]:     004bb540(j), 004bb555(j), 
    //                                                                                                         004bb559(j)  
    //                              Shape.cpp:2721 (11)
    //         004bb568     MOV        EDX,dword ptr [ESP + param_1]
    //         004bb56c     INC        EDX
    //                               LAB_004bb56d                                                 XREF[2]:     004bb4f9(j), 004bb514(j)  
    //         004bb56d     MOV        dword ptr [ESP + param_1],EDX
    //         004bb571     MOV        EDI,EDX
    //                               LAB_004bb573                                                 XREF[3]:     004bb4b3(j), 004bb4bb(j), 
    //                                                                                                         004bb520(j)  
    //                              Shape.cpp:2656 (8)
    //         004bb573     TEST       AL,AL
    //         004bb575     JZ         LAB_004bb48b
    //                               LAB_004bb57b                                                 XREF[1]:     004bb485(j)  
    //                              Shape.cpp:2727 (2)
    //         004bb57b     DEC        AL
    //                              Shape.cpp:2728 (2)
    //         004bb57d     JNZ        LAB_004bb5b0
    //                               LAB_004bb57f                                                 XREF[1]:     004bb5ae(j)  
    //                              Shape.cpp:2730 (2)
    //         004bb57f     MOV        this,byte ptr [EDI]
    //                              Shape.cpp:2731 (1)
    //         004bb581     INC        EDI
    //                              Shape.cpp:2732 (10)
    //         004bb582     MOV        DL,this
    //         004bb584     AND        DL,0x1
    //         004bb587     CMP        DL,0x1
    //         004bb58a     JNZ        LAB_004bb5a2
    //                              Shape.cpp:2734 (6)
    //         004bb58c     SHR        this,0x1
    //         004bb58e     MOV        byte ptr [ESP + param_5],this
    //                              Shape.cpp:2737 (2)
    //         004bb592     JZ         LAB_004bb5ab
    //                              Shape.cpp:2738 (12)
    //         004bb594     MOV        this,dword ptr [ESP + param_5]
    //         004bb598     AND        this,0xff
    //         004bb59e     ADD        EDI,this
    //                              Shape.cpp:2740 (2)
    //         004bb5a0     JMP        LAB_004bb5ac
    //                               LAB_004bb5a2                                                 XREF[1]:     004bb58a(j)  
    //                              Shape.cpp:2743 (5)
    //         004bb5a2     TEST       this,0xfe
    //         004bb5a5     JNZ        LAB_004bb5ab
    //                              Shape.cpp:2744 (2)
    //         004bb5a7     MOV        AL,0x2
    //                              Shape.cpp:2745 (2)
    //         004bb5a9     JMP        LAB_004bb5ac
    //                               LAB_004bb5ab                                                 XREF[2]:     004bb592(j), 004bb5a5(j)  
    //                              Shape.cpp:2746 (1)
    //         004bb5ab     INC        EDI
    //                               LAB_004bb5ac                                                 XREF[2]:     004bb5a0(j), 004bb5a9(j)  
    //                              Shape.cpp:2728 (4)
    //         004bb5ac     TEST       AL,AL
    //         004bb5ae     JZ         LAB_004bb57f
    //                               LAB_004bb5b0                                                 XREF[1]:     004bb57d(j)  
    //                              Shape.cpp:2751 (29)
    //         004bb5b0     MOV        this,dword ptr [ESP + width]
    //         004bb5b4     MOV        EDX,dword ptr [ESP + local_4]
    //         004bb5b8     MOV        EAX,dword ptr [ESP + param_3]
    //         004bb5bc     ADD        this,EDX
    //         004bb5be     DEC        EAX
    //         004bb5bf     MOV        dword ptr [ESP + width],this
    //         004bb5c3     MOV        dword ptr [ESP + param_3],EAX
    //         004bb5c7     JNZ        LAB_004bb349
    //                               LAB_004bb5cd                                                 XREF[1]:     004bb32e(j)  
    //                              Shape.cpp:2756 (12)
    //         004bb5cd     POP        EDI
    //         004bb5ce     POP        ESI
    //         004bb5cf     POP        EBP
    //         004bb5d0     MOV        AL,0x1
    //         004bb5d2     POP        EBX
    //         004bb5d3     ADD        ESP,0x8
    //         004bb5d6     RET        0x20
}

// Offset: 0x004BB5E0
uchar shape_dither(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TShape::shape_dither(class TDrawArea *,long,long,long,long,long)     *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_dither(TShape * this, TDrawArea * param_1, lo
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[5]:     004bb5e3(R), 004bb6b2(R), 004bb6c2(R), 004bb710(R), 
    //                                                                                     004bb742(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[8]:     004bb629(R), 004bb656(W), 004bb668(W), 004bb692(R), 
    //                                                                                     004bb69a(W), 004bb6d6(R), 004bb6ee(R), 004bb73b(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[7]:     004bb62d(R), 004bb65e(W), 004bb682(W), 004bb6be(W), 
    //                                                                                     004bb6da(R), 004bb6fa(R), 004bb730(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[8]:     004bb5f0(R), 004bb65a(W), 004bb674(W), 004bb6a2(R), 
    //                                                                                     004bb6aa(W), 004bb6e6(R), 004bb6f4(R), 004bb736(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[2]:     004bb709(R), 004bb72b(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[2]:     004bb704(R), 004bb726(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004bb613(W), 004bb686(R)  
    //              tagRECT           Stack[-0x14]   rect                      XREF[5,6]:   004bb662(W), 004bb68e(W), 004bb6c6(R), 004bb6d2(W), 
    //                                                                                     004bb6e2(R), 004bb5fb(W), 004bb64c(R), 004bb603(W), 
    //                                                                                     004bb66c(R), 004bb60a(W), 004bb678(R)  
    //              long              Stack[-0x18]:4 clip_y1
    //                               ?shape_dither@TShape@@QAEEPAVTDrawArea@@JJJJJ@Z
    //                               TShape::shape_dither
    //                              Shape.cpp:2761 (3)
    //         004bb5e0     SUB        ESP,0x14
    //                              Shape.cpp:2771 (13)
    //         004bb5e3     MOV        EAX,dword ptr [ESP + param_1]
    //         004bb5e7     PUSH       EBX
    //         004bb5e8     PUSH       EBP
    //         004bb5e9     PUSH       ESI
    //         004bb5ea     ADD        EAX,0x28
    //         004bb5ed     MOV        ESI,this
    //         004bb5ef     PUSH       EDI
    //                              Shape.cpp:2773 (46)
    //         004bb5f0     MOV        EDI,dword ptr [ESP + param_4]
    //         004bb5f4     MOV        this,dword ptr [EAX]
    //         004bb5f6     PUSH       s_RGL_shape_draw                                 = "RGL_shape_draw"
    //         004bb5fb     MOV        dword ptr [ESP + rect.top],this
    //         004bb5ff     PUSH       EDI
    //         004bb600     MOV        EDX,dword ptr [EAX + 0x4]
    //         004bb603     MOV        dword ptr [ESP + rect.right],EDX
    //         004bb607     MOV        this,dword ptr [EAX + 0x8]
    //         004bb60a     MOV        dword ptr [ESP + rect.bottom],this
    //         004bb60e     MOV        this,ESI
    //         004bb610     MOV        EDX,dword ptr [EAX + 0xc]
    //         004bb613     MOV        dword ptr [ESP + local_4],EDX
    //         004bb617     CALL       TShape::Check_shape                              uchar Check_shape(TShape * this, long param_1
    //         004bb61c     TEST       AL,AL
    //                              Shape.cpp:2774 (6)
    //         004bb61e     JNZ        LAB_004bb758
    //                              Shape.cpp:2776 (5)
    //         004bb624     MOV        EAX,dword ptr [ESI + 0x14]
    //         004bb627     MOV        EDX,dword ptr [ESI]
    //                              Shape.cpp:2778 (4)
    //         004bb629     MOV        EBX,dword ptr [ESP + param_2]
    //                              Shape.cpp:2779 (19)
    //         004bb62d     MOV        EBP,dword ptr [ESP + param_3]
    //         004bb631     MOV        this,dword ptr [EAX + EDI*0x8]
    //         004bb634     LEA        EAX,[this->shape + EDX*0x1]
    //         004bb637     MOV        dword ptr [ESI + 0xc],EAX
    //         004bb63a     MOV        this,dword ptr [EAX + 0x8]
    //         004bb63d     MOV        EDX,dword ptr [EAX + 0xc]
    //                              Shape.cpp:2780 (3)
    //         004bb640     MOV        EDI,dword ptr [EAX + 0x10]
    //                              Shape.cpp:2781 (9)
    //         004bb643     MOV        EAX,dword ptr [EAX + 0x14]
    //         004bb646     ADD        EDX,EBP
    //         004bb648     ADD        EDI,EBX
    //         004bb64a     ADD        EAX,EBP
    //                              Shape.cpp:2783 (32)
    //         004bb64c     MOV        EBP,dword ptr [ESP + rect.top]
    //         004bb650     ADD        this,EBX
    //         004bb652     MOV        EBX,EDI
    //         004bb654     CMP        this,EBP
    //         004bb656     MOV        dword ptr [ESP + param_2],this
    //         004bb65a     MOV        dword ptr [ESP + param_4],EDX
    //         004bb65e     MOV        dword ptr [ESP + param_3],EBX
    //         004bb662     MOV        dword ptr [ESP + rect.left],EAX
    //         004bb666     JGE        LAB_004bb66c
    //         004bb668     MOV        dword ptr [ESP + param_2],EBP
    //                               LAB_004bb66c                                                 XREF[1]:     004bb666(j)  
    //                              Shape.cpp:2784 (12)
    //         004bb66c     MOV        EBP,dword ptr [ESP + rect.right]
    //         004bb670     CMP        EDX,EBP
    //         004bb672     JGE        LAB_004bb678
    //         004bb674     MOV        dword ptr [ESP + param_4],EBP
    //                               LAB_004bb678                                                 XREF[1]:     004bb672(j)  
    //                              Shape.cpp:2785 (14)
    //         004bb678     MOV        EBP,dword ptr [ESP + rect.bottom]
    //         004bb67c     CMP        EDI,EBP
    //         004bb67e     JLE        LAB_004bb686
    //         004bb680     MOV        EBX,EBP
    //         004bb682     MOV        dword ptr [ESP + param_3],EBX
    //                               LAB_004bb686                                                 XREF[1]:     004bb67e(j)  
    //                              Shape.cpp:2786 (12)
    //         004bb686     MOV        EBP,dword ptr [ESP + local_4]
    //         004bb68a     CMP        EAX,EBP
    //         004bb68c     JLE        LAB_004bb692
    //         004bb68e     MOV        dword ptr [ESP + rect.left],EBP
    //                               LAB_004bb692                                                 XREF[1]:     004bb68c(j)  
    //                              Shape.cpp:2788 (16)
    //         004bb692     MOV        EBP,dword ptr [ESP + param_2]
    //         004bb696     TEST       EBP,EBP
    //         004bb698     JGE        LAB_004bb6a2
    //         004bb69a     MOV        dword ptr [ESP + param_2],0x0
    //                               LAB_004bb6a2                                                 XREF[1]:     004bb698(j)  
    //                              Shape.cpp:2789 (16)
    //         004bb6a2     MOV        EBP,dword ptr [ESP + param_4]
    //         004bb6a6     TEST       EBP,EBP
    //         004bb6a8     JGE        LAB_004bb6b2
    //         004bb6aa     MOV        dword ptr [ESP + param_4],0x0
    //                               LAB_004bb6b2                                                 XREF[1]:     004bb6a8(j)  
    //                              Shape.cpp:2790 (16)
    //         004bb6b2     MOV        EBP,dword ptr [ESP + param_1]
    //         004bb6b6     MOV        EBP,dword ptr [EBP + 0x18]
    //         004bb6b9     CMP        EBX,EBP
    //         004bb6bb     JL         LAB_004bb6c2
    //         004bb6bd     DEC        EBP
    //         004bb6be     MOV        dword ptr [ESP + param_3],EBP
    //                               LAB_004bb6c2                                                 XREF[1]:     004bb6bb(j)  
    //                              Shape.cpp:2791 (20)
    //         004bb6c2     MOV        EBX,dword ptr [ESP + param_1]
    //         004bb6c6     MOV        EBP,dword ptr [ESP + rect.left]
    //         004bb6ca     MOV        EBX,dword ptr [EBX + 0x1c]
    //         004bb6cd     CMP        EBP,EBX
    //         004bb6cf     JL         LAB_004bb6d6
    //         004bb6d1     DEC        EBX
    //         004bb6d2     MOV        dword ptr [ESP + rect.left],EBX
    //                               LAB_004bb6d6                                                 XREF[1]:     004bb6cf(j)  
    //                              Shape.cpp:2793 (24)
    //         004bb6d6     MOV        EBX,dword ptr [ESP + param_2]
    //         004bb6da     MOV        EBP,dword ptr [ESP + param_3]
    //         004bb6de     CMP        EBP,EBX
    //         004bb6e0     JL         LAB_004bb758
    //         004bb6e2     MOV        EBX,dword ptr [ESP + rect.left]
    //         004bb6e6     MOV        EBP,dword ptr [ESP + param_4]
    //         004bb6ea     CMP        EBX,EBP
    //         004bb6ec     JL         LAB_004bb758
    //                              Shape.cpp:2795 (22)
    //         004bb6ee     CMP        dword ptr [ESP + param_2],this
    //         004bb6f2     JNZ        LAB_004bb726
    //         004bb6f4     CMP        dword ptr [ESP + param_4],EDX
    //         004bb6f8     JNZ        LAB_004bb726
    //         004bb6fa     CMP        dword ptr [ESP + param_3],EDI
    //         004bb6fe     JNZ        LAB_004bb726
    //         004bb700     CMP        EBX,EAX
    //         004bb702     JNZ        LAB_004bb726
    //                              Shape.cpp:2796 (24)
    //         004bb704     MOV        EAX,dword ptr [ESP + param_6]
    //         004bb708     PUSH       EAX
    //         004bb709     MOV        EAX,dword ptr [ESP + param_5]
    //         004bb70d     PUSH       EAX
    //         004bb70e     PUSH       EDX
    //         004bb70f     PUSH       this
    //         004bb710     MOV        this,dword ptr [ESP + param_1]
    //         004bb714     PUSH       this
    //         004bb715     MOV        this,ESI
    //         004bb717     CALL       TShape::shape_dithered_unclipped                 uchar shape_dithered_unclipped(TShape * this,
    //                              Shape.cpp:2801 (10)
    //         004bb71c     POP        EDI
    //         004bb71d     POP        ESI
    //         004bb71e     POP        EBP
    //         004bb71f     POP        EBX
    //         004bb720     ADD        ESP,0x14
    //         004bb723     RET        0x18
    //                               LAB_004bb726                                                 XREF[4]:     004bb6f2(j), 004bb6f8(j), 
    //                                                                                                         004bb6fe(j), 004bb702(j)  
    //                              Shape.cpp:2798 (40)
    //         004bb726     MOV        EAX,dword ptr [ESP + param_6]
    //         004bb72a     PUSH       EAX
    //         004bb72b     MOV        EAX,dword ptr [ESP + param_5]
    //         004bb72f     PUSH       EAX
    //         004bb730     MOV        EAX,dword ptr [ESP + param_3]
    //         004bb734     PUSH       EBX
    //         004bb735     PUSH       EAX
    //         004bb736     MOV        EAX,dword ptr [ESP + param_4]
    //         004bb73a     PUSH       EAX
    //         004bb73b     MOV        EAX,dword ptr [ESP + param_2]
    //         004bb73f     PUSH       EAX
    //         004bb740     PUSH       EDX
    //         004bb741     PUSH       this
    //         004bb742     MOV        this,dword ptr [ESP + param_1]
    //         004bb746     PUSH       this
    //         004bb747     MOV        this,ESI
    //         004bb749     CALL       TShape::shape_dithered_clipped                   uchar shape_dithered_clipped(TShape * this, T
    //                              Shape.cpp:2801 (22)
    //         004bb74e     POP        EDI
    //         004bb74f     POP        ESI
    //         004bb750     POP        EBP
    //         004bb751     POP        EBX
    //         004bb752     ADD        ESP,0x14
    //         004bb755     RET        0x18
    //                               LAB_004bb758                                                 XREF[3]:     004bb61e(j), 004bb6e0(j), 
    //                                                                                                         004bb6ec(j)  
    //         004bb758     POP        EDI
    //         004bb759     POP        ESI
    //         004bb75a     POP        EBP
    //         004bb75b     XOR        AL,AL
    //         004bb75d     POP        EBX
    //         004bb75e     ADD        ESP,0x14
    //         004bb761     RET        0x18
}

// Offset: 0x004BB770
uchar shape_dithered_unclipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_dithered_unclipped(class TDrawArea *,long,long,lon... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_dithered_unclipped(TShape * this, TDrawArea *
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[4]:     004bb776(R), 004bb7e9(W), 004bb7fb(R), 004bb809(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[7]:     004bb7c1(R), 004bb84e(W), 004bb857(W), 004bb85b(R), 
    //                                                                                     004bb89f(W), 004bb8a8(W), 004bb8ac(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[5]:     004bb7a4(R), 004bb7b5(R), 004bb80d(W), 004bb896(W), 
    //                                                                                     004bb8d7(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[3]:     004bb7c5(R), 004bb822(W), 004bb885(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004bb7cf(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004bb797(W), 004bb8e7(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004bb7d8(W), 004bb8e3(R), 004bb8ee(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer
    //                               ?shape_dithered_unclipped@TShape@@AAEEPAVTDrawArea@@JJJJ@Z   XREF[1]:     shape_dither:004bb717(c)  
    //                               TShape::shape_dithered_unclipped
    //                              Shape.cpp:2805 (6)
    //         004bb770     SUB        ESP,0x8
    //         004bb773     PUSH       EBX
    //         004bb774     PUSH       EBP
    //         004bb775     PUSH       ESI
    //                              Shape.cpp:2806 (17)
    //         004bb776     MOV        ESI,dword ptr [ESP + param_1]
    //         004bb77a     MOV        EBX,this
    //         004bb77c     PUSH       EDI
    //         004bb77d     MOV        EDI,dword ptr [ESI + 0x24]
    //         004bb780     MOV        this,ESI
    //         004bb782     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //                              Shape.cpp:2807 (21)
    //         004bb787     MOV        this,dword ptr [EBX + 0xc]
    //         004bb78a     MOV        EDX,EAX
    //         004bb78c     IMUL       EDX,EDI
    //         004bb78f     MOV        EAX,dword ptr [ECX + this->offsets]
    //         004bb792     MOV        EBP,dword ptr [ECX + this->shape_header]
    //         004bb795     SUB        EAX,EBP
    //         004bb797     MOV        dword ptr [ESP + local_4],EDX
    //         004bb79b     INC        EAX
    //                              Shape.cpp:2819 (8)
    //         004bb79c     CMP        EDI,0x1
    //         004bb79f     LEA        EBP,[ECX + this->FShape]
    //         004bb7a2     JGE        LAB_004bb7b5
    //                              Shape.cpp:2820 (15)
    //         004bb7a4     MOV        EDI,dword ptr [ESP + param_3]
    //         004bb7a8     MOV        EBX,dword ptr [ESI + 0x1c]
    //         004bb7ab     MOV        this,EDI
    //         004bb7ad     SUB        this,EBX
    //         004bb7af     INC        this
    //         004bb7b0     IMUL       this,EDX
    //                              Shape.cpp:2821 (2)
    //         004bb7b3     JMP        LAB_004bb7be
    //                               LAB_004bb7b5                                                 XREF[1]:     004bb7a2(j)  
    //                              Shape.cpp:2822 (16)
    //         004bb7b5     MOV        EDI,dword ptr [ESP + param_3]
    //         004bb7b9     MOV        this,EDX
    //         004bb7bb     IMUL       this,EDI
    //                               LAB_004bb7be                                                 XREF[1]:     004bb7b3(j)  
    //         004bb7be     MOV        EBX,dword ptr [ESI + 0x8]
    //         004bb7c1     MOV        EDX,dword ptr [ESP + param_2]
    //                              Shape.cpp:2825 (10)
    //         004bb7c5     MOV        ESI,dword ptr [ESP + param_4]
    //         004bb7c9     ADD        this,EBX
    //         004bb7cb     ADD        this,EDX
    //         004bb7cd     ADD        ESI,EDX
    //                              Shape.cpp:2826 (18)
    //         004bb7cf     MOV        EDX,dword ptr [ESP + param_5]
    //         004bb7d3     AND        ESI,0x1
    //         004bb7d6     ADD        EDX,EDI
    //         004bb7d8     MOV        dword ptr [ESP + width],this
    //         004bb7dc     TEST       DL,0x1
    //         004bb7df     JZ         LAB_004bb7ef
    //                              Shape.cpp:2827 (14)
    //         004bb7e1     XOR        EDX,EDX
    //         004bb7e3     CMP        ESI,0x1
    //         004bb7e6     SETNZ      DL
    //         004bb7e9     MOV        dword ptr [ESP + param_1],EDX
    //         004bb7ed     MOV        ESI,EDX
    //                               LAB_004bb7ef                                                 XREF[1]:     004bb7df(j)  
    //                              Shape.cpp:2828 (16)
    //         004bb7ef     TEST       EAX,EAX
    //         004bb7f1     JLE        LAB_004bb8f8
    //         004bb7f7     MOV        EDI,EAX
    //         004bb7f9     JMP        LAB_004bb7ff
    //                               LAB_004bb7fb                                                 XREF[1]:     004bb8f2(j)  
    //         004bb7fb     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_004bb7ff                                                 XREF[1]:     004bb7f9(j)  
    //                              Shape.cpp:2831 (14)
    //         004bb7ff     XOR        EAX,EAX
    //         004bb801     CMP        ESI,0x1
    //         004bb804     SETNZ      AL
    //         004bb807     MOV        EDX,ESI
    //         004bb809     MOV        dword ptr [ESP + param_1],EAX
    //                              Shape.cpp:2832 (5)
    //         004bb80d     MOV        byte ptr [ESP + param_3],0x0
    //                               LAB_004bb812                                                 XREF[1]:     004bb8dd(j)  
    //                              Shape.cpp:2835 (3)
    //         004bb812     MOV        AL,byte ptr [EBP]
    //                              Shape.cpp:2836 (1)
    //         004bb815     INC        EBP
    //                              Shape.cpp:2837 (10)
    //         004bb816     MOV        BL,AL
    //         004bb818     AND        BL,0x1
    //         004bb81b     CMP        BL,0x1
    //         004bb81e     JNZ        LAB_004bb892
    //                              Shape.cpp:2839 (6)
    //         004bb820     SHR        AL,0x1
    //         004bb822     MOV        byte ptr [ESP + param_4],AL
    //                              Shape.cpp:2840 (2)
    //         004bb826     JNZ        LAB_004bb84c
    //                              Shape.cpp:2842 (13)
    //         004bb828     MOV        AL,byte ptr [EBP]
    //         004bb82b     MOV        ESI,EAX
    //         004bb82d     AND        ESI,0xff
    //         004bb833     ADD        this,ESI
    //                              Shape.cpp:2843 (8)
    //         004bb835     TEST       BL,AL
    //         004bb837     JZ         LAB_004bb8d6
    //                              Shape.cpp:2844 (10)
    //         004bb83d     XOR        EAX,EAX
    //         004bb83f     CMP        EDX,0x1
    //         004bb842     SETNZ      AL
    //         004bb845     MOV        EDX,EAX
    //                              Shape.cpp:2847 (5)
    //         004bb847     JMP        LAB_004bb8d6
    //                               LAB_004bb84c                                                 XREF[1]:     004bb826(j)  
    //                              Shape.cpp:2850 (8)
    //         004bb84c     TEST       EDX,EDX
    //         004bb84e     MOV        byte ptr [ESP + param_2],AL
    //         004bb852     JZ         LAB_004bb85b
    //                              Shape.cpp:2852 (2)
    //         004bb854     DEC        AL
    //                              Shape.cpp:2853 (11)
    //         004bb856     INC        this
    //         004bb857     MOV        byte ptr [ESP + param_2],AL
    //                               LAB_004bb85b                                                 XREF[1]:     004bb852(j)  
    //         004bb85b     MOV        ESI,dword ptr [ESP + param_2]
    //         004bb85f     MOV        EDX,ESI
    //                              Shape.cpp:2859 (17)
    //         004bb861     AND        ESI,0xff
    //         004bb867     AND        EDX,0xff
    //         004bb86d     ADD        ESI,this
    //         004bb86f     AND        EDX,0x1
    //                              Shape.cpp:2860 (4)
    //         004bb872     CMP        this,ESI
    //         004bb874     JNC        LAB_004bb880
    //                               LAB_004bb876                                                 XREF[1]:     004bb87e(j)  
    //                              Shape.cpp:2861 (10)
    //         004bb876     MOV        byte ptr [this->shape],0x0
    //         004bb879     ADD        this,0x2
    //         004bb87c     CMP        this,ESI
    //         004bb87e     JC         LAB_004bb876
    //                               LAB_004bb880                                                 XREF[1]:     004bb874(j)  
    //                              Shape.cpp:2862 (4)
    //         004bb880     TEST       EDX,EDX
    //         004bb882     JZ         LAB_004bb885
    //                              Shape.cpp:2863 (1)
    //         004bb884     DEC        this
    //                               LAB_004bb885                                                 XREF[1]:     004bb882(j)  
    //                              Shape.cpp:2864 (11)
    //         004bb885     MOV        EAX,dword ptr [ESP + param_4]
    //         004bb889     AND        EAX,0xff
    //         004bb88e     ADD        EBP,EAX
    //                              Shape.cpp:2867 (2)
    //         004bb890     JMP        LAB_004bb8d7
    //                               LAB_004bb892                                                 XREF[1]:     004bb81e(j)  
    //                              Shape.cpp:2869 (2)
    //         004bb892     SHR        AL,0x1
    //                              Shape.cpp:2870 (2)
    //         004bb894     JNZ        LAB_004bb89d
    //                              Shape.cpp:2871 (5)
    //         004bb896     MOV        byte ptr [ESP + param_3],0x1
    //                              Shape.cpp:2872 (2)
    //         004bb89b     JMP        LAB_004bb8d7
    //                               LAB_004bb89d                                                 XREF[1]:     004bb894(j)  
    //                              Shape.cpp:2875 (8)
    //         004bb89d     TEST       EDX,EDX
    //         004bb89f     MOV        byte ptr [ESP + param_2],AL
    //         004bb8a3     JZ         LAB_004bb8ac
    //                              Shape.cpp:2877 (2)
    //         004bb8a5     DEC        AL
    //                              Shape.cpp:2878 (11)
    //         004bb8a7     INC        this
    //         004bb8a8     MOV        byte ptr [ESP + param_2],AL
    //                               LAB_004bb8ac                                                 XREF[1]:     004bb8a3(j)  
    //         004bb8ac     MOV        ESI,dword ptr [ESP + param_2]
    //         004bb8b0     MOV        EDX,ESI
    //                              Shape.cpp:2884 (17)
    //         004bb8b2     AND        ESI,0xff
    //         004bb8b8     AND        EDX,0xff
    //         004bb8be     ADD        ESI,this
    //         004bb8c0     AND        EDX,0x1
    //                              Shape.cpp:2885 (4)
    //         004bb8c3     CMP        this,ESI
    //         004bb8c5     JNC        LAB_004bb8d1
    //                               LAB_004bb8c7                                                 XREF[1]:     004bb8cf(j)  
    //                              Shape.cpp:2886 (10)
    //         004bb8c7     MOV        byte ptr [this->shape],0x0
    //         004bb8ca     ADD        this,0x2
    //         004bb8cd     CMP        this,ESI
    //         004bb8cf     JC         LAB_004bb8c7
    //                               LAB_004bb8d1                                                 XREF[1]:     004bb8c5(j)  
    //                              Shape.cpp:2887 (4)
    //         004bb8d1     TEST       EDX,EDX
    //         004bb8d3     JZ         LAB_004bb8d6
    //                              Shape.cpp:2888 (1)
    //         004bb8d5     DEC        this
    //                               LAB_004bb8d6                                                 XREF[3]:     004bb837(j), 004bb847(j), 
    //                                                                                                         004bb8d3(j)  
    //                              Shape.cpp:2889 (1)
    //         004bb8d6     INC        EBP
    //                               LAB_004bb8d7                                                 XREF[2]:     004bb890(j), 004bb89b(j)  
    //                              Shape.cpp:2833 (12)
    //         004bb8d7     MOV        AL,byte ptr [ESP + param_3]
    //         004bb8db     TEST       AL,AL
    //         004bb8dd     JZ         LAB_004bb812
    //                              Shape.cpp:2893 (21)
    //         004bb8e3     MOV        this,dword ptr [ESP + width]
    //         004bb8e7     MOV        EDX,dword ptr [ESP + local_4]
    //         004bb8eb     ADD        this,EDX
    //         004bb8ed     DEC        EDI
    //         004bb8ee     MOV        dword ptr [ESP + width],this
    //         004bb8f2     JNZ        LAB_004bb7fb
    //                               LAB_004bb8f8                                                 XREF[1]:     004bb7f1(j)  
    //                              Shape.cpp:2898 (12)
    //         004bb8f8     POP        EDI
    //         004bb8f9     POP        ESI
    //         004bb8fa     POP        EBP
    //         004bb8fb     MOV        AL,0x1
    //         004bb8fd     POP        EBX
    //         004bb8fe     ADD        ESP,0x8
    //         004bb901     RET        0x14
}

// Offset: 0x004BB910
uchar shape_dithered_clipped(TShape* this_, TDrawArea* param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * private: unsigned char __thiscall TShape::shape_dithered_clipped(class TDrawArea *,long,long,long,... *
    //                              *********************************************************************************************************
    //                              uchar __thiscall shape_dithered_clipped(TShape * this, TDrawArea * p
    //              uchar             AL:1           <RETURN>
    //              TShape *          ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[5]:     004bb917(R), 004bb973(W), 004bb981(W), 004bb9df(R), 
    //                                                                                     004bb9ee(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004bb9e3(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[13]:    004bb985(R), 004bb9ae(W), 004bb9b4(R), 004bba1b(W), 
    //                                                                                     004bba7f(R), 004bbb38(W), 004bbb48(R), 004bbc21(W), 
    //                                                                                     004bbc63(R), 004bbd18(W), 004bbd28(R), 004bbdea(W), 
    //                                                                                     004bbdf0(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[10]:    004bb956(R), 004bb9f2(R), 004bba2c(R), 004bba4d(R), 
    //                                                                                     004bba93(R), 004bbaa9(R), 004bbaf1(R), 004bbb58(R), 
    //                                                                                     004bbb70(R), 004bbbb2(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[17]:    004bb939(R), 004bb94a(R), 004bba02(W), 004bba43(W), 
    //                                                                                     004bba51(W), 004bbab1(W), 004bbaf5(W), 004bbb3e(W), 
    //                                                                                     004bbb78(W), 004bbbb6(W), 004bbbf1(R), 004bbc03(W), 
    //                                                                                     004bbc59(W), 004bbc8d(W), 004bbd1e(W), 004bbd52(W), 
    //                                                                                     004bbdca(R)  
    //              long              Stack[0x18]:4  param_6                   XREF[5]:     004bb9db(R), 004bbc77(R), 004bbd09(R), 004bbd3c(R), 
    //                                                                                     004bbdc5(R)  
    //              long              Stack[0x1c]:4  param_7                   XREF[2]:     004bb9d1(R), 004bbe16(R)  
    //              long              Stack[0x20]:4  param_8                   XREF[27]:    004bb95a(R), 004bba58(W), 004bba5c(R), 004bbab9(W), 
    //                                                                                     004bbac2(W), 004bbacb(R), 004bbafe(W), 004bbb07(W), 
    //                                                                                     004bbb10(R), 004bbb80(W), 004bbb89(W), 004bbb92(R), 
    //                                                                                     004bbbbf(W), 004bbbc8(W), 004bbbd1(R), 004bbc9a(W), 
    //                                                                                     004bbca3(W), 004bbcac(R), 004bbcd8(W), 004bbce1(W)  
    //              long              Stack[0x24]:4  param_9                   XREF[16]:    004bb964(R), 004bb9f8(W), 004bba21(R), 004bba33(W), 
    //                                                                                     004bba83(R), 004bba8f(W), 004bba97(R), 004bbb4c(R), 
    //                                                                                     004bbb5e(W), 004bbc2a(R), 004bbc3b(W), 004bbc4a(R), 
    //                                                                                     004bbc67(R), 004bbc7f(W), 004bbd2c(R), 004bbd44(W)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004bb92d(W), 004bbe0e(R)  
    //              long              Stack[-0x8]:4  width                     XREF[3]:     004bb96d(W), 004bbe0a(R), 004bbe1f(W)  
    //              uchar *           Stack[-0xc]:4  save_buffer               XREF[4]:     004bb98d(W), 004bb998(W), 004bbe12(R), 004bbe23(W)  
    //              long              Stack[-0x10]:4 y                         XREF[6]:     004bbc73(W), 004bbc87(R), 004bbcca(R), 004bbd0d(R), 
    //                                                                                     004bbd38(W), 004bbd4c(R)  
    //                               ?shape_dithered_clipped@TShape@@AAEEPAVTDrawArea@@JJJJJJJJ@Z XREF[1]:     shape_dither:004bb749(c)  
    //                               TShape::shape_dithered_clipped
    //                              Shape.cpp:2902 (7)
    //         004bb910     SUB        ESP,0x10
    //         004bb913     PUSH       EBX
    //         004bb914     PUSH       EBP
    //         004bb915     PUSH       ESI
    //         004bb916     PUSH       EDI
    //                              Shape.cpp:2903 (19)
    //         004bb917     MOV        EDI,dword ptr [ESP + param_1]
    //         004bb91b     MOV        EBX,this
    //         004bb91d     MOV        this,EDI
    //         004bb91f     MOV        ESI,dword ptr [EDI + 0x24]
    //         004bb922     CALL       TDrawArea::AlignedWidth                          long AlignedWidth(TDrawArea * this)
    //         004bb927     IMUL       EAX,ESI
    //                              Shape.cpp:2907 (10)
    //         004bb92a     MOV        EBP,dword ptr [EBX + 0xc]
    //         004bb92d     MOV        dword ptr [ESP + local_4],EAX
    //         004bb931     ADD        EBP,0x18
    //                              Shape.cpp:2917 (5)
    //         004bb934     CMP        ESI,0x1
    //         004bb937     JGE        LAB_004bb94a
    //                              Shape.cpp:2918 (15)
    //         004bb939     MOV        ESI,dword ptr [ESP + param_5]
    //         004bb93d     MOV        EBX,dword ptr [EDI + 0x1c]
    //         004bb940     MOV        this,ESI
    //         004bb942     SUB        this,EBX
    //         004bb944     INC        this
    //         004bb945     IMUL       this,EAX
    //                              Shape.cpp:2919 (2)
    //         004bb948     JMP        LAB_004bb953
    //                               LAB_004bb94a                                                 XREF[1]:     004bb937(j)  
    //                              Shape.cpp:2920 (16)
    //         004bb94a     MOV        ESI,dword ptr [ESP + param_5]
    //         004bb94e     MOV        this,EAX
    //         004bb950     IMUL       this,ESI
    //                               LAB_004bb953                                                 XREF[1]:     004bb948(j)  
    //         004bb953     MOV        EBX,dword ptr [EDI + 0x8]
    //         004bb956     MOV        EAX,dword ptr [ESP + param_4]
    //                              Shape.cpp:2923 (10)
    //         004bb95a     MOV        DL,byte ptr [ESP + param_8]
    //         004bb95e     ADD        this,EBX
    //         004bb960     ADD        this,EAX
    //         004bb962     ADD        DL,AL
    //                              Shape.cpp:2924 (21)
    //         004bb964     MOV        EAX,dword ptr [ESP + param_9]
    //         004bb968     AND        DL,0x1
    //         004bb96b     ADD        EAX,ESI
    //         004bb96d     MOV        dword ptr [ESP + width],this
    //         004bb971     TEST       AL,0x1
    //         004bb973     MOV        byte ptr [ESP + param_1],DL
    //         004bb977     JZ         LAB_004bb985
    //                              Shape.cpp:2925 (12)
    //         004bb979     XOR        EAX,EAX
    //         004bb97b     CMP        DL,0x1
    //         004bb97e     SETNZ      AL
    //         004bb981     MOV        byte ptr [ESP + param_1],AL
    //                               LAB_004bb985                                                 XREF[1]:     004bb977(j)  
    //                              Shape.cpp:2928 (23)
    //         004bb985     MOV        EAX,dword ptr [ESP + param_3]
    //         004bb989     MOV        EDI,EAX
    //         004bb98b     CMP        EAX,ESI
    //         004bb98d     MOV        dword ptr [ESP + save_buffer],EDI
    //         004bb991     JGE        LAB_004bb9d1
    //         004bb993     SUB        ESI,EAX
    //         004bb995     LEA        EDI,[EAX + ESI*0x1]
    //         004bb998     MOV        dword ptr [ESP + save_buffer],EDI
    //                               LAB_004bb99c                                                 XREF[1]:     004bb9cf(j)  
    //                              Shape.cpp:2930 (2)
    //         004bb99c     XOR        DL,DL
    //                               LAB_004bb99e                                                 XREF[1]:     004bb9cc(j)  
    //                              Shape.cpp:2933 (3)
    //         004bb99e     MOV        AL,byte ptr [EBP]
    //                              Shape.cpp:2934 (1)
    //         004bb9a1     INC        EBP
    //                              Shape.cpp:2935 (10)
    //         004bb9a2     MOV        BL,AL
    //         004bb9a4     AND        BL,0x1
    //         004bb9a7     CMP        BL,0x1
    //         004bb9aa     JNZ        LAB_004bb9c1
    //                              Shape.cpp:2937 (6)
    //         004bb9ac     SHR        AL,0x1
    //         004bb9ae     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:2940 (2)
    //         004bb9b2     JZ         LAB_004bb9c9
    //                              Shape.cpp:2941 (11)
    //         004bb9b4     MOV        EAX,dword ptr [ESP + param_3]
    //         004bb9b8     AND        EAX,0xff
    //         004bb9bd     ADD        EBP,EAX
    //                              Shape.cpp:2943 (2)
    //         004bb9bf     JMP        LAB_004bb9ca
    //                               LAB_004bb9c1                                                 XREF[1]:     004bb9aa(j)  
    //                              Shape.cpp:2946 (4)
    //         004bb9c1     TEST       AL,0xfe
    //         004bb9c3     JNZ        LAB_004bb9c9
    //                              Shape.cpp:2947 (2)
    //         004bb9c5     MOV        DL,0x1
    //                              Shape.cpp:2948 (2)
    //         004bb9c7     JMP        LAB_004bb9ca
    //                               LAB_004bb9c9                                                 XREF[2]:     004bb9b2(j), 004bb9c3(j)  
    //                              Shape.cpp:2949 (1)
    //         004bb9c9     INC        EBP
    //                               LAB_004bb9ca                                                 XREF[2]:     004bb9bf(j), 004bb9c7(j)  
    //                              Shape.cpp:2931 (4)
    //         004bb9ca     TEST       DL,DL
    //         004bb9cc     JZ         LAB_004bb99e
    //                              Shape.cpp:2928 (3)
    //         004bb9ce     DEC        ESI
    //         004bb9cf     JNZ        LAB_004bb99c
    //                               LAB_004bb9d1                                                 XREF[1]:     004bb991(j)  
    //                              Shape.cpp:2955 (14)
    //         004bb9d1     CMP        EDI,dword ptr [ESP + param_7]
    //         004bb9d5     JG         LAB_004bbe2d
    //         004bb9db     MOV        EDI,dword ptr [ESP + param_6]
    //                               LAB_004bb9df                                                 XREF[1]:     004bbe27(j)  
    //                              Shape.cpp:2957 (8)
    //         004bb9df     MOV        AL,byte ptr [ESP + param_1]
    //         004bb9e3     MOV        ESI,dword ptr [ESP + param_2]
    //                              Shape.cpp:2958 (11)
    //         004bb9e7     XOR        EDX,EDX
    //         004bb9e9     CMP        AL,0x1
    //         004bb9eb     SETNZ      DL
    //         004bb9ee     MOV        byte ptr [ESP + param_1],DL
    //                              Shape.cpp:2962 (16)
    //         004bb9f2     MOV        EDX,dword ptr [ESP + param_4]
    //         004bb9f6     CMP        ESI,EDX
    //         004bb9f8     MOV        dword ptr [ESP + param_9],ESI
    //         004bb9fc     JGE        LAB_004bbbff
    //                              Shape.cpp:2964 (5)
    //         004bba02     MOV        byte ptr [ESP + param_5],0x0
    //                               LAB_004bba07                                                 XREF[1]:     004bbbf7(j)  
    //                              Shape.cpp:2967 (3)
    //         004bba07     MOV        DL,byte ptr [EBP]
    //                              Shape.cpp:2968 (1)
    //         004bba0a     INC        EBP
    //                              Shape.cpp:2969 (14)
    //         004bba0b     MOV        BL,DL
    //         004bba0d     AND        BL,0x1
    //         004bba10     CMP        BL,0x1
    //         004bba13     JNZ        LAB_004bbb36
    //                              Shape.cpp:2971 (6)
    //         004bba19     SHR        DL,0x1
    //         004bba1b     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:2972 (2)
    //         004bba1f     JNZ        LAB_004bba7f
    //                              Shape.cpp:2974 (11)
    //         004bba21     MOV        ESI,dword ptr [ESP + param_9]
    //         004bba25     XOR        EDX,EDX
    //         004bba27     MOV        DL,byte ptr [EBP]
    //         004bba2a     ADD        ESI,EDX
    //                              Shape.cpp:2976 (17)
    //         004bba2c     MOV        EDX,dword ptr [ESP + param_4]
    //         004bba30     INC        EBP
    //         004bba31     CMP        ESI,EDX
    //         004bba33     MOV        dword ptr [ESP + param_9],ESI
    //         004bba37     JL         LAB_004bbbf1
    //                              Shape.cpp:2978 (6)
    //         004bba3d     MOV        EDX,ESI
    //         004bba3f     CMP        EDX,EDI
    //         004bba41     JLE        LAB_004bba4d
    //                              Shape.cpp:2979 (5)
    //         004bba43     MOV        byte ptr [ESP + param_5],0x2
    //                              Shape.cpp:2980 (5)
    //         004bba48     JMP        LAB_004bbbf1
    //                               LAB_004bba4d                                                 XREF[1]:     004bba41(j)  
    //                              Shape.cpp:2983 (15)
    //         004bba4d     MOV        BL,byte ptr [ESP + param_4]
    //         004bba51     MOV        byte ptr [ESP + param_5],0x1
    //         004bba56     SUB        DL,BL
    //         004bba58     MOV        byte ptr [ESP + param_8],DL
    //                              Shape.cpp:2984 (12)
    //         004bba5c     MOV        ESI,dword ptr [ESP + param_8]
    //         004bba60     AND        ESI,0xff
    //         004bba66     ADD        this,ESI
    //                              Shape.cpp:2985 (9)
    //         004bba68     TEST       DL,0x1
    //         004bba6b     JZ         LAB_004bbbf1
    //                              Shape.cpp:2986 (9)
    //         004bba71     XOR        EDX,EDX
    //         004bba73     CMP        AL,0x1
    //         004bba75     SETNZ      DL
    //         004bba78     MOV        AL,DL
    //                              Shape.cpp:2990 (5)
    //         004bba7a     JMP        LAB_004bbbf1
    //                               LAB_004bba7f                                                 XREF[1]:     004bba1f(j)  
    //                              Shape.cpp:2992 (20)
    //         004bba7f     MOV        ESI,dword ptr [ESP + param_3]
    //         004bba83     MOV        EDX,dword ptr [ESP + param_9]
    //         004bba87     AND        ESI,0xff
    //         004bba8d     ADD        EDX,ESI
    //         004bba8f     MOV        dword ptr [ESP + param_9],EDX
    //                              Shape.cpp:2993 (16)
    //         004bba93     MOV        EDX,dword ptr [ESP + param_4]
    //         004bba97     MOV        EBX,dword ptr [ESP + param_9]
    //         004bba9b     CMP        EBX,EDX
    //         004bba9d     JLE        LAB_004bbb2f
    //                              Shape.cpp:2995 (6)
    //         004bbaa3     MOV        EDX,EBX
    //         004bbaa5     CMP        EDX,EDI
    //         004bbaa7     JLE        LAB_004bbaf1
    //                              Shape.cpp:2998 (14)
    //         004bbaa9     MOV        EBX,dword ptr [ESP + param_4]
    //         004bbaad     MOV        EDX,EDI
    //         004bbaaf     SUB        EDX,EBX
    //         004bbab1     MOV        byte ptr [ESP + param_5],0x2
    //         004bbab6     INC        EDX
    //                              Shape.cpp:3000 (8)
    //         004bbab7     TEST       AL,AL
    //         004bbab9     MOV        byte ptr [ESP + param_8],DL
    //         004bbabd     JZ         LAB_004bbac6
    //                              Shape.cpp:3002 (2)
    //         004bbabf     DEC        DL
    //                              Shape.cpp:3003 (5)
    //         004bbac1     INC        this
    //         004bbac2     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbac6                                                 XREF[1]:     004bbabd(j)  
    //                              Shape.cpp:3005 (5)
    //         004bbac6     AND        DL,0x1
    //         004bbac9     MOV        AL,DL
    //                              Shape.cpp:3009 (12)
    //         004bbacb     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbacf     AND        EDX,0xff
    //         004bbad5     ADD        EDX,this
    //                              Shape.cpp:3010 (4)
    //         004bbad7     CMP        this,EDX
    //         004bbad9     JNC        LAB_004bbae5
    //                               LAB_004bbadb                                                 XREF[1]:     004bbae3(j)  
    //                              Shape.cpp:3011 (10)
    //         004bbadb     MOV        byte ptr [this->shape],0x0
    //         004bbade     ADD        this,0x2
    //         004bbae1     CMP        this,EDX
    //         004bbae3     JC         LAB_004bbadb
    //                               LAB_004bbae5                                                 XREF[1]:     004bbad9(j)  
    //                              Shape.cpp:3012 (4)
    //         004bbae5     TEST       AL,AL
    //         004bbae7     JZ         LAB_004bbb2f
    //                              Shape.cpp:3033 (1)
    //         004bbae9     DEC        this
    //                              Shape.cpp:3036 (2)
    //         004bbaea     ADD        EBP,ESI
    //                              Shape.cpp:3039 (5)
    //         004bbaec     JMP        LAB_004bbbf1
    //                               LAB_004bbaf1                                                 XREF[1]:     004bbaa7(j)  
    //                              Shape.cpp:3018 (11)
    //         004bbaf1     MOV        EBX,dword ptr [ESP + param_4]
    //         004bbaf5     MOV        byte ptr [ESP + param_5],0x1
    //         004bbafa     SUB        EDX,EBX
    //                              Shape.cpp:3020 (8)
    //         004bbafc     TEST       AL,AL
    //         004bbafe     MOV        byte ptr [ESP + param_8],DL
    //         004bbb02     JZ         LAB_004bbb0b
    //                              Shape.cpp:3022 (2)
    //         004bbb04     DEC        DL
    //                              Shape.cpp:3023 (5)
    //         004bbb06     INC        this
    //         004bbb07     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbb0b                                                 XREF[1]:     004bbb02(j)  
    //                              Shape.cpp:3025 (5)
    //         004bbb0b     AND        DL,0x1
    //         004bbb0e     MOV        AL,DL
    //                              Shape.cpp:3029 (12)
    //         004bbb10     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbb14     AND        EDX,0xff
    //         004bbb1a     ADD        EDX,this
    //                              Shape.cpp:3030 (4)
    //         004bbb1c     CMP        this,EDX
    //         004bbb1e     JNC        LAB_004bbb2a
    //                               LAB_004bbb20                                                 XREF[1]:     004bbb28(j)  
    //                              Shape.cpp:3031 (10)
    //         004bbb20     MOV        byte ptr [this->shape],0x0
    //         004bbb23     ADD        this,0x2
    //         004bbb26     CMP        this,EDX
    //         004bbb28     JC         LAB_004bbb20
    //                               LAB_004bbb2a                                                 XREF[1]:     004bbb1e(j)  
    //                              Shape.cpp:3032 (4)
    //         004bbb2a     TEST       AL,AL
    //         004bbb2c     JZ         LAB_004bbb2f
    //                              Shape.cpp:3033 (1)
    //         004bbb2e     DEC        this
    //                               LAB_004bbb2f                                                 XREF[3]:     004bba9d(j), 004bbae7(j), 
    //                                                                                                         004bbb2c(j)  
    //                              Shape.cpp:3036 (2)
    //         004bbb2f     ADD        EBP,ESI
    //                              Shape.cpp:3039 (5)
    //         004bbb31     JMP        LAB_004bbbf1
    //                               LAB_004bbb36                                                 XREF[1]:     004bba13(j)  
    //                              Shape.cpp:3041 (6)
    //         004bbb36     SHR        DL,0x1
    //         004bbb38     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:3042 (2)
    //         004bbb3c     JNZ        LAB_004bbb48
    //                              Shape.cpp:3043 (5)
    //         004bbb3e     MOV        byte ptr [ESP + param_5],0x3
    //                              Shape.cpp:3044 (5)
    //         004bbb43     JMP        LAB_004bbbf1
    //                               LAB_004bbb48                                                 XREF[1]:     004bbb3c(j)  
    //                              Shape.cpp:3046 (16)
    //         004bbb48     MOV        EDX,dword ptr [ESP + param_3]
    //         004bbb4c     MOV        EBX,dword ptr [ESP + param_9]
    //         004bbb50     AND        EDX,0xff
    //         004bbb56     ADD        EBX,EDX
    //                              Shape.cpp:3047 (18)
    //         004bbb58     MOV        EDX,dword ptr [ESP + param_4]
    //         004bbb5c     MOV        ESI,EBX
    //         004bbb5e     MOV        dword ptr [ESP + param_9],EBX
    //         004bbb62     CMP        ESI,EDX
    //         004bbb64     JLE        LAB_004bbbf0
    //                              Shape.cpp:3049 (6)
    //         004bbb6a     MOV        EDX,EBX
    //         004bbb6c     CMP        EDX,EDI
    //         004bbb6e     JLE        LAB_004bbbb2
    //                              Shape.cpp:3052 (14)
    //         004bbb70     MOV        ESI,dword ptr [ESP + param_4]
    //         004bbb74     MOV        EDX,EDI
    //         004bbb76     SUB        EDX,ESI
    //         004bbb78     MOV        byte ptr [ESP + param_5],0x2
    //         004bbb7d     INC        EDX
    //                              Shape.cpp:3054 (8)
    //         004bbb7e     TEST       AL,AL
    //         004bbb80     MOV        byte ptr [ESP + param_8],DL
    //         004bbb84     JZ         LAB_004bbb8d
    //                              Shape.cpp:3056 (2)
    //         004bbb86     DEC        DL
    //                              Shape.cpp:3057 (5)
    //         004bbb88     INC        this
    //         004bbb89     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbb8d                                                 XREF[1]:     004bbb84(j)  
    //                              Shape.cpp:3059 (5)
    //         004bbb8d     AND        DL,0x1
    //         004bbb90     MOV        AL,DL
    //                              Shape.cpp:3063 (12)
    //         004bbb92     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbb96     AND        EDX,0xff
    //         004bbb9c     ADD        EDX,this
    //                              Shape.cpp:3064 (4)
    //         004bbb9e     CMP        this,EDX
    //         004bbba0     JNC        LAB_004bbbac
    //                               LAB_004bbba2                                                 XREF[1]:     004bbbaa(j)  
    //                              Shape.cpp:3065 (10)
    //         004bbba2     MOV        byte ptr [this->shape],0x0
    //         004bbba5     ADD        this,0x2
    //         004bbba8     CMP        this,EDX
    //         004bbbaa     JC         LAB_004bbba2
    //                               LAB_004bbbac                                                 XREF[1]:     004bbba0(j)  
    //                              Shape.cpp:3066 (4)
    //         004bbbac     TEST       AL,AL
    //         004bbbae     JZ         LAB_004bbbf0
    //                              Shape.cpp:3069 (2)
    //         004bbbb0     JMP        LAB_004bbbef
    //                               LAB_004bbbb2                                                 XREF[1]:     004bbb6e(j)  
    //                              Shape.cpp:3072 (11)
    //         004bbbb2     MOV        EBX,dword ptr [ESP + param_4]
    //         004bbbb6     MOV        byte ptr [ESP + param_5],0x1
    //         004bbbbb     SUB        EDX,EBX
    //                              Shape.cpp:3074 (8)
    //         004bbbbd     TEST       AL,AL
    //         004bbbbf     MOV        byte ptr [ESP + param_8],DL
    //         004bbbc3     JZ         LAB_004bbbcc
    //                              Shape.cpp:3076 (2)
    //         004bbbc5     DEC        DL
    //                              Shape.cpp:3077 (5)
    //         004bbbc7     INC        this
    //         004bbbc8     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbbcc                                                 XREF[1]:     004bbbc3(j)  
    //                              Shape.cpp:3079 (5)
    //         004bbbcc     AND        DL,0x1
    //         004bbbcf     MOV        AL,DL
    //                              Shape.cpp:3083 (12)
    //         004bbbd1     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbbd5     AND        EDX,0xff
    //         004bbbdb     ADD        EDX,this
    //                              Shape.cpp:3084 (4)
    //         004bbbdd     CMP        this,EDX
    //         004bbbdf     JNC        LAB_004bbbeb
    //                               LAB_004bbbe1                                                 XREF[1]:     004bbbe9(j)  
    //                              Shape.cpp:3085 (10)
    //         004bbbe1     MOV        byte ptr [this->shape],0x0
    //         004bbbe4     ADD        this,0x2
    //         004bbbe7     CMP        this,EDX
    //         004bbbe9     JC         LAB_004bbbe1
    //                               LAB_004bbbeb                                                 XREF[1]:     004bbbdf(j)  
    //                              Shape.cpp:3086 (4)
    //         004bbbeb     TEST       AL,AL
    //         004bbbed     JZ         LAB_004bbbf0
    //                               LAB_004bbbef                                                 XREF[1]:     004bbbb0(j)  
    //                              Shape.cpp:3087 (1)
    //         004bbbef     DEC        this
    //                               LAB_004bbbf0                                                 XREF[3]:     004bbb64(j), 004bbbae(j), 
    //                                                                                                         004bbbed(j)  
    //                              Shape.cpp:3090 (1)
    //         004bbbf0     INC        EBP
    //                               LAB_004bbbf1                                                 XREF[7]:     004bba37(j), 004bba48(j), 
    //                                                                                                         004bba6b(j), 004bba7a(j), 
    //                                                                                                         004bbaec(j), 004bbb31(j), 
    //                                                                                                         004bbb43(j)  
    //                              Shape.cpp:2965 (12)
    //         004bbbf1     MOV        DL,byte ptr [ESP + param_5]
    //         004bbbf5     TEST       DL,DL
    //         004bbbf7     JZ         LAB_004bba07
    //                              Shape.cpp:3095 (2)
    //         004bbbfd     JMP        LAB_004bbc01
    //                               LAB_004bbbff                                                 XREF[1]:     004bb9fc(j)  
    //                              Shape.cpp:3096 (2)
    //         004bbbff     MOV        DL,0x1
    //                               LAB_004bbc01                                                 XREF[1]:     004bbbfd(j)  
    //                              Shape.cpp:3099 (6)
    //         004bbc01     DEC        DL
    //         004bbc03     MOV        byte ptr [ESP + param_5],DL
    //                              Shape.cpp:3100 (6)
    //         004bbc07     JNZ        LAB_004bbdd6
    //                               LAB_004bbc0d                                                 XREF[1]:     004bbdd0(j)  
    //                              Shape.cpp:3102 (3)
    //         004bbc0d     MOV        DL,byte ptr [EBP]
    //                              Shape.cpp:3103 (1)
    //         004bbc10     INC        EBP
    //                              Shape.cpp:3104 (14)
    //         004bbc11     MOV        BL,DL
    //         004bbc13     AND        BL,0x1
    //         004bbc16     CMP        BL,0x1
    //         004bbc19     JNZ        LAB_004bbd16
    //                              Shape.cpp:3106 (6)
    //         004bbc1f     SHR        DL,0x1
    //         004bbc21     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:3107 (2)
    //         004bbc25     JNZ        LAB_004bbc63
    //                              Shape.cpp:3109 (17)
    //         004bbc27     MOV        DL,byte ptr [EBP]
    //         004bbc2a     MOV        EBX,dword ptr [ESP + param_9]
    //         004bbc2e     MOV        ESI,EDX
    //         004bbc30     AND        ESI,0xff
    //         004bbc36     ADD        EBX,ESI
    //                              Shape.cpp:3110 (9)
    //         004bbc38     TEST       DL,0x1
    //         004bbc3b     MOV        dword ptr [ESP + param_9],EBX
    //         004bbc3f     JZ         LAB_004bbc4a
    //                              Shape.cpp:3111 (9)
    //         004bbc41     XOR        EDX,EDX
    //         004bbc43     CMP        AL,0x1
    //         004bbc45     SETNZ      DL
    //         004bbc48     MOV        AL,DL
    //                               LAB_004bbc4a                                                 XREF[1]:     004bbc3f(j)  
    //                              Shape.cpp:3114 (15)
    //         004bbc4a     MOV        EDX,dword ptr [ESP + param_9]
    //         004bbc4e     ADD        this,ESI
    //         004bbc50     INC        EBP
    //         004bbc51     CMP        EDX,EDI
    //         004bbc53     JLE        LAB_004bbdca
    //                              Shape.cpp:3115 (5)
    //         004bbc59     MOV        byte ptr [ESP + param_5],0x1
    //                              Shape.cpp:3117 (5)
    //         004bbc5e     JMP        LAB_004bbdca
    //                               LAB_004bbc63                                                 XREF[1]:     004bbc25(j)  
    //                              Shape.cpp:3119 (20)
    //         004bbc63     MOV        ESI,dword ptr [ESP + param_3]
    //         004bbc67     MOV        EBX,dword ptr [ESP + param_9]
    //         004bbc6b     AND        ESI,0xff
    //         004bbc71     ADD        EBX,ESI
    //         004bbc73     MOV        dword ptr [ESP + y],ESI
    //                              Shape.cpp:3120 (14)
    //         004bbc77     MOV        ESI,dword ptr [ESP + param_6]
    //         004bbc7b     MOV        EDI,EBX
    //         004bbc7d     CMP        EDI,ESI
    //         004bbc7f     MOV        dword ptr [ESP + param_9],EBX
    //         004bbc83     JLE        LAB_004bbcd6
    //                              Shape.cpp:3123 (15)
    //         004bbc85     MOV        EDI,ESI
    //         004bbc87     MOV        ESI,dword ptr [ESP + y]
    //         004bbc8b     MOV        EDX,EDI
    //         004bbc8d     MOV        byte ptr [ESP + param_5],0x1
    //         004bbc92     SUB        EDX,EBX
    //                              Shape.cpp:3125 (12)
    //         004bbc94     TEST       AL,AL
    //         004bbc96     LEA        EDX,[EDX + ESI*0x1 + 0x1]
    //         004bbc9a     MOV        byte ptr [ESP + param_8],DL
    //         004bbc9e     JZ         LAB_004bbca7
    //                              Shape.cpp:3127 (2)
    //         004bbca0     DEC        DL
    //                              Shape.cpp:3128 (5)
    //         004bbca2     INC        this
    //         004bbca3     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbca7                                                 XREF[1]:     004bbc9e(j)  
    //                              Shape.cpp:3130 (5)
    //         004bbca7     AND        DL,0x1
    //         004bbcaa     MOV        AL,DL
    //                              Shape.cpp:3134 (12)
    //         004bbcac     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbcb0     AND        EDX,0xff
    //         004bbcb6     ADD        EDX,this
    //                              Shape.cpp:3135 (4)
    //         004bbcb8     CMP        this,EDX
    //         004bbcba     JNC        LAB_004bbcc6
    //                               LAB_004bbcbc                                                 XREF[1]:     004bbcc4(j)  
    //                              Shape.cpp:3136 (10)
    //         004bbcbc     MOV        byte ptr [this->shape],0x0
    //         004bbcbf     ADD        this,0x2
    //         004bbcc2     CMP        this,EDX
    //         004bbcc4     JC         LAB_004bbcbc
    //                               LAB_004bbcc6                                                 XREF[1]:     004bbcba(j)  
    //                              Shape.cpp:3137 (4)
    //         004bbcc6     TEST       AL,AL
    //         004bbcc8     JZ         LAB_004bbd0d
    //                              Shape.cpp:3159 (7)
    //         004bbcca     MOV        EDX,dword ptr [ESP + y]
    //         004bbcce     DEC        this
    //         004bbccf     ADD        EBP,EDX
    //                              Shape.cpp:3162 (5)
    //         004bbcd1     JMP        LAB_004bbdca
    //                               LAB_004bbcd6                                                 XREF[1]:     004bbc83(j)  
    //                              Shape.cpp:3143 (8)
    //         004bbcd6     TEST       AL,AL
    //         004bbcd8     MOV        byte ptr [ESP + param_8],DL
    //         004bbcdc     JZ         LAB_004bbce5
    //                              Shape.cpp:3145 (2)
    //         004bbcde     DEC        DL
    //                              Shape.cpp:3146 (5)
    //         004bbce0     INC        this
    //         004bbce1     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbce5                                                 XREF[1]:     004bbcdc(j)  
    //                              Shape.cpp:3148 (5)
    //         004bbce5     AND        DL,0x1
    //         004bbce8     MOV        AL,DL
    //                              Shape.cpp:3152 (12)
    //         004bbcea     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbcee     AND        EDX,0xff
    //         004bbcf4     ADD        EDX,this
    //                              Shape.cpp:3153 (4)
    //         004bbcf6     CMP        this,EDX
    //         004bbcf8     JNC        LAB_004bbd04
    //                               LAB_004bbcfa                                                 XREF[1]:     004bbd02(j)  
    //                              Shape.cpp:3154 (10)
    //         004bbcfa     MOV        byte ptr [this->shape],0x0
    //         004bbcfd     ADD        this,0x2
    //         004bbd00     CMP        this,EDX
    //         004bbd02     JC         LAB_004bbcfa
    //                               LAB_004bbd04                                                 XREF[1]:     004bbcf8(j)  
    //                              Shape.cpp:3155 (4)
    //         004bbd04     TEST       AL,AL
    //         004bbd06     JZ         LAB_004bbd09
    //                              Shape.cpp:3156 (5)
    //         004bbd08     DEC        this
    //                               LAB_004bbd09                                                 XREF[1]:     004bbd06(j)  
    //         004bbd09     MOV        EDI,dword ptr [ESP + param_6]
    //                               LAB_004bbd0d                                                 XREF[1]:     004bbcc8(j)  
    //                              Shape.cpp:3159 (4)
    //         004bbd0d     ADD        EBP,dword ptr [ESP + y]
    //                              Shape.cpp:3162 (5)
    //         004bbd11     JMP        LAB_004bbdca
    //                               LAB_004bbd16                                                 XREF[1]:     004bbc19(j)  
    //                              Shape.cpp:3164 (6)
    //         004bbd16     SHR        DL,0x1
    //         004bbd18     MOV        byte ptr [ESP + param_3],DL
    //                              Shape.cpp:3165 (2)
    //         004bbd1c     JNZ        LAB_004bbd28
    //                              Shape.cpp:3166 (5)
    //         004bbd1e     MOV        byte ptr [ESP + param_5],0x3
    //                              Shape.cpp:3167 (5)
    //         004bbd23     JMP        LAB_004bbdca
    //                               LAB_004bbd28                                                 XREF[1]:     004bbd1c(j)  
    //                              Shape.cpp:3169 (20)
    //         004bbd28     MOV        ESI,dword ptr [ESP + param_3]
    //         004bbd2c     MOV        EBX,dword ptr [ESP + param_9]
    //         004bbd30     AND        ESI,0xff
    //         004bbd36     ADD        EBX,ESI
    //         004bbd38     MOV        dword ptr [ESP + y],ESI
    //                              Shape.cpp:3170 (14)
    //         004bbd3c     MOV        ESI,dword ptr [ESP + param_6]
    //         004bbd40     MOV        EDI,EBX
    //         004bbd42     CMP        EDI,ESI
    //         004bbd44     MOV        dword ptr [ESP + param_9],EBX
    //         004bbd48     JLE        LAB_004bbd92
    //                              Shape.cpp:3173 (15)
    //         004bbd4a     MOV        EDI,ESI
    //         004bbd4c     MOV        ESI,dword ptr [ESP + y]
    //         004bbd50     MOV        EDX,EDI
    //         004bbd52     MOV        byte ptr [ESP + param_5],0x1
    //         004bbd57     SUB        EDX,EBX
    //                              Shape.cpp:3175 (12)
    //         004bbd59     TEST       AL,AL
    //         004bbd5b     LEA        EDX,[EDX + ESI*0x1 + 0x1]
    //         004bbd5f     MOV        byte ptr [ESP + param_8],DL
    //         004bbd63     JZ         LAB_004bbd6c
    //                              Shape.cpp:3177 (2)
    //         004bbd65     DEC        DL
    //                              Shape.cpp:3178 (5)
    //         004bbd67     INC        this
    //         004bbd68     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbd6c                                                 XREF[1]:     004bbd63(j)  
    //                              Shape.cpp:3180 (5)
    //         004bbd6c     AND        DL,0x1
    //         004bbd6f     MOV        AL,DL
    //                              Shape.cpp:3184 (12)
    //         004bbd71     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbd75     AND        EDX,0xff
    //         004bbd7b     ADD        EDX,this
    //                              Shape.cpp:3185 (4)
    //         004bbd7d     CMP        this,EDX
    //         004bbd7f     JNC        LAB_004bbd8b
    //                               LAB_004bbd81                                                 XREF[1]:     004bbd89(j)  
    //                              Shape.cpp:3186 (10)
    //         004bbd81     MOV        byte ptr [this->shape],0x0
    //         004bbd84     ADD        this,0x2
    //         004bbd87     CMP        this,EDX
    //         004bbd89     JC         LAB_004bbd81
    //                               LAB_004bbd8b                                                 XREF[1]:     004bbd7f(j)  
    //                              Shape.cpp:3187 (4)
    //         004bbd8b     TEST       AL,AL
    //         004bbd8d     JZ         LAB_004bbdc9
    //                              Shape.cpp:3188 (1)
    //         004bbd8f     DEC        this
    //                              Shape.cpp:3190 (2)
    //         004bbd90     JMP        LAB_004bbdc9
    //                               LAB_004bbd92                                                 XREF[1]:     004bbd48(j)  
    //                              Shape.cpp:3193 (8)
    //         004bbd92     TEST       AL,AL
    //         004bbd94     MOV        byte ptr [ESP + param_8],DL
    //         004bbd98     JZ         LAB_004bbda1
    //                              Shape.cpp:3195 (2)
    //         004bbd9a     DEC        DL
    //                              Shape.cpp:3196 (5)
    //         004bbd9c     INC        this
    //         004bbd9d     MOV        byte ptr [ESP + param_8],DL
    //                               LAB_004bbda1                                                 XREF[1]:     004bbd98(j)  
    //                              Shape.cpp:3198 (5)
    //         004bbda1     AND        DL,0x1
    //         004bbda4     MOV        AL,DL
    //                              Shape.cpp:3202 (12)
    //         004bbda6     MOV        EDX,dword ptr [ESP + param_8]
    //         004bbdaa     AND        EDX,0xff
    //         004bbdb0     ADD        EDX,this
    //                              Shape.cpp:3203 (4)
    //         004bbdb2     CMP        this,EDX
    //         004bbdb4     JNC        LAB_004bbdc0
    //                               LAB_004bbdb6                                                 XREF[1]:     004bbdbe(j)  
    //                              Shape.cpp:3204 (10)
    //         004bbdb6     MOV        byte ptr [this->shape],0x0
    //         004bbdb9     ADD        this,0x2
    //         004bbdbc     CMP        this,EDX
    //         004bbdbe     JC         LAB_004bbdb6
    //                               LAB_004bbdc0                                                 XREF[1]:     004bbdb4(j)  
    //                              Shape.cpp:3205 (4)
    //         004bbdc0     TEST       AL,AL
    //         004bbdc2     JZ         LAB_004bbdc5
    //                              Shape.cpp:3206 (5)
    //         004bbdc4     DEC        this
    //                               LAB_004bbdc5                                                 XREF[1]:     004bbdc2(j)  
    //         004bbdc5     MOV        EDI,dword ptr [ESP + param_6]
    //                               LAB_004bbdc9                                                 XREF[2]:     004bbd8d(j), 004bbd90(j)  
    //                              Shape.cpp:3208 (1)
    //         004bbdc9     INC        EBP
    //                               LAB_004bbdca                                                 XREF[5]:     004bbc53(j), 004bbc5e(j), 
    //                                                                                                         004bbcd1(j), 004bbd11(j), 
    //                                                                                                         004bbd23(j)  
    //                              Shape.cpp:3100 (12)
    //         004bbdca     MOV        DL,byte ptr [ESP + param_5]
    //         004bbdce     TEST       DL,DL
    //         004bbdd0     JZ         LAB_004bbc0d
    //                               LAB_004bbdd6                                                 XREF[1]:     004bbc07(j)  
    //                              Shape.cpp:3214 (2)
    //         004bbdd6     DEC        DL
    //                              Shape.cpp:3215 (2)
    //         004bbdd8     JNZ        LAB_004bbe0a
    //                               LAB_004bbdda                                                 XREF[1]:     004bbe08(j)  
    //                              Shape.cpp:3217 (3)
    //         004bbdda     MOV        AL,byte ptr [EBP]
    //                              Shape.cpp:3218 (1)
    //         004bbddd     INC        EBP
    //                              Shape.cpp:3219 (10)
    //         004bbdde     MOV        this,AL
    //         004bbde0     AND        this,0x1
    //         004bbde3     CMP        this,0x1
    //         004bbde6     JNZ        LAB_004bbdfd
    //                              Shape.cpp:3221 (6)
    //         004bbde8     SHR        AL,0x1
    //         004bbdea     MOV        byte ptr [ESP + param_3],AL
    //                              Shape.cpp:3224 (2)
    //         004bbdee     JZ         LAB_004bbe05
    //                              Shape.cpp:3225 (11)
    //         004bbdf0     MOV        EAX,dword ptr [ESP + param_3]
    //         004bbdf4     AND        EAX,0xff
    //         004bbdf9     ADD        EBP,EAX
    //                              Shape.cpp:3227 (2)
    //         004bbdfb     JMP        LAB_004bbe06
    //                               LAB_004bbdfd                                                 XREF[1]:     004bbde6(j)  
    //                              Shape.cpp:3230 (4)
    //         004bbdfd     TEST       AL,0xfe
    //         004bbdff     JNZ        LAB_004bbe05
    //                              Shape.cpp:3231 (2)
    //         004bbe01     MOV        DL,0x2
    //                              Shape.cpp:3232 (2)
    //         004bbe03     JMP        LAB_004bbe06
    //                               LAB_004bbe05                                                 XREF[2]:     004bbdee(j), 004bbdff(j)  
    //                              Shape.cpp:3233 (1)
    //         004bbe05     INC        EBP
    //                               LAB_004bbe06                                                 XREF[2]:     004bbdfb(j), 004bbe03(j)  
    //                              Shape.cpp:3215 (4)
    //         004bbe06     TEST       DL,DL
    //         004bbe08     JZ         LAB_004bbdda
    //                               LAB_004bbe0a                                                 XREF[1]:     004bbdd8(j)  
    //                              Shape.cpp:3238 (35)
    //         004bbe0a     MOV        this,dword ptr [ESP + width]
    //         004bbe0e     MOV        EBX,dword ptr [ESP + local_4]
    //         004bbe12     MOV        EAX,dword ptr [ESP + save_buffer]
    //         004bbe16     MOV        EDX,dword ptr [ESP + param_7]
    //         004bbe1a     ADD        this,EBX
    //         004bbe1c     INC        EAX
    //         004bbe1d     CMP        EAX,EDX
    //         004bbe1f     MOV        dword ptr [ESP + width],this
    //         004bbe23     MOV        dword ptr [ESP + save_buffer],EAX
    //         004bbe27     JLE        LAB_004bb9df
    //                               LAB_004bbe2d                                                 XREF[1]:     004bb9d5(j)  
    //                              Shape.cpp:3243 (12)
    //         004bbe2d     POP        EDI
    //         004bbe2e     POP        ESI
    //         004bbe2f     POP        EBP
    //         004bbe30     MOV        AL,0x1
    //         004bbe32     POP        EBX
    //         004bbe33     ADD        ESP,0x10
    //         004bbe36     RET        0x24
}

