// Auto-generated scaffold unit: scr_load.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/scr_load.cpp
#include "../include/common.h"

// Offset: 0x0049DD40
undefined TribeLoadSavedGameScreen(TribeLoadSavedGameScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeLoadSavedGameScreen::TribeLoadSavedGameScreen(void)                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeLoadSavedGameScreen(TribeLoadSavedGameScre
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeLoadSaved    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     0049dd7a(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049e05b(R)  
    //              char[260]         Stack[-0x114   info_file                 XREF[1,2]:   0049dd66(W), 0049dde5(*), 0049de15(*)  
    //              undefined4        Stack[-0x118   local_118                 XREF[1]:     0049e052(W)  
    //              TPanel *[4]       Stack[-0x128   tabList                   XREF[2,4]:   0049ddd5(W), 0049de0c(R), 0049e03f(W), 0049e045(*), 
    //                                                                                     0049e03b(W), 0049e049(W)  
    //              TEasy_Panel *     Stack[-0x12c   from_panel
    //                               ??0TribeLoadSavedGameScreen@@QAE@XZ                          XREF[2]:     action:004986c4(c), 
    //                               TribeLoadSavedGameScreen::TribeLoadSavedGameScreen                        action:004b6f0e(c)  
    //                              scr_load.cpp:54 (47)
    //         0049dd40     PUSH       -0x1
    //         0049dd42     PUSH       FUN_0055efbb
    //         0049dd47     MOV        EAX,FS:[0x0]
    //         0049dd4d     PUSH       EAX
    //         0049dd4e     MOV        dword ptr FS:[0x0],ESP
    //         0049dd55     SUB        ESP,0x11c
    //         0049dd5b     PUSH       EBX
    //         0049dd5c     PUSH       EBP
    //         0049dd5d     PUSH       ESI
    //         0049dd5e     PUSH       EDI
    //         0049dd5f     MOV        EBP,this
    //         0049dd61     PUSH       s_Load_Saved_Game_Screen                         = "Load Saved Game Screen"
    //         0049dd66     MOV        dword ptr [ESP + info_file[0]],EBP
    //         0049dd6a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
    //                              scr_load.cpp:58 (6)
    //         0049dd6f     LEA        EBX,[EBP + 0x480]
    //                              scr_load.cpp:65 (94)
    //         0049dd75     MOV        this,panel_system
    //         0049dd7a     MOV        dword ptr [ESP + local_4],0x0
    //         0049dd85     MOV        dword ptr [EBP],TribeLoadSavedGameScreen::`vft   = 0049e080
    //         0049dd8c     MOV        dword ptr [EBP + 0x478],0x0
    //         0049dd96     MOV        dword ptr [EBP + 0x47c],0x0
    //         0049dda0     MOV        dword ptr [EBX],0x0
    //         0049dda6     MOV        dword ptr [EBP + 0x484],0x0
    //         0049ddb0     MOV        dword ptr [EBP + 0x488],0x0
    //         0049ddba     MOV        dword ptr [EBP + 0x48c],0x0
    //         0049ddc4     MOV        dword ptr [EBP + 0x490],0x0
    //         0049ddce     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
    //                              scr_load.cpp:67 (28)
    //         0049ddd3     MOV        this,EAX
    //         0049ddd5     MOV        dword ptr [ESP + tabList[0]],EAX
    //         0049ddd9     CALL       TEasy_Panel::get_info_file                       char * get_info_file(TEasy_Panel * this)
    //         0049ddde     MOV        EDI,EAX
    //         0049dde0     OR         this,0xffffffff
    //         0049dde3     XOR        EAX,EAX
    //         0049dde5     LEA        EDX=>info_file[4],[ESP + 0x28]
    //         0049dde9     SCASB.RE   ES:EDI
    //         0049ddeb     NOT        this
    //         0049dded     SUB        EDI,this
    //                              scr_load.cpp:69 (56)
    //         0049ddef     PUSH       0x1
    //         0049ddf1     MOV        EAX,this
    //         0049ddf3     MOV        ESI,EDI
    //         0049ddf5     MOV        EDI,EDX
    //         0049ddf7     SHR        this,0x2
    //         0049ddfa     MOVSD.REP  ES:EDI,ESI
    //         0049ddfc     MOV        this,EAX
    //         0049ddfe     AND        this,0x3
    //         0049de01     MOVSB.REP  ES:EDI,ESI
    //         0049de03     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049de09     MOV        ESI,dword ptr [ECX + this->_padding_]
    //         0049de0c     MOV        this,dword ptr [ESP + tabList[0]]
    //         0049de10     CALL       TEasy_Panel::get_info_id                         long get_info_id(TEasy_Panel * this)
    //         0049de15     LEA        EDX=>info_file[4],[ESP + 0x2c]
    //         0049de19     PUSH       EAX
    //         0049de1a     PUSH       EDX
    //         0049de1b     PUSH       ESI
    //         0049de1c     MOV        this,EBP
    //         0049de1e     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
    //         0049de23     TEST       EAX,EAX
    //         0049de25     JNZ        LAB_0049de36
    //                              scr_load.cpp:70 (10)
    //         0049de27     MOV        dword ptr [EBP + 0xd8],0x1
    //                              scr_load.cpp:71 (5)
    //         0049de31     JMP        LAB_0049e05b
    //                               LAB_0049de36                                                 XREF[1]:     0049de25(j)  
    //                              scr_load.cpp:74 (9)
    //         0049de36     PUSH       0x0
    //         0049de38     MOV        this,EBP
    //         0049de3a     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
    //                              scr_load.cpp:75 (17)
    //         0049de3f     PUSH       0x1e0
    //         0049de44     PUSH       0x280
    //         0049de49     MOV        this,EBP
    //         0049de4b     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long 
    //                              scr_load.cpp:78 (47)
    //         0049de50     PUSH       0x0
    //         0049de52     PUSH       0x0
    //         0049de54     PUSH       0x1
    //         0049de56     PUSH       0x1
    //         0049de58     PUSH       0x1e
    //         0049de5a     PUSH       0x258
    //         0049de5f     PUSH       0xa
    //         0049de61     PUSH       0x14
    //         0049de63     LEA        EAX,[EBP + 0x478]
    //                              language.dll match for 0x24ff: "Saved Games"
    //         0049de69     PUSH       0x24ff
    //         0049de6e     PUSH       EAX
    //         0049de6f     PUSH       EBP
    //         0049de70     MOV        this,EBP
    //         0049de72     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0049de77     TEST       EAX,EAX
    //         0049de79     JZ         LAB_0049e05b
    //                              scr_load.cpp:79 (47)
    //         0049de7f     PUSH       0x0
    //         0049de81     PUSH       0x0
    //         0049de83     PUSH       0x0
    //         0049de85     PUSH       0x4
    //         0049de87     PUSH       0x14
    //         0049de89     PUSH       0x258
    //         0049de8e     PUSH       0x2d
    //         0049de90     PUSH       0x14
    //         0049de92     LEA        EAX,[EBP + 0x47c]
    //                              language.dll match for 0x2502: "Select Saved Game"
    //         0049de98     PUSH       0x2502
    //         0049de9d     PUSH       EAX
    //         0049de9e     PUSH       EBP
    //         0049de9f     MOV        this,EBP
    //         0049dea1     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel * 
    //         0049dea6     TEST       EAX,EAX
    //         0049dea8     JZ         LAB_0049e05b
    //                              scr_load.cpp:82 (33)
    //         0049deae     PUSH       0xb
    //         0049deb0     PUSH       0x160
    //         0049deb5     PUSH       0x258
    //         0049deba     PUSH       0x41
    //         0049debc     PUSH       0x14
    //         0049debe     PUSH       EBX
    //         0049debf     PUSH       EBP
    //         0049dec0     MOV        this,EBP
    //         0049dec2     CALL       TEasy_Panel::create_list                         int create_list(TEasy_Panel * this, TPanel * 
    //         0049dec7     TEST       EAX,EAX
    //         0049dec9     JZ         LAB_0049e05b
    //                              scr_load.cpp:83 (27)
    //         0049decf     MOV        EAX,dword ptr [EBX]
    //         0049ded1     PUSH       0x14
    //         0049ded3     LEA        ESI,[EBP + 0x484]
    //         0049ded9     PUSH       EAX
    //         0049deda     PUSH       ESI
    //         0049dedb     MOV        this,EBP
    //         0049dedd     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
    //         0049dee2     TEST       EAX,EAX
    //         0049dee4     JZ         LAB_0049e05b
    //                              scr_load.cpp:84 (14)
    //         0049deea     MOV        this,dword ptr [ESI]
    //         0049deec     PUSH       -0x1
    //                              language.dll match for 0x7670: "Type a name for the game."
    //         0049deee     PUSH       0x7670
    //         0049def3     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_load.cpp:87 (50)
    //         0049def8     PUSH       0x0
    //         0049defa     PUSH       0x0
    //         0049defc     PUSH       0x0
    //         0049defe     PUSH       0x1e
    //         0049df00     PUSH       0xb4
    //         0049df05     PUSH       0x1b8
    //         0049df0a     PUSH       0x1e
    //         0049df0c     PUSH       0x0
    //         0049df0e     LEA        EDI,[EBP + 0x488]
    //                              language.dll match for 0xfa1: "OK"
    //         0049df14     PUSH       0xfa1
    //         0049df19     PUSH       EDI
    //         0049df1a     PUSH       EBP
    //         0049df1b     MOV        this,EBP
    //         0049df1d     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049df22     TEST       EAX,EAX
    //         0049df24     JZ         LAB_0049e05b
    //                              scr_load.cpp:88 (53)
    //         0049df2a     PUSH       0x0
    //         0049df2c     PUSH       0x0
    //         0049df2e     PUSH       0x0
    //         0049df30     PUSH       0x1e
    //         0049df32     PUSH       0xb4
    //         0049df37     PUSH       0x1b8
    //         0049df3c     PUSH       0xe6
    //         0049df41     PUSH       0x0
    //         0049df43     LEA        EAX,[EBP + 0x490]
    //                              language.dll match for 0x24c9: "Delete"
    //         0049df49     PUSH       0x24c9
    //         0049df4e     PUSH       EAX
    //         0049df4f     PUSH       EBP
    //         0049df50     MOV        this,EBP
    //         0049df52     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049df57     TEST       EAX,EAX
    //         0049df59     JZ         LAB_0049e05b
    //                              scr_load.cpp:89 (53)
    //         0049df5f     PUSH       0x0
    //         0049df61     PUSH       0x0
    //         0049df63     PUSH       0x0
    //         0049df65     PUSH       0x1e
    //         0049df67     PUSH       0xb4
    //         0049df6c     PUSH       0x1b8
    //         0049df71     PUSH       0x1ae
    //         0049df76     PUSH       0x0
    //         0049df78     LEA        ESI,[EBP + 0x48c]
    //                              language.dll match for 0xfa2: "Cancel"
    //         0049df7e     PUSH       0xfa2
    //         0049df83     PUSH       ESI
    //         0049df84     PUSH       EBP
    //         0049df85     MOV        this,EBP
    //         0049df87     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel 
    //         0049df8c     TEST       EAX,EAX
    //         0049df8e     JZ         LAB_0049e05b
    //                              scr_load.cpp:90 (14)
    //         0049df94     MOV        this,dword ptr [EDI]
    //         0049df96     PUSH       -0x1
    //         0049df98     PUSH       0x7531
    //         0049df9d     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_load.cpp:91 (14)
    //         0049dfa2     MOV        this,dword ptr [ESI]
    //         0049dfa4     PUSH       -0x1
    //         0049dfa6     PUSH       0x7532
    //         0049dfab     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
    //                              scr_load.cpp:92 (20)
    //         0049dfb0     MOV        EAX,dword ptr [ESI]
    //         0049dfb2     XOR        this,this
    //         0049dfb4     MOV        dword ptr [EAX + 0x298],0x1b
    //         0049dfbe     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_load.cpp:94 (12)
    //         0049dfc4     MOV        EAX,dword ptr [EBP + 0x490]
    //         0049dfca     MOV        dword ptr [EAX + 0x29c],this
    //                              scr_load.cpp:97 (17)
    //         0049dfd0     MOV        this,EBP
    //         0049dfd2     MOV        dword ptr [EAX + 0x298],0x2e
    //         0049dfdc     CALL       TribeLoadSavedGameScreen::fillList               void fillList(TribeLoadSavedGameScreen * this)
    //                              scr_load.cpp:99 (12)
    //         0049dfe1     MOV        this,dword ptr [EBX]
    //         0049dfe3     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049dfe8     CMP        byte ptr [EAX],0x0
    //         0049dfeb     JNZ        LAB_0049e003
    //                              scr_load.cpp:101 (9)
    //         0049dfed     MOV        this,dword ptr [EDI]
    //         0049dfef     PUSH       0x1
    //         0049dff1     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_load.cpp:102 (13)
    //         0049dff6     MOV        this,dword ptr [EBP + 0x490]
    //         0049dffc     PUSH       0x1
    //         0049dffe     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                               LAB_0049e003                                                 XREF[1]:     0049dfeb(j)  
    //                              scr_load.cpp:106 (19)
    //         0049e003     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e009     CALL       TRIBE_Game::get_save_game_name                   char * get_save_game_name(TRIBE_Game * this)
    //         0049e00e     MOV        this,dword ptr [EBX]
    //         0049e010     PUSH       EAX
    //         0049e011     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this, char * param
    //                              scr_load.cpp:107 (5)
    //         0049e016     CMP        EAX,-0x1
    //         0049e019     JZ         LAB_0049e027
    //                              scr_load.cpp:108 (12)
    //         0049e01b     MOV        this,dword ptr [EBX]
    //         0049e01d     PUSH       0x1
    //         0049e01f     PUSH       EAX
    //         0049e020     PUSH       0x1
    //         0049e022     CALL       TListPanel::scroll_cur_line                      void scroll_cur_line(TListPanel * this, uchar
    //                               LAB_0049e027                                                 XREF[1]:     0049e019(j)  
    //                              scr_load.cpp:111 (10)
    //         0049e027     MOV        this,dword ptr [EBX]
    //         0049e029     PUSH       this
    //         0049e02a     MOV        this,EBP
    //         0049e02c     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
    //                              scr_load.cpp:115 (4)
    //         0049e031     MOV        EAX,dword ptr [EDI]
    //         0049e033     MOV        EDX,dword ptr [EBX]
    //                              scr_load.cpp:116 (14)
    //         0049e035     MOV        this,dword ptr [EBP + 0x490]
    //         0049e03b     MOV        dword ptr [ESP + tabList[2]],EAX
    //         0049e03f     MOV        dword ptr [ESP + tabList[1]],EDX
    //                              scr_load.cpp:117 (2)
    //         0049e043     MOV        EDX,dword ptr [ESI]
    //                              scr_load.cpp:118 (22)
    //         0049e045     LEA        EAX=>tabList[1],[ESP + 0x14]
    //         0049e049     MOV        dword ptr [ESP + tabList[3]],this
    //         0049e04d     PUSH       0x4
    //         0049e04f     PUSH       EAX
    //         0049e050     MOV        this,EBP
    //         0049e052     MOV        dword ptr [ESP + local_118],EDX
    //         0049e056     CALL       TPanel::set_tab_order                            void set_tab_order(TPanel * this, TPanel * * 
    //                               LAB_0049e05b                                                 XREF[8]:     0049de31(j), 0049de79(j), 
    //                                                                                                         0049dea8(j), 0049dec9(j), 
    //                                                                                                         0049dee4(j), 0049df24(j), 
    //                                                                                                         0049df59(j), 0049df8e(j)  
    //                              scr_load.cpp:119 (27)
    //         0049e05b     MOV        this,dword ptr [ESP + local_c]
    //         0049e062     POP        EDI
    //         0049e063     MOV        EAX,EBP
    //         0049e065     POP        ESI
    //         0049e066     POP        EBP
    //         0049e067     MOV        dword ptr FS:[0x0],this
    //         0049e06e     POP        EBX
    //         0049e06f     ADD        ESP,0x128
    //         0049e075     RET
}

// Offset: 0x0049E0A0
void TribeLoadSavedGameScreen(TribeLoadSavedGameScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen(void)                  *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeLoadSavedGameScreen(TribeLoadSavedGameScreen *
    //              void              <VOID>         <RETURN>
    //              TribeLoadSaved    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049e0c9(W), 0049e12d(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049e13a(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     0049e0b9(W)  
    //                               ??1TribeLoadSavedGameScreen@@UAE@XZ                          XREF[1]:     `vector_deleting_destructor':0049e
    //                               TribeLoadSavedGameScreen::~TribeLoadSavedGameScreen
    //                              scr_load.cpp:124 (35)
    //         0049e0a0     PUSH       -0x1
    //         0049e0a2     PUSH       FUN_0055efd8
    //         0049e0a7     MOV        EAX,FS:[0x0]
    //         0049e0ad     PUSH       EAX
    //         0049e0ae     MOV        dword ptr FS:[0x0],ESP
    //         0049e0b5     PUSH       this
    //         0049e0b6     PUSH       ESI
    //         0049e0b7     MOV        ESI,this
    //         0049e0b9     MOV        dword ptr [ESP + local_10],ESI
    //         0049e0bd     MOV        dword ptr [ESI],TribeLoadSavedGameScreen::`vft   = 0049e080
    //                              scr_load.cpp:125 (20)
    //         0049e0c3     LEA        EAX,[ESI + 0x478]
    //         0049e0c9     MOV        dword ptr [ESP + local_4],0x0
    //         0049e0d1     PUSH       EAX
    //         0049e0d2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_load.cpp:126 (14)
    //         0049e0d7     LEA        this,[ESI + 0x47c]
    //         0049e0dd     PUSH       this
    //         0049e0de     MOV        this,ESI
    //         0049e0e0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_load.cpp:127 (14)
    //         0049e0e5     LEA        EDX,[ESI + 0x480]
    //         0049e0eb     MOV        this,ESI
    //         0049e0ed     PUSH       EDX
    //         0049e0ee     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_load.cpp:128 (14)
    //         0049e0f3     LEA        EAX,[ESI + 0x484]
    //         0049e0f9     MOV        this,ESI
    //         0049e0fb     PUSH       EAX
    //         0049e0fc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_load.cpp:129 (14)
    //         0049e101     LEA        this,[ESI + 0x488]
    //         0049e107     PUSH       this
    //         0049e108     MOV        this,ESI
    //         0049e10a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_load.cpp:130 (14)
    //         0049e10f     LEA        EDX,[ESI + 0x48c]
    //         0049e115     MOV        this,ESI
    //         0049e117     PUSH       EDX
    //         0049e118     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //                              scr_load.cpp:131 (16)
    //         0049e11d     LEA        EAX,[ESI + 0x490]
    //         0049e123     MOV        this,ESI
    //         0049e125     PUSH       EAX
    //         0049e126     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
    //         0049e12b     MOV        this,ESI
    //                              scr_load.cpp:132 (29)
    //         0049e12d     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0049e135     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
    //         0049e13a     MOV        this,dword ptr [ESP + local_c]
    //         0049e13e     POP        ESI
    //         0049e13f     MOV        dword ptr FS:[0x0],this
    //         0049e146     ADD        ESP,0x10
    //         0049e149     RET
}

// Offset: 0x0049E150
void fillList(TribeLoadSavedGameScreen* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * protected: void __thiscall TribeLoadSavedGameScreen::fillList(void)                                   *
    //                              *********************************************************************************************************
    //                              void __thiscall fillList(TribeLoadSavedGameScreen * this)
    //              void              <VOID>         <RETURN>
    //              TribeLoadSaved    ECX:4 (auto)   this
    //              _finddata_t       Stack[-0x11c   fileInfo                  XREF[0,8]:   0049e199(*), 0049e1f8(*), 0049e230(*), 0049e28f(*), 
    //                                                                                     0049e1b5(*), 0049e1c6(*), 0049e24c(*), 0049e25d(*)  
    //              char[260]         Stack[-0x220   file_name                 XREF[0,8]:   0049e17d(*), 0049e1a0(*), 0049e1cf(*), 0049e1e7(*), 
    //                                                                                     0049e214(*), 0049e237(*), 0049e266(*), 0049e27e(*)  
    //                               ?fillList@TribeLoadSavedGameScreen@@IAEXXZ                   XREF[1]:     TribeLoadSavedGameScreen:0049dfdc(
    //                               TribeLoadSavedGameScreen::fillList
    //                              scr_load.cpp:137 (12)
    //         0049e150     SUB        ESP,0x21c
    //         0049e156     PUSH       EBX
    //         0049e157     PUSH       EBP
    //         0049e158     MOV        EBP,this
    //         0049e15a     PUSH       ESI
    //         0049e15b     PUSH       EDI
    //                              scr_load.cpp:144 (11)
    //         0049e15c     MOV        this,dword ptr [EBP + 0x480]
    //         0049e162     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
    //                              scr_load.cpp:145 (16)
    //         0049e167     MOV        EAX,dword ptr [EBP + 0x480]
    //         0049e16d     MOV        dword ptr [EAX + 0x15c],0x1
    //                              scr_load.cpp:148 (34)
    //         0049e177     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e17d     LEA        EAX=>file_name[4],[ESP + 0x10]
    //         0049e181     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0049e184     ADD        EDX,0xb12
    //         0049e18a     PUSH       EDX
    //         0049e18b     PUSH       s_%s*.gam                                        = "%s*.gam"
    //         0049e190     PUSH       EAX
    //         0049e191     CALL       sprintf                                          undefined sprintf()
    //         0049e196     ADD        ESP,0xc
    //                              scr_load.cpp:149 (23)
    //         0049e199     LEA        this=>fileInfo.time_create,[ESP + 0x114]
    //         0049e1a0     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         0049e1a4     PUSH       this
    //         0049e1a5     PUSH       EDX
    //         0049e1a6     CALL       __findfirst                                      undefined __findfirst()
    //         0049e1ab     MOV        EBX,EAX
    //         0049e1ad     ADD        ESP,0x8
    //                              scr_load.cpp:150 (5)
    //         0049e1b0     CMP        EBX,-0x1
    //         0049e1b3     JZ         LAB_0049e20e
    //                               LAB_0049e1b5                                                 XREF[1]:     0049e20c(j)  
    //                              scr_load.cpp:151 (17)
    //         0049e1b5     LEA        EDI=>fileInfo+0x18,[ESP + 0x128]
    //         0049e1bc     OR         this,0xffffffff
    //         0049e1bf     XOR        EAX,EAX
    //         0049e1c1     SCASB.RE   ES:EDI
    //         0049e1c3     NOT        this
    //         0049e1c5     DEC        this
    //                              scr_load.cpp:152 (24)
    //         0049e1c6     LEA        EAX=>fileInfo+0x18,[ESP + 0x128]
    //         0049e1cd     MOV        ESI,this
    //         0049e1cf     LEA        this=>file_name[4],[ESP + 0x10]
    //         0049e1d3     SUB        ESI,0x4
    //         0049e1d6     PUSH       ESI
    //         0049e1d7     PUSH       EAX
    //         0049e1d8     PUSH       this
    //         0049e1d9     CALL       strncpy                                          undefined strncpy()
    //                              scr_load.cpp:154 (26)
    //         0049e1de     MOV        this,dword ptr [EBP + 0x480]
    //         0049e1e4     ADD        ESP,0xc
    //         0049e1e7     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         0049e1eb     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
    //         0049e1f0     PUSH       0x0
    //         0049e1f2     PUSH       EDX
    //         0049e1f3     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              scr_load.cpp:155 (22)
    //         0049e1f8     LEA        EAX=>fileInfo.time_create,[ESP + 0x114]
    //         0049e1ff     PUSH       EAX
    //         0049e200     PUSH       EBX
    //         0049e201     CALL       __findnext                                       undefined __findnext()
    //         0049e206     ADD        ESP,0x8
    //         0049e209     CMP        EAX,-0x1
    //         0049e20c     JNZ        LAB_0049e1b5
    //                               LAB_0049e20e                                                 XREF[1]:     0049e1b3(j)  
    //                              scr_load.cpp:160 (34)
    //         0049e20e     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e214     LEA        EAX=>file_name[4],[ESP + 0x10]
    //         0049e218     MOV        EDX,dword ptr [ECX + this->_padding_]
    //         0049e21b     ADD        EDX,0xb12
    //         0049e221     PUSH       EDX
    //         0049e222     PUSH       s_%s*.gmx                                        = "%s*.gmx"
    //         0049e227     PUSH       EAX
    //         0049e228     CALL       sprintf                                          undefined sprintf()
    //         0049e22d     ADD        ESP,0xc
    //                              scr_load.cpp:161 (23)
    //         0049e230     LEA        this=>fileInfo.time_create,[ESP + 0x114]
    //         0049e237     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         0049e23b     PUSH       this
    //         0049e23c     PUSH       EDX
    //         0049e23d     CALL       __findfirst                                      undefined __findfirst()
    //         0049e242     MOV        EBX,EAX
    //         0049e244     ADD        ESP,0x8
    //                              scr_load.cpp:162 (5)
    //         0049e247     CMP        EBX,-0x1
    //         0049e24a     JZ         LAB_0049e2a5
    //                               LAB_0049e24c                                                 XREF[1]:     0049e2a3(j)  
    //                              scr_load.cpp:163 (17)
    //         0049e24c     LEA        EDI=>fileInfo+0x18,[ESP + 0x128]
    //         0049e253     OR         this,0xffffffff
    //         0049e256     XOR        EAX,EAX
    //         0049e258     SCASB.RE   ES:EDI
    //         0049e25a     NOT        this
    //         0049e25c     DEC        this
    //                              scr_load.cpp:164 (24)
    //         0049e25d     LEA        EAX=>fileInfo+0x18,[ESP + 0x128]
    //         0049e264     MOV        ESI,this
    //         0049e266     LEA        this=>file_name[4],[ESP + 0x10]
    //         0049e26a     SUB        ESI,0x4
    //         0049e26d     PUSH       ESI
    //         0049e26e     PUSH       EAX
    //         0049e26f     PUSH       this
    //         0049e270     CALL       strncpy                                          undefined strncpy()
    //                              scr_load.cpp:166 (26)
    //         0049e275     MOV        this,dword ptr [EBP + 0x480]
    //         0049e27b     ADD        ESP,0xc
    //         0049e27e     LEA        EDX=>file_name[4],[ESP + 0x10]
    //         0049e282     MOV        byte ptr [ESP + ESI*0x1 + 0x10],0x0
    //         0049e287     PUSH       0x0
    //         0049e289     PUSH       EDX
    //         0049e28a     CALL       TTextPanel::append_line                          int append_line(TTextPanel * this, char * par
    //                              scr_load.cpp:167 (22)
    //         0049e28f     LEA        EAX=>fileInfo.time_create,[ESP + 0x114]
    //         0049e296     PUSH       EAX
    //         0049e297     PUSH       EBX
    //         0049e298     CALL       __findnext                                       undefined __findnext()
    //         0049e29d     ADD        ESP,0x8
    //         0049e2a0     CMP        EAX,-0x1
    //         0049e2a3     JNZ        LAB_0049e24c
    //                               LAB_0049e2a5                                                 XREF[1]:     0049e24a(j)  
    //                              scr_load.cpp:170 (11)
    //         0049e2a5     POP        EDI
    //         0049e2a6     POP        ESI
    //         0049e2a7     POP        EBP
    //         0049e2a8     POP        EBX
    //         0049e2a9     ADD        ESP,0x21c
    //         0049e2af     RET
}

// Offset: 0x0049E2B0
long TribeLoadSavedGameScreen::handle_idle() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeLoadSavedGameScreen::handle_idle(void)                           *
    //                              *********************************************************************************************************
    //                              long __thiscall handle_idle(TribeLoadSavedGameScreen * this)
    //              long              EAX:4          <RETURN>
    //              TribeLoadSaved    ECX:4 (auto)   this
    //                               ?handle_idle@TribeLoadSavedGameScreen@@UAEJXZ                XREF[1]:     00572e74(*)  
    //                               TribeLoadSavedGameScreen::handle_idle
    //                              scr_load.cpp:176 (3)
    //         0049e2b0     PUSH       ESI
    //         0049e2b1     MOV        ESI,this
    //                              scr_load.cpp:177 (16)
    //         0049e2b3     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e2b9     MOV        EAX,dword ptr [ECX + this->_padding_]
    //         0049e2bf     TEST       EAX,EAX
    //         0049e2c1     JNZ        LAB_0049e2c8
    //                              scr_load.cpp:178 (5)
    //         0049e2c3     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
    //                               LAB_0049e2c8                                                 XREF[1]:     0049e2c1(j)  
    //                              scr_load.cpp:180 (7)
    //         0049e2c8     MOV        this,ESI
    //         0049e2ca     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
    //                              scr_load.cpp:181 (2)
    //         0049e2cf     POP        ESI
    //         0049e2d0     RET
}

// Offset: 0x0049E2E0
long TribeLoadSavedGameScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual long __thiscall TribeLoadSavedGameScreen::action(class TPanel *,long,unsigned long... *
    //                              *********************************************************************************************************
    //                              long __thiscall action(TribeLoadSavedGameScreen * this, TPanel * par
    //              long              EAX:4          <RETURN>
    //              TribeLoadSaved    ECX:4 (auto)   this
    //              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     0049e306(R)  
    //              long              Stack[0x8]:4   param_2                   XREF[2]:     0049e2fc(R), 0049e372(R)  
    //              ulong             Stack[0xc]:4   param_3                   XREF[1]:     0049e6a0(R)  
    //              ulong             Stack[0x10]:4  param_4                   XREF[1]:     0049e699(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     0049e653(W), 0049e669(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     0049e6b2(R)  
    //              _finddata_t       Stack[-0x23c   fileInfo                  XREF[0,3]:   0049e487(*), 0049e498(*), 0049e564(*)  
    //              char[260]         Stack[-0x340   fileNameNoExt             XREF[0,4]:   0049e51c(*), 0049e544(*), 0049e57e(*), 0049e592(*)  
    //              char[260]         Stack[-0x444   fileName                  XREF[1,11]:  0049e64d(W), 0049e39c(*), 0049e3ae(*), 0049e3d6(*), 
    //                                                                                     0049e3e8(*), 0049e461(*), 0049e482(*), 0049e552(*), 
    //                                                                                     0049e56b(*), 0049e585(*), 0049e599(*), 0049e5b2(*)  
    //                               ?action@TribeLoadSavedGameScreen@@UAEJPAVTPanel@@JKK@Z       XREF[1]:     00572edc(*)  
    //                               TribeLoadSavedGameScreen::action
    //                              scr_load.cpp:187 (28)
    //         0049e2e0     MOV        EAX,FS:[0x0]
    //         0049e2e6     PUSH       -0x1
    //         0049e2e8     PUSH       FUN_0055effe
    //         0049e2ed     PUSH       EAX
    //         0049e2ee     MOV        dword ptr FS:[0x0],ESP
    //         0049e2f5     SUB        ESP,0x438
    //         0049e2fb     PUSH       EBX
    //                              scr_load.cpp:188 (27)
    //         0049e2fc     MOV        EBX,dword ptr [ESP + param_2]
    //         0049e303     PUSH       EBP
    //         0049e304     PUSH       ESI
    //         0049e305     PUSH       EDI
    //         0049e306     MOV        EDI,dword ptr [ESP + param_1]
    //         0049e30d     TEST       EDI,EDI
    //         0049e30f     MOV        EBP,this
    //         0049e311     JZ         LAB_0049e699
    //                              scr_load.cpp:189 (76)
    //         0049e317     MOV        this,EDI
    //         0049e319     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //         0049e31e     TEST       EAX,EAX
    //         0049e320     JZ         LAB_0049e444
    //         0049e326     MOV        this,EDI
    //         0049e328     MOV        ESI,s_Cancel_Dialog                              = 43h
    //         0049e32d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
    //                               LAB_0049e332                                                 XREF[1]:     0049e350(j)  
    //         0049e332     MOV        DL,byte ptr [EAX]
    //         0049e334     MOV        this,DL
    //         0049e336     CMP        DL,byte ptr [ESI]=>s_Cancel_Dialog               = 43h
    //                                                                                  = 6Eh
    //         0049e338     JNZ        LAB_0049e356
    //         0049e33a     TEST       this,this
    //         0049e33c     JZ         LAB_0049e352
    //         0049e33e     MOV        DL,byte ptr [EAX + 0x1]
    //         0049e341     MOV        this,DL
    //         0049e343     CMP        DL,byte ptr [ESI + 0x1]=>DAT_005860e5            = 61h
    //                                                                                  = "cel Dialog"
    //         0049e346     JNZ        LAB_0049e356
    //         0049e348     ADD        EAX,0x2
    //         0049e34b     ADD        ESI,0x2
    //         0049e34e     TEST       this,this
    //         0049e350     JNZ        LAB_0049e332
    //                               LAB_0049e352                                                 XREF[1]:     0049e33c(j)  
    //         0049e352     XOR        EAX,EAX
    //         0049e354     JMP        LAB_0049e35b
    //                               LAB_0049e356                                                 XREF[2]:     0049e338(j), 0049e346(j)  
    //         0049e356     SBB        EAX,EAX
    //         0049e358     SBB        EAX,-0x1
    //                               LAB_0049e35b                                                 XREF[1]:     0049e354(j)  
    //         0049e35b     TEST       EAX,EAX
    //         0049e35d     JNZ        LAB_0049e444
    //                              scr_load.cpp:191 (15)
    //         0049e363     PUSH       s_Cancel_Dialog                                  = 43h
    //         0049e368     MOV        this,panel_system
    //         0049e36d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                              scr_load.cpp:193 (15)
    //         0049e372     MOV        EAX,dword ptr [ESP + param_2]
    //         0049e379     TEST       EAX,EAX
    //         0049e37b     JNZ        LAB_0049e692
    //                              scr_load.cpp:198 (45)
    //         0049e381     MOV        EAX,[rge_base_game]                              = 00000000
    //         0049e386     MOV        this,dword ptr [EBP + 0x480]
    //         0049e38c     MOV        ESI,dword ptr [EAX + 0xc]
    //         0049e38f     ADD        ESI,0xb12
    //         0049e395     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049e39a     PUSH       EAX
    //         0049e39b     PUSH       ESI
    //         0049e39c     LEA        this=>fileName[4],[ESP + 0x1c]
    //         0049e3a0     PUSH       s_%s%s.gam                                       = "%s%s.gam"
    //         0049e3a5     PUSH       this
    //         0049e3a6     CALL       sprintf                                          undefined sprintf()
    //         0049e3ab     ADD        ESP,0x10
    //                              scr_load.cpp:199 (10)
    //         0049e3ae     LEA        EDX=>fileName[4],[ESP + 0x14]
    //         0049e3b2     PUSH       EDX
    //         0049e3b3     CALL       __unlink                                         undefined __unlink()
    //                              scr_load.cpp:201 (48)
    //         0049e3b8     MOV        EAX,[rge_base_game]                              = 00000000
    //         0049e3bd     MOV        this,dword ptr [EBP + 0x480]
    //         0049e3c3     ADD        ESP,0x4
    //         0049e3c6     MOV        ESI,dword ptr [EAX + 0xc]
    //         0049e3c9     ADD        ESI,0xb12
    //         0049e3cf     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049e3d4     PUSH       EAX
    //         0049e3d5     PUSH       ESI
    //         0049e3d6     LEA        this=>fileName[4],[ESP + 0x1c]
    //         0049e3da     PUSH       s_%s%s.gmx                                       = "%s%s.gmx"
    //         0049e3df     PUSH       this
    //         0049e3e0     CALL       sprintf                                          undefined sprintf()
    //         0049e3e5     ADD        ESP,0x10
    //                              scr_load.cpp:202 (10)
    //         0049e3e8     LEA        EDX=>fileName[4],[ESP + 0x14]
    //         0049e3ec     PUSH       EDX
    //         0049e3ed     CALL       __unlink                                         undefined __unlink()
    //                              scr_load.cpp:205 (26)
    //         0049e3f2     MOV        this,dword ptr [EBP + 0x480]
    //         0049e3f8     ADD        ESP,0x4
    //         0049e3fb     CALL       TTextPanel::get_line                             long get_line(TTextPanel * this)
    //         0049e400     MOV        this,dword ptr [EBP + 0x480]
    //         0049e406     PUSH       EAX
    //         0049e407     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
    //                              scr_load.cpp:207 (20)
    //         0049e40c     MOV        this,dword ptr [EBP + 0x480]
    //         0049e412     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049e417     CMP        byte ptr [EAX],0x0
    //         0049e41a     JNZ        LAB_0049e692
    //                              scr_load.cpp:209 (13)
    //         0049e420     MOV        this,dword ptr [EBP + 0x488]
    //         0049e426     PUSH       0x1
    //         0049e428     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_load.cpp:210 (13)
    //         0049e42d     MOV        this,dword ptr [EBP + 0x490]
    //         0049e433     PUSH       0x1
    //         0049e435     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
    //                              scr_load.cpp:214 (10)
    //         0049e43a     MOV        EAX,0x1
    //         0049e43f     JMP        LAB_0049e6b2
    //                               LAB_0049e444                                                 XREF[2]:     0049e320(j), 0049e35d(j)  
    //                              scr_load.cpp:216 (13)
    //         0049e444     CMP        EDI,dword ptr [EBP + 0x490]
    //         0049e44a     JNZ        LAB_0049e4b3
    //         0049e44c     CMP        EBX,0x1
    //         0049e44f     JNZ        LAB_0049e4b3
    //                              scr_load.cpp:220 (16)
    //         0049e451     MOV        this,dword ptr [EBP + 0x480]
    //         0049e457     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049e45c     CMP        byte ptr [EAX],0x0
    //         0049e45f     JZ         LAB_0049e4b3
    //                              scr_load.cpp:222 (22)
    //         0049e461     LEA        EAX=>fileName[4],[ESP + 0x14]
    //         0049e465     PUSH       0x100
    //         0049e46a     PUSH       EAX
    //                              language.dll match for 0x24ca: "Are you sure you want to dele
    //         0049e46b     PUSH       0x24ca
    //         0049e470     MOV        this,EBP
    //         0049e472     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
    //                              scr_load.cpp:223 (33)
    //         0049e477     MOV        this,dword ptr [EBP + 0x480]
    //         0049e47d     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049e482     LEA        this=>fileName[4],[ESP + 0x14]
    //         0049e486     PUSH       EAX
    //         0049e487     LEA        EDX=>fileInfo.time_create,[ESP + 0x220]
    //         0049e48e     PUSH       this
    //         0049e48f     PUSH       EDX
    //         0049e490     CALL       sprintf                                          undefined sprintf()
    //         0049e495     ADD        ESP,0xc
    //                              scr_load.cpp:224 (27)
    //         0049e498     LEA        EAX=>fileInfo.time_create,[ESP + 0x21c]
    //         0049e49f     MOV        this,EBP
    //         0049e4a1     PUSH       0x64
    //         0049e4a3     PUSH       0x1c2
    //         0049e4a8     PUSH       s_Cancel_Dialog                                  = 43h
    //         0049e4ad     PUSH       EAX
    //         0049e4ae     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
    //                               LAB_0049e4b3                                                 XREF[3]:     0049e44a(j), 0049e44f(j), 
    //                                                                                                         0049e45f(j)  
    //                              scr_load.cpp:227 (10)
    //         0049e4b3     MOV        this,dword ptr [EBP + 0x480]
    //         0049e4b9     CMP        EDI,this
    //         0049e4bb     JNZ        LAB_0049e4e8
    //                              scr_load.cpp:228 (9)
    //         0049e4bd     CMP        EBX,0x3
    //         0049e4c0     JNZ        LAB_0049e699
    //                              scr_load.cpp:229 (24)
    //         0049e4c6     MOV        EAX,dword ptr [EBP + 0x488]
    //         0049e4cc     MOV        EDX,dword ptr [EBP]
    //         0049e4cf     PUSH       0x0
    //         0049e4d1     PUSH       0x0
    //         0049e4d3     PUSH       0x1
    //         0049e4d5     PUSH       EAX
    //         0049e4d6     MOV        this,EBP
    //         0049e4d8     CALL       dword ptr [EDX + 0xb4]
    //                              scr_load.cpp:230 (10)
    //         0049e4de     MOV        EAX,0x1
    //         0049e4e3     JMP        LAB_0049e6b2
    //                               LAB_0049e4e8                                                 XREF[1]:     0049e4bb(j)  
    //                              scr_load.cpp:233 (12)
    //         0049e4e8     CMP        EDI,dword ptr [EBP + 0x488]
    //         0049e4ee     JNZ        LAB_0049e5e2
    //                              scr_load.cpp:234 (9)
    //         0049e4f4     CMP        EBX,0x1
    //         0049e4f7     JNZ        LAB_0049e699
    //                              scr_load.cpp:235 (13)
    //         0049e4fd     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
    //         0049e502     TEST       EAX,EAX
    //         0049e504     JLE        LAB_0049e692
    //                              scr_load.cpp:238 (37)
    //         0049e50a     MOV        this,dword ptr [EBP + 0x480]
    //         0049e510     CALL       TTextPanel::currentLine                          char * currentLine(TTextPanel * this)
    //         0049e515     MOV        EDI,EAX
    //         0049e517     OR         this,0xffffffff
    //         0049e51a     XOR        EAX,EAX
    //         0049e51c     LEA        EDX=>fileNameNoExt[4],[ESP + 0x118]
    //         0049e523     SCASB.RE   ES:EDI
    //         0049e525     NOT        this
    //         0049e527     SUB        EDI,this
    //         0049e529     MOV        EAX,this
    //         0049e52b     MOV        ESI,EDI
    //         0049e52d     MOV        EDI,EDX
    //                              scr_load.cpp:240 (53)
    //         0049e52f     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
    //         0049e535     SHR        this,0x2
    //         0049e538     MOVSD.REP  ES:EDI,ESI
    //         0049e53a     MOV        this,EAX
    //         0049e53c     AND        this,0x3
    //         0049e53f     MOVSB.REP  ES:EDI,ESI
    //         0049e541     MOV        EAX,dword ptr [EDX + 0xc]
    //         0049e544     LEA        this=>fileNameNoExt[4],[ESP + 0x118]
    //         0049e54b     ADD        EAX,0xb12
    //         0049e550     PUSH       this
    //         0049e551     PUSH       EAX
    //         0049e552     LEA        this=>fileName[4],[ESP + 0x1c]
    //         0049e556     PUSH       s_%s%s.gmx                                       = "%s%s.gmx"
    //         0049e55b     PUSH       this
    //         0049e55c     CALL       sprintf                                          undefined sprintf()
    //         0049e561     ADD        ESP,0x10
    //                              scr_load.cpp:243 (21)
    //         0049e564     LEA        EDX=>fileInfo.time_create,[ESP + 0x21c]
    //         0049e56b     LEA        EAX=>fileName[4],[ESP + 0x14]
    //         0049e56f     PUSH       EDX
    //         0049e570     PUSH       EAX
    //         0049e571     CALL       __findfirst                                      undefined __findfirst()
    //         0049e576     ADD        ESP,0x8
    //                              scr_load.cpp:244 (5)
    //         0049e579     CMP        EAX,-0x1
    //         0049e57c     JNZ        LAB_0049e592
    //                              scr_load.cpp:245 (18)
    //         0049e57e     LEA        this=>fileNameNoExt[4],[ESP + 0x118]
    //         0049e585     LEA        EDX=>fileName[4],[ESP + 0x14]
    //         0049e589     PUSH       this
    //         0049e58a     PUSH       s_%s.gam                                         = "%s.gam"
    //         0049e58f     PUSH       EDX
    //                              scr_load.cpp:246 (2)
    //         0049e590     JMP        LAB_0049e5a4
    //                               LAB_0049e592                                                 XREF[1]:     0049e57c(j)  
    //                              scr_load.cpp:247 (23)
    //         0049e592     LEA        EAX=>fileNameNoExt[4],[ESP + 0x118]
    //         0049e599     LEA        this=>fileName[4],[ESP + 0x14]
    //         0049e59d     PUSH       EAX
    //         0049e59e     PUSH       s_%s.gmx                                         = "%s.gmx"
    //         0049e5a3     PUSH       this
    //                               LAB_0049e5a4                                                 XREF[1]:     0049e590(j)  
    //         0049e5a4     CALL       sprintf                                          undefined sprintf()
    //                              scr_load.cpp:250 (27)
    //         0049e5a9     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e5af     ADD        ESP,0xc
    //         0049e5b2     LEA        EDX=>fileName[4],[ESP + 0x14]
    //         0049e5b6     PUSH       EDX
    //         0049e5b7     CALL       TRIBE_Game::load_game                            int load_game(TRIBE_Game * this, char * param
    //         0049e5bc     TEST       EAX,EAX
    //         0049e5be     JNZ        LAB_0049e692
    //                              scr_load.cpp:251 (20)
    //         0049e5c4     PUSH       0x64
    //         0049e5c6     PUSH       0x1c2
    //         0049e5cb     PUSH       EAX
    //                              language.dll match for 0x2501: "Cannot load that saved game."
    //         0049e5cc     PUSH       0x2501
    //         0049e5d1     MOV        this,EBP
    //         0049e5d3     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
    //                              scr_load.cpp:253 (10)
    //         0049e5d8     MOV        EAX,0x1
    //         0049e5dd     JMP        LAB_0049e6b2
    //                               LAB_0049e5e2                                                 XREF[1]:     0049e4ee(j)  
    //                              scr_load.cpp:256 (12)
    //         0049e5e2     CMP        EDI,dword ptr [EBP + 0x48c]
    //         0049e5e8     JNZ        LAB_0049e699
    //                              scr_load.cpp:257 (9)
    //         0049e5ee     CMP        EBX,0x1
    //         0049e5f1     JNZ        LAB_0049e699
    //                              scr_load.cpp:258 (15)
    //         0049e5f7     PUSH       s_Game_Screen                                    = "Game Screen"
    //         0049e5fc     MOV        this,panel_system
    //         0049e601     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
    //                              scr_load.cpp:259 (35)
    //         0049e606     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e60c     TEST       EAX,EAX
    //         0049e60e     JZ         LAB_0049e63b
    //         0049e610     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
    //         0049e615     CMP        EAX,EBX
    //         0049e617     JNZ        LAB_0049e632
    //         0049e619     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         0049e61f     MOV        EAX,dword ptr [this->_padding_ + 0xa00]
    //         0049e625     TEST       EAX,EAX
    //         0049e627     JNZ        LAB_0049e632
    //                              scr_load.cpp:260 (9)
    //         0049e629     PUSH       0x0
    //         0049e62b     PUSH       0x0
    //         0049e62d     CALL       RGE_Base_Game::set_paused                        void set_paused(RGE_Base_Game * this, int par
    //                               LAB_0049e632                                                 XREF[2]:     0049e617(j), 0049e627(j)  
    //                              scr_load.cpp:261 (7)
    //         0049e632     PUSH       0x0
    //         0049e634     PUSH       s_Game_Screen                                    = "Game Screen"
    //                              scr_load.cpp:263 (2)
    //         0049e639     JMP        LAB_0049e679
    //                               LAB_0049e63b                                                 XREF[1]:     0049e60e(j)  
    //                              scr_load.cpp:264 (5)
    //         0049e63b     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
    //                              scr_load.cpp:265 (39)
    //         0049e640     PUSH       0x49c
    //         0049e645     CALL       operator_new                                     void * operator_new(uint param_1)
    //         0049e64a     ADD        ESP,0x4
    //         0049e64d     MOV        dword ptr [ESP + fileName[0]],EAX
    //         0049e651     TEST       EAX,EAX
    //         0049e653     MOV        dword ptr [ESP + local_4],0x0
    //         0049e65e     JZ         LAB_0049e667
    //         0049e660     MOV        this,EAX
    //         0049e662     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
    //                               LAB_0049e667                                                 XREF[1]:     0049e65e(j)  
    //                              scr_load.cpp:266 (28)
    //         0049e667     PUSH       0x0
    //         0049e669     MOV        dword ptr [ESP + local_4],0xffffffff
    //         0049e674     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
    //                               LAB_0049e679                                                 XREF[1]:     0049e639(j)  
    //         0049e679     MOV        this,panel_system
    //         0049e67e     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
    //                              scr_load.cpp:268 (15)
    //         0049e683     PUSH       s_Load_Saved_Game_Screen                         = "Load Saved Game Screen"
    //         0049e688     MOV        this,panel_system
    //         0049e68d     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char * 
    //                               LAB_0049e692                                                 XREF[4]:     0049e37b(j), 0049e41a(j), 
    //                                                                                                         0049e504(j), 0049e5be(j)  
    //                              scr_load.cpp:269 (7)
    //         0049e692     MOV        EAX,0x1
    //         0049e697     JMP        LAB_0049e6b2
    //                               LAB_0049e699                                                 XREF[5]:     0049e311(j), 0049e4c0(j), 
    //                                                                                                         0049e4f7(j), 0049e5e8(j), 
    //                                                                                                         0049e5f1(j)  
    //                              scr_load.cpp:274 (25)
    //         0049e699     MOV        EAX,dword ptr [ESP + param_4]
    //         0049e6a0     MOV        this,dword ptr [ESP + param_3]
    //         0049e6a7     PUSH       EAX
    //         0049e6a8     PUSH       this
    //         0049e6a9     PUSH       EBX
    //         0049e6aa     PUSH       EDI
    //         0049e6ab     MOV        this,EBP
    //         0049e6ad     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
    //                               LAB_0049e6b2                                                 XREF[4]:     0049e43f(j), 0049e4e3(j), 
    //                                                                                                         0049e5dd(j), 0049e697(j)  
    //                              scr_load.cpp:275 (27)
    //         0049e6b2     MOV        this,dword ptr [ESP + local_c]
    //         0049e6b9     POP        EDI
    //         0049e6ba     POP        ESI
    //         0049e6bb     POP        EBP
    //         0049e6bc     MOV        dword ptr FS:[0x0],this
    //         0049e6c3     POP        EBX
    //         0049e6c4     ADD        ESP,0x444
    //         0049e6ca     RET        0x10
}

