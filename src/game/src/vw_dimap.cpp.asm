// Auto-generated scaffold unit: vw_dimap.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/vw_dimap.cpp
#include "../include/common.h"

// Offset: 0x0053D360
undefined RGE_Diamond_Map_View(RGE_Diamond_Map_View* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall RGE_Diamond_Map_View::RGE_Diamond_Map_View(void)                                   *
    //                              *********************************************************************************************************
    //                              undefined __thiscall RGE_Diamond_Map_View(RGE_Diamond_Map_View * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ??0RGE_Diamond_Map_View@@QAE@XZ                              XREF[2]:     TRIBE_Screen_Sed:004a8445(c), 
    //                               RGE_Diamond_Map_View::RGE_Diamond_Map_View                                TRIBE_Diamond_Map_View:0052c9e3(c)
    //                              vw_dimap.cpp:26 (14)
    //         0053d360     PUSH       ESI
    //         0053d361     MOV        ESI,this
    //         0053d363     CALL       RGE_Diamond_Map::RGE_Diamond_Map                 undefined RGE_Diamond_Map(RGE_Diamond_Map * t
    //         0053d368     MOV        dword ptr [ESI],RGE_Diamond_Map_View::`vftable'  = 0053d380
    //                              vw_dimap.cpp:27 (10)
    //         0053d36e     MOV        dword ptr [ESI + 0xc0],0x0
    //                              vw_dimap.cpp:28 (4)
    //         0053d378     MOV        EAX,ESI
    //         0053d37a     POP        ESI
    //         0053d37b     RET
}

// Offset: 0x0053D3B0
long RGE_Diamond_Map_View::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::handle_mouse_down(unsigned char,long,long,in... *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_mouse_down(RGE_Diamond_Map_View * this, uchar
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0053d3e9(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0053d3b2(R), 0053d3c7(*)  
    //              long              Stack[0xc]:4   param_3                   XREF[2]:     0053d3be(R), 0053d3c2(*)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0053d3e5(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0053d3e1(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053d3b9(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile
    //                               ?handle_mouse_down@RGE_Diamond_Map_View@@UAEJEJJHH@Z         XREF[2]:     005773c0(*), 00577758(*)  
    //                               RGE_Diamond_Map_View::handle_mouse_down
    //                              vw_dimap.cpp:34 (2)
    //         0053d3b0     PUSH       this
    //         0053d3b1     PUSH       EBX
    //                              vw_dimap.cpp:40 (40)
    //         0053d3b2     MOV        EBX,dword ptr [ESP + param_2]
    //         0053d3b6     PUSH       ESI
    //         0053d3b7     MOV        ESI,this
    //         0053d3b9     LEA        EAX=>local_4,[ESP + 0x8]
    //         0053d3bd     PUSH       EDI
    //         0053d3be     MOV        EDI,dword ptr [ESP + param_3]
    //         0053d3c2     LEA        this=>param_3,[ESP + 0x1c]
    //         0053d3c6     PUSH       EAX
    //         0053d3c7     LEA        EDX=>param_2,[ESP + 0x1c]
    //         0053d3cb     PUSH       this
    //         0053d3cc     PUSH       EDX
    //         0053d3cd     PUSH       EDI
    //         0053d3ce     PUSH       EBX
    //         0053d3cf     MOV        this,ESI
    //         0053d3d1     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         0053d3d6     TEST       EAX,EAX
    //         0053d3d8     JNZ        LAB_0053d3e1
    //                              vw_dimap.cpp:44 (7)
    //         0053d3da     POP        EDI
    //         0053d3db     POP        ESI
    //         0053d3dc     POP        EBX
    //         0053d3dd     POP        this
    //         0053d3de     RET        0x14
    //                               LAB_0053d3e1                                                 XREF[1]:     0053d3d8(j)  
    //                              vw_dimap.cpp:43 (24)
    //         0053d3e1     MOV        EAX,dword ptr [ESP + param_5]
    //         0053d3e5     MOV        this,dword ptr [ESP + param_4]
    //         0053d3e9     MOV        EDX,dword ptr [ESP + param_1]
    //         0053d3ed     PUSH       EAX
    //         0053d3ee     PUSH       this
    //         0053d3ef     PUSH       EDI
    //         0053d3f0     PUSH       EBX
    //         0053d3f1     PUSH       EDX
    //         0053d3f2     MOV        this,ESI
    //         0053d3f4     CALL       TPanel::handle_mouse_down                        long handle_mouse_down(TPanel * this, uchar p
    //                              vw_dimap.cpp:44 (7)
    //         0053d3f9     POP        EDI
    //         0053d3fa     POP        ESI
    //         0053d3fb     POP        EBX
    //         0053d3fc     POP        this
    //         0053d3fd     RET        0x14
}

// Offset: 0x0053D400
long RGE_Diamond_Map_View::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::mouse_left_down_action(long,long,int,int)       *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_down_action(RGE_Diamond_Map_View * this, 
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0053d443(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0053d43f(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_down_action@RGE_Diamond_Map_View@@UAEJJJHH@Z     XREF[2]:     005773d4(*), 0057776c(*)  
    //                               RGE_Diamond_Map_View::mouse_left_down_action
    //                              vw_dimap.cpp:50 (3)
    //         0053d400     PUSH       ESI
    //         0053d401     MOV        ESI,this
    //                              vw_dimap.cpp:51 (47)
    //         0053d403     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d409     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0053d40e     TEST       EAX,EAX
    //         0053d410     JNZ        LAB_0053d478
    //         0053d412     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d418     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b0]
    //         0053d41e     CMP        EAX,0x4
    //         0053d421     JZ         LAB_0053d432
    //         0053d423     CMP        EAX,0x6
    //         0053d426     JZ         LAB_0053d432
    //         0053d428     CMP        EAX,0x7
    //         0053d42b     JZ         LAB_0053d432
    //         0053d42d     CMP        EAX,0x5
    //         0053d430     JNZ        LAB_0053d478
    //                               LAB_0053d432                                                 XREF[3]:     0053d421(j), 0053d426(j), 
    //                                                                                                         0053d42b(j)  
    //                              vw_dimap.cpp:54 (13)
    //         0053d432     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         0053d435     CMP        word ptr [this->field0_0x0 + 0x8dc],0x2
    //         0053d43d     JNZ        LAB_0053d459
    //                              vw_dimap.cpp:55 (17)
    //         0053d43f     MOV        EDX,dword ptr [ESP + param_2]
    //         0053d443     MOV        EAX,dword ptr [ESP + param_1]
    //         0053d447     PUSH       EDX
    //         0053d448     PUSH       EAX
    //         0053d449     MOV        this,ESI
    //         0053d44b     CALL       RGE_Diamond_Map::start_scroll_view               void start_scroll_view(RGE_Diamond_Map * this
    //                              vw_dimap.cpp:62 (5)
    //         0053d450     MOV        EAX,0x1
    //                              vw_dimap.cpp:63 (4)
    //         0053d455     POP        ESI
    //         0053d456     RET        0x10
    //                               LAB_0053d459                                                 XREF[1]:     0053d43d(j)  
    //                              vw_dimap.cpp:58 (15)
    //         0053d459     CMP        EAX,0x4
    //         0053d45c     JZ         LAB_0053d468
    //         0053d45e     CMP        EAX,0x6
    //         0053d461     JZ         LAB_0053d468
    //         0053d463     CMP        EAX,0x7
    //         0053d466     JNZ        LAB_0053d46f
    //                               LAB_0053d468                                                 XREF[2]:     0053d45c(j), 0053d461(j)  
    //                              vw_dimap.cpp:59 (7)
    //         0053d468     MOV        this,ESI
    //         0053d46a     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
    //                               LAB_0053d46f                                                 XREF[1]:     0053d466(j)  
    //                              vw_dimap.cpp:62 (5)
    //         0053d46f     MOV        EAX,0x1
    //                              vw_dimap.cpp:63 (4)
    //         0053d474     POP        ESI
    //         0053d475     RET        0x10
    //                               LAB_0053d478                                                 XREF[2]:     0053d410(j), 0053d430(j)  
    //                              vw_dimap.cpp:52 (2)
    //         0053d478     XOR        EAX,EAX
    //                              vw_dimap.cpp:63 (4)
    //         0053d47a     POP        ESI
    //         0053d47b     RET        0x10
}

// Offset: 0x0053D480
long RGE_Diamond_Map_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::mouse_left_move_action(long,long,int,int)       *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_move_action(RGE_Diamond_Map_View * this, 
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0053d4d6(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0053d4d2(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_move_action@RGE_Diamond_Map_View@@UAEJJJHH@Z     XREF[2]:     005773dc(*), 00577774(*)  
    //                               RGE_Diamond_Map_View::mouse_left_move_action
    //                              vw_dimap.cpp:69 (3)
    //         0053d480     PUSH       ESI
    //         0053d481     MOV        ESI,this
    //                              vw_dimap.cpp:70 (30)
    //         0053d483     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d489     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b0]
    //         0053d48f     CMP        EAX,0x4
    //         0053d492     JZ         LAB_0053d4a3
    //         0053d494     CMP        EAX,0x6
    //         0053d497     JZ         LAB_0053d4a3
    //         0053d499     CMP        EAX,0x7
    //         0053d49c     JZ         LAB_0053d4a3
    //         0053d49e     CMP        EAX,0x5
    //                              vw_dimap.cpp:71 (2)
    //         0053d4a1     JNZ        LAB_0053d4ec
    //                               LAB_0053d4a3                                                 XREF[3]:     0053d492(j), 0053d497(j), 
    //                                                                                                         0053d49c(j)  
    //                              vw_dimap.cpp:73 (7)
    //         0053d4a3     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0053d4a8     TEST       EAX,EAX
    //                              vw_dimap.cpp:75 (10)
    //         0053d4aa     MOV        EAX,dword ptr [ESI + 0x154]
    //         0053d4b0     JZ         LAB_0053d4ce
    //         0053d4b2     TEST       EAX,EAX
    //                              vw_dimap.cpp:76 (9)
    //         0053d4b4     MOV        this,ESI
    //         0053d4b6     JZ         LAB_0053d4c3
    //         0053d4b8     CALL       RGE_Diamond_Map::end_scroll_view                 void end_scroll_view(RGE_Diamond_Map * this)
    //                              vw_dimap.cpp:88 (2)
    //         0053d4bd     XOR        EAX,EAX
    //                              vw_dimap.cpp:89 (4)
    //         0053d4bf     POP        ESI
    //         0053d4c0     RET        0x10
    //                               LAB_0053d4c3                                                 XREF[1]:     0053d4b6(j)  
    //                              vw_dimap.cpp:78 (5)
    //         0053d4c3     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              vw_dimap.cpp:88 (2)
    //         0053d4c8     XOR        EAX,EAX
    //                              vw_dimap.cpp:89 (4)
    //         0053d4ca     POP        ESI
    //         0053d4cb     RET        0x10
    //                               LAB_0053d4ce                                                 XREF[1]:     0053d4b0(j)  
    //                              vw_dimap.cpp:82 (4)
    //         0053d4ce     TEST       EAX,EAX
    //         0053d4d0     JZ         LAB_0053d4ec
    //                              vw_dimap.cpp:84 (17)
    //         0053d4d2     MOV        EAX,dword ptr [ESP + param_2]
    //         0053d4d6     MOV        this,dword ptr [ESP + param_1]
    //         0053d4da     PUSH       EAX
    //         0053d4db     PUSH       this
    //         0053d4dc     MOV        this,ESI
    //         0053d4de     CALL       RGE_Diamond_Map::handle_scroll_view              void handle_scroll_view(RGE_Diamond_Map * thi
    //                              vw_dimap.cpp:85 (5)
    //         0053d4e3     MOV        EAX,0x1
    //                              vw_dimap.cpp:89 (4)
    //         0053d4e8     POP        ESI
    //         0053d4e9     RET        0x10
    //                               LAB_0053d4ec                                                 XREF[2]:     0053d4a1(j), 0053d4d0(j)  
    //                              vw_dimap.cpp:88 (2)
    //         0053d4ec     XOR        EAX,EAX
    //                              vw_dimap.cpp:89 (4)
    //         0053d4ee     POP        ESI
    //         0053d4ef     RET        0x10
}

// Offset: 0x0053D500
long RGE_Diamond_Map_View::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::mouse_left_up_action(long,long,int,int)         *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_up_action(RGE_Diamond_Map_View * this, lo
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0053d579(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0053d575(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053d57d(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[1,1]:   0053d581(*), 0053d586(*)  
    //              short             Stack[-0xa]:2  col
    //              short             Stack[-0xc]:2  row
    //                               ?mouse_left_up_action@RGE_Diamond_Map_View@@UAEJJJHH@Z       XREF[2]:     005773e0(*), 00577778(*)  
    //                               RGE_Diamond_Map_View::mouse_left_up_action
    //                              vw_dimap.cpp:95 (37)
    //         0053d500     MOV        EAX,[rge_base_game]                              = 00000000
    //         0053d505     SUB        ESP,0x8
    //         0053d508     MOV        EAX,dword ptr [EAX + 0x1b0]
    //         0053d50e     PUSH       EBX
    //         0053d50f     PUSH       ESI
    //         0053d510     CMP        EAX,0x4
    //         0053d513     PUSH       EDI
    //         0053d514     MOV        ESI,this
    //         0053d516     JZ         LAB_0053d52b
    //         0053d518     CMP        EAX,0x6
    //         0053d51b     JZ         LAB_0053d52b
    //         0053d51d     CMP        EAX,0x7
    //         0053d520     JZ         LAB_0053d52b
    //         0053d522     CMP        EAX,0x5
    //                              vw_dimap.cpp:102 (6)
    //         0053d525     JNZ        LAB_0053d611
    //                               LAB_0053d52b                                                 XREF[3]:     0053d516(j), 0053d51b(j), 
    //                                                                                                         0053d520(j)  
    //                              vw_dimap.cpp:104 (6)
    //         0053d52b     MOV        EAX,dword ptr [ESI + 0x154]
    //                              vw_dimap.cpp:106 (11)
    //         0053d531     MOV        this,ESI
    //         0053d533     TEST       EAX,EAX
    //         0053d535     JZ         LAB_0053d54a
    //         0053d537     CALL       RGE_Diamond_Map::end_scroll_view                 void end_scroll_view(RGE_Diamond_Map * this)
    //                              vw_dimap.cpp:107 (5)
    //         0053d53c     MOV        EAX,0x1
    //                              vw_dimap.cpp:148 (9)
    //         0053d541     POP        EDI
    //         0053d542     POP        ESI
    //         0053d543     POP        EBX
    //         0053d544     ADD        ESP,0x8
    //         0053d547     RET        0x10
    //                               LAB_0053d54a                                                 XREF[1]:     0053d535(j)  
    //                              vw_dimap.cpp:110 (5)
    //         0053d54a     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              vw_dimap.cpp:112 (13)
    //         0053d54f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d555     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0053d55a     TEST       EAX,EAX
    //                              vw_dimap.cpp:113 (6)
    //         0053d55c     JNZ        LAB_0053d611
    //                              vw_dimap.cpp:115 (13)
    //         0053d562     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d568     CMP        dword ptr [this->field0_0x0 + 0x1b0],0x5
    //                              vw_dimap.cpp:116 (6)
    //         0053d56f     JZ         LAB_0053d611
    //                              vw_dimap.cpp:118 (36)
    //         0053d575     MOV        EDI,dword ptr [ESP + param_2]
    //         0053d579     MOV        EBX,dword ptr [ESP + param_1]
    //         0053d57d     LEA        EDX=>local_4,[ESP + 0x10]
    //         0053d581     LEA        EAX=>tile,[ESP + 0xc]
    //         0053d585     PUSH       EDX
    //         0053d586     LEA        this=>tile+0x2,[ESP + 0x12]
    //         0053d58a     PUSH       EAX
    //         0053d58b     PUSH       this
    //         0053d58c     PUSH       EDI
    //         0053d58d     PUSH       EBX
    //         0053d58e     MOV        this,ESI
    //         0053d590     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         0053d595     TEST       EAX,EAX
    //         0053d597     JZ         LAB_0053d611
    //                              vw_dimap.cpp:125 (25)
    //         0053d599     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d59f     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b4]
    //         0053d5a5     SUB        EAX,0x0
    //         0053d5a8     JZ         LAB_0053d5e6
    //         0053d5aa     SUB        EAX,0x4
    //         0053d5ad     JZ         LAB_0053d5cc
    //         0053d5af     DEC        EAX
    //         0053d5b0     JNZ        LAB_0053d611
    //                              vw_dimap.cpp:132 (12)
    //         0053d5b2     MOV        EDX,dword ptr [ESI]
    //         0053d5b4     PUSH       EDI
    //         0053d5b5     PUSH       EBX
    //         0053d5b6     MOV        this,ESI
    //         0053d5b8     CALL       dword ptr [EDX + 0xfc]
    //                              vw_dimap.cpp:133 (5)
    //         0053d5be     MOV        EAX,0x1
    //                              vw_dimap.cpp:148 (9)
    //         0053d5c3     POP        EDI
    //         0053d5c4     POP        ESI
    //         0053d5c5     POP        EBX
    //         0053d5c6     ADD        ESP,0x8
    //         0053d5c9     RET        0x10
    //                               LAB_0053d5cc                                                 XREF[1]:     0053d5ad(j)  
    //                              vw_dimap.cpp:128 (12)
    //         0053d5cc     MOV        EAX,dword ptr [ESI]
    //         0053d5ce     PUSH       EDI
    //         0053d5cf     PUSH       EBX
    //         0053d5d0     MOV        this,ESI
    //         0053d5d2     CALL       dword ptr [EAX + 0xf8]
    //                              vw_dimap.cpp:129 (5)
    //         0053d5d8     MOV        EAX,0x1
    //                              vw_dimap.cpp:148 (9)
    //         0053d5dd     POP        EDI
    //         0053d5de     POP        ESI
    //         0053d5df     POP        EBX
    //         0053d5e0     ADD        ESP,0x8
    //         0053d5e3     RET        0x10
    //                               LAB_0053d5e6                                                 XREF[1]:     0053d5a8(j)  
    //                              vw_dimap.cpp:136 (11)
    //         0053d5e6     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         0053d5e9     CMP        word ptr [this->field0_0x0 + 0x8dc],0x2
    //                              vw_dimap.cpp:137 (2)
    //         0053d5f1     JZ         LAB_0053d611
    //                              vw_dimap.cpp:141 (16)
    //         0053d5f3     MOV        EDX,dword ptr [ESI]
    //         0053d5f5     PUSH       EDI
    //         0053d5f6     PUSH       EBX
    //         0053d5f7     MOV        this,ESI
    //         0053d5f9     CALL       dword ptr [EDX + 0xf4]
    //         0053d5ff     TEST       EAX,EAX
    //         0053d601     JZ         LAB_0053d611
    //                              vw_dimap.cpp:142 (5)
    //         0053d603     MOV        EAX,0x1
    //                              vw_dimap.cpp:148 (20)
    //         0053d608     POP        EDI
    //         0053d609     POP        ESI
    //         0053d60a     POP        EBX
    //         0053d60b     ADD        ESP,0x8
    //         0053d60e     RET        0x10
    //                               LAB_0053d611                                                 XREF[7]:     0053d525(j), 0053d55c(j), 
    //                                                                                                         0053d56f(j), 0053d597(j), 
    //                                                                                                         0053d5b0(j), 0053d5f1(j), 
    //                                                                                                         0053d601(j)  
    //         0053d611     POP        EDI
    //         0053d612     POP        ESI
    //         0053d613     XOR        EAX,EAX
    //         0053d615     POP        EBX
    //         0053d616     ADD        ESP,0x8
    //         0053d619     RET        0x10
}

// Offset: 0x0053D620
long RGE_Diamond_Map_View::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::mouse_right_down_action(long,long,int,int)      *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_down_action(RGE_Diamond_Map_View * this,
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0053d682(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0053d67e(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_right_down_action@RGE_Diamond_Map_View@@UAEJJJHH@Z    XREF[2]:     005773e8(*), 00577780(*)  
    //                               RGE_Diamond_Map_View::mouse_right_down_action
    //                              vw_dimap.cpp:154 (3)
    //         0053d620     PUSH       ESI
    //         0053d621     MOV        ESI,this
    //                              vw_dimap.cpp:155 (47)
    //         0053d623     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d629     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0053d62e     TEST       EAX,EAX
    //         0053d630     JNZ        LAB_0053d698
    //         0053d632     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d638     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b0]
    //         0053d63e     CMP        EAX,0x4
    //         0053d641     JZ         LAB_0053d652
    //         0053d643     CMP        EAX,0x6
    //         0053d646     JZ         LAB_0053d652
    //         0053d648     CMP        EAX,0x7
    //         0053d64b     JZ         LAB_0053d652
    //         0053d64d     CMP        EAX,0x5
    //         0053d650     JNZ        LAB_0053d698
    //                               LAB_0053d652                                                 XREF[3]:     0053d641(j), 0053d646(j), 
    //                                                                                                         0053d64b(j)  
    //                              vw_dimap.cpp:158 (13)
    //         0053d652     MOV        this,dword ptr [ECX + this->field12_0xc]
    //         0053d655     CMP        word ptr [this->field0_0x0 + 0x8dc],0x2
    //         0053d65d     JNZ        LAB_0053d67e
    //                              vw_dimap.cpp:160 (15)
    //         0053d65f     CMP        EAX,0x4
    //         0053d662     JZ         LAB_0053d66e
    //         0053d664     CMP        EAX,0x6
    //         0053d667     JZ         LAB_0053d66e
    //         0053d669     CMP        EAX,0x7
    //         0053d66c     JNZ        LAB_0053d68f
    //                               LAB_0053d66e                                                 XREF[2]:     0053d662(j), 0053d667(j)  
    //                              vw_dimap.cpp:161 (7)
    //         0053d66e     MOV        this,ESI
    //         0053d670     CALL       TPanel::capture_mouse                            int capture_mouse(TPanel * this)
    //                              vw_dimap.cpp:166 (5)
    //         0053d675     MOV        EAX,0x1
    //                              vw_dimap.cpp:167 (4)
    //         0053d67a     POP        ESI
    //         0053d67b     RET        0x10
    //                               LAB_0053d67e                                                 XREF[1]:     0053d65d(j)  
    //                              vw_dimap.cpp:164 (17)
    //         0053d67e     MOV        EDX,dword ptr [ESP + param_2]
    //         0053d682     MOV        EAX,dword ptr [ESP + param_1]
    //         0053d686     PUSH       EDX
    //         0053d687     PUSH       EAX
    //         0053d688     MOV        this,ESI
    //         0053d68a     CALL       RGE_Diamond_Map::start_scroll_view               void start_scroll_view(RGE_Diamond_Map * this
    //                               LAB_0053d68f                                                 XREF[1]:     0053d66c(j)  
    //                              vw_dimap.cpp:166 (5)
    //         0053d68f     MOV        EAX,0x1
    //                              vw_dimap.cpp:167 (4)
    //         0053d694     POP        ESI
    //         0053d695     RET        0x10
    //                               LAB_0053d698                                                 XREF[2]:     0053d630(j), 0053d650(j)  
    //                              vw_dimap.cpp:156 (2)
    //         0053d698     XOR        EAX,EAX
    //                              vw_dimap.cpp:167 (4)
    //         0053d69a     POP        ESI
    //         0053d69b     RET        0x10
}

// Offset: 0x0053D6A0
long RGE_Diamond_Map_View::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::mouse_right_move_action(long,long,int,int)      *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_move_action(RGE_Diamond_Map_View * this,
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[1]:     0053d6f6(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     0053d6f2(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_right_move_action@RGE_Diamond_Map_View@@UAEJJJHH@Z    XREF[2]:     005773f0(*), 00577788(*)  
    //                               RGE_Diamond_Map_View::mouse_right_move_action
    //                              vw_dimap.cpp:173 (3)
    //         0053d6a0     PUSH       ESI
    //         0053d6a1     MOV        ESI,this
    //                              vw_dimap.cpp:174 (30)
    //         0053d6a3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d6a9     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b0]
    //         0053d6af     CMP        EAX,0x4
    //         0053d6b2     JZ         LAB_0053d6c3
    //         0053d6b4     CMP        EAX,0x6
    //         0053d6b7     JZ         LAB_0053d6c3
    //         0053d6b9     CMP        EAX,0x7
    //         0053d6bc     JZ         LAB_0053d6c3
    //         0053d6be     CMP        EAX,0x5
    //                              vw_dimap.cpp:175 (2)
    //         0053d6c1     JNZ        LAB_0053d70c
    //                               LAB_0053d6c3                                                 XREF[3]:     0053d6b2(j), 0053d6b7(j), 
    //                                                                                                         0053d6bc(j)  
    //                              vw_dimap.cpp:177 (7)
    //         0053d6c3     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0053d6c8     TEST       EAX,EAX
    //                              vw_dimap.cpp:179 (10)
    //         0053d6ca     MOV        EAX,dword ptr [ESI + 0x154]
    //         0053d6d0     JZ         LAB_0053d6ee
    //         0053d6d2     TEST       EAX,EAX
    //                              vw_dimap.cpp:180 (9)
    //         0053d6d4     MOV        this,ESI
    //         0053d6d6     JZ         LAB_0053d6e3
    //         0053d6d8     CALL       RGE_Diamond_Map::end_scroll_view                 void end_scroll_view(RGE_Diamond_Map * this)
    //                              vw_dimap.cpp:199 (2)
    //         0053d6dd     XOR        EAX,EAX
    //                              vw_dimap.cpp:200 (4)
    //         0053d6df     POP        ESI
    //         0053d6e0     RET        0x10
    //                               LAB_0053d6e3                                                 XREF[1]:     0053d6d6(j)  
    //                              vw_dimap.cpp:182 (5)
    //         0053d6e3     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              vw_dimap.cpp:199 (2)
    //         0053d6e8     XOR        EAX,EAX
    //                              vw_dimap.cpp:200 (4)
    //         0053d6ea     POP        ESI
    //         0053d6eb     RET        0x10
    //                               LAB_0053d6ee                                                 XREF[1]:     0053d6d0(j)  
    //                              vw_dimap.cpp:186 (4)
    //         0053d6ee     TEST       EAX,EAX
    //         0053d6f0     JZ         LAB_0053d70c
    //                              vw_dimap.cpp:188 (17)
    //         0053d6f2     MOV        EAX,dword ptr [ESP + param_2]
    //         0053d6f6     MOV        this,dword ptr [ESP + param_1]
    //         0053d6fa     PUSH       EAX
    //         0053d6fb     PUSH       this
    //         0053d6fc     MOV        this,ESI
    //         0053d6fe     CALL       RGE_Diamond_Map::handle_scroll_view              void handle_scroll_view(RGE_Diamond_Map * thi
    //                              vw_dimap.cpp:189 (5)
    //         0053d703     MOV        EAX,0x1
    //                              vw_dimap.cpp:200 (4)
    //         0053d708     POP        ESI
    //         0053d709     RET        0x10
    //                               LAB_0053d70c                                                 XREF[2]:     0053d6c1(j), 0053d6f0(j)  
    //                              vw_dimap.cpp:199 (2)
    //         0053d70c     XOR        EAX,EAX
    //                              vw_dimap.cpp:200 (4)
    //         0053d70e     POP        ESI
    //         0053d70f     RET        0x10
}

// Offset: 0x0053D720
long RGE_Diamond_Map_View::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall RGE_Diamond_Map_View::mouse_right_up_action(long,long,int,int)        *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_right_up_action(RGE_Diamond_Map_View * this, l
    //              long              EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[4]:     0053d7ca(R), 0053d7f9(*), 0053d7fe(R), 0053d823(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[4]:     0053d7c6(R), 0053d7f0(*), 0053d7f5(R), 0053d810(R)  
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4                   XREF[5]:     0053d7be(R), 0053d81b(W), 0053d81f(R), 0053d836(W), 
    //                                                                                     0053d83d(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053d7ec(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0053d83a(*)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0053d848(*)  
    //                               ?mouse_right_up_action@RGE_Diamond_Map_View@@UAEJJJHH@Z      XREF[2]:     005773f4(*), 0057778c(*)  
    //                               RGE_Diamond_Map_View::mouse_right_up_action
    //                              vw_dimap.cpp:206 (1)
    //         0053d720     PUSH       this
    //                              vw_dimap.cpp:207 (32)
    //         0053d721     MOV        EAX,[rge_base_game]                              = 00000000
    //         0053d726     PUSH       ESI
    //         0053d727     MOV        ESI,this
    //         0053d729     MOV        EAX,dword ptr [EAX + 0x1b0]
    //         0053d72f     CMP        EAX,0x4
    //         0053d732     JZ         LAB_0053d747
    //         0053d734     CMP        EAX,0x6
    //         0053d737     JZ         LAB_0053d747
    //         0053d739     CMP        EAX,0x7
    //         0053d73c     JZ         LAB_0053d747
    //         0053d73e     CMP        EAX,0x5
    //                              vw_dimap.cpp:208 (6)
    //         0053d741     JNZ        LAB_0053d889
    //                               LAB_0053d747                                                 XREF[3]:     0053d732(j), 0053d737(j), 
    //                                                                                                         0053d73c(j)  
    //                              vw_dimap.cpp:210 (6)
    //         0053d747     MOV        EAX,dword ptr [ESI + 0x154]
    //                              vw_dimap.cpp:212 (11)
    //         0053d74d     MOV        this,ESI
    //         0053d74f     TEST       EAX,EAX
    //         0053d751     JZ         LAB_0053d762
    //         0053d753     CALL       RGE_Diamond_Map::end_scroll_view                 void end_scroll_view(RGE_Diamond_Map * this)
    //                              vw_dimap.cpp:213 (5)
    //         0053d758     MOV        EAX,0x1
    //                              vw_dimap.cpp:261 (5)
    //         0053d75d     POP        ESI
    //         0053d75e     POP        this
    //         0053d75f     RET        0x10
    //                               LAB_0053d762                                                 XREF[1]:     0053d751(j)  
    //                              vw_dimap.cpp:216 (5)
    //         0053d762     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              vw_dimap.cpp:218 (13)
    //         0053d767     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d76d     CALL       RGE_Base_Game::get_paused                        int get_paused(RGE_Base_Game * this)
    //         0053d772     TEST       EAX,EAX
    //                              vw_dimap.cpp:219 (6)
    //         0053d774     JNZ        LAB_0053d889
    //                              vw_dimap.cpp:225 (18)
    //         0053d77a     MOV        AL,byte ptr [ESI + 0xec]
    //         0053d780     CMP        AL,0x1
    //         0053d782     JZ         LAB_0053d78c
    //         0053d784     CMP        AL,0x2
    //         0053d786     JNZ        LAB_0053d889
    //                               LAB_0053d78c                                                 XREF[1]:     0053d782(j)  
    //                              vw_dimap.cpp:227 (23)
    //         0053d78c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d792     MOV        EDX,dword ptr [ECX + this->field12_0xc]
    //         0053d795     CMP        word ptr [EDX + 0x8dc],0x2
    //         0053d79d     JNZ        LAB_0053d85b
    //                              vw_dimap.cpp:229 (27)
    //         0053d7a3     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b4]
    //         0053d7a9     TEST       EAX,EAX
    //         0053d7ab     JNZ        LAB_0053d889
    //         0053d7b1     CMP        dword ptr [this->field0_0x0 + 0x1b0],0x5
    //         0053d7b8     JZ         LAB_0053d889
    //                              vw_dimap.cpp:231 (8)
    //         0053d7be     MOV        EAX,dword ptr [ESP + param_4]
    //         0053d7c2     TEST       EAX,EAX
    //         0053d7c4     JNZ        LAB_0053d7ec
    //                              vw_dimap.cpp:233 (28)
    //         0053d7c6     MOV        this,dword ptr [ESP + param_2]
    //         0053d7ca     MOV        EDX,dword ptr [ESP + param_1]
    //         0053d7ce     MOV        EAX,dword ptr [ESI]
    //         0053d7d0     PUSH       this
    //         0053d7d1     PUSH       EDX
    //         0053d7d2     MOV        this,ESI
    //         0053d7d4     CALL       dword ptr [EAX + 0xf4]
    //         0053d7da     TEST       EAX,EAX
    //         0053d7dc     JZ         LAB_0053d889
    //                              vw_dimap.cpp:234 (5)
    //         0053d7e2     MOV        EAX,0x1
    //                              vw_dimap.cpp:261 (5)
    //         0053d7e7     POP        ESI
    //         0053d7e8     POP        this
    //         0053d7e9     RET        0x10
    //                               LAB_0053d7ec                                                 XREF[1]:     0053d7c4(j)  
    //                              vw_dimap.cpp:240 (36)
    //         0053d7ec     LEA        EAX=>local_4,[ESP + 0x4]
    //         0053d7f0     LEA        this=>param_2,[ESP + 0x10]
    //         0053d7f4     PUSH       EAX
    //         0053d7f5     MOV        EAX,dword ptr [ESP + param_2]
    //         0053d7f9     LEA        EDX=>param_1,[ESP + 0x10]
    //         0053d7fd     PUSH       this
    //         0053d7fe     MOV        this,dword ptr [ESP + param_1]
    //         0053d802     PUSH       EDX
    //         0053d803     PUSH       EAX
    //         0053d804     PUSH       this
    //         0053d805     MOV        this,ESI
    //         0053d807     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         0053d80c     TEST       EAX,EAX
    //         0053d80e     JZ         LAB_0053d851
    //                              vw_dimap.cpp:241 (65)
    //         0053d810     MOVSX      EAX,word ptr [ESP + param_2]
    //         0053d815     MOV        this,dword ptr [ESI + 0xf8]
    //         0053d81b     MOV        dword ptr [ESP + param_4],EAX
    //         0053d81f     FILD       dword ptr [ESP + param_4]
    //         0053d823     MOVSX      EAX,word ptr [ESP + param_1]
    //         0053d828     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053d82e     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053d830     PUSH       0x3f800000
    //         0053d835     PUSH       this
    //         0053d836     MOV        dword ptr [ESP + param_4],EAX
    //         0053d83a     FSTP       float ptr [ESP]=>local_10
    //         0053d83d     FILD       dword ptr [ESP + param_4]
    //         0053d841     PUSH       this
    //         0053d842     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053d848     FSTP       float ptr [ESP]=>local_14
    //         0053d84b     CALL       dword ptr [EDX + 0xd8]
    //                               LAB_0053d851                                                 XREF[1]:     0053d80e(j)  
    //                              vw_dimap.cpp:242 (5)
    //         0053d851     MOV        EAX,0x1
    //                              vw_dimap.cpp:261 (5)
    //         0053d856     POP        ESI
    //         0053d857     POP        this
    //         0053d858     RET        0x10
    //                               LAB_0053d85b                                                 XREF[1]:     0053d79d(j)  
    //                              vw_dimap.cpp:250 (9)
    //         0053d85b     CMP        dword ptr [this->field0_0x0 + 0x1b0],0x7
    //         0053d862     JZ         LAB_0053d889
    //                              vw_dimap.cpp:252 (10)
    //         0053d864     MOV        EAX,dword ptr [this->field0_0x0 + 0x1b4]
    //         0053d86a     TEST       EAX,EAX
    //         0053d86c     JZ         LAB_0053d87e
    //                              vw_dimap.cpp:253 (9)
    //         0053d86e     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053d870     PUSH       0x0
    //         0053d872     PUSH       0x0
    //         0053d874     CALL       dword ptr [EDX + 0x10]
    //                              vw_dimap.cpp:260 (2)
    //         0053d877     XOR        EAX,EAX
    //                              vw_dimap.cpp:261 (5)
    //         0053d879     POP        ESI
    //         0053d87a     POP        this
    //         0053d87b     RET        0x10
    //                               LAB_0053d87e                                                 XREF[1]:     0053d86c(j)  
    //                              vw_dimap.cpp:255 (11)
    //         0053d87e     MOV        this,dword ptr [ESI + 0xf8]
    //         0053d884     CALL       RGE_Player::unselect_object                      void unselect_object(RGE_Player * this)
    //                               LAB_0053d889                                                 XREF[7]:     0053d741(j), 0053d774(j), 
    //                                                                                                         0053d786(j), 0053d7ab(j), 
    //                                                                                                         0053d7b8(j), 0053d7dc(j), 
    //                                                                                                         0053d862(j)  
    //                              vw_dimap.cpp:260 (2)
    //         0053d889     XOR        EAX,EAX
    //                              vw_dimap.cpp:261 (5)
    //         0053d88b     POP        ESI
    //         0053d88c     POP        this
    //         0053d88d     RET        0x10
}

// Offset: 0x0053D890
void RGE_Diamond_Map_View::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall RGE_Diamond_Map_View::draw(void)                                      *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(RGE_Diamond_Map_View * this)
    //              void              <VOID>         <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //                               ?draw@RGE_Diamond_Map_View@@UAEXXZ                           XREF[2]:     00577380(*), 00577718(*)  
    //                               RGE_Diamond_Map_View::draw
    //                              vw_dimap.cpp:267 (2)
    //         0053d890     PUSH       ESI
    //         0053d891     PUSH       EDI
    //                              vw_dimap.cpp:270 (20)
    //         0053d892     PUSH       0x10e
    //         0053d897     MOV        ESI,this
    //         0053d899     PUSH       s_C:\msdev\work\age1_x1\vw_dimap.c               = "C:\\msdev\\work\\age1_x1\\vw_dimap.cpp"
    //         0053d89e     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0053d8a3     ADD        ESP,0x8
    //                              vw_dimap.cpp:272 (9)
    //         0053d8a6     MOV        this,ESI
    //         0053d8a8     MOV        EDI,EAX
    //         0053d8aa     CALL       RGE_Diamond_Map::draw                            void draw(RGE_Diamond_Map * this)
    //                              vw_dimap.cpp:274 (34)
    //         0053d8af     PUSH       0x112
    //         0053d8b4     PUSH       s_C:\msdev\work\age1_x1\vw_dimap.c               = "C:\\msdev\\work\\age1_x1\\vw_dimap.cpp"
    //         0053d8b9     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0053d8be     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d8c4     ADD        ESP,0x8
    //         0053d8c7     SUB        EAX,EDI
    //         0053d8c9     PUSH       EAX
    //         0053d8ca     PUSH       0x7
    //         0053d8cc     CALL       RGE_Base_Game::add_to_timing                     void add_to_timing(RGE_Base_Game * this, int 
    //                              vw_dimap.cpp:275 (3)
    //         0053d8d1     POP        EDI
    //         0053d8d2     POP        ESI
    //         0053d8d3     RET
}

// Offset: 0x0053D8E0
int RGE_Diamond_Map_View::command_make_do(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Diamond_Map_View::command_make_do(long,long)                       *
    //                              *********************************************************************************************************
    //                              int __thiscall command_make_do(RGE_Diamond_Map_View * this, long par
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     0053d906(*), 0053d90b(R), 0053d932(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     0053d8fd(*), 0053d902(R), 0053d91f(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053d8f8(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[4]:     0053d92a(W), 0053d92e(R), 0053d940(W), 0053d947(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0053d944(*)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0053d952(*)  
    //                               ?command_make_do@RGE_Diamond_Map_View@@UAEHJJ@Z              XREF[2]:     00577444(*), 005777dc(*)  
    //                               RGE_Diamond_Map_View::command_make_do
    //                              vw_dimap.cpp:281 (15)
    //         0053d8e0     MOV        EAX,[allow_user_commands]                        = 1h
    //         0053d8e5     SUB        ESP,0x8
    //         0053d8e8     TEST       EAX,EAX
    //         0053d8ea     PUSH       ESI
    //         0053d8eb     MOV        ESI,this
    //         0053d8ed     JNZ        LAB_0053d8f8
    //                              vw_dimap.cpp:287 (2)
    //         0053d8ef     XOR        EAX,EAX
    //                              vw_dimap.cpp:295 (7)
    //         0053d8f1     POP        ESI
    //         0053d8f2     ADD        ESP,0x8
    //         0053d8f5     RET        0x8
    //                               LAB_0053d8f8                                                 XREF[1]:     0053d8ed(j)  
    //                              vw_dimap.cpp:291 (39)
    //         0053d8f8     LEA        EAX=>local_4,[ESP + 0x8]
    //         0053d8fc     PUSH       EDI
    //         0053d8fd     LEA        this=>param_2,[ESP + 0x18]
    //         0053d901     PUSH       EAX
    //         0053d902     MOV        EAX,dword ptr [ESP + param_2]
    //         0053d906     LEA        EDX=>param_1,[ESP + 0x18]
    //         0053d90a     PUSH       this
    //         0053d90b     MOV        this,dword ptr [ESP + param_1]
    //         0053d90f     PUSH       EDX
    //         0053d910     PUSH       EAX
    //         0053d911     PUSH       this
    //         0053d912     MOV        this,ESI
    //         0053d914     XOR        EDI,EDI
    //         0053d916     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         0053d91b     TEST       EAX,EAX
    //         0053d91d     JZ         LAB_0053d963
    //                              vw_dimap.cpp:292 (68)
    //         0053d91f     MOVSX      EAX,word ptr [ESP + param_2]
    //         0053d924     MOV        this,dword ptr [ESI + 0xf8]
    //         0053d92a     MOV        dword ptr [ESP + tile],EAX
    //         0053d92e     FILD       dword ptr [ESP + tile]
    //         0053d932     MOVSX      EAX,word ptr [ESP + param_1]
    //         0053d937     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053d93d     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053d93f     PUSH       this
    //         0053d940     MOV        dword ptr [ESP + tile],EAX
    //         0053d944     FSTP       float ptr [ESP]=>local_14
    //         0053d947     FILD       dword ptr [ESP + tile]
    //         0053d94b     PUSH       this
    //         0053d94c     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053d952     FSTP       float ptr [ESP]=>local_18
    //         0053d955     PUSH       EDI
    //         0053d956     CALL       dword ptr [EDX + 0xa8]
    //         0053d95c     AND        EAX,0xff
    //         0053d961     MOV        EDI,EAX
    //                               LAB_0053d963                                                 XREF[1]:     0053d91d(j)  
    //                              vw_dimap.cpp:294 (3)
    //         0053d963     MOV        EAX,EDI
    //         0053d965     POP        EDI
    //                              vw_dimap.cpp:295 (7)
    //         0053d966     POP        ESI
    //         0053d967     ADD        ESP,0x8
    //         0053d96a     RET        0x8
}

// Offset: 0x0053D970
int RGE_Diamond_Map_View::command_make_move(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Diamond_Map_View::command_make_move(long,long)                     *
    //                              *********************************************************************************************************
    //                              int __thiscall command_make_move(RGE_Diamond_Map_View * this, long p
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     0053d996(*), 0053d99b(R), 0053d9c2(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     0053d98d(*), 0053d992(R), 0053d9af(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053d988(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[4]:     0053d9ba(W), 0053d9be(R), 0053d9d0(W), 0053d9d7(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0053d9d4(*)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0053d9e2(*)  
    //                               ?command_make_move@RGE_Diamond_Map_View@@UAEHJJ@Z            XREF[2]:     00577448(*), 005777e0(*)  
    //                               RGE_Diamond_Map_View::command_make_move
    //                              vw_dimap.cpp:301 (15)
    //         0053d970     MOV        EAX,[allow_user_commands]                        = 1h
    //         0053d975     SUB        ESP,0x8
    //         0053d978     TEST       EAX,EAX
    //         0053d97a     PUSH       EDI
    //         0053d97b     MOV        EDI,this
    //         0053d97d     JNZ        LAB_0053d988
    //                              vw_dimap.cpp:307 (2)
    //         0053d97f     XOR        EAX,EAX
    //                              vw_dimap.cpp:316 (7)
    //         0053d981     POP        EDI
    //         0053d982     ADD        ESP,0x8
    //         0053d985     RET        0x8
    //                               LAB_0053d988                                                 XREF[1]:     0053d97d(j)  
    //                              vw_dimap.cpp:311 (39)
    //         0053d988     LEA        EAX=>local_4,[ESP + 0x8]
    //         0053d98c     PUSH       ESI
    //         0053d98d     LEA        this=>param_2,[ESP + 0x18]
    //         0053d991     PUSH       EAX
    //         0053d992     MOV        EAX,dword ptr [ESP + param_2]
    //         0053d996     LEA        EDX=>param_1,[ESP + 0x18]
    //         0053d99a     PUSH       this
    //         0053d99b     MOV        this,dword ptr [ESP + param_1]
    //         0053d99f     PUSH       EDX
    //         0053d9a0     PUSH       EAX
    //         0053d9a1     PUSH       this
    //         0053d9a2     MOV        this,EDI
    //         0053d9a4     XOR        ESI,ESI
    //         0053d9a6     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         0053d9ab     TEST       EAX,EAX
    //         0053d9ad     JZ         LAB_0053d9f3
    //                              vw_dimap.cpp:312 (68)
    //         0053d9af     MOVSX      EAX,word ptr [ESP + param_2]
    //         0053d9b4     MOV        this,dword ptr [EDI + 0xf8]
    //         0053d9ba     MOV        dword ptr [ESP + tile],EAX
    //         0053d9be     FILD       dword ptr [ESP + tile]
    //         0053d9c2     MOVSX      EAX,word ptr [ESP + param_1]
    //         0053d9c7     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053d9cd     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053d9cf     PUSH       this
    //         0053d9d0     MOV        dword ptr [ESP + tile],EAX
    //         0053d9d4     FSTP       float ptr [ESP]=>local_14
    //         0053d9d7     FILD       dword ptr [ESP + tile]
    //         0053d9db     PUSH       this
    //         0053d9dc     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053d9e2     FSTP       float ptr [ESP]=>local_18
    //         0053d9e5     PUSH       ESI
    //         0053d9e6     CALL       dword ptr [EDX + 0xa0]
    //         0053d9ec     AND        EAX,0xff
    //         0053d9f1     MOV        ESI,EAX
    //                               LAB_0053d9f3                                                 XREF[1]:     0053d9ad(j)  
    //                              vw_dimap.cpp:314 (15)
    //         0053d9f3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053d9f9     PUSH       0x0
    //         0053d9fb     PUSH       0x0=>DAT_fffffff8
    //         0053d9fd     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053d9ff     CALL       dword ptr [EDX + 0x10]
    //                              vw_dimap.cpp:315 (3)
    //         0053da02     MOV        EAX,ESI
    //         0053da04     POP        ESI
    //                              vw_dimap.cpp:316 (7)
    //         0053da05     POP        EDI
    //         0053da06     ADD        ESP,0x8
    //         0053da09     RET        0x8
}

// Offset: 0x0053DA10
int RGE_Diamond_Map_View::command_make_work(long param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall RGE_Diamond_Map_View::command_make_work(long,long)                     *
    //                              *********************************************************************************************************
    //                              int __thiscall command_make_work(RGE_Diamond_Map_View * this, long p
    //              int               EAX:4          <RETURN>
    //              RGE_Diamond_Ma    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1                   XREF[3]:     0053da36(*), 0053da3b(R), 0053da62(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[3]:     0053da2d(*), 0053da32(R), 0053da4f(R)  
    //              undefined         Stack[-0x4]:1  local_4                   XREF[1]:     0053da28(*)  
    //              RGE_Tile *        Stack[-0x8]:4  tile                      XREF[4]:     0053da5a(W), 0053da5e(R), 0053da70(W), 0053da77(R)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[1]:     0053da74(*)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[1]:     0053da82(*)  
    //                               ?command_make_work@RGE_Diamond_Map_View@@UAEHJJ@Z            XREF[2]:     0057744c(*), 005777e4(*)  
    //                               RGE_Diamond_Map_View::command_make_work
    //                              vw_dimap.cpp:322 (15)
    //         0053da10     MOV        EAX,[allow_user_commands]                        = 1h
    //         0053da15     SUB        ESP,0x8
    //         0053da18     TEST       EAX,EAX
    //         0053da1a     PUSH       EDI
    //         0053da1b     MOV        EDI,this
    //         0053da1d     JNZ        LAB_0053da28
    //                              vw_dimap.cpp:328 (2)
    //         0053da1f     XOR        EAX,EAX
    //                              vw_dimap.cpp:337 (7)
    //         0053da21     POP        EDI
    //         0053da22     ADD        ESP,0x8
    //         0053da25     RET        0x8
    //                               LAB_0053da28                                                 XREF[1]:     0053da1d(j)  
    //                              vw_dimap.cpp:332 (39)
    //         0053da28     LEA        EAX=>local_4,[ESP + 0x8]
    //         0053da2c     PUSH       ESI
    //         0053da2d     LEA        this=>param_2,[ESP + 0x18]
    //         0053da31     PUSH       EAX
    //         0053da32     MOV        EAX,dword ptr [ESP + param_2]
    //         0053da36     LEA        EDX=>param_1,[ESP + 0x18]
    //         0053da3a     PUSH       this
    //         0053da3b     MOV        this,dword ptr [ESP + param_1]
    //         0053da3f     PUSH       EDX
    //         0053da40     PUSH       EAX
    //         0053da41     PUSH       this
    //         0053da42     MOV        this,EDI
    //         0053da44     XOR        ESI,ESI
    //         0053da46     CALL       RGE_Diamond_Map::pick_tile                       int pick_tile(RGE_Diamond_Map * this, long pa
    //         0053da4b     TEST       EAX,EAX
    //         0053da4d     JZ         LAB_0053da93
    //                              vw_dimap.cpp:333 (68)
    //         0053da4f     MOVSX      EAX,word ptr [ESP + param_2]
    //         0053da54     MOV        this,dword ptr [EDI + 0xf8]
    //         0053da5a     MOV        dword ptr [ESP + tile],EAX
    //         0053da5e     FILD       dword ptr [ESP + tile]
    //         0053da62     MOVSX      EAX,word ptr [ESP + param_1]
    //         0053da67     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053da6d     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053da6f     PUSH       this
    //         0053da70     MOV        dword ptr [ESP + tile],EAX
    //         0053da74     FSTP       float ptr [ESP]=>local_14
    //         0053da77     FILD       dword ptr [ESP + tile]
    //         0053da7b     PUSH       this
    //         0053da7c     FSUB       float ptr [DAT_005777e8]                         = align(3)
    //         0053da82     FSTP       float ptr [ESP]=>local_18
    //         0053da85     PUSH       ESI
    //         0053da86     CALL       dword ptr [EDX + 0xa4]
    //         0053da8c     AND        EAX,0xff
    //         0053da91     MOV        ESI,EAX
    //                               LAB_0053da93                                                 XREF[1]:     0053da4d(j)  
    //                              vw_dimap.cpp:335 (15)
    //         0053da93     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0053da99     PUSH       0x0
    //         0053da9b     PUSH       0x0=>DAT_fffffff8
    //         0053da9d     MOV        EDX,dword ptr [this->field0_0x0]
    //         0053da9f     CALL       dword ptr [EDX + 0x10]
    //                              vw_dimap.cpp:336 (3)
    //         0053daa2     MOV        EAX,ESI
    //         0053daa4     POP        ESI
    //                              vw_dimap.cpp:337 (7)
    //         0053daa5     POP        EDI
    //         0053daa6     ADD        ESP,0x8
    //         0053daa9     RET        0x8
}

