// Auto-generated scaffold unit: Scr_sels.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/Scr_sels.cpp
#include "../include/common.h"

// Offset: 0x004B3C90
undefined TribeSelectScenarioScreen(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeSelectScenarioScreen::TribeSelectScenarioScreen(void)                         *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeSelectScenarioScreen(TribeSelectScenarioSc
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b3cbc(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004b3d29(R), 004b40e9(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b3cb1(W)  
    //                               ??0TribeSelectScenarioScreen@@QAE@XZ                         XREF[2]:     cancelScreen:004a2c01(c), 
    //                               TribeSelectScenarioScreen::TribeSelectScenarioScreen                      action:004b6e96(c)  
    //                              Scr_sels.cpp:66 (42)
    //         004b3c90     PUSH       -0x1
    //         004b3c92     PUSH       FUN_0055f638
    //         004b3c97     MOV        EAX,FS:[0x0]
    //         004b3c9d     PUSH       EAX
    //         004b3c9e     MOV        dword ptr FS:[0x0],ESP
    //         004b3ca5     PUSH       this
    //         004b3ca6     PUSH       EBX
    //         004b3ca7     PUSH       EBP
    //         004b3ca8     PUSH       ESI
    //         004b3ca9     PUSH       EDI
    //         004b3caa     MOV        ESI,this
    //         004b3cac     PUSH       s_Select_Scenario_Screen                         = "Select Scenario Screen"
    //         004b3cb1     MOV        dword ptr [ESP + local_10],ESI
    //         004b3cb5     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              Scr_sels.cpp:67 (21)
    //         004b3cba     MOV        this,ESI
    //         004b3cbc     MOV        dword ptr [ESP + local_4],0x0
    //         004b3cc4     MOV        dword ptr [ESI],TribeSelectScenarioScreen::`vf   = 004b4100
    //         004b3cca     CALL       TribeSelectScenarioScreen::init_vars             void init_vars(TribeSelectScenarioScreen * th
    //                              Scr_sels.cpp:70 (78)
    //         004b3ccf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3cd5     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b3cda     TEST       EAX,EAX
    //         004b3cdc     MOV        EBX,s_scr3                                       = 73h
    //         004b3ce1     JNZ        LAB_004b3ce8
    //         004b3ce3     MOV        EBX,s_scr2                                       = 73h
    //                               LAB_004b3ce8                                                 XREF[1]:     004b3ce1(j)  
    //         004b3ce8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b3cee     PUSH       0x1
    //         004b3cf0     PUSH       0x0
    //         004b3cf2     PUSH       0x0
    //         004b3cf4     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004b3cf7     PUSH       0x0
    //         004b3cf9     PUSH       0x0
    //         004b3cfb     PUSH       0x1
    //         004b3cfd     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b3d02     NEG        EAX
    //         004b3d04     SBB        EAX,EAX
    //         004b3d06     MOV        this,ESI
    //         004b3d08     NEG        EAX
    //         004b3d0a     ADD        EAX,0xc384
    //         004b3d0f     PUSH       EAX
    //         004b3d10     PUSH       EBX=>s_scr2                                      = 73h
    //         004b3d11     PUSH       0x0
    //         004b3d13     PUSH       EDI
    //         004b3d14     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
    //         004b3d19     TEST       EAX,EAX
    //         004b3d1b     JNZ        LAB_004b3d3c
    //                              Scr_sels.cpp:72 (10)
    //         004b3d1d     MOV        dword ptr [ESI + 0xd8],0x1
    //                              Scr_sels.cpp:134 (21)
    //         004b3d27     MOV        EAX,ESI
    //         004b3d29     MOV        this,dword ptr [ESP + local_c]
    //         004b3d2d     MOV        dword ptr FS:[0x0],this
    //         004b3d34     POP        EDI
    //         004b3d35     POP        ESI
    //         004b3d36     POP        EBP
    //         004b3d37     POP        EBX
    //         004b3d38     ADD        ESP,0x10
    //         004b3d3b     RET
    //                               LAB_004b3d3c                                                 XREF[1]:     004b3d1b(j)  
    //                              Scr_sels.cpp:76 (9)
    //         004b3d3c     PUSH       0x0
    //         004b3d3e     MOV        this,ESI
    //         004b3d40     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              Scr_sels.cpp:77 (17)
    //         004b3d45     PUSH       0x1e0
    //         004b3d4a     PUSH       0x280
    //         004b3d4f     MOV        this,ESI
    //         004b3d51     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              Scr_sels.cpp:80 (47)
    //         004b3d56     PUSH       0x0
    //         004b3d58     PUSH       0x0
    //         004b3d5a     PUSH       0x1
    //         004b3d5c     PUSH       0x1
    //         004b3d5e     PUSH       0x1e
    //         004b3d60     PUSH       0x258
    //         004b3d65     PUSH       0xa
    //         004b3d67     PUSH       0x14
    //         004b3d69     LEA        EAX,[ESI + 0x478]
    //                              language.dll match for 0x25fa: "Scenarios"
    //         004b3d6f     PUSH       0x25fa
    //         004b3d74     PUSH       EAX
    //         004b3d75     PUSH       ESI
    //         004b3d76     MOV        this,ESI
    //         004b3d78     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b3d7d     TEST       EAX,EAX
    //         004b3d7f     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:87 (79)
    //         004b3d85     PUSH       0xb
    //         004b3d87     PUSH       0x107
    //         004b3d8c     PUSH       0x258
    //         004b3d91     LEA        EBP,[ESI + 0x494]
    //         004b3d97     PUSH       0x46
    //         004b3d99     PUSH       0x14
    //         004b3d9b     PUSH       EBP
    //         004b3d9c     PUSH       ESI
    //         004b3d9d     MOV        this,ESI
    //         004b3d9f     MOV        dword ptr [ESI + 0x484],0x14
    //         004b3da9     MOV        dword ptr [ESI + 0x488],0x46
    //         004b3db3     MOV        dword ptr [ESI + 0x48c],0x258
    //         004b3dbd     MOV        dword ptr [ESI + 0x490],0x107
    //         004b3dc7     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         004b3dcc     TEST       EAX,EAX
    //         004b3dce     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:88 (31)
    //         004b3dd4     MOV        this,dword ptr [ESI + 0x48c]
    //         004b3dda     MOV        EAX,dword ptr [ESI + 0x14]
    //         004b3ddd     SUB        this,0x3c
    //         004b3de0     IMUL       EAX,this
    //         004b3de3     CDQ
    //         004b3de4     IDIV       dword ptr [ESI + 0xf4]
    //         004b3dea     MOV        this,dword ptr [EBP]
    //         004b3ded     PUSH       EAX
    //         004b3dee     CALL       TTextPanel::set_second_column_pos                void set_second_column_pos(TTextPanel * this,
    //                              Scr_sels.cpp:89 (16)
    //         004b3df3     MOV        this,dword ptr [EBP]
    //                              language.dll match for 0x25fd: "Loading list of scenarios..."
    //         004b3df6     PUSH       0x25fd
    //         004b3dfb     MOV        EDX,dword ptr [this->_padding_]
    //         004b3dfd     CALL       dword ptr [EDX + 0xe4]
    //                              Scr_sels.cpp:91 (28)
    //         004b3e03     MOV        EAX,dword ptr [EBP]
    //         004b3e06     LEA        EDI,[ESI + 0x498]
    //         004b3e0c     PUSH       0x14
    //         004b3e0e     PUSH       EAX=>DAT_fffffff8
    //         004b3e0f     PUSH       EDI=>DAT_fffffff4
    //         004b3e10     MOV        this,ESI
    //         004b3e12     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004b3e17     TEST       EAX,EAX
    //         004b3e19     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:92 (11)
    //         004b3e1f     MOV        this,dword ptr [EDI]
    //         004b3e21     PUSH       -0x1
    //         004b3e23     PUSH       offset DAT_fffffff8
    //         004b3e25     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              Scr_sels.cpp:94 (60)
    //         004b3e2a     MOV        this,dword ptr [ESI + 0x488]
    //         004b3e30     MOV        EDX,dword ptr [ESI + 0x484]
    //         004b3e36     PUSH       0x0
    //         004b3e38     PUSH       0x0=>DAT_fffffff8
    //         004b3e3a     PUSH       0x0=>DAT_fffffff4
    //         004b3e3c     PUSH       offset DAT_fffffff0
    //         004b3e3e     PUSH       0x14
    //         004b3e40     SUB        this,0x14
    //         004b3e43     PUSH       0x12c
    //         004b3e48     PUSH       this
    //         004b3e49     PUSH       EDX
    //         004b3e4a     LEA        EAX,[ESI + 0x47c]
    //                              language.dll match for 0x25fe: "Select Scenario"
    //         004b3e50     PUSH       0x25fe
    //         004b3e55     PUSH       EAX
    //         004b3e56     PUSH       ESI
    //         004b3e57     MOV        this,ESI
    //         004b3e59     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b3e5e     TEST       EAX,EAX
    //         004b3e60     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:96 (73)
    //         004b3e66     MOV        this,dword ptr [ESI + 0x488]
    //         004b3e6c     MOV        EDX,dword ptr [ESI + 0x48c]
    //         004b3e72     MOV        EAX,dword ptr [ESI + 0x484]
    //         004b3e78     PUSH       0x0
    //         004b3e7a     PUSH       0x0=>DAT_fffffff8
    //         004b3e7c     PUSH       0x0=>DAT_fffffff4
    //         004b3e7e     PUSH       offset DAT_fffffff0
    //         004b3e80     PUSH       0x14
    //         004b3e82     SUB        this,0x14
    //         004b3e85     PUSH       0xc8
    //         004b3e8a     PUSH       this
    //         004b3e8b     LEA        this,[EDX + EAX*0x1 + 0xffffff24]
    //         004b3e92     LEA        EDI,[ESI + 0x480]
    //         004b3e98     PUSH       this
    //                              language.dll match for 0x25ff: "Players"
    //         004b3e99     PUSH       0x25ff
    //         004b3e9e     PUSH       EDI
    //         004b3e9f     PUSH       ESI
    //         004b3ea0     MOV        this,ESI
    //         004b3ea2     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b3ea7     TEST       EAX,EAX
    //         004b3ea9     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:97 (11)
    //         004b3eaf     MOV        this,dword ptr [EDI]
    //         004b3eb1     PUSH       0x2
    //         004b3eb3     PUSH       offset DAT_fffffff8
    //         004b3eb5     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              Scr_sels.cpp:101 (18)
    //         004b3eba     MOV        EDX,dword ptr [ESI + 0x490]
    //         004b3ec0     MOV        this,dword ptr [ESI + 0x488]
    //         004b3ec6     MOV        EAX,dword ptr [ESI + 0x484]
    //                              Scr_sels.cpp:105 (86)
    //         004b3ecc     PUSH       0x0
    //         004b3ece     LEA        this,[EDX + this->_padding_*0x1 + 0x19]
    //         004b3ed2     PUSH       0x0=>DAT_fffffff8
    //         004b3ed4     MOV        EDX,dword ptr [ESI + 0x48c]
    //         004b3eda     PUSH       0x0=>DAT_fffffff4
    //         004b3edc     MOV        dword ptr [ESI + 0x4b4],this
    //         004b3ee2     PUSH       offset DAT_fffffff0
    //         004b3ee4     PUSH       0x14
    //         004b3ee6     ADD        this,-0x14
    //         004b3ee9     PUSH       0x190
    //         004b3eee     PUSH       this
    //         004b3eef     MOV        dword ptr [ESI + 0x4b0],EAX
    //         004b3ef5     PUSH       EAX
    //         004b3ef6     LEA        EAX,[ESI + 0x4ac]
    //                              language.dll match for 0x2600: "Scenario Instructions"
    //         004b3efc     PUSH       0x2600
    //         004b3f01     PUSH       EAX
    //         004b3f02     PUSH       ESI
    //         004b3f03     MOV        this,ESI
    //         004b3f05     MOV        dword ptr [ESI + 0x4b8],EDX
    //         004b3f0b     MOV        dword ptr [ESI + 0x4bc],0x3c
    //         004b3f15     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b3f1a     TEST       EAX,EAX
    //         004b3f1c     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:107 (64)
    //         004b3f22     MOV        this,dword ptr [ESI + 0x4bc]
    //         004b3f28     MOV        EDX,dword ptr [ESI + 0x4b8]
    //         004b3f2e     MOV        EAX,dword ptr [ESI + 0x4b4]
    //         004b3f34     PUSH       0x1
    //         004b3f36     PUSH       0x0=>DAT_fffffff8
    //         004b3f38     PUSH       0x0=>DAT_fffffff4
    //         004b3f3a     PUSH       offset DAT_fffffff0
    //         004b3f3c     PUSH       this
    //         004b3f3d     MOV        this,dword ptr [ESI + 0x4b0]
    //         004b3f43     PUSH       EDX
    //         004b3f44     PUSH       EAX
    //         004b3f45     LEA        EBX,[ESI + 0x4c0]
    //         004b3f4b     PUSH       this
    //         004b3f4c     PUSH       s_                                               = ""
    //         004b3f51     PUSH       EBX
    //         004b3f52     PUSH       ESI
    //         004b3f53     MOV        this,ESI
    //         004b3f55     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b3f5a     TEST       EAX,EAX
    //         004b3f5c     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:108 (66)
    //         004b3f62     XOR        EAX,EAX
    //         004b3f64     MOV        this,dword ptr [EBX]
    //         004b3f66     MOV        AL,byte ptr [ESI + 0x325]
    //         004b3f6c     PUSH       EAX
    //         004b3f6d     XOR        EAX,EAX
    //         004b3f6f     MOV        AL,byte ptr [ESI + 0x324]
    //         004b3f75     MOV        EDX,dword ptr [this->_padding_]
    //         004b3f77     PUSH       EAX=>DAT_fffffff8
    //         004b3f78     XOR        EAX,EAX
    //         004b3f7a     MOV        AL,byte ptr [ESI + 0x323]
    //         004b3f80     PUSH       EAX=>DAT_fffffff4
    //         004b3f81     XOR        EAX,EAX
    //         004b3f83     MOV        AL,byte ptr [ESI + 0x322]
    //         004b3f89     PUSH       EAX=>DAT_fffffff0
    //         004b3f8a     XOR        EAX,EAX
    //         004b3f8c     MOV        AL,byte ptr [ESI + 0x321]
    //         004b3f92     PUSH       EAX
    //         004b3f93     XOR        EAX,EAX
    //         004b3f95     MOV        AL,byte ptr [ESI + 0x320]
    //         004b3f9b     PUSH       EAX
    //         004b3f9c     PUSH       0x3
    //         004b3f9e     CALL       dword ptr [EDX + 0xec]
    //                              Scr_sels.cpp:110 (27)
    //         004b3fa4     MOV        this,dword ptr [EBX]
    //         004b3fa6     LEA        EDI,[ESI + 0x4c4]
    //         004b3fac     PUSH       0x14
    //         004b3fae     PUSH       this=>DAT_fffffff8
    //         004b3faf     PUSH       EDI=>DAT_fffffff4
    //         004b3fb0     MOV        this,ESI
    //         004b3fb2     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004b3fb7     TEST       EAX,EAX
    //         004b3fb9     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:111 (14)
    //         004b3fbf     MOV        this,dword ptr [EDI]
    //         004b3fc1     PUSH       -0x1
    //         004b3fc3     PUSH       offset DAT_fffffff8
    //         004b3fc8     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              Scr_sels.cpp:114 (50)
    //         004b3fcd     PUSH       0x0
    //         004b3fcf     PUSH       0x0=>DAT_fffffff8
    //         004b3fd1     PUSH       0x0=>DAT_fffffff4
    //         004b3fd3     PUSH       offset DAT_fffffff0
    //         004b3fd5     PUSH       0xf0
    //         004b3fda     PUSH       0x1b8
    //         004b3fdf     PUSH       0x46
    //         004b3fe1     LEA        EDI,[ESI + 0x4c8]
    //         004b3fe7     PUSH       0x0
    //                              language.dll match for 0xfa1: "OK"
    //         004b3fe9     PUSH       0xfa1
    //         004b3fee     PUSH       EDI
    //         004b3fef     PUSH       ESI
    //         004b3ff0     MOV        this,ESI
    //         004b3ff2     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b3ff7     TEST       EAX,EAX
    //         004b3ff9     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:115 (14)
    //         004b3fff     MOV        this,dword ptr [EDI]
    //         004b4001     PUSH       -0x1
    //         004b4003     PUSH       offset DAT_fffffff8
    //         004b4008     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              Scr_sels.cpp:116 (53)
    //         004b400d     PUSH       0x0
    //         004b400f     PUSH       0x0=>DAT_fffffff8
    //         004b4011     PUSH       0x0=>DAT_fffffff4
    //         004b4013     PUSH       offset DAT_fffffff0
    //         004b4015     PUSH       0xf0
    //         004b401a     PUSH       0x1b8
    //         004b401f     PUSH       0x14a
    //         004b4024     LEA        EDI,[ESI + 0x4cc]
    //         004b402a     PUSH       0x0
    //                              language.dll match for 0xfa2: "Cancel"
    //         004b402c     PUSH       0xfa2
    //         004b4031     PUSH       EDI
    //         004b4032     PUSH       ESI
    //         004b4033     MOV        this,ESI
    //         004b4035     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b403a     TEST       EAX,EAX
    //         004b403c     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:117 (14)
    //         004b4042     MOV        this,dword ptr [EDI]
    //         004b4044     PUSH       -0x1
    //         004b4046     PUSH       offset DAT_fffffff8
    //         004b404b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              Scr_sels.cpp:118 (2)
    //         004b4050     MOV        EDI,dword ptr [EDI]
    //                              Scr_sels.cpp:121 (60)
    //         004b4052     PUSH       0x0
    //         004b4054     PUSH       offset DAT_fffffff8
    //         004b4056     PUSH       offset DAT_fffffff4
    //         004b4058     PUSH       0x0=>DAT_fffffff0
    //         004b405a     PUSH       0x0
    //         004b405c     PUSH       0x0
    //         004b405e     MOV        dword ptr [EDI + 0x298],0x1b
    //         004b4068     MOV        dword ptr [EDI + 0x29c],0x0
    //         004b4072     PUSH       0x0
    //         004b4074     LEA        EDI,[ESI + 0x4d0]
    //         004b407a     PUSH       0x0
    //                              language.dll match for 0x3ea: "X"
    //         004b407c     PUSH       0x3ea
    //         004b4081     PUSH       EDI
    //         004b4082     PUSH       ESI
    //         004b4083     MOV        this,ESI
    //         004b4085     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b408a     TEST       EAX,EAX
    //         004b408c     JZ         LAB_004b40e9
    //                              Scr_sels.cpp:122 (9)
    //         004b408e     MOV        this,dword ptr [EDI]
    //         004b4090     PUSH       0x1
    //         004b4092     MOV        EDX,dword ptr [this->_padding_]
    //         004b4094     CALL       dword ptr [EDX + 0x14]
    //                              Scr_sels.cpp:123 (33)
    //         004b4097     MOV        this,dword ptr [EDI]
    //         004b4099     PUSH       0x0
    //         004b409b     PUSH       0x0=>DAT_fffffff8
    //         004b409d     PUSH       0x0=>DAT_fffffff4
    //         004b409f     MOV        EAX,dword ptr [this->_padding_]
    //         004b40a1     PUSH       0x0=>DAT_fffffff0
    //         004b40a3     PUSH       0x11
    //         004b40a5     PUSH       0x11
    //         004b40a7     PUSH       0x11
    //         004b40a9     PUSH       0x11
    //         004b40ab     PUSH       0x4
    //         004b40ad     PUSH       0x4
    //         004b40af     PUSH       0x4
    //         004b40b1     PUSH       0x4
    //         004b40b3     PUSH       0x9
    //         004b40b5     CALL       dword ptr [EAX + 0x18]
    //                              Scr_sels.cpp:126 (7)
    //         004b40b8     MOV        this,ESI
    //         004b40ba     CALL       TribeSelectScenarioScreen::fillScenarios         void fillScenarios(TribeSelectScenarioScreen 
    //                              Scr_sels.cpp:129 (17)
    //         004b40bf     MOV        this,ESI
    //         004b40c1     MOV        dword ptr [ESI + 0x4a8],0x1
    //         004b40cb     CALL       TribeSelectScenarioScreen::getSettings           void getSettings(TribeSelectScenarioScreen * 
    //                              Scr_sels.cpp:130 (7)
    //         004b40d0     MOV        this,ESI
    //         004b40d2     CALL       TribeSelectScenarioScreen::fillMissionText       void fillMissionText(TribeSelectScenarioScree
    //                              Scr_sels.cpp:132 (7)
    //         004b40d7     MOV        this,ESI
    //         004b40d9     CALL       TribeSelectScenarioScreen::activatePanels        void activatePanels(TribeSelectScenarioScreen
    //                              Scr_sels.cpp:133 (11)
    //         004b40de     MOV        this,dword ptr [EBP]
    //         004b40e1     PUSH       this
    //         004b40e2     MOV        this,ESI
    //         004b40e4     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b40e9                                                 XREF[11]:    004b3d7f(j), 004b3dce(j), 
    //                                                                                                         004b3e19(j), 004b3e60(j), 
    //                                                                                                         004b3ea9(j), 004b3f1c(j), 
    //                                                                                                         004b3f5c(j), 004b3fb9(j), 
    //                                                                                                         004b3ff9(j), 004b403c(j), 
    //                                                                                                         004b408c(j)  
    //                              Scr_sels.cpp:134 (21)
    //         004b40e9     MOV        this,dword ptr [ESP + local_c]
    //         004b40ed     MOV        EAX,ESI
    //         004b40ef     POP        EDI
    //         004b40f0     POP        ESI
    //         004b40f1     POP        EBP
    //         004b40f2     MOV        dword ptr FS:[0x0],this
    //         004b40f9     POP        EBX
    //         004b40fa     ADD        ESP,0x10
    //         004b40fd     RET
}

// Offset: 0x004B4120
void init_vars(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSelectScenarioScreen::init_vars(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall init_vars(TribeSelectScenarioScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //                               ?init_vars@TribeSelectScenarioScreen@@IAEXXZ                 XREF[1]:     TribeSelectScenarioScreen:004b3cca
    //                               TribeSelectScenarioScreen::init_vars
    //                              Scr_sels.cpp:140 (2)
    //         004b4120     XOR        EAX,EAX
    //                              Scr_sels.cpp:160 (100)
    //         004b4122     MOV        dword ptr [ECX + this->last_scenario_line],0xf
    //         004b412c     MOV        dword ptr [ECX + this->title],EAX
    //         004b4132     MOV        dword ptr [ECX + this->scenarioTitle],EAX
    //         004b4138     MOV        dword ptr [ECX + this->scenarioPlayersTitle],EAX
    //         004b413e     MOV        dword ptr [ECX + this->scenarioList],EAX
    //         004b4144     MOV        dword ptr [ECX + this->scenarioScrollbar],EAX
    //         004b414a     MOV        dword ptr [ECX + this->scenarioCount],EAX
    //         004b4150     MOV        dword ptr [ECX + this->scenarioMission],EAX
    //         004b4156     MOV        dword ptr [ECX + this->scenarioFixed],EAX
    //         004b415c     MOV        dword ptr [ECX + this->scenariosLoaded],EAX
    //         004b4162     MOV        dword ptr [ECX + this->missionTitle],EAX
    //         004b4168     MOV        dword ptr [ECX + this->missionText],EAX
    //         004b416e     MOV        dword ptr [ECX + this->missionScrollbar],EAX
    //         004b4174     MOV        dword ptr [ECX + this->okButton],EAX
    //         004b417a     MOV        dword ptr [ECX + this->cancelButton],EAX
    //         004b4180     MOV        dword ptr [ECX + this->close_button],EAX
    //                              Scr_sels.cpp:161 (1)
    //         004b4186     RET
}

// Offset: 0x004B4190
void TribeSelectScenarioScreen(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeSelectScenarioScreen::~TribeSelectScenarioScreen(void)                *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeSelectScenarioScreen(TribeSelectScenarioScreen
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b41b9(W), 004b4255(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b4262(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b41a9(W)  
    //                               ??1TribeSelectScenarioScreen@@UAE@XZ                         XREF[1]:     `scalar_deleting_destructor':004b4
    //                               TribeSelectScenarioScreen::~TribeSelectScenarioScreen
    //                              Scr_sels.cpp:167 (35)
    //         004b4190     PUSH       -0x1
    //         004b4192     PUSH       FUN_0055f658
    //         004b4197     MOV        EAX,FS:[0x0]
    //         004b419d     PUSH       EAX
    //         004b419e     MOV        dword ptr FS:[0x0],ESP
    //         004b41a5     PUSH       this
    //         004b41a6     PUSH       ESI
    //         004b41a7     MOV        ESI,this
    //         004b41a9     MOV        dword ptr [ESP + local_10],ESI
    //         004b41ad     MOV        dword ptr [ESI],TribeSelectScenarioScreen::`vf   = 004b4100
    //                              Scr_sels.cpp:168 (20)
    //         004b41b3     LEA        EAX,[ESI + 0x478]
    //         004b41b9     MOV        dword ptr [ESP + local_4],0x0
    //         004b41c1     PUSH       EAX
    //         004b41c2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:169 (14)
    //         004b41c7     LEA        this,[ESI + 0x47c]
    //         004b41cd     PUSH       this
    //         004b41ce     MOV        this,ESI
    //         004b41d0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:170 (14)
    //         004b41d5     LEA        EDX,[ESI + 0x480]
    //         004b41db     MOV        this,ESI
    //         004b41dd     PUSH       EDX
    //         004b41de     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:171 (14)
    //         004b41e3     LEA        EAX,[ESI + 0x494]
    //         004b41e9     MOV        this,ESI
    //         004b41eb     PUSH       EAX
    //         004b41ec     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:172 (14)
    //         004b41f1     LEA        this,[ESI + 0x498]
    //         004b41f7     PUSH       this
    //         004b41f8     MOV        this,ESI
    //         004b41fa     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:173 (14)
    //         004b41ff     LEA        EDX,[ESI + 0x4ac]
    //         004b4205     MOV        this,ESI
    //         004b4207     PUSH       EDX
    //         004b4208     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:174 (14)
    //         004b420d     LEA        EAX,[ESI + 0x4c0]
    //         004b4213     MOV        this,ESI
    //         004b4215     PUSH       EAX
    //         004b4216     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:175 (14)
    //         004b421b     LEA        this,[ESI + 0x4c4]
    //         004b4221     PUSH       this
    //         004b4222     MOV        this,ESI
    //         004b4224     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:176 (14)
    //         004b4229     LEA        EDX,[ESI + 0x4c8]
    //         004b422f     MOV        this,ESI
    //         004b4231     PUSH       EDX
    //         004b4232     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:177 (14)
    //         004b4237     LEA        EAX,[ESI + 0x4cc]
    //         004b423d     MOV        this,ESI
    //         004b423f     PUSH       EAX
    //         004b4240     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              Scr_sels.cpp:178 (16)
    //         004b4245     LEA        this,[ESI + 0x4d0]
    //         004b424b     PUSH       this
    //         004b424c     MOV        this,ESI
    //         004b424e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b4253     MOV        this,ESI
    //                              Scr_sels.cpp:179 (29)
    //         004b4255     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b425d     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004b4262     MOV        this,dword ptr [ESP + local_c]
    //         004b4266     POP        ESI
    //         004b4267     MOV        dword ptr FS:[0x0],this
    //         004b426e     ADD        ESP,0x10
    //         004b4271     RET
}

// Offset: 0x004B4280
long TribeSelectScenarioScreen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeSelectScenarioScreen::handle_idle(void)                          *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TribeSelectScenarioScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //                               ?handle_idle@TribeSelectScenarioScreen@@UAEJXZ               XREF[1]:     00573d9c(*)  
    //                               TribeSelectScenarioScreen::handle_idle
    //                              Scr_sels.cpp:185 (3)
    //         004b4280     PUSH       ESI
    //         004b4281     MOV        ESI,this
    //                              Scr_sels.cpp:186 (10)
    //         004b4283     MOV        EAX,dword ptr [ESI + 0x4a8]
    //         004b4289     TEST       EAX,EAX
    //         004b428b     JNZ        LAB_004b42b8
    //                              Scr_sels.cpp:188 (5)
    //         004b428d     CALL       TribeSelectScenarioScreen::fillScenarios         void fillScenarios(TribeSelectScenarioScreen 
    //                              Scr_sels.cpp:189 (7)
    //         004b4292     MOV        this,ESI
    //         004b4294     CALL       TribeSelectScenarioScreen::fillMissionText       void fillMissionText(TribeSelectScenarioScree
    //                              Scr_sels.cpp:191 (17)
    //         004b4299     MOV        this,ESI
    //         004b429b     MOV        dword ptr [ESI + 0x4a8],0x1
    //         004b42a5     CALL       TribeSelectScenarioScreen::activatePanels        void activatePanels(TribeSelectScenarioScreen
    //                              Scr_sels.cpp:192 (14)
    //         004b42aa     MOV        EAX,dword ptr [ESI + 0x494]
    //         004b42b0     MOV        this,ESI
    //         004b42b2     PUSH       EAX
    //         004b42b3     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b42b8                                                 XREF[1]:     004b428b(j)  
    //                              Scr_sels.cpp:195 (16)
    //         004b42b8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b42be     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004b42c4     TEST       EAX,EAX
    //         004b42c6     JNZ        LAB_004b42cd
    //                              Scr_sels.cpp:196 (5)
    //         004b42c8     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_004b42cd                                                 XREF[1]:     004b42c6(j)  
    //                              Scr_sels.cpp:198 (7)
    //         004b42cd     MOV        this,ESI
    //         004b42cf     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              Scr_sels.cpp:199 (2)
    //         004b42d4     POP        ESI
    //         004b42d5     RET
}

// Offset: 0x004B42E0
long TribeSelectScenarioScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual long __thiscall TribeSelectScenarioScreen::action(class TPanel *,long,unsigned ... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeSelectScenarioScreen * this, TPanel * pa
    //              long              EAX:4          <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[3]:     004b42ee(R), 004b435a(W), 004b43e7(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004b42fc(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b44d0(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004b44cb(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[4]:     004b4360(W), 004b437d(W), 004b43ed(W), 004b440a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     004b439e(R), 004b442b(R), 004b445a(R), 004b44b9(R), 
    //                                                                                     004b44de(R)  
    //                               ?action@TribeSelectScenarioScreen@@MAEJPAVTPanel@@JKK@Z      XREF[1]:     00573e04(*)  
    //                               TribeSelectScenarioScreen::action
    //                              Scr_sels.cpp:205 (14)
    //         004b42e0     MOV        EAX,FS:[0x0]
    //         004b42e6     PUSH       -0x1
    //         004b42e8     PUSH       FUN_0055f686
    //         004b42ed     PUSH       EAX
    //                              Scr_sels.cpp:206 (40)
    //         004b42ee     MOV        EAX,dword ptr [ESP + param_1]
    //         004b42f2     MOV        dword ptr FS:[0x0],ESP
    //         004b42f9     PUSH       ESI
    //         004b42fa     MOV        ESI,this
    //         004b42fc     MOV        this,dword ptr [ESP + param_2]
    //         004b4300     TEST       EAX,EAX
    //         004b4302     JZ         LAB_004b44cb
    //         004b4308     MOV        EDX,dword ptr [ESI + 0x4a8]
    //         004b430e     TEST       EDX,EDX
    //         004b4310     JZ         LAB_004b44cb
    //                              Scr_sels.cpp:209 (23)
    //         004b4316     MOV        EDX,dword ptr [ESI + 0x4c8]
    //         004b431c     CMP        EAX,EDX
    //         004b431e     JNZ        LAB_004b43b0
    //         004b4324     CMP        this,0x1
    //         004b4327     JNZ        LAB_004b43b0
    //                              Scr_sels.cpp:211 (14)
    //         004b432d     MOV        EAX,dword ptr [ESI + 0x494]
    //         004b4333     MOV        this,ESI
    //         004b4335     PUSH       EAX
    //         004b4336     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              Scr_sels.cpp:214 (7)
    //         004b433b     MOV        this,ESI
    //         004b433d     CALL       TribeSelectScenarioScreen::sendSettings          void sendSettings(TribeSelectScenarioScreen *
    //                              Scr_sels.cpp:217 (11)
    //         004b4342     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b4348     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sels.cpp:218 (36)
    //         004b434d     PUSH       0x890
    //         004b4352     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b4357     ADD        ESP,0x4
    //         004b435a     MOV        dword ptr [ESP + param_1],EAX
    //         004b435e     TEST       EAX,EAX
    //         004b4360     MOV        dword ptr [ESP + local_4],0x0
    //         004b4368     JZ         LAB_004b4371
    //         004b436a     MOV        this,EAX
    //         004b436c     CALL       TribeMPSetupScreen::TribeMPSetupScreen           undefined TribeMPSetupScreen(TribeMPSetupScre
    //                               LAB_004b4371                                                 XREF[1]:     004b4368(j)  
    //                              Scr_sels.cpp:219 (25)
    //         004b4371     PUSH       0x0
    //         004b4373     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
    //         004b4378     MOV        this,panel_system
    //         004b437d     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b4385     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sels.cpp:220 (15)
    //         004b438a     PUSH       s_Select_Scenario_Screen                         = "Select Scenario Screen"
    //         004b438f     MOV        this,panel_system
    //         004b4394     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sels.cpp:221 (5)
    //         004b4399     MOV        EAX,0x1
    //                              Scr_sels.cpp:263 (18)
    //         004b439e     MOV        this,dword ptr [ESP + local_c]
    //         004b43a2     MOV        dword ptr FS:[0x0],this
    //         004b43a9     POP        ESI
    //         004b43aa     ADD        ESP,0xc
    //         004b43ad     RET        0x10
    //                               LAB_004b43b0                                                 XREF[2]:     004b431e(j), 004b4327(j)  
    //                              Scr_sels.cpp:225 (17)
    //         004b43b0     CMP        EAX,dword ptr [ESI + 0x4cc]
    //         004b43b6     JNZ        LAB_004b443d
    //         004b43bc     CMP        this,0x1
    //         004b43bf     JNZ        LAB_004b443d
    //                              Scr_sels.cpp:227 (14)
    //         004b43c1     MOV        this,dword ptr [ESI + 0x494]
    //         004b43c7     PUSH       this
    //         004b43c8     MOV        this,ESI
    //         004b43ca     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              Scr_sels.cpp:230 (11)
    //         004b43cf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b43d5     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              Scr_sels.cpp:231 (36)
    //         004b43da     PUSH       0x49c
    //         004b43df     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004b43e4     ADD        ESP,0x4
    //         004b43e7     MOV        dword ptr [ESP + param_1],EAX
    //         004b43eb     TEST       EAX,EAX
    //         004b43ed     MOV        dword ptr [ESP + local_4],0x1
    //         004b43f5     JZ         LAB_004b43fe
    //         004b43f7     MOV        this,EAX
    //         004b43f9     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
    //                               LAB_004b43fe                                                 XREF[1]:     004b43f5(j)  
    //                              Scr_sels.cpp:232 (25)
    //         004b43fe     PUSH       0x0
    //         004b4400     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //         004b4405     MOV        this,panel_system
    //         004b440a     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b4412     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              Scr_sels.cpp:233 (15)
    //         004b4417     PUSH       s_Select_Scenario_Screen                         = "Select Scenario Screen"
    //         004b441c     MOV        this,panel_system
    //         004b4421     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              Scr_sels.cpp:234 (5)
    //         004b4426     MOV        EAX,0x1
    //                              Scr_sels.cpp:263 (18)
    //         004b442b     MOV        this,dword ptr [ESP + local_c]
    //         004b442f     MOV        dword ptr FS:[0x0],this
    //         004b4436     POP        ESI
    //         004b4437     ADD        ESP,0xc
    //         004b443a     RET        0x10
    //                               LAB_004b443d                                                 XREF[2]:     004b43b6(j), 004b43bf(j)  
    //                              Scr_sels.cpp:238 (13)
    //         004b443d     CMP        EAX,dword ptr [ESI + 0x4d0]
    //         004b4443     JNZ        LAB_004b446c
    //         004b4445     CMP        this,0x1
    //         004b4448     JNZ        LAB_004b446c
    //                              Scr_sels.cpp:240 (11)
    //         004b444a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b4450     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              Scr_sels.cpp:241 (5)
    //         004b4455     MOV        EAX,0x1
    //                              Scr_sels.cpp:263 (18)
    //         004b445a     MOV        this,dword ptr [ESP + local_c]
    //         004b445e     MOV        dword ptr FS:[0x0],this
    //         004b4465     POP        ESI
    //         004b4466     ADD        ESP,0xc
    //         004b4469     RET        0x10
    //                               LAB_004b446c                                                 XREF[2]:     004b4443(j), 004b4448(j)  
    //                              Scr_sels.cpp:245 (8)
    //         004b446c     CMP        EAX,dword ptr [ESI + 0x494]
    //         004b4472     JNZ        LAB_004b44cb
    //                              Scr_sels.cpp:247 (5)
    //         004b4474     CMP        this,0x3
    //         004b4477     JNZ        LAB_004b44a1
    //                              Scr_sels.cpp:249 (17)
    //         004b4479     MOV        EAX,dword ptr [ESI]
    //         004b447b     PUSH       0x0
    //         004b447d     PUSH       0x0
    //         004b447f     PUSH       0x1
    //         004b4481     PUSH       EDX
    //         004b4482     MOV        this,ESI
    //         004b4484     CALL       dword ptr [EAX + 0xb4]
    //                              Scr_sels.cpp:250 (5)
    //         004b448a     MOV        EAX,0x1
    //                              Scr_sels.cpp:263 (18)
    //         004b448f     MOV        this,dword ptr [ESP + 0x4]
    //         004b4493     MOV        dword ptr FS:[0x0],this
    //         004b449a     POP        ESI
    //         004b449b     ADD        ESP,0xc
    //         004b449e     RET        0x10
    //                               LAB_004b44a1                                                 XREF[1]:     004b4477(j)  
    //                              Scr_sels.cpp:253 (5)
    //         004b44a1     CMP        this,0x1
    //         004b44a4     JNZ        LAB_004b44cb
    //                              Scr_sels.cpp:255 (7)
    //         004b44a6     MOV        this,ESI
    //         004b44a8     CALL       TribeSelectScenarioScreen::fillMissionText       void fillMissionText(TribeSelectScenarioScree
    //                              Scr_sels.cpp:256 (7)
    //         004b44ad     MOV        this,ESI
    //         004b44af     CALL       TribeSelectScenarioScreen::activatePanels        void activatePanels(TribeSelectScenarioScreen
    //                              Scr_sels.cpp:257 (5)
    //         004b44b4     MOV        EAX,0x1
    //                              Scr_sels.cpp:263 (18)
    //         004b44b9     MOV        this,dword ptr [ESP + local_c]
    //         004b44bd     MOV        dword ptr FS:[0x0],this
    //         004b44c4     POP        ESI
    //         004b44c5     ADD        ESP,0xc
    //         004b44c8     RET        0x10
    //                               LAB_004b44cb                                                 XREF[4]:     004b4302(j), 004b4310(j), 
    //                                                                                                         004b4472(j), 004b44a4(j)  
    //                              Scr_sels.cpp:262 (19)
    //         004b44cb     MOV        EDX,dword ptr [ESP + param_4]
    //         004b44cf     PUSH       EDX
    //         004b44d0     MOV        EDX,dword ptr [ESP + param_3]
    //         004b44d4     PUSH       EDX
    //         004b44d5     PUSH       this
    //         004b44d6     PUSH       EAX
    //         004b44d7     MOV        this,ESI
    //         004b44d9     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              Scr_sels.cpp:263 (18)
    //         004b44de     MOV        this,dword ptr [ESP + local_c]
    //         004b44e2     MOV        dword ptr FS:[0x0],this
    //         004b44e9     POP        ESI
    //         004b44ea     ADD        ESP,0xc
    //         004b44ed     RET        0x10
}

// Offset: 0x004B44F0
void fillScenarios(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSelectScenarioScreen::fillScenarios(void)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall fillScenarios(TribeSelectScenarioScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //              char[260]         Stack[-0x108   scenario_file             XREF[0,2]:   004b46ba(*), 004b46cf(*)  
    //              char[260]         Stack[-0x20c   file_name                 XREF[0,2]:   004b4554(*), 004b456e(*)  
    //              char[20]          Stack[-0x220   player_str                XREF[2,3]:   004b4506(W), 004b45e6(R), 004b4680(*), 004b4695(*), 
    //                                                                                     004b46e6(*)  
    //              RGE_Scenario_F    Stack[-0x224   scenario_info_file        XREF[5]:     004b45da(W), 004b4651(R), 004b46dd(R), 004b46f8(R), 
    //                                                                                     004b4705(W)  
    //              int               Stack[-0x228   i
    //                               ?fillScenarios@TribeSelectScenarioScreen@@IAEXXZ             XREF[2]:     TribeSelectScenarioScreen:004b40ba
    //                               TribeSelectScenarioScreen::fillScenarios                                  handle_idle:004b428d(c)  
    //                              Scr_sels.cpp:269 (6)
    //         004b44f0     SUB        ESP,0x224
    //                              Scr_sels.cpp:281 (14)
    //         004b44f6     MOV        EAX,[rge_base_game]                              = 00000000
    //         004b44fb     PUSH       EBX
    //         004b44fc     PUSH       EBP
    //         004b44fd     MOV        EBP,this
    //         004b44ff     MOV        EBX,dword ptr [EAX + 0x8]
    //         004b4502     PUSH       ESI
    //         004b4503     PUSH       EDI
    //                              Scr_sels.cpp:283 (11)
    //         004b4504     MOV        this,EBX
    //         004b4506     MOV        dword ptr [ESP + player_str[0]],EBX
    //         004b450a     CALL       RGE_Scenario_File_Info::reload_scenarios         void reload_scenarios(RGE_Scenario_File_Info 
    //                              Scr_sels.cpp:286 (11)
    //         004b450f     MOV        this,dword ptr [EBP + 0x494]
    //         004b4515     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              Scr_sels.cpp:287 (16)
    //         004b451a     MOV        this,dword ptr [EBP + 0x494]
    //         004b4520     MOV        dword ptr [ECX + this->_padding_],0x1
    //                              Scr_sels.cpp:289 (10)
    //         004b452a     MOV        dword ptr [EBP + 0x49c],0x0
    //                               LAB_004b4534                                                 XREF[1]:     004b458a(j)  
    //                              Scr_sels.cpp:293 (16)
    //         004b4534     MOV        EDX,dword ptr [EBP + 0x49c]
    //         004b453a     MOV        this,EBX
    //         004b453c     PUSH       EDX
    //         004b453d     CALL       RGE_Scenario_File_Info::get_scenario_name        char * get_scenario_name(RGE_Scenario_File_In
    //         004b4542     MOV        EDX,EAX
    //                              Scr_sels.cpp:294 (4)
    //         004b4544     TEST       EDX,EDX
    //         004b4546     JZ         LAB_004b458c
    //                              Scr_sels.cpp:298 (12)
    //         004b4548     MOV        EDI,EDX
    //         004b454a     OR         this,0xffffffff
    //         004b454d     XOR        EAX,EAX
    //         004b454f     SCASB.RE   ES:EDI
    //         004b4551     NOT        this
    //         004b4553     DEC        this
    //                              Scr_sels.cpp:299 (17)
    //         004b4554     LEA        EAX=>file_name[4],[ESP + 0x2c]
    //         004b4558     MOV        ESI,this
    //         004b455a     SUB        ESI,0x4
    //         004b455d     PUSH       ESI
    //         004b455e     PUSH       EDX
    //         004b455f     PUSH       EAX
    //         004b4560     CALL       strncpy                                          undefined strncpy()
    //                              Scr_sels.cpp:301 (31)
    //         004b4565     MOV        this,dword ptr [EBP + 0x49c]
    //         004b456b     ADD        ESP,0xc
    //         004b456e     LEA        EDX=>file_name[4],[ESP + 0x2c]
    //         004b4572     MOV        byte ptr [ESP + ESI*0x1 + 0x2c],0x0
    //         004b4577     PUSH       this
    //         004b4578     MOV        this,dword ptr [EBP + 0x494]
    //         004b457e     PUSH       EDX
    //         004b457f     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              Scr_sels.cpp:302 (8)
    //         004b4584     INC        dword ptr [EBP + 0x49c]
    //         004b458a     JMP        LAB_004b4534
    //                               LAB_004b458c                                                 XREF[1]:     004b4546(j)  
    //                              Scr_sels.cpp:307 (14)
    //         004b458c     MOV        EAX,dword ptr [EBP + 0x49c]
    //         004b4592     PUSH       0x4
    //         004b4594     PUSH       EAX
    //         004b4595     CALL       calloc                                           undefined calloc()
    //                              Scr_sels.cpp:308 (23)
    //         004b459a     MOV        this,dword ptr [EBP + 0x49c]
    //         004b45a0     ADD        ESP,0x8
    //         004b45a3     MOV        dword ptr [EBP + 0x4a0],EAX
    //         004b45a9     PUSH       0x4
    //         004b45ab     PUSH       this
    //         004b45ac     CALL       calloc                                           undefined calloc()
    //                              Scr_sels.cpp:309 (31)
    //         004b45b1     MOV        this,dword ptr [EBP + 0x4a0]
    //         004b45b7     ADD        ESP,0x8
    //         004b45ba     TEST       this,this
    //         004b45bc     MOV        dword ptr [EBP + 0x4a4],EAX
    //         004b45c2     JZ         LAB_004b470f
    //         004b45c8     TEST       EAX,EAX
    //         004b45ca     JZ         LAB_004b470f
    //                              Scr_sels.cpp:311 (26)
    //         004b45d0     MOV        EAX,dword ptr [EBP + 0x49c]
    //         004b45d6     XOR        ESI,ESI
    //         004b45d8     TEST       EAX,EAX
    //         004b45da     MOV        dword ptr [ESP + scenario_info_file],ESI
    //         004b45de     JLE        LAB_004b470f
    //         004b45e4     JMP        LAB_004b45ea
    //                               LAB_004b45e6                                                 XREF[1]:     004b4709(j)  
    //         004b45e6     MOV        EBX,dword ptr [ESP + player_str[0]]
    //                               LAB_004b45ea                                                 XREF[1]:     004b45e4(j)  
    //                              Scr_sels.cpp:314 (22)
    //         004b45ea     MOV        this,dword ptr [EBP + 0x494]
    //         004b45f0     PUSH       ESI
    //         004b45f1     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this, long param_1)
    //         004b45f6     PUSH       EAX
    //         004b45f7     MOV        this,EBX
    //         004b45f9     CALL       RGE_Scenario_File_Info::get_scenario_info        RGE_Scenario_Header * get_scenario_info(RGE_S
    //         004b45fe     MOV        EBX,EAX
    //                              Scr_sels.cpp:316 (8)
    //         004b4600     TEST       EBX,EBX
    //         004b4602     JZ         LAB_004b46fc
    //                              Scr_sels.cpp:319 (24)
    //         004b4608     PUSH       0x1
    //         004b460a     PUSH       0x1000
    //         004b460f     CALL       calloc                                           undefined calloc()
    //         004b4614     MOV        EDX,dword ptr [EBP + 0x4a0]
    //         004b461a     ADD        ESP,0x8
    //         004b461d     MOV        dword ptr [EDX + ESI*0x4],EAX
    //                              Scr_sels.cpp:320 (13)
    //         004b4620     MOV        EAX,dword ptr [EBP + 0x4a0]
    //         004b4626     MOV        EDX,dword ptr [EAX + ESI*0x4]
    //         004b4629     TEST       EDX,EDX
    //         004b462b     JZ         LAB_004b4655
    //                              Scr_sels.cpp:323 (7)
    //         004b462d     MOV        EDI,dword ptr [EBX + 0x10]
    //         004b4630     TEST       EDI,EDI
    //         004b4632     JZ         LAB_004b4655
    //                              Scr_sels.cpp:324 (33)
    //         004b4634     OR         this,0xffffffff
    //         004b4637     XOR        EAX,EAX
    //         004b4639     SCASB.RE   ES:EDI
    //         004b463b     NOT        this
    //         004b463d     SUB        EDI,this
    //         004b463f     MOV        EAX,this
    //         004b4641     MOV        ESI,EDI
    //         004b4643     MOV        EDI,EDX
    //         004b4645     SHR        this,0x2
    //         004b4648     MOVSD.REP  ES:EDI,ESI
    //         004b464a     MOV        this,EAX
    //         004b464c     AND        this,0x3
    //         004b464f     MOVSB.REP  ES:EDI,ESI
    //         004b4651     MOV        ESI,dword ptr [ESP + scenario_info_file]
    //                               LAB_004b4655                                                 XREF[2]:     004b462b(j), 004b4632(j)  
    //                              Scr_sels.cpp:328 (12)
    //         004b4655     MOV        this,dword ptr [EBP + 0x4a4]
    //         004b465b     MOV        EDX,dword ptr [EBX + 0x14]
    //         004b465e     MOV        dword ptr [this->_padding_ + ESI*0x4],EDX
    //                              Scr_sels.cpp:331 (3)
    //         004b4661     MOV        EBX,dword ptr [EBX + 0x18]
    //                              Scr_sels.cpp:332 (8)
    //         004b4664     TEST       EBX,EBX
    //         004b4666     JLE        LAB_004b46fc
    //                              Scr_sels.cpp:334 (17)
    //         004b466c     MOV        EAX,dword ptr [EBP + 0x4a4]
    //         004b4672     CMP        dword ptr [EAX + ESI*0x4],0x0
    //         004b4676     JNZ        LAB_004b4694
    //         004b4678     CMP        EBX,0x3
    //         004b467b     JL         LAB_004b4694
    //                              Scr_sels.cpp:337 (23)
    //         004b467d     PUSH       EBX
    //         004b467e     PUSH       0x2
    //         004b4680     LEA        this=>player_str[4],[ESP + 0x20]
    //         004b4684     PUSH       s_%d_-_%d                                        = "%d - %d"
    //         004b4689     PUSH       this
    //         004b468a     CALL       sprintf                                          undefined sprintf()
    //         004b468f     ADD        ESP,0x10
    //         004b4692     JMP        LAB_004b46a7
    //                               LAB_004b4694                                                 XREF[2]:     004b4676(j), 004b467b(j)  
    //                              Scr_sels.cpp:335 (19)
    //         004b4694     PUSH       EBX
    //         004b4695     LEA        EDX=>player_str[4],[ESP + 0x1c]
    //         004b4699     PUSH       s_%d                                             = 6425h
    //         004b469e     PUSH       EDX
    //         004b469f     CALL       sprintf                                          undefined sprintf()
    //         004b46a4     ADD        ESP,0xc
    //                               LAB_004b46a7                                                 XREF[1]:     004b4692(j)  
    //                              Scr_sels.cpp:338 (32)
    //         004b46a7     MOV        this,dword ptr [EBP + 0x494]
    //         004b46ad     PUSH       ESI
    //         004b46ae     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
    //         004b46b3     MOV        EDI,EAX
    //         004b46b5     OR         this,0xffffffff
    //         004b46b8     XOR        EAX,EAX
    //         004b46ba     LEA        EDX=>scenario_file[4],[ESP + 0x130]
    //         004b46c1     SCASB.RE   ES:EDI
    //         004b46c3     NOT        this
    //         004b46c5     SUB        EDI,this
    //                              Scr_sels.cpp:339 (72)
    //         004b46c7     PUSH       0x0
    //         004b46c9     MOV        EAX,this
    //         004b46cb     MOV        ESI,EDI
    //         004b46cd     MOV        EDI,EDX
    //         004b46cf     LEA        EDX=>scenario_file[4],[ESP + 0x134]
    //         004b46d6     SHR        this,0x2
    //         004b46d9     MOVSD.REP  ES:EDI,ESI
    //         004b46db     MOV        this,EAX
    //         004b46dd     MOV        EAX,dword ptr [ESP + scenario_info_file]
    //         004b46e1     AND        this,0x3
    //         004b46e4     MOVSB.REP  ES:EDI,ESI
    //         004b46e6     LEA        this=>player_str[4],[ESP + 0x1c]
    //         004b46ea     PUSH       this
    //         004b46eb     MOV        this,dword ptr [EBP + 0x494]
    //         004b46f1     PUSH       EDX
    //         004b46f2     PUSH       EAX
    //         004b46f3     CALL       TTextPanel::change_line                          int change_line(TTextPanel * this, long param
    //         004b46f8     MOV        ESI,dword ptr [ESP + scenario_info_file]
    //                               LAB_004b46fc                                                 XREF[2]:     004b4602(j), 004b4666(j)  
    //         004b46fc     MOV        EAX,dword ptr [EBP + 0x49c]
    //         004b4702     INC        ESI
    //         004b4703     CMP        ESI,EAX
    //         004b4705     MOV        dword ptr [ESP + scenario_info_file],ESI
    //         004b4709     JL         LAB_004b45e6
    //                               LAB_004b470f                                                 XREF[3]:     004b45c2(j), 004b45ca(j), 
    //                                                                                                         004b45de(j)  
    //                              Scr_sels.cpp:348 (11)
    //         004b470f     POP        EDI
    //         004b4710     POP        ESI
    //         004b4711     POP        EBP
    //         004b4712     POP        EBX
    //         004b4713     ADD        ESP,0x224
    //         004b4719     RET
}

// Offset: 0x004B4720
void fillMissionText(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSelectScenarioScreen::fillMissionText(void)                           *
    //                              *********************************************************************************************************
    //                              void __thiscall fillMissionText(TribeSelectScenarioScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //                               ?fillMissionText@TribeSelectScenarioScreen@@IAEXXZ           XREF[3]:     TribeSelectScenarioScreen:004b40d2
    //                               TribeSelectScenarioScreen::fillMissionText                                handle_idle:004b4294(c), 
    //                                                                                                         action:004b44a8(c)  
    //                              Scr_sels.cpp:354 (4)
    //         004b4720     PUSH       ESI
    //         004b4721     MOV        ESI,this
    //         004b4723     PUSH       EDI
    //                              Scr_sels.cpp:357 (19)
    //         004b4724     PUSH       s_                                               = ""
    //         004b4729     MOV        this,dword ptr [ESI + 0x4c0]
    //         004b472f     MOV        EAX,dword ptr [this->_padding_]
    //         004b4731     CALL       dword ptr [EAX + 0xe8]
    //                              Scr_sels.cpp:359 (13)
    //         004b4737     MOV        this,dword ptr [ESI + 0x494]
    //         004b473d     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         004b4742     MOV        EDI,EAX
    //                              Scr_sels.cpp:367 (4)
    //         004b4744     TEST       EDI,EDI
    //         004b4746     JL         LAB_004b4760
    //                              Scr_sels.cpp:368 (24)
    //         004b4748     MOV        EAX,dword ptr [ESI + 0x4a0]
    //         004b474e     MOV        this,dword ptr [ESI + 0x4c0]
    //         004b4754     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         004b4757     MOV        EDX,dword ptr [this->_padding_]
    //         004b4759     PUSH       EAX
    //         004b475a     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_004b4760                                                 XREF[1]:     004b4746(j)  
    //                              Scr_sels.cpp:370 (6)
    //         004b4760     MOV        dword ptr [ESI + 0x4d4],EDI
    //                              Scr_sels.cpp:371 (3)
    //         004b4766     POP        EDI
    //         004b4767     POP        ESI
    //         004b4768     RET
}

// Offset: 0x004B4770
void getSettings(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSelectScenarioScreen::getSettings(void)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall getSettings(TribeSelectScenarioScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //                               ?getSettings@TribeSelectScenarioScreen@@IAEXXZ               XREF[1]:     TribeSelectScenarioScreen:004b40cb
    //                               TribeSelectScenarioScreen::getSettings
    //                              Scr_sels.cpp:377 (4)
    //         004b4770     PUSH       ESI
    //         004b4771     MOV        ESI,this
    //         004b4773     PUSH       EDI
    //                              Scr_sels.cpp:380 (10)
    //         004b4774     MOV        dword ptr [ESI + 0x4d4],0xffffffff
    //                              Scr_sels.cpp:382 (25)
    //         004b477e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b4784     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
    //         004b4789     MOV        this,dword ptr [ESI + 0x494]
    //         004b478f     PUSH       EAX
    //         004b4790     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
    //         004b4795     MOV        EDI,EAX
    //                              Scr_sels.cpp:385 (21)
    //         004b4797     PUSH       0x1
    //         004b4799     CMP        EDI,-0x1
    //         004b479c     JZ         LAB_004b47b6
    //         004b479e     MOV        this,dword ptr [ESI + 0x494]
    //         004b47a4     PUSH       EDI
    //         004b47a5     PUSH       0x1
    //         004b47a7     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              Scr_sels.cpp:386 (7)
    //         004b47ac     DEC        EDI
    //         004b47ad     MOV        dword ptr [ESI + 0x4d4],EDI
    //                              Scr_sels.cpp:390 (3)
    //         004b47b3     POP        EDI
    //         004b47b4     POP        ESI
    //         004b47b5     RET
    //                               LAB_004b47b6                                                 XREF[1]:     004b479c(j)  
    //                              Scr_sels.cpp:389 (15)
    //         004b47b6     MOV        this,dword ptr [ESI + 0x494]
    //         004b47bc     PUSH       0x0
    //         004b47be     PUSH       0x1
    //         004b47c0     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              Scr_sels.cpp:390 (3)
    //         004b47c5     POP        EDI
    //         004b47c6     POP        ESI
    //         004b47c7     RET
}

// Offset: 0x004B47D0
void sendSettings(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSelectScenarioScreen::sendSettings(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall sendSettings(TribeSelectScenarioScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //                               ?sendSettings@TribeSelectScenarioScreen@@IAEXXZ              XREF[1]:     action:004b433d(c)  
    //                               TribeSelectScenarioScreen::sendSettings
    //                              Scr_sels.cpp:396 (3)
    //         004b47d0     PUSH       ESI
    //         004b47d1     MOV        ESI,this
    //                              Scr_sels.cpp:401 (13)
    //         004b47d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b47d9     PUSH       0x1
    //         004b47db     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              Scr_sels.cpp:402 (23)
    //         004b47e0     MOV        this,dword ptr [ESI + 0x494]
    //         004b47e6     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
    //         004b47eb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b47f1     PUSH       EAX
    //         004b47f2     CALL       RGE_Base_Game::setScenarioName                   void setScenarioName(RGE_Base_Game * this, ch
    //                              Scr_sels.cpp:403 (13)
    //         004b47f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b47fd     PUSH       0x0
    //         004b47ff     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
    //                              Scr_sels.cpp:411 (2)
    //         004b4804     POP        ESI
    //         004b4805     RET
}

// Offset: 0x004B4810
void activatePanels(TribeSelectScenarioScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeSelectScenarioScreen::activatePanels(void)                            *
    //                              *********************************************************************************************************
    //                              void __thiscall activatePanels(TribeSelectScenarioScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeSelectSce    ECX:4 (auto)   this
    //              TPanel *[4]       Stack[-0x14]   tabList
    //                               ?activatePanels@TribeSelectScenarioScreen@@IAEXXZ            XREF[3]:     TribeSelectScenarioScreen:004b40d9
    //                               TribeSelectScenarioScreen::activatePanels                                 handle_idle:004b42a5(c), 
    //                                                                                                         action:004b44af(c)  
    //                              Scr_sels.cpp:417 (6)
    //         004b4810     SUB        ESP,0x10
    //         004b4813     PUSH       ESI
    //         004b4814     MOV        ESI,this
    //                              Scr_sels.cpp:418 (13)
    //         004b4816     PUSH       0x1
    //         004b4818     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b481e     MOV        EAX,dword ptr [this->_padding_]
    //         004b4820     CALL       dword ptr [EAX + 0x14]
    //                              Scr_sels.cpp:419 (13)
    //         004b4823     MOV        this,dword ptr [ESI + 0x4c0]
    //         004b4829     PUSH       0x1
    //         004b482b     MOV        EDX,dword ptr [this->_padding_]
    //         004b482d     CALL       dword ptr [EDX + 0x14]
    //                              Scr_sels.cpp:425 (12)
    //         004b4830     MOV        this,dword ptr [ESI + 0x4c8]
    //         004b4836     MOV        EAX,dword ptr [ESI + 0x494]
    //                              Scr_sels.cpp:426 (10)
    //         004b483c     MOV        EDX,dword ptr [ESI + 0x4cc]
    //         004b4842     MOV        dword ptr [ESP + 0x8],this
    //                              Scr_sels.cpp:427 (25)
    //         004b4846     LEA        this,[ESP + 0x4]
    //         004b484a     MOV        dword ptr [ESP + 0x4],EAX
    //         004b484e     MOV        EAX,dword ptr [ESI]
    //         004b4850     PUSH       0x3
    //         004b4852     PUSH       this=>DAT_fffffff8
    //         004b4853     MOV        this,ESI
    //         004b4855     MOV        dword ptr [ESP + 0x14],EDX
    //         004b4859     CALL       dword ptr [EAX + 0xc8]
    //                              Scr_sels.cpp:431 (14)
    //         004b485f     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004b4862     TEST       EAX,EAX
    //         004b4864     JZ         LAB_004b486d
    //         004b4866     MOV        this,dword ptr [EAX + 0x6c]
    //         004b4869     TEST       this,this
    //         004b486b     JNZ        LAB_004b487b
    //                               LAB_004b486d                                                 XREF[1]:     004b4864(j)  
    //                              Scr_sels.cpp:432 (14)
    //         004b486d     MOV        EDX,dword ptr [ESI + 0x4c8]
    //         004b4873     MOV        this,ESI
    //         004b4875     PUSH       EDX
    //         004b4876     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b487b                                                 XREF[1]:     004b486b(j)  
    //                              Scr_sels.cpp:433 (5)
    //         004b487b     POP        ESI
    //         004b487c     ADD        ESP,0x10
    //         004b487f     RET
}

