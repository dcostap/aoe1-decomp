#include "../common.h"
#include "pnl_sld.h"

TVerticalSliderPanel::TVerticalSliderPanel() {
    /* TODO: Stub */
//                              undefined __thiscall TVerticalSliderPanel(TVerticalSliderPanel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TVerticalSlide    ECX:4 (auto)   this
//                               ??0TVerticalSliderPanel@@QAE@XZ                              XREF[2]:     create_vert_slider:00469b51(c),
//                               TVerticalSliderPanel::TVerticalSliderPanel                                THorizontalSliderPanel:0047bdf3(c)
//                              pnl_sld.cpp:24 (34)
//         0047bce0     PUSH       ESI
//         0047bce1     MOV        ESI,this
//         0047bce3     CALL       TScrollBarPanel::TScrollBarPanel                 undefined TScrollBarPanel(TScrollBarPanel * t
//         0047bce8     MOV        dword ptr [ESI + 0x1c4],0x1
//         0047bcf2     MOV        dword ptr [ESI + 0x1c8],0x0
//         0047bcfc     MOV        dword ptr [ESI],TVerticalSliderPanel::`vftable'  = 0047bd10
//                              pnl_sld.cpp:25 (4)
//         0047bd02     MOV        EAX,ESI
//         0047bd04     POP        ESI
//         0047bd05     RET
//         0047bd06     ??         90h
//         0047bd07     NOP
//         0047bd08     NOP
//         0047bd09     NOP
//         0047bd0a     NOP
//         0047bd0b     NOP
//         0047bd0c     NOP
//         0047bd0d     NOP
//         0047bd0e     NOP
//         0047bd0f     NOP
}

TVerticalSliderPanel::~TVerticalSliderPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TVerticalSliderPanel(TVerticalSliderPanel * this)
//              void              <VOID>         <RETURN>
//              TVerticalSlide    ECX:4 (auto)   this
//                               ??1TVerticalSliderPanel@@UAE@XZ                              XREF[2]:     `scalar_deleting_destructor':0047b
//                               TVerticalSliderPanel::~TVerticalSliderPanel                               ~THorizontalSliderPanel:0047be36(c
//                              pnl_sld.cpp:30 (11)
//         0047bd30     MOV        dword ptr [this->_padding_],TVerticalSliderPan   = 0047bd10
//         0047bd36     JMP        TScrollBarPanel::~TScrollBarPanel                void ~TScrollBarPanel(TScrollBarPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0047bd3b     ??         90h
//         0047bd3c     NOP
//         0047bd3d     NOP
//         0047bd3e     NOP
//         0047bd3f     NOP
}

long TVerticalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14) {
    /* TODO: Stub */
//                              long __thiscall setup(TVerticalSliderPanel * this, TDrawArea * param
//              long              EAX:4          <RETURN>
//              TVerticalSlide    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047bd8c(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0047bd87(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047bd82(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0047bd7d(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0047bd74(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0047bd6d(R)
//              char *            Stack[0x1c]:4  param_7                   XREF[1]:     0047bd5c(R)
//              char *            Stack[0x20]:4  param_8                   XREF[1]:     0047bd66(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     0047bd57(R)
//              long              Stack[0x28]:4  param_10                  XREF[1]:     0047bd44(R)
//              long              Stack[0x2c]:4  param_11                  XREF[1]:     0047bda2(R)
//              long              Stack[0x30]:4  param_12                  XREF[1]:     0047bda6(R)
//              int               Stack[0x34]:4  param_13                  XREF[1]:     0047bd40(R)
//              int               Stack[0x38]:4  param_14                  XREF[1]:     0047bd4b(R)
//                               ?setup@TVerticalSliderPanel@@QAEJPAVTDrawArea@@PAVTPanel@@J  XREF[1]:     create_vert_slider:00469baf(c)
//                               TVerticalSliderPanel::setup
//                              pnl_sld.cpp:39 (4)
//         0047bd40     MOV        EAX,dword ptr [ESP + param_13]
//                              pnl_sld.cpp:48 (90)
//         0047bd44     MOV        EDX,dword ptr [ESP + param_10]
//         0047bd48     PUSH       ESI
//         0047bd49     MOV        ESI,this
//         0047bd4b     MOV        this,dword ptr [ESP + param_14]
//         0047bd4f     PUSH       0x0
//         0047bd51     MOV        dword ptr [ESI + 0x1c4],EAX
//         0047bd57     MOV        EAX,dword ptr [ESP + param_9]
//         0047bd5b     PUSH       EDX
//         0047bd5c     MOV        EDX,dword ptr [ESP + param_7]
//         0047bd60     MOV        dword ptr [ESI + 0x1c8],this
//         0047bd66     MOV        this,dword ptr [ESP + param_8]
//         0047bd6a     PUSH       0x0
//         0047bd6c     PUSH       EAX
//         0047bd6d     MOV        EAX,dword ptr [ESP + param_6]
//         0047bd71     PUSH       0x0
//         0047bd73     PUSH       this
//         0047bd74     MOV        this,dword ptr [ESP + param_5]
//         0047bd78     PUSH       0x0
//         0047bd7a     PUSH       0x0
//         0047bd7c     PUSH       EDX
//         0047bd7d     MOV        EDX,dword ptr [ESP + param_4]
//         0047bd81     PUSH       EAX
//         0047bd82     MOV        EAX,dword ptr [ESP + param_3]
//         0047bd86     PUSH       this
//         0047bd87     MOV        this,dword ptr [ESP + param_2]
//         0047bd8b     PUSH       EDX
//         0047bd8c     MOV        EDX,dword ptr [ESP + param_1]
//         0047bd90     PUSH       EAX
//         0047bd91     PUSH       this
//         0047bd92     PUSH       EDX
//         0047bd93     MOV        this,ESI
//         0047bd95     CALL       TScrollBarPanel::setup                           long setup(TScrollBarPanel * this, TDrawArea
//         0047bd9a     TEST       EAX,EAX
//         0047bd9c     JNZ        LAB_0047bda2
//                              pnl_sld.cpp:54 (4)
//         0047bd9e     POP        ESI
//         0047bd9f     RET        0x38
//                               LAB_0047bda2                                                 XREF[1]:     0047bd9c(j)
//                              pnl_sld.cpp:51 (20)
//         0047bda2     MOV        EAX,dword ptr [ESP + param_11]
//         0047bda6     MOV        this,dword ptr [ESP + param_12]
//         0047bdaa     MOV        dword ptr [ESI + 0xfc],EAX
//         0047bdb0     MOV        dword ptr [ESI + 0x100],this
//                              pnl_sld.cpp:53 (5)
//         0047bdb6     MOV        EAX,0x1
//                              pnl_sld.cpp:54 (4)
//         0047bdbb     POP        ESI
//         0047bdbc     RET        0x38
//         0047bdbf     ??         90h
    return 0;
}

void TVerticalSliderPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(TVerticalSliderPanel * this, long param_1,
//              void              <VOID>         <RETURN>
//              TVerticalSlide    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047bdce(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0047bdc9(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047bdc4(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0047bdc0(R)
//                               ?set_rect@TVerticalSliderPanel@@UAEXJJJJ@Z                   XREF[1]:     00571a44(*)
//                               TVerticalSliderPanel::set_rect
//                              pnl_sld.cpp:60 (25)
//         0047bdc0     MOV        EAX,dword ptr [ESP + param_4]
//         0047bdc4     MOV        EDX,dword ptr [ESP + param_3]
//         0047bdc8     PUSH       EAX
//         0047bdc9     MOV        EAX,dword ptr [ESP + param_2]
//         0047bdcd     PUSH       EDX
//         0047bdce     MOV        EDX,dword ptr [ESP + param_1]
//         0047bdd2     PUSH       EAX
//         0047bdd3     PUSH       EDX
//         0047bdd4     CALL       TScrollBarPanel::set_rect                        void set_rect(TScrollBarPanel * this, long pa
//                              pnl_sld.cpp:75 (3)
//         0047bdd9     RET        0x10
    return;
}

void TVerticalSliderPanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TVerticalSliderPanel * this)
//              void              <VOID>         <RETURN>
//              TVerticalSlide    ECX:4 (auto)   this
//                               ?draw@TVerticalSliderPanel@@UAEXXZ                           XREF[1]:     00571a68(*)
//                               TVerticalSliderPanel::draw
//                              pnl_sld.cpp:80 (5)
//         0047bde0     JMP        TScrollBarPanel::draw
//         0047bde5     ??         90h
//         0047bde6     NOP
//         0047bde7     NOP
//         0047bde8     NOP
//         0047bde9     NOP
//         0047bdea     NOP
//         0047bdeb     NOP
//         0047bdec     NOP
//         0047bded     NOP
//         0047bdee     NOP
//         0047bdef     NOP
    return;
}

THorizontalSliderPanel::THorizontalSliderPanel() {
    /* TODO: Stub */
//                              undefined __thiscall THorizontalSliderPanel(THorizontalSliderPanel *
//              undefined         <UNASSIGNED>   <RETURN>
//              THorizontalSli    ECX:4 (auto)   this
//                               ??0THorizontalSliderPanel@@QAE@XZ                            XREF[1]:     create_horz_slider:00469cc1(c)
//                               THorizontalSliderPanel::THorizontalSliderPanel
//                              pnl_sld.cpp:126 (14)
//         0047bdf0     PUSH       ESI
//         0047bdf1     MOV        ESI,this
//         0047bdf3     CALL       TVerticalSliderPanel::TVerticalSliderPanel       undefined TVerticalSliderPanel(TVerticalSlide
//         0047bdf8     MOV        dword ptr [ESI],THorizontalSliderPanel::`vftab   = 0047be10
//                              pnl_sld.cpp:127 (4)
//         0047bdfe     MOV        EAX,ESI
//         0047be00     POP        ESI
//         0047be01     RET
//         0047be02     ??         90h
//         0047be03     NOP
//         0047be04     NOP
//         0047be05     NOP
//         0047be06     NOP
//         0047be07     NOP
//         0047be08     NOP
//         0047be09     NOP
//         0047be0a     NOP
//         0047be0b     NOP
//         0047be0c     NOP
//         0047be0d     NOP
//         0047be0e     NOP
//         0047be0f     NOP
}

THorizontalSliderPanel::~THorizontalSliderPanel() {
    /* TODO: Stub */
//                              void __thiscall ~THorizontalSliderPanel(THorizontalSliderPanel * this)
//              void              <VOID>         <RETURN>
//              THorizontalSli    ECX:4 (auto)   this
//                               ??1THorizontalSliderPanel@@UAE@XZ                            XREF[1]:     `scalar_deleting_destructor':0047b
//                               THorizontalSliderPanel::~THorizontalSliderPanel
//                              pnl_sld.cpp:132 (11)
//         0047be30     MOV        dword ptr [this->field0_0x0],THorizontalSlider   = 0047be10
//         0047be36     JMP        TVerticalSliderPanel::~TVerticalSliderPanel      void ~TVerticalSliderPanel(TVerticalSliderPan
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0047be3b     ??         90h
//         0047be3c     NOP
//         0047be3d     NOP
//         0047be3e     NOP
//         0047be3f     NOP
}

long THorizontalSliderPanel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, char* param_7, char* param_8, long param_9, long param_10, long param_11, long param_12, int param_13, int param_14) {
    /* TODO: Stub */
//                              long __thiscall setup(THorizontalSliderPanel * this, TDrawArea * par
//              long              EAX:4          <RETURN>
//              THorizontalSli    ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047be8c(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0047be87(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047be82(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0047be7d(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     0047be74(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0047be6d(R)
//              char *            Stack[0x1c]:4  param_7                   XREF[1]:     0047be5c(R)
//              char *            Stack[0x20]:4  param_8                   XREF[1]:     0047be66(R)
//              long              Stack[0x24]:4  param_9                   XREF[1]:     0047be57(R)
//              long              Stack[0x28]:4  param_10                  XREF[1]:     0047be44(R)
//              long              Stack[0x2c]:4  param_11                  XREF[1]:     0047bea2(R)
//              long              Stack[0x30]:4  param_12                  XREF[1]:     0047bea6(R)
//              int               Stack[0x34]:4  param_13                  XREF[1]:     0047be40(R)
//              int               Stack[0x38]:4  param_14                  XREF[1]:     0047be4b(R)
//                               ?setup@THorizontalSliderPanel@@QAEJPAVTDrawArea@@PAVTPanel@  XREF[1]:     create_horz_slider:00469d1f(c)
//                               THorizontalSliderPanel::setup
//                              pnl_sld.cpp:141 (4)
//         0047be40     MOV        EAX,dword ptr [ESP + param_13]
//                              pnl_sld.cpp:150 (90)
//         0047be44     MOV        EDX,dword ptr [ESP + param_10]
//         0047be48     PUSH       ESI
//         0047be49     MOV        ESI,this
//         0047be4b     MOV        this,dword ptr [ESP + param_14]
//         0047be4f     PUSH       0x1
//         0047be51     MOV        dword ptr [ESI + 0x1c4],EAX
//         0047be57     MOV        EAX,dword ptr [ESP + param_9]
//         0047be5b     PUSH       EDX
//         0047be5c     MOV        EDX,dword ptr [ESP + param_7]
//         0047be60     MOV        dword ptr [ESI + 0x1c8],this
//         0047be66     MOV        this,dword ptr [ESP + param_8]
//         0047be6a     PUSH       0x0
//         0047be6c     PUSH       EAX
//         0047be6d     MOV        EAX,dword ptr [ESP + param_6]
//         0047be71     PUSH       0x0
//         0047be73     PUSH       this
//         0047be74     MOV        this,dword ptr [ESP + param_5]
//         0047be78     PUSH       0x0
//         0047be7a     PUSH       0x0
//         0047be7c     PUSH       EDX
//         0047be7d     MOV        EDX,dword ptr [ESP + param_4]
//         0047be81     PUSH       EAX
//         0047be82     MOV        EAX,dword ptr [ESP + param_3]
//         0047be86     PUSH       this
//         0047be87     MOV        this,dword ptr [ESP + param_2]
//         0047be8b     PUSH       EDX
//         0047be8c     MOV        EDX,dword ptr [ESP + param_1]
//         0047be90     PUSH       EAX
//         0047be91     PUSH       this
//         0047be92     PUSH       EDX
//         0047be93     MOV        this,ESI
//         0047be95     CALL       TScrollBarPanel::setup                           long setup(TScrollBarPanel * this, TDrawArea
//         0047be9a     TEST       EAX,EAX
//         0047be9c     JNZ        LAB_0047bea2
//                              pnl_sld.cpp:156 (4)
//         0047be9e     POP        ESI
//         0047be9f     RET        0x38
//                               LAB_0047bea2                                                 XREF[1]:     0047be9c(j)
//                              pnl_sld.cpp:153 (20)
//         0047bea2     MOV        EAX,dword ptr [ESP + param_11]
//         0047bea6     MOV        this,dword ptr [ESP + param_12]
//         0047beaa     MOV        dword ptr [ESI + 0xfc],EAX
//         0047beb0     MOV        dword ptr [ESI + 0x100],this
//                              pnl_sld.cpp:155 (5)
//         0047beb6     MOV        EAX,0x1
//                              pnl_sld.cpp:156 (4)
//         0047bebb     POP        ESI
//         0047bebc     RET        0x38
//         0047bebf     ??         90h
    return 0;
}

void THorizontalSliderPanel::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(THorizontalSliderPanel * this, long param_1
//              void              <VOID>         <RETURN>
//              THorizontalSli    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047bed0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0047bec4(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0047becb(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0047bec0(R)
//                               ?set_rect@THorizontalSliderPanel@@UAEXJJJJ@Z                 XREF[1]:     00571b24(*)
//                               THorizontalSliderPanel::set_rect
//                              pnl_sld.cpp:162 (30)
//         0047bec0     MOV        EAX,dword ptr [ESP + param_4]
//         0047bec4     MOV        EDX,dword ptr [ESP + param_2]
//         0047bec8     PUSH       ESI
//         0047bec9     MOV        ESI,this
//         0047becb     MOV        this,dword ptr [ESP + param_3]
//         0047becf     PUSH       EAX
//         0047bed0     MOV        EAX,dword ptr [ESP + param_1]
//         0047bed4     PUSH       this
//         0047bed5     PUSH       EDX
//         0047bed6     PUSH       EAX
//         0047bed7     MOV        this,ESI
//         0047bed9     CALL       TScrollBarPanel::set_rect                        void set_rect(TScrollBarPanel * this, long pa
//                              pnl_sld.cpp:165 (3)
//         0047bede     MOV        this,dword ptr [ESI + 0xc]
//                              pnl_sld.cpp:168 (19)
//         0047bee1     MOV        EDX,dword ptr [ESI + 0x14]
//         0047bee4     MOV        dword ptr [ESI + 0x164],this
//         0047beea     MOV        dword ptr [ESI + 0x16c],this
//         0047bef0     LEA        EAX,[EDX + this->field0_0x0*0x1 + -0x1]
//                              pnl_sld.cpp:172 (27)
//         0047bef4     MOV        EDX,dword ptr [ESI + 0x18]
//         0047bef7     MOV        dword ptr [ESI + 0x174],EAX
//         0047befd     MOV        dword ptr [ESI + 0x17c],EAX
//         0047bf03     INC        this
//         0047bf04     SUB        EAX,EDX
//         0047bf06     MOV        dword ptr [ESI + 0x138],this
//         0047bf0c     ADD        EAX,0x2
//                              pnl_sld.cpp:173 (6)
//         0047bf0f     MOV        dword ptr [ESI + 0x134],this
//                              pnl_sld.cpp:175 (13)
//         0047bf15     MOV        this,ESI
//         0047bf17     MOV        dword ptr [ESI + 0x13c],EAX
//         0047bf1d     CALL       TScrollBarPanel::calc_item_rects                 void calc_item_rects(TScrollBarPanel * this)
//                              pnl_sld.cpp:176 (4)
//         0047bf22     POP        ESI
//         0047bf23     RET        0x10
//         0047bf26     ??         90h
//         0047bf27     NOP
//         0047bf28     NOP
//         0047bf29     NOP
//         0047bf2a     NOP
//         0047bf2b     NOP
//         0047bf2c     NOP
//         0047bf2d     NOP
//         0047bf2e     NOP
//         0047bf2f     NOP
    return;
}

void THorizontalSliderPanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(THorizontalSliderPanel * this)
//              void              <VOID>         <RETURN>
//              THorizontalSli    ECX:4 (auto)   this
//                               ?draw@THorizontalSliderPanel@@UAEXXZ                         XREF[1]:     00571b48(*)
//                               THorizontalSliderPanel::draw
//                              pnl_sld.cpp:181 (5)
//         0047bf30     JMP        TScrollBarPanel::draw
//         0047bf35     ??         90h
//         0047bf36     NOP
//         0047bf37     NOP
//         0047bf38     NOP
//         0047bf39     NOP
//         0047bf3a     NOP
//         0047bf3b     NOP
//         0047bf3c     NOP
//         0047bf3d     NOP
//         0047bf3e     NOP
//         0047bf3f     NOP
    return;
}

