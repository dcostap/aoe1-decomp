// Auto-generated scaffold unit: spnl_obj.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/spnl_obj.cpp
#include "../include/common.h"

// Offset: 0x004BEDC0
undefined TRIBE_Scenario_Editor_Panel_Object(TRIBE_Scenario_Editor_Panel_Object* this_, TDrawArea* param_2, TPanel* param_3, void* param_4, long param_5, long param_6, TShape* param_7, TShape** param_8, TRIBE_Player* param_9) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_Panel_Object(class TD... *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TRIBE_Scenario_Editor_Panel_Object(TRIBE_Scenar
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     004bede4(R)  
    //              TPanel *          Stack[0x8]:4   param_2                   XREF[1]:     004beddf(R)  
    //              void *            Stack[0xc]:4   param_3                   XREF[1]:     004bedda(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004bedd5(R)  
    //              long              Stack[0x14]:4  param_5                   XREF[1]:     004bedd0(R)  
    //              TShape *          Stack[0x18]:4  param_6                   XREF[1]:     004bedc4(R)  
    //              TShape * *        Stack[0x1c]:4  param_7                   XREF[1]:     004bedcb(R)  
    //              TRIBE_Player *    Stack[0x20]:4  param_8                   XREF[1]:     004bedc0(R)  
    //                               ??0TRIBE_Scenario_Editor_Panel_Object@@QAE@PAVTDrawArea@@PA  XREF[1]:     create_all_buttons_etc:004b0289(c)
    //                               TRIBE_Scenario_Editor_Panel_Object::TRIBE_Scenario_Editor_P
    //                              spnl_obj.cpp:48 (50)
    //         004bedc0     MOV        EAX,dword ptr [ESP + param_8]
    //         004bedc4     MOV        EDX,dword ptr [ESP + param_6]
    //         004bedc8     PUSH       ESI
    //         004bedc9     MOV        ESI,this
    //         004bedcb     MOV        this,dword ptr [ESP + param_7]
    //         004bedcf     PUSH       EAX
    //         004bedd0     MOV        EAX,dword ptr [ESP + param_5]
    //         004bedd4     PUSH       this
    //         004bedd5     MOV        this,dword ptr [ESP + param_4]
    //         004bedd9     PUSH       EDX
    //         004bedda     MOV        EDX,dword ptr [ESP + param_3]
    //         004bedde     PUSH       EAX
    //         004beddf     MOV        EAX,dword ptr [ESP + param_2]
    //         004bede3     PUSH       this
    //         004bede4     MOV        this,dword ptr [ESP + param_1]
    //         004bede8     PUSH       EDX
    //         004bede9     PUSH       EAX
    //         004bedea     PUSH       this
    //         004bedeb     MOV        this,ESI
    //         004beded     CALL       TRIBE_Panel_Object::TRIBE_Panel_Object           undefined TRIBE_Panel_Object(TRIBE_Panel_Obje
    //                              spnl_obj.cpp:50 (14)
    //         004bedf2     XOR        EAX,EAX
    //         004bedf4     MOV        dword ptr [ESI],TRIBE_Scenario_Editor_Panel_Ob   = 004bee10
    //         004bedfa     MOV        dword ptr [ESI + 0x214],EAX
    //                              spnl_obj.cpp:51 (6)
    //         004bee00     MOV        dword ptr [ESI + 0x218],EAX
    //                              spnl_obj.cpp:52 (6)
    //         004bee06     MOV        EAX,ESI
    //         004bee08     POP        ESI
    //         004bee09     RET        0x20
}

// Offset: 0x004BEE30
void TRIBE_Scenario_Editor_Panel_Object(TRIBE_Scenario_Editor_Panel_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_Panel_Object... *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TRIBE_Scenario_Editor_Panel_Object(TRIBE_Scenario_E
    //              void              <VOID>         <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //                               ??1TRIBE_Scenario_Editor_Panel_Object@@UAE@XZ                XREF[1]:     `scalar_deleting_destructor':004be
    //                               TRIBE_Scenario_Editor_Panel_Object::~TRIBE_Scenario_Editor_
    //                              spnl_obj.cpp:58 (11)
    //         004bee30     MOV        dword ptr [this->_padding_],TRIBE_Scenario_Edi   = 004bee10
    //         004bee36     JMP        TRIBE_Panel_Object::~TRIBE_Panel_Object          void ~TRIBE_Panel_Object(TRIBE_Panel_Object *
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
}

// Offset: 0x004BEE40
void set_master_info(TRIBE_Scenario_Editor_Panel_Object* this_, RGE_Master_Static_Object* param_2, TRIBE_Player* param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TRIBE_Scenario_Editor_Panel_Object::set_master_info(class RGE_Master_Stati... *
    //                              *********************************************************************************************************
    //                              void __thiscall set_master_info(TRIBE_Scenario_Editor_Panel_Object *
    //              void              <VOID>         <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     004bee40(R)  
    //              TRIBE_Player *    Stack[0x8]:4   param_2                   XREF[1]:     004bee4a(R)  
    //                               ?set_master_info@TRIBE_Scenario_Editor_Panel_Object@@QAEXPA  XREF[3]:     set_scenario_mode:004aa0b3(c), 
    //                               TRIBE_Scenario_Editor_Panel_Object::set_master_info                       action:004acb02(c), 
    //                                                                                                         action:004acbc9(c)  
    //                              spnl_obj.cpp:63 (10)
    //         004bee40     MOV        EAX,dword ptr [ESP + param_1]
    //         004bee44     MOV        dword ptr [ECX + this->master_game_obj],EAX
    //                              spnl_obj.cpp:65 (4)
    //         004bee4a     MOV        EAX,dword ptr [ESP + param_2]
    //                              spnl_obj.cpp:66 (10)
    //         004bee4e     TEST       EAX,EAX
    //         004bee50     MOV        dword ptr [ECX + this->_padding_],EAX
    //         004bee56     JNZ        LAB_004bee61
    //                              spnl_obj.cpp:67 (6)
    //         004bee58     MOV        dword ptr [ECX + this->master_culture_id],EAX
    //                              spnl_obj.cpp:70 (3)
    //         004bee5e     RET        0x8
    //                               LAB_004bee61                                                 XREF[1]:     004bee56(j)  
    //                              spnl_obj.cpp:69 (11)
    //         004bee61     XOR        EDX,EDX
    //         004bee63     MOV        DL,byte ptr [EAX + 0x54]
    //         004bee66     MOV        dword ptr [ECX + this->master_culture_id],EDX
    //                              spnl_obj.cpp:70 (3)
    //         004bee6c     RET        0x8
}

// Offset: 0x004BEE70
void TRIBE_Scenario_Editor_Panel_Object::draw() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Scenario_Editor_Panel_Object::draw(void)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall draw(TRIBE_Scenario_Editor_Panel_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //              char[100]         Stack[-0x68]   str
    //              char[100]         Stack[-0xcc]   name
    //              long              Stack[-0xd0]:4 max_x
    //              long              Stack[-0xd4]:4 max_y
    //              long              Stack[-0xd8]:4 min_y
    //              long              Stack[-0xdc]:4 min_x
    //              void *            Stack[-0xe0]:4 old_font                  XREF[1]:     004beee2(W)  
    //              int               Stack[-0xe8]:4 text_flag
    //                               ?draw@TRIBE_Scenario_Editor_Panel_Object@@UAEXXZ             XREF[1]:     00574470(*)  
    //                               TRIBE_Scenario_Editor_Panel_Object::draw
    //                              spnl_obj.cpp:78 (12)
    //         004bee70     SUB        ESP,0xe4
    //         004bee76     PUSH       EBX
    //         004bee77     PUSH       EBP
    //         004bee78     MOV        EBP,this
    //         004bee7a     PUSH       ESI
    //         004bee7b     PUSH       EDI
    //                              spnl_obj.cpp:95 (29)
    //         004bee7c     XOR        EDI,EDI
    //         004bee7e     CMP        dword ptr [EBP + 0x20],EDI
    //         004bee81     JZ         LAB_004bf48b
    //         004bee87     CMP        dword ptr [EBP + 0x70],EDI
    //         004bee8a     JZ         LAB_004bf48b
    //         004bee90     CMP        dword ptr [EBP + 0x6c],EDI
    //         004bee93     JZ         LAB_004bf48b
    //                              spnl_obj.cpp:101 (9)
    //         004bee99     CMP        byte ptr [EBP + 0x120],0x2
    //         004beea0     JNZ        LAB_004beeb2
    //                              spnl_obj.cpp:103 (5)
    //         004beea2     CALL       TRIBE_Panel_Object::draw_score                   void draw_score(TRIBE_Panel_Object * this)
    //                              spnl_obj.cpp:325 (11)
    //         004beea7     POP        EDI
    //         004beea8     POP        ESI
    //         004beea9     POP        EBP
    //         004beeaa     POP        EBX
    //         004beeab     ADD        ESP,0xe4
    //         004beeb1     RET
    //                               LAB_004beeb2                                                 XREF[1]:     004beea0(j)  
    //                              spnl_obj.cpp:108 (8)
    //         004beeb2     CMP        dword ptr [EBP + 0x214],EDI
    //         004beeb8     JNZ        LAB_004beedc
    //                              spnl_obj.cpp:110 (11)
    //         004beeba     MOV        this,dword ptr [EBP + 0x40]
    //         004beebd     CMP        this,EDI
    //         004beebf     JZ         LAB_004bf48b
    //                              spnl_obj.cpp:111 (12)
    //         004beec5     MOV        EAX,dword ptr [this->_padding_]
    //         004beec7     LEA        EDX,[EBP + 0x24]
    //         004beeca     PUSH       EDX
    //         004beecb     CALL       dword ptr [EAX + 0x34]
    //         004beece     MOV        dword ptr [EBP + 0x38],EDI
    //                              spnl_obj.cpp:325 (11)
    //         004beed1     POP        EDI
    //         004beed2     POP        ESI
    //         004beed3     POP        EBP
    //         004beed4     POP        EBX
    //         004beed5     ADD        ESP,0xe4
    //         004beedb     RET
    //                               LAB_004beedc                                                 XREF[1]:     004beeb8(j)  
    //                              spnl_obj.cpp:116 (13)
    //         004beedc     MOV        EBX,dword ptr [EBP]
    //         004beedf     PUSH       EDI
    //         004beee0     MOV        this,EBP
    //         004beee2     MOV        dword ptr [ESP + old_font],EBX
    //         004beee6     CALL       dword ptr [EBX + 0x28]
    //                              spnl_obj.cpp:117 (13)
    //         004beee9     MOV        this,dword ptr [EBP + 0x20]
    //         004beeec     LEA        EAX,[EBP + 0x24]
    //         004beeef     PUSH       EDI
    //         004beef0     PUSH       EAX=>DAT_fffffff8
    //         004beef1     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              spnl_obj.cpp:120 (19)
    //         004beef6     MOV        this,dword ptr [EBP + 0x20]
    //         004beef9     PUSH       0x1
    //         004beefb     PUSH       EDI=>DAT_fffffff8
    //         004beefc     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004bef01     TEST       EAX,EAX
    //         004bef03     JZ         LAB_004bf03f
    //                              spnl_obj.cpp:126 (18)
    //         004bef09     MOV        EAX,dword ptr [EBP + 0x214]
    //         004bef0f     MOV        dword ptr [ESP + 0x10],0x1
    //         004bef17     MOV        SI,word ptr [EAX + 0x4c]
    //                              spnl_obj.cpp:127 (10)
    //         004bef1b     CMP        SI,-0x1
    //         004bef1f     JZ         LAB_004befcd
    //                              spnl_obj.cpp:129 (9)
    //         004bef25     CMP        byte ptr [EAX + 0x8f],0x2
    //         004bef2c     JNZ        LAB_004bef48
    //                              spnl_obj.cpp:131 (12)
    //         004bef2e     MOV        this,dword ptr [EBP + 0x218]
    //         004bef34     MOV        EDX,dword ptr [EBP + 0x10c]
    //                              spnl_obj.cpp:132 (12)
    //         004bef3a     MOV        AX,word ptr [EAX + 0x16e]
    //         004bef41     MOV        EDI,dword ptr [EDX + this->_padding_*0x4]
    //         004bef44     ADD        ESI,EAX
    //                              spnl_obj.cpp:134 (2)
    //         004bef46     JMP        LAB_004bef4e
    //                               LAB_004bef48                                                 XREF[1]:     004bef2c(j)  
    //                              spnl_obj.cpp:135 (6)
    //         004bef48     MOV        EDI,dword ptr [EBP + 0x108]
    //                               LAB_004bef4e                                                 XREF[1]:     004bef46(j)  
    //                              spnl_obj.cpp:137 (23)
    //         004bef4e     MOV        EAX,dword ptr [EBP + 0x110]
    //         004bef54     TEST       EAX,EAX
    //         004bef56     JZ         LAB_004befaa
    //         004bef58     MOV        EAX,dword ptr [EAX + 0x108]
    //         004bef5e     LEA        this,[EAX + 0x28]
    //         004bef61     TEST       this,this
    //         004bef63     JZ         LAB_004befaa
    //                              spnl_obj.cpp:139 (14)
    //         004bef65     MOVSX      EDX,word ptr [EAX + 0x26]
    //         004bef69     INC        EDX
    //         004bef6a     SHL        EDX,0x4
    //         004bef6d     PUSH       EDX
    //         004bef6e     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
    //                              spnl_obj.cpp:140 (50)
    //         004bef73     MOV        EAX,dword ptr [EBP + 0x110]
    //         004bef79     ADD        ESP,0x4
    //         004bef7c     MOVSX      EDX,SI
    //         004bef7f     MOV        this,dword ptr [EAX + 0x108]
    //         004bef85     MOV        EAX,dword ptr [EBP + 0x10]
    //         004bef88     ADD        this,0x28
    //         004bef8b     ADD        EAX,0x21
    //         004bef8e     PUSH       this
    //         004bef8f     MOV        this,dword ptr [EBP + 0xc]
    //         004bef92     PUSH       offset DAT_fffffff8
    //         004bef94     PUSH       EDX=>DAT_fffffff4
    //         004bef95     MOV        EDX,dword ptr [EBP + 0x20]
    //         004bef98     ADD        this,0x2
    //         004bef9b     PUSH       EAX=>DAT_fffffff0
    //         004bef9c     PUSH       this
    //         004bef9d     PUSH       EDX
    //         004bef9e     MOV        this,EDI
    //         004befa0     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              spnl_obj.cpp:142 (5)
    //         004befa5     JMP        LAB_004bf034
    //                               LAB_004befaa                                                 XREF[2]:     004bef56(j), 004bef63(j)  
    //                              spnl_obj.cpp:143 (33)
    //         004befaa     MOV        this,dword ptr [EBP + 0x10]
    //         004befad     MOV        EDX,dword ptr [EBP + 0xc]
    //         004befb0     MOVSX      EAX,SI
    //         004befb3     PUSH       0x0
    //         004befb5     PUSH       0x0=>DAT_fffffff8
    //         004befb7     ADD        this,0x21
    //         004befba     PUSH       EAX=>DAT_fffffff4
    //         004befbb     MOV        EAX,dword ptr [EBP + 0x20]
    //         004befbe     ADD        EDX,0x2
    //         004befc1     PUSH       this=>DAT_fffffff0
    //         004befc2     PUSH       EDX
    //         004befc3     PUSH       EAX
    //         004befc4     MOV        this,EDI
    //         004befc6     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              spnl_obj.cpp:145 (9)
    //         004befcb     JMP        LAB_004bf034
    //                               LAB_004befcd                                                 XREF[1]:     004bef1f(j)  
    //         004befcd     MOV        EAX,dword ptr [EAX + 0x18]
    //         004befd0     CMP        EAX,EDI
    //         004befd2     JZ         LAB_004bf034
    //                              spnl_obj.cpp:148 (36)
    //         004befd4     LEA        this,[ESP + 0x24]
    //         004befd8     PUSH       EDI
    //         004befd9     LEA        EDX,[ESP + 0x2c]
    //         004befdd     PUSH       this=>DAT_fffffff8
    //         004befde     PUSH       EDX=>DAT_fffffff4
    //         004befdf     LEA        this,[ESP + 0x2c]
    //         004befe3     LEA        EDX,[ESP + 0x28]
    //         004befe7     PUSH       this=>DAT_fffffff0
    //         004befe8     PUSH       EDX
    //         004befe9     MOV        this,EAX
    //         004befeb     MOV        dword ptr [ESP + 0x24],EDI
    //         004befef     CALL       RGE_Sprite::get_size                             int get_size(RGE_Sprite * this, long * param_
    //         004beff4     TEST       EAX,EAX
    //         004beff6     JZ         LAB_004bf034
    //                              spnl_obj.cpp:152 (60)
    //         004beff8     MOV        EAX,dword ptr [EBP + 0x20]
    //         004beffb     MOV        this,dword ptr [EBP + 0x110]
    //         004bf001     MOV        ESI,dword ptr [ESP + 0x20]
    //         004bf005     PUSH       EDI
    //         004bf006     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf00c     PUSH       EAX=>DAT_fffffff8
    //         004bf00d     MOV        EAX,dword ptr [EBP + 0x10]
    //         004bf010     MOV        this,dword ptr [EBP + 0xc]
    //         004bf013     SUB        EAX,ESI
    //         004bf015     PUSH       EDX=>DAT_fffffff4
    //         004bf016     ADD        EAX,0x28
    //         004bf019     MOV        EDX,dword ptr [EBP + 0x214]
    //         004bf01f     PUSH       EAX=>DAT_fffffff0
    //         004bf020     MOV        EAX,dword ptr [ESP + 0x2c]
    //         004bf024     SUB        this,EAX
    //         004bf026     ADD        this,0xa
    //         004bf029     PUSH       this
    //         004bf02a     MOV        this,dword ptr [EDX + 0x18]
    //         004bf02d     PUSH       EDI
    //         004bf02e     PUSH       EDI
    //         004bf02f     CALL       RGE_Sprite::do_draw                              void do_draw(RGE_Sprite * this, long param_1,
    //                               LAB_004bf034                                                 XREF[4]:     004befa5(j), 004befcb(j), 
    //                                                                                                         004befd2(j), 004beff6(j)  
    //                              spnl_obj.cpp:156 (11)
    //         004bf034     MOV        this,dword ptr [EBP + 0x20]
    //         004bf037     XOR        EDI,EDI
    //         004bf039     PUSH       EDI
    //         004bf03a     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_004bf03f                                                 XREF[1]:     004bef03(j)  
    //                              spnl_obj.cpp:160 (17)
    //         004bf03f     MOV        this,dword ptr [EBP + 0x20]
    //         004bf042     PUSH       EDI
    //         004bf043     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         004bf048     TEST       EAX,EAX
    //         004bf04a     JZ         LAB_004bf286
    //                              spnl_obj.cpp:162 (15)
    //         004bf050     MOV        EAX,dword ptr [EBP + 0x20]
    //         004bf053     PUSH       0x1
    //         004bf055     MOV        this,dword ptr [EAX + 0x38]
    //         004bf058     PUSH       this=>DAT_fffffff8
    //         004bf059     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              spnl_obj.cpp:163 (18)
    //         004bf05f     MOV        EDX,dword ptr [EBP + 0x20]
    //         004bf062     PUSH       0xffffff
    //         004bf067     MOV        EAX,dword ptr [EDX + 0x38]
    //         004bf06a     PUSH       EAX=>DAT_fffffff8
    //         004bf06b     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              spnl_obj.cpp:164 (20)
    //         004bf071     MOV        EDX,dword ptr [EBP + 0x20]
    //         004bf074     MOV        this,dword ptr [EBP + 0x88]
    //         004bf07a     PUSH       this
    //         004bf07b     MOV        EAX,dword ptr [EDX + 0x38]
    //         004bf07e     PUSH       EAX=>DAT_fffffff8
    //         004bf07f     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                              spnl_obj.cpp:165 (20)
    //         004bf085     MOV        EDX,dword ptr [EBP + 0x20]
    //         004bf088     MOV        this,dword ptr [EBP + 0xf4]
    //         004bf08e     PUSH       this
    //         004bf08f     MOV        EAX,dword ptr [EDX + 0x38]
    //         004bf092     PUSH       EAX=>DAT_fffffff8
    //         004bf093     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              spnl_obj.cpp:170 (24)
    //         004bf099     MOV        EBX,dword ptr [->GDI32.DLL::TextOutA]            = 0048b30c
    //         004bf09f     MOV        dword ptr [ESP + 0x18],EAX
    //         004bf0a3     MOV        EAX,dword ptr [EBP + 0x110]
    //         004bf0a9     CMP        EAX,EDI
    //         004bf0ab     JZ         LAB_004bf14e
    //                              spnl_obj.cpp:172 (27)
    //         004bf0b1     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004bf0b5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004bf0bb     LEA        ESI,[ESP + 0x2c]
    //         004bf0bf     PUSH       0x64
    //         004bf0c1     PUSH       ESI=>DAT_fffffff8
    //         004bf0c2     MOV        EDX,dword ptr [this->_padding_]
    //         004bf0c4     PUSH       0x0=>DAT_fffffff4
    //         004bf0c6     PUSH       EAX=>DAT_fffffff0
    //         004bf0c7     PUSH       0x69
    //         004bf0c9     CALL       dword ptr [EDX + 0x28]
    //                              spnl_obj.cpp:173 (54)
    //         004bf0cc     MOV        ESI,s_Unknown                                    = 55h
    //         004bf0d1     LEA        EAX,[ESP + 0x2c]
    //                               LAB_004bf0d5                                                 XREF[1]:     004bf0f3(j)  
    //         004bf0d5     MOV        DL,byte ptr [EAX]
    //         004bf0d7     MOV        this,DL
    //         004bf0d9     CMP        DL,byte ptr [ESI]=>s_Unknown                     = 55h
    //                                                                                  = 6Bh
    //         004bf0db     JNZ        LAB_004bf0f9
    //         004bf0dd     TEST       this,this
    //         004bf0df     JZ         LAB_004bf0f5
    //         004bf0e1     MOV        DL,byte ptr [EAX + 0x1]
    //         004bf0e4     MOV        this,DL
    //         004bf0e6     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0057f075            = 6Eh
    //         004bf0e9     JNZ        LAB_004bf0f9
    //         004bf0eb     ADD        EAX,0x2
    //         004bf0ee     ADD        ESI,0x2
    //         004bf0f1     TEST       this,this
    //         004bf0f3     JNZ        LAB_004bf0d5
    //                               LAB_004bf0f5                                                 XREF[1]:     004bf0df(j)  
    //         004bf0f5     XOR        EAX,EAX
    //         004bf0f7     JMP        LAB_004bf0fe
    //                               LAB_004bf0f9                                                 XREF[2]:     004bf0db(j), 004bf0e9(j)  
    //         004bf0f9     SBB        EAX,EAX
    //         004bf0fb     SBB        EAX,-0x1
    //                               LAB_004bf0fe                                                 XREF[1]:     004bf0f7(j)  
    //         004bf0fe     TEST       EAX,EAX
    //         004bf100     JNZ        LAB_004bf126
    //                              spnl_obj.cpp:174 (36)
    //         004bf102     MOV        EDI,s_Gaia                                       = 47h
    //         004bf107     OR         this,0xffffffff
    //         004bf10a     SCASB.RE   ES:EDI=>s_Gaia                                   = 47h
    //                                                                                  = 00616961
    //         004bf10c     NOT        this
    //         004bf10e     SUB        EDI,this
    //         004bf110     LEA        EDX,[ESP + 0x2c]
    //         004bf114     MOV        EAX,this
    //         004bf116     MOV        ESI,EDI
    //         004bf118     MOV        EDI,EDX
    //         004bf11a     SHR        this,0x2
    //         004bf11d     MOVSD.REP  ES:EDI,ESI
    //         004bf11f     MOV        this,EAX
    //         004bf121     AND        this,0x3
    //         004bf124     MOVSB.REP  ES:EDI,ESI
    //                               LAB_004bf126                                                 XREF[1]:     004bf100(j)  
    //                              spnl_obj.cpp:176 (40)
    //         004bf126     LEA        EDI,[ESP + 0x2c]
    //         004bf12a     OR         this,0xffffffff
    //         004bf12d     XOR        EAX,EAX
    //         004bf12f     MOV        EDX,dword ptr [EBP + 0x10]
    //         004bf132     SCASB.RE   ES:EDI
    //         004bf134     NOT        this
    //         004bf136     MOV        EAX,dword ptr [EBP + 0xc]
    //         004bf139     DEC        this
    //         004bf13a     PUSH       this
    //         004bf13b     LEA        this,[ESP + 0x30]
    //         004bf13f     PUSH       this=>DAT_fffffff8
    //         004bf140     MOV        this,dword ptr [EBP + 0x20]
    //         004bf143     PUSH       EDX=>DAT_fffffff4
    //         004bf144     ADD        EAX,0x2
    //         004bf147     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf14a     PUSH       EAX=>DAT_fffffff0
    //         004bf14b     PUSH       EDX
    //         004bf14c     CALL       EBX=>GDI32.DLL::TextOutA
    //                               LAB_004bf14e                                                 XREF[1]:     004bf0ab(j)  
    //                              spnl_obj.cpp:182 (15)
    //         004bf14e     MOV        EAX,dword ptr [EBP + 0x214]
    //         004bf154     MOV        AX,word ptr [EAX + 0xc]
    //         004bf158     TEST       AX,AX
    //         004bf15b     JLE        LAB_004bf178
    //                              spnl_obj.cpp:183 (25)
    //         004bf15d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004bf163     LEA        ESI,[ESP + 0x90]
    //         004bf16a     MOVSX      EAX,AX
    //         004bf16d     MOV        EDX,dword ptr [this->_padding_]
    //         004bf16f     PUSH       0x64
    //         004bf171     PUSH       ESI=>DAT_fffffff8
    //         004bf172     PUSH       EAX=>DAT_fffffff4
    //         004bf173     CALL       dword ptr [EDX + 0x20]
    //                              spnl_obj.cpp:184 (2)
    //         004bf176     JMP        LAB_004bf180
    //                               LAB_004bf178                                                 XREF[1]:     004bf15b(j)  
    //                              spnl_obj.cpp:185 (8)
    //         004bf178     MOV        byte ptr [ESP + 0x90],0x0
    //                               LAB_004bf180                                                 XREF[1]:     004bf176(j)  
    //                              spnl_obj.cpp:186 (11)
    //         004bf180     MOV        AL,byte ptr [ESP + 0x90]
    //         004bf187     TEST       AL,AL
    //         004bf189     JNZ        LAB_004bf1b8
    //                              spnl_obj.cpp:187 (45)
    //         004bf18b     MOV        this,dword ptr [EBP + 0x214]
    //         004bf191     XOR        EAX,EAX
    //         004bf193     LEA        EDX,[ESP + 0x90]
    //         004bf19a     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004bf19d     OR         this,0xffffffff
    //         004bf1a0     SCASB.RE   ES:EDI
    //         004bf1a2     NOT        this
    //         004bf1a4     SUB        EDI,this
    //         004bf1a6     MOV        EAX,this
    //         004bf1a8     MOV        ESI,EDI
    //         004bf1aa     MOV        EDI,EDX
    //         004bf1ac     SHR        this,0x2
    //         004bf1af     MOVSD.REP  ES:EDI,ESI
    //         004bf1b1     MOV        this,EAX
    //         004bf1b3     AND        this,0x3
    //         004bf1b6     MOVSB.REP  ES:EDI,ESI
    //                               LAB_004bf1b8                                                 XREF[1]:     004bf189(j)  
    //                              spnl_obj.cpp:188 (23)
    //         004bf1b8     LEA        this,[ESP + 0x90]
    //         004bf1bf     LEA        EDX,[ESP + 0x2c]
    //         004bf1c3     PUSH       this
    //         004bf1c4     PUSH       s_%s                                             = "%s"
    //         004bf1c9     PUSH       EDX=>DAT_fffffff4
    //         004bf1ca     CALL       sprintf                                          undefined sprintf()
    //                              spnl_obj.cpp:189 (46)
    //         004bf1cf     LEA        EDI,[ESP + 0x38]
    //         004bf1d3     OR         this,0xffffffff
    //         004bf1d6     XOR        EAX,EAX
    //         004bf1d8     ADD        ESP,0xc
    //         004bf1db     SCASB.RE   ES:EDI
    //         004bf1dd     MOV        EDX,dword ptr [EBP + 0xc]
    //         004bf1e0     LEA        EAX,[ESP + 0x2c]
    //         004bf1e4     NOT        this
    //         004bf1e6     DEC        this
    //         004bf1e7     ADD        EDX,0x2
    //         004bf1ea     PUSH       this
    //         004bf1eb     MOV        this,dword ptr [EBP + 0x10]
    //         004bf1ee     PUSH       EAX=>DAT_fffffff8
    //         004bf1ef     MOV        EAX,dword ptr [EBP + 0x20]
    //         004bf1f2     ADD        this,0xf
    //         004bf1f5     PUSH       this=>DAT_fffffff4
    //         004bf1f6     MOV        this,dword ptr [EAX + 0x38]
    //         004bf1f9     PUSH       EDX=>DAT_fffffff0
    //         004bf1fa     PUSH       this
    //         004bf1fb     CALL       EBX=>GDI32.DLL::TextOutA
    //                              spnl_obj.cpp:191 (8)
    //         004bf1fd     MOV        EAX,dword ptr [ESP + 0x10]
    //         004bf201     TEST       EAX,EAX
    //         004bf203     JZ         LAB_004bf278
    //                              spnl_obj.cpp:196 (30)
    //         004bf205     MOV        EDX,dword ptr [EBP + 0x214]
    //         004bf20b     MOVSX      EAX,word ptr [EDX + 0x26]
    //         004bf20f     PUSH       EAX
    //         004bf210     PUSH       EAX=>DAT_fffffff8
    //         004bf211     LEA        EAX,[ESP + 0x98]
    //         004bf218     PUSH       s_%d/%d                                          = "%d/%d"
    //         004bf21d     PUSH       EAX=>DAT_fffffff0
    //         004bf21e     CALL       sprintf                                          undefined sprintf()
    //                              spnl_obj.cpp:197 (52)
    //         004bf223     LEA        EDI,[ESP + 0xa0]
    //         004bf22a     OR         this,0xffffffff
    //         004bf22d     XOR        EAX,EAX
    //         004bf22f     ADD        ESP,0x10
    //         004bf232     SCASB.RE   ES:EDI
    //         004bf234     MOV        EDX,dword ptr [EBP + 0x10]
    //         004bf237     MOV        EAX,dword ptr [EBP + 0xc]
    //         004bf23a     NOT        this
    //         004bf23c     DEC        this
    //         004bf23d     ADD        EDX,0x55
    //         004bf240     PUSH       this
    //         004bf241     LEA        this,[ESP + 0x94]
    //         004bf248     PUSH       this=>DAT_fffffff8
    //         004bf249     MOV        this,dword ptr [EBP + 0x20]
    //         004bf24c     PUSH       EDX=>DAT_fffffff4
    //         004bf24d     ADD        EAX,0x5
    //         004bf250     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf253     PUSH       EAX=>DAT_fffffff0
    //         004bf254     PUSH       EDX
    //         004bf255     CALL       EBX=>GDI32.DLL::TextOutA
    //                              spnl_obj.cpp:198 (18)
    //         004bf257     MOV        this,dword ptr [EBP + 0x20]
    //         004bf25a     MOV        EAX,dword ptr [ESP + 0x18]
    //         004bf25e     PUSH       EAX
    //         004bf25f     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf262     PUSH       EDX=>DAT_fffffff8
    //         004bf263     CALL       dword ptr [->GDI32.DLL::SelectObject]            = 0048b192
    //                              spnl_obj.cpp:199 (15)
    //         004bf269     MOV        EAX,dword ptr [EBP + 0x20]
    //         004bf26c     PUSH       0x0
    //         004bf26e     MOV        this,dword ptr [EAX + 0x38]
    //         004bf271     PUSH       this=>DAT_fffffff8
    //         004bf272     CALL       dword ptr [->GDI32.DLL::SelectClipRgn]           = 0048b2fc
    //                               LAB_004bf278                                                 XREF[1]:     004bf203(j)  
    //                              spnl_obj.cpp:202 (14)
    //         004bf278     MOV        this,dword ptr [EBP + 0x20]
    //         004bf27b     PUSH       0x0
    //         004bf27d     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //         004bf282     MOV        EBX,dword ptr [ESP + 0x14]
    //                               LAB_004bf286                                                 XREF[1]:     004bf04a(j)  
    //                              spnl_obj.cpp:206 (12)
    //         004bf286     MOV        EAX,dword ptr [ESP + 0x10]
    //         004bf28a     TEST       EAX,EAX
    //         004bf28c     JZ         switchD_004bf313::caseD_4
    //                              spnl_obj.cpp:220 (62)
    //         004bf292     MOV        EDX,dword ptr [EBP + 0x214]
    //         004bf298     XOR        ESI,ESI
    //         004bf29a     MOV        AL,byte ptr [EDX + 0x8f]
    //         004bf2a0     CMP        AL,0x3
    //         004bf2a2     JZ         LAB_004bf3c9
    //         004bf2a8     CMP        AL,0x9
    //         004bf2aa     JZ         LAB_004bf3c1
    //         004bf2b0     CMP        AL,0x4
    //         004bf2b2     JZ         LAB_004bf3c1
    //         004bf2b8     CMP        AL,0x5
    //         004bf2ba     JZ         LAB_004bf3c1
    //         004bf2c0     CMP        AL,0x6
    //         004bf2c2     JZ         LAB_004bf3c1
    //         004bf2c8     CMP        AL,0x7
    //         004bf2ca     JZ         LAB_004bf3c1
    //                              spnl_obj.cpp:270 (8)
    //         004bf2d0     CMP        AL,0x1
    //         004bf2d2     JNZ        LAB_004bf35a
    //                              spnl_obj.cpp:272 (3)
    //         004bf2d8     OR         EDI,0xffffffff
    //                              spnl_obj.cpp:274 (2)
    //         004bf2db     XOR        this,this
    //                              spnl_obj.cpp:325 (29)
    //         004bf2dd     LEA        ESI,[EDX + 0x70]
    //                               LAB_004bf2e0                                                 XREF[1]:     004bf2f6(j)  
    //         004bf2e0     FLD        float ptr [ESI]
    //         004bf2e2     FCOMP      float ptr [DAT_00574524]                         = align(12)
    //         004bf2e8     FNSTSW     AX
    //         004bf2ea     TEST       AH,0x41
    //         004bf2ed     JZ         LAB_004bf2fa
    //         004bf2ef     INC        this
    //         004bf2f0     ADD        ESI,0x4
    //         004bf2f3     CMP        this,0x3
    //         004bf2f6     JL         LAB_004bf2e0
    //         004bf2f8     JMP        LAB_004bf2ff
    //                               LAB_004bf2fa                                                 XREF[1]:     004bf2ed(j)  
    //                              spnl_obj.cpp:278 (5)
    //         004bf2fa     MOV        DI,word ptr [EDX + this->_padding_*0x2 + 0x6a]
    //                               LAB_004bf2ff                                                 XREF[1]:     004bf2f8(j)  
    //                              spnl_obj.cpp:282 (27)
    //         004bf2ff     MOVSX      ESI,DI
    //         004bf302     CMP        ESI,0x11
    //         004bf305     JA         switchD_004bf313::caseD_4
    //         004bf30b     XOR        EAX,EAX
    //         004bf30d     MOV        AL,byte ptr [ESI + switchD_004bf313::switchdat
    //                               switchD_004bf313::switchD
    //         004bf313     JMP        dword ptr [EAX*0x4 + switchD_004bf313::switchd   = 004bf31a
    //                               switchD_004bf313::caseD_f                                    XREF[5]:     004bf313(j), 004bf49c(*), 
    //                               switchD_004bf313::caseD_10                                                004bf4ac(*), 004bf4b0(*), 
    //                               switchD_004bf313::caseD_11                                                004bf4b4(*)  
    //                               switchD_004bf313::caseD_0
    //                              spnl_obj.cpp:287 (7)
    //         004bf31a     MOV        ESI,0x2
    //         004bf31f     JMP        LAB_004bf331
    //                               switchD_004bf313::caseD_1                                    XREF[2]:     004bf313(j), 004bf4a0(*)  
    //                              spnl_obj.cpp:288 (4)
    //         004bf321     XOR        ESI,ESI
    //         004bf323     JMP        LAB_004bf331
    //                               switchD_004bf313::caseD_2                                    XREF[2]:     004bf313(j), 004bf4a4(*)  
    //                              spnl_obj.cpp:289 (7)
    //         004bf325     MOV        ESI,0x1
    //         004bf32a     JMP        LAB_004bf331
    //                               switchD_004bf313::caseD_3                                    XREF[2]:     004bf313(j), 004bf4a8(*)  
    //                              spnl_obj.cpp:290 (5)
    //         004bf32c     MOV        ESI,0x3
    //                               LAB_004bf331                                                 XREF[3]:     004bf31f(j), 004bf323(j), 
    //                                                                                                         004bf32a(j)  
    //                              spnl_obj.cpp:296 (25)
    //         004bf331     FLD        float ptr [EDX + this->_padding_*0x4 + 0x70]
    //         004bf335     PUSH       0x0
    //         004bf337     CALL       __ftol                                           undefined __ftol()
    //         004bf33c     PUSH       EAX=>DAT_fffffff8
    //         004bf33d     PUSH       0x0=>DAT_fffffff4
    //         004bf33f     PUSH       ESI=>DAT_fffffff0
    //         004bf340     PUSH       0x0
    //         004bf342     MOV        this,EBP
    //         004bf344     CALL       dword ptr [EBX + 0xe0]
    //                              spnl_obj.cpp:324 (5)
    //         004bf34a     MOV        this,EBP
    //         004bf34c     CALL       dword ptr [EBX + 0x2c]
    //                              spnl_obj.cpp:325 (11)
    //         004bf34f     POP        EDI
    //         004bf350     POP        ESI
    //         004bf351     POP        EBP
    //         004bf352     POP        EBX
    //         004bf353     ADD        ESP,0xe4
    //         004bf359     RET
    //                               LAB_004bf35a                                                 XREF[1]:     004bf2d2(j)  
    //                              spnl_obj.cpp:303 (8)
    //         004bf35a     CMP        AL,0x2
    //         004bf35c     JNZ        switchD_004bf313::caseD_4
    //                              spnl_obj.cpp:308 (25)
    //         004bf362     MOVSX      EAX,word ptr [EDX + 0x13e]
    //         004bf369     MOV        ESI,dword ptr [EBX + 0xe0]
    //         004bf36f     PUSH       EAX
    //         004bf370     PUSH       EAX=>DAT_fffffff8
    //         004bf371     PUSH       offset DAT_fffffff4
    //         004bf373     PUSH       offset DAT_fffffff0
    //         004bf375     PUSH       0x0
    //         004bf377     MOV        this,EBP
    //         004bf379     CALL       ESI
    //                              spnl_obj.cpp:311 (6)
    //         004bf37b     MOV        this,dword ptr [EBP + 0x214]
    //                              spnl_obj.cpp:313 (19)
    //         004bf381     MOVSX      EAX,word ptr [ECX + this->_padding_]
    //         004bf388     PUSH       EAX
    //         004bf389     PUSH       EAX=>DAT_fffffff8
    //         004bf38a     PUSH       offset DAT_fffffff4
    //         004bf38c     PUSH       offset DAT_fffffff0
    //         004bf38e     PUSH       0x1
    //         004bf390     MOV        this,EBP
    //         004bf392     CALL       ESI
    //                              spnl_obj.cpp:316 (12)
    //         004bf394     MOV        EDX,dword ptr [EBP + 0x214]
    //         004bf39a     FLD        float ptr [EDX + 0x114]
    //                              spnl_obj.cpp:318 (17)
    //         004bf3a0     CALL       __ftol                                           undefined __ftol()
    //         004bf3a5     PUSH       EAX
    //         004bf3a6     PUSH       EAX=>DAT_fffffff8
    //         004bf3a7     PUSH       offset DAT_fffffff4
    //         004bf3a9     PUSH       offset DAT_fffffff0
    //         004bf3ab     PUSH       0x2
    //         004bf3ad     MOV        this,EBP
    //         004bf3af     CALL       ESI
    //                              spnl_obj.cpp:324 (5)
    //         004bf3b1     MOV        this,EBP
    //         004bf3b3     CALL       dword ptr [EBX + 0x2c]
    //                              spnl_obj.cpp:325 (11)
    //         004bf3b6     POP        EDI
    //         004bf3b7     POP        ESI
    //         004bf3b8     POP        EBP
    //         004bf3b9     POP        EBX
    //         004bf3ba     ADD        ESP,0xe4
    //         004bf3c0     RET
    //                               LAB_004bf3c1                                                 XREF[5]:     004bf2aa(j), 004bf2b2(j), 
    //                                                                                                         004bf2ba(j), 004bf2c2(j), 
    //                                                                                                         004bf2ca(j)  
    //                              spnl_obj.cpp:229 (8)
    //         004bf3c1     CMP        AL,0x3
    //         004bf3c3     JZ         LAB_004bf3c9
    //         004bf3c5     CMP        AL,0x4
    //         004bf3c7     JNZ        LAB_004bf3e5
    //                               LAB_004bf3c9                                                 XREF[2]:     004bf2a2(j), 004bf3c3(j)  
    //                              spnl_obj.cpp:233 (23)
    //         004bf3c9     MOVSX      EAX,word ptr [EDX + 0x13e]
    //         004bf3d0     PUSH       EAX
    //         004bf3d1     PUSH       EAX=>DAT_fffffff8
    //         004bf3d2     PUSH       offset DAT_fffffff4
    //         004bf3d4     PUSH       offset DAT_fffffff0
    //         004bf3d6     PUSH       0x0
    //         004bf3d8     MOV        this,EBP
    //         004bf3da     CALL       dword ptr [EBX + 0xe0]
    //                              spnl_obj.cpp:234 (5)
    //         004bf3e0     MOV        ESI,0x1
    //                               LAB_004bf3e5                                                 XREF[1]:     004bf3c7(j)  
    //                              spnl_obj.cpp:238 (13)
    //         004bf3e5     MOV        EAX,dword ptr [EBP + 0x214]
    //         004bf3eb     MOV        this,word ptr [EAX + 0x13c]
    //                              spnl_obj.cpp:241 (14)
    //         004bf3f2     MOV        AL,byte ptr [EAX + 0x8f]
    //         004bf3f8     CMP        AL,0x4
    //         004bf3fa     JZ         LAB_004bf400
    //         004bf3fc     CMP        AL,0x6
    //         004bf3fe     JNZ        LAB_004bf413
    //                               LAB_004bf400                                                 XREF[1]:     004bf3fa(j)  
    //                              spnl_obj.cpp:243 (18)
    //         004bf400     MOVSX      EAX,this
    //         004bf403     PUSH       EAX
    //         004bf404     PUSH       EAX=>DAT_fffffff8
    //         004bf405     PUSH       offset DAT_fffffff4
    //         004bf407     PUSH       offset DAT_fffffff0
    //         004bf409     PUSH       ESI
    //         004bf40a     MOV        this,EBP
    //         004bf40c     CALL       dword ptr [EBX + 0xe0]
    //                              spnl_obj.cpp:244 (1)
    //         004bf412     INC        ESI
    //                               LAB_004bf413                                                 XREF[1]:     004bf3fe(j)  
    //                              spnl_obj.cpp:248 (7)
    //         004bf413     MOV        this,EBP
    //         004bf415     CALL       TRIBE_Scenario_Editor_Panel_Object::get_pierce   long get_pierce_armor(TRIBE_Scenario_Editor_P
    //                              spnl_obj.cpp:251 (24)
    //         004bf41a     MOV        this,dword ptr [EBP + 0x214]
    //         004bf420     MOV        EDI,EAX
    //         004bf422     MOV        this,byte ptr [ECX + this+0x8f]
    //         004bf428     CMP        this,0x4
    //         004bf42b     JZ         LAB_004bf432
    //         004bf42d     CMP        this,0x6
    //         004bf430     JNZ        LAB_004bf445
    //                               LAB_004bf432                                                 XREF[1]:     004bf42b(j)  
    //                              spnl_obj.cpp:253 (18)
    //         004bf432     MOVSX      EAX,AX
    //         004bf435     PUSH       EAX
    //         004bf436     PUSH       EAX=>DAT_fffffff8
    //         004bf437     PUSH       offset DAT_fffffff4
    //         004bf439     PUSH       offset DAT_fffffff0
    //         004bf43b     PUSH       ESI
    //         004bf43c     MOV        this,EBP
    //         004bf43e     CALL       dword ptr [EBX + 0xe0]
    //                              spnl_obj.cpp:254 (1)
    //         004bf444     INC        ESI
    //                               LAB_004bf445                                                 XREF[1]:     004bf430(j)  
    //                              spnl_obj.cpp:259 (22)
    //         004bf445     MOV        EAX,dword ptr [EBP + 0x214]
    //         004bf44b     MOV        this,byte ptr [EAX + 0x8f]
    //         004bf451     CMP        this,0x4
    //         004bf454     JZ         LAB_004bf45b
    //         004bf456     CMP        this,0x6
    //         004bf459     JNZ        switchD_004bf313::caseD_4
    //                               LAB_004bf45b                                                 XREF[1]:     004bf454(j)  
    //                              spnl_obj.cpp:261 (11)
    //         004bf45b     FLD        float ptr [EAX + 0x140]
    //         004bf461     CALL       __ftol                                           undefined __ftol()
    //                              spnl_obj.cpp:262 (21)
    //         004bf466     MOVSX      EDX,DI
    //         004bf469     MOVSX      EAX,AX
    //         004bf46c     PUSH       EDX
    //         004bf46d     PUSH       EAX=>DAT_fffffff8
    //         004bf46e     PUSH       offset DAT_fffffff4
    //         004bf470     PUSH       offset DAT_fffffff0
    //         004bf472     PUSH       ESI
    //         004bf473     MOV        this,EBP
    //         004bf475     CALL       dword ptr [EBX + 0xe0]
    //                               switchD_004bf313::caseD_5                                    XREF[6]:     004bf28c(j), 004bf305(j), 
    //                               switchD_004bf313::caseD_6                                                 004bf313(j), 004bf35c(j), 
    //                               switchD_004bf313::caseD_7                                                 004bf459(j), 004bf4b8(*)  
    //                               switchD_004bf313::caseD_8
    //                               switchD_004bf313::caseD_9
    //                               switchD_004bf313::caseD_a
    //                               switchD_004bf313::caseD_b
    //                               switchD_004bf313::caseD_c
    //                               switchD_004bf313::caseD_d
    //                               switchD_004bf313::caseD_e
    //                               switchD_004bf313::caseD_4
    //                              spnl_obj.cpp:324 (5)
    //         004bf47b     MOV        this,EBP
    //         004bf47d     CALL       dword ptr [EBX + 0x2c]
    //                              spnl_obj.cpp:325 (11)
    //         004bf480     POP        EDI
    //         004bf481     POP        ESI
    //         004bf482     POP        EBP
    //         004bf483     POP        EBX
    //         004bf484     ADD        ESP,0xe4
    //         004bf48a     RET
    //                               LAB_004bf48b                                                 XREF[4]:     004bee81(j), 004bee8a(j), 
    //                                                                                                         004bee93(j), 004beebf(j)  
    //                              spnl_obj.cpp:97 (3)
    //         004bf48b     MOV        dword ptr [EBP + 0x38],EDI
    //                              spnl_obj.cpp:325 (64)
    //         004bf48e     POP        EDI
    //         004bf48f     POP        ESI
    //         004bf490     POP        EBP
    //         004bf491     POP        EBX
    //         004bf492     ADD        ESP,0xe4
    //         004bf498     RET
}

// Offset: 0x004BF499
undefined FUN_004bf499() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004bf499()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004bf499
    //         004bf499     NOP
    //         004bf49a     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004bf313::switchdataD_004bf49c                       XREF[1]:     draw:004bf313(*)  
}

// Offset: 0x004BF4D0
void TRIBE_Scenario_Editor_Panel_Object::draw_item(int param_1, int param_2, ValueType param_3, int param_4, int param_5) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual void __thiscall TRIBE_Scenario_Editor_Panel_Object::draw_item(int,int,enum TRIBE_P... *
    //                              *********************************************************************************************************
    //                              void __thiscall draw_item(TRIBE_Scenario_Editor_Panel_Object * this,
    //              void              <VOID>         <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004bf4fc(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004bf4e3(R)  
    //              ValueType         Stack[0xc]:4   param_3                   XREF[1]:     004bf530(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[4]:     004bf544(R), 004bf561(R), 004bf59a(R), 004bf5b4(R)  
    //              int               Stack[0x14]:4  param_5                   XREF[2]:     004bf55d(R), 004bf596(R)  
    //              char[20]          Stack[-0x18]   val_str                   XREF[0,7]:   004bf548(*), 004bf56d(*), 004bf582(*), 004bf5a0(*), 
    //                                                                                     004bf5b8(*), 004bf5cd(W), 004bf5d2(R)  
    //                               ?draw_item@TRIBE_Scenario_Editor_Panel_Object@@UAEXHHW4Valu  XREF[1]:     00574520(*)  
    //                               TRIBE_Scenario_Editor_Panel_Object::draw_item
    //                              spnl_obj.cpp:333 (9)
    //         004bf4d0     SUB        ESP,0x14
    //         004bf4d3     PUSH       EBX
    //         004bf4d4     PUSH       EBP
    //         004bf4d5     PUSH       ESI
    //         004bf4d6     MOV        ESI,this
    //         004bf4d8     PUSH       EDI
    //                              spnl_obj.cpp:338 (35)
    //         004bf4d9     MOV        EAX,dword ptr [ESI + 0x104]
    //         004bf4df     TEST       EAX,EAX
    //         004bf4e1     JZ         LAB_004bf530
    //         004bf4e3     MOV        EDI,dword ptr [ESP + param_2]
    //         004bf4e7     CMP        EDI,-0x1
    //         004bf4ea     JZ         LAB_004bf530
    //         004bf4ec     MOV        this,dword ptr [ESI + 0x20]
    //         004bf4ef     PUSH       0x1
    //         004bf4f1     PUSH       0x0
    //         004bf4f3     CALL       TDrawArea::Lock                                  uchar * Lock(TDrawArea * this, char * param_1
    //         004bf4f8     TEST       EAX,EAX
    //         004bf4fa     JZ         LAB_004bf530
    //                              spnl_obj.cpp:340 (42)
    //         004bf4fc     MOV        EAX,dword ptr [ESP + param_1]
    //         004bf500     MOV        this,dword ptr [ESI + 0x10]
    //         004bf503     PUSH       0x0
    //         004bf505     PUSH       0x0
    //         004bf507     LEA        EAX,[EAX + EAX*0x8]
    //         004bf50a     PUSH       EDI
    //         004bf50b     LEA        EDX,[ECX + EAX*0x2 + this+0x1e]
    //         004bf50f     MOV        EAX,dword ptr [ESI + 0xc]
    //         004bf512     MOV        this,dword ptr [ESI + 0x20]
    //         004bf515     ADD        EAX,0x3c
    //         004bf518     PUSH       EDX
    //         004bf519     PUSH       EAX
    //         004bf51a     PUSH       this
    //         004bf51b     MOV        this,dword ptr [ESI + 0x104]
    //         004bf521     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                              spnl_obj.cpp:341 (10)
    //         004bf526     MOV        this,dword ptr [ESI + 0x20]
    //         004bf529     PUSH       0x0
    //         004bf52b     CALL       TDrawArea::Unlock                                void Unlock(TDrawArea * this, char * param_1)
    //                               LAB_004bf530                                                 XREF[3]:     004bf4e1(j), 004bf4ea(j), 
    //                                                                                                         004bf4fa(j)  
    //                              spnl_obj.cpp:345 (20)
    //         004bf530     MOV        EAX,dword ptr [ESP + param_3]
    //         004bf534     CMP        EAX,0x3
    //         004bf537     JA         switchD_004bf53d::default
    //                               switchD_004bf53d::switchD
    //         004bf53d     JMP        dword ptr [EAX*0x4 + switchD_004bf53d::switchd   = 004bf544
    //                               switchD_004bf53d::caseD_0                                    XREF[2]:     004bf53d(j), 004bf6a8(*)  
    //                              spnl_obj.cpp:348 (23)
    //         004bf544     MOV        EDX,dword ptr [ESP + param_4]
    //         004bf548     LEA        EAX=>val_str[4],[ESP + 0x10]
    //         004bf54c     PUSH       EDX
    //         004bf54d     PUSH       s_%d                                             = 6425h
    //         004bf552     PUSH       EAX
    //         004bf553     CALL       sprintf                                          undefined sprintf()
    //         004bf558     ADD        ESP,0xc
    //                              spnl_obj.cpp:349 (2)
    //         004bf55b     JMP        LAB_004bf5d2
    //                               switchD_004bf53d::caseD_1                                    XREF[2]:     004bf53d(j), 004bf6ac(*)  
    //                              spnl_obj.cpp:352 (12)
    //         004bf55d     MOV        EAX,dword ptr [ESP + param_5]
    //         004bf561     MOV        this,dword ptr [ESP + param_4]
    //         004bf565     CMP        EAX,this
    //         004bf567     JLE        LAB_004bf581
    //                              spnl_obj.cpp:353 (22)
    //         004bf569     SUB        EAX,this
    //         004bf56b     PUSH       EAX
    //         004bf56c     PUSH       this
    //         004bf56d     LEA        this=>val_str[4],[ESP + 0x18]
    //         004bf571     PUSH       s_%d+%d                                          = "%d+%d"
    //         004bf576     PUSH       this
    //         004bf577     CALL       sprintf                                          undefined sprintf()
    //         004bf57c     ADD        ESP,0x10
    //                              spnl_obj.cpp:354 (2)
    //         004bf57f     JMP        LAB_004bf5d2
    //                               LAB_004bf581                                                 XREF[1]:     004bf567(j)  
    //                              spnl_obj.cpp:355 (19)
    //         004bf581     PUSH       this
    //         004bf582     LEA        EDX=>val_str[4],[ESP + 0x14]
    //         004bf586     PUSH       s_%d                                             = 6425h
    //         004bf58b     PUSH       EDX
    //         004bf58c     CALL       sprintf                                          undefined sprintf()
    //         004bf591     ADD        ESP,0xc
    //                              spnl_obj.cpp:356 (2)
    //         004bf594     JMP        LAB_004bf5d2
    //                               switchD_004bf53d::caseD_2                                    XREF[2]:     004bf53d(j), 004bf6b0(*)  
    //                              spnl_obj.cpp:359 (28)
    //         004bf596     MOV        EAX,dword ptr [ESP + param_5]
    //         004bf59a     MOV        this,dword ptr [ESP + param_4]
    //         004bf59e     PUSH       EAX
    //         004bf59f     PUSH       this
    //         004bf5a0     LEA        EDX=>val_str[4],[ESP + 0x18]
    //         004bf5a4     PUSH       s_%d/%d                                          = "%d/%d"
    //         004bf5a9     PUSH       EDX
    //         004bf5aa     CALL       sprintf                                          undefined sprintf()
    //         004bf5af     ADD        ESP,0x10
    //                              spnl_obj.cpp:360 (2)
    //         004bf5b2     JMP        LAB_004bf5d2
    //                               switchD_004bf53d::caseD_3                                    XREF[2]:     004bf53d(j), 004bf6b4(*)  
    //                              spnl_obj.cpp:363 (23)
    //         004bf5b4     MOV        EAX,dword ptr [ESP + param_4]
    //         004bf5b8     LEA        this=>val_str[4],[ESP + 0x10]
    //         004bf5bc     PUSH       EAX
    //         004bf5bd     PUSH       s_%d%%                                           = "%d%%"
    //         004bf5c2     PUSH       this
    //         004bf5c3     CALL       sprintf                                          undefined sprintf()
    //         004bf5c8     ADD        ESP,0xc
    //                              spnl_obj.cpp:364 (2)
    //         004bf5cb     JMP        LAB_004bf5d2
    //                               switchD_004bf53d::default                                    XREF[1]:     004bf537(j)  
    //                              spnl_obj.cpp:367 (5)
    //         004bf5cd     MOV        byte ptr [ESP + val_str[4]],0x0
    //                               LAB_004bf5d2                                                 XREF[5]:     004bf55b(j), 004bf57f(j), 
    //                                                                                                         004bf594(j), 004bf5b2(j), 
    //                                                                                                         004bf5cb(j)  
    //                              spnl_obj.cpp:371 (30)
    //         004bf5d2     MOV        AL,byte ptr [ESP + val_str[4]]
    //         004bf5d6     TEST       AL,AL
    //         004bf5d8     JZ         LAB_004bf69b
    //         004bf5de     MOV        this,dword ptr [ESI + 0x20]
    //         004bf5e1     PUSH       0x0
    //         004bf5e3     CALL       TDrawArea::GetDc                                 void * GetDc(TDrawArea * this, char * param_1)
    //         004bf5e8     TEST       EAX,EAX
    //         004bf5ea     JZ         LAB_004bf69b
    //                              spnl_obj.cpp:373 (15)
    //         004bf5f0     MOV        EDX,dword ptr [ESI + 0x20]
    //         004bf5f3     PUSH       0x1
    //         004bf5f5     MOV        EAX,dword ptr [EDX + 0x38]
    //         004bf5f8     PUSH       EAX
    //         004bf5f9     CALL       dword ptr [->GDI32.DLL::SetBkMode]               = 0048b340
    //                              spnl_obj.cpp:374 (18)
    //         004bf5ff     MOV        this,dword ptr [ESI + 0x20]
    //         004bf602     PUSH       0xffffff
    //         004bf607     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf60a     PUSH       EDX
    //         004bf60b     CALL       dword ptr [->GDI32.DLL::SetTextColor]            = 0048b318
    //                              spnl_obj.cpp:375 (22)
    //         004bf611     MOV        this,dword ptr [ESI + 0x20]
    //         004bf614     MOV        EAX,dword ptr [ESI + 0x88]
    //         004bf61a     MOV        EBX,dword ptr [->GDI32.DLL::SelectClipRgn]       = 0048b2fc
    //         004bf620     PUSH       EAX
    //         004bf621     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf624     PUSH       EDX
    //         004bf625     CALL       EBX=>GDI32.DLL::SelectClipRgn
    //                              spnl_obj.cpp:376 (26)
    //         004bf627     MOV        this,dword ptr [ESI + 0x20]
    //         004bf62a     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004bf630     MOV        EBP,dword ptr [->GDI32.DLL::SelectObject]        = 0048b192
    //         004bf636     PUSH       EAX
    //         004bf637     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf63a     PUSH       EDX
    //         004bf63b     CALL       EBP=>GDI32.DLL::SelectObject
    //         004bf63d     MOV        dword ptr [ESP + 0x34],EAX
    //                              spnl_obj.cpp:377 (55)
    //         004bf641     LEA        EDI,[ESP + 0x10]
    //         004bf645     OR         this,0xffffffff
    //         004bf648     XOR        EAX,EAX
    //         004bf64a     SCASB.RE   ES:EDI
    //         004bf64c     NOT        this
    //         004bf64e     MOV        EDX,dword ptr [ESI + 0x10]
    //         004bf651     DEC        this
    //         004bf652     LEA        EAX,[ESP + 0x10]
    //         004bf656     PUSH       this
    //         004bf657     PUSH       EAX
    //         004bf658     MOV        EAX,dword ptr [ESP + 0x30]
    //         004bf65c     LEA        this,[EAX + EAX*0x8]
    //         004bf65f     LEA        EAX,[EDX + this->_padding_*0x2 + 0x20]
    //         004bf663     MOV        this,dword ptr [ESI + 0xc]
    //         004bf666     MOV        EDX,dword ptr [ESI + 0x20]
    //         004bf669     PUSH       EAX
    //         004bf66a     ADD        this,0x64
    //         004bf66d     MOV        EAX,dword ptr [EDX + 0x38]
    //         004bf670     PUSH       this
    //         004bf671     PUSH       EAX
    //         004bf672     CALL       dword ptr [->GDI32.DLL::TextOutA]                = 0048b30c
    //                              spnl_obj.cpp:378 (14)
    //         004bf678     MOV        EDX,dword ptr [ESI + 0x20]
    //         004bf67b     MOV        this,dword ptr [ESP + 0x34]
    //         004bf67f     PUSH       this
    //         004bf680     MOV        EAX,dword ptr [EDX + 0x38]
    //         004bf683     PUSH       EAX
    //         004bf684     CALL       EBP=>GDI32.DLL::SelectObject
    //                              spnl_obj.cpp:379 (11)
    //         004bf686     MOV        this,dword ptr [ESI + 0x20]
    //         004bf689     PUSH       0x0
    //         004bf68b     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004bf68e     PUSH       EDX
    //         004bf68f     CALL       EBX=>GDI32.DLL::SelectClipRgn
    //                              spnl_obj.cpp:380 (10)
    //         004bf691     MOV        this,dword ptr [ESI + 0x20]
    //         004bf694     PUSH       0x0
    //         004bf696     CALL       TDrawArea::ReleaseDc                             void ReleaseDc(TDrawArea * this, char * param
    //                               LAB_004bf69b                                                 XREF[2]:     004bf5d8(j), 004bf5ea(j)  
    //                              spnl_obj.cpp:382 (29)
    //         004bf69b     POP        EDI
    //         004bf69c     POP        ESI
    //         004bf69d     POP        EBP
    //         004bf69e     POP        EBX
    //         004bf69f     ADD        ESP,0x14
    //         004bf6a2     RET        0x14
}

// Offset: 0x004BF6A5
undefined FUN_004bf6a5() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004bf6a5()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004bf6a5
    //         004bf6a5     NOP
    //         004bf6a6     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004bf53d::switchdataD_004bf6a8                       XREF[1]:     draw_item:004bf53d(*)  
}

// Offset: 0x004BF6C0
long TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action(long,long... *
    //                              *********************************************************************************************************
    //                              long __thiscall mouse_left_up_action(TRIBE_Scenario_Editor_Panel_Obj
    //              long              EAX:4          <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //              long              Stack[0x8]:4   param_2
    //              int               Stack[0xc]:4   param_3
    //              int               Stack[0x10]:4  param_4
    //                               ?mouse_left_up_action@TRIBE_Scenario_Editor_Panel_Object@@U  XREF[1]:     005744d0(*)  
    //                               TRIBE_Scenario_Editor_Panel_Object::mouse_left_up_action
    //                              spnl_obj.cpp:390 (5)
    //         004bf6c0     CALL       TPanel::release_mouse                            void release_mouse(TPanel * this)
    //                              spnl_obj.cpp:393 (11)
    //         004bf6c5     MOV        EAX,[rge_base_game]                              = 00000000
    //         004bf6ca     MOV        EAX,dword ptr [EAX + 0x1b0]
    //                              spnl_obj.cpp:396 (5)
    //         004bf6d0     MOV        EAX,0x1
    //                              spnl_obj.cpp:397 (3)
    //         004bf6d5     RET        0x10
}

// Offset: 0x004BF6E0
long get_pierce_armor(TRIBE_Scenario_Editor_Panel_Object* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: long __thiscall TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor(void)                    *
    //                              *********************************************************************************************************
    //                              long __thiscall get_pierce_armor(TRIBE_Scenario_Editor_Panel_Object 
    //              long              EAX:4          <RETURN>
    //              TRIBE_Scenario    ECX:4 (auto)   this
    //                               ?get_pierce_armor@TRIBE_Scenario_Editor_Panel_Object@@QAEJXZ XREF[1]:     draw:004bf415(c)  
    //                               TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor
    //                              spnl_obj.cpp:406 (10)
    //         004bf6e0     MOV        this,dword ptr [ECX + this->master_game_obj]
    //         004bf6e6     TEST       this,this
    //         004bf6e8     JNZ        LAB_004bf6ed
    //                              spnl_obj.cpp:411 (2)
    //         004bf6ea     XOR        EAX,EAX
    //                              spnl_obj.cpp:423 (1)
    //         004bf6ec     RET
    //                               LAB_004bf6ed                                                 XREF[1]:     004bf6e8(j)  
    //                              spnl_obj.cpp:412 (6)
    //         004bf6ed     CMP        byte ptr [ECX + this->_padding_],0x46
    //         004bf6f1     JZ         LAB_004bf6f6
    //                              spnl_obj.cpp:413 (2)
    //         004bf6f3     XOR        EAX,EAX
    //                              spnl_obj.cpp:423 (1)
    //         004bf6f5     RET
    //                               LAB_004bf6f6                                                 XREF[1]:     004bf6f1(j)  
    //                              spnl_obj.cpp:416 (13)
    //         004bf6f6     MOVSX      EDX,word ptr [ECX + this+0x102]
    //         004bf6fd     XOR        EAX,EAX
    //         004bf6ff     TEST       EDX,EDX
    //         004bf701     JLE        LAB_004bf719
    //                              spnl_obj.cpp:423 (6)
    //         004bf703     MOV        this,dword ptr [ECX + this->_padding_]
    //                               LAB_004bf709                                                 XREF[1]:     004bf717(j)  
    //                              spnl_obj.cpp:418 (6)
    //         004bf709     CMP        word ptr [this->_padding_],0x3
    //         004bf70d     JNZ        LAB_004bf713
    //                              spnl_obj.cpp:419 (4)
    //         004bf70f     MOVSX      EAX,word ptr [ECX + this+0x2]
    //                               LAB_004bf713                                                 XREF[1]:     004bf70d(j)  
    //                              spnl_obj.cpp:416 (6)
    //         004bf713     ADD        this,0x4
    //         004bf716     DEC        EDX
    //         004bf717     JNZ        LAB_004bf709
    //                               LAB_004bf719                                                 XREF[1]:     004bf701(j)  
    //                              spnl_obj.cpp:423 (1)
    //         004bf719     RET
}

