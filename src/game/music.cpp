#include "../common.h"
#include "music.h"

TMusic_System::TMusic_System(uchar param_1, void* param_2, void* param_3, TSound_Driver* param_4, char* param_5) {
    /* TODO: Stub */
//                              undefined __thiscall TMusic_System(TMusic_System * this, uchar param
//              undefined         <UNASSIGNED>   <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00461910(R)
//              void *            Stack[0x8]:4   param_2                   XREF[1]:     00461917(R)
//              void *            Stack[0xc]:4   param_3                   XREF[1]:     0046192a(R)
//              TSound_Driver *   Stack[0x10]:4  param_4                   XREF[1]:     0046191b(R)
//              char *            Stack[0x14]:4  param_5                   XREF[1]:     00461920(R)
//                               ??0TMusic_System@@QAE@EPAX0PAVTSound_Driver@@PAD@Z           XREF[1]:     setup_music_system:0041f245(c)
//                               TMusic_System::TMusic_System
//                              music.cpp:52 (16)
//         00461910     MOV        AL,byte ptr [ESP + param_1]
//         00461914     PUSH       EBX
//         00461915     MOV        EBX,this
//         00461917     MOV        EDX,dword ptr [ESP + param_2]
//         0046191b     MOV        this,dword ptr [ESP + param_4]
//         0046191f     PUSH       EDI
//                              music.cpp:54 (190)
//         00461920     MOV        EDI,dword ptr [ESP + param_5]
//         00461924     MOV        byte ptr [EBX + 0x104],AL
//         0046192a     MOV        EAX,dword ptr [ESP + param_3]
//         0046192e     MOV        dword ptr [EBX + 0x108],this
//         00461934     MOV        dword ptr [EBX + 0x110],EAX
//         0046193a     XOR        EAX,EAX
//         0046193c     CMP        EDI,EAX
//         0046193e     MOV        dword ptr [EBX + 0x10c],EDX
//         00461944     MOV        dword ptr [EBX + 0x114],EAX
//         0046194a     MOV        dword ptr [EBX + 0x118],EAX
//         00461950     MOV        byte ptr [EBX + 0x128],AL
//         00461956     MOV        dword ptr [EBX + 0x230],EAX
//         0046195c     MOV        dword ptr [EBX + 0x234],EAX
//         00461962     MOV        dword ptr [EBX + 0x238],EAX
//         00461968     MOV        dword ptr [EBX + 0x23c],EAX
//         0046196e     MOV        dword ptr [EBX + 0x240],EAX
//         00461974     MOV        dword ptr [EBX + 0x244],EAX
//         0046197a     MOV        dword ptr [EBX + 0x248],EAX
//         00461980     MOV        dword ptr [EBX + 0x24c],EAX
//         00461986     MOV        dword ptr [EBX + 0x250],0x1
//         00461990     MOV        dword ptr [EBX + 0x254],EAX
//         00461996     MOV        dword ptr [EBX + 0x258],EAX
//         0046199c     MOV        dword ptr [EBX + 0x25c],EAX
//         004619a2     MOV        dword ptr [EBX + 0x260],EAX
//         004619a8     MOV        dword ptr [EBX + 0x264],EAX
//         004619ae     MOV        dword ptr [EBX + 0x268],0x7d0
//         004619b8     MOV        dword ptr [EBX + 0x26c],EAX
//         004619be     MOV        dword ptr [EBX + 0x274],EAX
//         004619c4     MOV        dword ptr [EBX + 0x278],EAX
//         004619ca     MOV        dword ptr [EBX + 0x27c],EAX
//         004619d0     MOV        dword ptr [EBX + 0x3f0],EAX
//         004619d6     MOV        byte ptr [EBX + 0x129],AL
//         004619dc     JZ         LAB_00461a09
//                              music.cpp:55 (29)
//         004619de     OR         this,0xffffffff
//         004619e1     PUSH       ESI
//         004619e2     SCASB.RE   ES:EDI
//         004619e4     NOT        this
//         004619e6     SUB        EDI,this
//         004619e8     MOV        EDX,this
//         004619ea     MOV        ESI,EDI
//         004619ec     MOV        EDI,EBX
//         004619ee     SHR        this,0x2
//         004619f1     MOVSD.REP  ES:EDI,ESI
//         004619f3     MOV        this,EDX
//         004619f5     AND        this,0x3
//         004619f8     MOVSB.REP  ES:EDI,ESI
//         004619fa     POP        ESI
//                              music.cpp:58 (7)
//         004619fb     MOV        this,EBX
//         004619fd     CALL       TMusic_System::open_device                       int open_device(TMusic_System * this)
//                              music.cpp:59 (7)
//         00461a02     MOV        EAX,EBX
//         00461a04     POP        EDI
//         00461a05     POP        EBX
//         00461a06     RET        0x14
//                               LAB_00461a09                                                 XREF[1]:     004619dc(j)
//                              music.cpp:58 (9)
//         00461a09     MOV        this,EBX
//         00461a0b     MOV        byte ptr [EBX],AL
//         00461a0d     CALL       TMusic_System::open_device                       int open_device(TMusic_System * this)
//                              music.cpp:59 (7)
//         00461a12     MOV        EAX,EBX
//         00461a14     POP        EDI
//         00461a15     POP        EBX
//         00461a16     RET        0x14
}

TMusic_System::~TMusic_System() {
    /* TODO: Stub */
//                              void __thiscall ~TMusic_System(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ??1TMusic_System@@QAE@XZ                                     XREF[2]:     setup_music_system:0041f183(c),
//                               TMusic_System::~TMusic_System                                             shutdown_music_system:0041faca(c)
//                              music.cpp:64 (5)
//         00461a20     JMP        TMusic_System::close_device
//         00461a25     ??         90h
//         00461a26     NOP
//         00461a27     NOP
//         00461a28     NOP
//         00461a29     NOP
//         00461a2a     NOP
//         00461a2b     NOP
//         00461a2c     NOP
//         00461a2d     NOP
//         00461a2e     NOP
//         00461a2f     NOP
}

int TMusic_System::open_device() {
    /* TODO: Stub */
//                              int __thiscall open_device(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              char[261]         Stack[-0x10c   file_name                 XREF[0,4]:   00461a63(*), 00461a78(*), 00461b1b(*), 00461b30(*)
//              tagMCI_OPEN_PA    Stack[-0x120   open_info                 XREF[0,3]:   00461b7c(*), 00461b9f(R), 00461b8d(W)
//              tagMCI_SET_PAR    Stack[-0x12c   set_info                  XREF[0,2]:   00461ba3(*), 00461bc3(W)
//              tagMCI_STATUS_    Stack[-0x13c   status_info               XREF[0,3]:   00461bd3(*), 00461bf1(R), 00461be3(W)
//                               ?open_device@TMusic_System@@QAEHXZ                           XREF[3]:     TMusic_System:004619fd(c),
//                               TMusic_System::open_device                                                TMusic_System:00461a0d(c),
//                                                                                                         set_music_type:00461f2a(c)
//                              music.cpp:71 (6)
//         00461a30     SUB        ESP,0x138
//                              music.cpp:79 (29)
//         00461a36     XOR        EAX,EAX
//         00461a38     PUSH       ESI
//         00461a39     MOV        ESI,this
//         00461a3b     PUSH       EDI
//         00461a3c     MOV        AL,byte ptr [ESI + 0x104]
//         00461a42     DEC        EAX
//         00461a43     JZ         LAB_00461b76
//         00461a49     DEC        EAX
//         00461a4a     JZ         LAB_00461ac8
//         00461a4c     DEC        EAX
//         00461a4d     JNZ        LAB_00461c4c
//                              music.cpp:155 (10)
//         00461a53     MOV        dword ptr [ESI + 0x248],0x0
//                               LAB_00461a5d                                                 XREF[1]:     00461aa4(j)
//                              music.cpp:158 (27)
//         00461a5d     MOV        EAX,dword ptr [ESI + 0x248]
//         00461a63     LEA        this=>file_name[4],[ESP + 0x38]
//         00461a67     INC        EAX
//         00461a68     PUSH       EAX
//         00461a69     PUSH       ESI
//         00461a6a     PUSH       s_%smusic%d.wav                                  = "%smusic%d.wav"
//         00461a6f     PUSH       this
//         00461a70     CALL       sprintf                                          undefined sprintf()
//         00461a75     ADD        ESP,0x10
//                              music.cpp:159 (18)
//         00461a78     LEA        EDX=>file_name[4],[ESP + 0x38]
//         00461a7c     PUSH       s_r                                              = "r"
//         00461a81     PUSH       EDX
//         00461a82     CALL       fopen                                            undefined fopen()
//         00461a87     ADD        ESP,0x8
//                              music.cpp:160 (4)
//         00461a8a     TEST       EAX,EAX
//         00461a8c     JZ         LAB_00461aa6
//                              music.cpp:162 (6)
//         00461a8e     PUSH       EAX
//         00461a8f     CALL       fclose                                           undefined fclose()
//                              music.cpp:163 (18)
//         00461a94     MOV        EAX,dword ptr [ESI + 0x248]
//         00461a9a     ADD        ESP,0x4
//         00461a9d     INC        EAX
//         00461a9e     MOV        dword ptr [ESI + 0x248],EAX
//         00461aa4     JMP        LAB_00461a5d
//                               LAB_00461aa6                                                 XREF[1]:     00461a8c(j)
//                              music.cpp:165 (10)
//         00461aa6     MOV        dword ptr [ESI + 0x254],0x0
//                              music.cpp:166 (10)
//         00461ab0     MOV        dword ptr [ESI + 0x114],0x1
//                              music.cpp:167 (5)
//         00461aba     MOV        EAX,0x1
//                              music.cpp:216 (9)
//         00461abf     POP        EDI
//         00461ac0     POP        ESI
//         00461ac1     ADD        ESP,0x138
//         00461ac7     RET
//                               LAB_00461ac8                                                 XREF[1]:     00461a4a(j)
//                              music.cpp:124 (11)
//         00461ac8     MOV        this,ESI
//         00461aca     CALL       TMusic_System::open_mixer                        int open_mixer(TMusic_System * this)
//         00461acf     TEST       EAX,EAX
//         00461ad1     JZ         LAB_00461b0b
//                              music.cpp:131 (50)
//         00461ad3     MOV        EAX,dword ptr [ESI + 0x3ec]
//         00461ad9     MOV        this,dword ptr [ESI + 0x3a8]
//         00461adf     MOV        EDI,dword ptr [ESI + 0x3a4]
//         00461ae5     XOR        EDX,EDX
//         00461ae7     LEA        EAX,[EAX + EAX*0x4]
//         00461aea     SUB        this,EDI
//         00461aec     LEA        EAX,[EAX + EAX*0x4]
//         00461aef     LEA        EAX,[EAX + EAX*0x4]
//         00461af2     LEA        EAX,[EAX + EAX*0x4]
//         00461af5     SHL        EAX,0x4
//         00461af8     DIV        this
//         00461afa     ADD        EAX,0xffffd8f0
//         00461aff     MOV        dword ptr [ESI + 0x250],EAX
//                              music.cpp:132 (6)
//         00461b05     MOV        dword ptr [ESI + 0x254],EAX
//                               LAB_00461b0b                                                 XREF[1]:     00461ad1(j)
//                              music.cpp:137 (10)
//         00461b0b     MOV        dword ptr [ESI + 0x248],0x0
//                               LAB_00461b15                                                 XREF[1]:     00461b5c(j)
//                              music.cpp:140 (27)
//         00461b15     MOV        EDX,dword ptr [ESI + 0x248]
//         00461b1b     LEA        EAX=>file_name[4],[ESP + 0x38]
//         00461b1f     INC        EDX
//         00461b20     PUSH       EDX
//         00461b21     PUSH       ESI
//         00461b22     PUSH       s_%smusic%d.mid                                  = "%smusic%d.mid"
//         00461b27     PUSH       EAX
//         00461b28     CALL       sprintf                                          undefined sprintf()
//         00461b2d     ADD        ESP,0x10
//                              music.cpp:142 (18)
//         00461b30     LEA        this=>file_name[4],[ESP + 0x38]
//         00461b34     PUSH       s_r                                              = "r"
//         00461b39     PUSH       this
//         00461b3a     CALL       fopen                                            undefined fopen()
//         00461b3f     ADD        ESP,0x8
//                              music.cpp:143 (4)
//         00461b42     TEST       EAX,EAX
//         00461b44     JZ         LAB_00461b5e
//                              music.cpp:145 (6)
//         00461b46     PUSH       EAX
//         00461b47     CALL       fclose                                           undefined fclose()
//                              music.cpp:146 (18)
//         00461b4c     MOV        EAX,dword ptr [ESI + 0x248]
//         00461b52     ADD        ESP,0x4
//         00461b55     INC        EAX
//         00461b56     MOV        dword ptr [ESI + 0x248],EAX
//         00461b5c     JMP        LAB_00461b15
//                               LAB_00461b5e                                                 XREF[1]:     00461b44(j)
//                              music.cpp:149 (10)
//         00461b5e     MOV        dword ptr [ESI + 0x114],0x1
//                              music.cpp:150 (5)
//         00461b68     MOV        EAX,0x1
//                              music.cpp:216 (9)
//         00461b6d     POP        EDI
//         00461b6e     POP        ESI
//         00461b6f     ADD        ESP,0x138
//         00461b75     RET
//                               LAB_00461b76                                                 XREF[1]:     00461a43(j)
//                              music.cpp:84 (33)
//         00461b76     MOV        EDI,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
//         00461b7c     LEA        EDX=>open_info.wDeviceID,[ESP + 0x24]
//         00461b80     PUSH       EDX
//         00461b81     PUSH       0x3102
//         00461b86     PUSH       0x803
//         00461b8b     PUSH       0x0
//         00461b8d     MOV        dword ptr [ESP + open_info.lpstrElementName],0
//         00461b95     CALL       EDI=>WINMM.DLL::mciSendCommandA
//                              music.cpp:87 (8)
//         00461b97     TEST       EAX,EAX
//         00461b99     JNZ        LAB_00461c4c
//                              music.cpp:92 (4)
//         00461b9f     MOV        EAX,dword ptr [ESP + open_info.lpstrDeviceType]
//                              music.cpp:96 (42)
//         00461ba3     LEA        this=>set_info.dwTimeFormat,[ESP + 0x18]
//         00461ba7     PUSH       this
//         00461ba8     PUSH       0x402
//         00461bad     PUSH       0x80d
//         00461bb2     PUSH       EAX
//         00461bb3     MOV        dword ptr [ESI + 0x114],0x1
//         00461bbd     MOV        dword ptr [ESI + 0x118],EAX
//         00461bc3     MOV        dword ptr [ESP + set_info.dwAudio],0xa
//         00461bcb     CALL       EDI=>WINMM.DLL::mciSendCommandA
//                              music.cpp:100 (32)
//         00461bcd     MOV        EAX,dword ptr [ESI + 0x118]
//         00461bd3     LEA        EDX=>status_info.dwReturn,[ESP + 0x8]
//         00461bd7     PUSH       EDX
//         00461bd8     PUSH       0x102
//         00461bdd     PUSH       0x814
//         00461be2     PUSH       EAX
//         00461be3     MOV        dword ptr [ESP + status_info.dwTrack],0x3
//         00461beb     CALL       EDI=>WINMM.DLL::mciSendCommandA
//                              music.cpp:101 (4)
//         00461bed     TEST       EAX,EAX
//         00461bef     JNZ        LAB_00461bfb
//                              music.cpp:102 (10)
//         00461bf1     MOV        this,dword ptr [ESP + status_info.dwItem]
//         00461bf5     MOV        dword ptr [ESI + 0x248],this
//                               LAB_00461bfb                                                 XREF[1]:     00461bef(j)
//                              music.cpp:106 (11)
//         00461bfb     MOV        this,ESI
//         00461bfd     CALL       TMusic_System::open_mixer                        int open_mixer(TMusic_System * this)
//         00461c02     TEST       EAX,EAX
//         00461c04     JZ         LAB_00461c3e
//                              music.cpp:113 (50)
//         00461c06     MOV        EAX,dword ptr [ESI + 0x3ec]
//         00461c0c     MOV        this,dword ptr [ESI + 0x3a8]
//         00461c12     MOV        EDI,dword ptr [ESI + 0x3a4]
//         00461c18     XOR        EDX,EDX
//         00461c1a     LEA        EAX,[EAX + EAX*0x4]
//         00461c1d     SUB        this,EDI
//         00461c1f     LEA        EAX,[EAX + EAX*0x4]
//         00461c22     LEA        EAX,[EAX + EAX*0x4]
//         00461c25     LEA        EAX,[EAX + EAX*0x4]
//         00461c28     SHL        EAX,0x4
//         00461c2b     DIV        this
//         00461c2d     ADD        EAX,0xffffd8f0
//         00461c32     MOV        dword ptr [ESI + 0x250],EAX
//                              music.cpp:114 (6)
//         00461c38     MOV        dword ptr [ESI + 0x254],EAX
//                               LAB_00461c3e                                                 XREF[1]:     00461c04(j)
//                              music.cpp:117 (5)
//         00461c3e     MOV        EAX,0x1
//                              music.cpp:216 (20)
//         00461c43     POP        EDI
//         00461c44     POP        ESI
//         00461c45     ADD        ESP,0x138
//         00461c4b     RET
//                               LAB_00461c4c                                                 XREF[2]:     00461a4d(j), 00461b99(j)
//         00461c4c     POP        EDI
//         00461c4d     XOR        EAX,EAX
//         00461c4f     POP        ESI
//         00461c50     ADD        ESP,0x138
//         00461c56     RET
//         00461c57     ??         90h
//         00461c58     NOP
//         00461c59     NOP
//         00461c5a     NOP
//         00461c5b     NOP
//         00461c5c     NOP
//         00461c5d     NOP
//         00461c5e     NOP
//         00461c5f     NOP
    return 0;
}

void TMusic_System::close_device() {
    /* TODO: Stub */
//                              void __thiscall close_device(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?close_device@TMusic_System@@QAEXXZ                          XREF[2]:     close_device:00461a19(T),
//                               TMusic_System::close_device                                               ~TMusic_System:00461a20(j),
//                                                                                                         set_music_type:00461f1d(c)
//                              music.cpp:221 (4)
//         00461c60     PUSH       ESI
//         00461c61     MOV        ESI,this
//         00461c63     PUSH       EDI
//                              music.cpp:224 (14)
//         00461c64     XOR        EDI,EDI
//         00461c66     CMP        dword ptr [ESI + 0x114],EDI
//         00461c6c     JZ         LAB_00461d1b
//                              music.cpp:227 (5)
//         00461c72     CALL       TMusic_System::stop_track                        int stop_track(TMusic_System * this)
//                              music.cpp:229 (21)
//         00461c77     XOR        EAX,EAX
//         00461c79     MOV        AL,byte ptr [ESI + 0x104]
//         00461c7f     DEC        EAX
//         00461c80     JZ         LAB_00461ccf
//         00461c82     DEC        EAX
//         00461c83     JZ         LAB_00461c9b
//         00461c85     DEC        EAX
//         00461c86     JNZ        LAB_00461d1b
//                              music.cpp:269 (6)
//         00461c8c     MOV        dword ptr [ESI + 0x248],EDI
//                              music.cpp:270 (6)
//         00461c92     MOV        dword ptr [ESI + 0x114],EDI
//                              music.cpp:290 (3)
//         00461c98     POP        EDI
//         00461c99     POP        ESI
//         00461c9a     RET
//                               LAB_00461c9b                                                 XREF[1]:     00461c83(j)
//                              music.cpp:248 (11)
//         00461c9b     MOV        EAX,dword ptr [ESI + 0x250]
//         00461ca1     CMP        EAX,0x1
//         00461ca4     JZ         LAB_00461cb9
//                              music.cpp:250 (9)
//         00461ca6     PUSH       EDI
//         00461ca7     PUSH       EAX
//         00461ca8     MOV        this,ESI
//         00461caa     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
//                              music.cpp:251 (10)
//         00461caf     MOV        dword ptr [ESI + 0x250],0x1
//                               LAB_00461cb9                                                 XREF[1]:     00461ca4(j)
//                              music.cpp:254 (19)
//         00461cb9     MOV        this,ESI
//         00461cbb     CALL       TMusic_System::close_mixer                       void close_mixer(TMusic_System * this)
//         00461cc0     MOV        dword ptr [ESI + 0x114],EDI
//         00461cc6     MOV        dword ptr [ESI + 0x248],EDI
//                              music.cpp:290 (3)
//         00461ccc     POP        EDI
//         00461ccd     POP        ESI
//         00461cce     RET
//                               LAB_00461ccf                                                 XREF[1]:     00461c80(j)
//                              music.cpp:232 (11)
//         00461ccf     MOV        EAX,dword ptr [ESI + 0x250]
//         00461cd5     CMP        EAX,0x1
//         00461cd8     JZ         LAB_00461ced
//                              music.cpp:234 (9)
//         00461cda     PUSH       EDI
//         00461cdb     PUSH       EAX
//         00461cdc     MOV        this,ESI
//         00461cde     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
//                              music.cpp:235 (10)
//         00461ce3     MOV        dword ptr [ESI + 0x250],0x1
//                               LAB_00461ced                                                 XREF[1]:     00461cd8(j)
//                              music.cpp:238 (7)
//         00461ced     MOV        this,ESI
//         00461cef     CALL       TMusic_System::close_mixer                       void close_mixer(TMusic_System * this)
//                              music.cpp:241 (21)
//         00461cf4     MOV        EAX,dword ptr [ESI + 0x118]
//         00461cfa     PUSH       EDI
//         00461cfb     PUSH       0x2
//         00461cfd     PUSH       0x804
//         00461d02     PUSH       EAX
//         00461d03     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:242 (6)
//         00461d09     MOV        dword ptr [ESI + 0x118],EDI
//                              music.cpp:243 (6)
//         00461d0f     MOV        dword ptr [ESI + 0x114],EDI
//                              music.cpp:244 (6)
//         00461d15     MOV        dword ptr [ESI + 0x248],EDI
//                               LAB_00461d1b                                                 XREF[2]:     00461c6c(j), 00461c86(j)
//                              music.cpp:290 (3)
//         00461d1b     POP        EDI
//         00461d1c     POP        ESI
//         00461d1d     RET
//         00461d1e     ??         90h
//         00461d1f     NOP
    return;
}

int TMusic_System::open_mixer() {
    /* TODO: Stub */
//                              int __thiscall open_mixer(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              uint              Stack[-0x8]:4  num_dev
//              uint              Stack[-0xc]:4  mixer_id
//                               ?open_mixer@TMusic_System@@IAEHXZ                            XREF[2]:     open_device:00461aca(c),
//                               TMusic_System::open_mixer                                                 open_device:00461bfd(c)
//                              music.cpp:294 (9)
//         00461d20     SUB        ESP,0x8
//         00461d23     PUSH       EBX
//         00461d24     PUSH       EBP
//         00461d25     PUSH       ESI
//         00461d26     PUSH       EDI
//         00461d27     MOV        ESI,this
//                              music.cpp:299 (8)
//         00461d29     CALL       dword ptr [->WINMM.DLL::mixerGetNumDevs]         = 0048b590
//         00461d2f     MOV        EDI,EAX
//                              music.cpp:300 (12)
//         00461d31     TEST       EDI,EDI
//         00461d33     MOV        dword ptr [ESP + 0x14],EDI
//         00461d37     JBE        LAB_00461eac
//                              music.cpp:303 (14)
//         00461d3d     XOR        EBP,EBP
//         00461d3f     TEST       EDI,EDI
//         00461d41     MOV        dword ptr [ESP + 0x10],EBP
//         00461d45     JBE        LAB_00461eac
//                              music.cpp:305 (20)
//         00461d4b     LEA        EBX,[ESI + 0x27c]
//                               LAB_00461d51                                                 XREF[1]:     00461e89(j)
//         00461d51     PUSH       0x0
//         00461d53     PUSH       0x0=>DAT_fffffff8
//         00461d55     PUSH       0x0=>DAT_fffffff4
//         00461d57     PUSH       EBP=>DAT_fffffff0
//         00461d58     PUSH       EBX
//         00461d59     CALL       dword ptr [->WINMM.DLL::mixerOpen]               = 0048b584
//                              music.cpp:306 (8)
//         00461d5f     TEST       EAX,EAX
//         00461d61     JNZ        LAB_00461e82
//                              music.cpp:309 (15)
//         00461d67     LEA        EDX,[ESI + 0x280]
//         00461d6d     MOV        this,0x2a
//         00461d72     MOV        EDI,EDX
//         00461d74     STOSD.REP  ES:EDI
//                              music.cpp:311 (16)
//         00461d76     MOV        AL,byte ptr [ESI + 0x104]
//         00461d7c     MOV        dword ptr [EDX],0xa8
//         00461d82     CMP        AL,0x1
//         00461d84     JNZ        LAB_00461d92
//                              language.dll match for 0x1005: "Work (W)"
//                              music.cpp:312 (10)
//         00461d86     MOV        dword ptr [ESI + 0x298],0x1005
//                              music.cpp:313 (2)
//         00461d90     JMP        LAB_00461d9c
//                               LAB_00461d92                                                 XREF[1]:     00461d84(j)
//                              music.cpp:314 (10)
//         00461d92     MOV        dword ptr [ESI + 0x298],0x1004
//                               LAB_00461d9c                                                 XREF[1]:     00461d90(j)
//                              music.cpp:315 (12)
//         00461d9c     MOV        EAX,dword ptr [EBX]
//         00461d9e     PUSH       0x3
//         00461da0     PUSH       EDX=>DAT_fffffff8
//         00461da1     PUSH       EAX=>DAT_fffffff4
//         00461da2     CALL       dword ptr [->WINMM.DLL::mixerGetLineInfoA]       = 0048b570
//                              music.cpp:316 (8)
//         00461da8     TEST       EAX,EAX
//         00461daa     JNZ        LAB_00461e6f
//                              music.cpp:319 (13)
//         00461db0     LEA        EDX,[ESI + 0x328]
//         00461db6     MOV        this,0x6
//         00461dbb     MOV        EDI,EDX
//                              music.cpp:320 (17)
//         00461dbd     LEA        EBP,[ESI + 0x340]
//         00461dc3     STOSD.REP  ES:EDI
//         00461dc5     MOV        this,0x25
//         00461dca     MOV        EDI,EBP
//         00461dcc     STOSD.REP  ES:EDI
//                              music.cpp:322 (6)
//         00461dce     MOV        this,dword ptr [ESI + 0x28c]
//                              music.cpp:327 (60)
//         00461dd4     PUSH       0x2
//         00461dd6     MOV        dword ptr [EDX],0x18
//         00461ddc     PUSH       EDX=>DAT_fffffff8
//         00461ddd     MOV        EDX,dword ptr [EBX]
//         00461ddf     MOV        dword ptr [ESI + 0x32c],this
//         00461de5     PUSH       EDX=>DAT_fffffff4
//         00461de6     MOV        dword ptr [ESI + 0x330],0x50030001
//         00461df0     MOV        dword ptr [ESI + 0x334],0x1
//         00461dfa     MOV        dword ptr [ESI + 0x338],0x94
//         00461e04     MOV        dword ptr [ESI + 0x33c],EBP
//         00461e0a     CALL       dword ptr [->WINMM.DLL::mixerGetLineControlsA]   = 0048b558
//                              music.cpp:328 (4)
//         00461e10     TEST       EAX,EAX
//         00461e12     JNZ        LAB_00461e6b
//                              music.cpp:331 (13)
//         00461e14     LEA        EDX,[ESI + 0x3d4]
//         00461e1a     MOV        this,0x6
//         00461e1f     MOV        EDI,EDX
//                              music.cpp:338 (70)
//         00461e21     PUSH       0x0
//         00461e23     STOSD.REP  ES:EDI
//         00461e25     LEA        EAX,[ESI + 0x3ec]
//         00461e2b     PUSH       EDX=>DAT_fffffff8
//         00461e2c     MOV        dword ptr [EAX],0x0
//         00461e32     MOV        this,dword ptr [ESI + 0x344]
//         00461e38     MOV        dword ptr [EDX],0x18
//         00461e3e     MOV        EDX,dword ptr [EBX]
//         00461e40     PUSH       EDX=>DAT_fffffff4
//         00461e41     MOV        dword ptr [ESI + 0x3d8],this
//         00461e47     MOV        dword ptr [ESI + 0x3dc],0x1
//         00461e51     MOV        dword ptr [ESI + 0x3e4],0x4
//         00461e5b     MOV        dword ptr [ESI + 0x3e8],EAX
//         00461e61     CALL       dword ptr [->WINMM.DLL::mixerGetControlDetailsA] = 0048b53e
//                              music.cpp:339 (8)
//         00461e67     TEST       EAX,EAX
//         00461e69     JZ         LAB_00461e99
//                               LAB_00461e6b                                                 XREF[1]:     00461e12(j)
//         00461e6b     MOV        EBP,dword ptr [ESP + 0x10]
//                               LAB_00461e6f                                                 XREF[1]:     00461daa(j)
//                              music.cpp:346 (9)
//         00461e6f     MOV        EAX,dword ptr [EBX]
//         00461e71     PUSH       EAX
//         00461e72     CALL       dword ptr [->WINMM.DLL::mixerClose]              = 0048b530
//                              music.cpp:347 (23)
//         00461e78     MOV        EDI,dword ptr [ESP + 0x14]
//         00461e7c     MOV        dword ptr [EBX],0x0
//                               LAB_00461e82                                                 XREF[1]:     00461d61(j)
//         00461e82     INC        EBP
//         00461e83     CMP        EBP,EDI
//         00461e85     MOV        dword ptr [ESP + 0x10],EBP
//         00461e89     JC         LAB_00461d51
//                              music.cpp:352 (2)
//         00461e8f     XOR        EAX,EAX
//                              music.cpp:353 (8)
//         00461e91     POP        EDI
//         00461e92     POP        ESI
//         00461e93     POP        EBP
//         00461e94     POP        EBX
//         00461e95     ADD        ESP,0x8
//         00461e98     RET
//                               LAB_00461e99                                                 XREF[1]:     00461e69(j)
//                              music.cpp:341 (11)
//         00461e99     MOV        EAX,0x1
//         00461e9e     MOV        dword ptr [ESI + 0x278],EAX
//                              music.cpp:353 (18)
//         00461ea4     POP        EDI
//         00461ea5     POP        ESI
//         00461ea6     POP        EBP
//         00461ea7     POP        EBX
//         00461ea8     ADD        ESP,0x8
//         00461eab     RET
//                               LAB_00461eac                                                 XREF[2]:     00461d37(j), 00461d45(j)
//         00461eac     POP        EDI
//         00461ead     POP        ESI
//         00461eae     POP        EBP
//         00461eaf     XOR        EAX,EAX
//         00461eb1     POP        EBX
//         00461eb2     ADD        ESP,0x8
//         00461eb5     RET
//         00461eb6     ??         90h
//         00461eb7     NOP
//         00461eb8     NOP
//         00461eb9     NOP
//         00461eba     NOP
//         00461ebb     NOP
//         00461ebc     NOP
//         00461ebd     NOP
//         00461ebe     NOP
//         00461ebf     NOP
    return 0;
}

void TMusic_System::close_mixer() {
    /* TODO: Stub */
//                              void __thiscall close_mixer(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?close_mixer@TMusic_System@@IAEXXZ                           XREF[2]:     close_device:00461cbb(c),
//                               TMusic_System::close_mixer                                                close_device:00461cef(c)
//                              music.cpp:357 (3)
//         00461ec0     PUSH       ESI
//         00461ec1     MOV        ESI,this
//                              music.cpp:358 (10)
//         00461ec3     MOV        EAX,dword ptr [ESI + 0x278]
//         00461ec9     TEST       EAX,EAX
//         00461ecb     JZ         LAB_00461ef2
//                              music.cpp:361 (10)
//         00461ecd     MOV        EAX,dword ptr [ESI + 0x27c]
//         00461ed3     TEST       EAX,EAX
//         00461ed5     JZ         LAB_00461ee8
//                              music.cpp:363 (7)
//         00461ed7     PUSH       EAX
//         00461ed8     CALL       dword ptr [->WINMM.DLL::mixerClose]              = 0048b530
//                              music.cpp:364 (10)
//         00461ede     MOV        dword ptr [ESI + 0x27c],0x0
//                               LAB_00461ee8                                                 XREF[1]:     00461ed5(j)
//                              music.cpp:367 (10)
//         00461ee8     MOV        dword ptr [ESI + 0x278],0x0
//                               LAB_00461ef2                                                 XREF[1]:     00461ecb(j)
//                              music.cpp:368 (2)
//         00461ef2     POP        ESI
//         00461ef3     RET
//         00461ef4     ??         90h
//         00461ef5     NOP
//         00461ef6     NOP
//         00461ef7     NOP
//         00461ef8     NOP
//         00461ef9     NOP
//         00461efa     NOP
//         00461efb     NOP
//         00461efc     NOP
//         00461efd     NOP
//         00461efe     NOP
//         00461eff     NOP
    return;
}

int TMusic_System::set_music_type(uchar param_1) {
    /* TODO: Stub */
//                              int __thiscall set_music_type(TMusic_System * this, uchar param_1)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00461f01(R)
//                               ?set_music_type@TMusic_System@@QAEHE@Z                       XREF[2]:     setup_music_system:0041f289(c),
//                               TMusic_System::set_music_type                                             setup_music_system:0041f297(c)
//                              music.cpp:372 (1)
//         00461f00     PUSH       EBX
//                              music.cpp:373 (15)
//         00461f01     MOV        BL,byte ptr [ESP + param_1]
//         00461f05     PUSH       ESI
//         00461f06     MOV        ESI,this
//         00461f08     CMP        BL,byte ptr [ESI + 0x104]
//         00461f0e     JNZ        LAB_00461f1b
//                              music.cpp:374 (6)
//         00461f10     MOV        EAX,dword ptr [ESI + 0x114]
//                              music.cpp:381 (5)
//         00461f16     POP        ESI
//         00461f17     POP        EBX
//         00461f18     RET        0x4
//                               LAB_00461f1b                                                 XREF[1]:     00461f0e(j)
//                              music.cpp:376 (7)
//         00461f1b     MOV        this,ESI
//         00461f1d     CALL       TMusic_System::close_device                      void close_device(TMusic_System * this)
//                              music.cpp:380 (13)
//         00461f22     MOV        this,ESI
//         00461f24     MOV        byte ptr [ESI + 0x104],BL
//         00461f2a     CALL       TMusic_System::open_device                       int open_device(TMusic_System * this)
//                              music.cpp:381 (5)
//         00461f2f     POP        ESI
//         00461f30     POP        EBX
//         00461f31     RET        0x4
//         00461f34     ??         90h
//         00461f35     NOP
//         00461f36     NOP
//         00461f37     NOP
//         00461f38     NOP
//         00461f39     NOP
//         00461f3a     NOP
//         00461f3b     NOP
//         00461f3c     NOP
//         00461f3d     NOP
//         00461f3e     NOP
//         00461f3f     NOP
    return 0;
}

void TMusic_System::set_fade_out(int param_1, ulong param_2) {
    /* TODO: Stub */
//                              void __thiscall set_fade_out(TMusic_System * this, int param_1, ulon
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00461f40(R)
//              ulong             Stack[0x8]:4   param_2                   XREF[1]:     00461f44(R)
//                               ?set_fade_out@TMusic_System@@QAEXHK@Z
//                               TMusic_System::set_fade_out
//                              music.cpp:385 (4)
//         00461f40     MOV        EAX,dword ptr [ESP + param_1]
//                              music.cpp:387 (16)
//         00461f44     MOV        EDX,dword ptr [ESP + param_2]
//         00461f48     MOV        dword ptr [ECX + this->fade_out],EAX
//         00461f4e     MOV        dword ptr [ECX + this->fade_time],EDX
//                              music.cpp:388 (3)
//         00461f54     RET        0x8
//         00461f57     ??         90h
//         00461f58     NOP
//         00461f59     NOP
//         00461f5a     NOP
//         00461f5b     NOP
//         00461f5c     NOP
//         00461f5d     NOP
//         00461f5e     NOP
//         00461f5f     NOP
    return;
}

void TMusic_System::set_volume(long param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall set_volume(TMusic_System * this, long param_1, int p
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00461f60(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00461f79(R)
//                               ?set_volume@TMusic_System@@QAEXJH@Z                          XREF[7]:     setup_music_system:0041f2a8(c),
//                               TMusic_System::set_volume                                                 action:0043c76e(c),
//                                                                                                         action:0043c85c(c),
//                                                                                                         close_device:00461caa(c),
//                                                                                                         close_device:00461cde(c),
//                                                                                                         do_fade:00462983(c),
//                                                                                                         end_fade:004629c6(c)
//                              music.cpp:393 (12)
//         00461f60     MOV        EAX,dword ptr [ESP + param_1]
//         00461f64     PUSH       ESI
//         00461f65     CMP        EAX,0xffffd8f0
//         00461f6a     JGE        LAB_00461f73
//                              music.cpp:398 (5)
//         00461f6c     MOV        EAX,0xffffd8f0
//                              music.cpp:399 (6)
//         00461f71     JMP        LAB_00461f79
//                               LAB_00461f73                                                 XREF[1]:     00461f6a(j)
//         00461f73     TEST       EAX,EAX
//         00461f75     JLE        LAB_00461f79
//                              music.cpp:400 (2)
//         00461f77     XOR        EAX,EAX
//                               LAB_00461f79                                                 XREF[2]:     00461f71(j), 00461f75(j)
//                              music.cpp:402 (8)
//         00461f79     MOV        EDX,dword ptr [ESP + param_2]
//         00461f7d     TEST       EDX,EDX
//         00461f7f     JZ         LAB_00461f87
//                              music.cpp:403 (6)
//         00461f81     MOV        dword ptr [ECX + this->volume],EAX
//                               LAB_00461f87                                                 XREF[1]:     00461f7f(j)
//                              music.cpp:405 (10)
//         00461f87     MOV        EDX,dword ptr [ECX + this->device_open]
//         00461f8d     TEST       EDX,EDX
//         00461f8f     JZ         LAB_00462008
//                              music.cpp:408 (17)
//         00461f91     XOR        EDX,EDX
//         00461f93     MOV        DL,byte ptr [ECX + this->music_type]
//         00461f99     DEC        EDX
//         00461f9a     JZ         LAB_00461fc2
//         00461f9c     DEC        EDX
//         00461f9d     JZ         LAB_00461fb6
//         00461f9f     DEC        EDX
//         00461fa0     JNZ        LAB_00462008
//                              music.cpp:432 (10)
//         00461fa2     MOV        this,dword ptr [ECX + this->sound_system]
//         00461fa8     TEST       this,this
//         00461faa     JZ         LAB_00462008
//                              music.cpp:433 (6)
//         00461fac     PUSH       EAX
//         00461fad     CALL       TSound_Driver::set_stream_volume                 int set_stream_volume(TSound_Driver * this, l
//                              music.cpp:448 (4)
//         00461fb2     POP        ESI
//         00461fb3     RET        0x8
//                               LAB_00461fb6                                                 XREF[1]:     00461f9d(j)
//                              music.cpp:422 (10)
//         00461fb6     MOV        EDX,dword ptr [ECX + this->mixer_open]
//         00461fbc     TEST       EDX,EDX
//         00461fbe     JZ         LAB_00462008
//                              music.cpp:429 (2)
//         00461fc0     JMP        LAB_00461fcc
//                               LAB_00461fc2                                                 XREF[1]:     00461f9a(j)
//                              music.cpp:412 (10)
//         00461fc2     MOV        EDX,dword ptr [ECX + this->mixer_open]
//         00461fc8     TEST       EDX,EDX
//         00461fca     JZ         LAB_00462008
//                               LAB_00461fcc                                                 XREF[1]:     00461fc0(j)
//                              music.cpp:416 (27)
//         00461fcc     MOV        EDX,dword ptr [ECX + this+0x3a8]
//         00461fd2     MOV        ESI,dword ptr [ECX + this+0x3a4]
//         00461fd8     SUB        EDX,ESI
//         00461fda     ADD        EAX,0x2710
//         00461fdf     IMUL       EDX,EAX
//         00461fe2     MOV        EAX,0xd1b71759
//                              music.cpp:417 (33)
//         00461fe7     PUSH       0x0
//         00461fe9     MUL        EDX
//         00461feb     SHR        EDX,0xd
//         00461fee     MOV        dword ptr [ECX + this->mixer_volume_value.dwVa
//         00461ff4     LEA        EAX,[ECX + this->mixer_volume_details.cbStruct]
//         00461ffa     MOV        this,dword ptr [ECX + this->mixer_handle]
//         00462000     PUSH       EAX
//         00462001     PUSH       this
//         00462002     CALL       dword ptr [->WINMM.DLL::mixerSetControlDetails]  = 0048b5a2
//                               LAB_00462008                                                 XREF[5]:     00461f8f(j), 00461fa0(j),
//                                                                                                         00461faa(j), 00461fbe(j),
//                                                                                                         00461fca(j)
//                              music.cpp:448 (4)
//         00462008     POP        ESI
//         00462009     RET        0x8
//         0046200c     ??         90h
//         0046200d     NOP
//         0046200e     NOP
//         0046200f     NOP
    return;
}

int TMusic_System::play_track(int param_1, int param_2, ulong param_3) {
    /* TODO: Stub */
//                              int __thiscall play_track(TMusic_System * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00462010(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00462020(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00462014(R)
//                               ?play_track@TMusic_System@@QAEHHHK@Z                         XREF[5]:     restart_music_system:0041fa1d(c),
//                               TMusic_System::play_track                                                 stop_video:00523e3c(c),
//                                                                                                         stop_video:00523e5a(c),
//                                                                                                         start_campaign_menu:00523fdb(c),
//                                                                                                         start_menu:005240fb(c)
//                              music.cpp:452 (4)
//         00462010     MOV        EAX,dword ptr [ESP + param_1]
//                              music.cpp:457 (4)
//         00462014     MOV        EDX,dword ptr [ESP + param_3]
//                              music.cpp:460 (75)
//         00462018     CMP        byte ptr [ECX + this->playing_track],0x0
//         0046201f     PUSH       ESI
//         00462020     MOV        ESI,dword ptr [ESP + param_2]
//         00462024     MOV        byte ptr [ECX + this->file_name[0]],0x0
//         0046202b     MOV        dword ptr [ECX + this->start_track],EAX
//         00462031     MOV        dword ptr [ECX + this->end_track],EAX
//         00462037     MOV        dword ptr [ECX + this->make_cur_track],0x0
//         00462041     MOV        dword ptr [ECX + this->set_pos],EDX
//         00462047     MOV        dword ptr [ECX + this->loop],ESI
//         0046204d     JZ         LAB_00462071
//         0046204f     MOV        ESI,dword ptr [ECX + this->fade_out]
//         00462055     TEST       ESI,ESI
//         00462057     JZ         LAB_00462071
//         00462059     MOV        ESI,dword ptr [ECX + this->fade_time]
//         0046205f     TEST       ESI,ESI
//         00462061     JBE        LAB_00462071
//                              music.cpp:462 (5)
//         00462063     CALL       TMusic_System::start_fade                        void start_fade(TMusic_System * this)
//                              music.cpp:463 (5)
//         00462068     MOV        EAX,0x1
//                              music.cpp:467 (4)
//         0046206d     POP        ESI
//         0046206e     RET        0xc
//                               LAB_00462071                                                 XREF[3]:     0046204d(j), 00462057(j),
//                                                                                                         00462061(j)
//                              music.cpp:466 (12)
//         00462071     PUSH       EDX
//         00462072     PUSH       0x0
//         00462074     PUSH       0x0
//         00462076     PUSH       EAX
//         00462077     PUSH       EAX
//         00462078     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                              music.cpp:467 (4)
//         0046207d     POP        ESI
//         0046207e     RET        0xc
//         00462081     ??         90h
//         00462082     NOP
//         00462083     NOP
//         00462084     NOP
//         00462085     NOP
//         00462086     NOP
//         00462087     NOP
//         00462088     NOP
//         00462089     NOP
//         0046208a     NOP
//         0046208b     NOP
//         0046208c     NOP
//         0046208d     NOP
//         0046208e     NOP
//         0046208f     NOP
    return 0;
}

int TMusic_System::play_file(char* param_1, int param_2, ulong param_3) {
    /* TODO: Stub */
//                              int __thiscall play_file(TMusic_System * this, char * param_1, int p
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004620a6(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004620d1(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004620c8(R)
//                               ?play_file@TMusic_System@@QAEHPADHK@Z                        XREF[5]:     restart_music_system:0041fa77(c),
//                               TMusic_System::play_file                                                  stop_video:00523e95(c),
//                                                                                                         stop_video:00523eb6(c),
//                                                                                                         start_campaign_menu:00523ffe(c),
//                                                                                                         start_menu:0052411e(c)
//                              music.cpp:471 (5)
//         00462090     MOV        EDX,this
//         00462092     PUSH       EBX
//         00462093     PUSH       ESI
//         00462094     PUSH       EDI
//                              music.cpp:472 (9)
//         00462095     CMP        byte ptr [EDX + 0x104],0x1
//         0046209c     JNZ        LAB_004620a6
//                              music.cpp:473 (2)
//         0046209e     XOR        EAX,EAX
//                              music.cpp:489 (6)
//         004620a0     POP        EDI
//         004620a1     POP        ESI
//         004620a2     POP        EBX
//         004620a3     RET        0xc
//                               LAB_004620a6                                                 XREF[1]:     0046209c(j)
//                              music.cpp:475 (34)
//         004620a6     MOV        EDI,dword ptr [ESP + param_1]
//         004620aa     OR         this,0xffffffff
//         004620ad     XOR        EAX,EAX
//         004620af     LEA        EBX,[EDX + 0x129]
//         004620b5     SCASB.RE   ES:EDI
//         004620b7     NOT        this
//         004620b9     SUB        EDI,this
//         004620bb     MOV        EAX,this
//         004620bd     MOV        ESI,EDI
//         004620bf     MOV        EDI,EBX
//         004620c1     SHR        this,0x2
//         004620c4     MOVSD.REP  ES:EDI,ESI
//         004620c6     MOV        this,EAX
//                              music.cpp:479 (9)
//         004620c8     MOV        EAX,dword ptr [ESP + param_3]
//         004620cc     AND        this,0x3
//         004620cf     MOVSB.REP  ES:EDI,ESI
//                              music.cpp:480 (6)
//         004620d1     MOV        ESI,dword ptr [ESP + param_2]
//         004620d5     XOR        this,this
//                              music.cpp:482 (54)
//         004620d7     CMP        byte ptr [EDX + 0x128],this
//         004620dd     MOV        dword ptr [EDX + 0x230],this
//         004620e3     MOV        dword ptr [EDX + 0x234],this
//         004620e9     MOV        dword ptr [EDX + 0x238],this
//         004620ef     MOV        dword ptr [EDX + 0x23c],EAX
//         004620f5     MOV        dword ptr [EDX + 0x240],ESI
//         004620fb     JZ         LAB_0046211f
//         004620fd     CMP        dword ptr [EDX + 0x264],this
//         00462103     JZ         LAB_0046211f
//         00462105     CMP        dword ptr [EDX + 0x268],this
//         0046210b     JBE        LAB_0046211f
//                              music.cpp:484 (7)
//         0046210d     MOV        this,EDX
//         0046210f     CALL       TMusic_System::start_fade                        void start_fade(TMusic_System * this)
//                              music.cpp:485 (5)
//         00462114     MOV        EAX,0x1
//                              music.cpp:489 (6)
//         00462119     POP        EDI
//         0046211a     POP        ESI
//         0046211b     POP        EBX
//         0046211c     RET        0xc
//                               LAB_0046211f                                                 XREF[3]:     004620fb(j), 00462103(j),
//                                                                                                         0046210b(j)
//                              music.cpp:488 (12)
//         0046211f     PUSH       EAX
//         00462120     PUSH       this
//         00462121     PUSH       EBX
//         00462122     PUSH       this
//         00462123     PUSH       this
//         00462124     MOV        this,EDX
//         00462126     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                              music.cpp:489 (6)
//         0046212b     POP        EDI
//         0046212c     POP        ESI
//         0046212d     POP        EBX
//         0046212e     RET        0xc
//         00462131     ??         90h
//         00462132     NOP
//         00462133     NOP
//         00462134     NOP
//         00462135     NOP
//         00462136     NOP
//         00462137     NOP
//         00462138     NOP
//         00462139     NOP
//         0046213a     NOP
//         0046213b     NOP
//         0046213c     NOP
//         0046213d     NOP
//         0046213e     NOP
//         0046213f     NOP
    return 0;
}

int TMusic_System::play_tracks(int param_1, int param_2, int param_3, int param_4, ulong param_5) {
    /* TODO: Stub */
//                              int __thiscall play_tracks(TMusic_System * this, int param_1, int pa
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0046214e(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00462144(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00462140(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0046215f(R)
//              ulong             Stack[0x14]:4  param_5                   XREF[1]:     00462149(R)
//                               ?play_tracks@TMusic_System@@QAEHHHHHK@Z                      XREF[6]:     restart_music_system:0041fa4a(c),
//                               TMusic_System::play_tracks                                                action:0043c5d8(c),
//                                                                                                         TRIBE_Credits_Screen:00492931(c),
//                                                                                                         ~TRIBE_Credits_Screen:00492a19(c),
//                                                                                                         let_game_begin:00528cae(c),
//                                                                                                         let_game_begin:00528cc6(c)
//                              music.cpp:493 (24)
//         00462140     MOV        EAX,dword ptr [ESP + param_3]
//         00462144     MOV        EDX,dword ptr [ESP + param_2]
//         00462148     PUSH       EBX
//         00462149     MOV        EBX,dword ptr [ESP + param_5]
//         0046214d     PUSH       ESI
//         0046214e     MOV        ESI,dword ptr [ESP + param_1]
//         00462152     MOV        dword ptr [ECX + this->loop],EAX
//                              music.cpp:501 (46)
//         00462158     MOV        EAX,dword ptr [ECX + this->track_count]
//         0046215e     PUSH       EDI
//         0046215f     MOV        EDI,dword ptr [ESP + param_4]
//         00462163     TEST       EAX,EAX
//         00462165     MOV        byte ptr [ECX + this->file_name[0]],0x0
//         0046216c     MOV        dword ptr [ECX + this->start_track],ESI
//         00462172     MOV        dword ptr [ECX + this->end_track],EDX
//         00462178     MOV        dword ptr [ECX + this->make_cur_track],EDI
//         0046217e     MOV        dword ptr [ECX + this->set_pos],EBX
//         00462184     JNZ        LAB_0046218c
//                              music.cpp:519 (6)
//         00462186     POP        EDI
//         00462187     POP        ESI
//         00462188     POP        EBX
//         00462189     RET        0x14
//                               LAB_0046218c                                                 XREF[1]:     00462184(j)
//                              music.cpp:504 (4)
//         0046218c     CMP        ESI,EAX
//         0046218e     JLE        LAB_00462196
//                              music.cpp:505 (6)
//         00462190     MOV        dword ptr [ECX + this->start_track],EAX
//                               LAB_00462196                                                 XREF[1]:     0046218e(j)
//                              music.cpp:507 (10)
//         00462196     MOV        ESI,dword ptr [ECX + this->start_track]
//         0046219c     CMP        EDX,ESI
//         0046219e     JGE        LAB_004621a8
//                              music.cpp:508 (6)
//         004621a0     MOV        dword ptr [ECX + this->end_track],ESI
//                              music.cpp:509 (6)
//         004621a6     JMP        LAB_004621b2
//                               LAB_004621a8                                                 XREF[1]:     0046219e(j)
//         004621a8     CMP        EDX,EAX
//         004621aa     JLE        LAB_004621b2
//                              music.cpp:510 (6)
//         004621ac     MOV        dword ptr [ECX + this->end_track],EAX
//                               LAB_004621b2                                                 XREF[2]:     004621a6(j), 004621aa(j)
//                              music.cpp:512 (30)
//         004621b2     MOV        AL,byte ptr [ECX + this->playing_track]
//         004621b8     TEST       AL,AL
//         004621ba     JZ         LAB_004621e0
//         004621bc     MOV        EAX,dword ptr [ECX + this->fade_out]
//         004621c2     TEST       EAX,EAX
//         004621c4     JZ         LAB_004621e0
//         004621c6     MOV        EAX,dword ptr [ECX + this->fade_time]
//         004621cc     TEST       EAX,EAX
//         004621ce     JBE        LAB_004621e0
//                              music.cpp:514 (5)
//         004621d0     CALL       TMusic_System::start_fade                        void start_fade(TMusic_System * this)
//                              music.cpp:515 (5)
//         004621d5     MOV        EAX,0x1
//                              music.cpp:519 (6)
//         004621da     POP        EDI
//         004621db     POP        ESI
//         004621dc     POP        EBX
//         004621dd     RET        0x14
//                               LAB_004621e0                                                 XREF[3]:     004621ba(j), 004621c4(j),
//                                                                                                         004621ce(j)
//                              music.cpp:518 (17)
//         004621e0     MOV        EDX,dword ptr [ECX + this->end_track]
//         004621e6     PUSH       EBX
//         004621e7     PUSH       EDI
//         004621e8     PUSH       0x0
//         004621ea     PUSH       EDX
//         004621eb     PUSH       ESI
//         004621ec     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                              music.cpp:519 (6)
//         004621f1     POP        EDI
//         004621f2     POP        ESI
//         004621f3     POP        EBX
//         004621f4     RET        0x14
//         004621f7     ??         90h
//         004621f8     NOP
//         004621f9     NOP
//         004621fa     NOP
//         004621fb     NOP
//         004621fc     NOP
//         004621fd     NOP
//         004621fe     NOP
//         004621ff     NOP
    return 0;
}

int TMusic_System::play(int param_1, int param_2, char* param_3, int param_4, ulong param_5) {
    /* TODO: Stub */
//                              int __thiscall play(TMusic_System * this, int param_1, int param_2,
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     00462247(R), 00462279(R), 004624cf(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004624f5(R)
//              char *            Stack[0xc]:4   param_3                   XREF[1]:     00462229(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0046225e(R)
//              ulong             Stack[0x14]:4  param_5                   XREF[2]:     0046241a(R), 0046248a(R)
//              char[256]         Stack[-0x104   szErrorMsg                XREF[0,2]:   004623cd(*), 0046253a(*)
//              char[261]         Stack[-0x20c   track_name                XREF[0,9]:   004622b2(*), 004622c4(*), 004622de(*), 00462310(*),
//                                                                                     00462322(*), 00462343(*), 00462369(*), 0046237d(*),
//                                                                                     004623a8(*)
//              tagMCI_OPEN_PA    Stack[-0x220   open_info                 XREF[2,4]:   0046242f(W), 004624b2(W), 004623a4(*), 00462421(R),
//                                                                                     004623b9(W), 004623c1(W)
//              tagMCI_SEEK_PA    Stack[-0x228   seek_info                 XREF[0,4]:   00462433(*), 00462440(W), 004624ae(*), 004624c5(W)
//                               ?play@TMusic_System@@IAEHHHPADHK@Z                           XREF[8]:     play_track:00462078(c),
//                               TMusic_System::play                                                       play_file:00462126(c),
//                                                                                                         play_tracks:004621ec(c),
//                                                                                                         end_fade:00462a08(c),
//                                                                                                         after_end_track:00462b92(c),
//                                                                                                         after_end_track:00462bcd(c),
//                                                                                                         after_end_track:00462bec(c),
//                                                                                                         after_end_track:00462c1c(c)
//                              music.cpp:523 (12)
//         00462200     SUB        ESP,0x224
//         00462206     PUSH       EBX
//         00462207     PUSH       EBP
//         00462208     MOV        EBP,this
//         0046220a     PUSH       ESI
//         0046220b     PUSH       EDI
//                              music.cpp:530 (8)
//         0046220c     MOV        EAX,dword ptr [EBP + 0x114]
//         00462212     TEST       EAX,EAX
//                              music.cpp:531 (6)
//         00462214     JZ         LAB_004625a9
//                              music.cpp:533 (10)
//         0046221a     MOV        AL,byte ptr [EBP + 0x128]
//         00462220     TEST       AL,AL
//         00462222     JZ         LAB_00462229
//                              music.cpp:534 (5)
//         00462224     CALL       TMusic_System::stop_playing                      int stop_playing(TMusic_System * this)
//                               LAB_00462229                                                 XREF[1]:     00462222(j)
//                              music.cpp:536 (16)
//         00462229     MOV        this,dword ptr [ESP + param_3]
//         00462230     TEST       this,this
//         00462232     JZ         LAB_00462239
//         00462234     CMP        byte ptr [this->path[0]],0x0
//         00462237     JNZ        LAB_00462279
//                               LAB_00462239                                                 XREF[1]:     00462232(j)
//                              music.cpp:539 (8)
//         00462239     MOV        EAX,dword ptr [EBP + 0x248]
//         0046223f     TEST       EAX,EAX
//                              music.cpp:540 (6)
//         00462241     JZ         LAB_004625a9
//                              music.cpp:542 (23)
//         00462247     MOV        EDX,dword ptr [ESP + param_1]
//         0046224e     CMP        EDX,EAX
//         00462250     JG         LAB_004625a9
//         00462256     TEST       EDX,EDX
//         00462258     JZ         LAB_004625a9
//                              music.cpp:545 (11)
//         0046225e     MOV        EAX,dword ptr [ESP + param_4]
//         00462265     TEST       EAX,EAX
//         00462267     JZ         LAB_00462271
//                              music.cpp:546 (6)
//         00462269     MOV        dword ptr [EBP + 0x244],EAX
//                              music.cpp:547 (2)
//         0046226f     JMP        LAB_00462280
//                               LAB_00462271                                                 XREF[1]:     00462267(j)
//                              music.cpp:548 (15)
//         00462271     MOV        dword ptr [EBP + 0x244],EDX
//         00462277     JMP        LAB_00462280
//                               LAB_00462279                                                 XREF[1]:     00462237(j)
//         00462279     MOV        EDX,dword ptr [ESP + param_1]
//                               LAB_00462280                                                 XREF[2]:     0046226f(j), 00462277(j)
//                              music.cpp:551 (25)
//         00462280     XOR        EAX,EAX
//         00462282     MOV        AL,byte ptr [EBP + 0x104]
//         00462288     DEC        EAX
//         00462289     JZ         LAB_0046248a
//         0046228f     DEC        EAX
//         00462290     JZ         LAB_00462305
//         00462292     DEC        EAX
//         00462293     JNZ        LAB_00462579
//                              music.cpp:670 (14)
//         00462299     MOV        EAX,dword ptr [EBP + 0x108]
//         0046229f     TEST       EAX,EAX
//         004622a1     JZ         LAB_00462579
//                              music.cpp:672 (9)
//         004622a7     TEST       this,this
//         004622a9     JZ         LAB_004622be
//         004622ab     CMP        byte ptr [this->path[0]],0x0
//         004622ae     JZ         LAB_004622be
//                              music.cpp:676 (14)
//         004622b0     PUSH       this
//         004622b1     PUSH       EBP
//         004622b2     LEA        EAX=>track_name[4],[ESP + 0x34]
//         004622b6     PUSH       s_%s%s                                           = "%s%s"
//         004622bb     PUSH       EAX
//         004622bc     JMP        LAB_004622d0
//                               LAB_004622be                                                 XREF[2]:     004622a9(j), 004622ae(j)
//                              music.cpp:673 (23)
//         004622be     MOV        this,dword ptr [EBP + 0x244]
//         004622c4     LEA        EDX=>track_name[4],[ESP + 0x2c]
//         004622c8     PUSH       this
//         004622c9     PUSH       EBP
//         004622ca     PUSH       s_%smusic%d.wav                                  = "%smusic%d.wav"
//         004622cf     PUSH       EDX
//                               LAB_004622d0                                                 XREF[1]:     004622bc(j)
//         004622d0     CALL       sprintf                                          undefined sprintf()
//                              music.cpp:680 (30)
//         004622d5     MOV        EAX,dword ptr [EBP + 0x254]
//         004622db     ADD        ESP,0x10
//         004622de     LEA        this=>track_name[4],[ESP + 0x2c]
//         004622e2     PUSH       EAX
//         004622e3     PUSH       0x0
//         004622e5     PUSH       this
//         004622e6     MOV        this,dword ptr [EBP + 0x108]
//         004622ec     CALL       TSound_Driver::stream_file                       int stream_file(TSound_Driver * this, char *
//         004622f1     TEST       EAX,EAX
//                              music.cpp:681 (6)
//         004622f3     JZ         LAB_004625a9
//                              music.cpp:682 (7)
//         004622f9     MOV        byte ptr [EBP + 0x128],0x1
//                              music.cpp:683 (5)
//         00462300     JMP        LAB_00462579
//                               LAB_00462305                                                 XREF[1]:     00462290(j)
//                              music.cpp:593 (9)
//         00462305     TEST       this,this
//         00462307     JZ         LAB_00462363
//         00462309     CMP        byte ptr [this->path[0]],0x0
//         0046230c     JZ         LAB_00462363
//                              music.cpp:597 (20)
//         0046230e     PUSH       this
//         0046230f     PUSH       EBP
//         00462310     LEA        EDX=>track_name[4],[ESP + 0x34]
//         00462314     PUSH       s_%s%s                                           = "%s%s"
//         00462319     PUSH       EDX
//         0046231a     CALL       sprintf                                          undefined sprintf()
//         0046231f     ADD        ESP,0x10
//                              music.cpp:598 (19)
//         00462322     LEA        EAX=>track_name[4],[ESP + 0x2c]
//         00462326     PUSH       0x2e
//         00462328     PUSH       EAX
//         00462329     CALL       strchr                                           undefined strchr()
//         0046232e     ADD        ESP,0x8
//         00462331     TEST       EAX,EAX
//         00462333     JNZ        LAB_0046237d
//                              music.cpp:599 (46)
//         00462335     MOV        EDI,s_.mid                                       = 2Eh
//         0046233a     OR         this,0xffffffff
//         0046233d     SCASB.RE   ES:EDI=>s_.mid                                   = 2Eh
//                                                                                  = 0064696d
//         0046233f     NOT        this
//         00462341     SUB        EDI,this
//         00462343     LEA        EDX=>track_name[4],[ESP + 0x2c]
//         00462347     MOV        ESI,EDI
//         00462349     MOV        EBX,this
//         0046234b     MOV        EDI,EDX
//         0046234d     OR         this,0xffffffff
//         00462350     SCASB.RE   ES:EDI
//         00462352     MOV        this,EBX
//         00462354     DEC        EDI
//         00462355     SHR        this,0x2
//         00462358     MOVSD.REP  ES:EDI,ESI
//         0046235a     MOV        this,EBX
//         0046235c     AND        this,0x3
//         0046235f     MOVSB.REP  ES:EDI,ESI
//         00462361     JMP        LAB_0046237d
//                               LAB_00462363                                                 XREF[2]:     00462307(j), 0046230c(j)
//                              music.cpp:594 (26)
//         00462363     MOV        EAX,dword ptr [EBP + 0x244]
//         00462369     LEA        this=>track_name[4],[ESP + 0x2c]
//         0046236d     PUSH       EAX
//         0046236e     PUSH       EBP
//         0046236f     PUSH       s_%smusic%d.mid                                  = "%smusic%d.mid"
//         00462374     PUSH       this
//         00462375     CALL       sprintf                                          undefined sprintf()
//         0046237a     ADD        ESP,0x10
//                               LAB_0046237d                                                 XREF[2]:     00462333(j), 00462361(j)
//                              music.cpp:603 (15)
//         0046237d     LEA        EDX=>track_name[4],[ESP + 0x2c]
//         00462381     PUSH       0x0
//         00462383     PUSH       EDX
//         00462384     CALL       __open                                           undefined __open()
//         00462389     ADD        ESP,0x8
//                              music.cpp:604 (9)
//         0046238c     CMP        EAX,-0x1
//         0046238f     JZ         LAB_00462579
//                              music.cpp:606 (6)
//         00462395     PUSH       EAX
//         00462396     CALL       close                                            undefined close()
//                              music.cpp:610 (46)
//         0046239b     MOV        ESI,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
//         004623a1     ADD        ESP,0x4
//         004623a4     LEA        this=>open_info.wDeviceID,[ESP + 0x18]
//         004623a8     LEA        EAX=>track_name[4],[ESP + 0x2c]
//         004623ac     PUSH       this
//         004623ad     PUSH       0x3200
//         004623b2     PUSH       0x803
//         004623b7     PUSH       0x0
//         004623b9     MOV        dword ptr [ESP + open_info.lpstrElementName],0
//         004623c1     MOV        dword ptr [ESP + open_info.lpstrAlias],EAX
//         004623c5     CALL       ESI=>WINMM.DLL::mciSendCommandA
//         004623c7     MOV        EBX,EAX
//                              music.cpp:611 (4)
//         004623c9     TEST       EBX,EBX
//         004623cb     JZ         LAB_0046241a
//                              music.cpp:614 (24)
//         004623cd     LEA        EDX=>szErrorMsg[4],[ESP + 0x134]
//         004623d4     PUSH       0x100
//         004623d9     PUSH       EDX
//         004623da     PUSH       EBX
//         004623db     CALL       dword ptr [->WINMM.DLL::mciGetErrorStringA]      = 0048b444
//         004623e1     TEST       EAX,EAX
//         004623e3     JNZ        LAB_00462412
//                              music.cpp:615 (45)
//         004623e5     MOV        EDI,s_Unknow_Error                               = 55h
//         004623ea     OR         this,0xffffffff
//         004623ed     SCASB.RE   ES:EDI=>s_Unknow_Error                           = 55h
//                                                                                  = "nknow Error"
//         004623ef     NOT        this
//         004623f1     SUB        EDI,this
//         004623f3     LEA        EDX,[ESP + 0x134]
//         004623fa     MOV        EAX,this
//         004623fc     MOV        ESI,EDI
//         004623fe     MOV        EDI,EDX
//         00462400     SHR        this,0x2
//         00462403     MOVSD.REP  ES:EDI,ESI
//         00462405     MOV        this,EAX
//         00462407     AND        this,0x3
//         0046240a     MOVSB.REP  ES:EDI,ESI
//         0046240c     MOV        ESI,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
//                               LAB_00462412                                                 XREF[1]:     004623e3(j)
//                              music.cpp:620 (8)
//         00462412     TEST       EBX,EBX
//         00462414     JNZ        LAB_00462579
//                               LAB_0046241a                                                 XREF[1]:     004623cb(j)
//                              music.cpp:625 (21)
//         0046241a     MOV        this,dword ptr [ESP + param_5]
//         00462421     MOV        EAX,dword ptr [ESP + open_info.lpstrDeviceType]
//         00462425     TEST       this,this
//         00462427     MOV        dword ptr [EBP + 0x118],EAX
//         0046242d     JBE        LAB_0046244a
//                              music.cpp:629 (4)
//         0046242f     MOV        dword ptr [ESP + open_info.dwCallback],this
//                              music.cpp:630 (23)
//         00462433     LEA        this=>seek_info.dwTo,[ESP + 0x10]
//         00462437     PUSH       this
//         00462438     PUSH       0x8
//         0046243a     PUSH       0x807
//         0046243f     PUSH       EAX
//         00462440     MOV        dword ptr [ESP + seek_info.dwTo],0x0
//         00462448     CALL       ESI=>WINMM.DLL::mciSendCommandA
//                               LAB_0046244a                                                 XREF[1]:     0046242d(j)
//                              music.cpp:634 (12)
//         0046244a     MOV        EDX,dword ptr [EBP + 0x110]
//         00462450     LEA        EAX,[EBP + 0x11c]
//                              music.cpp:636 (19)
//         00462456     PUSH       EAX
//         00462457     PUSH       0x1
//         00462459     MOV        dword ptr [EAX],EDX
//         0046245b     MOV        EAX,dword ptr [EBP + 0x118]
//         00462461     PUSH       0x806
//         00462466     PUSH       EAX
//         00462467     CALL       ESI=>WINMM.DLL::mciSendCommandA
//                              music.cpp:637 (8)
//         00462469     TEST       EAX,EAX
//         0046246b     JNZ        LAB_00462579
//                              music.cpp:639 (6)
//         00462471     MOV        EAX,dword ptr [EBP + 0x24c]
//                              music.cpp:640 (14)
//         00462477     MOV        byte ptr [EBP + 0x128],0x1
//         0046247e     INC        EAX
//         0046247f     MOV        dword ptr [EBP + 0x24c],EAX
//                              music.cpp:641 (5)
//         00462485     JMP        LAB_00462579
//                               LAB_0046248a                                                 XREF[1]:     00462289(j)
//                              music.cpp:557 (36)
//         0046248a     MOV        EAX,dword ptr [ESP + param_5]
//         00462491     MOV        this,dword ptr [EBP + 0x110]
//         00462497     MOV        EBX,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
//         0046249d     LEA        EDI,[EBP + 0x11c]
//         004624a3     TEST       EAX,EAX
//         004624a5     MOV        dword ptr [EDI],this
//         004624a7     MOV        ESI,0x1
//         004624ac     JBE        LAB_004624d8
//                              music.cpp:562 (33)
//         004624ae     LEA        EDX=>seek_info.dwTo,[ESP + 0x10]
//         004624b2     MOV        dword ptr [ESP + open_info.dwCallback],EAX
//         004624b6     MOV        EAX,dword ptr [EBP + 0x118]
//         004624bc     PUSH       EDX
//         004624bd     PUSH       0xa
//         004624bf     PUSH       0x807
//         004624c4     PUSH       EAX
//         004624c5     MOV        dword ptr [ESP + seek_info.dwTo],0x0
//         004624cd     CALL       EBX=>WINMM.DLL::mciSendCommandA
//                              music.cpp:564 (9)
//         004624cf     MOV        EDX,dword ptr [ESP + param_1]
//         004624d6     JMP        LAB_004624eb
//                               LAB_004624d8                                                 XREF[1]:     004624ac(j)
//                              music.cpp:567 (19)
//         004624d8     XOR        this,this
//         004624da     MOV        ESI,0x5
//         004624df     MOV        this,byte ptr [EBP + 0x244]
//         004624e5     MOV        dword ptr [EBP + 0x120],this
//                               LAB_004624eb                                                 XREF[1]:     004624d6(j)
//                              music.cpp:570 (21)
//         004624eb     MOV        this,dword ptr [EBP + 0x248]
//         004624f1     CMP        EDX,this
//         004624f3     JGE        LAB_00462510
//         004624f5     MOV        EAX,dword ptr [ESP + param_2]
//         004624fc     CMP        EAX,this
//         004624fe     JGE        LAB_00462510
//                              music.cpp:572 (3)
//         00462500     OR         ESI,0x8
//                              music.cpp:573 (13)
//         00462503     INC        AL
//         00462505     AND        EAX,0xff
//         0046250a     MOV        dword ptr [EBP + 0x124],EAX
//                               LAB_00462510                                                 XREF[2]:     004624f3(j), 004624fe(j)
//                              music.cpp:576 (16)
//         00462510     MOV        EDX,dword ptr [EBP + 0x118]
//         00462516     PUSH       EDI
//         00462517     PUSH       ESI
//         00462518     PUSH       0x806
//         0046251d     PUSH       EDX
//         0046251e     CALL       EBX=>WINMM.DLL::mciSendCommandA
//                              music.cpp:577 (4)
//         00462520     TEST       EAX,EAX
//         00462522     JNZ        LAB_0046253a
//                              music.cpp:579 (6)
//         00462524     MOV        EAX,dword ptr [EBP + 0x24c]
//                              music.cpp:580 (14)
//         0046252a     MOV        byte ptr [EBP + 0x128],0x1
//         00462531     INC        EAX
//         00462532     MOV        dword ptr [EBP + 0x24c],EAX
//                              music.cpp:581 (2)
//         00462538     JMP        LAB_00462579
//                               LAB_0046253a                                                 XREF[1]:     00462522(j)
//                              music.cpp:586 (24)
//         0046253a     LEA        this=>szErrorMsg[4],[ESP + 0x134]
//         00462541     PUSH       0x100
//         00462546     PUSH       this
//         00462547     PUSH       EAX
//         00462548     CALL       dword ptr [->WINMM.DLL::mciGetErrorStringA]      = 0048b444
//         0046254e     TEST       EAX,EAX
//         00462550     JNZ        LAB_00462579
//                              music.cpp:587 (39)
//         00462552     MOV        EDI,s_Unknow_Error                               = 55h
//         00462557     OR         this,0xffffffff
//         0046255a     SCASB.RE   ES:EDI=>s_Unknow_Error                           = 55h
//                                                                                  = "nknow Error"
//         0046255c     NOT        this
//         0046255e     SUB        EDI,this
//         00462560     LEA        EDX,[ESP + 0x134]
//         00462567     MOV        EAX,this
//         00462569     MOV        ESI,EDI
//         0046256b     MOV        EDI,EDX
//         0046256d     SHR        this,0x2
//         00462570     MOVSD.REP  ES:EDI,ESI
//         00462572     MOV        this,EAX
//         00462574     AND        this,0x3
//         00462577     MOVSB.REP  ES:EDI,ESI
//                               LAB_00462579                                                 XREF[9]:     00462293(j), 004622a1(j),
//                                                                                                         00462300(j), 0046238f(j),
//                                                                                                         00462414(j), 0046246b(j),
//                                                                                                         00462485(j), 00462538(j),
//                                                                                                         00462550(j)
//                              music.cpp:719 (10)
//         00462579     MOV        AL,byte ptr [EBP + 0x128]
//         0046257f     TEST       AL,AL
//         00462581     JZ         LAB_004625a9
//                              music.cpp:721 (8)
//         00462583     XOR        EAX,EAX
//         00462585     MOV        dword ptr [EBP + 0x258],EAX
//                              music.cpp:722 (6)
//         0046258b     MOV        dword ptr [EBP + 0x25c],EAX
//                              music.cpp:723 (6)
//         00462591     MOV        dword ptr [EBP + 0x260],EAX
//                              music.cpp:724 (5)
//         00462597     MOV        EAX,0x1
//                              music.cpp:728 (28)
//         0046259c     POP        EDI
//         0046259d     POP        ESI
//         0046259e     POP        EBP
//         0046259f     POP        EBX
//         004625a0     ADD        ESP,0x224
//         004625a6     RET        0x14
//                               LAB_004625a9                                                 XREF[6]:     00462214(j), 00462241(j),
//                                                                                                         00462250(j), 00462258(j),
//                                                                                                         004622f3(j), 00462581(j)
//         004625a9     POP        EDI
//         004625aa     POP        ESI
//         004625ab     POP        EBP
//         004625ac     XOR        EAX,EAX
//         004625ae     POP        EBX
//         004625af     ADD        ESP,0x224
//         004625b5     RET        0x14
//         004625b8     ??         90h
//         004625b9     NOP
//         004625ba     NOP
//         004625bb     NOP
//         004625bc     NOP
//         004625bd     NOP
//         004625be     NOP
//         004625bf     NOP
    return 0;
}

int TMusic_System::pause_play() {
    /* TODO: Stub */
//                              int __thiscall pause_play(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?pause_play@TMusic_System@@QAEHXZ                            XREF[1]:     handle_messages:00462a7a(c)
//                               TMusic_System::pause_play
//                              music.cpp:732 (28)
//         004625c0     MOV        EAX,dword ptr [ECX + this->device_open]
//         004625c6     XOR        EDX,EDX
//         004625c8     CMP        EAX,EDX
//         004625ca     JZ         LAB_0046266c
//         004625d0     CMP        byte ptr [ECX + this->playing_track],DL
//         004625d6     JZ         LAB_0046266c
//                              music.cpp:738 (8)
//         004625dc     CMP        dword ptr [ECX + this->paused],EDX
//         004625e2     JZ         LAB_004625f0
//                              music.cpp:740 (6)
//         004625e4     MOV        dword ptr [ECX + this->auto_paused],EDX
//                              music.cpp:741 (5)
//         004625ea     MOV        EAX,0x1
//                              music.cpp:775 (1)
//         004625ef     RET
//                               LAB_004625f0                                                 XREF[1]:     004625e2(j)
//                              music.cpp:744 (6)
//         004625f0     MOV        EAX,dword ptr [ECX + this->auto_paused]
//                              music.cpp:746 (14)
//         004625f6     MOV        dword ptr [ECX + this->paused],0x1
//         00462600     CMP        EAX,EDX
//         00462602     JZ         LAB_00462610
//                              music.cpp:747 (6)
//         00462604     MOV        dword ptr [ECX + this->auto_paused],EDX
//                              music.cpp:748 (5)
//         0046260a     MOV        EAX,0x1
//                              music.cpp:775 (1)
//         0046260f     RET
//                               LAB_00462610                                                 XREF[1]:     00462602(j)
//                              music.cpp:753 (17)
//         00462610     XOR        EAX,EAX
//         00462612     MOV        AL,byte ptr [ECX + this->music_type]
//         00462618     DEC        EAX
//         00462619     JZ         LAB_00462651
//         0046261b     DEC        EAX
//         0046261c     JZ         LAB_00462636
//         0046261e     DEC        EAX
//         0046261f     JNZ        LAB_00462666
//                              music.cpp:766 (10)
//         00462621     MOV        this,dword ptr [ECX + this->sound_system]
//         00462627     CMP        this,EDX
//         00462629     JZ         LAB_00462666
//                              music.cpp:767 (5)
//         0046262b     CALL       TSound_Driver::pause_stream                      int pause_stream(TSound_Driver * this)
//                              music.cpp:774 (5)
//         00462630     MOV        EAX,0x1
//                              music.cpp:775 (1)
//         00462635     RET
//                               LAB_00462636                                                 XREF[1]:     0046261c(j)
//                              music.cpp:761 (21)
//         00462636     MOV        EAX,dword ptr [ECX + this->device_id]
//         0046263c     PUSH       EDX
//         0046263d     PUSH       0x2
//         0046263f     PUSH       0x809
//         00462644     PUSH       EAX
//         00462645     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:774 (5)
//         0046264b     MOV        EAX,0x1
//                              music.cpp:775 (1)
//         00462650     RET
//                               LAB_00462651                                                 XREF[1]:     00462619(j)
//                              music.cpp:757 (21)
//         00462651     MOV        this,dword ptr [ECX + this->device_id]
//         00462657     PUSH       EDX
//         00462658     PUSH       0x2
//         0046265a     PUSH       0x809
//         0046265f     PUSH       this
//         00462660     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                               LAB_00462666                                                 XREF[2]:     0046261f(j), 00462629(j)
//                              music.cpp:774 (5)
//         00462666     MOV        EAX,0x1
//                              music.cpp:775 (1)
//         0046266b     RET
//                               LAB_0046266c                                                 XREF[2]:     004625ca(j), 004625d6(j)
//                              music.cpp:736 (2)
//         0046266c     XOR        EAX,EAX
//                              music.cpp:775 (1)
//         0046266e     RET
//         0046266f     ??         90h
    return 0;
}

int TMusic_System::resume_play() {
    /* TODO: Stub */
//                              int __thiscall resume_play(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?resume_play@TMusic_System@@QAEHXZ                           XREF[1]:     handle_messages:00462a51(c)
//                               TMusic_System::resume_play
//                              music.cpp:779 (3)
//         00462670     PUSH       ESI
//         00462671     MOV        ESI,this
//                              music.cpp:782 (42)
//         00462673     MOV        EAX,dword ptr [ESI + 0x114]
//         00462679     TEST       EAX,EAX
//         0046267b     JZ         LAB_0046273b
//         00462681     MOV        AL,byte ptr [ESI + 0x128]
//         00462687     TEST       AL,AL
//         00462689     JZ         LAB_0046273b
//         0046268f     MOV        EAX,dword ptr [ESI + 0x258]
//         00462695     TEST       EAX,EAX
//         00462697     JZ         LAB_0046273b
//                              music.cpp:788 (30)
//         0046269d     MOV        EAX,dword ptr [ESI + 0x26c]
//         004626a3     MOV        dword ptr [ESI + 0x258],0x0
//         004626ad     TEST       EAX,EAX
//         004626af     MOV        dword ptr [ESI + 0x25c],0x0
//         004626b9     JZ         LAB_004626c7
//                              music.cpp:790 (5)
//         004626bb     CALL       TMusic_System::end_fade                          void end_fade(TMusic_System * this)
//                              music.cpp:791 (5)
//         004626c0     MOV        EAX,0x1
//                              music.cpp:820 (2)
//         004626c5     POP        ESI
//         004626c6     RET
//                               LAB_004626c7                                                 XREF[1]:     004626b9(j)
//                              music.cpp:794 (17)
//         004626c7     XOR        EAX,EAX
//         004626c9     MOV        AL,byte ptr [ESI + 0x104]
//         004626cf     DEC        EAX
//         004626d0     JZ         LAB_0046270f
//         004626d2     DEC        EAX
//         004626d3     JZ         LAB_004626ee
//         004626d5     DEC        EAX
//         004626d6     JNZ        LAB_00462734
//                              music.cpp:810 (10)
//         004626d8     MOV        this,dword ptr [ESI + 0x108]
//         004626de     TEST       this,this
//         004626e0     JZ         LAB_00462734
//                              music.cpp:811 (5)
//         004626e2     CALL       TSound_Driver::resume_stream                     int resume_stream(TSound_Driver * this)
//                              music.cpp:819 (5)
//         004626e7     MOV        EAX,0x1
//                              music.cpp:820 (2)
//         004626ec     POP        ESI
//         004626ed     RET
//                               LAB_004626ee                                                 XREF[1]:     004626d3(j)
//                              music.cpp:803 (27)
//         004626ee     MOV        this,dword ptr [ESI + 0x118]
//         004626f4     LEA        EAX,[ESI + 0x11c]
//         004626fa     PUSH       EAX
//         004626fb     PUSH       0x0
//         004626fd     PUSH       0x806
//         00462702     PUSH       this
//         00462703     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:804 (4)
//         00462709     TEST       EAX,EAX
//         0046270b     JNZ        LAB_00462734
//                              music.cpp:807 (2)
//         0046270d     JMP        LAB_0046272e
//                               LAB_0046270f                                                 XREF[1]:     004626d0(j)
//                              music.cpp:797 (27)
//         0046270f     MOV        EAX,dword ptr [ESI + 0x118]
//         00462715     LEA        EDX,[ESI + 0x11c]
//         0046271b     PUSH       EDX
//         0046271c     PUSH       0x0
//         0046271e     PUSH       0x806
//         00462723     PUSH       EAX
//         00462724     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:798 (4)
//         0046272a     TEST       EAX,EAX
//         0046272c     JNZ        LAB_00462734
//                               LAB_0046272e                                                 XREF[1]:     0046270d(j)
//                              music.cpp:799 (6)
//         0046272e     INC        dword ptr [ESI + 0x24c]
//                               LAB_00462734                                                 XREF[4]:     004626d6(j), 004626e0(j),
//                                                                                                         0046270b(j), 0046272c(j)
//                              music.cpp:819 (5)
//         00462734     MOV        EAX,0x1
//                              music.cpp:820 (2)
//         00462739     POP        ESI
//         0046273a     RET
//                               LAB_0046273b                                                 XREF[3]:     0046267b(j), 00462689(j),
//                                                                                                         00462697(j)
//                              music.cpp:783 (2)
//         0046273b     XOR        EAX,EAX
//                              music.cpp:820 (2)
//         0046273d     POP        ESI
//         0046273e     RET
//         0046273f     ??         90h
    return 0;
}

int TMusic_System::stop_track() {
    /* TODO: Stub */
//                              int __thiscall stop_track(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?stop_track@TMusic_System@@QAEHXZ                            XREF[4]:     stop_music_system:0041f9e7(c),
//                               TMusic_System::stop_track                                                 close_device:00461c72(c),
//                                                                                                         let_game_begin:00528cd1(c),
//                                                                                                         start_scenario_editor:00528e60(c)
//                              music.cpp:824 (8)
//         00462740     XOR        EAX,EAX
//         00462742     MOV        dword ptr [ECX + this->loop],EAX
//                              music.cpp:826 (6)
//         00462748     MOV        dword ptr [ECX + this->start_track],EAX
//                              music.cpp:827 (6)
//         0046274e     MOV        dword ptr [ECX + this->end_track],EAX
//                              music.cpp:828 (6)
//         00462754     MOV        byte ptr [ECX + this->file_name[0]],AL
//                              music.cpp:829 (6)
//         0046275a     MOV        dword ptr [ECX + this->fading_track],EAX
//                              music.cpp:831 (5)
//         00462760     JMP        TMusic_System::stop_playing                      int stop_playing(TMusic_System * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         00462765     ??         90h
//         00462766     NOP
//         00462767     NOP
//         00462768     NOP
//         00462769     NOP
//         0046276a     NOP
//         0046276b     NOP
//         0046276c     NOP
//         0046276d     NOP
//         0046276e     NOP
//         0046276f     NOP
    return 0;
}

int TMusic_System::stop_playing() {
    /* TODO: Stub */
//                              int __thiscall stop_playing(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?stop_playing@TMusic_System@@IAEHXZ                          XREF[4]:     play:00462224(c),
//                               TMusic_System::stop_playing                                               stop_track:00462760(c),
//                                                                                                         do_fade:004628fc(c),
//                                                                                                         do_fade:00462962(c)
//                              music.cpp:836 (4)
//         00462770     PUSH       EBX
//         00462771     PUSH       ESI
//         00462772     MOV        ESI,this
//                              music.cpp:839 (10)
//         00462774     XOR        EBX,EBX
//         00462776     CMP        byte ptr [ESI + 0x128],BL
//         0046277c     JNZ        LAB_00462786
//                              music.cpp:840 (5)
//         0046277e     MOV        EAX,0x1
//                              music.cpp:883 (3)
//         00462783     POP        ESI
//         00462784     POP        EBX
//         00462785     RET
//                               LAB_00462786                                                 XREF[1]:     0046277c(j)
//                              music.cpp:842 (18)
//         00462786     XOR        EAX,EAX
//         00462788     PUSH       EDI
//         00462789     MOV        AL,byte ptr [ESI + 0x104]
//         0046278f     DEC        EAX
//         00462790     JZ         LAB_004627df
//         00462792     DEC        EAX
//         00462793     JZ         LAB_004627a9
//         00462795     DEC        EAX
//         00462796     JNZ        LAB_004627fa
//                              music.cpp:862 (10)
//         00462798     MOV        this,dword ptr [ESI + 0x108]
//         0046279e     CMP        this,EBX
//         004627a0     JZ         LAB_004627fa
//                              music.cpp:863 (5)
//         004627a2     CALL       TSound_Driver::stop_stream                       int stop_stream(TSound_Driver * this)
//                              music.cpp:864 (2)
//         004627a7     JMP        LAB_004627fa
//                               LAB_004627a9                                                 XREF[1]:     00462793(j)
//                              music.cpp:850 (23)
//         004627a9     MOV        EAX,dword ptr [ESI + 0x118]
//         004627af     MOV        EDI,dword ptr [->WINMM.DLL::mciSendCommandA]     = 0048b432
//         004627b5     PUSH       EBX
//         004627b6     PUSH       0x2
//         004627b8     PUSH       0x808
//         004627bd     PUSH       EAX
//         004627be     CALL       EDI=>WINMM.DLL::mciSendCommandA
//                              music.cpp:853 (23)
//         004627c0     MOV        this,dword ptr [ESI + 0x118]
//         004627c6     PUSH       EBX
//         004627c7     PUSH       0x2
//         004627c9     PUSH       0x804
//         004627ce     PUSH       this
//         004627cf     MOV        byte ptr [ESI + 0x128],BL
//         004627d5     CALL       EDI=>WINMM.DLL::mciSendCommandA
//                              music.cpp:854 (6)
//         004627d7     MOV        dword ptr [ESI + 0x118],EBX
//                              music.cpp:859 (2)
//         004627dd     JMP        LAB_004627fa
//                               LAB_004627df                                                 XREF[1]:     00462790(j)
//                              music.cpp:845 (21)
//         004627df     MOV        EDX,dword ptr [ESI + 0x118]
//         004627e5     PUSH       EBX
//         004627e6     PUSH       0x2
//         004627e8     PUSH       0x808
//         004627ed     PUSH       EDX
//         004627ee     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:846 (6)
//         004627f4     MOV        byte ptr [ESI + 0x128],BL
//                               LAB_004627fa                                                 XREF[4]:     00462796(j), 004627a0(j),
//                                                                                                         004627a7(j), 004627dd(j)
//                              music.cpp:878 (6)
//         004627fa     MOV        byte ptr [ESI + 0x128],BL
//                              music.cpp:879 (6)
//         00462800     MOV        dword ptr [ESI + 0x258],EBX
//                              music.cpp:880 (7)
//         00462806     MOV        dword ptr [ESI + 0x25c],EBX
//         0046280c     POP        EDI
//                              music.cpp:883 (8)
//         0046280d     POP        ESI
//         0046280e     MOV        EAX,0x1
//         00462813     POP        EBX
//         00462814     RET
//         00462815     ??         90h
//         00462816     NOP
//         00462817     NOP
//         00462818     NOP
//         00462819     NOP
//         0046281a     NOP
//         0046281b     NOP
//         0046281c     NOP
//         0046281d     NOP
//         0046281e     NOP
//         0046281f     NOP
    return 0;
}

int TMusic_System::fade_track() {
    /* TODO: Stub */
//                              int __thiscall fade_track(TMusic_System * this)
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?fade_track@TMusic_System@@QAEHXZ
//                               TMusic_System::fade_track
//                              music.cpp:887 (40)
//         00462820     MOV        DL,byte ptr [ECX + this->playing_track]
//         00462826     XOR        EAX,EAX
//         00462828     CMP        DL,AL
//         0046282a     MOV        dword ptr [ECX + this->loop],EAX
//         00462830     MOV        dword ptr [ECX + this->start_track],EAX
//         00462836     MOV        dword ptr [ECX + this->end_track],EAX
//         0046283c     MOV        byte ptr [ECX + this->file_name[0]],AL
//         00462842     MOV        dword ptr [ECX + this->fading_track],EAX
//                              music.cpp:895 (2)
//         00462848     JZ         LAB_0046284f
//                              music.cpp:897 (5)
//         0046284a     CALL       TMusic_System::start_fade                        void start_fade(TMusic_System * this)
//                               LAB_0046284f                                                 XREF[1]:     00462848(j)
//                              music.cpp:899 (5)
//         0046284f     MOV        EAX,0x1
//                              music.cpp:900 (1)
//         00462854     RET
//         00462855     ??         90h
//         00462856     NOP
//         00462857     NOP
//         00462858     NOP
//         00462859     NOP
//         0046285a     NOP
//         0046285b     NOP
//         0046285c     NOP
//         0046285d     NOP
//         0046285e     NOP
//         0046285f     NOP
    return 0;
}

void TMusic_System::start_fade() {
    /* TODO: Stub */
//                              void __thiscall start_fade(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?start_fade@TMusic_System@@IAEXXZ                            XREF[4]:     play_track:00462063(c),
//                               TMusic_System::start_fade                                                 play_file:0046210f(c),
//                                                                                                         play_tracks:004621d0(c),
//                                                                                                         fade_track:0046284a(c)
//                              music.cpp:904 (3)
//         00462860     PUSH       ESI
//         00462861     MOV        ESI,this
//                              music.cpp:905 (10)
//         00462863     MOV        EAX,dword ptr [ESI + 0x26c]
//         00462869     TEST       EAX,EAX
//         0046286b     JNZ        LAB_0046289b
//                              music.cpp:907 (6)
//         0046286d     MOV        EAX,dword ptr [ESI + 0x254]
//                              music.cpp:908 (30)
//         00462873     PUSH       0x38c
//         00462878     PUSH       s_C:\msdev\work\age1_x1\music.cpp                = "C:\\msdev\\work\\age1_x1\\music.cpp"
//         0046287d     MOV        dword ptr [ESI + 0x270],EAX
//         00462883     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00462888     ADD        ESP,0x8
//         0046288b     MOV        dword ptr [ESI + 0x274],EAX
//                              music.cpp:909 (10)
//         00462891     MOV        dword ptr [ESI + 0x26c],0x1
//                               LAB_0046289b                                                 XREF[1]:     0046286b(j)
//                              music.cpp:911 (2)
//         0046289b     POP        ESI
//         0046289c     RET
//         0046289d     ??         90h
//         0046289e     NOP
//         0046289f     NOP
    return;
}

void TMusic_System::do_fade() {
    /* TODO: Stub */
//                              void __thiscall do_fade(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              undefined8        Stack[-0x8]:8  local_8                   XREF[2,1]:   0046290f(W), 00462913(R), 00462907(W)
//              undefined8        Stack[-0x10]:8 local_10                  XREF[4,1]:   004628d7(W), 004628e1(R), 004628ea(W), 00462917(R),
//                                                                                     004628ca(W)
//              float             Stack[-0x14]:4 time
//                               ?do_fade@TMusic_System@@IAEXXZ                               XREF[1]:     handle_messages:00462aa9(c)
//                               TMusic_System::do_fade
//                              music.cpp:919 (7)
//         004628a0     SUB        ESP,0x10
//         004628a3     PUSH       ESI
//         004628a4     MOV        ESI,this
//         004628a6     PUSH       EDI
//                              music.cpp:922 (14)
//         004628a7     MOV        EAX,dword ptr [ESI + 0x258]
//         004628ad     TEST       EAX,EAX
//         004628af     JNZ        LAB_004629a0
//                              music.cpp:926 (38)
//         004628b5     PUSH       0x39e
//         004628ba     PUSH       s_C:\msdev\work\age1_x1\music.cpp                = "C:\\msdev\\work\\age1_x1\\music.cpp"
//         004628bf     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004628c4     MOV        this,dword ptr [ESI + 0x274]
//         004628ca     MOV        dword ptr [ESP + local_10+0x4],0x0
//         004628d2     SUB        EAX,this
//         004628d4     ADD        ESP,0x8
//         004628d7     MOV        dword ptr [ESP + local_10],EAX
//                              music.cpp:929 (21)
//         004628db     MOV        EAX,dword ptr [ESI + 0x270]
//         004628e1     FILD       qword ptr [ESP + local_10]
//         004628e5     CMP        EAX,0xffffd8f0
//         004628ea     FSTP       float ptr [ESP + local_10]
//         004628ee     JG         LAB_00462901
//                              music.cpp:931 (10)
//         004628f0     MOV        AL,byte ptr [ESI + 0x128]
//         004628f6     TEST       AL,AL
//         004628f8     JZ         LAB_00462901
//                              music.cpp:932 (7)
//         004628fa     MOV        this,ESI
//         004628fc     CALL       TMusic_System::stop_playing                      int stop_playing(TMusic_System * this)
//                               LAB_00462901                                                 XREF[2]:     004628ee(j), 004628f8(j)
//                              music.cpp:936 (39)
//         00462901     MOV        EAX,dword ptr [ESI + 0x268]
//         00462907     MOV        dword ptr [ESP + local_8+0x4],0x0
//         0046290f     MOV        dword ptr [ESP + local_8],EAX
//         00462913     FILD       qword ptr [ESP + local_8]
//         00462917     FLD        float ptr [ESP + local_10]
//         0046291b     FDIV       ST0,ST1
//         0046291d     FMUL       float ptr [DAT_00570c20]                         = align(1)
//         00462923     CALL       __ftol                                           undefined __ftol()
//                              music.cpp:939 (46)
//         00462928     FLD        float ptr [DAT_00570c24]
//         0046292e     FDIV       ST0,ST1
//         00462930     MOV        EDI,dword ptr [ESI + 0x270]
//         00462936     ADD        EDI,EAX
//         00462938     MOV        dword ptr [ESI + 0x270],EDI
//         0046293e     FMUL       float ptr [DAT_00570c28]
//         00462944     CALL       __ftol                                           undefined __ftol()
//         00462949     MOV        this,0xffffd8f0
//         0046294e     SUB        this,EAX
//         00462950     CMP        EDI,this
//         00462952     FSTP       ST0
//         00462954     JG         LAB_0046297e
//                              music.cpp:941 (10)
//         00462956     MOV        AL,byte ptr [ESI + 0x128]
//         0046295c     TEST       AL,AL
//         0046295e     JZ         LAB_00462967
//                              music.cpp:942 (7)
//         00462960     MOV        this,ESI
//         00462962     CALL       TMusic_System::stop_playing                      int stop_playing(TMusic_System * this)
//                               LAB_00462967                                                 XREF[1]:     0046295e(j)
//                              music.cpp:944 (10)
//         00462967     MOV        EAX,dword ptr [ESI + 0x26c]
//         0046296d     TEST       EAX,EAX
//         0046296f     JZ         LAB_004629a0
//                              music.cpp:945 (7)
//         00462971     MOV        this,ESI
//         00462973     CALL       TMusic_System::end_fade                          void end_fade(TMusic_System * this)
//                              music.cpp:953 (6)
//         00462978     POP        EDI
//         00462979     POP        ESI
//         0046297a     ADD        ESP,0x10
//         0046297d     RET
//                               LAB_0046297e                                                 XREF[1]:     00462954(j)
//                              music.cpp:951 (10)
//         0046297e     PUSH       0x0
//         00462980     PUSH       EDI
//         00462981     MOV        this,ESI
//         00462983     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
//                              music.cpp:952 (24)
//         00462988     PUSH       0x3b8
//         0046298d     PUSH       s_C:\msdev\work\age1_x1\music.cpp                = "C:\\msdev\\work\\age1_x1\\music.cpp"
//         00462992     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         00462997     ADD        ESP,0x8
//         0046299a     MOV        dword ptr [ESI + 0x274],EAX
//                               LAB_004629a0                                                 XREF[2]:     004628af(j), 0046296f(j)
//                              music.cpp:953 (6)
//         004629a0     POP        EDI
//         004629a1     POP        ESI
//         004629a2     ADD        ESP,0x10
//         004629a5     RET
//         004629a6     ??         90h
//         004629a7     NOP
//         004629a8     NOP
//         004629a9     NOP
//         004629aa     NOP
//         004629ab     NOP
//         004629ac     NOP
//         004629ad     NOP
//         004629ae     NOP
//         004629af     NOP
    return;
}

void TMusic_System::end_fade() {
    /* TODO: Stub */
//                              void __thiscall end_fade(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?end_fade@TMusic_System@@IAEXXZ                              XREF[2]:     resume_play:004626bb(c),
//                               TMusic_System::end_fade                                                   do_fade:00462973(c)
//                              music.cpp:958 (3)
//         004629b0     PUSH       ESI
//         004629b1     MOV        ESI,this
//                              music.cpp:961 (24)
//         004629b3     PUSH       0x0
//         004629b5     MOV        EAX,dword ptr [ESI + 0x254]
//         004629bb     MOV        dword ptr [ESI + 0x26c],0x0
//         004629c5     PUSH       EAX
//         004629c6     CALL       TMusic_System::set_volume                        void set_volume(TMusic_System * this, long pa
//                              music.cpp:963 (30)
//         004629cb     MOV        EAX,dword ptr [ESI + 0x230]
//         004629d1     TEST       EAX,EAX
//         004629d3     JLE        LAB_004629df
//         004629d5     MOV        this,dword ptr [ESI + 0x234]
//         004629db     TEST       this,this
//         004629dd     JG         LAB_004629e9
//                               LAB_004629df                                                 XREF[1]:     004629d3(j)
//         004629df     MOV        this,byte ptr [ESI + 0x129]
//         004629e5     TEST       this,this
//         004629e7     JZ         LAB_00462a0d
//                               LAB_004629e9                                                 XREF[1]:     004629dd(j)
//                              music.cpp:964 (36)
//         004629e9     MOV        this,dword ptr [ESI + 0x23c]
//         004629ef     MOV        EDX,dword ptr [ESI + 0x238]
//         004629f5     PUSH       this
//         004629f6     PUSH       EDX
//         004629f7     MOV        EDX,dword ptr [ESI + 0x234]
//         004629fd     LEA        this,[ESI + 0x129]
//         00462a03     PUSH       this
//         00462a04     PUSH       EDX
//         00462a05     PUSH       EAX
//         00462a06     MOV        this,ESI
//         00462a08     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                               LAB_00462a0d                                                 XREF[1]:     004629e7(j)
//                              music.cpp:965 (2)
//         00462a0d     POP        ESI
//         00462a0e     RET
//         00462a0f     ??         90h
    return;
}

uint TMusic_System::handle_messages(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
//                              uint __thiscall handle_messages(TMusic_System * this, void * param_1
//              uint              EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1
//              uint              Stack[0x8]:4   param_2                   XREF[1]:     00462a10(R)
//              uint              Stack[0xc]:4   param_3                   XREF[1]:     00462a2d(R)
//              long              Stack[0x10]:4  param_4
//                               ?handle_messages@TMusic_System@@QAEIPAXIIJ@Z                 XREF[1]:     wnd_proc:00420754(c)
//                               TMusic_System::handle_messages
//                              music.cpp:969 (29)
//         00462a10     MOV        EAX,dword ptr [ESP + param_2]
//         00462a14     PUSH       ESI
//         00462a15     CMP        EAX,0x113
//         00462a1a     MOV        ESI,this
//         00462a1c     JA         LAB_00462ab4
//         00462a22     JZ         LAB_00462a99
//         00462a24     CMP        EAX,0x1c
//         00462a27     JNZ        LAB_00462b31
//                              music.cpp:1043 (6)
//         00462a2d     MOV        EAX,dword ptr [ESP + param_3]
//         00462a31     TEST       EAX,EAX
//                              music.cpp:1045 (30)
//         00462a33     MOV        EAX,dword ptr [ESI + 0x260]
//         00462a39     JZ         LAB_00462a70
//         00462a3b     TEST       EAX,EAX
//         00462a3d     JZ         LAB_00462b31
//         00462a43     MOV        EAX,dword ptr [ESI + 0x25c]
//         00462a49     TEST       EAX,EAX
//         00462a4b     JZ         LAB_00462b31
//                              music.cpp:1047 (5)
//         00462a51     CALL       TMusic_System::resume_play                       int resume_play(TMusic_System * this)
//                              music.cpp:1048 (10)
//         00462a56     MOV        dword ptr [ESI + 0x25c],0x0
//                              music.cpp:1049 (10)
//         00462a60     MOV        dword ptr [ESI + 0x260],0x0
//                              music.cpp:1064 (2)
//         00462a6a     XOR        EAX,EAX
//                              music.cpp:1065 (4)
//         00462a6c     POP        ESI
//         00462a6d     RET        0x10
//                               LAB_00462a70                                                 XREF[1]:     00462a39(j)
//                              music.cpp:1054 (8)
//         00462a70     TEST       EAX,EAX
//         00462a72     JNZ        LAB_00462b31
//                              music.cpp:1056 (7)
//         00462a78     MOV        this,ESI
//         00462a7a     CALL       TMusic_System::pause_play                        int pause_play(TMusic_System * this)
//                              music.cpp:1057 (10)
//         00462a7f     MOV        dword ptr [ESI + 0x25c],0x1
//                              music.cpp:1058 (10)
//         00462a89     MOV        dword ptr [ESI + 0x260],0x1
//                              music.cpp:1064 (2)
//         00462a93     XOR        EAX,EAX
//                              music.cpp:1065 (4)
//         00462a95     POP        ESI
//         00462a96     RET        0x10
//                               LAB_00462a99                                                 XREF[1]:     00462a22(j)
//                              music.cpp:976 (14)
//         00462a99     MOV        EAX,dword ptr [ESI + 0x26c]
//         00462a9f     TEST       EAX,EAX
//         00462aa1     JZ         LAB_00462b31
//                              music.cpp:977 (7)
//         00462aa7     MOV        this,ESI
//         00462aa9     CALL       TMusic_System::do_fade                           void do_fade(TMusic_System * this)
//                              music.cpp:1064 (2)
//         00462aae     XOR        EAX,EAX
//                              music.cpp:1065 (4)
//         00462ab0     POP        ESI
//         00462ab1     RET        0x10
//                               LAB_00462ab4                                                 XREF[1]:     00462a1c(j)
//                              music.cpp:973 (14)
//         00462ab4     CMP        EAX,0x3b9
//         00462ab9     JZ         LAB_00462ae9
//         00462abb     CMP        EAX,0x500
//         00462ac0     JNZ        LAB_00462b31
//                              music.cpp:1016 (9)
//         00462ac2     CMP        byte ptr [ESI + 0x104],0x3
//         00462ac9     JNZ        LAB_00462b31
//                              music.cpp:1018 (24)
//         00462acb     MOV        EAX,dword ptr [ESI + 0x258]
//         00462ad1     TEST       EAX,EAX
//         00462ad3     JNZ        LAB_00462b31
//         00462ad5     MOV        this,ESI
//         00462ad7     MOV        byte ptr [ESI + 0x128],0x0
//         00462ade     CALL       TMusic_System::after_end_track                   void after_end_track(TMusic_System * this)
//                              music.cpp:1064 (2)
//         00462ae3     XOR        EAX,EAX
//                              music.cpp:1065 (4)
//         00462ae5     POP        ESI
//         00462ae6     RET        0x10
//                               LAB_00462ae9                                                 XREF[1]:     00462ab9(j)
//                              music.cpp:999 (16)
//         00462ae9     MOV        this,byte ptr [ESI + 0x104]
//         00462aef     CMP        this,0x1
//         00462af2     JZ         LAB_00462af9
//         00462af4     CMP        this,0x2
//         00462af7     JNZ        LAB_00462b31
//                               LAB_00462af9                                                 XREF[1]:     00462af2(j)
//                              music.cpp:1001 (10)
//         00462af9     MOV        EAX,dword ptr [ESI + 0x24c]
//         00462aff     TEST       EAX,EAX
//         00462b01     JLE        LAB_00462b0a
//                              music.cpp:1002 (7)
//         00462b03     DEC        EAX
//         00462b04     MOV        dword ptr [ESI + 0x24c],EAX
//                               LAB_00462b0a                                                 XREF[1]:     00462b01(j)
//                              music.cpp:1003 (10)
//         00462b0a     MOV        EAX,dword ptr [ESI + 0x24c]
//         00462b10     TEST       EAX,EAX
//         00462b12     JNZ        LAB_00462b31
//                              music.cpp:1005 (10)
//         00462b14     MOV        EAX,dword ptr [ESI + 0x258]
//         00462b1a     TEST       EAX,EAX
//         00462b1c     JNZ        LAB_00462b31
//                              music.cpp:1007 (5)
//         00462b1e     CMP        this,0x1
//         00462b21     JNZ        LAB_00462b2a
//                              music.cpp:1008 (7)
//         00462b23     MOV        byte ptr [ESI + 0x128],0x0
//                               LAB_00462b2a                                                 XREF[1]:     00462b21(j)
//                              music.cpp:1009 (7)
//         00462b2a     MOV        this,ESI
//         00462b2c     CALL       TMusic_System::after_end_track                   void after_end_track(TMusic_System * this)
//                               LAB_00462b31                                                 XREF[11]:    00462a27(j), 00462a3d(j),
//                                                                                                         00462a4b(j), 00462a72(j),
//                                                                                                         00462aa1(j), 00462ac0(j),
//                                                                                                         00462ac9(j), 00462ad3(j),
//                                                                                                         00462af7(j), 00462b12(j),
//                                                                                                         00462b1c(j)
//                              music.cpp:1064 (2)
//         00462b31     XOR        EAX,EAX
//                              music.cpp:1065 (4)
//         00462b33     POP        ESI
//         00462b34     RET        0x10
//         00462b37     ??         90h
//         00462b38     NOP
//         00462b39     NOP
//         00462b3a     NOP
//         00462b3b     NOP
//         00462b3c     NOP
//         00462b3d     NOP
//         00462b3e     NOP
//         00462b3f     NOP
    return 0;
}

void TMusic_System::after_end_track() {
    /* TODO: Stub */
//                              void __thiscall after_end_track(TMusic_System * this)
//              void              <VOID>         <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//                               ?after_end_track@TMusic_System@@IAEXXZ                       XREF[2]:     handle_messages:00462ade(c),
//                               TMusic_System::after_end_track                                            handle_messages:00462b2c(c)
//                              music.cpp:1069 (27)
//         00462b40     XOR        EAX,EAX
//         00462b42     PUSH       EBX
//         00462b43     MOV        AL,byte ptr [ECX + this->music_type]
//         00462b49     PUSH       ESI
//         00462b4a     DEC        EAX
//         00462b4b     JZ         LAB_00462bf4
//         00462b51     DEC        EAX
//         00462b52     JZ         LAB_00462b9a
//         00462b54     DEC        EAX
//         00462b55     JNZ        LAB_00462c21
//                              music.cpp:1080 (14)
//         00462b5b     MOV        EAX,dword ptr [ECX + this->fading_track]
//         00462b61     TEST       EAX,EAX
//         00462b63     JNZ        LAB_00462c21
//                              music.cpp:1082 (32)
//         00462b69     MOV        BL,byte ptr [ECX + this->file_name[0]]
//         00462b6f     LEA        EDX,[ECX + this->file_name[0]]
//         00462b75     TEST       BL,BL
//         00462b77     JNZ        LAB_00462bd5
//         00462b79     MOV        EAX,dword ptr [ECX + this->current_track]
//         00462b7f     MOV        ESI,dword ptr [ECX + this->end_track]
//         00462b85     CMP        EAX,ESI
//         00462b87     JGE        LAB_00462bd5
//                              music.cpp:1083 (14)
//         00462b89     PUSH       0x0
//         00462b8b     INC        EAX
//         00462b8c     PUSH       0x0
//         00462b8e     PUSH       0x0
//         00462b90     PUSH       EAX
//         00462b91     PUSH       EAX
//         00462b92     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                              music.cpp:1123 (3)
//         00462b97     POP        ESI
//         00462b98     POP        EBX
//         00462b99     RET
//                               LAB_00462b9a                                                 XREF[1]:     00462b52(j)
//                              music.cpp:1094 (10)
//         00462b9a     MOV        EAX,dword ptr [ECX + this->fading_track]
//         00462ba0     TEST       EAX,EAX
//         00462ba2     JNZ        LAB_00462c21
//                              music.cpp:1096 (32)
//         00462ba4     MOV        BL,byte ptr [ECX + this->file_name[0]]
//         00462baa     LEA        EDX,[ECX + this->file_name[0]]
//         00462bb0     TEST       BL,BL
//         00462bb2     JNZ        LAB_00462bd5
//         00462bb4     MOV        EAX,dword ptr [ECX + this->current_track]
//         00462bba     MOV        ESI,dword ptr [ECX + this->end_track]
//         00462bc0     CMP        EAX,ESI
//         00462bc2     JGE        LAB_00462bd5
//                              music.cpp:1097 (14)
//         00462bc4     PUSH       0x0
//         00462bc6     INC        EAX
//         00462bc7     PUSH       0x0
//         00462bc9     PUSH       0x0
//         00462bcb     PUSH       EAX
//         00462bcc     PUSH       EAX
//         00462bcd     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                              music.cpp:1123 (3)
//         00462bd2     POP        ESI
//         00462bd3     POP        EBX
//         00462bd4     RET
//                               LAB_00462bd5                                                 XREF[4]:     00462b77(j), 00462b87(j),
//                                                                                                         00462bb2(j), 00462bc2(j)
//                              music.cpp:1098 (10)
//         00462bd5     MOV        EAX,dword ptr [ECX + this->loop]
//         00462bdb     TEST       EAX,EAX
//         00462bdd     JZ         LAB_00462c21
//                              music.cpp:1100 (2)
//         00462bdf     TEST       BL,BL
//                              music.cpp:1101 (4)
//         00462be1     PUSH       0x0
//         00462be3     PUSH       0x0
//                              music.cpp:1102 (2)
//         00462be5     JZ         LAB_00462c0c
//                              music.cpp:1103 (10)
//         00462be7     PUSH       EDX
//         00462be8     PUSH       0x0
//         00462bea     PUSH       0x0
//         00462bec     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                              music.cpp:1123 (3)
//         00462bf1     POP        ESI
//         00462bf2     POP        EBX
//         00462bf3     RET
//                               LAB_00462bf4                                                 XREF[1]:     00462b4b(j)
//                              music.cpp:1073 (10)
//         00462bf4     MOV        EAX,dword ptr [ECX + this->fading_track]
//         00462bfa     TEST       EAX,EAX
//         00462bfc     JNZ        LAB_00462c21
//                              music.cpp:1075 (10)
//         00462bfe     MOV        EAX,dword ptr [ECX + this->loop]
//         00462c04     TEST       EAX,EAX
//         00462c06     JZ         LAB_00462c21
//                              music.cpp:1076 (25)
//         00462c08     PUSH       0x0
//         00462c0a     PUSH       0x0
//                               LAB_00462c0c                                                 XREF[1]:     00462be5(j)
//         00462c0c     MOV        EAX,dword ptr [ECX + this->end_track]
//         00462c12     MOV        EDX,dword ptr [ECX + this->start_track]
//         00462c18     PUSH       0x0
//         00462c1a     PUSH       EAX
//         00462c1b     PUSH       EDX
//         00462c1c     CALL       TMusic_System::play                              int play(TMusic_System * this, int param_1, i
//                               LAB_00462c21                                                 XREF[6]:     00462b55(j), 00462b63(j),
//                                                                                                         00462ba2(j), 00462bdd(j),
//                                                                                                         00462bfc(j), 00462c06(j)
//                              music.cpp:1123 (3)
//         00462c21     POP        ESI
//         00462c22     POP        EBX
//         00462c23     RET
//         00462c24     ??         90h
//         00462c25     NOP
//         00462c26     NOP
//         00462c27     NOP
//         00462c28     NOP
//         00462c29     NOP
//         00462c2a     NOP
//         00462c2b     NOP
//         00462c2c     NOP
//         00462c2d     NOP
//         00462c2e     NOP
//         00462c2f     NOP
    return;
}

int TMusic_System::get_play_info(uchar* param_1, int* param_2, int* param_3, int* param_4, char* param_5, int* param_6, ulong* param_7) {
    /* TODO: Stub */
//                              int __thiscall get_play_info(TMusic_System * this, uchar * param_1,
//              int               EAX:4          <RETURN>
//              TMusic_System *   ECX:4 (auto)   this
//              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     00462c35(R)
//              int *             Stack[0x8]:4   param_2                   XREF[1]:     00462c46(R)
//              int *             Stack[0xc]:4   param_3                   XREF[1]:     00462c4a(R)
//              int *             Stack[0x10]:4  param_4                   XREF[1]:     00462c54(R)
//              char *            Stack[0x14]:4  param_5                   XREF[1]:     00462c40(R)
//              int *             Stack[0x18]:4  param_6                   XREF[1]:     00462c4f(R)
//              ulong *           Stack[0x1c]:4  param_7                   XREF[2]:     00462c5f(R), 00462ce5(R)
//              tagMCI_STATUS_    Stack[-0x14]   status_info               XREF[0,4]:   00462d04(*), 00462d2e(*), 00462d14(W), 00462d3e(W)
//                               ?get_play_info@TMusic_System@@QAEHPAEPAH11PAD1PAK@Z          XREF[1]:     stop_music_system:0041f9df(c)
//                               TMusic_System::get_play_info
//                              music.cpp:1127 (5)
//         00462c30     MOV        EDX,this
//         00462c32     SUB        ESP,0x10
//                              music.cpp:1131 (11)
//         00462c35     MOV        this,dword ptr [ESP + param_1]
//         00462c39     MOV        AL,byte ptr [EDX + 0x104]
//         00462c3f     PUSH       EBX
//                              music.cpp:1135 (15)
//         00462c40     MOV        EBX,dword ptr [ESP + param_5]
//         00462c44     MOV        byte ptr [this->path[0]],AL
//         00462c46     MOV        EAX,dword ptr [ESP + param_2]
//         00462c4a     MOV        this,dword ptr [ESP + param_3]
//         00462c4e     PUSH       EBP
//                              music.cpp:1136 (16)
//         00462c4f     MOV        EBP,dword ptr [ESP + param_6]
//         00462c53     PUSH       ESI
//         00462c54     MOV        ESI,dword ptr [ESP + param_4]
//         00462c58     MOV        dword ptr [EAX],0x0
//         00462c5e     PUSH       EDI
//                              music.cpp:1137 (32)
//         00462c5f     MOV        EDI,dword ptr [ESP + param_7]
//         00462c63     MOV        dword ptr [this->path[0]],0x0
//         00462c69     MOV        dword ptr [ESI],0x0
//         00462c6f     MOV        byte ptr [EBX],0x0
//         00462c72     MOV        dword ptr [EBP],0x0
//         00462c79     MOV        dword ptr [EDI],0x0
//                              music.cpp:1139 (10)
//         00462c7f     MOV        EDI,dword ptr [EDX + 0x114]
//         00462c85     TEST       EDI,EDI
//         00462c87     JNZ        LAB_00462c95
//                              music.cpp:1140 (2)
//         00462c89     XOR        EAX,EAX
//                              music.cpp:1171 (10)
//         00462c8b     POP        EDI
//         00462c8c     POP        ESI
//         00462c8d     POP        EBP
//         00462c8e     POP        EBX
//         00462c8f     ADD        ESP,0x10
//         00462c92     RET        0x1c
//                               LAB_00462c95                                                 XREF[1]:     00462c87(j)
//                              music.cpp:1142 (13)
//         00462c95     CMP        byte ptr [EDX + 0x128],0x0
//         00462c9c     JZ         LAB_00462d56
//                              music.cpp:1144 (8)
//         00462ca2     MOV        EDI,dword ptr [EDX + 0x230]
//         00462ca8     MOV        dword ptr [EAX],EDI
//                              music.cpp:1145 (8)
//         00462caa     MOV        EAX,dword ptr [EDX + 0x234]
//         00462cb0     MOV        dword ptr [this->path[0]],EAX
//                              music.cpp:1146 (8)
//         00462cb2     MOV        this,dword ptr [EDX + 0x244]
//         00462cb8     MOV        dword ptr [ESI],this
//                              music.cpp:1147 (30)
//         00462cba     LEA        EDI,[EDX + 0x129]
//         00462cc0     OR         this,0xffffffff
//         00462cc3     XOR        EAX,EAX
//         00462cc5     SCASB.RE   ES:EDI
//         00462cc7     NOT        this
//         00462cc9     SUB        EDI,this
//         00462ccb     MOV        EAX,this
//         00462ccd     MOV        ESI,EDI
//         00462ccf     MOV        EDI,EBX
//         00462cd1     SHR        this,0x2
//         00462cd4     MOVSD.REP  ES:EDI,ESI
//         00462cd6     MOV        this,EAX
//                              music.cpp:1152 (38)
//         00462cd8     XOR        EAX,EAX
//         00462cda     AND        this,0x3
//         00462cdd     MOVSB.REP  ES:EDI,ESI
//         00462cdf     MOV        this,dword ptr [EDX + 0x240]
//         00462ce5     MOV        ESI,dword ptr [ESP + param_7]
//         00462ce9     MOV        dword ptr [EBP],this
//         00462cec     MOV        dword ptr [ESI],0x0
//         00462cf2     MOV        AL,byte ptr [EDX + 0x104]
//         00462cf8     DEC        EAX
//         00462cf9     JZ         LAB_00462d28
//         00462cfb     DEC        EAX
//         00462cfc     JNZ        LAB_00462d56
//                              music.cpp:1163 (36)
//         00462cfe     MOV        this,dword ptr [EDX + 0x118]
//         00462d04     LEA        EAX=>status_info.dwReturn,[ESP + 0x10]
//         00462d08     PUSH       EAX
//         00462d09     PUSH       0x102
//         00462d0e     PUSH       0x814
//         00462d13     PUSH       this
//         00462d14     MOV        dword ptr [ESP + status_info.dwTrack],0x2
//         00462d1c     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:1164 (4)
//         00462d22     TEST       EAX,EAX
//         00462d24     JNZ        LAB_00462d56
//                              music.cpp:1166 (2)
//         00462d26     JMP        LAB_00462d50
//                               LAB_00462d28                                                 XREF[1]:     00462cf9(j)
//                              music.cpp:1156 (36)
//         00462d28     MOV        this,dword ptr [EDX + 0x118]
//         00462d2e     LEA        EAX=>status_info.dwReturn,[ESP + 0x10]
//         00462d32     PUSH       EAX
//         00462d33     PUSH       0x102
//         00462d38     PUSH       0x814
//         00462d3d     PUSH       this
//         00462d3e     MOV        dword ptr [ESP + status_info.dwTrack],0x2
//         00462d46     CALL       dword ptr [->WINMM.DLL::mciSendCommandA]         = 0048b432
//                              music.cpp:1157 (4)
//         00462d4c     TEST       EAX,EAX
//         00462d4e     JNZ        LAB_00462d56
//                               LAB_00462d50                                                 XREF[1]:     00462d26(j)
//                              music.cpp:1158 (6)
//         00462d50     MOV        EDX,dword ptr [ESP + 0x14]
//         00462d54     MOV        dword ptr [ESI],EDX
//                               LAB_00462d56                                                 XREF[4]:     00462c9c(j), 00462cfc(j),
//                                                                                                         00462d24(j), 00462d4e(j)
//                              music.cpp:1171 (15)
//         00462d56     POP        EDI
//         00462d57     POP        ESI
//         00462d58     POP        EBP
//         00462d59     MOV        EAX,0x1
//         00462d5e     POP        EBX
//         00462d5f     ADD        ESP,0x10
//         00462d62     RET        0x1c
//         00462d65     ??         90h
//         00462d66     NOP
//         00462d67     NOP
//         00462d68     NOP
//         00462d69     NOP
//         00462d6a     NOP
//         00462d6b     NOP
//         00462d6c     NOP
//         00462d6d     NOP
//         00462d6e     NOP
//         00462d6f     NOP
    return 0;
}

