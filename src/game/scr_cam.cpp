#include "../common.h"
#include "scr_cam.h"

TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen() {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Campaign_Editor_Screen(TRIBE_Campaign_Edi
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048f610(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0048f6a7(R), 0048fa04(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0048f9c6(W)
//              TPanel *[8]       Stack[-0x30]   tabList                   XREF[1,8]:   0048f5f3(W), 0048f986(W), 0048f9b9(*), 0048f990(W),
//                                                                                     0048f99a(W), 0048f9a1(W), 0048f9a5(W), 0048f9b5(W),
//                                                                                     0048f9c2(W)
//                               ??0TRIBE_Campaign_Editor_Screen@@QAE@XZ                      XREF[1]:     action:004b32bf(c)
//                               TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen
//                              scr_cam.cpp:59 (44)
//         0048f5d0     PUSH       -0x1
//         0048f5d2     PUSH       FUN_0055e888
//         0048f5d7     MOV        EAX,FS:[0x0]
//         0048f5dd     PUSH       EAX
//         0048f5de     MOV        dword ptr FS:[0x0],ESP
//         0048f5e5     SUB        ESP,0x24
//         0048f5e8     PUSH       EBX
//         0048f5e9     PUSH       EBP
//         0048f5ea     PUSH       ESI
//         0048f5eb     PUSH       EDI
//         0048f5ec     MOV        ESI,this
//         0048f5ee     PUSH       s_Campaign_Editor_Screen                         = "Campaign Editor Screen"
//         0048f5f3     MOV        dword ptr [ESP + tabList[0]],ESI
//         0048f5f7     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//                              scr_cam.cpp:65 (6)
//         0048f5fc     LEA        EBX,[ESI + 0x48c]
//                              scr_cam.cpp:68 (6)
//         0048f602     LEA        EBP,[ESI + 0x490]
//                              scr_cam.cpp:76 (91)
//         0048f608     LEA        EDI,[ESI + 0x4bc]
//         0048f60e     XOR        EAX,EAX
//         0048f610     MOV        dword ptr [ESP + local_4],EAX
//         0048f614     MOV        dword ptr [ESI],TRIBE_Campaign_Editor_Screen::   = 0048fa20
//         0048f61a     MOV        dword ptr [ESI + 0x47c],EAX
//         0048f620     MOV        dword ptr [ESI + 0x484],EAX
//         0048f626     MOV        dword ptr [EBX],EAX
//         0048f628     MOV        dword ptr [ESI + 0x494],EAX
//         0048f62e     MOV        dword ptr [ESI + 0x488],EAX
//         0048f634     MOV        dword ptr [EBP],EAX
//         0048f637     MOV        dword ptr [ESI + 0x498],EAX
//         0048f63d     MOV        dword ptr [ESI + 0x480],EAX
//         0048f643     MOV        dword ptr [ESI + 0x49c],EAX
//         0048f649     MOV        dword ptr [ESI + 0x4a4],EAX
//         0048f64f     MOV        dword ptr [ESI + 0x4a8],EAX
//         0048f655     MOV        dword ptr [ESI + 0x4a0],EAX
//         0048f65b     MOV        dword ptr [ESI + 0x4c0],EAX
//         0048f661     MOV        dword ptr [EDI],EAX
//                              scr_cam.cpp:77 (6)
//         0048f663     MOV        dword ptr [ESI + 0x4ac],EAX
//                              scr_cam.cpp:78 (6)
//         0048f669     MOV        dword ptr [ESI + 0x4b0],EAX
//                              scr_cam.cpp:79 (6)
//         0048f66f     MOV        dword ptr [ESI + 0x4b4],EAX
//                              scr_cam.cpp:80 (6)
//         0048f675     MOV        dword ptr [ESI + 0x4b8],EAX
//                              scr_cam.cpp:84 (32)
//         0048f67b     MOV        EAX,[rge_base_game]                              = 00000000
//         0048f680     PUSH       0x1
//         0048f682     PUSH       0xc386
//         0048f687     PUSH       s_scr4                                           = "scr4"
//         0048f68c     MOV        this,dword ptr [EAX + 0x4c]
//         0048f68f     PUSH       this
//         0048f690     MOV        this,ESI
//         0048f692     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         0048f697     TEST       EAX,EAX
//         0048f699     JNZ        LAB_0048f6ba
//                              scr_cam.cpp:86 (10)
//         0048f69b     MOV        dword ptr [ESI + 0xd8],0x1
//                              scr_cam.cpp:144 (21)
//         0048f6a5     MOV        EAX,ESI
//         0048f6a7     MOV        this,dword ptr [ESP + local_c]
//         0048f6ab     MOV        dword ptr FS:[0x0],this
//         0048f6b2     POP        EDI
//         0048f6b3     POP        ESI
//         0048f6b4     POP        EBP
//         0048f6b5     POP        EBX
//         0048f6b6     ADD        ESP,0x30
//         0048f6b9     RET
//                               LAB_0048f6ba                                                 XREF[1]:     0048f699(j)
//                              scr_cam.cpp:90 (9)
//         0048f6ba     PUSH       0x0
//         0048f6bc     MOV        this,ESI
//         0048f6be     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
//                              scr_cam.cpp:91 (17)
//         0048f6c3     PUSH       0x1e0
//         0048f6c8     PUSH       0x280
//         0048f6cd     MOV        this,ESI
//         0048f6cf     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_cam.cpp:95 (39)
//         0048f6d4     PUSH       0x0
//         0048f6d6     PUSH       0x0
//         0048f6d8     PUSH       0x3
//         0048f6da     PUSH       0x1
//         0048f6dc     PUSH       0x32
//         0048f6de     PUSH       0x26c
//         0048f6e3     PUSH       0xa
//         0048f6e5     PUSH       0xa
//         0048f6e7     LEA        EAX,[ESI + 0x47c]
//                              language.dll match for 0x2bc1: "Campaign Editor"
//         0048f6ed     PUSH       0x2bc1
//         0048f6f2     PUSH       EAX
//         0048f6f3     PUSH       ESI
//         0048f6f4     MOV        this,ESI
//         0048f6f6     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:97 (39)
//         0048f6fb     PUSH       0x0
//         0048f6fd     PUSH       0x0
//         0048f6ff     PUSH       0x0
//         0048f701     PUSH       0x4
//         0048f703     PUSH       0x14
//         0048f705     PUSH       0x104
//         0048f70a     PUSH       0x28
//         0048f70c     PUSH       0x14
//         0048f70e     LEA        EAX,[ESI + 0x480]
//                              language.dll match for 0x2bc2: "Campaign Filename "
//         0048f714     PUSH       0x2bc2
//         0048f719     PUSH       EAX
//         0048f71a     PUSH       ESI
//         0048f71b     MOV        this,ESI
//         0048f71d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:98 (49)
//         0048f722     MOV        EAX,dword ptr [ESI + 0xf8]
//         0048f728     PUSH       0xb
//         0048f72a     MOV        this,ESI
//         0048f72c     LEA        EAX,[EAX + EAX*0x2]
//         0048f72f     LEA        EAX,[EAX + EAX*0x4]
//         0048f732     SHL        EAX,0x1
//         0048f734     CDQ
//         0048f735     IDIV       dword ptr [ESI + 0x18]
//         0048f738     PUSH       EAX
//         0048f739     PUSH       0x17c
//         0048f73e     PUSH       0x3c
//         0048f740     PUSH       0x14
//         0048f742     PUSH       0xc8
//         0048f747     PUSH       0x17c
//         0048f74c     PUSH       EDI
//         0048f74d     PUSH       ESI
//         0048f74e     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
//                              scr_cam.cpp:100 (51)
//         0048f753     PUSH       0x1
//         0048f755     PUSH       0x1
//         0048f757     PUSH       0xb
//         0048f759     PUSH       0x1e
//         0048f75b     PUSH       0x168
//         0048f760     PUSH       0x0
//         0048f762     PUSH       0x0
//         0048f764     PUSH       0x5
//         0048f766     PUSH       0x64
//                              language.dll match for 0x2bca: "default campaign"
//         0048f768     PUSH       0x2bca
//         0048f76d     MOV        this,ESI
//         0048f76f     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0048f774     MOV        EDX,dword ptr [EDI]
//         0048f776     PUSH       EAX
//         0048f777     LEA        EAX,[ESI + 0x49c]
//         0048f77d     MOV        this,ESI
//         0048f77f     PUSH       EAX
//         0048f780     PUSH       EDX
//         0048f781     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:102 (42)
//         0048f786     PUSH       0x0
//         0048f788     PUSH       0x0
//         0048f78a     PUSH       0x0
//         0048f78c     PUSH       0x1e
//         0048f78e     PUSH       0xc8
//         0048f793     PUSH       0x3c
//         0048f795     PUSH       0x1a4
//         0048f79a     PUSH       0x0
//                              language.dll match for 0x2bc4: "Save"
//         0048f79c     PUSH       0x2bc4
//         0048f7a1     LEA        EAX,[ESI + 0x4a8]
//         0048f7a7     PUSH       EAX
//         0048f7a8     PUSH       ESI
//         0048f7a9     MOV        this,ESI
//         0048f7ab     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:103 (45)
//         0048f7b0     PUSH       0x0
//         0048f7b2     PUSH       0x0
//         0048f7b4     PUSH       0x0
//         0048f7b6     PUSH       0x1e
//         0048f7b8     PUSH       0xa0
//         0048f7bd     PUSH       0x104
//         0048f7c2     PUSH       0x118
//         0048f7c7     PUSH       0x0
//         0048f7c9     LEA        EAX,[ESI + 0x4ac]
//                              language.dll match for 0x2bc5: "Add"
//         0048f7cf     PUSH       0x2bc5
//         0048f7d4     PUSH       EAX
//         0048f7d5     PUSH       ESI
//         0048f7d6     MOV        this,ESI
//         0048f7d8     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:104 (45)
//         0048f7dd     PUSH       0x0
//         0048f7df     PUSH       0x0
//         0048f7e1     PUSH       0x0
//         0048f7e3     PUSH       0x1e
//         0048f7e5     PUSH       0xa0
//         0048f7ea     PUSH       0x104
//         0048f7ef     PUSH       0x1cc
//         0048f7f4     PUSH       0x0
//         0048f7f6     LEA        EAX,[ESI + 0x4b0]
//                              language.dll match for 0x2bc6: "Remove"
//         0048f7fc     PUSH       0x2bc6
//         0048f801     PUSH       EAX
//         0048f802     PUSH       ESI
//         0048f803     MOV        this,ESI
//         0048f805     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:106 (39)
//         0048f80a     PUSH       0x0
//         0048f80c     PUSH       0x0
//         0048f80e     PUSH       0x0
//         0048f810     PUSH       0x4
//         0048f812     PUSH       0x14
//         0048f814     PUSH       0xc8
//         0048f819     PUSH       0x64
//         0048f81b     PUSH       0x14
//         0048f81d     LEA        EAX,[ESI + 0x484]
//                              language.dll match for 0x2bc7: "Scenarios"
//         0048f823     PUSH       0x2bc7
//         0048f828     PUSH       EAX
//         0048f829     PUSH       ESI
//         0048f82a     MOV        this,ESI
//         0048f82c     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:107 (25)
//         0048f831     PUSH       0xb
//         0048f833     PUSH       0x82
//         0048f838     PUSH       0x258
//                              language.dll match for 0x78: "10"
//         0048f83d     PUSH       0x78
//         0048f83f     PUSH       0x14
//         0048f841     PUSH       EBX
//         0048f842     PUSH       ESI
//         0048f843     MOV        this,ESI
//         0048f845     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:108 (19)
//         0048f84a     MOV        EAX,dword ptr [EBX]
//         0048f84c     PUSH       0x14
//         0048f84e     PUSH       EAX
//         0048f84f     LEA        EAX,[ESI + 0x494]
//         0048f855     PUSH       EAX
//         0048f856     MOV        this,ESI
//         0048f858     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
//                              scr_cam.cpp:110 (42)
//         0048f85d     PUSH       0x0
//         0048f85f     PUSH       0x0
//         0048f861     PUSH       0x0
//         0048f863     PUSH       0x4
//         0048f865     PUSH       0x14
//         0048f867     PUSH       0xc8
//         0048f86c     PUSH       0x118
//         0048f871     PUSH       0x14
//         0048f873     LEA        EAX,[ESI + 0x488]
//                              language.dll match for 0x2bc8: "Campaign Scenarios"
//         0048f879     PUSH       0x2bc8
//         0048f87e     PUSH       EAX
//         0048f87f     PUSH       ESI
//         0048f880     MOV        this,ESI
//         0048f882     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:111 (28)
//         0048f887     PUSH       0xb
//                              language.dll match for 0x82: "B"
//         0048f889     PUSH       0x82
//         0048f88e     PUSH       0x1f4
//         0048f893     PUSH       0x12c
//         0048f898     PUSH       0x14
//         0048f89a     PUSH       EBP
//         0048f89b     PUSH       ESI
//         0048f89c     MOV        this,ESI
//         0048f89e     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel *
//                              scr_cam.cpp:112 (20)
//         0048f8a3     MOV        this,dword ptr [EBP]
//         0048f8a6     PUSH       0x14
//         0048f8a8     LEA        EAX,[ESI + 0x498]
//         0048f8ae     PUSH       this
//         0048f8af     PUSH       EAX
//         0048f8b0     MOV        this,ESI
//         0048f8b2     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
//                              scr_cam.cpp:114 (42)
//         0048f8b7     PUSH       0x0
//         0048f8b9     PUSH       0x0
//         0048f8bb     PUSH       0x0
//         0048f8bd     PUSH       0x1e
//         0048f8bf     PUSH       0x118
//         0048f8c4     PUSH       0x1bd
//         0048f8c9     PUSH       0x14
//         0048f8cb     PUSH       0x0
//         0048f8cd     LEA        EAX,[ESI + 0x4a0]
//                              language.dll match for 0xfa1: "OK"
//         0048f8d3     PUSH       0xfa1
//         0048f8d8     PUSH       EAX
//         0048f8d9     PUSH       ESI
//         0048f8da     MOV        this,ESI
//         0048f8dc     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:115 (45)
//         0048f8e1     PUSH       0x0
//         0048f8e3     PUSH       0x0
//         0048f8e5     PUSH       0x0
//         0048f8e7     PUSH       0x1e
//         0048f8e9     PUSH       0x118
//         0048f8ee     PUSH       0x1bd
//         0048f8f3     PUSH       0x154
//         0048f8f8     PUSH       0x0
//         0048f8fa     LEA        EAX,[ESI + 0x4a4]
//                              language.dll match for 0xfa2: "Cancel"
//         0048f900     PUSH       0xfa2
//         0048f905     PUSH       EAX
//         0048f906     PUSH       ESI
//         0048f907     MOV        this,ESI
//         0048f909     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:116 (6)
//         0048f90e     MOV        EAX,dword ptr [ESI + 0x4a4]
//                              scr_cam.cpp:118 (62)
//         0048f914     PUSH       0x0
//         0048f916     PUSH       0x0
//         0048f918     PUSH       0x0
//         0048f91a     PUSH       0x1e
//         0048f91c     PUSH       0x5a
//         0048f91e     PUSH       0x12c
//         0048f923     MOV        dword ptr [EAX + 0x298],0x1b
//         0048f92d     MOV        dword ptr [EAX + 0x29c],0x0
//         0048f937     PUSH       0x212
//         0048f93c     PUSH       0x0
//         0048f93e     LEA        EAX,[ESI + 0x4b4]
//                              language.dll match for 0x2bd5: "Up"
//         0048f944     PUSH       0x2bd5
//         0048f949     PUSH       EAX
//         0048f94a     PUSH       ESI
//         0048f94b     MOV        this,ESI
//         0048f94d     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:119 (42)
//         0048f952     PUSH       0x0
//         0048f954     PUSH       0x0
//         0048f956     PUSH       0x0
//         0048f958     PUSH       0x1e
//         0048f95a     PUSH       0x5a
//         0048f95c     PUSH       0x154
//         0048f961     PUSH       0x212
//         0048f966     PUSH       0x0
//         0048f968     LEA        EAX,[ESI + 0x4b8]
//                              language.dll match for 0x2bd6: "Down"
//         0048f96e     PUSH       0x2bd6
//         0048f973     PUSH       EAX
//         0048f974     PUSH       ESI
//         0048f975     MOV        this,ESI
//         0048f977     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              scr_cam.cpp:122 (2)
//         0048f97c     MOV        EDX,dword ptr [EDI]
//                              scr_cam.cpp:123 (6)
//         0048f97e     MOV        EAX,dword ptr [ESI + 0x4a8]
//                              scr_cam.cpp:124 (6)
//         0048f984     MOV        this,dword ptr [EBX]
//         0048f986     MOV        dword ptr [ESP + tabList[1]],EDX
//                              scr_cam.cpp:125 (10)
//         0048f98a     MOV        EDX,dword ptr [ESI + 0x4ac]
//         0048f990     MOV        dword ptr [ESP + tabList[2]],EAX
//                              scr_cam.cpp:126 (10)
//         0048f994     MOV        EAX,dword ptr [ESI + 0x4b0]
//         0048f99a     MOV        dword ptr [ESP + tabList[3]],this
//                              scr_cam.cpp:127 (11)
//         0048f99e     MOV        this,dword ptr [EBP]
//         0048f9a1     MOV        dword ptr [ESP + tabList[4]],EDX
//         0048f9a5     MOV        dword ptr [ESP + tabList[5]],EAX
//                              scr_cam.cpp:128 (6)
//         0048f9a9     MOV        EDX,dword ptr [ESI + 0x4a0]
//                              scr_cam.cpp:129 (10)
//         0048f9af     MOV        EAX,dword ptr [ESI + 0x4a4]
//         0048f9b5     MOV        dword ptr [ESP + tabList[6]],this
//                              scr_cam.cpp:130 (22)
//         0048f9b9     LEA        this=>tabList[1],[ESP + 0x14]
//         0048f9bd     PUSH       0x8
//         0048f9bf     PUSH       this
//         0048f9c0     MOV        this,ESI
//         0048f9c2     MOV        dword ptr [ESP + tabList[7]],EDX
//         0048f9c6     MOV        dword ptr [ESP + local_10],EAX
//         0048f9ca     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * *
//                              scr_cam.cpp:132 (14)
//         0048f9cf     MOV        EDX,dword ptr [ESI + 0x49c]
//         0048f9d5     MOV        this,dword ptr [EDI]
//         0048f9d7     PUSH       EDX
//         0048f9d8     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_cam.cpp:133 (10)
//         0048f9dd     MOV        EAX,dword ptr [EDI]
//         0048f9df     MOV        this,ESI
//         0048f9e1     PUSH       EAX
//         0048f9e2     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_cam.cpp:136 (7)
//         0048f9e7     MOV        this,ESI
//         0048f9e9     CALL       TRIBE_Campaign_Editor_Screen::fill_scenario_list void fill_scenario_list(TRIBE_Campaign_Editor
//                              scr_cam.cpp:137 (7)
//         0048f9ee     MOV        this,ESI
//         0048f9f0     CALL       TRIBE_Campaign_Editor_Screen::fill_campaign_drop void fill_campaign_drop(TRIBE_Campaign_Editor
//                              scr_cam.cpp:138 (8)
//         0048f9f5     MOV        this,dword ptr [EBP]
//         0048f9f8     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                              scr_cam.cpp:139 (7)
//         0048f9fd     MOV        this,ESI
//         0048f9ff     CALL       TRIBE_Campaign_Editor_Screen::load_campaign      void load_campaign(TRIBE_Campaign_Editor_Scre
//                              scr_cam.cpp:144 (28)
//         0048fa04     MOV        this,dword ptr [ESP + local_c]
//         0048fa08     MOV        byte ptr [ESI + 0x478],0x0
//         0048fa0f     MOV        EAX,ESI
//         0048fa11     POP        EDI
//         0048fa12     POP        ESI
//         0048fa13     POP        EBP
//         0048fa14     MOV        dword ptr FS:[0x0],this
//         0048fa1b     POP        EBX
//         0048fa1c     ADD        ESP,0x30
//         0048fa1f     RET
}

TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Campaign_Editor_Screen(TRIBE_Campaign_Editor_
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0048fa6d(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0048fa59(W)
//                               ??1TRIBE_Campaign_Editor_Screen@@UAE@XZ                      XREF[1]:     `vector_deleting_destructor':0048f
//                               TRIBE_Campaign_Editor_Screen::~TRIBE_Campaign_Editor_Screen
//                              scr_cam.cpp:150 (35)
//         0048fa40     PUSH       -0x1
//         0048fa42     PUSH       FUN_0055e8a8
//         0048fa47     MOV        EAX,FS:[0x0]
//         0048fa4d     PUSH       EAX
//         0048fa4e     MOV        dword ptr FS:[0x0],ESP
//         0048fa55     PUSH       this
//         0048fa56     PUSH       ESI
//         0048fa57     MOV        ESI,this
//         0048fa59     MOV        dword ptr [ESP + local_10],ESI
//         0048fa5d     MOV        dword ptr [ESI],TRIBE_Campaign_Editor_Screen::   = 0048fa20
//                              scr_cam.cpp:151 (23)
//         0048fa63     PUSH       s_Cancel_Dialog                                  = 43h
//         0048fa68     MOV        this,panel_system
//         0048fa6d     MOV        dword ptr [ESP + local_4],0x0
//         0048fa75     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_cam.cpp:152 (15)
//         0048fa7a     PUSH       s_Load_Dialog                                    = 4Ch
//         0048fa7f     MOV        this,panel_system
//         0048fa84     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_cam.cpp:154 (10)
//         0048fa89     MOV        this,dword ptr [ESI + 0x47c]
//         0048fa8f     TEST       this,this
//         0048fa91     JZ         LAB_0048fa99
//                              scr_cam.cpp:155 (6)
//         0048fa93     MOV        EAX,dword ptr [this->_padding_]
//         0048fa95     PUSH       0x1
//         0048fa97     CALL       dword ptr [EAX]
//                               LAB_0048fa99                                                 XREF[1]:     0048fa91(j)
//                              scr_cam.cpp:157 (10)
//         0048fa99     MOV        this,dword ptr [ESI + 0x484]
//         0048fa9f     TEST       this,this
//         0048faa1     JZ         LAB_0048faa9
//                              scr_cam.cpp:158 (6)
//         0048faa3     MOV        EDX,dword ptr [this->_padding_]
//         0048faa5     PUSH       0x1
//         0048faa7     CALL       dword ptr [EDX]
//                               LAB_0048faa9                                                 XREF[1]:     0048faa1(j)
//                              scr_cam.cpp:160 (10)
//         0048faa9     MOV        this,dword ptr [ESI + 0x488]
//         0048faaf     TEST       this,this
//         0048fab1     JZ         LAB_0048fab9
//                              scr_cam.cpp:161 (6)
//         0048fab3     MOV        EAX,dword ptr [this->_padding_]
//         0048fab5     PUSH       0x1
//         0048fab7     CALL       dword ptr [EAX]
//                               LAB_0048fab9                                                 XREF[1]:     0048fab1(j)
//                              scr_cam.cpp:163 (10)
//         0048fab9     MOV        this,dword ptr [ESI + 0x48c]
//         0048fabf     TEST       this,this
//         0048fac1     JZ         LAB_0048fac9
//                              scr_cam.cpp:164 (6)
//         0048fac3     MOV        EDX,dword ptr [this->_padding_]
//         0048fac5     PUSH       0x1
//         0048fac7     CALL       dword ptr [EDX]
//                               LAB_0048fac9                                                 XREF[1]:     0048fac1(j)
//                              scr_cam.cpp:166 (10)
//         0048fac9     MOV        this,dword ptr [ESI + 0x494]
//         0048facf     TEST       this,this
//         0048fad1     JZ         LAB_0048fad9
//                              scr_cam.cpp:167 (6)
//         0048fad3     MOV        EAX,dword ptr [this->_padding_]
//         0048fad5     PUSH       0x1
//         0048fad7     CALL       dword ptr [EAX]
//                               LAB_0048fad9                                                 XREF[1]:     0048fad1(j)
//                              scr_cam.cpp:169 (10)
//         0048fad9     MOV        this,dword ptr [ESI + 0x490]
//         0048fadf     TEST       this,this
//         0048fae1     JZ         LAB_0048fae9
//                              scr_cam.cpp:170 (6)
//         0048fae3     MOV        EDX,dword ptr [this->_padding_]
//         0048fae5     PUSH       0x1
//         0048fae7     CALL       dword ptr [EDX]
//                               LAB_0048fae9                                                 XREF[1]:     0048fae1(j)
//                              scr_cam.cpp:172 (10)
//         0048fae9     MOV        this,dword ptr [ESI + 0x498]
//         0048faef     TEST       this,this
//         0048faf1     JZ         LAB_0048faf9
//                              scr_cam.cpp:173 (6)
//         0048faf3     MOV        EAX,dword ptr [this->_padding_]
//         0048faf5     PUSH       0x1
//         0048faf7     CALL       dword ptr [EAX]
//                               LAB_0048faf9                                                 XREF[1]:     0048faf1(j)
//                              scr_cam.cpp:175 (10)
//         0048faf9     MOV        this,dword ptr [ESI + 0x480]
//         0048faff     TEST       this,this
//         0048fb01     JZ         LAB_0048fb09
//                              scr_cam.cpp:176 (6)
//         0048fb03     MOV        EDX,dword ptr [this->_padding_]
//         0048fb05     PUSH       0x1
//         0048fb07     CALL       dword ptr [EDX]
//                               LAB_0048fb09                                                 XREF[1]:     0048fb01(j)
//                              scr_cam.cpp:178 (10)
//         0048fb09     MOV        this,dword ptr [ESI + 0x49c]
//         0048fb0f     TEST       this,this
//         0048fb11     JZ         LAB_0048fb19
//                              scr_cam.cpp:179 (6)
//         0048fb13     MOV        EAX,dword ptr [this->_padding_]
//         0048fb15     PUSH       0x1
//         0048fb17     CALL       dword ptr [EAX]
//                               LAB_0048fb19                                                 XREF[1]:     0048fb11(j)
//                              scr_cam.cpp:181 (10)
//         0048fb19     MOV        this,dword ptr [ESI + 0x4bc]
//         0048fb1f     TEST       this,this
//         0048fb21     JZ         LAB_0048fb29
//                              scr_cam.cpp:182 (6)
//         0048fb23     MOV        EDX,dword ptr [this->_padding_]
//         0048fb25     PUSH       0x1
//         0048fb27     CALL       dword ptr [EDX]
//                               LAB_0048fb29                                                 XREF[1]:     0048fb21(j)
//                              scr_cam.cpp:184 (10)
//         0048fb29     MOV        this,dword ptr [ESI + 0x4a4]
//         0048fb2f     TEST       this,this
//         0048fb31     JZ         LAB_0048fb39
//                              scr_cam.cpp:185 (6)
//         0048fb33     MOV        EAX,dword ptr [this->_padding_]
//         0048fb35     PUSH       0x1
//         0048fb37     CALL       dword ptr [EAX]
//                               LAB_0048fb39                                                 XREF[1]:     0048fb31(j)
//                              scr_cam.cpp:187 (10)
//         0048fb39     MOV        this,dword ptr [ESI + 0x4a8]
//         0048fb3f     TEST       this,this
//         0048fb41     JZ         LAB_0048fb49
//                              scr_cam.cpp:188 (6)
//         0048fb43     MOV        EDX,dword ptr [this->_padding_]
//         0048fb45     PUSH       0x1
//         0048fb47     CALL       dword ptr [EDX]
//                               LAB_0048fb49                                                 XREF[1]:     0048fb41(j)
//                              scr_cam.cpp:190 (10)
//         0048fb49     MOV        this,dword ptr [ESI + 0x4a0]
//         0048fb4f     TEST       this,this
//         0048fb51     JZ         LAB_0048fb59
//                              scr_cam.cpp:191 (6)
//         0048fb53     MOV        EAX,dword ptr [this->_padding_]
//         0048fb55     PUSH       0x1
//         0048fb57     CALL       dword ptr [EAX]
//                               LAB_0048fb59                                                 XREF[1]:     0048fb51(j)
//                              scr_cam.cpp:193 (10)
//         0048fb59     MOV        this,dword ptr [ESI + 0x4ac]
//         0048fb5f     TEST       this,this
//         0048fb61     JZ         LAB_0048fb69
//                              scr_cam.cpp:194 (6)
//         0048fb63     MOV        EDX,dword ptr [this->_padding_]
//         0048fb65     PUSH       0x1
//         0048fb67     CALL       dword ptr [EDX]
//                               LAB_0048fb69                                                 XREF[1]:     0048fb61(j)
//                              scr_cam.cpp:196 (10)
//         0048fb69     MOV        this,dword ptr [ESI + 0x4b0]
//         0048fb6f     TEST       this,this
//         0048fb71     JZ         LAB_0048fb79
//                              scr_cam.cpp:197 (6)
//         0048fb73     MOV        EAX,dword ptr [this->_padding_]
//         0048fb75     PUSH       0x1
//         0048fb77     CALL       dword ptr [EAX]
//                               LAB_0048fb79                                                 XREF[1]:     0048fb71(j)
//                              scr_cam.cpp:199 (10)
//         0048fb79     MOV        this,dword ptr [ESI + 0x4b4]
//         0048fb7f     TEST       this,this
//         0048fb81     JZ         LAB_0048fb89
//                              scr_cam.cpp:200 (6)
//         0048fb83     MOV        EDX,dword ptr [this->_padding_]
//         0048fb85     PUSH       0x1
//         0048fb87     CALL       dword ptr [EDX]
//                               LAB_0048fb89                                                 XREF[1]:     0048fb81(j)
//                              scr_cam.cpp:202 (10)
//         0048fb89     MOV        this,dword ptr [ESI + 0x4b8]
//         0048fb8f     TEST       this,this
//         0048fb91     JZ         LAB_0048fb99
//                              scr_cam.cpp:203 (8)
//         0048fb93     MOV        EAX,dword ptr [this->_padding_]
//         0048fb95     PUSH       0x1
//         0048fb97     CALL       dword ptr [EAX]
//                               LAB_0048fb99                                                 XREF[1]:     0048fb91(j)
//         0048fb99     MOV        this,ESI
//                              scr_cam.cpp:205 (29)
//         0048fb9b     MOV        dword ptr [ESP + 0x10],0xffffffff
//         0048fba3     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         0048fba8     MOV        this,dword ptr [ESP + 0x8]
//         0048fbac     POP        ESI
//         0048fbad     MOV        dword ptr FS:[0x0],this
//         0048fbb4     ADD        ESP,0x10
//         0048fbb7     RET
//         0048fbb8     ??         90h
//         0048fbb9     NOP
//         0048fbba     NOP
//         0048fbbb     NOP
//         0048fbbc     NOP
//         0048fbbd     NOP
//         0048fbbe     NOP
//         0048fbbf     NOP
}

void TRIBE_Campaign_Editor_Screen::fill_campaign_drop() {
    /* TODO: Stub */
//                              void __thiscall fill_campaign_drop(TRIBE_Campaign_Editor_Screen * th
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              _finddata_t       Stack[-0x11c   file_info                 XREF[0,8]:   0048fc05(*), 0048fc64(*), 0048fc9b(*), 0048fcfa(*),
//                                                                                     0048fc21(*), 0048fc2d(*), 0048fcb7(*), 0048fcc3(*)
//              char[256]         Stack[-0x21c   file_name                 XREF[0,8]:   0048fbe9(*), 0048fc0c(*), 0048fc39(*), 0048fc4d(*),
//                                                                                     0048fc7f(*), 0048fca2(*), 0048fccf(*), 0048fce3(*)
//                               ?fill_campaign_drop@TRIBE_Campaign_Editor_Screen@@IAEXXZ     XREF[2]:     TRIBE_Campaign_Editor_Screen:0048f
//                               TRIBE_Campaign_Editor_Screen::fill_campaign_drop                          make_campaign:0049033a(c)
//                              scr_cam.cpp:211 (12)
//         0048fbc0     SUB        ESP,0x218
//         0048fbc6     PUSH       EBX
//         0048fbc7     PUSH       EBP
//         0048fbc8     MOV        EBP,this
//         0048fbca     PUSH       ESI
//         0048fbcb     PUSH       EDI
//                              scr_cam.cpp:217 (13)
//         0048fbcc     PUSH       0x1
//         0048fbce     MOV        this,dword ptr [EBP + 0x4bc]
//         0048fbd4     CALL       TDropDownPanel::set_sorted                       void set_sorted(TDropDownPanel * this, int pa
//                              scr_cam.cpp:219 (11)
//         0048fbd9     MOV        this,dword ptr [EBP + 0x4bc]
//         0048fbdf     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_cam.cpp:221 (33)
//         0048fbe4     MOV        EAX,[rge_base_game]                              = 00000000
//         0048fbe9     LEA        EDX=>file_name[4],[ESP + 0x10]
//         0048fbed     MOV        this,dword ptr [EAX + 0xc]
//         0048fbf0     ADD        this,0xd1c
//         0048fbf6     PUSH       this
//         0048fbf7     PUSH       s_%s*.cpn                                        = "%s*.cpn"
//         0048fbfc     PUSH       EDX
//         0048fbfd     CALL       sprintf                                          undefined sprintf()
//         0048fc02     ADD        ESP,0xc
//                              scr_cam.cpp:222 (23)
//         0048fc05     LEA        EAX=>file_info.time_create,[ESP + 0x110]
//         0048fc0c     LEA        this=>file_name[4],[ESP + 0x10]
//         0048fc10     PUSH       EAX
//         0048fc11     PUSH       this
//         0048fc12     CALL       __findfirst                                      undefined __findfirst()
//         0048fc17     MOV        EBX,EAX
//         0048fc19     ADD        ESP,0x8
//                              scr_cam.cpp:223 (5)
//         0048fc1c     CMP        EBX,-0x1
//         0048fc1f     JZ         LAB_0048fc7a
//                               LAB_0048fc21                                                 XREF[1]:     0048fc78(j)
//                              scr_cam.cpp:227 (12)
//         0048fc21     LEA        EDI=>file_info+0x18,[ESP + 0x124]
//         0048fc28     OR         this,0xffffffff
//         0048fc2b     XOR        EAX,EAX
//                              scr_cam.cpp:228 (32)
//         0048fc2d     LEA        EDX=>file_info+0x18,[ESP + 0x124]
//         0048fc34     SCASB.RE   ES:EDI
//         0048fc36     NOT        this
//         0048fc38     DEC        this
//         0048fc39     LEA        EAX=>file_name[4],[ESP + 0x10]
//         0048fc3d     MOV        ESI,this
//         0048fc3f     SUB        ESI,0x4
//         0048fc42     PUSH       ESI
//         0048fc43     PUSH       EDX
//         0048fc44     PUSH       EAX
//         0048fc45     CALL       strncpy                                          undefined strncpy()
//         0048fc4a     ADD        ESP,0xc
//                              scr_cam.cpp:230 (23)
//         0048fc4d     LEA        this=>file_name[4],[ESP + 0x10]
//         0048fc51     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
//         0048fc56     PUSH       0x0
//         0048fc58     PUSH       this
//         0048fc59     MOV        this,dword ptr [EBP + 0x4bc]
//         0048fc5f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_cam.cpp:232 (22)
//         0048fc64     LEA        EDX=>file_info.time_create,[ESP + 0x110]
//         0048fc6b     PUSH       EDX
//         0048fc6c     PUSH       EBX
//         0048fc6d     CALL       __findnext                                       undefined __findnext()
//         0048fc72     ADD        ESP,0x8
//         0048fc75     CMP        EAX,-0x1
//         0048fc78     JNZ        LAB_0048fc21
//                               LAB_0048fc7a                                                 XREF[1]:     0048fc1f(j)
//                              scr_cam.cpp:236 (33)
//         0048fc7a     MOV        EAX,[rge_base_game]                              = 00000000
//         0048fc7f     LEA        EDX=>file_name[4],[ESP + 0x10]
//         0048fc83     MOV        this,dword ptr [EAX + 0xc]
//         0048fc86     ADD        this,0xd1c
//         0048fc8c     PUSH       this
//         0048fc8d     PUSH       s_%s*.cpx                                        = "%s*.cpx"
//         0048fc92     PUSH       EDX
//         0048fc93     CALL       sprintf                                          undefined sprintf()
//         0048fc98     ADD        ESP,0xc
//                              scr_cam.cpp:237 (23)
//         0048fc9b     LEA        EAX=>file_info.time_create,[ESP + 0x110]
//         0048fca2     LEA        this=>file_name[4],[ESP + 0x10]
//         0048fca6     PUSH       EAX
//         0048fca7     PUSH       this
//         0048fca8     CALL       __findfirst                                      undefined __findfirst()
//         0048fcad     MOV        EBX,EAX
//         0048fcaf     ADD        ESP,0x8
//                              scr_cam.cpp:238 (5)
//         0048fcb2     CMP        EBX,-0x1
//         0048fcb5     JZ         LAB_0048fd10
//                               LAB_0048fcb7                                                 XREF[1]:     0048fd0e(j)
//                              scr_cam.cpp:242 (12)
//         0048fcb7     LEA        EDI=>file_info+0x18,[ESP + 0x124]
//         0048fcbe     OR         this,0xffffffff
//         0048fcc1     XOR        EAX,EAX
//                              scr_cam.cpp:243 (32)
//         0048fcc3     LEA        EDX=>file_info+0x18,[ESP + 0x124]
//         0048fcca     SCASB.RE   ES:EDI
//         0048fccc     NOT        this
//         0048fcce     DEC        this
//         0048fccf     LEA        EAX=>file_name[4],[ESP + 0x10]
//         0048fcd3     MOV        ESI,this
//         0048fcd5     SUB        ESI,0x4
//         0048fcd8     PUSH       ESI
//         0048fcd9     PUSH       EDX
//         0048fcda     PUSH       EAX
//         0048fcdb     CALL       strncpy                                          undefined strncpy()
//         0048fce0     ADD        ESP,0xc
//                              scr_cam.cpp:245 (23)
//         0048fce3     LEA        this=>file_name[4],[ESP + 0x10]
//         0048fce7     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
//         0048fcec     PUSH       0x0
//         0048fcee     PUSH       this
//         0048fcef     MOV        this,dword ptr [EBP + 0x4bc]
//         0048fcf5     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//                              scr_cam.cpp:247 (22)
//         0048fcfa     LEA        EDX=>file_info.time_create,[ESP + 0x110]
//         0048fd01     PUSH       EDX
//         0048fd02     PUSH       EBX
//         0048fd03     CALL       __findnext                                       undefined __findnext()
//         0048fd08     ADD        ESP,0x8
//         0048fd0b     CMP        EAX,-0x1
//         0048fd0e     JNZ        LAB_0048fcb7
//                               LAB_0048fd10                                                 XREF[1]:     0048fcb5(j)
//                              scr_cam.cpp:249 (11)
//         0048fd10     POP        EDI
//         0048fd11     POP        ESI
//         0048fd12     POP        EBP
//         0048fd13     POP        EBX
//         0048fd14     ADD        ESP,0x218
//         0048fd1a     RET
//         0048fd1b     ??         90h
//         0048fd1c     NOP
//         0048fd1d     NOP
//         0048fd1e     NOP
//         0048fd1f     NOP
    return;
}

void TRIBE_Campaign_Editor_Screen::fill_scenario_list() {
    /* TODO: Stub */
//                              void __thiscall fill_scenario_list(TRIBE_Campaign_Editor_Screen * th
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              _finddata_t       Stack[-0x11c   file_info                 XREF[0,8]:   0048fd69(*), 0048fdc8(*), 0048fe00(*), 0048fe5f(*),
//                                                                                     0048fd85(*), 0048fd96(*), 0048fe1c(*), 0048fe2d(*)
//              char[256]         Stack[-0x21c   file_name                 XREF[0,8]:   0048fd4d(*), 0048fd70(*), 0048fd9f(*), 0048fdb7(*),
//                                                                                     0048fde4(*), 0048fe07(*), 0048fe36(*), 0048fe4e(*)
//                               ?fill_scenario_list@TRIBE_Campaign_Editor_Screen@@IAEXXZ     XREF[2]:     TRIBE_Campaign_Editor_Screen:0048f
//                               TRIBE_Campaign_Editor_Screen::fill_scenario_list                          load_campaign:00490096(c)
//                              scr_cam.cpp:255 (12)
//         0048fd20     SUB        ESP,0x218
//         0048fd26     PUSH       EBX
//         0048fd27     PUSH       EBP
//         0048fd28     MOV        EBP,this
//         0048fd2a     PUSH       ESI
//         0048fd2b     PUSH       EDI
//                              scr_cam.cpp:261 (16)
//         0048fd2c     MOV        EAX,dword ptr [EBP + 0x48c]
//         0048fd32     MOV        dword ptr [EAX + 0x15c],0x1
//                              scr_cam.cpp:263 (11)
//         0048fd3c     MOV        this,dword ptr [EBP + 0x48c]
//         0048fd42     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                              scr_cam.cpp:265 (34)
//         0048fd47     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048fd4d     LEA        EAX=>file_name[4],[ESP + 0x10]
//         0048fd51     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0048fd54     ADD        EDX,0xc17
//         0048fd5a     PUSH       EDX
//         0048fd5b     PUSH       s_%s*.scn                                        = "%s*.scn"
//         0048fd60     PUSH       EAX
//         0048fd61     CALL       sprintf                                          undefined sprintf()
//         0048fd66     ADD        ESP,0xc
//                              scr_cam.cpp:266 (23)
//         0048fd69     LEA        this=>file_info.time_create,[ESP + 0x110]
//         0048fd70     LEA        EDX=>file_name[4],[ESP + 0x10]
//         0048fd74     PUSH       this
//         0048fd75     PUSH       EDX
//         0048fd76     CALL       __findfirst                                      undefined __findfirst()
//         0048fd7b     MOV        EBX,EAX
//         0048fd7d     ADD        ESP,0x8
//                              scr_cam.cpp:267 (5)
//         0048fd80     CMP        EBX,-0x1
//         0048fd83     JZ         LAB_0048fdde
//                               LAB_0048fd85                                                 XREF[1]:     0048fddc(j)
//                              scr_cam.cpp:271 (17)
//         0048fd85     LEA        EDI=>file_info+0x18,[ESP + 0x124]
//         0048fd8c     OR         this,0xffffffff
//         0048fd8f     XOR        EAX,EAX
//         0048fd91     SCASB.RE   ES:EDI
//         0048fd93     NOT        this
//         0048fd95     DEC        this
//                              scr_cam.cpp:272 (24)
//         0048fd96     LEA        EAX=>file_info+0x18,[ESP + 0x124]
//         0048fd9d     MOV        ESI,this
//         0048fd9f     LEA        this=>file_name[4],[ESP + 0x10]
//         0048fda3     SUB        ESI,0x4
//         0048fda6     PUSH       ESI
//         0048fda7     PUSH       EAX
//         0048fda8     PUSH       this
//         0048fda9     CALL       strncpy                                          undefined strncpy()
//                              scr_cam.cpp:274 (26)
//         0048fdae     MOV        this,dword ptr [EBP + 0x48c]
//         0048fdb4     ADD        ESP,0xc
//         0048fdb7     LEA        EDX=>file_name[4],[ESP + 0x10]
//         0048fdbb     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
//         0048fdc0     PUSH       0x0
//         0048fdc2     PUSH       EDX
//         0048fdc3     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_cam.cpp:276 (22)
//         0048fdc8     LEA        EAX=>file_info.time_create,[ESP + 0x110]
//         0048fdcf     PUSH       EAX
//         0048fdd0     PUSH       EBX
//         0048fdd1     CALL       __findnext                                       undefined __findnext()
//         0048fdd6     ADD        ESP,0x8
//         0048fdd9     CMP        EAX,-0x1
//         0048fddc     JNZ        LAB_0048fd85
//                               LAB_0048fdde                                                 XREF[1]:     0048fd83(j)
//                              scr_cam.cpp:279 (34)
//         0048fdde     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0048fde4     LEA        EAX=>file_name[4],[ESP + 0x10]
//         0048fde8     MOV        EDX,dword ptr [ECX + this->_padding_]
//         0048fdeb     ADD        EDX,0xc17
//         0048fdf1     PUSH       EDX
//         0048fdf2     PUSH       s_%s*.scx                                        = "%s*.scx"
//         0048fdf7     PUSH       EAX
//         0048fdf8     CALL       sprintf                                          undefined sprintf()
//         0048fdfd     ADD        ESP,0xc
//                              scr_cam.cpp:280 (23)
//         0048fe00     LEA        this=>file_info.time_create,[ESP + 0x110]
//         0048fe07     LEA        EDX=>file_name[4],[ESP + 0x10]
//         0048fe0b     PUSH       this
//         0048fe0c     PUSH       EDX
//         0048fe0d     CALL       __findfirst                                      undefined __findfirst()
//         0048fe12     MOV        EBX,EAX
//         0048fe14     ADD        ESP,0x8
//                              scr_cam.cpp:281 (5)
//         0048fe17     CMP        EBX,-0x1
//         0048fe1a     JZ         LAB_0048fe75
//                               LAB_0048fe1c                                                 XREF[1]:     0048fe73(j)
//                              scr_cam.cpp:285 (17)
//         0048fe1c     LEA        EDI=>file_info+0x18,[ESP + 0x124]
//         0048fe23     OR         this,0xffffffff
//         0048fe26     XOR        EAX,EAX
//         0048fe28     SCASB.RE   ES:EDI
//         0048fe2a     NOT        this
//         0048fe2c     DEC        this
//                              scr_cam.cpp:286 (24)
//         0048fe2d     LEA        EAX=>file_info+0x18,[ESP + 0x124]
//         0048fe34     MOV        ESI,this
//         0048fe36     LEA        this=>file_name[4],[ESP + 0x10]
//         0048fe3a     SUB        ESI,0x4
//         0048fe3d     PUSH       ESI
//         0048fe3e     PUSH       EAX
//         0048fe3f     PUSH       this
//         0048fe40     CALL       strncpy                                          undefined strncpy()
//                              scr_cam.cpp:288 (26)
//         0048fe45     MOV        this,dword ptr [EBP + 0x48c]
//         0048fe4b     ADD        ESP,0xc
//         0048fe4e     LEA        EDX=>file_name[4],[ESP + 0x10]
//         0048fe52     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
//         0048fe57     PUSH       0x0
//         0048fe59     PUSH       EDX
//         0048fe5a     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_cam.cpp:290 (22)
//         0048fe5f     LEA        EAX=>file_info.time_create,[ESP + 0x110]
//         0048fe66     PUSH       EAX
//         0048fe67     PUSH       EBX
//         0048fe68     CALL       __findnext                                       undefined __findnext()
//         0048fe6d     ADD        ESP,0x8
//         0048fe70     CMP        EAX,-0x1
//         0048fe73     JNZ        LAB_0048fe1c
//                               LAB_0048fe75                                                 XREF[1]:     0048fe1a(j)
//                              scr_cam.cpp:292 (11)
//         0048fe75     POP        EDI
//         0048fe76     POP        ESI
//         0048fe77     POP        EBP
//         0048fe78     POP        EBX
//         0048fe79     ADD        ESP,0x218
//         0048fe7f     RET
    return;
}

void TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list() {
    /* TODO: Stub */
//                              void __thiscall fill_campaign_scenario_list(TRIBE_Campaign_Editor_Sc
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0048fea0(*), 0048feac(R), 0048febb(R), 0048fed0(R),
//                                                                                     0048fee5(R)
//              char * *          Stack[-0x8]:4  scenario_names
//                               ?fill_campaign_scenario_list@TRIBE_Campaign_Editor_Screen@@  XREF[1]:     load_campaign:0049009d(c)
//                               TRIBE_Campaign_Editor_Screen::fill_campaign_scenario_list
//                              scr_cam.cpp:298 (5)
//         0048fe80     PUSH       this
//         0048fe81     PUSH       EBX
//         0048fe82     PUSH       EDI
//         0048fe83     MOV        EDI,this
//                              scr_cam.cpp:303 (10)
//         0048fe85     MOV        EAX,dword ptr [EDI + 0x4c0]
//         0048fe8b     TEST       EAX,EAX
//         0048fe8d     JZ         LAB_0048fef3
//                              scr_cam.cpp:305 (11)
//         0048fe8f     MOV        this,dword ptr [EDI + 0x490]
//         0048fe95     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                              scr_cam.cpp:306 (18)
//         0048fe9a     MOV        this,dword ptr [EDI + 0x4c0]
//         0048fea0     LEA        EAX=>local_4,[ESP + 0x8]
//         0048fea4     PUSH       EAX
//         0048fea5     CALL       RGE_Campaign::scenario_info                      long scenario_info(RGE_Campaign * this, char
//         0048feaa     MOV        EBX,EAX
//                              scr_cam.cpp:307 (9)
//         0048feac     MOV        EAX,dword ptr [ESP + local_4]
//         0048feb0     TEST       EAX,EAX
//         0048feb2     JZ         LAB_0048fef3
//         0048feb4     PUSH       ESI
//                              scr_cam.cpp:309 (6)
//         0048feb5     XOR        ESI,ESI
//         0048feb7     TEST       EBX,EBX
//         0048feb9     JLE        LAB_0048fee5
//                               LAB_0048febb                                                 XREF[1]:     0048fee3(j)
//                              scr_cam.cpp:311 (21)
//         0048febb     MOV        this,dword ptr [ESP + local_4]
//         0048febf     PUSH       0x0
//         0048fec1     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
//         0048fec4     MOV        this,dword ptr [EDI + 0x490]
//         0048feca     PUSH       EDX
//         0048fecb     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_cam.cpp:312 (21)
//         0048fed0     MOV        EAX,dword ptr [ESP + local_4]
//         0048fed4     MOV        this,dword ptr [EAX + ESI*0x4]
//         0048fed7     PUSH       this
//         0048fed8     CALL       free                                             undefined free()
//         0048fedd     ADD        ESP,0x4
//         0048fee0     INC        ESI
//         0048fee1     CMP        ESI,EBX
//         0048fee3     JL         LAB_0048febb
//                               LAB_0048fee5                                                 XREF[1]:     0048feb9(j)
//                              scr_cam.cpp:314 (14)
//         0048fee5     MOV        EDX,dword ptr [ESP + local_4]
//         0048fee9     PUSH       EDX
//         0048feea     CALL       free                                             undefined free()
//         0048feef     ADD        ESP,0x4
//         0048fef2     POP        ESI
//                               LAB_0048fef3                                                 XREF[2]:     0048fe8d(j), 0048feb2(j)
//                              scr_cam.cpp:317 (4)
//         0048fef3     POP        EDI
//         0048fef4     POP        EBX
//         0048fef5     POP        this
//         0048fef6     RET
//         0048fef7     ??         90h
//         0048fef8     NOP
//         0048fef9     NOP
//         0048fefa     NOP
//         0048fefb     NOP
//         0048fefc     NOP
//         0048fefd     NOP
//         0048fefe     NOP
//         0048feff     NOP
    return;
}

uchar TRIBE_Campaign_Editor_Screen::check_lists() {
    /* TODO: Stub */
//                              uchar __thiscall check_lists(TRIBE_Campaign_Editor_Screen * this)
//              uchar             AL:1           <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//                               ?check_lists@TRIBE_Campaign_Editor_Screen@@IAEEXZ            XREF[1]:     load_campaign:004900a4(c)
//                               TRIBE_Campaign_Editor_Screen::check_lists
//                              scr_cam.cpp:323 (5)
//         0048ff00     PUSH       EBX
//         0048ff01     PUSH       ESI
//         0048ff02     MOV        ESI,this
//         0048ff04     PUSH       EDI
//                              scr_cam.cpp:327 (13)
//         0048ff05     MOV        this,dword ptr [ESI + 0x490]
//         0048ff0b     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         0048ff10     MOV        EBX,EAX
//                              scr_cam.cpp:328 (6)
//         0048ff12     XOR        EDI,EDI
//         0048ff14     TEST       EBX,EBX
//         0048ff16     JLE        LAB_0048ff3a
//                               LAB_0048ff18                                                 XREF[1]:     0048ff38(j)
//                              scr_cam.cpp:329 (34)
//         0048ff18     MOV        this,dword ptr [ESI + 0x490]
//         0048ff1e     PUSH       EDI
//         0048ff1f     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         0048ff24     MOV        this,dword ptr [ESI + 0x48c]
//         0048ff2a     PUSH       EAX
//         0048ff2b     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//         0048ff30     CMP        EAX,-0x1
//         0048ff33     JZ         LAB_0048ff6f
//         0048ff35     INC        EDI
//         0048ff36     CMP        EDI,EBX
//         0048ff38     JL         LAB_0048ff18
//                               LAB_0048ff3a                                                 XREF[1]:     0048ff16(j)
//                              scr_cam.cpp:332 (6)
//         0048ff3a     XOR        EDI,EDI
//         0048ff3c     TEST       EBX,EBX
//         0048ff3e     JLE        LAB_0048ff69
//                               LAB_0048ff40                                                 XREF[1]:     0048ff67(j)
//                              scr_cam.cpp:333 (41)
//         0048ff40     MOV        this,dword ptr [ESI + 0x490]
//         0048ff46     PUSH       EDI
//         0048ff47     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         0048ff4c     MOV        this,dword ptr [ESI + 0x48c]
//         0048ff52     PUSH       EAX
//         0048ff53     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//         0048ff58     MOV        this,dword ptr [ESI + 0x48c]
//         0048ff5e     PUSH       EAX
//         0048ff5f     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//         0048ff64     INC        EDI
//         0048ff65     CMP        EDI,EBX
//         0048ff67     JL         LAB_0048ff40
//                               LAB_0048ff69                                                 XREF[1]:     0048ff3e(j)
//                              scr_cam.cpp:335 (2)
//         0048ff69     MOV        AL,0x1
//                              scr_cam.cpp:336 (10)
//         0048ff6b     POP        EDI
//         0048ff6c     POP        ESI
//         0048ff6d     POP        EBX
//         0048ff6e     RET
//                               LAB_0048ff6f                                                 XREF[1]:     0048ff33(j)
//         0048ff6f     POP        EDI
//         0048ff70     POP        ESI
//         0048ff71     XOR        AL,AL
//         0048ff73     POP        EBX
//         0048ff74     RET
//         0048ff75     ??         90h
//         0048ff76     NOP
//         0048ff77     NOP
//         0048ff78     NOP
//         0048ff79     NOP
//         0048ff7a     NOP
//         0048ff7b     NOP
//         0048ff7c     NOP
//         0048ff7d     NOP
//         0048ff7e     NOP
//         0048ff7f     NOP
    return 0;
}

void TRIBE_Campaign_Editor_Screen::load_campaign() {
    /* TODO: Stub */
//                              void __thiscall load_campaign(TRIBE_Campaign_Editor_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049006a(W), 00490085(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004900f5(R)
//              _finddata_t       Stack[-0x128   file_info                 XREF[1,2]:   00490064(W), 0048ffee(*), 00490044(*)
//              undefined4        Stack[-0x12c   local_12c                 XREF[6]:     0048ffb2(W), 0048ffdc(*), 0048ffe7(R), 00490032(*),
//                                                                                     0049003d(R), 004900e8(R)
//              char *            Stack[-0x130   text2                     XREF[7]:     0048ffae(W), 0048ffbc(*), 0048ffcc(R), 00490011(*),
//                                                                                     00490021(R), 00490073(R), 004900de(R)
//              char *            Stack[-0x134   text
//                               ?load_campaign@TRIBE_Campaign_Editor_Screen@@IAEXXZ          XREF[3]:     TRIBE_Campaign_Editor_Screen:0048f
//                               TRIBE_Campaign_Editor_Screen::load_campaign                               action:00490709(c),
//                                                                                                         action:0049098b(c)
//                              scr_cam.cpp:342 (33)
//         0048ff80     PUSH       -0x1
//         0048ff82     PUSH       FUN_0055e8ce
//         0048ff87     MOV        EAX,FS:[0x0]
//         0048ff8d     PUSH       EAX
//         0048ff8e     MOV        dword ptr FS:[0x0],ESP
//         0048ff95     SUB        ESP,0x124
//         0048ff9b     PUSH       EBX
//         0048ff9c     PUSH       EBP
//         0048ff9d     PUSH       ESI
//         0048ff9e     MOV        ESI,this
//         0048ffa0     PUSH       EDI
//                              scr_cam.cpp:345 (2)
//         0048ffa1     XOR        EBP,EBP
//                              scr_cam.cpp:349 (35)
//         0048ffa3     MOV        this,dword ptr [ESI + 0x49c]
//         0048ffa9     PUSH       s_.cpn                                           = ".cpn"
//         0048ffae     MOV        dword ptr [ESP + text2],EBP
//         0048ffb2     MOV        dword ptr [ESP + local_12c],EBP
//         0048ffb6     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
//         0048ffbb     PUSH       EAX
//         0048ffbc     LEA        EAX=>text2,[ESP + 0x18]
//         0048ffc0     PUSH       EAX
//         0048ffc1     CALL       addstring                                        void addstring(char * * param_1, char * param
//                              scr_cam.cpp:350 (33)
//         0048ffc6     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         0048ffcc     MOV        this,dword ptr [ESP + text2]
//         0048ffd0     ADD        ESP,0xc
//         0048ffd3     MOV        EAX,dword ptr [EDX + 0xc]
//         0048ffd6     PUSH       this
//         0048ffd7     ADD        EAX,0xd1c
//         0048ffdc     LEA        this=>local_12c,[ESP + 0x18]
//         0048ffe0     PUSH       EAX
//         0048ffe1     PUSH       this
//         0048ffe2     CALL       addstring                                        void addstring(char * * param_1, char * param
//                              scr_cam.cpp:352 (21)
//         0048ffe7     MOV        EAX,dword ptr [ESP + local_12c]
//         0048ffeb     ADD        ESP,0xc
//         0048ffee     LEA        EDX=>file_info.time_create,[ESP + 0x1c]
//         0048fff2     PUSH       EDX
//         0048fff3     PUSH       EAX
//         0048fff4     CALL       __findfirst                                      undefined __findfirst()
//         0048fff9     ADD        ESP,0x8
//                              scr_cam.cpp:355 (5)
//         0048fffc     CMP        EAX,-0x1
//         0048ffff     JNZ        LAB_00490057
//                              scr_cam.cpp:357 (27)
//         00490001     MOV        this,dword ptr [ESI + 0x49c]
//         00490007     PUSH       s_.cpx                                           = ".cpx"
//         0049000c     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
//         00490011     LEA        this=>text2,[ESP + 0x14]
//         00490015     PUSH       EAX
//         00490016     PUSH       this
//         00490017     CALL       addstring                                        void addstring(char * * param_1, char * param
//                              scr_cam.cpp:358 (33)
//         0049001c     MOV        EAX,[rge_base_game]                              = 00000000
//         00490021     MOV        EDX,dword ptr [ESP + text2]
//         00490025     ADD        ESP,0xc
//         00490028     MOV        this,dword ptr [EAX + 0xc]
//         0049002b     PUSH       EDX
//         0049002c     ADD        this,0xd1c
//         00490032     LEA        EDX=>local_12c,[ESP + 0x18]
//         00490036     PUSH       this
//         00490037     PUSH       EDX
//         00490038     CALL       addstring                                        void addstring(char * * param_1, char * param
//                              scr_cam.cpp:360 (21)
//         0049003d     MOV        this,dword ptr [ESP + local_12c]
//         00490041     ADD        ESP,0xc
//         00490044     LEA        EAX=>file_info.time_create,[ESP + 0x1c]
//         00490048     PUSH       EAX
//         00490049     PUSH       this
//         0049004a     CALL       __findfirst                                      undefined __findfirst()
//         0049004f     ADD        ESP,0x8
//                              scr_cam.cpp:363 (5)
//         00490052     CMP        EAX,-0x1
//         00490055     JZ         LAB_004900cd
//                               LAB_00490057                                                 XREF[1]:     0048ffff(j)
//                              scr_cam.cpp:365 (44)
//         00490057     PUSH       0x20c
//         0049005c     CALL       operator_new                                     void * operator_new(uint param_1)
//         00490061     ADD        ESP,0x4
//         00490064     MOV        dword ptr [ESP + file_info.attrib],EAX
//         00490068     CMP        EAX,EBP
//         0049006a     MOV        dword ptr [ESP + local_4],EBP
//         00490071     JZ         LAB_00490081
//         00490073     MOV        EDX,dword ptr [ESP + text2]
//         00490077     MOV        this,EAX
//         00490079     PUSH       EDX
//         0049007a     CALL       RGE_Campaign::RGE_Campaign                       undefined RGE_Campaign(RGE_Campaign * this, c
//         0049007f     JMP        LAB_00490083
//                               LAB_00490081                                                 XREF[1]:     00490071(j)
//         00490081     XOR        EAX,EAX
//                               LAB_00490083                                                 XREF[1]:     0049007f(j)
//                              scr_cam.cpp:366 (24)
//         00490083     MOV        this,ESI
//         00490085     MOV        dword ptr [ESP + local_4],0xffffffff
//         00490090     MOV        dword ptr [ESI + 0x4c0],EAX
//         00490096     CALL       TRIBE_Campaign_Editor_Screen::fill_scenario_list void fill_scenario_list(TRIBE_Campaign_Editor
//                              scr_cam.cpp:367 (7)
//         0049009b     MOV        this,ESI
//         0049009d     CALL       TRIBE_Campaign_Editor_Screen::fill_campaign_sc   void fill_campaign_scenario_list(TRIBE_Campai
//                              scr_cam.cpp:368 (7)
//         004900a2     MOV        this,ESI
//         004900a4     CALL       TRIBE_Campaign_Editor_Screen::check_lists        uchar check_lists(TRIBE_Campaign_Editor_Scree
//                              scr_cam.cpp:369 (28)
//         004900a9     MOV        EDI,dword ptr [ESI + 0x4c0]
//         004900af     MOV        BL,AL
//         004900b1     CMP        EDI,EBP
//         004900b3     JZ         LAB_004900c5
//         004900b5     MOV        this,EDI
//         004900b7     CALL       RGE_Campaign::~RGE_Campaign                      void ~RGE_Campaign(RGE_Campaign * this)
//         004900bc     PUSH       EDI
//         004900bd     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004900c2     ADD        ESP,0x4
//                               LAB_004900c5                                                 XREF[1]:     004900b3(j)
//                              scr_cam.cpp:370 (6)
//         004900c5     MOV        dword ptr [ESI + 0x4c0],EBP
//                              scr_cam.cpp:372 (2)
//         004900cb     JMP        LAB_004900cf
//                               LAB_004900cd                                                 XREF[1]:     00490055(j)
//                              scr_cam.cpp:373 (2)
//         004900cd     XOR        BL,BL
//                               LAB_004900cf                                                 XREF[1]:     004900cb(j)
//                              scr_cam.cpp:375 (4)
//         004900cf     TEST       BL,BL
//         004900d1     JNZ        LAB_004900de
//                              scr_cam.cpp:376 (11)
//         004900d3     MOV        this,dword ptr [ESI + 0x490]
//         004900d9     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                               LAB_004900de                                                 XREF[1]:     004900d1(j)
//                              scr_cam.cpp:378 (10)
//         004900de     MOV        EAX,dword ptr [ESP + text2]
//         004900e2     PUSH       EAX
//         004900e3     CALL       free                                             undefined free()
//                              scr_cam.cpp:379 (13)
//         004900e8     MOV        this,dword ptr [ESP + local_12c]
//         004900ec     ADD        ESP,0x4
//         004900ef     PUSH       this
//         004900f0     CALL       free                                             undefined free()
//                              scr_cam.cpp:382 (35)
//         004900f5     MOV        this,dword ptr [ESP + local_c]
//         004900fc     ADD        ESP,0x4
//         004900ff     MOV        byte ptr [ESI + 0x478],0x0
//         00490106     MOV        dword ptr FS:[0x0],this
//         0049010d     POP        EDI
//         0049010e     POP        ESI
//         0049010f     POP        EBP
//         00490110     POP        EBX
//         00490111     ADD        ESP,0x130
//         00490117     RET
//         00490118     ??         90h
//         00490119     NOP
//         0049011a     NOP
//         0049011b     NOP
//         0049011c     NOP
//         0049011d     NOP
//         0049011e     NOP
//         0049011f     NOP
    return;
}

void TRIBE_Campaign_Editor_Screen::make_campaign() {
    /* TODO: Stub */
//                              void __thiscall make_campaign(TRIBE_Campaign_Editor_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049027c(W), 004902a5(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00490351(R)
//              _finddata_t       Stack[-0x128   file_info                 XREF[0,1]:   00490222(*)
//              char[260]         Stack[-0x22c   test                      XREF[2,2]:   004901c8(W), 004901d8(R), 00490210(*), 00490229(*)
//              undefined4        Stack[-0x230   local_230                 XREF[3]:     00490156(W), 00490263(R), 00490276(W)
//              char *            Stack[-0x234   text                      XREF[4]:     00490149(W), 00490177(*), 0049028e(R), 0049032b(R)
//              char *            Stack[-0x238   campaign_filename         XREF[5]:     004901a5(W), 004901c0(R), 00490285(R), 004902d6(R),
//                                                                                     004902fb(R)
//              char * *          Stack[-0x23c   scenarios_text            XREF[4]:     004901b6(W), 00490289(R), 004902d2(R), 00490305(R)
//              char * *          Stack[-0x240   scenarios_filenames
//                               ?make_campaign@TRIBE_Campaign_Editor_Screen@@IAEXXZ          XREF[3]:     action:004907c6(c),
//                               TRIBE_Campaign_Editor_Screen::make_campaign                               action:00490899(c),
//                                                                                                         action:00490964(c)
//                              scr_cam.cpp:388 (33)
//         00490120     PUSH       -0x1
//         00490122     PUSH       FUN_0055e8ee
//         00490127     MOV        EAX,FS:[0x0]
//         0049012d     PUSH       EAX
//         0049012e     MOV        dword ptr FS:[0x0],ESP
//         00490135     SUB        ESP,0x230
//         0049013b     PUSH       EBX
//         0049013c     PUSH       EBP
//         0049013d     PUSH       ESI
//         0049013e     MOV        EBP,this
//         00490140     PUSH       EDI
//                              scr_cam.cpp:390 (2)
//         00490141     XOR        EDI,EDI
//                              scr_cam.cpp:399 (17)
//         00490143     MOV        this,dword ptr [EBP + 0x49c]
//         00490149     MOV        dword ptr [ESP + text],EDI
//         0049014d     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
//         00490152     MOV        ESI,EAX
//                              scr_cam.cpp:400 (12)
//         00490154     CMP        ESI,EDI
//         00490156     MOV        dword ptr [ESP + local_230],ESI
//         0049015a     JZ         LAB_0049034a
//                              scr_cam.cpp:402 (18)
//         00490160     MOV        AL,byte ptr [ESI]
//         00490162     TEST       AL,AL
//         00490164     JZ         LAB_0049036a
//         0049016a     CMP        AL,0x20
//         0049016c     JZ         LAB_0049036a
//                              scr_cam.cpp:408 (16)
//         00490172     PUSH       s_.cpx                                           = ".cpx"
//         00490177     LEA        EAX=>text,[ESP + 0x1c]
//         0049017b     PUSH       ESI
//         0049017c     PUSH       EAX
//         0049017d     CALL       addstring                                        void addstring(char * * param_1, char * param
//                              scr_cam.cpp:410 (16)
//         00490182     MOV        this,dword ptr [EBP + 0x490]
//         00490188     ADD        ESP,0xc
//         0049018b     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00490190     MOV        EBX,EAX
//                              scr_cam.cpp:412 (8)
//         00490192     CMP        EBX,EDI
//         00490194     JLE        LAB_00490317
//                              scr_cam.cpp:415 (15)
//         0049019a     PUSH       0x4
//         0049019c     PUSH       EBX
//         0049019d     CALL       calloc                                           undefined calloc()
//         004901a2     ADD        ESP,0x8
//         004901a5     MOV        dword ptr [ESP + campaign_filename],EAX
//                              scr_cam.cpp:416 (11)
//         004901a9     PUSH       0x4
//         004901ab     PUSH       EBX
//         004901ac     CALL       calloc                                           undefined calloc()
//         004901b1     ADD        ESP,0x8
//                              scr_cam.cpp:417 (16)
//         004901b4     CMP        EBX,EDI
//         004901b6     MOV        dword ptr [ESP + scenarios_text],EAX
//         004901ba     JLE        LAB_00490269
//         004901c0     MOV        this,dword ptr [ESP + campaign_filename]
//                              scr_cam.cpp:457 (130)
//         004901c4     MOV        ESI,EAX
//         004901c6     SUB        this,EAX
//         004901c8     MOV        dword ptr [ESP + test[0]],this
//                               LAB_004901cc                                                 XREF[1]:     0049025d(j)
//         004901cc     MOV        this,dword ptr [EBP + 0x490]
//         004901d2     PUSH       EDI
//         004901d3     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004901d8     MOV        this,dword ptr [ESP + test[0]]
//         004901dc     PUSH       EAX
//         004901dd     ADD        this,ESI
//         004901df     PUSH       this
//         004901e0     CALL       getstring                                        void getstring(char * * param_1, char * param
//         004901e5     MOV        this,dword ptr [EBP + 0x490]
//         004901eb     ADD        ESP,0x8
//         004901ee     PUSH       EDI
//         004901ef     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
//         004901f4     PUSH       EAX
//         004901f5     PUSH       ESI
//         004901f6     CALL       getstring                                        void getstring(char * * param_1, char * param
//         004901fb     MOV        EAX,[rge_base_game]                              = 00000000
//         00490200     MOV        EDX,dword ptr [ESI]
//         00490202     ADD        ESP,0x8
//         00490205     MOV        this,dword ptr [EAX + 0xc]
//         00490208     ADD        this,0xc17
//         0049020e     PUSH       EDX
//         0049020f     PUSH       this
//         00490210     LEA        EDX=>test[4],[ESP + 0x2c]
//         00490214     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         00490219     PUSH       EDX
//         0049021a     CALL       sprintf                                          undefined sprintf()
//         0049021f     ADD        ESP,0x10
//         00490222     LEA        EAX=>file_info.time_create,[ESP + 0x128]
//         00490229     LEA        this=>test[4],[ESP + 0x24]
//         0049022d     PUSH       EAX
//         0049022e     PUSH       this
//         0049022f     CALL       __findfirst                                      undefined __findfirst()
//         00490234     ADD        ESP,0x8
//         00490237     CMP        EAX,-0x1
//         0049023a     JNZ        LAB_00490246
//         0049023c     MOV        EDX,dword ptr [ESI]
//         0049023e     PUSH       s_.scx                                           = ".scx"
//         00490243     PUSH       EDX
//         00490244     JMP        LAB_0049024e
//                               LAB_00490246                                                 XREF[1]:     0049023a(j)
//                              scr_cam.cpp:428 (35)
//         00490246     MOV        EAX,dword ptr [ESI]
//         00490248     PUSH       s_.scn                                           = ".scn"
//         0049024d     PUSH       EAX
//                               LAB_0049024e                                                 XREF[1]:     00490244(j)
//         0049024e     PUSH       ESI
//         0049024f     CALL       addstring                                        void addstring(char * * param_1, char * param
//         00490254     ADD        ESP,0xc
//         00490257     INC        EDI
//         00490258     ADD        ESI,0x4
//         0049025b     CMP        EDI,EBX
//         0049025d     JL         LAB_004901cc
//         00490263     MOV        ESI,dword ptr [ESP + local_230]
//         00490267     XOR        EDI,EDI
//                               LAB_00490269                                                 XREF[1]:     004901ba(j)
//                              scr_cam.cpp:431 (58)
//         00490269     PUSH       0x20c
//         0049026e     CALL       operator_new                                     void * operator_new(uint param_1)
//         00490273     ADD        ESP,0x4
//         00490276     MOV        dword ptr [ESP + local_230],EAX
//         0049027a     CMP        EAX,EDI
//         0049027c     MOV        dword ptr [ESP + local_4],EDI
//         00490283     JZ         LAB_004902a1
//         00490285     MOV        this,dword ptr [ESP + campaign_filename]
//         00490289     MOV        EDX,dword ptr [ESP + scenarios_text]
//         0049028d     PUSH       this
//         0049028e     MOV        this,dword ptr [ESP + text]
//         00490292     PUSH       EDX
//         00490293     PUSH       EBX
//         00490294     PUSH       ESI
//         00490295     PUSH       this
//         00490296     MOV        this,EAX
//         00490298     CALL       RGE_Campaign::RGE_Campaign                       undefined RGE_Campaign(RGE_Campaign * this, c
//         0049029d     MOV        ESI,EAX
//         0049029f     JMP        LAB_004902a3
//                               LAB_004902a1                                                 XREF[1]:     00490283(j)
//         004902a1     XOR        ESI,ESI
//                               LAB_004902a3                                                 XREF[1]:     0049029f(j)
//                              scr_cam.cpp:432 (37)
//         004902a3     CMP        ESI,EDI
//         004902a5     MOV        dword ptr [ESP + local_4],0xffffffff
//         004902b0     MOV        dword ptr [EBP + 0x4c0],ESI
//         004902b6     JZ         LAB_004902c8
//         004902b8     MOV        this,ESI
//         004902ba     CALL       RGE_Campaign::~RGE_Campaign                      void ~RGE_Campaign(RGE_Campaign * this)
//         004902bf     PUSH       ESI
//         004902c0     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004902c5     ADD        ESP,0x4
//                               LAB_004902c8                                                 XREF[1]:     004902b6(j)
//                              scr_cam.cpp:435 (22)
//         004902c8     CMP        EBX,EDI
//         004902ca     MOV        dword ptr [EBP + 0x4c0],EDI
//         004902d0     JLE        LAB_004902fb
//         004902d2     MOV        ESI,dword ptr [ESP + scenarios_text]
//         004902d6     MOV        EDI,dword ptr [ESP + campaign_filename]
//         004902da     MOV        EAX,ESI
//         004902dc     SUB        EDI,EAX
//                               LAB_004902de                                                 XREF[1]:     004902f9(j)
//                              scr_cam.cpp:437 (9)
//         004902de     MOV        EDX,dword ptr [ESI + EDI*0x1]
//         004902e1     PUSH       EDX
//         004902e2     CALL       free                                             undefined free()
//                              scr_cam.cpp:438 (20)
//         004902e7     MOV        EAX,dword ptr [ESI]
//         004902e9     ADD        ESP,0x4
//         004902ec     PUSH       EAX
//         004902ed     CALL       free                                             undefined free()
//         004902f2     ADD        ESP,0x4
//         004902f5     ADD        ESI,0x4
//         004902f8     DEC        EBX
//         004902f9     JNZ        LAB_004902de
//                               LAB_004902fb                                                 XREF[1]:     004902d0(j)
//                              scr_cam.cpp:440 (10)
//         004902fb     MOV        this,dword ptr [ESP + campaign_filename]
//         004902ff     PUSH       this
//         00490300     CALL       free                                             undefined free()
//                              scr_cam.cpp:441 (16)
//         00490305     MOV        EDX,dword ptr [ESP + scenarios_text]
//         00490309     ADD        ESP,0x4
//         0049030c     PUSH       EDX
//         0049030d     CALL       free                                             undefined free()
//         00490312     ADD        ESP,0x4
//                              scr_cam.cpp:443 (2)
//         00490315     JMP        LAB_0049032b
//                               LAB_00490317                                                 XREF[1]:     00490194(j)
//                              scr_cam.cpp:448 (20)
//         00490317     PUSH       0x64
//         00490319     PUSH       0x1c2
//         0049031e     PUSH       EDI
//                              language.dll match for 0x2bcb: "At least one scenario is requ
//         0049031f     PUSH       0x2bcb
//         00490324     MOV        this,EBP
//         00490326     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                               LAB_0049032b                                                 XREF[1]:     00490315(j)
//                              scr_cam.cpp:451 (13)
//         0049032b     MOV        EAX,dword ptr [ESP + text]
//         0049032f     PUSH       EAX
//         00490330     CALL       free                                             undefined free()
//         00490335     ADD        ESP,0x4
//                              scr_cam.cpp:452 (7)
//         00490338     MOV        this,EBP
//         0049033a     CALL       TRIBE_Campaign_Editor_Screen::fill_campaign_drop void fill_campaign_drop(TRIBE_Campaign_Editor
//                              scr_cam.cpp:453 (11)
//         0049033f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         00490345     CALL       RGE_Base_Game::find_campaigns                    void find_campaigns(RGE_Base_Game * this)
//                               LAB_0049034a                                                 XREF[1]:     0049015a(j)
//                              scr_cam.cpp:456 (7)
//         0049034a     MOV        byte ptr [EBP + 0x478],0x0
//                               LAB_00490351                                                 XREF[1]:     0049037e(j)
//                              scr_cam.cpp:457 (25)
//         00490351     MOV        this,dword ptr [ESP + local_c]
//         00490358     POP        EDI
//         00490359     POP        ESI
//         0049035a     POP        EBP
//         0049035b     MOV        dword ptr FS:[0x0],this
//         00490362     POP        EBX
//         00490363     ADD        ESP,0x23c
//         00490369     RET
//                               LAB_0049036a                                                 XREF[2]:     00490164(j), 0049016c(j)
//                              scr_cam.cpp:404 (20)
//         0049036a     PUSH       0x64
//         0049036c     PUSH       0x1c2
//         00490371     PUSH       EDI
//                              language.dll match for 0x2bcc: "Cannot save. You must enter a
//         00490372     PUSH       0x2bcc
//         00490377     MOV        this,EBP
//         00490379     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_cam.cpp:405 (2)
//         0049037e     JMP        LAB_00490351
    return;
}

void TRIBE_Campaign_Editor_Screen::add_scenario() {
    /* TODO: Stub */
//                              void __thiscall add_scenario(TRIBE_Campaign_Editor_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//                               ?add_scenario@TRIBE_Campaign_Editor_Screen@@IAEXXZ           XREF[2]:     action:00490659(c),
//                               TRIBE_Campaign_Editor_Screen::add_scenario                                action:00490800(c)
//                              scr_cam.cpp:463 (4)
//         00490380     PUSH       ESI
//         00490381     MOV        ESI,this
//         00490383     PUSH       EDI
//                              scr_cam.cpp:466 (13)
//         00490384     MOV        this,dword ptr [ESI + 0x48c]
//         0049038a     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//         0049038f     MOV        EDI,EAX
//                              scr_cam.cpp:467 (9)
//         00490391     TEST       EDI,EDI
//         00490393     JZ         LAB_004903f2
//         00490395     CMP        byte ptr [EDI],0x0
//         00490398     JZ         LAB_004903f2
//                              scr_cam.cpp:469 (14)
//         0049039a     MOV        this,dword ptr [ESI + 0x490]
//         004903a0     PUSH       0x0
//         004903a2     PUSH       EDI
//         004903a3     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_cam.cpp:470 (24)
//         004903a8     MOV        this,dword ptr [ESI + 0x490]
//         004903ae     PUSH       EDI
//         004903af     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//         004903b4     MOV        this,dword ptr [ESI + 0x490]
//         004903ba     PUSH       EAX
//         004903bb     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
//                              scr_cam.cpp:471 (23)
//         004903c0     MOV        this,dword ptr [ESI + 0x48c]
//         004903c6     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004903cb     MOV        this,dword ptr [ESI + 0x48c]
//         004903d1     PUSH       EAX
//         004903d2     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                              scr_cam.cpp:473 (27)
//         004903d7     MOV        this,dword ptr [ESI + 0x490]
//         004903dd     PUSH       0x1
//         004903df     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004903e4     MOV        this,dword ptr [ESI + 0x490]
//         004903ea     PUSH       EAX
//         004903eb     PUSH       0x1
//         004903ed     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_004903f2                                                 XREF[2]:     00490393(j), 00490398(j)
//                              scr_cam.cpp:476 (7)
//         004903f2     MOV        byte ptr [ESI + 0x478],0x1
//                              scr_cam.cpp:477 (3)
//         004903f9     POP        EDI
//         004903fa     POP        ESI
//         004903fb     RET
//         004903fc     ??         90h
//         004903fd     NOP
//         004903fe     NOP
//         004903ff     NOP
    return;
}

void TRIBE_Campaign_Editor_Screen::remove_scenario() {
    /* TODO: Stub */
//                              void __thiscall remove_scenario(TRIBE_Campaign_Editor_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//                               ?remove_scenario@TRIBE_Campaign_Editor_Screen@@IAEXXZ        XREF[2]:     action:0049066a(c),
//                               TRIBE_Campaign_Editor_Screen::remove_scenario                             action:00490811(c)
//                              scr_cam.cpp:483 (4)
//         00490400     PUSH       ESI
//         00490401     MOV        ESI,this
//         00490403     PUSH       EDI
//                              scr_cam.cpp:486 (13)
//         00490404     MOV        this,dword ptr [ESI + 0x490]
//         0049040a     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//         0049040f     MOV        EDI,EAX
//                              scr_cam.cpp:487 (9)
//         00490411     TEST       EDI,EDI
//         00490413     JZ         LAB_00490472
//         00490415     CMP        byte ptr [EDI],0x0
//         00490418     JZ         LAB_00490472
//                              scr_cam.cpp:489 (14)
//         0049041a     MOV        this,dword ptr [ESI + 0x48c]
//         00490420     PUSH       0x0
//         00490422     PUSH       EDI
//         00490423     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
//                              scr_cam.cpp:490 (24)
//         00490428     MOV        this,dword ptr [ESI + 0x48c]
//         0049042e     PUSH       EDI
//         0049042f     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
//         00490434     MOV        this,dword ptr [ESI + 0x48c]
//         0049043a     PUSH       EAX
//         0049043b     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
//                              scr_cam.cpp:491 (23)
//         00490440     MOV        this,dword ptr [ESI + 0x490]
//         00490446     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         0049044b     MOV        this,dword ptr [ESI + 0x490]
//         00490451     PUSH       EAX
//         00490452     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                              scr_cam.cpp:493 (27)
//         00490457     MOV        this,dword ptr [ESI + 0x48c]
//         0049045d     PUSH       0x1
//         0049045f     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         00490464     MOV        this,dword ptr [ESI + 0x48c]
//         0049046a     PUSH       EAX
//         0049046b     PUSH       0x1
//         0049046d     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_00490472                                                 XREF[2]:     00490413(j), 00490418(j)
//                              scr_cam.cpp:496 (7)
//         00490472     MOV        byte ptr [ESI + 0x478],0x1
//                              scr_cam.cpp:497 (3)
//         00490479     POP        EDI
//         0049047a     POP        ESI
//         0049047b     RET
//         0049047c     ??         90h
//         0049047d     NOP
//         0049047e     NOP
//         0049047f     NOP
    return;
}

void TRIBE_Campaign_Editor_Screen::move_scenario_up() {
    /* TODO: Stub */
//                              void __thiscall move_scenario_up(TRIBE_Campaign_Editor_Screen * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//                               ?move_scenario_up@TRIBE_Campaign_Editor_Screen@@IAEXXZ       XREF[1]:     action:00490822(c)
//                               TRIBE_Campaign_Editor_Screen::move_scenario_up
//                              scr_cam.cpp:503 (3)
//         00490480     PUSH       ESI
//         00490481     MOV        ESI,this
//                              scr_cam.cpp:506 (19)
//         00490483     MOV        this,dword ptr [ESI + 0x490]
//         00490489     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         0049048e     TEST       EAX,EAX
//         00490490     JLE        LAB_00490517
//                              scr_cam.cpp:508 (11)
//         00490496     MOV        this,dword ptr [ESI + 0x490]
//         0049049c     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//                              scr_cam.cpp:509 (9)
//         004904a1     TEST       EAX,EAX
//         004904a3     JZ         LAB_00490510
//         004904a5     CMP        byte ptr [EAX],0x0
//         004904a8     JZ         LAB_00490510
//                              scr_cam.cpp:511 (27)
//         004904aa     MOV        this,dword ptr [ESI + 0x490]
//         004904b0     PUSH       0x0
//         004904b2     PUSH       EAX
//         004904b3     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004904b8     MOV        this,dword ptr [ESI + 0x490]
//         004904be     DEC        EAX
//         004904bf     PUSH       EAX
//         004904c0     CALL       TTextPanel::insert_line                          int insert_line(TTextPanel * this, long param
//                              scr_cam.cpp:512 (24)
//         004904c5     MOV        this,dword ptr [ESI + 0x490]
//         004904cb     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004904d0     MOV        this,dword ptr [ESI + 0x490]
//         004904d6     INC        EAX
//         004904d7     PUSH       EAX
//         004904d8     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                              scr_cam.cpp:513 (24)
//         004904dd     MOV        this,dword ptr [ESI + 0x490]
//         004904e3     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004904e8     MOV        this,dword ptr [ESI + 0x490]
//         004904ee     DEC        EAX
//         004904ef     PUSH       EAX
//         004904f0     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
//                              scr_cam.cpp:515 (27)
//         004904f5     MOV        this,dword ptr [ESI + 0x490]
//         004904fb     PUSH       0x1
//         004904fd     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         00490502     MOV        this,dword ptr [ESI + 0x490]
//         00490508     PUSH       EAX
//         00490509     PUSH       0x1
//         0049050b     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_00490510                                                 XREF[2]:     004904a3(j), 004904a8(j)
//                              scr_cam.cpp:518 (7)
//         00490510     MOV        byte ptr [ESI + 0x478],0x1
//                               LAB_00490517                                                 XREF[1]:     00490490(j)
//                              scr_cam.cpp:520 (2)
//         00490517     POP        ESI
//         00490518     RET
//         00490519     ??         90h
//         0049051a     NOP
//         0049051b     NOP
//         0049051c     NOP
//         0049051d     NOP
//         0049051e     NOP
//         0049051f     NOP
    return;
}

void TRIBE_Campaign_Editor_Screen::move_scenario_down() {
    /* TODO: Stub */
//                              void __thiscall move_scenario_down(TRIBE_Campaign_Editor_Screen * th
//              void              <VOID>         <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//                               ?move_scenario_down@TRIBE_Campaign_Editor_Screen@@IAEXXZ     XREF[1]:     action:00490833(c)
//                               TRIBE_Campaign_Editor_Screen::move_scenario_down
//                              scr_cam.cpp:526 (4)
//         00490520     PUSH       ESI
//         00490521     MOV        ESI,this
//         00490523     PUSH       EDI
//                              scr_cam.cpp:529 (33)
//         00490524     MOV        this,dword ptr [ESI + 0x490]
//         0049052a     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         0049052f     MOV        this,dword ptr [ESI + 0x490]
//         00490535     MOV        EDI,EAX
//         00490537     DEC        EDI
//         00490538     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         0049053d     CMP        EAX,EDI
//         0049053f     JGE        LAB_004905c7
//                              scr_cam.cpp:531 (11)
//         00490545     MOV        this,dword ptr [ESI + 0x490]
//         0049054b     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
//                              scr_cam.cpp:532 (9)
//         00490550     TEST       EAX,EAX
//         00490552     JZ         LAB_004905c0
//         00490554     CMP        byte ptr [EAX],0x0
//         00490557     JZ         LAB_004905c0
//                              scr_cam.cpp:534 (29)
//         00490559     MOV        this,dword ptr [ESI + 0x490]
//         0049055f     PUSH       0x0
//         00490561     PUSH       EAX
//         00490562     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         00490567     MOV        this,dword ptr [ESI + 0x490]
//         0049056d     ADD        EAX,0x2
//         00490570     PUSH       EAX
//         00490571     CALL       TTextPanel::insert_line                          int insert_line(TTextPanel * this, long param
//                              scr_cam.cpp:535 (23)
//         00490576     MOV        this,dword ptr [ESI + 0x490]
//         0049057c     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         00490581     MOV        this,dword ptr [ESI + 0x490]
//         00490587     PUSH       EAX
//         00490588     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                              scr_cam.cpp:536 (24)
//         0049058d     MOV        this,dword ptr [ESI + 0x490]
//         00490593     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         00490598     MOV        this,dword ptr [ESI + 0x490]
//         0049059e     INC        EAX
//         0049059f     PUSH       EAX
//         004905a0     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
//                              scr_cam.cpp:538 (27)
//         004905a5     MOV        this,dword ptr [ESI + 0x490]
//         004905ab     PUSH       0x1
//         004905ad     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
//         004905b2     MOV        this,dword ptr [ESI + 0x490]
//         004905b8     PUSH       EAX
//         004905b9     PUSH       0x1
//         004905bb     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
//                               LAB_004905c0                                                 XREF[2]:     00490552(j), 00490557(j)
//                              scr_cam.cpp:541 (7)
//         004905c0     MOV        byte ptr [ESI + 0x478],0x1
//                               LAB_004905c7                                                 XREF[1]:     0049053f(j)
//                              scr_cam.cpp:543 (3)
//         004905c7     POP        EDI
//         004905c8     POP        ESI
//         004905c9     RET
//         004905ca     ??         90h
//         004905cb     NOP
//         004905cc     NOP
//         004905cd     NOP
//         004905ce     NOP
//         004905cf     NOP
    return;
}

long TRIBE_Campaign_Editor_Screen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TRIBE_Campaign_Editor_Screen * this, TPanel *
//              long              EAX:4          <RETURN>
//              TRIBE_Campaign    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004905ed(R)
//              long              Stack[0x8]:4   param_2                   XREF[2]:     0049060a(R), 00490620(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[2]:     00490603(R), 0049099e(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[2]:     004905fc(R), 00490997(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004907a6(W), 004907e6(W), 004908bc(W), 004908de(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004909b0(R)
//              char[300]         Stack[-0x13c   text                      XREF[0,4]:   004906c2(*), 004906d3(*), 00490762(*), 00490773(*)
//              char[256]         Stack[-0x23c   str                       XREF[3,4]:   004907a0(W), 004907e2(W), 004908b8(W), 0049069c(*),
//                                                                                     004906be(*), 0049073c(*), 0049075d(*)
//                               ?action@TRIBE_Campaign_Editor_Screen@@MAEJPAVTPanel@@JKK@Z   XREF[1]:     0057235c(*)
//                               TRIBE_Campaign_Editor_Screen::action
//                              scr_cam.cpp:549 (29)
//         004905d0     MOV        EAX,FS:[0x0]
//         004905d6     PUSH       -0x1
//         004905d8     PUSH       FUN_0055e92a
//         004905dd     PUSH       EAX
//         004905de     MOV        dword ptr FS:[0x0],ESP
//         004905e5     SUB        ESP,0x230
//         004905eb     PUSH       EBX
//         004905ec     PUSH       EBP
//                              scr_cam.cpp:552 (15)
//         004905ed     MOV        EBP,dword ptr [ESP + param_1]
//         004905f4     PUSH       ESI
//         004905f5     PUSH       EDI
//         004905f6     MOV        EDI,this
//         004905f8     TEST       EBP,EBP
//         004905fa     JNZ        LAB_0049061a
//                              scr_cam.cpp:553 (30)
//         004905fc     MOV        EAX,dword ptr [ESP + param_4]
//         00490603     MOV        this,dword ptr [ESP + param_3]
//         0049060a     MOV        EDX,dword ptr [ESP + param_2]
//         00490611     PUSH       EAX
//         00490612     PUSH       this
//         00490613     PUSH       EDX
//         00490614     PUSH       EBP
//         00490615     JMP        LAB_004909a9
//                               LAB_0049061a                                                 XREF[1]:     004905fa(j)
//                              scr_cam.cpp:555 (22)
//         0049061a     MOV        this,dword ptr [EDI + 0x4bc]
//         00490620     MOV        EBX,dword ptr [ESP + param_2]
//         00490627     CMP        EBP,this
//         00490629     JNZ        LAB_0049064a
//         0049062b     CMP        EBX,0x2
//         0049062e     JNZ        LAB_0049064a
//                              scr_cam.cpp:557 (12)
//         00490630     MOV        EAX,dword ptr [EDI + 0x49c]
//         00490636     PUSH       EAX
//         00490637     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_cam.cpp:558 (14)
//         0049063c     MOV        this,dword ptr [EDI + 0x4bc]
//         00490642     PUSH       this
//         00490643     MOV        this,EDI
//         00490645     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_0049064a                                                 XREF[2]:     00490629(j), 0049062e(j)
//                              scr_cam.cpp:561 (5)
//         0049064a     CMP        EBX,0x3
//         0049064d     JNZ        LAB_0049066f
//                              scr_cam.cpp:563 (8)
//         0049064f     CMP        EBP,dword ptr [EDI + 0x48c]
//         00490655     JNZ        LAB_00490660
//                              scr_cam.cpp:564 (7)
//         00490657     MOV        this,EDI
//         00490659     CALL       TRIBE_Campaign_Editor_Screen::add_scenario       void add_scenario(TRIBE_Campaign_Editor_Scree
//                              scr_cam.cpp:565 (10)
//         0049065e     JMP        LAB_0049066f
//                               LAB_00490660                                                 XREF[1]:     00490655(j)
//         00490660     CMP        EBP,dword ptr [EDI + 0x490]
//         00490666     JNZ        LAB_0049066f
//                              scr_cam.cpp:566 (7)
//         00490668     MOV        this,EDI
//         0049066a     CALL       TRIBE_Campaign_Editor_Screen::remove_scenario    void remove_scenario(TRIBE_Campaign_Editor_Sc
//                               LAB_0049066f                                                 XREF[3]:     0049064d(j), 0049065e(j),
//                                                                                                         00490666(j)
//                              scr_cam.cpp:569 (20)
//         0049066f     CMP        EBP,dword ptr [EDI + 0x4bc]
//         00490675     JNZ        LAB_0049070e
//         0049067b     TEST       EBX,EBX
//         0049067d     JNZ        LAB_0049070e
//                              scr_cam.cpp:571 (25)
//         00490683     MOV        AL,byte ptr [EDI + 0x478]
//         00490689     TEST       AL,AL
//         0049068b     JBE        LAB_004906f0
//         0049068d     MOV        this,dword ptr [EDI + 0x490]
//         00490693     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00490698     TEST       EAX,EAX
//         0049069a     JLE        LAB_004906f0
//                              scr_cam.cpp:574 (22)
//         0049069c     LEA        EDX=>str[4],[ESP + 0x14]
//         004906a0     PUSH       0x100
//         004906a5     PUSH       EDX
//                              language.dll match for 0x2bc9: "Do you want to save your chan
//         004906a6     PUSH       0x2bc9
//         004906ab     MOV        this,EDI
//         004906ad     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_cam.cpp:575 (33)
//         004906b2     MOV        this,dword ptr [EDI + 0x49c]
//         004906b8     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
//         004906bd     PUSH       EAX
//         004906be     LEA        EAX=>str[4],[ESP + 0x18]
//         004906c2     LEA        this=>text[4],[ESP + 0x118]
//         004906c9     PUSH       EAX
//         004906ca     PUSH       this
//         004906cb     CALL       sprintf                                          undefined sprintf()
//         004906d0     ADD        ESP,0xc
//                              scr_cam.cpp:576 (27)
//         004906d3     LEA        EDX=>text[4],[ESP + 0x114]
//         004906da     MOV        this,EDI
//         004906dc     PUSH       0x64
//         004906de     PUSH       0x1c2
//         004906e3     PUSH       s_Load_Dialog                                    = 4Ch
//         004906e8     PUSH       EDX
//         004906e9     CALL       TEasy_Panel::popupYesNoCancelDialog              void popupYesNoCancelDialog(TEasy_Panel * thi
//                              scr_cam.cpp:578 (2)
//         004906ee     JMP        LAB_0049070e
//                               LAB_004906f0                                                 XREF[2]:     0049068b(j), 0049069a(j)
//                              scr_cam.cpp:580 (23)
//         004906f0     MOV        this,dword ptr [EDI + 0x4bc]
//         004906f6     CALL       TDropDownPanel::get_text                         char * get_text(TDropDownPanel * this)
//         004906fb     MOV        this,dword ptr [EDI + 0x49c]
//         00490701     PUSH       EAX
//         00490702     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_cam.cpp:581 (7)
//         00490707     MOV        this,EDI
//         00490709     CALL       TRIBE_Campaign_Editor_Screen::load_campaign      void load_campaign(TRIBE_Campaign_Editor_Scre
//                               LAB_0049070e                                                 XREF[3]:     00490675(j), 0049067d(j),
//                                                                                                         004906ee(j)
//                              scr_cam.cpp:585 (9)
//         0049070e     CMP        EBX,0x1
//         00490711     JNZ        LAB_00490838
//                              scr_cam.cpp:587 (12)
//         00490717     CMP        EBP,dword ptr [EDI + 0x4a0]
//         0049071d     JNZ        LAB_004907bc
//                              scr_cam.cpp:589 (25)
//         00490723     MOV        AL,byte ptr [EDI + 0x478]
//         00490729     TEST       AL,AL
//         0049072b     JBE        LAB_00490793
//         0049072d     MOV        this,dword ptr [EDI + 0x490]
//         00490733     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         00490738     TEST       EAX,EAX
//         0049073a     JLE        LAB_00490793
//                              scr_cam.cpp:592 (22)
//         0049073c     LEA        EAX=>str[4],[ESP + 0x14]
//         00490740     PUSH       0x100
//         00490745     PUSH       EAX
//                              language.dll match for 0x2bc9: "Do you want to save your chan
//         00490746     PUSH       0x2bc9
//         0049074b     MOV        this,EDI
//         0049074d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_cam.cpp:593 (33)
//         00490752     MOV        this,dword ptr [EDI + 0x49c]
//         00490758     CALL       TEditPanel::get_text                             char * get_text(TEditPanel * this)
//         0049075d     LEA        this=>str[4],[ESP + 0x14]
//         00490761     PUSH       EAX
//         00490762     LEA        EDX=>text[4],[ESP + 0x118]
//         00490769     PUSH       this
//         0049076a     PUSH       EDX
//         0049076b     CALL       sprintf                                          undefined sprintf()
//         00490770     ADD        ESP,0xc
//                              scr_cam.cpp:594 (27)
//         00490773     LEA        EAX=>text[4],[ESP + 0x114]
//         0049077a     MOV        this,EDI
//         0049077c     PUSH       0x64
//         0049077e     PUSH       0x1c2
//         00490783     PUSH       s_Cancel_Dialog                                  = 43h
//         00490788     PUSH       EAX
//         00490789     CALL       TEasy_Panel::popupYesNoCancelDialog              void popupYesNoCancelDialog(TEasy_Panel * thi
//                              scr_cam.cpp:605 (5)
//         0049078e     JMP        LAB_00490838
//                               LAB_00490793                                                 XREF[2]:     0049072b(j), 0049073a(j)
//                              scr_cam.cpp:598 (36)
//         00490793     PUSH       0x490
//         00490798     CALL       operator_new                                     void * operator_new(uint param_1)
//         0049079d     ADD        ESP,0x4
//         004907a0     MOV        dword ptr [ESP + str[0]],EAX
//         004907a4     TEST       EAX,EAX
//         004907a6     MOV        dword ptr [ESP + local_4],0x0
//         004907b1     JZ         LAB_004908d2
//                              scr_cam.cpp:602 (5)
//         004907b7     JMP        LAB_004908cb
//                               LAB_004907bc                                                 XREF[1]:     0049071d(j)
//                              scr_cam.cpp:605 (8)
//         004907bc     CMP        EBP,dword ptr [EDI + 0x4a8]
//         004907c2     JNZ        LAB_004907cd
//                              scr_cam.cpp:606 (7)
//         004907c4     MOV        this,EDI
//         004907c6     CALL       TRIBE_Campaign_Editor_Screen::make_campaign      void make_campaign(TRIBE_Campaign_Editor_Scre
//                              scr_cam.cpp:607 (10)
//         004907cb     JMP        LAB_00490838
//                               LAB_004907cd                                                 XREF[1]:     004907c2(j)
//         004907cd     CMP        EBP,dword ptr [EDI + 0x4a4]
//         004907d3     JNZ        LAB_004907f6
//                              scr_cam.cpp:609 (28)
//         004907d5     PUSH       0x490
//         004907da     CALL       operator_new                                     void * operator_new(uint param_1)
//         004907df     ADD        ESP,0x4
//         004907e2     MOV        dword ptr [ESP + str[0]],EAX
//         004907e6     MOV        dword ptr [ESP + local_4],0x1
//                              scr_cam.cpp:613 (5)
//         004907f1     JMP        LAB_004908c7
//                               LAB_004907f6                                                 XREF[1]:     004907d3(j)
//                              scr_cam.cpp:615 (8)
//         004907f6     CMP        EBP,dword ptr [EDI + 0x4ac]
//         004907fc     JNZ        LAB_00490807
//                              scr_cam.cpp:616 (7)
//         004907fe     MOV        this,EDI
//         00490800     CALL       TRIBE_Campaign_Editor_Screen::add_scenario       void add_scenario(TRIBE_Campaign_Editor_Scree
//                              scr_cam.cpp:617 (10)
//         00490805     JMP        LAB_00490838
//                               LAB_00490807                                                 XREF[1]:     004907fc(j)
//         00490807     CMP        EBP,dword ptr [EDI + 0x4b0]
//         0049080d     JNZ        LAB_00490818
//                              scr_cam.cpp:618 (7)
//         0049080f     MOV        this,EDI
//         00490811     CALL       TRIBE_Campaign_Editor_Screen::remove_scenario    void remove_scenario(TRIBE_Campaign_Editor_Sc
//                              scr_cam.cpp:619 (10)
//         00490816     JMP        LAB_00490838
//                               LAB_00490818                                                 XREF[1]:     0049080d(j)
//         00490818     CMP        EBP,dword ptr [EDI + 0x4b4]
//         0049081e     JNZ        LAB_00490829
//                              scr_cam.cpp:620 (7)
//         00490820     MOV        this,EDI
//         00490822     CALL       TRIBE_Campaign_Editor_Screen::move_scenario_up   void move_scenario_up(TRIBE_Campaign_Editor_S
//                              scr_cam.cpp:621 (10)
//         00490827     JMP        LAB_00490838
//                               LAB_00490829                                                 XREF[1]:     0049081e(j)
//         00490829     CMP        EBP,dword ptr [EDI + 0x4b8]
//         0049082f     JNZ        LAB_00490838
//                              scr_cam.cpp:622 (7)
//         00490831     MOV        this,EDI
//         00490833     CALL       TRIBE_Campaign_Editor_Screen::move_scenario_down void move_scenario_down(TRIBE_Campaign_Editor
//                               LAB_00490838                                                 XREF[7]:     00490711(j), 0049078e(j),
//                                                                                                         004907cb(j), 00490805(j),
//                                                                                                         00490816(j), 00490827(j),
//                                                                                                         0049082f(j)
//                              scr_cam.cpp:625 (76)
//         00490838     MOV        this,EBP
//         0049083a     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         0049083f     TEST       EAX,EAX
//         00490841     JZ         LAB_00490907
//         00490847     MOV        this,EBP
//         00490849     MOV        ESI,s_Cancel_Dialog                              = 43h
//         0049084e     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_00490853                                                 XREF[1]:     00490871(j)
//         00490853     MOV        DL,byte ptr [EAX]
//         00490855     MOV        this,DL
//         00490857     CMP        DL,byte ptr [ESI]=>s_Cancel_Dialog               = 43h
//                                                                                  = 6Eh
//         00490859     JNZ        LAB_00490877
//         0049085b     TEST       this,this
//         0049085d     JZ         LAB_00490873
//         0049085f     MOV        DL,byte ptr [EAX + 0x1]
//         00490862     MOV        this,DL
//         00490864     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005860e5            = 61h
//                                                                                  = "cel Dialog"
//         00490867     JNZ        LAB_00490877
//         00490869     ADD        EAX,0x2
//         0049086c     ADD        ESI,0x2
//         0049086f     TEST       this,this
//         00490871     JNZ        LAB_00490853
//                               LAB_00490873                                                 XREF[1]:     0049085d(j)
//         00490873     XOR        EAX,EAX
//         00490875     JMP        LAB_0049087c
//                               LAB_00490877                                                 XREF[2]:     00490859(j), 00490867(j)
//         00490877     SBB        EAX,EAX
//         00490879     SBB        EAX,-0x1
//                               LAB_0049087c                                                 XREF[1]:     00490875(j)
//         0049087c     TEST       EAX,EAX
//         0049087e     JNZ        LAB_00490907
//                              scr_cam.cpp:627 (15)
//         00490884     PUSH       s_Cancel_Dialog                                  = 43h
//         00490889     MOV        this,panel_system
//         0049088e     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_cam.cpp:629 (4)
//         00490893     TEST       EBX,EBX
//         00490895     JNZ        LAB_004908a2
//                              scr_cam.cpp:630 (7)
//         00490897     MOV        this,EDI
//         00490899     CALL       TRIBE_Campaign_Editor_Screen::make_campaign      void make_campaign(TRIBE_Campaign_Editor_Scre
//                              scr_cam.cpp:632 (13)
//         0049089e     TEST       EBX,EBX
//         004908a0     JZ         LAB_004908ab
//                               LAB_004908a2                                                 XREF[1]:     00490895(j)
//         004908a2     CMP        EBX,0x1
//         004908a5     JNZ        LAB_00490990
//                               LAB_004908ab                                                 XREF[1]:     004908a0(j)
//                              scr_cam.cpp:634 (39)
//         004908ab     PUSH       0x490
//         004908b0     CALL       operator_new                                     void * operator_new(uint param_1)
//         004908b5     ADD        ESP,0x4
//         004908b8     MOV        dword ptr [ESP + str[0]],EAX
//         004908bc     MOV        dword ptr [ESP + local_4],0x2
//                               LAB_004908c7                                                 XREF[1]:     004907f1(j)
//         004908c7     TEST       EAX,EAX
//         004908c9     JZ         LAB_004908d2
//                               LAB_004908cb                                                 XREF[1]:     004907b7(j)
//         004908cb     MOV        this,EAX
//         004908cd     CALL       TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu     undefined TRIBE_Screen_Sed_Menu(TRIBE_Screen_
//                               LAB_004908d2                                                 XREF[2]:     004907b1(j), 004908c9(j)
//                              scr_cam.cpp:635 (28)
//         004908d2     PUSH       0x0
//         004908d4     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
//         004908d9     MOV        this,panel_system
//         004908de     MOV        dword ptr [ESP + local_4],0xffffffff
//         004908e9     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              scr_cam.cpp:637 (15)
//         004908ee     PUSH       s_Campaign_Editor_Screen                         = "Campaign Editor Screen"
//         004908f3     MOV        this,panel_system
//         004908f8     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_cam.cpp:639 (10)
//         004908fd     MOV        EAX,0x1
//         00490902     JMP        LAB_004909b0
//                               LAB_00490907                                                 XREF[2]:     00490841(j), 0049087e(j)
//                              scr_cam.cpp:642 (72)
//         00490907     MOV        this,EBP
//         00490909     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         0049090e     TEST       EAX,EAX
//         00490910     JZ         LAB_00490997
//         00490916     MOV        this,EBP
//         00490918     MOV        ESI,s_Load_Dialog                                = 4Ch
//         0049091d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_00490922                                                 XREF[1]:     00490940(j)
//         00490922     MOV        DL,byte ptr [EAX]
//         00490924     MOV        this,DL
//         00490926     CMP        DL,byte ptr [ESI]=>s_Load_Dialog                 = 4Ch
//                                                                                  = 61h
//         00490928     JNZ        LAB_00490946
//         0049092a     TEST       this,this
//         0049092c     JZ         LAB_00490942
//         0049092e     MOV        DL,byte ptr [EAX + 0x1]
//         00490931     MOV        this,DL
//         00490933     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005860d9            = 6Fh
//                                                                                  = "d Dialog"
//         00490936     JNZ        LAB_00490946
//         00490938     ADD        EAX,0x2
//         0049093b     ADD        ESI,0x2
//         0049093e     TEST       this,this
//         00490940     JNZ        LAB_00490922
//                               LAB_00490942                                                 XREF[1]:     0049092c(j)
//         00490942     XOR        EAX,EAX
//         00490944     JMP        LAB_0049094b
//                               LAB_00490946                                                 XREF[2]:     00490928(j), 00490936(j)
//         00490946     SBB        EAX,EAX
//         00490948     SBB        EAX,-0x1
//                               LAB_0049094b                                                 XREF[1]:     00490944(j)
//         0049094b     TEST       EAX,EAX
//         0049094d     JNZ        LAB_00490997
//                              scr_cam.cpp:644 (15)
//         0049094f     PUSH       s_Load_Dialog                                    = 4Ch
//         00490954     MOV        this,panel_system
//         00490959     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_cam.cpp:646 (4)
//         0049095e     TEST       EBX,EBX
//         00490960     JNZ        LAB_0049096d
//                              scr_cam.cpp:647 (7)
//         00490962     MOV        this,EDI
//         00490964     CALL       TRIBE_Campaign_Editor_Screen::make_campaign      void make_campaign(TRIBE_Campaign_Editor_Scre
//                              scr_cam.cpp:649 (9)
//         00490969     TEST       EBX,EBX
//         0049096b     JZ         LAB_00490972
//                               LAB_0049096d                                                 XREF[1]:     00490960(j)
//         0049096d     CMP        EBX,0x1
//         00490970     JNZ        LAB_00490990
//                               LAB_00490972                                                 XREF[1]:     0049096b(j)
//                              scr_cam.cpp:651 (23)
//         00490972     MOV        this,dword ptr [EDI + 0x4bc]
//         00490978     CALL       TDropDownPanel::get_text                         char * get_text(TDropDownPanel * this)
//         0049097d     MOV        this,dword ptr [EDI + 0x49c]
//         00490983     PUSH       EAX
//         00490984     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_cam.cpp:652 (7)
//         00490989     MOV        this,EDI
//         0049098b     CALL       TRIBE_Campaign_Editor_Screen::load_campaign      void load_campaign(TRIBE_Campaign_Editor_Scre
//                               LAB_00490990                                                 XREF[2]:     004908a5(j), 00490970(j)
//                              scr_cam.cpp:654 (7)
//         00490990     MOV        EAX,0x1
//         00490995     JMP        LAB_004909b0
//                               LAB_00490997                                                 XREF[2]:     00490910(j), 0049094d(j)
//                              scr_cam.cpp:657 (25)
//         00490997     MOV        EAX,dword ptr [ESP + param_4]
//         0049099e     MOV        this,dword ptr [ESP + param_3]
//         004909a5     PUSH       EAX
//         004909a6     PUSH       this
//         004909a7     PUSH       EBX
//         004909a8     PUSH       EBP
//                               LAB_004909a9                                                 XREF[1]:     00490615(j)
//         004909a9     MOV        this,EDI
//         004909ab     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                               LAB_004909b0                                                 XREF[2]:     00490902(j), 00490995(j)
//                              scr_cam.cpp:658 (27)
//         004909b0     MOV        this,dword ptr [ESP + local_c]
//         004909b7     POP        EDI
//         004909b8     POP        ESI
//         004909b9     POP        EBP
//         004909ba     MOV        dword ptr FS:[0x0],this
//         004909c1     POP        EBX
//         004909c2     ADD        ESP,0x23c
//         004909c8     RET        0x10
//         004909cb     ??         90h
//         004909cc     NOP
//         004909cd     NOP
//         004909ce     NOP
//         004909cf     NOP
    return 0;
}

