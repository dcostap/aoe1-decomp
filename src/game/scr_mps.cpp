#include "../common.h"
#include "scr_mps.h"

TribeMPSetupScreen::TribeMPSetupScreen() {
    /* TODO: Stub */
//                              undefined __thiscall TribeMPSetupScreen(TribeMPSetupScreen * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a00f0(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a0d3d(R)
//              char[256]         Stack[-0x110   str                       XREF[1,2]:   004a00d6(W), 004a05e9(*), 004a05fe(*)
//              undefined4        Stack[-0x114   local_114                 XREF[2]:     004a0613(W), 004a061c(R)
//              undefined4        Stack[-0x118   local_118                 XREF[4]:     004a0306(W), 004a0314(R), 004a0533(R), 004a0625(R)
//                               ??0TribeMPSetupScreen@@QAE@XZ                                XREF[6]:     handle_user_command:00491b87(c),
//                               TribeMPSetupScreen::TribeMPSetupScreen                                    action:004925ce(c),
//                                                                                                         action:004b436c(c),
//                                                                                                         action:004b6dd9(c),
//                                                                                                         setup:00521be3(c),
//                                                                                                         setup:00521eb8(c)
//                              scr_mps.cpp:203 (53)
//         004a00b0     PUSH       -0x1
//         004a00b2     PUSH       FUN_0055f19b
//         004a00b7     MOV        EAX,FS:[0x0]
//         004a00bd     PUSH       EAX
//         004a00be     MOV        dword ptr FS:[0x0],ESP
//         004a00c5     SUB        ESP,0x10c
//         004a00cb     PUSH       EBX
//         004a00cc     PUSH       EBP
//         004a00cd     PUSH       ESI
//         004a00ce     PUSH       EDI
//         004a00cf     MOV        EDI,this
//         004a00d1     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
//         004a00d6     MOV        dword ptr [ESP + str[0]],EDI
//         004a00da     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//         004a00df     MOV        dword ptr [EDI],TribeMPSetupScreen::`vftable'    = 004a0d60
//                              scr_mps.cpp:207 (30)
//         004a00e5     MOV        EAX,[L]                                          = 00000000
//         004a00ea     PUSH       s_$$$_CHAT_SCREEN:_CONSTRUCTOR_BEG               = "$$$ CHAT SCREEN: CONSTRUCTOR BEGIN"
//         004a00ef     PUSH       EAX
//         004a00f0     MOV        dword ptr [ESP + local_4],0x0
//         004a00fb     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a0100     ADD        ESP,0x8
//                              scr_mps.cpp:210 (7)
//         004a0103     MOV        this,EDI
//         004a0105     CALL       TribeMPSetupScreen::init_vars                    void init_vars(TribeMPSetupScreen * this)
//                              scr_mps.cpp:213 (11)
//         004a010a     MOV        this,dword ptr [chat]                            = 00000000
//         004a0110     CALL       TChat::ClearChat                                 void ClearChat(TChat * this)
//                              scr_mps.cpp:214 (5)
//         004a0115     MOV        ESI,0x1
//                               LAB_004a011a                                                 XREF[1]:     004a012c(j)
//                              scr_mps.cpp:215 (20)
//         004a011a     MOV        this,dword ptr [chat]                            = 00000000
//         004a0120     PUSH       0x1
//         004a0122     PUSH       ESI
//         004a0123     CALL       TChat::setInChatGroup                            void setInChatGroup(TChat * this, int param_1
//         004a0128     INC        ESI
//         004a0129     CMP        ESI,0x9
//         004a012c     JL         LAB_004a011a
//                              scr_mps.cpp:218 (78)
//         004a012e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0134     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a0139     TEST       EAX,EAX
//         004a013b     MOV        EBX,s_scr3                                       = 73h
//         004a0140     JNZ        LAB_004a0147
//         004a0142     MOV        EBX,s_scr2                                       = 73h
//                               LAB_004a0147                                                 XREF[1]:     004a0140(j)
//         004a0147     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a014d     PUSH       0x1
//         004a014f     PUSH       0x0
//         004a0151     PUSH       0x0
//         004a0153     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004a0156     PUSH       0x0
//         004a0158     PUSH       0x0
//         004a015a     PUSH       0x1
//         004a015c     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a0161     NEG        EAX
//         004a0163     SBB        EAX,EAX
//         004a0165     MOV        this,EDI
//         004a0167     NEG        EAX
//         004a0169     ADD        EAX,0xc384
//         004a016e     PUSH       EAX
//         004a016f     PUSH       EBX=>s_scr2                                      = 73h
//         004a0170     PUSH       0x0
//         004a0172     PUSH       ESI
//         004a0173     CALL       TEasy_Panel::setup                               long setup(TEasy_Panel * this, TDrawArea * pa
//         004a0178     TEST       EAX,EAX
//         004a017a     JNZ        LAB_004a018b
//                              scr_mps.cpp:220 (10)
//         004a017c     MOV        dword ptr [EDI + 0xd8],0x1
//                              scr_mps.cpp:221 (5)
//         004a0186     JMP        LAB_004a0d3d
//                               LAB_004a018b                                                 XREF[1]:     004a017a(j)
//                              scr_mps.cpp:224 (9)
//         004a018b     PUSH       0x0
//         004a018d     MOV        this,EDI
//         004a018f     CALL       TEasy_Panel::setup_shadow_area                   void setup_shadow_area(TEasy_Panel * this, in
//                              scr_mps.cpp:225 (17)
//         004a0194     PUSH       0x1e0
//         004a0199     PUSH       0x280
//         004a019e     MOV        this,EDI
//         004a01a0     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_mps.cpp:230 (63)
//         004a01a5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a01ab     PUSH       0x0
//         004a01ad     PUSH       0x0
//         004a01af     PUSH       0x1
//         004a01b1     PUSH       0x1
//         004a01b3     PUSH       0x1e
//         004a01b5     PUSH       0x258
//         004a01ba     PUSH       0x6
//         004a01bc     PUSH       0x14
//         004a01be     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a01c3     NEG        EAX
//         004a01c5     SBB        EAX,EAX
//         004a01c7     LEA        this,[EDI + 0x478]
//         004a01cd     ADD        EAX,0x25cf
//         004a01d2     PUSH       EAX
//         004a01d3     PUSH       this
//         004a01d4     PUSH       EDI
//         004a01d5     MOV        this,EDI
//         004a01d7     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a01dc     TEST       EAX,EAX
//         004a01de     JZ         LAB_004a0d3d
//                              scr_mps.cpp:231 (47)
//         004a01e4     PUSH       0x0
//         004a01e6     PUSH       0x1
//         004a01e8     PUSH       0x0
//         004a01ea     PUSH       0x0
//         004a01ec     PUSH       0x1e
//         004a01ee     PUSH       0xa0
//         004a01f3     PUSH       0x32
//         004a01f5     PUSH       0x1a
//         004a01f7     LEA        EDX,[EDI + 0x47c]
//                              language.dll match for 0x25d0: "Name"
//         004a01fd     PUSH       0x25d0
//         004a0202     PUSH       EDX
//         004a0203     PUSH       EDI
//         004a0204     MOV        this,EDI
//         004a0206     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a020b     TEST       EAX,EAX
//         004a020d     JZ         LAB_004a0d3d
//                              scr_mps.cpp:232 (50)
//         004a0213     PUSH       0x0
//         004a0215     PUSH       0x1
//         004a0217     PUSH       0x0
//         004a0219     PUSH       0x0
//         004a021b     PUSH       0x1e
//         004a021d     PUSH       0xa0
//         004a0222     PUSH       0x32
//         004a0224     PUSH       0xbd
//         004a0229     LEA        EAX,[EDI + 0x480]
//                              language.dll match for 0x25d1: "Civ"
//         004a022f     PUSH       0x25d1
//         004a0234     PUSH       EAX
//         004a0235     PUSH       EDI
//         004a0236     MOV        this,EDI
//         004a0238     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a023d     TEST       EAX,EAX
//         004a023f     JZ         LAB_004a0d3d
//                              scr_mps.cpp:234 (30)
//         004a0245     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a024b     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a0250     TEST       EAX,EAX
//         004a0252     JNZ        LAB_004a0292
//         004a0254     MOV        this,dword ptr [comm]                            = 00000000
//         004a025a     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a025f     TEST       EAX,EAX
//         004a0261     JNZ        LAB_004a0292
//                              scr_mps.cpp:236 (47)
//         004a0263     PUSH       EAX
//         004a0264     PUSH       0x1
//         004a0266     PUSH       EAX
//         004a0267     PUSH       EAX
//         004a0268     PUSH       0x1e
//         004a026a     PUSH       0xd2
//         004a026f     PUSH       0x32
//         004a0271     PUSH       0x1a4
//         004a0276     LEA        this,[EDI + 0x484]
//                              language.dll match for 0x25d2: "Settings"
//         004a027c     PUSH       0x25d2
//         004a0281     PUSH       this
//         004a0282     PUSH       EDI
//         004a0283     MOV        this,EDI
//         004a0285     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a028a     TEST       EAX,EAX
//         004a028c     JZ         LAB_004a0d3d
//                               LAB_004a0292                                                 XREF[2]:     004a0252(j), 004a0261(j)
//                              scr_mps.cpp:239 (47)
//         004a0292     PUSH       0x0
//         004a0294     PUSH       0x1
//         004a0296     PUSH       0x0
//         004a0298     PUSH       0x0
//         004a029a     PUSH       0x1e
//         004a029c     PUSH       0x64
//         004a029e     PUSH       0x32
//         004a02a0     LEA        ESI,[EDI + 0x488]
//         004a02a6     PUSH       0xf0
//                              language.dll match for 0x25ae: "Player"
//         004a02ab     PUSH       0x25ae
//         004a02b0     PUSH       ESI
//         004a02b1     PUSH       EDI
//         004a02b2     MOV        this,EDI
//         004a02b4     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a02b9     TEST       EAX,EAX
//         004a02bb     JZ         LAB_004a0d3d
//                              scr_mps.cpp:240 (11)
//         004a02c1     MOV        this,dword ptr [ESI]
//         004a02c3     PUSH       0x2
//         004a02c5     PUSH       0x0
//         004a02c7     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
//                              scr_mps.cpp:242 (47)
//         004a02cc     PUSH       0x0
//         004a02ce     PUSH       0x1
//         004a02d0     PUSH       0x0
//         004a02d2     PUSH       0x0
//         004a02d4     PUSH       0x1e
//         004a02d6     PUSH       0x64
//         004a02d8     PUSH       0x32
//         004a02da     LEA        ESI,[EDI + 0x48c]
//         004a02e0     PUSH       0x136
//                              language.dll match for 0x25af: "Team"
//         004a02e5     PUSH       0x25af
//         004a02ea     PUSH       ESI
//         004a02eb     PUSH       EDI
//         004a02ec     MOV        this,EDI
//         004a02ee     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a02f3     TEST       EAX,EAX
//         004a02f5     JZ         LAB_004a0d3d
//                              scr_mps.cpp:243 (25)
//         004a02fb     MOV        this,dword ptr [ESI]
//         004a02fd     PUSH       0x2
//         004a02ff     PUSH       0x0
//         004a0301     CALL       TTextPanel::set_alignment                        void set_alignment(TTextPanel * this, Alignme
//         004a0306     MOV        dword ptr [ESP + local_118],0x55
//         004a030e     LEA        ESI,[EDI + 0x5d0]
//                               LAB_004a0314                                                 XREF[1]:     004a0760(j)
//                              scr_mps.cpp:246 (4)
//         004a0314     MOV        EDX,dword ptr [ESP + local_118]
//                              scr_mps.cpp:248 (42)
//         004a0318     PUSH       0xb
//         004a031a     PUSH       offset DAT_fffffff8
//         004a031c     PUSH       offset DAT_fffffff4
//         004a0321     LEA        EBP,[EDX + -0x1]
//         004a0324     LEA        EBX,[ESI + -0x20]
//         004a0327     PUSH       EBP=>DAT_fffffff0
//         004a0328     PUSH       0x7
//         004a032a     PUSH       0x64
//         004a032c     PUSH       0x9e
//         004a0331     PUSH       EBX
//         004a0332     PUSH       EDI
//         004a0333     MOV        this,EDI
//         004a0335     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
//         004a033a     TEST       EAX,EAX
//         004a033c     JZ         LAB_004a0d3d
//                              scr_mps.cpp:249 (9)
//         004a0342     MOV        this,dword ptr [EBX]
//         004a0344     PUSH       0x1
//         004a0346     CALL       TDropDownPanel::set_draw_style                   void set_draw_style(TDropDownPanel * this, Dr
//                              scr_mps.cpp:250 (9)
//         004a034b     MOV        this,dword ptr [EBX]
//         004a034d     PUSH       0x0
//         004a034f     CALL       TDropDownPanel::set_draw_val_rect                void set_draw_val_rect(TDropDownPanel * this,
//                              scr_mps.cpp:251 (14)
//         004a0354     MOV        this,dword ptr [EBX]
//         004a0356     PUSH       -0x1
//                              language.dll match for 0x75f9: "To limit a game to less than
//         004a0358     PUSH       0x75f9
//         004a035d     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:253 (7)
//         004a0362     MOV        this,dword ptr [EBX]
//         004a0364     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_mps.cpp:255 (11)
//         004a0369     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a036f     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//                              scr_mps.cpp:257 (18)
//         004a0374     MOV        this,dword ptr [EBX]
//         004a0376     PUSH       0x4
//         004a0378     TEST       EAX,EAX
//                              language.dll match for 0x25d3: "Computer"
//         004a037a     PUSH       0x25d3
//         004a037f     JZ         LAB_004a039d
//         004a0381     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:258 (14)
//         004a0386     MOV        this,dword ptr [EBX]
//         004a0388     PUSH       0x1
//                              language.dll match for 0x25d4: "Closed"
//         004a038a     PUSH       0x25d4
//         004a038f     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:259 (7)
//         004a0394     PUSH       0x0
//                              language.dll match for 0x25d5: "Open"
//         004a0396     PUSH       0x25d5
//                              scr_mps.cpp:261 (2)
//         004a039b     JMP        LAB_004a03a9
//                               LAB_004a039d                                                 XREF[1]:     004a037f(j)
//                              scr_mps.cpp:263 (5)
//         004a039d     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:264 (14)
//         004a03a2     PUSH       0x0
//                              language.dll match for 0x25d6: "None"
//         004a03a4     PUSH       0x25d6
//                               LAB_004a03a9                                                 XREF[1]:     004a039b(j)
//         004a03a9     MOV        this,dword ptr [EBX]
//         004a03ab     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:267 (39)
//         004a03b0     PUSH       0xb
//         004a03b2     PUSH       0x18
//         004a03b4     PUSH       0x80
//         004a03b9     PUSH       EBP
//         004a03ba     PUSH       0xaa
//         004a03bf     PUSH       0x64
//                              language.dll match for 0x80: "Arial"
//         004a03c1     PUSH       0x80
//         004a03c6     PUSH       ESI
//         004a03c7     PUSH       EDI
//         004a03c8     MOV        this,EDI
//         004a03ca     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
//         004a03cf     TEST       EAX,EAX
//         004a03d1     JZ         LAB_004a0d3d
//                              scr_mps.cpp:268 (9)
//         004a03d7     MOV        this,dword ptr [ESI]
//         004a03d9     PUSH       0x1
//         004a03db     CALL       TDropDownPanel::set_draw_style                   void set_draw_style(TDropDownPanel * this, Dr
//                              scr_mps.cpp:269 (9)
//         004a03e0     MOV        this,dword ptr [ESI]
//         004a03e2     PUSH       0x0
//         004a03e4     CALL       TDropDownPanel::set_draw_val_rect                void set_draw_val_rect(TDropDownPanel * this,
//                              scr_mps.cpp:270 (17)
//         004a03e9     MOV        this,dword ptr [ESI]
//         004a03eb     PUSH       0x25f09
//                              language.dll match for 0x75fa: "Click to select a civilizatio
//                              language.dll match for 0x75fa: "Click to select a civilizatio
//         004a03f0     PUSH       0x75fa
//         004a03f5     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:272 (7)
//         004a03fa     MOV        this,dword ptr [ESI]
//         004a03fc     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_mps.cpp:273 (14)
//         004a0401     MOV        this,dword ptr [ESI]
//         004a0403     PUSH       0x1
//                              language.dll match for 0x27f7: "Egyptian"
//         004a0405     PUSH       0x27f7
//         004a040a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:274 (14)
//         004a040f     MOV        this,dword ptr [ESI]
//         004a0411     PUSH       0x2
//                              language.dll match for 0x27f8: "Greek"
//         004a0413     PUSH       0x27f8
//         004a0418     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:275 (14)
//         004a041d     MOV        this,dword ptr [ESI]
//         004a041f     PUSH       0x3
//                              language.dll match for 0x27f9: "Babylonian"
//         004a0421     PUSH       0x27f9
//         004a0426     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:276 (14)
//         004a042b     MOV        this,dword ptr [ESI]
//         004a042d     PUSH       0x4
//                              language.dll match for 0x27fa: "Assyrian"
//         004a042f     PUSH       0x27fa
//         004a0434     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:277 (14)
//         004a0439     MOV        this,dword ptr [ESI]
//         004a043b     PUSH       0x5
//                              language.dll match for 0x27fb: "Minoan"
//         004a043d     PUSH       0x27fb
//         004a0442     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:278 (14)
//         004a0447     MOV        this,dword ptr [ESI]
//         004a0449     PUSH       0x6
//                              language.dll match for 0x27fc: "Hittite"
//         004a044b     PUSH       0x27fc
//         004a0450     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:279 (14)
//         004a0455     MOV        this,dword ptr [ESI]
//         004a0457     PUSH       0x7
//                              language.dll match for 0x27fd: "Phoenician"
//         004a0459     PUSH       0x27fd
//         004a045e     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:280 (14)
//         004a0463     MOV        this,dword ptr [ESI]
//         004a0465     PUSH       0x8
//                              language.dll match for 0x27fe: "Sumerian"
//         004a0467     PUSH       0x27fe
//         004a046c     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:281 (14)
//         004a0471     MOV        this,dword ptr [ESI]
//         004a0473     PUSH       0x9
//                              language.dll match for 0x27ff: "Persian"
//         004a0475     PUSH       0x27ff
//         004a047a     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:282 (14)
//         004a047f     MOV        this,dword ptr [ESI]
//         004a0481     PUSH       0xa
//                              language.dll match for 0x2800: "Shang"
//         004a0483     PUSH       0x2800
//         004a0488     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:283 (14)
//         004a048d     MOV        this,dword ptr [ESI]
//         004a048f     PUSH       0xb
//                              language.dll match for 0x2801: "Yamato"
//         004a0491     PUSH       0x2801
//         004a0496     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:284 (14)
//         004a049b     MOV        this,dword ptr [ESI]
//         004a049d     PUSH       0xc
//                              language.dll match for 0x2802: "Choson"
//         004a049f     PUSH       0x2802
//         004a04a4     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:285 (14)
//         004a04a9     MOV        this,dword ptr [ESI]
//         004a04ab     PUSH       0xd
//                              language.dll match for 0x2806: "Roman"
//         004a04ad     PUSH       0x2806
//         004a04b2     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:286 (14)
//         004a04b7     MOV        this,dword ptr [ESI]
//         004a04b9     PUSH       0xe
//                              language.dll match for 0x2807: "Carthaginian"
//         004a04bb     PUSH       0x2807
//         004a04c0     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:287 (14)
//         004a04c5     MOV        this,dword ptr [ESI]
//         004a04c7     PUSH       0xf
//                              language.dll match for 0x2809: "Palmyran"
//         004a04c9     PUSH       0x2809
//         004a04ce     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:288 (14)
//         004a04d3     MOV        this,dword ptr [ESI]
//         004a04d5     PUSH       0x10
//                              language.dll match for 0x2808: "Macedonian"
//         004a04d7     PUSH       0x2808
//         004a04dc     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//                              scr_mps.cpp:289 (17)
//         004a04e1     MOV        this,dword ptr [ESI]
//         004a04e3     PUSH       0x11
//                              language.dll match for 0x280a: "Random"
//         004a04e5     PUSH       0x280a
//         004a04ea     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, long p
//         004a04ef     LEA        EBX,[ESI + 0x20]
//                              scr_mps.cpp:292 (33)
//         004a04f2     PUSH       0xb
//         004a04f4     PUSH       0x18
//         004a04f6     PUSH       0x28
//         004a04f8     PUSH       EBP
//         004a04f9     PUSH       0x144
//         004a04fe     PUSH       0x64
//         004a0500     PUSH       0x28
//         004a0502     PUSH       EBX
//         004a0503     PUSH       EDI
//         004a0504     MOV        this,EDI
//         004a0506     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
//         004a050b     TEST       EAX,EAX
//         004a050d     JZ         LAB_004a0d3d
//                              scr_mps.cpp:293 (9)
//         004a0513     MOV        this,dword ptr [EBX]
//         004a0515     PUSH       0x1
//         004a0517     CALL       TDropDownPanel::set_draw_style                   void set_draw_style(TDropDownPanel * this, Dr
//                              scr_mps.cpp:294 (9)
//         004a051c     MOV        this,dword ptr [EBX]
//         004a051e     PUSH       0x0
//         004a0520     CALL       TDropDownPanel::set_draw_val_rect                void set_draw_val_rect(TDropDownPanel * this,
//                              scr_mps.cpp:295 (14)
//         004a0525     MOV        this,dword ptr [EBX]
//         004a0527     PUSH       -0x1
//         004a0529     PUSH       0x75fb
//         004a052e     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:298 (47)
//         004a0533     MOV        EBX,dword ptr [ESP + local_118]
//         004a0537     PUSH       0x1
//         004a0539     PUSH       0x0
//         004a053b     PUSH       0xb
//         004a053d     PUSH       0x14
//         004a053f     PUSH       0x1e
//         004a0541     PUSH       EBX
//         004a0542     PUSH       0x136
//         004a0547     LEA        EBP,[ESI + -0x60]
//         004a054a     PUSH       0x0
//         004a054c     PUSH       s_                                               = ""
//         004a0551     PUSH       EBP
//         004a0552     PUSH       EDI
//         004a0553     MOV        this,EDI
//         004a0555     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a055a     TEST       EAX,EAX
//         004a055c     JZ         LAB_004a0d3d
//                              scr_mps.cpp:299 (15)
//         004a0562     MOV        this,dword ptr [EBP]
//         004a0565     PUSH       -0x1
//                              language.dll match for 0x7604: "Click to select your starting
//         004a0567     PUSH       0x7604
//         004a056c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:300 (46)
//         004a0571     PUSH       0x0
//         004a0573     PUSH       0x1
//         004a0575     PUSH       0x1
//         004a0577     PUSH       0xb
//         004a0579     PUSH       0x16
//         004a057b     PUSH       0x28
//         004a057d     PUSH       EBX
//         004a057e     PUSH       0x131
//         004a0583     LEA        EAX,[ESI + 0xffffff60]
//         004a0589     PUSH       s_                                               = ""
//         004a058e     PUSH       EAX
//         004a058f     PUSH       EDI
//         004a0590     MOV        this,EDI
//         004a0592     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a0597     TEST       EAX,EAX
//         004a0599     JZ         LAB_004a0d3d
//                              scr_mps.cpp:305 (43)
//         004a059f     PUSH       0x1
//         004a05a1     PUSH       0x0
//         004a05a3     PUSH       0xb
//         004a05a5     PUSH       0x14
//         004a05a7     PUSH       0x1e
//         004a05a9     PUSH       EBX
//         004a05aa     PUSH       0x17c
//         004a05af     LEA        EBP,[ESI + -0x40]
//         004a05b2     PUSH       0x0
//                              language.dll match for 0x25b0: "-"
//         004a05b4     PUSH       0x25b0
//         004a05b9     PUSH       EBP
//         004a05ba     PUSH       EDI
//         004a05bb     MOV        this,EDI
//         004a05bd     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a05c2     TEST       EAX,EAX
//         004a05c4     JZ         LAB_004a0d3d
//                              scr_mps.cpp:306 (15)
//         004a05ca     MOV        this,dword ptr [EBP]
//         004a05cd     PUSH       -0x1
//                              language.dll match for 0x7603: "Click to select a team if you
//         004a05cf     PUSH       0x7603
//         004a05d4     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:307 (10)
//         004a05d9     MOV        this,dword ptr [EBP]
//         004a05dc     PUSH       0x5
//         004a05de     CALL       TButtonPanel::set_state_info                     void set_state_info(TButtonPanel * this, shor
//                              scr_mps.cpp:308 (5)
//         004a05e3     MOV        EBX,0x1
//                               LAB_004a05e8                                                 XREF[1]:     004a0623(j)
//                              scr_mps.cpp:310 (16)
//         004a05e8     PUSH       EBX
//         004a05e9     LEA        this=>str[4],[ESP + 0x20]
//         004a05ed     PUSH       s_%d                                             = 6425h
//         004a05f2     PUSH       this
//         004a05f3     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:311 (17)
//         004a05f8     MOV        this,dword ptr [EBP]
//         004a05fb     ADD        ESP,0xc
//         004a05fe     LEA        EDX=>str[4],[ESP + 0x1c]
//         004a0602     PUSH       EDX
//         004a0603     PUSH       EBX
//         004a0604     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              scr_mps.cpp:312 (28)
//         004a0609     MOV        this,dword ptr [EBP]
//         004a060c     LEA        EAX,[EBX + 0x1]
//         004a060f     PUSH       0x0
//         004a0611     PUSH       EAX
//         004a0612     PUSH       EBX
//         004a0613     MOV        dword ptr [ESP + local_114],EAX
//         004a0617     CALL       TButtonPanel::set_id                             void set_id(TButtonPanel * this, short param_
//         004a061c     MOV        EBX,dword ptr [ESP + local_114]
//         004a0620     CMP        EBX,0x5
//         004a0623     JL         LAB_004a05e8
//                              scr_mps.cpp:314 (47)
//         004a0625     MOV        EBP,dword ptr [ESP + local_118]
//         004a0629     PUSH       0x0
//         004a062b     PUSH       0x1
//         004a062d     PUSH       0x1
//         004a062f     PUSH       0xb
//         004a0631     PUSH       0x16
//         004a0633     PUSH       0x28
//         004a0635     PUSH       EBP
//         004a0636     PUSH       0x177
//         004a063b     LEA        EAX,[ESI + -0x80]
//         004a063e     PUSH       s_                                               = ""
//         004a0643     PUSH       EAX
//         004a0644     PUSH       EDI
//         004a0645     MOV        this,EDI
//         004a0647     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a064c     TEST       EAX,EAX
//         004a064e     JZ         LAB_004a0d3d
//                              scr_mps.cpp:317 (49)
//         004a0654     PUSH       0x0
//         004a0656     PUSH       0x0
//         004a0658     PUSH       0x0
//         004a065a     PUSH       0xb
//         004a065c     LEA        EBX,[EBP + 0x2]
//         004a065f     PUSH       0x16
//         004a0661     PUSH       0x8b
//         004a0666     PUSH       EBX
//         004a0667     PUSH       0x1c
//         004a0669     LEA        this,[ESI + 0xfffffec0]
//         004a066f     PUSH       s_                                               = ""
//         004a0674     PUSH       this
//         004a0675     PUSH       EDI
//         004a0676     MOV        this,EDI
//         004a0678     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a067d     TEST       EAX,EAX
//         004a067f     JZ         LAB_004a0d3d
//                              scr_mps.cpp:318 (46)
//         004a0685     PUSH       0x0
//         004a0687     PUSH       0x0
//         004a0689     PUSH       0x0
//         004a068b     PUSH       0xb
//         004a068d     PUSH       0x16
//         004a068f     PUSH       0x6d
//         004a0691     PUSH       EBX
//         004a0692     PUSH       0xbf
//         004a0697     LEA        EDX,[ESI + 0xfffffee0]
//         004a069d     PUSH       s_                                               = ""
//         004a06a2     PUSH       EDX
//         004a06a3     PUSH       EDI
//         004a06a4     MOV        this,EDI
//         004a06a6     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a06ab     TEST       EAX,EAX
//         004a06ad     JZ         LAB_004a0d3d
//                              scr_mps.cpp:319 (46)
//         004a06b3     PUSH       0x0
//         004a06b5     PUSH       0x0
//         004a06b7     PUSH       0x0
//         004a06b9     PUSH       0xb
//         004a06bb     PUSH       0x16
//         004a06bd     PUSH       0x28
//         004a06bf     PUSH       EBX
//         004a06c0     PUSH       0x159
//         004a06c5     LEA        EAX,[ESI + 0xffffff00]
//         004a06cb     PUSH       s_                                               = ""
//         004a06d0     PUSH       EAX
//         004a06d1     PUSH       EDI
//         004a06d2     MOV        this,EDI
//         004a06d4     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a06d9     TEST       EAX,EAX
//         004a06db     JZ         LAB_004a0d3d
//                              scr_mps.cpp:320 (49)
//         004a06e1     PUSH       0x0
//         004a06e3     PUSH       0x0
//         004a06e5     PUSH       0x0
//         004a06e7     PUSH       0x6
//         004a06e9     LEA        EBX,[EBP + 0x3]
//         004a06ec     PUSH       0x16
//         004a06ee     PUSH       0x14
//         004a06f0     PUSH       EBX
//         004a06f1     LEA        EBP,[ESI + 0xffffff20]
//         004a06f7     PUSH       0x151
//                              language.dll match for 0x25df: "CD"
//         004a06fc     PUSH       0x25df
//         004a0701     PUSH       EBP
//         004a0702     PUSH       EDI
//         004a0703     MOV        this,EDI
//         004a0705     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a070a     TEST       EAX,EAX
//         004a070c     JZ         LAB_004a0d3d
//                              scr_mps.cpp:321 (46)
//         004a0712     PUSH       0x0
//         004a0714     PUSH       0x0
//         004a0716     PUSH       0x0
//         004a0718     PUSH       0x6
//         004a071a     PUSH       0x16
//         004a071c     PUSH       0x1d
//         004a071e     PUSH       EBX
//         004a071f     PUSH       0x161
//         004a0724     LEA        this,[ESI + 0xffffff40]
//         004a072a     PUSH       s_                                               = ""
//         004a072f     PUSH       this
//         004a0730     PUSH       EDI
//         004a0731     MOV        this,EDI
//         004a0733     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a0738     TEST       EAX,EAX
//         004a073a     JZ         LAB_004a0d3d
//                              scr_mps.cpp:323 (38)
//         004a0740     MOV        EBP,dword ptr [EBP]
//         004a0743     PUSH       0x0
//         004a0745     MOV        this,EBP
//         004a0747     MOV        EDX,dword ptr [EBP]
//         004a074a     CALL       dword ptr [EDX + 0x14]
//         004a074d     MOV        EAX,dword ptr [ESP + 0x10]
//         004a0751     ADD        ESI,0x4
//         004a0754     ADD        EAX,0x18
//         004a0757     CMP        EAX,0x115
//         004a075c     MOV        dword ptr [ESP + 0x10],EAX
//         004a0760     JL         LAB_004a0314
//                              scr_mps.cpp:330 (30)
//         004a0766     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a076c     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a0771     TEST       EAX,EAX
//         004a0773     JNZ        LAB_004a0784
//         004a0775     MOV        this,dword ptr [comm]                            = 00000000
//         004a077b     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a0780     TEST       EAX,EAX
//         004a0782     JZ         LAB_004a07c4
//                               LAB_004a0784                                                 XREF[1]:     004a0773(j)
//                              scr_mps.cpp:332 (50)
//         004a0784     PUSH       0x0
//         004a0786     PUSH       0x0=>DAT_fffffff8
//         004a0788     PUSH       0x0=>DAT_fffffff4
//         004a078a     PUSH       offset DAT_fffffff0
//         004a078c     PUSH       0xd2
//         004a0791     PUSH       0x32
//         004a0793     PUSH       0x1a4
//         004a0798     LEA        ESI,[EDI + 0x620]
//         004a079e     PUSH       0x0
//                              language.dll match for 0x25d2: "Settings"
//         004a07a0     PUSH       0x25d2
//         004a07a5     PUSH       ESI
//         004a07a6     PUSH       EDI
//         004a07a7     MOV        this,EDI
//         004a07a9     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a07ae     TEST       EAX,EAX
//         004a07b0     JZ         LAB_004a0d3d
//                              scr_mps.cpp:333 (14)
//         004a07b6     MOV        this,dword ptr [ESI]
//         004a07b8     PUSH       -0x1
//                              language.dll match for 0x75fc: "Click to change the scenario
//         004a07ba     PUSH       offset DAT_fffffff8
//         004a07bf     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                               LAB_004a07c4                                                 XREF[1]:     004a0782(j)
//                              scr_mps.cpp:337 (50)
//         004a07c4     XOR        EBP,EBP
//         004a07c6     PUSH       0x1
//         004a07c8     PUSH       EBP=>DAT_fffffff8
//         004a07c9     PUSH       EBP=>DAT_fffffff4
//         004a07ca     PUSH       offset DAT_fffffff0
//         004a07cc     PUSH       0x44
//         004a07ce     PUSH       0xdc
//         004a07d3     PUSH       0x54
//         004a07d5     PUSH       0x1a4
//         004a07da     LEA        EAX,[EDI + 0x624]
//         004a07e0     PUSH       s_                                               = ""
//         004a07e5     PUSH       EAX
//         004a07e6     PUSH       EDI
//         004a07e7     MOV        this,EDI
//         004a07e9     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a07ee     TEST       EAX,EAX
//         004a07f0     JZ         LAB_004a0d3d
//                              scr_mps.cpp:339 (11)
//         004a07f6     MOV        ESI,0x53
//         004a07fb     LEA        EBX,[EDI + 0x62c]
//                               LAB_004a0801                                                 XREF[1]:     004a0835(j)
//                              scr_mps.cpp:341 (54)
//         004a0801     PUSH       EBP
//         004a0802     PUSH       EBP=>DAT_fffffff8
//         004a0803     PUSH       EBP=>DAT_fffffff4
//         004a0804     PUSH       offset DAT_fffffff0
//         004a0806     PUSH       0x14
//         004a0808     PUSH       0xdc
//         004a080d     PUSH       ESI
//         004a080e     PUSH       0x1a4
//         004a0813     PUSH       s_                                               = ""
//         004a0818     PUSH       EBX
//         004a0819     PUSH       EDI
//         004a081a     MOV        this,EDI
//         004a081c     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a0821     TEST       EAX,EAX
//         004a0823     JZ         LAB_004a0d3d
//         004a0829     ADD        ESI,0x18
//         004a082c     ADD        EBX,0x4
//         004a082f     CMP        ESI,0x233
//         004a0835     JL         LAB_004a0801
//                              scr_mps.cpp:345 (19)
//         004a0837     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a083d     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a0842     TEST       EAX,EAX
//         004a0844     JZ         LAB_004a095b
//                              scr_mps.cpp:347 (45)
//         004a084a     PUSH       EBP
//         004a084b     PUSH       offset DAT_fffffff8
//         004a084d     PUSH       EBP=>DAT_fffffff4
//         004a084e     PUSH       offset DAT_fffffff0
//         004a0850     PUSH       0x14
//         004a0852     PUSH       0x64
//         004a0854     PUSH       0x118
//         004a0859     PUSH       0xa
//         004a085b     LEA        this,[EDI + 0x614]
//                              language.dll match for 0x25d7: "Chat"
//         004a0861     PUSH       0x25d7
//         004a0866     PUSH       this
//         004a0867     PUSH       EDI
//         004a0868     MOV        this,EDI
//         004a086a     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a086f     TEST       EAX,EAX
//         004a0871     JZ         LAB_004a0d3d
//                              scr_mps.cpp:348 (47)
//         004a0877     PUSH       EBP
//         004a0878     PUSH       EBP=>DAT_fffffff8
//         004a0879     PUSH       EBP=>DAT_fffffff4
//         004a087a     PUSH       offset DAT_fffffff0
//         004a087c     PUSH       0x60
//         004a087e     PUSH       0x190
//         004a0883     PUSH       0x12c
//         004a0888     LEA        ESI,[EDI + 0x618]
//         004a088e     PUSH       0xa
//         004a0890     PUSH       s_                                               = ""
//         004a0895     PUSH       ESI
//         004a0896     PUSH       EDI
//         004a0897     MOV        this,EDI
//         004a0899     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a089e     TEST       EAX,EAX
//         004a08a0     JZ         LAB_004a0d3d
//                              scr_mps.cpp:349 (27)
//         004a08a6     MOV        EDX,dword ptr [ESI]
//         004a08a8     PUSH       0x14
//         004a08aa     LEA        EAX,[EDI + 0x61c]
//         004a08b0     PUSH       EDX=>DAT_fffffff8
//         004a08b1     PUSH       EAX=>DAT_fffffff4
//         004a08b2     MOV        this,EDI
//         004a08b4     CALL       TEasy_Panel::create_auto_scrollbar               int create_auto_scrollbar(TEasy_Panel * this,
//         004a08b9     TEST       EAX,EAX
//         004a08bb     JZ         LAB_004a0d3d
//                              scr_mps.cpp:351 (53)
//         004a08c1     PUSH       EBP
//         004a08c2     PUSH       offset DAT_fffffff8
//         004a08c4     PUSH       offset DAT_fffffff4
//         004a08c6     PUSH       offset DAT_fffffff0
//         004a08c8     PUSH       0x190
//         004a08cd     PUSH       0x192
//         004a08d2     PUSH       0xa
//         004a08d4     PUSH       EBP
//         004a08d5     LEA        EBX,[EDI + 0x610]
//         004a08db     PUSH       0xf7
//         004a08e0     PUSH       s_                                               = ""
//         004a08e5     PUSH       EBX
//         004a08e6     PUSH       EDI
//         004a08e7     MOV        this,EDI
//         004a08e9     CALL       TEasy_Panel::create_edit                         int create_edit(TEasy_Panel * this, TPanel *
//         004a08ee     TEST       EAX,EAX
//         004a08f0     JZ         LAB_004a0d3d
//                              scr_mps.cpp:352 (14)
//         004a08f6     MOV        this,dword ptr [EBX]
//         004a08f8     PUSH       -0x1
//                              language.dll match for 0x75fe: "Type a message."
//         004a08fa     PUSH       offset DAT_fffffff8
//         004a08ff     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:353 (66)
//         004a0904     XOR        EAX,EAX
//         004a0906     MOV        this,dword ptr [ESI]
//         004a0908     MOV        AL,byte ptr [EDI + 0x325]
//         004a090e     PUSH       EAX
//         004a090f     XOR        EAX,EAX
//         004a0911     MOV        AL,byte ptr [EDI + 0x324]
//         004a0917     MOV        EDX,dword ptr [this->_padding_]
//         004a0919     PUSH       EAX=>DAT_fffffff8
//         004a091a     XOR        EAX,EAX
//         004a091c     MOV        AL,byte ptr [EDI + 0x323]
//         004a0922     PUSH       EAX=>DAT_fffffff4
//         004a0923     XOR        EAX,EAX
//         004a0925     MOV        AL,byte ptr [EDI + 0x322]
//         004a092b     PUSH       EAX=>DAT_fffffff0
//         004a092c     XOR        EAX,EAX
//         004a092e     MOV        AL,byte ptr [EDI + 0x321]
//         004a0934     PUSH       EAX
//         004a0935     XOR        EAX,EAX
//         004a0937     MOV        AL,byte ptr [EDI + 0x320]
//         004a093d     PUSH       EAX
//         004a093e     PUSH       0x3
//         004a0940     CALL       dword ptr [EDX + 0xec]
//                              scr_mps.cpp:354 (14)
//         004a0946     MOV        this,dword ptr [ESI]
//         004a0948     PUSH       -0x1
//                              language.dll match for 0x75fd: "Displays chat messages."
//         004a094a     PUSH       offset DAT_fffffff8
//         004a094f     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:355 (7)
//         004a0954     MOV        this,dword ptr [ESI]
//         004a0956     CALL       TTextPanel::empty_list                           void empty_list(TTextPanel * this)
//                               LAB_004a095b                                                 XREF[1]:     004a0844(j)
//                              scr_mps.cpp:359 (15)
//         004a095b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0961     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a0966     TEST       EAX,EAX
//         004a0968     JZ         LAB_004a09cf
//                              scr_mps.cpp:361 (47)
//         004a096a     PUSH       EBP
//         004a096b     PUSH       offset DAT_fffffff8
//         004a096d     PUSH       EBP=>DAT_fffffff4
//         004a096e     PUSH       EBP=>DAT_fffffff0
//         004a096f     PUSH       0x14
//         004a0971     PUSH       0x14f
//         004a0976     PUSH       0x127
//         004a097b     PUSH       0x1a
//         004a097d     LEA        this,[EDI + 0x6dc]
//                              language.dll match for 0x25d8: "Number of Players"
//         004a0983     PUSH       0x25d8
//         004a0988     PUSH       this
//         004a0989     PUSH       EDI
//         004a098a     MOV        this,EDI
//         004a098c     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a0991     TEST       EAX,EAX
//         004a0993     JZ         LAB_004a0d3d
//                              scr_mps.cpp:362 (40)
//         004a0999     PUSH       0xb
//         004a099b     PUSH       offset DAT_fffffff8
//         004a099d     PUSH       offset DAT_fffffff4
//         004a099f     PUSH       offset DAT_fffffff0
//         004a09a4     PUSH       0x1f
//         004a09a6     LEA        ESI,[EDI + 0x6e0]
//         004a09ac     PUSH       0x64
//         004a09ae     PUSH       0x46
//         004a09b0     PUSH       ESI
//         004a09b1     PUSH       EDI
//         004a09b2     MOV        this,EDI
//         004a09b4     CALL       TEasy_Panel::create_drop_down                    int create_drop_down(TEasy_Panel * this, TPan
//         004a09b9     TEST       EAX,EAX
//         004a09bb     JZ         LAB_004a0d3d
//                              scr_mps.cpp:363 (14)
//         004a09c1     MOV        this,dword ptr [ESI]
//         004a09c3     PUSH       -0x1
//                              language.dll match for 0x7600: "Select the number of players."
//         004a09c5     PUSH       offset DAT_fffffff8
//         004a09ca     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                               LAB_004a09cf                                                 XREF[1]:     004a0968(j)
//                              scr_mps.cpp:368 (6)
//         004a09cf     MOV        dword ptr [EDI + 0x85c],EBP
//                              scr_mps.cpp:370 (19)
//         004a09d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a09db     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a09e0     TEST       EAX,EAX
//         004a09e2     JZ         LAB_004a0a71
//                              scr_mps.cpp:373 (46)
//         004a09e8     PUSH       EBP
//         004a09e9     PUSH       EBP=>DAT_fffffff8
//         004a09ea     PUSH       EBP=>DAT_fffffff4
//         004a09eb     PUSH       offset DAT_fffffff0
//         004a09ed     PUSH       0xf0
//         004a09f2     PUSH       0x1b8
//         004a09f7     PUSH       0x46
//         004a09f9     LEA        ESI,[EDI + 0x700]
//         004a09ff     PUSH       EBP
//         004a0a00     PUSH       s_                                               = ""
//         004a0a05     PUSH       ESI
//         004a0a06     PUSH       EDI
//         004a0a07     MOV        this,EDI
//         004a0a09     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0a0e     TEST       EAX,EAX
//         004a0a10     JZ         LAB_004a0d3d
//                              scr_mps.cpp:374 (13)
//         004a0a16     MOV        this,dword ptr [ESI]
//                              language.dll match for 0x25ee: "Start Game"
//         004a0a18     PUSH       0x25ee
//         004a0a1d     PUSH       EBP=>DAT_fffffff8
//         004a0a1e     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              scr_mps.cpp:375 (14)
//         004a0a23     MOV        this,dword ptr [ESI]
//         004a0a25     PUSH       -0x1
//         004a0a27     PUSH       offset DAT_fffffff8
//         004a0a2c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:376 (10)
//         004a0a31     MOV        EDX,dword ptr [ESI]
//         004a0a33     MOV        this,EDI
//         004a0a35     PUSH       EDX
//         004a0a36     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_mps.cpp:378 (49)
//         004a0a3b     PUSH       EBP
//         004a0a3c     PUSH       EBP=>DAT_fffffff8
//         004a0a3d     PUSH       EBP=>DAT_fffffff4
//         004a0a3e     PUSH       offset DAT_fffffff0
//         004a0a40     PUSH       0xf0
//         004a0a45     PUSH       0x1b8
//         004a0a4a     PUSH       0x14a
//         004a0a4f     LEA        ESI,[EDI + 0x70c]
//         004a0a55     PUSH       EBP
//                              language.dll match for 0xfa2: "Cancel"
//         004a0a56     PUSH       0xfa2
//         004a0a5b     PUSH       ESI
//         004a0a5c     PUSH       EDI
//         004a0a5d     MOV        this,EDI
//         004a0a5f     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0a64     TEST       EAX,EAX
//         004a0a66     JZ         LAB_004a0d3d
//                              scr_mps.cpp:381 (16)
//         004a0a6c     JMP        LAB_004a0c51
//                               LAB_004a0a71                                                 XREF[1]:     004a09e2(j)
//         004a0a71     MOV        this,dword ptr [comm]                            = 00000000
//         004a0a77     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//                              scr_mps.cpp:384 (44)
//         004a0a7c     PUSH       EBP
//         004a0a7d     PUSH       EBP=>DAT_fffffff8
//         004a0a7e     PUSH       offset DAT_fffffff4
//         004a0a80     PUSH       offset DAT_fffffff0
//         004a0a82     TEST       EAX,EAX
//         004a0a84     LEA        ESI,[EDI + 0x714]
//         004a0a8a     PUSH       0x1b8
//         004a0a8f     JZ         LAB_004a0bcd
//         004a0a95     PUSH       0xa
//         004a0a97     PUSH       ESI
//         004a0a98     PUSH       EDI
//         004a0a99     MOV        this,EDI
//         004a0a9b     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
//         004a0aa0     TEST       EAX,EAX
//         004a0aa2     JZ         LAB_004a0d3d
//                              scr_mps.cpp:385 (47)
//         004a0aa8     PUSH       EBP
//         004a0aa9     PUSH       offset DAT_fffffff8
//         004a0aab     PUSH       EBP=>DAT_fffffff4
//         004a0aac     PUSH       EBP=>DAT_fffffff0
//         004a0aad     PUSH       0x1e
//         004a0aaf     PUSH       0x96
//         004a0ab4     PUSH       0x1b8
//         004a0ab9     PUSH       0x2d
//         004a0abb     LEA        EAX,[EDI + 0x71c]
//                              language.dll match for 0x25bf: "I'm Ready!"
//         004a0ac1     PUSH       0x25bf
//         004a0ac6     PUSH       EAX
//         004a0ac7     PUSH       EDI
//         004a0ac8     MOV        this,EDI
//         004a0aca     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a0acf     TEST       EAX,EAX
//         004a0ad1     JZ         LAB_004a0d3d
//                              scr_mps.cpp:386 (14)
//         004a0ad7     MOV        this,dword ptr [ESI]
//         004a0ad9     PUSH       -0x1
//                              language.dll match for 0x7602: "Click to indicate that you ar
//         004a0adb     PUSH       offset DAT_fffffff8
//         004a0ae0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:389 (49)
//         004a0ae5     PUSH       EBP
//         004a0ae6     PUSH       EBP=>DAT_fffffff8
//         004a0ae7     PUSH       EBP=>DAT_fffffff4
//         004a0ae8     PUSH       offset DAT_fffffff0
//         004a0aea     PUSH       0xc8
//         004a0aef     PUSH       0x1b8
//         004a0af4     PUSH       0xc3
//         004a0af9     LEA        ESI,[EDI + 0x700]
//         004a0aff     PUSH       EBP
//         004a0b00     PUSH       s_                                               = ""
//         004a0b05     PUSH       ESI
//         004a0b06     PUSH       EDI
//         004a0b07     MOV        this,EDI
//         004a0b09     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0b0e     TEST       EAX,EAX
//         004a0b10     JZ         LAB_004a0d3d
//                              scr_mps.cpp:390 (13)
//         004a0b16     MOV        this,dword ptr [ESI]
//                              language.dll match for 0x25ee: "Start Game"
//         004a0b18     PUSH       0x25ee
//         004a0b1d     PUSH       EBP=>DAT_fffffff8
//         004a0b1e     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              scr_mps.cpp:391 (14)
//         004a0b23     MOV        this,dword ptr [ESI]
//         004a0b25     PUSH       -0x1
//         004a0b27     PUSH       offset DAT_fffffff8
//         004a0b2c     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:392 (9)
//         004a0b31     MOV        this,dword ptr [ESI]
//         004a0b33     PUSH       0x1
//         004a0b35     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                              scr_mps.cpp:394 (49)
//         004a0b3a     PUSH       EBP
//         004a0b3b     PUSH       EBP=>DAT_fffffff8
//         004a0b3c     PUSH       EBP=>DAT_fffffff4
//         004a0b3d     PUSH       offset DAT_fffffff0
//         004a0b3f     PUSH       0xb4
//         004a0b44     PUSH       0x1b8
//         004a0b49     PUSH       0x195
//         004a0b4e     LEA        ESI,[EDI + 0x70c]
//         004a0b54     PUSH       EBP
//                              language.dll match for 0xfa2: "Cancel"
//         004a0b55     PUSH       0xfa2
//         004a0b5a     PUSH       ESI
//         004a0b5b     PUSH       EDI
//         004a0b5c     MOV        this,EDI
//         004a0b5e     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0b63     TEST       EAX,EAX
//         004a0b65     JZ         LAB_004a0d3d
//                              scr_mps.cpp:395 (14)
//         004a0b6b     MOV        this,dword ptr [ESI]
//         004a0b6d     PUSH       -0x1
//         004a0b6f     PUSH       offset DAT_fffffff8
//         004a0b74     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:398 (46)
//         004a0b79     PUSH       EBP
//         004a0b7a     PUSH       EBP=>DAT_fffffff8
//         004a0b7b     PUSH       EBP=>DAT_fffffff4
//         004a0b7c     PUSH       offset DAT_fffffff0
//         004a0b7e     PUSH       0x1e
//         004a0b80     PUSH       0x190
//         004a0b85     PUSH       0x258
//         004a0b8a     LEA        EBX,[EDI + 0x858]
//         004a0b90     PUSH       EBP
//                              language.dll match for 0x25ef: "IP"
//         004a0b91     PUSH       0x25ef
//         004a0b96     PUSH       EBX
//         004a0b97     PUSH       EDI
//         004a0b98     MOV        this,EDI
//         004a0b9a     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0b9f     TEST       EAX,EAX
//         004a0ba1     JZ         LAB_004a0d3d
//                              scr_mps.cpp:399 (14)
//         004a0ba7     MOV        this,dword ptr [EBX]
//         004a0ba9     PUSH       -0x1
//                              language.dll match for 0x7601: "Click to display your network
//         004a0bab     PUSH       offset DAT_fffffff8
//         004a0bb0     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:401 (19)
//         004a0bb5     MOV        this,dword ptr [comm]                            = 00000000
//         004a0bbb     PUSH       EBP
//         004a0bbc     PUSH       EBP=>DAT_fffffff8
//         004a0bbd     PUSH       EBP=>DAT_fffffff4
//         004a0bbe     PUSH       EBP=>DAT_fffffff0
//         004a0bbf     PUSH       EBP
//         004a0bc0     PUSH       EBP
//         004a0bc1     PUSH       EBP
//         004a0bc2     PUSH       EBP
//         004a0bc3     CALL       TCommunications_Handler::SetMyReadiness          int SetMyReadiness(TCommunications_Handler *
//                              scr_mps.cpp:403 (5)
//         004a0bc8     JMP        LAB_004a0c5f
//                               LAB_004a0bcd                                                 XREF[1]:     004a0a8f(j)
//                              scr_mps.cpp:406 (19)
//         004a0bcd     PUSH       0x64
//         004a0bcf     PUSH       ESI
//         004a0bd0     PUSH       EDI
//         004a0bd1     MOV        this,EDI
//         004a0bd3     CALL       TEasy_Panel::create_check_box                    int create_check_box(TEasy_Panel * this, TPan
//         004a0bd8     TEST       EAX,EAX
//         004a0bda     JZ         LAB_004a0d3d
//                              scr_mps.cpp:407 (50)
//         004a0be0     PUSH       EBP
//         004a0be1     PUSH       offset DAT_fffffff8
//         004a0be3     PUSH       EBP=>DAT_fffffff4
//         004a0be4     PUSH       EBP=>DAT_fffffff0
//         004a0be5     PUSH       0x1e
//         004a0be7     PUSH       0x96
//         004a0bec     PUSH       0x1b8
//         004a0bf1     PUSH       0x87
//         004a0bf6     LEA        this,[EDI + 0x71c]
//                              language.dll match for 0x25bf: "I'm Ready!"
//         004a0bfc     PUSH       0x25bf
//         004a0c01     PUSH       this
//         004a0c02     PUSH       EDI
//         004a0c03     MOV        this,EDI
//         004a0c05     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a0c0a     TEST       EAX,EAX
//         004a0c0c     JZ         LAB_004a0d3d
//                              scr_mps.cpp:408 (14)
//         004a0c12     MOV        this,dword ptr [ESI]
//         004a0c14     PUSH       -0x1
//                              language.dll match for 0x7602: "Click to indicate that you ar
//         004a0c16     PUSH       offset DAT_fffffff8
//         004a0c1b     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                              scr_mps.cpp:410 (49)
//         004a0c20     PUSH       EBP
//         004a0c21     PUSH       EBP=>DAT_fffffff8
//         004a0c22     PUSH       EBP=>DAT_fffffff4
//         004a0c23     PUSH       offset DAT_fffffff0
//         004a0c25     PUSH       0xf0
//         004a0c2a     PUSH       0x1b8
//         004a0c2f     PUSH       0x14a
//         004a0c34     LEA        ESI,[EDI + 0x70c]
//         004a0c3a     PUSH       EBP
//                              language.dll match for 0xfa2: "Cancel"
//         004a0c3b     PUSH       0xfa2
//         004a0c40     PUSH       ESI
//         004a0c41     PUSH       EDI
//         004a0c42     MOV        this,EDI
//         004a0c44     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0c49     TEST       EAX,EAX
//         004a0c4b     JZ         LAB_004a0d3d
//                               LAB_004a0c51                                                 XREF[1]:     004a0a6c(j)
//                              scr_mps.cpp:411 (14)
//         004a0c51     MOV        this,dword ptr [ESI]
//         004a0c53     PUSH       -0x1
//         004a0c55     PUSH       offset DAT_fffffff8
//         004a0c5a     CALL       TPanel::set_help_info                            void set_help_info(TPanel * this, long param_
//                               LAB_004a0c5f                                                 XREF[1]:     004a0bc8(j)
//                              scr_mps.cpp:415 (46)
//         004a0c5f     PUSH       EBP
//         004a0c60     PUSH       EBP=>DAT_fffffff8
//         004a0c61     PUSH       EBP=>DAT_fffffff4
//         004a0c62     PUSH       offset DAT_fffffff0
//         004a0c64     PUSH       0x1e
//         004a0c66     PUSH       0x1b8
//         004a0c6b     PUSH       0x258
//         004a0c70     PUSH       EBP
//         004a0c71     LEA        EDX,[EDI + 0x710]
//                              language.dll match for 0xfa9: "?"
//         004a0c77     PUSH       0xfa9
//         004a0c7c     PUSH       EDX
//         004a0c7d     PUSH       EDI
//         004a0c7e     MOV        this,EDI
//         004a0c80     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0c85     TEST       EAX,EAX
//         004a0c87     JZ         LAB_004a0d3d
//                              scr_mps.cpp:418 (38)
//         004a0c8d     PUSH       EBP
//         004a0c8e     PUSH       offset DAT_fffffff8
//         004a0c90     PUSH       offset DAT_fffffff4
//         004a0c92     PUSH       EBP=>DAT_fffffff0
//         004a0c93     PUSH       EBP
//         004a0c94     PUSH       EBP
//         004a0c95     PUSH       EBP
//         004a0c96     LEA        EBX,[EDI + 0x718]
//         004a0c9c     PUSH       EBP
//                              language.dll match for 0x3ea: "X"
//         004a0c9d     PUSH       0x3ea
//         004a0ca2     PUSH       EBX
//         004a0ca3     PUSH       EDI
//         004a0ca4     MOV        this,EDI
//         004a0ca6     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a0cab     TEST       EAX,EAX
//         004a0cad     JZ         LAB_004a0d3d
//                              scr_mps.cpp:419 (9)
//         004a0cb3     MOV        this,dword ptr [EBX]
//         004a0cb5     PUSH       0x1
//         004a0cb7     MOV        EAX,dword ptr [this->_padding_]
//         004a0cb9     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:420 (29)
//         004a0cbc     MOV        this,dword ptr [EBX]
//         004a0cbe     PUSH       EBP
//         004a0cbf     PUSH       EBP=>DAT_fffffff8
//         004a0cc0     PUSH       EBP=>DAT_fffffff4
//         004a0cc1     MOV        EDX,dword ptr [this->_padding_]
//         004a0cc3     PUSH       EBP=>DAT_fffffff0
//         004a0cc4     PUSH       0x11
//         004a0cc6     PUSH       0x11
//         004a0cc8     PUSH       0x11
//         004a0cca     PUSH       0x11
//         004a0ccc     PUSH       0x4
//         004a0cce     PUSH       0x4
//         004a0cd0     PUSH       0x4
//         004a0cd2     PUSH       0x4
//         004a0cd4     PUSH       0x9
//         004a0cd6     CALL       dword ptr [EDX + 0x18]
//                              scr_mps.cpp:423 (2)
//         004a0cd9     MOV        ESI,dword ptr [ESI]
//                              scr_mps.cpp:424 (23)
//         004a0cdb     MOV        this,EDI
//         004a0cdd     MOV        dword ptr [ESI + 0x298],0x1b
//         004a0ce7     MOV        dword ptr [ESI + 0x29c],EBP
//         004a0ced     CALL       TribeMPSetupScreen::setupTabOrder                void setupTabOrder(TribeMPSetupScreen * this)
//                              scr_mps.cpp:427 (19)
//         004a0cf2     MOV        EAX,[L]                                          = 00000000
//         004a0cf7     PUSH       s_$$$_CHAT_SCREEN:_UPDATE_SUMMARY                = "$$$ CHAT SCREEN: UPDATE SUMMARY"
//         004a0cfc     PUSH       EAX=>DAT_fffffff8
//         004a0cfd     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a0d02     ADD        ESP,0x8
//                              scr_mps.cpp:428 (7)
//         004a0d05     MOV        this,EDI
//         004a0d07     CALL       TribeMPSetupScreen::updateSummary                void updateSummary(TribeMPSetupScreen * this)
//                              scr_mps.cpp:430 (15)
//         004a0d0c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0d12     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a0d17     TEST       EAX,EAX
//         004a0d19     JZ         LAB_004a0d29
//                              scr_mps.cpp:432 (7)
//         004a0d1b     MOV        this,EDI
//         004a0d1d     CALL       TribeMPSetupScreen::setupSinglePlayerPlayers     void setupSinglePlayerPlayers(TribeMPSetupScr
//                              scr_mps.cpp:433 (7)
//         004a0d22     MOV        this,EDI
//         004a0d24     CALL       TribeMPSetupScreen::fillPlayers                  void fillPlayers(TribeMPSetupScreen * this)
//                               LAB_004a0d29                                                 XREF[1]:     004a0d19(j)
//                              scr_mps.cpp:436 (20)
//         004a0d29     MOV        this,dword ptr [L]                               = 00000000
//         004a0d2f     PUSH       s_$$$_CHAT_SCREEN:_CONSTRUCTOR_DON               = "$$$ CHAT SCREEN: CONSTRUCTOR DONE"
//         004a0d34     PUSH       this=>DAT_fffffff8
//         004a0d35     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a0d3a     ADD        ESP,0x8
//                               LAB_004a0d3d                                                 XREF[40]:    004a0186(j), 004a01de(j),
//                                                                                                         004a020d(j), 004a023f(j),
//                                                                                                         004a028c(j), 004a02bb(j),
//                                                                                                         004a02f5(j), 004a033c(j),
//                                                                                                         004a03d1(j), 004a050d(j),
//                                                                                                         004a055c(j), 004a0599(j),
//                                                                                                         004a05c4(j), 004a064e(j),
//                                                                                                         004a067f(j), 004a06ad(j),
//                                                                                                         004a06db(j), 004a070c(j),
//                                                                                                         004a073a(j), 004a07b0(j), [more]
//                              scr_mps.cpp:437 (27)
//         004a0d3d     MOV        this,dword ptr [ESP + local_c]
//         004a0d44     MOV        EAX,EDI
//         004a0d46     POP        EDI
//         004a0d47     POP        ESI
//         004a0d48     POP        EBP
//         004a0d49     MOV        dword ptr FS:[0x0],this
//         004a0d50     POP        EBX
//         004a0d51     ADD        ESP,0x118
//         004a0d57     RET
//         004a0d58     ??         90h
//         004a0d59     NOP
//         004a0d5a     NOP
//         004a0d5b     NOP
//         004a0d5c     NOP
//         004a0d5d     NOP
//         004a0d5e     NOP
//         004a0d5f     NOP
}

void TribeMPSetupScreen::init_vars() {
    /* TODO: Stub */
//                              void __thiscall init_vars(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//                               ?init_vars@TribeMPSetupScreen@@IAEXXZ                        XREF[1]:     TribeMPSetupScreen:004a0105(c)
//                               TribeMPSetupScreen::init_vars
//                              scr_mps.cpp:443 (5)
//         004a0d80     PUSH       EBX
//         004a0d81     PUSH       EBP
//         004a0d82     PUSH       ESI
//         004a0d83     MOV        ESI,this
//                              scr_mps.cpp:448 (13)
//         004a0d85     XOR        EBP,EBP
//         004a0d87     MOV        EBX,0x8
//         004a0d8c     MOV        dword ptr [ESI + 0x478],EBP
//                              scr_mps.cpp:449 (6)
//         004a0d92     MOV        dword ptr [ESI + 0x47c],EBP
//                              scr_mps.cpp:450 (6)
//         004a0d98     MOV        dword ptr [ESI + 0x480],EBP
//                              scr_mps.cpp:451 (6)
//         004a0d9e     MOV        dword ptr [ESI + 0x484],EBP
//                              scr_mps.cpp:452 (7)
//         004a0da4     MOV        dword ptr [ESI + 0x488],EBP
//         004a0daa     PUSH       EDI
//                              scr_mps.cpp:453 (14)
//         004a0dab     MOV        dword ptr [ESI + 0x48c],EBP
//         004a0db1     LEA        EAX,[ESI + 0x5d0]
//         004a0db7     MOV        this,EBX
//                               LAB_004a0db9                                                 XREF[1]:     004a0df2(j)
//                              scr_mps.cpp:457 (3)
//         004a0db9     MOV        dword ptr [EAX + -0x20],EBP
//                              scr_mps.cpp:458 (2)
//         004a0dbc     MOV        dword ptr [EAX],EBP
//                              scr_mps.cpp:459 (3)
//         004a0dbe     MOV        dword ptr [EAX + 0x20],EBP
//                              scr_mps.cpp:461 (3)
//         004a0dc1     MOV        dword ptr [EAX + -0x60],EBP
//                              scr_mps.cpp:462 (3)
//         004a0dc4     MOV        dword ptr [EAX + -0x40],EBP
//                              scr_mps.cpp:464 (6)
//         004a0dc7     MOV        dword ptr [EAX + 0xfffffec0],EBP
//                              scr_mps.cpp:465 (6)
//         004a0dcd     MOV        dword ptr [EAX + 0xfffffee0],EBP
//                              scr_mps.cpp:466 (6)
//         004a0dd3     MOV        dword ptr [EAX + 0xffffff00],EBP
//                              scr_mps.cpp:467 (6)
//         004a0dd9     MOV        dword ptr [EAX + 0xffffff20],EBP
//                              scr_mps.cpp:468 (6)
//         004a0ddf     MOV        dword ptr [EAX + 0xffffff40],EBP
//                              scr_mps.cpp:469 (6)
//         004a0de5     MOV        dword ptr [EAX + 0xffffff60],EBP
//                              scr_mps.cpp:470 (9)
//         004a0deb     MOV        dword ptr [EAX + -0x80],EBP
//         004a0dee     ADD        EAX,0x4
//         004a0df1     DEC        this
//         004a0df2     JNZ        LAB_004a0db9
//                              scr_mps.cpp:473 (6)
//         004a0df4     MOV        dword ptr [ESI + 0x610],EBP
//                              scr_mps.cpp:474 (6)
//         004a0dfa     MOV        dword ptr [ESI + 0x614],EBP
//                              scr_mps.cpp:475 (6)
//         004a0e00     MOV        dword ptr [ESI + 0x61c],EBP
//                              scr_mps.cpp:476 (6)
//         004a0e06     MOV        dword ptr [ESI + 0x618],EBP
//                              scr_mps.cpp:478 (6)
//         004a0e0c     MOV        dword ptr [ESI + 0x620],EBP
//                              scr_mps.cpp:480 (6)
//         004a0e12     MOV        dword ptr [ESI + 0x624],EBP
//                              scr_mps.cpp:481 (6)
//         004a0e18     MOV        dword ptr [ESI + 0x628],EBP
//                              scr_mps.cpp:663 (644)
//         004a0e1e     LEA        EAX,[ESI + 0x67c]
//         004a0e24     MOV        this,0x14
//                               LAB_004a0e29                                                 XREF[1]:     004a0e32(j)
//         004a0e29     MOV        dword ptr [EAX + -0x50],EBP
//         004a0e2c     MOV        dword ptr [EAX],EBP
//         004a0e2e     ADD        EAX,0x4
//         004a0e31     DEC        this
//         004a0e32     JNZ        LAB_004a0e29
//         004a0e34     MOV        dword ptr [ESI + 0x6cc],EBP
//         004a0e3a     MOV        dword ptr [ESI + 0x6d0],EBP
//         004a0e40     MOV        dword ptr [ESI + 0x6d4],EBP
//         004a0e46     MOV        dword ptr [ESI + 0x6d8],EBP
//         004a0e4c     MOV        dword ptr [ESI + 0x6dc],EBP
//         004a0e52     MOV        dword ptr [ESI + 0x6e0],EBP
//         004a0e58     MOV        dword ptr [ESI + 0x6e4],EBP
//         004a0e5e     MOV        dword ptr [ESI + 0x6e8],EBP
//         004a0e64     MOV        dword ptr [ESI + 0x6ec],EBP
//         004a0e6a     MOV        dword ptr [ESI + 0x6f0],EBP
//         004a0e70     MOV        dword ptr [ESI + 0x6f4],EBP
//         004a0e76     MOV        dword ptr [ESI + 0x6f8],EBP
//         004a0e7c     MOV        dword ptr [ESI + 0x6fc],EBP
//         004a0e82     MOV        dword ptr [ESI + 0x71c],EBP
//         004a0e88     MOV        dword ptr [ESI + 0x700],EBP
//         004a0e8e     MOV        dword ptr [ESI + 0x704],EBP
//         004a0e94     MOV        dword ptr [ESI + 0x708],EBP
//         004a0e9a     MOV        dword ptr [ESI + 0x70c],EBP
//         004a0ea0     MOV        dword ptr [ESI + 0x710],EBP
//         004a0ea6     MOV        dword ptr [ESI + 0x714],EBP
//         004a0eac     MOV        dword ptr [ESI + 0x718],EBP
//         004a0eb2     MOV        dword ptr [ESI + 0x720],EBP
//         004a0eb8     MOV        dword ptr [ESI + 0x724],EBP
//         004a0ebe     MOV        dword ptr [ESI + 0x72c],EBP
//         004a0ec4     MOV        dword ptr [ESI + 0x730],0xffffffff
//         004a0ece     MOV        dword ptr [ESI + 0x734],EBP
//         004a0ed4     MOV        dword ptr [ESI + 0x738],EBP
//         004a0eda     MOV        dword ptr [ESI + 0x73c],EBP
//         004a0ee0     MOV        byte ptr [ESI + 0x740],0x0
//         004a0ee7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0eed     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         004a0ef2     MOV        dword ptr [ESI + 0x840],EAX
//         004a0ef8     LEA        EDI,[ESI + 0x868]
//         004a0efe     MOV        this,EBX
//         004a0f00     XOR        EAX,EAX
//         004a0f02     MOV        dword ptr [ESI + 0x844],EBP
//         004a0f08     MOV        dword ptr [ESI + 0x848],EBP
//         004a0f0e     MOV        dword ptr [ESI + 0x850],EBX
//         004a0f14     MOV        dword ptr [ESI + 0x728],EBX
//         004a0f1a     MOV        dword ptr [ESI + 0x84c],EBP
//         004a0f20     MOV        dword ptr [ESI + 0x854],EBP
//         004a0f26     MOV        dword ptr [ESI + 0x858],EBP
//         004a0f2c     MOV        dword ptr [ESI + 0x85c],EBP
//         004a0f32     STOSD.REP  ES:EDI
//         004a0f34     MOV        dword ptr [ESI + 0x888],EBP
//         004a0f3a     MOV        dword ptr [ESI + 0x88c],EBP
//         004a0f40     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f46     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a0f4b     TEST       EAX,EAX
//         004a0f4d     JZ         LAB_004a1174
//         004a0f53     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f59     PUSH       EBP
//         004a0f5a     CALL       RGE_Base_Game::setCampaignGame                   void setCampaignGame(RGE_Base_Game * this, in
//         004a0f5f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f65     PUSH       EBP
//         004a0f66     CALL       RGE_Base_Game::setSavedGame                      void setSavedGame(RGE_Base_Game * this, int p
//         004a0f6b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f71     PUSH       EBP
//         004a0f72     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
//         004a0f77     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f7d     PUSH       s_                                               = ""
//         004a0f82     CALL       RGE_Base_Game::setScenarioName                   void setScenarioName(RGE_Base_Game * this, ch
//         004a0f87     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f8d     PUSH       0x3
//         004a0f8f     CALL       TRIBE_Game::setMapSize                           void setMapSize(TRIBE_Game * this, MapSize pa
//         004a0f94     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0f9a     PUSH       0x3
//         004a0f9c     CALL       TRIBE_Game::setMapType                           void setMapType(TRIBE_Game * this, MapType pa
//         004a0fa1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fa7     PUSH       EBP
//         004a0fa8     PUSH       EBP
//         004a0fa9     CALL       TRIBE_Game::setVictoryType                       void setVictoryType(TRIBE_Game * this, Victor
//         004a0fae     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fb4     PUSH       0x1
//         004a0fb6     CALL       TRIBE_Game::setAnimals                           void setAnimals(TRIBE_Game * this, int param_1)
//         004a0fbb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fc1     PUSH       0x1
//         004a0fc3     CALL       TRIBE_Game::setPredators                         void setPredators(TRIBE_Game * this, int para
//         004a0fc8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fce     PUSH       EBX
//         004a0fcf     CALL       RGE_Base_Game::setNumberPlayers                  void setNumberPlayers(RGE_Base_Game * this, i
//         004a0fd4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fda     PUSH       EBP
//         004a0fdb     CALL       RGE_Base_Game::setFullVisibility                 void setFullVisibility(RGE_Base_Game * this,
//         004a0fe0     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fe6     PUSH       0x1
//         004a0fe8     CALL       RGE_Base_Game::setFogOfWar                       void setFogOfWar(RGE_Base_Game * this, int pa
//         004a0fed     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0ff3     PUSH       EBP
//         004a0ff4     CALL       RGE_Base_Game::setAllowCheatCodes                void setAllowCheatCodes(RGE_Base_Game * this,
//         004a0ff9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a0fff     PUSH       EBP
//         004a1000     CALL       TRIBE_Game::setRandomizePositions                void setRandomizePositions(TRIBE_Game * this,
//         004a1005     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a100b     PUSH       EBP
//         004a100c     CALL       TRIBE_Game::setLongCombat                        void setLongCombat(TRIBE_Game * this, int par
//         004a1011     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1017     PUSH       0x1
//         004a1019     CALL       TRIBE_Game::setAllowTrading                      void setAllowTrading(TRIBE_Game * this, int p
//         004a101e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1024     PUSH       EBP
//         004a1025     CALL       TRIBE_Game::setFullTechTree                      void setFullTechTree(TRIBE_Game * this, int p
//         004a102a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1030     PUSH       EBP
//         004a1031     CALL       TRIBE_Game::setResourceLevel                     void setResourceLevel(TRIBE_Game * this, Reso
//         004a1036     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a103c     PUSH       EBP
//         004a103d     CALL       TRIBE_Game::setStartingAge                       void setStartingAge(TRIBE_Game * this, Age pa
//         004a1042     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1048     PUSH       EBP
//         004a1049     CALL       TRIBE_Game::setStartingUnits                     void setStartingUnits(TRIBE_Game * this, int
//         004a104e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1054     CALL       RGE_Base_Game::get_single_player_difficulty      int get_single_player_difficulty(RGE_Base_Gam
//         004a1059     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a105f     PUSH       EAX
//         004a1060     CALL       RGE_Base_Game::setDifficulty                     void setDifficulty(RGE_Base_Game * this, int
//         004a1065     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a106b     PUSH       EBP
//         004a106c     CALL       TRIBE_Game::setDeathMatch                        void setDeathMatch(TRIBE_Game * this, uchar p
//         004a1071     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1077     PUSH       EBP
//         004a1078     CALL       TRIBE_Game::setQuickStartGame                    void setQuickStartGame(TRIBE_Game * this, uch
//         004a107d     PUSH       0x243
//         004a1082     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a1087     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004a108c     ADD        ESP,0x8
//         004a108f     PUSH       EAX
//         004a1090     PUSH       0x243
//         004a1095     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a109a     CALL       debug_srand                                      void debug_srand(char * param_1, int param_2,
//         004a109f     ADD        ESP,0xc
//                              scr_mps.cpp:581 (2)
//         004a10a2     XOR        EBX,EBX
//                               LAB_004a10a4                                                 XREF[1]:     004a1137(j)
//                              scr_mps.cpp:583 (2)
//         004a10a4     MOV        AL,BL
//                              scr_mps.cpp:584 (27)
//         004a10a6     PUSH       0x248
//         004a10ab     INC        AL
//         004a10ad     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a10b2     MOV        byte ptr [EBX + ESI*0x1 + 0x860],AL
//         004a10b9     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004a10be     CDQ
//         004a10bf     XOR        EAX,EDX
//                              scr_mps.cpp:585 (26)
//         004a10c1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a10c7     SUB        EAX,EDX
//         004a10c9     ADD        ESP,0x8
//         004a10cc     AND        EAX,0xf
//         004a10cf     XOR        EAX,EDX
//         004a10d1     SUB        EAX,EDX
//         004a10d3     INC        EAX
//         004a10d4     PUSH       EAX
//         004a10d5     PUSH       EBX
//         004a10d6     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:589 (13)
//         004a10db     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a10e1     PUSH       EBX
//         004a10e2     PUSH       EBX
//         004a10e3     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:590 (13)
//         004a10e8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a10ee     PUSH       EBP
//         004a10ef     PUSH       EBX
//         004a10f0     CALL       RGE_Base_Game::setPlayerHasCD                    void setPlayerHasCD(RGE_Base_Game * this, int
//                              scr_mps.cpp:591 (13)
//         004a10f5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a10fb     PUSH       EBP
//         004a10fc     PUSH       EBX
//         004a10fd     CALL       RGE_Base_Game::setPlayerVersion                  void setPlayerVersion(RGE_Base_Game * this, i
//                              scr_mps.cpp:592 (22)
//         004a1102     XOR        this,this
//         004a1104     MOV        this,byte ptr [EBX + ESI*0x1 + 0x860]
//         004a110b     PUSH       this
//         004a110c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1112     PUSH       EBX
//         004a1113     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:593 (14)
//         004a1118     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a111e     PUSH       0x1
//         004a1120     PUSH       EBX
//         004a1121     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:594 (23)
//         004a1126     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a112c     PUSH       EBP
//         004a112d     PUSH       EBX
//         004a112e     CALL       TRIBE_Game::setComputerName                      void setComputerName(TRIBE_Game * this, int p
//         004a1133     INC        EBX
//         004a1134     CMP        EBX,0x8
//         004a1137     JL         LAB_004a10a4
//                              scr_mps.cpp:597 (19)
//         004a113d     MOV        this,dword ptr [comm]                            = 00000000
//         004a1143     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a1148     TEST       EAX,EAX
//         004a114a     JZ         LAB_004a12f6
//                              scr_mps.cpp:599 (14)
//         004a1150     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1156     PUSH       0x1
//         004a1158     PUSH       EBP
//         004a1159     CALL       RGE_Base_Game::setPlayerVersion                  void setPlayerVersion(RGE_Base_Game * this, i
//                              scr_mps.cpp:600 (11)
//         004a115e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1164     MOV        EDX,dword ptr [this->_padding_]
//         004a1166     CALL       dword ptr [EDX + 0x48]
//                              scr_mps.cpp:601 (6)
//         004a1169     MOV        dword ptr [ESI + 0x88c],EBP
//                              scr_mps.cpp:663 (5)
//         004a116f     POP        EDI
//         004a1170     POP        ESI
//         004a1171     POP        EBP
//         004a1172     POP        EBX
//         004a1173     RET
//                               LAB_004a1174                                                 XREF[1]:     004a0f4d(j)
//                              scr_mps.cpp:606 (13)
//         004a1174     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a117a     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a117f     TEST       EAX,EAX
//                              scr_mps.cpp:611 (6)
//         004a1181     JNZ        LAB_004a120c
//                              scr_mps.cpp:614 (13)
//         004a1187     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a118d     PUSH       0x3
//         004a118f     CALL       TRIBE_Game::setMapSize                           void setMapSize(TRIBE_Game * this, MapSize pa
//                              scr_mps.cpp:618 (26)
//         004a1194     PUSH       0x26a
//         004a1199     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a119e     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004a11a3     CDQ
//         004a11a4     MOV        this,0xa
//         004a11a9     ADD        ESP,0x8
//         004a11ac     IDIV       this
//                              scr_mps.cpp:620 (5)
//         004a11ae     CMP        EDX,0x2
//         004a11b1     JGE        LAB_004a11ba
//                              scr_mps.cpp:621 (5)
//         004a11b3     MOV        EAX,0x4
//                              scr_mps.cpp:622 (4)
//         004a11b8     JMP        LAB_004a1200
//                               LAB_004a11ba                                                 XREF[1]:     004a11b1(j)
//         004a11ba     JNZ        LAB_004a11c3
//                              scr_mps.cpp:623 (5)
//         004a11bc     MOV        EAX,0x3
//                              scr_mps.cpp:624 (7)
//         004a11c1     JMP        LAB_004a1200
//                               LAB_004a11c3                                                 XREF[1]:     004a11ba(j)
//         004a11c3     CMP        EDX,0x3
//         004a11c6     JNZ        LAB_004a11cf
//                              scr_mps.cpp:625 (5)
//         004a11c8     MOV        EAX,0x2
//                              scr_mps.cpp:626 (7)
//         004a11cd     JMP        LAB_004a1200
//                               LAB_004a11cf                                                 XREF[1]:     004a11c6(j)
//         004a11cf     CMP        EDX,0x4
//         004a11d2     JNZ        LAB_004a11db
//                              scr_mps.cpp:627 (5)
//         004a11d4     MOV        EAX,0x1
//                              scr_mps.cpp:628 (7)
//         004a11d9     JMP        LAB_004a1200
//                               LAB_004a11db                                                 XREF[1]:     004a11d2(j)
//         004a11db     CMP        EDX,0x5
//         004a11de     JNZ        LAB_004a11e4
//                              scr_mps.cpp:629 (2)
//         004a11e0     MOV        EAX,EDX
//                              scr_mps.cpp:630 (7)
//         004a11e2     JMP        LAB_004a1200
//                               LAB_004a11e4                                                 XREF[1]:     004a11de(j)
//         004a11e4     CMP        EDX,0x6
//         004a11e7     JNZ        LAB_004a11ed
//                              scr_mps.cpp:631 (2)
//         004a11e9     MOV        EAX,EDX
//                              scr_mps.cpp:632 (7)
//         004a11eb     JMP        LAB_004a1200
//                               LAB_004a11ed                                                 XREF[1]:     004a11e7(j)
//         004a11ed     CMP        EDX,0x7
//         004a11f0     JNZ        LAB_004a11f6
//                              scr_mps.cpp:633 (2)
//         004a11f2     MOV        EAX,EDX
//                              scr_mps.cpp:634 (12)
//         004a11f4     JMP        LAB_004a1200
//                               LAB_004a11f6                                                 XREF[1]:     004a11f0(j)
//         004a11f6     XOR        EAX,EAX
//         004a11f8     CMP        EDX,EBX
//         004a11fa     SETNZ      AL
//         004a11fd     DEC        EAX
//         004a11fe     AND        EAX,EBX
//                               LAB_004a1200                                                 XREF[7]:     004a11b8(j), 004a11c1(j),
//                                                                                                         004a11cd(j), 004a11d9(j),
//                                                                                                         004a11e2(j), 004a11eb(j),
//                                                                                                         004a11f4(j)
//                              scr_mps.cpp:638 (12)
//         004a1200     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1206     PUSH       EAX
//         004a1207     CALL       TRIBE_Game::setMapType                           void setMapType(TRIBE_Game * this, MapType pa
//                               LAB_004a120c                                                 XREF[1]:     004a1181(j)
//                              scr_mps.cpp:641 (13)
//         004a120c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1212     PUSH       EBP
//         004a1213     PUSH       EBP
//         004a1214     CALL       TRIBE_Game::setVictoryType                       void setVictoryType(TRIBE_Game * this, Victor
//                              scr_mps.cpp:645 (13)
//         004a1219     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a121f     PUSH       0x4
//         004a1221     CALL       RGE_Base_Game::setNumberPlayers                  void setNumberPlayers(RGE_Base_Game * this, i
//                              scr_mps.cpp:646 (12)
//         004a1226     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a122c     PUSH       EBP
//         004a122d     CALL       RGE_Base_Game::setCampaignGame                   void setCampaignGame(RGE_Base_Game * this, in
//                              scr_mps.cpp:647 (12)
//         004a1232     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1238     PUSH       EBP
//         004a1239     CALL       RGE_Base_Game::setSavedGame                      void setSavedGame(RGE_Base_Game * this, int p
//                              scr_mps.cpp:648 (13)
//         004a123e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1244     PUSH       0x1
//         004a1246     CALL       TRIBE_Game::setAnimals                           void setAnimals(TRIBE_Game * this, int param_1)
//                              scr_mps.cpp:649 (13)
//         004a124b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1251     PUSH       0x1
//         004a1253     CALL       TRIBE_Game::setPredators                         void setPredators(TRIBE_Game * this, int para
//                              scr_mps.cpp:650 (12)
//         004a1258     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a125e     PUSH       EBP
//         004a125f     CALL       RGE_Base_Game::setFullVisibility                 void setFullVisibility(RGE_Base_Game * this,
//                              scr_mps.cpp:651 (13)
//         004a1264     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a126a     PUSH       0x1
//         004a126c     CALL       RGE_Base_Game::setFogOfWar                       void setFogOfWar(RGE_Base_Game * this, int pa
//                              scr_mps.cpp:652 (13)
//         004a1271     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1277     PUSH       0x1
//         004a1279     CALL       RGE_Base_Game::setAllowCheatCodes                void setAllowCheatCodes(RGE_Base_Game * this,
//                              scr_mps.cpp:653 (12)
//         004a127e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1284     PUSH       EBP
//         004a1285     CALL       TRIBE_Game::setRandomizePositions                void setRandomizePositions(TRIBE_Game * this,
//                              scr_mps.cpp:654 (12)
//         004a128a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1290     PUSH       EBP
//         004a1291     CALL       TRIBE_Game::setLongCombat                        void setLongCombat(TRIBE_Game * this, int par
//                              scr_mps.cpp:655 (13)
//         004a1296     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a129c     PUSH       0x1
//         004a129e     CALL       TRIBE_Game::setAllowTrading                      void setAllowTrading(TRIBE_Game * this, int p
//                              scr_mps.cpp:656 (12)
//         004a12a3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12a9     PUSH       EBP
//         004a12aa     CALL       TRIBE_Game::setFullTechTree                      void setFullTechTree(TRIBE_Game * this, int p
//                              scr_mps.cpp:657 (12)
//         004a12af     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12b5     PUSH       EBP
//         004a12b6     CALL       TRIBE_Game::setResourceLevel                     void setResourceLevel(TRIBE_Game * this, Reso
//                              scr_mps.cpp:658 (12)
//         004a12bb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12c1     PUSH       EBP
//         004a12c2     CALL       TRIBE_Game::setStartingAge                       void setStartingAge(TRIBE_Game * this, Age pa
//                              scr_mps.cpp:659 (12)
//         004a12c7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12cd     PUSH       EBP
//         004a12ce     CALL       TRIBE_Game::setStartingUnits                     void setStartingUnits(TRIBE_Game * this, int
//                              scr_mps.cpp:660 (23)
//         004a12d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12d9     CALL       RGE_Base_Game::get_single_player_difficulty      int get_single_player_difficulty(RGE_Base_Gam
//         004a12de     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12e4     PUSH       EAX
//         004a12e5     CALL       RGE_Base_Game::setDifficulty                     void setDifficulty(RGE_Base_Game * this, int
//                              scr_mps.cpp:661 (12)
//         004a12ea     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a12f0     PUSH       EBP
//         004a12f1     CALL       TRIBE_Game::setQuickStartGame                    void setQuickStartGame(TRIBE_Game * this, uch
//                               LAB_004a12f6                                                 XREF[1]:     004a114a(j)
//                              scr_mps.cpp:663 (5)
//         004a12f6     POP        EDI
//         004a12f7     POP        ESI
//         004a12f8     POP        EBP
//         004a12f9     POP        EBX
//         004a12fa     RET
//         004a12fb     ??         90h
//         004a12fc     NOP
//         004a12fd     NOP
//         004a12fe     NOP
//         004a12ff     NOP
    return;
}

TribeMPSetupScreen::~TribeMPSetupScreen() {
    /* TODO: Stub */
//                              void __thiscall ~TribeMPSetupScreen(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a132f(W)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a131b(W)
//                               ??1TribeMPSetupScreen@@UAE@XZ                                XREF[1]:     `vector_deleting_destructor':004a0
//                               TribeMPSetupScreen::~TribeMPSetupScreen
//                              scr_mps.cpp:669 (37)
//         004a1300     PUSH       -0x1
//         004a1302     PUSH       FUN_0055f1b8
//         004a1307     MOV        EAX,FS:[0x0]
//         004a130d     PUSH       EAX
//         004a130e     MOV        dword ptr FS:[0x0],ESP
//         004a1315     PUSH       this
//         004a1316     PUSH       EBX
//         004a1317     PUSH       ESI
//         004a1318     MOV        ESI,this
//         004a131a     PUSH       EDI
//         004a131b     MOV        dword ptr [ESP + local_10],ESI
//         004a131f     MOV        dword ptr [ESI],TribeMPSetupScreen::`vftable'    = 004a0d60
//                              scr_mps.cpp:672 (16)
//         004a1325     MOV        this,dword ptr [ESI + 0x848]
//         004a132b     XOR        EDI,EDI
//         004a132d     CMP        this,EDI
//         004a132f     MOV        dword ptr [ESP + local_4],EDI
//         004a1333     JZ         LAB_004a1342
//                              scr_mps.cpp:674 (7)
//         004a1335     MOV        EAX,dword ptr [this->_padding_]
//         004a1337     PUSH       0x1
//         004a1339     CALL       dword ptr [EAX + 0x4]
//                              scr_mps.cpp:675 (6)
//         004a133c     MOV        dword ptr [ESI + 0x848],EDI
//                               LAB_004a1342                                                 XREF[1]:     004a1333(j)
//                              scr_mps.cpp:678 (15)
//         004a1342     PUSH       s_Game_Settings_Screen                           = 47h
//         004a1347     MOV        this,panel_system
//         004a134c     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:680 (15)
//         004a1351     PUSH       s_Select_Tribe_Screen                            = "Select Tribe Screen"
//         004a1356     MOV        this,panel_system
//         004a135b     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:681 (15)
//         004a1360     PUSH       s_Kick_Dialog                                    = 4Bh
//         004a1365     MOV        this,panel_system
//         004a136a     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:683 (15)
//         004a136f     PUSH       s_OKDialog                                       = 4Fh
//         004a1374     MOV        this,panel_system
//         004a1379     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:684 (15)
//         004a137e     PUSH       s_YesNoDialog                                    = 59h
//         004a1383     MOV        this,panel_system
//         004a1388     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:686 (14)
//         004a138d     LEA        this,[ESI + 0x478]
//         004a1393     PUSH       this
//         004a1394     MOV        this,ESI
//         004a1396     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:687 (14)
//         004a139b     LEA        EDX,[ESI + 0x47c]
//         004a13a1     MOV        this,ESI
//         004a13a3     PUSH       EDX
//         004a13a4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:688 (14)
//         004a13a9     LEA        EAX,[ESI + 0x480]
//         004a13af     MOV        this,ESI
//         004a13b1     PUSH       EAX
//         004a13b2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:689 (14)
//         004a13b7     LEA        this,[ESI + 0x484]
//         004a13bd     PUSH       this
//         004a13be     MOV        this,ESI
//         004a13c0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:690 (14)
//         004a13c5     LEA        EDX,[ESI + 0x488]
//         004a13cb     MOV        this,ESI
//         004a13cd     PUSH       EDX
//         004a13ce     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:691 (25)
//         004a13d3     LEA        EAX,[ESI + 0x48c]
//         004a13d9     MOV        this,ESI
//         004a13db     PUSH       EAX
//         004a13dc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a13e1     LEA        EDI,[ESI + 0x5d0]
//         004a13e7     MOV        EBX,0x8
//                               LAB_004a13ec                                                 XREF[1]:     004a1483(j)
//                              scr_mps.cpp:693 (3)
//         004a13ec     LEA        this,[EDI + -0x20]
//                              scr_mps.cpp:695 (8)
//         004a13ef     PUSH       this
//         004a13f0     MOV        this,ESI
//         004a13f2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:696 (11)
//         004a13f7     PUSH       EDI
//         004a13f8     MOV        this,ESI
//         004a13fa     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a13ff     LEA        EDX,[EDI + 0x20]
//                              scr_mps.cpp:697 (11)
//         004a1402     MOV        this,ESI
//         004a1404     PUSH       EDX
//         004a1405     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a140a     LEA        EAX,[EDI + -0x60]
//                              scr_mps.cpp:699 (11)
//         004a140d     MOV        this,ESI
//         004a140f     PUSH       EAX
//         004a1410     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1415     LEA        this,[EDI + -0x40]
//                              scr_mps.cpp:700 (14)
//         004a1418     PUSH       this
//         004a1419     MOV        this,ESI
//         004a141b     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1420     LEA        EDX,[EDI + 0xfffffec0]
//                              scr_mps.cpp:702 (14)
//         004a1426     MOV        this,ESI
//         004a1428     PUSH       EDX
//         004a1429     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a142e     LEA        EAX,[EDI + 0xfffffee0]
//                              scr_mps.cpp:703 (14)
//         004a1434     MOV        this,ESI
//         004a1436     PUSH       EAX
//         004a1437     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a143c     LEA        this,[EDI + 0xffffff00]
//                              scr_mps.cpp:704 (14)
//         004a1442     PUSH       this
//         004a1443     MOV        this,ESI
//         004a1445     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a144a     LEA        EDX,[EDI + 0xffffff20]
//                              scr_mps.cpp:705 (14)
//         004a1450     MOV        this,ESI
//         004a1452     PUSH       EDX
//         004a1453     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1458     LEA        EAX,[EDI + 0xffffff40]
//                              scr_mps.cpp:706 (14)
//         004a145e     MOV        this,ESI
//         004a1460     PUSH       EAX
//         004a1461     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1466     LEA        this,[EDI + 0xffffff60]
//                              scr_mps.cpp:707 (11)
//         004a146c     PUSH       this
//         004a146d     MOV        this,ESI
//         004a146f     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1474     LEA        EDX,[EDI + -0x80]
//                              scr_mps.cpp:708 (18)
//         004a1477     MOV        this,ESI
//         004a1479     PUSH       EDX
//         004a147a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a147f     ADD        EDI,0x4
//         004a1482     DEC        EBX
//         004a1483     JNZ        LAB_004a13ec
//                              scr_mps.cpp:711 (14)
//         004a1489     LEA        EAX,[ESI + 0x610]
//         004a148f     MOV        this,ESI
//         004a1491     PUSH       EAX
//         004a1492     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:712 (14)
//         004a1497     LEA        this,[ESI + 0x614]
//         004a149d     PUSH       this
//         004a149e     MOV        this,ESI
//         004a14a0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:713 (14)
//         004a14a5     LEA        EDX,[ESI + 0x618]
//         004a14ab     MOV        this,ESI
//         004a14ad     PUSH       EDX
//         004a14ae     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:715 (14)
//         004a14b3     LEA        EAX,[ESI + 0x620]
//         004a14b9     MOV        this,ESI
//         004a14bb     PUSH       EAX
//         004a14bc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:717 (14)
//         004a14c1     LEA        this,[ESI + 0x624]
//         004a14c7     PUSH       this
//         004a14c8     MOV        this,ESI
//         004a14ca     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:718 (14)
//         004a14cf     LEA        EDX,[ESI + 0x628]
//         004a14d5     MOV        this,ESI
//         004a14d7     PUSH       EDX
//         004a14d8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:753 (349)
//         004a14dd     LEA        EDI,[ESI + 0x67c]
//         004a14e3     MOV        EBX,0x14
//                               LAB_004a14e8                                                 XREF[1]:     004a14ff(j)
//         004a14e8     LEA        EAX,[EDI + -0x50]
//         004a14eb     MOV        this,ESI
//         004a14ed     PUSH       EAX
//         004a14ee     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a14f3     PUSH       EDI
//         004a14f4     MOV        this,ESI
//         004a14f6     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a14fb     ADD        EDI,0x4
//         004a14fe     DEC        EBX
//         004a14ff     JNZ        LAB_004a14e8
//         004a1501     LEA        this,[ESI + 0x6cc]
//         004a1507     PUSH       this
//         004a1508     MOV        this,ESI
//         004a150a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a150f     LEA        EDX,[ESI + 0x6d0]
//         004a1515     MOV        this,ESI
//         004a1517     PUSH       EDX
//         004a1518     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a151d     LEA        EAX,[ESI + 0x6d4]
//         004a1523     MOV        this,ESI
//         004a1525     PUSH       EAX
//         004a1526     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a152b     LEA        this,[ESI + 0x6d8]
//         004a1531     PUSH       this
//         004a1532     MOV        this,ESI
//         004a1534     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1539     LEA        EDX,[ESI + 0x6dc]
//         004a153f     MOV        this,ESI
//         004a1541     PUSH       EDX
//         004a1542     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1547     LEA        EAX,[ESI + 0x6e0]
//         004a154d     MOV        this,ESI
//         004a154f     PUSH       EAX
//         004a1550     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1555     LEA        this,[ESI + 0x6e4]
//         004a155b     PUSH       this
//         004a155c     MOV        this,ESI
//         004a155e     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1563     LEA        EDX,[ESI + 0x6e8]
//         004a1569     MOV        this,ESI
//         004a156b     PUSH       EDX
//         004a156c     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1571     LEA        EAX,[ESI + 0x6ec]
//         004a1577     MOV        this,ESI
//         004a1579     PUSH       EAX
//         004a157a     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a157f     LEA        this,[ESI + 0x6f0]
//         004a1585     PUSH       this
//         004a1586     MOV        this,ESI
//         004a1588     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a158d     LEA        EDX,[ESI + 0x6f4]
//         004a1593     MOV        this,ESI
//         004a1595     PUSH       EDX
//         004a1596     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a159b     LEA        EAX,[ESI + 0x6f8]
//         004a15a1     MOV        this,ESI
//         004a15a3     PUSH       EAX
//         004a15a4     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15a9     LEA        this,[ESI + 0x6fc]
//         004a15af     PUSH       this
//         004a15b0     MOV        this,ESI
//         004a15b2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15b7     LEA        EDX,[ESI + 0x700]
//         004a15bd     MOV        this,ESI
//         004a15bf     PUSH       EDX
//         004a15c0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15c5     LEA        EAX,[ESI + 0x70c]
//         004a15cb     MOV        this,ESI
//         004a15cd     PUSH       EAX
//         004a15ce     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15d3     LEA        this,[ESI + 0x718]
//         004a15d9     PUSH       this
//         004a15da     MOV        this,ESI
//         004a15dc     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15e1     LEA        EDX,[ESI + 0x714]
//         004a15e7     MOV        this,ESI
//         004a15e9     PUSH       EDX
//         004a15ea     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15ef     LEA        EAX,[ESI + 0x71c]
//         004a15f5     MOV        this,ESI
//         004a15f7     PUSH       EAX
//         004a15f8     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a15fd     LEA        this,[ESI + 0x858]
//         004a1603     PUSH       this
//         004a1604     MOV        this,ESI
//         004a1606     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a160b     LEA        EDX,[ESI + 0x710]
//         004a1611     MOV        this,ESI
//         004a1613     PUSH       EDX
//         004a1614     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a1619     MOV        dword ptr [ESP + 0x18],0xffffffff
//         004a1621     MOV        this,ESI
//         004a1623     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         004a1628     MOV        this,dword ptr [ESP + 0x10]
//         004a162c     POP        EDI
//         004a162d     POP        ESI
//         004a162e     MOV        dword ptr FS:[0x0],this
//         004a1635     POP        EBX
//         004a1636     ADD        ESP,0x10
//         004a1639     RET
//         004a163a     ??         90h
//         004a163b     NOP
//         004a163c     NOP
//         004a163d     NOP
//         004a163e     NOP
//         004a163f     NOP
}

long TribeMPSetupScreen::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TribeMPSetupScreen * this)
//              long              EAX:4          <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//                               ?handle_idle@TribeMPSetupScreen@@UAEJXZ                      XREF[1]:     00573314(*)
//                               TribeMPSetupScreen::handle_idle
//                              scr_mps.cpp:759 (3)
//         004a1640     PUSH       ESI
//         004a1641     MOV        ESI,this
//                              scr_mps.cpp:760 (16)
//         004a1643     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1649     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004a164f     TEST       EAX,EAX
//         004a1651     JNZ        LAB_004a165e
//                              scr_mps.cpp:761 (11)
//         004a1653     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
//         004a1658     MOV        this,dword ptr [rge_base_game]                   = 00000000
//                               LAB_004a165e                                                 XREF[1]:     004a1651(j)
//                              scr_mps.cpp:763 (9)
//         004a165e     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a1663     TEST       EAX,EAX
//         004a1665     JZ         LAB_004a16b9
//                              scr_mps.cpp:765 (10)
//         004a1667     MOV        EAX,dword ptr [ESI + 0x888]
//         004a166d     TEST       EAX,EAX
//         004a166f     JNZ        LAB_004a1678
//                              scr_mps.cpp:766 (5)
//         004a1671     PUSH       0x2fe
//                              scr_mps.cpp:767 (2)
//         004a1676     JMP        LAB_004a16a6
//                               LAB_004a1678                                                 XREF[1]:     004a166f(j)
//                              scr_mps.cpp:769 (28)
//         004a1678     PUSH       0x301
//         004a167d     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a1682     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004a1687     MOV        this,dword ptr [ESI + 0x888]
//         004a168d     ADD        ESP,0x8
//         004a1690     SUB        EAX,this
//         004a1692     JZ         LAB_004a16b9
//                              scr_mps.cpp:771 (13)
//         004a1694     MOV        this,dword ptr [comm]                            = 00000000
//         004a169a     PUSH       0x0
//         004a169c     CALL       TCommunications_Handler::SendSharedData          long SendSharedData(TCommunications_Handler *
//                              scr_mps.cpp:772 (24)
//         004a16a1     PUSH       0x304
//                               LAB_004a16a6                                                 XREF[1]:     004a1676(j)
//         004a16a6     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a16ab     CALL       debug_timeGetTime                                ulong debug_timeGetTime(char * param_1, int p
//         004a16b0     ADD        ESP,0x8
//         004a16b3     MOV        dword ptr [ESI + 0x888],EAX
//                               LAB_004a16b9                                                 XREF[2]:     004a1665(j), 004a1692(j)
//                              scr_mps.cpp:777 (7)
//         004a16b9     MOV        this,ESI
//         004a16bb     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              scr_mps.cpp:778 (2)
//         004a16c0     POP        ESI
//         004a16c1     RET
//         004a16c2     ??         90h
//         004a16c3     NOP
//         004a16c4     NOP
//         004a16c5     NOP
//         004a16c6     NOP
//         004a16c7     NOP
//         004a16c8     NOP
//         004a16c9     NOP
//         004a16ca     NOP
//         004a16cb     NOP
//         004a16cc     NOP
//         004a16cd     NOP
//         004a16ce     NOP
//         004a16cf     NOP
    return 0;
}

long TribeMPSetupScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              long __thiscall key_down_action(TribeMPSetupScreen * this, long para
//              long              EAX:4          <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1
//              short             Stack[0x8]:2   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?key_down_action@TribeMPSetupScreen@@UAEJJFHHH@Z             XREF[1]:     00573374(*)
//                               TribeMPSetupScreen::key_down_action
//                              scr_mps.cpp:784 (2)
//         004a16d0     XOR        EAX,EAX
//                              scr_mps.cpp:806 (3)
//         004a16d2     RET        0x14
//         004a16d5     ??         90h
//         004a16d6     NOP
//         004a16d7     NOP
//         004a16d8     NOP
//         004a16d9     NOP
//         004a16da     NOP
//         004a16db     NOP
//         004a16dc     NOP
//         004a16dd     NOP
//         004a16de     NOP
//         004a16df     NOP
    return 0;
}

long TribeMPSetupScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TribeMPSetupScreen * this, TPanel * param_1,
//              long              EAX:4          <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a16fc(R)
//              long              Stack[0x8]:4   param_2                   XREF[6]:     004a1716(R), 004a1c5f(R), 004a1cb0(R), 004a1d03(R),
//                                                                                     004a1d90(R), 004a1f80(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004a1f79(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004a1f72(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a1aa0(W), 004a1ab4(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a1f92(R)
//              _finddata_t       Stack[-0x128   file_info                 XREF[0,1]:   004a188c(*)
//              char[260]         Stack[-0x22c   file_name                 XREF[1,5]:   004a1a9a(W), 004a187a(*), 004a1893(*), 004a18b2(*),
//                                                                                     004a18c4(*), 004a18dc(*)
//                               ?action@TribeMPSetupScreen@@UAEJPAVTPanel@@JKK@Z             XREF[1]:     0057337c(*)
//                               TribeMPSetupScreen::action
//                              scr_mps.cpp:812 (28)
//         004a16e0     MOV        EAX,FS:[0x0]
//         004a16e6     PUSH       -0x1
//         004a16e8     PUSH       FUN_0055f1de
//         004a16ed     PUSH       EAX
//         004a16ee     MOV        dword ptr FS:[0x0],ESP
//         004a16f5     SUB        ESP,0x220
//         004a16fb     PUSH       EBX
//                              scr_mps.cpp:816 (20)
//         004a16fc     MOV        EBX,dword ptr [ESP + param_1]
//         004a1703     PUSH       EBP
//         004a1704     PUSH       ESI
//         004a1705     TEST       EBX,EBX
//         004a1707     PUSH       EDI
//         004a1708     MOV        ESI,this
//         004a170a     JZ         LAB_004a1f72
//                              scr_mps.cpp:818 (22)
//         004a1710     MOV        EAX,dword ptr [ESI + 0x700]
//         004a1716     MOV        EBP,dword ptr [ESP + param_2]
//         004a171d     CMP        EBX,EAX
//         004a171f     JNZ        LAB_004a1750
//         004a1721     CMP        EBP,0x1
//         004a1724     JNZ        LAB_004a1750
//                              scr_mps.cpp:820 (17)
//         004a1726     MOV        EAX,dword ptr [ESI + 0x610]
//         004a172c     TEST       EAX,EAX
//         004a172e     JZ         LAB_004a173f
//         004a1730     MOV        this,dword ptr [EAX + 0x6c]
//         004a1733     TEST       this,this
//         004a1735     JZ         LAB_004a173f
//                              scr_mps.cpp:821 (8)
//         004a1737     PUSH       EAX
//         004a1738     MOV        this,ESI
//         004a173a     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_004a173f                                                 XREF[2]:     004a172e(j), 004a1735(j)
//                              scr_mps.cpp:822 (7)
//         004a173f     MOV        this,ESI
//         004a1741     CALL       TribeMPSetupScreen::startGame                    int startGame(TribeMPSetupScreen * this)
//                              scr_mps.cpp:823 (10)
//         004a1746     MOV        EAX,0x1
//         004a174b     JMP        LAB_004a1f92
//                               LAB_004a1750                                                 XREF[2]:     004a171f(j), 004a1724(j)
//                              scr_mps.cpp:826 (23)
//         004a1750     MOV        this,dword ptr [ESI + 0x714]
//         004a1756     CMP        EBX,this
//         004a1758     JNZ        LAB_004a1a41
//         004a175e     CMP        EBP,0x1
//         004a1761     JNZ        LAB_004a1a41
//                              scr_mps.cpp:828 (13)
//         004a1767     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004a176c     TEST       EAX,EAX
//         004a176e     JZ         LAB_004a195f
//                              scr_mps.cpp:830 (16)
//         004a1774     MOV        EAX,[L]                                          = 00000000
//         004a1779     PUSH       s_$$$_SELECTED_I'M_READY                         = "$$$ SELECTED I'M READY"
//         004a177e     PUSH       EAX
//         004a177f     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:831 (16)
//         004a1784     MOV        this,dword ptr [comm]                            = 00000000
//         004a178a     ADD        ESP,0x8
//         004a178d     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a1792     TEST       EAX,EAX
//                              scr_mps.cpp:833 (16)
//         004a1794     PUSH       0x0
//         004a1796     JZ         LAB_004a17a9
//         004a1798     PUSH       0x0
//         004a179a     PUSH       0x0
//         004a179c     PUSH       0x0
//         004a179e     PUSH       0x0
//         004a17a0     PUSH       0x0
//         004a17a2     PUSH       0x0
//                              scr_mps.cpp:835 (5)
//         004a17a4     JMP        LAB_004a192d
//                               LAB_004a17a9                                                 XREF[1]:     004a1796(j)
//                              scr_mps.cpp:838 (15)
//         004a17a9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a17af     CALL       RGE_Base_Game::playerVersion                     uchar playerVersion(RGE_Base_Game * this, int
//         004a17b4     CMP        AL,0x1
//         004a17b6     JZ         LAB_004a17e7
//                              scr_mps.cpp:840 (16)
//         004a17b8     MOV        this,dword ptr [ESI + 0x714]
//         004a17be     PUSH       0x0
//         004a17c0     MOV        EDX,dword ptr [this->_padding_]
//         004a17c2     CALL       dword ptr [EDX + 0xe0]
//                              scr_mps.cpp:841 (21)
//         004a17c8     PUSH       0x64
//         004a17ca     PUSH       offset DAT_fffffff8
//         004a17cf     PUSH       0x0=>DAT_fffffff4
//                              language.dll match for 0x25e3: "The host is not running versi
//         004a17d1     PUSH       offset DAT_fffffff0
//         004a17d6     MOV        this,ESI
//         004a17d8     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_mps.cpp:842 (10)
//         004a17dd     MOV        EAX,0x1
//         004a17e2     JMP        LAB_004a1f92
//                               LAB_004a17e7                                                 XREF[1]:     004a17b6(j)
//                              scr_mps.cpp:845 (13)
//         004a17e7     MOV        this,dword ptr [comm]                            = 00000000
//         004a17ed     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a17f2     MOV        EDI,EAX
//                              scr_mps.cpp:847 (17)
//         004a17f4     MOV        EAX,[L]                                          = 00000000
//         004a17f9     PUSH       s_$$$_SAVING_MYCIV_&_MYTEAM                      = "$$$ SAVING MYCIV & MYTEAM"
//         004a17fe     PUSH       EAX
//         004a17ff     DEC        EDI
//         004a1800     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:848 (21)
//         004a1805     MOV        this,dword ptr [ESI + EDI*0x4 + 0x5d0]
//         004a180c     ADD        ESP,0x8
//         004a180f     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1814     MOV        dword ptr [ESI + 0x72c],EAX
//                              scr_mps.cpp:849 (18)
//         004a181a     MOV        this,dword ptr [ESI + EDI*0x4 + 0x5f0]
//         004a1821     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1826     MOV        dword ptr [ESI + 0x730],EAX
//                              scr_mps.cpp:850 (18)
//         004a182c     MOV        this,dword ptr [ESI + EDI*0x4 + 0x570]
//         004a1833     CALL       TButtonPanel::get_id                             long get_id(TButtonPanel * this)
//         004a1838     MOV        dword ptr [ESI + 0x734],EAX
//                              scr_mps.cpp:851 (19)
//         004a183e     MOV        this,dword ptr [ESI + EDI*0x4 + 0x590]
//         004a1845     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004a184a     INC        EAX
//         004a184b     MOV        dword ptr [ESI + 0x738],EAX
//                              scr_mps.cpp:853 (19)
//         004a1851     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1857     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a185c     TEST       EAX,EAX
//         004a185e     JZ         LAB_004a18ee
//                              scr_mps.cpp:859 (40)
//         004a1864     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a186a     MOV        EDI,dword ptr [ECX + this->_padding_]
//         004a186d     ADD        EDI,0xc17
//         004a1873     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a1878     PUSH       EAX
//         004a1879     PUSH       EDI
//         004a187a     LEA        this=>file_name[4],[ESP + 0x1c]
//         004a187e     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         004a1883     PUSH       this
//         004a1884     CALL       sprintf                                          undefined sprintf()
//         004a1889     ADD        ESP,0x10
//                              scr_mps.cpp:860 (18)
//         004a188c     LEA        EDX=>file_info.time_create,[ESP + 0x118]
//         004a1893     LEA        EAX=>file_name[4],[ESP + 0x14]
//         004a1897     PUSH       EDX
//         004a1898     PUSH       EAX
//         004a1899     CALL       __findfirst                                      undefined __findfirst()
//                              scr_mps.cpp:862 (30)
//         004a189e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a18a4     ADD        ESP,0x8
//         004a18a7     CMP        EAX,-0x1
//         004a18aa     JNZ        LAB_004a18be
//         004a18ac     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a18b1     PUSH       EAX
//         004a18b2     LEA        this=>file_name[4],[ESP + 0x18]
//         004a18b6     PUSH       s_%s.scx                                         = "%s.scx"
//         004a18bb     PUSH       this
//                              scr_mps.cpp:863 (2)
//         004a18bc     JMP        LAB_004a18ce
//                               LAB_004a18be                                                 XREF[1]:     004a18aa(j)
//                              scr_mps.cpp:864 (21)
//         004a18be     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a18c3     PUSH       EAX
//         004a18c4     LEA        EDX=>file_name[4],[ESP + 0x18]
//         004a18c8     PUSH       s_%s.scn                                         = "%s.scn"
//         004a18cd     PUSH       EDX
//                               LAB_004a18ce                                                 XREF[1]:     004a18bc(j)
//         004a18ce     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:866 (25)
//         004a18d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a18d9     ADD        ESP,0xc
//         004a18dc     LEA        EAX=>file_name[4],[ESP + 0x14]
//         004a18e0     PUSH       EAX
//         004a18e1     CALL       RGE_Base_Game::get_scenario_checksum             long get_scenario_checksum(RGE_Base_Game * th
//         004a18e6     MOV        dword ptr [ESI + 0x73c],EAX
//                              scr_mps.cpp:868 (2)
//         004a18ec     JMP        LAB_004a18f8
//                               LAB_004a18ee                                                 XREF[1]:     004a185e(j)
//                              scr_mps.cpp:869 (10)
//         004a18ee     MOV        dword ptr [ESI + 0x73c],0x0
//                               LAB_004a18f8                                                 XREF[1]:     004a18ec(j)
//                              scr_mps.cpp:871 (66)
//         004a18f8     MOV        this,dword ptr [ESI + 0x73c]
//         004a18fe     MOV        EDX,dword ptr [ESI + 0x738]
//         004a1904     MOV        EAX,dword ptr [ESI + 0x734]
//         004a190a     PUSH       0x1
//         004a190c     PUSH       this
//         004a190d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1913     PUSH       EDX
//         004a1914     PUSH       EAX
//         004a1915     PUSH       0x0
//         004a1917     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         004a191c     MOV        this,dword ptr [ESI + 0x730]
//         004a1922     MOV        EDX,dword ptr [ESI + 0x72c]
//         004a1928     INC        EAX
//         004a1929     INC        this
//         004a192a     PUSH       EAX
//         004a192b     PUSH       this
//         004a192c     PUSH       EDX
//                               LAB_004a192d                                                 XREF[1]:     004a17a4(j)
//         004a192d     MOV        this,dword ptr [comm]                            = 00000000
//         004a1933     PUSH       0x1
//         004a1935     CALL       TCommunications_Handler::SetMyReadiness          int SetMyReadiness(TCommunications_Handler *
//                              scr_mps.cpp:874 (17)
//         004a193a     MOV        EAX,dword ptr [ESI + 0x610]
//         004a1940     TEST       EAX,EAX
//         004a1942     JZ         LAB_004a1953
//         004a1944     MOV        this,dword ptr [EAX + 0x6c]
//         004a1947     TEST       this,this
//         004a1949     JZ         LAB_004a1953
//                              scr_mps.cpp:875 (8)
//         004a194b     PUSH       EAX
//         004a194c     MOV        this,ESI
//         004a194e     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_004a1953                                                 XREF[2]:     004a1942(j), 004a1949(j)
//                              scr_mps.cpp:876 (10)
//         004a1953     MOV        dword ptr [ESI + 0x85c],0x1
//                              scr_mps.cpp:879 (2)
//         004a195d     JMP        LAB_004a19d0
//                               LAB_004a195f                                                 XREF[1]:     004a176e(j)
//                              scr_mps.cpp:881 (16)
//         004a195f     MOV        EAX,[L]                                          = 00000000
//         004a1964     PUSH       s_$$$_SELECTED_NOT_READY                         = "$$$ SELECTED NOT READY"
//         004a1969     PUSH       EAX
//         004a196a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:882 (62)
//         004a196f     MOV        this,dword ptr [comm]                            = 00000000
//         004a1975     ADD        ESP,0x8
//         004a1978     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a197d     TEST       EAX,EAX
//         004a197f     JZ         LAB_004a1985
//         004a1981     XOR        EAX,EAX
//         004a1983     JMP        LAB_004a1993
//                               LAB_004a1985                                                 XREF[1]:     004a197f(j)
//         004a1985     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a198b     PUSH       0x0
//         004a198d     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         004a1992     INC        EAX
//                               LAB_004a1993                                                 XREF[1]:     004a1983(j)
//         004a1993     MOV        this,dword ptr [comm]                            = 00000000
//         004a1999     PUSH       0x0
//         004a199b     PUSH       0x0
//         004a199d     PUSH       0x0
//         004a199f     PUSH       0x0
//         004a19a1     PUSH       EAX
//         004a19a2     PUSH       0x0
//         004a19a4     PUSH       0x0
//         004a19a6     PUSH       0x0
//         004a19a8     CALL       TCommunications_Handler::SetMyReadiness          int SetMyReadiness(TCommunications_Handler *
//                              scr_mps.cpp:883 (17)
//         004a19ad     MOV        EAX,dword ptr [ESI + 0x610]
//         004a19b3     TEST       EAX,EAX
//         004a19b5     JZ         LAB_004a19c6
//         004a19b7     MOV        this,dword ptr [EAX + 0x6c]
//         004a19ba     TEST       this,this
//         004a19bc     JZ         LAB_004a19c6
//                              scr_mps.cpp:884 (8)
//         004a19be     PUSH       EAX
//         004a19bf     MOV        this,ESI
//         004a19c1     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_004a19c6                                                 XREF[2]:     004a19b5(j), 004a19bc(j)
//                              scr_mps.cpp:885 (10)
//         004a19c6     MOV        dword ptr [ESI + 0x85c],0x0
//                               LAB_004a19d0                                                 XREF[1]:     004a195d(j)
//                              scr_mps.cpp:886 (7)
//         004a19d0     MOV        this,ESI
//         004a19d2     CALL       TribeMPSetupScreen::fillPlayers                  void fillPlayers(TribeMPSetupScreen * this)
//                              scr_mps.cpp:889 (19)
//         004a19d7     MOV        this,dword ptr [comm]                            = 00000000
//         004a19dd     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a19e2     TEST       EAX,EAX
//         004a19e4     JZ         LAB_004a1f6b
//                              scr_mps.cpp:891 (18)
//         004a19ea     MOV        this,dword ptr [ESI + 0x85c]
//         004a19f0     PUSH       this
//         004a19f1     MOV        this,dword ptr [ESI + 0x620]
//         004a19f7     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                              scr_mps.cpp:892 (25)
//         004a19fc     MOV        EDI,dword ptr [ESI + 0x85c]
//         004a1a02     MOV        this,dword ptr [ESI + 0x700]
//         004a1a08     XOR        EDX,EDX
//         004a1a0a     TEST       EDI,EDI
//         004a1a0c     SETZ       DL
//         004a1a0f     PUSH       EDX
//         004a1a10     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                              scr_mps.cpp:893 (11)
//         004a1a15     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1a1b     MOV        EAX,dword ptr [this->_padding_]
//         004a1a1d     CALL       dword ptr [EAX + 0x48]
//                              scr_mps.cpp:894 (10)
//         004a1a20     MOV        dword ptr [ESI + 0x88c],0x0
//                              scr_mps.cpp:895 (13)
//         004a1a2a     MOV        this,dword ptr [comm]                            = 00000000
//         004a1a30     PUSH       0x1
//         004a1a32     CALL       TCommunications_Handler::SendSharedData          long SendSharedData(TCommunications_Handler *
//                              scr_mps.cpp:898 (10)
//         004a1a37     MOV        EAX,0x1
//         004a1a3c     JMP        LAB_004a1f92
//                               LAB_004a1a41                                                 XREF[2]:     004a1758(j), 004a1761(j)
//                              scr_mps.cpp:901 (21)
//         004a1a41     CMP        EBX,dword ptr [ESI + 0x620]
//         004a1a47     JNZ        LAB_004a1ada
//         004a1a4d     CMP        EBP,0x1
//         004a1a50     JNZ        LAB_004a1ada
//                              scr_mps.cpp:903 (17)
//         004a1a56     MOV        EAX,dword ptr [ESI + 0x610]
//         004a1a5c     TEST       EAX,EAX
//         004a1a5e     JZ         LAB_004a1a6f
//         004a1a60     MOV        this,dword ptr [EAX + 0x6c]
//         004a1a63     TEST       this,this
//         004a1a65     JZ         LAB_004a1a6f
//                              scr_mps.cpp:904 (8)
//         004a1a67     PUSH       EAX
//         004a1a68     MOV        this,ESI
//         004a1a6a     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_004a1a6f                                                 XREF[2]:     004a1a5e(j), 004a1a65(j)
//                              scr_mps.cpp:905 (19)
//         004a1a6f     PUSH       s_Game_Settings_Screen                           = 47h
//         004a1a74     MOV        this,panel_system
//         004a1a79     CALL       TPanelSystem::panel                              TPanel * panel(TPanelSystem * this, char * pa
//         004a1a7e     TEST       EAX,EAX
//         004a1a80     JNZ        LAB_004a1abf
//                              scr_mps.cpp:907 (11)
//         004a1a82     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1a88     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
//                              scr_mps.cpp:908 (50)
//         004a1a8d     PUSH       0x560
//         004a1a92     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a1a97     ADD        ESP,0x4
//         004a1a9a     MOV        dword ptr [ESP + file_name[0]],EAX
//         004a1a9e     TEST       EAX,EAX
//         004a1aa0     MOV        dword ptr [ESP + local_4],0x0
//         004a1aab     JZ         LAB_004a1ab4
//         004a1aad     MOV        this,EAX
//         004a1aaf     CALL       TribeGameSettingsScreen::TribeGameSettingsScreen undefined TribeGameSettingsScreen(TribeGameSe
//                               LAB_004a1ab4                                                 XREF[1]:     004a1aab(j)
//         004a1ab4     MOV        dword ptr [ESP + local_4],0xffffffff
//                               LAB_004a1abf                                                 XREF[1]:     004a1a80(j)
//                              scr_mps.cpp:910 (17)
//         004a1abf     PUSH       0x0
//         004a1ac1     PUSH       s_Game_Settings_Screen                           = 47h
//         004a1ac6     MOV        this,panel_system
//         004a1acb     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              scr_mps.cpp:911 (10)
//         004a1ad0     MOV        EAX,0x1
//         004a1ad5     JMP        LAB_004a1f92
//                               LAB_004a1ada                                                 XREF[2]:     004a1a47(j), 004a1a50(j)
//                              scr_mps.cpp:915 (13)
//         004a1ada     CMP        EBX,dword ptr [ESI + 0x710]
//         004a1ae0     JNZ        LAB_004a1af5
//         004a1ae2     CMP        EBP,0x1
//         004a1ae5     JNZ        LAB_004a1af5
//                              scr_mps.cpp:917 (7)
//         004a1ae7     MOV        this,ESI
//         004a1ae9     CALL       TEasy_Panel::setup_popup_help                    void setup_popup_help(TEasy_Panel * this)
//                              scr_mps.cpp:918 (7)
//         004a1aee     MOV        EAX,EBP
//         004a1af0     JMP        LAB_004a1f92
//                               LAB_004a1af5                                                 XREF[2]:     004a1ae0(j), 004a1ae5(j)
//                              scr_mps.cpp:922 (13)
//         004a1af5     CMP        EBX,dword ptr [ESI + 0x718]
//         004a1afb     JNZ        LAB_004a1b14
//         004a1afd     CMP        EBP,0x1
//         004a1b00     JNZ        LAB_004a1b14
//                              scr_mps.cpp:924 (11)
//         004a1b02     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1b08     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              scr_mps.cpp:925 (7)
//         004a1b0d     MOV        EAX,EBP
//         004a1b0f     JMP        LAB_004a1f92
//                               LAB_004a1b14                                                 XREF[2]:     004a1afb(j), 004a1b00(j)
//                              scr_mps.cpp:930 (13)
//         004a1b14     CMP        EBX,dword ptr [ESI + 0x70c]
//         004a1b1a     JNZ        LAB_004a1b4d
//         004a1b1c     CMP        EBP,0x1
//         004a1b1f     JNZ        LAB_004a1b4d
//                              scr_mps.cpp:932 (17)
//         004a1b21     MOV        EAX,dword ptr [ESI + 0x610]
//         004a1b27     TEST       EAX,EAX
//         004a1b29     JZ         LAB_004a1b3a
//         004a1b2b     MOV        this,dword ptr [EAX + 0x6c]
//         004a1b2e     TEST       this,this
//         004a1b30     JZ         LAB_004a1b3a
//                              scr_mps.cpp:933 (8)
//         004a1b32     PUSH       EAX
//         004a1b33     MOV        this,ESI
//         004a1b35     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                               LAB_004a1b3a                                                 XREF[2]:     004a1b29(j), 004a1b30(j)
//                              scr_mps.cpp:934 (9)
//         004a1b3a     PUSH       0x0
//         004a1b3c     MOV        this,ESI
//         004a1b3e     CALL       TribeMPSetupScreen::cancelScreen                 void cancelScreen(TribeMPSetupScreen * this,
//                              scr_mps.cpp:935 (10)
//         004a1b43     MOV        EAX,0x1
//         004a1b48     JMP        LAB_004a1f92
//                               LAB_004a1b4d                                                 XREF[2]:     004a1b1a(j), 004a1b1f(j)
//                              scr_mps.cpp:939 (13)
//         004a1b4d     CMP        EBX,dword ptr [ESI + 0x858]
//         004a1b53     JNZ        LAB_004a1b68
//         004a1b55     CMP        EBP,0x1
//         004a1b58     JNZ        LAB_004a1b8f
//                              scr_mps.cpp:941 (7)
//         004a1b5a     MOV        this,ESI
//         004a1b5c     CALL       TribeMPSetupScreen::showNetInfo                  void showNetInfo(TribeMPSetupScreen * this)
//                              scr_mps.cpp:942 (7)
//         004a1b61     MOV        EAX,EBP
//         004a1b63     JMP        LAB_004a1f92
//                               LAB_004a1b68                                                 XREF[1]:     004a1b53(j)
//                              scr_mps.cpp:946 (5)
//         004a1b68     CMP        EBP,0x1
//         004a1b6b     JNZ        LAB_004a1b8f
//                              scr_mps.cpp:948 (2)
//         004a1b6d     XOR        EDI,EDI
//                              scr_mps.cpp:1134 (32)
//         004a1b6f     LEA        EAX,[ESI + 0x590]
//                               LAB_004a1b75                                                 XREF[1]:     004a1b8d(j)
//         004a1b75     CMP        EBX,dword ptr [EAX + -0x20]
//         004a1b78     JZ         LAB_004a1fad
//         004a1b7e     CMP        EBX,dword ptr [EAX]
//         004a1b80     JZ         LAB_004a1ffd
//         004a1b86     INC        EDI
//         004a1b87     ADD        EAX,0x4
//         004a1b8a     CMP        EDI,0x8
//         004a1b8d     JL         LAB_004a1b75
//                               LAB_004a1b8f                                                 XREF[2]:     004a1b58(j), 004a1b6b(j)
//                              scr_mps.cpp:988 (39)
//         004a1b8f     MOV        this,dword ptr [ESI + 0x610]
//         004a1b95     CMP        EBX,this
//         004a1b97     JNZ        LAB_004a1be7
//         004a1b99     TEST       EBP,EBP
//         004a1b9b     JNZ        LAB_004a1be7
//         004a1b9d     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004a1ba2     TEST       EAX,EAX
//         004a1ba4     JZ         LAB_004a1be7
//         004a1ba6     MOV        this,dword ptr [ESI + 0x610]
//         004a1bac     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004a1bb1     CMP        byte ptr [EAX],0x0
//         004a1bb4     JZ         LAB_004a1be7
//                              scr_mps.cpp:990 (23)
//         004a1bb6     MOV        this,dword ptr [ESI + 0x610]
//         004a1bbc     CALL       TEditPanel::currentLine                          char * currentLine(TEditPanel * this)
//         004a1bc1     MOV        this,dword ptr [comm]                            = 00000000
//         004a1bc7     PUSH       EAX
//         004a1bc8     CALL       TCommunications_Handler::SendChatMsgAll          void SendChatMsgAll(TCommunications_Handler *
//                              scr_mps.cpp:991 (16)
//         004a1bcd     MOV        this,dword ptr [ESI + 0x610]
//         004a1bd3     PUSH       s_                                               = ""
//         004a1bd8     CALL       TEditPanel::set_text                             void set_text(TEditPanel * this, char * param
//                              scr_mps.cpp:992 (10)
//         004a1bdd     MOV        EAX,0x1
//         004a1be2     JMP        LAB_004a1f92
//                               LAB_004a1be7                                                 XREF[4]:     004a1b97(j), 004a1b9b(j),
//                                                                                                         004a1ba4(j), 004a1bb4(j)
//                              scr_mps.cpp:996 (14)
//         004a1be7     MOV        this,dword ptr [ESI + 0x6e0]
//         004a1bed     CMP        EBX,this
//         004a1bef     JNZ        LAB_004a1c17
//         004a1bf1     TEST       EBP,EBP
//         004a1bf3     JNZ        LAB_004a1c17
//                              scr_mps.cpp:998 (5)
//         004a1bf5     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//                              scr_mps.cpp:999 (12)
//         004a1bfa     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1c00     PUSH       EAX
//         004a1c01     CALL       RGE_Base_Game::setNumberPlayers                  void setNumberPlayers(RGE_Base_Game * this, i
//                              scr_mps.cpp:1000 (7)
//         004a1c06     MOV        this,ESI
//         004a1c08     CALL       TribeMPSetupScreen::updateSummary                void updateSummary(TribeMPSetupScreen * this)
//                              scr_mps.cpp:1001 (10)
//         004a1c0d     MOV        EAX,0x1
//         004a1c12     JMP        LAB_004a1f92
//                               LAB_004a1c17                                                 XREF[2]:     004a1bef(j), 004a1bf3(j)
//                              scr_mps.cpp:1006 (72)
//         004a1c17     MOV        this,EBX
//         004a1c19     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         004a1c1e     TEST       EAX,EAX
//         004a1c20     JZ         LAB_004a1cb7
//         004a1c26     MOV        this,EBX
//         004a1c28     MOV        EDI,s_Game_Settings_Screen                       = 47h
//         004a1c2d     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_004a1c32                                                 XREF[1]:     004a1c50(j)
//         004a1c32     MOV        DL,byte ptr [EAX]
//         004a1c34     MOV        this,DL
//         004a1c36     CMP        DL,byte ptr [EDI]=>s_Game_Settings_Screen        = 47h
//                                                                                  = 6Dh
//         004a1c38     JNZ        LAB_004a1c56
//         004a1c3a     TEST       this,this
//         004a1c3c     JZ         LAB_004a1c52
//         004a1c3e     MOV        DL,byte ptr [EAX + 0x1]
//         004a1c41     MOV        this,DL
//         004a1c43     CMP        DL,byte ptr [EDI + 0x1]=>DAT_00586809            = 61h
//                                                                                  = "e Settings Screen"
//         004a1c46     JNZ        LAB_004a1c56
//         004a1c48     ADD        EAX,0x2
//         004a1c4b     ADD        EDI,0x2
//         004a1c4e     TEST       this,this
//         004a1c50     JNZ        LAB_004a1c32
//                               LAB_004a1c52                                                 XREF[1]:     004a1c3c(j)
//         004a1c52     XOR        EAX,EAX
//         004a1c54     JMP        LAB_004a1c5b
//                               LAB_004a1c56                                                 XREF[2]:     004a1c38(j), 004a1c46(j)
//         004a1c56     SBB        EAX,EAX
//         004a1c58     SBB        EAX,-0x1
//                               LAB_004a1c5b                                                 XREF[1]:     004a1c54(j)
//         004a1c5b     TEST       EAX,EAX
//         004a1c5d     JNZ        LAB_004a1cb0
//                              scr_mps.cpp:1008 (11)
//         004a1c5f     MOV        EAX,dword ptr [ESP + param_2]
//         004a1c66     TEST       EAX,EAX
//         004a1c68     JZ         LAB_004a1c95
//                              scr_mps.cpp:1010 (7)
//         004a1c6a     MOV        this,ESI
//         004a1c6c     CALL       TribeMPSetupScreen::updateSummary                void updateSummary(TribeMPSetupScreen * this)
//                              scr_mps.cpp:1012 (15)
//         004a1c71     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1c77     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a1c7c     TEST       EAX,EAX
//         004a1c7e     JNZ        LAB_004a1c95
//                              scr_mps.cpp:1019 (11)
//         004a1c80     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1c86     MOV        EAX,dword ptr [this->_padding_]
//         004a1c88     CALL       dword ptr [EAX + 0x48]
//                              scr_mps.cpp:1020 (10)
//         004a1c8b     MOV        dword ptr [ESI + 0x88c],0x0
//                               LAB_004a1c95                                                 XREF[2]:     004a1c68(j), 004a1c7e(j)
//                              scr_mps.cpp:1023 (17)
//         004a1c95     PUSH       0x0
//         004a1c97     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
//         004a1c9c     MOV        this,panel_system
//         004a1ca1     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              scr_mps.cpp:1024 (17)
//         004a1ca6     MOV        EAX,0x1
//         004a1cab     JMP        LAB_004a1f92
//                               LAB_004a1cb0                                                 XREF[1]:     004a1c5d(j)
//         004a1cb0     MOV        EBP,dword ptr [ESP + param_2]
//                               LAB_004a1cb7                                                 XREF[1]:     004a1c20(j)
//                              scr_mps.cpp:1028 (76)
//         004a1cb7     MOV        this,EBX
//         004a1cb9     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//         004a1cbe     TEST       EAX,EAX
//         004a1cc0     JZ         LAB_004a1d97
//         004a1cc6     MOV        this,EBX
//         004a1cc8     MOV        EDI,s_Kick_Dialog                                = 4Bh
//         004a1ccd     CALL       TPanel::panelName                                char * panelName(TPanel * this)
//                               LAB_004a1cd2                                                 XREF[1]:     004a1cf0(j)
//         004a1cd2     MOV        DL,byte ptr [EAX]
//         004a1cd4     MOV        this,DL
//         004a1cd6     CMP        DL,byte ptr [EDI]=>s_Kick_Dialog                 = 4Bh
//                                                                                  = 63h
//         004a1cd8     JNZ        LAB_004a1cf6
//         004a1cda     TEST       this,this
//         004a1cdc     JZ         LAB_004a1cf2
//         004a1cde     MOV        DL,byte ptr [EAX + 0x1]
//         004a1ce1     MOV        this,DL
//         004a1ce3     CMP        DL,byte ptr [EDI + 0x1]=>DAT_005867e9            = 69h
//                                                                                  = "k Dialog"
//         004a1ce6     JNZ        LAB_004a1cf6
//         004a1ce8     ADD        EAX,0x2
//         004a1ceb     ADD        EDI,0x2
//         004a1cee     TEST       this,this
//         004a1cf0     JNZ        LAB_004a1cd2
//                               LAB_004a1cf2                                                 XREF[1]:     004a1cdc(j)
//         004a1cf2     XOR        EAX,EAX
//         004a1cf4     JMP        LAB_004a1cfb
//                               LAB_004a1cf6                                                 XREF[2]:     004a1cd8(j), 004a1ce6(j)
//         004a1cf6     SBB        EAX,EAX
//         004a1cf8     SBB        EAX,-0x1
//                               LAB_004a1cfb                                                 XREF[1]:     004a1cf4(j)
//         004a1cfb     TEST       EAX,EAX
//         004a1cfd     JNZ        LAB_004a1d90
//                              scr_mps.cpp:1031 (11)
//         004a1d03     MOV        EAX,dword ptr [ESP + param_2]
//         004a1d0a     TEST       EAX,EAX
//         004a1d0c     JNZ        LAB_004a1d6a
//                              scr_mps.cpp:1033 (18)
//         004a1d0e     MOV        EAX,dword ptr [ESI + 0x724]
//         004a1d14     MOV        this,dword ptr [ESI + EAX*0x4 + 0x5ac]
//         004a1d1b     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//                              scr_mps.cpp:1034 (20)
//         004a1d20     MOV        this,dword ptr [ESI + 0x724]
//         004a1d26     MOV        EDI,EAX
//         004a1d28     PUSH       this
//         004a1d29     MOV        this,dword ptr [comm]                            = 00000000
//         004a1d2f     CALL       TCommunications_Handler::Kick                    int Kick(TCommunications_Handler * this, uint
//                              scr_mps.cpp:1035 (19)
//         004a1d34     MOV        EDX,dword ptr [ESI + 0x724]
//         004a1d3a     MOV        this,dword ptr [comm]                            = 00000000
//         004a1d40     PUSH       EDI
//         004a1d41     PUSH       EDX
//         004a1d42     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
//                              scr_mps.cpp:1036 (33)
//         004a1d47     MOV        EAX,dword ptr [ESI + 0x724]
//         004a1d4d     PUSH       EDI
//         004a1d4e     MOV        this,dword ptr [ESI + EAX*0x4 + 0x5ac]
//         004a1d55     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004a1d5a     MOV        this,dword ptr [ESI + 0x724]
//         004a1d60     PUSH       EAX
//         004a1d61     MOV        this,dword ptr [ESI + this->_padding_*0x4 + 0x
//                              scr_mps.cpp:1038 (2)
//         004a1d68     JMP        LAB_004a1d79
//                               LAB_004a1d6a                                                 XREF[1]:     004a1d0c(j)
//                              scr_mps.cpp:1039 (20)
//         004a1d6a     MOV        EDX,dword ptr [ESI + 0x724]
//         004a1d70     PUSH       0x0
//         004a1d72     MOV        this,dword ptr [ESI + EDX*0x4 + 0x5ac]
//                               LAB_004a1d79                                                 XREF[1]:     004a1d68(j)
//         004a1d79     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_mps.cpp:1041 (8)
//         004a1d7e     MOV        EAX,dword ptr [EBX]
//         004a1d80     PUSH       0x1
//         004a1d82     MOV        this,EBX
//         004a1d84     CALL       dword ptr [EAX]
//                              scr_mps.cpp:1042 (17)
//         004a1d86     MOV        EAX,0x1
//         004a1d8b     JMP        LAB_004a1f92
//                               LAB_004a1d90                                                 XREF[1]:     004a1cfd(j)
//         004a1d90     MOV        EBP,dword ptr [ESP + param_2]
//                               LAB_004a1d97                                                 XREF[1]:     004a1cc0(j)
//                              scr_mps.cpp:1054 (8)
//         004a1d97     TEST       EBP,EBP
//         004a1d99     JNZ        LAB_004a1f72
//                              scr_mps.cpp:1056 (19)
//         004a1d9f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1da5     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a1daa     TEST       EAX,EAX
//         004a1dac     JLE        LAB_004a1f72
//                              scr_mps.cpp:1134 (6)
//         004a1db2     LEA        EDI,[ESI + 0x5d0]
//                               LAB_004a1db8                                                 XREF[1]:     004a1ddf(j)
//                              scr_mps.cpp:1058 (5)
//         004a1db8     CMP        EBX,dword ptr [EDI + -0x20]
//         004a1dbb     JZ         LAB_004a1de6
//                              scr_mps.cpp:1066 (8)
//         004a1dbd     CMP        EBX,dword ptr [EDI]
//         004a1dbf     JZ         LAB_004a1e4e
//                              scr_mps.cpp:1088 (33)
//         004a1dc5     CMP        EBX,dword ptr [EDI + 0x20]
//         004a1dc8     JZ         LAB_004a1ea9
//         004a1dce     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1dd4     INC        EBP
//         004a1dd5     ADD        EDI,0x4
//         004a1dd8     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a1ddd     CMP        EBP,EAX
//         004a1ddf     JL         LAB_004a1db8
//         004a1de1     JMP        LAB_004a1f72
//                               LAB_004a1de6                                                 XREF[1]:     004a1dbb(j)
//                              scr_mps.cpp:1060 (50)
//         004a1de6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1dec     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a1df1     TEST       EAX,EAX
//         004a1df3     JZ         LAB_004a1e2a
//         004a1df5     MOV        this,dword ptr [ESI + EBP*0x4 + 0x5b0]
//         004a1dfc     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this)
//         004a1e01     TEST       EAX,EAX
//         004a1e03     JLE        LAB_004a1e2a
//         004a1e05     MOV        this,dword ptr [comm]                            = 00000000
//         004a1e0b     LEA        EDI,[EBP + 0x1]
//         004a1e0e     PUSH       EDI
//         004a1e0f     CALL       TCommunications_Handler::IsPlayerHuman           int IsPlayerHuman(TCommunications_Handler * t
//         004a1e14     TEST       EAX,EAX
//         004a1e16     JZ         LAB_004a1e2a
//                              scr_mps.cpp:1061 (8)
//         004a1e18     PUSH       EDI
//         004a1e19     MOV        this,ESI
//         004a1e1b     CALL       TribeMPSetupScreen::kickPlayer                   void kickPlayer(TribeMPSetupScreen * this, in
//                              scr_mps.cpp:1127 (10)
//         004a1e20     MOV        EAX,0x1
//         004a1e25     JMP        LAB_004a1f92
//                               LAB_004a1e2a                                                 XREF[3]:     004a1df3(j), 004a1e03(j),
//                                                                                                         004a1e16(j)
//                              scr_mps.cpp:1063 (26)
//         004a1e2a     MOV        this,dword ptr [ESI + EBP*0x4 + 0x5b0]
//         004a1e31     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1e36     MOV        this,dword ptr [comm]                            = 00000000
//         004a1e3c     INC        EBP
//         004a1e3d     PUSH       EAX
//         004a1e3e     PUSH       EBP
//         004a1e3f     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
//                              scr_mps.cpp:1064 (10)
//         004a1e44     MOV        EAX,0x1
//         004a1e49     JMP        LAB_004a1f92
//                               LAB_004a1e4e                                                 XREF[1]:     004a1dbf(j)
//                              scr_mps.cpp:1068 (25)
//         004a1e4e     MOV        this,dword ptr [ESI + EBP*0x4 + 0x5d0]
//         004a1e55     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1e5a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1e60     PUSH       EAX
//         004a1e61     PUSH       EBP
//         004a1e62     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1069 (19)
//         004a1e67     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1e6d     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a1e72     TEST       EAX,EAX
//         004a1e74     JZ         LAB_004a1f6b
//                              scr_mps.cpp:1071 (19)
//         004a1e7a     MOV        this,dword ptr [comm]                            = 00000000
//         004a1e80     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a1e85     TEST       EAX,EAX
//         004a1e87     JNZ        LAB_004a1f6b
//                              scr_mps.cpp:1082 (18)
//         004a1e8d     MOV        this,dword ptr [ESI + EBP*0x4 + 0x5d0]
//         004a1e94     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1e99     MOV        dword ptr [ESI + 0x72c],EAX
//                              scr_mps.cpp:1086 (10)
//         004a1e9f     MOV        EAX,0x1
//         004a1ea4     JMP        LAB_004a1f92
//                               LAB_004a1ea9                                                 XREF[1]:     004a1dc8(j)
//                              scr_mps.cpp:1090 (15)
//         004a1ea9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1eaf     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a1eb4     TEST       EAX,EAX
//         004a1eb6     JZ         LAB_004a1f00
//                              scr_mps.cpp:1092 (25)
//         004a1eb8     MOV        this,dword ptr [ESI + EBP*0x4 + 0x5f0]
//         004a1ebf     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1ec4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1eca     PUSH       EAX
//         004a1ecb     PUSH       EBP
//         004a1ecc     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1093 (19)
//         004a1ed1     MOV        this,dword ptr [comm]                            = 00000000
//         004a1ed7     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a1edc     TEST       EAX,EAX
//         004a1ede     JNZ        LAB_004a1f6b
//                              scr_mps.cpp:1102 (18)
//         004a1ee4     MOV        this,dword ptr [ESI + EBP*0x4 + 0x5f0]
//         004a1eeb     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1ef0     MOV        dword ptr [ESI + 0x730],EAX
//                              scr_mps.cpp:1127 (10)
//         004a1ef6     MOV        EAX,0x1
//         004a1efb     JMP        LAB_004a1f92
//                               LAB_004a1f00                                                 XREF[1]:     004a1eb6(j)
//                              scr_mps.cpp:1109 (25)
//         004a1f00     MOV        this,dword ptr [ESI + 0x5f0]
//         004a1f06     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a1f0b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1f11     PUSH       EAX
//         004a1f12     PUSH       0x0
//         004a1f14     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1113 (5)
//         004a1f19     MOV        EBP,0x1
//                              scr_mps.cpp:1114 (2)
//         004a1f1e     XOR        EDI,EDI
//                               LAB_004a1f20                                                 XREF[1]:     004a1f62(j)
//                              scr_mps.cpp:1116 (33)
//         004a1f20     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1f26     PUSH       0x0
//         004a1f28     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
//         004a1f2d     CMP        EDI,EAX
//         004a1f2f     JZ         LAB_004a1f5e
//         004a1f31     MOV        this,dword ptr [ESI + 0x848]
//         004a1f37     PUSH       EDI
//         004a1f38     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
//         004a1f3d     TEST       EAX,EAX
//         004a1f3f     JZ         LAB_004a1f5e
//                              scr_mps.cpp:1118 (13)
//         004a1f41     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1f47     PUSH       EDI
//         004a1f48     PUSH       EBP
//         004a1f49     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1120 (16)
//         004a1f4e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1f54     INC        EBP
//         004a1f55     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a1f5a     CMP        EBP,EAX
//         004a1f5c     JGE        LAB_004a1f64
//                               LAB_004a1f5e                                                 XREF[2]:     004a1f2f(j), 004a1f3f(j)
//                              scr_mps.cpp:1114 (6)
//         004a1f5e     INC        EDI
//         004a1f5f     CMP        EDI,0x8
//         004a1f62     JL         LAB_004a1f20
//                               LAB_004a1f64                                                 XREF[1]:     004a1f5c(j)
//                              scr_mps.cpp:1125 (7)
//         004a1f64     MOV        this,ESI
//         004a1f66     CALL       TribeMPSetupScreen::fillPlayers                  void fillPlayers(TribeMPSetupScreen * this)
//                               LAB_004a1f6b                                                 XREF[8]:     004a19e4(j), 004a1e74(j),
//                                                                                                         004a1e87(j), 004a1ede(j),
//                                                                                                         004a1fd3(j), 004a1fe2(j),
//                                                                                                         004a2024(j), 004a2037(j)
//                              scr_mps.cpp:1127 (7)
//         004a1f6b     MOV        EAX,0x1
//         004a1f70     JMP        LAB_004a1f92
//                               LAB_004a1f72                                                 XREF[4]:     004a170a(j), 004a1d99(j),
//                                                                                                         004a1dac(j), 004a1de1(j)
//                              scr_mps.cpp:1133 (32)
//         004a1f72     MOV        this,dword ptr [ESP + param_4]
//         004a1f79     MOV        EDX,dword ptr [ESP + param_3]
//         004a1f80     MOV        EAX,dword ptr [ESP + param_2]
//         004a1f87     PUSH       this
//         004a1f88     PUSH       EDX
//         004a1f89     PUSH       EAX
//         004a1f8a     PUSH       EBX
//         004a1f8b     MOV        this,ESI
//         004a1f8d     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                               LAB_004a1f92                                                 XREF[19]:    004a174b(j), 004a17e2(j),
//                                                                                                         004a1a3c(j), 004a1ad5(j),
//                                                                                                         004a1af0(j), 004a1b0f(j),
//                                                                                                         004a1b48(j), 004a1b63(j),
//                                                                                                         004a1be2(j), 004a1c12(j),
//                                                                                                         004a1cab(j), 004a1d8b(j),
//                                                                                                         004a1e25(j), 004a1e49(j),
//                                                                                                         004a1ea4(j), 004a1efb(j),
//                                                                                                         004a1f70(j), 004a1ffb(j),
//                                                                                                         004a2055(j)
//                              scr_mps.cpp:1134 (27)
//         004a1f92     MOV        this,dword ptr [ESP + local_c]
//         004a1f99     POP        EDI
//         004a1f9a     POP        ESI
//         004a1f9b     POP        EBP
//         004a1f9c     MOV        dword ptr FS:[0x0],this
//         004a1fa3     POP        EBX
//         004a1fa4     ADD        ESP,0x22c
//         004a1faa     RET        0x10
//                               LAB_004a1fad                                                 XREF[1]:     004a1b78(j)
//                              scr_mps.cpp:952 (25)
//         004a1fad     MOV        this,dword ptr [ESI + EDI*0x4 + 0x570]
//         004a1fb4     CALL       TButtonPanel::get_id                             long get_id(TButtonPanel * this)
//         004a1fb9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1fbf     PUSH       EAX
//         004a1fc0     PUSH       EDI
//         004a1fc1     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:953 (15)
//         004a1fc6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a1fcc     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a1fd1     TEST       EAX,EAX
//         004a1fd3     JZ         LAB_004a1f6b
//                              scr_mps.cpp:955 (15)
//         004a1fd5     MOV        this,dword ptr [comm]                            = 00000000
//         004a1fdb     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a1fe0     TEST       EAX,EAX
//         004a1fe2     JNZ        LAB_004a1f6b
//                              scr_mps.cpp:959 (18)
//         004a1fe4     MOV        this,dword ptr [ESI + EDI*0x4 + 0x570]
//         004a1feb     CALL       TButtonPanel::get_id                             long get_id(TButtonPanel * this)
//         004a1ff0     MOV        dword ptr [ESI + 0x734],EAX
//                              scr_mps.cpp:963 (7)
//         004a1ff6     MOV        EAX,0x1
//         004a1ffb     JMP        LAB_004a1f92
//                               LAB_004a1ffd                                                 XREF[1]:     004a1b80(j)
//                              scr_mps.cpp:968 (26)
//         004a1ffd     MOV        this,dword ptr [ESI + EDI*0x4 + 0x590]
//         004a2004     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004a2009     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a200f     INC        EAX
//         004a2010     PUSH       EAX
//         004a2011     PUSH       EDI
//         004a2012     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:969 (19)
//         004a2017     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a201d     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a2022     TEST       EAX,EAX
//         004a2024     JZ         LAB_004a1f6b
//                              scr_mps.cpp:971 (19)
//         004a202a     MOV        this,dword ptr [comm]                            = 00000000
//         004a2030     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a2035     TEST       EAX,EAX
//         004a2037     JNZ        LAB_004a1f6b
//                              scr_mps.cpp:975 (19)
//         004a203d     MOV        this,dword ptr [ESI + EDI*0x4 + 0x590]
//         004a2044     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004a2049     INC        EAX
//         004a204a     MOV        dword ptr [ESI + 0x738],EAX
//                              scr_mps.cpp:979 (10)
//         004a2050     MOV        EAX,0x1
//         004a2055     JMP        LAB_004a1f92
//         004a205a     ??         90h
//         004a205b     NOP
//         004a205c     NOP
//         004a205d     NOP
//         004a205e     NOP
//         004a205f     NOP
    return 0;
}

int TribeMPSetupScreen::startGame() {
    /* TODO: Stub */
//                              int __thiscall startGame(TribeMPSetupScreen * this)
//              int               EAX:4          <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              char[1024]        Stack[-0x404   msg                       XREF[0,4]:   004a2184(*), 004a2194(*), 004a2761(*), 004a2772(*)
//              char[256]         Stack[-0x504   msg@fffffafc              XREF[0,4]:   004a2343(*), 004a2353(*), 004a23a5(*), 004a23b3(*)
//              int[8]            Stack[-0x524   temp_civ                  XREF[0,1]:   004a25cb(*)
//              int[8]            Stack[-0x544   temp_color                XREF[0,2]:   004a25d4(*), 004a2645(*)
//              int[8]            Stack[-0x564   temp_team                 XREF[2,6]:   004a2072(W), 004a26ad(R), 004a2281(*), 004a25be(*),
//                                                                                     004a25e6(*), 004a262f(*), 004a2641(*), 004a2667(*)
//              undefined4        Stack[-0x568   local_568                 XREF[6]:     004a2076(W), 004a249a(W), 004a2544(W), 004a2589(W),
//                                                                                     004a267f(W), 004a26a5(R)
//              int               Stack[-0x56c   send_options
//                               ?startGame@TribeMPSetupScreen@@IAEHXZ                        XREF[1]:     action:004a1741(c)
//                               TribeMPSetupScreen::startGame
//                              scr_mps.cpp:1140 (11)
//         004a2060     SUB        ESP,0x568
//         004a2066     PUSH       EBX
//         004a2067     PUSH       EBP
//         004a2068     MOV        EBP,this
//         004a206a     PUSH       ESI
//                              scr_mps.cpp:1146 (32)
//         004a206b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2071     PUSH       EDI
//         004a2072     MOV        dword ptr [ESP + temp_team[0]],EBP
//         004a2076     MOV        dword ptr [ESP + local_568],0x0
//         004a207e     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a2083     TEST       EAX,EAX
//         004a2085     JZ         LAB_004a21b9
//                              scr_mps.cpp:1148 (15)
//         004a208b     MOV        this,dword ptr [comm]                            = 00000000
//         004a2091     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a2096     TEST       EAX,EAX
//         004a2098     JNZ        LAB_004a20a5
//                              scr_mps.cpp:1446 (11)
//         004a209a     POP        EDI
//         004a209b     POP        ESI
//         004a209c     POP        EBP
//         004a209d     POP        EBX
//         004a209e     ADD        ESP,0x568
//         004a20a4     RET
//                               LAB_004a20a5                                                 XREF[1]:     004a2098(j)
//                              scr_mps.cpp:1151 (15)
//         004a20a5     MOV        this,dword ptr [comm]                            = 00000000
//         004a20ab     CALL       TCommunications_Handler::AllPlayersReady         int AllPlayersReady(TCommunications_Handler *
//         004a20b0     TEST       EAX,EAX
//         004a20b2     JNZ        LAB_004a20d5
//                              scr_mps.cpp:1153 (20)
//         004a20b4     PUSH       0x64
//         004a20b6     PUSH       0x1c2
//         004a20bb     PUSH       EAX
//                              language.dll match for 0x25c1: "All players must be ready for
//         004a20bc     PUSH       0x25c1
//         004a20c1     MOV        this,EBP
//         004a20c3     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_mps.cpp:1154 (2)
//         004a20c8     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a20ca     POP        EDI
//         004a20cb     POP        ESI
//         004a20cc     POP        EBP
//         004a20cd     POP        EBX
//         004a20ce     ADD        ESP,0x568
//         004a20d4     RET
//                               LAB_004a20d5                                                 XREF[1]:     004a20b2(j)
//                              scr_mps.cpp:1170 (15)
//         004a20d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a20db     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a20e0     TEST       EAX,EAX
//         004a20e2     JZ         LAB_004a212b
//                              scr_mps.cpp:1192 (13)
//         004a20e4     XOR        EBX,EBX
//         004a20e6     MOV        ESI,0x1
//         004a20eb     LEA        EDI,[EBP + 0x868]
//                               LAB_004a20f1                                                 XREF[1]:     004a2129(j)
//                              scr_mps.cpp:1194 (32)
//         004a20f1     MOV        this,dword ptr [comm]                            = 00000000
//         004a20f7     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a20fc     CMP        ESI,EAX
//         004a20fe     JZ         LAB_004a2121
//         004a2100     MOV        this,dword ptr [comm]                            = 00000000
//         004a2106     PUSH       ESI
//         004a2107     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         004a210c     CMP        EAX,0x2
//         004a210f     JNZ        LAB_004a2121
//                              scr_mps.cpp:1196 (16)
//         004a2111     MOV        EAX,dword ptr [EDI]
//         004a2113     MOV        this,dword ptr [EBP + 0x73c]
//         004a2119     CMP        EAX,this
//         004a211b     JNZ        LAB_004a2747
//                               LAB_004a2121                                                 XREF[2]:     004a20fe(j), 004a210f(j)
//                              scr_mps.cpp:1192 (10)
//         004a2121     INC        EBX
//         004a2122     ADD        EDI,0x4
//         004a2125     INC        ESI
//         004a2126     CMP        ESI,0x9
//         004a2129     JL         LAB_004a20f1
//                               LAB_004a212b                                                 XREF[1]:     004a20e2(j)
//                              scr_mps.cpp:1208 (2)
//         004a212b     XOR        ESI,ESI
//                               LAB_004a212d                                                 XREF[1]:     004a2165(j)
//                              scr_mps.cpp:1210 (35)
//         004a212d     MOV        this,dword ptr [comm]                            = 00000000
//         004a2133     LEA        EDI,[ESI + 0x1]
//         004a2136     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a213b     CMP        EDI,EAX
//         004a213d     JZ         LAB_004a2160
//         004a213f     MOV        this,dword ptr [comm]                            = 00000000
//         004a2145     PUSH       EDI
//         004a2146     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         004a214b     CMP        EAX,0x2
//         004a214e     JNZ        LAB_004a2160
//                              scr_mps.cpp:1212 (16)
//         004a2150     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2156     PUSH       ESI
//         004a2157     CALL       RGE_Base_Game::playerVersion                     uchar playerVersion(RGE_Base_Game * this, int
//         004a215c     CMP        AL,0x1
//         004a215e     JNZ        LAB_004a2169
//                               LAB_004a2160                                                 XREF[2]:     004a213d(j), 004a214e(j)
//                              scr_mps.cpp:1208 (9)
//         004a2160     MOV        ESI,EDI
//         004a2162     CMP        ESI,0x8
//         004a2165     JL         LAB_004a212d
//         004a2167     JMP        LAB_004a21b9
//                               LAB_004a2169                                                 XREF[1]:     004a215e(j)
//                              scr_mps.cpp:1215 (43)
//         004a2169     MOV        this,dword ptr [comm]                            = 00000000
//         004a216f     INC        ESI
//         004a2170     PUSH       ESI
//         004a2171     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler
//         004a2176     PUSH       EAX
//                              language.dll match for 0x25e2: "%s is not running version 1.0
//         004a2177     PUSH       0x25e2
//         004a217c     MOV        this,EBP
//         004a217e     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a2183     PUSH       EAX
//         004a2184     LEA        EAX=>msg[4],[ESP + 0x180]
//         004a218b     PUSH       EAX
//         004a218c     CALL       sprintf                                          undefined sprintf()
//         004a2191     ADD        ESP,0xc
//                              scr_mps.cpp:1216 (24)
//         004a2194     LEA        this=>msg[4],[ESP + 0x178]
//         004a219b     PUSH       0x64
//         004a219d     PUSH       0x1c2
//         004a21a2     PUSH       0x0
//         004a21a4     PUSH       this
//         004a21a5     MOV        this,EBP
//         004a21a7     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1217 (2)
//         004a21ac     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a21ae     POP        EDI
//         004a21af     POP        ESI
//         004a21b0     POP        EBP
//         004a21b1     POP        EBX
//         004a21b2     ADD        ESP,0x568
//         004a21b8     RET
//                               LAB_004a21b9                                                 XREF[2]:     004a2085(j), 004a2167(j)
//                              scr_mps.cpp:1224 (25)
//         004a21b9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a21bf     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a21c4     TEST       EAX,EAX
//         004a21c6     JZ         LAB_004a21f4
//         004a21c8     MOV        EAX,dword ptr [EBP + 0x848]
//         004a21ce     TEST       EAX,EAX
//         004a21d0     JNZ        LAB_004a21f4
//                              scr_mps.cpp:1226 (21)
//         004a21d2     PUSH       0x64
//         004a21d4     PUSH       0x1c2
//         004a21d9     PUSH       0x0
//                              language.dll match for 0x25c2: "The selected scenario is inva
//         004a21db     PUSH       0x25c2
//         004a21e0     MOV        this,EBP
//         004a21e2     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_mps.cpp:1227 (2)
//         004a21e7     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a21e9     POP        EDI
//         004a21ea     POP        ESI
//         004a21eb     POP        EBP
//         004a21ec     POP        EBX
//         004a21ed     ADD        ESP,0x568
//         004a21f3     RET
//                               LAB_004a21f4                                                 XREF[2]:     004a21c6(j), 004a21d0(j)
//                              scr_mps.cpp:1238 (30)
//         004a21f4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a21fa     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a21ff     TEST       EAX,EAX
//         004a2201     JZ         LAB_004a2267
//         004a2203     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2209     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a220e     TEST       EAX,EAX
//         004a2210     JZ         LAB_004a2267
//                              scr_mps.cpp:1240 (2)
//         004a2212     XOR        EBX,EBX
//                              scr_mps.cpp:1241 (2)
//         004a2214     XOR        ESI,ESI
//                               LAB_004a2216                                                 XREF[1]:     004a2265(j)
//                              scr_mps.cpp:1243 (15)
//         004a2216     MOV        this,dword ptr [comm]                            = 00000000
//         004a221c     LEA        EDI,[ESI + 0x1]
//         004a221f     PUSH       EDI
//         004a2220     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//                              scr_mps.cpp:1244 (10)
//         004a2225     CMP        EAX,0x2
//         004a2228     JZ         LAB_004a222f
//         004a222a     CMP        EAX,0x4
//         004a222d     JNZ        LAB_004a2260
//                               LAB_004a222f                                                 XREF[1]:     004a2228(j)
//                              scr_mps.cpp:1246 (25)
//         004a222f     MOV        this,dword ptr [EBP + 0x5f0]
//         004a2235     PUSH       EBX
//         004a2236     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this, long param
//         004a223b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2241     PUSH       EAX
//         004a2242     PUSH       ESI
//         004a2243     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1248 (22)
//         004a2248     MOV        EDX,dword ptr [EBP + 0x5f0]
//         004a224e     INC        EBX
//         004a224f     MOV        this,dword ptr [EDX + 0xfc]
//         004a2255     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//         004a225a     CMP        EBX,EAX
//         004a225c     JL         LAB_004a2260
//                              scr_mps.cpp:1249 (2)
//         004a225e     XOR        EBX,EBX
//                               LAB_004a2260                                                 XREF[2]:     004a222d(j), 004a225c(j)
//                              scr_mps.cpp:1241 (7)
//         004a2260     MOV        ESI,EDI
//         004a2262     CMP        ESI,0x8
//         004a2265     JL         LAB_004a2216
//                               LAB_004a2267                                                 XREF[2]:     004a2201(j), 004a2210(j)
//                              scr_mps.cpp:1257 (19)
//         004a2267     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a226d     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a2272     TEST       EAX,EAX
//         004a2274     JZ         LAB_004a2461
//                              scr_mps.cpp:1264 (15)
//         004a227a     MOV        this,0x8
//         004a227f     XOR        EAX,EAX
//         004a2281     LEA        EDI=>temp_team[1],[ESP + 0x18]
//         004a2285     XOR        EBX,EBX
//         004a2287     STOSD.REP  ES:EDI
//                              scr_mps.cpp:1267 (17)
//         004a2289     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a228f     XOR        ESI,ESI
//         004a2291     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a2296     TEST       EAX,EAX
//         004a2298     JLE        LAB_004a22f5
//                               LAB_004a229a                                                 XREF[1]:     004a22f3(j)
//                              scr_mps.cpp:1269 (15)
//         004a229a     MOV        this,dword ptr [comm]                            = 00000000
//         004a22a0     LEA        EDI,[ESI + 0x1]
//         004a22a3     PUSH       EDI
//         004a22a4     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//                              scr_mps.cpp:1270 (10)
//         004a22a9     CMP        EAX,0x2
//         004a22ac     JZ         LAB_004a22b8
//         004a22ae     CMP        EAX,0x4
//         004a22b1     JNZ        LAB_004a22e4
//                              scr_mps.cpp:1272 (5)
//         004a22b3     CMP        EAX,0x2
//         004a22b6     JNZ        LAB_004a22e3
//                               LAB_004a22b8                                                 XREF[1]:     004a22ac(j)
//                              scr_mps.cpp:1274 (20)
//         004a22b8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a22be     PUSH       ESI
//         004a22bf     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a22c4     MOV        this,dword ptr [ESP + EAX*0x4 + 0x14]
//         004a22c8     TEST       this,this
//         004a22ca     JNZ        LAB_004a22e4
//                              scr_mps.cpp:1277 (21)
//         004a22cc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a22d2     PUSH       ESI
//         004a22d3     INC        EBX
//         004a22d4     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a22d9     MOV        dword ptr [ESP + EAX*0x4 + 0x14],0x1
//                              scr_mps.cpp:1280 (2)
//         004a22e1     JMP        LAB_004a22e4
//                               LAB_004a22e3                                                 XREF[1]:     004a22b6(j)
//                              scr_mps.cpp:1281 (1)
//         004a22e3     INC        EBX
//                               LAB_004a22e4                                                 XREF[3]:     004a22b1(j), 004a22ca(j),
//                                                                                                         004a22e1(j)
//                              scr_mps.cpp:1267 (17)
//         004a22e4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a22ea     MOV        ESI,EDI
//         004a22ec     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a22f1     CMP        ESI,EAX
//         004a22f3     JL         LAB_004a229a
//                               LAB_004a22f5                                                 XREF[1]:     004a2298(j)
//                              scr_mps.cpp:1297 (5)
//         004a22f5     CMP        EBX,0x2
//         004a22f8     JGE        LAB_004a231c
//                              scr_mps.cpp:1299 (21)
//         004a22fa     PUSH       0x64
//         004a22fc     PUSH       0x1c2
//         004a2301     PUSH       0x0
//                              language.dll match for 0x25c6: "You cannot start a game with
//         004a2303     PUSH       0x25c6
//         004a2308     MOV        this,EBP
//         004a230a     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_mps.cpp:1300 (2)
//         004a230f     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a2311     POP        EDI
//         004a2312     POP        ESI
//         004a2313     POP        EBP
//         004a2314     POP        EBX
//         004a2315     ADD        ESP,0x568
//         004a231b     RET
//                               LAB_004a231c                                                 XREF[1]:     004a22f8(j)
//                              scr_mps.cpp:1303 (25)
//         004a231c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2322     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a2327     TEST       EAX,EAX
//         004a2329     JZ         LAB_004a2375
//         004a232b     MOV        EAX,dword ptr [EBP + 0x728]
//         004a2331     CMP        EBX,EAX
//         004a2333     JLE        LAB_004a2375
//                              scr_mps.cpp:1306 (30)
//         004a2335     PUSH       EAX
//                              language.dll match for 0x25c3: "This scenario only supports u
//         004a2336     PUSH       0x25c3
//         004a233b     MOV        this,EBP
//         004a233d     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a2342     PUSH       EAX
//         004a2343     LEA        EAX=>msg@fffffafc[4],[ESP + 0x80]
//         004a234a     PUSH       EAX
//         004a234b     CALL       sprintf                                          undefined sprintf()
//         004a2350     ADD        ESP,0xc
//                              scr_mps.cpp:1307 (21)
//         004a2353     LEA        this=>msg@fffffafc[4],[ESP + 0x78]
//         004a2357     PUSH       0x64
//         004a2359     PUSH       0x1c2
//         004a235e     PUSH       0x0
//         004a2360     PUSH       this
//         004a2361     MOV        this,EBP
//         004a2363     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1308 (2)
//         004a2368     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a236a     POP        EDI
//         004a236b     POP        ESI
//         004a236c     POP        EBP
//         004a236d     POP        EBX
//         004a236e     ADD        ESP,0x568
//         004a2374     RET
//                               LAB_004a2375                                                 XREF[2]:     004a2329(j), 004a2333(j)
//                              scr_mps.cpp:1313 (35)
//         004a2375     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a237b     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a2380     TEST       EAX,EAX
//         004a2382     JZ         LAB_004a23d5
//         004a2384     MOV        EAX,dword ptr [EBP + 0x84c]
//         004a238a     TEST       EAX,EAX
//         004a238c     JZ         LAB_004a23d5
//         004a238e     MOV        EAX,dword ptr [EBP + 0x728]
//         004a2394     CMP        EBX,EAX
//         004a2396     JZ         LAB_004a23d5
//                              scr_mps.cpp:1316 (27)
//         004a2398     PUSH       EAX
//                              language.dll match for 0x25c5: "This scenario requires exactl
//         004a2399     PUSH       0x25c5
//         004a239e     MOV        this,EBP
//         004a23a0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a23a5     LEA        EDX=>msg@fffffafc[4],[ESP + 0x7c]
//         004a23a9     PUSH       EAX
//         004a23aa     PUSH       EDX
//         004a23ab     CALL       sprintf                                          undefined sprintf()
//         004a23b0     ADD        ESP,0xc
//                              scr_mps.cpp:1317 (21)
//         004a23b3     LEA        EAX=>msg@fffffafc[4],[ESP + 0x78]
//         004a23b7     MOV        this,EBP
//         004a23b9     PUSH       0x64
//         004a23bb     PUSH       0x1c2
//         004a23c0     PUSH       0x0
//         004a23c2     PUSH       EAX
//         004a23c3     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1318 (2)
//         004a23c8     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a23ca     POP        EDI
//         004a23cb     POP        ESI
//         004a23cc     POP        EBP
//         004a23cd     POP        EBX
//         004a23ce     ADD        ESP,0x568
//         004a23d4     RET
//                               LAB_004a23d5                                                 XREF[3]:     004a2382(j), 004a238c(j),
//                                                                                                         004a2396(j)
//                              scr_mps.cpp:1324 (19)
//         004a23d5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a23db     XOR        EDI,EDI
//         004a23dd     XOR        ESI,ESI
//         004a23df     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a23e4     TEST       EAX,EAX
//         004a23e6     JLE        LAB_004a240a
//                               LAB_004a23e8                                                 XREF[1]:     004a2408(j)
//                              scr_mps.cpp:1326 (18)
//         004a23e8     MOV        this,dword ptr [comm]                            = 00000000
//         004a23ee     INC        ESI
//         004a23ef     PUSH       ESI
//         004a23f0     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         004a23f5     CMP        EAX,0x2
//         004a23f8     JNZ        LAB_004a23fb
//                              scr_mps.cpp:1327 (1)
//         004a23fa     INC        EDI
//                               LAB_004a23fb                                                 XREF[1]:     004a23f8(j)
//                              scr_mps.cpp:1324 (15)
//         004a23fb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2401     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a2406     CMP        ESI,EAX
//         004a2408     JL         LAB_004a23e8
//                               LAB_004a240a                                                 XREF[1]:     004a23e6(j)
//                              scr_mps.cpp:1331 (38)
//         004a240a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2410     PUSH       0x0
//         004a2412     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         004a2417     MOV        this,dword ptr [comm]                            = 00000000
//         004a241d     PUSH       EAX
//         004a241e     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a2423     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2429     DEC        EAX
//         004a242a     PUSH       EAX
//         004a242b     CALL       RGE_Base_Game::setPlayerHasCD                    void setPlayerHasCD(RGE_Base_Game * this, int
//                              scr_mps.cpp:1332 (16)
//         004a2430     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2436     PUSH       EDI
//         004a2437     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         004a243c     TEST       EAX,EAX
//         004a243e     JNZ        LAB_004a2461
//                              scr_mps.cpp:1334 (20)
//         004a2440     PUSH       0x64
//         004a2442     PUSH       0x1c2
//         004a2447     PUSH       EAX
//                              language.dll match for 0x7d9: "One game CD is required for ev
//         004a2448     PUSH       0x7d9
//         004a244d     MOV        this,EBP
//         004a244f     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_mps.cpp:1335 (2)
//         004a2454     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a2456     POP        EDI
//         004a2457     POP        ESI
//         004a2458     POP        EBP
//         004a2459     POP        EBX
//         004a245a     ADD        ESP,0x568
//         004a2460     RET
//                               LAB_004a2461                                                 XREF[2]:     004a2274(j), 004a243e(j)
//                              scr_mps.cpp:1341 (30)
//         004a2461     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2467     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a246c     TEST       EAX,EAX
//         004a246e     JZ         LAB_004a24a0
//         004a2470     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2476     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
//         004a247b     TEST       EAX,EAX
//         004a247d     JZ         LAB_004a24a0
//                              scr_mps.cpp:1343 (7)
//         004a247f     MOV        this,EBP
//         004a2481     CALL       TribeMPSetupScreen::calcRandomPositions          void calcRandomPositions(TribeMPSetupScreen *
//                              scr_mps.cpp:1346 (15)
//         004a2486     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a248c     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a2491     TEST       EAX,EAX
//         004a2493     JZ         LAB_004a24a0
//                              scr_mps.cpp:1347 (16)
//         004a2495     MOV        EDI,0x1
//         004a249a     MOV        dword ptr [ESP + local_568],EDI
//         004a249e     JMP        LAB_004a24a5
//                               LAB_004a24a0                                                 XREF[3]:     004a246e(j), 004a247d(j),
//                                                                                                         004a2493(j)
//         004a24a0     MOV        EDI,0x1
//                               LAB_004a24a5                                                 XREF[1]:     004a249e(j)
//                              scr_mps.cpp:1363 (15)
//         004a24a5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a24ab     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a24b0     TEST       EAX,EAX
//         004a24b2     JZ         LAB_004a24db
//                              scr_mps.cpp:1366 (19)
//         004a24b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a24ba     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a24bf     CMP        EAX,0x8
//         004a24c2     JGE        LAB_004a24db
//         004a24c4     LEA        ESI,[EAX + 0x1]
//                               LAB_004a24c7                                                 XREF[1]:     004a24d9(j)
//                              scr_mps.cpp:1367 (20)
//         004a24c7     MOV        this,dword ptr [comm]                            = 00000000
//         004a24cd     PUSH       0x0
//         004a24cf     PUSH       ESI
//         004a24d0     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
//         004a24d5     INC        ESI
//         004a24d6     CMP        ESI,0x9
//         004a24d9     JL         LAB_004a24c7
//                               LAB_004a24db                                                 XREF[2]:     004a24b2(j), 004a24c2(j)
//                              scr_mps.cpp:1371 (19)
//         004a24db     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a24e1     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a24e6     TEST       EAX,EAX
//         004a24e8     JZ         LAB_004a25a1
//                              scr_mps.cpp:1373 (21)
//         004a24ee     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a24f4     XOR        ESI,ESI
//         004a24f6     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a24fb     TEST       EAX,EAX
//         004a24fd     JLE        LAB_004a25a1
//                               LAB_004a2503                                                 XREF[1]:     004a259b(j)
//                              scr_mps.cpp:1375 (17)
//         004a2503     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2509     PUSH       ESI
//         004a250a     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a250f     CMP        EAX,0x32
//         004a2512     JL         LAB_004a2548
//                              scr_mps.cpp:1377 (17)
//         004a2514     MOV        this,dword ptr [L]                               = 00000000
//         004a251a     PUSH       s_$$$_HOST_RESET2_CIV+50                         = "$$$ HOST RESET2 CIV+50"
//         004a251f     PUSH       this
//         004a2520     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1378 (31)
//         004a2525     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a252b     ADD        ESP,0x8
//         004a252e     PUSH       ESI
//         004a252f     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a2534     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a253a     SUB        EAX,0x32
//         004a253d     PUSH       EAX
//         004a253e     PUSH       ESI
//         004a253f     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1379 (4)
//         004a2544     MOV        dword ptr [ESP + local_568],EDI
//                               LAB_004a2548                                                 XREF[1]:     004a2512(j)
//                              scr_mps.cpp:1381 (17)
//         004a2548     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a254e     PUSH       ESI
//         004a254f     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a2554     CMP        EAX,0x32
//         004a2557     JL         LAB_004a258d
//                              scr_mps.cpp:1383 (17)
//         004a2559     MOV        EDX,dword ptr [L]                                = 00000000
//         004a255f     PUSH       s_$$$_HOST_RESET2_TEAM+50                        = "$$$ HOST RESET2 TEAM+50"
//         004a2564     PUSH       EDX
//         004a2565     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1384 (31)
//         004a256a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2570     ADD        ESP,0x8
//         004a2573     PUSH       ESI
//         004a2574     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a2579     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a257f     SUB        EAX,0x32
//         004a2582     PUSH       EAX
//         004a2583     PUSH       ESI
//         004a2584     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:1385 (24)
//         004a2589     MOV        dword ptr [ESP + local_568],EDI
//                               LAB_004a258d                                                 XREF[1]:     004a2557(j)
//         004a258d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2593     INC        ESI
//         004a2594     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a2599     CMP        ESI,EAX
//         004a259b     JL         LAB_004a2503
//                               LAB_004a25a1                                                 XREF[2]:     004a24e8(j), 004a24fd(j)
//                              scr_mps.cpp:1391 (19)
//         004a25a1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a25a7     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a25ac     TEST       EAX,EAX
//         004a25ae     JZ         LAB_004a2687
//                              scr_mps.cpp:1400 (43)
//         004a25b4     MOV        this,0x8
//         004a25b9     MOV        EAX,0x1
//         004a25be     LEA        EDI=>temp_team[1],[ESP + 0x18]
//         004a25c2     XOR        EDX,EDX
//         004a25c4     STOSD.REP  ES:EDI
//         004a25c6     MOV        this,0x8
//         004a25cb     LEA        EDI=>temp_civ[1],[ESP + 0x58]
//         004a25cf     STOSD.REP  ES:EDI
//                               LAB_004a25d1                                                 XREF[1]:     004a25dd(j)
//         004a25d1     LEA        EAX,[EDX + 0x1]
//         004a25d4     MOV        dword ptr [ESP + EDX*0x4 + temp_color[2]],EAX
//         004a25d8     MOV        EDX,EAX
//         004a25da     CMP        EDX,0x8
//         004a25dd     JL         LAB_004a25d1
//                              scr_mps.cpp:1402 (7)
//         004a25df     XOR        EBP,EBP
//         004a25e1     MOV        EDI,0x1
//                              scr_mps.cpp:1446 (21)
//         004a25e6     LEA        EBX=>temp_team[1],[ESP + 0x18]
//                               LAB_004a25ea                                                 XREF[1]:     004a2639(j)
//         004a25ea     MOV        this,dword ptr [comm]                            = 00000000
//         004a25f0     PUSH       EDI
//         004a25f1     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         004a25f6     CMP        EAX,0x2
//         004a25f9     JZ         LAB_004a2600
//                              scr_mps.cpp:1405 (5)
//         004a25fb     CMP        EAX,0x4
//         004a25fe     JNZ        LAB_004a2635
//                               LAB_004a2600                                                 XREF[1]:     004a25f9(j)
//                              scr_mps.cpp:1407 (15)
//         004a2600     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2606     LEA        ESI,[EDI + -0x1]
//         004a2609     PUSH       ESI
//         004a260a     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//                              scr_mps.cpp:1408 (16)
//         004a260f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2615     PUSH       ESI
//         004a2616     MOV        dword ptr [ESP + EBP*0x4 + 0x3c],EAX
//         004a261a     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//                              scr_mps.cpp:1409 (18)
//         004a261f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2625     PUSH       ESI
//         004a2626     MOV        dword ptr [ESP + EBP*0x4 + 0x5c],EAX
//         004a262a     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a262f     MOV        dword ptr [EBX]=>temp_team[1],EAX
//                              scr_mps.cpp:1410 (10)
//         004a2631     INC        EBP
//         004a2632     ADD        EBX,0x4
//                               LAB_004a2635                                                 XREF[1]:     004a25fe(j)
//         004a2635     INC        EDI
//         004a2636     CMP        EDI,0x9
//         004a2639     JL         LAB_004a25ea
//                              scr_mps.cpp:1413 (4)
//         004a263b     TEST       EBP,EBP
//         004a263d     JLE        LAB_004a2687
//                              scr_mps.cpp:1415 (2)
//         004a263f     XOR        ESI,ESI
//                              scr_mps.cpp:1446 (62)
//         004a2641     LEA        EDI=>temp_team[1],[ESP + 0x18]
//                               LAB_004a2645                                                 XREF[1]:     004a267d(j)
//         004a2645     MOV        EAX,dword ptr [ESP + ESI*0x4 + temp_color[2]]
//         004a2649     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a264f     PUSH       EAX
//         004a2650     PUSH       ESI
//         004a2651     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//         004a2656     MOV        this,dword ptr [ESP + ESI*0x4 + 0x58]
//         004a265a     PUSH       this
//         004a265b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2661     PUSH       ESI
//         004a2662     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//         004a2667     MOV        EDX,dword ptr [EDI]=>temp_team[1]
//         004a2669     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a266f     PUSH       EDX
//         004a2670     PUSH       ESI
//         004a2671     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//         004a2676     INC        ESI
//         004a2677     ADD        EDI,0x4
//         004a267a     CMP        ESI,0x8
//         004a267d     JL         LAB_004a2645
//                              scr_mps.cpp:1421 (8)
//         004a267f     MOV        dword ptr [ESP + local_568],0x1
//                               LAB_004a2687                                                 XREF[2]:     004a25ae(j), 004a263d(j)
//                              scr_mps.cpp:1425 (15)
//         004a2687     PUSH       s_Status_Screen                                  = "Status Screen"
//         004a268c     MOV        this,panel_system
//         004a2691     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:1428 (15)
//         004a2696     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a269c     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a26a1     TEST       EAX,EAX
//         004a26a3     JZ         LAB_004a2703
//                              scr_mps.cpp:1430 (22)
//         004a26a5     MOV        EAX,dword ptr [ESP + local_568]
//         004a26a9     TEST       EAX,EAX
//         004a26ab     JNZ        LAB_004a26bb
//         004a26ad     MOV        EAX,dword ptr [ESP + temp_team[0]]
//         004a26b1     MOV        this,dword ptr [EAX + 0x88c]
//         004a26b7     TEST       this,this
//         004a26b9     JZ         LAB_004a26d4
//                               LAB_004a26bb                                                 XREF[1]:     004a26ab(j)
//                              scr_mps.cpp:1432 (11)
//         004a26bb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a26c1     MOV        EDX,dword ptr [this->_padding_]
//         004a26c3     CALL       dword ptr [EDX + 0x48]
//                              scr_mps.cpp:1433 (14)
//         004a26c6     MOV        EAX,dword ptr [ESP + 0x14]
//         004a26ca     MOV        dword ptr [EAX + 0x88c],0x0
//                               LAB_004a26d4                                                 XREF[1]:     004a26b9(j)
//                              scr_mps.cpp:1435 (11)
//         004a26d4     MOV        this,dword ptr [comm]                            = 00000000
//         004a26da     CALL       TCommunications_Handler::LaunchMultiplayerGame   void LaunchMultiplayerGame(TCommunications_Ha
//                              scr_mps.cpp:1436 (18)
//         004a26df     MOV        this,dword ptr [AppWnd]                          = 00000000
//         004a26e5     PUSH       this
//         004a26e6     MOV        this,dword ptr [chat]                            = 00000000
//         004a26ec     CALL       TChat::setWindowHandle                           void setWindowHandle(TChat * this, void * par
//                              scr_mps.cpp:1437 (18)
//         004a26f1     MOV        EDX,dword ptr [AppWnd]                           = 00000000
//         004a26f7     MOV        this,dword ptr [comm]                            = 00000000
//         004a26fd     PUSH       EDX
//         004a26fe     CALL       TCommunications_Handler::SetWindowHandle         void * SetWindowHandle(TCommunications_Handle
//                               LAB_004a2703                                                 XREF[1]:     004a26a3(j)
//                              scr_mps.cpp:1439 (17)
//         004a2703     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2709     PUSH       0x0
//         004a270b     CALL       TRIBE_Game::start_game                           int start_game(TRIBE_Game * this, int param_1)
//         004a2710     TEST       EAX,EAX
//         004a2712     JNZ        LAB_004a2737
//                              scr_mps.cpp:1441 (22)
//         004a2714     MOV        this,dword ptr [ESP + 0x14]
//         004a2718     PUSH       0x64
//         004a271a     PUSH       offset DAT_fffffff8
//         004a271f     PUSH       EAX=>DAT_fffffff4
//                              language.dll match for 0x961: "An error occurred while trying
//         004a2720     PUSH       offset DAT_fffffff0
//         004a2725     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                              scr_mps.cpp:1442 (2)
//         004a272a     XOR        EAX,EAX
//                              scr_mps.cpp:1446 (11)
//         004a272c     POP        EDI
//         004a272d     POP        ESI
//         004a272e     POP        EBP
//         004a272f     POP        EBX
//         004a2730     ADD        ESP,0x568
//         004a2736     RET
//                               LAB_004a2737                                                 XREF[1]:     004a2712(j)
//                              scr_mps.cpp:1445 (5)
//         004a2737     MOV        EAX,0x1
//                              scr_mps.cpp:1446 (11)
//         004a273c     POP        EDI
//         004a273d     POP        ESI
//         004a273e     POP        EBP
//         004a273f     POP        EBX
//         004a2740     ADD        ESP,0x568
//         004a2746     RET
//                               LAB_004a2747                                                 XREF[1]:     004a211b(j)
//                              scr_mps.cpp:1199 (43)
//         004a2747     MOV        this,dword ptr [comm]                            = 00000000
//         004a274d     INC        EBX
//         004a274e     PUSH       EBX
//         004a274f     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler
//         004a2754     PUSH       EAX
//                              language.dll match for 0x25e1: "%s does not have this scenari
//         004a2755     PUSH       0x25e1
//         004a275a     MOV        this,EBP
//         004a275c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a2761     LEA        this=>msg[4],[ESP + 0x17c]
//         004a2768     PUSH       EAX
//         004a2769     PUSH       this
//         004a276a     CALL       sprintf                                          undefined sprintf()
//         004a276f     ADD        ESP,0xc
//                              scr_mps.cpp:1200 (24)
//         004a2772     LEA        EDX=>msg[4],[ESP + 0x178]
//         004a2779     MOV        this,EBP
//         004a277b     PUSH       0x64
//         004a277d     PUSH       0x1c2
//         004a2782     PUSH       0x0
//         004a2784     PUSH       EDX
//         004a2785     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1446 (13)
//         004a278a     POP        EDI
//         004a278b     POP        ESI
//         004a278c     POP        EBP
//         004a278d     XOR        EAX,EAX
//         004a278f     POP        EBX
//         004a2790     ADD        ESP,0x568
//         004a2796     RET
//         004a2797     ??         90h
//         004a2798     NOP
//         004a2799     NOP
//         004a279a     NOP
//         004a279b     NOP
//         004a279c     NOP
//         004a279d     NOP
//         004a279e     NOP
//         004a279f     NOP
    return 0;
}

void TribeMPSetupScreen::calcRandomPositions() {
    /* TODO: Stub */
//                              void __thiscall calcRandomPositions(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              int[8]            Stack[-0x24]   position_used             XREF[2,5]:   004a2841(W), 004a28ed(R), 004a27e9(*), 004a2802(*),
//                                                                                     004a280a(*), 004a2868(*), 004a286c(*)
//              undefined4        Stack[-0x28]:4 local_28                  XREF[3]:     004a287b(W), 004a28d0(R), 004a28d8(W)
//              int               Stack[-0x2c]:4 pos                       XREF[3]:     004a27a5(W), 004a27ed(R), 004a2858(R)
//                               ?calcRandomPositions@TribeMPSetupScreen@@IAEXXZ              XREF[1]:     startGame:004a2481(c)
//                               TribeMPSetupScreen::calcRandomPositions
//                              scr_mps.cpp:1452 (10)
//         004a27a0     SUB        ESP,0x2c
//         004a27a3     PUSH       EBX
//         004a27a4     PUSH       EBP
//         004a27a5     MOV        dword ptr [ESP + pos],this
//         004a27a9     PUSH       ESI
//                              scr_mps.cpp:1462 (20)
//         004a27aa     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a27b0     PUSH       EDI
//         004a27b1     XOR        EBP,EBP
//         004a27b3     XOR        ESI,ESI
//         004a27b5     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a27ba     TEST       EAX,EAX
//         004a27bc     JLE        LAB_004a27e5
//                               LAB_004a27be                                                 XREF[1]:     004a27e3(j)
//                              scr_mps.cpp:1464 (13)
//         004a27be     MOV        this,dword ptr [comm]                            = 00000000
//         004a27c4     INC        ESI
//         004a27c5     PUSH       ESI
//         004a27c6     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//                              scr_mps.cpp:1465 (10)
//         004a27cb     CMP        EAX,0x2
//         004a27ce     JZ         LAB_004a27d5
//         004a27d0     CMP        EAX,0x4
//         004a27d3     JNZ        LAB_004a27d6
//                               LAB_004a27d5                                                 XREF[1]:     004a27ce(j)
//                              scr_mps.cpp:1466 (1)
//         004a27d5     INC        EBP
//                               LAB_004a27d6                                                 XREF[1]:     004a27d3(j)
//                              scr_mps.cpp:1462 (15)
//         004a27d6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a27dc     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a27e1     CMP        ESI,EAX
//         004a27e3     JL         LAB_004a27be
//                               LAB_004a27e5                                                 XREF[1]:     004a27bc(j)
//                              scr_mps.cpp:1472 (2)
//         004a27e5     XOR        EBX,EBX
//                              scr_mps.cpp:1473 (6)
//         004a27e7     XOR        ESI,ESI
//         004a27e9     LEA        EDI=>position_used[1],[ESP + 0x1c]
//                               LAB_004a27ed                                                 XREF[1]:     004a2818(j)
//                              scr_mps.cpp:1475 (21)
//         004a27ed     MOV        EAX,dword ptr [ESP + pos]
//         004a27f1     PUSH       ESI
//         004a27f2     MOV        this,dword ptr [EAX + 0x5f0]
//         004a27f8     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004a27fd     CMP        EAX,-0x1
//         004a2800     JNZ        LAB_004a280a
//                              scr_mps.cpp:1476 (6)
//         004a2802     MOV        dword ptr [EDI]=>position_used[1],0xfffffffe
//                              scr_mps.cpp:1477 (2)
//         004a2808     JMP        LAB_004a2811
//                               LAB_004a280a                                                 XREF[1]:     004a2800(j)
//                              scr_mps.cpp:1479 (6)
//         004a280a     MOV        dword ptr [EDI]=>position_used[1],0xffffffff
//                              scr_mps.cpp:1480 (10)
//         004a2810     INC        EBX
//                               LAB_004a2811                                                 XREF[1]:     004a2808(j)
//         004a2811     INC        ESI
//         004a2812     ADD        EDI,0x4
//         004a2815     CMP        ESI,0x8
//         004a2818     JL         LAB_004a27ed
//                              scr_mps.cpp:1487 (8)
//         004a281a     CMP        EBP,EBX
//         004a281c     JG         LAB_004a2906
//                              scr_mps.cpp:1489 (21)
//         004a2822     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2828     XOR        EBP,EBP
//         004a282a     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a282f     TEST       EAX,EAX
//         004a2831     JLE        LAB_004a2906
//                               LAB_004a2837                                                 XREF[1]:     004a2900(j)
//                              scr_mps.cpp:1491 (19)
//         004a2837     MOV        this,dword ptr [comm]                            = 00000000
//         004a283d     LEA        ESI,[EBP + 0x1]
//         004a2840     PUSH       ESI
//         004a2841     MOV        dword ptr [ESP + position_used[0]],ESI
//         004a2845     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//                              scr_mps.cpp:1492 (14)
//         004a284a     CMP        EAX,0x2
//         004a284d     JZ         LAB_004a2858
//         004a284f     CMP        EAX,0x4
//         004a2852     JNZ        LAB_004a28f1
//                               LAB_004a2858                                                 XREF[1]:     004a284d(j)
//                              scr_mps.cpp:1496 (20)
//         004a2858     MOV        EBX,dword ptr [ESP + pos]
//         004a285c     XOR        EAX,EAX
//         004a285e     MOV        this,dword ptr [EBX + 0x728]
//         004a2864     TEST       this,this
//         004a2866     JLE        LAB_004a287f
//         004a2868     LEA        EDX=>position_used[1],[ESP + 0x1c]
//                               LAB_004a286c                                                 XREF[1]:     004a2877(j)
//                              scr_mps.cpp:1498 (15)
//         004a286c     CMP        dword ptr [EDX]=>position_used[1],-0x1
//         004a286f     JZ         LAB_004a287b
//         004a2871     INC        EAX
//         004a2872     ADD        EDX,0x4
//         004a2875     CMP        EAX,this
//         004a2877     JL         LAB_004a286c
//         004a2879     JMP        LAB_004a287f
//                               LAB_004a287b                                                 XREF[1]:     004a286f(j)
//                              scr_mps.cpp:1500 (4)
//         004a287b     MOV        dword ptr [ESP + local_28],EAX
//                               LAB_004a287f                                                 XREF[2]:     004a2866(j), 004a2879(j)
//                              scr_mps.cpp:1506 (2)
//         004a287f     XOR        EDI,EDI
//                               LAB_004a2881                                                 XREF[1]:     004a28ce(j)
//                              scr_mps.cpp:1508 (48)
//         004a2881     MOV        ESI,dword ptr [EBX + 0x728]
//         004a2887     PUSH       0x5e4
//         004a288c     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a2891     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004a2896     MOV        this,EAX
//         004a2898     MOV        EAX,0x80010003
//         004a289d     IMUL       this,ESI
//         004a28a0     IMUL       this
//         004a28a2     ADD        EDX,this
//         004a28a4     ADD        ESP,0x8
//         004a28a7     SAR        EDX,0xe
//         004a28aa     MOV        this,EDX
//         004a28ac     SHR        this,0x1f
//         004a28af     ADD        EDX,this
//                              scr_mps.cpp:1509 (4)
//         004a28b1     CMP        EDX,ESI
//         004a28b3     JL         LAB_004a28ba
//                              scr_mps.cpp:1510 (3)
//         004a28b5     LEA        EDX,[ESI + -0x1]
//                              scr_mps.cpp:1511 (6)
//         004a28b8     JMP        LAB_004a28c0
//                               LAB_004a28ba                                                 XREF[1]:     004a28b3(j)
//         004a28ba     TEST       EDX,EDX
//         004a28bc     JGE        LAB_004a28c0
//                              scr_mps.cpp:1512 (2)
//         004a28be     XOR        EDX,EDX
//                               LAB_004a28c0                                                 XREF[2]:     004a28b8(j), 004a28bc(j)
//                              scr_mps.cpp:1513 (16)
//         004a28c0     CMP        dword ptr [ESP + EDX*0x4 + 0x1c],-0x1
//         004a28c5     JZ         LAB_004a28d6
//         004a28c7     INC        EDI
//         004a28c8     CMP        EDI,0x3e8
//         004a28ce     JL         LAB_004a2881
//                              scr_mps.cpp:1515 (12)
//         004a28d0     MOV        ESI,dword ptr [ESP + local_28]
//         004a28d4     JMP        LAB_004a28dc
//                               LAB_004a28d6                                                 XREF[1]:     004a28c5(j)
//         004a28d6     MOV        ESI,EDX
//         004a28d8     MOV        dword ptr [ESP + local_28],ESI
//                               LAB_004a28dc                                                 XREF[1]:     004a28d4(j)
//                              scr_mps.cpp:1521 (13)
//         004a28dc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a28e2     PUSH       ESI
//         004a28e3     PUSH       EBP
//         004a28e4     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1522 (29)
//         004a28e9     MOV        dword ptr [ESP + ESI*0x4 + 0x1c],EBP
//         004a28ed     MOV        ESI,dword ptr [ESP + position_used[0]]
//                               LAB_004a28f1                                                 XREF[1]:     004a2852(j)
//         004a28f1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a28f7     MOV        EBP,ESI
//         004a28f9     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a28fe     CMP        EBP,EAX
//         004a2900     JL         LAB_004a2837
//                               LAB_004a2906                                                 XREF[2]:     004a281c(j), 004a2831(j)
//                              scr_mps.cpp:1526 (8)
//         004a2906     POP        EDI
//         004a2907     POP        ESI
//         004a2908     POP        EBP
//         004a2909     POP        EBX
//         004a290a     ADD        ESP,0x2c
//         004a290d     RET
//         004a290e     ??         90h
//         004a290f     NOP
    return;
}

void TribeMPSetupScreen::showNetInfo() {
    /* TODO: Stub */
//                              void __thiscall showNetInfo(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a2948(W), 004a296b(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a2b7c(R)
//              char[256]         Stack[-0x110   temp_str                  XREF[0,2]:   004a29d6(*), 004a29e3(*)
//              char[1024]        Stack[-0x510   message                   XREF[2,9]:   004a2936(W), 004a2b41(R), 004a2982(W), 004a299d(*),
//                                                                                     004a29f8(*), 004a2a11(*), 004a2a6b(*), 004a2a8a(*),
//                                                                                     004a2ad6(*), 004a2b04(*), 004a2b38(*)
//              undefined4        Stack[-0x514   local_514                 XREF[4]:     004a2942(W), 004a2989(W), 004a2a3b(R), 004a2b21(R)
//              uint              Stack[-0x518   num_addr
//                               ?showNetInfo@TribeMPSetupScreen@@IAEXXZ                      XREF[1]:     action:004a1b5c(c)
//                               TribeMPSetupScreen::showNetInfo
//                              scr_mps.cpp:1532 (33)
//         004a2910     PUSH       -0x1
//         004a2912     PUSH       FUN_0055f1fe
//         004a2917     MOV        EAX,FS:[0x0]
//         004a291d     PUSH       EAX
//         004a291e     MOV        dword ptr FS:[0x0],ESP
//         004a2925     SUB        ESP,0x508
//         004a292b     PUSH       EBX
//         004a292c     PUSH       EBP
//         004a292d     PUSH       ESI
//         004a292e     PUSH       EDI
//         004a292f     MOV        EBX,this
//                              scr_mps.cpp:1533 (56)
//         004a2931     PUSH       0x224
//         004a2936     MOV        dword ptr [ESP + message[0]],EBX
//         004a293a     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a293f     ADD        ESP,0x4
//         004a2942     MOV        dword ptr [ESP + local_514],EAX
//         004a2946     TEST       EAX,EAX
//         004a2948     MOV        dword ptr [ESP + local_4],0x0
//         004a2953     JZ         LAB_004a2967
//         004a2955     MOV        this,dword ptr [comm]                            = 00000000
//         004a295b     PUSH       this
//         004a295c     MOV        this,EAX
//         004a295e     CALL       RGE_Communications_Addresses::RGE_Communicatio   undefined RGE_Communications_Addresses(RGE_Co
//         004a2963     MOV        EBP,EAX
//         004a2965     JMP        LAB_004a2969
//                               LAB_004a2967                                                 XREF[1]:     004a2953(j)
//         004a2967     XOR        EBP,EBP
//                               LAB_004a2969                                                 XREF[1]:     004a2965(j)
//                              scr_mps.cpp:1534 (19)
//         004a2969     TEST       EBP,EBP
//         004a296b     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a2976     JZ         LAB_004a2b7c
//                              scr_mps.cpp:1539 (11)
//         004a297c     MOV        EAX,dword ptr [EBP + 0x218]
//         004a2982     MOV        byte ptr [ESP + message[4]],0x0
//                              scr_mps.cpp:1541 (12)
//         004a2987     TEST       EAX,EAX
//         004a2989     MOV        dword ptr [ESP + local_514],EAX
//         004a298d     JBE        LAB_004a2b57
//                              scr_mps.cpp:1543 (46)
//         004a2993     MOV        EDI,s___                                         = 0Ah
//         004a2998     OR         this,0xffffffff
//         004a299b     XOR        EAX,EAX
//         004a299d     LEA        EDX=>message[4],[ESP + 0x18]
//         004a29a1     SCASB.RE   ES:EDI=>s___                                     = 0Ah
//         004a29a3     NOT        this
//         004a29a5     SUB        EDI,this
//         004a29a7     MOV        ESI,EDI
//         004a29a9     MOV        EDI,EDX
//         004a29ab     MOV        EDX,this
//         004a29ad     OR         this,0xffffffff
//         004a29b0     SCASB.RE   ES:EDI
//         004a29b2     MOV        this,EDX
//         004a29b4     DEC        EDI
//         004a29b5     SHR        this,0x2
//         004a29b8     MOVSD.REP  ES:EDI,ESI
//         004a29ba     MOV        this,EDX
//         004a29bc     AND        this,0x3
//         004a29bf     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:1546 (34)
//         004a29c1     MOV        this,EBP
//         004a29c3     CALL       RGE_Communications_Addresses::GetHostName        char * GetHostName(RGE_Communications_Address
//         004a29c8     PUSH       EAX
//                              language.dll match for 0x238c: "Host name: %s"
//         004a29c9     PUSH       0x238c
//         004a29ce     MOV        this,EBX
//         004a29d0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a29d5     PUSH       EAX
//         004a29d6     LEA        EAX=>temp_str[4],[ESP + 0x420]
//         004a29dd     PUSH       EAX
//         004a29de     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:1548 (46)
//         004a29e3     LEA        EDI=>temp_str[4],[ESP + 0x424]
//         004a29ea     OR         this,0xffffffff
//         004a29ed     XOR        EAX,EAX
//         004a29ef     ADD        ESP,0xc
//         004a29f2     SCASB.RE   ES:EDI
//         004a29f4     NOT        this
//         004a29f6     SUB        EDI,this
//         004a29f8     LEA        EDX=>message[4],[ESP + 0x18]
//         004a29fc     MOV        ESI,EDI
//         004a29fe     MOV        EBX,this
//         004a2a00     MOV        EDI,EDX
//         004a2a02     OR         this,0xffffffff
//         004a2a05     SCASB.RE   ES:EDI
//         004a2a07     MOV        this,EBX
//         004a2a09     DEC        EDI
//         004a2a0a     SHR        this,0x2
//         004a2a0d     MOVSD.REP  ES:EDI,ESI
//         004a2a0f     MOV        this,EBX
//                              scr_mps.cpp:1549 (42)
//         004a2a11     LEA        EDX=>message[4],[ESP + 0x18]
//         004a2a15     AND        this,0x3
//         004a2a18     MOVSB.REP  ES:EDI,ESI
//         004a2a1a     MOV        EDI,s__                                          = 0Ah
//         004a2a1f     OR         this,0xffffffff
//         004a2a22     SCASB.RE   ES:EDI=>s__                                      = 0Ah
//         004a2a24     NOT        this
//         004a2a26     SUB        EDI,this
//         004a2a28     MOV        ESI,EDI
//         004a2a2a     MOV        EBX,this
//         004a2a2c     MOV        EDI,EDX
//         004a2a2e     OR         this,0xffffffff
//         004a2a31     SCASB.RE   ES:EDI
//         004a2a33     MOV        this,EBX
//         004a2a35     DEC        EDI
//         004a2a36     SHR        this,0x2
//         004a2a39     MOVSD.REP  ES:EDI,ESI
//                              scr_mps.cpp:1551 (21)
//         004a2a3b     MOV        EAX,dword ptr [ESP + local_514]
//         004a2a3f     MOV        this,EBX
//         004a2a41     AND        this,0x3
//         004a2a44     XOR        EBX,EBX
//         004a2a46     TEST       EAX,EAX
//         004a2a48     MOVSB.REP  ES:EDI,ESI
//         004a2a4a     JBE        LAB_004a2b35
//                               LAB_004a2a50                                                 XREF[1]:     004a2b2f(j)
//                              scr_mps.cpp:1553 (12)
//         004a2a50     PUSH       EBX
//         004a2a51     MOV        this,EBP
//         004a2a53     CALL       RGE_Communications_Addresses::GetAddress         char * GetAddress(RGE_Communications_Addresse
//         004a2a58     TEST       EAX,EAX
//         004a2a5a     JZ         LAB_004a2abb
//                              scr_mps.cpp:1555 (46)
//         004a2a5c     PUSH       EBX
//         004a2a5d     MOV        this,EBP
//         004a2a5f     CALL       RGE_Communications_Addresses::GetAddress         char * GetAddress(RGE_Communications_Addresse
//         004a2a64     MOV        EDI,EAX
//         004a2a66     OR         this,0xffffffff
//         004a2a69     XOR        EAX,EAX
//         004a2a6b     LEA        EDX=>message[4],[ESP + 0x18]
//         004a2a6f     SCASB.RE   ES:EDI
//         004a2a71     NOT        this
//         004a2a73     SUB        EDI,this
//         004a2a75     MOV        ESI,EDI
//         004a2a77     MOV        EDI,EDX
//         004a2a79     MOV        EDX,this
//         004a2a7b     OR         this,0xffffffff
//         004a2a7e     SCASB.RE   ES:EDI
//         004a2a80     MOV        this,EDX
//         004a2a82     DEC        EDI
//         004a2a83     SHR        this,0x2
//         004a2a86     MOVSD.REP  ES:EDI,ESI
//         004a2a88     MOV        this,EDX
//                              scr_mps.cpp:1556 (49)
//         004a2a8a     LEA        EDX=>message[4],[ESP + 0x18]
//         004a2a8e     AND        this,0x3
//         004a2a91     MOVSB.REP  ES:EDI,ESI
//         004a2a93     MOV        EDI,s__                                          = 20h
//         004a2a98     OR         this,0xffffffff
//         004a2a9b     SCASB.RE   ES:EDI=>s__                                      = 20h
//         004a2a9d     NOT        this
//         004a2a9f     SUB        EDI,this
//         004a2aa1     MOV        ESI,EDI
//         004a2aa3     MOV        EDI,EDX
//         004a2aa5     MOV        EDX,this
//         004a2aa7     OR         this,0xffffffff
//         004a2aaa     SCASB.RE   ES:EDI
//         004a2aac     MOV        this,EDX
//         004a2aae     DEC        EDI
//         004a2aaf     SHR        this,0x2
//         004a2ab2     MOVSD.REP  ES:EDI,ESI
//         004a2ab4     MOV        this,EDX
//         004a2ab6     AND        this,0x3
//         004a2ab9     MOVSB.REP  ES:EDI,ESI
//                               LAB_004a2abb                                                 XREF[1]:     004a2a5a(j)
//                              scr_mps.cpp:1558 (12)
//         004a2abb     PUSH       EBX
//         004a2abc     MOV        this,EBP
//         004a2abe     CALL       RGE_Communications_Addresses::GetAlias           char * GetAlias(RGE_Communications_Addresses
//         004a2ac3     TEST       EAX,EAX
//         004a2ac5     JZ         LAB_004a2afa
//                              scr_mps.cpp:1559 (51)
//         004a2ac7     PUSH       EBX
//         004a2ac8     MOV        this,EBP
//         004a2aca     CALL       RGE_Communications_Addresses::GetAlias           char * GetAlias(RGE_Communications_Addresses
//         004a2acf     MOV        EDI,EAX
//         004a2ad1     OR         this,0xffffffff
//         004a2ad4     XOR        EAX,EAX
//         004a2ad6     LEA        EDX=>message[4],[ESP + 0x18]
//         004a2ada     SCASB.RE   ES:EDI
//         004a2adc     NOT        this
//         004a2ade     SUB        EDI,this
//         004a2ae0     MOV        ESI,EDI
//         004a2ae2     MOV        EDI,EDX
//         004a2ae4     MOV        EDX,this
//         004a2ae6     OR         this,0xffffffff
//         004a2ae9     SCASB.RE   ES:EDI
//         004a2aeb     MOV        this,EDX
//         004a2aed     DEC        EDI
//         004a2aee     SHR        this,0x2
//         004a2af1     MOVSD.REP  ES:EDI,ESI
//         004a2af3     MOV        this,EDX
//         004a2af5     AND        this,0x3
//         004a2af8     MOVSB.REP  ES:EDI,ESI
//                               LAB_004a2afa                                                 XREF[1]:     004a2ac5(j)
//                              scr_mps.cpp:1560 (59)
//         004a2afa     MOV        EDI,s__                                          = 0Ah
//         004a2aff     OR         this,0xffffffff
//         004a2b02     XOR        EAX,EAX
//         004a2b04     LEA        EDX=>message[4],[ESP + 0x18]
//         004a2b08     SCASB.RE   ES:EDI=>s__                                      = 0Ah
//         004a2b0a     NOT        this
//         004a2b0c     SUB        EDI,this
//         004a2b0e     MOV        ESI,EDI
//         004a2b10     MOV        EDI,EDX
//         004a2b12     MOV        EDX,this
//         004a2b14     OR         this,0xffffffff
//         004a2b17     SCASB.RE   ES:EDI
//         004a2b19     MOV        this,EDX
//         004a2b1b     DEC        EDI
//         004a2b1c     SHR        this,0x2
//         004a2b1f     MOVSD.REP  ES:EDI,ESI
//         004a2b21     MOV        EAX,dword ptr [ESP + local_514]
//         004a2b25     MOV        this,EDX
//         004a2b27     AND        this,0x3
//         004a2b2a     INC        EBX
//         004a2b2b     CMP        EBX,EAX
//         004a2b2d     MOVSB.REP  ES:EDI,ESI
//         004a2b2f     JC         LAB_004a2a50
//                               LAB_004a2b35                                                 XREF[1]:     004a2a4a(j)
//                              scr_mps.cpp:1563 (32)
//         004a2b35     LEA        EAX,[EAX + EAX*0x8]
//         004a2b38     LEA        EDX=>message[4],[ESP + 0x18]
//         004a2b3c     LEA        this,[EAX + EAX*0x1 + 0x64]
//         004a2b40     PUSH       this
//         004a2b41     MOV        this,dword ptr [ESP + message[0]]
//         004a2b45     PUSH       0x1c2
//         004a2b4a     PUSH       s_OKDialog                                       = 4Fh
//         004a2b4f     PUSH       EDX
//         004a2b50     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1565 (2)
//         004a2b55     JMP        LAB_004a2b6c
//                               LAB_004a2b57                                                 XREF[1]:     004a298d(j)
//                              scr_mps.cpp:1566 (21)
//         004a2b57     PUSH       0x64
//         004a2b59     PUSH       0x1c2
//         004a2b5e     PUSH       0x0
//                              language.dll match for 0x238d: "No IP addressing information
//         004a2b60     PUSH       0x238d
//         004a2b65     MOV        this,EBX
//         004a2b67     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                               LAB_004a2b6c                                                 XREF[1]:     004a2b55(j)
//                              scr_mps.cpp:1568 (16)
//         004a2b6c     MOV        this,EBP
//         004a2b6e     CALL       RGE_Communications_Addresses::~RGE_Communicati   void ~RGE_Communications_Addresses(RGE_Commun
//         004a2b73     PUSH       EBP
//         004a2b74     CALL       operator_delete                                  void operator_delete(void * param_1)
//         004a2b79     ADD        ESP,0x4
//                               LAB_004a2b7c                                                 XREF[1]:     004a2976(j)
//                              scr_mps.cpp:1570 (25)
//         004a2b7c     MOV        this,dword ptr [ESP + local_c]
//         004a2b83     POP        EDI
//         004a2b84     POP        ESI
//         004a2b85     POP        EBP
//         004a2b86     MOV        dword ptr FS:[0x0],this
//         004a2b8d     POP        EBX
//         004a2b8e     ADD        ESP,0x514
//         004a2b94     RET
//         004a2b95     ??         90h
//         004a2b96     NOP
//         004a2b97     NOP
//         004a2b98     NOP
//         004a2b99     NOP
//         004a2b9a     NOP
//         004a2b9b     NOP
//         004a2b9c     NOP
//         004a2b9d     NOP
//         004a2b9e     NOP
//         004a2b9f     NOP
    return;
}

void TribeMPSetupScreen::cancelScreen(int param_1) {
    /* TODO: Stub */
//                              void __thiscall cancelScreen(TribeMPSetupScreen * this, int param_1)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[5]:     004a2bef(W), 004a2c27(W), 004a2c61(R), 004a2c76(W),
//                                                                                     004a2cfd(W)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[8]:     004a2bf5(W), 004a2c08(W), 004a2c2d(W), 004a2c40(W),
//                                                                                     004a2c7c(W), 004a2c93(W), 004a2d03(W), 004a2d16(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[2]:     004a2cc7(*), 004a2d3c(*)
//                               ?cancelScreen@TribeMPSetupScreen@@IAEXH@Z                    XREF[4]:     action:004a1b3e(c),
//                               TribeMPSetupScreen::cancelScreen                                          handle_user_command:004a36b4(c),
//                                                                                                         handle_user_command:004a3701(c),
//                                                                                                         handleKickedPlayer:004a5022(c)
//                              scr_mps.cpp:1576 (6)
//         004a2ba0     MOV        EAX,FS:[0x0]
//                              scr_mps.cpp:1577 (34)
//         004a2ba6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2bac     PUSH       -0x1
//         004a2bae     PUSH       FUN_0055f23c
//         004a2bb3     PUSH       EAX
//         004a2bb4     MOV        dword ptr FS:[0x0],ESP
//         004a2bbb     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a2bc0     TEST       EAX,EAX
//         004a2bc2     JZ         LAB_004a2c52
//                              scr_mps.cpp:1580 (11)
//         004a2bc8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2bce     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
//                              scr_mps.cpp:1581 (15)
//         004a2bd3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2bd9     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a2bde     TEST       EAX,EAX
//         004a2be0     JZ         LAB_004a2c1a
//                              scr_mps.cpp:1583 (36)
//         004a2be2     PUSH       0x4d8
//         004a2be7     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a2bec     ADD        ESP,0x4
//         004a2bef     MOV        dword ptr [ESP + param_1],EAX
//         004a2bf3     TEST       EAX,EAX
//         004a2bf5     MOV        dword ptr [ESP + local_4],0x0
//         004a2bfd     JZ         LAB_004a2c06
//         004a2bff     MOV        this,EAX
//         004a2c01     CALL       TribeSelectScenarioScreen::TribeSelectScenario   undefined TribeSelectScenarioScreen(TribeSele
//                               LAB_004a2c06                                                 XREF[1]:     004a2bfd(j)
//                              scr_mps.cpp:1584 (15)
//         004a2c06     PUSH       0x0
//         004a2c08     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a2c10     PUSH       s_Select_Scenario_Screen                         = "Select Scenario Screen"
//                              scr_mps.cpp:1586 (5)
//         004a2c15     JMP        LAB_004a2d23
//                               LAB_004a2c1a                                                 XREF[1]:     004a2be0(j)
//                              scr_mps.cpp:1588 (36)
//         004a2c1a     PUSH       0x49c
//         004a2c1f     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a2c24     ADD        ESP,0x4
//         004a2c27     MOV        dword ptr [ESP + param_1],EAX
//         004a2c2b     TEST       EAX,EAX
//         004a2c2d     MOV        dword ptr [ESP + local_4],0x1
//         004a2c35     JZ         LAB_004a2c3e
//         004a2c37     MOV        this,EAX
//         004a2c39     CALL       TribeSPMenuScreen::TribeSPMenuScreen             undefined TribeSPMenuScreen(TribeSPMenuScreen
//                               LAB_004a2c3e                                                 XREF[1]:     004a2c35(j)
//                              scr_mps.cpp:1589 (15)
//         004a2c3e     PUSH       0x0
//         004a2c40     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a2c48     PUSH       s_Single_Player_Menu                             = "Single Player Menu"
//                              scr_mps.cpp:1593 (5)
//         004a2c4d     JMP        LAB_004a2d23
//                               LAB_004a2c52                                                 XREF[1]:     004a2bc2(j)
//                              scr_mps.cpp:1596 (15)
//         004a2c52     MOV        this,dword ptr [comm]                            = 00000000
//         004a2c58     CALL       TCommunications_Handler::IsLobbyLaunched         int IsLobbyLaunched(TCommunications_Handler *
//         004a2c5d     TEST       EAX,EAX
//         004a2c5f     JZ         LAB_004a2cd8
//                              scr_mps.cpp:1598 (8)
//         004a2c61     MOV        EAX,dword ptr [ESP + param_1]
//         004a2c65     TEST       EAX,EAX
//         004a2c67     JZ         LAB_004a2cbc
//                              scr_mps.cpp:1600 (40)
//         004a2c69     PUSH       0x484
//         004a2c6e     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a2c73     ADD        ESP,0x4
//         004a2c76     MOV        dword ptr [ESP + param_1],EAX
//         004a2c7a     TEST       EAX,EAX
//         004a2c7c     MOV        dword ptr [ESP + local_4],0x2
//         004a2c84     JZ         LAB_004a2c8f
//         004a2c86     MOV        this,EAX
//         004a2c88     CALL       TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error undefined TRIBE_Screen_Main_Error(TRIBE_Scree
//         004a2c8d     JMP        LAB_004a2c91
//                               LAB_004a2c8f                                                 XREF[1]:     004a2c84(j)
//         004a2c8f     XOR        EAX,EAX
//                               LAB_004a2c91                                                 XREF[1]:     004a2c8d(j)
//                              scr_mps.cpp:1601 (22)
//         004a2c91     TEST       EAX,EAX
//         004a2c93     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a2c9b     JZ         LAB_004a2cbc
//         004a2c9d     MOV        this,dword ptr [EAX + 0xd8]
//         004a2ca3     TEST       this,this
//         004a2ca5     JNZ        LAB_004a2cbc
//                              language.dll match for 0x96a: "Timed out while trying to conn
//                              scr_mps.cpp:1603 (12)
//         004a2ca7     PUSH       0x96a
//         004a2cac     MOV        this,EAX
//         004a2cae     CALL       TRIBE_Screen_Main_Error::set_text                void set_text(TRIBE_Screen_Main_Error * this,
//                              scr_mps.cpp:1604 (7)
//         004a2cb3     PUSH       0x0
//         004a2cb5     PUSH       s_Main_Error_Screen                              = "Main Error Screen"
//                              scr_mps.cpp:1606 (2)
//         004a2cba     JMP        LAB_004a2d23
//                               LAB_004a2cbc                                                 XREF[3]:     004a2c67(j), 004a2c9b(j),
//                                                                                                         004a2ca5(j)
//                              scr_mps.cpp:1609 (11)
//         004a2cbc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2cc2     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              scr_mps.cpp:1622 (17)
//         004a2cc7     MOV        this,dword ptr [ESP]=>local_c
//         004a2ccb     MOV        dword ptr FS:[0x0],this
//         004a2cd2     ADD        ESP,0xc
//         004a2cd5     RET        0x4
//                               LAB_004a2cd8                                                 XREF[1]:     004a2c5f(j)
//                              scr_mps.cpp:1613 (11)
//         004a2cd8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2cde     CALL       RGE_Base_Game::disable_input                     void disable_input(RGE_Base_Game * this)
//                              scr_mps.cpp:1615 (13)
//         004a2ce3     MOV        this,dword ptr [comm]                            = 00000000
//         004a2ce9     PUSH       0x5
//         004a2ceb     CALL       TCommunications_Handler::UnlinkToLevel           COMMSTATUS UnlinkToLevel(TCommunications_Hand
//                              language.dll match for 0x4b0: "Ready"
//                              scr_mps.cpp:1618 (36)
//         004a2cf0     PUSH       0x4b0
//         004a2cf5     CALL       operator_new                                     void * operator_new(uint param_1)
//         004a2cfa     ADD        ESP,0x4
//         004a2cfd     MOV        dword ptr [ESP + param_1],EAX
//         004a2d01     TEST       EAX,EAX
//         004a2d03     MOV        dword ptr [ESP + local_4],0x3
//         004a2d0b     JZ         LAB_004a2d14
//         004a2d0d     MOV        this,EAX
//         004a2d0f     CALL       TribeJoinScreen::TribeJoinScreen                 undefined TribeJoinScreen(TribeJoinScreen * t
//                               LAB_004a2d14                                                 XREF[1]:     004a2d0b(j)
//                              scr_mps.cpp:1619 (25)
//         004a2d14     PUSH       0x0
//         004a2d16     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a2d1e     PUSH       s_Join_Screen                                    = "Join Screen"
//                               LAB_004a2d23                                                 XREF[3]:     004a2c15(j), 004a2c4d(j),
//                                                                                                         004a2cba(j)
//         004a2d23     MOV        this,panel_system
//         004a2d28     CALL       TPanelSystem::setCurrentPanel                    int setCurrentPanel(TPanelSystem * this, char
//                              scr_mps.cpp:1620 (15)
//         004a2d2d     PUSH       s_MP_Setup_Screen                                = "MP Setup Screen"
//         004a2d32     MOV        this,panel_system
//         004a2d37     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:1622 (17)
//         004a2d3c     MOV        this,dword ptr [ESP]=>local_c
//         004a2d40     MOV        dword ptr FS:[0x0],this
//         004a2d47     ADD        ESP,0xc
//         004a2d4a     RET        0x4
//         004a2d4d     ??         90h
//         004a2d4e     NOP
//         004a2d4f     NOP
    return;
}

long TribeMPSetupScreen::handle_user_command(uint param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_user_command(TribeMPSetupScreen * this, uint
//              long              EAX:4          <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1                   XREF[1]:     004a2d73(R)
//              long              Stack[0x8]:4   param_2                   XREF[15]:    004a2d98(R), 004a2e92(R), 004a3205(R), 004a323b(R),
//                                                                                     004a345d(R), 004a34bc(R), 004a34cc(R), 004a3504(R),
//                                                                                     004a353d(R), 004a3576(R), 004a35ac(R), 004a3616(R),
//                                                                                     004a3680(R), 004a36e0(R), 004a3718(R)
//              char[256]         Stack[-0x104   message                   XREF[1,4]:   004a2f77(*), 004a35e1(*), 004a35ef(*), 004a364b(*),
//                                                                                     004a3659(*)
//              int               Stack[-0x108   ready                     XREF[2]:     004a2f55(*), 004a3078(R)
//              ulong             Stack[-0x10c   user6                     XREF[2]:     004a2f69(*), 004a2fb4(R)
//              ulong             Stack[-0x110   user2                     XREF[2]:     004a2f51(*), 004a3086(R)
//              ulong             Stack[-0x114   user7                     XREF[2]:     004a2f64(*), 004a2fde(R)
//              ulong             Stack[-0x118   user3                     XREF[3]:     004a2f6e(*), 004a2f89(R), 004a2f9d(R)
//              ulong             Stack[-0x11c   user1                     XREF[3]:     004a2f5f(*), 004a3022(R), 004a3036(R)
//              ulong             Stack[-0x120   user4                     XREF[3]:     004a2f5a(*), 004a304d(R), 004a3061(R)
//              ulong             Stack[-0x124   user5                     XREF[4]:     004a2f28(W), 004a2f3e(R), 004a2f73(R), 004a31b2(R)
//              undefined4        Stack[-0x128   local_128                 XREF[5]:     004a2f1a(W), 004a3080(R), 004a31a4(R), 004a31ae(R),
//                                                                                     004a31bc(W)
//              undefined4        Stack[-0x12c   local_12c                 XREF[3]:     004a2d62(W), 004a3137(R), 004a31e3(R)
//                               ?handle_user_command@TribeMPSetupScreen@@UAEJIJ@Z            XREF[1]:     0057332c(*)
//                               TribeMPSetupScreen::handle_user_command
//                              scr_mps.cpp:1628 (12)
//         004a2d50     SUB        ESP,0x12c
//         004a2d56     PUSH       EBX
//         004a2d57     PUSH       EBP
//         004a2d58     PUSH       ESI
//         004a2d59     PUSH       EDI
//         004a2d5a     MOV        EDI,this
//                              scr_mps.cpp:1634 (17)
//         004a2d5c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2d62     MOV        dword ptr [ESP + local_12c],EDI
//         004a2d66     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a2d6b     TEST       EAX,EAX
//                              scr_mps.cpp:1635 (6)
//         004a2d6d     JNZ        LAB_004a3735
//                              scr_mps.cpp:1637 (37)
//         004a2d73     MOV        EAX,dword ptr [ESP + param_1]
//         004a2d7a     LEA        this,[EAX + 0xffffe85c]
//         004a2d80     CMP        this,0x31
//         004a2d83     JA         switchD_004a2d91::caseD_17a5
//         004a2d89     XOR        EDX,EDX
//         004a2d8b     MOV        DL,byte ptr [this->_padding_ + switchD_004a2d9
//                               switchD_004a2d91::switchD
//         004a2d91     JMP        dword ptr [EDX*0x4 + switchD_004a2d91::switchd   = 004a2e92
//                               switchD_004a2d91::caseD_17bb                                 XREF[2]:     004a2d91(j), 004a3778(*)
//                              scr_mps.cpp:1640 (26)
//         004a2d98     MOV        this,dword ptr [ESP + param_2]
//         004a2d9f     MOV        EDX,dword ptr [L]                                = 00000000
//         004a2da5     PUSH       this
//         004a2da6     PUSH       EAX
//         004a2da7     PUSH       s_$$$_USER_COMMAND:_COMM_SHARED_DA               = "$$$ USER_COMMAND: COMM_SHARED_DATA_SENT (%
//         004a2dac     PUSH       EDX
//         004a2dad     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1641 (27)
//         004a2db2     MOV        this,dword ptr [comm]                            = 00000000
//         004a2db8     ADD        ESP,0x10
//         004a2dbb     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a2dc0     TEST       EAX,EAX
//         004a2dc2     MOV        EBX,0x1
//         004a2dc7     JZ         LAB_004a36d1
//                              scr_mps.cpp:1644 (21)
//         004a2dcd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2dd3     XOR        ESI,ESI
//         004a2dd5     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a2dda     TEST       EAX,EAX
//         004a2ddc     JLE        LAB_004a36d1
//                               LAB_004a2de2                                                 XREF[1]:     004a2e7d(j)
//                              scr_mps.cpp:1646 (17)
//         004a2de2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2de8     PUSH       ESI
//         004a2de9     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a2dee     CMP        EAX,0x32
//         004a2df1     JL         LAB_004a2e28
//                              scr_mps.cpp:1648 (16)
//         004a2df3     MOV        EAX,[L]                                          = 00000000
//         004a2df8     PUSH       s_$$$_HOST_RESET_CIV+50                          = "$$$ HOST RESET CIV+50"
//         004a2dfd     PUSH       EAX
//         004a2dfe     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1649 (31)
//         004a2e03     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2e09     ADD        ESP,0x8
//         004a2e0c     PUSH       ESI
//         004a2e0d     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a2e12     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2e18     SUB        EAX,0x32
//         004a2e1b     PUSH       EAX
//         004a2e1c     PUSH       ESI
//         004a2e1d     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1650 (6)
//         004a2e22     MOV        dword ptr [EDI + 0x88c],EBX
//                               LAB_004a2e28                                                 XREF[1]:     004a2df1(j)
//                              scr_mps.cpp:1652 (17)
//         004a2e28     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2e2e     PUSH       ESI
//         004a2e2f     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a2e34     CMP        EAX,0x32
//         004a2e37     JL         LAB_004a2e6f
//                              scr_mps.cpp:1654 (17)
//         004a2e39     MOV        this,dword ptr [L]                               = 00000000
//         004a2e3f     PUSH       s_$$$_HOST_RESET_TEAM+50                         = "$$$ HOST RESET TEAM+50"
//         004a2e44     PUSH       this
//         004a2e45     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1655 (31)
//         004a2e4a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2e50     ADD        ESP,0x8
//         004a2e53     PUSH       ESI
//         004a2e54     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a2e59     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2e5f     SUB        EAX,0x32
//         004a2e62     PUSH       EAX
//         004a2e63     PUSH       ESI
//         004a2e64     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:1656 (26)
//         004a2e69     MOV        dword ptr [EDI + 0x88c],EBX
//                               LAB_004a2e6f                                                 XREF[1]:     004a2e37(j)
//         004a2e6f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2e75     INC        ESI
//         004a2e76     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a2e7b     CMP        ESI,EAX
//         004a2e7d     JL         LAB_004a2de2
//                              scr_mps.cpp:1660 (2)
//         004a2e83     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a2e85     POP        EDI
//         004a2e86     POP        ESI
//         004a2e87     POP        EBP
//         004a2e88     POP        EBX
//         004a2e89     ADD        ESP,0x12c
//         004a2e8f     RET        0x8
//                               switchD_004a2d91::caseD_17a4                                 XREF[2]:     004a2d91(j), 004a3748(*)
//                              scr_mps.cpp:1663 (25)
//         004a2e92     MOV        EDX,dword ptr [ESP + param_2]
//         004a2e99     PUSH       EDX
//         004a2e9a     PUSH       EAX
//         004a2e9b     MOV        EAX,[L]                                          = 00000000
//         004a2ea0     PUSH       s_$$$_USER_COMMAND:_COMM_UPDATE_PL               = "$$$ USER_COMMAND: COMM_UPDATE_PLAYERS (%d,
//         004a2ea5     PUSH       EAX
//         004a2ea6     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1667 (35)
//         004a2eab     MOV        this,dword ptr [comm]                            = 00000000
//         004a2eb1     ADD        ESP,0x10
//         004a2eb4     XOR        EBP,EBP
//         004a2eb6     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a2ebb     TEST       EAX,EAX
//         004a2ebd     MOV        EBX,0x1
//         004a2ec2     JZ         LAB_004a2eff
//         004a2ec4     MOV        EAX,dword ptr [EDI + 0x854]
//         004a2eca     TEST       EAX,EAX
//         004a2ecc     JNZ        LAB_004a2eff
//                              scr_mps.cpp:1669 (6)
//         004a2ece     MOV        dword ptr [EDI + 0x854],EBX
//                              scr_mps.cpp:1670 (16)
//         004a2ed4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2eda     PUSH       EBP
//         004a2edb     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         004a2ee0     TEST       EAX,EAX
//         004a2ee2     JZ         LAB_004a2eff
//                              scr_mps.cpp:1673 (27)
//         004a2ee4     MOV        this,dword ptr [comm]                            = 00000000
//         004a2eea     PUSH       EBX
//         004a2eeb     MOV        EBP,EBX
//         004a2eed     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a2ef2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2ef8     DEC        EAX
//         004a2ef9     PUSH       EAX
//         004a2efa     CALL       RGE_Base_Game::setPlayerHasCD                    void setPlayerHasCD(RGE_Base_Game * this, int
//                               LAB_004a2eff                                                 XREF[3]:     004a2ec2(j), 004a2ecc(j),
//                                                                                                         004a2ee2(j)
//                              scr_mps.cpp:1678 (19)
//         004a2eff     MOV        this,dword ptr [comm]                            = 00000000
//         004a2f05     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a2f0a     TEST       EAX,EAX
//         004a2f0c     JZ         LAB_004a31e7
//                              scr_mps.cpp:1680 (12)
//         004a2f12     XOR        ESI,ESI
//         004a2f14     ADD        EDI,0x868
//         004a2f1a     MOV        dword ptr [ESP + local_128],EDI
//                               LAB_004a2f1e                                                 XREF[1]:     004a31c0(j)
//                              scr_mps.cpp:1682 (6)
//         004a2f1e     MOV        this,dword ptr [comm]                            = 00000000
//                              scr_mps.cpp:1781 (36)
//         004a2f24     LEA        EAX,[ESI + 0x1]
//         004a2f27     PUSH       EAX
//         004a2f28     MOV        dword ptr [ESP + user5],EAX
//         004a2f2c     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//         004a2f31     MOV        this,dword ptr [comm]                            = 00000000
//         004a2f37     MOV        EDI,EAX
//         004a2f39     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a2f3e     CMP        EAX,dword ptr [ESP + user5]
//         004a2f42     JZ         LAB_004a30a6
//                              scr_mps.cpp:1683 (9)
//         004a2f48     CMP        EDI,0x2
//         004a2f4b     JNZ        LAB_004a30af
//                              scr_mps.cpp:1685 (56)
//         004a2f51     LEA        this=>user2,[ESP + 0x2c]
//         004a2f55     LEA        EDX=>ready,[ESP + 0x34]
//         004a2f59     PUSH       this
//         004a2f5a     LEA        EAX=>user4,[ESP + 0x20]
//         004a2f5e     PUSH       EDX
//         004a2f5f     LEA        this=>user1,[ESP + 0x28]
//         004a2f63     PUSH       EAX
//         004a2f64     LEA        EDX=>user7,[ESP + 0x34]
//         004a2f68     PUSH       this
//         004a2f69     LEA        EAX=>user6,[ESP + 0x40]
//         004a2f6d     PUSH       EDX
//         004a2f6e     LEA        this=>user3,[ESP + 0x38]
//         004a2f72     PUSH       EAX
//         004a2f73     MOV        EAX,dword ptr [ESP + user5]
//         004a2f77     LEA        EDX=>message,[ESP + 0x50]
//         004a2f7b     PUSH       this
//         004a2f7c     MOV        this,dword ptr [comm]                            = 00000000
//         004a2f82     PUSH       EDX
//         004a2f83     PUSH       EAX
//         004a2f84     CALL       TCommunications_Handler::GetClientReadiness      int GetClientReadiness(TCommunications_Handle
//                              scr_mps.cpp:1688 (28)
//         004a2f89     MOV        EAX,dword ptr [ESP + user3]
//         004a2f8d     TEST       EAX,EAX
//         004a2f8f     JZ         LAB_004a2fb4
//         004a2f91     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2f97     PUSH       ESI
//         004a2f98     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a2f9d     MOV        this,dword ptr [ESP + user3]
//         004a2fa1     CMP        this,EAX
//         004a2fa3     JZ         LAB_004a2fb4
//                              scr_mps.cpp:1690 (13)
//         004a2fa5     PUSH       this
//         004a2fa6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2fac     PUSH       ESI
//         004a2fad     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1691 (2)
//         004a2fb2     MOV        EBP,EBX
//                               LAB_004a2fb4                                                 XREF[2]:     004a2f8f(j), 004a2fa3(j)
//                              scr_mps.cpp:1695 (27)
//         004a2fb4     MOV        EAX,dword ptr [ESP + user6]
//         004a2fb8     TEST       EAX,EAX
//         004a2fba     JZ         LAB_004a2fde
//         004a2fbc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2fc2     PUSH       ESI
//         004a2fc3     LEA        EDI,[EAX + -0x1]
//         004a2fc6     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
//         004a2fcb     CMP        EDI,EAX
//         004a2fcd     JZ         LAB_004a2fde
//                              scr_mps.cpp:1697 (13)
//         004a2fcf     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2fd5     PUSH       EDI
//         004a2fd6     PUSH       ESI
//         004a2fd7     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1698 (2)
//         004a2fdc     MOV        EBP,EBX
//                               LAB_004a2fde                                                 XREF[2]:     004a2fba(j), 004a2fcd(j)
//                              scr_mps.cpp:1702 (8)
//         004a2fde     MOV        EAX,dword ptr [ESP + user7]
//         004a2fe2     TEST       EAX,EAX
//         004a2fe4     JZ         LAB_004a3022
//                              scr_mps.cpp:1704 (4)
//         004a2fe6     CMP        EAX,EBX
//         004a2fe8     JNZ        LAB_004a2ffe
//                              scr_mps.cpp:1706 (16)
//         004a2fea     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a2ff0     PUSH       ESI
//         004a2ff1     CALL       RGE_Base_Game::playerHasCD                       int playerHasCD(RGE_Base_Game * this, int par
//         004a2ff6     CMP        EAX,EBX
//         004a2ff8     JNZ        LAB_004a3022
//                              scr_mps.cpp:1708 (2)
//         004a2ffa     PUSH       0x0
//                              scr_mps.cpp:1712 (7)
//         004a2ffc     JMP        LAB_004a3014
//                               LAB_004a2ffe                                                 XREF[1]:     004a2fe8(j)
//         004a2ffe     CMP        EAX,0x2
//         004a3001     JNZ        LAB_004a3022
//                              scr_mps.cpp:1714 (16)
//         004a3003     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3009     PUSH       ESI
//         004a300a     CALL       RGE_Base_Game::playerHasCD                       int playerHasCD(RGE_Base_Game * this, int par
//         004a300f     TEST       EAX,EAX
//         004a3011     JNZ        LAB_004a3022
//                              scr_mps.cpp:1716 (13)
//         004a3013     PUSH       EBX
//                               LAB_004a3014                                                 XREF[1]:     004a2ffc(j)
//         004a3014     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a301a     PUSH       ESI
//         004a301b     CALL       RGE_Base_Game::setPlayerHasCD                    void setPlayerHasCD(RGE_Base_Game * this, int
//                              scr_mps.cpp:1717 (2)
//         004a3020     MOV        EBP,EBX
//                               LAB_004a3022                                                 XREF[4]:     004a2fe4(j), 004a2ff8(j),
//                                                                                                         004a3001(j), 004a3011(j)
//                              scr_mps.cpp:1723 (28)
//         004a3022     MOV        EAX,dword ptr [ESP + user1]
//         004a3026     TEST       EAX,EAX
//         004a3028     JZ         LAB_004a304d
//         004a302a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3030     PUSH       ESI
//         004a3031     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a3036     MOV        this,dword ptr [ESP + user1]
//         004a303a     CMP        this,EAX
//         004a303c     JZ         LAB_004a304d
//                              scr_mps.cpp:1725 (13)
//         004a303e     PUSH       this
//         004a303f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3045     PUSH       ESI
//         004a3046     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:1726 (2)
//         004a304b     MOV        EBP,EBX
//                               LAB_004a304d                                                 XREF[2]:     004a3028(j), 004a303c(j)
//                              scr_mps.cpp:1730 (28)
//         004a304d     MOV        EAX,dword ptr [ESP + user4]
//         004a3051     TEST       EAX,EAX
//         004a3053     JZ         LAB_004a3078
//         004a3055     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a305b     PUSH       ESI
//         004a305c     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a3061     MOV        this,dword ptr [ESP + user4]
//         004a3065     CMP        this,EAX
//         004a3067     JZ         LAB_004a3078
//                              scr_mps.cpp:1732 (13)
//         004a3069     PUSH       this
//         004a306a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3070     PUSH       ESI
//         004a3071     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:1733 (2)
//         004a3076     MOV        EBP,EBX
//                               LAB_004a3078                                                 XREF[2]:     004a3053(j), 004a3067(j)
//                              scr_mps.cpp:1737 (8)
//         004a3078     MOV        EAX,dword ptr [ESP + ready]
//         004a307c     TEST       EAX,EAX
//         004a307e     JZ         LAB_004a3086
//                              scr_mps.cpp:1738 (6)
//         004a3080     MOV        this,dword ptr [ESP + local_128]
//         004a3084     MOV        dword ptr [this->_padding_],EAX
//                               LAB_004a3086                                                 XREF[1]:     004a307e(j)
//                              scr_mps.cpp:1741 (12)
//         004a3086     MOV        EAX,dword ptr [ESP + user2]
//         004a308a     TEST       EAX,EAX
//         004a308c     JZ         LAB_004a31ae
//                              scr_mps.cpp:1743 (13)
//         004a3092     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3098     PUSH       EAX
//         004a3099     PUSH       ESI
//         004a309a     CALL       RGE_Base_Game::setPlayerVersion                  void setPlayerVersion(RGE_Base_Game * this, i
//                              scr_mps.cpp:1744 (2)
//         004a309f     MOV        EBP,EBX
//                              scr_mps.cpp:1747 (23)
//         004a30a1     JMP        LAB_004a31ae
//                               LAB_004a30a6                                                 XREF[1]:     004a2f42(j)
//         004a30a6     CMP        EDI,0x2
//         004a30a9     JZ         LAB_004a31ae
//                               LAB_004a30af                                                 XREF[1]:     004a2f4b(j)
//         004a30af     CMP        EDI,0x4
//         004a30b2     JZ         LAB_004a31ae
//                              scr_mps.cpp:1750 (18)
//         004a30b8     PUSH       0x6d6
//         004a30bd     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a30c2     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004a30c7     CDQ
//         004a30c8     XOR        EAX,EDX
//                              scr_mps.cpp:1751 (31)
//         004a30ca     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a30d0     SUB        EAX,EDX
//         004a30d2     ADD        ESP,0x8
//         004a30d5     AND        EAX,0xf
//         004a30d8     XOR        EAX,EDX
//         004a30da     PUSH       ESI
//         004a30db     MOV        EDI,EAX
//         004a30dd     SUB        EDI,EDX
//         004a30df     INC        EDI
//         004a30e0     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a30e5     CMP        EAX,EDI
//         004a30e7     JZ         LAB_004a30f8
//                              scr_mps.cpp:1753 (13)
//         004a30e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a30ef     PUSH       EDI
//         004a30f0     PUSH       ESI
//         004a30f1     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1754 (2)
//         004a30f6     MOV        EBP,EBX
//                               LAB_004a30f8                                                 XREF[1]:     004a30e7(j)
//                              scr_mps.cpp:1756 (16)
//         004a30f8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a30fe     PUSH       ESI
//         004a30ff     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
//         004a3104     CMP        EAX,ESI
//         004a3106     JZ         LAB_004a3117
//                              scr_mps.cpp:1758 (13)
//         004a3108     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a310e     PUSH       ESI
//         004a310f     PUSH       ESI
//         004a3110     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:1759 (2)
//         004a3115     MOV        EBP,EBX
//                               LAB_004a3117                                                 XREF[1]:     004a3106(j)
//                              scr_mps.cpp:1761 (16)
//         004a3117     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a311d     PUSH       ESI
//         004a311e     CALL       RGE_Base_Game::playerHasCD                       int playerHasCD(RGE_Base_Game * this, int par
//         004a3123     TEST       EAX,EAX
//         004a3125     JZ         LAB_004a3137
//                              scr_mps.cpp:1763 (14)
//         004a3127     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a312d     PUSH       0x0
//         004a312f     PUSH       ESI
//         004a3130     CALL       RGE_Base_Game::setPlayerHasCD                    void setPlayerHasCD(RGE_Base_Game * this, int
//                              scr_mps.cpp:1764 (2)
//         004a3135     MOV        EBP,EBX
//                               LAB_004a3137                                                 XREF[1]:     004a3125(j)
//                              scr_mps.cpp:1766 (31)
//         004a3137     MOV        EAX,dword ptr [ESP + local_12c]
//         004a313b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3141     XOR        EDX,EDX
//         004a3143     PUSH       ESI
//         004a3144     MOV        DL,byte ptr [ESI + EAX*0x1 + 0x860]
//         004a314b     MOV        EDI,EDX
//         004a314d     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a3152     CMP        EAX,EDI
//         004a3154     JZ         LAB_004a3165
//                              scr_mps.cpp:1768 (13)
//         004a3156     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a315c     PUSH       EDI
//         004a315d     PUSH       ESI
//         004a315e     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:1769 (2)
//         004a3163     MOV        EBP,EBX
//                               LAB_004a3165                                                 XREF[1]:     004a3154(j)
//                              scr_mps.cpp:1771 (16)
//         004a3165     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a316b     PUSH       ESI
//         004a316c     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a3171     CMP        EAX,EBX
//         004a3173     JZ         LAB_004a3184
//                              scr_mps.cpp:1773 (13)
//         004a3175     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a317b     PUSH       EBX
//         004a317c     PUSH       ESI
//         004a317d     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:1774 (2)
//         004a3182     MOV        EBP,EBX
//                               LAB_004a3184                                                 XREF[1]:     004a3173(j)
//                              scr_mps.cpp:1776 (16)
//         004a3184     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a318a     PUSH       ESI
//         004a318b     CALL       RGE_Base_Game::playerVersion                     uchar playerVersion(RGE_Base_Game * this, int
//         004a3190     TEST       AL,AL
//         004a3192     JZ         LAB_004a31a4
//                              scr_mps.cpp:1778 (14)
//         004a3194     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a319a     PUSH       0x0
//         004a319c     PUSH       ESI
//         004a319d     CALL       RGE_Base_Game::setPlayerVersion                  void setPlayerVersion(RGE_Base_Game * this, i
//                              scr_mps.cpp:1779 (2)
//         004a31a2     MOV        EBP,EBX
//                               LAB_004a31a4                                                 XREF[1]:     004a3192(j)
//                              scr_mps.cpp:1781 (34)
//         004a31a4     MOV        this,dword ptr [ESP + local_128]
//         004a31a8     MOV        dword ptr [this->_padding_],0x0
//                               LAB_004a31ae                                                 XREF[4]:     004a308c(j), 004a30a1(j),
//                                                                                                         004a30a9(j), 004a30b2(j)
//         004a31ae     MOV        this,dword ptr [ESP + local_128]
//         004a31b2     MOV        ESI,dword ptr [ESP + user5]
//         004a31b6     ADD        this,0x4
//         004a31b9     CMP        ESI,0x8
//         004a31bc     MOV        dword ptr [ESP + local_128],this
//         004a31c0     JL         LAB_004a2f1e
//                              scr_mps.cpp:1785 (4)
//         004a31c6     TEST       EBP,EBP
//         004a31c8     JZ         LAB_004a31e3
//                              scr_mps.cpp:1787 (11)
//         004a31ca     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a31d0     MOV        EDX,dword ptr [this->_padding_]
//         004a31d2     CALL       dword ptr [EDX + 0x48]
//                              scr_mps.cpp:1788 (18)
//         004a31d5     MOV        EAX,dword ptr [ESP + 0x10]
//         004a31d9     MOV        dword ptr [EAX + 0x88c],0x0
//                               LAB_004a31e3                                                 XREF[1]:     004a31c8(j)
//         004a31e3     MOV        EDI,dword ptr [ESP + local_12c]
//                               LAB_004a31e7                                                 XREF[1]:     004a2f0c(j)
//                              scr_mps.cpp:1792 (7)
//         004a31e7     MOV        this,EDI
//         004a31e9     CALL       TribeMPSetupScreen::fillPlayers                  void fillPlayers(TribeMPSetupScreen * this)
//                              scr_mps.cpp:1797 (8)
//         004a31ee     MOV        EDX,dword ptr [EDI]
//         004a31f0     PUSH       EBX
//         004a31f1     MOV        this,EDI
//         004a31f3     CALL       dword ptr [EDX + 0x20]
//                              scr_mps.cpp:1798 (2)
//         004a31f6     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a31f8     POP        EDI
//         004a31f9     POP        ESI
//         004a31fa     POP        EBP
//         004a31fb     POP        EBX
//         004a31fc     ADD        ESP,0x12c
//         004a3202     RET        0x8
//                               switchD_004a2d91::caseD_17d5                                 XREF[2]:     004a2d91(j), 004a377c(*)
//                              scr_mps.cpp:1801 (28)
//         004a3205     MOV        ESI,dword ptr [ESP + param_2]
//         004a320c     PUSH       ESI
//         004a320d     PUSH       EAX
//         004a320e     MOV        EAX,[L]                                          = 00000000
//         004a3213     PUSH       s_$$$_USER_COMMAND:_CHAT_RECEIVED_               = "$$$ USER_COMMAND: CHAT_RECEIVED (%d,%d)"
//         004a3218     PUSH       EAX
//         004a3219     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a321e     ADD        ESP,0x10
//                              scr_mps.cpp:1802 (8)
//         004a3221     MOV        this,EDI
//         004a3223     PUSH       ESI
//         004a3224     CALL       TribeMPSetupScreen::fillChat                     void fillChat(TribeMPSetupScreen * this, int
//                              scr_mps.cpp:1923 (5)
//         004a3229     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a322e     POP        EDI
//         004a322f     POP        ESI
//         004a3230     POP        EBP
//         004a3231     POP        EBX
//         004a3232     ADD        ESP,0x12c
//         004a3238     RET        0x8
//                               switchD_004a2d91::caseD_17a6                                 XREF[2]:     004a2d91(j), 004a374c(*)
//                              scr_mps.cpp:1806 (26)
//         004a323b     MOV        this,dword ptr [ESP + param_2]
//         004a3242     MOV        EDX,dword ptr [L]                                = 00000000
//         004a3248     PUSH       this
//         004a3249     PUSH       EAX
//         004a324a     PUSH       s_$$$_USER_COMMAND:_COMM_UPDATE_PA               = "$$$ USER_COMMAND: COMM_UPDATE_PARAMS (%d,%
//         004a324f     PUSH       EDX
//         004a3250     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1807 (14)
//         004a3255     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a325b     ADD        ESP,0x10
//         004a325e     MOV        EAX,dword ptr [this->_padding_]
//         004a3260     CALL       dword ptr [EAX + 0x4c]
//                              scr_mps.cpp:1810 (23)
//         004a3263     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3269     XOR        EBP,EBP
//         004a326b     XOR        ESI,ESI
//         004a326d     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a3272     TEST       EAX,EAX
//         004a3274     JLE        LAB_004a3366
//                               LAB_004a327a                                                 XREF[1]:     004a3360(j)
//                              scr_mps.cpp:1812 (17)
//         004a327a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3280     PUSH       ESI
//         004a3281     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a3286     CMP        EAX,0x32
//         004a3289     JL         LAB_004a32e6
//                              scr_mps.cpp:1814 (17)
//         004a328b     MOV        this,dword ptr [L]                               = 00000000
//         004a3291     PUSH       s_$$$_CIV2>50                                    = "$$$ CIV2>50"
//         004a3296     PUSH       this=>DAT_fffffff8
//         004a3297     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1815 (31)
//         004a329c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a32a2     ADD        ESP,0x8
//         004a32a5     PUSH       ESI
//         004a32a6     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a32ab     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a32b1     SUB        EAX,0x32
//         004a32b4     PUSH       EAX
//         004a32b5     PUSH       ESI=>DAT_fffffff8
//         004a32b6     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1816 (18)
//         004a32bb     MOV        this,dword ptr [comm]                            = 00000000
//         004a32c1     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a32c6     LEA        EDX,[ESI + 0x1]
//         004a32c9     CMP        EDX,EAX
//         004a32cb     JNZ        LAB_004a32e6
//                              scr_mps.cpp:1818 (6)
//         004a32cd     MOV        dword ptr [EDI + 0x72c],EBP
//                              scr_mps.cpp:1819 (19)
//         004a32d3     MOV        EAX,[L]                                          = 00000000
//         004a32d8     PUSH       s_$$$_RESETTING_MYCIV2                           = "$$$ RESETTING MYCIV2"
//         004a32dd     PUSH       EAX=>DAT_fffffff8
//         004a32de     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a32e3     ADD        ESP,0x8
//                               LAB_004a32e6                                                 XREF[2]:     004a3289(j), 004a32cb(j)
//                              scr_mps.cpp:1823 (17)
//         004a32e6     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a32ec     PUSH       ESI
//         004a32ed     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a32f2     CMP        EAX,0x32
//         004a32f5     JL         LAB_004a3352
//                              scr_mps.cpp:1825 (17)
//         004a32f7     MOV        this,dword ptr [L]                               = 00000000
//         004a32fd     PUSH       s_$$$_TEAM2>50                                   = "$$$ TEAM2>50"
//         004a3302     PUSH       this=>DAT_fffffff8
//         004a3303     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1826 (31)
//         004a3308     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a330e     ADD        ESP,0x8
//         004a3311     PUSH       ESI
//         004a3312     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a3317     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a331d     SUB        EAX,0x32
//         004a3320     PUSH       EAX
//         004a3321     PUSH       ESI=>DAT_fffffff8
//         004a3322     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:1827 (18)
//         004a3327     MOV        this,dword ptr [comm]                            = 00000000
//         004a332d     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a3332     LEA        EDX,[ESI + 0x1]
//         004a3335     CMP        EDX,EAX
//         004a3337     JNZ        LAB_004a3352
//                              scr_mps.cpp:1829 (6)
//         004a3339     MOV        dword ptr [EDI + 0x738],EBP
//                              scr_mps.cpp:1830 (39)
//         004a333f     MOV        EAX,[L]                                          = 00000000
//         004a3344     PUSH       s_$$$_RESETTING_MYTEAM2                          = "$$$ RESETTING MYTEAM2"
//         004a3349     PUSH       EAX=>DAT_fffffff8
//         004a334a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a334f     ADD        ESP,0x8
//                               LAB_004a3352                                                 XREF[2]:     004a32f5(j), 004a3337(j)
//         004a3352     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3358     INC        ESI
//         004a3359     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a335e     CMP        ESI,EAX
//         004a3360     JL         LAB_004a327a
//                               LAB_004a3366                                                 XREF[1]:     004a3274(j)
//                              scr_mps.cpp:1837 (76)
//         004a3366     CMP        dword ptr [EDI + 0x730],EBP
//         004a336c     JZ         LAB_004a33bc
//         004a336e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3374     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a3379     MOV        ESI,EAX
//         004a337b     LEA        this,[EDI + 0x740]
//                               LAB_004a3381                                                 XREF[1]:     004a33a3(j)
//         004a3381     MOV        DL,byte ptr [this->_padding_]
//         004a3383     MOV        BL,byte ptr [ESI]
//         004a3385     MOV        AL,DL
//         004a3387     CMP        DL,BL
//         004a3389     JNZ        LAB_004a33a9
//         004a338b     TEST       AL,AL
//         004a338d     JZ         LAB_004a33a5
//         004a338f     MOV        DL,byte ptr [ECX + this+0x1]
//         004a3392     MOV        BL,byte ptr [ESI + 0x1]
//         004a3395     MOV        AL,DL
//         004a3397     CMP        DL,BL
//         004a3399     JNZ        LAB_004a33a9
//         004a339b     ADD        this,0x2
//         004a339e     ADD        ESI,0x2
//         004a33a1     TEST       AL,AL
//         004a33a3     JNZ        LAB_004a3381
//                               LAB_004a33a5                                                 XREF[1]:     004a338d(j)
//         004a33a5     XOR        EAX,EAX
//         004a33a7     JMP        LAB_004a33ae
//                               LAB_004a33a9                                                 XREF[2]:     004a3389(j), 004a3399(j)
//         004a33a9     SBB        EAX,EAX
//         004a33ab     SBB        EAX,-0x1
//                               LAB_004a33ae                                                 XREF[1]:     004a33a7(j)
//         004a33ae     CMP        EAX,EBP
//         004a33b0     JZ         LAB_004a33bc
//                              scr_mps.cpp:1838 (10)
//         004a33b2     MOV        dword ptr [EDI + 0x730],0xffffffff
//                               LAB_004a33bc                                                 XREF[2]:     004a336c(j), 004a33b0(j)
//                              scr_mps.cpp:1840 (7)
//         004a33bc     MOV        this,EDI
//         004a33be     CALL       TribeMPSetupScreen::updateSummary                void updateSummary(TribeMPSetupScreen * this)
//                              scr_mps.cpp:1842 (24)
//         004a33c3     MOV        this,dword ptr [comm]                            = 00000000
//         004a33c9     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a33ce     TEST       EAX,EAX
//         004a33d0     MOV        EBX,0x1
//         004a33d5     JNZ        LAB_004a36d1
//                              scr_mps.cpp:1845 (59)
//         004a33db     CMP        dword ptr [EDI + 0x854],EBP
//         004a33e1     JZ         LAB_004a3416
//         004a33e3     MOV        EAX,dword ptr [EDI + 0x73c]
//         004a33e9     MOV        this,dword ptr [EDI + 0x844]
//         004a33ef     CMP        EAX,this
//         004a33f1     JNZ        LAB_004a3416
//         004a33f3     MOV        this,dword ptr [comm]                            = 00000000
//         004a33f9     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a33fe     MOV        this,dword ptr [comm]                            = 00000000
//         004a3404     PUSH       EAX
//         004a3405     CALL       TCommunications_Handler::IsPlayerReady           int IsPlayerReady(TCommunications_Handler * t
//         004a340a     CMP        EAX,dword ptr [EDI + 0x85c]
//         004a3410     JZ         LAB_004a36d1
//                               LAB_004a3416                                                 XREF[2]:     004a33e1(j), 004a33f1(j)
//                              scr_mps.cpp:1848 (6)
//         004a3416     MOV        EAX,dword ptr [EDI + 0x73c]
//                              scr_mps.cpp:1849 (50)
//         004a341c     PUSH       EBX
//         004a341d     PUSH       EAX=>DAT_fffffff8
//         004a341e     PUSH       EBP=>DAT_fffffff4
//         004a341f     MOV        dword ptr [EDI + 0x854],EBX
//         004a3425     MOV        dword ptr [EDI + 0x844],EAX
//         004a342b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3431     PUSH       EBP=>DAT_fffffff0
//         004a3432     PUSH       EBP
//         004a3433     CALL       RGE_Base_Game::check_for_cd                      int check_for_cd(RGE_Base_Game * this, int pa
//         004a3438     MOV        this,dword ptr [EDI + 0x85c]
//         004a343e     INC        EAX
//         004a343f     PUSH       EAX
//         004a3440     PUSH       EBP
//         004a3441     PUSH       EBP
//         004a3442     PUSH       this
//         004a3443     MOV        this,dword ptr [comm]                            = 00000000
//         004a3449     CALL       TCommunications_Handler::SetMyReadiness          int SetMyReadiness(TCommunications_Handler *
//                              scr_mps.cpp:1852 (2)
//         004a344e     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a3450     POP        EDI
//         004a3451     POP        ESI
//         004a3452     POP        EBP
//         004a3453     POP        EBX
//         004a3454     ADD        ESP,0x12c
//         004a345a     RET        0x8
//                               switchD_004a2d91::caseD_17a7                                 XREF[2]:     004a2d91(j), 004a3750(*)
//                              scr_mps.cpp:1855 (25)
//         004a345d     MOV        EDX,dword ptr [ESP + param_2]
//         004a3464     PUSH       EDX
//         004a3465     PUSH       EAX
//         004a3466     MOV        EAX,[L]                                          = 00000000
//         004a346b     PUSH       s_$$$_USER_COMMAND:_COMM_LAUNCH_GA               = "$$$ USER_COMMAND: COMM_LAUNCH_GAME (%d,%d)"
//         004a3470     PUSH       EAX
//         004a3471     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1856 (21)
//         004a3476     MOV        this,dword ptr [AppWnd]                          = 00000000
//         004a347c     ADD        ESP,0x10
//         004a347f     PUSH       this
//         004a3480     MOV        this,dword ptr [chat]                            = 00000000
//         004a3486     CALL       TChat::setWindowHandle                           void setWindowHandle(TChat * this, void * par
//                              scr_mps.cpp:1857 (18)
//         004a348b     MOV        EDX,dword ptr [AppWnd]                           = 00000000
//         004a3491     MOV        this,dword ptr [comm]                            = 00000000
//         004a3497     PUSH       EDX
//         004a3498     CALL       TCommunications_Handler::SetWindowHandle         void * SetWindowHandle(TCommunications_Handle
//                              scr_mps.cpp:1858 (13)
//         004a349d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a34a3     PUSH       0x0
//         004a34a5     CALL       TRIBE_Game::start_game                           int start_game(TRIBE_Game * this, int param_1)
//                              scr_mps.cpp:1923 (5)
//         004a34aa     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a34af     POP        EDI
//         004a34b0     POP        ESI
//         004a34b1     POP        EBP
//         004a34b2     POP        EBX
//         004a34b3     ADD        ESP,0x12c
//         004a34b9     RET        0x8
//                               switchD_004a2d91::caseD_17a8                                 XREF[2]:     004a2d91(j), 004a3754(*)
//                              scr_mps.cpp:1862 (14)
//         004a34bc     MOV        this,dword ptr [ESP + param_2]
//         004a34c3     PUSH       this
//         004a34c4     PUSH       EAX
//         004a34c5     PUSH       s_$$$_USER_COMMAND:_COMM_CANCEL_GA               = "$$$ USER_COMMAND: COMM_CANCEL_GAME (%d,%d)"
//                              scr_mps.cpp:1864 (2)
//         004a34ca     JMP        LAB_004a34da
//                               switchD_004a2d91::caseD_17a9                                 XREF[2]:     004a2d91(j), 004a3758(*)
//                              scr_mps.cpp:1867 (29)
//         004a34cc     MOV        this,dword ptr [ESP + param_2]
//         004a34d3     PUSH       this
//         004a34d4     PUSH       EAX
//         004a34d5     PUSH       s_$$$_USER_COMMAND:_COMM_HOST_EXIT               = "$$$ USER_COMMAND: COMM_HOST_EXITED (%d,%d)"
//                               LAB_004a34da                                                 XREF[1]:     004a34ca(j)
//         004a34da     MOV        EDX,dword ptr [L]                                = 00000000
//         004a34e0     PUSH       EDX
//         004a34e1     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a34e6     ADD        ESP,0x10
//                              scr_mps.cpp:1868 (9)
//         004a34e9     MOV        this,EDI
//         004a34eb     PUSH       0x0
//         004a34ed     CALL       TribeMPSetupScreen::handleKickedPlayer           void handleKickedPlayer(TribeMPSetupScreen *
//                              scr_mps.cpp:1923 (5)
//         004a34f2     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a34f7     POP        EDI
//         004a34f8     POP        ESI
//         004a34f9     POP        EBP
//         004a34fa     POP        EBX
//         004a34fb     ADD        ESP,0x12c
//         004a3501     RET        0x8
//                               switchD_004a2d91::caseD_17b2                                 XREF[2]:     004a2d91(j), 004a3764(*)
//                              scr_mps.cpp:1872 (29)
//         004a3504     MOV        this,dword ptr [ESP + param_2]
//         004a350b     MOV        EDX,dword ptr [L]                                = 00000000
//         004a3511     PUSH       this
//         004a3512     PUSH       EAX
//         004a3513     PUSH       s_$$$_USER_COMMAND:_COMM_PLAYER_DR               = "$$$ USER_COMMAND: COMM_PLAYER_DROPPED (%d,
//         004a3518     PUSH       EDX
//         004a3519     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a351e     ADD        ESP,0x10
//                              scr_mps.cpp:1873 (13)
//         004a3521     MOV        EBX,0x1
//         004a3526     MOV        this,EDI
//         004a3528     PUSH       EBX
//         004a3529     CALL       TribeMPSetupScreen::handleKickedPlayer           void handleKickedPlayer(TribeMPSetupScreen *
//                              scr_mps.cpp:1874 (2)
//         004a352e     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a3530     POP        EDI
//         004a3531     POP        ESI
//         004a3532     POP        EBP
//         004a3533     POP        EBX
//         004a3534     ADD        ESP,0x12c
//         004a353a     RET        0x8
//                               switchD_004a2d91::caseD_17aa                                 XREF[2]:     004a2d91(j), 004a375c(*)
//                              scr_mps.cpp:1877 (29)
//         004a353d     MOV        this,dword ptr [ESP + param_2]
//         004a3544     MOV        EDX,dword ptr [L]                                = 00000000
//         004a354a     PUSH       this
//         004a354b     PUSH       EAX
//         004a354c     PUSH       s_$$$_USER_COMMAND:_COMM_PLAYER_KI               = "$$$ USER_COMMAND: COMM_PLAYER_KICKED (%d,%
//         004a3551     PUSH       EDX
//         004a3552     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a3557     ADD        ESP,0x10
//                              scr_mps.cpp:1878 (13)
//         004a355a     MOV        EBX,0x1
//         004a355f     MOV        this,EDI
//         004a3561     PUSH       EBX
//         004a3562     CALL       TribeMPSetupScreen::handleKickedPlayer           void handleKickedPlayer(TribeMPSetupScreen *
//                              scr_mps.cpp:1879 (2)
//         004a3567     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a3569     POP        EDI
//         004a356a     POP        ESI
//         004a356b     POP        EBP
//         004a356c     POP        EBX
//         004a356d     ADD        ESP,0x12c
//         004a3573     RET        0x8
//                               switchD_004a2d91::caseD_17b3                                 XREF[2]:     004a2d91(j), 004a3768(*)
//                              scr_mps.cpp:1882 (29)
//         004a3576     MOV        this,dword ptr [ESP + param_2]
//         004a357d     MOV        EDX,dword ptr [L]                                = 00000000
//         004a3583     PUSH       this
//         004a3584     PUSH       EAX
//         004a3585     PUSH       s_$$$_USER_COMMAND:_COMM_OTHER_PLA               = "$$$ USER_COMMAND: COMM_OTHER_PLAYER_DROPPE
//         004a358a     PUSH       EDX
//         004a358b     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a3590     ADD        ESP,0x10
//                              scr_mps.cpp:1883 (7)
//         004a3593     MOV        this,EDI
//         004a3595     CALL       TribeMPSetupScreen::fillPlayers                  void fillPlayers(TribeMPSetupScreen * this)
//                              scr_mps.cpp:1923 (5)
//         004a359a     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a359f     POP        EDI
//         004a35a0     POP        ESI
//         004a35a1     POP        EBP
//         004a35a2     POP        EBX
//         004a35a3     ADD        ESP,0x12c
//         004a35a9     RET        0x8
//                               switchD_004a2d91::caseD_17b7                                 XREF[2]:     004a2d91(j), 004a3770(*)
//                              scr_mps.cpp:1887 (25)
//         004a35ac     MOV        ESI,dword ptr [ESP + param_2]
//         004a35b3     PUSH       ESI
//         004a35b4     PUSH       EAX
//         004a35b5     MOV        EAX,[L]                                          = 00000000
//         004a35ba     PUSH       s_$$$_USER_COMMAND:_COMM_PLAYER_SE               = "$$$ USER_COMMAND: COMM_PLAYER_SERVICE_ERRO
//         004a35bf     PUSH       EAX
//         004a35c0     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1890 (42)
//         004a35c5     MOV        this,dword ptr [comm]                            = 00000000
//         004a35cb     ADD        ESP,0x10
//         004a35ce     PUSH       ESI
//         004a35cf     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler
//         004a35d4     PUSH       EAX
//                              language.dll match for 0x25de: "%s is using the wrong connect
//         004a35d5     PUSH       0x25de
//         004a35da     MOV        this,EDI
//         004a35dc     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a35e1     LEA        this=>message[4],[ESP + 0x40]
//         004a35e5     PUSH       EAX
//         004a35e6     PUSH       this
//         004a35e7     CALL       sprintf                                          undefined sprintf()
//         004a35ec     ADD        ESP,0xc
//                              scr_mps.cpp:1891 (21)
//         004a35ef     LEA        EDX=>message[4],[ESP + 0x3c]
//         004a35f3     MOV        this,EDI
//         004a35f5     PUSH       0x64
//         004a35f7     PUSH       0x1c2
//         004a35fc     PUSH       0x0
//         004a35fe     PUSH       EDX
//         004a35ff     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1923 (5)
//         004a3604     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a3609     POP        EDI
//         004a360a     POP        ESI
//         004a360b     POP        EBP
//         004a360c     POP        EBX
//         004a360d     ADD        ESP,0x12c
//         004a3613     RET        0x8
//                               switchD_004a2d91::caseD_17b6                                 XREF[2]:     004a2d91(j), 004a376c(*)
//                              scr_mps.cpp:1896 (25)
//         004a3616     MOV        ESI,dword ptr [ESP + param_2]
//         004a361d     PUSH       ESI
//         004a361e     PUSH       EAX
//         004a361f     MOV        EAX,[L]                                          = 00000000
//         004a3624     PUSH       s_$$$_USER_COMMAND:_COMM_BAD_VERSI               = "$$$ USER_COMMAND: COMM_BAD_VERSION (%d,%d)"
//         004a3629     PUSH       EAX
//         004a362a     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1899 (42)
//         004a362f     MOV        this,dword ptr [comm]                            = 00000000
//         004a3635     ADD        ESP,0x10
//         004a3638     PUSH       ESI
//         004a3639     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler
//         004a363e     PUSH       EAX
//                              language.dll match for 0x25dd: "%s is running the wrong versi
//         004a363f     PUSH       0x25dd
//         004a3644     MOV        this,EDI
//         004a3646     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a364b     LEA        this=>message[4],[ESP + 0x40]
//         004a364f     PUSH       EAX
//         004a3650     PUSH       this
//         004a3651     CALL       sprintf                                          undefined sprintf()
//         004a3656     ADD        ESP,0xc
//                              scr_mps.cpp:1900 (21)
//         004a3659     LEA        EDX=>message[4],[ESP + 0x3c]
//         004a365d     MOV        this,EDI
//         004a365f     PUSH       0x64
//         004a3661     PUSH       0x1c2
//         004a3666     PUSH       0x0
//         004a3668     PUSH       EDX
//         004a3669     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, char *
//                              scr_mps.cpp:1923 (5)
//         004a366e     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a3673     POP        EDI
//         004a3674     POP        ESI
//         004a3675     POP        EBP
//         004a3676     POP        EBX
//         004a3677     ADD        ESP,0x12c
//         004a367d     RET        0x8
//                               switchD_004a2d91::caseD_17b9                                 XREF[2]:     004a2d91(j), 004a3774(*)
//                              scr_mps.cpp:1905 (26)
//         004a3680     MOV        this,dword ptr [ESP + param_2]
//         004a3687     MOV        EDX,dword ptr [L]                                = 00000000
//         004a368d     PUSH       this
//         004a368e     PUSH       EAX
//         004a368f     PUSH       s_$$$_USER_COMMAND:_COMM_HOST_BUSY               = "$$$ USER_COMMAND: COMM_HOST_BUSY (%d,%d)"
//         004a3694     PUSH       EDX
//         004a3695     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1907 (23)
//         004a369a     MOV        this,dword ptr [comm]                            = 00000000
//         004a36a0     ADD        ESP,0x10
//         004a36a3     CALL       TCommunications_Handler::IsLobbyLaunched         int IsLobbyLaunched(TCommunications_Handler *
//         004a36a8     TEST       EAX,EAX
//         004a36aa     MOV        EBX,0x1
//         004a36af     JZ         LAB_004a36c8
//                              scr_mps.cpp:1908 (8)
//         004a36b1     PUSH       EBX
//         004a36b2     MOV        this,EDI
//         004a36b4     CALL       TribeMPSetupScreen::cancelScreen                 void cancelScreen(TribeMPSetupScreen * this,
//                              scr_mps.cpp:1911 (2)
//         004a36b9     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a36bb     POP        EDI
//         004a36bc     POP        ESI
//         004a36bd     POP        EBP
//         004a36be     POP        EBX
//         004a36bf     ADD        ESP,0x12c
//         004a36c5     RET        0x8
//                               LAB_004a36c8                                                 XREF[1]:     004a36af(j)
//                              scr_mps.cpp:1910 (9)
//         004a36c8     PUSH       0x0
//         004a36ca     MOV        this,EDI
//         004a36cc     CALL       TribeMPSetupScreen::handleKickedPlayer           void handleKickedPlayer(TribeMPSetupScreen *
//                               LAB_004a36d1                                                 XREF[4]:     004a2dc7(j), 004a2ddc(j),
//                                                                                                         004a33d5(j), 004a3410(j)
//                              scr_mps.cpp:1911 (2)
//         004a36d1     MOV        EAX,EBX
//                              scr_mps.cpp:1924 (13)
//         004a36d3     POP        EDI
//         004a36d4     POP        ESI
//         004a36d5     POP        EBP
//         004a36d6     POP        EBX
//         004a36d7     ADD        ESP,0x12c
//         004a36dd     RET        0x8
//                               switchD_004a2d91::caseD_17ae                                 XREF[2]:     004a2d91(j), 004a3760(*)
//                              scr_mps.cpp:1914 (29)
//         004a36e0     MOV        this,dword ptr [ESP + param_2]
//         004a36e7     MOV        EDX,dword ptr [L]                                = 00000000
//         004a36ed     PUSH       this
//         004a36ee     PUSH       EAX
//         004a36ef     PUSH       s_$$$_USER_COMMAND:_COMM_NO_LINK_(               = "$$$ USER_COMMAND: COMM_NO_LINK (%d,%d)"
//         004a36f4     PUSH       EDX
//         004a36f5     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a36fa     ADD        ESP,0x10
//                              scr_mps.cpp:1915 (9)
//         004a36fd     MOV        this,EDI
//         004a36ff     PUSH       0x0
//         004a3701     CALL       TribeMPSetupScreen::cancelScreen                 void cancelScreen(TribeMPSetupScreen * this,
//                              scr_mps.cpp:1923 (5)
//         004a3706     MOV        EAX,0x1
//                              scr_mps.cpp:1924 (13)
//         004a370b     POP        EDI
//         004a370c     POP        ESI
//         004a370d     POP        EBP
//         004a370e     POP        EBX
//         004a370f     ADD        ESP,0x12c
//         004a3715     RET        0x8
//                               switchD_004a2d91::caseD_17ab                                 XREF[3]:     004a2d83(j), 004a2d91(j),
//                               switchD_004a2d91::caseD_17ac                                              004a3780(*)
//                               switchD_004a2d91::caseD_17ad
//                               switchD_004a2d91::caseD_17af
//                               switchD_004a2d91::caseD_17b0
//                               switchD_004a2d91::caseD_17b1
//                               switchD_004a2d91::caseD_17b4
//                               switchD_004a2d91::caseD_17b5
//                               switchD_004a2d91::caseD_17b8
//                               switchD_004a2d91::caseD_17ba
//                               switchD_004a2d91::caseD_17bc
//                               switchD_004a2d91::caseD_17bd
//                               switchD_004a2d91::caseD_17be
//                               switchD_004a2d91::caseD_17bf
//                               switchD_004a2d91::caseD_17c0
//                               switchD_004a2d91::caseD_17c1
//                               switchD_004a2d91::caseD_17c2
//                               switchD_004a2d91::caseD_17c3
//                               switchD_004a2d91::caseD_17c4
//                               switchD_004a2d91::caseD_17c5
//                               switchD_004a2d91::caseD_17c6
//                               switchD_004a2d91::caseD_17c7
//                               switchD_004a2d91::caseD_17c8
//                               switchD_004a2d91::caseD_17c9
//                               switchD_004a2d91::caseD_17ca
//                               switchD_004a2d91::caseD_17cb
//                               switchD_004a2d91::caseD_17cc
//                               switchD_004a2d91::caseD_17cd
//                               switchD_004a2d91::caseD_17ce
//                               switchD_004a2d91::caseD_17cf
//                               switchD_004a2d91::caseD_17d0
//                               switchD_004a2d91::caseD_17d1
//                               switchD_004a2d91::caseD_17d2
//                               switchD_004a2d91::caseD_17d3
//                               switchD_004a2d91::caseD_17d4
//                               switchD_004a2d91::caseD_17a5
//                              scr_mps.cpp:1919 (29)
//         004a3718     MOV        this,dword ptr [ESP + param_2]
//         004a371f     MOV        EDX,dword ptr [L]                                = 00000000
//         004a3725     PUSH       this
//         004a3726     PUSH       EAX
//         004a3727     PUSH       s_$$$_USER_COMMAND:_UNKNOWN_(%d,_%               = "$$$ USER_COMMAND: UNKNOWN (%d, %d)"
//         004a372c     PUSH       EDX
//         004a372d     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//         004a3732     ADD        ESP,0x10
//                               LAB_004a3735                                                 XREF[1]:     004a2d6d(j)
//                              scr_mps.cpp:1924 (129)
//         004a3735     POP        EDI
//         004a3736     POP        ESI
//         004a3737     POP        EBP
//         004a3738     MOV        EAX,0x1
//         004a373d     POP        EBX
//         004a373e     ADD        ESP,0x12c
//         004a3744     RET        0x8
//         004a3747     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004a2d91::switchdataD_004a3748                       XREF[1]:     handle_user_command:004a2d91(*)
//         004a3748     addr       switchD_004a2d91::caseD_17a4
//         004a374c     addr       switchD_004a2d91::caseD_17a6
//         004a3750     addr       switchD_004a2d91::caseD_17a7
//         004a3754     addr       switchD_004a2d91::caseD_17a8
//         004a3758     addr       switchD_004a2d91::caseD_17a9
//         004a375c     addr       switchD_004a2d91::caseD_17aa
//         004a3760     addr       switchD_004a2d91::caseD_17ae
//         004a3764     addr       switchD_004a2d91::caseD_17b2
//         004a3768     addr       switchD_004a2d91::caseD_17b3
//         004a376c     addr       switchD_004a2d91::caseD_17b6
//         004a3770     addr       switchD_004a2d91::caseD_17b7
//         004a3774     addr       switchD_004a2d91::caseD_17b9
//         004a3778     addr       switchD_004a2d91::caseD_17bb
//         004a377c     addr       switchD_004a2d91::caseD_17d5
//         004a3780     addr       switchD_004a2d91::caseD_17a5
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004a2d91::switchdataD_004a3784                       XREF[1]:     handle_user_command:004a2d8b(*)
//         004a3784     db         0h
//         004a3785     db         Eh
//         004a3786     db         1h
//         004a3787     db         2h
//         004a3788     db         3h
//         004a3789     db         4h
//         004a378a     db         5h
//         004a378b     db         Eh
//         004a378c     db         Eh
//         004a378d     db         Eh
//         004a378e     db         6h
//         004a378f     db         Eh
//         004a3790     db         Eh
//         004a3791     db         Eh
//         004a3792     db         7h
//         004a3793     db         8h
//         004a3794     db         Eh
//         004a3795     db         Eh
//         004a3796     db         9h
//         004a3797     db         Ah
//         004a3798     db         Eh
//         004a3799     db         Bh
//         004a379a     db         Eh
//         004a379b     db         Ch
//         004a379c     db         Eh
//         004a379d     db         Eh
//         004a379e     db         Eh
//         004a379f     db         Eh
//         004a37a0     db         Eh
//         004a37a1     db         Eh
//         004a37a2     db         Eh
//         004a37a3     db         Eh
//         004a37a4     db         Eh
//         004a37a5     db         Eh
//         004a37a6     db         Eh
//         004a37a7     db         Eh
//         004a37a8     db         Eh
//         004a37a9     db         Eh
//         004a37aa     db         Eh
//         004a37ab     db         Eh
//         004a37ac     db         Eh
//         004a37ad     db         Eh
//         004a37ae     db         Eh
//         004a37af     db         Eh
//         004a37b0     db         Eh
//         004a37b1     db         Eh
//         004a37b2     db         Eh
//         004a37b3     db         Eh
//         004a37b4     db         Eh
//         004a37b5     db         Dh
//         004a37b6     ??         90h
//         004a37b7     ??         90h
//         004a37b8     ??         90h
//         004a37b9     ??         90h
//         004a37ba     ??         90h
//         004a37bb     ??         90h
//         004a37bc     ??         90h
//         004a37bd     ??         90h
//         004a37be     ??         90h
//         004a37bf     ??         90h
    return 0;
}

long TribeMPSetupScreen::handle_timer_command(uint param_1, long param_2) {
    /* TODO: Stub */
//                              long __thiscall handle_timer_command(TribeMPSetupScreen * this, uint
//              long              EAX:4          <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              uint              Stack[0x4]:4   param_1
//              long              Stack[0x8]:4   param_2
//                               ?handle_timer_command@TribeMPSetupScreen@@UAEJIJ@Z           XREF[1]:     00573330(*)
//                               TribeMPSetupScreen::handle_timer_command
//                              scr_mps.cpp:1930 (5)
//         004a37c0     MOV        EAX,0x1
//                              scr_mps.cpp:1932 (3)
//         004a37c5     RET        0x8
//         004a37c8     ??         90h
//         004a37c9     NOP
//         004a37ca     NOP
//         004a37cb     NOP
//         004a37cc     NOP
//         004a37cd     NOP
//         004a37ce     NOP
//         004a37cf     NOP
    return 0;
}

void TribeMPSetupScreen::fillPlayers() {
    /* TODO: Stub */
//                              void __thiscall fillPlayers(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              char *            Stack[-0x8]:4  text2
//              ulong             Stack[-0xc]:4  color1                    XREF[2]:     004a382c(W), 004a390b(R)
//              ulong             Stack[-0x10]:4 color2                    XREF[3]:     004a3807(W), 004a38ef(W), 004a392f(R)
//              char *            Stack[-0x14]:4 text1                     XREF[4]:     004a381e(W), 004a383d(R), 004a390f(R), 004a391e(W)
//              long              Stack[-0x18]:4 humanity
//                               ?fillPlayers@TribeMPSetupScreen@@QAEXXZ                      XREF[6]:     TribeMPSetupScreen:004a0d24(c),
//                               TribeMPSetupScreen::fillPlayers                                           action:004a19d2(c),
//                                                                                                         action:004a1f66(c),
//                                                                                                         handle_user_command:004a31e9(c),
//                                                                                                         handle_user_command:004a3595(c),
//                                                                                                         updateSummary:004a4f42(c)
//                              scr_mps.cpp:1940 (9)
//         004a37d0     SUB        ESP,0x14
//         004a37d3     PUSH       EBX
//         004a37d4     PUSH       EBP
//         004a37d5     PUSH       ESI
//         004a37d6     PUSH       EDI
//         004a37d7     MOV        EDI,this
//                              scr_mps.cpp:1951 (38)
//         004a37d9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a37df     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a37e4     TEST       EAX,EAX
//         004a37e6     JZ         LAB_004a3942
//         004a37ec     MOV        this,dword ptr [comm]                            = 00000000
//         004a37f2     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a37f7     TEST       EAX,EAX
//         004a37f9     JZ         LAB_004a3942
//                              scr_mps.cpp:1955 (35)
//         004a37ff     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3805     XOR        EBX,EBX
//         004a3807     MOV        dword ptr [ESP + color2],EBX
//         004a380b     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a3810     TEST       EAX,EAX
//         004a3812     JLE        LAB_004a392f
//         004a3818     LEA        EAX,[EDI + 0x490]
//         004a381e     MOV        dword ptr [ESP + text1],EAX
//                               LAB_004a3822                                                 XREF[1]:     004a3929(j)
//                              scr_mps.cpp:1958 (49)
//         004a3822     MOV        this,dword ptr [comm]                            = 00000000
//         004a3828     LEA        EBP,[EBX + 0x1]
//         004a382b     PUSH       EBP
//         004a382c     MOV        dword ptr [ESP + color1],EBP
//         004a3830     CALL       TCommunications_Handler::IsPlayerReady           int IsPlayerReady(TCommunications_Handler * t
//         004a3835     TEST       EAX,EAX
//         004a3837     JZ         LAB_004a390f
//         004a383d     MOV        this,dword ptr [ESP + text1]
//         004a3841     MOV        EDX,dword ptr [this->_padding_]
//         004a3843     CMP        dword ptr [EDX + 0x120],0xff
//         004a384d     JNZ        LAB_004a390f
//                              scr_mps.cpp:1961 (21)
//         004a3853     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3859     XOR        ESI,ESI
//         004a385b     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a3860     TEST       EAX,EAX
//         004a3862     JLE        LAB_004a390f
//                               LAB_004a3868                                                 XREF[1]:     004a3905(j)
//                              scr_mps.cpp:1963 (57)
//         004a3868     CMP        EBX,ESI
//         004a386a     JZ         LAB_004a38f7
//         004a3870     MOV        this,dword ptr [comm]                            = 00000000
//         004a3876     LEA        EAX,[ESI + 0x1]
//         004a3879     PUSH       EAX
//         004a387a     CALL       TCommunications_Handler::IsPlayerReady           int IsPlayerReady(TCommunications_Handler * t
//         004a387f     TEST       EAX,EAX
//         004a3881     JZ         LAB_004a38f7
//         004a3883     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3889     PUSH       ESI
//         004a388a     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a388f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3895     PUSH       EBX
//         004a3896     MOV        EBP,EAX
//         004a3898     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a389d     CMP        EBP,EAX
//         004a389f     JNZ        LAB_004a38f7
//                              scr_mps.cpp:1967 (19)
//         004a38a1     MOV        this,dword ptr [L]                               = 00000000
//         004a38a7     PUSH       ESI
//         004a38a8     PUSH       EBX
//         004a38a9     PUSH       s_$$$_SETTING_CIV/TEAM+50_(%d,%d)                = "$$$ SETTING CIV/TEAM+50 (%d,%d)"
//         004a38ae     PUSH       this
//         004a38af     CALL       TDebuggingLog::Log                               void Log(TDebuggingLog * this, char * param_1
//                              scr_mps.cpp:1968 (31)
//         004a38b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a38ba     ADD        ESP,0x10
//         004a38bd     PUSH       EBX
//         004a38be     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a38c3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a38c9     ADD        EAX,0x32
//         004a38cc     PUSH       EAX
//         004a38cd     PUSH       ESI
//         004a38ce     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:1969 (28)
//         004a38d3     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a38d9     PUSH       EBX
//         004a38da     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//         004a38df     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a38e5     ADD        EAX,0x32
//         004a38e8     PUSH       EAX
//         004a38e9     PUSH       ESI
//         004a38ea     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//                              scr_mps.cpp:1970 (28)
//         004a38ef     MOV        dword ptr [ESP + color2],0x1
//                               LAB_004a38f7                                                 XREF[3]:     004a386a(j), 004a3881(j),
//                                                                                                         004a389f(j)
//         004a38f7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a38fd     INC        ESI
//         004a38fe     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a3903     CMP        ESI,EAX
//         004a3905     JL         LAB_004a3868
//                              scr_mps.cpp:1961 (4)
//         004a390b     MOV        EBP,dword ptr [ESP + color1]
//                               LAB_004a390f                                                 XREF[3]:     004a3837(j), 004a384d(j),
//                                                                                                         004a3862(j)
//                              scr_mps.cpp:1955 (32)
//         004a390f     MOV        EDX,dword ptr [ESP + text1]
//         004a3913     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3919     ADD        EDX,0x4
//         004a391c     MOV        EBX,EBP
//         004a391e     MOV        dword ptr [ESP + text1],EDX
//         004a3922     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a3927     CMP        EBX,EAX
//         004a3929     JL         LAB_004a3822
//                               LAB_004a392f                                                 XREF[1]:     004a3812(j)
//                              scr_mps.cpp:1976 (8)
//         004a392f     MOV        EAX,dword ptr [ESP + color2]
//         004a3933     TEST       EAX,EAX
//         004a3935     JZ         LAB_004a3942
//                              scr_mps.cpp:1977 (11)
//         004a3937     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a393d     MOV        EDX,dword ptr [this->_padding_]
//         004a393f     CALL       dword ptr [EDX + 0x48]
//                               LAB_004a3942                                                 XREF[3]:     004a37e6(j), 004a37f9(j),
//                                                                                                         004a3935(j)
//                              scr_mps.cpp:1981 (21)
//         004a3942     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3948     XOR        ESI,ESI
//         004a394a     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a394f     TEST       EAX,EAX
//         004a3951     JLE        LAB_004a403d
//                               LAB_004a3957                                                 XREF[1]:     004a4037(j)
//                              scr_mps.cpp:1983 (15)
//         004a3957     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a395d     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3962     TEST       EAX,EAX
//         004a3964     JZ         LAB_004a398f
//                              scr_mps.cpp:1985 (15)
//         004a3966     MOV        this,dword ptr [comm]                            = 00000000
//         004a396c     LEA        EBX,[ESI + 0x1]
//         004a396f     PUSH       EBX
//         004a3970     CALL       TCommunications_Handler::GetPlayerHumanity       int GetPlayerHumanity(TCommunications_Handler
//                              scr_mps.cpp:1986 (24)
//         004a3975     MOV        this,dword ptr [comm]                            = 00000000
//         004a397b     MOV        dword ptr [ESP + 0x10],EAX
//         004a397f     CALL       TCommunications_Handler::WhoAmI                  int WhoAmI(TCommunications_Handler * this)
//         004a3984     XOR        this,this
//         004a3986     CMP        EAX,EBX
//         004a3988     SETZ       this
//         004a398b     MOV        EBP,this
//                              scr_mps.cpp:1988 (2)
//         004a398d     JMP        LAB_004a39b4
//                               LAB_004a398f                                                 XREF[1]:     004a3964(j)
//                              scr_mps.cpp:1990 (4)
//         004a398f     TEST       ESI,ESI
//         004a3991     JNZ        LAB_004a39a2
//                              scr_mps.cpp:1992 (8)
//         004a3993     MOV        dword ptr [ESP + 0x10],0x2
//                              scr_mps.cpp:1993 (5)
//         004a399b     MOV        EBP,0x1
//                              scr_mps.cpp:1995 (2)
//         004a39a0     JMP        LAB_004a39b4
//                               LAB_004a39a2                                                 XREF[1]:     004a3991(j)
//                              scr_mps.cpp:1997 (16)
//         004a39a2     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a39a9     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a39ae     MOV        dword ptr [ESP + 0x10],EAX
//                              scr_mps.cpp:1998 (2)
//         004a39b2     XOR        EBP,EBP
//                               LAB_004a39b4                                                 XREF[2]:     004a398d(j), 004a39a0(j)
//                              scr_mps.cpp:2003 (30)
//         004a39b4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a39ba     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a39bf     TEST       EAX,EAX
//         004a39c1     JZ         LAB_004a3acf
//         004a39c7     CMP        dword ptr [ESP + 0x10],0x2
//         004a39cc     JNZ        LAB_004a3acf
//                              scr_mps.cpp:2005 (32)
//         004a39d2     MOV        EDX,dword ptr [EDI + ESI*0x4 + 0x4f0]
//         004a39d9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a39df     PUSH       ESI
//         004a39e0     MOV        EBX,dword ptr [EDX]
//         004a39e2     CALL       RGE_Base_Game::playerHasCD                       int playerHasCD(RGE_Base_Game * this, int par
//         004a39e7     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4f0]
//         004a39ee     PUSH       EAX
//         004a39ef     CALL       dword ptr [EBX + 0x14]
//                              scr_mps.cpp:2012 (39)
//         004a39f2     MOV        this,dword ptr [comm]                            = 00000000
//         004a39f8     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a39fd     TEST       EAX,EAX
//         004a39ff     JNZ        LAB_004a3a9f
//         004a3a05     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3a0b     PUSH       EAX
//         004a3a0c     CALL       RGE_Base_Game::playerVersion                     uchar playerVersion(RGE_Base_Game * this, int
//         004a3a11     TEST       AL,AL
//         004a3a13     JNZ        LAB_004a3a9f
//                              scr_mps.cpp:2014 (4)
//         004a3a19     TEST       ESI,ESI
//         004a3a1b     JNZ        LAB_004a3a4d
//                              scr_mps.cpp:2016 (33)
//         004a3a1d     MOV        EAX,dword ptr [EDI + 0x510]
//         004a3a23     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3a29     PUSH       ESI
//         004a3a2a     MOV        EBX,dword ptr [EAX]
//         004a3a2c     CALL       RGE_Base_Game::playerVersionString               char * playerVersionString(RGE_Base_Game * th
//         004a3a31     MOV        this,dword ptr [EDI + 0x510]
//         004a3a37     PUSH       EAX
//         004a3a38     CALL       dword ptr [EBX + 0xe8]
//                              scr_mps.cpp:2017 (10)
//         004a3a3e     MOV        this,dword ptr [EDI + 0x510]
//         004a3a44     PUSH       0x1
//         004a3a46     MOV        EDX,dword ptr [this->_padding_]
//                              scr_mps.cpp:2019 (9)
//         004a3a48     JMP        LAB_004a3ae8
//                               LAB_004a3a4d                                                 XREF[1]:     004a3a1b(j)
//         004a3a4d     TEST       EBP,EBP
//         004a3a4f     JZ         LAB_004a3a8f
//                              scr_mps.cpp:2021 (14)
//         004a3a51     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3a57     PUSH       0x1
//         004a3a59     PUSH       ESI=>DAT_fffffff8
//         004a3a5a     CALL       RGE_Base_Game::setPlayerVersion                  void setPlayerVersion(RGE_Base_Game * this, i
//                              scr_mps.cpp:2022 (35)
//         004a3a5f     MOV        EAX,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3a66     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3a6c     PUSH       ESI
//         004a3a6d     MOV        EBX,dword ptr [EAX]
//         004a3a6f     CALL       RGE_Base_Game::playerVersionString               char * playerVersionString(RGE_Base_Game * th
//         004a3a74     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3a7b     PUSH       EAX
//         004a3a7c     CALL       dword ptr [EBX + 0xe8]
//                              scr_mps.cpp:2023 (11)
//         004a3a82     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3a89     PUSH       0x1
//         004a3a8b     MOV        EDX,dword ptr [this->_padding_]
//                              scr_mps.cpp:2025 (2)
//         004a3a8d     JMP        LAB_004a3ae8
//                               LAB_004a3a8f                                                 XREF[1]:     004a3a4f(j)
//                              scr_mps.cpp:2027 (14)
//         004a3a8f     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3a96     PUSH       0x0
//         004a3a98     MOV        EAX,dword ptr [this->_padding_]
//         004a3a9a     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2030 (2)
//         004a3a9d     JMP        LAB_004a3aeb
//                               LAB_004a3a9f                                                 XREF[2]:     004a39ff(j), 004a3a13(j)
//                              scr_mps.cpp:2032 (35)
//         004a3a9f     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3aa6     PUSH       ESI
//         004a3aa7     MOV        EBX,dword ptr [this->_padding_]
//         004a3aa9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3aaf     CALL       RGE_Base_Game::playerVersionString               char * playerVersionString(RGE_Base_Game * th
//         004a3ab4     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3abb     PUSH       EAX
//         004a3abc     CALL       dword ptr [EBX + 0xe8]
//                              scr_mps.cpp:2033 (11)
//         004a3ac2     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3ac9     PUSH       0x1
//         004a3acb     MOV        EDX,dword ptr [this->_padding_]
//                              scr_mps.cpp:2036 (2)
//         004a3acd     JMP        LAB_004a3ae8
//                               LAB_004a3acf                                                 XREF[2]:     004a39c1(j), 004a39cc(j)
//                              scr_mps.cpp:2038 (14)
//         004a3acf     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4f0]
//         004a3ad6     PUSH       0x0
//         004a3ad8     MOV        EAX,dword ptr [this->_padding_]
//         004a3ada     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2039 (14)
//         004a3add     MOV        this,dword ptr [EDI + ESI*0x4 + 0x510]
//         004a3ae4     PUSH       0x0
//         004a3ae6     MOV        EDX,dword ptr [this->_padding_]
//                               LAB_004a3ae8                                                 XREF[3]:     004a3a48(j), 004a3a8d(j),
//                                                                                                         004a3acd(j)
//         004a3ae8     CALL       dword ptr [EDX + 0x14]
//                               LAB_004a3aeb                                                 XREF[1]:     004a3a9d(j)
//                              scr_mps.cpp:2047 (13)
//         004a3aeb     CMP        EBP,0x1
//         004a3aee     JNZ        LAB_004a3afa
//         004a3af0     MOV        EAX,dword ptr [EDI + 0x734]
//         004a3af6     TEST       EAX,EAX
//                              scr_mps.cpp:2049 (2)
//         004a3af8     JNZ        LAB_004a3b06
//                               LAB_004a3afa                                                 XREF[1]:     004a3aee(j)
//                              scr_mps.cpp:2050 (25)
//         004a3afa     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3b00     PUSH       ESI
//         004a3b01     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//                               LAB_004a3b06                                                 XREF[1]:     004a3af8(j)
//         004a3b06     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3b0d     PUSH       EAX
//         004a3b0e     CALL       TButtonPanel::set_state_by_id                    void set_state_by_id(TButtonPanel * this, lon
//                              scr_mps.cpp:2052 (14)
//         004a3b13     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3b1a     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//         004a3b1f     MOV        EBX,EAX
//                              scr_mps.cpp:2053 (23)
//         004a3b21     LEA        EAX,[ESP + 0x20]
//         004a3b25     LEA        this,[ESP + 0x14]
//         004a3b29     PUSH       EAX
//         004a3b2a     PUSH       this=>DAT_fffffff8
//         004a3b2b     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3b32     PUSH       EBX=>DAT_fffffff4
//         004a3b33     CALL       TButtonPanel::get_text                           int get_text(TButtonPanel * this, short param
//                              scr_mps.cpp:2054 (23)
//         004a3b38     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3b3f     LEA        EDX,[ESP + 0x18]
//         004a3b43     LEA        EAX,[ESP + 0x1c]
//         004a3b47     PUSH       EDX
//         004a3b48     PUSH       EAX=>DAT_fffffff8
//         004a3b49     PUSH       EBX=>DAT_fffffff4
//         004a3b4a     CALL       TButtonPanel::get_text_color                     void get_text_color(TButtonPanel * this, shor
//                              scr_mps.cpp:2055 (20)
//         004a3b4f     MOV        this,dword ptr [EDI + ESI*0x4 + 0x530]
//         004a3b56     MOV        EAX,dword ptr [ESP + 0x14]
//         004a3b5a     PUSH       EAX
//         004a3b5b     MOV        EDX,dword ptr [this->_padding_]
//         004a3b5d     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2056 (22)
//         004a3b63     MOV        this,dword ptr [ESP + 0x18]
//         004a3b67     MOV        EDX,dword ptr [ESP + 0x1c]
//         004a3b6b     PUSH       this
//         004a3b6c     MOV        this,dword ptr [EDI + ESI*0x4 + 0x530]
//         004a3b73     PUSH       EDX=>DAT_fffffff8
//         004a3b74     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong
//                              scr_mps.cpp:2058 (14)
//         004a3b79     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3b80     PUSH       0x0
//         004a3b82     MOV        EAX,dword ptr [this->_padding_]
//         004a3b84     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2059 (14)
//         004a3b87     MOV        this,dword ptr [EDI + ESI*0x4 + 0x530]
//         004a3b8e     PUSH       0x0
//         004a3b90     MOV        EDX,dword ptr [this->_padding_]
//         004a3b92     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2062 (57)
//         004a3b95     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3b9b     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3ba0     TEST       EAX,EAX
//         004a3ba2     JZ         LAB_004a3bb2
//         004a3ba4     TEST       EBP,EBP
//         004a3ba6     JZ         LAB_004a3bb2
//         004a3ba8     MOV        EAX,dword ptr [EDI + 0x85c]
//         004a3bae     TEST       EAX,EAX
//         004a3bb0     JZ         LAB_004a3bce
//                               LAB_004a3bb2                                                 XREF[2]:     004a3ba2(j), 004a3ba6(j)
//         004a3bb2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3bb8     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a3bbd     TEST       EAX,EAX
//         004a3bbf     JZ         LAB_004a3bf0
//         004a3bc1     TEST       EBP,EBP
//         004a3bc3     JZ         LAB_004a3bf0
//         004a3bc5     CMP        dword ptr [EDI + 0x850],0x1
//         004a3bcc     JLE        LAB_004a3bf0
//                               LAB_004a3bce                                                 XREF[1]:     004a3bb0(j)
//                              scr_mps.cpp:2064 (14)
//         004a3bce     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3bd5     PUSH       0x1
//         004a3bd7     MOV        EAX,dword ptr [this->_padding_]
//         004a3bd9     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2065 (14)
//         004a3bdc     MOV        this,dword ptr [EDI + ESI*0x4 + 0x570]
//         004a3be3     PUSH       0x0
//         004a3be5     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                              scr_mps.cpp:2067 (15)
//         004a3bea     MOV        EBX,dword ptr [ESP + 0x10]
//         004a3bee     JMP        LAB_004a3c07
//                               LAB_004a3bf0                                                 XREF[3]:     004a3bbf(j), 004a3bc3(j),
//                                                                                                         004a3bcc(j)
//         004a3bf0     MOV        EBX,dword ptr [ESP + 0x10]
//         004a3bf4     CMP        EBX,0x2
//         004a3bf7     JNZ        LAB_004a3c07
//                              scr_mps.cpp:2068 (14)
//         004a3bf9     MOV        this,dword ptr [EDI + ESI*0x4 + 0x530]
//         004a3c00     PUSH       0x1
//         004a3c02     MOV        EDX,dword ptr [this->_padding_]
//         004a3c04     CALL       dword ptr [EDX + 0x14]
//                               LAB_004a3c07                                                 XREF[2]:     004a3bee(j), 004a3bf7(j)
//                              scr_mps.cpp:2073 (15)
//         004a3c07     CMP        EBP,0x1
//         004a3c0a     JNZ        LAB_004a3c31
//         004a3c0c     MOV        EAX,dword ptr [EDI + 0x738]
//         004a3c12     TEST       EAX,EAX
//         004a3c14     JZ         LAB_004a3c31
//                              scr_mps.cpp:2074 (25)
//         004a3c16     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3c1d     MOV        DX,word ptr [EDI + 0x738]
//         004a3c24     DEC        DX
//         004a3c26     MOV        EAX,dword ptr [this->_padding_]
//         004a3c28     PUSH       EDX
//         004a3c29     CALL       dword ptr [EAX + 0xe0]
//                              scr_mps.cpp:2075 (2)
//         004a3c2f     JMP        LAB_004a3c56
//                               LAB_004a3c31                                                 XREF[2]:     004a3c0a(j), 004a3c14(j)
//                              scr_mps.cpp:2077 (12)
//         004a3c31     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3c37     PUSH       ESI
//         004a3c38     CALL       RGE_Base_Game::playerTeam                        int playerTeam(RGE_Base_Game * this, int para
//                              scr_mps.cpp:2078 (5)
//         004a3c3d     CMP        EAX,0x32
//         004a3c40     JL         LAB_004a3c45
//                              scr_mps.cpp:2079 (3)
//         004a3c42     SUB        EAX,0x32
//                               LAB_004a3c45                                                 XREF[1]:     004a3c40(j)
//                              scr_mps.cpp:2080 (17)
//         004a3c45     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3c4c     DEC        EAX
//         004a3c4d     PUSH       EAX
//         004a3c4e     MOV        EDX,dword ptr [this->_padding_]
//         004a3c50     CALL       dword ptr [EDX + 0xe0]
//                               LAB_004a3c56                                                 XREF[1]:     004a3c2f(j)
//                              scr_mps.cpp:2083 (12)
//         004a3c56     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3c5d     CALL       TButtonPanel::get_state                          int get_state(TButtonPanel * this)
//                              scr_mps.cpp:2084 (23)
//         004a3c62     LEA        this,[ESP + 0x20]
//         004a3c66     LEA        EDX,[ESP + 0x14]
//         004a3c6a     PUSH       this
//         004a3c6b     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3c72     PUSH       EDX=>DAT_fffffff8
//         004a3c73     PUSH       EAX=>DAT_fffffff4
//         004a3c74     CALL       TButtonPanel::get_text                           int get_text(TButtonPanel * this, short param
//                              scr_mps.cpp:2085 (20)
//         004a3c79     MOV        this,dword ptr [EDI + ESI*0x4 + 0x550]
//         004a3c80     MOV        EDX,dword ptr [ESP + 0x14]
//         004a3c84     PUSH       EDX
//         004a3c85     MOV        EAX,dword ptr [this->_padding_]
//         004a3c87     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:2087 (14)
//         004a3c8d     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3c94     PUSH       0x0
//         004a3c96     MOV        EAX,dword ptr [this->_padding_]
//         004a3c98     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2088 (14)
//         004a3c9b     MOV        this,dword ptr [EDI + ESI*0x4 + 0x550]
//         004a3ca2     PUSH       0x0
//         004a3ca4     MOV        EDX,dword ptr [this->_padding_]
//         004a3ca6     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2091 (83)
//         004a3ca9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3caf     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3cb4     TEST       EAX,EAX
//         004a3cb6     JZ         LAB_004a3ce4
//         004a3cb8     TEST       EBP,EBP
//         004a3cba     JZ         LAB_004a3cc6
//         004a3cbc     MOV        EAX,dword ptr [EDI + 0x85c]
//         004a3cc2     TEST       EAX,EAX
//         004a3cc4     JZ         LAB_004a3cfc
//                               LAB_004a3cc6                                                 XREF[1]:     004a3cba(j)
//         004a3cc6     MOV        this,dword ptr [comm]                            = 00000000
//         004a3ccc     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a3cd1     TEST       EAX,EAX
//         004a3cd3     JZ         LAB_004a3ce4
//         004a3cd5     CMP        EBX,0x4
//         004a3cd8     JNZ        LAB_004a3ce4
//         004a3cda     MOV        EAX,dword ptr [EDI + 0x85c]
//         004a3ce0     TEST       EAX,EAX
//         004a3ce2     JZ         LAB_004a3cfc
//                               LAB_004a3ce4                                                 XREF[3]:     004a3cb6(j), 004a3cd3(j),
//                                                                                                         004a3cd8(j)
//         004a3ce4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3cea     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a3cef     TEST       EAX,EAX
//         004a3cf1     JZ         LAB_004a3d1a
//         004a3cf3     TEST       EBP,EBP
//         004a3cf5     JNZ        LAB_004a3cfc
//         004a3cf7     CMP        EBX,0x4
//         004a3cfa     JNZ        LAB_004a3d1a
//                               LAB_004a3cfc                                                 XREF[3]:     004a3cc4(j), 004a3ce2(j),
//                                                                                                         004a3cf5(j)
//                              scr_mps.cpp:2094 (14)
//         004a3cfc     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3d03     PUSH       0x1
//         004a3d05     MOV        EAX,dword ptr [this->_padding_]
//         004a3d07     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2095 (14)
//         004a3d0a     MOV        this,dword ptr [EDI + ESI*0x4 + 0x590]
//         004a3d11     PUSH       0x0
//         004a3d13     CALL       TButtonPanel::set_disabled                       void set_disabled(TButtonPanel * this, int pa
//                              scr_mps.cpp:2097 (12)
//         004a3d18     JMP        LAB_004a3d32
//                               LAB_004a3d1a                                                 XREF[2]:     004a3cf1(j), 004a3cfa(j)
//         004a3d1a     CMP        EBX,0x2
//         004a3d1d     JZ         LAB_004a3d24
//         004a3d1f     CMP        EBX,0x4
//         004a3d22     JNZ        LAB_004a3d32
//                               LAB_004a3d24                                                 XREF[1]:     004a3d1d(j)
//                              scr_mps.cpp:2098 (14)
//         004a3d24     MOV        this,dword ptr [EDI + ESI*0x4 + 0x550]
//         004a3d2b     PUSH       0x1
//         004a3d2d     MOV        EDX,dword ptr [this->_padding_]
//         004a3d2f     CALL       dword ptr [EDX + 0x14]
//                               LAB_004a3d32                                                 XREF[2]:     004a3d18(j), 004a3d22(j)
//                              scr_mps.cpp:2102 (15)
//         004a3d32     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3d38     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3d3d     TEST       EAX,EAX
//         004a3d3f     JZ         LAB_004a3d85
//                              scr_mps.cpp:2104 (22)
//         004a3d41     CMP        EBX,0x2
//         004a3d44     JNZ        LAB_004a3d5e
//         004a3d46     MOV        this,dword ptr [comm]                            = 00000000
//         004a3d4c     LEA        EAX,[ESI + 0x1]
//         004a3d4f     PUSH       EAX
//         004a3d50     CALL       TCommunications_Handler::IsPlayerReady           int IsPlayerReady(TCommunications_Handler * t
//         004a3d55     TEST       EAX,EAX
//                              scr_mps.cpp:2105 (7)
//         004a3d57     MOV        EBX,0xff
//         004a3d5c     JZ         LAB_004a3d63
//                               LAB_004a3d5e                                                 XREF[1]:     004a3d44(j)
//                              scr_mps.cpp:2107 (5)
//         004a3d5e     MOV        EBX,0xff00
//                               LAB_004a3d63                                                 XREF[1]:     004a3d5c(j)
//                              scr_mps.cpp:2108 (15)
//         004a3d63     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3d6a     PUSH       0x0
//         004a3d6c     PUSH       EBX=>DAT_fffffff8
//         004a3d6d     CALL       TDropDownPanel::set_val_text_color               void set_val_text_color(TDropDownPanel * this
//                              scr_mps.cpp:2109 (19)
//         004a3d72     MOV        this,dword ptr [EDI + ESI*0x4 + 0x490]
//         004a3d79     PUSH       0x0
//         004a3d7b     PUSH       EBX=>DAT_fffffff8
//         004a3d7c     CALL       TTextPanel::set_text_color                       void set_text_color(TTextPanel * this, ulong
//         004a3d81     MOV        EBX,dword ptr [ESP + 0x10]
//                               LAB_004a3d85                                                 XREF[1]:     004a3d3f(j)
//                              scr_mps.cpp:2113 (15)
//         004a3d85     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3d8b     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3d90     TEST       EAX,EAX
//         004a3d92     JZ         LAB_004a3dfe
//                              scr_mps.cpp:2115 (19)
//         004a3d94     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3d9b     PUSH       0x0
//         004a3d9d     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this, long param
//         004a3da2     CMP        EAX,0x2
//         004a3da5     JNZ        LAB_004a3db5
//                              scr_mps.cpp:2116 (14)
//         004a3da7     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3dae     PUSH       0x0
//         004a3db0     CALL       TDropDownPanel::delete_line                      int delete_line(TDropDownPanel * this, long p
//                               LAB_004a3db5                                                 XREF[1]:     004a3da5(j)
//                              scr_mps.cpp:2117 (5)
//         004a3db5     CMP        EBX,0x2
//         004a3db8     JNZ        LAB_004a3dd9
//                              scr_mps.cpp:2118 (31)
//         004a3dba     LEA        this,[ESI + 0x1]
//         004a3dbd     PUSH       EBX
//         004a3dbe     PUSH       this=>DAT_fffffff8
//         004a3dbf     MOV        this,dword ptr [comm]                            = 00000000
//         004a3dc5     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler
//         004a3dca     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3dd1     PUSH       EAX=>DAT_fffffff8
//         004a3dd2     PUSH       0x0=>DAT_fffffff4
//         004a3dd4     CALL       TDropDownPanel::insert_line                      int insert_line(TDropDownPanel * this, long p
//                               LAB_004a3dd9                                                 XREF[1]:     004a3db8(j)
//                              scr_mps.cpp:2119 (26)
//         004a3dd9     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3de0     PUSH       EBX
//         004a3de1     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004a3de6     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3ded     PUSH       EAX
//         004a3dee     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_mps.cpp:2120 (9)
//         004a3df3     MOV        EDX,dword ptr [EDI + ESI*0x4 + 0x490]
//         004a3dfa     MOV        EBX,dword ptr [EDX]
//                              scr_mps.cpp:2122 (2)
//         004a3dfc     JMP        LAB_004a3e1b
//                               LAB_004a3dfe                                                 XREF[1]:     004a3d92(j)
//                              scr_mps.cpp:2125 (25)
//         004a3dfe     MOV        this,dword ptr [EDI + ESI*0x4 + 0x490]
//         004a3e05     CMP        EBP,0x1
//         004a3e08     JNZ        LAB_004a3e19
//         004a3e0a     MOV        EAX,dword ptr [this->_padding_]
//                              language.dll match for 0x25b3: "You"
//         004a3e0c     PUSH       0x25b3
//         004a3e11     CALL       dword ptr [EAX + 0xe4]
//                              scr_mps.cpp:2126 (2)
//         004a3e17     JMP        LAB_004a3e35
//                               LAB_004a3e19                                                 XREF[1]:     004a3e08(j)
//                              scr_mps.cpp:2127 (28)
//         004a3e19     MOV        EBX,dword ptr [this->_padding_]
//                               LAB_004a3e1b                                                 XREF[1]:     004a3dfc(j)
//         004a3e1b     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3e22     CALL       TDropDownPanel::get_text                         char * get_text(TDropDownPanel * this)
//         004a3e27     MOV        this,dword ptr [EDI + ESI*0x4 + 0x490]
//         004a3e2e     PUSH       EAX
//         004a3e2f     CALL       dword ptr [EBX + 0xe8]
//                               LAB_004a3e35                                                 XREF[1]:     004a3e17(j)
//                              scr_mps.cpp:2130 (16)
//         004a3e35     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5d0]
//         004a3e3c     CMP        dword ptr [ECX + this->_padding_],0x2
//         004a3e43     JZ         LAB_004a3e85
//                              scr_mps.cpp:2132 (15)
//         004a3e45     CMP        EBP,0x1
//         004a3e48     JNZ        LAB_004a3e57
//         004a3e4a     MOV        EAX,dword ptr [EDI + 0x72c]
//         004a3e50     TEST       EAX,EAX
//         004a3e52     JZ         LAB_004a3e57
//                              scr_mps.cpp:2133 (1)
//         004a3e54     PUSH       EAX
//                              scr_mps.cpp:2134 (2)
//         004a3e55     JMP        LAB_004a3e73
//                               LAB_004a3e57                                                 XREF[2]:     004a3e48(j), 004a3e52(j)
//                              scr_mps.cpp:2136 (12)
//         004a3e57     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3e5d     PUSH       ESI
//         004a3e5e     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//                              scr_mps.cpp:2137 (5)
//         004a3e63     CMP        EAX,0x32
//         004a3e66     JL         LAB_004a3e6b
//                              scr_mps.cpp:2138 (3)
//         004a3e68     SUB        EAX,0x32
//                               LAB_004a3e6b                                                 XREF[1]:     004a3e66(j)
//                              scr_mps.cpp:2139 (26)
//         004a3e6b     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5d0]
//         004a3e72     PUSH       EAX
//                               LAB_004a3e73                                                 XREF[1]:     004a3e55(j)
//         004a3e73     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004a3e78     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5d0]
//         004a3e7f     PUSH       EAX
//         004a3e80     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                               LAB_004a3e85                                                 XREF[1]:     004a3e43(j)
//                              scr_mps.cpp:2142 (35)
//         004a3e85     MOV        EDX,dword ptr [EDI + ESI*0x4 + 0x4b0]
//         004a3e8c     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5d0]
//         004a3e93     MOV        EBX,dword ptr [EDX]
//         004a3e95     CALL       TDropDownPanel::get_text                         char * get_text(TDropDownPanel * this)
//         004a3e9a     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4b0]
//         004a3ea1     PUSH       EAX
//         004a3ea2     CALL       dword ptr [EBX + 0xe8]
//                              scr_mps.cpp:2144 (16)
//         004a3ea8     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5f0]
//         004a3eaf     CMP        dword ptr [ECX + this->_padding_],0x2
//         004a3eb6     JZ         LAB_004a3ef1
//                              scr_mps.cpp:2146 (16)
//         004a3eb8     CMP        EBP,0x1
//         004a3ebb     JNZ        LAB_004a3ecb
//         004a3ebd     MOV        EAX,dword ptr [EDI + 0x730]
//         004a3ec3     CMP        EAX,-0x1
//         004a3ec6     JZ         LAB_004a3ecb
//                              scr_mps.cpp:2147 (1)
//         004a3ec8     PUSH       EAX
//                              scr_mps.cpp:2148 (2)
//         004a3ec9     JMP        LAB_004a3edf
//                               LAB_004a3ecb                                                 XREF[2]:     004a3ebb(j), 004a3ec6(j)
//                              scr_mps.cpp:2149 (38)
//         004a3ecb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3ed1     PUSH       ESI
//         004a3ed2     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
//         004a3ed7     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5f0]
//         004a3ede     PUSH       EAX
//                               LAB_004a3edf                                                 XREF[1]:     004a3ec9(j)
//         004a3edf     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004a3ee4     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5f0]
//         004a3eeb     PUSH       EAX
//         004a3eec     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                               LAB_004a3ef1                                                 XREF[1]:     004a3eb6(j)
//                              scr_mps.cpp:2151 (35)
//         004a3ef1     MOV        EAX,dword ptr [EDI + ESI*0x4 + 0x4d0]
//         004a3ef8     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5f0]
//         004a3eff     MOV        EBX,dword ptr [EAX]
//         004a3f01     CALL       TDropDownPanel::get_text                         char * get_text(TDropDownPanel * this)
//         004a3f06     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4d0]
//         004a3f0d     PUSH       EAX
//         004a3f0e     CALL       dword ptr [EBX + 0xe8]
//                              scr_mps.cpp:2155 (34)
//         004a3f14     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3f1a     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3f1f     TEST       EAX,EAX
//         004a3f21     JZ         LAB_004a3f50
//         004a3f23     MOV        this,dword ptr [comm]                            = 00000000
//         004a3f29     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a3f2e     TEST       EAX,EAX
//         004a3f30     JZ         LAB_004a3f50
//         004a3f32     TEST       EBP,EBP
//         004a3f34     JNZ        LAB_004a3f50
//                              scr_mps.cpp:2157 (14)
//         004a3f36     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3f3d     PUSH       0x1
//         004a3f3f     MOV        EDX,dword ptr [this->_padding_]
//         004a3f41     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2158 (10)
//         004a3f44     MOV        this,dword ptr [EDI + ESI*0x4 + 0x490]
//         004a3f4b     PUSH       EBP
//         004a3f4c     MOV        EAX,dword ptr [this->_padding_]
//                              scr_mps.cpp:2160 (2)
//         004a3f4e     JMP        LAB_004a3f69
//                               LAB_004a3f50                                                 XREF[3]:     004a3f21(j), 004a3f30(j),
//                                                                                                         004a3f34(j)
//                              scr_mps.cpp:2162 (14)
//         004a3f50     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5b0]
//         004a3f57     PUSH       0x0
//         004a3f59     MOV        EDX,dword ptr [this->_padding_]
//         004a3f5b     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2163 (14)
//         004a3f5e     MOV        this,dword ptr [EDI + ESI*0x4 + 0x490]
//         004a3f65     PUSH       0x1
//         004a3f67     MOV        EAX,dword ptr [this->_padding_]
//                               LAB_004a3f69                                                 XREF[1]:     004a3f4e(j)
//         004a3f69     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2166 (14)
//         004a3f6c     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5d0]
//         004a3f73     PUSH       0x0
//         004a3f75     MOV        EDX,dword ptr [this->_padding_]
//         004a3f77     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2167 (14)
//         004a3f7a     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4b0]
//         004a3f81     PUSH       0x0
//         004a3f83     MOV        EAX,dword ptr [this->_padding_]
//         004a3f85     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2169 (93)
//         004a3f88     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3f8e     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a3f93     TEST       EAX,EAX
//         004a3f95     JZ         LAB_004a3fc9
//         004a3f97     TEST       EBP,EBP
//         004a3f99     JZ         LAB_004a3fa5
//         004a3f9b     MOV        EAX,dword ptr [EDI + 0x85c]
//         004a3fa1     TEST       EAX,EAX
//         004a3fa3     JZ         LAB_004a3fe5
//                               LAB_004a3fa5                                                 XREF[1]:     004a3f99(j)
//         004a3fa5     MOV        this,dword ptr [comm]                            = 00000000
//         004a3fab     CALL       TCommunications_Handler::IsHost                  int IsHost(TCommunications_Handler * this)
//         004a3fb0     TEST       EAX,EAX
//         004a3fb2     JZ         LAB_004a3fc9
//         004a3fb4     MOV        EBX,dword ptr [ESP + 0x10]
//         004a3fb8     CMP        EBX,0x4
//         004a3fbb     JNZ        LAB_004a3fcd
//         004a3fbd     MOV        EAX,dword ptr [EDI + 0x85c]
//         004a3fc3     TEST       EAX,EAX
//         004a3fc5     JZ         LAB_004a3fe5
//         004a3fc7     JMP        LAB_004a3fcd
//                               LAB_004a3fc9                                                 XREF[2]:     004a3f95(j), 004a3fb2(j)
//         004a3fc9     MOV        EBX,dword ptr [ESP + 0x10]
//                               LAB_004a3fcd                                                 XREF[2]:     004a3fbb(j), 004a3fc7(j)
//         004a3fcd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a3fd3     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a3fd8     TEST       EAX,EAX
//         004a3fda     JZ         LAB_004a3ff5
//         004a3fdc     TEST       EBP,EBP
//         004a3fde     JNZ        LAB_004a3fe5
//         004a3fe0     CMP        EBX,0x4
//         004a3fe3     JNZ        LAB_004a3ff5
//                               LAB_004a3fe5                                                 XREF[3]:     004a3fa3(j), 004a3fc5(j),
//                                                                                                         004a3fde(j)
//                              scr_mps.cpp:2170 (14)
//         004a3fe5     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5d0]
//         004a3fec     PUSH       0x1
//         004a3fee     MOV        EDX,dword ptr [this->_padding_]
//         004a3ff0     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2171 (12)
//         004a3ff3     JMP        LAB_004a400d
//                               LAB_004a3ff5                                                 XREF[2]:     004a3fda(j), 004a3fe3(j)
//         004a3ff5     CMP        EBX,0x2
//         004a3ff8     JZ         LAB_004a3fff
//         004a3ffa     CMP        EBX,0x4
//         004a3ffd     JNZ        LAB_004a400d
//                               LAB_004a3fff                                                 XREF[1]:     004a3ff8(j)
//                              scr_mps.cpp:2172 (14)
//         004a3fff     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4b0]
//         004a4006     PUSH       0x1
//         004a4008     MOV        EAX,dword ptr [this->_padding_]
//         004a400a     CALL       dword ptr [EAX + 0x14]
//                               LAB_004a400d                                                 XREF[2]:     004a3ff3(j), 004a3ffd(j)
//                              scr_mps.cpp:2174 (14)
//         004a400d     MOV        this,dword ptr [EDI + ESI*0x4 + 0x5f0]
//         004a4014     PUSH       0x0
//         004a4016     MOV        EDX,dword ptr [this->_padding_]
//         004a4018     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2175 (34)
//         004a401b     MOV        this,dword ptr [EDI + ESI*0x4 + 0x4d0]
//         004a4022     PUSH       0x0
//         004a4024     MOV        EAX,dword ptr [this->_padding_]
//         004a4026     CALL       dword ptr [EAX + 0x14]
//         004a4029     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a402f     INC        ESI
//         004a4030     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a4035     CMP        ESI,EAX
//         004a4037     JL         LAB_004a3957
//                               LAB_004a403d                                                 XREF[1]:     004a3951(j)
//                              scr_mps.cpp:2179 (23)
//         004a403d     CMP        ESI,0x8
//         004a4040     JGE        LAB_004a40e7
//         004a4046     MOV        EBP,0x8
//         004a404b     LEA        EBX,[EDI + ESI*0x4 + 0x5d0]
//         004a4052     SUB        EBP,ESI
//                               LAB_004a4054                                                 XREF[1]:     004a40e1(j)
//                              scr_mps.cpp:2181 (10)
//         004a4054     MOV        this,dword ptr [EBX + -0x20]
//         004a4057     PUSH       0x0
//         004a4059     MOV        EDX,dword ptr [this->_padding_]
//         004a405b     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2182 (9)
//         004a405e     MOV        this,dword ptr [EBX]
//         004a4060     PUSH       0x0
//         004a4062     MOV        EAX,dword ptr [this->_padding_]
//         004a4064     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2183 (10)
//         004a4067     MOV        this,dword ptr [EBX + 0x20]
//         004a406a     PUSH       0x0
//         004a406c     MOV        EDX,dword ptr [this->_padding_]
//         004a406e     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2185 (10)
//         004a4071     MOV        this,dword ptr [EBX + -0x60]
//         004a4074     PUSH       0x0
//         004a4076     MOV        EAX,dword ptr [this->_padding_]
//         004a4078     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2186 (13)
//         004a407b     MOV        this,dword ptr [EBX + 0xffffff60]
//         004a4081     PUSH       0x0
//         004a4083     MOV        EDX,dword ptr [this->_padding_]
//         004a4085     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2190 (10)
//         004a4088     MOV        this,dword ptr [EBX + -0x40]
//         004a408b     PUSH       0x0
//         004a408d     MOV        EAX,dword ptr [this->_padding_]
//         004a408f     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2191 (10)
//         004a4092     MOV        this,dword ptr [EBX + -0x80]
//         004a4095     PUSH       0x0
//         004a4097     MOV        EDX,dword ptr [this->_padding_]
//         004a4099     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2194 (13)
//         004a409c     MOV        this,dword ptr [EBX + 0xfffffec0]
//         004a40a2     PUSH       0x0
//         004a40a4     MOV        EAX,dword ptr [this->_padding_]
//         004a40a6     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2195 (13)
//         004a40a9     MOV        this,dword ptr [EBX + 0xfffffee0]
//         004a40af     PUSH       0x0
//         004a40b1     MOV        EDX,dword ptr [this->_padding_]
//         004a40b3     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2196 (13)
//         004a40b6     MOV        this,dword ptr [EBX + 0xffffff00]
//         004a40bc     PUSH       0x0
//         004a40be     MOV        EAX,dword ptr [this->_padding_]
//         004a40c0     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2198 (13)
//         004a40c3     MOV        this,dword ptr [EBX + 0xffffff20]
//         004a40c9     PUSH       0x0
//         004a40cb     MOV        EDX,dword ptr [this->_padding_]
//         004a40cd     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2199 (23)
//         004a40d0     MOV        this,dword ptr [EBX + 0xffffff40]
//         004a40d6     PUSH       0x0
//         004a40d8     MOV        EAX,dword ptr [this->_padding_]
//         004a40da     CALL       dword ptr [EAX + 0x14]
//         004a40dd     ADD        EBX,0x4
//         004a40e0     DEC        EBP
//         004a40e1     JNZ        LAB_004a4054
//                               LAB_004a40e7                                                 XREF[1]:     004a4040(j)
//                              scr_mps.cpp:2202 (7)
//         004a40e7     MOV        this,EDI
//         004a40e9     CALL       TribeMPSetupScreen::fillPlayerColors             void fillPlayerColors(TribeMPSetupScreen * th
//                              scr_mps.cpp:2203 (8)
//         004a40ee     POP        EDI
//         004a40ef     POP        ESI
//         004a40f0     POP        EBP
//         004a40f1     POP        EBX
//         004a40f2     ADD        ESP,0x14
//         004a40f5     RET
//         004a40f6     ??         90h
//         004a40f7     NOP
//         004a40f8     NOP
//         004a40f9     NOP
//         004a40fa     NOP
//         004a40fb     NOP
//         004a40fc     NOP
//         004a40fd     NOP
//         004a40fe     NOP
//         004a40ff     NOP
    return;
}

void TribeMPSetupScreen::fillChat(int param_1) {
    /* TODO: Stub */
//                              void __thiscall fillChat(TribeMPSetupScreen * this, int param_1)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004a4151(R)
//                               ?fillChat@TribeMPSetupScreen@@IAEXH@Z                        XREF[1]:     handle_user_command:004a3224(c)
//                               TribeMPSetupScreen::fillChat
//                              scr_mps.cpp:2209 (3)
//         004a4100     PUSH       ESI
//         004a4101     MOV        ESI,this
//                              scr_mps.cpp:2213 (16)
//         004a4103     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4109     PUSH       EDI
//         004a410a     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a410f     TEST       EAX,EAX
//         004a4111     JNZ        LAB_004a4182
//                              scr_mps.cpp:2216 (11)
//         004a4113     MOV        this,dword ptr [ESI + 0x618]
//         004a4119     CALL       TTextPanel::numberLines                          int numberLines(TTextPanel * this)
//                              scr_mps.cpp:2219 (24)
//         004a411e     TEST       EAX,EAX
//         004a4120     JLE        LAB_004a413d
//         004a4122     MOV        EDX,dword ptr [ESI + 0x618]
//         004a4128     LEA        this,[EAX + -0x1]
//         004a412b     MOVSX      EDX,word ptr [EDX + 0xfe]
//         004a4132     CMP        EDX,this
//         004a4134     JNZ        LAB_004a413d
//                              scr_mps.cpp:2220 (5)
//         004a4136     MOV        EDI,0x1
//                              scr_mps.cpp:2221 (2)
//         004a413b     JMP        LAB_004a413f
//                               LAB_004a413d                                                 XREF[2]:     004a4120(j), 004a4134(j)
//                              scr_mps.cpp:2222 (2)
//         004a413d     XOR        EDI,EDI
//                               LAB_004a413f                                                 XREF[1]:     004a413b(j)
//                              scr_mps.cpp:2225 (5)
//         004a413f     CMP        EAX,0x64
//         004a4142     JL         LAB_004a4151
//                              scr_mps.cpp:2226 (13)
//         004a4144     MOV        this,dword ptr [ESI + 0x618]
//         004a414a     PUSH       0x0
//         004a414c     CALL       TTextPanel::delete_line                          int delete_line(TTextPanel * this, long param
//                               LAB_004a4151                                                 XREF[1]:     004a4142(j)
//                              scr_mps.cpp:2228 (28)
//         004a4151     MOV        EAX,dword ptr [ESP + param_1]
//         004a4155     MOV        this,dword ptr [chat]                            = 00000000
//         004a415b     PUSH       EAX
//         004a415c     CALL       TChat::GetChatMsg                                char * GetChatMsg(TChat * this, int param_1)
//         004a4161     MOV        this,dword ptr [ESI + 0x618]
//         004a4167     PUSH       EAX
//         004a4168     CALL       TTextPanel::word_wrap_append                     int word_wrap_append(TTextPanel * this, char
//                              scr_mps.cpp:2230 (4)
//         004a416d     TEST       EDI,EDI
//         004a416f     JZ         LAB_004a4182
//                              scr_mps.cpp:2231 (17)
//         004a4171     MOV        this,dword ptr [ESI + 0x618]
//         004a4177     PUSH       0x1
//         004a4179     PUSH       0x0
//         004a417b     PUSH       0x7
//         004a417d     CALL       TTextPanel::scroll                               void scroll(TTextPanel * this, uchar param_1,
//                               LAB_004a4182                                                 XREF[2]:     004a4111(j), 004a416f(j)
//                              scr_mps.cpp:2232 (5)
//         004a4182     POP        EDI
//         004a4183     POP        ESI
//         004a4184     RET        0x4
//         004a4187     ??         90h
//         004a4188     NOP
//         004a4189     NOP
//         004a418a     NOP
//         004a418b     NOP
//         004a418c     NOP
//         004a418d     NOP
//         004a418e     NOP
//         004a418f     NOP
    return;
}

void TribeMPSetupScreen::updateSummary() {
    /* TODO: Stub */
//                              void __thiscall updateSummary(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              _finddata_t       Stack[-0x11c   file_info@fffffee4
//              char[256]         Stack[-0x21c   str3
//              char[260]         Stack[-0x334   file_name
//              char[256]         Stack[-0x434   str2
//              char[256]         Stack[-0x534   str1
//                               ?updateSummary@TribeMPSetupScreen@@QAEXXZ                    XREF[4]:     TribeMPSetupScreen:004a0d07(c),
//                               TribeMPSetupScreen::updateSummary                                         action:004a1c08(c),
//                                                                                                         action:004a1c6c(c),
//                                                                                                         handle_user_command:004a33be(c)
//                              scr_mps.cpp:2241 (11)
//         004a4190     SUB        ESP,0x534
//         004a4196     PUSH       EBX
//         004a4197     PUSH       EBP
//         004a4198     MOV        EBP,this
//         004a419a     PUSH       ESI
//                              scr_mps.cpp:2259 (16)
//         004a419b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a41a1     PUSH       EDI
//         004a41a2     XOR        EDI,EDI
//         004a41a4     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a41a9     TEST       EAX,EAX
//                              scr_mps.cpp:2261 (78)
//         004a41ab     MOV        EAX,dword ptr [EBP + 0x840]
//         004a41b1     JZ         LAB_004a41fb
//         004a41b3     TEST       EAX,EAX
//         004a41b5     JNZ        LAB_004a41ff
//         004a41b7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a41bd     LEA        ESI,[EBP + 0x740]
//         004a41c3     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//                               LAB_004a41c8                                                 XREF[1]:     004a41ea(j)
//         004a41c8     MOV        DL,byte ptr [EAX]
//         004a41ca     MOV        BL,byte ptr [ESI]
//         004a41cc     MOV        this,DL
//         004a41ce     CMP        DL,BL
//         004a41d0     JNZ        LAB_004a41f0
//         004a41d2     TEST       this,this
//         004a41d4     JZ         LAB_004a41ec
//         004a41d6     MOV        DL,byte ptr [EAX + 0x1]
//         004a41d9     MOV        BL,byte ptr [ESI + 0x1]
//         004a41dc     MOV        this,DL
//         004a41de     CMP        DL,BL
//         004a41e0     JNZ        LAB_004a41f0
//         004a41e2     ADD        EAX,0x2
//         004a41e5     ADD        ESI,0x2
//         004a41e8     TEST       this,this
//         004a41ea     JNZ        LAB_004a41c8
//                               LAB_004a41ec                                                 XREF[1]:     004a41d4(j)
//         004a41ec     XOR        EAX,EAX
//         004a41ee     JMP        LAB_004a41f5
//                               LAB_004a41f0                                                 XREF[2]:     004a41d0(j), 004a41e0(j)
//         004a41f0     SBB        EAX,EAX
//         004a41f2     SBB        EAX,-0x1
//                               LAB_004a41f5                                                 XREF[1]:     004a41ee(j)
//         004a41f5     TEST       EAX,EAX
//         004a41f7     JZ         LAB_004a4204
//                              scr_mps.cpp:2264 (6)
//         004a41f9     JMP        LAB_004a41ff
//                               LAB_004a41fb                                                 XREF[1]:     004a41b1(j)
//         004a41fb     TEST       EAX,EAX
//         004a41fd     JNZ        LAB_004a4204
//                               LAB_004a41ff                                                 XREF[2]:     004a41b5(j), 004a41f9(j)
//                              scr_mps.cpp:2265 (5)
//         004a41ff     MOV        EDI,0x1
//                               LAB_004a4204                                                 XREF[2]:     004a41f7(j), 004a41fd(j)
//                              scr_mps.cpp:2268 (8)
//         004a4204     TEST       EDI,EDI
//         004a4206     JZ         LAB_004a4611
//                              scr_mps.cpp:2271 (19)
//         004a420c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4212     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a4217     TEST       EAX,EAX
//         004a4219     JZ         LAB_004a4417
//                              scr_mps.cpp:2273 (12)
//         004a421f     MOV        this,dword ptr [EBP + 0x848]
//         004a4225     XOR        EBX,EBX
//         004a4227     CMP        this,EBX
//         004a4229     JZ         LAB_004a4238
//                              scr_mps.cpp:2275 (7)
//         004a422b     MOV        EAX,dword ptr [this->_padding_]
//         004a422d     PUSH       0x1
//         004a422f     CALL       dword ptr [EAX + 0x4]
//                              scr_mps.cpp:2276 (6)
//         004a4232     MOV        dword ptr [EBP + 0x848],EBX
//                               LAB_004a4238                                                 XREF[1]:     004a4229(j)
//                              scr_mps.cpp:2283 (40)
//         004a4238     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a423e     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004a4241     ADD        ESI,0xc17
//         004a4247     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a424c     PUSH       EAX
//         004a424d     PUSH       ESI=>DAT_fffffff8
//         004a424e     LEA        this,[ESP + 0x1c]
//         004a4252     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         004a4257     PUSH       this=>DAT_fffffff0
//         004a4258     CALL       sprintf                                          undefined sprintf()
//         004a425d     ADD        ESP,0x10
//                              scr_mps.cpp:2284 (18)
//         004a4260     LEA        EDX,[ESP + 0x214]
//         004a4267     LEA        EAX,[ESP + 0x14]
//         004a426b     PUSH       EDX
//         004a426c     PUSH       EAX=>DAT_fffffff8
//         004a426d     CALL       __findfirst                                      undefined __findfirst()
//                              scr_mps.cpp:2286 (30)
//         004a4272     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4278     ADD        ESP,0x8
//         004a427b     CMP        EAX,-0x1
//         004a427e     JNZ        LAB_004a4292
//         004a4280     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a4285     PUSH       EAX
//         004a4286     LEA        this,[ESP + 0x18]
//         004a428a     PUSH       s_%s.scx                                         = "%s.scx"
//         004a428f     PUSH       this=>DAT_fffffff4
//                              scr_mps.cpp:2287 (2)
//         004a4290     JMP        LAB_004a42a2
//                               LAB_004a4292                                                 XREF[1]:     004a427e(j)
//                              scr_mps.cpp:2288 (21)
//         004a4292     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a4297     PUSH       EAX
//         004a4298     LEA        EDX,[ESP + 0x18]
//         004a429c     PUSH       s_%s.scn                                         = "%s.scn"
//         004a42a1     PUSH       EDX=>DAT_fffffff4
//                               LAB_004a42a2                                                 XREF[1]:     004a4290(j)
//         004a42a2     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2290 (11)
//         004a42a7     MOV        AL,byte ptr [ESP + 0x20]
//         004a42ab     ADD        ESP,0xc
//         004a42ae     CMP        AL,0x2e
//         004a42b0     JZ         LAB_004a42c9
//                              scr_mps.cpp:2291 (23)
//         004a42b2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a42b8     LEA        EAX,[ESP + 0x14]
//         004a42bc     PUSH       EBX
//         004a42bd     PUSH       EAX=>DAT_fffffff8
//         004a42be     CALL       RGE_Base_Game::get_scenario_info                 RGE_Scenario * get_scenario_info(RGE_Base_Gam
//         004a42c3     MOV        dword ptr [EBP + 0x848],EAX
//                               LAB_004a42c9                                                 XREF[1]:     004a42b0(j)
//                              scr_mps.cpp:2293 (8)
//         004a42c9     CMP        dword ptr [EBP + 0x848],EBX
//         004a42cf     JNZ        LAB_004a42e2
//                              scr_mps.cpp:2298 (12)
//         004a42d1     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a42d7     PUSH       EBX
//         004a42d8     CALL       RGE_Base_Game::setScenarioGame                   void setScenarioGame(RGE_Base_Game * this, in
//                              scr_mps.cpp:2301 (5)
//         004a42dd     JMP        LAB_004a4417
//                               LAB_004a42e2                                                 XREF[1]:     004a42cf(j)
//                              scr_mps.cpp:2686 (158)
//         004a42e2     LEA        ESI,[EBP + 0x5f0]
//         004a42e8     MOV        EDI,0x8
//                               LAB_004a42ed                                                 XREF[1]:     004a42f8(j)
//         004a42ed     MOV        this,dword ptr [ESI]
//         004a42ef     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//         004a42f4     ADD        ESI,0x4
//         004a42f7     DEC        EDI
//         004a42f8     JNZ        LAB_004a42ed
//         004a42fa     MOV        this,dword ptr [EBP + 0x848]
//         004a4300     CALL       T_Scenario::any_sp_victory                       int any_sp_victory(T_Scenario * this)
//         004a4305     MOV        dword ptr [EBP + 0x84c],EAX
//         004a430b     MOV        dword ptr [EBP + 0x850],EBX
//         004a4311     MOV        dword ptr [EBP + 0x728],EBX
//                               LAB_004a4317                                                 XREF[1]:     004a43b2(j)
//         004a4317     MOV        this,dword ptr [EBP + 0x848]
//         004a431d     PUSH       EBX
//         004a431e     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
//         004a4323     TEST       EAX,EAX
//         004a4325     JZ         LAB_004a43ae
//         004a432b     MOV        this,dword ptr [EBP + 0x728]
//         004a4331     LEA        EDX,[ESP + 0x114]
//         004a4338     INC        this
//         004a4339     MOV        dword ptr [EBP + 0x728],this
//         004a433f     LEA        this,[EBX + 0x1]
//         004a4342     PUSH       this
//         004a4343     PUSH       s_%d                                             = 6425h
//         004a4348     PUSH       EDX=>DAT_fffffff4
//         004a4349     CALL       sprintf                                          undefined sprintf()
//         004a434e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4354     ADD        ESP,0xc
//         004a4357     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a435c     TEST       EAX,EAX
//         004a435e     JNZ        LAB_004a4380
//         004a4360     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4366     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a436b     TEST       EAX,EAX
//         004a436d     JZ         LAB_004a43ae
//         004a436f     MOV        this,dword ptr [EBP + 0x848]
//         004a4375     PUSH       EBX
//         004a4376     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int
//         004a437b     CMP        EAX,0x1
//         004a437e     JNZ        LAB_004a43ae
//                               LAB_004a4380                                                 XREF[1]:     004a435e(j)
//                              scr_mps.cpp:2319 (24)
//         004a4380     MOV        EAX,dword ptr [EBP + 0x850]
//         004a4386     LEA        EDI,[EBP + 0x5f0]
//         004a438c     INC        EAX
//         004a438d     MOV        ESI,0x8
//         004a4392     MOV        dword ptr [EBP + 0x850],EAX
//                               LAB_004a4398                                                 XREF[1]:     004a43ac(j)
//                              scr_mps.cpp:2321 (22)
//         004a4398     MOV        this,dword ptr [EDI]
//         004a439a     LEA        EAX,[ESP + 0x114]
//         004a43a1     PUSH       EBX
//         004a43a2     PUSH       EAX=>DAT_fffffff8
//         004a43a3     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//         004a43a8     ADD        EDI,0x4
//         004a43ab     DEC        ESI
//         004a43ac     JNZ        LAB_004a4398
//                               LAB_004a43ae                                                 XREF[3]:     004a4325(j), 004a436d(j),
//                                                                                                         004a437e(j)
//                              scr_mps.cpp:2310 (10)
//         004a43ae     INC        EBX
//         004a43af     CMP        EBX,0x9
//         004a43b2     JL         LAB_004a4317
//                              scr_mps.cpp:2326 (3)
//         004a43b8     OR         EBX,0xffffffff
//                              scr_mps.cpp:2327 (2)
//         004a43bb     XOR        EDI,EDI
//                               LAB_004a43bd                                                 XREF[2]:     004a43d3(j), 004a4415(j)
//                              scr_mps.cpp:2331 (1)
//         004a43bd     INC        EBX
//                              scr_mps.cpp:2332 (5)
//         004a43be     CMP        EBX,0x9
//         004a43c1     JNZ        LAB_004a43c5
//                              scr_mps.cpp:2333 (2)
//         004a43c3     XOR        EBX,EBX
//                               LAB_004a43c5                                                 XREF[1]:     004a43c1(j)
//                              scr_mps.cpp:2334 (16)
//         004a43c5     MOV        this,dword ptr [EBP + 0x848]
//         004a43cb     PUSH       EBX
//         004a43cc     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
//         004a43d1     TEST       EAX,EAX
//         004a43d3     JZ         LAB_004a43bd
//                              scr_mps.cpp:2336 (2)
//         004a43d5     MOV        this,BL
//                              scr_mps.cpp:2337 (22)
//         004a43d7     PUSH       EBX
//         004a43d8     INC        this
//         004a43da     PUSH       EDI=>DAT_fffffff8
//         004a43db     MOV        byte ptr [EDI + EBP*0x1 + 0x860],this
//         004a43e2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a43e8     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:2338 (22)
//         004a43ed     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a43f3     XOR        EDX,EDX
//         004a43f5     MOV        DL,byte ptr [EDI + EBP*0x1 + 0x860]
//         004a43fc     PUSH       EDX
//         004a43fd     PUSH       EDI=>DAT_fffffff8
//         004a43fe     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:2339 (20)
//         004a4403     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4409     PUSH       0x1
//         004a440b     PUSH       EDI=>DAT_fffffff8
//         004a440c     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//         004a4411     INC        EDI
//         004a4412     CMP        EDI,0x8
//         004a4415     JL         LAB_004a43bd
//                               LAB_004a4417                                                 XREF[2]:     004a4219(j), 004a42dd(j)
//                              scr_mps.cpp:2348 (19)
//         004a4417     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a441d     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         004a4422     TEST       EAX,EAX
//         004a4424     JZ         LAB_004a44e8
//                              scr_mps.cpp:2350 (11)
//         004a442a     LEA        ESI,[EBP + 0x5f0]
//         004a4430     MOV        EDI,0x8
//                               LAB_004a4435                                                 XREF[1]:     004a4440(j)
//                              scr_mps.cpp:2351 (13)
//         004a4435     MOV        this,dword ptr [ESI]
//         004a4437     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//         004a443c     ADD        ESI,0x4
//         004a443f     DEC        EDI
//         004a4440     JNZ        LAB_004a4435
//                              scr_mps.cpp:2354 (5)
//         004a4442     MOV        EAX,0x8
//                              scr_mps.cpp:2357 (17)
//         004a4447     MOV        this,0x1
//         004a444c     MOV        dword ptr [EBP + 0x728],EAX
//         004a4452     MOV        dword ptr [EBP + 0x850],EAX
//                              scr_mps.cpp:2361 (63)
//         004a4458     LEA        EAX,[EBP + 0x860]
//         004a445e     XOR        EBX,EBX
//         004a4460     SUB        this,EAX
//         004a4462     MOV        dword ptr [EBP + 0x84c],EBX
//         004a4468     MOV        dword ptr [ESP + 0x10],this
//                               LAB_004a446c                                                 XREF[1]:     004a44e6(j)
//         004a446c     MOV        AL,BL
//         004a446e     LEA        EDI,[EBX + EBP*0x1 + 0x860]
//         004a4475     INC        AL
//         004a4477     PUSH       EBX
//         004a4478     MOV        byte ptr [EDI],AL
//         004a447a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4480     PUSH       EBX=>DAT_fffffff8
//         004a4481     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//         004a4486     XOR        this,this
//         004a4488     MOV        this,byte ptr [EDI]
//         004a448a     PUSH       this
//         004a448b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4491     PUSH       EBX=>DAT_fffffff8
//         004a4492     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:2362 (18)
//         004a4497     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a449d     PUSH       0x1
//         004a449f     PUSH       EBX=>DAT_fffffff8
//         004a44a0     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//         004a44a5     MOV        EDX,dword ptr [ESP + 0x10]
//                              scr_mps.cpp:2363 (35)
//         004a44a9     LEA        EAX,[ESP + 0x114]
//         004a44b0     ADD        EDX,EDI
//         004a44b2     PUSH       EDX
//         004a44b3     PUSH       s_%d                                             = 6425h
//         004a44b8     PUSH       EAX=>DAT_fffffff4
//         004a44b9     CALL       sprintf                                          undefined sprintf()
//         004a44be     ADD        ESP,0xc
//         004a44c1     LEA        EDI,[EBP + 0x5f0]
//         004a44c7     MOV        ESI,0x8
//                               LAB_004a44cc                                                 XREF[1]:     004a44e0(j)
//                              scr_mps.cpp:2365 (28)
//         004a44cc     LEA        this,[ESP + 0x114]
//         004a44d3     PUSH       EBX
//         004a44d4     PUSH       this=>DAT_fffffff8
//         004a44d5     MOV        this,dword ptr [EDI]
//         004a44d7     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//         004a44dc     ADD        EDI,0x4
//         004a44df     DEC        ESI
//         004a44e0     JNZ        LAB_004a44cc
//         004a44e2     INC        EBX
//         004a44e3     CMP        EBX,0x8
//         004a44e6     JL         LAB_004a446c
//                               LAB_004a44e8                                                 XREF[1]:     004a4424(j)
//                              scr_mps.cpp:2370 (15)
//         004a44e8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a44ee     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a44f3     TEST       EAX,EAX
//         004a44f5     JZ         LAB_004a44fe
//                              scr_mps.cpp:2371 (7)
//         004a44f7     MOV        this,EBP
//         004a44f9     CALL       TribeMPSetupScreen::setupSinglePlayerPlayers     void setupSinglePlayerPlayers(TribeMPSetupScr
//                               LAB_004a44fe                                                 XREF[1]:     004a44f5(j)
//                              scr_mps.cpp:2374 (11)
//         004a44fe     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4504     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//                              scr_mps.cpp:2375 (10)
//         004a4509     TEST       EAX,EAX
//         004a450b     MOV        dword ptr [EBP + 0x840],EAX
//         004a4511     JZ         LAB_004a451c
//                              scr_mps.cpp:2376 (7)
//         004a4513     MOV        byte ptr [EBP + 0x740],0x0
//                              scr_mps.cpp:2377 (2)
//         004a451a     JMP        LAB_004a454c
//                               LAB_004a451c                                                 XREF[1]:     004a4511(j)
//                              scr_mps.cpp:2378 (48)
//         004a451c     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4522     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a4527     MOV        EDI,EAX
//         004a4529     OR         this,0xffffffff
//         004a452c     XOR        EAX,EAX
//         004a452e     LEA        EDX,[EBP + 0x740]
//         004a4534     SCASB.RE   ES:EDI
//         004a4536     NOT        this
//         004a4538     SUB        EDI,this
//         004a453a     MOV        EAX,this
//         004a453c     MOV        ESI,EDI
//         004a453e     MOV        EDI,EDX
//         004a4540     SHR        this,0x2
//         004a4543     MOVSD.REP  ES:EDI,ESI
//         004a4545     MOV        this,EAX
//         004a4547     AND        this,0x3
//         004a454a     MOVSB.REP  ES:EDI,ESI
//                               LAB_004a454c                                                 XREF[1]:     004a451a(j)
//                              scr_mps.cpp:2381 (6)
//         004a454c     LEA        EDI,[EBP + 0x868]
//                              scr_mps.cpp:2382 (9)
//         004a4552     MOV        this,0x8
//         004a4557     XOR        EAX,EAX
//         004a4559     STOSD.REP  ES:EDI
//                              scr_mps.cpp:2384 (19)
//         004a455b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4561     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a4566     TEST       EAX,EAX
//         004a4568     JZ         LAB_004a4607
//                              scr_mps.cpp:2391 (43)
//         004a456e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4574     MOV        ESI,dword ptr [ECX + this->_padding_]
//         004a4577     ADD        ESI,0xc17
//         004a457d     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a4582     PUSH       EAX
//         004a4583     PUSH       ESI=>DAT_fffffff8
//         004a4584     LEA        this,[ESP + 0x21c]
//         004a458b     PUSH       s_%s%s.scn                                       = "%s%s.scn"
//         004a4590     PUSH       this=>DAT_fffffff0
//         004a4591     CALL       sprintf                                          undefined sprintf()
//         004a4596     ADD        ESP,0x10
//                              scr_mps.cpp:2392 (21)
//         004a4599     LEA        EDX,[ESP + 0x42c]
//         004a45a0     LEA        EAX,[ESP + 0x214]
//         004a45a7     PUSH       EDX
//         004a45a8     PUSH       EAX=>DAT_fffffff8
//         004a45a9     CALL       __findfirst                                      undefined __findfirst()
//                              scr_mps.cpp:2394 (33)
//         004a45ae     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a45b4     ADD        ESP,0x8
//         004a45b7     CMP        EAX,-0x1
//         004a45ba     JNZ        LAB_004a45d1
//         004a45bc     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a45c1     PUSH       EAX
//         004a45c2     LEA        this,[ESP + 0x218]
//         004a45c9     PUSH       s_%s.scx                                         = "%s.scx"
//         004a45ce     PUSH       this=>DAT_fffffff4
//                              scr_mps.cpp:2395 (2)
//         004a45cf     JMP        LAB_004a45e4
//                               LAB_004a45d1                                                 XREF[1]:     004a45ba(j)
//                              scr_mps.cpp:2396 (24)
//         004a45d1     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a45d6     PUSH       EAX
//         004a45d7     LEA        EDX,[ESP + 0x218]
//         004a45de     PUSH       s_%s.scn                                         = "%s.scn"
//         004a45e3     PUSH       EDX=>DAT_fffffff4
//                               LAB_004a45e4                                                 XREF[1]:     004a45cf(j)
//         004a45e4     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2398 (28)
//         004a45e9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a45ef     ADD        ESP,0xc
//         004a45f2     LEA        EAX,[ESP + 0x214]
//         004a45f9     PUSH       EAX
//         004a45fa     CALL       RGE_Base_Game::get_scenario_checksum             long get_scenario_checksum(RGE_Base_Game * th
//         004a45ff     MOV        dword ptr [EBP + 0x73c],EAX
//                              scr_mps.cpp:2400 (2)
//         004a4605     JMP        LAB_004a4611
//                               LAB_004a4607                                                 XREF[1]:     004a4568(j)
//                              scr_mps.cpp:2401 (10)
//         004a4607     MOV        dword ptr [EBP + 0x73c],0x0
//                               LAB_004a4611                                                 XREF[2]:     004a4206(j), 004a4605(j)
//                              scr_mps.cpp:2409 (11)
//         004a4611     LEA        ESI,[EBP + 0x62c]
//         004a4617     MOV        EDI,0x14
//                               LAB_004a461c                                                 XREF[1]:     004a4629(j)
//                              scr_mps.cpp:2410 (15)
//         004a461c     MOV        this,dword ptr [ESI]
//         004a461e     PUSH       0x0
//         004a4620     MOV        EDX,dword ptr [this->_padding_]
//         004a4622     CALL       dword ptr [EDX + 0x14]
//         004a4625     ADD        ESI,0x4
//         004a4628     DEC        EDI
//         004a4629     JNZ        LAB_004a461c
//                              scr_mps.cpp:2412 (11)
//         004a462b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4631     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//                              scr_mps.cpp:2415 (42)
//         004a4636     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a463c     TEST       EAX,EAX
//         004a463e     JZ         LAB_004a4680
//         004a4640     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a4645     PUSH       EAX
//                              language.dll match for 0x25ed: "Scenario: %s"
//         004a4646     PUSH       offset DAT_fffffff8
//         004a464b     MOV        this,EBP
//         004a464d     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4652     PUSH       EAX=>DAT_fffffff8
//         004a4653     LEA        EAX,[ESP + 0x11c]
//         004a465a     PUSH       EAX=>DAT_fffffff4
//         004a465b     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2416 (25)
//         004a4660     MOV        this,dword ptr [EBP + 0x624]
//         004a4666     ADD        ESP,0xc
//         004a4669     LEA        EAX,[ESP + 0x114]
//         004a4670     MOV        EDX,dword ptr [this->_padding_]
//         004a4672     PUSH       EAX
//         004a4673     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2417 (5)
//         004a4679     MOV        EBX,0x3
//                              scr_mps.cpp:2419 (2)
//         004a467e     JMP        LAB_004a46e8
//                               LAB_004a4680                                                 XREF[1]:     004a463e(j)
//                              scr_mps.cpp:2421 (7)
//         004a4680     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         004a4685     TEST       AL,AL
//                              scr_mps.cpp:2422 (17)
//         004a4687     PUSH       0x100
//         004a468c     JZ         LAB_004a469a
//         004a468e     LEA        this,[ESP + 0x18]
//         004a4692     PUSH       this=>DAT_fffffff8
//         004a4693     PUSH       offset DAT_fffffff4
//                              scr_mps.cpp:2423 (2)
//         004a4698     JMP        LAB_004a46a4
//                               LAB_004a469a                                                 XREF[1]:     004a468c(j)
//                              scr_mps.cpp:2424 (17)
//         004a469a     LEA        EDX,[ESP + 0x18]
//         004a469e     PUSH       EDX=>DAT_fffffff8
//                              language.dll match for 0x25b5: "Random Map"
//         004a469f     PUSH       offset DAT_fffffff4
//                               LAB_004a46a4                                                 XREF[1]:     004a4698(j)
//         004a46a4     MOV        this,EBP
//         004a46a6     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2425 (31)
//         004a46ab     LEA        EAX,[ESP + 0x14]
//         004a46af     MOV        this,EBP
//         004a46b1     PUSH       EAX
//                              language.dll match for 0x25ed: "Scenario: %s"
//         004a46b2     PUSH       offset DAT_fffffff8
//         004a46b7     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a46bc     LEA        this,[ESP + 0x118]
//         004a46c3     PUSH       EAX=>DAT_fffffff8
//         004a46c4     PUSH       this=>DAT_fffffff4
//         004a46c5     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2426 (25)
//         004a46ca     MOV        this,dword ptr [EBP + 0x624]
//         004a46d0     ADD        ESP,0xc
//         004a46d3     LEA        EAX,[ESP + 0x114]
//         004a46da     MOV        EDX,dword ptr [this->_padding_]
//         004a46dc     PUSH       EAX
//         004a46dd     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2427 (5)
//         004a46e3     MOV        EBX,0x1
//                               LAB_004a46e8                                                 XREF[1]:     004a467e(j)
//                              scr_mps.cpp:2430 (19)
//         004a46e8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a46ee     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         004a46f3     TEST       EAX,EAX
//         004a46f5     JZ         LAB_004a4872
//                              scr_mps.cpp:2433 (23)
//         004a46fb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4701     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
//         004a4706     CMP        EAX,0x5
//         004a4709     JA         switchD_004a470b::default
//                               switchD_004a470b::switchD
//         004a470b     JMP        dword ptr [EAX*0x4 + switchD_004a470b::switchd   = 004a4712
//                               switchD_004a470b::caseD_0                                    XREF[2]:     004a470b(j), 004a4f54(*)
//                              scr_mps.cpp:2435 (7)
//         004a4712     PUSH       0x2973
//         004a4717     JMP        LAB_004a473a
//                               switchD_004a470b::caseD_1                                    XREF[2]:     004a470b(j), 004a4f58(*)
//                              scr_mps.cpp:2436 (7)
//         004a4719     PUSH       0x2974
//         004a471e     JMP        LAB_004a473a
//                               switchD_004a470b::caseD_2                                    XREF[2]:     004a470b(j), 004a4f5c(*)
//                              scr_mps.cpp:2437 (7)
//         004a4720     PUSH       0x2975
//         004a4725     JMP        LAB_004a473a
//                               switchD_004a470b::caseD_3                                    XREF[2]:     004a470b(j), 004a4f60(*)
//                              scr_mps.cpp:2438 (7)
//         004a4727     PUSH       0x2976
//         004a472c     JMP        LAB_004a473a
//                              language.dll match for 0x2977: "Huge"
//                               switchD_004a470b::caseD_4                                    XREF[2]:     004a470b(j), 004a4f64(*)
//                              scr_mps.cpp:2439 (7)
//         004a472e     PUSH       0x2977
//         004a4733     JMP        LAB_004a473a
//                              language.dll match for 0x2978: "Gigantic"
//                               switchD_004a470b::caseD_5                                    XREF[2]:     004a470b(j), 004a4f68(*)
//                              scr_mps.cpp:2440 (47)
//         004a4735     PUSH       0x2978
//                               LAB_004a473a                                                 XREF[5]:     004a4717(j), 004a471e(j),
//                                                                                                         004a4725(j), 004a472c(j),
//                                                                                                         004a4733(j)
//         004a473a     MOV        this,EBP
//         004a473c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4741     MOV        EDI,EAX
//         004a4743     OR         this,0xffffffff
//         004a4746     XOR        EAX,EAX
//         004a4748     LEA        EDX,[ESP + 0x14]
//         004a474c     SCASB.RE   ES:EDI
//         004a474e     NOT        this
//         004a4750     SUB        EDI,this
//         004a4752     MOV        EAX,this
//         004a4754     MOV        ESI,EDI
//         004a4756     MOV        EDI,EDX
//         004a4758     SHR        this,0x2
//         004a475b     MOVSD.REP  ES:EDI,ESI
//         004a475d     MOV        this,EAX
//         004a475f     AND        this,0x3
//         004a4762     MOVSB.REP  ES:EDI,ESI
//                               switchD_004a470b::default                                    XREF[1]:     004a4709(j)
//                              scr_mps.cpp:2442 (31)
//         004a4764     LEA        this,[ESP + 0x14]
//         004a4768     PUSH       this
//                              language.dll match for 0x25da: "Map Size: %s"
//         004a4769     PUSH       offset DAT_fffffff8
//         004a476e     MOV        this,EBP
//         004a4770     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4775     LEA        EDX,[ESP + 0x118]
//         004a477c     PUSH       EAX=>DAT_fffffff8
//         004a477d     PUSH       EDX=>DAT_fffffff4
//         004a477e     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2443 (26)
//         004a4783     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a478a     ADD        ESP,0xc
//         004a478d     LEA        EDX,[ESP + 0x114]
//         004a4794     MOV        EAX,dword ptr [this->_padding_]
//         004a4796     PUSH       EDX
//         004a4797     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:2444 (14)
//         004a479d     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a47a4     PUSH       0x1
//         004a47a6     MOV        EAX,dword ptr [this->_padding_]
//         004a47a8     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2448 (24)
//         004a47ab     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a47b1     INC        EBX
//         004a47b2     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         004a47b7     CMP        EAX,0x8
//         004a47ba     JA         switchD_004a47bc::default
//                               switchD_004a47bc::switchD
//         004a47bc     JMP        dword ptr [EAX*0x4 + switchD_004a47bc::switchd   = 004a47c3
//                               switchD_004a47bc::caseD_0                                    XREF[2]:     004a47bc(j), 004a4f6c(*)
//                              scr_mps.cpp:2450 (7)
//         004a47c3     PUSH       0x296a
//         004a47c8     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_1                                    XREF[2]:     004a47bc(j), 004a4f70(*)
//                              scr_mps.cpp:2451 (7)
//         004a47ca     PUSH       0x296b
//         004a47cf     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_2                                    XREF[2]:     004a47bc(j), 004a4f74(*)
//                              scr_mps.cpp:2452 (7)
//         004a47d1     PUSH       0x296c
//         004a47d6     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_3                                    XREF[2]:     004a47bc(j), 004a4f78(*)
//                              scr_mps.cpp:2453 (7)
//         004a47d8     PUSH       0x296d
//         004a47dd     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_4                                    XREF[2]:     004a47bc(j), 004a4f7c(*)
//                              scr_mps.cpp:2454 (7)
//         004a47df     PUSH       0x296e
//         004a47e4     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_5                                    XREF[2]:     004a47bc(j), 004a4f80(*)
//                              scr_mps.cpp:2455 (7)
//         004a47e6     PUSH       0x296f
//         004a47eb     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_6                                    XREF[2]:     004a47bc(j), 004a4f84(*)
//                              scr_mps.cpp:2456 (7)
//         004a47ed     PUSH       0x2970
//         004a47f2     JMP        LAB_004a4800
//                               switchD_004a47bc::caseD_7                                    XREF[2]:     004a47bc(j), 004a4f88(*)
//                              scr_mps.cpp:2457 (7)
//         004a47f4     PUSH       0x2971
//         004a47f9     JMP        LAB_004a4800
//                              language.dll match for 0x2972: "Narrows"
//                              language.dll match for 0x2972: "******* SIZE *******"
//                               switchD_004a47bc::caseD_8                                    XREF[2]:     004a47bc(j), 004a4f8c(*)
//                              scr_mps.cpp:2458 (47)
//         004a47fb     PUSH       0x2972
//                               LAB_004a4800                                                 XREF[8]:     004a47c8(j), 004a47cf(j),
//                                                                                                         004a47d6(j), 004a47dd(j),
//                                                                                                         004a47e4(j), 004a47eb(j),
//                                                                                                         004a47f2(j), 004a47f9(j)
//         004a4800     MOV        this,EBP
//         004a4802     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4807     MOV        EDI,EAX
//         004a4809     OR         this,0xffffffff
//         004a480c     XOR        EAX,EAX
//         004a480e     LEA        EDX,[ESP + 0x14]
//         004a4812     SCASB.RE   ES:EDI
//         004a4814     NOT        this
//         004a4816     SUB        EDI,this
//         004a4818     MOV        EAX,this
//         004a481a     MOV        ESI,EDI
//         004a481c     MOV        EDI,EDX
//         004a481e     SHR        this,0x2
//         004a4821     MOVSD.REP  ES:EDI,ESI
//         004a4823     MOV        this,EAX
//         004a4825     AND        this,0x3
//         004a4828     MOVSB.REP  ES:EDI,ESI
//                               switchD_004a47bc::default                                    XREF[1]:     004a47ba(j)
//                              scr_mps.cpp:2460 (31)
//         004a482a     LEA        this,[ESP + 0x14]
//         004a482e     PUSH       this
//                              language.dll match for 0x25b6: "Map Type: %s"
//         004a482f     PUSH       offset DAT_fffffff8
//         004a4834     MOV        this,EBP
//         004a4836     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a483b     LEA        EDX,[ESP + 0x118]
//         004a4842     PUSH       EAX=>DAT_fffffff8
//         004a4843     PUSH       EDX=>DAT_fffffff4
//         004a4844     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2461 (26)
//         004a4849     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4850     ADD        ESP,0xc
//         004a4853     LEA        EDX,[ESP + 0x114]
//         004a485a     MOV        EAX,dword ptr [this->_padding_]
//         004a485c     PUSH       EDX
//         004a485d     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:2462 (14)
//         004a4863     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a486a     PUSH       0x1
//         004a486c     MOV        EAX,dword ptr [this->_padding_]
//         004a486e     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2463 (1)
//         004a4871     INC        EBX
//                               LAB_004a4872                                                 XREF[1]:     004a46f5(j)
//                              scr_mps.cpp:2467 (15)
//         004a4872     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4878     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a487d     TEST       EAX,EAX
//         004a487f     JZ         LAB_004a48e8
//                              scr_mps.cpp:2469 (21)
//         004a4881     MOV        EAX,dword ptr [EBP + 0x84c]
//         004a4887     TEST       EAX,EAX
//         004a4889     JNZ        LAB_004a48bd
//         004a488b     MOV        EAX,dword ptr [EBP + 0x728]
//         004a4891     CMP        EAX,0x2
//         004a4894     JZ         LAB_004a48bd
//                              scr_mps.cpp:2472 (39)
//         004a4896     PUSH       EAX
//         004a4897     PUSH       offset DAT_fffffff8
//                              language.dll match for 0x25b7: "Players:"
//         004a4899     PUSH       offset DAT_fffffff4
//         004a489e     MOV        this,EBP
//         004a48a0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a48a5     PUSH       EAX=>DAT_fffffff4
//         004a48a6     LEA        this,[ESP + 0x120]
//         004a48ad     PUSH       s_%s_%d_-_%d                                     = "%s %d - %d"
//         004a48b2     PUSH       this
//         004a48b3     CALL       sprintf                                          undefined sprintf()
//         004a48b8     ADD        ESP,0x14
//         004a48bb     JMP        LAB_004a490a
//                               LAB_004a48bd                                                 XREF[2]:     004a4889(j), 004a4894(j)
//                              scr_mps.cpp:2470 (41)
//         004a48bd     MOV        EDX,dword ptr [EBP + 0x728]
//         004a48c3     MOV        this,EBP
//         004a48c5     PUSH       EDX
//                              language.dll match for 0x25b7: "Players:"
//         004a48c6     PUSH       offset DAT_fffffff8
//         004a48cb     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a48d0     PUSH       EAX=>DAT_fffffff8
//         004a48d1     LEA        EAX,[ESP + 0x11c]
//         004a48d8     PUSH       s_%s_%d                                          = "%s %d"
//         004a48dd     PUSH       EAX=>DAT_fffffff0
//         004a48de     CALL       sprintf                                          undefined sprintf()
//         004a48e3     ADD        ESP,0x10
//                              scr_mps.cpp:2474 (2)
//         004a48e6     JMP        LAB_004a490a
//                              language.dll match for 0x25b7: "Players:"
//                               LAB_004a48e8                                                 XREF[1]:     004a487f(j)
//                              scr_mps.cpp:2475 (34)
//         004a48e8     PUSH       0x25b7
//         004a48ed     MOV        this,EBP
//         004a48ef     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a48f4     PUSH       EAX
//         004a48f5     LEA        this,[ESP + 0x118]
//         004a48fc     PUSH       s_%s_2_-_8                                       = "%s 2 - 8"
//         004a4901     PUSH       this=>DAT_fffffff4
//         004a4902     CALL       sprintf                                          undefined sprintf()
//         004a4907     ADD        ESP,0xc
//                               LAB_004a490a                                                 XREF[2]:     004a48bb(j), 004a48e6(j)
//                              scr_mps.cpp:2476 (23)
//         004a490a     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4911     LEA        EAX,[ESP + 0x114]
//         004a4918     PUSH       EAX
//         004a4919     MOV        EDX,dword ptr [this->_padding_]
//         004a491b     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2477 (14)
//         004a4921     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4928     PUSH       0x1
//         004a492a     MOV        EDX,dword ptr [this->_padding_]
//         004a492c     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2481 (25)
//         004a492f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4935     INC        EBX
//         004a4936     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         004a493b     DEC        EAX
//         004a493c     CMP        EAX,0x8
//         004a493f     JA         switchD_004a4941::caseD_2
//                               switchD_004a4941::switchD
//         004a4941     JMP        dword ptr [EAX*0x4 + switchD_004a4941::switchd   = 004a4948
//                               switchD_004a4941::caseD_1                                    XREF[2]:     004a4941(j), 004a4f90(*)
//                              scr_mps.cpp:2484 (5)
//         004a4948     PUSH       0x10e1
//                              scr_mps.cpp:2489 (5)
//         004a494d     JMP        LAB_004a49d3
//                               switchD_004a4941::caseD_7                                    XREF[2]:     004a4941(j), 004a4fa8(*)
//                              scr_mps.cpp:2492 (5)
//         004a4952     PUSH       0x10e9
//                              scr_mps.cpp:2497 (2)
//         004a4957     JMP        LAB_004a495e
//                              language.dll match for 0x10ea: "Score"
//                               switchD_004a4941::caseD_8                                    XREF[2]:     004a4941(j), 004a4fac(*)
//                              scr_mps.cpp:2500 (47)
//         004a4959     PUSH       0x10ea
//                               LAB_004a495e                                                 XREF[1]:     004a4957(j)
//         004a495e     MOV        this,EBP
//         004a4960     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4965     MOV        EDI,EAX
//         004a4967     OR         this,0xffffffff
//         004a496a     XOR        EAX,EAX
//         004a496c     LEA        EDX,[ESP + 0x14]
//         004a4970     SCASB.RE   ES:EDI
//         004a4972     NOT        this
//         004a4974     SUB        EDI,this
//         004a4976     MOV        EAX,this
//         004a4978     MOV        ESI,EDI
//         004a497a     MOV        EDI,EDX
//         004a497c     SHR        this,0x2
//         004a497f     MOVSD.REP  ES:EDI,ESI
//         004a4981     MOV        this,EAX
//         004a4983     AND        this,0x3
//         004a4986     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:2501 (46)
//         004a4988     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a498e     CALL       TRIBE_Game::victoryAmount                        int victoryAmount(TRIBE_Game * this)
//         004a4993     LEA        this,[ESP + 0x14]
//         004a4997     PUSH       EAX
//         004a4998     PUSH       this=>DAT_fffffff8
//                              language.dll match for 0x25be: "Victory: %s (%d)"
//         004a4999     PUSH       offset DAT_fffffff4
//         004a499e     MOV        this,EBP
//         004a49a0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a49a5     LEA        EDX,[ESP + 0x11c]
//         004a49ac     PUSH       EAX=>DAT_fffffff4
//         004a49ad     PUSH       EDX=>DAT_fffffff0
//         004a49ae     CALL       sprintf                                          undefined sprintf()
//         004a49b3     ADD        ESP,0x10
//                              scr_mps.cpp:2505 (2)
//         004a49b6     JMP        LAB_004a4a1f
//                               switchD_004a4941::caseD_3                                    XREF[7]:     004a493f(j), 004a4941(j),
//                               switchD_004a4941::caseD_4                                                 004a4f94(*), 004a4f98(*),
//                               switchD_004a4941::caseD_5                                                 004a4f9c(*), 004a4fa0(*),
//                               switchD_004a4941::caseD_6                                                 004a4fa4(*)
//                               switchD_004a4941::caseD_2
//                              scr_mps.cpp:2558 (15)
//         004a49b8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a49be     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         004a49c3     TEST       EAX,EAX
//         004a49c5     JZ         LAB_004a49ce
//                               switchD_004a4941::caseD_9                                    XREF[2]:     004a4941(j), 004a4fb0(*)
//                              scr_mps.cpp:2559 (5)
//         004a49c7     PUSH       0x10ec
//                              scr_mps.cpp:2560 (2)
//         004a49cc     JMP        LAB_004a49d3
//                              language.dll match for 0x10e7: "Default"
//                               LAB_004a49ce                                                 XREF[1]:     004a49c5(j)
//                              scr_mps.cpp:2561 (47)
//         004a49ce     PUSH       0x10e7
//                               LAB_004a49d3                                                 XREF[2]:     004a494d(j), 004a49cc(j)
//         004a49d3     MOV        this,EBP
//         004a49d5     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a49da     MOV        EDI,EAX
//         004a49dc     OR         this,0xffffffff
//         004a49df     XOR        EAX,EAX
//         004a49e1     LEA        EDX,[ESP + 0x14]
//         004a49e5     SCASB.RE   ES:EDI
//         004a49e7     NOT        this
//         004a49e9     SUB        EDI,this
//         004a49eb     MOV        EAX,this
//         004a49ed     MOV        ESI,EDI
//         004a49ef     MOV        EDI,EDX
//         004a49f1     SHR        this,0x2
//         004a49f4     MOVSD.REP  ES:EDI,ESI
//         004a49f6     MOV        this,EAX
//         004a49f8     AND        this,0x3
//         004a49fb     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:2562 (34)
//         004a49fd     LEA        this,[ESP + 0x14]
//         004a4a01     PUSH       this
//                              language.dll match for 0x25bc: "Victory: %s"
//         004a4a02     PUSH       offset DAT_fffffff8
//         004a4a07     MOV        this,EBP
//         004a4a09     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4a0e     LEA        EDX,[ESP + 0x118]
//         004a4a15     PUSH       EAX=>DAT_fffffff8
//         004a4a16     PUSH       EDX=>DAT_fffffff4
//         004a4a17     CALL       sprintf                                          undefined sprintf()
//         004a4a1c     ADD        ESP,0xc
//                               LAB_004a4a1f                                                 XREF[1]:     004a49b6(j)
//                              scr_mps.cpp:2563 (23)
//         004a4a1f     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4a26     LEA        EDX,[ESP + 0x114]
//         004a4a2d     PUSH       EDX
//         004a4a2e     MOV        EAX,dword ptr [this->_padding_]
//         004a4a30     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:2564 (14)
//         004a4a36     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4a3d     PUSH       0x1
//         004a4a3f     MOV        EAX,dword ptr [this->_padding_]
//         004a4a41     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2570 (12)
//         004a4a44     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4a4a     INC        EBX
//         004a4a4b     CALL       TRIBE_Game::startingAge                          Age startingAge(TRIBE_Game * this)
//                              scr_mps.cpp:2571 (4)
//         004a4a50     TEST       EAX,EAX
//         004a4a52     JNZ        LAB_004a4a65
//                              scr_mps.cpp:2572 (15)
//         004a4a54     LEA        this,[ESP + 0x14]
//         004a4a58     PUSH       0x100
//         004a4a5d     PUSH       this=>DAT_fffffff8
//         004a4a5e     PUSH       offset DAT_fffffff4
//                              scr_mps.cpp:2573 (5)
//         004a4a63     JMP        LAB_004a4a86
//                               LAB_004a4a65                                                 XREF[1]:     004a4a52(j)
//         004a4a65     CMP        EAX,0x1
//                              scr_mps.cpp:2574 (17)
//         004a4a68     PUSH       0x100
//         004a4a6d     JNZ        LAB_004a4a7b
//         004a4a6f     LEA        EDX,[ESP + 0x18]
//         004a4a73     PUSH       EDX=>DAT_fffffff8
//                              language.dll match for 0x106e: "Nomad"
//         004a4a74     PUSH       offset DAT_fffffff4
//                              scr_mps.cpp:2575 (2)
//         004a4a79     JMP        LAB_004a4a86
//                               LAB_004a4a7b                                                 XREF[1]:     004a4a6d(j)
//                              scr_mps.cpp:2576 (18)
//         004a4a7b     LEA        this,[ESP + 0x18]
//         004a4a7f     ADD        EAX,0x1067
//         004a4a84     PUSH       this=>DAT_fffffff8
//         004a4a85     PUSH       EAX=>DAT_fffffff4
//                               LAB_004a4a86                                                 XREF[2]:     004a4a63(j), 004a4a79(j)
//         004a4a86     MOV        this,EBP
//         004a4a88     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2577 (31)
//         004a4a8d     LEA        EDX,[ESP + 0x14]
//         004a4a91     MOV        this,EBP
//         004a4a93     PUSH       EDX
//                              language.dll match for 0x25e4: "Age: %s"
//         004a4a94     PUSH       offset DAT_fffffff8
//         004a4a99     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4a9e     PUSH       EAX=>DAT_fffffff8
//         004a4a9f     LEA        EAX,[ESP + 0x11c]
//         004a4aa6     PUSH       EAX=>DAT_fffffff4
//         004a4aa7     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2578 (26)
//         004a4aac     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4ab3     ADD        ESP,0xc
//         004a4ab6     LEA        EAX,[ESP + 0x114]
//         004a4abd     MOV        EDX,dword ptr [this->_padding_]
//         004a4abf     PUSH       EAX
//         004a4ac0     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2579 (14)
//         004a4ac6     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4acd     PUSH       0x1
//         004a4acf     MOV        EDX,dword ptr [this->_padding_]
//         004a4ad1     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2583 (12)
//         004a4ad4     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4ada     INC        EBX
//         004a4adb     CALL       TRIBE_Game::resourceLevel                        ResourceLevel resourceLevel(TRIBE_Game * this)
//                              scr_mps.cpp:2584 (2)
//         004a4ae0     TEST       EAX,EAX
//                              scr_mps.cpp:2585 (17)
//         004a4ae2     PUSH       0x100
//         004a4ae7     JNZ        LAB_004a4af5
//         004a4ae9     LEA        EAX,[ESP + 0x18]
//         004a4aed     PUSH       EAX=>DAT_fffffff8
//                              language.dll match for 0x10e7: "Default"
//         004a4aee     PUSH       offset DAT_fffffff4
//                              scr_mps.cpp:2586 (2)
//         004a4af3     JMP        LAB_004a4b00
//                               LAB_004a4af5                                                 XREF[1]:     004a4ae7(j)
//                              scr_mps.cpp:2587 (18)
//         004a4af5     LEA        this,[ESP + 0x18]
//         004a4af9     ADD        EAX,0x25e5
//         004a4afe     PUSH       this=>DAT_fffffff8
//         004a4aff     PUSH       EAX=>DAT_fffffff4
//                               LAB_004a4b00                                                 XREF[1]:     004a4af3(j)
//         004a4b00     MOV        this,EBP
//         004a4b02     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2588 (31)
//         004a4b07     LEA        EDX,[ESP + 0x14]
//         004a4b0b     MOV        this,EBP
//         004a4b0d     PUSH       EDX
//                              language.dll match for 0x25e5: "Resources: %s"
//         004a4b0e     PUSH       offset DAT_fffffff8
//         004a4b13     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4b18     PUSH       EAX=>DAT_fffffff8
//         004a4b19     LEA        EAX,[ESP + 0x11c]
//         004a4b20     PUSH       EAX=>DAT_fffffff4
//         004a4b21     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2589 (26)
//         004a4b26     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4b2d     ADD        ESP,0xc
//         004a4b30     LEA        EAX,[ESP + 0x114]
//         004a4b37     MOV        EDX,dword ptr [this->_padding_]
//         004a4b39     PUSH       EAX
//         004a4b3a     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2590 (14)
//         004a4b40     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4b47     PUSH       0x1
//         004a4b49     MOV        EDX,dword ptr [this->_padding_]
//         004a4b4b     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2594 (12)
//         004a4b4e     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4b54     INC        EBX
//         004a4b55     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//                              scr_mps.cpp:2595 (34)
//         004a4b5a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4b60     LEA        EAX,[ESP + 0x14]
//         004a4b64     PUSH       0x100
//         004a4b69     PUSH       EAX=>DAT_fffffff8
//         004a4b6a     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         004a4b6f     ADD        EAX,0x2bd0
//         004a4b74     MOV        this,EBP
//         004a4b76     PUSH       EAX=>DAT_fffffff4
//         004a4b77     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2596 (25)
//         004a4b7c     LEA        this,[ESP + 0x114]
//         004a4b83     PUSH       0x100
//         004a4b88     PUSH       this=>DAT_fffffff8
//                              language.dll match for 0x25e0: "Difficulty Level: %s"
//         004a4b89     PUSH       offset DAT_fffffff4
//         004a4b8e     MOV        this,EBP
//         004a4b90     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2597 (26)
//         004a4b95     LEA        EDX,[ESP + 0x14]
//         004a4b99     LEA        EAX,[ESP + 0x114]
//         004a4ba0     PUSH       EDX
//         004a4ba1     LEA        this,[ESP + 0x330]
//         004a4ba8     PUSH       EAX=>DAT_fffffff8
//         004a4ba9     PUSH       this=>DAT_fffffff4
//         004a4baa     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2598 (26)
//         004a4baf     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4bb6     ADD        ESP,0xc
//         004a4bb9     LEA        EAX,[ESP + 0x32c]
//         004a4bc0     MOV        EDX,dword ptr [this->_padding_]
//         004a4bc2     PUSH       EAX
//         004a4bc3     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2599 (14)
//         004a4bc9     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4bd0     PUSH       0x1
//         004a4bd2     MOV        EDX,dword ptr [this->_padding_]
//         004a4bd4     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2603 (14)
//         004a4bd7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4bdd     INC        EBX
//         004a4bde     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
//         004a4be3     TEST       EAX,EAX
//                              scr_mps.cpp:2604 (17)
//         004a4be5     PUSH       0x100
//         004a4bea     JZ         LAB_004a4bf8
//         004a4bec     LEA        EAX,[ESP + 0x18]
//         004a4bf0     PUSH       EAX=>DAT_fffffff8
//         004a4bf1     PUSH       offset DAT_fffffff4
//                              scr_mps.cpp:2605 (2)
//         004a4bf6     JMP        LAB_004a4c02
//                               LAB_004a4bf8                                                 XREF[1]:     004a4bea(j)
//                              scr_mps.cpp:2606 (17)
//         004a4bf8     LEA        this,[ESP + 0x18]
//         004a4bfc     PUSH       this=>DAT_fffffff8
//                              language.dll match for 0xfa3: "Yes"
//         004a4bfd     PUSH       offset DAT_fffffff4
//                               LAB_004a4c02                                                 XREF[1]:     004a4bf6(j)
//         004a4c02     MOV        this,EBP
//         004a4c04     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2607 (31)
//         004a4c09     LEA        EDX,[ESP + 0x14]
//         004a4c0d     MOV        this,EBP
//         004a4c0f     PUSH       EDX
//                              language.dll match for 0x25e9: "Fixed Positions: %s"
//         004a4c10     PUSH       offset DAT_fffffff8
//         004a4c15     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4c1a     PUSH       EAX=>DAT_fffffff8
//         004a4c1b     LEA        EAX,[ESP + 0x11c]
//         004a4c22     PUSH       EAX=>DAT_fffffff4
//         004a4c23     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2608 (26)
//         004a4c28     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4c2f     ADD        ESP,0xc
//         004a4c32     LEA        EAX,[ESP + 0x114]
//         004a4c39     MOV        EDX,dword ptr [this->_padding_]
//         004a4c3b     PUSH       EAX
//         004a4c3c     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2609 (14)
//         004a4c42     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4c49     PUSH       0x1
//         004a4c4b     MOV        EDX,dword ptr [this->_padding_]
//         004a4c4d     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2613 (16)
//         004a4c50     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4c56     INC        EBX
//         004a4c57     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//         004a4c5c     TEST       EAX,EAX
//         004a4c5e     JZ         LAB_004a4c67
//                              scr_mps.cpp:2614 (5)
//         004a4c60     PUSH       0xfa3
//                              scr_mps.cpp:2615 (2)
//         004a4c65     JMP        LAB_004a4c6c
//                              language.dll match for 0xfa4: "No"
//                               LAB_004a4c67                                                 XREF[1]:     004a4c5e(j)
//                              scr_mps.cpp:2616 (47)
//         004a4c67     PUSH       0xfa4
//                               LAB_004a4c6c                                                 XREF[1]:     004a4c65(j)
//         004a4c6c     MOV        this,EBP
//         004a4c6e     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4c73     MOV        EDI,EAX
//         004a4c75     OR         this,0xffffffff
//         004a4c78     XOR        EAX,EAX
//         004a4c7a     LEA        EDX,[ESP + 0x14]
//         004a4c7e     SCASB.RE   ES:EDI
//         004a4c80     NOT        this
//         004a4c82     SUB        EDI,this
//         004a4c84     MOV        EAX,this
//         004a4c86     MOV        ESI,EDI
//         004a4c88     MOV        EDI,EDX
//         004a4c8a     SHR        this,0x2
//         004a4c8d     MOVSD.REP  ES:EDI,ESI
//         004a4c8f     MOV        this,EAX
//         004a4c91     AND        this,0x3
//         004a4c94     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:2617 (31)
//         004a4c96     LEA        this,[ESP + 0x14]
//         004a4c9a     PUSH       this
//                              language.dll match for 0x25b8: "Reveal Map: %s"
//         004a4c9b     PUSH       offset DAT_fffffff8
//         004a4ca0     MOV        this,EBP
//         004a4ca2     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4ca7     LEA        EDX,[ESP + 0x118]
//         004a4cae     PUSH       EAX=>DAT_fffffff8
//         004a4caf     PUSH       EDX=>DAT_fffffff4
//         004a4cb0     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2618 (26)
//         004a4cb5     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4cbc     ADD        ESP,0xc
//         004a4cbf     LEA        EDX,[ESP + 0x114]
//         004a4cc6     MOV        EAX,dword ptr [this->_padding_]
//         004a4cc8     PUSH       EDX
//         004a4cc9     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:2619 (14)
//         004a4ccf     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4cd6     PUSH       0x1
//         004a4cd8     MOV        EAX,dword ptr [this->_padding_]
//         004a4cda     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2623 (14)
//         004a4cdd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4ce3     INC        EBX
//         004a4ce4     CALL       TRIBE_Game::fullTechTree                         int fullTechTree(TRIBE_Game * this)
//         004a4ce9     TEST       EAX,EAX
//                              scr_mps.cpp:2624 (17)
//         004a4ceb     PUSH       0x100
//         004a4cf0     JZ         LAB_004a4cfe
//         004a4cf2     LEA        this,[ESP + 0x18]
//         004a4cf6     PUSH       this=>DAT_fffffff8
//         004a4cf7     PUSH       offset DAT_fffffff4
//                              scr_mps.cpp:2625 (2)
//         004a4cfc     JMP        LAB_004a4d08
//                               LAB_004a4cfe                                                 XREF[1]:     004a4cf0(j)
//                              scr_mps.cpp:2626 (17)
//         004a4cfe     LEA        EDX,[ESP + 0x18]
//         004a4d02     PUSH       EDX=>DAT_fffffff8
//                              language.dll match for 0xfa4: "No"
//         004a4d03     PUSH       offset DAT_fffffff4
//                               LAB_004a4d08                                                 XREF[1]:     004a4cfc(j)
//         004a4d08     MOV        this,EBP
//         004a4d0a     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2627 (31)
//         004a4d0f     LEA        EAX,[ESP + 0x14]
//         004a4d13     MOV        this,EBP
//         004a4d15     PUSH       EAX
//                              language.dll match for 0x25ec: "Full Tech Tree: %s"
//         004a4d16     PUSH       offset DAT_fffffff8
//         004a4d1b     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4d20     LEA        this,[ESP + 0x118]
//         004a4d27     PUSH       EAX=>DAT_fffffff8
//         004a4d28     PUSH       this=>DAT_fffffff4
//         004a4d29     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2628 (26)
//         004a4d2e     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4d35     ADD        ESP,0xc
//         004a4d38     LEA        EAX,[ESP + 0x114]
//         004a4d3f     MOV        EDX,dword ptr [this->_padding_]
//         004a4d41     PUSH       EAX
//         004a4d42     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2629 (14)
//         004a4d48     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4d4f     PUSH       0x1
//         004a4d51     MOV        EDX,dword ptr [this->_padding_]
//         004a4d53     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2633 (20)
//         004a4d56     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4d5c     INC        EBX
//         004a4d5d     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a4d62     TEST       EAX,EAX
//         004a4d64     JZ         LAB_004a4df7
//                              scr_mps.cpp:2635 (15)
//         004a4d6a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4d70     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
//         004a4d75     TEST       EAX,EAX
//         004a4d77     JZ         LAB_004a4d80
//                              scr_mps.cpp:2636 (5)
//         004a4d79     PUSH       0xfa3
//                              scr_mps.cpp:2637 (2)
//         004a4d7e     JMP        LAB_004a4d85
//                              language.dll match for 0xfa4: "No"
//                               LAB_004a4d80                                                 XREF[1]:     004a4d77(j)
//                              scr_mps.cpp:2638 (47)
//         004a4d80     PUSH       0xfa4
//                               LAB_004a4d85                                                 XREF[1]:     004a4d7e(j)
//         004a4d85     MOV        this,EBP
//         004a4d87     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4d8c     MOV        EDI,EAX
//         004a4d8e     OR         this,0xffffffff
//         004a4d91     XOR        EAX,EAX
//         004a4d93     LEA        EDX,[ESP + 0x14]
//         004a4d97     SCASB.RE   ES:EDI
//         004a4d99     NOT        this
//         004a4d9b     SUB        EDI,this
//         004a4d9d     MOV        EAX,this
//         004a4d9f     MOV        ESI,EDI
//         004a4da1     MOV        EDI,EDX
//         004a4da3     SHR        this,0x2
//         004a4da6     MOVSD.REP  ES:EDI,ESI
//         004a4da8     MOV        this,EAX
//         004a4daa     AND        this,0x3
//         004a4dad     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:2639 (31)
//         004a4daf     LEA        this,[ESP + 0x14]
//         004a4db3     PUSH       this
//                              language.dll match for 0x25bb: "Enable Cheating: %s"
//         004a4db4     PUSH       offset DAT_fffffff8
//         004a4db9     MOV        this,EBP
//         004a4dbb     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4dc0     LEA        EDX,[ESP + 0x118]
//         004a4dc7     PUSH       EAX=>DAT_fffffff8
//         004a4dc8     PUSH       EDX=>DAT_fffffff4
//         004a4dc9     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2640 (26)
//         004a4dce     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4dd5     ADD        ESP,0xc
//         004a4dd8     LEA        EDX,[ESP + 0x114]
//         004a4ddf     MOV        EAX,dword ptr [this->_padding_]
//         004a4de1     PUSH       EDX
//         004a4de2     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:2641 (14)
//         004a4de8     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4def     PUSH       0x1
//         004a4df1     MOV        EAX,dword ptr [this->_padding_]
//         004a4df3     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2642 (1)
//         004a4df6     INC        EBX
//                               LAB_004a4df7                                                 XREF[1]:     004a4d64(j)
//                              scr_mps.cpp:2648 (13)
//         004a4df7     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4dfd     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a4e02     TEST       EAX,EAX
//                              scr_mps.cpp:2649 (23)
//         004a4e04     PUSH       0x100
//         004a4e09     JZ         LAB_004a4e1d
//         004a4e0b     LEA        this,[ESP + 0x18]
//         004a4e0f     PUSH       this=>DAT_fffffff8
//         004a4e10     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4e16     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
//                              scr_mps.cpp:2650 (2)
//         004a4e1b     JMP        LAB_004a4e2d
//                               LAB_004a4e1d                                                 XREF[1]:     004a4e09(j)
//                              scr_mps.cpp:2651 (34)
//         004a4e1d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4e23     LEA        EDX,[ESP + 0x18]
//         004a4e27     PUSH       EDX=>DAT_fffffff8
//         004a4e28     CALL       RGE_Base_Game::pathFinding                       uchar pathFinding(RGE_Base_Game * this)
//                               LAB_004a4e2d                                                 XREF[1]:     004a4e1b(j)
//         004a4e2d     AND        EAX,0xff
//         004a4e32     MOV        this,EBP
//         004a4e34     ADD        EAX,0x260e
//         004a4e39     PUSH       EAX=>DAT_fffffff4
//         004a4e3a     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:2652 (31)
//         004a4e3f     LEA        EAX,[ESP + 0x14]
//         004a4e43     MOV        this,EBP
//         004a4e45     PUSH       EAX
//                              language.dll match for 0x25f1: "Path Finding: %s"
//         004a4e46     PUSH       offset DAT_fffffff8
//         004a4e4b     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4e50     LEA        this,[ESP + 0x118]
//         004a4e57     PUSH       EAX=>DAT_fffffff8
//         004a4e58     PUSH       this=>DAT_fffffff4
//         004a4e59     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2653 (26)
//         004a4e5e     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4e65     ADD        ESP,0xc
//         004a4e68     LEA        EAX,[ESP + 0x114]
//         004a4e6f     MOV        EDX,dword ptr [this->_padding_]
//         004a4e71     PUSH       EAX
//         004a4e72     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2654 (14)
//         004a4e78     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4e7f     PUSH       0x1
//         004a4e81     MOV        EDX,dword ptr [this->_padding_]
//         004a4e83     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2661 (44)
//         004a4e86     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4e8c     INC        EBX
//         004a4e8d     CALL       TRIBE_Game::popLimit                             uchar popLimit(TRIBE_Game * this)
//         004a4e92     AND        EAX,0xff
//         004a4e97     MOV        this,EBP
//         004a4e99     PUSH       EAX
//                              language.dll match for 0x25f0: "Population Limit: %d"
//         004a4e9a     PUSH       offset DAT_fffffff8
//         004a4e9f     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4ea4     PUSH       EAX=>DAT_fffffff8
//         004a4ea5     LEA        EAX,[ESP + 0x11c]
//         004a4eac     PUSH       EAX=>DAT_fffffff4
//         004a4ead     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:2662 (26)
//         004a4eb2     MOV        this,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4eb9     ADD        ESP,0xc
//         004a4ebc     LEA        EAX,[ESP + 0x114]
//         004a4ec3     MOV        EDX,dword ptr [this->_padding_]
//         004a4ec5     PUSH       EAX
//         004a4ec6     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:2663 (16)
//         004a4ecc     MOV        EBX,dword ptr [EBP + EBX*0x4 + 0x62c]
//         004a4ed3     PUSH       0x1
//         004a4ed5     MOV        this,EBX
//         004a4ed7     MOV        EDX,dword ptr [EBX]
//         004a4ed9     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2668 (15)
//         004a4edc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4ee2     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a4ee7     TEST       EAX,EAX
//         004a4ee9     JZ         LAB_004a4f40
//                              scr_mps.cpp:2670 (34)
//         004a4eeb     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a4ef1     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a4ef6     TEST       EAX,EAX
//         004a4ef8     JZ         LAB_004a4f26
//         004a4efa     MOV        EAX,dword ptr [EBP + 0x84c]
//         004a4f00     TEST       EAX,EAX
//         004a4f02     JNZ        LAB_004a4f0d
//         004a4f04     CMP        dword ptr [EBP + 0x728],0x3
//         004a4f0b     JGE        LAB_004a4f26
//                               LAB_004a4f0d                                                 XREF[1]:     004a4f02(j)
//                              scr_mps.cpp:2672 (13)
//         004a4f0d     MOV        this,dword ptr [EBP + 0x6dc]
//         004a4f13     PUSH       0x0
//         004a4f15     MOV        EAX,dword ptr [this->_padding_]
//         004a4f17     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2673 (10)
//         004a4f1a     MOV        this,dword ptr [EBP + 0x6e0]
//         004a4f20     PUSH       0x0
//         004a4f22     MOV        EDX,dword ptr [this->_padding_]
//                              scr_mps.cpp:2675 (2)
//         004a4f24     JMP        LAB_004a4f3d
//                               LAB_004a4f26                                                 XREF[2]:     004a4ef8(j), 004a4f0b(j)
//                              scr_mps.cpp:2677 (13)
//         004a4f26     MOV        this,dword ptr [EBP + 0x6dc]
//         004a4f2c     PUSH       0x1
//         004a4f2e     MOV        EAX,dword ptr [this->_padding_]
//         004a4f30     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2678 (13)
//         004a4f33     MOV        this,dword ptr [EBP + 0x6e0]
//         004a4f39     PUSH       0x1
//         004a4f3b     MOV        EDX,dword ptr [this->_padding_]
//                               LAB_004a4f3d                                                 XREF[1]:     004a4f24(j)
//         004a4f3d     CALL       dword ptr [EDX + 0x14]
//                               LAB_004a4f40                                                 XREF[1]:     004a4ee9(j)
//                              scr_mps.cpp:2685 (7)
//         004a4f40     MOV        this,EBP
//         004a4f42     CALL       TribeMPSetupScreen::fillPlayers                  void fillPlayers(TribeMPSetupScreen * this)
//                              scr_mps.cpp:2686 (109)
//         004a4f47     POP        EDI
//         004a4f48     POP        ESI
//         004a4f49     POP        EBP
//         004a4f4a     POP        EBX
//         004a4f4b     ADD        ESP,0x534
//         004a4f51     RET
    return;
}

void TribeMPSetupScreen::kickPlayer(int param_1) {
    /* TODO: Stub */
//                              void __thiscall kickPlayer(TribeMPSetupScreen * this, int param_1)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004a4fc0(R)
//              char[256]         Stack[-0x104   text                      XREF[0,2]:   004a4fed(*), 004a4ffa(*)
//                               ?kickPlayer@TribeMPSetupScreen@@IAEXH@Z                      XREF[1]:     action:004a1e1b(c)
//                               TribeMPSetupScreen::kickPlayer
//                              scr_mps.cpp:2692 (13)
//         004a4fc0     MOV        EAX,dword ptr [ESP + param_1]
//         004a4fc4     SUB        ESP,0x100
//         004a4fca     PUSH       ESI
//         004a4fcb     MOV        ESI,this
//                              scr_mps.cpp:2696 (45)
//         004a4fcd     PUSH       EAX
//         004a4fce     MOV        dword ptr [ESI + 0x724],EAX
//         004a4fd4     MOV        this,dword ptr [comm]                            = 00000000
//         004a4fda     CALL       TCommunications_Handler::GetPlayerName           char * GetPlayerName(TCommunications_Handler
//         004a4fdf     PUSH       EAX
//                              language.dll match for 0x25c8: "Do you want to eject %s?"
//         004a4fe0     PUSH       0x25c8
//         004a4fe5     MOV        this,ESI
//         004a4fe7     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a4fec     PUSH       EAX
//         004a4fed     LEA        EAX=>text[4],[ESP + 0xc]
//         004a4ff1     PUSH       EAX
//         004a4ff2     CALL       sprintf                                          undefined sprintf()
//         004a4ff7     ADD        ESP,0xc
//                              scr_mps.cpp:2698 (24)
//         004a4ffa     LEA        this=>text[4],[ESP + 0x4]
//         004a4ffe     PUSH       0x64
//         004a5000     PUSH       0x1c2
//         004a5005     PUSH       s_Kick_Dialog                                    = 4Bh
//         004a500a     PUSH       this
//         004a500b     MOV        this,ESI
//         004a500d     CALL       TEasy_Panel::popupYesNoDialog                    void popupYesNoDialog(TEasy_Panel * this, cha
//                              scr_mps.cpp:2699 (10)
//         004a5012     POP        ESI
//         004a5013     ADD        ESP,0x100
//         004a5019     RET        0x4
//         004a501c     ??         90h
//         004a501d     NOP
//         004a501e     NOP
//         004a501f     NOP
    return;
}

void TribeMPSetupScreen::handleKickedPlayer(int param_1) {
    /* TODO: Stub */
//                              void __thiscall handleKickedPlayer(TribeMPSetupScreen * this, int pa
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004a5035(R)
//                               ?handleKickedPlayer@TribeMPSetupScreen@@IAEXH@Z              XREF[4]:     handle_user_command:004a34ed(c),
//                               TribeMPSetupScreen::handleKickedPlayer                                    handle_user_command:004a3529(c),
//                                                                                                         handle_user_command:004a3562(c),
//                                                                                                         handle_user_command:004a36cc(c)
//                              scr_mps.cpp:2705 (7)
//         004a5020     PUSH       0x0
//         004a5022     CALL       TribeMPSetupScreen::cancelScreen                 void cancelScreen(TribeMPSetupScreen * this,
//                              scr_mps.cpp:2708 (10)
//         004a5027     MOV        this,panel_system
//         004a502c     CALL       TPanelSystem::currentPanel                       TPanel * currentPanel(TPanelSystem * this)
//                              scr_mps.cpp:2709 (4)
//         004a5031     TEST       EAX,EAX
//         004a5033     JZ         LAB_004a5054
//                              scr_mps.cpp:2710 (31)
//         004a5035     MOV        this,dword ptr [ESP + param_1]
//         004a5039     PUSH       0x64
//         004a503b     NEG        this
//         004a503d     SBB        this,this
//         004a503f     PUSH       0x1c2
//         004a5044     ADD        this,0x25ca
//         004a504a     PUSH       0x0
//         004a504c     PUSH       this
//         004a504d     MOV        this,EAX
//         004a504f     CALL       TEasy_Panel::popupOKDialog                       void popupOKDialog(TEasy_Panel * this, long p
//                               LAB_004a5054                                                 XREF[1]:     004a5033(j)
//                              scr_mps.cpp:2711 (3)
//         004a5054     RET        0x4
//         004a5057     ??         90h
//         004a5058     NOP
//         004a5059     NOP
//         004a505a     NOP
//         004a505b     NOP
//         004a505c     NOP
//         004a505d     NOP
//         004a505e     NOP
//         004a505f     NOP
    return;
}

void TribeMPSetupScreen::activateVictoryPanels() {
    /* TODO: Stub */
//                              void __thiscall activateVictoryPanels(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//                               ?activateVictoryPanels@TribeMPSetupScreen@@IAEXXZ
//                               TribeMPSetupScreen::activateVictoryPanels
//                              scr_mps.cpp:2717 (3)
//         004a5060     PUSH       ESI
//         004a5061     MOV        ESI,this
//                              scr_mps.cpp:2719 (35)
//         004a5063     MOV        this,dword ptr [ESI + 0x6f4]
//         004a5069     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a506e     CMP        EAX,0x1
//         004a5071     JZ         LAB_004a50f9
//         004a5077     MOV        this,dword ptr [ESI + 0x6f4]
//         004a507d     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a5082     TEST       EAX,EAX
//         004a5084     JZ         LAB_004a50f9
//                              scr_mps.cpp:2726 (13)
//         004a5086     MOV        this,dword ptr [ESI + 0x6f8]
//         004a508c     PUSH       0x1
//         004a508e     MOV        EAX,dword ptr [this->_padding_]
//         004a5090     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:2727 (13)
//         004a5093     MOV        this,dword ptr [ESI + 0x6fc]
//         004a5099     PUSH       0x1
//         004a509b     MOV        EDX,dword ptr [this->_padding_]
//         004a509d     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2729 (26)
//         004a50a0     MOV        this,dword ptr [ESI + 0x6f4]
//         004a50a6     CALL       TDropDownPanel::get_id                           long get_id(TDropDownPanel * this)
//         004a50ab     ADD        EAX,-0x2
//         004a50ae     CMP        EAX,0x4
//         004a50b1     JA         switchD_004a50b3::default
//                               switchD_004a50b3::switchD
//         004a50b3     JMP        dword ptr [EAX*0x4 + switchD_004a50b3::switchd   = 004a50ba
//                               switchD_004a50b3::caseD_2                                    XREF[2]:     004a50b3(j), 004a5118(*)
//                              scr_mps.cpp:2732 (19)
//         004a50ba     MOV        this,dword ptr [ESI + 0x6f8]
//                              language.dll match for 0x25cb: "Percent"
//         004a50c0     PUSH       0x25cb
//         004a50c5     MOV        EAX,dword ptr [this->_padding_]
//         004a50c7     CALL       dword ptr [EAX + 0xe4]
//                              scr_mps.cpp:2746 (2)
//         004a50cd     POP        ESI
//         004a50ce     RET
//                               switchD_004a50b3::caseD_4                                    XREF[4]:     004a50b3(j), 004a511c(*),
//                               switchD_004a50b3::caseD_5                                                 004a5120(*), 004a5124(*)
//                               switchD_004a50b3::caseD_3
//                              scr_mps.cpp:2738 (19)
//         004a50cf     MOV        this,dword ptr [ESI + 0x6f8]
//                              language.dll match for 0x25cc: "Count"
//         004a50d5     PUSH       0x25cc
//         004a50da     MOV        EDX,dword ptr [this->_padding_]
//         004a50dc     CALL       dword ptr [EDX + 0xe4]
//                              scr_mps.cpp:2746 (2)
//         004a50e2     POP        ESI
//         004a50e3     RET
//                               switchD_004a50b3::caseD_6                                    XREF[2]:     004a50b3(j), 004a5128(*)
//                              scr_mps.cpp:2742 (19)
//         004a50e4     MOV        this,dword ptr [ESI + 0x6f8]
//                              language.dll match for 0x25cd: "Quantity"
//         004a50ea     PUSH       0x25cd
//         004a50ef     MOV        EAX,dword ptr [this->_padding_]
//         004a50f1     CALL       dword ptr [EAX + 0xe4]
//                              scr_mps.cpp:2746 (2)
//         004a50f7     POP        ESI
//         004a50f8     RET
//                               LAB_004a50f9                                                 XREF[2]:     004a5071(j), 004a5084(j)
//                              scr_mps.cpp:2721 (13)
//         004a50f9     MOV        this,dword ptr [ESI + 0x6f8]
//         004a50ff     PUSH       0x0
//         004a5101     MOV        EDX,dword ptr [this->_padding_]
//         004a5103     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2722 (13)
//         004a5106     MOV        this,dword ptr [ESI + 0x6fc]
//         004a510c     PUSH       0x0
//         004a510e     MOV        EAX,dword ptr [this->_padding_]
//         004a5110     CALL       dword ptr [EAX + 0x14]
//                               switchD_004a50b3::default                                    XREF[1]:     004a50b1(j)
//                              scr_mps.cpp:2746 (25)
//         004a5113     POP        ESI
//         004a5114     RET
    return;
}

void TribeMPSetupScreen::setupTabOrder() {
    /* TODO: Stub */
//                              void __thiscall setupTabOrder(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a51af(W)
//              TPanel *[4]       Stack[-0x14]   tabList                   XREF[0,11]:  004a515b(*), 004a515f(W), 004a518d(W), 004a51ab(*),
//                                                                                     004a51e9(*), 004a5157(W), 004a51a7(W), 004a51e5(W),
//                                                                                     004a516a(W), 004a51ba(W), 004a51ed(W)
//                               ?setupTabOrder@TribeMPSetupScreen@@IAEXXZ                    XREF[1]:     TribeMPSetupScreen:004a0ced(c)
//                               TribeMPSetupScreen::setupTabOrder
//                              scr_mps.cpp:2752 (6)
//         004a5130     SUB        ESP,0x10
//         004a5133     PUSH       ESI
//         004a5134     MOV        ESI,this
//                              scr_mps.cpp:2757 (15)
//         004a5136     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a513c     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a5141     TEST       EAX,EAX
//         004a5143     JZ         LAB_004a5187
//                              scr_mps.cpp:2760 (12)
//         004a5145     MOV        this,dword ptr [ESI + 0x70c]
//         004a514b     MOV        EAX,dword ptr [ESI + 0x700]
//                              scr_mps.cpp:2761 (10)
//         004a5151     MOV        EDX,dword ptr [ESI + 0x620]
//         004a5157     MOV        dword ptr [ESP + tabList[2]],this
//                              scr_mps.cpp:2762 (25)
//         004a515b     LEA        this=>tabList[1],[ESP + 0x4]
//         004a515f     MOV        dword ptr [ESP + tabList[1]],EAX
//         004a5163     MOV        EAX,dword ptr [ESI]
//         004a5165     PUSH       0x3
//         004a5167     PUSH       this
//         004a5168     MOV        this,ESI
//         004a516a     MOV        dword ptr [ESP + tabList[3]],EDX
//         004a516e     CALL       dword ptr [EAX + 0xc8]
//                              scr_mps.cpp:2763 (6)
//         004a5174     MOV        EDX,dword ptr [ESI + 0x700]
//                              scr_mps.cpp:2785 (8)
//         004a517a     MOV        this,ESI
//         004a517c     PUSH       EDX
//         004a517d     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_mps.cpp:2787 (5)
//         004a5182     POP        ESI
//         004a5183     ADD        ESP,0x10
//         004a5186     RET
//                               LAB_004a5187                                                 XREF[1]:     004a5143(j)
//                              scr_mps.cpp:2767 (10)
//         004a5187     MOV        EAX,dword ptr [ESI + 0x610]
//         004a518d     MOV        dword ptr [ESP + tabList[1]],EAX
//                              scr_mps.cpp:2768 (10)
//         004a5191     MOV        EAX,dword ptr [ESI + 0x620]
//         004a5197     TEST       EAX,EAX
//         004a5199     JZ         LAB_004a51d7
//                              scr_mps.cpp:2771 (6)
//         004a519b     MOV        this,dword ptr [ESI + 0x700]
//                              scr_mps.cpp:2772 (10)
//         004a51a1     MOV        EDX,dword ptr [ESI + 0x70c]
//         004a51a7     MOV        dword ptr [ESP + tabList[2]],this
//                              scr_mps.cpp:2774 (25)
//         004a51ab     LEA        this=>tabList[1],[ESP + 0x4]
//         004a51af     MOV        dword ptr [ESP + local_4],EAX
//         004a51b3     MOV        EAX,dword ptr [ESI]
//         004a51b5     PUSH       0x4
//         004a51b7     PUSH       this
//         004a51b8     MOV        this,ESI
//         004a51ba     MOV        dword ptr [ESP + tabList[3]],EDX
//         004a51be     CALL       dword ptr [EAX + 0xc8]
//                              scr_mps.cpp:2775 (6)
//         004a51c4     MOV        EDX,dword ptr [ESI + 0x610]
//                              scr_mps.cpp:2785 (8)
//         004a51ca     MOV        this,ESI
//         004a51cc     PUSH       EDX
//         004a51cd     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_mps.cpp:2787 (5)
//         004a51d2     POP        ESI
//         004a51d3     ADD        ESP,0x10
//         004a51d6     RET
//                               LAB_004a51d7                                                 XREF[1]:     004a5199(j)
//                              scr_mps.cpp:2782 (6)
//         004a51d7     MOV        EAX,dword ptr [ESI + 0x714]
//                              scr_mps.cpp:2783 (6)
//         004a51dd     MOV        this,dword ptr [ESI + 0x70c]
//                              scr_mps.cpp:2784 (25)
//         004a51e3     MOV        EDX,dword ptr [ESI]
//         004a51e5     MOV        dword ptr [ESP + tabList[2]],EAX
//         004a51e9     LEA        EAX=>tabList[1],[ESP + 0x4]
//         004a51ed     MOV        dword ptr [ESP + tabList[3]],this
//         004a51f1     PUSH       0x3
//         004a51f3     PUSH       EAX
//         004a51f4     MOV        this,ESI
//         004a51f6     CALL       dword ptr [EDX + 0xc8]
//                              scr_mps.cpp:2785 (14)
//         004a51fc     MOV        this,dword ptr [ESI + 0x610]
//         004a5202     PUSH       this
//         004a5203     MOV        this,ESI
//         004a5205     CALL       TPanel::set_curr_child                           void set_curr_child(TPanel * this, TPanel * p
//                              scr_mps.cpp:2787 (5)
//         004a520a     POP        ESI
//         004a520b     ADD        ESP,0x10
//         004a520e     RET
//         004a520f     ??         90h
    return;
}

void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    /* TODO: Stub */
//                              void __thiscall setupSinglePlayerPlayers(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004a523f(W), 004a52bf(W), 004a5387(R)
//              int               Stack[-0x8]:4  first_any_color           XREF[3]:     004a523b(W), 004a52bb(W), 004a5375(R)
//              int               Stack[-0xc]:4  first_any_civ             XREF[4]:     004a5237(W), 004a52a4(R), 004a52b2(W), 004a52c3(R)
//              int               Stack[-0x10]:4 first_any_player
//                               ?setupSinglePlayerPlayers@TribeMPSetupScreen@@IAEXXZ         XREF[2]:     TribeMPSetupScreen:004a0d1d(c),
//                               TribeMPSetupScreen::setupSinglePlayerPlayers                              updateSummary:004a44f9(c)
//                              scr_mps.cpp:2793 (8)
//         004a5210     SUB        ESP,0xc
//         004a5213     PUSH       EBX
//         004a5214     PUSH       EBP
//         004a5215     MOV        EBX,this
//         004a5217     PUSH       ESI
//                              scr_mps.cpp:2801 (20)
//         004a5218     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a521e     PUSH       EDI
//         004a521f     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a5224     TEST       EAX,EAX
//         004a5226     JZ         LAB_004a539b
//                              scr_mps.cpp:2808 (29)
//         004a522c     MOV        EAX,dword ptr [EBX + 0x848]
//         004a5232     OR         EDI,0xffffffff
//         004a5235     TEST       EAX,EAX
//         004a5237     MOV        dword ptr [ESP + first_any_civ],EDI
//         004a523b     MOV        dword ptr [ESP + first_any_color],EDI
//         004a523f     MOV        dword ptr [ESP + local_4],EDI
//         004a5243     JZ         LAB_004a52d2
//                              scr_mps.cpp:2812 (2)
//         004a5249     XOR        EBP,EBP
//                              scr_mps.cpp:2813 (2)
//         004a524b     XOR        ESI,ESI
//                               LAB_004a524d                                                 XREF[1]:     004a52cc(j)
//                              scr_mps.cpp:2815 (16)
//         004a524d     MOV        this,dword ptr [EBX + 0x848]
//         004a5253     PUSH       ESI
//         004a5254     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
//         004a5259     TEST       EAX,EAX
//         004a525b     JZ         LAB_004a52c8
//                              scr_mps.cpp:2817 (13)
//         004a525d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5263     PUSH       ESI
//         004a5264     PUSH       EBP
//         004a5265     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:2818 (25)
//         004a526a     MOV        this,dword ptr [EBX + 0x848]
//         004a5270     PUSH       ESI
//         004a5271     CALL       RGE_Scenario::Get_player_Civ                     int Get_player_Civ(RGE_Scenario * this, int p
//         004a5276     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a527c     PUSH       EAX
//         004a527d     PUSH       EBP
//         004a527e     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:2819 (16)
//         004a5283     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5289     LEA        EDI,[ESI + 0x1]
//         004a528c     PUSH       EDI
//         004a528d     PUSH       EBP
//         004a528e     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:2822 (17)
//         004a5293     MOV        this,dword ptr [EBX + 0x848]
//         004a5299     PUSH       ESI
//         004a529a     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int
//         004a529f     CMP        EAX,0x1
//         004a52a2     JNZ        LAB_004a52c3
//                              scr_mps.cpp:2824 (7)
//         004a52a4     CMP        dword ptr [ESP + first_any_civ],-0x1
//         004a52a9     JNZ        LAB_004a52c3
//                              scr_mps.cpp:2827 (20)
//         004a52ab     MOV        this,dword ptr [EBX + 0x848]
//         004a52b1     PUSH       ESI
//         004a52b2     MOV        dword ptr [ESP + first_any_civ],ESI
//         004a52b6     CALL       RGE_Scenario::Get_player_Civ                     int Get_player_Civ(RGE_Scenario * this, int p
//         004a52bb     MOV        dword ptr [ESP + first_any_color],EAX
//                              scr_mps.cpp:2828 (4)
//         004a52bf     MOV        dword ptr [ESP + local_4],EDI
//                               LAB_004a52c3                                                 XREF[2]:     004a52a2(j), 004a52a9(j)
//                              scr_mps.cpp:2832 (15)
//         004a52c3     MOV        EDI,dword ptr [ESP + first_any_civ]
//         004a52c7     INC        EBP
//                               LAB_004a52c8                                                 XREF[1]:     004a525b(j)
//         004a52c8     INC        ESI
//         004a52c9     CMP        ESI,0x9
//         004a52cc     JL         LAB_004a524d
//                               LAB_004a52d2                                                 XREF[1]:     004a5243(j)
//                              scr_mps.cpp:2837 (18)
//         004a52d2     MOV        EAX,dword ptr [EBX + 0x728]
//         004a52d8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a52de     PUSH       EAX
//         004a52df     CALL       RGE_Base_Game::setNumberPlayers                  void setNumberPlayers(RGE_Base_Game * this, i
//                              scr_mps.cpp:2842 (9)
//         004a52e4     CMP        EDI,-0x1
//         004a52e7     JZ         LAB_004a53e0
//                              scr_mps.cpp:2844 (15)
//         004a52ed     MOV        EAX,dword ptr [EBX + 0x728]
//         004a52f3     MOV        ESI,0x1
//         004a52f8     CMP        EAX,ESI
//         004a52fa     JLE        LAB_004a5367
//                               LAB_004a52fc                                                 XREF[1]:     004a5315(j)
//                              scr_mps.cpp:2846 (29)
//         004a52fc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5302     PUSH       ESI
//         004a5303     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
//         004a5308     CMP        EAX,EDI
//         004a530a     JZ         LAB_004a5319
//         004a530c     MOV        EAX,dword ptr [EBX + 0x728]
//         004a5312     INC        ESI
//         004a5313     CMP        ESI,EAX
//         004a5315     JL         LAB_004a52fc
//         004a5317     JMP        LAB_004a5367
//                               LAB_004a5319                                                 XREF[1]:     004a530a(j)
//                              scr_mps.cpp:2848 (26)
//         004a5319     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a531f     PUSH       0x0
//         004a5321     CALL       TRIBE_Game::scenarioPlayer                       int scenarioPlayer(TRIBE_Game * this, int par
//         004a5326     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a532c     PUSH       EAX
//         004a532d     PUSH       ESI
//         004a532e     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:2849 (26)
//         004a5333     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5339     PUSH       0x0
//         004a533b     CALL       TRIBE_Game::civilization                         int civilization(TRIBE_Game * this, int param
//         004a5340     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5346     PUSH       EAX
//         004a5347     PUSH       ESI
//         004a5348     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:2850 (26)
//         004a534d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5353     PUSH       0x0
//         004a5355     CALL       TRIBE_Game::playerColor                          int playerColor(TRIBE_Game * this, int param_1)
//         004a535a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5360     PUSH       EAX
//         004a5361     PUSH       ESI
//         004a5362     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                               LAB_004a5367                                                 XREF[2]:     004a52fa(j), 004a5317(j)
//                              scr_mps.cpp:2854 (14)
//         004a5367     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a536d     PUSH       EDI
//         004a536e     PUSH       0x0
//         004a5370     CALL       TRIBE_Game::setScenarioPlayer                    void setScenarioPlayer(TRIBE_Game * this, int
//                              scr_mps.cpp:2855 (18)
//         004a5375     MOV        this,dword ptr [ESP + first_any_color]
//         004a5379     PUSH       this
//         004a537a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5380     PUSH       0x0
//         004a5382     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:2856 (18)
//         004a5387     MOV        EDX,dword ptr [ESP + local_4]
//         004a538b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5391     PUSH       EDX
//         004a5392     PUSH       0x0
//         004a5394     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//                              scr_mps.cpp:2859 (2)
//         004a5399     JMP        LAB_004a53e0
//                               LAB_004a539b                                                 XREF[1]:     004a5226(j)
//                              scr_mps.cpp:2863 (2)
//         004a539b     XOR        ESI,ESI
//                               LAB_004a539d                                                 XREF[1]:     004a53de(j)
//                              scr_mps.cpp:2865 (18)
//         004a539d     PUSH       0xb31
//         004a53a2     PUSH       s_C:\msdev\work\age1_x1\scr_mps.cp               = "C:\\msdev\\work\\age1_x1\\scr_mps.cpp"
//         004a53a7     CALL       debug_rand                                       int debug_rand(char * param_1, int param_2)
//         004a53ac     CDQ
//         004a53ad     XOR        EAX,EDX
//                              scr_mps.cpp:2866 (26)
//         004a53af     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a53b5     SUB        EAX,EDX
//         004a53b7     ADD        ESP,0x8
//         004a53ba     AND        EAX,0xf
//         004a53bd     XOR        EAX,EDX
//         004a53bf     SUB        EAX,EDX
//         004a53c1     INC        EAX
//         004a53c2     PUSH       EAX
//         004a53c3     PUSH       ESI
//         004a53c4     CALL       TRIBE_Game::setCivilization                      void setCivilization(TRIBE_Game * this, int p
//                              scr_mps.cpp:2870 (23)
//         004a53c9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a53cf     LEA        EDI,[ESI + 0x1]
//         004a53d2     PUSH       EDI
//         004a53d3     PUSH       ESI
//         004a53d4     CALL       TRIBE_Game::setPlayerColor                       void setPlayerColor(TRIBE_Game * this, int pa
//         004a53d9     MOV        ESI,EDI
//         004a53db     CMP        ESI,0x8
//         004a53de     JL         LAB_004a539d
//                               LAB_004a53e0                                                 XREF[2]:     004a52e7(j), 004a5399(j)
//                              scr_mps.cpp:2874 (2)
//         004a53e0     XOR        ESI,ESI
//                               LAB_004a53e2                                                 XREF[1]:     004a53f4(j)
//                              scr_mps.cpp:2875 (20)
//         004a53e2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a53e8     PUSH       0x1
//         004a53ea     PUSH       ESI
//         004a53eb     CALL       RGE_Base_Game::setPlayerTeam                     void setPlayerTeam(RGE_Base_Game * this, int
//         004a53f0     INC        ESI
//         004a53f1     CMP        ESI,0x8
//         004a53f4     JL         LAB_004a53e2
//                              scr_mps.cpp:2879 (15)
//         004a53f6     MOV        this,dword ptr [comm]                            = 00000000
//         004a53fc     PUSH       0x2
//         004a53fe     PUSH       0x1
//         004a5400     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
//                              scr_mps.cpp:2880 (5)
//         004a5405     MOV        ESI,0x2
//                               LAB_004a540a                                                 XREF[1]:     004a541c(j)
//                              scr_mps.cpp:2881 (20)
//         004a540a     MOV        this,dword ptr [comm]                            = 00000000
//         004a5410     PUSH       0x4
//         004a5412     PUSH       ESI
//         004a5413     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
//         004a5418     INC        ESI
//         004a5419     CMP        ESI,0x8
//         004a541c     JLE        LAB_004a540a
//                              scr_mps.cpp:2883 (15)
//         004a541e     MOV        this,dword ptr [comm]                            = 00000000
//         004a5424     PUSH       0x0
//         004a5426     PUSH       0x9
//         004a5428     CALL       TCommunications_Handler::SetPlayerHumanity       void SetPlayerHumanity(TCommunications_Handle
//                              scr_mps.cpp:2885 (7)
//         004a542d     MOV        this,EBX
//         004a542f     CALL       TribeMPSetupScreen::fillNumberPlayers            void fillNumberPlayers(TribeMPSetupScreen * t
//                              scr_mps.cpp:2886 (8)
//         004a5434     POP        EDI
//         004a5435     POP        ESI
//         004a5436     POP        EBP
//         004a5437     POP        EBX
//         004a5438     ADD        ESP,0xc
//         004a543b     RET
//         004a543c     ??         90h
//         004a543d     NOP
//         004a543e     NOP
//         004a543f     NOP
    return;
}

void TribeMPSetupScreen::fillNumberPlayers() {
    /* TODO: Stub */
//                              void __thiscall fillNumberPlayers(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              char[16]          Stack[-0x14]   str                       XREF[0,2]:   004a5462(*), 004a5474(*)
//                               ?fillNumberPlayers@TribeMPSetupScreen@@IAEXXZ                XREF[1]:     setupSinglePlayerPlayers:004a542f(
//                               TribeMPSetupScreen::fillNumberPlayers
//                              scr_mps.cpp:2892 (7)
//         004a5440     SUB        ESP,0x10
//         004a5443     PUSH       ESI
//         004a5444     PUSH       EDI
//         004a5445     MOV        EDI,this
//                              scr_mps.cpp:2897 (11)
//         004a5447     MOV        this,dword ptr [EDI + 0x6e0]
//         004a544d     CALL       TDropDownPanel::empty_list                       void empty_list(TDropDownPanel * this)
//                              scr_mps.cpp:2898 (15)
//         004a5452     MOV        EAX,dword ptr [EDI + 0x728]
//         004a5458     MOV        ESI,0x2
//         004a545d     CMP        EAX,ESI
//         004a545f     JL         LAB_004a5490
//                               LAB_004a5461                                                 XREF[1]:     004a548e(j)
//                              scr_mps.cpp:2900 (19)
//         004a5461     PUSH       ESI
//         004a5462     LEA        EAX=>str[4],[ESP + 0xc]
//         004a5466     PUSH       s_%d                                             = 6425h
//         004a546b     PUSH       EAX
//         004a546c     CALL       sprintf                                          undefined sprintf()
//         004a5471     ADD        ESP,0xc
//                              scr_mps.cpp:2901 (28)
//         004a5474     LEA        this=>str[4],[ESP + 0x8]
//         004a5478     PUSH       ESI
//         004a5479     PUSH       this
//         004a547a     MOV        this,dword ptr [EDI + 0x6e0]
//         004a5480     CALL       TDropDownPanel::append_line                      int append_line(TDropDownPanel * this, char *
//         004a5485     MOV        EAX,dword ptr [EDI + 0x728]
//         004a548b     INC        ESI
//         004a548c     CMP        ESI,EAX
//         004a548e     JLE        LAB_004a5461
//                               LAB_004a5490                                                 XREF[1]:     004a545f(j)
//                              scr_mps.cpp:2903 (35)
//         004a5490     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5496     CALL       RGE_Base_Game::numberPlayers                     int numberPlayers(RGE_Base_Game * this)
//         004a549b     MOV        this,dword ptr [EDI + 0x6e0]
//         004a54a1     PUSH       EAX
//         004a54a2     CALL       TDropDownPanel::get_line                         long get_line(TDropDownPanel * this, long par
//         004a54a7     MOV        this,dword ptr [EDI + 0x6e0]
//         004a54ad     PUSH       EAX
//         004a54ae     CALL       TDropDownPanel::set_line                         void set_line(TDropDownPanel * this, long par
//                              scr_mps.cpp:2904 (6)
//         004a54b3     POP        EDI
//         004a54b4     POP        ESI
//         004a54b5     ADD        ESP,0x10
//         004a54b8     RET
//         004a54b9     ??         90h
//         004a54ba     NOP
//         004a54bb     NOP
//         004a54bc     NOP
//         004a54bd     NOP
//         004a54be     NOP
//         004a54bf     NOP
    return;
}

void TribeMPSetupScreen::fillPlayerColors() {
    /* TODO: Stub */
//                              void __thiscall fillPlayerColors(TribeMPSetupScreen * this)
//              void              <VOID>         <RETURN>
//              TribeMPSetupSc    ECX:4 (auto)   this
//              char[16]          Stack[-0x14]   str                       XREF[2,2]:   004a54c9(W), 004a55b2(R), 004a552d(*), 004a5540(*)
//              undefined4        Stack[-0x18]:4 local_18                  XREF[3]:     004a54d3(W), 004a55c9(R), 004a55d1(W)
//                               ?fillPlayerColors@TribeMPSetupScreen@@IAEXXZ                 XREF[1]:     fillPlayers:004a40e9(c)
//                               TribeMPSetupScreen::fillPlayerColors
//                              scr_mps.cpp:2910 (13)
//         004a54c0     SUB        ESP,0x18
//         004a54c3     PUSH       EBX
//         004a54c4     PUSH       EBP
//         004a54c5     MOV        EBX,this
//         004a54c7     PUSH       ESI
//         004a54c8     PUSH       EDI
//         004a54c9     MOV        dword ptr [ESP + str[0]],EBX
//                              scr_mps.cpp:2914 (14)
//         004a54cd     LEA        EDI,[EBX + 0x570]
//         004a54d3     MOV        dword ptr [ESP + local_18],0x8
//                               LAB_004a54db                                                 XREF[1]:     004a55d5(j)
//                              scr_mps.cpp:2916 (4)
//         004a54db     XOR        EBP,EBP
//         004a54dd     XOR        ESI,ESI
//                               LAB_004a54df                                                 XREF[1]:     004a55bb(j)
//                              scr_mps.cpp:2918 (25)
//         004a54df     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a54e5     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//         004a54ea     TEST       EAX,EAX
//         004a54ec     JZ         LAB_004a552a
//         004a54ee     MOV        this,dword ptr [EBX + 0x848]
//         004a54f4     TEST       this,this
//         004a54f6     JZ         LAB_004a552a
//                              scr_mps.cpp:2920 (14)
//         004a54f8     PUSH       EBP
//         004a54f9     CALL       RGE_Scenario::Get_player_Active                  int Get_player_Active(RGE_Scenario * this, in
//         004a54fe     TEST       EAX,EAX
//         004a5500     JZ         LAB_004a55b7
//                              scr_mps.cpp:2922 (36)
//         004a5506     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a550c     CALL       RGE_Base_Game::singlePlayerGame                  int singlePlayerGame(RGE_Base_Game * this)
//         004a5511     TEST       EAX,EAX
//         004a5513     JZ         LAB_004a552a
//         004a5515     MOV        this,dword ptr [EBX + 0x848]
//         004a551b     PUSH       EBP
//         004a551c     CALL       RGE_Scenario::Get_player_Type                    int Get_player_Type(RGE_Scenario * this, int
//         004a5521     CMP        EAX,0x1
//         004a5524     JNZ        LAB_004a55b7
//                               LAB_004a552a                                                 XREF[3]:     004a54ec(j), 004a54f6(j),
//                                                                                                         004a5513(j)
//                              scr_mps.cpp:2925 (22)
//         004a552a     LEA        EBX,[EBP + 0x1]
//         004a552d     LEA        EAX=>str[4],[ESP + 0x18]
//         004a5531     PUSH       EBX
//         004a5532     PUSH       s_%d                                             = 6425h
//         004a5537     PUSH       EAX
//         004a5538     CALL       sprintf                                          undefined sprintf()
//         004a553d     ADD        ESP,0xc
//                              scr_mps.cpp:2926 (13)
//         004a5540     LEA        this=>str[4],[ESP + 0x18]
//         004a5544     PUSH       this
//         004a5545     MOV        this,dword ptr [EDI]
//         004a5547     PUSH       ESI
//         004a5548     CALL       TButtonPanel::set_text                           void set_text(TButtonPanel * this, short para
//                              scr_mps.cpp:2927 (11)
//         004a554d     MOV        this,dword ptr [EDI]
//         004a554f     PUSH       0x0
//         004a5551     PUSH       EBX
//         004a5552     PUSH       ESI
//         004a5553     CALL       TButtonPanel::set_id                             void set_id(TButtonPanel * this, short param_
//                              scr_mps.cpp:2928 (12)
//         004a5558     CMP        EBP,0x7
//         004a555b     JA         switchD_004a555d::default
//                               switchD_004a555d::switchD
//         004a555d     JMP        dword ptr [EBP*0x4 + ->switchD_004a555d::caseD   = 004a5564
//                               switchD_004a555d::caseD_0                                    XREF[2]:     004a555d(j), 004a55e4(*)
//                              scr_mps.cpp:2930 (9)
//         004a5564     PUSH       0x0
//         004a5566     PUSH       0xff0000
//         004a556b     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_1                                    XREF[2]:     004a555d(j), 004a55e8(*)
//                              scr_mps.cpp:2931 (9)
//         004a556d     PUSH       0x0
//         004a556f     PUSH       0xff
//         004a5574     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_2                                    XREF[2]:     004a555d(j), 004a55ec(*)
//                              scr_mps.cpp:2932 (9)
//         004a5576     PUSH       0x0
//         004a5578     PUSH       0xffff
//         004a557d     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_3                                    XREF[2]:     004a555d(j), 004a55f0(*)
//                              scr_mps.cpp:2933 (9)
//         004a557f     PUSH       0x0
//         004a5581     PUSH       0x284673
//         004a5586     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_4                                    XREF[2]:     004a555d(j), 004a55f4(*)
//                              scr_mps.cpp:2934 (9)
//         004a5588     PUSH       0x0
//         004a558a     PUSH       0x764f0
//         004a558f     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_5                                    XREF[2]:     004a555d(j), 004a55f8(*)
//                              scr_mps.cpp:2935 (9)
//         004a5591     PUSH       0x0
//         004a5593     PUSH       0xff00
//         004a5598     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_6                                    XREF[2]:     004a555d(j), 004a55fc(*)
//                              scr_mps.cpp:2936 (9)
//         004a559a     PUSH       0x0
//         004a559c     PUSH       0xb4b4b4
//         004a55a1     JMP        LAB_004a55aa
//                               switchD_004a555d::caseD_7                                    XREF[2]:     004a555d(j), 004a5600(*)
//                              scr_mps.cpp:2937 (15)
//         004a55a3     PUSH       0x0
//         004a55a5     PUSH       0x93bf2b
//                               LAB_004a55aa                                                 XREF[7]:     004a556b(j), 004a5574(j),
//                                                                                                         004a557d(j), 004a5586(j),
//                                                                                                         004a558f(j), 004a5598(j),
//                                                                                                         004a55a1(j)
//         004a55aa     MOV        this,dword ptr [EDI]
//         004a55ac     PUSH       ESI
//         004a55ad     CALL       TButtonPanel::set_text_color                     void set_text_color(TButtonPanel * this, int
//                               switchD_004a555d::default                                    XREF[1]:     004a555b(j)
//                              scr_mps.cpp:2939 (15)
//         004a55b2     MOV        EBX,dword ptr [ESP + str[0]]
//         004a55b6     INC        ESI
//                               LAB_004a55b7                                                 XREF[2]:     004a5500(j), 004a5524(j)
//         004a55b7     INC        EBP
//         004a55b8     CMP        EBP,0x8
//         004a55bb     JL         LAB_004a54df
//                              scr_mps.cpp:2941 (26)
//         004a55c1     MOV        this,dword ptr [EDI]
//         004a55c3     PUSH       ESI
//         004a55c4     CALL       TButtonPanel::set_state_info                     void set_state_info(TButtonPanel * this, shor
//         004a55c9     MOV        EAX,dword ptr [ESP + local_18]
//         004a55cd     ADD        EDI,0x4
//         004a55d0     DEC        EAX
//         004a55d1     MOV        dword ptr [ESP + local_18],EAX
//         004a55d5     JNZ        LAB_004a54db
//                              scr_mps.cpp:2943 (41)
//         004a55db     POP        EDI
//         004a55dc     POP        ESI
//         004a55dd     POP        EBP
//         004a55de     POP        EBX
//         004a55df     ADD        ESP,0x18
//         004a55e2     RET
//         004a55e3     ??         90h
//                              Symbol Ref: No symbol: NONAME
//                               switchD_004a555d::switchdataD_004a55e4                       XREF[1]:     fillPlayerColors:004a555d(R)
//         004a55e4     addr       switchD_004a555d::caseD_0
//         004a55e8     addr       switchD_004a555d::caseD_1
//         004a55ec     addr       switchD_004a555d::caseD_2
//         004a55f0     addr       switchD_004a555d::caseD_3
//         004a55f4     addr       switchD_004a555d::caseD_4
//         004a55f8     addr       switchD_004a555d::caseD_5
//         004a55fc     addr       switchD_004a555d::caseD_6
//         004a5600     addr       switchD_004a555d::caseD_7
//         004a5604     ??         90h
//         004a5605     ??         90h
//         004a5606     ??         90h
//         004a5607     ??         90h
//         004a5608     ??         90h
//         004a5609     ??         90h
//         004a560a     ??         90h
//         004a560b     ??         90h
//         004a560c     ??         90h
//         004a560d     ??         90h
//         004a560e     ??         90h
//         004a560f     ??         90h
    return;
}

TRIBE_Screen_Wait::TRIBE_Screen_Wait() {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Screen_Wait(TRIBE_Screen_Wait * this)
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Screen_W    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a5683(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a5fb2(R)
//              char[256]         Stack[-0x110   str3
//              char[256]         Stack[-0x210   str2
//              char[256]         Stack[-0x310   str1                      XREF[1]:     004a5636(W)
//                               ??0TRIBE_Screen_Wait@@QAE@XZ                                 XREF[1]:     create_game_screen:005278d8(c)
//                               TRIBE_Screen_Wait::TRIBE_Screen_Wait
//                              scr_mps.cpp:2950 (47)
//         004a5610     PUSH       -0x1
//         004a5612     PUSH       FUN_0055f25b
//         004a5617     MOV        EAX,FS:[0x0]
//         004a561d     PUSH       EAX
//         004a561e     MOV        dword ptr FS:[0x0],ESP
//         004a5625     SUB        ESP,0x304
//         004a562b     PUSH       EBX
//         004a562c     PUSH       EBP
//         004a562d     PUSH       ESI
//         004a562e     PUSH       EDI
//         004a562f     MOV        EBX,this
//         004a5631     PUSH       s_Multiplayer_Wait_Screen                        = "Multiplayer Wait Screen"
//         004a5636     MOV        dword ptr [ESP + str1[0]],EBX
//         004a563a     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//                              scr_mps.cpp:2952 (6)
//         004a563f     LEA        EBP,[EBX + 0x478]
//                              scr_mps.cpp:2954 (14)
//         004a5645     LEA        ESI,[EBX + 0x480]
//         004a564b     XOR        EDX,EDX
//         004a564d     LEA        EDI,[EBX + 0x488]
//                              scr_mps.cpp:2961 (30)
//         004a5653     MOV        this,0x14
//         004a5658     XOR        EAX,EAX
//         004a565a     MOV        dword ptr [EBX],TRIBE_Screen_Wait::`vftable'     = 004a6030
//         004a5660     MOV        dword ptr [EBP],EDX
//         004a5663     MOV        dword ptr [EBX + 0x47c],EDX
//         004a5669     MOV        dword ptr [ESI],EDX
//         004a566b     MOV        dword ptr [EBX + 0x484],EDX
//                              scr_mps.cpp:2966 (40)
//         004a5671     PUSH       EDX
//         004a5672     STOSD.REP  ES:EDI
//         004a5674     MOV        EAX,[rge_base_game]                              = 00000000
//         004a5679     PUSH       0xc385
//         004a567e     PUSH       s_scr3                                           = 73h
//         004a5683     MOV        dword ptr [ESP + local_4],EDX
//         004a568a     MOV        this,dword ptr [EAX + 0x4c]
//         004a568d     PUSH       this
//         004a568e     MOV        this,EBX
//         004a5690     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         004a5695     TEST       EAX,EAX
//         004a5697     JNZ        LAB_004a56a8
//                              scr_mps.cpp:2968 (10)
//         004a5699     MOV        dword ptr [EBX + 0xd8],0x1
//                              scr_mps.cpp:2969 (5)
//         004a56a3     JMP        LAB_004a5fb2
//                               LAB_004a56a8                                                 XREF[1]:     004a5697(j)
//                              scr_mps.cpp:2972 (17)
//         004a56a8     PUSH       0x1e0
//         004a56ad     PUSH       0x280
//         004a56b2     MOV        this,EBX
//         004a56b4     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_mps.cpp:2975 (36)
//         004a56b9     PUSH       0x1
//         004a56bb     PUSH       0x1
//         004a56bd     PUSH       0x1
//         004a56bf     PUSH       0x4
//         004a56c1     PUSH       0x190
//         004a56c6     PUSH       0x17c
//         004a56cb     PUSH       0x28
//         004a56cd     PUSH       0x14
//         004a56cf     PUSH       s_                                               = ""
//         004a56d4     PUSH       EBP
//         004a56d5     PUSH       EBX
//         004a56d6     MOV        this,EBX
//         004a56d8     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                              scr_mps.cpp:2980 (38)
//         004a56dd     PUSH       0x0
//         004a56df     PUSH       -0x1
//         004a56e1     PUSH       -0x1
//         004a56e3     PUSH       0x0
//         004a56e5     PUSH       0x0
//         004a56e7     PUSH       0x0
//         004a56e9     PUSH       0x0
//         004a56eb     PUSH       0x0
//                              language.dll match for 0x3ea: "X"
//         004a56ed     PUSH       0x3ea
//         004a56f2     PUSH       ESI
//         004a56f3     PUSH       EBX
//         004a56f4     MOV        this,EBX
//         004a56f6     CALL       TEasy_Panel::create_button                       int create_button(TEasy_Panel * this, TPanel
//         004a56fb     TEST       EAX,EAX
//         004a56fd     JZ         LAB_004a5fb2
//                              scr_mps.cpp:2981 (9)
//         004a5703     MOV        this,dword ptr [ESI]
//         004a5705     PUSH       0x1
//         004a5707     MOV        EDX,dword ptr [this->_padding_]
//         004a5709     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:2982 (33)
//         004a570c     MOV        this,dword ptr [ESI]
//         004a570e     PUSH       0x0
//         004a5710     PUSH       0x0
//         004a5712     PUSH       0x0
//         004a5714     MOV        EAX,dword ptr [this->_padding_]
//         004a5716     PUSH       0x0
//         004a5718     PUSH       0x11
//         004a571a     PUSH       0x11
//         004a571c     PUSH       0x11
//         004a571e     PUSH       0x11
//         004a5720     PUSH       0x4
//         004a5722     PUSH       0x4
//         004a5724     PUSH       0x4
//         004a5726     PUSH       0x4
//         004a5728     PUSH       0x9
//         004a572a     CALL       dword ptr [EAX + 0x18]
//                              scr_mps.cpp:2988 (50)
//         004a572d     PUSH       0x1
//         004a572f     PUSH       0x0
//         004a5731     PUSH       0x0
//         004a5733     PUSH       0xb
//         004a5735     PUSH       0x44
//         004a5737     PUSH       0xdc
//         004a573c     PUSH       0x54
//         004a573e     PUSH       0x1a4
//         004a5743     LEA        EAX,[EBX + 0x484]
//         004a5749     PUSH       s_                                               = ""
//         004a574e     PUSH       EAX
//         004a574f     PUSH       EBX
//         004a5750     MOV        this,EBX
//         004a5752     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a5757     TEST       EAX,EAX
//         004a5759     JZ         LAB_004a5fb2
//                              scr_mps.cpp:2990 (11)
//         004a575f     MOV        ESI,0x53
//         004a5764     LEA        EDI,[EBX + 0x488]
//                               LAB_004a576a                                                 XREF[1]:     004a57a1(j)
//                              scr_mps.cpp:2992 (57)
//         004a576a     PUSH       0x0
//         004a576c     PUSH       0x0
//         004a576e     PUSH       0x0
//         004a5770     PUSH       0xb
//         004a5772     PUSH       0x14
//         004a5774     PUSH       0xdc
//         004a5779     PUSH       ESI
//         004a577a     PUSH       0x1a4
//         004a577f     PUSH       s_                                               = ""
//         004a5784     PUSH       EDI
//         004a5785     PUSH       EBX
//         004a5786     MOV        this,EBX
//         004a5788     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//         004a578d     TEST       EAX,EAX
//         004a578f     JZ         LAB_004a5fb2
//         004a5795     ADD        ESI,0x18
//         004a5798     ADD        EDI,0x4
//         004a579b     CMP        ESI,0x233
//         004a57a1     JL         LAB_004a576a
//                              scr_mps.cpp:3010 (11)
//         004a57a3     LEA        ESI,[EBX + 0x488]
//         004a57a9     MOV        EDI,0x14
//                               LAB_004a57ae                                                 XREF[1]:     004a57bb(j)
//                              scr_mps.cpp:3011 (15)
//         004a57ae     MOV        this,dword ptr [ESI]
//         004a57b0     PUSH       0x0
//         004a57b2     MOV        EDX,dword ptr [this->_padding_]
//         004a57b4     CALL       dword ptr [EDX + 0x14]
//         004a57b7     ADD        ESI,0x4
//         004a57ba     DEC        EDI
//         004a57bb     JNZ        LAB_004a57ae
//                              scr_mps.cpp:3013 (11)
//         004a57bd     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a57c3     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
//                              scr_mps.cpp:3016 (42)
//         004a57c8     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a57ce     TEST       EAX,EAX
//         004a57d0     JZ         LAB_004a5812
//         004a57d2     CALL       RGE_Base_Game::scenarioName                      char * scenarioName(RGE_Base_Game * this)
//         004a57d7     PUSH       EAX
//                              language.dll match for 0x25ed: "Scenario: %s"
//         004a57d8     PUSH       0x25ed
//         004a57dd     MOV        this,EBX
//         004a57df     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a57e4     PUSH       EAX
//         004a57e5     LEA        EAX,[ESP + 0x11c]
//         004a57ec     PUSH       EAX
//         004a57ed     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3017 (25)
//         004a57f2     MOV        this,dword ptr [EBX + 0x484]
//         004a57f8     ADD        ESP,0xc
//         004a57fb     LEA        EAX,[ESP + 0x114]
//         004a5802     MOV        EDX,dword ptr [this->_padding_]
//         004a5804     PUSH       EAX
//         004a5805     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3018 (5)
//         004a580b     MOV        EBP,0x3
//                              scr_mps.cpp:3020 (2)
//         004a5810     JMP        LAB_004a587a
//                               LAB_004a5812                                                 XREF[1]:     004a57d0(j)
//                              scr_mps.cpp:3022 (7)
//         004a5812     CALL       TRIBE_Game::deathMatch                           uchar deathMatch(TRIBE_Game * this)
//         004a5817     TEST       AL,AL
//                              scr_mps.cpp:3023 (17)
//         004a5819     PUSH       0x100
//         004a581e     JZ         LAB_004a582c
//         004a5820     LEA        this,[ESP + 0x18]
//         004a5824     PUSH       this
//         004a5825     PUSH       0x2617
//                              scr_mps.cpp:3024 (2)
//         004a582a     JMP        LAB_004a5836
//                               LAB_004a582c                                                 XREF[1]:     004a581e(j)
//                              scr_mps.cpp:3025 (17)
//         004a582c     LEA        EDX,[ESP + 0x18]
//         004a5830     PUSH       EDX
//                              language.dll match for 0x25b5: "Random Map"
//         004a5831     PUSH       0x25b5
//                               LAB_004a5836                                                 XREF[1]:     004a582a(j)
//         004a5836     MOV        this,EBX
//         004a5838     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3026 (31)
//         004a583d     LEA        EAX,[ESP + 0x14]
//         004a5841     MOV        this,EBX
//         004a5843     PUSH       EAX
//                              language.dll match for 0x25ed: "Scenario: %s"
//         004a5844     PUSH       0x25ed
//         004a5849     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a584e     LEA        this,[ESP + 0x118]
//         004a5855     PUSH       EAX
//         004a5856     PUSH       this
//         004a5857     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3027 (25)
//         004a585c     MOV        this,dword ptr [EBX + 0x484]
//         004a5862     ADD        ESP,0xc
//         004a5865     LEA        EAX,[ESP + 0x114]
//         004a586c     MOV        EDX,dword ptr [this->_padding_]
//         004a586e     PUSH       EAX
//         004a586f     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3028 (5)
//         004a5875     MOV        EBP,0x1
//                               LAB_004a587a                                                 XREF[1]:     004a5810(j)
//                              scr_mps.cpp:3031 (19)
//         004a587a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5880     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         004a5885     TEST       EAX,EAX
//         004a5887     JZ         LAB_004a5a04
//                              scr_mps.cpp:3034 (23)
//         004a588d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5893     CALL       TRIBE_Game::mapSize                              MapSize mapSize(TRIBE_Game * this)
//         004a5898     CMP        EAX,0x5
//         004a589b     JA         switchD_004a589d::default
//                               switchD_004a589d::switchD
//         004a589d     JMP        dword ptr [EAX*0x4 + switchD_004a589d::switchd   = 004a58a4
//                               switchD_004a589d::caseD_0                                    XREF[2]:     004a589d(j), 004a5fd0(*)
//                              scr_mps.cpp:3036 (7)
//         004a58a4     PUSH       0x2973
//         004a58a9     JMP        LAB_004a58cc
//                               switchD_004a589d::caseD_1                                    XREF[2]:     004a589d(j), 004a5fd4(*)
//                              scr_mps.cpp:3037 (7)
//         004a58ab     PUSH       0x2974
//         004a58b0     JMP        LAB_004a58cc
//                               switchD_004a589d::caseD_2                                    XREF[2]:     004a589d(j), 004a5fd8(*)
//                              scr_mps.cpp:3038 (7)
//         004a58b2     PUSH       0x2975
//         004a58b7     JMP        LAB_004a58cc
//                               switchD_004a589d::caseD_3                                    XREF[2]:     004a589d(j), 004a5fdc(*)
//                              scr_mps.cpp:3039 (7)
//         004a58b9     PUSH       0x2976
//         004a58be     JMP        LAB_004a58cc
//                              language.dll match for 0x2977: "Huge"
//                               switchD_004a589d::caseD_4                                    XREF[2]:     004a589d(j), 004a5fe0(*)
//                              scr_mps.cpp:3040 (7)
//         004a58c0     PUSH       0x2977
//         004a58c5     JMP        LAB_004a58cc
//                              language.dll match for 0x2978: "Gigantic"
//                               switchD_004a589d::caseD_5                                    XREF[2]:     004a589d(j), 004a5fe4(*)
//                              scr_mps.cpp:3041 (47)
//         004a58c7     PUSH       0x2978
//                               LAB_004a58cc                                                 XREF[5]:     004a58a9(j), 004a58b0(j),
//                                                                                                         004a58b7(j), 004a58be(j),
//                                                                                                         004a58c5(j)
//         004a58cc     MOV        this,EBX
//         004a58ce     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a58d3     MOV        EDI,EAX
//         004a58d5     OR         this,0xffffffff
//         004a58d8     XOR        EAX,EAX
//         004a58da     LEA        EDX,[ESP + 0x14]
//         004a58de     SCASB.RE   ES:EDI
//         004a58e0     NOT        this
//         004a58e2     SUB        EDI,this
//         004a58e4     MOV        EAX,this
//         004a58e6     MOV        ESI,EDI
//         004a58e8     MOV        EDI,EDX
//         004a58ea     SHR        this,0x2
//         004a58ed     MOVSD.REP  ES:EDI,ESI
//         004a58ef     MOV        this,EAX
//         004a58f1     AND        this,0x3
//         004a58f4     MOVSB.REP  ES:EDI,ESI
//                               switchD_004a589d::default                                    XREF[1]:     004a589b(j)
//                              scr_mps.cpp:3043 (31)
//         004a58f6     LEA        this,[ESP + 0x14]
//         004a58fa     PUSH       this
//                              language.dll match for 0x25da: "Map Size: %s"
//         004a58fb     PUSH       0x25da
//         004a5900     MOV        this,EBX
//         004a5902     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5907     LEA        EDX,[ESP + 0x118]
//         004a590e     PUSH       EAX
//         004a590f     PUSH       EDX
//         004a5910     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3044 (26)
//         004a5915     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a591c     ADD        ESP,0xc
//         004a591f     LEA        EDX,[ESP + 0x114]
//         004a5926     MOV        EAX,dword ptr [this->_padding_]
//         004a5928     PUSH       EDX
//         004a5929     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3045 (14)
//         004a592f     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5936     PUSH       0x1
//         004a5938     MOV        EAX,dword ptr [this->_padding_]
//         004a593a     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:3049 (24)
//         004a593d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5943     INC        EBP
//         004a5944     CALL       TRIBE_Game::mapType                              MapType mapType(TRIBE_Game * this)
//         004a5949     CMP        EAX,0x8
//         004a594c     JA         switchD_004a594e::default
//                               switchD_004a594e::switchD
//         004a594e     JMP        dword ptr [EAX*0x4 + switchD_004a594e::switchd   = 004a5955
//                               switchD_004a594e::caseD_0                                    XREF[2]:     004a594e(j), 004a5fe8(*)
//                              scr_mps.cpp:3051 (7)
//         004a5955     PUSH       0x296a
//         004a595a     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_1                                    XREF[2]:     004a594e(j), 004a5fec(*)
//                              scr_mps.cpp:3052 (7)
//         004a595c     PUSH       0x296b
//         004a5961     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_2                                    XREF[2]:     004a594e(j), 004a5ff0(*)
//                              scr_mps.cpp:3053 (7)
//         004a5963     PUSH       0x296c
//         004a5968     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_3                                    XREF[2]:     004a594e(j), 004a5ff4(*)
//                              scr_mps.cpp:3054 (7)
//         004a596a     PUSH       0x296d
//         004a596f     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_4                                    XREF[2]:     004a594e(j), 004a5ff8(*)
//                              scr_mps.cpp:3055 (7)
//         004a5971     PUSH       0x296e
//         004a5976     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_5                                    XREF[2]:     004a594e(j), 004a5ffc(*)
//                              scr_mps.cpp:3056 (7)
//         004a5978     PUSH       0x296f
//         004a597d     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_6                                    XREF[2]:     004a594e(j), 004a6000(*)
//                              scr_mps.cpp:3057 (7)
//         004a597f     PUSH       0x2970
//         004a5984     JMP        LAB_004a5992
//                               switchD_004a594e::caseD_7                                    XREF[2]:     004a594e(j), 004a6004(*)
//                              scr_mps.cpp:3058 (7)
//         004a5986     PUSH       0x2971
//         004a598b     JMP        LAB_004a5992
//                              language.dll match for 0x2972: "Narrows"
//                              language.dll match for 0x2972: "******* SIZE *******"
//                               switchD_004a594e::caseD_8                                    XREF[2]:     004a594e(j), 004a6008(*)
//                              scr_mps.cpp:3059 (47)
//         004a598d     PUSH       0x2972
//                               LAB_004a5992                                                 XREF[8]:     004a595a(j), 004a5961(j),
//                                                                                                         004a5968(j), 004a596f(j),
//                                                                                                         004a5976(j), 004a597d(j),
//                                                                                                         004a5984(j), 004a598b(j)
//         004a5992     MOV        this,EBX
//         004a5994     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5999     MOV        EDI,EAX
//         004a599b     OR         this,0xffffffff
//         004a599e     XOR        EAX,EAX
//         004a59a0     LEA        EDX,[ESP + 0x14]
//         004a59a4     SCASB.RE   ES:EDI
//         004a59a6     NOT        this
//         004a59a8     SUB        EDI,this
//         004a59aa     MOV        EAX,this
//         004a59ac     MOV        ESI,EDI
//         004a59ae     MOV        EDI,EDX
//         004a59b0     SHR        this,0x2
//         004a59b3     MOVSD.REP  ES:EDI,ESI
//         004a59b5     MOV        this,EAX
//         004a59b7     AND        this,0x3
//         004a59ba     MOVSB.REP  ES:EDI,ESI
//                               switchD_004a594e::default                                    XREF[1]:     004a594c(j)
//                              scr_mps.cpp:3061 (31)
//         004a59bc     LEA        this,[ESP + 0x14]
//         004a59c0     PUSH       this
//                              language.dll match for 0x25b6: "Map Type: %s"
//         004a59c1     PUSH       0x25b6
//         004a59c6     MOV        this,EBX
//         004a59c8     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a59cd     LEA        EDX,[ESP + 0x118]
//         004a59d4     PUSH       EAX
//         004a59d5     PUSH       EDX
//         004a59d6     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3062 (26)
//         004a59db     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a59e2     ADD        ESP,0xc
//         004a59e5     LEA        EDX,[ESP + 0x114]
//         004a59ec     MOV        EAX,dword ptr [this->_padding_]
//         004a59ee     PUSH       EDX
//         004a59ef     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3063 (14)
//         004a59f5     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a59fc     PUSH       0x1
//         004a59fe     MOV        EAX,dword ptr [this->_padding_]
//         004a5a00     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:3064 (1)
//         004a5a03     INC        EBP
//                               LAB_004a5a04                                                 XREF[1]:     004a5887(j)
//                              scr_mps.cpp:3082 (25)
//         004a5a04     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5a0a     INC        EBP
//         004a5a0b     CALL       TRIBE_Game::victoryType                          VictoryType victoryType(TRIBE_Game * this)
//         004a5a10     DEC        EAX
//         004a5a11     CMP        EAX,0x8
//         004a5a14     JA         switchD_004a5a16::caseD_2
//                               switchD_004a5a16::switchD
//         004a5a16     JMP        dword ptr [EAX*0x4 + switchD_004a5a16::switchd   = 004a5a1d
//                               switchD_004a5a16::caseD_1                                    XREF[2]:     004a5a16(j), 004a600c(*)
//                              scr_mps.cpp:3085 (5)
//         004a5a1d     PUSH       0x10e1
//                              scr_mps.cpp:3090 (5)
//         004a5a22     JMP        LAB_004a5aa8
//                               switchD_004a5a16::caseD_7                                    XREF[2]:     004a5a16(j), 004a6024(*)
//                              scr_mps.cpp:3093 (5)
//         004a5a27     PUSH       0x10e9
//                              scr_mps.cpp:3098 (2)
//         004a5a2c     JMP        LAB_004a5a33
//                              language.dll match for 0x10ea: "Score"
//                               switchD_004a5a16::caseD_8                                    XREF[2]:     004a5a16(j), 004a6028(*)
//                              scr_mps.cpp:3101 (47)
//         004a5a2e     PUSH       0x10ea
//                               LAB_004a5a33                                                 XREF[1]:     004a5a2c(j)
//         004a5a33     MOV        this,EBX
//         004a5a35     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5a3a     MOV        EDI,EAX
//         004a5a3c     OR         this,0xffffffff
//         004a5a3f     XOR        EAX,EAX
//         004a5a41     LEA        EDX,[ESP + 0x14]
//         004a5a45     SCASB.RE   ES:EDI
//         004a5a47     NOT        this
//         004a5a49     SUB        EDI,this
//         004a5a4b     MOV        EAX,this
//         004a5a4d     MOV        ESI,EDI
//         004a5a4f     MOV        EDI,EDX
//         004a5a51     SHR        this,0x2
//         004a5a54     MOVSD.REP  ES:EDI,ESI
//         004a5a56     MOV        this,EAX
//         004a5a58     AND        this,0x3
//         004a5a5b     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:3102 (46)
//         004a5a5d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5a63     CALL       TRIBE_Game::victoryAmount                        int victoryAmount(TRIBE_Game * this)
//         004a5a68     LEA        this,[ESP + 0x14]
//         004a5a6c     PUSH       EAX
//         004a5a6d     PUSH       this
//                              language.dll match for 0x25be: "Victory: %s (%d)"
//         004a5a6e     PUSH       0x25be
//         004a5a73     MOV        this,EBX
//         004a5a75     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5a7a     LEA        EDX,[ESP + 0x11c]
//         004a5a81     PUSH       EAX
//         004a5a82     PUSH       EDX
//         004a5a83     CALL       sprintf                                          undefined sprintf()
//         004a5a88     ADD        ESP,0x10
//                              scr_mps.cpp:3106 (2)
//         004a5a8b     JMP        LAB_004a5af4
//                               switchD_004a5a16::caseD_3                                    XREF[7]:     004a5a14(j), 004a5a16(j),
//                               switchD_004a5a16::caseD_4                                                 004a6010(*), 004a6014(*),
//                               switchD_004a5a16::caseD_5                                                 004a6018(*), 004a601c(*),
//                               switchD_004a5a16::caseD_6                                                 004a6020(*)
//                               switchD_004a5a16::caseD_2
//                              scr_mps.cpp:3117 (15)
//         004a5a8d     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5a93     CALL       RGE_Base_Game::randomGame                        int randomGame(RGE_Base_Game * this)
//         004a5a98     TEST       EAX,EAX
//         004a5a9a     JZ         LAB_004a5aa3
//                               switchD_004a5a16::caseD_9                                    XREF[2]:     004a5a16(j), 004a602c(*)
//                              scr_mps.cpp:3118 (5)
//         004a5a9c     PUSH       0x10ec
//                              scr_mps.cpp:3119 (2)
//         004a5aa1     JMP        LAB_004a5aa8
//                              language.dll match for 0x10e7: "Default"
//                               LAB_004a5aa3                                                 XREF[1]:     004a5a9a(j)
//                              scr_mps.cpp:3120 (47)
//         004a5aa3     PUSH       0x10e7
//                               LAB_004a5aa8                                                 XREF[2]:     004a5a22(j), 004a5aa1(j)
//         004a5aa8     MOV        this,EBX
//         004a5aaa     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5aaf     MOV        EDI,EAX
//         004a5ab1     OR         this,0xffffffff
//         004a5ab4     XOR        EAX,EAX
//         004a5ab6     LEA        EDX,[ESP + 0x14]
//         004a5aba     SCASB.RE   ES:EDI
//         004a5abc     NOT        this
//         004a5abe     SUB        EDI,this
//         004a5ac0     MOV        EAX,this
//         004a5ac2     MOV        ESI,EDI
//         004a5ac4     MOV        EDI,EDX
//         004a5ac6     SHR        this,0x2
//         004a5ac9     MOVSD.REP  ES:EDI,ESI
//         004a5acb     MOV        this,EAX
//         004a5acd     AND        this,0x3
//         004a5ad0     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:3121 (34)
//         004a5ad2     LEA        this,[ESP + 0x14]
//         004a5ad6     PUSH       this
//                              language.dll match for 0x25bc: "Victory: %s"
//         004a5ad7     PUSH       0x25bc
//         004a5adc     MOV        this,EBX
//         004a5ade     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5ae3     LEA        EDX,[ESP + 0x118]
//         004a5aea     PUSH       EAX
//         004a5aeb     PUSH       EDX
//         004a5aec     CALL       sprintf                                          undefined sprintf()
//         004a5af1     ADD        ESP,0xc
//                               LAB_004a5af4                                                 XREF[1]:     004a5a8b(j)
//                              scr_mps.cpp:3122 (23)
//         004a5af4     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5afb     LEA        EDX,[ESP + 0x114]
//         004a5b02     PUSH       EDX
//         004a5b03     MOV        EAX,dword ptr [this->_padding_]
//         004a5b05     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3123 (14)
//         004a5b0b     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5b12     PUSH       0x1
//         004a5b14     MOV        EAX,dword ptr [this->_padding_]
//         004a5b16     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:3129 (12)
//         004a5b19     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5b1f     INC        EBP
//         004a5b20     CALL       TRIBE_Game::startingAge                          Age startingAge(TRIBE_Game * this)
//                              scr_mps.cpp:3130 (4)
//         004a5b25     TEST       EAX,EAX
//         004a5b27     JNZ        LAB_004a5b3a
//                              scr_mps.cpp:3131 (15)
//         004a5b29     LEA        this,[ESP + 0x14]
//         004a5b2d     PUSH       0x100
//         004a5b32     PUSH       this
//         004a5b33     PUSH       0x10e7
//                              scr_mps.cpp:3132 (5)
//         004a5b38     JMP        LAB_004a5b5b
//                               LAB_004a5b3a                                                 XREF[1]:     004a5b27(j)
//         004a5b3a     CMP        EAX,0x1
//                              scr_mps.cpp:3133 (17)
//         004a5b3d     PUSH       0x100
//         004a5b42     JNZ        LAB_004a5b50
//         004a5b44     LEA        EDX,[ESP + 0x18]
//         004a5b48     PUSH       EDX
//                              language.dll match for 0x106e: "Nomad"
//         004a5b49     PUSH       0x106e
//                              scr_mps.cpp:3134 (2)
//         004a5b4e     JMP        LAB_004a5b5b
//                               LAB_004a5b50                                                 XREF[1]:     004a5b42(j)
//                              scr_mps.cpp:3135 (18)
//         004a5b50     LEA        this,[ESP + 0x18]
//         004a5b54     ADD        EAX,0x1067
//         004a5b59     PUSH       this
//         004a5b5a     PUSH       EAX
//                               LAB_004a5b5b                                                 XREF[2]:     004a5b38(j), 004a5b4e(j)
//         004a5b5b     MOV        this,EBX
//         004a5b5d     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3136 (31)
//         004a5b62     LEA        EDX,[ESP + 0x14]
//         004a5b66     MOV        this,EBX
//         004a5b68     PUSH       EDX
//                              language.dll match for 0x25e4: "Age: %s"
//         004a5b69     PUSH       0x25e4
//         004a5b6e     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5b73     PUSH       EAX
//         004a5b74     LEA        EAX,[ESP + 0x11c]
//         004a5b7b     PUSH       EAX
//         004a5b7c     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3137 (26)
//         004a5b81     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5b88     ADD        ESP,0xc
//         004a5b8b     LEA        EAX,[ESP + 0x114]
//         004a5b92     MOV        EDX,dword ptr [this->_padding_]
//         004a5b94     PUSH       EAX
//         004a5b95     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3138 (14)
//         004a5b9b     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5ba2     PUSH       0x1
//         004a5ba4     MOV        EDX,dword ptr [this->_padding_]
//         004a5ba6     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:3142 (12)
//         004a5ba9     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5baf     INC        EBP
//         004a5bb0     CALL       TRIBE_Game::resourceLevel                        ResourceLevel resourceLevel(TRIBE_Game * this)
//                              scr_mps.cpp:3143 (2)
//         004a5bb5     TEST       EAX,EAX
//                              scr_mps.cpp:3144 (17)
//         004a5bb7     PUSH       0x100
//         004a5bbc     JNZ        LAB_004a5bca
//         004a5bbe     LEA        EAX,[ESP + 0x18]
//         004a5bc2     PUSH       EAX
//                              language.dll match for 0x10e7: "Default"
//         004a5bc3     PUSH       0x10e7
//                              scr_mps.cpp:3145 (2)
//         004a5bc8     JMP        LAB_004a5bd5
//                               LAB_004a5bca                                                 XREF[1]:     004a5bbc(j)
//                              scr_mps.cpp:3146 (18)
//         004a5bca     LEA        this,[ESP + 0x18]
//         004a5bce     ADD        EAX,0x25e5
//         004a5bd3     PUSH       this
//         004a5bd4     PUSH       EAX
//                               LAB_004a5bd5                                                 XREF[1]:     004a5bc8(j)
//         004a5bd5     MOV        this,EBX
//         004a5bd7     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3147 (31)
//         004a5bdc     LEA        EDX,[ESP + 0x14]
//         004a5be0     MOV        this,EBX
//         004a5be2     PUSH       EDX
//                              language.dll match for 0x25e5: "Resources: %s"
//         004a5be3     PUSH       0x25e5
//         004a5be8     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5bed     PUSH       EAX
//         004a5bee     LEA        EAX,[ESP + 0x11c]
//         004a5bf5     PUSH       EAX
//         004a5bf6     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3148 (26)
//         004a5bfb     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5c02     ADD        ESP,0xc
//         004a5c05     LEA        EAX,[ESP + 0x114]
//         004a5c0c     MOV        EDX,dword ptr [this->_padding_]
//         004a5c0e     PUSH       EAX
//         004a5c0f     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3149 (14)
//         004a5c15     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5c1c     PUSH       0x1
//         004a5c1e     MOV        EDX,dword ptr [this->_padding_]
//         004a5c20     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:3153 (12)
//         004a5c23     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5c29     INC        EBP
//         004a5c2a     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//                              scr_mps.cpp:3154 (34)
//         004a5c2f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5c35     LEA        EAX,[ESP + 0x14]
//         004a5c39     PUSH       0x100
//         004a5c3e     PUSH       EAX
//         004a5c3f     CALL       RGE_Base_Game::difficulty                        int difficulty(RGE_Base_Game * this)
//         004a5c44     ADD        EAX,0x2bd0
//         004a5c49     MOV        this,EBX
//         004a5c4b     PUSH       EAX
//         004a5c4c     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3155 (25)
//         004a5c51     LEA        this,[ESP + 0x114]
//         004a5c58     PUSH       0x100
//         004a5c5d     PUSH       this
//                              language.dll match for 0x25e0: "Difficulty Level: %s"
//         004a5c5e     PUSH       0x25e0
//         004a5c63     MOV        this,EBX
//         004a5c65     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3156 (26)
//         004a5c6a     LEA        EDX,[ESP + 0x14]
//         004a5c6e     LEA        EAX,[ESP + 0x114]
//         004a5c75     PUSH       EDX
//         004a5c76     LEA        this,[ESP + 0x218]
//         004a5c7d     PUSH       EAX
//         004a5c7e     PUSH       this
//         004a5c7f     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3157 (26)
//         004a5c84     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5c8b     ADD        ESP,0xc
//         004a5c8e     LEA        EAX,[ESP + 0x214]
//         004a5c95     MOV        EDX,dword ptr [this->_padding_]
//         004a5c97     PUSH       EAX
//         004a5c98     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3158 (14)
//         004a5c9e     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5ca5     PUSH       0x1
//         004a5ca7     MOV        EDX,dword ptr [this->_padding_]
//         004a5ca9     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:3162 (14)
//         004a5cac     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5cb2     INC        EBP
//         004a5cb3     CALL       TRIBE_Game::randomizePositions                   int randomizePositions(TRIBE_Game * this)
//         004a5cb8     TEST       EAX,EAX
//                              scr_mps.cpp:3163 (17)
//         004a5cba     PUSH       0x100
//         004a5cbf     JZ         LAB_004a5ccd
//         004a5cc1     LEA        EAX,[ESP + 0x18]
//         004a5cc5     PUSH       EAX
//         004a5cc6     PUSH       0xfa4
//                              scr_mps.cpp:3164 (2)
//         004a5ccb     JMP        LAB_004a5cd7
//                               LAB_004a5ccd                                                 XREF[1]:     004a5cbf(j)
//                              scr_mps.cpp:3165 (17)
//         004a5ccd     LEA        this,[ESP + 0x18]
//         004a5cd1     PUSH       this
//                              language.dll match for 0xfa3: "Yes"
//         004a5cd2     PUSH       0xfa3
//                               LAB_004a5cd7                                                 XREF[1]:     004a5ccb(j)
//         004a5cd7     MOV        this,EBX
//         004a5cd9     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3166 (31)
//         004a5cde     LEA        EDX,[ESP + 0x14]
//         004a5ce2     MOV        this,EBX
//         004a5ce4     PUSH       EDX
//                              language.dll match for 0x25e9: "Fixed Positions: %s"
//         004a5ce5     PUSH       0x25e9
//         004a5cea     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5cef     PUSH       EAX
//         004a5cf0     LEA        EAX,[ESP + 0x11c]
//         004a5cf7     PUSH       EAX
//         004a5cf8     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3167 (26)
//         004a5cfd     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5d04     ADD        ESP,0xc
//         004a5d07     LEA        EAX,[ESP + 0x114]
//         004a5d0e     MOV        EDX,dword ptr [this->_padding_]
//         004a5d10     PUSH       EAX
//         004a5d11     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3168 (14)
//         004a5d17     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5d1e     PUSH       0x1
//         004a5d20     MOV        EDX,dword ptr [this->_padding_]
//         004a5d22     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:3172 (16)
//         004a5d25     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5d2b     INC        EBP
//         004a5d2c     CALL       RGE_Base_Game::fullVisibility                    int fullVisibility(RGE_Base_Game * this)
//         004a5d31     TEST       EAX,EAX
//         004a5d33     JZ         LAB_004a5d3c
//                              scr_mps.cpp:3173 (5)
//         004a5d35     PUSH       0xfa3
//                              scr_mps.cpp:3174 (2)
//         004a5d3a     JMP        LAB_004a5d41
//                              language.dll match for 0xfa4: "No"
//                               LAB_004a5d3c                                                 XREF[1]:     004a5d33(j)
//                              scr_mps.cpp:3175 (47)
//         004a5d3c     PUSH       0xfa4
//                               LAB_004a5d41                                                 XREF[1]:     004a5d3a(j)
//         004a5d41     MOV        this,EBX
//         004a5d43     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5d48     MOV        EDI,EAX
//         004a5d4a     OR         this,0xffffffff
//         004a5d4d     XOR        EAX,EAX
//         004a5d4f     LEA        EDX,[ESP + 0x14]
//         004a5d53     SCASB.RE   ES:EDI
//         004a5d55     NOT        this
//         004a5d57     SUB        EDI,this
//         004a5d59     MOV        EAX,this
//         004a5d5b     MOV        ESI,EDI
//         004a5d5d     MOV        EDI,EDX
//         004a5d5f     SHR        this,0x2
//         004a5d62     MOVSD.REP  ES:EDI,ESI
//         004a5d64     MOV        this,EAX
//         004a5d66     AND        this,0x3
//         004a5d69     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:3176 (31)
//         004a5d6b     LEA        this,[ESP + 0x14]
//         004a5d6f     PUSH       this
//                              language.dll match for 0x25b8: "Reveal Map: %s"
//         004a5d70     PUSH       0x25b8
//         004a5d75     MOV        this,EBX
//         004a5d77     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5d7c     LEA        EDX,[ESP + 0x118]
//         004a5d83     PUSH       EAX
//         004a5d84     PUSH       EDX
//         004a5d85     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3177 (26)
//         004a5d8a     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5d91     ADD        ESP,0xc
//         004a5d94     LEA        EDX,[ESP + 0x114]
//         004a5d9b     MOV        EAX,dword ptr [this->_padding_]
//         004a5d9d     PUSH       EDX
//         004a5d9e     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3178 (14)
//         004a5da4     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5dab     PUSH       0x1
//         004a5dad     MOV        EAX,dword ptr [this->_padding_]
//         004a5daf     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:3182 (14)
//         004a5db2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5db8     INC        EBP
//         004a5db9     CALL       TRIBE_Game::fullTechTree                         int fullTechTree(TRIBE_Game * this)
//         004a5dbe     TEST       EAX,EAX
//                              scr_mps.cpp:3183 (17)
//         004a5dc0     PUSH       0x100
//         004a5dc5     JZ         LAB_004a5dd3
//         004a5dc7     LEA        this,[ESP + 0x18]
//         004a5dcb     PUSH       this
//         004a5dcc     PUSH       0xfa3
//                              scr_mps.cpp:3184 (2)
//         004a5dd1     JMP        LAB_004a5ddd
//                               LAB_004a5dd3                                                 XREF[1]:     004a5dc5(j)
//                              scr_mps.cpp:3185 (17)
//         004a5dd3     LEA        EDX,[ESP + 0x18]
//         004a5dd7     PUSH       EDX
//                              language.dll match for 0xfa4: "No"
//         004a5dd8     PUSH       0xfa4
//                               LAB_004a5ddd                                                 XREF[1]:     004a5dd1(j)
//         004a5ddd     MOV        this,EBX
//         004a5ddf     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3186 (31)
//         004a5de4     LEA        EAX,[ESP + 0x14]
//         004a5de8     MOV        this,EBX
//         004a5dea     PUSH       EAX
//                              language.dll match for 0x25ec: "Full Tech Tree: %s"
//         004a5deb     PUSH       0x25ec
//         004a5df0     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5df5     LEA        this,[ESP + 0x118]
//         004a5dfc     PUSH       EAX
//         004a5dfd     PUSH       this
//         004a5dfe     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3187 (26)
//         004a5e03     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5e0a     ADD        ESP,0xc
//         004a5e0d     LEA        EAX,[ESP + 0x114]
//         004a5e14     MOV        EDX,dword ptr [this->_padding_]
//         004a5e16     PUSH       EAX
//         004a5e17     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3188 (14)
//         004a5e1d     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5e24     PUSH       0x1
//         004a5e26     MOV        EDX,dword ptr [this->_padding_]
//         004a5e28     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:3192 (20)
//         004a5e2b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5e31     INC        EBP
//         004a5e32     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a5e37     TEST       EAX,EAX
//         004a5e39     JZ         LAB_004a5ecc
//                              scr_mps.cpp:3194 (15)
//         004a5e3f     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5e45     CALL       RGE_Base_Game::allowCheatCodes                   int allowCheatCodes(RGE_Base_Game * this)
//         004a5e4a     TEST       EAX,EAX
//         004a5e4c     JZ         LAB_004a5e55
//                              scr_mps.cpp:3195 (5)
//         004a5e4e     PUSH       0xfa3
//                              scr_mps.cpp:3196 (2)
//         004a5e53     JMP        LAB_004a5e5a
//                              language.dll match for 0xfa4: "No"
//                               LAB_004a5e55                                                 XREF[1]:     004a5e4c(j)
//                              scr_mps.cpp:3197 (47)
//         004a5e55     PUSH       0xfa4
//                               LAB_004a5e5a                                                 XREF[1]:     004a5e53(j)
//         004a5e5a     MOV        this,EBX
//         004a5e5c     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5e61     MOV        EDI,EAX
//         004a5e63     OR         this,0xffffffff
//         004a5e66     XOR        EAX,EAX
//         004a5e68     LEA        EDX,[ESP + 0x14]
//         004a5e6c     SCASB.RE   ES:EDI
//         004a5e6e     NOT        this
//         004a5e70     SUB        EDI,this
//         004a5e72     MOV        EAX,this
//         004a5e74     MOV        ESI,EDI
//         004a5e76     MOV        EDI,EDX
//         004a5e78     SHR        this,0x2
//         004a5e7b     MOVSD.REP  ES:EDI,ESI
//         004a5e7d     MOV        this,EAX
//         004a5e7f     AND        this,0x3
//         004a5e82     MOVSB.REP  ES:EDI,ESI
//                              scr_mps.cpp:3198 (31)
//         004a5e84     LEA        this,[ESP + 0x14]
//         004a5e88     PUSH       this
//                              language.dll match for 0x25bb: "Enable Cheating: %s"
//         004a5e89     PUSH       0x25bb
//         004a5e8e     MOV        this,EBX
//         004a5e90     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5e95     LEA        EDX,[ESP + 0x118]
//         004a5e9c     PUSH       EAX
//         004a5e9d     PUSH       EDX
//         004a5e9e     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3199 (26)
//         004a5ea3     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5eaa     ADD        ESP,0xc
//         004a5ead     LEA        EDX,[ESP + 0x114]
//         004a5eb4     MOV        EAX,dword ptr [this->_padding_]
//         004a5eb6     PUSH       EDX
//         004a5eb7     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3200 (14)
//         004a5ebd     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5ec4     PUSH       0x1
//         004a5ec6     MOV        EAX,dword ptr [this->_padding_]
//         004a5ec8     CALL       dword ptr [EAX + 0x14]
//                              scr_mps.cpp:3201 (1)
//         004a5ecb     INC        EBP
//                               LAB_004a5ecc                                                 XREF[1]:     004a5e39(j)
//                              scr_mps.cpp:3207 (13)
//         004a5ecc     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5ed2     CALL       RGE_Base_Game::multiplayerGame                   int multiplayerGame(RGE_Base_Game * this)
//         004a5ed7     TEST       EAX,EAX
//                              scr_mps.cpp:3208 (23)
//         004a5ed9     PUSH       0x100
//         004a5ede     JZ         LAB_004a5ef2
//         004a5ee0     LEA        this,[ESP + 0x18]
//         004a5ee4     PUSH       this
//         004a5ee5     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5eeb     CALL       RGE_Base_Game::mpPathFinding                     uchar mpPathFinding(RGE_Base_Game * this)
//                              scr_mps.cpp:3209 (2)
//         004a5ef0     JMP        LAB_004a5f02
//                               LAB_004a5ef2                                                 XREF[1]:     004a5ede(j)
//                              scr_mps.cpp:3210 (34)
//         004a5ef2     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5ef8     LEA        EDX,[ESP + 0x18]
//         004a5efc     PUSH       EDX
//         004a5efd     CALL       RGE_Base_Game::pathFinding                       uchar pathFinding(RGE_Base_Game * this)
//                               LAB_004a5f02                                                 XREF[1]:     004a5ef0(j)
//         004a5f02     AND        EAX,0xff
//         004a5f07     MOV        this,EBX
//         004a5f09     ADD        EAX,0x260e
//         004a5f0e     PUSH       EAX
//         004a5f0f     CALL       TPanel::get_string                               int get_string(TPanel * this, int param_1, ch
//                              scr_mps.cpp:3211 (31)
//         004a5f14     LEA        EAX,[ESP + 0x14]
//         004a5f18     MOV        this,EBX
//         004a5f1a     PUSH       EAX
//                              language.dll match for 0x25f1: "Path Finding: %s"
//         004a5f1b     PUSH       0x25f1
//         004a5f20     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5f25     LEA        this,[ESP + 0x118]
//         004a5f2c     PUSH       EAX
//         004a5f2d     PUSH       this
//         004a5f2e     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3212 (26)
//         004a5f33     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5f3a     ADD        ESP,0xc
//         004a5f3d     LEA        EAX,[ESP + 0x114]
//         004a5f44     MOV        EDX,dword ptr [this->_padding_]
//         004a5f46     PUSH       EAX
//         004a5f47     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3213 (14)
//         004a5f4d     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5f54     PUSH       0x1
//         004a5f56     MOV        EDX,dword ptr [this->_padding_]
//         004a5f58     CALL       dword ptr [EDX + 0x14]
//                              scr_mps.cpp:3220 (44)
//         004a5f5b     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a5f61     INC        EBP
//         004a5f62     CALL       TRIBE_Game::popLimit                             uchar popLimit(TRIBE_Game * this)
//         004a5f67     AND        EAX,0xff
//         004a5f6c     MOV        this,EBX
//         004a5f6e     PUSH       EAX
//                              language.dll match for 0x25f0: "Population Limit: %d"
//         004a5f6f     PUSH       0x25f0
//         004a5f74     CALL       TPanel::get_string                               char * get_string(TPanel * this, int param_1)
//         004a5f79     PUSH       EAX
//         004a5f7a     LEA        EAX,[ESP + 0x11c]
//         004a5f81     PUSH       EAX
//         004a5f82     CALL       sprintf                                          undefined sprintf()
//                              scr_mps.cpp:3221 (26)
//         004a5f87     MOV        this,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5f8e     ADD        ESP,0xc
//         004a5f91     LEA        EAX,[ESP + 0x114]
//         004a5f98     MOV        EDX,dword ptr [this->_padding_]
//         004a5f9a     PUSH       EAX
//         004a5f9b     CALL       dword ptr [EDX + 0xe8]
//                              scr_mps.cpp:3222 (17)
//         004a5fa1     MOV        EBP,dword ptr [EBX + EBP*0x4 + 0x488]
//         004a5fa8     PUSH       0x1
//         004a5faa     MOV        this,EBP
//         004a5fac     MOV        EDX,dword ptr [EBP]
//         004a5faf     CALL       dword ptr [EDX + 0x14]
//                               LAB_004a5fb2                                                 XREF[4]:     004a56a3(j), 004a56fd(j),
//                                                                                                         004a5759(j), 004a578f(j)
//                              scr_mps.cpp:3225 (126)
//         004a5fb2     MOV        this,dword ptr [ESP + local_c]
//         004a5fb9     POP        EDI
//         004a5fba     POP        ESI
//         004a5fbb     MOV        EAX,EBX
//         004a5fbd     POP        EBP
//         004a5fbe     MOV        dword ptr FS:[0x0],this
//         004a5fc5     POP        EBX
//         004a5fc6     ADD        ESP,0x310
//         004a5fcc     RET
}

TRIBE_Screen_Wait::~TRIBE_Screen_Wait() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Screen_Wait(TRIBE_Screen_Wait * this)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_W    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a607b(W), 004a60c0(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a60cd(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a606b(W)
//                               ??1TRIBE_Screen_Wait@@UAE@XZ                                 XREF[1]:     `scalar_deleting_destructor':004a6
//                               TRIBE_Screen_Wait::~TRIBE_Screen_Wait
//                              scr_mps.cpp:3231 (37)
//         004a6050     PUSH       -0x1
//         004a6052     PUSH       FUN_0055f278
//         004a6057     MOV        EAX,FS:[0x0]
//         004a605d     PUSH       EAX
//         004a605e     MOV        dword ptr FS:[0x0],ESP
//         004a6065     PUSH       this
//         004a6066     PUSH       EBX
//         004a6067     PUSH       ESI
//         004a6068     MOV        ESI,this
//         004a606a     PUSH       EDI
//         004a606b     MOV        dword ptr [ESP + local_10],ESI
//         004a606f     MOV        dword ptr [ESI],TRIBE_Screen_Wait::`vftable'     = 004a6030
//                              scr_mps.cpp:3232 (20)
//         004a6075     LEA        EAX,[ESI + 0x478]
//         004a607b     MOV        dword ptr [ESP + local_4],0x0
//         004a6083     PUSH       EAX
//         004a6084     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:3234 (14)
//         004a6089     LEA        this,[ESI + 0x480]
//         004a608f     PUSH       this
//         004a6090     MOV        this,ESI
//         004a6092     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//                              scr_mps.cpp:3236 (25)
//         004a6097     LEA        EDX,[ESI + 0x484]
//         004a609d     MOV        this,ESI
//         004a609f     PUSH       EDX
//         004a60a0     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a60a5     LEA        EDI,[ESI + 0x488]
//         004a60ab     MOV        EBX,0x14
//                               LAB_004a60b0                                                 XREF[1]:     004a60bc(j)
//                              scr_mps.cpp:3241 (16)
//         004a60b0     PUSH       EDI
//         004a60b1     MOV        this,ESI
//         004a60b3     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a60b8     ADD        EDI,0x4
//         004a60bb     DEC        EBX
//         004a60bc     JNZ        LAB_004a60b0
//         004a60be     MOV        this,ESI
//                              scr_mps.cpp:3245 (31)
//         004a60c0     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a60c8     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         004a60cd     MOV        this,dword ptr [ESP + local_c]
//         004a60d1     POP        EDI
//         004a60d2     POP        ESI
//         004a60d3     MOV        dword ptr FS:[0x0],this
//         004a60da     POP        EBX
//         004a60db     ADD        ESP,0x10
//         004a60de     RET
//         004a60df     ??         90h
}

void TRIBE_Screen_Wait::set_text(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Wait * this, char * param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_W    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004a60e6(R)
//                               ?set_text@TRIBE_Screen_Wait@@QAEXPAD@Z                       XREF[1]:     handle_idle:005298f9(c)
//                               TRIBE_Screen_Wait::set_text
//                              scr_mps.cpp:3251 (19)
//         004a60e0     MOV        this,dword ptr [ECX + this->message]
//         004a60e6     MOV        EDX,dword ptr [ESP + param_1]
//         004a60ea     PUSH       EDX
//         004a60eb     MOV        EAX,dword ptr [this->_padding_]
//         004a60ed     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3253 (3)
//         004a60f3     RET        0x4
//         004a60f6     ??         90h
//         004a60f7     NOP
//         004a60f8     NOP
//         004a60f9     NOP
//         004a60fa     NOP
//         004a60fb     NOP
//         004a60fc     NOP
//         004a60fd     NOP
//         004a60fe     NOP
//         004a60ff     NOP
    return;
}

void TRIBE_Screen_Wait::set_text(long param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Wait * this, long param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_W    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004a6106(R)
//                               ?set_text@TRIBE_Screen_Wait@@QAEXJ@Z                         XREF[1]:     create_game_screen:005278f4(c)
//                               TRIBE_Screen_Wait::set_text
//                              scr_mps.cpp:3259 (19)
//         004a6100     MOV        this,dword ptr [ECX + this->message]
//         004a6106     MOV        EDX,dword ptr [ESP + param_1]
//         004a610a     PUSH       EDX
//         004a610b     MOV        EAX,dword ptr [this->_padding_]
//         004a610d     CALL       dword ptr [EAX + 0xe4]
//                              scr_mps.cpp:3261 (3)
//         004a6113     RET        0x4
//         004a6116     ??         90h
//         004a6117     NOP
//         004a6118     NOP
//         004a6119     NOP
//         004a611a     NOP
//         004a611b     NOP
//         004a611c     NOP
//         004a611d     NOP
//         004a611e     NOP
//         004a611f     NOP
    return;
}

long TRIBE_Screen_Wait::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TRIBE_Screen_Wait * this, TPanel * param_1, l
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_W    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a6120(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004a6124(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004a6153(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004a614e(R)
//                               ?action@TRIBE_Screen_Wait@@UAEJPAVTPanel@@JKK@Z              XREF[1]:     005734a4(*)
//                               TRIBE_Screen_Wait::action
//                              scr_mps.cpp:3267 (13)
//         004a6120     MOV        EAX,dword ptr [ESP + param_1]
//         004a6124     MOV        EDX,dword ptr [ESP + param_2]
//         004a6128     TEST       EAX,EAX
//         004a612a     PUSH       ESI
//         004a612b     JZ         LAB_004a614e
//                              scr_mps.cpp:3278 (13)
//         004a612d     CMP        EAX,dword ptr [ECX + this->close_button]
//         004a6133     JNZ        LAB_004a614e
//         004a6135     CMP        EDX,0x1
//         004a6138     JNZ        LAB_004a614e
//                              scr_mps.cpp:3280 (11)
//         004a613a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a6140     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              scr_mps.cpp:3281 (5)
//         004a6145     MOV        EAX,0x1
//                              scr_mps.cpp:3286 (4)
//         004a614a     POP        ESI
//         004a614b     RET        0x10
//                               LAB_004a614e                                                 XREF[3]:     004a612b(j), 004a6133(j),
//                                                                                                         004a6138(j)
//                              scr_mps.cpp:3285 (17)
//         004a614e     MOV        ESI,dword ptr [ESP + param_4]
//         004a6152     PUSH       ESI
//         004a6153     MOV        ESI,dword ptr [ESP + param_3]
//         004a6157     PUSH       ESI
//         004a6158     PUSH       EDX
//         004a6159     PUSH       EAX
//         004a615a     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              scr_mps.cpp:3286 (4)
//         004a615f     POP        ESI
//         004a6160     RET        0x10
//         004a6163     ??         90h
//         004a6164     NOP
//         004a6165     NOP
//         004a6166     NOP
//         004a6167     NOP
//         004a6168     NOP
//         004a6169     NOP
//         004a616a     NOP
//         004a616b     NOP
//         004a616c     NOP
//         004a616d     NOP
//         004a616e     NOP
//         004a616f     NOP
    return 0;
}

long TRIBE_Screen_Wait::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TRIBE_Screen_Wait * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_W    ECX:4 (auto)   this
//                               ?handle_idle@TRIBE_Screen_Wait@@UAEJXZ                       XREF[1]:     0057343c(*)
//                               TRIBE_Screen_Wait::handle_idle
//                              scr_mps.cpp:3292 (3)
//         004a6170     PUSH       ESI
//         004a6171     MOV        ESI,this
//                              scr_mps.cpp:3293 (16)
//         004a6173     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a6179     MOV        EAX,dword ptr [ECX + this->_padding_]
//         004a617f     TEST       EAX,EAX
//         004a6181     JNZ        LAB_004a6188
//                              scr_mps.cpp:3294 (5)
//         004a6183     CALL       RGE_Base_Game::enable_input                      void enable_input(RGE_Base_Game * this)
//                               LAB_004a6188                                                 XREF[1]:     004a6181(j)
//                              scr_mps.cpp:3295 (7)
//         004a6188     MOV        this,ESI
//         004a618a     CALL       TPanel::handle_idle                              long handle_idle(TPanel * this)
//                              scr_mps.cpp:3296 (2)
//         004a618f     POP        ESI
//         004a6190     RET
//         004a6191     ??         90h
//         004a6192     NOP
//         004a6193     NOP
//         004a6194     NOP
//         004a6195     NOP
//         004a6196     NOP
//         004a6197     NOP
//         004a6198     NOP
//         004a6199     NOP
//         004a619a     NOP
//         004a619b     NOP
//         004a619c     NOP
//         004a619d     NOP
//         004a619e     NOP
//         004a619f     NOP
    return 0;
}

TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(int param_1) {
    /* TODO: Stub */
//                              undefined __thiscall TRIBE_Screen_Disconnect(TRIBE_Screen_Disconnect
//              undefined         <UNASSIGNED>   <RETURN>
//              TRIBE_Screen_D    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1                   XREF[1]:     004a61c8(R)
//              undefined4        Stack[-0x4]:4  local_4                   XREF[1]:     004a61f4(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a6253(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a61bf(W)
//                               ??0TRIBE_Screen_Disconnect@@QAE@H@Z
//                               TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect
//                              scr_mps.cpp:3304 (40)
//         004a61a0     PUSH       -0x1
//         004a61a2     PUSH       FUN_0055f298
//         004a61a7     MOV        EAX,FS:[0x0]
//         004a61ad     PUSH       EAX
//         004a61ae     MOV        dword ptr FS:[0x0],ESP
//         004a61b5     PUSH       this
//         004a61b6     PUSH       ESI
//         004a61b7     PUSH       EDI
//         004a61b8     MOV        ESI,this
//         004a61ba     PUSH       s_Multiplayer_Disconnect_Screen                  = "Multiplayer Disconnect Screen"
//         004a61bf     MOV        dword ptr [ESP + local_10],ESI
//         004a61c3     CALL       TScreenPanel::TScreenPanel                       undefined TScreenPanel(TScreenPanel * this, c
//                              scr_mps.cpp:3306 (4)
//         004a61c8     MOV        this,dword ptr [ESP + param_1]
//                              scr_mps.cpp:3307 (22)
//         004a61cc     LEA        EDI,[ESI + 0x47c]
//         004a61d2     XOR        EAX,EAX
//         004a61d4     MOV        dword ptr [ESI],TRIBE_Screen_Disconnect::`vfta   = 004a6270
//         004a61da     MOV        dword ptr [ESI + 0x478],this
//         004a61e0     MOV        dword ptr [EDI],EAX
//                              scr_mps.cpp:3308 (6)
//         004a61e2     MOV        dword ptr [ESI + 0x480],EAX
//                              scr_mps.cpp:3309 (6)
//         004a61e8     MOV        dword ptr [ESI + 0x484],EAX
//                              scr_mps.cpp:3312 (36)
//         004a61ee     MOV        EDX,dword ptr [rge_base_game]                    = 00000000
//         004a61f4     MOV        dword ptr [ESP + local_4],EAX
//         004a61f8     PUSH       EAX
//         004a61f9     PUSH       0xc385
//         004a61fe     MOV        EAX,dword ptr [EDX + 0x4c]
//         004a6201     PUSH       s_scr3                                           = 73h
//         004a6206     PUSH       EAX
//         004a6207     MOV        this,ESI
//         004a6209     CALL       TScreenPanel::setup                              long setup(TScreenPanel * this, TDrawArea * p
//         004a620e     TEST       EAX,EAX
//         004a6210     JNZ        LAB_004a621e
//                              scr_mps.cpp:3314 (10)
//         004a6212     MOV        dword ptr [ESI + 0xd8],0x1
//                              scr_mps.cpp:3315 (2)
//         004a621c     JMP        LAB_004a6253
//                               LAB_004a621e                                                 XREF[1]:     004a6210(j)
//                              scr_mps.cpp:3318 (17)
//         004a621e     PUSH       0x1e0
//         004a6223     PUSH       0x280
//         004a6228     MOV        this,ESI
//         004a622a     CALL       TEasy_Panel::set_ideal_size                      void set_ideal_size(TEasy_Panel * this, long
//                              scr_mps.cpp:3321 (36)
//         004a622f     PUSH       0x1
//         004a6231     PUSH       0x1
//         004a6233     PUSH       0x1
//         004a6235     PUSH       0x4
//         004a6237     PUSH       0x190
//         004a623c     PUSH       0x230
//         004a6241     PUSH       0x28
//         004a6243     PUSH       0x28
//                              language.dll match for 0x4c0: "Disconnecting from multiplayer
//         004a6245     PUSH       0x4c0
//         004a624a     PUSH       EDI
//         004a624b     PUSH       ESI
//         004a624c     MOV        this,ESI
//         004a624e     CALL       TEasy_Panel::create_text                         int create_text(TEasy_Panel * this, TPanel *
//                               LAB_004a6253                                                 XREF[1]:     004a621c(j)
//                              scr_mps.cpp:3331 (21)
//         004a6253     MOV        this,dword ptr [ESP + local_c]
//         004a6257     MOV        EAX,ESI
//         004a6259     POP        EDI
//         004a625a     MOV        dword ptr FS:[0x0],this
//         004a6261     POP        ESI
//         004a6262     ADD        ESP,0x10
//         004a6265     RET        0x4
//         004a6268     ??         90h
//         004a6269     NOP
//         004a626a     NOP
//         004a626b     NOP
//         004a626c     NOP
//         004a626d     NOP
//         004a626e     NOP
//         004a626f     NOP
}

TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect() {
    /* TODO: Stub */
//                              void __thiscall ~TRIBE_Screen_Disconnect(TRIBE_Screen_Disconnect * t
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_D    ECX:4 (auto)   this
//              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004a62b9(W), 004a62c9(W)
//              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004a62d6(R)
//              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004a62a9(W)
//                               ??1TRIBE_Screen_Disconnect@@UAE@XZ                           XREF[1]:     `vector_deleting_destructor':004a6
//                               TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect
//                              scr_mps.cpp:3337 (35)
//         004a6290     PUSH       -0x1
//         004a6292     PUSH       FUN_0055f2b8
//         004a6297     MOV        EAX,FS:[0x0]
//         004a629d     PUSH       EAX
//         004a629e     MOV        dword ptr FS:[0x0],ESP
//         004a62a5     PUSH       this
//         004a62a6     PUSH       ESI
//         004a62a7     MOV        ESI,this
//         004a62a9     MOV        dword ptr [ESP + local_10],ESI
//         004a62ad     MOV        dword ptr [ESI],TRIBE_Screen_Disconnect::`vfta   = 004a6270
//                              scr_mps.cpp:3338 (22)
//         004a62b3     LEA        EAX,[ESI + 0x47c]
//         004a62b9     MOV        dword ptr [ESP + local_4],0x0
//         004a62c1     PUSH       EAX
//         004a62c2     CALL       TPanel::delete_panel                             void delete_panel(TPanel * this, TPanel * * p
//         004a62c7     MOV        this,ESI
//                              scr_mps.cpp:3341 (29)
//         004a62c9     MOV        dword ptr [ESP + local_4],0xffffffff
//         004a62d1     CALL       TScreenPanel::~TScreenPanel                      void ~TScreenPanel(TScreenPanel * this)
//         004a62d6     MOV        this,dword ptr [ESP + local_c]
//         004a62da     POP        ESI
//         004a62db     MOV        dword ptr FS:[0x0],this
//         004a62e2     ADD        ESP,0x10
//         004a62e5     RET
//         004a62e6     ??         90h
//         004a62e7     NOP
//         004a62e8     NOP
//         004a62e9     NOP
//         004a62ea     NOP
//         004a62eb     NOP
//         004a62ec     NOP
//         004a62ed     NOP
//         004a62ee     NOP
//         004a62ef     NOP
}

void TRIBE_Screen_Disconnect::set_text(char* param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Disconnect * this, char * para
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_D    ECX:4 (auto)   this
//              char *            Stack[0x4]:4   param_1                   XREF[1]:     004a62f6(R)
//                               ?set_text@TRIBE_Screen_Disconnect@@QAEXPAD@Z
//                               TRIBE_Screen_Disconnect::set_text
//                              scr_mps.cpp:3347 (19)
//         004a62f0     MOV        this,dword ptr [ECX + this->message]
//         004a62f6     MOV        EDX,dword ptr [ESP + param_1]
//         004a62fa     PUSH       EDX
//         004a62fb     MOV        EAX,dword ptr [this->_padding_]
//         004a62fd     CALL       dword ptr [EAX + 0xe8]
//                              scr_mps.cpp:3349 (3)
//         004a6303     RET        0x4
//         004a6306     ??         90h
//         004a6307     NOP
//         004a6308     NOP
//         004a6309     NOP
//         004a630a     NOP
//         004a630b     NOP
//         004a630c     NOP
//         004a630d     NOP
//         004a630e     NOP
//         004a630f     NOP
    return;
}

void TRIBE_Screen_Disconnect::set_text(long param_1) {
    /* TODO: Stub */
//                              void __thiscall set_text(TRIBE_Screen_Disconnect * this, long param_1)
//              void              <VOID>         <RETURN>
//              TRIBE_Screen_D    ECX:4 (auto)   this
//              long              Stack[0x4]:4   param_1                   XREF[1]:     004a6316(R)
//                               ?set_text@TRIBE_Screen_Disconnect@@QAEXJ@Z
//                               TRIBE_Screen_Disconnect::set_text
//                              scr_mps.cpp:3355 (19)
//         004a6310     MOV        this,dword ptr [ECX + this->message]
//         004a6316     MOV        EDX,dword ptr [ESP + param_1]
//         004a631a     PUSH       EDX
//         004a631b     MOV        EAX,dword ptr [this->_padding_]
//         004a631d     CALL       dword ptr [EAX + 0xe4]
//                              scr_mps.cpp:3357 (3)
//         004a6323     RET        0x4
//         004a6326     ??         90h
//         004a6327     NOP
//         004a6328     NOP
//         004a6329     NOP
//         004a632a     NOP
//         004a632b     NOP
//         004a632c     NOP
//         004a632d     NOP
//         004a632e     NOP
//         004a632f     NOP
    return;
}

long TRIBE_Screen_Disconnect::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    /* TODO: Stub */
//                              long __thiscall action(TRIBE_Screen_Disconnect * this, TPanel * para
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_D    ECX:4 (auto)   this
//              TPanel *          Stack[0x4]:4   param_1                   XREF[1]:     004a6330(R)
//              long              Stack[0x8]:4   param_2                   XREF[1]:     004a6334(R)
//              ulong             Stack[0xc]:4   param_3                   XREF[1]:     004a63a2(R)
//              ulong             Stack[0x10]:4  param_4                   XREF[1]:     004a639d(R)
//                               ?action@TRIBE_Screen_Disconnect@@UAEJPAVTPanel@@JKK@Z        XREF[1]:     005735cc(*)
//                               TRIBE_Screen_Disconnect::action
//                              scr_mps.cpp:3363 (13)
//         004a6330     MOV        EAX,dword ptr [ESP + param_1]
//         004a6334     MOV        EDX,dword ptr [ESP + param_2]
//         004a6338     TEST       EAX,EAX
//         004a633a     PUSH       ESI
//         004a633b     JZ         LAB_004a639d
//                              scr_mps.cpp:3366 (13)
//         004a633d     CMP        EAX,dword ptr [ECX + this->cancel_button]
//         004a6343     JNZ        LAB_004a637c
//         004a6345     CMP        EDX,0x1
//         004a6348     JNZ        LAB_004a637c
//                              scr_mps.cpp:3368 (11)
//         004a634a     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a6350     CALL       TRIBE_Game::quit_game                            void quit_game(TRIBE_Game * this)
//                              scr_mps.cpp:3369 (15)
//         004a6355     PUSH       s_Multiplayer_Disconnect_Screen                  = "Multiplayer Disconnect Screen"
//         004a635a     MOV        this,panel_system
//         004a635f     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:3370 (15)
//         004a6364     PUSH       s_Status_Screen                                  = "Status Screen"
//         004a6369     MOV        this,panel_system
//         004a636e     CALL       TPanelSystem::destroyPanel                       int destroyPanel(TPanelSystem * this, char *
//                              scr_mps.cpp:3371 (5)
//         004a6373     MOV        EAX,0x1
//                              scr_mps.cpp:3382 (4)
//         004a6378     POP        ESI
//         004a6379     RET        0x10
//                               LAB_004a637c                                                 XREF[2]:     004a6343(j), 004a6348(j)
//                              scr_mps.cpp:3374 (13)
//         004a637c     CMP        EAX,dword ptr [ECX + this->close_button]
//         004a6382     JNZ        LAB_004a639d
//         004a6384     CMP        EDX,0x1
//         004a6387     JNZ        LAB_004a639d
//                              scr_mps.cpp:3376 (11)
//         004a6389     MOV        this,dword ptr [rge_base_game]                   = 00000000
//         004a638f     CALL       RGE_Base_Game::close                             void close(RGE_Base_Game * this)
//                              scr_mps.cpp:3377 (5)
//         004a6394     MOV        EAX,0x1
//                              scr_mps.cpp:3382 (4)
//         004a6399     POP        ESI
//         004a639a     RET        0x10
//                               LAB_004a639d                                                 XREF[3]:     004a633b(j), 004a6382(j),
//                                                                                                         004a6387(j)
//                              scr_mps.cpp:3381 (17)
//         004a639d     MOV        ESI,dword ptr [ESP + param_4]
//         004a63a1     PUSH       ESI
//         004a63a2     MOV        ESI,dword ptr [ESP + param_3]
//         004a63a6     PUSH       ESI
//         004a63a7     PUSH       EDX
//         004a63a8     PUSH       EAX
//         004a63a9     CALL       TEasy_Panel::action                              long action(TEasy_Panel * this, TPanel * para
//                              scr_mps.cpp:3382 (4)
//         004a63ae     POP        ESI
//         004a63af     RET        0x10
//         004a63b2     ??         90h
//         004a63b3     NOP
//         004a63b4     NOP
//         004a63b5     NOP
//         004a63b6     NOP
//         004a63b7     NOP
//         004a63b8     NOP
//         004a63b9     NOP
//         004a63ba     NOP
//         004a63bb     NOP
//         004a63bc     NOP
//         004a63bd     NOP
//         004a63be     NOP
//         004a63bf     NOP
    return 0;
}

long TRIBE_Screen_Disconnect::handle_idle() {
    /* TODO: Stub */
//                              long __thiscall handle_idle(TRIBE_Screen_Disconnect * this)
//              long              EAX:4          <RETURN>
//              TRIBE_Screen_D    ECX:4 (auto)   this
//                               ?handle_idle@TRIBE_Screen_Disconnect@@UAEJXZ                 XREF[1]:     00573564(*)
//                               TRIBE_Screen_Disconnect::handle_idle
//                              scr_mps.cpp:3388 (5)
//         004a63c0     JMP        TPanel::handle_idle
//         004a63c5     ??         90h
//         004a63c6     NOP
//         004a63c7     NOP
//         004a63c8     NOP
//         004a63c9     NOP
//         004a63ca     NOP
//         004a63cb     NOP
//         004a63cc     NOP
//         004a63cd     NOP
//         004a63ce     NOP
//         004a63cf     NOP
    return 0;
}

