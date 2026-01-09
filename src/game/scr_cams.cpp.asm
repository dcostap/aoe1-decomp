#include "common.h"
#include "scr_cams.h"

TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection() {
    /* TODO: Stub */
    //                              undefined __thiscall TRIBE_Screen_Campaign_Selection(TRIBE_Screen_Ca
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004909fe(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     00490a3d(R), 00490dfa(R)  
    //              TPanel *[5]       Stack[-0x24]   tabList                   XREF[1]:     004909f3(W)  
    //                               ??0TRIBE_Screen_Campaign_Selection@@QAE@XZ                   XREF[3]:     action:004a6a5d(c), 
    //                               TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Sele               action:004a70ad(c), 
    //                                                                                                         start_campaign_menu:00523f57(c)  
    //                              scr_cams.cpp:48 (44)
    //         004909d0     PUSH       -0x1
    //         004909d2     PUSH       FUN_0055e948
    //         004909d7     MOV        EAX,FS:[0x0]
    //         004909dd     PUSH       EAX
    //         004909de     MOV        dword ptr FS:[0x0],ESP
    //         004909e5     SUB        ESP,0x18
    //         004909e8     PUSH       EBX
    //         004909e9     PUSH       EBP
    //         004909ea     PUSH       ESI
    //         004909eb     PUSH       EDI
    //         004909ec     MOV        ESI,this
    //         004909ee     PUSH       s_Campaign_Selection_Screen                      = "Campaign Selection Screen"
    //         004909f3     MOV        dword ptr [ESP + tabList[0]],ESI
    //         004909f7     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_cams.cpp:49 (21)
    //         004909fc     MOV        this,ESI
    //         004909fe     MOV        dword ptr [ESP + local_4],0x0
    //         00490a06     MOV        dword ptr [ESI],TRIBE_Screen_Campaign_Selectio   = 00490e10
    //         00490a0c     CALL       TRIBE_Screen_Campaign_Selection::init_vars       void init_vars(TRIBE_Screen_Campaign_Selectio
    //                              scr_cams.cpp:52 (32)
    //         00490a11     MOV        EAX,[rge_base_game]                              = 00000000
    //         00490a16     PUSH       0x1
    //         00490a18     PUSH       0xc384
    //         00490a1d     PUSH       s_scr2                                           = 73h
    //         00490a22     MOV        this,dword ptr [EAX + 0x4c]
    //         00490a25     PUSH       this
    //         00490a26     MOV        this,ESI
    //         00490a28     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         00490a2d     TEST       EAX,EAX
    //         00490a2f     JNZ        LAB_00490a50
    //                              scr_cams.cpp:54 (10)
    //         00490a31     MOV        dword ptr [ESI + 0xd8],0x1
    //                              scr_cams.cpp:125 (21)
    //         00490a3b     MOV        EAX,ESI
    //         00490a3d     MOV        this,dword ptr [ESP + local_c]
    //         00490a41     MOV        dword ptr FS:[0x0],this
    //         00490a48     POP        EDI
    //         00490a49     POP        ESI
    //         00490a4a     POP        EBP
    //         00490a4b     POP        EBX
    //         00490a4c     ADD        ESP,0x24
    //         00490a4f     RET
    //                               LAB_00490a50                                                 XREF[1]:     00490a2f(j)  
    //                              scr_cams.cpp:58 (9)
    //         00490a50     PUSH       0x0
    //         00490a52     MOV        this,ESI
    //         00490a54     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_cams.cpp:59 (17)
    //         00490a59     PUSH       0x1e0
    //         00490a5e     PUSH       0x280
    //         00490a63     MOV        this,ESI
    //         00490a65     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_cams.cpp:62 (52)
    //         00490a6a     PUSH       0x0
    //         00490a6c     PUSH       0x0
    //         00490a6e     PUSH       0x1
    //         00490a70     PUSH       0x1
    //         00490a72     MOV        EBP,0x258
    //         00490a77     PUSH       0x1e
    //         00490a79     PUSH       EBP
    //         00490a7a     MOV        EBX,0x14
    //         00490a7f     PUSH       0xa
    //         00490a81     PUSH       EBX
    //         00490a82     LEA        EDX,[ESI + 0x478]
    //                              language.dll match for 0x2bcd: "Campaign"
    //         00490a88     PUSH       0x2bcd
    //         00490a8d     PUSH       EDX
    //         00490a8e     PUSH       ESI
    //         00490a8f     MOV        this,ESI
    //         00490a91     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00490a96     TEST       EAX,EAX
    //         00490a98     JZ         LAB_00490dfa
    //                              scr_cams.cpp:70 (66)
    //         00490a9e     PUSH       0xb
    //         00490aa0     PUSH       0x82
    //         00490aa5     PUSH       EBP
    //         00490aa6     LEA        EDI,[ESI + 0x490]
    //         00490aac     PUSH       0x46
    //         00490aae     PUSH       EBX
    //         00490aaf     PUSH       EDI
    //         00490ab0     PUSH       ESI
    //         00490ab1     MOV        this,ESI
    //         00490ab3     MOV        dword ptr [ESI + 0x47c],EBX
    //         00490ab9     MOV        dword ptr [ESI + 0x480],0x46
    //         00490ac3     MOV        dword ptr [ESI + 0x484],EBP
    //                              language.dll match for 0x82: "B"
    //         00490ac9     MOV        dword ptr [ESI + 0x488],0x82
    //         00490ad3     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         00490ad8     TEST       EAX,EAX
    //         00490ada     JZ         LAB_00490dfa
    //                              scr_cams.cpp:71 (26)
    //         00490ae0     MOV        EAX,dword ptr [EDI]
    //         00490ae2     PUSH       EBX
    //         00490ae3     LEA        this,[ESI + 0x494]
    //         00490ae9     PUSH       EAX
    //         00490aea     PUSH       this
    //         00490aeb     MOV        this,ESI
    //         00490aed     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         00490af2     TEST       EAX,EAX
    //         00490af4     JZ         LAB_00490dfa
    //                              scr_cams.cpp:72 (61)
    //         00490afa     MOV        EDX,dword ptr [ESI + 0x480]
    //         00490b00     MOV        EAX,dword ptr [ESI + 0x47c]
    //         00490b06     PUSH       0x0
    //         00490b08     PUSH       0x0
    //         00490b0a     PUSH       0x0
    //         00490b0c     PUSH       0x4
    //         00490b0e     PUSH       EBX
    //         00490b0f     SUB        EDX,EBX
    //         00490b11     PUSH       0xc8
    //         00490b16     SUB        EAX,0x5
    //         00490b19     PUSH       EDX
    //         00490b1a     PUSH       EAX
    //         00490b1b     LEA        this,[ESI + 0x48c]
    //                              language.dll match for 0x2bce: "Select Campaign"
    //         00490b21     PUSH       0x2bce
    //         00490b26     PUSH       this
    //         00490b27     PUSH       ESI
    //         00490b28     MOV        this,ESI
    //         00490b2a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00490b2f     TEST       EAX,EAX
    //         00490b31     JZ         LAB_00490dfa
    //                              scr_cams.cpp:74 (15)
    //         00490b37     MOV        this,dword ptr [EDI]
    //                              language.dll match for 0x2b5d: "Loading list of campaigns..."
    //         00490b39     PUSH       0x2b5d
    //         00490b3e     MOV        EDX,dword ptr [this->_padding_]
    //         00490b40     CALL       dword ptr [EDX + 0xe4]
    //                              scr_cams.cpp:78 (12)
    //         00490b46     MOV        EAX,dword ptr [ESI + 0x488]
    //         00490b4c     MOV        this,dword ptr [ESI + 0x480]
    //                              scr_cams.cpp:82 (65)
    //         00490b52     PUSH       0xb
    //         00490b54     PUSH       offset DAT_fffffff8
    //         00490b59     LEA        EAX,[EAX + this->_padding_*0x1 + 0x1e]
    //         00490b5d     PUSH       EBP=>DAT_fffffff4
    //         00490b5e     LEA        EDI,[ESI + 0x4ac]
    //         00490b64     PUSH       EAX=>DAT_fffffff0
    //         00490b65     PUSH       EBX
    //         00490b66     PUSH       EDI
    //         00490b67     PUSH       ESI
    //         00490b68     MOV        this,ESI
    //         00490b6a     MOV        dword ptr [ESI + 0x498],EBX
    //         00490b70     MOV        dword ptr [ESI + 0x49c],EAX
    //         00490b76     MOV        dword ptr [ESI + 0x4a0],EBP
    //                              language.dll match for 0x82: "B"
    //         00490b7c     MOV        dword ptr [ESI + 0x4a4],0x82
    //         00490b86     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         00490b8b     TEST       EAX,EAX
    //         00490b8d     JZ         LAB_00490dfa
    //                              scr_cams.cpp:83 (26)
    //         00490b93     MOV        EDX,dword ptr [EDI]
    //         00490b95     PUSH       EBX
    //         00490b96     LEA        EAX,[ESI + 0x4b0]
    //         00490b9c     PUSH       EDX=>DAT_fffffff8
    //         00490b9d     PUSH       EAX=>DAT_fffffff4
    //         00490b9e     MOV        this,ESI
    //         00490ba0     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         00490ba5     TEST       EAX,EAX
    //         00490ba7     JZ         LAB_00490dfa
    //                              scr_cams.cpp:84 (61)
    //         00490bad     MOV        this,dword ptr [ESI + 0x49c]
    //         00490bb3     MOV        EDX,dword ptr [ESI + 0x498]
    //         00490bb9     PUSH       0x0
    //         00490bbb     PUSH       0x0=>DAT_fffffff8
    //         00490bbd     PUSH       0x0=>DAT_fffffff4
    //         00490bbf     PUSH       offset DAT_fffffff0
    //         00490bc1     PUSH       EBX
    //         00490bc2     SUB        this,EBX
    //         00490bc4     PUSH       0xc8
    //         00490bc9     SUB        EDX,0x5
    //         00490bcc     PUSH       this
    //         00490bcd     PUSH       EDX
    //         00490bce     LEA        EAX,[ESI + 0x4a8]
    //                              language.dll match for 0x25fe: "Select Scenario"
    //         00490bd4     PUSH       0x25fe
    //         00490bd9     PUSH       EAX
    //         00490bda     PUSH       ESI
    //         00490bdb     MOV        this,ESI
    //         00490bdd     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00490be2     TEST       EAX,EAX
    //         00490be4     JZ         LAB_00490dfa
    //                              scr_cams.cpp:86 (2)
    //         00490bea     MOV        this,dword ptr [EDI]
    //                              scr_cams.cpp:89 (59)
    //         00490bec     PUSH       0x0
    //         00490bee     PUSH       0x0=>DAT_fffffff8
    //         00490bf0     PUSH       0x0=>DAT_fffffff4
    //         00490bf2     PUSH       offset DAT_fffffff0
    //         00490bf4     PUSH       EBX
    //         00490bf5     PUSH       0xc8
    //         00490bfa     PUSH       0x172
    //         00490bff     PUSH       0xf
    //         00490c01     LEA        EDX,[ESI + 0x4b4]
    //                              language.dll match for 0x2bcf: "Difficulty Level"
    //         00490c07     PUSH       0x2bcf
    //         00490c0c     MOV        dword ptr [ECX + this->_padding_],0x0
    //         00490c16     PUSH       EDX
    //         00490c17     PUSH       ESI
    //         00490c18     MOV        this,ESI
    //         00490c1a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         00490c1f     TEST       EAX,EAX
    //         00490c21     JZ         LAB_00490dfa
    //                              scr_cams.cpp:90 (45)
    //         00490c27     PUSH       0xb
    //         00490c29     PUSH       offset DAT_fffffff8
    //         00490c2b     PUSH       offset DAT_fffffff4
    //         00490c30     PUSH       offset DAT_fffffff0
    //         00490c35     PUSH       EBX
    //         00490c36     LEA        EDI,[ESI + 0x4b8]
    //         00490c3c     PUSH       0x64
    //                              language.dll match for 0x82: "B"
    //         00490c3e     PUSH       0x82
    //         00490c43     PUSH       EDI
    //         00490c44     PUSH       ESI
    //         00490c45     MOV        this,ESI
    //         00490c47     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
    //         00490c4c     TEST       EAX,EAX
    //         00490c4e     JZ         LAB_00490dfa
    //                              scr_cams.cpp:91 (7)
    //         00490c54     MOV        this,dword ptr [EDI]
    //         00490c56     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
    //                              scr_cams.cpp:92 (14)
    //         00490c5b     MOV        this,dword ptr [EDI]
    //         00490c5d     PUSH       0x4
    //                              language.dll match for 0x2bd4: "Easiest"
    //         00490c5f     PUSH       offset DAT_fffffff8
    //         00490c64     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_cams.cpp:93 (14)
    //         00490c69     MOV        this,dword ptr [EDI]
    //         00490c6b     PUSH       0x3
    //                              language.dll match for 0x2bd3: "Easy"
    //         00490c6d     PUSH       offset DAT_fffffff8
    //         00490c72     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_cams.cpp:94 (14)
    //         00490c77     MOV        this,dword ptr [EDI]
    //         00490c79     PUSH       0x2
    //                              language.dll match for 0x2bd2: "Moderate"
    //         00490c7b     PUSH       offset DAT_fffffff8
    //         00490c80     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_cams.cpp:95 (14)
    //         00490c85     MOV        this,dword ptr [EDI]
    //         00490c87     PUSH       0x1
    //                              language.dll match for 0x2bd1: "Hard"
    //         00490c89     PUSH       offset DAT_fffffff8
    //         00490c8e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_cams.cpp:96 (14)
    //         00490c93     MOV        this,dword ptr [EDI]
    //         00490c95     PUSH       0x0
    //                              language.dll match for 0x2bd0: "Hardest"
    //         00490c97     PUSH       offset DAT_fffffff8
    //         00490c9c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
    //                              scr_cams.cpp:97 (27)
    //         00490ca1     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00490ca7     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
    //         00490cac     MOV        this,dword ptr [EDI]
    //         00490cae     PUSH       EAX
    //         00490caf     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
    //         00490cb4     MOV        this,dword ptr [EDI]
    //         00490cb6     PUSH       EAX
    //         00490cb7     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
    //                              scr_cams.cpp:100 (50)
    //         00490cbc     PUSH       0x0
    //         00490cbe     PUSH       0x0=>DAT_fffffff8
    //         00490cc0     PUSH       0x0=>DAT_fffffff4
    //         00490cc2     PUSH       offset DAT_fffffff0
    //         00490cc4     PUSH       0xf0
    //         00490cc9     PUSH       0x1b8
    //         00490cce     PUSH       0x46
    //         00490cd0     LEA        EBX,[ESI + 0x4bc]
    //         00490cd6     PUSH       0x0
    //                              language.dll match for 0xfa1: "OK"
    //         00490cd8     PUSH       0xfa1
    //         00490cdd     PUSH       EBX
    //         00490cde     PUSH       ESI
    //         00490cdf     MOV        this,ESI
    //         00490ce1     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00490ce6     TEST       EAX,EAX
    //         00490ce8     JZ         LAB_00490dfa
    //                              scr_cams.cpp:101 (53)
    //         00490cee     PUSH       0x0
    //         00490cf0     PUSH       0x0=>DAT_fffffff8
    //         00490cf2     PUSH       0x0=>DAT_fffffff4
    //         00490cf4     PUSH       offset DAT_fffffff0
    //         00490cf6     PUSH       0xf0
    //         00490cfb     PUSH       0x1b8
    //         00490d00     PUSH       0x14a
    //         00490d05     LEA        EBP,[ESI + 0x4c0]
    //         00490d0b     PUSH       0x0
    //                              language.dll match for 0xfa2: "Cancel"
    //         00490d0d     PUSH       0xfa2
    //         00490d12     PUSH       EBP
    //         00490d13     PUSH       ESI
    //         00490d14     MOV        this,ESI
    //         00490d16     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00490d1b     TEST       EAX,EAX
    //         00490d1d     JZ         LAB_00490dfa
    //                              scr_cams.cpp:102 (3)
    //         00490d23     MOV        EBP,dword ptr [EBP]
    //                              scr_cams.cpp:105 (64)
    //         00490d26     PUSH       0x0
    //         00490d28     PUSH       offset DAT_fffffff8
    //         00490d2a     PUSH       offset DAT_fffffff4
    //         00490d2c     PUSH       0x0=>DAT_fffffff0
    //         00490d2e     PUSH       0x0
    //         00490d30     PUSH       0x0
    //         00490d32     MOV        dword ptr [EBP + 0x298],0x1b
    //         00490d3c     MOV        dword ptr [EBP + 0x29c],0x0
    //         00490d46     PUSH       0x0
    //         00490d48     LEA        EBP,[ESI + 0x4c4]
    //         00490d4e     PUSH       0x0
    //                              language.dll match for 0x3ea: "X"
    //         00490d50     PUSH       0x3ea
    //         00490d55     PUSH       EBP
    //         00490d56     PUSH       ESI
    //         00490d57     MOV        this,ESI
    //         00490d59     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         00490d5e     TEST       EAX,EAX
    //         00490d60     JZ         LAB_00490dfa
    //                              scr_cams.cpp:106 (10)
    //         00490d66     MOV        this,dword ptr [EBP]
    //         00490d69     PUSH       0x1
    //         00490d6b     MOV        EAX,dword ptr [this->_padding_]
    //         00490d6d     CALL       dword ptr [EAX + 0x14]
    //                              scr_cams.cpp:107 (34)
    //         00490d70     MOV        this,dword ptr [EBP]
    //         00490d73     PUSH       0x0
    //         00490d75     PUSH       0x0=>DAT_fffffff8
    //         00490d77     PUSH       0x0=>DAT_fffffff4
    //         00490d79     MOV        EDX,dword ptr [this->_padding_]
    //         00490d7b     PUSH       0x0=>DAT_fffffff0
    //         00490d7d     PUSH       0x11
    //         00490d7f     PUSH       0x11
    //         00490d81     PUSH       0x11
    //         00490d83     PUSH       0x11
    //         00490d85     PUSH       0x4
    //         00490d87     PUSH       0x4
    //         00490d89     PUSH       0x4
    //         00490d8b     PUSH       0x4
    //         00490d8d     PUSH       0x9
    //         00490d8f     CALL       dword ptr [EDX + 0x18]
    //                              scr_cams.cpp:112 (6)
    //         00490d92     MOV        this,dword ptr [ESI + 0x4ac]
    //                              scr_cams.cpp:113 (12)
    //         00490d98     MOV        EDX,dword ptr [EDI]
    //         00490d9a     MOV        EAX,dword ptr [ESI + 0x490]
    //         00490da0     MOV        dword ptr [ESP + 0x18],this
    //                              scr_cams.cpp:115 (16)
    //         00490da4     MOV        this,dword ptr [ESI + 0x4c0]
    //         00490daa     MOV        dword ptr [ESP + 0x1c],EDX
    //         00490dae     MOV        dword ptr [ESP + 0x14],EAX
    //         00490db2     MOV        EAX,dword ptr [EBX]
    //                              scr_cams.cpp:116 (22)
    //         00490db4     LEA        EDX,[ESP + 0x14]
    //         00490db8     MOV        dword ptr [ESP + 0x24],this
    //         00490dbc     PUSH       0x5
    //         00490dbe     PUSH       EDX=>DAT_fffffff8
    //         00490dbf     MOV        this,ESI
    //         00490dc1     MOV        dword ptr [ESP + 0x28],EAX
    //         00490dc5     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                              scr_cams.cpp:119 (10)
    //         00490dca     MOV        EAX,dword ptr [EBX]
    //         00490dcc     MOV        this,ESI
    //         00490dce     PUSH       EAX
    //         00490dcf     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_cams.cpp:121 (7)
    //         00490dd4     MOV        this,ESI
    //         00490dd6     CALL       TRIBE_Screen_Campaign_Selection::fillCampaigns   void fillCampaigns(TRIBE_Screen_Campaign_Sele
    //                              scr_cams.cpp:122 (7)
    //         00490ddb     MOV        this,ESI
    //         00490ddd     CALL       TRIBE_Screen_Campaign_Selection::fillScenarios   void fillScenarios(TRIBE_Screen_Campaign_Sele
    //                              scr_cams.cpp:123 (14)
    //         00490de2     MOV        this,dword ptr [ESI + 0x490]
    //         00490de8     PUSH       this
    //         00490de9     MOV        this,ESI
    //         00490deb     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_cams.cpp:124 (10)
    //         00490df0     MOV        dword ptr [ESI + 0x4c8],0x1
    //                               LAB_00490dfa                                                 XREF[12]:    00490a98(j), 00490ada(j), 
    //                                                                                                         00490af4(j), 00490b31(j), 
    //                                                                                                         00490b8d(j), 00490ba7(j), 
    //                                                                                                         00490be4(j), 00490c21(j), 
    //                                                                                                         00490c4e(j), 00490ce8(j), 
    //                                                                                                         00490d1d(j), 00490d60(j)  
    //                              scr_cams.cpp:125 (21)
    //         00490dfa     MOV        this,dword ptr [ESP + local_c]
    //         00490dfe     MOV        EAX,ESI
    //         00490e00     POP        EDI
    //         00490e01     POP        ESI
    //         00490e02     POP        EBP
    //         00490e03     MOV        dword ptr FS:[0x0],this
    //         00490e0a     POP        EBX
    //         00490e0b     ADD        ESP,0x24
    //         00490e0e     RET
    //         00490e0f     ??         90h
    //                              * public: virtual void * __thiscall TRIBE_Screen_Campaign_Selection::`vector deleting destructor'(un... *
    //                              void * __thiscall `vector_deleting_destructor'(TRIBE_Screen_Campaign
    //              void *            EAX:4          <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              uint              Stack[0x4]:4   param_1                   XREF[1]:     00490e18(R)  
    //                               ??_GTRIBE_Screen_Campaign_Selection@@UAEPAXI@Z               XREF[1]:     005723d0(*)  
    //                               ??_ETRIBE_Screen_Campaign_Selection@@UAEPAXI@Z
    //                               TRIBE_Screen_Campaign_Selection::`vector_deleting_destructor'
    //         00490e10     PUSH       ESI
    //         00490e11     MOV        ESI,this
    //         00490e13     CALL       TRIBE_Screen_Campaign_Selection::~TRIBE_Screen   void ~TRIBE_Screen_Campaign_Selection(TRIBE_S
    //         00490e18     TEST       byte ptr [ESP + param_1],0x1
    //         00490e1d     JZ         LAB_00490e28
    //         00490e1f     PUSH       ESI
    //         00490e20     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         00490e25     ADD        ESP,0x4
    //                               LAB_00490e28                                                 XREF[1]:     00490e1d(j)  
    //         00490e28     MOV        EAX,ESI
    //         00490e2a     POP        ESI
    //         00490e2b     RET        0x4
    //         00490e2e     ??         90h
    //         00490e2f     NOP
}

void TRIBE_Screen_Campaign_Selection::init_vars() {
    /* TODO: Stub */
    //                              void __thiscall init_vars(TRIBE_Screen_Campaign_Selection * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //                               ?init_vars@TRIBE_Screen_Campaign_Selection@@IAEXXZ           XREF[1]:     TRIBE_Screen_Campaign_Selection:00
    //                               TRIBE_Screen_Campaign_Selection::init_vars
    //                              scr_cams.cpp:131 (8)
    //         00490e30     XOR        EAX,EAX
    //         00490e32     MOV        dword ptr [ECX + this->title],EAX
    //                              scr_cams.cpp:134 (6)
    //         00490e38     MOV        dword ptr [ECX + this->campaignTitle],EAX
    //                              scr_cams.cpp:135 (6)
    //         00490e3e     MOV        dword ptr [ECX + this->campaignList],EAX
    //                              scr_cams.cpp:136 (6)
    //         00490e44     MOV        dword ptr [ECX + this->campaignScrollbar],EAX
    //                              scr_cams.cpp:138 (6)
    //         00490e4a     MOV        dword ptr [ECX + this->scenarioTitle],EAX
    //                              scr_cams.cpp:139 (6)
    //         00490e50     MOV        dword ptr [ECX + this->scenarioList],EAX
    //                              scr_cams.cpp:140 (6)
    //         00490e56     MOV        dword ptr [ECX + this->scenarioScrollbar],EAX
    //                              scr_cams.cpp:142 (6)
    //         00490e5c     MOV        dword ptr [ECX + this->difficultyTitle],EAX
    //                              scr_cams.cpp:143 (6)
    //         00490e62     MOV        dword ptr [ECX + this->difficultyDrop],EAX
    //                              scr_cams.cpp:145 (6)
    //         00490e68     MOV        dword ptr [ECX + this->okButton],EAX
    //                              scr_cams.cpp:146 (6)
    //         00490e6e     MOV        dword ptr [ECX + this->cancelButton],EAX
    //                              scr_cams.cpp:147 (6)
    //         00490e74     MOV        dword ptr [ECX + this->close_button],EAX
    //                              scr_cams.cpp:149 (6)
    //         00490e7a     MOV        dword ptr [ECX + this->campaignsLoaded],EAX
    //                              scr_cams.cpp:151 (23)
    //         00490e80     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00490e86     CALL       RGE_Base_Game::get_single_player_difficulty      int get_single_player_difficulty(RGE_Base_Gam
    //         00490e8b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00490e91     PUSH       EAX
    //         00490e92     CALL       RGE_Base_Game::setDifficulty                     void setDifficulty(RGE_Base_Game * this, int 
    //                              scr_cams.cpp:152 (1)
    //         00490e97     RET
    //         00490e98     ??         90h
    //         00490e99     NOP
    //         00490e9a     NOP
    //         00490e9b     NOP
    //         00490e9c     NOP
    //         00490e9d     NOP
    //         00490e9e     NOP
    //         00490e9f     NOP
    return;
}

TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Selection() {
    /* TODO: Stub */
    //                              void __thiscall ~TRIBE_Screen_Campaign_Selection(TRIBE_Screen_Campai
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00490ec9(W), 00490f73(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     00490f80(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     00490eb9(W)  
    //                               ??1TRIBE_Screen_Campaign_Selection@@UAE@XZ                   XREF[1]:     `vector_deleting_destructor':00490
    //                               TRIBE_Screen_Campaign_Selection::~TRIBE_Screen_Campaign_Sel
    //                              scr_cams.cpp:158 (35)
    //         00490ea0     PUSH       -0x1
    //         00490ea2     PUSH       FUN_0055e968
    //         00490ea7     MOV        EAX,FS:[0x0]
    //         00490ead     PUSH       EAX
    //         00490eae     MOV        dword ptr FS:[0x0],ESP
    //         00490eb5     PUSH       this
    //         00490eb6     PUSH       ESI
    //         00490eb7     MOV        ESI,this
    //         00490eb9     MOV        dword ptr [ESP + local_10],ESI
    //         00490ebd     MOV        dword ptr [ESI],TRIBE_Screen_Campaign_Selectio   = 00490e10
    //                              scr_cams.cpp:159 (20)
    //         00490ec3     LEA        EAX,[ESI + 0x478]
    //         00490ec9     MOV        dword ptr [ESP + local_4],0x0
    //         00490ed1     PUSH       EAX
    //         00490ed2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:160 (14)
    //         00490ed7     LEA        this,[ESI + 0x48c]
    //         00490edd     PUSH       this
    //         00490ede     MOV        this,ESI
    //         00490ee0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:161 (14)
    //         00490ee5     LEA        EDX,[ESI + 0x490]
    //         00490eeb     MOV        this,ESI
    //         00490eed     PUSH       EDX
    //         00490eee     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:162 (14)
    //         00490ef3     LEA        EAX,[ESI + 0x494]
    //         00490ef9     MOV        this,ESI
    //         00490efb     PUSH       EAX
    //         00490efc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:163 (14)
    //         00490f01     LEA        this,[ESI + 0x4a8]
    //         00490f07     PUSH       this
    //         00490f08     MOV        this,ESI
    //         00490f0a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:164 (14)
    //         00490f0f     LEA        EDX,[ESI + 0x4ac]
    //         00490f15     MOV        this,ESI
    //         00490f17     PUSH       EDX
    //         00490f18     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:165 (14)
    //         00490f1d     LEA        EAX,[ESI + 0x4b0]
    //         00490f23     MOV        this,ESI
    //         00490f25     PUSH       EAX
    //         00490f26     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:166 (14)
    //         00490f2b     LEA        this,[ESI + 0x4b4]
    //         00490f31     PUSH       this
    //         00490f32     MOV        this,ESI
    //         00490f34     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:167 (14)
    //         00490f39     LEA        EDX,[ESI + 0x4b8]
    //         00490f3f     MOV        this,ESI
    //         00490f41     PUSH       EDX
    //         00490f42     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:168 (14)
    //         00490f47     LEA        EAX,[ESI + 0x4bc]
    //         00490f4d     MOV        this,ESI
    //         00490f4f     PUSH       EAX
    //         00490f50     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:169 (14)
    //         00490f55     LEA        this,[ESI + 0x4c0]
    //         00490f5b     PUSH       this
    //         00490f5c     MOV        this,ESI
    //         00490f5e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_cams.cpp:170 (16)
    //         00490f63     LEA        EDX,[ESI + 0x4c4]
    //         00490f69     MOV        this,ESI
    //         00490f6b     PUSH       EDX
    //         00490f6c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         00490f71     MOV        this,ESI
    //                              scr_cams.cpp:171 (29)
    //         00490f73     MOV        dword ptr [ESP + local_4],0xffffffff
    //         00490f7b     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         00490f80     MOV        this,dword ptr [ESP + local_c]
    //         00490f84     POP        ESI
    //         00490f85     MOV        dword ptr FS:[0x0],this
    //         00490f8c     ADD        ESP,0x10
    //         00490f8f     RET
}

long TRIBE_Screen_Campaign_Selection::handle_idle() {
    /* TODO: Stub */
    //                              long __thiscall handle_idle(TRIBE_Screen_Campaign_Selection * this)
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //                               ?handle_idle@TRIBE_Screen_Campaign_Selection@@UAEJXZ         XREF[1]:     0057241c(*)  
    //                               TRIBE_Screen_Campaign_Selection::handle_idle
    //                              scr_cams.cpp:177 (3)
    //         00490f90     PUSH       ESI
    //         00490f91     MOV        ESI,this
    //                              scr_cams.cpp:178 (10)
    //         00490f93     MOV        EAX,dword ptr [ESI + 0x4c8]
    //         00490f99     TEST       EAX,EAX
    //         00490f9b     JNZ        LAB_00490fcb
    //                              scr_cams.cpp:180 (5)
    //         00490f9d     CALL       TRIBE_Screen_Campaign_Selection::fillCampaigns   void fillCampaigns(TRIBE_Screen_Campaign_Sele
    //                              scr_cams.cpp:181 (7)
    //         00490fa2     MOV        this,ESI
    //         00490fa4     CALL       TRIBE_Screen_Campaign_Selection::fillScenarios   void fillScenarios(TRIBE_Screen_Campaign_Sele
    //                              scr_cams.cpp:182 (14)
    //         00490fa9     MOV        EAX,dword ptr [ESI + 0x490]
    //         00490faf     MOV        this,ESI
    //         00490fb1     PUSH       EAX
    //         00490fb2     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_cams.cpp:183 (10)
    //         00490fb7     MOV        dword ptr [ESI + 0x4c8],0x1
    //                              scr_cams.cpp:186 (26)
    //         00490fc1     MOV        EAX,dword ptr [ESI + 0x4c8]
    //         00490fc7     TEST       EAX,EAX
    //         00490fc9     JZ         LAB_00490fe0
    //                               LAB_00490fcb                                                 XREF[1]:     00490f9b(j)  
    //         00490fcb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00490fd1     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         00490fd7     TEST       EAX,EAX
    //         00490fd9     JNZ        LAB_00490fe0
    //                              scr_cams.cpp:187 (5)
    //         00490fdb     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_00490fe0                                                 XREF[2]:     00490fc9(j), 00490fd9(j)  
    //                              scr_cams.cpp:189 (7)
    //         00490fe0     MOV        this,ESI
    //         00490fe2     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_cams.cpp:190 (2)
    //         00490fe7     POP        ESI
    //         00490fe8     RET
    //         00490fe9     ??         90h
    //         00490fea     NOP
    //         00490feb     NOP
    //         00490fec     NOP
    //         00490fed     NOP
    //         00490fee     NOP
    //         00490fef     NOP
    //                              * protected: virtual long __thiscall TRIBE_Screen_Campaign_Selection::action(class TPanel *,long,uns... *
    //                              long __thiscall action(TRIBE_Screen_Campaign_Selection * this, TPane
    //              long              EAX:4          <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[2]:     00491002(R), 0049107a(W)  
    //              long              Stack[0x8]:4   param_2                   XREF[1]:     00490ff6(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0049117f(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049117a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     00491080(W), 0049109d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[5]:     00491042(R), 004910be(R), 004910ee(R), 00491131(R), 
    //                                                                                     0049118d(R)  
    //                               ?action@TRIBE_Screen_Campaign_Selection@@MAEJPAVTPanel@@JKK@Z XREF[1]:     00572484(*)  
    //                               TRIBE_Screen_Campaign_Selection::action
    //                              scr_cams.cpp:196 (6)
    //         00490ff0     MOV        EAX,FS:[0x0]
    //                              scr_cams.cpp:197 (49)
    //         00490ff6     MOV        EDX,dword ptr [ESP + param_2]
    //         00490ffa     PUSH       -0x1
    //         00490ffc     PUSH       FUN_0055e98b
    //         00491001     PUSH       EAX
    //         00491002     MOV        EAX,dword ptr [ESP + param_1]
    //         00491006     MOV        dword ptr FS:[0x0],ESP
    //         0049100d     PUSH       ESI
    //         0049100e     TEST       EAX,EAX
    //         00491010     PUSH       EDI
    //         00491011     MOV        ESI,this
    //         00491013     JZ         LAB_0049117a
    //         00491019     MOV        this,dword ptr [ESI + 0x4c8]
    //         0049101f     TEST       this,this
    //         00491021     JZ         LAB_0049117a
    //                              scr_cams.cpp:200 (15)
    //         00491027     MOV        EDI,dword ptr [ESI + 0x4bc]
    //         0049102d     CMP        EAX,EDI
    //         0049102f     JNZ        LAB_00491055
    //         00491031     CMP        EDX,0x1
    //         00491034     JNZ        LAB_00491055
    //                              scr_cams.cpp:202 (7)
    //         00491036     MOV        this,ESI
    //         00491038     CALL       TRIBE_Screen_Campaign_Selection::startGame       void startGame(TRIBE_Screen_Campaign_Selectio
    //                              scr_cams.cpp:203 (5)
    //         0049103d     MOV        EAX,0x1
    //                              scr_cams.cpp:241 (19)
    //         00491042     MOV        this,dword ptr [ESP + local_c]
    //         00491046     MOV        dword ptr FS:[0x0],this
    //         0049104d     POP        EDI
    //         0049104e     POP        ESI
    //         0049104f     ADD        ESP,0xc
    //         00491052     RET        0x10
    //                               LAB_00491055                                                 XREF[2]:     0049102f(j), 00491034(j)  
    //                              scr_cams.cpp:207 (13)
    //         00491055     CMP        EAX,dword ptr [ESI + 0x4c0]
    //         0049105b     JNZ        LAB_004910d1
    //         0049105d     CMP        EDX,0x1
    //         00491060     JNZ        LAB_004910d1
    //                              scr_cams.cpp:209 (11)
    //         00491062     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491068     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_cams.cpp:210 (36)
    //         0049106d     PUSH       0x4a0
    //         00491072     CALL       operator_new                                     void * operator_new(uint param_1)
    //         00491077     ADD        ESP,0x4
    //         0049107a     MOV        dword ptr [ESP + param_1],EAX
    //         0049107e     TEST       EAX,EAX
    //         00491080     MOV        dword ptr [ESP + local_4],0x0
    //         00491088     JZ         LAB_00491091
    //         0049108a     MOV        this,EAX
    //         0049108c     CALL       TRIBE_Screen_Name::TRIBE_Screen_Name             undefined TRIBE_Screen_Name(TRIBE_Screen_Name
    //                               LAB_00491091                                                 XREF[1]:     00491088(j)  
    //                              scr_cams.cpp:211 (25)
    //         00491091     PUSH       0x0
    //         00491093     PUSH       s_Name_Selection_Screen                          = "Name Selection Screen"
    //         00491098     MOV        this,panel_system
    //         0049109d     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004910a5     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_cams.cpp:212 (15)
    //         004910aa     PUSH       s_Campaign_Selection_Screen                      = "Campaign Selection Screen"
    //         004910af     MOV        this,panel_system
    //         004910b4     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_cams.cpp:213 (5)
    //         004910b9     MOV        EAX,0x1
    //                              scr_cams.cpp:241 (19)
    //         004910be     MOV        this,dword ptr [ESP + local_c]
    //         004910c2     MOV        dword ptr FS:[0x0],this
    //         004910c9     POP        EDI
    //         004910ca     POP        ESI
    //         004910cb     ADD        ESP,0xc
    //         004910ce     RET        0x10
    //                               LAB_004910d1                                                 XREF[2]:     0049105b(j), 00491060(j)  
    //                              scr_cams.cpp:217 (13)
    //         004910d1     CMP        EAX,dword ptr [ESI + 0x4c4]
    //         004910d7     JNZ        LAB_00491101
    //         004910d9     CMP        EDX,0x1
    //         004910dc     JNZ        LAB_00491101
    //                              scr_cams.cpp:219 (11)
    //         004910de     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004910e4     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
    //                              scr_cams.cpp:220 (5)
    //         004910e9     MOV        EAX,0x1
    //                              scr_cams.cpp:241 (19)
    //         004910ee     MOV        this,dword ptr [ESP + local_c]
    //         004910f2     MOV        dword ptr FS:[0x0],this
    //         004910f9     POP        EDI
    //         004910fa     POP        ESI
    //         004910fb     ADD        ESP,0xc
    //         004910fe     RET        0x10
    //                               LAB_00491101                                                 XREF[2]:     004910d7(j), 004910dc(j)  
    //                              scr_cams.cpp:225 (15)
    //         00491101     MOV        this,dword ptr [ESI + 0x490]
    //         00491107     CMP        EAX,this
    //         00491109     JNZ        LAB_00491144
    //         0049110b     CMP        EDX,0x1
    //         0049110e     JNZ        LAB_00491144
    //                              scr_cams.cpp:227 (21)
    //         00491110     MOV        EAX,[rge_base_game]                              = 00000000
    //         00491115     MOV        EDI,dword ptr [EAX + 0x4]
    //         00491118     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         0049111d     PUSH       EAX
    //         0049111e     MOV        this,EDI
    //         00491120     CALL       RGE_Game_Info::set_current_campaign              uchar set_current_campaign(RGE_Game_Info * th
    //                              scr_cams.cpp:228 (7)
    //         00491125     MOV        this,ESI
    //         00491127     CALL       TRIBE_Screen_Campaign_Selection::fillScenarios   void fillScenarios(TRIBE_Screen_Campaign_Sele
    //                              scr_cams.cpp:229 (5)
    //         0049112c     MOV        EAX,0x1
    //                              scr_cams.cpp:241 (19)
    //         00491131     MOV        this,dword ptr [ESP + local_c]
    //         00491135     MOV        dword ptr FS:[0x0],this
    //         0049113c     POP        EDI
    //         0049113d     POP        ESI
    //         0049113e     ADD        ESP,0xc
    //         00491141     RET        0x10
    //                               LAB_00491144                                                 XREF[2]:     00491109(j), 0049110e(j)  
    //                              scr_cams.cpp:233 (13)
    //         00491144     CMP        EAX,dword ptr [ESI + 0x4ac]
    //         0049114a     JNZ        LAB_0049117a
    //         0049114c     CMP        EDX,0x3
    //         0049114f     JNZ        LAB_0049117a
    //                              scr_cams.cpp:235 (17)
    //         00491151     MOV        EDX,dword ptr [ESI]
    //         00491153     PUSH       0x0
    //         00491155     PUSH       0x0
    //         00491157     PUSH       0x1
    //         00491159     PUSH       EDI
    //         0049115a     MOV        this,ESI
    //         0049115c     CALL       dword ptr [EDX + 0xb4]
    //                              scr_cams.cpp:236 (5)
    //         00491162     MOV        EAX,0x1
    //                              scr_cams.cpp:241 (19)
    //         00491167     MOV        this,dword ptr [ESP + 0x8]
    //         0049116b     MOV        dword ptr FS:[0x0],this
    //         00491172     POP        EDI
    //         00491173     POP        ESI
    //         00491174     ADD        ESP,0xc
    //         00491177     RET        0x10
    //                               LAB_0049117a                                                 XREF[4]:     00491013(j), 00491021(j), 
    //                                                                                                         0049114a(j), 0049114f(j)  
    //                              scr_cams.cpp:240 (19)
    //         0049117a     MOV        this,dword ptr [ESP + param_4]
    //         0049117e     PUSH       this
    //         0049117f     MOV        this,dword ptr [ESP + param_3]
    //         00491183     PUSH       this
    //         00491184     PUSH       EDX
    //         00491185     PUSH       EAX
    //         00491186     MOV        this,ESI
    //         00491188     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                              scr_cams.cpp:241 (19)
    //         0049118d     MOV        this,dword ptr [ESP + local_c]
    //         00491191     POP        EDI
    //         00491192     MOV        dword ptr FS:[0x0],this
    //         00491199     POP        ESI
    //         0049119a     ADD        ESP,0xc
    //         0049119d     RET        0x10
    return 0;
}

void TRIBE_Screen_Campaign_Selection::fillCampaigns() {
    /* TODO: Stub */
    //                              void __thiscall fillCampaigns(TRIBE_Screen_Campaign_Selection * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004911b8(*), 0049120b(R)  
    //              long              Stack[-0x8]:4  currentCampaign           XREF[5]:     004911c0(*), 004911c5(W), 004911f2(R), 0049122d(R), 
    //                                                                                     00491242(R)  
    //              char * *          Stack[-0xc]:4  campaigns
    //                               ?fillCampaigns@TRIBE_Screen_Campaign_Selection@@IAEXXZ       XREF[2]:     TRIBE_Screen_Campaign_Selection:00
    //                               TRIBE_Screen_Campaign_Selection::fillCampaigns                            handle_idle:00490f9d(c)  
    //                              scr_cams.cpp:247 (8)
    //         004911a0     SUB        ESP,0x8
    //         004911a3     PUSH       EBX
    //         004911a4     MOV        EBX,this
    //         004911a6     PUSH       ESI
    //         004911a7     PUSH       EDI
    //                              scr_cams.cpp:254 (11)
    //         004911a8     MOV        this,dword ptr [EBX + 0x490]
    //         004911ae     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_cams.cpp:256 (5)
    //         004911b3     MOV        EAX,[rge_base_game]                              = 00000000
    //                              scr_cams.cpp:260 (28)
    //         004911b8     LEA        EDX=>local_4,[ESP + 0x10]
    //         004911bc     PUSH       EDX
    //         004911bd     MOV        this,dword ptr [EAX + 0x4]
    //         004911c0     LEA        EAX=>currentCampaign,[ESP + 0x10]
    //         004911c4     PUSH       EAX
    //         004911c5     MOV        dword ptr [ESP + currentCampaign],0x0
    //         004911cd     CALL       RGE_Game_Info::get_campaign_list                 long get_campaign_list(RGE_Game_Info * this, 
    //         004911d2     MOV        EDI,EAX
    //                              scr_cams.cpp:261 (8)
    //         004911d4     TEST       EDI,EDI
    //         004911d6     JZ         LAB_0049127b
    //                              scr_cams.cpp:265 (6)
    //         004911dc     MOV        this,dword ptr [EBX + 0x490]
    //                              scr_cams.cpp:266 (16)
    //         004911e2     XOR        ESI,ESI
    //         004911e4     TEST       EDI,EDI
    //         004911e6     MOV        dword ptr [ECX + this->_padding_],0x1
    //         004911f0     JLE        LAB_0049120b
    //                               LAB_004911f2                                                 XREF[1]:     00491209(j)  
    //                              scr_cams.cpp:267 (25)
    //         004911f2     MOV        EDX,dword ptr [ESP + currentCampaign]
    //         004911f6     MOV        this,dword ptr [EBX + 0x490]
    //         004911fc     PUSH       ESI
    //         004911fd     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         00491200     PUSH       EAX
    //         00491201     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //         00491206     INC        ESI
    //         00491207     CMP        ESI,EDI
    //         00491209     JL         LAB_004911f2
    //                               LAB_0049120b                                                 XREF[1]:     004911f0(j)  
    //                              scr_cams.cpp:268 (28)
    //         0049120b     MOV        this,dword ptr [ESP + local_4]
    //         0049120f     PUSH       this
    //         00491210     MOV        this,dword ptr [EBX + 0x490]
    //         00491216     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, long param_1)
    //         0049121b     MOV        this,dword ptr [EBX + 0x490]
    //         00491221     PUSH       EAX
    //         00491222     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
    //                              scr_cams.cpp:271 (6)
    //         00491227     XOR        ESI,ESI
    //         00491229     TEST       EDI,EDI
    //         0049122b     JLE        LAB_00491242
    //                               LAB_0049122d                                                 XREF[1]:     00491240(j)  
    //                              scr_cams.cpp:272 (21)
    //         0049122d     MOV        EDX,dword ptr [ESP + currentCampaign]
    //         00491231     MOV        EAX,dword ptr [EDX + ESI*0x4]
    //         00491234     PUSH       EAX
    //         00491235     CALL       free                                             undefined free()
    //         0049123a     ADD        ESP,0x4
    //         0049123d     INC        ESI
    //         0049123e     CMP        ESI,EDI
    //         00491240     JL         LAB_0049122d
    //                               LAB_00491242                                                 XREF[1]:     0049122b(j)  
    //                              scr_cams.cpp:273 (10)
    //         00491242     MOV        this,dword ptr [ESP + currentCampaign]
    //         00491246     PUSH       this
    //         00491247     CALL       free                                             undefined free()
    //                              scr_cams.cpp:276 (19)
    //         0049124c     MOV        this,dword ptr [EBX + 0x490]
    //         00491252     ADD        ESP,0x4
    //         00491255     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         0049125a     CMP        EAX,-0x1
    //         0049125d     JZ         LAB_0049127b
    //                              scr_cams.cpp:277 (28)
    //         0049125f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         00491265     MOV        this,dword ptr [EBX + 0x490]
    //         0049126b     MOV        ESI,dword ptr [EDX + 0x4]
    //         0049126e     CALL       TTextPanel::get_id                               long get_id(TTextPanel * this)
    //         00491273     PUSH       EAX
    //         00491274     MOV        this,ESI
    //         00491276     CALL       RGE_Game_Info::set_current_campaign              uchar set_current_campaign(RGE_Game_Info * th
    //                               LAB_0049127b                                                 XREF[2]:     004911d6(j), 0049125d(j)  
    //                              scr_cams.cpp:278 (7)
    //         0049127b     POP        EDI
    //         0049127c     POP        ESI
    //         0049127d     POP        EBX
    //         0049127e     ADD        ESP,0x8
    //         00491281     RET
    //         00491282     ??         90h
    //         00491283     NOP
    //         00491284     NOP
    //         00491285     NOP
    //         00491286     NOP
    //         00491287     NOP
    //         00491288     NOP
    //         00491289     NOP
    //         0049128a     NOP
    //         0049128b     NOP
    //         0049128c     NOP
    //         0049128d     NOP
    //         0049128e     NOP
    //         0049128f     NOP
    return;
}

void TRIBE_Screen_Campaign_Selection::fillScenarios() {
    /* TODO: Stub */
    //                              void __thiscall fillScenarios(TRIBE_Screen_Campaign_Selection * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004912a7(*), 004912e7(R)  
    //              long              Stack[-0x8]:4  currentScenario           XREF[5]:     004912af(*), 004912b4(W), 004912ce(R), 00491309(R), 
    //                                                                                     0049131e(R)  
    //              char * *          Stack[-0xc]:4  scenarios
    //                               ?fillScenarios@TRIBE_Screen_Campaign_Selection@@IAEXXZ       XREF[3]:     TRIBE_Screen_Campaign_Selection:00
    //                               TRIBE_Screen_Campaign_Selection::fillScenarios                            handle_idle:00490fa4(c), 
    //                                                                                                         action:00491127(c)  
    //                              scr_cams.cpp:284 (7)
    //         00491290     SUB        ESP,0x8
    //         00491293     PUSH       EBX
    //         00491294     MOV        EBX,this
    //         00491296     PUSH       EDI
    //                              scr_cams.cpp:291 (11)
    //         00491297     MOV        this,dword ptr [EBX + 0x4ac]
    //         0049129d     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_cams.cpp:293 (5)
    //         004912a2     MOV        EAX,[rge_base_game]                              = 00000000
    //                              scr_cams.cpp:297 (28)
    //         004912a7     LEA        EDX=>local_4,[ESP + 0xc]
    //         004912ab     PUSH       EDX
    //         004912ac     MOV        this,dword ptr [EAX + 0x4]
    //         004912af     LEA        EAX=>currentScenario,[ESP + 0xc]
    //         004912b3     PUSH       EAX
    //         004912b4     MOV        dword ptr [ESP + currentScenario],0x0
    //         004912bc     CALL       RGE_Game_Info::get_scenario_list                 long get_scenario_list(RGE_Game_Info * this, 
    //         004912c1     MOV        EDI,EAX
    //                              scr_cams.cpp:298 (5)
    //         004912c3     TEST       EDI,EDI
    //         004912c5     JZ         LAB_0049133d
    //         004912c7     PUSH       ESI
    //                              scr_cams.cpp:302 (6)
    //         004912c8     XOR        ESI,ESI
    //         004912ca     TEST       EDI,EDI
    //         004912cc     JLE        LAB_004912e7
    //                               LAB_004912ce                                                 XREF[1]:     004912e5(j)  
    //                              scr_cams.cpp:303 (25)
    //         004912ce     MOV        this,dword ptr [ESP + currentScenario]
    //         004912d2     PUSH       ESI
    //         004912d3     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         004912d6     MOV        this,dword ptr [EBX + 0x4ac]
    //         004912dc     PUSH       EDX
    //         004912dd     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //         004912e2     INC        ESI
    //         004912e3     CMP        ESI,EDI
    //         004912e5     JL         LAB_004912ce
    //                               LAB_004912e7                                                 XREF[1]:     004912cc(j)  
    //                              scr_cams.cpp:304 (28)
    //         004912e7     MOV        EAX,dword ptr [ESP + local_4]
    //         004912eb     MOV        this,dword ptr [EBX + 0x4ac]
    //         004912f1     PUSH       EAX
    //         004912f2     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, long param_1)
    //         004912f7     MOV        this,dword ptr [EBX + 0x4ac]
    //         004912fd     PUSH       EAX
    //         004912fe     CALL       TTextPanel::set_line                             void set_line(TTextPanel * this, long param_1)
    //                              scr_cams.cpp:307 (6)
    //         00491303     XOR        ESI,ESI
    //         00491305     TEST       EDI,EDI
    //         00491307     JLE        LAB_0049131e
    //                               LAB_00491309                                                 XREF[1]:     0049131c(j)  
    //                              scr_cams.cpp:308 (21)
    //         00491309     MOV        this,dword ptr [ESP + currentScenario]
    //         0049130d     MOV        EDX,dword ptr [this->_padding_ + ESI*0x4]
    //         00491310     PUSH       EDX
    //         00491311     CALL       free                                             undefined free()
    //         00491316     ADD        ESP,0x4
    //         00491319     INC        ESI
    //         0049131a     CMP        ESI,EDI
    //         0049131c     JL         LAB_00491309
    //                               LAB_0049131e                                                 XREF[1]:     00491307(j)  
    //                              scr_cams.cpp:309 (10)
    //         0049131e     MOV        EAX,dword ptr [ESP + currentScenario]
    //         00491322     PUSH       EAX
    //         00491323     CALL       free                                             undefined free()
    //                              scr_cams.cpp:311 (21)
    //         00491328     MOV        this,dword ptr [EBX + 0x4ac]
    //         0049132e     ADD        ESP,0x4
    //         00491331     PUSH       0x1
    //         00491333     PUSH       0x0
    //         00491335     PUSH       0x7
    //         00491337     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //         0049133c     POP        ESI
    //                               LAB_0049133d                                                 XREF[1]:     004912c5(j)  
    //                              scr_cams.cpp:312 (6)
    //         0049133d     POP        EDI
    //         0049133e     POP        EBX
    //         0049133f     ADD        ESP,0x8
    //         00491342     RET
    //         00491343     ??         90h
    //         00491344     NOP
    //         00491345     NOP
    //         00491346     NOP
    //         00491347     NOP
    //         00491348     NOP
    //         00491349     NOP
    //         0049134a     NOP
    //         0049134b     NOP
    //         0049134c     NOP
    //         0049134d     NOP
    //         0049134e     NOP
    //         0049134f     NOP
    return;
}

void TRIBE_Screen_Campaign_Selection::startGame() {
    /* TODO: Stub */
    //                              void __thiscall startGame(TRIBE_Screen_Campaign_Selection * this)
    //              void              <VOID>         <RETURN>
    //              TRIBE_Screen_C    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     00491359(W)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[2]:     004914a8(W), 0049152b(W)  
    //              int               Stack[-0xc]:4  first_any_color           XREF[4]:     004914b1(W), 004914d9(R), 0049151a(R), 00491535(R)  
    //              T_Scenario *      Stack[-0x10]:4 scenario_info
    //                               ?startGame@TRIBE_Screen_Campaign_Selection@@IAEXXZ           XREF[1]:     action:00491038(c)  
    //                               TRIBE_Screen_Campaign_Selection::startGame
    //                              scr_cams.cpp:318 (13)
    //         00491350     SUB        ESP,0xc
    //         00491353     PUSH       EBX
    //         00491354     PUSH       EBP
    //         00491355     PUSH       ESI
    //         00491356     PUSH       EDI
    //         00491357     MOV        EDI,this
    //         00491359     MOV        dword ptr [ESP + local_4],EDI
    //                              scr_cams.cpp:325 (20)
    //         0049135d     MOV        this,dword ptr [EDI + 0x4ac]
    //         00491363     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         00491368     CMP        EAX,-0x1
    //         0049136b     JZ         LAB_00491642
    //                              scr_cams.cpp:328 (27)
    //         00491371     MOV        EAX,[rge_base_game]                              = 00000000
    //         00491376     MOV        this,dword ptr [EDI + 0x4ac]
    //         0049137c     MOV        ESI,dword ptr [EAX + 0x4]
    //         0049137f     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         00491384     PUSH       EAX
    //         00491385     MOV        this,ESI
    //         00491387     CALL       RGE_Game_Info::set_current_scenario              uchar set_current_scenario(RGE_Game_Info * th
    //                              scr_cams.cpp:330 (13)
    //         0049138c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491392     PUSH       0x1
    //         00491394     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
    //                              scr_cams.cpp:331 (13)
    //         00491399     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049139f     PUSH       0x1
    //         004913a1     CALL       RGE_Base_Game::setCampaignGame                   void setCampaignGame(RGE_Base_Game * this, in
    //                              scr_cams.cpp:332 (14)
    //         004913a6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004913ac     XOR        ESI,ESI
    //         004913ae     PUSH       ESI
    //         004913af     CALL       RGE_Base_Game::setSavedGame                      void setSavedGame(RGE_Base_Game * this, int p
    //                              scr_cams.cpp:333 (13)
    //         004913b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004913ba     PUSH       ESI
    //         004913bb     PUSH       ESI
    //         004913bc     CALL       TRIBE_Game::setVictoryType                       void setVictoryType(TRIBE_Game * this, Victor
    //                              scr_cams.cpp:334 (23)
    //         004913c1     MOV        this,dword ptr [EDI + 0x4b8]
    //         004913c7     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004913cc     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004913d2     PUSH       EAX
    //         004913d3     CALL       RGE_Base_Game::setDifficulty                     void setDifficulty(RGE_Base_Game * this, int 
    //                              scr_cams.cpp:335 (23)
    //         004913d8     MOV        this,dword ptr [EDI + 0x4b8]
    //         004913de     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
    //         004913e3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004913e9     PUSH       EAX
    //         004913ea     CALL       RGE_Base_Game::set_single_player_difficulty      void set_single_player_difficulty(RGE_Base_Ga
    //                              scr_cams.cpp:336 (12)
    //         004913ef     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004913f5     PUSH       ESI
    //         004913f6     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
    //                              scr_cams.cpp:337 (12)
    //         004913fb     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491401     PUSH       ESI
    //         00491402     CALL       TRIBE_Game::setQuickStartGame                    void setQuickStartGame(TRIBE_Game * this, uch
    //                              scr_cams.cpp:338 (13)
    //         00491407     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049140d     PUSH       0x1
    //         0049140f     CALL       TRIBE_Game::setAnimals                           void setAnimals(TRIBE_Game * this, int param_1)
    //                              scr_cams.cpp:339 (13)
    //         00491414     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049141a     PUSH       0x1
    //         0049141c     CALL       TRIBE_Game::setPredators                         void setPredators(TRIBE_Game * this, int para
    //                              scr_cams.cpp:340 (12)
    //         00491421     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491427     PUSH       ESI
    //         00491428     CALL       RGE_Base_Game::setFullVisibility                 void setFullVisibility(RGE_Base_Game * this, 
    //                              scr_cams.cpp:341 (13)
    //         0049142d     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491433     PUSH       0x1
    //         00491435     CALL       RGE_Base_Game::setFogOfWar                       void setFogOfWar(RGE_Base_Game * this, int pa
    //                              scr_cams.cpp:342 (13)
    //         0049143a     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491440     PUSH       0x1
    //         00491442     CALL       RGE_Base_Game::setAllowCheatCodes                void setAllowCheatCodes(RGE_Base_Game * this,
    //                              scr_cams.cpp:343 (12)
    //         00491447     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049144d     PUSH       ESI
    //         0049144e     CALL       TRIBE_Game::setRandomizePositions                void setRandomizePositions(TRIBE_Game * this,
    //                              scr_cams.cpp:344 (12)
    //         00491453     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491459     PUSH       ESI
    //         0049145a     CALL       TRIBE_Game::setLongCombat                        void setLongCombat(TRIBE_Game * this, int par
    //                              scr_cams.cpp:345 (13)
    //         0049145f     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491465     PUSH       0x1
    //         00491467     CALL       TRIBE_Game::setAllowTrading                      void setAllowTrading(TRIBE_Game * this, int p
    //                              scr_cams.cpp:346 (12)
    //         0049146c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491472     PUSH       ESI
    //         00491473     CALL       TRIBE_Game::setFullTechTree                      void setFullTechTree(TRIBE_Game * this, int p
    //                              scr_cams.cpp:347 (12)
    //         00491478     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049147e     PUSH       ESI
    //         0049147f     CALL       TRIBE_Game::setResourceLevel                     void setResourceLevel(TRIBE_Game * this, Reso
    //                              scr_cams.cpp:348 (12)
    //         00491484     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049148a     PUSH       ESI
    //         0049148b     CALL       TRIBE_Game::setStartingAge                       void setStartingAge(TRIBE_Game * this, Age pa
    //                              scr_cams.cpp:349 (12)
    //         00491490     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491496     PUSH       ESI
    //         00491497     CALL       TRIBE_Game::setStartingUnits                     void setStartingUnits(TRIBE_Game * this, int 
    //                              scr_cams.cpp:355 (25)
    //         0049149c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004914a2     PUSH       0x1
    //         004914a4     PUSH       ESI
    //         004914a5     OR         EBP,0xffffffff
    //         004914a8     MOV        dword ptr [ESP + local_8],ESI
    //         004914ac     CALL       RGE_Base_Game::get_scenario_info                 RGE_Scenario * get_scenario_info(RGE_Base_Gam
    //         004914b1     MOV        dword ptr [ESP + first_any_color],EAX
    //                              scr_cams.cpp:356 (4)
    //         004914b5     CMP        EAX,ESI
    //         004914b7     JNZ        LAB_004914d5
    //                              scr_cams.cpp:358 (15)
    //         004914b9     PUSH       0x64
    //         004914bb     PUSH       0x1c2
    //         004914c0     PUSH       ESI
    //                              language.dll match for 0x9ca: "This scenario does not work wi
    //         004914c1     PUSH       0x9ca
    //         004914c6     MOV        this,EDI
    //                              scr_cams.cpp:418 (5)
    //         004914c8     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_cams.cpp:419 (8)
    //         004914cd     POP        EDI
    //         004914ce     POP        ESI
    //         004914cf     POP        EBP
    //         004914d0     POP        EBX
    //         004914d1     ADD        ESP,0xc
    //         004914d4     RET
    //                               LAB_004914d5                                                 XREF[1]:     004914b7(j)  
    //                              scr_cams.cpp:365 (8)
    //         004914d5     XOR        EDI,EDI
    //         004914d7     JMP        LAB_004914dd
    //                               LAB_004914d9                                                 XREF[1]:     00491533(j)  
    //         004914d9     MOV        EAX,dword ptr [ESP + first_any_color]
    //                               LAB_004914dd                                                 XREF[1]:     004914d7(j)  
    //                              scr_cams.cpp:367 (12)
    //         004914dd     PUSH       EDI
    //         004914de     MOV        this,EAX
    //         004914e0     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
    //         004914e5     TEST       EAX,EAX
    //         004914e7     JZ         LAB_0049152f
    //                              scr_cams.cpp:369 (13)
    //         004914e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004914ef     PUSH       EDI
    //         004914f0     PUSH       ESI
    //         004914f1     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
    //                              scr_cams.cpp:370 (16)
    //         004914f6     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004914fc     LEA        EBX,[EDI + 0x1]
    //         004914ff     PUSH       EBX
    //         00491500     PUSH       ESI
    //         00491501     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
    //                              scr_cams.cpp:371 (14)
    //         00491506     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049150c     PUSH       0x1
    //         0049150e     PUSH       ESI
    //         0049150f     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int 
    //                              scr_cams.cpp:373 (1)
    //         00491514     INC        ESI
    //                              scr_cams.cpp:376 (20)
    //         00491515     CMP        EBP,-0x1
    //         00491518     JNZ        LAB_0049152f
    //         0049151a     MOV        this,dword ptr [ESP + first_any_color]
    //         0049151e     PUSH       EDI
    //         0049151f     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int 
    //         00491524     CMP        EAX,0x1
    //         00491527     JNZ        LAB_0049152f
    //                              scr_cams.cpp:378 (2)
    //         00491529     MOV        EBP,EDI
    //                              scr_cams.cpp:379 (10)
    //         0049152b     MOV        dword ptr [ESP + local_8],EBX
    //                               LAB_0049152f                                                 XREF[3]:     004914e7(j), 00491518(j), 
    //                                                                                                         00491527(j)  
    //         0049152f     INC        EDI
    //         00491530     CMP        EDI,0x9
    //         00491533     JL         LAB_004914d9
    //                              scr_cams.cpp:384 (11)
    //         00491535     MOV        this,dword ptr [ESP + first_any_color]
    //         00491539     PUSH       0x1
    //         0049153b     MOV        EDX,dword ptr [this->_padding_]
    //         0049153d     CALL       dword ptr [EDX + 0x4]
    //                              scr_cams.cpp:386 (8)
    //         00491540     TEST       ESI,ESI
    //         00491542     JZ         LAB_00491642
    //                              scr_cams.cpp:389 (12)
    //         00491548     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049154e     PUSH       ESI
    //         0049154f     CALL       RGE_Base_Game::setNumberPlayers                  void setNumberPlayers(RGE_Base_Game * this, i
    //                              scr_cams.cpp:394 (5)
    //         00491554     CMP        EBP,-0x1
    //         00491557     JZ         LAB_004915cd
    //                              scr_cams.cpp:396 (9)
    //         00491559     MOV        EDI,0x1
    //         0049155e     CMP        ESI,EDI
    //         00491560     JLE        LAB_004915ad
    //                               LAB_00491562                                                 XREF[1]:     00491575(j)  
    //                              scr_cams.cpp:398 (23)
    //         00491562     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491568     PUSH       EDI
    //         00491569     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
    //         0049156e     CMP        EAX,EBP
    //         00491570     JZ         LAB_00491579
    //         00491572     INC        EDI
    //         00491573     CMP        EDI,ESI
    //         00491575     JL         LAB_00491562
    //         00491577     JMP        LAB_004915ad
    //                               LAB_00491579                                                 XREF[1]:     00491570(j)  
    //                              scr_cams.cpp:400 (26)
    //         00491579     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049157f     PUSH       0x0
    //         00491581     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
    //         00491586     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049158c     PUSH       EAX
    //         0049158d     PUSH       EDI=>DAT_fffffff8
    //         0049158e     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
    //                              scr_cams.cpp:401 (26)
    //         00491593     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491599     PUSH       0x0
    //         0049159b     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
    //         004915a0     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004915a6     PUSH       EAX
    //         004915a7     PUSH       EDI=>DAT_fffffff8
    //         004915a8     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
    //                               LAB_004915ad                                                 XREF[2]:     00491560(j), 00491577(j)  
    //                              scr_cams.cpp:405 (14)
    //         004915ad     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004915b3     PUSH       EBP
    //         004915b4     PUSH       0x0=>DAT_fffffff8
    //         004915b6     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
    //                              scr_cams.cpp:406 (18)
    //         004915bb     MOV        EAX,dword ptr [ESP + 0x14]
    //         004915bf     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004915c5     PUSH       EAX
    //         004915c6     PUSH       0x0=>DAT_fffffff8
    //         004915c8     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
    //                               LAB_004915cd                                                 XREF[1]:     00491557(j)  
    //                              scr_cams.cpp:410 (15)
    //         004915cd     MOV        this,dword ptr [comm]                            = 00000000
    //         004915d3     PUSH       0x2
    //         004915d5     PUSH       offset DAT_fffffff8
    //         004915d7     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
    //                              scr_cams.cpp:411 (9)
    //         004915dc     MOV        EAX,0x1
    //         004915e1     CMP        ESI,EAX
    //         004915e3     JLE        LAB_004915fc
    //                               LAB_004915e5                                                 XREF[1]:     004915fa(j)  
    //                              scr_cams.cpp:412 (23)
    //         004915e5     MOV        this,dword ptr [comm]                            = 00000000
    //         004915eb     LEA        EDI,[EAX + 0x1]
    //         004915ee     PUSH       0x4
    //         004915f0     PUSH       EDI=>DAT_fffffff8
    //         004915f1     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
    //         004915f6     MOV        EAX,EDI
    //         004915f8     CMP        EAX,ESI
    //         004915fa     JL         LAB_004915e5
    //                               LAB_004915fc                                                 XREF[1]:     004915e3(j)  
    //                              scr_cams.cpp:413 (7)
    //         004915fc     CMP        ESI,0x9
    //         004915ff     MOV        EAX,ESI
    //         00491601     JGE        LAB_0049161b
    //                               LAB_00491603                                                 XREF[1]:     00491619(j)  
    //                              scr_cams.cpp:414 (24)
    //         00491603     MOV        this,dword ptr [comm]                            = 00000000
    //         00491609     LEA        ESI,[EAX + 0x1]
    //         0049160c     PUSH       0x0
    //         0049160e     PUSH       ESI=>DAT_fffffff8
    //         0049160f     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
    //         00491614     MOV        EAX,ESI
    //         00491616     CMP        EAX,0x9
    //         00491619     JL         LAB_00491603
    //                               LAB_0049161b                                                 XREF[1]:     00491601(j)  
    //                              scr_cams.cpp:417 (17)
    //         0049161b     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         00491621     PUSH       0x0
    //         00491623     CALL       TRIBE_Game::start_game                           int start_game(TRIBE_Game * this, int param_1)
    //         00491628     TEST       EAX,EAX
    //         0049162a     JNZ        LAB_00491642
    //                              scr_cams.cpp:418 (22)
    //         0049162c     MOV        this,dword ptr [ESP + 0x18]
    //         00491630     PUSH       0x64
    //         00491632     PUSH       offset DAT_fffffff8
    //         00491637     PUSH       EAX=>DAT_fffffff4
    //                              language.dll match for 0x961: "An error occurred while trying
    //         00491638     PUSH       offset DAT_fffffff0
    //         0049163d     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                               LAB_00491642                                                 XREF[3]:     0049136b(j), 00491542(j), 
    //                                                                                                         0049162a(j)  
    //                              scr_cams.cpp:419 (8)
    //         00491642     POP        EDI
    //         00491643     POP        ESI
    //         00491644     POP        EBP
    //         00491645     POP        EBX
    //         00491646     ADD        ESP,0xc
    //         00491649     RET
    //         0049164a     ??         90h
    //         0049164b     NOP
    //         0049164c     NOP
    //         0049164d     NOP
    //         0049164e     NOP
    //         0049164f     NOP
    return;
}

long TRIBE_Screen_Campaign_Selection::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
    // <NO ASSEMBLY FOUND>
    return 0;
}

