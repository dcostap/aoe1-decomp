#include "common.h"
#include "Pnl_scr.h"

TScreenPanel::TScreenPanel() {
    /* TODO: Stub */
    //                              undefined __thiscall TScreenPanel(TScreenPanel * this)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //                               ??0TScreenPanel@@QAE@XZ
    //                               TScreenPanel::TScreenPanel
    //                              Pnl_scr.cpp:44 (14)
    //         0047ba70     PUSH       ESI
    //         0047ba71     MOV        ESI,this
    //         0047ba73     CALL       TEasy_Panel::TEasy_Panel                         undefined TEasy_Panel(TEasy_Panel * this)
    //         0047ba78     MOV        dword ptr [ESI],TScreenPanel::`vftable'          = 0047ba90
    //                              Pnl_scr.cpp:45 (4)
    //         0047ba7e     MOV        EAX,ESI
    //         0047ba80     POP        ESI
    //         0047ba81     RET
    //         0047ba82     ??         90h
    //         0047ba83     NOP
    //         0047ba84     NOP
    //         0047ba85     NOP
    //         0047ba86     NOP
    //         0047ba87     NOP
    //         0047ba88     NOP
    //         0047ba89     NOP
    //         0047ba8a     NOP
    //         0047ba8b     NOP
    //         0047ba8c     NOP
    //         0047ba8d     NOP
    //         0047ba8e     NOP
    //         0047ba8f     NOP
}

TScreenPanel::TScreenPanel(char* param_1) {
    /* TODO: Stub */
    //                              undefined __thiscall TScreenPanel(TScreenPanel * this, char * param_1)
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     0047bab0(R)  
    //                               ??0TScreenPanel@@QAE@PAD@Z                                   XREF[28]:    TribeAchievementsScreen:0048d55a(c
    //                               TScreenPanel::TScreenPanel                                                TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeJoinScreen:00491677(c), 
    //                                                                                                         TRIBE_Credits_Screen:00492707(c), 
    //                                                                                                         TRIBE_Screen_Game:00493d8a(c), 
    //                                                                                                         TRIBE_Screen_Info:0049d572(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049dd6a(
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e6fa(c)
    //                                                                                                         TRIBE_Screen_Main_Error:0049f0f4(c
    //                                                                                                         TribeMPSetupScreen:004a00da(c), 
    //                                                                                                         TRIBE_Screen_Wait:004a563a(c), 
    //                                                                                                         TribeSaveGameScreen:004a721a(c), 
    //                                                                                                         TRIBE_Screen_Sed:004a820a(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b2f15(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b33fa(c), 
    //                                                                                                         TribeSelectScenarioScreen:004b3cb5
    //                                                                                                         TribeGameSettingsScreen:004b48a6(c
    //                                                                                                         TribeSPMenuScreen:004b69c7(c), 
    //                                                                                                         TRIBE_Screen_Status_Message:004b71
    //                                                                                                         TRIBE_Screen_Status_Message:004b73
    //                                                                                                         [more]
    //                              Pnl_scr.cpp:52 (19)
    //         0047bab0     MOV        EAX,dword ptr [ESP + param_1]
    //         0047bab4     PUSH       ESI
    //         0047bab5     MOV        ESI,this
    //         0047bab7     PUSH       EAX
    //         0047bab8     CALL       TEasy_Panel::TEasy_Panel                         undefined TEasy_Panel(TEasy_Panel * this, cha
    //         0047babd     MOV        dword ptr [ESI],TScreenPanel::`vftable'          = 0047ba90
    //                              Pnl_scr.cpp:53 (6)
    //         0047bac3     MOV        EAX,ESI
    //         0047bac5     POP        ESI
    //         0047bac6     RET        0x4
    //         0047bac9     ??         90h
    //         0047baca     NOP
    //         0047bacb     NOP
    //         0047bacc     NOP
    //         0047bacd     NOP
    //         0047bace     NOP
    //         0047bacf     NOP
}

TScreenPanel::~TScreenPanel() {
    /* TODO: Stub */
    //                              void __thiscall ~TScreenPanel(TScreenPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //                               ??1TScreenPanel@@UAE@XZ                                      XREF[29]:    `vector_deleting_destructor':0047b
    //                               TScreenPanel::~TScreenPanel                                               ~TribeAchievementsScreen:0048e3e5(
    //                                                                                                         ~TRIBE_Screen_Campaign_Selection:0
    //                                                                                                         ~TribeJoinScreen:00491a5e(c), 
    //                                                                                                         ~TRIBE_Screen_Game:0049597f(c), 
    //                                                                                                         ~TribeLoadSavedGameScreen:0049e135
    //                                                                                                         ~TRIBE_Screen_Main_Menu:0049ecb4(c
    //                                                                                                         ~TRIBE_Screen_Main_Error:0049f28f(
    //                                                                                                         ~TribeMPStartupScreen:0049f97c(c), 
    //                                                                                                         ~TribeMPSetupScreen:004a1623(c), 
    //                                                                                                         ~TRIBE_Screen_Wait:004a60c8(c), 
    //                                                                                                         ~TRIBE_Screen_Disconnect:004a62d1(
    //                                                                                                         ~TRIBE_Screen_Name:004a67a4(c), 
    //                                                                                                         ~TribeSaveGameScreen:004a7655(c), 
    //                                                                                                         ~TRIBE_Screen_Sed_Menu:004b317a(c)
    //                                                                                                         ~TRIBE_Screen_Sed_Open:004b3727(c)
    //                                                                                                         ~TribeSelectScenarioScreen:004b425
    //                                                                                                         ~TribeGameSettingsScreen:004b5b92(
    //                                                                                                         ~TribeSPMenuScreen:004b6c6a(c), 
    //                                                                                                         ~TRIBE_Screen_Status_Message:004b7
    //                                                                                                         [more]
    //                              Pnl_scr.cpp:59 (11)
    //         0047bad0     MOV        dword ptr [this->field0_0x0],TScreenPanel::`vf   = 0047ba90
    //         0047bad6     JMP        TEasy_Panel::~TEasy_Panel                        void ~TEasy_Panel(TEasy_Panel * this)
    //                              -- Flow Override: CALL_RETURN (CALL_TERMINATOR)
    //         0047badb     ??         90h
    //         0047badc     NOP
    //         0047badd     NOP
    //         0047bade     NOP
    //         0047badf     NOP
}

long TScreenPanel::setup(TDrawArea* param_1, char* param_2, long param_3, int param_4) {
    /* TODO: Stub */
    //                              long __thiscall setup(TScreenPanel * this, TDrawArea * param_1, char
    //              long              EAX:4          <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047baf8(R)  
    //              char *            Stack[0x8]:4   param_2                   XREF[1]:     0047bae9(R)  
    //              long              Stack[0xc]:4   param_3                   XREF[1]:     0047bae4(R)  
    //              int               Stack[0x10]:4  param_4                   XREF[1]:     0047bae0(R)  
    //                               ?setup@TScreenPanel@@QAEJPAVTDrawArea@@PADJH@Z               XREF[24]:    setup_blank_screen:0041f79e(c), 
    //                               TScreenPanel::setup                                                       TribeAchievementsScreen:0048d716(c
    //                                                                                                         TRIBE_Campaign_Editor_Screen:0048f
    //                                                                                                         TRIBE_Screen_Campaign_Selection:00
    //                                                                                                         TribeJoinScreen:004916f3(c), 
    //                                                                                                         TRIBE_Credits_Screen:00492773(c), 
    //                                                                                                         TRIBE_Screen_Game:004940d5(c), 
    //                                                                                                         TRIBE_Screen_Info:0049d5b7(c), 
    //                                                                                                         TribeLoadSavedGameScreen:0049de1e(
    //                                                                                                         TRIBE_Screen_Main_Menu:0049e75f(c)
    //                                                                                                         TRIBE_Screen_Main_Error:0049f136(c
    //                                                                                                         TribeMPStartupScreen:0049f3ec(c), 
    //                                                                                                         TRIBE_Screen_Wait:004a5690(c), 
    //                                                                                                         TribeSaveGameScreen:004a7309(c), 
    //                                                                                                         TRIBE_Screen_Sed:004a839d(c), 
    //                                                                                                         TRIBE_Screen_Sed_Menu:004b2f67(c), 
    //                                                                                                         TRIBE_Screen_Sed_Open:004b34a4(c), 
    //                                                                                                         TribeSPMenuScreen:004b6a0e(c), 
    //                                                                                                         TRIBE_Screen_Status_Message:004b72
    //                                                                                                         TRIBE_Screen_Status_Message:004b74
    //                                                                                                         [more]
    //                              Pnl_scr.cpp:66 (43)
    //         0047bae0     MOV        EAX,dword ptr [ESP + param_4]
    //         0047bae4     MOV        EDX,dword ptr [ESP + param_3]
    //         0047bae8     PUSH       EAX
    //         0047bae9     MOV        EAX,dword ptr [ESP + param_2]
    //         0047baed     PUSH       0x0
    //         0047baef     PUSH       0x0
    //         0047baf1     PUSH       0x0
    //         0047baf3     PUSH       0x0
    //         0047baf5     PUSH       0x1
    //         0047baf7     PUSH       EDX
    //         0047baf8     MOV        EDX,dword ptr [ESP + param_1]
    //         0047bafc     PUSH       EAX
    //         0047bafd     PUSH       0x0
    //         0047baff     PUSH       EDX
    //         0047bb00     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
    //         0047bb05     NEG        EAX
    //         0047bb07     SBB        EAX,EAX
    //         0047bb09     NEG        EAX
    //                              Pnl_scr.cpp:71 (3)
    //         0047bb0b     RET        0x10
    //         0047bb0e     ??         90h
    //         0047bb0f     NOP
    return 0;
}

long TScreenPanel::setup(TDrawArea* param_1, char* param_2, long param_3, uchar param_4, int param_5) {
    /* TODO: Stub */
    //                              long __thiscall setup(TScreenPanel * this, TDrawArea * param_1, char
    //              long              EAX:4          <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //              TDrawArea *       Stack[0x4]:4   param_1                   XREF[1]:     0047bb14(R)  
    //              char *            Stack[0x8]:4   param_2
    //              long              Stack[0xc]:4   param_3
    //              uchar             Stack[0x10]:1  param_4
    //              int               Stack[0x14]:4  param_5                   XREF[1]:     0047bb10(R)  
    //                               ?setup@TScreenPanel@@QAEJPAVTDrawArea@@PADJEH@Z
    //                               TScreenPanel::setup
    //                              Pnl_scr.cpp:77 (37)
    //         0047bb10     MOV        EAX,dword ptr [ESP + param_5]
    //         0047bb14     MOV        EDX,dword ptr [ESP + param_1]
    //         0047bb18     PUSH       EAX
    //         0047bb19     PUSH       0x0
    //         0047bb1b     PUSH       0x0
    //         0047bb1d     PUSH       0x0
    //         0047bb1f     PUSH       0x0
    //         0047bb21     PUSH       0x1
    //         0047bb23     PUSH       -0x1
    //         0047bb25     PUSH       0x0
    //         0047bb27     PUSH       0x0
    //         0047bb29     PUSH       EDX
    //         0047bb2a     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
    //         0047bb2f     NEG        EAX
    //         0047bb31     SBB        EAX,EAX
    //         0047bb33     NEG        EAX
    //                              Pnl_scr.cpp:82 (3)
    //         0047bb35     RET        0x14
    //         0047bb38     ??         90h
    //         0047bb39     NOP
    //         0047bb3a     NOP
    //         0047bb3b     NOP
    //         0047bb3c     NOP
    //         0047bb3d     NOP
    //         0047bb3e     NOP
    //         0047bb3f     NOP
    return 0;
}

void TScreenPanel::draw() {
    /* TODO: Stub */
    //                              void __thiscall draw(TScreenPanel * this)
    //              void              <VOID>         <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //                               ?draw@TScreenPanel@@UAEXXZ                                   XREF[26]:    draw:0048f0b6(c), 
    //                               TScreenPanel::draw                                                        draw:00492d17(c), 
    //                                                                                                         draw:00492d37(c), 
    //                                                                                                         draw:004b88e3(c), 00571940(*), 
    //                                                                                                         005722d8(*), 00572400(*), 
    //                                                                                                         00572528(*), 005729b0(*), 
    //                                                                                                         00572d30(*), 00572e58(*), 
    //                                                                                                         00572f80(*), 005730a8(*), 
    //                                                                                                         005731d0(*), 005732f8(*), 
    //                                                                                                         00573420(*), 00573548(*), 
    //                                                                                                         00573670(*), 005738c8(*), 
    //                                                                                                         00573b30(*), [more]
    //                              Pnl_scr.cpp:88 (5)
    //         0047bb40     JMP        TEasy_Panel::draw
    //         0047bb45     ??         90h
    //         0047bb46     NOP
    //         0047bb47     NOP
    //         0047bb48     NOP
    //         0047bb49     NOP
    //         0047bb4a     NOP
    //         0047bb4b     NOP
    //         0047bb4c     NOP
    //         0047bb4d     NOP
    //         0047bb4e     NOP
    //         0047bb4f     NOP
    return;
}

long TScreenPanel::handle_paint() {
    /* TODO: Stub */
    //                              long __thiscall handle_paint(TScreenPanel * this)
    //              long              EAX:4          <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //                               ?handle_paint@TScreenPanel@@UAEJXZ                           XREF[26]:    00571964(*), 005721d4(*), 
    //                               TScreenPanel::handle_paint                                                005722fc(*), 00572424(*), 
    //                                                                                                         0057254c(*), 005727a4(*), 
    //                                                                                                         005729d4(*), 00572d54(*), 
    //                                                                                                         00572e7c(*), 00572fa4(*), 
    //                                                                                                         005730cc(*), 005731f4(*), 
    //                                                                                                         0057331c(*), 00573444(*), 
    //                                                                                                         0057356c(*), 00573694(*), 
    //                                                                                                         005738ec(*), 00573a14(*), 
    //                                                                                                         00573b54(*), 00573c7c(*), [more]
    //                              Pnl_scr.cpp:96 (5)
    //         0047bb50     CALL       TPanel::handle_paint                             long handle_paint(TPanel * this)
    //                              Pnl_scr.cpp:99 (2)
    //         0047bb55     XOR        EAX,EAX
    //                              Pnl_scr.cpp:100 (1)
    //         0047bb57     RET
    //         0047bb58     ??         90h
    //         0047bb59     NOP
    //         0047bb5a     NOP
    //         0047bb5b     NOP
    //         0047bb5c     NOP
    //         0047bb5d     NOP
    //         0047bb5e     NOP
    //         0047bb5f     NOP
    return 0;
}

void TScreenPanel::set_focus(int param_1) {
    /* TODO: Stub */
    //                              void __thiscall set_focus(TScreenPanel * this, int param_1)
    //              void              <VOID>         <RETURN>
    //              TScreenPanel *    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     0047bb71(R)  
    //              tagPALETTEENTR    Stack[-0x404   color_table               XREF[2,3]:   0047bb88(W), 0047bcbf(R), 0047bbd7(*), 0047bbe3(*), 
    //                                                                                     0047bc63(*)  
    //              int               Stack[-0x408   save_focus                XREF[3,2]:   0047bbc4(W), 0047bbf6(R), 0047bc2e(R), 0047bbcb(W), 
    //                                                                                     0047bbd0(W)  
    //              tagPALETTEENTRY   Stack[-0x40c   color
    //                               ?set_focus@TScreenPanel@@UAEXH@Z                             XREF[27]:    set_focus:0049d4b8(c), 
    //                               TScreenPanel::set_focus                                                   set_focus:004adc48(c), 
    //                                                                                                         005719d0(*), 00572240(*), 
    //                                                                                                         00572368(*), 00572490(*), 
    //                                                                                                         005725b8(*), 00572810(*), 
    //                                                                                                         00572a40(*), 00572dc0(*), 
    //                                                                                                         00572ee8(*), 00573010(*), 
    //                                                                                                         00573138(*), 00573260(*), 
    //                                                                                                         00573388(*), 005734b0(*), 
    //                                                                                                         005735d8(*), 00573700(*), 
    //                                                                                                         00573958(*), 00573bc0(*), [more]
    //                              Pnl_scr.cpp:106 (11)
    //         0047bb60     SUB        ESP,0x408
    //         0047bb66     PUSH       EBX
    //         0047bb67     PUSH       EBP
    //         0047bb68     PUSH       ESI
    //         0047bb69     MOV        ESI,this
    //                              Pnl_scr.cpp:109 (6)
    //         0047bb6b     MOV        this,dword ptr [last_screen]                     = 00000000
    //                              Pnl_scr.cpp:112 (77)
    //         0047bb71     MOV        EBP,dword ptr [ESP + param_1]
    //         0047bb78     MOV        EAX,dword ptr [ESI + 0x78]
    //         0047bb7b     XOR        EBX,EBX
    //         0047bb7d     CMP        ESI,this
    //         0047bb7f     MOV        this,dword ptr [ESI + 0x20]
    //         0047bb82     SETNZ      BL
    //         0047bb85     TEST       this,this
    //         0047bb87     PUSH       EDI
    //         0047bb88     MOV        dword ptr [ESP + color_table[0].peRed],EAX
    //         0047bb8c     JZ         LAB_0047bc2e
    //         0047bb92     MOV        EAX,dword ptr [this->field0_0x0]
    //         0047bb94     TEST       EAX,EAX
    //         0047bb96     JZ         LAB_0047bc2e
    //         0047bb9c     TEST       EBP,EBP
    //         0047bb9e     JZ         LAB_0047bc2e
    //         0047bba4     TEST       BL,BL
    //         0047bba6     JZ         LAB_0047bc2e
    //         0047bbac     CMP        byte ptr [EAX + 0x479],0x2
    //         0047bbb3     JZ         LAB_0047bbbe
    //         0047bbb5     CMP        byte ptr [EAX + 0x478],0x1
    //         0047bbbc     JNZ        LAB_0047bc2e
    //                               LAB_0047bbbe                                                 XREF[1]:     0047bbb3(j)  
    //                              Pnl_scr.cpp:117 (25)
    //         0047bbbe     MOV        EAX,dword ptr [ESI + 0x20c]
    //         0047bbc4     MOV        byte ptr [ESP + save_focus],0x0
    //         0047bbc9     TEST       EAX,EAX
    //         0047bbcb     MOV        byte ptr [ESP + save_focus+0x1],0x0
    //         0047bbd0     MOV        byte ptr [ESP + save_focus+0x2],0x0
    //         0047bbd5     JNZ        LAB_0047bbe3
    //                              Pnl_scr.cpp:118 (10)
    //         0047bbd7     LEA        EDX=>color_table[1],[ESP + 0x18]
    //         0047bbdb     PUSH       EDX
    //         0047bbdc     CALL       TDrawArea::GetPalette                            void GetPalette(TDrawArea * this, tagPALETTEE
    //                              Pnl_scr.cpp:119 (2)
    //         0047bbe1     JMP        LAB_0047bbf6
    //                               LAB_0047bbe3                                                 XREF[1]:     0047bbd5(j)  
    //                              Pnl_scr.cpp:120 (19)
    //         0047bbe3     LEA        this=>color_table[1],[ESP + 0x18]
    //         0047bbe7     PUSH       this
    //         0047bbe8     PUSH       0x100
    //         0047bbed     PUSH       0x0
    //         0047bbef     PUSH       EAX
    //         0047bbf0     CALL       dword ptr [->GDI32.DLL::GetPaletteEntries]       = 0048b270
    //                               LAB_0047bbf6                                                 XREF[1]:     0047bbe1(j)  
    //                              Pnl_scr.cpp:123 (27)
    //         0047bbf6     MOV        EDI,dword ptr [ESP + save_focus]
    //         0047bbfa     MOV        EDX,dword ptr [ESI + 0x20]
    //         0047bbfd     PUSH       -0x1
    //         0047bbff     PUSH       -0x1
    //         0047bc01     PUSH       0x0
    //         0047bc03     PUSH       0x1
    //         0047bc05     PUSH       0x3e051eb8
    //         0047bc0a     PUSH       EDI
    //         0047bc0b     PUSH       EDX
    //         0047bc0c     CALL       RGE_fade_palette                                 void RGE_fade_palette(TDrawArea * param_1, ta
    //                              Pnl_scr.cpp:124 (15)
    //         0047bc11     MOV        this,dword ptr [ESI + 0x20]
    //         0047bc14     ADD        ESP,0x1c
    //         0047bc17     PUSH       0x0
    //         0047bc19     PUSH       0x0
    //         0047bc1b     CALL       TDrawArea::Clear                                 void Clear(TDrawArea * this, tagRECT * param_
    //                              Pnl_scr.cpp:125 (18)
    //         0047bc20     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047bc23     PUSH       0x0
    //         0047bc25     MOV        this,dword ptr [EAX]
    //         0047bc27     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
    //         0047bc2c     JMP        LAB_0047bc32
    //                               LAB_0047bc2e                                                 XREF[5]:     0047bb8c(j), 0047bb96(j), 
    //                                                                                                         0047bb9e(j), 0047bba6(j), 
    //                                                                                                         0047bbbc(j)  
    //         0047bc2e     MOV        EDI,dword ptr [ESP + save_focus]
    //                               LAB_0047bc32                                                 XREF[1]:     0047bc2c(j)  
    //                              Pnl_scr.cpp:128 (8)
    //         0047bc32     PUSH       EBP
    //         0047bc33     MOV        this,ESI
    //         0047bc35     CALL       TEasy_Panel::set_focus                           void set_focus(TEasy_Panel * this, int param_1)
    //                              Pnl_scr.cpp:130 (39)
    //         0047bc3a     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047bc3d     TEST       EAX,EAX
    //         0047bc3f     JZ         LAB_0047bcbf
    //         0047bc41     MOV        this,dword ptr [EAX]
    //         0047bc43     TEST       this,this
    //         0047bc45     JZ         LAB_0047bcbf
    //         0047bc47     TEST       EBP,EBP
    //         0047bc49     JZ         LAB_0047bcbf
    //         0047bc4b     TEST       BL,BL
    //         0047bc4d     JZ         LAB_0047bcbf
    //         0047bc4f     CMP        byte ptr [this->field0_0x0 + 0x479],0x2
    //         0047bc56     JZ         LAB_0047bc61
    //         0047bc58     CMP        byte ptr [ECX + this+0x478],0x1
    //         0047bc5f     JNZ        LAB_0047bcbf
    //                               LAB_0047bc61                                                 XREF[1]:     0047bc56(j)  
    //                              Pnl_scr.cpp:132 (20)
    //         0047bc61     PUSH       -0x1
    //         0047bc63     LEA        this=>color_table[1],[ESP + 0x1c]
    //         0047bc67     PUSH       -0x1
    //         0047bc69     PUSH       this
    //         0047bc6a     PUSH       0x2
    //         0047bc6c     PUSH       0x0
    //         0047bc6e     PUSH       EDI
    //         0047bc6f     PUSH       EAX
    //         0047bc70     CALL       RGE_fade_palette                                 void RGE_fade_palette(TDrawArea * param_1, ta
    //                              Pnl_scr.cpp:133 (10)
    //         0047bc75     MOV        EDX,dword ptr [ESI]
    //         0047bc77     ADD        ESP,0x1c
    //         0047bc7a     MOV        this,ESI
    //         0047bc7c     CALL       dword ptr [EDX + 0x54]
    //                              Pnl_scr.cpp:136 (20)
    //         0047bc7f     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047bc82     PUSH       -0x1
    //         0047bc84     PUSH       offset DAT_fffffff8
    //         0047bc86     PUSH       0x0=>DAT_fffffff4
    //         0047bc88     PUSH       offset DAT_fffffff0
    //         0047bc8a     PUSH       0x0
    //         0047bc8c     PUSH       EDI
    //         0047bc8d     PUSH       EAX
    //         0047bc8e     CALL       RGE_fade_palette                                 void RGE_fade_palette(TDrawArea * param_1, ta
    //                              Pnl_scr.cpp:137 (15)
    //         0047bc93     MOV        this,dword ptr [ESI + 0x20]
    //         0047bc96     ADD        ESP,0x1c
    //         0047bc99     MOV        this,dword ptr [this->field0_0x0]
    //         0047bc9b     PUSH       0x0
    //         0047bc9d     CALL       TDrawSystem::Paint                               void Paint(TDrawSystem * this, tagRECT * para
    //                              Pnl_scr.cpp:140 (29)
    //         0047bca2     MOV        EAX,dword ptr [ESI + 0x20]
    //         0047bca5     PUSH       -0x1
    //         0047bca7     LEA        EDX,[ESP + 0x1c]
    //         0047bcab     PUSH       offset DAT_fffffff8
    //         0047bcad     PUSH       EDX=>DAT_fffffff4
    //         0047bcae     PUSH       offset DAT_fffffff0
    //         0047bcb0     PUSH       0x3e051eb8
    //         0047bcb5     PUSH       EDI
    //         0047bcb6     PUSH       EAX
    //         0047bcb7     CALL       RGE_fade_palette                                 void RGE_fade_palette(TDrawArea * param_1, ta
    //         0047bcbc     ADD        ESP,0x1c
    //                               LAB_0047bcbf                                                 XREF[5]:     0047bc3f(j), 0047bc45(j), 
    //                                                                                                         0047bc49(j), 0047bc4d(j), 
    //                                                                                                         0047bc5f(j)  
    //                              Pnl_scr.cpp:143 (13)
    //         0047bcbf     CMP        EBP,dword ptr [ESP + color_table[0].peRed]
    //         0047bcc3     JZ         LAB_0047bcd2
    //         0047bcc5     MOV        EAX,dword ptr [ESI + 0x78]
    //         0047bcc8     TEST       EAX,EAX
    //         0047bcca     JZ         LAB_0047bcd2
    //                              Pnl_scr.cpp:144 (6)
    //         0047bccc     MOV        dword ptr [last_screen],ESI                      = 00000000
    //                               LAB_0047bcd2                                                 XREF[2]:     0047bcc3(j), 0047bcca(j)  
    //                              Pnl_scr.cpp:145 (13)
    //         0047bcd2     POP        EDI
    //         0047bcd3     POP        ESI
    //         0047bcd4     POP        EBP
    //         0047bcd5     POP        EBX
    //         0047bcd6     ADD        ESP,0x408
    //         0047bcdc     RET        0x4
    //         0047bcdf     ??         90h
    return;
}

