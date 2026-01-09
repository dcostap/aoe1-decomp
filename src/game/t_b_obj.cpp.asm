#include "common.h"
#include "t_b_obj.h"

TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6, int param_7) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Building_Object(TRIBE_Building_Object * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c81e8(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004c81ee(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004c8202(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004c8206(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004c8282(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c81f9(W)  
    //                               ??0TRIBE_Building_Object@@QAE@HPAVRGE_Game_World@@H@Z        XREF[1]:     load:00511b6d(c)  
    //                               TRIBE_Building_Object::TRIBE_Building_Object
    //                              t_b_obj.cpp:117 (50)
    //         004c81d0     PUSH       -0x1
    //         004c81d2     PUSH       FUN_0055fab8
    //         004c81d7     MOV        EAX,FS:[0x0]
    //         004c81dd     PUSH       EAX
    //         004c81de     MOV        dword ptr FS:[0x0],ESP
    //         004c81e5     PUSH       this
    //         004c81e6     PUSH       EBX
    //         004c81e7     PUSH       EBP
    //         004c81e8     MOV        EBP,dword ptr [ESP + param_1]
    //         004c81ec     PUSH       ESI
    //         004c81ed     PUSH       EDI
    //         004c81ee     MOV        EDI,dword ptr [ESP + param_2]
    //         004c81f2     XOR        EBX,EBX
    //         004c81f4     MOV        ESI,this
    //         004c81f6     PUSH       EBX
    //         004c81f7     PUSH       EDI
    //         004c81f8     PUSH       EBP
    //         004c81f9     MOV        dword ptr [ESP + local_10],ESI
    //         004c81fd     CALL       TRIBE_Combat_Object::TRIBE_Combat_Object         undefined TRIBE_Combat_Object(TRIBE_Combat_Ob
    //                              t_b_obj.cpp:118 (78)
    //         004c8202     MOV        EAX,dword ptr [ESP + param_3]
    //         004c8206     MOV        dword ptr [ESP + local_4],EBX
    //         004c820a     CMP        EAX,EBX
    //         004c820c     MOV        dword ptr [ESI + 0x1c8],EBX
    //         004c8212     MOV        word ptr [ESI + 0x1cc],BX
    //         004c8219     MOV        word ptr [ESI + 0x1ce],BX
    //         004c8220     MOV        byte ptr [ESI + 0x1d0],0x1
    //         004c8227     MOV        dword ptr [ESI + 0x1d4],EBX
    //         004c822d     MOV        byte ptr [ESI + 0x1d8],BL
    //         004c8233     MOV        byte ptr [ESI + 0x1d9],BL
    //         004c8239     MOV        word ptr [ESI + 0x1da],0xffff
    //         004c8242     MOV        dword ptr [ESI + 0x1e8],EBX
    //         004c8248     MOV        dword ptr [ESI],TRIBE_Building_Object::`vftable' = 004c8090
    //         004c824e     JZ         LAB_004c8259
    //                              t_b_obj.cpp:119 (9)
    //         004c8250     PUSH       EDI
    //         004c8251     PUSH       EBP
    //         004c8252     MOV        this,ESI
    //         004c8254     CALL       TRIBE_Building_Object::setup                     int setup(TRIBE_Building_Object * this, int p
    //                               LAB_004c8259                                                 XREF[1]:     004c824e(j)  
    //                              t_b_obj.cpp:122 (41)
    //         004c8259     FLD        float ptr [ESI + 0x3c]
    //         004c825c     CALL       __ftol                                           undefined __ftol()
    //         004c8261     FLD        float ptr [ESI + 0x38]
    //         004c8264     MOV        EDI,EAX
    //         004c8266     CALL       __ftol                                           undefined __ftol()
    //         004c826b     MOV        this,dword ptr [EDI*0x4 + unified_map_offsets]   = 00000000
    //         004c8272     LEA        EDX,[this->_padding_ + EAX*0x4]
    //         004c8275     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8278     PUSH       EDX
    //         004c8279     PUSH       ESI
    //         004c827a     MOV        this,dword ptr [EAX + 0x40]
    //         004c827d     CALL       RGE_Doppleganger_Creator::add_doppleganger_check int add_doppleganger_check(RGE_Doppleganger_C
    //                              t_b_obj.cpp:124 (29)
    //         004c8282     MOV        this,dword ptr [ESP + local_c]
    //         004c8286     MOV        dword ptr [ESI + 0x1e8],EAX
    //         004c828c     MOV        EAX,ESI
    //         004c828e     POP        EDI
    //         004c828f     POP        ESI
    //         004c8290     POP        EBP
    //         004c8291     MOV        dword ptr FS:[0x0],this
    //         004c8298     POP        EBX
    //         004c8299     ADD        ESP,0x10
    //         004c829c     RET        0xc
    //         004c829f     ??         90h
}

TRIBE_Building_Object::TRIBE_Building_Object(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5, int param_6) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Building_Object(TRIBE_Building_Object * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c81e8(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004c81ee(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004c8202(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004c8206(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004c8282(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c81f9(W)  
    //                               ??0TRIBE_Building_Object@@QAE@HPAVRGE_Game_World@@H@Z        XREF[1]:     load:00511b6d(c)  
    //                               TRIBE_Building_Object::TRIBE_Building_Object
    //                              t_b_obj.cpp:117 (50)
    //         004c81d0     PUSH       -0x1
    //         004c81d2     PUSH       FUN_0055fab8
    //         004c81d7     MOV        EAX,FS:[0x0]
    //         004c81dd     PUSH       EAX
    //         004c81de     MOV        dword ptr FS:[0x0],ESP
    //         004c81e5     PUSH       this
    //         004c81e6     PUSH       EBX
    //         004c81e7     PUSH       EBP
    //         004c81e8     MOV        EBP,dword ptr [ESP + param_1]
    //         004c81ec     PUSH       ESI
    //         004c81ed     PUSH       EDI
    //         004c81ee     MOV        EDI,dword ptr [ESP + param_2]
    //         004c81f2     XOR        EBX,EBX
    //         004c81f4     MOV        ESI,this
    //         004c81f6     PUSH       EBX
    //         004c81f7     PUSH       EDI
    //         004c81f8     PUSH       EBP
    //         004c81f9     MOV        dword ptr [ESP + local_10],ESI
    //         004c81fd     CALL       TRIBE_Combat_Object::TRIBE_Combat_Object         undefined TRIBE_Combat_Object(TRIBE_Combat_Ob
    //                              t_b_obj.cpp:118 (78)
    //         004c8202     MOV        EAX,dword ptr [ESP + param_3]
    //         004c8206     MOV        dword ptr [ESP + local_4],EBX
    //         004c820a     CMP        EAX,EBX
    //         004c820c     MOV        dword ptr [ESI + 0x1c8],EBX
    //         004c8212     MOV        word ptr [ESI + 0x1cc],BX
    //         004c8219     MOV        word ptr [ESI + 0x1ce],BX
    //         004c8220     MOV        byte ptr [ESI + 0x1d0],0x1
    //         004c8227     MOV        dword ptr [ESI + 0x1d4],EBX
    //         004c822d     MOV        byte ptr [ESI + 0x1d8],BL
    //         004c8233     MOV        byte ptr [ESI + 0x1d9],BL
    //         004c8239     MOV        word ptr [ESI + 0x1da],0xffff
    //         004c8242     MOV        dword ptr [ESI + 0x1e8],EBX
    //         004c8248     MOV        dword ptr [ESI],TRIBE_Building_Object::`vftable' = 004c8090
    //         004c824e     JZ         LAB_004c8259
    //                              t_b_obj.cpp:119 (9)
    //         004c8250     PUSH       EDI
    //         004c8251     PUSH       EBP
    //         004c8252     MOV        this,ESI
    //         004c8254     CALL       TRIBE_Building_Object::setup                     int setup(TRIBE_Building_Object * this, int p
    //                               LAB_004c8259                                                 XREF[1]:     004c824e(j)  
    //                              t_b_obj.cpp:122 (41)
    //         004c8259     FLD        float ptr [ESI + 0x3c]
    //         004c825c     CALL       __ftol                                           undefined __ftol()
    //         004c8261     FLD        float ptr [ESI + 0x38]
    //         004c8264     MOV        EDI,EAX
    //         004c8266     CALL       __ftol                                           undefined __ftol()
    //         004c826b     MOV        this,dword ptr [EDI*0x4 + unified_map_offsets]   = 00000000
    //         004c8272     LEA        EDX,[this->_padding_ + EAX*0x4]
    //         004c8275     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8278     PUSH       EDX
    //         004c8279     PUSH       ESI
    //         004c827a     MOV        this,dword ptr [EAX + 0x40]
    //         004c827d     CALL       RGE_Doppleganger_Creator::add_doppleganger_check int add_doppleganger_check(RGE_Doppleganger_C
    //                              t_b_obj.cpp:124 (29)
    //         004c8282     MOV        this,dword ptr [ESP + local_c]
    //         004c8286     MOV        dword ptr [ESI + 0x1e8],EAX
    //         004c828c     MOV        EAX,ESI
    //         004c828e     POP        EDI
    //         004c828f     POP        ESI
    //         004c8290     POP        EBP
    //         004c8291     MOV        dword ptr FS:[0x0],this
    //         004c8298     POP        EBX
    //         004c8299     ADD        ESP,0x10
    //         004c829c     RET        0xc
    //         004c829f     ??         90h
}

TRIBE_Building_Object::TRIBE_Building_Object(int param_1, RGE_Game_World* param_2, int param_3) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Building_Object(TRIBE_Building_Object * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c81e8(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004c81ee(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004c8202(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004c8206(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004c8282(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c81f9(W)  
    //                               ??0TRIBE_Building_Object@@QAE@HPAVRGE_Game_World@@H@Z        XREF[1]:     load:00511b6d(c)  
    //                               TRIBE_Building_Object::TRIBE_Building_Object
    //                              t_b_obj.cpp:117 (50)
    //         004c81d0     PUSH       -0x1
    //         004c81d2     PUSH       FUN_0055fab8
    //         004c81d7     MOV        EAX,FS:[0x0]
    //         004c81dd     PUSH       EAX
    //         004c81de     MOV        dword ptr FS:[0x0],ESP
    //         004c81e5     PUSH       this
    //         004c81e6     PUSH       EBX
    //         004c81e7     PUSH       EBP
    //         004c81e8     MOV        EBP,dword ptr [ESP + param_1]
    //         004c81ec     PUSH       ESI
    //         004c81ed     PUSH       EDI
    //         004c81ee     MOV        EDI,dword ptr [ESP + param_2]
    //         004c81f2     XOR        EBX,EBX
    //         004c81f4     MOV        ESI,this
    //         004c81f6     PUSH       EBX
    //         004c81f7     PUSH       EDI
    //         004c81f8     PUSH       EBP
    //         004c81f9     MOV        dword ptr [ESP + local_10],ESI
    //         004c81fd     CALL       TRIBE_Combat_Object::TRIBE_Combat_Object         undefined TRIBE_Combat_Object(TRIBE_Combat_Ob
    //                              t_b_obj.cpp:118 (78)
    //         004c8202     MOV        EAX,dword ptr [ESP + param_3]
    //         004c8206     MOV        dword ptr [ESP + local_4],EBX
    //         004c820a     CMP        EAX,EBX
    //         004c820c     MOV        dword ptr [ESI + 0x1c8],EBX
    //         004c8212     MOV        word ptr [ESI + 0x1cc],BX
    //         004c8219     MOV        word ptr [ESI + 0x1ce],BX
    //         004c8220     MOV        byte ptr [ESI + 0x1d0],0x1
    //         004c8227     MOV        dword ptr [ESI + 0x1d4],EBX
    //         004c822d     MOV        byte ptr [ESI + 0x1d8],BL
    //         004c8233     MOV        byte ptr [ESI + 0x1d9],BL
    //         004c8239     MOV        word ptr [ESI + 0x1da],0xffff
    //         004c8242     MOV        dword ptr [ESI + 0x1e8],EBX
    //         004c8248     MOV        dword ptr [ESI],TRIBE_Building_Object::`vftable' = 004c8090
    //         004c824e     JZ         LAB_004c8259
    //                              t_b_obj.cpp:119 (9)
    //         004c8250     PUSH       EDI
    //         004c8251     PUSH       EBP
    //         004c8252     MOV        this,ESI
    //         004c8254     CALL       TRIBE_Building_Object::setup                     int setup(TRIBE_Building_Object * this, int p
    //                               LAB_004c8259                                                 XREF[1]:     004c824e(j)  
    //                              t_b_obj.cpp:122 (41)
    //         004c8259     FLD        float ptr [ESI + 0x3c]
    //         004c825c     CALL       __ftol                                           undefined __ftol()
    //         004c8261     FLD        float ptr [ESI + 0x38]
    //         004c8264     MOV        EDI,EAX
    //         004c8266     CALL       __ftol                                           undefined __ftol()
    //         004c826b     MOV        this,dword ptr [EDI*0x4 + unified_map_offsets]   = 00000000
    //         004c8272     LEA        EDX,[this->_padding_ + EAX*0x4]
    //         004c8275     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8278     PUSH       EDX
    //         004c8279     PUSH       ESI
    //         004c827a     MOV        this,dword ptr [EAX + 0x40]
    //         004c827d     CALL       RGE_Doppleganger_Creator::add_doppleganger_check int add_doppleganger_check(RGE_Doppleganger_C
    //                              t_b_obj.cpp:124 (29)
    //         004c8282     MOV        this,dword ptr [ESP + local_c]
    //         004c8286     MOV        dword ptr [ESI + 0x1e8],EAX
    //         004c828c     MOV        EAX,ESI
    //         004c828e     POP        EDI
    //         004c828f     POP        ESI
    //         004c8290     POP        EBP
    //         004c8291     MOV        dword ptr FS:[0x0],this
    //         004c8298     POP        EBX
    //         004c8299     ADD        ESP,0x10
    //         004c829c     RET        0xc
    //         004c829f     ??         90h
}

TRIBE_Building_Object::~TRIBE_Building_Object() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Building_Object(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c82c8(W), 004c834c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004c8355(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c82ba(W)  
    //                               ??1TRIBE_Building_Object@@UAE@XZ                             XREF[1]:     `scalar_deleting_destructor':004c8
    //                               TRIBE_Building_Object::~TRIBE_Building_Object
    //                              t_b_obj.cpp:129 (36)
    //         004c82a0     PUSH       -0x1
    //         004c82a2     PUSH       FUN_0055fad8
    //         004c82a7     MOV        EAX,FS:[0x0]
    //         004c82ad     PUSH       EAX
    //         004c82ae     MOV        dword ptr FS:[0x0],ESP
    //         004c82b5     PUSH       this
    //         004c82b6     PUSH       ESI
    //         004c82b7     MOV        ESI,this
    //         004c82b9     PUSH       EDI
    //         004c82ba     MOV        dword ptr [ESP + local_10],ESI
    //         004c82be     MOV        dword ptr [ESI],TRIBE_Building_Object::`vftable' = 004c8090
    //                              t_b_obj.cpp:131 (20)
    //         004c82c4     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c82c7     PUSH       ESI
    //         004c82c8     MOV        dword ptr [ESP + local_4],0x0
    //         004c82d0     MOV        this,dword ptr [EAX + 0x40]
    //         004c82d3     CALL       RGE_Doppleganger_Creator::remove_doppleganger_   int remove_doppleganger_check(RGE_Dopplegange
    //                              t_b_obj.cpp:133 (10)
    //         004c82d8     MOV        EDI,dword ptr [ESI + 0x1d4]
    //         004c82de     TEST       EDI,EDI
    //         004c82e0     JZ         LAB_004c82fc
    //                              t_b_obj.cpp:135 (16)
    //         004c82e2     MOV        this,EDI
    //         004c82e4     CALL       RGE_Action_List::~RGE_Action_List                void ~RGE_Action_List(RGE_Action_List * this)
    //         004c82e9     PUSH       EDI
    //         004c82ea     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004c82ef     ADD        ESP,0x4
    //                              t_b_obj.cpp:136 (10)
    //         004c82f2     MOV        dword ptr [ESI + 0x1d4],0x0
    //                               LAB_004c82fc                                                 XREF[1]:     004c82e0(j)  
    //                              t_b_obj.cpp:139 (13)
    //         004c82fc     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c8302     OR         EDI,0xffffffff
    //         004c8305     TEST       EAX,EAX
    //         004c8307     JZ         LAB_004c834a
    //                              t_b_obj.cpp:141 (9)
    //         004c8309     PUSH       EAX
    //         004c830a     CALL       free                                             undefined free()
    //         004c830f     ADD        ESP,0x4
    //                              t_b_obj.cpp:144 (20)
    //         004c8312     CMP        word ptr [ESI + 0x1da],0x4
    //         004c831a     MOV        dword ptr [ESI + 0x1c8],0x0
    //         004c8324     JNZ        LAB_004c834a
    //                              t_b_obj.cpp:147 (38)
    //         004c8326     MOV        this,dword ptr [ESI + 0xc]
    //         004c8329     MOV        word ptr [ESI + 0x1da],DI
    //         004c8330     MOV        EAX,[rge_base_game]                              = 00000000
    //         004c8335     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004c8339     MOV        this,dword ptr [EAX + EDX*0x4 + 0xa34]
    //         004c8340     LEA        EAX,[EAX + EDX*0x4 + 0xa34]
    //         004c8347     DEC        this
    //         004c8348     MOV        dword ptr [EAX],this
    //                               LAB_004c834a                                                 XREF[2]:     004c8307(j), 004c8324(j)  
    //         004c834a     MOV        this,ESI
    //                              t_b_obj.cpp:151 (26)
    //         004c834c     MOV        dword ptr [ESP + local_4],EDI
    //         004c8350     CALL       TRIBE_Combat_Object::~TRIBE_Combat_Object        void ~TRIBE_Combat_Object(TRIBE_Combat_Object
    //         004c8355     MOV        this,dword ptr [ESP + local_c]
    //         004c8359     POP        EDI
    //         004c835a     MOV        dword ptr FS:[0x0],this
    //         004c8361     POP        ESI
    //         004c8362     ADD        ESP,0x10
    //         004c8365     RET
    //         004c8366     ??         90h
    //         004c8367     NOP
    //         004c8368     NOP
    //         004c8369     NOP
    //         004c836a     NOP
    //         004c836b     NOP
    //         004c836c     NOP
    //         004c836d     NOP
    //         004c836e     NOP
    //         004c836f     NOP
}

void TRIBE_Building_Object::recycle_out_of_game() {
    /* TODO: Stub */
    //                              void __thiscall recycle_out_of_game(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?recycle_out_of_game@TRIBE_Building_Object@@UAEXXZ           XREF[1]:     00574780(*)  
    //                               TRIBE_Building_Object::recycle_out_of_game
    //                              t_b_obj.cpp:155 (4)
    //         004c8370     PUSH       EBX
    //         004c8371     PUSH       ESI
    //         004c8372     MOV        ESI,this
    //                              t_b_obj.cpp:156 (12)
    //         004c8374     XOR        EBX,EBX
    //         004c8376     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c837c     CMP        this,EBX
    //         004c837e     JZ         LAB_004c8385
    //                              t_b_obj.cpp:157 (5)
    //         004c8380     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                               LAB_004c8385                                                 XREF[1]:     004c837e(j)  
    //                              t_b_obj.cpp:159 (10)
    //         004c8385     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c838b     CMP        EAX,EBX
    //         004c838d     JZ         LAB_004c83c8
    //                              t_b_obj.cpp:161 (9)
    //         004c838f     PUSH       EAX
    //         004c8390     CALL       free                                             undefined free()
    //         004c8395     ADD        ESP,0x4
    //                              t_b_obj.cpp:162 (6)
    //         004c8398     MOV        dword ptr [ESI + 0x1c8],EBX
    //                              t_b_obj.cpp:163 (7)
    //         004c839e     MOV        word ptr [ESI + 0x1cc],BX
    //                              t_b_obj.cpp:164 (7)
    //         004c83a5     MOV        word ptr [ESI + 0x1ce],BX
    //                              t_b_obj.cpp:165 (7)
    //         004c83ac     MOV        byte ptr [ESI + 0x1d0],0x1
    //                              t_b_obj.cpp:166 (6)
    //         004c83b3     MOV        byte ptr [ESI + 0x1d8],BL
    //                              t_b_obj.cpp:167 (6)
    //         004c83b9     MOV        byte ptr [ESI + 0x1d9],BL
    //                              t_b_obj.cpp:168 (9)
    //         004c83bf     MOV        word ptr [ESI + 0x1da],0xffff
    //                               LAB_004c83c8                                                 XREF[1]:     004c838d(j)  
    //                              t_b_obj.cpp:171 (7)
    //         004c83c8     MOV        this,ESI
    //         004c83ca     CALL       RGE_Action_Object::recycle_out_of_game           void recycle_out_of_game(RGE_Action_Object * 
    //                              t_b_obj.cpp:172 (3)
    //         004c83cf     POP        ESI
    //         004c83d0     POP        EBX
    //         004c83d1     RET
    //         004c83d2     ??         90h
    //         004c83d3     NOP
    //         004c83d4     NOP
    //         004c83d5     NOP
    //         004c83d6     NOP
    //         004c83d7     NOP
    //         004c83d8     NOP
    //         004c83d9     NOP
    //         004c83da     NOP
    //         004c83db     NOP
    //         004c83dc     NOP
    //         004c83dd     NOP
    //         004c83de     NOP
    //         004c83df     NOP
    //                              * protected: virtual int __thiscall TRIBE_Building_Object::setup(class TRIBE_Master_Building_Object ... *
    //                              int __thiscall setup(TRIBE_Building_Object * this, TRIBE_Master_Buil
    //              int               EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              TRIBE_Master_B    Stack[0x4]:4   param_1                   XREF[1]:     004c83f6(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[1]:     004c83e9(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004c83e4(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004c83f0(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004c83e0(R)  
    //                               ?setup@TRIBE_Building_Object@@MAEHPAVTRIBE_Master_Building_  XREF[3]:     TRIBE_Building_Object:004c7ffe(c), 
    //                               TRIBE_Building_Object::setup                                              TRIBE_Building_Object:004c815b(c), 
    //                                                                                                         005749d8(*)  
    //                              t_b_obj.cpp:176 (44)
    //         004c83e0     MOV        EAX,dword ptr [ESP + param_5]
    //         004c83e4     MOV        EDX,dword ptr [ESP + param_3]
    //         004c83e8     PUSH       EBP
    //         004c83e9     MOV        EBP,dword ptr [ESP + param_2]
    //         004c83ed     PUSH       ESI
    //         004c83ee     MOV        ESI,this
    //         004c83f0     MOV        this,dword ptr [ESP + param_4]
    //         004c83f4     PUSH       EDI
    //         004c83f5     PUSH       EAX
    //         004c83f6     MOV        EAX,dword ptr [ESP + param_1]
    //         004c83fa     PUSH       this
    //         004c83fb     PUSH       EDX
    //         004c83fc     PUSH       EBP
    //         004c83fd     PUSH       EAX
    //         004c83fe     MOV        this,ESI
    //         004c8400     MOV        byte ptr [ESI + 0x1e5],0x0
    //         004c8407     CALL       TRIBE_Combat_Object::setup                       int setup(TRIBE_Combat_Object * this, TRIBE_M
    //                              t_b_obj.cpp:184 (13)
    //         004c840c     MOV        EDI,dword ptr [ESI]
    //         004c840e     PUSH       0x0
    //         004c8410     MOV        this,ESI
    //         004c8412     MOV        byte ptr [ESI + 0x4e],0x50
    //         004c8416     CALL       dword ptr [EDI + 0x5c]
    //                              t_b_obj.cpp:185 (13)
    //         004c8419     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c841c     CMP        word ptr [EAX + 0x15a],0x0
    //         004c8424     JLE        LAB_004c8432
    //                              t_b_obj.cpp:186 (12)
    //         004c8426     MOV        this,dword ptr [EAX + 0x168]
    //         004c842c     PUSH       this
    //         004c842d     MOV        this,ESI
    //         004c842f     CALL       dword ptr [EDI + 0x38]
    //                               LAB_004c8432                                                 XREF[1]:     004c8424(j)  
    //                              t_b_obj.cpp:190 (20)
    //         004c8432     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8435     MOV        dword ptr [ESI + 0x1dc],0x0
    //         004c843f     MOV        dword ptr [ESI + 0x30],0x3f800000
    //                              t_b_obj.cpp:194 (49)
    //         004c8446     PUSH       0x0
    //         004c8448     MOV        DL,byte ptr [EAX + 0x16e]
    //         004c844e     MOV        byte ptr [ESI + 0x35],DL
    //         004c8451     MOV        this,byte ptr [EBP + 0x54]
    //         004c8454     MOV        EDX,dword ptr [ESI + 0x3c]
    //         004c8457     MOV        byte ptr [ESI + 0x1e4],this
    //         004c845d     MOV        this,dword ptr [ESI + 0xc]
    //         004c8460     MOV        AX,word ptr [EAX + 0x10]
    //         004c8464     PUSH       EDX=>DAT_fffffff8
    //         004c8465     MOV        EDX,dword ptr [ESI + 0x38]
    //         004c8468     PUSH       EDX=>DAT_fffffff4
    //         004c8469     MOV        DX,word ptr [ECX + this+0x4a]
    //         004c846d     MOV        this,dword ptr [ECX + this->_padding_]
    //         004c8470     PUSH       EAX=>DAT_fffffff0
    //         004c8471     PUSH       EDX
    //         004c8472     CALL       TRIBE_World::check_destructables                 void check_destructables(TRIBE_World * this, 
    //                              t_b_obj.cpp:196 (14)
    //         004c8477     MOV        this,ESI
    //         004c8479     CALL       dword ptr [EDI + 0x218]
    //         004c847f     MOV        dword ptr [ESI + 0x1d4],EAX
    //                              t_b_obj.cpp:199 (11)
    //         004c8485     POP        EDI
    //         004c8486     POP        ESI
    //         004c8487     MOV        EAX,0x1
    //         004c848c     POP        EBP
    //         004c848d     RET        0x14
    return;
}

int TRIBE_Building_Object::setup(TRIBE_Master_Building_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Building_Object * this, int param_1, RGE_
    //              int               EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c8495(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004c8490(R)  
    //                               ?setup@TRIBE_Building_Object@@MAEHHPAVRGE_Game_World@@@Z     XREF[2]:     TRIBE_Building_Object:004c8254(c), 
    //                               TRIBE_Building_Object::setup                                              00574950(*)  
    //                              t_b_obj.cpp:203 (19)
    //         004c8490     MOV        EAX,dword ptr [ESP + param_2]
    //         004c8494     PUSH       EBX
    //         004c8495     MOV        EBX,dword ptr [ESP + param_1]
    //         004c8499     PUSH       EDI
    //         004c849a     PUSH       EAX
    //         004c849b     MOV        EDI,this
    //         004c849d     PUSH       EBX
    //         004c849e     CALL       TRIBE_Combat_Object::setup                       int setup(TRIBE_Combat_Object * this, int par
    //                              t_b_obj.cpp:208 (22)
    //         004c84a3     LEA        this,[EDI + 0x1e5]
    //         004c84a9     PUSH       0x1
    //         004c84ab     PUSH       this
    //         004c84ac     PUSH       EBX
    //         004c84ad     MOV        byte ptr [EDI + 0x4e],0x50
    //         004c84b1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c84b6     ADD        ESP,0xc
    //                              t_b_obj.cpp:209 (18)
    //         004c84b9     LEA        EDX,[EDI + 0x1dc]
    //         004c84bf     PUSH       0x4
    //         004c84c1     PUSH       EDX
    //         004c84c2     PUSH       EBX
    //         004c84c3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c84c8     ADD        ESP,0xc
    //                              t_b_obj.cpp:210 (18)
    //         004c84cb     LEA        EAX,[EDI + 0x1e0]
    //         004c84d1     PUSH       0x4
    //         004c84d3     PUSH       EAX
    //         004c84d4     PUSH       EBX
    //         004c84d5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c84da     ADD        ESP,0xc
    //                              t_b_obj.cpp:211 (15)
    //         004c84dd     LEA        this,[EDI + 0x1e4]
    //         004c84e3     PUSH       0x1
    //         004c84e5     PUSH       this
    //         004c84e6     PUSH       EBX
    //         004c84e7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:213 (19)
    //         004c84ec     MOV        EDX,dword ptr [EDI]
    //         004c84ee     ADD        ESP,0xc
    //         004c84f1     MOV        this,EDI
    //         004c84f3     CALL       dword ptr [EDX + 0x218]
    //         004c84f9     MOV        dword ptr [EDI + 0x1d4],EAX
    //                              t_b_obj.cpp:215 (25)
    //         004c84ff     FLD        float ptr [save_game_version]                    = 7.23
    //         004c8505     FCOMP      float ptr [DAT_005749e0]                         = 52h    R
    //         004c850b     FNSTSW     AX
    //         004c850d     TEST       AH,0x1
    //         004c8510     JNZ        LAB_004c85b9
    //         004c8516     PUSH       ESI
    //         004c8517     PUSH       EBP
    //                              t_b_obj.cpp:217 (15)
    //         004c8518     LEA        ESI,[EDI + 0x1cc]
    //         004c851e     PUSH       0x2
    //         004c8520     PUSH       ESI
    //         004c8521     PUSH       EBX
    //         004c8522     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:218 (11)
    //         004c8527     MOV        AX,word ptr [ESI]
    //         004c852a     ADD        ESP,0xc
    //         004c852d     TEST       AX,AX
    //         004c8530     JLE        LAB_004c8587
    //                              t_b_obj.cpp:220 (11)
    //         004c8532     MOVSX      EAX,AX
    //         004c8535     PUSH       0x4
    //         004c8537     PUSH       EAX
    //         004c8538     CALL       calloc                                           undefined calloc()
    //                              t_b_obj.cpp:221 (16)
    //         004c853d     XOR        EBP,EBP
    //         004c853f     ADD        ESP,0x8
    //         004c8542     CMP        word ptr [ESI],BP
    //         004c8545     MOV        dword ptr [EDI + 0x1c8],EAX
    //         004c854b     JLE        LAB_004c8587
    //                               LAB_004c854d                                                 XREF[1]:     004c8585(j)  
    //                              t_b_obj.cpp:223 (23)
    //         004c854d     MOV        this,dword ptr [EDI + 0x1c8]
    //         004c8553     PUSH       0x2
    //         004c8555     MOVSX      ESI,BP
    //         004c8558     SHL        ESI,0x2
    //         004c855b     ADD        this,ESI
    //         004c855d     PUSH       this
    //         004c855e     PUSH       EBX
    //         004c855f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:224 (35)
    //         004c8564     MOV        EDX,dword ptr [EDI + 0x1c8]
    //         004c856a     ADD        ESP,0xc
    //         004c856d     LEA        EAX,[EDX + ESI*0x1 + 0x2]
    //         004c8571     PUSH       0x2
    //         004c8573     PUSH       EAX
    //         004c8574     PUSH       EBX
    //         004c8575     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c857a     ADD        ESP,0xc
    //         004c857d     INC        EBP
    //         004c857e     CMP        BP,word ptr [EDI + 0x1cc]
    //         004c8585     JL         LAB_004c854d
    //                               LAB_004c8587                                                 XREF[2]:     004c8530(j), 004c854b(j)  
    //                              t_b_obj.cpp:227 (18)
    //         004c8587     LEA        this,[EDI + 0x1ce]
    //         004c858d     PUSH       0x2
    //         004c858f     PUSH       this
    //         004c8590     PUSH       EBX
    //         004c8591     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c8596     ADD        ESP,0xc
    //                              t_b_obj.cpp:228 (15)
    //         004c8599     LEA        EDX,[EDI + 0x1d0]
    //         004c859f     PUSH       0x1
    //         004c85a1     PUSH       EDX
    //         004c85a2     PUSH       EBX
    //         004c85a3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:230 (17)
    //         004c85a8     MOV        this,dword ptr [EDI + 0x1d4]
    //         004c85ae     ADD        ESP,0xc
    //         004c85b1     PUSH       EBX
    //         004c85b2     CALL       RGE_Action_List::load                            void load(RGE_Action_List * this, int param_1)
    //         004c85b7     POP        EBP
    //         004c85b8     POP        ESI
    //                               LAB_004c85b9                                                 XREF[1]:     004c8510(j)  
    //                              t_b_obj.cpp:234 (10)
    //         004c85b9     POP        EDI
    //         004c85ba     MOV        EAX,0x1
    //         004c85bf     POP        EBX
    //         004c85c0     RET        0x8
    //         004c85c3     ??         90h
    //         004c85c4     NOP
    //         004c85c5     NOP
    //         004c85c6     NOP
    //         004c85c7     NOP
    //         004c85c8     NOP
    //         004c85c9     NOP
    //         004c85ca     NOP
    //         004c85cb     NOP
    //         004c85cc     NOP
    //         004c85cd     NOP
    //         004c85ce     NOP
    //         004c85cf     NOP
    return 0;
}

int TRIBE_Building_Object::setup(int param_1, RGE_Game_World* param_2) {
    /* TODO: Stub */
    //                              int __thiscall setup(TRIBE_Building_Object * this, int param_1, RGE_
    //              int               EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c8495(R)  
    //              RGE_Game_World    Stack[0x8]:4   param_2                   XREF[1]:     004c8490(R)  
    //                               ?setup@TRIBE_Building_Object@@MAEHHPAVRGE_Game_World@@@Z     XREF[2]:     TRIBE_Building_Object:004c8254(c), 
    //                               TRIBE_Building_Object::setup                                              00574950(*)  
    //                              t_b_obj.cpp:203 (19)
    //         004c8490     MOV        EAX,dword ptr [ESP + param_2]
    //         004c8494     PUSH       EBX
    //         004c8495     MOV        EBX,dword ptr [ESP + param_1]
    //         004c8499     PUSH       EDI
    //         004c849a     PUSH       EAX
    //         004c849b     MOV        EDI,this
    //         004c849d     PUSH       EBX
    //         004c849e     CALL       TRIBE_Combat_Object::setup                       int setup(TRIBE_Combat_Object * this, int par
    //                              t_b_obj.cpp:208 (22)
    //         004c84a3     LEA        this,[EDI + 0x1e5]
    //         004c84a9     PUSH       0x1
    //         004c84ab     PUSH       this
    //         004c84ac     PUSH       EBX
    //         004c84ad     MOV        byte ptr [EDI + 0x4e],0x50
    //         004c84b1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c84b6     ADD        ESP,0xc
    //                              t_b_obj.cpp:209 (18)
    //         004c84b9     LEA        EDX,[EDI + 0x1dc]
    //         004c84bf     PUSH       0x4
    //         004c84c1     PUSH       EDX
    //         004c84c2     PUSH       EBX
    //         004c84c3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c84c8     ADD        ESP,0xc
    //                              t_b_obj.cpp:210 (18)
    //         004c84cb     LEA        EAX,[EDI + 0x1e0]
    //         004c84d1     PUSH       0x4
    //         004c84d3     PUSH       EAX
    //         004c84d4     PUSH       EBX
    //         004c84d5     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c84da     ADD        ESP,0xc
    //                              t_b_obj.cpp:211 (15)
    //         004c84dd     LEA        this,[EDI + 0x1e4]
    //         004c84e3     PUSH       0x1
    //         004c84e5     PUSH       this
    //         004c84e6     PUSH       EBX
    //         004c84e7     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:213 (19)
    //         004c84ec     MOV        EDX,dword ptr [EDI]
    //         004c84ee     ADD        ESP,0xc
    //         004c84f1     MOV        this,EDI
    //         004c84f3     CALL       dword ptr [EDX + 0x218]
    //         004c84f9     MOV        dword ptr [EDI + 0x1d4],EAX
    //                              t_b_obj.cpp:215 (25)
    //         004c84ff     FLD        float ptr [save_game_version]                    = 7.23
    //         004c8505     FCOMP      float ptr [DAT_005749e0]                         = 52h    R
    //         004c850b     FNSTSW     AX
    //         004c850d     TEST       AH,0x1
    //         004c8510     JNZ        LAB_004c85b9
    //         004c8516     PUSH       ESI
    //         004c8517     PUSH       EBP
    //                              t_b_obj.cpp:217 (15)
    //         004c8518     LEA        ESI,[EDI + 0x1cc]
    //         004c851e     PUSH       0x2
    //         004c8520     PUSH       ESI
    //         004c8521     PUSH       EBX
    //         004c8522     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:218 (11)
    //         004c8527     MOV        AX,word ptr [ESI]
    //         004c852a     ADD        ESP,0xc
    //         004c852d     TEST       AX,AX
    //         004c8530     JLE        LAB_004c8587
    //                              t_b_obj.cpp:220 (11)
    //         004c8532     MOVSX      EAX,AX
    //         004c8535     PUSH       0x4
    //         004c8537     PUSH       EAX
    //         004c8538     CALL       calloc                                           undefined calloc()
    //                              t_b_obj.cpp:221 (16)
    //         004c853d     XOR        EBP,EBP
    //         004c853f     ADD        ESP,0x8
    //         004c8542     CMP        word ptr [ESI],BP
    //         004c8545     MOV        dword ptr [EDI + 0x1c8],EAX
    //         004c854b     JLE        LAB_004c8587
    //                               LAB_004c854d                                                 XREF[1]:     004c8585(j)  
    //                              t_b_obj.cpp:223 (23)
    //         004c854d     MOV        this,dword ptr [EDI + 0x1c8]
    //         004c8553     PUSH       0x2
    //         004c8555     MOVSX      ESI,BP
    //         004c8558     SHL        ESI,0x2
    //         004c855b     ADD        this,ESI
    //         004c855d     PUSH       this
    //         004c855e     PUSH       EBX
    //         004c855f     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:224 (35)
    //         004c8564     MOV        EDX,dword ptr [EDI + 0x1c8]
    //         004c856a     ADD        ESP,0xc
    //         004c856d     LEA        EAX,[EDX + ESI*0x1 + 0x2]
    //         004c8571     PUSH       0x2
    //         004c8573     PUSH       EAX
    //         004c8574     PUSH       EBX
    //         004c8575     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c857a     ADD        ESP,0xc
    //         004c857d     INC        EBP
    //         004c857e     CMP        BP,word ptr [EDI + 0x1cc]
    //         004c8585     JL         LAB_004c854d
    //                               LAB_004c8587                                                 XREF[2]:     004c8530(j), 004c854b(j)  
    //                              t_b_obj.cpp:227 (18)
    //         004c8587     LEA        this,[EDI + 0x1ce]
    //         004c858d     PUSH       0x2
    //         004c858f     PUSH       this
    //         004c8590     PUSH       EBX
    //         004c8591     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004c8596     ADD        ESP,0xc
    //                              t_b_obj.cpp:228 (15)
    //         004c8599     LEA        EDX,[EDI + 0x1d0]
    //         004c859f     PUSH       0x1
    //         004c85a1     PUSH       EDX
    //         004c85a2     PUSH       EBX
    //         004c85a3     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              t_b_obj.cpp:230 (17)
    //         004c85a8     MOV        this,dword ptr [EDI + 0x1d4]
    //         004c85ae     ADD        ESP,0xc
    //         004c85b1     PUSH       EBX
    //         004c85b2     CALL       RGE_Action_List::load                            void load(RGE_Action_List * this, int param_1)
    //         004c85b7     POP        EBP
    //         004c85b8     POP        ESI
    //                               LAB_004c85b9                                                 XREF[1]:     004c8510(j)  
    //                              t_b_obj.cpp:234 (10)
    //         004c85b9     POP        EDI
    //         004c85ba     MOV        EAX,0x1
    //         004c85bf     POP        EBX
    //         004c85c0     RET        0x8
    //         004c85c3     ??         90h
    //         004c85c4     NOP
    //         004c85c5     NOP
    //         004c85c6     NOP
    //         004c85c7     NOP
    //         004c85c8     NOP
    //         004c85c9     NOP
    //         004c85ca     NOP
    //         004c85cb     NOP
    //         004c85cc     NOP
    //         004c85cd     NOP
    //         004c85ce     NOP
    //         004c85cf     NOP
    return 0;
}

void TRIBE_Building_Object::take_building_attribute_from_owner() {
    /* TODO: Stub */
    //                              void __thiscall take_building_attribute_from_owner(TRIBE_Building_Ob
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004c85d5(W)  
    //                               ?take_building_attribute_from_owner@TRIBE_Building_Object@@  XREF[1]:     005749d0(*)  
    //                               TRIBE_Building_Object::take_building_attribute_from_owner
    //                              t_b_obj.cpp:238 (9)
    //         004c85d0     PUSH       this
    //         004c85d1     PUSH       EBX
    //         004c85d2     PUSH       EBP
    //         004c85d3     PUSH       ESI
    //         004c85d4     PUSH       EDI
    //         004c85d5     MOV        dword ptr [ESP + local_4],this
    //                              t_b_obj.cpp:241 (12)
    //         004c85d9     XOR        EDI,EDI
    //         004c85db     MOV        EBP,0x6a
    //                              language.dll match for 0x70: "B"
    //         004c85e0     MOV        ESI,0x70
    //                               LAB_004c85e5                                                 XREF[1]:     004c861e(j)  
    //                              t_b_obj.cpp:242 (13)
    //         004c85e5     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004c85e8     CMP        byte ptr [EDI + EAX*0x1 + 0x88],0x4
    //         004c85f0     JC         LAB_004c8614
    //                              t_b_obj.cpp:243 (10)
    //         004c85f2     MOV        DX,word ptr [EBP + EAX*0x1]
    //         004c85f7     TEST       DX,DX
    //         004c85fa     JL         LAB_004c8614
    //                              t_b_obj.cpp:244 (36)
    //         004c85fc     MOV        this,dword ptr [ECX + this->_padding_]
    //         004c85ff     PUSH       0x0
    //         004c8601     FLD        float ptr [ESI + EAX*0x1]
    //         004c8604     MOV        EBX,dword ptr [this->_padding_]
    //         004c8606     PUSH       this=>DAT_fffffff8
    //         004c8607     FCHS
    //         004c8609     FSTP       float ptr [ESP]=>DAT_fffffff8
    //         004c860c     PUSH       EDX=>DAT_fffffff4
    //         004c860d     CALL       dword ptr [EBX + 0x78]
    //         004c8610     MOV        this,dword ptr [ESP + 0x10]
    //                               LAB_004c8614                                                 XREF[2]:     004c85f0(j), 004c85fa(j)  
    //         004c8614     ADD        ESI,0x4
    //         004c8617     INC        EDI
    //         004c8618     ADD        EBP,0x2
    //         004c861b     CMP        ESI,0x7c
    //         004c861e     JL         LAB_004c85e5
    //                              t_b_obj.cpp:245 (6)
    //         004c8620     POP        EDI
    //         004c8621     POP        ESI
    //         004c8622     POP        EBP
    //         004c8623     POP        EBX
    //         004c8624     POP        this
    //         004c8625     RET
    //         004c8626     ??         90h
    //         004c8627     NOP
    //         004c8628     NOP
    //         004c8629     NOP
    //         004c862a     NOP
    //         004c862b     NOP
    //         004c862c     NOP
    //         004c862d     NOP
    //         004c862e     NOP
    //         004c862f     NOP
    return;
}

void TRIBE_Building_Object::give_building_attribute_to_owner() {
    /* TODO: Stub */
    //                              void __thiscall give_building_attribute_to_owner(TRIBE_Building_Obje
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004c8635(W)  
    //                               ?give_building_attribute_to_owner@TRIBE_Building_Object@@UA  XREF[1]:     005749d4(*)  
    //                               TRIBE_Building_Object::give_building_attribute_to_owner
    //                              t_b_obj.cpp:249 (9)
    //         004c8630     PUSH       this
    //         004c8631     PUSH       EBX
    //         004c8632     PUSH       EBP
    //         004c8633     PUSH       ESI
    //         004c8634     PUSH       EDI
    //         004c8635     MOV        dword ptr [ESP + local_4],this
    //                              t_b_obj.cpp:252 (12)
    //         004c8639     XOR        EDI,EDI
    //         004c863b     MOV        EBP,0x6a
    //                              language.dll match for 0x70: "B"
    //         004c8640     MOV        ESI,0x70
    //                               LAB_004c8645                                                 XREF[1]:     004c8679(j)  
    //                              t_b_obj.cpp:253 (13)
    //         004c8645     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004c8648     CMP        byte ptr [EDI + EAX*0x1 + 0x88],0x4
    //         004c8650     JC         LAB_004c866f
    //                              t_b_obj.cpp:254 (10)
    //         004c8652     MOV        DX,word ptr [EBP + EAX*0x1]
    //         004c8657     TEST       DX,DX
    //         004c865a     JL         LAB_004c866f
    //                              t_b_obj.cpp:255 (31)
    //         004c865c     MOV        this,dword ptr [ECX + this->_padding_]
    //         004c865f     MOV        EAX,dword ptr [ESI + EAX*0x1]
    //         004c8662     PUSH       0x0
    //         004c8664     PUSH       EAX=>DAT_fffffff8
    //         004c8665     MOV        EBX,dword ptr [this->_padding_]
    //         004c8667     PUSH       EDX=>DAT_fffffff4
    //         004c8668     CALL       dword ptr [EBX + 0x78]
    //         004c866b     MOV        this,dword ptr [ESP + 0x10]
    //                               LAB_004c866f                                                 XREF[2]:     004c8650(j), 004c865a(j)  
    //         004c866f     ADD        ESI,0x4
    //         004c8672     INC        EDI
    //         004c8673     ADD        EBP,0x2
    //         004c8676     CMP        ESI,0x7c
    //         004c8679     JL         LAB_004c8645
    //                              t_b_obj.cpp:256 (6)
    //         004c867b     POP        EDI
    //         004c867c     POP        ESI
    //         004c867d     POP        EBP
    //         004c867e     POP        EBX
    //         004c867f     POP        this
    //         004c8680     RET
    //         004c8681     ??         90h
    //         004c8682     NOP
    //         004c8683     NOP
    //         004c8684     NOP
    //         004c8685     NOP
    //         004c8686     NOP
    //         004c8687     NOP
    //         004c8688     NOP
    //         004c8689     NOP
    //         004c868a     NOP
    //         004c868b     NOP
    //         004c868c     NOP
    //         004c868d     NOP
    //         004c868e     NOP
    //         004c868f     NOP
    return;
}

void TRIBE_Building_Object::destroy_obj() {
    /* TODO: Stub */
    //                              void __thiscall destroy_obj(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?destroy_obj@TRIBE_Building_Object@@UAEXXZ                   XREF[1]:     005747e0(*)  
    //                               TRIBE_Building_Object::destroy_obj
    //                              t_b_obj.cpp:260 (3)
    //         004c8690     PUSH       ESI
    //         004c8691     MOV        ESI,this
    //                              t_b_obj.cpp:261 (8)
    //         004c8693     MOV        EAX,dword ptr [ESI]
    //         004c8695     CALL       dword ptr [EAX + 0x258]
    //                              t_b_obj.cpp:263 (7)
    //         004c869b     MOV        this,ESI
    //         004c869d     CALL       RGE_Action_Object::destroy_obj                   void destroy_obj(RGE_Action_Object * this)
    //                              t_b_obj.cpp:265 (12)
    //         004c86a2     MOV        this,dword ptr [ESI + 0xc]
    //         004c86a5     PUSH       ESI
    //         004c86a6     MOV        this,dword ptr [ECX + this->_padding_]
    //         004c86a9     CALL       RGE_Doppleganger_Creator::remove_doppleganger_   int remove_doppleganger_check(RGE_Dopplegange
    //                              t_b_obj.cpp:266 (10)
    //         004c86ae     MOV        dword ptr [ESI + 0x1e8],0x0
    //                              t_b_obj.cpp:268 (2)
    //         004c86b8     POP        ESI
    //         004c86b9     RET
    //         004c86ba     ??         90h
    //         004c86bb     NOP
    //         004c86bc     NOP
    //         004c86bd     NOP
    //         004c86be     NOP
    //         004c86bf     NOP
    return;
}

uchar TRIBE_Building_Object::heal(float param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall heal(TRIBE_Building_Object * this, float param_1)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[7]:     004c86da(R), 004c86de(W), 004c86e4(R), 004c86e8(W), 
    //                                                                                     004c86fb(W), 004c8717(R), 004c8728(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004c86d2(W), 004c86d6(R), 004c8709(W), 004c870f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c871b(*)  
    //                               ?heal@TRIBE_Building_Object@@UAEEM@Z                         XREF[1]:     00574804(*)  
    //                               TRIBE_Building_Object::heal
    //                              t_b_obj.cpp:272 (4)
    //         004c86c0     PUSH       this
    //         004c86c1     PUSH       ESI
    //         004c86c2     MOV        ESI,this
    //                              t_b_obj.cpp:276 (3)
    //         004c86c4     MOV        this,dword ptr [ESI + 0x8]
    //                              t_b_obj.cpp:278 (49)
    //         004c86c7     MOVSX      EDX,word ptr [ECX + this+0x26]
    //         004c86cb     MOVSX      EAX,word ptr [ECX + this+0x15a]
    //         004c86d2     MOV        dword ptr [ESP + local_4],EDX
    //         004c86d6     FILD       dword ptr [ESP + local_4]
    //         004c86da     FLD        float ptr [ESP + param_1]
    //         004c86de     MOV        dword ptr [ESP + param_1],EAX
    //         004c86e2     FMUL       ST1
    //         004c86e4     FIDIV      dword ptr [ESP + param_1]
    //         004c86e8     FST        float ptr [ESP + param_1]
    //         004c86ec     FADD       float ptr [ESI + 0x30]
    //         004c86ef     FCOMP
    //         004c86f1     FNSTSW     AX
    //         004c86f3     TEST       AH,0x41
    //         004c86f6     JNZ        LAB_004c8701
    //                              t_b_obj.cpp:279 (9)
    //         004c86f8     FSUB       float ptr [ESI + 0x30]
    //         004c86fb     FSTP       float ptr [ESP + param_1]
    //         004c86ff     JMP        LAB_004c8703
    //                               LAB_004c8701                                                 XREF[1]:     004c86f6(j)  
    //                              t_b_obj.cpp:278 (2)
    //         004c8701     FSTP       ST0
    //                               LAB_004c8703                                                 XREF[1]:     004c86ff(j)  
    //                              t_b_obj.cpp:281 (37)
    //         004c8703     ADD        EDX,EDX
    //         004c8705     MOV        AX,word ptr [ECX + this->_padding_]
    //         004c8709     MOV        dword ptr [ESP + local_4],EDX
    //         004c870d     PUSH       0x0
    //         004c870f     FILD       dword ptr [ESP + local_4]
    //         004c8713     PUSH       this
    //         004c8714     MOV        this,dword ptr [ESI + 0xc]
    //         004c8717     FDIVR      float ptr [ESP + param_1]
    //         004c871b     FSTP       float ptr [ESP]=>local_10
    //         004c871e     PUSH       EAX
    //         004c871f     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
    //         004c8724     TEST       AL,AL
    //         004c8726     JZ         LAB_004c8739
    //                              t_b_obj.cpp:282 (12)
    //         004c8728     MOV        this,dword ptr [ESP + param_1]
    //         004c872c     PUSH       this
    //         004c872d     MOV        this,ESI
    //         004c872f     CALL       TRIBE_Combat_Object::heal                        uchar heal(TRIBE_Combat_Object * this, float 
    //                              t_b_obj.cpp:285 (5)
    //         004c8734     POP        ESI
    //         004c8735     POP        this
    //         004c8736     RET        0x4
    //                               LAB_004c8739                                                 XREF[1]:     004c8726(j)  
    //                              t_b_obj.cpp:284 (2)
    //         004c8739     MOV        AL,0x2
    //                              t_b_obj.cpp:285 (5)
    //         004c873b     POP        ESI
    //         004c873c     POP        this
    //         004c873d     RET        0x4
    return 0;
}

void TRIBE_Building_Object::set_object_state(uchar param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_object_state(TRIBE_Building_Object * this, uchar
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              uchar             Stack[0x4]:1   param_1                   XREF[1]:     004c8742(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c8768(W), 004c876c(R)  
    //                               ?set_object_state@TRIBE_Building_Object@@UAEXE@Z             XREF[1]:     005747d4(*)  
    //                               TRIBE_Building_Object::set_object_state
    //                              t_b_obj.cpp:289 (2)
    //         004c8740     PUSH       this
    //         004c8741     PUSH       EBX
    //                              t_b_obj.cpp:293 (18)
    //         004c8742     MOV        BL,byte ptr [ESP + param_1]
    //         004c8746     PUSH       EBP
    //         004c8747     PUSH       ESI
    //         004c8748     CMP        BL,0x2
    //         004c874b     PUSH       EDI
    //         004c874c     MOV        ESI,this
    //         004c874e     JNZ        LAB_004c8998
    //                              t_b_obj.cpp:295 (3)
    //         004c8754     MOV        EAX,dword ptr [ESI + 0x8]
    //                              t_b_obj.cpp:299 (36)
    //         004c8757     PUSH       0x12b
    //         004c875c     PUSH       s_C:\msdev\work\age1_x1\t_b_obj.cp               = "C:\\msdev\\work\\age1_x1\\t_b_obj.cpp"
    //         004c8761     MOVSX      this,word ptr [EAX + 0x15a]
    //         004c8768     MOV        dword ptr [ESP + local_4],this
    //         004c876c     FILD       dword ptr [ESP + local_4]
    //         004c8770     FSTP       float ptr [ESI + 0x1dc]
    //         004c8776     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
    //                              t_b_obj.cpp:301 (6)
    //         004c877b     MOV        EBP,dword ptr [debug_random_on]
    //                              t_b_obj.cpp:302 (10)
    //         004c8781     MOV        dword ptr [debug_random_on],0x0
    //                              t_b_obj.cpp:304 (34)
    //         004c878b     MOV        EDX,dword ptr [ESI + 0x8]
    //         004c878e     ADD        ESP,0x8
    //         004c8791     MOV        EDI,EAX
    //         004c8793     MOV        this,dword ptr [EDX + 0x164]
    //         004c8799     TEST       this,this
    //         004c879b     JZ         LAB_004c87b4
    //         004c879d     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c87a0     MOV        EDX,dword ptr [EAX + 0x3c]
    //         004c87a3     MOV        AX,word ptr [EAX + 0x4a]
    //         004c87a7     CMP        AX,word ptr [EDX + 0x7c]
    //         004c87ab     JNZ        LAB_004c87b4
    //                              t_b_obj.cpp:305 (7)
    //         004c87ad     PUSH       0x1
    //         004c87af     CALL       RGE_Sound::play                                  void play(RGE_Sound * this, int param_1)
    //                               LAB_004c87b4                                                 XREF[2]:     004c879b(j), 004c87ab(j)  
    //                              t_b_obj.cpp:309 (22)
    //         004c87b4     PUSH       EDI
    //         004c87b5     PUSH       0x135
    //         004c87ba     PUSH       s_C:\msdev\work\age1_x1\t_b_obj.cp               = "C:\\msdev\\work\\age1_x1\\t_b_obj.cpp"
    //         004c87bf     MOV        dword ptr [debug_random_on],EBP
    //         004c87c5     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
    //                              t_b_obj.cpp:312 (20)
    //         004c87ca     MOV        EDI,dword ptr [ESI]
    //         004c87cc     ADD        ESP,0xc
    //         004c87cf     MOV        this,ESI
    //         004c87d1     MOV        byte ptr [ESI + 0x1e5],0x1
    //         004c87d8     CALL       dword ptr [EDI + 0x25c]
    //                              t_b_obj.cpp:314 (13)
    //         004c87de     MOV        this,dword ptr [ESI + 0x8]
    //         004c87e1     MOV        AL,byte ptr [ECX + this->_padding_]
    //         004c87e7     TEST       AL,AL
    //         004c87e9     JZ         LAB_004c87f2
    //                              t_b_obj.cpp:316 (5)
    //         004c87eb     MOV        this,ESI
    //         004c87ed     CALL       dword ptr [EDI + 0x6c]
    //                              t_b_obj.cpp:318 (2)
    //         004c87f0     JMP        LAB_004c883b
    //                               LAB_004c87f2                                                 XREF[1]:     004c87e9(j)  
    //                              t_b_obj.cpp:321 (16)
    //         004c87f2     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c87f5     PUSH       -0x1
    //         004c87f7     PUSH       0x1
    //         004c87f9     PUSH       EDX
    //         004c87fa     MOV        this,ESI
    //         004c87fc     CALL       dword ptr [EDI + 0xdc]
    //                              t_b_obj.cpp:322 (16)
    //         004c8802     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8805     PUSH       -0x1
    //         004c8807     PUSH       0x0
    //         004c8809     PUSH       EAX
    //         004c880a     MOV        this,ESI
    //         004c880c     CALL       dword ptr [EDI + 0xd8]
    //                              t_b_obj.cpp:325 (12)
    //         004c8812     MOV        this,dword ptr [ESI + 0x8]
    //         004c8815     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004c8818     MOV        this,ESI
    //         004c881a     PUSH       EDX
    //         004c881b     CALL       dword ptr [EDI + 0x38]
    //                              t_b_obj.cpp:326 (12)
    //         004c881e     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8821     MOV        this,byte ptr [EAX + 0x16e]
    //         004c8827     MOV        byte ptr [ESI + 0x35],this
    //                              t_b_obj.cpp:329 (10)
    //         004c882a     MOV        this,byte ptr [EAX + 0x16c]
    //         004c8830     TEST       this,this
    //         004c8832     JZ         LAB_004c883b
    //                              t_b_obj.cpp:330 (7)
    //         004c8834     MOV        this,ESI
    //         004c8836     CALL       TRIBE_Building_Object::connect                   void connect(TRIBE_Building_Object * this)
    //                               LAB_004c883b                                                 XREF[2]:     004c87f0(j), 004c8832(j)  
    //                              t_b_obj.cpp:334 (16)
    //         004c883b     MOV        EDX,dword ptr [ESI + 0x8]
    //         004c883e     MOV        this,word ptr [EDX + 0x172]
    //         004c8845     CMP        this,-0x1
    //         004c8849     JLE        LAB_004c8869
    //                              t_b_obj.cpp:335 (30)
    //         004c884b     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c884e     MOV        EDI,dword ptr [ESI + 0x40]
    //         004c8851     MOVSX      this,this
    //         004c8854     MOV        EDX,dword ptr [EAX + 0x24]
    //         004c8857     PUSH       EDI
    //         004c8858     MOV        EDI,dword ptr [ESI + 0x3c]
    //         004c885b     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         004c885e     PUSH       EDI
    //         004c885f     MOV        EDI,dword ptr [ESI + 0x38]
    //         004c8862     MOV        EDX,dword ptr [this->_padding_]
    //         004c8864     PUSH       EDI
    //         004c8865     PUSH       EAX
    //         004c8866     CALL       dword ptr [EDX + 0x18]
    //                               LAB_004c8869                                                 XREF[1]:     004c8849(j)  
    //                              t_b_obj.cpp:337 (17)
    //         004c8869     MOV        EDI,dword ptr [ESI + 0x8]
    //         004c886c     CMP        word ptr [EDI + 0x174],-0x1
    //         004c8874     JLE        LAB_004c8935
    //                              t_b_obj.cpp:340 (92)
    //         004c887a     FLD        float ptr [EDI + 0x60]
    //         004c887d     FADD       float ptr [ESI + 0x3c]
    //         004c8880     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8883     MOV        this,byte ptr [EDI + 0x174]
    //         004c8889     PUSH       0x0
    //         004c888b     PUSH       0x1
    //         004c888d     FSUB       double ptr [DAT_005749e8]                        = FCh
    //         004c8893     MOV        EBP,dword ptr [EAX + 0x3c]
    //         004c8896     PUSH       this
    //         004c8897     CALL       __ftol                                           undefined __ftol()
    //         004c889c     FLD        float ptr [EDI + 0x5c]
    //         004c889f     FADD       float ptr [ESI + 0x38]
    //         004c88a2     PUSH       EAX
    //         004c88a3     FSUB       double ptr [DAT_005749e8]                        = FCh
    //         004c88a9     CALL       __ftol                                           undefined __ftol()
    //         004c88ae     FLD        float ptr [ESI + 0x3c]
    //         004c88b1     FSUB       float ptr [EDI + 0x60]
    //         004c88b4     PUSH       EAX
    //         004c88b5     CALL       __ftol                                           undefined __ftol()
    //         004c88ba     FLD        float ptr [ESI + 0x38]
    //         004c88bd     FSUB       float ptr [EDI + 0x5c]
    //         004c88c0     PUSH       EAX
    //         004c88c1     CALL       __ftol                                           undefined __ftol()
    //         004c88c6     MOV        EDX,dword ptr [EBP + 0x40]
    //         004c88c9     MOV        this,dword ptr [EBP + 0x28]
    //         004c88cc     PUSH       EAX
    //         004c88cd     PUSH       EBP
    //         004c88ce     MOV        EAX,dword ptr [EDX]
    //         004c88d0     PUSH       EAX
    //         004c88d1     CALL       RGE_Map::set_terrain                             void set_terrain(RGE_Map * this, RGE_Player *
    //                              t_b_obj.cpp:342 (95)
    //         004c88d6     MOV        EDI,dword ptr [ESI + 0x8]
    //         004c88d9     PUSH       0x0
    //         004c88db     FLD        float ptr [EDI + 0x60]
    //         004c88de     FADD       float ptr [ESI + 0x3c]
    //         004c88e1     FSUB       double ptr [DAT_005749e8]                        = FCh
    //         004c88e7     CALL       __ftol                                           undefined __ftol()
    //         004c88ec     FLD        float ptr [EDI + 0x5c]
    //         004c88ef     FADD       float ptr [ESI + 0x38]
    //         004c88f2     MOVSX      this,AX
    //         004c88f5     FSUB       double ptr [DAT_005749e8]                        = FCh
    //         004c88fb     INC        this
    //         004c88fc     PUSH       this
    //         004c88fd     CALL       __ftol                                           undefined __ftol()
    //         004c8902     FLD        float ptr [ESI + 0x3c]
    //         004c8905     FSUB       float ptr [EDI + 0x60]
    //         004c8908     MOVSX      EDX,AX
    //         004c890b     INC        EDX
    //         004c890c     PUSH       EDX
    //         004c890d     CALL       __ftol                                           undefined __ftol()
    //         004c8912     FLD        float ptr [ESI + 0x38]
    //         004c8915     FSUB       float ptr [EDI + 0x5c]
    //         004c8918     MOVSX      EAX,AX
    //         004c891b     DEC        EAX
    //         004c891c     PUSH       EAX
    //         004c891d     CALL       __ftol                                           undefined __ftol()
    //         004c8922     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c8925     MOVSX      this,AX
    //         004c8928     MOV        EAX,dword ptr [EDX + 0x3c]
    //         004c892b     DEC        this
    //         004c892c     PUSH       this
    //         004c892d     MOV        this,dword ptr [EAX + 0x28]
    //         004c8930     CALL       RGE_Map::request_redraw                          void request_redraw(RGE_Map * this, int param
    //                               LAB_004c8935                                                 XREF[1]:     004c8874(j)  
    //                              t_b_obj.cpp:348 (16)
    //         004c8935     MOV        this,dword ptr [ESI + 0x8]
    //         004c8938     MOV        AX,word ptr [ECX + this->_padding_]
    //         004c893f     CMP        AX,0xffff
    //         004c8943     JLE        LAB_004c8954
    //                              t_b_obj.cpp:349 (15)
    //         004c8945     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c8948     PUSH       EAX
    //         004c8949     MOV        this,dword ptr [EDX + 0x220]
    //         004c894f     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //                               LAB_004c8954                                                 XREF[1]:     004c8943(j)  
    //                              t_b_obj.cpp:351 (49)
    //         004c8954     MOV        EDI,dword ptr [rge_base_game]                    = 00000000
    //         004c895a     FLD        float ptr [ESI + 0x3c]
    //         004c895d     MOV        EBP,dword ptr [EDI]
    //         004c895f     CALL       __ftol                                           undefined __ftol()
    //         004c8964     FLD        float ptr [ESI + 0x38]
    //         004c8967     PUSH       EAX
    //         004c8968     CALL       __ftol                                           undefined __ftol()
    //         004c896d     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c8970     PUSH       EAX
    //         004c8971     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8974     MOVSX      this,word ptr [EAX + 0x10]
    //         004c8978     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         004c897c     PUSH       this
    //         004c897d     PUSH       EAX
    //         004c897e     PUSH       0x69
    //         004c8980     MOV        this,EDI
    //         004c8982     CALL       dword ptr [EBP + 0x40]
    //                              t_b_obj.cpp:355 (19)
    //         004c8985     MOV        this,dword ptr [ESI + 0xc]
    //         004c8988     MOV        EAX,dword ptr [ESI + 0x1e0]
    //         004c898e     PUSH       EAX
    //         004c898f     PUSH       ESI
    //         004c8990     MOV        EDX,dword ptr [this->_padding_]
    //         004c8992     CALL       dword ptr [EDX + 0x104]
    //                               LAB_004c8998                                                 XREF[1]:     004c874e(j)  
    //                              t_b_obj.cpp:359 (11)
    //         004c8998     CMP        BL,0x3
    //         004c899b     JNZ        LAB_004c89c7
    //         004c899d     CMP        byte ptr [ESI + 0x48],0x2
    //         004c89a1     JNZ        LAB_004c89c7
    //                              t_b_obj.cpp:361 (10)
    //         004c89a3     MOV        EDX,dword ptr [ESI]
    //         004c89a5     MOV        this,ESI
    //         004c89a7     CALL       dword ptr [EDX + 0x258]
    //                              t_b_obj.cpp:363 (12)
    //         004c89ad     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c89b0     PUSH       ESI
    //         004c89b1     MOV        this,dword ptr [EAX + 0x40]
    //         004c89b4     CALL       RGE_Doppleganger_Creator::remove_doppleganger_   int remove_doppleganger_check(RGE_Dopplegange
    //                              t_b_obj.cpp:364 (10)
    //         004c89b9     MOV        dword ptr [ESI + 0x1e8],0x0
    //                              t_b_obj.cpp:366 (2)
    //         004c89c3     MOV        BL,0x1
    //                              t_b_obj.cpp:368 (2)
    //         004c89c5     JMP        LAB_004c89c9
    //                               LAB_004c89c7                                                 XREF[2]:     004c899b(j), 004c89a1(j)  
    //                              t_b_obj.cpp:369 (2)
    //         004c89c7     XOR        BL,BL
    //                               LAB_004c89c9                                                 XREF[1]:     004c89c5(j)  
    //                              t_b_obj.cpp:379 (12)
    //         004c89c9     MOV        this,dword ptr [ESP + 0x18]
    //         004c89cd     PUSH       this
    //         004c89ce     MOV        this,ESI
    //         004c89d0     CALL       RGE_Static_Object::set_object_state              void set_object_state(RGE_Static_Object * thi
    //                              t_b_obj.cpp:381 (4)
    //         004c89d5     TEST       BL,BL
    //         004c89d7     JZ         LAB_004c8a4f
    //                              t_b_obj.cpp:383 (39)
    //         004c89d9     MOV        EDX,dword ptr [ESI + 0x8]
    //         004c89dc     MOV        this,dword ptr [ESI + 0xc]
    //         004c89df     PUSH       0x0
    //         004c89e1     PUSH       0x2
    //         004c89e3     MOVSX      EAX,word ptr [EDX + 0x10]
    //         004c89e7     MOV        this,dword ptr [ECX + this->_padding_]
    //         004c89ea     PUSH       0x1
    //         004c89ec     PUSH       0xbf800000
    //         004c89f1     PUSH       0xbf800000
    //         004c89f6     PUSH       EAX
    //         004c89f7     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //         004c89fc     TEST       EAX,EAX
    //         004c89fe     JNZ        LAB_004c8a4f
    //                              t_b_obj.cpp:385 (16)
    //         004c8a00     MOV        EDX,dword ptr [ESI + 0x8]
    //         004c8a03     MOV        AX,word ptr [EDX + 0x178]
    //         004c8a0a     CMP        AX,0xffff
    //         004c8a0e     JLE        LAB_004c8a1f
    //                              t_b_obj.cpp:386 (15)
    //         004c8a10     PUSH       EAX
    //         004c8a11     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8a14     MOV        this,dword ptr [EAX + 0x220]
    //         004c8a1a     CALL       TRIBE_Player_Tech::undo_tech                     uchar undo_tech(TRIBE_Player_Tech * this, sho
    //                               LAB_004c8a1f                                                 XREF[1]:     004c8a0e(j)  
    //                              t_b_obj.cpp:387 (16)
    //         004c8a1f     MOV        this,dword ptr [ESI + 0xc]
    //         004c8a22     PUSH       0x4a
    //         004c8a24     MOV        this,dword ptr [this->_padding_ + 0x220]
    //         004c8a2a     CALL       TRIBE_Player_Tech::undo_tech                     uchar undo_tech(TRIBE_Player_Tech * this, sho
    //                              t_b_obj.cpp:388 (16)
    //         004c8a2f     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c8a32     PUSH       0x4b
    //         004c8a34     MOV        this,dword ptr [EDX + 0x220]
    //         004c8a3a     CALL       TRIBE_Player_Tech::undo_tech                     uchar undo_tech(TRIBE_Player_Tech * this, sho
    //                              t_b_obj.cpp:389 (16)
    //         004c8a3f     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8a42     PUSH       0x4c
    //         004c8a44     MOV        this,dword ptr [EAX + 0x220]
    //         004c8a4a     CALL       TRIBE_Player_Tech::undo_tech                     uchar undo_tech(TRIBE_Player_Tech * this, sho
    //                               LAB_004c8a4f                                                 XREF[2]:     004c89d7(j), 004c89fe(j)  
    //                              t_b_obj.cpp:391 (8)
    //         004c8a4f     POP        EDI
    //         004c8a50     POP        ESI
    //         004c8a51     POP        EBP
    //         004c8a52     POP        EBX
    //         004c8a53     POP        this
    //         004c8a54     RET        0x4
    //         004c8a57     ??         90h
    //         004c8a58     NOP
    //         004c8a59     NOP
    //         004c8a5a     NOP
    //         004c8a5b     NOP
    //         004c8a5c     NOP
    //         004c8a5d     NOP
    //         004c8a5e     NOP
    //         004c8a5f     NOP
    return;
}

void TRIBE_Building_Object::rehook() {
    /* TODO: Stub */
    //                              void __thiscall rehook(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?rehook@TRIBE_Building_Object@@UAEXXZ                        XREF[1]:     005747a4(*)  
    //                               TRIBE_Building_Object::rehook
    //                              t_b_obj.cpp:395 (3)
    //         004c8a60     PUSH       ESI
    //         004c8a61     MOV        ESI,this
    //                              t_b_obj.cpp:396 (5)
    //         004c8a63     CALL       RGE_Action_Object::rehook                        void rehook(RGE_Action_Object * this)
    //                              t_b_obj.cpp:397 (11)
    //         004c8a68     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c8a6e     CALL       RGE_Action_List::rehook                          void rehook(RGE_Action_List * this)
    //                              t_b_obj.cpp:398 (2)
    //         004c8a73     POP        ESI
    //         004c8a74     RET
    //         004c8a75     ??         90h
    //         004c8a76     NOP
    //         004c8a77     NOP
    //         004c8a78     NOP
    //         004c8a79     NOP
    //         004c8a7a     NOP
    //         004c8a7b     NOP
    //         004c8a7c     NOP
    //         004c8a7d     NOP
    //         004c8a7e     NOP
    //         004c8a7f     NOP
    return;
}

uchar TRIBE_Building_Object::update() {
    /* TODO: Stub */
    //                              uchar __thiscall update(TRIBE_Building_Object * this)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     004c8aa1(W), 004c8aa5(R), 004c8aa9(W), 004c8ab3(R), 
    //                                                                                     004c8ad5(W), 004c8ad9(R)  
    //                               ?update@TRIBE_Building_Object@@UAEEXZ                        XREF[1]:     0057479c(*)  
    //                               TRIBE_Building_Object::update
    //                              t_b_obj.cpp:402 (6)
    //         004c8a80     PUSH       this
    //         004c8a81     PUSH       EBX
    //         004c8a82     PUSH       ESI
    //         004c8a83     MOV        ESI,this
    //         004c8a85     PUSH       EDI
    //                              t_b_obj.cpp:410 (7)
    //         004c8a86     MOV        AL,byte ptr [ESI + 0x48]
    //         004c8a89     TEST       AL,AL
    //         004c8a8b     JNZ        LAB_004c8af3
    //                              t_b_obj.cpp:413 (47)
    //         004c8a8d     MOV        EAX,dword ptr [ESI + 0x10]
    //         004c8a90     MOV        EBX,dword ptr [ESI + 0x8]
    //         004c8a93     MOV        DI,word ptr [EAX + 0x60]
    //         004c8a97     MOVSX      EDX,word ptr [EBX + 0x15a]
    //         004c8a9e     MOVSX      this,DI
    //         004c8aa1     MOV        dword ptr [ESP + local_4],this
    //         004c8aa5     FILD       dword ptr [ESP + local_4]
    //         004c8aa9     MOV        dword ptr [ESP + local_4],EDX
    //         004c8aad     FMUL       float ptr [ESI + 0x1dc]
    //         004c8ab3     FIDIV      dword ptr [ESP + local_4]
    //         004c8ab7     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:414 (15)
    //         004c8abc     XOR        this,this
    //         004c8abf     MOV        this,AL
    //         004c8ac1     CMP        this,DI
    //         004c8ac4     JGE        LAB_004c8ace
    //         004c8ac6     CMP        AL,byte ptr [ESI + 0x35]
    //         004c8ac9     JZ         LAB_004c8ace
    //                              t_b_obj.cpp:415 (3)
    //         004c8acb     MOV        byte ptr [ESI + 0x35],AL
    //                               LAB_004c8ace                                                 XREF[2]:     004c8ac4(j), 004c8ac9(j)  
    //                              t_b_obj.cpp:416 (28)
    //         004c8ace     MOVSX      EDX,word ptr [EBX + 0x15a]
    //         004c8ad5     MOV        dword ptr [ESP + local_4],EDX
    //         004c8ad9     FILD       dword ptr [ESP + local_4]
    //         004c8add     FCOMP      float ptr [ESI + 0x1dc]
    //         004c8ae3     FNSTSW     AX
    //         004c8ae5     TEST       AH,0x41
    //         004c8ae8     JZ         LAB_004c8af3
    //                              t_b_obj.cpp:417 (9)
    //         004c8aea     MOV        EAX,dword ptr [ESI]
    //         004c8aec     PUSH       0x2
    //         004c8aee     MOV        this,ESI
    //         004c8af0     CALL       dword ptr [EAX + 0x5c]
    //                               LAB_004c8af3                                                 XREF[2]:     004c8a8b(j), 004c8ae8(j)  
    //                              t_b_obj.cpp:421 (12)
    //         004c8af3     MOV        this,dword ptr [ESI + 0x1f0]
    //         004c8af9     MOV        EDX,dword ptr [ESI + 0x1ec]
    //                              t_b_obj.cpp:422 (36)
    //         004c8aff     MOV        EAX,dword ptr [ESI + 0x1fc]
    //         004c8b05     MOV        dword ptr [ESI + 0x1f4],this
    //         004c8b0b     MOV        this,dword ptr [ESI + 0x1f8]
    //         004c8b11     MOV        dword ptr [ESI + 0x1f0],EDX
    //         004c8b17     MOV        dword ptr [ESI + 0x200],EAX
    //         004c8b1d     MOV        dword ptr [ESI + 0x1fc],this
    //                              t_b_obj.cpp:423 (6)
    //         004c8b23     MOV        EDX,dword ptr [world_update_counter]
    //                              t_b_obj.cpp:428 (15)
    //         004c8b29     MOV        this,ESI
    //         004c8b2b     MOV        dword ptr [ESI + 0x1f8],EDX
    //         004c8b31     CALL       TRIBE_Combat_Object::update                      uchar update(TRIBE_Combat_Object * this)
    //         004c8b36     MOV        BL,AL
    //                              t_b_obj.cpp:430 (5)
    //         004c8b38     MOV        AL,byte ptr [ESI + 0x48]
    //         004c8b3b     CMP        AL,0x2
    //                              t_b_obj.cpp:431 (9)
    //         004c8b3d     MOV        this,ESI
    //         004c8b3f     JBE        LAB_004c8b59
    //         004c8b41     CALL       TRIBE_Building_Object::empty_production_queue    void empty_production_queue(TRIBE_Building_Ob
    //                              t_b_obj.cpp:435 (12)
    //         004c8b46     MOV        EAX,dword ptr [ESI + 0x1b8]
    //         004c8b4c     MOV        dword ptr [ESI + 0x1ec],EAX
    //                              t_b_obj.cpp:454 (2)
    //         004c8b52     MOV        AL,BL
    //                              t_b_obj.cpp:455 (5)
    //         004c8b54     POP        EDI
    //         004c8b55     POP        ESI
    //         004c8b56     POP        EBX
    //         004c8b57     POP        this
    //         004c8b58     RET
    //                               LAB_004c8b59                                                 XREF[1]:     004c8b3f(j)  
    //                              t_b_obj.cpp:433 (5)
    //         004c8b59     CALL       TRIBE_Building_Object::update_production_queue   void update_production_queue(TRIBE_Building_O
    //                              t_b_obj.cpp:435 (6)
    //         004c8b5e     MOV        EAX,dword ptr [ESI + 0x1b8]
    //                              t_b_obj.cpp:455 (13)
    //         004c8b64     POP        EDI
    //         004c8b65     MOV        dword ptr [ESI + 0x1ec],EAX
    //         004c8b6b     MOV        AL,BL
    //         004c8b6d     POP        ESI
    //         004c8b6e     POP        EBX
    //         004c8b6f     POP        this
    //         004c8b70     RET
    //         004c8b71     ??         90h
    //         004c8b72     NOP
    //         004c8b73     NOP
    //         004c8b74     NOP
    //         004c8b75     NOP
    //         004c8b76     NOP
    //         004c8b77     NOP
    //         004c8b78     NOP
    //         004c8b79     NOP
    //         004c8b7a     NOP
    //         004c8b7b     NOP
    //         004c8b7c     NOP
    //         004c8b7d     NOP
    //         004c8b7e     NOP
    //         004c8b7f     NOP
    //                              * public: virtual int __thiscall TRIBE_Building_Object::explore_terrain(class RGE_Player *,unsigned ... *
    //                              int __thiscall explore_terrain(TRIBE_Building_Object * this, RGE_Pla
    //              int               EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1                   XREF[2]:     004c8b93(R), 004c8ba5(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004c8b8e(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[2]:     004c8b8a(R), 004c8ba1(R)  
    //                               ?explore_terrain@TRIBE_Building_Object@@UAEHPAVRGE_Player@@  XREF[1]:     00574850(*)  
    //                               TRIBE_Building_Object::explore_terrain
    //                              t_b_obj.cpp:461 (10)
    //         004c8b80     MOV        AL,byte ptr [ECX + this->built]
    //         004c8b86     TEST       AL,AL
    //         004c8b88     JZ         LAB_004c8ba1
    //                              t_b_obj.cpp:463 (9)
    //         004c8b8a     MOV        EAX,dword ptr [ESP + param_3]
    //         004c8b8e     MOV        EDX,dword ptr [ESP + param_2]
    //         004c8b92     PUSH       EAX
    //                              t_b_obj.cpp:465 (11)
    //         004c8b93     MOV        EAX,dword ptr [ESP + param_1]
    //         004c8b97     PUSH       EDX
    //         004c8b98     PUSH       EAX
    //         004c8b99     CALL       RGE_Static_Object::explore_terrain               int explore_terrain(RGE_Static_Object * this,
    //                              t_b_obj.cpp:466 (3)
    //         004c8b9e     RET        0xc
    //                               LAB_004c8ba1                                                 XREF[1]:     004c8b88(j)  
    //                              t_b_obj.cpp:465 (17)
    //         004c8ba1     MOV        EDX,dword ptr [ESP + param_3]
    //         004c8ba5     MOV        EAX,dword ptr [ESP + param_1]
    //         004c8ba9     PUSH       EDX
    //         004c8baa     PUSH       0x1
    //         004c8bac     PUSH       EAX
    //         004c8bad     CALL       RGE_Static_Object::explore_terrain               int explore_terrain(RGE_Static_Object * this,
    //                              t_b_obj.cpp:466 (3)
    //         004c8bb2     RET        0xc
    //         004c8bb5     ??         90h
    //         004c8bb6     NOP
    //         004c8bb7     NOP
    //         004c8bb8     NOP
    //         004c8bb9     NOP
    //         004c8bba     NOP
    //         004c8bbb     NOP
    //         004c8bbc     NOP
    //         004c8bbd     NOP
    //         004c8bbe     NOP
    //         004c8bbf     NOP
    return 0;
}

void TRIBE_Building_Object::save(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall save(TRIBE_Building_Object * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c8bc1(R)  
    //                               ?save@TRIBE_Building_Object@@UAEXH@Z                         XREF[1]:     005747a8(*)  
    //                               TRIBE_Building_Object::save
    //                              t_b_obj.cpp:470 (1)
    //         004c8bc0     PUSH       EBX
    //                              t_b_obj.cpp:471 (15)
    //         004c8bc1     MOV        EBX,dword ptr [ESP + param_1]
    //         004c8bc5     PUSH       EBP
    //         004c8bc6     PUSH       ESI
    //         004c8bc7     PUSH       EDI
    //         004c8bc8     MOV        EDI,this
    //         004c8bca     PUSH       EBX
    //         004c8bcb     CALL       TRIBE_Combat_Object::save                        void save(TRIBE_Combat_Object * this, int par
    //                              t_b_obj.cpp:473 (18)
    //         004c8bd0     LEA        EAX,[EDI + 0x1e5]
    //         004c8bd6     PUSH       0x1
    //         004c8bd8     PUSH       EAX
    //         004c8bd9     PUSH       EBX
    //         004c8bda     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004c8bdf     ADD        ESP,0xc
    //                              t_b_obj.cpp:474 (18)
    //         004c8be2     LEA        this,[EDI + 0x1dc]
    //         004c8be8     PUSH       0x4
    //         004c8bea     PUSH       this
    //         004c8beb     PUSH       EBX
    //         004c8bec     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004c8bf1     ADD        ESP,0xc
    //                              t_b_obj.cpp:475 (18)
    //         004c8bf4     LEA        EDX,[EDI + 0x1e0]
    //         004c8bfa     PUSH       0x4
    //         004c8bfc     PUSH       EDX
    //         004c8bfd     PUSH       EBX
    //         004c8bfe     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004c8c03     ADD        ESP,0xc
    //                              t_b_obj.cpp:476 (18)
    //         004c8c06     LEA        EAX,[EDI + 0x1e4]
    //         004c8c0c     PUSH       0x1
    //         004c8c0e     PUSH       EAX
    //         004c8c0f     PUSH       EBX
    //         004c8c10     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004c8c15     ADD        ESP,0xc
    //                              t_b_obj.cpp:478 (15)
    //         004c8c18     LEA        ESI,[EDI + 0x1cc]
    //         004c8c1e     PUSH       0x2
    //         004c8c20     PUSH       ESI
    //         004c8c21     PUSH       EBX
    //         004c8c22     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              t_b_obj.cpp:479 (11)
    //         004c8c27     MOV        SI,word ptr [ESI]
    //         004c8c2a     ADD        ESP,0xc
    //         004c8c2d     TEST       SI,SI
    //         004c8c30     JLE        LAB_004c8c73
    //                              t_b_obj.cpp:481 (7)
    //         004c8c32     XOR        EBP,EBP
    //         004c8c34     TEST       SI,SI
    //         004c8c37     JLE        LAB_004c8c73
    //                               LAB_004c8c39                                                 XREF[1]:     004c8c71(j)  
    //                              t_b_obj.cpp:483 (23)
    //         004c8c39     MOV        this,dword ptr [EDI + 0x1c8]
    //         004c8c3f     PUSH       0x2
    //         004c8c41     MOVSX      ESI,BP
    //         004c8c44     SHL        ESI,0x2
    //         004c8c47     ADD        this,ESI
    //         004c8c49     PUSH       this
    //         004c8c4a     PUSH       EBX
    //         004c8c4b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              t_b_obj.cpp:484 (35)
    //         004c8c50     MOV        EDX,dword ptr [EDI + 0x1c8]
    //         004c8c56     ADD        ESP,0xc
    //         004c8c59     LEA        EAX,[EDX + ESI*0x1 + 0x2]
    //         004c8c5d     PUSH       0x2
    //         004c8c5f     PUSH       EAX
    //         004c8c60     PUSH       EBX
    //         004c8c61     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004c8c66     ADD        ESP,0xc
    //         004c8c69     INC        EBP
    //         004c8c6a     CMP        BP,word ptr [EDI + 0x1cc]
    //         004c8c71     JL         LAB_004c8c39
    //                               LAB_004c8c73                                                 XREF[2]:     004c8c30(j), 004c8c37(j)  
    //                              t_b_obj.cpp:487 (18)
    //         004c8c73     LEA        this,[EDI + 0x1ce]
    //         004c8c79     PUSH       0x2
    //         004c8c7b     PUSH       this
    //         004c8c7c     PUSH       EBX
    //         004c8c7d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004c8c82     ADD        ESP,0xc
    //                              t_b_obj.cpp:488 (15)
    //         004c8c85     LEA        EDX,[EDI + 0x1d0]
    //         004c8c8b     PUSH       0x1
    //         004c8c8d     PUSH       EDX
    //         004c8c8e     PUSH       EBX
    //         004c8c8f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              t_b_obj.cpp:489 (15)
    //         004c8c94     MOV        this,dword ptr [EDI + 0x1d4]
    //         004c8c9a     ADD        ESP,0xc
    //         004c8c9d     PUSH       EBX
    //         004c8c9e     CALL       RGE_Action_List::save                            void save(RGE_Action_List * this, int param_1)
    //                              t_b_obj.cpp:490 (7)
    //         004c8ca3     POP        EDI
    //         004c8ca4     POP        ESI
    //         004c8ca5     POP        EBP
    //         004c8ca6     POP        EBX
    //         004c8ca7     RET        0x4
    //         004c8caa     ??         90h
    //         004c8cab     NOP
    //         004c8cac     NOP
    //         004c8cad     NOP
    //         004c8cae     NOP
    //         004c8caf     NOP
    return;
}

void TRIBE_Building_Object::change_ownership(RGE_Player* param_1) {
    /* TODO: Stub */
    //                              void __thiscall change_ownership(TRIBE_Building_Object * this, RGE_P
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              RGE_Player *      Stack[0x4]:4   param_1
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c8cc3(W), 004c8cdd(R)  
    //                               ?change_ownership@TRIBE_Building_Object@@UAEXPAVRGE_Player@  XREF[1]:     005747bc(*)  
    //                               TRIBE_Building_Object::change_ownership
    //                              t_b_obj.cpp:494 (6)
    //         004c8cb0     PUSH       this
    //         004c8cb1     PUSH       EBX
    //         004c8cb2     PUSH       EBP
    //         004c8cb3     PUSH       ESI
    //         004c8cb4     MOV        ESI,this
    //                              t_b_obj.cpp:501 (11)
    //         004c8cb6     MOV        EBX,0x2
    //         004c8cbb     PUSH       EDI
    //         004c8cbc     CMP        byte ptr [ESI + 0x48],BL
    //         004c8cbf     JNZ        LAB_004c8d16
    //                              t_b_obj.cpp:502 (2)
    //         004c8cc1     XOR        EBP,EBP
    //                              t_b_obj.cpp:546 (83)
    //         004c8cc3     MOV        dword ptr [ESP + local_4],0x6a
    //         004c8ccb     MOV        EDI,0x70
    //                               LAB_004c8cd0                                                 XREF[1]:     004c8d14(j)  
    //         004c8cd0     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8cd3     CMP        byte ptr [EBP + EAX*0x1 + 0x88],0x4
    //         004c8cdb     JC         LAB_004c8d03
    //         004c8cdd     MOV        this,dword ptr [ESP + local_4]
    //         004c8ce1     MOV        DX,word ptr [this->_padding_ + EAX*0x1]
    //         004c8ce5     TEST       DX,DX
    //         004c8ce8     JL         LAB_004c8d03
    //         004c8cea     MOV        this,dword ptr [ESI + 0xc]
    //         004c8ced     PUSH       0x0
    //         004c8cef     FLD        float ptr [EDI + EAX*0x1]
    //         004c8cf2     MOV        EBX,dword ptr [this->_padding_]
    //         004c8cf4     PUSH       this=>DAT_fffffff8
    //         004c8cf5     FCHS
    //         004c8cf7     FSTP       float ptr [ESP]=>DAT_fffffff8
    //         004c8cfa     PUSH       EDX=>DAT_fffffff4
    //         004c8cfb     CALL       dword ptr [EBX + 0x78]
    //         004c8cfe     MOV        EBX,0x2
    //                               LAB_004c8d03                                                 XREF[2]:     004c8cdb(j), 004c8ce8(j)  
    //         004c8d03     MOV        this,dword ptr [ESP + 0x10]
    //         004c8d07     ADD        EDI,0x4
    //         004c8d0a     INC        EBP
    //         004c8d0b     ADD        this,EBX
    //         004c8d0d     CMP        EDI,0x7c
    //         004c8d10     MOV        dword ptr [ESP + 0x10],this
    //         004c8d14     JL         LAB_004c8cd0
    //                               LAB_004c8d16                                                 XREF[1]:     004c8cbf(j)  
    //                              t_b_obj.cpp:507 (12)
    //         004c8d16     MOV        AL,byte ptr [ESI + 0x48]
    //         004c8d19     MOV        EDI,0x1
    //         004c8d1e     TEST       AL,AL
    //         004c8d20     JNZ        LAB_004c8d33
    //                              t_b_obj.cpp:508 (17)
    //         004c8d22     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8d25     MOV        EDX,dword ptr [ESI]
    //         004c8d27     PUSH       -0x1
    //         004c8d29     PUSH       EDI=>DAT_fffffff8
    //         004c8d2a     PUSH       EAX=>DAT_fffffff4
    //         004c8d2b     MOV        this,ESI
    //         004c8d2d     CALL       dword ptr [EDX + 0xdc]
    //                               LAB_004c8d33                                                 XREF[1]:     004c8d20(j)  
    //                              t_b_obj.cpp:511 (10)
    //         004c8d33     CMP        word ptr [ESI + 0x1ce],0x0
    //         004c8d3b     JLE        LAB_004c8d7e
    //                              t_b_obj.cpp:513 (10)
    //         004c8d3d     CMP        word ptr [ESI + 0x1da],0x4
    //         004c8d45     JNZ        LAB_004c8d6d
    //                              t_b_obj.cpp:516 (38)
    //         004c8d47     MOV        this,dword ptr [ESI + 0xc]
    //         004c8d4a     MOV        word ptr [ESI + 0x1da],0xffff
    //         004c8d53     MOV        EAX,[rge_base_game]                              = 00000000
    //         004c8d58     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004c8d5c     MOV        this,dword ptr [EAX + EDX*0x4 + 0xa34]
    //         004c8d63     LEA        EAX,[EAX + EDX*0x4 + 0xa34]
    //         004c8d6a     DEC        this
    //         004c8d6b     MOV        dword ptr [EAX],this
    //                               LAB_004c8d6d                                                 XREF[1]:     004c8d45(j)  
    //                              t_b_obj.cpp:520 (17)
    //         004c8d6d     MOV        this,dword ptr [ESI + 0x1c8]
    //         004c8d73     MOV        word ptr [ESI + 0x1ce],DI
    //         004c8d7a     MOV        word ptr [ECX + this+0x2],DI
    //                               LAB_004c8d7e                                                 XREF[1]:     004c8d3b(j)  
    //                              t_b_obj.cpp:524 (11)
    //         004c8d7e     MOV        this,dword ptr [ESI + 0x184]
    //         004c8d84     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_b_obj.cpp:526 (12)
    //         004c8d89     MOV        EDX,dword ptr [ESP + 0x18]
    //         004c8d8d     MOV        this,ESI
    //         004c8d8f     PUSH       EDX
    //         004c8d90     CALL       TRIBE_Combat_Object::change_ownership            void change_ownership(TRIBE_Combat_Object * t
    //                              t_b_obj.cpp:528 (7)
    //         004c8d95     MOV        AL,byte ptr [ESI + 0x48]
    //         004c8d98     TEST       AL,AL
    //         004c8d9a     JNZ        LAB_004c8dad
    //                              t_b_obj.cpp:529 (17)
    //         004c8d9c     MOV        this,dword ptr [ESI + 0xc]
    //         004c8d9f     MOV        EAX,dword ptr [ESI]
    //         004c8da1     PUSH       -0x1
    //         004c8da3     PUSH       EDI=>DAT_fffffff8
    //         004c8da4     PUSH       this=>DAT_fffffff4
    //         004c8da5     MOV        this,ESI
    //         004c8da7     CALL       dword ptr [EAX + 0xd8]
    //                               LAB_004c8dad                                                 XREF[1]:     004c8d9a(j)  
    //                              t_b_obj.cpp:531 (9)
    //         004c8dad     CMP        byte ptr [ESI + 0x48],BL
    //         004c8db0     JNZ        LAB_004c8e58
    //                              t_b_obj.cpp:533 (16)
    //         004c8db6     MOV        EDX,dword ptr [ESI + 0x8]
    //         004c8db9     MOV        this,word ptr [EDX + 0x172]
    //         004c8dc0     CMP        this,-0x1
    //         004c8dc4     JLE        LAB_004c8de4
    //                              t_b_obj.cpp:534 (30)
    //         004c8dc6     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8dc9     MOV        EDI,dword ptr [ESI + 0x40]
    //         004c8dcc     MOVSX      this,this
    //         004c8dcf     MOV        EDX,dword ptr [EAX + 0x24]
    //         004c8dd2     PUSH       EDI
    //         004c8dd3     MOV        EDI,dword ptr [ESI + 0x3c]
    //         004c8dd6     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         004c8dd9     PUSH       EDI=>DAT_fffffff8
    //         004c8dda     MOV        EDI,dword ptr [ESI + 0x38]
    //         004c8ddd     MOV        EDX,dword ptr [this->_padding_]
    //         004c8ddf     PUSH       EDI=>DAT_fffffff4
    //         004c8de0     PUSH       EAX=>DAT_fffffff0
    //         004c8de1     CALL       dword ptr [EDX + 0x18]
    //                               LAB_004c8de4                                                 XREF[1]:     004c8dc4(j)  
    //                              t_b_obj.cpp:536 (16)
    //         004c8de4     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8de7     MOV        AX,word ptr [EAX + 0x178]
    //         004c8dee     CMP        AX,0xffff
    //         004c8df2     JLE        LAB_004c8e03
    //                              t_b_obj.cpp:537 (15)
    //         004c8df4     MOV        this,dword ptr [ESI + 0xc]
    //         004c8df7     PUSH       EAX
    //         004c8df8     MOV        this,dword ptr [this->_padding_ + 0x220]
    //         004c8dfe     CALL       TRIBE_Player_Tech::do_tech                       uchar do_tech(TRIBE_Player_Tech * this, short
    //                               LAB_004c8e03                                                 XREF[1]:     004c8df2(j)  
    //                              t_b_obj.cpp:541 (5)
    //         004c8e03     CMP        byte ptr [ESI + 0x48],BL
    //         004c8e06     JNZ        LAB_004c8e58
    //                              t_b_obj.cpp:542 (2)
    //         004c8e08     XOR        EBP,EBP
    //                              t_b_obj.cpp:546 (86)
    //         004c8e0a     MOV        dword ptr [ESP + 0x18],0x6a
    //                              language.dll match for 0x70: "B"
    //         004c8e12     MOV        EDI,0x70
    //                               LAB_004c8e17                                                 XREF[1]:     004c8e56(j)  
    //         004c8e17     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8e1a     CMP        byte ptr [EBP + EAX*0x1 + 0x88],0x4
    //         004c8e22     JC         LAB_004c8e45
    //         004c8e24     MOV        EDX,dword ptr [ESP + 0x18]
    //         004c8e28     MOV        DX,word ptr [EDX + EAX*0x1]
    //         004c8e2c     TEST       DX,DX
    //         004c8e2f     JL         LAB_004c8e45
    //         004c8e31     MOV        this,dword ptr [ESI + 0xc]
    //         004c8e34     MOV        EAX,dword ptr [EDI + EAX*0x1]
    //         004c8e37     PUSH       0x0
    //         004c8e39     PUSH       EAX=>DAT_fffffff8
    //         004c8e3a     MOV        EBX,dword ptr [this->_padding_]
    //         004c8e3c     PUSH       EDX=>DAT_fffffff4
    //         004c8e3d     CALL       dword ptr [EBX + 0x78]
    //         004c8e40     MOV        EBX,0x2
    //                               LAB_004c8e45                                                 XREF[2]:     004c8e22(j), 004c8e2f(j)  
    //         004c8e45     MOV        this,dword ptr [ESP + 0x18]
    //         004c8e49     ADD        EDI,0x4
    //         004c8e4c     INC        EBP
    //         004c8e4d     ADD        this,EBX
    //         004c8e4f     CMP        EDI,0x7c
    //         004c8e52     MOV        dword ptr [ESP + 0x18],this
    //         004c8e56     JL         LAB_004c8e17
    //                               LAB_004c8e58                                                 XREF[2]:     004c8db0(j), 004c8e06(j)  
    //         004c8e58     POP        EDI
    //         004c8e59     POP        ESI
    //         004c8e5a     POP        EBP
    //         004c8e5b     POP        EBX
    //         004c8e5c     POP        this
    //         004c8e5d     RET        0x4
    return;
}

void TRIBE_Building_Object::modify(float param_1, uchar param_2) {
    /* TODO: Stub */
    //                              void __thiscall modify(TRIBE_Building_Object * this, float param_1, 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[2]:     004c8e6c(R), 004c8e7a(R)  
    //              uchar             Stack[0x8]:1   param_2                   XREF[1]:     004c8e60(R)  
    //                               ?modify@TRIBE_Building_Object@@UAEXME@Z                      XREF[1]:     005747c0(*)  
    //                               TRIBE_Building_Object::modify
    //                              t_b_obj.cpp:550 (11)
    //         004c8e60     MOV        EAX,dword ptr [ESP + param_2]
    //         004c8e64     PUSH       ESI
    //         004c8e65     CMP        AL,0x11
    //         004c8e67     MOV        ESI,this
    //         004c8e69     JZ         LAB_004c8e7a
    //                              t_b_obj.cpp:557 (11)
    //         004c8e6b     PUSH       EAX
    //         004c8e6c     MOV        EAX,dword ptr [ESP + param_1]
    //         004c8e70     PUSH       EAX
    //         004c8e71     CALL       TRIBE_Combat_Object::modify                      void modify(TRIBE_Combat_Object * this, float
    //                              t_b_obj.cpp:560 (4)
    //         004c8e76     POP        ESI
    //         004c8e77     RET        0x8
    //                               LAB_004c8e7a                                                 XREF[1]:     004c8e69(j)  
    //                              t_b_obj.cpp:554 (12)
    //         004c8e7a     FLD        float ptr [ESP + param_1]
    //         004c8e7e     CALL       __ftol                                           undefined __ftol()
    //         004c8e83     MOV        byte ptr [ESI + 0x35],AL
    //                              t_b_obj.cpp:560 (4)
    //         004c8e86     POP        ESI
    //         004c8e87     RET        0x8
    //         004c8e8a     ??         90h
    //         004c8e8b     NOP
    //         004c8e8c     NOP
    //         004c8e8d     NOP
    //         004c8e8e     NOP
    //         004c8e8f     NOP
    return;
}

void TRIBE_Building_Object::transform(TRIBE_Master_Building_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall transform(TRIBE_Building_Object * this, TRIBE_Master
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              TRIBE_Master_B    Stack[0x4]:4   param_1                   XREF[1]:     004c8e92(R)  
    //                               ?transform@TRIBE_Building_Object@@QAEXPAVTRIBE_Master_Build
    //                               TRIBE_Building_Object::transform
    //                              t_b_obj.cpp:564 (2)
    //         004c8e90     PUSH       ESI
    //         004c8e91     PUSH       EDI
    //                              t_b_obj.cpp:565 (12)
    //         004c8e92     MOV        EDI,dword ptr [ESP + param_1]
    //         004c8e96     MOV        ESI,this
    //         004c8e98     PUSH       EDI
    //         004c8e99     CALL       TRIBE_Combat_Object::transform                   void transform(TRIBE_Combat_Object * this, RG
    //                              t_b_obj.cpp:568 (17)
    //         004c8e9e     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c8ea1     MOV        byte ptr [ESI + 0x48],0x0
    //         004c8ea5     CMP        word ptr [EAX + 0x15a],0x0
    //         004c8ead     JLE        LAB_004c8ebd
    //                              t_b_obj.cpp:569 (14)
    //         004c8eaf     MOV        EAX,dword ptr [EDI + 0x168]
    //         004c8eb5     MOV        EDX,dword ptr [ESI]
    //         004c8eb7     PUSH       EAX
    //         004c8eb8     MOV        this,ESI
    //         004c8eba     CALL       dword ptr [EDX + 0x38]
    //                               LAB_004c8ebd                                                 XREF[1]:     004c8ead(j)  
    //                              t_b_obj.cpp:571 (10)
    //         004c8ebd     MOV        dword ptr [ESI + 0x1dc],0x0
    //                              t_b_obj.cpp:572 (5)
    //         004c8ec7     POP        EDI
    //         004c8ec8     POP        ESI
    //         004c8ec9     RET        0x4
    //         004c8ecc     ??         90h
    //         004c8ecd     NOP
    //         004c8ece     NOP
    //         004c8ecf     NOP
    return;
}

long TRIBE_Building_Object::check(TRIBE_Building_Object** param_1) {
    /* TODO: Stub */
    //                              long __thiscall check(TRIBE_Building_Object * this, TRIBE_Building_O
    //              long              EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              TRIBE_Building    Stack[0x4]:4   param_1                   XREF[2]:     004c8f4f(R), 004c8f6d(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c8f15(W), 004c902d(R)  
    //              short             Stack[-0x8]:2  h                         XREF[2]:     004c8f08(W), 004c8fd5(R)  
    //              short             Stack[-0xc]:2  w                         XREF[4]:     004c8eef(W), 004c8f77(R), 004c8fd1(R), 004c9041(R)  
    //              short             Stack[-0x10]:2 x                         XREF[7]:     004c8f00(W), 004c8f63(W), 004c8fc4(RW), 004c9020(RW), 
    //                                                                                     004c907b(R), 004c9080(W), 004c9095(R)  
    //              long              Stack[-0x14]:4 counter
    //                               ?check@TRIBE_Building_Object@@QAEJPAPAV1@@Z                  XREF[2]:     connect:004c90d9(c), 
    //                               TRIBE_Building_Object::check                                              connect2:004c919e(c)  
    //                              t_b_obj.cpp:577 (9)
    //         004c8ed0     SUB        ESP,0x10
    //         004c8ed3     PUSH       EBX
    //         004c8ed4     PUSH       EBP
    //         004c8ed5     PUSH       ESI
    //         004c8ed6     MOV        ESI,this
    //         004c8ed8     PUSH       EDI
    //                              t_b_obj.cpp:578 (3)
    //         004c8ed9     MOV        EAX,dword ptr [ESI + 0xc]
    //                              t_b_obj.cpp:579 (14)
    //         004c8edc     FLD        float ptr [ESI + 0x38]
    //         004c8edf     MOV        this,dword ptr [EAX + 0x3c]
    //         004c8ee2     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004c8ee5     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:580 (16)
    //         004c8eea     FLD        float ptr [ESI + 0x3c]
    //         004c8eed     MOV        EBX,EAX
    //         004c8eef     MOV        dword ptr [ESP + w],EBX
    //         004c8ef3     CALL       __ftol                                           undefined __ftol()
    //         004c8ef8     MOV        EBP,EAX
    //                              t_b_obj.cpp:581 (6)
    //         004c8efa     MOV        AX,word ptr [EDI + 0x8]
    //         004c8efe     DEC        AX
    //                              t_b_obj.cpp:583 (18)
    //         004c8f00     MOV        dword ptr [ESP + x],0x0
    //         004c8f08     MOV        dword ptr [ESP + h],EAX
    //         004c8f0c     MOV        AX,word ptr [EDI + 0xc]
    //         004c8f10     DEC        AX
    //                              t_b_obj.cpp:585 (9)
    //         004c8f12     TEST       BP,BP
    //         004c8f15     MOV        dword ptr [ESP + local_4],EAX
    //         004c8f19     JLE        LAB_004c8f6d
    //                              t_b_obj.cpp:587 (56)
    //         004c8f1b     MOV        EDX,dword ptr [ESI + 0x8]
    //         004c8f1e     PUSH       0x0
    //         004c8f20     PUSH       0x0
    //         004c8f22     PUSH       0x0
    //         004c8f24     MOVSX      EAX,word ptr [EDX + 0x10]
    //         004c8f28     MOV        EDX,dword ptr [EDI + 0x8d8c]
    //         004c8f2e     PUSH       0xbf800000
    //         004c8f33     PUSH       0xbf800000
    //         004c8f38     PUSH       EAX
    //         004c8f39     MOVSX      this,BP
    //         004c8f3c     MOVSX      EAX,BX
    //         004c8f3f     MOV        this,dword ptr [EDX + this->_padding_*0x4 + -0
    //         004c8f43     LEA        EAX,[EAX + EAX*0x2]
    //         004c8f46     LEA        this,[ECX + EAX*0x8 + this->_padding_]
    //         004c8f4a     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //         004c8f4f     MOV        EBX,dword ptr [ESP + param_1]
    //                              t_b_obj.cpp:588 (6)
    //         004c8f53     TEST       EAX,EAX
    //         004c8f55     MOV        dword ptr [EBX],EAX
    //         004c8f57     JZ         LAB_004c8f77
    //                              t_b_obj.cpp:590 (10)
    //         004c8f59     MOV        EDX,dword ptr [EAX + 0xc]
    //         004c8f5c     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8f5f     CMP        EDX,EAX
    //         004c8f61     JNZ        LAB_004c8f71
    //                              t_b_obj.cpp:591 (8)
    //         004c8f63     MOV        dword ptr [ESP + x],0x1
    //                              t_b_obj.cpp:592 (2)
    //         004c8f6b     JMP        LAB_004c8f77
    //                               LAB_004c8f6d                                                 XREF[1]:     004c8f19(j)  
    //                              t_b_obj.cpp:597 (10)
    //         004c8f6d     MOV        EBX,dword ptr [ESP + param_1]
    //                               LAB_004c8f71                                                 XREF[1]:     004c8f61(j)  
    //         004c8f71     MOV        dword ptr [EBX],0x0
    //                               LAB_004c8f77                                                 XREF[2]:     004c8f57(j), 004c8f6b(j)  
    //                              t_b_obj.cpp:599 (9)
    //         004c8f77     MOV        EAX,dword ptr [ESP + w]
    //         004c8f7b     TEST       AX,AX
    //         004c8f7e     JLE        LAB_004c8fca
    //                              t_b_obj.cpp:601 (51)
    //         004c8f80     MOV        this,dword ptr [ESI + 0x8]
    //         004c8f83     PUSH       0x0
    //         004c8f85     PUSH       0x0
    //         004c8f87     PUSH       0x0
    //         004c8f89     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004c8f8d     PUSH       0xbf800000
    //         004c8f92     PUSH       0xbf800000
    //         004c8f97     MOVSX      this,BP
    //         004c8f9a     MOVSX      EAX,AX
    //         004c8f9d     PUSH       EDX
    //         004c8f9e     MOV        EDX,dword ptr [EDI + 0x8d8c]
    //         004c8fa4     LEA        EAX,[EAX + EAX*0x2]
    //         004c8fa7     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         004c8faa     LEA        this,[this->_padding_ + EAX*0x8 + -0xc]
    //         004c8fae     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //                              t_b_obj.cpp:602 (7)
    //         004c8fb3     TEST       EAX,EAX
    //         004c8fb5     MOV        dword ptr [EBX + 0x4],EAX
    //         004c8fb8     JZ         LAB_004c8fd1
    //                              t_b_obj.cpp:604 (10)
    //         004c8fba     MOV        EDX,dword ptr [EAX + 0xc]
    //         004c8fbd     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c8fc0     CMP        EDX,EAX
    //         004c8fc2     JNZ        LAB_004c8fca
    //                              t_b_obj.cpp:605 (4)
    //         004c8fc4     INC        dword ptr [ESP + x]
    //                              t_b_obj.cpp:606 (2)
    //         004c8fc8     JMP        LAB_004c8fd1
    //                               LAB_004c8fca                                                 XREF[2]:     004c8f7e(j), 004c8fc2(j)  
    //                              t_b_obj.cpp:611 (7)
    //         004c8fca     MOV        dword ptr [EBX + 0x4],0x0
    //                               LAB_004c8fd1                                                 XREF[2]:     004c8fb8(j), 004c8fc8(j)  
    //                              t_b_obj.cpp:613 (11)
    //         004c8fd1     MOV        EAX,dword ptr [ESP + w]
    //         004c8fd5     CMP        AX,word ptr [ESP + h]
    //         004c8fda     JGE        LAB_004c9026
    //                              t_b_obj.cpp:615 (51)
    //         004c8fdc     MOV        this,dword ptr [ESI + 0x8]
    //         004c8fdf     PUSH       0x0
    //         004c8fe1     PUSH       0x0
    //         004c8fe3     PUSH       0x0
    //         004c8fe5     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004c8fe9     PUSH       0xbf800000
    //         004c8fee     PUSH       0xbf800000
    //         004c8ff3     MOVSX      this,BP
    //         004c8ff6     MOVSX      EAX,AX
    //         004c8ff9     PUSH       EDX
    //         004c8ffa     MOV        EDX,dword ptr [EDI + 0x8d8c]
    //         004c9000     LEA        EAX,[EAX + EAX*0x2]
    //         004c9003     MOV        this,dword ptr [EDX + this->_padding_*0x4]
    //         004c9006     LEA        this,[ECX + EAX*0x8 + this->_padding_]
    //         004c900a     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //                              t_b_obj.cpp:616 (7)
    //         004c900f     TEST       EAX,EAX
    //         004c9011     MOV        dword ptr [EBX + 0x8],EAX
    //         004c9014     JZ         LAB_004c902d
    //                              t_b_obj.cpp:618 (10)
    //         004c9016     MOV        EDX,dword ptr [EAX + 0xc]
    //         004c9019     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c901c     CMP        EDX,EAX
    //         004c901e     JNZ        LAB_004c9026
    //                              t_b_obj.cpp:619 (4)
    //         004c9020     INC        dword ptr [ESP + x]
    //                              t_b_obj.cpp:620 (2)
    //         004c9024     JMP        LAB_004c902d
    //                               LAB_004c9026                                                 XREF[2]:     004c8fda(j), 004c901e(j)  
    //                              t_b_obj.cpp:625 (7)
    //         004c9026     MOV        dword ptr [EBX + 0x8],0x0
    //                               LAB_004c902d                                                 XREF[2]:     004c9014(j), 004c9024(j)  
    //                              t_b_obj.cpp:627 (7)
    //         004c902d     CMP        BP,word ptr [ESP + local_4]
    //         004c9032     JGE        LAB_004c908e
    //                              t_b_obj.cpp:629 (54)
    //         004c9034     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c9037     PUSH       0x0
    //         004c9039     PUSH       0x0
    //         004c903b     PUSH       0x0
    //         004c903d     MOVSX      this,word ptr [EAX + 0x10]
    //         004c9041     MOVSX      EAX,word ptr [ESP + w]
    //         004c9046     PUSH       0xbf800000
    //         004c904b     PUSH       0xbf800000
    //         004c9050     MOVSX      EDX,BP
    //         004c9053     PUSH       this
    //         004c9054     MOV        this,dword ptr [EDI + 0x8d8c]
    //         004c905a     LEA        EAX,[EAX + EAX*0x2]
    //         004c905d     MOV        this,dword ptr [ECX + EDX*this->_padding_ + 0x4]
    //         004c9061     LEA        this,[ECX + EAX*0x8 + this->_padding_]
    //         004c9065     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //                              t_b_obj.cpp:630 (7)
    //         004c906a     TEST       EAX,EAX
    //         004c906c     MOV        dword ptr [EBX + 0xc],EAX
    //         004c906f     JZ         LAB_004c9095
    //                              t_b_obj.cpp:632 (10)
    //         004c9071     MOV        EDX,dword ptr [EAX + 0xc]
    //         004c9074     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c9077     CMP        EDX,EAX
    //         004c9079     JNZ        LAB_004c908e
    //                              t_b_obj.cpp:633 (9)
    //         004c907b     MOV        EAX,dword ptr [ESP + x]
    //         004c907f     INC        EAX
    //         004c9080     MOV        dword ptr [ESP + x],EAX
    //                              t_b_obj.cpp:642 (10)
    //         004c9084     POP        EDI
    //         004c9085     POP        ESI
    //         004c9086     POP        EBP
    //         004c9087     POP        EBX
    //         004c9088     ADD        ESP,0x10
    //         004c908b     RET        0x4
    //                               LAB_004c908e                                                 XREF[2]:     004c9032(j), 004c9079(j)  
    //                              t_b_obj.cpp:639 (7)
    //         004c908e     MOV        dword ptr [EBX + 0xc],0x0
    //                               LAB_004c9095                                                 XREF[1]:     004c906f(j)  
    //                              t_b_obj.cpp:641 (4)
    //         004c9095     MOV        EAX,dword ptr [ESP + x]
    //                              t_b_obj.cpp:642 (10)
    //         004c9099     POP        EDI
    //         004c909a     POP        ESI
    //         004c909b     POP        EBP
    //         004c909c     POP        EBX
    //         004c909d     ADD        ESP,0x10
    //         004c90a0     RET        0x4
    //         004c90a3     ??         90h
    //         004c90a4     NOP
    //         004c90a5     NOP
    //         004c90a6     NOP
    //         004c90a7     NOP
    //         004c90a8     NOP
    //         004c90a9     NOP
    //         004c90aa     NOP
    //         004c90ab     NOP
    //         004c90ac     NOP
    //         004c90ad     NOP
    //         004c90ae     NOP
    //         004c90af     NOP
    return 0;
}

void TRIBE_Building_Object::connect() {
    /* TODO: Stub */
    //                              void __thiscall connect(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c90ea(R), 004c915b(R)  
    //              TRIBE_Building    Stack[-0x14]   checks                    XREF[0,7]:   004c90d2(*), 004c90de(R), 004c9134(R), 004c90e6(R), 
    //                                                                                     004c9141(R), 004c90e2(R), 004c914e(R)  
    //                               ?connect@TRIBE_Building_Object@@QAEXXZ                       XREF[2]:     set_object_state:004c8836(c), 
    //                               TRIBE_Building_Object::connect                                            copy_obj:004c974b(c)  
    //                              t_b_obj.cpp:647 (7)
    //         004c90b0     SUB        ESP,0x10
    //         004c90b3     PUSH       ESI
    //         004c90b4     MOV        ESI,this
    //         004c90b6     PUSH       EDI
    //                              t_b_obj.cpp:651 (11)
    //         004c90b7     MOV        EAX,dword ptr [ESI + 0x10]
    //         004c90ba     TEST       EAX,EAX
    //         004c90bc     JZ         LAB_004c9172
    //                              t_b_obj.cpp:655 (11)
    //         004c90c2     CMP        word ptr [EAX + 0x60],0x3
    //         004c90c7     JNZ        LAB_004c916e
    //                              t_b_obj.cpp:658 (5)
    //         004c90cd     CALL       RGE_Moving_Object::set_angle                     void set_angle(RGE_Moving_Object * this)
    //                              t_b_obj.cpp:659 (12)
    //         004c90d2     LEA        EAX=>checks[1],[ESP + 0x8]
    //         004c90d6     MOV        this,ESI
    //         004c90d8     PUSH       EAX
    //         004c90d9     CALL       TRIBE_Building_Object::check                     long check(TRIBE_Building_Object * this, TRIB
    //                              t_b_obj.cpp:661 (32)
    //         004c90de     MOV        EAX,dword ptr [ESP + checks[1]]
    //         004c90e2     MOV        EDX,dword ptr [ESP + checks[3]]
    //         004c90e6     MOV        this,dword ptr [ESP + checks[2]]
    //         004c90ea     MOV        EDI,dword ptr [ESP + local_4]
    //         004c90ee     TEST       EAX,EAX
    //         004c90f0     JZ         LAB_004c9108
    //         004c90f2     TEST       EDI,EDI
    //         004c90f4     JZ         LAB_004c9108
    //         004c90f6     TEST       this,this
    //         004c90f8     JNZ        LAB_004c910c
    //         004c90fa     TEST       EDX,EDX
    //         004c90fc     JNZ        LAB_004c9108
    //                              t_b_obj.cpp:662 (8)
    //         004c90fe     MOV        this,byte ptr [ESI + 0x35]
    //         004c9101     MOV        EDX,0x1
    //                              t_b_obj.cpp:663 (18)
    //         004c9106     JMP        LAB_004c912a
    //                               LAB_004c9108                                                 XREF[3]:     004c90f0(j), 004c90f4(j), 
    //                                                                                                         004c90fc(j)  
    //         004c9108     TEST       this,this
    //         004c910a     JZ         LAB_004c9120
    //                               LAB_004c910c                                                 XREF[1]:     004c90f8(j)  
    //         004c910c     TEST       EDX,EDX
    //         004c910e     JZ         LAB_004c9120
    //         004c9110     TEST       EAX,EAX
    //         004c9112     JNZ        LAB_004c9120
    //         004c9114     TEST       EDI,EDI
    //         004c9116     JNZ        LAB_004c9120
    //                              t_b_obj.cpp:664 (6)
    //         004c9118     MOV        AL,byte ptr [ESI + 0x35]
    //         004c911b     NEG        EAX
    //         004c911d     PUSH       EAX
    //                              t_b_obj.cpp:665 (2)
    //         004c911e     JMP        LAB_004c912d
    //                               LAB_004c9120                                                 XREF[4]:     004c910a(j), 004c910e(j), 
    //                                                                                                         004c9112(j), 004c9116(j)  
    //                              t_b_obj.cpp:666 (20)
    //         004c9120     XOR        this,this
    //         004c9122     MOV        EDX,0x2
    //         004c9127     MOV        this,byte ptr [ESI + 0x35]
    //                               LAB_004c912a                                                 XREF[1]:     004c9106(j)  
    //         004c912a     SUB        EDX,this
    //         004c912c     PUSH       EDX
    //                               LAB_004c912d                                                 XREF[1]:     004c911e(j)  
    //         004c912d     MOV        this,ESI
    //         004c912f     CALL       RGE_Moving_Object::rotate                        void rotate(RGE_Moving_Object * this, long pa
    //                              t_b_obj.cpp:668 (13)
    //         004c9134     MOV        this,dword ptr [ESP + checks[1]]
    //         004c9138     TEST       this,this
    //         004c913a     JZ         LAB_004c9141
    //         004c913c     CALL       TRIBE_Building_Object::connect2                  void connect2(TRIBE_Building_Object * this)
    //                               LAB_004c9141                                                 XREF[1]:     004c913a(j)  
    //                              t_b_obj.cpp:669 (13)
    //         004c9141     MOV        this,dword ptr [ESP + checks[2]]
    //         004c9145     TEST       this,this
    //         004c9147     JZ         LAB_004c914e
    //         004c9149     CALL       TRIBE_Building_Object::connect2                  void connect2(TRIBE_Building_Object * this)
    //                               LAB_004c914e                                                 XREF[1]:     004c9147(j)  
    //                              t_b_obj.cpp:670 (13)
    //         004c914e     MOV        this,dword ptr [ESP + checks[3]]
    //         004c9152     TEST       this,this
    //         004c9154     JZ         LAB_004c915b
    //         004c9156     CALL       TRIBE_Building_Object::connect2                  void connect2(TRIBE_Building_Object * this)
    //                               LAB_004c915b                                                 XREF[1]:     004c9154(j)  
    //                              t_b_obj.cpp:671 (13)
    //         004c915b     MOV        this,dword ptr [ESP + local_4]
    //         004c915f     TEST       this,this
    //         004c9161     JZ         LAB_004c9172
    //         004c9163     CALL       TRIBE_Building_Object::connect2                  void connect2(TRIBE_Building_Object * this)
    //                              t_b_obj.cpp:675 (6)
    //         004c9168     POP        EDI
    //         004c9169     POP        ESI
    //         004c916a     ADD        ESP,0x10
    //         004c916d     RET
    //                               LAB_004c916e                                                 XREF[1]:     004c90c7(j)  
    //                              t_b_obj.cpp:674 (4)
    //         004c916e     MOV        byte ptr [ESI + 0x35],0x0
    //                               LAB_004c9172                                                 XREF[2]:     004c90bc(j), 004c9161(j)  
    //                              t_b_obj.cpp:675 (6)
    //         004c9172     POP        EDI
    //         004c9173     POP        ESI
    //         004c9174     ADD        ESP,0x10
    //         004c9177     RET
    //         004c9178     ??         90h
    //         004c9179     NOP
    //         004c917a     NOP
    //         004c917b     NOP
    //         004c917c     NOP
    //         004c917d     NOP
    //         004c917e     NOP
    //         004c917f     NOP
    return;
}

void TRIBE_Building_Object::connect2() {
    /* TODO: Stub */
    //                              void __thiscall connect2(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004c91af(R)  
    //              TRIBE_Building    Stack[-0x14]   checks                    XREF[0,4]:   004c9199(*), 004c91a3(R), 004c91ab(R), 004c91a7(R)  
    //                               ?connect2@TRIBE_Building_Object@@QAEXXZ                      XREF[4]:     connect:004c913c(c), 
    //                               TRIBE_Building_Object::connect2                                           connect:004c9149(c), 
    //                                                                                                         connect:004c9156(c), 
    //                                                                                                         connect:004c9163(c)  
    //                              t_b_obj.cpp:680 (7)
    //         004c9180     SUB        ESP,0x10
    //         004c9183     PUSH       ESI
    //         004c9184     MOV        ESI,this
    //         004c9186     PUSH       EDI
    //                              t_b_obj.cpp:684 (11)
    //         004c9187     MOV        EAX,dword ptr [ESI + 0x10]
    //         004c918a     TEST       EAX,EAX
    //         004c918c     JZ         LAB_004c921c
    //                              t_b_obj.cpp:687 (7)
    //         004c9192     CMP        word ptr [EAX + 0x60],0x3
    //         004c9197     JNZ        LAB_004c9218
    //                              t_b_obj.cpp:689 (10)
    //         004c9199     LEA        EAX=>checks[1],[ESP + 0x8]
    //         004c919d     PUSH       EAX
    //         004c919e     CALL       TRIBE_Building_Object::check                     long check(TRIBE_Building_Object * this, TRIB
    //                              t_b_obj.cpp:691 (32)
    //         004c91a3     MOV        EAX,dword ptr [ESP + checks[1]]
    //         004c91a7     MOV        EDX,dword ptr [ESP + checks[3]]
    //         004c91ab     MOV        this,dword ptr [ESP + checks[2]]
    //         004c91af     MOV        EDI,dword ptr [ESP + local_4]
    //         004c91b3     TEST       EAX,EAX
    //         004c91b5     JZ         LAB_004c91db
    //         004c91b7     TEST       EDI,EDI
    //         004c91b9     JZ         LAB_004c91db
    //         004c91bb     TEST       this,this
    //         004c91bd     JNZ        LAB_004c91df
    //         004c91bf     TEST       EDX,EDX
    //         004c91c1     JNZ        LAB_004c91db
    //                              t_b_obj.cpp:692 (18)
    //         004c91c3     MOV        this,byte ptr [ESI + 0x35]
    //         004c91c6     MOV        EDX,0x1
    //         004c91cb     SUB        EDX,this
    //         004c91cd     MOV        this,ESI
    //         004c91cf     PUSH       EDX
    //         004c91d0     CALL       RGE_Moving_Object::rotate                        void rotate(RGE_Moving_Object * this, long pa
    //                              t_b_obj.cpp:700 (6)
    //         004c91d5     POP        EDI
    //         004c91d6     POP        ESI
    //         004c91d7     ADD        ESP,0x10
    //         004c91da     RET
    //                               LAB_004c91db                                                 XREF[3]:     004c91b5(j), 004c91b9(j), 
    //                                                                                                         004c91c1(j)  
    //                              t_b_obj.cpp:693 (16)
    //         004c91db     TEST       this,this
    //         004c91dd     JZ         LAB_004c91fe
    //                               LAB_004c91df                                                 XREF[1]:     004c91bd(j)  
    //         004c91df     TEST       EDX,EDX
    //         004c91e1     JZ         LAB_004c91fe
    //         004c91e3     TEST       EAX,EAX
    //         004c91e5     JNZ        LAB_004c91fe
    //         004c91e7     TEST       EDI,EDI
    //         004c91e9     JNZ        LAB_004c91fe
    //                              t_b_obj.cpp:694 (13)
    //         004c91eb     MOV        AL,byte ptr [ESI + 0x35]
    //         004c91ee     MOV        this,ESI
    //         004c91f0     NEG        EAX
    //         004c91f2     PUSH       EAX
    //         004c91f3     CALL       RGE_Moving_Object::rotate                        void rotate(RGE_Moving_Object * this, long pa
    //                              t_b_obj.cpp:700 (6)
    //         004c91f8     POP        EDI
    //         004c91f9     POP        ESI
    //         004c91fa     ADD        ESP,0x10
    //         004c91fd     RET
    //                               LAB_004c91fe                                                 XREF[4]:     004c91dd(j), 004c91e1(j), 
    //                                                                                                         004c91e5(j), 004c91e9(j)  
    //                              t_b_obj.cpp:696 (20)
    //         004c91fe     XOR        this,this
    //         004c9200     MOV        EDX,0x2
    //         004c9205     MOV        this,byte ptr [ESI + 0x35]
    //         004c9208     SUB        EDX,this
    //         004c920a     MOV        this,ESI
    //         004c920c     PUSH       EDX
    //         004c920d     CALL       RGE_Moving_Object::rotate                        void rotate(RGE_Moving_Object * this, long pa
    //                              t_b_obj.cpp:700 (6)
    //         004c9212     POP        EDI
    //         004c9213     POP        ESI
    //         004c9214     ADD        ESP,0x10
    //         004c9217     RET
    //                               LAB_004c9218                                                 XREF[1]:     004c9197(j)  
    //                              t_b_obj.cpp:699 (4)
    //         004c9218     MOV        byte ptr [ESI + 0x35],0x0
    //                               LAB_004c921c                                                 XREF[1]:     004c918c(j)  
    //                              t_b_obj.cpp:700 (6)
    //         004c921c     POP        EDI
    //         004c921d     POP        ESI
    //         004c921e     ADD        ESP,0x10
    //         004c9221     RET
    //         004c9222     ??         90h
    //         004c9223     NOP
    //         004c9224     NOP
    //         004c9225     NOP
    //         004c9226     NOP
    //         004c9227     NOP
    //         004c9228     NOP
    //         004c9229     NOP
    //         004c922a     NOP
    //         004c922b     NOP
    //         004c922c     NOP
    //         004c922d     NOP
    //         004c922e     NOP
    //         004c922f     NOP
    return;
}

void TRIBE_Building_Object::lay_down_impassable_terrain() {
    /* TODO: Stub */
    //                              void __thiscall lay_down_impassable_terrain(TRIBE_Building_Object * 
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004c924d(W), 004c92af(R), 004c9308(R)  
    //              RGE_Map *         Stack[-0x8]:4  map                       XREF[3]:     004c926a(W), 004c92a0(W), 004c92ec(R)  
    //              short             Stack[-0xc]:2  tx1                       XREF[4]:     004c927f(W), 004c92b3(R), 004c92c3(W), 004c92f0(R)  
    //              short             Stack[-0x10]:2 tx2
    //                               ?lay_down_impassable_terrain@TRIBE_Building_Object@@QAEXXZ
    //                               TRIBE_Building_Object::lay_down_impassable_terrain
    //                              t_b_obj.cpp:704 (9)
    //         004c9230     SUB        ESP,0xc
    //         004c9233     PUSH       EBX
    //         004c9234     PUSH       EBP
    //         004c9235     PUSH       ESI
    //         004c9236     MOV        ESI,this
    //         004c9238     PUSH       EDI
    //                              t_b_obj.cpp:712 (3)
    //         004c9239     MOV        EAX,dword ptr [ESI + 0xc]
    //                              t_b_obj.cpp:714 (27)
    //         004c923c     MOV        EDI,dword ptr [ESI + 0x8]
    //         004c923f     MOV        this,dword ptr [EAX + 0x3c]
    //         004c9242     CMP        word ptr [EDI + 0x174],-0x1
    //         004c924a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004c924d     MOV        dword ptr [ESP + local_4],EDX
    //         004c9251     JG         LAB_004c934c
    //                              t_b_obj.cpp:716 (11)
    //         004c9257     FLD        float ptr [ESI + 0x38]
    //         004c925a     FSUB       float ptr [EDI + 0x30]
    //         004c925d     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:717 (23)
    //         004c9262     FLD        float ptr [EDI + 0x30]
    //         004c9265     FADD       float ptr [ESI + 0x38]
    //         004c9268     MOV        EBP,EAX
    //         004c926a     MOV        dword ptr [ESP + map],EBP
    //         004c926e     FSUB       float ptr [DAT_005749f0]                         = 0Ah
    //         004c9274     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:718 (15)
    //         004c9279     FLD        float ptr [ESI + 0x3c]
    //         004c927c     FSUB       float ptr [EDI + 0x34]
    //         004c927f     MOV        dword ptr [ESP + tx1],EAX
    //         004c9283     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:719 (19)
    //         004c9288     FLD        float ptr [EDI + 0x34]
    //         004c928b     FADD       float ptr [ESI + 0x3c]
    //         004c928e     MOV        EBX,EAX
    //         004c9290     FSUB       float ptr [DAT_005749f0]                         = 0Ah
    //         004c9296     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:721 (13)
    //         004c929b     TEST       BP,BP
    //         004c929e     JGE        LAB_004c92a8
    //         004c92a0     MOV        dword ptr [ESP + map],0x0
    //                               LAB_004c92a8                                                 XREF[1]:     004c929e(j)  
    //                              t_b_obj.cpp:722 (7)
    //         004c92a8     TEST       BX,BX
    //         004c92ab     JGE        LAB_004c92af
    //         004c92ad     XOR        EBX,EBX
    //                               LAB_004c92af                                                 XREF[1]:     004c92ab(j)  
    //                              t_b_obj.cpp:723 (24)
    //         004c92af     MOV        this,dword ptr [ESP + local_4]
    //         004c92b3     MOVSX      EDX,word ptr [ESP + tx1]
    //         004c92b8     CMP        EDX,dword ptr [ECX + this->_padding_]
    //         004c92bb     JL         LAB_004c92c7
    //         004c92bd     MOV        DX,word ptr [ECX + this->_padding_]
    //         004c92c1     DEC        DX
    //         004c92c3     MOV        dword ptr [ESP + tx1],EDX
    //                               LAB_004c92c7                                                 XREF[1]:     004c92bb(j)  
    //                              t_b_obj.cpp:724 (16)
    //         004c92c7     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004c92ca     MOVSX      EDX,AX
    //         004c92cd     CMP        EDX,ESI
    //         004c92cf     JL         LAB_004c92d7
    //         004c92d1     MOV        AX,word ptr [ECX + this->_padding_]
    //         004c92d5     DEC        AX
    //                               LAB_004c92d7                                                 XREF[1]:     004c92cf(j)  
    //                              t_b_obj.cpp:726 (21)
    //         004c92d7     CMP        BX,AX
    //         004c92da     JG         LAB_004c934c
    //         004c92dc     MOVSX      this,BX
    //         004c92df     MOVSX      EBX,AX
    //         004c92e2     SUB        EBX,this
    //         004c92e4     LEA        EBP,[this->_padding_*0x4 + 0x0]
    //         004c92eb     INC        EBX
    //                               LAB_004c92ec                                                 XREF[1]:     004c934a(j)  
    //                              t_b_obj.cpp:727 (28)
    //         004c92ec     MOV        EAX,dword ptr [ESP + map]
    //         004c92f0     MOV        this,dword ptr [ESP + tx1]
    //         004c92f4     CMP        AX,this
    //         004c92f7     JG         LAB_004c9346
    //         004c92f9     MOVSX      EAX,AX
    //         004c92fc     MOVSX      EDI,this
    //         004c92ff     LEA        ESI,[EAX + EAX*0x2]
    //         004c9302     SUB        EDI,EAX
    //         004c9304     SHL        ESI,0x3
    //         004c9307     INC        EDI
    //                               LAB_004c9308                                                 XREF[1]:     004c9344(j)  
    //                              t_b_obj.cpp:729 (16)
    //         004c9308     MOV        EAX,dword ptr [ESP + local_4]
    //         004c930c     MOV        this,dword ptr [EAX + 0x8d8c]
    //         004c9312     MOV        this,dword ptr [EBP + this->_padding_*0x1]
    //         004c9316     ADD        this,ESI
    //                              t_b_obj.cpp:730 (21)
    //         004c9318     MOV        AL,byte ptr [ECX + this+0x5]
    //         004c931b     MOV        DL,AL
    //         004c931d     AND        EDX,0x1f
    //         004c9320     SUB        EDX,0x0
    //         004c9323     JZ         LAB_004c9339
    //         004c9325     DEC        EDX
    //         004c9326     JZ         LAB_004c9333
    //         004c9328     SUB        EDX,0x5
    //         004c932b     JNZ        LAB_004c9340
    //                              t_b_obj.cpp:736 (4)
    //         004c932d     AND        AL,0xee
    //         004c932f     OR         AL,0xe
    //                              t_b_obj.cpp:737 (2)
    //         004c9331     JMP        LAB_004c933d
    //                               LAB_004c9333                                                 XREF[1]:     004c9326(j)  
    //                              t_b_obj.cpp:739 (4)
    //         004c9333     AND        AL,0xef
    //         004c9335     OR         AL,0xf
    //                              t_b_obj.cpp:740 (2)
    //         004c9337     JMP        LAB_004c933d
    //                               LAB_004c9339                                                 XREF[1]:     004c9323(j)  
    //                              t_b_obj.cpp:733 (7)
    //         004c9339     AND        AL,0xf0
    //         004c933b     OR         AL,0x10
    //                               LAB_004c933d                                                 XREF[2]:     004c9331(j), 004c9337(j)  
    //         004c933d     MOV        byte ptr [ECX + this+0x5],AL
    //                               LAB_004c9340                                                 XREF[1]:     004c932b(j)  
    //                              t_b_obj.cpp:727 (6)
    //         004c9340     ADD        ESI,0x18
    //         004c9343     DEC        EDI
    //         004c9344     JNZ        LAB_004c9308
    //                               LAB_004c9346                                                 XREF[1]:     004c92f7(j)  
    //                              t_b_obj.cpp:726 (6)
    //         004c9346     ADD        EBP,0x4
    //         004c9349     DEC        EBX
    //         004c934a     JNZ        LAB_004c92ec
    //                               LAB_004c934c                                                 XREF[2]:     004c9251(j), 004c92da(j)  
    //                              t_b_obj.cpp:744 (8)
    //         004c934c     POP        EDI
    //         004c934d     POP        ESI
    //         004c934e     POP        EBP
    //         004c934f     POP        EBX
    //         004c9350     ADD        ESP,0xc
    //         004c9353     RET
    //         004c9354     ??         90h
    //         004c9355     NOP
    //         004c9356     NOP
    //         004c9357     NOP
    //         004c9358     NOP
    //         004c9359     NOP
    //         004c935a     NOP
    //         004c935b     NOP
    //         004c935c     NOP
    //         004c935d     NOP
    //         004c935e     NOP
    //         004c935f     NOP
    return;
}

void TRIBE_Building_Object::lay_down_passable_terrain() {
    /* TODO: Stub */
    //                              void __thiscall lay_down_passable_terrain(TRIBE_Building_Object * th
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004c937d(W), 004c93df(R), 004c9438(R)  
    //              RGE_Map *         Stack[-0x8]:4  map                       XREF[3]:     004c939a(W), 004c93d0(W), 004c941c(R)  
    //              short             Stack[-0xc]:2  tx1                       XREF[4]:     004c93af(W), 004c93e3(R), 004c93f3(W), 004c9420(R)  
    //              short             Stack[-0x10]:2 tx2
    //                               ?lay_down_passable_terrain@TRIBE_Building_Object@@QAEXXZ
    //                               TRIBE_Building_Object::lay_down_passable_terrain
    //                              t_b_obj.cpp:748 (9)
    //         004c9360     SUB        ESP,0xc
    //         004c9363     PUSH       EBX
    //         004c9364     PUSH       EBP
    //         004c9365     PUSH       ESI
    //         004c9366     MOV        ESI,this
    //         004c9368     PUSH       EDI
    //                              t_b_obj.cpp:756 (3)
    //         004c9369     MOV        EAX,dword ptr [ESI + 0xc]
    //                              t_b_obj.cpp:758 (27)
    //         004c936c     MOV        EDI,dword ptr [ESI + 0x8]
    //         004c936f     MOV        this,dword ptr [EAX + 0x3c]
    //         004c9372     CMP        word ptr [EDI + 0x174],-0x1
    //         004c937a     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004c937d     MOV        dword ptr [ESP + local_4],EDX
    //         004c9381     JG         LAB_004c9478
    //                              t_b_obj.cpp:760 (11)
    //         004c9387     FLD        float ptr [ESI + 0x38]
    //         004c938a     FSUB       float ptr [EDI + 0x30]
    //         004c938d     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:761 (23)
    //         004c9392     FLD        float ptr [EDI + 0x30]
    //         004c9395     FADD       float ptr [ESI + 0x38]
    //         004c9398     MOV        EBP,EAX
    //         004c939a     MOV        dword ptr [ESP + map],EBP
    //         004c939e     FSUB       float ptr [DAT_005749f0]                         = 0Ah
    //         004c93a4     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:762 (15)
    //         004c93a9     FLD        float ptr [ESI + 0x3c]
    //         004c93ac     FSUB       float ptr [EDI + 0x34]
    //         004c93af     MOV        dword ptr [ESP + tx1],EAX
    //         004c93b3     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:763 (19)
    //         004c93b8     FLD        float ptr [EDI + 0x34]
    //         004c93bb     FADD       float ptr [ESI + 0x3c]
    //         004c93be     MOV        EBX,EAX
    //         004c93c0     FSUB       float ptr [DAT_005749f0]                         = 0Ah
    //         004c93c6     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:765 (13)
    //         004c93cb     TEST       BP,BP
    //         004c93ce     JGE        LAB_004c93d8
    //         004c93d0     MOV        dword ptr [ESP + map],0x0
    //                               LAB_004c93d8                                                 XREF[1]:     004c93ce(j)  
    //                              t_b_obj.cpp:766 (7)
    //         004c93d8     TEST       BX,BX
    //         004c93db     JGE        LAB_004c93df
    //         004c93dd     XOR        EBX,EBX
    //                               LAB_004c93df                                                 XREF[1]:     004c93db(j)  
    //                              t_b_obj.cpp:767 (24)
    //         004c93df     MOV        this,dword ptr [ESP + local_4]
    //         004c93e3     MOVSX      EDX,word ptr [ESP + tx1]
    //         004c93e8     CMP        EDX,dword ptr [ECX + this->_padding_]
    //         004c93eb     JL         LAB_004c93f7
    //         004c93ed     MOV        DX,word ptr [ECX + this->_padding_]
    //         004c93f1     DEC        DX
    //         004c93f3     MOV        dword ptr [ESP + tx1],EDX
    //                               LAB_004c93f7                                                 XREF[1]:     004c93eb(j)  
    //                              t_b_obj.cpp:768 (16)
    //         004c93f7     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004c93fa     MOVSX      EDX,AX
    //         004c93fd     CMP        EDX,ESI
    //         004c93ff     JL         LAB_004c9407
    //         004c9401     MOV        AX,word ptr [ECX + this->_padding_]
    //         004c9405     DEC        AX
    //                               LAB_004c9407                                                 XREF[1]:     004c93ff(j)  
    //                              t_b_obj.cpp:770 (21)
    //         004c9407     CMP        BX,AX
    //         004c940a     JG         LAB_004c9478
    //         004c940c     MOVSX      this,BX
    //         004c940f     MOVSX      EBX,AX
    //         004c9412     SUB        EBX,this
    //         004c9414     LEA        EBP,[this->_padding_*0x4 + 0x0]
    //         004c941b     INC        EBX
    //                               LAB_004c941c                                                 XREF[1]:     004c9476(j)  
    //                              t_b_obj.cpp:771 (28)
    //         004c941c     MOV        EAX,dword ptr [ESP + map]
    //         004c9420     MOV        this,dword ptr [ESP + tx1]
    //         004c9424     CMP        AX,this
    //         004c9427     JG         LAB_004c9472
    //         004c9429     MOVSX      EAX,AX
    //         004c942c     MOVSX      EDI,this
    //         004c942f     LEA        ESI,[EAX + EAX*0x2]
    //         004c9432     SUB        EDI,EAX
    //         004c9434     SHL        ESI,0x3
    //         004c9437     INC        EDI
    //                               LAB_004c9438                                                 XREF[1]:     004c9470(j)  
    //                              t_b_obj.cpp:773 (16)
    //         004c9438     MOV        EAX,dword ptr [ESP + local_4]
    //         004c943c     MOV        this,dword ptr [EAX + 0x8d8c]
    //         004c9442     MOV        this,dword ptr [EBP + this->_padding_*0x1]
    //         004c9446     ADD        this,ESI
    //                              t_b_obj.cpp:774 (19)
    //         004c9448     MOV        AL,byte ptr [ECX + this+0x5]
    //         004c944b     MOV        DL,AL
    //         004c944d     AND        EDX,0x1f
    //         004c9450     SUB        EDX,0xe
    //         004c9453     JZ         LAB_004c9465
    //         004c9455     DEC        EDX
    //         004c9456     JZ         LAB_004c945f
    //         004c9458     DEC        EDX
    //         004c9459     JNZ        LAB_004c946c
    //                              t_b_obj.cpp:777 (2)
    //         004c945b     AND        AL,0xe0
    //                              t_b_obj.cpp:778 (2)
    //         004c945d     JMP        LAB_004c9469
    //                               LAB_004c945f                                                 XREF[1]:     004c9456(j)  
    //                              t_b_obj.cpp:783 (4)
    //         004c945f     AND        AL,0xe1
    //         004c9461     OR         AL,0x1
    //                              t_b_obj.cpp:784 (2)
    //         004c9463     JMP        LAB_004c9469
    //                               LAB_004c9465                                                 XREF[1]:     004c9453(j)  
    //                              t_b_obj.cpp:780 (7)
    //         004c9465     AND        AL,0xe6
    //         004c9467     OR         AL,0x6
    //                               LAB_004c9469                                                 XREF[2]:     004c945d(j), 004c9463(j)  
    //         004c9469     MOV        byte ptr [ECX + this+0x5],AL
    //                               LAB_004c946c                                                 XREF[1]:     004c9459(j)  
    //                              t_b_obj.cpp:771 (6)
    //         004c946c     ADD        ESI,0x18
    //         004c946f     DEC        EDI
    //         004c9470     JNZ        LAB_004c9438
    //                               LAB_004c9472                                                 XREF[1]:     004c9427(j)  
    //                              t_b_obj.cpp:770 (6)
    //         004c9472     ADD        EBP,0x4
    //         004c9475     DEC        EBX
    //         004c9476     JNZ        LAB_004c941c
    //                               LAB_004c9478                                                 XREF[2]:     004c9381(j), 004c940a(j)  
    //                              t_b_obj.cpp:788 (8)
    //         004c9478     POP        EDI
    //         004c9479     POP        ESI
    //         004c947a     POP        EBP
    //         004c947b     POP        EBX
    //         004c947c     ADD        ESP,0xc
    //         004c947f     RET
    return;
}

void TRIBE_Building_Object::cancel_object() {
    /* TODO: Stub */
    //                              void __thiscall cancel_object(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?cancel_object@TRIBE_Building_Object@@UAEXXZ                 XREF[1]:     005749b8(*)  
    //                               TRIBE_Building_Object::cancel_object
    //                              t_b_obj.cpp:792 (6)
    //         004c9480     CMP        byte ptr [ECX + this->_padding_],0x2
    //         004c9484     JNC        LAB_004c948b
    //                              t_b_obj.cpp:794 (5)
    //         004c9486     JMP        TRIBE_Building_Object::cancel_build              void cancel_build(TRIBE_Building_Object * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //                               LAB_004c948b                                                 XREF[1]:     004c9484(j)  
    //                              t_b_obj.cpp:799 (5)
    //         004c948b     JMP        TRIBE_Combat_Object::cancel_object               void cancel_object(TRIBE_Combat_Object * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    return;
}

void TRIBE_Building_Object::cancel_build() {
    /* TODO: Stub */
    //                              void __thiscall cancel_build(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c9530(W), 004c9534(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[7]:     004c94c7(W), 004c94cb(R), 004c94df(W), 004c94e7(W), 
    //                                                                                     004c94ef(R), 004c9500(W), 004c953d(R)  
    //              float             Stack[-0xc]:4  percent
    //              undefined4        Stack[-0x1c]:4 local_1c                  XREF[1]:     004c9541(*)  
    //                               ?cancel_build@TRIBE_Building_Object@@QAEXXZ                  XREF[1]:     cancel_object:004c9486(c)  
    //                               TRIBE_Building_Object::cancel_build
    //                              t_b_obj.cpp:805 (8)
    //         004c9490     SUB        ESP,0x8
    //         004c9493     PUSH       EBX
    //         004c9494     PUSH       ESI
    //         004c9495     PUSH       EDI
    //         004c9496     MOV        EDI,this
    //                              t_b_obj.cpp:811 (6)
    //         004c9498     TEST       byte ptr [EDI + 0x36],0x1
    //         004c949c     JZ         LAB_004c94a7
    //                              t_b_obj.cpp:812 (9)
    //         004c949e     MOV        this,dword ptr [EDI + 0xc]
    //         004c94a1     PUSH       EDI
    //         004c94a2     CALL       RGE_Player::unselect_one_object                  void unselect_one_object(RGE_Player * this, R
    //                               LAB_004c94a7                                                 XREF[1]:     004c949c(j)  
    //                              t_b_obj.cpp:815 (22)
    //         004c94a7     CMP        byte ptr [EDI + 0x48],0x2
    //         004c94ab     JNC        LAB_004c94e7
    //         004c94ad     FLD        float ptr [EDI + 0x30]
    //         004c94b0     FCOMP      float ptr [DAT_005749f4]
    //         004c94b6     FNSTSW     AX
    //         004c94b8     TEST       AH,0x41
    //         004c94bb     JNZ        LAB_004c94e7
    //                              t_b_obj.cpp:817 (40)
    //         004c94bd     MOV        EAX,dword ptr [EDI + 0x8]
    //         004c94c0     MOVSX      this,word ptr [EAX + 0x15a]
    //         004c94c7     MOV        dword ptr [ESP + local_8],this
    //         004c94cb     FILD       dword ptr [ESP + local_8]
    //         004c94cf     FLD        ST0
    //         004c94d1     FSUB       float ptr [EDI + 0x1dc]
    //         004c94d7     FDIV       ST0,ST1
    //         004c94d9     FMUL       double ptr [DAT_005749f8]
    //         004c94df     FSTP       float ptr [ESP + local_8]
    //         004c94e3     FSTP       ST0
    //                              t_b_obj.cpp:820 (2)
    //         004c94e5     JMP        LAB_004c94ef
    //                               LAB_004c94e7                                                 XREF[2]:     004c94ab(j), 004c94bb(j)  
    //                              t_b_obj.cpp:821 (8)
    //         004c94e7     MOV        dword ptr [ESP + local_8],0x0
    //                               LAB_004c94ef                                                 XREF[1]:     004c94e5(j)  
    //                              t_b_obj.cpp:825 (17)
    //         004c94ef     FLD        float ptr [ESP + local_8]
    //         004c94f3     FCOMP      double ptr [DAT_00574a00]
    //         004c94f9     FNSTSW     AX
    //         004c94fb     TEST       AH,0x41
    //         004c94fe     JNZ        LAB_004c9508
    //                              t_b_obj.cpp:826 (8)
    //         004c9500     MOV        dword ptr [ESP + local_8],0x3f800000
    //                               LAB_004c9508                                                 XREF[1]:     004c94fe(j)  
    //                              t_b_obj.cpp:828 (2)
    //         004c9508     XOR        ESI,ESI
    //                               LAB_004c950a                                                 XREF[1]:     004c954e(j)  
    //                              t_b_obj.cpp:831 (11)
    //         004c950a     MOV        EAX,dword ptr [EDI + 0x8]
    //         004c950d     MOV        DX,word ptr [ESI + EAX*0x1 + 0x148]
    //                              t_b_obj.cpp:832 (16)
    //         004c9515     TEST       DX,DX
    //         004c9518     JL         LAB_004c9548
    //         004c951a     MOV        this,byte ptr [ESI + EAX*0x1 + 0x14c]
    //         004c9521     TEST       this,this
    //         004c9523     JZ         LAB_004c9548
    //                              t_b_obj.cpp:837 (43)
    //         004c9525     MOVSX      EAX,word ptr [ESI + EAX*0x1 + 0x14a]
    //         004c952d     MOV        this,dword ptr [EDI + 0xc]
    //         004c9530     MOV        dword ptr [ESP + local_4],EAX
    //         004c9534     FILD       dword ptr [ESP + local_4]
    //         004c9538     MOV        EBX,dword ptr [this->_padding_]
    //         004c953a     PUSH       0x0
    //         004c953c     PUSH       this
    //         004c953d     FMUL       float ptr [ESP + local_8]
    //         004c9541     FSTP       float ptr [ESP]=>local_1c
    //         004c9544     PUSH       EDX
    //         004c9545     CALL       dword ptr [EBX + 0x78]
    //                               LAB_004c9548                                                 XREF[2]:     004c9518(j), 004c9523(j)  
    //         004c9548     ADD        ESI,0x6
    //         004c954b     CMP        ESI,0x12
    //         004c954e     JL         LAB_004c950a
    //                              t_b_obj.cpp:841 (7)
    //         004c9550     MOV        dword ptr [EDI + 0x30],0x0
    //                              t_b_obj.cpp:843 (7)
    //         004c9557     POP        EDI
    //         004c9558     POP        ESI
    //         004c9559     POP        EBX
    //         004c955a     ADD        ESP,0x8
    //         004c955d     RET
    //         004c955e     ??         90h
    //         004c955f     NOP
    return;
}

uchar TRIBE_Building_Object::build(float param_1) {
    /* TODO: Stub */
    //                              uchar __thiscall build(TRIBE_Building_Object * this, float param_1)
    //              uchar             AL:1           <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              float             Stack[0x4]:4   param_1                   XREF[6]:     004c957e(R), 004c9599(W), 004c95a9(R), 004c95d3(R), 
    //                                                                                     004c95ea(W), 004c95ee(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     004c9576(*), 004c957a(*), 004c95a1(*), 004c95a5(*), 
    //                                                                                     004c95b9(*), 004c95bd(*)  
    //                               ?build@TRIBE_Building_Object@@QAEEM@Z                        XREF[5]:     update:004cd845(c), 
    //                               TRIBE_Building_Object::build                                              do_command_tribe_create:00509972(c
    //                                                                                                         make_scenario_obj:00512234(c), 
    //                                                                                                         make_new_object:00512fba(c), 
    //                                                                                                         random_start:005141fb(c)  
    //                              t_b_obj.cpp:847 (1)
    //         004c9560     PUSH       this
    //                              t_b_obj.cpp:848 (11)
    //         004c9561     MOV        AL,byte ptr [ECX + this->_padding_]
    //         004c9564     TEST       AL,AL
    //         004c9566     JNZ        LAB_004c9610
    //                              t_b_obj.cpp:850 (37)
    //         004c956c     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         004c956f     MOVSX      EAX,word ptr [EDX + 0x15a]
    //         004c9576     MOV        dword ptr [ESP]=>local_4,EAX
    //         004c957a     FILD       dword ptr [ESP]=>local_4
    //         004c957e     FLD        float ptr [ESP + param_1]
    //         004c9582     FADD       float ptr [ECX + this->build_pts]
    //         004c9588     FCOMP
    //         004c958a     FNSTSW     AX
    //         004c958c     TEST       AH,0x41
    //         004c958f     JNZ        LAB_004c959d
    //                              t_b_obj.cpp:851 (12)
    //         004c9591     FLD        ST0
    //         004c9593     FSUB       float ptr [ECX + this->build_pts]
    //         004c9599     FSTP       float ptr [ESP + param_1]
    //                               LAB_004c959d                                                 XREF[1]:     004c958f(j)  
    //                              t_b_obj.cpp:853 (21)
    //         004c959d     MOVSX      EAX,word ptr [EDX + 0x26]
    //         004c95a1     MOV        dword ptr [ESP]=>local_4,EAX
    //         004c95a5     FILD       dword ptr [ESP]=>local_4
    //         004c95a9     FMUL       float ptr [ESP + param_1]
    //         004c95ad     FDIVRP
    //         004c95af     FADD       float ptr [ECX + this->_padding_]
    //                              t_b_obj.cpp:854 (26)
    //         004c95b2     FST        float ptr [ECX + this->_padding_]
    //         004c95b5     MOVSX      EAX,word ptr [EDX + 0x26]
    //         004c95b9     MOV        dword ptr [ESP]=>local_4,EAX
    //         004c95bd     FILD       dword ptr [ESP]=>local_4
    //         004c95c1     FXCH
    //         004c95c3     FCOMP
    //         004c95c5     FNSTSW     AX
    //         004c95c7     TEST       AH,0x41
    //         004c95ca     JNZ        LAB_004c95d1
    //                              t_b_obj.cpp:855 (3)
    //         004c95cc     FSTP       float ptr [ECX + this->_padding_]
    //                              t_b_obj.cpp:854 (4)
    //         004c95cf     JMP        LAB_004c95d3
    //                               LAB_004c95d1                                                 XREF[1]:     004c95ca(j)  
    //         004c95d1     FSTP       ST0
    //                               LAB_004c95d3                                                 XREF[1]:     004c95cf(j)  
    //                              t_b_obj.cpp:857 (10)
    //         004c95d3     FLD        float ptr [ESP + param_1]
    //         004c95d7     FADD       float ptr [ECX + this->build_pts]
    //                              t_b_obj.cpp:859 (32)
    //         004c95dd     FST        float ptr [ECX + this->build_pts]
    //         004c95e3     MOVSX      EDX,word ptr [EDX + 0x15a]
    //         004c95ea     MOV        dword ptr [ESP + param_1],EDX
    //         004c95ee     FILD       dword ptr [ESP + param_1]
    //         004c95f2     FXCH
    //         004c95f4     FCOMPP
    //         004c95f6     FNSTSW     AX
    //         004c95f8     TEST       AH,0x1
    //         004c95fb     JNZ        LAB_004c960a
    //                              t_b_obj.cpp:861 (7)
    //         004c95fd     MOV        EAX,dword ptr [this->_padding_]
    //         004c95ff     PUSH       0x2
    //         004c9601     CALL       dword ptr [EAX + 0x5c]
    //                              t_b_obj.cpp:867 (2)
    //         004c9604     MOV        AL,0x1
    //                              t_b_obj.cpp:868 (4)
    //         004c9606     POP        this
    //         004c9607     RET        0x4
    //                               LAB_004c960a                                                 XREF[1]:     004c95fb(j)  
    //                              t_b_obj.cpp:865 (2)
    //         004c960a     XOR        AL,AL
    //                              t_b_obj.cpp:868 (4)
    //         004c960c     POP        this
    //         004c960d     RET        0x4
    //                               LAB_004c9610                                                 XREF[1]:     004c9566(j)  
    //                              t_b_obj.cpp:867 (2)
    //         004c9610     MOV        AL,0x1
    //                              t_b_obj.cpp:868 (4)
    //         004c9612     POP        this
    //         004c9613     RET        0x4
    //         004c9616     ??         90h
    //         004c9617     NOP
    //         004c9618     NOP
    //         004c9619     NOP
    //         004c961a     NOP
    //         004c961b     NOP
    //         004c961c     NOP
    //         004c961d     NOP
    //         004c961e     NOP
    //         004c961f     NOP
    return 0;
}

int TRIBE_Building_Object::work_status(short* param_1, short* param_2, short* param_3, char* param_4, short param_5) {
    /* TODO: Stub */
    //                              int __thiscall work_status(TRIBE_Building_Object * this, short * par
    //              int               EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              short *           Stack[0x4]:4   param_1                   XREF[2]:     004c9631(R), 004c963e(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[3]:     004c9652(R), 004c9682(R), 004c96a3(R)  
    //              short *           Stack[0xc]:4   param_3                   XREF[3]:     004c9656(R), 004c967d(R), 004c969e(R)  
    //              char *            Stack[0x10]:4  param_4                   XREF[3]:     004c965f(R), 004c9678(R), 004c9699(R)  
    //              short             Stack[0x14]:2  param_5                   XREF[2]:     004c9674(R), 004c9695(R)  
    //                               ?work_status@TRIBE_Building_Object@@QAEHAAF00PADF@Z          XREF[7]:     setup_buttons:00499f0a(c), 
    //                               TRIBE_Building_Object::work_status                                        update_production_queue:004c9ded(c
    //                                                                                                         do_command_make:005099d5(c), 
    //                                                                                                         do_command_research:00509b45(c), 
    //                                                                                                         draw:0051b751(c), 
    //                                                                                                         handle_idle:0051c826(c), 
    //                                                                                                         save_object_info:0051cbd2(c)  
    //                              t_b_obj.cpp:872 (13)
    //         004c9620     MOV        this,dword ptr [ECX + this->_padding_]
    //         004c9626     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //         004c962b     MOV        this,EAX
    //                              t_b_obj.cpp:876 (4)
    //         004c962d     TEST       this,this
    //         004c962f     JZ         LAB_004c963e
    //                              t_b_obj.cpp:877 (11)
    //         004c9631     MOV        EAX,dword ptr [ESP + param_1]
    //         004c9635     MOV        DX,word ptr [ECX + this->_padding_]
    //         004c9639     MOV        word ptr [EAX],DX
    //                              t_b_obj.cpp:878 (2)
    //         004c963c     JMP        LAB_004c9647
    //                               LAB_004c963e                                                 XREF[1]:     004c962f(j)  
    //                              t_b_obj.cpp:879 (9)
    //         004c963e     MOV        EAX,dword ptr [ESP + param_1]
    //         004c9642     MOV        word ptr [EAX],0x0
    //                               LAB_004c9647                                                 XREF[1]:     004c963c(j)  
    //                              t_b_obj.cpp:881 (11)
    //         004c9647     MOVSX      EAX,word ptr [EAX]
    //         004c964a     SUB        EAX,0x66
    //         004c964d     JZ         LAB_004c9695
    //         004c964f     DEC        EAX
    //         004c9650     JZ         LAB_004c9674
    //                              t_b_obj.cpp:892 (4)
    //         004c9652     MOV        EAX,dword ptr [ESP + param_2]
    //                              t_b_obj.cpp:893 (9)
    //         004c9656     MOV        this,dword ptr [ESP + param_3]
    //         004c965a     MOV        word ptr [EAX],0xffff
    //                              t_b_obj.cpp:894 (13)
    //         004c965f     MOV        EAX,dword ptr [ESP + param_4]
    //         004c9663     TEST       EAX,EAX
    //         004c9665     MOV        word ptr [this->_padding_],0x0
    //         004c966a     JZ         LAB_004c966f
    //                              t_b_obj.cpp:895 (3)
    //         004c966c     MOV        byte ptr [EAX],0x0
    //                               LAB_004c966f                                                 XREF[1]:     004c966a(j)  
    //                              t_b_obj.cpp:896 (2)
    //         004c966f     XOR        EAX,EAX
    //                              t_b_obj.cpp:898 (3)
    //         004c9671     RET        0x14
    //                               LAB_004c9674                                                 XREF[1]:     004c9650(j)  
    //                              t_b_obj.cpp:888 (30)
    //         004c9674     MOV        EDX,dword ptr [ESP + param_5]
    //         004c9678     MOV        EAX,dword ptr [ESP + param_4]
    //         004c967c     PUSH       EDX
    //         004c967d     MOV        EDX,dword ptr [ESP + param_3]
    //         004c9681     PUSH       EAX
    //         004c9682     MOV        EAX,dword ptr [ESP + param_2]
    //         004c9686     PUSH       EDX
    //         004c9687     PUSH       EAX
    //         004c9688     CALL       TRIBE_Action_Make_Tech::get_info                 void get_info(TRIBE_Action_Make_Tech * this, 
    //         004c968d     MOV        EAX,0x1
    //                              t_b_obj.cpp:898 (3)
    //         004c9692     RET        0x14
    //                               LAB_004c9695                                                 XREF[1]:     004c964d(j)  
    //                              t_b_obj.cpp:884 (25)
    //         004c9695     MOV        EDX,dword ptr [ESP + param_5]
    //         004c9699     MOV        EAX,dword ptr [ESP + param_4]
    //         004c969d     PUSH       EDX
    //         004c969e     MOV        EDX,dword ptr [ESP + param_3]
    //         004c96a2     PUSH       EAX
    //         004c96a3     MOV        EAX,dword ptr [ESP + param_2]
    //         004c96a7     PUSH       EDX
    //         004c96a8     PUSH       EAX
    //         004c96a9     CALL       TRIBE_Action_Make_Obj::get_info                  void get_info(TRIBE_Action_Make_Obj * this, s
    //                              t_b_obj.cpp:885 (5)
    //         004c96ae     MOV        EAX,0x1
    //                              t_b_obj.cpp:898 (3)
    //         004c96b3     RET        0x14
    //         004c96b6     ??         90h
    //         004c96b7     NOP
    //         004c96b8     NOP
    //         004c96b9     NOP
    //         004c96ba     NOP
    //         004c96bb     NOP
    //         004c96bc     NOP
    //         004c96bd     NOP
    //         004c96be     NOP
    //         004c96bf     NOP
    return 0;
}

short TRIBE_Building_Object::get_construction_progress() {
    /* TODO: Stub */
    //                              short __thiscall get_construction_progress(TRIBE_Building_Object * t
    //              short             AX:2           <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c96e6(*), 004c96ea(*)  
    //                               ?get_construction_progress@TRIBE_Building_Object@@QAEFXZ     XREF[3]:     draw:0051b857(c), 
    //                               TRIBE_Building_Object::get_construction_progress                          handle_idle:0051c7c1(c), 
    //                                                                                                         save_object_info:0051cb9c(c)  
    //                              t_b_obj.cpp:902 (1)
    //         004c96c0     PUSH       this
    //                              t_b_obj.cpp:903 (7)
    //         004c96c1     MOV        AL,byte ptr [ECX + this->_padding_]
    //         004c96c4     TEST       AL,AL
    //         004c96c6     JZ         LAB_004c96ce
    //                              t_b_obj.cpp:904 (4)
    //         004c96c8     MOV        AX,0x64
    //                              t_b_obj.cpp:910 (2)
    //         004c96cc     POP        this
    //         004c96cd     RET
    //                               LAB_004c96ce                                                 XREF[1]:     004c96c6(j)  
    //                              t_b_obj.cpp:906 (15)
    //         004c96ce     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004c96d1     MOV        AX,word ptr [EAX + 0x15a]
    //         004c96d8     TEST       AX,AX
    //         004c96db     JNZ        LAB_004c96e3
    //                              t_b_obj.cpp:907 (4)
    //         004c96dd     MOV        AX,0x64
    //                              t_b_obj.cpp:910 (2)
    //         004c96e1     POP        this
    //         004c96e2     RET
    //                               LAB_004c96e3                                                 XREF[1]:     004c96db(j)  
    //                              t_b_obj.cpp:909 (28)
    //         004c96e3     MOVSX      EDX,AX
    //         004c96e6     MOV        dword ptr [ESP]=>local_4,EDX
    //         004c96ea     FILD       dword ptr [ESP]=>local_4
    //         004c96ee     FDIVR      float ptr [ECX + this->build_pts]
    //         004c96f4     FMUL       float ptr [DAT_00574a0c]
    //         004c96fa     CALL       __ftol                                           undefined __ftol()
    //                              t_b_obj.cpp:910 (2)
    //         004c96ff     POP        this
    //         004c9700     RET
    //         004c9701     ??         90h
    //         004c9702     NOP
    //         004c9703     NOP
    //         004c9704     NOP
    //         004c9705     NOP
    //         004c9706     NOP
    //         004c9707     NOP
    //         004c9708     NOP
    //         004c9709     NOP
    //         004c970a     NOP
    //         004c970b     NOP
    //         004c970c     NOP
    //         004c970d     NOP
    //         004c970e     NOP
    //         004c970f     NOP
    return 0;
}

void TRIBE_Building_Object::copy_obj(RGE_Master_Static_Object* param_1) {
    /* TODO: Stub */
    //                              void __thiscall copy_obj(TRIBE_Building_Object * this, RGE_Master_St
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              RGE_Master_Sta    Stack[0x4]:4   param_1                   XREF[1]:     004c9714(R)  
    //                               ?copy_obj@TRIBE_Building_Object@@UAEXPAVRGE_Master_Static_O  XREF[1]:     005747d0(*)  
    //                               TRIBE_Building_Object::copy_obj
    //                              t_b_obj.cpp:914 (4)
    //         004c9710     PUSH       ESI
    //         004c9711     MOV        ESI,this
    //         004c9713     PUSH       EDI
    //                              t_b_obj.cpp:915 (18)
    //         004c9714     MOV        EDI,dword ptr [ESP + param_1]
    //         004c9718     MOV        EAX,dword ptr [ESI + 0x8]
    //         004c971b     MOV        this,dword ptr [ESI + 0x10]
    //         004c971e     CMP        this,dword ptr [EAX + 0x168]
    //         004c9724     JNZ        LAB_004c9734
    //                              t_b_obj.cpp:916 (14)
    //         004c9726     MOV        EAX,dword ptr [EDI + 0x168]
    //         004c972c     MOV        EDX,dword ptr [ESI]
    //         004c972e     PUSH       EAX
    //         004c972f     MOV        this,ESI
    //         004c9731     CALL       dword ptr [EDX + 0x38]
    //                               LAB_004c9734                                                 XREF[1]:     004c9724(j)  
    //                              t_b_obj.cpp:918 (8)
    //         004c9734     PUSH       EDI
    //         004c9735     MOV        this,ESI
    //         004c9737     CALL       RGE_Combat_Object::copy_obj                      void copy_obj(RGE_Combat_Object * this, RGE_M
    //                              t_b_obj.cpp:920 (13)
    //         004c973c     MOV        this,dword ptr [ESI + 0x8]
    //         004c973f     MOV        AL,byte ptr [ECX + this->_padding_]
    //         004c9745     TEST       AL,AL
    //         004c9747     JZ         LAB_004c9750
    //                              t_b_obj.cpp:921 (7)
    //         004c9749     MOV        this,ESI
    //         004c974b     CALL       TRIBE_Building_Object::connect                   void connect(TRIBE_Building_Object * this)
    //                               LAB_004c9750                                                 XREF[1]:     004c9747(j)  
    //                              t_b_obj.cpp:922 (5)
    //         004c9750     POP        EDI
    //         004c9751     POP        ESI
    //         004c9752     RET        0x4
    //         004c9755     ??         90h
    //         004c9756     NOP
    //         004c9757     NOP
    //         004c9758     NOP
    //         004c9759     NOP
    //         004c975a     NOP
    //         004c975b     NOP
    //         004c975c     NOP
    //         004c975d     NOP
    //         004c975e     NOP
    //         004c975f     NOP
    return;
}

void TRIBE_Building_Object::rotate(long param_1) {
    /* TODO: Stub */
    //                              void __thiscall rotate(TRIBE_Building_Object * this, long param_1)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              long              Stack[0x4]:4   param_1
    //                               ?rotate@TRIBE_Building_Object@@UAEXJ@Z                       XREF[1]:     005747f0(*)  
    //                               TRIBE_Building_Object::rotate
    //                              t_b_obj.cpp:926 (3)
    //         004c9760     RET        0x4
    //         004c9763     ??         90h
    //         004c9764     NOP
    //         004c9765     NOP
    //         004c9766     NOP
    //         004c9767     NOP
    //         004c9768     NOP
    //         004c9769     NOP
    //         004c976a     NOP
    //         004c976b     NOP
    //         004c976c     NOP
    //         004c976d     NOP
    //         004c976e     NOP
    //         004c976f     NOP
    //                              * public: virtual void __thiscall TRIBE_Building_Object::damage(int,struct RGE_Armor_Weapon_Info *,f... *
    //                              void __thiscall damage(TRIBE_Building_Object * this, int param_1, RG
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c97a1(R)  
    //              RGE_Armor_Weap    Stack[0x8]:4   param_2                   XREF[1]:     004c979d(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004c9799(R)  
    //              RGE_Player *      Stack[0x10]:4  param_4                   XREF[1]:     004c9795(R)  
    //              RGE_Static_Obj    Stack[0x14]:4  param_5                   XREF[1]:     004c9791(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     004c9782(W), 004c97f4(R), 004c9808(R), 004c9814(R), 
    //                                                                                     004c9828(R)  
    //              float             Stack[-0x8]:4  temp_hp
    //                               ?damage@TRIBE_Building_Object@@UAEXHPAURGE_Armor_Weapon_Inf  XREF[1]:     005747e8(*)  
    //                               TRIBE_Building_Object::damage
    //                              t_b_obj.cpp:931 (6)
    //         004c9770     PUSH       this
    //         004c9771     PUSH       EBX
    //         004c9772     PUSH       ESI
    //         004c9773     PUSH       EDI
    //         004c9774     MOV        EDI,this
    //                              t_b_obj.cpp:934 (27)
    //         004c9776     FLD        float ptr [EDI + 0x30]
    //         004c9779     FCOMP      float ptr [DAT_005749f4]
    //         004c977f     MOV        EAX,dword ptr [EDI + 0x30]
    //         004c9782     MOV        dword ptr [ESP + local_4],EAX
    //         004c9786     FNSTSW     AX
    //         004c9788     TEST       AH,0x41
    //         004c978b     JNZ        LAB_004c985f
    //                              t_b_obj.cpp:939 (32)
    //         004c9791     MOV        ESI,dword ptr [ESP + param_5]
    //         004c9795     MOV        EBX,dword ptr [ESP + param_4]
    //         004c9799     MOV        this,dword ptr [ESP + param_3]
    //         004c979d     MOV        EDX,dword ptr [ESP + param_2]
    //         004c97a1     MOV        EAX,dword ptr [ESP + param_1]
    //         004c97a5     PUSH       ESI
    //         004c97a6     PUSH       EBX
    //         004c97a7     PUSH       this
    //         004c97a8     PUSH       EDX
    //         004c97a9     PUSH       EAX
    //         004c97aa     MOV        this,EDI
    //         004c97ac     CALL       RGE_Combat_Object::damage                        void damage(RGE_Combat_Object * this, int par
    //                              t_b_obj.cpp:951 (67)
    //         004c97b1     MOV        this,dword ptr [ESI + 0x8]
    //         004c97b4     MOV        AX,word ptr [ECX + this->_padding_]
    //         004c97b8     TEST       AX,AX
    //         004c97bb     JZ         LAB_004c9814
    //         004c97bd     CMP        AX,0x17
    //         004c97c1     JZ         LAB_004c9814
    //         004c97c3     CMP        AX,0x24
    //         004c97c7     JZ         LAB_004c9814
    //         004c97c9     CMP        AX,0x1a
    //         004c97cd     JZ         LAB_004c9814
    //         004c97cf     MOV        this,word ptr [ECX + this->_padding_]
    //         004c97d3     CMP        this,0x4f
    //         004c97d7     JZ         LAB_004c9814
    //         004c97d9     CMP        this,0x45
    //         004c97dd     JZ         LAB_004c9814
    //         004c97df     CMP        this,0xc7
    //         004c97e4     JZ         LAB_004c9814
    //         004c97e6     CMP        this,0x17f
    //         004c97eb     JZ         LAB_004c9814
    //         004c97ed     CMP        this,0x17c
    //         004c97f2     JZ         LAB_004c9814
    //                              t_b_obj.cpp:957 (20)
    //         004c97f4     FLD        float ptr [ESP + local_4]
    //         004c97f8     FSUB       float ptr [EDI + 0x30]
    //         004c97fb     FCOMP      double ptr [DAT_00574a00]
    //         004c9801     FNSTSW     AX
    //         004c9803     TEST       AH,0x1
    //         004c9806     JZ         LAB_004c9835
    //                              t_b_obj.cpp:958 (12)
    //         004c9808     FLD        float ptr [ESP + local_4]
    //         004c980c     FSUB       float ptr [DAT_00574a08]
    //         004c9812     JMP        LAB_004c9832
    //                               LAB_004c9814                                                 XREF[9]:     004c97bb(j), 004c97c1(j), 
    //                                                                                                         004c97c7(j), 004c97cd(j), 
    //                                                                                                         004c97d7(j), 004c97dd(j), 
    //                                                                                                         004c97e4(j), 004c97eb(j), 
    //                                                                                                         004c97f2(j)  
    //                              t_b_obj.cpp:953 (20)
    //         004c9814     FLD        float ptr [ESP + local_4]
    //         004c9818     FSUB       float ptr [EDI + 0x30]
    //         004c981b     FCOMP      double ptr [DAT_00574a10]                        = 9Ah
    //         004c9821     FNSTSW     AX
    //         004c9823     TEST       AH,0x1
    //         004c9826     JZ         LAB_004c9835
    //                              t_b_obj.cpp:954 (13)
    //         004c9828     FLD        float ptr [ESP + local_4]
    //         004c982c     FSUB       float ptr [DAT_00574a18]                         = CDh
    //                               LAB_004c9832                                                 XREF[1]:     004c9812(j)  
    //         004c9832     FSTP       float ptr [EDI + 0x30]
    //                               LAB_004c9835                                                 XREF[2]:     004c9806(j), 004c9826(j)  
    //                              t_b_obj.cpp:960 (26)
    //         004c9835     MOV        this,dword ptr [EDI + 0xc]
    //         004c9838     CMP        word ptr [ECX + this+0x4a],0x0
    //         004c983d     JLE        LAB_004c985f
    //         004c983f     FLD        float ptr [EDI + 0x30]
    //         004c9842     FCOMP      double ptr [DAT_00574a00]
    //         004c9848     FNSTSW     AX
    //         004c984a     TEST       AH,0x1
    //         004c984d     JZ         LAB_004c985f
    //                              t_b_obj.cpp:961 (16)
    //         004c984f     MOV        EDX,dword ptr [EBX]
    //         004c9851     PUSH       0x0
    //         004c9853     PUSH       0x3f800000
    //         004c9858     PUSH       0x2b
    //         004c985a     MOV        this,EBX
    //         004c985c     CALL       dword ptr [EDX + 0x78]
    //                               LAB_004c985f                                                 XREF[3]:     004c978b(j), 004c983d(j), 
    //                                                                                                         004c984d(j)  
    //                              t_b_obj.cpp:962 (7)
    //         004c985f     POP        EDI
    //         004c9860     POP        ESI
    //         004c9861     POP        EBX
    //         004c9862     POP        this
    //         004c9863     RET        0x14
    //         004c9866     ??         90h
    //         004c9867     NOP
    //         004c9868     NOP
    //         004c9869     NOP
    //         004c986a     NOP
    //         004c986b     NOP
    //         004c986c     NOP
    //         004c986d     NOP
    //         004c986e     NOP
    //         004c986f     NOP
    return;
}

void TRIBE_Building_Object::add_to_production_queue(short param_1, short param_2) {
    /* TODO: Stub */
    //                              void __thiscall add_to_production_queue(TRIBE_Building_Object * this
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[7]:     004c9877(R), 004c98b4(*), 004c98fa(R), 004c997c(*), 
    //                                                                                     004c9990(R), 004c9a64(*), 004c9aa5(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     004c98a4(R), 004c9a49(R)  
    //              undefined1        Stack[-0x1]:1  local_1                   XREF[3]:     004c9882(W), 004c98eb(W), 004c9919(R)  
    //              uchar             Stack[-0x5]:1  queue_changed
    //                               ?add_to_production_queue@TRIBE_Building_Object@@QAEXFF@Z     XREF[1]:     do_command_queue:0050a7d6(c)  
    //                               TRIBE_Building_Object::add_to_production_queue
    //                              t_b_obj.cpp:966 (7)
    //         004c9870     PUSH       this
    //         004c9871     PUSH       EBX
    //         004c9872     PUSH       EBP
    //         004c9873     PUSH       ESI
    //         004c9874     MOV        ESI,this
    //         004c9876     PUSH       EDI
    //                              t_b_obj.cpp:971 (45)
    //         004c9877     MOV        EDI,dword ptr [ESP + param_1]
    //         004c987b     MOV        AX,word ptr [ESI + 0x1ce]
    //         004c9882     MOV        byte ptr [ESP + local_1],0x0
    //         004c9887     TEST       AX,AX
    //         004c988a     JLE        LAB_004c9955
    //         004c9890     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9896     MOVSX      this,AX
    //         004c9899     CMP        word ptr [EDX + this->_padding_*0x4 + -0x4],DI
    //         004c989e     JNZ        LAB_004c9955
    //                              t_b_obj.cpp:973 (11)
    //         004c98a4     MOVSX      EBX,word ptr [ESP + param_2]
    //         004c98a9     XOR        EBP,EBP
    //         004c98ab     TEST       EBX,EBX
    //         004c98ad     JLE        LAB_004c9919
    //                               LAB_004c98af                                                 XREF[1]:     004c98f6(j)  
    //                              t_b_obj.cpp:975 (25)
    //         004c98af     MOV        this,dword ptr [ESI + 0xc]
    //         004c98b2     PUSH       0x1
    //         004c98b4     LEA        EAX=>param_1,[ESP + 0x1c]
    //         004c98b8     PUSH       0x3f800000
    //         004c98bd     PUSH       EAX
    //         004c98be     PUSH       EDI
    //         004c98bf     CALL       TRIBE_Player::check_obj_cost                     uchar check_obj_cost(TRIBE_Player * this, sho
    //         004c98c4     TEST       AL,AL
    //         004c98c6     JZ         LAB_004c98fa
    //                              t_b_obj.cpp:981 (16)
    //         004c98c8     MOV        this,dword ptr [ESI + 0xc]
    //         004c98cb     PUSH       0x1
    //         004c98cd     PUSH       0x3f800000
    //         004c98d2     PUSH       EDI
    //         004c98d3     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
    //                              t_b_obj.cpp:982 (19)
    //         004c98d8     MOVSX      this,word ptr [ESI + 0x1ce]
    //         004c98df     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c98e5     INC        word ptr [EDX + this->_padding_*0x4 + -0x2]
    //         004c98ea     INC        EBP
    //                              t_b_obj.cpp:983 (15)
    //         004c98eb     MOV        byte ptr [ESP + local_1],0x1
    //         004c98f0     LEA        EAX,[EDX + this->_padding_*0x4 + -0x2]
    //         004c98f4     CMP        EBP,EBX
    //         004c98f6     JL         LAB_004c98af
    //         004c98f8     JMP        LAB_004c9919
    //                               LAB_004c98fa                                                 XREF[1]:     004c98c6(j)  
    //                              t_b_obj.cpp:977 (31)
    //         004c98fa     MOVSX      EDX,word ptr [ESP + param_1]
    //         004c98ff     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9905     PUSH       0x0
    //         004c9907     PUSH       0x0
    //         004c9909     PUSH       EDX
    //         004c990a     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c990d     MOV        EAX,dword ptr [this->_padding_]
    //         004c990f     MOVSX      EDX,word ptr [EDX + 0x4a]
    //         004c9913     PUSH       EDX
    //                              language.dll match for 0x7d: "Arial"
    //         004c9914     PUSH       0x7d
    //         004c9916     CALL       dword ptr [EAX + 0x40]
    //                               LAB_004c9919                                                 XREF[2]:     004c98ad(j), 004c98f8(j)  
    //                              t_b_obj.cpp:986 (11)
    //         004c9919     CMP        byte ptr [ESP + local_1],0x1
    //         004c991e     JNZ        LAB_004c9b05
    //                              t_b_obj.cpp:988 (6)
    //         004c9924     MOV        AL,byte ptr [ESI + 0x1d8]
    //                              t_b_obj.cpp:990 (35)
    //         004c992a     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c992d     INC        AL
    //         004c992f     PUSH       0x0
    //         004c9931     MOV        byte ptr [ESI + 0x1d8],AL
    //         004c9937     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c993d     MOVSX      EDX,word ptr [EDX + 0x4a]
    //         004c9941     MOV        EAX,dword ptr [this->_padding_]
    //         004c9943     PUSH       0x0=>DAT_fffffff8
    //         004c9945     PUSH       0x0=>DAT_fffffff4
    //         004c9947     PUSH       EDX=>DAT_fffffff0
    //                              language.dll match for 0x7c: "B"
    //         004c9948     PUSH       0x7c
    //         004c994a     CALL       dword ptr [EAX + 0x40]
    //                              t_b_obj.cpp:1043 (8)
    //         004c994d     POP        EDI
    //         004c994e     POP        ESI
    //         004c994f     POP        EBP
    //         004c9950     POP        EBX
    //         004c9951     POP        this
    //         004c9952     RET        0x8
    //                               LAB_004c9955                                                 XREF[2]:     004c988a(j), 004c989e(j)  
    //                              t_b_obj.cpp:996 (5)
    //         004c9955     TEST       AX,AX
    //         004c9958     JLE        LAB_004c9977
    //                               LAB_004c995a                                                 XREF[1]:     004c9975(j)  
    //                              t_b_obj.cpp:997 (29)
    //         004c995a     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c9960     PUSH       0x1
    //         004c9962     MOV        this,word ptr [EAX]
    //         004c9965     PUSH       this
    //         004c9966     MOV        this,ESI
    //         004c9968     CALL       TRIBE_Building_Object::remove_from_production_   void remove_from_production_queue(TRIBE_Build
    //         004c996d     CMP        word ptr [ESI + 0x1ce],0x0
    //         004c9975     JG         LAB_004c995a
    //                               LAB_004c9977                                                 XREF[1]:     004c9958(j)  
    //                              t_b_obj.cpp:1000 (25)
    //         004c9977     MOV        this,dword ptr [ESI + 0xc]
    //         004c997a     PUSH       0x1
    //         004c997c     LEA        EDX=>param_1,[ESP + 0x1c]
    //         004c9980     PUSH       0x3f800000
    //         004c9985     PUSH       EDX
    //         004c9986     PUSH       EDI
    //         004c9987     CALL       TRIBE_Player::check_obj_cost                     uchar check_obj_cost(TRIBE_Player * this, sho
    //         004c998c     TEST       AL,AL
    //         004c998e     JNZ        LAB_004c99b7
    //                              t_b_obj.cpp:1002 (31)
    //         004c9990     MOVSX      EDX,word ptr [ESP + param_1]
    //         004c9995     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c999b     PUSH       0x0
    //         004c999d     PUSH       0x0
    //         004c999f     PUSH       EDX
    //         004c99a0     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c99a3     MOV        EAX,dword ptr [this->_padding_]
    //         004c99a5     MOVSX      EDX,word ptr [EDX + 0x4a]
    //         004c99a9     PUSH       EDX
    //                              language.dll match for 0x7d: "Arial"
    //         004c99aa     PUSH       0x7d
    //         004c99ac     CALL       dword ptr [EAX + 0x40]
    //                              t_b_obj.cpp:1043 (8)
    //         004c99af     POP        EDI
    //         004c99b0     POP        ESI
    //         004c99b1     POP        EBP
    //         004c99b2     POP        EBX
    //         004c99b3     POP        this
    //         004c99b4     RET        0x8
    //                               LAB_004c99b7                                                 XREF[1]:     004c998e(j)  
    //                              t_b_obj.cpp:1006 (16)
    //         004c99b7     MOV        AX,word ptr [ESI + 0x1cc]
    //         004c99be     CMP        word ptr [ESI + 0x1ce],AX
    //         004c99c5     JNZ        LAB_004c9a42
    //                              t_b_obj.cpp:1009 (19)
    //         004c99c7     MOVSX      EAX,AX
    //         004c99ca     ADD        EAX,0xa
    //         004c99cd     PUSH       0x4
    //         004c99cf     PUSH       EAX
    //         004c99d0     CALL       calloc                                           undefined calloc()
    //         004c99d5     MOV        EBX,EAX
    //         004c99d7     ADD        ESP,0x8
    //                              t_b_obj.cpp:1010 (8)
    //         004c99da     TEST       EBX,EBX
    //         004c99dc     JZ         LAB_004c9b05
    //                              t_b_obj.cpp:1012 (10)
    //         004c99e2     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c99e8     TEST       EAX,EAX
    //         004c99ea     JZ         LAB_004c9a34
    //                              t_b_obj.cpp:1014 (11)
    //         004c99ec     XOR        this,this
    //         004c99ee     CMP        word ptr [ESI + 0x1cc],this
    //         004c99f5     JLE        LAB_004c9a25
    //                               LAB_004c99f7                                                 XREF[1]:     004c9a23(j)  
    //                              t_b_obj.cpp:1016 (21)
    //         004c99f7     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c99fd     MOVSX      EAX,this
    //         004c9a00     SHL        EAX,0x2
    //         004c9a03     INC        this
    //         004c9a04     MOV        DX,word ptr [EAX + EDX*0x1]
    //         004c9a08     MOV        word ptr [EBX + EAX*0x1],DX
    //                              t_b_obj.cpp:1017 (25)
    //         004c9a0c     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9a12     MOV        DX,word ptr [EAX + EDX*0x1 + 0x2]
    //         004c9a17     MOV        word ptr [EBX + EAX*0x1 + 0x2],DX
    //         004c9a1c     CMP        this,word ptr [ESI + 0x1cc]
    //         004c9a23     JL         LAB_004c99f7
    //                               LAB_004c9a25                                                 XREF[1]:     004c99f5(j)  
    //                              t_b_obj.cpp:1019 (15)
    //         004c9a25     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c9a2b     PUSH       EAX
    //         004c9a2c     CALL       free                                             undefined free()
    //         004c9a31     ADD        ESP,0x4
    //                               LAB_004c9a34                                                 XREF[1]:     004c99ea(j)  
    //                              t_b_obj.cpp:1022 (14)
    //         004c9a34     ADD        word ptr [ESI + 0x1cc],0xa
    //         004c9a3c     MOV        dword ptr [ESI + 0x1c8],EBX
    //                               LAB_004c9a42                                                 XREF[1]:     004c99c5(j)  
    //                              t_b_obj.cpp:1026 (7)
    //         004c9a42     MOVSX      this,word ptr [ESI + 0x1ce]
    //                              t_b_obj.cpp:1027 (22)
    //         004c9a49     MOVSX      EBP,word ptr [ESP + param_2]
    //         004c9a4e     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9a54     XOR        EBX,EBX
    //         004c9a56     TEST       EBP,EBP
    //         004c9a58     MOV        word ptr [EDX + this->_padding_*0x4 + 0x2],BX
    //         004c9a5d     JLE        LAB_004c9ac4
    //                               LAB_004c9a5f                                                 XREF[1]:     004c9aa1(j)  
    //                              t_b_obj.cpp:1029 (25)
    //         004c9a5f     MOV        this,dword ptr [ESI + 0xc]
    //         004c9a62     PUSH       0x1
    //         004c9a64     LEA        EAX=>param_1,[ESP + 0x1c]
    //         004c9a68     PUSH       0x3f800000
    //         004c9a6d     PUSH       EAX
    //         004c9a6e     PUSH       EDI
    //         004c9a6f     CALL       TRIBE_Player::check_obj_cost                     uchar check_obj_cost(TRIBE_Player * this, sho
    //         004c9a74     TEST       AL,AL
    //         004c9a76     JZ         LAB_004c9aa5
    //                              t_b_obj.cpp:1035 (16)
    //         004c9a78     MOV        this,dword ptr [ESI + 0xc]
    //         004c9a7b     PUSH       0x1
    //         004c9a7d     PUSH       0x3f800000
    //         004c9a82     PUSH       EDI
    //         004c9a83     CALL       TRIBE_Player::pay_obj_cost                       uchar pay_obj_cost(TRIBE_Player * this, short
    //                              t_b_obj.cpp:1036 (29)
    //         004c9a88     MOVSX      this,word ptr [ESI + 0x1ce]
    //         004c9a8f     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9a95     INC        word ptr [EDX + this->_padding_*0x4 + 0x2]
    //         004c9a9a     INC        EBX
    //         004c9a9b     LEA        EAX,[EDX + this->_padding_*0x4 + 0x2]
    //         004c9a9f     CMP        EBX,EBP
    //         004c9aa1     JL         LAB_004c9a5f
    //         004c9aa3     JMP        LAB_004c9ac4
    //                               LAB_004c9aa5                                                 XREF[1]:     004c9a76(j)  
    //                              t_b_obj.cpp:1031 (31)
    //         004c9aa5     MOVSX      EDX,word ptr [ESP + param_1]
    //         004c9aaa     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9ab0     PUSH       0x0
    //         004c9ab2     PUSH       0x0
    //         004c9ab4     PUSH       EDX
    //         004c9ab5     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c9ab8     MOV        EAX,dword ptr [this->_padding_]
    //         004c9aba     MOVSX      EDX,word ptr [EDX + 0x4a]
    //         004c9abe     PUSH       EDX
    //                              language.dll match for 0x7d: "Arial"
    //         004c9abf     PUSH       0x7d
    //         004c9ac1     CALL       dword ptr [EAX + 0x40]
    //                               LAB_004c9ac4                                                 XREF[2]:     004c9a5d(j), 004c9aa3(j)  
    //                              t_b_obj.cpp:1039 (13)
    //         004c9ac4     MOVSX      EAX,word ptr [ESI + 0x1ce]
    //         004c9acb     MOV        this,dword ptr [ESI + 0x1c8]
    //                              t_b_obj.cpp:1042 (52)
    //         004c9ad1     PUSH       0x0
    //         004c9ad3     PUSH       0x0=>DAT_fffffff8
    //         004c9ad5     PUSH       0x0=>DAT_fffffff4
    //         004c9ad7     MOV        word ptr [this->_padding_ + EAX*0x4],DI
    //         004c9adb     MOV        AL,byte ptr [ESI + 0x1d8]
    //         004c9ae1     INC        word ptr [ESI + 0x1ce]
    //         004c9ae8     INC        AL
    //         004c9aea     MOV        byte ptr [ESI + 0x1d8],AL
    //         004c9af0     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c9af3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9af9     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004c9afd     MOV        EDX,dword ptr [this->_padding_]
    //         004c9aff     PUSH       EAX=>DAT_fffffff0
    //                              language.dll match for 0x7c: "B"
    //         004c9b00     PUSH       0x7c
    //         004c9b02     CALL       dword ptr [EDX + 0x40]
    //                               LAB_004c9b05                                                 XREF[2]:     004c991e(j), 004c99dc(j)  
    //                              t_b_obj.cpp:1043 (8)
    //         004c9b05     POP        EDI
    //         004c9b06     POP        ESI
    //         004c9b07     POP        EBP
    //         004c9b08     POP        EBX
    //         004c9b09     POP        this
    //         004c9b0a     RET        0x8
    //         004c9b0d     ??         90h
    //         004c9b0e     NOP
    //         004c9b0f     NOP
    return;
}

void TRIBE_Building_Object::remove_from_production_queue(short param_1, short param_2) {
    /* TODO: Stub */
    //                              void __thiscall remove_from_production_queue(TRIBE_Building_Object *
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              short             Stack[0x4]:2   param_1                   XREF[2]:     004c9b3d(R), 004c9b6e(R)  
    //              short             Stack[0x8]:2   param_2                   XREF[2]:     004c9b4f(R), 004c9b7e(R)  
    //                               ?remove_from_production_queue@TRIBE_Building_Object@@QAEXFF@Z XREF[4]:     add_to_production_queue:004c9968(c
    //                               TRIBE_Building_Object::remove_from_production_queue                       update_production_queue:004c9e23(c
    //                                                                                                         stop:004ca0d0(c), 
    //                                                                                                         do_command_queue:0050a7e7(c)  
    //                              t_b_obj.cpp:1047 (4)
    //         004c9b10     PUSH       EBX
    //         004c9b11     PUSH       ESI
    //         004c9b12     MOV        ESI,this
    //                              t_b_obj.cpp:1050 (16)
    //         004c9b14     MOV        BX,word ptr [ESI + 0x1ce]
    //         004c9b1b     TEST       BX,BX
    //         004c9b1e     JZ         LAB_004c9c6e
    //                              t_b_obj.cpp:1052 (12)
    //         004c9b24     DEC        EBX
    //         004c9b25     PUSH       EDI
    //         004c9b26     TEST       BX,BX
    //         004c9b29     PUSH       EBP
    //         004c9b2a     JL         LAB_004c9c51
    //                              t_b_obj.cpp:1054 (31)
    //         004c9b30     MOV        EAX,dword ptr [ESI + 0x1c8]
    //                               LAB_004c9b36                                                 XREF[1]:     004c9b48(j)  
    //         004c9b36     MOVSX      this,BX
    //         004c9b39     MOV        DX,word ptr [EAX + this->_padding_*0x4]
    //         004c9b3d     CMP        DX,word ptr [ESP + param_1]
    //         004c9b42     JZ         LAB_004c9b4f
    //         004c9b44     DEC        EBX
    //         004c9b45     TEST       BX,BX
    //         004c9b48     JGE        LAB_004c9b36
    //         004c9b4a     JMP        LAB_004c9c51
    //                               LAB_004c9b4f                                                 XREF[1]:     004c9b42(j)  
    //                              t_b_obj.cpp:1056 (11)
    //         004c9b4f     MOV        this,word ptr [ESP + param_2]
    //         004c9b54     MOVSX      EDI,BX
    //         004c9b57     SHL        EDI,0x2
    //                              t_b_obj.cpp:1057 (13)
    //         004c9b5a     MOVSX      EBP,this
    //         004c9b5d     MOV        AX,word ptr [EAX + EDI*0x1 + 0x2]
    //         004c9b62     CMP        AX,this
    //         004c9b65     JG         LAB_004c9b6a
    //                              t_b_obj.cpp:1059 (3)
    //         004c9b67     MOVSX      EBP,AX
    //                               LAB_004c9b6a                                                 XREF[1]:     004c9b65(j)  
    //                              t_b_obj.cpp:1061 (4)
    //         004c9b6a     TEST       EBP,EBP
    //         004c9b6c     JLE        LAB_004c9b83
    //                               LAB_004c9b6e                                                 XREF[1]:     004c9b7c(j)  
    //                              t_b_obj.cpp:1062 (16)
    //         004c9b6e     MOV        EAX,dword ptr [ESP + param_1]
    //         004c9b72     MOV        this,dword ptr [ESI + 0xc]
    //         004c9b75     PUSH       EAX
    //         004c9b76     CALL       TRIBE_Player::reimburse_obj_cost                 void reimburse_obj_cost(TRIBE_Player * this, 
    //         004c9b7b     DEC        EBP
    //         004c9b7c     JNZ        LAB_004c9b6e
    //                              t_b_obj.cpp:1061 (5)
    //         004c9b7e     MOV        this,word ptr [ESP + param_2]
    //                               LAB_004c9b83                                                 XREF[1]:     004c9b6c(j)  
    //                              t_b_obj.cpp:1064 (15)
    //         004c9b83     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9b89     SUB        word ptr [EDI + EDX*0x1 + 0x2],this
    //         004c9b8e     LEA        EAX,[EDI + EDX*0x1 + 0x2]
    //                              t_b_obj.cpp:1065 (6)
    //         004c9b92     MOV        DL,byte ptr [ESI + 0x1d8]
    //                              t_b_obj.cpp:1066 (26)
    //         004c9b98     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c9b9e     INC        DL
    //         004c9ba0     MOV        byte ptr [ESI + 0x1d8],DL
    //         004c9ba6     CMP        word ptr [EDI + EAX*0x1 + 0x2],0x0
    //         004c9bac     JG         LAB_004c9c51
    //                              t_b_obj.cpp:1068 (14)
    //         004c9bb2     DEC        word ptr [ESI + 0x1ce]
    //         004c9bb9     MOV        this,word ptr [ESI + 0x1ce]
    //                              t_b_obj.cpp:1069 (7)
    //         004c9bc0     CMP        BX,this
    //         004c9bc3     MOV        EAX,EBX
    //         004c9bc5     JGE        LAB_004c9bfc
    //                               LAB_004c9bc7                                                 XREF[1]:     004c9bfa(j)  
    //                              t_b_obj.cpp:1071 (26)
    //         004c9bc7     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9bcd     MOVSX      this,AX
    //         004c9bd0     INC        EAX
    //         004c9bd1     LEA        EDI,[this->_padding_*0x4 + 0x0]
    //         004c9bd8     MOV        this,word ptr [EDX + this->_padding_*0x4 + 0x4]
    //         004c9bdd     MOV        word ptr [EDI + EDX*0x1],this
    //                              t_b_obj.cpp:1072 (27)
    //         004c9be1     MOV        EDX,dword ptr [ESI + 0x1c8]
    //         004c9be7     LEA        this,[EDI + EDX*0x1]
    //         004c9bea     MOV        DX,word ptr [EDI + EDX*0x1 + 0x6]
    //         004c9bef     MOV        word ptr [ECX + this+0x2],DX
    //         004c9bf3     CMP        AX,word ptr [ESI + 0x1ce]
    //         004c9bfa     JL         LAB_004c9bc7
    //                               LAB_004c9bfc                                                 XREF[1]:     004c9bc5(j)  
    //                              t_b_obj.cpp:1074 (5)
    //         004c9bfc     TEST       BX,BX
    //         004c9bff     JNZ        LAB_004c9c51
    //                              t_b_obj.cpp:1076 (13)
    //         004c9c01     MOV        AX,word ptr [ESI + 0x1da]
    //         004c9c08     CMP        AX,0xffff
    //         004c9c0c     JZ         LAB_004c9c3b
    //                              t_b_obj.cpp:1079 (6)
    //         004c9c0e     CMP        AX,0x4
    //         004c9c12     JNZ        LAB_004c9c32
    //                              t_b_obj.cpp:1080 (30)
    //         004c9c14     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c9c17     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004c9c1d     MOVSX      this,word ptr [EAX + 0x4a]
    //         004c9c21     LEA        EAX,[EDX + this->_padding_*0x4 + 0xa34]
    //         004c9c28     MOV        this,dword ptr [EDX + this->_padding_*0x4 + 0x
    //         004c9c2f     DEC        this
    //         004c9c30     MOV        dword ptr [EAX],this
    //                               LAB_004c9c32                                                 XREF[1]:     004c9c12(j)  
    //                              t_b_obj.cpp:1082 (9)
    //         004c9c32     MOV        word ptr [ESI + 0x1da],0xffff
    //                               LAB_004c9c3b                                                 XREF[1]:     004c9c0c(j)  
    //                              t_b_obj.cpp:1084 (11)
    //         004c9c3b     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c9c41     CALL       RGE_Action_List::action_stop                     int action_stop(RGE_Action_List * this)
    //                              t_b_obj.cpp:1085 (11)
    //         004c9c46     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c9c4c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                               LAB_004c9c51                                                 XREF[4]:     004c9b2a(j), 004c9b4a(j), 
    //                                                                                                         004c9bac(j), 004c9bff(j)  
    //                              t_b_obj.cpp:1091 (29)
    //         004c9c51     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c9c54     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9c5a     PUSH       0x0
    //         004c9c5c     PUSH       0x0
    //         004c9c5e     MOVSX      EDX,word ptr [EDX + 0x4a]
    //         004c9c62     MOV        EAX,dword ptr [this->_padding_]
    //         004c9c64     PUSH       0x0
    //         004c9c66     PUSH       EDX
    //                              language.dll match for 0x7c: "B"
    //         004c9c67     PUSH       0x7c
    //         004c9c69     CALL       dword ptr [EAX + 0x40]
    //         004c9c6c     POP        EBP
    //         004c9c6d     POP        EDI
    //                               LAB_004c9c6e                                                 XREF[1]:     004c9b1e(j)  
    //                              t_b_obj.cpp:1092 (5)
    //         004c9c6e     POP        ESI
    //         004c9c6f     POP        EBX
    //         004c9c70     RET        0x8
    //         004c9c73     ??         90h
    //         004c9c74     NOP
    //         004c9c75     NOP
    //         004c9c76     NOP
    //         004c9c77     NOP
    //         004c9c78     NOP
    //         004c9c79     NOP
    //         004c9c7a     NOP
    //         004c9c7b     NOP
    //         004c9c7c     NOP
    //         004c9c7d     NOP
    //         004c9c7e     NOP
    //         004c9c7f     NOP
    return;
}

void TRIBE_Building_Object::advance_production_queue() {
    /* TODO: Stub */
    //                              void __thiscall advance_production_queue(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?advance_production_queue@TRIBE_Building_Object@@QAEXXZ      XREF[1]:     update_production_queue:004c9f7a(c
    //                               TRIBE_Building_Object::advance_production_queue
    //                              t_b_obj.cpp:1096 (3)
    //         004c9c80     MOV        EAX,this
    //         004c9c82     PUSH       ESI
    //                              t_b_obj.cpp:1097 (14)
    //         004c9c83     CMP        word ptr [EAX + 0x1ce],0x0
    //         004c9c8b     JZ         LAB_004c9d13
    //                              t_b_obj.cpp:1100 (10)
    //         004c9c91     MOV        this,dword ptr [EAX + 0x1c8]
    //         004c9c97     DEC        word ptr [ECX + this+0x2]
    //                              t_b_obj.cpp:1101 (14)
    //         004c9c9b     MOV        this,byte ptr [EAX + 0x1d8]
    //         004c9ca1     INC        this
    //         004c9ca3     MOV        byte ptr [EAX + 0x1d8],this
    //                              t_b_obj.cpp:1102 (11)
    //         004c9ca9     MOV        this,dword ptr [EAX + 0x1c8]
    //         004c9caf     CMP        word ptr [ECX + this+0x2],0x0
    //                              t_b_obj.cpp:1105 (2)
    //         004c9cb4     JG         LAB_004c9cf8
    //                              t_b_obj.cpp:1108 (14)
    //         004c9cb6     DEC        word ptr [EAX + 0x1ce]
    //         004c9cbd     MOV        DX,word ptr [EAX + 0x1ce]
    //                              t_b_obj.cpp:1109 (7)
    //         004c9cc4     XOR        this,this
    //         004c9cc6     TEST       DX,DX
    //         004c9cc9     JLE        LAB_004c9cf8
    //                               LAB_004c9ccb                                                 XREF[1]:     004c9cf6(j)  
    //                              t_b_obj.cpp:1111 (21)
    //         004c9ccb     MOV        EDX,dword ptr [EAX + 0x1c8]
    //         004c9cd1     MOV        SI,word ptr [EDX + this->_padding_*0x4 + 0x4]
    //         004c9cd6     MOV        word ptr [EDX + this->_padding_*0x4],SI
    //         004c9cda     MOV        EDX,dword ptr [EAX + 0x1c8]
    //                              t_b_obj.cpp:1112 (24)
    //         004c9ce0     MOV        SI,word ptr [EDX + this->_padding_*0x4 + 0x6]
    //         004c9ce5     LEA        EDX,[EDX + this->_padding_*0x4]
    //         004c9ce8     INC        this
    //         004c9ce9     MOV        word ptr [EDX + 0x2],SI
    //         004c9ced     MOVSX      EDX,word ptr [EAX + 0x1ce]
    //         004c9cf4     CMP        this,EDX
    //         004c9cf6     JL         LAB_004c9ccb
    //                               LAB_004c9cf8                                                 XREF[2]:     004c9cb4(j), 004c9cc9(j)  
    //                              t_b_obj.cpp:1114 (27)
    //         004c9cf8     MOV        EAX,dword ptr [EAX + 0xc]
    //         004c9cfb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9d01     PUSH       0x0
    //         004c9d03     PUSH       0x0
    //         004c9d05     MOVSX      EAX,word ptr [EAX + 0x4a]
    //         004c9d09     MOV        EDX,dword ptr [this->_padding_]
    //         004c9d0b     PUSH       0x0
    //         004c9d0d     PUSH       EAX
    //                              language.dll match for 0x7c: "B"
    //         004c9d0e     PUSH       0x7c
    //         004c9d10     CALL       dword ptr [EDX + 0x40]
    //                               LAB_004c9d13                                                 XREF[1]:     004c9c8b(j)  
    //                              t_b_obj.cpp:1115 (2)
    //         004c9d13     POP        ESI
    //         004c9d14     RET
    //         004c9d15     ??         90h
    //         004c9d16     NOP
    //         004c9d17     NOP
    //         004c9d18     NOP
    //         004c9d19     NOP
    //         004c9d1a     NOP
    //         004c9d1b     NOP
    //         004c9d1c     NOP
    //         004c9d1d     NOP
    //         004c9d1e     NOP
    //         004c9d1f     NOP
    return;
}

void TRIBE_Building_Object::empty_production_queue() {
    /* TODO: Stub */
    //                              void __thiscall empty_production_queue(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?empty_production_queue@TRIBE_Building_Object@@QAEXXZ        XREF[1]:     update:004c8b41(c)  
    //                               TRIBE_Building_Object::empty_production_queue
    //                              t_b_obj.cpp:1119 (3)
    //         004c9d20     PUSH       ESI
    //         004c9d21     MOV        ESI,this
    //                              t_b_obj.cpp:1120 (13)
    //         004c9d23     MOV        AX,word ptr [ESI + 0x1da]
    //         004c9d2a     CMP        AX,0xffff
    //         004c9d2e     JZ         LAB_004c9d5d
    //                              t_b_obj.cpp:1123 (6)
    //         004c9d30     CMP        AX,0x4
    //         004c9d34     JNZ        LAB_004c9d54
    //                              t_b_obj.cpp:1124 (30)
    //         004c9d36     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c9d39     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004c9d3f     MOVSX      this,word ptr [EAX + 0x4a]
    //         004c9d43     LEA        EAX,[EDX + this->_padding_*0x4 + 0xa34]
    //         004c9d4a     MOV        this,dword ptr [EDX + this->_padding_*0x4 + 0x
    //         004c9d51     DEC        this
    //         004c9d52     MOV        dword ptr [EAX],this
    //                               LAB_004c9d54                                                 XREF[1]:     004c9d34(j)  
    //                              t_b_obj.cpp:1125 (9)
    //         004c9d54     MOV        word ptr [ESI + 0x1da],0xffff
    //                               LAB_004c9d5d                                                 XREF[1]:     004c9d2e(j)  
    //                              t_b_obj.cpp:1129 (20)
    //         004c9d5d     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c9d63     MOV        word ptr [ESI + 0x1ce],0x0
    //         004c9d6c     CALL       RGE_Action_List::delete_list                     void delete_list(RGE_Action_List * this)
    //                              t_b_obj.cpp:1130 (14)
    //         004c9d71     MOV        AL,byte ptr [ESI + 0x1d8]
    //         004c9d77     INC        AL
    //         004c9d79     MOV        byte ptr [ESI + 0x1d8],AL
    //                              t_b_obj.cpp:1131 (2)
    //         004c9d7f     POP        ESI
    //         004c9d80     RET
    //         004c9d81     ??         90h
    //         004c9d82     NOP
    //         004c9d83     NOP
    //         004c9d84     NOP
    //         004c9d85     NOP
    //         004c9d86     NOP
    //         004c9d87     NOP
    //         004c9d88     NOP
    //         004c9d89     NOP
    //         004c9d8a     NOP
    //         004c9d8b     NOP
    //         004c9d8c     NOP
    //         004c9d8d     NOP
    //         004c9d8e     NOP
    //         004c9d8f     NOP
    return;
}

void TRIBE_Building_Object::enable_production_queue(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall enable_production_queue(TRIBE_Building_Object * this
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004c9d90(R)  
    //                               ?enable_production_queue@TRIBE_Building_Object@@QAEXH@Z
    //                               TRIBE_Building_Object::enable_production_queue
    //                              t_b_obj.cpp:1135 (10)
    //         004c9d90     MOV        AL,byte ptr [ESP + param_1]
    //         004c9d94     MOV        byte ptr [ECX + this->production_queue_enabled
    //                              t_b_obj.cpp:1137 (3)
    //         004c9d9a     RET        0x4
    //         004c9d9d     ??         90h
    //         004c9d9e     NOP
    //         004c9d9f     NOP
    return;
}

void TRIBE_Building_Object::update_production_queue() {
    /* TODO: Stub */
    //                              void __thiscall update_production_queue(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004c9f1a(W), 004c9f40(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004c9e32(R), 004c9fc1(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004c9f14(W)  
    //              undefined         Stack[-0x12]:1 local_12                  XREF[1]:     004c9de0(*)  
    //              undefined         Stack[-0x14]:1 local_14                  XREF[1]:     004c9dda(*)  
    //              short             Stack[-0x16]:2 work_target               XREF[2]:     004c9de5(*), 004c9df6(R)  
    //              short             Stack[-0x18]:2 progress
    //              short             Stack[-0x1a]:2 work_type
    //                               ?update_production_queue@TRIBE_Building_Object@@QAEXXZ       XREF[1]:     update:004c8b59(c)  
    //                               TRIBE_Building_Object::update_production_queue
    //                              t_b_obj.cpp:1141 (28)
    //         004c9da0     MOV        EAX,FS:[0x0]
    //         004c9da6     PUSH       -0x1
    //         004c9da8     PUSH       FUN_0055fafb
    //         004c9dad     PUSH       EAX
    //         004c9dae     MOV        dword ptr FS:[0x0],ESP
    //         004c9db5     SUB        ESP,0xc
    //         004c9db8     PUSH       ESI
    //         004c9db9     MOV        ESI,this
    //         004c9dbb     PUSH       EDI
    //                              t_b_obj.cpp:1142 (28)
    //         004c9dbc     MOV        AL,byte ptr [ESI + 0x1d0]
    //         004c9dc2     TEST       AL,AL
    //         004c9dc4     JZ         LAB_004c9f90
    //         004c9dca     CMP        word ptr [ESI + 0x1ce],0x0
    //         004c9dd2     JZ         LAB_004c9f90
    //                              t_b_obj.cpp:1154 (30)
    //         004c9dd8     PUSH       0x0
    //         004c9dda     LEA        EAX=>local_14,[ESP + 0x10]
    //         004c9dde     PUSH       0x0
    //         004c9de0     LEA        this=>local_12,[ESP + 0x16]
    //         004c9de4     PUSH       EAX
    //         004c9de5     LEA        EDX=>work_target,[ESP + 0x16]
    //         004c9de9     PUSH       this
    //         004c9dea     PUSH       EDX
    //         004c9deb     MOV        this,ESI
    //         004c9ded     CALL       TRIBE_Building_Object::work_status               int work_status(TRIBE_Building_Object * this,
    //         004c9df2     TEST       EAX,EAX
    //         004c9df4     JZ         LAB_004c9e43
    //                              t_b_obj.cpp:1155 (17)
    //         004c9df6     MOV        AX,word ptr [ESP + work_target]
    //         004c9dfb     CMP        AX,0x66
    //         004c9dff     JZ         LAB_004c9e07
    //         004c9e01     CMP        AX,0x67
    //         004c9e05     JNZ        LAB_004c9e43
    //                               LAB_004c9e07                                                 XREF[1]:     004c9dff(j)  
    //                              t_b_obj.cpp:1157 (14)
    //         004c9e07     CMP        word ptr [ESI + 0x1ce],0x0
    //         004c9e0f     JLE        LAB_004c9fc1
    //                               LAB_004c9e15                                                 XREF[1]:     004c9e30(j)  
    //                              t_b_obj.cpp:1158 (29)
    //         004c9e15     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004c9e1b     PUSH       -0x1
    //         004c9e1d     MOV        this,word ptr [EAX]
    //         004c9e20     PUSH       this
    //         004c9e21     MOV        this,ESI
    //         004c9e23     CALL       TRIBE_Building_Object::remove_from_production_   void remove_from_production_queue(TRIBE_Build
    //         004c9e28     CMP        word ptr [ESI + 0x1ce],0x0
    //         004c9e30     JG         LAB_004c9e15
    //                              t_b_obj.cpp:1260 (17)
    //         004c9e32     MOV        this,dword ptr [ESP + local_c]
    //         004c9e36     MOV        dword ptr FS:[0x0],this
    //         004c9e3d     POP        EDI
    //         004c9e3e     POP        ESI
    //         004c9e3f     ADD        ESP,0x18
    //         004c9e42     RET
    //                               LAB_004c9e43                                                 XREF[2]:     004c9df4(j), 004c9e05(j)  
    //                              t_b_obj.cpp:1163 (17)
    //         004c9e43     MOV        EDX,dword ptr [ESI + 0x1d4]
    //         004c9e49     MOV        EAX,dword ptr [EDX + 0x8]
    //         004c9e4c     TEST       EAX,EAX
    //         004c9e4e     JNZ        LAB_004c9f56
    //                              t_b_obj.cpp:1166 (22)
    //         004c9e54     MOV        EDX,dword ptr [ESI + 0xc]
    //         004c9e57     MOV        this,dword ptr [EDX + 0x50]
    //         004c9e5a     FLD        float ptr [ECX + this->_padding_]
    //         004c9e5d     FCOMP      float ptr [ECX + this->_padding_]
    //         004c9e63     FNSTSW     AX
    //         004c9e65     TEST       AH,0x1
    //         004c9e68     JNZ        LAB_004c9ec8
    //                              t_b_obj.cpp:1168 (18)
    //         004c9e6a     MOV        EAX,0x20
    //         004c9e6f     CMP        word ptr [ESI + 0x1da],AX
    //         004c9e76     JZ         LAB_004c9fc1
    //                              t_b_obj.cpp:1171 (30)
    //         004c9e7c     PUSH       0x0
    //         004c9e7e     PUSH       0x0
    //         004c9e80     MOV        word ptr [ESI + 0x1da],AX
    //         004c9e87     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9e8d     PUSH       EAX
    //         004c9e8e     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         004c9e92     MOV        EDI,dword ptr [this->_padding_]
    //         004c9e94     PUSH       EAX
    //                              language.dll match for 0x7d: "Arial"
    //         004c9e95     PUSH       0x7d
    //         004c9e97     CALL       dword ptr [EDI + 0x40]
    //                              t_b_obj.cpp:1172 (29)
    //         004c9e9a     MOV        this,dword ptr [ESI + 0xc]
    //         004c9e9d     MOV        EAX,[rge_base_game]                              = 00000000
    //         004c9ea2     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004c9ea6     MOV        this,dword ptr [EAX + EDX*0x4 + 0xa34]
    //         004c9ead     LEA        EAX,[EAX + EDX*0x4 + 0xa34]
    //         004c9eb4     INC        this
    //         004c9eb5     MOV        dword ptr [EAX],this
    //                              t_b_obj.cpp:1260 (17)
    //         004c9eb7     MOV        this,dword ptr [ESP + 0x14]
    //         004c9ebb     MOV        dword ptr FS:[0x0],this
    //         004c9ec2     POP        EDI
    //         004c9ec3     POP        ESI
    //         004c9ec4     ADD        ESP,0x18
    //         004c9ec7     RET
    //                               LAB_004c9ec8                                                 XREF[1]:     004c9e68(j)  
    //                              t_b_obj.cpp:1177 (20)
    //         004c9ec8     FLD        float ptr [ECX + this->_padding_]
    //         004c9ecb     FCOMP      float ptr [DAT_005749f4]
    //         004c9ed1     FNSTSW     AX
    //         004c9ed3     TEST       AH,0x41
    //         004c9ed6     JNZ        LAB_004c9fd2
    //                              t_b_obj.cpp:1188 (10)
    //         004c9edc     CMP        word ptr [ESI + 0x1da],0x4
    //         004c9ee4     JNZ        LAB_004c9f01
    //                              t_b_obj.cpp:1189 (27)
    //         004c9ee6     MOVSX      this,word ptr [EDX + 0x4a]
    //         004c9eea     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004c9ef0     LEA        EAX,[EDX + this->_padding_*0x4 + 0xa34]
    //         004c9ef7     MOV        this,dword ptr [EDX + this->_padding_*0x4 + 0x
    //         004c9efe     DEC        this
    //         004c9eff     MOV        dword ptr [EAX],this
    //                               LAB_004c9f01                                                 XREF[1]:     004c9ee4(j)  
    //                              t_b_obj.cpp:1193 (61)
    //         004c9f01     PUSH       0x50
    //         004c9f03     MOV        word ptr [ESI + 0x1da],0xffff
    //         004c9f0c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004c9f11     ADD        ESP,0x4
    //         004c9f14     MOV        dword ptr [ESP + local_10],EAX
    //         004c9f18     TEST       EAX,EAX
    //         004c9f1a     MOV        dword ptr [ESP + local_4],0x0
    //         004c9f22     JZ         LAB_004c9f3c
    //         004c9f24     MOV        this,dword ptr [ESI + 0x1c8]
    //         004c9f2a     PUSH       0x1
    //         004c9f2c     PUSH       -0x1
    //         004c9f2e     MOV        DX,word ptr [this->_padding_]
    //         004c9f31     MOV        this,EAX
    //         004c9f33     PUSH       EDX
    //         004c9f34     PUSH       ESI
    //         004c9f35     CALL       TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj     undefined TRIBE_Action_Make_Obj(TRIBE_Action_
    //         004c9f3a     JMP        LAB_004c9f3e
    //                               LAB_004c9f3c                                                 XREF[1]:     004c9f22(j)  
    //         004c9f3c     XOR        EAX,EAX
    //                               LAB_004c9f3e                                                 XREF[1]:     004c9f3a(j)  
    //                              t_b_obj.cpp:1194 (12)
    //         004c9f3e     TEST       EAX,EAX
    //         004c9f40     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004c9f48     JZ         LAB_004c9f56
    //                              t_b_obj.cpp:1195 (12)
    //         004c9f4a     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c9f50     PUSH       EAX
    //         004c9f51     CALL       RGE_Action_List::add_action                      void add_action(RGE_Action_List * this, RGE_A
    //                               LAB_004c9f56                                                 XREF[2]:     004c9e4e(j), 004c9f48(j)  
    //                              t_b_obj.cpp:1199 (11)
    //         004c9f56     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c9f5c     MOV        EDX,dword ptr [this->_padding_]
    //         004c9f5e     CALL       dword ptr [EDX + 0xc]
    //                              t_b_obj.cpp:1202 (12)
    //         004c9f61     CMP        AL,0x3
    //         004c9f63     JZ         LAB_004c9f6d
    //         004c9f65     CMP        AL,0x2
    //         004c9f67     JZ         LAB_004c9f6d
    //         004c9f69     CMP        AL,0x1
    //         004c9f6b     JNZ        LAB_004c9fc1
    //                               LAB_004c9f6d                                                 XREF[2]:     004c9f63(j), 004c9f67(j)  
    //                              t_b_obj.cpp:1204 (11)
    //         004c9f6d     MOV        this,dword ptr [ESI + 0x1d4]
    //         004c9f73     CALL       RGE_Action_List::remove_action                   void remove_action(RGE_Action_List * this)
    //                              t_b_obj.cpp:1205 (7)
    //         004c9f78     MOV        this,ESI
    //         004c9f7a     CALL       TRIBE_Building_Object::advance_production_queue  void advance_production_queue(TRIBE_Building_
    //                              t_b_obj.cpp:1260 (17)
    //         004c9f7f     MOV        this,dword ptr [ESP + 0x14]
    //         004c9f83     MOV        dword ptr FS:[0x0],this
    //         004c9f8a     POP        EDI
    //         004c9f8b     POP        ESI
    //         004c9f8c     ADD        ESP,0x18
    //         004c9f8f     RET
    //                               LAB_004c9f90                                                 XREF[2]:     004c9dc4(j), 004c9dd2(j)  
    //                              t_b_obj.cpp:1144 (10)
    //         004c9f90     CMP        word ptr [ESI + 0x1da],0x4
    //         004c9f98     JNZ        LAB_004c9fc1
    //                              t_b_obj.cpp:1147 (39)
    //         004c9f9a     MOV        EAX,dword ptr [ESI + 0xc]
    //         004c9f9d     MOV        word ptr [ESI + 0x1da],0xffff
    //         004c9fa6     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004c9fac     MOVSX      this,word ptr [EAX + 0x4a]
    //         004c9fb0     LEA        EAX,[EDX + this->_padding_*0x4 + 0xa34]
    //         004c9fb7     MOV        this,dword ptr [EDX + this->_padding_*0x4 + 0x
    //         004c9fbe     DEC        this
    //         004c9fbf     MOV        dword ptr [EAX],this
    //                               LAB_004c9fc1                                                 XREF[5]:     004c9e0f(j), 004c9e76(j), 
    //                                                                                                         004c9f6b(j), 004c9f98(j), 
    //                                                                                                         004c9fde(j)  
    //                              t_b_obj.cpp:1260 (17)
    //         004c9fc1     MOV        this,dword ptr [ESP + local_c]
    //         004c9fc5     MOV        dword ptr FS:[0x0],this
    //         004c9fcc     POP        EDI
    //         004c9fcd     POP        ESI
    //         004c9fce     ADD        ESP,0x18
    //         004c9fd1     RET
    //                               LAB_004c9fd2                                                 XREF[1]:     004c9ed6(j)  
    //                              t_b_obj.cpp:1179 (14)
    //         004c9fd2     MOV        EAX,0x4
    //         004c9fd7     CMP        word ptr [ESI + 0x1da],AX
    //         004c9fde     JZ         LAB_004c9fc1
    //                              t_b_obj.cpp:1182 (30)
    //         004c9fe0     PUSH       0x0
    //         004c9fe2     PUSH       0x0
    //         004c9fe4     MOV        word ptr [ESI + 0x1da],AX
    //         004c9feb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004c9ff1     PUSH       EAX
    //         004c9ff2     MOVSX      EAX,word ptr [EDX + 0x4a]
    //         004c9ff6     MOV        EDI,dword ptr [this->_padding_]
    //         004c9ff8     PUSH       EAX
    //                              language.dll match for 0x7d: "Arial"
    //         004c9ff9     PUSH       0x7d
    //         004c9ffb     CALL       dword ptr [EDI + 0x40]
    //                              t_b_obj.cpp:1183 (8)
    //         004c9ffe     MOV        this,dword ptr [ESI + 0xc]
    //         004ca001     MOV        EAX,[rge_base_game]                              = 00000000
    //                              t_b_obj.cpp:1260 (38)
    //         004ca006     POP        EDI
    //         004ca007     POP        ESI
    //         004ca008     MOVSX      EDX,word ptr [ECX + this+0x4a]
    //         004ca00c     MOV        this,dword ptr [EAX + EDX*0x4 + 0xa34]
    //         004ca013     LEA        EAX,[EAX + EDX*0x4 + 0xa34]
    //         004ca01a     INC        this
    //         004ca01b     MOV        dword ptr [EAX],this
    //         004ca01d     MOV        this,dword ptr [ESP + 0xc]
    //         004ca021     MOV        dword ptr FS:[0x0],this
    //         004ca028     ADD        ESP,0x18
    //         004ca02b     RET
    //         004ca02c     ??         90h
    //         004ca02d     NOP
    //         004ca02e     NOP
    //         004ca02f     NOP
    return;
}

int TRIBE_Building_Object::production_queue_status(short* param_1, short* param_2) {
    /* TODO: Stub */
    //                              int __thiscall production_queue_status(TRIBE_Building_Object * this,
    //              int               EAX:4          <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //              short *           Stack[0x4]:4   param_1                   XREF[1]:     004ca037(R)  
    //              short *           Stack[0x8]:4   param_2                   XREF[1]:     004ca031(R)  
    //                               ?production_queue_status@TRIBE_Building_Object@@QAEHAAF0@Z   XREF[3]:     draw:0051b772(c), 
    //                               TRIBE_Building_Object::production_queue_status                            handle_idle:0051c847(c), 
    //                                                                                                         save_object_info:0051cbf4(c)  
    //                              t_b_obj.cpp:1264 (1)
    //         004ca030     PUSH       EBX
    //                              t_b_obj.cpp:1268 (22)
    //         004ca031     MOV        EBX,dword ptr [ESP + param_2]
    //         004ca035     PUSH       ESI
    //         004ca036     PUSH       EDI
    //         004ca037     MOV        EDI,dword ptr [ESP + param_1]
    //         004ca03b     MOV        ESI,this
    //         004ca03d     MOV        word ptr [EDI],0xffff
    //         004ca042     MOV        word ptr [EBX],0x0
    //                              t_b_obj.cpp:1270 (11)
    //         004ca047     MOV        this,dword ptr [ESI + 0x1d4]
    //         004ca04d     CALL       RGE_Action_List::get_action                      RGE_Action * get_action(RGE_Action_List * this)
    //                              t_b_obj.cpp:1271 (11)
    //         004ca052     TEST       EAX,EAX
    //         004ca054     JZ         LAB_004ca075
    //         004ca056     CMP        word ptr [EAX + 0x4],0x66
    //         004ca05b     JNZ        LAB_004ca075
    //                              t_b_obj.cpp:1273 (13)
    //         004ca05d     PUSH       0x0
    //         004ca05f     PUSH       0x0
    //         004ca061     PUSH       EBX
    //         004ca062     PUSH       EDI
    //         004ca063     MOV        this,EAX
    //         004ca065     CALL       TRIBE_Action_Make_Obj::get_info                  void get_info(TRIBE_Action_Make_Obj * this, s
    //                              t_b_obj.cpp:1274 (5)
    //         004ca06a     MOV        EAX,0x1
    //                              t_b_obj.cpp:1285 (6)
    //         004ca06f     POP        EDI
    //         004ca070     POP        ESI
    //         004ca071     POP        EBX
    //         004ca072     RET        0x8
    //                               LAB_004ca075                                                 XREF[2]:     004ca054(j), 004ca05b(j)  
    //                              t_b_obj.cpp:1277 (10)
    //         004ca075     CMP        word ptr [ESI + 0x1ce],0x0
    //         004ca07d     JLE        LAB_004ca09b
    //                              t_b_obj.cpp:1279 (9)
    //         004ca07f     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004ca085     MOV        this,word ptr [EAX]
    //                              t_b_obj.cpp:1281 (13)
    //         004ca088     MOV        EAX,0x1
    //         004ca08d     MOV        word ptr [EDI],this
    //         004ca090     MOV        word ptr [EBX],0x0
    //                              t_b_obj.cpp:1285 (14)
    //         004ca095     POP        EDI
    //         004ca096     POP        ESI
    //         004ca097     POP        EBX
    //         004ca098     RET        0x8
    //                               LAB_004ca09b                                                 XREF[1]:     004ca07d(j)  
    //         004ca09b     POP        EDI
    //         004ca09c     POP        ESI
    //         004ca09d     XOR        EAX,EAX
    //         004ca09f     POP        EBX
    //         004ca0a0     RET        0x8
    //         004ca0a3     ??         90h
    //         004ca0a4     NOP
    //         004ca0a5     NOP
    //         004ca0a6     NOP
    //         004ca0a7     NOP
    //         004ca0a8     NOP
    //         004ca0a9     NOP
    //         004ca0aa     NOP
    //         004ca0ab     NOP
    //         004ca0ac     NOP
    //         004ca0ad     NOP
    //         004ca0ae     NOP
    //         004ca0af     NOP
    return 0;
}

void TRIBE_Building_Object::stop() {
    /* TODO: Stub */
    //                              void __thiscall stop(TRIBE_Building_Object * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Building    ECX:4 (auto)   this
    //                               ?stop@TRIBE_Building_Object@@UAEXXZ                          XREF[1]:     0057481c(*)  
    //                               TRIBE_Building_Object::stop
    //                              t_b_obj.cpp:1290 (3)
    //         004ca0b0     PUSH       ESI
    //         004ca0b1     MOV        ESI,this
    //                              t_b_obj.cpp:1291 (5)
    //         004ca0b3     CALL       RGE_Combat_Object::stop                          void stop(RGE_Combat_Object * this)
    //                              t_b_obj.cpp:1293 (10)
    //         004ca0b8     CMP        word ptr [ESI + 0x1ce],0x0
    //         004ca0c0     JLE        LAB_004ca0df
    //                               LAB_004ca0c2                                                 XREF[1]:     004ca0dd(j)  
    //                              t_b_obj.cpp:1294 (29)
    //         004ca0c2     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004ca0c8     PUSH       0x1
    //         004ca0ca     MOV        this,word ptr [EAX]
    //         004ca0cd     PUSH       this
    //         004ca0ce     MOV        this,ESI
    //         004ca0d0     CALL       TRIBE_Building_Object::remove_from_production_   void remove_from_production_queue(TRIBE_Build
    //         004ca0d5     CMP        word ptr [ESI + 0x1ce],0x0
    //         004ca0dd     JG         LAB_004ca0c2
    //                               LAB_004ca0df                                                 XREF[1]:     004ca0c0(j)  
    //                              t_b_obj.cpp:1295 (2)
    //         004ca0df     POP        ESI
    //         004ca0e0     RET
    //         004ca0e1     ??         90h
    //         004ca0e2     NOP
    //         004ca0e3     NOP
    //         004ca0e4     NOP
    //         004ca0e5     NOP
    //         004ca0e6     NOP
    //         004ca0e7     NOP
    //         004ca0e8     NOP
    //         004ca0e9     NOP
    //         004ca0ea     NOP
    //         004ca0eb     NOP
    //         004ca0ec     NOP
    //         004ca0ed     NOP
    //         004ca0ee     NOP
    //         004ca0ef     NOP
    //                              * public: __thiscall TRIBE_Combat_Object::TRIBE_Combat_Object(class TRIBE_Master_Combat_Object *,cla... *
    //                              undefined __thiscall TRIBE_Combat_Object(TRIBE_Combat_Object * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Combat_O    ECX:4 (auto)   this
    //              TRIBE_Master_C    Stack[0x4]:4   param_1                   XREF[2]:     004ca11e(R), 004ca14c(R)  
    //              RGE_Player *      Stack[0x8]:4   param_2                   XREF[2]:     004ca106(R), 004ca148(R)  
    //              float             Stack[0xc]:4   param_3                   XREF[1]:     004ca110(R)  
    //              float             Stack[0x10]:4  param_4                   XREF[1]:     004ca10b(R)  
    //              float             Stack[0x14]:4  param_5                   XREF[1]:     004ca116(R)  
    //              int               Stack[0x18]:4  param_6                   XREF[1]:     004ca132(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004ca136(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004ca15c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004ca129(W)  
    //                               ??0TRIBE_Combat_Object@@QAE@PAVTRIBE_Master_Combat_Object@@  XREF[3]:     TRIBE_Building_Object:004c7f8e(c), 
    //                               TRIBE_Combat_Object::TRIBE_Combat_Object                                  TRIBE_Building_Object:004c80ee(c), 
    //                                                                                                         make_new_obj:0050f0df(c)  
    //                              t_c_obj.cpp:61 (66)
    //         004ca0f0     PUSH       -0x1
    //         004ca0f2     PUSH       FUN_0055fb18
    //         004ca0f7     MOV        EAX,FS:[0x0]
    //         004ca0fd     PUSH       EAX
    //         004ca0fe     MOV        dword ptr FS:[0x0],ESP
    //         004ca105     PUSH       this
    //         004ca106     MOV        EAX,dword ptr [ESP + param_2]
    //         004ca10a     PUSH       EBX
    //         004ca10b     MOV        EBX,dword ptr [ESP + param_4]
    //         004ca10f     PUSH       EBP
    //         004ca110     MOV        EBP,dword ptr [ESP + param_3]
    //         004ca114     PUSH       ESI
    //         004ca115     PUSH       EDI
    //         004ca116     MOV        EDI,dword ptr [ESP + param_5]
    //         004ca11a     PUSH       0x0
    //         004ca11c     MOV        ESI,this
    //         004ca11e     MOV        this,dword ptr [ESP + param_1]
    //         004ca122     PUSH       EDI
    //         004ca123     PUSH       EBX
    //         004ca124     PUSH       EBP
    //         004ca125     PUSH       EAX
    //         004ca126     PUSH       this
    //         004ca127     MOV        this,ESI
    //         004ca129     MOV        dword ptr [ESP + local_10],ESI
    //         004ca12d     CALL       RGE_Combat_Object::RGE_Combat_Object             undefined RGE_Combat_Object(RGE_Combat_Object
    //                              t_c_obj.cpp:62 (22)
    //         004ca132     MOV        EAX,dword ptr [ESP + param_6]
    //         004ca136     MOV        dword ptr [ESP + local_4],0x0
    //         004ca13e     TEST       EAX,EAX
    //         004ca140     MOV        dword ptr [ESI],TRIBE_Combat_Object::`vftable'   = 004ca180
    //         004ca146     JZ         LAB_004ca15c
    //                              t_c_obj.cpp:63 (20)
    //         004ca148     MOV        EDX,dword ptr [ESP + param_2]
    //         004ca14c     MOV        EAX,dword ptr [ESP + param_1]
    //         004ca150     PUSH       EDI
    //         004ca151     PUSH       EBX
    //         004ca152     PUSH       EBP
    //         004ca153     PUSH       EDX
    //         004ca154     PUSH       EAX
    //         004ca155     MOV        this,ESI
    //         004ca157     CALL       TRIBE_Combat_Object::setup                       int setup(TRIBE_Combat_Object * this, TRIBE_M
    //                               LAB_004ca15c                                                 XREF[1]:     004ca146(j)  
    //                              t_c_obj.cpp:64 (23)
    //         004ca15c     MOV        this,dword ptr [ESP + local_c]
    //         004ca160     MOV        EAX,ESI
    //         004ca162     POP        EDI
    //         004ca163     POP        ESI
    //         004ca164     POP        EBP
    //         004ca165     MOV        dword ptr FS:[0x0],this
    //         004ca16c     POP        EBX
    //         004ca16d     ADD        ESP,0x10
    //         004ca170     RET        0x18
    //         004ca173     ??         90h
    //         004ca174     NOP
    //         004ca175     NOP
    //         004ca176     NOP
    //         004ca177     NOP
    //         004ca178     NOP
    //         004ca179     NOP
    //         004ca17a     NOP
    //         004ca17b     NOP
    //         004ca17c     NOP
    //         004ca17d     NOP
    //         004ca17e     NOP
    //         004ca17f     NOP
    return;
}

int TRIBE_Building_Object::explore_terrain(RGE_Player* param_1, uchar param_2, int param_3) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

void TRIBE_Building_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return;
}

