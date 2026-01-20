// Auto-generated scaffold unit: scr_set.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_set.cpp
#include "../include/common.h"

// Offset: 0x004B4880
undefined TribeGameSettingsScreen(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeGameSettingsScreen::TribeGameSettingsScreen(void)                             *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeGameSettingsScreen(TribeGameSettingsScreen
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004b48ad(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004b492f(R), 004b57d9(R)  
    //              char[5]           Stack[-0x18]:5 num_str                   XREF[1]:     004b48a2(W)  
    //                               ??0TribeGameSettingsScreen@@QAE@XZ                           XREF[1]:     action:004a1aaf(c)  
    //                               TribeGameSettingsScreen::TribeGameSettingsScreen
    //                              scr_set.cpp:162 (43)
    //         004b4880     PUSH       -0x1
    //         004b4882     PUSH       FUN_0055f698
    //         004b4887     MOV        EAX,FS:[0x0]
    //         004b488d     PUSH       EAX
    //         004b488e     MOV        dword ptr FS:[0x0],ESP
    //         004b4895     SUB        ESP,0xc
    //         004b4898     PUSH       EBX
    //         004b4899     PUSH       ESI
    //         004b489a     PUSH       EDI
    //         004b489b     MOV        ESI,this
    //         004b489d     PUSH       s_Game_Settings_Screen                           = 47h
    //         004b48a2     MOV        dword ptr [ESP + num_str[0]],ESI
    //         004b48a6     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_set.cpp:164 (21)
    //         004b48ab     MOV        this,ESI
    //         004b48ad     MOV        dword ptr [ESP + local_4],0x0
    //         004b48b5     MOV        dword ptr [ESI],TribeGameSettingsScreen::`vfta   = 004b57f0
    //         004b48bb     CALL       TribeGameSettingsScreen::init_vars               void init_vars(TribeGameSettingsScreen * this)
    //                              scr_set.cpp:167 (21)
    //         004b48c0     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
    //         004b48c5     MOV        this,panel_system
    //         004b48ca     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //         004b48cf     MOV        dword ptr [ESI + 0x550],EAX
    //                              scr_set.cpp:170 (78)
    //         004b48d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b48db     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b48e0     TEST       EAX,EAX
    //         004b48e2     MOV        EBX,s_scr3                                       = 73h
    //         004b48e7     JNZ        LAB_004b48ee
    //         004b48e9     MOV        EBX,s_scr2                                       = 73h
    //                               LAB_004b48ee                                                 XREF[1]:     004b48e7(j)  
    //         004b48ee     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b48f4     PUSH       0x1
    //         004b48f6     PUSH       0x0
    //         004b48f8     PUSH       0x0
    //         004b48fa     MOV        EDI,dword ptr [ECX + this->_padding_]
    //         004b48fd     PUSH       0x0
    //         004b48ff     PUSH       0x0
    //         004b4901     PUSH       0x1
    //         004b4903     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b4908     NEG        EAX
    //         004b490a     SBB        EAX,EAX
    //         004b490c     MOV        this,ESI
    //         004b490e     NEG        EAX
    //         004b4910     ADD        EAX,0xc384
    //         004b4915     PUSH       EAX
    //         004b4916     PUSH       EBX=>s_scr2                                      = 73h
    //         004b4917     PUSH       0x0
    //         004b4919     PUSH       EDI
    //         004b491a     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
    //         004b491f     TEST       EAX,EAX
    //         004b4921     JNZ        LAB_004b4941
    //                              scr_set.cpp:172 (10)
    //         004b4923     MOV        dword ptr [ESI + 0xd8],0x1
    //                              scr_set.cpp:419 (20)
    //         004b492d     MOV        EAX,ESI
    //         004b492f     MOV        this,dword ptr [ESP + local_c]
    //         004b4933     MOV        dword ptr FS:[0x0],this
    //         004b493a     POP        EDI
    //         004b493b     POP        ESI
    //         004b493c     POP        EBX
    //         004b493d     ADD        ESP,0x18
    //         004b4940     RET
    //                               LAB_004b4941                                                 XREF[1]:     004b4921(j)  
    //                              scr_set.cpp:176 (9)
    //         004b4941     PUSH       0x0
    //         004b4943     MOV        this,ESI
    //         004b4945     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_set.cpp:177 (17)
    //         004b494a     PUSH       0x1e0
    //         004b494f     PUSH       0x280
    //         004b4954     MOV        this,ESI
    //         004b4956     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_set.cpp:180 (47)
    //         004b495b     PUSH       0x1
    //         004b495d     PUSH       0x0
    //         004b495f     PUSH       0x1
    //         004b4961     PUSH       0x1
    //         004b4963     PUSH       0x1e
    //         004b4965     PUSH       0x258
    //         004b496a     PUSH       0xa
    //         004b496c     PUSH       0x14
    //         004b496e     LEA        EAX,[ESI + 0x478]
    //                              language.dll match for 0x2616: "Scenario Settings"
    //         004b4974     PUSH       0x2616
    //         004b4979     PUSH       EAX
    //         004b497a     PUSH       ESI
    //         004b497b     MOV        this,ESI
    //         004b497d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4982     TEST       EAX,EAX
    //         004b4984     JZ         LAB_004b57d9
    //                              scr_set.cpp:183 (50)
    //         004b498a     PUSH       0x0
    //         004b498c     PUSH       0x0
    //         004b498e     PUSH       0x0
    //         004b4990     PUSH       0xb
    //         004b4992     PUSH       0x14
    //         004b4994     PUSH       0xb4
    //         004b4999     PUSH       0xd8
    //         004b499e     PUSH       0x14
    //         004b49a0     LEA        this,[ESI + 0x480]
    //                              language.dll match for 0x29a0: "Map Size"
    //         004b49a6     PUSH       0x29a0
    //         004b49ab     PUSH       this
    //         004b49ac     PUSH       ESI
    //         004b49ad     MOV        this,ESI
    //         004b49af     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b49b4     TEST       EAX,EAX
    //         004b49b6     JZ         LAB_004b57d9
    //                              scr_set.cpp:185 (46)
    //         004b49bc     PUSH       0xb
    //         004b49be     PUSH       0x18
    //         004b49c0     PUSH       0xb4
    //         004b49c5     PUSH       0xec
    //         004b49ca     PUSH       0x14
    //         004b49cc     LEA        EDI,[ESI + 0x484]
    //         004b49d2     PUSH       0x64
    //         004b49d4     PUSH       0xb4
    //         004b49d9     PUSH       EDI
    //         004b49da     PUSH       ESI
    //         004b49db     MOV        this,ESI
    //         004b49dd     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b49e2     TEST       EAX,EAX
    //         004b49e4     JZ         LAB_004b57d9
    //                              scr_set.cpp:186 (7)
    //         004b49ea     MOV        this,dword ptr [EDI]
    //         004b49ec     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:187 (14)
    //         004b49f1     MOV        this,dword ptr [EDI]
    //         004b49f3     PUSH       0x0
    //                              language.dll match for 0x2973: "Tiny"
    //         004b49f5     PUSH       0x2973
    //         004b49fa     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:188 (14)
    //         004b49ff     MOV        this,dword ptr [EDI]
    //         004b4a01     PUSH       0x1
    //                              language.dll match for 0x2974: "Small"
    //         004b4a03     PUSH       0x2974
    //         004b4a08     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:189 (14)
    //         004b4a0d     MOV        this,dword ptr [EDI]
    //         004b4a0f     PUSH       0x2
    //                              language.dll match for 0x2975: "Medium"
    //         004b4a11     PUSH       0x2975
    //         004b4a16     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:190 (14)
    //         004b4a1b     MOV        this,dword ptr [EDI]
    //         004b4a1d     PUSH       0x3
    //                              language.dll match for 0x2976: "Large"
    //         004b4a1f     PUSH       0x2976
    //         004b4a24     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:191 (14)
    //         004b4a29     MOV        this,dword ptr [EDI]
    //         004b4a2b     PUSH       0x4
    //                              language.dll match for 0x2977: "Huge"
    //         004b4a2d     PUSH       0x2977
    //         004b4a32     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:192 (14)
    //         004b4a37     MOV        this,dword ptr [EDI]
    //         004b4a39     PUSH       0x5
    //                              language.dll match for 0x2978: "Gigantic"
    //         004b4a3b     PUSH       0x2978
    //         004b4a40     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:193 (14)
    //         004b4a45     MOV        this,dword ptr [EDI]
    //         004b4a47     PUSH       -0x1
    //                              language.dll match for 0x762a: "Select the map size. The larg
    //         004b4a49     PUSH       0x762a
    //         004b4a4e     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:196 (53)
    //         004b4a53     PUSH       0x0
    //         004b4a55     PUSH       0x0
    //         004b4a57     PUSH       0x0
    //         004b4a59     PUSH       0xb
    //         004b4a5b     PUSH       0x14
    //         004b4a5d     PUSH       0xb4
    //         004b4a62     PUSH       0xd8
    //         004b4a67     PUSH       0xdc
    //         004b4a6c     LEA        EDX,[ESI + 0x488]
    //                              language.dll match for 0x25db: "Map Type"
    //         004b4a72     PUSH       0x25db
    //         004b4a77     PUSH       EDX
    //         004b4a78     PUSH       ESI
    //         004b4a79     MOV        this,ESI
    //         004b4a7b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4a80     TEST       EAX,EAX
    //         004b4a82     JZ         LAB_004b57d9
    //                              scr_set.cpp:198 (49)
    //         004b4a88     PUSH       0xb
    //         004b4a8a     PUSH       0x18
    //         004b4a8c     PUSH       0xb4
    //         004b4a91     PUSH       0xec
    //         004b4a96     PUSH       0xdc
    //         004b4a9b     LEA        EDI,[ESI + 0x48c]
    //         004b4aa1     PUSH       0x64
    //         004b4aa3     PUSH       0xb4
    //         004b4aa8     PUSH       EDI
    //         004b4aa9     PUSH       ESI
    //         004b4aaa     MOV        this,ESI
    //         004b4aac     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b4ab1     TEST       EAX,EAX
    //         004b4ab3     JZ         LAB_004b57d9
    //                              scr_set.cpp:199 (7)
    //         004b4ab9     MOV        this,dword ptr [EDI]
    //         004b4abb     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:200 (14)
    //         004b4ac0     MOV        this,dword ptr [EDI]
    //         004b4ac2     PUSH       0x0
    //                              language.dll match for 0x296a: "Small Islands"
    //         004b4ac4     PUSH       0x296a
    //         004b4ac9     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:201 (14)
    //         004b4ace     MOV        this,dword ptr [EDI]
    //         004b4ad0     PUSH       0x1
    //                              language.dll match for 0x296b: "Large Islands"
    //         004b4ad2     PUSH       0x296b
    //         004b4ad7     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:202 (14)
    //         004b4adc     MOV        this,dword ptr [EDI]
    //         004b4ade     PUSH       0x2
    //                              language.dll match for 0x296c: "Coastal"
    //         004b4ae0     PUSH       0x296c
    //         004b4ae5     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:203 (14)
    //         004b4aea     MOV        this,dword ptr [EDI]
    //         004b4aec     PUSH       0x3
    //                              language.dll match for 0x296d: "Inland"
    //         004b4aee     PUSH       0x296d
    //         004b4af3     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:204 (14)
    //         004b4af8     MOV        this,dword ptr [EDI]
    //         004b4afa     PUSH       0x4
    //                              language.dll match for 0x296e: "Highland"
    //         004b4afc     PUSH       0x296e
    //         004b4b01     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:205 (14)
    //         004b4b06     MOV        this,dword ptr [EDI]
    //         004b4b08     PUSH       0x5
    //                              language.dll match for 0x296f: "Continental"
    //         004b4b0a     PUSH       0x296f
    //         004b4b0f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:206 (14)
    //         004b4b14     MOV        this,dword ptr [EDI]
    //         004b4b16     PUSH       0x6
    //                              language.dll match for 0x2970: "Mediterranean"
    //         004b4b18     PUSH       0x2970
    //         004b4b1d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:207 (14)
    //         004b4b22     MOV        this,dword ptr [EDI]
    //         004b4b24     PUSH       0x7
    //                              language.dll match for 0x2971: "Hill Country"
    //         004b4b26     PUSH       0x2971
    //         004b4b2b     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:208 (14)
    //         004b4b30     MOV        this,dword ptr [EDI]
    //         004b4b32     PUSH       0x8
    //                              language.dll match for 0x2972: "Narrows"
    //                              language.dll match for 0x2972: "******* SIZE *******"
    //         004b4b34     PUSH       0x2972
    //         004b4b39     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:209 (14)
    //         004b4b3e     MOV        this,dword ptr [EDI]
    //         004b4b40     PUSH       -0x1
    //                              language.dll match for 0x762b: "Select the distribution of la
    //         004b4b42     PUSH       0x762b
    //         004b4b47     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:214 (50)
    //         004b4b4c     PUSH       0x0
    //         004b4b4e     PUSH       0x0
    //         004b4b50     PUSH       0x0
    //         004b4b52     PUSH       0xb
    //         004b4b54     PUSH       0x14
    //         004b4b56     PUSH       0xb4
    //         004b4b5b     PUSH       0x108
    //         004b4b60     PUSH       0x14
    //         004b4b62     LEA        EAX,[ESI + 0x490]
    //                              language.dll match for 0x2a34: "Victory Condition"
    //         004b4b68     PUSH       0x2a34
    //         004b4b6d     PUSH       EAX
    //         004b4b6e     PUSH       ESI
    //         004b4b6f     MOV        this,ESI
    //         004b4b71     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4b76     TEST       EAX,EAX
    //         004b4b78     JZ         LAB_004b57d9
    //                              scr_set.cpp:216 (46)
    //         004b4b7e     PUSH       0xb
    //         004b4b80     PUSH       0x18
    //         004b4b82     PUSH       0xb4
    //         004b4b87     PUSH       0x11c
    //         004b4b8c     PUSH       0x14
    //         004b4b8e     LEA        EDI,[ESI + 0x494]
    //         004b4b94     PUSH       0x64
    //         004b4b96     PUSH       0xb4
    //         004b4b9b     PUSH       EDI
    //         004b4b9c     PUSH       ESI
    //         004b4b9d     MOV        this,ESI
    //         004b4b9f     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b4ba4     TEST       EAX,EAX
    //         004b4ba6     JZ         LAB_004b57d9
    //                              scr_set.cpp:217 (7)
    //         004b4bac     MOV        this,dword ptr [EDI]
    //         004b4bae     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:218 (13)
    //         004b4bb3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b4bb9     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         004b4bbe     TEST       EAX,EAX
    //                              scr_set.cpp:220 (16)
    //         004b4bc0     PUSH       0x0
    //         004b4bc2     JZ         LAB_004b4bd2
    //         004b4bc4     MOV        this,dword ptr [EDI]
    //                              language.dll match for 0x10e7: "Default"
    //         004b4bc6     PUSH       0x10e7
    //         004b4bcb     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:221 (2)
    //         004b4bd0     PUSH       0x9
    //                               LAB_004b4bd2                                                 XREF[1]:     004b4bc2(j)  
    //                              scr_set.cpp:224 (12)
    //         004b4bd2     MOV        this,dword ptr [EDI]
    //                              language.dll match for 0x10ec: "Standard"
    //         004b4bd4     PUSH       0x10ec
    //         004b4bd9     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:225 (14)
    //         004b4bde     MOV        this,dword ptr [EDI]
    //         004b4be0     PUSH       0x1
    //                              language.dll match for 0x10e1: "Conquest"
    //         004b4be2     PUSH       0x10e1
    //         004b4be7     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:226 (14)
    //         004b4bec     MOV        this,dword ptr [EDI]
    //         004b4bee     PUSH       0x7
    //                              language.dll match for 0x10e9: "Time Limit"
    //         004b4bf0     PUSH       0x10e9
    //         004b4bf5     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:227 (14)
    //         004b4bfa     MOV        this,dword ptr [EDI]
    //         004b4bfc     PUSH       0x8
    //                              language.dll match for 0x10ea: "Score"
    //         004b4bfe     PUSH       0x10ea
    //         004b4c03     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:228 (17)
    //         004b4c08     MOV        this,dword ptr [EDI]
    //         004b4c0a     PUSH       0x25f0a
    //                              language.dll match for 0x762c: "Select the victory condition.
    //         004b4c0f     PUSH       0x762c
    //         004b4c14     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:231 (50)
    //         004b4c19     PUSH       0x0
    //         004b4c1b     PUSH       0x0
    //         004b4c1d     PUSH       0x0
    //         004b4c1f     PUSH       0xb
    //         004b4c21     PUSH       0x14
    //         004b4c23     PUSH       0xb4
    //         004b4c28     PUSH       0x138
    //         004b4c2d     PUSH       0x14
    //         004b4c2f     LEA        this,[ESI + 0x4a8]
    //                              language.dll match for 0x10e9: "Time Limit"
    //         004b4c35     PUSH       0x10e9
    //         004b4c3a     PUSH       this
    //         004b4c3b     PUSH       ESI
    //         004b4c3c     MOV        this,ESI
    //         004b4c3e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4c43     TEST       EAX,EAX
    //         004b4c45     JZ         LAB_004b57d9
    //                              scr_set.cpp:233 (46)
    //         004b4c4b     PUSH       0xb
    //         004b4c4d     PUSH       0x18
    //         004b4c4f     PUSH       0xb4
    //         004b4c54     PUSH       0x14c
    //         004b4c59     PUSH       0x14
    //         004b4c5b     LEA        EDI,[ESI + 0x4ac]
    //         004b4c61     PUSH       0x64
    //         004b4c63     PUSH       0xb4
    //         004b4c68     PUSH       EDI
    //         004b4c69     PUSH       ESI
    //         004b4c6a     MOV        this,ESI
    //         004b4c6c     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b4c71     TEST       EAX,EAX
    //         004b4c73     JZ         LAB_004b57d9
    //                              scr_set.cpp:234 (7)
    //         004b4c79     MOV        this,dword ptr [EDI]
    //         004b4c7b     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:235 (17)
    //         004b4c80     MOV        this,dword ptr [EDI]
    //         004b4c82     PUSH       0x3a98
    //                              language.dll match for 0x2634: "15,000 years (2:00 hr)"
    //         004b4c87     PUSH       0x2634
    //         004b4c8c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:236 (17)
    //         004b4c91     MOV        this,dword ptr [EDI]
    //         004b4c93     PUSH       0x32c8
    //                              language.dll match for 0x2635: "13,000 years (1:45 hr)"
    //         004b4c98     PUSH       0x2635
    //         004b4c9d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:237 (17)
    //         004b4ca2     MOV        this,dword ptr [EDI]
    //         004b4ca4     PUSH       0x2af8
    //                              language.dll match for 0x2636: "11,000 years (1:30 hr)"
    //         004b4ca9     PUSH       0x2636
    //         004b4cae     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:238 (17)
    //         004b4cb3     MOV        this,dword ptr [EDI]
    //         004b4cb5     PUSH       0x2328
    //                              language.dll match for 0x2637: "9,000 years (1:15 hr)"
    //         004b4cba     PUSH       0x2637
    //         004b4cbf     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:239 (17)
    //         004b4cc4     MOV        this,dword ptr [EDI]
    //         004b4cc6     PUSH       0x1b58
    //                              language.dll match for 0x2638: "7,000 years (60 min)"
    //         004b4ccb     PUSH       0x2638
    //         004b4cd0     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:240 (17)
    //         004b4cd5     MOV        this,dword ptr [EDI]
    //         004b4cd7     PUSH       0x1388
    //                              language.dll match for 0x2639: "5,000 years (40 min)"
    //         004b4cdc     PUSH       0x2639
    //         004b4ce1     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:241 (17)
    //         004b4ce6     MOV        this,dword ptr [EDI]
    //         004b4ce8     PUSH       0xbb8
    //                              language.dll match for 0x263a: "3,000 years (25 min)"
    //         004b4ced     PUSH       0x263a
    //         004b4cf2     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:242 (14)
    //         004b4cf7     MOV        this,dword ptr [EDI]
    //         004b4cf9     PUSH       -0x1
    //                              language.dll match for 0x763b: "Select the time limit for the
    //         004b4cfb     PUSH       0x763b
    //         004b4d00     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:245 (50)
    //         004b4d05     PUSH       0x0
    //         004b4d07     PUSH       0x0
    //         004b4d09     PUSH       0x0
    //         004b4d0b     PUSH       0xb
    //         004b4d0d     PUSH       0x14
    //         004b4d0f     PUSH       0xb4
    //         004b4d14     PUSH       0x138
    //         004b4d19     PUSH       0x14
    //         004b4d1b     LEA        EDX,[ESI + 0x4a0]
    //                              language.dll match for 0x10ea: "Score"
    //         004b4d21     PUSH       0x10ea
    //         004b4d26     PUSH       EDX
    //         004b4d27     PUSH       ESI
    //         004b4d28     MOV        this,ESI
    //         004b4d2a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4d2f     TEST       EAX,EAX
    //         004b4d31     JZ         LAB_004b57d9
    //                              scr_set.cpp:247 (46)
    //         004b4d37     PUSH       0xb
    //         004b4d39     PUSH       0x18
    //         004b4d3b     PUSH       0xb4
    //         004b4d40     PUSH       0x14c
    //         004b4d45     PUSH       0x14
    //         004b4d47     LEA        EDI,[ESI + 0x4a4]
    //         004b4d4d     PUSH       0x64
    //         004b4d4f     PUSH       0xb4
    //         004b4d54     PUSH       EDI
    //         004b4d55     PUSH       ESI
    //         004b4d56     MOV        this,ESI
    //         004b4d58     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b4d5d     TEST       EAX,EAX
    //         004b4d5f     JZ         LAB_004b57d9
    //                              scr_set.cpp:248 (7)
    //         004b4d65     MOV        this,dword ptr [EDI]
    //         004b4d67     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:249 (17)
    //         004b4d6c     MOV        this,dword ptr [EDI]
    //         004b4d6e     PUSH       0xbb8
    //         004b4d73     PUSH       s_3000                                           = "3000"
    //         004b4d78     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:250 (17)
    //         004b4d7d     MOV        this,dword ptr [EDI]
    //         004b4d7f     PUSH       0xa8c
    //         004b4d84     PUSH       s_2700                                           = "2700"
    //         004b4d89     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:251 (17)
    //         004b4d8e     MOV        this,dword ptr [EDI]
    //                              language.dll match for 0x960: "********** TRIBE ERRORS ******
    //         004b4d90     PUSH       0x960
    //         004b4d95     PUSH       s_2400                                           = "2400"
    //         004b4d9a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:252 (17)
    //         004b4d9f     MOV        this,dword ptr [EDI]
    //         004b4da1     PUSH       0x834
    //         004b4da6     PUSH       s_2100                                           = "2100"
    //         004b4dab     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:253 (17)
    //         004b4db0     MOV        this,dword ptr [EDI]
    //         004b4db2     PUSH       0x708
    //         004b4db7     PUSH       s_1800                                           = "1800"
    //         004b4dbc     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:254 (17)
    //         004b4dc1     MOV        this,dword ptr [EDI]
    //         004b4dc3     PUSH       0x5dc
    //         004b4dc8     PUSH       s_1500                                           = "1500"
    //         004b4dcd     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:255 (17)
    //         004b4dd2     MOV        this,dword ptr [EDI]
    //                              language.dll match for 0x4b0: "Ready"
    //         004b4dd4     PUSH       0x4b0
    //         004b4dd9     PUSH       s_1200                                           = "1200"
    //         004b4dde     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:256 (17)
    //         004b4de3     MOV        this,dword ptr [EDI]
    //         004b4de5     PUSH       0x384
    //         004b4dea     PUSH       s_900                                            = "900"
    //         004b4def     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:257 (17)
    //         004b4df4     MOV        this,dword ptr [EDI]
    //         004b4df6     PUSH       0x320
    //         004b4dfb     PUSH       s_800                                            = "800"
    //         004b4e00     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:258 (17)
    //         004b4e05     MOV        this,dword ptr [EDI]
    //         004b4e07     PUSH       0x2bc
    //         004b4e0c     PUSH       s_700                                            = "700"
    //         004b4e11     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:259 (17)
    //         004b4e16     MOV        this,dword ptr [EDI]
    //         004b4e18     PUSH       0x258
    //         004b4e1d     PUSH       s_600                                            = "600"
    //         004b4e22     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:260 (17)
    //         004b4e27     MOV        this,dword ptr [EDI]
    //         004b4e29     PUSH       0x1f4
    //         004b4e2e     PUSH       s_500                                            = "500"
    //         004b4e33     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:261 (17)
    //         004b4e38     MOV        this,dword ptr [EDI]
    //         004b4e3a     PUSH       0x190
    //         004b4e3f     PUSH       s_400                                            = "400"
    //         004b4e44     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:262 (17)
    //         004b4e49     MOV        this,dword ptr [EDI]
    //         004b4e4b     PUSH       0x12c
    //         004b4e50     PUSH       s_300                                            = "300"
    //         004b4e55     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //                              scr_set.cpp:263 (14)
    //         004b4e5a     MOV        this,dword ptr [EDI]
    //         004b4e5c     PUSH       -0x1
    //                              language.dll match for 0x763c: "Select the score for the game
    //         004b4e5e     PUSH       0x763c
    //         004b4e63     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:266 (50)
    //         004b4e68     PUSH       0x1
    //         004b4e6a     PUSH       0x1
    //         004b4e6c     PUSH       0x1
    //         004b4e6e     PUSH       0xb
    //         004b4e70     PUSH       0x5c
    //         004b4e72     PUSH       0xb4
    //         004b4e77     PUSH       0x108
    //         004b4e7c     LEA        EDI,[ESI + 0x498]
    //         004b4e82     PUSH       0x14
    //                              language.dll match for 0x25d9: "This scenario contains Indivi
    //         004b4e84     PUSH       0x25d9
    //         004b4e89     PUSH       EDI
    //         004b4e8a     PUSH       ESI
    //         004b4e8b     MOV        this,ESI
    //         004b4e8d     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4e92     TEST       EAX,EAX
    //         004b4e94     JZ         LAB_004b57d9
    //                              scr_set.cpp:267 (66)
    //         004b4e9a     XOR        EDX,EDX
    //         004b4e9c     MOV        this,dword ptr [EDI]
    //         004b4e9e     MOV        DL,byte ptr [ESI + 0x325]
    //         004b4ea4     PUSH       EDX
    //         004b4ea5     XOR        EDX,EDX
    //         004b4ea7     MOV        DL,byte ptr [ESI + 0x324]
    //         004b4ead     MOV        EAX,dword ptr [this->_padding_]
    //         004b4eaf     PUSH       EDX
    //         004b4eb0     XOR        EDX,EDX
    //         004b4eb2     MOV        DL,byte ptr [ESI + 0x323]
    //         004b4eb8     PUSH       EDX
    //         004b4eb9     XOR        EDX,EDX
    //         004b4ebb     MOV        DL,byte ptr [ESI + 0x322]
    //         004b4ec1     PUSH       EDX
    //         004b4ec2     XOR        EDX,EDX
    //         004b4ec4     MOV        DL,byte ptr [ESI + 0x321]
    //         004b4eca     PUSH       EDX
    //         004b4ecb     XOR        EDX,EDX
    //         004b4ecd     MOV        DL,byte ptr [ESI + 0x320]
    //         004b4ed3     PUSH       EDX
    //         004b4ed4     PUSH       0x3
    //         004b4ed6     CALL       dword ptr [EAX + 0xec]
    //                              scr_set.cpp:270 (53)
    //         004b4edc     PUSH       0x0
    //         004b4ede     PUSH       0x0
    //         004b4ee0     PUSH       0x0
    //         004b4ee2     PUSH       0xb
    //         004b4ee4     PUSH       0x14
    //         004b4ee6     PUSH       0xb4
    //         004b4eeb     PUSH       0x108
    //         004b4ef0     PUSH       0xdc
    //         004b4ef5     LEA        EAX,[ESI + 0x4b8]
    //                              language.dll match for 0x2606: "Starting Age"
    //         004b4efb     PUSH       0x2606
    //         004b4f00     PUSH       EAX
    //         004b4f01     PUSH       ESI
    //         004b4f02     MOV        this,ESI
    //         004b4f04     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4f09     TEST       EAX,EAX
    //         004b4f0b     JZ         LAB_004b57d9
    //                              scr_set.cpp:272 (49)
    //         004b4f11     PUSH       0xb
    //         004b4f13     PUSH       0x18
    //         004b4f15     PUSH       0xb4
    //         004b4f1a     PUSH       0x11c
    //         004b4f1f     PUSH       0xdc
    //         004b4f24     LEA        EDI,[ESI + 0x4bc]
    //         004b4f2a     PUSH       0x64
    //         004b4f2c     PUSH       0xb4
    //         004b4f31     PUSH       EDI
    //         004b4f32     PUSH       ESI
    //         004b4f33     MOV        this,ESI
    //         004b4f35     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b4f3a     TEST       EAX,EAX
    //         004b4f3c     JZ         LAB_004b57d9
    //                              scr_set.cpp:273 (7)
    //         004b4f42     MOV        this,dword ptr [EDI]
    //         004b4f44     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:274 (14)
    //         004b4f49     MOV        this,dword ptr [EDI]
    //         004b4f4b     PUSH       0x0
    //                              language.dll match for 0x10e7: "Default"
    //         004b4f4d     PUSH       0x10e7
    //         004b4f52     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:275 (14)
    //         004b4f57     MOV        this,dword ptr [EDI]
    //         004b4f59     PUSH       0x1
    //                              language.dll match for 0x106e: "Nomad"
    //         004b4f5b     PUSH       0x106e
    //         004b4f60     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:276 (14)
    //         004b4f65     MOV        this,dword ptr [EDI]
    //         004b4f67     PUSH       0x2
    //                              language.dll match for 0x1069: "Stone Age"
    //         004b4f69     PUSH       0x1069
    //         004b4f6e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:277 (14)
    //         004b4f73     MOV        this,dword ptr [EDI]
    //         004b4f75     PUSH       0x3
    //                              language.dll match for 0x106a: "Tool Age"
    //         004b4f77     PUSH       0x106a
    //         004b4f7c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:278 (14)
    //         004b4f81     MOV        this,dword ptr [EDI]
    //         004b4f83     PUSH       0x4
    //                              language.dll match for 0x106b: "Bronze Age"
    //         004b4f85     PUSH       0x106b
    //         004b4f8a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:279 (14)
    //         004b4f8f     MOV        this,dword ptr [EDI]
    //         004b4f91     PUSH       0x5
    //                              language.dll match for 0x106c: "Iron Age"
    //         004b4f93     PUSH       0x106c
    //         004b4f98     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:280 (14)
    //         004b4f9d     MOV        this,dword ptr [EDI]
    //         004b4f9f     PUSH       -0x1
    //                              language.dll match for 0x7631: "Select the age at which the g
    //         004b4fa1     PUSH       0x7631
    //         004b4fa6     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:283 (53)
    //         004b4fab     PUSH       0x0
    //         004b4fad     PUSH       0x0
    //         004b4faf     PUSH       0x0
    //         004b4fb1     PUSH       0xb
    //         004b4fb3     PUSH       0x14
    //         004b4fb5     PUSH       0xb4
    //         004b4fba     PUSH       0x138
    //         004b4fbf     PUSH       0xdc
    //         004b4fc4     LEA        this,[ESI + 0x4c0]
    //                              language.dll match for 0x2607: "Resources"
    //         004b4fca     PUSH       0x2607
    //         004b4fcf     PUSH       this
    //         004b4fd0     PUSH       ESI
    //         004b4fd1     MOV        this,ESI
    //         004b4fd3     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b4fd8     TEST       EAX,EAX
    //         004b4fda     JZ         LAB_004b57d9
    //                              scr_set.cpp:285 (49)
    //         004b4fe0     PUSH       0xb
    //         004b4fe2     PUSH       0x18
    //         004b4fe4     PUSH       0xb4
    //         004b4fe9     PUSH       0x14c
    //         004b4fee     PUSH       0xdc
    //         004b4ff3     LEA        EDI,[ESI + 0x4c4]
    //         004b4ff9     PUSH       0x64
    //         004b4ffb     PUSH       0xb4
    //         004b5000     PUSH       EDI
    //         004b5001     PUSH       ESI
    //         004b5002     MOV        this,ESI
    //         004b5004     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b5009     TEST       EAX,EAX
    //         004b500b     JZ         LAB_004b57d9
    //                              scr_set.cpp:286 (7)
    //         004b5011     MOV        this,dword ptr [EDI]
    //         004b5013     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:287 (14)
    //         004b5018     MOV        this,dword ptr [EDI]
    //         004b501a     PUSH       0x0
    //                              language.dll match for 0x10e7: "Default"
    //         004b501c     PUSH       0x10e7
    //         004b5021     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:288 (14)
    //         004b5026     MOV        this,dword ptr [EDI]
    //         004b5028     PUSH       0x2
    //                              language.dll match for 0x2609: "Medium"
    //         004b502a     PUSH       0x2609
    //         004b502f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:289 (14)
    //         004b5034     MOV        this,dword ptr [EDI]
    //         004b5036     PUSH       0x3
    //                              language.dll match for 0x260a: "High"
    //         004b5038     PUSH       0x260a
    //         004b503d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:290 (14)
    //         004b5042     MOV        this,dword ptr [EDI]
    //         004b5044     PUSH       -0x1
    //                              language.dll match for 0x7632: "Select the quantity of resour
    //         004b5046     PUSH       0x7632
    //         004b504b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:295 (53)
    //         004b5050     PUSH       0x0
    //         004b5052     PUSH       0x0
    //         004b5054     PUSH       0x0
    //         004b5056     PUSH       0xb
    //         004b5058     PUSH       0x14
    //         004b505a     PUSH       0xb4
    //         004b505f     PUSH       0x138
    //         004b5064     PUSH       0x1a4
    //         004b5069     LEA        EDX,[ESI + 0x4c8]
    //                              language.dll match for 0x260d: "Path Finding"
    //         004b506f     PUSH       0x260d
    //         004b5074     PUSH       EDX
    //         004b5075     PUSH       ESI
    //         004b5076     MOV        this,ESI
    //         004b5078     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b507d     TEST       EAX,EAX
    //         004b507f     JZ         LAB_004b57d9
    //                              scr_set.cpp:297 (49)
    //         004b5085     PUSH       0xb
    //         004b5087     PUSH       0x18
    //         004b5089     PUSH       0xb4
    //         004b508e     PUSH       0x14c
    //         004b5093     PUSH       0x1a4
    //         004b5098     LEA        EDI,[ESI + 0x4cc]
    //         004b509e     PUSH       0x64
    //         004b50a0     PUSH       0xb4
    //         004b50a5     PUSH       EDI
    //         004b50a6     PUSH       ESI
    //         004b50a7     MOV        this,ESI
    //         004b50a9     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b50ae     TEST       EAX,EAX
    //         004b50b0     JZ         LAB_004b57d9
    //                              scr_set.cpp:298 (7)
    //         004b50b6     MOV        this,dword ptr [EDI]
    //         004b50b8     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:299 (14)
    //         004b50bd     MOV        this,dword ptr [EDI]
    //         004b50bf     PUSH       0x0
    //                              language.dll match for 0x260e: "Default"
    //         004b50c1     PUSH       0x260e
    //         004b50c6     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:300 (14)
    //         004b50cb     MOV        this,dword ptr [EDI]
    //         004b50cd     PUSH       0x1
    //                              language.dll match for 0x260f: "Medium"
    //         004b50cf     PUSH       0x260f
    //         004b50d4     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:301 (14)
    //         004b50d9     MOV        this,dword ptr [EDI]
    //         004b50db     PUSH       0x2
    //                              language.dll match for 0x2610: "High"
    //         004b50dd     PUSH       0x2610
    //         004b50e2     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:302 (14)
    //         004b50e7     MOV        this,dword ptr [EDI]
    //         004b50e9     PUSH       -0x1
    //                              language.dll match for 0x763e: "Select the path finding capab
    //         004b50eb     PUSH       0x763e
    //         004b50f0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:306 (19)
    //         004b50f5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b50fb     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b5100     TEST       EAX,EAX
    //         004b5102     JZ         LAB_004b51b3
    //                              scr_set.cpp:308 (53)
    //         004b5108     PUSH       0x0
    //         004b510a     PUSH       0x0
    //         004b510c     PUSH       0x0
    //         004b510e     PUSH       0xb
    //         004b5110     PUSH       0x14
    //         004b5112     PUSH       0xb4
    //         004b5117     PUSH       0xd8
    //         004b511c     PUSH       0x1a4
    //         004b5121     LEA        EAX,[ESI + 0x4d0]
    //                              language.dll match for 0x2613: "Population Limit"
    //         004b5127     PUSH       0x2613
    //         004b512c     PUSH       EAX
    //         004b512d     PUSH       ESI
    //         004b512e     MOV        this,ESI
    //         004b5130     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b5135     TEST       EAX,EAX
    //         004b5137     JZ         LAB_004b57d9
    //                              scr_set.cpp:310 (49)
    //         004b513d     PUSH       0xb
    //         004b513f     PUSH       0x18
    //         004b5141     PUSH       0xb4
    //         004b5146     PUSH       0xec
    //         004b514b     PUSH       0x1a4
    //         004b5150     LEA        EBX,[ESI + 0x4d4]
    //         004b5156     PUSH       0x64
    //         004b5158     PUSH       0xb4
    //         004b515d     PUSH       EBX
    //         004b515e     PUSH       ESI
    //         004b515f     MOV        this,ESI
    //         004b5161     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b5166     TEST       EAX,EAX
    //         004b5168     JZ         LAB_004b57d9
    //                              scr_set.cpp:311 (7)
    //         004b516e     MOV        this,dword ptr [EBX]
    //         004b5170     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:313 (5)
    //         004b5175     MOV        EDI,0x19
    //                               LAB_004b517a                                                 XREF[1]:     004b51a3(j)  
    //                              scr_set.cpp:315 (16)
    //         004b517a     PUSH       EDI
    //         004b517b     LEA        this,[ESP + 0x14]
    //         004b517f     PUSH       s_%d                                             = 6425h
    //         004b5184     PUSH       this
    //         004b5185     CALL       sprintf                                          undefined sprintf()
    //                              scr_set.cpp:316 (27)
    //         004b518a     MOV        this,dword ptr [EBX]
    //         004b518c     ADD        ESP,0xc
    //         004b518f     LEA        EDX,[ESP + 0x10]
    //         004b5193     PUSH       EDI
    //         004b5194     PUSH       EDX
    //         004b5195     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
    //         004b519a     ADD        EDI,0x19
    //         004b519d     CMP        EDI,0xc8
    //         004b51a3     JLE        LAB_004b517a
    //                              scr_set.cpp:318 (14)
    //         004b51a5     MOV        this,dword ptr [EBX]
    //         004b51a7     PUSH       -0x1
    //                              language.dll match for 0x763f: "Select the maximum number of 
    //         004b51a9     PUSH       0x763f
    //         004b51ae     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                               LAB_004b51b3                                                 XREF[1]:     004b5102(j)  
    //                              scr_set.cpp:322 (53)
    //         004b51b3     PUSH       0x0
    //         004b51b5     PUSH       0x0
    //         004b51b7     PUSH       0x0
    //         004b51b9     PUSH       0xb
    //         004b51bb     PUSH       0x14
    //         004b51bd     PUSH       0xb4
    //         004b51c2     PUSH       0x108
    //         004b51c7     PUSH       0x1a4
    //         004b51cc     LEA        EAX,[ESI + 0x4b0]
    //                              language.dll match for 0x2bcf: "Difficulty Level"
    //         004b51d2     PUSH       0x2bcf
    //         004b51d7     PUSH       EAX
    //         004b51d8     PUSH       ESI
    //         004b51d9     MOV        this,ESI
    //         004b51db     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b51e0     TEST       EAX,EAX
    //         004b51e2     JZ         LAB_004b57d9
    //                              scr_set.cpp:324 (49)
    //         004b51e8     PUSH       0xb
    //         004b51ea     PUSH       0x18
    //         004b51ec     PUSH       0xb4
    //         004b51f1     PUSH       0x11c
    //         004b51f6     PUSH       0x1a4
    //         004b51fb     LEA        EDI,[ESI + 0x4b4]
    //         004b5201     PUSH       0x64
    //         004b5203     PUSH       0xb4
    //         004b5208     PUSH       EDI
    //         004b5209     PUSH       ESI
    //         004b520a     MOV        this,ESI
    //         004b520c     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         004b5211     TEST       EAX,EAX
    //         004b5213     JZ         LAB_004b57d9
    //                              scr_set.cpp:325 (7)
    //         004b5219     MOV        this,dword ptr [EDI]
    //         004b521b     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_set.cpp:326 (14)
    //         004b5220     MOV        this,dword ptr [EDI]
    //         004b5222     PUSH       0x4
    //                              language.dll match for 0x2bd4: "Easiest"
    //         004b5224     PUSH       0x2bd4
    //         004b5229     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:327 (14)
    //         004b522e     MOV        this,dword ptr [EDI]
    //         004b5230     PUSH       0x3
    //                              language.dll match for 0x2bd3: "Easy"
    //         004b5232     PUSH       0x2bd3
    //         004b5237     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:328 (14)
    //         004b523c     MOV        this,dword ptr [EDI]
    //         004b523e     PUSH       0x2
    //                              language.dll match for 0x2bd2: "Moderate"
    //         004b5240     PUSH       0x2bd2
    //         004b5245     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:329 (14)
    //         004b524a     MOV        this,dword ptr [EDI]
    //         004b524c     PUSH       0x1
    //                              language.dll match for 0x2bd1: "Hard"
    //         004b524e     PUSH       0x2bd1
    //         004b5253     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:330 (14)
    //         004b5258     MOV        this,dword ptr [EDI]
    //         004b525a     PUSH       0x0
    //                              language.dll match for 0x2bd0: "Hardest"
    //         004b525c     PUSH       0x2bd0
    //         004b5261     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_set.cpp:331 (14)
    //         004b5266     MOV        this,dword ptr [EDI]
    //         004b5268     PUSH       -0x1
    //                              language.dll match for 0x763d: "Select the skill of civilizat
    //         004b526a     PUSH       0x763d
    //         004b526f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:334 (38)
    //         004b5274     PUSH       0x0
    //         004b5276     PUSH       0x0
    //         004b5278     PUSH       0x1e
    //         004b527a     PUSH       0x1e
    //         004b527c     LEA        EDI,[ESI + 0x524]
    //         004b5282     PUSH       0x168
    //         004b5287     PUSH       0xa
    //         004b5289     PUSH       EDI
    //         004b528a     PUSH       ESI
    //         004b528b     MOV        this,ESI
    //         004b528d     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
    //         004b5292     TEST       EAX,EAX
    //         004b5294     JZ         LAB_004b57d9
    //                              scr_set.cpp:335 (50)
    //         004b529a     PUSH       0x0
    //         004b529c     PUSH       0x1
    //         004b529e     PUSH       0x0
    //         004b52a0     PUSH       0xb
    //         004b52a2     PUSH       0x1e
    //         004b52a4     PUSH       0xaa
    //         004b52a9     PUSH       0x168
    //         004b52ae     PUSH       0x28
    //         004b52b0     LEA        this,[ESI + 0x534]
    //                              language.dll match for 0x2601: "Fixed Positions"
    //         004b52b6     PUSH       0x2601
    //         004b52bb     PUSH       this
    //         004b52bc     PUSH       ESI
    //         004b52bd     MOV        this,ESI
    //         004b52bf     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b52c4     TEST       EAX,EAX
    //         004b52c6     JZ         LAB_004b57d9
    //                              scr_set.cpp:336 (14)
    //         004b52cc     MOV        this,dword ptr [EDI]
    //         004b52ce     PUSH       -0x1
    //                              language.dll match for 0x7633: "If there is a check in the bo
    //         004b52d0     PUSH       0x7633
    //         004b52d5     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:339 (41)
    //         004b52da     PUSH       0x0
    //         004b52dc     PUSH       0x0
    //         004b52de     PUSH       0x1e
    //         004b52e0     PUSH       0x1e
    //         004b52e2     LEA        EDI,[ESI + 0x52c]
    //         004b52e8     PUSH       0x168
    //         004b52ed     PUSH       0xdc
    //         004b52f2     PUSH       EDI
    //         004b52f3     PUSH       ESI
    //         004b52f4     MOV        this,ESI
    //         004b52f6     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
    //         004b52fb     TEST       EAX,EAX
    //         004b52fd     JZ         LAB_004b57d9
    //                              scr_set.cpp:340 (53)
    //         004b5303     PUSH       0x0
    //         004b5305     PUSH       0x1
    //         004b5307     PUSH       0x0
    //         004b5309     PUSH       0xb
    //         004b530b     PUSH       0x1e
    //         004b530d     PUSH       0xaa
    //         004b5312     PUSH       0x168
    //         004b5317     PUSH       0xfa
    //         004b531c     LEA        EDX,[ESI + 0x53c]
    //                              language.dll match for 0x2604: "Full Tech Tree"
    //         004b5322     PUSH       0x2604
    //         004b5327     PUSH       EDX
    //         004b5328     PUSH       ESI
    //         004b5329     MOV        this,ESI
    //         004b532b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b5330     TEST       EAX,EAX
    //         004b5332     JZ         LAB_004b57d9
    //                              scr_set.cpp:341 (14)
    //         004b5338     MOV        this,dword ptr [EDI]
    //         004b533a     PUSH       -0x1
    //                              language.dll match for 0x7637: "If there is a check in the bo
    //                              language.dll match for 0x7637: "If there is a check in the bo
    //         004b533c     PUSH       0x7637
    //         004b5341     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:344 (41)
    //         004b5346     PUSH       0x0
    //         004b5348     PUSH       0x0
    //         004b534a     PUSH       0x1e
    //         004b534c     PUSH       0x1e
    //         004b534e     LEA        EDI,[ESI + 0x528]
    //         004b5354     PUSH       0x168
    //         004b5359     PUSH       0x1ae
    //         004b535e     PUSH       EDI
    //         004b535f     PUSH       ESI
    //         004b5360     MOV        this,ESI
    //         004b5362     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
    //         004b5367     TEST       EAX,EAX
    //         004b5369     JZ         LAB_004b57d9
    //                              scr_set.cpp:345 (53)
    //         004b536f     PUSH       0x0
    //         004b5371     PUSH       0x1
    //         004b5373     PUSH       0x0
    //         004b5375     PUSH       0xb
    //         004b5377     PUSH       0x1e
    //         004b5379     PUSH       0xaa
    //         004b537e     PUSH       0x168
    //         004b5383     PUSH       0x1cc
    //         004b5388     LEA        EAX,[ESI + 0x538]
    //                              language.dll match for 0x25fc: "Reveal Map"
    //         004b538e     PUSH       0x25fc
    //         004b5393     PUSH       EAX
    //         004b5394     PUSH       ESI
    //         004b5395     MOV        this,ESI
    //         004b5397     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b539c     TEST       EAX,EAX
    //         004b539e     JZ         LAB_004b57d9
    //                              scr_set.cpp:346 (14)
    //         004b53a4     MOV        this,dword ptr [EDI]
    //         004b53a6     PUSH       -0x1
    //                              language.dll match for 0x7634: "If there is a check in the bo
    //         004b53a8     PUSH       0x7634
    //         004b53ad     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:349 (15)
    //         004b53b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b53b8     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b53bd     TEST       EAX,EAX
    //         004b53bf     JZ         LAB_004b542d
    //                              scr_set.cpp:351 (41)
    //         004b53c1     PUSH       0x0
    //         004b53c3     PUSH       0x0
    //         004b53c5     PUSH       0x1e
    //         004b53c7     PUSH       0x1e
    //         004b53c9     LEA        EDI,[ESI + 0x530]
    //         004b53cf     PUSH       0x18b
    //         004b53d4     PUSH       0x1ae
    //         004b53d9     PUSH       EDI
    //         004b53da     PUSH       ESI
    //         004b53db     MOV        this,ESI
    //         004b53dd     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
    //         004b53e2     TEST       EAX,EAX
    //         004b53e4     JZ         LAB_004b57d9
    //                              scr_set.cpp:352 (53)
    //         004b53ea     PUSH       0x0
    //         004b53ec     PUSH       0x1
    //         004b53ee     PUSH       0x0
    //         004b53f0     PUSH       0xb
    //         004b53f2     PUSH       0x1e
    //         004b53f4     PUSH       0xa5
    //         004b53f9     PUSH       0x18b
    //         004b53fe     PUSH       0x1cc
    //         004b5403     LEA        this,[ESI + 0x540]
    //                              language.dll match for 0x25fb: "Enable Cheating"
    //         004b5409     PUSH       0x25fb
    //         004b540e     PUSH       this
    //         004b540f     PUSH       ESI
    //         004b5410     MOV        this,ESI
    //         004b5412     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b5417     TEST       EAX,EAX
    //         004b5419     JZ         LAB_004b57d9
    //                              scr_set.cpp:353 (14)
    //         004b541f     MOV        this,dword ptr [EDI]
    //         004b5421     PUSH       -0x1
    //                              language.dll match for 0x7638: "If there is a check in the bo
    //         004b5423     PUSH       0x7638
    //         004b5428     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                               LAB_004b542d                                                 XREF[1]:     004b53bf(j)  
    //                              scr_set.cpp:357 (10)
    //         004b542d     MOV        dword ptr [ESI + 0x4e0],0x14
    //                              scr_set.cpp:358 (10)
    //         004b5437     MOV        dword ptr [ESI + 0x4e4],0x3c
    //                              scr_set.cpp:359 (10)
    //         004b5441     MOV        dword ptr [ESI + 0x4e8],0x258
    //                              scr_set.cpp:361 (15)
    //         004b544b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5451     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b5456     TEST       EAX,EAX
    //         004b5458     JZ         LAB_004b5466
    //                              scr_set.cpp:362 (10)
    //         004b545a     MOV        dword ptr [ESI + 0x4ec],0x6f
    //                              scr_set.cpp:363 (2)
    //         004b5464     JMP        LAB_004b5470
    //                               LAB_004b5466                                                 XREF[1]:     004b5458(j)  
    //                              scr_set.cpp:364 (10)
    //         004b5466     MOV        dword ptr [ESI + 0x4ec],0x18
    //                               LAB_004b5470                                                 XREF[1]:     004b5464(j)  
    //                              scr_set.cpp:366 (53)
    //         004b5470     MOV        EDX,dword ptr [ESI + 0x4ec]
    //         004b5476     MOV        EAX,dword ptr [ESI + 0x4e8]
    //         004b547c     MOV        this,dword ptr [ESI + 0x4e4]
    //         004b5482     PUSH       0xb
    //         004b5484     PUSH       EDX
    //         004b5485     MOV        EDX,dword ptr [ESI + 0x4e0]
    //         004b548b     PUSH       EAX
    //         004b548c     LEA        EDI,[ESI + 0x4f0]
    //         004b5492     PUSH       this
    //         004b5493     PUSH       EDX
    //         004b5494     PUSH       EDI
    //         004b5495     PUSH       ESI
    //         004b5496     MOV        this,ESI
    //         004b5498     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         004b549d     TEST       EAX,EAX
    //         004b549f     JZ         LAB_004b57d9
    //                              scr_set.cpp:367 (30)
    //         004b54a5     MOV        this,dword ptr [ESI + 0x4e8]
    //         004b54ab     MOV        EAX,dword ptr [ESI + 0x14]
    //         004b54ae     SUB        this,0x3c
    //         004b54b1     IMUL       EAX,this
    //         004b54b4     CDQ
    //         004b54b5     IDIV       dword ptr [ESI + 0xf4]
    //         004b54bb     MOV        this,dword ptr [EDI]
    //         004b54bd     PUSH       EAX
    //         004b54be     CALL       TTextPanel::set_second_column_pos                void set_second_column_pos(TTextPanel * this,
    //                              scr_set.cpp:369 (15)
    //         004b54c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b54c9     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b54ce     TEST       EAX,EAX
    //         004b54d0     JZ         LAB_004b550c
    //                              scr_set.cpp:371 (15)
    //         004b54d2     MOV        this,dword ptr [EDI]
    //                              language.dll match for 0x25fd: "Loading list of scenarios..."
    //         004b54d4     PUSH       0x25fd
    //         004b54d9     MOV        EDX,dword ptr [this->_padding_]
    //         004b54db     CALL       dword ptr [EDX + 0xe4]
    //                              scr_set.cpp:372 (14)
    //         004b54e1     MOV        this,dword ptr [EDI]
    //         004b54e3     PUSH       -0x1
    //                              language.dll match for 0x7639: "Select the scenario to play."
    //         004b54e5     PUSH       0x7639
    //         004b54ea     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:373 (27)
    //         004b54ef     MOV        EAX,dword ptr [EDI]
    //         004b54f1     PUSH       0x14
    //         004b54f3     LEA        this,[ESI + 0x4f4]
    //         004b54f9     PUSH       EAX
    //         004b54fa     PUSH       this
    //         004b54fb     MOV        this,ESI
    //         004b54fd     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004b5502     TEST       EAX,EAX
    //         004b5504     JZ         LAB_004b57d9
    //                              scr_set.cpp:375 (2)
    //         004b550a     JMP        LAB_004b552a
    //                               LAB_004b550c                                                 XREF[1]:     004b54d0(j)  
    //                              scr_set.cpp:377 (2)
    //         004b550c     MOV        EDX,dword ptr [EDI]
    //                              scr_set.cpp:378 (19)
    //         004b550e     PUSH       0x0
    //         004b5510     MOV        dword ptr [EDX + 0x80],0x0
    //         004b551a     MOV        this,dword ptr [EDI]
    //         004b551c     CALL       TListPanel::setDrawHighlightBar                  void setDrawHighlightBar(TListPanel * this, i
    //                              scr_set.cpp:379 (9)
    //         004b5521     MOV        this,dword ptr [EDI]
    //         004b5523     PUSH       0x0
    //         004b5525     CALL       TTextPanel::set_spacer_size                      void set_spacer_size(TTextPanel * this, int p
    //                               LAB_004b552a                                                 XREF[1]:     004b550a(j)  
    //                              scr_set.cpp:382 (78)
    //         004b552a     MOV        EAX,dword ptr [ESI + 0x4e4]
    //         004b5530     MOV        this,dword ptr [ESI + 0x4e0]
    //         004b5536     PUSH       0x0
    //         004b5538     PUSH       0x0
    //         004b553a     PUSH       0x0
    //         004b553c     PUSH       0x4
    //         004b553e     PUSH       0x14
    //         004b5540     SUB        EAX,0x14
    //         004b5543     PUSH       0x12c
    //         004b5548     PUSH       EAX
    //         004b5549     PUSH       this
    //         004b554a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5550     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b5555     NEG        EAX
    //         004b5557     SBB        EAX,EAX
    //         004b5559     LEA        EDX,[ESI + 0x4d8]
    //         004b555f     AND        AL,0xde
    //         004b5561     MOV        this,ESI
    //         004b5563     ADD        EAX,0x2620
    //         004b5568     PUSH       EAX
    //         004b5569     PUSH       EDX
    //         004b556a     PUSH       ESI
    //         004b556b     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b5570     TEST       EAX,EAX
    //         004b5572     JZ         LAB_004b57d9
    //                              scr_set.cpp:384 (73)
    //         004b5578     MOV        EAX,dword ptr [ESI + 0x4e4]
    //         004b557e     MOV        this,dword ptr [ESI + 0x4e8]
    //         004b5584     MOV        EDX,dword ptr [ESI + 0x4e0]
    //         004b558a     PUSH       0x0
    //         004b558c     PUSH       0x0
    //         004b558e     PUSH       0x0
    //         004b5590     PUSH       0x4
    //         004b5592     PUSH       0x14
    //         004b5594     SUB        EAX,0x14
    //         004b5597     PUSH       0xdc
    //         004b559c     PUSH       EAX
    //         004b559d     LEA        EAX,[this->_padding_ + EDX*0x1 + 0xffffff24]
    //         004b55a4     LEA        EDI,[ESI + 0x4dc]
    //         004b55aa     PUSH       EAX
    //                              language.dll match for 0x25ff: "Players"
    //         004b55ab     PUSH       0x25ff
    //         004b55b0     PUSH       EDI
    //         004b55b1     PUSH       ESI
    //         004b55b2     MOV        this,ESI
    //         004b55b4     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b55b9     TEST       EAX,EAX
    //         004b55bb     JZ         LAB_004b57d9
    //                              scr_set.cpp:385 (11)
    //         004b55c1     MOV        this,dword ptr [EDI]
    //         004b55c3     PUSH       0x2
    //         004b55c5     PUSH       0x3
    //         004b55c7     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
    //                              scr_set.cpp:389 (18)
    //         004b55cc     MOV        EDX,dword ptr [ESI + 0x4ec]
    //         004b55d2     MOV        EAX,dword ptr [ESI + 0x4e4]
    //         004b55d8     MOV        this,dword ptr [ESI + 0x4e0]
    //                              scr_set.cpp:393 (89)
    //         004b55de     PUSH       0x0
    //         004b55e0     LEA        EAX,[EDX + EAX*0x1 + 0x18]
    //         004b55e4     MOV        EDX,dword ptr [ESI + 0x4e8]
    //         004b55ea     MOV        dword ptr [ESI + 0x514],EDX
    //         004b55f0     MOV        EDX,0x104
    //         004b55f5     PUSH       0x0
    //         004b55f7     PUSH       0x0
    //         004b55f9     MOV        dword ptr [ESI + 0x510],EAX
    //         004b55ff     SUB        EDX,EAX
    //         004b5601     PUSH       0x4
    //         004b5603     PUSH       0x14
    //         004b5605     ADD        EAX,-0x14
    //         004b5608     PUSH       0x12c
    //         004b560d     PUSH       EAX
    //         004b560e     PUSH       this
    //         004b560f     LEA        EAX,[ESI + 0x508]
    //                              language.dll match for 0x2600: "Scenario Instructions"
    //         004b5615     PUSH       0x2600
    //         004b561a     MOV        dword ptr [ESI + 0x50c],this
    //         004b5620     PUSH       EAX
    //         004b5621     PUSH       ESI
    //         004b5622     MOV        this,ESI
    //         004b5624     MOV        dword ptr [ESI + 0x518],EDX
    //         004b562a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b562f     TEST       EAX,EAX
    //         004b5631     JZ         LAB_004b57d9
    //                              scr_set.cpp:395 (64)
    //         004b5637     MOV        this,dword ptr [ESI + 0x518]
    //         004b563d     MOV        EDX,dword ptr [ESI + 0x514]
    //         004b5643     MOV        EAX,dword ptr [ESI + 0x510]
    //         004b5649     PUSH       0x1
    //         004b564b     PUSH       0x0
    //         004b564d     PUSH       0x0
    //         004b564f     PUSH       0xb
    //         004b5651     PUSH       this
    //         004b5652     MOV        this,dword ptr [ESI + 0x50c]
    //         004b5658     PUSH       EDX
    //         004b5659     PUSH       EAX
    //         004b565a     LEA        EDI,[ESI + 0x51c]
    //         004b5660     PUSH       this
    //         004b5661     PUSH       s_                                               = ""
    //         004b5666     PUSH       EDI
    //         004b5667     PUSH       ESI
    //         004b5668     MOV        this,ESI
    //         004b566a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         004b566f     TEST       EAX,EAX
    //         004b5671     JZ         LAB_004b57d9
    //                              scr_set.cpp:396 (66)
    //         004b5677     XOR        EAX,EAX
    //         004b5679     MOV        this,dword ptr [EDI]
    //         004b567b     MOV        AL,byte ptr [ESI + 0x325]
    //         004b5681     PUSH       EAX
    //         004b5682     XOR        EAX,EAX
    //         004b5684     MOV        AL,byte ptr [ESI + 0x324]
    //         004b568a     MOV        EDX,dword ptr [this->_padding_]
    //         004b568c     PUSH       EAX
    //         004b568d     XOR        EAX,EAX
    //         004b568f     MOV        AL,byte ptr [ESI + 0x323]
    //         004b5695     PUSH       EAX
    //         004b5696     XOR        EAX,EAX
    //         004b5698     MOV        AL,byte ptr [ESI + 0x322]
    //         004b569e     PUSH       EAX
    //         004b569f     XOR        EAX,EAX
    //         004b56a1     MOV        AL,byte ptr [ESI + 0x321]
    //         004b56a7     PUSH       EAX
    //         004b56a8     XOR        EAX,EAX
    //         004b56aa     MOV        AL,byte ptr [ESI + 0x320]
    //         004b56b0     PUSH       EAX
    //         004b56b1     PUSH       0x3
    //         004b56b3     CALL       dword ptr [EDX + 0xec]
    //                              scr_set.cpp:398 (27)
    //         004b56b9     MOV        this,dword ptr [EDI]
    //         004b56bb     LEA        EBX,[ESI + 0x520]
    //         004b56c1     PUSH       0x14
    //         004b56c3     PUSH       this
    //         004b56c4     PUSH       EBX
    //         004b56c5     MOV        this,ESI
    //         004b56c7     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         004b56cc     TEST       EAX,EAX
    //         004b56ce     JZ         LAB_004b57d9
    //                              scr_set.cpp:399 (14)
    //         004b56d4     MOV        this,dword ptr [EBX]
    //         004b56d6     PUSH       -0x1
    //                              language.dll match for 0x763a: "Explains what you must do to 
    //         004b56d8     PUSH       0x763a
    //         004b56dd     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:402 (50)
    //         004b56e2     PUSH       0x0
    //         004b56e4     PUSH       0x0
    //         004b56e6     PUSH       0x0
    //         004b56e8     PUSH       0x1e
    //         004b56ea     PUSH       0xf0
    //         004b56ef     PUSH       0x1b8
    //         004b56f4     PUSH       0x3c
    //         004b56f6     LEA        EBX,[ESI + 0x544]
    //         004b56fc     PUSH       0x0
    //                              language.dll match for 0xfa1: "OK"
    //         004b56fe     PUSH       0xfa1
    //         004b5703     PUSH       EBX
    //         004b5704     PUSH       ESI
    //         004b5705     MOV        this,ESI
    //         004b5707     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b570c     TEST       EAX,EAX
    //         004b570e     JZ         LAB_004b57d9
    //                              scr_set.cpp:403 (14)
    //         004b5714     MOV        this,dword ptr [EBX]
    //         004b5716     PUSH       -0x1
    //         004b5718     PUSH       0x7531
    //         004b571d     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:404 (53)
    //         004b5722     PUSH       0x0
    //         004b5724     PUSH       0x0
    //         004b5726     PUSH       0x0
    //         004b5728     PUSH       0x1e
    //         004b572a     PUSH       0xf0
    //         004b572f     PUSH       0x1b8
    //         004b5734     PUSH       0x140
    //         004b5739     LEA        EDI,[ESI + 0x548]
    //         004b573f     PUSH       0x0
    //                              language.dll match for 0xfa2: "Cancel"
    //         004b5741     PUSH       0xfa2
    //         004b5746     PUSH       EDI
    //         004b5747     PUSH       ESI
    //         004b5748     MOV        this,ESI
    //         004b574a     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b574f     TEST       EAX,EAX
    //         004b5751     JZ         LAB_004b57d9
    //                              scr_set.cpp:405 (2)
    //         004b5757     MOV        EAX,dword ptr [EDI]
    //                              scr_set.cpp:406 (34)
    //         004b5759     PUSH       -0x1
    //         004b575b     PUSH       0x7532
    //         004b5760     MOV        dword ptr [EAX + 0x298],0x1b
    //         004b576a     MOV        dword ptr [EAX + 0x29c],0x0
    //         004b5774     MOV        this,dword ptr [EDI]
    //         004b5776     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_set.cpp:407 (46)
    //         004b577b     PUSH       0x0
    //         004b577d     PUSH       0x0
    //         004b577f     PUSH       0x0
    //         004b5781     PUSH       0x1e
    //         004b5783     PUSH       0x1e
    //         004b5785     PUSH       0x1b8
    //         004b578a     PUSH       0x244
    //         004b578f     PUSH       0x0
    //         004b5791     LEA        EDX,[ESI + 0x54c]
    //                              language.dll match for 0xfa9: "?"
    //         004b5797     PUSH       0xfa9
    //         004b579c     PUSH       EDX
    //         004b579d     PUSH       ESI
    //         004b579e     MOV        this,ESI
    //         004b57a0     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         004b57a5     TEST       EAX,EAX
    //         004b57a7     JZ         LAB_004b57d9
    //                              scr_set.cpp:411 (7)
    //         004b57a9     MOV        this,ESI
    //         004b57ab     CALL       TribeGameSettingsScreen::fillScenarios           void fillScenarios(TribeGameSettingsScreen * 
    //                              scr_set.cpp:414 (17)
    //         004b57b0     MOV        this,ESI
    //         004b57b2     MOV        dword ptr [ESI + 0x504],0x1
    //         004b57bc     CALL       TribeGameSettingsScreen::getSettings             void getSettings(TribeGameSettingsScreen * th
    //                              scr_set.cpp:415 (7)
    //         004b57c1     MOV        this,ESI
    //         004b57c3     CALL       TribeGameSettingsScreen::fillMissionText         void fillMissionText(TribeGameSettingsScreen 
    //                              scr_set.cpp:417 (7)
    //         004b57c8     MOV        this,ESI
    //         004b57ca     CALL       TribeGameSettingsScreen::activatePanels          void activatePanels(TribeGameSettingsScreen *
    //                              scr_set.cpp:418 (10)
    //         004b57cf     MOV        EAX,dword ptr [EBX]
    //         004b57d1     MOV        this,ESI
    //         004b57d3     PUSH       EAX
    //         004b57d4     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b57d9                                                 XREF[40]:    004b4984(j), 004b49b6(j), 
    //                                                                                                         004b49e4(j), 004b4a82(j), 
    //                                                                                                         004b4ab3(j), 004b4b78(j), 
    //                                                                                                         004b4ba6(j), 004b4c45(j), 
    //                                                                                                         004b4c73(j), 004b4d31(j), 
    //                                                                                                         004b4d5f(j), 004b4e94(j), 
    //                                                                                                         004b4f0b(j), 004b4f3c(j), 
    //                                                                                                         004b4fda(j), 004b500b(j), 
    //                                                                                                         004b507f(j), 004b50b0(j), 
    //                                                                                                         004b5137(j), 004b5168(j), [more]
    //                              scr_set.cpp:419 (20)
    //         004b57d9     MOV        this,dword ptr [ESP + local_c]
    //         004b57dd     MOV        EAX,ESI
    //         004b57df     POP        EDI
    //         004b57e0     POP        ESI
    //         004b57e1     MOV        dword ptr FS:[0x0],this
    //         004b57e8     POP        EBX
    //         004b57e9     ADD        ESP,0x18
    //         004b57ec     RET
}

// Offset: 0x004B5810
void init_vars(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::init_vars(void)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall init_vars(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //                               ?init_vars@TribeGameSettingsScreen@@IAEXXZ                   XREF[1]:     TribeGameSettingsScreen:004b48bb(c
    //                               TribeGameSettingsScreen::init_vars
    //                              scr_set.cpp:425 (9)
    //         004b5810     XOR        EAX,EAX
    //         004b5812     PUSH       ESI
    //         004b5813     MOV        dword ptr [ECX + this->title],EAX
    //                              scr_set.cpp:428 (6)
    //         004b5819     MOV        dword ptr [ECX + this->mapSizeLabel],EAX
    //                              scr_set.cpp:429 (6)
    //         004b581f     MOV        dword ptr [ECX + this->mapSizeDrop],EAX
    //                              scr_set.cpp:431 (6)
    //         004b5825     MOV        dword ptr [ECX + this->mapTypeLabel],EAX
    //                              scr_set.cpp:432 (6)
    //         004b582b     MOV        dword ptr [ECX + this->mapTypeDrop],EAX
    //                              scr_set.cpp:434 (6)
    //         004b5831     MOV        dword ptr [ECX + this->victoryTypeLabel],EAX
    //                              scr_set.cpp:435 (6)
    //         004b5837     MOV        dword ptr [ECX + this->victoryTypeDrop],EAX
    //                              scr_set.cpp:437 (6)
    //         004b583d     MOV        dword ptr [ECX + this->scoreLabel],EAX
    //                              scr_set.cpp:438 (6)
    //         004b5843     MOV        dword ptr [ECX + this->scoreDrop],EAX
    //                              scr_set.cpp:440 (6)
    //         004b5849     MOV        dword ptr [ECX + this->timeLabel],EAX
    //                              scr_set.cpp:441 (6)
    //         004b584f     MOV        dword ptr [ECX + this->timeDrop],EAX
    //                              scr_set.cpp:443 (6)
    //         004b5855     MOV        dword ptr [ECX + this->victoryFixedText],EAX
    //                              scr_set.cpp:445 (6)
    //         004b585b     MOV        dword ptr [ECX + this->difficultyLabel],EAX
    //                              scr_set.cpp:446 (6)
    //         004b5861     MOV        dword ptr [ECX + this->difficultyDrop],EAX
    //                              scr_set.cpp:448 (6)
    //         004b5867     MOV        dword ptr [ECX + this->ageLabel],EAX
    //                              scr_set.cpp:449 (6)
    //         004b586d     MOV        dword ptr [ECX + this->ageDrop],EAX
    //                              scr_set.cpp:451 (6)
    //         004b5873     MOV        dword ptr [ECX + this->limitLabel],EAX
    //                              scr_set.cpp:452 (6)
    //         004b5879     MOV        dword ptr [ECX + this->limitDrop],EAX
    //                              scr_set.cpp:454 (6)
    //         004b587f     MOV        dword ptr [ECX + this->resourcesLabel],EAX
    //                              scr_set.cpp:455 (6)
    //         004b5885     MOV        dword ptr [ECX + this->resourcesDrop],EAX
    //                              scr_set.cpp:457 (6)
    //         004b588b     MOV        dword ptr [ECX + this->pathingLabel],EAX
    //                              scr_set.cpp:458 (6)
    //         004b5891     MOV        dword ptr [ECX + this->pathingDrop],EAX
    //                              scr_set.cpp:460 (6)
    //         004b5897     MOV        dword ptr [ECX + this->scenarioTitle],EAX
    //                              scr_set.cpp:461 (6)
    //         004b589d     MOV        dword ptr [ECX + this->scenarioPlayersTitle],EAX
    //                              scr_set.cpp:462 (6)
    //         004b58a3     MOV        dword ptr [ECX + this->scenarioList],EAX
    //                              scr_set.cpp:463 (6)
    //         004b58a9     MOV        dword ptr [ECX + this->scenarioScrollbar],EAX
    //                              scr_set.cpp:464 (6)
    //         004b58af     MOV        dword ptr [ECX + this->scenarioCount],EAX
    //                              scr_set.cpp:465 (6)
    //         004b58b5     MOV        dword ptr [ECX + this->scenarioMission],EAX
    //                              scr_set.cpp:466 (6)
    //         004b58bb     MOV        dword ptr [ECX + this->scenarioFixed],EAX
    //                              scr_set.cpp:467 (6)
    //         004b58c1     MOV        dword ptr [ECX + this->scenariosLoaded],EAX
    //                              scr_set.cpp:469 (6)
    //         004b58c7     MOV        dword ptr [ECX + this->missionTitle],EAX
    //                              scr_set.cpp:470 (6)
    //         004b58cd     MOV        dword ptr [ECX + this->missionText],EAX
    //                              scr_set.cpp:471 (17)
    //         004b58d3     MOV        dword ptr [ECX + this->missionScrollbar],EAX
    //         004b58d9     LEA        EDX,[ECX + this->optionText[0]]
    //         004b58df     MOV        ESI,0x4
    //                               LAB_004b58e4                                                 XREF[1]:     004b58ed(j)  
    //                              scr_set.cpp:475 (3)
    //         004b58e4     MOV        dword ptr [EDX + -0x10],EAX
    //                              scr_set.cpp:476 (8)
    //         004b58e7     MOV        dword ptr [EDX],EAX
    //         004b58e9     ADD        EDX,0x4
    //         004b58ec     DEC        ESI
    //         004b58ed     JNZ        LAB_004b58e4
    //                              scr_set.cpp:479 (6)
    //         004b58ef     MOV        dword ptr [ECX + this->okButton],EAX
    //                              scr_set.cpp:480 (6)
    //         004b58f5     MOV        dword ptr [ECX + this->cancelButton],EAX
    //                              scr_set.cpp:481 (6)
    //         004b58fb     MOV        dword ptr [ECX + this->help_button],EAX
    //                              scr_set.cpp:483 (6)
    //         004b5901     MOV        dword ptr [ECX + this->chat_scr],EAX
    //                              scr_set.cpp:485 (10)
    //         004b5907     MOV        dword ptr [ECX + this->last_scenario_line],0xf
    //                              scr_set.cpp:486 (6)
    //         004b5911     MOV        dword ptr [ECX + this->scenario_line_offset],EAX
    //                              scr_set.cpp:488 (6)
    //         004b5917     MOV        dword ptr [ECX + this->last_send_shared],EAX
    //                              scr_set.cpp:489 (2)
    //         004b591d     POP        ESI
    //         004b591e     RET
}

// Offset: 0x004B5920
void TribeGameSettingsScreen(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeGameSettingsScreen::~TribeGameSettingsScreen(void)                    *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeGameSettingsScreen(TribeGameSettingsScreen * t
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004b594b(W), 004b5b8a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004b5b97(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004b593b(W)  
    //                               ??1TribeGameSettingsScreen@@UAE@XZ                           XREF[1]:     `vector_deleting_destructor':004b5
    //                               TribeGameSettingsScreen::~TribeGameSettingsScreen
    //                              scr_set.cpp:495 (37)
    //         004b5920     PUSH       -0x1
    //         004b5922     PUSH       FUN_0055f6b8
    //         004b5927     MOV        EAX,FS:[0x0]
    //         004b592d     PUSH       EAX
    //         004b592e     MOV        dword ptr FS:[0x0],ESP
    //         004b5935     PUSH       this
    //         004b5936     PUSH       EBX
    //         004b5937     PUSH       ESI
    //         004b5938     MOV        ESI,this
    //         004b593a     PUSH       EDI
    //         004b593b     MOV        dword ptr [ESP + local_10],ESI
    //         004b593f     MOV        dword ptr [ESI],TribeGameSettingsScreen::`vfta   = 004b57f0
    //                              scr_set.cpp:496 (20)
    //         004b5945     LEA        EAX,[ESI + 0x478]
    //         004b594b     MOV        dword ptr [ESP + local_4],0x0
    //         004b5953     PUSH       EAX
    //         004b5954     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:497 (14)
    //         004b5959     LEA        this,[ESI + 0x480]
    //         004b595f     PUSH       this
    //         004b5960     MOV        this,ESI
    //         004b5962     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:498 (14)
    //         004b5967     LEA        EDX,[ESI + 0x484]
    //         004b596d     MOV        this,ESI
    //         004b596f     PUSH       EDX
    //         004b5970     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:499 (14)
    //         004b5975     LEA        EAX,[ESI + 0x488]
    //         004b597b     MOV        this,ESI
    //         004b597d     PUSH       EAX
    //         004b597e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:500 (14)
    //         004b5983     LEA        this,[ESI + 0x48c]
    //         004b5989     PUSH       this
    //         004b598a     MOV        this,ESI
    //         004b598c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:501 (14)
    //         004b5991     LEA        EDX,[ESI + 0x490]
    //         004b5997     MOV        this,ESI
    //         004b5999     PUSH       EDX
    //         004b599a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:502 (14)
    //         004b599f     LEA        EAX,[ESI + 0x494]
    //         004b59a5     MOV        this,ESI
    //         004b59a7     PUSH       EAX
    //         004b59a8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:503 (14)
    //         004b59ad     LEA        this,[ESI + 0x4ac]
    //         004b59b3     PUSH       this
    //         004b59b4     MOV        this,ESI
    //         004b59b6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:504 (14)
    //         004b59bb     LEA        EDX,[ESI + 0x4a8]
    //         004b59c1     MOV        this,ESI
    //         004b59c3     PUSH       EDX
    //         004b59c4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:505 (14)
    //         004b59c9     LEA        EAX,[ESI + 0x4a4]
    //         004b59cf     MOV        this,ESI
    //         004b59d1     PUSH       EAX
    //         004b59d2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:506 (14)
    //         004b59d7     LEA        this,[ESI + 0x4a0]
    //         004b59dd     PUSH       this
    //         004b59de     MOV        this,ESI
    //         004b59e0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:507 (14)
    //         004b59e5     LEA        EDX,[ESI + 0x498]
    //         004b59eb     MOV        this,ESI
    //         004b59ed     PUSH       EDX
    //         004b59ee     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:508 (14)
    //         004b59f3     LEA        EAX,[ESI + 0x4b0]
    //         004b59f9     MOV        this,ESI
    //         004b59fb     PUSH       EAX
    //         004b59fc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:509 (14)
    //         004b5a01     LEA        this,[ESI + 0x4b4]
    //         004b5a07     PUSH       this
    //         004b5a08     MOV        this,ESI
    //         004b5a0a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:510 (14)
    //         004b5a0f     LEA        EDX,[ESI + 0x4b8]
    //         004b5a15     MOV        this,ESI
    //         004b5a17     PUSH       EDX
    //         004b5a18     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:511 (14)
    //         004b5a1d     LEA        EAX,[ESI + 0x4bc]
    //         004b5a23     MOV        this,ESI
    //         004b5a25     PUSH       EAX
    //         004b5a26     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:512 (14)
    //         004b5a2b     LEA        this,[ESI + 0x4c0]
    //         004b5a31     PUSH       this
    //         004b5a32     MOV        this,ESI
    //         004b5a34     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:513 (14)
    //         004b5a39     LEA        EDX,[ESI + 0x4c4]
    //         004b5a3f     MOV        this,ESI
    //         004b5a41     PUSH       EDX
    //         004b5a42     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:514 (14)
    //         004b5a47     LEA        EAX,[ESI + 0x4d8]
    //         004b5a4d     PUSH       EAX
    //         004b5a4e     MOV        this,ESI
    //         004b5a50     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:515 (14)
    //         004b5a55     LEA        this,[ESI + 0x4dc]
    //         004b5a5b     PUSH       this
    //         004b5a5c     MOV        this,ESI
    //         004b5a5e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:516 (14)
    //         004b5a63     LEA        EDX,[ESI + 0x4f0]
    //         004b5a69     MOV        this,ESI
    //         004b5a6b     PUSH       EDX
    //         004b5a6c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:517 (14)
    //         004b5a71     LEA        EAX,[ESI + 0x4f4]
    //         004b5a77     MOV        this,ESI
    //         004b5a79     PUSH       EAX
    //         004b5a7a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:518 (14)
    //         004b5a7f     LEA        this,[ESI + 0x508]
    //         004b5a85     PUSH       this
    //         004b5a86     MOV        this,ESI
    //         004b5a88     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:519 (14)
    //         004b5a8d     LEA        EDX,[ESI + 0x51c]
    //         004b5a93     MOV        this,ESI
    //         004b5a95     PUSH       EDX
    //         004b5a96     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:520 (14)
    //         004b5a9b     LEA        EAX,[ESI + 0x520]
    //         004b5aa1     MOV        this,ESI
    //         004b5aa3     PUSH       EAX
    //         004b5aa4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:521 (14)
    //         004b5aa9     LEA        this,[ESI + 0x4c8]
    //         004b5aaf     PUSH       this
    //         004b5ab0     MOV        this,ESI
    //         004b5ab2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:522 (14)
    //         004b5ab7     LEA        EDX,[ESI + 0x4cc]
    //         004b5abd     MOV        this,ESI
    //         004b5abf     PUSH       EDX
    //         004b5ac0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:523 (14)
    //         004b5ac5     LEA        EAX,[ESI + 0x4d0]
    //         004b5acb     MOV        this,ESI
    //         004b5acd     PUSH       EAX
    //         004b5ace     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:524 (25)
    //         004b5ad3     LEA        this,[ESI + 0x4d4]
    //         004b5ad9     PUSH       this
    //         004b5ada     MOV        this,ESI
    //         004b5adc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b5ae1     LEA        EDI,[ESI + 0x534]
    //         004b5ae7     MOV        EBX,0x4
    //                               LAB_004b5aec                                                 XREF[1]:     004b5b03(j)  
    //                              scr_set.cpp:526 (3)
    //         004b5aec     LEA        EDX,[EDI + -0x10]
    //                              scr_set.cpp:528 (8)
    //         004b5aef     MOV        this,ESI
    //         004b5af1     PUSH       EDX
    //         004b5af2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:529 (14)
    //         004b5af7     PUSH       EDI
    //         004b5af8     MOV        this,ESI
    //         004b5afa     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         004b5aff     ADD        EDI,0x4
    //         004b5b02     DEC        EBX
    //         004b5b03     JNZ        LAB_004b5aec
    //                              scr_set.cpp:532 (14)
    //         004b5b05     LEA        EAX,[ESI + 0x544]
    //         004b5b0b     MOV        this,ESI
    //         004b5b0d     PUSH       EAX
    //         004b5b0e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:533 (14)
    //         004b5b13     LEA        this,[ESI + 0x548]
    //         004b5b19     PUSH       this
    //         004b5b1a     MOV        this,ESI
    //         004b5b1c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:534 (14)
    //         004b5b21     LEA        EDX,[ESI + 0x54c]
    //         004b5b27     MOV        this,ESI
    //         004b5b29     PUSH       EDX
    //         004b5b2a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_set.cpp:537 (10)
    //         004b5b2f     MOV        EAX,dword ptr [ESI + 0x4fc]
    //         004b5b35     TEST       EAX,EAX
    //         004b5b37     JZ         LAB_004b5b75
    //                              scr_set.cpp:539 (12)
    //         004b5b39     MOV        EAX,dword ptr [ESI + 0x4f8]
    //         004b5b3f     XOR        EDI,EDI
    //         004b5b41     TEST       EAX,EAX
    //         004b5b43     JLE        LAB_004b5b66
    //                               LAB_004b5b45                                                 XREF[1]:     004b5b64(j)  
    //                              scr_set.cpp:540 (13)
    //         004b5b45     MOV        EAX,dword ptr [ESI + 0x4fc]
    //         004b5b4b     MOV        EAX,dword ptr [EAX + EDI*0x4]
    //         004b5b4e     TEST       EAX,EAX
    //         004b5b50     JZ         LAB_004b5b5b
    //                              scr_set.cpp:541 (20)
    //         004b5b52     PUSH       EAX
    //         004b5b53     CALL       free                                             undefined free()
    //         004b5b58     ADD        ESP,0x4
    //                               LAB_004b5b5b                                                 XREF[1]:     004b5b50(j)  
    //         004b5b5b     MOV        EAX,dword ptr [ESI + 0x4f8]
    //         004b5b61     INC        EDI
    //         004b5b62     CMP        EDI,EAX
    //         004b5b64     JL         LAB_004b5b45
    //                               LAB_004b5b66                                                 XREF[1]:     004b5b43(j)  
    //                              scr_set.cpp:543 (15)
    //         004b5b66     MOV        this,dword ptr [ESI + 0x4fc]
    //         004b5b6c     PUSH       this
    //         004b5b6d     CALL       free                                             undefined free()
    //         004b5b72     ADD        ESP,0x4
    //                               LAB_004b5b75                                                 XREF[1]:     004b5b37(j)  
    //                              scr_set.cpp:546 (10)
    //         004b5b75     MOV        EAX,dword ptr [ESI + 0x500]
    //         004b5b7b     TEST       EAX,EAX
    //         004b5b7d     JZ         LAB_004b5b88
    //                              scr_set.cpp:547 (11)
    //         004b5b7f     PUSH       EAX
    //         004b5b80     CALL       free                                             undefined free()
    //         004b5b85     ADD        ESP,0x4
    //                               LAB_004b5b88                                                 XREF[1]:     004b5b7d(j)  
    //         004b5b88     MOV        this,ESI
    //                              scr_set.cpp:548 (31)
    //         004b5b8a     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004b5b92     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         004b5b97     MOV        this,dword ptr [ESP + local_c]
    //         004b5b9b     POP        EDI
    //         004b5b9c     POP        ESI
    //         004b5b9d     MOV        dword ptr FS:[0x0],this
    //         004b5ba4     POP        EBX
    //         004b5ba5     ADD        ESP,0x10
    //         004b5ba8     RET
}

// Offset: 0x004B5BB0
long TribeGameSettingsScreen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeGameSettingsScreen::handle_idle(void)                            *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TribeGameSettingsScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //                               ?handle_idle@TribeGameSettingsScreen@@UAEJXZ                 XREF[1]:     00573ec4(*)  
    //                               TribeGameSettingsScreen::handle_idle
    //                              scr_set.cpp:554 (3)
    //         004b5bb0     PUSH       ESI
    //         004b5bb1     MOV        ESI,this
    //                              scr_set.cpp:555 (10)
    //         004b5bb3     MOV        EAX,dword ptr [ESI + 0x504]
    //         004b5bb9     TEST       EAX,EAX
    //         004b5bbb     JNZ        LAB_004b5be8
    //                              scr_set.cpp:557 (5)
    //         004b5bbd     CALL       TribeGameSettingsScreen::fillScenarios           void fillScenarios(TribeGameSettingsScreen * 
    //                              scr_set.cpp:558 (7)
    //         004b5bc2     MOV        this,ESI
    //         004b5bc4     CALL       TribeGameSettingsScreen::fillMissionText         void fillMissionText(TribeGameSettingsScreen 
    //                              scr_set.cpp:560 (17)
    //         004b5bc9     MOV        this,ESI
    //         004b5bcb     MOV        dword ptr [ESI + 0x504],0x1
    //         004b5bd5     CALL       TribeGameSettingsScreen::activatePanels          void activatePanels(TribeGameSettingsScreen *
    //                              scr_set.cpp:561 (14)
    //         004b5bda     MOV        EAX,dword ptr [ESI + 0x4f0]
    //         004b5be0     MOV        this,ESI
    //         004b5be2     PUSH       EAX
    //         004b5be3     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b5be8                                                 XREF[1]:     004b5bbb(j)  
    //                              scr_set.cpp:564 (16)
    //         004b5be8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5bee     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         004b5bf4     TEST       EAX,EAX
    //         004b5bf6     JNZ        LAB_004b5c03
    //                              scr_set.cpp:565 (11)
    //         004b5bf8     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //         004b5bfd     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //                               LAB_004b5c03                                                 XREF[1]:     004b5bf6(j)  
    //                              scr_set.cpp:567 (9)
    //         004b5c03     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b5c08     TEST       EAX,EAX
    //         004b5c0a     JZ         LAB_004b5c5e
    //                              scr_set.cpp:569 (10)
    //         004b5c0c     MOV        EAX,dword ptr [ESI + 0x55c]
    //         004b5c12     TEST       EAX,EAX
    //         004b5c14     JNZ        LAB_004b5c1d
    //                              scr_set.cpp:570 (5)
    //         004b5c16     PUSH       0x23a
    //                              scr_set.cpp:571 (2)
    //         004b5c1b     JMP        LAB_004b5c4b
    //                               LAB_004b5c1d                                                 XREF[1]:     004b5c14(j)  
    //                              scr_set.cpp:573 (28)
    //         004b5c1d     PUSH       0x23d
    //         004b5c22     PUSH       s_C:\msdev\work\age1_x1\scr_set.cp               = "C:\\msdev\\work\\age1_x1\\scr_set.cpp"
    //         004b5c27     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004b5c2c     MOV        this,dword ptr [ESI + 0x55c]
    //         004b5c32     ADD        ESP,0x8
    //         004b5c35     SUB        EAX,this
    //         004b5c37     JZ         LAB_004b5c5e
    //                              scr_set.cpp:575 (13)
    //         004b5c39     MOV        this,dword ptr [comm]                            = 00000000
    //         004b5c3f     PUSH       0x0
    //         004b5c41     CALL       TCommunications_Handler::SendSharedData          long SendSharedData(TCommunications_Handler *
    //                              scr_set.cpp:576 (24)
    //         004b5c46     PUSH       0x240
    //                               LAB_004b5c4b                                                 XREF[1]:     004b5c1b(j)  
    //         004b5c4b     PUSH       s_C:\msdev\work\age1_x1\scr_set.cp               = "C:\\msdev\\work\\age1_x1\\scr_set.cpp"
    //         004b5c50     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
    //         004b5c55     ADD        ESP,0x8
    //         004b5c58     MOV        dword ptr [ESI + 0x55c],EAX
    //                               LAB_004b5c5e                                                 XREF[2]:     004b5c0a(j), 004b5c37(j)  
    //                              scr_set.cpp:581 (7)
    //         004b5c5e     MOV        this,ESI
    //         004b5c60     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_set.cpp:582 (2)
    //         004b5c65     POP        ESI
    //         004b5c66     RET
}

// Offset: 0x004B5C70
long TribeGameSettingsScreen::handle_user_command(uint param_1, long param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeGameSettingsScreen::handle_user_command(unsigned int,long)       *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_user_command(TribeGameSettingsScreen * this, 
    //              long              EAX:4          <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     004b5c71(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004b5c79(R)  
    //                               ?handle_user_command@TribeGameSettingsScreen@@UAEJIJ@Z       XREF[1]:     00573edc(*)  
    //                               TribeGameSettingsScreen::handle_user_command
    //                              scr_set.cpp:588 (1)
    //         004b5c70     PUSH       EBX
    //                              scr_set.cpp:589 (22)
    //         004b5c71     MOV        EBX,dword ptr [ESP + param_1]
    //         004b5c75     PUSH       ESI
    //         004b5c76     MOV        ESI,this
    //         004b5c78     PUSH       EDI
    //         004b5c79     MOV        EDI,dword ptr [ESP + param_2]
    //         004b5c7d     MOV        this,dword ptr [ESI + 0x550]
    //         004b5c83     TEST       this,this
    //         004b5c85     JZ         LAB_004b5c92
    //                              scr_set.cpp:591 (7)
    //         004b5c87     MOV        EAX,dword ptr [this->_padding_]
    //         004b5c89     PUSH       EDI
    //         004b5c8a     PUSH       EBX
    //         004b5c8b     CALL       dword ptr [EAX + 0x64]
    //                              scr_set.cpp:592 (2)
    //         004b5c8e     TEST       EAX,EAX
    //                              scr_set.cpp:593 (2)
    //         004b5c90     JNZ        LAB_004b5c9b
    //                               LAB_004b5c92                                                 XREF[1]:     004b5c85(j)  
    //                              scr_set.cpp:595 (9)
    //         004b5c92     PUSH       EDI
    //         004b5c93     PUSH       EBX=>DAT_fffffff8
    //         004b5c94     MOV        this,ESI
    //         004b5c96     CALL       TPanel::handle_user_command                      long handle_user_command(TPanel * this, uint 
    //                               LAB_004b5c9b                                                 XREF[1]:     004b5c90(j)  
    //                              scr_set.cpp:596 (6)
    //         004b5c9b     POP        EDI
    //         004b5c9c     POP        ESI
    //         004b5c9d     POP        EBX
    //         004b5c9e     RET        0x8
}

// Offset: 0x004B5CB0
long TribeGameSettingsScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: virtual long __thiscall TribeGameSettingsScreen::action(class TPanel *,long,unsigned lo... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeGameSettingsScreen * this, TPanel * para
    //              long              EAX:4          <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004b5cb0(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     004b5cb4(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004b5de7(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004b5de2(R)  
    //                               ?action@TribeGameSettingsScreen@@MAEJPAVTPanel@@JKK@Z        XREF[1]:     00573f2c(*)  
    //                               TribeGameSettingsScreen::action
    //                              scr_set.cpp:602 (33)
    //         004b5cb0     MOV        EAX,dword ptr [ESP + param_1]
    //         004b5cb4     MOV        EDX,dword ptr [ESP + param_2]
    //         004b5cb8     PUSH       ESI
    //         004b5cb9     MOV        ESI,this
    //         004b5cbb     TEST       EAX,EAX
    //         004b5cbd     JZ         LAB_004b5de2
    //         004b5cc3     MOV        this,dword ptr [ESI + 0x504]
    //         004b5cc9     TEST       this,this
    //         004b5ccb     JZ         LAB_004b5de2
    //                              scr_set.cpp:606 (13)
    //         004b5cd1     CMP        EAX,dword ptr [ESI + 0x544]
    //         004b5cd7     JNZ        LAB_004b5d11
    //         004b5cd9     CMP        EDX,0x1
    //         004b5cdc     JNZ        LAB_004b5d11
    //                              scr_set.cpp:608 (14)
    //         004b5cde     MOV        EAX,dword ptr [ESI + 0x4f0]
    //         004b5ce4     MOV        this,ESI
    //         004b5ce6     PUSH       EAX
    //         004b5ce7     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_set.cpp:641 (7)
    //         004b5cec     MOV        this,ESI
    //         004b5cee     CALL       TribeGameSettingsScreen::sendSettings            void sendSettings(TribeGameSettingsScreen * t
    //                              scr_set.cpp:644 (21)
    //         004b5cf3     MOV        this,dword ptr [ESI + 0x550]
    //         004b5cf9     PUSH       0x0
    //         004b5cfb     PUSH       0x0
    //         004b5cfd     PUSH       0x1
    //         004b5cff     MOV        EDX,dword ptr [this->_padding_]
    //         004b5d01     PUSH       ESI
    //         004b5d02     CALL       dword ptr [EDX + 0xb4]
    //                              scr_set.cpp:645 (5)
    //         004b5d08     MOV        EAX,0x1
    //                              scr_set.cpp:700 (4)
    //         004b5d0d     POP        ESI
    //         004b5d0e     RET        0x10
    //                               LAB_004b5d11                                                 XREF[2]:     004b5cd7(j), 004b5cdc(j)  
    //                              scr_set.cpp:649 (13)
    //         004b5d11     CMP        EAX,dword ptr [ESI + 0x548]
    //         004b5d17     JNZ        LAB_004b5d51
    //         004b5d19     CMP        EDX,0x1
    //         004b5d1c     JNZ        LAB_004b5d51
    //                              scr_set.cpp:651 (14)
    //         004b5d1e     MOV        EAX,dword ptr [ESI + 0x4f0]
    //         004b5d24     MOV        this,ESI
    //         004b5d26     PUSH       EAX
    //         004b5d27     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_set.cpp:654 (7)
    //         004b5d2c     MOV        this,ESI
    //         004b5d2e     CALL       TribeGameSettingsScreen::getSettings             void getSettings(TribeGameSettingsScreen * th
    //                              scr_set.cpp:655 (21)
    //         004b5d33     MOV        this,dword ptr [ESI + 0x550]
    //         004b5d39     PUSH       0x0
    //         004b5d3b     PUSH       0x0
    //         004b5d3d     PUSH       0x0
    //         004b5d3f     MOV        EDX,dword ptr [this->_padding_]
    //         004b5d41     PUSH       ESI
    //         004b5d42     CALL       dword ptr [EDX + 0xb4]
    //                              scr_set.cpp:656 (5)
    //         004b5d48     MOV        EAX,0x1
    //                              scr_set.cpp:700 (4)
    //         004b5d4d     POP        ESI
    //         004b5d4e     RET        0x10
    //                               LAB_004b5d51                                                 XREF[2]:     004b5d17(j), 004b5d1c(j)  
    //                              scr_set.cpp:660 (13)
    //         004b5d51     CMP        EAX,dword ptr [ESI + 0x54c]
    //         004b5d57     JNZ        LAB_004b5d6e
    //         004b5d59     CMP        EDX,0x1
    //         004b5d5c     JNZ        LAB_004b5d6e
    //                              scr_set.cpp:662 (7)
    //         004b5d5e     MOV        this,ESI
    //         004b5d60     CALL       TEasy_Panel::setup_popup_help                    void setup_popup_help(TEasy_Panel * this)
    //                              scr_set.cpp:663 (5)
    //         004b5d65     MOV        EAX,0x1
    //                              scr_set.cpp:700 (4)
    //         004b5d6a     POP        ESI
    //         004b5d6b     RET        0x10
    //                               LAB_004b5d6e                                                 XREF[2]:     004b5d57(j), 004b5d5c(j)  
    //                              scr_set.cpp:667 (14)
    //         004b5d6e     MOV        this,dword ptr [ESI + 0x494]
    //         004b5d74     CMP        EAX,this
    //         004b5d76     JNZ        LAB_004b5db0
    //         004b5d78     TEST       EDX,EDX
    //         004b5d7a     JNZ        LAB_004b5db0
    //                              scr_set.cpp:669 (13)
    //         004b5d7c     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b5d81     SUB        EAX,0x7
    //         004b5d84     JZ         LAB_004b5d93
    //         004b5d86     DEC        EAX
    //         004b5d87     JNZ        LAB_004b5dd2
    //                              scr_set.cpp:675 (8)
    //         004b5d89     MOV        this,dword ptr [ESI + 0x4a4]
    //         004b5d8f     PUSH       0x7
    //                              scr_set.cpp:676 (2)
    //         004b5d91     JMP        LAB_004b5d9b
    //                               LAB_004b5d93                                                 XREF[1]:     004b5d84(j)  
    //                              scr_set.cpp:672 (13)
    //         004b5d93     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b5d99     PUSH       0x3
    //                               LAB_004b5d9b                                                 XREF[1]:     004b5d91(j)  
    //         004b5d9b     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:678 (7)
    //         004b5da0     MOV        this,ESI
    //         004b5da2     CALL       TribeGameSettingsScreen::activatePanels          void activatePanels(TribeGameSettingsScreen *
    //                              scr_set.cpp:679 (5)
    //         004b5da7     MOV        EAX,0x1
    //                              scr_set.cpp:700 (4)
    //         004b5dac     POP        ESI
    //         004b5dad     RET        0x10
    //                               LAB_004b5db0                                                 XREF[2]:     004b5d76(j), 004b5d7a(j)  
    //                              scr_set.cpp:683 (8)
    //         004b5db0     CMP        EAX,dword ptr [ESI + 0x4f0]
    //         004b5db6     JNZ        LAB_004b5de2
    //                              scr_set.cpp:685 (5)
    //         004b5db8     CMP        EDX,0x3
    //         004b5dbb     JNZ        LAB_004b5dc6
    //                              scr_set.cpp:687 (5)
    //         004b5dbd     MOV        EAX,0x1
    //                              scr_set.cpp:700 (4)
    //         004b5dc2     POP        ESI
    //         004b5dc3     RET        0x10
    //                               LAB_004b5dc6                                                 XREF[1]:     004b5dbb(j)  
    //                              scr_set.cpp:690 (5)
    //         004b5dc6     CMP        EDX,0x1
    //         004b5dc9     JNZ        LAB_004b5de2
    //                              scr_set.cpp:692 (7)
    //         004b5dcb     MOV        this,ESI
    //         004b5dcd     CALL       TribeGameSettingsScreen::fillMissionText         void fillMissionText(TribeGameSettingsScreen 
    //                               LAB_004b5dd2                                                 XREF[1]:     004b5d87(j)  
    //                              scr_set.cpp:693 (7)
    //         004b5dd2     MOV        this,ESI
    //         004b5dd4     CALL       TribeGameSettingsScreen::activatePanels          void activatePanels(TribeGameSettingsScreen *
    //                              scr_set.cpp:694 (5)
    //         004b5dd9     MOV        EAX,0x1
    //                              scr_set.cpp:700 (4)
    //         004b5dde     POP        ESI
    //         004b5ddf     RET        0x10
    //                               LAB_004b5de2                                                 XREF[4]:     004b5cbd(j), 004b5ccb(j), 
    //                                                                                                         004b5db6(j), 004b5dc9(j)  
    //                              scr_set.cpp:699 (19)
    //         004b5de2     MOV        this,dword ptr [ESP + param_4]
    //         004b5de6     PUSH       this
    //         004b5de7     MOV        this,dword ptr [ESP + param_3]
    //         004b5deb     PUSH       this
    //         004b5dec     PUSH       EDX
    //         004b5ded     PUSH       EAX
    //         004b5dee     MOV        this,ESI
    //         004b5df0     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_set.cpp:700 (4)
    //         004b5df5     POP        ESI
    //         004b5df6     RET        0x10
}

// Offset: 0x004B5E00
void fillScenarios(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::fillScenarios(void)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall fillScenarios(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              char[260]         Stack[-0x108   scenario_file             XREF[0,2]:   004b6048(*), 004b605d(*)  
    //              char[260]         Stack[-0x20c   file_name                 XREF[0,5]:   004b5e90(*), 004b5ec5(*), 004b5ec9(*), 004b5efa(*), 
    //                                                                                     004b5ed5(R)  
    //              char[20]          Stack[-0x220   player_str                XREF[2,3]:   004b5e4b(W), 004b5f74(R), 004b600e(*), 004b6023(*), 
    //                                                                                     004b6074(*)  
    //              RGE_Scenario_F    Stack[-0x224   scenario_info_file        XREF[9]:     004b5e5a(W), 004b5e6e(R), 004b5ef6(R), 004b5f11(RW), 
    //                                                                                     004b5f68(W), 004b5fdf(R), 004b606b(R), 004b6086(R), 
    //                                                                                     004b6093(W)  
    //              int               Stack[-0x228   i
    //                               ?fillScenarios@TribeGameSettingsScreen@@IAEXXZ               XREF[2]:     TribeGameSettingsScreen:004b57ab(c
    //                               TribeGameSettingsScreen::fillScenarios                                    handle_idle:004b5bbd(c)  
    //                              scr_set.cpp:706 (12)
    //         004b5e00     SUB        ESP,0x224
    //         004b5e06     PUSH       EBX
    //         004b5e07     PUSH       EBP
    //         004b5e08     MOV        EBP,this
    //         004b5e0a     PUSH       ESI
    //         004b5e0b     PUSH       EDI
    //                              scr_set.cpp:718 (11)
    //         004b5e0c     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b5e12     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_set.cpp:719 (8)
    //         004b5e17     XOR        ESI,ESI
    //         004b5e19     MOV        dword ptr [EBP + 0x558],ESI
    //                              scr_set.cpp:721 (34)
    //         004b5e1f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5e25     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b5e2a     TEST       EAX,EAX
    //         004b5e2c     JNZ        LAB_004b5e41
    //         004b5e2e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5e34     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         004b5e39     TEST       EAX,EAX
    //         004b5e3b     JZ         LAB_004b609d
    //                               LAB_004b5e41                                                 XREF[1]:     004b5e2c(j)  
    //                              scr_set.cpp:723 (8)
    //         004b5e41     MOV        EAX,[rge_base_game]                              = 00000000
    //         004b5e46     MOV        EBX,dword ptr [EAX + 0x8]
    //                              scr_set.cpp:724 (11)
    //         004b5e49     MOV        this,EBX
    //         004b5e4b     MOV        dword ptr [ESP + player_str[0]],EBX
    //         004b5e4f     CALL       RGE_Scenario_File_Info::reload_scenarios         void reload_scenarios(RGE_Scenario_File_Info 
    //                              scr_set.cpp:727 (6)
    //         004b5e54     MOV        this,dword ptr [EBP + 0x4f0]
    //                              scr_set.cpp:730 (20)
    //         004b5e5a     MOV        dword ptr [ESP + scenario_info_file],ESI
    //         004b5e5e     MOV        dword ptr [ECX + this->_padding_],0x1
    //         004b5e68     MOV        dword ptr [EBP + 0x4f8],ESI
    //                               LAB_004b5e6e                                                 XREF[1]:     004b5f15(j)  
    //                              scr_set.cpp:733 (14)
    //         004b5e6e     MOV        EDX,dword ptr [ESP + scenario_info_file]
    //         004b5e72     MOV        this,EBX
    //         004b5e74     PUSH       EDX
    //         004b5e75     CALL       RGE_Scenario_File_Info::get_scenario_name        char * get_scenario_name(RGE_Scenario_File_In
    //         004b5e7a     MOV        EDX,EAX
    //                              scr_set.cpp:734 (8)
    //         004b5e7c     TEST       EDX,EDX
    //         004b5e7e     JZ         LAB_004b5f1a
    //                              scr_set.cpp:738 (12)
    //         004b5e84     MOV        EDI,EDX
    //         004b5e86     OR         this,0xffffffff
    //         004b5e89     XOR        EAX,EAX
    //         004b5e8b     SCASB.RE   ES:EDI
    //         004b5e8d     NOT        this
    //         004b5e8f     DEC        this
    //                              scr_set.cpp:739 (17)
    //         004b5e90     LEA        EAX=>file_name[4],[ESP + 0x2c]
    //         004b5e94     MOV        ESI,this
    //         004b5e96     SUB        ESI,0x4
    //         004b5e99     PUSH       ESI
    //         004b5e9a     PUSH       EDX
    //         004b5e9b     PUSH       EAX
    //         004b5e9c     CALL       strncpy                                          undefined strncpy()
    //                              scr_set.cpp:741 (85)
    //         004b5ea1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5ea7     ADD        ESP,0xc
    //         004b5eaa     MOV        byte ptr [ESP + ESI*0x1 + 0x2c],0x0
    //         004b5eaf     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b5eb4     TEST       EAX,EAX
    //         004b5eb6     JNZ        LAB_004b5ef6
    //         004b5eb8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b5ebe     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
    //         004b5ec3     MOV        ESI,EAX
    //         004b5ec5     LEA        this=>file_name[4],[ESP + 0x2c]
    //                               LAB_004b5ec9                                                 XREF[1]:     004b5ee7(j)  
    //         004b5ec9     MOV        DL,byte ptr [this->_padding_]=>file_name[4]
    //         004b5ecb     MOV        AL,DL
    //         004b5ecd     CMP        DL,byte ptr [ESI]
    //         004b5ecf     JNZ        LAB_004b5eed
    //         004b5ed1     TEST       AL,AL
    //         004b5ed3     JZ         LAB_004b5ee9
    //         004b5ed5     MOV        DL,byte ptr [ECX + file_name[5]]
    //         004b5ed8     MOV        AL,DL
    //         004b5eda     CMP        DL,byte ptr [ESI + 0x1]
    //         004b5edd     JNZ        LAB_004b5eed
    //         004b5edf     ADD        this,0x2
    //         004b5ee2     ADD        ESI,0x2
    //         004b5ee5     TEST       AL,AL
    //         004b5ee7     JNZ        LAB_004b5ec9
    //                               LAB_004b5ee9                                                 XREF[1]:     004b5ed3(j)  
    //         004b5ee9     XOR        EAX,EAX
    //         004b5eeb     JMP        LAB_004b5ef2
    //                               LAB_004b5eed                                                 XREF[2]:     004b5ecf(j), 004b5edd(j)  
    //         004b5eed     SBB        EAX,EAX
    //         004b5eef     SBB        EAX,-0x1
    //                               LAB_004b5ef2                                                 XREF[1]:     004b5eeb(j)  
    //         004b5ef2     TEST       EAX,EAX
    //         004b5ef4     JNZ        LAB_004b5f11
    //                               LAB_004b5ef6                                                 XREF[1]:     004b5eb6(j)  
    //                              scr_set.cpp:743 (21)
    //         004b5ef6     MOV        EAX,dword ptr [ESP + scenario_info_file]
    //         004b5efa     LEA        this=>file_name[4],[ESP + 0x2c]
    //         004b5efe     PUSH       EAX
    //         004b5eff     PUSH       this
    //         004b5f00     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b5f06     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              scr_set.cpp:744 (6)
    //         004b5f0b     INC        dword ptr [EBP + 0x4f8]
    //                               LAB_004b5f11                                                 XREF[1]:     004b5ef4(j)  
    //                              scr_set.cpp:747 (9)
    //         004b5f11     INC        dword ptr [ESP + scenario_info_file]
    //         004b5f15     JMP        LAB_004b5e6e
    //                               LAB_004b5f1a                                                 XREF[1]:     004b5e7e(j)  
    //                              scr_set.cpp:751 (23)
    //         004b5f1a     MOV        EDX,dword ptr [EBP + 0x4f8]
    //         004b5f20     PUSH       0x4
    //         004b5f22     PUSH       EDX
    //         004b5f23     CALL       calloc                                           undefined calloc()
    //         004b5f28     ADD        ESP,0x8
    //         004b5f2b     MOV        dword ptr [EBP + 0x4fc],EAX
    //                              scr_set.cpp:752 (14)
    //         004b5f31     MOV        EAX,dword ptr [EBP + 0x4f8]
    //         004b5f37     PUSH       0x4
    //         004b5f39     PUSH       EAX
    //         004b5f3a     CALL       calloc                                           undefined calloc()
    //                              scr_set.cpp:753 (31)
    //         004b5f3f     MOV        this,dword ptr [EBP + 0x4fc]
    //         004b5f45     ADD        ESP,0x8
    //         004b5f48     TEST       this,this
    //         004b5f4a     MOV        dword ptr [EBP + 0x500],EAX
    //         004b5f50     JZ         LAB_004b609d
    //         004b5f56     TEST       EAX,EAX
    //         004b5f58     JZ         LAB_004b609d
    //                              scr_set.cpp:755 (26)
    //         004b5f5e     MOV        EAX,dword ptr [EBP + 0x4f8]
    //         004b5f64     XOR        ESI,ESI
    //         004b5f66     TEST       EAX,EAX
    //         004b5f68     MOV        dword ptr [ESP + scenario_info_file],ESI
    //         004b5f6c     JLE        LAB_004b609d
    //         004b5f72     JMP        LAB_004b5f78
    //                               LAB_004b5f74                                                 XREF[1]:     004b6097(j)  
    //         004b5f74     MOV        EBX,dword ptr [ESP + player_str[0]]
    //                               LAB_004b5f78                                                 XREF[1]:     004b5f72(j)  
    //                              scr_set.cpp:758 (22)
    //         004b5f78     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b5f7e     PUSH       ESI
    //         004b5f7f     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this, long param_1)
    //         004b5f84     PUSH       EAX
    //         004b5f85     MOV        this,EBX
    //         004b5f87     CALL       RGE_Scenario_File_Info::get_scenario_info        RGE_Scenario_Header * get_scenario_info(RGE_S
    //         004b5f8c     MOV        EBX,EAX
    //                              scr_set.cpp:760 (8)
    //         004b5f8e     TEST       EBX,EBX
    //         004b5f90     JZ         LAB_004b608a
    //                              scr_set.cpp:763 (24)
    //         004b5f96     PUSH       0x1
    //         004b5f98     PUSH       0x1000
    //         004b5f9d     CALL       calloc                                           undefined calloc()
    //         004b5fa2     MOV        this,dword ptr [EBP + 0x4fc]
    //         004b5fa8     ADD        ESP,0x8
    //         004b5fab     MOV        dword ptr [this->_padding_ + ESI*0x4],EAX
    //                              scr_set.cpp:764 (13)
    //         004b5fae     MOV        EDX,dword ptr [EBP + 0x4fc]
    //         004b5fb4     MOV        EDX,dword ptr [EDX + ESI*0x4]
    //         004b5fb7     TEST       EDX,EDX
    //         004b5fb9     JZ         LAB_004b5fe3
    //                              scr_set.cpp:766 (7)
    //         004b5fbb     MOV        EDI,dword ptr [EBX + 0x10]
    //         004b5fbe     TEST       EDI,EDI
    //         004b5fc0     JZ         LAB_004b5fe3
    //                              scr_set.cpp:767 (33)
    //         004b5fc2     OR         this,0xffffffff
    //         004b5fc5     XOR        EAX,EAX
    //         004b5fc7     SCASB.RE   ES:EDI
    //         004b5fc9     NOT        this
    //         004b5fcb     SUB        EDI,this
    //         004b5fcd     MOV        EAX,this
    //         004b5fcf     MOV        ESI,EDI
    //         004b5fd1     MOV        EDI,EDX
    //         004b5fd3     SHR        this,0x2
    //         004b5fd6     MOVSD.REP  ES:EDI,ESI
    //         004b5fd8     MOV        this,EAX
    //         004b5fda     AND        this,0x3
    //         004b5fdd     MOVSB.REP  ES:EDI,ESI
    //         004b5fdf     MOV        ESI,dword ptr [ESP + scenario_info_file]
    //                               LAB_004b5fe3                                                 XREF[2]:     004b5fb9(j), 004b5fc0(j)  
    //                              scr_set.cpp:771 (12)
    //         004b5fe3     MOV        this,dword ptr [EBP + 0x500]
    //         004b5fe9     MOV        EDX,dword ptr [EBX + 0x14]
    //         004b5fec     MOV        dword ptr [this->_padding_ + ESI*0x4],EDX
    //                              scr_set.cpp:774 (3)
    //         004b5fef     MOV        EBX,dword ptr [EBX + 0x18]
    //                              scr_set.cpp:775 (8)
    //         004b5ff2     TEST       EBX,EBX
    //         004b5ff4     JLE        LAB_004b608a
    //                              scr_set.cpp:777 (17)
    //         004b5ffa     MOV        EAX,dword ptr [EBP + 0x500]
    //         004b6000     CMP        dword ptr [EAX + ESI*0x4],0x0
    //         004b6004     JNZ        LAB_004b6022
    //         004b6006     CMP        EBX,0x3
    //         004b6009     JL         LAB_004b6022
    //                              scr_set.cpp:780 (23)
    //         004b600b     PUSH       EBX
    //         004b600c     PUSH       0x2
    //         004b600e     LEA        this=>player_str[4],[ESP + 0x20]
    //         004b6012     PUSH       s_%d_-_%d                                        = "%d - %d"
    //         004b6017     PUSH       this
    //         004b6018     CALL       sprintf                                          undefined sprintf()
    //         004b601d     ADD        ESP,0x10
    //         004b6020     JMP        LAB_004b6035
    //                               LAB_004b6022                                                 XREF[2]:     004b6004(j), 004b6009(j)  
    //                              scr_set.cpp:778 (19)
    //         004b6022     PUSH       EBX
    //         004b6023     LEA        EDX=>player_str[4],[ESP + 0x1c]
    //         004b6027     PUSH       s_%d                                             = 6425h
    //         004b602c     PUSH       EDX
    //         004b602d     CALL       sprintf                                          undefined sprintf()
    //         004b6032     ADD        ESP,0xc
    //                               LAB_004b6035                                                 XREF[1]:     004b6020(j)  
    //                              scr_set.cpp:781 (32)
    //         004b6035     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b603b     PUSH       ESI
    //         004b603c     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this, long param
    //         004b6041     MOV        EDI,EAX
    //         004b6043     OR         this,0xffffffff
    //         004b6046     XOR        EAX,EAX
    //         004b6048     LEA        EDX=>scenario_file[4],[ESP + 0x130]
    //         004b604f     SCASB.RE   ES:EDI
    //         004b6051     NOT        this
    //         004b6053     SUB        EDI,this
    //                              scr_set.cpp:782 (72)
    //         004b6055     PUSH       0x0
    //         004b6057     MOV        EAX,this
    //         004b6059     MOV        ESI,EDI
    //         004b605b     MOV        EDI,EDX
    //         004b605d     LEA        EDX=>scenario_file[4],[ESP + 0x134]
    //         004b6064     SHR        this,0x2
    //         004b6067     MOVSD.REP  ES:EDI,ESI
    //         004b6069     MOV        this,EAX
    //         004b606b     MOV        EAX,dword ptr [ESP + scenario_info_file]
    //         004b606f     AND        this,0x3
    //         004b6072     MOVSB.REP  ES:EDI,ESI
    //         004b6074     LEA        this=>player_str[4],[ESP + 0x1c]
    //         004b6078     PUSH       this
    //         004b6079     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b607f     PUSH       EDX
    //         004b6080     PUSH       EAX
    //         004b6081     CALL       TTextPanel::change_line                          int change_line(TTextPanel * this, long param
    //         004b6086     MOV        ESI,dword ptr [ESP + scenario_info_file]
    //                               LAB_004b608a                                                 XREF[2]:     004b5f90(j), 004b5ff4(j)  
    //         004b608a     MOV        EAX,dword ptr [EBP + 0x4f8]
    //         004b6090     INC        ESI
    //         004b6091     CMP        ESI,EAX
    //         004b6093     MOV        dword ptr [ESP + scenario_info_file],ESI
    //         004b6097     JL         LAB_004b5f74
    //                               LAB_004b609d                                                 XREF[4]:     004b5e3b(j), 004b5f50(j), 
    //                                                                                                         004b5f58(j), 004b5f6c(j)  
    //                              scr_set.cpp:789 (16)
    //         004b609d     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b60a3     MOV        dword ptr [ECX + this->_padding_],0x0
    //                              scr_set.cpp:791 (45)
    //         004b60ad     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b60b3     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b60b8     TEST       EAX,EAX
    //         004b60ba     JNZ        LAB_004b60da
    //         004b60bc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b60c2     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
    //         004b60c7     TEST       EAX,EAX
    //         004b60c9     JZ         LAB_004b6101
    //         004b60cb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b60d1     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
    //         004b60d6     TEST       AL,AL
    //         004b60d8     JNZ        LAB_004b6101
    //                               LAB_004b60da                                                 XREF[1]:     004b60ba(j)  
    //                              scr_set.cpp:793 (33)
    //         004b60da     PUSH       -0x2
    //         004b60dc     PUSH       s_2_-_8                                          = "2 - 8"
    //                              language.dll match for 0x25b5: "Random Map"
    //         004b60e1     PUSH       0x25b5
    //         004b60e6     MOV        this,EBP
    //         004b60e8     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         004b60ed     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b60f3     PUSH       EAX
    //         004b60f4     PUSH       0x0
    //         004b60f6     CALL       TTextPanel::insert_line                          int insert_line(TTextPanel * this, long param
    //                              scr_set.cpp:794 (6)
    //         004b60fb     DEC        dword ptr [EBP + 0x558]
    //                               LAB_004b6101                                                 XREF[2]:     004b60c9(j), 004b60d8(j)  
    //                              scr_set.cpp:797 (45)
    //         004b6101     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6107     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b610c     TEST       EAX,EAX
    //         004b610e     JNZ        LAB_004b612e
    //         004b6110     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6116     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
    //         004b611b     TEST       EAX,EAX
    //         004b611d     JZ         LAB_004b6155
    //         004b611f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6125     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
    //         004b612a     TEST       AL,AL
    //         004b612c     JZ         LAB_004b6155
    //                               LAB_004b612e                                                 XREF[1]:     004b610e(j)  
    //                              scr_set.cpp:799 (33)
    //         004b612e     PUSH       -0x1
    //         004b6130     PUSH       s_2_-_8                                          = "2 - 8"
    //                              language.dll match for 0x2617: "Death Match"
    //         004b6135     PUSH       0x2617
    //         004b613a     MOV        this,EBP
    //         004b613c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
    //         004b6141     MOV        this,dword ptr [EBP + 0x4f0]
    //         004b6147     PUSH       EAX
    //         004b6148     PUSH       0x1
    //         004b614a     CALL       TTextPanel::insert_line                          int insert_line(TTextPanel * this, long param
    //                              scr_set.cpp:800 (6)
    //         004b614f     DEC        dword ptr [EBP + 0x558]
    //                               LAB_004b6155                                                 XREF[2]:     004b611d(j), 004b612c(j)  
    //                              scr_set.cpp:802 (11)
    //         004b6155     POP        EDI
    //         004b6156     POP        ESI
    //         004b6157     POP        EBP
    //         004b6158     POP        EBX
    //         004b6159     ADD        ESP,0x224
    //         004b615f     RET
}

// Offset: 0x004B6160
void fillMissionText(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::fillMissionText(void)                             *
    //                              *********************************************************************************************************
    //                              void __thiscall fillMissionText(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //                               ?fillMissionText@TribeGameSettingsScreen@@IAEXXZ             XREF[3]:     TribeGameSettingsScreen:004b57c3(c
    //                               TribeGameSettingsScreen::fillMissionText                                  handle_idle:004b5bc4(c), 
    //                                                                                                         action:004b5dcd(c)  
    //                              scr_set.cpp:808 (6)
    //         004b6160     PUSH       EBX
    //         004b6161     PUSH       EBP
    //         004b6162     PUSH       ESI
    //         004b6163     MOV        ESI,this
    //         004b6165     PUSH       EDI
    //                              scr_set.cpp:812 (19)
    //         004b6166     PUSH       s_                                               = ""
    //         004b616b     MOV        this,dword ptr [ESI + 0x51c]
    //         004b6171     MOV        EAX,dword ptr [this->_padding_]
    //         004b6173     CALL       dword ptr [EAX + 0xe8]
    //                              scr_set.cpp:814 (11)
    //         004b6179     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b617f     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //                              scr_set.cpp:815 (15)
    //         004b6184     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b618a     MOV        EDI,EAX
    //         004b618c     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         004b6191     MOV        EBX,EAX
    //                              scr_set.cpp:817 (5)
    //         004b6193     CMP        EBX,-0x2
    //         004b6196     JNZ        LAB_004b61ad
    //                              scr_set.cpp:818 (19)
    //         004b6198     MOV        this,dword ptr [ESI + 0x51c]
    //                              language.dll match for 0x25dc: "This is a game played on a ra
    //         004b619e     PUSH       0x25dc
    //         004b61a3     MOV        EDX,dword ptr [this->_padding_]
    //         004b61a5     CALL       dword ptr [EDX + 0xe4]
    //                              scr_set.cpp:819 (2)
    //         004b61ab     JMP        LAB_004b61e2
    //                               LAB_004b61ad                                                 XREF[1]:     004b6196(j)  
    //                              scr_set.cpp:820 (24)
    //         004b61ad     MOV        this,dword ptr [ESI + 0x51c]
    //         004b61b3     CMP        EBX,-0x1
    //         004b61b6     JNZ        LAB_004b61c7
    //         004b61b8     MOV        EAX,dword ptr [this->_padding_]
    //                              language.dll match for 0x2618: "A game played on a random map
    //         004b61ba     PUSH       0x2618
    //         004b61bf     CALL       dword ptr [EAX + 0xe4]
    //                              scr_set.cpp:821 (2)
    //         004b61c5     JMP        LAB_004b61e2
    //                               LAB_004b61c7                                                 XREF[1]:     004b61b6(j)  
    //                              scr_set.cpp:822 (27)
    //         004b61c7     MOV        EAX,dword ptr [ESI + 0x558]
    //         004b61cd     MOV        EBP,dword ptr [ESI + 0x4fc]
    //         004b61d3     MOV        EDX,dword ptr [this->_padding_]
    //         004b61d5     ADD        EAX,EDI
    //         004b61d7     MOV        EAX,dword ptr [EBP + EAX*0x4]
    //         004b61db     PUSH       EAX
    //         004b61dc     CALL       dword ptr [EDX + 0xe8]
    //                               LAB_004b61e2                                                 XREF[2]:     004b61ab(j), 004b61c5(j)  
    //                              scr_set.cpp:825 (8)
    //         004b61e2     CMP        EDI,dword ptr [ESI + 0x554]
    //         004b61e8     JZ         LAB_004b61f7
    //                              scr_set.cpp:826 (13)
    //         004b61ea     MOV        this,dword ptr [ESI + 0x494]
    //         004b61f0     PUSH       0x0
    //         004b61f2     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                               LAB_004b61f7                                                 XREF[1]:     004b61e8(j)  
    //                              scr_set.cpp:829 (4)
    //         004b61f7     TEST       EBX,EBX
    //         004b61f9     JGE        LAB_004b6210
    //                              scr_set.cpp:830 (10)
    //         004b61fb     MOV        dword ptr [ESI + 0x47c],0x1
    //                              scr_set.cpp:834 (6)
    //         004b6205     MOV        dword ptr [ESI + 0x554],EDI
    //                              scr_set.cpp:835 (5)
    //         004b620b     POP        EDI
    //         004b620c     POP        ESI
    //         004b620d     POP        EBP
    //         004b620e     POP        EBX
    //         004b620f     RET
    //                               LAB_004b6210                                                 XREF[1]:     004b61f9(j)  
    //                              scr_set.cpp:834 (16)
    //         004b6210     MOV        dword ptr [ESI + 0x554],EDI
    //         004b6216     MOV        dword ptr [ESI + 0x47c],0x0
    //                              scr_set.cpp:835 (5)
    //         004b6220     POP        EDI
    //         004b6221     POP        ESI
    //         004b6222     POP        EBP
    //         004b6223     POP        EBX
    //         004b6224     RET
}

// Offset: 0x004B6230
void getSettings(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::getSettings(void)                                 *
    //                              *********************************************************************************************************
    //                              void __thiscall getSettings(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //                               ?getSettings@TribeGameSettingsScreen@@IAEXXZ                 XREF[2]:     TribeGameSettingsScreen:004b57bc(c
    //                               TribeGameSettingsScreen::getSettings                                      action:004b5d2e(c)  
    //                              scr_set.cpp:841 (3)
    //         004b6230     PUSH       ESI
    //         004b6231     MOV        ESI,this
    //                              scr_set.cpp:844 (16)
    //         004b6233     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6239     PUSH       EDI
    //         004b623a     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         004b623f     TEST       EAX,EAX
    //         004b6241     JZ         LAB_004b624f
    //                              scr_set.cpp:845 (10)
    //         004b6243     MOV        dword ptr [ESI + 0x47c],0x0
    //                              scr_set.cpp:846 (2)
    //         004b624d     JMP        LAB_004b6259
    //                               LAB_004b624f                                                 XREF[1]:     004b6241(j)  
    //                              scr_set.cpp:847 (10)
    //         004b624f     MOV        dword ptr [ESI + 0x47c],0x1
    //                               LAB_004b6259                                                 XREF[1]:     004b624d(j)  
    //                              scr_set.cpp:851 (16)
    //         004b6259     MOV        EAX,dword ptr [ESI + 0x47c]
    //         004b625f     MOV        dword ptr [ESI + 0x554],0x0
    //                              scr_set.cpp:853 (18)
    //         004b6269     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b626f     CMP        EAX,0x1
    //         004b6272     JNZ        LAB_004b6283
    //         004b6274     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
    //         004b6279     TEST       AL,AL
    //                              scr_set.cpp:854 (6)
    //         004b627b     PUSH       0x1
    //         004b627d     JZ         LAB_004b62b4
    //         004b627f     PUSH       0x1
    //                              scr_set.cpp:855 (2)
    //         004b6281     JMP        LAB_004b62b6
    //                               LAB_004b6283                                                 XREF[1]:     004b6272(j)  
    //                              scr_set.cpp:860 (19)
    //         004b6283     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
    //         004b6288     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b628e     PUSH       EAX
    //         004b628f     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
    //         004b6294     MOV        EDI,EAX
    //                              scr_set.cpp:863 (21)
    //         004b6296     PUSH       0x1
    //         004b6298     CMP        EDI,-0x1
    //         004b629b     JZ         LAB_004b62b4
    //         004b629d     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b62a3     PUSH       EDI
    //         004b62a4     PUSH       0x1
    //         004b62a6     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                              scr_set.cpp:864 (7)
    //         004b62ab     DEC        EDI
    //         004b62ac     MOV        dword ptr [ESI + 0x554],EDI
    //                              scr_set.cpp:866 (2)
    //         004b62b2     JMP        LAB_004b62c3
    //                               LAB_004b62b4                                                 XREF[2]:     004b627d(j), 004b629b(j)  
    //                              scr_set.cpp:867 (15)
    //         004b62b4     PUSH       0x0
    //                               LAB_004b62b6                                                 XREF[1]:     004b6281(j)  
    //         004b62b6     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b62bc     PUSH       0x1
    //         004b62be     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                               LAB_004b62c3                                                 XREF[1]:     004b62b2(j)  
    //                              scr_set.cpp:870 (35)
    //         004b62c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b62c9     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
    //         004b62ce     MOV        this,dword ptr [ESI + 0x484]
    //         004b62d4     PUSH       EAX
    //         004b62d5     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b62da     MOV        this,dword ptr [ESI + 0x484]
    //         004b62e0     PUSH       EAX
    //         004b62e1     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:871 (35)
    //         004b62e6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b62ec     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
    //         004b62f1     MOV        this,dword ptr [ESI + 0x48c]
    //         004b62f7     PUSH       EAX
    //         004b62f8     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b62fd     MOV        this,dword ptr [ESI + 0x48c]
    //         004b6303     PUSH       EAX
    //         004b6304     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:872 (35)
    //         004b6309     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b630f     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
    //         004b6314     MOV        this,dword ptr [ESI + 0x494]
    //         004b631a     PUSH       EAX
    //         004b631b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b6320     MOV        this,dword ptr [ESI + 0x494]
    //         004b6326     PUSH       EAX
    //         004b6327     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:874 (10)
    //         004b632c     MOV        EAX,dword ptr [ESI + 0x530]
    //         004b6332     TEST       EAX,EAX
    //         004b6334     JZ         LAB_004b6350
    //                              scr_set.cpp:875 (26)
    //         004b6336     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b633c     MOV        EDI,dword ptr [EAX]
    //         004b633e     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
    //         004b6343     MOV        this,dword ptr [ESI + 0x530]
    //         004b6349     PUSH       EAX
    //         004b634a     CALL       dword ptr [EDI + 0xe0]
    //                               LAB_004b6350                                                 XREF[1]:     004b6334(j)  
    //                              scr_set.cpp:877 (32)
    //         004b6350     MOV        EAX,dword ptr [ESI + 0x528]
    //         004b6356     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b635c     MOV        EDI,dword ptr [EAX]
    //         004b635e     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
    //         004b6363     MOV        this,dword ptr [ESI + 0x528]
    //         004b6369     PUSH       EAX
    //         004b636a     CALL       dword ptr [EDI + 0xe0]
    //                              scr_set.cpp:878 (37)
    //         004b6370     MOV        this,dword ptr [ESI + 0x524]
    //         004b6376     MOV        EDI,dword ptr [this->_padding_]
    //         004b6378     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b637e     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
    //         004b6383     MOV        this,dword ptr [ESI + 0x524]
    //         004b6389     NEG        EAX
    //         004b638b     SBB        EAX,EAX
    //         004b638d     INC        EAX
    //         004b638e     PUSH       EAX
    //         004b638f     CALL       dword ptr [EDI + 0xe0]
    //                              scr_set.cpp:879 (32)
    //         004b6395     MOV        EDX,dword ptr [ESI + 0x52c]
    //         004b639b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b63a1     MOV        EDI,dword ptr [EDX]
    //         004b63a3     CALL       TRIBE_Game::fullTechTree                         int fullTechTree(TRIBE_Game * this)
    //         004b63a8     MOV        this,dword ptr [ESI + 0x52c]
    //         004b63ae     PUSH       EAX
    //         004b63af     CALL       dword ptr [EDI + 0xe0]
    //                              scr_set.cpp:881 (35)
    //         004b63b5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b63bb     CALL       TRIBE_Game::resourceLevel                        ResourceLevel resourceLevel(TRIBE_Game * this)
    //         004b63c0     MOV        this,dword ptr [ESI + 0x4c4]
    //         004b63c6     PUSH       EAX
    //         004b63c7     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b63cc     MOV        this,dword ptr [ESI + 0x4c4]
    //         004b63d2     PUSH       EAX
    //         004b63d3     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:882 (35)
    //         004b63d8     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b63de     CALL       TRIBE_Game::startingAge                          Age startingAge(TRIBE_Game * this)
    //         004b63e3     MOV        this,dword ptr [ESI + 0x4bc]
    //         004b63e9     PUSH       EAX
    //         004b63ea     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b63ef     MOV        this,dword ptr [ESI + 0x4bc]
    //         004b63f5     PUSH       EAX
    //         004b63f6     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:883 (35)
    //         004b63fb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6401     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
    //         004b6406     MOV        this,dword ptr [ESI + 0x4b4]
    //         004b640c     PUSH       EAX
    //         004b640d     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b6412     MOV        this,dword ptr [ESI + 0x4b4]
    //         004b6418     PUSH       EAX
    //         004b6419     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:885 (11)
    //         004b641e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6424     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //                              scr_set.cpp:886 (15)
    //         004b6429     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b642f     TEST       EAX,EAX
    //         004b6431     JZ         LAB_004b643a
    //         004b6433     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
    //                              scr_set.cpp:887 (2)
    //         004b6438     JMP        LAB_004b643f
    //                               LAB_004b643a                                                 XREF[1]:     004b6431(j)  
    //                              scr_set.cpp:888 (34)
    //         004b643a     CALL       RGE_Base_Game::pathFinding                       uchar pathFinding(RGE_Base_Game * this)
    //                               LAB_004b643f                                                 XREF[1]:     004b6438(j)  
    //         004b643f     MOV        this,dword ptr [ESI + 0x4cc]
    //         004b6445     AND        EAX,0xff
    //         004b644a     PUSH       EAX
    //         004b644b     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b6450     MOV        this,dword ptr [ESI + 0x4cc]
    //         004b6456     PUSH       EAX
    //         004b6457     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:890 (15)
    //         004b645c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6462     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b6467     TEST       EAX,EAX
    //         004b6469     JZ         LAB_004b6493
    //                              scr_set.cpp:891 (40)
    //         004b646b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6471     CALL       TRIBE_Game::popLimit                             uchar popLimit(TRIBE_Game * this)
    //         004b6476     MOV        this,dword ptr [ESI + 0x4d4]
    //         004b647c     AND        EAX,0xff
    //         004b6481     PUSH       EAX
    //         004b6482     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b6487     MOV        this,dword ptr [ESI + 0x4d4]
    //         004b648d     PUSH       EAX
    //         004b648e     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                               LAB_004b6493                                                 XREF[1]:     004b6469(j)  
    //                              scr_set.cpp:893 (11)
    //         004b6493     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6499     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
    //                              scr_set.cpp:894 (35)
    //         004b649e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b64a4     CMP        EAX,0x7
    //         004b64a7     JNZ        LAB_004b64c9
    //         004b64a9     CALL       TRIBE_Game::victoryAmount                        int victoryAmount(TRIBE_Game * this)
    //         004b64ae     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b64b4     PUSH       EAX
    //         004b64b5     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b64ba     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b64c0     PUSH       EAX
    //                              scr_set.cpp:896 (5)
    //         004b64c1     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_set.cpp:897 (3)
    //         004b64c6     POP        EDI
    //         004b64c7     POP        ESI
    //         004b64c8     RET
    //                               LAB_004b64c9                                                 XREF[1]:     004b64a7(j)  
    //                              scr_set.cpp:895 (10)
    //         004b64c9     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
    //         004b64ce     CMP        EAX,0x8
    //         004b64d1     JNZ        LAB_004b64f6
    //                              scr_set.cpp:896 (35)
    //         004b64d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b64d9     CALL       TRIBE_Game::victoryAmount                        int victoryAmount(TRIBE_Game * this)
    //         004b64de     MOV        this,dword ptr [ESI + 0x4a4]
    //         004b64e4     PUSH       EAX
    //         004b64e5     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         004b64ea     MOV        this,dword ptr [ESI + 0x4a4]
    //         004b64f0     PUSH       EAX
    //         004b64f1     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                               LAB_004b64f6                                                 XREF[1]:     004b64d1(j)  
    //                              scr_set.cpp:897 (3)
    //         004b64f6     POP        EDI
    //         004b64f7     POP        ESI
    //         004b64f8     RET
}

// Offset: 0x004B6500
void sendSettings(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::sendSettings(void)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall sendSettings(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //                               ?sendSettings@TribeGameSettingsScreen@@IAEXXZ                XREF[1]:     action:004b5cee(c)  
    //                               TribeGameSettingsScreen::sendSettings
    //                              scr_set.cpp:903 (3)
    //         004b6500     PUSH       ESI
    //         004b6501     MOV        ESI,this
    //                              scr_set.cpp:906 (15)
    //         004b6503     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b6509     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         004b650e     TEST       EAX,EAX
    //         004b6510     JL         LAB_004b652d
    //                              scr_set.cpp:908 (13)
    //         004b6512     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6518     PUSH       0x1
    //         004b651a     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              scr_set.cpp:909 (12)
    //         004b651f     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b6525     CALL       TTextPanel::get_text                             char * get_text(TTextPanel * this)
    //         004b652a     PUSH       EAX
    //                              scr_set.cpp:911 (2)
    //         004b652b     JMP        LAB_004b653f
    //                               LAB_004b652d                                                 XREF[1]:     004b6510(j)  
    //                              scr_set.cpp:913 (13)
    //         004b652d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6533     PUSH       0x0
    //         004b6535     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              scr_set.cpp:914 (16)
    //         004b653a     PUSH       s_                                               = ""
    //                               LAB_004b653f                                                 XREF[1]:     004b652b(j)  
    //         004b653f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6545     CALL       RGE_Base_Game::setScenarioName                   void setScenarioName(RGE_Base_Game * this, ch
    //                              scr_set.cpp:917 (31)
    //         004b654a     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b6550     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         004b6555     XOR        this,this
    //         004b6557     CMP        EAX,-0x1
    //         004b655a     SETZ       this
    //         004b655d     PUSH       this
    //         004b655e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6564     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
    //                              scr_set.cpp:919 (19)
    //         004b6569     MOV        this,dword ptr [ESI + 0x494]
    //         004b656f     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6574     SUB        EAX,0x7
    //         004b6577     JZ         LAB_004b659c
    //         004b6579     DEC        EAX
    //         004b657a     JZ         LAB_004b658c
    //                              scr_set.cpp:930 (14)
    //         004b657c     MOV        this,dword ptr [ESI + 0x494]
    //         004b6582     PUSH       0x1
    //         004b6584     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6589     PUSH       EAX
    //                              scr_set.cpp:931 (2)
    //         004b658a     JMP        LAB_004b65aa
    //                               LAB_004b658c                                                 XREF[1]:     004b657a(j)  
    //                              scr_set.cpp:926 (14)
    //         004b658c     MOV        this,dword ptr [ESI + 0x4a4]
    //         004b6592     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6597     PUSH       EAX
    //         004b6598     PUSH       0x8
    //                              scr_set.cpp:927 (2)
    //         004b659a     JMP        LAB_004b65aa
    //                               LAB_004b659c                                                 XREF[1]:     004b6577(j)  
    //                              scr_set.cpp:922 (25)
    //         004b659c     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b65a2     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b65a7     PUSH       EAX
    //         004b65a8     PUSH       0x7
    //                               LAB_004b65aa                                                 XREF[2]:     004b658a(j), 004b659a(j)  
    //         004b65aa     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b65b0     CALL       TRIBE_Game::setVictoryType                       void setVictoryType(TRIBE_Game * this, Victor
    //                              scr_set.cpp:934 (15)
    //         004b65b5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b65bb     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
    //         004b65c0     TEST       EAX,EAX
    //         004b65c2     JZ         LAB_004b65f2
    //                              scr_set.cpp:936 (23)
    //         004b65c4     MOV        this,dword ptr [ESI + 0x484]
    //         004b65ca     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b65cf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b65d5     PUSH       EAX
    //         004b65d6     CALL       TRIBE_Game::setMapSize                           void setMapSize(TRIBE_Game * this, MapSize pa
    //                              scr_set.cpp:937 (23)
    //         004b65db     MOV        this,dword ptr [ESI + 0x48c]
    //         004b65e1     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b65e6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b65ec     PUSH       EAX
    //         004b65ed     CALL       TRIBE_Game::setMapType                           void setMapType(TRIBE_Game * this, MapType pa
    //                               LAB_004b65f2                                                 XREF[1]:     004b65c2(j)  
    //                              scr_set.cpp:940 (10)
    //         004b65f2     MOV        this,dword ptr [ESI + 0x530]
    //         004b65f8     TEST       this,this
    //         004b65fa     JZ         LAB_004b660d
    //                              scr_set.cpp:941 (17)
    //         004b65fc     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         004b6601     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6607     PUSH       EAX
    //         004b6608     CALL       RGE_Base_Game::setAllowCheatCodes                void setAllowCheatCodes(RGE_Base_Game * this,
    //                               LAB_004b660d                                                 XREF[1]:     004b65fa(j)  
    //                              scr_set.cpp:943 (23)
    //         004b660d     MOV        this,dword ptr [ESI + 0x528]
    //         004b6613     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         004b6618     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b661e     PUSH       EAX
    //         004b661f     CALL       RGE_Base_Game::setFullVisibility                 void setFullVisibility(RGE_Base_Game * this, 
    //                              scr_set.cpp:944 (28)
    //         004b6624     MOV        this,dword ptr [ESI + 0x524]
    //         004b662a     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         004b662f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6635     NEG        EAX
    //         004b6637     SBB        EAX,EAX
    //         004b6639     INC        EAX
    //         004b663a     PUSH       EAX
    //         004b663b     CALL       TRIBE_Game::setRandomizePositions                void setRandomizePositions(TRIBE_Game * this,
    //                              scr_set.cpp:945 (23)
    //         004b6640     MOV        this,dword ptr [ESI + 0x52c]
    //         004b6646     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
    //         004b664b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6651     PUSH       EAX
    //         004b6652     CALL       TRIBE_Game::setFullTechTree                      void setFullTechTree(TRIBE_Game * this, int p
    //                              scr_set.cpp:947 (16)
    //         004b6657     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b665d     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         004b6662     CMP        EAX,-0x1
    //         004b6665     JNZ        LAB_004b666b
    //                              scr_set.cpp:948 (2)
    //         004b6667     PUSH       0x0
    //                              scr_set.cpp:949 (2)
    //         004b6669     JMP        LAB_004b6677
    //                               LAB_004b666b                                                 XREF[1]:     004b6665(j)  
    //                              scr_set.cpp:950 (23)
    //         004b666b     MOV        this,dword ptr [ESI + 0x4c4]
    //         004b6671     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6676     PUSH       EAX
    //                               LAB_004b6677                                                 XREF[1]:     004b6669(j)  
    //         004b6677     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b667d     CALL       TRIBE_Game::setResourceLevel                     void setResourceLevel(TRIBE_Game * this, Reso
    //                              scr_set.cpp:952 (11)
    //         004b6682     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6688     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //                              scr_set.cpp:953 (27)
    //         004b668d     MOV        this,dword ptr [ESI + 0x4cc]
    //         004b6693     TEST       EAX,EAX
    //         004b6695     JZ         LAB_004b66aa
    //         004b6697     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b669c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b66a2     PUSH       EAX
    //         004b66a3     CALL       RGE_Base_Game::setMpPathFinding                  void setMpPathFinding(RGE_Base_Game * this, u
    //                              scr_set.cpp:954 (2)
    //         004b66a8     JMP        LAB_004b66bb
    //                               LAB_004b66aa                                                 XREF[1]:     004b6695(j)  
    //                              scr_set.cpp:955 (17)
    //         004b66aa     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b66af     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b66b5     PUSH       EAX
    //         004b66b6     CALL       RGE_Base_Game::setPathFinding                    void setPathFinding(RGE_Base_Game * this, uch
    //                               LAB_004b66bb                                                 XREF[1]:     004b66a8(j)  
    //                              scr_set.cpp:957 (15)
    //         004b66bb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b66c1     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b66c6     TEST       EAX,EAX
    //         004b66c8     JZ         LAB_004b66e1
    //                              scr_set.cpp:958 (23)
    //         004b66ca     MOV        this,dword ptr [ESI + 0x4d4]
    //         004b66d0     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b66d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b66db     PUSH       EAX
    //         004b66dc     CALL       TRIBE_Game::setPopLimit                          void setPopLimit(TRIBE_Game * this, uchar par
    //                               LAB_004b66e1                                                 XREF[1]:     004b66c8(j)  
    //                              scr_set.cpp:960 (23)
    //         004b66e1     MOV        this,dword ptr [ESI + 0x4bc]
    //         004b66e7     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b66ec     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b66f2     PUSH       EAX
    //         004b66f3     CALL       TRIBE_Game::setStartingAge                       void setStartingAge(TRIBE_Game * this, Age pa
    //                              scr_set.cpp:961 (23)
    //         004b66f8     MOV        this,dword ptr [ESI + 0x4b4]
    //         004b66fe     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6703     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6709     PUSH       EAX
    //         004b670a     CALL       RGE_Base_Game::setDifficulty                     void setDifficulty(RGE_Base_Game * this, int 
    //                              scr_set.cpp:962 (15)
    //         004b670f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6715     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         004b671a     TEST       EAX,EAX
    //         004b671c     JZ         LAB_004b6735
    //                              scr_set.cpp:963 (23)
    //         004b671e     MOV        this,dword ptr [ESI + 0x4b4]
    //         004b6724     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6729     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b672f     PUSH       EAX
    //         004b6730     CALL       RGE_Base_Game::set_single_player_difficulty      void set_single_player_difficulty(RGE_Base_Ga
    //                               LAB_004b6735                                                 XREF[1]:     004b671c(j)  
    //                              scr_set.cpp:964 (2)
    //         004b6735     POP        ESI
    //         004b6736     RET
}

// Offset: 0x004B6740
void activatePanels(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::activatePanels(void)                              *
    //                              *********************************************************************************************************
    //                              void __thiscall activatePanels(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //              TPanel *[3]       Stack[-0x10]   tabList
    //                               ?activatePanels@TribeGameSettingsScreen@@IAEXXZ              XREF[4]:     TribeGameSettingsScreen:004b57ca(c
    //                               TribeGameSettingsScreen::activatePanels                                   handle_idle:004b5bd5(c), 
    //                                                                                                         action:004b5da2(c), 
    //                                                                                                         action:004b5dd4(c)  
    //                              scr_set.cpp:970 (3)
    //         004b6740     SUB        ESP,0xc
    //                              scr_set.cpp:974 (14)
    //         004b6743     XOR        EAX,EAX
    //         004b6745     PUSH       ESI
    //         004b6746     MOV        ESI,this
    //         004b6748     PUSH       EDI
    //         004b6749     MOV        this,dword ptr [ESI + 0x47c]
    //         004b674f     TEST       this,this
    //                              scr_set.cpp:978 (22)
    //         004b6751     MOV        this,dword ptr [ESI + 0x508]
    //         004b6757     SETZ       AL
    //         004b675a     MOV        EDX,dword ptr [this->_padding_]
    //         004b675c     MOV        EDI,EAX
    //         004b675e     TEST       EDI,EDI
    //         004b6760     JZ         LAB_004b6773
    //         004b6762     PUSH       0x1
    //         004b6764     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:979 (10)
    //         004b6767     MOV        this,dword ptr [ESI + 0x51c]
    //         004b676d     PUSH       0x1
    //         004b676f     MOV        EAX,dword ptr [this->_padding_]
    //                              scr_set.cpp:981 (2)
    //         004b6771     JMP        LAB_004b6782
    //                               LAB_004b6773                                                 XREF[1]:     004b6760(j)  
    //                              scr_set.cpp:983 (5)
    //         004b6773     PUSH       0x0
    //         004b6775     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:984 (13)
    //         004b6778     MOV        this,dword ptr [ESI + 0x51c]
    //         004b677e     PUSH       0x0
    //         004b6780     MOV        EAX,dword ptr [this->_padding_]
    //                               LAB_004b6782                                                 XREF[1]:     004b6771(j)  
    //         004b6782     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:987 (15)
    //         004b6785     MOV        this,dword ptr [ESI + 0x484]
    //         004b678b     XOR        EDX,EDX
    //         004b678d     TEST       EDI,EDI
    //         004b678f     MOV        EAX,dword ptr [this->_padding_]
    //         004b6791     SETZ       DL
    //                              scr_set.cpp:1020 (83)
    //         004b6794     MOV        EDI,EDX
    //         004b6796     PUSH       EDI
    //         004b6797     CALL       dword ptr [EAX + 0x14]
    //         004b679a     MOV        this,dword ptr [ESI + 0x48c]
    //         004b67a0     PUSH       EDI
    //         004b67a1     MOV        EDX,dword ptr [this->_padding_]
    //         004b67a3     CALL       dword ptr [EDX + 0x14]
    //         004b67a6     MOV        this,dword ptr [ESI + 0x480]
    //         004b67ac     PUSH       EDI
    //         004b67ad     MOV        EAX,dword ptr [this->_padding_]
    //         004b67af     CALL       dword ptr [EAX + 0x14]
    //         004b67b2     MOV        this,dword ptr [ESI + 0x488]
    //         004b67b8     PUSH       EDI
    //         004b67b9     MOV        EDX,dword ptr [this->_padding_]
    //         004b67bb     CALL       dword ptr [EDX + 0x14]
    //         004b67be     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b67c4     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         004b67c9     MOV        this,dword ptr [ESI + 0x4c4]
    //         004b67cf     CMP        EAX,-0x1
    //         004b67d2     MOV        EAX,dword ptr [this->_padding_]
    //         004b67d4     JNZ        LAB_004b67e7
    //         004b67d6     PUSH       0x0
    //         004b67d8     CALL       dword ptr [EAX + 0x14]
    //         004b67db     MOV        this,dword ptr [ESI + 0x4c0]
    //         004b67e1     PUSH       0x0
    //         004b67e3     MOV        EDX,dword ptr [this->_padding_]
    //         004b67e5     JMP        LAB_004b67f6
    //                               LAB_004b67e7                                                 XREF[1]:     004b67d4(j)  
    //                              scr_set.cpp:1000 (5)
    //         004b67e7     PUSH       0x1
    //         004b67e9     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:1001 (13)
    //         004b67ec     MOV        this,dword ptr [ESI + 0x4c0]
    //         004b67f2     PUSH       0x1
    //         004b67f4     MOV        EDX,dword ptr [this->_padding_]
    //                               LAB_004b67f6                                                 XREF[1]:     004b67e5(j)  
    //         004b67f6     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1005 (7)
    //         004b67f9     MOV        this,ESI
    //         004b67fb     CALL       TribeGameSettingsScreen::activateVictoryPanels   void activateVictoryPanels(TribeGameSettingsS
    //                              scr_set.cpp:1010 (17)
    //         004b6800     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004b6806     XOR        EDI,EDI
    //         004b6808     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
    //         004b680d     TEST       EAX,EAX
    //         004b680f     JZ         LAB_004b6820
    //                              scr_set.cpp:1011 (15)
    //         004b6811     MOV        EAX,dword ptr [ESI + 0x4f0]
    //         004b6817     MOV        EDI,0x1
    //         004b681c     MOV        dword ptr [ESP + 0x8],EAX
    //                               LAB_004b6820                                                 XREF[1]:     004b680f(j)  
    //                              scr_set.cpp:1012 (6)
    //         004b6820     MOV        this,dword ptr [ESI + 0x544]
    //                              scr_set.cpp:1013 (10)
    //         004b6826     MOV        EDX,dword ptr [ESI + 0x548]
    //         004b682c     MOV        dword ptr [ESP + EDI*0x4 + 0x8],this
    //                              scr_set.cpp:1014 (22)
    //         004b6830     MOV        EAX,dword ptr [ESI]
    //         004b6832     INC        EDI
    //         004b6833     LEA        this,[ESP + 0x8]
    //         004b6837     MOV        dword ptr [ESP + EDI*0x4 + 0x8],EDX
    //         004b683b     INC        EDI
    //         004b683c     PUSH       EDI
    //         004b683d     PUSH       this=>DAT_fffffff8
    //         004b683e     MOV        this,ESI
    //         004b6840     CALL       dword ptr [EAX + 0xc8]
    //                              scr_set.cpp:1018 (14)
    //         004b6846     MOV        EAX,dword ptr [ESI + 0x3c]
    //         004b6849     TEST       EAX,EAX
    //         004b684b     JZ         LAB_004b6854
    //         004b684d     MOV        this,dword ptr [EAX + 0x6c]
    //         004b6850     TEST       this,this
    //         004b6852     JNZ        LAB_004b6862
    //                               LAB_004b6854                                                 XREF[1]:     004b684b(j)  
    //                              scr_set.cpp:1019 (14)
    //         004b6854     MOV        EDX,dword ptr [ESI + 0x544]
    //         004b685a     MOV        this,ESI
    //         004b685c     PUSH       EDX
    //         004b685d     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                               LAB_004b6862                                                 XREF[1]:     004b6852(j)  
    //                              scr_set.cpp:1020 (6)
    //         004b6862     POP        EDI
    //         004b6863     POP        ESI
    //         004b6864     ADD        ESP,0xc
    //         004b6867     RET
}

// Offset: 0x004B6870
void activateVictoryPanels(TribeGameSettingsScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeGameSettingsScreen::activateVictoryPanels(void)                       *
    //                              *********************************************************************************************************
    //                              void __thiscall activateVictoryPanels(TribeGameSettingsScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeGameSetti    ECX:4 (auto)   this
    //                               ?activateVictoryPanels@TribeGameSettingsScreen@@IAEXXZ       XREF[1]:     activatePanels:004b67fb(c)  
    //                               TribeGameSettingsScreen::activateVictoryPanels
    //                              scr_set.cpp:1026 (4)
    //         004b6870     PUSH       ESI
    //         004b6871     MOV        ESI,this
    //         004b6873     PUSH       EDI
    //                              scr_set.cpp:1030 (13)
    //         004b6874     PUSH       0x0
    //         004b6876     MOV        this,dword ptr [ESI + 0x4a8]
    //         004b687c     MOV        EAX,dword ptr [this->_padding_]
    //         004b687e     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:1031 (13)
    //         004b6881     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b6887     PUSH       0x0
    //         004b6889     MOV        EDX,dword ptr [this->_padding_]
    //         004b688b     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1032 (13)
    //         004b688e     MOV        this,dword ptr [ESI + 0x4a0]
    //         004b6894     PUSH       0x0
    //         004b6896     MOV        EAX,dword ptr [this->_padding_]
    //         004b6898     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:1033 (13)
    //         004b689b     MOV        this,dword ptr [ESI + 0x4a4]
    //         004b68a1     PUSH       0x0
    //         004b68a3     MOV        EDX,dword ptr [this->_padding_]
    //         004b68a5     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1036 (10)
    //         004b68a8     MOV        EAX,dword ptr [ESI + 0x47c]
    //         004b68ae     TEST       EAX,EAX
    //         004b68b0     JNZ        LAB_004b6916
    //                              scr_set.cpp:1038 (11)
    //         004b68b2     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b68b8     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //                              scr_set.cpp:1039 (13)
    //         004b68bd     MOV        this,dword ptr [ESI + 0x4f0]
    //         004b68c3     MOV        EDI,EAX
    //         004b68c5     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //                              scr_set.cpp:1040 (34)
    //         004b68ca     MOV        this,dword ptr [ESI + 0x504]
    //         004b68d0     TEST       this,this
    //         004b68d2     JZ         LAB_004b6916
    //         004b68d4     TEST       EAX,EAX
    //         004b68d6     JL         LAB_004b6916
    //         004b68d8     MOV        EAX,dword ptr [ESI + 0x558]
    //         004b68de     MOV        this,dword ptr [ESI + 0x500]
    //         004b68e4     ADD        EAX,EDI
    //         004b68e6     CMP        dword ptr [this->_padding_ + EAX*0x4],0x0
    //         004b68ea     JZ         LAB_004b6916
    //                              scr_set.cpp:1042 (13)
    //         004b68ec     MOV        this,dword ptr [ESI + 0x498]
    //         004b68f2     PUSH       0x1
    //         004b68f4     MOV        EDX,dword ptr [this->_padding_]
    //         004b68f6     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1043 (13)
    //         004b68f9     MOV        this,dword ptr [ESI + 0x490]
    //         004b68ff     PUSH       0x0
    //         004b6901     MOV        EAX,dword ptr [this->_padding_]
    //         004b6903     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:1044 (13)
    //         004b6906     MOV        this,dword ptr [ESI + 0x494]
    //         004b690c     PUSH       0x0
    //         004b690e     MOV        EDX,dword ptr [this->_padding_]
    //         004b6910     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1064 (3)
    //         004b6913     POP        EDI
    //         004b6914     POP        ESI
    //         004b6915     RET
    //                               LAB_004b6916                                                 XREF[4]:     004b68b0(j), 004b68d2(j), 
    //                                                                                                         004b68d6(j), 004b68ea(j)  
    //                              scr_set.cpp:1049 (13)
    //         004b6916     MOV        this,dword ptr [ESI + 0x498]
    //         004b691c     PUSH       0x0
    //         004b691e     MOV        EAX,dword ptr [this->_padding_]
    //         004b6920     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:1050 (13)
    //         004b6923     MOV        this,dword ptr [ESI + 0x490]
    //         004b6929     PUSH       0x1
    //         004b692b     MOV        EDX,dword ptr [this->_padding_]
    //         004b692d     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1051 (13)
    //         004b6930     MOV        this,dword ptr [ESI + 0x494]
    //         004b6936     PUSH       0x1
    //         004b6938     MOV        EAX,dword ptr [this->_padding_]
    //         004b693a     CALL       dword ptr [EAX + 0x14]
    //                              scr_set.cpp:1053 (16)
    //         004b693d     MOV        this,dword ptr [ESI + 0x494]
    //         004b6943     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6948     CMP        EAX,0x7
    //         004b694b     JNZ        LAB_004b6967
    //                              scr_set.cpp:1055 (13)
    //         004b694d     MOV        this,dword ptr [ESI + 0x4a8]
    //         004b6953     PUSH       0x1
    //         004b6955     MOV        EDX,dword ptr [this->_padding_]
    //         004b6957     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1056 (13)
    //         004b695a     MOV        this,dword ptr [ESI + 0x4ac]
    //         004b6960     PUSH       0x1
    //         004b6962     MOV        EAX,dword ptr [this->_padding_]
    //         004b6964     CALL       dword ptr [EAX + 0x14]
    //                               LAB_004b6967                                                 XREF[1]:     004b694b(j)  
    //                              scr_set.cpp:1059 (16)
    //         004b6967     MOV        this,dword ptr [ESI + 0x494]
    //         004b696d     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004b6972     CMP        EAX,0x8
    //         004b6975     JNZ        LAB_004b6991
    //                              scr_set.cpp:1061 (13)
    //         004b6977     MOV        this,dword ptr [ESI + 0x4a0]
    //         004b697d     PUSH       0x1
    //         004b697f     MOV        EDX,dword ptr [this->_padding_]
    //         004b6981     CALL       dword ptr [EDX + 0x14]
    //                              scr_set.cpp:1062 (13)
    //         004b6984     MOV        this,dword ptr [ESI + 0x4a4]
    //         004b698a     PUSH       0x1
    //         004b698c     MOV        EAX,dword ptr [this->_padding_]
    //         004b698e     CALL       dword ptr [EAX + 0x14]
    //                               LAB_004b6991                                                 XREF[1]:     004b6975(j)  
    //                              scr_set.cpp:1064 (3)
    //         004b6991     POP        EDI
    //         004b6992     POP        ESI
    //         004b6993     RET
}

