#include "../common.h"
#include "view.h"

RGE_View::RGE_View() {
    /* TODO: Stub */
//                              undefined __thiscall RGE_View(RGE_View * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0053362d(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00533717(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0053352a(W)
//                               ??0RGE_View@@QAE@XZ                                          XREF[1]:     RGE_Main_View:0053dab3(c)
//                               RGE_View::RGE_View
//                              view.cpp:276 (43)
//         00533510     PUSH       -0x1
//         00533512     PUSH       FUN_00561b08
//         00533517     MOV        EAX,FS:[0x0]
//         0053351d     PUSH       EAX
//         0053351e     MOV        dword ptr FS:[0x0],ESP
//         00533525     PUSH       this
//         00533526     PUSH       EBX
//         00533527     PUSH       ESI
//         00533528     MOV        ESI,this
//         0053352a     MOV        dword ptr [ESP + local_10],ESI
//         0053352e     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
//         00533533     XOR        EBX,EBX
//         00533535     MOV        dword ptr [ESI],RGE_View::`vftable'              = 00533740
//                              view.cpp:277 (6)
//         0053353b     MOV        dword ptr [ESI + 0xf4],EBX
//                              view.cpp:279 (6)
//         00533541     MOV        dword ptr [ESI + 0xf8],EBX
//                              view.cpp:281 (6)
//         00533547     MOV        dword ptr [ESI + 0xfc],EBX
//                              view.cpp:282 (6)
//         0053354d     MOV        dword ptr [ESI + 0x100],EBX
//                              view.cpp:284 (6)
//         00533553     MOV        dword ptr [ESI + 0x104],EBX
//                              view.cpp:286 (7)
//         00533559     MOV        word ptr [ESI + 0x108],BX
//                              view.cpp:287 (7)
//         00533560     MOV        word ptr [ESI + 0x10a],BX
//                              view.cpp:288 (7)
//         00533567     MOV        word ptr [ESI + 0x10e],BX
//                              view.cpp:289 (7)
//         0053356e     MOV        word ptr [ESI + 0x10c],BX
//                              view.cpp:290 (7)
//         00533575     MOV        word ptr [ESI + 0x110],BX
//                              view.cpp:292 (7)
//         0053357c     MOV        word ptr [ESI + 0x116],BX
//                              view.cpp:293 (7)
//         00533583     MOV        word ptr [ESI + 0x118],BX
//                              view.cpp:294 (7)
//         0053358a     MOV        word ptr [ESI + 0x11a],BX
//                              view.cpp:295 (7)
//         00533591     MOV        word ptr [ESI + 0x11c],BX
//                              view.cpp:296 (7)
//         00533598     MOV        word ptr [ESI + 0x11e],BX
//                              view.cpp:297 (7)
//         0053359f     MOV        word ptr [ESI + 0x120],BX
//                              view.cpp:298 (7)
//         005335a6     MOV        word ptr [ESI + 0x122],BX
//                              view.cpp:299 (7)
//         005335ad     MOV        word ptr [ESI + 0x124],BX
//                              view.cpp:300 (7)
//         005335b4     MOV        word ptr [ESI + 0x126],BX
//                              view.cpp:301 (7)
//         005335bb     MOV        word ptr [ESI + 0x128],BX
//                              view.cpp:302 (7)
//         005335c2     MOV        word ptr [ESI + 0x12a],BX
//                              view.cpp:303 (7)
//         005335c9     MOV        word ptr [ESI + 0x12c],BX
//                              view.cpp:305 (6)
//         005335d0     MOV        dword ptr [ESI + 0x130],EBX
//                              view.cpp:308 (17)
//         005335d6     MOV        EAX,0xc61c3c00
//         005335db     MOV        dword ptr [ESI + 0x134],EBX
//         005335e1     MOV        dword ptr [ESI + 0x138],EAX
//                              view.cpp:309 (6)
//         005335e7     MOV        dword ptr [ESI + 0x13c],EAX
//                              view.cpp:311 (6)
//         005335ed     MOV        byte ptr [ESI + 0x140],BL
//                              view.cpp:312 (6)
//         005335f3     MOV        byte ptr [ESI + 0x142],BL
//                              view.cpp:316 (16)
//         005335f9     OR         EAX,0xffffffff
//         005335fc     MOV        dword ptr [ESI + 0x324],EBX
//         00533602     MOV        word ptr [ESI + 0x154],AX
//                              view.cpp:318 (6)
//         00533609     MOV        dword ptr [ESI + 0x158],EBX
//                              view.cpp:319 (6)
//         0053360f     MOV        dword ptr [ESI + 0x15c],EBX
//                              view.cpp:328 (51)
//         00533615     PUSH       EAX
//         00533616     MOV        dword ptr [ESI + 0x160],EBX
//         0053361c     PUSH       EAX
//         0053361d     MOV        dword ptr [ESI + 0x164],EBX
//         00533623     PUSH       EAX
//         00533624     MOV        byte ptr [ESI + 0x168],BL
//         0053362a     PUSH       EAX
//         0053362b     MOV        this,ESI
//         0053362d     MOV        dword ptr [ESP + local_4],EBX
//         00533631     MOV        dword ptr [ESI + 0x16c],EAX
//         00533637     MOV        dword ptr [ESI + 0x170],EAX
//         0053363d     MOV        dword ptr [ESI + 0x174],EBX
//         00533643     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              view.cpp:332 (6)
//         00533648     MOV        dword ptr [ESI + 0x178],EBX
//                              view.cpp:333 (6)
//         0053364e     MOV        dword ptr [ESI + 0x17c],EBX
//                              view.cpp:334 (6)
//         00533654     MOV        dword ptr [ESI + 0x180],EBX
//                              view.cpp:338 (6)
//         0053365a     MOV        dword ptr [ESI + 0x328],EBX
//                              view.cpp:339 (6)
//         00533660     MOV        dword ptr [ESI + 0x32c],EBX
//                              view.cpp:340 (6)
//         00533666     MOV        dword ptr [ESI + 0x330],EBX
//                              view.cpp:344 (6)
//         0053366c     MOV        dword ptr [ESI + 0x184],EBX
//                              view.cpp:345 (6)
//         00533672     MOV        dword ptr [ESI + 0x188],EBX
//                              view.cpp:349 (6)
//         00533678     MOV        dword ptr [ESI + 0x2d0],EBX
//                              view.cpp:350 (6)
//         0053367e     MOV        dword ptr [ESI + 0x2d4],EBX
//                              view.cpp:352 (6)
//         00533684     MOV        dword ptr [ESI + 0x2c8],EBX
//                              view.cpp:353 (6)
//         0053368a     MOV        dword ptr [ESI + 0x2cc],EBX
//                              view.cpp:357 (6)
//         00533690     MOV        dword ptr [ESI + 0x2d8],EBX
//                              view.cpp:358 (6)
//         00533696     MOV        dword ptr [ESI + 0x2dc],EBX
//                              view.cpp:359 (6)
//         0053369c     MOV        dword ptr [ESI + 0x2e0],EBX
//                              view.cpp:360 (6)
//         005336a2     MOV        dword ptr [ESI + 0x2e8],EBX
//                              view.cpp:361 (6)
//         005336a8     MOV        dword ptr [ESI + 0x2ec],EBX
//                              view.cpp:362 (6)
//         005336ae     MOV        dword ptr [ESI + 0x2f0],EBX
//                              view.cpp:366 (6)
//         005336b4     MOV        dword ptr [ESI + 0x334],EBX
//                              view.cpp:367 (17)
//         005336ba     MOV        dword ptr [ESI + 0x338],EBX
//         005336c0     LEA        EAX,[ESI + 0x310]
//         005336c6     MOV        this,0x5
//                               LAB_005336cb                                                 XREF[1]:     005336d4(j)
//                              view.cpp:373 (3)
//         005336cb     MOV        dword ptr [EAX + -0x14],EBX
//                              view.cpp:374 (8)
//         005336ce     MOV        dword ptr [EAX],EBX
//         005336d0     ADD        EAX,0x4
//         005336d3     DEC        this
//         005336d4     JNZ        LAB_005336cb
//                              view.cpp:393 (65)
//         005336d6     PUSH       0x14
//         005336d8     PUSH       0x8
//         005336da     MOV        dword ptr [ESI + 0x33c],EBX
//         005336e0     MOV        dword ptr [ESI + 0x340],0x80000000
//         005336ea     MOV        dword ptr [ESI + 0x344],EBX
//         005336f0     MOV        dword ptr [ESI + 0x348],EBX
//         005336f6     MOV        dword ptr [ESI + 0x34c],EBX
//         005336fc     MOV        dword ptr [ESI + 0x350],EBX
//         00533702     MOV        dword ptr [ESI + 0x358],EBX
//         00533708     MOV        dword ptr [ESI + 0x35c],0x8
//         00533712     CALL       calloc                                           undefined calloc()
//                              view.cpp:402 (28)
//         00533717     MOV        this,dword ptr [ESP + local_c]
//         0053371b     ADD        ESP,0x8
//         0053371e     MOV        dword ptr [ESI + 0x354],EAX
//         00533724     MOV        EAX,ESI
//         00533726     POP        ESI
//         00533727     MOV        dword ptr FS:[0x0],this
//         0053372e     POP        EBX
//         0053372f     ADD        ESP,0x10
//         00533732     RET
//         00533733     ??         90h
//         00533734     NOP
//         00533735     NOP
//         00533736     NOP
//         00533737     NOP
//         00533738     NOP
//         00533739     NOP
//         0053373a     NOP
//         0053373b     NOP
//         0053373c     NOP
//         0053373d     NOP
//         0053373e     NOP
//         0053373f     NOP
}

RGE_View::~RGE_View() {
    /* TODO: Stub */
//                              void __thiscall ~RGE_View(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0053378b(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0053377b(W)
//                               ??1RGE_View@@UAE@XZ                                          XREF[3]:     ~RGE_View:0049548e(T),
//                               RGE_View::~RGE_View                                                       ~TRIBE_Main_View:00495490(j),
//                                                                                                         `vector_deleting_destructor':00533
//                                                                                                         ~RGE_View:0053db2e(T),
//                                                                                                         ~RGE_Main_View:0053db30(j)
//                              view.cpp:408 (37)
//         00533760     PUSH       -0x1
//         00533762     PUSH       FUN_00561b28
//         00533767     MOV        EAX,FS:[0x0]
//         0053376d     PUSH       EAX
//         0053376e     MOV        dword ptr FS:[0x0],ESP
//         00533775     PUSH       this
//         00533776     PUSH       EBX
//         00533777     PUSH       ESI
//         00533778     MOV        ESI,this
//         0053377a     PUSH       EDI
//         0053377b     MOV        dword ptr [ESP + local_10],ESI
//         0053377f     MOV        dword ptr [ESI],RGE_View::`vftable'              = 00533740
//                              view.cpp:409 (18)
//         00533785     MOV        EDI,dword ptr [ESI + 0x164]
//         0053378b     MOV        dword ptr [ESP + local_4],0x0
//         00533793     TEST       EDI,EDI
//         00533795     JZ         LAB_005337b1
//                              view.cpp:411 (16)
//         00533797     MOV        this,EDI
//         00533799     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
//         0053379e     PUSH       EDI
//         0053379f     CALL       operator_delete                                  void operator_delete(void * param_1)
//         005337a4     ADD        ESP,0x4
//                              view.cpp:412 (10)
//         005337a7     MOV        dword ptr [ESI + 0x164],0x0
//                               LAB_005337b1                                                 XREF[1]:     00533795(j)
//                              view.cpp:415 (7)
//         005337b1     MOV        this,ESI
//         005337b3     CALL       RGE_View::delete_surfaces                        void delete_surfaces(RGE_View * this)
//                              view.cpp:417 (10)
//         005337b8     MOV        EAX,dword ptr [ESI + 0x15c]
//         005337be     TEST       EAX,EAX
//         005337c0     JZ         LAB_005337d3
//                              view.cpp:419 (7)
//         005337c2     PUSH       EAX
//         005337c3     CALL       dword ptr [->GDI32.DLL::DeleteObject]            = 0048b160
//                              view.cpp:420 (10)
//         005337c9     MOV        dword ptr [ESI + 0x15c],0x0
//                               LAB_005337d3                                                 XREF[1]:     005337c0(j)
//                              view.cpp:425 (19)
//         005337d3     MOV        EAX,dword ptr [ESI + 0x32c]
//         005337d9     TEST       EAX,EAX
//         005337db     JZ         LAB_005337e6
//         005337dd     PUSH       EAX
//         005337de     CALL       free                                             undefined free()
//         005337e3     ADD        ESP,0x4
//                               LAB_005337e6                                                 XREF[1]:     005337db(j)
//                              view.cpp:429 (26)
//         005337e6     MOV        EDI,dword ptr [ESI + 0x178]
//         005337ec     TEST       EDI,EDI
//         005337ee     JZ         LAB_00533800
//         005337f0     MOV        this,EDI
//         005337f2     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
//         005337f7     PUSH       EDI
//         005337f8     CALL       operator_delete                                  void operator_delete(void * param_1)
//         005337fd     ADD        ESP,0x4
//                               LAB_00533800                                                 XREF[1]:     005337ee(j)
//                              view.cpp:430 (26)
//         00533800     MOV        EDI,dword ptr [ESI + 0x17c]
//         00533806     TEST       EDI,EDI
//         00533808     JZ         LAB_0053381a
//         0053380a     MOV        this,EDI
//         0053380c     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
//         00533811     PUSH       EDI
//         00533812     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00533817     ADD        ESP,0x4
//                               LAB_0053381a                                                 XREF[1]:     00533808(j)
//                              view.cpp:431 (26)
//         0053381a     MOV        EDI,dword ptr [ESI + 0x180]
//         00533820     TEST       EDI,EDI
//         00533822     JZ         LAB_00533834
//         00533824     MOV        this,EDI
//         00533826     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
//         0053382b     PUSH       EDI
//         0053382c     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00533831     ADD        ESP,0x4
//                               LAB_00533834                                                 XREF[1]:     00533822(j)
//                              view.cpp:433 (19)
//         00533834     MOV        EAX,dword ptr [ESI + 0x184]
//         0053383a     TEST       EAX,EAX
//         0053383c     JZ         LAB_00533847
//         0053383e     PUSH       EAX
//         0053383f     CALL       free                                             undefined free()
//         00533844     ADD        ESP,0x4
//                               LAB_00533847                                                 XREF[1]:     0053383c(j)
//                              view.cpp:434 (19)
//         00533847     MOV        EAX,dword ptr [ESI + 0x188]
//         0053384d     TEST       EAX,EAX
//         0053384f     JZ         LAB_0053385a
//         00533851     PUSH       EAX
//         00533852     CALL       free                                             undefined free()
//         00533857     ADD        ESP,0x4
//                               LAB_0053385a                                                 XREF[1]:     0053384f(j)
//                              view.cpp:438 (19)
//         0053385a     MOV        EAX,dword ptr [ESI + 0x2c8]
//         00533860     TEST       EAX,EAX
//         00533862     JZ         LAB_0053386d
//         00533864     PUSH       EAX
//         00533865     CALL       free                                             undefined free()
//         0053386a     ADD        ESP,0x4
//                               LAB_0053386d                                                 XREF[1]:     00533862(j)
//                              view.cpp:442 (19)
//         0053386d     MOV        EAX,dword ptr [ESI + 0x2dc]
//         00533873     TEST       EAX,EAX
//         00533875     JZ         LAB_00533880
//         00533877     PUSH       EAX
//         00533878     CALL       free                                             undefined free()
//         0053387d     ADD        ESP,0x4
//                               LAB_00533880                                                 XREF[1]:     00533875(j)
//                              view.cpp:446 (26)
//         00533880     MOV        EDI,dword ptr [ESI + 0x334]
//         00533886     TEST       EDI,EDI
//         00533888     JZ         LAB_0053389a
//         0053388a     MOV        this,EDI
//         0053388c     CALL       DClipInfo_List::~DClipInfo_List                  void ~DClipInfo_List(DClipInfo_List * this)
//         00533891     PUSH       EDI
//         00533892     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00533897     ADD        ESP,0x4
//                               LAB_0053389a                                                 XREF[1]:     00533888(j)
//                              view.cpp:447 (26)
//         0053389a     MOV        EDI,dword ptr [ESI + 0x338]
//         005338a0     TEST       EDI,EDI
//         005338a2     JZ         LAB_005338b4
//         005338a4     MOV        this,EDI
//         005338a6     CALL       DClipInfo_List::~DClipInfo_List                  void ~DClipInfo_List(DClipInfo_List * this)
//         005338ab     PUSH       EDI
//         005338ac     CALL       operator_delete                                  void operator_delete(void * param_1)
//         005338b1     ADD        ESP,0x4
//                               LAB_005338b4                                                 XREF[1]:     005338a2(j)
//                              view.cpp:451 (11)
//         005338b4     LEA        EDI,[ESI + 0x2fc]
//         005338ba     MOV        EBX,0x5
//                               LAB_005338bf                                                 XREF[1]:     005338d2(j)
//                              view.cpp:452 (21)
//         005338bf     MOV        EAX,dword ptr [EDI]
//         005338c1     TEST       EAX,EAX
//         005338c3     JZ         LAB_005338ce
//         005338c5     PUSH       EAX
//         005338c6     CALL       free                                             undefined free()
//         005338cb     ADD        ESP,0x4
//                               LAB_005338ce                                                 XREF[1]:     005338c3(j)
//         005338ce     ADD        EDI,0x4
//         005338d1     DEC        EBX
//         005338d2     JNZ        LAB_005338bf
//                              view.cpp:456 (10)
//         005338d4     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         005338da     TEST       this,this
//         005338dc     JZ         LAB_005338f2
//                              view.cpp:458 (7)
//         005338de     PUSH       0x0
//         005338e0     CALL       TMousePointer::set_game_mode                     void set_game_mode(TMousePointer * this, int
//                              view.cpp:459 (13)
//         005338e5     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         005338eb     PUSH       0x0
//         005338ed     CALL       TMousePointer::set_game_enable                   void set_game_enable(TMousePointer * this, in
//                               LAB_005338f2                                                 XREF[1]:     005338dc(j)
//                              view.cpp:464 (19)
//         005338f2     MOV        EAX,dword ptr [ESI + 0x354]
//         005338f8     TEST       EAX,EAX
//         005338fa     JZ         LAB_00533905
//         005338fc     PUSH       EAX
//         005338fd     CALL       free                                             undefined free()
//         00533902     ADD        ESP,0x4
//                               LAB_00533905                                                 XREF[1]:     005338fa(j)
//                              view.cpp:468 (7)
//         00533905     MOV        this,ESI
//         00533907     CALL       RGE_View::reset_overlay_sprites                  void reset_overlay_sprites(RGE_View * this)
//                              view.cpp:476 (9)
//         0053390c     MOV        this,ESI
//         0053390e     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
//         00533913     MOV        this,ESI
//                              view.cpp:477 (31)
//         00533915     MOV        dword ptr [ESP + 0x18],0xffffffff
//         0053391d     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
//         00533922     MOV        this,dword ptr [ESP + 0x10]
//         00533926     POP        EDI
//         00533927     POP        ESI
//         00533928     MOV        dword ptr FS:[0x0],this
//         0053392f     POP        EBX
//         00533930     ADD        ESP,0x10
//         00533933     RET
//         00533934     ??         90h
//         00533935     NOP
//         00533936     NOP
//         00533937     NOP
//         00533938     NOP
//         00533939     NOP
//         0053393a     NOP
//         0053393b     NOP
//         0053393c     NOP
//         0053393d     NOP
//         0053393e     NOP
//         0053393f     NOP
}

long RGE_View::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7, int param_8, char* param_9) {
    /* TODO: Stub */
//                              long __thiscall setup(RGE_View * this, TDrawArea * param_1, TPanel *
//              long              EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0053398e(R)
//              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     00533986(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0053397e(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00533976(R)
//              long              Stack[0x14]:4  param_5                   XREF[1]:     00533962(R)
//              long              Stack[0x18]:4  param_6                   XREF[1]:     0053396e(R)
//              uchar             Stack[0x1c]:1  param_7                   XREF[1]:     0053395b(R)
//              int               Stack[0x20]:4  param_8                   XREF[1]:     0053399f(R)
//              char *            Stack[0x24]:4  param_9
//              char[260]         Stack[-0x114   str
//                               ?setup@RGE_View@@QAEJPAVTDrawArea@@PAVTPanel@@JJJJEHPAD@Z    XREF[2]:     TRIBE_Screen_Game:004942ed(c),
//                               RGE_View::setup                                                           TRIBE_Screen_Sed:004a8419(c)
//                              view.cpp:488 (27)
//         00533940     PUSH       -0x1
//         00533942     PUSH       FUN_00561b4e
//         00533947     MOV        EAX,FS:[0x0]
//         0053394d     PUSH       EAX
//         0053394e     MOV        dword ptr FS:[0x0],ESP
//         00533955     SUB        ESP,0x108
//                              view.cpp:491 (68)
//         0053395b     MOV        EAX,dword ptr [ESP + param_7]
//         00533962     MOV        EDX,dword ptr [ESP + param_5]
//         00533969     PUSH       EBX
//         0053396a     PUSH       ESI
//         0053396b     MOV        ESI,this
//         0053396d     PUSH       EDI
//         0053396e     MOV        this,dword ptr [ESP + param_6]
//         00533975     PUSH       EAX
//         00533976     MOV        EAX,dword ptr [ESP + param_4]
//         0053397d     PUSH       this
//         0053397e     MOV        this,dword ptr [ESP + param_3]
//         00533985     PUSH       EDX
//         00533986     MOV        EDX,dword ptr [ESP + param_2]
//         0053398d     PUSH       EAX
//         0053398e     MOV        EAX,dword ptr [ESP + param_1]
//         00533995     PUSH       this
//         00533996     PUSH       EDX
//         00533997     PUSH       EAX
//         00533998     MOV        this,ESI
//         0053399a     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
//                              view.cpp:495 (7)
//         0053399f     MOV        this,dword ptr [ESP + param_8]
//                              view.cpp:507 (75)
//         005339a6     MOV        EDI,dword ptr [->GDI32.DLL::GetStockObject]      = 0048b1b8
//         005339ac     XOR        EBX,EBX
//         005339ae     MOV        EAX,0xc61c3c00
//         005339b3     PUSH       0x6
//         005339b5     MOV        dword ptr [ESI + 0xf4],EBX
//         005339bb     MOV        dword ptr [ESI + 0xf8],this
//         005339c1     MOV        word ptr [ESI + 0x126],BX
//         005339c8     MOV        word ptr [ESI + 0x128],BX
//         005339cf     MOV        word ptr [ESI + 0x12a],BX
//         005339d6     MOV        word ptr [ESI + 0x12c],BX
//         005339dd     MOV        dword ptr [ESI + 0x138],EAX
//         005339e3     MOV        dword ptr [ESI + 0x13c],EAX
//         005339e9     MOV        byte ptr [ESI + 0x140],BL
//         005339ef     CALL       EDI=>GDI32.DLL::GetStockObject
//                              view.cpp:508 (20)
//         005339f1     PUSH       0xff
//         005339f6     PUSH       0x1
//         005339f8     PUSH       EBX
//         005339f9     MOV        dword ptr [ESI + 0x158],EAX
//         005339ff     CALL       dword ptr [->GDI32.DLL::CreatePen]               = 0048b370
//                              view.cpp:509 (10)
//         00533a05     PUSH       0x5
//         00533a07     MOV        dword ptr [ESI + 0x15c],EAX
//         00533a0d     CALL       EDI=>GDI32.DLL::GetStockObject
//                              view.cpp:511 (32)
//         00533a0f     MOV        EDX,dword ptr [ESP + 0x144]
//         00533a16     MOV        dword ptr [ESI + 0x160],EAX
//         00533a1c     PUSH       EDX
//         00533a1d     LEA        EAX,[ESP + 0x14]
//         00533a21     PUSH       s_%s.shp                                         = "%s.shp"
//         00533a26     PUSH       EAX
//         00533a27     CALL       sprintf                                          undefined sprintf()
//         00533a2c     ADD        ESP,0xc
//                              view.cpp:512 (43)
//         00533a2f     PUSH       0x20
//         00533a31     CALL       operator_new                                     void * operator_new(uint param_1)
//         00533a36     ADD        ESP,0x4
//         00533a39     MOV        dword ptr [ESP + 0xc],EAX
//         00533a3d     CMP        EAX,EBX
//         00533a3f     MOV        dword ptr [ESP + 0x11c],EBX
//         00533a46     JZ         LAB_00533a58
//         00533a48     LEA        this,[ESP + 0x10]
//         00533a4c     PUSH       -0x1
//         00533a4e     PUSH       this
//         00533a4f     MOV        this,EAX
//         00533a51     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
//         00533a56     JMP        LAB_00533a5a
//                               LAB_00533a58                                                 XREF[1]:     00533a46(j)
//         00533a58     XOR        EAX,EAX
//                               LAB_00533a5a                                                 XREF[1]:     00533a56(j)
//                              view.cpp:515 (35)
//         00533a5a     MOV        this,ESI
//         00533a5c     MOV        dword ptr [ESP + 0x11c],0xffffffff
//         00533a67     MOV        dword ptr [ESI + 0x164],EAX
//         00533a6d     CALL       RGE_View::Init_Tile_Edge_Tables                  void Init_Tile_Edge_Tables(RGE_View * this)
//         00533a72     ADD        ESI,0x310
//         00533a78     MOV        EDI,0x5
//                               LAB_00533a7d                                                 XREF[1]:     00533a92(j)
//                              view.cpp:521 (12)
//         00533a7d     PUSH       0x14
//         00533a7f     PUSH       0x40
//         00533a81     CALL       calloc                                           undefined calloc()
//         00533a86     MOV        dword ptr [ESI + -0x14],EAX
//                              view.cpp:522 (11)
//         00533a89     MOV        dword ptr [ESI],EBX
//         00533a8b     ADD        ESP,0x8
//         00533a8e     ADD        ESI,0x4
//         00533a91     DEC        EDI
//         00533a92     JNZ        LAB_00533a7d
//                              view.cpp:526 (31)
//         00533a94     MOV        this,dword ptr [ESP + 0x114]
//         00533a9b     POP        EDI
//         00533a9c     POP        ESI
//         00533a9d     MOV        EAX,0x1
//         00533aa2     MOV        dword ptr FS:[0x0],this
//         00533aa9     POP        EBX
//         00533aaa     ADD        ESP,0x114
//         00533ab0     RET        0x24
//         00533ab3     ??         90h
//         00533ab4     NOP
//         00533ab5     NOP
//         00533ab6     NOP
//         00533ab7     NOP
//         00533ab8     NOP
//         00533ab9     NOP
//         00533aba     NOP
//         00533abb     NOP
//         00533abc     NOP
//         00533abd     NOP
//         00533abe     NOP
//         00533abf     NOP
    return 0;
}

void RGE_View::set_focus(int param_1) {
    /* TODO: Stub */
//                              void __thiscall set_focus(RGE_View * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00533ac0(R)
//                               ?set_focus@RGE_View@@MAEXH@Z                                 XREF[3]:     00572b68(*), 00577678(*),
//                               RGE_View::set_focus                                                       005778b0(*)
//                              view.cpp:531 (13)
//         00533ac0     MOV        EAX,dword ptr [ESP + param_1]
//         00533ac4     PUSH       ESI
//         00533ac5     MOV        ESI,this
//         00533ac7     PUSH       EAX
//         00533ac8     CALL       TPanel::set_focus                                void set_focus(TPanel * this, int param_1)
//                              view.cpp:534 (10)
//         00533acd     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00533ad3     TEST       this,this
//         00533ad5     JZ         LAB_00533ae0
//                              view.cpp:536 (9)
//         00533ad7     MOV        EDX,dword ptr [ESI + 0x78]
//         00533ada     PUSH       EDX
//         00533adb     CALL       TMousePointer::set_game_enable                   void set_game_enable(TMousePointer * this, in
//                               LAB_00533ae0                                                 XREF[1]:     00533ad5(j)
//                              view.cpp:545 (4)
//         00533ae0     POP        ESI
//         00533ae1     RET        0x4
//         00533ae4     ??         90h
//         00533ae5     NOP
//         00533ae6     NOP
//         00533ae7     NOP
//         00533ae8     NOP
//         00533ae9     NOP
//         00533aea     NOP
//         00533aeb     NOP
//         00533aec     NOP
//         00533aed     NOP
//         00533aee     NOP
//         00533aef     NOP
    return;
}

void RGE_View::Init_Tile_Edge_Tables() {
    /* TODO: Stub */
//                              void __thiscall Init_Tile_Edge_Tables(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00533c7f(W), 00533de9(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[4]:     00533cd7(W), 00533d38(R), 00533dad(W), 00533dd7(R)
//              int               Stack[-0xc]:4  B4                        XREF[2]:     00533ce8(W), 00533d22(R)
//              int               Stack[-0x10]:4 B5                        XREF[6]:     00533c83(W), 00533d56(R), 00533d5e(W), 00533d90(W),
//                                                                                     00533dbf(R), 00533ddd(R)
//              int               Stack[-0x14]:4 y                         XREF[6]:     00533caa(W), 00533d2a(R), 00533d48(R), 00533d83(W),
//                                                                                     00533dcb(R), 00533de3(R)
//              int               Stack[-0x18]:4 A4                        XREF[3]:     00533c9c(W), 00533d06(R), 00533d40(R)
//              int               Stack[-0x1c]:4 B0
//                               ?Init_Tile_Edge_Tables@RGE_View@@IAEXXZ                      XREF[1]:     setup:00533a6d(c)
//                               RGE_View::Init_Tile_Edge_Tables
//                              view.cpp:550 (7)
//         00533af0     SUB        ESP,0x18
//         00533af3     PUSH       EBX
//         00533af4     PUSH       EBP
//         00533af5     PUSH       ESI
//         00533af6     PUSH       EDI
//                              view.cpp:561 (31)
//         00533af7     PUSH       0x8000
//         00533afc     MOV        EBP,this
//         00533afe     PUSH       s_DATA2\TILEEDGE.DAT                             = "DATA2\\TILEEDGE.DAT"
//         00533b03     CALL       __open                                           undefined __open()
//         00533b08     MOV        ESI,EAX
//         00533b0a     ADD        ESP,0x8
//         00533b0d     CMP        ESI,-0x1
//         00533b10     JZ         LAB_00533bb8
//                              view.cpp:563 (13)
//         00533b16     PUSH       0x2
//         00533b18     PUSH       0x0
//         00533b1a     PUSH       ESI
//         00533b1b     CALL       lseek                                            undefined lseek()
//         00533b20     ADD        ESP,0xc
//                              view.cpp:564 (11)
//         00533b23     PUSH       ESI
//         00533b24     CALL       __tell                                           undefined __tell()
//         00533b29     ADD        ESP,0x4
//         00533b2c     MOV        EDI,EAX
//                              view.cpp:566 (17)
//         00533b2e     PUSH       EDI
//         00533b2f     PUSH       0x1
//         00533b31     CALL       calloc                                           undefined calloc()
//         00533b36     ADD        ESP,0x8
//         00533b39     MOV        dword ptr [EBP + 0x184],EAX
//                              view.cpp:568 (10)
//         00533b3f     PUSH       0x0
//         00533b41     PUSH       0x0
//         00533b43     PUSH       ESI
//         00533b44     CALL       lseek                                            undefined lseek()
//                              view.cpp:569 (20)
//         00533b49     MOV        EAX,dword ptr [EBP + 0x184]
//         00533b4f     ADD        ESP,0xc
//         00533b52     PUSH       EDI
//         00533b53     PUSH       EAX
//         00533b54     PUSH       ESI
//         00533b55     CALL       read                                             undefined read()
//         00533b5a     ADD        ESP,0xc
//                              view.cpp:570 (6)
//         00533b5d     PUSH       ESI
//         00533b5e     CALL       close                                            undefined close()
//                              view.cpp:574 (9)
//         00533b63     MOV        EDX,dword ptr [EBP + 0x184]
//         00533b69     ADD        ESP,0x4
//                              view.cpp:704 (26)
//         00533b6c     XOR        EAX,EAX
//                               LAB_00533b6e                                                 XREF[1]:     00533b82(j)
//         00533b6e     MOV        this,dword ptr [EBP + 0x184]
//         00533b74     ADD        this,EAX
//         00533b76     ADD        EAX,0x4
//         00533b79     MOV        EDI,dword ptr [this->_padding_]
//         00533b7b     ADD        EDI,EDX
//         00533b7d     CMP        EAX,0x44
//         00533b80     MOV        dword ptr [this->_padding_],EDI
//         00533b82     JL         LAB_00533b6e
//         00533b84     XOR        EDI,EDI
//                               LAB_00533b86                                                 XREF[1]:     00533bb6(j)
//                              view.cpp:589 (14)
//         00533b86     MOV        EAX,dword ptr [EBP + 0x184]
//         00533b8c     MOV        ESI,0x2f
//         00533b91     MOV        EAX,dword ptr [EDI + EAX*0x1]
//                               LAB_00533b94                                                 XREF[1]:     00533bae(j)
//                              view.cpp:593 (2)
//         00533b94     MOV        this,dword ptr [EAX]
//                              view.cpp:594 (8)
//         00533b96     TEST       this,this
//         00533b98     JZ         LAB_00533b9e
//         00533b9a     ADD        this,EDX
//         00533b9c     MOV        dword ptr [EAX],this
//                               LAB_00533b9e                                                 XREF[1]:     00533b98(j)
//                              view.cpp:596 (3)
//         00533b9e     MOV        this,dword ptr [EAX + 0x4]
//                              view.cpp:597 (23)
//         00533ba1     TEST       this,this
//         00533ba3     JZ         LAB_00533baa
//         00533ba5     ADD        this,EDX
//         00533ba7     MOV        dword ptr [EAX + 0x4],this
//                               LAB_00533baa                                                 XREF[1]:     00533ba3(j)
//         00533baa     ADD        EAX,0x8
//         00533bad     DEC        ESI
//         00533bae     JNZ        LAB_00533b94
//         00533bb0     ADD        EDI,0x4
//         00533bb3     CMP        EDI,0x44
//         00533bb6     JL         LAB_00533b86
//                               LAB_00533bb8                                                 XREF[1]:     00533b10(j)
//                              view.cpp:606 (29)
//         00533bb8     PUSH       0x8000
//         00533bbd     PUSH       s_DATA2\BLKEDGE.DAT                              = "DATA2\\BLKEDGE.DAT"
//         00533bc2     CALL       __open                                           undefined __open()
//         00533bc7     MOV        ESI,EAX
//         00533bc9     ADD        ESP,0x8
//         00533bcc     CMP        ESI,-0x1
//         00533bcf     JZ         LAB_00533c6b
//                              view.cpp:608 (13)
//         00533bd5     PUSH       0x2
//         00533bd7     PUSH       0x0
//         00533bd9     PUSH       ESI
//         00533bda     CALL       lseek                                            undefined lseek()
//         00533bdf     ADD        ESP,0xc
//                              view.cpp:609 (11)
//         00533be2     PUSH       ESI
//         00533be3     CALL       __tell                                           undefined __tell()
//         00533be8     ADD        ESP,0x4
//         00533beb     MOV        EDI,EAX
//                              view.cpp:611 (17)
//         00533bed     PUSH       EDI
//         00533bee     PUSH       0x1
//         00533bf0     CALL       calloc                                           undefined calloc()
//         00533bf5     ADD        ESP,0x8
//         00533bf8     MOV        dword ptr [EBP + 0x188],EAX
//                              view.cpp:613 (10)
//         00533bfe     PUSH       0x0
//         00533c00     PUSH       0x0
//         00533c02     PUSH       ESI
//         00533c03     CALL       lseek                                            undefined lseek()
//                              view.cpp:614 (20)
//         00533c08     MOV        EDX,dword ptr [EBP + 0x188]
//         00533c0e     ADD        ESP,0xc
//         00533c11     PUSH       EDI
//         00533c12     PUSH       EDX
//         00533c13     PUSH       ESI
//         00533c14     CALL       read                                             undefined read()
//         00533c19     ADD        ESP,0xc
//                              view.cpp:615 (6)
//         00533c1c     PUSH       ESI
//         00533c1d     CALL       close                                            undefined close()
//                              view.cpp:619 (9)
//         00533c22     MOV        ESI,dword ptr [EBP + 0x188]
//         00533c28     ADD        ESP,0x4
//                              view.cpp:704 (26)
//         00533c2b     XOR        EAX,EAX
//                               LAB_00533c2d                                                 XREF[1]:     00533c41(j)
//         00533c2d     MOV        this,dword ptr [EBP + 0x188]
//         00533c33     ADD        this,EAX
//         00533c35     ADD        EAX,0x4
//         00533c38     MOV        EDI,dword ptr [this->_padding_]
//         00533c3a     ADD        EDI,ESI
//         00533c3c     CMP        EAX,0x44
//         00533c3f     MOV        dword ptr [this->_padding_],EDI
//         00533c41     JL         LAB_00533c2d
//         00533c43     XOR        EDI,EDI
//                               LAB_00533c45                                                 XREF[1]:     00533c69(j)
//                              view.cpp:634 (14)
//         00533c45     MOV        EDX,dword ptr [EBP + 0x188]
//         00533c4b     MOV        EAX,dword ptr [EDI + EDX*0x1]
//         00533c4e     MOV        EDX,0x2f
//                               LAB_00533c53                                                 XREF[1]:     00533c61(j)
//                              view.cpp:638 (2)
//         00533c53     MOV        this,dword ptr [EAX]
//                              view.cpp:639 (22)
//         00533c55     TEST       this,this
//         00533c57     JZ         LAB_00533c5d
//         00533c59     ADD        this,ESI
//         00533c5b     MOV        dword ptr [EAX],this
//                               LAB_00533c5d                                                 XREF[1]:     00533c57(j)
//         00533c5d     ADD        EAX,0x4
//         00533c60     DEC        EDX
//         00533c61     JNZ        LAB_00533c53
//         00533c63     ADD        EDI,0x4
//         00533c66     CMP        EDI,0x44
//         00533c69     JL         LAB_00533c45
//                               LAB_00533c6b                                                 XREF[1]:     00533bcf(j)
//                              view.cpp:647 (18)
//         00533c6b     ADD        EBP,0x1a0
//         00533c71     MOV        this,0x40
//         00533c76     OR         EAX,0xffffffff
//         00533c79     MOV        EDI,EBP
//         00533c7b     STOSD.REP  ES:EDI
//                              view.cpp:649 (10)
//         00533c7d     XOR        EAX,EAX
//         00533c7f     MOV        dword ptr [ESP + local_4],EBP
//         00533c83     MOV        dword ptr [ESP + B5],EAX
//                               LAB_00533c87                                                 XREF[1]:     00533d68(j)
//                              view.cpp:652 (5)
//         00533c87     MOV        EDI,0x1
//                              view.cpp:654 (4)
//         00533c8c     MOV        EDX,EAX
//         00533c8e     AND        EDX,EDI
//                              view.cpp:655 (21)
//         00533c90     MOV        this,EAX
//         00533c92     DEC        DL
//         00533c94     NEG        DL
//         00533c96     SBB        EDX,EDX
//         00533c98     AND        this,0x2
//         00533c9b     INC        EDX
//         00533c9c     MOV        dword ptr [ESP + A4],EDX
//         00533ca0     XOR        EDX,EDX
//         00533ca2     CMP        this,0x2
//                              view.cpp:656 (17)
//         00533ca5     MOV        this,EAX
//         00533ca7     SETZ       DL
//         00533caa     MOV        dword ptr [ESP + y],EDX
//         00533cae     AND        this,0x4
//         00533cb1     XOR        EDX,EDX
//         00533cb3     CMP        this,0x4
//                              view.cpp:657 (13)
//         00533cb6     MOV        this,EAX
//         00533cb8     SETZ       DL
//         00533cbb     AND        this,0x8
//         00533cbe     XOR        EBX,EBX
//         00533cc0     CMP        this,0x8
//                              view.cpp:658 (18)
//         00533cc3     MOV        this,EAX
//         00533cc5     SETZ       BL
//         00533cc8     MOV        ESI,EBX
//         00533cca     AND        this,0x10
//         00533ccd     XOR        EBX,EBX
//         00533ccf     CMP        this,0x10
//         00533cd2     SETZ       BL
//                              view.cpp:659 (14)
//         00533cd5     MOV        this,EAX
//         00533cd7     MOV        dword ptr [ESP + local_8],EBX
//         00533cdb     AND        this,0x20
//         00533cde     XOR        EBX,EBX
//         00533ce0     CMP        this,0x20
//                              view.cpp:660 (22)
//         00533ce3     MOV        this,EAX
//         00533ce5     SETZ       BL
//         00533ce8     MOV        dword ptr [ESP + B4],EBX
//         00533cec     AND        this,0x40
//         00533cef     XOR        EBX,EBX
//         00533cf1     CMP        this,0x40
//         00533cf4     SETZ       BL
//         00533cf7     MOV        this,EBX
//                              view.cpp:663 (27)
//         00533cf9     MOV        EBX,EAX
//         00533cfb     AND        EBX,0x80
//         00533d01     CMP        BL,0x80
//         00533d04     JNZ        LAB_00533d14
//         00533d06     MOV        EBX,dword ptr [ESP + A4]
//         00533d0a     TEST       EBX,EBX
//         00533d0c     JNZ        LAB_00533d12
//         00533d0e     TEST       ESI,ESI
//         00533d10     JZ         LAB_00533d14
//                               LAB_00533d12                                                 XREF[1]:     00533d0c(j)
//         00533d12     XOR        EDI,EDI
//                               LAB_00533d14                                                 XREF[2]:     00533d04(j), 00533d10(j)
//                              view.cpp:664 (14)
//         00533d14     TEST       this,this
//         00533d16     JZ         LAB_00533d22
//         00533d18     TEST       EDX,EDX
//         00533d1a     JNZ        LAB_00533d20
//         00533d1c     TEST       ESI,ESI
//         00533d1e     JZ         LAB_00533d22
//                               LAB_00533d20                                                 XREF[1]:     00533d1a(j)
//         00533d20     XOR        EDI,EDI
//                               LAB_00533d22                                                 XREF[2]:     00533d16(j), 00533d1e(j)
//                              view.cpp:665 (22)
//         00533d22     MOV        this,dword ptr [ESP + B4]
//         00533d26     TEST       this,this
//         00533d28     JZ         LAB_00533d38
//         00533d2a     MOV        this,dword ptr [ESP + y]
//         00533d2e     TEST       this,this
//         00533d30     JNZ        LAB_00533d36
//         00533d32     TEST       EDX,EDX
//         00533d34     JZ         LAB_00533d38
//                               LAB_00533d36                                                 XREF[1]:     00533d30(j)
//         00533d36     XOR        EDI,EDI
//                               LAB_00533d38                                                 XREF[2]:     00533d28(j), 00533d34(j)
//                              view.cpp:666 (26)
//         00533d38     MOV        this,dword ptr [ESP + local_8]
//         00533d3c     TEST       this,this
//         00533d3e     JZ         LAB_00533d52
//         00533d40     MOV        this,dword ptr [ESP + A4]
//         00533d44     TEST       this,this
//         00533d46     JNZ        LAB_00533d50
//         00533d48     MOV        this,dword ptr [ESP + y]
//         00533d4c     TEST       this,this
//         00533d4e     JZ         LAB_00533d52
//                               LAB_00533d50                                                 XREF[1]:     00533d46(j)
//         00533d50     XOR        EDI,EDI
//                               LAB_00533d52                                                 XREF[2]:     00533d3e(j), 00533d4e(j)
//                              view.cpp:668 (4)
//         00533d52     TEST       EDI,EDI
//         00533d54     JZ         LAB_00533d62
//                              view.cpp:670 (7)
//         00533d56     MOV        this,dword ptr [ESP + B5]
//         00533d5a     MOV        byte ptr [EAX + EBP*0x1],this
//                              view.cpp:671 (17)
//         00533d5d     INC        this
//         00533d5e     MOV        dword ptr [ESP + B5],this
//                               LAB_00533d62                                                 XREF[1]:     00533d54(j)
//         00533d62     INC        EAX
//         00533d63     CMP        EAX,0x100
//         00533d68     JL         LAB_00533c87
//                              view.cpp:676 (2)
//         00533d6e     XOR        EAX,EAX
//                               LAB_00533d70                                                 XREF[1]:     00533e01(j)
//                              view.cpp:678 (10)
//         00533d70     CMP        byte ptr [EAX + EBP*0x1],0xff
//         00533d74     JNZ        LAB_00533dfb
//                              view.cpp:684 (13)
//         00533d7a     MOV        this,EAX
//         00533d7c     MOV        ESI,EAX
//         00533d7e     AND        this,0x10
//         00533d81     MOV        EDX,EAX
//         00533d83     MOV        dword ptr [ESP + y],this
//                              view.cpp:685 (13)
//         00533d87     MOV        this,EAX
//         00533d89     AND        this,0x20
//         00533d8c     MOV        EDI,EAX
//         00533d8e     MOV        EBX,EAX
//         00533d90     MOV        dword ptr [ESP + B5],this
//                              view.cpp:686 (2)
//         00533d94     MOV        EBP,EAX
//                              view.cpp:687 (27)
//         00533d96     MOV        this,EAX
//         00533d98     AND        ESI,0x1
//         00533d9b     AND        EDX,0x2
//         00533d9e     AND        EDI,0x4
//         00533da1     AND        EBX,0x8
//         00533da4     AND        EBP,0x40
//         00533da7     AND        this,0x80
//         00533dad     MOV        dword ptr [ESP + local_8],EBP
//                              view.cpp:689 (6)
//         00533db1     JZ         LAB_00533db7
//         00533db3     XOR        EBX,EBX
//         00533db5     XOR        ESI,ESI
//                               LAB_00533db7                                                 XREF[1]:     00533db1(j)
//                              view.cpp:690 (8)
//         00533db7     TEST       EBP,EBP
//         00533db9     JZ         LAB_00533dbf
//         00533dbb     XOR        EBX,EBX
//         00533dbd     XOR        EDI,EDI
//                               LAB_00533dbf                                                 XREF[1]:     00533db9(j)
//                              view.cpp:691 (12)
//         00533dbf     MOV        EBP,dword ptr [ESP + B5]
//         00533dc3     TEST       EBP,EBP
//         00533dc5     JZ         LAB_00533dcb
//         00533dc7     XOR        EDI,EDI
//         00533dc9     XOR        EDX,EDX
//                               LAB_00533dcb                                                 XREF[1]:     00533dc5(j)
//                              view.cpp:692 (12)
//         00533dcb     MOV        EBP,dword ptr [ESP + y]
//         00533dcf     TEST       EBP,EBP
//         00533dd1     JZ         LAB_00533dd7
//         00533dd3     XOR        EDX,EDX
//         00533dd5     XOR        ESI,ESI
//                               LAB_00533dd7                                                 XREF[1]:     00533dd1(j)
//                              view.cpp:696 (48)
//         00533dd7     MOV        EBP,dword ptr [ESP + local_8]
//         00533ddb     OR         this,EBP
//         00533ddd     MOV        EBP,dword ptr [ESP + B5]
//         00533de1     OR         this,EBP
//         00533de3     MOV        EBP,dword ptr [ESP + y]
//         00533de7     OR         this,EBP
//         00533de9     MOV        EBP,dword ptr [ESP + local_4]
//         00533ded     OR         this,EBX
//         00533def     OR         this,EDI
//         00533df1     OR         this,EDX
//         00533df3     OR         this,ESI
//         00533df5     MOV        DL,byte ptr [this->_padding_ + EBP*0x1]
//         00533df8     MOV        byte ptr [EAX + EBP*0x1],DL
//                               LAB_00533dfb                                                 XREF[1]:     00533d74(j)
//         00533dfb     INC        EAX
//         00533dfc     CMP        EAX,0x100
//         00533e01     JL         LAB_00533d70
//                              view.cpp:704 (8)
//         00533e07     POP        EDI
//         00533e08     POP        ESI
//         00533e09     POP        EBP
//         00533e0a     POP        EBX
//         00533e0b     ADD        ESP,0x18
//         00533e0e     RET
//         00533e0f     ??         90h
    return;
}

void RGE_View::update_display_selected_objects() {
    /* TODO: Stub */
//                              void __thiscall update_display_selected_objects(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?update_display_selected_objects@RGE_View@@QAEXXZ            XREF[1]:     view_function_terrain:00536b56(c)
//                               RGE_View::update_display_selected_objects
//                              view.cpp:711 (2)
//         00533e10     PUSH       EBP
//         00533e11     PUSH       ESI
//                              view.cpp:715 (17)
//         00533e12     PUSH       0x2cb
//         00533e17     MOV        ESI,this
//         00533e19     PUSH       s_C:\msdev\work\age1_x1\view.cpp                 = "C:\\msdev\\work\\age1_x1\\view.cpp"
//         00533e1e     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              view.cpp:721 (19)
//         00533e23     MOV        this,dword ptr [ESI + 0x35c]
//         00533e29     ADD        ESP,0x8
//         00533e2c     XOR        EBP,EBP
//         00533e2e     TEST       this,this
//         00533e30     JLE        LAB_00533e9f
//         00533e32     PUSH       EDI
//         00533e33     PUSH       EBX
//         00533e34     XOR        EBX,EBX
//                               LAB_00533e36                                                 XREF[1]:     00533e9b(j)
//                              view.cpp:723 (8)
//         00533e36     MOV        this,dword ptr [ESI + 0x354]
//         00533e3c     ADD        this,EBX
//                              view.cpp:724 (5)
//         00533e3e     CMP        dword ptr [this->_padding_],0x0
//         00533e41     JZ         LAB_00533e8f
//                              view.cpp:726 (18)
//         00533e43     MOV        EDI,dword ptr [ESI + 0xfc]
//         00533e49     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00533e4c     MOV        EDI,dword ptr [EDI + 0x88]
//         00533e52     MOV        EDX,dword ptr [EDI + EDX*0x4]
//                              view.cpp:728 (4)
//         00533e55     TEST       EDX,EDX
//         00533e57     JNZ        LAB_00533e6a
//                              view.cpp:730 (2)
//         00533e59     MOV        dword ptr [this->_padding_],EDX
//                              view.cpp:731 (13)
//         00533e5b     MOV        this,dword ptr [ESI + 0x358]
//         00533e61     DEC        this
//         00533e62     MOV        dword ptr [ESI + 0x358],this
//                              view.cpp:733 (2)
//         00533e68     JMP        LAB_00533e8f
//                               LAB_00533e6a                                                 XREF[1]:     00533e57(j)
//                              view.cpp:735 (5)
//         00533e6a     MOV        EDI,EAX
//         00533e6c     SUB        EDI,dword ptr [ECX + this->_padding_]
//                              view.cpp:736 (5)
//         00533e6f     CMP        EDI,dword ptr [ECX + this->_padding_]
//         00533e72     JBE        LAB_00533ea2
//                              view.cpp:738 (6)
//         00533e74     MOV        dword ptr [this->_padding_],0x0
//                              view.cpp:739 (13)
//         00533e7a     MOV        EDI,dword ptr [ESI + 0x358]
//         00533e80     DEC        EDI
//         00533e81     MOV        dword ptr [ESI + 0x358],EDI
//                               LAB_00533e87                                                 XREF[1]:     00533ea8(j)
//                              view.cpp:751 (24)
//         00533e87     MOV        this,byte ptr [ECX + this->_padding_]
//         00533e8a     NOT        this
//         00533e8c     AND        byte ptr [EDX + 0x36],this
//                               LAB_00533e8f                                                 XREF[3]:     00533e41(j), 00533e68(j),
//                                                                                                         00533eb0(j)
//         00533e8f     MOV        this,dword ptr [ESI + 0x35c]
//         00533e95     INC        EBP
//         00533e96     ADD        EBX,0x14
//         00533e99     CMP        EBP,this
//         00533e9b     JL         LAB_00533e36
//         00533e9d     POP        EBX
//         00533e9e     POP        EDI
//                               LAB_00533e9f                                                 XREF[1]:     00533e30(j)
//                              view.cpp:759 (3)
//         00533e9f     POP        ESI
//         00533ea0     POP        EBP
//         00533ea1     RET
//                               LAB_00533ea2                                                 XREF[1]:     00533e72(j)
//                              view.cpp:745 (8)
//         00533ea2     TEST       EDI,0x100
//         00533ea8     JNZ        LAB_00533e87
//                              view.cpp:747 (6)
//         00533eaa     MOV        this,byte ptr [ECX + this->_padding_]
//         00533ead     OR         byte ptr [EDX + 0x36],this
//                              view.cpp:749 (2)
//         00533eb0     JMP        LAB_00533e8f
//         00533eb2     ??         90h
//         00533eb3     NOP
//         00533eb4     NOP
//         00533eb5     NOP
//         00533eb6     NOP
//         00533eb7     NOP
//         00533eb8     NOP
//         00533eb9     NOP
//         00533eba     NOP
//         00533ebb     NOP
//         00533ebc     NOP
//         00533ebd     NOP
//         00533ebe     NOP
//         00533ebf     NOP
    return;
}

void RGE_View::display_object_selection(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall display_object_selection(RGE_View * this, int param_
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00533f1f(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00533f3b(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00533f3f(R)
//              int               Stack[0x10]:4  param_4                   XREF[4]:     00533ed4(R), 00533ed8(R), 00533f03(R), 00533f17(R)
//                               ?display_object_selection@RGE_View@@QAEXHHHH@Z               XREF[4]:     mouse_left_up_action:0052d882(c),
//                               RGE_View::display_object_selection                                        mouse_right_up_action:0052dbf2(c),
//                                                                                                         command_make_do:0053fab9(c),
//                                                                                                         command_make_work:005404b5(c)
//                              view.cpp:765 (5)
//         00533ec0     PUSH       EBX
//         00533ec1     PUSH       EBP
//         00533ec2     PUSH       ESI
//         00533ec3     MOV        ESI,this
//                              view.cpp:768 (2)
//         00533ec5     XOR        EBX,EBX
//                              view.cpp:772 (23)
//         00533ec7     XOR        EDX,EDX
//         00533ec9     MOV        EAX,dword ptr [ESI + 0x35c]
//         00533ecf     PUSH       EDI
//         00533ed0     TEST       EAX,EAX
//         00533ed2     JLE        LAB_00533f17
//         00533ed4     MOV        EBP,dword ptr [ESP + param_4]
//         00533ed8     MOV        EDI,dword ptr [ESP + param_4]
//         00533edc     XOR        this,this
//                               LAB_00533ede                                                 XREF[1]:     00533f13(j)
//                              view.cpp:774 (8)
//         00533ede     MOV        EAX,dword ptr [ESI + 0x354]
//         00533ee4     ADD        EAX,this
//                              view.cpp:775 (5)
//         00533ee6     CMP        dword ptr [EAX],0x0
//         00533ee9     JNZ        LAB_00533ef4
//                              view.cpp:777 (5)
//         00533eeb     MOV        EBX,0x1
//                              view.cpp:778 (2)
//         00533ef0     MOV        EDI,EAX
//                              view.cpp:780 (2)
//         00533ef2     JMP        LAB_00533f07
//                               LAB_00533ef4                                                 XREF[1]:     00533ee9(j)
//                              view.cpp:782 (4)
//         00533ef4     TEST       EBP,EBP
//         00533ef6     JZ         LAB_00533f07
//                              view.cpp:784 (5)
//         00533ef8     CMP        dword ptr [EAX + 0x10],EBP
//         00533efb     JNZ        LAB_00533f07
//                              view.cpp:786 (24)
//         00533efd     MOV        EBP,dword ptr [EAX + 0xc]
//         00533f00     SUB        dword ptr [EAX + 0x8],EBP
//         00533f03     MOV        EBP,dword ptr [ESP + param_4]
//                               LAB_00533f07                                                 XREF[3]:     00533ef2(j), 00533ef6(j),
//                                                                                                         00533efb(j)
//         00533f07     MOV        EAX,dword ptr [ESI + 0x35c]
//         00533f0d     INC        EDX
//         00533f0e     ADD        this,0x14
//         00533f11     CMP        EDX,EAX
//         00533f13     JL         LAB_00533ede
//                              view.cpp:772 (6)
//         00533f15     JMP        LAB_00533f1b
//                               LAB_00533f17                                                 XREF[1]:     00533ed2(j)
//         00533f17     MOV        EDI,dword ptr [ESP + param_4]
//                               LAB_00533f1b                                                 XREF[1]:     00533f15(j)
//                              view.cpp:793 (4)
//         00533f1b     TEST       EBX,EBX
//         00533f1d     JZ         LAB_00533f5c
//                              view.cpp:796 (4)
//         00533f1f     MOV        EAX,dword ptr [ESP + param_1]
//                              view.cpp:797 (24)
//         00533f23     PUSH       0x31d
//         00533f28     PUSH       s_C:\msdev\work\age1_x1\view.cpp                 = "C:\\msdev\\work\\age1_x1\\view.cpp"
//         00533f2d     MOV        dword ptr [EDI],0x1
//         00533f33     MOV        dword ptr [EDI + 0x4],EAX
//         00533f36     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              view.cpp:798 (4)
//         00533f3b     MOV        this,dword ptr [ESP + param_2]
//                              view.cpp:799 (13)
//         00533f3f     MOV        EDX,dword ptr [ESP + param_3]
//         00533f43     MOV        dword ptr [EDI + 0x8],EAX
//         00533f46     MOV        dword ptr [EDI + 0xc],this
//         00533f49     MOV        dword ptr [EDI + 0x10],EDX
//                              view.cpp:801 (16)
//         00533f4c     MOV        EAX,dword ptr [ESI + 0x358]
//         00533f52     ADD        ESP,0x8
//         00533f55     INC        EAX
//         00533f56     MOV        dword ptr [ESI + 0x358],EAX
//                               LAB_00533f5c                                                 XREF[1]:     00533f1d(j)
//                              view.cpp:804 (7)
//         00533f5c     POP        EDI
//         00533f5d     POP        ESI
//         00533f5e     POP        EBP
//         00533f5f     POP        EBX
//         00533f60     RET        0x10
//         00533f63     ??         90h
//         00533f64     NOP
//         00533f65     NOP
//         00533f66     NOP
//         00533f67     NOP
//         00533f68     NOP
//         00533f69     NOP
//         00533f6a     NOP
//         00533f6b     NOP
//         00533f6c     NOP
//         00533f6d     NOP
//         00533f6e     NOP
//         00533f6f     NOP
    return;
}

void RGE_View::set_rect(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_rect(RGE_View * this, long param_1, long param_2
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[2]:     00533f98(R), 005340bf(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00533f7e(R), 005340bb(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00533f8f(R)
//              long              Stack[0x10]:4  param_4                   XREF[4]:     00533f8a(R), 0053401d(W), 00534051(W), 00534082(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     00534023(W), 0053403f(W), 00534057(W), 00534070(W),
//                                                                                     00534088(W), 005340ad(W)
//                               ?set_rect@RGE_View@@UAEXJJJJ@Z                               XREF[3]:     00572ab4(*), 005775c4(*),
//                               RGE_View::set_rect                                                        005777fc(*)
//                              view.cpp:811 (14)
//         00533f70     MOV        EAX,FS:[0x0]
//         00533f76     PUSH       -0x1
//         00533f78     PUSH       FUN_00561b81
//         00533f7d     PUSH       EAX
//                              view.cpp:813 (40)
//         00533f7e     MOV        EAX,dword ptr [ESP + param_2]
//         00533f82     MOV        dword ptr FS:[0x0],ESP
//         00533f89     PUSH       EBX
//         00533f8a     MOV        EBX,dword ptr [ESP + param_4]
//         00533f8e     PUSH       EBP
//         00533f8f     MOV        EBP,dword ptr [ESP + param_3]
//         00533f93     PUSH       ESI
//         00533f94     PUSH       EDI
//         00533f95     MOV        ESI,this
//         00533f97     PUSH       EBX
//         00533f98     MOV        this,dword ptr [ESP + param_1]
//         00533f9c     PUSH       EBP
//         00533f9d     PUSH       EAX
//         00533f9e     PUSH       this
//         00533f9f     MOV        this,ESI
//         00533fa1     CALL       TPanel::set_rect                                 void set_rect(TPanel * this, long param_1, lo
//                              view.cpp:815 (7)
//         00533fa6     MOV        this,ESI
//         00533fa8     CALL       RGE_View::calc_draw_vars                         void calc_draw_vars(RGE_View * this)
//                              view.cpp:817 (7)
//         00533fad     MOV        this,ESI
//         00533faf     CALL       RGE_View::create_surfaces                        int create_surfaces(RGE_View * this)
//                              view.cpp:824 (43)
//         00533fb4     MOV        EDI,dword ptr [ESI + 0x178]
//         00533fba     MOV        EAX,0xc61c3c00
//         00533fbf     TEST       EDI,EDI
//         00533fc1     MOV        dword ptr [ESI + 0x138],EAX
//         00533fc7     MOV        dword ptr [ESI + 0x13c],EAX
//         00533fcd     JZ         LAB_00533fdf
//         00533fcf     MOV        this,EDI
//         00533fd1     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
//         00533fd6     PUSH       EDI
//         00533fd7     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00533fdc     ADD        ESP,0x4
//                               LAB_00533fdf                                                 XREF[1]:     00533fcd(j)
//                              view.cpp:825 (26)
//         00533fdf     MOV        EDI,dword ptr [ESI + 0x17c]
//         00533fe5     TEST       EDI,EDI
//         00533fe7     JZ         LAB_00533ff9
//         00533fe9     MOV        this,EDI
//         00533feb     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
//         00533ff0     PUSH       EDI
//         00533ff1     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00533ff6     ADD        ESP,0x4
//                               LAB_00533ff9                                                 XREF[1]:     00533fe7(j)
//                              view.cpp:826 (26)
//         00533ff9     MOV        EDI,dword ptr [ESI + 0x180]
//         00533fff     TEST       EDI,EDI
//         00534001     JZ         LAB_00534013
//         00534003     MOV        this,EDI
//         00534005     CALL       TSpan_List_Manager::~TSpan_List_Manager          void ~TSpan_List_Manager(TSpan_List_Manager *
//         0053400a     PUSH       EDI
//         0053400b     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00534010     ADD        ESP,0x4
//                              language.dll match for 0x68: "Arial"
//                               LAB_00534013                                                 XREF[1]:     00534001(j)
//                              view.cpp:828 (42)
//         00534013     PUSH       0x68
//         00534015     CALL       operator_new                                     void * operator_new(uint param_1)
//         0053401a     ADD        ESP,0x4
//         0053401d     MOV        dword ptr [ESP + param_4],EAX
//         00534021     TEST       EAX,EAX
//         00534023     MOV        dword ptr [ESP + local_4],0x0
//         0053402b     JZ         LAB_00534038
//         0053402d     PUSH       EBX
//         0053402e     PUSH       EBP
//         0053402f     MOV        this,EAX
//         00534031     CALL       TSpan_List_Manager::TSpan_List_Manager           undefined TSpan_List_Manager(TSpan_List_Manag
//         00534036     JMP        LAB_0053403a
//                               LAB_00534038                                                 XREF[1]:     0053402b(j)
//         00534038     XOR        EAX,EAX
//                               LAB_0053403a                                                 XREF[1]:     00534036(j)
//         0053403a     OR         EDI,0xffffffff
//                              language.dll match for 0x68: "Arial"
//                              view.cpp:829 (49)
//         0053403d     PUSH       0x68
//         0053403f     MOV        dword ptr [ESP + local_4],EDI
//         00534043     MOV        dword ptr [ESI + 0x178],EAX
//         00534049     CALL       operator_new                                     void * operator_new(uint param_1)
//         0053404e     ADD        ESP,0x4
//         00534051     MOV        dword ptr [ESP + param_4],EAX
//         00534055     TEST       EAX,EAX
//         00534057     MOV        dword ptr [ESP + local_4],0x1
//         0053405f     JZ         LAB_0053406c
//         00534061     PUSH       EBX
//         00534062     PUSH       EBP
//         00534063     MOV        this,EAX
//         00534065     CALL       TSpan_List_Manager::TSpan_List_Manager           undefined TSpan_List_Manager(TSpan_List_Manag
//         0053406a     JMP        LAB_0053406e
//                               LAB_0053406c                                                 XREF[1]:     0053405f(j)
//         0053406c     XOR        EAX,EAX
//                              language.dll match for 0x68: "Arial"
//                               LAB_0053406e                                                 XREF[1]:     0053406a(j)
//                              view.cpp:830 (55)
//         0053406e     PUSH       0x68
//         00534070     MOV        dword ptr [ESP + local_4],EDI
//         00534074     MOV        dword ptr [ESI + 0x17c],EAX
//         0053407a     CALL       operator_new                                     void * operator_new(uint param_1)
//         0053407f     ADD        ESP,0x4
//         00534082     MOV        dword ptr [ESP + param_4],EAX
//         00534086     TEST       EAX,EAX
//         00534088     MOV        dword ptr [ESP + local_4],0x2
//         00534090     JZ         LAB_0053409d
//         00534092     PUSH       EBX
//         00534093     PUSH       EBP
//         00534094     MOV        this,EAX
//         00534096     CALL       TSpan_List_Manager::TSpan_List_Manager           undefined TSpan_List_Manager(TSpan_List_Manag
//         0053409b     JMP        LAB_0053409f
//                               LAB_0053409d                                                 XREF[1]:     00534090(j)
//         0053409d     XOR        EAX,EAX
//                               LAB_0053409f                                                 XREF[1]:     0053409b(j)
//         0053409f     MOV        dword ptr [ESI + 0x180],EAX
//                              view.cpp:834 (22)
//         005340a5     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         005340ab     TEST       this,this
//         005340ad     MOV        dword ptr [ESP + local_4],EDI
//         005340b1     JZ         LAB_005340dd
//         005340b3     TEST       EBP,EBP
//         005340b5     JLE        LAB_005340dd
//         005340b7     TEST       EBX,EBX
//         005340b9     JLE        LAB_005340dd
//                              view.cpp:836 (21)
//         005340bb     MOV        EAX,dword ptr [ESP + param_2]
//         005340bf     MOV        EDX,dword ptr [ESP + param_1]
//         005340c3     ADD        EBX,EAX
//         005340c5     ADD        EBP,EDX
//         005340c7     PUSH       EBX
//         005340c8     PUSH       EBP
//         005340c9     PUSH       EAX
//         005340ca     PUSH       EDX
//         005340cb     CALL       TMousePointer::set_game_window                   void set_game_window(TMousePointer * this, in
//                              view.cpp:837 (13)
//         005340d0     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         005340d6     PUSH       0x1
//         005340d8     CALL       TMousePointer::set_game_mode                     void set_game_mode(TMousePointer * this, int
//                               LAB_005340dd                                                 XREF[3]:     005340b1(j), 005340b5(j),
//                                                                                                         005340b9(j)
//                              view.cpp:840 (9)
//         005340dd     MOV        EDX,dword ptr [ESI]
//         005340df     PUSH       0x2
//         005340e1     MOV        this,ESI
//         005340e3     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:841 (21)
//         005340e6     MOV        this,dword ptr [ESP + 0x10]
//         005340ea     POP        EDI
//         005340eb     POP        ESI
//         005340ec     POP        EBP
//         005340ed     MOV        dword ptr FS:[0x0],this
//         005340f4     POP        EBX
//         005340f5     ADD        ESP,0xc
//         005340f8     RET        0x10
//         005340fb     ??         90h
//         005340fc     NOP
//         005340fd     NOP
//         005340fe     NOP
//         005340ff     NOP
    return;
}

void RGE_View::delete_surfaces() {
    /* TODO: Stub */
//                              void __thiscall delete_surfaces(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?delete_surfaces@RGE_View@@QAEXXZ                            XREF[1]:     ~RGE_View:005337b3(c)
//                               RGE_View::delete_surfaces
//                              view.cpp:848 (4)
//         00534100     PUSH       ESI
//         00534101     PUSH       EDI
//         00534102     MOV        EDI,this
//                              view.cpp:850 (10)
//         00534104     MOV        ESI,dword ptr [EDI + 0x324]
//         0053410a     TEST       ESI,ESI
//         0053410c     JZ         LAB_00534128
//                              view.cpp:852 (16)
//         0053410e     MOV        this,ESI
//         00534110     CALL       TDrawArea::~TDrawArea                            void ~TDrawArea(TDrawArea * this)
//         00534115     PUSH       ESI
//         00534116     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0053411b     ADD        ESP,0x4
//                              view.cpp:853 (10)
//         0053411e     MOV        dword ptr [EDI + 0x324],0x0
//                               LAB_00534128                                                 XREF[1]:     0053410c(j)
//                              view.cpp:855 (3)
//         00534128     POP        EDI
//         00534129     POP        ESI
//         0053412a     RET
//         0053412b     ??         90h
//         0053412c     NOP
//         0053412d     NOP
//         0053412e     NOP
//         0053412f     NOP
    return;
}

int RGE_View::create_surfaces() {
    /* TODO: Stub */
//                              int __thiscall create_surfaces(RGE_View * this)
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0053418b(W), 005341a9(W), 00534267(W), 00534296(W),
//                                                                                     005342b2(W), 005342eb(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0053415d(R), 00534329(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[3]:     00534185(W), 00534261(W), 005342ac(W)
//                               ?create_surfaces@RGE_View@@QAEHXZ                            XREF[1]:     set_rect:00533faf(c)
//                               RGE_View::create_surfaces
//                              view.cpp:861 (26)
//         00534130     PUSH       -0x1
//         00534132     PUSH       FUN_00561bb1
//         00534137     MOV        EAX,FS:[0x0]
//         0053413d     PUSH       EAX
//         0053413e     MOV        dword ptr FS:[0x0],ESP
//         00534145     PUSH       this
//         00534146     PUSH       ESI
//         00534147     MOV        ESI,this
//         00534149     PUSH       EDI
//                              view.cpp:871 (19)
//         0053414a     MOV        EAX,dword ptr [ESI + 0x14]
//         0053414d     TEST       EAX,EAX
//         0053414f     JNZ        LAB_0053416e
//         00534151     MOV        EAX,dword ptr [ESI + 0x18]
//         00534154     TEST       EAX,EAX
//         00534156     JNZ        LAB_0053416e
//         00534158     MOV        EAX,0x1
//                              view.cpp:908 (17)
//         0053415d     MOV        this,dword ptr [ESP + local_c]
//         00534161     MOV        dword ptr FS:[0x0],this
//         00534168     POP        EDI
//         00534169     POP        ESI
//         0053416a     ADD        ESP,0x10
//         0053416d     RET
//                               LAB_0053416e                                                 XREF[2]:     0053414f(j), 00534156(j)
//                              view.cpp:873 (10)
//         0053416e     MOV        EAX,dword ptr [ESI + 0x324]
//         00534174     TEST       EAX,EAX
//         00534176     JNZ        LAB_005341d2
//                              view.cpp:875 (47)
//         00534178     PUSH       0x100
//         0053417d     CALL       operator_new                                     void * operator_new(uint param_1)
//         00534182     ADD        ESP,0x4
//         00534185     MOV        dword ptr [ESP + local_10],EAX
//         00534189     TEST       EAX,EAX
//         0053418b     MOV        dword ptr [ESP + local_4],0x0
//         00534193     JZ         LAB_005341a5
//         00534195     PUSH       0x0
//         00534197     PUSH       s_Terrain_Buffer                                 = "Terrain Buffer"
//         0053419c     MOV        this,EAX
//         0053419e     CALL       TDrawArea::TDrawArea                             undefined TDrawArea(TDrawArea * this, char *
//         005341a3     JMP        LAB_005341a7
//                               LAB_005341a5                                                 XREF[1]:     00534193(j)
//         005341a5     XOR        EAX,EAX
//                               LAB_005341a7                                                 XREF[1]:     005341a3(j)
//                              view.cpp:876 (18)
//         005341a7     TEST       EAX,EAX
//         005341a9     MOV        dword ptr [ESP + local_4],0xffffffff
//         005341b1     MOV        dword ptr [ESI + 0x324],EAX
//         005341b7     JZ         LAB_005341d2
//                              view.cpp:877 (25)
//         005341b9     MOV        this,dword ptr [ESI + 0x18]
//         005341bc     MOV        EDX,dword ptr [ESI + 0x14]
//         005341bf     PUSH       0x0
//         005341c1     PUSH       0x1
//         005341c3     PUSH       this
//         005341c4     MOV        this,dword ptr [ESI + 0x20]
//         005341c7     PUSH       EDX
//         005341c8     MOV        EDX,dword ptr [this->_padding_]
//         005341ca     MOV        this,EAX
//         005341cc     PUSH       EDX
//         005341cd     CALL       TDrawArea::Init                                  int Init(TDrawArea * this, TDrawSystem * para
//                               LAB_005341d2                                                 XREF[2]:     00534176(j), 005341b7(j)
//                              view.cpp:880 (14)
//         005341d2     MOV        this,dword ptr [ESI + 0x324]
//         005341d8     TEST       this,this
//         005341da     JZ         LAB_0053431f
//                              view.cpp:882 (11)
//         005341e0     MOV        EAX,dword ptr [ESI + 0x18]
//         005341e3     TEST       EAX,EAX
//         005341e5     JLE        LAB_0053431f
//                              view.cpp:884 (12)
//         005341eb     PUSH       0x1
//         005341ed     PUSH       EAX
//         005341ee     MOV        EAX,dword ptr [ESI + 0x14]
//         005341f1     PUSH       EAX
//         005341f2     CALL       TDrawArea::SetSize                               void SetSize(TDrawArea * this, long param_1,
//                              view.cpp:889 (35)
//         005341f7     MOV        this,dword ptr [ESI + 0x324]
//         005341fd     PUSH       0x0
//         005341ff     PUSH       0x0
//         00534201     MOV        dword ptr [ESI + 0x2d0],0x0
//         0053420b     MOV        dword ptr [ESI + 0x2d4],0x0
//         00534215     CALL       TDrawArea::SetFloatOffsets                       void SetFloatOffsets(TDrawArea * this, int pa
//                              view.cpp:893 (26)
//         0053421a     MOV        EDI,dword ptr [ESI + 0x334]
//         00534220     TEST       EDI,EDI
//         00534222     JZ         LAB_00534234
//         00534224     MOV        this,EDI
//         00534226     CALL       DClipInfo_List::~DClipInfo_List                  void ~DClipInfo_List(DClipInfo_List * this)
//         0053422b     PUSH       EDI
//         0053422c     CALL       operator_delete                                  void operator_delete(void * param_1)
//         00534231     ADD        ESP,0x4
//                               LAB_00534234                                                 XREF[1]:     00534222(j)
//                              view.cpp:894 (26)
//         00534234     MOV        EDI,dword ptr [ESI + 0x338]
//         0053423a     TEST       EDI,EDI
//         0053423c     JZ         LAB_0053424e
//         0053423e     MOV        this,EDI
//         00534240     CALL       DClipInfo_List::~DClipInfo_List                  void ~DClipInfo_List(DClipInfo_List * this)
//         00534245     PUSH       EDI
//         00534246     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0053424b     ADD        ESP,0x4
//                               LAB_0053424e                                                 XREF[1]:     0053423c(j)
//                              view.cpp:896 (3)
//         0053424e     MOV        EDI,dword ptr [ESI + 0x18]
//                              language.dll match for 0x70: "B"
//                              view.cpp:898 (67)
//         00534251     PUSH       0x70
//         00534253     ADD        EDI,0x1c2
//         00534259     CALL       operator_new                                     void * operator_new(uint param_1)
//         0053425e     ADD        ESP,0x4
//         00534261     MOV        dword ptr [ESP + local_10],EAX
//         00534265     TEST       EAX,EAX
//         00534267     MOV        dword ptr [ESP + local_4],0x1
//         0053426f     JZ         LAB_00534292
//         00534271     MOV        this,dword ptr [ESI + 0x18]
//         00534274     PUSH       0x28
//         00534276     ADD        this,0xf9
//         0053427c     LEA        EDX,[EDI + EDI*0x1]
//         0053427f     PUSH       this
//         00534280     PUSH       0xffffff38
//         00534285     PUSH       0x40
//         00534287     PUSH       EDI
//         00534288     PUSH       EDX
//         00534289     MOV        this,EAX
//         0053428b     CALL       DClipInfo_List::DClipInfo_List                   undefined DClipInfo_List(DClipInfo_List * thi
//         00534290     JMP        LAB_00534294
//                               LAB_00534292                                                 XREF[1]:     0053426f(j)
//         00534292     XOR        EAX,EAX
//                              language.dll match for 0x70: "B"
//                               LAB_00534294                                                 XREF[1]:     00534290(j)
//                              view.cpp:899 (75)
//         00534294     PUSH       0x70
//         00534296     MOV        dword ptr [ESP + local_4],0xffffffff
//         0053429e     MOV        dword ptr [ESI + 0x334],EAX
//         005342a4     CALL       operator_new                                     void * operator_new(uint param_1)
//         005342a9     ADD        ESP,0x4
//         005342ac     MOV        dword ptr [ESP + local_10],EAX
//         005342b0     TEST       EAX,EAX
//         005342b2     MOV        dword ptr [ESP + local_4],0x2
//         005342ba     JZ         LAB_005342dd
//         005342bc     MOV        this,dword ptr [ESI + 0x18]
//         005342bf     PUSH       0x28
//         005342c1     ADD        this,0xf9
//         005342c7     LEA        EDX,[EDI + EDI*0x1]
//         005342ca     PUSH       this
//         005342cb     PUSH       0xffffff38
//         005342d0     PUSH       0x40
//         005342d2     PUSH       EDI
//         005342d3     PUSH       EDX
//         005342d4     MOV        this,EAX
//         005342d6     CALL       DClipInfo_List::DClipInfo_List                   undefined DClipInfo_List(DClipInfo_List * thi
//         005342db     JMP        LAB_005342df
//                               LAB_005342dd                                                 XREF[1]:     005342ba(j)
//         005342dd     XOR        EAX,EAX
//                               LAB_005342df                                                 XREF[1]:     005342db(j)
//                              view.cpp:901 (39)
//         005342df     MOV        this,dword ptr [ESI + 0x14]
//         005342e2     MOV        dword ptr [ESI + 0x338],EAX
//         005342e8     MOV        EAX,dword ptr [ESI + 0x18]
//         005342eb     MOV        dword ptr [ESP + local_4],0xffffffff
//         005342f3     DEC        EAX
//         005342f4     DEC        this
//         005342f5     PUSH       EAX
//         005342f6     PUSH       this
//         005342f7     MOV        this,dword ptr [ESI + 0x334]
//         005342fd     PUSH       0x0
//         005342ff     PUSH       0x0
//         00534301     CALL       DClipInfo_List::SetDrawRegion                    void SetDrawRegion(DClipInfo_List * this, int
//                              view.cpp:902 (25)
//         00534306     MOV        EDX,dword ptr [ESI + 0x18]
//         00534309     MOV        EAX,dword ptr [ESI + 0x14]
//         0053430c     MOV        this,dword ptr [ESI + 0x338]
//         00534312     DEC        EDX
//         00534313     DEC        EAX
//         00534314     PUSH       EDX
//         00534315     PUSH       EAX
//         00534316     PUSH       0x0
//         00534318     PUSH       0x0
//         0053431a     CALL       DClipInfo_List::SetDrawRegion                    void SetDrawRegion(DClipInfo_List * this, int
//                               LAB_0053431f                                                 XREF[2]:     005341da(j), 005341e5(j)
//                              view.cpp:907 (10)
//         0053431f     MOV        this,dword ptr [ESI + 0x324]
//         00534325     XOR        EAX,EAX
//         00534327     TEST       this,this
//                              view.cpp:908 (20)
//         00534329     MOV        this,dword ptr [ESP + local_c]
//         0053432d     POP        EDI
//         0053432e     SETNZ      AL
//         00534331     MOV        dword ptr FS:[0x0],this
//         00534338     POP        ESI
//         00534339     ADD        ESP,0x10
//         0053433c     RET
//         0053433d     ??         90h
//         0053433e     NOP
//         0053433f     NOP
    return 0;
}

void RGE_View::calc_draw_vars() {
    /* TODO: Stub */
//                              void __thiscall calc_draw_vars(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?calc_draw_vars@RGE_View@@IAEXXZ                             XREF[3]:     set_rect:00533fa8(c),
//                               RGE_View::calc_draw_vars                                                  set_world:005344b7(c),
//                                                                                                         set_world:005344eb(c)
//                              view.cpp:916 (41)
//         00534340     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00534343     PUSH       EBX
//         00534344     PUSH       EBP
//         00534345     XOR        EBP,EBP
//         00534347     PUSH       ESI
//         00534348     CMP        EAX,EBP
//         0053434a     PUSH       EDI
//         0053434b     JZ         LAB_005343dc
//         00534351     MOV        AX,word ptr [ECX + this->tile_wid]
//         00534358     CMP        AX,BP
//         0053435b     JZ         LAB_005343dc
//         0053435d     MOV        BX,word ptr [ECX + this->tile_hgt]
//         00534364     CMP        BX,BP
//         00534367     JZ         LAB_005343dc
//                              view.cpp:932 (3)
//         00534369     MOV        ESI,dword ptr [ECX + this->_padding_]
//                              view.cpp:940 (12)
//         0053436c     MOV        word ptr [ECX + this->center_scr_col_offset],BP
//         00534373     MOVSX      EDI,AX
//         00534376     MOV        EAX,ESI
//                              view.cpp:941 (95)
//         00534378     MOV        word ptr [ECX + this->center_scr_row_offset],BP
//         0053437f     CDQ
//         00534380     IDIV       EDI
//         00534382     MOV        EDI,dword ptr [ECX + this->_padding_]
//         00534385     MOVSX      EBX,BX
//         00534388     MOV        word ptr [ECX + this->max_col_num],AX
//         0053438f     MOV        EAX,EDI
//         00534391     CDQ
//         00534392     IDIV       EBX
//         00534394     MOV        BX,word ptr [ECX + this->_padding_]
//         0053439b     SUB        BX,word ptr [ECX + this->tile_half_wid]
//         005343a2     MOV        word ptr [ECX + this->max_row_num],AX
//         005343a9     MOV        EAX,ESI
//         005343ab     CDQ
//         005343ac     SUB        EAX,EDX
//         005343ae     MOV        SI,word ptr [ECX + this->_padding_]
//         005343b5     SAR        EAX,0x1
//         005343b7     SUB        SI,word ptr [ECX + this->tile_half_hgt]
//         005343be     ADD        EBX,EAX
//         005343c0     MOV        EAX,EDI
//         005343c2     MOV        word ptr [ECX + this->center_scr_col],BX
//         005343c9     CDQ
//         005343ca     SUB        EAX,EDX
//         005343cc     SAR        EAX,0x1
//         005343ce     ADD        ESI,EAX
//         005343d0     MOV        word ptr [ECX + this->center_scr_row],SI
//                              view.cpp:942 (66)
//         005343d7     POP        EDI
//         005343d8     POP        ESI
//         005343d9     POP        EBP
//         005343da     POP        EBX
//         005343db     RET
//                               LAB_005343dc                                                 XREF[3]:     0053434b(j), 0053435b(j),
//                                                                                                         00534367(j)
//         005343dc     POP        EDI
//         005343dd     MOV        word ptr [ECX + this->max_row_num],BP
//         005343e4     MOV        word ptr [ECX + this->max_col_num],BP
//         005343eb     MOV        word ptr [ECX + this->center_scr_col],BP
//         005343f2     MOV        word ptr [ECX + this->center_scr_row],BP
//         005343f9     MOV        word ptr [ECX + this->center_map_col],BP
//         00534400     MOV        word ptr [ECX + this->center_map_row],BP
//         00534407     MOV        word ptr [ECX + this->center_scr_col_offset],BP
//         0053440e     MOV        word ptr [ECX + this->center_scr_row_offset],BP
//         00534415     POP        ESI
//         00534416     POP        EBP
//         00534417     POP        EBX
//         00534418     RET
//         00534419     ??         90h
//         0053441a     NOP
//         0053441b     NOP
//         0053441c     NOP
//         0053441d     NOP
//         0053441e     NOP
//         0053441f     NOP
    return;
}

void RGE_View::set_redraw(RedrawMode param_1) {
    /* TODO: Stub */
//                              void __thiscall set_redraw(RGE_View * this, RedrawMode param_1)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RedrawMode        Stack[0x4]:4   param_1                   XREF[1]:     00534422(R)
//                               ?set_redraw@RGE_View@@UAEXW4RedrawMode@TPanel@@@Z            XREF[3]:     00572ac8(*), 005775d8(*),
//                               RGE_View::set_redraw                                                      00577810(*)
//                              view.cpp:948 (2)
//         00534420     PUSH       ESI
//         00534421     PUSH       EDI
//                              view.cpp:949 (12)
//         00534422     MOV        EDI,dword ptr [ESP + param_1]
//         00534426     MOV        ESI,this
//         00534428     PUSH       EDI
//         00534429     CALL       TPanel::set_redraw                               void set_redraw(TPanel * this, RedrawMode par
//                              view.cpp:950 (5)
//         0053442e     CMP        EDI,0x2
//         00534431     JNZ        LAB_0053443a
//                              view.cpp:951 (7)
//         00534433     MOV        byte ptr [ESI + 0x142],0x0
//                               LAB_0053443a                                                 XREF[1]:     00534431(j)
//                              view.cpp:952 (5)
//         0053443a     POP        EDI
//         0053443b     POP        ESI
//         0053443c     RET        0x4
//         0053443f     ??         90h
    return;
}

void RGE_View::set_world(RGE_Game_World* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_world(RGE_View * this, RGE_Game_World * param_1)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Game_World    Stack[0x4]:4   param_1                   XREF[1]:     00534440(R)
//                               ?set_world@RGE_View@@QAEXPAVRGE_Game_World@@@Z               XREF[2]:     TRIBE_Screen_Game:00494307(c),
//                               RGE_View::set_world                                                       set_panel_info:004a8780(c)
//                              view.cpp:958 (7)
//         00534440     MOV        EAX,dword ptr [ESP + param_1]
//         00534444     PUSH       ESI
//         00534445     MOV        ESI,this
//                              view.cpp:961 (12)
//         00534447     XOR        this,this
//         00534449     CMP        EAX,this
//         0053444b     MOV        dword ptr [ESI + 0xfc],EAX
//         00534451     JZ         LAB_005344c0
//                              view.cpp:963 (9)
//         00534453     MOV        this,dword ptr [EAX + 0x28]
//         00534456     MOV        dword ptr [ESI + 0x104],this
//                              view.cpp:965 (5)
//         0053445c     CALL       RGE_Map::coordinate_map                          void coordinate_map(RGE_Map * this)
//                              view.cpp:967 (6)
//         00534461     MOV        EAX,dword ptr [ESI + 0x104]
//                              view.cpp:968 (23)
//         00534467     MOV        EDX,EAX
//         00534469     MOV        this,word ptr [EAX + 0x8d96]
//         00534470     MOV        word ptr [ESI + 0x108],this
//         00534477     MOV        AX,word ptr [EDX + 0x8d98]
//                              view.cpp:969 (9)
//         0053447e     MOV        this,EDX
//         00534480     MOV        word ptr [ESI + 0x10a],AX
//                              view.cpp:970 (23)
//         00534487     MOV        EAX,this
//         00534489     MOV        DX,word ptr [this->_padding_ + 0x8d9c]
//         00534490     MOV        word ptr [ESI + 0x10c],DX
//         00534497     MOV        this,word ptr [EAX + 0x8d9a]
//                              view.cpp:971 (9)
//         0053449e     MOV        EDX,EAX
//         005344a0     MOV        word ptr [ESI + 0x10e],this
//                              view.cpp:985 (21)
//         005344a7     MOV        this,ESI
//         005344a9     MOV        AX,word ptr [EDX + 0x8d9e]
//         005344b0     MOV        word ptr [ESI + 0x110],AX
//         005344b7     CALL       RGE_View::calc_draw_vars                         void calc_draw_vars(RGE_View * this)
//                              view.cpp:986 (4)
//         005344bc     POP        ESI
//         005344bd     RET        0x4
//                               LAB_005344c0                                                 XREF[1]:     00534451(j)
//                              view.cpp:975 (6)
//         005344c0     MOV        dword ptr [ESI + 0x104],this
//                              view.cpp:976 (7)
//         005344c6     MOV        word ptr [ESI + 0x108],this
//                              view.cpp:977 (7)
//         005344cd     MOV        word ptr [ESI + 0x10a],this
//                              view.cpp:978 (7)
//         005344d4     MOV        word ptr [ESI + 0x10c],this
//                              view.cpp:979 (7)
//         005344db     MOV        word ptr [ESI + 0x10e],this
//                              view.cpp:980 (7)
//         005344e2     MOV        word ptr [ESI + 0x110],this
//                              view.cpp:985 (7)
//         005344e9     MOV        this,ESI
//         005344eb     CALL       RGE_View::calc_draw_vars                         void calc_draw_vars(RGE_View * this)
//                              view.cpp:986 (4)
//         005344f0     POP        ESI
//         005344f1     RET        0x4
//         005344f4     ??         90h
//         005344f5     NOP
//         005344f6     NOP
//         005344f7     NOP
//         005344f8     NOP
//         005344f9     NOP
//         005344fa     NOP
//         005344fb     NOP
//         005344fc     NOP
//         005344fd     NOP
//         005344fe     NOP
//         005344ff     NOP
    return;
}

void RGE_View::set_player(RGE_Player* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_player(RGE_View * this, RGE_Player * param_1)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Player *      Stack[0x4]:4   param_1                   XREF[1]:     00534500(R)
//                               ?set_player@RGE_View@@QAEXPAVRGE_Player@@@Z                  XREF[4]:     TRIBE_Screen_Game:0049431e(c),
//                               RGE_View::set_player                                                      player_changed:00498a85(c),
//                                                                                                         set_panel_info:004a8797(c),
//                                                                                                         set_unit_player:004ab384(c)
//                              view.cpp:992 (4)
//         00534500     MOV        EAX,dword ptr [ESP + param_1]
//                              view.cpp:998 (30)
//         00534504     MOV        EDX,dword ptr [this->_padding_]
//         00534506     MOV        dword ptr [ECX + this->player],EAX
//         0053450c     MOV        EAX,0xc61c3c00
//         00534511     PUSH       0x2
//         00534513     MOV        dword ptr [ECX + this->last_view_x],EAX
//         00534519     MOV        dword ptr [ECX + this->last_view_y],EAX
//         0053451f     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:999 (3)
//         00534522     RET        0x4
//         00534525     ??         90h
//         00534526     NOP
//         00534527     NOP
//         00534528     NOP
//         00534529     NOP
//         0053452a     NOP
//         0053452b     NOP
//         0053452c     NOP
//         0053452d     NOP
//         0053452e     NOP
//         0053452f     NOP
    return;
}

void RGE_View::set_selection_area(long param_1, long param_2, long param_3, long param_4) {
    /* TODO: Stub */
//                              void __thiscall set_selection_area(RGE_View * this, long param_1, lo
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     00534577(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053457b(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0053457f(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     00534583(R)
//                               ?set_selection_area@RGE_View@@QAEXJJJJ@Z                     XREF[15]:    game_mode_changed:0048a55e(c),
//                               RGE_View::set_selection_area                                              handle_game_update:00496a2b(c),
//                                                                                                         handle_game_update:00497071(c),
//                                                                                                         object_changed:00499363(c),
//                                                                                                         command_cancel:0049bef4(c),
//                                                                                                         load_victory_cond_from_scenario:00
//                                                                                                         load_victory_cond_from_scenario:00
//                                                                                                         command_place_multi_object:0052d4d
//                                                                                                         RGE_View:00533643(c),
//                                                                                                         draw_paint_brush:005358be(c),
//                                                                                                         draw_paint_brush:005359cc(c),
//                                                                                                         start_scroll_view:0053a12c(c),
//                                                                                                         handle_scroll_view:0053a883(c),
//                                                                                                         mouse_right_up_action:0053f5ee(c),
//                                                                                                         command_place_multi_object:005405c
//                              view.cpp:1005 (6)
//         00534530     PUSH       EBX
//         00534531     PUSH       EBP
//         00534532     PUSH       ESI
//         00534533     MOV        ESI,this
//         00534535     PUSH       EDI
//                              view.cpp:1009 (24)
//         00534536     MOV        this,dword ptr [ESI + 0x104]
//         0053453c     TEST       this,this
//         0053453e     JZ         LAB_00534571
//         00534540     MOV        EAX,[rge_base_game]                              = 00000000
//         00534545     CMP        dword ptr [EAX + 0x1b4],0x15
//         0053454c     JZ         LAB_00534571
//                              view.cpp:1010 (35)
//         0053454e     MOV        EDX,dword ptr [ESI + 0x150]
//         00534554     MOV        EAX,dword ptr [ESI + 0x14c]
//         0053455a     PUSH       0x0
//         0053455c     PUSH       EDX
//         0053455d     MOV        EDX,dword ptr [ESI + 0x148]
//         00534563     PUSH       EAX
//         00534564     MOV        EAX,dword ptr [ESI + 0x144]
//         0053456a     PUSH       EDX
//         0053456b     PUSH       EAX
//         0053456c     CALL       RGE_Map::request_redraw                          void request_redraw(RGE_Map * this, int param
//                               LAB_00534571                                                 XREF[2]:     0053453e(j), 0053454c(j)
//                              view.cpp:1017 (65)
//         00534571     MOV        this,dword ptr [ESI + 0x104]
//         00534577     MOV        EAX,dword ptr [ESP + param_1]
//         0053457b     MOV        EDX,dword ptr [ESP + param_2]
//         0053457f     MOV        EDI,dword ptr [ESP + param_3]
//         00534583     MOV        EBX,dword ptr [ESP + param_4]
//         00534587     MOV        dword ptr [ESI + 0x144],EAX
//         0053458d     TEST       this,this
//         0053458f     MOV        dword ptr [ESI + 0x148],EDX
//         00534595     MOV        dword ptr [ESI + 0x14c],EDI
//         0053459b     MOV        dword ptr [ESI + 0x150],EBX
//         005345a1     JZ         LAB_005345bd
//         005345a3     MOV        EBP,dword ptr [rge_base_game]                    = 00000000
//         005345a9     CMP        dword ptr [EBP + 0x1b4],0x15
//         005345b0     JZ         LAB_005345bd
//                              view.cpp:1018 (11)
//         005345b2     PUSH       0x10
//         005345b4     PUSH       EBX
//         005345b5     PUSH       EDI
//         005345b6     PUSH       EDX
//         005345b7     PUSH       EAX
//         005345b8     CALL       RGE_Map::request_redraw                          void request_redraw(RGE_Map * this, int param
//                               LAB_005345bd                                                 XREF[2]:     005345a1(j), 005345b0(j)
//                              view.cpp:1020 (9)
//         005345bd     MOV        EDX,dword ptr [ESI]
//         005345bf     PUSH       0x1
//         005345c1     MOV        this,ESI
//         005345c3     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:1022 (7)
//         005345c6     POP        EDI
//         005345c7     POP        ESI
//         005345c8     POP        EBP
//         005345c9     POP        EBX
//         005345ca     RET        0x10
//         005345cd     ??         90h
//         005345ce     NOP
//         005345cf     NOP
    return;
}

int RGE_View::get_selection_area(long* param_1, long* param_2, long* param_3, long* param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall get_selection_area(RGE_View * this, long * param_1, l
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              long *            Stack[0x4]:4   param_1                   XREF[1]:     005345e2(R)
//              long *            Stack[0x8]:4   param_2                   XREF[1]:     005345d8(R)
//              long *            Stack[0xc]:4   param_3                   XREF[2]:     005345dd(R), 005346c7(R)
//              long *            Stack[0x10]:4  param_4                   XREF[2]:     005345e6(R), 005346d3(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053469b(R)
//                               ?get_selection_area@RGE_View@@QAEHAAJ000H@Z                  XREF[7]:     draw_selected_area:00437c46(c),
//                               RGE_View::get_selection_area                                              key_down_action:0048a408(c),
//                                                                                                         key_down_action:0048a48b(c),
//                                                                                                         action:004ac2fa(c),
//                                                                                                         save_victory_cond_in_scenario:004a
//                                                                                                         draw_multi_object_outline:0052cb4e
//                                                                                                         view_function:00536125(c)
//                              view.cpp:1028 (8)
//         005345d0     MOV        EAX,dword ptr [ECX + this->sel_col1]
//         005345d6     PUSH       EBX
//         005345d7     PUSH       EBP
//                              view.cpp:1032 (5)
//         005345d8     MOV        EBP,dword ptr [ESP + param_2]
//         005345dc     PUSH       ESI
//                              view.cpp:1033 (9)
//         005345dd     MOV        ESI,dword ptr [ESP + param_3]
//         005345e1     PUSH       EDI
//         005345e2     MOV        EDI,dword ptr [ESP + param_1]
//                              view.cpp:1034 (31)
//         005345e6     MOV        EBX,dword ptr [ESP + param_4]
//         005345ea     MOV        dword ptr [EDI],EAX
//         005345ec     MOV        EDX,dword ptr [ECX + this->sel_row1]
//         005345f2     MOV        dword ptr [EBP],EDX
//         005345f5     MOV        EAX,dword ptr [ECX + this->sel_col2]
//         005345fb     MOV        dword ptr [ESI],EAX
//         005345fd     MOV        EDX,dword ptr [ECX + this->sel_row2]
//         00534603     MOV        dword ptr [EBX],EDX
//                              view.cpp:1037 (20)
//         00534605     MOV        EAX,dword ptr [EDI]
//         00534607     CMP        EAX,-0x1
//         0053460a     JNZ        LAB_00534622
//         0053460c     CMP        dword ptr [EBP],EAX
//         0053460f     JNZ        LAB_00534622
//         00534611     CMP        dword ptr [ESI],EAX
//         00534613     JNZ        LAB_00534622
//         00534615     CMP        EDX,EAX
//         00534617     JNZ        LAB_00534622
//                              view.cpp:1038 (2)
//         00534619     XOR        EAX,EAX
//                              view.cpp:1077 (7)
//         0053461b     POP        EDI
//         0053461c     POP        ESI
//         0053461d     POP        EBP
//         0053461e     POP        EBX
//         0053461f     RET        0x14
//                               LAB_00534622                                                 XREF[4]:     0053460a(j), 0053460f(j),
//                                                                                                         00534613(j), 00534617(j)
//                              view.cpp:1041 (4)
//         00534622     TEST       EAX,EAX
//         00534624     JGE        LAB_0053462e
//                              view.cpp:1042 (6)
//         00534626     MOV        dword ptr [EDI],0x0
//                              view.cpp:1043 (15)
//         0053462c     JMP        LAB_0053463e
//                               LAB_0053462e                                                 XREF[1]:     00534624(j)
//         0053462e     MOV        EDX,dword ptr [ECX + this->map]
//         00534634     MOV        EDX,dword ptr [EDX + 0x8]
//         00534637     CMP        EAX,EDX
//         00534639     JL         LAB_0053463e
//                              view.cpp:1044 (3)
//         0053463b     DEC        EDX
//         0053463c     MOV        dword ptr [EDI],EDX
//                               LAB_0053463e                                                 XREF[2]:     0053462c(j), 00534639(j)
//                              view.cpp:1046 (7)
//         0053463e     MOV        EAX,dword ptr [EBP]
//         00534641     TEST       EAX,EAX
//         00534643     JGE        LAB_0053464e
//                              view.cpp:1047 (7)
//         00534645     MOV        dword ptr [EBP],0x0
//                              view.cpp:1048 (15)
//         0053464c     JMP        LAB_0053465f
//                               LAB_0053464e                                                 XREF[1]:     00534643(j)
//         0053464e     MOV        EDX,dword ptr [ECX + this->map]
//         00534654     MOV        EDX,dword ptr [EDX + 0xc]
//         00534657     CMP        EAX,EDX
//         00534659     JL         LAB_0053465f
//                              view.cpp:1049 (4)
//         0053465b     DEC        EDX
//         0053465c     MOV        dword ptr [EBP],EDX
//                               LAB_0053465f                                                 XREF[2]:     0053464c(j), 00534659(j)
//                              view.cpp:1051 (6)
//         0053465f     MOV        EAX,dword ptr [ESI]
//         00534661     TEST       EAX,EAX
//         00534663     JGE        LAB_0053466d
//                              view.cpp:1052 (6)
//         00534665     MOV        dword ptr [ESI],0x0
//                              view.cpp:1053 (15)
//         0053466b     JMP        LAB_0053467d
//                               LAB_0053466d                                                 XREF[1]:     00534663(j)
//         0053466d     MOV        EDX,dword ptr [ECX + this->map]
//         00534673     MOV        EDX,dword ptr [EDX + 0x8]
//         00534676     CMP        EAX,EDX
//         00534678     JL         LAB_0053467d
//                              view.cpp:1054 (3)
//         0053467a     DEC        EDX
//         0053467b     MOV        dword ptr [ESI],EDX
//                               LAB_0053467d                                                 XREF[2]:     0053466b(j), 00534678(j)
//                              view.cpp:1056 (6)
//         0053467d     MOV        EAX,dword ptr [EBX]
//         0053467f     TEST       EAX,EAX
//         00534681     JGE        LAB_0053468b
//                              view.cpp:1057 (6)
//         00534683     MOV        dword ptr [EBX],0x0
//                              view.cpp:1058 (15)
//         00534689     JMP        LAB_0053469b
//                               LAB_0053468b                                                 XREF[1]:     00534681(j)
//         0053468b     MOV        this,dword ptr [ECX + this->map]
//         00534691     MOV        this,dword ptr [ECX + this->_padding_]
//         00534694     CMP        EAX,this
//         00534696     JL         LAB_0053469b
//                              view.cpp:1059 (3)
//         00534698     DEC        this
//         00534699     MOV        dword ptr [EBX],this
//                               LAB_0053469b                                                 XREF[2]:     00534689(j), 00534696(j)
//                              view.cpp:1063 (8)
//         0053469b     MOV        EAX,dword ptr [ESP + param_5]
//         0053469f     TEST       EAX,EAX
//         005346a1     JZ         LAB_005346d9
//                              view.cpp:1065 (2)
//         005346a3     MOV        EAX,dword ptr [EDI]
//                              view.cpp:1067 (2)
//         005346a5     MOV        this,dword ptr [ESI]
//                              view.cpp:1068 (5)
//         005346a7     MOV        ESI,dword ptr [EBX]
//         005346a9     MOV        EDX,dword ptr [EBP]
//                              view.cpp:1070 (10)
//         005346ac     CMP        EAX,this
//         005346ae     MOV        EBX,EAX
//         005346b0     JL         LAB_005346b4
//         005346b2     MOV        EBX,this
//                               LAB_005346b4                                                 XREF[1]:     005346b0(j)
//         005346b4     MOV        dword ptr [EDI],EBX
//                              view.cpp:1071 (8)
//         005346b6     CMP        EDX,ESI
//         005346b8     MOV        EDI,EDX
//         005346ba     JL         LAB_005346be
//         005346bc     MOV        EDI,ESI
//                               LAB_005346be                                                 XREF[1]:     005346ba(j)
//                              view.cpp:1072 (13)
//         005346be     CMP        EAX,this
//         005346c0     MOV        dword ptr [EBP],EDI
//         005346c3     JG         LAB_005346c7
//         005346c5     MOV        EAX,this
//                               LAB_005346c7                                                 XREF[1]:     005346c3(j)
//         005346c7     MOV        this,dword ptr [ESP + param_3]
//                              view.cpp:1073 (14)
//         005346cb     CMP        EDX,ESI
//         005346cd     MOV        dword ptr [this->_padding_],EAX
//         005346cf     JG         LAB_005346d3
//         005346d1     MOV        EDX,ESI
//                               LAB_005346d3                                                 XREF[1]:     005346cf(j)
//         005346d3     MOV        EAX,dword ptr [ESP + param_4]
//         005346d7     MOV        dword ptr [EAX],EDX
//                               LAB_005346d9                                                 XREF[1]:     005346a1(j)
//                              view.cpp:1077 (12)
//         005346d9     POP        EDI
//         005346da     POP        ESI
//         005346db     POP        EBP
//         005346dc     MOV        EAX,0x1
//         005346e1     POP        EBX
//         005346e2     RET        0x14
//         005346e5     ??         90h
//         005346e6     NOP
//         005346e7     NOP
//         005346e8     NOP
//         005346e9     NOP
//         005346ea     NOP
//         005346eb     NOP
//         005346ec     NOP
//         005346ed     NOP
//         005346ee     NOP
//         005346ef     NOP
    return 0;
}

void RGE_View::CreateBlitQueue(tagRECT* param_1, tagRECT* param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall CreateBlitQueue(RGE_View * this, tagRECT * param_1,
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              tagRECT *         Stack[0x4]:4   param_1                   XREF[8]:     00534715(R), 005347a1(R), 005347b0(R), 00534825(R),
//                                                                                     00534860(R), 00534894(R), 00534979(R), 00534994(R)
//              tagRECT *         Stack[0x8]:4   param_2                   XREF[7]:     00534719(R), 00534740(R), 00534757(R), 005348cd(R),
//                                                                                     005348fa(W), 005349aa(R), 005349b2(W)
//              int               Stack[0xc]:4   param_3                   XREF[6]:     005346f3(R), 00534775(R), 0053479d(R), 005347fd(R),
//                                                                                     0053492d(R), 0053494f(R)
//              int               Stack[0x10]:4  param_4                   XREF[4]:     005346f9(R), 005347dd(R), 0053490e(R), 0053493d(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0053482d(R)
//              tagRECT           Stack[-0x14]   blt_src                   XREF[2,10]:  00534736(W), 0053481b(R), 005347ba(W), 00534815(W),
//                                                                                     00534908(R), 00534929(R), 00534965(R), 00534975(W),
//                                                                                     00534988(R), 00534990(W), 00534831(R), 00534829(R)
//              undefined4        Stack[-0x18]:4 local_18                  XREF[2]:     0053475b(W), 0053480d(R)
//              undefined4        Stack[-0x1c]:4 local_1c                  XREF[2]:     00534725(W), 005347f3(R)
//              undefined4        Stack[-0x20]:4 local_20                  XREF[2]:     00534747(W), 005347e9(R)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[3]:     005347c9(W), 00534807(W), 0053496d(R)
//              int               Stack[-0x28]:4 blt_deltaX                XREF[3]:     005347cd(W), 005347e3(W), 00534961(R)
//              int               Stack[-0x2c]:4 blt_deltaY                XREF[3]:     00534703(W), 0053483a(W), 0053489e(R)
//              int               Stack[-0x30]:4 One_Blit                  XREF[3]:     0053478a(W), 00534799(W), 005347d1(R)
//              int               Stack[-0x34]:4 vBlits                    XREF[10]:    00534779(W), 00534795(R), 005347d9(W), 00534801(W),
//                                                                                     0053483e(W), 00534842(R), 0053487b(R), 00534887(R),
//                                                                                     005348ec(R), 005349bc(R)
//              int               Stack[-0x38]:4 yd
//                               ?CreateBlitQueue@RGE_View@@IAEXAAUtagRECT@@0HH@Z             XREF[1]:     draw:00534da0(c)
//                               RGE_View::CreateBlitQueue
//                              view.cpp:1085 (3)
//         005346f0     SUB        ESP,0x34
//                              view.cpp:1093 (34)
//         005346f3     MOV        EAX,dword ptr [ESP + param_3]
//         005346f7     PUSH       EBX
//         005346f8     PUSH       EBP
//         005346f9     MOV        EBP,dword ptr [ESP + param_4]
//         005346fd     PUSH       ESI
//         005346fe     PUSH       EDI
//         005346ff     TEST       EAX,EAX
//         00534701     MOV        ESI,this
//         00534703     MOV        dword ptr [ESP + blt_deltaY],0x0
//         0053470b     JNZ        LAB_00534715
//         0053470d     TEST       EBP,EBP
//         0053470f     JZ         LAB_005349f2
//                               LAB_00534715                                                 XREF[1]:     0053470b(j)
//                              view.cpp:1098 (82)
//         00534715     MOV        EDX,dword ptr [ESP + param_1]
//         00534719     MOV        EAX,dword ptr [ESP + param_2]
//         0053471d     MOV        EBX,dword ptr [EDX + 0x4]
//         00534720     MOV        this,dword ptr [EAX + 0xc]
//         00534723     CMP        EBX,this
//         00534725     MOV        dword ptr [ESP + local_1c],EBX
//         00534729     JG         LAB_00534829
//         0053472f     MOV        this,dword ptr [EDX]
//         00534731     MOV        EDI,dword ptr [EAX + 0x8]
//         00534734     CMP        this,EDI
//         00534736     MOV        dword ptr [ESP + blt_src.left],this
//         0053473a     JG         LAB_00534829
//         00534740     MOV        EDI,dword ptr [ESP + param_2]
//         00534744     MOV        EAX,dword ptr [EDX + 0xc]
//         00534747     MOV        dword ptr [ESP + local_20],EAX
//         0053474b     CMP        EAX,dword ptr [EDI + 0x4]
//         0053474e     JL         LAB_00534829
//         00534754     MOV        EDI,dword ptr [EDX + 0x8]
//         00534757     MOV        EDX,dword ptr [ESP + param_2]
//         0053475b     MOV        dword ptr [ESP + local_18],EDI
//         0053475f     CMP        EDI,dword ptr [EDX]
//         00534761     JL         LAB_00534825
//                              view.cpp:1108 (2)
//         00534767     SUB        EDI,this
//                              view.cpp:1109 (4)
//         00534769     SUB        EAX,EBX
//         0053476b     INC        EDI
//         0053476c     INC        EAX
//                              view.cpp:1111 (8)
//         0053476d     TEST       EBP,EBP
//         0053476f     MOV        EDX,EBP
//         00534771     JGE        LAB_00534775
//         00534773     NEG        EDX
//                               LAB_00534775                                                 XREF[1]:     00534771(j)
//                              view.cpp:1112 (14)
//         00534775     MOV        EBX,dword ptr [ESP + param_3]
//         00534779     MOV        dword ptr [ESP + vBlits],EDX
//         0053477d     TEST       EBX,EBX
//         0053477f     JGE        LAB_00534783
//         00534781     NEG        EBX
//                               LAB_00534783                                                 XREF[1]:     0053477f(j)
//                              view.cpp:1115 (5)
//         00534783     MOV        this,0x270f
//                              view.cpp:1118 (21)
//         00534788     TEST       EBP,EBP
//         0053478a     MOV        dword ptr [ESP + One_Blit],this
//         0053478e     JZ         LAB_0053479d
//         00534790     LEA        EAX,[EDX + EAX*0x1 + -0x1]
//         00534794     CDQ
//         00534795     IDIV       dword ptr [ESP + vBlits]
//         00534799     MOV        dword ptr [ESP + One_Blit],EAX
//                               LAB_0053479d                                                 XREF[1]:     0053478e(j)
//                              view.cpp:1119 (25)
//         0053479d     MOV        EAX,dword ptr [ESP + param_3]
//         005347a1     MOV        EDX,dword ptr [ESP + param_1]
//         005347a5     TEST       EAX,EAX
//         005347a7     JZ         LAB_005347b6
//         005347a9     LEA        EAX,[EBX + EDI*0x1 + -0x1]
//         005347ad     CDQ
//         005347ae     IDIV       EBX
//         005347b0     MOV        EDX,dword ptr [ESP + param_1]
//         005347b4     MOV        this,EAX
//                               LAB_005347b6                                                 XREF[1]:     005347a7(j)
//                              view.cpp:1121 (17)
//         005347b6     MOV        EAX,EDX
//         005347b8     MOV        EDI,dword ptr [EAX]
//         005347ba     MOV        dword ptr [ESP + blt_src.top],EDI
//         005347be     MOV        EDI,dword ptr [EAX + 0x4]
//         005347c1     MOV        EBP,dword ptr [EAX + 0x8]
//         005347c4     MOV        EBX,dword ptr [EAX + 0xc]
//                              view.cpp:1123 (6)
//         005347c7     XOR        EAX,EAX
//         005347c9     MOV        dword ptr [ESP + local_24],EAX
//                              view.cpp:1124 (4)
//         005347cd     MOV        dword ptr [ESP + blt_deltaX],EAX
//                              view.cpp:1126 (8)
//         005347d1     MOV        EAX,dword ptr [ESP + One_Blit]
//         005347d5     CMP        EAX,this
//         005347d7     JGE        LAB_005347fd
//                              view.cpp:1128 (4)
//         005347d9     MOV        dword ptr [ESP + vBlits],EAX
//                              view.cpp:1129 (4)
//         005347dd     MOV        EAX,dword ptr [ESP + param_4]
//                              view.cpp:1131 (8)
//         005347e1     TEST       EAX,EAX
//         005347e3     MOV        dword ptr [ESP + blt_deltaX],EAX
//         005347e7     JGE        LAB_005347f3
//                              view.cpp:1133 (8)
//         005347e9     MOV        this,dword ptr [ESP + local_20]
//         005347ed     LEA        EDI,[EAX + this->_padding_*0x1 + 0x1]
//                              view.cpp:1135 (2)
//         005347f1     JMP        LAB_00534842
//                               LAB_005347f3                                                 XREF[1]:     005347e7(j)
//                              view.cpp:1137 (8)
//         005347f3     MOV        this,dword ptr [ESP + local_1c]
//         005347f7     LEA        EBX,[EAX + this->_padding_*0x1 + -0x1]
//                              view.cpp:1140 (2)
//         005347fb     JMP        LAB_00534842
//                               LAB_005347fd                                                 XREF[1]:     005347d7(j)
//                              view.cpp:1143 (8)
//         005347fd     MOV        EAX,dword ptr [ESP + param_3]
//         00534801     MOV        dword ptr [ESP + vBlits],this
//                              view.cpp:1145 (8)
//         00534805     TEST       EAX,EAX
//         00534807     MOV        dword ptr [ESP + local_24],EAX
//         0053480b     JGE        LAB_0053481b
//                              view.cpp:1147 (12)
//         0053480d     MOV        this,dword ptr [ESP + local_18]
//         00534811     LEA        EAX,[EAX + this->_padding_*0x1 + 0x1]
//         00534815     MOV        dword ptr [ESP + blt_src.top],EAX
//                              view.cpp:1149 (2)
//         00534819     JMP        LAB_00534842
//                               LAB_0053481b                                                 XREF[1]:     0053480b(j)
//                              view.cpp:1151 (10)
//         0053481b     MOV        this,dword ptr [ESP + blt_src.left]
//         0053481f     LEA        EBP,[EAX + this->_padding_*0x1 + -0x1]
//         00534823     JMP        LAB_00534842
//                               LAB_00534825                                                 XREF[1]:     00534761(j)
//                              view.cpp:1140 (4)
//         00534825     MOV        EDX,dword ptr [ESP + param_1]
//                               LAB_00534829                                                 XREF[3]:     00534729(j), 0053473a(j),
//                                                                                                         0053474e(j)
//                              view.cpp:1101 (25)
//         00534829     MOV        EBP,dword ptr [ESP + blt_src.bottom]
//         0053482d     MOV        EBX,dword ptr [ESP + local_4]
//         00534831     MOV        EDI,dword ptr [ESP + blt_src.right]
//         00534835     MOV        EAX,0x1
//         0053483a     MOV        dword ptr [ESP + blt_deltaY],EAX
//         0053483e     MOV        dword ptr [ESP + vBlits],EAX
//                              Symbol Ref: No symbol: CBQ_One
//                               LAB_00534842                                                 XREF[4]:     005347f1(j), 005347fb(j),
//                                                                                                         00534819(j), 00534823(j)
//                              view.cpp:1159 (14)
//         00534842     MOV        EAX,dword ptr [ESP + vBlits]
//         00534846     MOV        this,dword ptr [ESI + 0x2e4]
//         0053484c     CMP        EAX,this
//         0053484e     JLE        LAB_00534871
//                              view.cpp:1161 (23)
//         00534850     MOV        EAX,dword ptr [ESI + 0x2dc]
//         00534856     TEST       EAX,EAX
//         00534858     JZ         LAB_00534867
//         0053485a     PUSH       EAX
//         0053485b     CALL       free                                             undefined free()
//         00534860     MOV        EDX,dword ptr [ESP + param_1]
//         00534864     ADD        ESP,0x4
//                               LAB_00534867                                                 XREF[1]:     00534858(j)
//                              view.cpp:1162 (10)
//         00534867     MOV        dword ptr [ESI + 0x2dc],0x0
//                               LAB_00534871                                                 XREF[1]:     0053484e(j)
//                              view.cpp:1165 (10)
//         00534871     MOV        EAX,dword ptr [ESI + 0x2dc]
//         00534877     TEST       EAX,EAX
//         00534879     JNZ        LAB_0053489e
//                              view.cpp:1167 (12)
//         0053487b     MOV        this,dword ptr [ESP + vBlits]
//         0053487f     PUSH       0x20
//         00534881     PUSH       this
//         00534882     CALL       calloc                                           undefined calloc()
//                              view.cpp:1168 (23)
//         00534887     MOV        EDX,dword ptr [ESP + vBlits]
//         0053488b     ADD        ESP,0x8
//         0053488e     MOV        dword ptr [ESI + 0x2e4],EDX
//         00534894     MOV        EDX,dword ptr [ESP + param_1]
//         00534898     MOV        dword ptr [ESI + 0x2dc],EAX
//                               LAB_0053489e                                                 XREF[1]:     00534879(j)
//                              view.cpp:1173 (8)
//         0053489e     MOV        EAX,dword ptr [ESP + blt_deltaY]
//         005348a2     TEST       EAX,EAX
//         005348a4     JZ         LAB_005348ec
//                              view.cpp:1175 (28)
//         005348a6     MOV        EAX,dword ptr [ESI + 0x2dc]
//         005348ac     MOV        this,dword ptr [EDX]
//         005348ae     MOV        dword ptr [EAX],this
//         005348b0     MOV        this,dword ptr [EDX + 0x4]
//         005348b3     MOV        dword ptr [EAX + 0x4],this
//         005348b6     MOV        this,dword ptr [EDX + 0x8]
//         005348b9     MOV        dword ptr [EAX + 0x8],this
//         005348bc     MOV        EDX,dword ptr [EDX + 0xc]
//         005348bf     MOV        dword ptr [EAX + 0xc],EDX
//                              view.cpp:1176 (37)
//         005348c2     MOV        EAX,dword ptr [ESI + 0x2dc]
//         005348c8     ADD        EAX,0x10
//         005348cb     MOV        this,EAX
//         005348cd     MOV        EAX,dword ptr [ESP + param_2]
//         005348d1     MOV        EDX,dword ptr [EAX]
//         005348d3     MOV        dword ptr [this->_padding_],EDX
//         005348d5     MOV        EDX,dword ptr [EAX + 0x4]
//         005348d8     MOV        dword ptr [ECX + this->_padding_],EDX
//         005348db     MOV        EDX,dword ptr [EAX + 0x8]
//         005348de     MOV        dword ptr [ECX + this->_padding_],EDX
//         005348e1     MOV        EAX,dword ptr [EAX + 0xc]
//         005348e4     MOV        dword ptr [ECX + this->_padding_],EAX
//                              view.cpp:1178 (5)
//         005348e7     JMP        LAB_005349bc
//                               LAB_005348ec                                                 XREF[1]:     005348a4(j)
//                              view.cpp:1180 (12)
//         005348ec     MOV        this,dword ptr [ESP + vBlits]
//         005348f0     TEST       this,this
//         005348f2     JLE        LAB_005349bc
//                              view.cpp:1211 (140)
//         005348f8     XOR        EAX,EAX
//         005348fa     MOV        dword ptr [ESP + param_2],this
//                               LAB_005348fe                                                 XREF[1]:     005349b6(j)
//         005348fe     MOV        EDX,dword ptr [ESI + 0x2dc]
//         00534904     MOV        this,EAX
//         00534906     ADD        this,EDX
//         00534908     MOV        EDX,dword ptr [ESP + blt_src.top]
//         0053490c     MOV        dword ptr [this->_padding_],EDX
//         0053490e     MOV        EDX,dword ptr [ESP + param_4]
//         00534912     MOV        dword ptr [ECX + this->_padding_],EDI
//         00534915     MOV        dword ptr [ECX + this->_padding_],EBP
//         00534918     MOV        dword ptr [ECX + this->_padding_],EBX
//         0053491b     MOV        this,EDI
//         0053491d     SUB        this,EDX
//         0053491f     MOV        EDX,dword ptr [ESI + 0x2dc]
//         00534925     MOV        dword ptr [EAX + EDX*0x1 + 0x14],this
//         00534929     MOV        this,dword ptr [ESP + blt_src.top]
//         0053492d     MOV        EDX,dword ptr [ESP + param_3]
//         00534931     SUB        this,EDX
//         00534933     MOV        EDX,dword ptr [ESI + 0x2dc]
//         00534939     MOV        dword ptr [EAX + EDX*0x1 + 0x10],this
//         0053493d     MOV        EDX,dword ptr [ESP + param_4]
//         00534941     MOV        this,EBX
//         00534943     SUB        this,EDX
//         00534945     MOV        EDX,dword ptr [ESI + 0x2dc]
//         0053494b     MOV        dword ptr [EAX + EDX*0x1 + 0x1c],this
//         0053494f     MOV        EDX,dword ptr [ESP + param_3]
//         00534953     MOV        this,EBP
//         00534955     SUB        this,EDX
//         00534957     MOV        EDX,dword ptr [ESI + 0x2dc]
//         0053495d     MOV        dword ptr [EAX + EDX*0x1 + 0x18],this
//         00534961     MOV        this,dword ptr [ESP + blt_deltaX]
//         00534965     MOV        EDX,dword ptr [ESP + blt_src.top]
//         00534969     ADD        EDI,this
//         0053496b     ADD        EBX,this
//         0053496d     MOV        this,dword ptr [ESP + local_24]
//         00534971     ADD        EDX,this
//         00534973     ADD        EBP,this
//         00534975     MOV        dword ptr [ESP + blt_src.top],EDX
//         00534979     MOV        EDX,dword ptr [ESP + param_1]
//         0053497d     MOV        this,dword ptr [EDX + 0x4]
//         00534980     CMP        EDI,this
//         00534982     JGE        LAB_00534986
//                              view.cpp:1194 (2)
//         00534984     MOV        EDI,this
//                               LAB_00534986                                                 XREF[1]:     00534982(j)
//                              view.cpp:1195 (14)
//         00534986     MOV        EDX,dword ptr [EDX]
//         00534988     MOV        this,dword ptr [ESP + blt_src.top]
//         0053498c     CMP        this,EDX
//         0053498e     JGE        LAB_00534994
//         00534990     MOV        dword ptr [ESP + blt_src.top],EDX
//                               LAB_00534994                                                 XREF[1]:     0053498e(j)
//                              view.cpp:1196 (13)
//         00534994     MOV        EDX,dword ptr [ESP + param_1]
//         00534998     MOV        this,dword ptr [EDX + 0x8]
//         0053499b     CMP        EBP,this
//         0053499d     JLE        LAB_005349a1
//         0053499f     MOV        EBP,this
//                               LAB_005349a1                                                 XREF[1]:     0053499d(j)
//                              view.cpp:1197 (9)
//         005349a1     MOV        this,dword ptr [EDX + 0xc]
//         005349a4     CMP        EBX,this
//         005349a6     JLE        LAB_005349aa
//         005349a8     MOV        EBX,this
//                               LAB_005349aa                                                 XREF[1]:     005349a6(j)
//                              view.cpp:1180 (18)
//         005349aa     MOV        this,dword ptr [ESP + param_2]
//         005349ae     ADD        EAX,0x20
//         005349b1     DEC        this
//         005349b2     MOV        dword ptr [ESP + param_2],this
//         005349b6     JNZ        LAB_005348fe
//                               LAB_005349bc                                                 XREF[2]:     005348e7(j), 005348f2(j)
//                              view.cpp:1205 (4)
//         005349bc     MOV        EAX,dword ptr [ESP + vBlits]
//                              view.cpp:1208 (6)
//         005349c0     MOV        this,dword ptr [ESI + 0x8c]
//                              view.cpp:1209 (44)
//         005349c6     MOV        EDX,dword ptr [ESI + 0x90]
//         005349cc     MOV        dword ptr [ESI + 0x2d8],0x1
//         005349d6     MOV        dword ptr [ESI + 0x2e0],EAX
//         005349dc     MOV        dword ptr [ESI + 0x2e8],0xffffffff
//         005349e6     MOV        dword ptr [ESI + 0x2ec],this
//         005349ec     MOV        dword ptr [ESI + 0x2f0],EDX
//                               LAB_005349f2                                                 XREF[1]:     0053470f(j)
//                              view.cpp:1211 (10)
//         005349f2     POP        EDI
//         005349f3     POP        ESI
//         005349f4     POP        EBP
//         005349f5     POP        EBX
//         005349f6     ADD        ESP,0x34
//         005349f9     RET        0x10
//         005349fc     ??         90h
//         005349fd     NOP
//         005349fe     NOP
//         005349ff     NOP
    return;
}

void RGE_View::ProcessQueuedBlit(int param_1) {
    /* TODO: Stub */
//                              void __thiscall ProcessQueuedBlit(RGE_View * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00534a16(R)
//              tagRECT           Stack[-0x14]   src
//                               ?ProcessQueuedBlit@RGE_View@@IAEXH@Z                         XREF[4]:     draw:00534dbf(c),
//                               RGE_View::ProcessQueuedBlit                                               draw:00535145(c),
//                                                                                                         view_function_terrain:00536c95(c),
//                                                                                                         view_function_terrain:00537504(c)
//                              view.cpp:1218 (8)
//         00534a00     SUB        ESP,0x10
//         00534a03     PUSH       EBP
//         00534a04     PUSH       ESI
//         00534a05     MOV        ESI,this
//         00534a07     PUSH       EDI
//                              view.cpp:1224 (14)
//         00534a08     MOV        EAX,dword ptr [ESI + 0x2d8]
//         00534a0e     TEST       EAX,EAX
//         00534a10     JZ         LAB_00534ad2
//                              view.cpp:1228 (8)
//         00534a16     MOV        EAX,dword ptr [ESP + param_1]
//         00534a1a     TEST       EAX,EAX
//         00534a1c     JNZ        LAB_00534a34
//                              view.cpp:1230 (14)
//         00534a1e     MOV        EAX,dword ptr [ESI + 0x20]
//         00534a21     PUSH       0x1
//         00534a23     MOV        EAX,dword ptr [EAX + 0x3c]
//         00534a26     PUSH       EAX
//         00534a27     MOV        this,dword ptr [EAX]
//         00534a29     CALL       dword ptr [ECX + this->_padding_]
//                              view.cpp:1254 (8)
//         00534a2c     TEST       EAX,EAX
//         00534a2e     JNZ        LAB_00534ad2
//                               LAB_00534a34                                                 XREF[1]:     00534a1c(j)
//                              view.cpp:1260 (6)
//         00534a34     MOV        EDI,dword ptr [ESI + 0x2e8]
//                              view.cpp:1262 (31)
//         00534a3a     MOV        this,dword ptr [ESI + 0x2dc]
//         00534a40     INC        EDI
//         00534a41     TEST       this,this
//         00534a43     MOV        dword ptr [ESI + 0x2e8],EDI
//         00534a49     MOV        EAX,EDI
//         00534a4b     JZ         LAB_00534ac8
//         00534a4d     TEST       EAX,EAX
//         00534a4f     JL         LAB_00534ac8
//         00534a51     CMP        EAX,dword ptr [ESI + 0x2e0]
//         00534a57     JGE        LAB_00534ac8
//                              view.cpp:1268 (11)
//         00534a59     SHL        EAX,0x5
//         00534a5c     ADD        EAX,this
//         00534a5e     MOV        this,dword ptr [ESI + 0x2f0]
//                              view.cpp:1281 (79)
//         00534a64     PUSH       0x10
//         00534a66     MOV        EDX,dword ptr [EAX + 0x4]
//         00534a69     ADD        EDX,this
//         00534a6b     MOV        dword ptr [ESP + 0x14],EDX
//         00534a6f     MOV        EDX,dword ptr [ESI + 0x2ec]
//         00534a75     MOV        EBP,dword ptr [EAX]
//         00534a77     MOV        EDI,EDX
//         00534a79     ADD        EDI,EBP
//         00534a7b     LEA        EBP,[ESP + 0x10]
//         00534a7f     MOV        dword ptr [ESP + 0x10],EDI
//         00534a83     MOV        EDI,dword ptr [EAX + 0xc]
//         00534a86     PUSH       EBP=>DAT_fffffff8
//         00534a87     LEA        EDI,[EDI + this->_padding_*0x1 + 0x1]
//         00534a8b     MOV        dword ptr [ESP + 0x20],EDI
//         00534a8f     MOV        EDI,dword ptr [EAX + 0x8]
//         00534a92     LEA        EDI,[EDI + EDX*0x1 + 0x1]
//         00534a96     MOV        dword ptr [ESP + 0x1c],EDI
//         00534a9a     MOV        EDI,dword ptr [EAX + 0x10]
//         00534a9d     MOV        EAX,dword ptr [EAX + 0x14]
//         00534aa0     ADD        EDI,EDX
//         00534aa2     ADD        EAX,this
//         00534aa4     MOV        this,dword ptr [ESI + 0x20]
//         00534aa7     MOV        this,dword ptr [ECX + this->_padding_]
//         00534aaa     PUSH       this=>DAT_fffffff4
//         00534aab     PUSH       EAX=>DAT_fffffff0
//         00534aac     MOV        EDX,dword ptr [this->_padding_]
//         00534aae     PUSH       EDI
//         00534aaf     PUSH       this
//         00534ab0     CALL       dword ptr [EDX + 0x1c]
//                              view.cpp:1315 (21)
//         00534ab3     MOV        this,dword ptr [ESI + 0x2e0]
//         00534ab9     MOV        dword ptr [ESP + 0x20],EAX
//         00534abd     MOV        EAX,dword ptr [ESI + 0x2e8]
//         00534ac3     INC        EAX
//         00534ac4     CMP        EAX,this
//         00534ac6     JL         LAB_00534ad2
//                               LAB_00534ac8                                                 XREF[3]:     00534a4b(j), 00534a4f(j),
//                                                                                                         00534a57(j)
//                              view.cpp:1264 (10)
//         00534ac8     MOV        dword ptr [ESI + 0x2d8],0x0
//                               LAB_00534ad2                                                 XREF[3]:     00534a10(j), 00534a2e(j),
//                                                                                                         00534ac6(j)
//                              view.cpp:1318 (9)
//         00534ad2     POP        EDI
//         00534ad3     POP        ESI
//         00534ad4     POP        EBP
//         00534ad5     ADD        ESP,0x10
//         00534ad8     RET        0x4
//         00534adb     ??         90h
//         00534adc     NOP
//         00534add     NOP
//         00534ade     NOP
//         00534adf     NOP
    return;
}

void RGE_View::draw() {
    /* TODO: Stub */
//                              void __thiscall draw(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              tagRECT           Stack[-0x14]   clip_rect1
//              tagRECT           Stack[-0x24]   old_rect
//              tagRECT           Stack[-0x34]   new_rect
//              tagRECT           Stack[-0x44]   clip_rect2                XREF[1]:     00534bc6(W)
//              undefined4        Stack[-0x48]:4 local_48                  XREF[1]:     00534bb7(W)
//              int               Stack[-0x4c]:4 old_map_scr_y_offset      XREF[1]:     00534b6d(W)
//              short             Stack[-0x50]:2 old_start_scr_row         XREF[1]:     00534b7d(W)
//              short             Stack[-0x54]:2 old_start_scr_col         XREF[1]:     00534b78(W)
//              short             Stack[-0x58]:2 old_start_map_row
//                               ?draw@RGE_View@@UAEXXZ                                       XREF[2]:     draw:0053f753(c), 005775e8(*)
//                               RGE_View::draw
//                              view.cpp:1324 (26)
//         00534ae0     MOV        EAX,[view_debug_redraw_all]
//         00534ae5     SUB        ESP,0x54
//         00534ae8     PUSH       EBX
//         00534ae9     PUSH       EBP
//         00534aea     PUSH       ESI
//         00534aeb     PUSH       EDI
//         00534aec     XOR        EDI,EDI
//         00534aee     MOV        EBP,this
//         00534af0     CMP        EAX,EDI
//         00534af2     MOV        dword ptr [tiles_drawn],EDI
//         00534af8     JZ         LAB_00534b07
//                              view.cpp:1363 (7)
//         00534afa     MOV        byte ptr [EBP + 0x142],0x0
//                              view.cpp:1364 (6)
//         00534b01     MOV        dword ptr [view_debug_redraw_all],EDI
//                               LAB_00534b07                                                 XREF[1]:     00534af8(j)
//                              view.cpp:1367 (16)
//         00534b07     CMP        dword ptr [view_debug_ObstructionMap],EDI
//         00534b0d     JNZ        LAB_00534b17
//         00534b0f     CMP        dword ptr [view_debug_palette],EDI
//         00534b15     JZ         LAB_00534b1e
//                               LAB_00534b17                                                 XREF[1]:     00534b0d(j)
//                              view.cpp:1369 (7)
//         00534b17     MOV        byte ptr [EBP + 0x142],0x0
//                               LAB_00534b1e                                                 XREF[1]:     00534b15(j)
//                              view.cpp:1376 (8)
//         00534b1e     CMP        dword ptr [EBP + 0xfc],EDI
//         00534b24     JNZ        LAB_00534b51
//                              view.cpp:1378 (9)
//         00534b26     MOV        ESI,dword ptr [EBP]
//         00534b29     PUSH       EDI
//         00534b2a     MOV        this,EBP
//         00534b2c     CALL       dword ptr [ESI + 0x28]
//                              view.cpp:1379 (21)
//         00534b2f     XOR        EAX,EAX
//         00534b31     LEA        this,[EBP + 0x24]
//         00534b34     MOV        AL,byte ptr [EBP + 0xef]
//         00534b3a     PUSH       EAX
//         00534b3b     PUSH       this=>DAT_fffffff8
//         00534b3c     MOV        this,dword ptr [EBP + 0x20]
//         00534b3f     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
//                              view.cpp:1380 (5)
//         00534b44     MOV        this,EBP
//         00534b46     CALL       dword ptr [ESI + 0x2c]
//                              view.cpp:1904 (8)
//         00534b49     POP        EDI
//         00534b4a     POP        ESI
//         00534b4b     POP        EBP
//         00534b4c     POP        EBX
//         00534b4d     ADD        ESP,0x54
//         00534b50     RET
//                               LAB_00534b51                                                 XREF[1]:     00534b24(j)
//                              view.cpp:1388 (33)
//         00534b51     MOV        this,word ptr [EBP + 0x128]
//         00534b58     MOV        DX,word ptr [EBP + 0x12c]
//         00534b5f     MOV        AX,word ptr [EBP + 0x126]
//         00534b66     MOV        SI,word ptr [EBP + 0x12a]
//         00534b6d     MOV        word ptr [ESP + old_map_scr_y_offset],this
//                              view.cpp:1392 (21)
//         00534b72     MOV        this,dword ptr [EBP + 0x178]
//         00534b78     MOV        word ptr [ESP + old_start_scr_col],DX
//         00534b7d     MOV        word ptr [ESP + old_start_scr_row],AX
//         00534b82     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
//                              view.cpp:1393 (11)
//         00534b87     MOV        this,dword ptr [EBP + 0x17c]
//         00534b8d     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
//                              view.cpp:1394 (11)
//         00534b92     MOV        this,dword ptr [EBP + 0x180]
//         00534b98     CALL       TSpan_List_Manager::ResetAll                     void ResetAll(TSpan_List_Manager * this)
//                              view.cpp:1404 (12)
//         00534b9d     MOV        EDX,dword ptr [EBP + 0x134]
//         00534ba3     MOV        EBX,dword ptr [EBP + 0x130]
//                              view.cpp:1406 (23)
//         00534ba9     MOV        this,EBP
//         00534bab     MOV        dword ptr [EBP + 0x2a4],EDI
//         00534bb1     MOV        dword ptr [EBP + 0x2a0],EDI
//         00534bb7     MOV        dword ptr [ESP + local_48],EDX
//         00534bbb     CALL       RGE_View::update                                 void update(RGE_View * this)
//                              view.cpp:1409 (13)
//         00534bc0     MOV        EAX,dword ptr [EBP]
//         00534bc3     PUSH       EDI
//         00534bc4     MOV        this,EBP
//         00534bc6     MOV        dword ptr [ESP + clip_rect2.left],EAX
//         00534bca     CALL       dword ptr [EAX + 0x28]
//                              view.cpp:1423 (13)
//         00534bcd     CMP        byte ptr [EBP + 0x142],0x1
//         00534bd4     JNZ        LAB_0053512b
//                              view.cpp:1428 (55)
//         00534bda     CMP        word ptr [EBP + 0x12a],SI
//         00534be1     JNZ        LAB_00534c11
//         00534be3     MOV        AX,word ptr [ESP + 0x10]
//         00534be8     CMP        word ptr [EBP + 0x12c],AX
//         00534bef     JNZ        LAB_00534c11
//         00534bf1     MOV        this,word ptr [ESP + 0x14]
//         00534bf6     CMP        word ptr [EBP + 0x126],this
//         00534bfd     JNZ        LAB_00534c11
//         00534bff     MOV        DX,word ptr [ESP + 0x18]
//         00534c04     CMP        word ptr [EBP + 0x128],DX
//         00534c0b     JZ         LAB_0053512b
//                               LAB_00534c11                                                 XREF[3]:     00534be1(j), 00534bef(j),
//                                                                                                         00534bfd(j)
//                              view.cpp:1441 (7)
//         00534c11     MOV        DX,word ptr [EBP + 0x130]
//                              view.cpp:1442 (15)
//         00534c18     MOV        SI,word ptr [EBP + 0x134]
//         00534c1f     SUB        SI,word ptr [ESP + 0x1c]
//         00534c24     SUB        DX,BX
//                              view.cpp:1444 (18)
//         00534c27     CMP        DX,DI
//         00534c2a     MOV        dword ptr [ESP + 0x1c],ESI
//         00534c2e     JNZ        LAB_00534c39
//         00534c30     CMP        SI,DI
//         00534c33     JZ         LAB_0053512b
//                               LAB_00534c39                                                 XREF[1]:     00534c2e(j)
//                              view.cpp:1454 (11)
//         00534c39     MOV        this,dword ptr [EBP + 0x14]
//         00534c3c     MOV        dword ptr [ESP + 0x44],EDI
//         00534c40     MOV        dword ptr [ESP + 0x48],EDI
//                              view.cpp:1455 (14)
//         00534c44     MOV        EDI,dword ptr [EBP + 0x18]
//         00534c47     LEA        EAX,[this->_padding_ + -0x1]
//         00534c4a     MOV        dword ptr [ESP + 0x10],EDI
//         00534c4e     MOV        dword ptr [ESP + 0x4c],EAX
//                              view.cpp:1459 (21)
//         00534c52     MOV        EBX,dword ptr [ESP + 0x4c]
//         00534c56     MOVSX      EAX,DX
//         00534c59     MOVSX      ESI,SI
//         00534c5c     DEC        EDI
//         00534c5d     ADD        EBX,EAX
//         00534c5f     MOV        dword ptr [ESP + 0x3c],EBX
//         00534c63     MOV        dword ptr [ESP + 0x50],EDI
//                              view.cpp:1460 (7)
//         00534c67     LEA        EBX,[EDI + ESI*0x1]
//         00534c6a     MOV        dword ptr [ESP + 0x34],EAX
//                              view.cpp:1465 (52)
//         00534c6e     TEST       EBX,EBX
//         00534c70     MOV        dword ptr [ESP + 0x38],ESI
//         00534c74     MOV        dword ptr [ESP + 0x40],EBX
//         00534c78     JL         LAB_005351fd
//         00534c7e     MOV        EBX,dword ptr [ESP + 0x3c]
//         00534c82     TEST       EBX,EBX
//         00534c84     JL         LAB_005351fd
//         00534c8a     MOV        EBX,ESI
//         00534c8c     CMP        EDI,EBX
//         00534c8e     JL         LAB_005351fd
//         00534c94     MOV        EBX,dword ptr [ESP + 0x4c]
//         00534c98     MOV        EDI,EAX
//         00534c9a     CMP        EBX,EDI
//         00534c9c     JL         LAB_005351fd
//                              view.cpp:1479 (5)
//         00534ca2     TEST       DL,0x7
//         00534ca5     JZ         LAB_00534cc4
//                              view.cpp:1482 (5)
//         00534ca7     TEST       DX,DX
//         00534caa     JG         LAB_00534caf
//                              view.cpp:1488 (8)
//         00534cac     LEA        EDI,[EAX + 0x7]
//                               LAB_00534caf                                                 XREF[1]:     00534caa(j)
//         00534caf     AND        EDI,0xfffffff8
//         00534cb2     SUB        EDI,EAX
//                              view.cpp:1491 (16)
//         00534cb4     MOV        EAX,dword ptr [EBP + 0x130]
//         00534cba     ADD        EDX,EDI
//         00534cbc     ADD        EAX,EDI
//         00534cbe     MOV        dword ptr [EBP + 0x130],EAX
//                               LAB_00534cc4                                                 XREF[1]:     00534ca5(j)
//                              view.cpp:1494 (9)
//         00534cc4     MOV        EBX,dword ptr [ESP + 0x1c]
//         00534cc8     TEST       BL,0x7
//         00534ccb     JZ         LAB_00534cec
//                              view.cpp:1497 (3)
//         00534ccd     TEST       BX,BX
//                              view.cpp:1499 (4)
//         00534cd0     MOV        EDI,ESI
//         00534cd2     JG         LAB_00534cd7
//                              view.cpp:1503 (3)
//         00534cd4     LEA        EDI,[ESI + 0x7]
//                               LAB_00534cd7                                                 XREF[1]:     00534cd2(j)
//                              view.cpp:1506 (21)
//         00534cd7     MOV        EAX,dword ptr [EBP + 0x134]
//         00534cdd     AND        EDI,0xfffffff8
//         00534ce0     SUB        EDI,ESI
//         00534ce2     ADD        EBX,EDI
//         00534ce4     ADD        EAX,EDI
//         00534ce6     MOV        dword ptr [EBP + 0x134],EAX
//                               LAB_00534cec                                                 XREF[1]:     00534ccb(j)
//                              view.cpp:1516 (7)
//         00534cec     XOR        EAX,EAX
//         00534cee     CMP        DX,AX
//         00534cf1     JL         LAB_00534d0a
//                              view.cpp:1518 (3)
//         00534cf3     MOVSX      ESI,DX
//                              view.cpp:1519 (2)
//         00534cf6     MOV        EDX,this
//                              view.cpp:1522 (16)
//         00534cf8     SUB        this,ESI
//         00534cfa     DEC        EDX
//         00534cfb     MOV        dword ptr [ESP + 0x44],ESI
//         00534cff     MOV        dword ptr [ESP + 0x4c],EDX
//         00534d03     MOV        dword ptr [ESP + 0x34],EAX
//         00534d07     DEC        this
//                              view.cpp:1524 (2)
//         00534d08     JMP        LAB_00534d27
//                               LAB_00534d0a                                                 XREF[1]:     00534cf1(j)
//                              view.cpp:1527 (15)
//         00534d0a     MOVSX      ESI,DX
//         00534d0d     MOV        dword ptr [ESP + 0x44],EAX
//         00534d11     LEA        EAX,[ESI + this->_padding_*0x1 + -0x1]
//         00534d15     MOV        dword ptr [ESP + 0x4c],EAX
//                              view.cpp:1529 (8)
//         00534d19     MOV        EAX,ESI
//         00534d1b     NEG        EAX
//         00534d1d     MOV        dword ptr [ESP + 0x34],EAX
//                              view.cpp:1530 (6)
//         00534d21     ADD        EAX,ESI
//         00534d23     LEA        this,[EAX + this->_padding_*0x1 + -0x1]
//                               LAB_00534d27                                                 XREF[1]:     00534d08(j)
//                              view.cpp:1533 (9)
//         00534d27     TEST       BX,BX
//         00534d2a     MOV        dword ptr [ESP + 0x3c],this
//         00534d2e     JL         LAB_00534d51
//                              view.cpp:1536 (4)
//         00534d30     MOV        EAX,dword ptr [ESP + 0x10]
//                              view.cpp:1538 (7)
//         00534d34     XOR        EDI,EDI
//         00534d36     MOVSX      EBX,BX
//         00534d39     MOV        EDX,EAX
//                              view.cpp:1539 (20)
//         00534d3b     SUB        EAX,EBX
//         00534d3d     DEC        EDX
//         00534d3e     DEC        EAX
//         00534d3f     MOV        dword ptr [ESP + 0x48],EBX
//         00534d43     MOV        dword ptr [ESP + 0x50],EDX
//         00534d47     MOV        dword ptr [ESP + 0x38],EDI
//         00534d4b     MOV        dword ptr [ESP + 0x40],EAX
//                              view.cpp:1541 (2)
//         00534d4f     JMP        LAB_00534d7c
//                               LAB_00534d51                                                 XREF[1]:     00534d2e(j)
//                              view.cpp:1544 (23)
//         00534d51     MOV        this,dword ptr [ESP + 0x10]
//         00534d55     MOV        dword ptr [ESP + 0x48],0x0
//         00534d5d     MOVSX      EBX,BX
//         00534d60     LEA        EAX,[EBX + this->_padding_*0x1 + -0x1]
//         00534d64     MOV        dword ptr [ESP + 0x50],EAX
//                              view.cpp:1546 (8)
//         00534d68     MOV        EAX,EBX
//         00534d6a     NEG        EAX
//         00534d6c     MOV        dword ptr [ESP + 0x38],EAX
//                              view.cpp:1547 (12)
//         00534d70     ADD        EAX,EBX
//         00534d72     XOR        EDI,EDI
//         00534d74     LEA        this,[EAX + this->_padding_*0x1 + -0x1]
//         00534d78     MOV        dword ptr [ESP + 0x40],this
//                               LAB_00534d7c                                                 XREF[1]:     00534d4f(j)
//                              view.cpp:1558 (22)
//         00534d7c     MOV        this,dword ptr [EBP + 0x20]
//         00534d7f     MOV        EDX,dword ptr [this->_padding_]
//         00534d81     CMP        byte ptr [EDX + 0x478],0x1
//         00534d88     JZ         LAB_00534dc6
//         00534d8a     CMP        dword ptr [ECX + this->_padding_],EDI
//         00534d90     JZ         LAB_00534dc6
//                              view.cpp:1575 (19)
//         00534d92     PUSH       EBX
//         00534d93     LEA        EAX,[ESP + 0x38]
//         00534d97     PUSH       ESI=>DAT_fffffff8
//         00534d98     LEA        this,[ESP + 0x4c]
//         00534d9c     PUSH       EAX=>DAT_fffffff4
//         00534d9d     PUSH       this=>DAT_fffffff0
//         00534d9e     MOV        this,EBP
//         00534da0     CALL       RGE_View::CreateBlitQueue                        void CreateBlitQueue(RGE_View * this, tagRECT
//                              view.cpp:1583 (15)
//         00534da5     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00534dab     CMP        this,EDI
//         00534dad     JZ         LAB_00534db4
//         00534daf     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_00534db4                                                 XREF[1]:     00534dad(j)
//                              view.cpp:1585 (18)
//         00534db4     CMP        dword ptr [EBP + 0x2d8],EDI
//         00534dba     JZ         LAB_00534deb
//         00534dbc     PUSH       EDI
//         00534dbd     MOV        this,EBP
//         00534dbf     CALL       RGE_View::ProcessQueuedBlit                      void ProcessQueuedBlit(RGE_View * this, int p
//         00534dc4     JMP        LAB_00534deb
//                               LAB_00534dc6                                                 XREF[2]:     00534d88(j), 00534d90(j)
//                              view.cpp:1569 (31)
//         00534dc6     MOV        EDX,dword ptr [EBP + 0x90]
//         00534dcc     MOV        EAX,dword ptr [EBP + 0x8c]
//         00534dd2     PUSH       EDX
//         00534dd3     PUSH       EAX=>DAT_fffffff8
//         00534dd4     PUSH       EBX=>DAT_fffffff4
//         00534dd5     LEA        EDX,[ESP + 0x40]
//         00534dd9     PUSH       ESI=>DAT_fffffff0
//         00534dda     LEA        EAX,[ESP + 0x54]
//         00534dde     PUSH       EDX
//         00534ddf     PUSH       EAX
//         00534de0     CALL       TDrawArea::OverlayMemCopy                        void OverlayMemCopy(TDrawArea * this, tagRECT
//                              view.cpp:1570 (6)
//         00534de5     MOV        dword ptr [EBP + 0x2d8],EDI
//                               LAB_00534deb                                                 XREF[2]:     00534dba(j), 00534dc4(j)
//                              view.cpp:1598 (13)
//         00534deb     MOV        this,dword ptr [EBP + 0x334]
//         00534df1     PUSH       EBX
//         00534df2     PUSH       ESI=>DAT_fffffff8
//         00534df3     CALL       DClipInfo_List::Scroll                           void Scroll(DClipInfo_List * this, int param_
//                              view.cpp:1602 (6)
//         00534df8     MOV        EAX,dword ptr [EBP + 0x2d0]
//                              view.cpp:1604 (25)
//         00534dfe     MOV        this,dword ptr [EBP + 0x324]
//         00534e04     ADD        EAX,ESI
//         00534e06     MOV        dword ptr [EBP + 0x2d0],EAX
//         00534e0c     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00534e0f     CMP        EAX,EDX
//         00534e11     JL         LAB_00534e99
//                              view.cpp:1606 (20)
//         00534e17     PUSH       0x1
//         00534e19     PUSH       s_view::draw                                     = "view::draw"
//         00534e1e     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         00534e23     TEST       EAX,EAX
//         00534e25     JZ         LAB_00534f17
//                              view.cpp:1612 (48)
//         00534e2b     MOV        EAX,dword ptr [EBP + 0x324]
//         00534e31     MOV        this,dword ptr [EBP + 0x2d0]
//         00534e37     SUB        this,ESI
//         00534e39     MOV        EDX,dword ptr [EAX + 0xbc]
//         00534e3f     MOV        ESI,dword ptr [EAX + 0x1c]
//         00534e42     MOV        EDI,dword ptr [EAX + 0x18]
//         00534e45     MOV        ESI,dword ptr [EDX + ESI*0x4 + -0x4]
//         00534e49     ADD        ESI,EDI
//         00534e4b     MOV        EDI,dword ptr [EDX]
//         00534e4d     MOV        EDX,this
//         00534e4f     SHR        this,0x2
//         00534e52     MOVSD.REP  ES:EDI,ESI
//         00534e54     MOV        this,EDX
//         00534e56     AND        this,0x3
//         00534e59     MOVSB.REP  ES:EDI,ESI
//                              view.cpp:1616 (12)
//         00534e5b     MOV        this,dword ptr [EBP + 0x324]
//         00534e61     MOV        EDI,dword ptr [EBP + 0x2d0]
//                              view.cpp:1617 (24)
//         00534e67     MOV        ESI,dword ptr [EBP + 0x2d4]
//         00534e6d     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00534e70     SUB        EDI,EAX
//         00534e72     INC        ESI
//         00534e73     MOV        dword ptr [EBP + 0x2d0],EDI
//         00534e79     MOV        dword ptr [EBP + 0x2d4],ESI
//                              view.cpp:1618 (19)
//         00534e7f     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00534e82     MOV        EAX,ESI
//         00534e84     CMP        EAX,EDX
//         00534e86     JL         LAB_00534e92
//         00534e88     MOV        dword ptr [EBP + 0x2d4],0x0
//                               LAB_00534e92                                                 XREF[1]:     00534e86(j)
//                              view.cpp:1620 (5)
//         00534e92     PUSH       s_view::draw                                     = "view::draw"
//                              view.cpp:1622 (6)
//         00534e97     JMP        LAB_00534f10
//                               LAB_00534e99                                                 XREF[1]:     00534e11(j)
//         00534e99     CMP        EAX,EDI
//         00534e9b     JGE        LAB_00534f17
//                              view.cpp:1624 (16)
//         00534e9d     PUSH       0x1
//         00534e9f     PUSH       s_view::draw2                                    = "view::draw2"
//         00534ea4     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         00534ea9     TEST       EAX,EAX
//         00534eab     JZ         LAB_00534f17
//                              view.cpp:1628 (17)
//         00534ead     MOV        EAX,dword ptr [EBP + 0x324]
//         00534eb3     MOV        EDX,dword ptr [EBP + 0x2d0]
//         00534eb9     MOV        this,dword ptr [EAX + 0x18]
//         00534ebc     ADD        EDX,this
//                              view.cpp:1629 (19)
//         00534ebe     MOV        this,dword ptr [EBP + 0x2d4]
//         00534ec4     DEC        this
//         00534ec5     MOV        dword ptr [EBP + 0x2d0],EDX
//         00534ecb     MOV        dword ptr [EBP + 0x2d4],this
//                              view.cpp:1630 (12)
//         00534ed1     JNS        LAB_00534edd
//         00534ed3     MOV        EDX,dword ptr [EAX + 0x1c]
//         00534ed6     DEC        EDX
//         00534ed7     MOV        dword ptr [EBP + 0x2d4],EDX
//                               LAB_00534edd                                                 XREF[1]:     00534ed1(j)
//                              view.cpp:1636 (15)
//         00534edd     MOV        EDX,dword ptr [EAX + 0xbc]
//         00534ee3     MOV        EDI,dword ptr [EAX + 0x1c]
//         00534ee6     MOV        this,dword ptr [EBP + 0x2d0]
//                              view.cpp:1637 (43)
//         00534eec     PUSH       s_view::draw3                                    = "view::draw3"
//         00534ef1     MOV        ESI,dword ptr [EDX]
//         00534ef3     MOV        EDI,dword ptr [EDX + EDI*0x4 + -0x4]
//         00534ef7     MOV        EDX,dword ptr [EAX + 0x18]
//         00534efa     MOV        EAX,this
//         00534efc     ADD        EDI,EDX
//         00534efe     SHR        this,0x2
//         00534f01     MOVSD.REP  ES:EDI,ESI
//         00534f03     MOV        this,EAX
//         00534f05     AND        this,0x3
//         00534f08     MOVSB.REP  ES:EDI,ESI
//         00534f0a     MOV        this,dword ptr [EBP + 0x324]
//                               LAB_00534f10                                                 XREF[1]:     00534e97(j)
//         00534f10     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//         00534f15     XOR        EDI,EDI
//                               LAB_00534f17                                                 XREF[3]:     00534e25(j), 00534e9b(j),
//                                                                                                         00534eab(j)
//                              view.cpp:1643 (14)
//         00534f17     MOV        EAX,dword ptr [EBP + 0x2d4]
//         00534f1d     ADD        EAX,EBX
//         00534f1f     MOV        dword ptr [EBP + 0x2d4],EAX
//                              view.cpp:1645 (19)
//         00534f25     JNS        LAB_00534f38
//         00534f27     MOV        this,dword ptr [EBP + 0x324]
//         00534f2d     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00534f30     ADD        EDX,EAX
//         00534f32     MOV        dword ptr [EBP + 0x2d4],EDX
//                               LAB_00534f38                                                 XREF[1]:     00534f25(j)
//                              view.cpp:1646 (27)
//         00534f38     MOV        this,dword ptr [EBP + 0x324]
//         00534f3e     MOV        EAX,dword ptr [EBP + 0x2d4]
//         00534f44     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00534f47     CMP        EAX,EDX
//         00534f49     JL         LAB_00534f53
//         00534f4b     SUB        EAX,EDX
//         00534f4d     MOV        dword ptr [EBP + 0x2d4],EAX
//                               LAB_00534f53                                                 XREF[1]:     00534f49(j)
//                              view.cpp:1648 (19)
//         00534f53     MOV        EAX,dword ptr [EBP + 0x2d4]
//         00534f59     MOV        EDX,dword ptr [EBP + 0x2d0]
//         00534f5f     PUSH       EAX
//         00534f60     PUSH       EDX=>DAT_fffffff8
//         00534f61     CALL       TDrawArea::SetFloatOffsets                       void SetFloatOffsets(TDrawArea * this, int pa
//                              view.cpp:1653 (20)
//         00534f66     MOV        this,dword ptr [ESP + 0x34]
//         00534f6a     MOV        EDX,dword ptr [ESP + 0x3c]
//         00534f6e     CMP        this,EDI
//         00534f70     JNZ        LAB_00534fd2
//         00534f72     MOV        EAX,dword ptr [EBP + 0x14]
//         00534f75     DEC        EAX
//         00534f76     CMP        EDX,EAX
//         00534f78     JNZ        LAB_00534fd2
//                              view.cpp:1657 (27)
//         00534f7a     MOV        this,dword ptr [ESP + 0x38]
//         00534f7e     MOV        EDX,dword ptr [ESP + 0x40]
//         00534f82     OR         EBX,0xffffffff
//         00534f85     CMP        this,EDI
//         00534f87     MOV        dword ptr [ESP + 0x54],EBX
//         00534f8b     JNZ        LAB_00534fa2
//         00534f8d     MOV        ESI,dword ptr [EBP + 0x18]
//         00534f90     DEC        ESI
//         00534f91     CMP        EDX,ESI
//         00534f93     JNZ        LAB_00534fa2
//                              view.cpp:1658 (8)
//         00534f95     MOV        dword ptr [ESP + 0x24],0xffffffff
//                              view.cpp:1659 (5)
//         00534f9d     JMP        LAB_00535093
//                               LAB_00534fa2                                                 XREF[2]:     00534f8b(j), 00534f93(j)
//                              view.cpp:1661 (2)
//         00534fa2     CMP        this,EDI
//                              view.cpp:1664 (6)
//         00534fa4     MOV        dword ptr [ESP + 0x24],EDI
//         00534fa8     JNZ        LAB_00534fc0
//                              view.cpp:1666 (4)
//         00534faa     MOV        dword ptr [ESP + 0x2c],EAX
//                              view.cpp:1667 (13)
//         00534fae     MOV        EAX,dword ptr [EBP + 0x18]
//         00534fb1     INC        EDX
//         00534fb2     DEC        EAX
//         00534fb3     MOV        dword ptr [ESP + 0x28],EDX
//         00534fb7     MOV        dword ptr [ESP + 0x30],EAX
//                              view.cpp:1669 (5)
//         00534fbb     JMP        LAB_00535093
//                               LAB_00534fc0                                                 XREF[1]:     00534fa8(j)
//                              view.cpp:1675 (13)
//         00534fc0     DEC        this
//         00534fc1     MOV        dword ptr [ESP + 0x28],EDI
//         00534fc5     MOV        dword ptr [ESP + 0x2c],EAX
//         00534fc9     MOV        dword ptr [ESP + 0x30],this
//                              view.cpp:1679 (5)
//         00534fcd     JMP        LAB_00535093
//                               LAB_00534fd2                                                 XREF[2]:     00534f70(j), 00534f78(j)
//                              view.cpp:1681 (4)
//         00534fd2     CMP        this,EDI
//         00534fd4     JNZ        LAB_00535034
//                              view.cpp:1686 (3)
//         00534fd6     MOV        this,dword ptr [EBP + 0x14]
//                              view.cpp:1687 (3)
//         00534fd9     MOV        EAX,dword ptr [EBP + 0x18]
//                              view.cpp:1689 (37)
//         00534fdc     MOV        ESI,dword ptr [ESP + 0x40]
//         00534fe0     DEC        this
//         00534fe1     MOV        dword ptr [ESP + 0x5c],this
//         00534fe5     MOV        this,dword ptr [ESP + 0x38]
//         00534fe9     LEA        EBX,[EDX + 0x1]
//         00534fec     DEC        EAX
//         00534fed     CMP        this,EDI
//         00534fef     MOV        dword ptr [ESP + 0x54],EBX
//         00534ff3     MOV        dword ptr [ESP + 0x58],EDI
//         00534ff7     MOV        dword ptr [ESP + 0x60],EAX
//         00534ffb     JNZ        LAB_0053500e
//         00534ffd     CMP        ESI,EAX
//         00534fff     JNZ        LAB_0053500e
//                              view.cpp:1690 (8)
//         00535001     MOV        dword ptr [ESP + 0x24],0xffffffff
//                              view.cpp:1691 (5)
//         00535009     JMP        LAB_00535093
//                               LAB_0053500e                                                 XREF[2]:     00534ffb(j), 00534fff(j)
//                              view.cpp:1693 (2)
//         0053500e     CMP        this,EDI
//                              view.cpp:1696 (6)
//         00535010     MOV        dword ptr [ESP + 0x24],EDI
//         00535014     JNZ        LAB_00535025
//                              view.cpp:1697 (1)
//         00535016     INC        ESI
//                              view.cpp:1698 (8)
//         00535017     MOV        dword ptr [ESP + 0x2c],EDX
//         0053501b     MOV        dword ptr [ESP + 0x28],ESI
//                              view.cpp:1699 (4)
//         0053501f     MOV        dword ptr [ESP + 0x30],EAX
//                              view.cpp:1701 (2)
//         00535023     JMP        LAB_00535093
//                               LAB_00535025                                                 XREF[1]:     00535014(j)
//                              view.cpp:1707 (13)
//         00535025     DEC        this
//         00535026     MOV        dword ptr [ESP + 0x28],EDI
//         0053502a     MOV        dword ptr [ESP + 0x2c],EDX
//         0053502e     MOV        dword ptr [ESP + 0x30],this
//                              view.cpp:1711 (2)
//         00535032     JMP        LAB_00535093
//                               LAB_00535034                                                 XREF[1]:     00534fd4(j)
//                              view.cpp:1717 (3)
//         00535034     MOV        EAX,dword ptr [EBP + 0x18]
//                              view.cpp:1719 (38)
//         00535037     MOV        ESI,dword ptr [ESP + 0x40]
//         0053503b     LEA        EDX,[this->_padding_ + -0x1]
//         0053503e     XOR        EBX,EBX
//         00535040     MOV        dword ptr [ESP + 0x5c],EDX
//         00535044     MOV        EDX,dword ptr [ESP + 0x38]
//         00535048     DEC        EAX
//         00535049     CMP        EDX,EDI
//         0053504b     MOV        dword ptr [ESP + 0x54],EBX
//         0053504f     MOV        dword ptr [ESP + 0x58],EDI
//         00535053     MOV        dword ptr [ESP + 0x60],EAX
//         00535057     JNZ        LAB_00535067
//         00535059     CMP        ESI,EAX
//         0053505b     JNZ        LAB_00535067
//                              view.cpp:1720 (8)
//         0053505d     MOV        dword ptr [ESP + 0x24],0xffffffff
//                              view.cpp:1721 (2)
//         00535065     JMP        LAB_00535093
//                               LAB_00535067                                                 XREF[2]:     00535057(j), 0053505b(j)
//                              view.cpp:1723 (2)
//         00535067     CMP        EDX,EDI
//                              view.cpp:1726 (6)
//         00535069     MOV        dword ptr [ESP + 0x24],this
//         0053506d     JNZ        LAB_00535082
//                              view.cpp:1728 (13)
//         0053506f     MOV        this,dword ptr [EBP + 0x14]
//         00535072     INC        ESI
//         00535073     DEC        this
//         00535074     MOV        dword ptr [ESP + 0x28],ESI
//         00535078     MOV        dword ptr [ESP + 0x2c],this
//                              view.cpp:1729 (4)
//         0053507c     MOV        dword ptr [ESP + 0x30],EAX
//                              view.cpp:1731 (2)
//         00535080     JMP        LAB_00535093
//                               LAB_00535082                                                 XREF[1]:     0053506d(j)
//                              view.cpp:1736 (8)
//         00535082     MOV        EAX,dword ptr [EBP + 0x14]
//         00535085     MOV        dword ptr [ESP + 0x28],EDI
//         00535089     DEC        EAX
//                              view.cpp:1737 (9)
//         0053508a     DEC        EDX
//         0053508b     MOV        dword ptr [ESP + 0x2c],EAX
//         0053508f     MOV        dword ptr [ESP + 0x30],EDX
//                               LAB_00535093                                                 XREF[8]:     00534f9d(j), 00534fbb(j),
//                                                                                                         00534fcd(j), 00535009(j),
//                                                                                                         00535023(j), 00535032(j),
//                                                                                                         00535065(j), 00535080(j)
//                              view.cpp:1751 (5)
//         00535093     CMP        EBX,-0x1
//         00535096     JZ         LAB_005350d7
//                              view.cpp:1753 (17)
//         00535098     LEA        this,[ESP + 0x54]
//         0053509c     PUSH       EDI
//         0053509d     PUSH       this=>DAT_fffffff8
//         0053509e     MOV        this,dword ptr [EBP + 0x324]
//         005350a4     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
//                              view.cpp:1756 (51)
//         005350a9     MOV        EAX,dword ptr [ESP + 0x54]
//         005350ad     MOV        this,dword ptr [ESP + 0x58]
//         005350b1     LEA        EDX,[EBP + 0x2a8]
//         005350b7     MOV        ESI,0x1
//         005350bc     MOV        dword ptr [EBP + 0x2a0],ESI
//         005350c2     MOV        dword ptr [EDX],EAX
//         005350c4     MOV        EAX,dword ptr [ESP + 0x5c]
//         005350c8     MOV        dword ptr [EDX + 0x4],this
//         005350cb     MOV        this,dword ptr [ESP + 0x60]
//         005350cf     MOV        dword ptr [EDX + 0x8],EAX
//         005350d2     MOV        dword ptr [EDX + 0xc],this
//         005350d5     JMP        LAB_005350dc
//                               LAB_005350d7                                                 XREF[1]:     00535096(j)
//         005350d7     MOV        ESI,0x1
//                               LAB_005350dc                                                 XREF[1]:     005350d5(j)
//                              view.cpp:1761 (11)
//         005350dc     MOV        EAX,dword ptr [ESP + 0x24]
//         005350e0     OR         EBX,0xffffffff
//         005350e3     CMP        EAX,EBX
//         005350e5     JZ         LAB_00535129
//                              view.cpp:1763 (17)
//         005350e7     MOV        this,dword ptr [EBP + 0x324]
//         005350ed     LEA        EDX,[ESP + 0x24]
//         005350f1     PUSH       EDI
//         005350f2     PUSH       EDX=>DAT_fffffff8
//         005350f3     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
//                              view.cpp:1765 (10)
//         005350f8     CMP        dword ptr [ESP + 0x54],EBX
//         005350fc     JZ         LAB_005351d1
//                              view.cpp:1768 (39)
//         00535102     MOV        this,dword ptr [ESP + 0x24]
//         00535106     MOV        EDX,dword ptr [ESP + 0x28]
//         0053510a     LEA        EAX,[EBP + 0x2b8]
//         00535110     MOV        dword ptr [EBP + 0x2a4],ESI
//         00535116     MOV        dword ptr [EAX],this
//         00535118     MOV        this,dword ptr [ESP + 0x2c]
//         0053511c     MOV        dword ptr [EAX + 0x4],EDX
//         0053511f     MOV        EDX,dword ptr [ESP + 0x30]
//         00535123     MOV        dword ptr [EAX + 0x8],this
//         00535126     MOV        dword ptr [EAX + 0xc],EDX
//                               LAB_00535129                                                 XREF[2]:     005350e5(j), 005351f8(j)
//                              view.cpp:1770 (2)
//         00535129     XOR        EDI,EDI
//                               LAB_0053512b                                                 XREF[4]:     00534bd4(j), 00534c0b(j),
//                                                                                                         00534c33(j), 00535206(j)
//                              view.cpp:1788 (15)
//         0053512b     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00535131     CMP        this,EDI
//         00535133     JZ         LAB_0053513a
//         00535135     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_0053513a                                                 XREF[1]:     00535133(j)
//                              view.cpp:1790 (16)
//         0053513a     CMP        dword ptr [EBP + 0x2d8],EDI
//         00535140     JZ         LAB_0053514a
//         00535142     PUSH       EDI
//         00535143     MOV        this,EBP
//         00535145     CALL       RGE_View::ProcessQueuedBlit                      void ProcessQueuedBlit(RGE_View * this, int p
//                               LAB_0053514a                                                 XREF[1]:     00535140(j)
//                              view.cpp:1794 (26)
//         0053514a     MOV        EAX,[rge_base_game]                              = 00000000
//         0053514f     MOV        EAX,dword ptr [EAX + 0x1b4]
//         00535155     CMP        EAX,0x9
//         00535158     JL         LAB_0053516b
//         0053515a     CMP        EAX,0xa
//         0053515d     JLE        LAB_00535164
//         0053515f     CMP        EAX,0x13
//         00535162     JNZ        LAB_0053516b
//                               LAB_00535164                                                 XREF[1]:     0053515d(j)
//                              view.cpp:1800 (7)
//         00535164     MOV        this,EBP
//         00535166     CALL       RGE_View::draw_paint_brush                       void draw_paint_brush(RGE_View * this)
//                               LAB_0053516b                                                 XREF[2]:     00535158(j), 00535162(j)
//                              view.cpp:1809 (10)
//         0053516b     MOV        AL,byte ptr [EBP + 0x142]
//         00535171     TEST       AL,AL
//         00535173     JNZ        LAB_0053519e
//                              view.cpp:1813 (25)
//         00535175     MOV        this,dword ptr [EBP + 0x324]
//         0053517b     PUSH       EDI
//         0053517c     PUSH       EDI=>DAT_fffffff8
//         0053517d     MOV        dword ptr [EBP + 0x2d0],EDI
//         00535183     MOV        dword ptr [EBP + 0x2d4],EDI
//         00535189     CALL       TDrawArea::SetFloatOffsets                       void SetFloatOffsets(TDrawArea * this, int pa
//                              view.cpp:1815 (16)
//         0053518e     MOV        this,dword ptr [EBP + 0x324]
//         00535194     PUSH       EDI
//         00535195     LEA        EDX,[ECX + this->_padding_]
//         00535198     PUSH       EDX=>DAT_fffffff8
//         00535199     CALL       TDrawArea::PtrClear                              void PtrClear(TDrawArea * this, tagRECT * par
//                               LAB_0053519e                                                 XREF[1]:     00535173(j)
//                              view.cpp:1837 (16)
//         0053519e     MOV        EAX,dword ptr [EBP + 0x324]
//         005351a4     MOV        this,EBP
//         005351a6     PUSH       EAX
//         005351a7     PUSH       offset DAT_fffffff8
//         005351a9     CALL       RGE_View::draw_view                              void draw_view(RGE_View * this, uchar param_1
//                              view.cpp:1847 (16)
//         005351ae     MOV        EDX,dword ptr [ESP + 0x20]
//         005351b2     MOV        this,EBP
//         005351b4     MOV        byte ptr [EBP + 0x142],0x1
//         005351bb     CALL       dword ptr [EDX + 0x2c]
//                              view.cpp:1854 (5)
//         005351be     MOV        EAX,[frame_count]
//                              view.cpp:1904 (14)
//         005351c3     POP        EDI
//         005351c4     INC        EAX
//         005351c5     POP        ESI
//         005351c6     POP        EBP
//         005351c7     MOV        [frame_count],EAX
//         005351cc     POP        EBX
//         005351cd     ADD        ESP,0x54
//         005351d0     RET
//                               LAB_005351d1                                                 XREF[1]:     005350fc(j)
//                              view.cpp:1773 (44)
//         005351d1     MOV        this,dword ptr [ESP + 0x24]
//         005351d5     MOV        EDX,dword ptr [ESP + 0x28]
//         005351d9     LEA        EAX,[EBP + 0x2a8]
//         005351df     MOV        dword ptr [EBP + 0x2a0],ESI
//         005351e5     MOV        dword ptr [EAX],this
//         005351e7     MOV        this,dword ptr [ESP + 0x2c]
//         005351eb     MOV        dword ptr [EAX + 0x4],EDX
//         005351ee     MOV        EDX,dword ptr [ESP + 0x30]
//         005351f2     MOV        dword ptr [EAX + 0x8],this
//         005351f5     MOV        dword ptr [EAX + 0xc],EDX
//         005351f8     JMP        LAB_00535129
//                               LAB_005351fd                                                 XREF[4]:     00534c78(j), 00534c84(j),
//                                                                                                         00534c8e(j), 00534c9c(j)
//                              view.cpp:1770 (14)
//         005351fd     XOR        EDI,EDI
//         005351ff     MOV        byte ptr [EBP + 0x142],0x0
//         00535206     JMP        LAB_0053512b
//         0053520b     ??         90h
//         0053520c     NOP
//         0053520d     NOP
//         0053520e     NOP
//         0053520f     NOP
    return;
}

void RGE_View::update() {
    /* TODO: Stub */
//                              void __thiscall update(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     0053533b(W), 0053533f(R), 00535377(W), 005353c1(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[9]:     0053529d(W), 005352a1(R), 005352c2(W), 005352dc(R),
//                                                                                     005352f7(W), 005352fd(R), 0053532e(W), 0053535a(R),
//                                                                                     005353ca(R)
//              short             Stack[-0xc]:2  col_adj                   XREF[3]:     0053527f(W), 0053528a(R), 0053536a(R)
//                               ?update@RGE_View@@IAEXXZ                                     XREF[1]:     draw:00534bbb(c)
//                               RGE_View::update
//                              view.cpp:1913 (9)
//         00535210     SUB        ESP,0xc
//         00535213     PUSH       EBX
//         00535214     PUSH       EBP
//         00535215     PUSH       ESI
//         00535216     MOV        ESI,this
//         00535218     PUSH       EDI
//                              view.cpp:1922 (14)
//         00535219     MOV        EBX,dword ptr [ESI + 0x100]
//         0053521f     TEST       EBX,EBX
//         00535221     JZ         LAB_00535473
//                              view.cpp:1925 (42)
//         00535227     FLD        float ptr [EBX + 0x114]
//         0053522d     FCOMP      float ptr [ESI + 0x138]
//         00535233     FNSTSW     AX
//         00535235     TEST       AH,0x40
//         00535238     JZ         LAB_00535251
//         0053523a     FLD        float ptr [EBX + 0x118]
//         00535240     FCOMP      float ptr [ESI + 0x13c]
//         00535246     FNSTSW     AX
//         00535248     TEST       AH,0x40
//         0053524b     JNZ        LAB_00535473
//                               LAB_00535251                                                 XREF[1]:     00535238(j)
//                              view.cpp:1928 (18)
//         00535251     FLD        float ptr [EBX + 0x114]
//         00535257     CALL       __ftol                                           undefined __ftol()
//         0053525c     MOV        word ptr [ESI + 0x122],AX
//                              view.cpp:1929 (11)
//         00535263     FLD        float ptr [EBX + 0x118]
//         00535269     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:1932 (21)
//         0053526e     MOV        DI,word ptr [ESI + 0x122]
//         00535275     MOV        word ptr [ESI + 0x124],AX
//         0053527c     MOVSX      this,DI
//         0053527f     MOV        dword ptr [ESP + col_adj],this
//                              view.cpp:1942 (77)
//         00535283     MOV        BP,word ptr [ESI + 0x90]
//         0053528a     FILD       dword ptr [ESP + col_adj]
//         0053528e     MOVSX      EDX,AX
//         00535291     FSUBR      float ptr [EBX + 0x114]
//         00535297     MOV        EAX,dword ptr [EBX + 0x114]
//         0053529d     MOV        dword ptr [ESP + local_8],EDX
//         005352a1     FILD       dword ptr [ESP + local_8]
//         005352a5     FSUBR      float ptr [EBX + 0x118]
//         005352ab     MOV        dword ptr [ESI + 0x138],EAX
//         005352b1     MOV        EAX,dword ptr [ESI + 0x14]
//         005352b4     MOV        this,dword ptr [EBX + 0x118]
//         005352ba     MOV        BX,word ptr [ESI + 0x8c]
//         005352c1     CDQ
//         005352c2     FSTP       float ptr [ESP + local_8]
//         005352c6     SUB        EAX,EDX
//         005352c8     MOV        dword ptr [ESI + 0x13c],this
//         005352ce     SAR        EAX,0x1
//                              view.cpp:1944 (12)
//         005352d0     FMUL       float ptr [DAT_005776b4]                         = align(3)
//         005352d6     ADD        BX,AX
//         005352d9     MOV        EAX,dword ptr [ESI + 0x18]
//                              view.cpp:1945 (20)
//         005352dc     FLD        float ptr [ESP + local_8]
//         005352e0     CDQ
//         005352e1     FMUL       float ptr [DAT_005776b4]                         = align(3)
//         005352e7     SUB        EAX,EDX
//         005352e9     MOV        this,word ptr [ESI + 0x10c]
//                              view.cpp:1947 (66)
//         005352f0     MOVSX      EDX,word ptr [ESI + 0x108]
//         005352f7     MOV        dword ptr [ESP + local_8],EDX
//         005352fb     SUB        EBX,this
//         005352fd     FILD       dword ptr [ESP + local_8]
//         00535301     FLD        ST1
//         00535303     MOV        this,word ptr [ESI + 0x10e]
//         0053530a     MOV        word ptr [ESI + 0x11a],BX
//         00535311     FMUL       ST1
//         00535313     FLD        ST3
//         00535315     FMUL       ST2
//         00535317     SAR        EAX,0x1
//         00535319     ADD        BP,AX
//         0053531c     FADDP
//         0053531e     SUB        EBP,this
//         00535320     MOV        word ptr [ESI + 0x11c],BP
//         00535327     CALL       __ftol                                           undefined __ftol()
//         0053532c     NEG        EAX
//         0053532e     MOV        dword ptr [ESP + local_8],EAX
//                              view.cpp:1948 (40)
//         00535332     MOVSX      EAX,word ptr [ESI + 0x10a]
//         00535339     FSTP       ST0
//         0053533b     MOV        dword ptr [ESP + local_4],EAX
//         0053533f     FILD       dword ptr [ESP + local_4]
//         00535343     FXCH
//         00535345     FMUL       ST1
//         00535347     FXCH       ST2
//         00535349     FMUL       ST1
//         0053534b     FSUBP      ST2,ST0
//         0053534d     FXCH
//         0053534f     CALL       __ftol                                           undefined __ftol()
//         00535354     MOV        EDX,dword ptr [ESI + 0x10e]
//                              view.cpp:1950 (6)
//         0053535a     MOV        this,dword ptr [ESP + local_8]
//         0053535e     ADD        EAX,EDX
//                              view.cpp:1953 (58)
//         00535360     MOV        EDX,dword ptr [ESI + 0x104]
//         00535366     NEG        EAX
//         00535368     ADD        EBX,this
//         0053536a     MOV        this,dword ptr [ESP + col_adj]
//         0053536e     ADD        EBP,EAX
//         00535370     MOV        word ptr [ESI + 0x11a],BX
//         00535377     MOV        dword ptr [ESP + local_4],EBP
//         0053537b     MOV        word ptr [ESI + 0x11c],BP
//         00535382     MOVSX      EBP,word ptr [ESI + 0x124]
//         00535389     FSTP       ST0
//         0053538b     MOV        EDX,dword ptr [EDX + 0x8d8c]
//         00535391     MOV        EDX,dword ptr [EDX + EBP*0x4]
//         00535394     LEA        this,[ECX + ECX*0x2]
//         00535397     LEA        EBP,[EDX + this->_padding_*0x8]
//                              view.cpp:1955 (9)
//         0053539a     MOVSX      EDX,BX
//         0053539d     MOVSX      this,word ptr [EBP]
//         005353a1     SUB        this,EDX
//                              view.cpp:1956 (39)
//         005353a3     MOVSX      EDX,word ptr [ESI + 0x110]
//         005353aa     MOV        dword ptr [ESI + 0x130],this
//         005353b0     XOR        this,this
//         005353b2     MOV        this,byte ptr [EBP + 0x5]
//         005353b5     SHR        this,0x5
//         005353b8     IMUL       EDX,this
//         005353bb     MOVSX      this,word ptr [EBP + 0x2]
//         005353bf     ADD        EDX,this
//         005353c1     MOV        this,dword ptr [ESP + local_4]
//         005353c5     MOVSX      EBP,this
//         005353c8     SUB        EDX,EBP
//                              view.cpp:1965 (29)
//         005353ca     MOV        EBP,dword ptr [ESP + local_8]
//         005353ce     MOV        dword ptr [ESI + 0x134],EDX
//         005353d4     MOV        DX,DI
//         005353d7     ADD        DX,word ptr [ESI + 0x124]
//         005353de     IMUL       EDX,dword ptr [ESI + 0x10c]
//         005353e5     ADD        EDX,EBP
//                              view.cpp:1966 (29)
//         005353e7     MOV        BP,word ptr [ESI + 0x10e]
//         005353ee     MOV        word ptr [ESI + 0x11e],DX
//         005353f5     MOV        DX,word ptr [ESI + 0x124]
//         005353fc     SUB        DX,DI
//         005353ff     IMUL       EDX,EBP
//         00535402     ADD        EDX,EAX
//                              view.cpp:1970 (21)
//         00535404     MOV        AX,word ptr [ESI + 0x124]
//         0053540b     MOV        word ptr [ESI + 0x12c],AX
//         00535412     MOV        word ptr [ESI + 0x120],DX
//                              view.cpp:1975 (15)
//         00535419     MOVSX      EAX,word ptr [ESI + 0x116]
//         00535420     CDQ
//         00535421     SUB        EAX,EDX
//         00535423     SAR        EAX,0x1
//         00535425     ADD        EAX,0x2
//                              view.cpp:1977 (9)
//         00535428     SUB        word ptr [ESI + 0x12c],AX
//         0053542f     SUB        EDI,EAX
//                              view.cpp:1978 (18)
//         00535431     IMUL       EAX,dword ptr [ESI + 0x10c]
//         00535438     SHL        EAX,0x1
//         0053543a     SUB        EBX,EAX
//         0053543c     MOV        word ptr [ESI + 0x12a],DI
//                              view.cpp:1980 (20)
//         00535443     MOVSX      EAX,word ptr [ESI + 0x118]
//         0053544a     CDQ
//         0053544b     SUB        EAX,EDX
//         0053544d     MOV        word ptr [ESI + 0x126],BX
//         00535454     SAR        EAX,0x1
//         00535456     INC        EAX
//                              view.cpp:1981 (7)
//         00535457     ADD        word ptr [ESI + 0x12a],AX
//                              view.cpp:1982 (7)
//         0053545e     SUB        word ptr [ESI + 0x12c],AX
//                              view.cpp:1983 (14)
//         00535465     IMUL       EAX,EBP
//         00535468     SHL        EAX,0x1
//         0053546a     SUB        this,EAX
//         0053546c     MOV        word ptr [ESI + 0x128],this
//                               LAB_00535473                                                 XREF[2]:     00535221(j), 0053524b(j)
//                              view.cpp:1985 (8)
//         00535473     POP        EDI
//         00535474     POP        ESI
//         00535475     POP        EBP
//         00535476     POP        EBX
//         00535477     ADD        ESP,0xc
//         0053547a     RET
//         0053547b     ??         90h
//         0053547c     NOP
//         0053547d     NOP
//         0053547e     NOP
//         0053547f     NOP
    return;
}

void RGE_View::draw_view(uchar param_1, TDrawArea* param_2) {
    /* TODO: Stub */
//                              void __thiscall draw_view(RGE_View * this, uchar param_1, TDrawArea
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0053552e(R)
//              TDrawArea *       Stack[0x8]:4   param_2                   XREF[1]:     00535480(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00535512(R)
//              tagRECT           Stack[-0x14]   save_render_rect          XREF[0,4]:   0053551a(R), 00535516(R), 005354be(W), 00535539(R)
//              undefined4        Stack[-0x24]:4 local_24                  XREF[1]:     00535549(W)
//              undefined4        Stack[-0x28]:4 local_28                  XREF[1]:     00535546(W)
//              undefined4        Stack[-0x2c]:4 local_2c                  XREF[1]:     00535543(W)
//              undefined4        Stack[-0x30]:4 local_30                  XREF[1]:     00535541(*)
//                               ?draw_view@RGE_View@@IAEXEPAVTDrawArea@@@Z                   XREF[1]:     draw:005351a9(c)
//                               RGE_View::draw_view
//                              view.cpp:1993 (17)
//         00535480     MOV        EAX,dword ptr [ESP + param_2]
//         00535484     SUB        ESP,0x10
//         00535487     TEST       EAX,EAX
//         00535489     PUSH       EBX
//         0053548a     PUSH       EBP
//         0053548b     PUSH       ESI
//         0053548c     PUSH       EDI
//         0053548d     MOV        ESI,this
//         0053548f     JNZ        LAB_00535494
//                              view.cpp:2002 (3)
//         00535491     MOV        EAX,dword ptr [ESI + 0x20]
//                               LAB_00535494                                                 XREF[1]:     0053548f(j)
//                              view.cpp:2004 (6)
//         00535494     MOV        dword ptr [ESI + 0xf4],EAX
//                              view.cpp:2006 (10)
//         0053549a     MOV        this,EAX
//         0053549c     CMP        this,dword ptr [ESI + 0x324]
//         005354a2     JNZ        LAB_00535512
//                              view.cpp:2009 (6)
//         005354a4     MOV        EBX,dword ptr [ESI + 0x8c]
//                              view.cpp:2011 (12)
//         005354aa     MOV        EAX,dword ptr [ESI + 0x94]
//         005354b0     MOV        EDI,dword ptr [ESI + 0x90]
//                              view.cpp:2012 (6)
//         005354b6     MOV        EBP,dword ptr [ESI + 0x98]
//                              view.cpp:2014 (8)
//         005354bc     MOV        EDX,EBX
//         005354be     MOV        dword ptr [ESP + save_render_rect.bottom],EAX
//         005354c2     SUB        EDX,EBX
//                              view.cpp:2016 (8)
//         005354c4     SUB        EAX,EBX
//         005354c6     MOV        dword ptr [ESI + 0x8c],EDX
//                              view.cpp:2019 (7)
//         005354cc     SUB        word ptr [ESI + 0x126],BX
//                              view.cpp:2020 (27)
//         005354d3     SUB        word ptr [ESI + 0x128],DI
//         005354da     MOV        EDX,EDI
//         005354dc     MOV        dword ptr [ESI + 0x94],EAX
//         005354e2     MOV        EAX,EBP
//         005354e4     SUB        EDX,EDI
//         005354e6     SUB        EAX,EDI
//         005354e8     MOV        dword ptr [ESI + 0x90],EDX
//                              view.cpp:2022 (12)
//         005354ee     MOV        EDX,dword ptr [ESI + 0x130]
//         005354f4     MOV        dword ptr [ESI + 0x98],EAX
//                              view.cpp:2023 (36)
//         005354fa     MOV        EAX,dword ptr [ESI + 0x134]
//         00535500     ADD        EDX,EBX
//         00535502     ADD        EAX,EDI
//         00535504     MOV        dword ptr [ESI + 0x130],EDX
//         0053550a     MOV        dword ptr [ESI + 0x134],EAX
//         00535510     JMP        LAB_0053551e
//                               LAB_00535512                                                 XREF[1]:     005354a2(j)
//         00535512     MOV        EBP,dword ptr [ESP + local_4]
//         00535516     MOV        EDI,dword ptr [ESP + save_render_rect.right]
//         0053551a     MOV        EBX,dword ptr [ESP + save_render_rect.top]
//                               LAB_0053551e                                                 XREF[1]:     00535510(j)
//                              view.cpp:2027 (16)
//         0053551e     PUSH       0x1
//         00535520     PUSH       s_view::draw_view                                = "view::draw_view"
//         00535525     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
//         0053552a     TEST       EAX,EAX
//         0053552c     JZ         LAB_0053557d
//                              view.cpp:2029 (8)
//         0053552e     MOV        EAX,dword ptr [ESP + param_1]
//         00535532     CMP        AL,0xa
//         00535534     JNZ        LAB_00535555
//                              view.cpp:2030 (29)
//         00535536     SUB        ESP,0x10
//         00535539     MOV        EDX,dword ptr [ESP + save_render_rect.bottom]
//         0053553d     MOV        this,ESP
//         0053553f     PUSH       0xa
//         00535541     MOV        dword ptr [this->_padding_]=>local_30,EBX
//         00535543     MOV        dword ptr [ECX + local_2c],EDI
//         00535546     MOV        dword ptr [ECX + local_28],EDX
//         00535549     MOV        dword ptr [ECX + local_24],EBP
//         0053554c     MOV        this,ESI
//         0053554e     CALL       RGE_View::view_function_terrain                  long view_function_terrain(RGE_View * this, u
//                              view.cpp:2031 (2)
//         00535553     JMP        LAB_0053556d
//                               LAB_00535555                                                 XREF[1]:     00535534(j)
//                              view.cpp:2032 (24)
//         00535555     PUSH       0x0
//         00535557     PUSH       0x0
//         00535559     PUSH       0x0
//         0053555b     PUSH       0x0
//         0053555d     PUSH       0x0
//         0053555f     PUSH       0x0
//         00535561     PUSH       0x0
//         00535563     PUSH       0x0
//         00535565     PUSH       EAX
//         00535566     MOV        this,ESI
//         00535568     CALL       RGE_View::view_function                          long view_function(RGE_View * this, uchar par
//                               LAB_0053556d                                                 XREF[1]:     00535553(j)
//                              view.cpp:2035 (16)
//         0053556d     MOV        this,dword ptr [ESI + 0xf4]
//         00535573     PUSH       s_view::draw_view                                = "view::draw_view"
//         00535578     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                               LAB_0053557d                                                 XREF[1]:     0053552c(j)
//                              view.cpp:2038 (16)
//         0053557d     MOV        EAX,dword ptr [ESI + 0xf4]
//         00535583     MOV        this,dword ptr [ESI + 0x324]
//         00535589     CMP        EAX,this
//         0053558b     JNZ        LAB_005355ef
//                              view.cpp:2043 (6)
//         0053558d     MOV        this,dword ptr [ESI + 0x94]
//                              view.cpp:2044 (18)
//         00535593     MOV        EAX,dword ptr [ESI + 0x98]
//         00535599     MOV        EBP,dword ptr [ESI + 0x8c]
//         0053559f     MOV        EDX,dword ptr [ESI + 0x90]
//                              view.cpp:2046 (7)
//         005355a5     ADD        word ptr [ESI + 0x126],BX
//                              view.cpp:2047 (17)
//         005355ac     ADD        word ptr [ESI + 0x128],DI
//         005355b3     ADD        this,EBX
//         005355b5     ADD        EAX,EDI
//         005355b7     MOV        dword ptr [ESI + 0x94],this
//                              view.cpp:2049 (12)
//         005355bd     MOV        this,dword ptr [ESI + 0x130]
//         005355c3     MOV        dword ptr [ESI + 0x98],EAX
//                              view.cpp:2050 (38)
//         005355c9     MOV        EAX,dword ptr [ESI + 0x134]
//         005355cf     ADD        EBP,EBX
//         005355d1     ADD        EDX,EDI
//         005355d3     SUB        this,EBX
//         005355d5     SUB        EAX,EDI
//         005355d7     MOV        dword ptr [ESI + 0x8c],EBP
//         005355dd     MOV        dword ptr [ESI + 0x90],EDX
//         005355e3     MOV        dword ptr [ESI + 0x130],this
//         005355e9     MOV        dword ptr [ESI + 0x134],EAX
//                               LAB_005355ef                                                 XREF[1]:     0053558b(j)
//                              view.cpp:2055 (10)
//         005355ef     MOV        dword ptr [ESI + 0xf4],0x0
//                              view.cpp:2056 (10)
//         005355f9     POP        EDI
//         005355fa     POP        ESI
//         005355fb     POP        EBP
//         005355fc     POP        EBX
//         005355fd     ADD        ESP,0x10
//         00535600     RET        0x8
//         00535603     ??         90h
//         00535604     NOP
//         00535605     NOP
//         00535606     NOP
//         00535607     NOP
//         00535608     NOP
//         00535609     NOP
//         0053560a     NOP
//         0053560b     NOP
//         0053560c     NOP
//         0053560d     NOP
//         0053560e     NOP
//         0053560f     NOP
    return;
}

void RGE_View::draw_object_outline() {
    /* TODO: Stub */
//                              void __thiscall draw_object_outline(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[1,3]:   0053567a(R), 00535692(*), 005356c7(*), 005356c2(*)
//              tagPOINT          Stack[-0x20]:8 point                     XREF[0,2]:   0053564c(*), 0053565c(R)
//              short             Stack[-0x24]:2 y4
//              short             Stack[-0x28]:2 x3
//              short             Stack[-0x2c]:2 scr_y
//              uchar             Stack[-0x30]:1 frame_color
//              short             Stack[-0x34]:2 scr_x
//              short             Stack[-0x36]:2 y1
//              short             Stack[-0x38]:2 x2
//              short             Stack[-0x3a]:2 y3
//              short             Stack[-0x3c]:2 x4
//              short             Stack[-0x3e]:2 y2
//              short             Stack[-0x40]:2 x1
//                               ?draw_object_outline@RGE_View@@IAEXXZ                        XREF[1]:     view_function_terrain:005375dc(c)
//                               RGE_View::draw_object_outline
//                              view.cpp:2062 (9)
//         00535610     SUB        ESP,0x3c
//         00535613     PUSH       EBX
//         00535614     PUSH       EBP
//         00535615     PUSH       ESI
//         00535616     PUSH       EDI
//         00535617     MOV        EDI,this
//                              view.cpp:2075 (13)
//         00535619     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053561f     MOV        SI,word ptr [this->_padding_ + 0x3fc]
//                              view.cpp:2076 (10)
//         00535626     CMP        SI,-0x1
//         0053562a     JZ         LAB_005358a1
//                              view.cpp:2078 (14)
//         00535630     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         00535635     MOV        EDX,dword ptr [EAX + 0x24]
//         00535638     MOVSX      this,SI
//         0053563b     MOV        ESI,dword ptr [EDX + this->_padding_*0x4]
//                              view.cpp:2079 (8)
//         0053563e     TEST       ESI,ESI
//         00535640     JZ         LAB_005358a1
//                              view.cpp:2085 (16)
//         00535646     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053564c     LEA        EAX=>point.y,[ESP + 0x30]
//         00535650     PUSH       EAX
//         00535651     CALL       RGE_Base_Game::get_mouse_pos                     void get_mouse_pos(RGE_Base_Game * this, tagP
//                              view.cpp:2086 (60)
//         00535656     MOV        EBX,dword ptr [EDI + 0x8c]
//         0053565c     MOV        this,dword ptr [ESP + point.y]
//         00535660     CMP        this,EBX
//         00535662     JL         LAB_005358a1
//         00535668     CMP        this,dword ptr [EDI + 0x94]
//         0053566e     JG         LAB_005358a1
//         00535674     MOV        EDX,dword ptr [EDI + 0x90]
//         0053567a     MOV        EAX,dword ptr [ESP + pick_info.x]
//         0053567e     CMP        EAX,EDX
//         00535680     JL         LAB_005358a1
//         00535686     CMP        EAX,dword ptr [EDI + 0x98]
//         0053568c     JG         LAB_005358a1
//                              view.cpp:2088 (28)
//         00535692     LEA        EBP=>pick_info.y,[ESP + 0x38]
//         00535696     PUSH       0x0
//         00535698     SUB        EAX,EDX
//         0053569a     PUSH       EBP
//         0053569b     SUB        this,EBX
//         0053569d     PUSH       EAX
//         0053569e     PUSH       this
//         0053569f     PUSH       0x0
//         005356a1     PUSH       0x28
//         005356a3     MOV        this,EDI
//         005356a5     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//         005356aa     MOVZX      AX,AL
//                              view.cpp:2089 (10)
//         005356ae     CMP        AX,0x33
//         005356b2     JNZ        LAB_005358a1
//                              view.cpp:2091 (26)
//         005356b8     MOV        this,dword ptr [EDI + 0xfc]
//         005356be     MOV        EBX,dword ptr [ESI]
//         005356c0     PUSH       0x0
//         005356c2     LEA        EDX=>pick_info.scr_x,[ESP + 0x40]
//         005356c6     PUSH       this
//         005356c7     LEA        EAX=>pick_info.y,[ESP + 0x40]
//         005356cb     PUSH       EDX
//         005356cc     PUSH       EAX
//         005356cd     MOV        this,ESI
//         005356cf     CALL       dword ptr [EBX + 0x24]
//                              view.cpp:2092 (47)
//         005356d2     FLD        float ptr [ESP + 0x3c]
//         005356d6     LEA        this,[ESP + 0x24]
//         005356da     PUSH       0x1
//         005356dc     LEA        EDX,[ESP + 0x20]
//         005356e0     PUSH       this=>DAT_fffffff8
//         005356e1     PUSH       EDX=>DAT_fffffff4
//         005356e2     CALL       __ftol                                           undefined __ftol()
//         005356e7     FLD        float ptr [ESP + 0x44]
//         005356eb     PUSH       EAX=>DAT_fffffff0
//         005356ec     CALL       __ftol                                           undefined __ftol()
//         005356f1     PUSH       EAX
//         005356f2     MOV        this,EDI
//         005356f4     CALL       RGE_View::get_tile_screen_coords                 int get_tile_screen_coords(RGE_View * this, s
//         005356f9     TEST       EAX,EAX
//         005356fb     JZ         LAB_005358a1
//                              view.cpp:2094 (64)
//         00535701     LEA        EAX,[ESP + 0x2c]
//         00535705     LEA        this,[ESP + 0x14]
//         00535709     PUSH       EAX
//         0053570a     LEA        EDX,[ESP + 0x1a]
//         0053570e     PUSH       this=>DAT_fffffff8
//         0053570f     LEA        EAX,[ESP + 0x30]
//         00535713     PUSH       EDX=>DAT_fffffff4
//         00535714     LEA        this,[ESP + 0x1e]
//         00535718     PUSH       EAX=>DAT_fffffff0
//         00535719     LEA        EDX,[ESP + 0x28]
//         0053571d     PUSH       this
//         0053571e     LEA        EAX,[ESP + 0x2e]
//         00535722     PUSH       EDX
//         00535723     MOV        EDX,dword ptr [ESP + 0x54]
//         00535727     LEA        this,[ESP + 0x28]
//         0053572b     PUSH       EAX
//         0053572c     MOV        EAX,dword ptr [ESP + 0x54]
//         00535730     PUSH       this
//         00535731     MOV        this,dword ptr [EDI + 0xfc]
//         00535737     PUSH       EDX
//         00535738     PUSH       EAX
//         00535739     PUSH       this
//         0053573a     MOV        this,ESI
//         0053573c     CALL       RGE_Master_Static_Object::alignment_box          uchar alignment_box(RGE_Master_Static_Object
//                              view.cpp:2095 (46)
//         00535741     MOV        DL,byte ptr [ESI + 0x64]
//         00535744     MOV        EAX,dword ptr [ESP + 0x3c]
//         00535748     MOV        this,dword ptr [ESP + 0x38]
//         0053574c     PUSH       0x1
//         0053574e     PUSH       offset DAT_fffffff8
//         00535750     PUSH       offset DAT_fffffff4
//         00535752     PUSH       0x0=>DAT_fffffff0
//         00535754     PUSH       EDX
//         00535755     PUSH       0x1
//         00535757     PUSH       0x0
//         00535759     PUSH       EAX
//         0053575a     PUSH       this
//         0053575b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00535761     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         00535766     PUSH       EAX
//         00535767     MOV        this,ESI
//         00535769     CALL       dword ptr [EBX + 0x20]
//         0053576c     XOR        this,this
//                              view.cpp:2097 (12)
//         0053576f     MOV        dword ptr [fog_next_shape],0x1
//         00535779     MOV        this,AL
//                              view.cpp:2099 (5)
//         0053577b     TEST       this,this
//         0053577e     JNZ        LAB_0053578c
//                              view.cpp:2101 (10)
//         00535780     MOV        dword ptr [fog_next_shape],0x5
//                              view.cpp:2103 (2)
//         0053578a     JMP        LAB_005357b8
//                               LAB_0053578c                                                 XREF[1]:     0053577e(j)
//                              view.cpp:2105 (15)
//         0053578c     MOV        EDX,dword ptr [EDI + 0xfc]
//         00535792     MOV        EAX,dword ptr [EDX + 0x4]
//         00535795     SHR        EAX,0x7
//         00535798     AND        EAX,0x7
//                              view.cpp:2106 (19)
//         0053579b     CMP        EAX,0x4
//         0053579e     JNC        LAB_005357a5
//         005357a0     ADD        EAX,0x24
//         005357a3     JMP        LAB_005357ae
//                               LAB_005357a5                                                 XREF[1]:     0053579e(j)
//         005357a5     MOV        EDX,0x2c
//         005357aa     SUB        EDX,EAX
//         005357ac     MOV        EAX,EDX
//                               LAB_005357ae                                                 XREF[1]:     005357a3(j)
//                              view.cpp:2107 (10)
//         005357ae     SHL        EAX,0x4
//         005357b1     OR         AL,0x9
//         005357b3     MOV        [fog_next_shape],EAX
//                               LAB_005357b8                                                 XREF[1]:     0053578a(j)
//                              view.cpp:2110 (27)
//         005357b8     MOV        EBP,dword ptr [ESP + 0x28]
//         005357bc     MOVSX      EAX,word ptr [ESP + 0x10]
//         005357c1     MOVSX      EDX,BP
//         005357c4     SUB        EAX,EDX
//         005357c6     CDQ
//         005357c7     SUB        EAX,EDX
//         005357c9     SAR        EAX,0x1
//         005357cb     ADD        EAX,EBP
//         005357cd     MOV        EBP,dword ptr [ESP + 0x1c]
//         005357d1     ADD        EBP,EAX
//                              view.cpp:2111 (35)
//         005357d3     MOVSX      EAX,word ptr [ESP + 0x12]
//         005357d8     MOV        dword ptr [ESP + 0x1c],EBP
//         005357dc     MOV        EBP,dword ptr [ESP + 0x2c]
//         005357e0     MOVSX      EDX,BP
//         005357e3     SUB        EAX,EDX
//         005357e5     CDQ
//         005357e6     SUB        EAX,EDX
//         005357e8     SAR        EAX,0x1
//         005357ea     ADD        EAX,EBP
//         005357ec     MOV        EBP,dword ptr [ESP + 0x24]
//         005357f0     ADD        EBP,EAX
//         005357f2     MOV        dword ptr [ESP + 0x24],EBP
//                              view.cpp:2113 (11)
//         005357f6     MOV        EAX,dword ptr [ESI + 0x18]
//         005357f9     TEST       EAX,EAX
//         005357fb     JZ         LAB_00535897
//                              view.cpp:2116 (8)
//         00535801     MOVSX      EAX,BP
//         00535804     MOV        [SDI_Draw_Line],EAX
//                              view.cpp:2118 (9)
//         00535809     MOV        DL,byte ptr [ESI + 0xa8]
//         0053580f     AND        EDX,0x1
//                              view.cpp:2119 (22)
//         00535812     TEST       this,this
//         00535815     JNZ        LAB_00535823
//         00535817     MOV        this,byte ptr [ESI + 0xa9]
//         0053581d     MOV        byte ptr [ESP + 0x20],this
//         00535821     JMP        LAB_00535828
//                               LAB_00535823                                                 XREF[1]:     00535815(j)
//         00535823     MOV        byte ptr [ESP + 0x20],0x97
//                               LAB_00535828                                                 XREF[1]:     00535821(j)
//                              view.cpp:2123 (34)
//         00535828     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053582e     CMP        dword ptr [ECX + this+0x1b4],0x8
//         00535835     JNZ        LAB_0053586e
//         00535837     CMP        dword ptr [ECX + this+0x1b8],0x1
//         0053583e     JNZ        LAB_0053586e
//         00535840     MOV        EAX,dword ptr [EDI + 0x174]
//         00535846     TEST       EAX,EAX
//         00535848     JZ         LAB_0053586e
//                              view.cpp:2124 (34)
//         0053584a     MOV        this,dword ptr [ESP + 0x20]
//         0053584e     PUSH       this
//         0053584f     PUSH       EDX=>DAT_fffffff8
//         00535850     XOR        EDX,EDX
//         00535852     PUSH       0x0=>DAT_fffffff4
//         00535854     MOV        DL,byte ptr [EAX + 0x35]
//         00535857     MOV        EAX,dword ptr [EAX + 0xc]
//         0053585a     PUSH       EDX=>DAT_fffffff0
//         0053585b     MOV        EDX,dword ptr [ESP + 0x2c]
//         0053585f     MOV        this,dword ptr [EAX + 0x108]
//         00535865     MOV        EAX,dword ptr [EDI + 0x20]
//         00535868     PUSH       this
//         00535869     PUSH       EBP
//         0053586a     PUSH       EDX
//         0053586b     PUSH       EAX
//                              view.cpp:2125 (2)
//         0053586c     JMP        LAB_00535892
//                               LAB_0053586e                                                 XREF[3]:     00535835(j), 0053583e(j),
//                                                                                                         00535848(j)
//                              view.cpp:2126 (41)
//         0053586e     MOV        EAX,dword ptr [ESP + 0x20]
//         00535872     PUSH       EAX
//         00535873     PUSH       EDX=>DAT_fffffff8
//         00535874     PUSH       0x0=>DAT_fffffff4
//         00535876     PUSH       0x0=>DAT_fffffff0
//         00535878     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
//         0053587d     MOV        this,dword ptr [EAX + 0x108]
//         00535883     MOV        EDX,dword ptr [ESP + 0x34]
//         00535887     MOV        EAX,dword ptr [ESP + 0x2c]
//         0053588b     PUSH       this
//         0053588c     MOV        this,dword ptr [EDI + 0x20]
//         0053588f     PUSH       EDX
//         00535890     PUSH       EAX
//         00535891     PUSH       this
//                               LAB_00535892                                                 XREF[1]:     0053586c(j)
//         00535892     MOV        this,ESI
//         00535894     CALL       dword ptr [EBX + 0x34]
//                               LAB_00535897                                                 XREF[1]:     005357fb(j)
//                              view.cpp:2130 (10)
//         00535897     MOV        dword ptr [fog_next_shape],0x0
//                               LAB_005358a1                                                 XREF[8]:     0053562a(j), 00535640(j),
//                                                                                                         00535662(j), 0053566e(j),
//                                                                                                         00535680(j), 0053568c(j),
//                                                                                                         005356b2(j), 005356fb(j)
//                              view.cpp:2207 (8)
//         005358a1     POP        EDI
//         005358a2     POP        ESI
//         005358a3     POP        EBP
//         005358a4     POP        EBX
//         005358a5     ADD        ESP,0x3c
//         005358a8     RET
//         005358a9     ??         90h
//         005358aa     NOP
//         005358ab     NOP
//         005358ac     NOP
//         005358ad     NOP
//         005358ae     NOP
//         005358af     NOP
    return;
}

void RGE_View::draw_paint_brush() {
    /* TODO: Stub */
//                              void __thiscall draw_paint_brush(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[1,7]:   005358f1(R), 0053590f(*), 00535941(R), 00535967(W),
//                                                                                     005359a3(R), 0053596b(R), 00535996(W), 005359ac(R)
//              tagPOINT          Stack[-0x20]:8 point                     XREF[4,2]:   00535959(W), 0053595d(R), 00535988(W), 0053598c(R),
//                                                                                     005358c9(*), 005358d3(R)
//                               ?draw_paint_brush@RGE_View@@IAEXXZ                           XREF[1]:     draw:00535166(c)
//                               RGE_View::draw_paint_brush
//                              view.cpp:2213 (4)
//         005358b0     SUB        ESP,0x20
//         005358b3     PUSH       EDI
//                              view.cpp:2221 (15)
//         005358b4     PUSH       -0x1
//         005358b6     PUSH       -0x1
//         005358b8     PUSH       -0x1
//         005358ba     MOV        EDI,this
//         005358bc     PUSH       -0x1
//         005358be     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              view.cpp:2223 (16)
//         005358c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         005358c9     LEA        EAX=>point.y,[ESP + 0x8]
//         005358cd     PUSH       EAX
//         005358ce     CALL       RGE_Base_Game::get_mouse_pos                     void get_mouse_pos(RGE_Base_Game * this, tagP
//                              view.cpp:2224 (60)
//         005358d3     MOV        this,dword ptr [ESP + point.y]
//         005358d7     MOV        EAX,dword ptr [EDI + 0x8c]
//         005358dd     CMP        this,EAX
//         005358df     JL         LAB_005359d3
//         005358e5     CMP        this,dword ptr [EDI + 0x94]
//         005358eb     JG         LAB_005359d3
//         005358f1     MOV        EAX,dword ptr [ESP + pick_info.x]
//         005358f5     MOV        EDX,dword ptr [EDI + 0x90]
//         005358fb     CMP        EAX,EDX
//         005358fd     JL         LAB_005359d3
//         00535903     CMP        EAX,dword ptr [EDI + 0x98]
//         00535909     JG         LAB_005359d3
//                              view.cpp:2226 (24)
//         0053590f     LEA        EDX=>pick_info.y,[ESP + 0x10]
//         00535913     PUSH       0x0
//         00535915     PUSH       EDX
//         00535916     PUSH       EAX
//         00535917     PUSH       this
//         00535918     PUSH       0x0
//         0053591a     PUSH       0x28
//         0053591c     MOV        this,EDI
//         0053591e     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//         00535923     MOVZX      AX,AL
//                              view.cpp:2227 (10)
//         00535927     CMP        AX,0x33
//         0053592b     JNZ        LAB_005359d3
//                              view.cpp:2229 (16)
//         00535931     MOV        EAX,[rge_base_game]                              = 00000000
//         00535936     PUSH       ESI
//         00535937     PUSH       EBX
//         00535938     CMP        dword ptr [EAX + 0x1b4],0x13
//         0053593f     JNZ        LAB_0053599c
//                              view.cpp:2231 (42)
//         00535941     FLD        float ptr [ESP + pick_info.y]
//         00535945     FMUL       float ptr [DAT_005776b8]                         = ABh
//         0053594b     CALL       __ftol                                           undefined __ftol()
//         00535950     MOV        this,EAX
//         00535952     SHL        this,0x2
//         00535955     SUB        this,EAX
//         00535957     NEG        this
//         00535959     MOV        dword ptr [ESP + point.x],this
//         0053595d     FILD       dword ptr [ESP + point.x]
//         00535961     FSUBR      float ptr [DAT_005776bc]
//         00535967     FSTP       float ptr [ESP + pick_info.y]
//                              view.cpp:2232 (17)
//         0053596b     FLD        float ptr [ESP + pick_info.scr_x]
//         0053596f     FMUL       float ptr [DAT_005776b8]                         = ABh
//         00535975     CALL       __ftol                                           undefined __ftol()
//         0053597a     MOV        EDX,EAX
//                              view.cpp:2233 (30)
//         0053597c     MOV        EBX,0x3
//         00535981     SHL        EDX,0x2
//         00535984     SUB        EDX,EAX
//         00535986     NEG        EDX
//         00535988     MOV        dword ptr [ESP + point.x],EDX
//         0053598c     FILD       dword ptr [ESP + point.x]
//         00535990     FSUBR      float ptr [DAT_005776bc]
//         00535996     FSTP       float ptr [ESP + pick_info.scr_x]
//                              view.cpp:2235 (2)
//         0053599a     JMP        LAB_005359a3
//                               LAB_0053599c                                                 XREF[1]:     0053593f(j)
//                              view.cpp:2236 (7)
//         0053599c     MOV        BX,word ptr [EAX + 0x402]
//                               LAB_005359a3                                                 XREF[1]:     0053599a(j)
//                              view.cpp:2238 (9)
//         005359a3     FLD        float ptr [ESP + pick_info.y]
//         005359a7     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:2239 (11)
//         005359ac     FLD        float ptr [ESP + pick_info.scr_x]
//         005359b0     MOV        ESI,EAX
//         005359b2     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:2247 (28)
//         005359b7     MOVSX      this,BX
//         005359ba     SAR        this,0x1
//         005359bc     LEA        EDX,[EAX + this->_padding_*0x1]
//         005359bf     SUB        EAX,this
//         005359c1     PUSH       EDX
//         005359c2     LEA        EDX,[ESI + this->_padding_*0x1]
//         005359c5     PUSH       EDX
//         005359c6     SUB        ESI,this
//         005359c8     PUSH       EAX
//         005359c9     PUSH       ESI
//         005359ca     MOV        this,EDI
//         005359cc     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//         005359d1     POP        EBX
//         005359d2     POP        ESI
//                               LAB_005359d3                                                 XREF[5]:     005358df(j), 005358eb(j),
//                                                                                                         005358fd(j), 00535909(j),
//                                                                                                         0053592b(j)
//                              view.cpp:2265 (5)
//         005359d3     POP        EDI
//         005359d4     ADD        ESP,0x20
//         005359d7     RET
//         005359d8     ??         90h
//         005359d9     NOP
//         005359da     NOP
//         005359db     NOP
//         005359dc     NOP
//         005359dd     NOP
//         005359de     NOP
//         005359df     NOP
    return;
}

uchar RGE_View::pick_multi(uchar param_1, long param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
//                              uchar __thiscall pick_multi(RGE_View * this, uchar param_1, long par
//              uchar             AL:1           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00535a85(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00535aa7(R), 00535b25(R)
//              long              Stack[0xc]:4   param_3                   XREF[3]:     00535a8b(R), 00535b0b(R), 00535b8e(W)
//              long              Stack[0x10]:4  param_4                   XREF[3]:     00535aa2(R), 00535b21(R), 00535b7f(W)
//              long              Stack[0x14]:4  param_5                   XREF[2]:     00535a98(R), 00535b29(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00535ab5(W), 00535afb(W), 00535b0f(R)
//              int               Stack[-0x8]:4  picked_any
//                               ?pick_multi@RGE_View@@QAEEEJJJJ@Z                            XREF[1]:     end_scroll_view:0053aa1b(c)
//                               RGE_View::pick_multi
//                              view.cpp:2306 (5)
//         00535a80     PUSH       this
//         00535a81     PUSH       EBX
//         00535a82     PUSH       EBP
//         00535a83     PUSH       ESI
//         00535a84     PUSH       EDI
//                              view.cpp:2317 (59)
//         00535a85     MOV        EAX,dword ptr [ESP + param_1]
//         00535a89     MOV        EDI,this
//         00535a8b     MOV        EBX,dword ptr [ESP + param_3]
//         00535a8f     PUSH       0x1
//         00535a91     MOV        this,dword ptr [EDI + 0x100]
//         00535a97     PUSH       EAX
//         00535a98     MOV        EAX,dword ptr [ESP + param_5]
//         00535a9c     XOR        ESI,ESI
//         00535a9e     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         00535aa2     MOV        this,dword ptr [ESP + param_4]
//         00535aa6     PUSH       EDX
//         00535aa7     MOV        EDX,dword ptr [ESP + param_2]
//         00535aab     PUSH       0x14
//         00535aad     PUSH       0xa
//         00535aaf     PUSH       EAX
//         00535ab0     PUSH       this
//         00535ab1     PUSH       EBX
//         00535ab2     PUSH       EDX
//         00535ab3     MOV        this,EDI
//         00535ab5     MOV        dword ptr [ESP + local_4],ESI
//         00535ab9     CALL       RGE_View::pick_multi_objects                     int pick_multi_objects(RGE_View * this, int p
//         00535abe     MOV        EBP,EAX
//                              view.cpp:2319 (4)
//         00535ac0     TEST       EBP,EBP
//         00535ac2     JLE        LAB_00535b0f
//                              view.cpp:2315 (5)
//         00535ac4     MOV        EBX,Picked_Objects                               = 00000000
//                               LAB_00535ac9                                                 XREF[1]:     00535b09(j)
//                              view.cpp:2321 (7)
//         00535ac9     MOV        EAX,dword ptr [EBX]=>Picked_Objects              = 00000000
//         00535acb     CMP        EAX,-0x1
//         00535ace     JZ         LAB_00535b03
//                              view.cpp:2323 (15)
//         00535ad0     MOV        this,dword ptr [EDI + 0xfc]
//         00535ad6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00535adc     MOV        EAX,dword ptr [EDX + EAX*0x4]
//                              view.cpp:2324 (10)
//         00535adf     TEST       EAX,EAX
//         00535ae1     JZ         LAB_00535b03
//         00535ae3     CMP        byte ptr [EAX + 0x48],0x7
//         00535ae7     JNC        LAB_00535b03
//                              view.cpp:2326 (18)
//         00535ae9     MOV        this,dword ptr [EDI + 0x100]
//         00535aef     PUSH       0x0
//         00535af1     PUSH       EAX
//         00535af2     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00535af7     TEST       EAX,EAX
//         00535af9     JZ         LAB_00535b0b
//                              view.cpp:2329 (8)
//         00535afb     MOV        dword ptr [ESP + local_4],0x1
//                               LAB_00535b03                                                 XREF[3]:     00535ace(j), 00535ae1(j),
//                                                                                                         00535ae7(j)
//                              view.cpp:2319 (12)
//         00535b03     INC        ESI
//         00535b04     ADD        EBX,0xc
//         00535b07     CMP        ESI,EBP
//         00535b09     JL         LAB_00535ac9
//                               LAB_00535b0b                                                 XREF[1]:     00535af9(j)
//         00535b0b     MOV        EBX,dword ptr [ESP + param_3]
//                               LAB_00535b0f                                                 XREF[1]:     00535ac2(j)
//                              view.cpp:2334 (8)
//         00535b0f     MOV        EAX,dword ptr [ESP + local_4]
//         00535b13     TEST       EAX,EAX
//         00535b15     JZ         LAB_00535b21
//                              view.cpp:2335 (2)
//         00535b17     MOV        AL,0x1
//                              view.cpp:2370 (8)
//         00535b19     POP        EDI
//         00535b1a     POP        ESI
//         00535b1b     POP        EBP
//         00535b1c     POP        EBX
//         00535b1d     POP        this
//         00535b1e     RET        0x14
//                               LAB_00535b21                                                 XREF[1]:     00535b15(j)
//                              view.cpp:2337 (80)
//         00535b21     MOV        this,dword ptr [ESP + param_4]
//         00535b25     MOV        ESI,dword ptr [ESP + param_2]
//         00535b29     MOV        EAX,dword ptr [ESP + param_5]
//         00535b2d     SUB        this,ESI
//         00535b2f     SUB        EAX,EBX
//         00535b31     MOV        EDX,this
//         00535b33     CMP        this,EAX
//         00535b35     JL         LAB_00535b39
//         00535b37     MOV        EDX,EAX
//                               LAB_00535b39                                                 XREF[1]:     00535b35(j)
//         00535b39     CMP        EDX,0x32
//         00535b3c     JGE        LAB_00535b4a
//         00535b3e     CMP        this,EAX
//         00535b40     JGE        LAB_00535b46
//         00535b42     MOV        EDX,this
//         00535b44     JMP        LAB_00535b4f
//                               LAB_00535b46                                                 XREF[1]:     00535b40(j)
//         00535b46     MOV        EDX,EAX
//         00535b48     JMP        LAB_00535b4f
//                               LAB_00535b4a                                                 XREF[1]:     00535b3c(j)
//         00535b4a     MOV        EDX,0x32
//                               LAB_00535b4f                                                 XREF[2]:     00535b44(j), 00535b48(j)
//         00535b4f     PUSH       0x1
//         00535b51     PUSH       0x4
//         00535b53     PUSH       EDX
//         00535b54     PUSH       0x14
//         00535b56     CDQ
//         00535b57     SUB        EAX,EDX
//         00535b59     PUSH       0xa
//         00535b5b     SAR        EAX,0x1
//         00535b5d     ADD        EAX,EBX
//         00535b5f     PUSH       EAX
//         00535b60     MOV        EAX,this
//         00535b62     CDQ
//         00535b63     SUB        EAX,EDX
//         00535b65     MOV        this,EDI
//         00535b67     SAR        EAX,0x1
//         00535b69     ADD        EAX,ESI
//         00535b6b     PUSH       EAX
//         00535b6c     CALL       RGE_View::pick_objects                           int pick_objects(RGE_View * this, int param_1
//                              view.cpp:2338 (2)
//         00535b71     TEST       EAX,EAX
//                              view.cpp:2339 (6)
//         00535b73     JZ         LAB_00535c65
//                              view.cpp:2342 (2)
//         00535b79     XOR        this,this
//                              view.cpp:2343 (2)
//         00535b7b     XOR        EBX,EBX
//                              view.cpp:2344 (12)
//         00535b7d     TEST       EAX,EAX
//         00535b7f     MOV        dword ptr [ESP + param_4],this
//         00535b83     JLE        LAB_00535c45
//                              view.cpp:2370 (124)
//         00535b89     MOV        EBP,Picked_Objects                               = 00000000
//         00535b8e     MOV        dword ptr [ESP + param_3],EAX
//                               LAB_00535b92                                                 XREF[1]:     00535c3b(j)
//         00535b92     MOV        EAX,dword ptr [EBP]=>Picked_Objects              = 00000000
//         00535b95     TEST       EAX,EAX
//         00535b97     JL         LAB_00535c2f
//         00535b9d     MOV        this,dword ptr [EDI + 0xfc]
//         00535ba3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00535ba9     MOV        ESI,dword ptr [EDX + EAX*0x4]
//         00535bac     TEST       ESI,ESI
//         00535bae     JZ         LAB_00535c2f
//         00535bb0     CMP        byte ptr [ESI + 0x48],0x7
//         00535bb4     JNC        LAB_00535c2f
//         00535bb6     MOV        EAX,dword ptr [ESI + 0x8]
//         00535bb9     CMP        byte ptr [EAX + 0x8d],0x2
//         00535bc0     JC         LAB_00535c2f
//         00535bc2     MOV        this,dword ptr [EDI + 0x104]
//         00535bc8     MOV        AL,byte ptr [this->_padding_ + 0x8db8]
//         00535bce     TEST       AL,AL
//         00535bd0     JNZ        LAB_00535c05
//         00535bd2     MOV        EDX,dword ptr [EDI]
//         00535bd4     PUSH       ESI
//         00535bd5     MOV        this,EDI
//         00535bd7     CALL       dword ptr [EDX + 0xe0]
//         00535bdd     TEST       EAX,EAX
//         00535bdf     JNZ        LAB_00535c05
//         00535be1     FLD        float ptr [ESI + 0x3c]
//         00535be4     CALL       __ftol                                           undefined __ftol()
//         00535be9     FLD        float ptr [ESI + 0x38]
//         00535bec     PUSH       EAX
//         00535bed     CALL       __ftol                                           undefined __ftol()
//         00535bf2     PUSH       EAX=>DAT_fffffff8
//         00535bf3     MOV        EAX,dword ptr [EDI + 0x100]
//         00535bf9     MOV        this,dword ptr [EAX + 0x38]
//         00535bfc     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         00535c01     CMP        AL,0xf
//         00535c03     JNZ        LAB_00535c2f
//                               LAB_00535c05                                                 XREF[2]:     00535bd0(j), 00535bdf(j)
//                              view.cpp:2351 (16)
//         00535c05     MOVSX      EAX,word ptr [EBP + 0x4]=>DAT_0087d4a4
//         00535c09     MOV        EDX,dword ptr [EDI]
//         00535c0b     PUSH       EAX
//         00535c0c     PUSH       ESI=>DAT_fffffff8
//         00535c0d     MOV        this,EDI
//         00535c0f     CALL       dword ptr [EDX + 0xe4]
//                              view.cpp:2353 (13)
//         00535c15     MOV        this,dword ptr [ESI + 0xc]
//         00535c18     MOV        EDX,dword ptr [EDI + 0x100]
//         00535c1e     CMP        this,EDX
//         00535c20     JNZ        LAB_00535c25
//                              view.cpp:2354 (3)
//         00535c22     ADD        EAX,0x5
//                               LAB_00535c25                                                 XREF[1]:     00535c20(j)
//                              view.cpp:2355 (4)
//         00535c25     CMP        EAX,EBX
//         00535c27     JLE        LAB_00535c2f
//                              view.cpp:2357 (4)
//         00535c29     MOV        dword ptr [ESP + 0x24],ESI
//                              view.cpp:2358 (20)
//         00535c2d     MOV        EBX,EAX
//                               LAB_00535c2f                                                 XREF[6]:     00535b97(j), 00535bae(j),
//                                                                                                         00535bb4(j), 00535bc0(j),
//                                                                                                         00535c03(j), 00535c27(j)
//         00535c2f     MOV        EAX,dword ptr [ESP + 0x20]
//         00535c33     ADD        EBP,0xc
//         00535c36     DEC        EAX
//         00535c37     MOV        dword ptr [ESP + 0x20],EAX
//         00535c3b     JNZ        LAB_00535b92
//                              view.cpp:2344 (4)
//         00535c41     MOV        this,dword ptr [ESP + 0x24]
//                               LAB_00535c45                                                 XREF[1]:     00535b83(j)
//                              view.cpp:2363 (4)
//         00535c45     TEST       this,this
//         00535c47     JZ         LAB_00535c65
//                              view.cpp:2365 (18)
//         00535c49     PUSH       0x0
//         00535c4b     PUSH       this=>DAT_fffffff8
//         00535c4c     MOV        this,dword ptr [EDI + 0x100]
//         00535c52     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00535c57     TEST       EAX,EAX
//         00535c59     JZ         LAB_00535c65
//                              view.cpp:2366 (2)
//         00535c5b     MOV        AL,0x1
//                              view.cpp:2370 (18)
//         00535c5d     POP        EDI
//         00535c5e     POP        ESI
//         00535c5f     POP        EBP
//         00535c60     POP        EBX
//         00535c61     POP        this
//         00535c62     RET        0x14
//                               LAB_00535c65                                                 XREF[3]:     00535b73(j), 00535c47(j),
//                                                                                                         00535c59(j)
//         00535c65     POP        EDI
//         00535c66     POP        ESI
//         00535c67     POP        EBP
//         00535c68     XOR        AL,AL
//         00535c6a     POP        EBX
//         00535c6b     POP        this
//         00535c6c     RET        0x14
//         00535c6f     ??         90h
    return 0;
}

uchar RGE_View::pick(uchar param_1, uchar param_2, long param_3, long param_4, RGE_Pick_Info* param_5, RGE_Static_Object* param_6) {
    /* TODO: Stub */
//                              uchar __thiscall pick(RGE_View * this, uchar param_1, uchar param_2,
//              uchar             AL:1           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[5]:     005359e3(R), 005359fc(W), 00535a36(*), 00535a55(R),
//                                                                                     00535a68(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00535a46(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     00535a00(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     005359f8(R)
//              RGE_Pick_Info *   Stack[0x14]:4  param_5                   XREF[1]:     00535a0c(R)
//              RGE_Static_Obj    Stack[0x18]:4  param_6                   XREF[1]:     005359e8(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00535a04(W)
//              tagPOINT          Stack[-0xc]:8  mouse_pos                 XREF[1,2]:   00535a08(W), 00535a10(W), 00535a41(*)
//              tagPOINT          Stack[-0x14]:8 start_mouse_pos           XREF[0,2]:   00535a14(W), 00535a3c(*)
//                               ?pick@RGE_View@@QAEEEEJJPAURGE_Pick_Info@@PAVRGE_Static_Obj  XREF[12]:    draw_object_outline:005356a5(c),
//                               RGE_View::pick                                                            draw_paint_brush:0053591e(c),
//                                                                                                         start_scroll_view:0053a0f7(c),
//                                                                                                         start_scroll_view:0053a147(c),
//                                                                                                         start_scroll_view:0053a22f(c),
//                                                                                                         handle_scroll_view:0053a350(c),
//                                                                                                         handle_scroll_view:0053a844(c),
//                                                                                                         handle_scroll_view:0053a8b8(c),
//                                                                                                         do_paint:0053ab0d(c),
//                                                                                                         do_paint:0053ab4f(c),
//                                                                                                         pick1:0053ff97(c),
//                                                                                                         pick_objects1:0053ffdd(c)
//                              view.cpp:2272 (3)
//         005359e0     SUB        ESP,0x10
//                              view.cpp:2278 (21)
//         005359e3     MOV        EAX,dword ptr [ESP + param_1]
//         005359e7     PUSH       ESI
//         005359e8     MOV        ESI,dword ptr [ESP + param_6]
//         005359ec     MOV        DL,AL
//         005359ee     SUB        DL,0x28
//         005359f1     PUSH       EDI
//         005359f2     NEG        DL
//         005359f4     SBB        EDX,EDX
//         005359f6     AND        EDX,ESI
//                              view.cpp:2284 (16)
//         005359f8     MOV        ESI,dword ptr [ESP + param_4]
//         005359fc     MOV        dword ptr [ESP + param_1],EDX
//         00535a00     MOV        EDX,dword ptr [ESP + param_3]
//         00535a04     MOV        dword ptr [ESP + local_4],ESI
//                              view.cpp:2287 (4)
//         00535a08     MOV        dword ptr [ESP + mouse_pos.x],ESI
//                              view.cpp:2289 (30)
//         00535a0c     MOV        ESI,dword ptr [ESP + param_5]
//         00535a10     MOV        dword ptr [ESP + mouse_pos.y],EDX
//         00535a14     MOV        dword ptr [ESP + start_mouse_pos.y],EDX
//         00535a18     MOV        EDI,ESI
//         00535a1a     XOR        EDX,EDX
//         00535a1c     MOV        dword ptr [EDI],EDX
//         00535a1e     MOV        dword ptr [EDI + 0x4],EDX
//         00535a21     MOV        dword ptr [EDI + 0x8],EDX
//         00535a24     MOV        dword ptr [EDI + 0xc],EDX
//         00535a27     MOV        dword ptr [EDI + 0x10],EDX
//                              view.cpp:2292 (39)
//         00535a2a     LEA        EDX,[ESI + 0xa]
//         00535a2d     PUSH       EDX
//         00535a2e     LEA        EDX,[ESI + 0x8]
//         00535a31     PUSH       EDX
//         00535a32     LEA        EDX,[ESI + 0x4]
//         00535a35     PUSH       EDX
//         00535a36     LEA        EDX=>param_1,[ESP + 0x28]
//         00535a3a     PUSH       ESI
//         00535a3b     PUSH       EDX
//         00535a3c     LEA        EDX=>start_mouse_pos.y,[ESP + 0x1c]
//         00535a40     PUSH       EDX
//         00535a41     LEA        EDX=>mouse_pos.y,[ESP + 0x28]
//         00535a45     PUSH       EDX
//         00535a46     MOV        EDX,dword ptr [ESP + param_2]
//         00535a4a     PUSH       EDX
//         00535a4b     PUSH       EAX
//         00535a4c     CALL       RGE_View::view_function                          long view_function(RGE_View * this, uchar par
//                              view.cpp:2294 (4)
//         00535a51     CMP        AL,0x34
//         00535a53     JNZ        LAB_00535a64
//                              view.cpp:2295 (7)
//         00535a55     MOV        this,dword ptr [ESP + param_1]
//         00535a59     MOV        dword ptr [ESI + 0xc],this
//                              view.cpp:2300 (8)
//         00535a5c     POP        EDI
//         00535a5d     POP        ESI
//         00535a5e     ADD        ESP,0x10
//         00535a61     RET        0x18
//                               LAB_00535a64                                                 XREF[1]:     00535a53(j)
//                              view.cpp:2296 (4)
//         00535a64     CMP        AL,0x33
//         00535a66     JNZ        LAB_00535a6f
//                              view.cpp:2297 (7)
//         00535a68     MOV        EDX,dword ptr [ESP + param_1]
//         00535a6c     MOV        dword ptr [ESI + 0x10],EDX
//                               LAB_00535a6f                                                 XREF[1]:     00535a66(j)
//                              view.cpp:2300 (8)
//         00535a6f     POP        EDI
//         00535a70     POP        ESI
//         00535a71     ADD        ESP,0x10
//         00535a74     RET        0x18
//         00535a77     ??         90h
//         00535a78     NOP
//         00535a79     NOP
//         00535a7a     NOP
//         00535a7b     NOP
//         00535a7c     NOP
//         00535a7d     NOP
//         00535a7e     NOP
//         00535a7f     NOP
    return 0;
}

uchar RGE_View::pick_multi(uchar param_1, long param_2, long param_3, long param_4, long param_5) {
    /* TODO: Stub */
//                              uchar __thiscall pick_multi(RGE_View * this, uchar param_1, long par
//              uchar             AL:1           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00535a85(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00535aa7(R), 00535b25(R)
//              long              Stack[0xc]:4   param_3                   XREF[3]:     00535a8b(R), 00535b0b(R), 00535b8e(W)
//              long              Stack[0x10]:4  param_4                   XREF[3]:     00535aa2(R), 00535b21(R), 00535b7f(W)
//              long              Stack[0x14]:4  param_5                   XREF[2]:     00535a98(R), 00535b29(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00535ab5(W), 00535afb(W), 00535b0f(R)
//              int               Stack[-0x8]:4  picked_any
//                               ?pick_multi@RGE_View@@QAEEEJJJJ@Z                            XREF[1]:     end_scroll_view:0053aa1b(c)
//                               RGE_View::pick_multi
//                              view.cpp:2306 (5)
//         00535a80     PUSH       this
//         00535a81     PUSH       EBX
//         00535a82     PUSH       EBP
//         00535a83     PUSH       ESI
//         00535a84     PUSH       EDI
//                              view.cpp:2317 (59)
//         00535a85     MOV        EAX,dword ptr [ESP + param_1]
//         00535a89     MOV        EDI,this
//         00535a8b     MOV        EBX,dword ptr [ESP + param_3]
//         00535a8f     PUSH       0x1
//         00535a91     MOV        this,dword ptr [EDI + 0x100]
//         00535a97     PUSH       EAX
//         00535a98     MOV        EAX,dword ptr [ESP + param_5]
//         00535a9c     XOR        ESI,ESI
//         00535a9e     MOVSX      EDX,word ptr [ECX + this+0x4a]
//         00535aa2     MOV        this,dword ptr [ESP + param_4]
//         00535aa6     PUSH       EDX
//         00535aa7     MOV        EDX,dword ptr [ESP + param_2]
//         00535aab     PUSH       0x14
//         00535aad     PUSH       0xa
//         00535aaf     PUSH       EAX
//         00535ab0     PUSH       this
//         00535ab1     PUSH       EBX
//         00535ab2     PUSH       EDX
//         00535ab3     MOV        this,EDI
//         00535ab5     MOV        dword ptr [ESP + local_4],ESI
//         00535ab9     CALL       RGE_View::pick_multi_objects                     int pick_multi_objects(RGE_View * this, int p
//         00535abe     MOV        EBP,EAX
//                              view.cpp:2319 (4)
//         00535ac0     TEST       EBP,EBP
//         00535ac2     JLE        LAB_00535b0f
//                              view.cpp:2315 (5)
//         00535ac4     MOV        EBX,Picked_Objects                               = 00000000
//                               LAB_00535ac9                                                 XREF[1]:     00535b09(j)
//                              view.cpp:2321 (7)
//         00535ac9     MOV        EAX,dword ptr [EBX]=>Picked_Objects              = 00000000
//         00535acb     CMP        EAX,-0x1
//         00535ace     JZ         LAB_00535b03
//                              view.cpp:2323 (15)
//         00535ad0     MOV        this,dword ptr [EDI + 0xfc]
//         00535ad6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00535adc     MOV        EAX,dword ptr [EDX + EAX*0x4]
//                              view.cpp:2324 (10)
//         00535adf     TEST       EAX,EAX
//         00535ae1     JZ         LAB_00535b03
//         00535ae3     CMP        byte ptr [EAX + 0x48],0x7
//         00535ae7     JNC        LAB_00535b03
//                              view.cpp:2326 (18)
//         00535ae9     MOV        this,dword ptr [EDI + 0x100]
//         00535aef     PUSH       0x0
//         00535af1     PUSH       EAX
//         00535af2     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00535af7     TEST       EAX,EAX
//         00535af9     JZ         LAB_00535b0b
//                              view.cpp:2329 (8)
//         00535afb     MOV        dword ptr [ESP + local_4],0x1
//                               LAB_00535b03                                                 XREF[3]:     00535ace(j), 00535ae1(j),
//                                                                                                         00535ae7(j)
//                              view.cpp:2319 (12)
//         00535b03     INC        ESI
//         00535b04     ADD        EBX,0xc
//         00535b07     CMP        ESI,EBP
//         00535b09     JL         LAB_00535ac9
//                               LAB_00535b0b                                                 XREF[1]:     00535af9(j)
//         00535b0b     MOV        EBX,dword ptr [ESP + param_3]
//                               LAB_00535b0f                                                 XREF[1]:     00535ac2(j)
//                              view.cpp:2334 (8)
//         00535b0f     MOV        EAX,dword ptr [ESP + local_4]
//         00535b13     TEST       EAX,EAX
//         00535b15     JZ         LAB_00535b21
//                              view.cpp:2335 (2)
//         00535b17     MOV        AL,0x1
//                              view.cpp:2370 (8)
//         00535b19     POP        EDI
//         00535b1a     POP        ESI
//         00535b1b     POP        EBP
//         00535b1c     POP        EBX
//         00535b1d     POP        this
//         00535b1e     RET        0x14
//                               LAB_00535b21                                                 XREF[1]:     00535b15(j)
//                              view.cpp:2337 (80)
//         00535b21     MOV        this,dword ptr [ESP + param_4]
//         00535b25     MOV        ESI,dword ptr [ESP + param_2]
//         00535b29     MOV        EAX,dword ptr [ESP + param_5]
//         00535b2d     SUB        this,ESI
//         00535b2f     SUB        EAX,EBX
//         00535b31     MOV        EDX,this
//         00535b33     CMP        this,EAX
//         00535b35     JL         LAB_00535b39
//         00535b37     MOV        EDX,EAX
//                               LAB_00535b39                                                 XREF[1]:     00535b35(j)
//         00535b39     CMP        EDX,0x32
//         00535b3c     JGE        LAB_00535b4a
//         00535b3e     CMP        this,EAX
//         00535b40     JGE        LAB_00535b46
//         00535b42     MOV        EDX,this
//         00535b44     JMP        LAB_00535b4f
//                               LAB_00535b46                                                 XREF[1]:     00535b40(j)
//         00535b46     MOV        EDX,EAX
//         00535b48     JMP        LAB_00535b4f
//                               LAB_00535b4a                                                 XREF[1]:     00535b3c(j)
//         00535b4a     MOV        EDX,0x32
//                               LAB_00535b4f                                                 XREF[2]:     00535b44(j), 00535b48(j)
//         00535b4f     PUSH       0x1
//         00535b51     PUSH       0x4
//         00535b53     PUSH       EDX
//         00535b54     PUSH       0x14
//         00535b56     CDQ
//         00535b57     SUB        EAX,EDX
//         00535b59     PUSH       0xa
//         00535b5b     SAR        EAX,0x1
//         00535b5d     ADD        EAX,EBX
//         00535b5f     PUSH       EAX
//         00535b60     MOV        EAX,this
//         00535b62     CDQ
//         00535b63     SUB        EAX,EDX
//         00535b65     MOV        this,EDI
//         00535b67     SAR        EAX,0x1
//         00535b69     ADD        EAX,ESI
//         00535b6b     PUSH       EAX
//         00535b6c     CALL       RGE_View::pick_objects                           int pick_objects(RGE_View * this, int param_1
//                              view.cpp:2338 (2)
//         00535b71     TEST       EAX,EAX
//                              view.cpp:2339 (6)
//         00535b73     JZ         LAB_00535c65
//                              view.cpp:2342 (2)
//         00535b79     XOR        this,this
//                              view.cpp:2343 (2)
//         00535b7b     XOR        EBX,EBX
//                              view.cpp:2344 (12)
//         00535b7d     TEST       EAX,EAX
//         00535b7f     MOV        dword ptr [ESP + param_4],this
//         00535b83     JLE        LAB_00535c45
//                              view.cpp:2370 (124)
//         00535b89     MOV        EBP,Picked_Objects                               = 00000000
//         00535b8e     MOV        dword ptr [ESP + param_3],EAX
//                               LAB_00535b92                                                 XREF[1]:     00535c3b(j)
//         00535b92     MOV        EAX,dword ptr [EBP]=>Picked_Objects              = 00000000
//         00535b95     TEST       EAX,EAX
//         00535b97     JL         LAB_00535c2f
//         00535b9d     MOV        this,dword ptr [EDI + 0xfc]
//         00535ba3     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00535ba9     MOV        ESI,dword ptr [EDX + EAX*0x4]
//         00535bac     TEST       ESI,ESI
//         00535bae     JZ         LAB_00535c2f
//         00535bb0     CMP        byte ptr [ESI + 0x48],0x7
//         00535bb4     JNC        LAB_00535c2f
//         00535bb6     MOV        EAX,dword ptr [ESI + 0x8]
//         00535bb9     CMP        byte ptr [EAX + 0x8d],0x2
//         00535bc0     JC         LAB_00535c2f
//         00535bc2     MOV        this,dword ptr [EDI + 0x104]
//         00535bc8     MOV        AL,byte ptr [this->_padding_ + 0x8db8]
//         00535bce     TEST       AL,AL
//         00535bd0     JNZ        LAB_00535c05
//         00535bd2     MOV        EDX,dword ptr [EDI]
//         00535bd4     PUSH       ESI
//         00535bd5     MOV        this,EDI
//         00535bd7     CALL       dword ptr [EDX + 0xe0]
//         00535bdd     TEST       EAX,EAX
//         00535bdf     JNZ        LAB_00535c05
//         00535be1     FLD        float ptr [ESI + 0x3c]
//         00535be4     CALL       __ftol                                           undefined __ftol()
//         00535be9     FLD        float ptr [ESI + 0x38]
//         00535bec     PUSH       EAX
//         00535bed     CALL       __ftol                                           undefined __ftol()
//         00535bf2     PUSH       EAX=>DAT_fffffff8
//         00535bf3     MOV        EAX,dword ptr [EDI + 0x100]
//         00535bf9     MOV        this,dword ptr [EAX + 0x38]
//         00535bfc     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//         00535c01     CMP        AL,0xf
//         00535c03     JNZ        LAB_00535c2f
//                               LAB_00535c05                                                 XREF[2]:     00535bd0(j), 00535bdf(j)
//                              view.cpp:2351 (16)
//         00535c05     MOVSX      EAX,word ptr [EBP + 0x4]=>DAT_0087d4a4
//         00535c09     MOV        EDX,dword ptr [EDI]
//         00535c0b     PUSH       EAX
//         00535c0c     PUSH       ESI=>DAT_fffffff8
//         00535c0d     MOV        this,EDI
//         00535c0f     CALL       dword ptr [EDX + 0xe4]
//                              view.cpp:2353 (13)
//         00535c15     MOV        this,dword ptr [ESI + 0xc]
//         00535c18     MOV        EDX,dword ptr [EDI + 0x100]
//         00535c1e     CMP        this,EDX
//         00535c20     JNZ        LAB_00535c25
//                              view.cpp:2354 (3)
//         00535c22     ADD        EAX,0x5
//                               LAB_00535c25                                                 XREF[1]:     00535c20(j)
//                              view.cpp:2355 (4)
//         00535c25     CMP        EAX,EBX
//         00535c27     JLE        LAB_00535c2f
//                              view.cpp:2357 (4)
//         00535c29     MOV        dword ptr [ESP + 0x24],ESI
//                              view.cpp:2358 (20)
//         00535c2d     MOV        EBX,EAX
//                               LAB_00535c2f                                                 XREF[6]:     00535b97(j), 00535bae(j),
//                                                                                                         00535bb4(j), 00535bc0(j),
//                                                                                                         00535c03(j), 00535c27(j)
//         00535c2f     MOV        EAX,dword ptr [ESP + 0x20]
//         00535c33     ADD        EBP,0xc
//         00535c36     DEC        EAX
//         00535c37     MOV        dword ptr [ESP + 0x20],EAX
//         00535c3b     JNZ        LAB_00535b92
//                              view.cpp:2344 (4)
//         00535c41     MOV        this,dword ptr [ESP + 0x24]
//                               LAB_00535c45                                                 XREF[1]:     00535b83(j)
//                              view.cpp:2363 (4)
//         00535c45     TEST       this,this
//         00535c47     JZ         LAB_00535c65
//                              view.cpp:2365 (18)
//         00535c49     PUSH       0x0
//         00535c4b     PUSH       this=>DAT_fffffff8
//         00535c4c     MOV        this,dword ptr [EDI + 0x100]
//         00535c52     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00535c57     TEST       EAX,EAX
//         00535c59     JZ         LAB_00535c65
//                              view.cpp:2366 (2)
//         00535c5b     MOV        AL,0x1
//                              view.cpp:2370 (18)
//         00535c5d     POP        EDI
//         00535c5e     POP        ESI
//         00535c5f     POP        EBP
//         00535c60     POP        EBX
//         00535c61     POP        this
//         00535c62     RET        0x14
//                               LAB_00535c65                                                 XREF[3]:     00535b73(j), 00535c47(j),
//                                                                                                         00535c59(j)
//         00535c65     POP        EDI
//         00535c66     POP        ESI
//         00535c67     POP        EBP
//         00535c68     XOR        AL,AL
//         00535c6a     POP        EBX
//         00535c6b     POP        this
//         00535c6c     RET        0x14
//         00535c6f     ??         90h
    return 0;
}

uchar RGE_View::pick(uchar param_1, uchar param_2, tagPOINT* param_3, tagPOINT* param_4, void** param_5, float* param_6, float* param_7, short* param_8, short* param_9) {
    /* TODO: Stub */
//                              uchar __thiscall pick(RGE_View * this, uchar param_1, uchar param_2,
//              uchar             AL:1           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00535c97(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00535c92(R)
//              tagPOINT *        Stack[0xc]:4   param_3                   XREF[1]:     00535c8d(R)
//              tagPOINT *        Stack[0x10]:4  param_4                   XREF[1]:     00535c88(R)
//              void * *          Stack[0x14]:4  param_5                   XREF[1]:     00535c83(R)
//              float *           Stack[0x18]:4  param_6                   XREF[1]:     00535c7e(R)
//              float *           Stack[0x1c]:4  param_7                   XREF[1]:     00535c79(R)
//              short *           Stack[0x20]:4  param_8                   XREF[1]:     00535c74(R)
//              short *           Stack[0x24]:4  param_9                   XREF[1]:     00535c70(R)
//                               ?pick@RGE_View@@QAEEEEPAUtagPOINT@@0PAPAXPAM2PAF3@Z
//                               RGE_View::pick
//                              view.cpp:2377 (50)
//         00535c70     MOV        EAX,dword ptr [ESP + param_9]
//         00535c74     MOV        EDX,dword ptr [ESP + param_8]
//         00535c78     PUSH       EAX
//         00535c79     MOV        EAX,dword ptr [ESP + param_7]
//         00535c7d     PUSH       EDX
//         00535c7e     MOV        EDX,dword ptr [ESP + param_6]
//         00535c82     PUSH       EAX
//         00535c83     MOV        EAX,dword ptr [ESP + param_5]
//         00535c87     PUSH       EDX
//         00535c88     MOV        EDX,dword ptr [ESP + param_4]
//         00535c8c     PUSH       EAX
//         00535c8d     MOV        EAX,dword ptr [ESP + param_3]
//         00535c91     PUSH       EDX
//         00535c92     MOV        EDX,dword ptr [ESP + param_2]
//         00535c96     PUSH       EAX
//         00535c97     MOV        EAX,dword ptr [ESP + param_1]
//         00535c9b     PUSH       EDX
//         00535c9c     PUSH       EAX
//         00535c9d     CALL       RGE_View::view_function                          long view_function(RGE_View * this, uchar par
//                              view.cpp:2380 (3)
//         00535ca2     RET        0x24
//         00535ca5     ??         90h
//         00535ca6     NOP
//         00535ca7     NOP
//         00535ca8     NOP
//         00535ca9     NOP
//         00535caa     NOP
//         00535cab     NOP
//         00535cac     NOP
//         00535cad     NOP
//         00535cae     NOP
//         00535caf     NOP
    return 0;
}

int RGE_View::pick_through_fog(RGE_Static_Object* param_1) {
    /* TODO: Stub */
//                              int __thiscall pick_through_fog(RGE_View * this, RGE_Static_Object *
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1
//                               ?pick_through_fog@RGE_View@@UAEHPAVRGE_Static_Object@@@Z     XREF[3]:     pick_through_fog:0052dcfb(c),
//                               RGE_View::pick_through_fog                                                00577698(*), 005778d0(*)
//                              view.cpp:2386 (2)
//         00535cb0     XOR        EAX,EAX
//                              view.cpp:2388 (3)
//         00535cb2     RET        0x4
//         00535cb5     ??         90h
//         00535cb6     NOP
//         00535cb7     NOP
//         00535cb8     NOP
//         00535cb9     NOP
//         00535cba     NOP
//         00535cbb     NOP
//         00535cbc     NOP
//         00535cbd     NOP
//         00535cbe     NOP
//         00535cbf     NOP
    return 0;
}

int RGE_View::pick_weight(RGE_Static_Object* param_1, int param_2) {
    /* TODO: Stub */
//                              int __thiscall pick_weight(RGE_View * this, RGE_Static_Object * para
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[3]:     00535cc0(R), 00535ccd(W), 00535cf1(R)
//              int               Stack[0x8]:4   param_2                   XREF[3]:     00535d1c(R), 00535d4e(R), 00535d70(R)
//                               ?pick_weight@RGE_View@@UAEHPAVRGE_Static_Object@@H@Z         XREF[2]:     0057769c(*), 005778d4(*)
//                               RGE_View::pick_weight
//                              view.cpp:2396 (17)
//         00535cc0     MOV        EAX,dword ptr [ESP + param_1]
//         00535cc4     MOV        EDX,dword ptr [EAX + 0x8]
//         00535cc7     MOV        DL,byte ptr [EDX + 0x8d]
//         00535ccd     MOV        byte ptr [ESP + param_1],DL
//                              view.cpp:2402 (32)
//         00535cd1     MOV        EDX,dword ptr [ECX + this->UC_ObjectTouched]
//         00535cd7     TEST       EDX,EDX
//         00535cd9     JZ         LAB_00535cef
//         00535cdb     MOV        this,dword ptr [ECX + this->UC_TouchedObj]
//         00535ce1     MOV        EDX,dword ptr [EAX + 0x4]
//         00535ce4     CMP        this,EDX
//         00535ce6     JNZ        LAB_00535cef
//         00535ce8     MOV        EDX,0x1
//         00535ced     JMP        LAB_00535cf1
//                               LAB_00535cef                                                 XREF[2]:     00535cd9(j), 00535ce6(j)
//         00535cef     XOR        EDX,EDX
//                               LAB_00535cf1                                                 XREF[1]:     00535ced(j)
//                              view.cpp:2405 (23)
//         00535cf1     MOV        this,dword ptr [ESP + param_1]
//         00535cf5     XOR        EAX,EAX
//         00535cf7     AND        this,0xff
//         00535cfd     SUB        this,0x2
//         00535d00     JZ         LAB_00535d64
//         00535d02     DEC        this
//         00535d03     JZ         LAB_00535d42
//         00535d05     DEC        this
//         00535d06     JZ         LAB_00535d10
//                              view.cpp:2435 (5)
//         00535d08     MOV        EAX,0x1
//                              view.cpp:2440 (3)
//         00535d0d     RET        0x8
//                               LAB_00535d10                                                 XREF[1]:     00535d06(j)
//                              view.cpp:2408 (4)
//         00535d10     TEST       EDX,EDX
//         00535d12     JZ         LAB_00535d1c
//                              view.cpp:2409 (5)
//         00535d14     MOV        EAX,0x5
//                              view.cpp:2440 (3)
//         00535d19     RET        0x8
//                               LAB_00535d1c                                                 XREF[1]:     00535d12(j)
//                              view.cpp:2410 (14)
//         00535d1c     MOV        EAX,dword ptr [ESP + param_2]
//         00535d20     CMP        EAX,0x1
//         00535d23     JZ         LAB_00535d3a
//         00535d25     CMP        EAX,0x2
//         00535d28     JZ         LAB_00535d3a
//                              view.cpp:2412 (13)
//         00535d2a     XOR        EDX,EDX
//         00535d2c     CMP        EAX,0x3
//         00535d2f     SETZ       DL
//         00535d32     ADD        EDX,0x2
//         00535d35     MOV        EAX,EDX
//                              view.cpp:2440 (3)
//         00535d37     RET        0x8
//                               LAB_00535d3a                                                 XREF[2]:     00535d23(j), 00535d28(j)
//                              view.cpp:2411 (5)
//         00535d3a     MOV        EAX,0x4
//                              view.cpp:2440 (3)
//         00535d3f     RET        0x8
//                               LAB_00535d42                                                 XREF[1]:     00535d03(j)
//                              view.cpp:2419 (4)
//         00535d42     TEST       EDX,EDX
//         00535d44     JZ         LAB_00535d4e
//                              view.cpp:2420 (5)
//         00535d46     MOV        EAX,0x5
//                              view.cpp:2440 (3)
//         00535d4b     RET        0x8
//                               LAB_00535d4e                                                 XREF[1]:     00535d44(j)
//                              view.cpp:2421 (14)
//         00535d4e     MOV        this,dword ptr [ESP + param_2]
//         00535d52     CMP        this,0x1
//         00535d55     JZ         LAB_00535d8b
//         00535d57     CMP        this,0x2
//         00535d5a     JNZ        LAB_00535d90
//                              view.cpp:2429 (5)
//         00535d5c     MOV        EAX,0x3
//                              view.cpp:2440 (3)
//         00535d61     RET        0x8
//                               LAB_00535d64                                                 XREF[1]:     00535d00(j)
//                              view.cpp:2426 (4)
//         00535d64     TEST       EDX,EDX
//         00535d66     JZ         LAB_00535d70
//                              view.cpp:2427 (5)
//         00535d68     MOV        EAX,0x5
//                              view.cpp:2440 (3)
//         00535d6d     RET        0x8
//                               LAB_00535d70                                                 XREF[1]:     00535d66(j)
//                              view.cpp:2428 (14)
//         00535d70     MOV        this,dword ptr [ESP + param_2]
//         00535d74     CMP        this,0x1
//         00535d77     JZ         LAB_00535d8b
//         00535d79     CMP        this,0x2
//         00535d7c     JZ         LAB_00535d8b
//                              view.cpp:2430 (5)
//         00535d7e     CMP        this,0x3
//         00535d81     JNZ        LAB_00535d90
//                              view.cpp:2431 (5)
//         00535d83     MOV        EAX,0x2
//                              view.cpp:2440 (3)
//         00535d88     RET        0x8
//                               LAB_00535d8b                                                 XREF[3]:     00535d55(j), 00535d77(j),
//                                                                                                         00535d7c(j)
//                              view.cpp:2429 (5)
//         00535d8b     MOV        EAX,0x3
//                               LAB_00535d90                                                 XREF[2]:     00535d5a(j), 00535d81(j)
//                              view.cpp:2440 (3)
//         00535d90     RET        0x8
//         00535d93     ??         90h
//         00535d94     NOP
//         00535d95     NOP
//         00535d96     NOP
//         00535d97     NOP
//         00535d98     NOP
//         00535d99     NOP
//         00535d9a     NOP
//         00535d9b     NOP
//         00535d9c     NOP
//         00535d9d     NOP
//         00535d9e     NOP
//         00535d9f     NOP
    return 0;
}

int RGE_View::get_tile_screen_coords(short param_1, short param_2, short* param_3, short* param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall get_tile_screen_coords(RGE_View * this, short param_1
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              short             Stack[0x4]:2   param_1                   XREF[1]:     00535dbf(R)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00535ddf(R)
//              short *           Stack[0xc]:4   param_3                   XREF[2]:     00535da0(R), 00535e8d(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     00535db1(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     00535e33(R)
//                               ?get_tile_screen_coords@RGE_View@@QAEHFFPAF0H@Z              XREF[2]:     draw_wall_outline:0052d081(c),
//                               RGE_View::get_tile_screen_coords                                          draw_object_outline:005356f4(c)
//                              view.cpp:2447 (17)
//         00535da0     MOV        EAX,dword ptr [ESP + param_3]
//         00535da4     PUSH       EBX
//         00535da5     PUSH       EBP
//         00535da6     PUSH       ESI
//         00535da7     TEST       EAX,EAX
//         00535da9     PUSH       EDI
//         00535daa     JZ         LAB_00535db1
//         00535dac     MOV        word ptr [EAX],0x0
//                               LAB_00535db1                                                 XREF[1]:     00535daa(j)
//                              view.cpp:2452 (14)
//         00535db1     MOV        EBP,dword ptr [ESP + param_4]
//         00535db5     TEST       EBP,EBP
//         00535db7     JZ         LAB_00535dbf
//         00535db9     MOV        word ptr [EBP],0x0
//                               LAB_00535dbf                                                 XREF[1]:     00535db7(j)
//                              view.cpp:2454 (60)
//         00535dbf     MOV        AX,word ptr [ESP + param_1]
//         00535dc4     TEST       AX,AX
//         00535dc7     JL         LAB_00535ea4
//         00535dcd     MOV        ESI,dword ptr [ECX + this->map]
//         00535dd3     MOVSX      EAX,AX
//         00535dd6     CMP        EAX,dword ptr [ESI + 0x8]
//         00535dd9     JGE        LAB_00535ea4
//         00535ddf     MOV        DX,word ptr [ESP + param_2]
//         00535de4     TEST       DX,DX
//         00535de7     JL         LAB_00535ea4
//         00535ded     MOV        EDI,dword ptr [ESI + 0xc]
//         00535df0     MOVSX      EDX,DX
//         00535df3     CMP        EDX,EDI
//         00535df5     JGE        LAB_00535ea4
//                              view.cpp:2456 (15)
//         00535dfb     MOV        EDI,dword ptr [ESI + 0x8d8c]
//         00535e01     LEA        EAX,[EAX + EAX*0x2]
//         00535e04     MOV        EDX,dword ptr [EDI + EDX*0x4]
//         00535e07     LEA        EDX,[EDX + EAX*0x8]
//                              view.cpp:2458 (8)
//         00535e0a     TEST       EDX,EDX
//         00535e0c     JZ         LAB_00535ea4
//                              view.cpp:2460 (11)
//         00535e12     MOVSX      EDI,word ptr [EDX]
//         00535e15     MOV        EBX,dword ptr [ECX + this->map_scr_x_offset]
//         00535e1b     SUB        EDI,EBX
//                              view.cpp:2462 (22)
//         00535e1d     MOV        BL,byte ptr [EDX + 0x4]
//         00535e20     MOV        EAX,EBX
//         00535e22     MOVSX      EDX,word ptr [EDX + 0x2]
//         00535e26     AND        EAX,0xff
//         00535e2b     LEA        EAX,[EAX + EAX*0x2]
//         00535e2e     MOVSX      ESI,word ptr [ESI + EAX*0x2 + 0x1c]
//                              view.cpp:2464 (16)
//         00535e33     MOV        EAX,dword ptr [ESP + param_5]
//         00535e37     ADD        ESI,EDX
//         00535e39     SUB        ESI,dword ptr [ECX + this->map_scr_y_offset]
//         00535e3f     TEST       EAX,EAX
//         00535e41     JZ         LAB_00535e8d
//                              view.cpp:2466 (18)
//         00535e43     TEST       BL,BL
//         00535e45     JZ         LAB_00535e55
//         00535e47     MOVSX      EAX,word ptr [ECX + this->elev_hgt]
//         00535e4e     CDQ
//         00535e4f     SUB        EAX,EDX
//         00535e51     SAR        EAX,0x1
//         00535e53     ADD        ESI,EAX
//                               LAB_00535e55                                                 XREF[1]:     00535e45(j)
//                              view.cpp:2468 (14)
//         00535e55     CMP        BL,0x6
//         00535e58     JNZ        LAB_00535e63
//         00535e5a     MOVSX      EAX,word ptr [ECX + this->elev_hgt]
//         00535e61     SUB        ESI,EAX
//                               LAB_00535e63                                                 XREF[1]:     00535e58(j)
//                              view.cpp:2469 (14)
//         00535e63     CMP        BL,0x5
//         00535e66     JNZ        LAB_00535e71
//         00535e68     MOVSX      EDX,word ptr [ECX + this->elev_hgt]
//         00535e6f     SUB        ESI,EDX
//                               LAB_00535e71                                                 XREF[1]:     00535e66(j)
//                              view.cpp:2470 (14)
//         00535e71     CMP        BL,0x3
//         00535e74     JNZ        LAB_00535e7f
//         00535e76     MOVSX      EAX,word ptr [ECX + this->elev_hgt]
//         00535e7d     SUB        ESI,EAX
//                               LAB_00535e7f                                                 XREF[1]:     00535e74(j)
//                              view.cpp:2471 (14)
//         00535e7f     CMP        BL,0xb
//         00535e82     JNZ        LAB_00535e8d
//         00535e84     MOVSX      this,word ptr [ECX + this->elev_hgt]
//         00535e8b     SUB        ESI,this
//                               LAB_00535e8d                                                 XREF[2]:     00535e41(j), 00535e82(j)
//                              view.cpp:2476 (4)
//         00535e8d     MOV        EDX,dword ptr [ESP + param_3]
//                              view.cpp:2479 (12)
//         00535e91     MOV        EAX,0x1
//         00535e96     MOV        word ptr [EDX],DI
//         00535e99     MOV        word ptr [EBP],SI
//                              view.cpp:2480 (16)
//         00535e9d     POP        EDI
//         00535e9e     POP        ESI
//         00535e9f     POP        EBP
//         00535ea0     POP        EBX
//         00535ea1     RET        0x14
//                               LAB_00535ea4                                                 XREF[5]:     00535dc7(j), 00535dd9(j),
//                                                                                                         00535de7(j), 00535df5(j),
//                                                                                                         00535e0c(j)
//         00535ea4     POP        EDI
//         00535ea5     POP        ESI
//         00535ea6     POP        EBP
//         00535ea7     XOR        EAX,EAX
//         00535ea9     POP        EBX
//         00535eaa     RET        0x14
//         00535ead     ??         90h
//         00535eae     NOP
//         00535eaf     NOP
    return 0;
}

void RGE_View::get_center_screen_pos(short* param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_center_screen_pos(RGE_View * this, short * param
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00535eb0(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00535ec5(R)
//                               ?get_center_screen_pos@RGE_View@@QAEXPAF0@Z
//                               RGE_View::get_center_screen_pos
//                              view.cpp:2486 (14)
//         00535eb0     MOV        EDX,dword ptr [ESP + param_1]
//         00535eb4     MOV        AX,word ptr [ECX + this->center_scr_row]
//         00535ebb     MOV        word ptr [EDX],AX
//                              view.cpp:2488 (14)
//         00535ebe     MOV        AX,word ptr [ECX + this->center_scr_col]
//         00535ec5     MOV        this,dword ptr [ESP + param_2]
//         00535ec9     MOV        word ptr [this->_padding_],AX
//                              view.cpp:2489 (3)
//         00535ecc     RET        0x8
//         00535ecf     ??         90h
    return;
}

void RGE_View::get_start_coords(short* param_1, short* param_2, short* param_3, short* param_4) {
    /* TODO: Stub */
//                              void __thiscall get_start_coords(RGE_View * this, short * param_1, s
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00535ed0(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00535ee2(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     00535ef4(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     00535f06(R)
//                               ?get_start_coords@RGE_View@@QAEXPAF000@Z
//                               RGE_View::get_start_coords
//                              view.cpp:2496 (8)
//         00535ed0     MOV        EAX,dword ptr [ESP + param_1]
//         00535ed4     TEST       EAX,EAX
//         00535ed6     JZ         LAB_00535ee2
//                              view.cpp:2498 (10)
//         00535ed8     MOV        DX,word ptr [ECX + this->start_map_col]
//         00535edf     MOV        word ptr [EAX],DX
//                               LAB_00535ee2                                                 XREF[1]:     00535ed6(j)
//                              view.cpp:2499 (8)
//         00535ee2     MOV        EAX,dword ptr [ESP + param_2]
//         00535ee6     TEST       EAX,EAX
//         00535ee8     JZ         LAB_00535ef4
//                              view.cpp:2500 (10)
//         00535eea     MOV        DX,word ptr [ECX + this->start_map_row]
//         00535ef1     MOV        word ptr [EAX],DX
//                               LAB_00535ef4                                                 XREF[1]:     00535ee8(j)
//                              view.cpp:2501 (8)
//         00535ef4     MOV        EAX,dword ptr [ESP + param_3]
//         00535ef8     TEST       EAX,EAX
//         00535efa     JZ         LAB_00535f06
//                              view.cpp:2502 (10)
//         00535efc     MOV        DX,word ptr [ECX + this->start_scr_col]
//         00535f03     MOV        word ptr [EAX],DX
//                               LAB_00535f06                                                 XREF[1]:     00535efa(j)
//                              view.cpp:2503 (8)
//         00535f06     MOV        EAX,dword ptr [ESP + param_4]
//         00535f0a     TEST       EAX,EAX
//         00535f0c     JZ         LAB_00535f18
//                              view.cpp:2504 (10)
//         00535f0e     MOV        this,word ptr [ECX + this->start_scr_row]
//         00535f15     MOV        word ptr [EAX],this
//                               LAB_00535f18                                                 XREF[1]:     00535f0c(j)
//                              view.cpp:2505 (3)
//         00535f18     RET        0x10
//         00535f1b     ??         90h
//         00535f1c     NOP
//         00535f1d     NOP
//         00535f1e     NOP
//         00535f1f     NOP
    return;
}

void RGE_View::get_center_coords(short* param_1, short* param_2, short* param_3, short* param_4) {
    /* TODO: Stub */
//                              void __thiscall get_center_coords(RGE_View * this, short * param_1,
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00535f20(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00535f32(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     00535f44(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     00535f56(R)
//                               ?get_center_coords@RGE_View@@QAEXPAF000@Z
//                               RGE_View::get_center_coords
//                              view.cpp:2512 (8)
//         00535f20     MOV        EAX,dword ptr [ESP + param_1]
//         00535f24     TEST       EAX,EAX
//         00535f26     JZ         LAB_00535f32
//                              view.cpp:2514 (10)
//         00535f28     MOV        DX,word ptr [ECX + this->center_map_col]
//         00535f2f     MOV        word ptr [EAX],DX
//                               LAB_00535f32                                                 XREF[1]:     00535f26(j)
//                              view.cpp:2515 (8)
//         00535f32     MOV        EAX,dword ptr [ESP + param_2]
//         00535f36     TEST       EAX,EAX
//         00535f38     JZ         LAB_00535f44
//                              view.cpp:2516 (10)
//         00535f3a     MOV        DX,word ptr [ECX + this->center_map_row]
//         00535f41     MOV        word ptr [EAX],DX
//                               LAB_00535f44                                                 XREF[1]:     00535f38(j)
//                              view.cpp:2517 (8)
//         00535f44     MOV        EAX,dword ptr [ESP + param_3]
//         00535f48     TEST       EAX,EAX
//         00535f4a     JZ         LAB_00535f56
//                              view.cpp:2518 (10)
//         00535f4c     MOV        DX,word ptr [ECX + this->center_scr_col]
//         00535f53     MOV        word ptr [EAX],DX
//                               LAB_00535f56                                                 XREF[1]:     00535f4a(j)
//                              view.cpp:2519 (8)
//         00535f56     MOV        EAX,dword ptr [ESP + param_4]
//         00535f5a     TEST       EAX,EAX
//         00535f5c     JZ         LAB_00535f68
//                              view.cpp:2520 (10)
//         00535f5e     MOV        this,word ptr [ECX + this->center_scr_row]
//         00535f65     MOV        word ptr [EAX],this
//                               LAB_00535f68                                                 XREF[1]:     00535f5c(j)
//                              view.cpp:2521 (3)
//         00535f68     RET        0x10
//         00535f6b     ??         90h
//         00535f6c     NOP
//         00535f6d     NOP
//         00535f6e     NOP
//         00535f6f     NOP
    return;
}

void RGE_View::get_tile_sizes(short* param_1, short* param_2, short* param_3, short* param_4) {
    /* TODO: Stub */
//                              void __thiscall get_tile_sizes(RGE_View * this, short * param_1, sho
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00535f70(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00535f82(R)
//              short *           Stack[0xc]:4   param_3                   XREF[1]:     00535f94(R)
//              short *           Stack[0x10]:4  param_4                   XREF[1]:     00535fa6(R)
//                               ?get_tile_sizes@RGE_View@@QAEXPAF000@Z
//                               RGE_View::get_tile_sizes
//                              view.cpp:2527 (8)
//         00535f70     MOV        EAX,dword ptr [ESP + param_1]
//         00535f74     TEST       EAX,EAX
//         00535f76     JZ         LAB_00535f82
//                              view.cpp:2529 (10)
//         00535f78     MOV        DX,word ptr [ECX + this->tile_wid]
//         00535f7f     MOV        word ptr [EAX],DX
//                               LAB_00535f82                                                 XREF[1]:     00535f76(j)
//                              view.cpp:2530 (8)
//         00535f82     MOV        EAX,dword ptr [ESP + param_2]
//         00535f86     TEST       EAX,EAX
//         00535f88     JZ         LAB_00535f94
//                              view.cpp:2531 (10)
//         00535f8a     MOV        DX,word ptr [ECX + this->tile_hgt]
//         00535f91     MOV        word ptr [EAX],DX
//                               LAB_00535f94                                                 XREF[1]:     00535f88(j)
//                              view.cpp:2532 (8)
//         00535f94     MOV        EAX,dword ptr [ESP + param_3]
//         00535f98     TEST       EAX,EAX
//         00535f9a     JZ         LAB_00535fa6
//                              view.cpp:2533 (10)
//         00535f9c     MOV        DX,word ptr [ECX + this->tile_half_wid]
//         00535fa3     MOV        word ptr [EAX],DX
//                               LAB_00535fa6                                                 XREF[1]:     00535f9a(j)
//                              view.cpp:2534 (8)
//         00535fa6     MOV        EAX,dword ptr [ESP + param_4]
//         00535faa     TEST       EAX,EAX
//         00535fac     JZ         LAB_00535fb8
//                              view.cpp:2535 (10)
//         00535fae     MOV        this,word ptr [ECX + this->tile_half_hgt]
//         00535fb5     MOV        word ptr [EAX],this
//                               LAB_00535fb8                                                 XREF[1]:     00535fac(j)
//                              view.cpp:2536 (3)
//         00535fb8     RET        0x10
//         00535fbb     ??         90h
//         00535fbc     NOP
//         00535fbd     NOP
//         00535fbe     NOP
//         00535fbf     NOP
    return;
}

void RGE_View::get_max_size(short* param_1, short* param_2) {
    /* TODO: Stub */
//                              void __thiscall get_max_size(RGE_View * this, short * param_1, short
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              short *           Stack[0x4]:4   param_1                   XREF[1]:     00535fc0(R)
//              short *           Stack[0x8]:4   param_2                   XREF[1]:     00535fd5(R)
//                               ?get_max_size@RGE_View@@QAEXPAF0@Z                           XREF[1]:     draw_view_rect:0043836d(c)
//                               RGE_View::get_max_size
//                              view.cpp:2542 (14)
//         00535fc0     MOV        EDX,dword ptr [ESP + param_1]
//         00535fc4     MOV        AX,word ptr [ECX + this->max_col_num]
//         00535fcb     MOV        word ptr [EDX],AX
//                              view.cpp:2544 (14)
//         00535fce     MOV        AX,word ptr [ECX + this->max_row_num]
//         00535fd5     MOV        this,dword ptr [ESP + param_2]
//         00535fd9     MOV        word ptr [this->_padding_],AX
//                              view.cpp:2545 (3)
//         00535fdc     RET        0x8
//         00535fdf     ??         90h
    return;
}

long RGE_View::view_function(uchar param_1, uchar param_2, tagPOINT* param_3, tagPOINT* param_4, void** param_5, float* param_6, float* param_7, short* param_8, short* param_9) {
    /* TODO: Stub */
//                              long __thiscall view_function(RGE_View * this, uchar param_1, uchar
//              long              EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00535fe0(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00535fee(R)
//              tagPOINT *        Stack[0xc]:4   param_3                   XREF[3]:     0053649b(R), 00536525(R), 00536555(R)
//              tagPOINT *        Stack[0x10]:4  param_4                   XREF[1]:     00536492(R)
//              void * *          Stack[0x14]:4  param_5                   XREF[2]:     00536076(R), 005365d8(R)
//              float *           Stack[0x18]:4  param_6                   XREF[2]:     0053606f(R), 005364de(R)
//              float *           Stack[0x1c]:4  param_7                   XREF[2]:     00536068(R), 005364d7(R)
//              short *           Stack[0x20]:4  param_8                   XREF[3]:     005360b4(R), 0053648a(R), 005365bb(R)
//              short *           Stack[0x24]:4  param_9                   XREF[3]:     005360bb(R), 00536483(R), 005365d1(R)
//              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053604b(*)
//              RGE_Tile_List_    Stack[-0x8]:4  list                      XREF[1]:     00536044(*)
//              int               Stack[-0xc]:4  list_size                 XREF[1]:     00536187(W)
//              short             Stack[-0x10]:2 max_row_num2              XREF[2]:     00536183(W), 005368ec(R)
//              short             Stack[-0x14]:2 max_col_num2              XREF[2]:     005360b0(W), 00536515(R)
//              short             Stack[-0x18]:2 find_row                  XREF[2]:     005360a7(W), 00536506(R)
//              short             Stack[-0x1c]:2 find_col                  XREF[2]:     005360f1(W), 0053647f(R)
//              RGE_Static_Obj    Stack[-0x20]:4 orig_picked_obj           XREF[2]:     0053610d(*), 005363db(R)
//              long              Stack[-0x24]:4 calc_sel_row2             XREF[2]:     00536118(*), 005363d5(R)
//              long              Stack[-0x28]:4 calc_sel_row1             XREF[2]:     00536113(*), 005363ca(R)
//              long              Stack[-0x2c]:4 calc_sel_col2             XREF[2]:     0053611d(*), 005363c4(R)
//              long              Stack[-0x30]:4 calc_sel_col1             XREF[1]:     00536194(W)
//              short             Stack[-0x34]:2 row_num                   XREF[3]:     005361c0(W), 005368bc(R), 005368d6(W)
//              short             Stack[-0x38]:2 col_num                   XREF[3]:     005362f3(W), 0053631f(W), 00536341(R)
//              uchar             Stack[-0x3c]:1 tile_type                 XREF[4]:     00536618(W), 0053661c(R), 00536642(W), 00536646(R)
//              uchar             Stack[-0x40]:1 terrain_type              XREF[1]:     005360fc(W)
//              RGE_Static_Obj    Stack[-0x44]:4 last_picked_obj           XREF[5]:     0053634b(W), 00536368(W), 00536535(R), 0053656b(R),
//                                                                                     005365c9(R)
//              short             Stack[-0x48]:2 tile_screen_row           XREF[4]:     0053618f(W), 005368e0(R), 005368f3(W), 005368f8(R)
//              uchar             Stack[-0x4c]:1 direction                 XREF[2]:     00536165(W), 005361aa(R)
//              short             Stack[-0x50]:2 start_map_row2            XREF[2]:     00536159(W), 005361a6(R)
//              short             Stack[-0x54]:2 start_map_col2            XREF[14]:    005362ef(W), 00536323(W), 00536587(W), 0053658b(R),
//                                                                                     0053658f(W), 00536597(R), 005365a9(W), 005365ad(R),
//                                                                                     005365b1(W), 005365b7(R), 00536708(R), 00536773(R),
//                                                                                     0053679c(R), 00536807(R)
//              RGE_Tile *        Stack[-0x58]:4 tile                      XREF[6]:     0053646f(W), 00536476(W), 0053647b(R), 005366e4(W),
//                                                                                     005366eb(W), 005366f0(R)
//              uchar             Stack[-0x5c]:1 fog_flag                  XREF[4]:     0053607f(W), 005364d2(W), 005364f3(R), 005365df(W)
//              uchar             Stack[-0x60]:1 picked_type               XREF[4]:     0053618b(W), 005361ae(R), 005368c9(R), 005368e7(R)
//              short             Stack[-0x64]:2 cur_col_num               XREF[7]:     0053617b(W), 00536334(R), 005364ad(R), 0053670c(R),
//                                                                                     005367a0(R), 00536842(R), 00536885(R)
//              short             Stack[-0x68]:2 start_scr_row2            XREF[2]:     0053614d(W), 005361a2(R)
//              short             Stack[-0x6c]:2 start_scr_col2            XREF[12]:    005361b8(W), 005361ce(R), 00536219(R), 00536307(R),
//                                                                                     005363bf(R), 005364a8(R), 00536502(R), 00536530(R),
//                                                                                     0053657d(R), 0053659f(R), 005368b4(R), 005368ce(W)
//              short             Stack[-0x70]:2 map_col                   XREF[13]:    005361bc(W), 005361e5(R), 005361ff(R), 0053621d(R),
//                                                                                     00536302(R), 005363d0(R), 005364a3(R), 00536511(R),
//                                                                                     0053652c(R), 00536582(R), 005365a4(R), 005368b8(R),
//                                                                                     005368d2(W)
//              short             Stack[-0x74]:2 map_row                   XREF[14]:    005361b4(W), 0053636c(R), 005364b2(R), 0053653a(R),
//                                                                                     00536570(R), 005365c2(R), 00536716(R), 00536746(R),
//                                                                                     005367aa(R), 005367da(R), 00536846(R), 00536889(R),
//                                                                                     005368b0(R), 005368c5(W)
//              undefined1        Stack[-0x75]:1 local_75                  XREF[13]:    00536259(W), 00536267(W), 0053627d(W), 00536283(W),
//                                                                                     005362af(W), 005362b4(R), 005362c0(W), 005362c5(R),
//                                                                                     0053642f(R), 0053669c(R), 005366c6(R), 00536831(R),
//                                                                                     00536874(R)
//              short             Stack[-0x78]:2 screen_col
//              uchar             Stack[-0x79]:1 visible
//                               ?view_function@RGE_View@@IAEJEEPAUtagPOINT@@0PAPAXPAM2PAF3@Z XREF[3]:     draw_view:00535568(c),
//                               RGE_View::view_function                                                   pick:00535a4c(c),
//                                                                                                         pick:00535c9d(c)
//                              view.cpp:2562 (7)
//         00535fe0     MOV        AL,byte ptr [ESP + param_1]
//         00535fe4     SUB        ESP,0x78
//                              view.cpp:2592 (39)
//         00535fe7     CMP        AL,0xa
//         00535fe9     PUSH       EBX
//         00535fea     PUSH       EBP
//         00535feb     PUSH       ESI
//         00535fec     MOV        ESI,this
//         00535fee     MOV        this,byte ptr [ESP + param_2]
//         00535ff5     PUSH       EDI
//         00535ff6     MOV        byte ptr [ESI + 0x140],AL
//         00535ffc     MOV        byte ptr [ESI + 0x141],this
//         00536002     JNZ        LAB_00536044
//         00536004     MOV        EAX,dword ptr [ESI + 0xf8]
//         0053600a     TEST       EAX,EAX
//         0053600c     JZ         LAB_00536044
//                              view.cpp:2594 (17)
//         0053600e     MOV        this,dword ptr [ESI + 0x104]
//         00536014     XOR        EDX,EDX
//         00536016     CMP        word ptr [this->_padding_ + 0x8d90],DX
//         0053601d     JLE        LAB_00536044
//                               LAB_0053601f                                                 XREF[1]:     00536042(j)
//                              view.cpp:2595 (37)
//         0053601f     MOVSX      EDI,DX
//         00536022     MOV        EAX,EDI
//         00536024     SHL        EAX,0x4
//         00536027     ADD        EAX,EDI
//         00536029     INC        EDX
//         0053602a     LEA        EAX,[EAX + EAX*0x2]
//         0053602d     MOV        byte ptr [ECX + EAX*0x8 + this+0xd1],0x0
//         00536035     MOV        this,dword ptr [ESI + 0x104]
//         0053603b     CMP        DX,word ptr [this->_padding_ + 0x8d90]
//         00536042     JL         LAB_0053601f
//                               LAB_00536044                                                 XREF[3]:     00536002(j), 0053600c(j),
//                                                                                                         0053601d(j)
//                              view.cpp:2598 (30)
//         00536044     LEA        this=>list,[ESP + 0x80]
//         0053604b     LEA        EDX=>local_4,[ESP + 0x84]
//         00536052     PUSH       this
//         00536053     MOV        this,dword ptr [ESI + 0x100]
//         00536059     PUSH       EDX
//         0053605a     ADD        this,0x58
//         0053605d     CALL       RGE_Tile_List::get_list_info                     void get_list_info(RGE_Tile_List * this, RGE_
//                              view.cpp:2603 (56)
//         00536062     MOV        AL,byte ptr [ESI + 0x140]
//         00536068     MOV        EDI,dword ptr [ESP + param_7]
//         0053606f     MOV        EBX,dword ptr [ESP + param_6]
//         00536076     MOV        EBP,dword ptr [ESP + param_5]
//         0053607d     CMP        AL,0x28
//         0053607f     MOV        byte ptr [ESP + fog_flag],0x32
//         00536084     JZ         LAB_0053609a
//         00536086     CMP        AL,0x3c
//         00536088     JZ         LAB_0053609e
//         0053608a     CMP        AL,0x29
//         0053608c     JZ         LAB_0053609a
//         0053608e     CMP        AL,0x2a
//         00536090     JZ         LAB_0053609a
//         00536092     CMP        AL,0x2b
//         00536094     JZ         LAB_0053609a
//         00536096     CMP        AL,0x2c
//         00536098     JNZ        LAB_00536104
//                               LAB_0053609a                                                 XREF[4]:     00536084(j), 0053608c(j),
//                                                                                                         00536090(j), 00536094(j)
//                              view.cpp:2605 (4)
//         0053609a     CMP        AL,0x3c
//         0053609c     JNZ        LAB_005360b4
//                               LAB_0053609e                                                 XREF[1]:     00536088(j)
//                              view.cpp:2607 (7)
//         0053609e     FLD        float ptr [EBX]
//         005360a0     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:2608 (15)
//         005360a5     FLD        float ptr [EDI]
//         005360a7     MOV        dword ptr [ESP + find_row],EAX
//         005360ab     CALL       __ftol                                           undefined __ftol()
//         005360b0     MOV        dword ptr [ESP + max_col_num2],EAX
//                               LAB_005360b4                                                 XREF[1]:     0053609c(j)
//                              view.cpp:2612 (7)
//         005360b4     MOV        EAX,dword ptr [ESP + param_8]
//                              view.cpp:2613 (29)
//         005360bb     MOV        this,dword ptr [ESP + param_9]
//         005360c2     MOV        dword ptr [EBX],0x0
//         005360c8     MOV        dword ptr [EDI],0x0
//         005360ce     MOV        word ptr [EAX],0x0
//         005360d3     MOV        word ptr [this->_padding_],0x0
//                              view.cpp:2614 (22)
//         005360d8     MOV        AL,byte ptr [ESI + 0x140]
//         005360de     CMP        AL,0x29
//         005360e0     JZ         LAB_005360ee
//         005360e2     CMP        AL,0x2a
//         005360e4     JZ         LAB_005360ee
//         005360e6     CMP        AL,0x2b
//         005360e8     JZ         LAB_005360ee
//         005360ea     CMP        AL,0x2c
//         005360ec     JNZ        LAB_005360f5
//                               LAB_005360ee                                                 XREF[3]:     005360e0(j), 005360e4(j),
//                                                                                                         005360e8(j)
//                              view.cpp:2615 (7)
//         005360ee     MOV        EDX,dword ptr [EBP]
//         005360f1     MOV        dword ptr [ESP + find_col],EDX
//                               LAB_005360f5                                                 XREF[1]:     005360ec(j)
//                              view.cpp:2616 (7)
//         005360f5     MOV        dword ptr [EBP],0x0
//                              view.cpp:2617 (8)
//         005360fc     MOV        dword ptr [ESP + terrain_type],0x0
//                               LAB_00536104                                                 XREF[1]:     00536098(j)
//                              view.cpp:2623 (9)
//         00536104     CMP        byte ptr [ESI + 0x140],0xe
//         0053610b     JNZ        LAB_00536138
//                              view.cpp:2625 (33)
//         0053610d     LEA        EAX=>orig_picked_obj,[ESP + 0x68]
//         00536111     PUSH       0x1
//         00536113     LEA        this=>calc_sel_row1,[ESP + 0x64]
//         00536117     PUSH       EAX
//         00536118     LEA        EDX=>calc_sel_row2,[ESP + 0x6c]
//         0053611c     PUSH       this
//         0053611d     LEA        EAX=>calc_sel_col2,[ESP + 0x68]
//         00536121     PUSH       EDX
//         00536122     PUSH       EAX
//         00536123     MOV        this,ESI
//         00536125     CALL       RGE_View::get_selection_area                     int get_selection_area(RGE_View * this, long
//         0053612a     TEST       EAX,EAX
//         0053612c     JNZ        LAB_00536138
//                              view.cpp:3006 (10)
//         0053612e     POP        EDI
//         0053612f     POP        ESI
//         00536130     POP        EBP
//         00536131     POP        EBX
//         00536132     ADD        ESP,0x78
//         00536135     RET        0x24
//                               LAB_00536138                                                 XREF[2]:     0053610b(j), 0053612c(j)
//                              view.cpp:2630 (7)
//         00536138     MOV        this,word ptr [ESI + 0x126]
//                              view.cpp:2633 (19)
//         0053613f     MOV        AX,word ptr [ESI + 0x12a]
//         00536146     MOV        DX,word ptr [ESI + 0x128]
//         0053614d     MOV        word ptr [ESP + start_scr_row2],this
//                              view.cpp:2634 (12)
//         00536152     MOV        this,word ptr [ESI + 0x12c]
//         00536159     MOV        word ptr [ESP + start_map_row2],AX
//                              view.cpp:2637 (34)
//         0053615e     MOV        AX,word ptr [ESI + 0x118]
//         00536165     MOV        word ptr [ESP + direction],this
//         0053616a     MOV        this,word ptr [ESI + 0x116]
//         00536171     ADD        AX,0x6
//         00536175     SHL        EAX,0x1
//         00536177     ADD        this,0x4
//         0053617b     MOV        word ptr [ESP + cur_col_num],DX
//                              view.cpp:2642 (34)
//         00536180     TEST       AX,AX
//         00536183     MOV        dword ptr [ESP + max_row_num2],this
//         00536187     MOV        dword ptr [ESP + list_size],EAX
//         0053618b     MOV        dword ptr [ESP + picked_type],this
//         0053618f     MOV        byte ptr [ESP + tile_screen_row],0x4
//         00536194     MOV        dword ptr [ESP + calc_sel_col1],0x0
//         0053619c     JLE        LAB_00536a2c
//                               LAB_005361a2                                                 XREF[1]:     FUN_00536957:005369b1(j)
//                              view.cpp:2644 (4)
//         005361a2     MOV        EDX,dword ptr [ESP + start_scr_row2]
//                              view.cpp:2647 (4)
//         005361a6     MOV        EAX,dword ptr [ESP + start_map_row2]
//                              view.cpp:2648 (4)
//         005361aa     MOV        this,dword ptr [ESP + direction]
//                              view.cpp:2650 (32)
//         005361ae     CMP        word ptr [ESP + picked_type],0x0
//         005361b4     MOV        dword ptr [ESP + map_row],EDX
//         005361b8     MOV        dword ptr [ESP + start_scr_col2],EAX
//         005361bc     MOV        dword ptr [ESP + map_col],this
//         005361c0     MOV        dword ptr [ESP + row_num],0x0
//         005361c8     JLE        LAB_005368e0
//                               LAB_005361ce                                                 XREF[1]:     005368da(j)
//                              view.cpp:2658 (53)
//         005361ce     MOV        EDX,dword ptr [ESP + start_scr_col2]
//         005361d2     TEST       DX,DX
//         005361d5     JL         LAB_005361ff
//         005361d7     MOV        this,dword ptr [ESI + 0x104]
//         005361dd     MOVSX      EAX,DX
//         005361e0     CMP        EAX,dword ptr [ECX + this->_padding_]
//         005361e3     JGE        LAB_005361ff
//         005361e5     MOV        EAX,dword ptr [ESP + map_col]
//         005361e9     TEST       AX,AX
//         005361ec     JL         LAB_00536203
//         005361ee     MOV        EBX,dword ptr [ECX + this->_padding_]
//         005361f1     MOVSX      EDI,AX
//         005361f4     CMP        EDI,EBX
//         005361f6     JGE        LAB_00536203
//         005361f8     MOV        EBP,0x1
//         005361fd     JMP        LAB_00536221
//                               LAB_005361ff                                                 XREF[2]:     005361d5(j), 005361e3(j)
//         005361ff     MOV        EAX,dword ptr [ESP + map_col]
//                               LAB_00536203                                                 XREF[2]:     005361ec(j), 005361f6(j)
//                              view.cpp:2660 (30)
//         00536203     MOV        this,byte ptr [ESI + 0x140]
//         00536209     XOR        EBP,EBP
//         0053620b     CMP        this,0x28
//         0053620e     JZ         LAB_00536221
//         00536210     CMP        this,0x2a
//         00536213     JNZ        LAB_005368a9
//         00536219     MOV        EDX,dword ptr [ESP + start_scr_col2]
//         0053621d     MOV        EAX,dword ptr [ESP + map_col]
//                               LAB_00536221                                                 XREF[2]:     005361fd(j), 0053620e(j)
//                              view.cpp:2664 (2)
//         00536221     TEST       EBP,EBP
//                              view.cpp:2666 (6)
//         00536223     JZ         LAB_005362af
//                              view.cpp:2669 (29)
//         00536229     MOV        this,dword ptr [ESI + 0x100]
//         0053622f     MOV        this,dword ptr [ECX + this->_padding_]
//         00536232     TEST       this,this
//         00536234     JZ         LAB_0053626e
//         00536236     MOV        EDI,dword ptr [ESI + 0x104]
//         0053623c     MOV        BL,byte ptr [EDI + 0x8db8]
//         00536242     TEST       BL,BL
//         00536244     JNZ        LAB_0053626e
//                              view.cpp:2677 (13)
//         00536246     MOVSX      EBX,AX
//         00536249     MOVSX      EDI,DX
//         0053624c     PUSH       EBX
//         0053624d     PUSH       EDI
//         0053624e     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//                              view.cpp:2678 (27)
//         00536253     MOV        this,byte ptr [ESI + 0x140]
//         00536259     MOV        byte ptr [ESP + local_75],AL
//         0053625d     CMP        this,0x1e
//         00536260     JZ         LAB_00536267
//         00536262     CMP        this,0x1f
//         00536265     JNZ        LAB_00536288
//                               LAB_00536267                                                 XREF[1]:     00536260(j)
//         00536267     MOV        byte ptr [ESP + local_75],0xf
//         0053626c     JMP        LAB_00536288
//                               LAB_0053626e                                                 XREF[2]:     00536234(j), 00536244(j)
//                              view.cpp:2671 (13)
//         0053626e     MOVSX      EBX,AX
//         00536271     MOVSX      EDI,DX
//         00536274     PUSH       EBX
//         00536275     PUSH       EDI
//         00536276     CALL       RGE_Visible_Map::get_visible                     uchar get_visible(RGE_Visible_Map * this, int
//                              view.cpp:2672 (13)
//         0053627b     TEST       AL,AL
//         0053627d     MOV        byte ptr [ESP + local_75],AL
//         00536281     JNZ        LAB_00536288
//         00536283     MOV        byte ptr [ESP + local_75],0x80
//                               LAB_00536288                                                 XREF[3]:     00536265(j), 0053626c(j),
//                                                                                                         00536281(j)
//                              view.cpp:2684 (9)
//         00536288     CMP        byte ptr [ESI + 0x140],0xb
//         0053628f     JNZ        LAB_005362b4
//                              view.cpp:2686 (18)
//         00536291     MOV        EDX,dword ptr [ESI + 0x104]
//         00536297     LEA        this,[EDI + EDI*0x2]
//         0053629a     MOV        EAX,dword ptr [EDX + 0x8d8c]
//         005362a0     MOV        EDX,dword ptr [EAX + EBX*0x4]
//                              view.cpp:2687 (12)
//         005362a3     MOV        AL,byte ptr [EDX + this->_padding_*0x8 + 0x9]
//         005362a7     LEA        this,[EDX + this->_padding_*0x8]
//         005362aa     CMP        AL,byte ptr [ECX + this+0x7]
//         005362ad     JNZ        LAB_005362b4
//                               LAB_005362af                                                 XREF[1]:     00536223(j)
//                              view.cpp:2688 (5)
//         005362af     MOV        byte ptr [ESP + local_75],0x0
//                               LAB_005362b4                                                 XREF[2]:     0053628f(j), 005362ad(j)
//                              view.cpp:2710 (12)
//         005362b4     MOV        AL,byte ptr [ESP + local_75]
//         005362b8     CMP        AL,0xf
//         005362ba     JZ         LAB_005362c5
//         005362bc     CMP        AL,0x80
//         005362be     JZ         LAB_005362c5
//                              view.cpp:2711 (5)
//         005362c0     MOV        byte ptr [ESP + local_75],0x0
//                               LAB_005362c5                                                 XREF[2]:     005362ba(j), 005362be(j)
//                              view.cpp:2719 (38)
//         005362c5     MOV        AL,byte ptr [ESP + local_75]
//         005362c9     TEST       AL,AL
//         005362cb     JNZ        LAB_005362eb
//         005362cd     MOV        this,byte ptr [ESI + 0x140]
//         005362d3     CMP        this,0xe
//         005362d6     JZ         LAB_005362eb
//         005362d8     CMP        this,0x28
//         005362db     JZ         LAB_005362eb
//         005362dd     CMP        this,0x3c
//         005362e0     JZ         LAB_005362eb
//         005362e2     CMP        this,0x2a
//         005362e5     JNZ        LAB_005368a9
//                               LAB_005362eb                                                 XREF[4]:     005362cb(j), 005362d6(j),
//                                                                                                         005362db(j), 005362e0(j)
//                              view.cpp:2722 (4)
//         005362eb     TEST       EBP,EBP
//         005362ed     JNZ        LAB_005362fc
//                              view.cpp:2724 (4)
//         005362ef     MOV        dword ptr [ESP + start_map_col2],EBP
//                              view.cpp:2725 (5)
//         005362f3     MOV        byte ptr [ESP + col_num],0x0
//                              view.cpp:2726 (2)
//         005362f8     XOR        this,this
//                              view.cpp:2728 (2)
//         005362fa     JMP        LAB_0053632d
//                               LAB_005362fc                                                 XREF[1]:     005362ed(j)
//                              view.cpp:2730 (28)
//         005362fc     MOV        EAX,dword ptr [ESI + 0x104]
//         00536302     MOVSX      EDX,word ptr [ESP + map_col]
//         00536307     MOVSX      this,word ptr [ESP + start_scr_col2]
//         0053630c     MOV        EAX,dword ptr [EAX + 0x8d8c]
//         00536312     LEA        this,[ECX + ECX*0x2]
//         00536315     MOV        EDX,dword ptr [EAX + EDX*0x4]
//                              view.cpp:2731 (15)
//         00536318     MOV        AL,byte ptr [EDX + this->_padding_*0x8 + 0x4]
//         0053631c     LEA        EBP,[EDX + this->_padding_*0x8]
//         0053631f     MOV        byte ptr [ESP + col_num],AL
//         00536323     MOV        dword ptr [ESP + start_map_col2],EBP
//                              view.cpp:2732 (6)
//         00536327     MOV        this,byte ptr [EBP + 0x5]
//         0053632a     SHR        this,0x5
//                               LAB_0053632d                                                 XREF[1]:     005362fa(j)
//                              view.cpp:2739 (20)
//         0053632d     MOV        DX,word ptr [ESI + 0x110]
//         00536334     MOV        EBX,dword ptr [ESP + cur_col_num]
//         00536338     MOVZX      this,this
//         0053633c     IMUL       this,EDX
//         0053633f     SUB        EBX,this
//                              view.cpp:2744 (37)
//         00536341     MOV        this,dword ptr [ESP + col_num]
//         00536345     AND        this,0xff
//         0053634b     MOV        dword ptr [ESP + last_picked_obj],EBX
//         0053634f     LEA        EDI,[this->_padding_ + -0x2]
//         00536352     CMP        EDI,0xe
//         00536355     JA         switchD_0053635f::caseD_3
//         00536357     XOR        EAX,EAX
//         00536359     MOV        AL,byte ptr [EDI + 0x536b1c]=>PTR_caseD_3_0053
//                               switchD_0053635f::switchD
//         0053635f     JMP        dword ptr [EAX*0x4 + switchD_0053635f::switchd   = 00536366
//                               switchD_0053635f::caseD_6                                    XREF[6]:     0053635f(j), 00536b04(*),
//                               switchD_0053635f::caseD_8                                                 00536b08(*), 00536b0c(*),
//                               switchD_0053635f::caseD_a                                                 00536b10(*), 00536b14(*)
//                               switchD_0053635f::caseD_e
//                               switchD_0053635f::caseD_f
//                               switchD_0053635f::caseD_10
//                               switchD_0053635f::caseD_2
//                              view.cpp:2753 (6)
//         00536366     SUB        EBX,EDX
//         00536368     MOV        dword ptr [ESP + last_picked_obj],EBX
//                               switchD_0053635f::caseD_4                                    XREF[3]:     00536355(j), 0053635f(j),
//                               switchD_0053635f::caseD_5                                                 00536b18(*)
//                               switchD_0053635f::caseD_7
//                               switchD_0053635f::caseD_9
//                               switchD_0053635f::caseD_b
//                               switchD_0053635f::caseD_c
//                               switchD_0053635f::caseD_d
//                               switchD_0053635f::caseD_3
//                              view.cpp:2761 (74)
//         0053636c     MOVSX      EAX,word ptr [ESP + map_row]
//         00536371     CMP        EAX,dword ptr [ESI + 0x94]
//         00536377     JG         LAB_005363e5
//         00536379     MOV        EDX,dword ptr [ESI + 0x98]
//         0053637f     MOVSX      EBX,BX
//         00536382     CMP        EBX,EDX
//         00536384     JG         LAB_005363e5
//         00536386     MOV        EDI,dword ptr [ESI + 0x104]
//         0053638c     LEA        EDX,[ECX + this->_padding_]
//         0053638f     LEA        EDX,[EDX + EDX*0x2]
//         00536392     MOVSX      EDX,word ptr [EDI + EDX*0x2]
//         00536396     ADD        EDX,EAX
//         00536398     MOV        EAX,dword ptr [ESI + 0x8c]
//         0053639e     CMP        EDX,EAX
//         005363a0     JLE        LAB_005363e5
//         005363a2     LEA        EAX,[ECX + ECX*0x2]
//         005363a5     MOVSX      this,word ptr [EDI + EAX*0x2 + 0x1a]
//         005363aa     MOV        EAX,dword ptr [ESI + 0x90]
//         005363b0     ADD        this,EBX
//         005363b2     CMP        this,EAX
//         005363b4     JLE        LAB_005363e5
//                              view.cpp:2765 (41)
//         005363b6     CMP        byte ptr [ESI + 0x140],0xe
//         005363bd     JNZ        LAB_005363e1
//         005363bf     MOVSX      EAX,word ptr [ESP + start_scr_col2]
//         005363c4     CMP        EAX,dword ptr [ESP + calc_sel_col2]
//         005363c8     JL         LAB_005363e5
//         005363ca     CMP        EAX,dword ptr [ESP + calc_sel_row1]
//         005363ce     JG         LAB_005363e5
//         005363d0     MOVSX      EAX,word ptr [ESP + map_col]
//         005363d5     CMP        EAX,dword ptr [ESP + calc_sel_row2]
//         005363d9     JL         LAB_005363e5
//         005363db     CMP        EAX,dword ptr [ESP + orig_picked_obj]
//                              view.cpp:2767 (2)
//         005363df     JG         LAB_005363e5
//                               LAB_005363e1                                                 XREF[1]:     005363bd(j)
//                              view.cpp:2768 (4)
//         005363e1     XOR        EAX,EAX
//         005363e3     JMP        LAB_005363ea
//                               LAB_005363e5                                                 XREF[8]:     00536377(j), 00536384(j),
//                                                                                                         005363a0(j), 005363b4(j),
//                                                                                                         005363c8(j), 005363ce(j),
//                                                                                                         005363d9(j), 005363df(j)
//                              view.cpp:2762 (5)
//         005363e5     MOV        EAX,0x1
//                               LAB_005363ea                                                 XREF[1]:     005363e3(j)
//                              view.cpp:2777 (69)
//         005363ea     MOV        this,byte ptr [ESI + 0x140]
//         005363f0     CMP        this,0xa
//         005363f3     JZ         LAB_005365ee
//         005363f9     CMP        this,0x1e
//         005363fc     JZ         LAB_005365ee
//         00536402     CMP        this,0x1f
//         00536405     JZ         LAB_005365ee
//         0053640b     CMP        this,0x20
//         0053640e     JZ         LAB_005365ee
//         00536414     CMP        this,0x15
//         00536417     JZ         LAB_005365ee
//         0053641d     CMP        this,0xb
//         00536420     JZ         LAB_005365ee
//         00536426     CMP        this,0xe
//         00536429     JZ         LAB_005365ee
//                              view.cpp:2876 (40)
//         0053642f     MOV        AL,byte ptr [ESP + local_75]
//         00536433     CMP        AL,0xf
//         00536435     JZ         LAB_0053643f
//         00536437     CMP        AL,0x80
//         00536439     JNZ        LAB_005364d7
//                               LAB_0053643f                                                 XREF[1]:     00536435(j)
//         0053643f     CMP        this,0x29
//         00536442     JZ         LAB_00536457
//         00536444     CMP        this,0x2a
//         00536447     JZ         LAB_00536457
//         00536449     CMP        this,0x2b
//         0053644c     JZ         LAB_00536457
//         0053644e     CMP        this,0x2c
//         00536451     JNZ        LAB_005364d7
//                               LAB_00536457                                                 XREF[3]:     00536442(j), 00536447(j),
//                                                                                                         0053644c(j)
//                              view.cpp:2878 (24)
//         00536457     CMP        AL,0xf
//         00536459     JZ         LAB_00536476
//         0053645b     CMP        AL,0x80
//         0053645d     JNZ        LAB_0053646f
//         0053645f     MOV        EDX,dword ptr [ESI + 0x104]
//         00536465     MOV        AL,byte ptr [EDX + 0x8db9]
//         0053646b     TEST       AL,AL
//         0053646d     JZ         LAB_00536476
//                               LAB_0053646f                                                 XREF[1]:     0053645d(j)
//                              view.cpp:2881 (7)
//         0053646f     MOV        byte ptr [ESP + tile],0x1
//         00536474     JMP        LAB_0053647b
//                               LAB_00536476                                                 XREF[2]:     00536459(j), 0053646d(j)
//                              view.cpp:2879 (5)
//         00536476     MOV        byte ptr [ESP + tile],0x0
//                               LAB_0053647b                                                 XREF[1]:     00536474(j)
//                              view.cpp:2883 (70)
//         0053647b     MOV        EAX,dword ptr [ESP + tile]
//         0053647f     MOV        EDI,dword ptr [ESP + find_col]
//         00536483     MOV        this,dword ptr [ESP + param_9]
//         0053648a     MOV        EDX,dword ptr [ESP + param_8]
//         00536491     PUSH       EAX
//         00536492     MOV        EAX,dword ptr [ESP + param_4]
//         00536499     PUSH       EDI
//         0053649a     PUSH       this
//         0053649b     MOV        this,dword ptr [ESP + param_3]
//         005364a2     PUSH       EDX
//         005364a3     MOV        EDX,dword ptr [ESP + map_col]
//         005364a7     PUSH       EAX
//         005364a8     MOV        EAX,dword ptr [ESP + start_scr_col2]
//         005364ac     PUSH       this
//         005364ad     MOV        this,dword ptr [ESP + cur_col_num]
//         005364b1     PUSH       EDX
//         005364b2     MOV        EDX,dword ptr [ESP + map_row]
//         005364b6     PUSH       EAX
//         005364b7     PUSH       this
//         005364b8     PUSH       EDX
//         005364b9     PUSH       EBP
//         005364ba     MOV        this,ESI
//         005364bc     CALL       RGE_View::hit_object                             RGE_Static_Object * hit_object(RGE_View * thi
//                              view.cpp:2885 (4)
//         005364c1     TEST       EAX,EAX
//         005364c3     JZ         LAB_005364d7
//                              view.cpp:2887 (13)
//         005364c5     CMP        byte ptr [ESI + 0x140],0x2c
//         005364cc     JNZ        LAB_00536a9e
//                              view.cpp:2888 (5)
//         005364d2     MOV        byte ptr [ESP + fog_flag],0x34
//                               LAB_005364d7                                                 XREF[5]:     00536439(j), 00536451(j),
//                                                                                                         005364c3(j),
//                                                                                                         FUN_00536957:00536acf(j),
//                                                                                                         FUN_00536957:00536ad7(j)
//                              view.cpp:2889 (14)
//         005364d7     MOV        EDI,dword ptr [ESP + param_7]
//         005364de     MOV        EBX,dword ptr [ESP + param_6]
//                               LAB_005364e5                                                 XREF[1]:     FUN_00536957:00536afe(j)
//                              view.cpp:2911 (21)
//         005364e5     MOV        AL,byte ptr [ESI + 0x140]
//         005364eb     CMP        AL,0x28
//         005364ed     JZ         LAB_00536525
//         005364ef     CMP        AL,0x2a
//         005364f1     JNZ        LAB_005364fa
//         005364f3     CMP        byte ptr [ESP + fog_flag],0x32
//         005364f8     JZ         LAB_00536525
//                               LAB_005364fa                                                 XREF[1]:     005364f1(j)
//                              view.cpp:2937 (8)
//         005364fa     CMP        AL,0x3c
//         005364fc     JNZ        LAB_005368a9
//                              view.cpp:2939 (35)
//         00536502     MOV        this,dword ptr [ESP + start_scr_col2]
//         00536506     CMP        this,word ptr [ESP + find_row]
//         0053650b     JNZ        LAB_005368a9
//         00536511     MOV        EAX,dword ptr [ESP + map_col]
//         00536515     CMP        AX,word ptr [ESP + max_col_num2]
//         0053651a     JZ         LAB_005369dc
//         00536520     JMP        LAB_005368a9
//                               LAB_00536525                                                 XREF[2]:     005364ed(j), 005364f8(j)
//                              view.cpp:2915 (44)
//         00536525     MOV        EAX,dword ptr [ESP + param_3]
//         0053652c     MOV        this,dword ptr [ESP + map_col]
//         00536530     MOV        EDX,dword ptr [ESP + start_scr_col2]
//         00536534     PUSH       EAX
//         00536535     MOV        EAX,dword ptr [ESP + last_picked_obj]
//         00536539     PUSH       this
//         0053653a     MOV        this,dword ptr [ESP + map_row]
//         0053653e     PUSH       EDX
//         0053653f     PUSH       EAX
//         00536540     PUSH       this
//         00536541     PUSH       EBP
//         00536542     MOV        this,ESI
//         00536544     CALL       RGE_View::hit_tile                               int hit_tile(RGE_View * this, RGE_Tile * para
//         00536549     TEST       EAX,EAX
//         0053654b     JZ         LAB_005368a9
//                              view.cpp:2917 (4)
//         00536551     TEST       EBP,EBP
//         00536553     JZ         LAB_0053659f
//                              view.cpp:2919 (40)
//         00536555     MOV        EAX,dword ptr [ESP + param_3]
//         0053655c     MOV        this,dword ptr [ESI + 0x104]
//         00536562     PUSH       EDI
//         00536563     PUSH       EBX
//         00536564     MOV        DX,word ptr [EAX + 0x4]
//         00536568     MOV        AX,word ptr [EAX]
//         0053656b     SUB        DX,word ptr [ESP + last_picked_obj]
//         00536570     SUB        AX,word ptr [ESP + map_row]
//         00536575     PUSH       EBP
//         00536576     PUSH       EDX
//         00536577     PUSH       EAX
//         00536578     CALL       RGE_Map::tile_map_coords                         void tile_map_coords(RGE_Map * this, short pa
//                              view.cpp:2920 (5)
//         0053657d     MOVSX      this,word ptr [ESP + start_scr_col2]
//                              view.cpp:2921 (27)
//         00536582     MOVSX      EDX,word ptr [ESP + map_col]
//         00536587     MOV        dword ptr [ESP + start_map_col2],this
//         0053658b     FILD       dword ptr [ESP + start_map_col2]
//         0053658f     MOV        dword ptr [ESP + start_map_col2],EDX
//         00536593     FADD       float ptr [EBX]
//         00536595     FSTP       float ptr [EBX]
//         00536597     FILD       dword ptr [ESP + start_map_col2]
//         0053659b     FADD       float ptr [EDI]
//                              view.cpp:2923 (2)
//         0053659d     JMP        LAB_005365bb
//                               LAB_0053659f                                                 XREF[1]:     00536553(j)
//                              view.cpp:2925 (5)
//         0053659f     MOVSX      EAX,word ptr [ESP + start_scr_col2]
//                              view.cpp:2926 (23)
//         005365a4     MOVSX      this,word ptr [ESP + map_col]
//         005365a9     MOV        dword ptr [ESP + start_map_col2],EAX
//         005365ad     FILD       dword ptr [ESP + start_map_col2]
//         005365b1     MOV        dword ptr [ESP + start_map_col2],this
//         005365b5     FSTP       float ptr [EBX]
//         005365b7     FILD       dword ptr [ESP + start_map_col2]
//                               LAB_005365bb                                                 XREF[1]:     0053659d(j)
//                              view.cpp:2928 (14)
//         005365bb     MOV        EAX,dword ptr [ESP + param_8]
//         005365c2     MOV        DX,word ptr [ESP + map_row]
//         005365c7     FSTP       float ptr [EDI]
//                              view.cpp:2929 (15)
//         005365c9     MOV        this,word ptr [ESP + last_picked_obj]
//         005365ce     MOV        word ptr [EAX],DX
//         005365d1     MOV        EDX,dword ptr [ESP + param_9]
//                              view.cpp:2930 (7)
//         005365d8     MOV        EAX,dword ptr [ESP + param_5]
//                              view.cpp:2934 (10)
//         005365df     MOV        byte ptr [ESP + fog_flag],0x33
//         005365e4     MOV        word ptr [EDX],this
//         005365e7     MOV        dword ptr [EAX],EBP
//                              view.cpp:2937 (5)
//         005365e9     JMP        LAB_005368a9
//                               LAB_005365ee                                                 XREF[7]:     005363f3(j), 005363fc(j),
//                                                                                                         00536405(j), 0053640e(j),
//                                                                                                         00536417(j), 00536420(j),
//                                                                                                         00536429(j)
//                              view.cpp:2782 (30)
//         005365ee     TEST       EAX,EAX
//         005365f0     JNZ        LAB_0053669c
//         005365f6     MOV        AL,byte ptr [ESI + 0x140]
//         005365fc     CMP        AL,0xa
//         005365fe     JZ         LAB_0053660c
//         00536600     CMP        AL,0xb
//         00536602     JZ         LAB_0053660c
//         00536604     CMP        AL,0xe
//         00536606     JNZ        LAB_0053669c
//                               LAB_0053660c                                                 XREF[2]:     005365fe(j), 00536602(j)
//                              view.cpp:2787 (3)
//         0053660c     MOV        BL,byte ptr [EBP + 0x5]
//                              view.cpp:2788 (43)
//         0053660f     MOV        EDI,dword ptr [ESI + 0x104]
//         00536615     AND        BL,0x1f
//         00536618     MOV        byte ptr [ESP + tile_type],BL
//         0053661c     MOV        EDX,dword ptr [ESP + tile_type]
//         00536620     MOV        this,EDX
//         00536622     AND        this,0xff
//         00536628     MOV        EAX,this
//         0053662a     SHL        EAX,0x4
//         0053662d     ADD        EAX,this
//         0053662f     LEA        this,[EAX + EAX*0x2]
//         00536632     MOV        AX,word ptr [EDI + this->_padding_*0x8 + 0x144]
//                              view.cpp:2789 (6)
//         0053663a     CMP        AX,0xffff
//         0053663e     JZ         LAB_0053664a
//                              view.cpp:2790 (10)
//         00536640     MOV        BL,AL
//         00536642     MOV        byte ptr [ESP + tile_type],BL
//         00536646     MOV        EDX,dword ptr [ESP + tile_type]
//                               LAB_0053664a                                                 XREF[1]:     0053663e(j)
//                              view.cpp:2794 (33)
//         0053664a     CMP        byte ptr [ESI + 0x140],0xa
//         00536651     JNZ        LAB_0053668d
//         00536653     MOV        EAX,dword ptr [ESI + 0xf8]
//         00536659     TEST       EAX,EAX
//         0053665b     JZ         LAB_0053668d
//         0053665d     XOR        AX,AX
//         00536660     MOV        AL,BL
//         00536662     CMP        AX,word ptr [EDI + 0x8d90]
//         00536669     JGE        LAB_0053668d
//                              view.cpp:2795 (34)
//         0053666b     AND        EDX,0xff
//         00536671     MOV        EAX,EDX
//         00536673     SHL        EAX,0x4
//         00536676     ADD        EAX,EDX
//         00536678     LEA        this,[EAX + EAX*0x2]
//         0053667b     LEA        EAX,[EDI + this->_padding_*0x8 + 0xd1]
//         00536682     MOV        this,byte ptr [EDI + this->_padding_*0x8 + 0xd1]
//         00536689     INC        this
//         0053668b     MOV        byte ptr [EAX],this
//                               LAB_0053668d                                                 XREF[3]:     00536651(j), 0053665b(j),
//                                                                                                         00536669(j)
//                              view.cpp:2799 (9)
//         0053668d     CMP        byte ptr [ESI + 0x140],0xb
//         00536694     JNZ        LAB_0053669c
//                              view.cpp:2800 (6)
//         00536696     MOV        DL,byte ptr [EBP + 0x9]
//         00536699     MOV        byte ptr [EBP + 0x7],DL
//                               LAB_0053669c                                                 XREF[3]:     005365f0(j), 00536606(j),
//                                                                                                         00536694(j)
//                              view.cpp:2809 (42)
//         0053669c     MOV        AL,byte ptr [ESP + local_75]
//         005366a0     CMP        AL,0xf
//         005366a2     JZ         LAB_005366ac
//         005366a4     CMP        AL,0x80
//         005366a6     JNZ        LAB_005368a9
//                               LAB_005366ac                                                 XREF[1]:     005366a2(j)
//         005366ac     MOV        AL,byte ptr [ESI + 0x140]
//         005366b2     CMP        AL,0x1e
//         005366b4     JZ         LAB_005366c6
//         005366b6     CMP        AL,0x1f
//         005366b8     JZ         LAB_005366c6
//         005366ba     CMP        AL,0x20
//         005366bc     JZ         LAB_005366c6
//         005366be     CMP        AL,0x15
//         005366c0     JNZ        LAB_005368a9
//                               LAB_005366c6                                                 XREF[3]:     005366b4(j), 005366b8(j),
//                                                                                                         005366bc(j)
//                              view.cpp:2812 (30)
//         005366c6     MOV        this,byte ptr [ESP + local_75]
//         005366ca     CMP        this,0xf
//         005366cd     JZ         LAB_005366eb
//         005366cf     CMP        this,0x80
//         005366d2     JNZ        LAB_005366e4
//         005366d4     MOV        this,dword ptr [ESI + 0x104]
//         005366da     MOV        DL,byte ptr [this->_padding_ + 0x8db9]
//         005366e0     TEST       DL,DL
//         005366e2     JZ         LAB_005366eb
//                               LAB_005366e4                                                 XREF[1]:     005366d2(j)
//                              view.cpp:2815 (7)
//         005366e4     MOV        byte ptr [ESP + tile],0x1
//         005366e9     JMP        LAB_005366f0
//                               LAB_005366eb                                                 XREF[2]:     005366cd(j), 005366e2(j)
//                              view.cpp:2813 (5)
//         005366eb     MOV        byte ptr [ESP + tile],0x0
//                               LAB_005366f0                                                 XREF[1]:     005366e9(j)
//                              view.cpp:2817 (12)
//         005366f0     MOV        EDI,dword ptr [ESP + tile]
//         005366f4     CMP        AL,0x1e
//         005366f6     JNZ        LAB_00536783
//                              view.cpp:2822 (12)
//         005366fc     MOV        EDX,dword ptr [ESI + 0xf4]
//         00536702     MOV        EAX,dword ptr [ESI + 0x17c]
//                              view.cpp:2824 (50)
//         00536708     MOV        this,dword ptr [ESP + start_map_col2]
//         0053670c     MOV        EBX,dword ptr [ESP + cur_col_num]
//         00536710     MOV        dword ptr [EDX + 0xd0],EAX
//         00536716     MOV        EDX,dword ptr [ESP + map_row]
//         0053671a     PUSH       EDI
//         0053671b     MOV        dword ptr [fog_next_shape],0x1
//         00536725     MOV        EAX,dword ptr [ESI + 0xf4]
//         0053672b     PUSH       0x1
//         0053672d     LEA        EBP,[ECX + this->_padding_]
//         00536730     PUSH       EBX
//         00536731     PUSH       EDX
//         00536732     PUSH       EAX
//         00536733     MOV        this,EBP
//         00536735     CALL       RGE_Object_List::shadow_draw                     void shadow_draw(RGE_Object_List * this, TDra
//                              view.cpp:2826 (12)
//         0053673a     MOV        this,dword ptr [ESI + 0xf4]
//         00536740     MOV        EDX,dword ptr [ESI + 0x178]
//                              view.cpp:2828 (39)
//         00536746     MOV        EAX,dword ptr [ESP + map_row]
//         0053674a     PUSH       EDI
//         0053674b     MOV        dword ptr [ECX + this->_padding_],EDX
//         00536751     MOV        dword ptr [fog_next_shape],0x0
//         0053675b     MOV        this,dword ptr [ESI + 0xf4]
//         00536761     PUSH       0x1
//         00536763     PUSH       EBX
//         00536764     PUSH       EAX
//         00536765     PUSH       this
//         00536766     MOV        this,EBP
//         00536768     CALL       RGE_Object_List::shadow_draw                     void shadow_draw(RGE_Object_List * this, TDra
//                              view.cpp:2830 (22)
//         0053676d     MOV        EAX,dword ptr [ESI + 0xf4]
//         00536773     MOV        EBP,dword ptr [ESP + start_map_col2]
//         00536777     MOV        EDX,dword ptr [EAX + 0xcc]
//         0053677d     MOV        dword ptr [EAX + 0xd0],EDX
//                               LAB_00536783                                                 XREF[1]:     005366f6(j)
//                              view.cpp:2832 (13)
//         00536783     CMP        byte ptr [ESI + 0x140],0x1f
//         0053678a     JNZ        LAB_00536817
//                              view.cpp:2837 (12)
//         00536790     MOV        EAX,dword ptr [ESI + 0xf4]
//         00536796     MOV        this,dword ptr [ESI + 0x17c]
//                              view.cpp:2839 (50)
//         0053679c     MOV        EDX,dword ptr [ESP + start_map_col2]
//         005367a0     MOV        EBX,dword ptr [ESP + cur_col_num]
//         005367a4     MOV        dword ptr [EAX + 0xd0],this
//         005367aa     MOV        EAX,dword ptr [ESP + map_row]
//         005367ae     PUSH       EDI
//         005367af     MOV        dword ptr [fog_next_shape],0x1
//         005367b9     MOV        this,dword ptr [ESI + 0xf4]
//         005367bf     PUSH       0xa
//         005367c1     PUSH       EBX
//         005367c2     LEA        EBP,[EDX + 0xc]
//         005367c5     PUSH       EAX
//         005367c6     PUSH       this
//         005367c7     MOV        this,EBP
//         005367c9     CALL       RGE_Object_List::shadow_draw                     void shadow_draw(RGE_Object_List * this, TDra
//                              view.cpp:2841 (12)
//         005367ce     MOV        EDX,dword ptr [ESI + 0xf4]
//         005367d4     MOV        EAX,dword ptr [ESI + 0x178]
//                              view.cpp:2843 (39)
//         005367da     MOV        this,dword ptr [ESP + map_row]
//         005367de     PUSH       EDI
//         005367df     MOV        dword ptr [EDX + 0xd0],EAX
//         005367e5     MOV        dword ptr [fog_next_shape],0x0
//         005367ef     MOV        EDX,dword ptr [ESI + 0xf4]
//         005367f5     PUSH       0xa
//         005367f7     PUSH       EBX
//         005367f8     PUSH       this
//         005367f9     PUSH       EDX
//         005367fa     MOV        this,EBP
//         005367fc     CALL       RGE_Object_List::shadow_draw                     void shadow_draw(RGE_Object_List * this, TDra
//                              view.cpp:2845 (22)
//         00536801     MOV        EAX,dword ptr [ESI + 0xf4]
//         00536807     MOV        EBP,dword ptr [ESP + start_map_col2]
//         0053680b     MOV        this,dword ptr [EAX + 0xcc]
//         00536811     MOV        dword ptr [EAX + 0xd0],this
//                               LAB_00536817                                                 XREF[1]:     0053678a(j)
//                              view.cpp:2847 (10)
//         00536817     MOV        AL,byte ptr [ESI + 0x140]
//         0053681d     CMP        AL,0x20
//         0053681f     JNZ        LAB_00536860
//                              view.cpp:2850 (33)
//         00536821     MOV        EDX,dword ptr [ESI + 0x104]
//         00536827     MOV        AL,byte ptr [EDX + 0x8db9]
//         0053682d     TEST       AL,AL
//         0053682f     JZ         LAB_00536842
//         00536831     CMP        byte ptr [ESP + local_75],0x80
//         00536836     JNZ        LAB_00536842
//         00536838     MOV        dword ptr [fog_next_shape],0x1
//                               LAB_00536842                                                 XREF[2]:     0053682f(j), 00536836(j)
//                              view.cpp:2853 (28)
//         00536842     MOV        EAX,dword ptr [ESP + cur_col_num]
//         00536846     MOV        this,dword ptr [ESP + map_row]
//         0053684a     MOV        EDX,dword ptr [ESI + 0xf4]
//         00536850     PUSH       EDI
//         00536851     PUSH       0x0
//         00536853     PUSH       EAX
//         00536854     PUSH       this
//         00536855     PUSH       EDX
//         00536856     LEA        this,[EBP + 0xc]
//         00536859     CALL       RGE_Object_List::shadow_draw                     void shadow_draw(RGE_Object_List * this, TDra
//                              view.cpp:2862 (6)
//         0053685e     JMP        LAB_0053689f
//                               LAB_00536860                                                 XREF[1]:     0053681f(j)
//         00536860     CMP        AL,0x15
//         00536862     JNZ        LAB_005368a9
//                              view.cpp:2867 (33)
//         00536864     MOV        EAX,dword ptr [ESI + 0x104]
//         0053686a     MOV        this,byte ptr [EAX + 0x8db9]
//         00536870     TEST       this,this
//         00536872     JZ         LAB_00536885
//         00536874     CMP        byte ptr [ESP + local_75],0x80
//         00536879     JNZ        LAB_00536885
//         0053687b     MOV        dword ptr [fog_next_shape],0x1
//                               LAB_00536885                                                 XREF[2]:     00536872(j), 00536879(j)
//                              view.cpp:2868 (26)
//         00536885     MOV        this,dword ptr [ESP + cur_col_num]
//         00536889     MOV        EDX,dword ptr [ESP + map_row]
//         0053688d     MOV        EAX,dword ptr [ESI + 0xf4]
//         00536893     PUSH       EDI
//         00536894     PUSH       this
//         00536895     PUSH       EDX
//         00536896     PUSH       EAX
//         00536897     LEA        this,[EBP + 0xc]
//         0053689a     CALL       RGE_Object_List::normal_draw                     void normal_draw(RGE_Object_List * this, TDra
//                               LAB_0053689f                                                 XREF[1]:     0053685e(j)
//                              view.cpp:2869 (10)
//         0053689f     MOV        dword ptr [fog_next_shape],0x0
//                               LAB_005368a9                                                 XREF[10]:    00536213(j), 005362e5(j),
//                                                                                                         005364fc(j), 0053650b(j),
//                                                                                                         00536520(j), 0053654b(j),
//                                                                                                         005365e9(j), 005366a6(j),
//                                                                                                         005366c0(j), 00536862(j)
//                              view.cpp:2954 (11)
//         005368a9     MOV        this,word ptr [ESI + 0x108]
//         005368b0     MOV        EBP,dword ptr [ESP + map_row]
//                              view.cpp:2955 (4)
//         005368b4     MOV        EBX,dword ptr [ESP + start_scr_col2]
//                              view.cpp:2956 (40)
//         005368b8     MOV        EDI,dword ptr [ESP + map_col]
//         005368bc     MOV        EAX,dword ptr [ESP + row_num]
//         005368c0     ADD        EBP,this
//         005368c2     INC        EBX
//         005368c3     INC        EDI
//         005368c4     INC        EAX
//         005368c5     MOV        dword ptr [ESP + map_row],EBP
//         005368c9     CMP        AX,word ptr [ESP + picked_type]
//         005368ce     MOV        dword ptr [ESP + start_scr_col2],EBX
//         005368d2     MOV        dword ptr [ESP + map_col],EDI
//         005368d6     MOV        dword ptr [ESP + row_num],EAX
//         005368da     JL         LAB_005361ce
//                               LAB_005368e0                                                 XREF[1]:     005361c8(j)
//                              view.cpp:2959 (7)
//         005368e0     CMP        byte ptr [ESP + tile_screen_row],0x1
//         005368e5     JNZ        LAB_005368f8
//                              view.cpp:2961 (12)
//         005368e7     MOV        DX,word ptr [ESP + picked_type]
//         005368ec     CMP        DX,word ptr [ESP + max_row_num2]
//         005368f1     JNZ        LAB_005368f8
//                              view.cpp:2962 (5)
//         005368f3     MOV        byte ptr [ESP + tile_screen_row],0x2
//                               LAB_005368f8                                                 XREF[2]:     005368e5(j), 005368f1(j)
//                              view.cpp:2965 (26)
//         005368f8     MOV        EAX,dword ptr [ESP + tile_screen_row]
//         005368fc     AND        EAX,0xff
//         00536901     DEC        EAX
//         00536902     CMP        EAX,0x3
//         00536905     JA         switchD_0053690b::default
//                               switchD_0053690b::switchD
//         0053690b     JMP        dword ptr [EAX*0x4 + DAT_00536b2c]               = 12h
    return 0;
}

long RGE_View::view_function_terrain(uchar param_1, tagRECT param_2) {
    /* TODO: Stub */
//                              long __thiscall view_function_terrain(RGE_View * this, uchar param_1
//              long              EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00536b9d(R)
//              tagRECT           Stack[0x8]:16  param_2                   XREF[1,1]:   00537522(R), 00537537(R)
//              char[128]         Stack[-0x84]   pText
//              tagRECT           Stack[-0x94]   panel_rect
//              tagPOINT          Stack[-0x9c]:8 CPoint
//              int               Stack[-0xa0]:4 theObj                    XREF[2]:     00536b90(W), 005374e2(R)
//              int               Stack[-0xa4]:4 rows_2_scan               XREF[2]:     00536c81(W), 005374cb(R)
//              undefined4        Stack[-0xa8]:4 local_a8                  XREF[4]:     00536bfd(W), 00536d4a(R), 00536e9a(R), 00536ffc(R)
//              ulong             Stack[-0xac]:4 TileFoggedMask            XREF[4]:     00536b86(W), 00536c9a(R), 005374a0(R), 005374b0(R)
//              int               Stack[-0xb0]:4 cols_2_scan               XREF[4]:     0053702f(W), 00537063(R), 005371bd(R), 0053729f(R)
//              VSpanMiniList *   Stack[-0xb4]:4 normal_draw_data          XREF[4]:     00536c9e(W), 005374a4(W), 005374ac(R), 005374c1(W)
//              int               Stack[-0xb8]:4 col_num                   XREF[3]:     00536b70(W), 00536c50(R), 005374d8(RW)
//              int               Stack[-0xbc]:4 start_map_x               XREF[4]:     00537037(W), 0053705d(W), 005371db(R), 005372b9(R)
//              VSpanMiniList *   Stack[-0xc0]:4 fog_draw_data             XREF[4]:     00536c0c(W), 00536d38(R), 00536e4f(R), 00536fc1(R)
//              ulong             Stack[-0xc4]:4 TileVisibleMask           XREF[5]:     00536c2e(W), 00536c3c(W), 00536d50(R), 00536e8e(R),
//                                                                                     00536fa9(R)
//              int               Stack[-0xc8]:4 Full_Visibility           XREF[6]:     00536e1c(W), 00536f11(W), 00536f1b(W), 00536f5b(R),
//                                                                                     00536f65(W), 00537231(R)
//              int               Stack[-0xcc]:4 rect2                     XREF[6]:     00536f91(W), 00537024(R), 00537087(W), 00537091(W),
//                                                                                     005371ed(R), 005372cb(R)
//              int               Stack[-0xd0]:4 black_draw                XREF[6]:     00536bb6(W), 00536cc2(R), 00536e53(R), 00536e9e(R),
//                                                                                     00536fc5(R), 00537000(R)
//              int               Stack[-0xd4]:4 Map_Height                XREF[6]:     00536c5a(W), 00536fd3(R), 0053700e(R), 00537376(R),
//                                                                                     00537391(R), 005374b9(W)
//              int               Stack[-0xd8]:4 map_col                   XREF[6]:     00536ba4(W), 00536cce(R), 00536e57(R), 00536ea2(R),
//                                                                                     00536fc9(R), 00537004(R)
//              int               Stack[-0xdc]:4 Map_Width                 XREF[7]:     00536e16(W), 00536f51(W), 00536f69(W), 00537099(R),
//                                                                                     005370fb(R), 00537152(R), 005371a9(R)
//              int               Stack[-0xe0]:4 clip_to                   XREF[7]:     0053704d(W), 00537079(W), 005371cf(R), 00537213(R),
//                                                                                     005372b1(R), 005372ed(R), 00537358(R)
//              int               Stack[-0xe4]:4 fog_draw                  XREF[9]:     00536d16(W), 00536d98(R), 00536ee9(R), 00536f27(R),
//                                                                                     00537045(W), 00537201(R), 0053721f(R), 005372db(R),
//                                                                                     005372f5(R)
//              VSpanMiniList *   Stack[-0xe8]:4 black_draw_data           XREF[10]:    00536e08(W), 00536e49(W), 00536e6b(W), 00536e6f(R),
//                                                                                     00536fa1(W), 00536fb3(R), 00536fe1(W), 00536fe9(W),
//                                                                                     00537020(R), 00537347(R)
//              int               Stack[-0xec]:4 tile_mask_num             XREF[11]:    00536d2d(W), 00536daa(R), 00536f05(R), 00536f43(R),
//                                                                                     00537055(W), 0053706e(W), 005371b1(R), 005371f5(R),
//                                                                                     0053728b(R), 005372d3(R), 00537365(R)
//              int               Stack[-0xf0]:4 screen_row2               XREF[10]:    00536e0c(W), 00536e94(W), 00536eb6(W), 00536eba(R),
//                                                                                     00536faf(W), 00536fed(R), 0053701c(W), 00537033(R),
//                                                                                     0053707d(R), 00537343(R)
//              int               Stack[-0xf4]:4 black_tile_mask_num       XREF[3]:     00536b74(W), 00536c54(R), 005374de(RW)
//              int               Stack[-0xf8]:4 text_id                   XREF[3]:     00536c46(W), 005374cf(R), 005374ec(W)
//              int               Stack[-0xfc]:4 newFacet                  XREF[12]:    00536d12(W), 00536d86(R), 00536ef7(R), 00536f35(R),
//                                                                                     005371b9(R), 005371d7(R), 005371fd(R), 0053721b(R),
//                                                                                     0053728f(R), 00537309(R), 005373e7(R), 00537463(R)
//              int               Stack[-0x100   screen_row                XREF[12]:    00536c61(W), 00536cae(R), 00536cde(R), 00536d29(R),
//                                                                                     00536e5c(R), 00536ea7(R), 00536fce(R), 00537009(R),
//                                                                                     00537371(R), 005373e3(R), 005374a8(R), 005374bd(W)
//              int               Stack[-0x104   map_row                   XREF[14]:    00536d43(W), 00536d58(W), 00536d76(W), 00536e26(R),
//                                                                                     00536e82(R), 00536fba(R), 00536ff4(R), 0053703e(R),
//                                                                                     0053734b(R), 0053736c(R), 005373df(R), 0053741a(R),
//                                                                                     0053743b(R), 0053744c(R)
//              uchar             Stack[-0x108   MapVis                    XREF[4]:     00536c1b(W), 0053709d(R), 005371ad(W), 00537295(W)
//              DClipInfo_Node    Stack[-0x10c   LDI                       XREF[10]:    00536dca(W), 00536ddd(R), 00537313(W), 00537317(R),
//                                                                                     0053733f(W), 0053737b(R), 005373b5(W), 005373b9(R),
//                                                                                     005373db(W), 005373f0(R)
//              int               Stack[-0x110   y                         XREF[0,1]:   00537600(W)
//              uchar             Stack[-0x111   ResetALLCyclic
//                               ?view_function_terrain@RGE_View@@IAEJEUtagRECT@@@Z           XREF[1]:     draw_view:0053554e(c)
//                               RGE_View::view_function_terrain
//                              view.cpp:3026 (10)
//         00536b40     SUB        ESP,0x110
//         00536b46     PUSH       EBX
//         00536b47     PUSH       EBP
//         00536b48     MOV        EBP,this
//                              view.cpp:3134 (17)
//         00536b4a     XOR        EBX,EBX
//         00536b4c     PUSH       ESI
//         00536b4d     PUSH       EDI
//         00536b4e     CMP        dword ptr [EBP + 0x358],EBX
//         00536b54     JLE        LAB_00536b5b
//         00536b56     CALL       RGE_View::update_display_selected_objects        void update_display_selected_objects(RGE_View
//                               LAB_00536b5b                                                 XREF[1]:     00536b54(j)
//                              view.cpp:3169 (7)
//         00536b5b     MOVSX      EAX,word ptr [EBP + 0x12a]
//                              view.cpp:3172 (40)
//         00536b62     MOVSX      EDX,word ptr [EBP + 0x118]
//         00536b69     MOVSX      this,word ptr [EBP + 0x12c]
//         00536b70     MOV        dword ptr [ESP + col_num],EAX
//         00536b74     MOV        dword ptr [ESP + black_tile_mask_num],this
//         00536b78     MOVSX      EAX,word ptr [EBP + 0x116]
//         00536b7f     ADD        EAX,0x5
//         00536b82     LEA        ESI,[EDX + EDX*0x1 + 0xc]
//         00536b86     MOV        dword ptr [ESP + TileFoggedMask],EAX
//                              view.cpp:3177 (16)
//         00536b8a     MOV        EAX,dword ptr [EBP + 0x104]
//         00536b90     MOV        dword ptr [ESP + theObj],ESI
//         00536b97     MOV        this,dword ptr [EAX + 0x8]
//                              view.cpp:3178 (3)
//         00536b9a     MOV        EDX,dword ptr [EAX + 0xc]
//                              view.cpp:3193 (17)
//         00536b9d     MOV        AL,byte ptr [ESP + param_1]
//         00536ba4     MOV        dword ptr [ESP + map_col],this
//         00536ba8     MOV        byte ptr [EBP + 0x140],AL
//                              view.cpp:3197 (21)
//         00536bae     MOV        EAX,dword ptr [EBP + 0x104]
//         00536bb4     XOR        this,this
//         00536bb6     MOV        dword ptr [ESP + black_draw],EDX
//         00536bba     CMP        word ptr [EAX + 0x8d90],BX
//         00536bc1     JLE        LAB_00536be5
//                              view.cpp:3169 (2)
//         00536bc3     XOR        EDX,EDX
//                               LAB_00536bc5                                                 XREF[1]:     00536be3(j)
//                              view.cpp:3198 (32)
//         00536bc5     MOV        byte ptr [EDX + EAX*0x1 + 0xd1],0x0
//         00536bcd     MOV        EAX,dword ptr [EBP + 0x104]
//         00536bd3     INC        this
//         00536bd4     ADD        EDX,0x198
//         00536bda     MOVSX      EDI,word ptr [EAX + 0x8d90]
//         00536be1     CMP        this,EDI
//         00536be3     JL         LAB_00536bc5
//                               LAB_00536be5                                                 XREF[1]:     00536bc1(j)
//                              view.cpp:3202 (12)
//         00536be5     MOV        EAX,dword ptr [EBP + 0x100]
//         00536beb     MOV        this,dword ptr [EAX + 0xd0]
//                              view.cpp:3203 (6)
//         00536bf1     MOV        EDX,dword ptr [EAX + 0xd4]
//                              view.cpp:3207 (15)
//         00536bf7     MOV        EAX,dword ptr [EBP + 0x338]
//         00536bfd     MOV        dword ptr [ESP + local_a8],this
//         00536c01     MOV        [SDI_List],EAX                                   = 00000000
//                              view.cpp:3208 (15)
//         00536c06     MOV        this,dword ptr [EBP + 0x338]
//         00536c0c     MOV        dword ptr [ESP + fog_draw_data],EDX
//         00536c10     CALL       DClipInfo_List::ReclaimAllNodes                  void ReclaimAllNodes(DClipInfo_List * this)
//                              view.cpp:3225 (47)
//         00536c15     MOV        this,dword ptr [EBP + 0x100]
//         00536c1b     MOV        dword ptr [ESP + MapVis],0xffffffff
//         00536c23     CMP        dword ptr [ECX + this->_padding_],EBX
//         00536c26     JZ         LAB_00536c3c
//         00536c28     MOV        EDX,dword ptr [EBP + 0x104]
//         00536c2e     MOV        dword ptr [ESP + TileVisibleMask],EBX
//         00536c32     MOV        AL,byte ptr [EDX + 0x8db8]
//         00536c38     TEST       AL,AL
//         00536c3a     JZ         LAB_00536c44
//                               LAB_00536c3c                                                 XREF[1]:     00536c26(j)
//         00536c3c     MOV        dword ptr [ESP + TileVisibleMask],0x1
//                               LAB_00536c44                                                 XREF[1]:     00536c3a(j)
//                              view.cpp:3227 (12)
//         00536c44     CMP        ESI,EBX
//         00536c46     MOV        dword ptr [ESP + text_id],EBX
//         00536c4a     JLE        LAB_005374f6
//                               LAB_00536c50                                                 XREF[1]:     005374f0(j)
//                              view.cpp:3232 (4)
//         00536c50     MOV        EDI,dword ptr [ESP + col_num]
//                              view.cpp:3233 (4)
//         00536c54     MOV        EAX,dword ptr [ESP + black_tile_mask_num]
//                              view.cpp:3237 (18)
//         00536c58     MOV        this,EBX
//         00536c5a     MOV        dword ptr [ESP + Map_Height],EDI
//         00536c5e     AND        this,0x3
//         00536c61     MOV        dword ptr [ESP + screen_row],EAX
//         00536c65     CMP        this,0x3
//         00536c68     JNZ        LAB_00536c79
//                              view.cpp:3239 (15)
//         00536c6a     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00536c70     TEST       this,this
//         00536c72     JZ         LAB_00536c79
//         00536c74     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_00536c79                                                 XREF[2]:     00536c68(j), 00536c72(j)
//                              view.cpp:3242 (14)
//         00536c79     MOV        ESI,EBX
//         00536c7b     AND        ESI,0x1
//         00536c7e     CMP        ESI,0x1
//         00536c81     MOV        dword ptr [ESP + rows_2_scan],ESI
//         00536c85     JNZ        LAB_00536c9a
//                              view.cpp:3244 (19)
//         00536c87     MOV        EAX,dword ptr [EBP + 0x2d8]
//         00536c8d     TEST       EAX,EAX
//         00536c8f     JZ         LAB_00536c9a
//         00536c91     PUSH       0x0
//         00536c93     MOV        this,EBP
//         00536c95     CALL       RGE_View::ProcessQueuedBlit                      void ProcessQueuedBlit(RGE_View * this, int p
//                               LAB_00536c9a                                                 XREF[2]:     00536c85(j), 00536c8f(j)
//                              view.cpp:3247 (20)
//         00536c9a     MOV        EAX,dword ptr [ESP + TileFoggedMask]
//         00536c9e     MOV        dword ptr [ESP + normal_draw_data],0x0
//         00536ca6     TEST       EAX,EAX
//         00536ca8     JLE        LAB_005374d3
//                               LAB_00536cae                                                 XREF[1]:     005374c5(j)
//                              view.cpp:3255 (20)
//         00536cae     MOV        EAX,dword ptr [ESP + screen_row]
//         00536cb2     TEST       EAX,EAX
//         00536cb4     JL         LAB_005374a8
//         00536cba     TEST       EDI,EDI
//         00536cbc     JL         LAB_005374a8
//                              view.cpp:3256 (22)
//         00536cc2     MOV        EDX,dword ptr [ESP + black_draw]
//         00536cc6     CMP        EAX,EDX
//         00536cc8     JGE        LAB_005374a0
//         00536cce     CMP        EDI,dword ptr [ESP + map_col]
//         00536cd2     JGE        LAB_005374a0
//                              view.cpp:3260 (22)
//         00536cd8     MOV        EAX,dword ptr [EBP + 0x104]
//         00536cde     MOV        ESI,dword ptr [ESP + screen_row]
//         00536ce2     LEA        EDX,[EDI + EDI*0x2]
//         00536ce5     MOV        this,dword ptr [EAX + 0x8d8c]
//         00536ceb     MOV        this,dword ptr [this->_padding_ + ESI*0x4]
//                              view.cpp:3262 (13)
//         00536cee     MOVSX      EBX,word ptr [this->_padding_ + EDX*0x8]
//         00536cf2     LEA        ESI,[this->_padding_ + EDX*0x8]
//         00536cf5     MOV        EDX,dword ptr [EBP + 0x130]
//                              view.cpp:3263 (14)
//         00536cfb     MOV        this,dword ptr [EBP + 0x134]
//         00536d01     SUB        EBX,EDX
//         00536d03     MOVSX      EDX,word ptr [ESI + 0x2]
//         00536d07     SUB        EDX,this
//                              view.cpp:3264 (17)
//         00536d09     MOVSX      this,word ptr [EBP + 0x108]
//         00536d10     ADD        this,EBX
//         00536d12     MOV        dword ptr [ESP + newFacet],EDX
//         00536d16     MOV        dword ptr [ESP + fog_draw],this
//                              view.cpp:3265 (15)
//         00536d1a     XOR        this,this
//         00536d1c     MOV        this,byte ptr [ESI + 0x4]
//         00536d1f     LEA        this,[ECX + ECX*0x2]
//         00536d22     MOVSX      this,word ptr [EAX + this->_padding_*0x2 + 0x1a]
//         00536d27     ADD        this,EDX
//                              view.cpp:3269 (15)
//         00536d29     MOV        EDX,dword ptr [ESP + screen_row]
//         00536d2d     MOV        dword ptr [ESP + tile_mask_num],this
//         00536d31     MOV        this,dword ptr [EDX*0x4 + unified_map_offsets]   = 00000000
//                              view.cpp:3271 (11)
//         00536d38     MOV        EDX,dword ptr [ESP + fog_draw_data]
//         00536d3c     MOV        this,dword ptr [this->_padding_ + EDI*0x4]
//         00536d3f     TEST       this,EDX
//         00536d41     JZ         LAB_00536d4a
//                              view.cpp:3273 (5)
//         00536d43     MOV        byte ptr [ESP + map_row],0xf
//                              view.cpp:3275 (16)
//         00536d48     JMP        LAB_00536d7a
//                               LAB_00536d4a                                                 XREF[1]:     00536d41(j)
//         00536d4a     TEST       dword ptr [ESP + local_a8],this
//         00536d4e     JNZ        LAB_00536d66
//         00536d50     MOV        this,dword ptr [ESP + TileVisibleMask]
//         00536d54     TEST       this,this
//         00536d56     JNZ        LAB_00536d66
//                              view.cpp:3284 (5)
//         00536d58     MOV        byte ptr [ESP + map_row],0x0
//                              view.cpp:3285 (4)
//         00536d5d     MOV        byte ptr [ESI + 0x7],0x0
//                              view.cpp:4250 (5)
//         00536d61     JMP        LAB_0053739b
//                               LAB_00536d66                                                 XREF[2]:     00536d4e(j), 00536d56(j)
//                              view.cpp:3277 (16)
//         00536d66     MOV        this,byte ptr [EAX + 0x8db9]
//         00536d6c     NEG        this
//         00536d6e     SBB        this,this
//         00536d70     AND        this,0x71
//         00536d73     ADD        this,0xf
//                              view.cpp:3284 (4)
//         00536d76     MOV        byte ptr [ESP + map_row],this
//                               LAB_00536d7a                                                 XREF[1]:     00536d48(j)
//                              view.cpp:3292 (66)
//         00536d7a     CMP        EBX,dword ptr [EBP + 0x94]
//         00536d80     JG         LAB_0053739b
//         00536d86     MOV        EDX,dword ptr [ESP + newFacet]
//         00536d8a     MOV        this,dword ptr [EBP + 0x98]
//         00536d90     CMP        EDX,this
//         00536d92     JG         LAB_0053739b
//         00536d98     MOV        this,dword ptr [ESP + fog_draw]
//         00536d9c     MOV        EDX,dword ptr [EBP + 0x8c]
//         00536da2     CMP        this,EDX
//         00536da4     JLE        LAB_0053739b
//         00536daa     MOV        EDX,dword ptr [ESP + tile_mask_num]
//         00536dae     MOV        this,dword ptr [EBP + 0x90]
//         00536db4     CMP        EDX,this
//         00536db6     JLE        LAB_0053739b
//                              view.cpp:3296 (3)
//         00536dbc     MOV        this,byte ptr [ESI + 0x5]
//                              view.cpp:3298 (30)
//         00536dbf     MOV        EDX,dword ptr [EBP + 0xf8]
//         00536dc5     AND        this,0x1f
//         00536dc8     TEST       EDX,EDX
//         00536dca     MOV        byte ptr [ESP + LDI],this
//         00536dce     JZ         LAB_00536e03
//         00536dd0     MOVZX      this,this
//         00536dd4     CMP        this,word ptr [EAX + 0x8d90]
//         00536ddb     JGE        LAB_00536e03
//                              view.cpp:3299 (38)
//         00536ddd     MOV        EDX,dword ptr [ESP + LDI]
//         00536de1     AND        EDX,0xff
//         00536de7     MOV        this,EDX
//         00536de9     SHL        this,0x4
//         00536dec     ADD        this,EDX
//         00536dee     LEA        EDX,[ECX + ECX*0x2]
//         00536df1     MOV        this,byte ptr [EAX + EDX*0x8 + 0xd1]
//         00536df8     INC        this
//         00536dfa     LEA        EAX,[EAX + EDX*0x8 + 0xd1]
//         00536e01     MOV        byte ptr [EAX],this
//                               LAB_00536e03                                                 XREF[2]:     00536dce(j), 00536ddb(j)
//                              view.cpp:3304 (3)
//         00536e03     OR         EAX,0xffffffff
//                              view.cpp:3306 (10)
//         00536e06     XOR        this,this
//         00536e08     MOV        dword ptr [ESP + black_draw_data],EAX
//         00536e0c     MOV        dword ptr [ESP + screen_row2],EAX
//                              view.cpp:3311 (22)
//         00536e10     MOV        AL,byte ptr [EBP + 0x142]
//         00536e16     MOV        dword ptr [ESP + Map_Width],this
//         00536e1a     TEST       AL,AL
//         00536e1c     MOV        dword ptr [ESP + Full_Visibility],this
//         00536e20     JZ         LAB_00536f71
//                              view.cpp:3315 (15)
//         00536e26     MOV        AL,byte ptr [ESP + map_row]
//         00536e2a     MOV        DL,byte ptr [ESI + 0x7]
//         00536e2d     CMP        DL,AL
//         00536e2f     JNZ        LAB_00536f71
//                              view.cpp:3319 (4)
//         00536e35     CMP        AL,0xf
//         00536e37     JNZ        LAB_00536e82
//                              view.cpp:3321 (16)
//         00536e39     MOV        EAX,dword ptr [EBP + 0x104]
//         00536e3f     MOV        DL,byte ptr [EAX + 0x8db9]
//         00536e45     TEST       DL,DL
//         00536e47     JNZ        LAB_00536e4f
//                              view.cpp:3323 (4)
//         00536e49     MOV        dword ptr [ESP + black_draw_data],this
//                              view.cpp:3325 (2)
//         00536e4d     JMP        LAB_00536e6f
//                               LAB_00536e4f                                                 XREF[1]:     00536e47(j)
//                              view.cpp:3326 (32)
//         00536e4f     MOV        this,dword ptr [ESP + fog_draw_data]
//         00536e53     MOV        EDX,dword ptr [ESP + black_draw]
//         00536e57     MOV        EAX,dword ptr [ESP + map_col]
//         00536e5b     PUSH       this
//         00536e5c     MOV        this,dword ptr [ESP + screen_row]
//         00536e60     PUSH       EDX
//         00536e61     PUSH       EAX
//         00536e62     PUSH       this
//         00536e63     PUSH       EDI
//         00536e64     MOV        this,EBP
//         00536e66     CALL       RGE_View::get_tile_mask_num                      int get_tile_mask_num(RGE_View * this, int pa
//         00536e6b     MOV        dword ptr [ESP + black_draw_data],EAX
//                               LAB_00536e6f                                                 XREF[1]:     00536e4d(j)
//                              view.cpp:3328 (19)
//         00536e6f     MOV        EAX,dword ptr [ESP + black_draw_data]
//         00536e73     XOR        EDX,EDX
//         00536e75     MOV        DL,byte ptr [ESI + 0x8]
//         00536e78     CMP        EDX,EAX
//         00536e7a     JNZ        LAB_00536f71
//         00536e80     XOR        this,this
//                               LAB_00536e82                                                 XREF[1]:     00536e37(j)
//                              view.cpp:3333 (12)
//         00536e82     MOV        AL,byte ptr [ESP + map_row]
//         00536e86     CMP        AL,0xf
//         00536e88     JZ         LAB_00536e8e
//         00536e8a     CMP        AL,0x80
//         00536e8c     JNZ        LAB_00536ecd
//                               LAB_00536e8e                                                 XREF[1]:     00536e88(j)
//                              view.cpp:3335 (6)
//         00536e8e     CMP        dword ptr [ESP + TileVisibleMask],this
//         00536e92     JZ         LAB_00536e9a
//                              view.cpp:3337 (4)
//         00536e94     MOV        dword ptr [ESP + screen_row2],this
//                              view.cpp:3339 (2)
//         00536e98     JMP        LAB_00536eba
//                               LAB_00536e9a                                                 XREF[1]:     00536e92(j)
//                              view.cpp:3341 (32)
//         00536e9a     MOV        EAX,dword ptr [ESP + local_a8]
//         00536e9e     MOV        this,dword ptr [ESP + black_draw]
//         00536ea2     MOV        EDX,dword ptr [ESP + map_col]
//         00536ea6     PUSH       EAX
//         00536ea7     MOV        EAX,dword ptr [ESP + screen_row]
//         00536eab     PUSH       this
//         00536eac     PUSH       EDX
//         00536ead     PUSH       EAX
//         00536eae     PUSH       EDI
//         00536eaf     MOV        this,EBP
//         00536eb1     CALL       RGE_View::get_tile_mask_num                      int get_tile_mask_num(RGE_View * this, int pa
//         00536eb6     MOV        dword ptr [ESP + screen_row2],EAX
//                               LAB_00536eba                                                 XREF[1]:     00536e98(j)
//                              view.cpp:3344 (19)
//         00536eba     MOV        EAX,dword ptr [ESP + screen_row2]
//         00536ebe     XOR        this,this
//         00536ec0     MOV        this,byte ptr [ESI + 0xb]
//         00536ec3     CMP        this,EAX
//         00536ec5     JNZ        LAB_00536f71
//         00536ecb     XOR        this,this
//                               LAB_00536ecd                                                 XREF[1]:     00536e8c(j)
//                              view.cpp:3349 (12)
//         00536ecd     CMP        dword ptr [EBP + 0x2a0],this
//         00536ed3     JZ         LAB_0053739b
//                              view.cpp:3353 (8)
//         00536ed9     CMP        dword ptr [EBP + 0x2a4],this
//         00536edf     JZ         LAB_00536f1f
//                              view.cpp:3356 (62)
//         00536ee1     CMP        EBX,dword ptr [EBP + 0x2c0]
//         00536ee7     JG         LAB_00536f1b
//         00536ee9     MOV        EDX,dword ptr [ESP + fog_draw]
//         00536eed     MOV        EAX,dword ptr [EBP + 0x2b8]
//         00536ef3     CMP        EDX,EAX
//         00536ef5     JL         LAB_00536f1b
//         00536ef7     MOV        EAX,dword ptr [ESP + newFacet]
//         00536efb     MOV        EDX,dword ptr [EBP + 0x2c4]
//         00536f01     CMP        EAX,EDX
//         00536f03     JG         LAB_00536f1b
//         00536f05     MOV        EDX,dword ptr [ESP + tile_mask_num]
//         00536f09     MOV        EAX,dword ptr [EBP + 0x2bc]
//         00536f0f     CMP        EDX,EAX
//         00536f11     MOV        dword ptr [ESP + Full_Visibility],0x1
//         00536f19     JGE        LAB_00536f1f
//                               LAB_00536f1b                                                 XREF[3]:     00536ee7(j), 00536ef5(j),
//                                                                                                         00536f03(j)
//         00536f1b     MOV        dword ptr [ESP + Full_Visibility],this
//                               LAB_00536f1f                                                 XREF[2]:     00536edf(j), 00536f19(j)
//                              view.cpp:3360 (50)
//         00536f1f     CMP        EBX,dword ptr [EBP + 0x2b0]
//         00536f25     JG         LAB_00536f5b
//         00536f27     MOV        EAX,dword ptr [ESP + fog_draw]
//         00536f2b     MOV        EDX,dword ptr [EBP + 0x2a8]
//         00536f31     CMP        EAX,EDX
//         00536f33     JL         LAB_00536f5b
//         00536f35     MOV        EDX,dword ptr [ESP + newFacet]
//         00536f39     MOV        EAX,dword ptr [EBP + 0x2b4]
//         00536f3f     CMP        EDX,EAX
//         00536f41     JG         LAB_00536f5b
//         00536f43     MOV        EAX,dword ptr [ESP + tile_mask_num]
//         00536f47     MOV        EDX,dword ptr [EBP + 0x2ac]
//         00536f4d     CMP        EAX,EDX
//         00536f4f     JL         LAB_00536f5b
//                              view.cpp:3363 (8)
//         00536f51     MOV        dword ptr [ESP + Map_Width],0x1
//                              view.cpp:4250 (2)
//         00536f59     JMP        LAB_00536f71
//                               LAB_00536f5b                                                 XREF[4]:     00536f25(j), 00536f33(j),
//                                                                                                         00536f41(j), 00536f4f(j)
//                              view.cpp:3367 (10)
//         00536f5b     CMP        dword ptr [ESP + Full_Visibility],this
//         00536f5f     JZ         LAB_0053739b
//                              view.cpp:3370 (4)
//         00536f65     MOV        dword ptr [ESP + Full_Visibility],this
//                              view.cpp:3371 (8)
//         00536f69     MOV        dword ptr [ESP + Map_Width],0x2
//                              Symbol Ref: No symbol: draw_this_tile
//                               LAB_00536f71                                                 XREF[5]:     00536e20(j), 00536e2f(j),
//                                                                                                         00536e7a(j), 00536ec5(j),
//                                                                                                         00536f59(j)
//                              view.cpp:3386 (6)
//         00536f71     MOV        this,dword ptr [EBP + 0x184]
//                              view.cpp:3387 (20)
//         00536f77     MOV        EDX,dword ptr [EBP + 0x188]
//         00536f7d     XOR        EAX,EAX
//         00536f7f     MOV        AL,byte ptr [ESI + 0x4]
//         00536f82     SHL        EAX,0x2
//         00536f85     MOV        EDI,dword ptr [this->_padding_ + EAX*0x1]
//         00536f88     MOV        EAX,dword ptr [EDX + EAX*0x1]
//                              view.cpp:3391 (20)
//         00536f8b     MOV        this,dword ptr [EBP + 0x104]
//         00536f91     MOV        dword ptr [ESP + rect2],EAX
//         00536f95     MOV        AL,byte ptr [this->_padding_ + 0x8db9]
//         00536f9b     TEST       AL,AL
//         00536f9d     JNZ        LAB_00536fa7
//                              view.cpp:3394 (10)
//         00536f9f     XOR        EAX,EAX
//         00536fa1     MOV        dword ptr [ESP + black_draw_data],EAX
//         00536fa5     JMP        LAB_00536fa9
//                               LAB_00536fa7                                                 XREF[1]:     00536f9d(j)
//         00536fa7     XOR        EAX,EAX
//                               LAB_00536fa9                                                 XREF[1]:     00536fa5(j)
//                              view.cpp:3398 (6)
//         00536fa9     CMP        dword ptr [ESP + TileVisibleMask],EAX
//         00536fad     JZ         LAB_00536fb3
//                              view.cpp:3400 (4)
//         00536faf     MOV        dword ptr [ESP + screen_row2],EAX
//                               LAB_00536fb3                                                 XREF[1]:     00536fad(j)
//                              view.cpp:3405 (7)
//         00536fb3     CMP        dword ptr [ESP + black_draw_data],-0x1
//         00536fb8     JNZ        LAB_00536fed
//                              view.cpp:3407 (7)
//         00536fba     CMP        byte ptr [ESP + map_row],0xf
//         00536fbf     JNZ        LAB_00536fe9
//                              view.cpp:3408 (36)
//         00536fc1     MOV        EDX,dword ptr [ESP + fog_draw_data]
//         00536fc5     MOV        EAX,dword ptr [ESP + black_draw]
//         00536fc9     MOV        this,dword ptr [ESP + map_col]
//         00536fcd     PUSH       EDX
//         00536fce     MOV        EDX,dword ptr [ESP + screen_row]
//         00536fd2     PUSH       EAX
//         00536fd3     MOV        EAX,dword ptr [ESP + Map_Height]
//         00536fd7     PUSH       this
//         00536fd8     PUSH       EDX
//         00536fd9     PUSH       EAX
//         00536fda     MOV        this,EBP
//         00536fdc     CALL       RGE_View::get_tile_mask_num                      int get_tile_mask_num(RGE_View * this, int pa
//         00536fe1     MOV        dword ptr [ESP + black_draw_data],EAX
//                              view.cpp:3409 (4)
//         00536fe5     XOR        EAX,EAX
//         00536fe7     JMP        LAB_00536fed
//                               LAB_00536fe9                                                 XREF[1]:     00536fbf(j)
//                              view.cpp:3410 (4)
//         00536fe9     MOV        dword ptr [ESP + black_draw_data],EAX
//                               LAB_00536fed                                                 XREF[2]:     00536fb8(j), 00536fe7(j)
//                              view.cpp:3415 (7)
//         00536fed     CMP        dword ptr [ESP + screen_row2],-0x1
//         00536ff2     JNZ        LAB_00537020
//                              view.cpp:3417 (8)
//         00536ff4     MOV        this,byte ptr [ESP + map_row]
//         00536ff8     TEST       this,this
//         00536ffa     JZ         LAB_0053701c
//                              view.cpp:3418 (32)
//         00536ffc     MOV        this,dword ptr [ESP + local_a8]
//         00537000     MOV        EDX,dword ptr [ESP + black_draw]
//         00537004     MOV        EAX,dword ptr [ESP + map_col]
//         00537008     PUSH       this
//         00537009     MOV        this,dword ptr [ESP + screen_row]
//         0053700d     PUSH       EDX
//         0053700e     MOV        EDX,dword ptr [ESP + Map_Height]
//         00537012     PUSH       EAX
//         00537013     PUSH       this
//         00537014     PUSH       EDX
//         00537015     MOV        this,EBP
//         00537017     CALL       RGE_View::get_tile_mask_num                      int get_tile_mask_num(RGE_View * this, int pa
//                               LAB_0053701c                                                 XREF[1]:     00536ffa(j)
//                              view.cpp:3420 (4)
//         0053701c     MOV        dword ptr [ESP + screen_row2],EAX
//                               LAB_00537020                                                 XREF[1]:     00536ff2(j)
//                              view.cpp:3425 (4)
//         00537020     MOV        EAX,dword ptr [ESP + black_draw_data]
//                              view.cpp:3427 (26)
//         00537024     MOV        EDX,dword ptr [ESP + rect2]
//         00537028     MOV        this,dword ptr [EDI + EAX*0x8]
//         0053702b     MOV        EAX,dword ptr [EDI + EAX*0x8 + 0x4]
//         0053702f     MOV        dword ptr [ESP + cols_2_scan],this
//         00537033     MOV        this,dword ptr [ESP + screen_row2]
//         00537037     MOV        dword ptr [ESP + start_map_x],EAX
//         0053703b     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//                              view.cpp:3429 (13)
//         0053703e     MOV        DL,byte ptr [ESP + map_row]
//         00537042     CMP        DL,0x80
//         00537045     MOV        dword ptr [ESP + fog_draw],this
//         00537049     JNZ        LAB_00537063
//                              view.cpp:3433 (22)
//         0053704b     MOV        EDX,dword ptr [EDI]
//         0053704d     MOV        dword ptr [ESP + clip_to],0x1
//         00537055     MOV        dword ptr [ESP + tile_mask_num],0x0
//         0053705d     MOV        dword ptr [ESP + start_map_x],EDX
//                              view.cpp:3435 (2)
//         00537061     JMP        LAB_0053707d
//                               LAB_00537063                                                 XREF[1]:     00537049(j)
//                              view.cpp:3437 (15)
//         00537063     MOV        EDI,dword ptr [ESP + cols_2_scan]
//         00537067     XOR        EDX,EDX
//         00537069     TEST       EDI,EDI
//         0053706b     SETNZ      DL
//         0053706e     MOV        dword ptr [ESP + tile_mask_num],EDX
//                              view.cpp:3438 (11)
//         00537072     XOR        EDX,EDX
//         00537074     TEST       EAX,EAX
//         00537076     SETNZ      DL
//         00537079     MOV        dword ptr [ESP + clip_to],EDX
//                               LAB_0053707d                                                 XREF[1]:     00537061(j)
//                              view.cpp:3441 (28)
//         0053707d     MOV        EAX,dword ptr [ESP + screen_row2]
//         00537081     TEST       EAX,EAX
//         00537083     JLE        LAB_00537091
//         00537085     TEST       this,this
//         00537087     MOV        dword ptr [ESP + rect2],0x1
//         0053708f     JNZ        LAB_00537099
//                               LAB_00537091                                                 XREF[1]:     00537083(j)
//         00537091     MOV        dword ptr [ESP + rect2],0x0
//                               LAB_00537099                                                 XREF[1]:     0053708f(j)
//                              view.cpp:3445 (16)
//         00537099     MOV        EAX,dword ptr [ESP + Map_Width]
//         0053709d     MOV        this,dword ptr [ESP + MapVis]
//         005370a1     CMP        EAX,this
//         005370a3     JZ         LAB_005371b1
//                              view.cpp:3447 (4)
//         005370a9     TEST       EAX,EAX
//         005370ab     JNZ        LAB_005370ff
//                              view.cpp:3449 (39)
//         005370ad     MOV        EAX,dword ptr [EBP + 0x98]
//         005370b3     MOV        this,dword ptr [EBP + 0x94]
//         005370b9     MOV        EDX,dword ptr [EBP + 0x90]
//         005370bf     PUSH       EAX
//         005370c0     MOV        EAX,dword ptr [EBP + 0x8c]
//         005370c6     PUSH       this
//         005370c7     MOV        this,dword ptr [EBP + 0x178]
//         005370cd     PUSH       EDX
//         005370ce     PUSH       EAX
//         005370cf     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                              view.cpp:3450 (43)
//         005370d4     MOV        this,dword ptr [EBP + 0x98]
//         005370da     MOV        EDX,dword ptr [EBP + 0x94]
//         005370e0     MOV        EAX,dword ptr [EBP + 0x90]
//         005370e6     PUSH       this
//         005370e7     MOV        this,dword ptr [EBP + 0x8c]
//         005370ed     PUSH       EDX
//         005370ee     PUSH       EAX
//         005370ef     PUSH       this
//         005370f0     MOV        this,dword ptr [EBP + 0x17c]
//         005370f6     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//         005370fb     MOV        EAX,dword ptr [ESP + Map_Width]
//                               LAB_005370ff                                                 XREF[1]:     005370ab(j)
//                              view.cpp:3452 (5)
//         005370ff     CMP        EAX,0x1
//         00537102     JNZ        LAB_00537156
//                              view.cpp:3454 (39)
//         00537104     MOV        EDX,dword ptr [EBP + 0x2b4]
//         0053710a     MOV        EAX,dword ptr [EBP + 0x2b0]
//         00537110     MOV        this,dword ptr [EBP + 0x2ac]
//         00537116     PUSH       EDX
//         00537117     MOV        EDX,dword ptr [EBP + 0x2a8]
//         0053711d     PUSH       EAX
//         0053711e     PUSH       this
//         0053711f     MOV        this,dword ptr [EBP + 0x178]
//         00537125     PUSH       EDX
//         00537126     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                              view.cpp:3455 (43)
//         0053712b     MOV        EAX,dword ptr [EBP + 0x2b4]
//         00537131     MOV        this,dword ptr [EBP + 0x2b0]
//         00537137     MOV        EDX,dword ptr [EBP + 0x2ac]
//         0053713d     PUSH       EAX
//         0053713e     MOV        EAX,dword ptr [EBP + 0x2a8]
//         00537144     PUSH       this
//         00537145     MOV        this,dword ptr [EBP + 0x17c]
//         0053714b     PUSH       EDX
//         0053714c     PUSH       EAX
//         0053714d     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//         00537152     MOV        EAX,dword ptr [ESP + Map_Width]
//                               LAB_00537156                                                 XREF[1]:     00537102(j)
//                              view.cpp:3457 (5)
//         00537156     CMP        EAX,0x2
//         00537159     JNZ        LAB_005371ad
//                              view.cpp:3459 (39)
//         0053715b     MOV        this,dword ptr [EBP + 0x2c4]
//         00537161     MOV        EDX,dword ptr [EBP + 0x2c0]
//         00537167     MOV        EAX,dword ptr [EBP + 0x2bc]
//         0053716d     PUSH       this
//         0053716e     MOV        this,dword ptr [EBP + 0x2b8]
//         00537174     PUSH       EDX
//         00537175     PUSH       EAX
//         00537176     PUSH       this
//         00537177     MOV        this,dword ptr [EBP + 0x178]
//         0053717d     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                              view.cpp:3460 (43)
//         00537182     MOV        EDX,dword ptr [EBP + 0x2c4]
//         00537188     MOV        EAX,dword ptr [EBP + 0x2c0]
//         0053718e     MOV        this,dword ptr [EBP + 0x2bc]
//         00537194     PUSH       EDX
//         00537195     MOV        EDX,dword ptr [EBP + 0x2b8]
//         0053719b     PUSH       EAX
//         0053719c     PUSH       this
//         0053719d     MOV        this,dword ptr [EBP + 0x17c]
//         005371a3     PUSH       EDX
//         005371a4     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//         005371a9     MOV        EAX,dword ptr [ESP + Map_Width]
//                               LAB_005371ad                                                 XREF[1]:     00537159(j)
//                              view.cpp:3463 (4)
//         005371ad     MOV        dword ptr [ESP + MapVis],EAX
//                               LAB_005371b1                                                 XREF[1]:     005370a3(j)
//                              view.cpp:3468 (30)
//         005371b1     MOV        EAX,dword ptr [ESP + tile_mask_num]
//         005371b5     TEST       EAX,EAX
//         005371b7     JZ         LAB_005371cf
//         005371b9     MOV        EAX,dword ptr [ESP + newFacet]
//         005371bd     MOV        this,dword ptr [ESP + cols_2_scan]
//         005371c1     PUSH       EAX
//         005371c2     PUSH       EBX
//         005371c3     PUSH       this
//         005371c4     MOV        this,dword ptr [EBP + 0x178]
//         005371ca     CALL       TSpan_List_Manager::AddMiniList                  void AddMiniList(TSpan_List_Manager * this, V
//                               LAB_005371cf                                                 XREF[1]:     005371b7(j)
//                              view.cpp:3470 (30)
//         005371cf     MOV        EAX,dword ptr [ESP + clip_to]
//         005371d3     TEST       EAX,EAX
//         005371d5     JZ         LAB_005371ed
//         005371d7     MOV        EDX,dword ptr [ESP + newFacet]
//         005371db     MOV        EAX,dword ptr [ESP + start_map_x]
//         005371df     MOV        this,dword ptr [EBP + 0x17c]
//         005371e5     PUSH       EDX
//         005371e6     PUSH       EBX
//         005371e7     PUSH       EAX
//         005371e8     CALL       TSpan_List_Manager::AddMiniList                  void AddMiniList(TSpan_List_Manager * this, V
//                               LAB_005371ed                                                 XREF[1]:     005371d5(j)
//                              view.cpp:3474 (8)
//         005371ed     MOV        EAX,dword ptr [ESP + rect2]
//         005371f1     TEST       EAX,EAX
//         005371f3     JZ         LAB_00537231
//                              view.cpp:3476 (30)
//         005371f5     MOV        EAX,dword ptr [ESP + tile_mask_num]
//         005371f9     TEST       EAX,EAX
//         005371fb     JZ         LAB_00537213
//         005371fd     MOV        this,dword ptr [ESP + newFacet]
//         00537201     MOV        EDX,dword ptr [ESP + fog_draw]
//         00537205     PUSH       this
//         00537206     MOV        this,dword ptr [EBP + 0x178]
//         0053720c     PUSH       EBX
//         0053720d     PUSH       EDX
//         0053720e     CALL       TSpan_List_Manager::SubtractMiniList             void SubtractMiniList(TSpan_List_Manager * th
//                               LAB_00537213                                                 XREF[1]:     005371fb(j)
//                              view.cpp:3477 (30)
//         00537213     MOV        EAX,dword ptr [ESP + clip_to]
//         00537217     TEST       EAX,EAX
//         00537219     JZ         LAB_00537231
//         0053721b     MOV        EAX,dword ptr [ESP + newFacet]
//         0053721f     MOV        this,dword ptr [ESP + fog_draw]
//         00537223     PUSH       EAX
//         00537224     PUSH       EBX
//         00537225     PUSH       this
//         00537226     MOV        this,dword ptr [EBP + 0x17c]
//         0053722c     CALL       TSpan_List_Manager::SubtractMiniList             void SubtractMiniList(TSpan_List_Manager * th
//                               LAB_00537231                                                 XREF[2]:     005371f3(j), 00537219(j)
//                              view.cpp:3482 (12)
//         00537231     MOV        EAX,dword ptr [ESP + Full_Visibility]
//         00537235     TEST       EAX,EAX
//         00537237     JZ         LAB_00537309
//                              view.cpp:3484 (39)
//         0053723d     MOV        EDX,dword ptr [EBP + 0x2c4]
//         00537243     MOV        EAX,dword ptr [EBP + 0x2c0]
//         00537249     MOV        this,dword ptr [EBP + 0x2bc]
//         0053724f     PUSH       EDX
//         00537250     MOV        EDX,dword ptr [EBP + 0x2b8]
//         00537256     PUSH       EAX
//         00537257     PUSH       this
//         00537258     MOV        this,dword ptr [EBP + 0x178]
//         0053725e     PUSH       EDX
//         0053725f     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                              view.cpp:3485 (39)
//         00537264     MOV        EAX,dword ptr [EBP + 0x2c4]
//         0053726a     MOV        this,dword ptr [EBP + 0x2c0]
//         00537270     MOV        EDX,dword ptr [EBP + 0x2bc]
//         00537276     PUSH       EAX
//         00537277     MOV        EAX,dword ptr [EBP + 0x2b8]
//         0053727d     PUSH       this
//         0053727e     MOV        this,dword ptr [EBP + 0x17c]
//         00537284     PUSH       EDX
//         00537285     PUSH       EAX
//         00537286     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                              view.cpp:3489 (38)
//         0053728b     MOV        EAX,dword ptr [ESP + tile_mask_num]
//         0053728f     MOV        EDI,dword ptr [ESP + newFacet]
//         00537293     TEST       EAX,EAX
//         00537295     MOV        dword ptr [ESP + MapVis],0x2
//         0053729d     JZ         LAB_005372b1
//         0053729f     MOV        this,dword ptr [ESP + cols_2_scan]
//         005372a3     PUSH       EDI
//         005372a4     PUSH       EBX
//         005372a5     PUSH       this
//         005372a6     MOV        this,dword ptr [EBP + 0x178]
//         005372ac     CALL       TSpan_List_Manager::AddMiniList                  void AddMiniList(TSpan_List_Manager * this, V
//                               LAB_005372b1                                                 XREF[1]:     0053729d(j)
//                              view.cpp:3490 (26)
//         005372b1     MOV        EAX,dword ptr [ESP + clip_to]
//         005372b5     TEST       EAX,EAX
//         005372b7     JZ         LAB_005372cb
//         005372b9     MOV        EDX,dword ptr [ESP + start_map_x]
//         005372bd     MOV        this,dword ptr [EBP + 0x17c]
//         005372c3     PUSH       EDI
//         005372c4     PUSH       EBX
//         005372c5     PUSH       EDX
//         005372c6     CALL       TSpan_List_Manager::AddMiniList                  void AddMiniList(TSpan_List_Manager * this, V
//                               LAB_005372cb                                                 XREF[1]:     005372b7(j)
//                              view.cpp:3494 (8)
//         005372cb     MOV        EAX,dword ptr [ESP + rect2]
//         005372cf     TEST       EAX,EAX
//         005372d1     JZ         LAB_0053730d
//                              view.cpp:3496 (26)
//         005372d3     MOV        EAX,dword ptr [ESP + tile_mask_num]
//         005372d7     TEST       EAX,EAX
//         005372d9     JZ         LAB_005372ed
//         005372db     MOV        EAX,dword ptr [ESP + fog_draw]
//         005372df     MOV        this,dword ptr [EBP + 0x178]
//         005372e5     PUSH       EDI
//         005372e6     PUSH       EBX
//         005372e7     PUSH       EAX
//         005372e8     CALL       TSpan_List_Manager::SubtractMiniList             void SubtractMiniList(TSpan_List_Manager * th
//                               LAB_005372ed                                                 XREF[1]:     005372d9(j)
//                              view.cpp:3497 (32)
//         005372ed     MOV        EAX,dword ptr [ESP + clip_to]
//         005372f1     TEST       EAX,EAX
//         005372f3     JZ         LAB_0053730d
//         005372f5     MOV        this,dword ptr [ESP + fog_draw]
//         005372f9     PUSH       EDI
//         005372fa     PUSH       EBX
//         005372fb     PUSH       this
//         005372fc     MOV        this,dword ptr [EBP + 0x17c]
//         00537302     CALL       TSpan_List_Manager::SubtractMiniList             void SubtractMiniList(TSpan_List_Manager * th
//         00537307     JMP        LAB_0053730d
//                               LAB_00537309                                                 XREF[1]:     00537237(j)
//         00537309     MOV        EDI,dword ptr [ESP + newFacet]
//                               LAB_0053730d                                                 XREF[3]:     005372d1(j), 005372f3(j),
//                                                                                                         00537307(j)
//                              view.cpp:3503 (10)
//         0053730d     MOV        DL,byte ptr [ESI + 0x5]
//         00537310     AND        DL,0x1f
//         00537313     MOV        byte ptr [ESP + LDI],DL
//                              view.cpp:3504 (34)
//         00537317     MOV        this,dword ptr [ESP + LDI]
//         0053731b     AND        this,0xff
//         00537321     MOV        EAX,this
//         00537323     SHL        EAX,0x4
//         00537326     ADD        EAX,this
//         00537328     MOV        this,dword ptr [EBP + 0x104]
//         0053732e     LEA        EAX,[EAX + EAX*0x2]
//         00537331     MOV        AX,word ptr [ECX + EAX*0x8 + this->sel_col1]
//                              view.cpp:3506 (10)
//         00537339     CMP        AX,0xffff
//         0053733d     JZ         LAB_00537343
//         0053733f     MOV        byte ptr [ESP + LDI],AL
//                               LAB_00537343                                                 XREF[1]:     0053733d(j)
//                              view.cpp:3512 (15)
//         00537343     MOV        this,byte ptr [ESP + screen_row2]
//         00537347     MOV        DL,byte ptr [ESP + black_draw_data]
//         0053734b     MOV        AL,byte ptr [ESP + map_row]
//         0053734f     MOV        byte ptr [ESI + 0xb],this
//                              view.cpp:3514 (6)
//         00537352     MOV        this,byte ptr [ESI + 0xa]
//         00537355     MOV        byte ptr [ESI + 0x8],DL
//                              view.cpp:3518 (52)
//         00537358     MOV        EDX,dword ptr [ESP + clip_to]
//         0053735c     AND        this,0xbf
//         0053735f     MOV        byte ptr [ESI + 0x7],AL
//         00537362     MOV        byte ptr [ESI + 0x9],AL
//         00537365     MOV        EAX,dword ptr [ESP + tile_mask_num]
//         00537369     MOV        byte ptr [ESI + 0xa],this
//         0053736c     MOV        this,dword ptr [ESP + map_row]
//         00537370     PUSH       EDX
//         00537371     MOV        EDX,dword ptr [ESP + screen_row]
//         00537375     PUSH       EAX
//         00537376     MOV        EAX,dword ptr [ESP + Map_Height]
//         0053737a     PUSH       this
//         0053737b     MOV        this,dword ptr [ESP + LDI]
//         0053737f     PUSH       EDX
//         00537380     PUSH       EAX
//         00537381     PUSH       EDI
//         00537382     PUSH       EBX
//         00537383     PUSH       this
//         00537384     PUSH       ESI
//         00537385     MOV        this,EBP
//         00537387     CALL       RGE_View::draw_tile                              int draw_tile(RGE_View * this, RGE_Tile * par
//                              view.cpp:3519 (5)
//         0053738c     MOV        EAX,[tiles_drawn]
//                              view.cpp:4250 (10)
//         00537391     MOV        EDI,dword ptr [ESP + Map_Height]
//         00537395     INC        EAX
//         00537396     MOV        [tiles_drawn],EAX
//                              Symbol Ref: No symbol: TileOffScreen
//                               LAB_0053739b                                                 XREF[7]:     00536d61(j), 00536d80(j),
//                                                                                                         00536d92(j), 00536da4(j),
//                                                                                                         00536db6(j), 00536ed3(j),
//                                                                                                         00536f5f(j)
//                              view.cpp:3526 (4)
//         0053739b     TEST       ESI,ESI
//         0053739d     JZ         LAB_00537405
//                              view.cpp:3528 (11)
//         0053739f     MOV        DL,byte ptr [ESI + 0xa]
//         005373a2     AND        DL,0x40
//         005373a5     CMP        DL,0x40
//         005373a8     JNZ        LAB_00537405
//                              view.cpp:3530 (3)
//         005373aa     MOV        AL,byte ptr [ESI + 0x5]
//                              view.cpp:3531 (40)
//         005373ad     MOV        EDX,dword ptr [EBP + 0x104]
//         005373b3     AND        AL,0x1f
//         005373b5     MOV        byte ptr [ESP + LDI],AL
//         005373b9     MOV        this,dword ptr [ESP + LDI]
//         005373bd     AND        this,0xff
//         005373c3     MOV        EAX,this
//         005373c5     SHL        EAX,0x4
//         005373c8     ADD        EAX,this
//         005373ca     LEA        this,[EAX + EAX*0x2]
//         005373cd     MOV        AX,word ptr [EDX + this->_padding_*0x8 + 0x144]
//                              view.cpp:3532 (10)
//         005373d5     CMP        AX,0xffff
//         005373d9     JZ         LAB_005373df
//         005373db     MOV        byte ptr [ESP + LDI],AL
//                               LAB_005373df                                                 XREF[1]:     005373d9(j)
//                              view.cpp:3534 (34)
//         005373df     MOV        EAX,dword ptr [ESP + map_row]
//         005373e3     MOV        this,dword ptr [ESP + screen_row]
//         005373e7     MOV        EDX,dword ptr [ESP + newFacet]
//         005373eb     PUSH       0x1
//         005373ed     PUSH       0x1
//         005373ef     PUSH       EAX
//         005373f0     MOV        EAX,dword ptr [ESP + LDI]
//         005373f4     PUSH       this
//         005373f5     PUSH       EDI
//         005373f6     PUSH       EDX
//         005373f7     PUSH       EBX
//         005373f8     PUSH       EAX
//         005373f9     PUSH       ESI
//         005373fa     MOV        this,EBP
//         005373fc     CALL       RGE_View::draw_tile                              int draw_tile(RGE_View * this, RGE_Tile * par
//                              view.cpp:3536 (4)
//         00537401     AND        byte ptr [ESI + 0xa],0xbf
//                               LAB_00537405                                                 XREF[2]:     0053739d(j), 005373a8(j)
//                              view.cpp:3543 (13)
//         00537405     MOV        EAX,[view_debug_Objects]
//         0053740a     TEST       EAX,EAX
//         0053740c     JNZ        LAB_005374a8
//                              view.cpp:3546 (8)
//         00537412     TEST       ESI,ESI
//         00537414     JZ         LAB_005374a8
//                              view.cpp:3549 (33)
//         0053741a     MOV        AL,byte ptr [ESP + map_row]
//         0053741e     MOV        dword ptr [SDI_Capture_Info],0x1
//         00537428     TEST       AL,AL
//         0053742a     JNZ        LAB_0053743b
//         0053742c     MOV        this,dword ptr [EBP + 0x338]
//         00537432     PUSH       0x5
//         00537434     PUSH       0x0
//         00537436     CALL       DClipInfo_List::SetCaptureLevel                  void SetCaptureLevel(DClipInfo_List * this, i
//                               LAB_0053743b                                                 XREF[1]:     0053742a(j)
//                              view.cpp:3550 (17)
//         0053743b     CMP        byte ptr [ESP + map_row],0xf
//         00537440     JZ         LAB_0053744c
//         00537442     MOV        dword ptr [fog_next_shape],0x1
//                               LAB_0053744c                                                 XREF[1]:     00537440(j)
//                              view.cpp:3552 (54)
//         0053744c     MOV        AL,byte ptr [ESP + map_row]
//         00537450     MOV        DL,byte ptr [ESI + 0x5]
//         00537453     XOR        this,this
//         00537455     CMP        AL,0x80
//         00537457     SETZ       this
//         0053745a     SHR        DL,0x5
//         0053745d     XOR        AX,AX
//         00537460     PUSH       this
//         00537461     MOV        AL,DL
//         00537463     MOV        EDX,dword ptr [ESP + newFacet]
//         00537467     IMUL       AX,word ptr [EBP + 0x10e]
//         0053746f     MOV        this,dword ptr [EBP + 0x324]
//         00537475     ADD        EAX,EDX
//         00537477     PUSH       EAX
//         00537478     PUSH       EBX
//         00537479     PUSH       this
//         0053747a     LEA        this,[ESI + 0xc]
//         0053747d     CALL       RGE_Object_List::draw                            void draw(RGE_Object_List * this, TDrawArea *
//                              view.cpp:3554 (16)
//         00537482     MOV        this,dword ptr [EBP + 0x338]
//         00537488     XOR        ESI,ESI
//         0053748a     PUSH       0x28
//         0053748c     PUSH       ESI
//         0053748d     CALL       DClipInfo_List::SetCaptureLevel                  void SetCaptureLevel(DClipInfo_List * this, i
//                              view.cpp:3555 (6)
//         00537492     MOV        dword ptr [fog_next_shape],ESI
//                              view.cpp:3556 (8)
//         00537498     MOV        dword ptr [SDI_Capture_Info],ESI
//         0053749e     JMP        LAB_005374a8
//                               LAB_005374a0                                                 XREF[2]:     00536cc8(j), 00536cd2(j)
//                              view.cpp:3256 (8)
//         005374a0     MOV        EDX,dword ptr [ESP + TileFoggedMask]
//         005374a4     MOV        dword ptr [ESP + normal_draw_data],EDX
//                              Symbol Ref: No symbol: SkipCol
//                               LAB_005374a8                                                 XREF[5]:     00536cb4(j), 00536cbc(j),
//                                                                                                         0053740c(j), 00537414(j),
//                                                                                                         0053749e(j)
//                              view.cpp:3563 (43)
//         005374a8     MOV        ESI,dword ptr [ESP + screen_row]
//         005374ac     MOV        EAX,dword ptr [ESP + normal_draw_data]
//         005374b0     MOV        this,dword ptr [ESP + TileFoggedMask]
//         005374b4     INC        EDI
//         005374b5     INC        ESI
//         005374b6     INC        EAX
//         005374b7     CMP        EAX,this
//         005374b9     MOV        dword ptr [ESP + Map_Height],EDI
//         005374bd     MOV        dword ptr [ESP + screen_row],ESI
//         005374c1     MOV        dword ptr [ESP + normal_draw_data],EAX
//         005374c5     JL         LAB_00536cae
//         005374cb     MOV        ESI,dword ptr [ESP + rows_2_scan]
//         005374cf     MOV        EBX,dword ptr [ESP + text_id]
//                               LAB_005374d3                                                 XREF[1]:     00536ca8(j)
//                              view.cpp:3566 (5)
//         005374d3     CMP        ESI,0x1
//         005374d6     JZ         LAB_005374de
//                              view.cpp:3567 (4)
//         005374d8     DEC        dword ptr [ESP + col_num]
//                              view.cpp:3568 (2)
//         005374dc     JMP        LAB_005374e2
//                               LAB_005374de                                                 XREF[1]:     005374d6(j)
//                              view.cpp:3569 (24)
//         005374de     INC        dword ptr [ESP + black_tile_mask_num]
//                               LAB_005374e2                                                 XREF[1]:     005374dc(j)
//         005374e2     MOV        EAX,dword ptr [ESP + theObj]
//         005374e9     INC        EBX
//         005374ea     CMP        EBX,EAX
//         005374ec     MOV        dword ptr [ESP + text_id],EBX
//         005374f0     JL         LAB_00536c50
//                               LAB_005374f6                                                 XREF[1]:     00536c4a(j)
//                              view.cpp:3583 (10)
//         005374f6     MOV        EAX,dword ptr [EBP + 0x2d8]
//         005374fc     TEST       EAX,EAX
//         005374fe     JZ         LAB_00537513
//                               LAB_00537500                                                 XREF[1]:     00537511(j)
//                              view.cpp:3587 (19)
//         00537500     PUSH       0x1
//         00537502     MOV        this,EBP
//         00537504     CALL       RGE_View::ProcessQueuedBlit                      void ProcessQueuedBlit(RGE_View * this, int p
//         00537509     MOV        EAX,dword ptr [EBP + 0x2d8]
//         0053750f     TEST       EAX,EAX
//         00537511     JNZ        LAB_00537500
//                               LAB_00537513                                                 XREF[1]:     005374fe(j)
//                              view.cpp:3599 (15)
//         00537513     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00537519     TEST       this,this
//         0053751b     JZ         LAB_00537522
//         0053751d     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//                               LAB_00537522                                                 XREF[1]:     0053751b(j)
//                              view.cpp:3603 (21)
//         00537522     MOV        EAX,dword ptr [ESP + param_2.left]
//         00537529     MOV        this,dword ptr [EBP + 0x8c]
//         0053752f     ADD        this,EAX
//         00537531     MOV        dword ptr [EBP + 0x8c],this
//                              view.cpp:3604 (21)
//         00537537     MOV        this,dword ptr [ESP + param_2.top]
//         0053753e     MOV        EBX,dword ptr [EBP + 0x90]
//         00537544     ADD        EBX,this
//         00537546     MOV        dword ptr [EBP + 0x90],EBX
//                              view.cpp:3605 (14)
//         0053754c     MOV        EDI,dword ptr [EBP + 0x94]
//         00537552     ADD        EDI,EAX
//         00537554     MOV        dword ptr [EBP + 0x94],EDI
//                              view.cpp:3606 (14)
//         0053755a     MOV        ESI,dword ptr [EBP + 0x98]
//         00537560     ADD        ESI,this
//         00537562     MOV        dword ptr [EBP + 0x98],ESI
//                              view.cpp:3608 (10)
//         00537568     MOV        dword ptr [SDI_Capture_Info],0x1
//                              view.cpp:3612 (9)
//         00537572     CMP        byte ptr [EBP + 0x168],0x2
//         00537579     JNZ        LAB_005375bf
//                              view.cpp:3617 (68)
//         0053757b     MOV        EDX,dword ptr [EBP + 0x170]
//         00537581     PUSH       0x0
//         00537583     PUSH       0xff
//         00537588     PUSH       0x28
//         0053758a     PUSH       0x0
//         0053758c     PUSH       0x0
//         0053758e     PUSH       0x0
//         00537590     SUB        EDX,this
//         00537592     PUSH       0x0
//         00537594     PUSH       EDX
//         00537595     MOV        EDX,dword ptr [EBP + 0x16c]
//         0053759b     SUB        EDX,EAX
//         0053759d     PUSH       EDX
//         0053759e     MOV        EDX,dword ptr [EBP + 0xc8]
//         005375a4     SUB        EDX,this
//         005375a6     MOV        this,dword ptr [EBP + 0xc4]
//         005375ac     SUB        this,EAX
//         005375ae     PUSH       EDX
//         005375af     PUSH       this
//         005375b0     MOV        this,dword ptr [EBP + 0x338]
//         005375b6     PUSH       0x14
//         005375b8     PUSH       0x4
//         005375ba     CALL       DClipInfo_List::AddGDINode                       DClipInfo_Node * AddGDINode(DClipInfo_List *
//                               LAB_005375bf                                                 XREF[1]:     00537579(j)
//                              view.cpp:3622 (25)
//         005375bf     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         005375c5     MOV        EAX,dword ptr [EDX + 0x1b4]
//         005375cb     CMP        EAX,0x1
//         005375ce     JZ         LAB_005375da
//         005375d0     CMP        EAX,0x6
//         005375d3     JLE        LAB_005375e1
//         005375d5     CMP        EAX,0x8
//                              view.cpp:3633 (2)
//         005375d8     JG         LAB_005375e1
//                               LAB_005375da                                                 XREF[1]:     005375ce(j)
//                              view.cpp:3629 (7)
//         005375da     MOV        this,EBP
//         005375dc     CALL       RGE_View::draw_object_outline                    void draw_object_outline(RGE_View * this)
//                               LAB_005375e1                                                 XREF[2]:     005375d3(j), 005375d8(j)
//                              view.cpp:3636 (14)
//         005375e1     MOV        EAX,[rge_base_game]                              = 00000000
//         005375e6     CMP        dword ptr [EAX + 0x1b4],0x15
//         005375ed     JNZ        LAB_005375fa
//                              view.cpp:3637 (11)
//         005375ef     MOV        EDX,dword ptr [EBP]
//         005375f2     MOV        this,EBP
//         005375f4     CALL       dword ptr [EDX + 0xf8]
//                               LAB_005375fa                                                 XREF[1]:     005375ed(j)
//                              view.cpp:3644 (19)
//         005375fa     MOV        EAX,dword ptr [EBP + 0x350]
//         00537600     MOV        byte ptr [ESP + y+0x3],0x0
//         00537605     TEST       EAX,EAX
//         00537607     JZ         LAB_0053772c
//                              view.cpp:3646 (15)
//         0053760d     PUSH       0xe3e
//         00537612     PUSH       s_C:\msdev\work\age1_x1\view.cpp                 = "C:\\msdev\\work\\age1_x1\\view.cpp"
//         00537617     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              view.cpp:3648 (9)
//         0053761c     MOV        ESI,dword ptr [EBP + 0x350]
//         00537622     ADD        ESP,0x8
//                              view.cpp:3651 (12)
//         00537625     TEST       ESI,ESI
//         00537627     MOV        dword ptr [ESP + 0x28],EAX
//         0053762b     JZ         LAB_0053772c
//                               LAB_00537631                                                 XREF[1]:     00537726(j)
//                              view.cpp:3654 (13)
//         00537631     MOV        EAX,dword ptr [ESI + 0x8]
//         00537634     XOR        BL,BL
//         00537636     TEST       EAX,EAX
//         00537638     JZ         LAB_005376e9
//                              view.cpp:3656 (7)
//         0053763e     MOV        this,dword ptr [ESI + 0x24]
//         00537641     TEST       this,this
//         00537643     JNZ        LAB_0053764e
//                              view.cpp:3658 (7)
//         00537645     MOV        EAX,dword ptr [ESP + 0x28]
//         00537649     MOV        dword ptr [ESI + 0x24],EAX
//                              view.cpp:3660 (2)
//         0053764c     JMP        LAB_005376a2
//                               LAB_0053764e                                                 XREF[1]:     00537643(j)
//                              view.cpp:3662 (13)
//         0053764e     MOV        EAX,dword ptr [ESI + 0x20]
//         00537651     CMP        EAX,0x1
//         00537654     JZ         LAB_0053765b
//         00537656     CMP        EAX,0x2
//         00537659     JNZ        LAB_005376a2
//                               LAB_0053765b                                                 XREF[1]:     00537654(j)
//                              view.cpp:3664 (4)
//         0053765b     MOV        EDI,dword ptr [ESP + 0x28]
//                              view.cpp:3665 (9)
//         0053765f     MOV        EAX,dword ptr [ESI + 0x28]
//         00537662     SUB        EDI,this
//         00537664     CMP        EDI,EAX
//         00537666     JC         LAB_005376a2
//                               LAB_00537668                                                 XREF[1]:     005376a0(j)
//                              view.cpp:3667 (3)
//         00537668     MOV        EDX,dword ptr [ESI + 0xc]
//                              view.cpp:3668 (17)
//         0053766b     MOV        this,dword ptr [ESI + 0x8]
//         0053766e     INC        EDX
//         0053766f     MOV        dword ptr [ESI + 0xc],EDX
//         00537672     CALL       TShape::shape_count                              long shape_count(TShape * this)
//         00537677     CMP        dword ptr [ESI + 0xc],EAX
//         0053767a     JL         LAB_00537691
//                              view.cpp:3673 (15)
//         0053767c     MOV        EAX,dword ptr [ESI + 0x20]
//         0053767f     MOV        dword ptr [ESI + 0xc],0x0
//         00537686     CMP        EAX,0x2
//         00537689     JNZ        LAB_00537691
//                              view.cpp:3675 (2)
//         0053768b     MOV        BL,0x1
//                              view.cpp:3676 (4)
//         0053768d     MOV        byte ptr [ESP + 0x13],BL
//                               LAB_00537691                                                 XREF[2]:     0053767a(j), 00537689(j)
//                              view.cpp:3679 (3)
//         00537691     MOV        EAX,dword ptr [ESI + 0x28]
//                              view.cpp:3680 (14)
//         00537694     MOV        this,dword ptr [ESI + 0x24]
//         00537697     SUB        EDI,EAX
//         00537699     ADD        this,EAX
//         0053769b     CMP        EDI,EAX
//         0053769d     MOV        dword ptr [ESI + 0x24],this
//         005376a0     JNC        LAB_00537668
//                               LAB_005376a2                                                 XREF[3]:     0053764c(j), 00537659(j),
//                                                                                                         00537666(j)
//                              view.cpp:3687 (4)
//         005376a2     TEST       BL,BL
//         005376a4     JNZ        LAB_005376ed
//                              view.cpp:3689 (3)
//         005376a6     MOV        this,dword ptr [ESI + 0x1c]
//                              view.cpp:3690 (16)
//         005376a9     MOV        dword ptr [SDI_Object_ID],0xffffffff
//         005376b3     MOV        dword ptr [SDI_Draw_Level],this
//                              view.cpp:3692 (48)
//         005376b9     MOV        EDX,dword ptr [ESI + 0x2c]
//         005376bc     MOV        AL,byte ptr [ESI + 0x18]
//         005376bf     MOV        this,dword ptr [ESI + 0xc]
//         005376c2     PUSH       EDX
//         005376c3     MOV        EDX,dword ptr [ESI + 0x14]
//         005376c6     PUSH       EAX
//         005376c7     MOV        EAX,dword ptr [EBP + 0x134]
//         005376cd     SUB        EDX,EAX
//         005376cf     MOV        EAX,dword ptr [ESI + 0x10]
//         005376d2     PUSH       this
//         005376d3     MOV        this,dword ptr [EBP + 0x20]
//         005376d6     PUSH       EDX
//         005376d7     MOV        EDX,dword ptr [EBP + 0x130]
//         005376dd     SUB        EAX,EDX
//         005376df     PUSH       EAX
//         005376e0     PUSH       this
//         005376e1     MOV        this,dword ptr [ESI + 0x8]
//         005376e4     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                               LAB_005376e9                                                 XREF[1]:     00537638(j)
//                              view.cpp:3697 (4)
//         005376e9     TEST       BL,BL
//         005376eb     JZ         LAB_00537722
//                               LAB_005376ed                                                 XREF[1]:     005376a4(j)
//                              view.cpp:3699 (11)
//         005376ed     MOV        EAX,dword ptr [ESI + 0x4]
//         005376f0     TEST       EAX,EAX
//         005376f2     JZ         LAB_005376f8
//         005376f4     MOV        EDX,dword ptr [ESI]
//         005376f6     MOV        dword ptr [EAX],EDX
//                               LAB_005376f8                                                 XREF[1]:     005376f2(j)
//                              view.cpp:3700 (12)
//         005376f8     MOV        EAX,dword ptr [ESI]
//         005376fa     TEST       EAX,EAX
//         005376fc     JZ         LAB_00537704
//         005376fe     MOV        this,dword ptr [ESI + 0x4]
//         00537701     MOV        dword ptr [EAX + 0x4],this
//                               LAB_00537704                                                 XREF[1]:     005376fc(j)
//                              view.cpp:3702 (15)
//         00537704     MOV        EAX,dword ptr [ESI + 0x4]
//         00537707     TEST       EAX,EAX
//         00537709     JNZ        LAB_00537713
//         0053770b     MOV        EDX,dword ptr [ESI]
//         0053770d     MOV        dword ptr [EBP + 0x350],EDX
//                               LAB_00537713                                                 XREF[1]:     00537709(j)
//                              view.cpp:3704 (2)
//         00537713     MOV        EDI,dword ptr [ESI]
//                              view.cpp:3705 (9)
//         00537715     PUSH       ESI
//         00537716     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0053771b     ADD        ESP,0x4
//                              view.cpp:3706 (2)
//         0053771e     MOV        ESI,EDI
//                              view.cpp:3708 (2)
//         00537720     JMP        LAB_00537724
//                               LAB_00537722                                                 XREF[1]:     005376eb(j)
//                              view.cpp:3710 (2)
//         00537722     MOV        ESI,dword ptr [ESI]
//                               LAB_00537724                                                 XREF[1]:     00537720(j)
//                              view.cpp:3651 (8)
//         00537724     TEST       ESI,ESI
//         00537726     JNZ        LAB_00537631
//                               LAB_0053772c                                                 XREF[2]:     00537607(j), 0053762b(j)
//                              view.cpp:3719 (15)
//         0053772c     MOV        AL,byte ptr [ESP + 0x13]
//         00537730     TEST       AL,AL
//         00537732     JZ         LAB_0053773b
//         00537734     MOV        this,EBP
//         00537736     CALL       RGE_View::reset_cyclic_overlay_sprites           void reset_cyclic_overlay_sprites(RGE_View *
//                               LAB_0053773b                                                 XREF[1]:     00537732(j)
//                              view.cpp:3725 (29)
//         0053773b     MOV        EAX,dword ptr [ESP + 0x128]
//         00537742     XOR        EDI,EDI
//         00537744     MOV        dword ptr [SDI_Capture_Info],EDI
//         0053774a     MOV        this,dword ptr [EBP + 0x8c]
//         00537750     SUB        this,EAX
//         00537752     MOV        dword ptr [EBP + 0x8c],this
//                              view.cpp:3726 (21)
//         00537758     MOV        this,dword ptr [ESP + 0x12c]
//         0053775f     MOV        EBX,dword ptr [EBP + 0x90]
//         00537765     SUB        EBX,this
//         00537767     MOV        dword ptr [EBP + 0x90],EBX
//                              view.cpp:3727 (14)
//         0053776d     MOV        ESI,dword ptr [EBP + 0x94]
//         00537773     SUB        ESI,EAX
//         00537775     MOV        dword ptr [EBP + 0x94],ESI
//                              view.cpp:3728 (14)
//         0053777b     MOV        EDX,dword ptr [EBP + 0x98]
//         00537781     SUB        EDX,this
//         00537783     MOV        dword ptr [EBP + 0x98],EDX
//                              view.cpp:3736 (11)
//         00537789     MOV        EAX,dword ptr [EBP + 0x338]
//         0053778f     CMP        dword ptr [EAX + 0x68],EDI
//         00537792     JLE        LAB_005377dd
//                               LAB_00537794                                                 XREF[1]:     005377db(j)
//                              view.cpp:3738 (6)
//         00537794     MOV        EAX,dword ptr [EAX + 0x58]
//         00537797     MOV        EAX,dword ptr [EAX + EDI*0x4]
//                              view.cpp:3739 (4)
//         0053779a     TEST       EAX,EAX
//         0053779c     JZ         LAB_005377d1
//                               LAB_0053779e                                                 XREF[1]:     005377cf(j)
//                              view.cpp:3742 (22)
//         0053779e     MOV        EDX,dword ptr [EBP + 0x338]
//         005377a4     MOV        this,dword ptr [EAX + 0x10]
//         005377a7     SHL        this,0x2
//         005377aa     MOV        ESI,dword ptr [EDX + 0x60]
//         005377ad     MOV        ESI,dword ptr [ESI + this->_padding_*0x1]
//         005377b0     TEST       ESI,ESI
//         005377b2     JNZ        LAB_005377bc
//                              view.cpp:3744 (6)
//         005377b4     MOV        EDX,dword ptr [EDX + 0x5c]
//         005377b7     MOV        dword ptr [EDX + this->_padding_*0x1],EAX
//                              view.cpp:3747 (2)
//         005377ba     JMP        LAB_005377bf
//                               LAB_005377bc                                                 XREF[1]:     005377b2(j)
//                              view.cpp:3749 (3)
//         005377bc     MOV        dword ptr [ESI + 0x4],EAX
//                               LAB_005377bf                                                 XREF[1]:     005377ba(j)
//                              view.cpp:3750 (12)
//         005377bf     MOV        EDX,dword ptr [EBP + 0x338]
//         005377c5     MOV        EDX,dword ptr [EDX + 0x60]
//         005377c8     MOV        dword ptr [EDX + this->_padding_*0x1],EAX
//                              view.cpp:3752 (6)
//         005377cb     MOV        EAX,dword ptr [EAX]
//         005377cd     TEST       EAX,EAX
//         005377cf     JNZ        LAB_0053779e
//                               LAB_005377d1                                                 XREF[1]:     0053779c(j)
//                              view.cpp:3736 (12)
//         005377d1     MOV        EAX,dword ptr [EBP + 0x338]
//         005377d7     INC        EDI
//         005377d8     CMP        EDI,dword ptr [EAX + 0x68]
//         005377db     JL         LAB_00537794
//                               LAB_005377dd                                                 XREF[1]:     00537792(j)
//                              view.cpp:3761 (22)
//         005377dd     MOV        EAX,dword ptr [ESP + 0x18]
//         005377e1     XOR        EBX,EBX
//         005377e3     CMP        EAX,EBX
//         005377e5     MOV        dword ptr [Clip_draw],EBX
//         005377eb     MOV        dword ptr [Clip_remove],EBX
//         005377f1     JZ         LAB_00537841
//                              view.cpp:3763 (39)
//         005377f3     MOV        EAX,dword ptr [EBP + 0x98]
//         005377f9     MOV        this,dword ptr [EBP + 0x94]
//         005377ff     MOV        EDX,dword ptr [EBP + 0x90]
//         00537805     PUSH       EAX
//         00537806     MOV        EAX,dword ptr [EBP + 0x8c]
//         0053780c     PUSH       this
//         0053780d     MOV        this,dword ptr [EBP + 0x178]
//         00537813     PUSH       EDX
//         00537814     PUSH       EAX
//         00537815     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                              view.cpp:3764 (39)
//         0053781a     MOV        this,dword ptr [EBP + 0x98]
//         00537820     MOV        EDX,dword ptr [EBP + 0x94]
//         00537826     MOV        EAX,dword ptr [EBP + 0x90]
//         0053782c     PUSH       this
//         0053782d     MOV        this,dword ptr [EBP + 0x8c]
//         00537833     PUSH       EDX
//         00537834     PUSH       EAX
//         00537835     PUSH       this
//         00537836     MOV        this,dword ptr [EBP + 0x17c]
//         0053783c     CALL       TSpan_List_Manager::SetSpanRegions               void SetSpanRegions(TSpan_List_Manager * this
//                               LAB_00537841                                                 XREF[2]:     005377f1(j), 00537949(j)
//                              view.cpp:3777 (12)
//         00537841     MOV        EDX,dword ptr [EBP + 0x338]
//         00537847     MOV        EAX,dword ptr [EDX + 0x5c]
//         0053784a     MOV        ESI,dword ptr [EAX + EBX*0x1]
//                              view.cpp:3778 (8)
//         0053784d     TEST       ESI,ESI
//         0053784f     JZ         LAB_00537943
//                               LAB_00537855                                                 XREF[1]:     0053793d(j)
//                              view.cpp:3783 (11)
//         00537855     MOV        EAX,dword ptr [ESI + 0x2c]
//         00537858     TEST       EAX,EAX
//         0053785a     JNZ        LAB_00537938
//                              view.cpp:3791 (48)
//         00537860     MOV        EAX,dword ptr [EBP + 0x178]
//         00537866     MOV        this,dword ptr [EAX + 0x64]
//         00537869     MOV        EDX,dword ptr [EAX + 0x5c]
//         0053786c     PUSH       this
//         0053786d     MOV        this,dword ptr [EAX + 0x60]
//         00537870     PUSH       EDX
//         00537871     MOV        EDX,dword ptr [EAX + 0x58]
//         00537874     PUSH       this
//         00537875     MOV        this,dword ptr [EAX + 0x40]
//         00537878     PUSH       EDX
//         00537879     MOV        EDX,dword ptr [EAX + 0x3c]
//         0053787c     MOV        EAX,dword ptr [EBP + 0x324]
//         00537882     PUSH       this
//         00537883     PUSH       EDX
//         00537884     MOV        this,dword ptr [EAX + 0xc0]
//         0053788a     PUSH       this
//         0053788b     CALL       _ASMSet_Surface_Info                             undefined _ASMSet_Surface_Info()
//                              view.cpp:3793 (12)
//         00537890     MOV        EDX,dword ptr [ESI + 0x28]
//         00537893     ADD        ESP,0x1c
//         00537896     PUSH       EDX
//         00537897     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//                              view.cpp:3795 (12)
//         0053789c     MOV        EAX,dword ptr [ESI + 0x24]
//         0053789f     ADD        ESP,0x4
//         005378a2     PUSH       EAX
//         005378a3     CALL       _ASMSet_Xlate_Table                              undefined _ASMSet_Xlate_Table()
//                              view.cpp:3797 (3)
//         005378a8     MOV        EDI,dword ptr [ESI + 0xc]
//                              view.cpp:3804 (45)
//         005378ab     MOV        this,dword ptr [ESI + 0x1c]
//         005378ae     ADD        ESP,0x4
//         005378b1     AND        this,0xfe
//         005378b7     MOV        EDX,dword ptr [EDI + 0x4]
//         005378ba     MOV        EAX,dword ptr [EDI]
//         005378bc     PUSH       this
//         005378bd     MOV        this,dword ptr [EDI + 0x14]
//         005378c0     PUSH       EDX
//         005378c1     MOV        EDX,dword ptr [EDI + 0x10]
//         005378c4     PUSH       EAX
//         005378c5     MOV        EAX,dword ptr [ESI + 0x18]
//         005378c8     PUSH       this
//         005378c9     MOV        this,dword ptr [ESI + 0x14]
//         005378cc     PUSH       EDX
//         005378cd     MOV        EDX,dword ptr [ESI + 0x20]
//         005378d0     PUSH       EAX
//         005378d1     PUSH       this
//         005378d2     PUSH       EDX
//         005378d3     CALL       _ASMDraw_Sprite                                  undefined _ASMDraw_Sprite()
//                              view.cpp:3813 (51)
//         005378d8     MOV        EAX,dword ptr [EBP + 0x17c]
//         005378de     ADD        ESP,0x20
//         005378e1     MOV        this,dword ptr [EAX + 0x64]
//         005378e4     MOV        EDX,dword ptr [EAX + 0x5c]
//         005378e7     PUSH       this
//         005378e8     MOV        this,dword ptr [EAX + 0x60]
//         005378eb     PUSH       EDX
//         005378ec     MOV        EDX,dword ptr [EAX + 0x58]
//         005378ef     PUSH       this
//         005378f0     MOV        this,dword ptr [EAX + 0x40]
//         005378f3     PUSH       EDX
//         005378f4     MOV        EDX,dword ptr [EAX + 0x3c]
//         005378f7     MOV        EAX,dword ptr [EBP + 0x324]
//         005378fd     PUSH       this
//         005378fe     PUSH       EDX
//         005378ff     MOV        this,dword ptr [EAX + 0xc0]
//         00537905     PUSH       this
//         00537906     CALL       _ASMSet_Surface_Info                             undefined _ASMSet_Surface_Info()
//                              view.cpp:3820 (45)
//         0053790b     MOV        EDX,dword ptr [ESI + 0x1c]
//         0053790e     MOV        EAX,dword ptr [EDI + 0x4]
//         00537911     MOV        this,dword ptr [EDI]
//         00537913     ADD        ESP,0x1c
//         00537916     OR         EDX,0x1
//         00537919     PUSH       EDX
//         0053791a     MOV        EDX,dword ptr [EDI + 0x14]
//         0053791d     PUSH       EAX
//         0053791e     MOV        EAX,dword ptr [EDI + 0x10]
//         00537921     PUSH       this
//         00537922     MOV        this,dword ptr [ESI + 0x18]
//         00537925     PUSH       EDX
//         00537926     MOV        EDX,dword ptr [ESI + 0x14]
//         00537929     PUSH       EAX
//         0053792a     MOV        EAX,dword ptr [ESI + 0x20]
//         0053792d     PUSH       this
//         0053792e     PUSH       EDX
//         0053792f     PUSH       EAX
//         00537930     CALL       _ASMDraw_Sprite                                  undefined _ASMDraw_Sprite()
//         00537935     ADD        ESP,0x20
//                               LAB_00537938                                                 XREF[1]:     0053785a(j)
//                              view.cpp:3833 (11)
//         00537938     MOV        ESI,dword ptr [ESI + 0x4]
//         0053793b     TEST       ESI,ESI
//         0053793d     JNZ        LAB_00537855
//                               LAB_00537943                                                 XREF[1]:     0053784f(j)
//                              view.cpp:3775 (12)
//         00537943     ADD        EBX,0x4
//         00537946     CMP        EBX,0x14
//         00537949     JLE        LAB_00537841
//                              view.cpp:3843 (23)
//         0053794f     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00537955     XOR        EDI,EDI
//         00537957     CMP        this,EDI
//         00537959     JZ         LAB_00537966
//         0053795b     CALL       TMousePointer::Poll                              void Poll(TMousePointer * this)
//         00537960     MOV        this,dword ptr [MouseSystem]                     = 00000000
//                               LAB_00537966                                                 XREF[1]:     00537959(j)
//                              view.cpp:3853 (41)
//         00537966     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0053796c     CMP        dword ptr [EDX + 0x1b0],0x4
//         00537973     JNZ        LAB_00537b2a
//         00537979     CMP        dword ptr [EBP + 0x78],EDI
//         0053797c     JZ         LAB_00537b2a
//         00537982     CALL       TMousePointer::get_game_enable                   int get_game_enable(TMousePointer * this)
//         00537987     TEST       EAX,EAX
//         00537989     JZ         LAB_00537b2a
//                              language.dll match for 0xf11: "Click to select this Ruin."
//                              view.cpp:3857 (15)
//         0053798f     PUSH       0xf11
//         00537994     PUSH       s_C:\msdev\work\age1_x1\view.cpp                 = "C:\\msdev\\work\\age1_x1\\view.cpp"
//         00537999     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//                              view.cpp:3859 (48)
//         0053799e     MOV        this,dword ptr [ESP + 0x130]
//         005379a5     MOV        ESI,EAX
//         005379a7     MOV        EAX,dword ptr [ESP + 0x134]
//         005379ae     ADD        ESP,0x8
//         005379b1     NEG        EAX
//         005379b3     NEG        this
//         005379b5     PUSH       EAX
//         005379b6     LEA        EDX,[ESP + 0x8c]
//         005379bd     PUSH       this
//         005379be     PUSH       EDX
//         005379bf     MOV        this,EBP
//         005379c1     CALL       RGE_View::Get_Cursor_Position                    int Get_Cursor_Position(RGE_View * this, tagP
//         005379c6     TEST       EAX,EAX
//         005379c8     JZ         LAB_00537b2a
//                              view.cpp:3863 (45)
//         005379ce     MOV        this,dword ptr [ESP + 0x8c]
//         005379d5     MOV        EDX,dword ptr [ESP + 0x88]
//         005379dc     LEA        EAX,[ESP + 0x84]
//         005379e3     PUSH       EAX
//         005379e4     MOV        EAX,dword ptr [EBP + 0x338]
//         005379ea     PUSH       0x28
//         005379ec     PUSH       0xa
//         005379ee     PUSH       this
//         005379ef     PUSH       EDX
//         005379f0     PUSH       EAX
//         005379f1     MOV        this,EBP
//         005379f3     CALL       RGE_View::pick_touched_object                    int pick_touched_object(RGE_View * this, DCli
//         005379f8     CMP        EAX,0x1
//                              view.cpp:3867 (35)
//         005379fb     MOV        EAX,dword ptr [EBP + 0x33c]
//         00537a01     JNZ        LAB_00537aee
//         00537a07     CMP        EAX,EDI
//         00537a09     MOV        EAX,dword ptr [ESP + 0x84]
//         00537a10     JZ         LAB_00537a1e
//         00537a12     CMP        dword ptr [EBP + 0x340],EAX
//         00537a18     JZ         LAB_00537b2a
//                               LAB_00537a1e                                                 XREF[1]:     00537a10(j)
//                              view.cpp:3871 (24)
//         00537a1e     MOV        this,dword ptr [EBP + 0x340]
//         00537a24     MOV        dword ptr [EBP + 0x33c],0x1
//         00537a2e     CMP        this,EAX
//         00537a30     JZ         LAB_00537b2a
//                              view.cpp:3881 (50)
//         00537a36     MOV        this,dword ptr [EBP + 0x100]
//         00537a3c     MOV        dword ptr [EBP + 0x344],ESI
//         00537a42     LEA        ESI,[ESP + 0x2c]
//         00537a46     MOV        dword ptr [EBP + 0x340],EAX
//         00537a4c     MOV        EDX,dword ptr [this->_padding_]
//         00537a4e     PUSH       ESI
//         00537a4f     LEA        ESI,[ESP + 0x2c]
//         00537a53     MOV        dword ptr [ESP + 0x2c],EDI
//         00537a57     PUSH       ESI
//         00537a58     PUSH       EAX
//         00537a59     MOV        dword ptr [ESP + 0x38],EDI
//         00537a5d     CALL       dword ptr [EDX + 0x9c]
//         00537a63     CMP        EAX,0x1
//         00537a66     JNZ        LAB_00537ac8
//                              view.cpp:3883 (16)
//         00537a68     MOV        EAX,dword ptr [ESP + 0x28]
//         00537a6c     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00537a72     PUSH       EAX
//         00537a73     CALL       TMousePointer::set_game_facet                    void set_game_facet(TMousePointer * this, int
//                              view.cpp:3884 (30)
//         00537a78     CMP        dword ptr [EBP + 0x34c],EDI
//         00537a7e     JZ         LAB_00537b2a
//         00537a84     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00537a8a     CMP        dword ptr [this->_padding_ + 0xa08],EDI
//         00537a90     JZ         LAB_00537b2a
//                              view.cpp:3886 (22)
//         00537a96     MOV        EAX,dword ptr [ESP + 0x2c]
//         00537a9a     LEA        EDX,[ESP + 0xa0]
//                              language.dll match for 0x7f: "N"
//         00537aa1     PUSH       0x7f
//         00537aa3     PUSH       EDX
//         00537aa4     PUSH       EAX
//         00537aa5     MOV        this,EBP
//         00537aa7     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              view.cpp:3887 (26)
//         00537aac     PUSH       EDI
//         00537aad     PUSH       EDI
//         00537aae     PUSH       EDI
//         00537aaf     PUSH       EDI
//         00537ab0     LEA        this,[ESP + 0xb0]
//                              language.dll match for 0x70: "B"
//         00537ab7     PUSH       0x70
//         00537ab9     PUSH       this
//         00537aba     MOV        this,dword ptr [EBP + 0x34c]
//         00537ac0     PUSH       EDI
//         00537ac1     CALL       TMessagePanel::show_message                      void show_message(TMessagePanel * this, Messa
//                              view.cpp:3890 (2)
//         00537ac6     JMP        LAB_00537b2a
//                               LAB_00537ac8                                                 XREF[1]:     00537a66(j)
//                              view.cpp:3892 (12)
//         00537ac8     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00537ace     PUSH       EDI
//         00537acf     CALL       TMousePointer::set_game_facet                    void set_game_facet(TMousePointer * this, int
//                              view.cpp:3893 (24)
//         00537ad4     MOV        this,dword ptr [EBP + 0x34c]
//         00537ada     CMP        this,EDI
//         00537adc     JZ         LAB_00537b2a
//         00537ade     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         00537ae4     CMP        dword ptr [EDX + 0xa08],EDI
//         00537aea     JZ         LAB_00537b2a
//                              view.cpp:3903 (2)
//         00537aec     JMP        LAB_00537b25
//                               LAB_00537aee                                                 XREF[1]:     00537a01(j)
//                              view.cpp:3906 (4)
//         00537aee     CMP        EAX,EDI
//         00537af0     JZ         LAB_00537b2a
//                              view.cpp:3911 (6)
//         00537af2     MOV        dword ptr [EBP + 0x33c],EDI
//                              view.cpp:3912 (10)
//         00537af8     MOV        dword ptr [EBP + 0x340],0x80000000
//                              view.cpp:3914 (12)
//         00537b02     MOV        this,dword ptr [MouseSystem]                     = 00000000
//         00537b08     PUSH       EDI
//         00537b09     CALL       TMousePointer::set_game_facet                    void set_game_facet(TMousePointer * this, int
//                              view.cpp:3915 (23)
//         00537b0e     MOV        this,dword ptr [EBP + 0x34c]
//         00537b14     CMP        this,EDI
//         00537b16     JZ         LAB_00537b2a
//         00537b18     MOV        EAX,[rge_base_game]                              = 00000000
//         00537b1d     CMP        dword ptr [EAX + 0xa08],EDI
//         00537b23     JZ         LAB_00537b2a
//                               LAB_00537b25                                                 XREF[1]:     00537aec(j)
//                              view.cpp:3916 (5)
//         00537b25     CALL       TMessagePanel::remove_message                    void remove_message(TMessagePanel * this)
//                              Symbol Ref: No symbol: no_mouse_process
//                               LAB_00537b2a                                                 XREF[14]:    00537973(j), 0053797c(j),
//                                                                                                         00537989(j), 005379c8(j),
//                                                                                                         00537a18(j), 00537a30(j),
//                                                                                                         00537a7e(j), 00537a90(j),
//                                                                                                         00537ac6(j), 00537adc(j),
//                                                                                                         00537aea(j), 00537af0(j),
//                                                                                                         00537b16(j), 00537b23(j)
//                              view.cpp:3929 (11)
//         00537b2a     MOV        EBX,dword ptr [EBP + 0x58]
//         00537b2d     CMP        EBX,EDI
//         00537b2f     JZ         LAB_00537bfd
//                               LAB_00537b35                                                 XREF[1]:     00537bf7(j)
//                              view.cpp:3931 (2)
//         00537b35     MOV        EDI,dword ptr [EBX]
//                              view.cpp:3933 (11)
//         00537b37     MOV        EAX,dword ptr [EDI + 0x6c]
//         00537b3a     TEST       EAX,EAX
//         00537b3c     JZ         LAB_00537bf2
//                              view.cpp:3935 (11)
//         00537b42     MOV        EAX,dword ptr [EDI + 0x38]
//         00537b45     TEST       EAX,EAX
//         00537b47     JZ         LAB_00537bf2
//                              view.cpp:3939 (18)
//         00537b4d     MOV        EDX,dword ptr [EDI]
//         00537b4f     LEA        EAX,[ESP + 0x90]
//         00537b56     PUSH       EAX
//         00537b57     MOV        this,EDI
//         00537b59     CALL       dword ptr [EDX + 0xb8]
//                              view.cpp:3942 (30)
//         00537b5f     MOV        EDX,dword ptr [ESP + 0x94]
//         00537b66     MOV        ESI,dword ptr [ESP + 0x12c]
//         00537b6d     MOV        EAX,dword ptr [ESP + 0x90]
//         00537b74     MOV        this,dword ptr [ESP + 0x128]
//         00537b7b     SUB        EDX,ESI
//                              view.cpp:3944 (11)
//         00537b7d     MOV        ESI,dword ptr [ESP + 0x98]
//         00537b84     SUB        EAX,this
//         00537b86     SUB        ESI,this
//                              view.cpp:3945 (14)
//         00537b88     MOV        this,dword ptr [ESP + 0x9c]
//         00537b8f     SUB        this,dword ptr [ESP + 0x12c]
//                              view.cpp:3947 (6)
//         00537b96     TEST       EAX,EAX
//         00537b98     JGE        LAB_00537b9c
//         00537b9a     XOR        EAX,EAX
//                               LAB_00537b9c                                                 XREF[1]:     00537b98(j)
//                              view.cpp:3948 (6)
//         00537b9c     TEST       EDX,EDX
//         00537b9e     JGE        LAB_00537ba2
//         00537ba0     XOR        EDX,EDX
//                               LAB_00537ba2                                                 XREF[1]:     00537b9e(j)
//                              view.cpp:3952 (37)
//         00537ba2     MOV        EDI,dword ptr [EDI + 0xe0]
//         00537ba8     PUSH       0x0
//         00537baa     PUSH       EDI
//         00537bab     PUSH       0x1e
//         00537bad     PUSH       0x0
//         00537baf     PUSH       0x0
//         00537bb1     PUSH       0x0
//         00537bb3     PUSH       0x0
//         00537bb5     PUSH       this
//         00537bb6     PUSH       ESI
//         00537bb7     PUSH       EDX
//         00537bb8     PUSH       EAX
//         00537bb9     PUSH       this
//         00537bba     MOV        this,dword ptr [EBP + 0x338]
//         00537bc0     PUSH       0x3
//         00537bc2     CALL       DClipInfo_List::AddGDINode                       DClipInfo_Node * AddGDINode(DClipInfo_List *
//                              view.cpp:3954 (4)
//         00537bc7     TEST       EAX,EAX
//         00537bc9     JZ         LAB_00537bf2
//                              view.cpp:3956 (16)
//         00537bcb     MOV        this,dword ptr [EBP + 0x338]
//         00537bd1     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00537bd4     MOV        EDX,dword ptr [EDX + 0x78]
//         00537bd7     TEST       EDX,EDX
//         00537bd9     JNZ        LAB_00537be3
//                              view.cpp:3958 (6)
//         00537bdb     MOV        this,dword ptr [ECX + this->_padding_]
//         00537bde     MOV        dword ptr [ECX + this->_padding_],EAX
//                              view.cpp:3961 (2)
//         00537be1     JMP        LAB_00537be6
//                               LAB_00537be3                                                 XREF[1]:     00537bd9(j)
//                              view.cpp:3963 (3)
//         00537be3     MOV        dword ptr [EDX + 0x4],EAX
//                               LAB_00537be6                                                 XREF[1]:     00537be1(j)
//                              view.cpp:3964 (23)
//         00537be6     MOV        EDX,dword ptr [EBP + 0x338]
//         00537bec     MOV        this,dword ptr [EDX + 0x60]
//         00537bef     MOV        dword ptr [ECX + this->_padding_],EAX
//                               LAB_00537bf2                                                 XREF[3]:     00537b3c(j), 00537b47(j),
//                                                                                                         00537bc9(j)
//         00537bf2     MOV        EBX,dword ptr [EBX + 0x8]
//         00537bf5     TEST       EBX,EBX
//         00537bf7     JNZ        LAB_00537b35
//                               LAB_00537bfd                                                 XREF[1]:     00537b2f(j)
//                              view.cpp:3974 (10)
//         00537bfd     MOV        AL,byte ptr [EBP + 0x142]
//         00537c03     TEST       AL,AL
//         00537c05     JNZ        LAB_00537c45
//                              view.cpp:3976 (15)
//         00537c07     MOV        EAX,dword ptr [EBP + 0x324]
//         00537c0d     XOR        ESI,ESI
//         00537c0f     MOV        this,dword ptr [EAX + 0x1c]
//         00537c12     TEST       this,this
//         00537c14     JLE        LAB_00537c35
//                               LAB_00537c16                                                 XREF[1]:     00537c33(j)
//                              view.cpp:3977 (31)
//         00537c16     MOV        EDX,dword ptr [EAX + 0x18]
//         00537c19     MOV        this,dword ptr [EBP + 0x180]
//         00537c1f     DEC        EDX
//         00537c20     PUSH       ESI
//         00537c21     PUSH       EDX
//         00537c22     PUSH       0x0
//         00537c24     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//         00537c29     MOV        EAX,dword ptr [EBP + 0x324]
//         00537c2f     INC        ESI
//         00537c30     CMP        ESI,dword ptr [EAX + 0x1c]
//         00537c33     JL         LAB_00537c16
//                               LAB_00537c35                                                 XREF[1]:     00537c14(j)
//                              view.cpp:3979 (11)
//         00537c35     MOV        this,dword ptr [EBP + 0x334]
//         00537c3b     CALL       DClipInfo_List::ReclaimAllNodes                  void ReclaimAllNodes(DClipInfo_List * this)
//                              view.cpp:4250 (5)
//         00537c40     JMP        LAB_00537ecb
//                               LAB_00537c45                                                 XREF[1]:     00537c05(j)
//                              view.cpp:3985 (25)
//         00537c45     MOV        EAX,dword ptr [EBP + 0x17c]
//         00537c4b     MOV        this,dword ptr [EBP + 0x178]
//         00537c51     PUSH       EAX
//         00537c52     PUSH       this
//         00537c53     MOV        this,dword ptr [EBP + 0x180]
//         00537c59     CALL       TSpan_List_Manager::Merge_n_Align                void Merge_n_Align(TSpan_List_Manager * this,
//                              view.cpp:3989 (14)
//         00537c5e     MOV        EAX,dword ptr [EBP + 0x2a0]
//         00537c64     TEST       EAX,EAX
//         00537c66     JZ         LAB_00537cf4
//                              view.cpp:3991 (10)
//         00537c6c     MOV        EAX,dword ptr [EBP + 0x2a8]
//         00537c72     TEST       EAX,EAX
//         00537c74     JL         LAB_00537cab
//                              view.cpp:3993 (16)
//         00537c76     MOV        ESI,dword ptr [EBP + 0x2ac]
//         00537c7c     MOV        EAX,dword ptr [EBP + 0x2b4]
//         00537c82     CMP        ESI,EAX
//         00537c84     JG         LAB_00537cab
//                               LAB_00537c86                                                 XREF[1]:     00537ca9(j)
//                              view.cpp:3994 (37)
//         00537c86     MOV        EDX,dword ptr [EBP + 0x2b0]
//         00537c8c     MOV        EAX,dword ptr [EBP + 0x2a8]
//         00537c92     MOV        this,dword ptr [EBP + 0x180]
//         00537c98     PUSH       ESI
//         00537c99     PUSH       EDX
//         00537c9a     PUSH       EAX
//         00537c9b     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//         00537ca0     MOV        EAX,dword ptr [EBP + 0x2b4]
//         00537ca6     INC        ESI
//         00537ca7     CMP        ESI,EAX
//         00537ca9     JLE        LAB_00537c86
//                               LAB_00537cab                                                 XREF[2]:     00537c74(j), 00537c84(j)
//                              view.cpp:3997 (10)
//         00537cab     MOV        EAX,dword ptr [EBP + 0x2a4]
//         00537cb1     TEST       EAX,EAX
//         00537cb3     JZ         LAB_00537cf4
//                              view.cpp:3999 (10)
//         00537cb5     MOV        EAX,dword ptr [EBP + 0x2b8]
//         00537cbb     TEST       EAX,EAX
//         00537cbd     JL         LAB_00537cf4
//                              view.cpp:4001 (16)
//         00537cbf     MOV        ESI,dword ptr [EBP + 0x2bc]
//         00537cc5     MOV        EAX,dword ptr [EBP + 0x2c4]
//         00537ccb     CMP        ESI,EAX
//         00537ccd     JG         LAB_00537cf4
//                               LAB_00537ccf                                                 XREF[1]:     00537cf2(j)
//                              view.cpp:4002 (37)
//         00537ccf     MOV        this,dword ptr [EBP + 0x2c0]
//         00537cd5     MOV        EDX,dword ptr [EBP + 0x2b8]
//         00537cdb     PUSH       ESI
//         00537cdc     PUSH       this
//         00537cdd     MOV        this,dword ptr [EBP + 0x180]
//         00537ce3     PUSH       EDX
//         00537ce4     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//         00537ce9     MOV        EAX,dword ptr [EBP + 0x2c4]
//         00537cef     INC        ESI
//         00537cf0     CMP        ESI,EAX
//         00537cf2     JLE        LAB_00537ccf
//                               LAB_00537cf4                                                 XREF[4]:     00537c66(j), 00537cb3(j),
//                                                                                                         00537cbd(j), 00537ccd(j)
//                              view.cpp:4010 (23)
//         00537cf4     MOV        EAX,dword ptr [EBP + 0x338]
//         00537cfa     XOR        this,this
//         00537cfc     MOV        dword ptr [ESP + 0x14],this
//         00537d00     MOV        EDX,dword ptr [EAX + 0x68]
//         00537d03     TEST       EDX,EDX
//         00537d05     JLE        LAB_00537ecb
//                               LAB_00537d0b                                                 XREF[1]:     00537ec5(j)
//                              view.cpp:4012 (6)
//         00537d0b     MOV        EAX,dword ptr [EAX + 0x58]
//         00537d0e     MOV        ESI,dword ptr [EAX + this->_padding_*0x4]
//                              view.cpp:4013 (12)
//         00537d11     TEST       ESI,ESI
//         00537d13     MOV        dword ptr [ESP + 0x18],ESI
//         00537d17     JZ         LAB_00537de3
//                               LAB_00537d1d                                                 XREF[1]:     00537ddd(j)
//                              view.cpp:4015 (10)
//         00537d1d     CMP        dword ptr [ESI + 0x10],0x5
//         00537d21     JLE        LAB_00537dd1
//                              view.cpp:4017 (12)
//         00537d27     MOV        EDX,dword ptr [EBP + 0x334]
//         00537d2d     MOV        EAX,dword ptr [EDX + 0x58]
//         00537d30     MOV        EDX,dword ptr [EAX + this->_padding_*0x4]
//                              view.cpp:4020 (22)
//         00537d33     MOV        EAX,dword ptr [ESI + 0x2c]
//         00537d36     NEG        EAX
//         00537d38     SBB        EAX,EAX
//         00537d3a     MOV        this,0x1
//         00537d3f     AND        EAX,0x10
//         00537d42     MOV        dword ptr [ESP + 0x2c],this
//         00537d46     ADD        EAX,0x24
//                              view.cpp:4022 (4)
//         00537d49     TEST       EDX,EDX
//         00537d4b     JZ         LAB_00537d85
//                              view.cpp:4024 (20)
//         00537d4d     JMP        LAB_00537d53
//                               LAB_00537d4f                                                 XREF[1]:     00537d65(j)
//         00537d4f     MOV        ESI,dword ptr [ESP + 0x18]
//                               LAB_00537d53                                                 XREF[1]:     00537d4d(j)
//         00537d53     ADD        ESI,0xc
//         00537d56     MOV        this,EAX
//         00537d58     LEA        EDI,[EDX + 0xc]
//         00537d5b     XOR        EBX,EBX
//         00537d5d     CMPSB.REPE ES:EDI,ESI
//         00537d5f     JZ         LAB_00537d6d
//                              view.cpp:4036 (6)
//         00537d61     MOV        EDX,dword ptr [EDX]
//         00537d63     TEST       EDX,EDX
//         00537d65     JNZ        LAB_00537d4f
//                              view.cpp:4028 (6)
//         00537d67     MOV        this,dword ptr [ESP + 0x2c]
//         00537d6b     JMP        LAB_00537d81
//                               LAB_00537d6d                                                 XREF[1]:     00537d5f(j)
//                              view.cpp:4027 (13)
//         00537d6d     MOV        EAX,[Clip_remove]
//         00537d72     XOR        this,this
//         00537d74     INC        EAX
//         00537d75     MOV        [Clip_remove],EAX
//                              view.cpp:4028 (11)
//         00537d7a     MOV        dword ptr [EDX + 0x2c],0xffffffff
//                               LAB_00537d81                                                 XREF[1]:     00537d6b(j)
//         00537d81     MOV        ESI,dword ptr [ESP + 0x18]
//                               LAB_00537d85                                                 XREF[1]:     00537d4b(j)
//                              view.cpp:4040 (4)
//         00537d85     TEST       this,this
//         00537d87     JZ         LAB_00537dd1
//                              view.cpp:4042 (7)
//         00537d89     MOV        EAX,dword ptr [ESI + 0x2c]
//         00537d8c     TEST       EAX,EAX
//         00537d8e     JNZ        LAB_00537dc2
//                              view.cpp:4044 (42)
//         00537d90     MOV        this,dword ptr [ESI + 0x1c]
//         00537d93     MOV        EAX,dword ptr [ESI + 0x18]
//         00537d96     AND        this,0x2
//         00537d99     XOR        EDX,EDX
//         00537d9b     CMP        this,0x2
//         00537d9e     MOV        this,dword ptr [ESI + 0x14]
//         00537da1     SETZ       DL
//         00537da4     PUSH       EDX
//         00537da5     MOV        EDX,dword ptr [ESI + 0xc]
//         00537da8     PUSH       EAX
//         00537da9     MOV        EAX,dword ptr [ESI + 0x20]
//         00537dac     PUSH       this
//         00537dad     MOV        this,dword ptr [EBP + 0x180]
//         00537db3     PUSH       EDX
//         00537db4     PUSH       EAX
//         00537db5     CALL       TSpan_List_Manager::AddShape_Align               void AddShape_Align(TSpan_List_Manager * this
//                              view.cpp:4045 (6)
//         00537dba     INC        dword ptr [Clip_draw]
//                              view.cpp:4051 (2)
//         00537dc0     JMP        LAB_00537dd1
//                               LAB_00537dc2                                                 XREF[1]:     00537d8e(j)
//                              view.cpp:4053 (15)
//         00537dc2     MOV        this,dword ptr [EBP + 0x180]
//         00537dc8     PUSH       this
//         00537dc9     PUSH       ESI
//         00537dca     MOV        this,EBP
//         00537dcc     CALL       RGE_View::Add_GDI_Clip_Mask                      void Add_GDI_Clip_Mask(RGE_View * this, DClip
//                               LAB_00537dd1                                                 XREF[3]:     00537d21(j), 00537d87(j),
//                                                                                                         00537dc0(j)
//                              view.cpp:4058 (18)
//         00537dd1     MOV        ESI,dword ptr [ESI]
//         00537dd3     MOV        this,dword ptr [ESP + 0x14]
//         00537dd7     TEST       ESI,ESI
//         00537dd9     MOV        dword ptr [ESP + 0x18],ESI
//         00537ddd     JNZ        LAB_00537d1d
//                               LAB_00537de3                                                 XREF[1]:     00537d17(j)
//                              view.cpp:4063 (12)
//         00537de3     MOV        EDX,dword ptr [EBP + 0x334]
//         00537de9     MOV        EAX,dword ptr [EDX + 0x58]
//         00537dec     MOV        ESI,dword ptr [EAX + this->_padding_*0x4]
//                              view.cpp:4064 (12)
//         00537def     TEST       ESI,ESI
//         00537df1     MOV        dword ptr [ESP + 0x18],ESI
//         00537df5     JZ         LAB_00537eb7
//                               LAB_00537dfb                                                 XREF[1]:     00537eb1(j)
//                              view.cpp:4066 (22)
//         00537dfb     CMP        dword ptr [ESI + 0x10],0x5
//         00537dff     JLE        LAB_00537ea5
//         00537e05     MOV        EAX,dword ptr [ESI + 0x2c]
//         00537e08     CMP        EAX,-0x1
//         00537e0b     JZ         LAB_00537ea5
//                              view.cpp:4068 (6)
//         00537e11     MOV        EDX,dword ptr [EBP + 0x338]
//                              view.cpp:4071 (21)
//         00537e17     NEG        EAX
//         00537e19     MOV        EDX,dword ptr [EDX + 0x58]
//         00537e1c     SBB        EAX,EAX
//         00537e1e     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//         00537e21     AND        EAX,0x10
//         00537e24     MOV        this,0x1
//         00537e29     ADD        EAX,0x24
//                              view.cpp:4073 (8)
//         00537e2c     TEST       EDX,EDX
//         00537e2e     MOV        dword ptr [ESP + 0x2c],this
//         00537e32     JZ         LAB_00537e5a
//                              view.cpp:4075 (20)
//         00537e34     JMP        LAB_00537e3a
//                               LAB_00537e36                                                 XREF[1]:     00537e4c(j)
//         00537e36     MOV        ESI,dword ptr [ESP + 0x18]
//                               LAB_00537e3a                                                 XREF[1]:     00537e34(j)
//         00537e3a     LEA        EDI,[ESI + 0xc]
//         00537e3d     MOV        this,EAX
//         00537e3f     LEA        ESI,[EDX + 0xc]
//         00537e42     XOR        EBX,EBX
//         00537e44     CMPSB.REPE ES:EDI,ESI
//         00537e46     JZ         LAB_00537e54
//                              view.cpp:4080 (6)
//         00537e48     MOV        EDX,dword ptr [EDX]
//         00537e4a     TEST       EDX,EDX
//         00537e4c     JNZ        LAB_00537e36
//                              view.cpp:4077 (12)
//         00537e4e     MOV        this,dword ptr [ESP + 0x2c]
//         00537e52     JMP        LAB_00537e56
//                               LAB_00537e54                                                 XREF[1]:     00537e46(j)
//         00537e54     XOR        this,this
//                               LAB_00537e56                                                 XREF[1]:     00537e52(j)
//         00537e56     MOV        ESI,dword ptr [ESP + 0x18]
//                               LAB_00537e5a                                                 XREF[1]:     00537e32(j)
//                              view.cpp:4083 (4)
//         00537e5a     TEST       this,this
//         00537e5c     JZ         LAB_00537ea5
//                              view.cpp:4085 (7)
//         00537e5e     MOV        EAX,dword ptr [ESI + 0x2c]
//         00537e61     TEST       EAX,EAX
//         00537e63     JNZ        LAB_00537e96
//                              view.cpp:4087 (41)
//         00537e65     MOV        EAX,dword ptr [ESI + 0x1c]
//         00537e68     MOV        EDX,dword ptr [ESI + 0x18]
//         00537e6b     AND        EAX,0x2
//         00537e6e     XOR        this,this
//         00537e70     CMP        AL,0x2
//         00537e72     MOV        EAX,dword ptr [ESI + 0x14]
//         00537e75     SETZ       this
//         00537e78     PUSH       this
//         00537e79     MOV        this,dword ptr [ESI + 0xc]
//         00537e7c     PUSH       EDX
//         00537e7d     MOV        EDX,dword ptr [ESI + 0x20]
//         00537e80     PUSH       EAX
//         00537e81     PUSH       this
//         00537e82     MOV        this,dword ptr [EBP + 0x180]
//         00537e88     PUSH       EDX
//         00537e89     CALL       TSpan_List_Manager::AddShape_Align               void AddShape_Align(TSpan_List_Manager * this
//                              view.cpp:4088 (6)
//         00537e8e     INC        dword ptr [Clip_draw]
//                              view.cpp:4095 (2)
//         00537e94     JMP        LAB_00537ea5
//                               LAB_00537e96                                                 XREF[1]:     00537e63(j)
//                              view.cpp:4097 (15)
//         00537e96     MOV        EAX,dword ptr [EBP + 0x180]
//         00537e9c     MOV        this,EBP
//         00537e9e     PUSH       EAX
//         00537e9f     PUSH       ESI
//         00537ea0     CALL       RGE_View::Add_GDI_Clip_Mask                      void Add_GDI_Clip_Mask(RGE_View * this, DClip
//                               LAB_00537ea5                                                 XREF[4]:     00537dff(j), 00537e0b(j),
//                                                                                                         00537e5c(j), 00537e94(j)
//                              view.cpp:4101 (18)
//         00537ea5     MOV        ESI,dword ptr [ESI]
//         00537ea7     MOV        this,dword ptr [ESP + 0x14]
//         00537eab     TEST       ESI,ESI
//         00537ead     MOV        dword ptr [ESP + 0x18],ESI
//         00537eb1     JNZ        LAB_00537dfb
//                               LAB_00537eb7                                                 XREF[1]:     00537df5(j)
//                              view.cpp:4010 (20)
//         00537eb7     MOV        EAX,dword ptr [EBP + 0x338]
//         00537ebd     INC        this
//         00537ebe     MOV        dword ptr [ESP + 0x14],this
//         00537ec2     CMP        this,dword ptr [EAX + 0x68]
//         00537ec5     JL         LAB_00537d0b
//                              Symbol Ref: No symbol: addNoMore
//                               LAB_00537ecb                                                 XREF[2]:     00537c40(j), 00537d05(j)
//                              view.cpp:4117 (13)
//         00537ecb     MOV        ESI,dword ptr [ESP + 0x128]
//         00537ed2     MOV        EDX,dword ptr [EBP + 0x8c]
//                              view.cpp:4118 (23)
//         00537ed8     MOV        EDI,dword ptr [ESP + 0x12c]
//         00537edf     ADD        EDX,ESI
//         00537ee1     MOV        dword ptr [EBP + 0x8c],EDX
//         00537ee7     MOV        this,dword ptr [EBP + 0x90]
//         00537eed     ADD        this,EDI
//                              view.cpp:4125 (77)
//         00537eef     MOV        EDX,dword ptr [EBP + 0x180]
//         00537ef5     MOV        dword ptr [EBP + 0x90],this
//         00537efb     MOV        EAX,dword ptr [EBP + 0x94]
//         00537f01     MOV        this,dword ptr [EBP + 0x324]
//         00537f07     ADD        EAX,ESI
//         00537f09     MOV        dword ptr [EBP + 0x94],EAX
//         00537f0f     MOV        EBX,dword ptr [EBP + 0x98]
//         00537f15     ADD        EBX,EDI
//         00537f17     MOV        dword ptr [EBP + 0x98],EBX
//         00537f1d     MOV        EAX,dword ptr [EDX + 0x3c]
//         00537f20     PUSH       EAX
//         00537f21     MOV        EAX,dword ptr [EBP + 0x90]
//         00537f27     LEA        EDX,[ECX + this->_padding_]
//         00537f2a     PUSH       EDX
//         00537f2b     MOV        EDX,dword ptr [EBP + 0x8c]
//         00537f31     PUSH       EAX
//         00537f32     MOV        EAX,dword ptr [EBP + 0x20]
//         00537f35     PUSH       EDX
//         00537f36     PUSH       EAX
//         00537f37     CALL       TDrawArea::PtrSpanCopy                           void PtrSpanCopy(TDrawArea * this, TDrawArea
//                              view.cpp:4129 (7)
//         00537f3c     MOV        this,EBP
//         00537f3e     CALL       RGE_View::Update_Render_Pointers                 void Update_Render_Pointers(RGE_View * this)
//                              view.cpp:4131 (14)
//         00537f43     MOV        EDX,dword ptr [EBP + 0x8c]
//         00537f49     SUB        EDX,ESI
//         00537f4b     MOV        dword ptr [EBP + 0x8c],EDX
//                              view.cpp:4132 (14)
//         00537f51     MOV        this,dword ptr [EBP + 0x90]
//         00537f57     SUB        this,EDI
//         00537f59     MOV        dword ptr [EBP + 0x90],this
//                              view.cpp:4133 (14)
//         00537f5f     MOV        EAX,dword ptr [EBP + 0x94]
//         00537f65     SUB        EAX,ESI
//         00537f67     MOV        dword ptr [EBP + 0x94],EAX
//                              view.cpp:4134 (6)
//         00537f6d     MOV        EBX,dword ptr [EBP + 0x98]
//                              view.cpp:4148 (50)
//         00537f73     MOV        EAX,dword ptr [EBP + 0x180]
//         00537f79     SUB        EBX,EDI
//         00537f7b     MOV        dword ptr [EBP + 0x98],EBX
//         00537f81     MOV        this,dword ptr [EAX + 0x64]
//         00537f84     MOV        EDX,dword ptr [EAX + 0x5c]
//         00537f87     PUSH       this
//         00537f88     MOV        this,dword ptr [EAX + 0x60]
//         00537f8b     PUSH       EDX
//         00537f8c     MOV        EDX,dword ptr [EAX + 0x58]
//         00537f8f     PUSH       this
//         00537f90     MOV        this,dword ptr [EAX + 0x40]
//         00537f93     PUSH       EDX
//         00537f94     MOV        EDX,dword ptr [EAX + 0x3c]
//         00537f97     MOV        EAX,dword ptr [EBP + 0x32c]
//         00537f9d     PUSH       this
//         00537f9e     PUSH       EDX
//         00537f9f     PUSH       EAX
//         00537fa0     CALL       _ASMSet_Surface_Info                             undefined _ASMSet_Surface_Info()
//                              view.cpp:4150 (27)
//         00537fa5     MOV        this,dword ptr [EBP + 0x20]
//         00537fa8     MOV        EDX,dword ptr [EBP + 0x180]
//         00537fae     MOV        EAX,0x18
//         00537fb3     ADD        ESP,0x1c
//         00537fb6     MOV        dword ptr [ECX + this->_padding_],EDX
//         00537fbc     MOV        dword ptr [ESP + 0x28],EAX
//                               LAB_00537fc0                                                 XREF[1]:     005380cc(j)
//                              view.cpp:4156 (12)
//         00537fc0     MOV        this,dword ptr [EBP + 0x338]
//         00537fc6     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00537fc9     MOV        ESI,dword ptr [EDX + EAX*0x1]
//                              view.cpp:4157 (8)
//         00537fcc     TEST       ESI,ESI
//         00537fce     JZ         LAB_005380c0
//                               LAB_00537fd4                                                 XREF[1]:     005380b6(j)
//                              view.cpp:4159 (11)
//         00537fd4     MOV        EAX,dword ptr [ESI + 0x2c]
//         00537fd7     TEST       EAX,EAX
//         00537fd9     JNZ        LAB_005380a5
//                              view.cpp:4161 (3)
//         00537fdf     MOV        EDI,dword ptr [ESI + 0x1c]
//                              view.cpp:4162 (11)
//         00537fe2     MOV        EBX,0x0
//         00537fe7     AND        EDI,0xffc
//                              view.cpp:4164 (2)
//         00537fed     JZ         LAB_00538044
//                              view.cpp:4166 (9)
//         00537fef     MOV        EAX,EDI
//         00537ff1     AND        EAX,0x4
//         00537ff4     CMP        AL,0x4
//         00537ff6     JNZ        LAB_0053800c
//                              view.cpp:4167 (20)
//         00537ff8     PUSH       EBX
//         00537ff9     PUSH       0xffff00ff
//         00537ffe     PUSH       EBX
//         00537fff     PUSH       0xffffff
//         00538004     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         00538009     ADD        ESP,0x10
//                               LAB_0053800c                                                 XREF[1]:     00537ff6(j)
//                              view.cpp:4169 (10)
//         0053800c     MOV        this,EDI
//         0053800e     AND        this,0x8
//         00538011     CMP        this,0x8
//         00538014     JNZ        LAB_0053803f
//                              view.cpp:4171 (9)
//         00538016     SAR        EDI,0x4
//         00538019     AND        EDI,0xff
//                              view.cpp:4172 (7)
//         0053801f     MOV        EAX,EDI
//         00538021     SHL        EAX,0x10
//         00538024     OR         EAX,EDI
//                              view.cpp:4175 (25)
//         00538026     MOV        EDX,EAX
//         00538028     SHL        EDX,0x8
//         0053802b     PUSH       EDX
//         0053802c     PUSH       0xff00ff
//         00538031     PUSH       EAX
//         00538032     PUSH       0xff00ff00
//         00538037     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         0053803c     ADD        ESP,0x10
//                               LAB_0053803f                                                 XREF[1]:     00538014(j)
//                              view.cpp:4178 (5)
//         0053803f     MOV        EBX,0x1
//                               LAB_00538044                                                 XREF[1]:     00537fed(j)
//                              view.cpp:4181 (9)
//         00538044     MOV        EAX,dword ptr [ESI + 0x28]
//         00538047     PUSH       EAX
//         00538048     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
//                              view.cpp:4182 (12)
//         0053804d     MOV        this,dword ptr [ESI + 0x24]
//         00538050     ADD        ESP,0x4
//         00538053     PUSH       this
//         00538054     CALL       _ASMSet_Xlate_Table                              undefined _ASMSet_Xlate_Table()
//                              view.cpp:4191 (48)
//         00538059     MOV        EDX,dword ptr [ESI + 0x1c]
//         0053805c     MOV        EAX,dword ptr [ESI + 0xc]
//         0053805f     ADD        ESP,0x4
//         00538062     AND        EDX,0x3
//         00538065     MOV        this,dword ptr [EAX + 0x4]
//         00538068     PUSH       EDX
//         00538069     MOV        EDX,dword ptr [EAX]
//         0053806b     PUSH       this
//         0053806c     MOV        this,dword ptr [EAX + 0x14]
//         0053806f     PUSH       EDX
//         00538070     MOV        EDX,dword ptr [EAX + 0x10]
//         00538073     MOV        EAX,dword ptr [ESI + 0x18]
//         00538076     PUSH       this
//         00538077     MOV        this,dword ptr [ESI + 0x14]
//         0053807a     PUSH       EDX
//         0053807b     MOV        EDX,dword ptr [ESI + 0x20]
//         0053807e     PUSH       EAX
//         0053807f     PUSH       this
//         00538080     PUSH       EDX
//         00538081     CALL       _ASMDraw_Sprite                                  undefined _ASMDraw_Sprite()
//         00538086     ADD        ESP,0x20
//                              view.cpp:4193 (4)
//         00538089     TEST       EBX,EBX
//         0053808b     JZ         LAB_005380b1
//                              view.cpp:4194 (22)
//         0053808d     PUSH       0x0
//         0053808f     PUSH       0xff00ff00
//         00538094     PUSH       0x0
//         00538096     PUSH       0xff00ff
//         0053809b     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         005380a0     ADD        ESP,0x10
//                              view.cpp:4202 (2)
//         005380a3     JMP        LAB_005380b1
//                               LAB_005380a5                                                 XREF[1]:     00537fd9(j)
//                              view.cpp:4204 (12)
//         005380a5     MOV        EAX,dword ptr [EBP + 0x20]
//         005380a8     MOV        this,EBP
//         005380aa     PUSH       EAX
//         005380ab     PUSH       ESI
//         005380ac     CALL       RGE_View::Draw_GDI_Object                        void Draw_GDI_Object(RGE_View * this, DClipIn
//                               LAB_005380b1                                                 XREF[2]:     0053808b(j), 005380a3(j)
//                              view.cpp:4206 (11)
//         005380b1     MOV        ESI,dword ptr [ESI + 0x4]
//         005380b4     TEST       ESI,ESI
//         005380b6     JNZ        LAB_00537fd4
//                              view.cpp:4157 (4)
//         005380bc     MOV        EAX,dword ptr [ESP + 0x28]
//                               LAB_005380c0                                                 XREF[1]:     00537fce(j)
//                              view.cpp:4154 (18)
//         005380c0     ADD        EAX,0x4
//         005380c3     CMP        EAX,0xa0
//         005380c8     MOV        dword ptr [ESP + 0x28],EAX
//         005380cc     JLE        LAB_00537fc0
//                              view.cpp:4214 (9)
//         005380d2     MOV        EAX,[view_debug_spans]
//         005380d7     TEST       EAX,EAX
//         005380d9     JZ         LAB_0053811b
//                              view.cpp:4216 (10)
//         005380db     MOV        AL,byte ptr [EBP + 0x142]
//         005380e1     TEST       AL,AL
//         005380e3     JZ         LAB_0053811b
//                              view.cpp:4218 (13)
//         005380e5     MOV        EAX,[frame_count]
//         005380ea     MOV        this,0xdc
//         005380ef     CDQ
//         005380f0     IDIV       this
//                              view.cpp:4219 (17)
//         005380f2     MOV        this,dword ptr [EBP + 0x20]
//         005380f5     XOR        ESI,ESI
//         005380f7     MOV        EAX,dword ptr [ECX + this->_padding_]
//         005380fa     MOV        EDI,EDX
//         005380fc     ADD        EDI,0x10
//         005380ff     TEST       EAX,EAX
//         00538101     JLE        LAB_0053811b
//                               LAB_00538103                                                 XREF[1]:     00538119(j)
//                              view.cpp:4221 (24)
//         00538103     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00538106     PUSH       EDI
//         00538107     DEC        EDX
//         00538108     PUSH       ESI
//         00538109     PUSH       EDX
//         0053810a     PUSH       ESI
//         0053810b     PUSH       0x0
//         0053810d     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//         00538112     MOV        this,dword ptr [EBP + 0x20]
//         00538115     INC        ESI
//         00538116     CMP        ESI,dword ptr [ECX + this->_padding_]
//         00538119     JL         LAB_00538103
//                               LAB_0053811b                                                 XREF[3]:     005380d9(j), 005380e3(j),
//                                                                                                         00538101(j)
//                              view.cpp:4226 (9)
//         0053811b     MOV        EAX,[view_debug_palette]
//         00538120     TEST       EAX,EAX
//         00538122     JZ         LAB_0053817d
//                              view.cpp:4228 (8)
//         00538124     MOV        dword ptr [ESP + 0x14],0x0
//                              view.cpp:4250 (22)
//         0053812c     MOV        EDI,0x20
//                               LAB_00538131                                                 XREF[1]:     0053817b(j)
//         00538131     MOV        AL,byte ptr [ESP + 0x14]
//         00538135     XOR        EBX,EBX
//         00538137     SHL        AL,0x4
//         0053813a     MOV        byte ptr [ESP + 0x13],AL
//         0053813e     XOR        ESI,ESI
//         00538140     JMP        LAB_00538146
//                               LAB_00538142                                                 XREF[1]:     00538167(j)
//                              view.cpp:4229 (4)
//         00538142     MOV        AL,byte ptr [ESP + 0x13]
//                               LAB_00538146                                                 XREF[1]:     00538140(j)
//                              view.cpp:4230 (55)
//         00538146     MOV        this,BL
//         00538148     LEA        EDX,[ESI + 0x1f]
//         0053814b     ADD        this,AL
//         0053814d     LEA        EAX,[EDI + 0xf]
//         00538150     PUSH       this
//         00538151     MOV        this,dword ptr [EBP + 0x20]
//         00538154     PUSH       EAX
//         00538155     PUSH       EDX
//         00538156     PUSH       EDI
//         00538157     PUSH       ESI
//         00538158     CALL       TDrawArea::FillRect                              void FillRect(TDrawArea * this, long param_1,
//         0053815d     ADD        ESI,0x20
//         00538160     INC        EBX
//         00538161     CMP        ESI,0x200
//         00538167     JL         LAB_00538142
//         00538169     MOV        EDX,dword ptr [ESP + 0x14]
//         0053816d     ADD        EDI,0x10
//         00538170     INC        EDX
//         00538171     CMP        EDI,0x120
//         00538177     MOV        dword ptr [ESP + 0x14],EDX
//         0053817b     JL         LAB_00538131
//                               LAB_0053817d                                                 XREF[1]:     00538122(j)
//                              view.cpp:4234 (13)
//         0053817d     MOV        this,dword ptr [EBP + 0x20]
//         00538180     PUSH       s_view::view_function_terrain                    = "view::view_function_terrain"
//         00538185     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
//                              view.cpp:4235 (3)
//         0053818a     MOV        EAX,dword ptr [EBP + 0x20]
//                              view.cpp:4250 (51)
//         0053818d     POP        EDI
//         0053818e     POP        ESI
//         0053818f     MOV        this,dword ptr [EAX + 0xcc]
//         00538195     MOV        dword ptr [EAX + 0xd0],this
//         0053819b     MOV        EAX,dword ptr [EBP + 0x334]
//         005381a1     MOV        EDX,dword ptr [EBP + 0x338]
//         005381a7     MOV        dword ptr [EBP + 0x338],EAX
//         005381ad     MOV        dword ptr [EBP + 0x334],EDX
//         005381b3     POP        EBP
//         005381b4     XOR        EAX,EAX
//         005381b6     POP        EBX
//         005381b7     ADD        ESP,0x110
//         005381bd     RET        0x14
    return 0;
}

void RGE_View::Update_Render_Pointers() {
    /* TODO: Stub */
//                              void __thiscall Update_Render_Pointers(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?Update_Render_Pointers@RGE_View@@IAEXXZ                     XREF[1]:     view_function_terrain:00537f3e(c)
//                               RGE_View::Update_Render_Pointers
//                              view.cpp:4254 (4)
//         005381c0     PUSH       ESI
//         005381c1     MOV        ESI,this
//         005381c3     PUSH       EDI
//                              view.cpp:4258 (45)
//         005381c4     MOV        EAX,dword ptr [ESI + 0x20]
//         005381c7     MOV        this,dword ptr [ESI + 0x328]
//         005381cd     MOV        EAX,dword ptr [EAX + 0x8]
//         005381d0     CMP        this,EAX
//         005381d2     JNZ        LAB_005381f1
//         005381d4     MOV        this,dword ptr [ESI + 0x98]
//         005381da     MOV        EDX,dword ptr [ESI + 0x90]
//         005381e0     SUB        this,EDX
//         005381e2     MOV        EDX,dword ptr [ESI + 0x330]
//         005381e8     INC        this
//         005381e9     CMP        EDX,this
//         005381eb     JZ         LAB_0053827b
//                               LAB_005381f1                                                 XREF[1]:     005381d2(j)
//                              view.cpp:4260 (15)
//         005381f1     MOV        EDI,dword ptr [ESI + 0x98]
//         005381f7     MOV        this,dword ptr [ESI + 0x90]
//         005381fd     SUB        EDI,this
//         005381ff     INC        EDI
//                              view.cpp:4262 (8)
//         00538200     TEST       EDI,EDI
//         00538202     JLE        LAB_0053827b
//         00538204     TEST       EAX,EAX
//         00538206     JZ         LAB_0053827b
//                              view.cpp:4264 (18)
//         00538208     CMP        EDI,dword ptr [ESI + 0x330]
//         0053820e     JNZ        LAB_0053821a
//         00538210     MOV        EAX,dword ptr [ESI + 0x32c]
//         00538216     TEST       EAX,EAX
//         00538218     JNZ        LAB_00538249
//                               LAB_0053821a                                                 XREF[1]:     0053820e(j)
//                              view.cpp:4266 (19)
//         0053821a     MOV        EAX,dword ptr [ESI + 0x32c]
//         00538220     TEST       EAX,EAX
//         00538222     JZ         LAB_0053822d
//         00538224     PUSH       EAX
//         00538225     CALL       free                                             undefined free()
//         0053822a     ADD        ESP,0x4
//                               LAB_0053822d                                                 XREF[1]:     00538222(j)
//                              view.cpp:4268 (22)
//         0053822d     LEA        EDX,[EDI*0x4 + 0x0]
//         00538234     PUSH       EDX
//         00538235     CALL       malloc                                           undefined malloc()
//         0053823a     ADD        ESP,0x4
//         0053823d     MOV        dword ptr [ESI + 0x32c],EAX
//                              view.cpp:4270 (6)
//         00538243     MOV        dword ptr [ESI + 0x330],EDI
//                               LAB_00538249                                                 XREF[1]:     00538218(j)
//                              view.cpp:4273 (6)
//         00538249     XOR        EAX,EAX
//         0053824b     TEST       EDI,EDI
//         0053824d     JLE        LAB_0053827b
//                               LAB_0053824f                                                 XREF[1]:     00538279(j)
//                              view.cpp:4275 (44)
//         0053824f     MOV        EDX,dword ptr [ESI + 0x90]
//         00538255     MOV        this,EAX
//         00538257     ADD        this,EDX
//         00538259     MOV        EDX,dword ptr [ESI + 0x20]
//         0053825c     MOV        EDX,dword ptr [EDX + 0xbc]
//         00538262     MOV        this,dword ptr [EDX + this->_padding_*0x4]
//         00538265     MOV        EDX,dword ptr [ESI + 0x8c]
//         0053826b     ADD        this,EDX
//         0053826d     MOV        EDX,dword ptr [ESI + 0x32c]
//         00538273     MOV        dword ptr [EDX + EAX*0x4],this
//         00538276     INC        EAX
//         00538277     CMP        EAX,EDI
//         00538279     JL         LAB_0053824f
//                               LAB_0053827b                                                 XREF[4]:     005381eb(j), 00538202(j),
//                                                                                                         00538206(j), 0053824d(j)
//                              view.cpp:4278 (3)
//         0053827b     POP        EDI
//         0053827c     POP        ESI
//         0053827d     RET
//         0053827e     ??         90h
//         0053827f     NOP
    return;
}

void RGE_View::Add_GDI_Clip_Mask(DClipInfo_Node* param_1, TSpan_List_Manager* param_2) {
    /* TODO: Stub */
//                              void __thiscall Add_GDI_Clip_Mask(RGE_View * this, DClipInfo_Node *
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              DClipInfo_Node    Stack[0x4]:4   param_1                   XREF[5]:     00538286(R), 00538336(W), 00538348(R), 00538383(W),
//                                                                                     005383d2(R)
//              TSpan_List_Man    Stack[0x8]:4   param_2                   XREF[8]:     0053829f(R), 0053830d(R), 00538332(W), 0053834c(R),
//                                                                                     0053839f(W), 005383a5(W), 005383ab(R), 005383c7(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053838e(W), 005383e4(R)
//              int               Stack[-0x8]:4  xl2                       XREF[3]:     0053839b(W), 005383b9(R), 005383e0(R)
//              int               Stack[-0xc]:4  xr2
//                               ?Add_GDI_Clip_Mask@RGE_View@@IAEXPAUDClipInfo_Node@@PAVTSpa  XREF[2]:     view_function_terrain:00537dcc(c),
//                               RGE_View::Add_GDI_Clip_Mask                                               view_function_terrain:00537ea0(c)
//                              view.cpp:4281 (6)
//         00538280     SUB        ESP,0x8
//         00538283     PUSH       EBX
//         00538284     PUSH       EBP
//         00538285     PUSH       ESI
//                              view.cpp:4286 (13)
//         00538286     MOV        ESI,dword ptr [ESP + param_1]
//         0053828a     PUSH       EDI
//         0053828b     MOV        EAX,dword ptr [ESI + 0x2c]
//         0053828e     CMP        EAX,0x1
//         00538291     JNZ        LAB_0053830d
//                              view.cpp:4288 (31)
//         00538293     MOVSX      EAX,word ptr [ESI + 0x36]
//         00538297     MOVSX      this,word ptr [ESI + 0x34]
//         0053829b     MOVSX      EDX,word ptr [ESI + 0x32]
//         0053829f     MOV        EDI,dword ptr [ESP + param_2]
//         005382a3     PUSH       EAX
//         005382a4     MOVSX      EAX,word ptr [ESI + 0x30]
//         005382a8     PUSH       this
//         005382a9     PUSH       EDX
//         005382aa     PUSH       EAX
//         005382ab     MOV        this,EDI
//         005382ad     CALL       TSpan_List_Manager::AddLine_Align                void AddLine_Align(TSpan_List_Manager * this,
//                              view.cpp:4289 (27)
//         005382b2     MOVSX      this,word ptr [ESI + 0x3a]
//         005382b6     MOVSX      EDX,word ptr [ESI + 0x38]
//         005382ba     MOVSX      EAX,word ptr [ESI + 0x36]
//         005382be     PUSH       this
//         005382bf     PUSH       EDX
//         005382c0     MOVSX      this,word ptr [ESI + 0x34]
//         005382c4     PUSH       EAX
//         005382c5     PUSH       this
//         005382c6     MOV        this,EDI
//         005382c8     CALL       TSpan_List_Manager::AddLine_Align                void AddLine_Align(TSpan_List_Manager * this,
//                              view.cpp:4290 (27)
//         005382cd     MOVSX      EDX,word ptr [ESI + 0x3e]
//         005382d1     MOVSX      EAX,word ptr [ESI + 0x3c]
//         005382d5     MOVSX      this,word ptr [ESI + 0x3a]
//         005382d9     PUSH       EDX
//         005382da     PUSH       EAX
//         005382db     MOVSX      EDX,word ptr [ESI + 0x38]
//         005382df     PUSH       this
//         005382e0     PUSH       EDX
//         005382e1     MOV        this,EDI
//         005382e3     CALL       TSpan_List_Manager::AddLine_Align                void AddLine_Align(TSpan_List_Manager * this,
//                              view.cpp:4291 (27)
//         005382e8     MOVSX      EAX,word ptr [ESI + 0x32]
//         005382ec     MOVSX      this,word ptr [ESI + 0x30]
//         005382f0     MOVSX      EDX,word ptr [ESI + 0x3e]
//         005382f4     PUSH       EAX
//         005382f5     PUSH       this
//         005382f6     MOVSX      EAX,word ptr [ESI + 0x3c]
//         005382fa     PUSH       EDX
//         005382fb     PUSH       EAX
//         005382fc     MOV        this,EDI
//         005382fe     CALL       TSpan_List_Manager::AddLine_Align                void AddLine_Align(TSpan_List_Manager * this,
//                              view.cpp:4335 (10)
//         00538303     POP        EDI
//         00538304     POP        ESI
//         00538305     POP        EBP
//         00538306     POP        EBX
//         00538307     ADD        ESP,0x8
//         0053830a     RET        0x8
//                               LAB_0053830d                                                 XREF[1]:     00538291(j)
//                              view.cpp:4296 (14)
//         0053830d     MOV        EBX,dword ptr [ESP + param_2]
//         00538311     CMP        EAX,0x2
//         00538314     JZ         LAB_0053831b
//         00538316     CMP        EAX,0x3
//         00538319     JNZ        LAB_0053835f
//                               LAB_0053831b                                                 XREF[1]:     00538314(j)
//                              view.cpp:4298 (4)
//         0053831b     MOVSX      EAX,word ptr [ESI + 0x30]
//                              view.cpp:4299 (4)
//         0053831f     MOVSX      this,word ptr [ESI + 0x34]
//                              view.cpp:4301 (13)
//         00538323     MOVSX      EDI,word ptr [ESI + 0x32]
//         00538327     MOVSX      EBP,word ptr [ESI + 0x36]
//         0053832b     AND        AL,0xfc
//         0053832d     OR         this,0x3
//                              view.cpp:4302 (18)
//         00538330     CMP        EDI,EBP
//         00538332     MOV        dword ptr [ESP + param_2],EAX
//         00538336     MOV        dword ptr [ESP + param_1],this
//         0053833a     JLE        LAB_00538350
//         0053833c     MOV        EDX,EDI
//         0053833e     MOV        EDI,EBP
//         00538340     MOV        EBP,EDX
//                              view.cpp:4304 (14)
//         00538342     CMP        EDI,EBP
//         00538344     JG         LAB_0053835f
//         00538346     JMP        LAB_00538350
//                               LAB_00538348                                                 XREF[1]:     0053835d(j)
//         00538348     MOV        this,dword ptr [ESP + param_1]
//         0053834c     MOV        EAX,dword ptr [ESP + param_2]
//                               LAB_00538350                                                 XREF[2]:     0053833a(j), 00538346(j)
//                              view.cpp:4305 (15)
//         00538350     PUSH       EDI
//         00538351     PUSH       this
//         00538352     PUSH       EAX
//         00538353     MOV        this,EBX
//         00538355     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//         0053835a     INC        EDI
//         0053835b     CMP        EDI,EBP
//         0053835d     JLE        LAB_00538348
//                               LAB_0053835f                                                 XREF[2]:     00538319(j), 00538344(j)
//                              view.cpp:4308 (10)
//         0053835f     CMP        dword ptr [ESI + 0x2c],0x4
//         00538363     JNZ        LAB_005383f7
//                              view.cpp:4310 (4)
//         00538369     MOVSX      EAX,word ptr [ESI + 0x30]
//                              view.cpp:4311 (4)
//         0053836d     MOVSX      this,word ptr [ESI + 0x34]
//                              view.cpp:4312 (10)
//         00538371     CMP        EAX,this
//         00538373     JLE        LAB_0053837b
//         00538375     MOV        EDX,EAX
//         00538377     MOV        EAX,this
//         00538379     MOV        this,EDX
//                               LAB_0053837b                                                 XREF[1]:     00538373(j)
//                              view.cpp:4314 (2)
//         0053837b     MOV        EDI,EAX
//                              view.cpp:4315 (2)
//         0053837d     OR         AL,0x3
//                              view.cpp:4319 (26)
//         0053837f     MOVSX      EBP,word ptr [ESI + 0x36]
//         00538383     MOV        dword ptr [ESP + param_1],EAX
//         00538387     MOV        EAX,this
//         00538389     AND        AL,0xfc
//         0053838b     AND        EDI,0xfffffffc
//         0053838e     MOV        dword ptr [ESP + local_4],EAX
//         00538392     OR         this,0x3
//         00538395     MOVSX      EAX,word ptr [ESI + 0x32]
//                              view.cpp:4320 (22)
//         00538399     CMP        EAX,EBP
//         0053839b     MOV        dword ptr [ESP + xl2],this
//         0053839f     MOV        dword ptr [ESP + param_2],EAX
//         005383a3     JLE        LAB_005383af
//         005383a5     MOV        dword ptr [ESP + param_2],EBP
//         005383a9     MOV        EBP,EAX
//         005383ab     MOV        EAX,dword ptr [ESP + param_2]
//                               LAB_005383af                                                 XREF[1]:     005383a3(j)
//                              view.cpp:4322 (10)
//         005383af     PUSH       EAX
//         005383b0     PUSH       this
//         005383b1     PUSH       EDI
//         005383b2     MOV        this,EBX
//         005383b4     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//                              view.cpp:4323 (14)
//         005383b9     MOV        this,dword ptr [ESP + xl2]
//         005383bd     PUSH       EBP
//         005383be     PUSH       this
//         005383bf     PUSH       EDI
//         005383c0     MOV        this,EBX
//         005383c2     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//                              view.cpp:4325 (11)
//         005383c7     MOV        EDX,dword ptr [ESP + param_2]
//         005383cb     LEA        ESI,[EDX + 0x1]
//         005383ce     CMP        ESI,EBP
//         005383d0     JGE        LAB_005383f7
//                               LAB_005383d2                                                 XREF[1]:     005383f5(j)
//                              view.cpp:4327 (14)
//         005383d2     MOV        EAX,dword ptr [ESP + param_1]
//         005383d6     PUSH       ESI
//         005383d7     PUSH       EAX
//         005383d8     PUSH       EDI
//         005383d9     MOV        this,EBX
//         005383db     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//                              view.cpp:4328 (23)
//         005383e0     MOV        this,dword ptr [ESP + xl2]
//         005383e4     MOV        EDX,dword ptr [ESP + local_4]
//         005383e8     PUSH       ESI
//         005383e9     PUSH       this
//         005383ea     PUSH       EDX
//         005383eb     MOV        this,EBX
//         005383ed     CALL       TSpan_List_Manager::AddSpan                      void AddSpan(TSpan_List_Manager * this, int p
//         005383f2     INC        ESI
//         005383f3     CMP        ESI,EBP
//         005383f5     JL         LAB_005383d2
//                               LAB_005383f7                                                 XREF[2]:     00538363(j), 005383d0(j)
//                              view.cpp:4335 (10)
//         005383f7     POP        EDI
//         005383f8     POP        ESI
//         005383f9     POP        EBP
//         005383fa     POP        EBX
//         005383fb     ADD        ESP,0x8
//         005383fe     RET        0x8
//         00538401     ??         90h
//         00538402     NOP
//         00538403     NOP
//         00538404     NOP
//         00538405     NOP
//         00538406     NOP
//         00538407     NOP
//         00538408     NOP
//         00538409     NOP
//         0053840a     NOP
//         0053840b     NOP
//         0053840c     NOP
//         0053840d     NOP
//         0053840e     NOP
//         0053840f     NOP
    return;
}

void RGE_View::draw_multi_object_outline() {
    /* TODO: Stub */
//                              void __thiscall draw_multi_object_outline(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?draw_multi_object_outline@RGE_View@@UAEXXZ                  XREF[1]:     005776b0(*)
//                               RGE_View::draw_multi_object_outline
//                              view.cpp:4342 (1)
//         00538410     RET
//         00538411     ??         90h
//         00538412     NOP
//         00538413     NOP
//         00538414     NOP
//         00538415     NOP
//         00538416     NOP
//         00538417     NOP
//         00538418     NOP
//         00538419     NOP
//         0053841a     NOP
//         0053841b     NOP
//         0053841c     NOP
//         0053841d     NOP
//         0053841e     NOP
//         0053841f     NOP
    return;
}

void RGE_View::Draw_GDI_Object(DClipInfo_Node* param_1, TDrawArea* param_2) {
    /* TODO: Stub */
//                              void __thiscall Draw_GDI_Object(RGE_View * this, DClipInfo_Node * pa
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              DClipInfo_Node    Stack[0x4]:4   param_1                   XREF[1]:     00538422(R)
//              TDrawArea *       Stack[0x8]:4   param_2                   XREF[2]:     0053843a(R), 005384b9(R)
//                               ?Draw_GDI_Object@RGE_View@@IAEXPAUDClipInfo_Node@@PAVTDrawA  XREF[1]:     view_function_terrain:005380ac(c)
//                               RGE_View::Draw_GDI_Object
//                              view.cpp:4347 (2)
//         00538420     PUSH       EBX
//         00538421     PUSH       ESI
//                              view.cpp:4355 (17)
//         00538422     MOV        ESI,dword ptr [ESP + param_1]
//         00538426     PUSH       EDI
//         00538427     MOV        EAX,dword ptr [ESI + 0x2c]
//         0053842a     CMP        EAX,0x1
//         0053842d     JNZ        LAB_005384b9
//                              view.cpp:4357 (35)
//         00538433     MOVSX      this,word ptr [ESI + 0x36]
//         00538437     MOV        AL,byte ptr [ESI + 0x1c]
//         0053843a     MOV        EDI,dword ptr [ESP + param_2]
//         0053843e     MOVSX      EDX,word ptr [ESI + 0x34]
//         00538442     PUSH       EAX
//         00538443     PUSH       this
//         00538444     MOVSX      EAX,word ptr [ESI + 0x32]
//         00538448     MOVSX      this,word ptr [ESI + 0x30]
//         0053844c     PUSH       EDX
//         0053844d     PUSH       EAX
//         0053844e     PUSH       this
//         0053844f     MOV        this,EDI
//         00538451     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4358 (31)
//         00538456     MOVSX      EAX,word ptr [ESI + 0x3a]
//         0053845a     MOV        DL,byte ptr [ESI + 0x1c]
//         0053845d     MOVSX      this,word ptr [ESI + 0x38]
//         00538461     PUSH       EDX
//         00538462     PUSH       EAX
//         00538463     MOVSX      EDX,word ptr [ESI + 0x36]
//         00538467     MOVSX      EAX,word ptr [ESI + 0x34]
//         0053846b     PUSH       this
//         0053846c     PUSH       EDX
//         0053846d     PUSH       EAX
//         0053846e     MOV        this,EDI
//         00538470     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4359 (31)
//         00538475     MOVSX      EDX,word ptr [ESI + 0x3e]
//         00538479     MOV        this,byte ptr [ESI + 0x1c]
//         0053847c     MOVSX      EAX,word ptr [ESI + 0x3c]
//         00538480     PUSH       this
//         00538481     PUSH       EDX
//         00538482     MOVSX      this,word ptr [ESI + 0x3a]
//         00538486     MOVSX      EDX,word ptr [ESI + 0x38]
//         0053848a     PUSH       EAX
//         0053848b     PUSH       this
//         0053848c     PUSH       EDX
//         0053848d     MOV        this,EDI
//         0053848f     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4360 (26)
//         00538494     MOVSX      this,word ptr [ESI + 0x32]
//         00538498     MOV        AL,byte ptr [ESI + 0x1c]
//         0053849b     MOVSX      EDX,word ptr [ESI + 0x30]
//         0053849f     PUSH       EAX
//         005384a0     PUSH       this
//         005384a1     MOVSX      EAX,word ptr [ESI + 0x3e]
//         005384a5     MOVSX      this,word ptr [ESI + 0x3c]
//         005384a9     PUSH       EDX
//         005384aa     PUSH       EAX
//         005384ab     PUSH       this
//         005384ac     MOV        this,EDI
//                              view.cpp:4383 (5)
//         005384ae     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4387 (6)
//         005384b3     POP        EDI
//         005384b4     POP        ESI
//         005384b5     POP        EBX
//         005384b6     RET        0x8
//                               LAB_005384b9                                                 XREF[1]:     0053842d(j)
//                              view.cpp:4365 (9)
//         005384b9     MOV        EBX,dword ptr [ESP + param_2]
//         005384bd     CMP        EAX,0x2
//         005384c0     JNZ        LAB_00538512
//                              view.cpp:4370 (12)
//         005384c2     MOVSX      EDI,word ptr [ESI + 0x32]
//         005384c6     MOVSX      EDX,word ptr [ESI + 0x36]
//         005384ca     CMP        EDI,EDX
//         005384cc     JG         LAB_00538512
//                               LAB_005384ce                                                 XREF[1]:     00538510(j)
//                              view.cpp:4372 (28)
//         005384ce     CMP        word ptr [ESI + 0x3a],0x0
//         005384d3     JZ         LAB_005384ea
//         005384d5     MOVSX      EAX,word ptr [ESI + 0x38]
//         005384d9     MOVSX      this,word ptr [ESI + 0x30]
//         005384dd     PUSH       0x4a
//         005384df     PUSH       EDI
//         005384e0     PUSH       EAX
//         005384e1     PUSH       EDI
//         005384e2     PUSH       this
//         005384e3     MOV        this,EBX
//         005384e5     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                               LAB_005384ea                                                 XREF[1]:     005384d3(j)
//                              view.cpp:4373 (40)
//         005384ea     CMP        word ptr [ESI + 0x3e],0x0
//         005384ef     JZ         LAB_00538509
//         005384f1     MOVSX      EDX,word ptr [ESI + 0x34]
//         005384f5     MOVSX      EAX,word ptr [ESI + 0x3c]
//         005384f9     PUSH       0x97
//         005384fe     PUSH       EDI
//         005384ff     PUSH       EDX
//         00538500     PUSH       EDI
//         00538501     PUSH       EAX
//         00538502     MOV        this,EBX
//         00538504     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                               LAB_00538509                                                 XREF[1]:     005384ef(j)
//         00538509     MOVSX      this,word ptr [ESI + 0x36]
//         0053850d     INC        EDI
//         0053850e     CMP        EDI,this
//         00538510     JLE        LAB_005384ce
//                               LAB_00538512                                                 XREF[2]:     005384c0(j), 005384cc(j)
//                              view.cpp:4378 (6)
//         00538512     CMP        dword ptr [ESI + 0x2c],0x4
//         00538516     JNZ        LAB_00538588
//                              view.cpp:4380 (28)
//         00538518     MOVSX      EAX,word ptr [ESI + 0x32]
//         0053851c     MOVSX      EDX,word ptr [ESI + 0x34]
//         00538520     PUSH       0xff
//         00538525     PUSH       EAX
//         00538526     PUSH       EDX
//         00538527     PUSH       EAX
//         00538528     MOVSX      EAX,word ptr [ESI + 0x30]
//         0053852c     PUSH       EAX
//         0053852d     MOV        this,EBX
//         0053852f     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4381 (28)
//         00538534     MOVSX      EAX,word ptr [ESI + 0x36]
//         00538538     MOVSX      this,word ptr [ESI + 0x34]
//         0053853c     MOVSX      EDX,word ptr [ESI + 0x30]
//         00538540     PUSH       0xff
//         00538545     PUSH       EAX
//         00538546     PUSH       this
//         00538547     PUSH       EAX
//         00538548     PUSH       EDX
//         00538549     MOV        this,EBX
//         0053854b     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4382 (28)
//         00538550     MOVSX      this,word ptr [ESI + 0x36]
//         00538554     MOVSX      EAX,word ptr [ESI + 0x30]
//         00538558     MOVSX      EDX,word ptr [ESI + 0x32]
//         0053855c     PUSH       0xff
//         00538561     PUSH       this
//         00538562     PUSH       EAX
//         00538563     PUSH       EDX
//         00538564     PUSH       EAX
//         00538565     MOV        this,EBX
//         00538567     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                              view.cpp:4383 (28)
//         0053856c     MOVSX      this,word ptr [ESI + 0x36]
//         00538570     MOVSX      EAX,word ptr [ESI + 0x34]
//         00538574     MOVSX      EDX,word ptr [ESI + 0x32]
//         00538578     PUSH       0xff
//         0053857d     PUSH       this
//         0053857e     PUSH       EAX
//         0053857f     PUSH       EDX
//         00538580     PUSH       EAX
//         00538581     MOV        this,EBX
//         00538583     CALL       TDrawArea::DrawLine                              void DrawLine(TDrawArea * this, int param_1,
//                               LAB_00538588                                                 XREF[1]:     00538516(j)
//                              view.cpp:4387 (6)
//         00538588     POP        EDI
//         00538589     POP        ESI
//         0053858a     POP        EBX
//         0053858b     RET        0x8
//         0053858e     ??         90h
//         0053858f     NOP
    return;
}

int RGE_View::get_tile_mask_num(int param_1, int param_2, int param_3, int param_4, ulong param_5) {
    /* TODO: Stub */
//                              int __thiscall get_tile_mask_num(RGE_View * this, int param_1, int p
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00538591(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00538595(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     005385a7(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053859a(R)
//              ulong             Stack[0x14]:4  param_5                   XREF[2]:     005385d0(R), 0053863f(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0053859e(W), 005386f9(R)
//                               ?get_tile_mask_num@RGE_View@@IAEHHHHHK@Z                     XREF[4]:     view_function_terrain:00536e66(c),
//                               RGE_View::get_tile_mask_num                                               view_function_terrain:00536eb1(c),
//                                                                                                         view_function_terrain:00536fdc(c),
//                                                                                                         view_function_terrain:00537017(c)
//                              view.cpp:4394 (1)
//         00538590     PUSH       this
//                              view.cpp:4398 (56)
//         00538591     MOV        EAX,dword ptr [ESP + param_1]
//         00538595     MOV        EDX,dword ptr [ESP + param_2]
//         00538599     PUSH       EBX
//         0053859a     MOV        EBX,dword ptr [ESP + param_4]
//         0053859e     MOV        dword ptr [ESP + local_4],this
//         005385a2     PUSH       EBP
//         005385a3     PUSH       ESI
//         005385a4     XOR        this,this
//         005385a6     PUSH       EDI
//         005385a7     MOV        EDI,dword ptr [ESP + param_3]
//         005385ab     TEST       EAX,EAX
//         005385ad     JLE        LAB_0053863f
//         005385b3     TEST       EDX,EDX
//         005385b5     JLE        LAB_0053863f
//         005385bb     LEA        ESI,[EDI + -0x1]
//         005385be     CMP        EAX,ESI
//         005385c0     JGE        LAB_0053863f
//         005385c2     LEA        ESI,[EBX + -0x1]
//         005385c5     CMP        EDX,ESI
//         005385c7     JGE        LAB_0053863f
//                              view.cpp:4400 (29)
//         005385c9     MOV        EBP,dword ptr [EDX*0x4 + null_00886804]          = align(4)
//         005385d0     MOV        ESI,dword ptr [ESP + param_5]
//         005385d4     LEA        EDI,[EAX*0x4 + 0x0]
//         005385db     TEST       dword ptr [EBP + EDI*0x1],ESI
//         005385df     JNZ        LAB_005385e6
//         005385e1     MOV        this,0x80
//                               LAB_005385e6                                                 XREF[1]:     005385df(j)
//                              view.cpp:4401 (22)
//         005385e6     MOV        EBX,dword ptr [EDX*0x4 + unified_map_offsets]    = 00000000
//         005385ed     LEA        EAX,[EAX*0x4 + 0x4]
//         005385f4     TEST       dword ptr [EBX + EAX*0x1],ESI
//         005385f7     JNZ        LAB_005385fc
//         005385f9     OR         this,0x40
//                               LAB_005385fc                                                 XREF[1]:     005385f7(j)
//                              view.cpp:4402 (15)
//         005385fc     MOV        EDX,dword ptr [EDX*0x4 + DAT_0088680c]
//         00538603     TEST       dword ptr [EDX + EDI*0x1],ESI
//         00538606     JNZ        LAB_0053860b
//         00538608     OR         this,0x20
//                               LAB_0053860b                                                 XREF[1]:     00538606(j)
//                              view.cpp:4403 (9)
//         0053860b     TEST       dword ptr [EBX + EDI*0x1 + -0x4],ESI
//         0053860f     JNZ        LAB_00538614
//         00538611     OR         this,0x10
//                               LAB_00538614                                                 XREF[1]:     0053860f(j)
//                              view.cpp:4404 (8)
//         00538614     TEST       dword ptr [EAX + EBP*0x1],ESI
//         00538617     JNZ        LAB_0053861c
//         00538619     OR         this,0x8
//                               LAB_0053861c                                                 XREF[1]:     00538617(j)
//                              view.cpp:4405 (8)
//         0053861c     TEST       dword ptr [EDX + EAX*0x1],ESI
//         0053861f     JNZ        LAB_00538624
//         00538621     OR         this,0x4
//                               LAB_00538624                                                 XREF[1]:     0053861f(j)
//                              view.cpp:4406 (9)
//         00538624     TEST       dword ptr [EDX + EDI*0x1 + -0x4],ESI
//         00538628     JNZ        LAB_0053862d
//         0053862a     OR         this,0x2
//                               LAB_0053862d                                                 XREF[1]:     00538628(j)
//                              view.cpp:4407 (13)
//         0053862d     TEST       dword ptr [EBP + EDI*0x1 + -0x4],ESI
//         00538631     JNZ        LAB_005386f9
//         00538637     OR         this,0x1
//                              view.cpp:4409 (5)
//         0053863a     JMP        LAB_005386f9
//                               LAB_0053863f                                                 XREF[4]:     005385ad(j), 005385b5(j),
//                                                                                                         005385c0(j), 005385c7(j)
//                              view.cpp:4411 (8)
//         0053863f     MOV        ESI,dword ptr [ESP + param_5]
//         00538643     TEST       EAX,EAX
//         00538645     JLE        LAB_00538659
//                              view.cpp:4412 (18)
//         00538647     MOV        EBP,dword ptr [EDX*0x4 + unified_map_offsets]    = 00000000
//         0053864e     TEST       dword ptr [EBP + EAX*0x4 + -0x4],ESI
//         00538652     JNZ        LAB_00538659
//         00538654     MOV        this,0x10
//                               LAB_00538659                                                 XREF[2]:     00538645(j), 00538652(j)
//                              view.cpp:4414 (7)
//         00538659     LEA        EBP,[EDI + -0x1]
//         0053865c     CMP        EAX,EBP
//         0053865e     JGE        LAB_00538670
//                              view.cpp:4415 (16)
//         00538660     MOV        EDI,dword ptr [EDX*0x4 + unified_map_offsets]    = 00000000
//         00538667     TEST       dword ptr [EDI + EAX*0x4 + 0x4],ESI
//         0053866b     JNZ        LAB_00538670
//         0053866d     OR         this,0x40
//                               LAB_00538670                                                 XREF[2]:     0053865e(j), 0053866b(j)
//                              view.cpp:4417 (4)
//         00538670     TEST       EDX,EDX
//         00538672     JLE        LAB_00538683
//                              view.cpp:4418 (15)
//         00538674     MOV        EDI,dword ptr [EDX*0x4 + null_00886804]          = align(4)
//         0053867b     TEST       dword ptr [EDI + EAX*0x4],ESI
//         0053867e     JNZ        LAB_00538683
//         00538680     OR         this,0x80
//                               LAB_00538683                                                 XREF[2]:     00538672(j), 0053867e(j)
//                              view.cpp:4420 (7)
//         00538683     LEA        EDI,[EBX + -0x1]
//         00538686     CMP        EDX,EDI
//         00538688     JGE        LAB_00538699
//                              view.cpp:4421 (15)
//         0053868a     MOV        EBX,dword ptr [EDX*0x4 + DAT_0088680c]
//         00538691     TEST       dword ptr [EBX + EAX*0x4],ESI
//         00538694     JNZ        LAB_00538699
//         00538696     OR         this,0x20
//                               LAB_00538699                                                 XREF[2]:     00538688(j), 00538694(j)
//                              view.cpp:4423 (8)
//         00538699     TEST       EAX,EAX
//         0053869b     JLE        LAB_005386c9
//         0053869d     TEST       EDX,EDX
//         0053869f     JLE        LAB_005386b1
//                              view.cpp:4424 (16)
//         005386a1     MOV        EBX,dword ptr [EDX*0x4 + null_00886804]          = align(4)
//         005386a8     TEST       dword ptr [EBX + EAX*0x4 + -0x4],ESI
//         005386ac     JNZ        LAB_005386b1
//         005386ae     OR         this,0x1
//                               LAB_005386b1                                                 XREF[2]:     0053869f(j), 005386ac(j)
//                              view.cpp:4426 (8)
//         005386b1     TEST       EAX,EAX
//         005386b3     JLE        LAB_005386c9
//         005386b5     CMP        EDX,EDI
//         005386b7     JGE        LAB_005386c9
//                              view.cpp:4427 (16)
//         005386b9     MOV        EBX,dword ptr [EDX*0x4 + DAT_0088680c]
//         005386c0     TEST       dword ptr [EBX + EAX*0x4 + -0x4],ESI
//         005386c4     JNZ        LAB_005386c9
//         005386c6     OR         this,0x2
//                               LAB_005386c9                                                 XREF[4]:     0053869b(j), 005386b3(j),
//                                                                                                         005386b7(j), 005386c4(j)
//                              view.cpp:4429 (8)
//         005386c9     CMP        EAX,EBP
//         005386cb     JGE        LAB_005386f9
//         005386cd     TEST       EDX,EDX
//         005386cf     JLE        LAB_005386e1
//                              view.cpp:4430 (16)
//         005386d1     MOV        EBX,dword ptr [EDX*0x4 + null_00886804]          = align(4)
//         005386d8     TEST       dword ptr [EBX + EAX*0x4 + 0x4],ESI
//         005386dc     JNZ        LAB_005386e1
//         005386de     OR         this,0x8
//                               LAB_005386e1                                                 XREF[2]:     005386cf(j), 005386dc(j)
//                              view.cpp:4432 (8)
//         005386e1     CMP        EAX,EBP
//         005386e3     JGE        LAB_005386f9
//         005386e5     CMP        EDX,EDI
//         005386e7     JGE        LAB_005386f9
//                              view.cpp:4433 (16)
//         005386e9     MOV        EDX,dword ptr [EDX*0x4 + DAT_0088680c]
//         005386f0     TEST       dword ptr [EDX + EAX*0x4 + 0x4],ESI
//         005386f4     JNZ        LAB_005386f9
//         005386f6     OR         this,0x4
//                               LAB_005386f9                                                 XREF[6]:     00538631(j), 0053863a(j),
//                                                                                                         005386cb(j), 005386e3(j),
//                                                                                                         005386e7(j), 005386f4(j)
//                              view.cpp:4437 (4)
//         005386f9     MOV        EDX,dword ptr [ESP + local_4]
//                              view.cpp:4439 (17)
//         005386fd     POP        EDI
//         005386fe     XOR        EAX,EAX
//         00538700     POP        ESI
//         00538701     MOV        AL,byte ptr [ECX + EDX*0x1 + this->EdgeNumber[
//         00538708     POP        EBP
//         00538709     POP        EBX
//         0053870a     POP        this
//         0053870b     RET        0x14
//         0053870e     ??         90h
//         0053870f     NOP
    return 0;
}

int RGE_View::draw_tile(RGE_Tile* param_1, uchar param_2, short param_3, short param_4, short param_5, short param_6, uchar param_7, int param_8, int param_9) {
    /* TODO: Stub */
//                              int __thiscall draw_tile(RGE_View * this, RGE_Tile * param_1, uchar
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Tile *        Stack[0x4]:4   param_1                   XREF[4]:     00538714(R), 005388b0(R), 005389e5(R), 00538a42(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[2]:     0053871f(R), 005388bd(R)
//              short             Stack[0xc]:2   param_3                   XREF[7]:     005388f2(R), 00538925(R), 00538a1b(R), 00538a77(R),
//                                                                                     00538aa8(R), 00538acb(R), 00538afc(R)
//              short             Stack[0x10]:2  param_4                   XREF[7]:     005388ed(R), 00538920(R), 00538a16(R), 00538a7e(R),
//                                                                                     00538aa1(R), 00538ad2(R), 00538af5(R)
//              short             Stack[0x14]:2  param_5                   XREF[8]:     005387cc(R), 0053881d(R), 00538855(R), 005388b4(R),
//                                                                                     005388e3(R), 00538941(R), 0053899c(R), 00538b0a(R)
//              short             Stack[0x18]:2  param_6                   XREF[11]:    005387c8(R), 00538818(R), 0053885f(R), 005388a5(R),
//                                                                                     005388de(R), 00538954(R), 00538976(R), 005389e0(R),
//                                                                                     00538a3d(R), 00538b19(R), 00538b3b(R)
//              uchar             Stack[0x1c]:1  param_7                   XREF[6]:     00538915(R), 00538a0b(R), 00538a6f(R), 00538a99(R),
//                                                                                     00538ac3(R), 00538aed(R)
//              int               Stack[0x20]:4  param_8                   XREF[1]:     0053888f(R)
//              int               Stack[0x24]:4  param_9                   XREF[1]:     0053888b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00538753(W), 005388a1(R)
//              undefined4        Stack[-0x8]:4  local_8                   XREF[3]:     00538770(W), 00538935(W), 00538b65(R)
//              int               Stack[-0xc]:4  retval                    XREF[3]:     00538805(*), 00538a29(*), 00538ae0(R)
//              int               Stack[-0x10]:4 bottom_index              XREF[3]:     0053880f(*), 00538a33(*), 00538ab6(R)
//              int               Stack[-0x14]:4 right_index               XREF[3]:     00538809(*), 00538a2e(*), 00538a8c(R)
//              int               Stack[-0x18]:4 left_index                XREF[3]:     00538813(*), 00538a38(*), 00538a62(R)
//              int               Stack[-0x1c]:4 top_index                 XREF[3]:     00538780(W), 0053878a(R), 005389ac(R)
//              uchar             Stack[-0x20]:1 border_type               XREF[4]:     00538768(W), 005387ff(W), 00538840(W), 00538887(R)
//              int               Stack[-0x24]:4 draw_terrain              XREF[6]:     00538774(W), 005387f0(W), 0053883c(W), 0053887f(W),
//                                                                                     0053893d(R), 005389a0(R)
//              int               Stack[-0x28]:4 draw_border               XREF[9]:     00538723(W), 0053884e(R), 00538871(RW), 00538911(R),
//                                                                                     00538a07(R), 00538a6b(R), 00538a95(R), 00538abf(R),
//                                                                                     00538ae9(R)
//              uchar             Stack[-0x2c]:1 draw_attribute
//                               ?draw_tile@RGE_View@@IAEHPAURGE_Tile@@EFFFFEHH@Z             XREF[2]:     view_function_terrain:00537387(c),
//                               RGE_View::draw_tile                                                       view_function_terrain:005373fc(c)
//                              view.cpp:4447 (4)
//         00538710     SUB        ESP,0x28
//         00538713     PUSH       EBX
//                              view.cpp:4455 (11)
//         00538714     MOV        EBX,dword ptr [ESP + param_1]
//         00538718     PUSH       EBP
//         00538719     PUSH       ESI
//         0053871a     MOV        AL,byte ptr [EBX + 0xa]
//         0053871d     MOV        ESI,this
//                              view.cpp:4460 (71)
//         0053871f     MOV        this,dword ptr [ESP + param_2]
//         00538723     MOV        byte ptr [ESP + draw_border],AL
//         00538727     MOV        EDX,dword ptr [ESI + 0x104]
//         0053872d     XOR        AX,AX
//         00538730     MOV        AL,this
//         00538732     PUSH       EDI
//         00538733     CMP        AX,word ptr [EDX + 0x8d90]
//         0053873a     JGE        LAB_00538b73
//         00538740     AND        this,0xff
//         00538746     MOV        EAX,this
//         00538748     SHL        EAX,0x4
//         0053874b     ADD        EAX,this
//         0053874d     LEA        EAX,[EAX + EAX*0x2]
//         00538750     SHL        EAX,0x3
//         00538753     MOV        dword ptr [ESP + local_4],EAX
//         00538757     MOV        this,byte ptr [EAX + EDX*0x1 + 0x8c]
//         0053875e     TEST       this,this
//         00538760     JZ         LAB_00538b73
//                              view.cpp:4466 (2)
//         00538766     XOR        EAX,EAX
//                              view.cpp:4469 (12)
//         00538768     MOV        dword ptr [ESP + border_type],0x1
//         00538770     MOV        dword ptr [ESP + local_8],EAX
//                              view.cpp:4470 (4)
//         00538774     MOV        dword ptr [ESP + draw_terrain],EAX
//                              view.cpp:4472 (12)
//         00538778     MOV        AL,byte ptr [EBX + 0x6]
//         0053877b     MOV        this,AL
//         0053877d     AND        this,0xf
//         00538780     MOV        byte ptr [ESP + top_index],this
//                              view.cpp:4473 (42)
//         00538784     JZ         LAB_00538844
//         0053878a     MOV        EBP,dword ptr [ESP + top_index]
//         0053878e     MOV        this,EBP
//         00538790     AND        this,0xff
//         00538796     LEA        this,[ECX + ECX*0x4]
//         00538799     LEA        EDI,[ECX + ECX*0x8]
//         0053879c     SHL        EDI,0x5
//         0053879f     MOV        this,byte ptr [EDI + EDX*0x1 + 0x338c]
//         005387a6     TEST       this,this
//         005387a8     JZ         LAB_00538844
//                              view.cpp:4476 (15)
//         005387ae     MOV        this,dword ptr [EDI + EDX*0x1 + 0x33ac]
//         005387b5     TEST       this,this
//         005387b7     JZ         LAB_00538844
//                              view.cpp:4478 (11)
//         005387bd     CMP        word ptr [EDI + EDX*0x1 + 0x392a],0x0
//         005387c6     JNZ        LAB_00538805
//                              view.cpp:4480 (26)
//         005387c8     MOV        EDX,dword ptr [ESP + param_6]
//         005387cc     MOV        this,dword ptr [ESP + param_5]
//         005387d0     PUSH       EDX
//         005387d1     MOV        DL,byte ptr [EBX + 0x4]
//         005387d4     SHR        AL,0x4
//         005387d7     PUSH       this
//         005387d8     PUSH       EAX
//         005387d9     PUSH       EDX
//         005387da     PUSH       EBP
//         005387db     MOV        this,ESI
//         005387dd     CALL       RGE_View::get_border_picture                     short get_border_picture(RGE_View * this, uch
//                              view.cpp:4481 (6)
//         005387e2     CMP        AX,0xffff
//         005387e6     JZ         LAB_00538844
//                              view.cpp:4484 (27)
//         005387e8     MOV        EAX,dword ptr [ESI + 0x104]
//         005387ee     XOR        this,this
//         005387f0     MOV        dword ptr [ESP + draw_terrain],0x1
//         005387f8     MOV        this,byte ptr [EDI + EAX*0x1 + 0x3926]
//         005387ff     MOV        dword ptr [ESP + border_type],this
//                              view.cpp:4487 (2)
//         00538803     JMP        LAB_00538844
//                               LAB_00538805                                                 XREF[1]:     005387c6(j)
//                              view.cpp:4489 (50)
//         00538805     LEA        EDX=>retval,[ESP + 0x2c]
//         00538809     LEA        this=>right_index,[ESP + 0x24]
//         0053880d     PUSH       EDX
//         0053880e     PUSH       this
//         0053880f     LEA        EDX=>bottom_index,[ESP + 0x30]
//         00538813     LEA        this=>left_index,[ESP + 0x28]
//         00538817     PUSH       EDX
//         00538818     MOV        EDX,dword ptr [ESP + param_6]
//         0053881c     PUSH       this
//         0053881d     MOV        this,dword ptr [ESP + param_5]
//         00538821     PUSH       EDX
//         00538822     MOV        DL,byte ptr [EBX + 0x4]
//         00538825     SHR        AL,0x4
//         00538828     PUSH       this
//         00538829     PUSH       EAX
//         0053882a     PUSH       EDX
//         0053882b     PUSH       EBP
//         0053882c     MOV        this,ESI
//         0053882e     CALL       RGE_View::get_border_edge_pictures               int get_border_edge_pictures(RGE_View * this,
//         00538833     TEST       EAX,EAX
//         00538835     JZ         LAB_00538844
//                              view.cpp:4491 (9)
//         00538837     MOV        EAX,0x1
//         0053883c     MOV        dword ptr [ESP + draw_terrain],EAX
//                              view.cpp:4492 (4)
//         00538840     MOV        dword ptr [ESP + border_type],EAX
//                               LAB_00538844                                                 XREF[6]:     00538784(j), 005387a8(j),
//                                                                                                         005387b7(j), 005387e6(j),
//                                                                                                         00538803(j), 00538835(j)
//                              view.cpp:4501 (17)
//         00538844     MOV        EDI,dword ptr [View_Grid_Mode]
//         0053884a     TEST       EDI,EDI
//         0053884c     JLE        LAB_00538876
//         0053884e     TEST       byte ptr [ESP + draw_border],0xdf
//         00538853     JNZ        LAB_00538876
//                              view.cpp:4511 (33)
//         00538855     MOVSX      EAX,word ptr [ESP + param_5]
//         0053885a     CDQ
//         0053885b     IDIV       EDI
//         0053885d     MOV        this,EAX
//         0053885f     MOVSX      EAX,word ptr [ESP + param_6]
//         00538864     CDQ
//         00538865     IDIV       EDI
//         00538867     ADD        this,EAX
//         00538869     AND        this,0x1
//         0053886c     CMP        this,0x1
//         0053886f     JNZ        LAB_00538876
//         00538871     OR         byte ptr [ESP + draw_border],0x20
//                               LAB_00538876                                                 XREF[3]:     0053884c(j), 00538853(j),
//                                                                                                         0053886f(j)
//                              view.cpp:4516 (17)
//         00538876     MOV        EAX,[view_debug_ObstructionMap]
//         0053887b     TEST       EAX,EAX
//         0053887d     JZ         LAB_00538887
//         0053887f     MOV        dword ptr [ESP + draw_terrain],0x0
//                               LAB_00538887                                                 XREF[1]:     0053887d(j)
//                              view.cpp:4521 (20)
//         00538887     MOV        EAX,dword ptr [ESP + border_type]
//         0053888b     MOV        EBP,dword ptr [ESP + param_9]
//         0053888f     MOV        EBX,dword ptr [ESP + param_8]
//         00538893     TEST       EAX,EAX
//         00538895     JZ         LAB_0053899c
//                              view.cpp:4523 (10)
//         0053889b     MOV        EDX,dword ptr [ESI + 0x104]
//         005388a1     MOV        EAX,dword ptr [ESP + local_4]
//                              view.cpp:4524 (37)
//         005388a5     MOV        this,dword ptr [ESP + param_6]
//         005388a9     MOV        EDI,dword ptr [EAX + EDX*0x1 + 0xac]
//         005388b0     MOV        EAX,dword ptr [ESP + param_1]
//         005388b4     MOV        EDX,dword ptr [ESP + param_5]
//         005388b8     PUSH       this
//         005388b9     MOV        this,byte ptr [EAX + 0x4]
//         005388bc     PUSH       EDX
//         005388bd     MOV        EDX,dword ptr [ESP + param_2]
//         005388c1     PUSH       this
//         005388c2     PUSH       EDX
//         005388c3     MOV        this,ESI
//         005388c5     CALL       RGE_View::get_tile_picture                       short get_tile_picture(RGE_View * this, uchar
//                              view.cpp:4525 (10)
//         005388ca     TEST       EDI,EDI
//         005388cc     JZ         LAB_0053893d
//         005388ce     CMP        AX,0xffff
//         005388d2     JZ         LAB_0053893d
//                              view.cpp:4528 (10)
//         005388d4     MOV        this,dword ptr [view_debug_ObstructionMap]
//         005388da     TEST       this,this
//         005388dc     JZ         LAB_00538911
//                              view.cpp:4530 (36)
//         005388de     MOVSX      this,word ptr [ESP + param_6]
//         005388e3     MOVSX      EDX,word ptr [ESP + param_5]
//         005388e8     MOVSX      EAX,AX
//         005388eb     PUSH       this
//         005388ec     PUSH       EDX
//         005388ed     MOVSX      this,word ptr [ESP + param_4]
//         005388f2     MOVSX      EDX,word ptr [ESP + param_3]
//         005388f7     PUSH       EAX
//         005388f8     PUSH       EDI
//         005388f9     PUSH       this
//         005388fa     PUSH       EDX
//         005388fb     MOV        this,ESI
//         005388fd     CALL       RGE_View::draw_terrain_obstruction_map           void draw_terrain_obstruction_map(RGE_View *
//                              view.cpp:4531 (5)
//         00538902     MOV        EAX,0x1
//                              view.cpp:4600 (10)
//         00538907     POP        EDI
//         00538908     POP        ESI
//         00538909     POP        EBP
//         0053890a     POP        EBX
//         0053890b     ADD        ESP,0x28
//         0053890e     RET        0x24
//                               LAB_00538911                                                 XREF[1]:     005388dc(j)
//                              view.cpp:4535 (36)
//         00538911     MOV        this,dword ptr [ESP + draw_border]
//         00538915     MOV        EDX,dword ptr [ESP + param_7]
//         00538919     PUSH       EBP
//         0053891a     PUSH       EBX
//         0053891b     MOVSX      EAX,AX
//         0053891e     PUSH       this
//         0053891f     PUSH       EDX
//         00538920     MOVSX      this,word ptr [ESP + param_4]
//         00538925     MOVSX      EDX,word ptr [ESP + param_3]
//         0053892a     PUSH       EAX
//         0053892b     PUSH       EDI
//         0053892c     PUSH       this
//         0053892d     PUSH       EDX
//         0053892e     MOV        this,ESI
//         00538930     CALL       RGE_View::draw_terrain_shape                     void draw_terrain_shape(RGE_View * this, int
//                              view.cpp:4536 (8)
//         00538935     MOV        dword ptr [ESP + local_8],0x1
//                               LAB_0053893d                                                 XREF[2]:     005388cc(j), 005388d2(j)
//                              view.cpp:4539 (4)
//         0053893d     MOV        EAX,dword ptr [ESP + draw_terrain]
//                              view.cpp:4543 (13)
//         00538941     MOV        this,dword ptr [ESP + param_5]
//         00538945     TEST       EAX,EAX
//         00538947     JNZ        LAB_005389a0
//         00538949     TEST       this,this
//         0053894c     JLE        LAB_00538970
//                              view.cpp:4545 (30)
//         0053894e     MOV        EAX,dword ptr [ESI + 0x104]
//         00538954     MOVSX      EDX,word ptr [ESP + param_6]
//         00538959     MOV        EDI,dword ptr [EAX + 0x8d8c]
//         0053895f     MOVSX      EAX,this
//         00538962     MOV        EDX,dword ptr [EDI + EDX*0x4]
//         00538965     LEA        EAX,[EAX + EAX*0x2]
//         00538968     LEA        EAX,[EDX + EAX*0x8 + -0x18]
//                              view.cpp:4546 (4)
//         0053896c     OR         byte ptr [EAX + 0xa],0x40
//                               LAB_00538970                                                 XREF[1]:     0053894c(j)
//                              view.cpp:4549 (19)
//         00538970     MOV        EAX,dword ptr [ESI + 0x104]
//         00538976     MOVSX      EDX,word ptr [ESP + param_6]
//         0053897b     MOV        EDI,dword ptr [EAX + 0xc]
//         0053897e     DEC        EDI
//         0053897f     CMP        EDX,EDI
//         00538981     JGE        LAB_005389a0
//                              view.cpp:4551 (19)
//         00538983     MOV        EDI,dword ptr [EAX + 0x8d8c]
//         00538989     MOVSX      EAX,this
//         0053898c     MOV        EDX,dword ptr [EDI + EDX*0x4 + 0x4]
//         00538990     LEA        EAX,[EAX + EAX*0x2]
//         00538993     LEA        EAX,[EDX + EAX*0x8]
//                              view.cpp:4552 (10)
//         00538996     OR         byte ptr [EAX + 0xa],0x40
//         0053899a     JMP        LAB_005389a0
//                               LAB_0053899c                                                 XREF[1]:     00538895(j)
//         0053899c     MOV        this,dword ptr [ESP + param_5]
//                               LAB_005389a0                                                 XREF[3]:     00538947(j), 00538981(j),
//                                                                                                         0053899a(j)
//                              view.cpp:4560 (12)
//         005389a0     MOV        EAX,dword ptr [ESP + draw_terrain]
//         005389a4     TEST       EAX,EAX
//         005389a6     JZ         LAB_00538b65
//                              view.cpp:4562 (34)
//         005389ac     MOV        EDX,dword ptr [ESP + top_index]
//         005389b0     MOV        EDI,dword ptr [ESI + 0x104]
//         005389b6     MOV        EAX,EDX
//         005389b8     AND        EAX,0xff
//         005389bd     LEA        EAX,[EAX + EAX*0x4]
//         005389c0     LEA        EAX,[EAX + EAX*0x8]
//         005389c3     SHL        EAX,0x5
//         005389c6     ADD        EAX,EDI
//         005389c8     MOV        EDI,dword ptr [EAX + 0x33ac]
//                              view.cpp:4563 (8)
//         005389ce     TEST       EDI,EDI
//         005389d0     JZ         LAB_00538b0e
//                              view.cpp:4565 (10)
//         005389d6     CMP        word ptr [EAX + 0x392a],0x0
//         005389de     JNZ        LAB_00538a29
//                              view.cpp:4567 (29)
//         005389e0     MOV        EAX,dword ptr [ESP + param_6]
//         005389e4     PUSH       EAX
//         005389e5     MOV        EAX,dword ptr [ESP + param_1]
//         005389e9     PUSH       this
//         005389ea     MOV        this,byte ptr [EAX + 0x6]
//         005389ed     MOV        AL,byte ptr [EAX + 0x4]
//         005389f0     SHR        this,0x4
//         005389f3     PUSH       this
//         005389f4     PUSH       EAX
//         005389f5     PUSH       EDX
//         005389f6     MOV        this,ESI
//         005389f8     CALL       RGE_View::get_border_picture                     short get_border_picture(RGE_View * this, uch
//                              view.cpp:4568 (10)
//         005389fd     CMP        AX,0xffff
//         00538a01     JZ         LAB_00538b0a
//                              view.cpp:4569 (29)
//         00538a07     MOV        this,dword ptr [ESP + draw_border]
//         00538a0b     MOV        EDX,dword ptr [ESP + param_7]
//         00538a0f     PUSH       EBP
//         00538a10     PUSH       EBX
//         00538a11     MOVSX      EAX,AX
//         00538a14     PUSH       this
//         00538a15     PUSH       EDX
//         00538a16     MOVSX      this,word ptr [ESP + param_4]
//         00538a1b     MOVSX      EDX,word ptr [ESP + param_3]
//         00538a20     PUSH       EAX
//         00538a21     PUSH       EDI
//         00538a22     PUSH       this
//         00538a23     PUSH       EDX
//                              view.cpp:4571 (5)
//         00538a24     JMP        LAB_00538b03
//                               LAB_00538a29                                                 XREF[1]:     005389de(j)
//                              view.cpp:4573 (57)
//         00538a29     LEA        EAX=>retval,[ESP + 0x2c]
//         00538a2d     PUSH       EAX
//         00538a2e     LEA        EAX=>right_index,[ESP + 0x28]
//         00538a32     PUSH       EAX
//         00538a33     LEA        EAX=>bottom_index,[ESP + 0x30]
//         00538a37     PUSH       EAX
//         00538a38     LEA        EAX=>left_index,[ESP + 0x2c]
//         00538a3c     PUSH       EAX
//         00538a3d     MOV        EAX,dword ptr [ESP + param_6]
//         00538a41     PUSH       EAX
//         00538a42     MOV        EAX,dword ptr [ESP + param_1]
//         00538a46     PUSH       this
//         00538a47     MOV        this,byte ptr [EAX + 0x6]
//         00538a4a     MOV        AL,byte ptr [EAX + 0x4]
//         00538a4d     SHR        this,0x4
//         00538a50     PUSH       this
//         00538a51     PUSH       EAX
//         00538a52     PUSH       EDX
//         00538a53     MOV        this,ESI
//         00538a55     CALL       RGE_View::get_border_edge_pictures               int get_border_edge_pictures(RGE_View * this,
//         00538a5a     TEST       EAX,EAX
//         00538a5c     JZ         LAB_00538b0a
//                              view.cpp:4575 (42)
//         00538a62     MOV        EAX,dword ptr [ESP + left_index]
//         00538a66     CMP        EAX,-0x1
//         00538a69     JZ         LAB_00538a8c
//         00538a6b     MOV        this,dword ptr [ESP + draw_border]
//         00538a6f     MOV        EDX,dword ptr [ESP + param_7]
//         00538a73     PUSH       EBP
//         00538a74     PUSH       EBX
//         00538a75     PUSH       this
//         00538a76     PUSH       EDX
//         00538a77     MOVSX      this,word ptr [ESP + param_3]
//         00538a7c     PUSH       EAX
//         00538a7d     PUSH       EDI
//         00538a7e     MOVSX      EAX,word ptr [ESP + param_4]
//         00538a83     PUSH       EAX
//         00538a84     PUSH       this
//         00538a85     MOV        this,ESI
//         00538a87     CALL       RGE_View::draw_terrain_shape                     void draw_terrain_shape(RGE_View * this, int
//                               LAB_00538a8c                                                 XREF[1]:     00538a69(j)
//                              view.cpp:4576 (42)
//         00538a8c     MOV        EAX,dword ptr [ESP + right_index]
//         00538a90     CMP        EAX,-0x1
//         00538a93     JZ         LAB_00538ab6
//         00538a95     MOV        EDX,dword ptr [ESP + draw_border]
//         00538a99     MOV        this,dword ptr [ESP + param_7]
//         00538a9d     PUSH       EBP
//         00538a9e     PUSH       EBX
//         00538a9f     PUSH       EDX
//         00538aa0     PUSH       this
//         00538aa1     MOVSX      EDX,word ptr [ESP + param_4]
//         00538aa6     PUSH       EAX
//         00538aa7     PUSH       EDI
//         00538aa8     MOVSX      EAX,word ptr [ESP + param_3]
//         00538aad     PUSH       EDX
//         00538aae     PUSH       EAX
//         00538aaf     MOV        this,ESI
//         00538ab1     CALL       RGE_View::draw_terrain_shape                     void draw_terrain_shape(RGE_View * this, int
//                               LAB_00538ab6                                                 XREF[1]:     00538a93(j)
//                              view.cpp:4577 (42)
//         00538ab6     MOV        EAX,dword ptr [ESP + bottom_index]
//         00538aba     CMP        EAX,-0x1
//         00538abd     JZ         LAB_00538ae0
//         00538abf     MOV        this,dword ptr [ESP + draw_border]
//         00538ac3     MOV        EDX,dword ptr [ESP + param_7]
//         00538ac7     PUSH       EBP
//         00538ac8     PUSH       EBX
//         00538ac9     PUSH       this
//         00538aca     PUSH       EDX
//         00538acb     MOVSX      this,word ptr [ESP + param_3]
//         00538ad0     PUSH       EAX
//         00538ad1     PUSH       EDI
//         00538ad2     MOVSX      EAX,word ptr [ESP + param_4]
//         00538ad7     PUSH       EAX
//         00538ad8     PUSH       this
//         00538ad9     MOV        this,ESI
//         00538adb     CALL       RGE_View::draw_terrain_shape                     void draw_terrain_shape(RGE_View * this, int
//                               LAB_00538ae0                                                 XREF[1]:     00538abd(j)
//                              view.cpp:4578 (46)
//         00538ae0     MOV        EAX,dword ptr [ESP + retval]
//         00538ae4     CMP        EAX,-0x1
//         00538ae7     JZ         LAB_00538b0a
//         00538ae9     MOV        EDX,dword ptr [ESP + draw_border]
//         00538aed     MOV        this,dword ptr [ESP + param_7]
//         00538af1     PUSH       EBP
//         00538af2     PUSH       EBX
//         00538af3     PUSH       EDX
//         00538af4     PUSH       this
//         00538af5     MOVSX      EDX,word ptr [ESP + param_4]
//         00538afa     PUSH       EAX
//         00538afb     PUSH       EDI
//         00538afc     MOVSX      EAX,word ptr [ESP + param_3]
//         00538b01     PUSH       EDX
//         00538b02     PUSH       EAX
//                               LAB_00538b03                                                 XREF[1]:     00538a24(j)
//         00538b03     MOV        this,ESI
//         00538b05     CALL       RGE_View::draw_terrain_shape                     void draw_terrain_shape(RGE_View * this, int
//                               LAB_00538b0a                                                 XREF[3]:     00538a01(j), 00538a5c(j),
//                                                                                                         00538ae7(j)
//         00538b0a     MOV        this,dword ptr [ESP + param_5]
//                               LAB_00538b0e                                                 XREF[1]:     005389d0(j)
//                              view.cpp:4585 (5)
//         00538b0e     TEST       this,this
//         00538b11     JLE        LAB_00538b35
//                              view.cpp:4587 (30)
//         00538b13     MOV        EAX,dword ptr [ESI + 0x104]
//         00538b19     MOVSX      EDX,word ptr [ESP + param_6]
//         00538b1e     MOV        EDI,dword ptr [EAX + 0x8d8c]
//         00538b24     MOVSX      EAX,this
//         00538b27     MOV        EDX,dword ptr [EDI + EDX*0x4]
//         00538b2a     LEA        EAX,[EAX + EAX*0x2]
//         00538b2d     LEA        EAX,[EDX + EAX*0x8 + -0x18]
//                              view.cpp:4588 (4)
//         00538b31     OR         byte ptr [EAX + 0xa],0x40
//                               LAB_00538b35                                                 XREF[1]:     00538b11(j)
//                              view.cpp:4591 (19)
//         00538b35     MOV        ESI,dword ptr [ESI + 0x104]
//         00538b3b     MOVSX      EDX,word ptr [ESP + param_6]
//         00538b40     MOV        EAX,dword ptr [ESI + 0xc]
//         00538b43     DEC        EAX
//         00538b44     CMP        EDX,EAX
//         00538b46     JGE        LAB_00538b65
//                              view.cpp:4593 (19)
//         00538b48     MOV        ESI,dword ptr [ESI + 0x8d8c]
//         00538b4e     MOVSX      EAX,this
//         00538b51     MOV        EDX,dword ptr [ESI + EDX*0x4 + 0x4]
//         00538b55     LEA        this,[EAX + EAX*0x2]
//         00538b58     LEA        EAX,[EDX + this->_padding_*0x8]
//                              view.cpp:4594 (10)
//         00538b5b     MOV        this,byte ptr [EDX + this->_padding_*0x8 + 0xa]
//         00538b5f     OR         this,0x40
//         00538b62     MOV        byte ptr [EAX + 0xa],this
//                               LAB_00538b65                                                 XREF[2]:     005389a6(j), 00538b46(j)
//                              view.cpp:4599 (4)
//         00538b65     MOV        EAX,dword ptr [ESP + local_8]
//                              view.cpp:4600 (22)
//         00538b69     POP        EDI
//         00538b6a     POP        ESI
//         00538b6b     POP        EBP
//         00538b6c     POP        EBX
//         00538b6d     ADD        ESP,0x28
//         00538b70     RET        0x24
//                               LAB_00538b73                                                 XREF[2]:     0053873a(j), 00538760(j)
//         00538b73     POP        EDI
//         00538b74     POP        ESI
//         00538b75     POP        EBP
//         00538b76     XOR        EAX,EAX
//         00538b78     POP        EBX
//         00538b79     ADD        ESP,0x28
//         00538b7c     RET        0x24
//         00538b7f     ??         90h
    return 0;
}

void RGE_View::draw_terrain_shape(int param_1, int param_2, TShape* param_3, int param_4, uchar param_5, uchar param_6, int param_7, int param_8) {
    /* TODO: Stub */
//                              void __thiscall draw_terrain_shape(RGE_View * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     00538b9e(R), 00538cbe(R), 00538d0d(R)
//              int               Stack[0x8]:4   param_2                   XREF[3]:     00538b89(R), 00538cb3(R), 00538d02(R)
//              TShape *          Stack[0xc]:4   param_3                   XREF[4]:     00538b8d(R), 00538be5(R), 00538cd1(R), 00538d1b(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00538b81(R)
//              uchar             Stack[0x14]:1  param_5                   XREF[1]:     00538c90(R)
//              uchar             Stack[0x18]:1  param_6                   XREF[4]:     00538ba9(R), 00538c40(R), 00538c74(R), 00538cdc(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     00538cf0(R)
//              int               Stack[0x20]:4  param_8                   XREF[1]:     00538c9d(R)
//                               ?draw_terrain_shape@RGE_View@@IAEXHHPAVTShape@@HEEHH@Z       XREF[5]:     draw_tile:00538930(c),
//                               RGE_View::draw_terrain_shape                                              draw_tile:00538a87(c),
//                                                                                                         draw_tile:00538ab1(c),
//                                                                                                         draw_tile:00538adb(c),
//                                                                                                         draw_tile:00538b05(c)
//                              view.cpp:4606 (1)
//         00538b80     PUSH       EBX
//                              view.cpp:4609 (8)
//         00538b81     MOV        EBX,dword ptr [ESP + param_4]
//         00538b85     PUSH       EBP
//         00538b86     PUSH       ESI
//         00538b87     MOV        ESI,this
//                              view.cpp:4610 (32)
//         00538b89     MOV        EBP,dword ptr [ESP + param_2]
//         00538b8d     MOV        this,dword ptr [ESP + param_3]
//         00538b91     MOV        EAX,EBX
//         00538b93     SHL        EAX,0x5
//         00538b96     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00538b99     PUSH       EDI
//         00538b9a     MOV        this,dword ptr [EAX + EDX*0x1 + 0x1c]
//         00538b9e     MOV        EDI,dword ptr [ESP + param_1]
//         00538ba2     ADD        EAX,EDX
//         00538ba4     SUB        EBP,this
//         00538ba6     MOV        EDX,dword ptr [EAX + 0x18]
//                              view.cpp:4612 (16)
//         00538ba9     MOV        AL,byte ptr [ESP + param_6]
//         00538bad     MOV        this,AL
//         00538baf     SUB        EDI,EDX
//         00538bb1     AND        this,0x10
//         00538bb4     CMP        this,0x10
//         00538bb7     JNZ        LAB_00538c1d
//                              view.cpp:4615 (35)
//         00538bb9     PUSH       0x280028
//         00538bbe     PUSH       DAT_ff00ff00
//         00538bc3     PUSH       0x28002800
//         00538bc8     PUSH       0xff00ff
//         00538bcd     MOV        dword ptr [fog_next_shape],0x1
//         00538bd7     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//                              view.cpp:4617 (26)
//         00538bdc     MOV        EDX,dword ptr [ESI + 0xf4]
//         00538be2     ADD        ESP,0x10
//         00538be5     MOV        this,dword ptr [ESP + param_3]
//         00538be9     PUSH       0x0
//         00538beb     PUSH       0x0
//         00538bed     PUSH       EBX
//         00538bee     PUSH       EBP
//         00538bef     PUSH       EDI
//         00538bf0     PUSH       EDX
//         00538bf1     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              view.cpp:4619 (22)
//         00538bf6     PUSH       0x0
//         00538bf8     PUSH       DAT_ff00ff00
//         00538bfd     PUSH       0x0
//         00538bff     PUSH       0xff00ff
//         00538c04     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         00538c09     ADD        ESP,0x10
//                              view.cpp:4620 (10)
//         00538c0c     MOV        dword ptr [fog_next_shape],0x0
//                              view.cpp:4661 (7)
//         00538c16     POP        EDI
//         00538c17     POP        ESI
//         00538c18     POP        EBP
//         00538c19     POP        EBX
//         00538c1a     RET        0x20
//                               LAB_00538c1d                                                 XREF[1]:     00538bb7(j)
//                              view.cpp:4625 (10)
//         00538c1d     MOV        this,AL
//         00538c1f     AND        this,0x20
//         00538c22     CMP        this,0x20
//         00538c25     JNZ        LAB_00538c47
//                              view.cpp:4627 (32)
//         00538c27     PUSH       DAT_00560056                                     = FEh
//         00538c2c     PUSH       DAT_ff00ff00
//         00538c31     PUSH       0x56005600
//         00538c36     PUSH       0xff00ff
//         00538c3b     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         00538c40     MOV        AL,byte ptr [ESP + param_6]
//         00538c44     ADD        ESP,0x10
//                               LAB_00538c47                                                 XREF[1]:     00538c25(j)
//                              view.cpp:4630 (10)
//         00538c47     MOV        DL,AL
//         00538c49     AND        DL,0x80
//         00538c4c     CMP        DL,0x80
//         00538c4f     JNZ        LAB_00538c7b
//                              view.cpp:4633 (18)
//         00538c51     AND        EAX,0xf
//         00538c54     MOV        this,EAX
//         00538c56     SHL        EAX,0x10
//         00538c59     ADD        EAX,this
//         00538c5b     SHL        EAX,0xc
//         00538c5e     ADD        EAX,0x4000400
//                              view.cpp:4634 (24)
//         00538c63     PUSH       EAX
//         00538c64     PUSH       DAT_ff00ff00
//         00538c69     PUSH       EAX
//         00538c6a     PUSH       0xff00ff
//         00538c6f     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         00538c74     MOV        AL,byte ptr [ESP + param_6]
//         00538c78     ADD        ESP,0x10
//                               LAB_00538c7b                                                 XREF[1]:     00538c4f(j)
//                              view.cpp:4637 (28)
//         00538c7b     MOV        this,dword ptr [ESI + 0x104]
//         00538c81     MOV        EBP,0x1
//         00538c86     MOV        DL,byte ptr [this->_padding_ + 0x8db9]
//         00538c8c     TEST       DL,DL
//         00538c8e     JZ         LAB_00538c9d
//         00538c90     CMP        byte ptr [ESP + param_5],0x80
//         00538c95     JNZ        LAB_00538c9d
//                              view.cpp:4638 (6)
//         00538c97     MOV        dword ptr [fog_next_shape],EBP
//                               LAB_00538c9d                                                 XREF[2]:     00538c8e(j), 00538c95(j)
//                              view.cpp:4640 (10)
//         00538c9d     MOV        this,dword ptr [ESP + param_8]
//         00538ca1     XOR        EDI,EDI
//         00538ca3     CMP        this,EDI
//         00538ca5     JZ         LAB_00538ce6
//                              view.cpp:4642 (12)
//         00538ca7     MOV        EDX,dword ptr [ESI + 0xf4]
//         00538cad     MOV        EAX,dword ptr [ESI + 0x17c]
//                              view.cpp:4644 (41)
//         00538cb3     MOV        this,dword ptr [ESP + param_2]
//         00538cb7     PUSH       EDI
//         00538cb8     MOV        dword ptr [EDX + 0xd0],EAX
//         00538cbe     MOV        EDX,dword ptr [ESP + param_1]
//         00538cc2     PUSH       EDI
//         00538cc3     MOV        dword ptr [fog_next_shape],EBP
//         00538cc9     MOV        EAX,dword ptr [ESI + 0xf4]
//         00538ccf     PUSH       EBX
//         00538cd0     PUSH       this
//         00538cd1     MOV        this,dword ptr [ESP + param_3]
//         00538cd5     PUSH       EDX
//         00538cd6     PUSH       EAX
//         00538cd7     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              view.cpp:4645 (10)
//         00538cdc     MOV        AL,byte ptr [ESP + param_6]
//         00538ce0     MOV        dword ptr [fog_next_shape],EDI
//                               LAB_00538ce6                                                 XREF[1]:     00538ca5(j)
//                              view.cpp:4648 (10)
//         00538ce6     TEST       AL,0xa0
//         00538ce8     JZ         LAB_00538cf0
//         00538cea     MOV        dword ptr [fog_next_shape],EBP
//                               LAB_00538cf0                                                 XREF[1]:     00538ce8(j)
//                              view.cpp:4650 (6)
//         00538cf0     CMP        dword ptr [ESP + param_7],EDI
//         00538cf4     JZ         LAB_00538d25
//                              view.cpp:4652 (12)
//         00538cf6     MOV        this,dword ptr [ESI + 0xf4]
//         00538cfc     MOV        EDX,dword ptr [ESI + 0x178]
//                              view.cpp:4653 (35)
//         00538d02     MOV        EAX,dword ptr [ESP + param_2]
//         00538d06     PUSH       EDI
//         00538d07     MOV        dword ptr [ECX + this->_padding_],EDX
//         00538d0d     MOV        this,dword ptr [ESP + param_1]
//         00538d11     MOV        EDX,dword ptr [ESI + 0xf4]
//         00538d17     PUSH       EDI
//         00538d18     PUSH       EBX
//         00538d19     PUSH       EAX
//         00538d1a     PUSH       this
//         00538d1b     MOV        this,dword ptr [ESP + param_3]
//         00538d1f     PUSH       EDX
//         00538d20     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                               LAB_00538d25                                                 XREF[1]:     00538cf4(j)
//                              view.cpp:4656 (6)
//         00538d25     MOV        ESI,dword ptr [ESI + 0xf4]
//                              view.cpp:4658 (32)
//         00538d2b     PUSH       EDI
//         00538d2c     PUSH       DAT_ff00ff00
//         00538d31     PUSH       EDI
//         00538d32     MOV        EAX,dword ptr [ESI + 0xcc]
//         00538d38     PUSH       0xff00ff
//         00538d3d     MOV        dword ptr [ESI + 0xd0],EAX
//         00538d43     CALL       _ASMSet_Shadowing                                undefined _ASMSet_Shadowing()
//         00538d48     ADD        ESP,0x10
//                              view.cpp:4659 (6)
//         00538d4b     MOV        dword ptr [fog_next_shape],EDI
//                              view.cpp:4661 (7)
//         00538d51     POP        EDI
//         00538d52     POP        ESI
//         00538d53     POP        EBP
//         00538d54     POP        EBX
//         00538d55     RET        0x20
//         00538d58     ??         90h
//         00538d59     NOP
//         00538d5a     NOP
//         00538d5b     NOP
//         00538d5c     NOP
//         00538d5d     NOP
//         00538d5e     NOP
//         00538d5f     NOP
    return;
}

void RGE_View::draw_terrain_obstruction_map(int param_1, int param_2, TShape* param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              void __thiscall draw_terrain_obstruction_map(RGE_View * this, int pa
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[2]:     00538d9f(R), 00538e10(R)
//              int               Stack[0x8]:4   param_2                   XREF[2]:     00538d9b(R), 00538e1a(R)
//              TShape *          Stack[0xc]:4   param_3                   XREF[3]:     00538daf(R), 00538dc7(W), 00538e2f(R)
//              int               Stack[0x10]:4  param_4                   XREF[3]:     00538d91(R), 00538dee(W), 00538df6(R)
//              int               Stack[0x14]:4  param_5                   XREF[5]:     00538d61(R), 00538dcd(W), 00538dd3(R), 00538e44(R),
//                                                                                     00538e4c(W)
//              int               Stack[0x18]:4  param_6                   XREF[3]:     00538d65(R), 00538d8d(W), 00538dd7(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00538d82(W), 00538df2(R)
//              int               Stack[-0x8]:4  TileX4
//                               ?draw_terrain_obstruction_map@RGE_View@@IAEXHHPAVTShape@@HH  XREF[1]:     draw_tile:005388fd(c)
//                               RGE_View::draw_terrain_obstruction_map
//                              view.cpp:4676 (1)
//         00538d60     PUSH       this
//                              view.cpp:4679 (4)
//         00538d61     MOV        EAX,dword ptr [ESP + param_5]
//                              view.cpp:4680 (23)
//         00538d65     MOV        EDX,dword ptr [ESP + param_6]
//         00538d69     PUSH       EBX
//         00538d6a     PUSH       EBP
//         00538d6b     MOV        EBP,this
//         00538d6d     PUSH       ESI
//         00538d6e     LEA        this,[EAX*0x4 + 0x0]
//         00538d75     LEA        EAX,[EDX*0x4 + 0x0]
//                              view.cpp:4686 (21)
//         00538d7c     MOV        EDX,dword ptr [EBP + 0x178]
//         00538d82     MOV        dword ptr [ESP + local_4],this
//         00538d86     MOV        this,dword ptr [EBP + 0xf4]
//         00538d8c     PUSH       EDI
//         00538d8d     MOV        dword ptr [ESP + param_6],EAX
//                              view.cpp:4687 (41)
//         00538d91     MOV        EAX,dword ptr [ESP + param_4]
//         00538d95     MOV        dword ptr [ECX + this->_padding_],EDX
//         00538d9b     MOV        this,dword ptr [ESP + param_2]
//         00538d9f     MOV        EDX,dword ptr [ESP + param_1]
//         00538da3     PUSH       0x0
//         00538da5     PUSH       0x0
//         00538da7     PUSH       EAX
//         00538da8     MOV        EAX,dword ptr [EBP + 0xf4]
//         00538dae     PUSH       this
//         00538daf     MOV        this,dword ptr [ESP + param_3]
//         00538db3     PUSH       EDX
//         00538db4     PUSH       EAX
//         00538db5     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                              view.cpp:4689 (17)
//         00538dba     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00538dc0     PUSH       0x0
//         00538dc2     CALL       RGE_Base_Game::get_shape                         TShape * get_shape(RGE_Base_Game * this, int
//         00538dc7     MOV        dword ptr [ESP + param_3],EAX
//                              view.cpp:4691 (16)
//         00538dcb     XOR        EAX,EAX
//         00538dcd     MOV        dword ptr [ESP + param_5],EAX
//         00538dd1     JMP        LAB_00538dd7
//                               LAB_00538dd3                                                 XREF[1]:     00538e50(j)
//         00538dd3     MOV        EAX,dword ptr [ESP + param_5]
//                               LAB_00538dd7                                                 XREF[1]:     00538dd1(j)
//         00538dd7     MOV        this,dword ptr [ESP + param_6]
//                              view.cpp:4693 (27)
//         00538ddb     XOR        ESI,ESI
//         00538ddd     LEA        EDI,[EAX*0x8 + 0x0]
//         00538de4     LEA        EBX,[EAX*0x4 + 0x0]
//         00538deb     LEA        EDX,[EAX + this->_padding_*0x1]
//         00538dee     MOV        dword ptr [ESP + param_4],EDX
//                               LAB_00538df2                                                 XREF[1]:     00538e42(j)
//         00538df2     MOV        this,dword ptr [ESP + local_4]
//                              view.cpp:4695 (24)
//         00538df6     MOV        EAX,dword ptr [ESP + param_4]
//         00538dfa     PUSH       EAX
//         00538dfb     LEA        EDX,[ESI + this->_padding_*0x1]
//         00538dfe     MOV        this,pathSystem
//         00538e03     PUSH       EDX
//         00538e04     CALL       PathingSystem::obstruction                       uchar obstruction(PathingSystem * this, int p
//         00538e09     AND        EAX,0xff
//                              view.cpp:4697 (2)
//         00538e0e     JLE        LAB_00538e38
//                              view.cpp:4702 (66)
//         00538e10     MOV        EDX,dword ptr [ESP + param_1]
//         00538e14     PUSH       0x0
//         00538e16     DEC        EAX
//         00538e17     PUSH       0x0
//         00538e19     PUSH       EAX
//         00538e1a     MOV        EAX,dword ptr [ESP + param_2]
//         00538e1e     LEA        this,[EAX + EBX*0x1 + 0xd]
//         00538e22     LEA        EAX,[EDX + EDI*0x1 + 0x2]
//         00538e26     PUSH       this
//         00538e27     MOV        this,dword ptr [EBP + 0xf4]
//         00538e2d     PUSH       EAX
//         00538e2e     PUSH       this
//         00538e2f     MOV        this,dword ptr [ESP + param_3]
//         00538e33     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
//                               LAB_00538e38                                                 XREF[1]:     00538e0e(j)
//         00538e38     INC        ESI
//         00538e39     ADD        EDI,0x8
//         00538e3c     SUB        EBX,0x4
//         00538e3f     CMP        ESI,0x4
//         00538e42     JL         LAB_00538df2
//         00538e44     MOV        EAX,dword ptr [ESP + param_5]
//         00538e48     INC        EAX
//         00538e49     CMP        EAX,0x4
//         00538e4c     MOV        dword ptr [ESP + param_5],EAX
//         00538e50     JL         LAB_00538dd3
//                              view.cpp:4707 (8)
//         00538e52     POP        EDI
//         00538e53     POP        ESI
//         00538e54     POP        EBP
//         00538e55     POP        EBX
//         00538e56     POP        this
//         00538e57     RET        0x18
//         00538e5a     ??         90h
//         00538e5b     NOP
//         00538e5c     NOP
//         00538e5d     NOP
//         00538e5e     NOP
//         00538e5f     NOP
    return;
}

int RGE_View::Get_Cursor_Position(tagPOINT* param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              int __thiscall Get_Cursor_Position(RGE_View * this, tagPOINT * param
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              tagPOINT *        Stack[0x4]:4   param_1                   XREF[1]:     00538e61(R)
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?Get_Cursor_Position@RGE_View@@QAEHAAUtagPOINT@@HH@Z         XREF[1]:     view_function_terrain:005379c1(c)
//                               RGE_View::Get_Cursor_Position
//                              view.cpp:4716 (1)
//         00538e60     PUSH       ESI
//                              view.cpp:4717 (14)
//         00538e61     MOV        ESI,dword ptr [ESP + param_1]
//         00538e65     PUSH       EDI
//         00538e66     MOV        EDI,this
//         00538e68     PUSH       ESI
//         00538e69     CALL       dword ptr [->USER32.DLL::GetCursorPos]           = 0048aeba
//                              view.cpp:4719 (14)
//         00538e6f     MOV        EAX,dword ptr [EDI + 0x20]
//         00538e72     MOV        this,dword ptr [EAX]
//         00538e74     CMP        byte ptr [this->_padding_ + 0x479],0x1
//         00538e7b     JNZ        LAB_00538eaa
//                              view.cpp:4721 (11)
//         00538e7d     MOV        EDX,dword ptr [EAX + 0x4]
//         00538e80     PUSH       ESI
//         00538e81     PUSH       EDX
//         00538e82     CALL       dword ptr [->USER32.DLL::ScreenToClient]         = 0048aea8
//                              view.cpp:4722 (16)
//         00538e88     MOV        EAX,dword ptr [ESI]
//         00538e8a     CMP        EAX,0x7fff
//         00538e8f     JLE        LAB_00538e98
//         00538e91     ADD        EAX,0xffff0000
//         00538e96     MOV        dword ptr [ESI],EAX
//                               LAB_00538e98                                                 XREF[1]:     00538e8f(j)
//                              view.cpp:4723 (18)
//         00538e98     MOV        EAX,dword ptr [ESI + 0x4]
//         00538e9b     CMP        EAX,0x7fff
//         00538ea0     JLE        LAB_00538eaa
//         00538ea2     ADD        EAX,0xffff0000
//         00538ea7     MOV        dword ptr [ESI + 0x4],EAX
//                               LAB_00538eaa                                                 XREF[2]:     00538e7b(j), 00538ea0(j)
//                              view.cpp:4726 (6)
//         00538eaa     MOV        EAX,dword ptr [ESP + 0x10]
//         00538eae     MOV        this,dword ptr [ESI]
//                              view.cpp:4727 (18)
//         00538eb0     MOV        EDX,dword ptr [ESI + 0x4]
//         00538eb3     ADD        this,EAX
//         00538eb5     MOV        dword ptr [ESI],this
//         00538eb7     MOV        EAX,this
//         00538eb9     MOV        this,dword ptr [ESP + 0x14]
//         00538ebd     ADD        EDX,this
//         00538ebf     MOV        dword ptr [ESI + 0x4],EDX
//                              view.cpp:4731 (36)
//         00538ec2     MOV        this,dword ptr [EDI + 0x8c]
//         00538ec8     CMP        EAX,this
//         00538eca     MOV        ESI,EDX
//         00538ecc     JL         LAB_00538ef0
//         00538ece     CMP        EAX,dword ptr [EDI + 0x94]
//         00538ed4     JG         LAB_00538ef0
//         00538ed6     CMP        ESI,dword ptr [EDI + 0x90]
//         00538edc     JL         LAB_00538ef0
//         00538ede     CMP        ESI,dword ptr [EDI + 0x98]
//         00538ee4     JG         LAB_00538ef0
//                              view.cpp:4739 (5)
//         00538ee6     MOV        EAX,0x1
//                              view.cpp:4741 (12)
//         00538eeb     POP        EDI
//         00538eec     POP        ESI
//         00538eed     RET        0xc
//                               LAB_00538ef0                                                 XREF[4]:     00538ecc(j), 00538ed4(j),
//                                                                                                         00538edc(j), 00538ee4(j)
//         00538ef0     POP        EDI
//         00538ef1     XOR        EAX,EAX
//         00538ef3     POP        ESI
//         00538ef4     RET        0xc
//         00538ef7     ??         90h
//         00538ef8     NOP
//         00538ef9     NOP
//         00538efa     NOP
//         00538efb     NOP
//         00538efc     NOP
//         00538efd     NOP
//         00538efe     NOP
//         00538eff     NOP
    return 0;
}

int RGE_View::Pick_Tile(long param_1, long param_2, int* param_3, int* param_4) {
    /* TODO: Stub */
//                              int __thiscall Pick_Tile(RGE_View * this, long param_1, long param_2
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[3]:     00538f27(R), 00538fd2(*), 00538ff9(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     00538f35(R), 00538fd6(*)
//              int *             Stack[0xc]:4   param_3                   XREF[5]:     00538f49(R), 00538f79(R), 00538fca(W), 00539003(W),
//                                                                                     0053900b(R)
//              int *             Stack[0x10]:4  param_4                   XREF[4]:     00538f4d(R), 00538f7d(R), 00538fdb(*), 00538fef(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     00538f41(W), 00538fba(R), 00538fe0(*)
//              int               Stack[-0x8]:4  bx1                       XREF[2]:     00538f3b(W), 00538faa(R)
//              int               Stack[-0xc]:4  MapW
//                               ?Pick_Tile@RGE_View@@IAEHJJPAH0@Z
//                               RGE_View::Pick_Tile
//                              view.cpp:4748 (8)
//         00538f00     SUB        ESP,0x8
//         00538f03     PUSH       EBX
//         00538f04     MOV        EBX,this
//         00538f06     PUSH       EBP
//         00538f07     PUSH       ESI
//                              view.cpp:4758 (6)
//         00538f08     MOV        EAX,dword ptr [EBX + 0x104]
//                              view.cpp:4772 (6)
//         00538f0e     MOV        EBP,dword ptr [EBX + 0x8c]
//                              view.cpp:4773 (49)
//         00538f14     MOV        this,dword ptr [EBX + 0x90]
//         00538f1a     PUSH       EDI
//         00538f1b     MOV        EDX,dword ptr [EAX + 0x8]
//         00538f1e     MOV        ESI,dword ptr [EAX + 0xc]
//         00538f21     MOV        EAX,dword ptr [EBX + 0x130]
//         00538f27     MOV        EDI,dword ptr [ESP + param_1]
//         00538f2b     SUB        EAX,EBP
//         00538f2d     MOV        EBP,dword ptr [EBX + 0x134]
//         00538f33     ADD        EAX,EDI
//         00538f35     MOV        EDI,dword ptr [ESP + param_2]
//         00538f39     SUB        EBP,this
//         00538f3b     MOV        dword ptr [ESP + bx1],EDX
//         00538f3f     ADD        EBP,EDI
//         00538f41     MOV        dword ptr [ESP + local_4],ESI
//                              view.cpp:4778 (4)
//         00538f45     TEST       EAX,EAX
//         00538f47     JGE        LAB_00538f69
//                              view.cpp:4780 (4)
//         00538f49     MOV        EAX,dword ptr [ESP + param_3]
//                              view.cpp:4781 (16)
//         00538f4d     MOV        this,dword ptr [ESP + param_4]
//         00538f51     MOV        dword ptr [EAX],0xffffffff
//         00538f57     MOV        dword ptr [this->_padding_],0xffffffff
//                              view.cpp:4854 (2)
//         00538f5d     XOR        EAX,EAX
//                              view.cpp:4855 (10)
//         00538f5f     POP        EDI
//         00538f60     POP        ESI
//         00538f61     POP        EBP
//         00538f62     POP        EBX
//         00538f63     ADD        ESP,0x8
//         00538f66     RET        0x10
//                               LAB_00538f69                                                 XREF[1]:     00538f47(j)
//                              view.cpp:4785 (16)
//         00538f69     MOVSX      this,word ptr [EBX + 0x108]
//         00538f70     MOV        EDI,EDX
//         00538f72     IMUL       EDI,this
//         00538f75     CMP        EAX,EDI
//         00538f77     JL         LAB_00538f93
//                              view.cpp:4787 (4)
//         00538f79     MOV        EAX,dword ptr [ESP + param_3]
//                              view.cpp:4788 (10)
//         00538f7d     MOV        this,dword ptr [ESP + param_4]
//         00538f81     INC        EDX
//         00538f82     INC        ESI
//         00538f83     MOV        dword ptr [EAX],EDX
//         00538f85     MOV        dword ptr [this->_padding_],ESI
//                              view.cpp:4854 (2)
//         00538f87     XOR        EAX,EAX
//                              view.cpp:4855 (10)
//         00538f89     POP        EDI
//         00538f8a     POP        ESI
//         00538f8b     POP        EBP
//         00538f8c     POP        EBX
//         00538f8d     ADD        ESP,0x8
//         00538f90     RET        0x10
//                               LAB_00538f93                                                 XREF[1]:     00538f77(j)
//                              view.cpp:4794 (3)
//         00538f93     CDQ
//         00538f94     IDIV       this
//                              view.cpp:4800 (16)
//         00538f96     MOVSX      this,word ptr [EBX + 0x10a]
//         00538f9d     MOV        ESI,EAX
//         00538f9f     MOV        EAX,EBP
//         00538fa1     CDQ
//         00538fa2     IDIV       this
//         00538fa4     MOV        EDI,ESI
//                              view.cpp:4802 (8)
//         00538fa6     ADD        ESI,EAX
//         00538fa8     SUB        EDI,EAX
//         00538faa     MOV        EAX,dword ptr [ESP + bx1]
//                               LAB_00538fae                                                 XREF[1]:     00538fb8(j)
//                              view.cpp:4806 (8)
//         00538fae     TEST       EDI,EDI
//         00538fb0     JL         LAB_00538fb6
//         00538fb2     CMP        ESI,EAX
//         00538fb4     JL         LAB_00538fba
//                               LAB_00538fb6                                                 XREF[1]:     00538fb0(j)
//                              view.cpp:4808 (2)
//         00538fb6     DEC        ESI
//         00538fb7     INC        EDI
//                              view.cpp:4809 (6)
//         00538fb8     JMP        LAB_00538fae
//                               LAB_00538fba                                                 XREF[1]:     00538fb4(j)
//         00538fba     MOV        EAX,dword ptr [ESP + local_4]
//                               LAB_00538fbe                                                 XREF[1]:     00538fc8(j)
//                              view.cpp:4813 (8)
//         00538fbe     CMP        EDI,EAX
//         00538fc0     JGE        LAB_00538fc6
//         00538fc2     TEST       ESI,ESI
//         00538fc4     JGE        LAB_00538fca
//                               LAB_00538fc6                                                 XREF[1]:     00538fc0(j)
//                              view.cpp:4815 (2)
//         00538fc6     INC        ESI
//         00538fc7     DEC        EDI
//                              view.cpp:4816 (2)
//         00538fc8     JMP        LAB_00538fbe
//                               LAB_00538fca                                                 XREF[1]:     00538fc4(j)
//                              view.cpp:4820 (8)
//         00538fca     MOV        dword ptr [ESP + param_3],0x1
//                               LAB_00538fd2                                                 XREF[1]:     00539011(j)
//                              view.cpp:4825 (29)
//         00538fd2     LEA        EDX=>param_1,[ESP + 0x1c]
//         00538fd6     LEA        EAX=>param_2,[ESP + 0x20]
//         00538fda     PUSH       EDX
//         00538fdb     LEA        this=>param_4,[ESP + 0x2c]
//         00538fdf     PUSH       EAX
//         00538fe0     LEA        EDX=>local_4,[ESP + 0x1c]
//         00538fe4     PUSH       this
//         00538fe5     PUSH       EDX
//         00538fe6     PUSH       EDI
//         00538fe7     PUSH       ESI
//         00538fe8     MOV        this,EBX
//         00538fea     CALL       RGE_View::get_tile_bounding_coords               void get_tile_bounding_coords(RGE_View * this
//                              view.cpp:4829 (6)
//         00538fef     CMP        EBP,dword ptr [ESP + param_4]
//         00538ff3     JGE        LAB_00538ff9
//                              view.cpp:4831 (1)
//         00538ff5     INC        ESI
//                              view.cpp:4832 (1)
//         00538ff6     DEC        EDI
//                              view.cpp:4834 (8)
//         00538ff7     JMP        LAB_0053900b
//                               LAB_00538ff9                                                 XREF[1]:     00538ff3(j)
//         00538ff9     CMP        EBP,dword ptr [ESP + param_1]
//         00538ffd     JLE        LAB_00539003
//                              view.cpp:4836 (1)
//         00538fff     DEC        ESI
//                              view.cpp:4837 (1)
//         00539000     INC        EDI
//                              view.cpp:4839 (2)
//         00539001     JMP        LAB_0053900b
//                               LAB_00539003                                                 XREF[1]:     00538ffd(j)
//                              view.cpp:4841 (8)
//         00539003     MOV        dword ptr [ESP + param_3],0x0
//                               LAB_0053900b                                                 XREF[2]:     00538ff7(j), 00539001(j)
//                              view.cpp:4822 (8)
//         0053900b     MOV        EAX,dword ptr [ESP + param_3]
//         0053900f     TEST       EAX,EAX
//         00539011     JNZ        LAB_00538fd2
//                              view.cpp:4848 (2)
//         00539013     XOR        EAX,EAX
//                              view.cpp:4855 (24)
//         00539015     POP        EDI
//         00539016     POP        ESI
//         00539017     MOV        word ptr [EBX + 0x10e],AX
//         0053901e     MOV        word ptr [EBX + 0x10c],AX
//         00539025     POP        EBP
//         00539026     POP        EBX
//         00539027     ADD        ESP,0x8
//         0053902a     RET        0x10
//         0053902d     ??         90h
//         0053902e     NOP
//         0053902f     NOP
    return 0;
}

void RGE_View::get_tile_bounding_coords(int param_1, int param_2, int* param_3, int* param_4, int* param_5, int* param_6) {
    /* TODO: Stub */
//                              void __thiscall get_tile_bounding_coords(RGE_View * this, int param_
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     00539042(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     00539038(R)
//              int *             Stack[0xc]:4   param_3                   XREF[1]:     00539047(R)
//              int *             Stack[0x10]:4  param_4                   XREF[1]:     0053908a(R)
//              int *             Stack[0x14]:4  param_5                   XREF[1]:     00539076(R)
//              int *             Stack[0x18]:4  param_6                   XREF[1]:     005390ba(R)
//                               ?get_tile_bounding_coords@RGE_View@@IAEXHHAAH000@Z           XREF[1]:     Pick_Tile:00538fea(c)
//                               RGE_View::get_tile_bounding_coords
//                              view.cpp:4862 (23)
//         00539030     MOV        EAX,dword ptr [ECX + this->map]
//         00539036     PUSH       EBX
//         00539037     PUSH       ESI
//         00539038     MOV        ESI,dword ptr [ESP + param_2]
//         0053903c     MOV        EDX,dword ptr [EAX + 0x8d8c]
//         00539042     MOV        EAX,dword ptr [ESP + param_1]
//         00539046     PUSH       EDI
//                              view.cpp:4881 (24)
//         00539047     MOV        EDI,dword ptr [ESP + param_3]
//         0053904b     MOV        EDX,dword ptr [EDX + ESI*0x4]
//         0053904e     LEA        EAX,[EAX + EAX*0x2]
//         00539051     MOVSX      ESI,word ptr [EDX + EAX*0x8]
//         00539055     LEA        EAX,[EDX + EAX*0x8]
//         00539058     XOR        EDX,EDX
//         0053905a     MOV        DL,byte ptr [EAX + 0x4]
//         0053905d     MOV        dword ptr [EDI],ESI
//                              view.cpp:4882 (9)
//         0053905f     MOV        EBX,dword ptr [ECX + this->map]
//         00539065     LEA        EDI,[EDX + 0x4]
//                              view.cpp:4940 (20)
//         00539068     LEA        EDX,[EDX + EDX*0x2]
//         0053906b     LEA        EDI,[EDI + EDI*0x2]
//         0053906e     MOVSX      EDI,word ptr [EBX + EDI*0x2]
//         00539072     LEA        ESI,[EDI + ESI*0x1 + -0x1]
//         00539076     MOV        EDI,dword ptr [ESP + param_5]
//         0053907a     MOV        dword ptr [EDI],ESI
//                              view.cpp:4947 (71)
//         0053907c     POP        EDI
//         0053907d     MOVSX      ESI,word ptr [EAX + 0x2]
//         00539081     MOVSX      EAX,word ptr [ECX + this->tile_half_hgt]
//         00539088     SUB        ESI,EAX
//         0053908a     MOV        EAX,dword ptr [ESP + param_4]
//         0053908e     MOV        dword ptr [EAX],ESI
//         00539090     XOR        ESI,ESI
//         00539092     MOV        word ptr [ECX + this->tile_half_hgt],SI
//         00539099     MOV        word ptr [ECX + this->tile_half_wid],SI
//         005390a0     MOV        word ptr [ECX + this->elev_hgt],SI
//         005390a7     MOV        this,dword ptr [ECX + this->map]
//         005390ad     MOV        EAX,dword ptr [EAX]
//         005390af     POP        ESI
//         005390b0     MOVSX      EDX,word ptr [ECX + EDX*0x2 + this+0x1a]
//         005390b5     POP        EBX
//         005390b6     LEA        this,[EDX + EAX*0x1 + -0x1]
//         005390ba     MOV        EDX,dword ptr [ESP + param_6]
//         005390be     MOV        dword ptr [EDX],this
//         005390c0     RET        0x18
//         005390c3     ??         90h
//         005390c4     NOP
//         005390c5     NOP
//         005390c6     NOP
//         005390c7     NOP
//         005390c8     NOP
//         005390c9     NOP
//         005390ca     NOP
//         005390cb     NOP
//         005390cc     NOP
//         005390cd     NOP
//         005390ce     NOP
//         005390cf     NOP
    return;
}

int RGE_View::pick_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    /* TODO: Stub */
//                              int __thiscall pick_objects(RGE_View * this, int param_1, int param_
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     00539105(R), 00539176(W), 00539226(R)
//              int               Stack[0x8]:4   param_2                   XREF[7]:     00539123(R), 00539164(W), 005391bb(R), 00539232(R),
//                                                                                     00539257(R), 00539265(R), 00539279(R)
//              int               Stack[0xc]:4   param_3                   XREF[3]:     005390f3(R), 00539152(W), 00539475(R)
//              int               Stack[0x10]:4  param_4                   XREF[9]:     005390ef(R), 005391e2(W), 005392b6(R), 005392e0(W),
//                                                                                     0053932f(W), 00539337(R), 0053938e(R), 005393c4(W),
//                                                                                     005393e3(R)
//              int               Stack[0x14]:4  param_5                   XREF[4]:     005390d3(R), 0053920a(R), 00539220(R), 0053923a(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     005392c2(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     005391ec(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00539186(W)
//              RGE_SPick_Info    Stack[-0x18]   freep                     XREF[1,5]:   00539196(W), 00539172(W), 0053917a(W), 0053937e(*),
//                                                                                     0053938c(*), 00539182(W)
//              RGE_SPick_Info    Stack[-0x2c]   tail                      XREF[1,3]:   005391a6(W), 0053918a(W), 0053918e(W), 00539192(W)
//              RGE_SPick_Info    Stack[-0x40]   head                      XREF[2,11]:  005390e1(W), 00539486(R), 0053919a(W), 005392e6(*),
//                                                                                     005392f4(*), 0053940a(*), 00539414(*), 00539420(*),
//                                                                                     0053944a(*), 0053948f(*), 00539493(*), 0053919e(W),
//                                                                                     005391a2(W)
//              int               Stack[-0x44]:4 num_picked                XREF[2]:     0053930a(W), 0053931b(R)
//              int               Stack[-0x48]:4 z                         XREF[5]:     0053921c(W), 00539244(R), 005392dc(W), 005392ec(R),
//                                                                                     005393eb(R)
//              int               Stack[-0x4c]:4 obj_id                    XREF[4]:     0053917e(W), 005391c9(R), 00539471(R), 0053947c(W)
//              int               Stack[-0x50]:4 l                         XREF[4]:     005392d3(W), 00539329(R), 005393ef(R), 00539428(R)
//              int               Stack[-0x54]:4 hotY                      XREF[4]:     005390dd(W), 005391bf(R), 00539297(R), 005393b4(R)
//                               ?pick_objects@RGE_View@@IAEHHHHHHHH@Z                        XREF[3]:     pick_multi:00535b6c(c),
//                               RGE_View::pick_objects                                                    pick1:0053fc2b(c),
//                                                                                                         pick_best_target:0054004d(c)
//                              view.cpp:4961 (3)
//         005390d0     SUB        ESP,0x54
//                              view.cpp:4974 (44)
//         005390d3     MOV        EAX,dword ptr [ESP + param_5]
//         005390d7     PUSH       EBX
//         005390d8     PUSH       EBP
//         005390d9     PUSH       ESI
//         005390da     TEST       EAX,EAX
//         005390dc     PUSH       EDI
//         005390dd     MOV        dword ptr [ESP + hotY],this
//         005390e1     MOV        dword ptr [ESP + head[0]],0x0
//         005390e9     JL         LAB_005394fd
//         005390ef     MOV        EDX,dword ptr [ESP + param_4]
//         005390f3     MOV        EDI,dword ptr [ESP + param_3]
//         005390f7     CMP        EDX,EDI
//         005390f9     JL         LAB_005394fd
//                              view.cpp:4979 (60)
//         005390ff     MOV        EBP,dword ptr [ECX + this->_padding_]
//         00539105     MOV        EBX,dword ptr [ESP + param_1]
//         00539109     CMP        EBX,EBP
//         0053910b     JL         LAB_005394fd
//         00539111     CMP        EBX,dword ptr [ECX + this->_padding_]
//         00539117     JG         LAB_005394fd
//         0053911d     MOV        ESI,dword ptr [ECX + this->_padding_]
//         00539123     MOV        EAX,dword ptr [ESP + param_2]
//         00539127     CMP        EAX,ESI
//         00539129     JL         LAB_005394fd
//         0053912f     CMP        EAX,dword ptr [ECX + this->_padding_]
//         00539135     JG         LAB_005394fd
//                              view.cpp:4981 (17)
//         0053913b     CMP        EDI,0x28
//         0053913e     JG         LAB_005394fd
//         00539144     TEST       EDX,EDX
//         00539146     JL         LAB_005394fd
//                              view.cpp:4985 (10)
//         0053914c     TEST       EDI,EDI
//         0053914e     JGE        LAB_00539156
//         00539150     XOR        EDI,EDI
//         00539152     MOV        dword ptr [ESP + param_3],EDI
//                               LAB_00539156                                                 XREF[1]:     0053914e(j)
//                              view.cpp:4987 (10)
//         00539156     CMP        EDX,0x28
//         00539159     JLE        LAB_00539160
//         0053915b     MOV        EDX,0x28
//                               LAB_00539160                                                 XREF[1]:     00539159(j)
//                              view.cpp:4992 (14)
//         00539160     SUB        EAX,ESI
//         00539162     SUB        EBX,EBP
//         00539164     MOV        dword ptr [ESP + param_2],EAX
//         00539168     LEA        EAX,[ECX + this+0x314]
//                              view.cpp:5001 (2)
//         0053916e     XOR        this,this
//                              view.cpp:5006 (75)
//         00539170     CMP        EDX,EDI
//         00539172     MOV        dword ptr [ESP + freep[2]],this
//         00539176     MOV        dword ptr [ESP + param_1],EBX
//         0053917a     MOV        dword ptr [ESP + freep[3]],this
//         0053917e     MOV        dword ptr [ESP + obj_id],EDX
//         00539182     MOV        dword ptr [ESP + freep[4]],this
//         00539186     MOV        dword ptr [ESP + local_4],this
//         0053918a     MOV        dword ptr [ESP + tail[2]],this
//         0053918e     MOV        dword ptr [ESP + tail[3]],this
//         00539192     MOV        dword ptr [ESP + tail[4]],this
//         00539196     MOV        dword ptr [ESP + freep[0]],this
//         0053919a     MOV        dword ptr [ESP + head[2]],this
//         0053919e     MOV        dword ptr [ESP + head[3]],this
//         005391a2     MOV        dword ptr [ESP + head[4]],this
//         005391a6     MOV        dword ptr [ESP + tail[0]],this
//         005391aa     MOV        dword ptr [EAX],this
//         005391ac     MOV        dword ptr [EAX + 0x4],this
//         005391af     MOV        dword ptr [EAX + 0x8],this
//         005391b2     MOV        dword ptr [EAX + 0xc],this
//         005391b5     JL         LAB_00539486
//                              view.cpp:5008 (24)
//         005391bb     MOV        ESI,dword ptr [ESP + param_2]
//                               LAB_005391bf                                                 XREF[1]:     00539480(j)
//         005391bf     MOV        EDX,dword ptr [ESP + hotY]
//         005391c3     MOV        EAX,dword ptr [EDX + 0x334]
//         005391c9     MOV        EDX,dword ptr [ESP + obj_id]
//         005391cd     MOV        this,dword ptr [EAX + 0x5c]
//         005391d0     MOV        EDI,dword ptr [this->_padding_ + EDX*0x4]
//                              view.cpp:5009 (8)
//         005391d3     TEST       EDI,EDI
//         005391d5     JZ         LAB_00539471
//                               LAB_005391db                                                 XREF[1]:     0053946b(j)
//                              view.cpp:5014 (17)
//         005391db     MOV        EAX,dword ptr [EDI + 0x2c]
//         005391de     XOR        EBX,EBX
//         005391e0     TEST       EAX,EAX
//         005391e2     MOV        dword ptr [ESP + param_4],EBX
//         005391e6     JNZ        LAB_005392ba
//                              view.cpp:5016 (22)
//         005391ec     MOV        EAX,dword ptr [ESP + param_7]
//         005391f3     TEST       EAX,EAX
//         005391f5     JZ         LAB_00539202
//         005391f7     MOV        EAX,dword ptr [EDI + 0x8]
//         005391fa     TEST       EAX,EAX
//         005391fc     JL         LAB_005392ba
//                               LAB_00539202                                                 XREF[1]:     005391f5(j)
//                              view.cpp:5019 (4)
//         00539202     MOVSX      EDX,word ptr [EDI + 0x32]
//                              view.cpp:5021 (14)
//         00539206     MOVSX      EBP,word ptr [EDI + 0x36]
//         0053920a     MOV        EBX,dword ptr [ESP + param_5]
//         0053920e     MOV        this,EDX
//         00539210     SUB        this,EBX
//         00539212     ADD        EBP,EBX
//                              view.cpp:5026 (54)
//         00539214     MOVSX      EBX,word ptr [EDI + 0x30]
//         00539218     MOVSX      EAX,word ptr [EDI + 0x34]
//         0053921c     MOV        dword ptr [ESP + z],EBP
//         00539220     MOV        EBP,dword ptr [ESP + param_5]
//         00539224     SUB        EBX,EBP
//         00539226     MOV        EBP,dword ptr [ESP + param_1]
//         0053922a     CMP        EBP,EBX
//         0053922c     JL         LAB_005392b6
//         00539232     MOV        EBX,dword ptr [ESP + param_2]
//         00539236     CMP        EBX,this
//         00539238     JL         LAB_005392b6
//         0053923a     MOV        this,dword ptr [ESP + param_5]
//         0053923e     ADD        this,EAX
//         00539240     CMP        EBP,this
//         00539242     JG         LAB_005392b6
//         00539244     CMP        EBX,dword ptr [ESP + z]
//         00539248     JG         LAB_005392b6
//                              view.cpp:5033 (33)
//         0053924a     MOVSX      this,word ptr [EDI + 0x30]
//         0053924e     CMP        EBP,this
//         00539250     MOV        EBX,0x4
//         00539255     JL         LAB_005392ba
//         00539257     CMP        dword ptr [ESP + param_2],EDX
//         0053925b     JL         LAB_005392ba
//         0053925d     CMP        EBP,EAX
//         0053925f     JG         LAB_005392ba
//         00539261     MOVSX      this,word ptr [EDI + 0x36]
//         00539265     CMP        dword ptr [ESP + param_2],this
//         00539269     JG         LAB_005392ba
//                              view.cpp:5039 (22)
//         0053926b     MOV        this,dword ptr [EDI + 0x1c]
//         0053926e     MOV        EBX,0x3
//         00539273     AND        this,0x2
//         00539276     CMP        this,0x2
//         00539279     MOV        this,dword ptr [ESP + param_2]
//         0053927d     JNZ        LAB_00539287
//         0053927f     SUB        this,EDX
//                              view.cpp:5041 (4)
//         00539281     SUB        EAX,EBP
//         00539283     PUSH       this
//         00539284     PUSH       EAX
//                              view.cpp:5056 (2)
//         00539285     JMP        LAB_00539291
//                               LAB_00539287                                                 XREF[1]:     0053927d(j)
//                              view.cpp:5009 (8)
//         00539287     MOVSX      EAX,word ptr [EDI + 0x30]
//         0053928b     SUB        this,EDX
//         0053928d     SUB        EBP,EAX
//                              view.cpp:5058 (25)
//         0053928f     PUSH       this
//         00539290     PUSH       EBP
//                               LAB_00539291                                                 XREF[1]:     00539285(j)
//         00539291     MOV        EDX,dword ptr [EDI + 0xc]
//         00539294     MOV        EAX,dword ptr [EDI + 0x20]
//         00539297     MOV        this,dword ptr [ESP + hotY]
//         0053929b     PUSH       EDX
//         0053929c     PUSH       EAX
//         0053929d     CALL       RGE_View::sprite_check                           int sprite_check(RGE_View * this, uchar * par
//         005392a2     DEC        EAX
//         005392a3     JZ         LAB_005392af
//         005392a5     DEC        EAX
//         005392a6     JNZ        LAB_005392ba
//                              view.cpp:5067 (5)
//         005392a8     MOV        EBX,0x1
//                              view.cpp:5068 (2)
//         005392ad     JMP        LAB_005392ba
//                               LAB_005392af                                                 XREF[1]:     005392a3(j)
//                              view.cpp:5062 (7)
//         005392af     MOV        EBX,0x2
//         005392b4     JMP        LAB_005392ba
//                               LAB_005392b6                                                 XREF[4]:     0053922c(j), 00539238(j),
//                                                                                                         00539242(j), 00539248(j)
//                              view.cpp:5056 (4)
//         005392b6     MOV        EBX,dword ptr [ESP + param_4]
//                               LAB_005392ba                                                 XREF[9]:     005391e6(j), 005391fc(j),
//                                                                                                         00539255(j), 0053925b(j),
//                                                                                                         0053925f(j), 00539269(j),
//                                                                                                         005392a6(j), 005392ad(j),
//                                                                                                         005392b4(j)
//                              view.cpp:5081 (18)
//         005392ba     TEST       EBX,EBX
//         005392bc     JZ         LAB_00539466
//         005392c2     CMP        EBX,dword ptr [ESP + param_6]
//         005392c6     JG         LAB_00539466
//                              view.cpp:5084 (11)
//         005392cc     MOVSX      this,word ptr [EDI + 0x3a]
//         005392d0     MOV        EDX,dword ptr [EDI + 0x8]
//         005392d3     MOV        dword ptr [ESP + l],this
//                              view.cpp:5085 (13)
//         005392d7     MOV        this,0x1
//         005392dc     MOV        dword ptr [ESP + z],EDX
//         005392e0     MOV        dword ptr [ESP + param_4],this
//                              view.cpp:5089 (2)
//         005392e4     XOR        EAX,EAX
//                              view.cpp:5226 (10)
//         005392e6     LEA        EBP=>head[2],[ESP + 0x2c]
//         005392ea     JMP        LAB_005392f0
//                               LAB_005392ec                                                 XREF[1]:     00539315(j)
//         005392ec     MOV        EDX,dword ptr [ESP + z]
//                               LAB_005392f0                                                 XREF[1]:     005392ea(j)
//                              view.cpp:5091 (4)
//         005392f0     TEST       EAX,EAX
//         005392f2     JNZ        LAB_0053931b
//                              view.cpp:5093 (3)
//         005392f4     MOV        ESI,dword ptr [EBP]=>head[2]
//                              view.cpp:5095 (4)
//         005392f7     TEST       ESI,ESI
//         005392f9     JZ         LAB_0053930e
//                               LAB_005392fb                                                 XREF[1]:     00539304(j)
//                              view.cpp:5097 (4)
//         005392fb     CMP        dword ptr [ESI],EDX
//         005392fd     JZ         LAB_00539308
//                              view.cpp:5103 (9)
//         005392ff     MOV        ESI,dword ptr [ESI + 0xc]
//         00539302     TEST       ESI,ESI
//         00539304     JNZ        LAB_005392fb
//         00539306     JMP        LAB_0053930e
//                               LAB_00539308                                                 XREF[1]:     005392fd(j)
//                              view.cpp:5099 (2)
//         00539308     MOV        EAX,ESI
//                              view.cpp:5100 (13)
//         0053930a     MOV        dword ptr [ESP + num_picked],this
//                               LAB_0053930e                                                 XREF[2]:     005392f9(j), 00539306(j)
//         0053930e     INC        this
//         0053930f     ADD        EBP,0x4
//         00539312     CMP        this,0x5
//         00539315     JL         LAB_005392ec
//                              view.cpp:5107 (4)
//         00539317     TEST       EAX,EAX
//         00539319     JZ         LAB_0053938e
//                               LAB_0053931b                                                 XREF[1]:     005392f2(j)
//                              view.cpp:5109 (28)
//         0053931b     MOV        this,dword ptr [ESP + num_picked]
//         0053931f     CMP        this,EBX
//         00539321     JL         LAB_0053932f
//         00539323     JNZ        LAB_00539337
//         00539325     MOVSX      EDX,word ptr [EAX + 0x6]
//         00539329     CMP        dword ptr [ESP + l],EDX
//         0053932d     JGE        LAB_00539337
//                               LAB_0053932f                                                 XREF[1]:     00539321(j)
//         0053932f     MOV        dword ptr [ESP + param_4],0x0
//                               LAB_00539337                                                 XREF[2]:     00539323(j), 0053932d(j)
//                              view.cpp:5111 (8)
//         00539337     MOV        EDX,dword ptr [ESP + param_4]
//         0053933b     TEST       EDX,EDX
//         0053933d     JZ         LAB_0053938e
//                              view.cpp:5113 (20)
//         0053933f     LEA        EBP,[this->_padding_*0x4 + 0x0]
//         00539346     CMP        dword ptr [ESP + EBP*0x1 + 0x28],EAX
//         0053934a     JNZ        LAB_00539353
//         0053934c     MOV        this,dword ptr [EAX + 0xc]
//         0053934f     MOV        dword ptr [ESP + EBP*0x1 + 0x28],this
//                               LAB_00539353                                                 XREF[1]:     0053934a(j)
//                              view.cpp:5114 (13)
//         00539353     CMP        dword ptr [ESP + EBP*0x1 + 0x3c],EAX
//         00539357     JNZ        LAB_00539360
//         00539359     MOV        EDX,dword ptr [EAX + 0x10]
//         0053935c     MOV        dword ptr [ESP + EBP*0x1 + 0x3c],EDX
//                               LAB_00539360                                                 XREF[1]:     00539357(j)
//                              view.cpp:5117 (13)
//         00539360     MOV        this,dword ptr [EAX + 0xc]
//         00539363     TEST       this,this
//         00539365     JZ         LAB_0053936d
//         00539367     MOV        EDX,dword ptr [EAX + 0x10]
//         0053936a     MOV        dword ptr [ECX + this->_padding_],EDX
//                               LAB_0053936d                                                 XREF[1]:     00539365(j)
//                              view.cpp:5118 (13)
//         0053936d     MOV        this,dword ptr [EAX + 0x10]
//         00539370     TEST       this,this
//         00539372     JZ         LAB_0053937a
//         00539374     MOV        EDX,dword ptr [EAX + 0xc]
//         00539377     MOV        dword ptr [ECX + this->_padding_],EDX
//                               LAB_0053937a                                                 XREF[1]:     00539372(j)
//                              view.cpp:5120 (11)
//         0053937a     MOV        EDX,dword ptr [ESP + EBP*0x1 + 0x50]
//         0053937e     LEA        this=>freep[3],[ESP + EBP*0x1 + 0x50]
//         00539382     MOV        dword ptr [EAX + 0xc],EDX
//                              view.cpp:5121 (7)
//         00539385     MOV        dword ptr [EAX + 0x10],0x0
//                              view.cpp:5122 (2)
//         0053938c     MOV        dword ptr [this->_padding_]=>freep[3],EAX
//                               LAB_0053938e                                                 XREF[2]:     00539319(j), 0053933d(j)
//                              view.cpp:5126 (12)
//         0053938e     MOV        EAX,dword ptr [ESP + param_4]
//         00539392     TEST       EAX,EAX
//         00539394     JZ         LAB_00539466
//                              view.cpp:5130 (15)
//         0053939a     LEA        EBP,[EBX*0x4 + 0x0]
//         005393a1     MOV        EAX,dword ptr [ESP + EBP*0x1 + 0x50]
//         005393a5     TEST       EAX,EAX
//         005393a7     JZ         LAB_005393b4
//                              view.cpp:5132 (2)
//         005393a9     MOV        ESI,EAX
//                              view.cpp:5133 (7)
//         005393ab     MOV        EAX,dword ptr [ESI + 0xc]
//         005393ae     MOV        dword ptr [ESP + EBP*0x1 + 0x50],EAX
//                              view.cpp:5135 (2)
//         005393b2     JMP        LAB_005393e3
//                               LAB_005393b4                                                 XREF[1]:     005393a7(j)
//                              view.cpp:5137 (16)
//         005393b4     MOV        this,dword ptr [ESP + hotY]
//         005393b8     MOV        EAX,dword ptr [ECX + EBX*0x4 + this->pick_list
//         005393bf     CMP        EAX,0x40
//         005393c2     JNZ        LAB_005393ce
//                              view.cpp:5139 (8)
//         005393c4     MOV        dword ptr [ESP + param_4],0x0
//                              view.cpp:5141 (2)
//         005393cc     JMP        LAB_005393e3
//                               LAB_005393ce                                                 XREF[1]:     005393c2(j)
//                              view.cpp:5143 (10)
//         005393ce     MOV        ESI,dword ptr [ECX + EBX*0x4 + this->pick_list
//         005393d5     LEA        EDX,[EAX + EAX*0x4]
//                              view.cpp:5144 (11)
//         005393d8     INC        EAX
//         005393d9     LEA        ESI,[ESI + EDX*0x4]
//         005393dc     MOV        dword ptr [ECX + EBX*0x4 + this->pick_list_siz
//                               LAB_005393e3                                                 XREF[2]:     005393b2(j), 005393cc(j)
//                              view.cpp:5148 (8)
//         005393e3     MOV        EAX,dword ptr [ESP + param_4]
//         005393e7     TEST       EAX,EAX
//         005393e9     JZ         LAB_00539466
//                              view.cpp:5150 (4)
//         005393eb     MOV        EAX,dword ptr [ESP + z]
//                              view.cpp:5152 (15)
//         005393ef     MOV        this,word ptr [ESP + l]
//         005393f4     MOV        dword ptr [ESI],EAX
//         005393f6     MOV        word ptr [ESI + 0x4],BX
//         005393fa     MOV        word ptr [ESI + 0x6],this
//                              view.cpp:5153 (8)
//         005393fe     MOV        DX,word ptr [EDI + 0x14]
//         00539402     MOV        word ptr [ESI + 0x8],DX
//                              view.cpp:5154 (4)
//         00539406     MOV        AX,word ptr [EDI + 0x18]
//                              view.cpp:5158 (15)
//         0053940a     LEA        EDX=>head[2],[ESP + EBP*0x1 + 0x28]
//         0053940e     MOV        word ptr [ESI + 0xa],AX
//         00539412     XOR        this,this
//         00539414     MOV        EAX,dword ptr [EDX]=>head[2]
//         00539416     MOV        dword ptr [ESI + 0xc],this
//                              view.cpp:5160 (7)
//         00539419     CMP        EAX,this
//         0053941b     MOV        dword ptr [ESI + 0x10],this
//         0053941e     JNZ        LAB_00539424
//                              view.cpp:5162 (2)
//         00539420     MOV        dword ptr [EDX]=>head[2],ESI
//                              view.cpp:5165 (2)
//         00539422     JMP        LAB_00539462
//                               LAB_00539424                                                 XREF[2]:     0053941e(j), 00539439(j)
//                              view.cpp:5169 (10)
//         00539424     MOVSX      this,word ptr [EAX + 0x6]
//         00539428     CMP        dword ptr [ESP + l],this
//         0053942c     JGE        LAB_0053943d
//                              view.cpp:5186 (7)
//         0053942e     MOV        this,dword ptr [EAX + 0xc]
//         00539431     TEST       this,this
//         00539433     JZ         LAB_0053945c
//                              view.cpp:5193 (8)
//         00539435     MOV        EAX,this
//         00539437     TEST       EAX,EAX
//         00539439     JNZ        LAB_00539424
//         0053943b     JMP        LAB_00539466
//                               LAB_0053943d                                                 XREF[1]:     0053942c(j)
//                              view.cpp:5171 (3)
//         0053943d     MOV        dword ptr [ESI + 0xc],EAX
//                              view.cpp:5172 (3)
//         00539440     MOV        this,dword ptr [EAX + 0x10]
//                              view.cpp:5174 (7)
//         00539443     TEST       this,this
//         00539445     MOV        dword ptr [ESI + 0x10],this
//         00539448     JNZ        LAB_00539451
//                              view.cpp:5176 (2)
//         0053944a     MOV        dword ptr [EDX]=>head[2],ESI
//                              view.cpp:5183 (3)
//         0053944c     MOV        dword ptr [EAX + 0x10],ESI
//                              view.cpp:5184 (2)
//         0053944f     JMP        LAB_00539466
//                               LAB_00539451                                                 XREF[1]:     00539448(j)
//                              view.cpp:5180 (6)
//         00539451     MOV        EDX,dword ptr [ESI + 0x10]
//         00539454     MOV        dword ptr [EDX + 0xc],ESI
//                              view.cpp:5183 (3)
//         00539457     MOV        dword ptr [EAX + 0x10],ESI
//                              view.cpp:5184 (2)
//         0053945a     JMP        LAB_00539466
//                               LAB_0053945c                                                 XREF[1]:     00539433(j)
//                              view.cpp:5188 (3)
//         0053945c     MOV        dword ptr [EAX + 0xc],ESI
//                              view.cpp:5189 (3)
//         0053945f     MOV        dword ptr [ESI + 0x10],EAX
//                               LAB_00539462                                                 XREF[1]:     00539422(j)
//                              view.cpp:5190 (4)
//         00539462     MOV        dword ptr [ESP + EBP*0x1 + 0x3c],ESI
//                               LAB_00539466                                                 XREF[7]:     005392bc(j), 005392c6(j),
//                                                                                                         00539394(j), 005393e9(j),
//                                                                                                         0053943b(j), 0053944f(j),
//                                                                                                         0053945a(j)
//                              view.cpp:5200 (11)
//         00539466     MOV        EDI,dword ptr [EDI + 0x4]
//         00539469     TEST       EDI,EDI
//         0053946b     JNZ        LAB_005391db
//                               LAB_00539471                                                 XREF[1]:     005391d5(j)
//                              view.cpp:5006 (21)
//         00539471     MOV        EAX,dword ptr [ESP + obj_id]
//         00539475     MOV        this,dword ptr [ESP + param_3]
//         00539479     DEC        EAX
//         0053947a     CMP        EAX,this
//         0053947c     MOV        dword ptr [ESP + obj_id],EAX
//         00539480     JGE        LAB_005391bf
//                               LAB_00539486                                                 XREF[1]:     005391b5(j)
//                              view.cpp:5206 (13)
//         00539486     MOV        EDX,dword ptr [ESP + head[0]]
//         0053948a     MOV        EDI,0x1
//         0053948f     LEA        ESI=>head[2],[ESP + 0x2c]
//                               LAB_00539493                                                 XREF[1]:     005394e0(j)
//                              view.cpp:5208 (2)
//         00539493     MOV        this,dword ptr [ESI]=>head[2]
//                              view.cpp:5210 (14)
//         00539495     TEST       this,this
//         00539497     JZ         LAB_005394d9
//         00539499     LEA        EAX,[EDX + EDX*0x2]
//         0053949c     LEA        EAX,[EAX*0x4 + DAT_0087d4a4]
//                               LAB_005394a3                                                 XREF[1]:     005394d7(j)
//                              view.cpp:5212 (2)
//         005394a3     MOV        EBX,dword ptr [this->_padding_]
//                              view.cpp:5217 (38)
//         005394a5     INC        EDX
//         005394a6     MOV        dword ptr [EAX + -0x4],EBX=>Picked_Objects       = 00000000
//         005394a9     MOV        BX,word ptr [ECX + this->_padding_]
//         005394ad     MOV        word ptr [EAX],BX=>DAT_0087d4a4
//         005394b0     MOV        BX,word ptr [ECX + this+0x6]
//         005394b4     MOV        word ptr [EAX + 0x2],BX=>DAT_0087d4a6            = align(750)
//         005394b8     MOV        BX,word ptr [ECX + this->_padding_]
//         005394bc     MOV        word ptr [EAX + 0x4],BX=>DAT_0087d4a8            = align(748)
//         005394c0     MOV        BX,word ptr [ECX + this+0xa]
//         005394c4     MOV        word ptr [EAX + 0x6],BX=>DAT_0087d4aa            = align(746)
//         005394c8     ADD        EAX,0xc
//                              view.cpp:5219 (7)
//         005394cb     CMP        EAX,view_debug_redraw_all
//         005394d0     JGE        LAB_005394ee
//                              view.cpp:5220 (7)
//         005394d2     MOV        this,dword ptr [ECX + this->_padding_]
//         005394d5     TEST       this,this
//         005394d7     JNZ        LAB_005394a3
//                               LAB_005394d9                                                 XREF[1]:     00539497(j)
//                              view.cpp:5206 (9)
//         005394d9     INC        EDI
//         005394da     ADD        ESI,0x4
//         005394dd     CMP        EDI,0x4
//         005394e0     JLE        LAB_00539493
//                              view.cpp:5224 (2)
//         005394e2     MOV        EAX,EDX
//                              view.cpp:5226 (10)
//         005394e4     POP        EDI
//         005394e5     POP        ESI
//         005394e6     POP        EBP
//         005394e7     POP        EBX
//         005394e8     ADD        ESP,0x54
//         005394eb     RET        0x1c
//                               LAB_005394ee                                                 XREF[1]:     005394d0(j)
//                              view.cpp:5219 (5)
//         005394ee     MOV        EAX,0x40
//                              view.cpp:5226 (22)
//         005394f3     POP        EDI
//         005394f4     POP        ESI
//         005394f5     POP        EBP
//         005394f6     POP        EBX
//         005394f7     ADD        ESP,0x54
//         005394fa     RET        0x1c
//                               LAB_005394fd                                                 XREF[8]:     005390e9(j), 005390f9(j),
//                                                                                                         0053910b(j), 00539117(j),
//                                                                                                         00539129(j), 00539135(j),
//                                                                                                         0053913e(j), 00539146(j)
//         005394fd     POP        EDI
//         005394fe     POP        ESI
//         005394ff     POP        EBP
//         00539500     XOR        EAX,EAX
//         00539502     POP        EBX
//         00539503     ADD        ESP,0x54
//         00539506     RET        0x1c
//         00539509     ??         90h
//         0053950a     NOP
//         0053950b     NOP
//         0053950c     NOP
//         0053950d     NOP
//         0053950e     NOP
//         0053950f     NOP
    return 0;
}

int RGE_View::sprite_check(uchar* param_1, Shape_Info* param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              int __thiscall sprite_check(RGE_View * this, uchar * param_1, Shape_
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar *           Stack[0x4]:4   param_1                   XREF[1]:     0053954f(R)
//              Shape_Info *      Stack[0x8]:4   param_2                   XREF[11]:    00539514(R), 00539567(W), 0053957b(R), 005395a3(W),
//                                                                                     005395ba(R), 005395d8(R), 005395fa(R), 0053960b(R),
//                                                                                     00539623(R), 00539641(R), 0053965e(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     00539520(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     00539537(R)
//                               ?sprite_check@RGE_View@@IAEHPAEPAUShape_Info@@HH@Z           XREF[3]:     pick_objects:0053929d(c),
//                               RGE_View::sprite_check                                                    pick_touched_object:00539a13(c),
//                                                                                                         pick_touched_object:00539a44(c)
//                              view.cpp:5238 (4)
//         00539510     PUSH       EBX
//         00539511     PUSH       EBP
//         00539512     PUSH       ESI
//         00539513     PUSH       EDI
//                              view.cpp:5244 (12)
//         00539514     MOV        EDI,dword ptr [ESP + param_2]
//         00539518     TEST       EDI,EDI
//         0053951a     JZ         switchD_005395b3::caseD_e
//                              view.cpp:5246 (23)
//         00539520     MOV        EBP,dword ptr [ESP + param_3]
//         00539524     TEST       EBP,EBP
//         00539526     JL         switchD_005395b3::caseD_e
//         0053952c     MOV        EBX,dword ptr [EDI + 0x10]
//         0053952f     CMP        EBP,EBX
//         00539531     JGE        switchD_005395b3::caseD_e
//                              view.cpp:5247 (21)
//         00539537     MOV        this,dword ptr [ESP + param_4]
//         0053953b     TEST       this,this
//         0053953d     JL         switchD_005395b3::caseD_e
//         00539543     CMP        this,dword ptr [EDI + 0x14]
//         00539546     JGE        switchD_005395b3::caseD_e
//                              view.cpp:5251 (9)
//         0053954c     MOV        EAX,dword ptr [EDI + 0x4]
//         0053954f     MOV        ESI,dword ptr [ESP + param_1]
//         00539553     ADD        EAX,ESI
//                              view.cpp:5253 (11)
//         00539555     LEA        EDX,[this->_padding_*0x4 + 0x0]
//         0053955c     MOVSX      this,word ptr [EAX + this->_padding_*0x4]
//                              view.cpp:5254 (5)
//         00539560     MOVSX      EAX,word ptr [EAX + EDX*0x1 + 0x2]
//                              view.cpp:5256 (12)
//         00539565     TEST       this,this
//         00539567     MOV        dword ptr [ESP + param_2],EAX
//         0053956b     JL         switchD_005395b3::caseD_e
//                              view.cpp:5257 (8)
//         00539571     CMP        EBP,this
//         00539573     JL         switchD_005395b3::caseD_e
//                              view.cpp:5258 (14)
//         00539579     MOV        EAX,EBX
//         0053957b     SUB        EAX,dword ptr [ESP + param_2]
//         0053957f     CMP        EBP,EAX
//         00539581     JG         switchD_005395b3::caseD_e
//                              view.cpp:5263 (9)
//         00539587     MOV        EAX,dword ptr [EDI]
//         00539589     ADD        EAX,ESI
//         0053958b     MOV        EAX,dword ptr [EAX + EDX*0x1]
//         0053958e     ADD        EAX,ESI
//                              view.cpp:5266 (8)
//         00539590     CMP        this,EBX
//         00539592     JGE        switchD_005395b3::default
//                               LAB_00539598                                                 XREF[1]:     0053967a(j)
//                              view.cpp:5270 (8)
//         00539598     CMP        EBP,this
//         0053959a     JL         switchD_005395b3::default
//                              view.cpp:5272 (2)
//         005395a0     MOV        DL,byte ptr [EAX]
//                              view.cpp:5273 (5)
//         005395a2     INC        EAX
//         005395a3     MOV        byte ptr [ESP + param_2],DL
//                              view.cpp:5276 (19)
//         005395a7     AND        EDX,0xf
//         005395aa     CMP        EDX,0xf
//         005395ad     JA         switchD_005395b3::default
//                               switchD_005395b3::switchD
//         005395b3     JMP        dword ptr [EDX*0x4 + switchD_005395b3::switchd   = 005395ba
//                               switchD_005395b3::caseD_4                                    XREF[5]:     005395b3(j), 005396b0(*),
//                               switchD_005395b3::caseD_8                                                 005396c0(*), 005396d0(*),
//                               switchD_005395b3::caseD_c                                                 005396e0(*)
//                               switchD_005395b3::caseD_0
//                              view.cpp:5282 (13)
//         005395ba     MOV        EDX,dword ptr [ESP + param_2]
//         005395be     AND        EDX,0xff
//         005395c4     SHR        EDX,0x2
//                              view.cpp:5283 (10)
//         005395c7     ADD        this,EDX
//         005395c9     CMP        EBP,this
//         005395cb     JL         LAB_0053968c
//                              view.cpp:5284 (2)
//         005395d1     ADD        EAX,EDX
//                              view.cpp:5286 (5)
//         005395d3     JMP        LAB_00539678
//                               switchD_005395b3::caseD_2                                    XREF[2]:     005395b3(j), 005396b8(*)
//                              view.cpp:5289 (19)
//         005395d8     MOV        ESI,dword ptr [ESP + param_2]
//         005395dc     XOR        EDX,EDX
//         005395de     MOV        DL,byte ptr [EAX]
//         005395e0     AND        ESI,0xff
//         005395e6     SHL        ESI,0x4
//         005395e9     OR         ESI,EDX
//                              view.cpp:5290 (1)
//         005395eb     INC        EAX
//                              view.cpp:5291 (10)
//         005395ec     ADD        this,ESI
//         005395ee     CMP        EBP,this
//         005395f0     JL         LAB_0053968c
//                              view.cpp:5293 (2)
//         005395f6     ADD        EAX,ESI
//                              view.cpp:5295 (2)
//         005395f8     JMP        LAB_00539678
//                               switchD_005395b3::caseD_5                                    XREF[5]:     005395b3(j), 005396b4(*),
//                               switchD_005395b3::caseD_9                                                 005396c4(*), 005396d4(*),
//                               switchD_005395b3::caseD_d                                                 005396e4(*)
//                               switchD_005395b3::caseD_1
//                              view.cpp:5302 (15)
//         005395fa     MOV        EDX,dword ptr [ESP + param_2]
//         005395fe     AND        EDX,0xff
//         00539604     SHR        EDX,0x2
//         00539607     ADD        this,EDX
//                              view.cpp:5303 (2)
//         00539609     JMP        LAB_00539678
//                               switchD_005395b3::caseD_3                                    XREF[2]:     005395b3(j), 005396bc(*)
//                              view.cpp:5306 (19)
//         0053960b     MOV        ESI,dword ptr [ESP + param_2]
//         0053960f     XOR        EDX,EDX
//         00539611     MOV        DL,byte ptr [EAX]
//         00539613     AND        ESI,0xff
//         00539619     SHL        ESI,0x4
//         0053961c     OR         ESI,EDX
//                              view.cpp:5307 (1)
//         0053961e     INC        EAX
//                              view.cpp:5308 (2)
//         0053961f     ADD        this,ESI
//                              view.cpp:5309 (2)
//         00539621     JMP        LAB_00539678
//                               switchD_005395b3::caseD_6                                    XREF[2]:     005395b3(j), 005396c8(*)
//                              view.cpp:5312 (13)
//         00539623     MOV        EDX,dword ptr [ESP + param_2]
//         00539627     AND        EDX,0xff
//         0053962d     SHR        EDX,0x4
//                              view.cpp:5313 (7)
//         00539630     JNZ        LAB_00539637
//         00539632     XOR        EDX,EDX
//         00539634     MOV        DL,byte ptr [EAX]
//         00539636     INC        EAX
//                               LAB_00539637                                                 XREF[1]:     00539630(j)
//                              view.cpp:5314 (6)
//         00539637     ADD        this,EDX
//         00539639     CMP        EBP,this
//         0053963b     JL         LAB_0053968c
//                              view.cpp:5315 (2)
//         0053963d     ADD        EAX,EDX
//                              view.cpp:5317 (2)
//         0053963f     JMP        LAB_00539678
//                               switchD_005395b3::caseD_a                                    XREF[3]:     005395b3(j), 005396cc(*),
//                               switchD_005395b3::caseD_7                                                 005396d8(*)
//                              view.cpp:5321 (13)
//         00539641     MOV        EDX,dword ptr [ESP + param_2]
//         00539645     AND        EDX,0xff
//         0053964b     SHR        EDX,0x4
//                              view.cpp:5322 (7)
//         0053964e     JNZ        LAB_00539655
//         00539650     XOR        EDX,EDX
//         00539652     MOV        DL,byte ptr [EAX]
//         00539654     INC        EAX
//                               LAB_00539655                                                 XREF[1]:     0053964e(j)
//                              view.cpp:5323 (6)
//         00539655     ADD        this,EDX
//         00539657     CMP        EBP,this
//         00539659     JL         LAB_0053968c
//                              view.cpp:5324 (1)
//         0053965b     INC        EAX
//                              view.cpp:5326 (2)
//         0053965c     JMP        LAB_00539678
//                               switchD_005395b3::caseD_b                                    XREF[2]:     005395b3(j), 005396dc(*)
//                              view.cpp:5329 (13)
//         0053965e     MOV        EDX,dword ptr [ESP + param_2]
//         00539662     AND        EDX,0xff
//         00539668     SHR        EDX,0x4
//                              view.cpp:5330 (7)
//         0053966b     JNZ        LAB_00539672
//         0053966d     XOR        EDX,EDX
//         0053966f     MOV        DL,byte ptr [EAX]
//         00539671     INC        EAX
//                               LAB_00539672                                                 XREF[1]:     0053966b(j)
//                              view.cpp:5331 (6)
//         00539672     ADD        this,EDX
//         00539674     CMP        EBP,this
//         00539676     JL         LAB_0053968c
//                               LAB_00539678                                                 XREF[6]:     005395d3(j), 005395f8(j),
//                                                                                                         00539609(j), 00539621(j),
//                                                                                                         0053963f(j), 0053965c(j)
//                              view.cpp:5266 (8)
//         00539678     CMP        this,EBX
//         0053967a     JL         LAB_00539598
//                              view.cpp:5345 (5)
//         00539680     MOV        EAX,0x1
//                              view.cpp:5347 (7)
//         00539685     POP        EDI
//         00539686     POP        ESI
//         00539687     POP        EBP
//         00539688     POP        EBX
//         00539689     RET        0x10
//                               LAB_0053968c                                                 XREF[5]:     005395cb(j), 005395f0(j),
//                                                                                                         0053963b(j), 00539659(j),
//                                                                                                         00539676(j)
//                              view.cpp:5331 (5)
//         0053968c     MOV        EAX,0x2
//                              view.cpp:5347 (7)
//         00539691     POP        EDI
//         00539692     POP        ESI
//         00539693     POP        EBP
//         00539694     POP        EBX
//         00539695     RET        0x10
//                               switchD_005395b3::default                                    XREF[3]:     00539592(j), 0053959a(j),
//                                                                                                         005395ad(j)
//                              view.cpp:5345 (5)
//         00539698     MOV        EAX,0x1
//                              view.cpp:5347 (83)
//         0053969d     POP        EDI
//         0053969e     POP        ESI
//         0053969f     POP        EBP
//         005396a0     POP        EBX
//         005396a1     RET        0x10
//                               switchD_005395b3::caseD_f                                    XREF[11]:    0053951a(j), 00539526(j),
//                               switchD_005395b3::caseD_e                                                 00539531(j), 0053953d(j),
//                                                                                                         00539546(j), 0053956b(j),
//                                                                                                         00539573(j), 00539581(j),
//                                                                                                         005395b3(j), 005396e8(*),
//                                                                                                         005396ec(*)
//         005396a4     POP        EDI
//         005396a5     POP        ESI
//         005396a6     POP        EBP
//         005396a7     XOR        EAX,EAX
//         005396a9     POP        EBX
//         005396aa     RET        0x10
    return 0;
}

int RGE_View::pick_multi_objects(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, uchar param_8, int param_9) {
    /* TODO: Stub */
//                              int __thiscall pick_multi_objects(RGE_View * this, int param_1, int
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[4]:     00539715(R), 00539778(R), 0053977e(W), 005397e5(R)
//              int               Stack[0x8]:4   param_2                   XREF[4]:     00539739(R), 00539788(R), 005397a0(W), 005397fd(R)
//              int               Stack[0xc]:4   param_3                   XREF[4]:     005396f3(R), 00539782(R), 0053978c(W), 005397f7(R)
//              int               Stack[0x10]:4  param_4                   XREF[4]:     0053972d(R), 00539790(R), 00539798(W), 00539803(R)
//              int               Stack[0x14]:4  param_5                   XREF[3]:     0053974b(R), 0053976a(W), 005398e2(R)
//              int               Stack[0x18]:4  param_6                   XREF[5]:     00539758(R), 005397db(W), 00539819(R), 00539872(R),
//                                                                                     005398a5(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     00539820(R)
//              uchar             Stack[0x20]:1  param_8                   XREF[1]:     0053983d(R)
//              int               Stack[0x24]:4  param_9
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     005397a4(W), 005398e6(R), 005398f5(W)
//              int               Stack[-0x8]:4  z                         XREF[3]:     00539707(W), 00539809(R), 005398ea(R)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     0053970b(W), 0053987a(R), 005398c3(R), 005398cb(W),
//                                                                                     005398ee(R)
//              int               Stack[-0x10]:4 num_picked
//                               ?pick_multi_objects@RGE_View@@IAEHHHHHHHHEH@Z                XREF[1]:     pick_multi:00535ab9(c)
//                               RGE_View::pick_multi_objects
//                              view.cpp:5355 (3)
//         005396f0     SUB        ESP,0xc
//                              view.cpp:5372 (88)
//         005396f3     MOV        EAX,dword ptr [ESP + param_3]
//         005396f7     PUSH       EBX
//         005396f8     MOV        EBX,this
//         005396fa     PUSH       EBP
//         005396fb     PUSH       ESI
//         005396fc     XOR        EBP,EBP
//         005396fe     MOV        ESI,dword ptr [EBX + 0x8c]
//         00539704     PUSH       EDI
//         00539705     CMP        EAX,ESI
//         00539707     MOV        dword ptr [ESP + z],EBX
//         0053970b     MOV        dword ptr [ESP + local_c],EBP
//         0053970f     JL         LAB_0053991a
//         00539715     MOV        EAX,dword ptr [ESP + param_1]
//         00539719     MOV        this,dword ptr [EBX + 0x94]
//         0053971f     CMP        EAX,this
//         00539721     JG         LAB_0053991a
//         00539727     MOV        EDI,dword ptr [EBX + 0x90]
//         0053972d     MOV        EAX,dword ptr [ESP + param_4]
//         00539731     CMP        EAX,EDI
//         00539733     JL         LAB_0053991a
//         00539739     MOV        this,dword ptr [ESP + param_2]
//         0053973d     MOV        EAX,dword ptr [EBX + 0x98]
//         00539743     CMP        this,EAX
//         00539745     JG         LAB_0053991a
//                              view.cpp:5374 (25)
//         0053974b     MOV        this,dword ptr [ESP + param_5]
//         0053974f     CMP        this,0x28
//         00539752     JG         LAB_0053991a
//         00539758     MOV        EDX,dword ptr [ESP + param_6]
//         0053975c     TEST       EDX,EDX
//         0053975e     JL         LAB_0053991a
//                              view.cpp:5378 (10)
//         00539764     TEST       this,this
//         00539766     JGE        LAB_0053976e
//         00539768     XOR        this,this
//         0053976a     MOV        dword ptr [ESP + param_5],this
//                               LAB_0053976e                                                 XREF[1]:     00539766(j)
//                              view.cpp:5380 (10)
//         0053976e     CMP        EDX,0x28
//         00539771     JLE        LAB_00539778
//         00539773     MOV        EDX,0x28
//                               LAB_00539778                                                 XREF[1]:     00539771(j)
//                              view.cpp:5384 (10)
//         00539778     MOV        EAX,dword ptr [ESP + param_1]
//         0053977c     SUB        EAX,ESI
//         0053977e     MOV        dword ptr [ESP + param_1],EAX
//                              view.cpp:5385 (6)
//         00539782     MOV        EAX,dword ptr [ESP + param_3]
//         00539786     SUB        EAX,ESI
//                              view.cpp:5386 (8)
//         00539788     MOV        ESI,dword ptr [ESP + param_2]
//         0053978c     MOV        dword ptr [ESP + param_3],EAX
//                              view.cpp:5387 (12)
//         00539790     MOV        EAX,dword ptr [ESP + param_4]
//         00539794     SUB        EAX,EDI
//         00539796     SUB        ESI,EDI
//         00539798     MOV        dword ptr [ESP + param_4],EAX
//                              view.cpp:5391 (18)
//         0053979c     MOV        EAX,EDX
//         0053979e     CMP        EDX,this
//         005397a0     MOV        dword ptr [ESP + param_2],ESI
//         005397a4     MOV        dword ptr [ESP + local_4],EAX
//         005397a8     JL         LAB_005398ff
//                               LAB_005397ae                                                 XREF[1]:     005398f9(j)
//                              view.cpp:5393 (12)
//         005397ae     MOV        EDX,dword ptr [EBX + 0x334]
//         005397b4     MOV        EDX,dword ptr [EDX + 0x5c]
//         005397b7     MOV        ESI,dword ptr [EDX + EAX*0x4]
//                              view.cpp:5394 (19)
//         005397ba     TEST       ESI,ESI
//         005397bc     JZ         LAB_005398f2
//         005397c2     LEA        EAX,[EBP + EBP*0x2]
//         005397c6     LEA        EDI,[EAX*0x4 + DAT_0087d4a4]
//                               LAB_005397cd                                                 XREF[1]:     005398dc(j)
//                              view.cpp:5398 (9)
//         005397cd     MOV        this,dword ptr [ESI + 0x2c]
//         005397d0     XOR        EAX,EAX
//         005397d2     TEST       this,this
//         005397d4     JNZ        LAB_0053984e
//                              view.cpp:5400 (3)
//         005397d6     MOV        this,dword ptr [ESI + 0x8]
//                              view.cpp:5402 (8)
//         005397d9     TEST       this,this
//         005397db     MOV        dword ptr [ESP + param_6],this
//         005397df     JL         LAB_0053984e
//                              view.cpp:5412 (40)
//         005397e1     MOVSX      this,word ptr [ESI + 0x34]
//         005397e5     CMP        dword ptr [ESP + param_1],this
//         005397e9     MOVSX      EDX,word ptr [ESI + 0x30]
//         005397ed     MOVSX      EBP,word ptr [ESI + 0x32]
//         005397f1     MOVSX      EBX,word ptr [ESI + 0x36]
//         005397f5     JG         LAB_0053984e
//         005397f7     CMP        dword ptr [ESP + param_3],EDX
//         005397fb     JL         LAB_0053984e
//         005397fd     CMP        dword ptr [ESP + param_2],EBX
//         00539801     JG         LAB_0053984e
//         00539803     CMP        dword ptr [ESP + param_4],EBP
//         00539807     JL         LAB_0053984e
//                              view.cpp:5414 (23)
//         00539809     MOV        EDX,dword ptr [ESP + z]
//         0053980d     MOV        this,dword ptr [EDX + 0xfc]
//         00539813     MOV        EDX,dword ptr [ECX + this->_padding_]
//         00539819     MOV        this,dword ptr [ESP + param_6]
//         0053981d     MOV        EDX,dword ptr [EDX + this->_padding_*0x4]
//                              view.cpp:5415 (20)
//         00539820     MOV        this,dword ptr [ESP + param_7]
//         00539824     CMP        this,-0x1
//         00539827     JZ         LAB_00539834
//         00539829     MOV        EBX,dword ptr [EDX + 0xc]
//         0053982c     MOVSX      EBX,word ptr [EBX + 0x4a]
//         00539830     CMP        EBX,this
//         00539832     JNZ        LAB_0053984e
//                               LAB_00539834                                                 XREF[1]:     00539827(j)
//                              view.cpp:5417 (21)
//         00539834     CMP        byte ptr [EDX + 0x48],0x2
//         00539838     JNZ        LAB_0053984e
//         0053983a     MOV        EDX,dword ptr [EDX + 0x8]
//         0053983d     MOV        this,byte ptr [ESP + param_8]
//         00539841     CMP        byte ptr [EDX + 0x8d],this
//         00539847     JC         LAB_0053984e
//                              view.cpp:5419 (5)
//         00539849     MOV        EAX,0x1
//                               LAB_0053984e                                                 XREF[9]:     005397d4(j), 005397df(j),
//                                                                                                         005397f5(j), 005397fb(j),
//                                                                                                         00539801(j), 00539807(j),
//                                                                                                         00539832(j), 00539838(j),
//                                                                                                         00539847(j)
//                              view.cpp:5428 (8)
//         0053984e     TEST       EAX,EAX
//         00539850     JZ         LAB_005398d7
//                              view.cpp:5434 (13)
//         00539856     CMP        EDI,DAT_0087d4a4
//         0053985c     MOV        this,0x1
//         00539861     JLE        LAB_005398a1
//                              view.cpp:5436 (10)
//         00539863     XOR        EDX,EDX
//         00539865     CMP        EDI,DAT_0087d4a4
//         0053986b     JLE        LAB_005398a1
//                              view.cpp:5468 (5)
//         0053986d     MOV        EBX,Picked_Objects                               = 00000000
//                               LAB_00539872                                                 XREF[1]:     00539884(j)
//                              view.cpp:5438 (22)
//         00539872     MOV        EBP,dword ptr [ESP + param_6]
//         00539876     CMP        dword ptr [EBX]=>Picked_Objects,EBP              = 00000000
//         00539878     JZ         LAB_00539888
//         0053987a     MOV        EBP,dword ptr [ESP + local_c]
//         0053987e     INC        EDX
//         0053987f     ADD        EBX,0xc
//         00539882     CMP        EDX,EBP
//         00539884     JL         LAB_00539872
//         00539886     JMP        LAB_005398a1
//                               LAB_00539888                                                 XREF[1]:     00539878(j)
//                              view.cpp:5441 (25)
//         00539888     LEA        EDX,[EDX + EDX*0x2]
//         0053988b     XOR        this,this
//         0053988d     MOVSX      EBX,word ptr [EDX*0x4 + 0x87d4a4]=>DAT_0087d4b0
//         00539895     CMP        EBX,EAX
//         00539897     JLE        LAB_005398a1
//         00539899     MOV        word ptr [EDX*0x4 + 0x87d4a4]=>DAT_0087d4b0,AX
//                               LAB_005398a1                                                 XREF[4]:     00539861(j), 0053986b(j),
//                                                                                                         00539886(j), 00539897(j)
//                              view.cpp:5449 (4)
//         005398a1     TEST       this,this
//         005398a3     JZ         LAB_005398cf
//                              view.cpp:5451 (7)
//         005398a5     MOV        EDX,dword ptr [ESP + param_6]
//         005398a9     MOV        dword ptr [EDI + -0x4]=>Picked_Objects,EDX       = 00000000
//                              view.cpp:5452 (3)
//         005398ac     MOV        word ptr [EDI]=>DAT_0087d4a4,AX
//                              view.cpp:5453 (4)
//         005398af     MOV        word ptr [EDI + 0x2]=>DAT_0087d4a6,AX
//                              view.cpp:5454 (8)
//         005398b3     MOV        AX,word ptr [ESI + 0x14]
//         005398b7     MOV        word ptr [EDI + 0x4]=>DAT_0087d4a8,AX
//                              view.cpp:5455 (8)
//         005398bb     MOV        this,word ptr [ESI + 0x18]
//         005398bf     MOV        word ptr [EDI + 0x6]=>DAT_0087d4aa,this
//                              view.cpp:5456 (12)
//         005398c3     MOV        this,dword ptr [ESP + local_c]
//         005398c7     INC        this
//         005398c8     ADD        EDI,0xc
//         005398cb     MOV        dword ptr [ESP + local_c],this
//                               LAB_005398cf                                                 XREF[1]:     005398a3(j)
//                              view.cpp:5459 (8)
//         005398cf     CMP        EDI,view_debug_redraw_all
//         005398d5     JGE        LAB_0053990b
//                               LAB_005398d7                                                 XREF[1]:     00539850(j)
//                              view.cpp:5462 (40)
//         005398d7     MOV        ESI,dword ptr [ESI + 0x4]
//         005398da     TEST       ESI,ESI
//         005398dc     JNZ        LAB_005397cd
//         005398e2     MOV        this,dword ptr [ESP + param_5]
//         005398e6     MOV        EAX,dword ptr [ESP + local_4]
//         005398ea     MOV        EBX,dword ptr [ESP + z]
//         005398ee     MOV        EBP,dword ptr [ESP + local_c]
//                               LAB_005398f2                                                 XREF[1]:     005397bc(j)
//         005398f2     DEC        EAX
//         005398f3     CMP        EAX,this
//         005398f5     MOV        dword ptr [ESP + local_4],EAX
//         005398f9     JGE        LAB_005397ae
//                               LAB_005398ff                                                 XREF[1]:     005397a8(j)
//                              view.cpp:5466 (2)
//         005398ff     MOV        EAX,EBP
//                              view.cpp:5468 (10)
//         00539901     POP        EDI
//         00539902     POP        ESI
//         00539903     POP        EBP
//         00539904     POP        EBX
//         00539905     ADD        ESP,0xc
//         00539908     RET        0x24
//                               LAB_0053990b                                                 XREF[1]:     005398d5(j)
//                              view.cpp:5459 (5)
//         0053990b     MOV        EAX,0x40
//                              view.cpp:5468 (22)
//         00539910     POP        EDI
//         00539911     POP        ESI
//         00539912     POP        EBP
//         00539913     POP        EBX
//         00539914     ADD        ESP,0xc
//         00539917     RET        0x24
//                               LAB_0053991a                                                 XREF[6]:     0053970f(j), 00539721(j),
//                                                                                                         00539733(j), 00539745(j),
//                                                                                                         00539752(j), 0053975e(j)
//         0053991a     POP        EDI
//         0053991b     POP        ESI
//         0053991c     POP        EBP
//         0053991d     XOR        EAX,EAX
//         0053991f     POP        EBX
//         00539920     ADD        ESP,0xc
//         00539923     RET        0x24
//         00539926     ??         90h
//         00539927     NOP
//         00539928     NOP
//         00539929     NOP
//         0053992a     NOP
//         0053992b     NOP
//         0053992c     NOP
//         0053992d     NOP
//         0053992e     NOP
//         0053992f     NOP
    return 0;
}

int RGE_View::pick_touched_object(DClipInfo_List* param_1, int param_2, int param_3, int param_4, int param_5, int* param_6) {
    /* TODO: Stub */
//                              int __thiscall pick_touched_object(RGE_View * this, DClipInfo_List *
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              DClipInfo_List    Stack[0x4]:4   param_1                   XREF[1]:     005399cd(R)
//              int               Stack[0x8]:4   param_2                   XREF[3]:     00539950(R), 00539a05(R), 00539a30(R)
//              int               Stack[0xc]:4   param_3                   XREF[4]:     0053996e(R), 005399c3(W), 00539a6a(R), 00539a82(W)
//              int               Stack[0x10]:4  param_4                   XREF[4]:     00539934(R), 005399a1(W), 005399b3(R), 00539a7b(R)
//              int               Stack[0x14]:4  param_5                   XREF[5]:     00539940(R), 005399bb(W), 00539a24(W), 00539a55(W),
//                                                                                     00539a6e(R)
//              int *             Stack[0x18]:4  param_6                   XREF[3]:     00539930(R), 00539a1d(R), 00539a4e(R)
//                               ?pick_touched_object@RGE_View@@IAEHPAVDClipInfo_List@@HHHHA  XREF[1]:     view_function_terrain:005379f3(c)
//                               RGE_View::pick_touched_object
//                              view.cpp:5477 (4)
//         00539930     MOV        EAX,dword ptr [ESP + param_6]
//                              view.cpp:5486 (28)
//         00539934     MOV        EDX,dword ptr [ESP + param_4]
//         00539938     PUSH       EBX
//         00539939     PUSH       EBP
//         0053993a     MOV        dword ptr [EAX],0x0
//         00539940     MOV        EAX,dword ptr [ESP + param_5]
//         00539944     PUSH       ESI
//         00539945     CMP        EAX,EDX
//         00539947     PUSH       EDI
//         00539948     MOV        EBP,this
//         0053994a     JL         LAB_00539a8c
//                              view.cpp:5491 (60)
//         00539950     MOV        this,dword ptr [ESP + param_2]
//         00539954     MOV        ESI,dword ptr [EBP + 0x8c]
//         0053995a     CMP        this,ESI
//         0053995c     JL         LAB_00539a8c
//         00539962     CMP        this,dword ptr [EBP + 0x94]
//         00539968     JG         LAB_00539a8c
//         0053996e     MOV        EBX,dword ptr [ESP + param_3]
//         00539972     MOV        this,dword ptr [EBP + 0x90]
//         00539978     CMP        EBX,this
//         0053997a     JL         LAB_00539a8c
//         00539980     CMP        EBX,dword ptr [EBP + 0x98]
//         00539986     JG         LAB_00539a8c
//                              view.cpp:5493 (17)
//         0053998c     CMP        EDX,0x28
//         0053998f     JG         LAB_00539a8c
//         00539995     TEST       EAX,EAX
//         00539997     JL         LAB_00539a8c
//                              view.cpp:5497 (12)
//         0053999d     TEST       EDX,EDX
//         0053999f     JGE        LAB_005399a9
//         005399a1     MOV        dword ptr [ESP + param_4],0x0
//                               LAB_005399a9                                                 XREF[1]:     0053999f(j)
//                              view.cpp:5499 (10)
//         005399a9     CMP        EAX,0x28
//         005399ac     JLE        LAB_005399b3
//         005399ae     MOV        EAX,0x28
//                               LAB_005399b3                                                 XREF[1]:     005399ac(j)
//                              view.cpp:5510 (26)
//         005399b3     MOV        EDX,dword ptr [ESP + param_4]
//         005399b7     MOV        this,EAX
//         005399b9     CMP        EAX,EDX
//         005399bb     MOV        dword ptr [ESP + param_5],0x0
//         005399c3     MOV        dword ptr [ESP + param_3],this
//         005399c7     JL         LAB_00539a8c
//                               LAB_005399cd                                                 XREF[1]:     00539a86(j)
//                              view.cpp:5512 (10)
//         005399cd     MOV        EDX,dword ptr [ESP + param_1]
//         005399d1     MOV        EAX,dword ptr [EDX + 0x5c]
//         005399d4     MOV        ESI,dword ptr [EAX + this->_padding_*0x4]
//                              view.cpp:5514 (8)
//         005399d7     TEST       ESI,ESI
//         005399d9     JZ         LAB_00539a6e
//                               LAB_005399df                                                 XREF[1]:     00539a64(j)
//                              view.cpp:5516 (7)
//         005399df     MOV        EAX,dword ptr [ESI + 0x2c]
//         005399e2     TEST       EAX,EAX
//         005399e4     JNZ        LAB_00539a5f
//                              view.cpp:5525 (27)
//         005399e6     MOV        EDX,dword ptr [ESI + 0x1c]
//         005399e9     MOVSX      EDI,word ptr [ESI + 0x30]
//         005399ed     MOVSX      this,word ptr [ESI + 0x32]
//         005399f1     MOVSX      EAX,word ptr [ESI + 0x34]
//         005399f5     AND        EDX,0x2
//         005399f8     CMP        DL,0x2
//         005399fb     MOV        EDX,EBX
//         005399fd     JNZ        LAB_00539a30
//         005399ff     SUB        EDX,this
//                              view.cpp:5527 (28)
//         00539a01     MOV        this,dword ptr [ESI + 0x20]
//         00539a04     PUSH       EDX
//         00539a05     MOV        EDX,dword ptr [ESP + param_2]
//         00539a09     SUB        EAX,EDX
//         00539a0b     PUSH       EAX
//         00539a0c     MOV        EAX,dword ptr [ESI + 0xc]
//         00539a0f     PUSH       EAX
//         00539a10     PUSH       this
//         00539a11     MOV        this,EBP
//         00539a13     CALL       RGE_View::sprite_check                           int sprite_check(RGE_View * this, uchar * par
//         00539a18     CMP        EAX,0x2
//         00539a1b     JNZ        LAB_00539a5f
//                              view.cpp:5530 (17)
//         00539a1d     MOV        EAX,dword ptr [ESP + param_6]
//         00539a21     MOV        EDX,dword ptr [ESI + 0x8]
//         00539a24     MOV        dword ptr [ESP + param_5],0x1
//         00539a2c     MOV        dword ptr [EAX],EDX
//                              view.cpp:5532 (2)
//         00539a2e     JMP        LAB_00539a5f
//                               LAB_00539a30                                                 XREF[1]:     005399fd(j)
//                              view.cpp:5514 (6)
//         00539a30     MOV        EAX,dword ptr [ESP + param_2]
//         00539a34     SUB        EDX,this
//                              view.cpp:5534 (24)
//         00539a36     MOV        this,dword ptr [ESI + 0xc]
//         00539a39     SUB        EAX,EDI
//         00539a3b     PUSH       EDX
//         00539a3c     MOV        EDX,dword ptr [ESI + 0x20]
//         00539a3f     PUSH       EAX
//         00539a40     PUSH       this
//         00539a41     PUSH       EDX
//         00539a42     MOV        this,EBP
//         00539a44     CALL       RGE_View::sprite_check                           int sprite_check(RGE_View * this, uchar * par
//         00539a49     CMP        EAX,0x2
//         00539a4c     JNZ        LAB_00539a5f
//                              view.cpp:5537 (17)
//         00539a4e     MOV        this,dword ptr [ESP + param_6]
//         00539a52     MOV        EAX,dword ptr [ESI + 0x8]
//         00539a55     MOV        dword ptr [ESP + param_5],0x1
//         00539a5d     MOV        dword ptr [this->_padding_],EAX
//                               LAB_00539a5f                                                 XREF[4]:     005399e4(j), 00539a1b(j),
//                                                                                                         00539a2e(j), 00539a4c(j)
//                              view.cpp:5542 (11)
//         00539a5f     MOV        ESI,dword ptr [ESI + 0x4]
//         00539a62     TEST       ESI,ESI
//         00539a64     JNZ        LAB_005399df
//                              view.cpp:5514 (4)
//         00539a6a     MOV        this,dword ptr [ESP + param_3]
//                               LAB_00539a6e                                                 XREF[1]:     005399d9(j)
//                              view.cpp:5545 (30)
//         00539a6e     MOV        EDX,dword ptr [ESP + param_5]
//         00539a72     MOV        EAX,0x1
//         00539a77     CMP        EDX,EAX
//         00539a79     JZ         LAB_00539a8e
//         00539a7b     MOV        EAX,dword ptr [ESP + param_4]
//         00539a7f     DEC        this
//         00539a80     CMP        this,EAX
//         00539a82     MOV        dword ptr [ESP + param_3],this
//         00539a86     JGE        LAB_005399cd
//                               LAB_00539a8c                                                 XREF[8]:     0053994a(j), 0053995c(j),
//                                                                                                         00539968(j), 0053997a(j),
//                                                                                                         00539986(j), 0053998f(j),
//                                                                                                         00539997(j), 005399c7(j)
//                              view.cpp:5491 (2)
//         00539a8c     XOR        EAX,EAX
//                               LAB_00539a8e                                                 XREF[1]:     00539a79(j)
//                              view.cpp:5550 (7)
//         00539a8e     POP        EDI
//         00539a8f     POP        ESI
//         00539a90     POP        EBP
//         00539a91     POP        EBX
//         00539a92     RET        0x18
//         00539a95     ??         90h
//         00539a96     NOP
//         00539a97     NOP
//         00539a98     NOP
//         00539a99     NOP
//         00539a9a     NOP
//         00539a9b     NOP
//         00539a9c     NOP
//         00539a9d     NOP
//         00539a9e     NOP
//         00539a9f     NOP
    return 0;
}

short RGE_View::get_tile_picture(uchar param_1, uchar param_2, short param_3, short param_4) {
    /* TODO: Stub */
//                              short __thiscall get_tile_picture(RGE_View * this, uchar param_1, uc
//              short             AX:2           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[3]:     00539aa0(R), 00539b16(W), 00539b2e(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[3]:     00539adb(R), 00539b1a(W), 00539b4a(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     00539b45(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00539b29(R)
//                               ?get_tile_picture@RGE_View@@IAEFEEFF@Z                       XREF[2]:     draw_tile:005388c5(c),
//                               RGE_View::get_tile_picture                                                hit_tile:00539e55(c)
//                              view.cpp:5559 (37)
//         00539aa0     MOV        EDX,dword ptr [ESP + param_1]
//         00539aa4     MOV        this,dword ptr [ECX + this->map]
//         00539aaa     AND        EDX,0xff
//         00539ab0     PUSH       EBX
//         00539ab1     MOV        EAX,EDX
//         00539ab3     PUSH       EBP
//         00539ab4     SHL        EAX,0x4
//         00539ab7     ADD        EAX,EDX
//         00539ab9     PUSH       ESI
//         00539aba     PUSH       EDI
//         00539abb     LEA        EAX,[EAX + EAX*0x2]
//         00539abe     LEA        EDX,[ECX + EAX*0x8 + this->_padding_]
//                              view.cpp:5567 (11)
//         00539ac5     MOV        EAX,dword ptr [ECX + EAX*0x8 + this->_padding_]
//         00539acc     TEST       EAX,EAX
//         00539ace     JNZ        LAB_00539adb
//                              view.cpp:5568 (4)
//         00539ad0     OR         AX,0xffff
//                              view.cpp:5610 (7)
//         00539ad4     POP        EDI
//         00539ad5     POP        ESI
//         00539ad6     POP        EBP
//         00539ad7     POP        EBX
//         00539ad8     RET        0x10
//                               LAB_00539adb                                                 XREF[1]:     00539ace(j)
//                              view.cpp:5570 (12)
//         00539adb     MOV        EAX,dword ptr [ESP + param_2]
//         00539adf     AND        EAX,0xff
//         00539ae4     LEA        EAX,[EAX + EAX*0x2]
//                              view.cpp:5572 (9)
//         00539ae7     MOV        SI,word ptr [EDX + EAX*0x2 + 0x46]
//         00539aec     LEA        EDI,[EDX + EAX*0x2 + 0x46]
//                              view.cpp:5573 (5)
//         00539af0     TEST       SI,SI
//         00539af3     JNZ        LAB_00539b00
//                              view.cpp:5574 (4)
//         00539af5     OR         AX,0xffff
//                              view.cpp:5610 (7)
//         00539af9     POP        EDI
//         00539afa     POP        ESI
//         00539afb     POP        EBP
//         00539afc     POP        EBX
//         00539afd     RET        0x10
//                               LAB_00539b00                                                 XREF[1]:     00539af3(j)
//                              view.cpp:5576 (2)
//         00539b00     XOR        this,this
//                              view.cpp:5577 (6)
//         00539b02     CMP        SI,0x1
//         00539b06     JLE        LAB_00539b6d
//                              view.cpp:5588 (6)
//         00539b08     MOV        AL,byte ptr [EDX + 0xba]
//                              view.cpp:5589 (6)
//         00539b0e     MOV        BL,byte ptr [EDX + 0xbc]
//                              view.cpp:5590 (17)
//         00539b14     CMP        AL,0x1
//         00539b16     MOV        byte ptr [ESP + param_1],AL
//         00539b1a     MOV        byte ptr [ESP + param_2],BL
//         00539b1e     JA         LAB_00539b25
//         00539b20     CMP        BL,0x1
//         00539b23     JBE        LAB_00539b6d
//                               LAB_00539b25                                                 XREF[1]:     00539b1e(j)
//                              view.cpp:5592 (4)
//         00539b25     TEST       AL,AL
//         00539b27     JBE        LAB_00539b3f
//                              view.cpp:5593 (20)
//         00539b29     MOVSX      EAX,word ptr [ESP + param_4]
//         00539b2e     MOV        this,dword ptr [ESP + param_1]
//         00539b32     CDQ
//         00539b33     AND        this,0xff
//         00539b39     IDIV       this
//         00539b3b     MOV        this,DL
//                              view.cpp:5594 (2)
//         00539b3d     JMP        LAB_00539b41
//                               LAB_00539b3f                                                 XREF[1]:     00539b27(j)
//                              view.cpp:5595 (2)
//         00539b3f     XOR        this,this
//                               LAB_00539b41                                                 XREF[1]:     00539b3d(j)
//                              view.cpp:5596 (4)
//         00539b41     TEST       BL,BL
//         00539b43     JBE        LAB_00539b59
//                              view.cpp:5597 (18)
//         00539b45     MOVSX      EAX,word ptr [ESP + param_3]
//         00539b4a     MOV        EBP,dword ptr [ESP + param_2]
//         00539b4e     CDQ
//         00539b4f     AND        EBP,0xff
//         00539b55     IDIV       EBP
//                              view.cpp:5598 (2)
//         00539b57     JMP        LAB_00539b5b
//                               LAB_00539b59                                                 XREF[1]:     00539b43(j)
//                              view.cpp:5599 (2)
//         00539b59     XOR        DL,DL
//                               LAB_00539b5b                                                 XREF[1]:     00539b57(j)
//                              view.cpp:5600 (18)
//         00539b5b     MOVZX      this,this
//         00539b5f     XOR        AX,AX
//         00539b62     MOV        AL,BL
//         00539b64     IMUL       this,EAX
//         00539b67     MOVZX      DX,DL
//         00539b6b     ADD        this,EDX
//                               LAB_00539b6d                                                 XREF[2]:     00539b06(j), 00539b23(j)
//                              view.cpp:5605 (11)
//         00539b6d     MOVSX      EAX,SI
//         00539b70     MOVSX      EDX,this
//         00539b73     DEC        EAX
//         00539b74     CMP        EDX,EAX
//         00539b76     JLE        LAB_00539b7a
//                              view.cpp:5606 (2)
//         00539b78     XOR        this,this
//                               LAB_00539b7a                                                 XREF[1]:     00539b76(j)
//                              view.cpp:5609 (11)
//         00539b7a     MOV        AX,word ptr [EDI + 0x2]
//         00539b7e     IMUL       EAX,this
//         00539b81     MOV        this,word ptr [EDI + 0x4]
//                              view.cpp:5610 (9)
//         00539b85     POP        EDI
//         00539b86     POP        ESI
//         00539b87     POP        EBP
//         00539b88     ADD        EAX,this
//         00539b8a     POP        EBX
//         00539b8b     RET        0x10
//         00539b8e     ??         90h
//         00539b8f     NOP
    return 0;
}

short RGE_View::get_border_picture(uchar param_1, uchar param_2, uchar param_3, short param_4, short param_5) {
    /* TODO: Stub */
//                              short __thiscall get_border_picture(RGE_View * this, uchar param_1,
//              short             AX:2           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00539b90(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00539bc3(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[1]:     00539bc7(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00539c50(R)
//              short             Stack[0x14]:2  param_5                   XREF[1]:     00539c25(R)
//                               ?get_border_picture@RGE_View@@IAEFEEEFF@Z                    XREF[6]:     draw_tile:005387dd(c),
//                               RGE_View::get_border_picture                                              draw_tile:005389f8(c),
//                                                                                                         get_border_edge_pictures:00539cfb(
//                                                                                                         get_border_edge_pictures:00539d1d(
//                                                                                                         get_border_edge_pictures:00539d3f(
//                                                                                                         get_border_edge_pictures:00539d61(
//                              view.cpp:5617 (34)
//         00539b90     MOV        EAX,dword ptr [ESP + param_1]
//         00539b94     MOV        this,dword ptr [ECX + this->map]
//         00539b9a     AND        EAX,0xff
//         00539b9f     PUSH       EBX
//         00539ba0     PUSH       ESI
//         00539ba1     PUSH       EDI
//         00539ba2     LEA        EAX,[EAX + EAX*0x4]
//         00539ba5     LEA        EAX,[EAX + EAX*0x8]
//         00539ba8     SHL        EAX,0x5
//         00539bab     LEA        this,[EAX + this->_padding_*0x1 + 0x338c]
//                              view.cpp:5626 (7)
//         00539bb2     MOV        EAX,dword ptr [ECX + this->_padding_]
//         00539bb5     TEST       EAX,EAX
//         00539bb7     JNZ        LAB_00539bc3
//                              view.cpp:5627 (4)
//         00539bb9     OR         AX,0xffff
//                              view.cpp:5671 (6)
//         00539bbd     POP        EDI
//         00539bbe     POP        ESI
//         00539bbf     POP        EBX
//         00539bc0     RET        0x14
//                               LAB_00539bc3                                                 XREF[1]:     00539bb7(j)
//                              view.cpp:5629 (30)
//         00539bc3     MOV        EAX,dword ptr [ESP + param_2]
//         00539bc7     MOV        EBX,dword ptr [ESP + param_3]
//         00539bcb     AND        EAX,0xff
//         00539bd0     LEA        EDX,[EAX + EAX*0x2]
//         00539bd3     MOV        EAX,EBX
//         00539bd5     AND        EAX,0xff
//         00539bda     LEA        EAX,[EAX + EDX*0x4 + 0xa]
//         00539bde     LEA        EDX,[EAX + EAX*0x2]
//                              view.cpp:5630 (7)
//         00539be1     MOV        SI,word ptr [this->_padding_ + EDX*0x2]
//         00539be5     LEA        EDI,[this->_padding_ + EDX*0x2]
//                              view.cpp:5632 (5)
//         00539be8     TEST       SI,SI
//         00539beb     JNZ        LAB_00539bf7
//                              view.cpp:5633 (4)
//         00539bed     OR         AX,0xffff
//                              view.cpp:5671 (6)
//         00539bf1     POP        EDI
//         00539bf2     POP        ESI
//         00539bf3     POP        EBX
//         00539bf4     RET        0x14
//                               LAB_00539bf7                                                 XREF[1]:     00539beb(j)
//                              view.cpp:5635 (2)
//         00539bf7     XOR        EDX,EDX
//                              view.cpp:5636 (6)
//         00539bf9     CMP        SI,0x1
//         00539bfd     JLE        LAB_00539c5f
//                              view.cpp:5641 (7)
//         00539bff     MOV        this,word ptr [this->_padding_ + 0x59e]
//                              view.cpp:5648 (31)
//         00539c06     TEST       this,this
//         00539c09     JNZ        LAB_00539c15
//         00539c0b     CMP        BL,0xb
//         00539c0e     JZ         LAB_00539c25
//         00539c10     CMP        BL,0xc
//         00539c13     JZ         LAB_00539c25
//                               LAB_00539c15                                                 XREF[1]:     00539c09(j)
//         00539c15     CMP        this,0x1
//         00539c19     JNZ        LAB_00539c32
//         00539c1b     CMP        BL,0x3
//         00539c1e     JZ         LAB_00539c25
//         00539c20     CMP        BL,0x2
//         00539c23     JNZ        LAB_00539c32
//                               LAB_00539c25                                                 XREF[3]:     00539c0e(j), 00539c13(j),
//                                                                                                         00539c1e(j)
//                              view.cpp:5649 (11)
//         00539c25     MOVSX      EAX,word ptr [ESP + param_5]
//         00539c2a     MOVSX      this,SI
//         00539c2d     CDQ
//         00539c2e     IDIV       this
//                              view.cpp:5651 (2)
//         00539c30     JMP        LAB_00539c5f
//                               LAB_00539c32                                                 XREF[2]:     00539c19(j), 00539c23(j)
//                              view.cpp:5656 (30)
//         00539c32     TEST       this,this
//         00539c35     JNZ        LAB_00539c41
//         00539c37     CMP        BL,0x9
//         00539c3a     JZ         LAB_00539c50
//         00539c3c     CMP        BL,0xa
//         00539c3f     JZ         LAB_00539c50
//                               LAB_00539c41                                                 XREF[1]:     00539c35(j)
//         00539c41     CMP        this,0x1
//         00539c45     JNZ        LAB_00539c5d
//         00539c47     CMP        BL,this
//         00539c49     JZ         LAB_00539c50
//         00539c4b     CMP        BL,0x4
//         00539c4e     JNZ        LAB_00539c5d
//                               LAB_00539c50                                                 XREF[3]:     00539c3a(j), 00539c3f(j),
//                                                                                                         00539c49(j)
//                              view.cpp:5657 (11)
//         00539c50     MOVSX      EAX,word ptr [ESP + param_4]
//         00539c55     MOVSX      this,SI
//         00539c58     CDQ
//         00539c59     IDIV       this
//                              view.cpp:5659 (2)
//         00539c5b     JMP        LAB_00539c5f
//                               LAB_00539c5d                                                 XREF[2]:     00539c45(j), 00539c4e(j)
//                              view.cpp:5663 (2)
//         00539c5d     XOR        EDX,EDX
//                               LAB_00539c5f                                                 XREF[3]:     00539bfd(j), 00539c30(j),
//                                                                                                         00539c5b(j)
//                              view.cpp:5667 (11)
//         00539c5f     MOVSX      EAX,SI
//         00539c62     MOVSX      this,DX
//         00539c65     DEC        EAX
//         00539c66     CMP        this,EAX
//         00539c68     JLE        LAB_00539c6c
//                              view.cpp:5668 (2)
//         00539c6a     XOR        EDX,EDX
//                               LAB_00539c6c                                                 XREF[1]:     00539c68(j)
//                              view.cpp:5670 (11)
//         00539c6c     MOV        AX,word ptr [EDI + 0x2]
//         00539c70     IMUL       EAX,EDX
//         00539c73     MOV        DX,word ptr [EDI + 0x4]
//                              view.cpp:5671 (8)
//         00539c77     POP        EDI
//         00539c78     POP        ESI
//         00539c79     ADD        EAX,EDX
//         00539c7b     POP        EBX
//         00539c7c     RET        0x14
//         00539c7f     ??         90h
    return 0;
}

int RGE_View::get_border_edge_pictures(uchar param_1, uchar param_2, uchar param_3, short param_4, short param_5, int* param_6, int* param_7, int* param_8, int* param_9) {
    /* TODO: Stub */
//                              int __thiscall get_border_edge_pictures(RGE_View * this, uchar param
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[1]:     00539c9c(R)
//              uchar             Stack[0x8]:1   param_2                   XREF[1]:     00539ce3(R)
//              uchar             Stack[0xc]:1   param_3                   XREF[4]:     00539cd7(R), 00539d07(R), 00539d29(R), 00539d4b(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00539ce7(R)
//              short             Stack[0x14]:2  param_5                   XREF[4]:     00539cef(R), 00539d11(R), 00539d33(R), 00539d55(R)
//              int *             Stack[0x18]:4  param_6                   XREF[2]:     00539c80(R), 00539d00(R)
//              int *             Stack[0x1c]:4  param_7                   XREF[2]:     00539c84(R), 00539d66(R)
//              int *             Stack[0x20]:4  param_8                   XREF[2]:     00539c8d(R), 00539d44(R)
//              int *             Stack[0x24]:4  param_9                   XREF[2]:     00539c97(R), 00539d22(R)
//                               ?get_border_edge_pictures@RGE_View@@IAEHEEEFFAAH000@Z        XREF[2]:     draw_tile:0053882e(c),
//                               RGE_View::get_border_edge_pictures                                        draw_tile:00538a55(c)
//                              view.cpp:5677 (4)
//         00539c80     MOV        EAX,dword ptr [ESP + param_6]
//                              view.cpp:5682 (19)
//         00539c84     MOV        EDX,dword ptr [ESP + param_7]
//         00539c88     PUSH       EBX
//         00539c89     PUSH       EBP
//         00539c8a     PUSH       ESI
//         00539c8b     MOV        ESI,this
//         00539c8d     MOV        this,dword ptr [ESP + param_8]
//         00539c91     MOV        dword ptr [EAX],0xffffffff
//                              view.cpp:5683 (5)
//         00539c97     MOV        EAX,dword ptr [ESP + param_9]
//         00539c9b     PUSH       EDI
//                              view.cpp:5687 (71)
//         00539c9c     MOV        EDI,dword ptr [ESP + param_1]
//         00539ca0     MOV        dword ptr [this->_padding_],0xffffffff
//         00539ca6     MOV        dword ptr [EDX],0xffffffff
//         00539cac     MOV        dword ptr [EAX],0xffffffff
//         00539cb2     MOV        EAX,EDI
//         00539cb4     MOV        EDX,dword ptr [ESI + 0x104]
//         00539cba     AND        EAX,0xff
//         00539cbf     LEA        EAX,[EAX + EAX*0x4]
//         00539cc2     LEA        this,[EAX + EAX*0x8]
//         00539cc5     SHL        this,0x5
//         00539cc8     MOV        EAX,dword ptr [this->_padding_ + EDX*0x1 + 0x3
//         00539ccf     TEST       EAX,EAX
//         00539cd1     JZ         LAB_00539d7b
//         00539cd7     MOV        AL,byte ptr [ESP + param_3]
//         00539cdb     TEST       AL,AL
//         00539cdd     JZ         LAB_00539d7b
//                              view.cpp:5690 (12)
//         00539ce3     MOV        EBP,dword ptr [ESP + param_2]
//         00539ce7     MOV        EBX,dword ptr [ESP + param_4]
//         00539ceb     TEST       AL,0x1
//         00539ced     JZ         LAB_00539d0d
//                              view.cpp:5691 (30)
//         00539cef     MOV        EAX,dword ptr [ESP + param_5]
//         00539cf3     MOV        this,ESI
//         00539cf5     PUSH       EAX
//         00539cf6     PUSH       EBX
//         00539cf7     PUSH       0x1
//         00539cf9     PUSH       EBP
//         00539cfa     PUSH       EDI
//         00539cfb     CALL       RGE_View::get_border_picture                     short get_border_picture(RGE_View * this, uch
//         00539d00     MOV        EDX,dword ptr [ESP + param_6]
//         00539d04     MOVSX      this,AX
//         00539d07     MOV        AL,byte ptr [ESP + param_3]
//         00539d0b     MOV        dword ptr [EDX],this
//                               LAB_00539d0d                                                 XREF[1]:     00539ced(j)
//                              view.cpp:5693 (4)
//         00539d0d     TEST       AL,0x2
//         00539d0f     JZ         LAB_00539d2f
//                              view.cpp:5694 (30)
//         00539d11     MOV        EAX,dword ptr [ESP + param_5]
//         00539d15     MOV        this,ESI
//         00539d17     PUSH       EAX
//         00539d18     PUSH       EBX
//         00539d19     PUSH       0x4
//         00539d1b     PUSH       EBP
//         00539d1c     PUSH       EDI
//         00539d1d     CALL       RGE_View::get_border_picture                     short get_border_picture(RGE_View * this, uch
//         00539d22     MOV        EDX,dword ptr [ESP + param_9]
//         00539d26     MOVSX      this,AX
//         00539d29     MOV        AL,byte ptr [ESP + param_3]
//         00539d2d     MOV        dword ptr [EDX],this
//                               LAB_00539d2f                                                 XREF[1]:     00539d0f(j)
//                              view.cpp:5696 (4)
//         00539d2f     TEST       AL,0x4
//         00539d31     JZ         LAB_00539d51
//                              view.cpp:5697 (30)
//         00539d33     MOV        EAX,dword ptr [ESP + param_5]
//         00539d37     MOV        this,ESI
//         00539d39     PUSH       EAX
//         00539d3a     PUSH       EBX
//         00539d3b     PUSH       0x3
//         00539d3d     PUSH       EBP
//         00539d3e     PUSH       EDI
//         00539d3f     CALL       RGE_View::get_border_picture                     short get_border_picture(RGE_View * this, uch
//         00539d44     MOV        EDX,dword ptr [ESP + param_8]
//         00539d48     MOVSX      this,AX
//         00539d4b     MOV        AL,byte ptr [ESP + param_3]
//         00539d4f     MOV        dword ptr [EDX],this
//                               LAB_00539d51                                                 XREF[1]:     00539d31(j)
//                              view.cpp:5699 (4)
//         00539d51     TEST       AL,0x8
//         00539d53     JZ         LAB_00539d6f
//                              view.cpp:5700 (26)
//         00539d55     MOV        EAX,dword ptr [ESP + param_5]
//         00539d59     MOV        this,ESI
//         00539d5b     PUSH       EAX
//         00539d5c     PUSH       EBX
//         00539d5d     PUSH       0x2
//         00539d5f     PUSH       EBP
//         00539d60     PUSH       EDI
//         00539d61     CALL       RGE_View::get_border_picture                     short get_border_picture(RGE_View * this, uch
//         00539d66     MOV        EDX,dword ptr [ESP + param_7]
//         00539d6a     MOVSX      this,AX
//         00539d6d     MOV        dword ptr [EDX],this
//                               LAB_00539d6f                                                 XREF[1]:     00539d53(j)
//                              view.cpp:5702 (5)
//         00539d6f     MOV        EAX,0x1
//                              view.cpp:5703 (16)
//         00539d74     POP        EDI
//         00539d75     POP        ESI
//         00539d76     POP        EBP
//         00539d77     POP        EBX
//         00539d78     RET        0x24
//                               LAB_00539d7b                                                 XREF[2]:     00539cd1(j), 00539cdd(j)
//         00539d7b     POP        EDI
//         00539d7c     POP        ESI
//         00539d7d     POP        EBP
//         00539d7e     XOR        EAX,EAX
//         00539d80     POP        EBX
//         00539d81     RET        0x24
//         00539d84     ??         90h
//         00539d85     NOP
//         00539d86     NOP
//         00539d87     NOP
//         00539d88     NOP
//         00539d89     NOP
//         00539d8a     NOP
//         00539d8b     NOP
//         00539d8c     NOP
//         00539d8d     NOP
//         00539d8e     NOP
//         00539d8f     NOP
    return 0;
}

int RGE_View::hit_tile(RGE_Tile* param_1, short param_2, short param_3, short param_4, short param_5, tagPOINT* param_6) {
    /* TODO: Stub */
//                              int __thiscall hit_tile(RGE_View * this, RGE_Tile * param_1, short p
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Tile *        Stack[0x4]:4   param_1                   XREF[4]:     00539d91(R), 00539dab(W), 00539db7(W), 00539e47(R)
//              short             Stack[0x8]:2   param_2                   XREF[2]:     00539dc1(R), 00539e82(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     00539ded(R)
//              short             Stack[0x10]:2  param_4                   XREF[1]:     00539e43(R)
//              short             Stack[0x14]:2  param_5                   XREF[1]:     00539e3f(R)
//              tagPOINT *        Stack[0x18]:4  param_6                   XREF[2]:     00539dbd(R), 00539e6a(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00539d9d(W), 00539e4f(R)
//                               ?hit_tile@RGE_View@@IAEHPAURGE_Tile@@FFFFPAUtagPOINT@@@Z     XREF[1]:     view_function:00536544(c)
//                               RGE_View::hit_tile
//                              view.cpp:5709 (1)
//         00539d90     PUSH       this
//                              view.cpp:5715 (18)
//         00539d91     MOV        EAX,dword ptr [ESP + param_1]
//         00539d95     PUSH       EBX
//         00539d96     PUSH       EBP
//         00539d97     XOR        EBP,EBP
//         00539d99     PUSH       ESI
//         00539d9a     CMP        EAX,EBP
//         00539d9c     PUSH       EDI
//         00539d9d     MOV        dword ptr [ESP + local_4],this
//         00539da1     JZ         LAB_00539db7
//                              view.cpp:5717 (5)
//         00539da3     MOVZX      DX,byte ptr [EAX + 0x4]
//                              view.cpp:5718 (13)
//         00539da8     MOV        AL,byte ptr [EAX + 0x5]
//         00539dab     MOV        dword ptr [ESP + param_1],EDX
//         00539daf     AND        AL,0x1f
//         00539db1     MOVZX      BP,AL
//                              view.cpp:5720 (2)
//         00539db5     JMP        LAB_00539dbd
//                               LAB_00539db7                                                 XREF[1]:     00539da1(j)
//                              view.cpp:5722 (4)
//         00539db7     MOV        dword ptr [ESP + param_1],EBP
//                              view.cpp:5723 (2)
//         00539dbb     MOV        EDX,EBP
//                               LAB_00539dbd                                                 XREF[1]:     00539db5(j)
//                              view.cpp:5731 (84)
//         00539dbd     MOV        EDI,dword ptr [ESP + param_6]
//         00539dc1     MOVSX      EBX,word ptr [ESP + param_2]
//         00539dc6     MOV        ESI,dword ptr [EDI]
//         00539dc8     CMP        ESI,EBX
//         00539dca     JL         LAB_00539eb2
//         00539dd0     MOVSX      EAX,DX
//         00539dd3     MOV        this,dword ptr [ECX + this->map]
//         00539dd9     LEA        EDX,[EAX + 0x4]
//         00539ddc     LEA        EDX,[EDX + EDX*0x2]
//         00539ddf     MOVSX      EDX,word ptr [this->_padding_ + EDX*0x2]
//         00539de3     ADD        EDX,EBX
//         00539de5     CMP        ESI,EDX
//         00539de7     JGE        LAB_00539eb2
//         00539ded     MOVSX      EBX,word ptr [ESP + param_3]
//         00539df2     MOV        EDX,dword ptr [EDI + 0x4]
//         00539df5     CMP        EDX,EBX
//         00539df7     JL         LAB_00539eb2
//         00539dfd     LEA        EDI,[EAX + EAX*0x2]
//         00539e00     SHL        EDI,0x1
//         00539e02     MOVSX      EAX,word ptr [EDI + this->_padding_*0x1 + 0x1a]
//         00539e07     ADD        EAX,EBX
//         00539e09     CMP        EDX,EAX
//         00539e0b     JGE        LAB_00539eb2
//                              view.cpp:5734 (40)
//         00539e11     CMP        BP,word ptr [this->_padding_ + 0x8d90]
//         00539e18     JGE        LAB_00539ea5
//         00539e1e     MOVSX      EDX,BP
//         00539e21     MOV        EAX,EDX
//         00539e23     SHL        EAX,0x4
//         00539e26     ADD        EAX,EDX
//         00539e28     LEA        EDX,[EAX + EAX*0x2]
//         00539e2b     LEA        EAX,[this->_padding_ + EDX*0x8]
//         00539e2e     MOV        this,byte ptr [ECX + EDX*0x8 + this->_padding_]
//         00539e35     TEST       this,this
//         00539e37     JZ         LAB_00539ea5
//                              view.cpp:5738 (6)
//         00539e39     MOV        ESI,dword ptr [EAX + 0xac]
//                              view.cpp:5739 (27)
//         00539e3f     MOV        EAX,dword ptr [ESP + param_5]
//         00539e43     MOV        this,dword ptr [ESP + param_4]
//         00539e47     MOV        EDX,dword ptr [ESP + param_1]
//         00539e4b     PUSH       EAX
//         00539e4c     PUSH       this
//         00539e4d     PUSH       EDX
//         00539e4e     PUSH       EBP
//         00539e4f     MOV        EBP,dword ptr [ESP + local_4]
//         00539e53     MOV        this,EBP
//         00539e55     CALL       RGE_View::get_tile_picture                       short get_tile_picture(RGE_View * this, uchar
//                              view.cpp:5740 (10)
//         00539e5a     TEST       ESI,ESI
//         00539e5c     JZ         LAB_00539ea5
//         00539e5e     CMP        AX,0xffff
//         00539e62     JZ         LAB_00539ea5
//                              view.cpp:5743 (24)
//         00539e64     MOV        EBP,dword ptr [EBP + 0x104]
//         00539e6a     MOV        EDX,dword ptr [ESP + param_6]
//         00539e6e     MOVSX      EDI,word ptr [EBP + EDI*0x1 + 0x1a]
//         00539e73     MOV        this,dword ptr [EDX + 0x4]
//         00539e76     ADD        EDI,EBX
//         00539e78     CMP        this,EDI
//         00539e7a     JGE        LAB_00539eb2
//                              view.cpp:5746 (28)
//         00539e7c     MOVSX      EAX,AX
//         00539e7f     PUSH       EAX
//         00539e80     SUB        this,EBX
//         00539e82     MOVSX      EAX,word ptr [ESP + param_2]
//         00539e87     PUSH       this
//         00539e88     MOV        this,dword ptr [EDX]
//         00539e8a     SUB        this,EAX
//         00539e8c     PUSH       this
//         00539e8d     MOV        this,ESI
//         00539e8f     CALL       TShape::shape_check                              uchar shape_check(TShape * this, long param_1
//         00539e94     TEST       AL,AL
//         00539e96     JZ         LAB_00539eb2
//                              view.cpp:5747 (5)
//         00539e98     MOV        EAX,0x1
//                              view.cpp:5753 (8)
//         00539e9d     POP        EDI
//         00539e9e     POP        ESI
//         00539e9f     POP        EBP
//         00539ea0     POP        EBX
//         00539ea1     POP        this
//         00539ea2     RET        0x18
//                               LAB_00539ea5                                                 XREF[4]:     00539e18(j), 00539e37(j),
//                                                                                                         00539e5c(j), 00539e62(j)
//                              view.cpp:5735 (5)
//         00539ea5     MOV        EAX,0x1
//                              view.cpp:5753 (18)
//         00539eaa     POP        EDI
//         00539eab     POP        ESI
//         00539eac     POP        EBP
//         00539ead     POP        EBX
//         00539eae     POP        this
//         00539eaf     RET        0x18
//                               LAB_00539eb2                                                 XREF[6]:     00539dca(j), 00539de7(j),
//                                                                                                         00539df7(j), 00539e0b(j),
//                                                                                                         00539e7a(j), 00539e96(j)
//         00539eb2     POP        EDI
//         00539eb3     POP        ESI
//         00539eb4     POP        EBP
//         00539eb5     XOR        EAX,EAX
//         00539eb7     POP        EBX
//         00539eb8     POP        this
//         00539eb9     RET        0x18
//         00539ebc     ??         90h
//         00539ebd     NOP
//         00539ebe     NOP
//         00539ebf     NOP
    return 0;
}

RGE_Static_Object* RGE_View::hit_object(RGE_Tile* param_1, short param_2, short param_3, short param_4, short param_5, tagPOINT* param_6, tagPOINT* param_7, short* param_8, short* param_9, RGE_Static_Object* param_10, uchar param_11) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall hit_object(RGE_View * this, RGE_Tile
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              RGE_Tile *        Stack[0x4]:4   param_1                   XREF[2]:     00539ec3(R), 0053a029(*)
//              short             Stack[0x8]:2   param_2                   XREF[1]:     00539eff(R)
//              short             Stack[0xc]:2   param_3                   XREF[1]:     00539efb(R)
//              short             Stack[0x10]:2  param_4
//              short             Stack[0x14]:2  param_5
//              tagPOINT *        Stack[0x18]:4  param_6                   XREF[1]:     00539ef7(R)
//              tagPOINT *        Stack[0x1c]:4  param_7                   XREF[1]:     00539f75(R)
//              short *           Stack[0x20]:4  param_8                   XREF[1]:     0053a058(R)
//              short *           Stack[0x24]:4  param_9                   XREF[1]:     0053a06f(R)
//              RGE_Static_Obj    Stack[0x28]:4  param_10                  XREF[1]:     00539fd3(R)
//              uchar             Stack[0x2c]:1  param_11                  XREF[1]:     00539f1b(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0053a032(*), 0053a050(W), 0053a06a(R)
//              short             Stack[-0x8]:2  min_y                     XREF[3]:     0053a037(*), 0053a04c(W), 0053a05c(R)
//              short             Stack[-0xc]:2  min_x                     XREF[4]:     00539ee9(W), 0053a08b(R), 0053a093(R), 0053a0a3(W)
//              RGE_Object_Nod    Stack[-0x10]:4 save_list                 XREF[4]:     00539eed(W), 00539f03(R), 0053a078(R), 0053a081(W)
//              RGE_Object_Nod    Stack[-0x14]:4 temp                      XREF[4]:     00539ec7(W), 00539f34(R), 00539f94(R), 00539ff5(R)
//              undefined4        Stack[-0x18]:4 local_18                  XREF[7]:     00539ed4(W), 00539fae(W), 00539fdf(R), 00539fed(R),
//                                                                                     0053a00b(R), 0053a03f(W), 0053a0ab(R)
//              RGE_Static_Obj    Stack[-0x1c]:4 picked_obj                XREF[0,1]:   0053a02d(*)
//              short             Stack[-0x1e]:2 max_x
//                               ?hit_object@RGE_View@@IAEPAVRGE_Static_Object@@PAURGE_Tile@  XREF[1]:     view_function:005364bc(c)
//                               RGE_View::hit_object
//                              view.cpp:5761 (3)
//         00539ec0     SUB        ESP,0x1c
//                              view.cpp:5772 (14)
//         00539ec3     MOV        EAX,dword ptr [ESP + param_1]
//         00539ec7     MOV        dword ptr [ESP + temp],this
//         00539ecb     PUSH       EBX
//         00539ecc     PUSH       EBP
//         00539ecd     LEA        this,[EAX + 0xc]
//         00539ed0     PUSH       ESI
//                              view.cpp:5773 (17)
//         00539ed1     TEST       this,this
//         00539ed3     PUSH       EDI
//         00539ed4     MOV        dword ptr [ESP + local_18],0x0
//         00539edc     JZ         LAB_0053a0ab
//                              view.cpp:5778 (5)
//         00539ee2     CALL       RGE_Object_List::sort                            RGE_Object_Node * sort(RGE_Object_List * this)
//                              view.cpp:5780 (28)
//         00539ee7     TEST       EAX,EAX
//         00539ee9     MOV        dword ptr [ESP + min_x],EAX
//         00539eed     MOV        dword ptr [ESP + save_list],EAX
//         00539ef1     JZ         LAB_0053a08b
//         00539ef7     MOV        EBX,dword ptr [ESP + param_6]
//         00539efb     MOV        EDI,dword ptr [ESP + param_3]
//         00539eff     MOV        EBP,dword ptr [ESP + param_2]
//                               LAB_00539f03                                                 XREF[1]:     0053a085(j)
//                              view.cpp:5783 (6)
//         00539f03     MOV        this,dword ptr [ESP + save_list]
//         00539f07     MOV        ESI,dword ptr [this->_padding_]
//                              view.cpp:5784 (8)
//         00539f09     TEST       ESI,ESI
//         00539f0b     JZ         LAB_0053a08b
//                              view.cpp:5787 (88)
//         00539f11     CMP        byte ptr [ESI + 0x48],0x7
//         00539f15     JNC        LAB_0053a078
//         00539f1b     MOV        AL,byte ptr [ESP + param_11]
//         00539f1f     TEST       AL,AL
//         00539f21     JZ         LAB_00539f31
//         00539f23     MOV        EDX,dword ptr [ESI + 0x8]
//         00539f26     MOV        AL,byte ptr [EDX + 0x65]
//         00539f29     TEST       AL,AL
//         00539f2b     JZ         LAB_0053a078
//                               LAB_00539f31                                                 XREF[1]:     00539f21(j)
//         00539f31     MOV        EAX,dword ptr [ESI + 0x8]
//         00539f34     MOV        this,dword ptr [ESP + temp]
//         00539f38     MOV        DL,byte ptr [EAX + 0x8d]
//         00539f3e     MOV        AL,byte ptr [ECX + this->function_parm]
//         00539f44     CMP        DL,AL
//         00539f46     JC         LAB_0053a078
//         00539f4c     MOV        AL,byte ptr [ECX + this->function_mode]
//         00539f52     CMP        AL,0x2b
//         00539f54     JZ         LAB_00539f5a
//         00539f56     CMP        AL,0x2c
//         00539f58     JNZ        LAB_00539fb7
//                               LAB_00539f5a                                                 XREF[1]:     00539f54(j)
//         00539f5a     MOV        EDX,dword ptr [ESI + 0xc]
//         00539f5d     CMP        EDX,dword ptr [ECX + this->player]
//         00539f63     JNZ        LAB_0053a078
//                              view.cpp:5789 (4)
//         00539f69     CMP        AL,0x2c
//         00539f6b     JNZ        LAB_00539fb7
//                              view.cpp:5791 (39)
//         00539f6d     MOV        AX,word ptr [EBX + 0x4]
//         00539f71     MOV        this,word ptr [EBX]
//         00539f74     PUSH       EAX
//         00539f75     MOV        EAX,dword ptr [ESP + param_7]
//         00539f79     PUSH       this
//         00539f7a     MOV        this,ESI
//         00539f7c     MOV        DX,word ptr [EAX + 0x4]
//         00539f80     MOV        AX,word ptr [EAX]
//         00539f83     PUSH       EDX
//         00539f84     PUSH       EAX
//         00539f85     PUSH       EDI
//         00539f86     PUSH       EBP
//         00539f87     CALL       RGE_Static_Object::box_hit_test                  uchar box_hit_test(RGE_Static_Object * this,
//         00539f8c     TEST       AL,AL
//         00539f8e     JZ         LAB_0053a078
//                              view.cpp:5793 (26)
//         00539f94     MOV        this,dword ptr [ESP + temp]
//         00539f98     PUSH       0x0
//         00539f9a     PUSH       ESI
//         00539f9b     MOV        this,dword ptr [ECX + this->player]
//         00539fa1     CALL       RGE_Player::select_one_object                    int select_one_object(RGE_Player * this, RGE_
//         00539fa6     TEST       EAX,EAX
//         00539fa8     JZ         LAB_0053a08b
//                              view.cpp:5795 (4)
//         00539fae     MOV        dword ptr [ESP + local_18],ESI
//                              view.cpp:5798 (5)
//         00539fb2     JMP        LAB_0053a078
//                               LAB_00539fb7                                                 XREF[2]:     00539f58(j), 00539f6b(j)
//                              view.cpp:5800 (28)
//         00539fb7     MOV        DX,word ptr [EBX + 0x4]
//         00539fbb     MOV        AX,word ptr [EBX]
//         00539fbe     PUSH       0x5
//         00539fc0     PUSH       EDX
//         00539fc1     PUSH       EAX
//         00539fc2     PUSH       EDI
//         00539fc3     PUSH       EBP
//         00539fc4     MOV        this,ESI
//         00539fc6     CALL       RGE_Static_Object::hit_test                      uchar hit_test(RGE_Static_Object * this, shor
//         00539fcb     TEST       AL,AL
//         00539fcd     JZ         LAB_0053a078
//                              view.cpp:5803 (30)
//         00539fd3     MOV        EAX,dword ptr [ESP + param_10]
//         00539fd7     TEST       EAX,EAX
//         00539fd9     JZ         LAB_00539fed
//         00539fdb     CMP        ESI,EAX
//         00539fdd     JNZ        LAB_00539fed
//         00539fdf     MOV        this,dword ptr [ESP + local_18]
//         00539fe3     TEST       this,this
//         00539fe5     JNZ        LAB_0053a0b9
//         00539feb     JMP        LAB_00539ff1
//                               LAB_00539fed                                                 XREF[2]:     00539fd9(j), 00539fdd(j)
//         00539fed     MOV        this,dword ptr [ESP + local_18]
//                               LAB_00539ff1                                                 XREF[1]:     00539feb(j)
//                              view.cpp:5810 (30)
//         00539ff1     TEST       this,this
//         00539ff3     JZ         LAB_0053a029
//         00539ff5     MOV        EDX,dword ptr [ESP + temp]
//         00539ff9     MOV        EAX,dword ptr [EDX + 0x100]
//         00539fff     MOV        EDX,dword ptr [ESI + 0xc]
//         0053a002     CMP        EDX,EAX
//         0053a004     JZ         LAB_0053a00f
//         0053a006     CMP        dword ptr [ECX + this->_padding_],EAX
//         0053a009     JZ         LAB_0053a078
//         0053a00b     MOV        this,dword ptr [ESP + local_18]
//                               LAB_0053a00f                                                 XREF[1]:     0053a004(j)
//                              view.cpp:5813 (26)
//         0053a00f     TEST       this,this
//         0053a011     JZ         LAB_0053a029
//         0053a013     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0053a016     MOV        this,dword ptr [ESI + 0x8]
//         0053a019     MOV        DL,byte ptr [ECX + this+0x8d]
//         0053a01f     MOV        this,byte ptr [EAX + 0x8d]
//         0053a025     CMP        DL,this
//         0053a027     JC         LAB_0053a078
//                               LAB_0053a029                                                 XREF[2]:     00539ff3(j), 0053a011(j)
//                              view.cpp:5818 (35)
//         0053a029     LEA        EAX=>param_1,[ESP + 0x30]
//         0053a02d     LEA        this=>picked_obj+0x2,[ESP + 0x12]
//         0053a031     PUSH       EAX
//         0053a032     LEA        EDX=>local_4,[ESP + 0x2c]
//         0053a036     PUSH       this
//         0053a037     LEA        EAX=>min_y,[ESP + 0x2c]
//         0053a03b     PUSH       EDX
//         0053a03c     PUSH       EAX
//         0053a03d     MOV        this,ESI
//         0053a03f     MOV        dword ptr [ESP + local_18],ESI
//         0053a043     CALL       RGE_Static_Object::get_frame                     int get_frame(RGE_Static_Object * this, short
//         0053a048     TEST       EAX,EAX
//         0053a04a     JNZ        LAB_0053a054
//                              view.cpp:5820 (4)
//         0053a04c     MOV        dword ptr [ESP + min_y],EAX
//                              view.cpp:5821 (4)
//         0053a050     MOV        dword ptr [ESP + local_4],EAX
//                               LAB_0053a054                                                 XREF[1]:     0053a04a(j)
//                              view.cpp:5823 (18)
//         0053a054     MOV        this,word ptr [ESI + 0x28]
//         0053a058     MOV        EDX,dword ptr [ESP + param_8]
//         0053a05c     ADD        this,word ptr [ESP + min_y]
//         0053a061     ADD        this,EBP
//         0053a063     MOV        word ptr [EDX],this
//                              view.cpp:5824 (18)
//         0053a066     MOV        AX,word ptr [ESI + 0x2a]
//         0053a06a     ADD        AX,word ptr [ESP + local_4]
//         0053a06f     MOV        this,dword ptr [ESP + param_9]
//         0053a073     ADD        EAX,EDI
//         0053a075     MOV        word ptr [this->_padding_],AX
//                               LAB_0053a078                                                 XREF[9]:     00539f15(j), 00539f2b(j),
//                                                                                                         00539f46(j), 00539f63(j),
//                                                                                                         00539f8e(j), 00539fb2(j),
//                                                                                                         00539fcd(j), 0053a009(j),
//                                                                                                         0053a027(j)
//                              view.cpp:5832 (19)
//         0053a078     MOV        EDX,dword ptr [ESP + save_list]
//         0053a07c     MOV        EAX,dword ptr [EDX + 0x4]
//         0053a07f     TEST       EAX,EAX
//         0053a081     MOV        dword ptr [ESP + save_list],EAX
//         0053a085     JNZ        LAB_00539f03
//                               LAB_0053a08b                                                 XREF[3]:     00539ef1(j), 00539f0b(j),
//                                                                                                         00539fa8(j)
//                              view.cpp:5835 (8)
//         0053a08b     MOV        EAX,dword ptr [ESP + min_x]
//         0053a08f     TEST       EAX,EAX
//         0053a091     JZ         LAB_0053a0ab
//                               LAB_0053a093                                                 XREF[1]:     0053a0a9(j)
//                              view.cpp:5837 (4)
//         0053a093     MOV        EAX,dword ptr [ESP + min_x]
//                              view.cpp:5838 (12)
//         0053a097     PUSH       EAX
//         0053a098     MOV        ESI,dword ptr [EAX + 0x4]
//         0053a09b     CALL       free                                             undefined free()
//         0053a0a0     ADD        ESP,0x4
//                              view.cpp:5839 (8)
//         0053a0a3     MOV        dword ptr [ESP + min_x],ESI
//         0053a0a7     TEST       ESI,ESI
//         0053a0a9     JNZ        LAB_0053a093
//                               LAB_0053a0ab                                                 XREF[2]:     00539edc(j), 0053a091(j)
//                              view.cpp:5843 (4)
//         0053a0ab     MOV        EAX,dword ptr [ESP + local_18]
//                              view.cpp:5844 (22)
//         0053a0af     POP        EDI
//         0053a0b0     POP        ESI
//         0053a0b1     POP        EBP
//         0053a0b2     POP        EBX
//         0053a0b3     ADD        ESP,0x1c
//         0053a0b6     RET        0x2c
//                               LAB_0053a0b9                                                 XREF[1]:     00539fe5(j)
//         0053a0b9     POP        EDI
//         0053a0ba     POP        ESI
//         0053a0bb     POP        EBP
//         0053a0bc     MOV        EAX,this
//         0053a0be     POP        EBX
//         0053a0bf     ADD        ESP,0x1c
//         0053a0c2     RET        0x2c
//         0053a0c5     ??         90h
//         0053a0c6     NOP
//         0053a0c7     NOP
//         0053a0c8     NOP
//         0053a0c9     NOP
//         0053a0ca     NOP
//         0053a0cb     NOP
//         0053a0cc     NOP
//         0053a0cd     NOP
//         0053a0ce     NOP
//         0053a0cf     NOP
    return 0;
}

int RGE_View::start_scroll_view(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall start_scroll_view(RGE_View * this, uchar param_1, lon
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              uchar             Stack[0x4]:1   param_1                   XREF[4]:     0053a0d4(R), 0053a119(W), 0053a122(R), 0053a195(W)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053a0d9(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0053a0df(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053a1f6(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053a1ee(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,7]:   0053a0ea(*), 0053a115(R), 0053a138(*), 0053a14c(R),
//                                                                                     0053a220(*), 0053a10c(R), 0053a155(R)
//                               ?start_scroll_view@RGE_View@@UAEHEJJHH@Z                     XREF[2]:     start_scroll_view:0053f67e(c),
//                               RGE_View::start_scroll_view                                               005776a0(*)
//                              view.cpp:5854 (4)
//         0053a0d0     SUB        ESP,0x14
//         0053a0d3     PUSH       EBX
//                              view.cpp:5859 (22)
//         0053a0d4     MOV        BL,byte ptr [ESP + param_1]
//         0053a0d8     PUSH       EBP
//         0053a0d9     MOV        EBP,dword ptr [ESP + param_2]
//         0053a0dd     PUSH       ESI
//         0053a0de     PUSH       EDI
//         0053a0df     MOV        EDI,dword ptr [ESP + param_3]
//         0053a0e3     CMP        BL,0x3
//         0053a0e6     MOV        ESI,this
//         0053a0e8     JNZ        LAB_0053a133
//                              view.cpp:5862 (18)
//         0053a0ea     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0053a0ee     PUSH       0x0
//         0053a0f0     PUSH       EAX
//         0053a0f1     PUSH       EDI
//         0053a0f2     PUSH       EBP
//         0053a0f3     PUSH       0x0
//         0053a0f5     PUSH       0x28
//         0053a0f7     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:5863 (4)
//         0053a0fc     CMP        AL,0x33
//         0053a0fe     JZ         LAB_0053a10c
//                              view.cpp:5864 (2)
//         0053a100     XOR        EAX,EAX
//                              view.cpp:5914 (10)
//         0053a102     POP        EDI
//         0053a103     POP        ESI
//         0053a104     POP        EBP
//         0053a105     POP        EBX
//         0053a106     ADD        ESP,0x14
//         0053a109     RET        0x14
//                               LAB_0053a10c                                                 XREF[1]:     0053a0fe(j)
//                              view.cpp:5867 (37)
//         0053a10c     FLD        float ptr [ESP + pick_info.scr_x]
//         0053a110     CALL       __ftol                                           undefined __ftol()
//         0053a115     FLD        float ptr [ESP + pick_info.y]
//         0053a119     MOV        dword ptr [ESP + param_1],EAX
//         0053a11d     CALL       __ftol                                           undefined __ftol()
//         0053a122     MOV        this,dword ptr [ESP + param_1]
//         0053a126     PUSH       this
//         0053a127     PUSH       EAX
//         0053a128     PUSH       this
//         0053a129     PUSH       EAX
//         0053a12a     MOV        this,ESI
//         0053a12c     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              view.cpp:5869 (7)
//         0053a131     JMP        LAB_0053a193
//                               LAB_0053a133                                                 XREF[1]:     0053a0e8(j)
//         0053a133     CMP        BL,0x9
//         0053a136     JNZ        LAB_0053a193
//                              view.cpp:5872 (20)
//         0053a138     LEA        this=>pick_info.y,[ESP + 0x10]
//         0053a13c     PUSH       0x0
//         0053a13e     PUSH       this
//         0053a13f     PUSH       EDI
//         0053a140     PUSH       EBP
//         0053a141     PUSH       0x0
//         0053a143     PUSH       0x28
//         0053a145     MOV        this,ESI
//         0053a147     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:5874 (9)
//         0053a14c     FLD        float ptr [ESP + pick_info.y]
//         0053a150     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:5875 (15)
//         0053a155     FLD        float ptr [ESP + pick_info.scr_x]
//         0053a159     MOV        dword ptr [ESI + 0x2f4],EAX
//         0053a15f     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:5876 (26)
//         0053a164     MOV        EBX,dword ptr [ESI]
//         0053a166     PUSH       0x1
//         0053a168     PUSH       EDI
//         0053a169     PUSH       EBP
//         0053a16a     PUSH       EDI
//         0053a16b     PUSH       EBP
//         0053a16c     MOV        this,ESI
//         0053a16e     MOV        dword ptr [ESI + 0x2f8],EAX
//         0053a174     CALL       dword ptr [EBX + 0xf4]
//         0053a17a     TEST       EAX,EAX
//         0053a17c     JNZ        LAB_0053a188
//                              view.cpp:5914 (10)
//         0053a17e     POP        EDI
//         0053a17f     POP        ESI
//         0053a180     POP        EBP
//         0053a181     POP        EBX
//         0053a182     ADD        ESP,0x14
//         0053a185     RET        0x14
//                               LAB_0053a188                                                 XREF[1]:     0053a17c(j)
//                              view.cpp:5878 (11)
//         0053a188     PUSH       0x1
//         0053a18a     MOV        this,ESI
//         0053a18c     CALL       dword ptr [EBX + 0x20]
//         0053a18f     MOV        BL,byte ptr [ESP + 0x28]
//                               LAB_0053a193                                                 XREF[2]:     0053a131(j), 0053a136(j)
//                              view.cpp:5887 (45)
//         0053a193     MOV        this,ESI
//         0053a195     MOV        dword ptr [ESP + param_1],0x0
//         0053a19d     MOV        byte ptr [ESI + 0x168],BL
//         0053a1a3     MOV        dword ptr [ESI + 0x16c],EBP
//         0053a1a9     MOV        dword ptr [ESI + 0xc4],EBP
//         0053a1af     MOV        dword ptr [ESI + 0x170],EDI
//         0053a1b5     MOV        dword ptr [ESI + 0xc8],EDI
//         0053a1bb     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
//                              view.cpp:5891 (26)
//         0053a1c0     MOV        AL,byte ptr [ESI + 0x168]
//         0053a1c6     CMP        AL,0x1
//         0053a1c8     JZ         LAB_0053a1da
//         0053a1ca     CMP        AL,0x2
//         0053a1cc     JZ         LAB_0053a1da
//         0053a1ce     CMP        AL,0x6
//         0053a1d0     JZ         LAB_0053a1da
//         0053a1d2     CMP        AL,0x7
//         0053a1d4     JZ         LAB_0053a1da
//         0053a1d6     CMP        AL,0x8
//         0053a1d8     JNZ        LAB_0053a1e5
//                               LAB_0053a1da                                                 XREF[4]:     0053a1c8(j), 0053a1cc(j),
//                                                                                                         0053a1d0(j), 0053a1d4(j)
//                              view.cpp:5892 (11)
//         0053a1da     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053a1e0     CALL       RGE_Base_Game::mouse_off                         void mouse_off(RGE_Base_Game * this)
//                               LAB_0053a1e5                                                 XREF[1]:     0053a1d8(j)
//                              view.cpp:5894 (9)
//         0053a1e5     CMP        byte ptr [ESI + 0x168],0x2
//         0053a1ec     JNZ        LAB_0053a212
//                              view.cpp:5896 (16)
//         0053a1ee     MOV        EAX,dword ptr [ESP + param_5]
//         0053a1f2     TEST       EAX,EAX
//         0053a1f4     JNZ        LAB_0053a209
//         0053a1f6     MOV        EAX,dword ptr [ESP + param_4]
//         0053a1fa     TEST       EAX,EAX
//         0053a1fc     JNZ        LAB_0053a209
//                              view.cpp:5897 (11)
//         0053a1fe     MOV        this,dword ptr [ESI + 0x100]
//         0053a204     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
//                               LAB_0053a209                                                 XREF[2]:     0053a1f4(j), 0053a1fc(j)
//                              view.cpp:5898 (9)
//         0053a209     MOV        EDX,dword ptr [ESI]
//         0053a20b     PUSH       0x1
//         0053a20d     MOV        this,ESI
//         0053a20f     CALL       dword ptr [EDX + 0x20]
//                               LAB_0053a212                                                 XREF[1]:     0053a1ec(j)
//                              view.cpp:5901 (14)
//         0053a212     MOV        AL,byte ptr [ESI + 0x168]
//         0053a218     CMP        AL,0x6
//         0053a21a     JZ         LAB_0053a220
//         0053a21c     CMP        AL,0x8
//         0053a21e     JNZ        LAB_0053a277
//                               LAB_0053a220                                                 XREF[1]:     0053a21a(j)
//                              view.cpp:5904 (20)
//         0053a220     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0053a224     PUSH       0x0
//         0053a226     PUSH       EAX=>DAT_fffffff8
//         0053a227     PUSH       EDI=>DAT_fffffff4
//         0053a228     PUSH       EBP=>DAT_fffffff0
//         0053a229     PUSH       0x0
//         0053a22b     PUSH       0x28
//         0053a22d     MOV        this,ESI
//         0053a22f     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:5905 (4)
//         0053a234     CMP        AL,0x33
//         0053a236     JNZ        LAB_0053a277
//                              view.cpp:5907 (39)
//         0053a238     FLD        float ptr [ESP + 0x14]
//         0053a23c     FSUB       float ptr [DAT_005776c0]
//         0053a242     PUSH       this
//         0053a243     FSTP       float ptr [ESP]
//         0053a246     FLD        float ptr [ESP + 0x14]
//         0053a24a     FSUB       float ptr [DAT_005776c0]
//         0053a250     PUSH       this=>DAT_fffffff8
//         0053a251     MOV        this,dword ptr [ESI + 0x100]
//         0053a257     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053a25a     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                              view.cpp:5908 (9)
//         0053a25f     MOV        EDX,dword ptr [ESI]
//         0053a261     PUSH       0x1
//         0053a263     MOV        this,ESI
//         0053a265     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:5909 (5)
//         0053a268     MOV        EAX,0x1
//                              view.cpp:5914 (10)
//         0053a26d     POP        EDI
//         0053a26e     POP        ESI
//         0053a26f     POP        EBP
//         0053a270     POP        EBX
//         0053a271     ADD        ESP,0x14
//         0053a274     RET        0x14
//                               LAB_0053a277                                                 XREF[2]:     0053a21e(j), 0053a236(j)
//                              view.cpp:5909 (4)
//         0053a277     MOV        EAX,dword ptr [ESP + 0x28]
//                              view.cpp:5914 (10)
//         0053a27b     POP        EDI
//         0053a27c     POP        ESI
//         0053a27d     POP        EBP
//         0053a27e     POP        EBX
//         0053a27f     ADD        ESP,0x14
//         0053a282     RET        0x14
//         0053a285     ??         90h
//         0053a286     NOP
//         0053a287     NOP
//         0053a288     NOP
//         0053a289     NOP
//         0053a28a     NOP
//         0053a28b     NOP
//         0053a28c     NOP
//         0053a28d     NOP
//         0053a28e     NOP
//         0053a28f     NOP
    return 0;
}

int RGE_View::handle_scroll_view(long param_1, long param_2) {
    /* TODO: Stub */
//                              int __thiscall handle_scroll_view(RGE_View * this, long param_1, lon
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[19]:    0053a295(R), 0053a333(W), 0053a3e3(W), 0053a3f3(R),
//                                                                                     0053a423(W), 0053a433(R), 0053a50c(W), 0053a51c(R),
//                                                                                     0053a52b(W), 0053a536(R), 0053a563(W), 0053a573(R),
//                                                                                     0053a588(W), 0053a58c(R), 0053a6e1(W), 0053a6f9(R),
//                                                                                     0053a738(W), 0053a756(R), 0053a79b(W)
//              long              Stack[0x8]:4   param_2                   XREF[3]:     0053a29d(R), 0053a2db(W), 0053a631(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[3,1]:   0053a4ae(W), 0053a5ef(W), 0053a7db(W), 0053a835(*)
//              tagPOINT          Stack[-0x20]:8 point                     XREF[4,6]:   0053a2af(W), 0053a694(R), 0053a6a4(R), 0053a797(W),
//                                                                                     0053a4b2(W), 0053a4b9(*), 0053a5f3(W), 0053a5fa(*),
//                                                                                     0053a7e2(W), 0053a7e6(*)
//              long              Stack[-0x24]:4 save_mouse_last_x         XREF[2]:     0053a2e5(W), 0053a642(R)
//              float             Stack[-0x28]:4 save_view_y
//              undefined4        Stack[-0x38]:4 local_38                  XREF[4]:     0053a54e(*), 0053a5a5(*), 0053a71e(*), 0053a779(*)
//              undefined4        Stack[-0x3c]:4 local_3c                  XREF[4]:     0053a552(*), 0053a5a9(*), 0053a724(*), 0053a77f(*)
//                               ?handle_scroll_view@RGE_View@@UAEHJJ@Z                       XREF[2]:     handle_scroll_view:0053f6bf(c),
//                               RGE_View::handle_scroll_view                                              005776a4(*)
//                              view.cpp:5922 (5)
//         0053a290     SUB        ESP,0x24
//         0053a293     PUSH       EBX
//         0053a294     PUSH       EBP
//                              view.cpp:5940 (40)
//         0053a295     MOV        EBX,dword ptr [ESP + param_1]
//         0053a299     PUSH       ESI
//         0053a29a     MOV        ESI,this
//         0053a29c     PUSH       EDI
//         0053a29d     MOV        EDI,dword ptr [ESP + param_2]
//         0053a2a1     MOV        EAX,dword ptr [ESI + 0x16c]
//         0053a2a7     LEA        EBP,[ESI + 0x16c]
//         0053a2ad     CMP        EBX,EAX
//         0053a2af     MOV        dword ptr [ESP + point.x],EAX
//         0053a2b3     JNZ        LAB_0053a2c9
//         0053a2b5     CMP        EDI,dword ptr [ESI + 0x170]
//         0053a2bb     JNZ        LAB_0053a2c9
//                              view.cpp:5941 (2)
//         0053a2bd     XOR        EAX,EAX
//                              view.cpp:6155 (10)
//         0053a2bf     POP        EDI
//         0053a2c0     POP        ESI
//         0053a2c1     POP        EBP
//         0053a2c2     POP        EBX
//         0053a2c3     ADD        ESP,0x24
//         0053a2c6     RET        0x8
//                               LAB_0053a2c9                                                 XREF[2]:     0053a2b3(j), 0053a2bb(j)
//                              view.cpp:5943 (12)
//         0053a2c9     MOV        EDX,dword ptr [ESI + 0x100]
//         0053a2cf     MOV        EAX,dword ptr [EDX + 0x114]
//                              view.cpp:5944 (10)
//         0053a2d5     MOV        this,dword ptr [EDX + 0x118]
//         0053a2db     MOV        dword ptr [ESP + param_2],EAX
//                              view.cpp:5946 (37)
//         0053a2df     MOV        AL,byte ptr [ESI + 0x168]
//         0053a2e5     MOV        dword ptr [ESP + save_mouse_last_x],this
//         0053a2e9     MOV        this,EAX
//         0053a2eb     AND        this,0xff
//         0053a2f1     ADD        this,-0x2
//         0053a2f4     CMP        this,0x6
//         0053a2f7     JA         switchD_0053a2fd::caseD_3
//                               switchD_0053a2fd::switchD
//         0053a2fd     JMP        dword ptr [this->_padding_*0x4 + switchD_0053a   = 0053a304
//                               switchD_0053a2fd::caseD_2                                    XREF[2]:     0053a2fd(j), 0053a99c(*)
//                              view.cpp:5950 (6)
//         0053a304     LEA        EAX,[ESI + 0x170]
//                              view.cpp:5951 (14)
//         0053a30a     MOV        this,ESI
//         0053a30c     PUSH       EAX
//         0053a30d     PUSH       EBP
//         0053a30e     MOV        dword ptr [EBP],EBX
//         0053a311     MOV        dword ptr [EAX],EDI
//         0053a313     CALL       TPanel::bound_point                              int bound_point(TPanel * this, long * param_1
//                              view.cpp:5952 (9)
//         0053a318     MOV        EDX,dword ptr [ESI]
//         0053a31a     PUSH       0x1
//         0053a31c     MOV        this,ESI
//         0053a31e     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:5953 (2)
//         0053a321     XOR        EAX,EAX
//                              view.cpp:6155 (10)
//         0053a323     POP        EDI
//         0053a324     POP        ESI
//         0053a325     POP        EBP
//         0053a326     POP        EBX
//         0053a327     ADD        ESP,0x24
//         0053a32a     RET        0x8
//                               switchD_0053a2fd::caseD_6                                    XREF[2]:     0053a2fd(j), 0053a9ac(*)
//                              view.cpp:5956 (20)
//         0053a32d     MOV        EAX,dword ptr [ESI]
//         0053a32f     PUSH       EDI
//         0053a330     PUSH       EBX
//         0053a331     MOV        this,ESI
//         0053a333     MOV        dword ptr [ESP + param_1],EAX
//         0053a337     CALL       dword ptr [EAX + 0xbc]
//         0053a33d     TEST       EAX,EAX
//         0053a33f     JZ         LAB_0053a382
//                              view.cpp:5959 (20)
//         0053a341     LEA        EAX,[ESP + 0x20]
//         0053a345     PUSH       0x0
//         0053a347     PUSH       EAX=>DAT_fffffff8
//         0053a348     PUSH       EDI=>DAT_fffffff4
//         0053a349     PUSH       EBX=>DAT_fffffff0
//         0053a34a     PUSH       0x0
//         0053a34c     PUSH       0x28
//         0053a34e     MOV        this,ESI
//         0053a350     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:5960 (4)
//         0053a355     CMP        AL,0x33
//         0053a357     JNZ        LAB_0053a382
//                              view.cpp:5961 (41)
//         0053a359     FLD        float ptr [ESP + 0x24]
//         0053a35d     FSUB       float ptr [DAT_005776c0]
//         0053a363     FLD        float ptr [ESP + 0x20]
//         0053a367     FSUB       float ptr [DAT_005776c0]
//         0053a36d     FXCH
//         0053a36f     PUSH       this
//         0053a370     MOV        this,dword ptr [ESI + 0x100]
//         0053a376     FSTP       float ptr [ESP]
//         0053a379     PUSH       this=>DAT_fffffff8
//         0053a37a     FSTP       float ptr [ESP]=>DAT_fffffff8
//         0053a37d     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053a382                                                 XREF[2]:     0053a33f(j), 0053a357(j)
//                              view.cpp:5967 (49)
//         0053a382     MOV        this,dword ptr [ESI + 0x100]
//         0053a388     MOV        dword ptr [EBP],EBX
//         0053a38b     FLD        float ptr [ESP + 0x3c]
//         0053a38f     MOV        dword ptr [ESI + 0x170],EDI
//         0053a395     FCOMP      float ptr [ECX + this->render_rect_hgt]
//         0053a39b     FNSTSW     AX
//         0053a39d     TEST       AH,0x40
//         0053a3a0     JZ         LAB_0053a3bf
//         0053a3a2     FLD        float ptr [ESP + 0x10]
//         0053a3a6     FCOMP      float ptr [ECX + this->max_row_num]
//         0053a3ac     FNSTSW     AX
//         0053a3ae     TEST       AH,0x40
//         0053a3b1     JZ         LAB_0053a3bf
//                              view.cpp:5968 (2)
//         0053a3b3     XOR        EAX,EAX
//                              view.cpp:6155 (10)
//         0053a3b5     POP        EDI
//         0053a3b6     POP        ESI
//         0053a3b7     POP        EBP
//         0053a3b8     POP        EBX
//         0053a3b9     ADD        ESP,0x24
//         0053a3bc     RET        0x8
//                               LAB_0053a3bf                                                 XREF[2]:     0053a3a0(j), 0053a3b1(j)
//                              view.cpp:5971 (11)
//         0053a3bf     MOV        EDX,dword ptr [ESP + 0x38]
//         0053a3c3     PUSH       0x1
//         0053a3c5     MOV        this,ESI
//         0053a3c7     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:6153 (5)
//         0053a3ca     MOV        EAX,0x1
//                              view.cpp:6155 (10)
//         0053a3cf     POP        EDI
//         0053a3d0     POP        ESI
//         0053a3d1     POP        EBP
//         0053a3d2     POP        EBX
//         0053a3d3     ADD        ESP,0x24
//         0053a3d6     RET        0x8
//                               switchD_0053a2fd::caseD_7                                    XREF[2]:     0053a2fd(j), 0053a9b0(*)
//                              view.cpp:5977 (14)
//         0053a3d9     MOV        this,dword ptr [ESI + 0x170]
//         0053a3df     MOV        EAX,EDI
//         0053a3e1     SUB        EAX,this
//         0053a3e3     MOV        dword ptr [ESP + param_1],EAX
//                              view.cpp:5978 (12)
//         0053a3e7     JZ         LAB_0053a41c
//         0053a3e9     CMP        EAX,0x64
//         0053a3ec     JGE        LAB_0053a41c
//         0053a3ee     CMP        EAX,-0x64
//         0053a3f1     JLE        LAB_0053a41c
//                              view.cpp:5980 (28)
//         0053a3f3     FILD       dword ptr [ESP + param_1]
//         0053a3f7     FMUL       float ptr [DAT_005776b4]                         = align(3)
//         0053a3fd     CALL       __ftol                                           undefined __ftol()
//         0053a402     MOV        this,dword ptr [ESI + 0x100]
//         0053a408     ADD        word ptr [ECX + this->center_scr_col_offset],AX
//                              view.cpp:5981 (13)
//         0053a40f     MOV        this,dword ptr [ESI + 0x100]
//         0053a415     SUB        word ptr [ECX + this->center_scr_row],AX
//                               LAB_0053a41c                                                 XREF[3]:     0053a3e7(j), 0053a3ec(j),
//                                                                                                         0053a3f1(j)
//                              view.cpp:5984 (11)
//         0053a41c     MOV        this,dword ptr [EBP]
//         0053a41f     MOV        EAX,EBX
//         0053a421     SUB        EAX,this
//         0053a423     MOV        dword ptr [ESP + param_1],EAX
//                              view.cpp:5985 (12)
//         0053a427     JZ         LAB_0053a45c
//         0053a429     CMP        EAX,0x64
//         0053a42c     JGE        LAB_0053a45c
//         0053a42e     CMP        EAX,-0x64
//         0053a431     JLE        LAB_0053a45c
//                              view.cpp:5987 (28)
//         0053a433     FILD       dword ptr [ESP + param_1]
//         0053a437     FMUL       float ptr [DAT_005776b4]                         = align(3)
//         0053a43d     CALL       __ftol                                           undefined __ftol()
//         0053a442     MOV        this,dword ptr [ESI + 0x100]
//         0053a448     ADD        word ptr [ECX + this->center_scr_col_offset],AX
//                              view.cpp:5988 (13)
//         0053a44f     MOV        this,dword ptr [ESI + 0x100]
//         0053a455     ADD        word ptr [ECX + this->center_scr_row],AX
//                               LAB_0053a45c                                                 XREF[3]:     0053a427(j), 0053a42c(j),
//                                                                                                         0053a431(j)
//                              view.cpp:5992 (40)
//         0053a45c     MOV        this,dword ptr [ESI + 0xc8]
//         0053a462     MOV        EAX,EDI
//         0053a464     SUB        EAX,this
//         0053a466     CDQ
//         0053a467     XOR        EAX,EDX
//         0053a469     SUB        EAX,EDX
//         0053a46b     CMP        EAX,0x8
//         0053a46e     JG         LAB_0053a4a5
//         0053a470     MOV        EDX,dword ptr [ESI + 0xc4]
//         0053a476     MOV        EAX,EBX
//         0053a478     SUB        EAX,EDX
//         0053a47a     CDQ
//         0053a47b     XOR        EAX,EDX
//         0053a47d     SUB        EAX,EDX
//         0053a47f     CMP        EAX,0x8
//         0053a482     JG         LAB_0053a4a5
//                              view.cpp:6044 (18)
//         0053a484     MOV        EDX,dword ptr [ESI]
//         0053a486     PUSH       0x1
//         0053a488     MOV        this,ESI
//         0053a48a     MOV        dword ptr [EBP],EBX
//         0053a48d     MOV        dword ptr [ESI + 0x170],EDI
//         0053a493     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:6153 (5)
//         0053a496     MOV        EAX,0x1
//                              view.cpp:6155 (10)
//         0053a49b     POP        EDI
//         0053a49c     POP        ESI
//         0053a49d     POP        EBP
//         0053a49e     POP        EBX
//         0053a49f     ADD        ESP,0x24
//         0053a4a2     RET        0x8
//                               LAB_0053a4a5                                                 XREF[2]:     0053a46e(j), 0053a482(j)
//                              view.cpp:5994 (6)
//         0053a4a5     MOV        EAX,dword ptr [ESI + 0xc4]
//                              view.cpp:5996 (26)
//         0053a4ab     MOV        EDX,dword ptr [ESI + 0x20]
//         0053a4ae     MOV        dword ptr [ESP + pick_info.x],this
//         0053a4b2     MOV        dword ptr [ESP + point.y],EAX
//         0053a4b6     MOV        EAX,dword ptr [EDX + 0x4]
//         0053a4b9     LEA        this=>point.y,[ESP + 0x18]
//         0053a4bd     PUSH       this
//         0053a4be     PUSH       EAX
//         0053a4bf     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
//                              view.cpp:5997 (16)
//         0053a4c5     MOV        this,dword ptr [ESP + 0x1c]
//         0053a4c9     MOV        EDX,dword ptr [ESP + 0x18]
//         0053a4cd     PUSH       this
//         0053a4ce     PUSH       EDX
//         0053a4cf     CALL       dword ptr [->USER32.DLL::SetCursorPos]           = 0048b01a
//                              view.cpp:5999 (12)
//         0053a4d5     MOV        this,dword ptr [ESI + 0xc8]
//         0053a4db     MOV        EAX,dword ptr [ESI + 0xc4]
//                              view.cpp:6007 (18)
//         0053a4e1     MOV        EDX,dword ptr [ESI]
//         0053a4e3     MOV        dword ptr [ESI + 0x170],this
//         0053a4e9     PUSH       0x1
//         0053a4eb     MOV        this,ESI
//         0053a4ed     MOV        dword ptr [EBP],EAX
//         0053a4f0     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:6153 (5)
//         0053a4f3     MOV        EAX,0x1
//                              view.cpp:6155 (10)
//         0053a4f8     POP        EDI
//         0053a4f9     POP        ESI
//         0053a4fa     POP        EBP
//         0053a4fb     POP        EBX
//         0053a4fc     ADD        ESP,0x24
//         0053a4ff     RET        0x8
//                               switchD_0053a2fd::caseD_8                                    XREF[2]:     0053a2fd(j), 0053a9b4(*)
//                              view.cpp:6012 (14)
//         0053a502     MOV        this,dword ptr [ESI + 0x170]
//         0053a508     MOV        EAX,EDI
//         0053a50a     SUB        EAX,this
//         0053a50c     MOV        dword ptr [ESP + param_1],EAX
//                              view.cpp:6013 (12)
//         0053a510     JZ         LAB_0053a55c
//         0053a512     CMP        EAX,0x64
//         0053a515     JGE        LAB_0053a55c
//         0053a517     CMP        EAX,-0x64
//         0053a51a     JLE        LAB_0053a55c
//                              view.cpp:6015 (64)
//         0053a51c     FILD       dword ptr [ESP + param_1]
//         0053a520     FMUL       float ptr [DAT_005776b4]                         = align(3)
//         0053a526     CALL       __ftol                                           undefined __ftol()
//         0053a52b     MOV        dword ptr [ESP + param_1],EAX
//         0053a52f     PUSH       this
//         0053a530     MOV        this,dword ptr [ESI + 0x100]
//         0053a536     FILD       dword ptr [ESP + param_1]
//         0053a53a     FLD        float ptr [ECX + this->render_rect_hgt]
//         0053a540     FLD        float ptr [ECX + this->max_row_num]
//         0053a546     FADD       ST0,ST2
//         0053a548     FXCH
//         0053a54a     FSUB       ST0,ST2
//         0053a54c     FXCH
//         0053a54e     FSTP       float ptr [ESP]=>local_38
//         0053a551     PUSH       this
//         0053a552     FSTP       float ptr [ESP]=>local_3c
//         0053a555     FSTP       ST0
//         0053a557     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053a55c                                                 XREF[3]:     0053a510(j), 0053a515(j),
//                                                                                                         0053a51a(j)
//                              view.cpp:6018 (11)
//         0053a55c     MOV        this,dword ptr [EBP]
//         0053a55f     MOV        EAX,EBX
//         0053a561     SUB        EAX,this
//         0053a563     MOV        dword ptr [ESP + param_1],EAX
//                              view.cpp:6019 (12)
//         0053a567     JZ         LAB_0053a5b3
//         0053a569     CMP        EAX,0x64
//         0053a56c     JGE        LAB_0053a5b3
//         0053a56e     CMP        EAX,-0x64
//         0053a571     JLE        LAB_0053a5b3
//                              view.cpp:6021 (64)
//         0053a573     FILD       dword ptr [ESP + param_1]
//         0053a577     FMUL       float ptr [DAT_005776b4]                         = align(3)
//         0053a57d     CALL       __ftol                                           undefined __ftol()
//         0053a582     MOV        this,dword ptr [ESI + 0x100]
//         0053a588     MOV        dword ptr [ESP + param_1],EAX
//         0053a58c     FILD       dword ptr [ESP + param_1]
//         0053a590     FLD        float ptr [ECX + this->render_rect_hgt]
//         0053a596     FLD        float ptr [ECX + this->max_row_num]
//         0053a59c     FADD       ST0,ST2
//         0053a59e     FXCH
//         0053a5a0     FADD       ST0,ST2
//         0053a5a2     FXCH
//         0053a5a4     PUSH       this
//         0053a5a5     FSTP       float ptr [ESP]=>local_38
//         0053a5a8     PUSH       this
//         0053a5a9     FSTP       float ptr [ESP]=>local_3c
//         0053a5ac     FSTP       ST0
//         0053a5ae     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053a5b3                                                 XREF[3]:     0053a567(j), 0053a56c(j),
//                                                                                                         0053a571(j)
//                              view.cpp:6025 (40)
//         0053a5b3     MOV        this,dword ptr [ESI + 0xc8]
//         0053a5b9     MOV        EAX,EDI
//         0053a5bb     SUB        EAX,this
//         0053a5bd     CDQ
//         0053a5be     XOR        EAX,EDX
//         0053a5c0     SUB        EAX,EDX
//         0053a5c2     CMP        EAX,0x8
//         0053a5c5     JG         LAB_0053a5e6
//         0053a5c7     MOV        EDX,dword ptr [ESI + 0xc4]
//         0053a5cd     MOV        EAX,EBX
//         0053a5cf     SUB        EAX,EDX
//         0053a5d1     CDQ
//         0053a5d2     XOR        EAX,EDX
//         0053a5d4     SUB        EAX,EDX
//         0053a5d6     CMP        EAX,0x8
//         0053a5d9     JG         LAB_0053a5e6
//                              view.cpp:6036 (3)
//         0053a5db     MOV        dword ptr [EBP],EBX
//                              view.cpp:6037 (8)
//         0053a5de     MOV        dword ptr [ESI + 0x170],EDI
//         0053a5e4     JMP        LAB_0053a62b
//                               LAB_0053a5e6                                                 XREF[2]:     0053a5c5(j), 0053a5d9(j)
//                              view.cpp:6027 (6)
//         0053a5e6     MOV        EAX,dword ptr [ESI + 0xc4]
//                              view.cpp:6029 (26)
//         0053a5ec     MOV        EDX,dword ptr [ESI + 0x20]
//         0053a5ef     MOV        dword ptr [ESP + pick_info.x],this
//         0053a5f3     MOV        dword ptr [ESP + point.y],EAX
//         0053a5f7     MOV        EAX,dword ptr [EDX + 0x4]
//         0053a5fa     LEA        this=>point.y,[ESP + 0x18]
//         0053a5fe     PUSH       this
//         0053a5ff     PUSH       EAX
//         0053a600     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
//                              view.cpp:6030 (16)
//         0053a606     MOV        this,dword ptr [ESP + 0x1c]
//         0053a60a     MOV        EDX,dword ptr [ESP + 0x18]
//         0053a60e     PUSH       this
//         0053a60f     PUSH       EDX
//         0053a610     CALL       dword ptr [->USER32.DLL::SetCursorPos]           = 0048b01a
//                              view.cpp:6031 (6)
//         0053a616     MOV        EAX,dword ptr [ESI + 0xc4]
//                              view.cpp:6032 (15)
//         0053a61c     MOV        this,dword ptr [ESI + 0xc8]
//         0053a622     MOV        dword ptr [EBP],EAX
//         0053a625     MOV        dword ptr [ESI + 0x170],this
//                               LAB_0053a62b                                                 XREF[1]:     0053a5e4(j)
//                              view.cpp:6040 (40)
//         0053a62b     MOV        this,dword ptr [ESI + 0x100]
//         0053a631     FLD        float ptr [ESP + param_2]
//         0053a635     FCOMP      float ptr [ECX + this->render_rect_hgt]
//         0053a63b     FNSTSW     AX
//         0053a63d     TEST       AH,0x40
//         0053a640     JZ         LAB_0053a65f
//         0053a642     FLD        float ptr [ESP + save_mouse_last_x]
//         0053a646     FCOMP      float ptr [ECX + this->max_row_num]
//         0053a64c     FNSTSW     AX
//         0053a64e     TEST       AH,0x40
//         0053a651     JZ         LAB_0053a65f
//                              view.cpp:6041 (2)
//         0053a653     XOR        EAX,EAX
//                              view.cpp:6155 (10)
//         0053a655     POP        EDI
//         0053a656     POP        ESI
//         0053a657     POP        EBP
//         0053a658     POP        EBX
//         0053a659     ADD        ESP,0x24
//         0053a65c     RET        0x8
//                               LAB_0053a65f                                                 XREF[2]:     0053a640(j), 0053a651(j)
//                              view.cpp:6044 (9)
//         0053a65f     MOV        EDX,dword ptr [ESI]
//         0053a661     PUSH       0x1
//         0053a663     MOV        this,ESI
//         0053a665     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:6153 (5)
//         0053a668     MOV        EAX,0x1
//                              view.cpp:6155 (10)
//         0053a66d     POP        EDI
//         0053a66e     POP        ESI
//         0053a66f     POP        EBP
//         0053a670     POP        EBX
//         0053a671     ADD        ESP,0x24
//         0053a674     RET        0x8
//                               switchD_0053a2fd::caseD_4                                    XREF[5]:     0053a2f7(j), 0053a2fd(j),
//                               switchD_0053a2fd::caseD_5                                                 0053a9a0(*), 0053a9a4(*),
//                               switchD_0053a2fd::caseD_3                                                 0053a9a8(*)
//                              view.cpp:6051 (12)
//         0053a677     CMP        AL,0x3
//         0053a679     JZ         LAB_0053a68a
//         0053a67b     CMP        AL,0x4
//         0053a67d     JZ         LAB_0053a68a
//         0053a67f     CMP        AL,0x9
//         0053a681     JZ         LAB_0053a68a
//                              view.cpp:6060 (7)
//         0053a683     MOV        EBP,0x1
//         0053a688     JMP        LAB_0053a6d7
//                               LAB_0053a68a                                                 XREF[3]:     0053a679(j), 0053a67d(j),
//                                                                                                         0053a681(j)
//                              view.cpp:6054 (68)
//         0053a68a     MOV        EAX,dword ptr [ESI + 0x24]
//         0053a68d     ADD        EAX,0x40
//         0053a690     CMP        EBX,EAX
//         0053a692     JGE        LAB_0053a69a
//         0053a694     CMP        EBX,dword ptr [ESP + point.x]
//         0053a698     JL         LAB_0053a6ce
//                               LAB_0053a69a                                                 XREF[1]:     0053a692(j)
//         0053a69a     MOV        this,dword ptr [ESI + 0x2c]
//         0053a69d     SUB        this,0x40
//         0053a6a0     CMP        EBX,this
//         0053a6a2     JLE        LAB_0053a6aa
//         0053a6a4     CMP        EBX,dword ptr [ESP + point.x]
//         0053a6a8     JG         LAB_0053a6ce
//                               LAB_0053a6aa                                                 XREF[1]:     0053a6a2(j)
//         0053a6aa     MOV        EAX,dword ptr [ESI + 0x28]
//         0053a6ad     ADD        EAX,0x20
//         0053a6b0     CMP        EDI,EAX
//         0053a6b2     JGE        LAB_0053a6bc
//         0053a6b4     CMP        EDI,dword ptr [ESI + 0x170]
//         0053a6ba     JL         LAB_0053a6ce
//                               LAB_0053a6bc                                                 XREF[1]:     0053a6b2(j)
//         0053a6bc     MOV        this,dword ptr [ESI + 0x30]
//         0053a6bf     SUB        this,0x20
//         0053a6c2     CMP        EDI,this
//         0053a6c4     JLE        LAB_0053a6d5
//         0053a6c6     CMP        EDI,dword ptr [ESI + 0x170]
//         0053a6cc     JLE        LAB_0053a6d5
//                               LAB_0053a6ce                                                 XREF[3]:     0053a698(j), 0053a6a8(j),
//                                                                                                         0053a6ba(j)
//                              view.cpp:6055 (5)
//         0053a6ce     MOV        EBP,0x1
//                              view.cpp:6056 (2)
//         0053a6d3     JMP        LAB_0053a6d7
//                               LAB_0053a6d5                                                 XREF[2]:     0053a6c4(j), 0053a6cc(j)
//                              view.cpp:6057 (2)
//         0053a6d5     XOR        EBP,EBP
//                               LAB_0053a6d7                                                 XREF[2]:     0053a688(j), 0053a6d3(j)
//                              view.cpp:6063 (14)
//         0053a6d7     MOV        this,dword ptr [ESI + 0x170]
//         0053a6dd     MOV        EAX,EDI
//         0053a6df     SUB        EAX,this
//         0053a6e1     MOV        dword ptr [ESP + param_1],EAX
//                              view.cpp:6064 (16)
//         0053a6e5     JZ         LAB_0053a72e
//         0053a6e7     CMP        EAX,0xc8
//         0053a6ec     JGE        LAB_0053a72e
//         0053a6ee     CMP        EAX,0xffffff38
//         0053a6f3     JLE        LAB_0053a72e
//                              view.cpp:6066 (4)
//         0053a6f5     TEST       EBP,EBP
//         0053a6f7     JZ         LAB_0053a72e
//                              view.cpp:6068 (16)
//         0053a6f9     FILD       dword ptr [ESP + param_1]
//         0053a6fd     FLD        float ptr [EDX + 0x118]
//         0053a703     FLD        float ptr [EDX + 0x114]
//                              view.cpp:6152 (53)
//         0053a709     FXCH       ST2
//         0053a70b     FMUL       float ptr [DAT_005776c4]
//         0053a711     FXCH
//         0053a713     PUSH       this
//         0053a714     MOV        this,EDX
//         0053a716     FADD       ST0,ST1
//         0053a718     FXCH       ST2
//         0053a71a     FSUB       ST0,ST1
//         0053a71c     FXCH       ST2
//         0053a71e     FSTP       float ptr [ESP]=>local_38
//         0053a721     PUSH       this
//         0053a722     FXCH
//         0053a724     FSTP       float ptr [ESP]=>local_3c
//         0053a727     FSTP       ST0
//         0053a729     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053a72e                                                 XREF[4]:     0053a6e5(j), 0053a6ec(j),
//                                                                                                         0053a6f3(j), 0053a6f7(j)
//         0053a72e     MOV        this,dword ptr [ESI + 0x16c]
//         0053a734     MOV        EAX,EBX
//         0053a736     SUB        EAX,this
//         0053a738     MOV        dword ptr [ESP + param_1],EAX
//         0053a73c     JZ         LAB_0053a789
//                              view.cpp:6073 (14)
//         0053a73e     CMP        EAX,0xc8
//         0053a743     JGE        LAB_0053a789
//         0053a745     CMP        EAX,0xffffff38
//         0053a74a     JLE        LAB_0053a789
//                              view.cpp:6075 (4)
//         0053a74c     TEST       EBP,EBP
//         0053a74e     JZ         LAB_0053a789
//                              view.cpp:6077 (16)
//         0053a750     MOV        this,dword ptr [ESI + 0x100]
//         0053a756     FILD       dword ptr [ESP + param_1]
//         0053a75a     FLD        float ptr [ECX + this->max_row_num]
//                              view.cpp:6152 (117)
//         0053a760     FXCH
//         0053a762     FMUL       float ptr [DAT_005776c4]
//         0053a768     FLD        float ptr [ECX + this->render_rect_hgt]
//         0053a76e     FXCH       ST2
//         0053a770     FADD       ST0,ST1
//         0053a772     FXCH       ST2
//         0053a774     FADD       ST0,ST1
//         0053a776     FXCH       ST2
//         0053a778     PUSH       this
//         0053a779     FSTP       float ptr [ESP]=>local_38
//         0053a77c     PUSH       this
//         0053a77d     FXCH
//         0053a77f     FSTP       float ptr [ESP]=>local_3c
//         0053a782     FSTP       ST0
//         0053a784     CALL       RGE_Player::set_view_loc                         void set_view_loc(RGE_Player * this, float pa
//                               LAB_0053a789                                                 XREF[4]:     0053a73c(j), 0053a743(j),
//                                                                                                         0053a74a(j), 0053a74e(j)
//         0053a789     MOV        EDX,dword ptr [ESI + 0x16c]
//         0053a78f     MOV        EAX,dword ptr [ESI + 0x170]
//         0053a795     TEST       EBP,EBP
//         0053a797     MOV        dword ptr [ESP + point.x],EDX
//         0053a79b     MOV        dword ptr [ESP + param_1],EAX
//         0053a79f     MOV        dword ptr [ESI + 0x16c],EBX
//         0053a7a5     MOV        dword ptr [ESI + 0x170],EDI
//         0053a7ab     JZ         LAB_0053a81f
//         0053a7ad     MOV        this,dword ptr [ESI + 0xc8]
//         0053a7b3     MOV        EAX,EDI
//         0053a7b5     SUB        EAX,this
//         0053a7b7     CDQ
//         0053a7b8     XOR        EAX,EDX
//         0053a7ba     SUB        EAX,EDX
//         0053a7bc     CMP        EAX,0x8
//         0053a7bf     JG         LAB_0053a7d5
//         0053a7c1     MOV        EDX,dword ptr [ESI + 0xc4]
//         0053a7c7     MOV        EAX,EBX
//         0053a7c9     SUB        EAX,EDX
//         0053a7cb     CDQ
//         0053a7cc     XOR        EAX,EDX
//         0053a7ce     SUB        EAX,EDX
//         0053a7d0     CMP        EAX,0x8
//         0053a7d3     JLE        LAB_0053a82b
//                               LAB_0053a7d5                                                 XREF[1]:     0053a7bf(j)
//                              view.cpp:6092 (6)
//         0053a7d5     MOV        EDX,dword ptr [ESI + 0xc4]
//                              view.cpp:6093 (4)
//         0053a7db     MOV        dword ptr [ESP + pick_info.x],this
//                              view.cpp:6094 (22)
//         0053a7df     MOV        this,dword ptr [ESI + 0x20]
//         0053a7e2     MOV        dword ptr [ESP + point.y],EDX
//         0053a7e6     LEA        EAX=>point.y,[ESP + 0x18]
//         0053a7ea     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053a7ed     PUSH       EAX
//         0053a7ee     PUSH       EDX
//         0053a7ef     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
//                              view.cpp:6095 (16)
//         0053a7f5     MOV        EAX,dword ptr [ESP + 0x1c]
//         0053a7f9     MOV        this,dword ptr [ESP + 0x18]
//         0053a7fd     PUSH       EAX
//         0053a7fe     PUSH       this
//         0053a7ff     CALL       dword ptr [->USER32.DLL::SetCursorPos]           = 0048b01a
//                              view.cpp:6096 (6)
//         0053a805     MOV        EDX,dword ptr [ESI + 0xc4]
//                              view.cpp:6097 (18)
//         0053a80b     MOV        EAX,dword ptr [ESI + 0xc8]
//         0053a811     MOV        dword ptr [ESI + 0x16c],EDX
//         0053a817     MOV        dword ptr [ESI + 0x170],EAX
//                              view.cpp:6100 (2)
//         0053a81d     JMP        LAB_0053a82b
//                               LAB_0053a81f                                                 XREF[1]:     0053a7ab(j)
//                              view.cpp:6103 (6)
//         0053a81f     MOV        dword ptr [ESI + 0xc4],EBX
//                              view.cpp:6104 (6)
//         0053a825     MOV        dword ptr [ESI + 0xc8],EDI
//                               LAB_0053a82b                                                 XREF[2]:     0053a7d3(j), 0053a81d(j)
//                              view.cpp:6107 (10)
//         0053a82b     MOV        AL,byte ptr [ESI + 0x168]
//         0053a831     CMP        AL,0x3
//         0053a833     JNZ        LAB_0053a88d
//                              view.cpp:6110 (20)
//         0053a835     LEA        this=>pick_info.y,[ESP + 0x20]
//         0053a839     PUSH       0x0
//         0053a83b     PUSH       this=>DAT_fffffff8
//         0053a83c     PUSH       EDI=>DAT_fffffff4
//         0053a83d     PUSH       EBX=>DAT_fffffff0
//         0053a83e     PUSH       0x0
//         0053a840     PUSH       0x28
//         0053a842     MOV        this,ESI
//         0053a844     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:6111 (22)
//         0053a849     CMP        AL,0x33
//         0053a84b     JNZ        LAB_0053a94d
//         0053a851     MOV        EAX,dword ptr [ESI + 0x100]
//         0053a857     TEST       EAX,EAX
//         0053a859     JZ         LAB_0053a94d
//                              view.cpp:6113 (41)
//         0053a85f     FLD        float ptr [ESP + 0x24]
//         0053a863     CALL       __ftol                                           undefined __ftol()
//         0053a868     FLD        float ptr [ESP + 0x20]
//         0053a86c     PUSH       EAX
//         0053a86d     CALL       __ftol                                           undefined __ftol()
//         0053a872     MOV        EDX,dword ptr [ESI + 0x148]
//         0053a878     PUSH       EAX=>DAT_fffffff8
//         0053a879     MOV        EAX,dword ptr [ESI + 0x144]
//         0053a87f     PUSH       EDX=>DAT_fffffff4
//         0053a880     PUSH       EAX=>DAT_fffffff0
//         0053a881     MOV        this,ESI
//         0053a883     CALL       RGE_View::set_selection_area                     void set_selection_area(RGE_View * this, long
//                              view.cpp:6116 (13)
//         0053a888     JMP        LAB_0053a94d
//                               LAB_0053a88d                                                 XREF[1]:     0053a833(j)
//         0053a88d     CMP        AL,0x4
//         0053a88f     JNZ        LAB_0053a92a
//                              view.cpp:6118 (20)
//         0053a895     MOV        this,dword ptr [ESI + 0x100]
//         0053a89b     MOV        EAX,dword ptr [ECX + this->map_scr_x_offset]
//         0053a8a1     TEST       EAX,EAX
//         0053a8a3     JZ         LAB_0053a94d
//                              view.cpp:6120 (20)
//         0053a8a9     LEA        EDX,[ESP + 0x20]
//         0053a8ad     PUSH       0x0
//         0053a8af     PUSH       EDX=>DAT_fffffff8
//         0053a8b0     PUSH       EDI=>DAT_fffffff4
//         0053a8b1     PUSH       EBX=>DAT_fffffff0
//         0053a8b2     PUSH       0x0
//         0053a8b4     PUSH       0x28
//         0053a8b6     MOV        this,ESI
//         0053a8b8     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:6121 (8)
//         0053a8bd     CMP        AL,0x33
//         0053a8bf     JNZ        LAB_0053a94d
//                              view.cpp:6123 (29)
//         0053a8c5     MOV        EAX,dword ptr [ESI + 0x100]
//         0053a8cb     PUSH       0x0
//         0053a8cd     MOV        this,dword ptr [EAX + 0x130]
//         0053a8d3     MOV        EAX,dword ptr [ESP + 0x28]
//         0053a8d7     PUSH       EAX=>DAT_fffffff8
//         0053a8d8     MOV        EAX,dword ptr [ESP + 0x28]
//         0053a8dc     MOV        EDX,dword ptr [this->_padding_]
//         0053a8de     PUSH       EAX=>DAT_fffffff4
//         0053a8df     CALL       dword ptr [EDX + 0x34]
//                              view.cpp:6127 (21)
//         0053a8e2     MOV        this,dword ptr [ESI + 0x100]
//         0053a8e8     FSTP       ST0
//         0053a8ea     MOV        EAX,dword ptr [ECX + this->map_scr_x_offset]
//         0053a8f0     MOV        this,dword ptr [EAX + 0x18]
//         0053a8f3     TEST       this,this
//         0053a8f5     JZ         LAB_0053a8fe
//                              view.cpp:6128 (5)
//         0053a8f7     CALL       RGE_Active_Sprite_List::get_lowest_draw_level    uchar get_lowest_draw_level(RGE_Active_Sprite
//                              view.cpp:6129 (9)
//         0053a8fc     JMP        LAB_0053a910
//                               LAB_0053a8fe                                                 XREF[1]:     0053a8f5(j)
//         0053a8fe     MOV        EAX,dword ptr [EAX + 0x10]
//         0053a901     TEST       EAX,EAX
//         0053a903     JZ         LAB_0053a90e
//                              view.cpp:6130 (7)
//         0053a905     MOV        this,EAX
//         0053a907     CALL       RGE_Sprite::get_lowest_draw_level                uchar get_lowest_draw_level(RGE_Sprite * this)
//                              view.cpp:6131 (2)
//         0053a90c     JMP        LAB_0053a910
//                               LAB_0053a90e                                                 XREF[1]:     0053a903(j)
//                              view.cpp:6132 (2)
//         0053a90e     MOV        AL,0x14
//                               LAB_0053a910                                                 XREF[2]:     0053a8fc(j), 0053a90c(j)
//                              view.cpp:6133 (4)
//         0053a910     TEST       AL,AL
//         0053a912     JNZ        LAB_0053a91f
//                              view.cpp:6134 (9)
//         0053a914     MOV        EDX,dword ptr [ESI]
//         0053a916     PUSH       0x2
//         0053a918     MOV        this,ESI
//         0053a91a     CALL       dword ptr [EDX + 0x20]
//                              view.cpp:6135 (2)
//         0053a91d     JMP        LAB_0053a94d
//                               LAB_0053a91f                                                 XREF[1]:     0053a912(j)
//                              view.cpp:6136 (9)
//         0053a91f     MOV        EAX,dword ptr [ESI]
//         0053a921     PUSH       0x1
//         0053a923     MOV        this,ESI
//         0053a925     CALL       dword ptr [EAX + 0x20]
//                              view.cpp:6140 (6)
//         0053a928     JMP        LAB_0053a94d
//                               LAB_0053a92a                                                 XREF[1]:     0053a88f(j)
//         0053a92a     CMP        AL,0x9
//         0053a92c     JNZ        LAB_0053a94d
//                              view.cpp:6142 (24)
//         0053a92e     MOV        this,dword ptr [ESP + 0x38]
//         0053a932     MOV        EDX,dword ptr [ESP + 0x14]
//         0053a936     MOV        EBP,dword ptr [ESI]
//         0053a938     PUSH       0x2
//         0053a93a     PUSH       EDI=>DAT_fffffff8
//         0053a93b     PUSH       EBX=>DAT_fffffff4
//         0053a93c     PUSH       this=>DAT_fffffff0
//         0053a93d     PUSH       EDX
//         0053a93e     MOV        this,ESI
//         0053a940     CALL       dword ptr [EBP + 0xf4]
//                              view.cpp:6143 (7)
//         0053a946     PUSH       0x1
//         0053a948     MOV        this,ESI
//         0053a94a     CALL       dword ptr [EBP + 0x20]
//                               LAB_0053a94d                                                 XREF[8]:     0053a84b(j), 0053a859(j),
//                                                                                                         0053a888(j), 0053a8a3(j),
//                                                                                                         0053a8bf(j), 0053a91d(j),
//                                                                                                         0053a928(j), 0053a92c(j)
//                              view.cpp:6147 (40)
//         0053a94d     MOV        this,dword ptr [ESI + 0x100]
//         0053a953     FLD        float ptr [ESP + 0x3c]
//         0053a957     FCOMP      float ptr [ECX + this->render_rect_hgt]
//         0053a95d     FNSTSW     AX
//         0053a95f     TEST       AH,0x40
//         0053a962     JZ         LAB_0053a981
//         0053a964     FLD        float ptr [ESP + 0x10]
//         0053a968     FCOMP      float ptr [ECX + this->max_row_num]
//         0053a96e     FNSTSW     AX
//         0053a970     TEST       AH,0x40
//         0053a973     JZ         LAB_0053a981
//                              view.cpp:6148 (2)
//         0053a975     XOR        EAX,EAX
//                              view.cpp:6155 (10)
//         0053a977     POP        EDI
//         0053a978     POP        ESI
//         0053a979     POP        EBP
//         0053a97a     POP        EBX
//         0053a97b     ADD        ESP,0x24
//         0053a97e     RET        0x8
//                               LAB_0053a981                                                 XREF[2]:     0053a962(j), 0053a973(j)
//                              view.cpp:6152 (9)
//         0053a981     MOV        EAX,dword ptr [ESI]
//         0053a983     PUSH       0x1
//         0053a985     MOV        this,ESI
//         0053a987     CALL       dword ptr [EAX + 0x20]
//                              view.cpp:6155 (46)
//         0053a98a     POP        EDI
//         0053a98b     POP        ESI
//         0053a98c     POP        EBP
//         0053a98d     MOV        EAX,0x1
//         0053a992     POP        EBX
//         0053a993     ADD        ESP,0x24
//         0053a996     RET        0x8
    return 0;
}

void RGE_View::end_scroll_view() {
    /* TODO: Stub */
//                              void __thiscall end_scroll_view(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0053aa3e(W)
//              tagPOINT          Stack[-0xc]:8  point                     XREF[0,2]:   0053aa37(W), 0053aa42(*)
//                               ?end_scroll_view@RGE_View@@UAEXXZ                            XREF[3]:     00572b98(*), 005776a8(*),
//                               RGE_View::end_scroll_view                                                 005778e0(*)
//                              view.cpp:6161 (3)
//         0053a9c0     SUB        ESP,0x8
//                              view.cpp:6165 (30)
//         0053a9c3     XOR        EAX,EAX
//         0053a9c5     PUSH       EBX
//         0053a9c6     PUSH       ESI
//         0053a9c7     MOV        ESI,this
//         0053a9c9     PUSH       EDI
//         0053a9ca     MOV        AL,byte ptr [ESI + 0x168]
//         0053a9d0     DEC        EAX
//         0053a9d1     CMP        EAX,0x8
//         0053a9d4     JA         switchD_0053a9da::caseD_3
//                               switchD_0053a9da::switchD
//         0053a9da     JMP        dword ptr [EAX*0x4 + switchD_0053a9da::switchd   = 0053aa2b
//                               switchD_0053a9da::caseD_2                                    XREF[2]:     0053a9da(j), 0053aac4(*)
//                              view.cpp:6169 (16)
//         0053a9e1     MOV        EAX,dword ptr [ESI + 0xc4]
//         0053a9e7     MOV        this,dword ptr [ESI + 0x16c]
//         0053a9ed     CMP        EAX,this
//         0053a9ef     JLE        LAB_0053a9f7
//                              view.cpp:6171 (2)
//         0053a9f1     MOV        EDI,this
//                              view.cpp:6172 (2)
//         0053a9f3     MOV        EBX,EAX
//                              view.cpp:6174 (2)
//         0053a9f5     JMP        LAB_0053a9fb
//                               LAB_0053a9f7                                                 XREF[1]:     0053a9ef(j)
//                              view.cpp:6176 (2)
//         0053a9f7     MOV        EDI,EAX
//                              view.cpp:6177 (2)
//         0053a9f9     MOV        EBX,this
//                               LAB_0053a9fb                                                 XREF[1]:     0053a9f5(j)
//                              view.cpp:6180 (16)
//         0053a9fb     MOV        this,dword ptr [ESI + 0xc8]
//         0053aa01     MOV        EDX,dword ptr [ESI + 0x170]
//         0053aa07     CMP        this,EDX
//         0053aa09     JLE        LAB_0053aa0f
//                              view.cpp:6182 (2)
//         0053aa0b     MOV        EAX,EDX
//                              view.cpp:6185 (2)
//         0053aa0d     JMP        LAB_0053aa13
//                               LAB_0053aa0f                                                 XREF[1]:     0053aa09(j)
//                              view.cpp:6187 (2)
//         0053aa0f     MOV        EAX,this
//                              view.cpp:6188 (2)
//         0053aa11     MOV        this,EDX
//                               LAB_0053aa13                                                 XREF[1]:     0053aa0d(j)
//                              view.cpp:6191 (13)
//         0053aa13     PUSH       this
//         0053aa14     PUSH       EBX
//         0053aa15     PUSH       EAX
//         0053aa16     PUSH       EDI
//         0053aa17     PUSH       0x4
//         0053aa19     MOV        this,ESI
//         0053aa1b     CALL       RGE_View::pick_multi                             uchar pick_multi(RGE_View * this, uchar param
//                              view.cpp:6192 (9)
//         0053aa20     MOV        EAX,dword ptr [ESI]
//         0053aa22     PUSH       0x1
//         0053aa24     MOV        this,ESI
//         0053aa26     CALL       dword ptr [EAX + 0x20]
//                              view.cpp:6194 (2)
//         0053aa29     JMP        switchD_0053a9da::caseD_3
//                               switchD_0053a9da::caseD_6                                    XREF[5]:     0053a9da(j), 0053aac0(*),
//                               switchD_0053a9da::caseD_7                                                 0053aad4(*), 0053aad8(*),
//                               switchD_0053a9da::caseD_8                                                 0053aadc(*)
//                               switchD_0053a9da::caseD_1
//                              view.cpp:6200 (6)
//         0053aa2b     MOV        this,dword ptr [ESI + 0xc4]
//                              view.cpp:6201 (10)
//         0053aa31     MOV        EDX,dword ptr [ESI + 0xc8]
//         0053aa37     MOV        dword ptr [ESP + point.y],this
//                              view.cpp:6202 (22)
//         0053aa3b     MOV        this,dword ptr [ESI + 0x20]
//         0053aa3e     MOV        dword ptr [ESP + local_4],EDX
//         0053aa42     LEA        EAX=>point.y,[ESP + 0xc]
//         0053aa46     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0053aa49     PUSH       EAX
//         0053aa4a     PUSH       EDX
//         0053aa4b     CALL       dword ptr [->USER32.DLL::ClientToScreen]         = 0048afd2
//                              view.cpp:6203 (16)
//         0053aa51     MOV        EAX,dword ptr [ESP + 0x10]
//         0053aa55     MOV        this,dword ptr [ESP + 0xc]
//         0053aa59     PUSH       EAX
//         0053aa5a     PUSH       this
//         0053aa5b     CALL       dword ptr [->USER32.DLL::SetCursorPos]           = 0048b01a
//                              view.cpp:6204 (2)
//         0053aa61     JMP        switchD_0053a9da::caseD_3
//                               switchD_0053a9da::caseD_9                                    XREF[2]:     0053a9da(j), 0053aae0(*)
//                              view.cpp:6207 (28)
//         0053aa63     MOV        EAX,dword ptr [ESI + 0xc8]
//         0053aa69     MOV        this,dword ptr [ESI + 0xc4]
//         0053aa6f     MOV        EDI,dword ptr [ESI]
//         0053aa71     PUSH       0x0
//         0053aa73     PUSH       EAX
//         0053aa74     PUSH       this
//         0053aa75     PUSH       EAX
//         0053aa76     PUSH       this
//         0053aa77     MOV        this,ESI
//         0053aa79     CALL       dword ptr [EDI + 0xf4]
//                              view.cpp:6208 (7)
//         0053aa7f     PUSH       0x1
//         0053aa81     MOV        this,ESI
//         0053aa83     CALL       dword ptr [EDI + 0x20]
//                               switchD_0053a9da::caseD_4                                    XREF[7]:     0053a9d4(j), 0053a9da(j),
//                               switchD_0053a9da::caseD_5                                                 0053aa29(j), 0053aa61(j),
//                               switchD_0053a9da::caseD_3                                                 0053aac8(*), 0053aacc(*),
//                                                                                                         0053aad0(*)
//                              view.cpp:6214 (26)
//         0053aa86     MOV        AL,byte ptr [ESI + 0x168]
//         0053aa8c     CMP        AL,0x1
//         0053aa8e     JZ         LAB_0053aaa0
//         0053aa90     CMP        AL,0x2
//         0053aa92     JZ         LAB_0053aaa0
//         0053aa94     CMP        AL,0x6
//         0053aa96     JZ         LAB_0053aaa0
//         0053aa98     CMP        AL,0x7
//         0053aa9a     JZ         LAB_0053aaa0
//         0053aa9c     CMP        AL,0x8
//         0053aa9e     JNZ        LAB_0053aaab
//                               LAB_0053aaa0                                                 XREF[4]:     0053aa8e(j), 0053aa92(j),
//                                                                                                         0053aa96(j), 0053aa9a(j)
//                              view.cpp:6215 (11)
//         0053aaa0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0053aaa6     CALL       RGE_Base_Game::mouse_on                          void mouse_on(RGE_Base_Game * this)
//                               LAB_0053aaab                                                 XREF[1]:     0053aa9e(j)
//                              view.cpp:6217 (7)
//         0053aaab     MOV        this,ESI
//         0053aaad     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
//                              view.cpp:6219 (7)
//         0053aab2     MOV        byte ptr [ESI + 0x168],0x0
//                              view.cpp:6220 (43)
//         0053aab9     POP        EDI
//         0053aaba     POP        ESI
//         0053aabb     POP        EBX
//         0053aabc     ADD        ESP,0x8
//         0053aabf     RET
//                              Symbol Ref: No symbol: NONAME
//                               switchD_0053a9da::switchdataD_0053aac0                       XREF[1]:     end_scroll_view:0053a9da(*)
//         0053aac0     addr       switchD_0053a9da::caseD_1
//         0053aac4     addr       switchD_0053a9da::caseD_2
//         0053aac8     addr       switchD_0053a9da::caseD_3
//         0053aacc     addr       switchD_0053a9da::caseD_3
//         0053aad0     addr       switchD_0053a9da::caseD_3
//         0053aad4     addr       switchD_0053a9da::caseD_1
//         0053aad8     addr       switchD_0053a9da::caseD_1
//         0053aadc     addr       switchD_0053a9da::caseD_1
//         0053aae0     addr       switchD_0053a9da::caseD_9
//         0053aae4     ??         90h
//         0053aae5     ??         90h
//         0053aae6     ??         90h
//         0053aae7     ??         90h
//         0053aae8     ??         90h
//         0053aae9     ??         90h
//         0053aaea     ??         90h
//         0053aaeb     ??         90h
//         0053aaec     ??         90h
//         0053aaed     ??         90h
//         0053aaee     ??         90h
//         0053aaef     ??         90h
    return;
}

int RGE_View::do_paint(long param_1, long param_2, long param_3, long param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall do_paint(RGE_View * this, long param_1, long param_2,
//              int               EAX:4          <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0053ab3a(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0053ab36(R)
//              long              Stack[0xc]:4   param_3                   XREF[1]:     0053aaf0(R)
//              long              Stack[0x10]:4  param_4                   XREF[1]:     0053aafe(R)
//              int               Stack[0x14]:4  param_5                   XREF[2]:     0053abb1(R), 0053abea(R)
//              RGE_Pick_Info     Stack[-0x18]   pick_info                 XREF[0,4]:   0053aaf7(*), 0053ab1f(R), 0053ab40(*), 0053ab2b(R)
//                               ?do_paint@RGE_View@@UAEHJJJJH@Z                              XREF[3]:     00572b9c(*), 005776ac(*),
//                               RGE_View::do_paint                                                        005778e4(*)
//                              view.cpp:6226 (34)
//         0053aaf0     MOV        EDX,dword ptr [ESP + param_3]
//         0053aaf4     SUB        ESP,0x14
//         0053aaf7     LEA        EAX=>pick_info.y,[ESP]
//         0053aafb     PUSH       ESI
//         0053aafc     MOV        ESI,this
//         0053aafe     MOV        this,dword ptr [ESP + param_4]
//         0053ab02     PUSH       0x0
//         0053ab04     PUSH       EAX
//         0053ab05     PUSH       this
//         0053ab06     PUSH       EDX
//         0053ab07     PUSH       0x0
//         0053ab09     PUSH       0x28
//         0053ab0b     MOV        this,ESI
//         0053ab0d     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:6239 (4)
//         0053ab12     CMP        AL,0x33
//         0053ab14     JZ         LAB_0053ab1f
//                              view.cpp:6240 (2)
//         0053ab16     XOR        EAX,EAX
//                              view.cpp:6301 (7)
//         0053ab18     POP        ESI
//         0053ab19     ADD        ESP,0x14
//         0053ab1c     RET        0x14
//                               LAB_0053ab1f                                                 XREF[1]:     0053ab14(j)
//                              view.cpp:6242 (12)
//         0053ab1f     FLD        float ptr [ESP + pick_info.y]
//         0053ab23     PUSH       EDI
//         0053ab24     PUSH       EBP
//         0053ab25     PUSH       EBX
//         0053ab26     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:6243 (11)
//         0053ab2b     FLD        float ptr [ESP + pick_info.scr_x]
//         0053ab2f     MOV        EDI,EAX
//         0053ab31     CALL       __ftol                                           undefined __ftol()
//                              view.cpp:6246 (30)
//         0053ab36     MOV        this,dword ptr [ESP + param_2]
//         0053ab3a     MOV        EDX,dword ptr [ESP + param_1]
//         0053ab3e     MOV        EBX,EAX
//         0053ab40     LEA        EAX=>pick_info.y,[ESP + 0x10]
//         0053ab44     PUSH       0x0
//         0053ab46     PUSH       EAX
//         0053ab47     PUSH       this
//         0053ab48     PUSH       EDX
//         0053ab49     PUSH       0x0
//         0053ab4b     PUSH       0x28
//         0053ab4d     MOV        this,ESI
//         0053ab4f     CALL       RGE_View::pick                                   uchar pick(RGE_View * this, uchar param_1, uc
//                              view.cpp:6259 (6)
//         0053ab54     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                              view.cpp:6262 (30)
//         0053ab5a     MOV        EAX,dword ptr [ECX + this+0x1b4]
//         0053ab60     MOV        DX,word ptr [this->_padding_ + 0x402]
//         0053ab67     SUB        EAX,0x9
//         0053ab6a     JZ         LAB_0053abea
//         0053ab6c     DEC        EAX
//         0053ab6d     JZ         LAB_0053abb1
//         0053ab6f     SUB        EAX,0x9
//         0053ab72     JNZ        LAB_0053ac21
//                              view.cpp:6287 (6)
//         0053ab78     MOV        EAX,dword ptr [ECX + this+0x1b8]
//                              view.cpp:6288 (15)
//         0053ab7e     MOV        this,dword ptr [ESI + 0x104]
//         0053ab84     CMP        EAX,0x1
//         0053ab87     MOV        EAX,dword ptr [this->_padding_]
//         0053ab89     JNZ        LAB_0053ab8f
//         0053ab8b     PUSH       0x1
//                              view.cpp:6289 (2)
//         0053ab8d     JMP        LAB_0053ab91
//                               LAB_0053ab8f                                                 XREF[1]:     0053ab89(j)
//                              view.cpp:6290 (23)
//         0053ab8f     PUSH       0x0
//                               LAB_0053ab91                                                 XREF[1]:     0053ab8d(j)
//         0053ab91     MOV        EDX,dword ptr [ESI + 0x2f8]
//         0053ab97     PUSH       0x0
//         0053ab99     PUSH       EBX
//         0053ab9a     PUSH       EDI
//         0053ab9b     PUSH       EDX
//         0053ab9c     MOV        EDX,dword ptr [ESI + 0x2f4]
//         0053aba2     PUSH       EDX
//         0053aba3     CALL       dword ptr [EAX + 0x20]
//                              view.cpp:6292 (9)
//         0053aba6     MOV        EAX,dword ptr [ESI]
//         0053aba8     PUSH       0x2
//         0053abaa     MOV        this,ESI
//         0053abac     CALL       dword ptr [EAX + 0x20]
//                              view.cpp:6293 (2)
//         0053abaf     JMP        LAB_0053ac21
//                               LAB_0053abb1                                                 XREF[1]:     0053ab6d(j)
//                              view.cpp:6276 (8)
//         0053abb1     MOV        EAX,dword ptr [ESP + param_5]
//         0053abb5     TEST       EAX,EAX
//         0053abb7     JZ         LAB_0053ac21
//                              view.cpp:6279 (7)
//         0053abb9     MOV        this,word ptr [this->_padding_ + 0x400]
//                              view.cpp:6280 (6)
//         0053abc0     CMP        this,-0x1
//         0053abc4     JZ         LAB_0053ac21
//                              view.cpp:6282 (34)
//         0053abc6     MOV        EAX,dword ptr [ESI + 0x104]
//         0053abcc     PUSH       this
//         0053abcd     MOVSX      this,DX
//         0053abd0     MOV        EDX,dword ptr [ESI + 0x2f8]
//         0053abd6     MOV        EBP,dword ptr [EAX]
//         0053abd8     PUSH       this
//         0053abd9     MOV        this,dword ptr [ESI + 0x2f4]
//         0053abdf     PUSH       EBX
//         0053abe0     PUSH       EDI
//         0053abe1     PUSH       EDX
//         0053abe2     PUSH       this
//         0053abe3     MOV        this,EAX
//         0053abe5     CALL       dword ptr [EBP + 0x18]
//                              view.cpp:6284 (2)
//         0053abe8     JMP        LAB_0053ac21
//                               LAB_0053abea                                                 XREF[1]:     0053ab6a(j)
//                              view.cpp:6265 (8)
//         0053abea     MOV        EAX,dword ptr [ESP + param_5]
//         0053abee     TEST       EAX,EAX
//         0053abf0     JZ         LAB_0053ac21
//                              view.cpp:6268 (7)
//         0053abf2     MOV        this,word ptr [this->_padding_ + 0x3fe]
//                              view.cpp:6269 (6)
//         0053abf9     CMP        this,-0x1
//         0053abfd     JZ         LAB_0053ac21
//                              view.cpp:6271 (34)
//         0053abff     MOV        EAX,dword ptr [ESI + 0x104]
//         0053ac05     PUSH       this
//         0053ac06     MOV        this,dword ptr [ESI + 0x2f8]
//         0053ac0c     MOV        EBP,dword ptr [EAX]
//         0053ac0e     MOVSX      EDX,DX
//         0053ac11     PUSH       EDX
//         0053ac12     MOV        EDX,dword ptr [ESI + 0x2f4]
//         0053ac18     PUSH       EBX
//         0053ac19     PUSH       EDI
//         0053ac1a     PUSH       this
//         0053ac1b     PUSH       EDX
//         0053ac1c     MOV        this,EAX
//         0053ac1e     CALL       dword ptr [EBP + 0x10]
//                               LAB_0053ac21                                                 XREF[7]:     0053ab72(j), 0053abaf(j),
//                                                                                                         0053abb7(j), 0053abc4(j),
//                                                                                                         0053abe8(j), 0053abf0(j),
//                                                                                                         0053abfd(j)
//                              view.cpp:6298 (15)
//         0053ac21     MOV        dword ptr [ESI + 0x2f8],EBX
//         0053ac27     POP        EBX
//         0053ac28     MOV        dword ptr [ESI + 0x2f4],EDI
//         0053ac2e     POP        EBP
//         0053ac2f     POP        EDI
//                              view.cpp:6300 (5)
//         0053ac30     MOV        EAX,0x1
//                              view.cpp:6301 (7)
//         0053ac35     POP        ESI
//         0053ac36     ADD        ESP,0x14
//         0053ac39     RET        0x14
//         0053ac3c     ??         90h
//         0053ac3d     NOP
//         0053ac3e     NOP
//         0053ac3f     NOP
    return 0;
}

void RGE_View::reset_overlay_sprites() {
    /* TODO: Stub */
//                              void __thiscall reset_overlay_sprites(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?reset_overlay_sprites@RGE_View@@QAEXXZ                      XREF[7]:     mouse_left_up_action:0052d889(c),
//                               RGE_View::reset_overlay_sprites                                           mouse_right_up_action:0052dbf9(c),
//                                                                                                         ~RGE_View:00533907(c),
//                                                                                                         command_make_do:0053fac0(c),
//                                                                                                         command_make_do:0053fba0(c),
//                                                                                                         command_make_work:005404bc(c),
//                                                                                                         command_make_work:00540593(c)
//                              view.cpp:6305 (3)
//         0053ac40     PUSH       EDI
//         0053ac41     MOV        EDI,this
//                              view.cpp:6309 (6)
//         0053ac43     MOV        EAX,dword ptr [EDI + 0x350]
//                              view.cpp:6311 (4)
//         0053ac49     TEST       EAX,EAX
//         0053ac4b     JZ         LAB_0053ac60
//                              view.cpp:6305 (1)
//         0053ac4d     PUSH       ESI
//                               LAB_0053ac4e                                                 XREF[1]:     0053ac5d(j)
//                              view.cpp:6313 (2)
//         0053ac4e     MOV        ESI,dword ptr [EAX]
//                              view.cpp:6314 (9)
//         0053ac50     PUSH       EAX
//         0053ac51     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0053ac56     ADD        ESP,0x4
//                              view.cpp:6315 (6)
//         0053ac59     MOV        EAX,ESI
//         0053ac5b     TEST       ESI,ESI
//         0053ac5d     JNZ        LAB_0053ac4e
//                              view.cpp:6305 (1)
//         0053ac5f     POP        ESI
//                               LAB_0053ac60                                                 XREF[1]:     0053ac4b(j)
//                              view.cpp:6317 (10)
//         0053ac60     MOV        dword ptr [EDI + 0x350],0x0
//                              view.cpp:6319 (2)
//         0053ac6a     POP        EDI
//         0053ac6b     RET
//         0053ac6c     ??         90h
//         0053ac6d     NOP
//         0053ac6e     NOP
//         0053ac6f     NOP
    return;
}

void RGE_View::reset_cyclic_overlay_sprites() {
    /* TODO: Stub */
//                              void __thiscall reset_cyclic_overlay_sprites(RGE_View * this)
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//                               ?reset_cyclic_overlay_sprites@RGE_View@@QAEXXZ               XREF[1]:     view_function_terrain:00537736(c)
//                               RGE_View::reset_cyclic_overlay_sprites
//                              view.cpp:6322 (3)
//         0053ac70     PUSH       EDI
//         0053ac71     MOV        EDI,this
//                              view.cpp:6325 (6)
//         0053ac73     MOV        EAX,dword ptr [EDI + 0x350]
//                              view.cpp:6327 (11)
//         0053ac79     TEST       EAX,EAX
//         0053ac7b     JZ         LAB_0053acc6
//         0053ac7d     PUSH       ESI
//         0053ac7e     PUSH       EBX
//         0053ac7f     MOV        EBX,0x1
//                               LAB_0053ac84                                                 XREF[1]:     0053acc2(j)
//                              view.cpp:6329 (5)
//         0053ac84     CMP        dword ptr [EAX + 0x20],EBX
//         0053ac87     JNZ        LAB_0053acbe
//                              view.cpp:6331 (11)
//         0053ac89     MOV        this,dword ptr [EAX + 0x4]
//         0053ac8c     TEST       this,this
//         0053ac8e     JZ         LAB_0053ac94
//         0053ac90     MOV        EDX,dword ptr [EAX]
//         0053ac92     MOV        dword ptr [this->_padding_],EDX
//                               LAB_0053ac94                                                 XREF[1]:     0053ac8e(j)
//                              view.cpp:6332 (12)
//         0053ac94     MOV        this,dword ptr [EAX]
//         0053ac96     TEST       this,this
//         0053ac98     JZ         LAB_0053aca0
//         0053ac9a     MOV        EDX,dword ptr [EAX + 0x4]
//         0053ac9d     MOV        dword ptr [ECX + this->_padding_],EDX
//                               LAB_0053aca0                                                 XREF[1]:     0053ac98(j)
//                              view.cpp:6334 (15)
//         0053aca0     MOV        this,dword ptr [EAX + 0x4]
//         0053aca3     TEST       this,this
//         0053aca5     JNZ        LAB_0053acaf
//         0053aca7     MOV        this,dword ptr [EAX]
//         0053aca9     MOV        dword ptr [EDI + 0x350],this
//                               LAB_0053acaf                                                 XREF[1]:     0053aca5(j)
//                              view.cpp:6336 (2)
//         0053acaf     MOV        ESI,dword ptr [EAX]
//                              view.cpp:6337 (9)
//         0053acb1     PUSH       EAX
//         0053acb2     CALL       operator_delete                                  void operator_delete(void * param_1)
//         0053acb7     ADD        ESP,0x4
//                              view.cpp:6338 (2)
//         0053acba     MOV        EAX,ESI
//                              view.cpp:6340 (2)
//         0053acbc     JMP        LAB_0053acc0
//                               LAB_0053acbe                                                 XREF[1]:     0053ac87(j)
//                              view.cpp:6342 (2)
//         0053acbe     MOV        EAX,dword ptr [EAX]
//                               LAB_0053acc0                                                 XREF[1]:     0053acbc(j)
//                              view.cpp:6327 (6)
//         0053acc0     TEST       EAX,EAX
//         0053acc2     JNZ        LAB_0053ac84
//         0053acc4     POP        EBX
//         0053acc5     POP        ESI
//                               LAB_0053acc6                                                 XREF[1]:     0053ac7b(j)
//                              view.cpp:6346 (2)
//         0053acc6     POP        EDI
//         0053acc7     RET
//         0053acc8     ??         90h
//         0053acc9     NOP
//         0053acca     NOP
//         0053accb     NOP
//         0053accc     NOP
//         0053accd     NOP
//         0053acce     NOP
//         0053accf     NOP
    return;
}

void RGE_View::add_overlay_sprite(TShape* param_1, int param_2, int param_3, int param_4, int param_5, int param_6, uchar* param_7, int param_8, ulong param_9) {
    /* TODO: Stub */
//                              void __thiscall add_overlay_sprite(RGE_View * this, TShape * param_1
//              void              <VOID>         <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              TShape *          Stack[0x4]:4   param_1                   XREF[1]:     0053acf5(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053ad02(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053ad09(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053ad10(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053ad17(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0053ad1e(R)
//              uchar *           Stack[0x1c]:4  param_7                   XREF[1]:     0053ad25(R)
//              int               Stack[0x20]:4  param_8                   XREF[1]:     0053ad2c(R)
//              ulong             Stack[0x24]:4  param_9                   XREF[1]:     0053ad33(R)
//                               ?add_overlay_sprite@RGE_View@@QAEXPAVTShape@@HHHHHPAEHK@Z    XREF[8]:     mouse_left_up_action:0052d6fc(c),
//                               RGE_View::add_overlay_sprite                                              mouse_left_up_action:0052d939(c),
//                                                                                                         mouse_right_up_action:0052da6c(c),
//                                                                                                         mouse_right_up_action:0052dca9(c),
//                                                                                                         mouse_left_up_action:0053f1b1(c),
//                                                                                                         mouse_right_up_action:0053f5d8(c),
//                                                                                                         command_make_do:0053fb76(c),
//                                                                                                         command_make_work:00540568(c)
//                              view.cpp:6349 (3)
//         0053acd0     PUSH       ESI
//         0053acd1     MOV        ESI,this
//                              view.cpp:6352 (7)
//         0053acd3     PUSH       0x30
//         0053acd5     CALL       operator_new                                     void * operator_new(uint param_1)
//                              view.cpp:6354 (9)
//         0053acda     XOR        EDX,EDX
//         0053acdc     ADD        ESP,0x4
//         0053acdf     CMP        EAX,EDX
//         0053ace1     JZ         LAB_0053ad3d
//                              view.cpp:6358 (6)
//         0053ace3     MOV        this,dword ptr [ESI + 0x350]
//                              view.cpp:6359 (3)
//         0053ace9     MOV        dword ptr [EAX + 0x4],EDX
//                              view.cpp:6360 (9)
//         0053acec     CMP        this,EDX
//         0053acee     MOV        dword ptr [EAX],this
//         0053acf0     JZ         LAB_0053acf5
//         0053acf2     MOV        dword ptr [ECX + this->_padding_],EAX
//                               LAB_0053acf5                                                 XREF[1]:     0053acf0(j)
//                              view.cpp:6363 (13)
//         0053acf5     MOV        this,dword ptr [ESP + param_1]
//         0053acf9     MOV        dword ptr [ESI + 0x350],EAX
//         0053acff     MOV        dword ptr [EAX + 0x8],this
//                              view.cpp:6364 (7)
//         0053ad02     MOV        this,dword ptr [ESP + param_2]
//         0053ad06     MOV        dword ptr [EAX + 0xc],this
//                              view.cpp:6365 (7)
//         0053ad09     MOV        this,dword ptr [ESP + param_3]
//         0053ad0d     MOV        dword ptr [EAX + 0x10],this
//                              view.cpp:6366 (7)
//         0053ad10     MOV        this,dword ptr [ESP + param_4]
//         0053ad14     MOV        dword ptr [EAX + 0x14],this
//                              view.cpp:6367 (7)
//         0053ad17     MOV        this,dword ptr [ESP + param_5]
//         0053ad1b     MOV        dword ptr [EAX + 0x18],this
//                              view.cpp:6368 (7)
//         0053ad1e     MOV        this,dword ptr [ESP + param_6]
//         0053ad22     MOV        dword ptr [EAX + 0x1c],this
//                              view.cpp:6369 (7)
//         0053ad25     MOV        this,dword ptr [ESP + param_7]
//         0053ad29     MOV        dword ptr [EAX + 0x2c],this
//                              view.cpp:6370 (7)
//         0053ad2c     MOV        this,dword ptr [ESP + param_8]
//         0053ad30     MOV        dword ptr [EAX + 0x20],this
//                              view.cpp:6371 (7)
//         0053ad33     MOV        this,dword ptr [ESP + param_9]
//         0053ad37     MOV        dword ptr [EAX + 0x28],this
//                              view.cpp:6373 (3)
//         0053ad3a     MOV        dword ptr [EAX + 0x24],EDX
//                               LAB_0053ad3d                                                 XREF[1]:     0053ace1(j)
//                              view.cpp:6376 (4)
//         0053ad3d     POP        ESI
//         0053ad3e     RET        0x24
//         0053ad41     ??         90h
//         0053ad42     NOP
//         0053ad43     NOP
//         0053ad44     NOP
//         0053ad45     NOP
//         0053ad46     NOP
//         0053ad47     NOP
//         0053ad48     NOP
//         0053ad49     NOP
//         0053ad4a     NOP
//         0053ad4b     NOP
//         0053ad4c     NOP
//         0053ad4d     NOP
//         0053ad4e     NOP
//         0053ad4f     NOP
    return;
}

bool RGE_View::Object_Was_Displayed(int param_1, bool param_2) {
    /* TODO: Stub */
//                              bool __thiscall Object_Was_Displayed(RGE_View * this, int param_1, b
//              bool              AL:1           <RETURN>
//              RGE_View *        ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053ad50(R)
//              bool              Stack[0x8]:1   param_2                   XREF[1]:     0053ad6f(R)
//                               ?Object_Was_Displayed@RGE_View@@QAE_NH_N@Z                   XREF[1]:     mouse_left_dbl_click_action:0052df
//                               RGE_View::Object_Was_Displayed
//                              view.cpp:6384 (22)
//         0053ad50     MOV        EAX,dword ptr [ESP + param_1]
//         0053ad54     MOV        this,dword ptr [ECX + this->prior_objs]
//         0053ad5a     PUSH       0x0
//         0053ad5c     PUSH       0x28
//         0053ad5e     PUSH       0x6
//         0053ad60     PUSH       EAX
//         0053ad61     CALL       DClipInfo_List::LocateIDbyDrawLevel              DClipInfo_Node * LocateIDbyDrawLevel(DClipInf
//                              view.cpp:6389 (6)
//         0053ad66     TEST       EAX,EAX
//         0053ad68     JNZ        LAB_0053ad6f
//         0053ad6a     XOR        AL,AL
//                              view.cpp:6397 (3)
//         0053ad6c     RET        0x8
//                               LAB_0053ad6f                                                 XREF[1]:     0053ad68(j)
//                              view.cpp:6391 (8)
//         0053ad6f     MOV        this,byte ptr [ESP + param_2]
//         0053ad73     TEST       this,this
//         0053ad75     JNZ        LAB_0053ad82
//                              view.cpp:6393 (8)
//         0053ad77     TEST       byte ptr [EAX + 0x1c],0x1
//         0053ad7b     JZ         LAB_0053ad82
//         0053ad7d     XOR        AL,AL
//                              view.cpp:6397 (3)
//         0053ad7f     RET        0x8
//                               LAB_0053ad82                                                 XREF[2]:     0053ad75(j), 0053ad7b(j)
//                              view.cpp:6396 (2)
//         0053ad82     MOV        AL,0x1
//                              view.cpp:6397 (3)
//         0053ad84     RET        0x8
//         0053ad87     ??         90h
//         0053ad88     NOP
//         0053ad89     NOP
//         0053ad8a     NOP
//         0053ad8b     NOP
//         0053ad8c     NOP
//         0053ad8d     NOP
//         0053ad8e     NOP
//         0053ad8f     NOP
    return 0;
}

DClipInfo_List::DClipInfo_List(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    /* TODO: Stub */
//                              undefined __thiscall DClipInfo_List(DClipInfo_List * this, int param
//              undefined         <UNASSIGNED>   <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053ae2f(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053ada0(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053ad93(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053adae(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053ada7(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0053adb7(R)
//                               ??0DClipInfo_List@@QAE@HHHHHH@Z                              XREF[2]:     create_surfaces:0053428b(c),
//                               DClipInfo_List::DClipInfo_List                                            create_surfaces:005342d6(c)
//                              view.cpp:6410 (3)
//         0053ad90     PUSH       ESI
//         0053ad91     MOV        ESI,this
//                              view.cpp:6428 (20)
//         0053ad93     MOV        this,dword ptr [ESP + param_3]
//         0053ad97     OR         EAX,0xffffffff
//         0053ad9a     MOV        dword ptr [ESI + 0x14],EAX
//         0053ad9d     MOV        dword ptr [ESI + 0x18],EAX
//         0053ada0     MOV        EAX,dword ptr [ESP + param_2]
//         0053ada4     MOV        dword ptr [ESI + 0x28],this
//                              view.cpp:6433 (16)
//         0053ada7     MOV        this,dword ptr [ESP + param_5]
//         0053adab     MOV        dword ptr [ESI + 0x24],EAX
//         0053adae     MOV        EAX,dword ptr [ESP + param_4]
//         0053adb2     PUSH       EDI
//         0053adb3     MOV        EDX,EAX
//         0053adb5     SUB        this,EAX
//                              view.cpp:6435 (9)
//         0053adb7     MOV        EAX,dword ptr [ESP + param_6]
//         0053adbb     XOR        EDI,EDI
//         0053adbd     NEG        EDX
//         0053adbf     INC        this
//                              view.cpp:6436 (42)
//         0053adc0     PUSH       EAX
//         0053adc1     MOV        dword ptr [ESI + 0x68],this
//         0053adc4     PUSH       EDI
//         0053adc5     MOV        this,ESI
//         0053adc7     MOV        dword ptr [ESI],EDI
//         0053adc9     MOV        dword ptr [ESI + 0x4],EDI
//         0053adcc     MOV        dword ptr [ESI + 0xc],0x8
//         0053add3     MOV        dword ptr [ESI + 0x8],EDI
//         0053add6     MOV        dword ptr [ESI + 0x10],EDI
//         0053add9     MOV        dword ptr [ESI + 0x1c],EDI
//         0053addc     MOV        dword ptr [ESI + 0x20],EDI
//         0053addf     MOV        dword ptr [ESI + 0x64],EDX
//         0053ade2     MOV        dword ptr [ESI + 0x4c],EAX
//         0053ade5     CALL       DClipInfo_List::SetCaptureLevel                  void SetCaptureLevel(DClipInfo_List * this, i
//                              view.cpp:6438 (14)
//         0053adea     MOV        EDX,dword ptr [ESI + 0x68]
//         0053aded     PUSH       0x4
//         0053adef     PUSH       EDX
//         0053adf0     CALL       calloc                                           undefined calloc()
//         0053adf5     MOV        dword ptr [ESI + 0x58],EAX
//                              view.cpp:6440 (15)
//         0053adf8     MOV        EAX,dword ptr [ESI + 0x4c]
//         0053adfb     ADD        ESP,0x8
//         0053adfe     INC        EAX
//         0053adff     PUSH       0x4
//         0053ae01     PUSH       EAX
//         0053ae02     CALL       calloc                                           undefined calloc()
//                              view.cpp:6441 (21)
//         0053ae07     MOV        this,dword ptr [ESI + 0x4c]
//         0053ae0a     ADD        ESP,0x8
//         0053ae0d     INC        this
//         0053ae0e     MOV        dword ptr [ESI + 0x5c],EAX
//         0053ae11     PUSH       0x4
//         0053ae13     PUSH       this
//         0053ae14     CALL       calloc                                           undefined calloc()
//         0053ae19     ADD        ESP,0x8
//                              view.cpp:6443 (10)
//         0053ae1c     MOV        this,ESI
//         0053ae1e     MOV        dword ptr [ESI + 0x60],EAX
//         0053ae21     CALL       DClipInfo_List::ResetStats                       void ResetStats(DClipInfo_List * this)
//                              view.cpp:6447 (9)
//         0053ae26     PUSH       0x8
//         0053ae28     MOV        this,ESI
//         0053ae2a     CALL       DClipInfo_List::SetNumZones                      void SetNumZones(DClipInfo_List * this, int p
//                              view.cpp:6449 (12)
//         0053ae2f     MOV        EDX,dword ptr [ESP + param_1]
//         0053ae33     MOV        this,ESI
//         0053ae35     PUSH       EDX
//         0053ae36     CALL       DClipInfo_List::InitNewZone                      void InitNewZone(DClipInfo_List * this, int p
//                              view.cpp:6451 (3)
//         0053ae3b     MOV        dword ptr [ESI + 0x6c],EDI
//                              view.cpp:6453 (7)
//         0053ae3e     MOV        EAX,ESI
//         0053ae40     POP        EDI
//         0053ae41     POP        ESI
//         0053ae42     RET        0x18
//         0053ae45     ??         90h
//         0053ae46     NOP
//         0053ae47     NOP
//         0053ae48     NOP
//         0053ae49     NOP
//         0053ae4a     NOP
//         0053ae4b     NOP
//         0053ae4c     NOP
//         0053ae4d     NOP
//         0053ae4e     NOP
//         0053ae4f     NOP
}

DClipInfo_List::~DClipInfo_List() {
    /* TODO: Stub */
//                              void __thiscall ~DClipInfo_List(DClipInfo_List * this)
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//                               ??1DClipInfo_List@@QAE@XZ                                    XREF[4]:     ~RGE_View:0053388c(c),
//                               DClipInfo_List::~DClipInfo_List                                           ~RGE_View:005338a6(c),
//                                                                                                         create_surfaces:00534226(c),
//                                                                                                         create_surfaces:00534240(c)
//                              view.cpp:6461 (4)
//         0053ae50     PUSH       ESI
//         0053ae51     MOV        ESI,this
//         0053ae53     PUSH       EDI
//                              view.cpp:6466 (9)
//         0053ae54     XOR        EDI,EDI
//         0053ae56     MOV        EAX,dword ptr [ESI + 0x8]
//         0053ae59     TEST       EAX,EAX
//         0053ae5b     JLE        LAB_0053ae77
//                               LAB_0053ae5d                                                 XREF[1]:     0053ae75(j)
//                              view.cpp:6468 (26)
//         0053ae5d     MOV        EAX,dword ptr [ESI]
//         0053ae5f     MOV        EAX,dword ptr [EAX + EDI*0x4]
//         0053ae62     TEST       EAX,EAX
//         0053ae64     JZ         LAB_0053ae6f
//         0053ae66     PUSH       EAX
//         0053ae67     CALL       free                                             undefined free()
//         0053ae6c     ADD        ESP,0x4
//                               LAB_0053ae6f                                                 XREF[1]:     0053ae64(j)
//         0053ae6f     MOV        EAX,dword ptr [ESI + 0x8]
//         0053ae72     INC        EDI
//         0053ae73     CMP        EDI,EAX
//         0053ae75     JL         LAB_0053ae5d
//                               LAB_0053ae77                                                 XREF[1]:     0053ae5b(j)
//                              view.cpp:6471 (15)
//         0053ae77     MOV        EAX,dword ptr [ESI]
//         0053ae79     TEST       EAX,EAX
//         0053ae7b     JZ         LAB_0053ae86
//         0053ae7d     PUSH       EAX
//         0053ae7e     CALL       free                                             undefined free()
//         0053ae83     ADD        ESP,0x4
//                               LAB_0053ae86                                                 XREF[1]:     0053ae7b(j)
//                              view.cpp:6472 (16)
//         0053ae86     MOV        EAX,dword ptr [ESI + 0x4]
//         0053ae89     TEST       EAX,EAX
//         0053ae8b     JZ         LAB_0053ae96
//         0053ae8d     PUSH       EAX
//         0053ae8e     CALL       free                                             undefined free()
//         0053ae93     ADD        ESP,0x4
//                               LAB_0053ae96                                                 XREF[1]:     0053ae8b(j)
//                              view.cpp:6473 (16)
//         0053ae96     MOV        EAX,dword ptr [ESI + 0x58]
//         0053ae99     TEST       EAX,EAX
//         0053ae9b     JZ         LAB_0053aea6
//         0053ae9d     PUSH       EAX
//         0053ae9e     CALL       free                                             undefined free()
//         0053aea3     ADD        ESP,0x4
//                               LAB_0053aea6                                                 XREF[1]:     0053ae9b(j)
//                              view.cpp:6475 (16)
//         0053aea6     MOV        EAX,dword ptr [ESI + 0x5c]
//         0053aea9     TEST       EAX,EAX
//         0053aeab     JZ         LAB_0053aeb6
//         0053aead     PUSH       EAX
//         0053aeae     CALL       free                                             undefined free()
//         0053aeb3     ADD        ESP,0x4
//                               LAB_0053aeb6                                                 XREF[1]:     0053aeab(j)
//                              view.cpp:6476 (16)
//         0053aeb6     MOV        ESI,dword ptr [ESI + 0x60]
//         0053aeb9     TEST       ESI,ESI
//         0053aebb     JZ         LAB_0053aec6
//         0053aebd     PUSH       ESI
//         0053aebe     CALL       free                                             undefined free()
//         0053aec3     ADD        ESP,0x4
//                               LAB_0053aec6                                                 XREF[1]:     0053aebb(j)
//                              view.cpp:6478 (3)
//         0053aec6     POP        EDI
//         0053aec7     POP        ESI
//         0053aec8     RET
//         0053aec9     ??         90h
//         0053aeca     NOP
//         0053aecb     NOP
//         0053aecc     NOP
//         0053aecd     NOP
//         0053aece     NOP
//         0053aecf     NOP
}

void DClipInfo_List::SetCaptureLevel(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall SetCaptureLevel(DClipInfo_List * this, int param_1,
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053aed0(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053aed4(R)
//                               ?SetCaptureLevel@DClipInfo_List@@QAEXHH@Z                    XREF[3]:     view_function_terrain:00537436(c),
//                               DClipInfo_List::SetCaptureLevel                                           view_function_terrain:0053748d(c),
//                                                                                                         DClipInfo_List:0053ade5(c)
//                              view.cpp:6485 (19)
//         0053aed0     MOV        EDX,dword ptr [ESP + param_1]
//         0053aed4     MOV        EAX,dword ptr [ESP + param_2]
//         0053aed8     CMP        EDX,EAX
//         0053aeda     PUSH       ESI
//         0053aedb     JLE        LAB_0053aee3
//         0053aedd     MOV        ESI,EDX
//         0053aedf     MOV        EDX,EAX
//         0053aee1     MOV        EAX,ESI
//                               LAB_0053aee3                                                 XREF[1]:     0053aedb(j)
//                              view.cpp:6490 (6)
//         0053aee3     TEST       EDX,EDX
//         0053aee5     JGE        LAB_0053aee9
//         0053aee7     XOR        EDX,EDX
//                               LAB_0053aee9                                                 XREF[1]:     0053aee5(j)
//                              view.cpp:6491 (9)
//         0053aee9     MOV        ESI,dword ptr [ECX + this->Max_Draw_Levels]
//         0053aeec     CMP        EAX,ESI
//         0053aeee     JLE        LAB_0053aef2
//         0053aef0     MOV        EAX,ESI
//                               LAB_0053aef2                                                 XREF[1]:     0053aeee(j)
//                              view.cpp:6493 (3)
//         0053aef2     MOV        dword ptr [ECX + this->Accept_Min_Level],EDX
//                              view.cpp:6494 (3)
//         0053aef5     MOV        dword ptr [ECX + this->Accept_Max_Level],EAX
//                              view.cpp:6496 (4)
//         0053aef8     POP        ESI
//         0053aef9     RET        0x8
//         0053aefc     ??         90h
//         0053aefd     NOP
//         0053aefe     NOP
//         0053aeff     NOP
    return;
}

void DClipInfo_List::SetNumZones(int param_1) {
    /* TODO: Stub */
//                              void __thiscall SetNumZones(DClipInfo_List * this, int param_1)
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[3]:     0053af01(R), 0053af1c(W), 0053af5d(R)
//                               ?SetNumZones@DClipInfo_List@@AAEXH@Z                         XREF[2]:     DClipInfo_List:0053ae2a(c),
//                               DClipInfo_List::SetNumZones                                               InitNewZone:0053afa5(c)
//                              view.cpp:6502 (1)
//         0053af00     PUSH       EBX
//                              view.cpp:6508 (14)
//         0053af01     MOV        EBX,dword ptr [ESP + param_1]
//         0053af05     PUSH       ESI
//         0053af06     MOV        ESI,this
//         0053af08     CMP        EBX,dword ptr [ESI + 0xc]
//         0053af0b     JL         LAB_0053af82
//         0053af0d     PUSH       EDI
//         0053af0e     PUSH       EBP
//                              view.cpp:6512 (17)
//         0053af0f     PUSH       0x4
//         0053af11     PUSH       EBX
//         0053af12     CALL       calloc                                           undefined calloc()
//         0053af17     ADD        ESP,0x8
//         0053af1a     MOV        EBP,EAX
//         0053af1c     MOV        dword ptr [ESP + param_1],EBP
//                              view.cpp:6515 (10)
//         0053af20     PUSH       0x4
//         0053af22     PUSH       EBX
//         0053af23     CALL       calloc                                           undefined calloc()
//         0053af28     MOV        EDI,EAX
//                              view.cpp:6520 (9)
//         0053af2a     MOV        EAX,dword ptr [ESI]
//         0053af2c     ADD        ESP,0x8
//         0053af2f     TEST       EAX,EAX
//         0053af31     JZ         LAB_0053af78
//                              view.cpp:6522 (13)
//         0053af33     MOV        this,dword ptr [ESI + 0x8]
//         0053af36     XOR        EAX,EAX
//         0053af38     TEST       this,this
//         0053af3a     JLE        LAB_0053af61
//         0053af3c     MOV        EDX,EBP
//         0053af3e     SUB        EDX,EDI
//                               LAB_0053af40                                                 XREF[1]:     0053af5b(j)
//                              view.cpp:6524 (13)
//         0053af40     MOV        EBP,dword ptr [ESI]
//         0053af42     LEA        this,[EDI + EAX*0x4]
//         0053af45     MOV        EBP,dword ptr [EBP + EAX*0x4]
//         0053af49     INC        EAX
//         0053af4a     MOV        dword ptr [EDX + this->Zone_Ptrs*0x1],EBP
//                              view.cpp:6525 (16)
//         0053af4d     MOV        EBP,dword ptr [ESI + 0x4]
//         0053af50     MOV        EBP,dword ptr [EBP + EAX*0x4 + -0x4]
//         0053af54     MOV        dword ptr [this->Zone_Ptrs],EBP
//         0053af56     MOV        this,dword ptr [ESI + 0x8]
//         0053af59     CMP        EAX,this
//         0053af5b     JL         LAB_0053af40
//                              view.cpp:6522 (4)
//         0053af5d     MOV        EBP,dword ptr [ESP + param_1]
//                               LAB_0053af61                                                 XREF[1]:     0053af3a(j)
//                              view.cpp:6527 (8)
//         0053af61     MOV        EAX,dword ptr [ESI]
//         0053af63     PUSH       EAX
//         0053af64     CALL       free                                             undefined free()
//                              view.cpp:6528 (15)
//         0053af69     MOV        this,dword ptr [ESI + 0x4]
//         0053af6c     ADD        ESP,0x4
//         0053af6f     PUSH       this
//         0053af70     CALL       free                                             undefined free()
//         0053af75     ADD        ESP,0x4
//                               LAB_0053af78                                                 XREF[1]:     0053af31(j)
//                              view.cpp:6533 (2)
//         0053af78     MOV        dword ptr [ESI],EBP
//                              view.cpp:6534 (4)
//         0053af7a     MOV        dword ptr [ESI + 0x4],EDI
//         0053af7d     POP        EBP
//                              view.cpp:6536 (4)
//         0053af7e     MOV        dword ptr [ESI + 0xc],EBX
//         0053af81     POP        EDI
//                               LAB_0053af82                                                 XREF[1]:     0053af0b(j)
//                              view.cpp:6538 (5)
//         0053af82     POP        ESI
//         0053af83     POP        EBX
//         0053af84     RET        0x4
//         0053af87     ??         90h
//         0053af88     NOP
//         0053af89     NOP
//         0053af8a     NOP
//         0053af8b     NOP
//         0053af8c     NOP
//         0053af8d     NOP
//         0053af8e     NOP
//         0053af8f     NOP
    return;
}

void DClipInfo_List::InitNewZone(int param_1) {
    /* TODO: Stub */
//                              void __thiscall InitNewZone(DClipInfo_List * this, int param_1)
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053afad(R)
//                               ?InitNewZone@DClipInfo_List@@AAEXH@Z                         XREF[2]:     DClipInfo_List:0053ae36(c),
//                               DClipInfo_List::InitNewZone                                               GetNode:0053b00f(c)
//                              view.cpp:6545 (5)
//         0053af90     PUSH       EBX
//         0053af91     PUSH       ESI
//         0053af92     MOV        ESI,this
//         0053af94     PUSH       EDI
//                              view.cpp:6551 (21)
//         0053af95     MOV        EAX,dword ptr [ESI + 0x8]
//         0053af98     MOV        this,dword ptr [ESI + 0xc]
//         0053af9b     CMP        EAX,this
//         0053af9d     JNZ        LAB_0053afaa
//         0053af9f     ADD        EAX,0x4
//         0053afa2     MOV        this,ESI
//         0053afa4     PUSH       EAX
//         0053afa5     CALL       DClipInfo_List::SetNumZones                      void SetNumZones(DClipInfo_List * this, int p
//                               LAB_0053afaa                                                 XREF[1]:     0053af9d(j)
//                              view.cpp:6553 (3)
//         0053afaa     MOV        EBX,dword ptr [ESI + 0x8]
//                              view.cpp:6558 (4)
//         0053afad     MOV        EDI,dword ptr [ESP + param_1]
//                              view.cpp:6560 (15)
//         0053afb1     MOV        this,dword ptr [ESI + 0x4]
//         0053afb4     LEA        EAX,[EBX + 0x1]
//         0053afb7     MOV        dword ptr [ESI + 0x8],EAX
//         0053afba     MOV        EAX,dword ptr [ESI + 0x28]
//         0053afbd     IMUL       EAX,EDI
//                              view.cpp:6561 (17)
//         0053afc0     PUSH       EAX
//         0053afc1     MOV        dword ptr [this->Zone_Ptrs + EBX*0x4],EDI
//         0053afc4     CALL       malloc                                           undefined malloc()
//         0053afc9     MOV        EDX,dword ptr [ESI]
//         0053afcb     ADD        ESP,0x4
//         0053afce     MOV        dword ptr [EDX + EBX*0x4],EAX
//                              view.cpp:6565 (3)
//         0053afd1     MOV        EAX,dword ptr [ESI + 0x34]
//                              view.cpp:6566 (3)
//         0053afd4     MOV        EDX,dword ptr [ESI + 0x1c]
//                              view.cpp:6567 (9)
//         0053afd7     MOV        this,dword ptr [ESI + 0x20]
//         0053afda     INC        EAX
//         0053afdb     ADD        EDX,EDI
//         0053afdd     MOV        dword ptr [ESI + 0x34],EAX
//                              view.cpp:6569 (16)
//         0053afe0     MOV        EAX,dword ptr [ESI + 0x14]
//         0053afe3     ADD        this,EDI
//         0053afe5     CMP        EAX,-0x1
//         0053afe8     MOV        dword ptr [ESI + 0x1c],EDX
//         0053afeb     MOV        dword ptr [ESI + 0x20],this
//         0053afee     JNZ        LAB_0053affa
//                              view.cpp:6571 (3)
//         0053aff0     MOV        dword ptr [ESI + 0x14],EBX
//                              view.cpp:6572 (7)
//         0053aff3     MOV        dword ptr [ESI + 0x18],0x0
//                               LAB_0053affa                                                 XREF[1]:     0053afee(j)
//                              view.cpp:6575 (6)
//         0053affa     POP        EDI
//         0053affb     POP        ESI
//         0053affc     POP        EBX
//         0053affd     RET        0x4
    return;
}

DClipInfo_Node* DClipInfo_List::GetNode() {
    /* TODO: Stub */
//                              DClipInfo_Node * __thiscall GetNode(DClipInfo_List * this)
//              DClipInfo_Node    EAX:4          <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//                               ?GetNode@DClipInfo_List@@QAEPAUDClipInfo_Node@@XZ            XREF[2]:     AddDrawNode:0053b134(c),
//                               DClipInfo_List::GetNode                                                   AddGDINode:0053b25c(c)
//                              view.cpp:6582 (4)
//         0053b000     PUSH       ESI
//         0053b001     MOV        ESI,this
//         0053b003     PUSH       EDI
//                              view.cpp:6585 (7)
//         0053b004     MOV        EAX,dword ptr [ESI + 0x20]
//         0053b007     TEST       EAX,EAX
//         0053b009     JNZ        LAB_0053b014
//                              view.cpp:6587 (9)
//         0053b00b     MOV        EAX,dword ptr [ESI + 0x24]
//         0053b00e     PUSH       EAX
//         0053b00f     CALL       DClipInfo_List::InitNewZone                      void InitNewZone(DClipInfo_List * this, int p
//                               LAB_0053b014                                                 XREF[1]:     0053b009(j)
//                              view.cpp:6592 (7)
//         0053b014     MOV        EAX,dword ptr [ESI + 0x10]
//         0053b017     TEST       EAX,EAX
//         0053b019     JZ         LAB_0053b02a
//                              view.cpp:6595 (5)
//         0053b01b     MOV        this,dword ptr [EAX]
//         0053b01d     MOV        dword ptr [ESI + 0x10],this
//                              view.cpp:6596 (7)
//         0053b020     MOV        this,dword ptr [ESI + 0x20]
//         0053b023     DEC        this
//         0053b024     MOV        dword ptr [ESI + 0x20],this
//                              view.cpp:6626 (3)
//         0053b027     POP        EDI
//         0053b028     POP        ESI
//         0053b029     RET
//                               LAB_0053b02a                                                 XREF[1]:     0053b019(j)
//                              view.cpp:6605 (18)
//         0053b02a     MOV        this,dword ptr [ESI + 0x18]
//         0053b02d     MOV        EDX,dword ptr [ESI + 0x14]
//         0053b030     MOV        EAX,dword ptr [ESI]
//         0053b032     MOV        EDI,this
//         0053b034     SHL        EDI,0x6
//         0053b037     MOV        EAX,dword ptr [EAX + EDX*0x4]
//         0053b03a     ADD        EAX,EDI
//                              view.cpp:6607 (4)
//         0053b03c     MOV        EDI,dword ptr [ESI + 0x20]
//         0053b03f     DEC        EDI
//                              view.cpp:6611 (4)
//         0053b040     INC        this
//         0053b041     MOV        dword ptr [ESI + 0x20],EDI
//                              view.cpp:6612 (11)
//         0053b044     MOV        EDI,dword ptr [ESI + 0x4]
//         0053b047     MOV        dword ptr [ESI + 0x18],this
//         0053b04a     CMP        this,dword ptr [EDI + EDX*0x4]
//         0053b04d     JNZ        LAB_0053b06a
//                              view.cpp:6614 (3)
//         0053b04f     LEA        this,[EDX + 0x1]
//                              view.cpp:6616 (17)
//         0053b052     MOV        EDX,dword ptr [ESI + 0x8]
//         0053b055     CMP        this,EDX
//         0053b057     MOV        dword ptr [ESI + 0x14],this
//         0053b05a     MOV        dword ptr [ESI + 0x18],0x0
//         0053b061     JNZ        LAB_0053b06a
//                              view.cpp:6618 (7)
//         0053b063     MOV        dword ptr [ESI + 0x14],0xffffffff
//                               LAB_0053b06a                                                 XREF[2]:     0053b04d(j), 0053b061(j)
//                              view.cpp:6626 (3)
//         0053b06a     POP        EDI
//         0053b06b     POP        ESI
//         0053b06c     RET
//         0053b06d     ??         90h
//         0053b06e     NOP
//         0053b06f     NOP
    return 0;
}

void DClipInfo_List::SetDrawRegion(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              void __thiscall SetDrawRegion(DClipInfo_List * this, int param_1, in
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053b071(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053b07e(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053b076(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053b082(R)
//                               ?SetDrawRegion@DClipInfo_List@@QAEXHHHH@Z                    XREF[2]:     create_surfaces:00534301(c),
//                               DClipInfo_List::SetDrawRegion                                             create_surfaces:0053431a(c)
//                              view.cpp:6634 (1)
//         0053b070     PUSH       ESI
//                              view.cpp:6636 (25)
//         0053b071     MOV        ESI,dword ptr [ESP + param_1]
//         0053b075     PUSH       EDI
//         0053b076     MOV        EDI,dword ptr [ESP + param_3]
//         0053b07a     CMP        ESI,EDI
//         0053b07c     JG         LAB_0053b096
//         0053b07e     MOV        EAX,dword ptr [ESP + param_2]
//         0053b082     MOV        EDX,dword ptr [ESP + param_4]
//         0053b086     CMP        EAX,EDX
//         0053b088     JG         LAB_0053b096
//                              view.cpp:6638 (3)
//         0053b08a     MOV        dword ptr [ECX + this->SD_XMin],ESI
//                              view.cpp:6639 (3)
//         0053b08d     MOV        dword ptr [ECX + this->SD_XMax],EDI
//                              view.cpp:6641 (3)
//         0053b090     MOV        dword ptr [ECX + this->SD_YMin],EAX
//                              view.cpp:6642 (3)
//         0053b093     MOV        dword ptr [ECX + this->SD_YMax],EDX
//                               LAB_0053b096                                                 XREF[2]:     0053b07c(j), 0053b088(j)
//                              view.cpp:6644 (5)
//         0053b096     POP        EDI
//         0053b097     POP        ESI
//         0053b098     RET        0x10
//         0053b09b     ??         90h
//         0053b09c     NOP
//         0053b09d     NOP
//         0053b09e     NOP
//         0053b09f     NOP
    return;
}

void DClipInfo_List::AddDrawNode(void* param_1, Shape_Info* param_2, int param_3, int param_4, int param_5, int param_6, uchar* param_7, int param_8, int param_9, int param_10) {
    /* TODO: Stub */
//                              void __thiscall AddDrawNode(DClipInfo_List * this, void * param_1, S
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              void *            Stack[0x4]:4   param_1                   XREF[1]:     0053b16d(R)
//              Shape_Info *      Stack[0x8]:4   param_2                   XREF[4]:     0053b0cb(R), 0053b0ea(W), 0053b1a1(R), 0053b1fb(R)
//              int               Stack[0xc]:4   param_3                   XREF[4]:     0053b0a0(R), 0053b0b2(W), 0053b11d(R), 0053b13c(R)
//              int               Stack[0x10]:4  param_4                   XREF[4]:     0053b0cf(R), 0053b0f3(W), 0053b1b6(R), 0053b1ee(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053b0d3(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0053b166(R)
//              uchar *           Stack[0x1c]:4  param_7                   XREF[1]:     0053b174(R)
//              int               Stack[0x20]:4  param_8                   XREF[1]:     0053b17b(R)
//              int               Stack[0x24]:4  param_9                   XREF[2]:     0053b0b6(R), 0053b182(R)
//              int               Stack[0x28]:4  param_10                  XREF[1]:     0053b15d(R)
//                               ?AddDrawNode@DClipInfo_List@@QAEXPAXPAUShape_Info@@HHHHPAEH  XREF[4]:     shape_draw:004b94cd(c),
//                               DClipInfo_List::AddDrawNode                                               shape_mirror:004ba5e3(c),
//                                                                                                         capture_frame_3d_square:004c2633(c
//                                                                                                         capture_frame_3d_square:004c2914(c
//                              view.cpp:6652 (13)
//         0053b0a0     MOV        EDX,dword ptr [ESP + param_3]
//         0053b0a4     PUSH       EBX
//         0053b0a5     PUSH       EBP
//         0053b0a6     PUSH       ESI
//         0053b0a7     MOV        ESI,this
//         0053b0a9     PUSH       EDI
//         0053b0aa     MOV        EAX,dword ptr [ESI + 0x64]
//                              view.cpp:6662 (30)
//         0053b0ad     MOV        this,dword ptr [ESI + 0x54]
//         0053b0b0     ADD        EAX,EDX
//         0053b0b2     MOV        dword ptr [ESP + param_3],EAX
//         0053b0b6     MOV        EAX,dword ptr [ESP + param_9]
//         0053b0ba     CMP        EAX,this
//         0053b0bc     JG         LAB_0053b214
//         0053b0c2     CMP        EAX,dword ptr [ESI + 0x50]
//         0053b0c5     JL         LAB_0053b214
//                              view.cpp:6666 (8)
//         0053b0cb     MOV        EBX,dword ptr [ESP + param_2]
//         0053b0cf     MOV        EDI,dword ptr [ESP + param_4]
//                              view.cpp:6667 (14)
//         0053b0d3     MOV        EBP,dword ptr [ESP + param_5]
//         0053b0d7     MOV        EAX,dword ptr [EBX + 0x10]
//         0053b0da     MOV        EDX,dword ptr [EBX + 0x14]
//         0053b0dd     LEA        this,[EDI + EAX*0x1 + -0x1]
//                              view.cpp:6669 (13)
//         0053b0e1     MOV        EAX,dword ptr [EBX + 0x18]
//         0053b0e4     ADD        EAX,EDI
//         0053b0e6     LEA        EDX,[EBP + EDX*0x1 + -0x1]
//         0053b0ea     MOV        dword ptr [ESP + param_2],EAX
//                              view.cpp:6670 (9)
//         0053b0ee     MOV        EAX,dword ptr [EBX + 0x1c]
//         0053b0f1     ADD        EAX,EBP
//         0053b0f3     MOV        dword ptr [ESP + param_4],EAX
//                              view.cpp:6672 (38)
//         0053b0f7     MOV        EAX,dword ptr [ESI + 0x40]
//         0053b0fa     CMP        EDI,EAX
//         0053b0fc     JG         LAB_0053b214
//         0053b102     CMP        this,dword ptr [ESI + 0x3c]
//         0053b105     JL         LAB_0053b214
//         0053b10b     CMP        EBP,dword ptr [ESI + 0x48]
//         0053b10e     JG         LAB_0053b214
//         0053b114     CMP        EDX,dword ptr [ESI + 0x44]
//         0053b117     JL         LAB_0053b214
//                              view.cpp:6676 (21)
//         0053b11d     MOV        EAX,dword ptr [ESP + param_3]
//         0053b121     TEST       EAX,EAX
//         0053b123     JL         LAB_0053b214
//         0053b129     CMP        EAX,dword ptr [ESI + 0x68]
//         0053b12c     JGE        LAB_0053b214
//                              view.cpp:6680 (7)
//         0053b132     MOV        this,ESI
//         0053b134     CALL       DClipInfo_List::GetNode                          DClipInfo_Node * GetNode(DClipInfo_List * this)
//                              view.cpp:6684 (12)
//         0053b139     MOV        this,dword ptr [ESI + 0x58]
//         0053b13c     MOV        EDX,dword ptr [ESP + param_3]
//         0053b140     LEA        this,[this->Zone_Ptrs + EDX*0x4]
//         0053b143     MOV        EDX,dword ptr [this->Zone_Ptrs]
//                              view.cpp:6685 (4)
//         0053b145     TEST       EDX,EDX
//         0053b147     JNZ        LAB_0053b14d
//                              view.cpp:6687 (2)
//         0053b149     MOV        dword ptr [this->Zone_Ptrs],EAX
//                              view.cpp:6689 (2)
//         0053b14b     JMP        LAB_0053b15d
//                               LAB_0053b14d                                                 XREF[1]:     0053b147(j)
//                              view.cpp:6691 (14)
//         0053b14d     MOV        this,dword ptr [EDX]
//         0053b14f     TEST       this,this
//         0053b151     JZ         LAB_0053b15b
//                               LAB_0053b153                                                 XREF[1]:     0053b159(j)
//         0053b153     MOV        EDX,this
//         0053b155     MOV        this,dword ptr [EDX]
//         0053b157     TEST       this,this
//         0053b159     JNZ        LAB_0053b153
//                               LAB_0053b15b                                                 XREF[1]:     0053b151(j)
//                              view.cpp:6692 (2)
//         0053b15b     MOV        dword ptr [EDX],EAX
//                               LAB_0053b15d                                                 XREF[1]:     0053b14b(j)
//                              view.cpp:6702 (9)
//         0053b15d     MOV        EDX,dword ptr [ESP + param_10]
//         0053b161     XOR        this,this
//         0053b163     MOV        dword ptr [EAX + 0x8],EDX
//                              view.cpp:6706 (7)
//         0053b166     MOV        EDX,dword ptr [ESP + param_6]
//         0053b16a     MOV        dword ptr [EAX + 0x1c],EDX
//                              view.cpp:6707 (7)
//         0053b16d     MOV        EDX,dword ptr [ESP + param_1]
//         0053b171     MOV        dword ptr [EAX + 0x20],EDX
//                              view.cpp:6708 (7)
//         0053b174     MOV        EDX,dword ptr [ESP + param_7]
//         0053b178     MOV        dword ptr [EAX + 0x24],EDX
//                              view.cpp:6709 (7)
//         0053b17b     MOV        EDX,dword ptr [ESP + param_8]
//         0053b17f     MOV        dword ptr [EAX + 0x28],EDX
//                              view.cpp:6710 (21)
//         0053b182     MOV        EDX,dword ptr [ESP + param_9]
//         0053b186     MOV        dword ptr [EAX],this
//         0053b188     MOV        dword ptr [EAX + 0x4],this
//         0053b18b     MOV        dword ptr [EAX + 0xc],EBX
//         0053b18e     MOV        dword ptr [EAX + 0x14],EDI
//         0053b191     MOV        dword ptr [EAX + 0x18],EBP
//         0053b194     MOV        dword ptr [EAX + 0x10],EDX
//                              view.cpp:6711 (3)
//         0053b197     MOV        dword ptr [EAX + 0x2c],this
//                              view.cpp:6713 (7)
//         0053b19a     MOV        EDX,dword ptr [ESI + 0x6c]
//         0053b19d     CMP        EDX,this
//         0053b19f     JZ         LAB_0053b1e2
//                              view.cpp:6715 (14)
//         0053b1a1     MOV        EDI,dword ptr [ESP + param_2]
//         0053b1a5     MOV        BX,DI
//         0053b1a8     ADD        BX,word ptr [EDX]
//         0053b1ab     MOV        word ptr [EAX + 0x30],BX
//                              view.cpp:6716 (18)
//         0053b1af     MOV        EDX,dword ptr [ESI + 0x6c]
//         0053b1b2     MOV        BX,word ptr [EDX + 0x2]
//         0053b1b6     MOV        EDX,dword ptr [ESP + param_4]
//         0053b1ba     ADD        BX,DX
//         0053b1bd     MOV        word ptr [EAX + 0x32],BX
//                              view.cpp:6717 (14)
//         0053b1c1     MOV        EBX,dword ptr [ESI + 0x6c]
//         0053b1c4     MOV        BX,word ptr [EBX + 0x4]
//         0053b1c8     ADD        BX,DI
//         0053b1cb     MOV        word ptr [EAX + 0x34],BX
//                              view.cpp:6718 (14)
//         0053b1cf     MOV        EBX,dword ptr [ESI + 0x6c]
//         0053b1d2     MOV        BX,word ptr [EBX + 0x6]
//         0053b1d6     ADD        BX,DX
//         0053b1d9     MOV        word ptr [EAX + 0x36],BX
//                              view.cpp:6720 (3)
//         0053b1dd     MOV        dword ptr [ESI + 0x6c],this
//                              view.cpp:6722 (2)
//         0053b1e0     JMP        LAB_0053b204
//                               LAB_0053b1e2                                                 XREF[1]:     0053b19f(j)
//                              view.cpp:6724 (4)
//         0053b1e2     MOV        word ptr [EAX + 0x30],DI
//                              view.cpp:6725 (4)
//         0053b1e6     MOV        word ptr [EAX + 0x32],BP
//                              view.cpp:6726 (4)
//         0053b1ea     ADD        DI,word ptr [EBX + 0x10]
//                              view.cpp:6727 (22)
//         0053b1ee     MOV        EDX,dword ptr [ESP + param_4]
//         0053b1f2     DEC        EDI
//         0053b1f3     MOV        word ptr [EAX + 0x34],DI
//         0053b1f7     ADD        BP,word ptr [EBX + 0x14]
//         0053b1fb     MOV        EDI,dword ptr [ESP + param_2]
//         0053b1ff     DEC        EBP
//         0053b200     MOV        word ptr [EAX + 0x36],BP
//                               LAB_0053b204                                                 XREF[1]:     0053b1e0(j)
//                              view.cpp:6730 (4)
//         0053b204     MOV        word ptr [EAX + 0x38],DI
//                              view.cpp:6731 (4)
//         0053b208     MOV        word ptr [EAX + 0x3a],DX
//                              view.cpp:6732 (4)
//         0053b20c     MOV        word ptr [EAX + 0x3c],this
//                              view.cpp:6733 (4)
//         0053b210     MOV        word ptr [EAX + 0x3e],this
//                               LAB_0053b214                                                 XREF[8]:     0053b0bc(j), 0053b0c5(j),
//                                                                                                         0053b0fc(j), 0053b105(j),
//                                                                                                         0053b10e(j), 0053b117(j),
//                                                                                                         0053b123(j), 0053b12c(j)
//                              view.cpp:6736 (7)
//         0053b214     POP        EDI
//         0053b215     POP        ESI
//         0053b216     POP        EBP
//         0053b217     POP        EBX
//         0053b218     RET        0x28
//         0053b21b     ??         90h
//         0053b21c     NOP
//         0053b21d     NOP
//         0053b21e     NOP
//         0053b21f     NOP
    return;
}

DClipInfo_Node* DClipInfo_List::AddGDINode(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10, int param_11, int param_12, int param_13) {
    /* TODO: Stub */
//                              DClipInfo_Node * __thiscall AddGDINode(DClipInfo_List * this, int pa
//              DClipInfo_Node    EAX:4          <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053b281(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053b22a(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053b288(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053b290(R)
//              int               Stack[0x14]:4  param_5                   XREF[1]:     0053b299(R)
//              int               Stack[0x18]:4  param_6                   XREF[1]:     0053b2a2(R)
//              int               Stack[0x1c]:4  param_7                   XREF[1]:     0053b2ab(R)
//              int               Stack[0x20]:4  param_8                   XREF[1]:     0053b2b4(R)
//              int               Stack[0x24]:4  param_9                   XREF[1]:     0053b2bd(R)
//              int               Stack[0x28]:4  param_10                  XREF[1]:     0053b2c6(R)
//              int               Stack[0x2c]:4  param_11                  XREF[1]:     0053b222(R)
//              int               Stack[0x30]:4  param_12                  XREF[1]:     0053b27a(R)
//              int               Stack[0x34]:4  param_13                  XREF[1]:     0053b276(R)
//                               ?AddGDINode@DClipInfo_List@@QAEPAUDClipInfo_Node@@HHHHHHHHH  XREF[10]:    draw:0045493d(c),
//                               DClipInfo_List::AddGDINode                                                capture_square_frame:004c2377(c),
//                                                                                                         capture_square_frame:004c23df(c),
//                                                                                                         capture_frame_3d_square:004c25c4(c
//                                                                                                         capture_frame_3d_square:004c2784(c
//                                                                                                         capture_frame_3d_square:004c28bb(c
//                                                                                                         capture_frame_3d_square:004c294d(c
//                                                                                                         draw:0050e935(c),
//                                                                                                         view_function_terrain:005375ba(c),
//                                                                                                         view_function_terrain:00537bc2(c)
//                              view.cpp:6746 (2)
//         0053b220     PUSH       EBX
//         0053b221     PUSH       EBP
//                              view.cpp:6753 (37)
//         0053b222     MOV        EBP,dword ptr [ESP + param_11]
//         0053b226     PUSH       ESI
//         0053b227     MOV        ESI,this
//         0053b229     PUSH       EDI
//         0053b22a     MOV        this,dword ptr [ESP + param_2]
//         0053b22e     MOV        EBX,dword ptr [ESI + 0x64]
//         0053b231     MOV        EAX,dword ptr [ESI + 0x54]
//         0053b234     ADD        EBX,this
//         0053b236     CMP        EBP,EAX
//         0053b238     JG         LAB_0053b2f2
//         0053b23e     CMP        EBP,dword ptr [ESI + 0x50]
//         0053b241     JL         LAB_0053b2f2
//                              view.cpp:6757 (19)
//         0053b247     XOR        EDI,EDI
//         0053b249     CMP        EBX,EDI
//         0053b24b     JL         LAB_0053b2f2
//         0053b251     CMP        EBX,dword ptr [ESI + 0x68]
//         0053b254     JGE        LAB_0053b2f2
//                              view.cpp:6761 (7)
//         0053b25a     MOV        this,ESI
//         0053b25c     CALL       DClipInfo_List::GetNode                          DClipInfo_Node * GetNode(DClipInfo_List * this)
//                              view.cpp:6765 (15)
//         0053b261     MOV        EDX,dword ptr [ESI + 0x58]
//         0053b264     LEA        this,[EBX*0x4 + 0x0]
//         0053b26b     MOV        EDX,dword ptr [EDX + this->Zone_Ptrs*0x1]
//         0053b26e     MOV        dword ptr [EAX],EDX
//                              view.cpp:6767 (6)
//         0053b270     MOV        EDX,dword ptr [ESI + 0x58]
//         0053b273     MOV        dword ptr [EDX + this->Zone_Ptrs*0x1],EAX
//                              view.cpp:6772 (4)
//         0053b276     MOV        this,dword ptr [ESP + param_13]
//                              view.cpp:6776 (7)
//         0053b27a     MOV        EDX,dword ptr [ESP + param_12]
//         0053b27e     MOV        dword ptr [EAX + 0x8],this
//                              view.cpp:6781 (7)
//         0053b281     MOV        this,dword ptr [ESP + param_1]
//         0053b285     MOV        dword ptr [EAX + 0x1c],EDX
//                              view.cpp:6783 (8)
//         0053b288     MOV        DX,word ptr [ESP + param_3]
//         0053b28d     MOV        dword ptr [EAX + 0x2c],this
//                              view.cpp:6784 (9)
//         0053b290     MOV        this,word ptr [ESP + param_4]
//         0053b295     MOV        word ptr [EAX + 0x30],DX
//                              view.cpp:6785 (9)
//         0053b299     MOV        DX,word ptr [ESP + param_5]
//         0053b29e     MOV        word ptr [EAX + 0x32],this
//                              view.cpp:6786 (9)
//         0053b2a2     MOV        this,word ptr [ESP + param_6]
//         0053b2a7     MOV        word ptr [EAX + 0x34],DX
//                              view.cpp:6787 (9)
//         0053b2ab     MOV        DX,word ptr [ESP + param_7]
//         0053b2b0     MOV        word ptr [EAX + 0x36],this
//                              view.cpp:6788 (9)
//         0053b2b4     MOV        this,word ptr [ESP + param_8]
//         0053b2b9     MOV        word ptr [EAX + 0x38],DX
//                              view.cpp:6789 (9)
//         0053b2bd     MOV        DX,word ptr [ESP + param_9]
//         0053b2c2     MOV        word ptr [EAX + 0x3a],this
//                              view.cpp:6790 (37)
//         0053b2c6     MOV        this,word ptr [ESP + param_10]
//         0053b2cb     MOV        dword ptr [EAX + 0x4],EDI
//         0053b2ce     MOV        dword ptr [EAX + 0xc],EDI
//         0053b2d1     MOV        dword ptr [EAX + 0x14],EDI
//         0053b2d4     MOV        dword ptr [EAX + 0x18],EDI
//         0053b2d7     MOV        dword ptr [EAX + 0x20],EDI
//         0053b2da     MOV        dword ptr [EAX + 0x24],EDI
//         0053b2dd     MOV        dword ptr [EAX + 0x28],EDI
//         0053b2e0     MOV        dword ptr [EAX + 0x10],EBP
//         0053b2e3     MOV        word ptr [EAX + 0x3c],DX
//         0053b2e7     MOV        word ptr [EAX + 0x3e],this
//                              view.cpp:6793 (16)
//         0053b2eb     POP        EDI
//         0053b2ec     POP        ESI
//         0053b2ed     POP        EBP
//         0053b2ee     POP        EBX
//         0053b2ef     RET        0x34
//                               LAB_0053b2f2                                                 XREF[4]:     0053b238(j), 0053b241(j),
//                                                                                                         0053b24b(j), 0053b254(j)
//         0053b2f2     POP        EDI
//         0053b2f3     POP        ESI
//         0053b2f4     POP        EBP
//         0053b2f5     XOR        EAX,EAX
//         0053b2f7     POP        EBX
//         0053b2f8     RET        0x34
//         0053b2fb     ??         90h
//         0053b2fc     NOP
//         0053b2fd     NOP
//         0053b2fe     NOP
//         0053b2ff     NOP
    return 0;
}

DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int param_1, int param_2, int param_3, int param_4) {
    /* TODO: Stub */
//                              DClipInfo_Node * __thiscall LocateIDbyDrawLevel(DClipInfo_List * thi
//              DClipInfo_Node    EAX:4          <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053b339(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053b300(R)
//              int               Stack[0xc]:4   param_3                   XREF[1]:     0053b306(R)
//              int               Stack[0x10]:4  param_4                   XREF[1]:     0053b335(R)
//                               ?LocateIDbyDrawLevel@DClipInfo_List@@QAEPAUDClipInfo_Node@@  XREF[1]:     Object_Was_Displayed:0053ad61(c)
//                               DClipInfo_List::LocateIDbyDrawLevel
//                              view.cpp:6800 (21)
//         0053b300     MOV        EAX,dword ptr [ESP + param_2]
//         0053b304     PUSH       EBX
//         0053b305     PUSH       ESI
//         0053b306     MOV        ESI,dword ptr [ESP + param_3]
//         0053b30a     PUSH       EDI
//         0053b30b     CMP        EAX,ESI
//         0053b30d     JLE        LAB_0053b315
//         0053b30f     MOV        EDX,EAX
//         0053b311     MOV        EAX,ESI
//         0053b313     MOV        ESI,EDX
//                               LAB_0053b315                                                 XREF[1]:     0053b30d(j)
//                              view.cpp:6805 (6)
//         0053b315     TEST       EAX,EAX
//         0053b317     JGE        LAB_0053b31b
//         0053b319     XOR        EAX,EAX
//                               LAB_0053b31b                                                 XREF[1]:     0053b317(j)
//                              view.cpp:6806 (9)
//         0053b31b     MOV        EDX,dword ptr [ECX + this->Max_Draw_Levels]
//         0053b31e     CMP        ESI,EDX
//         0053b320     JLE        LAB_0053b324
//         0053b322     MOV        ESI,EDX
//                               LAB_0053b324                                                 XREF[1]:     0053b320(j)
//                              view.cpp:6808 (8)
//         0053b324     CMP        EAX,EDX
//         0053b326     JG         LAB_0053b35f
//         0053b328     TEST       ESI,ESI
//         0053b32a     JL         LAB_0053b35f
//                              view.cpp:6810 (6)
//         0053b32c     CMP        EAX,ESI
//         0053b32e     MOV        EDX,EAX
//         0053b330     JG         LAB_0053b35f
//                              view.cpp:6822 (20)
//         0053b332     MOV        this,dword ptr [ECX + this->Draw_Level_Head]
//         0053b335     MOV        EDI,dword ptr [ESP + param_4]
//         0053b339     MOV        EBX,dword ptr [ESP + param_1]
//         0053b33d     LEA        this,[this->Zone_Ptrs + EAX*0x4]
//                               LAB_0053b340                                                 XREF[1]:     0053b35d(j)
//         0053b340     MOV        EAX,dword ptr [this->Zone_Ptrs]
//         0053b342     TEST       EAX,EAX
//         0053b344     JZ         LAB_0053b357
//                               LAB_0053b346                                                 XREF[1]:     0053b355(j)
//                              view.cpp:6815 (10)
//         0053b346     CMP        dword ptr [EAX + 0x8],EBX
//         0053b349     JNZ        LAB_0053b350
//         0053b34b     CMP        dword ptr [EAX + 0x2c],EDI
//         0053b34e     JZ         LAB_0053b361
//                               LAB_0053b350                                                 XREF[1]:     0053b349(j)
//                              view.cpp:6816 (7)
//         0053b350     MOV        EAX,dword ptr [EAX + 0x4]
//         0053b353     TEST       EAX,EAX
//         0053b355     JNZ        LAB_0053b346
//                               LAB_0053b357                                                 XREF[1]:     0053b344(j)
//                              view.cpp:6810 (8)
//         0053b357     INC        EDX
//         0053b358     ADD        this,0x4
//         0053b35b     CMP        EDX,ESI
//         0053b35d     JLE        LAB_0053b340
//                               LAB_0053b35f                                                 XREF[3]:     0053b326(j), 0053b32a(j),
//                                                                                                         0053b330(j)
//                              view.cpp:6808 (2)
//         0053b35f     XOR        EAX,EAX
//                               LAB_0053b361                                                 XREF[1]:     0053b34e(j)
//                              view.cpp:6822 (6)
//         0053b361     POP        EDI
//         0053b362     POP        ESI
//         0053b363     POP        EBX
//         0053b364     RET        0x10
//         0053b367     ??         90h
//         0053b368     NOP
//         0053b369     NOP
//         0053b36a     NOP
//         0053b36b     NOP
//         0053b36c     NOP
//         0053b36d     NOP
//         0053b36e     NOP
//         0053b36f     NOP
    return 0;
}

void DClipInfo_List::Scroll(int param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall Scroll(DClipInfo_List * this, int param_1, int param
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     0053b411(R)
//              int               Stack[0x8]:4   param_2                   XREF[1]:     0053b370(R)
//                               ?Scroll@DClipInfo_List@@QAEXHH@Z                             XREF[1]:     draw:00534df3(c)
//                               DClipInfo_List::Scroll
//                              view.cpp:6829 (12)
//         0053b370     MOV        EDX,dword ptr [ESP + param_2]
//         0053b374     PUSH       EBX
//         0053b375     PUSH       EBP
//         0053b376     PUSH       ESI
//         0053b377     TEST       EDX,EDX
//         0053b379     PUSH       EDI
//         0053b37a     JLE        LAB_0053b3c5
//                              view.cpp:6837 (11)
//         0053b37c     MOV        ESI,dword ptr [ECX + this->YLine_Size]
//         0053b37f     XOR        EAX,EAX
//         0053b381     SUB        ESI,EDX
//         0053b383     TEST       ESI,ESI
//         0053b385     JLE        LAB_0053b3a5
//                              view.cpp:6898 (7)
//         0053b387     LEA        EDI,[EDX*0x4 + 0x0]
//                               LAB_0053b38e                                                 XREF[1]:     0053b3a3(j)
//                              view.cpp:6838 (23)
//         0053b38e     MOV        ESI,dword ptr [ECX + this->Draw_Clip_Nodes]
//         0053b391     INC        EAX
//         0053b392     MOV        EBX,dword ptr [EDI + ESI*0x1]
//         0053b395     ADD        EDI,0x4
//         0053b398     MOV        dword ptr [ESI + EAX*0x4 + -0x4],EBX
//         0053b39c     MOV        ESI,dword ptr [ECX + this->YLine_Size]
//         0053b39f     SUB        ESI,EDX
//         0053b3a1     CMP        EAX,ESI
//         0053b3a3     JL         LAB_0053b38e
//                               LAB_0053b3a5                                                 XREF[1]:     0053b385(j)
//                              view.cpp:6840 (11)
//         0053b3a5     MOV        ESI,dword ptr [ECX + this->YLine_Size]
//         0053b3a8     MOV        EAX,ESI
//         0053b3aa     SUB        EAX,EDX
//         0053b3ac     CMP        EAX,ESI
//         0053b3ae     JGE        LAB_0053b3c3
//                               LAB_0053b3b0                                                 XREF[1]:     0053b3c1(j)
//                              view.cpp:6841 (19)
//         0053b3b0     MOV        ESI,dword ptr [ECX + this->Draw_Clip_Nodes]
//         0053b3b3     INC        EAX
//         0053b3b4     MOV        dword ptr [ESI + EAX*0x4 + -0x4],0x0
//         0053b3bc     MOV        ESI,dword ptr [ECX + this->YLine_Size]
//         0053b3bf     CMP        EAX,ESI
//         0053b3c1     JL         LAB_0053b3b0
//                               LAB_0053b3c3                                                 XREF[1]:     0053b3ae(j)
//                              view.cpp:6843 (4)
//         0053b3c3     TEST       EDX,EDX
//                               LAB_0053b3c5                                                 XREF[1]:     0053b37a(j)
//         0053b3c5     JGE        LAB_0053b408
//                              view.cpp:6845 (18)
//         0053b3c7     MOV        ESI,dword ptr [ECX + this->YLine_Size]
//         0053b3ca     MOV        EDI,EDX
//         0053b3cc     NEG        EDI
//         0053b3ce     LEA        EAX,[ESI + -0x1]
//         0053b3d1     LEA        ESI,[EDX + ESI*0x1 + -0x1]
//         0053b3d5     CMP        EAX,EDI
//         0053b3d7     JL         LAB_0053b3f2
//                              view.cpp:6898 (7)
//         0053b3d9     LEA        EBX,[ESI*0x4 + 0x0]
//                               LAB_0053b3e0                                                 XREF[1]:     0053b3f0(j)
//                              view.cpp:6846 (18)
//         0053b3e0     MOV        ESI,dword ptr [ECX + this->Draw_Clip_Nodes]
//         0053b3e3     DEC        EAX
//         0053b3e4     MOV        EBP,dword ptr [EBX + ESI*0x1]
//         0053b3e7     SUB        EBX,0x4
//         0053b3ea     MOV        dword ptr [ESI + EAX*0x4 + 0x4],EBP
//         0053b3ee     CMP        EAX,EDI
//         0053b3f0     JGE        LAB_0053b3e0
//                               LAB_0053b3f2                                                 XREF[1]:     0053b3d7(j)
//                              view.cpp:6848 (6)
//         0053b3f2     XOR        EAX,EAX
//         0053b3f4     TEST       EDI,EDI
//         0053b3f6     JLE        LAB_0053b408
//                               LAB_0053b3f8                                                 XREF[1]:     0053b406(j)
//                              view.cpp:6849 (16)
//         0053b3f8     MOV        ESI,dword ptr [ECX + this->Draw_Clip_Nodes]
//         0053b3fb     INC        EAX
//         0053b3fc     CMP        EAX,EDI
//         0053b3fe     MOV        dword ptr [ESI + EAX*0x4 + -0x4],0x0
//         0053b406     JL         LAB_0053b3f8
//                               LAB_0053b408                                                 XREF[2]:     0053b3c5(j), 0053b3f6(j)
//                              view.cpp:6855 (9)
//         0053b408     MOV        EAX,dword ptr [ECX + this->YLine_Size]
//         0053b40b     XOR        EBX,EBX
//         0053b40d     TEST       EAX,EAX
//         0053b40f     JLE        LAB_0053b46e
//                              view.cpp:6857 (10)
//         0053b411     MOV        ESI,dword ptr [ESP + param_1]
//                               LAB_0053b415                                                 XREF[1]:     0053b46c(j)
//         0053b415     MOV        EAX,dword ptr [ECX + this->Draw_Clip_Nodes]
//         0053b418     MOV        EAX,dword ptr [EAX + EBX*0x4]
//                              view.cpp:6859 (4)
//         0053b41b     TEST       EAX,EAX
//         0053b41d     JZ         LAB_0053b466
//                               LAB_0053b41f                                                 XREF[1]:     0053b464(j)
//                              view.cpp:6861 (15)
//         0053b41f     MOV        EDI,dword ptr [EAX + 0x2c]
//         0053b422     CMP        EDI,0x4
//         0053b425     JA         switchD_0053b427::default
//                               switchD_0053b427::switchD
//         0053b427     JMP        dword ptr [EDI*0x4 + switchD_0053b427::switchd   = 0053b42e
//                               switchD_0053b427::caseD_0                                    XREF[2]:     0053b427(j), 0053b478(*)
//                              view.cpp:6865 (3)
//         0053b42e     MOV        EBP,dword ptr [EAX + 0x14]
//                              view.cpp:6866 (13)
//         0053b431     MOV        EDI,dword ptr [EAX + 0x18]
//         0053b434     SUB        EBP,ESI
//         0053b436     SUB        EDI,EDX
//         0053b438     MOV        dword ptr [EAX + 0x14],EBP
//         0053b43b     MOV        dword ptr [EAX + 0x18],EDI
//                              view.cpp:6867 (2)
//         0053b43e     JMP        switchD_0053b427::default
//                               switchD_0053b427::caseD_1                                    XREF[2]:     0053b427(j), 0053b47c(*)
//                              view.cpp:6871 (4)
//         0053b440     SUB        word ptr [EAX + 0x3a],DX
//                              view.cpp:6872 (4)
//         0053b444     SUB        word ptr [EAX + 0x3e],DX
//                               switchD_0053b427::caseD_2                                    XREF[2]:     0053b427(j), 0053b480(*)
//                              view.cpp:6876 (4)
//         0053b448     SUB        word ptr [EAX + 0x38],SI
//                              view.cpp:6877 (4)
//         0053b44c     SUB        word ptr [EAX + 0x3c],SI
//                               switchD_0053b427::caseD_4                                    XREF[3]:     0053b427(j), 0053b484(*),
//                               switchD_0053b427::caseD_3                                                 0053b488(*)
//                              view.cpp:6882 (4)
//         0053b450     SUB        word ptr [EAX + 0x30],SI
//                              view.cpp:6883 (4)
//         0053b454     SUB        word ptr [EAX + 0x32],DX
//                              view.cpp:6884 (4)
//         0053b458     SUB        word ptr [EAX + 0x34],SI
//                              view.cpp:6885 (4)
//         0053b45c     SUB        word ptr [EAX + 0x36],DX
//                               switchD_0053b427::default                                    XREF[2]:     0053b425(j), 0053b43e(j)
//                              view.cpp:6891 (6)
//         0053b460     MOV        EAX,dword ptr [EAX]
//         0053b462     TEST       EAX,EAX
//         0053b464     JNZ        LAB_0053b41f
//                               LAB_0053b466                                                 XREF[1]:     0053b41d(j)
//                              view.cpp:6855 (8)
//         0053b466     MOV        EAX,dword ptr [ECX + this->YLine_Size]
//         0053b469     INC        EBX
//         0053b46a     CMP        EBX,EAX
//         0053b46c     JL         LAB_0053b415
//                               LAB_0053b46e                                                 XREF[1]:     0053b40f(j)
//                              view.cpp:6898 (30)
//         0053b46e     POP        EDI
//         0053b46f     POP        ESI
//         0053b470     POP        EBP
//         0053b471     POP        EBX
//         0053b472     RET        0x8
    return;
}

void DClipInfo_List::FreeNode(DClipInfo_Node* param_1) {
    /* TODO: Stub */
//                              void __thiscall FreeNode(DClipInfo_List * this, DClipInfo_Node * par
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              DClipInfo_Node    Stack[0x4]:4   param_1                   XREF[1]:     0053b490(R)
//                               ?FreeNode@DClipInfo_List@@QAEXPAUDClipInfo_Node@@@Z
//                               DClipInfo_List::FreeNode
//                              view.cpp:6906 (9)
//         0053b490     MOV        EAX,dword ptr [ESP + param_1]
//         0053b494     MOV        EDX,dword ptr [ECX + this->Free_Head]
//         0053b497     MOV        dword ptr [EAX],EDX
//                              view.cpp:6910 (3)
//         0053b499     MOV        dword ptr [ECX + this->Free_Head],EAX
//                              view.cpp:6911 (3)
//         0053b49c     INC        dword ptr [ECX + this->Free_Blocks]
//                              view.cpp:6913 (3)
//         0053b49f     RET        0x4
//         0053b4a2     ??         90h
//         0053b4a3     NOP
//         0053b4a4     NOP
//         0053b4a5     NOP
//         0053b4a6     NOP
//         0053b4a7     NOP
//         0053b4a8     NOP
//         0053b4a9     NOP
//         0053b4aa     NOP
//         0053b4ab     NOP
//         0053b4ac     NOP
//         0053b4ad     NOP
//         0053b4ae     NOP
//         0053b4af     NOP
    return;
}

int DClipInfo_List::FreeThread(DClipInfo_Node* param_1, DClipInfo_Node* param_2) {
    /* TODO: Stub */
//                              int __thiscall FreeThread(DClipInfo_List * this, DClipInfo_Node * pa
//              int               EAX:4          <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//              DClipInfo_Node    Stack[0x4]:4   param_1                   XREF[1]:     0053b4b1(R)
//              DClipInfo_Node    Stack[0x8]:4   param_2                   XREF[1]:     0053b4c2(R)
//                               ?FreeThread@DClipInfo_List@@QAEHPAUDClipInfo_Node@@0@Z
//                               DClipInfo_List::FreeThread
//                              view.cpp:6923 (1)
//         0053b4b0     PUSH       EDI
//                              view.cpp:6924 (4)
//         0053b4b1     MOV        EDI,dword ptr [ESP + param_1]
//                              view.cpp:6925 (4)
//         0053b4b5     XOR        EAX,EAX
//         0053b4b7     MOV        EDX,EDI
//                              view.cpp:6927 (4)
//         0053b4b9     TEST       EDI,EDI
//         0053b4bb     JNZ        LAB_0053b4c1
//                              view.cpp:6957 (4)
//         0053b4bd     POP        EDI
//         0053b4be     RET        0x8
//                               LAB_0053b4c1                                                 XREF[1]:     0053b4bb(j)
//                              view.cpp:6923 (1)
//         0053b4c1     PUSH       ESI
//                              view.cpp:6931 (9)
//         0053b4c2     MOV        ESI,dword ptr [ESP + param_2]
//         0053b4c6     TEST       ESI,ESI
//         0053b4c8     PUSH       EBX
//         0053b4c9     JNZ        LAB_0053b4e9
//                               LAB_0053b4cb                                                 XREF[1]:     0053b4d9(j)
//                              view.cpp:6936 (6)
//         0053b4cb     MOV        EBX,dword ptr [ECX + this->Free_Blocks]
//         0053b4ce     MOV        ESI,EDX
//         0053b4d0     INC        EBX
//                              view.cpp:6937 (4)
//         0053b4d1     INC        EAX
//         0053b4d2     MOV        dword ptr [ECX + this->Free_Blocks],EBX
//                              view.cpp:6938 (6)
//         0053b4d5     MOV        EDX,dword ptr [EDX]
//         0053b4d7     TEST       EDX,EDX
//         0053b4d9     JNZ        LAB_0053b4cb
//                              view.cpp:6953 (6)
//         0053b4db     MOV        EDX,dword ptr [ECX + this->Free_Head]
//         0053b4de     POP        EBX
//         0053b4df     MOV        dword ptr [ESI],EDX
//                              view.cpp:6954 (4)
//         0053b4e1     MOV        dword ptr [ECX + this->Free_Head],EDI
//         0053b4e4     POP        ESI
//                              view.cpp:6957 (4)
//         0053b4e5     POP        EDI
//         0053b4e6     RET        0x8
//                               LAB_0053b4e9                                                 XREF[2]:     0053b4c9(j), 0053b4fd(j)
//                              view.cpp:6945 (4)
//         0053b4e9     MOV        EBX,dword ptr [ECX + this->Free_Blocks]
//         0053b4ec     INC        EBX
//                              view.cpp:6946 (1)
//         0053b4ed     INC        EAX
//                              view.cpp:6947 (13)
//         0053b4ee     CMP        EDX,ESI
//         0053b4f0     MOV        dword ptr [ECX + this->Free_Blocks],EBX
//         0053b4f3     JZ         LAB_0053b4f9
//         0053b4f5     MOV        EDX,dword ptr [EDX]
//         0053b4f7     JMP        LAB_0053b4fb
//                               LAB_0053b4f9                                                 XREF[1]:     0053b4f3(j)
//         0053b4f9     XOR        EDX,EDX
//                               LAB_0053b4fb                                                 XREF[1]:     0053b4f7(j)
//                              view.cpp:6948 (4)
//         0053b4fb     TEST       EDX,EDX
//         0053b4fd     JNZ        LAB_0053b4e9
//                              view.cpp:6953 (6)
//         0053b4ff     MOV        EDX,dword ptr [ECX + this->Free_Head]
//         0053b502     POP        EBX
//         0053b503     MOV        dword ptr [ESI],EDX
//                              view.cpp:6954 (4)
//         0053b505     MOV        dword ptr [ECX + this->Free_Head],EDI
//         0053b508     POP        ESI
//                              view.cpp:6957 (4)
//         0053b509     POP        EDI
//         0053b50a     RET        0x8
//         0053b50d     ??         90h
//         0053b50e     NOP
//         0053b50f     NOP
    return 0;
}

void DClipInfo_List::ReclaimAllNodes() {
    /* TODO: Stub */
//                              void __thiscall ReclaimAllNodes(DClipInfo_List * this)
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//                               ?ReclaimAllNodes@DClipInfo_List@@QAEXXZ                      XREF[2]:     view_function_terrain:00536c10(c),
//                               DClipInfo_List::ReclaimAllNodes                                           view_function_terrain:00537c3b(c)
//                              view.cpp:6964 (4)
//         0053b510     MOV        EDX,this
//         0053b512     PUSH       ESI
//         0053b513     PUSH       EDI
//                              view.cpp:6966 (25)
//         0053b514     XOR        EAX,EAX
//         0053b516     MOV        this,dword ptr [EDX + 0x68]
//         0053b519     MOV        EDI,dword ptr [EDX + 0x58]
//         0053b51c     SHL        this,0x2
//         0053b51f     MOV        ESI,this
//         0053b521     SHR        this,0x2
//         0053b524     STOSD.REP  ES:EDI
//         0053b526     MOV        this,ESI
//         0053b528     AND        this,0x3
//         0053b52b     STOSB.REP  ES:EDI
//                              view.cpp:6967 (29)
//         0053b52d     MOV        EAX,dword ptr [EDX + 0x4c]
//         0053b530     MOV        EDI,dword ptr [EDX + 0x5c]
//         0053b533     LEA        this,[EAX*0x4 + 0x4]
//         0053b53a     XOR        EAX,EAX
//         0053b53c     MOV        ESI,this
//         0053b53e     SHR        this,0x2
//         0053b541     STOSD.REP  ES:EDI
//         0053b543     MOV        this,ESI
//         0053b545     AND        this,0x3
//         0053b548     STOSB.REP  ES:EDI
//                              view.cpp:6968 (29)
//         0053b54a     MOV        this,dword ptr [EDX + 0x4c]
//         0053b54d     MOV        EDI,dword ptr [EDX + 0x60]
//         0053b550     XOR        EAX,EAX
//         0053b552     LEA        this,[this->Zone_Ptrs*0x4 + 0x4]
//         0053b559     MOV        ESI,this
//         0053b55b     SHR        this,0x2
//         0053b55e     STOSD.REP  ES:EDI
//         0053b560     MOV        this,ESI
//         0053b562     AND        this,0x3
//         0053b565     STOSB.REP  ES:EDI
//                              view.cpp:6970 (2)
//         0053b567     XOR        EAX,EAX
//                              view.cpp:6976 (25)
//         0053b569     POP        EDI
//         0053b56a     MOV        dword ptr [EDX + 0x10],EAX
//         0053b56d     MOV        dword ptr [EDX + 0x14],EAX
//         0053b570     MOV        dword ptr [EDX + 0x18],EAX
//         0053b573     MOV        EAX,dword ptr [EDX + 0x1c]
//         0053b576     MOV        dword ptr [EDX + 0x20],EAX
//         0053b579     MOV        EAX,dword ptr [EDX + 0x38]
//         0053b57c     INC        EAX
//         0053b57d     POP        ESI
//         0053b57e     MOV        dword ptr [EDX + 0x38],EAX
//         0053b581     RET
//         0053b582     ??         90h
//         0053b583     NOP
//         0053b584     NOP
//         0053b585     NOP
//         0053b586     NOP
//         0053b587     NOP
//         0053b588     NOP
//         0053b589     NOP
//         0053b58a     NOP
//         0053b58b     NOP
//         0053b58c     NOP
//         0053b58d     NOP
//         0053b58e     NOP
//         0053b58f     NOP
    return;
}

void DClipInfo_List::ResetStats() {
    /* TODO: Stub */
//                              void __thiscall ResetStats(DClipInfo_List * this)
//              void              <VOID>         <RETURN>
//              DClipInfo_List    ECX:4 (auto)   this
//                               ?ResetStats@DClipInfo_List@@QAEXXZ                           XREF[1]:     DClipInfo_List:0053ae21(c)
//                               DClipInfo_List::ResetStats
//                              view.cpp:6984 (5)
//         0053b590     XOR        EAX,EAX
//         0053b592     MOV        dword ptr [ECX + this->Alloc_Count],EAX
//                              view.cpp:6986 (3)
//         0053b595     MOV        dword ptr [ECX + this->Dealloc_Count],EAX
//                              view.cpp:6987 (3)
//         0053b598     MOV        dword ptr [ECX + this->NewZone_Count],EAX
//                              view.cpp:6988 (3)
//         0053b59b     MOV        dword ptr [ECX + this->Reset_Count],EAX
//                              view.cpp:6990 (1)
//         0053b59e     RET
//         0053b59f     ??         90h
    return;
}

