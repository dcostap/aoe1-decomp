#include "common.h"
#include "dlg_dip.h"

TribeDiplomacyDialog::TribeDiplomacyDialog(TScreenPanel* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TribeDiplomacyDialog(TribeDiplomacyDialog * thi
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //              TScreenPanel *    Stack[0x4]:4   param_1                   XREF[1]:     0043c9d0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     0043c967(W), 0043ca7e(W), 0043caa6(W), 0043caca(W), 
    //                                                                                     0043caf2(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0043d694(R)  
    //              TPanel *[35]      Stack[-0x9c]   tabList
    //              char[100]         Stack[-0x100   temp_str                  XREF[1,2]:   0043cd65(*), 0043cc7a(*), 0043cc88(*)  
    //              tagPALETTEENTRY   Stack[-0x104   paletteColor              XREF[1]:     0043c956(W)  
    //              undefined4        Stack[-0x108   local_108                 XREF[1]:     0043cd4c(W)  
    //              int               Stack[-0x110   disable_buttons           XREF[1]:     0043cd3c(W)  
    //              undefined4        Stack[-0x114   local_114                 XREF[3]:     0043ca78(W), 0043cac4(W), 0043cd48(W)  
    //              undefined4        Stack[-0x118   local_118                 XREF[1]:     0043c96e(W)  
    //              int               Stack[-0x11c   tabCount                  XREF[1]:     0043cd2f(W)  
    //              int               Stack[-0x124   humanity                  XREF[1]:     0043cd09(W)  
    //              RGE_Game_World    Stack[-0x128   world                     XREF[1]:     0043ccfb(W)  
    //              int               Stack[-0x12c   a                         XREF[1]:     0043cd40(W)  
    //              undefined4        Stack[-0x130   local_130                 XREF[2]:     0043cd25(W), 0043cd5c(R)  
    //                               ??0TribeDiplomacyDialog@@QAE@PAVTScreenPanel@@@Z             XREF[1]:     command_diplomacy:0049c215(c)  
    //                               TribeDiplomacyDialog::TribeDiplomacyDialog
    //                              dlg_dip.cpp:77 (62)
    //         0043c930     PUSH       -0x1
    //         0043c932     PUSH       FUN_0055d047
    //         0043c937     MOV        EAX,FS:[0x0]
    //         0043c93d     PUSH       EAX
    //         0043c93e     MOV        dword ptr FS:[0x0],ESP
    //         0043c945     SUB        ESP,0x124
    //         0043c94b     PUSH       EBX
    //         0043c94c     PUSH       EBP
    //         0043c94d     PUSH       ESI
    //         0043c94e     PUSH       EDI
    //         0043c94f     MOV        ESI,this
    //         0043c951     PUSH       s_Diplomacy_Dialog                               = "Diplomacy Dialog"
    //         0043c956     MOV        dword ptr [ESP + paletteColor.peRed],ESI
    //         0043c95a     CALL       TDialogPanel::TDialogPanel                       undefined TDialogPanel(TDialogPanel * this, c
    //         0043c95f     XOR        EBX,EBX
    //         0043c961     MOV        dword ptr [ESI],TribeDiplomacyDialog::`vftable'  = 0043d6c0
    //         0043c967     MOV        dword ptr [ESP + local_4],EBX
    //                              dlg_dip.cpp:84 (15)
    //         0043c96e     MOV        dword ptr [ESP + local_118],EBX
    //         0043c972     LEA        EAX,[ESI + 0x4b0]
    //         0043c978     MOV        this,0x8
    //                               LAB_0043c97d                                                 XREF[1]:     0043c9b9(j)  
    //                              dlg_dip.cpp:89 (3)
    //         0043c97d     MOV        dword ptr [EAX + -0x20],EBX
    //                              dlg_dip.cpp:90 (2)
    //         0043c980     MOV        dword ptr [EAX],EBX
    //                              dlg_dip.cpp:91 (3)
    //         0043c982     MOV        dword ptr [EAX + 0x20],EBX
    //                              dlg_dip.cpp:92 (3)
    //         0043c985     MOV        dword ptr [EAX + 0x40],EBX
    //                              dlg_dip.cpp:93 (3)
    //         0043c988     MOV        dword ptr [EAX + 0x64],EBX
    //                              dlg_dip.cpp:94 (6)
    //         0043c98b     MOV        dword ptr [EAX + 0xa4],EBX
    //                              dlg_dip.cpp:95 (6)
    //         0043c991     MOV        dword ptr [EAX + 0x84],EBX
    //                              dlg_dip.cpp:96 (6)
    //         0043c997     MOV        dword ptr [EAX + 0xc4],EBX
    //                              dlg_dip.cpp:97 (6)
    //         0043c99d     MOV        dword ptr [EAX + 0x180],EBX
    //                              dlg_dip.cpp:98 (6)
    //         0043c9a3     MOV        dword ptr [EAX + 0x1a0],EBX
    //                              dlg_dip.cpp:99 (6)
    //         0043c9a9     MOV        dword ptr [EAX + 0x1c0],EBX
    //                              dlg_dip.cpp:100 (12)
    //         0043c9af     MOV        dword ptr [EAX + 0x1e0],EBX
    //         0043c9b5     ADD        EAX,0x4
    //         0043c9b8     DEC        this
    //         0043c9b9     JNZ        LAB_0043c97d
    //                              dlg_dip.cpp:369 (224)
    //         0043c9bb     LEA        EDI,[ESI + 0x594]
    //         0043c9c1     MOV        this,0x18
    //         0043c9c6     XOR        EAX,EAX
    //         0043c9c8     LEA        EBP,[ESI + 0x510]
    //         0043c9ce     STOSD.REP  ES:EDI
    //         0043c9d0     MOV        EDI,dword ptr [ESP + param_1]
    //         0043c9d7     PUSH       0x1
    //         0043c9d9     MOV        this,EDI
    //         0043c9db     MOV        dword ptr [ESI + 0x5f4],EBX
    //         0043c9e1     MOV        dword ptr [ESI + 0x5f8],EBX
    //         0043c9e7     MOV        dword ptr [ESI + 0x600],EBX
    //         0043c9ed     MOV        dword ptr [ESI + 0x5fc],EBX
    //         0043c9f3     MOV        dword ptr [ESI + 0x604],EBX
    //         0043c9f9     MOV        dword ptr [EBP],EBX
    //         0043c9fc     MOV        dword ptr [ESI + 0x608],EBX
    //         0043ca02     MOV        dword ptr [ESI + 0x60c],EBX
    //         0043ca08     MOV        dword ptr [ESI + 0x628],EBX
    //         0043ca0e     MOV        dword ptr [ESI + 0x62c],EBX
    //         0043ca14     MOV        dword ptr [ESI + 0x624],EBX
    //         0043ca1a     MOV        dword ptr [ESI + 0x620],EBX
    //         0043ca20     MOV        dword ptr [ESI + 0x614],EBX
    //         0043ca26     MOV        dword ptr [ESI + 0x61c],EBX
    //         0043ca2c     MOV        dword ptr [ESI + 0x610],EBX
    //         0043ca32     MOV        dword ptr [ESI + 0x618],EBX
    //         0043ca38     MOV        dword ptr [ESI + 0x6b4],EBX
    //         0043ca3e     CALL       TEasy_Panel::get_popup_info_id                   long get_popup_info_id(TEasy_Panel * this)
    //         0043ca43     PUSH       EAX
    //         0043ca44     MOV        this,EDI
    //         0043ca46     CALL       TEasy_Panel::get_popup_info_file                 char * get_popup_info_file(TEasy_Panel * this)
    //         0043ca4b     PUSH       EAX
    //         0043ca4c     PUSH       0x195
    //         0043ca51     PUSH       0x271
    //         0043ca56     PUSH       EDI
    //         0043ca57     MOV        this,EDI
    //         0043ca59     CALL       TPanel::renderArea                               TDrawArea * renderArea(TPanel * this)
    //         0043ca5e     PUSH       EAX
    //         0043ca5f     MOV        this,ESI
    //         0043ca61     CALL       TDialogPanel::setup                              int setup(TDialogPanel * this, TDrawArea * pa
    //         0043ca66     TEST       EAX,EAX
    //         0043ca68     JZ         LAB_0043d694
    //         0043ca6e     PUSH       0x20
    //         0043ca70     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0043ca75     ADD        ESP,0x4
    //         0043ca78     MOV        dword ptr [ESP + local_114],EAX
    //         0043ca7c     CMP        EAX,EBX
    //         0043ca7e     MOV        byte ptr [ESP + local_4],0x1
    //         0043ca86     JZ         LAB_0043ca9b
    //         0043ca88     PUSH       0xc62c
    //         0043ca8d     PUSH       s_tradicon.shp                                   = "tradicon.shp"
    //         0043ca92     MOV        this,EAX
    //         0043ca94     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0043ca99     JMP        LAB_0043ca9d
    //                               LAB_0043ca9b                                                 XREF[1]:     0043ca86(j)  
    //                              dlg_dip.cpp:134 (31)
    //         0043ca9b     XOR        EAX,EAX
    //                               LAB_0043ca9d                                                 XREF[1]:     0043ca99(j)  
    //         0043ca9d     XOR        this,this
    //         0043ca9f     CMP        EAX,EBX
    //         0043caa1     SETZ       this
    //         0043caa4     TEST       this,this
    //         0043caa6     MOV        byte ptr [ESP + local_4],0x0
    //         0043caae     MOV        dword ptr [ESI + 0x608],EAX
    //         0043cab4     JNZ        LAB_0043d694
    //                              dlg_dip.cpp:135 (76)
    //         0043caba     PUSH       0x20
    //         0043cabc     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0043cac1     ADD        ESP,0x4
    //         0043cac4     MOV        dword ptr [ESP + local_114],EAX
    //         0043cac8     CMP        EAX,EBX
    //         0043caca     MOV        byte ptr [ESP + local_4],0x2
    //         0043cad2     JZ         LAB_0043cae7
    //         0043cad4     PUSH       0xc63a
    //         0043cad9     PUSH       s_dlg_plbn.shp                                   = "dlg_plbn.shp"
    //         0043cade     MOV        this,EAX
    //         0043cae0     CALL       TShape::TShape                                   undefined TShape(TShape * this, char * param_
    //         0043cae5     JMP        LAB_0043cae9
    //                               LAB_0043cae7                                                 XREF[1]:     0043cad2(j)  
    //         0043cae7     XOR        EAX,EAX
    //                               LAB_0043cae9                                                 XREF[1]:     0043cae5(j)  
    //         0043cae9     XOR        this,this
    //         0043caeb     CMP        EAX,EBX
    //         0043caed     SETZ       this
    //         0043caf0     TEST       this,this
    //         0043caf2     MOV        byte ptr [ESP + local_4],0x0
    //         0043cafa     MOV        dword ptr [ESI + 0x60c],EAX
    //         0043cb00     JNZ        LAB_0043d694
    //                              dlg_dip.cpp:138 (13)
    //         0043cb06     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043cb0c     PUSH       0x1
    //         0043cb0e     CALL       RGE_Base_Game::get_font                          RGE_Font * get_font(RGE_Base_Game * this, int
    //                              dlg_dip.cpp:141 (46)
    //         0043cb13     PUSH       EBX
    //         0043cb14     PUSH       0x1
    //         0043cb16     PUSH       0x1
    //         0043cb18     PUSH       0x1
    //         0043cb1a     PUSH       0x1e
    //         0043cb1c     PUSH       0x1f4
    //         0043cb21     PUSH       0x5
    //         0043cb23     PUSH       0x48
    //         0043cb25     LEA        EAX,[ESI + 0x490]
    //                              language.dll match for 0x267b: "Diplomacy"
    //         0043cb2b     PUSH       0x267b
    //         0043cb30     PUSH       EAX
    //         0043cb31     PUSH       ESI
    //         0043cb32     MOV        this,ESI
    //         0043cb34     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cb39     TEST       EAX,EAX
    //         0043cb3b     JZ         LAB_0043d694
    //                              dlg_dip.cpp:143 (44)
    //         0043cb41     PUSH       0x1
    //         0043cb43     PUSH       0x1
    //         0043cb45     PUSH       0x1
    //         0043cb47     PUSH       0xb
    //         0043cb49     PUSH       0x3c
    //         0043cb4b     PUSH       0xaf
    //         0043cb50     PUSH       0x6e
    //         0043cb52     PUSH       0x1b8
    //                              language.dll match for 0x2687: "You need a Market to pay trib
    //         0043cb57     PUSH       0x2687
    //         0043cb5c     PUSH       EBP
    //         0043cb5d     PUSH       ESI
    //         0043cb5e     MOV        this,ESI
    //         0043cb60     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cb65     TEST       EAX,EAX
    //         0043cb67     JZ         LAB_0043d694
    //                              dlg_dip.cpp:146 (45)
    //         0043cb6d     PUSH       EBX
    //         0043cb6e     PUSH       0x1
    //         0043cb70     PUSH       EBX
    //         0043cb71     PUSH       0xb
    //         0043cb73     PUSH       0x1e
    //         0043cb75     PUSH       0x82
    //         0043cb7a     PUSH       0x32
    //         0043cb7c     PUSH       0x5
    //         0043cb7e     LEA        this,[ESI + 0x494]
    //                              language.dll match for 0x2686: "Name"
    //         0043cb84     PUSH       0x2686
    //         0043cb89     PUSH       this
    //         0043cb8a     PUSH       ESI
    //         0043cb8b     MOV        this,ESI
    //         0043cb8d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cb92     TEST       EAX,EAX
    //         0043cb94     JZ         LAB_0043d694
    //                              dlg_dip.cpp:147 (45)
    //         0043cb9a     PUSH       EBX
    //         0043cb9b     PUSH       0x1
    //         0043cb9d     PUSH       EBX
    //         0043cb9e     PUSH       0xb
    //         0043cba0     PUSH       0x1e
    //         0043cba2     PUSH       0x50
    //         0043cba4     PUSH       0x32
    //         0043cba6     PUSH       0x89
    //         0043cbab     LEA        EDX,[ESI + 0x498]
    //                              language.dll match for 0x267c: "Civilization"
    //         0043cbb1     PUSH       0x267c
    //         0043cbb6     PUSH       EDX
    //         0043cbb7     PUSH       ESI
    //         0043cbb8     MOV        this,ESI
    //         0043cbba     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cbbf     TEST       EAX,EAX
    //         0043cbc1     JZ         LAB_0043d694
    //                              dlg_dip.cpp:148 (45)
    //         0043cbc7     PUSH       EBX
    //         0043cbc8     PUSH       0x1
    //         0043cbca     PUSH       EBX
    //         0043cbcb     PUSH       0xb
    //         0043cbcd     PUSH       0x1e
    //         0043cbcf     PUSH       0x46
    //         0043cbd1     PUSH       0x32
    //         0043cbd3     PUSH       0xeb
    //         0043cbd8     LEA        EAX,[ESI + 0x49c]
    //                              language.dll match for 0x267d: "Ally"
    //         0043cbde     PUSH       0x267d
    //         0043cbe3     PUSH       EAX
    //         0043cbe4     PUSH       ESI
    //         0043cbe5     MOV        this,ESI
    //         0043cbe7     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cbec     TEST       EAX,EAX
    //         0043cbee     JZ         LAB_0043d694
    //                              dlg_dip.cpp:149 (45)
    //         0043cbf4     PUSH       EBX
    //         0043cbf5     PUSH       0x1
    //         0043cbf7     PUSH       EBX
    //         0043cbf8     PUSH       0xb
    //         0043cbfa     PUSH       0x1e
    //         0043cbfc     PUSH       0x46
    //         0043cbfe     PUSH       0x32
    //         0043cc00     PUSH       0x122
    //         0043cc05     LEA        this,[ESI + 0x4a0]
    //                              language.dll match for 0x267e: "Neutral"
    //         0043cc0b     PUSH       0x267e
    //         0043cc10     PUSH       this
    //         0043cc11     PUSH       ESI
    //         0043cc12     MOV        this,ESI
    //         0043cc14     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cc19     TEST       EAX,EAX
    //         0043cc1b     JZ         LAB_0043d694
    //                              dlg_dip.cpp:150 (45)
    //         0043cc21     PUSH       EBX
    //         0043cc22     PUSH       0x1
    //         0043cc24     PUSH       EBX
    //         0043cc25     PUSH       0xb
    //         0043cc27     PUSH       0x1e
    //         0043cc29     PUSH       0x46
    //         0043cc2b     PUSH       0x32
    //         0043cc2d     PUSH       0x168
    //         0043cc32     LEA        EDX,[ESI + 0x4a4]
    //                              language.dll match for 0x267f: "Enemy"
    //         0043cc38     PUSH       0x267f
    //         0043cc3d     PUSH       EDX
    //         0043cc3e     PUSH       ESI
    //         0043cc3f     MOV        this,ESI
    //         0043cc41     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cc46     TEST       EAX,EAX
    //         0043cc48     JZ         LAB_0043d694
    //                              dlg_dip.cpp:153 (20)
    //         0043cc4e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043cc54     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043cc59     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043cc5c     FLD        float ptr [EAX + 0xb8]
    //                              dlg_dip.cpp:154 (38)
    //         0043cc62     FMUL       float ptr [DAT_0056f880]                         = align(2)
    //         0043cc68     CALL       __ftol                                           undefined __ftol()
    //         0043cc6d     PUSH       EAX
    //                              language.dll match for 0x2680: "Pay Tribute (cost %d%%)"
    //         0043cc6e     PUSH       0x2680
    //         0043cc73     MOV        this,ESI
    //         0043cc75     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         0043cc7a     LEA        this=>temp_str[4],[ESP + 0x48]
    //         0043cc7e     PUSH       EAX
    //         0043cc7f     PUSH       this
    //         0043cc80     CALL       sprintf                                          undefined sprintf()
    //         0043cc85     ADD        ESP,0xc
    //                              dlg_dip.cpp:155 (48)
    //         0043cc88     LEA        EDX=>temp_str[4],[ESP + 0x44]
    //         0043cc8c     LEA        EAX,[ESI + 0x4a8]
    //         0043cc92     MOV        this,ESI
    //         0043cc94     PUSH       EBX
    //         0043cc95     PUSH       0x1
    //         0043cc97     PUSH       EBX
    //         0043cc98     PUSH       0xb
    //         0043cc9a     PUSH       0x1e
    //         0043cc9c     PUSH       0xb4
    //         0043cca1     PUSH       0x32
    //         0043cca3     PUSH       0x1b8
    //         0043cca8     PUSH       EDX
    //         0043cca9     PUSH       EAX
    //         0043ccaa     PUSH       ESI
    //         0043ccab     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043ccb0     TEST       EAX,EAX
    //         0043ccb2     JZ         LAB_0043d694
    //                              dlg_dip.cpp:157 (51)
    //         0043ccb8     PUSH       EBX
    //         0043ccb9     PUSH       0x1
    //         0043ccbb     PUSH       EBX
    //         0043ccbc     PUSH       0xb
    //         0043ccbe     PUSH       0x1e
    //         0043ccc0     PUSH       0x12c
    //         0043ccc5     PUSH       0x14a
    //         0043ccca     PUSH       0x13e
    //         0043cccf     LEA        EAX,[ESI + 0x4ac]
    //                              language.dll match for 0x2681: "Allied Victory"
    //         0043ccd5     PUSH       0x2681
    //         0043ccda     PUSH       EAX
    //         0043ccdb     PUSH       ESI
    //         0043ccdc     MOV        this,ESI
    //         0043ccde     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cce3     TEST       EAX,EAX
    //         0043cce5     JZ         LAB_0043d694
    //                              dlg_dip.cpp:166 (10)
    //         0043cceb     MOV        dword ptr [ESI + 0x6b0],0xffffffff
    //                              dlg_dip.cpp:168 (6)
    //         0043ccf5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                              dlg_dip.cpp:170 (101)
    //         0043ccfb     MOV        dword ptr [ESP + world],0x1
    //         0043cd03     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         0043cd09     MOV        dword ptr [ESP + humanity],EDI
    //         0043cd0d     MOVSX      EDX,word ptr [EDI + 0x3c]
    //         0043cd11     DEC        EDX
    //         0043cd12     TEST       EDX,EDX
    //         0043cd14     JLE        LAB_0043d209
    //         0043cd1a     LEA        EAX,[ESI + 0x534]
    //         0043cd20     MOV        EBP,0xfffffad0
    //         0043cd25     MOV        dword ptr [ESP + local_130],EAX
    //         0043cd29     LEA        EAX,[ESI + 0x594]
    //         0043cd2f     MOV        dword ptr [ESP + tabCount],EAX
    //         0043cd33     MOV        EAX,0xfffffa6c
    //         0043cd38     SUB        EAX,ESI
    //         0043cd3a     SUB        EBP,ESI
    //         0043cd3c     MOV        dword ptr [ESP + disable_buttons],EBX
    //         0043cd40     MOV        dword ptr [ESP + a],0x50
    //         0043cd48     MOV        dword ptr [ESP + local_114],EAX
    //         0043cd4c     MOV        dword ptr [ESP + local_108],EBP
    //         0043cd50     JMP        LAB_0043cd5c
    //                               LAB_0043cd52                                                 XREF[1]:     0043d201(j)  
    //         0043cd52     MOV        EBP,dword ptr [ESP + 0x38]
    //         0043cd56     MOV        EDI,dword ptr [ESP + 0x1c]
    //         0043cd5a     XOR        EBX,EBX
    //                               LAB_0043cd5c                                                 XREF[1]:     0043cd50(j)  
    //         0043cd5c     MOV        this,dword ptr [ESP + local_130]
    //                              dlg_dip.cpp:173 (41)
    //         0043cd60     MOV        EAX,dword ptr [EDI + 0x40]
    //         0043cd63     ADD        EBP,this
    //         0043cd65     LEA        EDX=>temp_str,[ESP + 0x40]
    //         0043cd69     PUSH       EDX
    //         0043cd6a     PUSH       offset DAT_fffffff8
    //         0043cd6c     MOV        this,dword ptr [EBP + EAX*0x1]
    //         0043cd70     XOR        EAX,EAX
    //         0043cd72     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0043cd78     MOV        this,dword ptr [ESI + 0x20c]
    //         0043cd7e     MOV        AL,byte ptr [EDX + 0x25]
    //         0043cd81     PUSH       EAX=>DAT_fffffff4
    //         0043cd82     PUSH       this=>DAT_fffffff0
    //         0043cd83     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                              dlg_dip.cpp:178 (44)
    //         0043cd89     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0043cd8f     CMP        dword ptr [EDX + 0x1b0],0x5
    //         0043cd96     JZ         LAB_0043cdbb
    //         0043cd98     MOVSX      this,word ptr [EDI + 0x7c]
    //         0043cd9c     MOV        EAX,dword ptr [ESP + 0x18]
    //         0043cda0     CMP        EAX,this
    //         0043cda2     JZ         LAB_0043cdbf
    //         0043cda4     MOV        EDX,dword ptr [EDI + 0x40]
    //         0043cda7     MOV        this,dword ptr [EBP + EDX*0x1]
    //         0043cdab     MOV        DL,byte ptr [ECX + this->_padding_]
    //         0043cdb1     TEST       DL,DL
    //         0043cdb3     JNZ        LAB_0043cdbf
    //                              dlg_dip.cpp:181 (10)
    //         0043cdb5     MOV        dword ptr [ESP + 0x34],EBX
    //         0043cdb9     JMP        LAB_0043cdc7
    //                               LAB_0043cdbb                                                 XREF[1]:     0043cd96(j)  
    //         0043cdbb     MOV        EAX,dword ptr [ESP + 0x18]
    //                               LAB_0043cdbf                                                 XREF[2]:     0043cda2(j), 0043cdb3(j)  
    //                              dlg_dip.cpp:179 (8)
    //         0043cdbf     MOV        dword ptr [ESP + 0x34],0x1
    //                               LAB_0043cdc7                                                 XREF[1]:     0043cdb9(j)  
    //                              dlg_dip.cpp:184 (9)
    //         0043cdc7     MOVSX      EDX,word ptr [EDI + 0x7c]
    //         0043cdcb     CMP        EAX,EDX
    //         0043cdcd     JNZ        LAB_0043cdd6
    //         0043cdcf     DEC        EAX
    //                              dlg_dip.cpp:185 (6)
    //         0043cdd0     MOV        dword ptr [ESI + 0x6b0],EAX
    //                               LAB_0043cdd6                                                 XREF[1]:     0043cdcd(j)  
    //                              dlg_dip.cpp:190 (20)
    //         0043cdd6     MOV        EAX,dword ptr [ESP + 0x1c]
    //         0043cdda     XOR        EDI,EDI
    //         0043cddc     MOV        this,dword ptr [EAX + 0x40]
    //         0043cddf     MOV        EDX,dword ptr [EBP + this->_padding_*0x1]
    //         0043cde3     CMP        byte ptr [EDX + 0x80],0x2
    //                              dlg_dip.cpp:192 (2)
    //         0043cdea     JZ         LAB_0043ce5d
    //                              dlg_dip.cpp:195 (15)
    //         0043cdec     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043cdf2     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         0043cdf7     TEST       EAX,EAX
    //         0043cdf9     JZ         LAB_0043ce62
    //                              dlg_dip.cpp:198 (24)
    //         0043cdfb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043ce01     MOV        dword ptr [ESP + 0x20],EBX
    //         0043ce05     MOV        EBX,0x1
    //         0043ce0a     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
    //         0043ce0f     CMP        EAX,EBX
    //         0043ce11     JL         LAB_0043ce4f
    //                               LAB_0043ce13                                                 XREF[1]:     0043ce4d(j)  
    //                              dlg_dip.cpp:200 (18)
    //         0043ce13     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043ce19     PUSH       EBX
    //         0043ce1a     CALL       RGE_Base_Game::playerID                          int playerID(RGE_Base_Game * this, int param_1)
    //         0043ce1f     CMP        EAX,dword ptr [ESP + 0x18]
    //         0043ce23     JNZ        LAB_0043ce3f
    //                              dlg_dip.cpp:202 (12)
    //         0043ce25     MOV        this,dword ptr [comm]                            = 00000000
    //         0043ce2b     PUSH       EBX
    //         0043ce2c     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
    //                              dlg_dip.cpp:203 (10)
    //         0043ce31     CMP        EAX,0x2
    //         0043ce34     JZ         LAB_0043ce3b
    //         0043ce36     CMP        EAX,0x4
    //         0043ce39     JNZ        LAB_0043ce3f
    //                               LAB_0043ce3b                                                 XREF[1]:     0043ce34(j)  
    //                              dlg_dip.cpp:204 (4)
    //         0043ce3b     MOV        dword ptr [ESP + 0x20],EAX
    //                               LAB_0043ce3f                                                 XREF[2]:     0043ce23(j), 0043ce39(j)  
    //                              dlg_dip.cpp:198 (16)
    //         0043ce3f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043ce45     INC        EBX
    //         0043ce46     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
    //         0043ce4b     CMP        EBX,EAX
    //         0043ce4d     JLE        LAB_0043ce13
    //                               LAB_0043ce4f                                                 XREF[1]:     0043ce11(j)  
    //                              dlg_dip.cpp:207 (14)
    //         0043ce4f     MOV        EAX,dword ptr [ESP + 0x20]
    //         0043ce53     CMP        EAX,0x2
    //         0043ce56     JZ         LAB_0043ce62
    //         0043ce58     CMP        EAX,0x4
    //         0043ce5b     JZ         LAB_0043ce62
    //                               LAB_0043ce5d                                                 XREF[1]:     0043cdea(j)  
    //                              dlg_dip.cpp:208 (5)
    //         0043ce5d     MOV        EDI,0x1
    //                               LAB_0043ce62                                                 XREF[3]:     0043cdf9(j), 0043ce56(j), 
    //                                                                                                         0043ce5b(j)  
    //                              dlg_dip.cpp:215 (73)
    //         0043ce62     MOV        this,dword ptr [ESP + 0x1c]
    //         0043ce66     MOV        EAX,dword ptr [ESP + 0x10]
    //         0043ce6a     NEG        EDI
    //         0043ce6c     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0043ce6f     PUSH       0x0
    //         0043ce71     SBB        EDI,EDI
    //         0043ce73     PUSH       0x1
    //         0043ce75     AND        EDI,0xfffffffd
    //         0043ce78     LEA        EBX,[EAX + -0x44]
    //         0043ce7b     MOV        EAX,dword ptr [EBP + EDX*0x1]
    //         0043ce7f     ADD        EDI,0xb
    //         0043ce82     PUSH       0x0
    //         0043ce84     PUSH       EDI
    //         0043ce85     MOV        EDI,dword ptr [ESP + 0x24]
    //         0043ce89     MOV        this,dword ptr [EAX + 0x44]
    //         0043ce8c     PUSH       0x1e
    //                              language.dll match for 0x82: "B"
    //         0043ce8e     PUSH       0x82
    //         0043ce93     PUSH       EDI
    //         0043ce94     PUSH       0x5
    //         0043ce96     LEA        EDX,[EBX + -0x40]
    //         0043ce99     PUSH       this
    //         0043ce9a     PUSH       EDX
    //         0043ce9b     PUSH       ESI
    //         0043ce9c     MOV        this,ESI
    //         0043ce9e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cea3     TEST       EAX,EAX
    //         0043cea5     JZ         LAB_0043d694
    //                              dlg_dip.cpp:218 (42)
    //         0043ceab     LEA        EDX,[ESP + 0x44]
    //         0043ceaf     PUSH       0x64
    //         0043ceb1     PUSH       EDX
    //         0043ceb2     MOV        EDX,dword ptr [ESP + 0x24]
    //         0043ceb6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043cebc     PUSH       0x0
    //         0043cebe     MOV        EDX,dword ptr [EDX + 0x40]
    //         0043cec1     MOV        EAX,dword ptr [this->_padding_]
    //         0043cec3     MOV        EBP,dword ptr [EBP + EDX*0x1]
    //         0043cec7     XOR        EDX,EDX
    //         0043cec9     MOV        DL,byte ptr [EBP + 0x105]
    //         0043cecf     PUSH       EDX
    //         0043ced0     PUSH       0x69
    //         0043ced2     CALL       dword ptr [EAX + 0x28]
    //                              dlg_dip.cpp:219 (40)
    //         0043ced5     PUSH       0x0
    //         0043ced7     PUSH       offset DAT_fffffff8
    //         0043ced9     PUSH       0x0=>DAT_fffffff4
    //         0043cedb     PUSH       offset DAT_fffffff0
    //         0043cedd     PUSH       0x1e
    //         0043cedf     PUSH       0x64
    //         0043cee1     PUSH       EDI
    //         0043cee2     LEA        EAX,[ESP + 0x60]
    //         0043cee6     PUSH       0x89
    //         0043ceeb     PUSH       EAX
    //         0043ceec     PUSH       EBX
    //         0043ceed     PUSH       ESI
    //         0043ceee     MOV        this,ESI
    //         0043cef0     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043cef5     TEST       EAX,EAX
    //         0043cef7     JZ         LAB_0043d694
    //                              dlg_dip.cpp:221 (28)
    //         0043cefd     MOV        this,dword ptr [ESP + 0x1c]
    //         0043cf01     MOV        EAX,dword ptr [ESP + 0x18]
    //         0043cf05     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0043cf09     CMP        EAX,EDX
    //         0043cf0b     JZ         LAB_0043d04e
    //         0043cf11     MOV        EAX,dword ptr [ESP + 0x2c]
    //         0043cf15     MOV        EBP,dword ptr [ESP + 0x24]
    //                              dlg_dip.cpp:225 (37)
    //         0043cf19     PUSH       0x0
    //         0043cf1b     PUSH       0x0=>DAT_fffffff8
    //         0043cf1d     PUSH       offset DAT_fffffff4
    //         0043cf1f     PUSH       offset DAT_fffffff0
    //         0043cf21     PUSH       EDI
    //         0043cf22     PUSH       0xf0
    //         0043cf27     ADD        EAX,EBP
    //         0043cf29     PUSH       EBP
    //         0043cf2a     PUSH       ESI
    //         0043cf2b     MOV        this,ESI
    //         0043cf2d     MOV        dword ptr [ESP + 0x40],EAX
    //         0043cf31     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043cf36     TEST       EAX,EAX
    //         0043cf38     JZ         LAB_0043d694
    //                              dlg_dip.cpp:226 (15)
    //         0043cf3e     MOV        this,dword ptr [EBP]
    //         0043cf41     PUSH       -0x1
    //                              language.dll match for 0x7684: "Click to set your diplomatic 
    //         0043cf43     PUSH       offset DAT_fffffff8
    //         0043cf48     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:228 (41)
    //         0043cf4d     MOV        this,dword ptr [ESP + 0x14]
    //         0043cf51     PUSH       0x0
    //         0043cf53     LEA        EDI,[EBP + 0x8]
    //         0043cf56     PUSH       0x0=>DAT_fffffff8
    //         0043cf58     PUSH       offset DAT_fffffff4
    //         0043cf5a     PUSH       offset DAT_fffffff0
    //         0043cf5c     LEA        EBX,[EDI + -0x4]
    //         0043cf5f     PUSH       this
    //         0043cf60     PUSH       0x136
    //         0043cf65     PUSH       EBX
    //         0043cf66     PUSH       ESI
    //         0043cf67     MOV        this,ESI
    //         0043cf69     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043cf6e     TEST       EAX,EAX
    //         0043cf70     JZ         LAB_0043d694
    //                              dlg_dip.cpp:229 (14)
    //         0043cf76     MOV        this,dword ptr [EBX]
    //         0043cf78     PUSH       -0x1
    //                              language.dll match for 0x7685: "Click to set your diplomatic 
    //                              language.dll match for 0x7685: "Click to set your diplomatic 
    //         0043cf7a     PUSH       offset DAT_fffffff8
    //         0043cf7f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:231 (35)
    //         0043cf84     MOV        EDX,dword ptr [ESP + 0x14]
    //         0043cf88     PUSH       0x0
    //         0043cf8a     PUSH       0x0=>DAT_fffffff8
    //         0043cf8c     PUSH       offset DAT_fffffff4
    //         0043cf8e     PUSH       offset DAT_fffffff0
    //         0043cf90     PUSH       EDX
    //         0043cf91     PUSH       0x17c
    //         0043cf96     PUSH       EDI
    //         0043cf97     PUSH       ESI
    //         0043cf98     MOV        this,ESI
    //         0043cf9a     CALL       TEasy_Panel::create_radio_button                 int create_radio_button(TEasy_Panel * this, T
    //         0043cf9f     TEST       EAX,EAX
    //         0043cfa1     JZ         LAB_0043d694
    //                              dlg_dip.cpp:232 (21)
    //         0043cfa7     MOV        this,dword ptr [EDI]
    //         0043cfa9     PUSH       -0x1
    //                              language.dll match for 0x7686: "Click to set your diplomatic 
    //         0043cfab     PUSH       offset DAT_fffffff8
    //         0043cfb0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //         0043cfb5     MOV        this,dword ptr [ESP + 0x30]
    //         0043cfb9     LEA        EAX,[ECX + this+0x3]
    //                              dlg_dip.cpp:234 (10)
    //         0043cfbc     CMP        this,EAX
    //         0043cfbe     JGE        LAB_0043cfed
    //         0043cfc0     SUB        EAX,this
    //         0043cfc2     MOV        EDI,EBP
    //         0043cfc4     MOV        EBX,EAX
    //                               LAB_0043cfc6                                                 XREF[1]:     0043cfeb(j)  
    //                              dlg_dip.cpp:236 (10)
    //         0043cfc6     MOV        this,dword ptr [EDI]
    //         0043cfc8     PUSH       0x3
    //         0043cfca     PUSH       EBP=>DAT_fffffff8
    //         0043cfcb     CALL       TButtonPanel::set_radio_info                     void set_radio_info(TButtonPanel * this, TBut
    //                              dlg_dip.cpp:237 (14)
    //         0043cfd0     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043cfd5     CMP        dword ptr [EAX + 0x1b0],0x5
    //         0043cfdc     JNZ        LAB_0043cfe7
    //                              dlg_dip.cpp:238 (15)
    //         0043cfde     MOV        this,dword ptr [EDI]
    //         0043cfe0     PUSH       0x1
    //         0043cfe2     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0043cfe7                                                 XREF[1]:     0043cfdc(j)  
    //         0043cfe7     ADD        EDI,0x4
    //         0043cfea     DEC        EBX
    //         0043cfeb     JNZ        LAB_0043cfc6
    //                               LAB_0043cfed                                                 XREF[1]:     0043cfbe(j)  
    //                              dlg_dip.cpp:241 (23)
    //         0043cfed     MOV        EDI,dword ptr [ESP + 0x18]
    //         0043cff1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043cff7     PUSH       EDI
    //         0043cff8     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043cffd     MOV        this,EAX
    //         0043cfff     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
    //                              dlg_dip.cpp:242 (16)
    //         0043d004     MOV        this,dword ptr [ESP + 0x1c]
    //         0043d008     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0043d00c     CMP        EDI,EDX
    //         0043d00e     JZ         LAB_0043d03c
    //         0043d010     TEST       AL,AL
    //         0043d012     JZ         LAB_0043d03c
    //                              dlg_dip.cpp:244 (4)
    //         0043d014     CMP        AL,0x1
    //         0043d016     JNZ        LAB_0043d02a
    //                              dlg_dip.cpp:245 (16)
    //         0043d018     MOV        EAX,dword ptr [ESP + 0x20]
    //         0043d01c     MOV        this,dword ptr [ESI + EAX*0x1 + 0x598]
    //         0043d023     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //                              dlg_dip.cpp:246 (2)
    //         0043d028     JMP        LAB_0043d052
    //                               LAB_0043d02a                                                 XREF[1]:     0043d016(j)  
    //                              dlg_dip.cpp:247 (18)
    //         0043d02a     MOV        this,dword ptr [ESP + 0x20]
    //         0043d02e     MOV        this,dword ptr [ESI + this->_padding_*0x1 + 0x
    //         0043d035     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //         0043d03a     JMP        LAB_0043d052
    //                               LAB_0043d03c                                                 XREF[2]:     0043d00e(j), 0043d012(j)  
    //                              dlg_dip.cpp:243 (22)
    //         0043d03c     MOV        EDX,dword ptr [ESP + 0x20]
    //         0043d040     MOV        this,dword ptr [ESI + EDX*0x1 + 0x594]
    //         0043d047     CALL       TButtonPanel::set_radio_button                   void set_radio_button(TButtonPanel * this)
    //         0043d04c     JMP        LAB_0043d052
    //                               LAB_0043d04e                                                 XREF[1]:     0043cf0b(j)  
    //         0043d04e     MOV        EBP,dword ptr [ESP + 0x24]
    //                               LAB_0043d052                                                 XREF[3]:     0043d028(j), 0043d03a(j), 
    //                                                                                                         0043d04c(j)  
    //                              dlg_dip.cpp:250 (12)
    //         0043d052     MOV        EAX,dword ptr [ESP + 0x34]
    //         0043d056     TEST       EAX,EAX
    //         0043d058     JNZ        LAB_0043d1c4
    //                              dlg_dip.cpp:252 (45)
    //         0043d05e     MOV        EDI,dword ptr [ESP + 0x14]
    //         0043d062     MOV        EBP,dword ptr [ESP + 0x10]
    //         0043d066     PUSH       0x0
    //         0043d068     PUSH       0x0=>DAT_fffffff8
    //         0043d06a     PUSH       offset DAT_fffffff4
    //         0043d06c     PUSH       offset DAT_fffffff0
    //         0043d06e     PUSH       0x28
    //         0043d070     PUSH       EDI
    //         0043d071     PUSH       0x1b8
    //         0043d076     PUSH       0x0
    //         0043d078     PUSH       -0x1
    //         0043d07a     PUSH       EBP
    //         0043d07b     PUSH       ESI
    //         0043d07c     MOV        this,ESI
    //         0043d07e     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d083     TEST       EAX,EAX
    //         0043d085     JZ         LAB_0043d694
    //                              dlg_dip.cpp:255 (40)
    //         0043d08b     PUSH       0x0
    //         0043d08d     PUSH       0x0=>DAT_fffffff8
    //         0043d08f     PUSH       offset DAT_fffffff4
    //         0043d091     PUSH       offset DAT_fffffff0
    //         0043d093     PUSH       0x28
    //         0043d095     PUSH       EDI
    //         0043d096     PUSH       0x1e0
    //         0043d09b     LEA        EBX,[EBP + 0x20]
    //         0043d09e     PUSH       0x0
    //         0043d0a0     PUSH       -0x1
    //         0043d0a2     PUSH       EBX
    //         0043d0a3     PUSH       ESI
    //         0043d0a4     MOV        this,ESI
    //         0043d0a6     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d0ab     TEST       EAX,EAX
    //         0043d0ad     JZ         LAB_0043d694
    //                              dlg_dip.cpp:258 (42)
    //         0043d0b3     PUSH       0x0
    //         0043d0b5     PUSH       0x0=>DAT_fffffff8
    //         0043d0b7     PUSH       offset DAT_fffffff4
    //         0043d0b9     PUSH       offset DAT_fffffff0
    //         0043d0bb     MOV        EAX,EDI
    //         0043d0bd     PUSH       0x28
    //         0043d0bf     PUSH       EAX
    //         0043d0c0     PUSH       0x208
    //         0043d0c5     ADD        EBP,-0x20
    //         0043d0c8     PUSH       0x0
    //         0043d0ca     PUSH       -0x1
    //         0043d0cc     PUSH       EBP
    //         0043d0cd     PUSH       ESI
    //         0043d0ce     MOV        this,ESI
    //         0043d0d0     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d0d5     TEST       EAX,EAX
    //         0043d0d7     JZ         LAB_0043d694
    //                              dlg_dip.cpp:261 (48)
    //         0043d0dd     MOV        EDX,dword ptr [ESP + 0x14]
    //         0043d0e1     MOV        this,dword ptr [ESP + 0x10]
    //         0043d0e5     PUSH       0x0
    //         0043d0e7     PUSH       0x0=>DAT_fffffff8
    //         0043d0e9     PUSH       offset DAT_fffffff4
    //         0043d0eb     PUSH       offset DAT_fffffff0
    //         0043d0ed     PUSH       0x28
    //         0043d0ef     PUSH       EDX
    //         0043d0f0     PUSH       0x230
    //         0043d0f5     LEA        EDI,[ECX + this->_padding_]
    //         0043d0f8     PUSH       0x0
    //         0043d0fa     PUSH       -0x1
    //         0043d0fc     PUSH       EDI
    //         0043d0fd     PUSH       ESI
    //         0043d0fe     MOV        this,ESI
    //         0043d100     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d105     TEST       EAX,EAX
    //         0043d107     JZ         LAB_0043d694
    //                              dlg_dip.cpp:265 (22)
    //         0043d10d     MOV        EAX,dword ptr [ESI + 0x608]
    //         0043d113     MOV        this,dword ptr [ESP + 0x10]
    //         0043d117     PUSH       0x0
    //         0043d119     PUSH       EAX=>DAT_fffffff8
    //         0043d11a     MOV        this,dword ptr [this->_padding_]
    //         0043d11c     PUSH       0x0=>DAT_fffffff4
    //         0043d11e     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              dlg_dip.cpp:266 (18)
    //         0043d123     MOV        EDX,dword ptr [ESI + 0x608]
    //         0043d129     MOV        this,dword ptr [EBX]
    //         0043d12b     PUSH       0x2
    //         0043d12d     PUSH       EDX=>DAT_fffffff8
    //         0043d12e     PUSH       0x0=>DAT_fffffff4
    //         0043d130     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              dlg_dip.cpp:267 (19)
    //         0043d135     MOV        EAX,dword ptr [ESI + 0x608]
    //         0043d13b     MOV        this,dword ptr [EBP]
    //         0043d13e     PUSH       0x3
    //         0043d140     PUSH       EAX=>DAT_fffffff8
    //         0043d141     PUSH       0x0=>DAT_fffffff4
    //         0043d143     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              dlg_dip.cpp:268 (18)
    //         0043d148     MOV        this,dword ptr [ESI + 0x608]
    //         0043d14e     PUSH       0x1
    //         0043d150     PUSH       this=>DAT_fffffff8
    //         0043d151     MOV        this,dword ptr [EDI]
    //         0043d153     PUSH       0x0=>DAT_fffffff4
    //         0043d155     CALL       TButtonPanel::set_picture                        void set_picture(TButtonPanel * this, short p
    //                              dlg_dip.cpp:270 (13)
    //         0043d15a     MOV        EDX,dword ptr [ESP + 0x10]
    //         0043d15e     PUSH       0x4
    //         0043d160     MOV        this,dword ptr [EDX]
    //         0043d162     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              dlg_dip.cpp:271 (9)
    //         0043d167     MOV        this,dword ptr [EBX]
    //         0043d169     PUSH       0x4
    //         0043d16b     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              dlg_dip.cpp:272 (10)
    //         0043d170     MOV        this,dword ptr [EBP]
    //         0043d173     PUSH       0x4
    //         0043d175     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              dlg_dip.cpp:273 (9)
    //         0043d17a     MOV        this,dword ptr [EDI]
    //         0043d17c     PUSH       0x4
    //         0043d17e     CALL       TButtonPanel::setDrawType                        void setDrawType(TButtonPanel * this, DrawTyp
    //                              dlg_dip.cpp:275 (18)
    //         0043d183     MOV        EAX,dword ptr [ESP + 0x10]
    //         0043d187     PUSH       -0x1
    //                              language.dll match for 0x7687: "Click to tribute this player 
    //         0043d189     PUSH       offset DAT_fffffff8
    //         0043d18e     MOV        this,dword ptr [EAX]
    //         0043d190     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:276 (14)
    //         0043d195     MOV        this,dword ptr [EBX]
    //         0043d197     PUSH       -0x1
    //                              language.dll match for 0x7688: "Click to tribute this player 
    //         0043d199     PUSH       offset DAT_fffffff8
    //         0043d19e     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:277 (15)
    //         0043d1a3     MOV        this,dword ptr [EBP]
    //         0043d1a6     PUSH       -0x1
    //                              language.dll match for 0x7689: "Click to tribute this player 
    //         0043d1a8     PUSH       offset DAT_fffffff8
    //         0043d1ad     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:278 (85)
    //         0043d1b2     MOV        this,dword ptr [EDI]
    //         0043d1b4     PUSH       -0x1
    //                              language.dll match for 0x768a: "Click to tribute this player 
    //         0043d1b6     PUSH       offset DAT_fffffff8
    //         0043d1bb     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //         0043d1c0     MOV        EBP,dword ptr [ESP + 0x24]
    //                               LAB_0043d1c4                                                 XREF[1]:     0043d058(j)  
    //         0043d1c4     MOV        this,dword ptr [ESP + 0x30]
    //         0043d1c8     MOV        EAX,dword ptr [ESP + 0x18]
    //         0043d1cc     MOV        EBX,dword ptr [ESP + 0x10]
    //         0043d1d0     ADD        this,0x3
    //         0043d1d3     MOV        dword ptr [ESP + 0x30],this
    //         0043d1d7     MOV        this,dword ptr [ESP + 0x1c]
    //         0043d1db     ADD        EBP,0xc
    //         0043d1de     INC        EAX
    //         0043d1df     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         0043d1e3     MOV        dword ptr [ESP + 0x24],EBP
    //         0043d1e7     MOV        EBP,dword ptr [ESP + 0x14]
    //         0043d1eb     MOV        dword ptr [ESP + 0x18],EAX
    //         0043d1ef     ADD        EBP,0x1e
    //         0043d1f2     ADD        EBX,0x4
    //         0043d1f5     DEC        EAX
    //         0043d1f6     DEC        EDX
    //         0043d1f7     MOV        dword ptr [ESP + 0x14],EBP
    //         0043d1fb     CMP        EAX,EDX
    //         0043d1fd     MOV        dword ptr [ESP + 0x10],EBX
    //         0043d201     JL         LAB_0043cd52
    //                              dlg_dip.cpp:170 (2)
    //         0043d207     XOR        EBX,EBX
    //                               LAB_0043d209                                                 XREF[1]:     0043cd14(j)  
    //                              dlg_dip.cpp:287 (39)
    //         0043d209     PUSH       EBX
    //         0043d20a     PUSH       EBX=>DAT_fffffff8
    //         0043d20b     PUSH       offset DAT_fffffff4
    //         0043d20d     PUSH       offset DAT_fffffff0
    //         0043d20f     PUSH       0x147
    //         0043d214     LEA        EDI,[ESI + 0x5f4]
    //         0043d21a     PUSH       0x11a
    //         0043d21f     PUSH       EDI
    //         0043d220     PUSH       ESI
    //         0043d221     MOV        this,ESI
    //         0043d223     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
    //         0043d228     TEST       EAX,EAX
    //         0043d22a     JZ         LAB_0043d694
    //                              dlg_dip.cpp:288 (36)
    //         0043d230     MOV        EAX,dword ptr [EDI]
    //         0043d232     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d238     MOV        EBP,dword ptr [EAX]
    //         0043d23a     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d23f     MOV        this,EAX
    //         0043d241     CALL       RGE_Player::get_allied_victory                   uchar get_allied_victory(RGE_Player * this)
    //         0043d246     XOR        this,this
    //         0043d249     MOV        this,AL
    //         0043d24b     PUSH       this
    //         0043d24c     MOV        this,dword ptr [EDI]
    //         0043d24e     CALL       dword ptr [EBP + 0xe0]
    //                              dlg_dip.cpp:289 (14)
    //         0043d254     MOV        this,dword ptr [EDI]
    //         0043d256     PUSH       -0x1
    //                              language.dll match for 0x768c: "If there is a check in the bo
    //         0043d258     PUSH       offset DAT_fffffff8
    //         0043d25d     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:290 (19)
    //         0043d262     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0043d268     MOV        EBP,0x5
    //         0043d26d     CMP        dword ptr [EDX + 0x1b0],EBP
    //         0043d273     JNZ        LAB_0043d27e
    //                              dlg_dip.cpp:291 (9)
    //         0043d275     MOV        this,dword ptr [EDI]
    //         0043d277     PUSH       0x1
    //         0043d279     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0043d27e                                                 XREF[1]:     0043d273(j)  
    //                              dlg_dip.cpp:294 (13)
    //         0043d27e     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043d283     CMP        dword ptr [EAX + 0x1b0],EBP
    //         0043d289     JZ         LAB_0043d306
    //                              dlg_dip.cpp:295 (46)
    //         0043d28b     PUSH       EBX
    //         0043d28c     PUSH       EBX=>DAT_fffffff8
    //         0043d28d     PUSH       EBX=>DAT_fffffff4
    //         0043d28e     PUSH       offset DAT_fffffff0
    //         0043d290     PUSH       0xbe
    //         0043d295     PUSH       0x16f
    //         0043d29a     PUSH       0xa
    //         0043d29c     PUSH       EBX
    //         0043d29d     LEA        EDI,[ESI + 0x5f8]
    //                              language.dll match for 0xfa1: "OK"
    //         0043d2a3     PUSH       0xfa1
    //         0043d2a8     PUSH       EDI
    //         0043d2a9     PUSH       ESI
    //         0043d2aa     MOV        this,ESI
    //         0043d2ac     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d2b1     TEST       EAX,EAX
    //         0043d2b3     JZ         LAB_0043d694
    //                              dlg_dip.cpp:296 (14)
    //         0043d2b9     MOV        this,dword ptr [EDI]
    //         0043d2bb     PUSH       -0x1
    //         0043d2bd     PUSH       offset DAT_fffffff8
    //         0043d2c2     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:298 (49)
    //         0043d2c7     PUSH       EBX
    //         0043d2c8     PUSH       EBX=>DAT_fffffff8
    //         0043d2c9     PUSH       EBX=>DAT_fffffff4
    //         0043d2ca     PUSH       offset DAT_fffffff0
    //         0043d2cc     PUSH       0xbe
    //         0043d2d1     PUSH       0x16f
    //         0043d2d6     PUSH       0xd7
    //         0043d2db     PUSH       EBX
    //         0043d2dc     LEA        EDI,[ESI + 0x5fc]
    //                              language.dll match for 0x2683: "Clear Tributes"
    //         0043d2e2     PUSH       0x2683
    //         0043d2e7     PUSH       EDI
    //         0043d2e8     PUSH       ESI
    //         0043d2e9     MOV        this,ESI
    //         0043d2eb     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d2f0     TEST       EAX,EAX
    //         0043d2f2     JZ         LAB_0043d694
    //                              dlg_dip.cpp:299 (14)
    //         0043d2f8     MOV        this,dword ptr [EDI]
    //         0043d2fa     PUSH       -0x1
    //                              language.dll match for 0x768b: "Click to clear all tributes b
    //         0043d2fc     PUSH       offset DAT_fffffff8
    //         0043d301     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                               LAB_0043d306                                                 XREF[1]:     0043d289(j)  
    //                              dlg_dip.cpp:302 (49)
    //         0043d306     PUSH       EBX
    //         0043d307     PUSH       EBX=>DAT_fffffff8
    //         0043d308     PUSH       EBX=>DAT_fffffff4
    //         0043d309     PUSH       offset DAT_fffffff0
    //         0043d30b     PUSH       0xbe
    //         0043d310     PUSH       0x16f
    //         0043d315     PUSH       0x1a4
    //         0043d31a     PUSH       EBX
    //         0043d31b     LEA        EDI,[ESI + 0x600]
    //                              language.dll match for 0xfa2: "Cancel"
    //         0043d321     PUSH       0xfa2
    //         0043d326     PUSH       EDI
    //         0043d327     PUSH       ESI
    //         0043d328     MOV        this,ESI
    //         0043d32a     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d32f     TEST       EAX,EAX
    //         0043d331     JZ         LAB_0043d694
    //                              dlg_dip.cpp:303 (14)
    //         0043d337     MOV        this,dword ptr [EDI]
    //         0043d339     PUSH       -0x1
    //         0043d33b     PUSH       offset DAT_fffffff8
    //         0043d340     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              dlg_dip.cpp:304 (2)
    //         0043d345     MOV        EDI,dword ptr [EDI]
    //                              dlg_dip.cpp:307 (62)
    //         0043d347     PUSH       EBX
    //         0043d348     PUSH       EBX=>DAT_fffffff8
    //         0043d349     PUSH       EBX=>DAT_fffffff4
    //         0043d34a     PUSH       offset DAT_fffffff0
    //         0043d34c     PUSH       0x1e
    //         0043d34e     PUSH       0x147
    //         0043d353     PUSH       0x1f4
    //         0043d358     PUSH       EBX
    //         0043d359     LEA        EAX,[ESI + 0x604]
    //                              language.dll match for 0xfa9: "?"
    //         0043d35f     PUSH       0xfa9
    //         0043d364     PUSH       EAX
    //         0043d365     PUSH       ESI
    //         0043d366     MOV        this,ESI
    //         0043d368     MOV        dword ptr [EDI + 0x298],0x1b
    //         0043d372     MOV        dword ptr [EDI + 0x29c],EBX
    //         0043d378     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0043d37d     TEST       EAX,EAX
    //         0043d37f     JZ         LAB_0043d694
    //                              dlg_dip.cpp:310 (23)
    //         0043d385     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d38b     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d390     MOV        this,dword ptr [EAX + 0x50]
    //         0043d393     FLD        float ptr [ECX + this->_padding_]
    //         0043d396     FSUB       float ptr [ESI + 0x614]
    //                              dlg_dip.cpp:311 (21)
    //         0043d39c     CALL       __ftol                                           undefined __ftol()
    //         0043d3a1     PUSH       EAX
    //         0043d3a2     LEA        EDX,[ESP + 0x48]
    //         0043d3a6     PUSH       s_%ld                                            = "%ld"
    //         0043d3ab     PUSH       EDX=>DAT_fffffff4
    //         0043d3ac     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:312 (63)
    //         0043d3b1     MOV        EAX,dword ptr [ESI + 0x6b0]
    //         0043d3b7     ADD        ESP,0xc
    //         0043d3ba     LEA        EDX,[ESP + 0x44]
    //         0043d3be     LEA        EAX,[EAX + EAX*0x2]
    //         0043d3c1     PUSH       EBX
    //         0043d3c2     PUSH       offset DAT_fffffff8
    //         0043d3c4     PUSH       EBX=>DAT_fffffff4
    //         0043d3c5     LEA        EAX,[EAX + EAX*0x4]
    //         0043d3c8     PUSH       offset DAT_fffffff0
    //         0043d3ca     PUSH       0x1e
    //         0043d3cc     PUSH       0x28
    //         0043d3ce     LEA        this,[EAX + EAX*0x1 + 0x50]
    //         0043d3d2     LEA        EAX,[ESI + 0x628]
    //         0043d3d8     PUSH       this
    //         0043d3d9     PUSH       0x1b8
    //         0043d3de     PUSH       EDX
    //         0043d3df     PUSH       EAX
    //         0043d3e0     PUSH       ESI
    //         0043d3e1     MOV        this,ESI
    //         0043d3e3     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043d3e8     TEST       EAX,EAX
    //         0043d3ea     JZ         LAB_0043d694
    //                              dlg_dip.cpp:314 (22)
    //         0043d3f0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d3f6     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d3fb     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043d3fe     FLD        float ptr [EAX]
    //         0043d400     FSUB       float ptr [ESI + 0x610]
    //                              dlg_dip.cpp:315 (21)
    //         0043d406     CALL       __ftol                                           undefined __ftol()
    //         0043d40b     PUSH       EAX
    //         0043d40c     LEA        this,[ESP + 0x48]
    //         0043d410     PUSH       s_%ld                                            = "%ld"
    //         0043d415     PUSH       this=>DAT_fffffff4
    //         0043d416     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:316 (63)
    //         0043d41b     MOV        EAX,dword ptr [ESI + 0x6b0]
    //         0043d421     ADD        ESP,0xc
    //         0043d424     LEA        this,[ESP + 0x44]
    //         0043d428     LEA        EAX,[EAX + EAX*0x2]
    //         0043d42b     PUSH       EBX
    //         0043d42c     PUSH       offset DAT_fffffff8
    //         0043d42e     PUSH       EBX=>DAT_fffffff4
    //         0043d42f     LEA        EDX,[EAX + EAX*0x4]
    //         0043d432     PUSH       offset DAT_fffffff0
    //         0043d434     PUSH       0x1e
    //         0043d436     PUSH       0x28
    //         0043d438     LEA        EAX,[EDX + EDX*0x1 + 0x50]
    //         0043d43c     PUSH       EAX
    //         0043d43d     PUSH       0x1e0
    //         0043d442     LEA        EAX,[ESI + 0x620]
    //         0043d448     PUSH       this
    //         0043d449     PUSH       EAX
    //         0043d44a     PUSH       ESI
    //         0043d44b     MOV        this,ESI
    //         0043d44d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043d452     TEST       EAX,EAX
    //         0043d454     JZ         LAB_0043d694
    //                              dlg_dip.cpp:318 (23)
    //         0043d45a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d460     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d465     MOV        EDX,dword ptr [EAX + 0x50]
    //         0043d468     FLD        float ptr [EDX + 0xc]
    //         0043d46b     FSUB       float ptr [ESI + 0x618]
    //                              dlg_dip.cpp:319 (21)
    //         0043d471     CALL       __ftol                                           undefined __ftol()
    //         0043d476     PUSH       EAX
    //         0043d477     LEA        EAX,[ESP + 0x48]
    //         0043d47b     PUSH       s_%ld                                            = "%ld"
    //         0043d480     PUSH       EAX=>DAT_fffffff4
    //         0043d481     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:320 (63)
    //         0043d486     MOV        EAX,dword ptr [ESI + 0x6b0]
    //         0043d48c     ADD        ESP,0xc
    //         0043d48f     LEA        EBP,[ESI + 0x624]
    //         0043d495     LEA        EAX,[EAX + EAX*0x2]
    //         0043d498     PUSH       EBX
    //         0043d499     PUSH       offset DAT_fffffff8
    //         0043d49b     PUSH       EBX=>DAT_fffffff4
    //         0043d49c     LEA        this,[EAX + EAX*0x4]
    //         0043d49f     PUSH       offset DAT_fffffff0
    //         0043d4a1     PUSH       0x1e
    //         0043d4a3     PUSH       0x28
    //         0043d4a5     LEA        EDX,[ECX + ECX*0x1 + 0x50]
    //         0043d4a9     LEA        EAX,[ESP + 0x5c]
    //         0043d4ad     PUSH       EDX
    //         0043d4ae     PUSH       0x208
    //         0043d4b3     PUSH       EAX
    //         0043d4b4     PUSH       EBP
    //         0043d4b5     PUSH       ESI
    //         0043d4b6     MOV        this,ESI
    //         0043d4b8     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043d4bd     TEST       EAX,EAX
    //         0043d4bf     JZ         LAB_0043d694
    //                              dlg_dip.cpp:322 (23)
    //         0043d4c5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d4cb     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d4d0     MOV        this,dword ptr [EAX + 0x50]
    //         0043d4d3     FLD        float ptr [ECX + this->_padding_]
    //         0043d4d6     FSUB       float ptr [ESI + 0x61c]
    //                              dlg_dip.cpp:323 (21)
    //         0043d4dc     CALL       __ftol                                           undefined __ftol()
    //         0043d4e1     PUSH       EAX
    //         0043d4e2     LEA        EDX,[ESP + 0x48]
    //         0043d4e6     PUSH       s_%ld                                            = "%ld"
    //         0043d4eb     PUSH       EDX=>DAT_fffffff4
    //         0043d4ec     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:324 (63)
    //         0043d4f1     MOV        EAX,dword ptr [ESI + 0x6b0]
    //         0043d4f7     ADD        ESP,0xc
    //         0043d4fa     LEA        EDX,[ESP + 0x44]
    //         0043d4fe     LEA        EDI,[ESI + 0x62c]
    //         0043d504     LEA        EAX,[EAX + EAX*0x2]
    //         0043d507     PUSH       EBX
    //         0043d508     PUSH       offset DAT_fffffff8
    //         0043d50a     PUSH       EBX=>DAT_fffffff4
    //         0043d50b     LEA        EAX,[EAX + EAX*0x4]
    //         0043d50e     PUSH       offset DAT_fffffff0
    //         0043d510     PUSH       0x1e
    //         0043d512     PUSH       0x28
    //         0043d514     LEA        this,[EAX + EAX*0x1 + 0x50]
    //         0043d518     PUSH       this
    //         0043d519     PUSH       0x230
    //         0043d51e     PUSH       EDX
    //         0043d51f     PUSH       EDI
    //         0043d520     PUSH       ESI
    //         0043d521     MOV        this,ESI
    //         0043d523     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0043d528     TEST       EAX,EAX
    //         0043d52a     JZ         LAB_0043d694
    //                              dlg_dip.cpp:327 (40)
    //         0043d530     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d536     PUSH       EBX
    //         0043d537     PUSH       offset DAT_fffffff8
    //         0043d539     PUSH       offset DAT_fffffff4
    //         0043d53b     PUSH       offset DAT_fffffff0
    //         0043d540     PUSH       0xbf800000
    //         0043d545     PUSH       0x54
    //         0043d547     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d54c     MOV        this,dword ptr [EAX + 0x28]
    //         0043d54f     CALL       RGE_Object_List::find_by_master_id               RGE_Static_Object * find_by_master_id(RGE_Obj
    //         0043d554     TEST       EAX,EAX
    //         0043d556     JZ         LAB_0043d5a7
    //                              dlg_dip.cpp:330 (22)
    //         0043d558     MOV        this,dword ptr [ESI + 0x510]
    //         0043d55e     PUSH       EBX
    //         0043d55f     MOV        dword ptr [ESI + 0x6b4],0x1
    //         0043d569     MOV        EAX,dword ptr [this->_padding_]
    //         0043d56b     CALL       dword ptr [EAX + 0x14]
    //                              dlg_dip.cpp:331 (13)
    //         0043d56e     MOV        this,dword ptr [ESI + 0x4a8]
    //         0043d574     PUSH       0x1
    //         0043d576     MOV        EDX,dword ptr [this->_padding_]
    //         0043d578     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:332 (13)
    //         0043d57b     MOV        this,dword ptr [ESI + 0x628]
    //         0043d581     PUSH       0x1
    //         0043d583     MOV        EAX,dword ptr [this->_padding_]
    //         0043d585     CALL       dword ptr [EAX + 0x14]
    //                              dlg_dip.cpp:333 (13)
    //         0043d588     MOV        this,dword ptr [ESI + 0x620]
    //         0043d58e     PUSH       0x1
    //         0043d590     MOV        EDX,dword ptr [this->_padding_]
    //         0043d592     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:334 (10)
    //         0043d595     MOV        this,dword ptr [EBP]
    //         0043d598     PUSH       0x1
    //         0043d59a     MOV        EAX,dword ptr [this->_padding_]
    //         0043d59c     CALL       dword ptr [EAX + 0x14]
    //                              dlg_dip.cpp:335 (6)
    //         0043d59f     MOV        this,dword ptr [EDI]
    //         0043d5a1     PUSH       0x1
    //         0043d5a3     MOV        EDX,dword ptr [this->_padding_]
    //                              dlg_dip.cpp:337 (2)
    //         0043d5a5     JMP        LAB_0043d5ec
    //                               LAB_0043d5a7                                                 XREF[1]:     0043d556(j)  
    //                              dlg_dip.cpp:340 (19)
    //         0043d5a7     MOV        this,dword ptr [ESI + 0x510]
    //         0043d5ad     PUSH       0x1
    //         0043d5af     MOV        dword ptr [ESI + 0x6b4],EBX
    //         0043d5b5     MOV        EAX,dword ptr [this->_padding_]
    //         0043d5b7     CALL       dword ptr [EAX + 0x14]
    //                              dlg_dip.cpp:341 (12)
    //         0043d5ba     MOV        this,dword ptr [ESI + 0x4a8]
    //         0043d5c0     PUSH       EBX
    //         0043d5c1     MOV        EDX,dword ptr [this->_padding_]
    //         0043d5c3     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:342 (12)
    //         0043d5c6     MOV        this,dword ptr [ESI + 0x628]
    //         0043d5cc     PUSH       EBX
    //         0043d5cd     MOV        EAX,dword ptr [this->_padding_]
    //         0043d5cf     CALL       dword ptr [EAX + 0x14]
    //                              dlg_dip.cpp:343 (12)
    //         0043d5d2     MOV        this,dword ptr [ESI + 0x620]
    //         0043d5d8     PUSH       EBX
    //         0043d5d9     MOV        EDX,dword ptr [this->_padding_]
    //         0043d5db     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:344 (9)
    //         0043d5de     MOV        this,dword ptr [EBP]
    //         0043d5e1     PUSH       EBX
    //         0043d5e2     MOV        EAX,dword ptr [this->_padding_]
    //         0043d5e4     CALL       dword ptr [EAX + 0x14]
    //                              dlg_dip.cpp:345 (8)
    //         0043d5e7     MOV        this,dword ptr [EDI]
    //         0043d5e9     PUSH       EBX
    //         0043d5ea     MOV        EDX,dword ptr [this->_padding_]
    //                               LAB_0043d5ec                                                 XREF[1]:     0043d5a5(j)  
    //         0043d5ec     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:348 (30)
    //         0043d5ef     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d5f5     PUSH       0x1e
    //         0043d5f7     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d5fc     MOV        this,dword ptr [EAX + 0x220]
    //         0043d602     CALL       TRIBE_Player_Tech::get_tech_state                short get_tech_state(TRIBE_Player_Tech * this
    //         0043d607     CMP        AX,0x3
    //         0043d60b     JNZ        LAB_0043d619
    //                              dlg_dip.cpp:349 (12)
    //         0043d60d     MOV        this,dword ptr [ESI + 0x4a8]
    //         0043d613     PUSH       EBX
    //         0043d614     MOV        EAX,dword ptr [this->_padding_]
    //         0043d616     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0043d619                                                 XREF[1]:     0043d60b(j)  
    //                              dlg_dip.cpp:353 (7)
    //         0043d619     MOV        this,ESI
    //         0043d61b     CALL       TribeDiplomacyDialog::check_gold                 int check_gold(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:354 (7)
    //         0043d620     MOV        this,ESI
    //         0043d622     CALL       TribeDiplomacyDialog::check_wood                 int check_wood(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:355 (7)
    //         0043d627     MOV        this,ESI
    //         0043d629     CALL       TribeDiplomacyDialog::check_food                 int check_food(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:356 (7)
    //         0043d62e     MOV        this,ESI
    //         0043d630     CALL       TribeDiplomacyDialog::check_stone                int check_stone(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:359 (14)
    //         0043d635     MOV        this,dword ptr [ESI + 0x5f8]
    //         0043d63b     PUSH       this
    //         0043d63c     MOV        this,ESI
    //         0043d63e     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              dlg_dip.cpp:362 (10)
    //         0043d643     MOV        EAX,dword ptr [ESI + 0x5f8]
    //         0043d649     CMP        EAX,EBX
    //         0043d64b     JZ         LAB_0043d65c
    //                              dlg_dip.cpp:363 (15)
    //         0043d64d     MOV        dword ptr [ESP + 0xa8],EAX
    //         0043d654     MOV        dword ptr [ESP + 0x28],0x1
    //                               LAB_0043d65c                                                 XREF[1]:     0043d64b(j)  
    //                              dlg_dip.cpp:364 (6)
    //         0043d65c     MOV        this,dword ptr [ESI + 0x5fc]
    //                              dlg_dip.cpp:365 (16)
    //         0043d662     MOV        EAX,dword ptr [ESP + 0x28]
    //         0043d666     CMP        this,EBX
    //         0043d668     JZ         LAB_0043d672
    //         0043d66a     MOV        dword ptr [ESP + EAX*0x4 + 0xa8],this
    //         0043d671     INC        EAX
    //                               LAB_0043d672                                                 XREF[1]:     0043d668(j)  
    //                              dlg_dip.cpp:366 (10)
    //         0043d672     MOV        this,dword ptr [ESI + 0x600]
    //         0043d678     CMP        this,EBX
    //         0043d67a     JZ         LAB_0043d684
    //                              dlg_dip.cpp:367 (8)
    //         0043d67c     MOV        dword ptr [ESP + EAX*0x4 + 0xa8],this
    //         0043d683     INC        EAX
    //                               LAB_0043d684                                                 XREF[1]:     0043d67a(j)  
    //                              dlg_dip.cpp:368 (16)
    //         0043d684     LEA        EDX,[ESP + 0xa8]
    //         0043d68b     PUSH       EAX
    //         0043d68c     PUSH       EDX=>DAT_fffffff8
    //         0043d68d     MOV        this,ESI
    //         0043d68f     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_0043d694                                                 XREF[30]:    0043ca68(j), 0043cab4(j), 
    //                                                                                                         0043cb00(j), 0043cb3b(j), 
    //                                                                                                         0043cb67(j), 0043cb94(j), 
    //                                                                                                         0043cbc1(j), 0043cbee(j), 
    //                                                                                                         0043cc1b(j), 0043cc48(j), 
    //                                                                                                         0043ccb2(j), 0043cce5(j), 
    //                                                                                                         0043cea5(j), 0043cef7(j), 
    //                                                                                                         0043cf38(j), 0043cf70(j), 
    //                                                                                                         0043cfa1(j), 0043d085(j), 
    //                                                                                                         0043d0ad(j), 0043d0d7(j), [more]
    //                              dlg_dip.cpp:369 (29)
    //         0043d694     MOV        this,dword ptr [ESP + local_c]
    //         0043d69b     MOV        EAX,ESI
    //         0043d69d     POP        EDI
    //         0043d69e     POP        ESI
    //         0043d69f     POP        EBP
    //         0043d6a0     MOV        dword ptr FS:[0x0],this
    //         0043d6a7     POP        EBX
    //         0043d6a8     ADD        ESP,0x130
    //         0043d6ae     RET        0x4
    //         0043d6b1     ??         90h
    //         0043d6b2     NOP
    //         0043d6b3     NOP
    //         0043d6b4     NOP
    //         0043d6b5     NOP
    //         0043d6b6     NOP
    //         0043d6b7     NOP
    //         0043d6b8     NOP
    //         0043d6b9     NOP
    //         0043d6ba     NOP
    //         0043d6bb     NOP
    //         0043d6bc     NOP
    //         0043d6bd     NOP
    //         0043d6be     NOP
    //         0043d6bf     NOP
}

TribeDiplomacyDialog::~TribeDiplomacyDialog() {
    /* TODO: Stub */
    //                              void __thiscall ~TribeDiplomacyDialog(TribeDiplomacyDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043d705(W)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0043d6fb(W)  
    //                               ??1TribeDiplomacyDialog@@UAE@XZ                              XREF[1]:     `scalar_deleting_destructor':0043d
    //                               TribeDiplomacyDialog::~TribeDiplomacyDialog
    //                              dlg_dip.cpp:374 (56)
    //         0043d6e0     PUSH       -0x1
    //         0043d6e2     PUSH       FUN_0055d068
    //         0043d6e7     MOV        EAX,FS:[0x0]
    //         0043d6ed     PUSH       EAX
    //         0043d6ee     MOV        dword ptr FS:[0x0],ESP
    //         0043d6f5     PUSH       this
    //         0043d6f6     PUSH       EBX
    //         0043d6f7     MOV        EBX,this
    //         0043d6f9     PUSH       ESI
    //         0043d6fa     PUSH       EDI
    //         0043d6fb     MOV        dword ptr [ESP + local_10],EBX
    //         0043d6ff     MOV        dword ptr [EBX],TribeDiplomacyDialog::`vftable'  = 0043d6c0
    //         0043d705     MOV        dword ptr [ESP + local_4],0x0
    //         0043d70d     LEA        ESI,[EBX + 0x4d0]
    //         0043d713     MOV        EDI,0x8
    //                               LAB_0043d718                                                 XREF[1]:     0043d789(j)  
    //                              dlg_dip.cpp:376 (7)
    //         0043d718     MOV        this,dword ptr [ESI + -0x40]
    //         0043d71b     TEST       this,this
    //         0043d71d     JZ         LAB_0043d725
    //                              dlg_dip.cpp:377 (6)
    //         0043d71f     MOV        EAX,dword ptr [this->_padding_]
    //         0043d721     PUSH       0x1
    //         0043d723     CALL       dword ptr [EAX]
    //                               LAB_0043d725                                                 XREF[1]:     0043d71d(j)  
    //                              dlg_dip.cpp:378 (6)
    //         0043d725     MOV        this,dword ptr [ESI]
    //         0043d727     TEST       this,this
    //         0043d729     JZ         LAB_0043d731
    //                              dlg_dip.cpp:379 (6)
    //         0043d72b     MOV        EDX,dword ptr [this->_padding_]
    //         0043d72d     PUSH       0x1
    //         0043d72f     CALL       dword ptr [EDX]
    //                               LAB_0043d731                                                 XREF[1]:     0043d729(j)  
    //                              dlg_dip.cpp:380 (7)
    //         0043d731     MOV        this,dword ptr [ESI + -0x20]
    //         0043d734     TEST       this,this
    //         0043d736     JZ         LAB_0043d73e
    //                              dlg_dip.cpp:381 (6)
    //         0043d738     MOV        EAX,dword ptr [this->_padding_]
    //         0043d73a     PUSH       0x1
    //         0043d73c     CALL       dword ptr [EAX]
    //                               LAB_0043d73e                                                 XREF[1]:     0043d736(j)  
    //                              dlg_dip.cpp:382 (7)
    //         0043d73e     MOV        this,dword ptr [ESI + 0x20]
    //         0043d741     TEST       this,this
    //         0043d743     JZ         LAB_0043d74b
    //                              dlg_dip.cpp:383 (6)
    //         0043d745     MOV        EDX,dword ptr [this->_padding_]
    //         0043d747     PUSH       0x1
    //         0043d749     CALL       dword ptr [EDX]
    //                               LAB_0043d74b                                                 XREF[1]:     0043d743(j)  
    //                              dlg_dip.cpp:384 (7)
    //         0043d74b     MOV        this,dword ptr [ESI + 0x64]
    //         0043d74e     TEST       this,this
    //         0043d750     JZ         LAB_0043d758
    //                              dlg_dip.cpp:385 (6)
    //         0043d752     MOV        EAX,dword ptr [this->_padding_]
    //         0043d754     PUSH       0x1
    //         0043d756     CALL       dword ptr [EAX]
    //                               LAB_0043d758                                                 XREF[1]:     0043d750(j)  
    //                              dlg_dip.cpp:386 (10)
    //         0043d758     MOV        this,dword ptr [ESI + 0x84]
    //         0043d75e     TEST       this,this
    //         0043d760     JZ         LAB_0043d768
    //                              dlg_dip.cpp:387 (6)
    //         0043d762     MOV        EDX,dword ptr [this->_padding_]
    //         0043d764     PUSH       0x1
    //         0043d766     CALL       dword ptr [EDX]
    //                               LAB_0043d768                                                 XREF[1]:     0043d760(j)  
    //                              dlg_dip.cpp:388 (7)
    //         0043d768     MOV        this,dword ptr [ESI + 0x44]
    //         0043d76b     TEST       this,this
    //         0043d76d     JZ         LAB_0043d775
    //                              dlg_dip.cpp:389 (6)
    //         0043d76f     MOV        EAX,dword ptr [this->_padding_]
    //         0043d771     PUSH       0x1
    //         0043d773     CALL       dword ptr [EAX]
    //                               LAB_0043d775                                                 XREF[1]:     0043d76d(j)  
    //                              dlg_dip.cpp:390 (10)
    //         0043d775     MOV        this,dword ptr [ESI + 0xa4]
    //         0043d77b     TEST       this,this
    //         0043d77d     JZ         LAB_0043d785
    //                              dlg_dip.cpp:391 (12)
    //         0043d77f     MOV        EDX,dword ptr [this->_padding_]
    //         0043d781     PUSH       0x1
    //         0043d783     CALL       dword ptr [EDX]
    //                               LAB_0043d785                                                 XREF[1]:     0043d77d(j)  
    //         0043d785     ADD        ESI,0x4
    //         0043d788     DEC        EDI
    //         0043d789     JNZ        LAB_0043d718
    //                              dlg_dip.cpp:428 (274)
    //         0043d78b     LEA        ESI,[EBX + 0x594]
    //         0043d791     MOV        EDI,0x18
    //                               LAB_0043d796                                                 XREF[1]:     0043d7a6(j)  
    //         0043d796     MOV        this,dword ptr [ESI]
    //         0043d798     TEST       this,this
    //         0043d79a     JZ         LAB_0043d7a2
    //         0043d79c     MOV        EAX,dword ptr [this->_padding_]
    //         0043d79e     PUSH       0x1
    //         0043d7a0     CALL       dword ptr [EAX]
    //                               LAB_0043d7a2                                                 XREF[1]:     0043d79a(j)  
    //         0043d7a2     ADD        ESI,0x4
    //         0043d7a5     DEC        EDI
    //         0043d7a6     JNZ        LAB_0043d796
    //         0043d7a8     MOV        this,dword ptr [EBX + 0x5f4]
    //         0043d7ae     TEST       this,this
    //         0043d7b0     JZ         LAB_0043d7b8
    //         0043d7b2     MOV        EDX,dword ptr [this->_padding_]
    //         0043d7b4     PUSH       0x1
    //         0043d7b6     CALL       dword ptr [EDX]
    //                               LAB_0043d7b8                                                 XREF[1]:     0043d7b0(j)  
    //         0043d7b8     MOV        this,dword ptr [EBX + 0x5f8]
    //         0043d7be     TEST       this,this
    //         0043d7c0     JZ         LAB_0043d7c8
    //         0043d7c2     MOV        EAX,dword ptr [this->_padding_]
    //         0043d7c4     PUSH       0x1
    //         0043d7c6     CALL       dword ptr [EAX]
    //                               LAB_0043d7c8                                                 XREF[1]:     0043d7c0(j)  
    //         0043d7c8     MOV        this,dword ptr [EBX + 0x600]
    //         0043d7ce     TEST       this,this
    //         0043d7d0     JZ         LAB_0043d7d8
    //         0043d7d2     MOV        EDX,dword ptr [this->_padding_]
    //         0043d7d4     PUSH       0x1
    //         0043d7d6     CALL       dword ptr [EDX]
    //                               LAB_0043d7d8                                                 XREF[1]:     0043d7d0(j)  
    //         0043d7d8     MOV        this,dword ptr [EBX + 0x5fc]
    //         0043d7de     TEST       this,this
    //         0043d7e0     JZ         LAB_0043d7e8
    //         0043d7e2     MOV        EAX,dword ptr [this->_padding_]
    //         0043d7e4     PUSH       0x1
    //         0043d7e6     CALL       dword ptr [EAX]
    //                               LAB_0043d7e8                                                 XREF[1]:     0043d7e0(j)  
    //         0043d7e8     MOV        this,dword ptr [EBX + 0x604]
    //         0043d7ee     TEST       this,this
    //         0043d7f0     JZ         LAB_0043d7f8
    //         0043d7f2     MOV        EDX,dword ptr [this->_padding_]
    //         0043d7f4     PUSH       0x1
    //         0043d7f6     CALL       dword ptr [EDX]
    //                               LAB_0043d7f8                                                 XREF[1]:     0043d7f0(j)  
    //         0043d7f8     MOV        this,dword ptr [EBX + 0x620]
    //         0043d7fe     TEST       this,this
    //         0043d800     JZ         LAB_0043d808
    //         0043d802     MOV        EAX,dword ptr [this->_padding_]
    //         0043d804     PUSH       0x1
    //         0043d806     CALL       dword ptr [EAX]
    //                               LAB_0043d808                                                 XREF[1]:     0043d800(j)  
    //         0043d808     MOV        this,dword ptr [EBX + 0x624]
    //         0043d80e     TEST       this,this
    //         0043d810     JZ         LAB_0043d818
    //         0043d812     MOV        EDX,dword ptr [this->_padding_]
    //         0043d814     PUSH       0x1
    //         0043d816     CALL       dword ptr [EDX]
    //                               LAB_0043d818                                                 XREF[1]:     0043d810(j)  
    //         0043d818     MOV        this,dword ptr [EBX + 0x628]
    //         0043d81e     TEST       this,this
    //         0043d820     JZ         LAB_0043d828
    //         0043d822     MOV        EAX,dword ptr [this->_padding_]
    //         0043d824     PUSH       0x1
    //         0043d826     CALL       dword ptr [EAX]
    //                               LAB_0043d828                                                 XREF[1]:     0043d820(j)  
    //         0043d828     MOV        this,dword ptr [EBX + 0x62c]
    //         0043d82e     TEST       this,this
    //         0043d830     JZ         LAB_0043d838
    //         0043d832     MOV        EDX,dword ptr [this->_padding_]
    //         0043d834     PUSH       0x1
    //         0043d836     CALL       dword ptr [EDX]
    //                               LAB_0043d838                                                 XREF[1]:     0043d830(j)  
    //         0043d838     MOV        this,dword ptr [EBX + 0x510]
    //         0043d83e     TEST       this,this
    //         0043d840     JZ         LAB_0043d848
    //         0043d842     MOV        EAX,dword ptr [this->_padding_]
    //         0043d844     PUSH       0x1
    //         0043d846     CALL       dword ptr [EAX]
    //                               LAB_0043d848                                                 XREF[1]:     0043d840(j)  
    //         0043d848     MOV        ESI,dword ptr [EBX + 0x608]
    //         0043d84e     TEST       ESI,ESI
    //         0043d850     JZ         LAB_0043d862
    //         0043d852     MOV        this,ESI
    //         0043d854     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0043d859     PUSH       ESI
    //         0043d85a     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043d85f     ADD        ESP,0x4
    //                               LAB_0043d862                                                 XREF[1]:     0043d850(j)  
    //         0043d862     MOV        ESI,dword ptr [EBX + 0x60c]
    //         0043d868     TEST       ESI,ESI
    //         0043d86a     JZ         LAB_0043d87c
    //         0043d86c     MOV        this,ESI
    //         0043d86e     CALL       TShape::~TShape                                  void ~TShape(TShape * this)
    //         0043d873     PUSH       ESI
    //         0043d874     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         0043d879     ADD        ESP,0x4
    //                               LAB_0043d87c                                                 XREF[1]:     0043d86a(j)  
    //         0043d87c     MOV        this,EBX
    //         0043d87e     MOV        dword ptr [ESP + 0x18],0xffffffff
    //         0043d886     CALL       TDialogPanel::~TDialogPanel                      void ~TDialogPanel(TDialogPanel * this)
    //         0043d88b     MOV        this,dword ptr [ESP + 0x10]
    //         0043d88f     POP        EDI
    //         0043d890     POP        ESI
    //         0043d891     MOV        dword ptr FS:[0x0],this
    //         0043d898     POP        EBX
    //         0043d899     ADD        ESP,0x10
    //         0043d89c     RET
    //         0043d89d     ??         90h
    //         0043d89e     NOP
    //         0043d89f     NOP
    //                              * protected: virtual long __thiscall TribeDiplomacyDialog::action(class TPanel *,long,unsigned long,... *
    //                              long __thiscall action(TribeDiplomacyDialog * this, TPanel * param_1
    //              long              EAX:4          <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0043d8a8(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0043d8bb(R), 0043de4a(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0043de43(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0043de3c(R)  
    //              char[256]         Stack[-0x104   temp_str                  XREF[2,18]:  0043d8eb(W), 0043d9d7(R), 0043dcaa(*), 0043dcc2(*), 
    //                                                                                     0043df38(*), 0043df50(*), 0043dfda(*), 0043dff2(*), 
    //                                                                                     0043e0e7(*), 0043e0ff(*), 0043e189(*), 0043e1a1(*), 
    //                                                                                     0043e293(*), 0043e2ab(*), 0043e334(*), 0043e34c(*), 
    //                                                                                     0043e441(*), 0043e459(*), 0043e4e3(*), 0043e4fb(*)  
    //              TRIBE_Command *   Stack[-0x108   tc                        XREF[29]:    0043d961(W), 0043daff(R), 0043db13(W), 0043ddb6(W), 
    //                                                                                     0043dded(W), 0043de78(R), 0043de88(W), 0043de97(R), 
    //                                                                                     0043decb(R), 0043deda(R), 0043defc(R), 0043e027(R), 
    //                                                                                     0043e037(W), 0043e046(R), 0043e07a(R), 0043e089(R), 
    //                                                                                     0043e0ab(R), 0043e1d6(R), 0043e1e6(W), 0043e1f4(R)  
    //              float             Stack[-0x10c   cost
    //              undefined4        Stack[-0x11c   local_11c                 XREF[1]:     0043da18(*)  
    //                               ?action@TribeDiplomacyDialog@@MAEJPAVTPanel@@JKK@Z           XREF[1]:     0056f94c(*)  
    //                               TribeDiplomacyDialog::action
    //                              dlg_dip.cpp:434 (8)
    //         0043d8a0     SUB        ESP,0x108
    //         0043d8a6     PUSH       EBX
    //         0043d8a7     PUSH       EBP
    //                              dlg_dip.cpp:440 (33)
    //         0043d8a8     MOV        EBP,dword ptr [ESP + param_1]
    //         0043d8af     PUSH       ESI
    //         0043d8b0     TEST       EBP,EBP
    //         0043d8b2     PUSH       EDI
    //         0043d8b3     MOV        ESI,this
    //         0043d8b5     JZ         LAB_0043de3c
    //         0043d8bb     CMP        dword ptr [ESP + param_2],0x1
    //         0043d8c3     JNZ        LAB_0043de3c
    //                              dlg_dip.cpp:442 (12)
    //         0043d8c9     CMP        EBP,dword ptr [ESI + 0x5f8]
    //         0043d8cf     JNZ        LAB_0043db79
    //                              dlg_dip.cpp:444 (15)
    //         0043d8d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d8db     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0043d8e1     MOV        EDI,dword ptr [EAX + 0x58]
    //                              dlg_dip.cpp:446 (13)
    //         0043d8e4     MOV        EAX,[allow_user_commands]                        = 1h
    //         0043d8e9     TEST       EAX,EAX
    //         0043d8eb     MOV        dword ptr [ESP + temp_str[0]],EDI
    //         0043d8ef     JZ         LAB_0043d937
    //                              dlg_dip.cpp:448 (35)
    //         0043d8f1     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d8f6     MOV        this,EAX
    //         0043d8f8     CALL       RGE_Player::get_allied_victory                   uchar get_allied_victory(RGE_Player * this)
    //         0043d8fd     MOV        this,dword ptr [ESI + 0x5f4]
    //         0043d903     MOV        BL,AL
    //         0043d905     AND        EBX,0xff
    //         0043d90b     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043d910     CMP        EAX,EBX
    //         0043d912     JZ         LAB_0043d937
    //                              dlg_dip.cpp:449 (35)
    //         0043d914     MOV        this,dword ptr [ESI + 0x5f4]
    //         0043d91a     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043d91f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d925     PUSH       EAX
    //         0043d926     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d92b     MOV        this,word ptr [EAX + 0x4a]
    //         0043d92f     PUSH       this
    //         0043d930     MOV        this,EDI
    //         0043d932     CALL       TRIBE_Command::command_allied_victory            void command_allied_victory(TRIBE_Command * t
    //                               LAB_0043d937                                                 XREF[2]:     0043d8ef(j), 0043d912(j)  
    //                              dlg_dip.cpp:454 (46)
    //         0043d937     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d93d     MOV        EDI,0x1
    //         0043d942     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0043d948     MOVSX      EDX,word ptr [EAX + 0x3c]
    //         0043d94c     DEC        EDX
    //         0043d94d     TEST       EDX,EDX
    //         0043d94f     JLE        LAB_0043db87
    //         0043d955     LEA        EBP,[ESI + 0x690]
    //         0043d95b     ADD        ESI,0x594
    //         0043d961     MOV        dword ptr [ESP + tc],ESI
    //                               LAB_0043d965                                                 XREF[1]:     0043db1e(j)  
    //                              dlg_dip.cpp:455 (12)
    //         0043d965     MOVSX      EAX,word ptr [EAX + 0x7c]
    //         0043d969     CMP        EDI,EAX
    //         0043d96b     JZ         LAB_0043daf9
    //                              dlg_dip.cpp:459 (10)
    //         0043d971     MOV        this,dword ptr [ESI]
    //         0043d973     TEST       this,this
    //         0043d975     JZ         LAB_0043daf9
    //                              dlg_dip.cpp:461 (10)
    //         0043d97b     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043d980     CMP        EAX,0x1
    //         0043d983     JNZ        LAB_0043d989
    //                              dlg_dip.cpp:462 (2)
    //         0043d985     XOR        BL,BL
    //                              dlg_dip.cpp:463 (22)
    //         0043d987     JMP        LAB_0043d99d
    //                               LAB_0043d989                                                 XREF[1]:     0043d983(j)  
    //         0043d989     MOV        this,dword ptr [ESI + 0x4]
    //         0043d98c     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         0043d991     MOV        EBX,EAX
    //         0043d993     DEC        EBX
    //         0043d994     NEG        EBX
    //         0043d996     SBB        BL,BL
    //         0043d998     AND        BL,0x2
    //         0043d99b     INC        BL
    //                               LAB_0043d99d                                                 XREF[1]:     0043d987(j)  
    //                              dlg_dip.cpp:468 (13)
    //         0043d99d     MOV        EAX,[allow_user_commands]                        = 1h
    //         0043d9a2     TEST       EAX,EAX
    //         0043d9a4     JZ         LAB_0043daf9
    //                              dlg_dip.cpp:470 (23)
    //         0043d9aa     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d9b0     PUSH       EDI
    //         0043d9b1     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d9b6     MOV        this,EAX
    //         0043d9b8     CALL       RGE_Player::relation                             uchar relation(RGE_Player * this, long param_1)
    //         0043d9bd     CMP        AL,BL
    //         0043d9bf     JZ         LAB_0043d9e1
    //                              dlg_dip.cpp:474 (32)
    //         0043d9c1     XOR        this,this
    //         0043d9c4     MOV        this,BL
    //         0043d9c6     PUSH       this
    //         0043d9c7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d9cd     PUSH       EDI
    //         0043d9ce     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d9d3     MOV        DX,word ptr [EAX + 0x4a]
    //         0043d9d7     MOV        this,dword ptr [ESP + temp_str[0]]
    //         0043d9db     PUSH       EDX
    //         0043d9dc     CALL       TRIBE_Command::command_relation                  void command_relation(TRIBE_Command * this, s
    //                               LAB_0043d9e1                                                 XREF[1]:     0043d9bf(j)  
    //                              dlg_dip.cpp:478 (16)
    //         0043d9e1     FLD        float ptr [EBP + -0x60]
    //         0043d9e4     FCOMP      float ptr [DAT_0056f884]
    //         0043d9ea     FNSTSW     AX
    //         0043d9ec     TEST       AH,0x41
    //         0043d9ef     JNZ        LAB_0043da27
    //                              dlg_dip.cpp:480 (54)
    //         0043d9f1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043d9f7     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043d9fc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043da02     MOV        ESI,EAX
    //         0043da04     MOV        EBX,dword ptr [ESI]
    //         0043da06     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043da0b     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043da0e     PUSH       this
    //         0043da0f     MOV        this,dword ptr [EBP + -0x60]
    //         0043da12     FLD        float ptr [EAX + 0xb8]
    //         0043da18     FSTP       float ptr [ESP]=>local_11c
    //         0043da1b     PUSH       this
    //         0043da1c     PUSH       0x3
    //         0043da1e     PUSH       EDI
    //         0043da1f     MOV        this,ESI
    //         0043da21     CALL       dword ptr [EBX + 0xf8]
    //                               LAB_0043da27                                                 XREF[1]:     0043d9ef(j)  
    //                              dlg_dip.cpp:481 (16)
    //         0043da27     FLD        float ptr [EBP]
    //         0043da2a     FCOMP      float ptr [DAT_0056f884]
    //         0043da30     FNSTSW     AX
    //         0043da32     TEST       AH,0x41
    //         0043da35     JNZ        LAB_0043da6d
    //                              dlg_dip.cpp:483 (54)
    //         0043da37     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043da3d     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043da42     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043da48     MOV        ESI,EAX
    //         0043da4a     MOV        EBX,dword ptr [ESI]
    //         0043da4c     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043da51     MOV        EDX,dword ptr [EAX + 0x50]
    //         0043da54     MOV        EAX,dword ptr [EBP]
    //         0043da57     PUSH       this
    //         0043da58     MOV        this,ESI
    //         0043da5a     FLD        float ptr [EDX + 0xb8]
    //         0043da60     FSTP       float ptr [ESP]
    //         0043da63     PUSH       EAX=>DAT_fffffff8
    //         0043da64     PUSH       offset DAT_fffffff4
    //         0043da66     PUSH       EDI=>DAT_fffffff0
    //         0043da67     CALL       dword ptr [EBX + 0xf8]
    //                               LAB_0043da6d                                                 XREF[1]:     0043da35(j)  
    //                              dlg_dip.cpp:485 (16)
    //         0043da6d     FLD        float ptr [EBP + -0x40]
    //         0043da70     FCOMP      float ptr [DAT_0056f884]
    //         0043da76     FNSTSW     AX
    //         0043da78     TEST       AH,0x41
    //         0043da7b     JNZ        LAB_0043dab3
    //                              dlg_dip.cpp:487 (54)
    //         0043da7d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043da83     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043da88     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043da8e     MOV        EBX,EAX
    //         0043da90     MOV        ESI,dword ptr [EBX]
    //         0043da92     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043da97     MOV        this,dword ptr [EAX + 0x50]
    //         0043da9a     MOV        EDX,dword ptr [EBP + -0x40]
    //         0043da9d     PUSH       this
    //         0043da9e     FLD        float ptr [ECX + this->_padding_]
    //         0043daa4     FSTP       float ptr [ESP]
    //         0043daa7     PUSH       EDX=>DAT_fffffff8
    //         0043daa8     PUSH       0x0=>DAT_fffffff4
    //         0043daaa     PUSH       EDI=>DAT_fffffff0
    //         0043daab     MOV        this,EBX
    //         0043daad     CALL       dword ptr [ESI + 0xf8]
    //                               LAB_0043dab3                                                 XREF[1]:     0043da7b(j)  
    //                              dlg_dip.cpp:489 (16)
    //         0043dab3     FLD        float ptr [EBP + -0x20]
    //         0043dab6     FCOMP      float ptr [DAT_0056f884]
    //         0043dabc     FNSTSW     AX
    //         0043dabe     TEST       AH,0x41
    //         0043dac1     JNZ        LAB_0043daf9
    //                              dlg_dip.cpp:491 (97)
    //         0043dac3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dac9     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dace     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dad4     MOV        EBX,EAX
    //         0043dad6     MOV        ESI,dword ptr [EBX]
    //         0043dad8     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dadd     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043dae0     PUSH       this
    //         0043dae1     MOV        this,dword ptr [EBP + -0x20]
    //         0043dae4     FLD        float ptr [EAX + 0xb8]
    //         0043daea     FSTP       float ptr [ESP]
    //         0043daed     PUSH       this=>DAT_fffffff8
    //         0043daee     PUSH       offset DAT_fffffff4
    //         0043daf0     PUSH       EDI=>DAT_fffffff0
    //         0043daf1     MOV        this,EBX
    //         0043daf3     CALL       dword ptr [ESI + 0xf8]
    //                               LAB_0043daf9                                                 XREF[4]:     0043d96b(j), 0043d975(j), 
    //                                                                                                         0043d9a4(j), 0043dac1(j)  
    //         0043daf9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043daff     MOV        ESI,dword ptr [ESP + tc]
    //         0043db03     INC        EDI
    //         0043db04     ADD        ESI,0xc
    //         0043db07     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0043db0d     ADD        EBP,0x4
    //         0043db10     LEA        EDX,[EDI + -0x1]
    //         0043db13     MOV        dword ptr [ESP + tc],ESI
    //         0043db17     MOVSX      EBX,word ptr [EAX + 0x3c]
    //         0043db1b     DEC        EBX
    //         0043db1c     CMP        EDX,EBX
    //         0043db1e     JL         LAB_0043d965
    //                              dlg_dip.cpp:498 (26)
    //         0043db24     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043db29     CMP        EAX,0x1
    //         0043db2c     JNZ        LAB_0043dbaa
    //         0043db2e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043db34     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0043db3a     TEST       EAX,EAX
    //         0043db3c     JNZ        LAB_0043dbaa
    //                              dlg_dip.cpp:499 (9)
    //         0043db3e     PUSH       0x0
    //         0043db40     PUSH       0x0=>DAT_fffffff8
    //         0043db42     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                              dlg_dip.cpp:501 (17)
    //         0043db47     PUSH       0x0
    //         0043db49     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0043db4e     MOV        this,panel_system
    //         0043db53     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_dip.cpp:502 (15)
    //         0043db58     PUSH       s_Diplomacy_Dialog                               = "Diplomacy Dialog"
    //         0043db5d     MOV        this,panel_system
    //         0043db62     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_dip.cpp:503 (5)
    //         0043db67     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043db6c     POP        EDI
    //         0043db6d     POP        ESI
    //         0043db6e     POP        EBP
    //         0043db6f     POP        EBX
    //         0043db70     ADD        ESP,0x108
    //         0043db76     RET        0x10
    //                               LAB_0043db79                                                 XREF[1]:     0043d8cf(j)  
    //                              dlg_dip.cpp:508 (8)
    //         0043db79     CMP        EBP,dword ptr [ESI + 0x600]
    //         0043db7f     JNZ        LAB_0043dbdc
    //                              dlg_dip.cpp:510 (32)
    //         0043db81     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                               LAB_0043db87                                                 XREF[1]:     0043d94f(j)  
    //         0043db87     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0043db8c     CMP        EAX,0x1
    //         0043db8f     JNZ        LAB_0043dbaa
    //         0043db91     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043db97     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0043db9d     TEST       EAX,EAX
    //         0043db9f     JNZ        LAB_0043dbaa
    //                              dlg_dip.cpp:511 (9)
    //         0043dba1     PUSH       0x0
    //         0043dba3     PUSH       0x0
    //         0043dba5     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_0043dbaa                                                 XREF[4]:     0043db2c(j), 0043db3c(j), 
    //                                                                                                         0043db8f(j), 0043db9f(j)  
    //                              dlg_dip.cpp:513 (17)
    //         0043dbaa     PUSH       0x0
    //         0043dbac     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0043dbb1     MOV        this,panel_system
    //         0043dbb6     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              dlg_dip.cpp:514 (15)
    //         0043dbbb     PUSH       s_Diplomacy_Dialog                               = "Diplomacy Dialog"
    //         0043dbc0     MOV        this,panel_system
    //         0043dbc5     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              dlg_dip.cpp:515 (5)
    //         0043dbca     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043dbcf     POP        EDI
    //         0043dbd0     POP        ESI
    //         0043dbd1     POP        EBP
    //         0043dbd2     POP        EBX
    //         0043dbd3     ADD        ESP,0x108
    //         0043dbd9     RET        0x10
    //                               LAB_0043dbdc                                                 XREF[1]:     0043db7f(j)  
    //                              dlg_dip.cpp:519 (8)
    //         0043dbdc     CMP        EBP,dword ptr [ESI + 0x604]
    //         0043dbe2     JNZ        LAB_0043dbfd
    //                              dlg_dip.cpp:520 (7)
    //         0043dbe4     MOV        this,ESI
    //         0043dbe6     CALL       TEasy_Panel::setup_popup_help                    void setup_popup_help(TEasy_Panel * this)
    //                              dlg_dip.cpp:521 (5)
    //         0043dbeb     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043dbf0     POP        EDI
    //         0043dbf1     POP        ESI
    //         0043dbf2     POP        EBP
    //         0043dbf3     POP        EBX
    //         0043dbf4     ADD        ESP,0x108
    //         0043dbfa     RET        0x10
    //                               LAB_0043dbfd                                                 XREF[1]:     0043dbe2(j)  
    //                              dlg_dip.cpp:525 (12)
    //         0043dbfd     CMP        EBP,dword ptr [ESI + 0x5fc]
    //         0043dc03     JNZ        LAB_0043ddb0
    //                              dlg_dip.cpp:527 (2)
    //         0043dc09     XOR        EBX,EBX
    //                              dlg_dip.cpp:738 (421)
    //         0043dc0b     LEA        EDI,[ESI + 0x554]
    //         0043dc11     MOV        dword ptr [ESI + 0x610],EBX
    //         0043dc17     MOV        dword ptr [ESI + 0x618],EBX
    //         0043dc1d     MOV        dword ptr [ESI + 0x61c],EBX
    //         0043dc23     MOV        dword ptr [ESI + 0x614],EBX
    //         0043dc29     MOV        EBP,0x8
    //                               LAB_0043dc2e                                                 XREF[1]:     0043dc91(j)  
    //         0043dc2e     MOV        this,dword ptr [EDI + -0x40]
    //         0043dc31     CMP        this,EBX
    //         0043dc33     JZ         LAB_0043dc40
    //         0043dc35     PUSH       s_                                               = ""
    //         0043dc3a     PUSH       EBX
    //         0043dc3b     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_0043dc40                                                 XREF[1]:     0043dc33(j)  
    //         0043dc40     MOV        this,dword ptr [EDI]
    //         0043dc42     CMP        this,EBX
    //         0043dc44     JZ         LAB_0043dc51
    //         0043dc46     PUSH       s_                                               = ""
    //         0043dc4b     PUSH       EBX
    //         0043dc4c     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_0043dc51                                                 XREF[1]:     0043dc44(j)  
    //         0043dc51     MOV        this,dword ptr [EDI + -0x20]
    //         0043dc54     CMP        this,EBX
    //         0043dc56     JZ         LAB_0043dc63
    //         0043dc58     PUSH       s_                                               = ""
    //         0043dc5d     PUSH       EBX
    //         0043dc5e     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_0043dc63                                                 XREF[1]:     0043dc56(j)  
    //         0043dc63     MOV        this,dword ptr [EDI + 0x20]
    //         0043dc66     CMP        this,EBX
    //         0043dc68     JZ         LAB_0043dc75
    //         0043dc6a     PUSH       s_                                               = ""
    //         0043dc6f     PUSH       EBX
    //         0043dc70     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                               LAB_0043dc75                                                 XREF[1]:     0043dc68(j)  
    //         0043dc75     MOV        dword ptr [EDI + 0xdc],EBX
    //         0043dc7b     MOV        dword ptr [EDI + 0xfc],EBX
    //         0043dc81     MOV        dword ptr [EDI + 0x11c],EBX
    //         0043dc87     MOV        dword ptr [EDI + 0x13c],EBX
    //         0043dc8d     ADD        EDI,0x4
    //         0043dc90     DEC        EBP
    //         0043dc91     JNZ        LAB_0043dc2e
    //         0043dc93     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dc99     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dc9e     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043dca1     FLD        float ptr [EAX + 0xc]
    //         0043dca4     CALL       __ftol                                           undefined __ftol()
    //         0043dca9     PUSH       EAX
    //         0043dcaa     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043dcae     PUSH       s_%ld                                            = "%ld"
    //         0043dcb3     PUSH       this
    //         0043dcb4     CALL       sprintf                                          undefined sprintf()
    //         0043dcb9     MOV        this,dword ptr [ESI + 0x624]
    //         0043dcbf     ADD        ESP,0xc
    //         0043dcc2     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043dcc6     MOV        EDX,dword ptr [this->_padding_]
    //         0043dcc8     PUSH       EAX
    //         0043dcc9     CALL       dword ptr [EDX + 0xe8]
    //         0043dccf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dcd5     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dcda     MOV        this,dword ptr [EAX + 0x50]
    //         0043dcdd     FLD        float ptr [this->_padding_]
    //         0043dcdf     CALL       __ftol                                           undefined __ftol()
    //         0043dce4     PUSH       EAX
    //         0043dce5     LEA        EDX,[ESP + 0x1c]
    //         0043dce9     PUSH       s_%ld                                            = "%ld"
    //         0043dcee     PUSH       EDX=>DAT_fffffff4
    //         0043dcef     CALL       sprintf                                          undefined sprintf()
    //         0043dcf4     MOV        this,dword ptr [ESI + 0x620]
    //         0043dcfa     ADD        ESP,0xc
    //         0043dcfd     LEA        EDX,[ESP + 0x18]
    //         0043dd01     MOV        EAX,dword ptr [this->_padding_]
    //         0043dd03     PUSH       EDX
    //         0043dd04     CALL       dword ptr [EAX + 0xe8]
    //         0043dd0a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dd10     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dd15     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043dd18     FLD        float ptr [EAX + 0x4]
    //         0043dd1b     CALL       __ftol                                           undefined __ftol()
    //         0043dd20     PUSH       EAX
    //         0043dd21     LEA        this,[ESP + 0x1c]
    //         0043dd25     PUSH       s_%ld                                            = "%ld"
    //         0043dd2a     PUSH       this=>DAT_fffffff4
    //         0043dd2b     CALL       sprintf                                          undefined sprintf()
    //         0043dd30     MOV        this,dword ptr [ESI + 0x628]
    //         0043dd36     ADD        ESP,0xc
    //         0043dd39     LEA        EAX,[ESP + 0x18]
    //         0043dd3d     MOV        EDX,dword ptr [this->_padding_]
    //         0043dd3f     PUSH       EAX
    //         0043dd40     CALL       dword ptr [EDX + 0xe8]
    //         0043dd46     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dd4c     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dd51     MOV        this,dword ptr [EAX + 0x50]
    //         0043dd54     FLD        float ptr [ECX + this->_padding_]
    //         0043dd57     CALL       __ftol                                           undefined __ftol()
    //         0043dd5c     PUSH       EAX
    //         0043dd5d     LEA        EDX,[ESP + 0x1c]
    //         0043dd61     PUSH       s_%ld                                            = "%ld"
    //         0043dd66     PUSH       EDX=>DAT_fffffff4
    //         0043dd67     CALL       sprintf                                          undefined sprintf()
    //         0043dd6c     MOV        this,dword ptr [ESI + 0x62c]
    //         0043dd72     ADD        ESP,0xc
    //         0043dd75     LEA        EDX,[ESP + 0x18]
    //         0043dd79     MOV        EAX,dword ptr [this->_padding_]
    //         0043dd7b     PUSH       EDX
    //         0043dd7c     CALL       dword ptr [EAX + 0xe8]
    //         0043dd82     MOV        this,ESI
    //         0043dd84     CALL       TribeDiplomacyDialog::check_gold                 int check_gold(TribeDiplomacyDialog * this)
    //         0043dd89     MOV        this,ESI
    //         0043dd8b     CALL       TribeDiplomacyDialog::check_wood                 int check_wood(TribeDiplomacyDialog * this)
    //         0043dd90     MOV        this,ESI
    //         0043dd92     CALL       TribeDiplomacyDialog::check_stone                int check_stone(TribeDiplomacyDialog * this)
    //         0043dd97     MOV        this,ESI
    //         0043dd99     CALL       TribeDiplomacyDialog::check_food                 int check_food(TribeDiplomacyDialog * this)
    //         0043dd9e     MOV        EAX,0x1
    //         0043dda3     POP        EDI
    //         0043dda4     POP        ESI
    //         0043dda5     POP        EBP
    //         0043dda6     POP        EBX
    //         0043dda7     ADD        ESP,0x108
    //         0043ddad     RET        0x10
    //                               LAB_0043ddb0                                                 XREF[1]:     0043dc03(j)  
    //                              dlg_dip.cpp:579 (41)
    //         0043ddb0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043ddb6     MOV        dword ptr [ESP + tc],0x0
    //         0043ddbe     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043ddc3     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043ddc6     FLD        float ptr [EAX + 0xb8]
    //         0043ddcc     FCOMP      double ptr [DAT_0056f888]
    //         0043ddd2     FNSTSW     AX
    //         0043ddd4     TEST       AH,0x41
    //         0043ddd7     JNZ        LAB_0043ddf1
    //                              dlg_dip.cpp:580 (24)
    //         0043ddd9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dddf     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dde4     MOV        this,dword ptr [EAX + 0x50]
    //         0043dde7     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0043dded     MOV        dword ptr [ESP + tc],EDX
    //                               LAB_0043ddf1                                                 XREF[1]:     0043ddd7(j)  
    //                              dlg_dip.cpp:582 (35)
    //         0043ddf1     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043ddf6     XOR        EBX,EBX
    //         0043ddf8     MOV        EDI,0x1
    //         0043ddfd     MOV        this,dword ptr [EAX + 0x3f4]
    //         0043de03     MOVSX      EAX,word ptr [ECX + this->_padding_]
    //         0043de07     LEA        this,[EAX + -0x1]
    //         0043de0a     TEST       this,this
    //         0043de0c     JLE        LAB_0043de3c
    //         0043de0e     LEA        EAX,[ESI + 0x534]
    //                               LAB_0043de14                                                 XREF[1]:     0043de3a(j)  
    //                              dlg_dip.cpp:585 (5)
    //         0043de14     CMP        EBP,dword ptr [EAX + -0x20]
    //         0043de17     JZ         LAB_0043de69
    //                              dlg_dip.cpp:622 (8)
    //         0043de19     CMP        EBP,dword ptr [EAX]
    //         0043de1b     JZ         LAB_0043e018
    //                              dlg_dip.cpp:659 (9)
    //         0043de21     CMP        EBP,dword ptr [EAX + 0x20]
    //         0043de24     JZ         LAB_0043e1c7
    //                              dlg_dip.cpp:696 (18)
    //         0043de2a     CMP        EBP,dword ptr [EAX + 0x40]
    //         0043de2d     JZ         LAB_0043e372
    //         0043de33     INC        EBX
    //         0043de34     ADD        EAX,0x4
    //         0043de37     INC        EDI
    //         0043de38     CMP        EBX,this
    //         0043de3a     JL         LAB_0043de14
    //                               LAB_0043de3c                                                 XREF[3]:     0043d8b5(j), 0043d8c3(j), 
    //                                                                                                         0043de0c(j)  
    //                              dlg_dip.cpp:737 (32)
    //         0043de3c     MOV        this,dword ptr [ESP + param_4]
    //         0043de43     MOV        EDX,dword ptr [ESP + param_3]
    //         0043de4a     MOV        EAX,dword ptr [ESP + param_2]
    //         0043de51     PUSH       this
    //         0043de52     PUSH       EDX
    //         0043de53     PUSH       EAX
    //         0043de54     PUSH       EBP
    //         0043de55     MOV        this,ESI
    //         0043de57     CALL       TPanel::action                                   long action(TPanel * this, TPanel * param_1, 
    //                              dlg_dip.cpp:738 (13)
    //         0043de5c     POP        EDI
    //         0043de5d     POP        ESI
    //         0043de5e     POP        EBP
    //         0043de5f     POP        EBX
    //         0043de60     ADD        ESP,0x108
    //         0043de66     RET        0x10
    //                               LAB_0043de69                                                 XREF[1]:     0043de17(j)  
    //                              dlg_dip.cpp:588 (15)
    //         0043de69     MOV        this,ESI
    //         0043de6b     CALL       TribeDiplomacyDialog::check_gold                 int check_gold(TribeDiplomacyDialog * this)
    //         0043de70     TEST       EAX,EAX
    //         0043de72     JNZ        LAB_0043dfa8
    //                              dlg_dip.cpp:590 (60)
    //         0043de78     FLD        float ptr [ESP + tc]
    //         0043de7c     FSUB       float ptr [DAT_0056f890]
    //         0043de82     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043de88     FSTP       float ptr [ESP + tc]
    //         0043de8c     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043de91     MOV        EDX,dword ptr [EAX + 0x50]
    //         0043de94     FLD        float ptr [EDX + 0xc]
    //         0043de97     FLD        float ptr [ESP + tc]
    //         0043de9b     FMUL       float ptr [DAT_0056f880]                         = align(2)
    //         0043dea1     FXCH
    //         0043dea3     FSUB       float ptr [ESI + 0x618]
    //         0043dea9     FXCH
    //         0043deab     FCOMPP
    //         0043dead     FNSTSW     AX
    //         0043deaf     TEST       AH,0x41
    //         0043deb2     JNZ        LAB_0043deef
    //                              dlg_dip.cpp:593 (14)
    //         0043deb4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043deba     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043debf     MOV        EAX,dword ptr [EAX + 0x50]
    //                              dlg_dip.cpp:594 (22)
    //         0043dec2     FLD        float ptr [EAX + 0xc]
    //         0043dec5     FSUB       float ptr [ESI + 0x618]
    //         0043decb     FDIV       float ptr [ESP + tc]
    //         0043decf     FLD        ST0
    //         0043ded1     FADD       float ptr [ESI + EDI*0x4 + 0x62c]
    //                              dlg_dip.cpp:595 (21)
    //         0043ded8     FXCH
    //         0043deda     FMUL       float ptr [ESP + tc]
    //         0043dede     FXCH
    //         0043dee0     FSTP       float ptr [ESI + EDI*0x4 + 0x62c]
    //         0043dee7     FADD       float ptr [ESI + 0x618]
    //                              dlg_dip.cpp:597 (2)
    //         0043deed     JMP        LAB_0043df15
    //                               LAB_0043deef                                                 XREF[1]:     0043deb2(j)  
    //                              dlg_dip.cpp:600 (13)
    //         0043deef     FLD        float ptr [ESI + EDI*0x4 + 0x62c]
    //         0043def6     FSUB       float ptr [DAT_0056f894]
    //                              dlg_dip.cpp:601 (31)
    //         0043defc     FLD        float ptr [ESP + tc]
    //         0043df00     FMUL       float ptr [DAT_0056f894]
    //         0043df06     FXCH
    //         0043df08     FSTP       float ptr [ESI + EDI*0x4 + 0x62c]
    //         0043df0f     FSUBR      float ptr [ESI + 0x618]
    //                               LAB_0043df15                                                 XREF[1]:     0043deed(j)  
    //         0043df15     FSTP       float ptr [ESI + 0x618]
    //                              dlg_dip.cpp:603 (23)
    //         0043df1b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043df21     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043df26     MOV        this,dword ptr [EAX + 0x50]
    //         0043df29     FLD        float ptr [ECX + this->_padding_]
    //         0043df2c     FSUB       float ptr [ESI + 0x618]
    //                              dlg_dip.cpp:604 (21)
    //         0043df32     CALL       __ftol                                           undefined __ftol()
    //         0043df37     PUSH       EAX
    //         0043df38     LEA        EDX=>temp_str[4],[ESP + 0x1c]
    //         0043df3c     PUSH       s_%ld                                            = "%ld"
    //         0043df41     PUSH       EDX
    //         0043df42     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:605 (22)
    //         0043df47     MOV        this,dword ptr [ESI + 0x624]
    //         0043df4d     ADD        ESP,0xc
    //         0043df50     LEA        EDX=>temp_str[4],[ESP + 0x18]
    //         0043df54     MOV        EAX,dword ptr [this->_padding_]
    //         0043df56     PUSH       EDX
    //         0043df57     CALL       dword ptr [EAX + 0xe8]
    //                              dlg_dip.cpp:606 (31)
    //         0043df5d     FLD        float ptr [ESI + EDI*0x4 + 0x62c]
    //         0043df64     CALL       __ftol                                           undefined __ftol()
    //         0043df69     PUSH       EAX
    //         0043df6a     LEA        EAX,[ESP + 0x1c]
    //         0043df6e     PUSH       s_%ld                                            = "%ld"
    //         0043df73     PUSH       EAX=>DAT_fffffff4
    //         0043df74     CALL       sprintf                                          undefined sprintf()
    //         0043df79     ADD        ESP,0xc
    //                              dlg_dip.cpp:607 (19)
    //         0043df7c     LEA        this,[ESP + 0x18]
    //         0043df80     PUSH       this
    //         0043df81     MOV        this,dword ptr [ESI + EBX*0x4 + 0x514]
    //         0043df88     PUSH       0x0=>DAT_fffffff8
    //         0043df8a     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              dlg_dip.cpp:617 (7)
    //         0043df8f     MOV        this,ESI
    //         0043df91     CALL       TribeDiplomacyDialog::check_gold                 int check_gold(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:618 (5)
    //         0043df96     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043df9b     POP        EDI
    //         0043df9c     POP        ESI
    //         0043df9d     POP        EBP
    //         0043df9e     POP        EBX
    //         0043df9f     ADD        ESP,0x108
    //         0043dfa5     RET        0x10
    //                               LAB_0043dfa8                                                 XREF[1]:     0043de72(j)  
    //                              dlg_dip.cpp:611 (23)
    //         0043dfa8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043dfae     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043dfb3     MOV        EDX,dword ptr [EAX + 0x50]
    //         0043dfb6     FLD        float ptr [EDX + 0xc]
    //         0043dfb9     FSUB       float ptr [ESI + 0x618]
    //                              dlg_dip.cpp:612 (15)
    //         0043dfbf     FCOM       float ptr [DAT_0056f884]
    //         0043dfc5     FNSTSW     AX
    //         0043dfc7     TEST       AH,0x1
    //         0043dfca     JZ         LAB_0043dfd4
    //         0043dfcc     FSTP       ST0
    //                              dlg_dip.cpp:613 (6)
    //         0043dfce     FLD        float ptr [DAT_0056f884]
    //                               LAB_0043dfd4                                                 XREF[1]:     0043dfca(j)  
    //                              dlg_dip.cpp:614 (21)
    //         0043dfd4     CALL       __ftol                                           undefined __ftol()
    //         0043dfd9     PUSH       EAX
    //         0043dfda     LEA        EAX=>temp_str[4],[ESP + 0x1c]
    //         0043dfde     PUSH       s_%ld                                            = "%ld"
    //         0043dfe3     PUSH       EAX
    //         0043dfe4     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:615 (22)
    //         0043dfe9     MOV        this,dword ptr [ESI + 0x624]
    //         0043dfef     ADD        ESP,0xc
    //         0043dff2     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043dff6     MOV        EDX,dword ptr [this->_padding_]
    //         0043dff8     PUSH       EAX
    //         0043dff9     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:617 (7)
    //         0043dfff     MOV        this,ESI
    //         0043e001     CALL       TribeDiplomacyDialog::check_gold                 int check_gold(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:618 (5)
    //         0043e006     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043e00b     POP        EDI
    //         0043e00c     POP        ESI
    //         0043e00d     POP        EBP
    //         0043e00e     POP        EBX
    //         0043e00f     ADD        ESP,0x108
    //         0043e015     RET        0x10
    //                               LAB_0043e018                                                 XREF[1]:     0043de1b(j)  
    //                              dlg_dip.cpp:625 (15)
    //         0043e018     MOV        this,ESI
    //         0043e01a     CALL       TribeDiplomacyDialog::check_wood                 int check_wood(TribeDiplomacyDialog * this)
    //         0043e01f     TEST       EAX,EAX
    //         0043e021     JNZ        LAB_0043e157
    //                              dlg_dip.cpp:627 (60)
    //         0043e027     FLD        float ptr [ESP + tc]
    //         0043e02b     FSUB       float ptr [DAT_0056f890]
    //         0043e031     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e037     FSTP       float ptr [ESP + tc]
    //         0043e03b     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e040     MOV        this,dword ptr [EAX + 0x50]
    //         0043e043     FLD        float ptr [ECX + this->_padding_]
    //         0043e046     FLD        float ptr [ESP + tc]
    //         0043e04a     FMUL       float ptr [DAT_0056f880]                         = align(2)
    //         0043e050     FXCH
    //         0043e052     FSUB       float ptr [ESI + 0x614]
    //         0043e058     FXCH
    //         0043e05a     FCOMPP
    //         0043e05c     FNSTSW     AX
    //         0043e05e     TEST       AH,0x41
    //         0043e061     JNZ        LAB_0043e09e
    //                              dlg_dip.cpp:630 (14)
    //         0043e063     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e069     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e06e     MOV        EDX,dword ptr [EAX + 0x50]
    //                              dlg_dip.cpp:631 (22)
    //         0043e071     FLD        float ptr [EDX + 0x4]
    //         0043e074     FSUB       float ptr [ESI + 0x614]
    //         0043e07a     FDIV       float ptr [ESP + tc]
    //         0043e07e     FLD        ST0
    //         0043e080     FADD       float ptr [ESI + EDI*0x4 + 0x68c]
    //                              dlg_dip.cpp:632 (21)
    //         0043e087     FXCH
    //         0043e089     FMUL       float ptr [ESP + tc]
    //         0043e08d     FXCH
    //         0043e08f     FSTP       float ptr [ESI + EDI*0x4 + 0x68c]
    //         0043e096     FADD       float ptr [ESI + 0x614]
    //                              dlg_dip.cpp:634 (2)
    //         0043e09c     JMP        LAB_0043e0c4
    //                               LAB_0043e09e                                                 XREF[1]:     0043e061(j)  
    //                              dlg_dip.cpp:637 (13)
    //         0043e09e     FLD        float ptr [ESI + EDI*0x4 + 0x68c]
    //         0043e0a5     FSUB       float ptr [DAT_0056f894]
    //                              dlg_dip.cpp:638 (31)
    //         0043e0ab     FLD        float ptr [ESP + tc]
    //         0043e0af     FMUL       float ptr [DAT_0056f894]
    //         0043e0b5     FXCH
    //         0043e0b7     FSTP       float ptr [ESI + EDI*0x4 + 0x68c]
    //         0043e0be     FSUBR      float ptr [ESI + 0x614]
    //                               LAB_0043e0c4                                                 XREF[1]:     0043e09c(j)  
    //         0043e0c4     FSTP       float ptr [ESI + 0x614]
    //                              dlg_dip.cpp:640 (23)
    //         0043e0ca     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e0d0     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e0d5     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e0d8     FLD        float ptr [EAX + 0x4]
    //         0043e0db     FSUB       float ptr [ESI + 0x614]
    //                              dlg_dip.cpp:641 (21)
    //         0043e0e1     CALL       __ftol                                           undefined __ftol()
    //         0043e0e6     PUSH       EAX
    //         0043e0e7     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043e0eb     PUSH       s_%ld                                            = "%ld"
    //         0043e0f0     PUSH       this
    //         0043e0f1     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:642 (22)
    //         0043e0f6     MOV        this,dword ptr [ESI + 0x628]
    //         0043e0fc     ADD        ESP,0xc
    //         0043e0ff     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043e103     MOV        EDX,dword ptr [this->_padding_]
    //         0043e105     PUSH       EAX
    //         0043e106     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:643 (28)
    //         0043e10c     FLD        float ptr [ESI + EDI*0x4 + 0x68c]
    //         0043e113     CALL       __ftol                                           undefined __ftol()
    //         0043e118     PUSH       EAX
    //         0043e119     LEA        this,[ESP + 0x1c]
    //         0043e11d     PUSH       s_%ld                                            = "%ld"
    //         0043e122     PUSH       this=>DAT_fffffff4
    //         0043e123     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:644 (22)
    //         0043e128     MOV        this,dword ptr [ESI + EBX*0x4 + 0x534]
    //         0043e12f     ADD        ESP,0xc
    //         0043e132     LEA        EDX,[ESP + 0x18]
    //         0043e136     PUSH       EDX
    //         0043e137     PUSH       0x0=>DAT_fffffff8
    //         0043e139     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              dlg_dip.cpp:654 (7)
    //         0043e13e     MOV        this,ESI
    //         0043e140     CALL       TribeDiplomacyDialog::check_wood                 int check_wood(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:655 (5)
    //         0043e145     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043e14a     POP        EDI
    //         0043e14b     POP        ESI
    //         0043e14c     POP        EBP
    //         0043e14d     POP        EBX
    //         0043e14e     ADD        ESP,0x108
    //         0043e154     RET        0x10
    //                               LAB_0043e157                                                 XREF[1]:     0043e021(j)  
    //                              dlg_dip.cpp:648 (23)
    //         0043e157     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e15d     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e162     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e165     FLD        float ptr [EAX + 0x4]
    //         0043e168     FSUB       float ptr [ESI + 0x614]
    //                              dlg_dip.cpp:649 (15)
    //         0043e16e     FCOM       float ptr [DAT_0056f884]
    //         0043e174     FNSTSW     AX
    //         0043e176     TEST       AH,0x1
    //         0043e179     JZ         LAB_0043e183
    //         0043e17b     FSTP       ST0
    //                              dlg_dip.cpp:650 (6)
    //         0043e17d     FLD        float ptr [DAT_0056f884]
    //                               LAB_0043e183                                                 XREF[1]:     0043e179(j)  
    //                              dlg_dip.cpp:651 (21)
    //         0043e183     CALL       __ftol                                           undefined __ftol()
    //         0043e188     PUSH       EAX
    //         0043e189     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043e18d     PUSH       s_%ld                                            = "%ld"
    //         0043e192     PUSH       this
    //         0043e193     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:652 (22)
    //         0043e198     MOV        this,dword ptr [ESI + 0x628]
    //         0043e19e     ADD        ESP,0xc
    //         0043e1a1     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043e1a5     MOV        EDX,dword ptr [this->_padding_]
    //         0043e1a7     PUSH       EAX
    //         0043e1a8     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:654 (7)
    //         0043e1ae     MOV        this,ESI
    //         0043e1b0     CALL       TribeDiplomacyDialog::check_wood                 int check_wood(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:655 (5)
    //         0043e1b5     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043e1ba     POP        EDI
    //         0043e1bb     POP        ESI
    //         0043e1bc     POP        EBP
    //         0043e1bd     POP        EBX
    //         0043e1be     ADD        ESP,0x108
    //         0043e1c4     RET        0x10
    //                               LAB_0043e1c7                                                 XREF[1]:     0043de24(j)  
    //                              dlg_dip.cpp:662 (15)
    //         0043e1c7     MOV        this,ESI
    //         0043e1c9     CALL       TribeDiplomacyDialog::check_food                 int check_food(TribeDiplomacyDialog * this)
    //         0043e1ce     TEST       EAX,EAX
    //         0043e1d0     JNZ        LAB_0043e303
    //                              dlg_dip.cpp:664 (59)
    //         0043e1d6     FLD        float ptr [ESP + tc]
    //         0043e1da     FSUB       float ptr [DAT_0056f890]
    //         0043e1e0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e1e6     FSTP       float ptr [ESP + tc]
    //         0043e1ea     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e1ef     MOV        this,dword ptr [EAX + 0x50]
    //         0043e1f2     FLD        float ptr [this->_padding_]
    //         0043e1f4     FLD        float ptr [ESP + tc]
    //         0043e1f8     FMUL       float ptr [DAT_0056f880]                         = align(2)
    //         0043e1fe     FXCH
    //         0043e200     FSUB       float ptr [ESI + 0x610]
    //         0043e206     FXCH
    //         0043e208     FCOMPP
    //         0043e20a     FNSTSW     AX
    //         0043e20c     TEST       AH,0x41
    //         0043e20f     JNZ        LAB_0043e24b
    //                              dlg_dip.cpp:667 (14)
    //         0043e211     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e217     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e21c     MOV        EDX,dword ptr [EAX + 0x50]
    //                              dlg_dip.cpp:668 (21)
    //         0043e21f     FLD        float ptr [EDX]
    //         0043e221     FSUB       float ptr [ESI + 0x610]
    //         0043e227     FDIV       float ptr [ESP + tc]
    //         0043e22b     FLD        ST0
    //         0043e22d     FADD       float ptr [ESI + EDI*0x4 + 0x64c]
    //                              dlg_dip.cpp:669 (21)
    //         0043e234     FXCH
    //         0043e236     FMUL       float ptr [ESP + tc]
    //         0043e23a     FXCH
    //         0043e23c     FSTP       float ptr [ESI + EDI*0x4 + 0x64c]
    //         0043e243     FADD       float ptr [ESI + 0x610]
    //                              dlg_dip.cpp:671 (2)
    //         0043e249     JMP        LAB_0043e271
    //                               LAB_0043e24b                                                 XREF[1]:     0043e20f(j)  
    //                              dlg_dip.cpp:674 (13)
    //         0043e24b     FLD        float ptr [ESI + EDI*0x4 + 0x64c]
    //         0043e252     FSUB       float ptr [DAT_0056f894]
    //                              dlg_dip.cpp:675 (31)
    //         0043e258     FLD        float ptr [ESP + tc]
    //         0043e25c     FMUL       float ptr [DAT_0056f894]
    //         0043e262     FXCH
    //         0043e264     FSTP       float ptr [ESI + EDI*0x4 + 0x64c]
    //         0043e26b     FSUBR      float ptr [ESI + 0x610]
    //                               LAB_0043e271                                                 XREF[1]:     0043e249(j)  
    //         0043e271     FSTP       float ptr [ESI + 0x610]
    //                              dlg_dip.cpp:677 (22)
    //         0043e277     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e27d     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e282     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e285     FLD        float ptr [EAX]
    //         0043e287     FSUB       float ptr [ESI + 0x610]
    //                              dlg_dip.cpp:678 (21)
    //         0043e28d     CALL       __ftol                                           undefined __ftol()
    //         0043e292     PUSH       EAX
    //         0043e293     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043e297     PUSH       s_%ld                                            = "%ld"
    //         0043e29c     PUSH       this
    //         0043e29d     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:679 (22)
    //         0043e2a2     MOV        this,dword ptr [ESI + 0x620]
    //         0043e2a8     ADD        ESP,0xc
    //         0043e2ab     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043e2af     MOV        EDX,dword ptr [this->_padding_]
    //         0043e2b1     PUSH       EAX
    //         0043e2b2     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:680 (28)
    //         0043e2b8     FLD        float ptr [ESI + EDI*0x4 + 0x64c]
    //         0043e2bf     CALL       __ftol                                           undefined __ftol()
    //         0043e2c4     PUSH       EAX
    //         0043e2c5     LEA        this,[ESP + 0x1c]
    //         0043e2c9     PUSH       s_%ld                                            = "%ld"
    //         0043e2ce     PUSH       this=>DAT_fffffff4
    //         0043e2cf     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:681 (22)
    //         0043e2d4     MOV        this,dword ptr [ESI + EBX*0x4 + 0x554]
    //         0043e2db     ADD        ESP,0xc
    //         0043e2de     LEA        EDX,[ESP + 0x18]
    //         0043e2e2     PUSH       EDX
    //         0043e2e3     PUSH       0x0=>DAT_fffffff8
    //         0043e2e5     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              dlg_dip.cpp:691 (7)
    //         0043e2ea     MOV        this,ESI
    //         0043e2ec     CALL       TribeDiplomacyDialog::check_food                 int check_food(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:692 (5)
    //         0043e2f1     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043e2f6     POP        EDI
    //         0043e2f7     POP        ESI
    //         0043e2f8     POP        EBP
    //         0043e2f9     POP        EBX
    //         0043e2fa     ADD        ESP,0x108
    //         0043e300     RET        0x10
    //                               LAB_0043e303                                                 XREF[1]:     0043e1d0(j)  
    //                              dlg_dip.cpp:685 (22)
    //         0043e303     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e309     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e30e     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e311     FLD        float ptr [EAX]
    //         0043e313     FSUB       float ptr [ESI + 0x610]
    //                              dlg_dip.cpp:686 (15)
    //         0043e319     FCOM       float ptr [DAT_0056f884]
    //         0043e31f     FNSTSW     AX
    //         0043e321     TEST       AH,0x1
    //         0043e324     JZ         LAB_0043e32e
    //         0043e326     FSTP       ST0
    //                              dlg_dip.cpp:687 (6)
    //         0043e328     FLD        float ptr [DAT_0056f884]
    //                               LAB_0043e32e                                                 XREF[1]:     0043e324(j)  
    //                              dlg_dip.cpp:688 (21)
    //         0043e32e     CALL       __ftol                                           undefined __ftol()
    //         0043e333     PUSH       EAX
    //         0043e334     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043e338     PUSH       s_%ld                                            = "%ld"
    //         0043e33d     PUSH       this
    //         0043e33e     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:689 (22)
    //         0043e343     MOV        this,dword ptr [ESI + 0x620]
    //         0043e349     ADD        ESP,0xc
    //         0043e34c     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043e350     MOV        EDX,dword ptr [this->_padding_]
    //         0043e352     PUSH       EAX
    //         0043e353     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:691 (7)
    //         0043e359     MOV        this,ESI
    //         0043e35b     CALL       TribeDiplomacyDialog::check_food                 int check_food(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:692 (5)
    //         0043e360     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043e365     POP        EDI
    //         0043e366     POP        ESI
    //         0043e367     POP        EBP
    //         0043e368     POP        EBX
    //         0043e369     ADD        ESP,0x108
    //         0043e36f     RET        0x10
    //                               LAB_0043e372                                                 XREF[1]:     0043de2d(j)  
    //                              dlg_dip.cpp:699 (15)
    //         0043e372     MOV        this,ESI
    //         0043e374     CALL       TribeDiplomacyDialog::check_stone                int check_stone(TribeDiplomacyDialog * this)
    //         0043e379     TEST       EAX,EAX
    //         0043e37b     JNZ        LAB_0043e4b1
    //                              dlg_dip.cpp:701 (60)
    //         0043e381     FLD        float ptr [ESP + tc]
    //         0043e385     FSUB       float ptr [DAT_0056f890]
    //         0043e38b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e391     FSTP       float ptr [ESP + tc]
    //         0043e395     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e39a     MOV        this,dword ptr [EAX + 0x50]
    //         0043e39d     FLD        float ptr [ECX + this->_padding_]
    //         0043e3a0     FLD        float ptr [ESP + tc]
    //         0043e3a4     FMUL       float ptr [DAT_0056f880]                         = align(2)
    //         0043e3aa     FXCH
    //         0043e3ac     FSUB       float ptr [ESI + 0x61c]
    //         0043e3b2     FXCH
    //         0043e3b4     FCOMPP
    //         0043e3b6     FNSTSW     AX
    //         0043e3b8     TEST       AH,0x41
    //         0043e3bb     JNZ        LAB_0043e3f8
    //                              dlg_dip.cpp:704 (14)
    //         0043e3bd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e3c3     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e3c8     MOV        EDX,dword ptr [EAX + 0x50]
    //                              dlg_dip.cpp:705 (22)
    //         0043e3cb     FLD        float ptr [EDX + 0x8]
    //         0043e3ce     FSUB       float ptr [ESI + 0x61c]
    //         0043e3d4     FDIV       float ptr [ESP + tc]
    //         0043e3d8     FLD        ST0
    //         0043e3da     FADD       float ptr [ESI + EDI*0x4 + 0x66c]
    //                              dlg_dip.cpp:706 (21)
    //         0043e3e1     FXCH
    //         0043e3e3     FMUL       float ptr [ESP + tc]
    //         0043e3e7     FXCH
    //         0043e3e9     FSTP       float ptr [ESI + EDI*0x4 + 0x66c]
    //         0043e3f0     FADD       float ptr [ESI + 0x61c]
    //                              dlg_dip.cpp:708 (2)
    //         0043e3f6     JMP        LAB_0043e41e
    //                               LAB_0043e3f8                                                 XREF[1]:     0043e3bb(j)  
    //                              dlg_dip.cpp:711 (13)
    //         0043e3f8     FLD        float ptr [ESI + EDI*0x4 + 0x66c]
    //         0043e3ff     FSUB       float ptr [DAT_0056f894]
    //                              dlg_dip.cpp:712 (31)
    //         0043e405     FLD        float ptr [ESP + tc]
    //         0043e409     FMUL       float ptr [DAT_0056f894]
    //         0043e40f     FXCH
    //         0043e411     FSTP       float ptr [ESI + EDI*0x4 + 0x66c]
    //         0043e418     FSUBR      float ptr [ESI + 0x61c]
    //                               LAB_0043e41e                                                 XREF[1]:     0043e3f6(j)  
    //         0043e41e     FSTP       float ptr [ESI + 0x61c]
    //                              dlg_dip.cpp:714 (23)
    //         0043e424     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e42a     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e42f     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e432     FLD        float ptr [EAX + 0x8]
    //         0043e435     FSUB       float ptr [ESI + 0x61c]
    //                              dlg_dip.cpp:715 (21)
    //         0043e43b     CALL       __ftol                                           undefined __ftol()
    //         0043e440     PUSH       EAX
    //         0043e441     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043e445     PUSH       s_%ld                                            = "%ld"
    //         0043e44a     PUSH       this
    //         0043e44b     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:716 (22)
    //         0043e450     MOV        this,dword ptr [ESI + 0x62c]
    //         0043e456     ADD        ESP,0xc
    //         0043e459     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043e45d     MOV        EDX,dword ptr [this->_padding_]
    //         0043e45f     PUSH       EAX
    //         0043e460     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:717 (28)
    //         0043e466     FLD        float ptr [ESI + EDI*0x4 + 0x66c]
    //         0043e46d     CALL       __ftol                                           undefined __ftol()
    //         0043e472     PUSH       EAX
    //         0043e473     LEA        this,[ESP + 0x1c]
    //         0043e477     PUSH       s_%ld                                            = "%ld"
    //         0043e47c     PUSH       this=>DAT_fffffff4
    //         0043e47d     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:718 (22)
    //         0043e482     MOV        this,dword ptr [ESI + EBX*0x4 + 0x574]
    //         0043e489     ADD        ESP,0xc
    //         0043e48c     LEA        EDX,[ESP + 0x18]
    //         0043e490     PUSH       EDX
    //         0043e491     PUSH       0x0=>DAT_fffffff8
    //         0043e493     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
    //                              dlg_dip.cpp:729 (7)
    //         0043e498     MOV        this,ESI
    //         0043e49a     CALL       TribeDiplomacyDialog::check_stone                int check_stone(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:730 (5)
    //         0043e49f     MOV        EAX,0x1
    //                              dlg_dip.cpp:738 (13)
    //         0043e4a4     POP        EDI
    //         0043e4a5     POP        ESI
    //         0043e4a6     POP        EBP
    //         0043e4a7     POP        EBX
    //         0043e4a8     ADD        ESP,0x108
    //         0043e4ae     RET        0x10
    //                               LAB_0043e4b1                                                 XREF[1]:     0043e37b(j)  
    //                              dlg_dip.cpp:722 (23)
    //         0043e4b1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e4b7     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e4bc     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e4bf     FLD        float ptr [EAX + 0x8]
    //         0043e4c2     FSUB       float ptr [ESI + 0x61c]
    //                              dlg_dip.cpp:723 (15)
    //         0043e4c8     FCOM       float ptr [DAT_0056f884]
    //         0043e4ce     FNSTSW     AX
    //         0043e4d0     TEST       AH,0x1
    //         0043e4d3     JZ         LAB_0043e4dd
    //         0043e4d5     FSTP       ST0
    //                              dlg_dip.cpp:724 (6)
    //         0043e4d7     FLD        float ptr [DAT_0056f884]
    //                               LAB_0043e4dd                                                 XREF[1]:     0043e4d3(j)  
    //                              dlg_dip.cpp:725 (21)
    //         0043e4dd     CALL       __ftol                                           undefined __ftol()
    //         0043e4e2     PUSH       EAX
    //         0043e4e3     LEA        this=>temp_str[4],[ESP + 0x1c]
    //         0043e4e7     PUSH       s_%ld                                            = "%ld"
    //         0043e4ec     PUSH       this
    //         0043e4ed     CALL       sprintf                                          undefined sprintf()
    //                              dlg_dip.cpp:726 (22)
    //         0043e4f2     MOV        this,dword ptr [ESI + 0x62c]
    //         0043e4f8     ADD        ESP,0xc
    //         0043e4fb     LEA        EAX=>temp_str[4],[ESP + 0x18]
    //         0043e4ff     MOV        EDX,dword ptr [this->_padding_]
    //         0043e501     PUSH       EAX
    //         0043e502     CALL       dword ptr [EDX + 0xe8]
    //                              dlg_dip.cpp:729 (7)
    //         0043e508     MOV        this,ESI
    //         0043e50a     CALL       TribeDiplomacyDialog::check_stone                int check_stone(TribeDiplomacyDialog * this)
    //                              dlg_dip.cpp:738 (18)
    //         0043e50f     POP        EDI
    //         0043e510     POP        ESI
    //         0043e511     POP        EBP
    //         0043e512     MOV        EAX,0x1
    //         0043e517     POP        EBX
    //         0043e518     ADD        ESP,0x108
    //         0043e51e     RET        0x10
    //         0043e521     ??         90h
    //         0043e522     NOP
    //         0043e523     NOP
    //         0043e524     NOP
    //         0043e525     NOP
    //         0043e526     NOP
    //         0043e527     NOP
    //         0043e528     NOP
    //         0043e529     NOP
    //         0043e52a     NOP
    //         0043e52b     NOP
    //         0043e52c     NOP
    //         0043e52d     NOP
    //         0043e52e     NOP
    //         0043e52f     NOP
}

int TribeDiplomacyDialog::check_gold() {
    /* TODO: Stub */
    //                              int __thiscall check_gold(TribeDiplomacyDialog * this)
    //              int               EAX:4          <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //                               ?check_gold@TribeDiplomacyDialog@@IAEHXZ                     XREF[5]:     TribeDiplomacyDialog:0043d61b(c), 
    //                               TribeDiplomacyDialog::check_gold                                          action:0043dd84(c), 
    //                                                                                                         action:0043de6b(c), 
    //                                                                                                         action:0043df91(c), 
    //                                                                                                         action:0043e001(c)  
    //                              dlg_dip.cpp:744 (3)
    //         0043e530     PUSH       EBX
    //         0043e531     MOV        EBX,this
    //                              dlg_dip.cpp:750 (48)
    //         0043e533     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e539     PUSH       EBP
    //         0043e53a     PUSH       ESI
    //         0043e53b     PUSH       EDI
    //         0043e53c     CMP        dword ptr [ECX + this->_padding_],0x5
    //         0043e543     JZ         LAB_0043e567
    //         0043e545     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e54a     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e54d     FLD        float ptr [EAX + 0xc]
    //         0043e550     FSUB       float ptr [EBX + 0x618]
    //         0043e556     FCOMP      float ptr [DAT_0056f884]
    //         0043e55c     FNSTSW     AX
    //         0043e55e     TEST       AH,0x41
    //         0043e561     JNZ        LAB_0043e567
    //                              dlg_dip.cpp:753 (4)
    //         0043e563     XOR        EBP,EBP
    //         0043e565     JMP        LAB_0043e56c
    //                               LAB_0043e567                                                 XREF[2]:     0043e543(j), 0043e561(j)  
    //                              dlg_dip.cpp:751 (5)
    //         0043e567     MOV        EBP,0x1
    //                               LAB_0043e56c                                                 XREF[1]:     0043e565(j)  
    //                              dlg_dip.cpp:755 (8)
    //         0043e56c     XOR        EDI,EDI
    //         0043e56e     LEA        ESI,[EBX + 0x514]
    //                               LAB_0043e574                                                 XREF[1]:     0043e5af(j)  
    //                              dlg_dip.cpp:757 (6)
    //         0043e574     MOV        this,dword ptr [ESI]
    //         0043e576     TEST       this,this
    //         0043e578     JZ         LAB_0043e5a8
    //                              dlg_dip.cpp:759 (8)
    //         0043e57a     CMP        EDI,dword ptr [EBX + 0x6b0]
    //         0043e580     JNZ        LAB_0043e586
    //                              dlg_dip.cpp:760 (2)
    //         0043e582     PUSH       0x1
    //                              dlg_dip.cpp:761 (2)
    //         0043e584     JMP        LAB_0043e587
    //                               LAB_0043e586                                                 XREF[1]:     0043e580(j)  
    //                              dlg_dip.cpp:762 (6)
    //         0043e586     PUSH       EBP
    //                               LAB_0043e587                                                 XREF[1]:     0043e584(j)  
    //         0043e587     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              dlg_dip.cpp:764 (6)
    //         0043e58c     MOV        EAX,dword ptr [EBX + 0x6b4]
    //                              dlg_dip.cpp:765 (13)
    //         0043e592     MOV        this,dword ptr [ESI]
    //         0043e594     TEST       EAX,EAX
    //         0043e596     JZ         LAB_0043e5a1
    //         0043e598     MOV        EDX,dword ptr [this->_padding_]
    //         0043e59a     PUSH       0x1
    //         0043e59c     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:766 (2)
    //         0043e59f     JMP        LAB_0043e5a8
    //                               LAB_0043e5a1                                                 XREF[1]:     0043e596(j)  
    //                              dlg_dip.cpp:767 (16)
    //         0043e5a1     MOV        EAX,dword ptr [this->_padding_]
    //         0043e5a3     PUSH       0x0
    //         0043e5a5     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0043e5a8                                                 XREF[2]:     0043e578(j), 0043e59f(j)  
    //         0043e5a8     INC        EDI
    //         0043e5a9     ADD        ESI,0x4
    //         0043e5ac     CMP        EDI,0x8
    //         0043e5af     JL         LAB_0043e574
    //                              dlg_dip.cpp:771 (7)
    //         0043e5b1     POP        EDI
    //         0043e5b2     MOV        EAX,EBP
    //         0043e5b4     POP        ESI
    //         0043e5b5     POP        EBP
    //         0043e5b6     POP        EBX
    //         0043e5b7     RET
    //         0043e5b8     ??         90h
    //         0043e5b9     NOP
    //         0043e5ba     NOP
    //         0043e5bb     NOP
    //         0043e5bc     NOP
    //         0043e5bd     NOP
    //         0043e5be     NOP
    //         0043e5bf     NOP
    return 0;
}

int TribeDiplomacyDialog::check_wood() {
    /* TODO: Stub */
    //                              int __thiscall check_wood(TribeDiplomacyDialog * this)
    //              int               EAX:4          <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //                               ?check_wood@TribeDiplomacyDialog@@IAEHXZ                     XREF[5]:     TribeDiplomacyDialog:0043d622(c), 
    //                               TribeDiplomacyDialog::check_wood                                          action:0043dd8b(c), 
    //                                                                                                         action:0043e01a(c), 
    //                                                                                                         action:0043e140(c), 
    //                                                                                                         action:0043e1b0(c)  
    //                              dlg_dip.cpp:777 (3)
    //         0043e5c0     PUSH       EBX
    //         0043e5c1     MOV        EBX,this
    //                              dlg_dip.cpp:783 (48)
    //         0043e5c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e5c9     PUSH       EBP
    //         0043e5ca     PUSH       ESI
    //         0043e5cb     PUSH       EDI
    //         0043e5cc     CMP        dword ptr [ECX + this->_padding_],0x5
    //         0043e5d3     JZ         LAB_0043e5f7
    //         0043e5d5     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e5da     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e5dd     FLD        float ptr [EAX + 0x4]
    //         0043e5e0     FSUB       float ptr [EBX + 0x614]
    //         0043e5e6     FCOMP      float ptr [DAT_0056f884]
    //         0043e5ec     FNSTSW     AX
    //         0043e5ee     TEST       AH,0x41
    //         0043e5f1     JNZ        LAB_0043e5f7
    //                              dlg_dip.cpp:786 (4)
    //         0043e5f3     XOR        EBP,EBP
    //         0043e5f5     JMP        LAB_0043e5fc
    //                               LAB_0043e5f7                                                 XREF[2]:     0043e5d3(j), 0043e5f1(j)  
    //                              dlg_dip.cpp:784 (5)
    //         0043e5f7     MOV        EBP,0x1
    //                               LAB_0043e5fc                                                 XREF[1]:     0043e5f5(j)  
    //                              dlg_dip.cpp:788 (8)
    //         0043e5fc     XOR        EDI,EDI
    //         0043e5fe     LEA        ESI,[EBX + 0x534]
    //                               LAB_0043e604                                                 XREF[1]:     0043e63f(j)  
    //                              dlg_dip.cpp:790 (6)
    //         0043e604     MOV        this,dword ptr [ESI]
    //         0043e606     TEST       this,this
    //         0043e608     JZ         LAB_0043e638
    //                              dlg_dip.cpp:792 (8)
    //         0043e60a     CMP        EDI,dword ptr [EBX + 0x6b0]
    //         0043e610     JNZ        LAB_0043e616
    //                              dlg_dip.cpp:793 (2)
    //         0043e612     PUSH       0x1
    //                              dlg_dip.cpp:794 (2)
    //         0043e614     JMP        LAB_0043e617
    //                               LAB_0043e616                                                 XREF[1]:     0043e610(j)  
    //                              dlg_dip.cpp:795 (6)
    //         0043e616     PUSH       EBP
    //                               LAB_0043e617                                                 XREF[1]:     0043e614(j)  
    //         0043e617     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              dlg_dip.cpp:797 (6)
    //         0043e61c     MOV        EAX,dword ptr [EBX + 0x6b4]
    //                              dlg_dip.cpp:798 (13)
    //         0043e622     MOV        this,dword ptr [ESI]
    //         0043e624     TEST       EAX,EAX
    //         0043e626     JZ         LAB_0043e631
    //         0043e628     MOV        EDX,dword ptr [this->_padding_]
    //         0043e62a     PUSH       0x1
    //         0043e62c     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:799 (2)
    //         0043e62f     JMP        LAB_0043e638
    //                               LAB_0043e631                                                 XREF[1]:     0043e626(j)  
    //                              dlg_dip.cpp:800 (16)
    //         0043e631     MOV        EAX,dword ptr [this->_padding_]
    //         0043e633     PUSH       0x0
    //         0043e635     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0043e638                                                 XREF[2]:     0043e608(j), 0043e62f(j)  
    //         0043e638     INC        EDI
    //         0043e639     ADD        ESI,0x4
    //         0043e63c     CMP        EDI,0x8
    //         0043e63f     JL         LAB_0043e604
    //                              dlg_dip.cpp:805 (7)
    //         0043e641     POP        EDI
    //         0043e642     MOV        EAX,EBP
    //         0043e644     POP        ESI
    //         0043e645     POP        EBP
    //         0043e646     POP        EBX
    //         0043e647     RET
    //         0043e648     ??         90h
    //         0043e649     NOP
    //         0043e64a     NOP
    //         0043e64b     NOP
    //         0043e64c     NOP
    //         0043e64d     NOP
    //         0043e64e     NOP
    //         0043e64f     NOP
    return 0;
}

int TribeDiplomacyDialog::check_food() {
    /* TODO: Stub */
    //                              int __thiscall check_food(TribeDiplomacyDialog * this)
    //              int               EAX:4          <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //                               ?check_food@TribeDiplomacyDialog@@IAEHXZ                     XREF[5]:     TribeDiplomacyDialog:0043d629(c), 
    //                               TribeDiplomacyDialog::check_food                                          action:0043dd99(c), 
    //                                                                                                         action:0043e1c9(c), 
    //                                                                                                         action:0043e2ec(c), 
    //                                                                                                         action:0043e35b(c)  
    //                              dlg_dip.cpp:811 (3)
    //         0043e650     PUSH       EBX
    //         0043e651     MOV        EBX,this
    //                              dlg_dip.cpp:818 (47)
    //         0043e653     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e659     PUSH       EBP
    //         0043e65a     PUSH       ESI
    //         0043e65b     PUSH       EDI
    //         0043e65c     CMP        dword ptr [ECX + this->_padding_],0x5
    //         0043e663     JZ         LAB_0043e686
    //         0043e665     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e66a     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e66d     FLD        float ptr [EAX]
    //         0043e66f     FSUB       float ptr [EBX + 0x610]
    //         0043e675     FCOMP      float ptr [DAT_0056f884]
    //         0043e67b     FNSTSW     AX
    //         0043e67d     TEST       AH,0x41
    //         0043e680     JNZ        LAB_0043e686
    //                              dlg_dip.cpp:821 (4)
    //         0043e682     XOR        EBP,EBP
    //         0043e684     JMP        LAB_0043e68b
    //                               LAB_0043e686                                                 XREF[2]:     0043e663(j), 0043e680(j)  
    //                              dlg_dip.cpp:819 (5)
    //         0043e686     MOV        EBP,0x1
    //                               LAB_0043e68b                                                 XREF[1]:     0043e684(j)  
    //                              dlg_dip.cpp:823 (8)
    //         0043e68b     XOR        EDI,EDI
    //         0043e68d     LEA        ESI,[EBX + 0x554]
    //                               LAB_0043e693                                                 XREF[1]:     0043e6ce(j)  
    //                              dlg_dip.cpp:825 (6)
    //         0043e693     MOV        this,dword ptr [ESI]
    //         0043e695     TEST       this,this
    //         0043e697     JZ         LAB_0043e6c7
    //                              dlg_dip.cpp:827 (8)
    //         0043e699     CMP        EDI,dword ptr [EBX + 0x6b0]
    //         0043e69f     JNZ        LAB_0043e6a5
    //                              dlg_dip.cpp:828 (2)
    //         0043e6a1     PUSH       0x1
    //                              dlg_dip.cpp:829 (2)
    //         0043e6a3     JMP        LAB_0043e6a6
    //                               LAB_0043e6a5                                                 XREF[1]:     0043e69f(j)  
    //                              dlg_dip.cpp:830 (6)
    //         0043e6a5     PUSH       EBP
    //                               LAB_0043e6a6                                                 XREF[1]:     0043e6a3(j)  
    //         0043e6a6     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              dlg_dip.cpp:832 (6)
    //         0043e6ab     MOV        EAX,dword ptr [EBX + 0x6b4]
    //                              dlg_dip.cpp:833 (13)
    //         0043e6b1     MOV        this,dword ptr [ESI]
    //         0043e6b3     TEST       EAX,EAX
    //         0043e6b5     JZ         LAB_0043e6c0
    //         0043e6b7     MOV        EDX,dword ptr [this->_padding_]
    //         0043e6b9     PUSH       0x1
    //         0043e6bb     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:834 (2)
    //         0043e6be     JMP        LAB_0043e6c7
    //                               LAB_0043e6c0                                                 XREF[1]:     0043e6b5(j)  
    //                              dlg_dip.cpp:835 (16)
    //         0043e6c0     MOV        EAX,dword ptr [this->_padding_]
    //         0043e6c2     PUSH       0x0
    //         0043e6c4     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0043e6c7                                                 XREF[2]:     0043e697(j), 0043e6be(j)  
    //         0043e6c7     INC        EDI
    //         0043e6c8     ADD        ESI,0x4
    //         0043e6cb     CMP        EDI,0x8
    //         0043e6ce     JL         LAB_0043e693
    //                              dlg_dip.cpp:840 (7)
    //         0043e6d0     POP        EDI
    //         0043e6d1     MOV        EAX,EBP
    //         0043e6d3     POP        ESI
    //         0043e6d4     POP        EBP
    //         0043e6d5     POP        EBX
    //         0043e6d6     RET
    //         0043e6d7     ??         90h
    //         0043e6d8     NOP
    //         0043e6d9     NOP
    //         0043e6da     NOP
    //         0043e6db     NOP
    //         0043e6dc     NOP
    //         0043e6dd     NOP
    //         0043e6de     NOP
    //         0043e6df     NOP
    return 0;
}

int TribeDiplomacyDialog::check_stone() {
    /* TODO: Stub */
    //                              int __thiscall check_stone(TribeDiplomacyDialog * this)
    //              int               EAX:4          <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //                               ?check_stone@TribeDiplomacyDialog@@IAEHXZ                    XREF[5]:     TribeDiplomacyDialog:0043d630(c), 
    //                               TribeDiplomacyDialog::check_stone                                         action:0043dd92(c), 
    //                                                                                                         action:0043e374(c), 
    //                                                                                                         action:0043e49a(c), 
    //                                                                                                         action:0043e50a(c)  
    //                              dlg_dip.cpp:846 (3)
    //         0043e6e0     PUSH       EBX
    //         0043e6e1     MOV        EBX,this
    //                              dlg_dip.cpp:852 (48)
    //         0043e6e3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0043e6e9     PUSH       EBP
    //         0043e6ea     PUSH       ESI
    //         0043e6eb     PUSH       EDI
    //         0043e6ec     CMP        dword ptr [ECX + this->_padding_],0x5
    //         0043e6f3     JZ         LAB_0043e717
    //         0043e6f5     CALL       RGE_Base_Game::get_player                        RGE_Player * get_player(RGE_Base_Game * this)
    //         0043e6fa     MOV        EAX,dword ptr [EAX + 0x50]
    //         0043e6fd     FLD        float ptr [EAX + 0x8]
    //         0043e700     FSUB       float ptr [EBX + 0x61c]
    //         0043e706     FCOMP      float ptr [DAT_0056f884]
    //         0043e70c     FNSTSW     AX
    //         0043e70e     TEST       AH,0x41
    //         0043e711     JNZ        LAB_0043e717
    //                              dlg_dip.cpp:855 (4)
    //         0043e713     XOR        EBP,EBP
    //         0043e715     JMP        LAB_0043e71c
    //                               LAB_0043e717                                                 XREF[2]:     0043e6f3(j), 0043e711(j)  
    //                              dlg_dip.cpp:853 (5)
    //         0043e717     MOV        EBP,0x1
    //                               LAB_0043e71c                                                 XREF[1]:     0043e715(j)  
    //                              dlg_dip.cpp:857 (8)
    //         0043e71c     XOR        EDI,EDI
    //         0043e71e     LEA        ESI,[EBX + 0x574]
    //                               LAB_0043e724                                                 XREF[1]:     0043e75f(j)  
    //                              dlg_dip.cpp:859 (6)
    //         0043e724     MOV        this,dword ptr [ESI]
    //         0043e726     TEST       this,this
    //         0043e728     JZ         LAB_0043e758
    //                              dlg_dip.cpp:861 (8)
    //         0043e72a     CMP        EDI,dword ptr [EBX + 0x6b0]
    //         0043e730     JNZ        LAB_0043e736
    //                              dlg_dip.cpp:862 (2)
    //         0043e732     PUSH       0x1
    //                              dlg_dip.cpp:863 (2)
    //         0043e734     JMP        LAB_0043e737
    //                               LAB_0043e736                                                 XREF[1]:     0043e730(j)  
    //                              dlg_dip.cpp:864 (6)
    //         0043e736     PUSH       EBP
    //                               LAB_0043e737                                                 XREF[1]:     0043e734(j)  
    //         0043e737     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              dlg_dip.cpp:866 (6)
    //         0043e73c     MOV        EAX,dword ptr [EBX + 0x6b4]
    //                              dlg_dip.cpp:867 (13)
    //         0043e742     MOV        this,dword ptr [ESI]
    //         0043e744     TEST       EAX,EAX
    //         0043e746     JZ         LAB_0043e751
    //         0043e748     MOV        EDX,dword ptr [this->_padding_]
    //         0043e74a     PUSH       0x1
    //         0043e74c     CALL       dword ptr [EDX + 0x14]
    //                              dlg_dip.cpp:868 (2)
    //         0043e74f     JMP        LAB_0043e758
    //                               LAB_0043e751                                                 XREF[1]:     0043e746(j)  
    //                              dlg_dip.cpp:869 (16)
    //         0043e751     MOV        EAX,dword ptr [this->_padding_]
    //         0043e753     PUSH       0x0
    //         0043e755     CALL       dword ptr [EAX + 0x14]
    //                               LAB_0043e758                                                 XREF[2]:     0043e728(j), 0043e74f(j)  
    //         0043e758     INC        EDI
    //         0043e759     ADD        ESI,0x4
    //         0043e75c     CMP        EDI,0x8
    //         0043e75f     JL         LAB_0043e724
    //                              dlg_dip.cpp:874 (7)
    //         0043e761     POP        EDI
    //         0043e762     MOV        EAX,EBP
    //         0043e764     POP        ESI
    //         0043e765     POP        EBP
    //         0043e766     POP        EBX
    //         0043e767     RET
    //         0043e768     ??         90h
    //         0043e769     NOP
    //         0043e76a     NOP
    //         0043e76b     NOP
    //         0043e76c     NOP
    //         0043e76d     NOP
    //         0043e76e     NOP
    //         0043e76f     NOP
    return 0;
}

void TribeDiplomacyDialog::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TribeDiplomacyDialog * this)
    //              void              <VOID>         <RETURN>
    //              TribeDiplomacy    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0043e79e(W)  
    //                               ?draw@TribeDiplomacyDialog@@MAEXXZ                           XREF[1]:     0056f8c8(*)  
    //                               TribeDiplomacyDialog::draw
    //                              dlg_dip.cpp:880 (7)
    //         0043e770     SUB        ESP,0x8
    //         0043e773     PUSH       EBP
    //         0043e774     PUSH       ESI
    //         0043e775     MOV        ESI,this
    //                              dlg_dip.cpp:884 (5)
    //         0043e777     CALL       TEasy_Panel::draw                                void draw(TEasy_Panel * this)
    //                              dlg_dip.cpp:886 (16)
    //         0043e77c     MOV        EAX,dword ptr [ESI + 0x60c]
    //         0043e782     XOR        EBP,EBP
    //         0043e784     CMP        EAX,EBP
    //         0043e786     JZ         LAB_0043e82d
    //                              dlg_dip.cpp:888 (7)
    //         0043e78c     MOV        EAX,[rge_base_game]                              = 00000000
    //         0043e791     PUSH       EDI
    //         0043e792     PUSH       EBX
    //                              dlg_dip.cpp:890 (18)
    //         0043e793     MOV        EBX,dword ptr [ESI]
    //         0043e795     MOV        EDI,dword ptr [EAX + 0x3f4]
    //         0043e79b     PUSH       EBP
    //         0043e79c     MOV        this,ESI
    //         0043e79e     MOV        dword ptr [ESP + local_4],EBX
    //         0043e7a2     CALL       dword ptr [EBX + 0x28]
    //                              dlg_dip.cpp:891 (9)
    //         0043e7a5     MOVSX      this,word ptr [EDI + 0x3c]
    //         0043e7a9     DEC        this
    //         0043e7aa     TEST       this,this
    //         0043e7ac     JLE        LAB_0043e826
    //                              dlg_dip.cpp:903 (116)
    //         0043e7ae     MOV        dword ptr [ESP + 0x10],EBP
    //         0043e7b2     MOV        EBX,0x4
    //                               LAB_0043e7b7                                                 XREF[1]:     0043e820(j)  
    //         0043e7b7     MOV        EDX,dword ptr [EDI + 0x40]
    //         0043e7ba     MOV        EAX,dword ptr [EDX + EBX*0x1]
    //         0043e7bd     MOV        EAX,dword ptr [EAX + 0x108]
    //         0043e7c3     TEST       EAX,EAX
    //         0043e7c5     JZ         LAB_0043e80a
    //         0043e7c7     MOVSX      this,word ptr [EAX + 0x26]
    //         0043e7cb     INC        this
    //         0043e7cc     SHL        this,0x4
    //         0043e7cf     PUSH       this
    //         0043e7d0     CALL       _ASMSet_Color_Xform                              undefined _ASMSet_Color_Xform()
    //         0043e7d5     MOV        EDX,dword ptr [EDI + 0x40]
    //         0043e7d8     ADD        ESP,0x4
    //         0043e7db     MOV        EAX,dword ptr [EDX + EBX*0x1]
    //         0043e7de     MOV        EDX,dword ptr [ESI + 0x10]
    //         0043e7e1     MOV        this,dword ptr [EAX + 0x108]
    //         0043e7e7     LEA        EAX,[EDX + EBP*0x1 + 0x50]
    //         0043e7eb     MOV        EDX,dword ptr [ESI + 0x20]
    //         0043e7ee     ADD        this,0x28
    //         0043e7f1     PUSH       this
    //         0043e7f2     MOV        this,dword ptr [ESI + 0xc]
    //         0043e7f5     PUSH       offset DAT_fffffff8
    //         0043e7f7     PUSH       0x0=>DAT_fffffff4
    //         0043e7f9     ADD        this,0xa
    //         0043e7fc     PUSH       EAX=>DAT_fffffff0
    //         0043e7fd     PUSH       this
    //         0043e7fe     MOV        this,dword ptr [ESI + 0x60c]
    //         0043e804     PUSH       EDX
    //         0043e805     CALL       TShape::shape_draw                               uchar shape_draw(TShape * this, TDrawArea * p
    //                               LAB_0043e80a                                                 XREF[1]:     0043e7c5(j)  
    //         0043e80a     MOVSX      this,word ptr [EDI + 0x3c]
    //         0043e80e     MOV        EAX,dword ptr [ESP + 0x10]
    //         0043e812     ADD        EBP,0x1e
    //         0043e815     ADD        EBX,0x4
    //         0043e818     INC        EAX
    //         0043e819     DEC        this
    //         0043e81a     MOV        dword ptr [ESP + 0x10],EAX
    //         0043e81e     CMP        EAX,this
    //         0043e820     JL         LAB_0043e7b7
    //                              dlg_dip.cpp:891 (4)
    //         0043e822     MOV        EBX,dword ptr [ESP + 0x14]
    //                               LAB_0043e826                                                 XREF[1]:     0043e7ac(j)  
    //                              dlg_dip.cpp:901 (7)
    //         0043e826     MOV        this,ESI
    //         0043e828     CALL       dword ptr [EBX + 0x2c]
    //         0043e82b     POP        EBX
    //         0043e82c     POP        EDI
    //                               LAB_0043e82d                                                 XREF[1]:     0043e786(j)  
    //                              dlg_dip.cpp:903 (6)
    //         0043e82d     POP        ESI
    //         0043e82e     POP        EBP
    //         0043e82f     ADD        ESP,0x8
    //         0043e832     RET
    //         0043e833     ??         90h
    //         0043e834     NOP
    //         0043e835     NOP
    //         0043e836     NOP
    //         0043e837     NOP
    //         0043e838     NOP
    //         0043e839     NOP
    //         0043e83a     NOP
    //         0043e83b     NOP
    //         0043e83c     NOP
    //         0043e83d     NOP
    //         0043e83e     NOP
    //         0043e83f     NOP
    return;
}

long TribeDiplomacyDialog::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

