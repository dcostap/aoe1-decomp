// Auto-generated scaffold unit: tpnl_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/tpnl_obj.cpp
#include "../include/common.h"

// Offset: 0x0051ADF0
undefined TRIBE_Panel_Object(TRIBE_Panel_Object* this_, TDrawArea* param_2, TPanel* param_3, void* param_4, long param_5, long param_6, TShape* param_7, TShape** param_8, TRIBE_Player* param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Panel_Object::TRIBE_Panel_Object(class TDrawArea *,class TPanel *,void *,... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Panel_Object(TRIBE_Panel_Object * this, T
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0051af33(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     0051ae42(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[3]:     0051ae14(R), 0051af6e(W), 0051afd3(W)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     0051ae18(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     0051ae1c(R)  
    //              TShape *          Stack[0x18]:4  param_6                   XREF[1]:     0051ae2c(R)  
    //              TShape * *        Stack[0x1c]:4  param_7                   XREF[1]:     0051ae38(R)  
    //              TRIBE_Player *    Stack[0x20]:4  param_8                   XREF[1]:     0051af58(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0051af3c(W), 0051af74(W), 0051af92(W), 0051afd9(W), 
    //                                                                                     0051aff7(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051b02e(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051ae0b(W)  
    //                               ??0TRIBE_Panel_Object@@QAE@PAVTDrawArea@@PAVTPanel@@PAXJJPA  XREF[2]:     TRIBE_Screen_Game:004944cc(c), 
    //                               TRIBE_Panel_Object::TRIBE_Panel_Object                                    TRIBE_Scenario_Editor_Panel_Object
    //                              tpnl_obj.cpp:49 (36)
    //         0051adf0     PUSH       -0x1
    //         0051adf2     PUSH       FUN_0056136e
    //         0051adf7     MOV        EAX,FS:[0x0]
    //         0051adfd     PUSH       EAX
    //         0051adfe     MOV        dword ptr FS:[0x0],ESP
    //         0051ae05     PUSH       this
    //         0051ae06     PUSH       EBX
    //         0051ae07     PUSH       ESI
    //         0051ae08     MOV        ESI,this
    //         0051ae0a     PUSH       EDI
    //         0051ae0b     MOV        dword ptr [ESP + local_10],ESI
    //         0051ae0f     CALL       TPanel::TPanel                                   undefined TPanel(TPanel * this)
    //                              tpnl_obj.cpp:50 (4)
    //         0051ae14     MOV        EAX,dword ptr [ESP + param_3]
    //                              tpnl_obj.cpp:51 (4)
    //         0051ae18     MOV        this,dword ptr [ESP + param_4]
    //                              tpnl_obj.cpp:52 (16)
    //         0051ae1c     MOV        EDX,dword ptr [ESP + param_5]
    //         0051ae20     MOV        dword ptr [ESI],TRIBE_Panel_Object::`vftable'    = 0051b050
    //         0051ae26     MOV        dword ptr [ESI + 0xf4],EAX
    //                              tpnl_obj.cpp:56 (12)
    //         0051ae2c     MOV        EAX,dword ptr [ESP + param_6]
    //         0051ae30     XOR        EBX,EBX
    //         0051ae32     MOV        dword ptr [ESI + 0xf8],this
    //                              tpnl_obj.cpp:57 (10)
    //         0051ae38     MOV        this,dword ptr [ESP + param_7]
    //         0051ae3c     MOV        dword ptr [ESI + 0xfc],EDX
    //                              tpnl_obj.cpp:95 (263)
    //         0051ae42     MOV        EDX,dword ptr [ESP + param_2]
    //         0051ae46     MOV        dword ptr [ESI + 0x100],EBX
    //         0051ae4c     MOV        dword ptr [ESI + 0x104],EBX
    //         0051ae52     MOV        dword ptr [ESI + 0x108],EAX
    //         0051ae58     MOV        dword ptr [ESI + 0x10c],this
    //         0051ae5e     PUSH       EBX
    //         0051ae5f     LEA        EDI,[ESI + 0x1ec]
    //         0051ae65     MOV        this,0x9
    //         0051ae6a     XOR        EAX,EAX
    //         0051ae6c     PUSH       EBX
    //         0051ae6d     MOV        dword ptr [ESI + 0x110],EBX
    //         0051ae73     MOV        dword ptr [ESI + 0x114],EBX
    //         0051ae79     MOV        dword ptr [ESI + 0x118],EBX
    //         0051ae7f     MOV        dword ptr [ESI + 0x11c],0x1f4
    //         0051ae89     MOV        byte ptr [ESI + 0x120],0x1
    //         0051ae90     MOV        dword ptr [ESI + 0x124],EBX
    //         0051ae96     MOV        word ptr [ESI + 0x12c],0xffff
    //         0051ae9f     MOV        dword ptr [ESI + 0x130],EBX
    //         0051aea5     MOV        byte ptr [ESI + 0x134],BL
    //         0051aeab     MOV        dword ptr [ESI + 0x138],EBX
    //         0051aeb1     MOV        dword ptr [ESI + 0x13c],EBX
    //         0051aeb7     MOV        dword ptr [ESI + 0x14c],EBX
    //         0051aebd     MOV        word ptr [ESI + 0x150],BX
    //         0051aec4     MOV        word ptr [ESI + 0x152],BX
    //         0051aecb     MOV        word ptr [ESI + 0x154],BX
    //         0051aed2     MOV        dword ptr [ESI + 0x158],EBX
    //         0051aed8     MOV        dword ptr [ESI + 0x15c],EBX
    //         0051aede     MOV        word ptr [ESI + 0x160],BX
    //         0051aee5     MOV        word ptr [ESI + 0x162],BX
    //         0051aeec     MOV        word ptr [ESI + 0x164],BX
    //         0051aef3     MOV        byte ptr [ESI + 0x166],BL
    //         0051aef9     MOV        byte ptr [ESI + 0x1ca],BL
    //         0051aeff     MOV        dword ptr [ESI + 0x1cc],EBX
    //         0051af05     MOV        dword ptr [ESI + 0x1d0],EBX
    //         0051af0b     MOV        dword ptr [ESI + 0x1d4],EBX
    //         0051af11     MOV        dword ptr [ESI + 0x1d8],EBX
    //         0051af17     MOV        byte ptr [ESI + 0x1dc],BL
    //         0051af1d     MOV        dword ptr [ESI + 0x1e0],EBX
    //         0051af23     MOV        byte ptr [ESI + 0x1e8],BL
    //         0051af29     MOV        dword ptr [ESI + 0x210],EBX
    //         0051af2f     PUSH       EBX
    //         0051af30     PUSH       EBX
    //         0051af31     STOSD.REP  ES:EDI
    //         0051af33     MOV        EAX,dword ptr [ESP + param_1]
    //         0051af37     PUSH       EBX
    //         0051af38     PUSH       EDX
    //         0051af39     PUSH       EAX
    //         0051af3a     MOV        this,ESI
    //         0051af3c     MOV        dword ptr [ESP + local_4],EBX
    //         0051af40     CALL       TPanel::setup                                    long setup(TPanel * this, TDrawArea * param_1
    //         0051af45     TEST       EAX,EAX
    //         0051af47     JNZ        LAB_0051af58
    //                              tpnl_obj.cpp:97 (10)
    //         0051af49     MOV        dword ptr [ESI + 0xd8],0x1
    //                              tpnl_obj.cpp:98 (5)
    //         0051af53     JMP        LAB_0051b02e
    //                               LAB_0051af58                                                 XREF[1]:     0051af47(j)  
    //                              tpnl_obj.cpp:101 (12)
    //         0051af58     MOV        this,dword ptr [ESP + param_8]
    //         0051af5c     PUSH       this
    //         0051af5d     MOV        this,ESI
    //         0051af5f     CALL       TRIBE_Panel_Object::set_player                   void set_player(TRIBE_Panel_Object * this, TR
    //                              tpnl_obj.cpp:103 (44)
    //         0051af64     PUSH       0x20
    //         0051af66     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0051af6b     ADD        ESP,0x4
    //         0051af6e     MOV        dword ptr [ESP + param_3],EAX
    //         0051af72     CMP        EAX,EBX
    //         0051af74     MOV        byte ptr [ESP + local_4],0x1
    //         0051af79     JZ         LAB_0051af8e
    //         0051af7b     PUSH       0xc639
    //         0051af80     PUSH       s_health.shp                                     = "health.shp"
    //         0051af85     MOV        this,EAX
    //         0051af87     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0051af8c     JMP        LAB_0051af90
    //                               LAB_0051af8e                                                 XREF[1]:     0051af79(j)  
    //         0051af8e     XOR        EAX,EAX
    //                               LAB_0051af90                                                 XREF[1]:     0051af8c(j)  
    //                              tpnl_obj.cpp:104 (25)
    //         0051af90     CMP        EAX,EBX
    //         0051af92     MOV        byte ptr [ESP + local_4],BL
    //         0051af96     MOV        dword ptr [ESI + 0x100],EAX
    //         0051af9c     JZ         LAB_0051afc9
    //         0051af9e     MOV        this,EAX
    //         0051afa0     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0051afa5     TEST       EAX,EAX
    //         0051afa7     JNZ        LAB_0051afc9
    //                              tpnl_obj.cpp:106 (26)
    //         0051afa9     MOV        EDI,dword ptr [ESI + 0x100]
    //         0051afaf     CMP        EDI,EBX
    //         0051afb1     JZ         LAB_0051afc3
    //         0051afb3     MOV        this,EDI
    //         0051afb5     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051afba     PUSH       EDI
    //         0051afbb     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051afc0     ADD        ESP,0x4
    //                               LAB_0051afc3                                                 XREF[1]:     0051afb1(j)  
    //                              tpnl_obj.cpp:107 (6)
    //         0051afc3     MOV        dword ptr [ESI + 0x100],EBX
    //                               LAB_0051afc9                                                 XREF[2]:     0051af9c(j), 0051afa7(j)  
    //                              tpnl_obj.cpp:110 (44)
    //         0051afc9     PUSH       0x20
    //         0051afcb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0051afd0     ADD        ESP,0x4
    //         0051afd3     MOV        dword ptr [ESP + param_3],EAX
    //         0051afd7     CMP        EAX,EBX
    //         0051afd9     MOV        byte ptr [ESP + local_4],0x2
    //         0051afde     JZ         LAB_0051aff3
    //         0051afe0     PUSH       0xc62b
    //         0051afe5     PUSH       s_itemicon.shp                                   = "itemicon.shp"
    //         0051afea     MOV        this,EAX
    //         0051afec     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0051aff1     JMP        LAB_0051aff5
    //                               LAB_0051aff3                                                 XREF[1]:     0051afde(j)  
    //         0051aff3     XOR        EAX,EAX
    //                               LAB_0051aff5                                                 XREF[1]:     0051aff1(j)  
    //                              tpnl_obj.cpp:111 (25)
    //         0051aff5     CMP        EAX,EBX
    //         0051aff7     MOV        byte ptr [ESP + local_4],BL
    //         0051affb     MOV        dword ptr [ESI + 0x104],EAX
    //         0051b001     JZ         LAB_0051b02e
    //         0051b003     MOV        this,EAX
    //         0051b005     CALL       TShape::is_loaded                                int is_loaded(TShape * this)
    //         0051b00a     TEST       EAX,EAX
    //         0051b00c     JNZ        LAB_0051b02e
    //                              tpnl_obj.cpp:113 (26)
    //         0051b00e     MOV        EDI,dword ptr [ESI + 0x104]
    //         0051b014     CMP        EDI,EBX
    //         0051b016     JZ         LAB_0051b028
    //         0051b018     MOV        this,EDI
    //         0051b01a     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051b01f     PUSH       EDI
    //         0051b020     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051b025     ADD        ESP,0x4
    //                               LAB_0051b028                                                 XREF[1]:     0051b016(j)  
    //                              tpnl_obj.cpp:114 (6)
    //         0051b028     MOV        dword ptr [ESI + 0x104],EBX
    //                               LAB_0051b02e                                                 XREF[3]:     0051af53(j), 0051b001(j), 
    //                                                                                                         0051b00c(j)  
    //                              tpnl_obj.cpp:116 (22)
    //         0051b02e     MOV        this,dword ptr [ESP + local_c]
    //         0051b032     MOV        EAX,ESI
    //         0051b034     POP        EDI
    //         0051b035     POP        ESI
    //         0051b036     MOV        dword ptr FS:[0x0],this
    //         0051b03d     POP        EBX
    //         0051b03e     ADD        ESP,0x10
    //         0051b041     RET        0x20
}

// Offset: 0x0051B070
void TRIBE_Panel_Object(TRIBE_Panel_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Panel_Object::~TRIBE_Panel_Object(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Panel_Object(TRIBE_Panel_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0051b09a(W), 0051b0e6(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0051b0f3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0051b08a(W)  
    //                               ??1TRIBE_Panel_Object@@UAE@XZ                                XREF[2]:     ~TRIBE_Scenario_Editor_Panel_Objec
    //                               TRIBE_Panel_Object::~TRIBE_Panel_Object                                   `scalar_deleting_destructor':0051b
    //                              tpnl_obj.cpp:122 (36)
    //         0051b070     PUSH       -0x1
    //         0051b072     PUSH       FUN_00561388
    //         0051b077     MOV        EAX,FS:[0x0]
    //         0051b07d     PUSH       EAX
    //         0051b07e     MOV        dword ptr FS:[0x0],ESP
    //         0051b085     PUSH       this
    //         0051b086     PUSH       ESI
    //         0051b087     MOV        ESI,this
    //         0051b089     PUSH       EDI
    //         0051b08a     MOV        dword ptr [ESP + local_10],ESI
    //         0051b08e     MOV        dword ptr [ESI],TRIBE_Panel_Object::`vftable'    = 0051b050
    //                              tpnl_obj.cpp:123 (18)
    //         0051b094     MOV        EDI,dword ptr [ESI + 0x100]
    //         0051b09a     MOV        dword ptr [ESP + local_4],0x0
    //         0051b0a2     TEST       EDI,EDI
    //         0051b0a4     JZ         LAB_0051b0c0
    //                              tpnl_obj.cpp:125 (16)
    //         0051b0a6     MOV        this,EDI
    //         0051b0a8     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051b0ad     PUSH       EDI
    //         0051b0ae     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051b0b3     ADD        ESP,0x4
    //                              tpnl_obj.cpp:126 (10)
    //         0051b0b6     MOV        dword ptr [ESI + 0x100],0x0
    //                               LAB_0051b0c0                                                 XREF[1]:     0051b0a4(j)  
    //                              tpnl_obj.cpp:129 (10)
    //         0051b0c0     MOV        EDI,dword ptr [ESI + 0x104]
    //         0051b0c6     TEST       EDI,EDI
    //         0051b0c8     JZ         LAB_0051b0e4
    //                              tpnl_obj.cpp:131 (16)
    //         0051b0ca     MOV        this,EDI
    //         0051b0cc     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0051b0d1     PUSH       EDI
    //         0051b0d2     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0051b0d7     ADD        ESP,0x4
    //                              tpnl_obj.cpp:132 (12)
    //         0051b0da     MOV        dword ptr [ESI + 0x104],0x0
    //                               LAB_0051b0e4                                                 XREF[1]:     0051b0c8(j)  
    //         0051b0e4     MOV        this,ESI
    //                              tpnl_obj.cpp:134 (30)
    //         0051b0e6     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0051b0ee     CALL       TPanel::~TPanel                                  void ~TPanel(TPanel * this)
    //         0051b0f3     MOV        this,dword ptr [ESP + local_c]
    //         0051b0f7     POP        EDI
    //         0051b0f8     MOV        dword ptr FS:[0x0],this
    //         0051b0ff     POP        ESI
    //         0051b100     ADD        ESP,0x10
    //         0051b103     RET
}

// Offset: 0x0051B110
void set_player(TRIBE_Panel_Object* this_, TRIBE_Player* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Panel_Object::set_player(class TRIBE_Player *)                          *
    //                              *********************************************************************************************************
    //                              void __thiscall set_player(TRIBE_Panel_Object * this, TRIBE_Player *
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              TRIBE_Player *    Stack[0x4]:4   param_1                   XREF[1]:     0051b110(R)  
    //                               ?set_player@TRIBE_Panel_Object@@QAEXPAVTRIBE_Player@@@Z      XREF[2]:     player_changed:00498aa9(c), 
    //                               TRIBE_Panel_Object::set_player                                            TRIBE_Panel_Object:0051af5f(c)  
    //                              tpnl_obj.cpp:140 (4)
    //         0051b110     MOV        EAX,dword ptr [ESP + param_1]
    //                              tpnl_obj.cpp:142 (10)
    //         0051b114     TEST       EAX,EAX
    //         0051b116     MOV        dword ptr [ECX + this->player],EAX
    //         0051b11c     JZ         LAB_0051b12d
    //                              tpnl_obj.cpp:143 (7)
    //         0051b11e     MOV        EAX,dword ptr [EAX + 0x130]
    //         0051b124     PUSH       EAX
    //                              tpnl_obj.cpp:145 (5)
    //         0051b125     CALL       TRIBE_Panel_Object::set_object                   void set_object(TRIBE_Panel_Object * this, RG
    //                              tpnl_obj.cpp:146 (3)
    //         0051b12a     RET        0x4
    //                               LAB_0051b12d                                                 XREF[1]:     0051b11c(j)  
    //                              tpnl_obj.cpp:145 (7)
    //         0051b12d     PUSH       0x0
    //         0051b12f     CALL       TRIBE_Panel_Object::set_object                   void set_object(TRIBE_Panel_Object * this, RG
    //                              tpnl_obj.cpp:146 (3)
    //         0051b134     RET        0x4
}

// Offset: 0x0051B140
void set_object(TRIBE_Panel_Object* this_, RGE_Static_Object* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Panel_Object::set_object(class RGE_Static_Object *)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall set_object(TRIBE_Panel_Object * this, RGE_Static_Obj
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              RGE_Static_Obj    Stack[0x4]:4   param_1                   XREF[1]:     0051b140(R)  
    //                               ?set_object@TRIBE_Panel_Object@@QAEXPAVRGE_Static_Object@@@Z XREF[5]:     handle_game_update:00496b38(c), 
    //                               TRIBE_Panel_Object::set_object                                            set_player:0051b125(c), 
    //                                                                                                         set_player:0051b12f(c), 
    //                                                                                                         handle_idle:0051c4fc(c), 
    //                                                                                                         handle_idle:0051c512(c)  
    //                              tpnl_obj.cpp:152 (13)
    //         0051b140     MOV        EAX,dword ptr [ESP + param_1]
    //         0051b144     PUSH       ESI
    //         0051b145     MOV        ESI,this
    //         0051b147     MOV        dword ptr [ESI + 0x114],EAX
    //                              tpnl_obj.cpp:165 (5)
    //         0051b14d     CALL       TRIBE_Panel_Object::save_object_info             void save_object_info(TRIBE_Panel_Object * th
    //                              tpnl_obj.cpp:166 (9)
    //         0051b152     MOV        EDX,dword ptr [ESI]
    //         0051b154     PUSH       0x1
    //         0051b156     MOV        this,ESI
    //         0051b158     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_obj.cpp:167 (4)
    //         0051b15b     POP        ESI
    //         0051b15c     RET        0x4
}

// Offset: 0x0051B160
void set_mode(TRIBE_Panel_Object* this_, uchar param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Panel_Object::set_mode(unsigned char)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall set_mode(TRIBE_Panel_Object * this, uchar param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     0051b160(R)  
    //                               ?set_mode@TRIBE_Panel_Object@@QAEXE@Z
    //                               TRIBE_Panel_Object::set_mode
    //                              tpnl_obj.cpp:175 (13)
    //         0051b160     MOV        AL,byte ptr [ESP + param_1]
    //         0051b164     PUSH       ESI
    //         0051b165     MOV        ESI,this
    //         0051b167     MOV        byte ptr [ESI + 0x120],AL
    //                              tpnl_obj.cpp:177 (5)
    //         0051b16d     CALL       TRIBE_Panel_Object::save_object_info             void save_object_info(TRIBE_Panel_Object * th
    //                              tpnl_obj.cpp:178 (9)
    //         0051b172     MOV        EDX,dword ptr [ESI]
    //         0051b174     PUSH       0x1
    //         0051b176     MOV        this,ESI
    //         0051b178     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_obj.cpp:179 (4)
    //         0051b17b     POP        ESI
    //         0051b17c     RET        0x4
}

// Offset: 0x0051B180
uchar get_mode(TRIBE_Panel_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: unsigned char __thiscall TRIBE_Panel_Object::get_mode(void)                                   *
    //                              *********************************************************************************************************
    //                              uchar __thiscall get_mode(TRIBE_Panel_Object * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //                               ?get_mode@TRIBE_Panel_Object@@QAEEXZ
    //                               TRIBE_Panel_Object::get_mode
    //                              tpnl_obj.cpp:185 (6)
    //         0051b180     MOV        AL,byte ptr [ECX + this->mode]
    //                              tpnl_obj.cpp:187 (1)
    //         0051b186     RET
}

// Offset: 0x0051B190
void TRIBE_Panel_Object::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Panel_Object::draw(void)                                        *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TRIBE_Panel_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              char[100]         Stack[-0x68]   work_name
    //              char[100]         Stack[-0xcc]   str
    //              char[100]         Stack[-0x130   name
    //              short             Stack[-0x134   temp
    //              float             Stack[-0x138   orig_fval
    //              short             Stack[-0x13a   work_target
    //              short             Stack[-0x140   progress
    //              float             Stack[-0x144   cur_fval
    //              TRIBE_Building    Stack[-0x148   bldg_obj
    //              short             Stack[-0x14c   work_type
    //              float             Stack[-0x150   dx                        XREF[1]:     0051b202(W)  
    //              short             Stack[-0x156   orig_val
    //              short             Stack[-0x15c   cur_val
    //                               ?draw@TRIBE_Panel_Object@@UAEXXZ                             XREF[1]:     00576cc8(*)  
    //                               TRIBE_Panel_Object::draw
    //                              tpnl_obj.cpp:193 (11)
    //         0051b190     SUB        ESP,0x158
    //         0051b196     PUSH       EBX
    //         0051b197     PUSH       EBP
    //         0051b198     MOV        EBP,this
    //         0051b19a     PUSH       ESI
    //                              tpnl_obj.cpp:217 (30)
    //         0051b19b     XOR        ESI,ESI
    //         0051b19d     PUSH       EDI
    //         0051b19e     CMP        dword ptr [EBP + 0x20],ESI
    //         0051b1a1     JZ         LAB_0051be7b
    //         0051b1a7     CMP        dword ptr [EBP + 0x70],ESI
    //         0051b1aa     JZ         LAB_0051be7b
    //         0051b1b0     CMP        dword ptr [EBP + 0x6c],ESI
    //         0051b1b3     JZ         LAB_0051be7b
    //                              tpnl_obj.cpp:223 (9)
    //         0051b1b9     CMP        byte ptr [EBP + 0x120],0x2
    //         0051b1c0     JNZ        LAB_0051b1d2
    //                              tpnl_obj.cpp:225 (5)
    //         0051b1c2     CALL       TRIBE_Panel_Object::draw_score                   void draw_score(TRIBE_Panel_Object * this)
    //                              tpnl_obj.cpp:735 (11)
    //         0051b1c7     POP        EDI
    //         0051b1c8     POP        ESI
    //         0051b1c9     POP        EBP
    //         0051b1ca     POP        EBX
    //         0051b1cb     ADD        ESP,0x158
    //         0051b1d1     RET
    //                               LAB_0051b1d2                                                 XREF[1]:     0051b1c0(j)  
    //                              tpnl_obj.cpp:229 (8)
    //         0051b1d2     CMP        dword ptr [EBP + 0x114],ESI
    //         0051b1d8     JNZ        LAB_0051b1fc
    //                              tpnl_obj.cpp:231 (11)
    //         0051b1da     MOV        this,dword ptr [EBP + 0x40]
    //         0051b1dd     CMP        this,ESI
    //         0051b1df     JZ         LAB_0051be7b
    //                              tpnl_obj.cpp:232 (12)
    //         0051b1e5     MOV        EAX,dword ptr [this->_padding_]
    //         0051b1e7     LEA        EDX,[EBP + 0x24]
    //         0051b1ea     PUSH       EDX
    //         0051b1eb     CALL       dword ptr [EAX + 0x34]
    //         0051b1ee     MOV        dword ptr [EBP + 0x38],ESI
    //                              tpnl_obj.cpp:735 (11)
    //         0051b1f1     POP        EDI
    //         0051b1f2     POP        ESI
    //         0051b1f3     POP        EBP
    //         0051b1f4     POP        EBX
    //         0051b1f5     ADD        ESP,0x158
    //         0051b1fb     RET
    //                               LAB_0051b1fc                                                 XREF[1]:     0051b1d8(j)  
    //                              tpnl_obj.cpp:237 (13)
    //         0051b1fc     MOV        EBX,dword ptr [EBP]
    //         0051b1ff     PUSH       ESI
    //         0051b200     MOV        this,EBP
    //         0051b202     MOV        dword ptr [ESP + dx],EBX
    //         0051b206     CALL       dword ptr [EBX + 0x28]
    //                              tpnl_obj.cpp:239 (13)
    //         0051b209     MOV        this,dword ptr [EBP + 0x20]
    //         0051b20c     LEA        EAX,[EBP + 0x24]
    //         0051b20f     PUSH       ESI
    //         0051b210     PUSH       EAX=>DAT_fffffff8
    //         0051b211     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              tpnl_obj.cpp:241 (23)
    //         0051b216     MOV        this,dword ptr [EBP + 0x20]
    //         0051b219     PUSH       0x1
    //         0051b21b     PUSH       s_tpnl_obj::draw                                 = "tpnl_obj::draw"
    //         0051b220     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0051b225     TEST       EAX,EAX
    //         0051b227     JZ         LAB_0051b3ae
    //                              tpnl_obj.cpp:246 (13)
    //         0051b22d     MOV        this,dword ptr [EBP + 0x114]
    //         0051b233     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051b236     MOV        SI,word ptr [EAX + 0x4c]
    //                              tpnl_obj.cpp:247 (10)
    //         0051b23a     CMP        SI,-0x1
    //         0051b23e     JZ         LAB_0051b2e7
    //                              tpnl_obj.cpp:249 (9)
    //         0051b244     CMP        byte ptr [EAX + 0x8f],0x2
    //         0051b24b     JNZ        LAB_0051b275
    //                              tpnl_obj.cpp:251 (12)
    //         0051b24d     MOV        DL,byte ptr [ECX + this->save_age]
    //         0051b253     MOV        EDI,dword ptr [EBP + 0x10c]
    //                              tpnl_obj.cpp:252 (26)
    //         0051b259     MOV        AX,word ptr [EAX + 0x16e]
    //         0051b260     MOV        byte ptr [ESP + 0x1c],DL
    //         0051b264     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051b268     AND        EDX,0xff
    //         0051b26e     ADD        ESI,EAX
    //         0051b270     MOV        EDI,dword ptr [EDI + EDX*0x4]
    //                              tpnl_obj.cpp:254 (2)
    //         0051b273     JMP        LAB_0051b27b
    //                               LAB_0051b275                                                 XREF[1]:     0051b24b(j)  
    //                              tpnl_obj.cpp:255 (6)
    //         0051b275     MOV        EDI,dword ptr [EBP + 0x108]
    //                               LAB_0051b27b                                                 XREF[1]:     0051b273(j)  
    //                              tpnl_obj.cpp:256 (13)
    //         0051b27b     MOV        this,dword ptr [ECX + this->_padding_]
    //         0051b27e     MOV        EAX,dword ptr [ECX + this->unit_pics]
    //         0051b284     TEST       EAX,EAX
    //         0051b286     JZ         LAB_0051b2c6
    //                              tpnl_obj.cpp:258 (14)
    //         0051b288     MOVSX      EDX,word ptr [EAX + 0x26]
    //         0051b28c     INC        EDX
    //         0051b28d     SHL        EDX,0x4
    //         0051b290     PUSH       EDX
    //         0051b291     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
    //                              tpnl_obj.cpp:259 (46)
    //         0051b296     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051b29c     ADD        ESP,0x4
    //         0051b29f     MOV        this,dword ptr [EAX + 0xc]
    //         0051b2a2     MOVSX      EAX,SI
    //         0051b2a5     MOV        EDX,dword ptr [ECX + this->unit_pics]
    //         0051b2ab     MOV        this,dword ptr [EBP + 0x10]
    //         0051b2ae     ADD        EDX,0x28
    //         0051b2b1     ADD        this,0x1e
    //         0051b2b4     PUSH       EDX
    //         0051b2b5     MOV        EDX,dword ptr [EBP + 0xc]
    //         0051b2b8     PUSH       offset DAT_fffffff8
    //         0051b2ba     PUSH       EAX=>DAT_fffffff4
    //         0051b2bb     MOV        EAX,dword ptr [EBP + 0x20]
    //         0051b2be     ADD        EDX,0x3
    //         0051b2c1     PUSH       this=>DAT_fffffff0
    //         0051b2c2     PUSH       EDX
    //         0051b2c3     PUSH       EAX
    //                              tpnl_obj.cpp:261 (2)
    //         0051b2c4     JMP        LAB_0051b2e0
    //                               LAB_0051b2c6                                                 XREF[1]:     0051b286(j)  
    //                              tpnl_obj.cpp:262 (33)
    //         0051b2c6     MOV        EDX,dword ptr [EBP + 0x10]
    //         0051b2c9     MOV        EAX,dword ptr [EBP + 0xc]
    //         0051b2cc     MOVSX      this,SI
    //         0051b2cf     PUSH       0x0
    //         0051b2d1     PUSH       0x0=>DAT_fffffff8
    //         0051b2d3     ADD        EDX,0x1e
    //         0051b2d6     PUSH       this=>DAT_fffffff4
    //         0051b2d7     MOV        this,dword ptr [EBP + 0x20]
    //         0051b2da     ADD        EAX,0x3
    //         0051b2dd     PUSH       EDX=>DAT_fffffff0
    //         0051b2de     PUSH       EAX
    //         0051b2df     PUSH       this
    //                               LAB_0051b2e0                                                 XREF[1]:     0051b2c4(j)  
    //         0051b2e0     MOV        this,EDI
    //         0051b2e2     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_0051b2e7                                                 XREF[1]:     0051b23e(j)  
    //                              tpnl_obj.cpp:271 (40)
    //         0051b2e7     MOV        EDX,dword ptr [EBP + 0x114]
    //         0051b2ed     FLD        float ptr [EDX + 0x30]
    //         0051b2f0     FCOMP      float ptr [null_00576d80]                        = align(7)
    //         0051b2f6     FNSTSW     AX
    //         0051b2f8     TEST       AH,0x41
    //         0051b2fb     JNZ        LAB_0051b3a1
    //         0051b301     MOV        this,dword ptr [EBP + 0x100]
    //         0051b307     TEST       this,this
    //         0051b309     JZ         LAB_0051b3a1
    //                              tpnl_obj.cpp:273 (67)
    //         0051b30f     MOV        ESI,EDX
    //         0051b311     CALL       TShape::shape_count                              long shape_count(TShape * this)
    //         0051b316     MOV        this,dword ptr [EBP + 0x100]
    //         0051b31c     MOV        dword ptr [ESP + 0x1c],EAX
    //         0051b320     FILD       dword ptr [ESP + 0x1c]
    //         0051b324     FSTP       float ptr [ESP + 0x24]
    //         0051b328     CALL       TShape::shape_count                              long shape_count(TShape * this)
    //         0051b32d     MOV        dword ptr [ESP + 0x1c],EAX
    //         0051b331     MOV        EAX,dword ptr [ESI + 0x8]
    //         0051b334     FILD       dword ptr [ESP + 0x1c]
    //         0051b338     MOVSX      this,word ptr [EAX + 0x26]
    //         0051b33c     FMUL       float ptr [ESI + 0x30]
    //         0051b33f     MOV        dword ptr [ESP + 0x1c],this
    //         0051b343     FIDIV      dword ptr [ESP + 0x1c]
    //         0051b347     FSUBR      float ptr [ESP + 0x24]
    //         0051b34b     CALL       __ftol                                           undefined __ftol()
    //         0051b350     MOV        ESI,EAX
    //                              tpnl_obj.cpp:274 (5)
    //         0051b352     TEST       SI,SI
    //         0051b355     JGE        LAB_0051b35b
    //                              tpnl_obj.cpp:275 (2)
    //         0051b357     XOR        ESI,ESI
    //                              tpnl_obj.cpp:276 (21)
    //         0051b359     JMP        LAB_0051b37c
    //                               LAB_0051b35b                                                 XREF[1]:     0051b355(j)  
    //         0051b35b     MOV        this,dword ptr [EBP + 0x100]
    //         0051b361     CALL       TShape::shape_count                              long shape_count(TShape * this)
    //         0051b366     MOVSX      EDX,SI
    //         0051b369     DEC        EAX
    //         0051b36a     CMP        EDX,EAX
    //         0051b36c     JLE        LAB_0051b37c
    //                              tpnl_obj.cpp:277 (14)
    //         0051b36e     MOV        this,dword ptr [EBP + 0x100]
    //         0051b374     CALL       TShape::shape_count                              long shape_count(TShape * this)
    //         0051b379     MOV        ESI,EAX
    //         0051b37b     DEC        ESI
    //                               LAB_0051b37c                                                 XREF[2]:     0051b359(j), 0051b36c(j)  
    //                              tpnl_obj.cpp:278 (37)
    //         0051b37c     MOV        this,dword ptr [EBP + 0x10]
    //         0051b37f     MOV        EDX,dword ptr [EBP + 0xc]
    //         0051b382     MOVSX      EAX,SI
    //         0051b385     PUSH       0x0
    //         0051b387     PUSH       0x0=>DAT_fffffff8
    //         0051b389     ADD        this,0x54
    //         0051b38c     PUSH       EAX=>DAT_fffffff4
    //         0051b38d     MOV        EAX,dword ptr [EBP + 0x20]
    //         0051b390     ADD        EDX,0x3
    //         0051b393     PUSH       this=>DAT_fffffff0
    //         0051b394     MOV        this,dword ptr [EBP + 0x100]
    //         0051b39a     PUSH       EDX
    //         0051b39b     PUSH       EAX
    //         0051b39c     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_0051b3a1                                                 XREF[2]:     0051b2fb(j), 0051b309(j)  
    //                              tpnl_obj.cpp:281 (13)
    //         0051b3a1     MOV        this,dword ptr [EBP + 0x20]
    //         0051b3a4     PUSH       s_tpnl_obj::draw                                 = "tpnl_obj::draw"
    //         0051b3a9     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0051b3ae                                                 XREF[1]:     0051b227(j)  
    //                              tpnl_obj.cpp:285 (21)
    //         0051b3ae     MOV        this,dword ptr [EBP + 0x20]
    //         0051b3b1     PUSH       s_tpnl_obj::draw                                 = "tpnl_obj::draw"
    //         0051b3b6     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0051b3bb     TEST       EAX,EAX
    //         0051b3bd     JZ         LAB_0051b662
    //                              tpnl_obj.cpp:287 (15)
    //         0051b3c3     MOV        this,dword ptr [EBP + 0x20]
    //         0051b3c6     PUSH       0x1
    //         0051b3c8     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051b3cb     PUSH       EDX=>DAT_fffffff8
    //         0051b3cc     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_obj.cpp:288 (18)
    //         0051b3d2     MOV        EAX,dword ptr [EBP + 0x20]
    //         0051b3d5     PUSH       0xffffff
    //         0051b3da     MOV        this,dword ptr [EAX + 0x38]
    //         0051b3dd     PUSH       this=>DAT_fffffff8
    //         0051b3de     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_obj.cpp:289 (20)
    //         0051b3e4     MOV        EAX,dword ptr [EBP + 0x20]
    //         0051b3e7     MOV        EDX,dword ptr [EBP + 0x88]
    //         0051b3ed     PUSH       EDX
    //         0051b3ee     MOV        this,dword ptr [EAX + 0x38]
    //         0051b3f1     PUSH       this=>DAT_fffffff8
    //         0051b3f2     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              tpnl_obj.cpp:291 (20)
    //         0051b3f8     MOV        EAX,dword ptr [EBP + 0x20]
    //         0051b3fb     MOV        EDX,dword ptr [EBP + 0xf4]
    //         0051b401     PUSH       EDX
    //         0051b402     MOV        this,dword ptr [EAX + 0x38]
    //         0051b405     PUSH       this=>DAT_fffffff8
    //         0051b406     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_obj.cpp:306 (30)
    //         0051b40c     MOV        EDX,dword ptr [EBP + 0x114]
    //         0051b412     MOV        EBX,dword ptr [->GDI32.DLL::TextOutA]            = 0048b30c
    //         0051b418     MOV        dword ptr [ESP + 0x24],EAX
    //         0051b41c     MOV        EAX,dword ptr [EDX + 0xc]
    //         0051b41f     CMP        word ptr [EAX + 0x4a],0x0
    //         0051b424     JZ         LAB_0051b4d8
    //                              tpnl_obj.cpp:308 (15)
    //         0051b42a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051b430     CALL       RGE_Base_Game::campaignGame                      int campaignGame(RGE_Base_Game * this)
    //         0051b435     TEST       EAX,EAX
    //         0051b437     JZ         LAB_0051b478
    //                              tpnl_obj.cpp:309 (61)
    //         0051b439     MOV        this,dword ptr [EBP + 0x114]
    //         0051b43f     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051b442     MOVSX      EDX,word ptr [EAX + 0x4a]
    //         0051b446     MOV        EAX,dword ptr [EAX + 0x3c]
    //         0051b449     DEC        EDX
    //         0051b44a     PUSH       EDX
    //         0051b44b     MOV        this,dword ptr [EAX + 0x5c]
    //         0051b44e     CALL       RGE_Scenario::GetPlayerName                      char * GetPlayerName(RGE_Scenario * this, int
    //         0051b453     MOV        EDI,EAX
    //         0051b455     OR         this,0xffffffff
    //         0051b458     XOR        EAX,EAX
    //         0051b45a     LEA        EDX,[ESP + 0x3c]
    //         0051b45e     SCASB.RE   ES:EDI
    //         0051b460     NOT        this
    //         0051b462     SUB        EDI,this
    //         0051b464     MOV        EAX,this
    //         0051b466     MOV        ESI,EDI
    //         0051b468     MOV        EDI,EDX
    //         0051b46a     SHR        this,0x2
    //         0051b46d     MOVSD.REP  ES:EDI,ESI
    //         0051b46f     MOV        this,EAX
    //         0051b471     AND        this,0x3
    //         0051b474     MOVSB.REP  ES:EDI,ESI
    //                              tpnl_obj.cpp:310 (2)
    //         0051b476     JMP        LAB_0051b47d
    //                               LAB_0051b478                                                 XREF[1]:     0051b437(j)  
    //                              tpnl_obj.cpp:311 (5)
    //         0051b478     MOV        byte ptr [ESP + 0x3c],0x0
    //                               LAB_0051b47d                                                 XREF[1]:     0051b476(j)  
    //                              tpnl_obj.cpp:312 (8)
    //         0051b47d     MOV        AL,byte ptr [ESP + 0x3c]
    //         0051b481     TEST       AL,AL
    //         0051b483     JNZ        LAB_0051b4ad
    //                              tpnl_obj.cpp:313 (40)
    //         0051b485     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051b48b     LEA        EAX,[ESP + 0x3c]
    //         0051b48f     PUSH       0x64
    //         0051b491     PUSH       EAX=>DAT_fffffff8
    //         0051b492     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051b498     MOV        EDX,dword ptr [this->_padding_]
    //         0051b49a     PUSH       0x0=>DAT_fffffff4
    //         0051b49c     MOV        ESI,dword ptr [EAX + 0xc]
    //         0051b49f     XOR        EAX,EAX
    //         0051b4a1     MOV        AL,byte ptr [ESI + 0x105]
    //         0051b4a7     PUSH       EAX=>DAT_fffffff0
    //         0051b4a8     PUSH       0x69
    //         0051b4aa     CALL       dword ptr [EDX + 0x28]
    //                               LAB_0051b4ad                                                 XREF[1]:     0051b483(j)  
    //                              tpnl_obj.cpp:314 (43)
    //         0051b4ad     LEA        EDI,[ESP + 0x3c]
    //         0051b4b1     OR         this,0xffffffff
    //         0051b4b4     XOR        EAX,EAX
    //         0051b4b6     MOV        EDX,dword ptr [EBP + 0x10]
    //         0051b4b9     SCASB.RE   ES:EDI
    //         0051b4bb     NOT        this
    //         0051b4bd     MOV        EAX,dword ptr [EBP + 0xc]
    //         0051b4c0     DEC        this
    //         0051b4c1     PUSH       this
    //         0051b4c2     LEA        this,[ESP + 0x40]
    //         0051b4c6     PUSH       this=>DAT_fffffff8
    //         0051b4c7     MOV        this,dword ptr [EBP + 0x20]
    //         0051b4ca     SUB        EDX,0x2
    //         0051b4cd     ADD        EAX,0x3
    //         0051b4d0     PUSH       EDX=>DAT_fffffff4
    //         0051b4d1     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051b4d4     PUSH       EAX=>DAT_fffffff0
    //         0051b4d5     PUSH       EDX
    //         0051b4d6     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_0051b4d8                                                 XREF[1]:     0051b424(j)  
    //                              tpnl_obj.cpp:326 (18)
    //         0051b4d8     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051b4de     MOV        this,dword ptr [EAX + 0x8]
    //         0051b4e1     MOV        AX,word ptr [ECX + this->_padding_]
    //         0051b4e5     TEST       AX,AX
    //         0051b4e8     JLE        LAB_0051b505
    //                              tpnl_obj.cpp:327 (25)
    //         0051b4ea     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051b4f0     LEA        ESI,[ESP + 0xa0]
    //         0051b4f7     MOVSX      EAX,AX
    //         0051b4fa     MOV        EDX,dword ptr [this->_padding_]
    //         0051b4fc     PUSH       0x64
    //         0051b4fe     PUSH       ESI=>DAT_fffffff8
    //         0051b4ff     PUSH       EAX=>DAT_fffffff4
    //         0051b500     CALL       dword ptr [EDX + 0x20]
    //                              tpnl_obj.cpp:328 (2)
    //         0051b503     JMP        LAB_0051b50d
    //                               LAB_0051b505                                                 XREF[1]:     0051b4e8(j)  
    //                              tpnl_obj.cpp:329 (8)
    //         0051b505     MOV        byte ptr [ESP + 0xa0],0x0
    //                               LAB_0051b50d                                                 XREF[1]:     0051b503(j)  
    //                              tpnl_obj.cpp:330 (11)
    //         0051b50d     MOV        AL,byte ptr [ESP + 0xa0]
    //         0051b514     TEST       AL,AL
    //         0051b516     JNZ        LAB_0051b548
    //                              tpnl_obj.cpp:331 (48)
    //         0051b518     MOV        this,dword ptr [EBP + 0x114]
    //         0051b51e     LEA        EDX,[ESP + 0xa0]
    //         0051b525     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051b528     OR         this,0xffffffff
    //         0051b52b     MOV        EDI,dword ptr [EAX + 0x8]
    //         0051b52e     XOR        EAX,EAX
    //         0051b530     SCASB.RE   ES:EDI
    //         0051b532     NOT        this
    //         0051b534     SUB        EDI,this
    //         0051b536     MOV        EAX,this
    //         0051b538     MOV        ESI,EDI
    //         0051b53a     MOV        EDI,EDX
    //         0051b53c     SHR        this,0x2
    //         0051b53f     MOVSD.REP  ES:EDI,ESI
    //         0051b541     MOV        this,EAX
    //         0051b543     AND        this,0x3
    //         0051b546     MOVSB.REP  ES:EDI,ESI
    //                               LAB_0051b548                                                 XREF[1]:     0051b516(j)  
    //                              tpnl_obj.cpp:332 (16)
    //         0051b548     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051b54e     MOV        EAX,dword ptr [this->_padding_ + 0xc20]
    //         0051b554     TEST       EAX,EAX
    //         0051b556     JZ         LAB_0051b57e
    //                              tpnl_obj.cpp:333 (36)
    //         0051b558     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051b55e     LEA        EDX,[ESP + 0xa0]
    //         0051b565     PUSH       EDX
    //         0051b566     LEA        EDX,[ESP + 0x40]
    //         0051b56a     MOV        this,dword ptr [EAX + 0x4]
    //         0051b56d     PUSH       this=>DAT_fffffff8
    //         0051b56e     PUSH       s_%d-%s                                          = "%d-%s"
    //         0051b573     PUSH       EDX=>DAT_fffffff0
    //         0051b574     CALL       sprintf                                          undefined sprintf()
    //         0051b579     ADD        ESP,0x10
    //                              tpnl_obj.cpp:334 (2)
    //         0051b57c     JMP        LAB_0051b598
    //                               LAB_0051b57e                                                 XREF[1]:     0051b556(j)  
    //                              tpnl_obj.cpp:335 (26)
    //         0051b57e     LEA        EAX,[ESP + 0xa0]
    //         0051b585     LEA        this,[ESP + 0x3c]
    //         0051b589     PUSH       EAX
    //         0051b58a     PUSH       s_%s                                             = "%s"
    //         0051b58f     PUSH       this=>DAT_fffffff4
    //         0051b590     CALL       sprintf                                          undefined sprintf()
    //         0051b595     ADD        ESP,0xc
    //                               LAB_0051b598                                                 XREF[1]:     0051b57c(j)  
    //                              tpnl_obj.cpp:336 (43)
    //         0051b598     LEA        EDI,[ESP + 0x3c]
    //         0051b59c     OR         this,0xffffffff
    //         0051b59f     XOR        EAX,EAX
    //         0051b5a1     LEA        EDX,[ESP + 0x3c]
    //         0051b5a5     SCASB.RE   ES:EDI
    //         0051b5a7     MOV        EAX,dword ptr [EBP + 0x10]
    //         0051b5aa     NOT        this
    //         0051b5ac     DEC        this
    //         0051b5ad     ADD        EAX,0xd
    //         0051b5b0     PUSH       this
    //         0051b5b1     MOV        this,dword ptr [EBP + 0xc]
    //         0051b5b4     PUSH       EDX=>DAT_fffffff8
    //         0051b5b5     MOV        EDX,dword ptr [EBP + 0x20]
    //         0051b5b8     PUSH       EAX=>DAT_fffffff4
    //         0051b5b9     ADD        this,0x3
    //         0051b5bc     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051b5bf     PUSH       this=>DAT_fffffff0
    //         0051b5c0     PUSH       EAX
    //         0051b5c1     CALL       EBX=>GDI32.DLL::TextOutA
    //                              tpnl_obj.cpp:341 (22)
    //         0051b5c3     MOV        this,dword ptr [EBP + 0x114]
    //         0051b5c9     FLD        float ptr [ECX + this->_padding_]
    //         0051b5cc     FCOMP      float ptr [null_00576d80]                        = align(7)
    //         0051b5d2     FNSTSW     AX
    //         0051b5d4     TEST       AH,0x41
    //         0051b5d7     JNZ        LAB_0051b630
    //                              tpnl_obj.cpp:343 (35)
    //         0051b5d9     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051b5dc     FLD        float ptr [ECX + this->_padding_]
    //         0051b5df     MOVSX      EAX,word ptr [EDX + 0x26]
    //         0051b5e3     PUSH       EAX
    //         0051b5e4     CALL       __ftol                                           undefined __ftol()
    //         0051b5e9     PUSH       EAX=>DAT_fffffff8
    //         0051b5ea     LEA        this,[ESP + 0xa8]
    //         0051b5f1     PUSH       s_%d/%d                                          = "%d/%d"
    //         0051b5f6     PUSH       this=>DAT_fffffff0
    //         0051b5f7     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_obj.cpp:344 (52)
    //         0051b5fc     LEA        EDI,[ESP + 0xb0]
    //         0051b603     OR         this,0xffffffff
    //         0051b606     XOR        EAX,EAX
    //         0051b608     ADD        ESP,0x10
    //         0051b60b     SCASB.RE   ES:EDI
    //         0051b60d     MOV        EAX,dword ptr [EBP + 0x10]
    //         0051b610     LEA        EDX,[ESP + 0xa0]
    //         0051b617     NOT        this
    //         0051b619     DEC        this
    //         0051b61a     ADD        EAX,0x5c
    //         0051b61d     PUSH       this
    //         0051b61e     MOV        this,dword ptr [EBP + 0xc]
    //         0051b621     PUSH       EDX=>DAT_fffffff8
    //         0051b622     MOV        EDX,dword ptr [EBP + 0x20]
    //         0051b625     PUSH       EAX=>DAT_fffffff4
    //         0051b626     ADD        this,0x3
    //         0051b629     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051b62c     PUSH       this=>DAT_fffffff0
    //         0051b62d     PUSH       EAX
    //         0051b62e     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_0051b630                                                 XREF[1]:     0051b5d7(j)  
    //                              tpnl_obj.cpp:348 (18)
    //         0051b630     MOV        EDX,dword ptr [EBP + 0x20]
    //         0051b633     MOV        this,dword ptr [ESP + 0x24]
    //         0051b637     PUSH       this
    //         0051b638     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051b63b     PUSH       EAX=>DAT_fffffff8
    //         0051b63c     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_obj.cpp:349 (15)
    //         0051b642     MOV        this,dword ptr [EBP + 0x20]
    //         0051b645     PUSH       0x0
    //         0051b647     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051b64a     PUSH       EDX=>DAT_fffffff8
    //         0051b64b     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              tpnl_obj.cpp:350 (17)
    //         0051b651     MOV        this,dword ptr [EBP + 0x20]
    //         0051b654     PUSH       s_tpnl_obj::draw                                 = "tpnl_obj::draw"
    //         0051b659     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         0051b65e     MOV        EBX,dword ptr [ESP + 0x18]
    //                               LAB_0051b662                                                 XREF[1]:     0051b3bd(j)  
    //                              tpnl_obj.cpp:391 (65)
    //         0051b662     MOV        this,dword ptr [EBP + 0x114]
    //         0051b668     XOR        ESI,ESI
    //         0051b66a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051b66d     MOV        AL,byte ptr [EDX + 0x8f]
    //         0051b673     CMP        AL,0x3
    //         0051b675     JZ         LAB_0051bb21
    //         0051b67b     CMP        AL,0x9
    //         0051b67d     JZ         LAB_0051bb19
    //         0051b683     CMP        AL,0x4
    //         0051b685     JZ         LAB_0051bb19
    //         0051b68b     CMP        AL,0x5
    //         0051b68d     JZ         LAB_0051bb19
    //         0051b693     CMP        AL,0x6
    //         0051b695     JZ         LAB_0051bb19
    //         0051b69b     CMP        AL,0x7
    //         0051b69d     JZ         LAB_0051bb19
    //                              tpnl_obj.cpp:516 (4)
    //         0051b6a3     CMP        AL,0x1
    //         0051b6a5     JNZ        LAB_0051b71a
    //                              tpnl_obj.cpp:518 (28)
    //         0051b6a7     MOVSX      EAX,word ptr [ECX + this->_padding_]
    //         0051b6ab     CMP        EAX,0x11
    //         0051b6ae     JA         switchD_0051b6bc::caseD_4
    //         0051b6b4     XOR        EDX,EDX
    //         0051b6b6     MOV        DL,byte ptr [EAX + switchD_0051b6bc::switchdat
    //                               switchD_0051b6bc::switchD
    //         0051b6bc     JMP        dword ptr [EDX*0x4 + switchD_0051b6bc::switchd   = 0051b6c3
    //                               switchD_0051b6bc::caseD_f                                    XREF[3]:     0051b6bc(j), 0051becc(*), 
    //                               switchD_0051b6bc::caseD_10                                                0051bee0(*)  
    //                               switchD_0051b6bc::caseD_11
    //                               switchD_0051b6bc::caseD_0
    //                              tpnl_obj.cpp:523 (7)
    //         0051b6c3     MOV        ESI,0x2
    //         0051b6c8     JMP        LAB_0051b6e1
    //                               switchD_0051b6bc::caseD_1                                    XREF[2]:     0051b6bc(j), 0051bed0(*)  
    //                              tpnl_obj.cpp:524 (4)
    //         0051b6ca     XOR        ESI,ESI
    //         0051b6cc     JMP        LAB_0051b6e1
    //                               switchD_0051b6bc::caseD_2                                    XREF[2]:     0051b6bc(j), 0051bed4(*)  
    //                              tpnl_obj.cpp:525 (7)
    //         0051b6ce     MOV        ESI,0x1
    //         0051b6d3     JMP        LAB_0051b6e1
    //                               switchD_0051b6bc::caseD_3                                    XREF[2]:     0051b6bc(j), 0051bed8(*)  
    //                              tpnl_obj.cpp:526 (7)
    //         0051b6d5     MOV        ESI,0x3
    //         0051b6da     JMP        LAB_0051b6e1
    //                               switchD_0051b6bc::caseD_9                                    XREF[2]:     0051b6bc(j), 0051bedc(*)  
    //                              tpnl_obj.cpp:527 (9)
    //         0051b6dc     MOV        ESI,0x5
    //                               LAB_0051b6e1                                                 XREF[4]:     0051b6c8(j), 0051b6cc(j), 
    //                                                                                                         0051b6d3(j), 0051b6da(j)  
    //         0051b6e1     MOV        dword ptr [ESP + 0x10],ESI
    //                              tpnl_obj.cpp:532 (33)
    //         0051b6e5     PUSH       0x0
    //         0051b6e7     FLD        float ptr [ECX + this->_padding_]
    //         0051b6ea     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051b6f0     CALL       __ftol                                           undefined __ftol()
    //         0051b6f5     PUSH       EAX=>DAT_fffffff8
    //         0051b6f6     PUSH       0x0=>DAT_fffffff4
    //         0051b6f8     MOVSX      EAX,SI
    //         0051b6fb     PUSH       EAX=>DAT_fffffff0
    //         0051b6fc     PUSH       0x0
    //         0051b6fe     MOV        this,EBP
    //         0051b700     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:734 (9)
    //         0051b706     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051b70a     MOV        this,EBP
    //         0051b70c     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051b70f     POP        EDI
    //         0051b710     POP        ESI
    //         0051b711     POP        EBP
    //         0051b712     POP        EBX
    //         0051b713     ADD        ESP,0x158
    //         0051b719     RET
    //                               LAB_0051b71a                                                 XREF[1]:     0051b6a5(j)  
    //                              tpnl_obj.cpp:540 (12)
    //         0051b71a     CMP        AL,0x2
    //         0051b71c     JZ         LAB_0051b726
    //         0051b71e     CMP        AL,0x8
    //         0051b720     JNZ        LAB_0051be67
    //                               LAB_0051b726                                                 XREF[1]:     0051b71c(j)  
    //                              tpnl_obj.cpp:542 (10)
    //         0051b726     CMP        byte ptr [EDX + 0x4],0x50
    //         0051b72a     JNZ        LAB_0051b925
    //                              tpnl_obj.cpp:544 (2)
    //         0051b730     MOV        EDI,this
    //                              tpnl_obj.cpp:545 (36)
    //         0051b732     LEA        this,[ESP + 0x104]
    //         0051b739     PUSH       0x64
    //         0051b73b     LEA        EDX,[ESP + 0x30]
    //         0051b73f     PUSH       this=>DAT_fffffff8
    //         0051b740     LEA        EAX,[ESP + 0x3a]
    //         0051b744     PUSH       EDX=>DAT_fffffff4
    //         0051b745     LEA        this,[ESP + 0x2c]
    //         0051b749     PUSH       EAX=>DAT_fffffff0
    //         0051b74a     PUSH       this
    //         0051b74b     MOV        this,EDI
    //         0051b74d     MOV        dword ptr [ESP + 0x38],EDI
    //         0051b751     CALL       TRIBE_Building_Object::work_status               int work_status(TRIBE_Building_Object * this,
    //                              tpnl_obj.cpp:547 (16)
    //         0051b756     MOV        EAX,dword ptr [ESP + 0x20]
    //         0051b75a     CMP        AX,0x67
    //         0051b75e     JZ         LAB_0051b78b
    //         0051b760     CMP        AX,0x66
    //         0051b764     JZ         LAB_0051b78b
    //                              tpnl_obj.cpp:548 (21)
    //         0051b766     LEA        EDX,[ESP + 0x38]
    //         0051b76a     LEA        EAX,[ESP + 0x32]
    //         0051b76e     PUSH       EDX
    //         0051b76f     PUSH       EAX=>DAT_fffffff8
    //         0051b770     MOV        this,EDI
    //         0051b772     CALL       TRIBE_Building_Object::production_queue_status   int production_queue_status(TRIBE_Building_Ob
    //         0051b777     TEST       EAX,EAX
    //         0051b779     JZ         LAB_0051b78b
    //                              tpnl_obj.cpp:551 (16)
    //         0051b77b     MOV        this,dword ptr [ESP + 0x38]
    //         0051b77f     MOV        dword ptr [ESP + 0x20],0x66
    //         0051b787     MOV        dword ptr [ESP + 0x2c],this
    //                               LAB_0051b78b                                                 XREF[3]:     0051b75e(j), 0051b764(j), 
    //                                                                                                         0051b779(j)  
    //                              tpnl_obj.cpp:556 (50)
    //         0051b78b     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051b791     MOV        this,byte ptr [EAX + 0x48]
    //         0051b794     TEST       this,this
    //         0051b796     JZ         LAB_0051b837
    //         0051b79c     MOV        EDX,dword ptr [EAX + 0xc]
    //         0051b79f     MOV        EAX,dword ptr [EBP + 0x110]
    //         0051b7a5     CMP        EDX,EAX
    //         0051b7a7     JNZ        LAB_0051b7bd
    //         0051b7a9     MOV        EAX,dword ptr [ESP + 0x20]
    //         0051b7ad     CMP        AX,0x67
    //         0051b7b1     JZ         LAB_0051b837
    //         0051b7b7     CMP        AX,0x66
    //         0051b7bb     JZ         LAB_0051b837
    //                               LAB_0051b7bd                                                 XREF[1]:     0051b7a7(j)  
    //                              tpnl_obj.cpp:559 (20)
    //         0051b7bd     MOV        EBX,dword ptr [EDI]
    //         0051b7bf     LEA        EAX,[ESP + 0x16]
    //         0051b7c3     LEA        this,[ESP + 0x10]
    //         0051b7c7     PUSH       EAX
    //         0051b7c8     PUSH       this=>DAT_fffffff8
    //         0051b7c9     MOV        this,EDI
    //         0051b7cb     CALL       dword ptr [EBX + 0x230]
    //                              tpnl_obj.cpp:560 (9)
    //         0051b7d1     MOV        EAX,dword ptr [ESP + 0x10]
    //         0051b7d5     TEST       AX,AX
    //         0051b7d8     JLE        LAB_0051b7fb
    //                              tpnl_obj.cpp:562 (28)
    //         0051b7da     MOVSX      EDX,AX
    //         0051b7dd     MOVSX      EAX,word ptr [ESP + 0x16]
    //         0051b7e2     PUSH       EDX
    //         0051b7e3     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051b7e7     PUSH       EAX=>DAT_fffffff8
    //         0051b7e8     PUSH       offset DAT_fffffff4
    //         0051b7ea     PUSH       offset DAT_fffffff0
    //         0051b7ec     PUSH       0x0
    //         0051b7ee     MOV        this,EBP
    //         0051b7f0     CALL       dword ptr [EDX + 0xe0]
    //                              tpnl_obj.cpp:563 (5)
    //         0051b7f6     MOV        ESI,0x1
    //                               LAB_0051b7fb                                                 XREF[1]:     0051b7d8(j)  
    //                              tpnl_obj.cpp:567 (18)
    //         0051b7fb     LEA        EAX,[ESP + 0x34]
    //         0051b7ff     LEA        this,[ESP + 0x28]
    //         0051b803     PUSH       EAX
    //         0051b804     PUSH       this=>DAT_fffffff8
    //         0051b805     MOV        this,EDI
    //         0051b807     CALL       dword ptr [EBX + 0x234]
    //                              tpnl_obj.cpp:568 (13)
    //         0051b80d     FLD        float ptr [ESP + 0x28]
    //         0051b811     CALL       __ftol                                           undefined __ftol()
    //         0051b816     TEST       EAX,EAX
    //         0051b818     JLE        LAB_0051b837
    //                              tpnl_obj.cpp:570 (28)
    //         0051b81a     FLD        float ptr [ESP + 0x34]
    //         0051b81e     PUSH       EAX
    //         0051b81f     CALL       __ftol                                           undefined __ftol()
    //         0051b824     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051b828     PUSH       EAX=>DAT_fffffff8
    //         0051b829     PUSH       offset DAT_fffffff4
    //         0051b82b     PUSH       offset DAT_fffffff0
    //         0051b82d     PUSH       ESI
    //         0051b82e     MOV        this,EBP
    //         0051b830     CALL       dword ptr [EDX + 0xe0]
    //                              tpnl_obj.cpp:571 (1)
    //         0051b836     INC        ESI
    //                               LAB_0051b837                                                 XREF[4]:     0051b796(j), 0051b7b1(j), 
    //                                                                                                         0051b7bb(j), 0051b818(j)  
    //                              tpnl_obj.cpp:575 (21)
    //         0051b837     MOV        this,dword ptr [EBP + 0x114]
    //         0051b83d     MOV        EAX,dword ptr [EBP + 0x110]
    //         0051b843     CMP        dword ptr [ECX + this->_padding_],EAX
    //         0051b846     JNZ        LAB_0051b925
    //                              tpnl_obj.cpp:578 (7)
    //         0051b84c     MOV        DL,byte ptr [EDI + 0x48]
    //         0051b84f     TEST       DL,DL
    //         0051b851     JNZ        LAB_0051b861
    //                              tpnl_obj.cpp:580 (12)
    //         0051b853     PUSH       0x0
    //         0051b855     MOV        this,EDI
    //         0051b857     CALL       TRIBE_Building_Object::get_construction_progress short get_construction_progress(TRIBE_Buildin
    //         0051b85c     MOVSX      EAX,AX
    //                              tpnl_obj.cpp:583 (10)
    //         0051b85f     JMP        LAB_0051b878
    //                               LAB_0051b861                                                 XREF[1]:     0051b851(j)  
    //         0051b861     MOV        EDX,dword ptr [ESP + 0x20]
    //         0051b865     CMP        DX,0x67
    //                              tpnl_obj.cpp:593 (8)
    //         0051b869     JZ         LAB_0051b871
    //         0051b86b     CMP        DX,0x66
    //         0051b86f     JNZ        LAB_0051b88f
    //                               LAB_0051b871                                                 XREF[1]:     0051b869(j)  
    //                              tpnl_obj.cpp:606 (25)
    //         0051b871     MOVSX      EAX,word ptr [ESP + 0x2c]
    //         0051b876     PUSH       0x0
    //                               LAB_0051b878                                                 XREF[1]:     0051b85f(j)  
    //         0051b878     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051b87c     PUSH       EAX=>DAT_fffffff8
    //         0051b87d     PUSH       offset DAT_fffffff4
    //         0051b87f     PUSH       offset DAT_fffffff0
    //         0051b881     PUSH       ESI
    //         0051b882     MOV        this,EBP
    //         0051b884     CALL       dword ptr [EDX + 0xe0]
    //                              tpnl_obj.cpp:609 (5)
    //         0051b88a     JMP        LAB_0051b924
    //                               LAB_0051b88f                                                 XREF[1]:     0051b86f(j)  
    //                              tpnl_obj.cpp:612 (10)
    //         0051b88f     MOV        this,dword ptr [ECX + this->_padding_]
    //         0051b892     CMP        word ptr [ECX + this->_padding_],0x46
    //         0051b897     JNZ        LAB_0051b8da
    //                              tpnl_obj.cpp:614 (60)
    //         0051b899     MOV        EDI,dword ptr [EAX + 0x50]
    //         0051b89c     FLD        float ptr [EDI + 0x10]
    //         0051b89f     FADD       float ptr [EDI + 0x2c]
    //         0051b8a2     CALL       __ftol                                           undefined __ftol()
    //         0051b8a7     FLD        float ptr [EDI + 0x80]
    //         0051b8ad     MOV        EBX,EAX
    //         0051b8af     CALL       __ftol                                           undefined __ftol()
    //         0051b8b4     CMP        EAX,EBX
    //         0051b8b6     JL         LAB_0051b8ba
    //         0051b8b8     MOV        EAX,EBX
    //                               LAB_0051b8ba                                                 XREF[1]:     0051b8b6(j)  
    //         0051b8ba     FLD        float ptr [EDI + 0x2c]
    //         0051b8bd     PUSH       EAX
    //         0051b8be     CALL       __ftol                                           undefined __ftol()
    //         0051b8c3     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051b8c7     PUSH       EAX=>DAT_fffffff8
    //         0051b8c8     PUSH       offset DAT_fffffff4
    //         0051b8ca     PUSH       offset DAT_fffffff0
    //         0051b8cc     PUSH       ESI
    //         0051b8cd     MOV        this,EBP
    //         0051b8cf     CALL       dword ptr [EDX + 0xe0]
    //                              tpnl_obj.cpp:615 (5)
    //         0051b8d5     MOV        EDI,dword ptr [ESP + 0x24]
    //         0051b8d9     INC        ESI
    //                               LAB_0051b8da                                                 XREF[1]:     0051b897(j)  
    //                              tpnl_obj.cpp:619 (16)
    //         0051b8da     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051b8e0     MOV        this,dword ptr [EAX + 0x8]
    //         0051b8e3     CMP        word ptr [ECX + this->_padding_],0x32
    //         0051b8e8     JNZ        LAB_0051b925
    //                              tpnl_obj.cpp:621 (11)
    //         0051b8ea     MOV        this,dword ptr [EDI + 0x184]
    //         0051b8f0     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //                              tpnl_obj.cpp:622 (4)
    //         0051b8f5     TEST       EAX,EAX
    //         0051b8f7     JZ         LAB_0051b925
    //                              tpnl_obj.cpp:624 (43)
    //         0051b8f9     FLD        float ptr [EAX + 0x2c]
    //         0051b8fc     MOV        EDX,dword ptr [EBP + 0x114]
    //         0051b902     PUSH       0x0
    //         0051b904     FADD       float ptr [EDX + 0x44]
    //         0051b907     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051b90d     CALL       __ftol                                           undefined __ftol()
    //         0051b912     PUSH       EAX=>DAT_fffffff8
    //         0051b913     MOV        EAX,dword ptr [ESP + 0x20]
    //         0051b917     PUSH       0x0=>DAT_fffffff4
    //         0051b919     PUSH       offset DAT_fffffff0
    //         0051b91b     PUSH       ESI
    //         0051b91c     MOV        this,EBP
    //         0051b91e     CALL       dword ptr [EAX + 0xe0]
    //                               LAB_0051b924                                                 XREF[1]:     0051b88a(j)  
    //                              tpnl_obj.cpp:625 (1)
    //         0051b924     INC        ESI
    //                               LAB_0051b925                                                 XREF[4]:     0051b72a(j), 0051b846(j), 
    //                                                                                                         0051b8e8(j), 0051b8f7(j)  
    //                              tpnl_obj.cpp:635 (25)
    //         0051b925     MOV        EDI,dword ptr [EBP + 0x114]
    //         0051b92b     MOV        AL,byte ptr [EDI + 0x48]
    //         0051b92e     TEST       AL,AL
    //         0051b930     JZ         LAB_0051ba3c
    //         0051b936     CMP        AL,0x2
    //         0051b938     JNZ        LAB_0051ba3c
    //                              tpnl_obj.cpp:639 (23)
    //         0051b93e     MOV        EAX,dword ptr [EDI + 0xc]
    //         0051b941     MOV        this,dword ptr [EBP + 0x110]
    //         0051b947     XOR        EBX,EBX
    //         0051b949     CMP        EAX,this
    //         0051b94b     JZ         LAB_0051b95b
    //         0051b94d     MOV        EDX,dword ptr [EDI + 0x8]
    //         0051b950     CMP        word ptr [EDX + 0x10],0x2d
    //                              tpnl_obj.cpp:642 (22)
    //         0051b955     JZ         LAB_0051b995
    //         0051b957     CMP        EAX,this
    //         0051b959     JNZ        LAB_0051b99a
    //                               LAB_0051b95b                                                 XREF[1]:     0051b94b(j)  
    //         0051b95b     MOV        EAX,dword ptr [ESP + 0x20]
    //         0051b95f     CMP        AX,0x67
    //         0051b963     JZ         LAB_0051b99a
    //         0051b965     CMP        AX,0x66
    //         0051b969     JZ         LAB_0051b99a
    //                              tpnl_obj.cpp:645 (11)
    //         0051b96b     MOV        EAX,dword ptr [EDI + 0x8]
    //         0051b96e     MOV        AX,word ptr [EAX + 0x10]
    //         0051b972     CMP        AX,0x2d
    //                              tpnl_obj.cpp:647 (8)
    //         0051b976     JZ         LAB_0051b995
    //         0051b978     CMP        AX,0x32
    //         0051b97c     JNZ        LAB_0051b982
    //                              tpnl_obj.cpp:648 (2)
    //         0051b97e     XOR        EBX,EBX
    //                              tpnl_obj.cpp:650 (21)
    //         0051b980     JMP        LAB_0051b99a
    //                               LAB_0051b982                                                 XREF[1]:     0051b97c(j)  
    //         0051b982     CMP        word ptr [EDI + 0x4c],-0x1
    //         0051b987     JZ         LAB_0051b99a
    //         0051b989     FLD        float ptr [EDI + 0x44]
    //         0051b98c     CALL       __ftol                                           undefined __ftol()
    //         0051b991     TEST       EAX,EAX
    //         0051b993     JLE        LAB_0051b99a
    //                               LAB_0051b995                                                 XREF[2]:     0051b955(j), 0051b976(j)  
    //                              tpnl_obj.cpp:651 (5)
    //         0051b995     MOV        EBX,0x1
    //                               LAB_0051b99a                                                 XREF[6]:     0051b959(j), 0051b963(j), 
    //                                                                                                         0051b969(j), 0051b980(j), 
    //                                                                                                         0051b987(j), 0051b993(j)  
    //                              tpnl_obj.cpp:653 (8)
    //         0051b99a     TEST       EBX,EBX
    //         0051b99c     JZ         LAB_0051ba3c
    //                              tpnl_obj.cpp:655 (10)
    //         0051b9a2     MOV        this,dword ptr [EDI + 0x8]
    //         0051b9a5     CMP        word ptr [ECX + this->_padding_],0x2d
    //         0051b9aa     JNZ        LAB_0051b9b6
    //                              tpnl_obj.cpp:656 (8)
    //         0051b9ac     MOV        dword ptr [ESP + 0x10],0x9
    //                              tpnl_obj.cpp:657 (2)
    //         0051b9b4     JMP        LAB_0051b9be
    //                               LAB_0051b9b6                                                 XREF[1]:     0051b9aa(j)  
    //                              tpnl_obj.cpp:658 (8)
    //         0051b9b6     MOV        DX,word ptr [EDI + 0x4c]
    //         0051b9ba     MOV        dword ptr [ESP + 0x10],EDX
    //                               LAB_0051b9be                                                 XREF[1]:     0051b9b4(j)  
    //                              tpnl_obj.cpp:659 (28)
    //         0051b9be     MOVSX      EAX,word ptr [EDI + 0x4c]
    //         0051b9c2     CMP        EAX,0x11
    //         0051b9c5     JA         switchD_0051b9d3::caseD_4
    //         0051b9cb     XOR        this,this
    //         0051b9cd     MOV        this,byte ptr [EAX + switchD_0051b9d3::switchd
    //                               switchD_0051b9d3::switchD
    //         0051b9d3     JMP        dword ptr [this->_padding_*0x4 + switchD_0051b   = 0051b9da
    //                               switchD_0051b9d3::caseD_f                                    XREF[3]:     0051b9d3(j), 0051befc(*), 
    //                               switchD_0051b9d3::caseD_10                                                0051bf10(*)  
    //                               switchD_0051b9d3::caseD_11
    //                               switchD_0051b9d3::caseD_0
    //                              tpnl_obj.cpp:664 (9)
    //         0051b9da     MOV        EBX,0x2
    //         0051b9df     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_0051b9e3                                                 XREF[4]:     0051be8f(j), 0051be9d(j), 
    //                                                                                                         0051beab(j), 0051beb9(j)  
    //                              tpnl_obj.cpp:674 (3)
    //         0051b9e3     MOV        EDX,dword ptr [EDI + 0x8]
    //                              tpnl_obj.cpp:675 (49)
    //         0051b9e6     PUSH       0x0
    //         0051b9e8     CMP        word ptr [EDX + 0x10],0x2d
    //         0051b9ed     JNZ        LAB_0051ba19
    //         0051b9ef     MOV        EAX,dword ptr [EDI + 0xc]
    //         0051b9f2     MOV        this,dword ptr [EAX + 0x50]
    //         0051b9f5     FLD        float ptr [ECX + this->_padding_]
    //         0051b9f8     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051b9fe     CALL       __ftol                                           undefined __ftol()
    //         0051ba03     MOVSX      EDX,BX
    //         0051ba06     PUSH       EAX=>DAT_fffffff8
    //         0051ba07     MOV        EAX,dword ptr [ESP + 0x20]
    //         0051ba0b     PUSH       0x0=>DAT_fffffff4
    //         0051ba0d     PUSH       EDX=>DAT_fffffff0
    //         0051ba0e     PUSH       ESI
    //         0051ba0f     MOV        this,EBP
    //         0051ba11     CALL       dword ptr [EAX + 0xe0]
    //                              tpnl_obj.cpp:676 (2)
    //         0051ba17     JMP        LAB_0051ba3b
    //                               LAB_0051ba19                                                 XREF[1]:     0051b9ed(j)  
    //                              tpnl_obj.cpp:677 (34)
    //         0051ba19     FLD        float ptr [EDI + 0x44]
    //         0051ba1c     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051ba22     CALL       __ftol                                           undefined __ftol()
    //         0051ba27     MOV        EDX,dword ptr [ESP + 0x1c]
    //         0051ba2b     PUSH       EAX=>DAT_fffffff8
    //         0051ba2c     MOVSX      this,BX
    //         0051ba2f     PUSH       0x0=>DAT_fffffff4
    //         0051ba31     PUSH       this=>DAT_fffffff0
    //         0051ba32     PUSH       ESI
    //         0051ba33     MOV        this,EBP
    //         0051ba35     CALL       dword ptr [EDX + 0xe0]
    //                               LAB_0051ba3b                                                 XREF[1]:     0051ba17(j)  
    //                              tpnl_obj.cpp:678 (1)
    //         0051ba3b     INC        ESI
    //                               LAB_0051ba3c                                                 XREF[4]:     0051b930(j), 0051b938(j), 
    //                                                                                                         0051b99c(j), 0051bec6(j)  
    //                              tpnl_obj.cpp:686 (37)
    //         0051ba3c     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051ba42     MOV        this,dword ptr [EAX + 0x8]
    //         0051ba45     CMP        word ptr [ECX + this->_padding_],0x2d
    //         0051ba4a     JNZ        LAB_0051be67
    //         0051ba50     MOV        EDX,dword ptr [EAX + 0xc]
    //         0051ba53     MOV        this,dword ptr [EBP + 0x110]
    //         0051ba59     CMP        EDX,this
    //         0051ba5b     JZ         LAB_0051be67
    //                              tpnl_obj.cpp:697 (34)
    //         0051ba61     MOV        this,dword ptr [EAX + 0x3c]
    //         0051ba64     MOV        EDX,dword ptr [EAX + 0x38]
    //         0051ba67     PUSH       EAX
    //         0051ba68     PUSH       offset DAT_fffffff8
    //         0051ba6a     PUSH       offset DAT_fffffff4
    //         0051ba6c     PUSH       this=>DAT_fffffff0
    //         0051ba6d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051ba73     PUSH       EDX
    //         0051ba74     PUSH       0x2d
    //         0051ba76     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0051ba7b     MOV        this,dword ptr [EAX + 0x28]
    //         0051ba7e     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //                              tpnl_obj.cpp:699 (8)
    //         0051ba83     TEST       EAX,EAX
    //         0051ba85     JZ         LAB_0051be67
    //                              tpnl_obj.cpp:714 (69)
    //         0051ba8b     FLD        float ptr [EAX + 0x3c]
    //         0051ba8e     MOV        this,dword ptr [EBP + 0x114]
    //         0051ba94     MOV        EDX,dword ptr [EBP + 0x110]
    //         0051ba9a     FLD        float ptr [EAX + 0x38]
    //         0051ba9d     FSUB       float ptr [ECX + this->_padding_]
    //         0051baa0     FXCH
    //         0051baa2     FSUB       float ptr [ECX + this->_padding_]
    //         0051baa5     FXCH
    //         0051baa7     CMP        byte ptr [EDX + 0x105],0xf
    //         0051baae     FST        float ptr [ESP + 0x1c]
    //         0051bab2     FLD        ST1
    //         0051bab4     FXCH
    //         0051bab6     FMUL       float ptr [ESP + 0x1c]
    //         0051baba     FXCH
    //         0051babc     FMUL       ST2
    //         0051babe     FADDP
    //         0051bac0     FMUL       float ptr [DAT_00576d88]                         = 0Ch
    //         0051bac6     FMUL       float ptr [DAT_00576d8c]                         = 33h    3
    //         0051bacc     FSTP       ST1
    //         0051bace     JNZ        LAB_0051bad2
    //                              tpnl_obj.cpp:715 (2)
    //         0051bad0     FADD       ST0,ST0
    //                               LAB_0051bad2                                                 XREF[1]:     0051bace(j)  
    //                              tpnl_obj.cpp:718 (15)
    //         0051bad2     FCOM       double ptr [DAT_00576d98]                        = 66h    f
    //         0051bad8     FNSTSW     AX
    //         0051bada     TEST       AH,0x1
    //         0051badd     JZ         LAB_0051bae7
    //         0051badf     FSTP       ST0
    //                              tpnl_obj.cpp:719 (6)
    //         0051bae1     FLD        float ptr [DAT_00576da0]                         = 33h    3
    //                               LAB_0051bae7                                                 XREF[1]:     0051badd(j)  
    //                              tpnl_obj.cpp:721 (6)
    //         0051bae7     FMUL       float ptr [DAT_00576da4]
    //                              tpnl_obj.cpp:724 (15)
    //         0051baed     FCOM       float ptr [DAT_00576da8]
    //         0051baf3     FNSTSW     AX
    //         0051baf5     TEST       AH,0x41
    //         0051baf8     JNZ        LAB_0051bb02
    //         0051bafa     FSTP       ST0
    //                              tpnl_obj.cpp:725 (6)
    //         0051bafc     FLD        float ptr [DAT_00576da8]
    //                               LAB_0051bb02                                                 XREF[1]:     0051baf8(j)  
    //                              tpnl_obj.cpp:727 (23)
    //         0051bb02     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051bb08     PUSH       0x14
    //         0051bb0a     CALL       __ftol                                           undefined __ftol()
    //         0051bb0f     PUSH       EAX=>DAT_fffffff8
    //         0051bb10     PUSH       offset DAT_fffffff4
    //         0051bb12     PUSH       offset DAT_fffffff0
    //         0051bb14     JMP        LAB_0051be5a
    //                               LAB_0051bb19                                                 XREF[5]:     0051b67d(j), 0051b685(j), 
    //                                                                                                         0051b68d(j), 0051b695(j), 
    //                                                                                                         0051b69d(j)  
    //                              tpnl_obj.cpp:395 (8)
    //         0051bb19     CMP        AL,0x3
    //         0051bb1b     JZ         LAB_0051bb21
    //         0051bb1d     CMP        AL,0x4
    //         0051bb1f     JNZ        LAB_0051bb52
    //                               LAB_0051bb21                                                 XREF[2]:     0051b675(j), 0051bb1b(j)  
    //                              tpnl_obj.cpp:397 (18)
    //         0051bb21     MOV        EDX,dword ptr [this->_padding_]
    //         0051bb23     LEA        EAX,[ESP + 0x16]
    //         0051bb27     PUSH       EAX
    //         0051bb28     LEA        EAX,[ESP + 0x14]
    //         0051bb2c     PUSH       EAX=>DAT_fffffff8
    //         0051bb2d     CALL       dword ptr [EDX + 0x230]
    //                              tpnl_obj.cpp:398 (26)
    //         0051bb33     MOVSX      this,word ptr [ESP + 0x10]
    //         0051bb38     MOVSX      EDX,word ptr [ESP + 0x16]
    //         0051bb3d     PUSH       this
    //         0051bb3e     PUSH       EDX=>DAT_fffffff8
    //         0051bb3f     PUSH       offset DAT_fffffff4
    //         0051bb41     PUSH       offset DAT_fffffff0
    //         0051bb43     PUSH       0x0
    //         0051bb45     MOV        this,EBP
    //         0051bb47     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:399 (5)
    //         0051bb4d     MOV        ESI,0x1
    //                               LAB_0051bb52                                                 XREF[1]:     0051bb1f(j)  
    //                              tpnl_obj.cpp:411 (24)
    //         0051bb52     MOV        this,dword ptr [EBP + 0x114]
    //         0051bb58     LEA        EDX,[ESP + 0x16]
    //         0051bb5c     PUSH       EDX
    //         0051bb5d     LEA        EDX,[ESP + 0x14]
    //         0051bb61     MOV        EAX,dword ptr [this->_padding_]
    //         0051bb63     PUSH       EDX=>DAT_fffffff8
    //         0051bb64     CALL       dword ptr [EAX + 0x22c]
    //                              tpnl_obj.cpp:414 (32)
    //         0051bb6a     MOV        this,dword ptr [ESP + 0x10]
    //         0051bb6e     TEST       this,this
    //         0051bb71     JG         LAB_0051bb8a
    //         0051bb73     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051bb79     MOV        EDX,dword ptr [EAX + 0x8]
    //         0051bb7c     MOV        AL,byte ptr [EDX + 0x8f]
    //         0051bb82     CMP        AL,0x4
    //         0051bb84     JZ         LAB_0051bb8a
    //         0051bb86     CMP        AL,0x6
    //         0051bb88     JNZ        LAB_0051bba2
    //                               LAB_0051bb8a                                                 XREF[2]:     0051bb71(j), 0051bb84(j)  
    //                              tpnl_obj.cpp:416 (23)
    //         0051bb8a     MOVSX      EAX,this
    //         0051bb8d     MOVSX      this,word ptr [ESP + 0x16]
    //         0051bb92     PUSH       EAX
    //         0051bb93     PUSH       this=>DAT_fffffff8
    //         0051bb94     PUSH       offset DAT_fffffff4
    //         0051bb96     PUSH       offset DAT_fffffff0
    //         0051bb98     PUSH       ESI
    //         0051bb99     MOV        this,EBP
    //         0051bb9b     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:417 (1)
    //         0051bba1     INC        ESI
    //                               LAB_0051bba2                                                 XREF[1]:     0051bb88(j)  
    //                              tpnl_obj.cpp:421 (24)
    //         0051bba2     MOV        this,dword ptr [EBP + 0x114]
    //         0051bba8     LEA        EAX,[ESP + 0x16]
    //         0051bbac     PUSH       EAX
    //         0051bbad     LEA        EAX,[ESP + 0x14]
    //         0051bbb1     MOV        EDX,dword ptr [this->_padding_]
    //         0051bbb3     PUSH       EAX=>DAT_fffffff8
    //         0051bbb4     CALL       dword ptr [EDX + 0x244]
    //                              tpnl_obj.cpp:422 (9)
    //         0051bbba     MOV        EAX,dword ptr [ESP + 0x10]
    //         0051bbbe     TEST       AX,AX
    //         0051bbc1     JLE        LAB_0051bbdb
    //                              tpnl_obj.cpp:424 (23)
    //         0051bbc3     MOVSX      EDX,word ptr [ESP + 0x16]
    //         0051bbc8     MOVSX      this,AX
    //         0051bbcb     PUSH       this
    //         0051bbcc     PUSH       EDX=>DAT_fffffff8
    //         0051bbcd     PUSH       offset DAT_fffffff4
    //         0051bbcf     PUSH       offset DAT_fffffff0
    //         0051bbd1     PUSH       ESI
    //         0051bbd2     MOV        this,EBP
    //         0051bbd4     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:425 (1)
    //         0051bbda     INC        ESI
    //                               LAB_0051bbdb                                                 XREF[1]:     0051bbc1(j)  
    //                              tpnl_obj.cpp:430 (23)
    //         0051bbdb     MOV        this,dword ptr [EBP + 0x114]
    //         0051bbe1     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051bbe4     MOV        AL,byte ptr [EAX + 0x8f]
    //         0051bbea     CMP        AL,0x4
    //         0051bbec     JZ         LAB_0051bbf2
    //         0051bbee     CMP        AL,0x6
    //         0051bbf0     JNZ        LAB_0051bc37
    //                               LAB_0051bbf2                                                 XREF[1]:     0051bbec(j)  
    //                              tpnl_obj.cpp:432 (18)
    //         0051bbf2     MOV        EDX,dword ptr [this->_padding_]
    //         0051bbf4     LEA        EAX,[ESP + 0x34]
    //         0051bbf8     PUSH       EAX
    //         0051bbf9     LEA        EAX,[ESP + 0x2c]
    //         0051bbfd     PUSH       EAX=>DAT_fffffff8
    //         0051bbfe     CALL       dword ptr [EDX + 0x234]
    //                              tpnl_obj.cpp:433 (17)
    //         0051bc04     FLD        float ptr [ESP + 0x28]
    //         0051bc08     FCOMP      float ptr [DAT_00576dac]                         = A4h
    //         0051bc0e     FNSTSW     AX
    //         0051bc10     TEST       AH,0x41
    //         0051bc13     JNZ        LAB_0051bc37
    //                              tpnl_obj.cpp:435 (33)
    //         0051bc15     FLD        float ptr [ESP + 0x28]
    //         0051bc19     CALL       __ftol                                           undefined __ftol()
    //         0051bc1e     FLD        float ptr [ESP + 0x34]
    //         0051bc22     PUSH       EAX
    //         0051bc23     CALL       __ftol                                           undefined __ftol()
    //         0051bc28     PUSH       EAX=>DAT_fffffff8
    //         0051bc29     PUSH       offset DAT_fffffff4
    //         0051bc2b     PUSH       offset DAT_fffffff0
    //         0051bc2d     PUSH       ESI
    //         0051bc2e     MOV        this,EBP
    //         0051bc30     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:436 (1)
    //         0051bc36     INC        ESI
    //                               LAB_0051bc37                                                 XREF[2]:     0051bbf0(j), 0051bc13(j)  
    //                              tpnl_obj.cpp:441 (18)
    //         0051bc37     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051bc3d     MOV        this,dword ptr [EAX + 0x8]
    //         0051bc40     CMP        byte ptr [ECX + this+0x8f],0x6
    //         0051bc47     JNZ        LAB_0051bc68
    //                              tpnl_obj.cpp:443 (30)
    //         0051bc49     FLD        float ptr [EAX + 0x44]
    //         0051bc4c     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051bc52     PUSH       0x0
    //         0051bc54     CALL       __ftol                                           undefined __ftol()
    //         0051bc59     PUSH       EAX=>DAT_fffffff8
    //         0051bc5a     PUSH       offset DAT_fffffff4
    //         0051bc5c     PUSH       offset DAT_fffffff0
    //         0051bc5e     PUSH       ESI
    //         0051bc5f     MOV        this,EBP
    //         0051bc61     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:444 (1)
    //         0051bc67     INC        ESI
    //                               LAB_0051bc68                                                 XREF[1]:     0051bc47(j)  
    //                              tpnl_obj.cpp:448 (23)
    //         0051bc68     MOV        EDI,dword ptr [EBP + 0x114]
    //         0051bc6e     MOV        EAX,dword ptr [EBP + 0x110]
    //         0051bc74     MOV        EDX,dword ptr [EDI + 0xc]
    //         0051bc77     CMP        EDX,EAX
    //         0051bc79     JNZ        LAB_0051be67
    //                              tpnl_obj.cpp:450 (14)
    //         0051bc7f     MOV        EAX,dword ptr [EDI + 0x8]
    //         0051bc82     MOV        this,byte ptr [EAX + 0x8f]
    //         0051bc88     CMP        this,0x7
    //         0051bc8b     JNZ        LAB_0051bcbc
    //                              tpnl_obj.cpp:452 (27)
    //         0051bc8d     MOV        EDX,dword ptr [EDI + 0x24]
    //         0051bc90     XOR        this,this
    //         0051bc92     MOV        this,byte ptr [EAX + 0x2c]
    //         0051bc95     MOVSX      EAX,word ptr [EDX + 0x8]
    //         0051bc99     PUSH       this
    //         0051bc9a     PUSH       EAX=>DAT_fffffff8
    //         0051bc9b     PUSH       offset DAT_fffffff4
    //         0051bc9d     PUSH       offset DAT_fffffff0
    //         0051bc9f     PUSH       ESI
    //         0051bca0     MOV        this,EBP
    //         0051bca2     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:734 (9)
    //         0051bca8     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051bcac     MOV        this,EBP
    //         0051bcae     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051bcb1     POP        EDI
    //         0051bcb2     POP        ESI
    //         0051bcb3     POP        EBP
    //         0051bcb4     POP        EBX
    //         0051bcb5     ADD        ESP,0x158
    //         0051bcbb     RET
    //                               LAB_0051bcbc                                                 XREF[1]:     0051bc8b(j)  
    //                              tpnl_obj.cpp:455 (5)
    //         0051bcbc     CMP        this,0x9
    //         0051bcbf     JNZ        LAB_0051bd0d
    //                              tpnl_obj.cpp:457 (15)
    //         0051bcc1     MOV        AX,word ptr [EDI + 0x4c]
    //         0051bcc5     CMP        AX,0x11
    //         0051bcc9     JZ         LAB_0051bcd4
    //         0051bccb     TEST       AX,AX
    //         0051bcce     JZ         LAB_0051bcd4
    //                              tpnl_obj.cpp:460 (4)
    //         0051bcd0     XOR        EAX,EAX
    //         0051bcd2     JMP        LAB_0051bce2
    //                               LAB_0051bcd4                                                 XREF[2]:     0051bcc9(j), 0051bcce(j)  
    //                              tpnl_obj.cpp:458 (14)
    //         0051bcd4     FLD        float ptr [EDI + 0x44]
    //         0051bcd7     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051bcdd     CALL       __ftol                                           undefined __ftol()
    //                               LAB_0051bce2                                                 XREF[1]:     0051bcd2(j)  
    //                              tpnl_obj.cpp:461 (23)
    //         0051bce2     MOVSX      this,AX
    //         0051bce5     PUSH       0x0
    //         0051bce7     PUSH       this=>DAT_fffffff8
    //         0051bce8     PUSH       0x0=>DAT_fffffff4
    //         0051bcea     PUSH       offset DAT_fffffff0
    //         0051bcec     PUSH       ESI
    //         0051bced     MOV        this,EBP
    //         0051bcef     MOV        dword ptr [ESP + 0x24],EAX
    //         0051bcf3     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:734 (9)
    //         0051bcf9     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051bcfd     MOV        this,EBP
    //         0051bcff     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051bd02     POP        EDI
    //         0051bd03     POP        ESI
    //         0051bd04     POP        EBP
    //         0051bd05     POP        EBX
    //         0051bd06     ADD        ESP,0x158
    //         0051bd0c     RET
    //                               LAB_0051bd0d                                                 XREF[1]:     0051bcbf(j)  
    //                              tpnl_obj.cpp:465 (9)
    //         0051bd0d     CMP        this,0x5
    //         0051bd10     JNZ        LAB_0051bdc5
    //                              tpnl_obj.cpp:467 (28)
    //         0051bd16     MOVSX      EAX,word ptr [EDI + 0x4c]
    //         0051bd1a     CMP        EAX,0x11
    //         0051bd1d     JA         switchD_0051b6bc::caseD_4
    //         0051bd23     XOR        EDX,EDX
    //         0051bd25     MOV        DL,byte ptr [EAX + switchD_0051bd2b::switchdat
    //                               switchD_0051bd2b::switchD
    //         0051bd2b     JMP        dword ptr [EDX*0x4 + switchD_0051bd2b::switchd   = 0051bd32
    //                               switchD_0051bd2b::caseD_f                                    XREF[3]:     0051bd2b(j), 0051bf2c(*), 
    //                               switchD_0051bd2b::caseD_10                                                0051bf40(*)  
    //                               switchD_0051bd2b::caseD_11
    //                               switchD_0051bd2b::caseD_0
    //                              tpnl_obj.cpp:472 (7)
    //         0051bd32     MOV        this,0x2
    //         0051bd37     JMP        LAB_0051bd50
    //                               switchD_0051bd2b::caseD_1                                    XREF[2]:     0051bd2b(j), 0051bf30(*)  
    //                              tpnl_obj.cpp:473 (4)
    //         0051bd39     XOR        this,this
    //         0051bd3b     JMP        LAB_0051bd50
    //                               switchD_0051bd2b::caseD_2                                    XREF[2]:     0051bd2b(j), 0051bf34(*)  
    //                              tpnl_obj.cpp:474 (7)
    //         0051bd3d     MOV        this,0x1
    //         0051bd42     JMP        LAB_0051bd50
    //                               switchD_0051bd2b::caseD_3                                    XREF[2]:     0051bd2b(j), 0051bf38(*)  
    //                              tpnl_obj.cpp:475 (7)
    //         0051bd44     MOV        this,0x3
    //         0051bd49     JMP        LAB_0051bd50
    //                               switchD_0051bd2b::caseD_9                                    XREF[2]:     0051bd2b(j), 0051bf3c(*)  
    //                              tpnl_obj.cpp:476 (9)
    //         0051bd4b     MOV        this,0x5
    //                               LAB_0051bd50                                                 XREF[4]:     0051bd37(j), 0051bd3b(j), 
    //                                                                                                         0051bd42(j), 0051bd49(j)  
    //         0051bd50     MOV        dword ptr [ESP + 0x10],this
    //                              tpnl_obj.cpp:481 (16)
    //         0051bd54     FLD        float ptr [EDI + 0x44]
    //         0051bd57     FCOMP      double ptr [DAT_00576db0]
    //         0051bd5d     FNSTSW     AX
    //         0051bd5f     TEST       AH,0x41
    //         0051bd62     JNZ        LAB_0051bd9e
    //                              tpnl_obj.cpp:483 (8)
    //         0051bd64     MOV        dword ptr [ESP + 0x10],0x3
    //                              tpnl_obj.cpp:484 (30)
    //         0051bd6c     PUSH       0x0
    //         0051bd6e     FLD        float ptr [EDI + 0x44]
    //         0051bd71     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051bd77     CALL       __ftol                                           undefined __ftol()
    //         0051bd7c     PUSH       EAX=>DAT_fffffff8
    //         0051bd7d     PUSH       0x0=>DAT_fffffff4
    //         0051bd7f     PUSH       offset DAT_fffffff0
    //         0051bd81     PUSH       ESI
    //         0051bd82     MOV        this,EBP
    //         0051bd84     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:734 (9)
    //         0051bd8a     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051bd8e     MOV        this,EBP
    //         0051bd90     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051bd93     POP        EDI
    //         0051bd94     POP        ESI
    //         0051bd95     POP        EBP
    //         0051bd96     POP        EBX
    //         0051bd97     ADD        ESP,0x158
    //         0051bd9d     RET
    //                               LAB_0051bd9e                                                 XREF[1]:     0051bd62(j)  
    //                              tpnl_obj.cpp:487 (19)
    //         0051bd9e     MOVSX      EAX,this
    //         0051bda1     PUSH       0x0
    //         0051bda3     PUSH       offset DAT_fffffff8
    //         0051bda5     PUSH       offset DAT_fffffff4
    //         0051bda7     PUSH       EAX=>DAT_fffffff0
    //         0051bda8     PUSH       ESI
    //         0051bda9     MOV        this,EBP
    //         0051bdab     CALL       dword ptr [EBX + 0xe0]
    //                              tpnl_obj.cpp:734 (9)
    //         0051bdb1     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051bdb5     MOV        this,EBP
    //         0051bdb7     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051bdba     POP        EDI
    //         0051bdbb     POP        ESI
    //         0051bdbc     POP        EBP
    //         0051bdbd     POP        EBX
    //         0051bdbe     ADD        ESP,0x158
    //         0051bdc4     RET
    //                               LAB_0051bdc5                                                 XREF[1]:     0051bd10(j)  
    //                              tpnl_obj.cpp:491 (22)
    //         0051bdc5     FLD        float ptr [EDI + 0x44]
    //         0051bdc8     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051bdce     CALL       __ftol                                           undefined __ftol()
    //         0051bdd3     TEST       EAX,EAX
    //         0051bdd5     JLE        LAB_0051be67
    //                              tpnl_obj.cpp:493 (24)
    //         0051bddb     MOVSX      EAX,word ptr [EDI + 0x4c]
    //         0051bddf     CMP        EAX,0x11
    //         0051bde2     JA         switchD_0051b6bc::caseD_4
    //         0051bde4     XOR        this,this
    //         0051bde6     MOV        this,byte ptr [EAX + switchD_0051bdec::switchd
    //                               switchD_0051bdec::switchD
    //         0051bdec     JMP        dword ptr [this->_padding_*0x4 + switchD_0051b   = 0051bdf3
    //                               switchD_0051bdec::caseD_f                                    XREF[3]:     0051bdec(j), 0051bf5c(*), 
    //                               switchD_0051bdec::caseD_10                                                0051bf70(*)  
    //                               switchD_0051bdec::caseD_11
    //                               switchD_0051bdec::caseD_0
    //                              tpnl_obj.cpp:498 (11)
    //         0051bdf3     MOV        EBX,0x2
    //         0051bdf8     MOV        dword ptr [ESP + 0x10],EBX
    //         0051bdfc     JMP        LAB_0051be43
    //                               switchD_0051bdec::caseD_1                                    XREF[2]:     0051bdec(j), 0051bf60(*)  
    //                              tpnl_obj.cpp:499 (8)
    //         0051bdfe     XOR        EBX,EBX
    //         0051be00     MOV        dword ptr [ESP + 0x10],EBX
    //         0051be04     JMP        LAB_0051be43
    //                               switchD_0051bdec::caseD_2                                    XREF[2]:     0051bdec(j), 0051bf64(*)  
    //                              tpnl_obj.cpp:500 (11)
    //         0051be06     MOV        EBX,0x1
    //         0051be0b     MOV        dword ptr [ESP + 0x10],EBX
    //         0051be0f     JMP        LAB_0051be43
    //                               switchD_0051bdec::caseD_3                                    XREF[2]:     0051bdec(j), 0051bf68(*)  
    //                              tpnl_obj.cpp:501 (11)
    //         0051be11     MOV        EBX,0x3
    //         0051be16     MOV        dword ptr [ESP + 0x10],EBX
    //         0051be1a     JMP        LAB_0051be43
    //                               switchD_0051bdec::caseD_9                                    XREF[2]:     0051bdec(j), 0051bf6c(*)  
    //                              tpnl_obj.cpp:502 (11)
    //         0051be1c     MOV        EBX,0x5
    //         0051be21     MOV        dword ptr [ESP + 0x10],EBX
    //         0051be25     JMP        LAB_0051be43
    //                               switchD_0051b6bc::caseD_5                                    XREF[9]:     0051b6ae(j), 0051b6bc(j), 
    //                               switchD_0051b6bc::caseD_6                                                 0051bd1d(j), 0051bd2b(j), 
    //                               switchD_0051b6bc::caseD_7                                                 0051bde2(j), 0051bdec(j), 
    //                               switchD_0051b6bc::caseD_8                                                 0051bee4(*), 0051bf44(*), 
    //                               switchD_0051b6bc::caseD_a                                                 0051bf74(*)  
    //                               switchD_0051b6bc::caseD_b
    //                               switchD_0051b6bc::caseD_c
    //                               switchD_0051b6bc::caseD_d
    //                               switchD_0051b6bc::caseD_e
    //                               switchD_0051bd2b::caseD_4
    //                               switchD_0051bd2b::caseD_5
    //                               switchD_0051bd2b::caseD_6
    //                               switchD_0051bd2b::caseD_7
    //                               switchD_0051bd2b::caseD_8
    //                               switchD_0051bd2b::caseD_a
    //                               switchD_0051bd2b::caseD_b
    //                               switchD_0051bd2b::caseD_c
    //                               switchD_0051bd2b::caseD_d
    //                               switchD_0051bd2b::caseD_e
    //                               switchD_0051bdec::caseD_4
    //                               switchD_0051bdec::caseD_5
    //                               switchD_0051bdec::caseD_6
    //                               switchD_0051bdec::caseD_7
    //                               switchD_0051bdec::caseD_8
    //                               switchD_0051bdec::caseD_a
    //                               switchD_0051bdec::caseD_b
    //                               switchD_0051bdec::caseD_c
    //                               switchD_0051bdec::caseD_d
    //                               switchD_0051bdec::caseD_e
    //                               switchD_0051b6bc::caseD_4
    //                              tpnl_obj.cpp:734 (17)
    //         0051be27     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051be2b     MOV        this,EBP
    //         0051be2d     MOV        dword ptr [ESP + 0x10],0xffffffff
    //         0051be35     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051be38     POP        EDI
    //         0051be39     POP        ESI
    //         0051be3a     POP        EBP
    //         0051be3b     POP        EBX
    //         0051be3c     ADD        ESP,0x158
    //         0051be42     RET
    //                               LAB_0051be43                                                 XREF[5]:     0051bdfc(j), 0051be04(j), 
    //                                                                                                         0051be0f(j), 0051be1a(j), 
    //                                                                                                         0051be25(j)  
    //                              tpnl_obj.cpp:507 (36)
    //         0051be43     FLD        float ptr [EDI + 0x44]
    //         0051be46     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051be4c     PUSH       0x0
    //         0051be4e     CALL       __ftol                                           undefined __ftol()
    //         0051be53     MOVSX      EDX,BX
    //         0051be56     PUSH       EAX=>DAT_fffffff8
    //         0051be57     PUSH       0x0=>DAT_fffffff4
    //         0051be59     PUSH       EDX=>DAT_fffffff0
    //                               LAB_0051be5a                                                 XREF[1]:     0051bb14(j)  
    //         0051be5a     MOV        EAX,dword ptr [ESP + 0x28]
    //         0051be5e     PUSH       ESI
    //         0051be5f     MOV        this,EBP
    //         0051be61     CALL       dword ptr [EAX + 0xe0]
    //                               LAB_0051be67                                                 XREF[6]:     0051b720(j), 0051ba4a(j), 
    //                                                                                                         0051ba5b(j), 0051ba85(j), 
    //                                                                                                         0051bc79(j), 0051bdd5(j)  
    //                              tpnl_obj.cpp:734 (9)
    //         0051be67     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051be6b     MOV        this,EBP
    //         0051be6d     CALL       dword ptr [EDX + 0x2c]
    //                              tpnl_obj.cpp:735 (11)
    //         0051be70     POP        EDI
    //         0051be71     POP        ESI
    //         0051be72     POP        EBP
    //         0051be73     POP        EBX
    //         0051be74     ADD        ESP,0x158
    //         0051be7a     RET
    //                               LAB_0051be7b                                                 XREF[4]:     0051b1a1(j), 0051b1aa(j), 
    //                                                                                                         0051b1b3(j), 0051b1df(j)  
    //                              tpnl_obj.cpp:219 (3)
    //         0051be7b     MOV        dword ptr [EBP + 0x38],ESI
    //                              tpnl_obj.cpp:735 (11)
    //         0051be7e     POP        EDI
    //         0051be7f     POP        ESI
    //         0051be80     POP        EBP
    //         0051be81     POP        EBX
    //         0051be82     ADD        ESP,0x158
    //         0051be88     RET
    //                               switchD_0051b9d3::caseD_1                                    XREF[2]:     0051b9d3(j), 0051bf00(*)  
    //                              tpnl_obj.cpp:665 (11)
    //         0051be89     XOR        EBX,EBX
    //         0051be8b     MOV        dword ptr [ESP + 0x10],EBX
    //         0051be8f     JMP        LAB_0051b9e3
    //                               switchD_0051b9d3::caseD_2                                    XREF[2]:     0051b9d3(j), 0051bf04(*)  
    //                              tpnl_obj.cpp:666 (14)
    //         0051be94     MOV        EBX,0x1
    //         0051be99     MOV        dword ptr [ESP + 0x10],EBX
    //         0051be9d     JMP        LAB_0051b9e3
    //                               switchD_0051b9d3::caseD_3                                    XREF[2]:     0051b9d3(j), 0051bf08(*)  
    //                              tpnl_obj.cpp:667 (14)
    //         0051bea2     MOV        EBX,0x3
    //         0051bea7     MOV        dword ptr [ESP + 0x10],EBX
    //         0051beab     JMP        LAB_0051b9e3
    //                               switchD_0051b9d3::caseD_9                                    XREF[2]:     0051b9d3(j), 0051bf0c(*)  
    //                              tpnl_obj.cpp:668 (14)
    //         0051beb0     MOV        EBX,0x5
    //         0051beb5     MOV        dword ptr [ESP + 0x10],EBX
    //         0051beb9     JMP        LAB_0051b9e3
    //                               switchD_0051b9d3::caseD_5                                    XREF[3]:     0051b9c5(j), 0051b9d3(j), 
    //                               switchD_0051b9d3::caseD_6                                                 0051bf14(*)  
    //                               switchD_0051b9d3::caseD_7
    //                               switchD_0051b9d3::caseD_8
    //                               switchD_0051b9d3::caseD_a
    //                               switchD_0051b9d3::caseD_b
    //                               switchD_0051b9d3::caseD_c
    //                               switchD_0051b9d3::caseD_d
    //                               switchD_0051b9d3::caseD_e
    //                               switchD_0051b9d3::caseD_4
    //                              tpnl_obj.cpp:669 (8)
    //         0051bebe     MOV        dword ptr [ESP + 0x10],0xffffffff
    //                              tpnl_obj.cpp:671 (5)
    //         0051bec6     JMP        LAB_0051ba3c
    //                              tpnl_obj.cpp:735 (191)
}

// Offset: 0x0051BF90
void draw_score(TRIBE_Panel_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TRIBE_Panel_Object::draw_score(void)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_score(TRIBE_Panel_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              char[100]         Stack[-0x68]   str
    //              tagRECT           Stack[-0x78]   rect
    //              short             Stack[-0x7c]:2 y
    //              short             Stack[-0x80]:2 x                         XREF[1]:     0051bfbe(W)  
    //              RGE_Player *      Stack[-0x88]:4 temp_player
    //              void *            Stack[-0x8c]:4 old_font
    //              short             Stack[-0x90]:2 x_val
    //              int               Stack[-0x98]:4 i
    //                               ?draw_score@TRIBE_Panel_Object@@IAEXXZ                       XREF[2]:     draw:004beea2(c), 
    //                               TRIBE_Panel_Object::draw_score                                            draw:0051b1c2(c)  
    //                              tpnl_obj.cpp:741 (10)
    //         0051bf90     SUB        ESP,0x94
    //         0051bf96     PUSH       EBX
    //         0051bf97     MOV        EBX,this
    //         0051bf99     PUSH       EBP
    //                              tpnl_obj.cpp:753 (33)
    //         0051bf9a     XOR        EBP,EBP
    //         0051bf9c     MOV        EAX,dword ptr [EBX + 0x20]
    //         0051bf9f     PUSH       ESI
    //         0051bfa0     CMP        EAX,EBP
    //         0051bfa2     PUSH       EDI
    //         0051bfa3     JZ         LAB_0051c1e8
    //         0051bfa9     CMP        dword ptr [EBX + 0x70],EBP
    //         0051bfac     JZ         LAB_0051c1e8
    //         0051bfb2     CMP        dword ptr [EBX + 0x6c],EBP
    //         0051bfb5     JZ         LAB_0051c1e8
    //                              tpnl_obj.cpp:759 (10)
    //         0051bfbb     MOV        ESI,dword ptr [EBX]
    //         0051bfbd     PUSH       EBP
    //         0051bfbe     MOV        dword ptr [ESP + x],ESI
    //         0051bfc2     CALL       dword ptr [ESI + 0x28]
    //                              tpnl_obj.cpp:761 (13)
    //         0051bfc5     MOV        this,dword ptr [EBX + 0x20]
    //         0051bfc8     LEA        EAX,[EBX + 0x24]
    //         0051bfcb     PUSH       EBP
    //         0051bfcc     PUSH       EAX
    //         0051bfcd     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              tpnl_obj.cpp:763 (21)
    //         0051bfd2     MOV        this,dword ptr [EBX + 0x20]
    //         0051bfd5     PUSH       s_tpnl_obj::draw_score                           = "tpnl_obj::draw_score"
    //         0051bfda     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0051bfdf     TEST       EAX,EAX
    //         0051bfe1     JZ         LAB_0051c1d8
    //                              tpnl_obj.cpp:765 (15)
    //         0051bfe7     MOV        this,dword ptr [EBX + 0x20]
    //         0051bfea     PUSH       0x1
    //         0051bfec     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051bfef     PUSH       EDX
    //         0051bff0     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_obj.cpp:766 (18)
    //         0051bff6     MOV        EAX,dword ptr [EBX + 0x20]
    //         0051bff9     PUSH       0xffffff
    //         0051bffe     MOV        this,dword ptr [EAX + 0x38]
    //         0051c001     PUSH       this
    //         0051c002     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_obj.cpp:768 (24)
    //         0051c008     MOV        EAX,dword ptr [EBX + 0x20]
    //         0051c00b     MOV        EDX,dword ptr [EBX + 0xf4]
    //         0051c011     PUSH       EDX
    //         0051c012     MOV        this,dword ptr [EAX + 0x38]
    //         0051c015     PUSH       this
    //         0051c016     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //         0051c01c     MOV        dword ptr [ESP + 0x1c],EAX
    //                              tpnl_obj.cpp:770 (4)
    //         0051c020     MOV        AX,word ptr [EBX + 0xc]
    //                              tpnl_obj.cpp:775 (33)
    //         0051c024     MOV        ESI,0x1
    //         0051c029     LEA        EDX,[EAX + 0x3]
    //         0051c02c     ADD        EAX,0x5a
    //         0051c02f     MOV        dword ptr [ESP + 0x18],EAX
    //         0051c033     MOV        AX,word ptr [EBX + 0x10]
    //         0051c037     DEC        AX
    //         0051c039     MOV        dword ptr [ESP + 0x28],EDX
    //         0051c03d     MOV        dword ptr [ESP + 0x2c],EAX
    //         0051c041     MOV        dword ptr [ESP + 0x10],ESI
    //                               LAB_0051c045                                                 XREF[1]:     0051c1af(j)  
    //                              tpnl_obj.cpp:777 (12)
    //         0051c045     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051c04b     PUSH       ESI
    //         0051c04c     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //                              tpnl_obj.cpp:778 (32)
    //         0051c051     TEST       EAX,EAX
    //         0051c053     JZ         LAB_0051c1a7
    //         0051c059     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051c05f     MOV        this,dword ptr [this->_padding_ + 0x3f4]
    //         0051c065     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0051c069     CMP        EAX,EDX
    //         0051c06b     JGE        LAB_0051c1a7
    //                              tpnl_obj.cpp:781 (10)
    //         0051c071     MOV        this,dword ptr [ECX + this->_padding_]
    //         0051c074     MOV        EAX,dword ptr [this->_padding_ + EAX*0x4]
    //         0051c077     MOV        dword ptr [ESP + 0x20],EAX
    //                              tpnl_obj.cpp:783 (22)
    //         0051c07b     MOV        EDX,dword ptr [EAX + 0x108]
    //         0051c081     MOVSX      EAX,word ptr [EDX + 0x26]
    //         0051c085     CMP        EAX,0x7
    //         0051c088     JA         switchD_0051c08a::default
    //                               switchD_0051c08a::switchD
    //         0051c08a     JMP        dword ptr [EAX*0x4 + switchD_0051c08a::switchd   = 0051c091
    //                               switchD_0051c08a::caseD_0                                    XREF[2]:     0051c08a(j), 0051c1f8(*)  
    //                              tpnl_obj.cpp:785 (7)
    //         0051c091     MOV        EAX,0xff0000
    //         0051c096     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_1                                    XREF[2]:     0051c08a(j), 0051c1fc(*)  
    //                              tpnl_obj.cpp:786 (7)
    //         0051c098     MOV        EAX,0x2139c6
    //         0051c09d     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_2                                    XREF[2]:     0051c08a(j), 0051c200(*)  
    //                              tpnl_obj.cpp:787 (7)
    //         0051c09f     MOV        EAX,0xffff
    //         0051c0a4     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_3                                    XREF[2]:     0051c08a(j), 0051c204(*)  
    //                              tpnl_obj.cpp:788 (7)
    //         0051c0a6     MOV        EAX,0x4f73a3
    //         0051c0ab     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_4                                    XREF[2]:     0051c08a(j), 0051c208(*)  
    //                              tpnl_obj.cpp:789 (7)
    //         0051c0ad     MOV        EAX,0xf77f3
    //         0051c0b2     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_5                                    XREF[2]:     0051c08a(j), 0051c20c(*)  
    //                              tpnl_obj.cpp:790 (7)
    //         0051c0b4     MOV        EAX,0xc700
    //         0051c0b9     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_6                                    XREF[2]:     0051c08a(j), 0051c210(*)  
    //                              tpnl_obj.cpp:791 (7)
    //         0051c0bb     MOV        EAX,pathSystem.MGP_openPaths[14537].total+2
    //         0051c0c0     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::caseD_7                                    XREF[2]:     0051c08a(j), 0051c214(*)  
    //                              tpnl_obj.cpp:792 (7)
    //         0051c0c2     MOV        EAX,0xadad00
    //         0051c0c7     JMP        LAB_0051c0ce
    //                               switchD_0051c08a::default                                    XREF[1]:     0051c088(j)  
    //                              tpnl_obj.cpp:793 (5)
    //         0051c0c9     MOV        EAX,0xffffff
    //                               LAB_0051c0ce                                                 XREF[8]:     0051c096(j), 0051c09d(j), 
    //                                                                                                         0051c0a4(j), 0051c0ab(j), 
    //                                                                                                         0051c0b2(j), 0051c0b9(j), 
    //                                                                                                         0051c0c0(j), 0051c0c7(j)  
    //                              tpnl_obj.cpp:796 (14)
    //         0051c0ce     PUSH       EAX=>pathSystem.MGP_openPaths[14537].total+2
    //         0051c0cf     MOV        EAX,dword ptr [EBX + 0x20]
    //         0051c0d2     MOV        this,dword ptr [EAX + 0x38]
    //         0051c0d5     PUSH       this
    //         0051c0d6     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_obj.cpp:798 (42)
    //         0051c0dc     MOV        this,dword ptr [comm]                            = 00000000
    //         0051c0e2     PUSH       ESI
    //         0051c0e3     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler 
    //         0051c0e8     MOV        EDI,EAX
    //         0051c0ea     OR         this,0xffffffff
    //         0051c0ed     XOR        EAX,EAX
    //         0051c0ef     LEA        EDX,[ESP + 0x40]
    //         0051c0f3     SCASB.RE   ES:EDI
    //         0051c0f5     NOT        this
    //         0051c0f7     SUB        EDI,this
    //         0051c0f9     MOV        EAX,this
    //         0051c0fb     MOV        ESI,EDI
    //         0051c0fd     MOV        EDI,EDX
    //         0051c0ff     SHR        this,0x2
    //         0051c102     MOVSD.REP  ES:EDI,ESI
    //         0051c104     MOV        this,EAX
    //                              tpnl_obj.cpp:799 (58)
    //         0051c106     XOR        EAX,EAX
    //         0051c108     AND        this,0x3
    //         0051c10b     MOVSB.REP  ES:EDI,ESI
    //         0051c10d     LEA        EDI,[ESP + 0x40]
    //         0051c111     OR         this,0xffffffff
    //         0051c114     SCASB.RE   ES:EDI
    //         0051c116     MOVSX      ESI,word ptr [ESP + 0x2c]
    //         0051c11b     NOT        this
    //         0051c11d     MOV        EAX,dword ptr [EBX + 0x20]
    //         0051c120     DEC        this
    //         0051c121     PUSH       this
    //         0051c122     LEA        this,[ESP + 0x44]
    //         0051c126     LEA        EDX,[EBP + ESI*0x1]
    //         0051c12a     PUSH       this
    //         0051c12b     MOV        this,dword ptr [EAX + 0x38]
    //         0051c12e     MOV        dword ptr [ESP + 0x1c],EDX
    //         0051c132     PUSH       EDX
    //         0051c133     MOVSX      EDX,word ptr [ESP + 0x34]
    //         0051c138     PUSH       EDX
    //         0051c139     PUSH       this
    //         0051c13a     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_obj.cpp:801 (28)
    //         0051c140     MOV        EDX,dword ptr [ESP + 0x20]
    //         0051c144     MOV        this,dword ptr [EDX + 0x34]
    //         0051c147     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //         0051c14c     PUSH       EAX
    //         0051c14d     LEA        EAX,[ESP + 0x44]
    //         0051c151     PUSH       s_%d                                             = 6425h
    //         0051c156     PUSH       EAX
    //         0051c157     CALL       sprintf                                          undefined sprintf()
    //                              tpnl_obj.cpp:803 (41)
    //         0051c15c     MOV        EDX,dword ptr [EBX + 0x14]
    //         0051c15f     MOV        EAX,dword ptr [EBX + 0xc]
    //         0051c162     ADD        ESP,0xc
    //         0051c165     LEA        this,[EBP + ESI*0x1 + 0xe]
    //         0051c169     PUSH       this
    //         0051c16a     LEA        this,[EDX + EAX*0x1 + -0x3]
    //         0051c16e     MOVSX      EAX,word ptr [ESP + 0x1c]
    //         0051c173     MOV        EDX,dword ptr [ESP + 0x18]
    //         0051c177     PUSH       this
    //         0051c178     PUSH       EDX
    //         0051c179     LEA        this,[ESP + 0x3c]
    //         0051c17d     PUSH       EAX
    //         0051c17e     PUSH       this
    //         0051c17f     CALL       dword ptr [->USER32.DLL::SetRect]                = 0048b002
    //                              tpnl_obj.cpp:804 (27)
    //         0051c185     MOV        this,dword ptr [EBX + 0x20]
    //         0051c188     LEA        EDX,[ESP + 0x30]
    //         0051c18c     PUSH       0x22
    //         0051c18e     PUSH       EDX
    //         0051c18f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051c192     LEA        EAX,[ESP + 0x48]
    //         0051c196     PUSH       -0x1
    //         0051c198     PUSH       EAX
    //         0051c199     PUSH       EDX
    //         0051c19a     CALL       dword ptr [->USER32.DLL::DrawTextA]              = 0048b10a
    //                              tpnl_obj.cpp:806 (21)
    //         0051c1a0     MOV        ESI,dword ptr [ESP + 0x10]
    //         0051c1a4     ADD        EBP,0xe
    //                               LAB_0051c1a7                                                 XREF[2]:     0051c053(j), 0051c06b(j)  
    //         0051c1a7     INC        ESI
    //         0051c1a8     CMP        ESI,0x9
    //         0051c1ab     MOV        dword ptr [ESP + 0x10],ESI
    //         0051c1af     JL         LAB_0051c045
    //                              tpnl_obj.cpp:809 (18)
    //         0051c1b5     MOV        this,dword ptr [EBX + 0x20]
    //         0051c1b8     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0051c1bc     PUSH       EAX
    //         0051c1bd     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051c1c0     PUSH       EDX
    //         0051c1c1     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              tpnl_obj.cpp:810 (17)
    //         0051c1c7     MOV        this,dword ptr [EBX + 0x20]
    //         0051c1ca     PUSH       s_tpnl_obj::draw_score                           = "tpnl_obj::draw_score"
    //         0051c1cf     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         0051c1d4     MOV        ESI,dword ptr [ESP + 0x24]
    //                               LAB_0051c1d8                                                 XREF[1]:     0051bfe1(j)  
    //                              tpnl_obj.cpp:813 (5)
    //         0051c1d8     MOV        this,EBX
    //         0051c1da     CALL       dword ptr [ESI + 0x2c]
    //                              tpnl_obj.cpp:814 (59)
    //         0051c1dd     POP        EDI
    //         0051c1de     POP        ESI
    //         0051c1df     POP        EBP
    //         0051c1e0     POP        EBX
    //         0051c1e1     ADD        ESP,0x94
    //         0051c1e7     RET
    //                               LAB_0051c1e8                                                 XREF[3]:     0051bfa3(j), 0051bfac(j), 
    //                                                                                                         0051bfb5(j)  
    //         0051c1e8     POP        EDI
    //         0051c1e9     MOV        dword ptr [EBX + 0x38],EBP
    //         0051c1ec     POP        ESI
    //         0051c1ed     POP        EBP
    //         0051c1ee     POP        EBX
    //         0051c1ef     ADD        ESP,0x94
    //         0051c1f5     RET
}

// Offset: 0x0051C1F6
undefined FUN_0051c1f6() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0051c1f6()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0051c1f6
    //         0051c1f6     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0051c08a::switchdataD_0051c1f8                       XREF[1]:     draw_score:0051c08a(*)  
}

// Offset: 0x0051C220
void TRIBE_Panel_Object::draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual void __thiscall TRIBE_Panel_Object::draw_item(int,int,enum TRIBE_Panel_Object::... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_item(TRIBE_Panel_Object * this, int param_1, in
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0051c24f(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     0051c233(R)  
    //              ValueType         Stack[0xc]:4   param_3                   XREF[1]:     0051c286(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[4]:     0051c29a(R), 0051c2b7(R), 0051c2f0(R), 0051c30a(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     0051c2b3(R), 0051c2ec(R)  
    //              char[20]          Stack[-0x18]   val_str                   XREF[0,7]:   0051c29e(*), 0051c2c3(*), 0051c2d8(*), 0051c2f6(*), 
    //                                                                                     0051c30e(*), 0051c323(W), 0051c328(R)  
    //                               ?draw_item@TRIBE_Panel_Object@@MAEXHHW4ValueType@1@HH@Z      XREF[1]:     00576d78(*)  
    //                               TRIBE_Panel_Object::draw_item
    //                              tpnl_obj.cpp:820 (9)
    //         0051c220     SUB        ESP,0x14
    //         0051c223     PUSH       EBX
    //         0051c224     PUSH       EBP
    //         0051c225     PUSH       ESI
    //         0051c226     MOV        ESI,this
    //         0051c228     PUSH       EDI
    //                              tpnl_obj.cpp:825 (38)
    //         0051c229     MOV        EAX,dword ptr [ESI + 0x104]
    //         0051c22f     TEST       EAX,EAX
    //         0051c231     JZ         LAB_0051c286
    //         0051c233     MOV        EDI,dword ptr [ESP + param_2]
    //         0051c237     CMP        EDI,-0x1
    //         0051c23a     JZ         LAB_0051c286
    //         0051c23c     MOV        this,dword ptr [ESI + 0x20]
    //         0051c23f     PUSH       0x1
    //         0051c241     PUSH       s_tpnl_obj::draw_item                            = "tpnl_obj::draw_item"
    //         0051c246     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         0051c24b     TEST       EAX,EAX
    //         0051c24d     JZ         LAB_0051c286
    //                              tpnl_obj.cpp:827 (42)
    //         0051c24f     MOV        EAX,dword ptr [ESP + param_1]
    //         0051c253     MOV        this,dword ptr [ESI + 0x10]
    //         0051c256     PUSH       0x0
    //         0051c258     PUSH       0x0
    //         0051c25a     LEA        EAX,[EAX + EAX*0x4]
    //         0051c25d     PUSH       EDI
    //         0051c25e     LEA        EDX,[ECX + EAX*0x4 + this+0x1e]
    //         0051c262     MOV        EAX,dword ptr [ESI + 0xc]
    //         0051c265     MOV        this,dword ptr [ESI + 0x20]
    //         0051c268     ADD        EAX,0x36
    //         0051c26b     PUSH       EDX
    //         0051c26c     PUSH       EAX
    //         0051c26d     PUSH       this
    //         0051c26e     MOV        this,dword ptr [ESI + 0x104]
    //         0051c274     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              tpnl_obj.cpp:828 (13)
    //         0051c279     MOV        this,dword ptr [ESI + 0x20]
    //         0051c27c     PUSH       s_tpnl_obj::draw_item                            = "tpnl_obj::draw_item"
    //         0051c281     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_0051c286                                                 XREF[3]:     0051c231(j), 0051c23a(j), 
    //                                                                                                         0051c24d(j)  
    //                              tpnl_obj.cpp:832 (20)
    //         0051c286     MOV        EAX,dword ptr [ESP + param_3]
    //         0051c28a     CMP        EAX,0x3
    //         0051c28d     JA         switchD_0051c293::default
    //                               switchD_0051c293::switchD
    //         0051c293     JMP        dword ptr [EAX*0x4 + switchD_0051c293::switchd   = 0051c29a
    //                               switchD_0051c293::caseD_0                                    XREF[2]:     0051c293(j), 0051c3dc(*)  
    //                              tpnl_obj.cpp:835 (23)
    //         0051c29a     MOV        EDX,dword ptr [ESP + param_4]
    //         0051c29e     LEA        EAX=>val_str[4],[ESP + 0x10]
    //         0051c2a2     PUSH       EDX
    //         0051c2a3     PUSH       s_%d                                             = 6425h
    //         0051c2a8     PUSH       EAX
    //         0051c2a9     CALL       sprintf                                          undefined sprintf()
    //         0051c2ae     ADD        ESP,0xc
    //                              tpnl_obj.cpp:836 (2)
    //         0051c2b1     JMP        LAB_0051c328
    //                               switchD_0051c293::caseD_1                                    XREF[2]:     0051c293(j), 0051c3e0(*)  
    //                              tpnl_obj.cpp:839 (12)
    //         0051c2b3     MOV        EAX,dword ptr [ESP + param_5]
    //         0051c2b7     MOV        this,dword ptr [ESP + param_4]
    //         0051c2bb     CMP        EAX,this
    //         0051c2bd     JLE        LAB_0051c2d7
    //                              tpnl_obj.cpp:840 (22)
    //         0051c2bf     SUB        EAX,this
    //         0051c2c1     PUSH       EAX
    //         0051c2c2     PUSH       this
    //         0051c2c3     LEA        this=>val_str[4],[ESP + 0x18]
    //         0051c2c7     PUSH       s_%d+%d                                          = "%d+%d"
    //         0051c2cc     PUSH       this
    //         0051c2cd     CALL       sprintf                                          undefined sprintf()
    //         0051c2d2     ADD        ESP,0x10
    //                              tpnl_obj.cpp:841 (2)
    //         0051c2d5     JMP        LAB_0051c328
    //                               LAB_0051c2d7                                                 XREF[1]:     0051c2bd(j)  
    //                              tpnl_obj.cpp:842 (19)
    //         0051c2d7     PUSH       this
    //         0051c2d8     LEA        EDX=>val_str[4],[ESP + 0x14]
    //         0051c2dc     PUSH       s_%d                                             = 6425h
    //         0051c2e1     PUSH       EDX
    //         0051c2e2     CALL       sprintf                                          undefined sprintf()
    //         0051c2e7     ADD        ESP,0xc
    //                              tpnl_obj.cpp:843 (2)
    //         0051c2ea     JMP        LAB_0051c328
    //                               switchD_0051c293::caseD_2                                    XREF[2]:     0051c293(j), 0051c3e4(*)  
    //                              tpnl_obj.cpp:846 (28)
    //         0051c2ec     MOV        EAX,dword ptr [ESP + param_5]
    //         0051c2f0     MOV        this,dword ptr [ESP + param_4]
    //         0051c2f4     PUSH       EAX
    //         0051c2f5     PUSH       this
    //         0051c2f6     LEA        EDX=>val_str[4],[ESP + 0x18]
    //         0051c2fa     PUSH       s_%d/%d                                          = "%d/%d"
    //         0051c2ff     PUSH       EDX
    //         0051c300     CALL       sprintf                                          undefined sprintf()
    //         0051c305     ADD        ESP,0x10
    //                              tpnl_obj.cpp:847 (2)
    //         0051c308     JMP        LAB_0051c328
    //                               switchD_0051c293::caseD_3                                    XREF[2]:     0051c293(j), 0051c3e8(*)  
    //                              tpnl_obj.cpp:850 (23)
    //         0051c30a     MOV        EAX,dword ptr [ESP + param_4]
    //         0051c30e     LEA        this=>val_str[4],[ESP + 0x10]
    //         0051c312     PUSH       EAX
    //         0051c313     PUSH       s_%d%%                                           = "%d%%"
    //         0051c318     PUSH       this
    //         0051c319     CALL       sprintf                                          undefined sprintf()
    //         0051c31e     ADD        ESP,0xc
    //                              tpnl_obj.cpp:851 (2)
    //         0051c321     JMP        LAB_0051c328
    //                               switchD_0051c293::default                                    XREF[1]:     0051c28d(j)  
    //                              tpnl_obj.cpp:854 (5)
    //         0051c323     MOV        byte ptr [ESP + val_str[4]],0x0
    //                               LAB_0051c328                                                 XREF[5]:     0051c2b1(j), 0051c2d5(j), 
    //                                                                                                         0051c2ea(j), 0051c308(j), 
    //                                                                                                         0051c321(j)  
    //                              tpnl_obj.cpp:858 (33)
    //         0051c328     MOV        AL,byte ptr [ESP + val_str[4]]
    //         0051c32c     TEST       AL,AL
    //         0051c32e     JZ         LAB_0051c3d0
    //         0051c334     MOV        this,dword ptr [ESI + 0x20]
    //         0051c337     PUSH       s_tpnl_obj::draw_item                            = "tpnl_obj::draw_item"
    //         0051c33c     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         0051c341     TEST       EAX,EAX
    //         0051c343     JZ         LAB_0051c3d0
    //                              tpnl_obj.cpp:860 (15)
    //         0051c349     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051c34c     PUSH       0x1
    //         0051c34e     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051c351     PUSH       EAX
    //         0051c352     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              tpnl_obj.cpp:861 (18)
    //         0051c358     MOV        this,dword ptr [ESI + 0x20]
    //         0051c35b     PUSH       0xffffff
    //         0051c360     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051c363     PUSH       EDX
    //         0051c364     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              tpnl_obj.cpp:862 (24)
    //         0051c36a     MOV        this,dword ptr [ESI + 0x20]
    //         0051c36d     MOV        EAX,dword ptr [ESI + 0xf4]
    //         0051c373     MOV        EBX,dword ptr [->GDI32.DLL::SelectObject]        = 0048b192
    //         0051c379     PUSH       EAX
    //         0051c37a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051c37d     PUSH       EDX
    //         0051c37e     CALL       EBX=>GDI32.DLL::SelectObject
    //         0051c380     MOV        EBP,EAX
    //                              tpnl_obj.cpp:863 (55)
    //         0051c382     LEA        EDI,[ESP + 0x10]
    //         0051c386     OR         this,0xffffffff
    //         0051c389     XOR        EAX,EAX
    //         0051c38b     SCASB.RE   ES:EDI
    //         0051c38d     NOT        this
    //         0051c38f     MOV        EDX,dword ptr [ESI + 0x10]
    //         0051c392     DEC        this
    //         0051c393     LEA        EAX,[ESP + 0x10]
    //         0051c397     PUSH       this
    //         0051c398     PUSH       EAX
    //         0051c399     MOV        EAX,dword ptr [ESP + 0x30]
    //         0051c39d     LEA        this,[EAX + EAX*0x4]
    //         0051c3a0     LEA        EAX,[EDX + this->_padding_*0x4 + 0x21]
    //         0051c3a4     MOV        this,dword ptr [ESI + 0xc]
    //         0051c3a7     MOV        EDX,dword ptr [ESI + 0x20]
    //         0051c3aa     PUSH       EAX
    //         0051c3ab     ADD        this,0x58
    //         0051c3ae     MOV        EAX,dword ptr [EDX + 0x38]
    //         0051c3b1     PUSH       this
    //         0051c3b2     PUSH       EAX
    //         0051c3b3     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              tpnl_obj.cpp:864 (10)
    //         0051c3b9     MOV        this,dword ptr [ESI + 0x20]
    //         0051c3bc     PUSH       EBP
    //         0051c3bd     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051c3c0     PUSH       EDX
    //         0051c3c1     CALL       EBX=>GDI32.DLL::SelectObject
    //                              tpnl_obj.cpp:865 (13)
    //         0051c3c3     MOV        this,dword ptr [ESI + 0x20]
    //         0051c3c6     PUSH       s_tpnl_obj::draw_item                            = "tpnl_obj::draw_item"
    //         0051c3cb     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //                               LAB_0051c3d0                                                 XREF[2]:     0051c32e(j), 0051c343(j)  
    //                              tpnl_obj.cpp:867 (28)
    //         0051c3d0     POP        EDI
    //         0051c3d1     POP        ESI
    //         0051c3d2     POP        EBP
    //         0051c3d3     POP        EBX
    //         0051c3d4     ADD        ESP,0x14
    //         0051c3d7     RET        0x14
}

// Offset: 0x0051C3DA
undefined FUN_0051c3da() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_0051c3da()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_0051c3da
    //         0051c3da     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_0051c293::switchdataD_0051c3dc                       XREF[1]:     draw_item:0051c293(*)  
}

// Offset: 0x0051C3F0
long TRIBE_Panel_Object::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Panel_Object::handle_idle(void)                                 *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TRIBE_Panel_Object * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              char[100]         Stack[-0x68]   name                      XREF[0,7]:   0051c80e(*), 0051c895(*), 0051c899(*), 0051c8e4(*), 
    //                                                                                     0051c8e8(*), 0051c8a5(R), 0051c8f4(R)  
    //              float             Stack[-0x6c]:4 orig_fval                 XREF[3]:     0051c814(*), 0051c85d(W), 0051c881(R)  
    //              short             Stack[-0x70]:2 progress                  XREF[3]:     0051c797(W), 0051c80a(R), 0051c996(R)  
    //              TRIBE_Building    Stack[-0x74]:4 bldg_obj                  XREF[4]:     0051c81e(*), 0051c82b(R), 0051c859(W), 0051c863(R)  
    //              short             Stack[-0x78]:2 work_type                 XREF[4]:     0051c7c9(W), 0051c7cd(R), 0051c83b(*), 0051c850(R)  
    //              short             Stack[-0x7c]:2 temp
    //              float             Stack[-0x80]:4 cur_fval                  XREF[4,1]:   0051c819(*), 0051c83f(*), 0051c873(R), 0051c8d0(R), 
    //                                                                                     0051c669(*)  
    //              short             Stack[-0x82]:2 orig_val                  XREF[1]:     0051c66e(*)  
    //              short             Stack[-0x84]:2 work_target
    //              short             Stack[-0x86]:2 cur_val
    //              int               Stack[-0x8c]:4 do_buttons                XREF[10]:    0051c52e(W), 0051c54e(W), 0051c56d(W), 0051c58c(W), 
    //                                                                                     0051c5b4(W), 0051c61f(W), 0051c653(W), 0051c7ad(W), 
    //                                                                                     0051c7e9(W), 0051c91f(R)  
    //              int               Stack[-0x90]:4 changed
    //                               ?handle_idle@TRIBE_Panel_Object@@UAEJXZ                      XREF[2]:     0057448c(*), 00576ce4(*)  
    //                               TRIBE_Panel_Object::handle_idle
    //                              tpnl_obj.cpp:873 (12)
    //         0051c3f0     SUB        ESP,0x8c
    //         0051c3f6     PUSH       EBX
    //         0051c3f7     PUSH       EBP
    //         0051c3f8     PUSH       ESI
    //         0051c3f9     PUSH       EDI
    //         0051c3fa     MOV        EBP,this
    //                              tpnl_obj.cpp:887 (5)
    //         0051c3fc     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              tpnl_obj.cpp:889 (5)
    //         0051c401     MOV        EAX,dword ptr [EBP + 0x6c]
    //         0051c404     TEST       EAX,EAX
    //                              tpnl_obj.cpp:890 (6)
    //         0051c406     JZ         LAB_0051ca03
    //                              tpnl_obj.cpp:892 (34)
    //         0051c40c     PUSH       0x37c
    //         0051c411     PUSH       s_C:\msdev\work\age1_x1\tpnl_obj.c               = "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp"
    //         0051c416     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0051c41b     MOV        EDX,dword ptr [EBP + 0x118]
    //         0051c421     MOV        this,dword ptr [EBP + 0x11c]
    //         0051c427     SUB        EAX,EDX
    //         0051c429     ADD        ESP,0x8
    //         0051c42c     CMP        EAX,this
    //                              tpnl_obj.cpp:893 (6)
    //         0051c42e     JC         LAB_0051ca03
    //                              tpnl_obj.cpp:895 (21)
    //         0051c434     PUSH       0x37f
    //         0051c439     PUSH       s_C:\msdev\work\age1_x1\tpnl_obj.c               = "C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp"
    //         0051c43e     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         0051c443     MOV        dword ptr [EBP + 0x118],EAX
    //                              tpnl_obj.cpp:897 (13)
    //         0051c449     MOV        AL,byte ptr [EBP + 0x120]
    //         0051c44f     ADD        ESP,0x8
    //         0051c452     CMP        AL,0x2
    //         0051c454     JNZ        LAB_0051c4c7
    //                              tpnl_obj.cpp:900 (5)
    //         0051c456     MOV        EDI,0x1
    //                               LAB_0051c45b                                                 XREF[1]:     0051c493(j)  
    //                              tpnl_obj.cpp:902 (14)
    //         0051c45b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051c461     PUSH       EDI
    //         0051c462     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         0051c467     MOV        ESI,EAX
    //                              tpnl_obj.cpp:903 (4)
    //         0051c469     TEST       ESI,ESI
    //         0051c46b     JZ         LAB_0051c48f
    //                              tpnl_obj.cpp:905 (34)
    //         0051c46d     MOV        EAX,[rge_base_game]                              = 00000000
    //         0051c472     MOV        this,dword ptr [EAX + 0x3f4]
    //         0051c478     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051c47b     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         0051c47e     MOV        this,dword ptr [EAX + 0x34]
    //         0051c481     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //         0051c486     CMP        dword ptr [EBP + ESI*0x4 + 0x1ec],EAX
    //         0051c48d     JNZ        LAB_0051c4a2
    //                               LAB_0051c48f                                                 XREF[1]:     0051c46b(j)  
    //                              tpnl_obj.cpp:900 (6)
    //         0051c48f     INC        EDI
    //         0051c490     CMP        EDI,0x9
    //         0051c493     JL         LAB_0051c45b
    //                              tpnl_obj.cpp:1132 (2)
    //         0051c495     XOR        EAX,EAX
    //                              tpnl_obj.cpp:1133 (11)
    //         0051c497     POP        EDI
    //         0051c498     POP        ESI
    //         0051c499     POP        EBP
    //         0051c49a     POP        EBX
    //         0051c49b     ADD        ESP,0x8c
    //         0051c4a1     RET
    //                               LAB_0051c4a2                                                 XREF[1]:     0051c48d(j)  
    //                              tpnl_obj.cpp:907 (7)
    //         0051c4a2     MOV        EAX,dword ptr [EBP + 0x38]
    //         0051c4a5     TEST       EAX,EAX
    //         0051c4a7     JNZ        LAB_0051c4b3
    //                              tpnl_obj.cpp:908 (10)
    //         0051c4a9     MOV        EDX,dword ptr [EBP]
    //         0051c4ac     PUSH       0x1
    //         0051c4ae     MOV        this,EBP
    //         0051c4b0     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0051c4b3                                                 XREF[1]:     0051c4a7(j)  
    //                              tpnl_obj.cpp:909 (7)
    //         0051c4b3     MOV        this,EBP
    //         0051c4b5     CALL       TRIBE_Panel_Object::save_object_info             void save_object_info(TRIBE_Panel_Object * th
    //                              tpnl_obj.cpp:1132 (2)
    //         0051c4ba     XOR        EAX,EAX
    //                              tpnl_obj.cpp:1133 (11)
    //         0051c4bc     POP        EDI
    //         0051c4bd     POP        ESI
    //         0051c4be     POP        EBP
    //         0051c4bf     POP        EBX
    //         0051c4c0     ADD        ESP,0x8c
    //         0051c4c6     RET
    //                               LAB_0051c4c7                                                 XREF[1]:     0051c454(j)  
    //                              tpnl_obj.cpp:918 (40)
    //         0051c4c7     MOV        EAX,dword ptr [EBP + 0x110]
    //         0051c4cd     TEST       EAX,EAX
    //         0051c4cf     JNZ        LAB_0051c4df
    //         0051c4d1     MOV        this,dword ptr [EBP + 0x114]
    //         0051c4d7     TEST       this,this
    //         0051c4d9     JNZ        LAB_0051c4ef
    //         0051c4db     TEST       EAX,EAX
    //         0051c4dd     JZ         LAB_0051c524
    //                               LAB_0051c4df                                                 XREF[1]:     0051c4cf(j)  
    //         0051c4df     MOV        this,dword ptr [EAX + 0x130]
    //         0051c4e5     MOV        EDX,dword ptr [EBP + 0x114]
    //         0051c4eb     CMP        this,EDX
    //         0051c4ed     JZ         LAB_0051c524
    //                               LAB_0051c4ef                                                 XREF[1]:     0051c4d9(j)  
    //                              tpnl_obj.cpp:920 (4)
    //         0051c4ef     TEST       EAX,EAX
    //         0051c4f1     JZ         LAB_0051c50e
    //                              tpnl_obj.cpp:921 (6)
    //         0051c4f3     MOV        EDX,dword ptr [EAX + 0x130]
    //                              tpnl_obj.cpp:923 (8)
    //         0051c4f9     MOV        this,EBP
    //         0051c4fb     PUSH       EDX
    //         0051c4fc     CALL       TRIBE_Panel_Object::set_object                   void set_object(TRIBE_Panel_Object * this, RG
    //                              tpnl_obj.cpp:1132 (2)
    //         0051c501     XOR        EAX,EAX
    //                              tpnl_obj.cpp:1133 (11)
    //         0051c503     POP        EDI
    //         0051c504     POP        ESI
    //         0051c505     POP        EBP
    //         0051c506     POP        EBX
    //         0051c507     ADD        ESP,0x8c
    //         0051c50d     RET
    //                               LAB_0051c50e                                                 XREF[1]:     0051c4f1(j)  
    //                              tpnl_obj.cpp:923 (9)
    //         0051c50e     PUSH       0x0
    //         0051c510     MOV        this,EBP
    //         0051c512     CALL       TRIBE_Panel_Object::set_object                   void set_object(TRIBE_Panel_Object * this, RG
    //                              tpnl_obj.cpp:1132 (2)
    //         0051c517     XOR        EAX,EAX
    //                              tpnl_obj.cpp:1133 (11)
    //         0051c519     POP        EDI
    //         0051c51a     POP        ESI
    //         0051c51b     POP        EBP
    //         0051c51c     POP        EBX
    //         0051c51d     ADD        ESP,0x8c
    //         0051c523     RET
    //                               LAB_0051c524                                                 XREF[2]:     0051c4dd(j), 0051c4ed(j)  
    //                              tpnl_obj.cpp:931 (24)
    //         0051c524     MOV        this,dword ptr [EBP + 0x114]
    //         0051c52a     XOR        EBX,EBX
    //         0051c52c     CMP        this,EBX
    //         0051c52e     MOV        dword ptr [ESP + do_buttons],EBX
    //         0051c532     MOV        dword ptr [ESP + Stack[-0x88]],EBX
    //         0051c536     JZ         LAB_0051c9cd
    //                              tpnl_obj.cpp:940 (13)
    //         0051c53c     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051c53f     MOV        EDX,dword ptr [EBP + 0x1e0]
    //         0051c545     CMP        EAX,EDX
    //         0051c547     JZ         LAB_0051c55b
    //                              tpnl_obj.cpp:942 (9)
    //         0051c549     MOV        EBX,0x1
    //         0051c54e     MOV        dword ptr [ESP + do_buttons],EBX
    //                              tpnl_obj.cpp:943 (4)
    //         0051c552     MOV        dword ptr [ESP + Stack[-0x88]],EBX
    //                              tpnl_obj.cpp:945 (18)
    //         0051c556     JMP        LAB_0051c623
    //                               LAB_0051c55b                                                 XREF[1]:     0051c547(j)  
    //         0051c55b     MOV        DL,byte ptr [ECX + this+0x37]
    //         0051c55e     MOV        AL,byte ptr [EBP + 0x1dc]
    //         0051c564     CMP        DL,AL
    //         0051c566     JZ         LAB_0051c57a
    //                              tpnl_obj.cpp:947 (9)
    //         0051c568     MOV        EBX,0x1
    //         0051c56d     MOV        dword ptr [ESP + do_buttons],EBX
    //                              tpnl_obj.cpp:948 (4)
    //         0051c571     MOV        dword ptr [ESP + Stack[-0x88]],EBX
    //                              tpnl_obj.cpp:950 (18)
    //         0051c575     JMP        LAB_0051c623
    //                               LAB_0051c57a                                                 XREF[1]:     0051c566(j)  
    //         0051c57a     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         0051c57d     MOV        EAX,dword ptr [EBP + 0x124]
    //         0051c583     CMP        EDI,EAX
    //         0051c585     JZ         LAB_0051c599
    //                              tpnl_obj.cpp:952 (9)
    //         0051c587     MOV        EBX,0x1
    //         0051c58c     MOV        dword ptr [ESP + do_buttons],EBX
    //                              tpnl_obj.cpp:953 (4)
    //         0051c590     MOV        dword ptr [ESP + Stack[-0x88]],EBX
    //                              tpnl_obj.cpp:955 (24)
    //         0051c594     JMP        LAB_0051c623
    //                               LAB_0051c599                                                 XREF[1]:     0051c585(j)  
    //         0051c599     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         0051c59c     MOV        DX,word ptr [EBP + 0x140]
    //         0051c5a3     MOV        AX,word ptr [ESI + 0x8]
    //         0051c5a7     CMP        AX,DX
    //         0051c5aa     JZ         LAB_0051c5c9
    //                              tpnl_obj.cpp:957 (5)
    //         0051c5ac     MOV        EBX,0x1
    //                              tpnl_obj.cpp:958 (14)
    //         0051c5b1     TEST       AX,AX
    //         0051c5b4     MOV        dword ptr [ESP + do_buttons],EBX
    //         0051c5b8     JZ         LAB_0051c5bf
    //         0051c5ba     TEST       DX,DX
    //         0051c5bd     JNZ        LAB_0051c623
    //                               LAB_0051c5bf                                                 XREF[1]:     0051c5b8(j)  
    //                              tpnl_obj.cpp:959 (8)
    //         0051c5bf     MOV        dword ptr [ESP + Stack[-0x88]],0x1
    //                              tpnl_obj.cpp:961 (13)
    //         0051c5c7     JMP        LAB_0051c623
    //                               LAB_0051c5c9                                                 XREF[1]:     0051c5aa(j)  
    //         0051c5c9     MOV        AX,word ptr [ECX + this->_padding_]
    //         0051c5cd     CMP        AX,word ptr [EBP + 0x12c]
    //                              tpnl_obj.cpp:963 (16)
    //         0051c5d4     JNZ        LAB_0051c61a
    //         0051c5d6     FLD        float ptr [ECX + this->_padding_]
    //         0051c5d9     FCOMP      float ptr [EBP + 0x130]
    //         0051c5df     FNSTSW     AX
    //         0051c5e1     TEST       AH,0x40
    //                              tpnl_obj.cpp:965 (16)
    //         0051c5e4     JZ         LAB_0051c61a
    //         0051c5e6     FLD        float ptr [ECX + this->_padding_]
    //         0051c5e9     FCOMP      float ptr [EBP + 0x14c]
    //         0051c5ef     FNSTSW     AX
    //         0051c5f1     TEST       AH,0x40
    //                              tpnl_obj.cpp:967 (13)
    //         0051c5f4     JZ         LAB_0051c61a
    //         0051c5f6     MOV        EDX,dword ptr [ESI + 0x4]
    //         0051c5f9     MOV        EAX,dword ptr [EBP + 0x13c]
    //         0051c5ff     CMP        EDX,EAX
    //                              tpnl_obj.cpp:969 (16)
    //         0051c601     JNZ        LAB_0051c61a
    //         0051c603     FLD        float ptr [EDI + 0x28]
    //         0051c606     FCOMP      float ptr [EBP + 0x1d0]
    //         0051c60c     FNSTSW     AX
    //         0051c60e     TEST       AH,0x40
    //                              tpnl_obj.cpp:971 (9)
    //         0051c611     JZ         LAB_0051c61a
    //         0051c613     CMP        word ptr [EDI + 0x10],0x2d
    //         0051c618     JNZ        LAB_0051c623
    //                               LAB_0051c61a                                                 XREF[5]:     0051c5d4(j), 0051c5e4(j), 
    //                                                                                                         0051c5f4(j), 0051c601(j), 
    //                                                                                                         0051c611(j)  
    //                              tpnl_obj.cpp:972 (9)
    //         0051c61a     MOV        EBX,0x1
    //         0051c61f     MOV        dword ptr [ESP + do_buttons],EBX
    //                               LAB_0051c623                                                 XREF[6]:     0051c556(j), 0051c575(j), 
    //                                                                                                         0051c594(j), 0051c5bd(j), 
    //                                                                                                         0051c5c7(j), 0051c618(j)  
    //                              tpnl_obj.cpp:974 (30)
    //         0051c623     TEST       EBX,EBX
    //         0051c625     JNZ        LAB_0051c770
    //         0051c62b     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051c62e     MOV        AL,byte ptr [EAX + 0x4]
    //         0051c631     CMP        AL,0x46
    //         0051c633     JC         LAB_0051c76c
    //         0051c639     CMP        AL,0x5a
    //         0051c63b     JZ         LAB_0051c76c
    //                              tpnl_obj.cpp:976 (13)
    //         0051c641     CALL       RGE_Action_Object::have_action                   uchar have_action(RGE_Action_Object * this)
    //         0051c646     CMP        AL,byte ptr [EBP + 0x1e8]
    //         0051c64c     JZ         LAB_0051c65b
    //                              tpnl_obj.cpp:978 (9)
    //         0051c64e     MOV        EBX,0x1
    //         0051c653     MOV        dword ptr [ESP + do_buttons],EBX
    //                              tpnl_obj.cpp:979 (4)
    //         0051c657     MOV        dword ptr [ESP + Stack[-0x88]],EBX
    //                               LAB_0051c65b                                                 XREF[1]:     0051c64c(j)  
    //                              tpnl_obj.cpp:981 (8)
    //         0051c65b     TEST       EBX,EBX
    //         0051c65d     JNZ        LAB_0051c770
    //                              tpnl_obj.cpp:983 (24)
    //         0051c663     MOV        this,dword ptr [EBP + 0x114]
    //         0051c669     LEA        EAX=>cur_fval+0x2,[ESP + 0x1e]
    //         0051c66d     PUSH       EAX
    //         0051c66e     LEA        EAX=>orig_val,[ESP + 0x1e]
    //         0051c672     MOV        EDX,dword ptr [this->_padding_]
    //         0051c674     PUSH       EAX
    //         0051c675     CALL       dword ptr [EDX + 0x22c]
    //                              tpnl_obj.cpp:984 (14)
    //         0051c67b     MOV        this,word ptr [ESP + 0x1a]
    //         0051c680     CMP        this,word ptr [EBP + 0x150]
    //         0051c687     JZ         LAB_0051c692
    //                              tpnl_obj.cpp:985 (9)
    //         0051c689     MOV        EBX,0x1
    //         0051c68e     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_0051c692                                                 XREF[1]:     0051c687(j)  
    //                              tpnl_obj.cpp:987 (8)
    //         0051c692     TEST       EBX,EBX
    //         0051c694     JNZ        LAB_0051c770
    //                              tpnl_obj.cpp:989 (24)
    //         0051c69a     MOV        this,dword ptr [EBP + 0x114]
    //         0051c6a0     LEA        EAX,[ESP + 0x1e]
    //         0051c6a4     PUSH       EAX
    //         0051c6a5     LEA        EAX,[ESP + 0x1e]
    //         0051c6a9     MOV        EDX,dword ptr [this->_padding_]
    //         0051c6ab     PUSH       EAX
    //         0051c6ac     CALL       dword ptr [EDX + 0x244]
    //                              tpnl_obj.cpp:990 (14)
    //         0051c6b2     MOV        this,word ptr [ESP + 0x1a]
    //         0051c6b7     CMP        this,word ptr [EBP + 0x152]
    //         0051c6be     JZ         LAB_0051c6c9
    //                              tpnl_obj.cpp:991 (9)
    //         0051c6c0     MOV        EBX,0x1
    //         0051c6c5     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_0051c6c9                                                 XREF[1]:     0051c6be(j)  
    //                              tpnl_obj.cpp:993 (8)
    //         0051c6c9     TEST       EBX,EBX
    //         0051c6cb     JNZ        LAB_0051c770
    //                              tpnl_obj.cpp:995 (24)
    //         0051c6d1     MOV        this,dword ptr [EBP + 0x114]
    //         0051c6d7     LEA        EAX,[ESP + 0x1e]
    //         0051c6db     PUSH       EAX
    //         0051c6dc     LEA        EAX,[ESP + 0x1e]
    //         0051c6e0     MOV        EDX,dword ptr [this->_padding_]
    //         0051c6e2     PUSH       EAX
    //         0051c6e3     CALL       dword ptr [EDX + 0x230]
    //                              tpnl_obj.cpp:996 (14)
    //         0051c6e9     MOV        this,word ptr [ESP + 0x1a]
    //         0051c6ee     CMP        this,word ptr [EBP + 0x154]
    //         0051c6f5     JZ         LAB_0051c700
    //                              tpnl_obj.cpp:997 (9)
    //         0051c6f7     MOV        EBX,0x1
    //         0051c6fc     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_0051c700                                                 XREF[1]:     0051c6f5(j)  
    //                              tpnl_obj.cpp:999 (4)
    //         0051c700     TEST       EBX,EBX
    //         0051c702     JNZ        LAB_0051c770
    //                              tpnl_obj.cpp:1001 (24)
    //         0051c704     MOV        this,dword ptr [EBP + 0x114]
    //         0051c70a     LEA        EAX,[ESP + 0x34]
    //         0051c70e     PUSH       EAX
    //         0051c70f     LEA        EAX,[ESP + 0x24]
    //         0051c713     MOV        EDX,dword ptr [this->_padding_]
    //         0051c715     PUSH       EAX
    //         0051c716     CALL       dword ptr [EDX + 0x234]
    //                              tpnl_obj.cpp:1002 (17)
    //         0051c71c     FLD        float ptr [ESP + 0x20]
    //         0051c720     FCOMP      float ptr [EBP + 0x158]
    //         0051c726     FNSTSW     AX
    //         0051c728     TEST       AH,0x40
    //         0051c72b     JNZ        LAB_0051c736
    //                              tpnl_obj.cpp:1003 (9)
    //         0051c72d     MOV        EBX,0x1
    //         0051c732     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_0051c736                                                 XREF[1]:     0051c72b(j)  
    //                              tpnl_obj.cpp:1005 (4)
    //         0051c736     TEST       EBX,EBX
    //         0051c738     JNZ        LAB_0051c770
    //                              tpnl_obj.cpp:1007 (24)
    //         0051c73a     MOV        this,dword ptr [EBP + 0x114]
    //         0051c740     LEA        EAX,[ESP + 0x34]
    //         0051c744     PUSH       EAX
    //         0051c745     LEA        EAX,[ESP + 0x24]
    //         0051c749     MOV        EDX,dword ptr [this->_padding_]
    //         0051c74b     PUSH       EAX
    //         0051c74c     CALL       dword ptr [EDX + 0x238]
    //                              tpnl_obj.cpp:1008 (17)
    //         0051c752     FLD        float ptr [ESP + 0x20]
    //         0051c756     FCOMP      float ptr [EBP + 0x15c]
    //         0051c75c     FNSTSW     AX
    //         0051c75e     TEST       AH,0x40
    //         0051c761     JNZ        LAB_0051c76c
    //                              tpnl_obj.cpp:1009 (9)
    //         0051c763     MOV        EBX,0x1
    //         0051c768     MOV        dword ptr [ESP + 0x10],EBX
    //                               LAB_0051c76c                                                 XREF[3]:     0051c633(j), 0051c63b(j), 
    //                                                                                                         0051c761(j)  
    //                              tpnl_obj.cpp:1021 (35)
    //         0051c76c     TEST       EBX,EBX
    //         0051c76e     JZ         LAB_0051c77c
    //                               LAB_0051c770                                                 XREF[6]:     0051c625(j), 0051c65d(j), 
    //                                                                                                         0051c694(j), 0051c6cb(j), 
    //                                                                                                         0051c702(j), 0051c738(j)  
    //         0051c770     MOV        EAX,dword ptr [ESP + Stack[-0x88]]
    //         0051c774     TEST       EAX,EAX
    //         0051c776     JNZ        LAB_0051c9cd
    //                               LAB_0051c77c                                                 XREF[1]:     0051c76e(j)  
    //         0051c77c     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051c782     MOV        this,dword ptr [EAX + 0x8]
    //         0051c785     CMP        byte ptr [ECX + this->_padding_],0x50
    //         0051c789     JNZ        LAB_0051c9cd
    //                              tpnl_obj.cpp:1023 (2)
    //         0051c78f     MOV        ESI,EAX
    //                              tpnl_obj.cpp:1024 (17)
    //         0051c791     MOV        AL,byte ptr [EBP + 0x134]
    //         0051c797     MOV        dword ptr [ESP + progress],ESI
    //         0051c79b     MOV        DL,byte ptr [ESI + 0x48]
    //         0051c79e     CMP        DL,AL
    //         0051c7a0     JZ         LAB_0051c7b3
    //                              tpnl_obj.cpp:1026 (5)
    //         0051c7a2     MOV        EDI,0x1
    //                              tpnl_obj.cpp:1027 (16)
    //         0051c7a7     MOV        EBX,EDI
    //         0051c7a9     MOV        dword ptr [ESP + Stack[-0x88]],EDI
    //         0051c7ad     MOV        dword ptr [ESP + do_buttons],EBX
    //         0051c7b1     JMP        LAB_0051c7b7
    //                               LAB_0051c7b3                                                 XREF[1]:     0051c7a0(j)  
    //         0051c7b3     MOV        EDI,dword ptr [ESP + Stack[-0x88]]
    //                               LAB_0051c7b7                                                 XREF[1]:     0051c7b1(j)  
    //                              tpnl_obj.cpp:1030 (8)
    //         0051c7b7     TEST       EBX,EBX
    //         0051c7b9     JZ         LAB_0051c7bf
    //         0051c7bb     TEST       EDI,EDI
    //         0051c7bd     JNZ        LAB_0051c7fe
    //                               LAB_0051c7bf                                                 XREF[1]:     0051c7b9(j)  
    //                              tpnl_obj.cpp:1032 (18)
    //         0051c7bf     MOV        this,ESI
    //         0051c7c1     CALL       TRIBE_Building_Object::get_construction_progress short get_construction_progress(TRIBE_Buildin
    //         0051c7c6     MOVSX      EAX,AX
    //         0051c7c9     MOV        dword ptr [ESP + work_type],EAX
    //         0051c7cd     FILD       dword ptr [ESP + work_type]
    //                              tpnl_obj.cpp:1033 (13)
    //         0051c7d1     FCOM       float ptr [EBP + 0x138]
    //         0051c7d7     FNSTSW     AX
    //         0051c7d9     TEST       AH,0x40
    //         0051c7dc     JNZ        LAB_0051c7fc
    //                              tpnl_obj.cpp:1036 (22)
    //         0051c7de     FCOMP      float ptr [DAT_00576db8]
    //         0051c7e4     MOV        EBX,0x1
    //         0051c7e9     MOV        dword ptr [ESP + do_buttons],EBX
    //         0051c7ed     FNSTSW     AX
    //         0051c7ef     TEST       AH,0x41
    //         0051c7f2     JNZ        LAB_0051c7fe
    //                              tpnl_obj.cpp:1037 (8)
    //         0051c7f4     MOV        EDI,EBX
    //         0051c7f6     MOV        dword ptr [ESP + Stack[-0x88]],EDI
    //         0051c7fa     JMP        LAB_0051c7fe
    //                               LAB_0051c7fc                                                 XREF[1]:     0051c7dc(j)  
    //                              tpnl_obj.cpp:1033 (2)
    //         0051c7fc     FSTP       ST0
    //                               LAB_0051c7fe                                                 XREF[3]:     0051c7bd(j), 0051c7f2(j), 
    //                                                                                                         0051c7fa(j)  
    //                              tpnl_obj.cpp:1041 (16)
    //         0051c7fe     TEST       EBX,EBX
    //         0051c800     JZ         LAB_0051c80e
    //         0051c802     TEST       EDI,EDI
    //         0051c804     JNZ        LAB_0051c923
    //         0051c80a     MOV        ESI,dword ptr [ESP + progress]
    //                               LAB_0051c80e                                                 XREF[1]:     0051c800(j)  
    //                              tpnl_obj.cpp:1043 (29)
    //         0051c80e     LEA        this=>name[4],[ESP + 0x38]
    //         0051c812     PUSH       0x64
    //         0051c814     LEA        EDX=>orig_fval,[ESP + 0x34]
    //         0051c818     PUSH       this
    //         0051c819     LEA        EAX=>cur_fval,[ESP + 0x24]
    //         0051c81d     PUSH       EDX
    //         0051c81e     LEA        this=>bldg_obj,[ESP + 0x34]
    //         0051c822     PUSH       EAX
    //         0051c823     PUSH       this
    //         0051c824     MOV        this,ESI
    //         0051c826     CALL       TRIBE_Building_Object::work_status               int work_status(TRIBE_Building_Object * this,
    //                              tpnl_obj.cpp:1046 (16)
    //         0051c82b     MOV        EDI,dword ptr [ESP + bldg_obj]
    //         0051c82f     CMP        DI,0x67
    //         0051c833     JZ         LAB_0051c867
    //         0051c835     CMP        DI,0x66
    //         0051c839     JZ         LAB_0051c867
    //                              tpnl_obj.cpp:1047 (21)
    //         0051c83b     LEA        EDX=>work_type,[ESP + 0x24]
    //         0051c83f     LEA        EAX=>cur_fval,[ESP + 0x1c]
    //         0051c843     PUSH       EDX
    //         0051c844     PUSH       EAX
    //         0051c845     MOV        this,ESI
    //         0051c847     CALL       TRIBE_Building_Object::production_queue_status   int production_queue_status(TRIBE_Building_Ob
    //         0051c84c     TEST       EAX,EAX
    //         0051c84e     JZ         LAB_0051c863
    //                              tpnl_obj.cpp:1050 (23)
    //         0051c850     MOV        this,dword ptr [ESP + work_type]
    //         0051c854     MOV        EDI,0x66
    //         0051c859     MOV        dword ptr [ESP + bldg_obj],EDI
    //         0051c85d     MOV        dword ptr [ESP + orig_fval],this
    //         0051c861     JMP        LAB_0051c867
    //                               LAB_0051c863                                                 XREF[1]:     0051c84e(j)  
    //         0051c863     MOV        EDI,dword ptr [ESP + bldg_obj]
    //                               LAB_0051c867                                                 XREF[3]:     0051c833(j), 0051c839(j), 
    //                                                                                                         0051c861(j)  
    //                              tpnl_obj.cpp:1053 (95)
    //         0051c867     MOV        DX,word ptr [EBP + 0x160]
    //         0051c86e     CMP        DI,DX
    //         0051c871     JNZ        LAB_0051c8c6
    //         0051c873     MOV        AX,word ptr [ESP + cur_fval]
    //         0051c878     CMP        AX,word ptr [EBP + 0x162]
    //         0051c87f     JNZ        LAB_0051c8c6
    //         0051c881     MOV        this,word ptr [ESP + orig_fval]
    //         0051c886     CMP        this,word ptr [EBP + 0x164]
    //         0051c88d     JNZ        LAB_0051c8c6
    //         0051c88f     LEA        ESI,[EBP + 0x166]
    //         0051c895     LEA        EAX=>name[4],[ESP + 0x38]
    //                               LAB_0051c899                                                 XREF[1]:     0051c8b7(j)  
    //         0051c899     MOV        BL,byte ptr [EAX]=>name[4]
    //         0051c89b     MOV        this,BL
    //         0051c89d     CMP        BL,byte ptr [ESI]
    //         0051c89f     JNZ        LAB_0051c8bd
    //         0051c8a1     TEST       this,this
    //         0051c8a3     JZ         LAB_0051c8b9
    //         0051c8a5     MOV        BL,byte ptr [EAX + name[5]]
    //         0051c8a8     MOV        this,BL
    //         0051c8aa     CMP        BL,byte ptr [ESI + 0x1]
    //         0051c8ad     JNZ        LAB_0051c8bd
    //         0051c8af     ADD        EAX,0x2
    //         0051c8b2     ADD        ESI,0x2
    //         0051c8b5     TEST       this,this
    //         0051c8b7     JNZ        LAB_0051c899
    //                               LAB_0051c8b9                                                 XREF[1]:     0051c8a3(j)  
    //         0051c8b9     XOR        EAX,EAX
    //         0051c8bb     JMP        LAB_0051c8c2
    //                               LAB_0051c8bd                                                 XREF[2]:     0051c89f(j), 0051c8ad(j)  
    //         0051c8bd     SBB        EAX,EAX
    //         0051c8bf     SBB        EAX,-0x1
    //                               LAB_0051c8c2                                                 XREF[1]:     0051c8bb(j)  
    //         0051c8c2     TEST       EAX,EAX
    //         0051c8c4     JZ         LAB_0051c91f
    //                               LAB_0051c8c6                                                 XREF[3]:     0051c871(j), 0051c87f(j), 
    //                                                                                                         0051c88d(j)  
    //                              tpnl_obj.cpp:1056 (79)
    //         0051c8c6     CMP        DI,DX
    //         0051c8c9     MOV        EBX,0x1
    //         0051c8ce     JNZ        LAB_0051c915
    //         0051c8d0     MOV        DX,word ptr [ESP + cur_fval]
    //         0051c8d5     CMP        DX,word ptr [EBP + 0x162]
    //         0051c8dc     JNZ        LAB_0051c915
    //         0051c8de     LEA        ESI,[EBP + 0x166]
    //         0051c8e4     LEA        EAX=>name[4],[ESP + 0x38]
    //                               LAB_0051c8e8                                                 XREF[1]:     0051c906(j)  
    //         0051c8e8     MOV        DL,byte ptr [EAX]=>name[4]
    //         0051c8ea     MOV        this,DL
    //         0051c8ec     CMP        DL,byte ptr [ESI]
    //         0051c8ee     JNZ        LAB_0051c90c
    //         0051c8f0     TEST       this,this
    //         0051c8f2     JZ         LAB_0051c908
    //         0051c8f4     MOV        DL,byte ptr [EAX + name[5]]
    //         0051c8f7     MOV        this,DL
    //         0051c8f9     CMP        DL,byte ptr [ESI + 0x1]
    //         0051c8fc     JNZ        LAB_0051c90c
    //         0051c8fe     ADD        EAX,0x2
    //         0051c901     ADD        ESI,0x2
    //         0051c904     TEST       this,this
    //         0051c906     JNZ        LAB_0051c8e8
    //                               LAB_0051c908                                                 XREF[1]:     0051c8f2(j)  
    //         0051c908     XOR        EAX,EAX
    //         0051c90a     JMP        LAB_0051c911
    //                               LAB_0051c90c                                                 XREF[2]:     0051c8ee(j), 0051c8fc(j)  
    //         0051c90c     SBB        EAX,EAX
    //         0051c90e     SBB        EAX,-0x1
    //                               LAB_0051c911                                                 XREF[1]:     0051c90a(j)  
    //         0051c911     TEST       EAX,EAX
    //         0051c913     JZ         LAB_0051c923
    //                               LAB_0051c915                                                 XREF[2]:     0051c8ce(j), 0051c8dc(j)  
    //                              tpnl_obj.cpp:1057 (14)
    //         0051c915     MOV        dword ptr [ESP + Stack[-0x88]],0x1
    //         0051c91d     JMP        LAB_0051c923
    //                               LAB_0051c91f                                                 XREF[1]:     0051c8c4(j)  
    //         0051c91f     MOV        EBX,dword ptr [ESP + do_buttons]
    //                               LAB_0051c923                                                 XREF[3]:     0051c804(j), 0051c913(j), 
    //                                                                                                         0051c91d(j)  
    //                              tpnl_obj.cpp:1061 (28)
    //         0051c923     TEST       EBX,EBX
    //         0051c925     JZ         LAB_0051c92f
    //         0051c927     MOV        EAX,dword ptr [ESP + Stack[-0x88]]
    //         0051c92b     TEST       EAX,EAX
    //         0051c92d     JNZ        LAB_0051c96d
    //                               LAB_0051c92f                                                 XREF[1]:     0051c925(j)  
    //         0051c92f     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051c935     MOV        this,dword ptr [EAX + 0x8]
    //         0051c938     CMP        word ptr [ECX + this->_padding_],0x46
    //         0051c93d     JNZ        LAB_0051c96d
    //                              tpnl_obj.cpp:1064 (41)
    //         0051c93f     MOV        EDX,dword ptr [EBP + 0x110]
    //         0051c945     MOV        ESI,dword ptr [EDX + 0x50]
    //         0051c948     FLD        float ptr [ESI + 0x2c]
    //         0051c94b     CALL       __ftol                                           undefined __ftol()
    //         0051c950     CMP        EAX,dword ptr [EBP + 0x1d4]
    //         0051c956     JNZ        LAB_0051c968
    //         0051c958     FLD        float ptr [ESI + 0x10]
    //         0051c95b     CALL       __ftol                                           undefined __ftol()
    //         0051c960     CMP        EAX,dword ptr [EBP + 0x1d8]
    //         0051c966     JZ         LAB_0051c96d
    //                               LAB_0051c968                                                 XREF[1]:     0051c956(j)  
    //                              tpnl_obj.cpp:1065 (5)
    //         0051c968     MOV        EBX,0x1
    //                               LAB_0051c96d                                                 XREF[3]:     0051c92d(j), 0051c93d(j), 
    //                                                                                                         0051c966(j)  
    //                              tpnl_obj.cpp:1068 (41)
    //         0051c96d     TEST       EBX,EBX
    //         0051c96f     JZ         LAB_0051c979
    //         0051c971     MOV        EAX,dword ptr [ESP + Stack[-0x88]]
    //         0051c975     TEST       EAX,EAX
    //         0051c977     JNZ        LAB_0051c9cd
    //                               LAB_0051c979                                                 XREF[1]:     0051c96f(j)  
    //         0051c979     MOV        EAX,dword ptr [EBP + 0x114]
    //         0051c97f     MOV        EDX,dword ptr [EBP + 0x110]
    //         0051c985     MOV        this,dword ptr [EAX + 0xc]
    //         0051c988     CMP        this,EDX
    //         0051c98a     JNZ        LAB_0051c9cd
    //         0051c98c     MOV        EDX,dword ptr [EAX + 0x8]
    //         0051c98f     CMP        word ptr [EDX + 0x10],0x32
    //         0051c994     JNZ        LAB_0051c9cd
    //                              tpnl_obj.cpp:1070 (15)
    //         0051c996     MOV        EAX,dword ptr [ESP + progress]
    //         0051c99a     MOV        this,dword ptr [EAX + 0x184]
    //         0051c9a0     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //                              tpnl_obj.cpp:1071 (4)
    //         0051c9a5     TEST       EAX,EAX
    //         0051c9a7     JZ         LAB_0051c9cd
    //                              tpnl_obj.cpp:1073 (31)
    //         0051c9a9     FLD        float ptr [EAX + 0x2c]
    //         0051c9ac     MOV        this,dword ptr [EBP + 0x114]
    //         0051c9b2     FADD       float ptr [ECX + this->_padding_]
    //         0051c9b5     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051c9bb     CALL       __ftol                                           undefined __ftol()
    //         0051c9c0     CMP        dword ptr [EBP + 0x210],EAX
    //         0051c9c6     JZ         LAB_0051c9cd
    //                              tpnl_obj.cpp:1074 (5)
    //         0051c9c8     MOV        EBX,0x1
    //                               LAB_0051c9cd                                                 XREF[8]:     0051c536(j), 0051c776(j), 
    //                                                                                                         0051c789(j), 0051c977(j), 
    //                                                                                                         0051c98a(j), 0051c994(j), 
    //                                                                                                         0051c9a7(j), 0051c9c6(j)  
    //                              tpnl_obj.cpp:1121 (4)
    //         0051c9cd     TEST       EBX,EBX
    //         0051c9cf     JZ         LAB_0051ca03
    //                              tpnl_obj.cpp:1123 (7)
    //         0051c9d1     MOV        EAX,dword ptr [EBP + 0x38]
    //         0051c9d4     TEST       EAX,EAX
    //         0051c9d6     JNZ        LAB_0051c9e2
    //                              tpnl_obj.cpp:1124 (10)
    //         0051c9d8     MOV        EDX,dword ptr [EBP]
    //         0051c9db     PUSH       0x1
    //         0051c9dd     MOV        this,EBP
    //         0051c9df     CALL       dword ptr [EDX + 0x20]
    //                               LAB_0051c9e2                                                 XREF[1]:     0051c9d6(j)  
    //                              tpnl_obj.cpp:1126 (7)
    //         0051c9e2     MOV        this,EBP
    //         0051c9e4     CALL       TRIBE_Panel_Object::save_object_info             void save_object_info(TRIBE_Panel_Object * th
    //                              tpnl_obj.cpp:1128 (8)
    //         0051c9e9     MOV        EAX,dword ptr [ESP + 0x14]
    //         0051c9ed     TEST       EAX,EAX
    //         0051c9ef     JZ         LAB_0051ca03
    //                              tpnl_obj.cpp:1129 (18)
    //         0051c9f1     MOV        this,dword ptr [EBP + 0x40]
    //         0051c9f4     PUSH       0x0
    //         0051c9f6     PUSH       0x0
    //         0051c9f8     PUSH       0x1
    //         0051c9fa     MOV        EAX,dword ptr [this->_padding_]
    //         0051c9fc     PUSH       EBP
    //         0051c9fd     CALL       dword ptr [EAX + 0xb4]
    //                               LAB_0051ca03                                                 XREF[4]:     0051c406(j), 0051c42e(j), 
    //                                                                                                         0051c9cf(j), 0051c9ef(j)  
    //                              tpnl_obj.cpp:1133 (13)
    //         0051ca03     POP        EDI
    //         0051ca04     POP        ESI
    //         0051ca05     POP        EBP
    //         0051ca06     XOR        EAX,EAX
    //         0051ca08     POP        EBX
    //         0051ca09     ADD        ESP,0x8c
    //         0051ca0f     RET
}

// Offset: 0x0051CA10
void save_object_info(TRIBE_Panel_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TRIBE_Panel_Object::save_object_info(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall save_object_info(TRIBE_Panel_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              float             Stack[-0xc]:4  orig_fval                 XREF[1]:     0051cafc(*)  
    //              short             Stack[-0xe]:2  temp
    //              short             Stack[-0x10]:2 orig_val
    //                               ?save_object_info@TRIBE_Panel_Object@@IAEXXZ                 XREF[4]:     set_object:0051b14d(c), 
    //                               TRIBE_Panel_Object::save_object_info                                      set_mode:0051b16d(c), 
    //                                                                                                         handle_idle:0051c4b5(c), 
    //                                                                                                         handle_idle:0051c9e4(c)  
    //                              tpnl_obj.cpp:1139 (9)
    //         0051ca10     SUB        ESP,0xc
    //         0051ca13     PUSH       EBX
    //         0051ca14     PUSH       EBP
    //         0051ca15     PUSH       ESI
    //         0051ca16     MOV        ESI,this
    //         0051ca18     PUSH       EDI
    //                              tpnl_obj.cpp:1144 (9)
    //         0051ca19     CMP        byte ptr [ESI + 0x120],0x2
    //         0051ca20     JNZ        LAB_0051ca6f
    //                              tpnl_obj.cpp:1147 (5)
    //         0051ca22     MOV        EBX,0x1
    //                               LAB_0051ca27                                                 XREF[1]:     0051ca65(j)  
    //                              tpnl_obj.cpp:1149 (14)
    //         0051ca27     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0051ca2d     PUSH       EBX
    //         0051ca2e     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         0051ca33     MOV        EDI,EAX
    //                              tpnl_obj.cpp:1150 (23)
    //         0051ca35     TEST       EDI,EDI
    //         0051ca37     JZ         LAB_0051ca61
    //         0051ca39     MOV        EAX,[rge_base_game]                              = 00000000
    //         0051ca3e     MOV        EAX,dword ptr [EAX + 0x3f4]
    //         0051ca44     MOVSX      this,word ptr [EAX + 0x3c]
    //         0051ca48     CMP        EDI,this
    //         0051ca4a     JGE        LAB_0051ca61
    //                              tpnl_obj.cpp:1152 (27)
    //         0051ca4c     MOV        EDX,dword ptr [EAX + 0x40]
    //         0051ca4f     MOV        EAX,dword ptr [EDX + EDI*0x4]
    //         0051ca52     MOV        this,dword ptr [EAX + 0x34]
    //         0051ca55     CALL       RGE_Victory_Conditions::get_victory_points       long get_victory_points(RGE_Victory_Condition
    //         0051ca5a     MOV        dword ptr [ESI + EDI*0x4 + 0x1ec],EAX
    //                               LAB_0051ca61                                                 XREF[2]:     0051ca37(j), 0051ca4a(j)  
    //         0051ca61     INC        EBX
    //         0051ca62     CMP        EBX,0x9
    //         0051ca65     JL         LAB_0051ca27
    //                              tpnl_obj.cpp:1228 (8)
    //         0051ca67     POP        EDI
    //         0051ca68     POP        ESI
    //         0051ca69     POP        EBP
    //         0051ca6a     POP        EBX
    //         0051ca6b     ADD        ESP,0xc
    //         0051ca6e     RET
    //                               LAB_0051ca6f                                                 XREF[1]:     0051ca20(j)  
    //                              tpnl_obj.cpp:1158 (14)
    //         0051ca6f     MOV        this,dword ptr [ESI + 0x114]
    //         0051ca75     TEST       this,this
    //         0051ca77     JZ         LAB_0051cc74
    //                              tpnl_obj.cpp:1160 (9)
    //         0051ca7d     MOV        DL,byte ptr [ECX + this+0x37]
    //         0051ca80     MOV        byte ptr [ESI + 0x1dc],DL
    //                              tpnl_obj.cpp:1161 (9)
    //         0051ca86     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051ca89     MOV        dword ptr [ESI + 0x124],EAX
    //                              tpnl_obj.cpp:1162 (11)
    //         0051ca8f     MOV        DX,word ptr [ECX + this->_padding_]
    //         0051ca93     MOV        word ptr [ESI + 0x12c],DX
    //                              tpnl_obj.cpp:1163 (9)
    //         0051ca9a     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051ca9d     MOV        dword ptr [ESI + 0x130],EAX
    //                              tpnl_obj.cpp:1164 (9)
    //         0051caa3     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051caa6     MOV        dword ptr [ESI + 0x14c],EDX
    //                              tpnl_obj.cpp:1165 (12)
    //         0051caac     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051caaf     MOV        EDX,dword ptr [EAX + 0x4]
    //         0051cab2     MOV        dword ptr [ESI + 0x13c],EDX
    //                              tpnl_obj.cpp:1166 (14)
    //         0051cab8     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051cabb     MOV        DX,word ptr [EAX + 0x8]
    //         0051cabf     MOV        word ptr [ESI + 0x140],DX
    //                              tpnl_obj.cpp:1167 (12)
    //         0051cac6     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051cac9     MOV        EDX,dword ptr [EAX + 0x28]
    //         0051cacc     MOV        dword ptr [ESI + 0x1d0],EDX
    //                              tpnl_obj.cpp:1168 (9)
    //         0051cad2     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0051cad5     MOV        dword ptr [ESI + 0x1e0],EAX
    //                              tpnl_obj.cpp:1170 (22)
    //         0051cadb     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0051cade     MOV        AL,byte ptr [EDX + 0x4]
    //         0051cae1     CMP        AL,0x46
    //         0051cae3     JC         LAB_0051cb7e
    //         0051cae9     CMP        AL,0x5a
    //         0051caeb     JZ         LAB_0051cb7e
    //                              tpnl_obj.cpp:1172 (5)
    //         0051caf1     CALL       RGE_Action_Object::have_action                   uchar have_action(RGE_Action_Object * this)
    //                              tpnl_obj.cpp:1173 (32)
    //         0051caf6     MOV        this,dword ptr [ESI + 0x114]
    //         0051cafc     LEA        EDX=>orig_fval,[ESP + 0x10]
    //         0051cb00     PUSH       EDX
    //         0051cb01     MOV        byte ptr [ESI + 0x1e8],AL
    //         0051cb07     MOV        EAX,dword ptr [this->_padding_]
    //         0051cb09     LEA        EDX,[ESI + 0x150]
    //         0051cb0f     PUSH       EDX
    //         0051cb10     CALL       dword ptr [EAX + 0x22c]
    //                              tpnl_obj.cpp:1174 (26)
    //         0051cb16     MOV        this,dword ptr [ESI + 0x114]
    //         0051cb1c     LEA        EDX,[ESP + 0x10]
    //         0051cb20     PUSH       EDX
    //         0051cb21     LEA        EDX,[ESI + 0x152]
    //         0051cb27     MOV        EAX,dword ptr [this->_padding_]
    //         0051cb29     PUSH       EDX
    //         0051cb2a     CALL       dword ptr [EAX + 0x22c]
    //                              tpnl_obj.cpp:1175 (26)
    //         0051cb30     MOV        this,dword ptr [ESI + 0x114]
    //         0051cb36     LEA        EDX,[ESP + 0x10]
    //         0051cb3a     PUSH       EDX
    //         0051cb3b     LEA        EDX,[ESI + 0x154]
    //         0051cb41     MOV        EAX,dword ptr [this->_padding_]
    //         0051cb43     PUSH       EDX
    //         0051cb44     CALL       dword ptr [EAX + 0x230]
    //                              tpnl_obj.cpp:1176 (26)
    //         0051cb4a     MOV        this,dword ptr [ESI + 0x114]
    //         0051cb50     LEA        EDX,[ESP + 0x14]
    //         0051cb54     PUSH       EDX
    //         0051cb55     LEA        EDX,[ESI + 0x158]
    //         0051cb5b     MOV        EAX,dword ptr [this->_padding_]
    //         0051cb5d     PUSH       EDX
    //         0051cb5e     CALL       dword ptr [EAX + 0x234]
    //                              tpnl_obj.cpp:1177 (26)
    //         0051cb64     MOV        this,dword ptr [ESI + 0x114]
    //         0051cb6a     LEA        EDX,[ESP + 0x14]
    //         0051cb6e     PUSH       EDX
    //         0051cb6f     LEA        EDX,[ESI + 0x15c]
    //         0051cb75     MOV        EAX,dword ptr [this->_padding_]
    //         0051cb77     PUSH       EDX
    //         0051cb78     CALL       dword ptr [EAX + 0x238]
    //                               LAB_0051cb7e                                                 XREF[2]:     0051cae3(j), 0051caeb(j)  
    //                              tpnl_obj.cpp:1188 (19)
    //         0051cb7e     MOV        EDI,dword ptr [ESI + 0x114]
    //         0051cb84     MOV        EAX,dword ptr [EDI + 0x8]
    //         0051cb87     CMP        byte ptr [EAX + 0x4],0x50
    //         0051cb8b     JNZ        LAB_0051cc74
    //                              tpnl_obj.cpp:1191 (9)
    //         0051cb91     MOV        this,byte ptr [EDI + 0x48]
    //         0051cb94     MOV        byte ptr [ESI + 0x134],this
    //                              tpnl_obj.cpp:1192 (14)
    //         0051cb9a     MOV        this,EDI
    //         0051cb9c     CALL       TRIBE_Building_Object::get_construction_progress short get_construction_progress(TRIBE_Buildin
    //         0051cba1     MOVSX      EDX,AX
    //         0051cba4     MOV        dword ptr [ESP + 0x18],EDX
    //                              tpnl_obj.cpp:1194 (47)
    //         0051cba8     LEA        this,[ESI + 0x166]
    //         0051cbae     FILD       dword ptr [ESP + 0x18]
    //         0051cbb2     LEA        EBP,[ESI + 0x164]
    //         0051cbb8     PUSH       0x64
    //         0051cbba     LEA        EAX,[ESI + 0x162]
    //         0051cbc0     PUSH       this
    //         0051cbc1     FSTP       float ptr [ESI + 0x138]
    //         0051cbc7     LEA        EBX,[ESI + 0x160]
    //         0051cbcd     PUSH       EBP
    //         0051cbce     PUSH       EAX
    //         0051cbcf     PUSH       EBX
    //         0051cbd0     MOV        this,EDI
    //         0051cbd2     CALL       TRIBE_Building_Object::work_status               int work_status(TRIBE_Building_Object * this,
    //                              tpnl_obj.cpp:1197 (15)
    //         0051cbd7     MOV        AX,word ptr [EBX]
    //         0051cbda     CMP        AX,0x67
    //         0051cbde     JZ         LAB_0051cc0b
    //         0051cbe0     CMP        AX,0x66
    //         0051cbe4     JZ         LAB_0051cc0b
    //                              tpnl_obj.cpp:1198 (23)
    //         0051cbe6     LEA        EDX,[ESP + 0x12]
    //         0051cbea     LEA        EAX,[ESI + 0x162]
    //         0051cbf0     PUSH       EDX
    //         0051cbf1     PUSH       EAX
    //         0051cbf2     MOV        this,EDI
    //         0051cbf4     CALL       TRIBE_Building_Object::production_queue_status   int production_queue_status(TRIBE_Building_Ob
    //         0051cbf9     TEST       EAX,EAX
    //         0051cbfb     JZ         LAB_0051cc0b
    //                              tpnl_obj.cpp:1201 (14)
    //         0051cbfd     MOV        AX,word ptr [ESP + 0x12]
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         0051cc02     MOV        word ptr [EBX],0x66
    //         0051cc07     MOV        word ptr [EBP],AX
    //                               LAB_0051cc0b                                                 XREF[3]:     0051cbde(j), 0051cbe4(j), 
    //                                                                                                         0051cbfb(j)  
    //                              tpnl_obj.cpp:1204 (23)
    //         0051cc0b     MOV        EBX,dword ptr [ESI + 0x110]
    //         0051cc11     MOV        this,dword ptr [EBX + 0x50]
    //         0051cc14     FLD        float ptr [ECX + this->_padding_]
    //         0051cc17     CALL       __ftol                                           undefined __ftol()
    //         0051cc1c     MOV        dword ptr [ESI + 0x1d4],EAX
    //                              tpnl_obj.cpp:1205 (17)
    //         0051cc22     MOV        EDX,dword ptr [EBX + 0x50]
    //         0051cc25     FLD        float ptr [EDX + 0x10]
    //         0051cc28     CALL       __ftol                                           undefined __ftol()
    //         0051cc2d     MOV        dword ptr [ESI + 0x1d8],EAX
    //                              tpnl_obj.cpp:1207 (21)
    //         0051cc33     MOV        EAX,dword ptr [ESI + 0x114]
    //         0051cc39     CMP        dword ptr [EAX + 0xc],EBX
    //         0051cc3c     JNZ        LAB_0051cc74
    //         0051cc3e     MOV        EAX,dword ptr [EAX + 0x8]
    //         0051cc41     CMP        word ptr [EAX + 0x10],0x32
    //         0051cc46     JNZ        LAB_0051cc74
    //                              tpnl_obj.cpp:1209 (11)
    //         0051cc48     MOV        this,dword ptr [EDI + 0x184]
    //         0051cc4e     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //                              tpnl_obj.cpp:1210 (4)
    //         0051cc53     TEST       EAX,EAX
    //         0051cc55     JZ         LAB_0051cc74
    //                              tpnl_obj.cpp:1211 (29)
    //         0051cc57     FLD        float ptr [EAX + 0x2c]
    //         0051cc5a     MOV        this,dword ptr [ESI + 0x114]
    //         0051cc60     FADD       float ptr [ECX + this->_padding_]
    //         0051cc63     FSUB       float ptr [null_00576d84]                        = align(3)
    //         0051cc69     CALL       __ftol                                           undefined __ftol()
    //         0051cc6e     MOV        dword ptr [ESI + 0x210],EAX
    //                               LAB_0051cc74                                                 XREF[5]:     0051ca77(j), 0051cb8b(j), 
    //                                                                                                         0051cc3c(j), 0051cc46(j), 
    //                                                                                                         0051cc55(j)  
    //                              tpnl_obj.cpp:1228 (8)
    //         0051cc74     POP        EDI
    //         0051cc75     POP        ESI
    //         0051cc76     POP        EBP
    //         0051cc77     POP        EBX
    //         0051cc78     ADD        ESP,0xc
    //         0051cc7b     RET
}

// Offset: 0x0051CC80
long TRIBE_Panel_Object::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Panel_Object::mouse_left_down_action(long,long,int,int)         *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_down_action(TRIBE_Panel_Object * this, lo
    //              long              EAX:4          <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_down_action@TRIBE_Panel_Object@@UAEJJJHH@Z       XREF[2]:     005744c4(*), 00576d1c(*)  
    //                               TRIBE_Panel_Object::mouse_left_down_action
    //                              tpnl_obj.cpp:1234 (2)
    //         0051cc80     XOR        EAX,EAX
    //                              tpnl_obj.cpp:1244 (3)
    //         0051cc82     RET        0x10
}

// Offset: 0x0051CC90
long TRIBE_Panel_Object::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Panel_Object::mouse_left_up_action(long,long,int,int)           *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_up_action(TRIBE_Panel_Object * this, long
    //              long              EAX:4          <RETURN>
    //              TRIBE_Panel_Ob    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_up_action@TRIBE_Panel_Object@@UAEJJJHH@Z         XREF[1]:     00576d28(*)  
    //                               TRIBE_Panel_Object::mouse_left_up_action
    //                              tpnl_obj.cpp:1250 (2)
    //         0051cc90     XOR        EAX,EAX
    //                              tpnl_obj.cpp:1265 (3)
    //         0051cc92     RET        0x10
}

