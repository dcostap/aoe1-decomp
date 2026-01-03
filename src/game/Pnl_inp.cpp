#include "../common.h"
#include "Pnl_inp.h"

TInputPanel::TInputPanel() {
    /* TODO: Stub */
//                              undefined __thiscall TInputPanel(TInputPanel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00476c35(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00476c2a(W)
//                               ??0TInputPanel@@QAE@XZ                                       XREF[1]:     create_input:00469081(c)
//                               TInputPanel::TInputPanel
//                              Pnl_inp.cpp:36 (53)
//         00476c10     PUSH       -0x1
//         00476c12     PUSH       FUN_0055e488
//         00476c17     MOV        EAX,FS:[0x0]
//         00476c1d     PUSH       EAX
//         00476c1e     MOV        dword ptr FS:[0x0],ESP
//         00476c25     PUSH       this
//         00476c26     PUSH       EBX
//         00476c27     PUSH       ESI
//         00476c28     MOV        ESI,this
//         00476c2a     MOV        dword ptr [ESP + local_10],ESI
//         00476c2e     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
//         00476c33     XOR        EBX,EBX
//         00476c35     MOV        dword ptr [ESP + local_4],EBX
//         00476c39     MOV        byte ptr [ESI + 0x188],BL
//         00476c3f     CALL       dword ptr [->USER32.DLL::GetCaretBlinkTime]      = 0048b0a2
//                              Pnl_inp.cpp:41 (128)
//         00476c45     MOV        this,dword ptr [ESP + 0xc]
//         00476c49     MOV        dword ptr [ESI + 0x18c],EAX
//         00476c4f     MOV        EAX,0x1
//         00476c54     MOV        dword ptr [ESI + 0x190],EBX
//         00476c5a     MOV        dword ptr [ESI + 0x194],EAX
//         00476c60     MOV        dword ptr [ESI + 0x1b0],EAX
//         00476c66     MOV        dword ptr [ESI + 0x80],EAX
//         00476c6c     MOV        dword ptr [ESI + 0x170],EAX
//         00476c72     MOV        dword ptr [ESI + 0x198],EBX
//         00476c78     MOV        dword ptr [ESI + 0x1a0],EBX
//         00476c7e     MOV        dword ptr [ESI + 0x1a4],EBX
//         00476c84     MOV        dword ptr [ESI + 0x1a8],EBX
//         00476c8a     MOV        word ptr [ESI + 0x1ac],BX
//         00476c91     MOV        word ptr [ESI + 0x1ae],BX
//         00476c98     MOV        word ptr [ESI + 0x1b4],BX
//         00476c9f     MOV        dword ptr [ESI],TInputPanel::`vftable'           = 00476cd0
//         00476ca5     MOV        byte ptr [ESI + 0xee],0x7
//         00476cac     MOV        dword ptr [ESI + 0x114],0x5
//         00476cb6     MOV        EAX,ESI
//         00476cb8     POP        ESI
//         00476cb9     MOV        dword ptr FS:[0x0],this
//         00476cc0     POP        EBX
//         00476cc1     ADD        ESP,0x10
//         00476cc4     RET
//         00476cc5     ??         90h
//         00476cc6     NOP
//         00476cc7     NOP
//         00476cc8     NOP
//         00476cc9     NOP
//         00476cca     NOP
//         00476ccb     NOP
//         00476ccc     NOP
//         00476ccd     NOP
//         00476cce     NOP
//         00476ccf     NOP
}

TInputPanel::~TInputPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TInputPanel(TInputPanel * this)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00476d1e(W), 00476d5e(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00476d6b(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00476d0a(W)
//                               ??1TInputPanel@@UAE@XZ                                       XREF[1]:     `scalar_deleting_destructor':00476
//                               TInputPanel::~TInputPanel
//                              Pnl_inp.cpp:47 (36)
//         00476cf0     PUSH       -0x1
//         00476cf2     PUSH       FUN_0055e4a8
//         00476cf7     MOV        EAX,FS:[0x0]
//         00476cfd     PUSH       EAX
//         00476cfe     MOV        dword ptr FS:[0x0],ESP
//         00476d05     PUSH       this
//         00476d06     PUSH       ESI
//         00476d07     MOV        ESI,this
//         00476d09     PUSH       EDI
//         00476d0a     MOV        dword ptr [ESP + local_10],ESI
//         00476d0e     MOV        dword ptr [ESI],TInputPanel::`vftable'           = 00476cd0
//                              Pnl_inp.cpp:48 (16)
//         00476d14     MOV        EAX,dword ptr [ESI + 0x1a4]
//         00476d1a     XOR        EDI,EDI
//         00476d1c     CMP        EAX,EDI
//         00476d1e     MOV        dword ptr [ESP + local_4],EDI
//         00476d22     JZ         LAB_00476d33
//                              Pnl_inp.cpp:50 (9)
//         00476d24     PUSH       EAX
//         00476d25     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00476d2a     ADD        ESP,0x4
//                              Pnl_inp.cpp:51 (6)
//         00476d2d     MOV        dword ptr [ESI + 0x1a4],EDI
//                               LAB_00476d33                                                 XREF[1]:     00476d22(j)
//                              Pnl_inp.cpp:53 (10)
//         00476d33     MOV        EAX,dword ptr [ESI + 0x1a8]
//         00476d39     CMP        EAX,EDI
//         00476d3b     JZ         LAB_00476d4c
//                              Pnl_inp.cpp:55 (9)
//         00476d3d     PUSH       EAX
//         00476d3e     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00476d43     ADD        ESP,0x4
//                              Pnl_inp.cpp:56 (8)
//         00476d46     MOV        dword ptr [ESI + 0x1a8],EDI
//                               LAB_00476d4c                                                 XREF[1]:     00476d3b(j)
//         00476d4c     MOV        this,ESI
//                              Pnl_inp.cpp:58 (6)
//         00476d4e     MOV        dword ptr [ESI + 0x1a0],EDI
//                              Pnl_inp.cpp:59 (10)
//         00476d54     MOV        dword ptr [ESI + 0x80],0x1
//                              Pnl_inp.cpp:60 (30)
//         00476d5e     MOV        dword ptr [ESP + local_4],0xffffffff
//         00476d66     CALL       TTextPanel::~TTextPanel                          void ~TTextPanel(TTextPanel * this)
//         00476d6b     MOV        this,dword ptr [ESP + local_c]
//         00476d6f     POP        EDI
//         00476d70     MOV        dword ptr FS:[0x0],this
//         00476d77     POP        ESI
//         00476d78     ADD        ESP,0x10
//         00476d7b     RET
//         00476d7c     ??         90h
//         00476d7d     NOP
//         00476d7e     NOP
//         00476d7f     NOP
}

long TInputPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, void* param_7, long param_8, long param_9, char* param_10, int param_11, uchar param_12, int param_13, uchar param_14, uchar param_15, short param_16, TDigital* param_17, char* param_18, FormatType param_19) {
    /* TODO: Stub */
//                              long __thiscall setup(TInputPanel * this, TDrawArea * param_1, TPane
//              long              EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     00476ddc(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00476dd7(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00476dd2(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00476dcd(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00476dc8(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     00476dc3(R)
//              void *            Stack[0x1c]:4  param_7                   XREF[1]:     00476dbe(R)
//              long              Stack[0x20]:4  param_8                   XREF[1]:     00476db9(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     00476db4(R)
//              char *            Stack[0x28]:4  param_10                  XREF[1]:     00476daf(R)
//              int               Stack[0x2c]:4  param_11                  XREF[1]:     00476daa(R)
//              uchar             Stack[0x30]:1  param_12                  XREF[1]:     00476d9e(R)
//              int               Stack[0x34]:4  param_13                  XREF[1]:     00476d9a(R)
//              uchar             Stack[0x38]:1  param_14                  XREF[1]:     00476da5(R)
//              uchar             Stack[0x3c]:1  param_15                  XREF[1]:     00476df7(R)
//              short             Stack[0x40]:2  param_16                  XREF[1]:     00476d81(R)
//              TDigital *        Stack[0x44]:4  param_17                  XREF[1]:     00476e2f(R)
//              char *            Stack[0x48]:4  param_18                  XREF[1]:     00476eb2(R)
//              FormatType        Stack[0x4c]:4  param_19                  XREF[1]:     00476d88(R)
//                               ?setup@TInputPanel@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJPAXJJP  XREF[1]:     create_input:0046910b(c)
//                               TInputPanel::setup
//                              Pnl_inp.cpp:71 (1)
//         00476d80     PUSH       EBX
//                              Pnl_inp.cpp:78 (105)
//         00476d81     MOV        BX,word ptr [ESP + param_16]
//         00476d86     PUSH       ESI
//         00476d87     PUSH       EDI
//         00476d88     MOV        EDI,dword ptr [ESP + param_19]
//         00476d8c     MOV        ESI,this
//         00476d8e     CMP        EDI,0x7
//         00476d91     JNZ        LAB_00476d97
//         00476d93     XOR        EAX,EAX
//         00476d95     JMP        LAB_00476d9a
//                               LAB_00476d97                                                 XREF[1]:     00476d91(j)
//         00476d97     MOVSX      EAX,BX
//                               LAB_00476d9a                                                 XREF[1]:     00476d95(j)
//         00476d9a     MOV        this,dword ptr [ESP + param_13]
//         00476d9e     MOV        EDX,dword ptr [ESP + param_12]
//         00476da2     PUSH       0x0
//         00476da4     PUSH       EAX
//         00476da5     MOV        EAX,dword ptr [ESP + param_14]
//         00476da9     PUSH       EAX
//         00476daa     MOV        EAX,dword ptr [ESP + param_11]
//         00476dae     PUSH       this
//         00476daf     MOV        this,dword ptr [ESP + param_10]
//         00476db3     PUSH       EDX
//         00476db4     MOV        EDX,dword ptr [ESP + param_9]
//         00476db8     PUSH       EAX
//         00476db9     MOV        EAX,dword ptr [ESP + param_8]
//         00476dbd     PUSH       this
//         00476dbe     MOV        this,dword ptr [ESP + param_7]
//         00476dc2     PUSH       EDX
//         00476dc3     MOV        EDX,dword ptr [ESP + param_6]
//         00476dc7     PUSH       EAX
//         00476dc8     MOV        EAX,dword ptr [ESP + param_5]
//         00476dcc     PUSH       this
//         00476dcd     MOV        this,dword ptr [ESP + param_4]
//         00476dd1     PUSH       EDX
//         00476dd2     MOV        EDX,dword ptr [ESP + param_3]
//         00476dd6     PUSH       EAX
//         00476dd7     MOV        EAX,dword ptr [ESP + param_2]
//         00476ddb     PUSH       this
//         00476ddc     MOV        this,dword ptr [ESP + param_1]
//         00476de0     PUSH       EDX
//         00476de1     PUSH       EAX
//         00476de2     PUSH       this
//         00476de3     MOV        this,ESI
//         00476de5     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
//                              Pnl_inp.cpp:80 (4)
//         00476dea     TEST       EAX,EAX
//         00476dec     JNZ        LAB_00476df4
//                              Pnl_inp.cpp:125 (6)
//         00476dee     POP        EDI
//         00476def     POP        ESI
//         00476df0     POP        EBX
//         00476df1     RET        0x4c
//                               LAB_00476df4                                                 XREF[1]:     00476dec(j)
//                              Pnl_inp.cpp:86 (23)
//         00476df4     MOV        EAX,dword ptr [ESI + 0x78]
//         00476df7     MOV        DL,byte ptr [ESP + param_15]
//         00476dfb     TEST       EAX,EAX
//         00476dfd     MOV        byte ptr [ESI + 0x188],DL
//         00476e03     MOV        dword ptr [ESI + 0x19c],EDI
//         00476e09     JZ         LAB_00476e2a
//                              Pnl_inp.cpp:89 (31)
//         00476e0b     PUSH       0x59
//         00476e0d     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00476e12     MOV        dword ptr [ESI + 0x194],0x1
//         00476e1c     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00476e21     ADD        ESP,0x8
//         00476e24     MOV        dword ptr [ESI + 0x190],EAX
//                               LAB_00476e2a                                                 XREF[1]:     00476e09(j)
//                              Pnl_inp.cpp:94 (5)
//         00476e2a     TEST       BX,BX
//         00476e2d     JZ         LAB_00476e3b
//                              Pnl_inp.cpp:95 (10)
//         00476e2f     MOV        EAX,dword ptr [ESP + param_17]
//         00476e33     MOV        dword ptr [ESI + 0x198],EAX
//                              Pnl_inp.cpp:96 (2)
//         00476e39     JMP        LAB_00476e45
//                               LAB_00476e3b                                                 XREF[1]:     00476e2d(j)
//                              Pnl_inp.cpp:97 (10)
//         00476e3b     MOV        dword ptr [ESI + 0x198],0x0
//                               LAB_00476e45                                                 XREF[1]:     00476e39(j)
//                              Pnl_inp.cpp:99 (9)
//         00476e45     CMP        dword ptr [ESI + 0x19c],0x7
//         00476e4c     JNZ        LAB_00476e64
//                              Pnl_inp.cpp:101 (11)
//         00476e4e     PUSH       0x1
//         00476e50     PUSH       0x3
//         00476e52     MOV        this,ESI
//         00476e54     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
//                              Pnl_inp.cpp:102 (9)
//         00476e59     PUSH       0x1
//         00476e5b     MOV        this,ESI
//         00476e5d     CALL       TTextPanel::set_word_wrap                        void set_word_wrap(TTextPanel * this, int par
//                              Pnl_inp.cpp:104 (2)
//         00476e62     JMP        LAB_00476e6f
//                               LAB_00476e64                                                 XREF[1]:     00476e4c(j)
//                              Pnl_inp.cpp:105 (11)
//         00476e64     PUSH       0x5
//         00476e66     PUSH       0x0
//         00476e68     MOV        this,ESI
//         00476e6a     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
//                               LAB_00476e6f                                                 XREF[1]:     00476e62(j)
//                              Pnl_inp.cpp:108 (24)
//         00476e6f     MOVSX      EAX,BX
//         00476e72     PUSH       0x1
//         00476e74     LEA        EDI,[EAX + EAX*0x1 + 0x1]
//         00476e78     PUSH       EDI
//         00476e79     CALL       calloc                                           undefined calloc()
//         00476e7e     ADD        ESP,0x8
//         00476e81     MOV        dword ptr [ESI + 0x1a4],EAX
//                              Pnl_inp.cpp:109 (4)
//         00476e87     TEST       EAX,EAX
//         00476e89     JNZ        LAB_00476e91
//                              Pnl_inp.cpp:125 (6)
//         00476e8b     POP        EDI
//         00476e8c     POP        ESI
//         00476e8d     POP        EBX
//         00476e8e     RET        0x4c
//                               LAB_00476e91                                                 XREF[1]:     00476e89(j)
//                              Pnl_inp.cpp:112 (17)
//         00476e91     PUSH       0x1
//         00476e93     PUSH       EDI
//         00476e94     CALL       calloc                                           undefined calloc()
//         00476e99     ADD        ESP,0x8
//         00476e9c     MOV        dword ptr [ESI + 0x1a8],EAX
//                              Pnl_inp.cpp:113 (4)
//         00476ea2     TEST       EAX,EAX
//         00476ea4     JNZ        LAB_00476eac
//                              Pnl_inp.cpp:125 (6)
//         00476ea6     POP        EDI
//         00476ea7     POP        ESI
//         00476ea8     POP        EBX
//         00476ea9     RET        0x4c
//                               LAB_00476eac                                                 XREF[1]:     00476ea4(j)
//                              Pnl_inp.cpp:116 (6)
//         00476eac     MOV        this,dword ptr [ESI + 0x1a4]
//                              Pnl_inp.cpp:118 (21)
//         00476eb2     MOV        EAX,dword ptr [ESP + param_18]
//         00476eb6     MOV        EDX,dword ptr [ESI]
//         00476eb8     MOV        dword ptr [ESI + 0x1a0],this
//         00476ebe     PUSH       EAX
//         00476ebf     MOV        this,ESI
//         00476ec1     CALL       dword ptr [EDX + 0xe8]
//                              Pnl_inp.cpp:122 (14)
//         00476ec7     MOV        this,ESI
//         00476ec9     MOV        word ptr [ESI + 0x1ae],BX
//         00476ed0     CALL       TInputPanel::reformat                            void reformat(TInputPanel * this)
//                              Pnl_inp.cpp:125 (11)
//         00476ed5     POP        EDI
//         00476ed6     POP        ESI
//         00476ed7     MOV        EAX,0x1
//         00476edc     POP        EBX
//         00476edd     RET        0x4c
    return 0;
}

void TInputPanel::set_focus(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_focus(TInputPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00476ee0(R)
//                               ?set_focus@TInputPanel@@UAEXH@Z                              XREF[1]:     00571548(*)
//                               TInputPanel::set_focus
//                              Pnl_inp.cpp:131 (13)
//         00476ee0     MOV        EAX,dword ptr [ESP + param_1]
//         00476ee4     PUSH       ESI
//         00476ee5     MOV        ESI,this
//         00476ee7     PUSH       EAX
//         00476ee8     CALL       TPanel::set_focus                                void set_focus(TPanel * this, int param_1)
//                              Pnl_inp.cpp:134 (7)
//         00476eed     MOV        EAX,dword ptr [ESI + 0x78]
//         00476ef0     TEST       EAX,EAX
//         00476ef2     JZ         LAB_00476f16
//                              Pnl_inp.cpp:137 (34)
//         00476ef4     PUSH       0x89
//         00476ef9     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00476efe     MOV        dword ptr [ESI + 0x194],0x1
//         00476f08     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00476f0d     ADD        ESP,0x8
//         00476f10     MOV        dword ptr [ESI + 0x190],EAX
//                               LAB_00476f16                                                 XREF[1]:     00476ef2(j)
//                              Pnl_inp.cpp:139 (4)
//         00476f16     POP        ESI
//         00476f17     RET        0x4
//         00476f1a     ??         90h
//         00476f1b     NOP
//         00476f1c     NOP
//         00476f1d     NOP
//         00476f1e     NOP
//         00476f1f     NOP
    return;
}

void TInputPanel::set_format(FormatType param_1) {
    /* TODO: Stub */
//                              void __thiscall set_format(TInputPanel * this, FormatType param_1)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              FormatType        Stack[0x4]:4   param_1                   XREF[1]:     00476f20(R)
//                               ?set_format@TInputPanel@@QAEXW4FormatType@1@@Z
//                               TInputPanel::set_format
//                              Pnl_inp.cpp:145 (10)
//         00476f20     MOV        EAX,dword ptr [ESP + param_1]
//         00476f24     MOV        dword ptr [ECX + this->format_type],EAX
//                              Pnl_inp.cpp:147 (3)
//         00476f2a     RET        0x4
//         00476f2d     ??         90h
//         00476f2e     NOP
//         00476f2f     NOP
    return;
}

long TInputPanel::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TInputPanel * this)
//              long              EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?handle_idle@TInputPanel@@UAEJXZ                             XREF[1]:     005714d4(*)
//                               TInputPanel::handle_idle
//                              Pnl_inp.cpp:153 (3)
//         00476f30     PUSH       ESI
//         00476f31     MOV        ESI,this
//                              Pnl_inp.cpp:156 (7)
//         00476f33     MOV        EAX,dword ptr [ESI + 0x78]
//         00476f36     TEST       EAX,EAX
//         00476f38     JZ         LAB_00476f92
//                              Pnl_inp.cpp:158 (15)
//         00476f3a     PUSH       0x9e
//         00476f3f     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00476f44     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              Pnl_inp.cpp:159 (21)
//         00476f49     MOV        EDX,dword ptr [ESI + 0x190]
//         00476f4f     MOV        this,dword ptr [ESI + 0x18c]
//         00476f55     SUB        EAX,EDX
//         00476f57     ADD        ESP,0x8
//         00476f5a     CMP        EAX,this
//         00476f5c     JC         LAB_00476f92
//                              Pnl_inp.cpp:161 (10)
//         00476f5e     MOV        EDX,dword ptr [ESI + 0x194]
//         00476f64     XOR        EAX,EAX
//         00476f66     TEST       EDX,EDX
//                              Pnl_inp.cpp:162 (18)
//         00476f68     MOV        EDX,dword ptr [ESI]
//         00476f6a     PUSH       0x1
//         00476f6c     SETZ       AL
//         00476f6f     MOV        this,ESI
//         00476f71     MOV        dword ptr [ESI + 0x194],EAX
//         00476f77     CALL       dword ptr [EDX + 0x20]
//                              Pnl_inp.cpp:163 (24)
//         00476f7a     PUSH       0xa3
//         00476f7f     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00476f84     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00476f89     ADD        ESP,0x8
//         00476f8c     MOV        dword ptr [ESI + 0x190],EAX
//                               LAB_00476f92                                                 XREF[2]:     00476f38(j), 00476f5c(j)
//                              Pnl_inp.cpp:167 (7)
//         00476f92     MOV        this,ESI
//         00476f94     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              Pnl_inp.cpp:168 (2)
//         00476f99     POP        ESI
//         00476f9a     RET
//         00476f9b     ??         90h
//         00476f9c     NOP
//         00476f9d     NOP
//         00476f9e     NOP
//         00476f9f     NOP
    return 0;
}

long TInputPanel::char_action(long param_1, short param_2) {
    /* TODO: Stub */
//                              long __thiscall char_action(TInputPanel * this, long param_1, short
//              long              EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00476fa3(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00476fdd(R)
//                               ?char_action@TInputPanel@@UAEJJF@Z                           XREF[1]:     00571538(*)
//                               TInputPanel::char_action
//                              Pnl_inp.cpp:177 (3)
//         00476fa0     PUSH       EBX
//         00476fa1     PUSH       EBP
//         00476fa2     PUSH       ESI
//                              Pnl_inp.cpp:181 (52)
//         00476fa3     MOV        ESI,dword ptr [ESP + param_1]
//         00476fa7     PUSH       EDI
//         00476fa8     CMP        ESI,0x8
//         00476fab     MOV        EDI,this
//         00476fad     JZ         LAB_004771ec
//         00476fb3     CMP        ESI,0x9
//         00476fb6     JZ         LAB_004771ec
//         00476fbc     CMP        ESI,0xa
//         00476fbf     JZ         LAB_004771ec
//         00476fc5     CMP        ESI,0xd
//         00476fc8     JZ         LAB_004771ec
//         00476fce     CMP        ESI,0x1b
//         00476fd1     JZ         LAB_004771ec
//                              Pnl_inp.cpp:185 (6)
//         00476fd7     JL         LAB_004771ec
//                              Pnl_inp.cpp:187 (9)
//         00476fdd     MOV        EBP,dword ptr [ESP + param_2]
//         00476fe1     TEST       BP,BP
//         00476fe4     JNZ        LAB_00476feb
//                              Pnl_inp.cpp:188 (5)
//         00476fe6     MOV        EBP,0x1
//                               LAB_00476feb                                                 XREF[1]:     00476fe4(j)
//                              Pnl_inp.cpp:190 (11)
//         00476feb     XOR        EBX,EBX
//         00476fed     TEST       BP,BP
//         00476ff0     JLE        LAB_004771ec
//                               LAB_00476ff6                                                 XREF[1]:     00477181(j)
//                              Pnl_inp.cpp:193 (22)
//         00476ff6     MOV        EAX,dword ptr [EDI + 0x19c]
//         00476ffc     CMP        EAX,0x8
//         00476fff     JA         switchD_00477005::caseD_0
//                               switchD_00477005::switchD
//         00477005     JMP        dword ptr [EAX*0x4 + switchD_00477005::switchd   = 00477171
//                               switchD_00477005::caseD_8                                    XREF[2]:     00477005(j), 00477218(*)
//                              Pnl_inp.cpp:199 (21)
//         0047700c     MOV        this,EDI
//         0047700e     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//         00477013     PUSH       EAX
//         00477014     CALL       __mbslen                                         undefined __mbslen()
//         00477019     ADD        ESP,0x4
//         0047701c     CMP        EAX,0x2
//         0047701f     JNC        LAB_0047702f
//                              Pnl_inp.cpp:201 (14)
//         00477021     CMP        ESI,0x30
//         00477024     JL         LAB_0047702f
//         00477026     CMP        ESI,0x39
//         00477029     JLE        switchD_00477005::caseD_0
//                               LAB_0047702f                                                 XREF[2]:     0047701f(j), 00477024(j)
//                              Pnl_inp.cpp:204 (34)
//         0047702f     MOV        this,EDI
//         00477031     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//         00477036     PUSH       EAX
//         00477037     CALL       __mbslen                                         undefined __mbslen()
//         0047703c     ADD        ESP,0x4
//         0047703f     CMP        EAX,0x2
//         00477042     JNZ        LAB_00477193
//         00477048     CMP        ESI,0x30
//         0047704b     JNZ        LAB_00477193
//                              Pnl_inp.cpp:206 (29)
//         00477051     MOV        this,EDI
//         00477053     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//         00477058     PUSH       EAX
//         00477059     PUSH       s_10                                             = "10"
//         0047705e     CALL       __mbscmp                                         undefined __mbscmp()
//         00477063     ADD        ESP,0x8
//         00477066     TEST       EAX,EAX
//         00477068     JNZ        LAB_00477193
//                              Pnl_inp.cpp:207 (5)
//         0047706e     JMP        switchD_00477005::caseD_0
//                               switchD_00477005::caseD_2                                    XREF[4]:     00477005(j), 004771fc(*),
//                               switchD_00477005::caseD_3                                                 00477200(*), 00477204(*)
//                               switchD_00477005::caseD_1
//                              Pnl_inp.cpp:219 (14)
//         00477073     CMP        ESI,0x30
//         00477076     JL         LAB_00477081
//         00477078     CMP        ESI,0x39
//         0047707b     JLE        switchD_00477005::caseD_0
//                               LAB_00477081                                                 XREF[1]:     00477076(j)
//                              Pnl_inp.cpp:221 (25)
//         00477081     CMP        ESI,0x2d
//         00477084     JNZ        LAB_0047709a
//         00477086     MOV        this,dword ptr [EDI + 0x1a0]
//         0047708c     CMP        byte ptr [this->_padding_],0x0
//         0047708f     JNZ        LAB_0047709a
//         00477091     CMP        EAX,0x3
//         00477094     JNZ        switchD_00477005::caseD_0
//                               LAB_0047709a                                                 XREF[2]:     00477084(j), 0047708f(j)
//                              Pnl_inp.cpp:223 (46)
//         0047709a     CMP        ESI,0x2e
//         0047709d     JNZ        LAB_004771ae
//         004770a3     MOV        EDX,dword ptr [EDI + 0x1a0]
//         004770a9     PUSH       ESI
//         004770aa     PUSH       EDX
//         004770ab     CALL       __mbschr                                         undefined __mbschr()
//         004770b0     ADD        ESP,0x8
//         004770b3     TEST       EAX,EAX
//         004770b5     JZ         LAB_004771ae
//         004770bb     CMP        dword ptr [EDI + 0x19c],0x1
//         004770c2     JNZ        LAB_004771ae
//                              Pnl_inp.cpp:224 (5)
//         004770c8     JMP        switchD_00477005::caseD_0
//                               switchD_00477005::caseD_5                                    XREF[3]:     00477005(j), 00477208(*),
//                               switchD_00477005::caseD_4                                                 0047720c(*)
//                              Pnl_inp.cpp:234 (34)
//         004770cd     CMP        ESI,0x2e
//         004770d0     JNZ        LAB_004770f8
//         004770d2     CMP        EAX,0x4
//         004770d5     JNZ        LAB_004770ef
//         004770d7     MOV        EAX,dword ptr [EDI + 0x1a0]
//         004770dd     PUSH       ESI
//         004770de     PUSH       EAX
//         004770df     CALL       __mbschr                                         undefined __mbschr()
//         004770e4     ADD        ESP,0x8
//         004770e7     TEST       EAX,EAX
//         004770e9     JZ         switchD_00477005::caseD_0
//                               LAB_004770ef                                                 XREF[1]:     004770d5(j)
//                              Pnl_inp.cpp:237 (78)
//         004770ef     CMP        ESI,0x2e
//         004770f2     JZ         LAB_004771ae
//                               LAB_004770f8                                                 XREF[1]:     004770d0(j)
//         004770f8     CMP        ESI,0x5c
//         004770fb     JZ         LAB_004771ae
//         00477101     CMP        ESI,0x3a
//         00477104     JZ         LAB_004771ae
//         0047710a     CMP        ESI,0x2f
//         0047710d     JZ         LAB_004771ae
//         00477113     CMP        ESI,0x22
//         00477116     JZ         LAB_004771ae
//         0047711c     CMP        ESI,0x2a
//         0047711f     JZ         LAB_004771ae
//         00477125     CMP        ESI,0x3f
//         00477128     JZ         LAB_004771ae
//         0047712e     CMP        ESI,0x3e
//         00477131     JZ         LAB_004771ae
//         00477133     CMP        ESI,0x3c
//         00477136     JZ         LAB_004771ae
//         00477138     CMP        ESI,0x7c
//         0047713b     JZ         LAB_004771ae
//                              Pnl_inp.cpp:246 (2)
//         0047713d     JMP        switchD_00477005::caseD_0
//                               switchD_00477005::caseD_6                                    XREF[2]:     00477005(j), 00477210(*)
//                              Pnl_inp.cpp:250 (50)
//         0047713f     CMP        ESI,0x3a
//         00477142     JNZ        LAB_0047714e
//         00477144     CMP        word ptr [EDI + 0x1ac],0x1
//         0047714c     JNZ        LAB_004771c9
//                               LAB_0047714e                                                 XREF[1]:     00477142(j)
//         0047714e     CMP        ESI,0x2f
//         00477151     JZ         LAB_004771c9
//         00477153     CMP        ESI,0x22
//         00477156     JZ         LAB_004771c9
//         00477158     CMP        ESI,0x2a
//         0047715b     JZ         LAB_004771c9
//         0047715d     CMP        ESI,0x3f
//         00477160     JZ         LAB_004771c9
//         00477162     CMP        ESI,0x3e
//         00477165     JZ         LAB_004771c9
//         00477167     CMP        ESI,0x3c
//         0047716a     JZ         LAB_004771c9
//         0047716c     CMP        ESI,0x7c
//         0047716f     JZ         LAB_004771c9
//                               switchD_00477005::caseD_7                                    XREF[11]:    00476fff(j), 00477005(j),
//                               switchD_00477005::caseD_0                                                 00477029(j), 0047706e(j),
//                                                                                                         0047707b(j), 00477094(j),
//                                                                                                         004770c8(j), 004770e9(j),
//                                                                                                         0047713d(j), 004771f8(*),
//                                                                                                         00477214(*)
//                              Pnl_inp.cpp:263 (22)
//         00477171     PUSH       ESI
//         00477172     MOV        this,EDI
//         00477174     CALL       TInputPanel::insert_character                    int insert_character(TInputPanel * this, long
//         00477179     TEST       EAX,EAX
//         0047717b     JZ         LAB_004771ec
//         0047717d     INC        EBX
//         0047717e     CMP        BX,BP
//         00477181     JL         LAB_00476ff6
//                              Pnl_inp.cpp:182 (5)
//         00477187     MOV        EAX,0x1
//                              Pnl_inp.cpp:268 (7)
//         0047718c     POP        EDI
//         0047718d     POP        ESI
//         0047718e     POP        EBP
//         0047718f     POP        EBX
//         00477190     RET        0x8
//                               LAB_00477193                                                 XREF[3]:     00477042(j), 0047704b(j),
//                                                                                                         00477068(j)
//                              Pnl_inp.cpp:210 (10)
//         00477193     MOV        this,dword ptr [EDI + 0x198]
//         00477199     TEST       this,this
//         0047719b     JZ         LAB_004771e4
//                              Pnl_inp.cpp:211 (5)
//         0047719d     CALL       TDigital::play                                   int play(TDigital * this)
//                              Pnl_inp.cpp:182 (5)
//         004771a2     MOV        EAX,0x1
//                              Pnl_inp.cpp:268 (7)
//         004771a7     POP        EDI
//         004771a8     POP        ESI
//         004771a9     POP        EBP
//         004771aa     POP        EBX
//         004771ab     RET        0x8
//                               LAB_004771ae                                                 XREF[13]:    0047709d(j), 004770b5(j),
//                                                                                                         004770c2(j), 004770f2(j),
//                                                                                                         004770fb(j), 00477104(j),
//                                                                                                         0047710d(j), 00477116(j),
//                                                                                                         0047711f(j), 00477128(j),
//                                                                                                         00477131(j), 00477136(j),
//                                                                                                         0047713b(j)
//                              Pnl_inp.cpp:240 (10)
//         004771ae     MOV        this,dword ptr [EDI + 0x198]
//         004771b4     TEST       this,this
//         004771b6     JZ         LAB_004771e4
//                              Pnl_inp.cpp:254 (5)
//         004771b8     CALL       TDigital::play                                   int play(TDigital * this)
//                              Pnl_inp.cpp:182 (5)
//         004771bd     MOV        EAX,0x1
//                              Pnl_inp.cpp:268 (7)
//         004771c2     POP        EDI
//         004771c3     POP        ESI
//         004771c4     POP        EBP
//         004771c5     POP        EBX
//         004771c6     RET        0x8
//                               LAB_004771c9                                                 XREF[8]:     0047714c(j), 00477151(j),
//                                                                                                         00477156(j), 0047715b(j),
//                                                                                                         00477160(j), 00477165(j),
//                                                                                                         0047716a(j), 0047716f(j)
//                              Pnl_inp.cpp:253 (10)
//         004771c9     MOV        this,dword ptr [EDI + 0x198]
//         004771cf     TEST       this,this
//         004771d1     JZ         LAB_004771e4
//                              Pnl_inp.cpp:254 (5)
//         004771d3     CALL       TDigital::play                                   int play(TDigital * this)
//                              Pnl_inp.cpp:182 (5)
//         004771d8     MOV        EAX,0x1
//                              Pnl_inp.cpp:268 (7)
//         004771dd     POP        EDI
//         004771de     POP        ESI
//         004771df     POP        EBP
//         004771e0     POP        EBX
//         004771e1     RET        0x8
//                               LAB_004771e4                                                 XREF[3]:     0047719b(j), 004771b6(j),
//                                                                                                         004771d1(j)
//                              Pnl_inp.cpp:256 (8)
//         004771e4     PUSH       -0x1
//         004771e6     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
//                               LAB_004771ec                                                 XREF[8]:     00476fad(j), 00476fb6(j),
//                                                                                                         00476fbf(j), 00476fc8(j),
//                                                                                                         00476fd1(j), 00476fd7(j),
//                                                                                                         00476ff0(j), 0047717b(j)
//                              Pnl_inp.cpp:268 (48)
//         004771ec     POP        EDI
//         004771ed     POP        ESI
//         004771ee     POP        EBP
//         004771ef     MOV        EAX,0x1
//         004771f4     POP        EBX
//         004771f5     RET        0x8
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00477005::switchdataD_004771f8                       XREF[1]:     char_action:00477005(*)
//         004771f8     addr       switchD_00477005::caseD_0
//         004771fc     addr       switchD_00477005::caseD_1
//         00477200     addr       switchD_00477005::caseD_1
//         00477204     addr       switchD_00477005::caseD_1
//         00477208     addr       switchD_00477005::caseD_4
//         0047720c     addr       switchD_00477005::caseD_4
//         00477210     addr       switchD_00477005::caseD_6
//         00477214     addr       switchD_00477005::caseD_0
//         00477218     addr       switchD_00477005::caseD_8
//         0047721c     ??         90h
//         0047721d     ??         90h
//         0047721e     ??         90h
//         0047721f     ??         90h
    return 0;
}

long TInputPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TInputPanel * this, long param_1, sh
//              long              EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00477220(R)
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[4]:     00477402(R), 00477481(R), 00477673(R), 00477709(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00477667(R)
//                               ?key_down_action@TInputPanel@@UAEJJFHHH@Z                    XREF[1]:     00571534(*)
//                               TInputPanel::key_down_action
//                              Pnl_inp.cpp:274 (35)
//         00477220     MOV        EAX,dword ptr [ESP + param_1]
//         00477224     PUSH       ESI
//         00477225     ADD        EAX,-0x8
//         00477228     PUSH       EDI
//         00477229     CMP        EAX,0x4e
//         0047722c     MOV        ESI,this
//         0047722e     JA         switchD_0047723c::caseD_9
//         00477234     XOR        this,this
//         00477236     MOV        this,byte ptr [EAX + 0x477768]=>PTR_caseD_56_0   = 00477709
//                               switchD_0047723c::switchD
//         0047723c     JMP        dword ptr [this->_padding_*0x4 + switchD_00477   = 0047769c
//                               switchD_0047723c::caseD_25                                   XREF[2]:     0047723c(j), 00477748(*)
//                              Pnl_inp.cpp:278 (10)
//         00477243     CMP        word ptr [ESI + 0xf8],0x1
//         0047724b     JGE        LAB_00477257
//                              Pnl_inp.cpp:279 (5)
//         0047724d     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477252     POP        EDI
//         00477253     POP        ESI
//         00477254     RET        0x14
//                               LAB_00477257                                                 XREF[1]:     0047724b(j)
//                              Pnl_inp.cpp:280 (12)
//         00477257     MOV        AX,word ptr [ESI + 0x102]
//         0047725e     TEST       AX,AX
//         00477261     JLE        LAB_00477269
//                              Pnl_inp.cpp:282 (1)
//         00477263     DEC        EAX
//                              Pnl_inp.cpp:286 (21)
//         00477264     JMP        LAB_00477635
//                               LAB_00477269                                                 XREF[1]:     00477261(j)
//         00477269     MOV        AX,word ptr [ESI + 0x100]
//         00477270     TEST       AX,AX
//         00477273     JLE        LAB_00477718
//                              Pnl_inp.cpp:288 (8)
//         00477279     DEC        EAX
//         0047727a     MOV        word ptr [ESI + 0x100],AX
//                              Pnl_inp.cpp:289 (4)
//         00477281     MOVSX      EAX,AX
//         00477284     PUSH       EAX
//                              Pnl_inp.cpp:293 (5)
//         00477285     JMP        LAB_00477625
//                               switchD_0047723c::caseD_27                                   XREF[2]:     0047723c(j), 00477750(*)
//                              Pnl_inp.cpp:296 (10)
//         0047728a     CMP        word ptr [ESI + 0xf8],0x1
//         00477292     JGE        LAB_0047729e
//                              Pnl_inp.cpp:297 (5)
//         00477294     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477299     POP        EDI
//         0047729a     POP        ESI
//         0047729b     RET        0x14
//                               LAB_0047729e                                                 XREF[1]:     00477292(j)
//                              Pnl_inp.cpp:298 (36)
//         0047729e     MOVSX      EAX,word ptr [ESI + 0x100]
//         004772a5     MOV        DI,word ptr [ESI + 0x102]
//         004772ac     PUSH       EAX
//         004772ad     MOV        this,ESI
//         004772af     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004772b4     PUSH       EAX
//         004772b5     CALL       __mbslen                                         undefined __mbslen()
//         004772ba     ADD        ESP,0x4
//         004772bd     CMP        DI,AX
//         004772c0     JGE        LAB_004772e4
//                              Pnl_inp.cpp:300 (1)
//         004772c2     INC        EDI
//                              Pnl_inp.cpp:301 (14)
//         004772c3     MOV        this,ESI
//         004772c5     MOV        word ptr [ESI + 0x102],DI
//         004772cc     CALL       TInputPanel::calc_input_pos                      void calc_input_pos(TInputPanel * this)
//                              Pnl_inp.cpp:302 (9)
//         004772d1     MOV        EDX,dword ptr [ESI]
//         004772d3     PUSH       0x1
//         004772d5     MOV        this,ESI
//         004772d7     CALL       dword ptr [EDX + 0x20]
//                              Pnl_inp.cpp:465 (5)
//         004772da     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         004772df     POP        EDI
//         004772e0     POP        ESI
//         004772e1     RET        0x14
//                               LAB_004772e4                                                 XREF[1]:     004772c0(j)
//                              Pnl_inp.cpp:304 (26)
//         004772e4     MOV        AX,word ptr [ESI + 0x100]
//         004772eb     MOVSX      this,word ptr [ESI + 0xf8]
//         004772f2     MOVSX      EDX,AX
//         004772f5     DEC        this
//         004772f6     CMP        EDX,this
//         004772f8     JGE        LAB_00477718
//                              Pnl_inp.cpp:306 (1)
//         004772fe     INC        EAX
//                              Pnl_inp.cpp:307 (16)
//         004772ff     MOV        word ptr [ESI + 0x102],0x0
//         00477308     MOV        word ptr [ESI + 0x100],AX
//                              Pnl_inp.cpp:311 (2)
//         0047730f     JMP        LAB_00477379
//                               switchD_0047723c::caseD_26                                   XREF[2]:     0047723c(j), 0047774c(*)
//                              Pnl_inp.cpp:314 (10)
//         00477311     CMP        word ptr [ESI + 0xf8],0x1
//         00477319     JGE        LAB_00477325
//                              Pnl_inp.cpp:315 (5)
//         0047731b     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477320     POP        EDI
//         00477321     POP        ESI
//         00477322     RET        0x14
//                               LAB_00477325                                                 XREF[1]:     00477319(j)
//                              Pnl_inp.cpp:316 (16)
//         00477325     MOV        AX,word ptr [ESI + 0x100]
//         0047732c     TEST       AX,AX
//         0047732f     JLE        LAB_00477718
//                              Pnl_inp.cpp:318 (1)
//         00477335     DEC        EAX
//                              Pnl_inp.cpp:319 (36)
//         00477336     MOVSX      this,AX
//         00477339     PUSH       this
//         0047733a     MOV        this,ESI
//         0047733c     MOV        word ptr [ESI + 0x100],AX
//         00477343     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         00477348     PUSH       EAX
//         00477349     CALL       __mbslen                                         undefined __mbslen()
//         0047734e     ADD        ESP,0x4
//         00477351     CMP        word ptr [ESI + 0x102],AX
//         00477358     JLE        LAB_00477379
//                              Pnl_inp.cpp:320 (31)
//         0047735a     MOVSX      EDX,word ptr [ESI + 0x100]
//         00477361     PUSH       EDX
//         00477362     MOV        this,ESI
//         00477364     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         00477369     PUSH       EAX
//         0047736a     CALL       __mbslen                                         undefined __mbslen()
//         0047736f     ADD        ESP,0x4
//         00477372     MOV        word ptr [ESI + 0x102],AX
//                               LAB_00477379                                                 XREF[2]:     0047730f(j), 00477358(j)
//                              Pnl_inp.cpp:321 (7)
//         00477379     MOV        this,ESI
//         0047737b     CALL       TInputPanel::calc_input_pos                      void calc_input_pos(TInputPanel * this)
//                              Pnl_inp.cpp:322 (9)
//         00477380     MOV        EAX,dword ptr [ESI]
//         00477382     PUSH       0x1
//         00477384     MOV        this,ESI
//         00477386     CALL       dword ptr [EAX + 0x20]
//                              Pnl_inp.cpp:324 (5)
//         00477389     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         0047738e     POP        EDI
//         0047738f     POP        ESI
//         00477390     RET        0x14
//                               switchD_0047723c::caseD_28                                   XREF[2]:     0047723c(j), 00477754(*)
//                              Pnl_inp.cpp:327 (13)
//         00477393     MOV        this,word ptr [ESI + 0xf8]
//         0047739a     CMP        this,0x1
//         0047739e     JGE        LAB_004773aa
//                              Pnl_inp.cpp:328 (5)
//         004773a0     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         004773a5     POP        EDI
//         004773a6     POP        ESI
//         004773a7     RET        0x14
//                               LAB_004773aa                                                 XREF[1]:     0047739e(j)
//                              Pnl_inp.cpp:329 (22)
//         004773aa     MOV        AX,word ptr [ESI + 0x100]
//         004773b1     MOVSX      this,this
//         004773b4     MOVSX      EDX,AX
//         004773b7     DEC        this
//         004773b8     CMP        EDX,this
//         004773ba     JGE        LAB_00477718
//                              Pnl_inp.cpp:331 (1)
//         004773c0     INC        EAX
//                              Pnl_inp.cpp:332 (40)
//         004773c1     MOV        this,ESI
//         004773c3     MOV        word ptr [ESI + 0x100],AX
//         004773ca     MOVSX      EAX,AX
//         004773cd     PUSH       EAX
//         004773ce     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004773d3     PUSH       EAX
//         004773d4     CALL       __mbslen                                         undefined __mbslen()
//         004773d9     ADD        ESP,0x4
//         004773dc     CMP        word ptr [ESI + 0x102],AX
//         004773e3     JLE        LAB_0047763c
//                              Pnl_inp.cpp:337 (5)
//         004773e9     JMP        LAB_0047761d
//                               switchD_0047723c::caseD_24                                   XREF[2]:     0047723c(j), 00477744(*)
//                              Pnl_inp.cpp:340 (10)
//         004773ee     CMP        word ptr [ESI + 0xf8],0x1
//         004773f6     JGE        LAB_00477402
//                              Pnl_inp.cpp:341 (5)
//         004773f8     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         004773fd     POP        EDI
//         004773fe     POP        ESI
//         004773ff     RET        0x14
//                               LAB_00477402                                                 XREF[1]:     004773f6(j)
//                              Pnl_inp.cpp:342 (8)
//         00477402     MOV        EAX,dword ptr [ESP + param_4]
//         00477406     TEST       EAX,EAX
//         00477408     JZ         LAB_0047744e
//                              Pnl_inp.cpp:344 (24)
//         0047740a     CMP        word ptr [ESI + 0x102],0x0
//         00477412     JNZ        LAB_00477422
//         00477414     CMP        word ptr [ESI + 0x100],0x0
//         0047741c     JZ         LAB_00477718
//                               LAB_00477422                                                 XREF[1]:     00477412(j)
//                              Pnl_inp.cpp:348 (25)
//         00477422     MOV        this,ESI
//         00477424     MOV        word ptr [ESI + 0x102],0x0
//         0047742d     MOV        word ptr [ESI + 0x100],0x0
//         00477436     CALL       TInputPanel::calc_input_pos                      void calc_input_pos(TInputPanel * this)
//                              Pnl_inp.cpp:349 (9)
//         0047743b     MOV        EAX,dword ptr [ESI]
//         0047743d     PUSH       0x1
//         0047743f     MOV        this,ESI
//         00477441     CALL       dword ptr [EAX + 0x20]
//                              Pnl_inp.cpp:465 (5)
//         00477444     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477449     POP        EDI
//         0047744a     POP        ESI
//         0047744b     RET        0x14
//                               LAB_0047744e                                                 XREF[1]:     00477408(j)
//                              Pnl_inp.cpp:354 (14)
//         0047744e     CMP        word ptr [ESI + 0x102],0x0
//         00477456     JZ         LAB_00477718
//                              Pnl_inp.cpp:356 (9)
//         0047745c     MOV        word ptr [ESI + 0x102],0x0
//                              Pnl_inp.cpp:361 (5)
//         00477465     JMP        LAB_0047750f
//                               switchD_0047723c::caseD_23                                   XREF[2]:     0047723c(j), 00477740(*)
//                              Pnl_inp.cpp:364 (13)
//         0047746a     MOV        AX,word ptr [ESI + 0xf8]
//         00477471     CMP        AX,0x1
//         00477475     JGE        LAB_00477481
//                              Pnl_inp.cpp:365 (5)
//         00477477     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         0047747c     POP        EDI
//         0047747d     POP        ESI
//         0047747e     RET        0x14
//                               LAB_00477481                                                 XREF[1]:     00477475(j)
//                              Pnl_inp.cpp:366 (8)
//         00477481     MOV        this,dword ptr [ESP + param_4]
//         00477485     TEST       this,this
//         00477487     JZ         LAB_004774cb
//                              Pnl_inp.cpp:368 (45)
//         00477489     MOVSX      this,word ptr [ESI + 0x100]
//         00477490     MOVSX      EAX,AX
//         00477493     DEC        EAX
//         00477494     CMP        this,EAX
//         00477496     JNZ        LAB_004774b6
//         00477498     PUSH       this
//         00477499     MOV        this,ESI
//         0047749b     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004774a0     PUSH       EAX
//         004774a1     CALL       __mbslen                                         undefined __mbslen()
//         004774a6     ADD        ESP,0x4
//         004774a9     CMP        word ptr [ESI + 0x102],AX
//         004774b0     JZ         LAB_00477718
//                               LAB_004774b6                                                 XREF[1]:     00477496(j)
//                              Pnl_inp.cpp:370 (16)
//         004774b6     MOV        AX,word ptr [ESI + 0xf8]
//         004774bd     DEC        AX
//         004774bf     MOV        word ptr [ESI + 0x100],AX
//                              Pnl_inp.cpp:371 (3)
//         004774c6     MOVSX      this,AX
//                              Pnl_inp.cpp:376 (2)
//         004774c9     JMP        LAB_004774f7
//                               LAB_004774cb                                                 XREF[1]:     00477487(j)
//                              Pnl_inp.cpp:378 (37)
//         004774cb     MOVSX      EAX,word ptr [ESI + 0x100]
//         004774d2     PUSH       EAX
//         004774d3     MOV        this,ESI
//         004774d5     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004774da     PUSH       EAX
//         004774db     CALL       __mbslen                                         undefined __mbslen()
//         004774e0     ADD        ESP,0x4
//         004774e3     CMP        word ptr [ESI + 0x102],AX
//         004774ea     JZ         LAB_00477718
//                              Pnl_inp.cpp:380 (31)
//         004774f0     MOVSX      this,word ptr [ESI + 0x100]
//                               LAB_004774f7                                                 XREF[1]:     004774c9(j)
//         004774f7     PUSH       this
//         004774f8     MOV        this,ESI
//         004774fa     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004774ff     PUSH       EAX
//         00477500     CALL       __mbslen                                         undefined __mbslen()
//         00477505     ADD        ESP,0x4
//         00477508     MOV        word ptr [ESI + 0x102],AX
//                               LAB_0047750f                                                 XREF[1]:     00477465(j)
//                              Pnl_inp.cpp:381 (9)
//         0047750f     MOV        EDX,dword ptr [ESI]
//         00477511     PUSH       0x1
//         00477513     MOV        this,ESI
//         00477515     CALL       dword ptr [EDX + 0x20]
//                              Pnl_inp.cpp:382 (7)
//         00477518     MOV        this,ESI
//         0047751a     CALL       TInputPanel::calc_input_pos                      void calc_input_pos(TInputPanel * this)
//                              Pnl_inp.cpp:385 (5)
//         0047751f     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477524     POP        EDI
//         00477525     POP        ESI
//         00477526     RET        0x14
//                               switchD_0047723c::caseD_21                                   XREF[2]:     0047723c(j), 00477738(*)
//                              Pnl_inp.cpp:388 (10)
//         00477529     CMP        word ptr [ESI + 0xf8],0x1
//         00477531     JGE        LAB_0047753d
//                              Pnl_inp.cpp:389 (5)
//         00477533     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477538     POP        EDI
//         00477539     POP        ESI
//         0047753a     RET        0x14
//                               LAB_0047753d                                                 XREF[1]:     00477531(j)
//                              Pnl_inp.cpp:390 (16)
//         0047753d     MOV        this,word ptr [ESI + 0x100]
//         00477544     TEST       this,this
//         00477547     JLE        LAB_00477718
//                              Pnl_inp.cpp:392 (21)
//         0047754d     MOV        AX,word ptr [ESI + 0xfc]
//         00477554     CMP        this,AX
//         00477557     JL         LAB_00477562
//         00477559     CMP        this,word ptr [ESI + 0xfe]
//         00477560     JLE        LAB_00477569
//                               LAB_00477562                                                 XREF[1]:     00477557(j)
//                              Pnl_inp.cpp:393 (7)
//         00477562     MOV        word ptr [ESI + 0x100],AX
//                               LAB_00477569                                                 XREF[1]:     00477560(j)
//                              Pnl_inp.cpp:394 (13)
//         00477569     CMP        word ptr [ESI + 0x100],AX
//         00477570     JNZ        LAB_004775f9
//                              Pnl_inp.cpp:396 (13)
//         00477576     PUSH       0x1
//         00477578     PUSH       0x0
//         0047757a     PUSH       0x5
//         0047757c     MOV        this,ESI
//         0047757e     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_inp.cpp:397 (7)
//         00477583     MOV        AX,word ptr [ESI + 0xfc]
//                              Pnl_inp.cpp:406 (2)
//         0047758a     JMP        LAB_004775f9
//                               switchD_0047723c::caseD_22                                   XREF[2]:     0047723c(j), 0047773c(*)
//                              Pnl_inp.cpp:409 (13)
//         0047758c     MOV        AX,word ptr [ESI + 0xf8]
//         00477593     CMP        AX,0x1
//         00477597     JGE        LAB_004775a3
//                              Pnl_inp.cpp:410 (5)
//         00477599     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         0047759e     POP        EDI
//         0047759f     POP        ESI
//         004775a0     RET        0x14
//                               LAB_004775a3                                                 XREF[1]:     00477597(j)
//                              Pnl_inp.cpp:411 (22)
//         004775a3     MOV        this,word ptr [ESI + 0x100]
//         004775aa     MOVSX      EAX,AX
//         004775ad     MOVSX      EDX,this
//         004775b0     DEC        EAX
//         004775b1     CMP        EDX,EAX
//         004775b3     JGE        LAB_00477718
//                              Pnl_inp.cpp:413 (21)
//         004775b9     CMP        this,word ptr [ESI + 0xfc]
//         004775c0     JL         LAB_004775ce
//         004775c2     MOV        AX,word ptr [ESI + 0xfe]
//         004775c9     CMP        this,AX
//         004775cc     JLE        LAB_004775dc
//                               LAB_004775ce                                                 XREF[1]:     004775c0(j)
//                              Pnl_inp.cpp:414 (14)
//         004775ce     MOV        AX,word ptr [ESI + 0xfe]
//         004775d5     MOV        word ptr [ESI + 0x100],AX
//                               LAB_004775dc                                                 XREF[1]:     004775cc(j)
//                              Pnl_inp.cpp:415 (9)
//         004775dc     CMP        word ptr [ESI + 0x100],AX
//         004775e3     JNZ        LAB_004775f9
//                              Pnl_inp.cpp:417 (13)
//         004775e5     PUSH       0x1
//         004775e7     PUSH       0x0
//         004775e9     PUSH       0x4
//         004775eb     MOV        this,ESI
//         004775ed     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_inp.cpp:418 (7)
//         004775f2     MOV        AX,word ptr [ESI + 0xfe]
//                               LAB_004775f9                                                 XREF[3]:     00477570(j), 0047758a(j),
//                                                                                                         004775e3(j)
//                              Pnl_inp.cpp:421 (7)
//         004775f9     MOV        word ptr [ESI + 0x100],AX
//                              Pnl_inp.cpp:422 (29)
//         00477600     MOV        this,ESI
//         00477602     MOVSX      EAX,AX
//         00477605     PUSH       EAX
//         00477606     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         0047760b     PUSH       EAX
//         0047760c     CALL       __mbslen                                         undefined __mbslen()
//         00477611     ADD        ESP,0x4
//         00477614     CMP        word ptr [ESI + 0x102],AX
//         0047761b     JLE        LAB_0047763c
//                               LAB_0047761d                                                 XREF[1]:     004773e9(j)
//                              Pnl_inp.cpp:423 (31)
//         0047761d     MOVSX      this,word ptr [ESI + 0x100]
//         00477624     PUSH       this
//                               LAB_00477625                                                 XREF[1]:     00477285(j)
//         00477625     MOV        this,ESI
//         00477627     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         0047762c     PUSH       EAX
//         0047762d     CALL       __mbslen                                         undefined __mbslen()
//         00477632     ADD        ESP,0x4
//                               LAB_00477635                                                 XREF[1]:     00477264(j)
//         00477635     MOV        word ptr [ESI + 0x102],AX
//                               LAB_0047763c                                                 XREF[2]:     004773e3(j), 0047761b(j)
//                              Pnl_inp.cpp:424 (7)
//         0047763c     MOV        this,ESI
//         0047763e     CALL       TInputPanel::calc_input_pos                      void calc_input_pos(TInputPanel * this)
//                              Pnl_inp.cpp:425 (9)
//         00477643     MOV        EDX,dword ptr [ESI]
//         00477645     PUSH       0x1
//         00477647     MOV        this,ESI
//         00477649     CALL       dword ptr [EDX + 0x20]
//                              Pnl_inp.cpp:427 (5)
//         0047764c     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477651     POP        EDI
//         00477652     POP        ESI
//         00477653     RET        0x14
//                               switchD_0047723c::caseD_2e                                   XREF[2]:     0047723c(j), 0047775c(*)
//                              Pnl_inp.cpp:430 (7)
//         00477656     MOV        this,ESI
//         00477658     CALL       TInputPanel::delete_character                    int delete_character(TInputPanel * this)
//                              Pnl_inp.cpp:431 (5)
//         0047765d     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477662     POP        EDI
//         00477663     POP        ESI
//         00477664     RET        0x14
//                               switchD_0047723c::caseD_2d                                   XREF[2]:     0047723c(j), 00477758(*)
//                              Pnl_inp.cpp:434 (6)
//         00477667     MOV        EAX,dword ptr [ESP + param_5]
//         0047766b     TEST       EAX,EAX
//                              Pnl_inp.cpp:436 (18)
//         0047766d     JNZ        LAB_00477711
//         00477673     MOV        EAX,dword ptr [ESP + param_4]
//         00477677     TEST       EAX,EAX
//         00477679     JNZ        LAB_00477718
//                              Pnl_inp.cpp:439 (19)
//         0047767f     MOV        this,dword ptr [ESI + 0x1b0]
//         00477685     XOR        EAX,EAX
//         00477687     TEST       this,this
//         00477689     SETZ       AL
//         0047768c     MOV        dword ptr [ESI + 0x1b0],EAX
//                              Pnl_inp.cpp:440 (5)
//         00477692     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477697     POP        EDI
//         00477698     POP        ESI
//         00477699     RET        0x14
//                               switchD_0047723c::caseD_8                                    XREF[2]:     0047723c(j), 0047772c(*)
//                              Pnl_inp.cpp:443 (7)
//         0047769c     MOV        this,ESI
//         0047769e     CALL       TInputPanel::backspace_character                 int backspace_character(TInputPanel * this)
//                              Pnl_inp.cpp:444 (5)
//         004776a3     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         004776a8     POP        EDI
//         004776a9     POP        ESI
//         004776aa     RET        0x14
//                               switchD_0047723c::caseD_d                                    XREF[2]:     0047723c(j), 00477730(*)
//                              Pnl_inp.cpp:447 (9)
//         004776ad     CMP        dword ptr [ESI + 0x19c],0x7
//         004776b4     JNZ        LAB_004776c9
//                              Pnl_inp.cpp:448 (9)
//         004776b6     PUSH       0xa
//         004776b8     MOV        this,ESI
//         004776ba     CALL       TInputPanel::insert_character                    int insert_character(TInputPanel * this, long
//                              Pnl_inp.cpp:465 (5)
//         004776bf     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         004776c4     POP        EDI
//         004776c5     POP        ESI
//         004776c6     RET        0x14
//                               LAB_004776c9                                                 XREF[1]:     004776b4(j)
//                              Pnl_inp.cpp:451 (7)
//         004776c9     MOV        this,dword ptr [ESI + 0x40]
//         004776cc     TEST       this,this
//         004776ce     JZ         LAB_00477718
//                              Pnl_inp.cpp:452 (15)
//         004776d0     MOV        EDX,dword ptr [this->_padding_]
//         004776d2     PUSH       0x0
//         004776d4     PUSH       0x0
//         004776d6     PUSH       0x0
//         004776d8     PUSH       ESI
//         004776d9     CALL       dword ptr [EDX + 0xb4]
//                              Pnl_inp.cpp:454 (5)
//         004776df     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         004776e4     POP        EDI
//         004776e5     POP        ESI
//         004776e6     RET        0x14
//                               switchD_0047723c::caseD_1b                                   XREF[2]:     0047723c(j), 00477734(*)
//                              Pnl_inp.cpp:457 (7)
//         004776e9     MOV        this,dword ptr [ESI + 0x40]
//         004776ec     TEST       this,this
//         004776ee     JZ         LAB_00477718
//                              Pnl_inp.cpp:458 (15)
//         004776f0     MOV        EAX,dword ptr [this->_padding_]
//         004776f2     PUSH       0x0
//         004776f4     PUSH       0x0
//         004776f6     PUSH       0x1
//         004776f8     PUSH       ESI
//         004776f9     CALL       dword ptr [EAX + 0xb4]
//                              Pnl_inp.cpp:459 (5)
//         004776ff     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (5)
//         00477704     POP        EDI
//         00477705     POP        ESI
//         00477706     RET        0x14
//                               switchD_0047723c::caseD_56                                   XREF[2]:     0047723c(j), 00477760(*)
//                              Pnl_inp.cpp:462 (8)
//         00477709     MOV        EAX,dword ptr [ESP + param_4]
//         0047770d     TEST       EAX,EAX
//         0047770f     JZ         switchD_0047723c::caseD_9
//                               LAB_00477711                                                 XREF[1]:     0047766d(j)
//                              Pnl_inp.cpp:464 (7)
//         00477711     MOV        this,ESI
//         00477713     CALL       TInputPanel::paste                               int paste(TInputPanel * this)
//                               LAB_00477718                                                 XREF[13]:    00477273(j), 004772f8(j),
//                                                                                                         0047732f(j), 004773ba(j),
//                                                                                                         0047741c(j), 00477456(j),
//                                                                                                         004774b0(j), 004774ea(j),
//                                                                                                         00477547(j), 004775b3(j),
//                                                                                                         00477679(j), 004776ce(j),
//                                                                                                         004776ee(j)
//                              Pnl_inp.cpp:465 (5)
//         00477718     MOV        EAX,0x1
//                              Pnl_inp.cpp:471 (154)
//         0047771d     POP        EDI
//         0047771e     POP        ESI
//         0047771f     RET        0x14
//                               switchD_0047723c::caseD_a                                    XREF[4]:     0047722e(j), 0047723c(j),
//                               switchD_0047723c::caseD_b                                                 0047770f(j), 00477764(*)
//                               switchD_0047723c::caseD_c
//                               switchD_0047723c::caseD_e
//                               switchD_0047723c::caseD_f
//                               switchD_0047723c::caseD_10
//                               switchD_0047723c::caseD_11
//                               switchD_0047723c::caseD_12
//                               switchD_0047723c::caseD_13
//                               switchD_0047723c::caseD_14
//                               switchD_0047723c::caseD_15
//                               switchD_0047723c::caseD_16
//                               switchD_0047723c::caseD_17
//                               switchD_0047723c::caseD_18
//                               switchD_0047723c::caseD_19
//                               switchD_0047723c::caseD_1a
//                               switchD_0047723c::caseD_1c
//                               switchD_0047723c::caseD_1d
//                               switchD_0047723c::caseD_1e
//                               switchD_0047723c::caseD_1f
//                               switchD_0047723c::caseD_20
//                               switchD_0047723c::caseD_29
//                               switchD_0047723c::caseD_2a
//                               switchD_0047723c::caseD_2b
//                               switchD_0047723c::caseD_2c
//                               switchD_0047723c::caseD_2f
//                               switchD_0047723c::caseD_30
//                               switchD_0047723c::caseD_31
//                               switchD_0047723c::caseD_32
//                               switchD_0047723c::caseD_33
//                               switchD_0047723c::caseD_34
//                               switchD_0047723c::caseD_35
//                               switchD_0047723c::caseD_36
//                               switchD_0047723c::caseD_37
//                               switchD_0047723c::caseD_38
//                               switchD_0047723c::caseD_39
//                               switchD_0047723c::caseD_3a
//                               switchD_0047723c::caseD_3b
//                               switchD_0047723c::caseD_3c
//                               switchD_0047723c::caseD_3d
//                               switchD_0047723c::caseD_3e
//                               switchD_0047723c::caseD_3f
//                               switchD_0047723c::caseD_40
//                               switchD_0047723c::caseD_41
//                               switchD_0047723c::caseD_42
//                               switchD_0047723c::caseD_43
//                               switchD_0047723c::caseD_44
//                               switchD_0047723c::caseD_45
//                               switchD_0047723c::caseD_46
//                               switchD_0047723c::caseD_47
//                               switchD_0047723c::caseD_48
//                               switchD_0047723c::caseD_49
//                               switchD_0047723c::caseD_4a
//                               switchD_0047723c::caseD_4b
//                               switchD_0047723c::caseD_4c
//                               switchD_0047723c::caseD_4d
//                               switchD_0047723c::caseD_4e
//                               switchD_0047723c::caseD_4f
//                               switchD_0047723c::caseD_50
//                               switchD_0047723c::caseD_51
//                               switchD_0047723c::caseD_52
//                               switchD_0047723c::caseD_53
//                               switchD_0047723c::caseD_54
//                               switchD_0047723c::caseD_55
//                               switchD_0047723c::caseD_9
//         00477722     POP        EDI
//         00477723     XOR        EAX,EAX
//         00477725     POP        ESI
//         00477726     RET        0x14
    return 0;
}

void TInputPanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TInputPanel * this)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   line_rect                 XREF[1]:     0047782f(W)
//              long              Stack[-0x1c]:4 cursor_x_offset
//                               ?draw@TInputPanel@@UAEXXZ                                    XREF[1]:     005714b8(*)
//                               TInputPanel::draw
//                              Pnl_inp.cpp:477 (6)
//         004777c0     SUB        ESP,0x18
//         004777c3     PUSH       ESI
//         004777c4     MOV        ESI,this
//                              Pnl_inp.cpp:486 (5)
//         004777c6     CALL       TTextPanel::draw                                 void draw(TTextPanel * this)
//                              Pnl_inp.cpp:488 (33)
//         004777cb     MOV        EAX,dword ptr [ESI + 0x20]
//         004777ce     TEST       EAX,EAX
//         004777d0     JZ         LAB_00477905
//         004777d6     MOV        EAX,dword ptr [ESI + 0x70]
//         004777d9     TEST       EAX,EAX
//         004777db     JZ         LAB_00477905
//         004777e1     MOV        EAX,dword ptr [ESI + 0x6c]
//         004777e4     TEST       EAX,EAX
//         004777e6     JZ         LAB_00477905
//                              Pnl_inp.cpp:492 (58)
//         004777ec     MOV        EAX,dword ptr [ESI + 0x78]
//         004777ef     TEST       EAX,EAX
//         004777f1     JZ         LAB_00477905
//         004777f7     MOV        EAX,dword ptr [ESI + 0x194]
//         004777fd     TEST       EAX,EAX
//         004777ff     JZ         LAB_00477905
//         00477805     MOV        AX,word ptr [ESI + 0x100]
//         0047780c     CMP        AX,word ptr [ESI + 0xfc]
//         00477813     JL         LAB_00477905
//         00477819     CMP        AX,word ptr [ESI + 0xfe]
//         00477820     JG         LAB_00477905
//                              Pnl_inp.cpp:494 (16)
//         00477826     MOV        EAX,dword ptr [ESI]
//         00477828     PUSH       EDI
//         00477829     PUSH       EBP
//         0047782a     PUSH       EBX
//         0047782b     PUSH       0x0
//         0047782d     MOV        this,ESI
//         0047782f     MOV        dword ptr [ESP + line_rect.left],EAX
//         00477833     CALL       dword ptr [EAX + 0x28]
//                              Pnl_inp.cpp:496 (15)
//         00477836     MOV        this,dword ptr [ESI + 0x20]
//         00477839     PUSH       s_pnl_inp::draw                                  = "pnl_inp::draw"
//         0047783e     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         00477843     MOV        EDI,EAX
//                              Pnl_inp.cpp:497 (8)
//         00477845     TEST       EDI,EDI
//         00477847     JZ         LAB_004778f9
//                              Pnl_inp.cpp:499 (16)
//         0047784d     MOV        EAX,dword ptr [ESI + 0x104]
//         00477853     MOV        EBX,dword ptr [->GDI32.DLL::SelectObject]        = 0048b192
//         00477859     PUSH       EAX
//         0047785a     PUSH       EDI
//         0047785b     CALL       EBX=>GDI32.DLL::SelectObject
//                              Pnl_inp.cpp:500 (36)
//         0047785d     LEA        this,[ESP + 0x10]
//         00477861     MOV        EBP,EAX
//         00477863     MOV        AX,word ptr [ESI + 0x100]
//         0047786a     LEA        EDX,[ESP + 0x18]
//         0047786e     PUSH       this
//         0047786f     PUSH       EDX
//         00477870     PUSH       EAX
//         00477871     SUB        AX,word ptr [ESI + 0xfc]
//         00477878     MOV        this,ESI
//         0047787a     PUSH       EAX
//         0047787b     PUSH       EDI
//         0047787c     CALL       TTextPanel::calc_line_pos                        void calc_line_pos(TTextPanel * this, void *
//                              Pnl_inp.cpp:501 (4)
//         00477881     PUSH       EBP
//         00477882     PUSH       EDI
//         00477883     CALL       EBX=>GDI32.DLL::SelectObject
//                              Pnl_inp.cpp:503 (13)
//         00477885     MOV        this,dword ptr [ESI + 0x20]
//         00477888     PUSH       s_pnl_inp::draw                                  = "pnl_inp::draw"
//         0047788d     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              Pnl_inp.cpp:505 (19)
//         00477892     MOV        this,dword ptr [ESI + 0x20]
//         00477895     PUSH       0x1
//         00477897     PUSH       s_pnl_inp::draw                                  = "pnl_inp::draw"
//         0047789c     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         004778a1     TEST       EAX,EAX
//         004778a3     JZ         LAB_004778f9
//                              Pnl_inp.cpp:510 (8)
//         004778a5     MOV        EAX,dword ptr [ESP + 0x10]
//         004778a9     MOV        this,dword ptr [ESP + 0x18]
//                              Pnl_inp.cpp:513 (11)
//         004778ad     MOV        EDI,dword ptr [ESP + 0x24]
//         004778b1     LEA        EBX,[EAX + this->_padding_*0x1]
//         004778b4     MOV        EAX,dword ptr [ESP + 0x1c]
//                              Pnl_inp.cpp:514 (15)
//         004778b8     MOV        this,dword ptr [ESI + 0x94]
//         004778be     SUB        EDI,EAX
//         004778c0     INC        EDI
//         004778c1     CMP        EBX,this
//         004778c3     MOV        EBP,EAX
//         004778c5     JGE        LAB_004778ec
//                              Pnl_inp.cpp:516 (18)
//         004778c7     MOV        DL,byte ptr [ESI + 0x188]
//         004778cd     MOV        this,dword ptr [ESI + 0x20]
//         004778d0     PUSH       EDX
//         004778d1     PUSH       EDI
//         004778d2     PUSH       EAX
//         004778d3     PUSH       EBX
//         004778d4     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
//                              Pnl_inp.cpp:517 (19)
//         004778d9     MOV        AL,byte ptr [ESI + 0x188]
//         004778df     MOV        this,dword ptr [ESI + 0x20]
//         004778e2     PUSH       EAX
//         004778e3     PUSH       EDI
//         004778e4     INC        EBX
//         004778e5     PUSH       EBP
//         004778e6     PUSH       EBX
//         004778e7     CALL       TDrawArea::DrawVertLine                          void DrawVertLine(TDrawArea * this, long para
//                               LAB_004778ec                                                 XREF[1]:     004778c5(j)
//                              Pnl_inp.cpp:519 (13)
//         004778ec     MOV        this,dword ptr [ESI + 0x20]
//         004778ef     PUSH       s_pnl_inp::draw                                  = "pnl_inp::draw"
//         004778f4     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_004778f9                                                 XREF[2]:     00477847(j), 004778a3(j)
//                              Pnl_inp.cpp:523 (12)
//         004778f9     MOV        EDX,dword ptr [ESP + 0x14]
//         004778fd     MOV        this,ESI
//         004778ff     CALL       dword ptr [EDX + 0x2c]
//         00477902     POP        EBX
//         00477903     POP        EBP
//         00477904     POP        EDI
//                               LAB_00477905                                                 XREF[7]:     004777d0(j), 004777db(j),
//                                                                                                         004777e6(j), 004777f1(j),
//                                                                                                         004777ff(j), 00477813(j),
//                                                                                                         00477820(j)
//                              Pnl_inp.cpp:525 (5)
//         00477905     POP        ESI
//         00477906     ADD        ESP,0x18
//         00477909     RET
//         0047790a     ??         90h
//         0047790b     NOP
//         0047790c     NOP
//         0047790d     NOP
//         0047790e     NOP
//         0047790f     NOP
    return;
}

void TInputPanel::set_text(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TInputPanel * this, char * param_1)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047791d(R)
//                               ?set_text@TInputPanel@@UAEXPAD@Z                             XREF[1]:     00571570(*)
//                               TInputPanel::set_text
//                              Pnl_inp.cpp:532 (3)
//         00477910     PUSH       ESI
//         00477911     MOV        ESI,this
//                              Pnl_inp.cpp:533 (10)
//         00477913     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00477919     TEST       EAX,EAX
//         0047791b     JZ         LAB_00477989
//                              Pnl_inp.cpp:536 (8)
//         0047791d     MOV        this,dword ptr [ESP + param_1]
//         00477921     TEST       this,this
//         00477923     JNZ        LAB_00477929
//                              Pnl_inp.cpp:537 (2)
//         00477925     MOV        byte ptr [EAX],this
//                              Pnl_inp.cpp:538 (2)
//         00477927     JMP        LAB_00477933
//                               LAB_00477929                                                 XREF[1]:     00477923(j)
//                              Pnl_inp.cpp:539 (10)
//         00477929     PUSH       this
//         0047792a     PUSH       EAX
//         0047792b     CALL       __mbscpy                                         undefined __mbscpy()
//         00477930     ADD        ESP,0x8
//                               LAB_00477933                                                 XREF[1]:     00477927(j)
//                              Pnl_inp.cpp:540 (12)
//         00477933     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00477939     PUSH       EAX
//         0047793a     CALL       __mbslen                                         undefined __mbslen()
//                              Pnl_inp.cpp:546 (53)
//         0047793f     MOV        this,dword ptr [ESI + 0x19c]
//         00477945     ADD        ESP,0x4
//         00477948     CMP        this,0x7
//         0047794b     MOV        word ptr [ESI + 0x1ac],AX
//         00477952     MOV        word ptr [ESI + 0x1b4],0x0
//         0047795b     MOV        word ptr [ESI + 0x100],0x0
//         00477964     MOV        word ptr [ESI + 0x102],0x0
//         0047796d     JZ         LAB_00477982
//         0047796f     TEST       AX,AX
//         00477972     JLE        LAB_00477982
//                              Pnl_inp.cpp:548 (7)
//         00477974     MOV        word ptr [ESI + 0x1b4],AX
//                              Pnl_inp.cpp:549 (7)
//         0047797b     MOV        word ptr [ESI + 0x102],AX
//                               LAB_00477982                                                 XREF[2]:     0047796d(j), 00477972(j)
//                              Pnl_inp.cpp:552 (7)
//         00477982     MOV        this,ESI
//         00477984     CALL       TInputPanel::reformat                            void reformat(TInputPanel * this)
//                               LAB_00477989                                                 XREF[1]:     0047791b(j)
//                              Pnl_inp.cpp:554 (4)
//         00477989     POP        ESI
//         0047798a     RET        0x4
//         0047798d     ??         90h
//         0047798e     NOP
//         0047798f     NOP
    return;
}

void TInputPanel::set_text(char** param_1, short param_2) {
    /* TODO: Stub */
//                              void __thiscall set_text(TInputPanel * this, char * * param_1, short
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              char * *          Stack[0x4]:4   param_1
//              short             Stack[0x8]:2   param_2
//                               ?set_text@TInputPanel@@UAEXPAPADF@Z                          XREF[1]:     00571568(*)
//                               TInputPanel::set_text
//                              Pnl_inp.cpp:560 (3)
//         00477990     RET        0x8
//         00477993     ??         90h
//         00477994     NOP
//         00477995     NOP
//         00477996     NOP
//         00477997     NOP
//         00477998     NOP
//         00477999     NOP
//         0047799a     NOP
//         0047799b     NOP
//         0047799c     NOP
//         0047799d     NOP
//         0047799e     NOP
//         0047799f     NOP
    return;
}

char* TInputPanel::get_input_buffer() {
    /* TODO: Stub */
//                              char * __thiscall get_input_buffer(TInputPanel * this)
//              char *            EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?get_input_buffer@TInputPanel@@QAEPADXZ
//                               TInputPanel::get_input_buffer
//                              Pnl_inp.cpp:569 (6)
//         004779a0     MOV        EAX,dword ptr [ECX + this->input_buffer]
//                              Pnl_inp.cpp:571 (1)
//         004779a6     RET
//         004779a7     ??         90h
//         004779a8     NOP
//         004779a9     NOP
//         004779aa     NOP
//         004779ab     NOP
//         004779ac     NOP
//         004779ad     NOP
//         004779ae     NOP
//         004779af     NOP
    return 0;
}

int TInputPanel::append_character(long param_1) {
    /* TODO: Stub */
//                              int __thiscall append_character(TInputPanel * this, long param_1)
//              int               EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004779b0(R)
//                               ?append_character@TInputPanel@@IAEHJ@Z
//                               TInputPanel::append_character
//                              Pnl_inp.cpp:577 (24)
//         004779b0     MOV        EDX,dword ptr [ESP + param_1]
//         004779b4     MOV        AX,word ptr [ECX + this->input_len]
//         004779bb     PUSH       EDX
//         004779bc     MOV        word ptr [ECX + this->input_pos],AX
//         004779c3     CALL       TInputPanel::insert_character                    int insert_character(TInputPanel * this, long
//                              Pnl_inp.cpp:580 (3)
//         004779c8     RET        0x4
//         004779cb     ??         90h
//         004779cc     NOP
//         004779cd     NOP
//         004779ce     NOP
//         004779cf     NOP
    return 0;
}

int TInputPanel::insert_character(long param_1) {
    /* TODO: Stub */
//                              int __thiscall insert_character(TInputPanel * this, long param_1)
//              int               EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00477a71(*)
//                               ?insert_character@TInputPanel@@IAEHJ@Z                       XREF[3]:     char_action:00477174(c),
//                               TInputPanel::insert_character                                             key_down_action:004776ba(c),
//                                                                                                         append_character:004779c3(c)
//                              Pnl_inp.cpp:586 (3)
//         004779d0     PUSH       ESI
//         004779d1     MOV        ESI,this
//                              Pnl_inp.cpp:587 (16)
//         004779d3     MOV        AX,word ptr [ESI + 0x1ac]
//         004779da     CMP        AX,word ptr [ESI + 0x1ae]
//         004779e1     JL         LAB_00477a06
//                              Pnl_inp.cpp:589 (10)
//         004779e3     MOV        this,dword ptr [ESI + 0x198]
//         004779e9     TEST       this,this
//         004779eb     JZ         LAB_004779f8
//                              Pnl_inp.cpp:590 (5)
//         004779ed     CALL       TDigital::play                                   int play(TDigital * this)
//                              Pnl_inp.cpp:593 (2)
//         004779f2     XOR        EAX,EAX
//                              Pnl_inp.cpp:657 (4)
//         004779f4     POP        ESI
//         004779f5     RET        0x4
//                               LAB_004779f8                                                 XREF[1]:     004779eb(j)
//                              Pnl_inp.cpp:592 (8)
//         004779f8     PUSH       -0x1
//         004779fa     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
//                              Pnl_inp.cpp:593 (2)
//         00477a00     XOR        EAX,EAX
//                              Pnl_inp.cpp:657 (4)
//         00477a02     POP        ESI
//         00477a03     RET        0x4
//                               LAB_00477a06                                                 XREF[1]:     004779e1(j)
//                              Pnl_inp.cpp:613 (18)
//         00477a06     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00477a0c     PUSH       EDI
//         00477a0d     MOV        EDI,dword ptr [ESI + 0x1a4]
//         00477a13     PUSH       EBX
//         00477a14     CMP        EAX,EDI
//         00477a16     JNZ        LAB_00477a22
//                              Pnl_inp.cpp:615 (2)
//         00477a18     MOV        EBX,EDI
//                              Pnl_inp.cpp:616 (6)
//         00477a1a     MOV        EDI,dword ptr [ESI + 0x1a8]
//                              Pnl_inp.cpp:618 (2)
//         00477a20     JMP        LAB_00477a28
//                               LAB_00477a22                                                 XREF[1]:     00477a16(j)
//                              Pnl_inp.cpp:620 (6)
//         00477a22     MOV        EBX,dword ptr [ESI + 0x1a8]
//                               LAB_00477a28                                                 XREF[1]:     00477a20(j)
//                              Pnl_inp.cpp:625 (6)
//         00477a28     MOV        dword ptr [ESI + 0x1a0],EDI
//                              Pnl_inp.cpp:628 (3)
//         00477a2e     MOV        byte ptr [EDI],0x0
//                              Pnl_inp.cpp:634 (12)
//         00477a31     MOV        AX,word ptr [ESI + 0x1b4]
//         00477a38     TEST       AX,AX
//         00477a3b     JLE        LAB_00477a71
//                              Pnl_inp.cpp:636 (11)
//         00477a3d     MOVSX      this,AX
//         00477a40     PUSH       this
//         00477a41     PUSH       EBX
//         00477a42     PUSH       EDI
//         00477a43     CALL       __mbsncpy                                        undefined __mbsncpy()
//                              Pnl_inp.cpp:637 (22)
//         00477a48     MOVSX      EDX,word ptr [ESI + 0x1b4]
//         00477a4f     ADD        ESP,0xc
//         00477a52     PUSH       EDX
//         00477a53     PUSH       EBX
//         00477a54     CALL       __mbsninc                                        undefined __mbsninc()
//         00477a59     MOV        EBX,EAX
//         00477a5b     ADD        ESP,0x8
//                              Pnl_inp.cpp:638 (19)
//         00477a5e     MOVSX      EAX,word ptr [ESI + 0x1b4]
//         00477a65     PUSH       EAX
//         00477a66     PUSH       EDI
//         00477a67     CALL       __mbsninc                                        undefined __mbsninc()
//         00477a6c     ADD        ESP,0x8
//         00477a6f     MOV        EDI,EAX
//                               LAB_00477a71                                                 XREF[1]:     00477a3b(j)
//                              Pnl_inp.cpp:642 (16)
//         00477a71     LEA        this=>param_1,[ESP + 0x10]
//         00477a75     PUSH       0x1
//         00477a77     PUSH       this
//         00477a78     PUSH       EDI
//         00477a79     CALL       __mbsncpy                                        undefined __mbsncpy()
//         00477a7e     ADD        ESP,0xc
//                              Pnl_inp.cpp:643 (6)
//         00477a81     PUSH       EDI
//         00477a82     CALL       __mbsinc                                         undefined __mbsinc()
//                              Pnl_inp.cpp:646 (31)
//         00477a87     MOVSX      EDX,word ptr [ESI + 0x1ac]
//         00477a8e     MOVSX      this,word ptr [ESI + 0x1b4]
//         00477a95     SUB        EDX,this
//         00477a97     ADD        ESP,0x4
//         00477a9a     INC        EDX
//         00477a9b     PUSH       EDX
//         00477a9c     PUSH       EBX
//         00477a9d     PUSH       EAX
//         00477a9e     CALL       __mbsncpy                                        undefined __mbsncpy()
//         00477aa3     ADD        ESP,0xc
//                              Pnl_inp.cpp:648 (7)
//         00477aa6     INC        word ptr [ESI + 0x1ac]
//                              Pnl_inp.cpp:649 (7)
//         00477aad     INC        word ptr [ESI + 0x1b4]
//                              Pnl_inp.cpp:652 (7)
//         00477ab4     MOV        this,ESI
//         00477ab6     CALL       TInputPanel::reformat                            void reformat(TInputPanel * this)
//                              Pnl_inp.cpp:653 (7)
//         00477abb     MOV        this,ESI
//         00477abd     CALL       TInputPanel::calc_cur_line_col                   void calc_cur_line_col(TInputPanel * this)
//                              Pnl_inp.cpp:655 (34)
//         00477ac2     PUSH       0x28f
//         00477ac7     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00477acc     MOV        dword ptr [ESI + 0x194],0x1
//         00477ad6     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00477adb     ADD        ESP,0x8
//         00477ade     MOV        dword ptr [ESI + 0x190],EAX
//                              Pnl_inp.cpp:656 (7)
//         00477ae4     MOV        EAX,0x1
//         00477ae9     POP        EBX
//         00477aea     POP        EDI
//                              Pnl_inp.cpp:657 (4)
//         00477aeb     POP        ESI
//         00477aec     RET        0x4
//         00477aef     ??         90h
    return 0;
}

int TInputPanel::delete_character() {
    /* TODO: Stub */
//                              int __thiscall delete_character(TInputPanel * this)
//              int               EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00477b1e(W), 00477bf0(W), 00477c32(R)
//              int               Stack[-0x8]:4  move_back_one             XREF[5]:     00477b4d(W), 00477b85(W), 00477bce(R), 00477bdc(W),
//                                                                                     00477c27(R)
//              uchar *           Stack[-0xc]:4  cur_dest
//                               ?delete_character@TInputPanel@@IAEHXZ                        XREF[2]:     key_down_action:00477658(c),
//                               TInputPanel::delete_character                                             backspace_character:00477ca4(c)
//                              Pnl_inp.cpp:663 (6)
//         00477af0     SUB        ESP,0x8
//         00477af3     PUSH       ESI
//         00477af4     MOV        ESI,this
//                              Pnl_inp.cpp:664 (16)
//         00477af6     MOV        AX,word ptr [ESI + 0x1b4]
//         00477afd     CMP        AX,word ptr [ESI + 0x1ac]
//         00477b04     JL         LAB_00477b0d
//                              Pnl_inp.cpp:665 (2)
//         00477b06     XOR        EAX,EAX
//                              Pnl_inp.cpp:760 (5)
//         00477b08     POP        ESI
//         00477b09     ADD        ESP,0x8
//         00477b0c     RET
//                               LAB_00477b0d                                                 XREF[1]:     00477b04(j)
//                              Pnl_inp.cpp:684 (27)
//         00477b0d     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00477b13     PUSH       EDI
//         00477b14     MOV        EDI,dword ptr [ESI + 0x1a4]
//         00477b1a     PUSH       EBP
//         00477b1b     CMP        EAX,EDI
//         00477b1d     PUSH       EBX
//         00477b1e     MOV        dword ptr [ESP + local_4],0x0
//         00477b26     JNZ        LAB_00477b32
//                              Pnl_inp.cpp:686 (2)
//         00477b28     MOV        EBX,EDI
//                              Pnl_inp.cpp:687 (6)
//         00477b2a     MOV        EDI,dword ptr [ESI + 0x1a8]
//                              Pnl_inp.cpp:689 (2)
//         00477b30     JMP        LAB_00477b38
//                               LAB_00477b32                                                 XREF[1]:     00477b26(j)
//                              Pnl_inp.cpp:691 (6)
//         00477b32     MOV        EBX,dword ptr [ESI + 0x1a8]
//                               LAB_00477b38                                                 XREF[1]:     00477b30(j)
//                              Pnl_inp.cpp:696 (6)
//         00477b38     MOV        dword ptr [ESI + 0x1a0],EDI
//                              Pnl_inp.cpp:699 (3)
//         00477b3e     MOV        byte ptr [EDI],0x0
//                              Pnl_inp.cpp:705 (18)
//         00477b41     MOV        AX,word ptr [ESI + 0x1b4]
//         00477b48     MOV        EBP,EBX
//         00477b4a     TEST       AX,AX
//         00477b4d     MOV        dword ptr [ESP + move_back_one],EDI
//         00477b51     JLE        LAB_00477b89
//                              Pnl_inp.cpp:707 (11)
//         00477b53     MOVSX      this,AX
//         00477b56     PUSH       this
//         00477b57     PUSH       EBX
//         00477b58     PUSH       EDI
//         00477b59     CALL       __mbsncpy                                        undefined __mbsncpy()
//                              Pnl_inp.cpp:708 (22)
//         00477b5e     MOVSX      EDX,word ptr [ESI + 0x1b4]
//         00477b65     ADD        ESP,0xc
//         00477b68     PUSH       EDX
//         00477b69     PUSH       EBX
//         00477b6a     CALL       __mbsninc                                        undefined __mbsninc()
//         00477b6f     MOV        EBP,EAX
//         00477b71     ADD        ESP,0x8
//                              Pnl_inp.cpp:709 (21)
//         00477b74     MOVSX      EAX,word ptr [ESI + 0x1b4]
//         00477b7b     PUSH       EAX
//         00477b7c     PUSH       EDI
//         00477b7d     CALL       __mbsninc                                        undefined __mbsninc()
//         00477b82     ADD        ESP,0x8
//         00477b85     MOV        dword ptr [ESP + move_back_one],EAX
//                               LAB_00477b89                                                 XREF[1]:     00477b51(j)
//                              Pnl_inp.cpp:713 (7)
//         00477b89     MOV        AL,byte ptr [EBP]
//         00477b8c     CMP        AL,0xd
//         00477b8e     JNZ        LAB_00477bb5
//                              Pnl_inp.cpp:717 (6)
//         00477b90     PUSH       EBP
//         00477b91     CALL       __mbsinc                                         undefined __mbsinc()
//                              Pnl_inp.cpp:719 (15)
//         00477b96     MOV        this,byte ptr [EAX]
//         00477b98     ADD        ESP,0x4
//         00477b9b     CMP        this,0xa
//         00477b9e     MOV        EDI,0x1
//         00477ba3     JNZ        LAB_00477c15
//                              Pnl_inp.cpp:721 (9)
//         00477ba5     PUSH       EAX
//         00477ba6     CALL       __mbsinc                                         undefined __mbsinc()
//         00477bab     ADD        ESP,0x4
//                              Pnl_inp.cpp:722 (5)
//         00477bae     MOV        EDI,0x2
//                              Pnl_inp.cpp:725 (10)
//         00477bb3     JMP        LAB_00477c15
//                               LAB_00477bb5                                                 XREF[1]:     00477b8e(j)
//         00477bb5     CMP        AL,0xa
//         00477bb7     JNZ        LAB_00477c07
//         00477bb9     CMP        EBP,EBX
//         00477bbb     JBE        LAB_00477c07
//                              Pnl_inp.cpp:728 (12)
//         00477bbd     PUSH       EBP
//         00477bbe     PUSH       EBX
//         00477bbf     CALL       __mbsdec                                         undefined __mbsdec()
//         00477bc4     MOV        EBX,EAX
//         00477bc6     ADD        ESP,0x8
//                              Pnl_inp.cpp:729 (5)
//         00477bc9     CMP        byte ptr [EBX],0xd
//         00477bcc     JNZ        LAB_00477bfa
//                              Pnl_inp.cpp:731 (18)
//         00477bce     MOV        this,dword ptr [ESP + move_back_one]
//         00477bd2     PUSH       this
//         00477bd3     PUSH       EDI
//         00477bd4     CALL       __mbsdec                                         undefined __mbsdec()
//         00477bd9     ADD        ESP,0x8
//         00477bdc     MOV        dword ptr [ESP + move_back_one],EAX
//                              Pnl_inp.cpp:732 (11)
//         00477be0     PUSH       0x2
//         00477be2     PUSH       EBX
//         00477be3     CALL       __mbsninc                                        undefined __mbsninc()
//         00477be8     ADD        ESP,0x8
//                              Pnl_inp.cpp:733 (5)
//         00477beb     MOV        EDI,0x2
//                              Pnl_inp.cpp:734 (8)
//         00477bf0     MOV        dword ptr [ESP + local_4],0x1
//                              Pnl_inp.cpp:736 (2)
//         00477bf8     JMP        LAB_00477c15
//                               LAB_00477bfa                                                 XREF[1]:     00477bcc(j)
//                              Pnl_inp.cpp:738 (11)
//         00477bfa     PUSH       0x2
//         00477bfc     PUSH       EBX
//         00477bfd     CALL       __mbsninc                                        undefined __mbsninc()
//         00477c02     ADD        ESP,0x8
//                              Pnl_inp.cpp:742 (2)
//         00477c05     JMP        LAB_00477c10
//                               LAB_00477c07                                                 XREF[2]:     00477bb7(j), 00477bbb(j)
//                              Pnl_inp.cpp:744 (9)
//         00477c07     PUSH       EBP
//         00477c08     CALL       __mbsinc                                         undefined __mbsinc()
//         00477c0d     ADD        ESP,0x4
//                               LAB_00477c10                                                 XREF[1]:     00477c05(j)
//                              Pnl_inp.cpp:745 (5)
//         00477c10     MOV        EDI,0x1
//                               LAB_00477c15                                                 XREF[3]:     00477ba3(j), 00477bb3(j),
//                                                                                                         00477bf8(j)
//                              Pnl_inp.cpp:749 (29)
//         00477c15     MOVSX      EDX,word ptr [ESI + 0x1ac]
//         00477c1c     MOVSX      this,word ptr [ESI + 0x1b4]
//         00477c23     SUB        EDX,this
//         00477c25     INC        EDX
//         00477c26     PUSH       EDX
//         00477c27     MOV        EDX,dword ptr [ESP + move_back_one]
//         00477c2b     PUSH       EAX
//         00477c2c     PUSH       EDX
//         00477c2d     CALL       __mbsncpy                                        undefined __mbsncpy()
//                              Pnl_inp.cpp:752 (11)
//         00477c32     MOV        EAX,dword ptr [ESP + local_4]
//         00477c36     ADD        ESP,0xc
//         00477c39     TEST       EAX,EAX
//         00477c3b     JZ         LAB_00477c44
//                              Pnl_inp.cpp:753 (7)
//         00477c3d     DEC        word ptr [ESI + 0x1b4]
//                               LAB_00477c44                                                 XREF[1]:     00477c3b(j)
//                              Pnl_inp.cpp:754 (7)
//         00477c44     SUB        word ptr [ESI + 0x1ac],DI
//                              Pnl_inp.cpp:755 (7)
//         00477c4b     MOV        this,ESI
//         00477c4d     CALL       TInputPanel::reformat                            void reformat(TInputPanel * this)
//                              Pnl_inp.cpp:756 (7)
//         00477c52     MOV        this,ESI
//         00477c54     CALL       TInputPanel::calc_cur_line_col                   void calc_cur_line_col(TInputPanel * this)
//                              Pnl_inp.cpp:758 (34)
//         00477c59     PUSH       0x2f6
//         00477c5e     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00477c63     MOV        dword ptr [ESI + 0x194],0x1
//         00477c6d     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00477c72     ADD        ESP,0x8
//         00477c75     MOV        dword ptr [ESI + 0x190],EAX
//                              Pnl_inp.cpp:759 (8)
//         00477c7b     MOV        EAX,0x1
//         00477c80     POP        EBX
//         00477c81     POP        EBP
//         00477c82     POP        EDI
//                              Pnl_inp.cpp:760 (5)
//         00477c83     POP        ESI
//         00477c84     ADD        ESP,0x8
//         00477c87     RET
//         00477c88     ??         90h
//         00477c89     NOP
//         00477c8a     NOP
//         00477c8b     NOP
//         00477c8c     NOP
//         00477c8d     NOP
//         00477c8e     NOP
//         00477c8f     NOP
    return 0;
}

int TInputPanel::backspace_character() {
    /* TODO: Stub */
//                              int __thiscall backspace_character(TInputPanel * this)
//              int               EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?backspace_character@TInputPanel@@IAEHXZ                     XREF[1]:     key_down_action:0047769e(c)
//                               TInputPanel::backspace_character
//                              Pnl_inp.cpp:766 (12)
//         00477c90     MOV        AX,word ptr [ECX + this->input_pos]
//         00477c97     TEST       AX,AX
//         00477c9a     JLE        LAB_00477ca9
//                              Pnl_inp.cpp:769 (8)
//         00477c9c     DEC        EAX
//         00477c9d     MOV        word ptr [ECX + this->input_pos],AX
//                              Pnl_inp.cpp:770 (5)
//         00477ca4     JMP        TInputPanel::delete_character                    int delete_character(TInputPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_00477ca9                                                 XREF[1]:     00477c9a(j)
//                              Pnl_inp.cpp:773 (2)
//         00477ca9     XOR        EAX,EAX
//                              Pnl_inp.cpp:774 (1)
//         00477cab     RET
//         00477cac     ??         90h
//         00477cad     NOP
//         00477cae     NOP
//         00477caf     NOP
    return 0;
}

int TInputPanel::paste() {
    /* TODO: Stub */
//                              int __thiscall paste(TInputPanel * this)
//              int               EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              char[4096]        Stack[-0x100   new_str                   XREF[0,1]:   00477cc4(W)
//              void *            Stack[-0x100   data_handle
//                               ?paste@TInputPanel@@IAEHXZ                                   XREF[1]:     key_down_action:00477713(c)
//                               TInputPanel::paste
//                              Pnl_inp.cpp:780 (14)
//         00477cb0     MOV        EAX,0x1004
//         00477cb5     CALL       __alloca_probe                                   undefined __alloca_probe()
//         00477cba     PUSH       EBX
//         00477cbb     PUSH       EBP
//         00477cbc     PUSH       ESI
//         00477cbd     PUSH       EDI
//                              Pnl_inp.cpp:787 (4)
//         00477cbe     XOR        EBX,EBX
//         00477cc0     MOV        ESI,this
//                              Pnl_inp.cpp:790 (16)
//         00477cc2     PUSH       0x1
//         00477cc4     MOV        byte ptr [ESP + new_str[4]],BL
//         00477cc8     CALL       dword ptr [->USER32.DLL::IsClipboardFormatAvai   = 0048b0ec
//         00477cce     TEST       EAX,EAX
//         00477cd0     JNZ        LAB_00477cdd
//                              Pnl_inp.cpp:868 (11)
//         00477cd2     POP        EDI
//         00477cd3     POP        ESI
//         00477cd4     POP        EBP
//         00477cd5     POP        EBX
//         00477cd6     ADD        ESP,0x1004
//         00477cdc     RET
//                               LAB_00477cdd                                                 XREF[1]:     00477cd0(j)
//                              Pnl_inp.cpp:792 (17)
//         00477cdd     MOV        EAX,dword ptr [ESI + 0x20]
//         00477ce0     MOV        this,dword ptr [EAX + 0x4]
//         00477ce3     PUSH       this
//         00477ce4     CALL       dword ptr [->USER32.DLL::OpenClipboard]          = 0048b0dc
//         00477cea     TEST       EAX,EAX
//         00477cec     JNZ        LAB_00477cf9
//                              Pnl_inp.cpp:868 (11)
//         00477cee     POP        EDI
//         00477cef     POP        ESI
//         00477cf0     POP        EBP
//         00477cf1     POP        EBX
//         00477cf2     ADD        ESP,0x1004
//         00477cf8     RET
//                               LAB_00477cf9                                                 XREF[1]:     00477cec(j)
//                              Pnl_inp.cpp:795 (8)
//         00477cf9     PUSH       0x1
//         00477cfb     CALL       dword ptr [->USER32.DLL::GetClipboardData]       = 0048b0c8
//                              Pnl_inp.cpp:796 (8)
//         00477d01     TEST       EAX,EAX
//         00477d03     MOV        dword ptr [ESP + 0x10],EAX
//         00477d07     JZ         LAB_00477d55
//                              Pnl_inp.cpp:798 (9)
//         00477d09     PUSH       EAX
//         00477d0a     CALL       dword ptr [->KERNEL32.DLL::GlobalLock]           = 0048aade
//         00477d10     MOV        EBP,EAX
//                              Pnl_inp.cpp:799 (4)
//         00477d12     TEST       EBP,EBP
//         00477d14     JZ         LAB_00477d55
//                              Pnl_inp.cpp:801 (11)
//         00477d16     PUSH       EBP
//         00477d17     CALL       __mbslen                                         undefined __mbslen()
//         00477d1c     MOV        EBX,EAX
//         00477d1e     ADD        ESP,0x4
//                              Pnl_inp.cpp:802 (8)
//         00477d21     CMP        EBX,0xfff
//         00477d27     JLE        LAB_00477d2e
//                              Pnl_inp.cpp:803 (5)
//         00477d29     MOV        EBX,0xfff
//                               LAB_00477d2e                                                 XREF[1]:     00477d27(j)
//                              Pnl_inp.cpp:804 (11)
//         00477d2e     MOV        this,0x400
//         00477d33     XOR        EAX,EAX
//         00477d35     LEA        EDI,[ESP + 0x14]
//                              Pnl_inp.cpp:805 (14)
//         00477d39     PUSH       EBX
//         00477d3a     LEA        EDX,[ESP + 0x18]
//         00477d3e     PUSH       EBP=>DAT_fffffff8
//         00477d3f     STOSD.REP  ES:EDI
//         00477d41     PUSH       EDX=>DAT_fffffff4
//         00477d42     CALL       __mbsncpy                                        undefined __mbsncpy()
//                              Pnl_inp.cpp:806 (14)
//         00477d47     MOV        EAX,dword ptr [ESP + 0x1c]
//         00477d4b     ADD        ESP,0xc
//         00477d4e     PUSH       EAX
//         00477d4f     CALL       dword ptr [->KERNEL32.DLL::GlobalUnlock]         = 0048aafc
//                               LAB_00477d55                                                 XREF[2]:     00477d07(j), 00477d14(j)
//                              Pnl_inp.cpp:809 (6)
//         00477d55     CALL       dword ptr [->USER32.DLL::CloseClipboard]         = 0048b0b6
//                              Pnl_inp.cpp:812 (22)
//         00477d5b     MOVSX      this,word ptr [ESI + 0x1ac]
//         00477d62     MOVSX      EAX,word ptr [ESI + 0x1ae]
//         00477d69     MOV        EDX,EBX
//         00477d6b     ADD        EDX,this
//         00477d6d     CMP        EDX,EAX
//         00477d6f     JL         LAB_00477da4
//                              Pnl_inp.cpp:814 (10)
//         00477d71     MOV        ESI,dword ptr [ESI + 0x198]
//         00477d77     TEST       ESI,ESI
//         00477d79     JZ         LAB_00477d8f
//                              Pnl_inp.cpp:815 (7)
//         00477d7b     MOV        this,ESI
//         00477d7d     CALL       TDigital::play                                   int play(TDigital * this)
//                              Pnl_inp.cpp:818 (2)
//         00477d82     XOR        EAX,EAX
//                              Pnl_inp.cpp:868 (11)
//         00477d84     POP        EDI
//         00477d85     POP        ESI
//         00477d86     POP        EBP
//         00477d87     POP        EBX
//         00477d88     ADD        ESP,0x1004
//         00477d8e     RET
//                               LAB_00477d8f                                                 XREF[1]:     00477d79(j)
//                              Pnl_inp.cpp:817 (8)
//         00477d8f     PUSH       -0x1
//         00477d91     CALL       dword ptr [->USER32.DLL::MessageBeep]            = 0048b05a
//                              Pnl_inp.cpp:818 (2)
//         00477d97     XOR        EAX,EAX
//                              Pnl_inp.cpp:868 (11)
//         00477d99     POP        EDI
//         00477d9a     POP        ESI
//         00477d9b     POP        EBP
//         00477d9c     POP        EBX
//         00477d9d     ADD        ESP,0x1004
//         00477da3     RET
//                               LAB_00477da4                                                 XREF[1]:     00477d6f(j)
//                              Pnl_inp.cpp:827 (16)
//         00477da4     MOV        EDI,dword ptr [ESI + 0x1a4]
//         00477daa     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00477db0     CMP        EAX,EDI
//         00477db2     JNZ        LAB_00477dbe
//                              Pnl_inp.cpp:829 (2)
//         00477db4     MOV        EBP,EDI
//                              Pnl_inp.cpp:830 (6)
//         00477db6     MOV        EDI,dword ptr [ESI + 0x1a8]
//                              Pnl_inp.cpp:832 (2)
//         00477dbc     JMP        LAB_00477dc4
//                               LAB_00477dbe                                                 XREF[1]:     00477db2(j)
//                              Pnl_inp.cpp:834 (6)
//         00477dbe     MOV        EBP,dword ptr [ESI + 0x1a8]
//                               LAB_00477dc4                                                 XREF[1]:     00477dbc(j)
//                              Pnl_inp.cpp:839 (6)
//         00477dc4     MOV        dword ptr [ESI + 0x1a0],EDI
//                              Pnl_inp.cpp:842 (3)
//         00477dca     MOV        byte ptr [EDI],0x0
//                              Pnl_inp.cpp:848 (15)
//         00477dcd     MOVSX      this,word ptr [ESI + 0x1b4]
//         00477dd4     PUSH       this
//         00477dd5     PUSH       EBP=>DAT_fffffff8
//         00477dd6     PUSH       EDI=>DAT_fffffff4
//         00477dd7     CALL       __mbsncpy                                        undefined __mbsncpy()
//                              Pnl_inp.cpp:849 (22)
//         00477ddc     MOVSX      EDX,word ptr [ESI + 0x1b4]
//         00477de3     ADD        ESP,0xc
//         00477de6     PUSH       EDX
//         00477de7     PUSH       EBP=>DAT_fffffff8
//         00477de8     CALL       __mbsninc                                        undefined __mbsninc()
//         00477ded     MOV        EBP,EAX
//         00477def     ADD        ESP,0x8
//                              Pnl_inp.cpp:850 (17)
//         00477df2     MOVSX      EAX,word ptr [ESI + 0x1b4]
//         00477df9     PUSH       EAX
//         00477dfa     PUSH       EDI=>DAT_fffffff8
//         00477dfb     CALL       __mbsninc                                        undefined __mbsninc()
//         00477e00     ADD        ESP,0x8
//                              Pnl_inp.cpp:853 (17)
//         00477e03     LEA        this,[ESP + 0x14]
//         00477e07     MOV        EDI,EAX
//         00477e09     PUSH       EBX
//         00477e0a     PUSH       this=>DAT_fffffff8
//         00477e0b     PUSH       EDI=>DAT_fffffff4
//         00477e0c     CALL       __mbsncpy                                        undefined __mbsncpy()
//         00477e11     ADD        ESP,0xc
//                              Pnl_inp.cpp:854 (7)
//         00477e14     PUSH       EBX
//         00477e15     PUSH       EDI=>DAT_fffffff8
//         00477e16     CALL       __mbsninc                                        undefined __mbsninc()
//                              Pnl_inp.cpp:857 (28)
//         00477e1b     MOVSX      EDX,word ptr [ESI + 0x1b4]
//         00477e22     MOVSX      this,word ptr [ESI + 0x1ac]
//         00477e29     SUB        this,EDX
//         00477e2b     ADD        ESP,0x8
//         00477e2e     INC        this
//         00477e2f     PUSH       this
//         00477e30     PUSH       EBP=>DAT_fffffff8
//         00477e31     PUSH       EAX=>DAT_fffffff4
//         00477e32     CALL       __mbsncpy                                        undefined __mbsncpy()
//                              Pnl_inp.cpp:859 (7)
//         00477e37     ADD        word ptr [ESI + 0x1ac],BX
//                              Pnl_inp.cpp:860 (10)
//         00477e3e     ADD        word ptr [ESI + 0x1b4],BX
//         00477e45     ADD        ESP,0xc
//                              Pnl_inp.cpp:863 (7)
//         00477e48     MOV        this,ESI
//         00477e4a     CALL       TInputPanel::reformat                            void reformat(TInputPanel * this)
//                              Pnl_inp.cpp:864 (7)
//         00477e4f     MOV        this,ESI
//         00477e51     CALL       TInputPanel::calc_cur_line_col                   void calc_cur_line_col(TInputPanel * this)
//                              Pnl_inp.cpp:866 (34)
//         00477e56     PUSH       0x362
//         00477e5b     PUSH       s_C:\msdev\work\age1_x1\Pnl_inp.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_inp.cpp"
//         00477e60     MOV        dword ptr [ESI + 0x194],0x1
//         00477e6a     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00477e6f     ADD        ESP,0x8
//         00477e72     MOV        dword ptr [ESI + 0x190],EAX
//                              Pnl_inp.cpp:867 (5)
//         00477e78     MOV        EAX,0x1
//                              Pnl_inp.cpp:868 (11)
//         00477e7d     POP        EDI
//         00477e7e     POP        ESI
//         00477e7f     POP        EBP
//         00477e80     POP        EBX
//         00477e81     ADD        ESP,0x1004
//         00477e87     RET
//         00477e88     ??         90h
//         00477e89     NOP
//         00477e8a     NOP
//         00477e8b     NOP
//         00477e8c     NOP
//         00477e8d     NOP
//         00477e8e     NOP
//         00477e8f     NOP
    return 0;
}

void TInputPanel::reformat() {
    /* TODO: Stub */
//                              void __thiscall reformat(TInputPanel * this)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?reformat@TInputPanel@@IAEXXZ                                XREF[5]:     setup:00476ed0(c),
//                               TInputPanel::reformat                                                     set_text:00477984(c),
//                                                                                                         insert_character:00477ab6(c),
//                                                                                                         delete_character:00477c4d(c),
//                                                                                                         paste:00477e4a(c)
//                              Pnl_inp.cpp:874 (5)
//         00477e90     PUSH       EBX
//         00477e91     PUSH       ESI
//         00477e92     MOV        ESI,this
//         00477e94     PUSH       EDI
//                              Pnl_inp.cpp:881 (26)
//         00477e95     MOV        EAX,dword ptr [ESI + 0x1a0]
//         00477e9b     MOV        BX,word ptr [ESI + 0xfc]
//         00477ea2     MOV        DI,word ptr [ESI + 0x100]
//         00477ea9     PUSH       EAX
//         00477eaa     CALL       TTextPanel::set_text                             void set_text(TTextPanel * this, char * param
//                              Pnl_inp.cpp:883 (12)
//         00477eaf     MOV        AX,word ptr [ESI + 0xf8]
//         00477eb6     CMP        DI,AX
//         00477eb9     JL         LAB_00477ebe
//                              Pnl_inp.cpp:884 (3)
//         00477ebb     LEA        EDI,[EAX + -0x1]
//                               LAB_00477ebe                                                 XREF[1]:     00477eb9(j)
//                              Pnl_inp.cpp:887 (12)
//         00477ebe     CMP        BX,AX
//         00477ec1     MOV        word ptr [ESI + 0x100],DI
//         00477ec8     JL         LAB_00477ed2
//                              Pnl_inp.cpp:888 (8)
//         00477eca     DEC        EAX
//         00477ecb     MOV        word ptr [ESI + 0xfc],AX
//                               LAB_00477ed2                                                 XREF[1]:     00477ec8(j)
//                              Pnl_inp.cpp:889 (12)
//         00477ed2     PUSH       0x1
//         00477ed4     PUSH       EBX
//         00477ed5     PUSH       0x1
//         00477ed7     MOV        this,ESI
//         00477ed9     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_inp.cpp:891 (9)
//         00477ede     MOV        EDX,dword ptr [ESI]
//         00477ee0     PUSH       0x1
//         00477ee2     MOV        this,ESI
//         00477ee4     CALL       dword ptr [EDX + 0x20]
//                              Pnl_inp.cpp:892 (4)
//         00477ee7     POP        EDI
//         00477ee8     POP        ESI
//         00477ee9     POP        EBX
//         00477eea     RET
//         00477eeb     ??         90h
//         00477eec     NOP
//         00477eed     NOP
//         00477eee     NOP
//         00477eef     NOP
    return;
}

void TInputPanel::calc_input_pos() {
    /* TODO: Stub */
//                              void __thiscall calc_input_pos(TInputPanel * this)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?calc_input_pos@TInputPanel@@IAEXXZ                          XREF[5]:     key_down_action:004772cc(c),
//                               TInputPanel::calc_input_pos                                               key_down_action:0047737b(c),
//                                                                                                         key_down_action:00477436(c),
//                                                                                                         key_down_action:0047751a(c),
//                                                                                                         key_down_action:0047763e(c)
//                              Pnl_inp.cpp:900 (5)
//         00477ef0     PUSH       EBX
//         00477ef1     PUSH       ESI
//         00477ef2     MOV        ESI,this
//         00477ef4     PUSH       EDI
//                              Pnl_inp.cpp:906 (2)
//         00477ef5     XOR        EBX,EBX
//                              Pnl_inp.cpp:907 (19)
//         00477ef7     MOV        EDI,dword ptr [ESI + 0xf4]
//         00477efd     MOV        word ptr [ESI + 0x1b4],0x0
//         00477f06     TEST       EDI,EDI
//         00477f08     JZ         LAB_00477f2d
//                               LAB_00477f0a                                                 XREF[1]:     00477f2b(j)
//                              Pnl_inp.cpp:909 (9)
//         00477f0a     CMP        BX,word ptr [ESI + 0x100]
//         00477f11     JGE        LAB_00477f2d
//                              Pnl_inp.cpp:911 (21)
//         00477f13     MOV        EAX,dword ptr [EDI]
//         00477f15     PUSH       EAX
//         00477f16     CALL       __mbslen                                         undefined __mbslen()
//         00477f1b     ADD        word ptr [ESI + 0x1b4],AX
//         00477f22     MOV        EDI,dword ptr [EDI + 0xc]
//         00477f25     ADD        ESP,0x4
//                              Pnl_inp.cpp:912 (5)
//         00477f28     INC        EBX
//         00477f29     TEST       EDI,EDI
//         00477f2b     JNZ        LAB_00477f0a
//                               LAB_00477f2d                                                 XREF[2]:     00477f08(j), 00477f11(j)
//                              Pnl_inp.cpp:915 (21)
//         00477f2d     MOV        AX,word ptr [ESI + 0x102]
//         00477f34     ADD        word ptr [ESI + 0x1b4],AX
//         00477f3b     MOV        this,word ptr [ESI + 0x1b4]
//                              Pnl_inp.cpp:919 (26)
//         00477f42     TEST       AX,AX
//         00477f45     JLE        LAB_00477f6c
//         00477f47     TEST       this,this
//         00477f4a     JLE        LAB_00477f6c
//         00477f4c     MOV        EDI,dword ptr [ESI + 0x1a0]
//         00477f52     MOVSX      EDX,this
//         00477f55     CMP        byte ptr [EDI + EDX*0x1 + -0x1],0xa
//         00477f5a     JNZ        LAB_00477f6c
//                              Pnl_inp.cpp:921 (1)
//         00477f5c     DEC        this
//                              Pnl_inp.cpp:922 (15)
//         00477f5d     DEC        EAX
//         00477f5e     MOV        word ptr [ESI + 0x1b4],this
//         00477f65     MOV        word ptr [ESI + 0x102],AX
//                               LAB_00477f6c                                                 XREF[3]:     00477f45(j), 00477f4a(j),
//                                                                                                         00477f5a(j)
//                              Pnl_inp.cpp:924 (40)
//         00477f6c     MOV        this,word ptr [ESI + 0x102]
//         00477f73     TEST       this,this
//         00477f76     JLE        LAB_00477fa4
//         00477f78     MOV        AX,word ptr [ESI + 0x1b4]
//         00477f7f     TEST       AX,AX
//         00477f82     JLE        LAB_00477fa4
//         00477f84     MOV        EDI,dword ptr [ESI + 0x1a0]
//         00477f8a     MOVSX      EDX,AX
//         00477f8d     CMP        byte ptr [EDI + EDX*0x1 + -0x1],0xd
//         00477f92     JNZ        LAB_00477fa4
//                              Pnl_inp.cpp:926 (1)
//         00477f94     DEC        EAX
//                              Pnl_inp.cpp:927 (15)
//         00477f95     DEC        this
//         00477f96     MOV        word ptr [ESI + 0x1b4],AX
//         00477f9d     MOV        word ptr [ESI + 0x102],this
//                               LAB_00477fa4                                                 XREF[3]:     00477f76(j), 00477f82(j),
//                                                                                                         00477f92(j)
//                              Pnl_inp.cpp:930 (16)
//         00477fa4     MOV        AX,word ptr [ESI + 0x100]
//         00477fab     CMP        AX,word ptr [ESI + 0xfc]
//         00477fb2     JGE        LAB_00477fd1
//                               LAB_00477fb4                                                 XREF[1]:     00477fcf(j)
//                              Pnl_inp.cpp:931 (29)
//         00477fb4     PUSH       0x1
//         00477fb6     PUSH       0x1
//         00477fb8     PUSH       0x3
//         00477fba     MOV        this,ESI
//         00477fbc     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//         00477fc1     MOV        this,word ptr [ESI + 0x100]
//         00477fc8     CMP        this,word ptr [ESI + 0xfc]
//         00477fcf     JL         LAB_00477fb4
//                               LAB_00477fd1                                                 XREF[1]:     00477fb2(j)
//                              Pnl_inp.cpp:933 (16)
//         00477fd1     MOV        DX,word ptr [ESI + 0x100]
//         00477fd8     CMP        DX,word ptr [ESI + 0xfe]
//         00477fdf     JLE        LAB_00477ffe
//                               LAB_00477fe1                                                 XREF[1]:     00477ffc(j)
//                              Pnl_inp.cpp:934 (29)
//         00477fe1     PUSH       0x1
//         00477fe3     PUSH       0x1
//         00477fe5     PUSH       0x2
//         00477fe7     MOV        this,ESI
//         00477fe9     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//         00477fee     MOV        AX,word ptr [ESI + 0x100]
//         00477ff5     CMP        AX,word ptr [ESI + 0xfe]
//         00477ffc     JG         LAB_00477fe1
//                               LAB_00477ffe                                                 XREF[1]:     00477fdf(j)
//                              Pnl_inp.cpp:935 (4)
//         00477ffe     POP        EDI
//         00477fff     POP        ESI
//         00478000     POP        EBX
//         00478001     RET
//         00478002     ??         90h
//         00478003     NOP
//         00478004     NOP
//         00478005     NOP
//         00478006     NOP
//         00478007     NOP
//         00478008     NOP
//         00478009     NOP
//         0047800a     NOP
//         0047800b     NOP
//         0047800c     NOP
//         0047800d     NOP
//         0047800e     NOP
//         0047800f     NOP
    return;
}

void TInputPanel::calc_cur_line_col() {
    /* TODO: Stub */
//                              void __thiscall calc_cur_line_col(TInputPanel * this)
//              void              <VOID>         <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?calc_cur_line_col@TInputPanel@@IAEXXZ                       XREF[3]:     insert_character:00477abd(c),
//                               TInputPanel::calc_cur_line_col                                            delete_character:00477c54(c),
//                                                                                                         paste:00477e51(c)
//                              Pnl_inp.cpp:943 (5)
//         00478010     PUSH       EBX
//         00478011     PUSH       ESI
//         00478012     MOV        ESI,this
//         00478014     PUSH       EDI
//                              Pnl_inp.cpp:951 (2)
//         00478015     XOR        EBX,EBX
//                              Pnl_inp.cpp:952 (28)
//         00478017     MOV        EDI,dword ptr [ESI + 0xf4]
//         0047801d     MOV        word ptr [ESI + 0x100],0x0
//         00478026     TEST       EDI,EDI
//         00478028     MOV        word ptr [ESI + 0x102],0x0
//         00478031     JZ         LAB_00478074
//                               LAB_00478033                                                 XREF[1]:     00478072(j)
//                              Pnl_inp.cpp:954 (19)
//         00478033     MOVSX      EAX,word ptr [ESI + 0xf8]
//         0047803a     MOVSX      this,word ptr [ESI + 0x100]
//         00478041     DEC        EAX
//         00478042     CMP        this,EAX
//         00478044     JZ         LAB_00478074
//                              Pnl_inp.cpp:956 (8)
//         00478046     MOV        EDX,dword ptr [EDI]
//         00478048     PUSH       EDX
//         00478049     CALL       __mbslen                                         undefined __mbslen()
//                              Pnl_inp.cpp:959 (22)
//         0047804e     MOVSX      this,BX
//         00478051     MOVSX      EDX,AX
//         00478054     ADD        this,EDX
//         00478056     ADD        ESP,0x4
//         00478059     MOVSX      EDX,word ptr [ESI + 0x1b4]
//         00478060     CMP        this,EDX
//         00478062     JG         LAB_00478074
//                              Pnl_inp.cpp:961 (2)
//         00478064     ADD        EBX,EAX
//                              Pnl_inp.cpp:962 (14)
//         00478066     INC        word ptr [ESI + 0x100]
//         0047806d     MOV        EDI,dword ptr [EDI + 0xc]
//         00478070     TEST       EDI,EDI
//         00478072     JNZ        LAB_00478033
//                               LAB_00478074                                                 XREF[3]:     00478031(j), 00478044(j),
//                                                                                                         00478062(j)
//                              Pnl_inp.cpp:965 (11)
//         00478074     MOV        this,word ptr [ESI + 0x1b4]
//         0047807b     MOV        EAX,this
//         0047807d     SUB        EAX,EBX
//                              Pnl_inp.cpp:969 (33)
//         0047807f     TEST       AX,AX
//         00478082     MOV        word ptr [ESI + 0x102],AX
//         00478089     JLE        LAB_004780af
//         0047808b     TEST       this,this
//         0047808e     JLE        LAB_004780af
//         00478090     MOV        EDX,dword ptr [ESI + 0x1a0]
//         00478096     MOVSX      EAX,this
//         00478099     CMP        byte ptr [EDX + EAX*0x1 + -0x1],0xa
//         0047809e     JNZ        LAB_004780af
//                              Pnl_inp.cpp:971 (1)
//         004780a0     DEC        this
//                              Pnl_inp.cpp:972 (14)
//         004780a1     DEC        word ptr [ESI + 0x102]
//         004780a8     MOV        word ptr [ESI + 0x1b4],this
//                               LAB_004780af                                                 XREF[3]:     00478089(j), 0047808e(j),
//                                                                                                         0047809e(j)
//                              Pnl_inp.cpp:974 (38)
//         004780af     CMP        word ptr [ESI + 0x102],0x0
//         004780b7     JLE        LAB_004780e4
//         004780b9     MOV        AX,word ptr [ESI + 0x1b4]
//         004780c0     TEST       AX,AX
//         004780c3     JLE        LAB_004780e4
//         004780c5     MOV        EDX,dword ptr [ESI + 0x1a0]
//         004780cb     MOVSX      this,AX
//         004780ce     CMP        byte ptr [EDX + this->_padding_*0x1 + -0x1],0xd
//         004780d3     JNZ        LAB_004780e4
//                              Pnl_inp.cpp:976 (1)
//         004780d5     DEC        EAX
//                              Pnl_inp.cpp:977 (14)
//         004780d6     DEC        word ptr [ESI + 0x102]
//         004780dd     MOV        word ptr [ESI + 0x1b4],AX
//                               LAB_004780e4                                                 XREF[3]:     004780b7(j), 004780c3(j),
//                                                                                                         004780d3(j)
//                              Pnl_inp.cpp:980 (16)
//         004780e4     MOV        AX,word ptr [ESI + 0x100]
//         004780eb     CMP        AX,word ptr [ESI + 0xfc]
//         004780f2     JGE        LAB_00478111
//                               LAB_004780f4                                                 XREF[1]:     0047810f(j)
//                              Pnl_inp.cpp:981 (29)
//         004780f4     PUSH       0x1
//         004780f6     PUSH       0x1
//         004780f8     PUSH       0x3
//         004780fa     MOV        this,ESI
//         004780fc     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//         00478101     MOV        this,word ptr [ESI + 0x100]
//         00478108     CMP        this,word ptr [ESI + 0xfc]
//         0047810f     JL         LAB_004780f4
//                               LAB_00478111                                                 XREF[1]:     004780f2(j)
//                              Pnl_inp.cpp:983 (16)
//         00478111     MOV        DX,word ptr [ESI + 0x100]
//         00478118     CMP        DX,word ptr [ESI + 0xfe]
//         0047811f     JLE        LAB_0047813e
//                               LAB_00478121                                                 XREF[1]:     0047813c(j)
//                              Pnl_inp.cpp:984 (29)
//         00478121     PUSH       0x1
//         00478123     PUSH       0x1
//         00478125     PUSH       0x2
//         00478127     MOV        this,ESI
//         00478129     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//         0047812e     MOV        AX,word ptr [ESI + 0x100]
//         00478135     CMP        AX,word ptr [ESI + 0xfe]
//         0047813c     JG         LAB_00478121
//                               LAB_0047813e                                                 XREF[1]:     0047811f(j)
//                              Pnl_inp.cpp:985 (4)
//         0047813e     POP        EDI
//         0047813f     POP        ESI
//         00478140     POP        EBX
//         00478141     RET
//         00478142     ??         90h
//         00478143     NOP
//         00478144     NOP
//         00478145     NOP
//         00478146     NOP
//         00478147     NOP
//         00478148     NOP
//         00478149     NOP
//         0047814a     NOP
//         0047814b     NOP
//         0047814c     NOP
//         0047814d     NOP
//         0047814e     NOP
//         0047814f     NOP
    return;
}

int TInputPanel::is_blank() {
    /* TODO: Stub */
//                              int __thiscall is_blank(TInputPanel * this)
//              int               EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//                               ?is_blank@TInputPanel@@QAEHXZ
//                               TInputPanel::is_blank
//                              Pnl_inp.cpp:991 (1)
//         00478150     PUSH       ESI
//                              Pnl_inp.cpp:994 (7)
//         00478151     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         00478156     MOV        ESI,EAX
//                              Pnl_inp.cpp:995 (2)
//         00478158     TEST       ESI,ESI
//                              Pnl_inp.cpp:996 (2)
//         0047815a     JZ         LAB_0047818a
//                              Pnl_inp.cpp:998 (3)
//         0047815c     CMP        byte ptr [ESI],0x0
//                              Pnl_inp.cpp:999 (2)
//         0047815f     JZ         LAB_0047818a
//                               LAB_00478161                                                 XREF[1]:     00478184(j)
//                              Pnl_inp.cpp:1003 (6)
//         00478161     MOV        AL,byte ptr [ESI]
//         00478163     TEST       AL,AL
//         00478165     JZ         LAB_0047818a
//                              Pnl_inp.cpp:1006 (18)
//         00478167     AND        EAX,0xff
//         0047816c     PUSH       EAX
//         0047816d     CALL       __ismbcspace                                     undefined __ismbcspace()
//         00478172     ADD        ESP,0x4
//         00478175     TEST       EAX,EAX
//         00478177     JZ         LAB_00478186
//                              Pnl_inp.cpp:1009 (13)
//         00478179     PUSH       ESI
//         0047817a     CALL       __mbsinc                                         undefined __mbsinc()
//         0047817f     ADD        ESP,0x4
//         00478182     MOV        ESI,EAX
//         00478184     JMP        LAB_00478161
//                               LAB_00478186                                                 XREF[1]:     00478177(j)
//                              Pnl_inp.cpp:1007 (2)
//         00478186     XOR        EAX,EAX
//                              Pnl_inp.cpp:1013 (2)
//         00478188     POP        ESI
//         00478189     RET
//                               LAB_0047818a                                                 XREF[3]:     0047815a(j), 0047815f(j),
//                                                                                                         00478165(j)
//                              Pnl_inp.cpp:1012 (5)
//         0047818a     MOV        EAX,0x1
//                              Pnl_inp.cpp:1013 (2)
//         0047818f     POP        ESI
//         00478190     RET
//         00478191     ??         90h
//         00478192     NOP
//         00478193     NOP
//         00478194     NOP
//         00478195     NOP
//         00478196     NOP
//         00478197     NOP
//         00478198     NOP
//         00478199     NOP
//         0047819a     NOP
//         0047819b     NOP
//         0047819c     NOP
//         0047819d     NOP
//         0047819e     NOP
//         0047819f     NOP
    return 0;
}

char* TInputPanel::get_trimmed_str(char* param_1, int param_2) {
    /* TODO: Stub */
//                              char * __thiscall get_trimmed_str(TInputPanel * this, char * param_1
//              char *            EAX:4          <RETURN>
//              TInputPanel *     ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004781d0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004781eb(R)
//              char[256]         Stack[-0x104   temp_str                  XREF[0,5]:   004781b2(*), 004781c6(*), 00478204(R), 00478208(*),
//                                                                                     0047823a(*)
//                               ?get_trimmed_str@TInputPanel@@QAEPADPADH@Z
//                               TInputPanel::get_trimmed_str
//                              Pnl_inp.cpp:1019 (8)
//         004781a0     SUB        ESP,0x100
//         004781a6     MOV        EDX,this
//                              Pnl_inp.cpp:1024 (16)
//         004781a8     MOV        this,0x40
//         004781ad     XOR        EAX,EAX
//         004781af     PUSH       EBX
//         004781b0     PUSH       ESI
//         004781b1     PUSH       EDI
//         004781b2     LEA        EDI=>temp_str[4],[ESP + 0xc]
//         004781b6     STOSD.REP  ES:EDI
//                              Pnl_inp.cpp:1025 (24)
//         004781b8     MOV        this,EDX
//         004781ba     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//         004781bf     MOV        EDI,EAX
//         004781c1     OR         this,0xffffffff
//         004781c4     XOR        EAX,EAX
//         004781c6     LEA        EDX=>temp_str[4],[ESP + 0xc]
//         004781ca     SCASB.RE   ES:EDI
//         004781cc     NOT        this
//         004781ce     SUB        EDI,this
//                              Pnl_inp.cpp:1027 (38)
//         004781d0     MOV        EBX,dword ptr [ESP + param_1]
//         004781d7     MOV        EAX,this
//         004781d9     MOV        ESI,EDI
//         004781db     MOV        EDI,EDX
//         004781dd     SHR        this,0x2
//         004781e0     MOVSD.REP  ES:EDI,ESI
//         004781e2     MOV        this,EAX
//         004781e4     XOR        EAX,EAX
//         004781e6     AND        this,0x3
//         004781e9     MOVSB.REP  ES:EDI,ESI
//         004781eb     MOV        this,dword ptr [ESP + param_2]
//         004781f2     MOV        EDI,EBX
//         004781f4     MOV        EDX,this
//                              Pnl_inp.cpp:1030 (14)
//         004781f6     MOV        ESI,EBX
//         004781f8     SHR        this,0x2
//         004781fb     STOSD.REP  ES:EDI
//         004781fd     MOV        this,EDX
//         004781ff     AND        this,0x3
//         00478202     STOSB.REP  ES:EDI
//                              Pnl_inp.cpp:1032 (26)
//         00478204     MOV        EAX,dword ptr [ESP + temp_str[4]]
//         00478208     LEA        EDI=>temp_str[4],[ESP + 0xc]
//         0047820c     AND        EAX,0xff
//         00478211     PUSH       EAX
//         00478212     CALL       __ismbcspace                                     undefined __ismbcspace()
//         00478217     ADD        ESP,0x4
//         0047821a     TEST       EAX,EAX
//         0047821c     JZ         LAB_0047823a
//                               LAB_0047821e                                                 XREF[1]:     00478238(j)
//                              Pnl_inp.cpp:1033 (28)
//         0047821e     PUSH       EDI
//         0047821f     CALL       __mbsinc                                         undefined __mbsinc()
//         00478224     MOV        EDI,EAX
//         00478226     XOR        this,this
//         00478228     ADD        ESP,0x4
//         0047822b     MOV        this,byte ptr [EDI]
//         0047822d     PUSH       this
//         0047822e     CALL       __ismbcspace                                     undefined __ismbcspace()
//         00478233     ADD        ESP,0x4
//         00478236     TEST       EAX,EAX
//         00478238     JNZ        LAB_0047821e
//                               LAB_0047823a                                                 XREF[1]:     0047821c(j)
//                              Pnl_inp.cpp:1035 (5)
//         0047823a     CMP        byte ptr [EDI]=>temp_str[4],0x0
//         0047823d     JZ         LAB_00478266
//                               LAB_0047823f                                                 XREF[1]:     00478264(j)
//                              Pnl_inp.cpp:1037 (12)
//         0047823f     PUSH       0x1
//         00478241     PUSH       EDI
//         00478242     PUSH       ESI
//         00478243     CALL       __mbsncpy                                        undefined __mbsncpy()
//         00478248     ADD        ESP,0xc
//                              Pnl_inp.cpp:1038 (11)
//         0047824b     PUSH       ESI
//         0047824c     CALL       __mbsinc                                         undefined __mbsinc()
//         00478251     ADD        ESP,0x4
//         00478254     MOV        ESI,EAX
//                              Pnl_inp.cpp:1039 (16)
//         00478256     PUSH       EDI
//         00478257     CALL       __mbsinc                                         undefined __mbsinc()
//         0047825c     MOV        EDI,EAX
//         0047825e     ADD        ESP,0x4
//         00478261     CMP        byte ptr [EDI],0x0
//         00478264     JNZ        LAB_0047823f
//                               LAB_00478266                                                 XREF[2]:     0047823d(j), 00478288(j)
//                              Pnl_inp.cpp:1045 (7)
//         00478266     CMP        ESI,EBX
//         00478268     MOV        byte ptr [ESI],0x0
//         0047826b     JZ         LAB_0047828a
//                              Pnl_inp.cpp:1047 (9)
//         0047826d     PUSH       ESI
//         0047826e     PUSH       EBX
//         0047826f     CALL       __mbsdec                                         undefined __mbsdec()
//         00478274     MOV        ESI,EAX
//                              Pnl_inp.cpp:1048 (20)
//         00478276     XOR        EDX,EDX
//         00478278     ADD        ESP,0x8
//         0047827b     MOV        DL,byte ptr [ESI]
//         0047827d     PUSH       EDX
//         0047827e     CALL       __ismbcspace                                     undefined __ismbcspace()
//         00478283     ADD        ESP,0x4
//         00478286     TEST       EAX,EAX
//         00478288     JNZ        LAB_00478266
//                               LAB_0047828a                                                 XREF[1]:     0047826b(j)
//                              Pnl_inp.cpp:1054 (14)
//         0047828a     POP        EDI
//         0047828b     MOV        EAX,EBX
//         0047828d     POP        ESI
//         0047828e     POP        EBX
//         0047828f     ADD        ESP,0x100
//         00478295     RET        0x8
//         00478298     ??         90h
//         00478299     NOP
//         0047829a     NOP
//         0047829b     NOP
//         0047829c     NOP
//         0047829d     NOP
//         0047829e     NOP
//         0047829f     NOP
    return 0;
}

