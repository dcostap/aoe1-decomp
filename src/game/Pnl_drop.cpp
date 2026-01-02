#include "../common.h"
#include "Pnl_drop.h"

TDropDownPanel::TDropDownPanel() {
    /* TODO: Stub */
//                              undefined __thiscall TDropDownPanel(TDropDownPanel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ??0TDropDownPanel@@QAE@XZ                                    XREF[1]:     create_drop_down:004694b4(c)
//                               TDropDownPanel::TDropDownPanel
//                              Pnl_drop.cpp:26 (8)
//         00473ed0     PUSH       ESI
//         00473ed1     MOV        ESI,this
//         00473ed3     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
//                              Pnl_drop.cpp:29 (14)
//         00473ed8     XOR        EAX,EAX
//         00473eda     MOV        dword ptr [ESI],TDropDownPanel::`vftable'        = 00473f30
//         00473ee0     MOV        dword ptr [ESI + 0xf4],EAX
//                              Pnl_drop.cpp:30 (6)
//         00473ee6     MOV        dword ptr [ESI + 0xf8],EAX
//                              Pnl_drop.cpp:31 (6)
//         00473eec     MOV        dword ptr [ESI + 0xfc],EAX
//                              Pnl_drop.cpp:32 (6)
//         00473ef2     MOV        dword ptr [ESI + 0x100],EAX
//                              Pnl_drop.cpp:33 (6)
//         00473ef8     MOV        dword ptr [ESI + 0x104],EAX
//                              Pnl_drop.cpp:34 (7)
//         00473efe     MOV        word ptr [ESI + 0x108],AX
//                              Pnl_drop.cpp:35 (6)
//         00473f05     MOV        byte ptr [ESI + 0x130],AL
//                              Pnl_drop.cpp:36 (13)
//         00473f0b     MOV        dword ptr [ESI + 0x13c],EAX
//         00473f11     MOV        byte ptr [ESI + 0xee],0x6
//                              Pnl_drop.cpp:37 (10)
//         00473f18     MOV        dword ptr [ESI + 0x140],0x1
//                              Pnl_drop.cpp:38 (4)
//         00473f22     MOV        EAX,ESI
//         00473f24     POP        ESI
//         00473f25     RET
//         00473f26     ??         90h
//         00473f27     NOP
//         00473f28     NOP
//         00473f29     NOP
//         00473f2a     NOP
//         00473f2b     NOP
//         00473f2c     NOP
//         00473f2d     NOP
//         00473f2e     NOP
//         00473f2f     NOP
}

TDropDownPanel::~TDropDownPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TDropDownPanel(TDropDownPanel * this)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00473f79(W), 00473fb3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00473fc0(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00473f69(W)
//                               ??1TDropDownPanel@@UAE@XZ                                    XREF[1]:     `scalar_deleting_destructor':00473
//                               TDropDownPanel::~TDropDownPanel
//                              Pnl_drop.cpp:44 (35)
//         00473f50     PUSH       -0x1
//         00473f52     PUSH       FUN_0055e408
//         00473f57     MOV        EAX,FS:[0x0]
//         00473f5d     PUSH       EAX
//         00473f5e     MOV        dword ptr FS:[0x0],ESP
//         00473f65     PUSH       this
//         00473f66     PUSH       ESI
//         00473f67     MOV        ESI,this
//         00473f69     MOV        dword ptr [ESP + local_10],ESI
//         00473f6d     MOV        dword ptr [ESI],TDropDownPanel::`vftable'        = 00473f30
//                              Pnl_drop.cpp:45 (20)
//         00473f73     LEA        EAX,[ESI + 0xf8]
//         00473f79     MOV        dword ptr [ESP + local_4],0x0
//         00473f81     PUSH       EAX
//         00473f82     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Pnl_drop.cpp:46 (14)
//         00473f87     LEA        this,[ESI + 0xfc]
//         00473f8d     PUSH       this
//         00473f8e     MOV        this,ESI
//         00473f90     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Pnl_drop.cpp:47 (14)
//         00473f95     LEA        EDX,[ESI + 0x100]
//         00473f9b     MOV        this,ESI
//         00473f9d     PUSH       EDX
//         00473f9e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Pnl_drop.cpp:48 (16)
//         00473fa3     LEA        EAX,[ESI + 0xf4]
//         00473fa9     MOV        this,ESI
//         00473fab     PUSH       EAX
//         00473fac     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         00473fb1     MOV        this,ESI
//                              Pnl_drop.cpp:51 (29)
//         00473fb3     MOV        dword ptr [ESP + local_4],0xffffffff
//         00473fbb     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
//         00473fc0     MOV        this,dword ptr [ESP + local_c]
//         00473fc4     POP        ESI
//         00473fc5     MOV        dword ptr FS:[0x0],this
//         00473fcc     ADD        ESP,0x10
//         00473fcf     RET
}

long TDropDownPanel::setup(TDrawArea* param_1, TPanel* param_2, void* param_3, long param_4, long param_5, int param_6, uchar param_7, int param_8, uchar param_9, long param_10, long param_11, long param_12, long param_13, short param_14, short param_15, long param_16, long param_17, char* param_18, long param_19, long param_20, char** param_21, short param_22, long param_23, char* param_24, char* param_25, char* param_26, char* param_27, long param_28, long param_29) {
    /* TODO: Stub */
//                              long __thiscall setup(TDropDownPanel * this, TDrawArea * param_1, TP
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047405e(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00474082(R)
//              void *            Stack[0xc]:4   param_3                   XREF[2]:     004740fd(R), 00474203(R)
//              long              Stack[0x10]:4  param_4                   XREF[2]:     004740f8(R), 004741fe(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00474059(R)
//              int               Stack[0x18]:4  param_6                   XREF[2]:     004740f3(R), 004741f9(R)
//              uchar             Stack[0x1c]:1  param_7                   XREF[2]:     004740ed(R), 004741f3(R)
//              int               Stack[0x20]:4  param_8                   XREF[2]:     004740e8(R), 004741ee(R)
//              uchar             Stack[0x24]:1  param_9                   XREF[1]:     00473ff3(R)
//              long              Stack[0x28]:4  param_10                  XREF[1]:     00474078(R)
//              long              Stack[0x2c]:4  param_11                  XREF[1]:     00474073(R)
//              long              Stack[0x30]:4  param_12                  XREF[1]:     00473ffe(R)
//              long              Stack[0x34]:4  param_13                  XREF[1]:     00474055(R)
//              short             Stack[0x38]:2  param_14                  XREF[2]:     004740e3(R), 004741e9(R)
//              short             Stack[0x3c]:2  param_15                  XREF[4]:     00473fde(R), 004740a4(W), 00474145(W), 004741af(W)
//              long              Stack[0x40]:4  param_16                  XREF[1]:     00473fef(R)
//              long              Stack[0x44]:4  param_17                  XREF[1]:     0047400c(R)
//              char *            Stack[0x48]:4  param_18
//              long              Stack[0x4c]:4  param_19                  XREF[1]:     00474016(R)
//              long              Stack[0x50]:4  param_20                  XREF[1]:     00474020(R)
//              char * *          Stack[0x54]:4  param_21                  XREF[2]:     004740dc(R), 004741e4(R)
//              short             Stack[0x58]:2  param_22                  XREF[1]:     004741e0(R)
//              long              Stack[0x5c]:4  param_23                  XREF[1]:     0047402a(R)
//              char *            Stack[0x60]:4  param_24
//              char *            Stack[0x64]:4  param_25
//              char *            Stack[0x68]:4  param_26
//              char *            Stack[0x6c]:4  param_27
//              long              Stack[0x70]:4  param_28                  XREF[1]:     00474034(R)
//              long              Stack[0x74]:4  param_29                  XREF[1]:     00474041(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     004740aa(W), 004740c1(W), 0047414b(W), 00474163(W),
//                                                                                     004741b5(W), 004741cc(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0047431c(R)
//                               ?setup@TDropDownPanel@@QAEJPAVTDrawArea@@PAVTPanel@@PAXJJHE  XREF[1]:     create_drop_down:0046954d(c)
//                               TDropDownPanel::setup
//                              Pnl_drop.cpp:65 (14)
//         00473fd0     MOV        EAX,FS:[0x0]
//         00473fd6     PUSH       -0x1
//         00473fd8     PUSH       FUN_0055e44c
//         00473fdd     PUSH       EAX
//                              Pnl_drop.cpp:66 (17)
//         00473fde     MOV        AX,word ptr [ESP + param_15]
//         00473fe3     MOV        dword ptr FS:[0x0],ESP
//         00473fea     PUSH       EBX
//         00473feb     PUSH       EBP
//         00473fec     PUSH       ESI
//         00473fed     MOV        ESI,this
//                              Pnl_drop.cpp:68 (4)
//         00473fef     MOV        this,dword ptr [ESP + param_16]
//                              Pnl_drop.cpp:78 (107)
//         00473ff3     MOV        EBP,dword ptr [ESP + param_9]
//         00473ff7     MOV        word ptr [ESI + 0x108],AX
//         00473ffe     MOV        EAX,dword ptr [ESP + param_12]
//         00474002     MOV        EDX,EAX
//         00474004     MOV        dword ptr [ESI + 0x114],this
//         0047400a     SUB        EDX,this
//         0047400c     MOV        this,dword ptr [ESP + param_17]
//         00474010     MOV        dword ptr [ESI + 0x118],this
//         00474016     MOV        this,dword ptr [ESP + param_19]
//         0047401a     MOV        dword ptr [ESI + 0x11c],this
//         00474020     MOV        this,dword ptr [ESP + param_20]
//         00474024     MOV        dword ptr [ESI + 0x120],this
//         0047402a     MOV        this,dword ptr [ESP + param_23]
//         0047402e     MOV        dword ptr [ESI + 0x124],this
//         00474034     MOV        this,dword ptr [ESP + param_28]
//         0047403b     MOV        dword ptr [ESI + 0x128],this
//         00474041     MOV        this,dword ptr [ESP + param_29]
//         00474048     DEC        EDX
//         00474049     MOV        dword ptr [ESI + 0x12c],this
//         0047404f     MOV        dword ptr [ESI + 0x10c],EDX
//         00474055     MOV        EDX,dword ptr [ESP + param_13]
//         00474059     MOV        EBX,dword ptr [ESP + param_5]
//         0047405d     PUSH       EDI
//                              Pnl_drop.cpp:80 (57)
//         0047405e     MOV        EDI,dword ptr [ESP + param_1]
//         00474062     MOV        this,EBP
//         00474064     PUSH       0x0
//         00474066     MOV        dword ptr [ESI + 0x110],EDX
//         0047406c     AND        this,0xff
//         00474072     PUSH       EDX
//         00474073     MOV        EDX,dword ptr [ESP + param_11]
//         00474077     PUSH       EAX
//         00474078     MOV        EAX,dword ptr [ESP + param_10]
//         0047407c     MOV        dword ptr [ESI + 0x138],this
//         00474082     MOV        this,dword ptr [ESP + param_2]
//         00474086     PUSH       EDX
//         00474087     PUSH       EAX
//         00474088     PUSH       this
//         00474089     PUSH       EDI
//         0047408a     MOV        this,ESI
//         0047408c     MOV        dword ptr [ESI + 0x134],EBX
//         00474092     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
//                              Pnl_drop.cpp:83 (40)
//         00474097     PUSH       0x188
//         0047409c     CALL       operator_new                                     void * operator_new(uint param_1)
//         004740a1     ADD        ESP,0x4
//         004740a4     MOV        dword ptr [ESP + param_15],EAX
//         004740a8     TEST       EAX,EAX
//         004740aa     MOV        dword ptr [ESP + local_4],0x0
//         004740b2     JZ         LAB_004740bd
//         004740b4     MOV        this,EAX
//         004740b6     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
//         004740bb     JMP        LAB_004740bf
//                               LAB_004740bd                                                 XREF[1]:     004740b2(j)
//         004740bd     XOR        EAX,EAX
//                               LAB_004740bf                                                 XREF[1]:     004740bb(j)
//                              Pnl_drop.cpp:84 (22)
//         004740bf     TEST       EAX,EAX
//         004740c1     MOV        dword ptr [ESP + local_4],0xffffffff
//         004740c9     MOV        dword ptr [ESI + 0xf4],EAX
//         004740cf     JZ         LAB_0047431c
//                              Pnl_drop.cpp:88 (84)
//         004740d5     MOVSX      EDX,word ptr [ESI + 0x108]
//         004740dc     MOV        this,dword ptr [ESP + param_21]
//         004740e0     MOV        EDX,dword ptr [this->_padding_ + EDX*0x4]
//         004740e3     MOV        this,dword ptr [ESP + param_14]
//         004740e7     PUSH       EDX
//         004740e8     MOV        EDX,dword ptr [ESP + param_8]
//         004740ec     PUSH       this
//         004740ed     MOV        this,dword ptr [ESP + param_7]
//         004740f1     PUSH       EBP
//         004740f2     PUSH       EDX
//         004740f3     MOV        EDX,dword ptr [ESP + param_6]
//         004740f7     PUSH       this
//         004740f8     MOV        this,dword ptr [ESP + param_4]
//         004740fc     PUSH       EDX
//         004740fd     MOV        EDX,dword ptr [ESP + param_3]
//         00474101     PUSH       0x0
//         00474103     PUSH       EBX
//         00474104     PUSH       this
//         00474105     MOV        this,dword ptr [ESI + 0x110]
//         0047410b     PUSH       EDX
//         0047410c     MOV        EDX,dword ptr [ESI + 0x10c]
//         00474112     PUSH       this
//         00474113     PUSH       EDX
//         00474114     PUSH       0x0
//         00474116     PUSH       0x0
//         00474118     PUSH       ESI
//         00474119     PUSH       EDI
//         0047411a     MOV        this,EAX
//         0047411c     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
//         00474121     TEST       EAX,EAX
//         00474123     JZ         LAB_0047431c
//                              Pnl_drop.cpp:90 (15)
//         00474129     MOV        this,dword ptr [ESI + 0xf4]
//         0047412f     PUSH       0x1
//         00474131     PUSH       0x0
//         00474133     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
//                              Pnl_drop.cpp:93 (41)
//         00474138     PUSH       0x2bc
//         0047413d     CALL       operator_new                                     void * operator_new(uint param_1)
//         00474142     ADD        ESP,0x4
//         00474145     MOV        dword ptr [ESP + param_15],EAX
//         00474149     TEST       EAX,EAX
//         0047414b     MOV        dword ptr [ESP + local_4],0x1
//         00474153     JZ         LAB_0047415f
//         00474155     PUSH       ESI
//         00474156     MOV        this,EAX
//         00474158     CALL       TDropDownButtonPanel::TDropDownButtonPanel       undefined TDropDownButtonPanel(TDropDownButto
//         0047415d     JMP        LAB_00474161
//                               LAB_0047415f                                                 XREF[1]:     00474153(j)
//         0047415f     XOR        EAX,EAX
//                               LAB_00474161                                                 XREF[1]:     0047415d(j)
//                              Pnl_drop.cpp:94 (22)
//         00474161     TEST       EAX,EAX
//         00474163     MOV        dword ptr [ESP + local_4],0xffffffff
//         0047416b     MOV        dword ptr [ESI + 0xf8],EAX
//         00474171     JZ         LAB_0047431c
//                              Pnl_drop.cpp:97 (43)
//         00474177     MOV        this,dword ptr [ESI + 0x118]
//         0047417d     MOV        EDX,dword ptr [ESI + 0x114]
//         00474183     PUSH       0x0
//         00474185     PUSH       0x1
//         00474187     PUSH       0x0
//         00474189     PUSH       0x6
//         0047418b     PUSH       this
//         0047418c     PUSH       EDX
//         0047418d     PUSH       0x0
//         0047418f     PUSH       0x0
//         00474191     PUSH       ESI
//         00474192     PUSH       EDI
//         00474193     MOV        this,EAX
//         00474195     CALL       TButtonPanel::setup                              long setup(TButtonPanel * this, TDrawArea * p
//         0047419a     TEST       EAX,EAX
//         0047419c     JZ         LAB_0047431c
//                              Pnl_drop.cpp:101 (40)
//         004741a2     PUSH       0x1a0
//         004741a7     CALL       operator_new                                     void * operator_new(uint param_1)
//         004741ac     ADD        ESP,0x4
//         004741af     MOV        dword ptr [ESP + param_15],EAX
//         004741b3     TEST       EAX,EAX
//         004741b5     MOV        dword ptr [ESP + local_4],0x2
//         004741bd     JZ         LAB_004741c8
//         004741bf     MOV        this,EAX
//         004741c1     CALL       TListPanel::TListPanel                           undefined TListPanel(TListPanel * this)
//         004741c6     JMP        LAB_004741ca
//                               LAB_004741c8                                                 XREF[1]:     004741bd(j)
//         004741c8     XOR        EAX,EAX
//                               LAB_004741ca                                                 XREF[1]:     004741c6(j)
//                              Pnl_drop.cpp:102 (22)
//         004741ca     TEST       EAX,EAX
//         004741cc     MOV        dword ptr [ESP + local_4],0xffffffff
//         004741d4     MOV        dword ptr [ESI + 0xfc],EAX
//         004741da     JZ         LAB_0047431c
//                              Pnl_drop.cpp:106 (79)
//         004741e0     MOV        this,dword ptr [ESP + param_22]
//         004741e4     MOV        EDX,dword ptr [ESP + param_21]
//         004741e8     PUSH       this
//         004741e9     MOV        this,dword ptr [ESP + param_14]
//         004741ed     PUSH       EDX
//         004741ee     MOV        EDX,dword ptr [ESP + param_8]
//         004741f2     PUSH       this
//         004741f3     MOV        this,dword ptr [ESP + param_7]
//         004741f7     PUSH       EBP
//         004741f8     PUSH       EDX
//         004741f9     MOV        EDX,dword ptr [ESP + param_6]
//         004741fd     PUSH       this
//         004741fe     MOV        this,dword ptr [ESP + param_4]
//         00474202     PUSH       EDX
//         00474203     MOV        EDX,dword ptr [ESP + param_3]
//         00474207     PUSH       0x0
//         00474209     PUSH       EBX
//         0047420a     PUSH       this
//         0047420b     MOV        this,dword ptr [ESI + 0x120]
//         00474211     PUSH       EDX
//         00474212     MOV        EDX,dword ptr [ESI + 0x11c]
//         00474218     PUSH       this
//         00474219     PUSH       EDX
//         0047421a     PUSH       0x0
//         0047421c     PUSH       0x0
//         0047421e     PUSH       ESI
//         0047421f     PUSH       EDI
//         00474220     MOV        this,EAX
//         00474222     CALL       TTextPanel::setup                                long setup(TTextPanel * this, TDrawArea * par
//         00474227     TEST       EAX,EAX
//         00474229     JZ         LAB_0047431c
//                              Pnl_drop.cpp:108 (13)
//         0047422f     MOV        this,dword ptr [ESI + 0xfc]
//         00474235     PUSH       0x1
//         00474237     CALL       TListPanel::set_auto_track                       void set_auto_track(TListPanel * this, int pa
//                              Pnl_drop.cpp:109 (13)
//         0047423c     MOV        this,dword ptr [ESI + 0xfc]
//         00474242     PUSH       0x0
//         00474244     MOV        EAX,dword ptr [this->_padding_]
//         00474246     CALL       dword ptr [EAX + 0x14]
//                              Pnl_drop.cpp:110 (19)
//         00474249     MOVSX      this,word ptr [ESI + 0x108]
//         00474250     PUSH       this
//         00474251     MOV        this,dword ptr [ESI + 0xfc]
//         00474257     CALL       TTextPanel::setCurrentLineNumber                 void setCurrentLineNumber(TTextPanel * this,
//                              Pnl_drop.cpp:113 (40)
//         0047425c     PUSH       0x1c4
//         00474261     CALL       operator_new                                     void * operator_new(uint param_1)
//         00474266     ADD        ESP,0x4
//         00474269     MOV        dword ptr [ESP + 0x58],EAX
//         0047426d     TEST       EAX,EAX
//         0047426f     MOV        dword ptr [ESP + 0x18],0x3
//         00474277     JZ         LAB_00474282
//         00474279     MOV        this,EAX
//         0047427b     CALL       TScrollBarPanel::TScrollBarPanel                 undefined TScrollBarPanel(TScrollBarPanel * t
//         00474280     JMP        LAB_00474284
//                               LAB_00474282                                                 XREF[1]:     00474277(j)
//         00474282     XOR        EAX,EAX
//                               LAB_00474284                                                 XREF[1]:     00474280(j)
//                              Pnl_drop.cpp:114 (22)
//         00474284     TEST       EAX,EAX
//         00474286     MOV        dword ptr [ESP + 0x18],0xffffffff
//         0047428e     MOV        dword ptr [ESI + 0x100],EAX
//         00474294     JZ         LAB_0047431c
//                              Pnl_drop.cpp:117 (83)
//         0047429a     MOVSX      EDX,word ptr [ESP + 0x74]
//         0047429f     MOV        this,dword ptr [ESI + 0xfc]
//         004742a5     PUSH       0x0
//         004742a7     PUSH       EDX
//         004742a8     MOV        EDX,dword ptr [ESI + 0x12c]
//         004742ae     PUSH       this
//         004742af     MOV        this,dword ptr [ESI + 0x128]
//         004742b5     PUSH       EDX
//         004742b6     MOV        EDX,dword ptr [ESI + 0x120]
//         004742bc     PUSH       this
//         004742bd     MOV        this,dword ptr [ESI + 0x124]
//         004742c3     PUSH       s_                                               = ""
//         004742c8     PUSH       s_                                               = ""
//         004742cd     PUSH       s_                                               = ""
//         004742d2     PUSH       s_                                               = ""
//         004742d7     PUSH       EDX
//         004742d8     MOV        EDX,dword ptr [ESI + 0x20]
//         004742db     PUSH       this
//         004742dc     PUSH       0x0
//         004742de     PUSH       0x0
//         004742e0     PUSH       ESI
//         004742e1     PUSH       EDX
//         004742e2     MOV        this,EAX
//         004742e4     CALL       TScrollBarPanel::setup                           long setup(TScrollBarPanel * this, TDrawArea
//         004742e9     TEST       EAX,EAX
//         004742eb     JZ         LAB_0047431c
//                              Pnl_drop.cpp:119 (20)
//         004742ed     MOV        EAX,dword ptr [ESI + 0x100]
//         004742f3     MOV        this,dword ptr [ESI + 0xfc]
//         004742f9     PUSH       0x0
//         004742fb     PUSH       EAX
//         004742fc     CALL       TTextPanel::set_scrollbar                        void set_scrollbar(TTextPanel * this, TScroll
//                              Pnl_drop.cpp:120 (13)
//         00474301     MOV        this,dword ptr [ESI + 0x100]
//         00474307     PUSH       0x0
//         00474309     MOV        EDX,dword ptr [this->_padding_]
//         0047430b     CALL       dword ptr [EDX + 0x14]
//                              Pnl_drop.cpp:122 (9)
//         0047430e     PUSH       0x1
//         00474310     MOV        this,ESI
//         00474312     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:124 (5)
//         00474317     MOV        EAX,0x1
//                               LAB_0047431c                                                 XREF[8]:     004740cf(j), 00474123(j),
//                                                                                                         00474171(j), 0047419c(j),
//                                                                                                         004741da(j), 00474229(j),
//                                                                                                         00474294(j), 004742eb(j)
//                              Pnl_drop.cpp:125 (21)
//         0047431c     MOV        this,dword ptr [ESP + local_c]
//         00474320     POP        EDI
//         00474321     POP        ESI
//         00474322     POP        EBP
//         00474323     MOV        dword ptr FS:[0x0],this
//         0047432a     POP        EBX
//         0047432b     ADD        ESP,0xc
//         0047432e     RET        0x74
//         00474331     ??         90h
//         00474332     NOP
//         00474333     NOP
//         00474334     NOP
//         00474335     NOP
//         00474336     NOP
//         00474337     NOP
//         00474338     NOP
//         00474339     NOP
//         0047433a     NOP
//         0047433b     NOP
//         0047433c     NOP
//         0047433d     NOP
//         0047433e     NOP
//         0047433f     NOP
    return 0;
}

void TDropDownPanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TDropDownPanel * this)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ?draw@TDropDownPanel@@UAEXXZ                                 XREF[1]:     00571210(*)
//                               TDropDownPanel::draw
//                              Pnl_drop.cpp:131 (5)
//         00474340     JMP        TPanel::draw
//         00474345     ??         90h
//         00474346     NOP
//         00474347     NOP
//         00474348     NOP
//         00474349     NOP
//         0047434a     NOP
//         0047434b     NOP
//         0047434c     NOP
//         0047434d     NOP
//         0047434e     NOP
//         0047434f     NOP
    return;
}

long TDropDownPanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_down(TDropDownPanel * this, uchar param
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004743db(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00474374(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00474370(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     004743d7(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     004743d3(R)
//                               ?handle_mouse_down@TDropDownPanel@@UAEJEJJHH@Z               XREF[1]:     00571250(*)
//                               TDropDownPanel::handle_mouse_down
//                              Pnl_drop.cpp:139 (6)
//         00474350     PUSH       EBX
//         00474351     PUSH       EBP
//         00474352     PUSH       ESI
//         00474353     MOV        ESI,this
//         00474355     PUSH       EDI
//                              Pnl_drop.cpp:143 (14)
//         00474356     MOV        EAX,dword ptr [ESI + 0x74]
//         00474359     TEST       EAX,EAX
//         0047435b     JZ         LAB_0047436a
//         0047435d     MOV        this,dword ptr [ESI + 0x40]
//         00474360     TEST       this,this
//         00474362     JZ         LAB_0047436a
//                              Pnl_drop.cpp:144 (6)
//         00474364     PUSH       ESI
//         00474365     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_0047436a                                                 XREF[2]:     0047435b(j), 00474362(j)
//                              Pnl_drop.cpp:146 (19)
//         0047436a     MOV        EAX,dword ptr [ESI + 0x104]
//         00474370     MOV        EDI,dword ptr [ESP + param_3]
//         00474374     MOV        EBX,dword ptr [ESP + param_2]
//         00474378     CMP        EAX,0x2
//         0047437b     JNZ        LAB_004743d3
//                              Pnl_drop.cpp:148 (16)
//         0047437d     MOV        this,dword ptr [ESI + 0xfc]
//         00474383     PUSH       EDI
//         00474384     PUSH       EBX
//         00474385     MOV        EAX,dword ptr [this->_padding_]
//         00474387     CALL       dword ptr [EAX + 0xbc]
//                              Pnl_drop.cpp:150 (12)
//         0047438d     MOV        this,dword ptr [ESI + 0x100]
//         00474393     MOV        EBP,EAX
//         00474395     TEST       this,this
//         00474397     JZ         LAB_004743a5
//                              Pnl_drop.cpp:151 (10)
//         00474399     MOV        EDX,dword ptr [this->_padding_]
//         0047439b     PUSH       EDI
//         0047439c     PUSH       EBX=>DAT_fffffff8
//         0047439d     CALL       dword ptr [EDX + 0xbc]
//                              Pnl_drop.cpp:152 (2)
//         004743a3     JMP        LAB_004743a7
//                               LAB_004743a5                                                 XREF[1]:     00474397(j)
//                              Pnl_drop.cpp:153 (2)
//         004743a5     XOR        EAX,EAX
//                               LAB_004743a7                                                 XREF[1]:     004743a3(j)
//                              Pnl_drop.cpp:155 (8)
//         004743a7     TEST       EBP,EBP
//         004743a9     JNZ        LAB_004743d3
//         004743ab     TEST       EAX,EAX
//         004743ad     JNZ        LAB_004743d3
//                              Pnl_drop.cpp:157 (9)
//         004743af     PUSH       0x1
//         004743b1     MOV        this,ESI
//         004743b3     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:158 (15)
//         004743b8     MOVSX      EAX,word ptr [ESI + 0x108]
//         004743bf     PUSH       EAX
//         004743c0     MOV        this,ESI
//         004743c2     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              Pnl_drop.cpp:161 (5)
//         004743c7     MOV        EAX,0x1
//                              Pnl_drop.cpp:175 (7)
//         004743cc     POP        EDI
//         004743cd     POP        ESI
//         004743ce     POP        EBP
//         004743cf     POP        EBX
//         004743d0     RET        0x14
//                               LAB_004743d3                                                 XREF[3]:     0047437b(j), 004743a9(j),
//                                                                                                         004743ad(j)
//                              Pnl_drop.cpp:174 (24)
//         004743d3     MOV        this,dword ptr [ESP + param_5]
//         004743d7     MOV        EDX,dword ptr [ESP + param_4]
//         004743db     MOV        EAX,dword ptr [ESP + param_1]
//         004743df     PUSH       this
//         004743e0     PUSH       EDX=>DAT_fffffff8
//         004743e1     PUSH       EDI=>DAT_fffffff4
//         004743e2     PUSH       EBX=>DAT_fffffff0
//         004743e3     PUSH       EAX
//         004743e4     MOV        this,ESI
//         004743e6     CALL       TPanel::handle_mouse_down                        long handle_mouse_down(TPanel * this, uchar p
//                              Pnl_drop.cpp:175 (7)
//         004743eb     POP        EDI
//         004743ec     POP        ESI
//         004743ed     POP        EBP
//         004743ee     POP        EBX
//         004743ef     RET        0x14
//         004743f2     ??         90h
//         004743f3     NOP
//         004743f4     NOP
//         004743f5     NOP
//         004743f6     NOP
//         004743f7     NOP
//         004743f8     NOP
//         004743f9     NOP
//         004743fa     NOP
//         004743fb     NOP
//         004743fc     NOP
//         004743fd     NOP
//         004743fe     NOP
//         004743ff     NOP
    return 0;
}

long TDropDownPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_move(TDropDownPanel * this, long param_
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047440e(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00474409(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00474404(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00474400(R)
//                               ?handle_mouse_move@TDropDownPanel@@UAEJJJHH@Z                XREF[1]:     00571254(*)
//                               TDropDownPanel::handle_mouse_move
//                              Pnl_drop.cpp:181 (25)
//         00474400     MOV        EAX,dword ptr [ESP + param_4]
//         00474404     MOV        EDX,dword ptr [ESP + param_3]
//         00474408     PUSH       EAX
//         00474409     MOV        EAX,dword ptr [ESP + param_2]
//         0047440d     PUSH       EDX
//         0047440e     MOV        EDX,dword ptr [ESP + param_1]
//         00474412     PUSH       EAX
//         00474413     PUSH       EDX
//         00474414     CALL       TPanel::handle_mouse_move                        long handle_mouse_move(TPanel * this, long pa
//                              Pnl_drop.cpp:201 (3)
//         00474419     RET        0x10
//         0047441c     ??         90h
//         0047441d     NOP
//         0047441e     NOP
//         0047441f     NOP
    return 0;
}

long TDropDownPanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_up(TDropDownPanel * this, uchar param_1
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00474433(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0047442e(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00474429(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00474424(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00474420(R)
//                               ?handle_mouse_up@TDropDownPanel@@UAEJEJJHH@Z                 XREF[1]:     00571258(*)
//                               TDropDownPanel::handle_mouse_up
//                              Pnl_drop.cpp:207 (30)
//         00474420     MOV        EAX,dword ptr [ESP + param_5]
//         00474424     MOV        EDX,dword ptr [ESP + param_4]
//         00474428     PUSH       EAX
//         00474429     MOV        EAX,dword ptr [ESP + param_3]
//         0047442d     PUSH       EDX
//         0047442e     MOV        EDX,dword ptr [ESP + param_2]
//         00474432     PUSH       EAX
//         00474433     MOV        EAX,dword ptr [ESP + param_1]
//         00474437     PUSH       EDX
//         00474438     PUSH       EAX
//         00474439     CALL       TPanel::handle_mouse_up                          long handle_mouse_up(TPanel * this, uchar par
//                              Pnl_drop.cpp:213 (3)
//         0047443e     RET        0x14
//         00474441     ??         90h
//         00474442     NOP
//         00474443     NOP
//         00474444     NOP
//         00474445     NOP
//         00474446     NOP
//         00474447     NOP
//         00474448     NOP
//         00474449     NOP
//         0047444a     NOP
//         0047444b     NOP
//         0047444c     NOP
//         0047444d     NOP
//         0047444e     NOP
//         0047444f     NOP
    return 0;
}

long TDropDownPanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall handle_key_down(TDropDownPanel * this, long param_1,
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00474455(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     0047448c(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00474487(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00474482(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0047447d(R)
//                               ?handle_key_down@TDropDownPanel@@UAEJJFHHH@Z                 XREF[1]:     00571238(*)
//                               TDropDownPanel::handle_key_down
//                              Pnl_drop.cpp:219 (30)
//         00474450     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00474453     TEST       EAX,EAX
//         00474455     MOV        EAX,dword ptr [ESP + param_1]
//         00474459     JZ         LAB_0047447d
//         0047445b     CMP        EAX,0x28
//         0047445e     JZ         LAB_00474465
//         00474460     CMP        EAX,0x26
//         00474463     JNZ        LAB_0047447d
//                               LAB_00474465                                                 XREF[1]:     0047445e(j)
//         00474465     CMP        dword ptr [ECX + this->mode],0x1
//         0047446c     JNZ        LAB_0047447d
//                              Pnl_drop.cpp:222 (7)
//         0047446e     PUSH       0x2
//         00474470     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:223 (5)
//         00474475     MOV        EAX,0x1
//                              Pnl_drop.cpp:226 (3)
//         0047447a     RET        0x14
//                               LAB_0047447d                                                 XREF[3]:     00474459(j), 00474463(j),
//                                                                                                         0047446c(j)
//                              Pnl_drop.cpp:225 (26)
//         0047447d     MOV        EDX,dword ptr [ESP + param_5]
//         00474481     PUSH       EDX
//         00474482     MOV        EDX,dword ptr [ESP + param_4]
//         00474486     PUSH       EDX
//         00474487     MOV        EDX,dword ptr [ESP + param_3]
//         0047448b     PUSH       EDX
//         0047448c     MOV        EDX,dword ptr [ESP + param_2]
//         00474490     PUSH       EDX
//         00474491     PUSH       EAX
//         00474492     CALL       TPanel::handle_key_down                          long handle_key_down(TPanel * this, long para
//                              Pnl_drop.cpp:226 (3)
//         00474497     RET        0x14
//         0047449a     ??         90h
//         0047449b     NOP
//         0047449c     NOP
//         0047449d     NOP
//         0047449e     NOP
//         0047449f     NOP
    return 0;
}

long TDropDownPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TDropDownPanel * this, TPanel * param_1, long
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004744a1(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004744a6(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004744ae(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0047452c(R)
//                               ?action@TDropDownPanel@@UAEJPAVTPanel@@JKK@Z                 XREF[1]:     00571294(*)
//                               TDropDownPanel::action
//                              Pnl_drop.cpp:232 (1)
//         004744a0     PUSH       EBX
//                              Pnl_drop.cpp:233 (25)
//         004744a1     MOV        EBX,dword ptr [ESP + param_1]
//         004744a5     PUSH       EBP
//         004744a6     MOV        EBP,dword ptr [ESP + param_2]
//         004744aa     PUSH       ESI
//         004744ab     MOV        ESI,this
//         004744ad     PUSH       EDI
//         004744ae     MOV        EDI,dword ptr [ESP + param_3]
//         004744b2     CMP        EBX,dword ptr [ESI + 0xf8]
//         004744b8     JNZ        LAB_004744d0
//                              Pnl_drop.cpp:235 (5)
//         004744ba     CMP        EBP,0x2
//         004744bd     JNZ        LAB_0047452c
//                              Pnl_drop.cpp:237 (9)
//         004744bf     CMP        dword ptr [ESI + 0x104],0x1
//         004744c6     JNZ        LAB_0047452c
//                              Pnl_drop.cpp:238 (6)
//         004744c8     PUSH       EBP
//         004744c9     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:241 (12)
//         004744ce     JMP        LAB_0047452c
//                               LAB_004744d0                                                 XREF[1]:     004744b8(j)
//         004744d0     MOV        this,dword ptr [ESI + 0xfc]
//         004744d6     CMP        EBX,this
//         004744d8     JNZ        LAB_0047452c
//                              Pnl_drop.cpp:243 (10)
//         004744da     CMP        EBP,0x3
//         004744dd     JZ         LAB_004744e4
//         004744df     CMP        EBP,0x2
//         004744e2     JNZ        LAB_0047452c
//                               LAB_004744e4                                                 XREF[1]:     004744dd(j)
//                              Pnl_drop.cpp:246 (37)
//         004744e4     MOV        EAX,dword ptr [ESI + 0xf4]
//         004744ea     MOV        word ptr [ESI + 0x108],DI
//         004744f1     MOVSX      EDX,DI
//         004744f4     MOV        EBP,dword ptr [EAX]
//         004744f6     PUSH       EDX
//         004744f7     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004744fc     MOV        this,dword ptr [ESI + 0xf4]
//         00474502     PUSH       EAX
//         00474503     CALL       dword ptr [EBP + 0xe8]
//                              Pnl_drop.cpp:247 (9)
//         00474509     PUSH       0x1
//         0047450b     MOV        this,ESI
//         0047450d     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:248 (7)
//         00474512     MOV        this,dword ptr [ESI + 0x40]
//         00474515     TEST       this,this
//         00474517     JZ         LAB_00474528
//                              Pnl_drop.cpp:249 (19)
//         00474519     MOV        EAX,dword ptr [this->_padding_]
//         0047451b     PUSH       0x0
//         0047451d     PUSH       0x0=>DAT_fffffff8
//         0047451f     PUSH       0x0=>DAT_fffffff4
//         00474521     PUSH       ESI=>DAT_fffffff0
//         00474522     CALL       dword ptr [EAX + 0xb4]
//                               LAB_00474528                                                 XREF[1]:     00474517(j)
//         00474528     MOV        EBP,dword ptr [ESP + 0x18]
//                               LAB_0047452c                                                 XREF[5]:     004744bd(j), 004744c6(j),
//                                                                                                         004744ce(j), 004744d8(j),
//                                                                                                         004744e2(j)
//                              Pnl_drop.cpp:253 (15)
//         0047452c     MOV        this,dword ptr [ESP + param_4]
//         00474530     PUSH       this
//         00474531     PUSH       EDI=>DAT_fffffff8
//         00474532     PUSH       EBP=>DAT_fffffff4
//         00474533     PUSH       EBX=>DAT_fffffff0
//         00474534     MOV        this,ESI
//         00474536     CALL       TPanel::action                                   long action(TPanel * this, TPanel * param_1,
//                              Pnl_drop.cpp:254 (7)
//         0047453b     POP        EDI
//         0047453c     POP        ESI
//         0047453d     POP        EBP
//         0047453e     POP        EBX
//         0047453f     RET        0x10
//         00474542     ??         90h
//         00474543     NOP
//         00474544     NOP
//         00474545     NOP
//         00474546     NOP
//         00474547     NOP
//         00474548     NOP
//         00474549     NOP
//         0047454a     NOP
//         0047454b     NOP
//         0047454c     NOP
//         0047454d     NOP
//         0047454e     NOP
//         0047454f     NOP
    return 0;
}

void TDropDownPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(TDropDownPanel * this, long param_1, long p
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00474560(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00474554(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047455b(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00474550(R)
//                               ?set_rect@TDropDownPanel@@UAEXJJJJ@Z                         XREF[1]:     005711ec(*)
//                               TDropDownPanel::set_rect
//                              Pnl_drop.cpp:262 (30)
//         00474550     MOV        EAX,dword ptr [ESP + param_4]
//         00474554     MOV        EDX,dword ptr [ESP + param_2]
//         00474558     PUSH       ESI
//         00474559     MOV        ESI,this
//         0047455b     MOV        this,dword ptr [ESP + param_3]
//         0047455f     PUSH       EAX
//         00474560     MOV        EAX,dword ptr [ESP + param_1]
//         00474564     PUSH       this
//         00474565     PUSH       EDX
//         00474566     PUSH       EAX
//         00474567     MOV        this,ESI
//         00474569     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
//                              Pnl_drop.cpp:265 (11)
//         0047456e     MOV        EAX,dword ptr [ESI + 0x104]
//         00474574     CMP        EAX,0x1
//         00474577     JNZ        LAB_004745aa
//                              Pnl_drop.cpp:267 (9)
//         00474579     MOV        this,dword ptr [ESI + 0x14]
//         0047457c     MOV        EAX,dword ptr [ESI + 0x114]
//                              Pnl_drop.cpp:268 (6)
//         00474582     MOV        EDX,dword ptr [ESI + 0x18]
//         00474585     SUB        this,EAX
//         00474587     DEC        this
//                              Pnl_drop.cpp:271 (21)
//         00474588     PUSH       0x0
//         0047458a     MOV        dword ptr [ESI + 0x10c],this
//         00474590     MOV        this,ESI
//         00474592     MOV        dword ptr [ESI + 0x110],EDX
//         00474598     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:272 (2)
//         0047459d     PUSH       0x1
//                              Pnl_drop.cpp:281 (7)
//         0047459f     MOV        this,ESI
//         004745a1     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:283 (4)
//         004745a6     POP        ESI
//         004745a7     RET        0x10
//                               LAB_004745aa                                                 XREF[1]:     00474577(j)
//                              Pnl_drop.cpp:274 (5)
//         004745aa     CMP        EAX,0x2
//         004745ad     JNZ        LAB_004745dc
//                              Pnl_drop.cpp:276 (3)
//         004745af     MOV        EAX,dword ptr [ESI + 0x14]
//                              Pnl_drop.cpp:277 (17)
//         004745b2     MOV        this,dword ptr [ESI + 0x18]
//         004745b5     MOV        dword ptr [ESI + 0x11c],EAX
//         004745bb     MOV        EAX,dword ptr [ESI + 0x110]
//         004745c1     SUB        this,EAX
//                              Pnl_drop.cpp:280 (16)
//         004745c3     PUSH       0x1
//         004745c5     DEC        this
//         004745c6     MOV        dword ptr [ESI + 0x120],this
//         004745cc     MOV        this,ESI
//         004745ce     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                              Pnl_drop.cpp:281 (9)
//         004745d3     PUSH       0x2
//         004745d5     MOV        this,ESI
//         004745d7     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                               LAB_004745dc                                                 XREF[1]:     004745ad(j)
//                              Pnl_drop.cpp:283 (4)
//         004745dc     POP        ESI
//         004745dd     RET        0x10
    return;
}

void TDropDownPanel::set_val_text_color(ulong param_1, ulong param_2) {
    /* TODO: Stub */
//                              void __thiscall set_val_text_color(TDropDownPanel * this, ulong para
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              ulong             Stack[0x4]:4   param_1                   XREF[1]:     004745ee(R)
//              ulong             Stack[0x8]:4   param_2                   XREF[1]:     004745ea(R)
//                               ?set_val_text_color@TDropDownPanel@@QAEXKK@Z                 XREF[2]:     create_drop_down:004695cf(c),
//                               TDropDownPanel::set_val_text_color                                        fillPlayers:004a3d6d(c)
//                              Pnl_drop.cpp:289 (10)
//         004745e0     MOV        this,dword ptr [ECX + this->val_panel]
//         004745e6     TEST       this,this
//         004745e8     JZ         LAB_004745f9
//                              Pnl_drop.cpp:291 (15)
//         004745ea     MOV        EAX,dword ptr [ESP + param_2]
//         004745ee     MOV        EDX,dword ptr [ESP + param_1]
//         004745f2     PUSH       EAX
//         004745f3     PUSH       EDX
//         004745f4     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong
//                               LAB_004745f9                                                 XREF[1]:     004745e8(j)
//                              Pnl_drop.cpp:292 (3)
//         004745f9     RET        0x8
//         004745fc     ??         90h
//         004745fd     NOP
//         004745fe     NOP
//         004745ff     NOP
    return;
}

void TDropDownPanel::set_draw_style(DrawStyle param_1) {
    /* TODO: Stub */
//                              void __thiscall set_draw_style(TDropDownPanel * this, DrawStyle para
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              DrawStyle         Stack[0x4]:4   param_1                   XREF[1]:     00474600(R)
//                               ?set_draw_style@TDropDownPanel@@QAEXW4DrawStyle@1@@Z         XREF[3]:     TribeMPSetupScreen:004a0346(c),
//                               TDropDownPanel::set_draw_style                                            TribeMPSetupScreen:004a03db(c),
//                                                                                                         TribeMPSetupScreen:004a0517(c)
//                              Pnl_drop.cpp:298 (10)
//         00474600     MOV        EAX,dword ptr [ESP + param_1]
//         00474604     MOV        dword ptr [ECX + this->draw_style],EAX
//                              Pnl_drop.cpp:302 (10)
//         0047460a     MOV        EAX,dword ptr [ECX + this->val_panel]
//         00474610     TEST       EAX,EAX
//         00474612     JZ         LAB_0047462a
//                              Pnl_drop.cpp:304 (6)
//         00474614     MOV        EAX,dword ptr [ECX + this->mode]
//                              Pnl_drop.cpp:305 (10)
//         0047461a     MOV        dword ptr [ECX + this->mode],0x0
//                              Pnl_drop.cpp:306 (6)
//         00474624     PUSH       EAX
//         00474625     CALL       TDropDownPanel::set_mode                         void set_mode(TDropDownPanel * this, Dropdown
//                               LAB_0047462a                                                 XREF[1]:     00474612(j)
//                              Pnl_drop.cpp:308 (3)
//         0047462a     RET        0x4
//         0047462d     ??         90h
//         0047462e     NOP
//         0047462f     NOP
    return;
}

void TDropDownPanel::set_draw_val_rect(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_draw_val_rect(TDropDownPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00474630(R)
//                               ?set_draw_val_rect@TDropDownPanel@@QAEXH@Z                   XREF[3]:     TribeMPSetupScreen:004a034f(c),
//                               TDropDownPanel::set_draw_val_rect                                         TribeMPSetupScreen:004a03e4(c),
//                                                                                                         TribeMPSetupScreen:004a0520(c)
//                              Pnl_drop.cpp:314 (7)
//         00474630     MOV        EAX,dword ptr [ESP + param_1]
//         00474634     PUSH       ESI
//         00474635     MOV        ESI,this
//                              Pnl_drop.cpp:316 (16)
//         00474637     MOV        this,dword ptr [ESI + 0xf4]
//         0047463d     MOV        dword ptr [ESI + 0x140],EAX
//         00474643     TEST       this,this
//         00474645     JZ         LAB_0047465d
//                              Pnl_drop.cpp:318 (13)
//         00474647     MOV        DL,byte ptr [ESI + 0x138]
//         0047464d     PUSH       EDX
//         0047464e     PUSH       EAX
//         0047464f     CALL       TTextPanel::set_outline                          void set_outline(TTextPanel * this, int param
//                              Pnl_drop.cpp:319 (9)
//         00474654     MOV        EAX,dword ptr [ESI]
//         00474656     PUSH       0x1
//         00474658     MOV        this,ESI
//         0047465a     CALL       dword ptr [EAX + 0x20]
//                               LAB_0047465d                                                 XREF[1]:     00474645(j)
//                              Pnl_drop.cpp:321 (4)
//         0047465d     POP        ESI
//         0047465e     RET        0x4
//         00474661     ??         90h
//         00474662     NOP
//         00474663     NOP
//         00474664     NOP
//         00474665     NOP
//         00474666     NOP
//         00474667     NOP
//         00474668     NOP
//         00474669     NOP
//         0047466a     NOP
//         0047466b     NOP
//         0047466c     NOP
//         0047466d     NOP
//         0047466e     NOP
//         0047466f     NOP
    return;
}

void TDropDownPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              void __thiscall set_bevel_info(TDropDownPanel * this, int param_1, i
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     0047468c(R), 004746e4(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00474676(R), 004746ce(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004746c9(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     004746c2(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     004746bb(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00474672(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0047467e(R)
//                               ?set_bevel_info@TDropDownPanel@@QAEXHHHHHHH@Z                XREF[1]:     create_drop_down:004695ba(c)
//                               TDropDownPanel::set_bevel_info
//                              Pnl_drop.cpp:327 (2)
//         00474670     PUSH       EBX
//         00474671     PUSH       EBP
//                              Pnl_drop.cpp:330 (26)
//         00474672     MOV        EBX,dword ptr [ESP + param_6]
//         00474676     MOV        EBP,dword ptr [ESP + param_2]
//         0047467a     PUSH       ESI
//         0047467b     MOV        ESI,this
//         0047467d     PUSH       EDI
//         0047467e     MOV        EDI,dword ptr [ESP + param_7]
//         00474682     MOV        this,dword ptr [ESI + 0xf4]
//         00474688     TEST       this,this
//         0047468a     JZ         LAB_004746da
//                              Pnl_drop.cpp:332 (17)
//         0047468c     MOV        EAX,dword ptr [ESP + param_1]
//         00474690     DEC        EAX
//         00474691     CMP        EAX,0x3
//         00474694     JA         switchD_00474696::default
//                               switchD_00474696::switchD
//         00474696     JMP        dword ptr [EAX*0x4 + switchD_00474696::switchd   = 0047469d
//                               switchD_00474696::caseD_1                                    XREF[2]:     00474696(j), 004747dc(*)
//                              Pnl_drop.cpp:334 (7)
//         0047469d     MOV        EAX,0x1
//         004746a2     JMP        LAB_004746bb
//                               switchD_00474696::caseD_2                                    XREF[2]:     00474696(j), 004747e0(*)
//                              Pnl_drop.cpp:335 (7)
//         004746a4     MOV        EAX,0x5
//         004746a9     JMP        LAB_004746bb
//                               switchD_00474696::caseD_3                                    XREF[2]:     00474696(j), 004747e4(*)
//                              Pnl_drop.cpp:336 (7)
//         004746ab     MOV        EAX,0x6
//         004746b0     JMP        LAB_004746bb
//                               switchD_00474696::caseD_4                                    XREF[2]:     00474696(j), 004747e8(*)
//                              Pnl_drop.cpp:337 (7)
//         004746b2     MOV        EAX,0x7
//         004746b7     JMP        LAB_004746bb
//                               switchD_00474696::default                                    XREF[1]:     00474694(j)
//                              Pnl_drop.cpp:338 (2)
//         004746b9     XOR        EAX,EAX
//                               LAB_004746bb                                                 XREF[4]:     004746a2(j), 004746a9(j),
//                                                                                                         004746b0(j), 004746b7(j)
//                              Pnl_drop.cpp:340 (31)
//         004746bb     MOV        EBP,dword ptr [ESP + param_5]
//         004746bf     PUSH       EDI
//         004746c0     PUSH       EBX
//         004746c1     PUSH       EBP
//         004746c2     MOV        EBP,dword ptr [ESP + param_4]
//         004746c6     MOV        EDX,dword ptr [this->_padding_]
//         004746c8     PUSH       EBP
//         004746c9     MOV        EBP,dword ptr [ESP + param_3]
//         004746cd     PUSH       EBP
//         004746ce     MOV        EBP,dword ptr [ESP + param_2]
//         004746d2     PUSH       EBP
//         004746d3     PUSH       EAX
//         004746d4     CALL       dword ptr [EDX + 0xec]
//                               LAB_004746da                                                 XREF[1]:     0047468a(j)
//                              Pnl_drop.cpp:343 (10)
//         004746da     MOV        this,dword ptr [ESI + 0xfc]
//         004746e0     TEST       this,this
//         004746e2     JZ         LAB_00474732
//                              Pnl_drop.cpp:345 (17)
//         004746e4     MOV        EAX,dword ptr [ESP + param_1]
//         004746e8     DEC        EAX
//         004746e9     CMP        EAX,0x3
//         004746ec     JA         switchD_004746ee::default
//                               switchD_004746ee::switchD
//         004746ee     JMP        dword ptr [EAX*0x4 + switchD_004746ee::switchd   = 004746f5
//                               switchD_004746ee::caseD_1                                    XREF[2]:     004746ee(j), 004747ec(*)
//                              Pnl_drop.cpp:347 (7)
//         004746f5     MOV        EAX,0x1
//         004746fa     JMP        LAB_00474713
//                               switchD_004746ee::caseD_2                                    XREF[2]:     004746ee(j), 004747f0(*)
//                              Pnl_drop.cpp:348 (7)
//         004746fc     MOV        EAX,0x2
//         00474701     JMP        LAB_00474713
//                               switchD_004746ee::caseD_3                                    XREF[2]:     004746ee(j), 004747f4(*)
//                              Pnl_drop.cpp:349 (7)
//         00474703     MOV        EAX,0x3
//         00474708     JMP        LAB_00474713
//                               switchD_004746ee::caseD_4                                    XREF[2]:     004746ee(j), 004747f8(*)
//                              Pnl_drop.cpp:350 (7)
//         0047470a     MOV        EAX,0x4
//         0047470f     JMP        LAB_00474713
//                               switchD_004746ee::default                                    XREF[1]:     004746ec(j)
//                              Pnl_drop.cpp:351 (2)
//         00474711     XOR        EAX,EAX
//                               LAB_00474713                                                 XREF[4]:     004746fa(j), 00474701(j),
//                                                                                                         00474708(j), 0047470f(j)
//                              Pnl_drop.cpp:353 (31)
//         00474713     MOV        EBP,dword ptr [ESP + 0x24]
//         00474717     PUSH       EDI
//         00474718     PUSH       EBX=>DAT_fffffff8
//         00474719     PUSH       EBP=>DAT_fffffff4
//         0047471a     MOV        EBP,dword ptr [ESP + 0x2c]
//         0047471e     MOV        EDX,dword ptr [this->_padding_]
//         00474720     PUSH       EBP=>DAT_fffffff0
//         00474721     MOV        EBP,dword ptr [ESP + 0x2c]
//         00474725     PUSH       EBP
//         00474726     MOV        EBP,dword ptr [ESP + 0x2c]
//         0047472a     PUSH       EBP
//         0047472b     PUSH       EAX
//         0047472c     CALL       dword ptr [EDX + 0xec]
//                               LAB_00474732                                                 XREF[1]:     004746e2(j)
//                              Pnl_drop.cpp:356 (10)
//         00474732     MOV        this,dword ptr [ESI + 0x100]
//         00474738     TEST       this,this
//         0047473a     JZ         LAB_00474783
//                              Pnl_drop.cpp:358 (17)
//         0047473c     MOV        EAX,dword ptr [ESP + 0x14]
//         00474740     DEC        EAX
//         00474741     CMP        EAX,0x3
//         00474744     JA         switchD_00474746::default
//                               switchD_00474746::switchD
//         00474746     JMP        dword ptr [EAX*0x4 + switchD_00474746::switchd   = 0047474d
//                               switchD_00474746::caseD_1                                    XREF[2]:     00474746(j), 004747fc(*)
//                              Pnl_drop.cpp:360 (7)
//         0047474d     MOV        EAX,0x1
//         00474752     JMP        LAB_0047476b
//                               switchD_00474746::caseD_2                                    XREF[2]:     00474746(j), 00474800(*)
//                              Pnl_drop.cpp:361 (7)
//         00474754     MOV        EAX,0x2
//         00474759     JMP        LAB_0047476b
//                               switchD_00474746::caseD_3                                    XREF[2]:     00474746(j), 00474804(*)
//                              Pnl_drop.cpp:362 (7)
//         0047475b     MOV        EAX,0x3
//         00474760     JMP        LAB_0047476b
//                               switchD_00474746::caseD_4                                    XREF[2]:     00474746(j), 00474808(*)
//                              Pnl_drop.cpp:363 (7)
//         00474762     MOV        EAX,0x4
//         00474767     JMP        LAB_0047476b
//                               switchD_00474746::default                                    XREF[1]:     00474744(j)
//                              Pnl_drop.cpp:364 (2)
//         00474769     XOR        EAX,EAX
//                               LAB_0047476b                                                 XREF[4]:     00474752(j), 00474759(j),
//                                                                                                         00474760(j), 00474767(j)
//                              Pnl_drop.cpp:366 (24)
//         0047476b     MOV        EDX,dword ptr [ESP + 0x24]
//         0047476f     PUSH       EDI
//         00474770     PUSH       EBX=>DAT_fffffff8
//         00474771     PUSH       EDX=>DAT_fffffff4
//         00474772     MOV        EDX,dword ptr [ESP + 0x2c]
//         00474776     PUSH       EDX=>DAT_fffffff0
//         00474777     MOV        EDX,dword ptr [ESP + 0x2c]
//         0047477b     PUSH       EDX
//         0047477c     PUSH       EBP
//         0047477d     PUSH       EAX
//         0047477e     CALL       TScrollBarPanel::set_bevel_info                  void set_bevel_info(TScrollBarPanel * this, i
//                               LAB_00474783                                                 XREF[1]:     0047473a(j)
//                              Pnl_drop.cpp:369 (10)
//         00474783     MOV        this,dword ptr [ESI + 0xf8]
//         00474789     TEST       this,this
//         0047478b     JZ         LAB_004747d4
//                              Pnl_drop.cpp:371 (17)
//         0047478d     MOV        EAX,dword ptr [ESP + 0x14]
//         00474791     DEC        EAX
//         00474792     CMP        EAX,0x3
//         00474795     JA         switchD_00474797::default
//                               switchD_00474797::switchD
//         00474797     JMP        dword ptr [EAX*0x4 + switchD_00474797::switchd   = 0047479e
//                               switchD_00474797::caseD_1                                    XREF[2]:     00474797(j), 0047480c(*)
//                              Pnl_drop.cpp:373 (7)
//         0047479e     MOV        EAX,0x1
//         004747a3     JMP        LAB_004747bc
//                               switchD_00474797::caseD_2                                    XREF[2]:     00474797(j), 00474810(*)
//                              Pnl_drop.cpp:374 (7)
//         004747a5     MOV        EAX,0x2
//         004747aa     JMP        LAB_004747bc
//                               switchD_00474797::caseD_3                                    XREF[2]:     00474797(j), 00474814(*)
//                              Pnl_drop.cpp:375 (7)
//         004747ac     MOV        EAX,0x3
//         004747b1     JMP        LAB_004747bc
//                               switchD_00474797::caseD_4                                    XREF[2]:     00474797(j), 00474818(*)
//                              Pnl_drop.cpp:376 (7)
//         004747b3     MOV        EAX,0x4
//         004747b8     JMP        LAB_004747bc
//                               switchD_00474797::default                                    XREF[1]:     00474795(j)
//                              Pnl_drop.cpp:377 (2)
//         004747ba     XOR        EAX,EAX
//                               LAB_004747bc                                                 XREF[4]:     004747a3(j), 004747aa(j),
//                                                                                                         004747b1(j), 004747b8(j)
//                              Pnl_drop.cpp:379 (24)
//         004747bc     MOV        EDX,dword ptr [ESP + 0x24]
//         004747c0     PUSH       EDI
//         004747c1     PUSH       EBX=>DAT_fffffff8
//         004747c2     PUSH       EDX=>DAT_fffffff4
//         004747c3     MOV        EDX,dword ptr [ESP + 0x2c]
//         004747c7     PUSH       EDX=>DAT_fffffff0
//         004747c8     MOV        EDX,dword ptr [ESP + 0x2c]
//         004747cc     PUSH       EDX
//         004747cd     PUSH       EBP
//         004747ce     PUSH       EAX
//         004747cf     CALL       TButtonPanel::set_bevel_info                     void set_bevel_info(TButtonPanel * this, int
//                               LAB_004747d4                                                 XREF[1]:     0047478b(j)
//                              Pnl_drop.cpp:381 (72)
//         004747d4     POP        EDI
//         004747d5     POP        ESI
//         004747d6     POP        EBP
//         004747d7     POP        EBX
//         004747d8     RET        0x1c
//         004747db     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00474696::switchdataD_004747dc                       XREF[1]:     set_bevel_info:00474696(*)
//         004747dc     addr       switchD_00474696::caseD_1
//         004747e0     addr       switchD_00474696::caseD_2
//         004747e4     addr       switchD_00474696::caseD_3
//         004747e8     addr       switchD_00474696::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004746ee::switchdataD_004747ec                       XREF[1]:     set_bevel_info:004746ee(*)
//         004747ec     addr       switchD_004746ee::caseD_1
//         004747f0     addr       switchD_004746ee::caseD_2
//         004747f4     addr       switchD_004746ee::caseD_3
//         004747f8     addr       switchD_004746ee::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00474746::switchdataD_004747fc                       XREF[1]:     set_bevel_info:00474746(*)
//         004747fc     addr       switchD_00474746::caseD_1
//         00474800     addr       switchD_00474746::caseD_2
//         00474804     addr       switchD_00474746::caseD_3
//         00474808     addr       switchD_00474746::caseD_4
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00474797::switchdataD_0047480c                       XREF[1]:     set_bevel_info:00474797(*)
//         0047480c     addr       switchD_00474797::caseD_1
//         00474810     addr       switchD_00474797::caseD_2
//         00474814     addr       switchD_00474797::caseD_3
//         00474818     addr       switchD_00474797::caseD_4
//         0047481c     ??         90h
//         0047481d     ??         90h
//         0047481e     ??         90h
//         0047481f     ??         90h
    return;
}

void TDropDownPanel::set_buttons(TShape* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              void __thiscall set_buttons(TDropDownPanel * this, TShape * param_1,
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              TShape *          Stack[0x4]:4   param_1                   XREF[1]:     00474824(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00474836(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00474861(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0047485c(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00474857(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     00474853(R)
//                               ?set_buttons@TDropDownPanel@@QAEXPAVTShape@@HHHHH@Z          XREF[1]:     create_drop_down:00469571(c)
//                               TDropDownPanel::set_buttons
//                              Pnl_drop.cpp:387 (4)
//         00474820     PUSH       ESI
//         00474821     MOV        ESI,this
//         00474823     PUSH       EDI
//                              Pnl_drop.cpp:388 (14)
//         00474824     MOV        EDI,dword ptr [ESP + param_1]
//         00474828     MOV        this,dword ptr [ESI + 0xf8]
//         0047482e     TEST       this,this
//         00474830     JZ         LAB_00474849
//                              Pnl_drop.cpp:390 (4)
//         00474832     TEST       EDI,EDI
//         00474834     JZ         LAB_0047483e
//                              Pnl_drop.cpp:393 (6)
//         00474836     MOV        EAX,dword ptr [ESP + param_2]
//         0047483a     PUSH       EAX
//         0047483b     PUSH       EDI
//                              Pnl_drop.cpp:395 (2)
//         0047483c     JMP        LAB_00474842
//                               LAB_0047483e                                                 XREF[1]:     00474834(j)
//                              Pnl_drop.cpp:397 (11)
//         0047483e     PUSH       -0x1
//         00474840     PUSH       0x0
//                               LAB_00474842                                                 XREF[1]:     0047483c(j)
//         00474842     PUSH       0x0
//         00474844     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
//                               LAB_00474849                                                 XREF[1]:     00474830(j)
//                              Pnl_drop.cpp:400 (10)
//         00474849     MOV        this,dword ptr [ESI + 0x100]
//         0047484f     TEST       this,this
//         00474851     JZ         LAB_0047486d
//                              Pnl_drop.cpp:401 (26)
//         00474853     MOV        EDX,dword ptr [ESP + param_6]
//         00474857     MOV        EAX,dword ptr [ESP + param_5]
//         0047485b     PUSH       EDX
//         0047485c     MOV        EDX,dword ptr [ESP + param_4]
//         00474860     PUSH       EAX
//         00474861     MOV        EAX,dword ptr [ESP + param_3]
//         00474865     PUSH       EDX
//         00474866     PUSH       EAX
//         00474867     PUSH       EDI
//         00474868     CALL       TScrollBarPanel::set_buttons                     void set_buttons(TScrollBarPanel * this, TSha
//                               LAB_0047486d                                                 XREF[1]:     00474851(j)
//                              Pnl_drop.cpp:402 (5)
//         0047486d     POP        EDI
//         0047486e     POP        ESI
//         0047486f     RET        0x18
//         00474872     ??         90h
//         00474873     NOP
//         00474874     NOP
//         00474875     NOP
//         00474876     NOP
//         00474877     NOP
//         00474878     NOP
//         00474879     NOP
//         0047487a     NOP
//         0047487b     NOP
//         0047487c     NOP
//         0047487d     NOP
//         0047487e     NOP
//         0047487f     NOP
    return;
}

void TDropDownPanel::set_mode(DropdownMode param_1) {
    /* TODO: Stub */
//                              void __thiscall set_mode(TDropDownPanel * this, DropdownMode param_1)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              DropdownMode      Stack[0x4]:4   param_1                   XREF[3]:     00474880(R), 004748f2(R), 004750f5(R)
//              long              Stack[-0x8]:4  calc_wid                  XREF[1]:     004748f6(W)
//              DropdownMode      Stack[-0xc]:4  save_mode                 XREF[2]:     004748ac(W), 004748d4(W)
//              long              Stack[-0x10]:4 parent_x                  XREF[2]:     004748ba(W), 004748d8(W)
//              long              Stack[-0x14]:4 parent_y
//                               ?set_mode@TDropDownPanel@@QAEXW4DropdownMode@1@@Z            XREF[10]:    setup:00474312(c),
//                               TDropDownPanel::set_mode                                                  handle_mouse_down:004743b3(c),
//                                                                                                         handle_key_down:00474470(c),
//                                                                                                         action:004744c9(c),
//                                                                                                         action:0047450d(c),
//                                                                                                         set_rect:00474598(c),
//                                                                                                         set_rect:004745a1(c),
//                                                                                                         set_rect:004745ce(c),
//                                                                                                         set_rect:004745d7(c),
//                                                                                                         set_draw_style:00474625(c)
//                              Pnl_drop.cpp:408 (22)
//         00474880     MOV        EAX,dword ptr [ESP + param_1]
//         00474884     SUB        ESP,0x10
//         00474887     PUSH       ESI
//         00474888     MOV        ESI,this
//         0047488a     CMP        EAX,dword ptr [ESI + 0x104]
//         00474890     JZ         LAB_00475102
//                              Pnl_drop.cpp:423 (12)
//         00474896     MOV        this,dword ptr [ESI + 0x40]
//         00474899     XOR        EDX,EDX
//         0047489b     PUSH       EDI
//         0047489c     PUSH       EBP
//         0047489d     CMP        this,EDX
//         0047489f     PUSH       EBX
//         004748a0     JZ         LAB_004748d1
//                              Pnl_drop.cpp:425 (5)
//         004748a2     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//                              Pnl_drop.cpp:426 (14)
//         004748a7     MOV        this,dword ptr [ESI + 0x40]
//         004748aa     MOV        EBP,EAX
//         004748ac     MOV        dword ptr [ESP + save_mode],EBP
//         004748b0     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//                              Pnl_drop.cpp:427 (14)
//         004748b5     MOV        this,dword ptr [ESI + 0x40]
//         004748b8     MOV        EBX,EAX
//         004748ba     MOV        dword ptr [ESP + parent_x],EBX
//         004748be     CALL       TPanel::width                                    long width(TPanel * this)
//                              Pnl_drop.cpp:428 (10)
//         004748c3     MOV        this,dword ptr [ESI + 0x40]
//         004748c6     MOV        EDI,EAX
//         004748c8     CALL       TPanel::height                                   long height(TPanel * this)
//                              Pnl_drop.cpp:430 (4)
//         004748cd     XOR        EDX,EDX
//         004748cf     JMP        LAB_004748e6
//                               LAB_004748d1                                                 XREF[1]:     004748a0(j)
//                              Pnl_drop.cpp:434 (11)
//         004748d1     MOV        EAX,dword ptr [ESI + 0x20]
//         004748d4     MOV        dword ptr [ESP + save_mode],EDX
//         004748d8     MOV        dword ptr [ESP + parent_x],EDX
//                              Pnl_drop.cpp:435 (10)
//         004748dc     MOV        EBP,EDX
//         004748de     MOV        EDI,dword ptr [EAX + 0x18]
//         004748e1     MOV        EAX,dword ptr [EAX + 0x1c]
//         004748e4     MOV        EBX,EDX
//                               LAB_004748e6                                                 XREF[1]:     004748cf(j)
//                              Pnl_drop.cpp:440 (6)
//         004748e6     MOV        this,dword ptr [ESI + 0x104]
//                              Pnl_drop.cpp:441 (6)
//         004748ec     MOV        dword ptr [ESI + 0x104],EDX
//                              Pnl_drop.cpp:443 (17)
//         004748f2     MOV        EDX,dword ptr [ESP + param_1]
//         004748f6     MOV        dword ptr [ESP + calc_wid],this
//         004748fa     CMP        EDX,0x1
//         004748fd     JNZ        LAB_00474aea
//                              Pnl_drop.cpp:447 (19)
//         00474903     CMP        this,0x2
//         00474906     JNZ        LAB_0047493d
//         00474908     MOV        this,dword ptr [ESI + 0x40]
//         0047490b     TEST       this,this
//         0047490d     JZ         LAB_0047493d
//         0047490f     MOV        this,dword ptr [ECX + this->_padding_]
//         00474912     TEST       this,this
//         00474914     JZ         LAB_0047493d
//                              Pnl_drop.cpp:452 (32)
//         00474916     CMP        dword ptr [ESI + 0x24],EBP
//         00474919     JL         LAB_00474936
//         0047491b     CMP        dword ptr [ESI + 0x28],EBX
//         0047491e     JL         LAB_00474936
//         00474920     LEA        EDX,[EDI + EBP*0x1 + -0x1]
//         00474924     MOV        EDI,dword ptr [ESI + 0x2c]
//         00474927     CMP        EDI,EDX
//         00474929     JG         LAB_00474936
//         0047492b     MOV        EDX,dword ptr [ESI + 0x30]
//         0047492e     LEA        EAX,[EAX + EBX*0x1 + -0x1]
//         00474932     CMP        EDX,EAX
//         00474934     JLE        LAB_0047493d
//                               LAB_00474936                                                 XREF[3]:     00474919(j), 0047491e(j),
//                                                                                                         00474929(j)
//                              Pnl_drop.cpp:455 (7)
//         00474936     MOV        EDX,dword ptr [this->_padding_]
//         00474938     PUSH       0x2
//         0047493a     CALL       dword ptr [EDX + 0x20]
//                               LAB_0047493d                                                 XREF[4]:     00474906(j), 0047490d(j),
//                                                                                                         00474914(j), 00474934(j)
//                              Pnl_drop.cpp:459 (13)
//         0047493d     MOV        this,dword ptr [ESI + 0xfc]
//         00474943     PUSH       0x0
//         00474945     MOV        EAX,dword ptr [this->_padding_]
//         00474947     CALL       dword ptr [EAX + 0x14]
//                              Pnl_drop.cpp:460 (13)
//         0047494a     MOV        this,dword ptr [ESI + 0x100]
//         00474950     PUSH       0x0
//         00474952     MOV        EDX,dword ptr [this->_padding_]
//         00474954     CALL       dword ptr [EDX + 0x14]
//                              Pnl_drop.cpp:463 (9)
//         00474957     CMP        dword ptr [ESI + 0x13c],0x1
//         0047495e     JNZ        LAB_004749af
//                              Pnl_drop.cpp:465 (45)
//         00474960     MOV        EAX,dword ptr [ESI + 0x118]
//         00474966     MOV        EDX,dword ptr [ESI + 0x114]
//         0047496c     MOV        this,dword ptr [ESI + 0xf8]
//         00474972     PUSH       0x0
//         00474974     PUSH       0x0=>DAT_fffffff8
//         00474976     PUSH       0x0=>DAT_fffffff4
//         00474978     MOV        EDI,dword ptr [this->_padding_]
//         0047497a     PUSH       0x0=>DAT_fffffff0
//         0047497c     PUSH       EAX
//         0047497d     PUSH       EAX
//         0047497e     PUSH       EDX
//         0047497f     PUSH       EDX
//         00474980     PUSH       0x0
//         00474982     PUSH       0x1
//         00474984     PUSH       0x0
//         00474986     PUSH       0x0
//         00474988     PUSH       0x7
//         0047498a     CALL       dword ptr [EDI + 0x18]
//                              Pnl_drop.cpp:466 (32)
//         0047498d     MOV        this,dword ptr [ESI + 0xf4]
//         00474993     MOV        EAX,dword ptr [ESI + 0x110]
//         00474999     MOV        EDX,dword ptr [ESI + 0x10c]
//         0047499f     MOV        EBX,dword ptr [ESI + 0xf8]
//         004749a5     MOV        EDI,dword ptr [this->_padding_]
//         004749a7     PUSH       0x0
//         004749a9     PUSH       0x0=>DAT_fffffff8
//         004749ab     PUSH       0x0=>DAT_fffffff4
//                              Pnl_drop.cpp:468 (2)
//         004749ad     JMP        LAB_004749fc
//                               LAB_004749af                                                 XREF[1]:     0047495e(j)
//                              Pnl_drop.cpp:470 (45)
//         004749af     MOV        EAX,dword ptr [ESI + 0x110]
//         004749b5     MOV        EDX,dword ptr [ESI + 0x10c]
//         004749bb     MOV        this,dword ptr [ESI + 0xf4]
//         004749c1     PUSH       0x0
//         004749c3     PUSH       0x0=>DAT_fffffff8
//         004749c5     PUSH       0x0=>DAT_fffffff4
//         004749c7     MOV        EDI,dword ptr [this->_padding_]
//         004749c9     PUSH       0x0=>DAT_fffffff0
//         004749cb     PUSH       EAX
//         004749cc     PUSH       EAX
//         004749cd     PUSH       EDX
//         004749ce     PUSH       EDX
//         004749cf     PUSH       0x0
//         004749d1     PUSH       0x1
//         004749d3     PUSH       0x0
//         004749d5     PUSH       0x0
//         004749d7     PUSH       0x7
//         004749d9     CALL       dword ptr [EDI + 0x18]
//                              Pnl_drop.cpp:471 (50)
//         004749dc     MOV        this,dword ptr [ESI + 0xf8]
//         004749e2     MOV        EAX,dword ptr [ESI + 0x118]
//         004749e8     MOV        EDX,dword ptr [ESI + 0x114]
//         004749ee     MOV        EBX,dword ptr [ESI + 0xf4]
//         004749f4     MOV        EDI,dword ptr [this->_padding_]
//         004749f6     PUSH       0x0
//         004749f8     PUSH       0x0=>DAT_fffffff8
//         004749fa     PUSH       0x0=>DAT_fffffff4
//                               LAB_004749fc                                                 XREF[1]:     004749ad(j)
//         004749fc     PUSH       EBX=>DAT_fffffff0
//         004749fd     PUSH       EAX
//         004749fe     PUSH       EAX
//         004749ff     PUSH       EDX
//         00474a00     PUSH       EDX
//         00474a01     PUSH       0x0
//         00474a03     PUSH       0x0
//         00474a05     PUSH       0x0
//         00474a07     PUSH       0x1
//         00474a09     PUSH       0x7
//         00474a0b     CALL       dword ptr [EDI + 0x18]
//                              Pnl_drop.cpp:476 (12)
//         00474a0e     MOV        EAX,dword ptr [ESI + 0x10c]
//         00474a14     MOV        this,dword ptr [ESI + 0x114]
//                              Pnl_drop.cpp:478 (6)
//         00474a1a     MOV        DL,byte ptr [ESI + 0x130]
//                              Pnl_drop.cpp:480 (53)
//         00474a20     MOV        EDI,dword ptr [ESI]
//         00474a22     LEA        this,[EAX + this->_padding_*0x1 + 0x1]
//         00474a26     MOV        EAX,dword ptr [ESI + 0x110]
//         00474a2c     TEST       DL,DL
//         00474a2e     PUSH       EAX
//         00474a2f     MOV        byte ptr [ESI + 0xf1],0x1
//         00474a36     PUSH       this=>DAT_fffffff8
//         00474a37     JZ         LAB_00474a5e
//         00474a39     MOV        EDX,dword ptr [ESI + 0x10]
//         00474a3c     MOV        EBX,dword ptr [ESI + 0x18]
//         00474a3f     ADD        EDX,EBX
//         00474a41     MOV        this,ESI
//         00474a43     SUB        EDX,EAX
//         00474a45     MOV        EAX,dword ptr [ESP + 0x18]
//         00474a49     SUB        EDX,EAX
//         00474a4b     MOV        EAX,dword ptr [ESI + 0xc]
//         00474a4e     SUB        EAX,EBP
//         00474a50     PUSH       EDX=>DAT_fffffff4
//         00474a51     PUSH       EAX=>DAT_fffffff0
//         00474a52     CALL       dword ptr [EDI + 0x1c]
//                              Pnl_drop.cpp:481 (7)
//         00474a55     MOV        byte ptr [ESI + 0x130],0x0
//                              Pnl_drop.cpp:483 (2)
//         00474a5c     JMP        LAB_00474a73
//                               LAB_00474a5e                                                 XREF[1]:     00474a37(j)
//                              Pnl_drop.cpp:484 (21)
//         00474a5e     MOV        this,dword ptr [ESI + 0x10]
//         00474a61     MOV        EBX,dword ptr [ESP + 0x18]
//         00474a65     MOV        EDX,dword ptr [ESI + 0xc]
//         00474a68     SUB        this,EBX
//         00474a6a     SUB        EDX,EBP
//         00474a6c     PUSH       this=>DAT_fffffff4
//         00474a6d     PUSH       EDX=>DAT_fffffff0
//         00474a6e     MOV        this,ESI
//         00474a70     CALL       dword ptr [EDI + 0x1c]
//                               LAB_00474a73                                                 XREF[1]:     00474a5c(j)
//                              Pnl_drop.cpp:487 (7)
//         00474a73     MOV        this,dword ptr [ESI + 0x40]
//         00474a76     TEST       this,this
//         00474a78     JZ         LAB_00474a83
//                              Pnl_drop.cpp:488 (7)
//         00474a7a     MOV        EAX,dword ptr [this->_padding_]
//         00474a7c     PUSH       0x1
//         00474a7e     CALL       dword ptr [EAX + 0x20]
//                              Pnl_drop.cpp:489 (2)
//         00474a81     JMP        LAB_00474a8a
//                               LAB_00474a83                                                 XREF[1]:     00474a78(j)
//                              Pnl_drop.cpp:490 (7)
//         00474a83     PUSH       0x1
//         00474a85     MOV        this,ESI
//         00474a87     CALL       dword ptr [EDI + 0x20]
//                               LAB_00474a8a                                                 XREF[1]:     00474a81(j)
//                              Pnl_drop.cpp:491 (14)
//         00474a8a     MOV        this,dword ptr [ESI + 0xf4]
//         00474a90     PUSH       this
//         00474a91     MOV        this,ESI
//         00474a93     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              Pnl_drop.cpp:493 (11)
//         00474a98     CMP        dword ptr [ESP + 0x18],0x2
//         00474a9d     JNZ        LAB_004750f5
//                              Pnl_drop.cpp:495 (14)
//         00474aa3     MOV        this,panel_system
//         00474aa8     CALL       TPanelSystem::restorePreviousModalPanel          int restorePreviousModalPanel(TPanelSystem *
//         00474aad     TEST       EAX,EAX
//         00474aaf     JNZ        LAB_00474abc
//                              Pnl_drop.cpp:496 (11)
//         00474ab1     PUSH       EAX
//         00474ab2     MOV        this,panel_system
//         00474ab7     CALL       TPanelSystem::setModalPanel                      void setModalPanel(TPanelSystem * this, TPane
//                               LAB_00474abc                                                 XREF[1]:     00474aaf(j)
//                              Pnl_drop.cpp:497 (11)
//         00474abc     MOV        this,dword ptr [ESI + 0x40]
//         00474abf     TEST       this,this
//         00474ac1     JZ         LAB_004750f5
//                              Pnl_drop.cpp:498 (15)
//         00474ac7     MOV        EDX,dword ptr [this->_padding_]
//         00474ac9     PUSH       0x0
//         00474acb     PUSH       0x0=>DAT_fffffff8
//         00474acd     PUSH       offset DAT_fffffff4
//         00474acf     PUSH       ESI=>DAT_fffffff0
//         00474ad0     CALL       dword ptr [EDX + 0xb4]
//                              Pnl_drop.cpp:626 (13)
//         00474ad6     MOV        this,dword ptr [ESP + 0x24]
//         00474ada     POP        EBX
//         00474adb     POP        EBP
//         00474adc     MOV        dword ptr [ESI + 0x104],this
//         00474ae2     POP        EDI
//                              Pnl_drop.cpp:627 (7)
//         00474ae3     POP        ESI
//         00474ae4     ADD        ESP,0x10
//         00474ae7     RET        0x4
//                               LAB_00474aea                                                 XREF[1]:     004748fd(j)
//                              Pnl_drop.cpp:501 (9)
//         00474aea     CMP        EDX,0x2
//         00474aed     JNZ        LAB_004750f5
//                              Pnl_drop.cpp:504 (13)
//         00474af3     MOV        this,dword ptr [ESI + 0xfc]
//         00474af9     PUSH       0x1
//         00474afb     MOV        EAX,dword ptr [this->_padding_]
//         00474afd     CALL       dword ptr [EAX + 0x14]
//                              Pnl_drop.cpp:506 (16)
//         00474b00     MOV        this,dword ptr [ESI + 0xfc]
//         00474b06     MOV        EDI,dword ptr [this->_padding_ + 0x184]
//         00474b0c     TEST       EDI,EDI
//         00474b0e     JNZ        LAB_00474b32
//                              Pnl_drop.cpp:507 (32)
//         00474b10     MOV        EDI,dword ptr [this->_padding_ + 0x180]
//         00474b16     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00474b1b     MOV        this,dword ptr [ESI + 0x134]
//         00474b21     ADD        this,0x2
//         00474b24     IMUL       EAX,this
//         00474b27     LEA        EDX,[EAX + EDI*0x2]
//         00474b2a     MOV        dword ptr [ESI + 0x120],EDX
//                              Pnl_drop.cpp:508 (2)
//         00474b30     JMP        LAB_00474b53
//                               LAB_00474b32                                                 XREF[1]:     00474b0e(j)
//                              Pnl_drop.cpp:509 (33)
//         00474b32     MOV        EBX,dword ptr [this->_padding_ + 0x180]
//         00474b38     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00474b3d     MOV        this,dword ptr [ESI + 0x134]
//         00474b43     LEA        EDX,[ECX + EDI*0x2 + this+0x1]
//         00474b47     IMUL       EAX,EDX
//         00474b4a     LEA        EAX,[EAX + EBX*0x2]
//         00474b4d     MOV        dword ptr [ESI + 0x120],EAX
//                               LAB_00474b53                                                 XREF[1]:     00474b30(j)
//                              Pnl_drop.cpp:511 (29)
//         00474b53     MOV        EAX,dword ptr [ESI + 0x120]
//         00474b59     MOV        this,dword ptr [ESI + 0xfc]
//         00474b5f     PUSH       EAX
//         00474b60     MOV        EAX,dword ptr [ESI + 0x11c]
//         00474b66     MOV        EDX,dword ptr [this->_padding_]
//         00474b68     PUSH       EAX=>DAT_fffffff8
//         00474b69     PUSH       0x0=>DAT_fffffff4
//         00474b6b     PUSH       0x0=>DAT_fffffff0
//         00474b6d     CALL       dword ptr [EDX + 0x1c]
//                              Pnl_drop.cpp:512 (24)
//         00474b70     MOV        this,dword ptr [ESI + 0xfc]
//         00474b76     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00474b7b     MOV        this,dword ptr [ESI + 0xfc]
//         00474b81     MOV        EDI,EAX
//         00474b83     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//                              Pnl_drop.cpp:513 (17)
//         00474b88     MOV        this,dword ptr [ESI + 0x100]
//         00474b8e     CMP        EDI,EAX
//         00474b90     JLE        LAB_00474b9b
//         00474b92     MOV        EDX,dword ptr [this->_padding_]
//         00474b94     PUSH       0x1
//         00474b96     CALL       dword ptr [EDX + 0x14]
//                              Pnl_drop.cpp:514 (2)
//         00474b99     JMP        LAB_00474ba2
//                               LAB_00474b9b                                                 XREF[1]:     00474b90(j)
//                              Pnl_drop.cpp:515 (7)
//         00474b9b     MOV        EAX,dword ptr [this->_padding_]
//         00474b9d     PUSH       0x0
//         00474b9f     CALL       dword ptr [EAX + 0x14]
//                               LAB_00474ba2                                                 XREF[1]:     00474b99(j)
//                              Pnl_drop.cpp:518 (9)
//         00474ba2     CMP        dword ptr [ESI + 0x13c],0x1
//         00474ba9     JNZ        LAB_00474bfa
//                              Pnl_drop.cpp:520 (45)
//         00474bab     MOV        EAX,dword ptr [ESI + 0x118]
//         00474bb1     MOV        EDX,dword ptr [ESI + 0x114]
//         00474bb7     MOV        this,dword ptr [ESI + 0xf8]
//         00474bbd     PUSH       0x0
//         00474bbf     PUSH       0x0=>DAT_fffffff8
//         00474bc1     PUSH       0x0=>DAT_fffffff4
//         00474bc3     MOV        EDI,dword ptr [this->_padding_]
//         00474bc5     PUSH       0x0=>DAT_fffffff0
//         00474bc7     PUSH       EAX
//         00474bc8     PUSH       EAX
//         00474bc9     PUSH       EDX
//         00474bca     PUSH       EDX
//         00474bcb     PUSH       0x0
//         00474bcd     PUSH       0x1
//         00474bcf     PUSH       0x0
//         00474bd1     PUSH       0x0
//         00474bd3     PUSH       0x7
//         00474bd5     CALL       dword ptr [EDI + 0x18]
//                              Pnl_drop.cpp:521 (32)
//         00474bd8     MOV        this,dword ptr [ESI + 0xf4]
//         00474bde     MOV        EAX,dword ptr [ESI + 0x110]
//         00474be4     MOV        EDX,dword ptr [ESI + 0x10c]
//         00474bea     MOV        EBX,dword ptr [ESI + 0xf8]
//         00474bf0     MOV        EDI,dword ptr [this->_padding_]
//         00474bf2     PUSH       0x0
//         00474bf4     PUSH       0x0=>DAT_fffffff8
//         00474bf6     PUSH       0x0=>DAT_fffffff4
//                              Pnl_drop.cpp:523 (2)
//         00474bf8     JMP        LAB_00474c47
//                               LAB_00474bfa                                                 XREF[1]:     00474ba9(j)
//                              Pnl_drop.cpp:525 (45)
//         00474bfa     MOV        EAX,dword ptr [ESI + 0x110]
//         00474c00     MOV        EDX,dword ptr [ESI + 0x10c]
//         00474c06     MOV        this,dword ptr [ESI + 0xf4]
//         00474c0c     PUSH       0x0
//         00474c0e     PUSH       0x0=>DAT_fffffff8
//         00474c10     PUSH       0x0=>DAT_fffffff4
//         00474c12     MOV        EDI,dword ptr [this->_padding_]
//         00474c14     PUSH       0x0=>DAT_fffffff0
//         00474c16     PUSH       EAX
//         00474c17     PUSH       EAX
//         00474c18     PUSH       EDX
//         00474c19     PUSH       EDX
//         00474c1a     PUSH       0x0
//         00474c1c     PUSH       0x1
//         00474c1e     PUSH       0x0
//         00474c20     PUSH       0x0
//         00474c22     PUSH       0x7
//         00474c24     CALL       dword ptr [EDI + 0x18]
//                              Pnl_drop.cpp:526 (50)
//         00474c27     MOV        this,dword ptr [ESI + 0xf8]
//         00474c2d     MOV        EAX,dword ptr [ESI + 0x118]
//         00474c33     MOV        EDX,dword ptr [ESI + 0x114]
//         00474c39     MOV        EBX,dword ptr [ESI + 0xf4]
//         00474c3f     MOV        EDI,dword ptr [this->_padding_]
//         00474c41     PUSH       0x0
//         00474c43     PUSH       0x0=>DAT_fffffff8
//         00474c45     PUSH       0x0=>DAT_fffffff4
//                               LAB_00474c47                                                 XREF[1]:     00474bf8(j)
//         00474c47     PUSH       EBX=>DAT_fffffff0
//         00474c48     PUSH       EAX
//         00474c49     PUSH       EAX
//         00474c4a     PUSH       EDX
//         00474c4b     PUSH       EDX
//         00474c4c     PUSH       0x0
//         00474c4e     PUSH       0x0
//         00474c50     PUSH       0x0
//         00474c52     PUSH       0x1
//         00474c54     PUSH       0x7
//         00474c56     CALL       dword ptr [EDI + 0x18]
//                              Pnl_drop.cpp:529 (46)
//         00474c59     MOV        EDI,dword ptr [ESI + 0xf4]
//         00474c5f     MOV        EAX,dword ptr [ESI + 0x124]
//         00474c65     MOV        this,dword ptr [ESI + 0x100]
//         00474c6b     PUSH       0x0
//         00474c6d     PUSH       0x0=>DAT_fffffff8
//         00474c6f     PUSH       EDI=>DAT_fffffff4
//         00474c70     MOV        EDX,dword ptr [this->_padding_]
//         00474c72     PUSH       0x0=>DAT_fffffff0
//         00474c74     PUSH       0x0
//         00474c76     PUSH       0x0
//         00474c78     PUSH       EAX
//         00474c79     PUSH       EAX
//         00474c7a     PUSH       0x0
//         00474c7c     PUSH       0x0
//         00474c7e     PUSH       0x1
//         00474c80     PUSH       0x1
//         00474c82     PUSH       0xa
//         00474c84     CALL       dword ptr [EDX + 0x18]
//                              Pnl_drop.cpp:530 (47)
//         00474c87     MOV        EDX,dword ptr [ESI + 0x100]
//         00474c8d     PUSH       0x0
//         00474c8f     PUSH       EDX=>DAT_fffffff8
//         00474c90     MOV        EDX,dword ptr [ESI + 0xf4]
//         00474c96     MOV        this,dword ptr [ESI + 0xfc]
//         00474c9c     PUSH       EDX=>DAT_fffffff4
//         00474c9d     PUSH       0x0=>DAT_fffffff0
//         00474c9f     PUSH       0x0
//         00474ca1     MOV        EAX,dword ptr [this->_padding_]
//         00474ca3     PUSH       0x0
//         00474ca5     PUSH       0x0
//         00474ca7     PUSH       0x0
//         00474ca9     PUSH       0x0
//         00474cab     PUSH       0x1
//         00474cad     PUSH       0x1
//         00474caf     PUSH       0x0
//         00474cb1     PUSH       0x8
//         00474cb3     CALL       dword ptr [EAX + 0x18]
//                              Pnl_drop.cpp:535 (12)
//         00474cb6     MOV        EAX,dword ptr [ESI + 0x120]
//         00474cbc     MOV        this,dword ptr [ESI + 0x110]
//                              Pnl_drop.cpp:536 (52)
//         00474cc2     MOV        EDX,dword ptr [ESI + 0x10]
//         00474cc5     MOV        EBX,dword ptr [ESI + 0x11c]
//         00474ccb     LEA        EDI,[EAX + this->_padding_*0x1 + 0x1]
//         00474ccf     MOV        this,dword ptr [ESP + 0x10]
//         00474cd3     MOV        EAX,dword ptr [ESI]
//         00474cd5     SUB        EDX,this
//         00474cd7     MOV        this,dword ptr [ESI + 0xc]
//         00474cda     PUSH       EDI
//         00474cdb     MOV        EAX,dword ptr [EAX + 0x1c]
//         00474cde     PUSH       EBX=>DAT_fffffff8
//         00474cdf     SUB        this,EBP
//         00474ce1     PUSH       EDX=>DAT_fffffff4
//         00474ce2     PUSH       this=>DAT_fffffff0
//         00474ce3     MOV        this,ESI
//         00474ce5     MOV        byte ptr [ESI + 0xf1],0x0
//         00474cec     MOV        dword ptr [ESP + 0x2c],EBX
//         00474cf0     MOV        dword ptr [ESP + 0x28],EAX
//         00474cf4     CALL       EAX
//                              Pnl_drop.cpp:540 (43)
//         00474cf6     MOV        this,dword ptr [ESI + 0xfc]
//         00474cfc     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         00474d01     MOV        this,dword ptr [ESI + 0xfc]
//         00474d07     MOV        EBP,EAX
//         00474d09     CALL       TPanel::height                                   long height(TPanel * this)
//         00474d0e     MOV        EDX,dword ptr [ESI + 0x20]
//         00474d11     ADD        EBP,EAX
//         00474d13     MOV        EAX,dword ptr [EDX + 0x1c]
//         00474d16     SUB        EAX,0x4
//         00474d19     CMP        EBP,EAX
//         00474d1b     JLE        LAB_004750b2
//                              Pnl_drop.cpp:542 (37)
//         00474d21     MOV        this,dword ptr [ESI + 0xfc]
//         00474d27     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         00474d2c     MOV        this,dword ptr [ESI + 0xfc]
//         00474d32     MOV        EBP,EAX
//         00474d34     CALL       TPanel::height                                   long height(TPanel * this)
//         00474d39     MOV        this,dword ptr [ESI + 0x20]
//         00474d3c     ADD        EBP,EAX
//         00474d3e     MOV        EDX,0x4
//         00474d43     MOV        EAX,dword ptr [ECX + this->_padding_]
//                              Pnl_drop.cpp:543 (27)
//         00474d46     MOV        this,dword ptr [ESI + 0xfc]
//         00474d4c     SUB        EDX,EAX
//         00474d4e     ADD        EBP,EDX
//         00474d50     CALL       TPanel::height                                   long height(TPanel * this)
//         00474d55     MOV        EDX,dword ptr [ESI + 0x10]
//         00474d58     MOV        this,0x4
//         00474d5d     SUB        this,EDX
//         00474d5f     ADD        EAX,this
//                              Pnl_drop.cpp:544 (8)
//         00474d61     CMP        EAX,EBP
//         00474d63     JGE        LAB_00474f92
//                              Pnl_drop.cpp:546 (8)
//         00474d69     TEST       EAX,EAX
//         00474d6b     JLE        LAB_00474e48
//                              Pnl_drop.cpp:549 (6)
//         00474d71     MOV        EBX,dword ptr [ESI + 0x120]
//                              Pnl_drop.cpp:552 (33)
//         00474d77     MOV        this,dword ptr [ESI + 0xfc]
//         00474d7d     SUB        EBX,EAX
//         00474d7f     MOV        EDX,dword ptr [this->_padding_]
//         00474d81     MOV        EAX,EBX
//         00474d83     PUSH       EAX
//         00474d84     MOV        EAX,dword ptr [ESI + 0x11c]
//         00474d8a     PUSH       EAX=>DAT_fffffff8
//         00474d8b     PUSH       0x0=>DAT_fffffff4
//         00474d8d     PUSH       0x0=>DAT_fffffff0
//         00474d8f     MOV        dword ptr [ESI + 0x120],EBX
//         00474d95     CALL       dword ptr [EDX + 0x1c]
//                              Pnl_drop.cpp:553 (16)
//         00474d98     MOV        this,dword ptr [ESI + 0xfc]
//         00474d9e     MOV        EDI,dword ptr [this->_padding_ + 0x184]
//         00474da4     TEST       EDI,EDI
//         00474da6     JNZ        LAB_00474dca
//                              Pnl_drop.cpp:554 (32)
//         00474da8     MOV        EDI,dword ptr [this->_padding_ + 0x180]
//         00474dae     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         00474db3     MOV        this,dword ptr [ESI + 0x134]
//         00474db9     ADD        this,0x2
//         00474dbc     IMUL       EAX,this
//         00474dbf     LEA        EDX,[EAX + EDI*0x2]
//         00474dc2     MOV        dword ptr [ESI + 0x120],EDX
//                              Pnl_drop.cpp:555 (2)
//         00474dc8     JMP        LAB_00474deb
//                               LAB_00474dca                                                 XREF[1]:     00474da6(j)
//                              Pnl_drop.cpp:556 (33)
//         00474dca     MOV        EBX,dword ptr [this->_padding_ + 0x180]
//         00474dd0     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         00474dd5     MOV        this,dword ptr [ESI + 0x134]
//         00474ddb     LEA        EDX,[ECX + EDI*0x2 + this+0x1]
//         00474ddf     IMUL       EAX,EDX
//         00474de2     LEA        EAX,[EAX + EBX*0x2]
//         00474de5     MOV        dword ptr [ESI + 0x120],EAX
//                               LAB_00474deb                                                 XREF[1]:     00474dc8(j)
//                              Pnl_drop.cpp:557 (12)
//         00474deb     MOV        EAX,dword ptr [ESI + 0x120]
//         00474df1     MOV        this,dword ptr [ESI + 0x110]
//                              Pnl_drop.cpp:559 (17)
//         00474df7     MOV        EDX,dword ptr [ESI + 0x100]
//         00474dfd     LEA        EDI,[EAX + this->_padding_*0x1 + 0x1]
//         00474e01     MOV        this,dword ptr [EDX + 0x6c]
//         00474e04     TEST       this,this
//         00474e06     JNZ        LAB_00474e48
//                              Pnl_drop.cpp:561 (23)
//         00474e08     MOV        this,dword ptr [ESI + 0xfc]
//         00474e0e     PUSH       EAX
//         00474e0f     MOV        EAX,dword ptr [ESI + 0x11c]
//         00474e15     MOV        EDX,dword ptr [this->_padding_]
//         00474e17     PUSH       EAX=>DAT_fffffff8
//         00474e18     PUSH       0x0=>DAT_fffffff4
//         00474e1a     PUSH       0x0=>DAT_fffffff0
//         00474e1c     CALL       dword ptr [EDX + 0x1c]
//                              Pnl_drop.cpp:562 (28)
//         00474e1f     MOV        this,dword ptr [ESI + 0xfc]
//         00474e25     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00474e2a     MOV        this,dword ptr [ESI + 0xfc]
//         00474e30     MOV        EBX,EAX
//         00474e32     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         00474e37     CMP        EBX,EAX
//         00474e39     JLE        LAB_00474e48
//                              Pnl_drop.cpp:563 (13)
//         00474e3b     MOV        this,dword ptr [ESI + 0x100]
//         00474e41     PUSH       0x1
//         00474e43     MOV        EDX,dword ptr [this->_padding_]
//         00474e45     CALL       dword ptr [EDX + 0x14]
//                               LAB_00474e48                                                 XREF[3]:     00474d6b(j), 00474e06(j),
//                                                                                                         00474e39(j)
//                              Pnl_drop.cpp:568 (9)
//         00474e48     CMP        dword ptr [ESI + 0x13c],0x1
//         00474e4f     JNZ        LAB_00474ea0
//                              Pnl_drop.cpp:570 (45)
//         00474e51     MOV        EAX,dword ptr [ESI + 0x118]
//         00474e57     MOV        EDX,dword ptr [ESI + 0x114]
//         00474e5d     MOV        this,dword ptr [ESI + 0xf8]
//         00474e63     PUSH       0x0
//         00474e65     PUSH       0x0=>DAT_fffffff8
//         00474e67     PUSH       0x0=>DAT_fffffff4
//         00474e69     MOV        EBX,dword ptr [this->_padding_]
//         00474e6b     PUSH       0x0=>DAT_fffffff0
//         00474e6d     PUSH       EAX
//         00474e6e     PUSH       EAX
//         00474e6f     PUSH       EDX
//         00474e70     PUSH       EDX
//         00474e71     PUSH       0x0
//         00474e73     PUSH       0x1
//         00474e75     PUSH       0x0
//         00474e77     PUSH       0x0
//         00474e79     PUSH       0x8
//         00474e7b     CALL       dword ptr [EBX + 0x18]
//                              Pnl_drop.cpp:571 (32)
//         00474e7e     MOV        this,dword ptr [ESI + 0xf4]
//         00474e84     MOV        EAX,dword ptr [ESI + 0x110]
//         00474e8a     MOV        EDX,dword ptr [ESI + 0x10c]
//         00474e90     MOV        EBP,dword ptr [ESI + 0xf8]
//         00474e96     MOV        EBX,dword ptr [this->_padding_]
//         00474e98     PUSH       0x0
//         00474e9a     PUSH       0x0=>DAT_fffffff8
//         00474e9c     PUSH       0x0=>DAT_fffffff4
//                              Pnl_drop.cpp:573 (2)
//         00474e9e     JMP        LAB_00474eed
//                               LAB_00474ea0                                                 XREF[1]:     00474e4f(j)
//                              Pnl_drop.cpp:575 (45)
//         00474ea0     MOV        EAX,dword ptr [ESI + 0x110]
//         00474ea6     MOV        EDX,dword ptr [ESI + 0x10c]
//         00474eac     MOV        this,dword ptr [ESI + 0xf4]
//         00474eb2     PUSH       0x0
//         00474eb4     PUSH       0x0=>DAT_fffffff8
//         00474eb6     PUSH       0x0=>DAT_fffffff4
//         00474eb8     MOV        EBX,dword ptr [this->_padding_]
//         00474eba     PUSH       0x0=>DAT_fffffff0
//         00474ebc     PUSH       EAX
//         00474ebd     PUSH       EAX
//         00474ebe     PUSH       EDX
//         00474ebf     PUSH       EDX
//         00474ec0     PUSH       0x0
//         00474ec2     PUSH       0x1
//         00474ec4     PUSH       0x0
//         00474ec6     PUSH       0x0
//         00474ec8     PUSH       0x8
//         00474eca     CALL       dword ptr [EBX + 0x18]
//                              Pnl_drop.cpp:576 (50)
//         00474ecd     MOV        this,dword ptr [ESI + 0xf8]
//         00474ed3     MOV        EAX,dword ptr [ESI + 0x118]
//         00474ed9     MOV        EDX,dword ptr [ESI + 0x114]
//         00474edf     MOV        EBP,dword ptr [ESI + 0xf4]
//         00474ee5     MOV        EBX,dword ptr [this->_padding_]
//         00474ee7     PUSH       0x0
//         00474ee9     PUSH       0x0=>DAT_fffffff8
//         00474eeb     PUSH       0x0=>DAT_fffffff4
//                               LAB_00474eed                                                 XREF[1]:     00474e9e(j)
//         00474eed     PUSH       EBP=>DAT_fffffff0
//         00474eee     PUSH       EAX
//         00474eef     PUSH       EAX
//         00474ef0     PUSH       EDX
//         00474ef1     PUSH       EDX
//         00474ef2     PUSH       0x0
//         00474ef4     PUSH       0x0
//         00474ef6     PUSH       0x0
//         00474ef8     PUSH       0x1
//         00474efa     PUSH       0x8
//         00474efc     CALL       dword ptr [EBX + 0x18]
//                              Pnl_drop.cpp:579 (46)
//         00474eff     MOV        EBX,dword ptr [ESI + 0xf4]
//         00474f05     MOV        EAX,dword ptr [ESI + 0x124]
//         00474f0b     MOV        this,dword ptr [ESI + 0x100]
//         00474f11     PUSH       EBX
//         00474f12     PUSH       0x0=>DAT_fffffff8
//         00474f14     PUSH       0x0=>DAT_fffffff4
//         00474f16     MOV        EDX,dword ptr [this->_padding_]
//         00474f18     PUSH       0x0=>DAT_fffffff0
//         00474f1a     PUSH       0x0
//         00474f1c     PUSH       0x0
//         00474f1e     PUSH       EAX
//         00474f1f     PUSH       EAX
//         00474f20     PUSH       0x0
//         00474f22     PUSH       0x0
//         00474f24     PUSH       0x1
//         00474f26     PUSH       0x1
//         00474f28     PUSH       0x9
//         00474f2a     CALL       dword ptr [EDX + 0x18]
//                              Pnl_drop.cpp:580 (47)
//         00474f2d     MOV        EDX,dword ptr [ESI + 0xf4]
//         00474f33     MOV        this,dword ptr [ESI + 0xfc]
//         00474f39     PUSH       EDX
//         00474f3a     MOV        EDX,dword ptr [ESI + 0x100]
//         00474f40     PUSH       EDX=>DAT_fffffff8
//         00474f41     PUSH       0x0=>DAT_fffffff4
//         00474f43     MOV        EAX,dword ptr [this->_padding_]
//         00474f45     PUSH       0x0=>DAT_fffffff0
//         00474f47     PUSH       0x0
//         00474f49     PUSH       0x0
//         00474f4b     PUSH       0x0
//         00474f4d     PUSH       0x0
//         00474f4f     PUSH       0x0
//         00474f51     PUSH       0x1
//         00474f53     PUSH       0x1
//         00474f55     PUSH       0x0
//         00474f57     PUSH       0x7
//         00474f59     CALL       dword ptr [EAX + 0x18]
//                              Pnl_drop.cpp:583 (42)
//         00474f5c     MOV        this,dword ptr [ESI + 0x110]
//         00474f62     MOV        EBX,dword ptr [ESP + 0x10]
//         00474f66     MOV        EAX,dword ptr [ESP + 0x1c]
//         00474f6a     MOV        EDX,dword ptr [ESI + 0xc]
//         00474f6d     SUB        this,EDI
//         00474f6f     PUSH       EDI
//         00474f70     MOV        EDI,dword ptr [ESI + 0x10]
//         00474f73     SUB        this,EBX
//         00474f75     ADD        this,EDI
//         00474f77     PUSH       EAX=>DAT_fffffff8
//         00474f78     PUSH       this=>DAT_fffffff4
//         00474f79     MOV        this,dword ptr [ESP + 0x20]
//         00474f7d     SUB        EDX,this
//         00474f7f     MOV        this,ESI
//         00474f81     PUSH       EDX=>DAT_fffffff0
//         00474f82     CALL       dword ptr [ESP + 0x28]
//                              Pnl_drop.cpp:587 (7)
//         00474f86     MOV        byte ptr [ESI + 0x130],0x1
//                              Pnl_drop.cpp:589 (5)
//         00474f8d     JMP        LAB_004750b2
//                               LAB_00474f92                                                 XREF[1]:     00474d63(j)
//                              Pnl_drop.cpp:592 (6)
//         00474f92     MOV        EAX,dword ptr [ESI + 0x120]
//                              Pnl_drop.cpp:595 (31)
//         00474f98     MOV        this,dword ptr [ESI + 0xfc]
//         00474f9e     SUB        EAX,EBP
//         00474fa0     MOV        EDX,dword ptr [this->_padding_]
//         00474fa2     MOV        dword ptr [ESI + 0x120],EAX
//         00474fa8     PUSH       EAX
//         00474fa9     MOV        EAX,dword ptr [ESI + 0x11c]
//         00474faf     PUSH       EAX=>DAT_fffffff8
//         00474fb0     PUSH       0x0=>DAT_fffffff4
//         00474fb2     PUSH       0x0=>DAT_fffffff0
//         00474fb4     CALL       dword ptr [EDX + 0x1c]
//                              Pnl_drop.cpp:596 (16)
//         00474fb7     MOV        this,dword ptr [ESI + 0xfc]
//         00474fbd     MOV        EDI,dword ptr [this->_padding_ + 0x184]
//         00474fc3     TEST       EDI,EDI
//         00474fc5     JNZ        LAB_00474fe9
//                              Pnl_drop.cpp:597 (32)
//         00474fc7     MOV        EDI,dword ptr [this->_padding_ + 0x180]
//         00474fcd     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         00474fd2     MOV        this,dword ptr [ESI + 0x134]
//         00474fd8     ADD        this,0x2
//         00474fdb     IMUL       EAX,this
//         00474fde     LEA        EDX,[EAX + EDI*0x2]
//         00474fe1     MOV        dword ptr [ESI + 0x120],EDX
//                              Pnl_drop.cpp:598 (2)
//         00474fe7     JMP        LAB_0047500a
//                               LAB_00474fe9                                                 XREF[1]:     00474fc5(j)
//                              Pnl_drop.cpp:599 (33)
//         00474fe9     MOV        EBP,dword ptr [this->_padding_ + 0x180]
//         00474fef     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         00474ff4     MOV        this,dword ptr [ESI + 0x134]
//         00474ffa     LEA        EDX,[ECX + EDI*0x2 + this+0x1]
//         00474ffe     IMUL       EAX,EDX
//         00475001     LEA        EAX,[EAX + EBP*0x2]
//         00475004     MOV        dword ptr [ESI + 0x120],EAX
//                               LAB_0047500a                                                 XREF[1]:     00474fe7(j)
//                              Pnl_drop.cpp:600 (12)
//         0047500a     MOV        EAX,dword ptr [ESI + 0x120]
//         00475010     MOV        this,dword ptr [ESI + 0x110]
//                              Pnl_drop.cpp:602 (17)
//         00475016     MOV        EDX,dword ptr [ESI + 0x100]
//         0047501c     LEA        EDI,[EAX + this->_padding_*0x1 + 0x1]
//         00475020     MOV        this,dword ptr [EDX + 0x6c]
//         00475023     TEST       this,this
//         00475025     JNZ        LAB_00475096
//                              Pnl_drop.cpp:604 (23)
//         00475027     MOV        this,dword ptr [ESI + 0xfc]
//         0047502d     PUSH       EAX
//         0047502e     MOV        EAX,dword ptr [ESI + 0x11c]
//         00475034     MOV        EDX,dword ptr [this->_padding_]
//         00475036     PUSH       EAX=>DAT_fffffff8
//         00475037     PUSH       0x0=>DAT_fffffff4
//         00475039     PUSH       0x0=>DAT_fffffff0
//         0047503b     CALL       dword ptr [EDX + 0x1c]
//                              Pnl_drop.cpp:605 (28)
//         0047503e     MOV        this,dword ptr [ESI + 0xfc]
//         00475044     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00475049     MOV        this,dword ptr [ESI + 0xfc]
//         0047504f     MOV        EBP,EAX
//         00475051     CALL       TTextPanel::numberDrawLines                      int numberDrawLines(TTextPanel * this)
//         00475056     CMP        EBP,EAX
//         00475058     JLE        LAB_00475067
//                              Pnl_drop.cpp:606 (13)
//         0047505a     MOV        this,dword ptr [ESI + 0x100]
//         00475060     PUSH       0x1
//         00475062     MOV        EDX,dword ptr [this->_padding_]
//         00475064     CALL       dword ptr [EDX + 0x14]
//                               LAB_00475067                                                 XREF[1]:     00475058(j)
//                              Pnl_drop.cpp:607 (47)
//         00475067     MOV        EDX,dword ptr [ESI + 0x100]
//         0047506d     PUSH       0x0
//         0047506f     PUSH       EDX=>DAT_fffffff8
//         00475070     MOV        EDX,dword ptr [ESI + 0xf4]
//         00475076     MOV        this,dword ptr [ESI + 0xfc]
//         0047507c     PUSH       EDX=>DAT_fffffff4
//         0047507d     PUSH       0x0=>DAT_fffffff0
//         0047507f     PUSH       0x0
//         00475081     MOV        EAX,dword ptr [this->_padding_]
//         00475083     PUSH       0x0
//         00475085     PUSH       0x0
//         00475087     PUSH       0x0
//         00475089     PUSH       0x0
//         0047508b     PUSH       0x1
//         0047508d     PUSH       0x1
//         0047508f     PUSH       0x0
//         00475091     PUSH       0x8
//         00475093     CALL       dword ptr [EAX + 0x18]
//                               LAB_00475096                                                 XREF[1]:     00475025(j)
//                              Pnl_drop.cpp:609 (28)
//         00475096     MOV        EAX,dword ptr [ESI + 0x10]
//         00475099     MOV        this,dword ptr [ESI + 0xc]
//         0047509c     MOV        EDX,dword ptr [ESP + 0x14]
//         004750a0     PUSH       EDI
//         004750a1     PUSH       EBX=>DAT_fffffff8
//         004750a2     MOV        EBX,dword ptr [ESP + 0x18]
//         004750a6     SUB        EAX,EBX
//         004750a8     SUB        this,EDX
//         004750aa     PUSH       EAX=>DAT_fffffff4
//         004750ab     PUSH       this=>DAT_fffffff0
//         004750ac     MOV        this,ESI
//         004750ae     CALL       dword ptr [ESP + 0x28]
//                               LAB_004750b2                                                 XREF[2]:     00474d1b(j), 00474f8d(j)
//                              Pnl_drop.cpp:614 (9)
//         004750b2     MOV        EAX,dword ptr [ESI]
//         004750b4     PUSH       0x1
//         004750b6     MOV        this,ESI
//         004750b8     CALL       dword ptr [EAX + 0x20]
//                              Pnl_drop.cpp:615 (11)
//         004750bb     PUSH       0x0
//         004750bd     PUSH       offset DAT_fffffff8
//         004750bf     MOV        this,ESI
//         004750c1     CALL       TPanel::set_z_order                              void set_z_order(TPanel * this, uchar param_1
//                              Pnl_drop.cpp:616 (14)
//         004750c6     MOV        EDX,dword ptr [ESI + 0xfc]
//         004750cc     MOV        this,ESI
//         004750ce     PUSH       EDX
//         004750cf     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              Pnl_drop.cpp:619 (11)
//         004750d4     PUSH       ESI
//         004750d5     MOV        this,panel_system
//         004750da     CALL       TPanelSystem::setModalPanel                      void setModalPanel(TPanelSystem * this, TPane
//                              Pnl_drop.cpp:620 (7)
//         004750df     MOV        this,dword ptr [ESI + 0x40]
//         004750e2     TEST       this,this
//         004750e4     JZ         LAB_004750f5
//                              Pnl_drop.cpp:621 (15)
//         004750e6     MOV        EAX,dword ptr [this->_padding_]
//         004750e8     PUSH       0x0
//         004750ea     PUSH       0x0=>DAT_fffffff8
//         004750ec     PUSH       offset DAT_fffffff4
//         004750ee     PUSH       ESI=>DAT_fffffff0
//         004750ef     CALL       dword ptr [EAX + 0xb4]
//                               LAB_004750f5                                                 XREF[4]:     00474a9d(j), 00474ac1(j),
//                                                                                                         00474aed(j), 004750e4(j)
//                              Pnl_drop.cpp:626 (13)
//         004750f5     MOV        this,dword ptr [ESP + param_1]
//         004750f9     POP        EBX
//         004750fa     POP        EBP
//         004750fb     MOV        dword ptr [ESI + 0x104],this
//         00475101     POP        EDI
//                               LAB_00475102                                                 XREF[1]:     00474890(j)
//                              Pnl_drop.cpp:627 (7)
//         00475102     POP        ESI
//         00475103     ADD        ESP,0x10
//         00475106     RET        0x4
//         00475109     ??         90h
//         0047510a     NOP
//         0047510b     NOP
//         0047510c     NOP
//         0047510d     NOP
//         0047510e     NOP
//         0047510f     NOP
    return;
}

int TDropDownPanel::numberLines() {
    /* TODO: Stub */
//                              int __thiscall numberLines(TDropDownPanel * this)
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ?numberLines@TDropDownPanel@@QAEHXZ
//                               TDropDownPanel::numberLines
//                              Pnl_drop.cpp:633 (10)
//         00475110     MOV        this,dword ptr [ECX + this->list_panel]
//         00475116     TEST       this,this
//         00475118     JZ         LAB_0047511f
//                              Pnl_drop.cpp:635 (5)
//         0047511a     JMP        TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0047511f                                                 XREF[1]:     00475118(j)
//                              Pnl_drop.cpp:637 (2)
//         0047511f     XOR        EAX,EAX
//                              Pnl_drop.cpp:638 (1)
//         00475121     RET
//         00475122     ??         90h
//         00475123     NOP
//         00475124     NOP
//         00475125     NOP
//         00475126     NOP
//         00475127     NOP
//         00475128     NOP
//         00475129     NOP
//         0047512a     NOP
//         0047512b     NOP
//         0047512c     NOP
//         0047512d     NOP
//         0047512e     NOP
//         0047512f     NOP
    return 0;
}

int TDropDownPanel::currentLineNumber() {
    /* TODO: Stub */
//                              int __thiscall currentLineNumber(TDropDownPanel * this)
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ?currentLineNumber@TDropDownPanel@@QAEHXZ                    XREF[7]:     set_player:004aaf86(c),
//                               TDropDownPanel::currentLineNumber                                         set_player:004aafa1(c),
//                                                                                                         action:004ac544(c),
//                                                                                                         action:004ac551(c),
//                                                                                                         action:004ac5b7(c),
//                                                                                                         action:004ac95f(c),
//                                                                                                         action:004aca0a(c)
//                              Pnl_drop.cpp:644 (10)
//         00475130     MOV        this,dword ptr [ECX + this->list_panel]
//         00475136     TEST       this,this
//         00475138     JZ         LAB_0047513f
//                              Pnl_drop.cpp:646 (5)
//         0047513a     JMP        TTextPanel::currentLineNumber                    int currentLineNumber(TTextPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0047513f                                                 XREF[1]:     00475138(j)
//                              Pnl_drop.cpp:648 (2)
//         0047513f     XOR        EAX,EAX
//                              Pnl_drop.cpp:649 (1)
//         00475141     RET
//         00475142     ??         90h
//         00475143     NOP
//         00475144     NOP
//         00475145     NOP
//         00475146     NOP
//         00475147     NOP
//         00475148     NOP
//         00475149     NOP
//         0047514a     NOP
//         0047514b     NOP
//         0047514c     NOP
//         0047514d     NOP
//         0047514e     NOP
//         0047514f     NOP
    return 0;
}

void TDropDownPanel::setCurrentLineNumber(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setCurrentLineNumber(TDropDownPanel * this, int para
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00475150(R)
//                               ?setCurrentLineNumber@TDropDownPanel@@QAEXH@Z                XREF[25]:    set_scenario_mode:004a9ea0(c),
//                               TDropDownPanel::setCurrentLineNumber                                      set_scenario_mode:004aa378(c),
//                                                                                                         set_scenario_mode:004aa39e(c),
//                                                                                                         set_scenario_mode:004aa3c4(c),
//                                                                                                         set_scenario_mode:004aa425(c),
//                                                                                                         set_scenario_mode:004aa600(c),
//                                                                                                         set_player:004ab142(c),
//                                                                                                         set_player:004ab15e(c),
//                                                                                                         set_player:004ab1c8(c),
//                                                                                                         set_player:004ab232(c),
//                                                                                                         set_player:004ab29c(c),
//                                                                                                         set_unit_player:004ab39f(c),
//                                                                                                         key_down_action:004aba11(c),
//                                                                                                         key_down_action:004aba6b(c),
//                                                                                                         key_down_action:004aba98(c),
//                                                                                                         key_down_action:004abad9(c),
//                                                                                                         key_down_action:004abb10(c),
//                                                                                                         load_victory_cond_from_scenario:00
//                                                                                                         load_victory_cond_from_scenario:00
//                                                                                                         load_victory_cond_from_scenario:00
//                                                                                                         [more]
//                              Pnl_drop.cpp:655 (10)
//         00475150     MOV        EAX,dword ptr [ESP + param_1]
//         00475154     PUSH       EAX
//         00475155     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              Pnl_drop.cpp:657 (3)
//         0047515a     RET        0x4
//         0047515d     ??         90h
//         0047515e     NOP
//         0047515f     NOP
    return;
}

void TDropDownPanel::setCurrentLineId(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setCurrentLineId(TDropDownPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047516d(R)
//                               ?setCurrentLineId@TDropDownPanel@@QAEXH@Z                    XREF[2]:     load_victory_cond_from_scenario:00
//                               TDropDownPanel::setCurrentLineId                                          load_victory_cond_from_scenario:00
//                              Pnl_drop.cpp:663 (3)
//         00475160     PUSH       ESI
//         00475161     MOV        ESI,this
//                              Pnl_drop.cpp:664 (10)
//         00475163     MOV        this,dword ptr [ESI + 0xfc]
//         00475169     TEST       this,this
//         0047516b     JZ         LAB_004751b3
//                              Pnl_drop.cpp:666 (10)
//         0047516d     MOV        EAX,dword ptr [ESP + param_1]
//         00475171     PUSH       EAX
//         00475172     CALL       TTextPanel::set_line_by_id                       void set_line_by_id(TTextPanel * this, long p
//                              Pnl_drop.cpp:668 (11)
//         00475177     MOV        this,dword ptr [ESI + 0xfc]
//         0047517d     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//                              Pnl_drop.cpp:670 (18)
//         00475182     MOV        this,dword ptr [ESI + 0xf4]
//         00475188     MOV        word ptr [ESI + 0x108],AX
//         0047518f     TEST       this,this
//         00475191     JZ         LAB_004751b3
//         00475193     PUSH       EDI
//                              Pnl_drop.cpp:671 (31)
//         00475194     MOV        EDI,dword ptr [this->_padding_]
//         00475196     MOVSX      this,AX
//         00475199     PUSH       this
//         0047519a     MOV        this,dword ptr [ESI + 0xfc]
//         004751a0     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004751a5     MOV        this,dword ptr [ESI + 0xf4]
//         004751ab     PUSH       EAX
//         004751ac     CALL       dword ptr [EDI + 0xe8]
//         004751b2     POP        EDI
//                               LAB_004751b3                                                 XREF[2]:     0047516b(j), 00475191(j)
//                              Pnl_drop.cpp:673 (4)
//         004751b3     POP        ESI
//         004751b4     RET        0x4
//         004751b7     ??         90h
//         004751b8     NOP
//         004751b9     NOP
//         004751ba     NOP
//         004751bb     NOP
//         004751bc     NOP
//         004751bd     NOP
//         004751be     NOP
//         004751bf     NOP
    return;
}

char* TDropDownPanel::currentLine() {
    /* TODO: Stub */
//                              char * __thiscall currentLine(TDropDownPanel * this)
//              char *            EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ?currentLine@TDropDownPanel@@QAEPADXZ                        XREF[7]:     set_scenario_mode:004aa42f(c),
//                               TDropDownPanel::currentLine                                               set_scenario_mode:004aa449(c),
//                                                                                                         set_scenario_mode:004aa463(c),
//                                                                                                         set_scenario_mode:004aa47d(c),
//                                                                                                         set_player:004aafbf(c),
//                                                                                                         set_player:004aafdc(c),
//                                                                                                         set_player:004aaff9(c)
//                              Pnl_drop.cpp:679 (10)
//         004751c0     MOV        this,dword ptr [ECX + this->list_panel]
//         004751c6     TEST       this,this
//         004751c8     JZ         LAB_004751cf
//                              Pnl_drop.cpp:681 (5)
//         004751ca     JMP        TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_004751cf                                                 XREF[1]:     004751c8(j)
//                              Pnl_drop.cpp:683 (2)
//         004751cf     XOR        EAX,EAX
//                              Pnl_drop.cpp:684 (1)
//         004751d1     RET
//         004751d2     ??         90h
//         004751d3     NOP
//         004751d4     NOP
//         004751d5     NOP
//         004751d6     NOP
//         004751d7     NOP
//         004751d8     NOP
//         004751d9     NOP
//         004751da     NOP
//         004751db     NOP
//         004751dc     NOP
//         004751dd     NOP
//         004751de     NOP
//         004751df     NOP
    return 0;
}

void TDropDownPanel::set_tab_order(TPanel* param_1, TPanel* param_2) {
    /* TODO: Stub */
//                              void __thiscall set_tab_order(TDropDownPanel * this, TPanel * param_
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004751e8(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     004751e0(R)
//                               ?set_tab_order@TDropDownPanel@@UAEXPAVTPanel@@0@Z            XREF[1]:     005712a4(*)
//                               TDropDownPanel::set_tab_order
//                              Pnl_drop.cpp:690 (20)
//         004751e0     MOV        EAX,dword ptr [ESP + param_2]
//         004751e4     PUSH       ESI
//         004751e5     MOV        ESI,this
//         004751e7     PUSH       EAX
//         004751e8     MOV        this,dword ptr [ESP + param_1]
//         004751ec     PUSH       this
//         004751ed     MOV        this,ESI
//         004751ef     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * pa
//                              Pnl_drop.cpp:692 (10)
//         004751f4     MOV        this,dword ptr [ESI + 0xf4]
//         004751fa     TEST       this,this
//         004751fc     JZ         LAB_0047520a
//                              Pnl_drop.cpp:693 (12)
//         004751fe     MOV        EDX,dword ptr [this->_padding_]
//         00475200     PUSH       0x0
//         00475202     PUSH       0x0
//         00475204     CALL       dword ptr [EDX + 0xc4]
//                               LAB_0047520a                                                 XREF[1]:     004751fc(j)
//                              Pnl_drop.cpp:694 (4)
//         0047520a     POP        ESI
//         0047520b     RET        0x8
//         0047520e     ??         90h
//         0047520f     NOP
    return;
}

void TDropDownPanel::set_sorted(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_sorted(TDropDownPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0047521a(R)
//                               ?set_sorted@TDropDownPanel@@QAEXH@Z                          XREF[3]:     fill_campaign_drop:0048fbd4(c),
//                               TDropDownPanel::set_sorted                                                create_drop_down:004a90f9(c),
//                                                                                                         create_drop_down:004a922a(c)
//                              Pnl_drop.cpp:700 (10)
//         00475210     MOV        EAX,dword ptr [ECX + this->list_panel]
//         00475216     TEST       EAX,EAX
//         00475218     JZ         LAB_00475224
//                              Pnl_drop.cpp:702 (10)
//         0047521a     MOV        this,dword ptr [ESP + param_1]
//         0047521e     MOV        dword ptr [EAX + 0x15c],this
//                               LAB_00475224                                                 XREF[1]:     00475218(j)
//                              Pnl_drop.cpp:703 (3)
//         00475224     RET        0x4
//         00475227     ??         90h
//         00475228     NOP
//         00475229     NOP
//         0047522a     NOP
//         0047522b     NOP
//         0047522c     NOP
//         0047522d     NOP
//         0047522e     NOP
//         0047522f     NOP
    return;
}

int TDropDownPanel::get_sorted() {
    /* TODO: Stub */
//                              int __thiscall get_sorted(TDropDownPanel * this)
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ?get_sorted@TDropDownPanel@@QAEHXZ
//                               TDropDownPanel::get_sorted
//                              Pnl_drop.cpp:706 (10)
//         00475230     MOV        EAX,dword ptr [ECX + this->list_panel]
//         00475236     TEST       EAX,EAX
//         00475238     JZ         LAB_00475241
//                              Pnl_drop.cpp:708 (6)
//         0047523a     MOV        EAX,dword ptr [EAX + 0x15c]
//                              Pnl_drop.cpp:711 (1)
//         00475240     RET
//                               LAB_00475241                                                 XREF[1]:     00475238(j)
//                              Pnl_drop.cpp:710 (2)
//         00475241     XOR        EAX,EAX
//                              Pnl_drop.cpp:711 (1)
//         00475243     RET
//         00475244     ??         90h
//         00475245     NOP
//         00475246     NOP
//         00475247     NOP
//         00475248     NOP
//         00475249     NOP
//         0047524a     NOP
//         0047524b     NOP
//         0047524c     NOP
//         0047524d     NOP
//         0047524e     NOP
//         0047524f     NOP
    return 0;
}

void TDropDownPanel::set_line(long param_1) {
    /* TODO: Stub */
//                              void __thiscall set_line(TDropDownPanel * this, long param_1)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00475254(R)
//                               ?set_line@TDropDownPanel@@QAEXJ@Z                            XREF[34]:    setCurrentLineNumber:00475155(c),
//                               TDropDownPanel::set_line                                                  TRIBE_Screen_Campaign_Selection:00
//                                                                                                         action:004a1d79(c),
//                                                                                                         fillPlayers:004a3dee(c),
//                                                                                                         fillPlayers:004a3e80(c),
//                                                                                                         fillPlayers:004a3eec(c),
//                                                                                                         fillNumberPlayers:004a54ae(c),
//                                                                                                         TRIBE_Screen_Sed:004a867e(c),
//                                                                                                         create_drop_down:004a92fb(c),
//                                                                                                         set_player:004ab02d(c),
//                                                                                                         command_new_map:004ad573(c),
//                                                                                                         SavePlayerActiveStatus:004b2d77(c)
//                                                                                                         SavePlayerActiveStatus:004b2d8b(c)
//                                                                                                         SavePlayerActiveStatus:004b2d9f(c)
//                                                                                                         SavePlayerActiveStatus:004b2db3(c)
//                                                                                                         SavePlayerActiveStatus:004b2dc6(c)
//                                                                                                         fillMissionText:004b61f2(c),
//                                                                                                         getSettings:004b62e1(c),
//                                                                                                         getSettings:004b6304(c),
//                                                                                                         getSettings:004b6327(c), [more]
//                              Pnl_drop.cpp:714 (4)
//         00475250     PUSH       ESI
//         00475251     MOV        ESI,this
//         00475253     PUSH       EDI
//                              Pnl_drop.cpp:715 (4)
//         00475254     MOV        EDI,dword ptr [ESP + param_1]
//                              Pnl_drop.cpp:716 (17)
//         00475258     MOV        this,dword ptr [ESI + 0xfc]
//         0047525e     MOV        word ptr [ESI + 0x108],DI
//         00475265     TEST       this,this
//         00475267     JZ         LAB_00475296
//                              Pnl_drop.cpp:718 (6)
//         00475269     PUSH       EDI
//         0047526a     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
//                              Pnl_drop.cpp:720 (10)
//         0047526f     MOV        EAX,dword ptr [ESI + 0xf4]
//         00475275     TEST       EAX,EAX
//         00475277     JZ         LAB_00475296
//                              Pnl_drop.cpp:721 (29)
//         00475279     MOV        this,dword ptr [ESI + 0xfc]
//         0047527f     PUSH       EBX
//         00475280     MOV        EBX,dword ptr [EAX]
//         00475282     PUSH       EDI
//         00475283     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         00475288     MOV        this,dword ptr [ESI + 0xf4]
//         0047528e     PUSH       EAX
//         0047528f     CALL       dword ptr [EBX + 0xe8]
//         00475295     POP        EBX
//                               LAB_00475296                                                 XREF[2]:     00475267(j), 00475277(j)
//                              Pnl_drop.cpp:723 (5)
//         00475296     POP        EDI
//         00475297     POP        ESI
//         00475298     RET        0x4
//         0047529b     ??         90h
//         0047529c     NOP
//         0047529d     NOP
//         0047529e     NOP
//         0047529f     NOP
    return;
}

int TDropDownPanel::append_line(char* param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall append_line(TDropDownPanel * this, long param_1, long
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004752de(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004752da(R)
//                               ?append_line@TDropDownPanel@@QAEHJJ@Z                        XREF[165]:   TRIBE_Screen_Campaign_Selection:00
//                               TDropDownPanel::append_line                                               TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         create_drop_down:004a8c0f(c),
//                                                                                                         create_drop_down:004a8c1d(c),
//                                                                                                         create_drop_down:004a8c2b(c),
//                                                                                                         create_drop_down:004a8c39(c),
//                                                                                                         create_drop_down:004a8c47(c),
//                                                                                                         create_drop_down:004a8c55(c),
//                                                                                                         create_drop_down:004a8c7a(c),
//                                                                                                         create_drop_down:004a8c88(c),
//                                                                                                         create_drop_down:004a8c96(c),
//                                                                                                         create_all_buttons_etc:004b0e1b(c)
//                                                                                                         create_all_buttons_etc:004b0e2c(c)
//                                                                                                         create_all_buttons_etc:004b0e3d(c)
//                                                                                                         create_all_buttons_etc:004b0e4e(c)
//                                                                                                         create_all_buttons_etc:004b0e5f(c)
//                                                                                                         create_all_buttons_etc:004b0e70(c)
//                                                                                                         [more]
//                              Pnl_drop.cpp:734 (10)
//         004752d0     MOV        this,dword ptr [ECX + this->list_panel]
//         004752d6     TEST       this,this
//         004752d8     JZ         LAB_004752ec
//                              Pnl_drop.cpp:736 (15)
//         004752da     MOV        EAX,dword ptr [ESP + param_2]
//         004752de     MOV        EDX,dword ptr [ESP + param_1]
//         004752e2     PUSH       EAX
//         004752e3     PUSH       EDX
//         004752e4     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
//                              Pnl_drop.cpp:739 (3)
//         004752e9     RET        0x8
//                               LAB_004752ec                                                 XREF[1]:     004752d8(j)
//                              Pnl_drop.cpp:738 (2)
//         004752ec     XOR        EAX,EAX
//                              Pnl_drop.cpp:739 (3)
//         004752ee     RET        0x8
//         004752f1     ??         90h
//         004752f2     NOP
//         004752f3     NOP
//         004752f4     NOP
//         004752f5     NOP
//         004752f6     NOP
//         004752f7     NOP
//         004752f8     NOP
//         004752f9     NOP
//         004752fa     NOP
//         004752fb     NOP
//         004752fc     NOP
//         004752fd     NOP
//         004752fe     NOP
//         004752ff     NOP
    return 0;
}

int TDropDownPanel::append_line(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall append_line(TDropDownPanel * this, long param_1, long
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004752de(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004752da(R)
//                               ?append_line@TDropDownPanel@@QAEHJJ@Z                        XREF[165]:   TRIBE_Screen_Campaign_Selection:00
//                               TDropDownPanel::append_line                                               TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TRIBE_Screen_Campaign_Selection:00
//                                                                                                         create_drop_down:004a8c0f(c),
//                                                                                                         create_drop_down:004a8c1d(c),
//                                                                                                         create_drop_down:004a8c2b(c),
//                                                                                                         create_drop_down:004a8c39(c),
//                                                                                                         create_drop_down:004a8c47(c),
//                                                                                                         create_drop_down:004a8c55(c),
//                                                                                                         create_drop_down:004a8c7a(c),
//                                                                                                         create_drop_down:004a8c88(c),
//                                                                                                         create_drop_down:004a8c96(c),
//                                                                                                         create_all_buttons_etc:004b0e1b(c)
//                                                                                                         create_all_buttons_etc:004b0e2c(c)
//                                                                                                         create_all_buttons_etc:004b0e3d(c)
//                                                                                                         create_all_buttons_etc:004b0e4e(c)
//                                                                                                         create_all_buttons_etc:004b0e5f(c)
//                                                                                                         create_all_buttons_etc:004b0e70(c)
//                                                                                                         [more]
//                              Pnl_drop.cpp:734 (10)
//         004752d0     MOV        this,dword ptr [ECX + this->list_panel]
//         004752d6     TEST       this,this
//         004752d8     JZ         LAB_004752ec
//                              Pnl_drop.cpp:736 (15)
//         004752da     MOV        EAX,dword ptr [ESP + param_2]
//         004752de     MOV        EDX,dword ptr [ESP + param_1]
//         004752e2     PUSH       EAX
//         004752e3     PUSH       EDX
//         004752e4     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, long param
//                              Pnl_drop.cpp:739 (3)
//         004752e9     RET        0x8
//                               LAB_004752ec                                                 XREF[1]:     004752d8(j)
//                              Pnl_drop.cpp:738 (2)
//         004752ec     XOR        EAX,EAX
//                              Pnl_drop.cpp:739 (3)
//         004752ee     RET        0x8
//         004752f1     ??         90h
//         004752f2     NOP
//         004752f3     NOP
//         004752f4     NOP
//         004752f5     NOP
//         004752f6     NOP
//         004752f7     NOP
//         004752f8     NOP
//         004752f9     NOP
//         004752fa     NOP
//         004752fb     NOP
//         004752fc     NOP
//         004752fd     NOP
//         004752fe     NOP
//         004752ff     NOP
    return 0;
}

int TDropDownPanel::insert_line(long param_1, char* param_2, long param_3) {
    /* TODO: Stub */
//                              int __thiscall insert_line(TDropDownPanel * this, long param_1, long
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00475343(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0047533e(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047533a(R)
//                               ?insert_line@TDropDownPanel@@QAEHJJJ@Z
//                               TDropDownPanel::insert_line
//                              Pnl_drop.cpp:750 (10)
//         00475330     MOV        this,dword ptr [ECX + this->list_panel]
//         00475336     TEST       this,this
//         00475338     JZ         LAB_00475351
//                              Pnl_drop.cpp:752 (20)
//         0047533a     MOV        EAX,dword ptr [ESP + param_3]
//         0047533e     MOV        EDX,dword ptr [ESP + param_2]
//         00475342     PUSH       EAX
//         00475343     MOV        EAX,dword ptr [ESP + param_1]
//         00475347     PUSH       EDX
//         00475348     PUSH       EAX
//         00475349     CALL       TTextPanel::insert_line                          int insert_line(TTextPanel * this, long param
//                              Pnl_drop.cpp:755 (3)
//         0047534e     RET        0xc
//                               LAB_00475351                                                 XREF[1]:     00475338(j)
//                              Pnl_drop.cpp:754 (2)
//         00475351     XOR        EAX,EAX
//                              Pnl_drop.cpp:755 (3)
//         00475353     RET        0xc
//         00475356     ??         90h
//         00475357     NOP
//         00475358     NOP
//         00475359     NOP
//         0047535a     NOP
//         0047535b     NOP
//         0047535c     NOP
//         0047535d     NOP
//         0047535e     NOP
//         0047535f     NOP
    return 0;
}

int TDropDownPanel::insert_line(long param_1, long param_2, long param_3) {
    /* TODO: Stub */
//                              int __thiscall insert_line(TDropDownPanel * this, long param_1, long
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00475343(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0047533e(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047533a(R)
//                               ?insert_line@TDropDownPanel@@QAEHJJJ@Z
//                               TDropDownPanel::insert_line
//                              Pnl_drop.cpp:750 (10)
//         00475330     MOV        this,dword ptr [ECX + this->list_panel]
//         00475336     TEST       this,this
//         00475338     JZ         LAB_00475351
//                              Pnl_drop.cpp:752 (20)
//         0047533a     MOV        EAX,dword ptr [ESP + param_3]
//         0047533e     MOV        EDX,dword ptr [ESP + param_2]
//         00475342     PUSH       EAX
//         00475343     MOV        EAX,dword ptr [ESP + param_1]
//         00475347     PUSH       EDX
//         00475348     PUSH       EAX
//         00475349     CALL       TTextPanel::insert_line                          int insert_line(TTextPanel * this, long param
//                              Pnl_drop.cpp:755 (3)
//         0047534e     RET        0xc
//                               LAB_00475351                                                 XREF[1]:     00475338(j)
//                              Pnl_drop.cpp:754 (2)
//         00475351     XOR        EAX,EAX
//                              Pnl_drop.cpp:755 (3)
//         00475353     RET        0xc
//         00475356     ??         90h
//         00475357     NOP
//         00475358     NOP
//         00475359     NOP
//         0047535a     NOP
//         0047535b     NOP
//         0047535c     NOP
//         0047535d     NOP
//         0047535e     NOP
//         0047535f     NOP
    return 0;
}

int TDropDownPanel::delete_line(long param_1) {
    /* TODO: Stub */
//                              int __thiscall delete_line(TDropDownPanel * this, long param_1)
//              int               EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047536a(R)
//                               ?delete_line@TDropDownPanel@@QAEHJ@Z                         XREF[1]:     fillPlayers:004a3db0(c)
//                               TDropDownPanel::delete_line
//                              Pnl_drop.cpp:758 (10)
//         00475360     MOV        this,dword ptr [ECX + this->list_panel]
//         00475366     TEST       this,this
//         00475368     JZ         LAB_00475377
//                              Pnl_drop.cpp:760 (10)
//         0047536a     MOV        EAX,dword ptr [ESP + param_1]
//         0047536e     PUSH       EAX
//         0047536f     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                              Pnl_drop.cpp:763 (3)
//         00475374     RET        0x4
//                               LAB_00475377                                                 XREF[1]:     00475368(j)
//                              Pnl_drop.cpp:762 (2)
//         00475377     XOR        EAX,EAX
//                              Pnl_drop.cpp:763 (3)
//         00475379     RET        0x4
//         0047537c     ??         90h
//         0047537d     NOP
//         0047537e     NOP
//         0047537f     NOP
    return 0;
}

long TDropDownPanel::get_line() {
    /* TODO: Stub */
//                              long __thiscall get_line(TDropDownPanel * this, char * param_1)
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004753ca(R)
//                               ?get_line@TDropDownPanel@@QAEJPAD@Z                          XREF[11]:    set_scenario_mode:004aa36f(c),
//                               TDropDownPanel::get_line                                                  set_scenario_mode:004aa392(c),
//                                                                                                         set_scenario_mode:004aa3b8(c),
//                                                                                                         set_scenario_mode:004aa3de(c),
//                                                                                                         set_scenario_mode:004aa419(c),
//                                                                                                         set_player:004ab17b(c),
//                                                                                                         set_player:004ab1bc(c),
//                                                                                                         set_player:004ab1e5(c),
//                                                                                                         set_player:004ab226(c),
//                                                                                                         set_player:004ab24f(c),
//                                                                                                         set_player:004ab290(c)
//                              Pnl_drop.cpp:782 (10)
//         004753c0     MOV        this,dword ptr [ECX + this->list_panel]
//         004753c6     TEST       this,this
//         004753c8     JZ         LAB_004753d7
//                              Pnl_drop.cpp:784 (10)
//         004753ca     MOV        EAX,dword ptr [ESP + param_1]
//         004753ce     PUSH       EAX
//         004753cf     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//                              Pnl_drop.cpp:787 (3)
//         004753d4     RET        0x4
//                               LAB_004753d7                                                 XREF[1]:     004753c8(j)
//                              Pnl_drop.cpp:786 (2)
//         004753d7     XOR        EAX,EAX
//                              Pnl_drop.cpp:787 (3)
//         004753d9     RET        0x4
//         004753dc     ??         90h
//         004753dd     NOP
//         004753de     NOP
//         004753df     NOP
    return 0;
}

long TDropDownPanel::get_line(long param_1) {
    /* TODO: Stub */
//                              long __thiscall get_line(TDropDownPanel * this, char * param_1)
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004753ca(R)
//                               ?get_line@TDropDownPanel@@QAEJPAD@Z                          XREF[11]:    set_scenario_mode:004aa36f(c),
//                               TDropDownPanel::get_line                                                  set_scenario_mode:004aa392(c),
//                                                                                                         set_scenario_mode:004aa3b8(c),
//                                                                                                         set_scenario_mode:004aa3de(c),
//                                                                                                         set_scenario_mode:004aa419(c),
//                                                                                                         set_player:004ab17b(c),
//                                                                                                         set_player:004ab1bc(c),
//                                                                                                         set_player:004ab1e5(c),
//                                                                                                         set_player:004ab226(c),
//                                                                                                         set_player:004ab24f(c),
//                                                                                                         set_player:004ab290(c)
//                              Pnl_drop.cpp:782 (10)
//         004753c0     MOV        this,dword ptr [ECX + this->list_panel]
//         004753c6     TEST       this,this
//         004753c8     JZ         LAB_004753d7
//                              Pnl_drop.cpp:784 (10)
//         004753ca     MOV        EAX,dword ptr [ESP + param_1]
//         004753ce     PUSH       EAX
//         004753cf     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//                              Pnl_drop.cpp:787 (3)
//         004753d4     RET        0x4
//                               LAB_004753d7                                                 XREF[1]:     004753c8(j)
//                              Pnl_drop.cpp:786 (2)
//         004753d7     XOR        EAX,EAX
//                              Pnl_drop.cpp:787 (3)
//         004753d9     RET        0x4
//         004753dc     ??         90h
//         004753dd     NOP
//         004753de     NOP
//         004753df     NOP
    return 0;
}

long TDropDownPanel::get_line(char* param_1) {
    /* TODO: Stub */
//                              long __thiscall get_line(TDropDownPanel * this, char * param_1)
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004753ca(R)
//                               ?get_line@TDropDownPanel@@QAEJPAD@Z                          XREF[11]:    set_scenario_mode:004aa36f(c),
//                               TDropDownPanel::get_line                                                  set_scenario_mode:004aa392(c),
//                                                                                                         set_scenario_mode:004aa3b8(c),
//                                                                                                         set_scenario_mode:004aa3de(c),
//                                                                                                         set_scenario_mode:004aa419(c),
//                                                                                                         set_player:004ab17b(c),
//                                                                                                         set_player:004ab1bc(c),
//                                                                                                         set_player:004ab1e5(c),
//                                                                                                         set_player:004ab226(c),
//                                                                                                         set_player:004ab24f(c),
//                                                                                                         set_player:004ab290(c)
//                              Pnl_drop.cpp:782 (10)
//         004753c0     MOV        this,dword ptr [ECX + this->list_panel]
//         004753c6     TEST       this,this
//         004753c8     JZ         LAB_004753d7
//                              Pnl_drop.cpp:784 (10)
//         004753ca     MOV        EAX,dword ptr [ESP + param_1]
//         004753ce     PUSH       EAX
//         004753cf     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//                              Pnl_drop.cpp:787 (3)
//         004753d4     RET        0x4
//                               LAB_004753d7                                                 XREF[1]:     004753c8(j)
//                              Pnl_drop.cpp:786 (2)
//         004753d7     XOR        EAX,EAX
//                              Pnl_drop.cpp:787 (3)
//         004753d9     RET        0x4
//         004753dc     ??         90h
//         004753dd     NOP
//         004753de     NOP
//         004753df     NOP
    return 0;
}

char* TDropDownPanel::get_text() {
    /* TODO: Stub */
//                              char * __thiscall get_text(TDropDownPanel * this, long param_1)
//              char *            EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047540a(R)
//                               ?get_text@TDropDownPanel@@QAEPADJ@Z
//                               TDropDownPanel::get_text
//                              Pnl_drop.cpp:798 (10)
//         00475400     MOV        this,dword ptr [ECX + this->list_panel]
//         00475406     TEST       this,this
//         00475408     JZ         LAB_00475417
//                              Pnl_drop.cpp:800 (10)
//         0047540a     MOV        EAX,dword ptr [ESP + param_1]
//         0047540e     PUSH       EAX
//         0047540f     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//                              Pnl_drop.cpp:803 (3)
//         00475414     RET        0x4
//                               LAB_00475417                                                 XREF[1]:     00475408(j)
//                              Pnl_drop.cpp:802 (2)
//         00475417     XOR        EAX,EAX
//                              Pnl_drop.cpp:803 (3)
//         00475419     RET        0x4
//         0047541c     ??         90h
//         0047541d     NOP
//         0047541e     NOP
//         0047541f     NOP
    return 0;
}

char* TDropDownPanel::get_text(long param_1) {
    /* TODO: Stub */
//                              char * __thiscall get_text(TDropDownPanel * this, long param_1)
//              char *            EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047540a(R)
//                               ?get_text@TDropDownPanel@@QAEPADJ@Z
//                               TDropDownPanel::get_text
//                              Pnl_drop.cpp:798 (10)
//         00475400     MOV        this,dword ptr [ECX + this->list_panel]
//         00475406     TEST       this,this
//         00475408     JZ         LAB_00475417
//                              Pnl_drop.cpp:800 (10)
//         0047540a     MOV        EAX,dword ptr [ESP + param_1]
//         0047540e     PUSH       EAX
//         0047540f     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//                              Pnl_drop.cpp:803 (3)
//         00475414     RET        0x4
//                               LAB_00475417                                                 XREF[1]:     00475408(j)
//                              Pnl_drop.cpp:802 (2)
//         00475417     XOR        EAX,EAX
//                              Pnl_drop.cpp:803 (3)
//         00475419     RET        0x4
//         0047541c     ??         90h
//         0047541d     NOP
//         0047541e     NOP
//         0047541f     NOP
    return 0;
}

long TDropDownPanel::get_id() {
    /* TODO: Stub */
//                              long __thiscall get_id(TDropDownPanel * this, long param_1)
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047544a(R)
//                               ?get_id@TDropDownPanel@@QAEJJ@Z                              XREF[2]:     startGame:004a2236(c),
//                               TDropDownPanel::get_id                                                    fillPlayers:004a3d9d(c)
//                              Pnl_drop.cpp:814 (10)
//         00475440     MOV        this,dword ptr [ECX + this->list_panel]
//         00475446     TEST       this,this
//         00475448     JZ         LAB_00475457
//                              Pnl_drop.cpp:816 (10)
//         0047544a     MOV        EAX,dword ptr [ESP + param_1]
//         0047544e     PUSH       EAX
//         0047544f     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this, long param_1)
//                              Pnl_drop.cpp:819 (3)
//         00475454     RET        0x4
//                               LAB_00475457                                                 XREF[1]:     00475448(j)
//                              Pnl_drop.cpp:818 (2)
//         00475457     XOR        EAX,EAX
//                              Pnl_drop.cpp:819 (3)
//         00475459     RET        0x4
//         0047545c     ??         90h
//         0047545d     NOP
//         0047545e     NOP
//         0047545f     NOP
    return 0;
}

long TDropDownPanel::get_id(long param_1) {
    /* TODO: Stub */
//                              long __thiscall get_id(TDropDownPanel * this, long param_1)
//              long              EAX:4          <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047544a(R)
//                               ?get_id@TDropDownPanel@@QAEJJ@Z                              XREF[2]:     startGame:004a2236(c),
//                               TDropDownPanel::get_id                                                    fillPlayers:004a3d9d(c)
//                              Pnl_drop.cpp:814 (10)
//         00475440     MOV        this,dword ptr [ECX + this->list_panel]
//         00475446     TEST       this,this
//         00475448     JZ         LAB_00475457
//                              Pnl_drop.cpp:816 (10)
//         0047544a     MOV        EAX,dword ptr [ESP + param_1]
//         0047544e     PUSH       EAX
//         0047544f     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this, long param_1)
//                              Pnl_drop.cpp:819 (3)
//         00475454     RET        0x4
//                               LAB_00475457                                                 XREF[1]:     00475448(j)
//                              Pnl_drop.cpp:818 (2)
//         00475457     XOR        EAX,EAX
//                              Pnl_drop.cpp:819 (3)
//         00475459     RET        0x4
//         0047545c     ??         90h
//         0047545d     NOP
//         0047545e     NOP
//         0047545f     NOP
    return 0;
}

void TDropDownPanel::empty_list() {
    /* TODO: Stub */
//                              void __thiscall empty_list(TDropDownPanel * this)
//              void              <VOID>         <RETURN>
//              TDropDownPanel    ECX:4 (auto)   this
//                               ?empty_list@TDropDownPanel@@QAEXXZ                           XREF[29]:    fill_campaign_drop:0048fbdf(c),
//                               TDropDownPanel::empty_list                                                TRIBE_Screen_Campaign_Selection:00
//                                                                                                         TribeMPSetupScreen:004a0364(c),
//                                                                                                         TribeMPSetupScreen:004a03fc(c),
//                                                                                                         updateSummary:004a42ef(c),
//                                                                                                         updateSummary:004a4437(c),
//                                                                                                         fillNumberPlayers:004a544d(c),
//                                                                                                         create_drop_down:004a8bf7(c),
//                                                                                                         create_drop_down:004a9231(c),
//                                                                                                         create_all_buttons_etc:004b0cc8(c)
//                                                                                                         create_all_buttons_etc:004b0e0a(c)
//                                                                                                         MakeFileList:004b2abb(c),
//                                                                                                         Set_player_advance_civilization_te
//                                                                                                         SavePlayerActiveStatus:004b2c9b(c)
//                                                                                                         SavePlayerActiveStatus:004b2ca6(c)
//                                                                                                         SavePlayerActiveStatus:004b2cb1(c)
//                                                                                                         SavePlayerActiveStatus:004b2cbc(c)
//                                                                                                         SavePlayerActiveStatus:004b2cc7(c)
//                                                                                                         SavePlayerActiveStatus:004b2cd2(c)
//                                                                                                         TribeGameSettingsScreen:004b49ec(c
//                                                                                                         [more]
//                              Pnl_drop.cpp:822 (10)
//         00475460     MOV        this,dword ptr [ECX + this->list_panel]
//         00475466     TEST       this,this
//         00475468     JZ         LAB_0047546f
//                              Pnl_drop.cpp:824 (5)
//         0047546a     JMP        TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//                               LAB_0047546f                                                 XREF[1]:     00475468(j)
//                              Pnl_drop.cpp:825 (1)
//         0047546f     RET
    return;
}

TDropDownButtonPanel::TDropDownButtonPanel(TDropDownPanel* param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TDropDownButtonPanel(TDropDownButtonPanel * thi
//              undefined         <UNASSIGNED>   <RETURN>
//              TDropDownButto    ECX:4 (auto)   this
//              TDropDownPanel    Stack[0x4]:4   param_1                   XREF[1]:     00475478(R)
//                               ??0TDropDownButtonPanel@@QAE@PAVTDropDownPanel@@@Z           XREF[1]:     setup:00474158(c)
//                               TDropDownButtonPanel::TDropDownButtonPanel
//                              Pnl_drop.cpp:833 (8)
//         00475470     PUSH       ESI
//         00475471     MOV        ESI,this
//         00475473     CALL       TButtonPanel::TButtonPanel                       undefined TButtonPanel(TButtonPanel * this)
//                              Pnl_drop.cpp:834 (16)
//         00475478     MOV        EAX,dword ptr [ESP + param_1]
//         0047547c     MOV        dword ptr [ESI],TDropDownButtonPanel::`vftable'  = 00475490
//         00475482     MOV        dword ptr [ESI + 0x2b8],EAX
//                              Pnl_drop.cpp:835 (6)
//         00475488     MOV        EAX,ESI
//         0047548a     POP        ESI
//         0047548b     RET        0x4
//         0047548e     ??         90h
//         0047548f     NOP
}

long TDropDownButtonPanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall handle_mouse_move(TDropDownButtonPanel * this, long
//              long              EAX:4          <RETURN>
//              TDropDownButto    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004754c2(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004754ca(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     004755a7(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     004755a3(R)
//                               ?handle_mouse_move@TDropDownButtonPanel@@UAEJJJHH@Z          XREF[1]:     00571334(*)
//                               TDropDownButtonPanel::handle_mouse_move
//                              Pnl_drop.cpp:841 (2)
//         004754c0     PUSH       EBX
//         004754c1     PUSH       EBP
//                              Pnl_drop.cpp:844 (23)
//         004754c2     MOV        EBX,dword ptr [ESP + param_1]
//         004754c6     PUSH       ESI
//         004754c7     MOV        ESI,this
//         004754c9     PUSH       EDI
//         004754ca     MOV        EDI,dword ptr [ESP + param_2]
//         004754ce     MOV        EAX,dword ptr [ESI + 0x68]
//         004754d1     TEST       EAX,EAX
//         004754d3     JZ         LAB_004755a3
//                              Pnl_drop.cpp:846 (26)
//         004754d9     MOV        EAX,dword ptr [ESI + 0x2b8]
//         004754df     PUSH       EDI
//         004754e0     PUSH       EBX
//         004754e1     MOV        this,dword ptr [EAX + 0xfc]
//         004754e7     MOV        EDX,dword ptr [this->_padding_]
//         004754e9     CALL       dword ptr [EDX + 0xbc]
//         004754ef     TEST       EAX,EAX
//         004754f1     JZ         LAB_0047552a
//                              Pnl_drop.cpp:848 (21)
//         004754f3     MOV        EBP,dword ptr [ESP + 0x20]
//         004754f7     MOV        this,dword ptr [ESP + 0x1c]
//         004754fb     MOV        EAX,dword ptr [ESI]
//         004754fd     PUSH       EBP
//         004754fe     PUSH       this=>DAT_fffffff8
//         004754ff     PUSH       EDI=>DAT_fffffff4
//         00475500     PUSH       EBX=>DAT_fffffff0
//         00475501     PUSH       0x1
//         00475503     MOV        this,ESI
//         00475505     CALL       dword ptr [EAX + 0x78]
//                              Pnl_drop.cpp:849 (27)
//         00475508     MOV        EDX,dword ptr [ESI + 0x2b8]
//         0047550e     PUSH       EBP
//         0047550f     MOV        this,dword ptr [EDX + 0xfc]
//         00475515     MOV        EDX,dword ptr [ESP + 0x20]
//         00475519     PUSH       EDX=>DAT_fffffff8
//         0047551a     PUSH       EDI=>DAT_fffffff4
//         0047551b     MOV        EAX,dword ptr [this->_padding_]
//         0047551d     PUSH       EBX=>DAT_fffffff0
//         0047551e     PUSH       0x1
//         00475520     CALL       dword ptr [EAX + 0x70]
//                              Pnl_drop.cpp:860 (7)
//         00475523     POP        EDI
//         00475524     POP        ESI
//         00475525     POP        EBP
//         00475526     POP        EBX
//         00475527     RET        0x10
//                               LAB_0047552a                                                 XREF[1]:     004754f1(j)
//                              Pnl_drop.cpp:851 (26)
//         0047552a     MOV        EAX,dword ptr [ESI + 0x2b8]
//         00475530     PUSH       EDI
//         00475531     PUSH       EBX=>DAT_fffffff8
//         00475532     MOV        this,dword ptr [EAX + 0x100]
//         00475538     MOV        EDX,dword ptr [this->_padding_]
//         0047553a     CALL       dword ptr [EDX + 0xbc]
//         00475540     TEST       EAX,EAX
//         00475542     JZ         LAB_004755a3
//                              Pnl_drop.cpp:853 (21)
//         00475544     MOV        EBP,dword ptr [ESP + 0x20]
//         00475548     MOV        this,dword ptr [ESP + 0x1c]
//         0047554c     MOV        EAX,dword ptr [ESI]
//         0047554e     PUSH       EBP
//         0047554f     PUSH       this=>DAT_fffffff8
//         00475550     PUSH       EDI=>DAT_fffffff4
//         00475551     PUSH       EBX=>DAT_fffffff0
//         00475552     PUSH       0x1
//         00475554     MOV        this,ESI
//         00475556     CALL       dword ptr [EAX + 0x78]
//                              Pnl_drop.cpp:854 (36)
//         00475559     MOV        EDX,dword ptr [ESI + 0x2b8]
//         0047555f     MOV        this,dword ptr [EDX + 0xfc]
//         00475565     CALL       TPanel::width                                    long width(TPanel * this)
//         0047556a     MOV        EBX,EAX
//         0047556c     MOV        EAX,dword ptr [ESI + 0x2b8]
//         00475572     MOV        this,dword ptr [EAX + 0xfc]
//         00475578     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//                              Pnl_drop.cpp:855 (31)
//         0047557d     MOV        this,dword ptr [ESI + 0x2b8]
//         00475583     MOV        ESI,dword ptr [ESP + 0x1c]
//         00475587     PUSH       EBP
//         00475588     LEA        EAX,[EBX + EAX*0x1 + -0x1]
//         0047558c     MOV        this,dword ptr [ECX + this->_padding_]
//         00475592     PUSH       ESI=>DAT_fffffff8
//         00475593     PUSH       EDI=>DAT_fffffff4
//         00475594     PUSH       EAX=>DAT_fffffff0
//         00475595     MOV        EDX,dword ptr [this->_padding_]
//         00475597     PUSH       0x1
//         00475599     CALL       dword ptr [EDX + 0x70]
//                              Pnl_drop.cpp:860 (7)
//         0047559c     POP        EDI
//         0047559d     POP        ESI
//         0047559e     POP        EBP
//         0047559f     POP        EBX
//         004755a0     RET        0x10
//                               LAB_004755a3                                                 XREF[2]:     004754d3(j), 00475542(j)
//                              Pnl_drop.cpp:859 (19)
//         004755a3     MOV        EAX,dword ptr [ESP + param_4]
//         004755a7     MOV        this,dword ptr [ESP + param_3]
//         004755ab     PUSH       EAX
//         004755ac     PUSH       this=>DAT_fffffff8
//         004755ad     PUSH       EDI=>DAT_fffffff4
//         004755ae     PUSH       EBX=>DAT_fffffff0
//         004755af     MOV        this,ESI
//         004755b1     CALL       TPanel::handle_mouse_move                        long handle_mouse_move(TPanel * this, long pa
//                              Pnl_drop.cpp:860 (7)
//         004755b6     POP        EDI
//         004755b7     POP        ESI
//         004755b8     POP        EBP
//         004755b9     POP        EBX
//         004755ba     RET        0x10
//         004755bd     ??         90h
//         004755be     NOP
//         004755bf     NOP
    return 0;
}

TDropDownButtonPanel::~TDropDownButtonPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TDropDownButtonPanel(TDropDownButtonPanel * this)
//              void              <VOID>         <RETURN>
//              TDropDownButto    ECX:4 (auto)   this
//                               ??1TDropDownButtonPanel@@UAE@XZ                              XREF[1]:     `vector_deleting_destructor':00475
//                               TDropDownButtonPanel::~TDropDownButtonPanel
//         004754b0     JMP        TButtonPanel::~TButtonPanel
//         004754b5     ??         90h
//         004754b6     NOP
//         004754b7     NOP
//         004754b8     NOP
//         004754b9     NOP
//         004754ba     NOP
//         004754bb     NOP
//         004754bc     NOP
//         004754bd     NOP
//         004754be     NOP
//         004754bf     NOP
}

