#include "common.h"
#include "dlg_sedm.h"

TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu(TRIBE_Screen_Sed* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Dialog_Sed_Menu(TRIBE_Dialog_Sed_Menu * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Dialog_S    ECX:4 (auto)   this
    //              TRIBE_Screen_S    Stack[0x4]:4   param_1                   XREF[1]:     0044016a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00440195(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00440322(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00440161(W)  
    //                               ??0TRIBE_Dialog_Sed_Menu@@QAE@PAVTRIBE_Screen_Sed@@@Z        XREF[1]:     command_menu:004ad2a9(c)  
    //                               TRIBE_Dialog_Sed_Menu::TRIBE_Dialog_Sed_Menu
    //                              dlg_sedm.cpp:41 (54)
    //         00440140     PUSH       -0x1
    //         00440142     PUSH       FUN_0055d1b8
    //         00440147     MOV        EAX,FS:[0x0]
    //         0044014d     PUSH       EAX
    //         0044014e     MOV        dword ptr FS:[0x0],ESP
    //         00440155     PUSH       this
    //         00440156     PUSH       EBX
    //         00440157     PUSH       EBP
    //         00440158     PUSH       ESI
    //         00440159     PUSH       EDI
    //         0044015a     MOV        ESI,this
    //         0044015c     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         00440161     MOV        dword ptr [ESP + local_10],ESI
    //         00440165     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //         0044016a     MOV        EBX,dword ptr [ESP + param_1]
    //         0044016e     LEA        EBP,[ESI + 0x498]
    //         00440174     XOR        EAX,EAX
    //                              dlg_sedm.cpp:45 (27)
    //         00440176     MOV        this,0x7
    //         0044017b     MOV        EDI,EBP
    //         0044017d     MOV        dword ptr [ESI + 0x490],EBX
    //         00440183     MOV        dword ptr [ESI + 0x494],EAX
    //         00440189     MOV        dword ptr [ESI],TRIBE_Dialog_Sed_Menu::`vftable' = 00440340
    //         0044018f     STOSD.REP  ES:EDI
    //                              dlg_sedm.cpp:47 (56)
    //         00440191     PUSH       0x1
    //         00440193     MOV        this,EBX
    //         00440195     MOV        dword ptr [ESP + local_4],EAX
    //         00440199     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0044019e     PUSH       EAX
    //         0044019f     MOV        this,EBX
    //         004401a1     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         004401a6     PUSH       EAX
    //         004401a7     PUSH       0x190
    //         004401ac     PUSH       0x1cc
    //         004401b1     PUSH       EBX
    //         004401b2     MOV        this,EBX
    //         004401b4     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         004401b9     PUSH       EAX
    //         004401ba     MOV        this,ESI
    //         004401bc     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         004401c1     TEST       EAX,EAX
    //         004401c3     JZ         LAB_00440322
    //                              dlg_sedm.cpp:50 (41)
    //         004401c9     PUSH       0x0
    //         004401cb     PUSH       0x0
    //         004401cd     PUSH       0x0
    //         004401cf     PUSH       0x28
    //         004401d1     PUSH       0x190
    //         004401d6     PUSH       0x14
    //         004401d8     PUSH       0x1e
    //         004401da     PUSH       0x0
    //                              language.dll match for 0x2443: "Quit to Main Menu"
    //         004401dc     PUSH       0x2443
    //         004401e1     PUSH       EBP
    //         004401e2     PUSH       ESI
    //         004401e3     MOV        this,ESI
    //         004401e5     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004401ea     TEST       EAX,EAX
    //         004401ec     JZ         LAB_00440322
    //                              dlg_sedm.cpp:51 (47)
    //         004401f2     PUSH       0x0
    //         004401f4     PUSH       0x0
    //         004401f6     PUSH       0x0
    //         004401f8     PUSH       0x28
    //         004401fa     PUSH       0x190
    //         004401ff     PUSH       0x46
    //         00440201     PUSH       0x1e
    //         00440203     PUSH       0x0
    //         00440205     LEA        EAX,[ESI + 0x49c]
    //                              language.dll match for 0x2441: "Save"
    //         0044020b     PUSH       0x2441
    //         00440210     PUSH       EAX
    //         00440211     PUSH       ESI
    //         00440212     MOV        this,ESI
    //         00440214     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00440219     TEST       EAX,EAX
    //         0044021b     JZ         LAB_00440322
    //                              dlg_sedm.cpp:52 (47)
    //         00440221     PUSH       0x0
    //         00440223     PUSH       0x0
    //         00440225     PUSH       0x0
    //         00440227     PUSH       0x28
    //         00440229     PUSH       0x190
    //         0044022e     PUSH       0x78
    //         00440230     PUSH       0x1e
    //         00440232     PUSH       0x0
    //         00440234     LEA        this,[ESI + 0x4a0]
    //                              language.dll match for 0x2442: "Save As"
    //         0044023a     PUSH       0x2442
    //         0044023f     PUSH       this
    //         00440240     PUSH       ESI
    //         00440241     MOV        this,ESI
    //         00440243     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00440248     TEST       EAX,EAX
    //         0044024a     JZ         LAB_00440322
    //                              dlg_sedm.cpp:53 (50)
    //         00440250     PUSH       0x0
    //         00440252     PUSH       0x0
    //         00440254     PUSH       0x0
    //         00440256     PUSH       0x28
    //         00440258     PUSH       0x190
    //         0044025d     PUSH       0xaa
    //         00440262     PUSH       0x1e
    //         00440264     PUSH       0x0
    //         00440266     LEA        EDX,[ESI + 0x4a4]
    //                              language.dll match for 0x2445: "Edit Scenario"
    //         0044026c     PUSH       0x2445
    //         00440271     PUSH       EDX
    //         00440272     PUSH       ESI
    //         00440273     MOV        this,ESI
    //         00440275     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0044027a     TEST       EAX,EAX
    //         0044027c     JZ         LAB_00440322
    //                              dlg_sedm.cpp:54 (46)
    //         00440282     PUSH       0x0
    //         00440284     PUSH       0x0
    //         00440286     PUSH       0x0
    //         00440288     PUSH       0x28
    //         0044028a     PUSH       0x190
    //         0044028f     PUSH       0xdc
    //         00440294     PUSH       0x1e
    //         00440296     PUSH       0x0
    //         00440298     LEA        EAX,[ESI + 0x4a8]
    //                              language.dll match for 0x242e: "Create Scenario"
    //         0044029e     PUSH       0x242e
    //         004402a3     PUSH       EAX
    //         004402a4     PUSH       ESI
    //         004402a5     MOV        this,ESI
    //         004402a7     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004402ac     TEST       EAX,EAX
    //         004402ae     JZ         LAB_00440322
    //                              dlg_sedm.cpp:55 (46)
    //         004402b0     PUSH       0x0
    //         004402b2     PUSH       0x0
    //         004402b4     PUSH       0x0
    //         004402b6     PUSH       0x28
    //         004402b8     PUSH       0x190
    //         004402bd     PUSH       0x10e
    //         004402c2     PUSH       0x1e
    //         004402c4     PUSH       0x0
    //         004402c6     LEA        this,[ESI + 0x4ac]
    //                              language.dll match for 0x2446: "Test"
    //         004402cc     PUSH       0x2446
    //         004402d1     PUSH       this
    //         004402d2     PUSH       ESI
    //         004402d3     MOV        this,ESI
    //         004402d5     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004402da     TEST       EAX,EAX
    //         004402dc     JZ         LAB_00440322
    //                              dlg_sedm.cpp:56 (46)
    //         004402de     PUSH       0x0
    //         004402e0     PUSH       0x0
    //         004402e2     PUSH       0x0
    //         004402e4     PUSH       0x28
    //         004402e6     PUSH       0x190
    //         004402eb     PUSH       0x154
    //         004402f0     PUSH       0x1e
    //         004402f2     LEA        EDI,[ESI + 0x4b0]
    //         004402f8     PUSH       0x0
    //                              language.dll match for 0x2444: "Cancel"
    //         004402fa     PUSH       0x2444
    //         004402ff     PUSH       EDI
    //         00440300     PUSH       ESI
    //         00440301     MOV        this,ESI
    //         00440303     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00440308     TEST       EAX,EAX
    //         0044030a     JZ         LAB_00440322
    //                              dlg_sedm.cpp:57 (22)
    //         0044030c     MOV        EDI,dword ptr [EDI]
    //         0044030e     MOV        dword ptr [EDI + 0x298],0x1b
    //         00440318     MOV        dword ptr [EDI + 0x29c],0x0
    //                               LAB_00440322                                                 XREF[8]:     004401c3(j), 004401ec(j), 
    //                                                                                                         0044021b(j), 0044024a(j), 
    //                                                                                                         0044027c(j), 004402ae(j), 
    //                                                                                                         004402dc(j), 0044030a(j)  
    //                              dlg_sedm.cpp:58 (23)
    //         00440322     MOV        this,dword ptr [ESP + local_c]
    //         00440326     MOV        EAX,ESI
    //         00440328     POP        EDI
    //         00440329     POP        ESI
    //         0044032a     POP        EBP
    //         0044032b     MOV        dword ptr FS:[0x0],this
    //         00440332     POP        EBX
    //         00440333     ADD        ESP,0x10
    //         00440336     RET        0x4
    //         00440339     ??         90h
    //         0044033a     NOP
    //         0044033b     NOP
    //         0044033c     NOP
    //         0044033d     NOP
    //         0044033e     NOP
    //         0044033f     NOP
}

TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Dialog_Sed_Menu(TRIBE_Dialog_Sed_Menu * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Dialog_S    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044038f(W), 004403d4(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004403e1(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0044037b(W)  
    //                               ??1TRIBE_Dialog_Sed_Menu@@UAE@XZ                             XREF[1]:     `scalar_deleting_destructor':00440
    //                               TRIBE_Dialog_Sed_Menu::~TRIBE_Dialog_Sed_Menu
    //                              dlg_sedm.cpp:64 (37)
    //         00440360     PUSH       -0x1
    //         00440362     PUSH       FUN_0055d1d8
    //         00440367     MOV        EAX,FS:[0x0]
    //         0044036d     PUSH       EAX
    //         0044036e     MOV        dword ptr FS:[0x0],ESP
    //         00440375     PUSH       this
    //         00440376     PUSH       EBX
    //         00440377     PUSH       ESI
    //         00440378     MOV        ESI,this
    //         0044037a     PUSH       EDI
    //         0044037b     MOV        dword ptr [ESP + local_10],ESI
    //         0044037f     MOV        dword ptr [ESI],TRIBE_Dialog_Sed_Menu::`vftable' = 00440340
    //                              dlg_sedm.cpp:68 (23)
    //         00440385     PUSH       s_Open_Dialog                                    = 4Fh
    //         0044038a     MOV        this,panel_system
    //         0044038f     MOV        dword ptr [ESP + local_4],0x0
    //         00440397     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:69 (15)
    //         0044039c     PUSH       s_New_Dialog                                     = 4Eh
    //         004403a1     MOV        this,panel_system
    //         004403a6     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:71 (25)
    //         004403ab     LEA        EAX,[ESI + 0x494]
    //         004403b1     MOV        this,ESI
    //         004403b3     PUSH       EAX
    //         004403b4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004403b9     LEA        EDI,[ESI + 0x498]
    //         004403bf     MOV        EBX,0x7
    //                               LAB_004403c4                                                 XREF[1]:     004403d0(j)  
    //                              dlg_sedm.cpp:74 (16)
    //         004403c4     PUSH       EDI
    //         004403c5     MOV        this,ESI
    //         004403c7     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004403cc     ADD        EDI,0x4
    //         004403cf     DEC        EBX
    //         004403d0     JNZ        LAB_004403c4
    //         004403d2     MOV        this,ESI
    //                              dlg_sedm.cpp:75 (31)
    //         004403d4     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004403dc     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         004403e1     MOV        this,dword ptr [ESP + local_c]
    //         004403e5     POP        EDI
    //         004403e6     POP        ESI
    //         004403e7     MOV        dword ptr FS:[0x0],this
    //         004403ee     POP        EBX
    //         004403ef     ADD        ESP,0x10
    //         004403f2     RET
    //         004403f3     ??         90h
    //         004403f4     NOP
    //         004403f5     NOP
    //         004403f6     NOP
    //         004403f7     NOP
    //         004403f8     NOP
    //         004403f9     NOP
    //         004403fa     NOP
    //         004403fb     NOP
    //         004403fc     NOP
    //         004403fd     NOP
    //         004403fe     NOP
    //         004403ff     NOP
    //                              * public: virtual long __thiscall TRIBE_Dialog_Sed_Menu::action(class TPanel *,long,unsigned long,un... *
    //                              long __thiscall action(TRIBE_Dialog_Sed_Menu * this, TPanel * param_
    //              long              EAX:4          <RETURN>
    //              TRIBE_Dialog_S    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     00440423(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     00440416(R), 00440726(W)  
    //              ulong             Stack[0xc]:4   param_3
    //              ulong             Stack[0x10]:4  param_4
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0044072c(W), 00440749(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00440782(R)  
    //                               ?action@TRIBE_Dialog_Sed_Menu@@UAEJPAVTPanel@@JKK@Z          XREF[1]:     0056ff44(*)  
    //                               TRIBE_Dialog_Sed_Menu::action
    //                              dlg_sedm.cpp:81 (22)
    //         00440400     MOV        EAX,FS:[0x0]
    //         00440406     PUSH       -0x1
    //         00440408     PUSH       FUN_0055d1fb
    //         0044040d     PUSH       EAX
    //         0044040e     MOV        dword ptr FS:[0x0],ESP
    //         00440415     PUSH       EBX
    //                              dlg_sedm.cpp:88 (26)
    //         00440416     MOV        EBX,dword ptr [ESP + param_2]
    //         0044041a     PUSH       EBP
    //         0044041b     MOV        EBP,dword ptr [ECX + this->scenario_editor]
    //         00440421     PUSH       ESI
    //         00440422     PUSH       EDI
    //         00440423     MOV        EDI,dword ptr [ESP + param_1]
    //         00440427     CMP        EBX,0x1
    //         0044042a     JNZ        LAB_004405d2
    //                              dlg_sedm.cpp:91 (8)
    //         00440430     CMP        EDI,dword ptr [ECX + this->buttons[0]]
    //         00440436     JNZ        LAB_00440469
    //                              dlg_sedm.cpp:104 (17)
    //         00440438     PUSH       0x0
    //         0044043a     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         0044043f     MOV        this,panel_system
    //         00440444     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:105 (15)
    //         00440449     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         0044044e     MOV        this,panel_system
    //         00440453     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:106 (7)
    //         00440458     MOV        this,EBP
    //         0044045a     CALL       TRIBE_Screen_Sed::command_quit                   void command_quit(TRIBE_Screen_Sed * this)
    //                              dlg_sedm.cpp:107 (10)
    //         0044045f     MOV        EAX,0x1
    //         00440464     JMP        LAB_00440782
    //                               LAB_00440469                                                 XREF[1]:     00440436(j)  
    //                              dlg_sedm.cpp:111 (8)
    //         00440469     CMP        EDI,dword ptr [ECX + this+0x49c]
    //         0044046f     JNZ        LAB_004404a6
    //                              dlg_sedm.cpp:113 (17)
    //         00440471     PUSH       0x0
    //         00440473     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         00440478     MOV        this,panel_system
    //         0044047d     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:114 (15)
    //         00440482     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         00440487     MOV        this,panel_system
    //         0044048c     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:115 (11)
    //         00440491     PUSH       0x0
    //         00440493     PUSH       0x1
    //         00440495     MOV        this,EBP
    //         00440497     CALL       TRIBE_Screen_Sed::command_save                   void command_save(TRIBE_Screen_Sed * this, uc
    //                              dlg_sedm.cpp:116 (10)
    //         0044049c     MOV        EAX,0x1
    //         004404a1     JMP        LAB_00440782
    //                               LAB_004404a6                                                 XREF[1]:     0044046f(j)  
    //                              dlg_sedm.cpp:120 (8)
    //         004404a6     CMP        EDI,dword ptr [ECX + this+0x4a0]
    //         004404ac     JNZ        LAB_004404e1
    //                              dlg_sedm.cpp:122 (17)
    //         004404ae     PUSH       0x0
    //         004404b0     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004404b5     MOV        this,panel_system
    //         004404ba     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:123 (15)
    //         004404bf     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004404c4     MOV        this,panel_system
    //         004404c9     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:124 (9)
    //         004404ce     PUSH       0x0
    //         004404d0     MOV        this,EBP
    //         004404d2     CALL       TRIBE_Screen_Sed::command_save_as                void command_save_as(TRIBE_Screen_Sed * this,
    //                              dlg_sedm.cpp:125 (10)
    //         004404d7     MOV        EAX,0x1
    //         004404dc     JMP        LAB_00440782
    //                               LAB_004404e1                                                 XREF[1]:     004404ac(j)  
    //                              dlg_sedm.cpp:129 (8)
    //         004404e1     CMP        EDI,dword ptr [ECX + this+0x4a4]
    //         004404e7     JNZ        LAB_0044051a
    //                              dlg_sedm.cpp:147 (17)
    //         004404e9     PUSH       0x0
    //         004404eb     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004404f0     MOV        this,panel_system
    //         004404f5     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:148 (15)
    //         004404fa     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004404ff     MOV        this,panel_system
    //         00440504     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:149 (7)
    //         00440509     MOV        this,EBP
    //         0044050b     CALL       TRIBE_Screen_Sed::command_open                   void command_open(TRIBE_Screen_Sed * this)
    //                              dlg_sedm.cpp:150 (10)
    //         00440510     MOV        EAX,0x1
    //         00440515     JMP        LAB_00440782
    //                               LAB_0044051a                                                 XREF[1]:     004404e7(j)  
    //                              dlg_sedm.cpp:154 (8)
    //         0044051a     CMP        EDI,dword ptr [ECX + this+0x4a8]
    //         00440520     JNZ        LAB_00440553
    //                              dlg_sedm.cpp:173 (17)
    //         00440522     PUSH       0x0
    //         00440524     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         00440529     MOV        this,panel_system
    //         0044052e     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:174 (15)
    //         00440533     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         00440538     MOV        this,panel_system
    //         0044053d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:175 (7)
    //         00440542     MOV        this,EBP
    //         00440544     CALL       TRIBE_Screen_Sed::command_new                    void command_new(TRIBE_Screen_Sed * this)
    //                              dlg_sedm.cpp:176 (10)
    //         00440549     MOV        EAX,0x1
    //         0044054e     JMP        LAB_00440782
    //                               LAB_00440553                                                 XREF[1]:     00440520(j)  
    //                              dlg_sedm.cpp:180 (8)
    //         00440553     CMP        EDI,dword ptr [ECX + this+0x4ac]
    //         00440559     JNZ        LAB_004405a0
    //                              dlg_sedm.cpp:182 (17)
    //         0044055b     PUSH       0x0
    //         0044055d     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         00440562     MOV        this,panel_system
    //         00440567     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:183 (15)
    //         0044056c     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         00440571     MOV        this,panel_system
    //         00440576     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:186 (7)
    //         0044057b     MOV        this,EBP
    //         0044057d     CALL       TRIBE_Screen_Sed::scenario_save_defaulted        char * scenario_save_defaulted(TRIBE_Screen_S
    //                              dlg_sedm.cpp:187 (8)
    //         00440582     TEST       EAX,EAX
    //         00440584     JZ         LAB_0044076a
    //                              dlg_sedm.cpp:188 (12)
    //         0044058a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00440590     PUSH       EAX
    //         00440591     CALL       TRIBE_Game::test_scenario                        int test_scenario(TRIBE_Game * this, char * p
    //                              dlg_sedm.cpp:268 (10)
    //         00440596     MOV        EAX,0x1
    //         0044059b     JMP        LAB_00440782
    //                               LAB_004405a0                                                 XREF[1]:     00440559(j)  
    //                              dlg_sedm.cpp:195 (8)
    //         004405a0     CMP        EDI,dword ptr [ECX + this+0x4b0]
    //         004405a6     JNZ        LAB_004405d2
    //                              dlg_sedm.cpp:197 (17)
    //         004405a8     PUSH       0x0
    //         004405aa     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004405af     MOV        this,panel_system
    //         004405b4     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:198 (15)
    //         004405b9     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004405be     MOV        this,panel_system
    //         004405c3     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:199 (10)
    //         004405c8     MOV        EAX,0x1
    //         004405cd     JMP        LAB_00440782
    //                               LAB_004405d2                                                 XREF[2]:     0044042a(j), 004405a6(j)  
    //                              dlg_sedm.cpp:206 (8)
    //         004405d2     TEST       EDI,EDI
    //         004405d4     JZ         LAB_00440780
    //                              dlg_sedm.cpp:228 (72)
    //         004405da     MOV        this,EDI
    //         004405dc     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004405e1     TEST       EAX,EAX
    //         004405e3     JZ         LAB_0044068b
    //         004405e9     MOV        this,EDI
    //         004405eb     MOV        ESI,s_New_Dialog                                 = 4Eh
    //         004405f0     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004405f5                                                 XREF[1]:     00440613(j)  
    //         004405f5     MOV        DL,byte ptr [EAX]
    //         004405f7     MOV        this,DL
    //         004405f9     CMP        DL,byte ptr [ESI]=>s_New_Dialog                  = 4Eh
    //                                                                                  = 77h
    //         004405fb     JNZ        LAB_00440619
    //         004405fd     TEST       this,this
    //         004405ff     JZ         LAB_00440615
    //         00440601     MOV        DL,byte ptr [EAX + 0x1]
    //         00440604     MOV        this,DL
    //         00440606     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005843e5            = 65h
    //                                                                                  = " Dialog"
    //         00440609     JNZ        LAB_00440619
    //         0044060b     ADD        EAX,0x2
    //         0044060e     ADD        ESI,0x2
    //         00440611     TEST       this,this
    //         00440613     JNZ        LAB_004405f5
    //                               LAB_00440615                                                 XREF[1]:     004405ff(j)  
    //         00440615     XOR        EAX,EAX
    //         00440617     JMP        LAB_0044061e
    //                               LAB_00440619                                                 XREF[2]:     004405fb(j), 00440609(j)  
    //         00440619     SBB        EAX,EAX
    //         0044061b     SBB        EAX,-0x1
    //                               LAB_0044061e                                                 XREF[1]:     00440617(j)  
    //         0044061e     TEST       EAX,EAX
    //         00440620     JNZ        LAB_0044068b
    //                              dlg_sedm.cpp:230 (16)
    //         00440622     PUSH       EAX
    //         00440623     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         00440628     MOV        this,panel_system
    //         0044062d     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:231 (15)
    //         00440632     PUSH       s_New_Dialog                                     = 4Eh
    //         00440637     MOV        this,panel_system
    //         0044063c     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:232 (15)
    //         00440641     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         00440646     MOV        this,panel_system
    //         0044064b     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:234 (4)
    //         00440650     TEST       EBX,EBX
    //         00440652     JNZ        LAB_0044065f
    //                              dlg_sedm.cpp:235 (7)
    //         00440654     MOV        this,EBP
    //         00440656     CALL       TRIBE_Screen_Sed::command_quick_save             void command_quick_save(TRIBE_Screen_Sed * th
    //                              dlg_sedm.cpp:237 (13)
    //         0044065b     TEST       EBX,EBX
    //         0044065d     JZ         LAB_00440668
    //                               LAB_0044065f                                                 XREF[1]:     00440652(j)  
    //         0044065f     CMP        EBX,0x1
    //         00440662     JNZ        LAB_00440765
    //                               LAB_00440668                                                 XREF[1]:     0044065d(j)  
    //                              dlg_sedm.cpp:239 (15)
    //         00440668     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         0044066d     MOV        this,panel_system
    //         00440672     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:240 (15)
    //         00440677     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0044067d     PUSH       0x0
    //         0044067f     PUSH       0x0
    //         00440681     CALL       TRIBE_Game::start_scenario_editor                int start_scenario_editor(TRIBE_Game * this, 
    //                              dlg_sedm.cpp:246 (5)
    //         00440686     JMP        LAB_00440765
    //                               LAB_0044068b                                                 XREF[2]:     004405e3(j), 00440620(j)  
    //                              dlg_sedm.cpp:249 (76)
    //         0044068b     MOV        this,EDI
    //         0044068d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         00440692     TEST       EAX,EAX
    //         00440694     JZ         LAB_00440780
    //         0044069a     MOV        this,EDI
    //         0044069c     MOV        ESI,s_Open_Dialog                                = 4Fh
    //         004406a1     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004406a6                                                 XREF[1]:     004406c4(j)  
    //         004406a6     MOV        DL,byte ptr [EAX]
    //         004406a8     MOV        this,DL
    //         004406aa     CMP        DL,byte ptr [ESI]=>s_Open_Dialog                 = 4Fh
    //                                                                                  = 65h
    //         004406ac     JNZ        LAB_004406ca
    //         004406ae     TEST       this,this
    //         004406b0     JZ         LAB_004406c6
    //         004406b2     MOV        DL,byte ptr [EAX + 0x1]
    //         004406b5     MOV        this,DL
    //         004406b7     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005843f1            = 70h
    //                                                                                  = "n Dialog"
    //         004406ba     JNZ        LAB_004406ca
    //         004406bc     ADD        EAX,0x2
    //         004406bf     ADD        ESI,0x2
    //         004406c2     TEST       this,this
    //         004406c4     JNZ        LAB_004406a6
    //                               LAB_004406c6                                                 XREF[1]:     004406b0(j)  
    //         004406c6     XOR        EAX,EAX
    //         004406c8     JMP        LAB_004406cf
    //                               LAB_004406ca                                                 XREF[2]:     004406ac(j), 004406ba(j)  
    //         004406ca     SBB        EAX,EAX
    //         004406cc     SBB        EAX,-0x1
    //                               LAB_004406cf                                                 XREF[1]:     004406c8(j)  
    //         004406cf     TEST       EAX,EAX
    //         004406d1     JNZ        LAB_00440780
    //                              dlg_sedm.cpp:251 (16)
    //         004406d7     PUSH       EAX
    //         004406d8     PUSH       s_Scenario_Editor_Screen                         = "Scenario Editor Screen"
    //         004406dd     MOV        this,panel_system
    //         004406e2     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:252 (15)
    //         004406e7     PUSH       s_Open_Dialog                                    = 4Fh
    //         004406ec     MOV        this,panel_system
    //         004406f1     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:253 (15)
    //         004406f6     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         004406fb     MOV        this,panel_system
    //         00440700     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_sedm.cpp:255 (4)
    //         00440705     TEST       EBX,EBX
    //         00440707     JNZ        LAB_00440714
    //                              dlg_sedm.cpp:256 (7)
    //         00440709     MOV        this,EBP
    //         0044070b     CALL       TRIBE_Screen_Sed::command_quick_save             void command_quick_save(TRIBE_Screen_Sed * th
    //                              dlg_sedm.cpp:258 (9)
    //         00440710     TEST       EBX,EBX
    //         00440712     JZ         LAB_00440719
    //                               LAB_00440714                                                 XREF[1]:     00440707(j)  
    //         00440714     CMP        EBX,0x1
    //         00440717     JNZ        LAB_00440765
    //                               LAB_00440719                                                 XREF[1]:     00440712(j)  
    //                              dlg_sedm.cpp:260 (36)
    //         00440719     PUSH       0x490
    //         0044071e     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00440723     ADD        ESP,0x4
    //         00440726     MOV        dword ptr [ESP + param_2],EAX
    //         0044072a     TEST       EAX,EAX
    //         0044072c     MOV        dword ptr [ESP + local_4],0x0
    //         00440734     JZ         LAB_0044073d
    //         00440736     MOV        this,EAX
    //         00440738     CALL       TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open     undefined TRIBE_Screen_Sed_Open(TRIBE_Screen_
    //                               LAB_0044073d                                                 XREF[1]:     00440734(j)  
    //                              dlg_sedm.cpp:261 (25)
    //         0044073d     PUSH       0x0
    //         0044073f     PUSH       s_Scenario_Editor_Open                           = "Scenario Editor Open"
    //         00440744     MOV        this,panel_system
    //         00440749     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00440751     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_sedm.cpp:262 (15)
    //         00440756     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         0044075b     MOV        this,panel_system
    //         00440760     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_00440765                                                 XREF[3]:     00440662(j), 00440686(j), 
    //                                                                                                         00440717(j)  
    //                              dlg_sedm.cpp:265 (5)
    //         00440765     CMP        EBX,0x2
    //         00440768     JNZ        LAB_00440779
    //                               LAB_0044076a                                                 XREF[1]:     00440584(j)  
    //                              dlg_sedm.cpp:266 (15)
    //         0044076a     PUSH       s_Scenario_Menu_Dialog                           = "Scenario Menu Dialog"
    //         0044076f     MOV        this,panel_system
    //         00440774     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_00440779                                                 XREF[1]:     00440768(j)  
    //                              dlg_sedm.cpp:268 (7)
    //         00440779     MOV        EAX,0x1
    //         0044077e     JMP        LAB_00440782
    //                               LAB_00440780                                                 XREF[3]:     004405d4(j), 00440694(j), 
    //                                                                                                         004406d1(j)  
    //                              dlg_sedm.cpp:273 (2)
    //         00440780     XOR        EAX,EAX
    //                               LAB_00440782                                                 XREF[8]:     00440464(j), 004404a1(j), 
    //                                                                                                         004404dc(j), 00440515(j), 
    //                                                                                                         0044054e(j), 0044059b(j), 
    //                                                                                                         004405cd(j), 0044077e(j)  
    //                              dlg_sedm.cpp:274 (21)
    //         00440782     MOV        this,dword ptr [ESP + local_c]
    //         00440786     POP        EDI
    //         00440787     POP        ESI
    //         00440788     POP        EBP
    //         00440789     MOV        dword ptr FS:[0x0],this
    //         00440790     POP        EBX
    //         00440791     ADD        ESP,0xc
    //         00440794     RET        0x10
    //         00440797     ??         90h
    //         00440798     NOP
    //         00440799     NOP
    //         0044079a     NOP
    //         0044079b     NOP
    //         0044079c     NOP
    //         0044079d     NOP
    //         0044079e     NOP
    //         0044079f     NOP
}

long TRIBE_Dialog_Sed_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

