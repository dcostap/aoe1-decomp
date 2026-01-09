#include "common.h"
#include "scr_sedm.h"

TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu() {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_Menu * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b2f47(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004b2f7c(R), 004b30d3(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b2f11(W)  
    //                               ??0TRIBE_Screen_Sed_Menu@@QAE@XZ                             XREF[3]:     action:004908cd(c), 
    //                               TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu                              action:0049f05b(c), 
    //                                                                                                         action:004b3c20(c)  
    //                              scr_sedm.cpp:41 (48)
    //         004b2ef0     PUSH       -0x1
    //         004b2ef2     PUSH       FUN_0055f568
    //         004b2ef7     MOV        EAX,FS:[0x0]
    //         004b2efd     PUSH       EAX
    //         004b2efe     MOV        dword ptr FS:[0x0],ESP
    //         004b2f05     PUSH       this
    //         004b2f06     PUSH       EBX
    //         004b2f07     PUSH       EBP
    //         004b2f08     PUSH       ESI
    //         004b2f09     PUSH       EDI
    //         004b2f0a     MOV        ESI,this
    //         004b2f0c     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
    //         004b2f11     MOV        dword ptr [ESP + local_10],ESI
    //         004b2f15     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //         004b2f1a     LEA        EBP,[ESI + 0x47c]
    //                              scr_sedm.cpp:46 (6)
    //         004b2f20     LEA        EDI,[ESI + 0x478]
    //                              scr_sedm.cpp:48 (18)
    //         004b2f26     MOV        this,EBP
    //         004b2f28     XOR        EAX,EAX
    //         004b2f2a     MOV        dword ptr [ESI],TRIBE_Screen_Sed_Menu::`vftable' = 004b30f0
    //         004b2f30     MOV        dword ptr [EDI],0x0
    //         004b2f36     MOV        dword ptr [this->_padding_],EAX
    //                              scr_sedm.cpp:53 (56)
    //         004b2f38     PUSH       0x1
    //         004b2f3a     PUSH       0xc386
    //         004b2f3f     PUSH       s_scr4                                           = "scr4"
    //         004b2f44     MOV        dword ptr [ECX + this->_padding_],EAX
    //         004b2f47     MOV        dword ptr [ESP + local_4],0x0
    //         004b2f4f     MOV        dword ptr [ECX + this->_padding_],EAX
    //         004b2f52     MOV        dword ptr [ECX + this->_padding_],EAX
    //         004b2f55     MOV        dword ptr [ESI + 0x48c],EAX
    //         004b2f5b     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         004b2f61     MOV        this,ESI
    //         004b2f63     MOV        EAX,dword ptr [EDX + 0x4c]
    //         004b2f66     PUSH       EAX
    //         004b2f67     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004b2f6c     TEST       EAX,EAX
    //         004b2f6e     JNZ        LAB_004b2f8f
    //                              scr_sedm.cpp:55 (10)
    //         004b2f70     MOV        dword ptr [ESI + 0xd8],0x1
    //                              scr_sedm.cpp:86 (21)
    //         004b2f7a     MOV        EAX,ESI
    //         004b2f7c     MOV        this,dword ptr [ESP + local_c]
    //         004b2f80     MOV        dword ptr FS:[0x0],this
    //         004b2f87     POP        EDI
    //         004b2f88     POP        ESI
    //         004b2f89     POP        EBP
    //         004b2f8a     POP        EBX
    //         004b2f8b     ADD        ESP,0x10
    //         004b2f8e     RET
    //                               LAB_004b2f8f                                                 XREF[1]:     004b2f6e(j)  
    //                              scr_sedm.cpp:59 (17)
    //         004b2f8f     PUSH       0x1e0
    //         004b2f94     PUSH       0x280
    //         004b2f99     MOV        this,ESI
    //         004b2f9b     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_sedm.cpp:62 (41)
    //         004b2fa0     PUSH       0x0
    //         004b2fa2     PUSH       0x0
    //         004b2fa4     PUSH       0x1
    //         004b2fa6     PUSH       0x1
    //         004b2fa8     PUSH       0x1e
    //         004b2faa     PUSH       0x258
    //         004b2faf     PUSH       0x14
    //         004b2fb1     PUSH       0x14
    //                              language.dll match for 0x242d: "Scenario Builder"
    //         004b2fb3     PUSH       0x242d
    //         004b2fb8     PUSH       EDI
    //         004b2fb9     PUSH       ESI
    //         004b2fba     MOV        this,ESI
    //         004b2fbc     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b2fc1     TEST       EAX,EAX
    //         004b2fc3     JZ         LAB_004b30d3
    //                              scr_sedm.cpp:65 (7)
    //         004b2fc9     MOV        EDI,0xaa
    //         004b2fce     MOV        EBX,EBP
    //                               LAB_004b2fd0                                                 XREF[1]:     004b3007(j)  
    //                              scr_sedm.cpp:66 (57)
    //         004b2fd0     PUSH       0x0
    //         004b2fd2     PUSH       0x0
    //         004b2fd4     PUSH       0x0
    //         004b2fd6     PUSH       0x28
    //         004b2fd8     PUSH       0x12c
    //         004b2fdd     PUSH       EDI
    //         004b2fde     PUSH       0xaa
    //         004b2fe3     PUSH       0x0
    //         004b2fe5     PUSH       s_                                               = ""
    //         004b2fea     PUSH       EBX
    //         004b2feb     PUSH       ESI
    //         004b2fec     MOV        this,ESI
    //         004b2fee     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b2ff3     TEST       EAX,EAX
    //         004b2ff5     JZ         LAB_004b30d3
    //         004b2ffb     ADD        EDI,0x32
    //         004b2ffe     ADD        EBX,0x4
    //         004b3001     CMP        EDI,0x172
    //         004b3007     JL         LAB_004b2fd0
    //                              scr_sedm.cpp:70 (44)
    //         004b3009     PUSH       0x0
    //         004b300b     PUSH       -0x1
    //         004b300d     PUSH       -0x1
    //         004b300f     PUSH       0x0
    //         004b3011     PUSH       0x0
    //         004b3013     PUSH       0x0
    //         004b3015     PUSH       0x0
    //         004b3017     PUSH       0x0
    //         004b3019     LEA        EDI,[ESI + 0x48c]
    //                              language.dll match for 0x3ea: "X"
    //         004b301f     PUSH       0x3ea
    //         004b3024     PUSH       EDI
    //         004b3025     PUSH       ESI
    //         004b3026     MOV        this,ESI
    //         004b3028     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b302d     TEST       EAX,EAX
    //         004b302f     JZ         LAB_004b30d3
    //                              scr_sedm.cpp:71 (9)
    //         004b3035     MOV        this,dword ptr [EDI]
    //         004b3037     PUSH       0x1
    //         004b3039     MOV        EDX,dword ptr [this->_padding_]
    //         004b303b     CALL       dword ptr [EDX + 0x14]
    //                              scr_sedm.cpp:72 (33)
    //         004b303e     MOV        this,dword ptr [EDI]
    //         004b3040     PUSH       0x0
    //         004b3042     PUSH       0x0=>DAT_fffffff8
    //         004b3044     PUSH       0x0=>DAT_fffffff4
    //         004b3046     MOV        EAX,dword ptr [this->_padding_]
    //         004b3048     PUSH       0x0=>DAT_fffffff0
    //         004b304a     PUSH       0x11
    //         004b304c     PUSH       0x11
    //         004b304e     PUSH       0x11
    //         004b3050     PUSH       0x11
    //         004b3052     PUSH       0x4
    //         004b3054     PUSH       0x4
    //         004b3056     PUSH       0x4
    //         004b3058     PUSH       0x4
    //         004b305a     PUSH       0x9
    //         004b305c     CALL       dword ptr [EAX + 0x18]
    //                              scr_sedm.cpp:74 (15)
    //         004b305f     MOV        this,dword ptr [EBP]
    //                              language.dll match for 0x242e: "Create Scenario"
    //         004b3062     PUSH       0x242e
    //         004b3067     PUSH       0x0=>DAT_fffffff8
    //         004b3069     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              scr_sedm.cpp:75 (18)
    //         004b306e     MOV        this,dword ptr [ESI + 0x480]
    //                              language.dll match for 0x242f: "Edit Scenario"
    //         004b3074     PUSH       0x242f
    //         004b3079     PUSH       0x0=>DAT_fffffff8
    //         004b307b     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              scr_sedm.cpp:76 (18)
    //         004b3080     MOV        this,dword ptr [ESI + 0x484]
    //                              language.dll match for 0x2431: "Campaign Editor"
    //         004b3086     PUSH       0x2431
    //         004b308b     PUSH       0x0=>DAT_fffffff8
    //         004b308d     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              scr_sedm.cpp:77 (18)
    //         004b3092     MOV        this,dword ptr [ESI + 0x488]
    //                              language.dll match for 0x2430: "Cancel"
    //         004b3098     PUSH       0x2430
    //         004b309d     PUSH       0x0=>DAT_fffffff8
    //         004b309f     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              scr_sedm.cpp:79 (6)
    //         004b30a4     MOV        EAX,dword ptr [ESI + 0x488]
    //                              scr_sedm.cpp:82 (30)
    //         004b30aa     PUSH       0x4
    //         004b30ac     PUSH       EBP=>DAT_fffffff8
    //         004b30ad     MOV        this,ESI
    //         004b30af     MOV        dword ptr [EAX + 0x298],0x1b
    //         004b30b9     MOV        dword ptr [EAX + 0x29c],0x0
    //         004b30c3     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              scr_sedm.cpp:85 (11)
    //         004b30c8     MOV        this,dword ptr [EBP]
    //         004b30cb     PUSH       this
    //         004b30cc     MOV        this,ESI
    //         004b30ce     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b30d3                                                 XREF[3]:     004b2fc3(j), 004b2ff5(j), 
    //                                                                                                         004b302f(j)  
    //                              scr_sedm.cpp:86 (21)
    //         004b30d3     MOV        this,dword ptr [ESP + local_c]
    //         004b30d7     MOV        EAX,ESI
    //         004b30d9     POP        EDI
    //         004b30da     POP        ESI
    //         004b30db     POP        EBP
    //         004b30dc     MOV        dword ptr FS:[0x0],this
    //         004b30e3     POP        EBX
    //         004b30e4     ADD        ESP,0x10
    //         004b30e7     RET
    //         004b30e8     ??         90h
    //         004b30e9     NOP
    //         004b30ea     NOP
    //         004b30eb     NOP
    //         004b30ec     NOP
    //         004b30ed     NOP
    //         004b30ee     NOP
    //         004b30ef     NOP
}

TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_Menu * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b313b(W), 004b3172(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b317f(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b312b(W)  
    //                               ??1TRIBE_Screen_Sed_Menu@@UAE@XZ                             XREF[1]:     `scalar_deleting_destructor':004b3
    //                               TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu
    //                              scr_sedm.cpp:91 (37)
    //         004b3110     PUSH       -0x1
    //         004b3112     PUSH       FUN_0055f588
    //         004b3117     MOV        EAX,FS:[0x0]
    //         004b311d     PUSH       EAX
    //         004b311e     MOV        dword ptr FS:[0x0],ESP
    //         004b3125     PUSH       this
    //         004b3126     PUSH       EBX
    //         004b3127     PUSH       ESI
    //         004b3128     MOV        ESI,this
    //         004b312a     PUSH       EDI
    //         004b312b     MOV        dword ptr [ESP + local_10],ESI
    //         004b312f     MOV        dword ptr [ESI],TRIBE_Screen_Sed_Menu::`vftable' = 004b30f0
    //                              scr_sedm.cpp:92 (31)
    //         004b3135     LEA        EAX,[ESI + 0x478]
    //         004b313b     MOV        dword ptr [ESP + local_4],0x0
    //         004b3143     PUSH       EAX
    //         004b3144     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b3149     LEA        EDI,[ESI + 0x47c]
    //         004b314f     MOV        EBX,0x4
    //                               LAB_004b3154                                                 XREF[1]:     004b3160(j)  
    //                              scr_sedm.cpp:94 (14)
    //         004b3154     PUSH       EDI
    //         004b3155     MOV        this,ESI
    //         004b3157     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b315c     ADD        EDI,0x4
    //         004b315f     DEC        EBX
    //         004b3160     JNZ        LAB_004b3154
    //                              scr_sedm.cpp:96 (16)
    //         004b3162     LEA        this,[ESI + 0x48c]
    //         004b3168     PUSH       this
    //         004b3169     MOV        this,ESI
    //         004b316b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b3170     MOV        this,ESI
    //                              scr_sedm.cpp:97 (31)
    //         004b3172     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b317a     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004b317f     MOV        this,dword ptr [ESP + local_c]
    //         004b3183     POP        EDI
    //         004b3184     POP        ESI
    //         004b3185     MOV        dword ptr FS:[0x0],this
    //         004b318c     POP        EBX
    //         004b318d     ADD        ESP,0x10
    //         004b3190     RET
    //         004b3191     ??         90h
    //         004b3192     NOP
    //         004b3193     NOP
    //         004b3194     NOP
    //         004b3195     NOP
    //         004b3196     NOP
    //         004b3197     NOP
    //         004b3198     NOP
    //         004b3199     NOP
    //         004b319a     NOP
    //         004b319b     NOP
    //         004b319c     NOP
    //         004b319d     NOP
    //         004b319e     NOP
    //         004b319f     NOP
}

long TRIBE_Screen_Sed_Menu::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TRIBE_Screen_Sed_Menu * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //                               ?handle_idle@TRIBE_Screen_Sed_Menu@@MAEJXZ                   XREF[1]:     00573b4c(*)  
    //                               TRIBE_Screen_Sed_Menu::handle_idle
    //                              scr_sedm.cpp:103 (3)
    //         004b31a0     PUSH       ESI
    //         004b31a1     MOV        ESI,this
    //                              scr_sedm.cpp:104 (16)
    //         004b31a3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b31a9     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004b31af     TEST       EAX,EAX
    //         004b31b1     JNZ        LAB_004b31b8
    //                              scr_sedm.cpp:105 (5)
    //         004b31b3     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_004b31b8                                                 XREF[1]:     004b31b1(j)  
    //                              scr_sedm.cpp:107 (7)
    //         004b31b8     MOV        this,ESI
    //         004b31ba     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_sedm.cpp:108 (2)
    //         004b31bf     POP        ESI
    //         004b31c0     RET
    //         004b31c1     ??         90h
    //         004b31c2     NOP
    //         004b31c3     NOP
    //         004b31c4     NOP
    //         004b31c5     NOP
    //         004b31c6     NOP
    //         004b31c7     NOP
    //         004b31c8     NOP
    //         004b31c9     NOP
    //         004b31ca     NOP
    //         004b31cb     NOP
    //         004b31cc     NOP
    //         004b31cd     NOP
    //         004b31ce     NOP
    //         004b31cf     NOP
    //                              * protected: virtual long __thiscall TRIBE_Screen_Sed_Menu::action(class TPanel *,long,unsigned long... *
    //                              long __thiscall action(TRIBE_Screen_Sed_Menu * this, TPanel * param_
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[4]:     004b31e2(R), 004b3242(W), 004b32ad(W), 004b3323(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004b31d6(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b33a8(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004b33a3(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     004b3248(W), 004b3265(W), 004b32b3(W), 004b32d0(W), 
    //                                                                                     004b3329(W), 004b3346(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[6]:     004b321b(R), 004b3286(R), 004b32f1(R), 004b3367(R), 
    //                                                                                     004b3391(R), 004b33b4(R)  
    //                               ?action@TRIBE_Screen_Sed_Menu@@MAEJPAVTPanel@@JKK@Z          XREF[1]:     00573bb4(*)  
    //                               TRIBE_Screen_Sed_Menu::action
    //                              scr_sedm.cpp:114 (6)
    //         004b31d0     MOV        EAX,FS:[0x0]
    //                              scr_sedm.cpp:115 (32)
    //         004b31d6     MOV        EDX,dword ptr [ESP + param_2]
    //         004b31da     PUSH       -0x1
    //         004b31dc     PUSH       FUN_0055f5c1
    //         004b31e1     PUSH       EAX
    //         004b31e2     MOV        EAX,dword ptr [ESP + param_1]
    //         004b31e6     MOV        dword ptr FS:[0x0],ESP
    //         004b31ed     PUSH       ESI
    //         004b31ee     TEST       EAX,EAX
    //         004b31f0     JZ         LAB_004b33a3
    //                              scr_sedm.cpp:116 (9)
    //         004b31f6     CMP        EDX,0x1
    //         004b31f9     JNZ        LAB_004b33a3
    //                              scr_sedm.cpp:118 (8)
    //         004b31ff     CMP        EAX,dword ptr [ECX + this->button[0]]
    //         004b3205     JNZ        LAB_004b322d
    //                              scr_sedm.cpp:119 (15)
    //         004b3207     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b320d     PUSH       0x0
    //         004b320f     PUSH       0x0
    //         004b3211     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this, 
    //                              scr_sedm.cpp:120 (5)
    //         004b3216     MOV        EAX,0x1
    //                              scr_sedm.cpp:154 (18)
    //         004b321b     MOV        this,dword ptr [ESP + local_c]
    //         004b321f     MOV        dword ptr FS:[0x0],this
    //         004b3226     POP        ESI
    //         004b3227     ADD        ESP,0xc
    //         004b322a     RET        0x10
    //                               LAB_004b322d                                                 XREF[1]:     004b3205(j)  
    //                              scr_sedm.cpp:123 (8)
    //         004b322d     CMP        EAX,dword ptr [ECX + this+0x480]
    //         004b3233     JNZ        LAB_004b3298
    //                              scr_sedm.cpp:124 (36)
    //         004b3235     PUSH       0x490
    //         004b323a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b323f     ADD        ESP,0x4
    //         004b3242     MOV        dword ptr [ESP + param_1],EAX
    //         004b3246     TEST       EAX,EAX
    //         004b3248     MOV        dword ptr [ESP + local_4],0x0
    //         004b3250     JZ         LAB_004b3259
    //         004b3252     MOV        this,EAX
    //         004b3254     CALL       TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open     undefined TRIBE_Screen_Sed_Open(TRIBE_Screen_
    //                               LAB_004b3259                                                 XREF[1]:     004b3250(j)  
    //                              scr_sedm.cpp:125 (25)
    //         004b3259     PUSH       0x0
    //         004b325b     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         004b3260     MOV        this,panel_system
    //         004b3265     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b326d     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sedm.cpp:126 (15)
    //         004b3272     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
    //         004b3277     MOV        this,panel_system
    //         004b327c     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sedm.cpp:127 (5)
    //         004b3281     MOV        EAX,0x1
    //                              scr_sedm.cpp:154 (18)
    //         004b3286     MOV        this,dword ptr [ESP + local_c]
    //         004b328a     MOV        dword ptr FS:[0x0],this
    //         004b3291     POP        ESI
    //         004b3292     ADD        ESP,0xc
    //         004b3295     RET        0x10
    //                               LAB_004b3298                                                 XREF[1]:     004b3233(j)  
    //                              scr_sedm.cpp:129 (8)
    //         004b3298     CMP        EAX,dword ptr [ECX + this+0x484]
    //         004b329e     JNZ        LAB_004b3303
    //                              scr_sedm.cpp:130 (36)
    //         004b32a0     PUSH       0x4c4
    //         004b32a5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b32aa     ADD        ESP,0x4
    //         004b32ad     MOV        dword ptr [ESP + param_1],EAX
    //         004b32b1     TEST       EAX,EAX
    //         004b32b3     MOV        dword ptr [ESP + local_4],0x1
    //         004b32bb     JZ         LAB_004b32c4
    //         004b32bd     MOV        this,EAX
    //         004b32bf     CALL       TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_E   undefined TRIBE_Campaign_Editor_Screen(TRIBE_
    //                               LAB_004b32c4                                                 XREF[1]:     004b32bb(j)  
    //                              scr_sedm.cpp:131 (25)
    //         004b32c4     PUSH       0x0
    //         004b32c6     PUSH       s_Campaign_Editor_Screen                         = "Campaign Editor Screen"
    //         004b32cb     MOV        this,panel_system
    //         004b32d0     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b32d8     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sedm.cpp:133 (15)
    //         004b32dd     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
    //         004b32e2     MOV        this,panel_system
    //         004b32e7     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sedm.cpp:134 (5)
    //         004b32ec     MOV        EAX,0x1
    //                              scr_sedm.cpp:154 (18)
    //         004b32f1     MOV        this,dword ptr [ESP + local_c]
    //         004b32f5     MOV        dword ptr FS:[0x0],this
    //         004b32fc     POP        ESI
    //         004b32fd     ADD        ESP,0xc
    //         004b3300     RET        0x10
    //                               LAB_004b3303                                                 XREF[1]:     004b329e(j)  
    //                              scr_sedm.cpp:137 (8)
    //         004b3303     CMP        EAX,dword ptr [ECX + this+0x488]
    //         004b3309     JNZ        LAB_004b3379
    //                              scr_sedm.cpp:138 (11)
    //         004b330b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3311     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              language.dll match for 0x4b0: "Ready"
    //                              scr_sedm.cpp:139 (36)
    //         004b3316     PUSH       0x4b0
    //         004b331b     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b3320     ADD        ESP,0x4
    //         004b3323     MOV        dword ptr [ESP + param_1],EAX
    //         004b3327     TEST       EAX,EAX
    //         004b3329     MOV        dword ptr [ESP + local_4],0x2
    //         004b3331     JZ         LAB_004b333a
    //         004b3333     MOV        this,EAX
    //         004b3335     CALL       TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu   undefined TRIBE_Screen_Main_Menu(TRIBE_Screen
    //                               LAB_004b333a                                                 XREF[1]:     004b3331(j)  
    //                              scr_sedm.cpp:140 (25)
    //         004b333a     PUSH       0x0
    //         004b333c     PUSH       s_Main_Menu                                      = "Main Menu"
    //         004b3341     MOV        this,panel_system
    //         004b3346     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b334e     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_sedm.cpp:141 (15)
    //         004b3353     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
    //         004b3358     MOV        this,panel_system
    //         004b335d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_sedm.cpp:142 (5)
    //         004b3362     MOV        EAX,0x1
    //                              scr_sedm.cpp:154 (18)
    //         004b3367     MOV        this,dword ptr [ESP + local_c]
    //         004b336b     MOV        dword ptr FS:[0x0],this
    //         004b3372     POP        ESI
    //         004b3373     ADD        ESP,0xc
    //         004b3376     RET        0x10
    //                               LAB_004b3379                                                 XREF[1]:     004b3309(j)  
    //                              scr_sedm.cpp:144 (8)
    //         004b3379     CMP        EAX,dword ptr [ECX + this->close_button]
    //         004b337f     JNZ        LAB_004b33a3
    //                              scr_sedm.cpp:146 (11)
    //         004b3381     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3387     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_sedm.cpp:147 (5)
    //         004b338c     MOV        EAX,0x1
    //                              scr_sedm.cpp:154 (18)
    //         004b3391     MOV        this,dword ptr [ESP + local_c]
    //         004b3395     MOV        dword ptr FS:[0x0],this
    //         004b339c     POP        ESI
    //         004b339d     ADD        ESP,0xc
    //         004b33a0     RET        0x10
    //                               LAB_004b33a3                                                 XREF[3]:     004b31f0(j), 004b31f9(j), 
    //                                                                                                         004b337f(j)  
    //                              scr_sedm.cpp:153 (17)
    //         004b33a3     MOV        ESI,dword ptr [ESP + param_4]
    //         004b33a7     PUSH       ESI
    //         004b33a8     MOV        ESI,dword ptr [ESP + param_3]
    //         004b33ac     PUSH       ESI
    //         004b33ad     PUSH       EDX
    //         004b33ae     PUSH       EAX
    //         004b33af     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_sedm.cpp:154 (18)
    //         004b33b4     MOV        this,dword ptr [ESP + local_c]
    //         004b33b8     POP        ESI
    //         004b33b9     MOV        dword ptr FS:[0x0],this
    //         004b33c0     ADD        ESP,0xc
    //         004b33c3     RET        0x10
    //         004b33c6     ??         90h
    //         004b33c7     NOP
    //         004b33c8     NOP
    //         004b33c9     NOP
    //         004b33ca     NOP
    //         004b33cb     NOP
    //         004b33cc     NOP
    //         004b33cd     NOP
    //         004b33ce     NOP
    //         004b33cf     NOP
    return 0;
}

long TRIBE_Screen_Sed_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

