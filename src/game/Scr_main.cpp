#include "../common.h"
#include "Scr_main.h"

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu() {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Screen_Main_Menu(TRIBE_Screen_Main_Menu *
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     0049e73f(W), 0049e8ce(W), 0049e8e5(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049ebb6(R)
//              char[512]         Stack[-0x210   temp_str                  XREF[0,7]:   0049e85f(*), 0049e875(R), 0049ea70(*), 0049ea9f(*),
//                                                                                     0049eac3(*), 0049eb02(*), 0049eb39(*)
//              TPanel *[5]       Stack[-0x224   tabList                   XREF[1]:     0049e6f6(W)
//              tagRECT           Stack[-0x238   rect                      XREF[3,6]:   0049e8c8(W), 0049e9a9(W), 0049e9da(R), 0049e8a7(*),
//                                                                                     0049e972(*), 0049e8f9(R), 0049e92a(R), 0049e8fd(R),
//                                                                                     0049e989(R)
//              undefined4        Stack[-0x23c   local_23c                 XREF[2]:     0049e999(W), 0049e9d6(R)
//              int               Stack[-0x240   diff
//                               ??0TRIBE_Screen_Main_Menu@@QAE@XZ                            XREF[6]:     close_screen:00492e2a(c),
//                               TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu                            close_screen:0049dba0(c),
//                                                                                                         action:0049fcb2(c),
//                                                                                                         action:004b3335(c),
//                                                                                                         action:004b7099(c),
//                                                                                                         start_menu:00524077(c)
//                              Scr_main.cpp:85 (55)
//         0049e6d0     PUSH       -0x1
//         0049e6d2     PUSH       FUN_0055f029
//         0049e6d7     MOV        EAX,FS:[0x0]
//         0049e6dd     PUSH       EAX
//         0049e6de     MOV        dword ptr FS:[0x0],ESP
//         0049e6e5     SUB        ESP,0x230
//         0049e6eb     PUSH       EBX
//         0049e6ec     PUSH       EBP
//         0049e6ed     PUSH       ESI
//         0049e6ee     PUSH       EDI
//         0049e6ef     MOV        EBP,this
//         0049e6f1     PUSH       s_Main_Menu                                      = "Main Menu"
//         0049e6f6     MOV        dword ptr [ESP + tabList[0]],EBP
//         0049e6fa     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//         0049e6ff     LEA        EBX,[EBP + 0x480]
//         0049e705     XOR        EAX,EAX
//                              Scr_main.cpp:99 (63)
//         0049e707     MOV        this,0x7
//         0049e70c     MOV        EDI,EBX
//         0049e70e     MOV        dword ptr [EBP],TRIBE_Screen_Main_Menu::`vftab   = 0049ebe0
//         0049e715     MOV        dword ptr [EBP + 0x478],EAX
//         0049e71b     MOV        dword ptr [EBP + 0x47c],EAX
//         0049e721     MOV        dword ptr [EBP + 0x4ac],EAX
//         0049e727     MOV        dword ptr [EBP + 0x49c],EAX
//         0049e72d     MOV        dword ptr [EBP + 0x4a0],EAX
//         0049e733     MOV        dword ptr [EBP + 0x4a4],EAX
//         0049e739     MOV        dword ptr [EBP + 0x4a8],EAX
//         0049e73f     MOV        dword ptr [ESP + local_4],EAX
//                              Scr_main.cpp:102 (34)
//         0049e746     PUSH       0x1
//         0049e748     STOSD.REP  ES:EDI
//         0049e74a     MOV        EAX,[rge_base_game]                              = 00000000
//         0049e74f     PUSH       0xc383
//         0049e754     PUSH       s_scr1                                           = "scr1"
//         0049e759     MOV        this,dword ptr [EAX + 0x4c]
//         0049e75c     PUSH       this
//         0049e75d     MOV        this,EBP
//         0049e75f     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         0049e764     TEST       EAX,EAX
//         0049e766     JNZ        LAB_0049e777
//                              Scr_main.cpp:104 (10)
//         0049e768     MOV        dword ptr [EBP + 0xd8],0x1
//                              Scr_main.cpp:105 (5)
//         0049e772     JMP        LAB_0049ebb6
//                               LAB_0049e777                                                 XREF[1]:     0049e766(j)
//                              Scr_main.cpp:108 (24)
//         0049e777     PUSH       0x1e0
//         0049e77c     PUSH       0x280
//         0049e781     MOV        this,EBP
//         0049e783     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//         0049e788     MOV        ESI,0xb2
//         0049e78d     MOV        EDI,EBX
//                               LAB_0049e78f                                                 XREF[1]:     0049e7c6(j)
//                              Scr_main.cpp:115 (57)
//         0049e78f     PUSH       0x0
//         0049e791     PUSH       0x0
//         0049e793     PUSH       0x0
//         0049e795     PUSH       0x28
//         0049e797     PUSH       0x12c
//         0049e79c     PUSH       ESI
//         0049e79d     PUSH       0xaa
//         0049e7a2     PUSH       0x0
//         0049e7a4     PUSH       s_                                               = ""
//         0049e7a9     PUSH       EDI
//         0049e7aa     PUSH       EBP
//         0049e7ab     MOV        this,EBP
//         0049e7ad     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0049e7b2     TEST       EAX,EAX
//         0049e7b4     JZ         LAB_0049ebb6
//         0049e7ba     ADD        ESI,0x32
//         0049e7bd     ADD        EDI,0x4
//         0049e7c0     CMP        ESI,0x1ac
//         0049e7c6     JL         LAB_0049e78f
//                              Scr_main.cpp:118 (18)
//         0049e7c8     MOV        this,dword ptr [EBP + 0x480]
//                              language.dll match for 0x23f2: "Single Player"
//         0049e7ce     PUSH       0x23f2
//         0049e7d3     PUSH       0x0
//         0049e7d5     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              Scr_main.cpp:119 (18)
//         0049e7da     MOV        this,dword ptr [EBP + 0x484]
//                              language.dll match for 0x23f3: "Multiplayer"
//         0049e7e0     PUSH       0x23f3
//         0049e7e5     PUSH       0x0
//         0049e7e7     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              Scr_main.cpp:120 (18)
//         0049e7ec     MOV        this,dword ptr [EBP + 0x488]
//                              language.dll match for 0x23f5: "Help"
//         0049e7f2     PUSH       0x23f5
//         0049e7f7     PUSH       0x0
//         0049e7f9     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              Scr_main.cpp:121 (18)
//         0049e7fe     MOV        this,dword ptr [EBP + 0x48c]
//                              language.dll match for 0x23f6: "Scenario Builder"
//         0049e804     PUSH       0x23f6
//         0049e809     PUSH       0x0
//         0049e80b     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              Scr_main.cpp:123 (18)
//         0049e810     MOV        this,dword ptr [EBP + 0x490]
//                              language.dll match for 0x23f7: "Exit"
//         0049e816     PUSH       0x23f7
//         0049e81b     PUSH       0x0
//         0049e81d     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              Scr_main.cpp:130 (15)
//         0049e822     MOV        EDX,dword ptr [EBP + 0x18]
//         0049e825     MOV        EAX,dword ptr [EBP + 0x14]
//         0049e828     PUSH       EDX
//         0049e829     PUSH       EAX
//         0049e82a     MOV        this,EBP
//         0049e82c     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              Scr_main.cpp:135 (46)
//         0049e831     MOV        this,dword ptr [EBP + 0x14]
//         0049e834     MOV        EBX,dword ptr [EBP + 0x18]
//         0049e837     PUSH       0x0
//         0049e839     PUSH       0x0
//         0049e83b     PUSH       0x1
//         0049e83d     PUSH       0xa
//         0049e83f     SUB        this,0xa
//         0049e842     SUB        EBX,0x3c
//         0049e845     PUSH       0x12
//         0049e847     PUSH       this
//         0049e848     PUSH       EBX
//         0049e849     PUSH       0x5
//         0049e84b     LEA        EAX,[EBP + 0x49c]
//                              language.dll match for 0x2419: "Microsoft\\xAE Age of Empires
//                              language.dll match for 0x2419: "Microsoft\\xA9 Age of Empires
//         0049e851     PUSH       0x2419
//         0049e856     PUSH       EAX
//         0049e857     PUSH       EBP
//         0049e858     MOV        this,EBP
//         0049e85a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              Scr_main.cpp:139 (22)
//         0049e85f     LEA        EDX=>temp_str[4],[ESP + 0x40]
//         0049e863     PUSH       0x200
//         0049e868     PUSH       EDX
//         0049e869     PUSH       0x2424
//         0049e86e     MOV        this,EBP
//         0049e870     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              Scr_main.cpp:140 (12)
//         0049e875     MOV        AL,byte ptr [ESP + temp_str[4]]
//         0049e879     TEST       AL,AL
//         0049e87b     JNZ        LAB_0049ea5d
//                              Scr_main.cpp:144 (38)
//         0049e881     PUSH       0x0
//         0049e883     PUSH       0x0
//         0049e885     PUSH       0x0
//         0049e887     PUSH       0xa
//         0049e889     PUSH       0x12
//         0049e88b     LEA        EAX,[EBX + 0x12]
//         0049e88e     PUSH       0x32
//         0049e890     PUSH       EAX
//         0049e891     PUSH       0x5
//         0049e893     LEA        EDI,[EBP + 0x4a0]
//                              language.dll match for 0x241b: "\\xA9 & "
//         0049e899     PUSH       0x241b
//         0049e89e     PUSH       EDI
//         0049e89f     PUSH       EBP
//         0049e8a0     MOV        this,EBP
//         0049e8a2     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              Scr_main.cpp:147 (20)
//         0049e8a7     LEA        this=>rect.top,[ESP + 0x18]
//         0049e8ab     PUSH       this
//         0049e8ac     MOV        this,dword ptr [EDI]
//         0049e8ae     CALL       TTextPanel::get_text_rect                        int get_text_rect(TTextPanel * this, tagRECT
//         0049e8b3     TEST       EAX,EAX
//         0049e8b5     JZ         LAB_0049eb4f
//                              Scr_main.cpp:149 (40)
//         0049e8bb     PUSH       0x11c
//         0049e8c0     CALL       operator_new                                     void * operator_new(uint param_1)
//         0049e8c5     ADD        ESP,0x4
//         0049e8c8     MOV        dword ptr [ESP + rect.left],EAX
//         0049e8cc     TEST       EAX,EAX
//         0049e8ce     MOV        byte ptr [ESP + local_4],0x1
//         0049e8d6     JZ         LAB_0049e8e1
//         0049e8d8     MOV        this,EAX
//         0049e8da     CALL       TPicturePanel::TPicturePanel                     undefined TPicturePanel(TPicturePanel * this)
//         0049e8df     JMP        LAB_0049e8e3
//                               LAB_0049e8e1                                                 XREF[1]:     0049e8d6(j)
//         0049e8e1     XOR        EAX,EAX
//                               LAB_0049e8e3                                                 XREF[1]:     0049e8df(j)
//                              Scr_main.cpp:150 (22)
//         0049e8e3     TEST       EAX,EAX
//         0049e8e5     MOV        byte ptr [ESP + local_4],0x0
//         0049e8ed     MOV        dword ptr [EBP + 0x4ac],EAX
//         0049e8f3     JZ         LAB_0049eb4f
//                              Scr_main.cpp:152 (49)
//         0049e8f9     MOV        EDX,dword ptr [ESP + rect.right]
//         0049e8fd     MOV        this,dword ptr [ESP + rect.bottom]
//         0049e901     PUSH       0x1
//         0049e903     PUSH       0x0
//         0049e905     PUSH       0xc4e6
//         0049e90a     PUSH       s_circlep2                                       = "circlep2"
//         0049e90f     PUSH       0xe
//         0049e911     INC        EDX
//         0049e912     PUSH       0xf
//         0049e914     PUSH       EDX
//         0049e915     MOV        EDX,dword ptr [EBP + 0xc]
//         0049e918     SUB        this,EDX
//         0049e91a     MOV        EDX,dword ptr [EBP + 0x20]
//         0049e91d     ADD        this,0x3
//         0049e920     PUSH       this
//         0049e921     PUSH       EBP
//         0049e922     PUSH       EDX
//         0049e923     MOV        this,EAX
//         0049e925     CALL       TPicturePanel::setup                             long setup(TPicturePanel * this, TDrawArea *
//                              Scr_main.cpp:153 (72)
//         0049e92a     MOV        EAX,dword ptr [ESP + rect.right]
//         0049e92e     MOV        this,dword ptr [EBP + 0x4ac]
//         0049e934     PUSH       0x0
//         0049e936     PUSH       0x0
//         0049e938     PUSH       0x0
//         0049e93a     PUSH       0xa
//         0049e93c     PUSH       0x12
//         0049e93e     PUSH       0x1f4
//         0049e943     PUSH       EAX
//         0049e944     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0049e949     MOV        EDX,dword ptr [EBP + 0xc]
//         0049e94c     MOV        this,dword ptr [EBP + 0x4ac]
//         0049e952     MOV        ESI,EAX
//         0049e954     SUB        ESI,EDX
//         0049e956     CALL       TPanel::width                                    long width(TPanel * this)
//         0049e95b     ADD        ESI,EAX
//         0049e95d     MOV        this,EBP
//         0049e95f     PUSH       ESI
//         0049e960     LEA        ESI,[EBP + 0x4a4]
//                              language.dll match for 0x241c: "1997-1998 Microsoft Corporati
//                              language.dll match for 0x241c: "1997 Microsoft Corporation. A
//         0049e966     PUSH       0x241c
//         0049e96b     PUSH       ESI
//         0049e96c     PUSH       EBP
//         0049e96d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              Scr_main.cpp:157 (20)
//         0049e972     LEA        this=>rect.top,[ESP + 0x18]
//         0049e976     PUSH       this
//         0049e977     MOV        this,dword ptr [ESI]
//         0049e979     CALL       TTextPanel::get_text_rect                        int get_text_rect(TTextPanel * this, tagRECT
//         0049e97e     TEST       EAX,EAX
//         0049e980     JZ         LAB_0049eb4f
//                              Scr_main.cpp:159 (17)
//         0049e986     MOV        EAX,dword ptr [EBP + 0x14]
//         0049e989     MOV        this,dword ptr [ESP + rect.bottom]
//         0049e98d     SUB        EAX,this
//         0049e98f     SUB        EAX,0x5
//         0049e992     CDQ
//         0049e993     SUB        EAX,EDX
//         0049e995     SAR        EAX,0x1
//                              Scr_main.cpp:160 (12)
//         0049e997     TEST       EAX,EAX
//         0049e999     MOV        dword ptr [ESP + local_23c],EAX
//         0049e99d     JLE        LAB_0049eb4f
//                              Scr_main.cpp:162 (71)
//         0049e9a3     MOV        EDI,dword ptr [EDI]
//         0049e9a5     MOV        this,EDI
//         0049e9a7     MOV        EDX,dword ptr [EDI]
//         0049e9a9     MOV        dword ptr [ESP + rect.left],EDX
//         0049e9ad     CALL       TPanel::height                                   long height(TPanel * this)
//         0049e9b2     MOV        this,dword ptr [EBP + 0x4a0]
//         0049e9b8     PUSH       EAX
//         0049e9b9     CALL       TPanel::width                                    long width(TPanel * this)
//         0049e9be     MOV        this,dword ptr [EBP + 0x4a0]
//         0049e9c4     PUSH       EAX
//         0049e9c5     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0049e9ca     MOV        this,dword ptr [EBP + 0x4a0]
//         0049e9d0     PUSH       EAX
//         0049e9d1     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0049e9d6     MOV        this,dword ptr [ESP + local_23c]
//         0049e9da     MOV        EDX,dword ptr [ESP + rect.left]
//         0049e9de     ADD        EAX,this
//         0049e9e0     MOV        this,dword ptr [EBP + 0x4a0]
//         0049e9e6     PUSH       EAX
//         0049e9e7     CALL       dword ptr [EDX + 0x1c]
//                              Scr_main.cpp:163 (65)
//         0049e9ea     MOV        this,dword ptr [EBP + 0x4ac]
//         0049e9f0     MOV        EDI,dword ptr [this->_padding_]
//         0049e9f2     CALL       TPanel::height                                   long height(TPanel * this)
//         0049e9f7     MOV        this,dword ptr [EBP + 0x4ac]
//         0049e9fd     PUSH       EAX
//         0049e9fe     CALL       TPanel::width                                    long width(TPanel * this)
//         0049ea03     MOV        this,dword ptr [EBP + 0x4ac]
//         0049ea09     PUSH       EAX=>DAT_fffffff8
//         0049ea0a     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0049ea0f     MOV        this,dword ptr [EBP + 0x4ac]
//         0049ea15     PUSH       EAX=>DAT_fffffff4
//         0049ea16     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0049ea1b     MOV        this,dword ptr [ESP + 0x1c]
//         0049ea1f     ADD        EAX,this
//         0049ea21     MOV        this,dword ptr [EBP + 0x4ac]
//         0049ea27     PUSH       EAX=>DAT_fffffff0
//         0049ea28     CALL       dword ptr [EDI + 0x1c]
//                              Scr_main.cpp:164 (45)
//         0049ea2b     MOV        this,dword ptr [ESI]
//         0049ea2d     MOV        EDI,dword ptr [this->_padding_]
//         0049ea2f     CALL       TPanel::height                                   long height(TPanel * this)
//         0049ea34     MOV        this,dword ptr [ESI]
//         0049ea36     PUSH       EAX
//         0049ea37     CALL       TPanel::width                                    long width(TPanel * this)
//         0049ea3c     MOV        this,dword ptr [ESI]
//         0049ea3e     PUSH       EAX=>DAT_fffffff8
//         0049ea3f     CALL       TPanel::yPosition                                long yPosition(TPanel * this)
//         0049ea44     MOV        this,dword ptr [ESI]
//         0049ea46     PUSH       EAX=>DAT_fffffff4
//         0049ea47     CALL       TPanel::xPosition                                long xPosition(TPanel * this)
//         0049ea4c     MOV        EDX,dword ptr [ESP + 0x1c]
//         0049ea50     MOV        this,dword ptr [ESI]
//         0049ea52     ADD        EAX,EDX
//         0049ea54     PUSH       EAX=>DAT_fffffff0
//         0049ea55     CALL       dword ptr [EDI + 0x1c]
//                              Scr_main.cpp:170 (5)
//         0049ea58     JMP        LAB_0049eb4f
//                              language.dll match for 0x241b: "\\xA9 & "
//                               LAB_0049ea5d                                                 XREF[1]:     0049e87b(j)
//                              Scr_main.cpp:172 (29)
//         0049ea5d     PUSH       0x241b
//         0049ea62     MOV        this,EBP
//         0049ea64     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0049ea69     MOV        EDI,EAX
//         0049ea6b     OR         this,0xffffffff
//         0049ea6e     XOR        EAX,EAX
//         0049ea70     LEA        EDX=>temp_str[4],[ESP + 0x40]
//         0049ea74     SCASB.RE   ES:EDI
//         0049ea76     NOT        this
//         0049ea78     SUB        EDI,this
//                              Scr_main.cpp:173 (47)
//         0049ea7a     PUSH       0x2424
//         0049ea7f     MOV        EAX,this
//         0049ea81     MOV        ESI,EDI
//         0049ea83     MOV        EDI,EDX
//         0049ea85     SHR        this,0x2
//         0049ea88     MOVSD.REP  ES:EDI,ESI
//         0049ea8a     MOV        this,EAX
//         0049ea8c     AND        this,0x3
//         0049ea8f     MOVSB.REP  ES:EDI,ESI
//         0049ea91     MOV        this,EBP
//         0049ea93     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0049ea98     MOV        EDI,EAX
//         0049ea9a     OR         this,0xffffffff
//         0049ea9d     XOR        EAX,EAX
//         0049ea9f     LEA        EDX=>temp_str[4],[ESP + 0x40]
//         0049eaa3     SCASB.RE   ES:EDI
//         0049eaa5     NOT        this
//         0049eaa7     SUB        EDI,this
//                              Scr_main.cpp:175 (99)
//         0049eaa9     PUSH       0x241c
//         0049eaae     MOV        ESI,EDI
//         0049eab0     MOV        EDI,EDX
//         0049eab2     MOV        EDX,this
//         0049eab4     OR         this,0xffffffff
//         0049eab7     SCASB.RE   ES:EDI
//         0049eab9     MOV        this,EDX
//         0049eabb     DEC        EDI
//         0049eabc     SHR        this,0x2
//         0049eabf     MOVSD.REP  ES:EDI,ESI
//         0049eac1     MOV        this,EDX
//         0049eac3     LEA        EDX=>temp_str[4],[ESP + 0x44]
//         0049eac7     AND        this,0x3
//         0049eaca     MOVSB.REP  ES:EDI,ESI
//         0049eacc     MOV        EDI,s__                                          = 20h
//         0049ead1     OR         this,0xffffffff
//         0049ead4     SCASB.RE   ES:EDI=>s__                                      = 20h
//         0049ead6     NOT        this
//         0049ead8     SUB        EDI,this
//         0049eada     MOV        ESI,EDI
//         0049eadc     MOV        EDI,EDX
//         0049eade     MOV        EDX,this
//         0049eae0     OR         this,0xffffffff
//         0049eae3     SCASB.RE   ES:EDI
//         0049eae5     MOV        this,EDX
//         0049eae7     DEC        EDI
//         0049eae8     SHR        this,0x2
//         0049eaeb     MOVSD.REP  ES:EDI,ESI
//         0049eaed     MOV        this,EDX
//         0049eaef     AND        this,0x3
//         0049eaf2     MOVSB.REP  ES:EDI,ESI
//         0049eaf4     MOV        this,EBP
//         0049eaf6     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         0049eafb     MOV        EDI,EAX
//         0049eafd     OR         this,0xffffffff
//         0049eb00     XOR        EAX,EAX
//         0049eb02     LEA        EDX=>temp_str[4],[ESP + 0x40]
//         0049eb06     SCASB.RE   ES:EDI
//         0049eb08     NOT        this
//         0049eb0a     SUB        EDI,this
//                              Scr_main.cpp:176 (67)
//         0049eb0c     PUSH       EAX
//         0049eb0d     MOV        ESI,EDI
//         0049eb0f     MOV        EDI,EDX
//         0049eb11     MOV        EDX,this
//         0049eb13     OR         this,0xffffffff
//         0049eb16     SCASB.RE   ES:EDI
//         0049eb18     MOV        this,EDX
//         0049eb1a     DEC        EDI
//         0049eb1b     SHR        this,0x2
//         0049eb1e     MOVSD.REP  ES:EDI,ESI
//         0049eb20     MOV        this,EDX
//         0049eb22     AND        this,0x3
//         0049eb25     MOVSB.REP  ES:EDI,ESI
//         0049eb27     PUSH       EAX
//         0049eb28     MOV        EAX,dword ptr [EBP + 0x14]
//         0049eb2b     PUSH       0x1
//         0049eb2d     PUSH       0xa
//         0049eb2f     SUB        EAX,0xa
//         0049eb32     PUSH       0x12
//         0049eb34     LEA        this,[EBX + 0x12]
//         0049eb37     PUSH       EAX
//         0049eb38     PUSH       this
//         0049eb39     LEA        EDX=>temp_str[4],[ESP + 0x5c]
//         0049eb3d     PUSH       0x5
//         0049eb3f     LEA        EAX,[EBP + 0x4a0]
//         0049eb45     PUSH       EDX
//         0049eb46     PUSH       EAX
//         0049eb47     PUSH       EBP
//         0049eb48     MOV        this,EBP
//         0049eb4a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                               LAB_0049eb4f                                                 XREF[5]:     0049e8b5(j), 0049e8f3(j),
//                                                                                                         0049e980(j), 0049e99d(j),
//                                                                                                         0049ea58(j)
//                              Scr_main.cpp:179 (43)
//         0049eb4f     MOV        EAX,dword ptr [EBP + 0x14]
//         0049eb52     PUSH       0x0
//         0049eb54     PUSH       0x0=>DAT_fffffff8
//         0049eb56     PUSH       offset DAT_fffffff4
//         0049eb58     PUSH       offset DAT_fffffff0
//         0049eb5a     SUB        EAX,0xa
//         0049eb5d     PUSH       0x12
//         0049eb5f     ADD        EBX,0x24
//         0049eb62     PUSH       EAX
//         0049eb63     PUSH       EBX
//         0049eb64     PUSH       0x5
//         0049eb66     LEA        EAX,[EBP + 0x4a8]
//                              language.dll match for 0x2425: "This program is protected by
//         0049eb6c     PUSH       0x2425
//         0049eb71     PUSH       EAX
//         0049eb72     PUSH       EBP
//         0049eb73     MOV        this,EBP
//         0049eb75     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              Scr_main.cpp:182 (17)
//         0049eb7a     PUSH       0x1e0
//         0049eb7f     PUSH       offset DAT_fffffff8
//         0049eb84     MOV        this,EBP
//         0049eb86     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              Scr_main.cpp:188 (19)
//         0049eb8b     LEA        EBX,[EBP + 0x480]
//         0049eb91     MOV        this,0x5
//         0049eb96     MOV        ESI,EBX
//         0049eb98     LEA        EDI,[ESP + 0x2c]
//         0049eb9c     MOVSD.REP  ES:EDI,ESI
//                              Scr_main.cpp:189 (14)
//         0049eb9e     LEA        this,[ESP + 0x2c]
//         0049eba2     PUSH       0x5
//         0049eba4     PUSH       this=>DAT_fffffff8
//         0049eba5     MOV        this,EBP
//         0049eba7     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * *
//                              Scr_main.cpp:192 (10)
//         0049ebac     MOV        EDX,dword ptr [EBX]
//         0049ebae     MOV        this,EBP
//         0049ebb0     PUSH       EDX
//         0049ebb1     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_0049ebb6                                                 XREF[2]:     0049e772(j), 0049e7b4(j)
//                              Scr_main.cpp:193 (27)
//         0049ebb6     MOV        this,dword ptr [ESP + local_c]
//         0049ebbd     POP        EDI
//         0049ebbe     MOV        EAX,EBP
//         0049ebc0     POP        ESI
//         0049ebc1     POP        EBP
//         0049ebc2     MOV        dword ptr FS:[0x0],this
//         0049ebc9     POP        EBX
//         0049ebca     ADD        ESP,0x23c
//         0049ebd0     RET
//         0049ebd1     ??         90h
//         0049ebd2     NOP
//         0049ebd3     NOP
//         0049ebd4     NOP
//         0049ebd5     NOP
//         0049ebd6     NOP
//         0049ebd7     NOP
//         0049ebd8     NOP
//         0049ebd9     NOP
//         0049ebda     NOP
//         0049ebdb     NOP
//         0049ebdc     NOP
//         0049ebdd     NOP
//         0049ebde     NOP
//         0049ebdf     NOP
}

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Screen_Main_Menu(TRIBE_Screen_Main_Menu * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0049ec2b(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049ec1b(W)
//                               ??1TRIBE_Screen_Main_Menu@@UAE@XZ                            XREF[1]:     `scalar_deleting_destructor':0049e
//                               TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu
//                              Scr_main.cpp:199 (37)
//         0049ec00     PUSH       -0x1
//         0049ec02     PUSH       FUN_0055f048
//         0049ec07     MOV        EAX,FS:[0x0]
//         0049ec0d     PUSH       EAX
//         0049ec0e     MOV        dword ptr FS:[0x0],ESP
//         0049ec15     PUSH       this
//         0049ec16     PUSH       EBX
//         0049ec17     PUSH       ESI
//         0049ec18     MOV        ESI,this
//         0049ec1a     PUSH       EDI
//         0049ec1b     MOV        dword ptr [ESP + local_10],ESI
//         0049ec1f     MOV        dword ptr [ESI],TRIBE_Screen_Main_Menu::`vftab   = 0049ebe0
//                              Scr_main.cpp:200 (20)
//         0049ec25     LEA        EAX,[ESI + 0x478]
//         0049ec2b     MOV        dword ptr [ESP + local_4],0x0
//         0049ec33     PUSH       EAX
//         0049ec34     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Scr_main.cpp:201 (14)
//         0049ec39     LEA        this,[ESI + 0x47c]
//         0049ec3f     PUSH       this
//         0049ec40     MOV        this,ESI
//         0049ec42     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Scr_main.cpp:202 (14)
//         0049ec47     LEA        EDX,[ESI + 0x4a0]
//         0049ec4d     MOV        this,ESI
//         0049ec4f     PUSH       EDX
//         0049ec50     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Scr_main.cpp:203 (14)
//         0049ec55     LEA        EAX,[ESI + 0x4a4]
//         0049ec5b     MOV        this,ESI
//         0049ec5d     PUSH       EAX
//         0049ec5e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Scr_main.cpp:204 (25)
//         0049ec63     LEA        this,[ESI + 0x4a8]
//         0049ec69     PUSH       this
//         0049ec6a     MOV        this,ESI
//         0049ec6c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         0049ec71     LEA        EDI,[ESI + 0x480]
//         0049ec77     MOV        EBX,0x7
//                               LAB_0049ec7c                                                 XREF[1]:     0049ec88(j)
//                              Scr_main.cpp:207 (14)
//         0049ec7c     PUSH       EDI
//         0049ec7d     MOV        this,ESI
//         0049ec7f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         0049ec84     ADD        EDI,0x4
//         0049ec87     DEC        EBX
//         0049ec88     JNZ        LAB_0049ec7c
//                              Scr_main.cpp:209 (10)
//         0049ec8a     MOV        this,dword ptr [ESI + 0x4ac]
//         0049ec90     TEST       this,this
//         0049ec92     JZ         LAB_0049ec9a
//                              Scr_main.cpp:210 (6)
//         0049ec94     MOV        EDX,dword ptr [this->_padding_]
//         0049ec96     PUSH       0x1
//         0049ec98     CALL       dword ptr [EDX]
//                               LAB_0049ec9a                                                 XREF[1]:     0049ec92(j)
//                              Scr_main.cpp:212 (10)
//         0049ec9a     MOV        this,dword ptr [ESI + 0x49c]
//         0049eca0     TEST       this,this
//         0049eca2     JZ         LAB_0049ecaa
//                              Scr_main.cpp:213 (8)
//         0049eca4     MOV        EAX,dword ptr [this->_padding_]
//         0049eca6     PUSH       0x1
//         0049eca8     CALL       dword ptr [EAX]
//                               LAB_0049ecaa                                                 XREF[1]:     0049eca2(j)
//         0049ecaa     MOV        this,ESI
//                              Scr_main.cpp:214 (31)
//         0049ecac     MOV        dword ptr [ESP + 0x18],0xffffffff
//         0049ecb4     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         0049ecb9     MOV        this,dword ptr [ESP + 0x10]
//         0049ecbd     POP        EDI
//         0049ecbe     POP        ESI
//         0049ecbf     MOV        dword ptr FS:[0x0],this
//         0049ecc6     POP        EBX
//         0049ecc7     ADD        ESP,0x10
//         0049ecca     RET
//         0049eccb     ??         90h
//         0049eccc     NOP
//         0049eccd     NOP
//         0049ecce     NOP
//         0049eccf     NOP
}

long TRIBE_Screen_Main_Menu::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TRIBE_Screen_Main_Menu * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//                               ?handle_idle@TRIBE_Screen_Main_Menu@@UAEJXZ                  XREF[1]:     00572f9c(*)
//                               TRIBE_Screen_Main_Menu::handle_idle
//                              Scr_main.cpp:220 (3)
//         0049ecd0     PUSH       ESI
//         0049ecd1     MOV        ESI,this
//                              Scr_main.cpp:221 (16)
//         0049ecd3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049ecd9     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0049ecdf     TEST       EAX,EAX
//         0049ece1     JNZ        LAB_0049ece8
//                              Scr_main.cpp:222 (5)
//         0049ece3     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
//                               LAB_0049ece8                                                 XREF[1]:     0049ece1(j)
//                              Scr_main.cpp:224 (7)
//         0049ece8     MOV        this,ESI
//         0049ecea     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              Scr_main.cpp:225 (2)
//         0049ecef     POP        ESI
//         0049ecf0     RET
//         0049ecf1     ??         90h
//         0049ecf2     NOP
//         0049ecf3     NOP
//         0049ecf4     NOP
//         0049ecf5     NOP
//         0049ecf6     NOP
//         0049ecf7     NOP
//         0049ecf8     NOP
//         0049ecf9     NOP
//         0049ecfa     NOP
//         0049ecfb     NOP
//         0049ecfc     NOP
//         0049ecfd     NOP
//         0049ecfe     NOP
//         0049ecff     NOP
    return 0;
}

long TRIBE_Screen_Main_Menu::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TRIBE_Screen_Main_Menu * this, long
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0049ed24(R)
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4                   XREF[2]:     0049ed0e(R), 0049ed90(W)
//              int               Stack[0x14]:4  param_5
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049ed96(W), 0049edb3(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[3]:     0049ed71(R), 0049edd4(R), 0049ede6(R)
//                               ?key_down_action@TRIBE_Screen_Main_Menu@@UAEJJFHHH@Z         XREF[1]:     00572ffc(*)
//                               TRIBE_Screen_Main_Menu::key_down_action
//                              Scr_main.cpp:231 (14)
//         0049ed00     MOV        EAX,FS:[0x0]
//         0049ed06     PUSH       -0x1
//         0049ed08     PUSH       FUN_0055f06b
//         0049ed0d     PUSH       EAX
//                              Scr_main.cpp:233 (22)
//         0049ed0e     MOV        EAX,dword ptr [ESP + param_4]
//         0049ed12     MOV        dword ptr FS:[0x0],ESP
//         0049ed19     PUSH       ESI
//         0049ed1a     MOV        ESI,this
//         0049ed1c     TEST       EAX,EAX
//         0049ed1e     JZ         LAB_0049ede6
//                              Scr_main.cpp:235 (18)
//         0049ed24     MOV        EAX,dword ptr [ESP + param_1]
//         0049ed28     CMP        EAX,0x43
//         0049ed2b     JZ         LAB_0049ed83
//         0049ed2d     CMP        EAX,0x4c
//         0049ed30     JNZ        LAB_0049ede6
//                              Scr_main.cpp:238 (19)
//         0049ed36     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049ed3c     CALL       RGE_Base_Game::gameDeveloperMode                 int gameDeveloperMode(RGE_Base_Game * this)
//         0049ed41     TEST       EAX,EAX
//         0049ed43     JZ         LAB_0049edcf
//                              Scr_main.cpp:240 (15)
//         0049ed49     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049ed4f     CALL       TRIBE_Game::load_db_files                        int load_db_files(TRIBE_Game * this)
//         0049ed54     TEST       EAX,EAX
//         0049ed56     JNZ        LAB_0049edcf
//                              Scr_main.cpp:241 (20)
//         0049ed58     PUSH       0x64
//         0049ed5a     PUSH       0x1c2
//         0049ed5f     PUSH       EAX
//                              language.dll match for 0x7d7: "Could not load game data."
//         0049ed60     PUSH       0x7d7
//         0049ed65     MOV        this,ESI
//         0049ed67     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              Scr_main.cpp:243 (5)
//         0049ed6c     MOV        EAX,0x1
//                              Scr_main.cpp:258 (18)
//         0049ed71     MOV        this,dword ptr [ESP + local_c]
//         0049ed75     MOV        dword ptr FS:[0x0],this
//         0049ed7c     POP        ESI
//         0049ed7d     ADD        ESP,0xc
//         0049ed80     RET        0x14
//                               LAB_0049ed83                                                 XREF[1]:     0049ed2b(j)
//                              Scr_main.cpp:249 (36)
//         0049ed83     PUSH       0x8b8
//         0049ed88     CALL       operator_new                                     void * operator_new(uint param_1)
//         0049ed8d     ADD        ESP,0x4
//         0049ed90     MOV        dword ptr [ESP + param_4],EAX
//         0049ed94     TEST       EAX,EAX
//         0049ed96     MOV        dword ptr [ESP + local_4],0x0
//         0049ed9e     JZ         LAB_0049eda7
//         0049eda0     MOV        this,EAX
//         0049eda2     CALL       TRIBE_Credits_Screen::TRIBE_Credits_Screen       undefined TRIBE_Credits_Screen(TRIBE_Credits_
//                               LAB_0049eda7                                                 XREF[1]:     0049ed9e(j)
//                              Scr_main.cpp:250 (25)
//         0049eda7     PUSH       0x0
//         0049eda9     PUSH       s_Credits_Screen                                 = "Credits Screen"
//         0049edae     MOV        this,panel_system
//         0049edb3     MOV        dword ptr [ESP + local_4],0xffffffff
//         0049edbb     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              Scr_main.cpp:251 (15)
//         0049edc0     PUSH       s_Main_Menu                                      = "Main Menu"
//         0049edc5     MOV        this,panel_system
//         0049edca     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                               LAB_0049edcf                                                 XREF[2]:     0049ed43(j), 0049ed56(j)
//                              Scr_main.cpp:252 (5)
//         0049edcf     MOV        EAX,0x1
//                              Scr_main.cpp:258 (38)
//         0049edd4     MOV        this,dword ptr [ESP + local_c]
//         0049edd8     MOV        dword ptr FS:[0x0],this
//         0049eddf     POP        ESI
//         0049ede0     ADD        ESP,0xc
//         0049ede3     RET        0x14
//                               LAB_0049ede6                                                 XREF[2]:     0049ed1e(j), 0049ed30(j)
//         0049ede6     MOV        this,dword ptr [ESP + local_c]
//         0049edea     XOR        EAX,EAX
//         0049edec     MOV        dword ptr FS:[0x0],this
//         0049edf3     POP        ESI
//         0049edf4     ADD        ESP,0xc
//         0049edf7     RET        0x14
//         0049edfa     ??         90h
//         0049edfb     NOP
//         0049edfc     NOP
//         0049edfd     NOP
//         0049edfe     NOP
//         0049edff     NOP
    return 0;
}

long TRIBE_Screen_Main_Menu::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TRIBE_Screen_Main_Menu * this, TPanel * param
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[4]:     0049ee1d(R), 0049ef15(W), 0049ef7b(W), 0049f049(W)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0049ee16(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0049f0a7(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049f0a3(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[6]:     0049ef1b(W), 0049ef38(W), 0049ef81(W), 0049ef9a(W),
//                                                                                     0049f04f(W), 0049f06c(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049f0b6(R)
//                               ?action@TRIBE_Screen_Main_Menu@@UAEJPAVTPanel@@JKK@Z         XREF[1]:     00573004(*)
//                               TRIBE_Screen_Main_Menu::action
//                              Scr_main.cpp:264 (22)
//         0049ee00     MOV        EAX,FS:[0x0]
//         0049ee06     PUSH       -0x1
//         0049ee08     PUSH       FUN_0055f0a1
//         0049ee0d     PUSH       EAX
//         0049ee0e     MOV        dword ptr FS:[0x0],ESP
//         0049ee15     PUSH       EBX
//                              Scr_main.cpp:265 (21)
//         0049ee16     MOV        EBX,dword ptr [ESP + param_2]
//         0049ee1a     PUSH       EBP
//         0049ee1b     PUSH       ESI
//         0049ee1c     PUSH       EDI
//         0049ee1d     MOV        EDI,dword ptr [ESP + param_1]
//         0049ee21     MOV        EBP,this
//         0049ee23     TEST       EDI,EDI
//         0049ee25     JZ         LAB_0049f0a3
//                              Scr_main.cpp:268 (72)
//         0049ee2b     MOV        this,EDI
//         0049ee2d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         0049ee32     TEST       EAX,EAX
//         0049ee34     JZ         LAB_0049eea3
//         0049ee36     MOV        this,EDI
//         0049ee38     MOV        ESI,s_Confirm_Dialog                             = 43h
//         0049ee3d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_0049ee42                                                 XREF[1]:     0049ee60(j)
//         0049ee42     MOV        DL,byte ptr [EAX]
//         0049ee44     MOV        this,DL
//         0049ee46     CMP        DL,byte ptr [ESI]=>s_Confirm_Dialog              = 43h
//                                                                                  = 6Eh
//         0049ee48     JNZ        LAB_0049ee66
//         0049ee4a     TEST       this,this
//         0049ee4c     JZ         LAB_0049ee62
//         0049ee4e     MOV        DL,byte ptr [EAX + 0x1]
//         0049ee51     MOV        this,DL
//         0049ee53     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005866a5            = 6Fh
//                                                                                  = "firm Dialog"
//         0049ee56     JNZ        LAB_0049ee66
//         0049ee58     ADD        EAX,0x2
//         0049ee5b     ADD        ESI,0x2
//         0049ee5e     TEST       this,this
//         0049ee60     JNZ        LAB_0049ee42
//                               LAB_0049ee62                                                 XREF[1]:     0049ee4c(j)
//         0049ee62     XOR        EAX,EAX
//         0049ee64     JMP        LAB_0049ee6b
//                               LAB_0049ee66                                                 XREF[2]:     0049ee48(j), 0049ee56(j)
//         0049ee66     SBB        EAX,EAX
//         0049ee68     SBB        EAX,-0x1
//                               LAB_0049ee6b                                                 XREF[1]:     0049ee64(j)
//         0049ee6b     TEST       EAX,EAX
//         0049ee6d     JNZ        LAB_0049eea3
//         0049ee6f     TEST       EBX,EBX
//         0049ee71     JNZ        LAB_0049eea3
//                              Scr_main.cpp:270 (15)
//         0049ee73     PUSH       s_Confirm_Dialog                                 = 43h
//         0049ee78     MOV        this,panel_system
//         0049ee7d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              Scr_main.cpp:271 (23)
//         0049ee82     MOV        EAX,[rge_base_game]                              = 00000000
//         0049ee87     PUSH       EBX
//         0049ee88     PUSH       0x3
//         0049ee8a     PUSH       s_empires.hlp                                    = "empires.hlp"
//         0049ee8f     MOV        this,dword ptr [EAX + 0x10]
//         0049ee92     PUSH       this
//         0049ee93     CALL       dword ptr [->USER32.DLL::WinHelpA]               = 0048aff6
//                              Scr_main.cpp:272 (10)
//         0049ee99     MOV        EAX,0x1
//         0049ee9e     JMP        LAB_0049f0b6
//                               LAB_0049eea3                                                 XREF[3]:     0049ee34(j), 0049ee6d(j),
//                                                                                                         0049ee71(j)
//                              Scr_main.cpp:275 (13)
//         0049eea3     MOV        ESI,0x1
//         0049eea8     CMP        EBX,ESI
//         0049eeaa     JNZ        LAB_0049f0a3
//                              Scr_main.cpp:277 (12)
//         0049eeb0     CMP        EDI,dword ptr [EBP + 0x480]
//         0049eeb6     JNZ        LAB_0049ef5b
//                              Scr_main.cpp:279 (16)
//         0049eebc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049eec2     MOV        EAX,dword ptr [this->_padding_ + 0x9ac]
//         0049eec8     TEST       EAX,EAX
//         0049eeca     JNZ        LAB_0049ef03
//                              Scr_main.cpp:280 (11)
//         0049eecc     PUSH       0x0
//         0049eece     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         0049eed3     TEST       EAX,EAX
//         0049eed5     JNZ        LAB_0049eef2
//                              Scr_main.cpp:281 (20)
//         0049eed7     PUSH       0x64
//         0049eed9     PUSH       0x1c2
//         0049eede     PUSH       EAX
//                              language.dll match for 0x7d8: "You must insert a game CD to p
//         0049eedf     PUSH       0x7d8
//         0049eee4     MOV        this,EBP
//         0049eee6     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              Scr_main.cpp:282 (7)
//         0049eeeb     MOV        EAX,ESI
//         0049eeed     JMP        LAB_0049f0b6
//                               LAB_0049eef2                                                 XREF[1]:     0049eed5(j)
//                              Scr_main.cpp:285 (17)
//         0049eef2     MOV        EAX,[rge_base_game]                              = 00000000
//         0049eef7     MOV        dword ptr [EAX + 0x9ac],ESI
//         0049eefd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                               LAB_0049ef03                                                 XREF[1]:     0049eeca(j)
//                              Scr_main.cpp:287 (5)
//         0049ef03     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
//                              Scr_main.cpp:288 (36)
//         0049ef08     PUSH       0x49c
//         0049ef0d     CALL       operator_new                                     void * operator_new(uint param_1)
//         0049ef12     ADD        ESP,0x4
//         0049ef15     MOV        dword ptr [ESP + param_1],EAX
//         0049ef19     TEST       EAX,EAX
//         0049ef1b     MOV        dword ptr [ESP + local_4],0x0
//         0049ef23     JZ         LAB_0049ef2c
//         0049ef25     MOV        this,EAX
//         0049ef27     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
//                               LAB_0049ef2c                                                 XREF[1]:     0049ef23(j)
//                              Scr_main.cpp:289 (25)
//         0049ef2c     PUSH       0x0
//         0049ef2e     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
//         0049ef33     MOV        this,panel_system
//         0049ef38     MOV        dword ptr [ESP + local_4],0xffffffff
//         0049ef40     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              Scr_main.cpp:290 (15)
//         0049ef45     PUSH       s_Main_Menu                                      = "Main Menu"
//         0049ef4a     MOV        this,panel_system
//         0049ef4f     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              Scr_main.cpp:291 (7)
//         0049ef54     MOV        EAX,ESI
//         0049ef56     JMP        LAB_0049f0b6
//                               LAB_0049ef5b                                                 XREF[1]:     0049eeb6(j)
//                              Scr_main.cpp:294 (8)
//         0049ef5b     CMP        EDI,dword ptr [EBP + 0x484]
//         0049ef61     JNZ        LAB_0049efbd
//                              Scr_main.cpp:295 (11)
//         0049ef63     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049ef69     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
//                              Scr_main.cpp:296 (32)
//         0049ef6e     PUSH       0x6a0
//         0049ef73     CALL       operator_new                                     void * operator_new(uint param_1)
//         0049ef78     ADD        ESP,0x4
//         0049ef7b     MOV        dword ptr [ESP + param_1],EAX
//         0049ef7f     TEST       EAX,EAX
//         0049ef81     MOV        dword ptr [ESP + local_4],ESI
//         0049ef85     JZ         LAB_0049ef8e
//         0049ef87     MOV        this,EAX
//         0049ef89     CALL       TribeMPStartupScreen::TribeMPStartupScreen       undefined TribeMPStartupScreen(TribeMPStartup
//                               LAB_0049ef8e                                                 XREF[1]:     0049ef85(j)
//                              Scr_main.cpp:297 (25)
//         0049ef8e     PUSH       0x0
//         0049ef90     PUSH       s_MP_Startup_Screen                              = "MP Startup Screen"
//         0049ef95     MOV        this,panel_system
//         0049ef9a     MOV        dword ptr [ESP + local_4],0xffffffff
//         0049efa2     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              Scr_main.cpp:298 (15)
//         0049efa7     PUSH       s_Main_Menu                                      = "Main Menu"
//         0049efac     MOV        this,panel_system
//         0049efb1     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              Scr_main.cpp:299 (7)
//         0049efb6     MOV        EAX,ESI
//         0049efb8     JMP        LAB_0049f0b6
//                               LAB_0049efbd                                                 XREF[1]:     0049ef61(j)
//                              Scr_main.cpp:302 (8)
//         0049efbd     CMP        EDI,dword ptr [EBP + 0x488]
//         0049efc3     JNZ        LAB_0049efe4
//                              Scr_main.cpp:326 (24)
//         0049efc5     PUSH       0x64
//         0049efc7     PUSH       0x1c2
//         0049efcc     PUSH       s_Confirm_Dialog                                 = 43h
//         0049efd1     PUSH       0x1d4f7
//         0049efd6     MOV        this,EBP
//         0049efd8     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              Scr_main.cpp:327 (7)
//         0049efdd     MOV        EAX,ESI
//         0049efdf     JMP        LAB_0049f0b6
//                               LAB_0049efe4                                                 XREF[1]:     0049efc3(j)
//                              Scr_main.cpp:336 (12)
//         0049efe4     CMP        EDI,dword ptr [EBP + 0x48c]
//         0049efea     JNZ        LAB_0049f08c
//                              Scr_main.cpp:344 (16)
//         0049eff0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049eff6     MOV        EAX,dword ptr [this->_padding_ + 0x9ac]
//         0049effc     TEST       EAX,EAX
//         0049effe     JNZ        LAB_0049f037
//                              Scr_main.cpp:345 (11)
//         0049f000     PUSH       0x0
//         0049f002     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         0049f007     TEST       EAX,EAX
//         0049f009     JNZ        LAB_0049f026
//                              Scr_main.cpp:346 (20)
//         0049f00b     PUSH       0x64
//         0049f00d     PUSH       0x1c2
//         0049f012     PUSH       EAX
//                              language.dll match for 0x7da: "You must insert a game CD to u
//         0049f013     PUSH       0x7da
//         0049f018     MOV        this,EBP
//         0049f01a     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              Scr_main.cpp:347 (7)
//         0049f01f     MOV        EAX,ESI
//         0049f021     JMP        LAB_0049f0b6
//                               LAB_0049f026                                                 XREF[1]:     0049f009(j)
//                              Scr_main.cpp:350 (17)
//         0049f026     MOV        EAX,[rge_base_game]                              = 00000000
//         0049f02b     MOV        dword ptr [EAX + 0x9ac],ESI
//         0049f031     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                               LAB_0049f037                                                 XREF[1]:     0049effe(j)
//                              Scr_main.cpp:353 (5)
//         0049f037     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
//                              Scr_main.cpp:354 (36)
//         0049f03c     PUSH       0x490
//         0049f041     CALL       operator_new                                     void * operator_new(uint param_1)
//         0049f046     ADD        ESP,0x4
//         0049f049     MOV        dword ptr [ESP + param_1],EAX
//         0049f04d     TEST       EAX,EAX
//         0049f04f     MOV        dword ptr [ESP + local_4],0x2
//         0049f057     JZ         LAB_0049f060
//         0049f059     MOV        this,EAX
//         0049f05b     CALL       TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu     undefined TRIBE_Screen_Sed_Menu(TRIBE_Screen_
//                               LAB_0049f060                                                 XREF[1]:     0049f057(j)
//                              Scr_main.cpp:355 (25)
//         0049f060     PUSH       0x0
//         0049f062     PUSH       s_Scenario_Editor_Menu                           = "Scenario Editor Menu"
//         0049f067     MOV        this,panel_system
//         0049f06c     MOV        dword ptr [ESP + local_4],0xffffffff
//         0049f074     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              Scr_main.cpp:356 (15)
//         0049f079     PUSH       s_Main_Menu                                      = "Main Menu"
//         0049f07e     MOV        this,panel_system
//         0049f083     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              Scr_main.cpp:358 (4)
//         0049f088     MOV        EAX,ESI
//         0049f08a     JMP        LAB_0049f0b6
//                               LAB_0049f08c                                                 XREF[1]:     0049efea(j)
//                              Scr_main.cpp:367 (8)
//         0049f08c     CMP        EDI,dword ptr [EBP + 0x490]
//         0049f092     JNZ        LAB_0049f0a3
//                              Scr_main.cpp:374 (11)
//         0049f094     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049f09a     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              Scr_main.cpp:376 (4)
//         0049f09f     MOV        EAX,ESI
//         0049f0a1     JMP        LAB_0049f0b6
//                               LAB_0049f0a3                                                 XREF[3]:     0049ee25(j), 0049eeaa(j),
//                                                                                                         0049f092(j)
//                              Scr_main.cpp:386 (19)
//         0049f0a3     MOV        EDX,dword ptr [ESP + param_4]
//         0049f0a7     MOV        EAX,dword ptr [ESP + param_3]
//         0049f0ab     PUSH       EDX
//         0049f0ac     PUSH       EAX
//         0049f0ad     PUSH       EBX
//         0049f0ae     PUSH       EDI
//         0049f0af     MOV        this,EBP
//         0049f0b1     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                               LAB_0049f0b6                                                 XREF[8]:     0049ee9e(j), 0049eeed(j),
//                                                                                                         0049ef56(j), 0049efb8(j),
//                                                                                                         0049efdf(j), 0049f021(j),
//                                                                                                         0049f08a(j), 0049f0a1(j)
//                              Scr_main.cpp:387 (21)
//         0049f0b6     MOV        this,dword ptr [ESP + local_c]
//         0049f0ba     POP        EDI
//         0049f0bb     POP        ESI
//         0049f0bc     POP        EBP
//         0049f0bd     MOV        dword ptr FS:[0x0],this
//         0049f0c4     POP        EBX
//         0049f0c5     ADD        ESP,0xc
//         0049f0c8     RET        0x10
//         0049f0cb     ??         90h
//         0049f0cc     NOP
//         0049f0cd     NOP
//         0049f0ce     NOP
//         0049f0cf     NOP
    return 0;
}

TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error() {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Screen_Main_Error(TRIBE_Screen_Main_Error
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0049f128(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     0049f14b(R), 0049f20b(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049f0f0(W)
//                               ??0TRIBE_Screen_Main_Error@@QAE@XZ                           XREF[2]:     cancelScreen:004a2c88(c),
//                               TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error                          setup:00521c38(c)
//                              Scr_main.cpp:395 (41)
//         0049f0d0     PUSH       -0x1
//         0049f0d2     PUSH       FUN_0055f0b8
//         0049f0d7     MOV        EAX,FS:[0x0]
//         0049f0dd     PUSH       EAX
//         0049f0de     MOV        dword ptr FS:[0x0],ESP
//         0049f0e5     PUSH       this
//         0049f0e6     PUSH       EBX
//         0049f0e7     PUSH       ESI
//         0049f0e8     PUSH       EDI
//         0049f0e9     MOV        ESI,this
//         0049f0eb     PUSH       s_Main_Error_Screen                              = "Main Error Screen"
//         0049f0f0     MOV        dword ptr [ESP + local_10],ESI
//         0049f0f4     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//                              Scr_main.cpp:397 (6)
//         0049f0f9     LEA        EDI,[ESI + 0x478]
//                              Scr_main.cpp:398 (12)
//         0049f0ff     LEA        EBX,[ESI + 0x47c]
//         0049f105     MOV        dword ptr [ESI],TRIBE_Screen_Main_Error::`vfta   = 0049f220
//                              Scr_main.cpp:401 (52)
//         0049f10b     PUSH       0x0
//         0049f10d     MOV        dword ptr [EDI],0x0
//         0049f113     MOV        dword ptr [EBX],0x0
//         0049f119     MOV        EAX,[rge_base_game]                              = 00000000
//         0049f11e     PUSH       0xc383
//         0049f123     PUSH       s_scr1                                           = "scr1"
//         0049f128     MOV        dword ptr [ESP + local_4],0x0
//         0049f130     MOV        this,dword ptr [EAX + 0x4c]
//         0049f133     PUSH       this
//         0049f134     MOV        this,ESI
//         0049f136     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         0049f13b     TEST       EAX,EAX
//         0049f13d     JNZ        LAB_0049f15d
//                              Scr_main.cpp:403 (10)
//         0049f13f     MOV        dword ptr [ESI + 0xd8],0x1
//                              Scr_main.cpp:420 (20)
//         0049f149     MOV        EAX,ESI
//         0049f14b     MOV        this,dword ptr [ESP + local_c]
//         0049f14f     MOV        dword ptr FS:[0x0],this
//         0049f156     POP        EDI
//         0049f157     POP        ESI
//         0049f158     POP        EBX
//         0049f159     ADD        ESP,0x10
//         0049f15c     RET
//                               LAB_0049f15d                                                 XREF[1]:     0049f13d(j)
//                              Scr_main.cpp:407 (17)
//         0049f15d     PUSH       0x1e0
//         0049f162     PUSH       0x280
//         0049f167     MOV        this,ESI
//         0049f169     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              Scr_main.cpp:410 (36)
//         0049f16e     PUSH       0x1
//         0049f170     PUSH       0x1
//         0049f172     PUSH       0x1
//         0049f174     PUSH       0x4
//         0049f176     PUSH       0x190
//         0049f17b     PUSH       0x230
//         0049f180     PUSH       0x28
//         0049f182     PUSH       0x28
//         0049f184     PUSH       s_                                               = ""
//         0049f189     PUSH       EDI
//         0049f18a     PUSH       ESI
//         0049f18b     MOV        this,ESI
//         0049f18d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              Scr_main.cpp:411 (39)
//         0049f192     PUSH       0x0
//         0049f194     PUSH       0x0
//         0049f196     PUSH       0x0
//         0049f198     PUSH       0x1e
//         0049f19a     PUSH       0xf0
//         0049f19f     PUSH       0x1b8
//         0049f1a4     PUSH       0xc8
//         0049f1a9     PUSH       0x0
//                              language.dll match for 0xfa1: "OK"
//         0049f1ab     PUSH       0xfa1
//         0049f1b0     PUSH       EBX
//         0049f1b1     PUSH       ESI
//         0049f1b2     MOV        this,ESI
//         0049f1b4     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//                              Scr_main.cpp:414 (40)
//         0049f1b9     PUSH       0x0
//         0049f1bb     PUSH       -0x1
//         0049f1bd     PUSH       -0x1
//         0049f1bf     PUSH       0x0
//         0049f1c1     PUSH       0x0
//         0049f1c3     PUSH       0x0
//         0049f1c5     PUSH       0x0
//         0049f1c7     LEA        EDI,[ESI + 0x480]
//         0049f1cd     PUSH       0x0
//                              language.dll match for 0x3ea: "X"
//         0049f1cf     PUSH       0x3ea
//         0049f1d4     PUSH       EDI
//         0049f1d5     PUSH       ESI
//         0049f1d6     MOV        this,ESI
//         0049f1d8     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         0049f1dd     TEST       EAX,EAX
//         0049f1df     JZ         LAB_0049f20b
//                              Scr_main.cpp:415 (9)
//         0049f1e1     MOV        this,dword ptr [EDI]
//         0049f1e3     PUSH       0x1
//         0049f1e5     MOV        EDX,dword ptr [this->_padding_]
//         0049f1e7     CALL       dword ptr [EDX + 0x14]
//                              Scr_main.cpp:416 (33)
//         0049f1ea     MOV        this,dword ptr [EDI]
//         0049f1ec     PUSH       0x0
//         0049f1ee     PUSH       0x0=>DAT_fffffff8
//         0049f1f0     PUSH       0x0=>DAT_fffffff4
//         0049f1f2     MOV        EAX,dword ptr [this->_padding_]
//         0049f1f4     PUSH       0x0=>DAT_fffffff0
//         0049f1f6     PUSH       0x11
//         0049f1f8     PUSH       0x11
//         0049f1fa     PUSH       0x11
//         0049f1fc     PUSH       0x11
//         0049f1fe     PUSH       0x4
//         0049f200     PUSH       0x4
//         0049f202     PUSH       0x4
//         0049f204     PUSH       0x4
//         0049f206     PUSH       0x9
//         0049f208     CALL       dword ptr [EAX + 0x18]
//                               LAB_0049f20b                                                 XREF[1]:     0049f1df(j)
//                              Scr_main.cpp:420 (20)
//         0049f20b     MOV        this,dword ptr [ESP + local_c]
//         0049f20f     MOV        EAX,ESI
//         0049f211     POP        EDI
//         0049f212     POP        ESI
//         0049f213     MOV        dword ptr FS:[0x0],this
//         0049f21a     POP        EBX
//         0049f21b     ADD        ESP,0x10
//         0049f21e     RET
//         0049f21f     ??         90h
}

TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Screen_Main_Error(TRIBE_Screen_Main_Error * t
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049f269(W), 0049f287(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049f294(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049f259(W)
//                               ??1TRIBE_Screen_Main_Error@@UAE@XZ                           XREF[1]:     `vector_deleting_destructor':0049f
//                               TRIBE_Screen_Main_Error::~TRIBE_Screen_Main_Error
//                              Scr_main.cpp:426 (35)
//         0049f240     PUSH       -0x1
//         0049f242     PUSH       FUN_0055f0d8
//         0049f247     MOV        EAX,FS:[0x0]
//         0049f24d     PUSH       EAX
//         0049f24e     MOV        dword ptr FS:[0x0],ESP
//         0049f255     PUSH       this
//         0049f256     PUSH       ESI
//         0049f257     MOV        ESI,this
//         0049f259     MOV        dword ptr [ESP + local_10],ESI
//         0049f25d     MOV        dword ptr [ESI],TRIBE_Screen_Main_Error::`vfta   = 0049f220
//                              Scr_main.cpp:427 (20)
//         0049f263     LEA        EAX,[ESI + 0x478]
//         0049f269     MOV        dword ptr [ESP + local_4],0x0
//         0049f271     PUSH       EAX
//         0049f272     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              Scr_main.cpp:428 (16)
//         0049f277     LEA        this,[ESI + 0x47c]
//         0049f27d     PUSH       this
//         0049f27e     MOV        this,ESI
//         0049f280     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         0049f285     MOV        this,ESI
//                              Scr_main.cpp:429 (29)
//         0049f287     MOV        dword ptr [ESP + local_4],0xffffffff
//         0049f28f     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         0049f294     MOV        this,dword ptr [ESP + local_c]
//         0049f298     POP        ESI
//         0049f299     MOV        dword ptr FS:[0x0],this
//         0049f2a0     ADD        ESP,0x10
//         0049f2a3     RET
//         0049f2a4     ??         90h
//         0049f2a5     NOP
//         0049f2a6     NOP
//         0049f2a7     NOP
//         0049f2a8     NOP
//         0049f2a9     NOP
//         0049f2aa     NOP
//         0049f2ab     NOP
//         0049f2ac     NOP
//         0049f2ad     NOP
//         0049f2ae     NOP
//         0049f2af     NOP
}

void TRIBE_Screen_Main_Error::set_text(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Main_Error * this, char * para
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     0049f2b6(R)
//                               ?set_text@TRIBE_Screen_Main_Error@@QAEXPAD@Z
//                               TRIBE_Screen_Main_Error::set_text
//                              Scr_main.cpp:435 (19)
//         0049f2b0     MOV        this,dword ptr [ECX + this->message]
//         0049f2b6     MOV        EDX,dword ptr [ESP + param_1]
//         0049f2ba     PUSH       EDX
//         0049f2bb     MOV        EAX,dword ptr [this->_padding_]
//         0049f2bd     CALL       dword ptr [EAX + 0xe8]
//                              Scr_main.cpp:437 (3)
//         0049f2c3     RET        0x4
//         0049f2c6     ??         90h
//         0049f2c7     NOP
//         0049f2c8     NOP
//         0049f2c9     NOP
//         0049f2ca     NOP
//         0049f2cb     NOP
//         0049f2cc     NOP
//         0049f2cd     NOP
//         0049f2ce     NOP
//         0049f2cf     NOP
    return;
}

void TRIBE_Screen_Main_Error::set_text(long param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Main_Error * this, long param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     0049f2d6(R)
//                               ?set_text@TRIBE_Screen_Main_Error@@QAEXJ@Z                   XREF[2]:     cancelScreen:004a2cae(c),
//                               TRIBE_Screen_Main_Error::set_text                                         setup:00521c65(c)
//                              Scr_main.cpp:443 (19)
//         0049f2d0     MOV        this,dword ptr [ECX + this->message]
//         0049f2d6     MOV        EDX,dword ptr [ESP + param_1]
//         0049f2da     PUSH       EDX
//         0049f2db     MOV        EAX,dword ptr [this->_padding_]
//         0049f2dd     CALL       dword ptr [EAX + 0xe4]
//                              Scr_main.cpp:445 (3)
//         0049f2e3     RET        0x4
//         0049f2e6     ??         90h
//         0049f2e7     NOP
//         0049f2e8     NOP
//         0049f2e9     NOP
//         0049f2ea     NOP
//         0049f2eb     NOP
//         0049f2ec     NOP
//         0049f2ed     NOP
//         0049f2ee     NOP
//         0049f2ef     NOP
    return;
}

long TRIBE_Screen_Main_Error::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TRIBE_Screen_Main_Error * this, TPanel * para
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0049f2f0(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     0049f2f4(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0049f330(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049f32b(R)
//                               ?action@TRIBE_Screen_Main_Error@@UAEJPAVTPanel@@JKK@Z        XREF[1]:     0057312c(*)
//                               TRIBE_Screen_Main_Error::action
//                              Scr_main.cpp:451 (13)
//         0049f2f0     MOV        EAX,dword ptr [ESP + param_1]
//         0049f2f4     MOV        EDX,dword ptr [ESP + param_2]
//         0049f2f8     TEST       EAX,EAX
//         0049f2fa     PUSH       ESI
//         0049f2fb     JZ         LAB_0049f32b
//                              Scr_main.cpp:454 (11)
//         0049f2fd     CMP        EAX,dword ptr [ECX + this->cancel_button]
//         0049f303     JNZ        LAB_0049f30a
//         0049f305     CMP        EDX,0x1
//                              Scr_main.cpp:460 (2)
//         0049f308     JZ         LAB_0049f317
//                               LAB_0049f30a                                                 XREF[1]:     0049f303(j)
//                              Scr_main.cpp:463 (13)
//         0049f30a     CMP        EAX,dword ptr [ECX + this->close_button]
//         0049f310     JNZ        LAB_0049f32b
//         0049f312     CMP        EDX,0x1
//         0049f315     JNZ        LAB_0049f32b
//                               LAB_0049f317                                                 XREF[1]:     0049f308(j)
//                              Scr_main.cpp:468 (11)
//         0049f317     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049f31d     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              Scr_main.cpp:469 (5)
//         0049f322     MOV        EAX,0x1
//                              Scr_main.cpp:474 (4)
//         0049f327     POP        ESI
//         0049f328     RET        0x10
//                               LAB_0049f32b                                                 XREF[3]:     0049f2fb(j), 0049f310(j),
//                                                                                                         0049f315(j)
//                              Scr_main.cpp:473 (17)
//         0049f32b     MOV        ESI,dword ptr [ESP + param_4]
//         0049f32f     PUSH       ESI
//         0049f330     MOV        ESI,dword ptr [ESP + param_3]
//         0049f334     PUSH       ESI
//         0049f335     PUSH       EDX
//         0049f336     PUSH       EAX
//         0049f337     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              Scr_main.cpp:474 (4)
//         0049f33c     POP        ESI
//         0049f33d     RET        0x10
    return 0;
}

long TRIBE_Screen_Main_Error::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TRIBE_Screen_Main_Error * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_M    ECX:4 (auto)   this
//                               ?handle_idle@TRIBE_Screen_Main_Error@@UAEJXZ                 XREF[1]:     005730c4(*)
//                               TRIBE_Screen_Main_Error::handle_idle
//                              Scr_main.cpp:480 (3)
//         0049f340     PUSH       ESI
//         0049f341     MOV        ESI,this
//                              Scr_main.cpp:481 (16)
//         0049f343     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         0049f349     MOV        EAX,dword ptr [ECX + this->_padding_]
//         0049f34f     TEST       EAX,EAX
//         0049f351     JNZ        LAB_0049f358
//                              Scr_main.cpp:482 (5)
//         0049f353     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
//                               LAB_0049f358                                                 XREF[1]:     0049f351(j)
//                              Scr_main.cpp:483 (7)
//         0049f358     MOV        this,ESI
//         0049f35a     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              Scr_main.cpp:484 (2)
//         0049f35f     POP        ESI
//         0049f360     RET
//         0049f361     ??         90h
//         0049f362     NOP
//         0049f363     NOP
//         0049f364     NOP
//         0049f365     NOP
//         0049f366     NOP
//         0049f367     NOP
//         0049f368     NOP
//         0049f369     NOP
//         0049f36a     NOP
//         0049f36b     NOP
//         0049f36c     NOP
//         0049f36d     NOP
//         0049f36e     NOP
//         0049f36f     NOP
    return 0;
}

