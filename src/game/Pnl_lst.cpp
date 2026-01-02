#include "../common.h"
#include "Pnl_lst.h"

TListPanel::TListPanel() {
    /* TODO: Stub */
//                              undefined __thiscall TListPanel(TListPanel * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//                               ??0TListPanel@@QAE@XZ                                        XREF[2]:     create_list:004697c0(c),
//                               TListPanel::TListPanel                                                    setup:004741c1(c)
//                              Pnl_lst.cpp:26 (8)
//         004782a0     PUSH       ESI
//         004782a1     MOV        ESI,this
//         004782a3     CALL       TTextPanel::TTextPanel                           undefined TTextPanel(TTextPanel * this)
//                              Pnl_lst.cpp:31 (13)
//         004782a8     XOR        EAX,EAX
//         004782aa     MOV        this,0x1
//         004782af     MOV        dword ptr [ESI + 0xc0],EAX
//                              Pnl_lst.cpp:32 (6)
//         004782b5     MOV        dword ptr [ESI + 0x18c],EAX
//                              Pnl_lst.cpp:34 (6)
//         004782bb     MOV        dword ptr [ESI + 0x194],EAX
//                              Pnl_lst.cpp:35 (6)
//         004782c1     MOV        dword ptr [ESI + 0x198],EAX
//                              Pnl_lst.cpp:36 (41)
//         004782c7     MOV        dword ptr [ESI + 0x188],EAX
//         004782cd     MOV        dword ptr [ESI + 0x19c],this
//         004782d3     MOV        dword ptr [ESI],TListPanel::`vftable'            = 00478310
//         004782d9     MOV        byte ptr [ESI + 0xee],0x4
//         004782e0     MOV        dword ptr [ESI + 0x170],this
//         004782e6     MOV        dword ptr [ESI + 0x190],0x32
//                              Pnl_lst.cpp:37 (6)
//         004782f0     MOV        dword ptr [ESI + 0x80],this
//                              Pnl_lst.cpp:39 (6)
//         004782f6     MOV        dword ptr [ESI + 0x184],this
//                              Pnl_lst.cpp:40 (6)
//         004782fc     MOV        dword ptr [ESI + 0x180],this
//                              Pnl_lst.cpp:41 (4)
//         00478302     MOV        EAX,ESI
//         00478304     POP        ESI
//         00478305     RET
//         00478306     ??         90h
//         00478307     NOP
//         00478308     NOP
//         00478309     NOP
//         0047830a     NOP
//         0047830b     NOP
//         0047830c     NOP
//         0047830d     NOP
//         0047830e     NOP
//         0047830f     NOP
}

TListPanel::~TListPanel() {
    /* TODO: Stub */
//                              void __thiscall ~TListPanel(TListPanel * this)
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//                               ??1TListPanel@@UAE@XZ                                        XREF[1]:     `vector_deleting_destructor':00478
//                               TListPanel::~TListPanel
//                              Pnl_lst.cpp:47 (11)
//         00478330     MOV        dword ptr [this->_padding_],TListPanel::`vftab   = 00478310
//         00478336     JMP        TTextPanel::~TTextPanel                          void ~TTextPanel(TTextPanel * this)
//                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
//         0047833b     ??         90h
//         0047833c     NOP
//         0047833d     NOP
//         0047833e     NOP
//         0047833f     NOP
}

void TListPanel::set_auto_track(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_auto_track(TListPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00478340(R)
//                               ?set_auto_track@TListPanel@@QAEXH@Z                          XREF[1]:     setup:00474237(c)
//                               TListPanel::set_auto_track
//                              Pnl_lst.cpp:55 (10)
//         00478340     MOV        EAX,dword ptr [ESP + param_1]
//         00478344     MOV        dword ptr [ECX + this->auto_track],EAX
//                              Pnl_lst.cpp:57 (3)
//         0047834a     RET        0x4
//         0047834d     ??         90h
//         0047834e     NOP
//         0047834f     NOP
    return;
}

void TListPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              void __thiscall set_bevel_info(TListPanel * this, int param_1, int p
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00478353(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     004783a0(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0047839b(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00478396(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00478391(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0047838c(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     00478388(R)
//                               ?set_bevel_info@TListPanel@@UAEXHHHHHHH@Z                    XREF[1]:     00571664(*)
//                               TListPanel::set_bevel_info
//                              Pnl_lst.cpp:63 (3)
//         00478350     PUSH       ESI
//         00478351     MOV        ESI,this
//                              Pnl_lst.cpp:64 (19)
//         00478353     MOV        this,dword ptr [ESP + param_1]
//         00478357     LEA        EAX,[this->_padding_ + -0x1]
//         0047835a     CMP        EAX,0x6
//         0047835d     JA         switchD_0047835f::caseD_1
//                               switchD_0047835f::switchD
//         0047835f     JMP        dword ptr [EAX*0x4 + switchD_0047835f::switchd   = 0047837e
//                               switchD_0047835f::caseD_6                                    XREF[3]:     0047835f(j), 004783d8(*),
//                               switchD_0047835f::caseD_3                                                 004783e4(*)
//                              Pnl_lst.cpp:74 (10)
//         00478366     MOV        dword ptr [ESI + 0x184],0x2
//                              Pnl_lst.cpp:75 (2)
//         00478370     JMP        LAB_00478388
//                               switchD_0047835f::caseD_7                                    XREF[3]:     0047835f(j), 004783dc(*),
//                               switchD_0047835f::caseD_4                                                 004783e8(*)
//                              Pnl_lst.cpp:79 (10)
//         00478372     MOV        dword ptr [ESI + 0x184],0x3
//                              Pnl_lst.cpp:80 (2)
//         0047837c     JMP        LAB_00478388
//                               switchD_0047835f::caseD_2                                    XREF[5]:     0047835d(j), 0047835f(j),
//                               switchD_0047835f::caseD_5                                                 004783d0(*), 004783d4(*),
//                               switchD_0047835f::caseD_1                                                 004783e0(*)
//                              Pnl_lst.cpp:83 (10)
//         0047837e     MOV        dword ptr [ESI + 0x184],0x1
//                               LAB_00478388                                                 XREF[2]:     00478370(j), 0047837c(j)
//                              Pnl_lst.cpp:87 (38)
//         00478388     MOV        EAX,dword ptr [ESP + param_7]
//         0047838c     MOV        EDX,dword ptr [ESP + param_6]
//         00478390     PUSH       EAX
//         00478391     MOV        EAX,dword ptr [ESP + param_5]
//         00478395     PUSH       EDX
//         00478396     MOV        EDX,dword ptr [ESP + param_4]
//         0047839a     PUSH       EAX
//         0047839b     MOV        EAX,dword ptr [ESP + param_3]
//         0047839f     PUSH       EDX
//         004783a0     MOV        EDX,dword ptr [ESP + param_2]
//         004783a4     PUSH       EAX
//         004783a5     PUSH       EDX
//         004783a6     PUSH       this
//         004783a7     MOV        this,ESI
//         004783a9     CALL       TTextPanel::set_bevel_info                       void set_bevel_info(TTextPanel * this, int pa
//                              Pnl_lst.cpp:89 (10)
//         004783ae     MOV        EAX,dword ptr [ESI + 0x180]
//         004783b4     TEST       EAX,EAX
//         004783b6     JNZ        LAB_004783cb
//                              Pnl_lst.cpp:92 (19)
//         004783b8     PUSH       0x1
//         004783ba     MOV        this,ESI
//         004783bc     MOV        dword ptr [ESI + 0x180],0x1
//         004783c6     CALL       TTextPanel::calc_draw_info                       void calc_draw_info(TTextPanel * this, int pa
//                               LAB_004783cb                                                 XREF[1]:     004783b6(j)
//                              Pnl_lst.cpp:94 (33)
//         004783cb     POP        ESI
//         004783cc     RET        0x1c
//         004783cf     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0047835f::switchdataD_004783d0                       XREF[1]:     set_bevel_info:0047835f(*)
//         004783d0     addr       switchD_0047835f::caseD_1
//         004783d4     addr       switchD_0047835f::caseD_1
//         004783d8     addr       switchD_0047835f::caseD_3
//         004783dc     addr       switchD_0047835f::caseD_4
//         004783e0     addr       switchD_0047835f::caseD_1
//         004783e4     addr       switchD_0047835f::caseD_3
//         004783e8     addr       switchD_0047835f::caseD_4
//         004783ec     ??         90h
//         004783ed     ??         90h
//         004783ee     ??         90h
//         004783ef     ??         90h
    return;
}

long TListPanel::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TListPanel * this)
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//                               ?handle_idle@TListPanel@@UAEJXZ                              XREF[1]:     005715c4(*)
//                               TListPanel::handle_idle
//                              Pnl_lst.cpp:100 (3)
//         004783f0     PUSH       ESI
//         004783f1     MOV        ESI,this
//                              Pnl_lst.cpp:103 (5)
//         004783f3     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              Pnl_lst.cpp:105 (18)
//         004783f8     MOV        EAX,dword ptr [ESI + 0x194]
//         004783fe     TEST       EAX,EAX
//         00478400     JNZ        LAB_00478410
//         00478402     MOV        EAX,dword ptr [ESI + 0x198]
//         00478408     TEST       EAX,EAX
//                              Pnl_lst.cpp:106 (6)
//         0047840a     JZ         LAB_00478499
//                               LAB_00478410                                                 XREF[1]:     00478400(j)
//                              Pnl_lst.cpp:108 (12)
//         00478410     PUSH       0x6c
//         00478412     PUSH       s_C:\msdev\work\age1_x1\Pnl_lst.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp"
//         00478417     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              Pnl_lst.cpp:109 (21)
//         0047841c     MOV        EDX,dword ptr [ESI + 0x18c]
//         00478422     MOV        this,EAX
//         00478424     SUB        this,EDX
//         00478426     MOV        EDX,dword ptr [ESI + 0x190]
//         0047842c     ADD        ESP,0x8
//         0047842f     CMP        this,EDX
//                              Pnl_lst.cpp:110 (2)
//         00478431     JC         LAB_00478499
//                              Pnl_lst.cpp:112 (6)
//         00478433     MOV        dword ptr [ESI + 0x18c],EAX
//                              Pnl_lst.cpp:114 (10)
//         00478439     MOV        EAX,dword ptr [ESI + 0x194]
//         0047843f     TEST       EAX,EAX
//         00478441     JZ         LAB_00478470
//                              Pnl_lst.cpp:116 (16)
//         00478443     MOV        AX,word ptr [ESI + 0xfc]
//         0047844a     CMP        word ptr [ESI + 0x100],AX
//         00478451     JZ         LAB_0047845f
//                              Pnl_lst.cpp:117 (12)
//         00478453     PUSH       0x1
//         00478455     PUSH       EAX
//         00478456     PUSH       0x1
//         00478458     MOV        this,ESI
//         0047845a     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_0047845f                                                 XREF[1]:     00478451(j)
//                              Pnl_lst.cpp:118 (6)
//         0047845f     PUSH       0x1
//         00478461     PUSH       0x0
//         00478463     PUSH       0x3
//                              Pnl_lst.cpp:124 (7)
//         00478465     MOV        this,ESI
//         00478467     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:127 (2)
//         0047846c     XOR        EAX,EAX
//                              Pnl_lst.cpp:128 (2)
//         0047846e     POP        ESI
//         0047846f     RET
//                               LAB_00478470                                                 XREF[1]:     00478441(j)
//                              Pnl_lst.cpp:122 (16)
//         00478470     MOV        AX,word ptr [ESI + 0xfe]
//         00478477     CMP        word ptr [ESI + 0x100],AX
//         0047847e     JZ         LAB_0047848c
//                              Pnl_lst.cpp:123 (12)
//         00478480     PUSH       0x1
//         00478482     PUSH       EAX
//         00478483     PUSH       0x1
//         00478485     MOV        this,ESI
//         00478487     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_0047848c                                                 XREF[1]:     0047847e(j)
//                              Pnl_lst.cpp:124 (13)
//         0047848c     PUSH       0x1
//         0047848e     PUSH       0x0
//         00478490     PUSH       0x2
//         00478492     MOV        this,ESI
//         00478494     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_00478499                                                 XREF[2]:     0047840a(j), 00478431(j)
//                              Pnl_lst.cpp:127 (2)
//         00478499     XOR        EAX,EAX
//                              Pnl_lst.cpp:128 (2)
//         0047849b     POP        ESI
//         0047849c     RET
//         0047849d     ??         90h
//         0047849e     NOP
//         0047849f     NOP
    return 0;
}

long TListPanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_move_action(TListPanel * this, long param_1, l
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004784bb(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004784b7(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_move_action@TListPanel@@UAEJJJHH@Z                    XREF[1]:     005715f8(*)
//                               TListPanel::mouse_move_action
//                              Pnl_lst.cpp:134 (5)
//         004784a0     PUSH       EBX
//         004784a1     PUSH       ESI
//         004784a2     MOV        ESI,this
//         004784a4     PUSH       EDI
//                              Pnl_lst.cpp:137 (10)
//         004784a5     MOV        EAX,dword ptr [ESI + 0x188]
//         004784ab     TEST       EAX,EAX
//         004784ad     JNZ        LAB_004784b7
//                              Pnl_lst.cpp:138 (2)
//         004784af     XOR        EAX,EAX
//                              Pnl_lst.cpp:148 (6)
//         004784b1     POP        EDI
//         004784b2     POP        ESI
//         004784b3     POP        EBX
//         004784b4     RET        0x10
//                               LAB_004784b7                                                 XREF[1]:     004784ad(j)
//                              Pnl_lst.cpp:140 (24)
//         004784b7     MOV        EDI,dword ptr [ESP + param_2]
//         004784bb     MOV        EBX,dword ptr [ESP + param_1]
//         004784bf     MOV        EAX,dword ptr [ESI]
//         004784c1     PUSH       EDI
//         004784c2     PUSH       EBX
//         004784c3     MOV        this,ESI
//         004784c5     CALL       dword ptr [EAX + 0xbc]
//         004784cb     TEST       EAX,EAX
//         004784cd     JNZ        LAB_004784d5
//                              Pnl_lst.cpp:148 (6)
//         004784cf     POP        EDI
//         004784d0     POP        ESI
//         004784d1     POP        EBX
//         004784d2     RET        0x10
//                               LAB_004784d5                                                 XREF[1]:     004784cd(j)
//                              Pnl_lst.cpp:143 (9)
//         004784d5     PUSH       EDI
//         004784d6     PUSH       EBX=>DAT_fffffff8
//         004784d7     MOV        this,ESI
//         004784d9     CALL       TListPanel::item_at                              short item_at(TListPanel * this, long param_1
//                              Pnl_lst.cpp:144 (18)
//         004784de     CMP        AX,word ptr [ESI + 0xfc]
//         004784e5     JL         LAB_004784f9
//         004784e7     CMP        AX,word ptr [ESI + 0xfe]
//         004784ee     JG         LAB_004784f9
//                              Pnl_lst.cpp:145 (9)
//         004784f0     PUSH       EDI
//         004784f1     PUSH       EBX=>DAT_fffffff8
//         004784f2     MOV        this,ESI
//         004784f4     CALL       TListPanel::goto_item                            void goto_item(TListPanel * this, long param_
//                               LAB_004784f9                                                 XREF[2]:     004784e5(j), 004784ee(j)
//                              Pnl_lst.cpp:148 (11)
//         004784f9     POP        EDI
//         004784fa     POP        ESI
//         004784fb     MOV        EAX,0x1
//         00478500     POP        EBX
//         00478501     RET        0x10
//         00478504     ??         90h
//         00478505     NOP
//         00478506     NOP
//         00478507     NOP
//         00478508     NOP
//         00478509     NOP
//         0047850a     NOP
//         0047850b     NOP
//         0047850c     NOP
//         0047850d     NOP
//         0047850e     NOP
//         0047850f     NOP
    return 0;
}

long TListPanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_down_action(TListPanel * this, long param
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0047851c(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00478518(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_down_action@TListPanel@@UAEJJJHH@Z               XREF[1]:     005715fc(*)
//                               TListPanel::mouse_left_down_action
//                              Pnl_lst.cpp:154 (3)
//         00478510     PUSH       ESI
//         00478511     MOV        ESI,this
//                              Pnl_lst.cpp:155 (5)
//         00478513     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
//                              Pnl_lst.cpp:156 (17)
//         00478518     MOV        EAX,dword ptr [ESP + param_2]
//         0047851c     MOV        this,dword ptr [ESP + param_1]
//         00478520     PUSH       EAX
//         00478521     PUSH       this
//         00478522     MOV        this,ESI
//         00478524     CALL       TListPanel::goto_item                            void goto_item(TListPanel * this, long param_
//                              Pnl_lst.cpp:157 (5)
//         00478529     MOV        EAX,0x1
//                              Pnl_lst.cpp:158 (4)
//         0047852e     POP        ESI
//         0047852f     RET        0x10
//         00478532     ??         90h
//         00478533     NOP
//         00478534     NOP
//         00478535     NOP
//         00478536     NOP
//         00478537     NOP
//         00478538     NOP
//         00478539     NOP
//         0047853a     NOP
//         0047853b     NOP
//         0047853c     NOP
//         0047853d     NOP
//         0047853e     NOP
//         0047853f     NOP
    return 0;
}

long TListPanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_move_action(TListPanel * this, long param
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00478566(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00478543(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_move_action@TListPanel@@UAEJJJHH@Z               XREF[1]:     00571604(*)
//                               TListPanel::mouse_left_move_action
//                              Pnl_lst.cpp:164 (3)
//         00478540     PUSH       ESI
//         00478541     MOV        ESI,this
//                              Pnl_lst.cpp:165 (20)
//         00478543     MOV        this,dword ptr [ESP + param_2]
//         00478547     MOV        EAX,dword ptr [ESI + 0x10]
//         0047854a     CMP        this,EAX
//         0047854c     JL         LAB_0047857f
//         0047854e     MOV        EDX,dword ptr [ESI + 0x18]
//         00478551     ADD        EDX,EAX
//         00478553     CMP        this,EDX
//         00478555     JGE        LAB_0047857b
//                              Pnl_lst.cpp:167 (2)
//         00478557     XOR        EAX,EAX
//                              Pnl_lst.cpp:169 (25)
//         00478559     PUSH       this
//         0047855a     MOV        dword ptr [ESI + 0x194],EAX
//         00478560     MOV        dword ptr [ESI + 0x198],EAX
//         00478566     MOV        EAX,dword ptr [ESP + param_1]
//         0047856a     MOV        this,ESI
//         0047856c     PUSH       EAX
//         0047856d     CALL       TListPanel::goto_item                            void goto_item(TListPanel * this, long param_
//                              Pnl_lst.cpp:195 (5)
//         00478572     MOV        EAX,0x1
//                              Pnl_lst.cpp:196 (4)
//         00478577     POP        ESI
//         00478578     RET        0x10
//                               LAB_0047857b                                                 XREF[1]:     00478555(j)
//                              Pnl_lst.cpp:171 (4)
//         0047857b     CMP        this,EAX
//         0047857d     JGE        LAB_004785a2
//                               LAB_0047857f                                                 XREF[1]:     0047854c(j)
//                              Pnl_lst.cpp:174 (18)
//         0047857f     MOV        this,dword ptr [ESI + 0x194]
//         00478585     XOR        EAX,EAX
//         00478587     CMP        this,EAX
//         00478589     MOV        dword ptr [ESI + 0x198],EAX
//         0047858f     JNZ        LAB_00478600
//                              Pnl_lst.cpp:176 (10)
//         00478591     MOV        dword ptr [ESI + 0x194],0x1
//                              Pnl_lst.cpp:177 (5)
//         0047859b     PUSH       0xb1
//                              Pnl_lst.cpp:180 (13)
//         004785a0     JMP        LAB_004785ce
//                               LAB_004785a2                                                 XREF[1]:     0047857d(j)
//         004785a2     MOV        EDX,dword ptr [ESI + 0x18]
//         004785a5     LEA        EAX,[EDX + EAX*0x1 + -0x1]
//         004785a9     CMP        this,EAX
//         004785ab     JLE        LAB_004785f2
//                              Pnl_lst.cpp:183 (18)
//         004785ad     MOV        this,dword ptr [ESI + 0x198]
//         004785b3     XOR        EAX,EAX
//         004785b5     CMP        this,EAX
//         004785b7     MOV        dword ptr [ESI + 0x194],EAX
//         004785bd     JNZ        LAB_00478600
//                              Pnl_lst.cpp:185 (10)
//         004785bf     MOV        dword ptr [ESI + 0x198],0x1
//                              Pnl_lst.cpp:186 (32)
//         004785c9     PUSH       0xba
//                               LAB_004785ce                                                 XREF[1]:     004785a0(j)
//         004785ce     PUSH       s_C:\msdev\work\age1_x1\Pnl_lst.cp               = "C:\\msdev\\work\\age1_x1\\Pnl_lst.cpp"
//         004785d3     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004785d8     MOV        this,dword ptr [ESI + 0x190]
//         004785de     ADD        ESP,0x8
//         004785e1     SUB        EAX,this
//         004785e3     MOV        dword ptr [ESI + 0x18c],EAX
//                              Pnl_lst.cpp:195 (5)
//         004785e9     MOV        EAX,0x1
//                              Pnl_lst.cpp:196 (4)
//         004785ee     POP        ESI
//         004785ef     RET        0x10
//                               LAB_004785f2                                                 XREF[1]:     004785ab(j)
//                              Pnl_lst.cpp:191 (8)
//         004785f2     XOR        EAX,EAX
//         004785f4     MOV        dword ptr [ESI + 0x194],EAX
//                              Pnl_lst.cpp:192 (6)
//         004785fa     MOV        dword ptr [ESI + 0x198],EAX
//                               LAB_00478600                                                 XREF[2]:     0047858f(j), 004785bd(j)
//                              Pnl_lst.cpp:195 (5)
//         00478600     MOV        EAX,0x1
//                              Pnl_lst.cpp:196 (4)
//         00478605     POP        ESI
//         00478606     RET        0x10
//         00478609     ??         90h
//         0047860a     NOP
//         0047860b     NOP
//         0047860c     NOP
//         0047860d     NOP
//         0047860e     NOP
//         0047860f     NOP
    return 0;
}

long TListPanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_up_action(TListPanel * this, long param_1
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_up_action@TListPanel@@UAEJJJHH@Z                 XREF[1]:     00571608(*)
//                               TListPanel::mouse_left_up_action
//                              Pnl_lst.cpp:202 (3)
//         00478610     PUSH       ESI
//         00478611     MOV        ESI,this
//                              Pnl_lst.cpp:203 (5)
//         00478613     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              Pnl_lst.cpp:206 (43)
//         00478618     MOV        this,dword ptr [ESI + 0x40]
//         0047861b     XOR        EDX,EDX
//         0047861d     CMP        this,EDX
//         0047861f     MOV        dword ptr [ESI + 0x194],EDX
//         00478625     MOV        dword ptr [ESI + 0x198],EDX
//         0047862b     JZ         LAB_00478655
//         0047862d     MOV        AX,word ptr [ESI + 0x100]
//         00478634     CMP        AX,0xffff
//         00478638     JLE        LAB_00478655
//         0047863a     CMP        AX,word ptr [ESI + 0xf8]
//         00478641     JGE        LAB_00478655
//                              Pnl_lst.cpp:208 (18)
//         00478643     MOVSX      EAX,AX
//         00478646     PUSH       EDI
//         00478647     MOV        EDI,dword ptr [this->_padding_]
//         00478649     PUSH       EDX
//         0047864a     PUSH       EAX
//         0047864b     PUSH       0x2
//         0047864d     PUSH       ESI
//         0047864e     CALL       dword ptr [EDI + 0xb4]
//         00478654     POP        EDI
//                               LAB_00478655                                                 XREF[3]:     0047862b(j), 00478638(j),
//                                                                                                         00478641(j)
//                              Pnl_lst.cpp:209 (5)
//         00478655     MOV        EAX,0x1
//                              Pnl_lst.cpp:210 (4)
//         0047865a     POP        ESI
//         0047865b     RET        0x10
//         0047865e     ??         90h
//         0047865f     NOP
    return 0;
}

long TListPanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              long __thiscall mouse_left_dbl_click_action(TListPanel * this, long
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00478668(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00478660(R)
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//                               ?mouse_left_dbl_click_action@TListPanel@@UAEJJJHH@Z          XREF[1]:     0057160c(*)
//                               TListPanel::mouse_left_dbl_click_action
//                              Pnl_lst.cpp:216 (20)
//         00478660     MOV        EAX,dword ptr [ESP + param_2]
//         00478664     PUSH       ESI
//         00478665     MOV        ESI,this
//         00478667     PUSH       EAX
//         00478668     MOV        this,dword ptr [ESP + param_1]
//         0047866c     PUSH       this
//         0047866d     MOV        this,ESI
//         0047866f     CALL       TListPanel::goto_item                            void goto_item(TListPanel * this, long param_
//                              Pnl_lst.cpp:218 (29)
//         00478674     MOV        this,dword ptr [ESI + 0x40]
//         00478677     TEST       this,this
//         00478679     JZ         LAB_004786a2
//         0047867b     MOV        AX,word ptr [ESI + 0x100]
//         00478682     CMP        AX,0xffff
//         00478686     JLE        LAB_004786a2
//         00478688     CMP        AX,word ptr [ESI + 0xf8]
//         0047868f     JGE        LAB_004786a2
//                              Pnl_lst.cpp:219 (17)
//         00478691     MOV        EDX,dword ptr [this->_padding_]
//         00478693     PUSH       0x0
//         00478695     MOVSX      EAX,AX
//         00478698     PUSH       EAX
//         00478699     PUSH       0x3
//         0047869b     PUSH       ESI
//         0047869c     CALL       dword ptr [EDX + 0xb4]
//                               LAB_004786a2                                                 XREF[3]:     00478679(j), 00478686(j),
//                                                                                                         0047868f(j)
//                              Pnl_lst.cpp:220 (5)
//         004786a2     MOV        EAX,0x1
//                              Pnl_lst.cpp:221 (4)
//         004786a7     POP        ESI
//         004786a8     RET        0x10
//         004786ab     ??         90h
//         004786ac     NOP
//         004786ad     NOP
//         004786ae     NOP
//         004786af     NOP
    return 0;
}

short TListPanel::item_at(long param_1, long param_2) {
    /* TODO: Stub */
//                              short __thiscall item_at(TListPanel * this, long param_1, long param
//              short             AX:2           <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004786ce(R)
//                               ?item_at@TListPanel@@QAEFJJ@Z                                XREF[2]:     mouse_move_action:004784d9(c),
//                               TListPanel::item_at                                                       goto_item:00478711(c)
//                              Pnl_lst.cpp:227 (12)
//         004786b0     MOV        EDX,dword ptr [ECX + this->_padding_]
//         004786b6     PUSH       ESI
//         004786b7     TEST       EDX,EDX
//         004786b9     PUSH       EDI
//         004786ba     JNZ        LAB_004786c4
//                              Pnl_lst.cpp:231 (6)
//         004786bc     MOV        ESI,dword ptr [ECX + this->_padding_]
//                              Pnl_lst.cpp:232 (2)
//         004786c2     JMP        LAB_004786ce
//                               LAB_004786c4                                                 XREF[1]:     004786ba(j)
//                              Pnl_lst.cpp:233 (10)
//         004786c4     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004786ca     LEA        ESI,[EAX + EDX*0x2 + -0x1]
//                               LAB_004786ce                                                 XREF[1]:     004786c2(j)
//                              Pnl_lst.cpp:235 (26)
//         004786ce     MOV        EAX,dword ptr [ESP + param_2]
//         004786d2     MOV        EDI,dword ptr [ECX + this->_padding_]
//         004786d8     SUB        EAX,EDI
//         004786da     MOV        EDI,dword ptr [ECX + this->_padding_]
//         004786dd     SUB        EAX,EDI
//         004786df     MOV        this,word ptr [ECX + this->_padding_]
//         004786e6     SUB        EAX,EDX
//                              Pnl_lst.cpp:237 (10)
//         004786e8     POP        EDI
//         004786e9     CDQ
//         004786ea     IDIV       ESI
//         004786ec     POP        ESI
//         004786ed     ADD        EAX,this
//         004786ef     RET        0x8
//         004786f2     ??         90h
//         004786f3     NOP
//         004786f4     NOP
//         004786f5     NOP
//         004786f6     NOP
//         004786f7     NOP
//         004786f8     NOP
//         004786f9     NOP
//         004786fa     NOP
//         004786fb     NOP
//         004786fc     NOP
//         004786fd     NOP
//         004786fe     NOP
//         004786ff     NOP
    return 0;
}

void TListPanel::goto_item(long param_1, long param_2) {
    /* TODO: Stub */
//                              void __thiscall goto_item(TListPanel * this, long param_1, long para
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00478709(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00478700(R)
//                               ?goto_item@TListPanel@@QAEXJJ@Z                              XREF[4]:     mouse_move_action:004784f4(c),
//                               TListPanel::goto_item                                                     mouse_left_down_action:00478524(c)
//                                                                                                         mouse_left_move_action:0047856d(c)
//                                                                                                         mouse_left_dbl_click_action:004786
//                              Pnl_lst.cpp:243 (32)
//         00478700     MOV        EAX,dword ptr [ESP + param_2]
//         00478704     PUSH       ESI
//         00478705     MOV        ESI,this
//         00478707     PUSH       0x1
//         00478709     MOV        this,dword ptr [ESP + param_1]
//         0047870d     PUSH       EAX
//         0047870e     PUSH       this
//         0047870f     MOV        this,ESI
//         00478711     CALL       TListPanel::item_at                              short item_at(TListPanel * this, long param_1
//         00478716     PUSH       EAX
//         00478717     PUSH       0x1
//         00478719     MOV        this,ESI
//         0047871b     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:245 (4)
//         00478720     POP        ESI
//         00478721     RET        0x8
//         00478724     ??         90h
//         00478725     NOP
//         00478726     NOP
//         00478727     NOP
//         00478728     NOP
//         00478729     NOP
//         0047872a     NOP
//         0047872b     NOP
//         0047872c     NOP
//         0047872d     NOP
//         0047872e     NOP
//         0047872f     NOP
    return;
}

long TListPanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TListPanel * this, long param_1, sho
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00478730(R)
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?key_down_action@TListPanel@@UAEJJFHHH@Z                     XREF[1]:     00571624(*)
//                               TListPanel::key_down_action
//                              Pnl_lst.cpp:251 (32)
//         00478730     MOV        EAX,dword ptr [ESP + param_1]
//         00478734     PUSH       ESI
//         00478735     ADD        EAX,-0xd
//         00478738     CMP        EAX,0x1b
//         0047873b     JA         switchD_00478749::caseD_e
//         00478741     XOR        EDX,EDX
//         00478743     MOV        DL,byte ptr [EAX + 0x478828]=>PTR_caseD_24_004
//                               switchD_00478749::switchD
//         00478749     JMP        dword ptr [EDX*0x4 + switchD_00478749::switchd   = 004787c8
//                               switchD_00478749::caseD_28                                   XREF[2]:     00478749(j), 00478820(*)
//                              Pnl_lst.cpp:255 (11)
//         00478750     PUSH       0x1
//         00478752     PUSH       0x0
//         00478754     PUSH       0x2
//         00478756     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:256 (5)
//         0047875b     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         00478760     POP        ESI
//         00478761     RET        0x14
//                               switchD_00478749::caseD_26                                   XREF[2]:     00478749(j), 0047881c(*)
//                              Pnl_lst.cpp:259 (11)
//         00478764     PUSH       0x1
//         00478766     PUSH       0x0
//         00478768     PUSH       0x3
//         0047876a     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:260 (5)
//         0047876f     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         00478774     POP        ESI
//         00478775     RET        0x14
//                               switchD_00478749::caseD_22                                   XREF[2]:     00478749(j), 00478810(*)
//                              Pnl_lst.cpp:263 (11)
//         00478778     PUSH       0x1
//         0047877a     PUSH       0x0
//         0047877c     PUSH       0x4
//         0047877e     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:264 (5)
//         00478783     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         00478788     POP        ESI
//         00478789     RET        0x14
//                               switchD_00478749::caseD_21                                   XREF[2]:     00478749(j), 0047880c(*)
//                              Pnl_lst.cpp:267 (11)
//         0047878c     PUSH       0x1
//         0047878e     PUSH       0x0
//         00478790     PUSH       0x5
//         00478792     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:268 (5)
//         00478797     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         0047879c     POP        ESI
//         0047879d     RET        0x14
//                               switchD_00478749::caseD_24                                   XREF[2]:     00478749(j), 00478818(*)
//                              Pnl_lst.cpp:271 (11)
//         004787a0     PUSH       0x1
//         004787a2     PUSH       0x0
//         004787a4     PUSH       0x6
//         004787a6     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:272 (5)
//         004787ab     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         004787b0     POP        ESI
//         004787b1     RET        0x14
//                               switchD_00478749::caseD_23                                   XREF[2]:     00478749(j), 00478814(*)
//                              Pnl_lst.cpp:275 (11)
//         004787b4     PUSH       0x1
//         004787b6     PUSH       0x0
//         004787b8     PUSH       0x7
//         004787ba     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:276 (5)
//         004787bf     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         004787c4     POP        ESI
//         004787c5     RET        0x14
//                               switchD_00478749::caseD_d                                    XREF[2]:     00478749(j), 00478808(*)
//                              Pnl_lst.cpp:279 (29)
//         004787c8     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004787cb     TEST       EAX,EAX
//         004787cd     JZ         LAB_004787f8
//         004787cf     MOV        DX,word ptr [ECX + this->_padding_]
//         004787d6     CMP        DX,-0x1
//         004787da     JLE        LAB_004787f8
//         004787dc     CMP        DX,word ptr [ECX + this->_padding_]
//         004787e3     JGE        LAB_004787f8
//                              Pnl_lst.cpp:280 (19)
//         004787e5     MOV        ESI,dword ptr [EAX]
//         004787e7     PUSH       0x0
//         004787e9     MOVSX      EDX,DX
//         004787ec     PUSH       EDX
//         004787ed     PUSH       0x3
//         004787ef     PUSH       this
//         004787f0     MOV        this,EAX
//         004787f2     CALL       dword ptr [ESI + 0xb4]
//                               LAB_004787f8                                                 XREF[3]:     004787cd(j), 004787da(j),
//                                                                                                         004787e3(j)
//                              Pnl_lst.cpp:281 (5)
//         004787f8     MOV        EAX,0x1
//                              Pnl_lst.cpp:285 (4)
//         004787fd     POP        ESI
//         004787fe     RET        0x14
//                               switchD_00478749::caseD_f                                    XREF[3]:     0047873b(j), 00478749(j),
//                               switchD_00478749::caseD_10                                                00478824(*)
//                               switchD_00478749::caseD_11
//                               switchD_00478749::caseD_12
//                               switchD_00478749::caseD_13
//                               switchD_00478749::caseD_14
//                               switchD_00478749::caseD_15
//                               switchD_00478749::caseD_16
//                               switchD_00478749::caseD_17
//                               switchD_00478749::caseD_18
//                               switchD_00478749::caseD_19
//                               switchD_00478749::caseD_1a
//                               switchD_00478749::caseD_1b
//                               switchD_00478749::caseD_1c
//                               switchD_00478749::caseD_1d
//                               switchD_00478749::caseD_1e
//                               switchD_00478749::caseD_1f
//                               switchD_00478749::caseD_20
//                               switchD_00478749::caseD_25
//                               switchD_00478749::caseD_27
//                               switchD_00478749::caseD_e
//                              Pnl_lst.cpp:284 (2)
//         00478801     XOR        EAX,EAX
//                              Pnl_lst.cpp:285 (65)
//         00478803     POP        ESI
//         00478804     RET        0x14
//         00478807     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00478749::switchdataD_00478808                       XREF[1]:     key_down_action:00478749(*)
//         00478808     addr       switchD_00478749::caseD_d
//         0047880c     addr       switchD_00478749::caseD_21
//         00478810     addr       switchD_00478749::caseD_22
//         00478814     addr       switchD_00478749::caseD_23
//                               PTR_caseD_24_00478818+3                                      XREF[0,1]:   key_down_action:00478743(*)
//         00478818     addr       switchD_00478749::caseD_24
//         0047881c     addr       switchD_00478749::caseD_26
//         00478820     addr       switchD_00478749::caseD_28
//         00478824     addr       switchD_00478749::caseD_e
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00478749::switchdataD_00478828
//         00478828     db         0h
//         00478829     db         7h
//         0047882a     db         7h
//         0047882b     db         7h
//         0047882c     db         7h
//         0047882d     db         7h
//         0047882e     db         7h
//         0047882f     db         7h
//         00478830     db         7h
//         00478831     db         7h
//         00478832     db         7h
//         00478833     db         7h
//         00478834     db         7h
//         00478835     db         7h
//         00478836     db         7h
//         00478837     db         7h
//         00478838     db         7h
//         00478839     db         7h
//         0047883a     db         7h
//         0047883b     db         7h
//         0047883c     db         1h
//         0047883d     db         2h
//         0047883e     db         3h
//         0047883f     db         4h
//         00478840     db         7h
//         00478841     db         5h
//         00478842     db         7h
//         00478843     db         6h
//         00478844     ??         90h
//         00478845     ??         90h
//         00478846     ??         90h
//         00478847     ??         90h
//         00478848     ??         90h
//         00478849     ??         90h
//         0047884a     ??         90h
//         0047884b     ??         90h
//         0047884c     ??         90h
//         0047884d     ??         90h
//         0047884e     ??         90h
//         0047884f     ??         90h
    return 0;
}

long TListPanel::char_action(long param_1, short param_2) {
    /* TODO: Stub */
//                              long __thiscall char_action(TListPanel * this, long param_1, short p
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00478850(R)
//              short             Stack[0x8]:2   param_2
//                               ?char_action@TListPanel@@UAEJJF@Z                            XREF[1]:     00571628(*)
//                               TListPanel::char_action
//                              Pnl_lst.cpp:291 (16)
//         00478850     MOV        EAX,dword ptr [ESP + param_1]
//         00478854     PUSH       EBX
//         00478855     PUSH       EBP
//         00478856     PUSH       ESI
//         00478857     PUSH       EDI
//         00478858     MOV        EBX,this
//         0047885a     PUSH       EAX
//         0047885b     CALL       toupper                                          undefined toupper()
//                              Pnl_lst.cpp:301 (17)
//         00478860     MOV        ESI,dword ptr [EBX + 0xf4]
//         00478866     ADD        ESP,0x4
//         00478869     XOR        EDI,EDI
//         0047886b     MOV        EBP,EAX
//         0047886d     TEST       ESI,ESI
//         0047886f     JZ         LAB_00478896
//                               LAB_00478871                                                 XREF[1]:     00478894(j)
//                              Pnl_lst.cpp:303 (11)
//         00478871     MOVSX      this,word ptr [EBX + 0x100]
//         00478878     CMP        EDI,this
//         0047887a     JLE        LAB_0047888e
//                              Pnl_lst.cpp:305 (18)
//         0047887c     MOV        EDX,dword ptr [ESI]
//         0047887e     MOVSX      EAX,byte ptr [EDX]
//         00478881     PUSH       EAX
//         00478882     CALL       toupper                                          undefined toupper()
//         00478887     ADD        ESP,0x4
//         0047888a     CMP        EAX,EBP
//         0047888c     JZ         LAB_004788da
//                               LAB_0047888e                                                 XREF[1]:     0047887a(j)
//                              Pnl_lst.cpp:301 (3)
//         0047888e     MOV        ESI,dword ptr [ESI + 0xc]
//                              Pnl_lst.cpp:311 (5)
//         00478891     INC        EDI
//         00478892     TEST       ESI,ESI
//         00478894     JNZ        LAB_00478871
//                               LAB_00478896                                                 XREF[1]:     0047886f(j)
//                              Pnl_lst.cpp:315 (10)
//         00478896     CMP        word ptr [EBX + 0x100],0x0
//         0047889e     JLE        LAB_004788f2
//                              Pnl_lst.cpp:318 (12)
//         004788a0     MOV        ESI,dword ptr [EBX + 0xf4]
//         004788a6     XOR        EDI,EDI
//         004788a8     TEST       ESI,ESI
//         004788aa     JZ         LAB_004788f2
//                               LAB_004788ac                                                 XREF[1]:     004788cf(j)
//                              Pnl_lst.cpp:320 (18)
//         004788ac     MOV        this,dword ptr [ESI]
//         004788ae     MOVSX      EDX,byte ptr [this->_padding_]
//         004788b1     PUSH       EDX
//         004788b2     CALL       toupper                                          undefined toupper()
//         004788b7     ADD        ESP,0x4
//         004788ba     CMP        EAX,EBP
//         004788bc     JZ         LAB_004788da
//                              Pnl_lst.cpp:326 (19)
//         004788be     MOVSX      EAX,word ptr [EBX + 0x100]
//         004788c5     INC        EDI
//         004788c6     CMP        EDI,EAX
//         004788c8     JGE        LAB_004788f2
//         004788ca     MOV        ESI,dword ptr [ESI + 0xc]
//         004788cd     TEST       ESI,ESI
//         004788cf     JNZ        LAB_004788ac
//                              Pnl_lst.cpp:331 (2)
//         004788d1     XOR        EAX,EAX
//                              Pnl_lst.cpp:332 (7)
//         004788d3     POP        EDI
//         004788d4     POP        ESI
//         004788d5     POP        EBP
//         004788d6     POP        EBX
//         004788d7     RET        0x8
//                               LAB_004788da                                                 XREF[2]:     0047888c(j), 004788bc(j)
//                              Pnl_lst.cpp:322 (12)
//         004788da     PUSH       0x1
//         004788dc     PUSH       EDI
//         004788dd     PUSH       0x1
//         004788df     MOV        this,EBX
//         004788e1     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                              Pnl_lst.cpp:323 (5)
//         004788e6     MOV        EAX,0x1
//                              Pnl_lst.cpp:332 (16)
//         004788eb     POP        EDI
//         004788ec     POP        ESI
//         004788ed     POP        EBP
//         004788ee     POP        EBX
//         004788ef     RET        0x8
//                               LAB_004788f2                                                 XREF[3]:     0047889e(j), 004788aa(j),
//                                                                                                         004788c8(j)
//         004788f2     POP        EDI
//         004788f3     POP        ESI
//         004788f4     POP        EBP
//         004788f5     XOR        EAX,EAX
//         004788f7     POP        EBX
//         004788f8     RET        0x8
//         004788fb     ??         90h
//         004788fc     NOP
//         004788fd     NOP
//         004788fe     NOP
//         004788ff     NOP
    return 0;
}

long TListPanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TListPanel * this, TPanel * param_1, long par
//              long              EAX:4          <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0047890e(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     00478909(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     00478904(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     00478900(R)
//                               ?action@TListPanel@@UAEJPAVTPanel@@JKK@Z                     XREF[1]:     0057162c(*)
//                               TListPanel::action
//                              Pnl_lst.cpp:338 (25)
//         00478900     MOV        EAX,dword ptr [ESP + param_4]
//         00478904     MOV        EDX,dword ptr [ESP + param_3]
//         00478908     PUSH       EAX
//         00478909     MOV        EAX,dword ptr [ESP + param_2]
//         0047890d     PUSH       EDX
//         0047890e     MOV        EDX,dword ptr [ESP + param_1]
//         00478912     PUSH       EAX
//         00478913     PUSH       EDX
//         00478914     CALL       TTextPanel::action                               long action(TTextPanel * this, TPanel * param
//                              Pnl_lst.cpp:367 (3)
//         00478919     RET        0x10
//         0047891c     ??         90h
//         0047891d     NOP
//         0047891e     NOP
//         0047891f     NOP
    return 0;
}

void TListPanel::scroll_cur_line(uchar param_1, short param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall scroll_cur_line(TListPanel * this, uchar param_1, sh
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00478923(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00478948(R)
//              int               Stack[0xc]:4   param_3                   XREF[8]:     0047898e(R), 004789b2(R), 00478a1a(R), 00478a64(R),
//                                                                                     00478aad(R), 00478add(R), 00478afd(R), 00478b1d(R)
//                               ?scroll_cur_line@TListPanel@@QAEXEFH@Z                       XREF[29]:    setup:0043f07c(c),
//                               TListPanel::scroll_cur_line                                               create_list:0046983e(c),
//                                                                                                         handle_idle:0047845a(c),
//                                                                                                         handle_idle:00478467(c),
//                                                                                                         handle_idle:00478487(c),
//                                                                                                         handle_idle:00478494(c),
//                                                                                                         goto_item:0047871b(c),
//                                                                                                         char_action:004788e1(c),
//                                                                                                         add_scenario:004903ed(c),
//                                                                                                         move_scenario_up:0049050b(c),
//                                                                                                         fillScenarios:00491337(c),
//                                                                                                         TribeLoadSavedGameScreen:0049e022(
//                                                                                                         set_terrain:004aadb6(c),
//                                                                                                         set_elevation:004aae0b(c),
//                                                                                                         set_unit_player:004ab62f(c),
//                                                                                                         set_unit:004ab692(c),
//                                                                                                         set_unit:004ab6cd(c),
//                                                                                                         getSettings:004b47a7(c),
//                                                                                                         getSettings:004b47c0(c),
//                                                                                                         getSettings:004b62a6(c), [more]
//                              Pnl_lst.cpp:373 (3)
//         00478920     PUSH       ESI
//         00478921     MOV        ESI,this
//                              Pnl_lst.cpp:378 (37)
//         00478923     MOV        this,dword ptr [ESP + param_1]
//         00478927     PUSH       EDI
//         00478928     MOV        AX,word ptr [ESI + 0x100]
//         0047892f     AND        this,0xff
//         00478935     DEC        this
//         00478936     MOV        EDI,EAX
//         00478938     CMP        this,0x6
//         0047893b     JA         switchD_00478941::default
//                               switchD_00478941::switchD
//         00478941     JMP        dword ptr [this->_padding_*0x4 + switchD_00478   = 00478948
//                               switchD_00478941::caseD_0                                    XREF[2]:     00478941(j), 00478b7c(*)
//                              Pnl_lst.cpp:381 (5)
//         00478948     MOV        AX,word ptr [ESP + param_2]
//                              Pnl_lst.cpp:382 (12)
//         0047894d     TEST       AX,AX
//         00478950     MOV        word ptr [ESI + 0x100],AX
//         00478957     JGE        LAB_00478964
//                              Pnl_lst.cpp:383 (9)
//         00478959     MOV        word ptr [ESI + 0x100],0x0
//                              Pnl_lst.cpp:384 (20)
//         00478962     JMP        LAB_0047897e
//                               LAB_00478964                                                 XREF[1]:     00478957(j)
//         00478964     MOV        this,word ptr [ESI + 0xf8]
//         0047896b     MOVSX      EDX,this
//         0047896e     MOVSX      EAX,AX
//         00478971     DEC        EDX
//         00478972     CMP        EAX,EDX
//         00478974     JLE        LAB_0047897e
//                              Pnl_lst.cpp:385 (8)
//         00478976     DEC        this
//         00478977     MOV        word ptr [ESI + 0x100],this
//                               LAB_0047897e                                                 XREF[2]:     00478962(j), 00478974(j)
//                              Pnl_lst.cpp:386 (16)
//         0047897e     MOV        AX,word ptr [ESI + 0x100]
//         00478985     CMP        AX,word ptr [ESI + 0xfc]
//         0047898c     JGE        LAB_004789a2
//                              Pnl_lst.cpp:387 (15)
//         0047898e     MOV        this,dword ptr [ESP + param_3]
//         00478992     PUSH       this
//         00478993     PUSH       EAX
//         00478994     PUSH       0x1
//         00478996     MOV        this,ESI
//         00478998     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:388 (21)
//         0047899d     JMP        switchD_00478941::default
//                               LAB_004789a2                                                 XREF[1]:     0047898c(j)
//         004789a2     MOV        this,word ptr [ESI + 0xfe]
//         004789a9     CMP        AX,this
//         004789ac     JLE        switchD_00478941::default
//                              Pnl_lst.cpp:389 (17)
//         004789b2     MOV        EDX,dword ptr [ESP + param_3]
//         004789b6     SUB        EAX,this
//         004789b8     PUSH       EDX
//         004789b9     PUSH       EAX
//         004789ba     PUSH       0x0
//         004789bc     MOV        this,ESI
//         004789be     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:390 (5)
//         004789c3     JMP        switchD_00478941::default
//                               switchD_00478941::caseD_1                                    XREF[2]:     00478941(j), 00478b80(*)
//                              Pnl_lst.cpp:393 (21)
//         004789c8     CMP        AX,word ptr [ESI + 0xfc]
//         004789cf     JL         LAB_004789dd
//         004789d1     MOV        this,word ptr [ESI + 0xfe]
//         004789d8     CMP        AX,this
//         004789db     JLE        LAB_004789eb
//                               LAB_004789dd                                                 XREF[1]:     004789cf(j)
//                              Pnl_lst.cpp:394 (14)
//         004789dd     MOV        this,word ptr [ESI + 0xfe]
//         004789e4     MOV        word ptr [ESI + 0x100],this
//                               LAB_004789eb                                                 XREF[1]:     004789db(j)
//                              Pnl_lst.cpp:395 (12)
//         004789eb     MOV        AX,word ptr [ESI + 0x100]
//         004789f2     CMP        AX,this
//         004789f5     JGE        LAB_004789fd
//                              Pnl_lst.cpp:396 (1)
//         004789f7     INC        EAX
//                              Pnl_lst.cpp:397 (5)
//         004789f8     JMP        LAB_00478b34
//                               LAB_004789fd                                                 XREF[1]:     004789f5(j)
//                              Pnl_lst.cpp:399 (19)
//         004789fd     MOVSX      this,word ptr [ESI + 0xf8]
//         00478a04     MOVSX      EDX,AX
//         00478a07     DEC        this
//         00478a08     CMP        EDX,this
//         00478a0a     JGE        switchD_00478941::default
//                              Pnl_lst.cpp:401 (1)
//         00478a10     INC        EAX
//                              Pnl_lst.cpp:402 (23)
//         00478a11     MOV        this,ESI
//         00478a13     MOV        word ptr [ESI + 0x100],AX
//         00478a1a     MOV        EAX,dword ptr [ESP + param_3]
//         00478a1e     PUSH       EAX
//         00478a1f     PUSH       0x0
//         00478a21     PUSH       0x2
//         00478a23     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:405 (5)
//         00478a28     JMP        switchD_00478941::default
//                               switchD_00478941::caseD_2                                    XREF[2]:     00478941(j), 00478b84(*)
//                              Pnl_lst.cpp:408 (21)
//         00478a2d     MOV        this,word ptr [ESI + 0xfc]
//         00478a34     CMP        AX,this
//         00478a37     JL         LAB_00478a42
//         00478a39     CMP        AX,word ptr [ESI + 0xfe]
//         00478a40     JLE        LAB_00478a49
//                               LAB_00478a42                                                 XREF[1]:     00478a37(j)
//                              Pnl_lst.cpp:409 (7)
//         00478a42     MOV        word ptr [ESI + 0x100],this
//                               LAB_00478a49                                                 XREF[1]:     00478a40(j)
//                              Pnl_lst.cpp:410 (12)
//         00478a49     MOV        AX,word ptr [ESI + 0x100]
//         00478a50     CMP        AX,this
//         00478a53     JLE        LAB_00478a5b
//                              Pnl_lst.cpp:411 (1)
//         00478a55     DEC        EAX
//                              Pnl_lst.cpp:412 (5)
//         00478a56     JMP        LAB_00478b34
//                               LAB_00478a5b                                                 XREF[1]:     00478a53(j)
//                              Pnl_lst.cpp:414 (9)
//         00478a5b     TEST       AX,AX
//         00478a5e     JLE        switchD_00478941::default
//                              Pnl_lst.cpp:417 (24)
//         00478a64     MOV        this,dword ptr [ESP + param_3]
//         00478a68     DEC        EAX
//         00478a69     PUSH       this
//         00478a6a     PUSH       0x0
//         00478a6c     PUSH       0x3
//         00478a6e     MOV        this,ESI
//         00478a70     MOV        word ptr [ESI + 0x100],AX
//         00478a77     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:420 (5)
//         00478a7c     JMP        switchD_00478941::default
//                               switchD_00478941::caseD_3                                    XREF[2]:     00478941(j), 00478b88(*)
//                              Pnl_lst.cpp:423 (21)
//         00478a81     CMP        AX,word ptr [ESI + 0xfc]
//         00478a88     JL         LAB_00478a96
//         00478a8a     MOV        this,word ptr [ESI + 0xfe]
//         00478a91     CMP        AX,this
//         00478a94     JLE        LAB_00478aa4
//                               LAB_00478a96                                                 XREF[1]:     00478a88(j)
//                              Pnl_lst.cpp:424 (14)
//         00478a96     MOV        this,word ptr [ESI + 0xfe]
//         00478a9d     MOV        word ptr [ESI + 0x100],this
//                               LAB_00478aa4                                                 XREF[1]:     00478a94(j)
//                              Pnl_lst.cpp:425 (9)
//         00478aa4     CMP        word ptr [ESI + 0x100],this
//         00478aab     JNZ        LAB_00478b14
//                              Pnl_lst.cpp:427 (9)
//         00478aad     MOV        EDX,dword ptr [ESP + param_3]
//         00478ab1     PUSH       EDX
//         00478ab2     PUSH       0x0
//         00478ab4     PUSH       0x4
//                              Pnl_lst.cpp:430 (2)
//         00478ab6     JMP        LAB_00478b26
//                               switchD_00478941::caseD_4                                    XREF[2]:     00478941(j), 00478b8c(*)
//                              Pnl_lst.cpp:435 (21)
//         00478ab8     MOV        this,word ptr [ESI + 0xfc]
//         00478abf     CMP        AX,this
//         00478ac2     JL         LAB_00478acd
//         00478ac4     CMP        AX,word ptr [ESI + 0xfe]
//         00478acb     JLE        LAB_00478ad4
//                               LAB_00478acd                                                 XREF[1]:     00478ac2(j)
//                              Pnl_lst.cpp:436 (7)
//         00478acd     MOV        word ptr [ESI + 0x100],this
//                               LAB_00478ad4                                                 XREF[1]:     00478acb(j)
//                              Pnl_lst.cpp:437 (9)
//         00478ad4     CMP        word ptr [ESI + 0x100],this
//         00478adb     JNZ        LAB_00478b14
//                              Pnl_lst.cpp:439 (16)
//         00478add     MOV        this,dword ptr [ESP + param_3]
//         00478ae1     PUSH       this
//         00478ae2     PUSH       0x0
//         00478ae4     PUSH       0x5
//         00478ae6     MOV        this,ESI
//         00478ae8     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:440 (14)
//         00478aed     MOV        DX,word ptr [ESI + 0xfc]
//         00478af4     MOV        word ptr [ESI + 0x100],DX
//                              Pnl_lst.cpp:442 (2)
//         00478afb     JMP        switchD_00478941::default
//                               switchD_00478941::caseD_5                                    XREF[2]:     00478941(j), 00478b90(*)
//                              Pnl_lst.cpp:447 (16)
//         00478afd     MOV        EAX,dword ptr [ESP + param_3]
//         00478b01     MOV        this,ESI
//         00478b03     PUSH       EAX
//         00478b04     PUSH       0x0
//         00478b06     PUSH       0x6
//         00478b08     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:448 (14)
//         00478b0d     MOV        this,word ptr [ESI + 0xfc]
//                               LAB_00478b14                                                 XREF[2]:     00478aab(j), 00478adb(j)
//         00478b14     MOV        word ptr [ESI + 0x100],this
//                              Pnl_lst.cpp:449 (2)
//         00478b1b     JMP        switchD_00478941::default
//                               switchD_00478941::caseD_6                                    XREF[2]:     00478941(j), 00478b94(*)
//                              Pnl_lst.cpp:452 (16)
//         00478b1d     MOV        EDX,dword ptr [ESP + param_3]
//         00478b21     PUSH       EDX
//         00478b22     PUSH       0x0
//         00478b24     PUSH       0x7
//                               LAB_00478b26                                                 XREF[1]:     00478ab6(j)
//         00478b26     MOV        this,ESI
//         00478b28     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                              Pnl_lst.cpp:453 (14)
//         00478b2d     MOV        AX,word ptr [ESI + 0xfe]
//                               LAB_00478b34                                                 XREF[2]:     004789f8(j), 00478a56(j)
//         00478b34     MOV        word ptr [ESI + 0x100],AX
//                               switchD_00478941::default                                    XREF[10]:    0047893b(j), 0047899d(j),
//                                                                                                         004789ac(j), 004789c3(j),
//                                                                                                         00478a0a(j), 00478a28(j),
//                                                                                                         00478a5e(j), 00478a7c(j),
//                                                                                                         00478afb(j), 00478b1b(j)
//                              Pnl_lst.cpp:457 (9)
//         00478b3b     MOV        EDX,dword ptr [ESI]
//         00478b3d     PUSH       0x1
//         00478b3f     MOV        this,ESI
//         00478b41     CALL       dword ptr [EDX + 0x20]
//                              Pnl_lst.cpp:461 (34)
//         00478b44     MOV        AX,word ptr [ESI + 0x100]
//         00478b4b     CMP        AX,DI
//         00478b4e     JZ         LAB_00478b77
//         00478b50     MOV        this,dword ptr [ESI + 0x40]
//         00478b53     TEST       this,this
//         00478b55     JZ         LAB_00478b77
//         00478b57     CMP        AX,0xffff
//         00478b5b     JLE        LAB_00478b77
//         00478b5d     CMP        AX,word ptr [ESI + 0xf8]
//         00478b64     JGE        LAB_00478b77
//                              Pnl_lst.cpp:462 (17)
//         00478b66     MOV        EDX,dword ptr [this->_padding_]
//         00478b68     PUSH       0x0
//         00478b6a     MOVSX      EAX,AX
//         00478b6d     PUSH       EAX=>DAT_fffffff8
//         00478b6e     PUSH       offset DAT_fffffff4
//         00478b70     PUSH       ESI=>DAT_fffffff0
//         00478b71     CALL       dword ptr [EDX + 0xb4]
//                               LAB_00478b77                                                 XREF[4]:     00478b4e(j), 00478b55(j),
//                                                                                                         00478b5b(j), 00478b64(j)
//                              Pnl_lst.cpp:463 (33)
//         00478b77     POP        EDI
//         00478b78     POP        ESI
//         00478b79     RET        0xc
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00478941::switchdataD_00478b7c                       XREF[1]:     scroll_cur_line:00478941(*)
//         00478b7c     addr       switchD_00478941::caseD_0
//         00478b80     addr       switchD_00478941::caseD_1
//         00478b84     addr       switchD_00478941::caseD_2
//         00478b88     addr       switchD_00478941::caseD_3
//         00478b8c     addr       switchD_00478941::caseD_4
//         00478b90     addr       switchD_00478941::caseD_5
//         00478b94     addr       switchD_00478941::caseD_6
//         00478b98     ??         90h
//         00478b99     ??         90h
//         00478b9a     ??         90h
//         00478b9b     ??         90h
//         00478b9c     ??         90h
//         00478b9d     ??         90h
//         00478b9e     ??         90h
//         00478b9f     ??         90h
    return;
}

void TListPanel::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(TListPanel * this)
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00478bd5(W)
//              void *            Stack[-0xc]:4  old_font
//                               ?draw@TListPanel@@UAEXXZ                                     XREF[1]:     005715a8(*)
//                               TListPanel::draw
//                              Pnl_lst.cpp:468 (7)
//         00478ba0     SUB        ESP,0x8
//         00478ba3     PUSH       EBP
//         00478ba4     PUSH       ESI
//         00478ba5     MOV        ESI,this
//                              Pnl_lst.cpp:474 (2)
//         00478ba7     XOR        EBP,EBP
//                              Pnl_lst.cpp:476 (34)
//         00478ba9     MOV        EAX,dword ptr [ESI + 0x20]
//         00478bac     MOV        dword ptr [ESI + 0x38],EBP
//         00478baf     CMP        EAX,EBP
//         00478bb1     JZ         LAB_00478cc9
//         00478bb7     CMP        dword ptr [ESI + 0x70],EBP
//         00478bba     JZ         LAB_00478cc9
//         00478bc0     CMP        dword ptr [ESI + 0x6c],EBP
//         00478bc3     JZ         LAB_00478cc9
//         00478bc9     PUSH       EDI
//         00478bca     PUSH       EBX
//                              Pnl_lst.cpp:480 (5)
//         00478bcb     CALL       TTextPanel::draw_background                      void draw_background(TTextPanel * this)
//                              Pnl_lst.cpp:482 (12)
//         00478bd0     MOV        EBX,dword ptr [ESI]
//         00478bd2     PUSH       EBP
//         00478bd3     MOV        this,ESI
//         00478bd5     MOV        dword ptr [ESP + local_4],EBX
//         00478bd9     CALL       dword ptr [EBX + 0x28]
//                              Pnl_lst.cpp:485 (15)
//         00478bdc     MOV        this,dword ptr [ESI + 0x20]
//         00478bdf     PUSH       s_pnl_lst::draw                                  = "pnl_lst::draw"
//         00478be4     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//         00478be9     MOV        EDI,EAX
//                              Pnl_lst.cpp:486 (8)
//         00478beb     CMP        EDI,EBP
//         00478bed     JZ         LAB_00478cb4
//                              Pnl_lst.cpp:487 (14)
//         00478bf3     MOV        EAX,dword ptr [ESI + 0x88]
//         00478bf9     PUSH       EAX
//         00478bfa     PUSH       EDI
//         00478bfb     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              Pnl_lst.cpp:488 (14)
//         00478c01     MOV        this,dword ptr [ESI + 0x104]
//         00478c07     PUSH       this
//         00478c08     PUSH       EDI
//         00478c09     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              Pnl_lst.cpp:489 (13)
//         00478c0f     PUSH       0x1
//         00478c11     PUSH       EDI
//         00478c12     MOV        dword ptr [ESP + 0x18],EAX
//         00478c16     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
//                              Pnl_lst.cpp:491 (16)
//         00478c1c     MOV        BX,word ptr [ESI + 0xfc]
//         00478c23     CMP        BX,word ptr [ESI + 0xfe]
//         00478c2a     JG         LAB_00478c8e
//                               LAB_00478c2c                                                 XREF[1]:     00478c8c(j)
//                              Pnl_lst.cpp:492 (47)
//         00478c2c     MOV        EAX,dword ptr [ESI + 0x19c]
//         00478c32     TEST       EAX,EAX
//         00478c34     JZ         LAB_00478c6b
//         00478c36     MOV        EAX,dword ptr [ESI + 0x78]
//         00478c39     TEST       EAX,EAX
//         00478c3b     JNZ        LAB_00478c44
//         00478c3d     MOV        EAX,dword ptr [ESI + 0x68]
//         00478c40     TEST       EAX,EAX
//         00478c42     JZ         LAB_00478c6b
//                               LAB_00478c44                                                 XREF[1]:     00478c3b(j)
//         00478c44     MOVSX      EAX,word ptr [ESI + 0xfc]
//         00478c4b     MOVSX      this,word ptr [ESI + 0x100]
//         00478c52     MOVSX      EDX,BP
//         00478c55     ADD        EDX,EAX
//         00478c57     CMP        EDX,this
//         00478c59     JNZ        LAB_00478c6b
//                              Pnl_lst.cpp:493 (14)
//         00478c5b     MOV        EDX,dword ptr [ESI + 0x12c]
//         00478c61     MOV        EAX,dword ptr [ESI + 0x128]
//         00478c67     PUSH       EDX
//         00478c68     PUSH       EAX
//                              Pnl_lst.cpp:494 (2)
//         00478c69     JMP        LAB_00478c79
//                               LAB_00478c6b                                                 XREF[3]:     00478c34(j), 00478c42(j),
//                                                                                                         00478c59(j)
//                              Pnl_lst.cpp:495 (35)
//         00478c6b     MOV        this,dword ptr [ESI + 0x124]
//         00478c71     MOV        EDX,dword ptr [ESI + 0x120]
//         00478c77     PUSH       this
//         00478c78     PUSH       EDX
//                               LAB_00478c79                                                 XREF[1]:     00478c69(j)
//         00478c79     PUSH       EBX
//         00478c7a     PUSH       EBP
//         00478c7b     PUSH       EDI
//         00478c7c     MOV        this,ESI
//         00478c7e     CALL       TTextPanel::draw_line                            void draw_line(TTextPanel * this, void * para
//         00478c83     INC        EBX
//         00478c84     INC        EBP
//         00478c85     CMP        BX,word ptr [ESI + 0xfe]
//         00478c8c     JLE        LAB_00478c2c
//                               LAB_00478c8e                                                 XREF[1]:     00478c2a(j)
//                              Pnl_lst.cpp:497 (12)
//         00478c8e     MOV        EAX,dword ptr [ESP + 0x10]
//         00478c92     PUSH       EAX
//         00478c93     PUSH       EDI
//         00478c94     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
//                              Pnl_lst.cpp:498 (9)
//         00478c9a     PUSH       0x0
//         00478c9c     PUSH       EDI
//         00478c9d     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
//                              Pnl_lst.cpp:499 (17)
//         00478ca3     MOV        this,dword ptr [ESI + 0x20]
//         00478ca6     PUSH       s_pnl_lst::draw                                  = "pnl_lst::draw"
//         00478cab     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//         00478cb0     MOV        EBX,dword ptr [ESP + 0x14]
//                               LAB_00478cb4                                                 XREF[1]:     00478bed(j)
//                              Pnl_lst.cpp:503 (7)
//         00478cb4     MOV        this,ESI
//         00478cb6     CALL       TTextPanel::draw_border                          void draw_border(TTextPanel * this)
//                              Pnl_lst.cpp:506 (7)
//         00478cbb     MOV        this,ESI
//         00478cbd     CALL       TListPanel::draw_highlight_bar                   void draw_highlight_bar(TListPanel * this)
//                              Pnl_lst.cpp:508 (7)
//         00478cc2     MOV        this,ESI
//         00478cc4     CALL       dword ptr [EBX + 0x2c]
//         00478cc7     POP        EBX
//         00478cc8     POP        EDI
//                               LAB_00478cc9                                                 XREF[3]:     00478bb1(j), 00478bba(j),
//                                                                                                         00478bc3(j)
//                              Pnl_lst.cpp:509 (6)
//         00478cc9     POP        ESI
//         00478cca     POP        EBP
//         00478ccb     ADD        ESP,0x8
//         00478cce     RET
//         00478ccf     ??         90h
    return;
}

void TListPanel::draw_highlight_bar() {
    /* TODO: Stub */
//                              void __thiscall draw_highlight_bar(TListPanel * this)
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00478d6c(R)
//              tagRECT           Stack[-0x14]   r                         XREF[0,2]:   00478d24(*), 00478d75(R)
//                               ?draw_highlight_bar@TListPanel@@QAEXXZ                       XREF[1]:     draw:00478cbd(c)
//                               TListPanel::draw_highlight_bar
//                              Pnl_lst.cpp:515 (6)
//         00478cd0     SUB        ESP,0x10
//         00478cd3     PUSH       ESI
//         00478cd4     MOV        ESI,this
//                              Pnl_lst.cpp:520 (47)
//         00478cd6     MOV        EAX,dword ptr [ESI + 0x19c]
//         00478cdc     TEST       EAX,EAX
//         00478cde     JZ         LAB_00478eb6
//         00478ce4     MOV        AX,word ptr [ESI + 0x100]
//         00478ceb     CMP        AX,word ptr [ESI + 0xfc]
//         00478cf2     JL         LAB_00478eb6
//         00478cf8     CMP        AX,word ptr [ESI + 0xfe]
//         00478cff     JG         LAB_00478eb6
//                              Pnl_lst.cpp:522 (16)
//         00478d05     MOV        this,dword ptr [ESI + 0x20]
//         00478d08     PUSH       EDI
//         00478d09     PUSH       EBP
//         00478d0a     PUSH       EBX
//         00478d0b     PUSH       s_pnl_lst::draw_highlight_bar                    = "pnl_lst::draw_highlight_bar"
//         00478d10     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
//                              Pnl_lst.cpp:523 (8)
//         00478d15     TEST       EAX,EAX
//         00478d17     JZ         switchD_00478d96::default
//                              Pnl_lst.cpp:525 (31)
//         00478d1d     MOV        this,word ptr [ESI + 0x100]
//         00478d24     LEA        EDX=>r.top,[ESP + 0x10]
//         00478d28     PUSH       0x0
//         00478d2a     PUSH       EDX
//         00478d2b     PUSH       this
//         00478d2c     SUB        this,word ptr [ESI + 0xfc]
//         00478d33     PUSH       this
//         00478d34     PUSH       EAX
//         00478d35     MOV        this,ESI
//         00478d37     CALL       TTextPanel::calc_line_pos                        void calc_line_pos(TTextPanel * this, void *
//                              Pnl_lst.cpp:526 (13)
//         00478d3c     MOV        this,dword ptr [ESI + 0x20]
//         00478d3f     PUSH       s_pnl_lst::draw_highlight_bar                    = "pnl_lst::draw_highlight_bar"
//         00478d44     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
//                              Pnl_lst.cpp:528 (23)
//         00478d49     MOV        this,dword ptr [ESI + 0x20]
//         00478d4c     PUSH       0x1
//         00478d4e     PUSH       s_pnl_lst::draw_highlight_bar                    = "pnl_lst::draw_highlight_bar"
//         00478d53     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         00478d58     TEST       EAX,EAX
//         00478d5a     JZ         switchD_00478d96::default
//                              Pnl_lst.cpp:530 (3)
//         00478d60     MOV        this,dword ptr [ESI + 0xc]
//                              Pnl_lst.cpp:531 (9)
//         00478d63     MOV        EAX,dword ptr [ESI + 0x14]
//         00478d66     MOV        EDX,dword ptr [ESI + 0x180]
//                              Pnl_lst.cpp:534 (27)
//         00478d6c     MOV        EBX,dword ptr [ESP + local_4]
//         00478d70     ADD        EAX,this
//         00478d72     LEA        EDI,[EDX + this->_padding_*0x1]
//         00478d75     MOV        this,dword ptr [ESP + r.right]
//         00478d79     SUB        EAX,EDX
//         00478d7b     MOV        EDX,dword ptr [ESI + 0x184]
//         00478d81     SUB        this,EDX
//         00478d83     DEC        EAX
//         00478d84     LEA        EBP,[EBX + EDX*0x1]
//                              Pnl_lst.cpp:536 (22)
//         00478d87     MOV        EDX,dword ptr [ESI + 0x170]
//         00478d8d     CMP        EDX,0x7
//         00478d90     JA         switchD_00478d96::default
//                               switchD_00478d96::switchD
//         00478d96     JMP        dword ptr [EDX*0x4 + switchD_00478d96::switchd   = 00478d9d
//                               switchD_00478d96::caseD_1                                    XREF[3]:     00478d96(j), 00478ebc(*),
//                               switchD_00478d96::caseD_0                                                 00478ec0(*)
//                              Pnl_lst.cpp:540 (17)
//         00478d9d     PUSH       0xff
//         00478da2     PUSH       EBP
//         00478da3     PUSH       EAX
//         00478da4     PUSH       this
//         00478da5     MOV        this,dword ptr [ESI + 0x20]
//         00478da8     PUSH       EDI
//         00478da9     CALL       TDrawArea::DrawRect                              void DrawRect(TDrawArea * this, long param_1,
//                              Pnl_lst.cpp:541 (5)
//         00478dae     JMP        switchD_00478d96::default
//                               switchD_00478d96::caseD_5                                    XREF[2]:     00478d96(j), 00478ed0(*)
//                              Pnl_lst.cpp:544 (26)
//         00478db3     MOV        DL,byte ptr [ESI + 0x174]
//         00478db9     PUSH       EDX
//         00478dba     MOV        DL,byte ptr [ESI + 0x179]
//         00478dc0     PUSH       EDX
//         00478dc1     PUSH       EBP
//         00478dc2     PUSH       EAX
//         00478dc3     PUSH       this
//         00478dc4     MOV        this,dword ptr [ESI + 0x20]
//         00478dc7     PUSH       EDI
//         00478dc8     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
//                              Pnl_lst.cpp:545 (5)
//         00478dcd     JMP        switchD_00478d96::default
//                               switchD_00478d96::caseD_6                                    XREF[2]:     00478d96(j), 00478ed4(*)
//                              Pnl_lst.cpp:548 (40)
//         00478dd2     MOV        DL,byte ptr [ESI + 0x174]
//         00478dd8     PUSH       EDX
//         00478dd9     MOV        DL,byte ptr [ESI + 0x175]
//         00478ddf     PUSH       EDX
//         00478de0     MOV        DL,byte ptr [ESI + 0x178]
//         00478de6     PUSH       EDX
//         00478de7     MOV        DL,byte ptr [ESI + 0x179]
//         00478ded     PUSH       EDX
//         00478dee     PUSH       EBP
//         00478def     PUSH       EAX
//         00478df0     PUSH       this
//         00478df1     MOV        this,dword ptr [ESI + 0x20]
//         00478df4     PUSH       EDI
//         00478df5     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
//                              Pnl_lst.cpp:549 (5)
//         00478dfa     JMP        switchD_00478d96::default
//                               switchD_00478d96::caseD_7                                    XREF[2]:     00478d96(j), 00478ed8(*)
//                              Pnl_lst.cpp:552 (41)
//         00478dff     MOV        DL,byte ptr [ESI + 0x174]
//         00478e05     PUSH       EDX
//         00478e06     MOV        DL,byte ptr [ESI + 0x175]
//         00478e0c     PUSH       EDX
//         00478e0d     MOV        DL,byte ptr [ESI + 0x176]
//         00478e13     PUSH       EDX
//         00478e14     MOV        DL,byte ptr [ESI + 0x177]
//         00478e1a     PUSH       EDX
//         00478e1b     MOV        DL,byte ptr [ESI + 0x178]
//         00478e21     PUSH       EDX
//         00478e22     MOV        DL,byte ptr [ESI + 0x179]
//                              Pnl_lst.cpp:553 (2)
//         00478e28     JMP        LAB_00478e99
//                               switchD_00478d96::caseD_2                                    XREF[2]:     00478d96(j), 00478ec4(*)
//                              Pnl_lst.cpp:556 (26)
//         00478e2a     MOV        DL,byte ptr [ESI + 0x179]
//         00478e30     PUSH       EDX
//         00478e31     MOV        DL,byte ptr [ESI + 0x174]
//         00478e37     PUSH       EDX
//         00478e38     PUSH       EBP
//         00478e39     PUSH       EAX
//         00478e3a     PUSH       this
//         00478e3b     MOV        this,dword ptr [ESI + 0x20]
//         00478e3e     PUSH       EDI
//         00478e3f     CALL       TDrawArea::DrawBevel                             void DrawBevel(TDrawArea * this, long param_1
//                              Pnl_lst.cpp:557 (2)
//         00478e44     JMP        switchD_00478d96::default
//                               switchD_00478d96::caseD_3                                    XREF[2]:     00478d96(j), 00478ec8(*)
//                              Pnl_lst.cpp:560 (40)
//         00478e46     MOV        DL,byte ptr [ESI + 0x179]
//         00478e4c     PUSH       EDX
//         00478e4d     MOV        DL,byte ptr [ESI + 0x178]
//         00478e53     PUSH       EDX
//         00478e54     MOV        DL,byte ptr [ESI + 0x175]
//         00478e5a     PUSH       EDX
//         00478e5b     MOV        DL,byte ptr [ESI + 0x174]
//         00478e61     PUSH       EDX
//         00478e62     PUSH       EBP
//         00478e63     PUSH       EAX
//         00478e64     PUSH       this
//         00478e65     MOV        this,dword ptr [ESI + 0x20]
//         00478e68     PUSH       EDI
//         00478e69     CALL       TDrawArea::DrawBevel2                            void DrawBevel2(TDrawArea * this, long param_
//                              Pnl_lst.cpp:561 (2)
//         00478e6e     JMP        switchD_00478d96::default
//                               switchD_00478d96::caseD_4                                    XREF[2]:     00478d96(j), 00478ecc(*)
//                              Pnl_lst.cpp:564 (54)
//         00478e70     MOV        DL,byte ptr [ESI + 0x179]
//         00478e76     PUSH       EDX
//         00478e77     MOV        DL,byte ptr [ESI + 0x178]
//         00478e7d     PUSH       EDX
//         00478e7e     MOV        DL,byte ptr [ESI + 0x177]
//         00478e84     PUSH       EDX
//         00478e85     MOV        DL,byte ptr [ESI + 0x176]
//         00478e8b     PUSH       EDX
//         00478e8c     MOV        DL,byte ptr [ESI + 0x175]
//         00478e92     PUSH       EDX
//         00478e93     MOV        DL,byte ptr [ESI + 0x174]
//                               LAB_00478e99                                                 XREF[1]:     00478e28(j)
//         00478e99     PUSH       EDX
//         00478e9a     PUSH       EBP
//         00478e9b     PUSH       EAX
//         00478e9c     PUSH       this
//         00478e9d     MOV        this,dword ptr [ESI + 0x20]
//         00478ea0     PUSH       EDI
//         00478ea1     CALL       TDrawArea::DrawBevel3                            void DrawBevel3(TDrawArea * this, long param_
//                               switchD_00478d96::default                                    XREF[8]:     00478d17(j), 00478d5a(j),
//                                                                                                         00478d90(j), 00478dae(j),
//                                                                                                         00478dcd(j), 00478dfa(j),
//                                                                                                         00478e44(j), 00478e6e(j)
//                              Pnl_lst.cpp:570 (16)
//         00478ea6     MOV        this,dword ptr [ESI + 0x20]
//         00478ea9     PUSH       s_pnl_lst::draw_highlight_bar                    = "pnl_lst::draw_highlight_bar"
//         00478eae     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//         00478eb3     POP        EBX
//         00478eb4     POP        EBP
//         00478eb5     POP        EDI
//                               LAB_00478eb6                                                 XREF[3]:     00478cde(j), 00478cf2(j),
//                                                                                                         00478cff(j)
//                              Pnl_lst.cpp:572 (38)
//         00478eb6     POP        ESI
//         00478eb7     ADD        ESP,0x10
//         00478eba     RET
//         00478ebb     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_00478d96::switchdataD_00478ebc                       XREF[1]:     draw_highlight_bar:00478d96(*)
//         00478ebc     addr       switchD_00478d96::caseD_0
//         00478ec0     addr       switchD_00478d96::caseD_0
//         00478ec4     addr       switchD_00478d96::caseD_2
//         00478ec8     addr       switchD_00478d96::caseD_3
//         00478ecc     addr       switchD_00478d96::caseD_4
//         00478ed0     addr       switchD_00478d96::caseD_5
//         00478ed4     addr       switchD_00478d96::caseD_6
//         00478ed8     addr       switchD_00478d96::caseD_7
//         00478edc     ??         90h
//         00478edd     ??         90h
//         00478ede     ??         90h
//         00478edf     ??         90h
    return;
}

void TListPanel::setDrawHighlightBar(int param_1) {
    /* TODO: Stub */
//                              void __thiscall setDrawHighlightBar(TListPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00478ee0(R)
//                               ?setDrawHighlightBar@TListPanel@@QAEXH@Z                     XREF[1]:     TribeGameSettingsScreen:004b551c(c
//                               TListPanel::setDrawHighlightBar
//                              Pnl_lst.cpp:577 (10)
//         00478ee0     MOV        EAX,dword ptr [ESP + param_1]
//         00478ee4     MOV        dword ptr [ECX + this->drawHighlightBar],EAX
//                              Pnl_lst.cpp:579 (3)
//         00478eea     RET        0x4
//         00478eed     ??         90h
//         00478eee     NOP
//         00478eef     NOP
    return;
}

void TListPanel::set_focus(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_focus(TListPanel * this, int param_1)
//              void              <VOID>         <RETURN>
//              TListPanel *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00478ef0(R)
//                               ?set_focus@TListPanel@@UAEXH@Z                               XREF[1]:     00571638(*)
//                               TListPanel::set_focus
//                              Pnl_lst.cpp:585 (13)
//         00478ef0     MOV        EAX,dword ptr [ESP + param_1]
//         00478ef4     PUSH       ESI
//         00478ef5     MOV        ESI,this
//         00478ef7     PUSH       EAX
//         00478ef8     CALL       TPanel::set_focus                                void set_focus(TPanel * this, int param_1)
//                              Pnl_lst.cpp:588 (7)
//         00478efd     MOV        EAX,dword ptr [ESI + 0x78]
//         00478f00     TEST       EAX,EAX
//         00478f02     JZ         LAB_00478f32
//                              Pnl_lst.cpp:590 (29)
//         00478f04     MOV        this,dword ptr [ESI + 0x40]
//         00478f07     TEST       this,this
//         00478f09     JZ         LAB_00478f32
//         00478f0b     MOV        AX,word ptr [ESI + 0x100]
//         00478f12     CMP        AX,0xffff
//         00478f16     JLE        LAB_00478f32
//         00478f18     CMP        AX,word ptr [ESI + 0xf8]
//         00478f1f     JGE        LAB_00478f32
//                              Pnl_lst.cpp:591 (17)
//         00478f21     MOV        EDX,dword ptr [this->_padding_]
//         00478f23     PUSH       0x0
//         00478f25     MOVSX      EAX,AX
//         00478f28     PUSH       EAX
//         00478f29     PUSH       0x1
//         00478f2b     PUSH       ESI
//         00478f2c     CALL       dword ptr [EDX + 0xb4]
//                               LAB_00478f32                                                 XREF[4]:     00478f02(j), 00478f09(j),
//                                                                                                         00478f16(j), 00478f1f(j)
//                              Pnl_lst.cpp:593 (4)
//         00478f32     POP        ESI
//         00478f33     RET        0x4
//         00478f36     ??         90h
//         00478f37     NOP
//         00478f38     NOP
//         00478f39     NOP
//         00478f3a     NOP
//         00478f3b     NOP
//         00478f3c     NOP
//         00478f3d     NOP
//         00478f3e     NOP
//         00478f3f     NOP
    return;
}

