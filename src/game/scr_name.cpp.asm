#include "common.h"
#include "scr_name.h"

TRIBE_Screen_Name::TRIBE_Screen_Name() {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Screen_Name(TRIBE_Screen_Name * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a63fb(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004a6446(R), 004a669d(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a63f0(W)  
    //                               ??0TRIBE_Screen_Name@@QAE@XZ                                 XREF[2]:     action:0049108c(c), 
    //                               TRIBE_Screen_Name::TRIBE_Screen_Name                                      action:004b6fdf(c)  
    //                              scr_name.cpp:50 (41)
    //         004a63d0     PUSH       -0x1
    //         004a63d2     PUSH       FUN_0055f2d8
    //         004a63d7     MOV        EAX,FS:[0x0]
    //         004a63dd     PUSH       EAX
    //         004a63de     MOV        dword ptr FS:[0x0],ESP
    //         004a63e5     PUSH       this
    //         004a63e6     PUSH       EBX
    //         004a63e7     PUSH       ESI
    //         004a63e8     PUSH       EDI
    //         004a63e9     MOV        ESI,this
    //         004a63eb     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004a63f0     MOV        dword ptr [ESP + local_10],ESI
    //         004a63f4     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_name.cpp:51 (21)
    //         004a63f9     MOV        this,ESI
    //         004a63fb     MOV        dword ptr [ESP + local_4],0x0
    //         004a6403     MOV        dword ptr [ESI],TRIBE_Screen_Name::`vftable'     = 004a66c0
    //         004a6409     CALL       TRIBE_Screen_Name::init_vars                     void init_vars(TRIBE_Screen_Name * this)
    //                              scr_name.cpp:54 (44)
    //         004a640e     MOV        EAX,[rge_base_game]                              = 00000000
    //         004a6413     PUSH       0x1
    //         004a6415     PUSH       0x0
    //         004a6417     PUSH       0x0
    //         004a6419     MOV        this,dword ptr [EAX + 0x4c]
    //         004a641c     PUSH       0x0
    //         004a641e     PUSH       0x0
    //         004a6420     PUSH       0x1
    //         004a6422     PUSH       0xc384
    //         004a6427     PUSH       s_scr2                                           = 73h
    //         004a642c     PUSH       0x0
    //         004a642e     PUSH       this
    //         004a642f     MOV        this,ESI
    //         004a6431     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
    //         004a6436     TEST       EAX,EAX
    //         004a6438     JNZ        LAB_004a6458
    //                              scr_name.cpp:56 (10)
    //         004a643a     MOV        dword ptr [ESI + 0xd8],0x1
    //                              scr_name.cpp:96 (20)
    //         004a6444     MOV        EAX,ESI
    //         004a6446     MOV        this,dword ptr [ESP + local_c]
    //         004a644a     MOV        dword ptr FS:[0x0],this
    //         004a6451     POP        EDI
    //         004a6452     POP        ESI
    //         004a6453     POP        EBX
    //         004a6454     ADD        ESP,0x10
    //         004a6457     RET
    //                               LAB_004a6458                                                 XREF[1]:     004a6438(j)  
    //                              scr_name.cpp:60 (9)
    //         004a6458     PUSH       0x0
    //         004a645a     MOV        this,ESI
    //         004a645c     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_name.cpp:61 (17)
    //         004a6461     PUSH       0x1e0
    //         004a6466     PUSH       0x280
    //         004a646b     MOV        this,ESI
    //         004a646d     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_name.cpp:64 (47)
    //         004a6472     PUSH       0x0
    //         004a6474     PUSH       0x0
    //         004a6476     PUSH       0x1
    //         004a6478     PUSH       0x1
    //         004a647a     PUSH       0x1e
    //         004a647c     PUSH       0x258
    //         004a6481     PUSH       0x14
    //         004a6483     PUSH       0x14
    //         004a6485     LEA        EDX,[ESI + 0x478]
    //                              language.dll match for 0x29fe: "Select Player"
    //         004a648b     PUSH       0x29fe
    //         004a6490     PUSH       EDX
    //         004a6491     PUSH       ESI
    //         004a6492     MOV        this,ESI
    //         004a6494     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a6499     TEST       EAX,EAX
    //         004a649b     JZ         LAB_004a669d
    //                              scr_name.cpp:67 (47)
    //         004a64a1     PUSH       0x0
    //         004a64a3     PUSH       0x0
    //         004a64a5     PUSH       0x0
    //         004a64a7     PUSH       0x4
    //         004a64a9     PUSH       0x14
    //         004a64ab     PUSH       0x8c
    //         004a64b0     PUSH       0x50
    //         004a64b2     PUSH       0x3c
    //         004a64b4     LEA        EAX,[ESI + 0x47c]
    //                              language.dll match for 0x29ff: "Name"
    //         004a64ba     PUSH       0x29ff
    //         004a64bf     PUSH       EAX
    //         004a64c0     PUSH       ESI
    //         004a64c1     MOV        this,ESI
    //         004a64c3     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a64c8     TEST       EAX,EAX
    //         004a64ca     JZ         LAB_004a669d
    //                              scr_name.cpp:68 (39)
    //         004a64d0     PUSH       0xb
    //         004a64d2     PUSH       0x12c
    //         004a64d7     PUSH       0x14a
    //         004a64dc     LEA        EBX,[ESI + 0x480]
    //         004a64e2     PUSH       0x64
    //         004a64e4     PUSH       0x3c
    //         004a64e6     PUSH       EBX
    //         004a64e7     PUSH       ESI
    //         004a64e8     MOV        this,ESI
    //         004a64ea     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         004a64ef     TEST       EAX,EAX
    //         004a64f1     JZ         LAB_004a669d
    //                              scr_name.cpp:69 (27)
    //         004a64f7     MOV        this,dword ptr [EBX]
    //         004a64f9     LEA        EDI,[ESI + 0x484]
    //         004a64ff     PUSH       0x14
    //         004a6501     PUSH       this
    //         004a6502     PUSH       EDI
    //         004a6503     MOV        this,ESI
    //         004a6505     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004a650a     TEST       EAX,EAX
    //         004a650c     JZ         LAB_004a669d
    //                              scr_name.cpp:70 (14)
    //         004a6512     MOV        this,dword ptr [EDI]
    //         004a6514     PUSH       -0x1
    //                              language.dll match for 0x765c: "Select a player name."
    //         004a6516     PUSH       0x765c
    //         004a651b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_name.cpp:73 (50)
    //         004a6520     PUSH       0x0
    //         004a6522     PUSH       0x0
    //         004a6524     PUSH       0x0
    //         004a6526     PUSH       0x1e
    //         004a6528     PUSH       0xb4
    //         004a652d     PUSH       0x64
    //         004a652f     PUSH       0x190
    //         004a6534     LEA        EDI,[ESI + 0x488]
    //         004a653a     PUSH       0x0
    //                              language.dll match for 0x2a00: "New"
    //         004a653c     PUSH       0x2a00
    //         004a6541     PUSH       EDI
    //         004a6542     PUSH       ESI
    //         004a6543     MOV        this,ESI
    //         004a6545     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a654a     TEST       EAX,EAX
    //         004a654c     JZ         LAB_004a669d
    //                              scr_name.cpp:74 (14)
    //         004a6552     MOV        this,dword ptr [EDI]
    //         004a6554     PUSH       -0x1
    //                              language.dll match for 0x765d: "Click to add a new player nam
    //         004a6556     PUSH       0x765d
    //         004a655b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_name.cpp:75 (53)
    //         004a6560     PUSH       0x0
    //         004a6562     PUSH       0x0
    //         004a6564     PUSH       0x0
    //         004a6566     PUSH       0x1e
    //         004a6568     PUSH       0xb4
    //         004a656d     PUSH       0x8c
    //         004a6572     PUSH       0x190
    //         004a6577     LEA        EDI,[ESI + 0x48c]
    //         004a657d     PUSH       0x0
    //                              language.dll match for 0x2a01: "Remove"
    //         004a657f     PUSH       0x2a01
    //         004a6584     PUSH       EDI
    //         004a6585     PUSH       ESI
    //         004a6586     MOV        this,ESI
    //         004a6588     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a658d     TEST       EAX,EAX
    //         004a658f     JZ         LAB_004a669d
    //                              scr_name.cpp:76 (14)
    //         004a6595     MOV        this,dword ptr [EDI]
    //         004a6597     PUSH       -0x1
    //                              language.dll match for 0x765e: "Click to remove a player name
    //         004a6599     PUSH       0x765e
    //         004a659e     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_name.cpp:79 (50)
    //         004a65a3     PUSH       0x0
    //         004a65a5     PUSH       0x0
    //         004a65a7     PUSH       0x0
    //         004a65a9     PUSH       0x1e
    //         004a65ab     PUSH       0xf0
    //         004a65b0     PUSH       0x1b8
    //         004a65b5     PUSH       0x46
    //         004a65b7     LEA        EDI,[ESI + 0x490]
    //         004a65bd     PUSH       0x0
    //                              language.dll match for 0xfa1: "OK"
    //         004a65bf     PUSH       0xfa1
    //         004a65c4     PUSH       EDI
    //         004a65c5     PUSH       ESI
    //         004a65c6     MOV        this,ESI
    //         004a65c8     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a65cd     TEST       EAX,EAX
    //         004a65cf     JZ         LAB_004a669d
    //                              scr_name.cpp:80 (14)
    //         004a65d5     MOV        this,dword ptr [EDI]
    //         004a65d7     PUSH       -0x1
    //         004a65d9     PUSH       0x7531
    //         004a65de     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_name.cpp:81 (53)
    //         004a65e3     PUSH       0x0
    //         004a65e5     PUSH       0x0
    //         004a65e7     PUSH       0x0
    //         004a65e9     PUSH       0x1e
    //         004a65eb     PUSH       0xf0
    //         004a65f0     PUSH       0x1b8
    //         004a65f5     PUSH       0x14a
    //         004a65fa     LEA        EDI,[ESI + 0x494]
    //         004a6600     PUSH       0x0
    //                              language.dll match for 0xfa2: "Cancel"
    //         004a6602     PUSH       0xfa2
    //         004a6607     PUSH       EDI
    //         004a6608     PUSH       ESI
    //         004a6609     MOV        this,ESI
    //         004a660b     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a6610     TEST       EAX,EAX
    //         004a6612     JZ         LAB_004a669d
    //                              scr_name.cpp:82 (14)
    //         004a6618     MOV        this,dword ptr [EDI]
    //         004a661a     PUSH       -0x1
    //         004a661c     PUSH       0x7532
    //         004a6621     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_name.cpp:83 (2)
    //         004a6626     MOV        EDI,dword ptr [EDI]
    //                              scr_name.cpp:86 (60)
    //         004a6628     PUSH       0x0
    //         004a662a     PUSH       -0x1
    //         004a662c     PUSH       -0x1
    //         004a662e     PUSH       0x0
    //         004a6630     PUSH       0x0
    //         004a6632     PUSH       0x0
    //         004a6634     MOV        dword ptr [EDI + 0x298],0x1b
    //         004a663e     MOV        dword ptr [EDI + 0x29c],0x0
    //         004a6648     PUSH       0x0
    //         004a664a     LEA        EDI,[ESI + 0x498]
    //         004a6650     PUSH       0x0
    //                              language.dll match for 0x3ea: "X"
    //         004a6652     PUSH       0x3ea
    //         004a6657     PUSH       EDI
    //         004a6658     PUSH       ESI
    //         004a6659     MOV        this,ESI
    //         004a665b     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a6660     TEST       EAX,EAX
    //         004a6662     JZ         LAB_004a669d
    //                              scr_name.cpp:87 (33)
    //         004a6664     MOV        this,dword ptr [EDI]
    //         004a6666     PUSH       0x0
    //         004a6668     PUSH       0x0
    //         004a666a     PUSH       0x0
    //         004a666c     MOV        EDX,dword ptr [this->_padding_]
    //         004a666e     PUSH       0x0
    //         004a6670     PUSH       0x11
    //         004a6672     PUSH       0x11
    //         004a6674     PUSH       0x11
    //         004a6676     PUSH       0x11
    //         004a6678     PUSH       0x4
    //         004a667a     PUSH       0x4
    //         004a667c     PUSH       0x4
    //         004a667e     PUSH       0x4
    //         004a6680     PUSH       0x9
    //         004a6682     CALL       dword ptr [EDX + 0x18]
    //                              scr_name.cpp:90 (7)
    //         004a6685     MOV        this,ESI
    //         004a6687     CALL       TRIBE_Screen_Name::setup_tab_order               void setup_tab_order(TRIBE_Screen_Name * this)
    //                              scr_name.cpp:93 (7)
    //         004a668c     MOV        this,ESI
    //         004a668e     CALL       TRIBE_Screen_Name::get_player_names              void get_player_names(TRIBE_Screen_Name * this)
    //                              scr_name.cpp:95 (10)
    //         004a6693     MOV        dword ptr [ESI + 0x49c],0x0
    //                               LAB_004a669d                                                 XREF[9]:     004a649b(j), 004a64ca(j), 
    //                                                                                                         004a64f1(j), 004a650c(j), 
    //                                                                                                         004a654c(j), 004a658f(j), 
    //                                                                                                         004a65cf(j), 004a6612(j), 
    //                                                                                                         004a6662(j)  
    //                              scr_name.cpp:96 (20)
    //         004a669d     MOV        this,dword ptr [ESP + local_c]
    //         004a66a1     MOV        EAX,ESI
    //         004a66a3     POP        EDI
    //         004a66a4     POP        ESI
    //         004a66a5     MOV        dword ptr FS:[0x0],this
    //         004a66ac     POP        EBX
    //         004a66ad     ADD        ESP,0x10
    //         004a66b0     RET
    //         004a66b1     ??         90h
    //         004a66b2     NOP
    //         004a66b3     NOP
    //         004a66b4     NOP
    //         004a66b5     NOP
    //         004a66b6     NOP
    //         004a66b7     NOP
    //         004a66b8     NOP
    //         004a66b9     NOP
    //         004a66ba     NOP
    //         004a66bb     NOP
    //         004a66bc     NOP
    //         004a66bd     NOP
    //         004a66be     NOP
    //         004a66bf     NOP
}

TRIBE_Screen_Name::~TRIBE_Screen_Name() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Screen_Name(TRIBE_Screen_Name * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a670f(W), 004a679c(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a67a9(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a66f9(W)  
    //                               ??1TRIBE_Screen_Name@@UAE@XZ                                 XREF[1]:     `vector_deleting_destructor':004a6
    //                               TRIBE_Screen_Name::~TRIBE_Screen_Name
    //                              scr_name.cpp:102 (35)
    //         004a66e0     PUSH       -0x1
    //         004a66e2     PUSH       FUN_0055f2f8
    //         004a66e7     MOV        EAX,FS:[0x0]
    //         004a66ed     PUSH       EAX
    //         004a66ee     MOV        dword ptr FS:[0x0],ESP
    //         004a66f5     PUSH       this
    //         004a66f6     PUSH       ESI
    //         004a66f7     MOV        ESI,this
    //         004a66f9     MOV        dword ptr [ESP + local_10],ESI
    //         004a66fd     MOV        dword ptr [ESI],TRIBE_Screen_Name::`vftable'     = 004a66c0
    //                              scr_name.cpp:103 (25)
    //         004a6703     PUSH       0x0
    //         004a6705     PUSH       s_New_Name_Dialog                                = 4Eh
    //         004a670a     MOV        this,panel_system
    //         004a670f     MOV        dword ptr [ESP + local_4],0x0
    //         004a6717     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:105 (14)
    //         004a671c     LEA        EAX,[ESI + 0x478]
    //         004a6722     MOV        this,ESI
    //         004a6724     PUSH       EAX
    //         004a6725     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:106 (14)
    //         004a672a     LEA        this,[ESI + 0x47c]
    //         004a6730     PUSH       this
    //         004a6731     MOV        this,ESI
    //         004a6733     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:107 (14)
    //         004a6738     LEA        EDX,[ESI + 0x480]
    //         004a673e     MOV        this,ESI
    //         004a6740     PUSH       EDX
    //         004a6741     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:108 (14)
    //         004a6746     LEA        EAX,[ESI + 0x484]
    //         004a674c     MOV        this,ESI
    //         004a674e     PUSH       EAX
    //         004a674f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:109 (14)
    //         004a6754     LEA        this,[ESI + 0x488]
    //         004a675a     PUSH       this
    //         004a675b     MOV        this,ESI
    //         004a675d     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:110 (14)
    //         004a6762     LEA        EDX,[ESI + 0x48c]
    //         004a6768     MOV        this,ESI
    //         004a676a     PUSH       EDX
    //         004a676b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:111 (14)
    //         004a6770     LEA        EAX,[ESI + 0x490]
    //         004a6776     MOV        this,ESI
    //         004a6778     PUSH       EAX
    //         004a6779     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:112 (14)
    //         004a677e     LEA        this,[ESI + 0x494]
    //         004a6784     PUSH       this
    //         004a6785     MOV        this,ESI
    //         004a6787     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:113 (16)
    //         004a678c     LEA        EDX,[ESI + 0x498]
    //         004a6792     MOV        this,ESI
    //         004a6794     PUSH       EDX
    //         004a6795     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a679a     MOV        this,ESI
    //                              scr_name.cpp:114 (29)
    //         004a679c     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a67a4     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004a67a9     MOV        this,dword ptr [ESP + local_c]
    //         004a67ad     POP        ESI
    //         004a67ae     MOV        dword ptr FS:[0x0],this
    //         004a67b5     ADD        ESP,0x10
    //         004a67b8     RET
    //         004a67b9     ??         90h
    //         004a67ba     NOP
    //         004a67bb     NOP
    //         004a67bc     NOP
    //         004a67bd     NOP
    //         004a67be     NOP
    //         004a67bf     NOP
}

void TRIBE_Screen_Name::init_vars() {
    /* TODO: Stub */
    //                              void __thiscall init_vars(TRIBE_Screen_Name * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //                               ?init_vars@TRIBE_Screen_Name@@QAEXXZ                         XREF[1]:     TRIBE_Screen_Name:004a6409(c)  
    //                               TRIBE_Screen_Name::init_vars
    //                              scr_name.cpp:120 (8)
    //         004a67c0     XOR        EAX,EAX
    //         004a67c2     MOV        dword ptr [ECX + this->title],EAX
    //                              scr_name.cpp:122 (6)
    //         004a67c8     MOV        dword ptr [ECX + this->name_text],EAX
    //                              scr_name.cpp:123 (6)
    //         004a67ce     MOV        dword ptr [ECX + this->name_list],EAX
    //                              scr_name.cpp:124 (6)
    //         004a67d4     MOV        dword ptr [ECX + this->name_scrollbar],EAX
    //                              scr_name.cpp:125 (6)
    //         004a67da     MOV        dword ptr [ECX + this->new_button],EAX
    //                              scr_name.cpp:126 (6)
    //         004a67e0     MOV        dword ptr [ECX + this->remove_button],EAX
    //                              scr_name.cpp:127 (6)
    //         004a67e6     MOV        dword ptr [ECX + this->ok_button],EAX
    //                              scr_name.cpp:128 (6)
    //         004a67ec     MOV        dword ptr [ECX + this->cancel_button],EAX
    //                              scr_name.cpp:129 (6)
    //         004a67f2     MOV        dword ptr [ECX + this->close_button],EAX
    //                              scr_name.cpp:130 (1)
    //         004a67f8     RET
    //         004a67f9     ??         90h
    //         004a67fa     NOP
    //         004a67fb     NOP
    //         004a67fc     NOP
    //         004a67fd     NOP
    //         004a67fe     NOP
    //         004a67ff     NOP
    return;
}

void TRIBE_Screen_Name::get_player_names() {
    /* TODO: Stub */
    //                              void __thiscall get_player_names(TRIBE_Screen_Name * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a6817(*), 004a6867(R)  
    //              long              Stack[-0x8]:4  curr_player               XREF[5]:     004a681f(*), 004a6824(W), 004a684e(R), 004a6889(R), 
    //                                                                                     004a689e(R)  
    //              char * *          Stack[-0xc]:4  players
    //                               ?get_player_names@TRIBE_Screen_Name@@IAEXXZ                  XREF[3]:     TRIBE_Screen_Name:004a668e(c), 
    //                               TRIBE_Screen_Name::get_player_names                                       action:004a6c51(c), 
    //                                                                                                         action:004a6cec(c)  
    //                              scr_name.cpp:136 (7)
    //         004a6800     SUB        ESP,0x8
    //         004a6803     PUSH       EBX
    //         004a6804     MOV        EBX,this
    //         004a6806     PUSH       EDI
    //                              scr_name.cpp:143 (11)
    //         004a6807     MOV        this,dword ptr [EBX + 0x480]
    //         004a680d     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_name.cpp:145 (5)
    //         004a6812     MOV        EAX,[rge_base_game]                              = 00000000
    //                              scr_name.cpp:149 (28)
    //         004a6817     LEA        EDX=>local_4,[ESP + 0xc]
    //         004a681b     PUSH       EDX
    //         004a681c     MOV        this,dword ptr [EAX + 0x4]
    //         004a681f     LEA        EAX=>curr_player,[ESP + 0xc]
    //         004a6823     PUSH       EAX
    //         004a6824     MOV        dword ptr [ESP + curr_player],0x0
    //         004a682c     CALL       RGE_Game_Info::get_people_list                   long get_people_list(RGE_Game_Info * this, ch
    //         004a6831     MOV        EDI,EAX
    //                              scr_name.cpp:150 (4)
    //         004a6833     TEST       EDI,EDI
    //         004a6835     JZ         LAB_004a68ac
    //                              scr_name.cpp:154 (7)
    //         004a6837     MOV        this,dword ptr [EBX + 0x480]
    //         004a683d     PUSH       ESI
    //                              scr_name.cpp:155 (16)
    //         004a683e     XOR        ESI,ESI
    //         004a6840     TEST       EDI,EDI
    //         004a6842     MOV        dword ptr [ECX + this->_padding_],0x1
    //         004a684c     JLE        LAB_004a6867
    //                               LAB_004a684e                                                 XREF[1]:     004a6865(j)  
    //                              scr_name.cpp:156 (25)
    //         004a684e     MOV        EDX,dword ptr [ESP + curr_player]
    //         004a6852     MOV        this,dword ptr [EBX + 0x480]
    //         004a6858     PUSH       ESI
    //         004a6859     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         004a685c     PUSH       EAX
    //         004a685d     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //         004a6862     INC        ESI
    //         004a6863     CMP        ESI,EDI
    //         004a6865     JL         LAB_004a684e
    //                               LAB_004a6867                                                 XREF[1]:     004a684c(j)  
    //                              scr_name.cpp:157 (28)
    //         004a6867     MOV        this,dword ptr [ESP + local_4]
    //         004a686b     PUSH       this
    //         004a686c     MOV        this,dword ptr [EBX + 0x480]
    //         004a6872     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, long param_1)
    //         004a6877     MOV        this,dword ptr [EBX + 0x480]
    //         004a687d     PUSH       EAX
    //         004a687e     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
    //                              scr_name.cpp:160 (6)
    //         004a6883     XOR        ESI,ESI
    //         004a6885     TEST       EDI,EDI
    //         004a6887     JLE        LAB_004a689e
    //                               LAB_004a6889                                                 XREF[1]:     004a689c(j)  
    //                              scr_name.cpp:161 (21)
    //         004a6889     MOV        EDX,dword ptr [ESP + curr_player]
    //         004a688d     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         004a6890     PUSH       EAX
    //         004a6891     CALL       free                                             undefined free()
    //         004a6896     ADD        ESP,0x4
    //         004a6899     INC        ESI
    //         004a689a     CMP        ESI,EDI
    //         004a689c     JL         LAB_004a6889
    //                               LAB_004a689e                                                 XREF[1]:     004a6887(j)  
    //                              scr_name.cpp:162 (14)
    //         004a689e     MOV        this,dword ptr [ESP + curr_player]
    //         004a68a2     PUSH       this
    //         004a68a3     CALL       free                                             undefined free()
    //         004a68a8     ADD        ESP,0x4
    //         004a68ab     POP        ESI
    //                               LAB_004a68ac                                                 XREF[1]:     004a6835(j)  
    //                              scr_name.cpp:163 (6)
    //         004a68ac     POP        EDI
    //         004a68ad     POP        EBX
    //         004a68ae     ADD        ESP,0x8
    //         004a68b1     RET
    //         004a68b2     ??         90h
    //         004a68b3     NOP
    //         004a68b4     NOP
    //         004a68b5     NOP
    //         004a68b6     NOP
    //         004a68b7     NOP
    //         004a68b8     NOP
    //         004a68b9     NOP
    //         004a68ba     NOP
    //         004a68bb     NOP
    //         004a68bc     NOP
    //         004a68bd     NOP
    //         004a68be     NOP
    //         004a68bf     NOP
    return;
}

void TRIBE_Screen_Name::setup_tab_order() {
    /* TODO: Stub */
    //                              void __thiscall setup_tab_order(TRIBE_Screen_Name * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //              TPanel *[5]       Stack[-0x18]   tab_list                  XREF[0,5]:   004a6901(W), 004a6939(*), 004a6905(W), 004a6922(W), 
    //                                                                                     004a691e(W)  
    //                               ?setup_tab_order@TRIBE_Screen_Name@@IAEXXZ                   XREF[2]:     TRIBE_Screen_Name:004a6687(c), 
    //                               TRIBE_Screen_Name::setup_tab_order                                        action:004a6d02(c)  
    //                              scr_name.cpp:169 (7)
    //         004a68c0     SUB        ESP,0x14
    //         004a68c3     PUSH       ESI
    //         004a68c4     MOV        ESI,this
    //         004a68c6     PUSH       EDI
    //                              scr_name.cpp:170 (2)
    //         004a68c7     XOR        EDI,EDI
    //                              scr_name.cpp:173 (15)
    //         004a68c9     MOV        this,dword ptr [ESI + 0x480]
    //         004a68cf     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
    //         004a68d4     TEST       EAX,EAX
    //         004a68d6     JNZ        LAB_004a68dd
    //                              scr_name.cpp:174 (5)
    //         004a68d8     MOV        EDI,0x1
    //                               LAB_004a68dd                                                 XREF[1]:     004a68d6(j)  
    //                              scr_name.cpp:176 (12)
    //         004a68dd     MOV        this,dword ptr [ESI + 0x48c]
    //         004a68e3     PUSH       EDI
    //         004a68e4     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_name.cpp:177 (12)
    //         004a68e9     MOV        this,dword ptr [ESI + 0x490]
    //         004a68ef     PUSH       EDI
    //         004a68f0     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_name.cpp:182 (6)
    //         004a68f5     MOV        EAX,dword ptr [ESI + 0x480]
    //                              scr_name.cpp:183 (14)
    //         004a68fb     MOV        this,dword ptr [ESI + 0x488]
    //         004a6901     MOV        dword ptr [ESP + tab_list[1]],EAX
    //         004a6905     MOV        dword ptr [ESP + tab_list[2]],this
    //                              scr_name.cpp:184 (9)
    //         004a6909     TEST       EDI,EDI
    //         004a690b     MOV        EAX,0x2
    //         004a6910     JNZ        LAB_004a692b
    //                              scr_name.cpp:187 (25)
    //         004a6912     MOV        EAX,dword ptr [ESI + 0x490]
    //         004a6918     MOV        EDX,dword ptr [ESI + 0x48c]
    //         004a691e     MOV        dword ptr [ESP + tab_list[4]],EAX
    //         004a6922     MOV        dword ptr [ESP + tab_list[3]],EDX
    //         004a6926     MOV        EAX,0x4
    //                               LAB_004a692b                                                 XREF[1]:     004a6910(j)  
    //                              scr_name.cpp:189 (6)
    //         004a692b     MOV        this,dword ptr [ESI + 0x494]
    //                              scr_name.cpp:190 (21)
    //         004a6931     MOV        EDX,dword ptr [ESI]
    //         004a6933     MOV        dword ptr [ESP + EAX*0x4 + 0x8],this
    //         004a6937     INC        EAX
    //         004a6938     PUSH       EAX
    //         004a6939     LEA        EAX=>tab_list[1],[ESP + 0xc]
    //         004a693d     PUSH       EAX
    //         004a693e     MOV        this,ESI
    //         004a6940     CALL       dword ptr [EDX + 0xc8]
    //                              scr_name.cpp:193 (15)
    //         004a6946     MOV        this,dword ptr [ESI + 0x480]
    //         004a694c     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
    //         004a6951     TEST       EAX,EAX
    //         004a6953     JNZ        LAB_004a6969
    //                              scr_name.cpp:194 (7)
    //         004a6955     MOV        this,dword ptr [ESI + 0x488]
    //         004a695b     PUSH       this
    //                              scr_name.cpp:196 (7)
    //         004a695c     MOV        this,ESI
    //         004a695e     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_name.cpp:197 (6)
    //         004a6963     POP        EDI
    //         004a6964     POP        ESI
    //         004a6965     ADD        ESP,0x14
    //         004a6968     RET
    //                               LAB_004a6969                                                 XREF[1]:     004a6953(j)  
    //                              scr_name.cpp:196 (14)
    //         004a6969     MOV        EDX,dword ptr [ESI + 0x480]
    //         004a696f     MOV        this,ESI
    //         004a6971     PUSH       EDX
    //         004a6972     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_name.cpp:197 (6)
    //         004a6977     POP        EDI
    //         004a6978     POP        ESI
    //         004a6979     ADD        ESP,0x14
    //         004a697c     RET
    //         004a697d     ??         90h
    //         004a697e     NOP
    //         004a697f     NOP
    return;
}

long TRIBE_Screen_Name::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TRIBE_Screen_Name * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //                               ?handle_idle@TRIBE_Screen_Name@@UAEJXZ                       XREF[1]:     0057368c(*)  
    //                               TRIBE_Screen_Name::handle_idle
    //                              scr_name.cpp:204 (3)
    //         004a6980     PUSH       ESI
    //         004a6981     MOV        ESI,this
    //                              scr_name.cpp:215 (16)
    //         004a6983     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a6989     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004a698f     TEST       EAX,EAX
    //         004a6991     JNZ        LAB_004a6998
    //                              scr_name.cpp:216 (5)
    //         004a6993     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_004a6998                                                 XREF[1]:     004a6991(j)  
    //                              scr_name.cpp:218 (7)
    //         004a6998     MOV        this,ESI
    //         004a699a     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_name.cpp:219 (2)
    //         004a699f     POP        ESI
    //         004a69a0     RET
    //         004a69a1     ??         90h
    //         004a69a2     NOP
    //         004a69a3     NOP
    //         004a69a4     NOP
    //         004a69a5     NOP
    //         004a69a6     NOP
    //         004a69a7     NOP
    //         004a69a8     NOP
    //         004a69a9     NOP
    //         004a69aa     NOP
    //         004a69ab     NOP
    //         004a69ac     NOP
    //         004a69ad     NOP
    //         004a69ae     NOP
    //         004a69af     NOP
    //                              * public: virtual long __thiscall TRIBE_Screen_Name::action(class TPanel *,long,unsigned long,unsign... *
    //                              long __thiscall action(TRIBE_Screen_Name * this, TPanel * param_1, l
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_N    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a69d4(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004a69cc(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004a6d15(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004a6d0e(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     004a6a4e(W), 004a6a6e(W), 004a6ac2(W), 004a6ade(W), 
    //                                                                                     004a6b6e(W), 004a6b8f(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a6d27(R)  
    //              char[256]         Stack[-0x110   str                       XREF[3,2]:   004a6a48(W), 004a6abc(W), 004a6b68(W), 004a6bdd(*), 
    //                                                                                     004a6bea(*)  
    //                               ?action@TRIBE_Screen_Name@@UAEJPAVTPanel@@JKK@Z              XREF[1]:     005736f4(*)  
    //                               TRIBE_Screen_Name::action
    //                              scr_name.cpp:225 (28)
    //         004a69b0     MOV        EAX,FS:[0x0]
    //         004a69b6     PUSH       -0x1
    //         004a69b8     PUSH       FUN_0055f33a
    //         004a69bd     PUSH       EAX
    //         004a69be     MOV        dword ptr FS:[0x0],ESP
    //         004a69c5     SUB        ESP,0x104
    //         004a69cb     PUSH       EBX
    //                              scr_name.cpp:226 (27)
    //         004a69cc     MOV        EBX,dword ptr [ESP + param_2]
    //         004a69d3     PUSH       EBP
    //         004a69d4     MOV        EBP,dword ptr [ESP + param_1]
    //         004a69db     PUSH       ESI
    //         004a69dc     PUSH       EDI
    //         004a69dd     TEST       EBP,EBP
    //         004a69df     MOV        EDI,this
    //         004a69e1     JZ         LAB_004a6d0e
    //                              scr_name.cpp:229 (23)
    //         004a69e7     MOV        EAX,dword ptr [EDI + 0x490]
    //         004a69ed     CMP        EBP,EAX
    //         004a69ef     JNZ        LAB_004a6a97
    //         004a69f5     CMP        EBX,0x1
    //         004a69f8     JNZ        LAB_004a6a97
    //                              scr_name.cpp:231 (16)
    //         004a69fe     MOV        this,dword ptr [EDI + 0x480]
    //         004a6a04     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         004a6a09     CMP        EAX,-0x1
    //         004a6a0c     JNZ        LAB_004a6a15
    //                              scr_name.cpp:232 (7)
    //         004a6a0e     MOV        EAX,EBX
    //         004a6a10     JMP        LAB_004a6d27
    //                               LAB_004a6a15                                                 XREF[1]:     004a6a0c(j)  
    //                              scr_name.cpp:234 (11)
    //         004a6a15     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a6a1b     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_name.cpp:236 (27)
    //         004a6a20     MOV        EAX,[rge_base_game]                              = 00000000
    //         004a6a25     MOV        this,dword ptr [EDI + 0x480]
    //         004a6a2b     MOV        ESI,dword ptr [EAX + 0x4]
    //         004a6a2e     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         004a6a33     PUSH       EAX
    //         004a6a34     MOV        this,ESI
    //         004a6a36     CALL       RGE_Game_Info::set_current_person                uchar set_current_person(RGE_Game_Info * this
    //                              scr_name.cpp:238 (39)
    //         004a6a3b     PUSH       0x4cc
    //         004a6a40     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a6a45     ADD        ESP,0x4
    //         004a6a48     MOV        dword ptr [ESP + str[0]],EAX
    //         004a6a4c     TEST       EAX,EAX
    //         004a6a4e     MOV        dword ptr [ESP + local_4],0x0
    //         004a6a59     JZ         LAB_004a6a62
    //         004a6a5b     MOV        this,EAX
    //         004a6a5d     CALL       TRIBE_Screen_Campaign_Selection::TRIBE_Screen_   undefined TRIBE_Screen_Campaign_Selection(TRI
    //                               LAB_004a6a62                                                 XREF[1]:     004a6a59(j)  
    //                              scr_name.cpp:239 (28)
    //         004a6a62     PUSH       0x0
    //         004a6a64     PUSH       s_Campaign_Selection_Screen                      = "Campaign Selection Screen"
    //         004a6a69     MOV        this,panel_system
    //         004a6a6e     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a6a79     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:240 (15)
    //         004a6a7e     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004a6a83     MOV        this,panel_system
    //         004a6a88     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_name.cpp:241 (10)
    //         004a6a8d     MOV        EAX,0x1
    //         004a6a92     JMP        LAB_004a6d27
    //                               LAB_004a6a97                                                 XREF[2]:     004a69ef(j), 004a69f8(j)  
    //                              scr_name.cpp:245 (13)
    //         004a6a97     CMP        EBP,dword ptr [EDI + 0x494]
    //         004a6a9d     JNZ        LAB_004a6b07
    //         004a6a9f     CMP        EBX,0x1
    //         004a6aa2     JNZ        LAB_004a6b07
    //                              scr_name.cpp:247 (11)
    //         004a6aa4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a6aaa     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_name.cpp:248 (35)
    //         004a6aaf     PUSH       0x49c
    //         004a6ab4     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a6ab9     ADD        ESP,0x4
    //         004a6abc     MOV        dword ptr [ESP + str[0]],EAX
    //         004a6ac0     TEST       EAX,EAX
    //         004a6ac2     MOV        dword ptr [ESP + local_4],EBX
    //         004a6ac9     JZ         LAB_004a6ad2
    //         004a6acb     MOV        this,EAX
    //         004a6acd     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
    //                               LAB_004a6ad2                                                 XREF[1]:     004a6ac9(j)  
    //                              scr_name.cpp:249 (28)
    //         004a6ad2     PUSH       0x0
    //         004a6ad4     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004a6ad9     MOV        this,panel_system
    //         004a6ade     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a6ae9     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:250 (15)
    //         004a6aee     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004a6af3     MOV        this,panel_system
    //         004a6af8     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_name.cpp:251 (10)
    //         004a6afd     MOV        EAX,0x1
    //         004a6b02     JMP        LAB_004a6d27
    //                               LAB_004a6b07                                                 XREF[2]:     004a6a9d(j), 004a6aa2(j)  
    //                              scr_name.cpp:254 (8)
    //         004a6b07     CMP        EBP,dword ptr [EDI + 0x498]
    //         004a6b0d     JNZ        LAB_004a6b24
    //                              scr_name.cpp:256 (11)
    //         004a6b0f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a6b15     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_name.cpp:257 (10)
    //         004a6b1a     MOV        EAX,0x1
    //         004a6b1f     JMP        LAB_004a6d27
    //                               LAB_004a6b24                                                 XREF[1]:     004a6b0d(j)  
    //                              scr_name.cpp:261 (15)
    //         004a6b24     MOV        this,dword ptr [EDI + 0x480]
    //         004a6b2a     CMP        EBP,this
    //         004a6b2c     JNZ        LAB_004a6b4e
    //         004a6b2e     CMP        EBX,0x3
    //         004a6b31     JNZ        LAB_004a6b4e
    //                              scr_name.cpp:263 (17)
    //         004a6b33     MOV        EDX,dword ptr [EDI]
    //         004a6b35     PUSH       0x0
    //         004a6b37     PUSH       0x0
    //         004a6b39     PUSH       0x1
    //         004a6b3b     PUSH       EAX
    //         004a6b3c     MOV        this,EDI
    //         004a6b3e     CALL       dword ptr [EDX + 0xb4]
    //                              scr_name.cpp:264 (10)
    //         004a6b44     MOV        EAX,0x1
    //         004a6b49     JMP        LAB_004a6d27
    //                               LAB_004a6b4e                                                 XREF[2]:     004a6b2c(j), 004a6b31(j)  
    //                              scr_name.cpp:268 (13)
    //         004a6b4e     CMP        EBP,dword ptr [EDI + 0x488]
    //         004a6b54     JNZ        LAB_004a6ba9
    //         004a6b56     CMP        EBX,0x1
    //         004a6b59     JNZ        LAB_004a6ba9
    //                              scr_name.cpp:270 (40)
    //         004a6b5b     PUSH       0x4a4
    //         004a6b60     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a6b65     ADD        ESP,0x4
    //         004a6b68     MOV        dword ptr [ESP + str[0]],EAX
    //         004a6b6c     TEST       EAX,EAX
    //         004a6b6e     MOV        dword ptr [ESP + local_4],0x2
    //         004a6b79     JZ         LAB_004a6b83
    //         004a6b7b     PUSH       EDI
    //         004a6b7c     MOV        this,EAX
    //         004a6b7e     CALL       TRIBE_Dialog_Name::TRIBE_Dialog_Name             undefined TRIBE_Dialog_Name(TRIBE_Dialog_Name
    //                               LAB_004a6b83                                                 XREF[1]:     004a6b79(j)  
    //                              scr_name.cpp:271 (28)
    //         004a6b83     PUSH       0x0
    //         004a6b85     PUSH       s_New_Name_Dialog                                = 4Eh
    //         004a6b8a     MOV        this,panel_system
    //         004a6b8f     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a6b9a     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:272 (10)
    //         004a6b9f     MOV        EAX,0x1
    //         004a6ba4     JMP        LAB_004a6d27
    //                               LAB_004a6ba9                                                 XREF[2]:     004a6b54(j), 004a6b59(j)  
    //                              scr_name.cpp:276 (13)
    //         004a6ba9     CMP        EBP,dword ptr [EDI + 0x48c]
    //         004a6baf     JNZ        LAB_004a6c06
    //         004a6bb1     CMP        EBX,0x1
    //         004a6bb4     JNZ        LAB_004a6c06
    //                              scr_name.cpp:278 (5)
    //         004a6bb6     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //                              scr_name.cpp:279 (9)
    //         004a6bbb     CMP        EAX,-0x1
    //         004a6bbe     JZ         LAB_004a6d07
    //                              scr_name.cpp:282 (38)
    //         004a6bc4     MOV        this,dword ptr [EDI + 0x480]
    //         004a6bca     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
    //         004a6bcf     PUSH       EAX
    //                              language.dll match for 0x2a02: "Are you sure you want to remo
    //         004a6bd0     PUSH       0x2a02
    //         004a6bd5     MOV        this,EDI
    //         004a6bd7     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         004a6bdc     PUSH       EAX
    //         004a6bdd     LEA        EAX=>str[4],[ESP + 0x1c]
    //         004a6be1     PUSH       EAX
    //         004a6be2     CALL       sprintf                                          undefined sprintf()
    //         004a6be7     ADD        ESP,0xc
    //                              scr_name.cpp:283 (21)
    //         004a6bea     LEA        this=>str[4],[ESP + 0x14]
    //         004a6bee     PUSH       0x64
    //         004a6bf0     PUSH       0x1c2
    //         004a6bf5     PUSH       0x0
    //         004a6bf7     PUSH       this
    //         004a6bf8     MOV        this,EDI
    //         004a6bfa     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
    //                              scr_name.cpp:285 (7)
    //         004a6bff     MOV        EAX,EBX
    //         004a6c01     JMP        LAB_004a6d27
    //                               LAB_004a6c06                                                 XREF[2]:     004a6baf(j), 004a6bb4(j)  
    //                              scr_name.cpp:289 (68)
    //         004a6c06     MOV        this,EBP
    //         004a6c08     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004a6c0d     TEST       EAX,EAX
    //         004a6c0f     JZ         LAB_004a6c71
    //         004a6c11     MOV        this,EBP
    //         004a6c13     MOV        ESI,s_New_Name_Dialog                            = 4Eh
    //         004a6c18     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004a6c1d                                                 XREF[1]:     004a6c3b(j)  
    //         004a6c1d     MOV        DL,byte ptr [EAX]
    //         004a6c1f     MOV        this,DL
    //         004a6c21     CMP        DL,byte ptr [ESI]=>s_New_Name_Dialog             = 4Eh
    //                                                                                  = 77h
    //         004a6c23     JNZ        LAB_004a6c41
    //         004a6c25     TEST       this,this
    //         004a6c27     JZ         LAB_004a6c3d
    //         004a6c29     MOV        DL,byte ptr [EAX + 0x1]
    //         004a6c2c     MOV        this,DL
    //         004a6c2e     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00586c65            = 65h
    //                                                                                  = " Name Dialog"
    //         004a6c31     JNZ        LAB_004a6c41
    //         004a6c33     ADD        EAX,0x2
    //         004a6c36     ADD        ESI,0x2
    //         004a6c39     TEST       this,this
    //         004a6c3b     JNZ        LAB_004a6c1d
    //                               LAB_004a6c3d                                                 XREF[1]:     004a6c27(j)  
    //         004a6c3d     XOR        EAX,EAX
    //         004a6c3f     JMP        LAB_004a6c46
    //                               LAB_004a6c41                                                 XREF[2]:     004a6c23(j), 004a6c31(j)  
    //         004a6c41     SBB        EAX,EAX
    //         004a6c43     SBB        EAX,-0x1
    //                               LAB_004a6c46                                                 XREF[1]:     004a6c3f(j)  
    //         004a6c46     TEST       EAX,EAX
    //         004a6c48     JNZ        LAB_004a6c71
    //                              scr_name.cpp:291 (5)
    //         004a6c4a     CMP        EBX,0x1
    //         004a6c4d     JNZ        LAB_004a6c56
    //                              scr_name.cpp:294 (7)
    //         004a6c4f     MOV        this,EDI
    //         004a6c51     CALL       TRIBE_Screen_Name::get_player_names              void get_player_names(TRIBE_Screen_Name * this)
    //                               LAB_004a6c56                                                 XREF[1]:     004a6c4d(j)  
    //                              scr_name.cpp:296 (17)
    //         004a6c56     PUSH       0x0
    //         004a6c58     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004a6c5d     MOV        this,panel_system
    //         004a6c62     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:297 (5)
    //         004a6c67     PUSH       s_New_Name_Dialog                                = 4Eh
    //                              scr_name.cpp:299 (5)
    //         004a6c6c     JMP        LAB_004a6cf6
    //                               LAB_004a6c71                                                 XREF[2]:     004a6c0f(j), 004a6c48(j)  
    //                              scr_name.cpp:303 (72)
    //         004a6c71     MOV        this,EBP
    //         004a6c73     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         004a6c78     TEST       EAX,EAX
    //         004a6c7a     JZ         LAB_004a6d0e
    //         004a6c80     MOV        this,EBP
    //         004a6c82     MOV        ESI,s_YesNoDialog                                = 59h
    //         004a6c87     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_004a6c8c                                                 XREF[1]:     004a6caa(j)  
    //         004a6c8c     MOV        DL,byte ptr [EAX]
    //         004a6c8e     MOV        this,DL
    //         004a6c90     CMP        DL,byte ptr [ESI]=>s_YesNoDialog                 = 59h
    //                                                                                  = 73h
    //         004a6c92     JNZ        LAB_004a6cb0
    //         004a6c94     TEST       this,this
    //         004a6c96     JZ         LAB_004a6cac
    //         004a6c98     MOV        DL,byte ptr [EAX + 0x1]
    //         004a6c9b     MOV        this,DL
    //         004a6c9d     CMP        DL,byte ptr [ESI + 0x1]=>DAT_00584ec1            = 65h
    //                                                                                  = "NoDialog"
    //         004a6ca0     JNZ        LAB_004a6cb0
    //         004a6ca2     ADD        EAX,0x2
    //         004a6ca5     ADD        ESI,0x2
    //         004a6ca8     TEST       this,this
    //         004a6caa     JNZ        LAB_004a6c8c
    //                               LAB_004a6cac                                                 XREF[1]:     004a6c96(j)  
    //         004a6cac     XOR        EAX,EAX
    //         004a6cae     JMP        LAB_004a6cb5
    //                               LAB_004a6cb0                                                 XREF[2]:     004a6c92(j), 004a6ca0(j)  
    //         004a6cb0     SBB        EAX,EAX
    //         004a6cb2     SBB        EAX,-0x1
    //                               LAB_004a6cb5                                                 XREF[1]:     004a6cae(j)  
    //         004a6cb5     TEST       EAX,EAX
    //         004a6cb7     JNZ        LAB_004a6d0e
    //                              scr_name.cpp:305 (4)
    //         004a6cb9     TEST       EBX,EBX
    //         004a6cbb     JNZ        LAB_004a6cf1
    //                              scr_name.cpp:307 (11)
    //         004a6cbd     MOV        this,dword ptr [EDI + 0x480]
    //         004a6cc3     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //                              scr_name.cpp:308 (5)
    //         004a6cc8     CMP        EAX,-0x1
    //         004a6ccb     JZ         LAB_004a6cf1
    //                              scr_name.cpp:310 (29)
    //         004a6ccd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a6cd3     PUSH       EAX
    //         004a6cd4     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004a6cd7     MOV        this,dword ptr [EDI + 0x480]
    //         004a6cdd     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this, long param_1)
    //         004a6ce2     PUSH       EAX
    //         004a6ce3     MOV        this,ESI
    //         004a6ce5     CALL       RGE_Game_Info::remove_player                     void remove_player(RGE_Game_Info * this, long
    //                              scr_name.cpp:311 (7)
    //         004a6cea     MOV        this,EDI
    //         004a6cec     CALL       TRIBE_Screen_Name::get_player_names              void get_player_names(TRIBE_Screen_Name * this)
    //                               LAB_004a6cf1                                                 XREF[2]:     004a6cbb(j), 004a6ccb(j)  
    //                              scr_name.cpp:315 (15)
    //         004a6cf1     PUSH       s_YesNoDialog                                    = 59h
    //                               LAB_004a6cf6                                                 XREF[1]:     004a6c6c(j)  
    //         004a6cf6     MOV        this,panel_system
    //         004a6cfb     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_name.cpp:316 (7)
    //         004a6d00     MOV        this,EDI
    //         004a6d02     CALL       TRIBE_Screen_Name::setup_tab_order               void setup_tab_order(TRIBE_Screen_Name * this)
    //                               LAB_004a6d07                                                 XREF[1]:     004a6bbe(j)  
    //                              scr_name.cpp:317 (7)
    //         004a6d07     MOV        EAX,0x1
    //         004a6d0c     JMP        LAB_004a6d27
    //                               LAB_004a6d0e                                                 XREF[3]:     004a69e1(j), 004a6c7a(j), 
    //                                                                                                         004a6cb7(j)  
    //                              scr_name.cpp:321 (25)
    //         004a6d0e     MOV        EDX,dword ptr [ESP + param_4]
    //         004a6d15     MOV        EAX,dword ptr [ESP + param_3]
    //         004a6d1c     PUSH       EDX
    //         004a6d1d     PUSH       EAX
    //         004a6d1e     PUSH       EBX
    //         004a6d1f     PUSH       EBP
    //         004a6d20     MOV        this,EDI
    //         004a6d22     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                               LAB_004a6d27                                                 XREF[8]:     004a6a10(j), 004a6a92(j), 
    //                                                                                                         004a6b02(j), 004a6b1f(j), 
    //                                                                                                         004a6b49(j), 004a6ba4(j), 
    //                                                                                                         004a6c01(j), 004a6d0c(j)  
    //                              scr_name.cpp:322 (27)
    //         004a6d27     MOV        this,dword ptr [ESP + local_c]
    //         004a6d2e     POP        EDI
    //         004a6d2f     POP        ESI
    //         004a6d30     POP        EBP
    //         004a6d31     MOV        dword ptr FS:[0x0],this
    //         004a6d38     POP        EBX
    //         004a6d39     ADD        ESP,0x110
    //         004a6d3f     RET        0x10
    //         004a6d42     ??         90h
    //         004a6d43     NOP
    //         004a6d44     NOP
    //         004a6d45     NOP
    //         004a6d46     NOP
    //         004a6d47     NOP
    //         004a6d48     NOP
    //         004a6d49     NOP
    //         004a6d4a     NOP
    //         004a6d4b     NOP
    //         004a6d4c     NOP
    //         004a6d4d     NOP
    //         004a6d4e     NOP
    //         004a6d4f     NOP
    return 0;
}

TRIBE_Dialog_Name::TRIBE_Dialog_Name(TScreenPanel* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Dialog_Name(TRIBE_Dialog_Name * this, TSc
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Dialog_N    ECX:4 (auto)   this
    //              TScreenPanel *    Stack[0x4]:4   param_1                   XREF[1]:     004a6d7c(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a6d90(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a6f1c(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a6f09(W)  
    //              TPanel *[3]       Stack[-0x1c]   tab_list                  XREF[1,3]:   004a6d73(W), 004a6efa(W), 004a6efe(*), 004a6f02(W)  
    //                               ??0TRIBE_Dialog_Name@@QAE@PAVTScreenPanel@@@Z                XREF[2]:     action:004a6b7e(c), 
    //                               TRIBE_Dialog_Name::TRIBE_Dialog_Name                                      action:004b7049(c)  
    //                              scr_name.cpp:329 (44)
    //         004a6d50     PUSH       -0x1
    //         004a6d52     PUSH       FUN_0055f358
    //         004a6d57     MOV        EAX,FS:[0x0]
    //         004a6d5d     PUSH       EAX
    //         004a6d5e     MOV        dword ptr FS:[0x0],ESP
    //         004a6d65     SUB        ESP,0x10
    //         004a6d68     PUSH       EBX
    //         004a6d69     PUSH       EBP
    //         004a6d6a     PUSH       ESI
    //         004a6d6b     PUSH       EDI
    //         004a6d6c     MOV        ESI,this
    //         004a6d6e     PUSH       s_New_Name_Dialog                                = 4Eh
    //         004a6d73     MOV        dword ptr [ESP + tab_list[0]],ESI
    //         004a6d77     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //                              scr_name.cpp:336 (125)
    //         004a6d7c     MOV        EDI,dword ptr [ESP + param_1]
    //         004a6d80     LEA        EBP,[ESI + 0x490]
    //         004a6d86     LEA        EBX,[ESI + 0x498]
    //         004a6d8c     PUSH       0x1
    //         004a6d8e     MOV        this,EDI
    //         004a6d90     MOV        dword ptr [ESP + local_4],0x0
    //         004a6d98     MOV        dword ptr [ESI],TRIBE_Dialog_Name::`vftable'     = 004a6f40
    //         004a6d9e     MOV        dword ptr [EBP],0x0
    //         004a6da5     MOV        dword ptr [ESI + 0x494],0x0
    //         004a6daf     MOV        dword ptr [EBX],0x0
    //         004a6db5     MOV        dword ptr [ESI + 0x49c],0x0
    //         004a6dbf     MOV        dword ptr [ESI + 0x4a0],0x0
    //         004a6dc9     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         004a6dce     PUSH       EAX
    //         004a6dcf     MOV        this,EDI
    //         004a6dd1     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         004a6dd6     PUSH       EAX
    //         004a6dd7     PUSH       0xe6
    //         004a6ddc     PUSH       0x1f4
    //         004a6de1     PUSH       EDI
    //         004a6de2     MOV        this,EDI
    //         004a6de4     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         004a6de9     PUSH       EAX
    //         004a6dea     MOV        this,ESI
    //         004a6dec     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         004a6df1     TEST       EAX,EAX
    //         004a6df3     JZ         LAB_004a6f1c
    //                              scr_name.cpp:341 (41)
    //         004a6df9     PUSH       0x0
    //         004a6dfb     PUSH       0x1
    //         004a6dfd     PUSH       0x1
    //         004a6dff     PUSH       0x1
    //         004a6e01     PUSH       0x1e
    //         004a6e03     PUSH       0x1cc
    //         004a6e08     PUSH       0x14
    //         004a6e0a     PUSH       0x14
    //                              language.dll match for 0x2a03: "Name"
    //         004a6e0c     PUSH       0x2a03
    //         004a6e11     PUSH       EBP
    //         004a6e12     PUSH       ESI
    //         004a6e13     MOV        this,ESI
    //         004a6e15     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a6e1a     TEST       EAX,EAX
    //         004a6e1c     JZ         LAB_004a6f1c
    //                              scr_name.cpp:343 (47)
    //         004a6e22     PUSH       0x0
    //         004a6e24     PUSH       0x1
    //         004a6e26     PUSH       0x0
    //         004a6e28     PUSH       0x4
    //         004a6e2a     PUSH       0x14
    //         004a6e2c     PUSH       0x1a4
    //         004a6e31     PUSH       0x55
    //         004a6e33     PUSH       0x28
    //         004a6e35     LEA        EAX,[ESI + 0x494]
    //                              language.dll match for 0x2a04: "New Player"
    //         004a6e3b     PUSH       0x2a04
    //         004a6e40     PUSH       EAX
    //         004a6e41     PUSH       ESI
    //         004a6e42     MOV        this,ESI
    //         004a6e44     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a6e49     TEST       EAX,EAX
    //         004a6e4b     JZ         LAB_004a6f1c
    //                              scr_name.cpp:346 (43)
    //         004a6e51     PUSH       0x1
    //         004a6e53     PUSH       0x1
    //         004a6e55     PUSH       0xb
    //         004a6e57     PUSH       0x17
    //         004a6e59     PUSH       0x1a4
    //                              language.dll match for 0x6e: "Copperplate Gothic Light"
    //         004a6e5e     PUSH       0x6e
    //         004a6e60     PUSH       0x28
    //         004a6e62     PUSH       0x0
    //         004a6e64     PUSH       0xf
    //         004a6e66     PUSH       s_                                               = ""
    //         004a6e6b     PUSH       EBX
    //         004a6e6c     PUSH       ESI
    //         004a6e6d     MOV        this,ESI
    //         004a6e6f     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         004a6e74     TEST       EAX,EAX
    //         004a6e76     JZ         LAB_004a6f1c
    //                              scr_name.cpp:348 (46)
    //         004a6e7c     PUSH       0x0
    //         004a6e7e     PUSH       0x0
    //         004a6e80     PUSH       0x0
    //         004a6e82     PUSH       0x1e
    //         004a6e84     PUSH       0xb4
    //         004a6e89     PUSH       0xb4
    //         004a6e8e     PUSH       0x3c
    //         004a6e90     PUSH       0x0
    //         004a6e92     LEA        EBP,[ESI + 0x49c]
    //                              language.dll match for 0xfa1: "OK"
    //         004a6e98     PUSH       0xfa1
    //         004a6e9d     PUSH       EBP
    //         004a6e9e     PUSH       ESI
    //         004a6e9f     MOV        this,ESI
    //         004a6ea1     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a6ea6     TEST       EAX,EAX
    //         004a6ea8     JZ         LAB_004a6f1c
    //                              scr_name.cpp:349 (49)
    //         004a6eaa     PUSH       0x0
    //         004a6eac     PUSH       0x0
    //         004a6eae     PUSH       0x0
    //         004a6eb0     PUSH       0x1e
    //         004a6eb2     PUSH       0xb4
    //         004a6eb7     PUSH       0xb4
    //         004a6ebc     PUSH       0x104
    //         004a6ec1     PUSH       0x0
    //         004a6ec3     LEA        EDI,[ESI + 0x4a0]
    //                              language.dll match for 0xfa2: "Cancel"
    //         004a6ec9     PUSH       0xfa2
    //         004a6ece     PUSH       EDI
    //         004a6ecf     PUSH       ESI
    //         004a6ed0     MOV        this,ESI
    //         004a6ed2     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a6ed7     TEST       EAX,EAX
    //         004a6ed9     JZ         LAB_004a6f1c
    //                              scr_name.cpp:350 (2)
    //         004a6edb     MOV        EAX,dword ptr [EDI]
    //                              scr_name.cpp:357 (53)
    //         004a6edd     PUSH       0x3
    //         004a6edf     MOV        dword ptr [EAX + 0x298],0x1b
    //         004a6ee9     MOV        dword ptr [EAX + 0x29c],0x0
    //         004a6ef3     MOV        EAX,dword ptr [EBX]
    //         004a6ef5     MOV        this,dword ptr [EBP]
    //         004a6ef8     MOV        EDX,dword ptr [EDI]
    //         004a6efa     MOV        dword ptr [ESP + tab_list[1]],EAX
    //         004a6efe     LEA        EAX=>tab_list[1],[ESP + 0x18]
    //         004a6f02     MOV        dword ptr [ESP + tab_list[2]],this
    //         004a6f06     PUSH       EAX
    //         004a6f07     MOV        this,ESI
    //         004a6f09     MOV        dword ptr [ESP + local_10],EDX
    //         004a6f0d     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              scr_name.cpp:360 (10)
    //         004a6f12     MOV        this,dword ptr [EBX]
    //         004a6f14     PUSH       this
    //         004a6f15     MOV        this,ESI
    //         004a6f17     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004a6f1c                                                 XREF[6]:     004a6df3(j), 004a6e1c(j), 
    //                                                                                                         004a6e4b(j), 004a6e76(j), 
    //                                                                                                         004a6ea8(j), 004a6ed9(j)  
    //                              scr_name.cpp:361 (23)
    //         004a6f1c     MOV        this,dword ptr [ESP + local_c]
    //         004a6f20     MOV        EAX,ESI
    //         004a6f22     POP        EDI
    //         004a6f23     POP        ESI
    //         004a6f24     POP        EBP
    //         004a6f25     MOV        dword ptr FS:[0x0],this
    //         004a6f2c     POP        EBX
    //         004a6f2d     ADD        ESP,0x1c
    //         004a6f30     RET        0x4
    //         004a6f33     ??         90h
    //         004a6f34     NOP
    //         004a6f35     NOP
    //         004a6f36     NOP
    //         004a6f37     NOP
    //         004a6f38     NOP
    //         004a6f39     NOP
    //         004a6f3a     NOP
    //         004a6f3b     NOP
    //         004a6f3c     NOP
    //         004a6f3d     NOP
    //         004a6f3e     NOP
    //         004a6f3f     NOP
}

TRIBE_Dialog_Name::~TRIBE_Dialog_Name() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Dialog_Name(TRIBE_Dialog_Name * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Dialog_N    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a6f89(W), 004a6fd1(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a6fde(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a6f79(W)  
    //                               ??1TRIBE_Dialog_Name@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':004a6
    //                               TRIBE_Dialog_Name::~TRIBE_Dialog_Name
    //                              scr_name.cpp:367 (35)
    //         004a6f60     PUSH       -0x1
    //         004a6f62     PUSH       FUN_0055f378
    //         004a6f67     MOV        EAX,FS:[0x0]
    //         004a6f6d     PUSH       EAX
    //         004a6f6e     MOV        dword ptr FS:[0x0],ESP
    //         004a6f75     PUSH       this
    //         004a6f76     PUSH       ESI
    //         004a6f77     MOV        ESI,this
    //         004a6f79     MOV        dword ptr [ESP + local_10],ESI
    //         004a6f7d     MOV        dword ptr [ESI],TRIBE_Dialog_Name::`vftable'     = 004a6f40
    //                              scr_name.cpp:368 (20)
    //         004a6f83     LEA        EAX,[ESI + 0x490]
    //         004a6f89     MOV        dword ptr [ESP + local_4],0x0
    //         004a6f91     PUSH       EAX
    //         004a6f92     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:369 (14)
    //         004a6f97     LEA        this,[ESI + 0x494]
    //         004a6f9d     PUSH       this
    //         004a6f9e     MOV        this,ESI
    //         004a6fa0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:370 (14)
    //         004a6fa5     LEA        EDX,[ESI + 0x498]
    //         004a6fab     MOV        this,ESI
    //         004a6fad     PUSH       EDX
    //         004a6fae     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:371 (14)
    //         004a6fb3     LEA        EAX,[ESI + 0x49c]
    //         004a6fb9     MOV        this,ESI
    //         004a6fbb     PUSH       EAX
    //         004a6fbc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_name.cpp:372 (16)
    //         004a6fc1     LEA        this,[ESI + 0x4a0]
    //         004a6fc7     PUSH       this
    //         004a6fc8     MOV        this,ESI
    //         004a6fca     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004a6fcf     MOV        this,ESI
    //                              scr_name.cpp:373 (29)
    //         004a6fd1     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a6fd9     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         004a6fde     MOV        this,dword ptr [ESP + local_c]
    //         004a6fe2     POP        ESI
    //         004a6fe3     MOV        dword ptr FS:[0x0],this
    //         004a6fea     ADD        ESP,0x10
    //         004a6fed     RET
    //         004a6fee     ??         90h
    //         004a6fef     NOP
    //                              * public: virtual long __thiscall TRIBE_Dialog_Name::action(class TPanel *,long,unsigned long,unsign... *
    //                              long __thiscall action(TRIBE_Dialog_Name * this, TPanel * param_1, l
    //              long              EAX:4          <RETURN>
    //              TRIBE_Dialog_N    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[3]:     004a6ffe(R), 004a709b(W), 004a7148(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004a700c(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004a71a4(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004a719f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004a70a1(W), 004a70be(W), 004a714e(W), 004a7161(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[4]:     004a705f(R), 004a70ee(R), 004a718c(R), 004a71b2(R)  
    //                               ?action@TRIBE_Dialog_Name@@UAEJPAVTPanel@@JKK@Z              XREF[1]:     0057381c(*)  
    //                               TRIBE_Dialog_Name::action
    //                              scr_name.cpp:379 (14)
    //         004a6ff0     MOV        EAX,FS:[0x0]
    //         004a6ff6     PUSH       -0x1
    //         004a6ff8     PUSH       FUN_0055f3a6
    //         004a6ffd     PUSH       EAX
    //                              scr_name.cpp:380 (27)
    //         004a6ffe     MOV        EAX,dword ptr [ESP + param_1]
    //         004a7002     MOV        dword ptr FS:[0x0],ESP
    //         004a7009     PUSH       ESI
    //         004a700a     MOV        ESI,this
    //         004a700c     MOV        this,dword ptr [ESP + param_2]
    //         004a7010     PUSH       EDI
    //         004a7011     TEST       EAX,EAX
    //         004a7013     JZ         LAB_004a719f
    //                              scr_name.cpp:384 (35)
    //         004a7019     CMP        EAX,dword ptr [ESI + 0x49c]
    //         004a701f     JNZ        LAB_004a7026
    //         004a7021     CMP        this,0x1
    //         004a7024     JZ         LAB_004a703c
    //                               LAB_004a7026                                                 XREF[1]:     004a701f(j)  
    //         004a7026     MOV        EDX,dword ptr [ESI + 0x498]
    //         004a702c     CMP        EAX,EDX
    //         004a702e     JNZ        LAB_004a7101
    //         004a7034     TEST       this,this
    //         004a7036     JNZ        LAB_004a7101
    //                               LAB_004a703c                                                 XREF[1]:     004a7024(j)  
    //                              scr_name.cpp:386 (16)
    //         004a703c     MOV        this,dword ptr [ESI + 0x498]
    //         004a7042     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
    //         004a7047     CMP        byte ptr [EAX],0x0
    //         004a704a     JNZ        LAB_004a7072
    //                              scr_name.cpp:388 (14)
    //         004a704c     MOV        EAX,dword ptr [ESI + 0x498]
    //         004a7052     MOV        this,ESI
    //         004a7054     PUSH       EAX
    //         004a7055     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_name.cpp:389 (5)
    //         004a705a     MOV        EAX,0x1
    //                              scr_name.cpp:423 (19)
    //         004a705f     MOV        this,dword ptr [ESP + local_c]
    //         004a7063     MOV        dword ptr FS:[0x0],this
    //         004a706a     POP        EDI
    //         004a706b     POP        ESI
    //         004a706c     ADD        ESP,0xc
    //         004a706f     RET        0x10
    //                               LAB_004a7072                                                 XREF[1]:     004a704a(j)  
    //                              scr_name.cpp:392 (28)
    //         004a7072     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a7078     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004a707b     MOV        this,dword ptr [ESI + 0x498]
    //         004a7081     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
    //         004a7086     PUSH       EAX
    //         004a7087     MOV        this,EDI
    //         004a7089     CALL       RGE_Game_Info::add_new_person                    uchar add_new_person(RGE_Game_Info * this, ch
    //                              scr_name.cpp:395 (36)
    //         004a708e     PUSH       0x4cc
    //         004a7093     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a7098     ADD        ESP,0x4
    //         004a709b     MOV        dword ptr [ESP + param_1],EAX
    //         004a709f     TEST       EAX,EAX
    //         004a70a1     MOV        dword ptr [ESP + local_4],0x0
    //         004a70a9     JZ         LAB_004a70b2
    //         004a70ab     MOV        this,EAX
    //         004a70ad     CALL       TRIBE_Screen_Campaign_Selection::TRIBE_Screen_   undefined TRIBE_Screen_Campaign_Selection(TRI
    //                               LAB_004a70b2                                                 XREF[1]:     004a70a9(j)  
    //                              scr_name.cpp:396 (25)
    //         004a70b2     PUSH       0x0
    //         004a70b4     PUSH       s_Campaign_Selection_Screen                      = "Campaign Selection Screen"
    //         004a70b9     MOV        this,panel_system
    //         004a70be     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a70c6     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:397 (15)
    //         004a70cb     PUSH       s_New_Name_Dialog                                = 4Eh
    //         004a70d0     MOV        this,panel_system
    //         004a70d5     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_name.cpp:398 (15)
    //         004a70da     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004a70df     MOV        this,panel_system
    //         004a70e4     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_name.cpp:402 (5)
    //         004a70e9     MOV        EAX,0x1
    //                              scr_name.cpp:423 (19)
    //         004a70ee     MOV        this,dword ptr [ESP + local_c]
    //         004a70f2     MOV        dword ptr FS:[0x0],this
    //         004a70f9     POP        EDI
    //         004a70fa     POP        ESI
    //         004a70fb     ADD        ESP,0xc
    //         004a70fe     RET        0x10
    //                               LAB_004a7101                                                 XREF[2]:     004a702e(j), 004a7036(j)  
    //                              scr_name.cpp:407 (30)
    //         004a7101     CMP        EAX,dword ptr [ESI + 0x4a0]
    //         004a7107     JNZ        LAB_004a710e
    //         004a7109     CMP        this,0x1
    //         004a710c     JZ         LAB_004a711f
    //                               LAB_004a710e                                                 XREF[1]:     004a7107(j)  
    //         004a710e     CMP        EAX,EDX
    //         004a7110     JNZ        LAB_004a719f
    //         004a7116     CMP        this,0x1
    //         004a7119     JNZ        LAB_004a719f
    //                               LAB_004a711f                                                 XREF[1]:     004a710c(j)  
    //                              scr_name.cpp:409 (19)
    //         004a711f     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         004a7124     MOV        this,panel_system
    //         004a7129     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //         004a712e     TEST       EAX,EAX
    //         004a7130     JZ         LAB_004a713b
    //                              scr_name.cpp:410 (7)
    //         004a7132     PUSH       0x0
    //         004a7134     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //                              scr_name.cpp:411 (2)
    //         004a7139     JMP        LAB_004a716e
    //                               LAB_004a713b                                                 XREF[1]:     004a7130(j)  
    //                              scr_name.cpp:413 (36)
    //         004a713b     PUSH       0x49c
    //         004a7140     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004a7145     ADD        ESP,0x4
    //         004a7148     MOV        dword ptr [ESP + param_1],EAX
    //         004a714c     TEST       EAX,EAX
    //         004a714e     MOV        dword ptr [ESP + local_4],0x1
    //         004a7156     JZ         LAB_004a715f
    //         004a7158     MOV        this,EAX
    //         004a715a     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
    //                               LAB_004a715f                                                 XREF[1]:     004a7156(j)  
    //                              scr_name.cpp:414 (25)
    //         004a715f     PUSH       0x0
    //         004a7161     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004a7169     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //                               LAB_004a716e                                                 XREF[1]:     004a7139(j)  
    //         004a716e     MOV        this,panel_system
    //         004a7173     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_name.cpp:416 (15)
    //         004a7178     PUSH       s_New_Name_Dialog                                = 4Eh
    //         004a717d     MOV        this,panel_system
    //         004a7182     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_name.cpp:418 (5)
    //         004a7187     MOV        EAX,0x1
    //                              scr_name.cpp:423 (19)
    //         004a718c     MOV        this,dword ptr [ESP + local_c]
    //         004a7190     MOV        dword ptr FS:[0x0],this
    //         004a7197     POP        EDI
    //         004a7198     POP        ESI
    //         004a7199     ADD        ESP,0xc
    //         004a719c     RET        0x10
    //                               LAB_004a719f                                                 XREF[3]:     004a7013(j), 004a7110(j), 
    //                                                                                                         004a7119(j)  
    //                              scr_name.cpp:422 (19)
    //         004a719f     MOV        EDX,dword ptr [ESP + param_4]
    //         004a71a3     PUSH       EDX
    //         004a71a4     MOV        EDX,dword ptr [ESP + param_3]
    //         004a71a8     PUSH       EDX
    //         004a71a9     PUSH       this
    //         004a71aa     PUSH       EAX
    //         004a71ab     MOV        this,ESI
    //         004a71ad     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_name.cpp:423 (19)
    //         004a71b2     MOV        this,dword ptr [ESP + local_c]
    //         004a71b6     POP        EDI
    //         004a71b7     MOV        dword ptr FS:[0x0],this
    //         004a71be     POP        ESI
    //         004a71bf     ADD        ESP,0xc
    //         004a71c2     RET        0x10
    //         004a71c5     ??         90h
    //         004a71c6     NOP
    //         004a71c7     NOP
    //         004a71c8     NOP
    //         004a71c9     NOP
    //         004a71ca     NOP
    //         004a71cb     NOP
    //         004a71cc     NOP
    //         004a71cd     NOP
    //         004a71ce     NOP
    //         004a71cf     NOP
}

long TRIBE_Dialog_Name::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) {
    /* TODO: Stub */
    //                              long __thiscall wnd_proc(TRIBE_Dialog_Name * this, void * param_1, u
    //              long              EAX:4          <RETURN>
    //              TRIBE_Dialog_N    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004a71de(R)  
    //              uint              Stack[0x8]:4   param_2                   XREF[1]:     004a71d9(R)  
    //              uint              Stack[0xc]:4   param_3                   XREF[1]:     004a71d4(R)  
    //              long              Stack[0x10]:4  param_4                   XREF[1]:     004a71d0(R)  
    //                               ?wnd_proc@TRIBE_Dialog_Name@@UAEJPAXIIJ@Z                    XREF[1]:     005737b0(*)  
    //                               TRIBE_Dialog_Name::wnd_proc
    //                              scr_name.cpp:429 (25)
    //         004a71d0     MOV        EAX,dword ptr [ESP + param_4]
    //         004a71d4     MOV        EDX,dword ptr [ESP + param_3]
    //         004a71d8     PUSH       EAX
    //         004a71d9     MOV        EAX,dword ptr [ESP + param_2]
    //         004a71dd     PUSH       EDX
    //         004a71de     MOV        EDX,dword ptr [ESP + param_1]
    //         004a71e2     PUSH       EAX
    //         004a71e3     PUSH       EDX
    //         004a71e4     CALL       TPanel::wnd_proc                                 long wnd_proc(TPanel * this, void * param_1, 
    //                              scr_name.cpp:440 (3)
    //         004a71e9     RET        0x10
    //         004a71ec     ??         90h
    //         004a71ed     NOP
    //         004a71ee     NOP
    //         004a71ef     NOP
    //                              * public: __thiscall TribeSaveGameScreen::TribeSaveGameScreen(enum TribeSaveGameScreen::Mode,char *,... *
    //                              undefined __thiscall TribeSaveGameScreen(TribeSaveGameScreen * this,
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSaveGameS    ECX:4 (auto)   this
    //              Mode              Stack[0x4]:4   param_1                   XREF[1]:     004a7226(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[3]:     004a7233(R), 004a72ad(W), 004a73b0(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004a721f(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a7240(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a7581(R)  
    //              char[260]         Stack[-0x114   info_file                 XREF[1,2]:   004a7216(W), 004a72d0(*), 004a7300(*)  
    //              undefined4        Stack[-0x118   local_118                 XREF[1]:     004a7578(W)  
    //              TPanel *[5]       Stack[-0x12c   tabList                   XREF[2,5]:   004a72c0(W), 004a72f7(R), 004a755b(W), 004a756b(*), 
    //                                                                                     004a7565(W), 004a7561(W), 004a756f(W)  
    //              TEasy_Panel *     Stack[-0x130   from_panel
    //                               ??0TribeSaveGameScreen@@QAE@W4Mode@0@PADH@Z                  XREF[6]:     action:0043f77f(c), 
    //                               TribeSaveGameScreen::TribeSaveGameScreen                                  action:0043f7ee(c), 
    //                                                                                                         key_down_action:00497d3a(c), 
    //                                                                                                         command_save_game:0049cbe7(c), 
    //                                                                                                         command_save_scenario:0049cc77(c), 
    //                                                                                                         command_save_as:004ada28(c)  
    //                              scr_save.cpp:57 (47)
    //         004a71f0     PUSH       -0x1
    //         004a71f2     PUSH       FUN_0055f3bb
    //         004a71f7     MOV        EAX,FS:[0x0]
    //         004a71fd     PUSH       EAX
    //         004a71fe     MOV        dword ptr FS:[0x0],ESP
    //         004a7205     SUB        ESP,0x120
    //         004a720b     PUSH       EBX
    //         004a720c     PUSH       EBP
    //         004a720d     PUSH       ESI
    //         004a720e     PUSH       EDI
    //         004a720f     MOV        EBP,this
    //         004a7211     PUSH       s_Save_Game_Screen                               = "Save Game Screen"
    //         004a7216     MOV        dword ptr [ESP + info_file[0]],EBP
    //         004a721a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_save.cpp:66 (20)
    //         004a721f     MOV        this,dword ptr [ESP + param_3]
    //         004a7226     MOV        EAX,dword ptr [ESP + param_1]
    //         004a722d     MOV        dword ptr [EBP + 0x6a0],this
    //                              scr_save.cpp:69 (111)
    //         004a7233     MOV        this,dword ptr [ESP + param_2]
    //         004a723a     LEA        EBX,[EBP + 0x478]
    //         004a7240     MOV        dword ptr [ESP + local_4],0x0
    //         004a724b     TEST       this,this
    //         004a724d     MOV        dword ptr [EBP + 0x69c],EAX
    //         004a7253     MOV        dword ptr [EBP],TribeSaveGameScreen::`vftable'   = 004a75a0
    //         004a725a     MOV        dword ptr [EBX],0x0
    //         004a7260     MOV        dword ptr [EBP + 0x47c],0x0
    //         004a726a     MOV        dword ptr [EBP + 0x480],0x0
    //         004a7274     MOV        dword ptr [EBP + 0x484],0x0
    //         004a727e     MOV        dword ptr [EBP + 0x488],0x0
    //         004a7288     MOV        dword ptr [EBP + 0x48c],0x0
    //         004a7292     MOV        dword ptr [EBP + 0x490],0x0
    //         004a729c     JNZ        LAB_004a72b4
    //         004a729e     TEST       EAX,EAX
    //         004a72a0     JNZ        LAB_004a72b4
    //                              scr_save.cpp:70 (18)
    //         004a72a2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a72a8     CALL       TRIBE_Game::get_save_game_name                   char * get_save_game_name(TRIBE_Game * this)
    //         004a72ad     MOV        dword ptr [ESP + param_2],EAX
    //                               LAB_004a72b4                                                 XREF[2]:     004a729c(j), 004a72a0(j)  
    //                              scr_save.cpp:73 (10)
    //         004a72b4     MOV        this,panel_system
    //         004a72b9     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
    //                              scr_save.cpp:75 (28)
    //         004a72be     MOV        this,EAX
    //         004a72c0     MOV        dword ptr [ESP + tabList[0]],EAX
    //         004a72c4     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         004a72c9     MOV        EDI,EAX
    //         004a72cb     OR         this,0xffffffff
    //         004a72ce     XOR        EAX,EAX
    //         004a72d0     LEA        EDX=>info_file[4],[ESP + 0x2c]
    //         004a72d4     SCASB.RE   ES:EDI
    //         004a72d6     NOT        this
    //         004a72d8     SUB        EDI,this
    //                              scr_save.cpp:77 (56)
    //         004a72da     PUSH       0x1
    //         004a72dc     MOV        EAX,this
    //         004a72de     MOV        ESI,EDI
    //         004a72e0     MOV        EDI,EDX
    //         004a72e2     SHR        this,0x2
    //         004a72e5     MOVSD.REP  ES:EDI,ESI
    //         004a72e7     MOV        this,EAX
    //         004a72e9     AND        this,0x3
    //         004a72ec     MOVSB.REP  ES:EDI,ESI
    //         004a72ee     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a72f4     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         004a72f7     MOV        this,dword ptr [ESP + tabList[0]]
    //         004a72fb     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         004a7300     LEA        EDX=>info_file[4],[ESP + 0x30]
    //         004a7304     PUSH       EAX
    //         004a7305     PUSH       EDX
    //         004a7306     PUSH       ESI
    //         004a7307     MOV        this,EBP
    //         004a7309     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         004a730e     TEST       EAX,EAX
    //         004a7310     JNZ        LAB_004a7321
    //                              scr_save.cpp:78 (10)
    //         004a7312     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_save.cpp:79 (5)
    //         004a731c     JMP        LAB_004a7581
    //                               LAB_004a7321                                                 XREF[1]:     004a7310(j)  
    //                              scr_save.cpp:82 (9)
    //         004a7321     PUSH       0x0
    //         004a7323     MOV        this,EBP
    //         004a7325     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_save.cpp:83 (17)
    //         004a732a     PUSH       0x1e0
    //         004a732f     PUSH       0x280
    //         004a7334     MOV        this,EBP
    //         004a7336     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_save.cpp:88 (55)
    //         004a733b     MOV        EDX,dword ptr [EBP + 0x69c]
    //         004a7341     PUSH       0x0
    //         004a7343     PUSH       0x0
    //         004a7345     XOR        EAX,EAX
    //         004a7347     PUSH       0x1
    //         004a7349     PUSH       0x1
    //         004a734b     TEST       EDX,EDX
    //         004a734d     PUSH       0x1e
    //         004a734f     PUSH       0x258
    //         004a7354     SETNZ      AL
    //         004a7357     PUSH       0x14
    //         004a7359     ADD        EAX,0x24c3
    //         004a735e     PUSH       0x14
    //         004a7360     PUSH       EAX
    //         004a7361     PUSH       EBX
    //         004a7362     PUSH       EBP
    //         004a7363     MOV        this,EBP
    //         004a7365     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004a736a     TEST       EAX,EAX
    //         004a736c     JZ         LAB_004a7581
    //                              scr_save.cpp:96 (113)
    //         004a7372     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004a7378     XOR        EAX,EAX
    //         004a737a     LEA        EDX,[ECX + this->_padding_]
    //         004a7380     OR         this,0xffffffff
    //         004a7383     MOV        EDI,EDX
    //         004a7385     SCASB.RE   ES:EDI
    //         004a7387     NOT        this
    //         004a7389     DEC        this
    //         004a738a     MOV        EAX,0x7a
    //         004a738f     SUB        EAX,this
    //         004a7391     CMP        EAX,0x50
    //         004a7394     JBE        LAB_004a739d
    //         004a7396     MOV        EAX,0x50
    //         004a739b     JMP        LAB_004a73b0
    //                               LAB_004a739d                                                 XREF[1]:     004a7394(j)  
    //         004a739d     MOV        EDI,EDX
    //         004a739f     OR         this,0xffffffff
    //         004a73a2     XOR        EAX,EAX
    //         004a73a4     SCASB.RE   ES:EDI
    //         004a73a6     NOT        this
    //         004a73a8     DEC        this
    //         004a73a9     MOV        EAX,0x7a
    //         004a73ae     SUB        EAX,this
    //                               LAB_004a73b0                                                 XREF[1]:     004a739b(j)  
    //         004a73b0     MOV        this,dword ptr [ESP + param_2]
    //         004a73b7     PUSH       0x1
    //         004a73b9     PUSH       0x1
    //         004a73bb     PUSH       0xb
    //         004a73bd     PUSH       0x17
    //         004a73bf     PUSH       0x258
    //         004a73c4     PUSH       0x46
    //         004a73c6     PUSH       0x14
    //         004a73c8     PUSH       0x5
    //         004a73ca     PUSH       EAX
    //         004a73cb     LEA        ESI,[EBP + 0x47c]
    //         004a73d1     PUSH       this
    //         004a73d2     PUSH       ESI
    //         004a73d3     PUSH       EBP
    //         004a73d4     MOV        this,EBP
    //         004a73d6     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel * 
    //         004a73db     TEST       EAX,EAX
    //         004a73dd     JZ         LAB_004a7581
    //                              scr_save.cpp:97 (14)
    //         004a73e3     MOV        this,dword ptr [ESI]
    //         004a73e5     PUSH       -0x1
    //                              language.dll match for 0x7670: "Type a name for the game."
    //         004a73e7     PUSH       0x7670
    //         004a73ec     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_save.cpp:100 (39)
    //         004a73f1     PUSH       0xb
    //         004a73f3     PUSH       0x12c
    //         004a73f8     PUSH       0x258
    //                              language.dll match for 0x6e: "Copperplate Gothic Light"
    //         004a73fd     PUSH       0x6e
    //         004a73ff     LEA        ESI,[EBP + 0x480]
    //         004a7405     PUSH       0x14
    //         004a7407     PUSH       ESI
    //         004a7408     PUSH       EBP
    //         004a7409     MOV        this,EBP
    //         004a740b     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         004a7410     TEST       EAX,EAX
    //         004a7412     JZ         LAB_004a7581
    //                              scr_save.cpp:101 (27)
    //         004a7418     MOV        EDX,dword ptr [ESI]
    //         004a741a     PUSH       0x14
    //         004a741c     LEA        ESI,[EBP + 0x484]
    //         004a7422     PUSH       EDX
    //         004a7423     PUSH       ESI
    //         004a7424     MOV        this,EBP
    //         004a7426     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004a742b     TEST       EAX,EAX
    //         004a742d     JZ         LAB_004a7581
    //                              scr_save.cpp:102 (14)
    //         004a7433     MOV        this,dword ptr [ESI]
    //         004a7435     PUSH       -0x1
    //                              language.dll match for 0x7671: "Select a saved game."
    //         004a7437     PUSH       0x7671
    //         004a743c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_save.cpp:105 (50)
    //         004a7441     PUSH       0x0
    //         004a7443     PUSH       0x0
    //         004a7445     PUSH       0x0
    //         004a7447     PUSH       0x1e
    //         004a7449     PUSH       0xb4
    //         004a744e     PUSH       0x1b8
    //         004a7453     PUSH       0x1e
    //         004a7455     PUSH       0x0
    //         004a7457     LEA        ESI,[EBP + 0x488]
    //                              language.dll match for 0xfa1: "OK"
    //         004a745d     PUSH       0xfa1
    //         004a7462     PUSH       ESI
    //         004a7463     PUSH       EBP
    //         004a7464     MOV        this,EBP
    //         004a7466     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a746b     TEST       EAX,EAX
    //         004a746d     JZ         LAB_004a7581
    //                              scr_save.cpp:106 (53)
    //         004a7473     PUSH       0x0
    //         004a7475     PUSH       0x0
    //         004a7477     PUSH       0x0
    //         004a7479     PUSH       0x1e
    //         004a747b     PUSH       0xb4
    //         004a7480     PUSH       0x1b8
    //         004a7485     PUSH       0xe6
    //         004a748a     PUSH       0x0
    //         004a748c     LEA        EBX,[EBP + 0x490]
    //                              language.dll match for 0x24c9: "Delete"
    //         004a7492     PUSH       0x24c9
    //         004a7497     PUSH       EBX
    //         004a7498     PUSH       EBP
    //         004a7499     MOV        this,EBP
    //         004a749b     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a74a0     TEST       EAX,EAX
    //         004a74a2     JZ         LAB_004a7581
    //                              scr_save.cpp:107 (53)
    //         004a74a8     PUSH       0x0
    //         004a74aa     PUSH       0x0
    //         004a74ac     PUSH       0x0
    //         004a74ae     PUSH       0x1e
    //         004a74b0     PUSH       0xb4
    //         004a74b5     PUSH       0x1b8
    //         004a74ba     PUSH       0x1ae
    //         004a74bf     PUSH       0x0
    //         004a74c1     LEA        EDI,[EBP + 0x48c]
    //                              language.dll match for 0xfa2: "Cancel"
    //         004a74c7     PUSH       0xfa2
    //         004a74cc     PUSH       EDI
    //         004a74cd     PUSH       EBP
    //         004a74ce     MOV        this,EBP
    //         004a74d0     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004a74d5     TEST       EAX,EAX
    //         004a74d7     JZ         LAB_004a7581
    //                              scr_save.cpp:108 (14)
    //         004a74dd     MOV        this,dword ptr [ESI]
    //         004a74df     PUSH       -0x1
    //         004a74e1     PUSH       0x7531
    //         004a74e6     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_save.cpp:109 (14)
    //         004a74eb     MOV        this,dword ptr [EDI]
    //         004a74ed     PUSH       -0x1
    //         004a74ef     PUSH       0x7532
    //         004a74f4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_save.cpp:111 (20)
    //         004a74f9     MOV        EAX,dword ptr [EDI]
    //         004a74fb     XOR        this,this
    //         004a74fd     MOV        dword ptr [EAX + 0x298],0x1b
    //         004a7507     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_save.cpp:112 (8)
    //         004a750d     MOV        EAX,dword ptr [EBX]
    //         004a750f     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_save.cpp:115 (17)
    //         004a7515     MOV        this,EBP
    //         004a7517     MOV        dword ptr [EAX + 0x298],0x2e
    //         004a7521     CALL       TribeSaveGameScreen::fillList                    void fillList(TribeSaveGameScreen * this)
    //                              scr_save.cpp:117 (16)
    //         004a7526     MOV        this,dword ptr [EBP + 0x480]
    //         004a752c     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         004a7531     CMP        byte ptr [EAX],0x0
    //         004a7534     JNZ        LAB_004a753f
    //                              scr_save.cpp:118 (9)
    //         004a7536     MOV        this,dword ptr [EBX]
    //         004a7538     PUSH       0x1
    //         004a753a     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_004a753f                                                 XREF[1]:     004a7534(j)  
    //                              scr_save.cpp:121 (14)
    //         004a753f     MOV        EAX,dword ptr [EBP + 0x47c]
    //         004a7545     MOV        this,EBP
    //         004a7547     PUSH       EAX
    //         004a7548     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_save.cpp:124 (6)
    //         004a754d     MOV        this,dword ptr [EBP + 0x47c]
    //                              scr_save.cpp:126 (12)
    //         004a7553     MOV        EAX,dword ptr [ESI]
    //         004a7555     MOV        EDX,dword ptr [EBP + 0x480]
    //         004a755b     MOV        dword ptr [ESP + tabList[1]],this
    //                              scr_save.cpp:127 (10)
    //         004a755f     MOV        this,dword ptr [EBX]
    //         004a7561     MOV        dword ptr [ESP + tabList[3]],EAX
    //         004a7565     MOV        dword ptr [ESP + tabList[2]],EDX
    //                              scr_save.cpp:128 (2)
    //         004a7569     MOV        EDX,dword ptr [EDI]
    //                              scr_save.cpp:129 (22)
    //         004a756b     LEA        EAX=>tabList[1],[ESP + 0x14]
    //         004a756f     MOV        dword ptr [ESP + tabList[4]],this
    //         004a7573     PUSH       0x5
    //         004a7575     PUSH       EAX
    //         004a7576     MOV        this,EBP
    //         004a7578     MOV        dword ptr [ESP + local_118],EDX
    //         004a757c     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_004a7581                                                 XREF[8]:     004a731c(j), 004a736c(j), 
    //                                                                                                         004a73dd(j), 004a7412(j), 
    //                                                                                                         004a742d(j), 004a746d(j), 
    //                                                                                                         004a74a2(j), 004a74d7(j)  
    //                              scr_save.cpp:130 (29)
    //         004a7581     MOV        this,dword ptr [ESP + local_c]
    //         004a7588     POP        EDI
    //         004a7589     MOV        EAX,EBP
    //         004a758b     POP        ESI
    //         004a758c     POP        EBP
    //         004a758d     MOV        dword ptr FS:[0x0],this
    //         004a7594     POP        EBX
    //         004a7595     ADD        ESP,0x12c
    //         004a759b     RET        0xc
    //         004a759e     ??         90h
    //         004a759f     NOP
    return 0;
}

long TRIBE_Screen_Name::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

long TRIBE_Dialog_Name::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

